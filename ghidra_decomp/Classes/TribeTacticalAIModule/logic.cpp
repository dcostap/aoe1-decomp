// Class: TribeTacticalAIModule
// Function: TribeTacticalAIModule
// Address: 004ed1c0
/* public: __thiscall TribeTacticalAIModule::TribeTacticalAIModule(void *,int) */

TribeTacticalAIModule * __thiscall
TribeTacticalAIModule::TribeTacticalAIModule(TribeTacticalAIModule *this,void *param_1,int param_2)
{
  TacticalAIGroup *this_00;
  int *piVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056092a;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TacticalAIModule::TacticalAIModule((TacticalAIModule *)this,param_1,param_2);
  this->md = (TribeMainDecisionAIModule *)0x0;
  (this->civilians).value = (int *)0x0;
  (this->civilians).numberValue = 0;
  (this->civilians).desiredNumberValue = 0;
  (this->civilians).maximumSizeValue = 0;
  (this->civilianExplorers).value = (int *)0x0;
  (this->civilianExplorers).numberValue = 0;
  (this->civilianExplorers).desiredNumberValue = 0;
  (this->civilianExplorers).maximumSizeValue = 0;
  (this->soldiers).value = (int *)0x0;
  (this->soldiers).numberValue = 0;
  (this->soldiers).desiredNumberValue = 0;
  (this->soldiers).maximumSizeValue = 0;
  (this->ungroupedSoldiers).value = (int *)0x0;
  (this->ungroupedSoldiers).numberValue = 0;
  (this->ungroupedSoldiers).desiredNumberValue = 0;
  (this->ungroupedSoldiers).maximumSizeValue = 0;
  (this->boats).value = (int *)0x0;
  (this->boats).numberValue = 0;
  (this->boats).desiredNumberValue = 0;
  (this->boats).maximumSizeValue = 0;
  (this->warBoats).value = (int *)0x0;
  (this->warBoats).numberValue = 0;
  (this->warBoats).desiredNumberValue = 0;
  (this->warBoats).maximumSizeValue = 0;
  (this->fishingBoats).value = (int *)0x0;
  (this->fishingBoats).numberValue = 0;
  (this->fishingBoats).desiredNumberValue = 0;
  (this->fishingBoats).maximumSizeValue = 0;
  (this->tradeBoats).value = (int *)0x0;
  (this->tradeBoats).numberValue = 0;
  (this->tradeBoats).desiredNumberValue = 0;
  (this->tradeBoats).maximumSizeValue = 0;
  (this->transportBoats).value = (int *)0x0;
  (this->transportBoats).numberValue = 0;
  (this->transportBoats).desiredNumberValue = 0;
  (this->transportBoats).maximumSizeValue = 0;
  (this->artifacts).value = (int *)0x0;
  (this->artifacts).numberValue = 0;
  (this->artifacts).desiredNumberValue = 0;
  (this->artifacts).maximumSizeValue = 0;
  this_00 = &this->groups;
  this->numberGatherersValue = 0;
  local_4._0_1_ = 10;
  local_4._1_3_ = 0;
  this->desiredNumberGatherersValue = 0;
  TacticalAIGroup::TacticalAIGroup(this_00);
  this->groupIDValue = 0;
  this->numberGroupsValue = 0;
  this->lastGroupAttackTime = 0;
  this->lastGroupRebalanceTime = 0;
  this->lastAttackResponseTime = 0;
  this->lastBoatAttackResponseTime = 0;
  this->lastScalingUpdateValue = 0;
  this->numberBuildUpdatesSkipped = 0;
  this->randomizedAttackSeparationTime = 0;
  (this->playersToAttack).value = (int *)0x0;
  (this->playersToAttack).numberValue = 0;
  (this->playersToAttack).desiredNumberValue = 0;
  (this->playersToAttack).maximumSizeValue = 0;
  (this->playersToDefend).value = (int *)0x0;
  (this->playersToDefend).numberValue = 0;
  (this->playersToDefend).desiredNumberValue = 0;
  (this->playersToDefend).maximumSizeValue = 0;
  (this->workingArea).value = (int *)0x0;
  (this->workingArea).numberValue = 0;
  (this->workingArea).desiredNumberValue = 0;
  (this->workingArea).maximumSizeValue = 0;
  (this->unitsTaskedThisUpdate).value = (int *)0x0;
  (this->unitsTaskedThisUpdate).numberValue = 0;
  (this->unitsTaskedThisUpdate).desiredNumberValue = 0;
  (this->unitsTaskedThisUpdate).maximumSizeValue = 0;
  local_4 = CONCAT31(local_4._1_3_,0xf);
  ResourceItem::ResourceItem(&this->neededResources,4);
  this->attackEnabledValue = 0;
  this->updateArea = 0;
  this->firstNeededResourceUpdateDone = 0;
  this->wonderInProgressValue = 0;
  this->wonderBuiltValue = 0;
  this->nextCivilianToTaskValue = -1;
  this->nextIdleSoldierGroupToTaskValue = -1;
  this->nextActiveSoldierGroupToTaskValue = -1;
  this->builtFirstStoragePit = 0;
  this->builtFirstGranary = 0;
  this->lastBuildTime = 0;
  this->lastAttackResponseBuildInsertionTime = 0;
  this->lastCoopTributeDemandTime = 0;
  this->lastCoopTributeGiftTime = 0;
  this->lastCoopAttackDemandTime = 0;
  this->zoomingToNextAge = 0;
  this->lastUngroupedSoldierTaskTime = 0;
  this->lastUpdateAreaTimeValue = -1;
  this->averageUpdateAreaTimeValue = -1;
  this->updateAreaAverageCount = 0;
  this->updateAreaAverageTotal = 0;
  this->_padding_ = (int)&_vftable_;
  piVar1 = this->desiredGathererDistribution;
  iVar2 = 4;
  do {
    piVar1[4] = -1;
    *piVar1 = 0;
    piVar1[-4] = 0;
    piVar1[8] = 0;
    piVar1[0x2b] = 0;
    piVar1[0x2f] = 0;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar1 = this->sn;
  for (iVar2 = 0xe2; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar1 = -1;
    piVar1 = piVar1 + 1;
  }
  piVar1 = this->hitsByPlayer;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
  }
  piVar1 = &this->gatherers[0].data1;
  iVar2 = 0x32;
  do {
    ((UnitData *)(piVar1 + -1))->id = -1;
    *piVar1 = -1;
    piVar1[1] = -1;
    piVar1[2] = -1;
    piVar1[3] = -1;
    piVar1 = piVar1 + 6;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (this->groups).next = this_00;
  (this->groups).prev = this_00;
  (this->placementStateValue).active = 0;
  (this->attackStateValue).active = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004ed4d0
/* public: virtual void * __thiscall TribeTacticalAIModule::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TribeTacticalAIModule::_scalar_deleting_destructor_(TribeTacticalAIModule *this,uint param_1)
{
  ~TribeTacticalAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TribeTacticalAIModule
// Address: 004ed4f0
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall TribeTacticalAIModule::TribeTacticalAIModule(int,int) */

TribeTacticalAIModule * __thiscall
TribeTacticalAIModule::TribeTacticalAIModule(TribeTacticalAIModule *this,int param_1,int param_2)
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
  int i;
  int tempInt;
  int local_2c;
  int local_28;
  OldUnitData tempUD;
  int local_14;
  int local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560a28;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  tempUD.id = (int)this;
  TacticalAIModule::TacticalAIModule((TacticalAIModule *)this,(void *)0x0,param_1);
  this->md = (TribeMainDecisionAIModule *)0x0;
  (this->civilians).value = (int *)0x0;
  (this->civilians).numberValue = 0;
  (this->civilians).desiredNumberValue = 0;
  (this->civilians).maximumSizeValue = 0;
  (this->civilianExplorers).value = (int *)0x0;
  (this->civilianExplorers).numberValue = 0;
  (this->civilianExplorers).desiredNumberValue = 0;
  (this->civilianExplorers).maximumSizeValue = 0;
  (this->soldiers).value = (int *)0x0;
  (this->soldiers).numberValue = 0;
  (this->soldiers).desiredNumberValue = 0;
  (this->soldiers).maximumSizeValue = 0;
  (this->ungroupedSoldiers).value = (int *)0x0;
  (this->ungroupedSoldiers).numberValue = 0;
  (this->ungroupedSoldiers).desiredNumberValue = 0;
  (this->ungroupedSoldiers).maximumSizeValue = 0;
  (this->boats).value = (int *)0x0;
  (this->boats).numberValue = 0;
  (this->boats).desiredNumberValue = 0;
  (this->boats).maximumSizeValue = 0;
  (this->warBoats).value = (int *)0x0;
  (this->warBoats).numberValue = 0;
  (this->warBoats).desiredNumberValue = 0;
  (this->warBoats).maximumSizeValue = 0;
  (this->fishingBoats).value = (int *)0x0;
  (this->fishingBoats).numberValue = 0;
  (this->fishingBoats).desiredNumberValue = 0;
  (this->fishingBoats).maximumSizeValue = 0;
  (this->tradeBoats).value = (int *)0x0;
  (this->tradeBoats).numberValue = 0;
  (this->tradeBoats).desiredNumberValue = 0;
  (this->tradeBoats).maximumSizeValue = 0;
  (this->transportBoats).value = (int *)0x0;
  (this->transportBoats).numberValue = 0;
  (this->transportBoats).desiredNumberValue = 0;
  (this->transportBoats).maximumSizeValue = 0;
  (this->artifacts).value = (int *)0x0;
  (this->artifacts).numberValue = 0;
  (this->artifacts).desiredNumberValue = 0;
  (this->artifacts).maximumSizeValue = 0;
  pTVar5 = &this->groups;
  local_4._0_1_ = 10;
  local_4._1_3_ = 0;
  TacticalAIGroup::TacticalAIGroup(pTVar5);
  this->lastGroupRebalanceTime = 0;
  (this->playersToAttack).value = (int *)0x0;
  (this->playersToAttack).numberValue = 0;
  (this->playersToAttack).desiredNumberValue = 0;
  (this->playersToAttack).maximumSizeValue = 0;
  (this->playersToDefend).value = (int *)0x0;
  (this->playersToDefend).numberValue = 0;
  (this->playersToDefend).desiredNumberValue = 0;
  (this->playersToDefend).maximumSizeValue = 0;
  (this->workingArea).value = (int *)0x0;
  (this->workingArea).numberValue = 0;
  (this->workingArea).desiredNumberValue = 0;
  (this->workingArea).maximumSizeValue = 0;
  (this->unitsTaskedThisUpdate).value = (int *)0x0;
  (this->unitsTaskedThisUpdate).numberValue = 0;
  (this->unitsTaskedThisUpdate).desiredNumberValue = 0;
  (this->unitsTaskedThisUpdate).maximumSizeValue = 0;
  local_4._0_1_ = 0xf;
  ResourceItem::ResourceItem(&this->neededResources,4);
  iVar6 = param_2;
  (this->groups).next = pTVar5;
  (this->groups).prev = pTVar5;
  local_4 = CONCAT31(local_4._1_3_,0x10);
  this->attackEnabledValue = 0;
  this->updateArea = 0;
  this->firstNeededResourceUpdateDone = 0;
  this->wonderInProgressValue = 0;
  this->wonderBuiltValue = 0;
  this->nextCivilianToTaskValue = -1;
  this->nextIdleSoldierGroupToTaskValue = -1;
  this->nextActiveSoldierGroupToTaskValue = -1;
  this->builtFirstStoragePit = 0;
  this->builtFirstGranary = 0;
  this->lastBuildTime = 0;
  this->lastAttackResponseBuildInsertionTime = 0;
  this->lastCoopTributeDemandTime = 0;
  this->lastCoopTributeGiftTime = 0;
  this->lastCoopAttackDemandTime = 0;
  this->zoomingToNextAge = 0;
  this->lastUngroupedSoldierTaskTime = 0;
  this->lastUpdateAreaTimeValue = -1;
  this->averageUpdateAreaTimeValue = -1;
  this->updateAreaAverageCount = 0;
  this->updateAreaAverageTotal = 0;
  this->_padding_ = (int)&_vftable_;
  rge_read(param_2,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(iVar6,&local_2c,4);
      iVar6 = (this->civilians).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if ((this->civilians).maximumSizeValue <= iVar1) break;
          if ((this->civilians).value[iVar1] == local_2c) goto LAB_004ed829;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if ((this->civilians).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->civilians).maximumSizeValue) {
            do {
              if (iVar6 <= iVar1) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->civilians).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->civilians).maximumSizeValue);
          }
          operator_delete((this->civilians).value);
          (this->civilians).value = piVar2;
          (this->civilians).maximumSizeValue = iVar6;
        }
      }
      (this->civilians).value[(this->civilians).numberValue] = local_28;
      (this->civilians).numberValue = (this->civilians).numberValue + 1;
LAB_004ed829:
      tempInt = tempInt + 1;
      iVar6 = param_2;
    } while (tempInt < param_1);
  }
  rge_read(iVar6,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(iVar6,&local_2c,4);
      iVar6 = (this->civilianExplorers).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if ((this->civilianExplorers).maximumSizeValue <= iVar1) break;
          if ((this->civilianExplorers).value[iVar1] == local_2c) goto LAB_004ed92c;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if ((this->civilianExplorers).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->civilianExplorers).maximumSizeValue) {
            do {
              if (iVar6 <= iVar1) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->civilianExplorers).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->civilianExplorers).maximumSizeValue);
          }
          operator_delete((this->civilianExplorers).value);
          (this->civilianExplorers).value = piVar2;
          (this->civilianExplorers).maximumSizeValue = iVar6;
        }
      }
      (this->civilianExplorers).value[(this->civilianExplorers).numberValue] = local_28;
      (this->civilianExplorers).numberValue = (this->civilianExplorers).numberValue + 1;
LAB_004ed92c:
      tempInt = tempInt + 1;
      iVar6 = param_2;
    } while (tempInt < param_1);
  }
  rge_read(iVar6,&this->numberGatherersValue,4);
  rge_read(iVar6,&this->desiredNumberGatherersValue,4);
  if (save_game_version < _DAT_00575710) {
    piVar2 = &this->gatherers[0].data1;
    iVar6 = 0x32;
    if (save_game_version < _DAT_00575714) {
      do {
        rge_read(param_2,&tempUD.data1,0x10);
        ((UnitData *)(piVar2 + -1))->id = tempUD.data1;
        *piVar2 = tempUD.data2;
        piVar2[1] = tempUD.data3;
        piVar2[2] = local_14;
        piVar2[3] = -1;
        piVar2[4] = 0;
        piVar2 = piVar2 + 6;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    else {
      do {
        rge_read(param_2,&tempUD.data1,0x14);
        ((UnitData *)(piVar2 + -1))->id = tempUD.data1;
        *piVar2 = tempUD.data2;
        piVar2[1] = tempUD.data3;
        piVar2[2] = local_14;
        piVar2[3] = local_10;
        piVar2[4] = 0;
        piVar2 = piVar2 + 6;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else {
                    /* language.dll match for 0x4b0: "Ready" */
    rge_read(iVar6,this->gatherers,0x4b0);
  }
  rge_read(param_2,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(param_2,&local_2c,4);
      iVar6 = (this->soldiers).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if ((this->soldiers).maximumSizeValue <= iVar1) break;
          if ((this->soldiers).value[iVar1] == local_2c) goto LAB_004edb26;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if ((this->soldiers).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->soldiers).maximumSizeValue) {
            do {
              if (iVar6 <= iVar1) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->soldiers).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->soldiers).maximumSizeValue);
          }
          operator_delete((this->soldiers).value);
          (this->soldiers).value = piVar2;
          (this->soldiers).maximumSizeValue = iVar6;
        }
      }
      (this->soldiers).value[(this->soldiers).numberValue] = local_28;
      (this->soldiers).numberValue = (this->soldiers).numberValue + 1;
LAB_004edb26:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  if (_DAT_00575718 <= save_game_version) {
    rge_read(param_2,&param_1,4);
    tempInt = 0;
    if (0 < param_1) {
      do {
        rge_read(param_2,&local_2c,4);
        iVar6 = (this->ungroupedSoldiers).numberValue;
        iVar1 = 0;
        local_28 = local_2c;
        if (0 < iVar6) {
          do {
            if ((this->ungroupedSoldiers).maximumSizeValue <= iVar1) break;
            if ((this->ungroupedSoldiers).value[iVar1] == local_2c) goto LAB_004edc44;
            iVar1 = iVar1 + 1;
          } while (iVar1 < iVar6);
        }
        if ((this->ungroupedSoldiers).maximumSizeValue + -1 < iVar6) {
          iVar6 = iVar6 + 1;
          piVar2 = (int *)operator_new(iVar6 * 4);
          if (piVar2 != (int *)0x0) {
            iVar1 = 0;
            if (0 < (this->ungroupedSoldiers).maximumSizeValue) {
              do {
                if (iVar6 <= iVar1) break;
                iVar3 = iVar1 + 1;
                piVar2[iVar1] = (this->ungroupedSoldiers).value[iVar1];
                iVar1 = iVar3;
              } while (iVar3 < (this->ungroupedSoldiers).maximumSizeValue);
            }
            operator_delete((this->ungroupedSoldiers).value);
            (this->ungroupedSoldiers).value = piVar2;
            (this->ungroupedSoldiers).maximumSizeValue = iVar6;
          }
        }
        (this->ungroupedSoldiers).value[(this->ungroupedSoldiers).numberValue] = local_28;
        (this->ungroupedSoldiers).numberValue = (this->ungroupedSoldiers).numberValue + 1;
LAB_004edc44:
        tempInt = tempInt + 1;
      } while (tempInt < param_1);
    }
  }
  rge_read(param_2,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(param_2,&local_2c,4);
      iVar6 = (this->boats).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if ((this->boats).maximumSizeValue <= iVar1) break;
          if ((this->boats).value[iVar1] == local_2c) goto LAB_004edd4b;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if ((this->boats).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->boats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar1) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->boats).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->boats).maximumSizeValue);
          }
          operator_delete((this->boats).value);
          (this->boats).value = piVar2;
          (this->boats).maximumSizeValue = iVar6;
        }
      }
      (this->boats).value[(this->boats).numberValue] = local_28;
      (this->boats).numberValue = (this->boats).numberValue + 1;
LAB_004edd4b:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(param_2,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(param_2,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->warBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((this->warBoats).maximumSizeValue <= iVar3) break;
          if ((this->warBoats).value[iVar3] == local_2c) goto LAB_004ede4c;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((this->warBoats).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->warBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->warBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->warBoats).maximumSizeValue);
          }
          operator_delete((this->warBoats).value);
          (this->warBoats).value = piVar2;
          (this->warBoats).maximumSizeValue = iVar6;
        }
      }
      (this->warBoats).value[(this->warBoats).numberValue] = iVar1;
      (this->warBoats).numberValue = (this->warBoats).numberValue + 1;
LAB_004ede4c:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(param_2,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(param_2,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->fishingBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((this->fishingBoats).maximumSizeValue <= iVar3) break;
          if ((this->fishingBoats).value[iVar3] == local_2c) goto LAB_004edf51;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((this->fishingBoats).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->fishingBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->fishingBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->fishingBoats).maximumSizeValue);
          }
          operator_delete((this->fishingBoats).value);
          (this->fishingBoats).value = piVar2;
          (this->fishingBoats).maximumSizeValue = iVar6;
        }
      }
      (this->fishingBoats).value[(this->fishingBoats).numberValue] = iVar1;
      (this->fishingBoats).numberValue = (this->fishingBoats).numberValue + 1;
LAB_004edf51:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(param_2,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(param_2,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->tradeBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((this->tradeBoats).maximumSizeValue <= iVar3) break;
          if ((this->tradeBoats).value[iVar3] == local_2c) goto LAB_004ee056;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((this->tradeBoats).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->tradeBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->tradeBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->tradeBoats).maximumSizeValue);
          }
          operator_delete((this->tradeBoats).value);
          (this->tradeBoats).value = piVar2;
          (this->tradeBoats).maximumSizeValue = iVar6;
        }
      }
      (this->tradeBoats).value[(this->tradeBoats).numberValue] = iVar1;
      (this->tradeBoats).numberValue = (this->tradeBoats).numberValue + 1;
LAB_004ee056:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(param_2,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(param_2,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->transportBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((this->transportBoats).maximumSizeValue <= iVar3) break;
          if ((this->transportBoats).value[iVar3] == local_2c) goto LAB_004ee15b;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((this->transportBoats).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->transportBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->transportBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->transportBoats).maximumSizeValue);
          }
          operator_delete((this->transportBoats).value);
          (this->transportBoats).value = piVar2;
          (this->transportBoats).maximumSizeValue = iVar6;
        }
      }
      (this->transportBoats).value[(this->transportBoats).numberValue] = iVar1;
      (this->transportBoats).numberValue = (this->transportBoats).numberValue + 1;
LAB_004ee15b:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  if (_DAT_0057571c <= save_game_version) {
    rge_read(param_2,&param_1,4);
    tempInt = 0;
    if (0 < param_1) {
      do {
        rge_read(param_2,&local_2c,4);
        iVar1 = local_2c;
        iVar6 = (this->artifacts).numberValue;
        iVar3 = 0;
        if (0 < iVar6) {
          do {
            if ((this->artifacts).maximumSizeValue <= iVar3) break;
            if ((this->artifacts).value[iVar3] == local_2c) goto LAB_004ee277;
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar6);
        }
        if ((this->artifacts).maximumSizeValue + -1 < iVar6) {
          iVar6 = iVar6 + 1;
          piVar2 = (int *)operator_new(iVar6 * 4);
          if (piVar2 != (int *)0x0) {
            iVar3 = 0;
            if (0 < (this->artifacts).maximumSizeValue) {
              do {
                if (iVar6 <= iVar3) break;
                iVar4 = iVar3 + 1;
                piVar2[iVar3] = (this->artifacts).value[iVar3];
                iVar3 = iVar4;
              } while (iVar4 < (this->artifacts).maximumSizeValue);
            }
            operator_delete((this->artifacts).value);
            (this->artifacts).value = piVar2;
            (this->artifacts).maximumSizeValue = iVar6;
          }
        }
        (this->artifacts).value[(this->artifacts).numberValue] = iVar1;
        (this->artifacts).numberValue = (this->artifacts).numberValue + 1;
LAB_004ee277:
        tempInt = tempInt + 1;
      } while (tempInt < param_1);
    }
  }
  iVar6 = param_2;
  rge_read(param_2,&param_1,4);
  iVar1 = 0;
  if (0 < param_1) {
    piVar2 = this->sn;
    do {
      rge_read(iVar6,piVar2,4);
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < param_1);
  }
  rge_read(iVar6,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(param_2,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->playersToAttack).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((this->playersToAttack).maximumSizeValue <= iVar3) break;
          if ((this->playersToAttack).value[iVar3] == local_2c) goto LAB_004ee3b4;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((this->playersToAttack).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->playersToAttack).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->playersToAttack).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->playersToAttack).maximumSizeValue);
          }
          operator_delete((this->playersToAttack).value);
          (this->playersToAttack).value = piVar2;
          (this->playersToAttack).maximumSizeValue = iVar6;
        }
      }
      (this->playersToAttack).value[(this->playersToAttack).numberValue] = iVar1;
      (this->playersToAttack).numberValue = (this->playersToAttack).numberValue + 1;
LAB_004ee3b4:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(param_2,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(param_2,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->playersToDefend).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((this->playersToDefend).maximumSizeValue <= iVar3) break;
          if ((this->playersToDefend).value[iVar3] == local_2c) goto LAB_004ee4b9;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((this->playersToDefend).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->playersToDefend).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->playersToDefend).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->playersToDefend).maximumSizeValue);
          }
          operator_delete((this->playersToDefend).value);
          (this->playersToDefend).value = piVar2;
          (this->playersToDefend).maximumSizeValue = iVar6;
        }
      }
      (this->playersToDefend).value[(this->playersToDefend).numberValue] = iVar1;
      (this->playersToDefend).numberValue = (this->playersToDefend).numberValue + 1;
LAB_004ee4b9:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(param_2,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(param_2,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->workingArea).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((this->workingArea).maximumSizeValue <= iVar3) break;
          if ((this->workingArea).value[iVar3] == local_2c) goto LAB_004ee5be;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->workingArea).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->workingArea).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->workingArea).maximumSizeValue);
          }
          operator_delete((this->workingArea).value);
          (this->workingArea).value = piVar2;
          (this->workingArea).maximumSizeValue = iVar6;
        }
      }
      (this->workingArea).value[(this->workingArea).numberValue] = iVar1;
      (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004ee5be:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(param_2,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(param_2,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->unitsTaskedThisUpdate).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar3) break;
          if ((this->unitsTaskedThisUpdate).value[iVar3] == local_2c) goto LAB_004ee6c3;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->unitsTaskedThisUpdate).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->unitsTaskedThisUpdate).maximumSizeValue);
          }
          operator_delete((this->unitsTaskedThisUpdate).value);
          (this->unitsTaskedThisUpdate).value = piVar2;
          (this->unitsTaskedThisUpdate).maximumSizeValue = iVar6;
        }
      }
      (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = iVar1;
      (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004ee6c3:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  iVar6 = param_2;
  piVar2 = this->actualGathererDistribution;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->desiredGathererDistribution;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->neededResourceValue;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->resourceDifferenceValue;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->numberStoragePitsBuilt;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->numberGranariesBuilt;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0;
  do {
    rge_read(iVar6,&local_2c,4);
    ResourceItem::setValue(&this->neededResources,iVar1,local_2c);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  rge_read(iVar6,&this->groupIDValue,4);
  piVar2 = &this->numberGroupsValue;
  rge_read(iVar6,piVar2,4);
  iVar1 = 0;
  if (0 < *piVar2) {
    do {
      pTVar5 = createGroup(this,0);
      if (pTVar5 != (TacticalAIGroup *)0x0) {
        TacticalAIGroup::load(pTVar5,iVar6);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *piVar2);
  }
  rge_read(iVar6,&this->lastGroupAttackTime,4);
  if (_DAT_00575720 <= save_game_version) {
    rge_read(iVar6,&this->lastGroupRebalanceTime,4);
  }
  rge_read(iVar6,&this->lastAttackResponseTime,4);
  rge_read(iVar6,&this->lastBoatAttackResponseTime,4);
  rge_read(iVar6,&this->lastScalingUpdateValue,4);
  rge_read(iVar6,&this->numberBuildUpdatesSkipped,4);
  rge_read(iVar6,&this->randomizedAttackSeparationTime,4);
  if (_DAT_00575724 <= save_game_version) {
    rge_read(iVar6,&this->attackEnabledValue,4);
  }
  rge_read(iVar6,&this->updateArea,4);
  if (_DAT_00575728 <= save_game_version) {
    rge_read(iVar6,&this->wonderInProgressValue,4);
    rge_read(iVar6,&this->wonderBuiltValue,4);
  }
  if (save_game_version < _DAT_0057572c) {
    pPVar7 = &this->placementStateValue;
    for (iVar1 = 0x4c; iVar1 != 0; iVar1 = iVar1 + -1) {
      pPVar7->buildingTypeID = 0;
      pPVar7 = (PlacementState *)&pPVar7->buildingSize;
    }
  }
  else {
    rge_read(iVar6,&this->placementStateValue,0x130);
  }
  (this->placementStateValue).active = 0;
  if (_DAT_00575730 <= save_game_version) {
    rge_read(iVar6,&this->nextCivilianToTaskValue,4);
  }
  if (_DAT_00575734 <= save_game_version) {
    rge_read(iVar6,&this->nextIdleSoldierGroupToTaskValue,4);
    rge_read(iVar6,&this->nextActiveSoldierGroupToTaskValue,4);
  }
  if (_DAT_00575738 <= save_game_version) {
    rge_read(iVar6,&this->builtFirstStoragePit,4);
    rge_read(iVar6,&this->builtFirstGranary,4);
  }
  if (_DAT_0057573c <= save_game_version) {
    rge_read(iVar6,&this->lastBuildTime,4);
    rge_read(iVar6,&this->lastAttackResponseBuildInsertionTime,4);
    rge_read(iVar6,&this->lastCoopTributeDemandTime,4);
  }
  if (_DAT_00575740 <= save_game_version) {
    rge_read(iVar6,&this->lastCoopTributeGiftTime,4);
  }
  if (_DAT_00575744 <= save_game_version) {
    rge_read(iVar6,&this->zoomingToNextAge,4);
  }
  if (_DAT_00575748 <= save_game_version) {
    rge_read(iVar6,&this->lastCoopAttackDemandTime,4);
  }
  if (_DAT_0057574c <= save_game_version) {
    rge_read(iVar6,&this->lastUngroupedSoldierTaskTime,4);
  }
  if (save_game_version < _DAT_00575750) {
    pAVar8 = &this->attackStateValue;
    for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
      pAVar8->bestTargetID = 0;
      pAVar8 = (AttackState *)&pAVar8->bestTargetValue;
    }
  }
  else {
    rge_read(iVar6,&this->attackStateValue,0x2c);
  }
  (this->attackStateValue).active = 0;
  if (save_game_version < _DAT_00575754) {
    piVar2 = this->hitsByPlayer;
    for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
  }
  else {
    rge_read(iVar6,this->hitsByPlayer,0x24);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TribeTacticalAIModule
// Address: 004eeb40
/* public: virtual __thiscall TribeTacticalAIModule::~TribeTacticalAIModule(void) */

void __thiscall TribeTacticalAIModule::~TribeTacticalAIModule(TribeTacticalAIModule *this)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00560b28;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0x10;
  removeAllGroups(this,-1);
  local_4._0_1_ = 0xf;
  ResourceItem::~ResourceItem(&this->neededResources);
  piVar1 = (this->unitsTaskedThisUpdate).value;
  local_4._0_1_ = 0xe;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->unitsTaskedThisUpdate).value = (int *)0x0;
  }
  (this->unitsTaskedThisUpdate).numberValue = 0;
  (this->unitsTaskedThisUpdate).desiredNumberValue = 0;
  (this->unitsTaskedThisUpdate).maximumSizeValue = 0;
  piVar1 = (this->workingArea).value;
  local_4._0_1_ = 0xd;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->workingArea).value = (int *)0x0;
  }
  (this->workingArea).numberValue = 0;
  (this->workingArea).desiredNumberValue = 0;
  (this->workingArea).maximumSizeValue = 0;
  piVar1 = (this->playersToDefend).value;
  local_4._0_1_ = 0xc;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->playersToDefend).value = (int *)0x0;
  }
  (this->playersToDefend).numberValue = 0;
  (this->playersToDefend).desiredNumberValue = 0;
  (this->playersToDefend).maximumSizeValue = 0;
  piVar1 = (this->playersToAttack).value;
  local_4._0_1_ = 0xb;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->playersToAttack).value = (int *)0x0;
  }
  (this->playersToAttack).numberValue = 0;
  (this->playersToAttack).desiredNumberValue = 0;
  (this->playersToAttack).maximumSizeValue = 0;
  local_4._0_1_ = 10;
  TacticalAIGroup::~TacticalAIGroup(&this->groups);
  piVar1 = (this->artifacts).value;
  local_4._0_1_ = 9;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->artifacts).value = (int *)0x0;
  }
  (this->artifacts).numberValue = 0;
  (this->artifacts).desiredNumberValue = 0;
  (this->artifacts).maximumSizeValue = 0;
  piVar1 = (this->transportBoats).value;
  local_4._0_1_ = 8;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->transportBoats).value = (int *)0x0;
  }
  (this->transportBoats).numberValue = 0;
  (this->transportBoats).desiredNumberValue = 0;
  (this->transportBoats).maximumSizeValue = 0;
  piVar1 = (this->tradeBoats).value;
  local_4._0_1_ = 7;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->tradeBoats).value = (int *)0x0;
  }
  (this->tradeBoats).numberValue = 0;
  (this->tradeBoats).desiredNumberValue = 0;
  (this->tradeBoats).maximumSizeValue = 0;
  piVar1 = (this->fishingBoats).value;
  local_4._0_1_ = 6;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->fishingBoats).value = (int *)0x0;
  }
  (this->fishingBoats).numberValue = 0;
  (this->fishingBoats).desiredNumberValue = 0;
  (this->fishingBoats).maximumSizeValue = 0;
  piVar1 = (this->warBoats).value;
  local_4._0_1_ = 5;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->warBoats).value = (int *)0x0;
  }
  (this->warBoats).numberValue = 0;
  (this->warBoats).desiredNumberValue = 0;
  (this->warBoats).maximumSizeValue = 0;
  piVar1 = (this->boats).value;
  local_4._0_1_ = 4;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->boats).value = (int *)0x0;
  }
  (this->boats).numberValue = 0;
  (this->boats).desiredNumberValue = 0;
  (this->boats).maximumSizeValue = 0;
  piVar1 = (this->ungroupedSoldiers).value;
  local_4._0_1_ = 3;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->ungroupedSoldiers).value = (int *)0x0;
  }
  (this->ungroupedSoldiers).numberValue = 0;
  (this->ungroupedSoldiers).desiredNumberValue = 0;
  (this->ungroupedSoldiers).maximumSizeValue = 0;
  piVar1 = (this->soldiers).value;
  local_4._0_1_ = 2;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->soldiers).value = (int *)0x0;
  }
  (this->soldiers).numberValue = 0;
  (this->soldiers).desiredNumberValue = 0;
  (this->soldiers).maximumSizeValue = 0;
  piVar1 = (this->civilianExplorers).value;
  local_4._0_1_ = 1;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->civilianExplorers).value = (int *)0x0;
  }
  (this->civilianExplorers).numberValue = 0;
  (this->civilianExplorers).desiredNumberValue = 0;
  (this->civilianExplorers).maximumSizeValue = 0;
  local_4 = (uint)local_4._1_3_ << 8;
  ManagedArray<int>::~ManagedArray<int>(&this->civilians);
  local_4 = 0xffffffff;
  TacticalAIModule::~TacticalAIModule((TacticalAIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: updateAreaName
// Address: 004eee40
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
/* public: char * __thiscall TribeTacticalAIModule::updateAreaName(void) */

char * __thiscall TribeTacticalAIModule::updateAreaName(TribeTacticalAIModule *this)
{
  switch(this->updateArea) {
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

// Function: update
// Address: 004eef40
/* WARNING: Removing unreachable block (ram,0x004ef113) */
/* WARNING: Removing unreachable block (ram,0x004ef119) */
/* WARNING: Removing unreachable block (ram,0x004ef11d) */
/* WARNING: Removing unreachable block (ram,0x004ef12c) */
/* WARNING: Removing unreachable block (ram,0x004ef1d5) */
/* WARNING: Removing unreachable block (ram,0x004ef1db) */
/* WARNING: Removing unreachable block (ram,0x004ef1df) */
/* WARNING: Removing unreachable block (ram,0x004ef1ee) */
/* WARNING: Variable defined which should be unmapped: mostHatedPlayer */
/* public: virtual int __thiscall TribeTacticalAIModule::update(int) */

int __thiscall TribeTacticalAIModule::update(TribeTacticalAIModule *this,int param_1)
{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  TribeMainDecisionAIModule *pTVar7;
  int iVar8;
  int mostHatedPlayer;
  int mostLikedPlayer;
  
  pTVar7 = this->md;
  if ((uint)(this->sn[99] * 60000) <
      *(int *)(*(int *)(pTVar7->_padding_ + 0x3c) + 4) - this->lastScalingUpdateValue) {
    iVar2 = this->sn[0x1a] + this->sn[0x5e];
    this->sn[0x1a] = iVar2;
    if (iVar2 < 0) {
      this->sn[0x1a] = 0;
    }
    iVar2 = this->sn[0x10] + this->sn[0x5d];
    this->sn[0x10] = iVar2;
    if (iVar2 < 0) {
      this->sn[0x10] = 0;
    }
    iVar2 = this->sn[0x1a];
    if (iVar2 < this->sn[0x10]) {
      this->sn[0x10] = iVar2;
    }
    if (iVar2 < this->sn[0x10]) {
      this->sn[0x1a] = this->sn[0x10];
    }
    iVar2 = this->sn[0x1e] << 1;
    this->sn[0x1e] = iVar2;
    if (iVar2 < 0) {
      this->sn[0x1e] = 0;
    }
    if (100 < this->sn[0x1e]) {
      this->sn[0x1e] = 100;
    }
    iVar2 = this->sn[0x1f] << 1;
    this->sn[0x1f] = iVar2;
    if (iVar2 < 0) {
      this->sn[0x1f] = 0;
    }
    if (100 < this->sn[0x1f]) {
      this->sn[0x1f] = 100;
    }
    iVar2 = this->sn[0x5b] << 1;
    this->sn[0x5b] = iVar2;
    if (iVar2 < 0) {
      this->sn[0x5b] = 0;
    }
    if (100 < this->sn[0x5b]) {
      this->sn[0x5b] = 100;
    }
    this->lastScalingUpdateValue = *(ulong *)(*(int *)(pTVar7->_padding_ + 0x3c) + 4);
  }
  (this->unitsTaskedThisUpdate).numberValue = 0;
  (this->md->informationAI).farmsTaskedThisUpdate.numberValue = 0;
  if ((uint)this->sn[0x68] <= *(uint *)(*(int *)(this->md->_padding_ + 0x3c) + 4) / 1000) {
    enableAttack(this,2);
  }
  iVar2 = DiplomacyAIModule::mostHated
                    (&this->md->diplomacyAI,this->sn[0x7c],this->sn[0x80],this->sn[0xbc],
                     this->sn[0xc3]);
  iVar3 = DiplomacyAIModule::mostLiked(&this->md->diplomacyAI,this->sn[0x7c],this->sn[0x80]);
  (this->playersToAttack).numberValue = 0;
  if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
     (piVar4 = (int *)operator_new(4), piVar4 != (int *)0x0)) {
    iVar8 = 0;
    if (0 < (this->playersToAttack).maximumSizeValue) {
      do {
        if (0 < iVar8) break;
        iVar5 = iVar8 + 1;
        piVar4[iVar8] = (this->playersToAttack).value[iVar8];
        iVar8 = iVar5;
      } while (iVar5 < (this->playersToAttack).maximumSizeValue);
    }
    operator_delete((this->playersToAttack).value);
    (this->playersToAttack).value = piVar4;
    (this->playersToAttack).maximumSizeValue = 1;
  }
  (this->playersToAttack).value[(this->playersToAttack).numberValue] = iVar2;
  (this->playersToAttack).numberValue = (this->playersToAttack).numberValue + 1;
  (this->playersToDefend).numberValue = 0;
  sVar1 = *(short *)(this->md->_padding_ + 0x4a);
  if (((this->playersToDefend).maximumSizeValue + -1 < 0) &&
     (piVar4 = (int *)operator_new(4), piVar4 != (int *)0x0)) {
    iVar8 = 0;
    if (0 < (this->playersToDefend).maximumSizeValue) {
      do {
        if (0 < iVar8) break;
        iVar5 = iVar8 + 1;
        piVar4[iVar8] = (this->playersToDefend).value[iVar8];
        iVar8 = iVar5;
      } while (iVar5 < (this->playersToDefend).maximumSizeValue);
    }
    operator_delete((this->playersToDefend).value);
    (this->playersToDefend).value = piVar4;
    (this->playersToDefend).maximumSizeValue = 1;
  }
  (this->playersToDefend).value[(this->playersToDefend).numberValue] = (int)sVar1;
  (this->playersToDefend).numberValue = (this->playersToDefend).numberValue + 1;
  if (iVar2 != iVar3) {
    iVar8 = (this->playersToDefend).numberValue;
    iVar5 = 0;
    if (0 < iVar8) {
      do {
        if ((this->playersToDefend).maximumSizeValue <= iVar5) break;
        if ((this->playersToDefend).value[iVar5] == iVar3) goto LAB_004ef339;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar8);
    }
    if ((this->playersToDefend).maximumSizeValue + -1 < iVar8) {
      iVar8 = iVar8 + 1;
      piVar4 = (int *)operator_new(iVar8 * 4);
      if (piVar4 != (int *)0x0) {
        iVar5 = 0;
        if (0 < (this->playersToDefend).maximumSizeValue) {
          do {
            if (iVar8 <= iVar5) break;
            iVar6 = iVar5 + 1;
            piVar4[iVar5] = (this->playersToDefend).value[iVar5];
            iVar5 = iVar6;
          } while (iVar6 < (this->playersToDefend).maximumSizeValue);
        }
        operator_delete((this->playersToDefend).value);
        (this->playersToDefend).value = piVar4;
        (this->playersToDefend).maximumSizeValue = iVar8;
      }
    }
    (this->playersToDefend).value[(this->playersToDefend).numberValue] = iVar3;
    (this->playersToDefend).numberValue = (this->playersToDefend).numberValue + 1;
  }
LAB_004ef339:
  pTVar7 = this->md;
  iVar5 = 1;
  iVar8 = pTVar7->_padding_;
  if (1 < *(short *)(*(int *)(iVar8 + 0x3c) + 0x3c)) {
    do {
      if (iVar5 != *(short *)(iVar8 + 0x4a)) {
        if (iVar5 == iVar2) {
          iVar8 = DiplomacyAIModule::isEnemy(&pTVar7->diplomacyAI,iVar5);
          if (((iVar8 == 0) &&
              (iVar8 = DiplomacyAIModule::isChangeable(&this->md->diplomacyAI,iVar5), iVar8 != 0))
             && (iVar8 = DiplomacyAIModule::stance(&this->md->diplomacyAI,iVar5,0), 0x4a < iVar8)) {
            iVar8 = 3;
            goto LAB_004ef47f;
          }
        }
        else if (iVar5 == iVar3) {
          iVar8 = DiplomacyAIModule::isAlly(&pTVar7->diplomacyAI,iVar5);
          if (((iVar8 == 0) &&
              (iVar8 = DiplomacyAIModule::isChangeable(&this->md->diplomacyAI,iVar5), iVar8 != 0))
             && (iVar8 = DiplomacyAIModule::stance(&this->md->diplomacyAI,iVar5,2), 0x4a < iVar8)) {
            iVar8 = 0;
            goto LAB_004ef47f;
          }
        }
        else {
          iVar8 = DiplomacyAIModule::stance(&pTVar7->diplomacyAI,iVar5,2);
          if ((this->sn[0x1d] < iVar8) &&
             (iVar8 = DiplomacyAIModule::isChangeable(&this->md->diplomacyAI,iVar5), iVar8 != 0)) {
            iVar8 = DiplomacyAIModule::isAlly(&this->md->diplomacyAI,iVar5);
            if (iVar8 == 0) {
              iVar8 = 0;
LAB_004ef47f:
              DiplomacyAIModule::setRelation(&this->md->diplomacyAI,iVar5,iVar8);
            }
          }
          else {
            iVar8 = DiplomacyAIModule::isNeutral(&this->md->diplomacyAI,iVar5);
            if ((iVar8 == 0) &&
               (iVar8 = DiplomacyAIModule::isChangeable(&this->md->diplomacyAI,iVar5), iVar8 != 0))
{
              iVar8 = 1;
              goto LAB_004ef47f;
            }
          }
        }
      }
      pTVar7 = this->md;
      iVar5 = iVar5 + 1;
      iVar8 = pTVar7->_padding_;
    } while (iVar5 < *(short *)(*(int *)(iVar8 + 0x3c) + 0x3c));
  }
  doSomething(this);
  (this->unitsTaskedThisUpdate).numberValue = 0;
  return 1;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 004ef4d0
/* public: void __thiscall TribeTacticalAIModule::setMainDecisionAI(class TribeMainDecisionAIModule
   *) */

void __thiscall
TribeTacticalAIModule::setMainDecisionAI
          (TribeTacticalAIModule *this,TribeMainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004ef4e0
/* WARNING: Variable defined which should be unmapped: tempInt */
/* public: virtual int __thiscall TribeTacticalAIModule::save(int) */

int __thiscall TribeTacticalAIModule::save(TribeTacticalAIModule *this,int param_1)
{
  TacticalAIGroup *this_00;
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int tempInt;
  int local_4;
  
  local_4 = (this->civilians).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->civilians).numberValue) {
    do {
      if ((this->civilians).maximumSizeValue + -1 < iVar4) {
        ManagedArray<int>::resize(&this->civilians,iVar4 + 1);
      }
      local_4 = (this->civilians).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->civilians).numberValue);
  }
  local_4 = (this->civilianExplorers).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->civilianExplorers).numberValue) {
    do {
      if ((this->civilianExplorers).maximumSizeValue + -1 < iVar4) {
        ManagedArray<int>::resize(&this->civilianExplorers,iVar4 + 1);
      }
      local_4 = (this->civilianExplorers).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->civilianExplorers).numberValue);
  }
  rge_write(param_1,&this->numberGatherersValue,4);
  rge_write(param_1,&this->desiredNumberGatherersValue,4);
                    /* language.dll match for 0x4b0: "Ready" */
  rge_write(param_1,this->gatherers,0x4b0);
  local_4 = (this->soldiers).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->soldiers).numberValue) {
    do {
      if ((this->soldiers).maximumSizeValue + -1 < iVar4) {
        ManagedArray<int>::resize(&this->soldiers,iVar4 + 1);
      }
      local_4 = (this->soldiers).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->soldiers).numberValue);
  }
  local_4 = (this->ungroupedSoldiers).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->ungroupedSoldiers).numberValue) {
    do {
      if ((this->ungroupedSoldiers).maximumSizeValue + -1 < iVar4) {
        ManagedArray<int>::resize(&this->ungroupedSoldiers,iVar4 + 1);
      }
      local_4 = (this->ungroupedSoldiers).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->ungroupedSoldiers).numberValue);
  }
  local_4 = (this->boats).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->boats).numberValue) {
    do {
      if (((this->boats).maximumSizeValue + -1 < iVar4) &&
         (piVar1 = (int *)operator_new(iVar4 * 4 + 4), piVar1 != (int *)0x0)) {
        iVar3 = 0;
        if (0 < (this->boats).maximumSizeValue) {
          do {
            if (iVar4 + 1 <= iVar3) break;
            iVar2 = iVar3 + 1;
            piVar1[iVar3] = (this->boats).value[iVar3];
            iVar3 = iVar2;
          } while (iVar2 < (this->boats).maximumSizeValue);
        }
        operator_delete((this->boats).value);
        (this->boats).value = piVar1;
        (this->boats).maximumSizeValue = iVar4 + 1;
      }
      local_4 = (this->boats).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->boats).numberValue);
  }
  local_4 = (this->warBoats).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->warBoats).numberValue) {
    do {
      if (((this->warBoats).maximumSizeValue + -1 < iVar4) &&
         (piVar1 = (int *)operator_new(iVar4 * 4 + 4), piVar1 != (int *)0x0)) {
        iVar3 = 0;
        if (0 < (this->warBoats).maximumSizeValue) {
          do {
            if (iVar4 + 1 <= iVar3) break;
            iVar2 = iVar3 + 1;
            piVar1[iVar3] = (this->warBoats).value[iVar3];
            iVar3 = iVar2;
          } while (iVar2 < (this->warBoats).maximumSizeValue);
        }
        operator_delete((this->warBoats).value);
        (this->warBoats).value = piVar1;
        (this->warBoats).maximumSizeValue = iVar4 + 1;
      }
      local_4 = (this->warBoats).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->warBoats).numberValue);
  }
  local_4 = (this->fishingBoats).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->fishingBoats).numberValue) {
    do {
      if (((this->fishingBoats).maximumSizeValue + -1 < iVar4) &&
         (piVar1 = (int *)operator_new(iVar4 * 4 + 4), piVar1 != (int *)0x0)) {
        iVar3 = 0;
        if (0 < (this->fishingBoats).maximumSizeValue) {
          do {
            if (iVar4 + 1 <= iVar3) break;
            iVar2 = iVar3 + 1;
            piVar1[iVar3] = (this->fishingBoats).value[iVar3];
            iVar3 = iVar2;
          } while (iVar2 < (this->fishingBoats).maximumSizeValue);
        }
        operator_delete((this->fishingBoats).value);
        (this->fishingBoats).value = piVar1;
        (this->fishingBoats).maximumSizeValue = iVar4 + 1;
      }
      local_4 = (this->fishingBoats).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->fishingBoats).numberValue);
  }
  local_4 = (this->tradeBoats).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->tradeBoats).numberValue) {
    do {
      if (((this->tradeBoats).maximumSizeValue + -1 < iVar4) &&
         (piVar1 = (int *)operator_new(iVar4 * 4 + 4), piVar1 != (int *)0x0)) {
        iVar3 = 0;
        if (0 < (this->tradeBoats).maximumSizeValue) {
          do {
            if (iVar4 + 1 <= iVar3) break;
            iVar2 = iVar3 + 1;
            piVar1[iVar3] = (this->tradeBoats).value[iVar3];
            iVar3 = iVar2;
          } while (iVar2 < (this->tradeBoats).maximumSizeValue);
        }
        operator_delete((this->tradeBoats).value);
        (this->tradeBoats).value = piVar1;
        (this->tradeBoats).maximumSizeValue = iVar4 + 1;
      }
      local_4 = (this->tradeBoats).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->tradeBoats).numberValue);
  }
  local_4 = (this->transportBoats).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->transportBoats).numberValue) {
    do {
      if (((this->transportBoats).maximumSizeValue + -1 < iVar4) &&
         (piVar1 = (int *)operator_new(iVar4 * 4 + 4), piVar1 != (int *)0x0)) {
        iVar3 = 0;
        if (0 < (this->transportBoats).maximumSizeValue) {
          do {
            if (iVar4 + 1 <= iVar3) break;
            iVar2 = iVar3 + 1;
            piVar1[iVar3] = (this->transportBoats).value[iVar3];
            iVar3 = iVar2;
          } while (iVar2 < (this->transportBoats).maximumSizeValue);
        }
        operator_delete((this->transportBoats).value);
        (this->transportBoats).value = piVar1;
        (this->transportBoats).maximumSizeValue = iVar4 + 1;
      }
      local_4 = (this->transportBoats).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->transportBoats).numberValue);
  }
  local_4 = (this->artifacts).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->artifacts).numberValue) {
    do {
      if (((this->artifacts).maximumSizeValue + -1 < iVar4) &&
         (piVar1 = (int *)operator_new(iVar4 * 4 + 4), piVar1 != (int *)0x0)) {
        iVar3 = 0;
        if (0 < (this->artifacts).maximumSizeValue) {
          do {
            if (iVar4 + 1 <= iVar3) break;
            iVar2 = iVar3 + 1;
            piVar1[iVar3] = (this->artifacts).value[iVar3];
            iVar3 = iVar2;
          } while (iVar2 < (this->artifacts).maximumSizeValue);
        }
        operator_delete((this->artifacts).value);
        (this->artifacts).value = piVar1;
        (this->artifacts).maximumSizeValue = iVar4 + 1;
      }
      local_4 = (this->artifacts).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->artifacts).numberValue);
  }
  local_4 = 0xe2;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < local_4) {
    piVar1 = this->sn;
    do {
      rge_write(param_1,piVar1,4);
      iVar4 = iVar4 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar4 < local_4);
  }
  local_4 = (this->playersToAttack).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->playersToAttack).numberValue) {
    do {
      if (((this->playersToAttack).maximumSizeValue + -1 < iVar4) &&
         (piVar1 = (int *)operator_new(iVar4 * 4 + 4), piVar1 != (int *)0x0)) {
        iVar3 = 0;
        if (0 < (this->playersToAttack).maximumSizeValue) {
          do {
            if (iVar4 + 1 <= iVar3) break;
            iVar2 = iVar3 + 1;
            piVar1[iVar3] = (this->playersToAttack).value[iVar3];
            iVar3 = iVar2;
          } while (iVar2 < (this->playersToAttack).maximumSizeValue);
        }
        operator_delete((this->playersToAttack).value);
        (this->playersToAttack).value = piVar1;
        (this->playersToAttack).maximumSizeValue = iVar4 + 1;
      }
      local_4 = (this->playersToAttack).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->playersToAttack).numberValue);
  }
  local_4 = (this->playersToDefend).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->playersToDefend).numberValue) {
    do {
      if (((this->playersToDefend).maximumSizeValue + -1 < iVar4) &&
         (piVar1 = (int *)operator_new(iVar4 * 4 + 4), piVar1 != (int *)0x0)) {
        iVar3 = 0;
        if (0 < (this->playersToDefend).maximumSizeValue) {
          do {
            if (iVar4 + 1 <= iVar3) break;
            iVar2 = iVar3 + 1;
            piVar1[iVar3] = (this->playersToDefend).value[iVar3];
            iVar3 = iVar2;
          } while (iVar2 < (this->playersToDefend).maximumSizeValue);
        }
        operator_delete((this->playersToDefend).value);
        (this->playersToDefend).value = piVar1;
        (this->playersToDefend).maximumSizeValue = iVar4 + 1;
      }
      local_4 = (this->playersToDefend).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->playersToDefend).numberValue);
  }
  local_4 = (this->workingArea).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->workingArea).numberValue) {
    do {
      if (((this->workingArea).maximumSizeValue + -1 < iVar4) &&
         (piVar1 = (int *)operator_new(iVar4 * 4 + 4), piVar1 != (int *)0x0)) {
        iVar3 = 0;
        if (0 < (this->workingArea).maximumSizeValue) {
          do {
            if (iVar4 + 1 <= iVar3) break;
            iVar2 = iVar3 + 1;
            piVar1[iVar3] = (this->workingArea).value[iVar3];
            iVar3 = iVar2;
          } while (iVar2 < (this->workingArea).maximumSizeValue);
        }
        operator_delete((this->workingArea).value);
        (this->workingArea).value = piVar1;
        (this->workingArea).maximumSizeValue = iVar4 + 1;
      }
      local_4 = (this->workingArea).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->workingArea).numberValue);
  }
  local_4 = (this->unitsTaskedThisUpdate).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->unitsTaskedThisUpdate).numberValue) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar4) {
        piVar1 = (int *)operator_new(iVar4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
            do {
              if (iVar4 + 1 <= iVar3) break;
              iVar2 = iVar3 + 1;
              piVar1[iVar3] = (this->unitsTaskedThisUpdate).value[iVar3];
              iVar3 = iVar2;
            } while (iVar2 < (this->unitsTaskedThisUpdate).maximumSizeValue);
          }
          operator_delete((this->unitsTaskedThisUpdate).value);
          (this->unitsTaskedThisUpdate).value = piVar1;
          (this->unitsTaskedThisUpdate).maximumSizeValue = iVar4 + 1;
        }
      }
      local_4 = (this->unitsTaskedThisUpdate).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->unitsTaskedThisUpdate).numberValue);
  }
  piVar1 = this->actualGathererDistribution;
  iVar4 = 4;
  do {
    rge_write(param_1,piVar1,4);
    piVar1 = piVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar1 = this->desiredGathererDistribution;
  iVar4 = 4;
  do {
    rge_write(param_1,piVar1,4);
    piVar1 = piVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar1 = this->neededResourceValue;
  iVar4 = 4;
  do {
    rge_write(param_1,piVar1,4);
    piVar1 = piVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar1 = this->resourceDifferenceValue;
  iVar4 = 4;
  do {
    rge_write(param_1,piVar1,4);
    piVar1 = piVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar1 = this->numberStoragePitsBuilt;
  iVar4 = 4;
  do {
    rge_write(param_1,piVar1,4);
    piVar1 = piVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar1 = this->numberGranariesBuilt;
  iVar4 = 4;
  do {
    rge_write(param_1,piVar1,4);
    piVar1 = piVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0;
  do {
    local_4 = ResourceItem::value(&this->neededResources,iVar4);
    rge_write(param_1,&local_4,4);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  rge_write(param_1,&this->groupIDValue,4);
  rge_write(param_1,&this->numberGroupsValue,4);
  for (this_00 = (this->groups).next;
      (this_00 != &this->groups && (this_00 != (TacticalAIGroup *)0x0)); this_00 = this_00->next) {
    TacticalAIGroup::save(this_00,param_1);
  }
  rge_write(param_1,&this->lastGroupAttackTime,4);
  rge_write(param_1,&this->lastGroupRebalanceTime,4);
  rge_write(param_1,&this->lastAttackResponseTime,4);
  rge_write(param_1,&this->lastBoatAttackResponseTime,4);
  rge_write(param_1,&this->lastScalingUpdateValue,4);
  rge_write(param_1,&this->numberBuildUpdatesSkipped,4);
  rge_write(param_1,&this->randomizedAttackSeparationTime,4);
  rge_write(param_1,&this->attackEnabledValue,4);
  rge_write(param_1,&this->updateArea,4);
  rge_write(param_1,&this->wonderInProgressValue,4);
  rge_write(param_1,&this->wonderBuiltValue,4);
  rge_write(param_1,&this->placementStateValue,0x130);
  rge_write(param_1,&this->nextCivilianToTaskValue,4);
  rge_write(param_1,&this->nextIdleSoldierGroupToTaskValue,4);
  rge_write(param_1,&this->nextActiveSoldierGroupToTaskValue,4);
  rge_write(param_1,&this->builtFirstStoragePit,4);
  rge_write(param_1,&this->builtFirstGranary,4);
  rge_write(param_1,&this->lastBuildTime,4);
  rge_write(param_1,&this->lastAttackResponseBuildInsertionTime,4);
  rge_write(param_1,&this->lastCoopTributeDemandTime,4);
  rge_write(param_1,&this->lastCoopTributeGiftTime,4);
  rge_write(param_1,&this->zoomingToNextAge,4);
  rge_write(param_1,&this->lastCoopAttackDemandTime,4);
  rge_write(param_1,&this->lastUngroupedSoldierTaskTime,4);
  rge_write(param_1,&this->attackStateValue,0x2c);
  rge_write(param_1,this->hitsByPlayer,0x24);
  return 1;
}

// --------------------------------------------------

// Function: logGroupDebug
// Address: 004f0180
/* public: void __cdecl TribeTacticalAIModule::logGroupDebug(int,char *,...) */

void __thiscall
TribeTacticalAIModule::logGroupDebug(TribeTacticalAIModule *this,int param_1,char *param_2,...)
{
  return;
}

// --------------------------------------------------

// Function: doSomething
// Address: 004f0190
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
// [HELPER] s__s_bld: "%s.bld"
/* WARNING: Variable defined which should be unmapped: incUpdateArea */
/* public: int __thiscall TribeTacticalAIModule::doSomething(void) */

int __thiscall TribeTacticalAIModule::doSomething(TribeTacticalAIModule *this)
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
  int incUpdateArea;
  ulong updateAreaStartTime;
  ulong availableTime;
  ulong startTime;
  XYPoint position_fffffee4;
  XYPoint position_fffffeec;
  XYPoint position;
  char tempName [256];
  
  uVar1 = *(uint *)(*(int *)(this->md->_padding_ + 0x3c) + 0xf8);
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x99c);
  position_fffffee4.x = uVar3;
  if (uVar1 != 0) {
    do {
      uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x99f);
      bVar2 = true;
      switch(this->updateArea) {
      case 0:
        setupSoldierGroups(this);
        break;
      case 1:
        if (0 < (this->civilians).numberValue) {
          if (this->firstNeededResourceUpdateDone == 0) {
            this->firstNeededResourceUpdateDone = 1;
            updateNeededResources(this);
          }
          evaluateCivilianDistribution(this);
        }
        break;
      case 2:
        taskCivilians(this,uVar3,uVar1);
        if (this->nextCivilianToTaskValue != -1) {
          bVar2 = false;
        }
        break;
      case 3:
        if (0 < (this->boats).numberValue) {
          setupBoatGroups(this);
        }
        break;
      case 4:
        if (0 < (this->boats).numberValue) {
          fillBoatGroups(this);
        }
        break;
      case 5:
        if (0 < (this->boats).numberValue) {
          taskBoats(this);
        }
        break;
      case 6:
        if ((0 < (this->boats).numberValue) || (0 < (this->soldiers).numberValue)) {
          fillSoldierGroups(this);
        }
        break;
      case 7:
        if ((((0 < (this->boats).numberValue) || (0 < (this->soldiers).numberValue)) ||
            (0 < (this->artifacts).numberValue)) &&
           (taskIdleSoldiers(this,uVar3,uVar1), this->nextIdleSoldierGroupToTaskValue != -1)) {
          bVar2 = false;
        }
        break;
      case 8:
        if ((((0 < (this->boats).numberValue) || (0 < (this->soldiers).numberValue)) ||
            (0 < (this->artifacts).numberValue)) &&
           (taskActiveSoldiers(this,uVar3,uVar1), this->nextActiveSoldierGroupToTaskValue != -1)) {
          bVar2 = false;
        }
        break;
      case 9:
        if (0 < (this->soldiers).numberValue) {
          playTaskSoldiers(this,uVar3,uVar1);
        }
        break;
      case 10:
        pRVar9 = MainDecisionAIModule::object
                           ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
        if ((pRVar9 != (RGE_Static_Object *)0x0) &&
           (iVar11 = TribeInformationAIModule::withinXTilesOfObject
                               (&this->md->informationAI,pRVar9,0x14,0x4f,199,0x45,0x116),
           iVar11 != -1)) {
          saveTheTown(this,iVar11);
        }
        break;
      case 0xb:
        this->numberBuildUpdatesSkipped = this->numberBuildUpdatesSkipped + 1;
        iVar11 = BuildAIModule::buildListLength((BuildAIModule *)&this->md->buildAI);
        if (((0 < iVar11) && (this->sn[0x65] <= this->numberBuildUpdatesSkipped)) &&
           (pBVar7 = TribeBuildAIModule::nextBuildableItem(&this->md->buildAI,1),
           pBVar7 != (BuildItem *)0x0)) {
          taskResearch(this,pBVar7);
        }
        break;
      case 0xc:
        iVar11 = *(int *)(this->md->_padding_ + 0x50);
        if ((((*(float *)(iVar11 + 0x2c) < *(float *)(iVar11 + 0x80)) &&
             (iVar11 = BuildAIModule::buildListLength((BuildAIModule *)&this->md->buildAI),
             0 < iVar11)) && (this->sn[0x65] <= this->numberBuildUpdatesSkipped)) &&
           (pBVar7 = TribeBuildAIModule::nextBuildableItem(&this->md->buildAI,2),
           pBVar7 != (BuildItem *)0x0)) {
          taskTrain(this,pBVar7);
        }
        break;
      case 0xd:
        iVar11 = BuildAIModule::buildListLength((BuildAIModule *)&this->md->buildAI);
        if ((0 < iVar11) && (this->sn[0x65] <= this->numberBuildUpdatesSkipped)) {
          pBVar7 = TribeBuildAIModule::nextBuildableItem(&this->md->buildAI,3);
          if (pBVar7 != (BuildItem *)0x0) {
            pcVar5 = BaseItem::name((BaseItem *)pBVar7);
            sprintf(tempName + 4,s__s_bld,pcVar5);
            (**(code **)((this->md->buildAI)._padding_ + 0x44))(tempName + 4,this->md->aiPlayer);
            TribeMainDecisionAIModule::updateBuildAIWithObjects(this->md);
            updateNeededResources(this);
          }
          this->numberBuildUpdatesSkipped = 0;
        }
        break;
      case 0xe:
        iVar11 = initialExplorationSatisfied(this);
        if ((iVar11 != 0) &&
           ((((iVar11 = MainDecisionAIModule::numberObjectsWithAction
                                  ((MainDecisionAIModule *)this->md,0x25a), iVar11 < this->sn[4] ||
              (this->wonderInProgressValue != 0)) || (this->wonderBuiltValue != 0)) &&
            ((pRVar9 = MainDecisionAIModule::object
                                 ((MainDecisionAIModule *)this->md,-1,-1,-1,-1,-1,-1,-1,-1,0,-1),
             pRVar9 != (RGE_Static_Object *)0x0 &&
             ((pRVar6 = MainDecisionAIModule::object
                                  ((MainDecisionAIModule *)this->md,-1,-1,-1,0x25a,-1,pRVar9->id,-1,
                                   -1,-1,-1), this->wonderInProgressValue != 0 ||
              (pRVar6 == (RGE_Static_Object *)0x0)))))))) {
          position.y = __ftol();
          tempName._0_4_ = __ftol();
          iVar11 = civilian(this,(XYPoint *)&position.y,1,0x2be,0x2ce,700,0);
          if ((iVar11 != -1) && (iVar11 = taskBuilder(this,iVar11,pRVar9), iVar11 == 1)) {
            this->lastBuildTime = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
          }
        }
        break;
      case 0xf:
        iVar11 = initialExplorationSatisfied(this);
        if ((iVar11 != 0) &&
           (((iVar11 = MainDecisionAIModule::numberObjectsWithAction
                                 ((MainDecisionAIModule *)this->md,0x25a), iVar11 < this->sn[4] ||
             (this->wonderInProgressValue != 0)) || (this->wonderBuiltValue != 0)))) {
          if (this->wonderBuiltValue == 1) {
            iVar11 = 0x114;
          }
          else {
            iVar11 = -1;
          }
          pRVar9 = MainDecisionAIModule::mostDamaged((MainDecisionAIModule *)this->md,3,iVar11);
          if (((pRVar9 != (RGE_Static_Object *)0x0) && (pRVar9->object_state == '\x02')) &&
             (pRVar6 = MainDecisionAIModule::object
                                 ((MainDecisionAIModule *)this->md,-1,-1,-1,0x26a,-1,pRVar9->id,-1,
                                  -1,-1,-1), pRVar6 == (RGE_Static_Object *)0x0)) {
            position_fffffee4.y = __ftol();
            position_fffffeec.x = __ftol();
            iVar11 = civilian(this,(XYPoint *)&position_fffffee4.y,1,0x2be,0x2ce,700,0);
            if (iVar11 != -1) {
              taskRepairer(this,iVar11,pRVar9);
            }
          }
        }
        break;
      case 0x10:
        iVar11 = initialExplorationSatisfied(this);
        if (((iVar11 != 0) &&
            ((((iVar11 = MainDecisionAIModule::numberObjectsWithAction
                                   ((MainDecisionAIModule *)this->md,0x25a), iVar11 < this->sn[4] ||
               (this->wonderInProgressValue != 0)) || (this->wonderBuiltValue != 0)) &&
             ((pRVar9 = MainDecisionAIModule::mostDamaged((MainDecisionAIModule *)this->md,0x1b,-1),
              pRVar9 != (RGE_Static_Object *)0x0 && (pRVar9->object_state == '\x02')))))) &&
           (pRVar6 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)this->md,-1,-1,-1,0x26a,-1,pRVar9->id,-1,-1,
                                -1,-1), pRVar6 == (RGE_Static_Object *)0x0)) {
          position_fffffeec.y = __ftol();
          position.x = __ftol();
          iVar11 = civilian(this,(XYPoint *)&position_fffffeec.y,1,0x2be,0x2ce,700,0);
          if (iVar11 != -1) {
            taskRepairer(this,iVar11,pRVar9);
          }
        }
        break;
      case 0x11:
        iVar11 = initialExplorationSatisfied(this);
        if ((((iVar11 != 0) &&
             ((iVar11 = MainDecisionAIModule::numberObjectsWithAction
                                  ((MainDecisionAIModule *)this->md,0x25a), iVar11 < this->sn[4] ||
              ((this->wonderInProgressValue == 0 && (this->wonderBuiltValue != 0)))))) &&
            (this->wonderInProgressValue == 0)) &&
           ((pBVar7 = TribeBuildAIModule::nextBuildableItem(&this->md->buildAI,0),
            pBVar7 != (BuildItem *)0x0 &&
            (iVar11 = taskBuilder(this,-1,pBVar7,(ConstructionItem *)0x0,uVar3), iVar11 == 1)))) {
          this->lastBuildTime = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
        }
        break;
      case 0x12:
        if ((this->placementStateValue).active == 1) {
          pCVar8 = TribeConstructionAIModule::placeStructure
                             (&this->md->constructionAI,(this->placementStateValue).buildItem,
                              (this->placementStateValue).builderID,&this->placementStateValue,uVar3
                             );
          if ((pCVar8 != (ConstructionItem *)0x0) &&
             (iVar11 = taskBuilder(this,(this->placementStateValue).builderID,
                                   (this->placementStateValue).buildItem,pCVar8,uVar3), iVar11 == 1)
             ) {
            this->lastBuildTime = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
          }
          if ((this->placementStateValue).active == 1) {
            bVar2 = false;
          }
        }
        break;
      case 0x13:
        evaluateOpenTasks(this);
        iVar11 = 0;
        piVar12 = this->resourceDifferenceValue;
        do {
          if ((0 < *piVar12) &&
             (iVar13 = TribeResourceAIModule::resource(&this->md->resourceAI,iVar11),
             iVar13 + *piVar12 < 0)) {
            updateNeededResources(this);
            break;
          }
          iVar11 = iVar11 + 1;
          piVar12 = piVar12 + 1;
        } while (iVar11 < 4);
        checkForCoopTributeDemand(this);
        checkForCoopTributeGift(this);
        checkForASAPAgeResearch(this);
        checkTradeBoats(this);
        checkStaleAttackGroups(this);
        uVar3 = position_fffffee4.x;
        break;
      case 0x14:
        iVar11 = TribeInformationAIModule::closestDropsiteResID(&this->md->informationAI,0);
        pRVar9 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar11);
        if (pRVar9 == (RGE_Static_Object *)0x0) {
          TribeInformationAIModule::updateResourceDropsites(&this->md->informationAI,0);
        }
        break;
      case 0x15:
        evaluateBuildListInsertions(this);
        if (5 < (int)(*(int *)(*(int *)(this->md->_padding_ + 0x3c) + 4) - this->lastBuildTime) /
                60000) {
          TribeBuildAIModule::unskipBuildList
                    (&this->md->buildAI,this->builtFirstStoragePit,this->builtFirstGranary);
          this->lastBuildTime = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
        }
        uVar10 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xb92);
        RGE_Game_World::useComputerPlayerUpdateTime
                  (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),uVar10 - uVar3);
        iVar11 = this->updateAreaAverageTotal + (uVar10 - uVar4);
        iVar13 = this->updateAreaAverageCount + 1;
        this->lastUpdateAreaTimeValue = uVar10 - uVar4;
        this->updateAreaAverageTotal = iVar11;
        this->updateAreaAverageCount = iVar13;
        if (0x13 < iVar13) {
          this->updateAreaAverageTotal = 0;
          this->updateAreaAverageCount = 0;
          this->averageUpdateAreaTimeValue = iVar11 / iVar13;
        }
        this->updateArea = 0;
        RGE_Game_World::selectNextComputerPlayer(*(RGE_Game_World **)(this->md->_padding_ + 0x3c),3)
        ;
        return 1;
      }
      uVar10 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xbaa);
      iVar11 = this->updateAreaAverageTotal + (uVar10 - uVar4);
      iVar13 = this->updateAreaAverageCount + 1;
      this->lastUpdateAreaTimeValue = uVar10 - uVar4;
      this->updateAreaAverageTotal = iVar11;
      this->updateAreaAverageCount = iVar13;
      if (0x13 < iVar13) {
        this->updateAreaAverageTotal = 0;
        this->updateAreaAverageCount = 0;
        this->averageUpdateAreaTimeValue = iVar11 / 0x14;
      }
      if (bVar2) {
        this->updateArea = this->updateArea + 1;
      }
    } while (uVar10 - uVar3 < uVar1);
  }
                    /* language.dll match for 0xbc9: "%s paid %d stone in tribute to you." */
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xbc9);
  RGE_Game_World::useComputerPlayerUpdateTime
            (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),uVar4 - uVar3);
  return 1;
}

// --------------------------------------------------

// Function: clearArea
// Address: 004f0bc0
/* WARNING: Variable defined which should be unmapped: tempX */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TribeTacticalAIModule::clearArea(int,float,float,float,float) */

int __thiscall
TribeTacticalAIModule::clearArea
          (TribeTacticalAIModule *this,int param_1,float param_2,float param_3,float param_4,
          float param_5)
{
  code *pcVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  int iVar3;
  float fVar4;
  float tempX;
  float tempY;
  float bestDistance;
  float newY;
  float newX;
  float local_4;
  
  iVar2 = busyWithAction(this,param_1,-1);
  if ((iVar2 == 1) &&
     (this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1),
     this_00 != (RGE_Static_Object *)0x0)) {
    local_4 = -1.0;
    newX = -1.0;
    newY = -1.0;
    pcVar1 = *(code **)(this_00->_padding_ + 0x114);
    tempY = -1.0;
    bestDistance = -1.0;
    iVar2 = 0;
    do {
      switch(iVar2) {
      case 0:
        tempY = param_2 - _DAT_00575700;
        bestDistance = param_3 - _DAT_00575700;
        break;
      case 1:
      case 5:
        tempY = (param_4 + param_2) * _DAT_005756fc;
        break;
      case 2:
        tempY = param_4 - _DAT_0057575c;
        break;
      case 3:
      case 7:
        bestDistance = (param_5 + param_3) * _DAT_005756fc;
        break;
      case 4:
        bestDistance = param_5 - _DAT_0057575c;
        break;
      case 6:
        tempY = param_2 - _DAT_00575700;
      }
      iVar3 = (*pcVar1)(tempY,bestDistance,1);
      if ((iVar3 != 0) &&
         ((fVar4 = RGE_Static_Object::distance_to_position
                             (this_00,tempY,bestDistance,this_00->world_z), newY == _DAT_00575758 ||
          (fVar4 < newY)))) {
        local_4 = tempY;
        newX = bestDistance;
        newY = fVar4;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    if (newY != _DAT_00575758) {
      moveUnit(this,param_1,local_4,newX,100);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: addObject
// Address: 004f0d70
/* public: void __thiscall TribeTacticalAIModule::addObject(class RGE_Static_Object *) */

void __thiscall
TribeTacticalAIModule::addObject(TribeTacticalAIModule *this,RGE_Static_Object *param_1)
{
  short sVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  ManagedArray<int> *pMVar5;
  int iVar6;
  
  pRVar2 = param_1;
  sVar1 = param_1->master_obj->object_group;
  if (sVar1 == 4) {
    iVar4 = (this->civilians).numberValue;
    iVar6 = param_1->id;
    pMVar5 = &this->civilians;
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        if ((this->civilians).maximumSizeValue <= iVar3) break;
        if (pMVar5->value[iVar3] == iVar6) {
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar4);
    }
    if (iVar4 <= (this->civilians).maximumSizeValue + -1) goto LAB_004f1077;
  }
  else {
    if ((((((sVar1 != 0) && (sVar1 != 0x18)) && (sVar1 != 6)) &&
         (((sVar1 != 0x19 && (sVar1 != 0x1a)) &&
          ((sVar1 != 0xc && ((sVar1 != 0x23 && (sVar1 != 0x17)))))))) && (sVar1 != 0x24)) &&
       ((((sVar1 != 0x1c && (sVar1 != 0x12)) && (sVar1 != 0xd)) && (sVar1 != 0x27)))) {
      if (((sVar1 != 2) && (sVar1 != 0x14)) && ((sVar1 != 0x16 && (sVar1 != 0x15)))) {
        if (param_1->master_obj->id != 0x9f) {
          return;
        }
        iVar4 = RGE_Game_World::difficultyLevel(*(RGE_Game_World **)(this->md->_padding_ + 0x3c));
        if (3 < iVar4) {
          return;
        }
        ManagedArray<int>::add(&this->artifacts,pRVar2->id);
        return;
      }
      iVar4 = (this->boats).numberValue;
      iVar6 = param_1->id;
      pMVar5 = &this->boats;
      iVar3 = 0;
      if (0 < iVar4) {
        do {
          if ((this->boats).maximumSizeValue <= iVar3) break;
          if (pMVar5->value[iVar3] == iVar6) goto LAB_004f0ee8;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar4);
      }
      if ((this->boats).maximumSizeValue + -1 < iVar4) {
        ManagedArray<int>::resize(pMVar5,iVar4 + 1);
      }
      pMVar5->value[(this->boats).numberValue] = iVar6;
      (this->boats).numberValue = (this->boats).numberValue + 1;
LAB_004f0ee8:
      if (pRVar2->master_obj->object_group == 2) {
        iVar4 = (this->tradeBoats).numberValue;
        iVar6 = pRVar2->id;
        pMVar5 = &this->tradeBoats;
        iVar3 = 0;
        if (0 < iVar4) {
          do {
            if ((this->tradeBoats).maximumSizeValue <= iVar3) break;
            if (pMVar5->value[iVar3] == iVar6) goto LAB_004f0f45;
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar4);
        }
        if ((this->tradeBoats).maximumSizeValue + -1 < iVar4) {
          ManagedArray<int>::resize(pMVar5,iVar4 + 1);
        }
        pMVar5->value[(this->tradeBoats).numberValue] = iVar6;
        (this->tradeBoats).numberValue = (this->tradeBoats).numberValue + 1;
      }
LAB_004f0f45:
      if (pRVar2->master_obj->object_group == 0x14) {
        param_1 = (RGE_Static_Object *)pRVar2->id;
        pMVar5 = &this->transportBoats;
        iVar4 = ManagedArray<int>::contains(pMVar5,(int *)&param_1);
        if (iVar4 != 1) {
          iVar4 = (this->transportBoats).numberValue;
          if ((this->transportBoats).maximumSizeValue + -1 < iVar4) {
            ManagedArray<int>::resize(pMVar5,iVar4 + 1);
          }
          pMVar5->value[(this->transportBoats).numberValue] = (int)param_1;
          (this->transportBoats).numberValue = (this->transportBoats).numberValue + 1;
        }
      }
      if (pRVar2->master_obj->object_group == 0x16) {
        param_1 = (RGE_Static_Object *)pRVar2->id;
        pMVar5 = &this->warBoats;
        iVar4 = ManagedArray<int>::contains(pMVar5,(int *)&param_1);
        if (iVar4 != 1) {
          iVar4 = (this->warBoats).numberValue;
          if ((this->warBoats).maximumSizeValue + -1 < iVar4) {
            ManagedArray<int>::resize(pMVar5,iVar4 + 1);
          }
          pMVar5->value[(this->warBoats).numberValue] = (int)param_1;
          (this->warBoats).numberValue = (this->warBoats).numberValue + 1;
        }
      }
      if (pRVar2->master_obj->object_group != 0x15) {
        return;
      }
      param_1 = (RGE_Static_Object *)pRVar2->id;
      pMVar5 = &this->fishingBoats;
      iVar4 = ManagedArray<int>::contains(pMVar5,(int *)&param_1);
      if (iVar4 == 1) {
        return;
      }
      iVar4 = (this->fishingBoats).numberValue;
      if ((this->fishingBoats).maximumSizeValue + -1 < iVar4) {
        ManagedArray<int>::resize(pMVar5,iVar4 + 1);
      }
      pMVar5->value[(this->fishingBoats).numberValue] = (int)param_1;
      (this->fishingBoats).numberValue = (this->fishingBoats).numberValue + 1;
      return;
    }
    iVar4 = (this->soldiers).numberValue;
    iVar6 = param_1->id;
    pMVar5 = &this->soldiers;
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        if ((this->soldiers).maximumSizeValue <= iVar3) break;
        if (pMVar5->value[iVar3] == iVar6) {
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar4);
    }
    if (iVar4 <= (this->soldiers).maximumSizeValue + -1) goto LAB_004f1077;
  }
  ManagedArray<int>::resize(pMVar5,iVar4 + 1);
LAB_004f1077:
  pMVar5->value[pMVar5->numberValue] = iVar6;
  pMVar5->numberValue = pMVar5->numberValue + 1;
  return;
}

// --------------------------------------------------

// Function: removeObject
// Address: 004f1090
/* public: void __thiscall TribeTacticalAIModule::removeObject(int) */

void __thiscall TribeTacticalAIModule::removeObject(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  ManagedArray<int> *this_00;
  
  removeFromTaskLists(this,param_1);
  iVar2 = (this->civilians).numberValue;
  iVar1 = 0;
  if (0 < iVar2) {
    do {
      if ((this->civilians).maximumSizeValue <= iVar1) break;
      if ((this->civilians).value[iVar1] == param_1) {
        iVar2 = (this->civilians).maximumSizeValue;
        iVar1 = 0;
        if (iVar2 < 1) goto LAB_004f1343;
        piVar3 = (this->civilians).value;
        goto LAB_004f1337;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  iVar2 = (this->soldiers).numberValue;
  iVar1 = 0;
  if (0 < iVar2) {
    do {
      if ((this->soldiers).maximumSizeValue <= iVar1) break;
      if ((this->soldiers).value[iVar1] == param_1) {
        iVar2 = (this->soldiers).maximumSizeValue;
        iVar1 = 0;
        if (iVar2 < 1) goto LAB_004f1120;
        piVar3 = (this->soldiers).value;
        goto LAB_004f1114;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  iVar2 = (this->boats).numberValue;
  iVar1 = 0;
  if (0 < iVar2) {
    do {
      if ((this->boats).maximumSizeValue <= iVar1) break;
      if ((this->boats).value[iVar1] == param_1) {
        iVar2 = (this->boats).maximumSizeValue;
        iVar1 = 0;
        if (iVar2 < 1) goto LAB_004f11c4;
        piVar3 = (this->boats).value;
        goto LAB_004f11b8;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  this_00 = &this->artifacts;
  iVar2 = ManagedArray<int>::contains(this_00,&param_1);
joined_r0x004f12e7:
  if (iVar2 == 0) goto LAB_004f1316;
  goto LAB_004f130b;
  while( true ) {
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
    if (iVar2 <= iVar1) break;
LAB_004f1337:
    if (*piVar3 == param_1) break;
  }
LAB_004f1343:
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar3 = (this->civilians).value;
        iVar2 = iVar1 + 1;
        piVar3[iVar1] = piVar3[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (this->civilians).maximumSizeValue + -1);
    }
    iVar2 = (this->civilians).numberValue + -1;
    (this->civilians).numberValue = iVar2;
    if (iVar2 < 0) {
      (this->civilians).numberValue = 0;
      removeFromGroup(this,param_1);
      return;
    }
  }
  goto LAB_004f1316;
  while( true ) {
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
    if (iVar2 <= iVar1) break;
LAB_004f1114:
    if (*piVar3 == param_1) break;
  }
LAB_004f1120:
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar3 = (this->soldiers).value;
        iVar2 = iVar1 + 1;
        piVar3[iVar1] = piVar3[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (this->soldiers).maximumSizeValue + -1);
    }
    iVar2 = (this->soldiers).numberValue + -1;
    (this->soldiers).numberValue = iVar2;
    if (iVar2 < 0) {
      (this->soldiers).numberValue = 0;
      removeFromGroup(this,param_1);
      return;
    }
  }
  goto LAB_004f1316;
  while( true ) {
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
    if (iVar2 <= iVar1) break;
LAB_004f11b8:
    if (*piVar3 == param_1) break;
  }
LAB_004f11c4:
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar3 = (this->boats).value;
        iVar2 = iVar1 + 1;
        piVar3[iVar1] = piVar3[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (this->boats).maximumSizeValue + -1);
    }
    iVar2 = (this->boats).numberValue + -1;
    (this->boats).numberValue = iVar2;
    if (iVar2 < 0) {
      (this->boats).numberValue = 0;
    }
  }
  iVar2 = (this->warBoats).numberValue;
  iVar1 = 0;
  if (0 < iVar2) {
    do {
      if ((this->warBoats).maximumSizeValue <= iVar1) break;
      if ((this->warBoats).value[iVar1] == param_1) {
        iVar2 = (this->warBoats).maximumSizeValue;
        iVar1 = 0;
        if (iVar2 < 1) goto LAB_004f124e;
        piVar3 = (this->warBoats).value;
        goto LAB_004f1242;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  this_00 = &this->fishingBoats;
  iVar2 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar2 == 0) {
    this_00 = &this->tradeBoats;
    iVar2 = ManagedArray<int>::contains(this_00,&param_1);
    if (iVar2 == 0) {
      this_00 = &this->transportBoats;
      iVar2 = ManagedArray<int>::contains(this_00,&param_1);
      goto joined_r0x004f12e7;
    }
  }
LAB_004f130b:
  ManagedArray<int>::remove(this_00,param_1);
  goto LAB_004f1316;
  while( true ) {
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
    if (iVar2 <= iVar1) break;
LAB_004f1242:
    if (*piVar3 == param_1) break;
  }
LAB_004f124e:
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar3 = (this->warBoats).value;
        iVar2 = iVar1 + 1;
        piVar3[iVar1] = piVar3[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (this->warBoats).maximumSizeValue + -1);
    }
    iVar2 = (this->warBoats).numberValue + -1;
    (this->warBoats).numberValue = iVar2;
    if (iVar2 < 0) {
      (this->warBoats).numberValue = 0;
      removeFromGroup(this,param_1);
      return;
    }
  }
LAB_004f1316:
  removeFromGroup(this,param_1);
  return;
}

// --------------------------------------------------

// Function: evaluateCivilianDistribution
// Address: 004f13f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TribeTacticalAIModule::evaluateCivilianDistribution(void) */

void __thiscall TribeTacticalAIModule::evaluateCivilianDistribution(TribeTacticalAIModule *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  RGE_Visible_Map::percentExplored(*(RGE_Visible_Map **)(this->md->_padding_ + 0x38));
  iVar1 = __ftol();
  if ((this->playersToAttack).maximumSizeValue + -1 < 0) {
    ManagedArray<int>::resize(&this->playersToAttack,1);
  }
  iVar2 = TribeInformationAIModule::numberGameIDsOwnedBy
                    (&this->md->informationAI,-1,*(this->playersToAttack).value);
  iVar3 = (this->civilians).numberValue;
  if (iVar3 < 3) {
    iVar1 = 1;
    if (iVar3 == 1) {
      this->desiredNumberGatherersValue = 0;
    }
    else {
      iVar1 = this->sn[5];
      this->desiredNumberGatherersValue = 1;
      if ((iVar1 != -1) && (iVar1 < 1)) {
        this->desiredNumberGatherersValue = iVar1;
      }
      iVar3 = (this->civilians).numberValue - this->desiredNumberGatherersValue;
      (this->civilianExplorers).desiredNumberValue = iVar3;
      iVar1 = this->sn[3];
      if ((iVar1 == -1) || (iVar3 <= iVar1)) goto LAB_004f15df;
    }
    (this->civilianExplorers).desiredNumberValue = iVar1;
    goto LAB_004f15df;
  }
  if ((this->civilians).maximumSizeValue + -1 < 0) {
    ManagedArray<int>::resize(&this->civilians,1);
  }
  iVar3 = TribeInformationAIModule::fullyExploredZone
                    (&this->md->informationAI,*(this->civilians).value);
  if (iVar3 == 1) {
    ceil((double)((float)this->sn[0] * (float)(this->civilians).numberValue * _DAT_00575764));
    iVar3 = __ftol();
    (this->civilianExplorers).desiredNumberValue = iVar3;
    iVar3 = numberSoldierExplorers(this);
    if (this->sn[0x12] < iVar3 + (this->civilianExplorers).desiredNumberValue) {
      (this->civilianExplorers).desiredNumberValue = this->sn[0x12] - iVar3;
    }
    iVar3 = this->sn[3];
    if ((iVar3 != -1) && (iVar3 < (this->civilianExplorers).desiredNumberValue)) {
      (this->civilianExplorers).desiredNumberValue = iVar3;
    }
  }
  else {
    (this->civilianExplorers).desiredNumberValue = 0;
  }
  if ((iVar1 < this->sn[0x20]) || (iVar2 <= this->sn[0x91])) {
    if (this->sn[0xb3] <= iVar1) {
      iVar1 = (this->civilianExplorers).desiredNumberValue / 2;
      if (iVar1 < 1) {
        iVar1 = 0;
      }
      goto LAB_004f1535;
    }
  }
  else {
    iVar1 = this->sn[0x23];
    if (iVar1 < (this->civilianExplorers).desiredNumberValue) {
LAB_004f1535:
      (this->civilianExplorers).desiredNumberValue = iVar1;
    }
  }
  if (this->zoomingToNextAge == 1) {
    (this->civilianExplorers).desiredNumberValue = 0;
  }
  iVar1 = this->sn[5];
  iVar3 = (this->civilians).numberValue - (this->civilianExplorers).desiredNumberValue;
  this->desiredNumberGatherersValue = iVar3;
  if ((iVar1 != -1) && (iVar1 < iVar3)) {
    this->desiredNumberGatherersValue = iVar1;
    displayCivilianDistribution(this);
    updateGathererDistribution(this);
    return;
  }
LAB_004f15df:
  displayCivilianDistribution(this);
  updateGathererDistribution(this);
  return;
}

// --------------------------------------------------

// Function: taskCivilians
// Address: 004f1600
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Variable defined which should be unmapped: j */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TribeTacticalAIModule::taskCivilians(unsigned long,unsigned long) */

int __thiscall
TribeTacticalAIModule::taskCivilians(TribeTacticalAIModule *this,ulong param_1,ulong param_2)
{
  ManagedArray<int> *this_00;
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  UnitData *pUVar7;
  ulong uVar8;
  int j;
  int newExplorer;
  int taskedCount;
  XYPoint tcPosition;
  
  if ((this->civilians).numberValue < 1) {
    this->nextCivilianToTaskValue = -1;
    return 0;
  }
  tcPosition.x = 0;
  if (this->nextCivilianToTaskValue == -1) {
    if ((this->civilianExplorers).numberValue < (this->civilianExplorers).desiredNumberValue) {
      do {
        pRVar1 = MainDecisionAIModule::object
                           ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
        if (pRVar1 == (RGE_Static_Object *)0x0) {
          iVar2 = idleCivilian(this,-1);
        }
        else {
          tcPosition.y = __ftol();
          __ftol();
          iVar2 = idleCivilian(this,-1,(XYPoint *)&tcPosition.y,0);
        }
        if (iVar2 == -1) {
          if (this->desiredNumberGatherersValue < this->numberGatherersValue) {
            newExplorer = 3;
            piVar5 = this->neededResourceValue + 3;
            taskedCount = iVar2;
            do {
              if (iVar2 != -1) goto LAB_004f1799;
              pRVar1 = MainDecisionAIModule::object
                                 ((MainDecisionAIModule *)this->md,-1,-1,-1,0x261,0x25d,-1,-1,
                                  *piVar5,-1,0);
              if (((pRVar1 != (RGE_Static_Object *)0x0) ||
                  (pRVar1 = MainDecisionAIModule::object
                                      ((MainDecisionAIModule *)this->md,-1,-1,-1,0x265,0x25d,-1,-1,
                                       *piVar5,-1,0), pRVar1 != (RGE_Static_Object *)0x0)) &&
                 (pRVar1->attribute_amount_held == _DAT_005756f0)) {
                iVar6 = (this->civilianExplorers).numberValue;
                iVar4 = pRVar1->id;
                iVar3 = 0;
                if (0 < iVar6) {
                  do {
                    if ((this->civilianExplorers).maximumSizeValue <= iVar3) break;
                    iVar2 = taskedCount;
                    if ((this->civilianExplorers).value[iVar3] == iVar4) goto LAB_004f177f;
                    iVar3 = iVar3 + 1;
                  } while (iVar3 < iVar6);
                }
                removeGatherer(this,iVar4);
                iVar2 = iVar4;
                taskedCount = iVar4;
              }
LAB_004f177f:
              piVar5 = piVar5 + -1;
              newExplorer = newExplorer - 1;
            } while ((uint)newExplorer < 0x80000000);
          }
          if (iVar2 == -1) break;
        }
LAB_004f1799:
        iVar6 = (this->civilianExplorers).numberValue;
        this_00 = &this->civilianExplorers;
        iVar4 = 0;
        if (0 < iVar6) {
          do {
            if ((this->civilianExplorers).maximumSizeValue <= iVar4) break;
            if (this_00->value[iVar4] == iVar2) goto LAB_004f17f1;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar6);
        }
        if ((this->civilianExplorers).maximumSizeValue + -1 < iVar6) {
          ManagedArray<int>::resize(this_00,iVar6 + 1);
        }
        this_00->value[(this->civilianExplorers).numberValue] = iVar2;
        (this->civilianExplorers).numberValue = (this->civilianExplorers).numberValue + 1;
      } while ((this->civilianExplorers).numberValue < (this->civilianExplorers).desiredNumberValue)
      ;
    }
LAB_004f17f1:
    iVar2 = (this->civilianExplorers).numberValue;
    if ((this->civilianExplorers).desiredNumberValue < iVar2) {
      do {
        if (iVar2 < 1) break;
        if (((this->civilianExplorers).maximumSizeValue + -1 < 0) &&
           (piVar5 = (int *)operator_new(4), piVar5 != (int *)0x0)) {
          iVar2 = 0;
          if (0 < (this->civilianExplorers).maximumSizeValue) {
            do {
              if (0 < iVar2) break;
              iVar6 = iVar2 + 1;
              piVar5[iVar2] = (this->civilianExplorers).value[iVar2];
              iVar2 = iVar6;
            } while (iVar6 < (this->civilianExplorers).maximumSizeValue);
          }
          operator_delete((this->civilianExplorers).value);
          (this->civilianExplorers).value = piVar5;
          (this->civilianExplorers).maximumSizeValue = 1;
        }
        iVar4 = 0;
        iVar2 = *(this->civilianExplorers).value;
        iVar6 = (this->civilianExplorers).maximumSizeValue;
        if (0 < iVar6) {
          piVar5 = (this->civilianExplorers).value;
          do {
            if (*piVar5 == iVar2) break;
            iVar4 = iVar4 + 1;
            piVar5 = piVar5 + 1;
          } while (iVar4 < iVar6);
        }
        if (iVar4 < iVar6) {
          if (iVar4 < iVar6 + -1) {
            do {
              piVar5 = (this->civilianExplorers).value;
              iVar6 = iVar4 + 1;
              piVar5[iVar4] = piVar5[iVar6];
              iVar4 = iVar6;
            } while (iVar6 < (this->civilianExplorers).maximumSizeValue + -1);
          }
          iVar6 = (this->civilianExplorers).numberValue + -1;
          (this->civilianExplorers).numberValue = iVar6;
          if (iVar6 < 0) {
            (this->civilianExplorers).numberValue = 0;
          }
        }
        stopUnit(this,iVar2,100);
        iVar2 = (this->civilianExplorers).numberValue;
      } while ((this->civilianExplorers).desiredNumberValue < iVar2);
    }
    if (this->numberGatherersValue < this->desiredNumberGatherersValue) {
      do {
        pRVar1 = MainDecisionAIModule::object
                           ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
        if (pRVar1 == (RGE_Static_Object *)0x0) {
          iVar2 = idleCivilian(this,-1);
        }
        else {
          tcPosition.y = __ftol();
          __ftol();
          iVar2 = idleCivilian(this,-1,(XYPoint *)&tcPosition.y,0);
        }
      } while (((iVar2 != -1) && (pUVar7 = addGatherer(this,iVar2), pUVar7 != (UnitData *)0x0)) &&
              (this->numberGatherersValue < this->desiredNumberGatherersValue));
    }
    if ((this->civilians).maximumSizeValue + -1 < 0) {
      ManagedArray<int>::resize(&this->civilians,1);
    }
    this->nextCivilianToTaskValue = *(this->civilians).value;
    uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xd8a);
    if (param_2 <= uVar8 - param_1) {
      return 0;
    }
  }
  iVar2 = 0;
  if (0 < (this->civilians).numberValue) {
    do {
      if ((this->civilians).maximumSizeValue + -1 < iVar2) {
        piVar5 = (int *)operator_new(iVar2 * 4 + 4);
        if (piVar5 != (int *)0x0) {
          iVar6 = 0;
          if (0 < (this->civilians).maximumSizeValue) {
            do {
              if (iVar2 + 1 <= iVar6) break;
              iVar4 = iVar6 + 1;
              piVar5[iVar6] = (this->civilians).value[iVar6];
              iVar6 = iVar4;
            } while (iVar4 < (this->civilians).maximumSizeValue);
          }
          operator_delete((this->civilians).value);
          (this->civilians).value = piVar5;
          (this->civilians).maximumSizeValue = iVar2 + 1;
        }
      }
    } while ((this->nextCivilianToTaskValue != (this->civilians).value[iVar2]) &&
            (iVar2 = iVar2 + 1, iVar2 < (this->civilians).numberValue));
  }
  if ((this->civilians).numberValue <= iVar2) {
LAB_004f1d72:
    this->nextCivilianToTaskValue = -1;
    return tcPosition.x;
  }
  taskedCount = iVar2 + 1;
  newExplorer = taskedCount * 4;
LAB_004f1a80:
  tcPosition.x = tcPosition.x + 1;
  if (((this->civilians).maximumSizeValue + -1 < iVar2) &&
     (piVar5 = (int *)operator_new(newExplorer), piVar5 != (int *)0x0)) {
    iVar6 = 0;
    if (0 < (this->civilians).maximumSizeValue) {
      do {
        if (taskedCount <= iVar6) break;
        iVar4 = iVar6 + 1;
        piVar5[iVar6] = (this->civilians).value[iVar6];
        iVar6 = iVar4;
      } while (iVar4 < (this->civilians).maximumSizeValue);
    }
    operator_delete((this->civilians).value);
    (this->civilians).value = piVar5;
    (this->civilians).maximumSizeValue = taskedCount;
  }
  iVar6 = (this->civilianExplorers).numberValue;
  iVar4 = 0;
  if (0 < iVar6) {
    do {
      if ((this->civilianExplorers).maximumSizeValue <= iVar4) break;
      if ((this->civilianExplorers).value[iVar4] == (this->civilians).value[iVar2]) {
        if ((iVar2 <= (this->civilians).maximumSizeValue + -1) ||
           (piVar5 = (int *)operator_new(newExplorer), piVar5 == (int *)0x0)) goto LAB_004f1df6;
        iVar6 = 0;
        if ((this->civilians).maximumSizeValue < 1) goto LAB_004f1dd5;
        goto LAB_004f1db8;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar6);
  }
  if (((this->civilians).maximumSizeValue + -1 < iVar2) &&
     (piVar5 = (int *)operator_new(newExplorer), piVar5 != (int *)0x0)) {
    iVar6 = 0;
    if (0 < (this->civilians).maximumSizeValue) {
      do {
        if (taskedCount <= iVar6) break;
        iVar4 = iVar6 + 1;
        piVar5[iVar6] = (this->civilians).value[iVar6];
        iVar6 = iVar4;
      } while (iVar4 < (this->civilians).maximumSizeValue);
    }
    operator_delete((this->civilians).value);
    (this->civilians).value = piVar5;
    (this->civilians).maximumSizeValue = taskedCount;
  }
  iVar6 = highLevelTaskGatherer(this,(this->civilians).value[iVar2],param_1);
  if (iVar6 != 0) goto LAB_004f1c2b;
  if (((this->civilians).maximumSizeValue + -1 < iVar2) &&
     (piVar5 = (int *)operator_new(newExplorer), piVar5 != (int *)0x0)) {
    iVar6 = 0;
    if (0 < (this->civilians).maximumSizeValue) {
      do {
        if (taskedCount <= iVar6) break;
        iVar4 = iVar6 + 1;
        piVar5[iVar6] = (this->civilians).value[iVar6];
        iVar6 = iVar4;
      } while (iVar4 < (this->civilians).maximumSizeValue);
    }
    operator_delete((this->civilians).value);
    (this->civilians).value = piVar5;
    (this->civilians).maximumSizeValue = taskedCount;
  }
  addGatherer(this,(this->civilians).value[iVar2]);
  goto LAB_004f1ce0;
  while( true ) {
    iVar4 = iVar6 + 1;
    piVar5[iVar6] = (this->civilians).value[iVar6];
    iVar6 = iVar4;
    if ((this->civilians).maximumSizeValue <= iVar4) break;
LAB_004f1db8:
    if (taskedCount <= iVar6) break;
  }
LAB_004f1dd5:
  operator_delete((this->civilians).value);
  (this->civilians).value = piVar5;
  (this->civilians).maximumSizeValue = taskedCount;
LAB_004f1df6:
  highLevelTaskExplorer(this,(this->civilians).value[iVar2],1);
LAB_004f1c2b:
  updateGathererDistribution(this);
  iVar6 = iVar2 + 1;
  if ((this->civilians).numberValue <= iVar6) goto LAB_004f1d72;
  if (((this->civilians).maximumSizeValue + -1 < iVar6) &&
     (piVar5 = (int *)operator_new(newExplorer + 4), piVar5 != (int *)0x0)) {
    iVar4 = 0;
    if (0 < (this->civilians).maximumSizeValue) {
      do {
        if (taskedCount + 1 <= iVar4) break;
        iVar3 = iVar4 + 1;
        piVar5[iVar4] = (this->civilians).value[iVar4];
        iVar4 = iVar3;
      } while (iVar3 < (this->civilians).maximumSizeValue);
    }
    operator_delete((this->civilians).value);
    (this->civilians).value = piVar5;
    (this->civilians).maximumSizeValue = taskedCount + 1;
  }
  this->nextCivilianToTaskValue = (this->civilians).value[iVar6];
  uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xdc6);
  if (param_2 <= uVar8 - param_1) {
    if (iVar6 < 1) {
      return tcPosition.x;
    }
    if (iVar2 <= (this->civilians).maximumSizeValue + -1) {
      return tcPosition.x;
    }
    iVar2 = iVar2 + 1;
    piVar5 = (int *)operator_new(iVar2 * 4);
    if (piVar5 == (int *)0x0) {
      return tcPosition.x;
    }
    iVar6 = 0;
    if (0 < (this->civilians).maximumSizeValue) goto LAB_004f1d2c;
    goto LAB_004f1d49;
  }
LAB_004f1ce0:
  taskedCount = taskedCount + 1;
  newExplorer = newExplorer + 4;
  iVar2 = iVar2 + 1;
  if ((this->civilians).numberValue <= iVar2) goto LAB_004f1d72;
  goto LAB_004f1a80;
  while( true ) {
    iVar4 = iVar6 + 1;
    piVar5[iVar6] = (this->civilians).value[iVar6];
    iVar6 = iVar4;
    if ((this->civilians).maximumSizeValue <= iVar4) break;
LAB_004f1d2c:
    if (iVar2 <= iVar6) break;
  }
LAB_004f1d49:
  operator_delete((this->civilians).value);
  (this->civilians).value = piVar5;
  (this->civilians).maximumSizeValue = iVar2;
  return tcPosition.x;
}

// --------------------------------------------------

// Function: taskIdleSoldiers
// Address: 004f1e10
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Variable defined which should be unmapped: readyToTask */
/* public: void __thiscall TribeTacticalAIModule::taskIdleSoldiers(unsigned long,unsigned long) */

void __thiscall
TribeTacticalAIModule::taskIdleSoldiers(TribeTacticalAIModule *this,ulong param_1,ulong param_2)
{
  bool bVar1;
  uchar uVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  RGE_Static_Object *this_00;
  RGE_Static_Object *pRVar7;
  ulong uVar8;
  TacticalAIGroup *this_01;
  int readyToTask;
  int isGathered;
  
  this_01 = (this->groups).next;
  if (this->nextIdleSoldierGroupToTaskValue != -1) {
    while (((this_01 != &this->groups && (this_01 != (TacticalAIGroup *)0x0)) &&
           (iVar4 = TacticalAIGroup::id(this_01), iVar4 != this->nextIdleSoldierGroupToTaskValue)))
{
      this_01 = this_01->next;
    }
    iVar4 = TacticalAIGroup::id(this_01);
    if (iVar4 != this->nextIdleSoldierGroupToTaskValue) {
      this_01 = (this->groups).next;
    }
  }
  do {
    while( true ) {
      if ((this_01 == &this->groups) || (this_01 == (TacticalAIGroup *)0x0)) {
        this->nextIdleSoldierGroupToTaskValue = -1;
        return;
      }
      iVar4 = TacticalAIGroup::type(this_01);
      if (((iVar4 != 0x6b) && (iVar4 = TacticalAIGroup::type(this_01), iVar4 != 0x6c)) &&
         ((iVar4 = TacticalAIGroup::type(this_01), iVar4 != 0x6a &&
          ((iVar4 = TacticalAIGroup::action(this_01), iVar4 == 0 ||
           (iVar4 = TacticalAIGroup::action(this_01), iVar4 == 1)))))) break;
      this_01 = this_01->next;
    }
    iVar4 = 1;
    bVar1 = true;
    if (this_01->consecutiveGatherAttemptsValue < 0xb) {
      iVar4 = TacticalAIGroup::isGathered(this_01,this,this->md);
    }
    iVar5 = TacticalAIGroup::desiredNumberUnits(this_01);
    iVar6 = TacticalAIGroup::numberUnits(this_01);
    if (iVar6 < iVar5) {
      iVar5 = TacticalAIGroup::commander(this_01);
      this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar5);
      pRVar7 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
      if ((this_00 == (RGE_Static_Object *)0x0) || (pRVar7 == (RGE_Static_Object *)0x0)) {
        bVar1 = false;
      }
      else {
        uVar2 = RGE_Static_Object::currentZone(this_00);
        iVar5 = __ftol();
        iVar6 = __ftol();
        uVar3 = RGE_Static_Object::lookupZone(this_00,iVar6,iVar5);
        if (uVar2 == uVar3) {
          bVar1 = false;
        }
        else {
          iVar5 = TacticalAIGroup::numberUnits(this_01);
          TacticalAIGroup::setDesiredNumberUnits(this_01,iVar5);
        }
      }
    }
    else if (iVar4 == 0) {
      bVar1 = false;
    }
    else {
      iVar5 = TacticalAIGroup::allUnitsIdle(this_01,this->md,1);
      if (iVar5 == 0) {
        bVar1 = false;
      }
      else {
        iVar5 = TacticalAIGroup::type(this_01);
        if ((iVar5 == 0x66) || (iVar5 = TacticalAIGroup::type(this_01), iVar5 == 0x69)) {
          iVar5 = TacticalAIGroup::commander(this_01);
          iVar5 = TribeInformationAIModule::fullyExploredZone(&this->md->informationAI,iVar5);
          if (iVar5 == 0) {
            bVar1 = false;
            goto LAB_004f20e6;
          }
        }
        iVar5 = TacticalAIGroup::type(this_01);
        if ((iVar5 == 100) || (iVar5 = TacticalAIGroup::type(this_01), iVar5 == 0x67)) {
          iVar5 = TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI);
          if (iVar5 == 0) {
            iVar5 = itemToCapture(this);
            if ((iVar5 == -1) && (iVar5 = TacticalAIGroup::type(this_01), iVar5 == 100)) {
              bVar1 = false;
            }
            else {
              TacticalAIGroup::setSubType(this_01,0);
            }
          }
          iVar5 = TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI);
          if (iVar5 == 4) {
            iVar5 = itemToBringToArea(this);
            if ((iVar5 == -1) && (iVar5 = TacticalAIGroup::type(this_01), iVar5 == 100)) {
              bVar1 = false;
            }
            else {
              TacticalAIGroup::setSubType(this_01,4);
            }
          }
        }
        else {
          iVar5 = TacticalAIGroup::type(this_01);
          if (((iVar5 == 0x65) || (iVar5 = TacticalAIGroup::type(this_01), iVar5 == 0x68)) &&
             (iVar5 = numberItemsToDefend(this), iVar5 == 0)) {
            bVar1 = false;
          }
        }
      }
    }
LAB_004f20e6:
    if (bVar1) {
      iVar4 = TacticalAIGroup::type(this_01);
      if ((iVar4 == 0x66) || (iVar4 = TacticalAIGroup::type(this_01), iVar4 == 0x69)) {
LAB_004f218b:
        iVar4 = 8;
      }
      else {
        iVar4 = TacticalAIGroup::type(this_01);
        if ((iVar4 == 100) || (iVar4 = TacticalAIGroup::type(this_01), iVar4 == 0x67)) {
          iVar4 = numberItemsToAttack(this);
          if ((iVar4 == 0) && (iVar4 = TacticalAIGroup::type(this_01), iVar4 == 0x67)) {
            TacticalAIGroup::setType(this_01,0x69);
            goto LAB_004f218b;
          }
          iVar4 = 2;
        }
        else {
          iVar4 = TacticalAIGroup::type(this_01);
          if ((iVar4 == 0x65) || (iVar4 = TacticalAIGroup::type(this_01), iVar4 == 0x68)) {
            iVar4 = 4;
          }
          else {
            iVar4 = TacticalAIGroup::type(this_01);
            if (iVar4 != 0x6d) goto LAB_004f2194;
            iVar4 = 0x13;
          }
        }
      }
      TacticalAIGroup::setAction(this_01,iVar4);
    }
    else if (iVar4 == 0) {
      TacticalAIGroup::task(this_01,this,this->md,9,1,0);
    }
LAB_004f2194:
    this_01 = this_01->next;
    iVar4 = TacticalAIGroup::id(this_01);
    this->nextIdleSoldierGroupToTaskValue = iVar4;
    uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xea9);
    if (param_2 <= uVar8 - param_1) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: taskActiveSoldiers
// Address: 004f21f0
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
// [HELPER] s_____Unit__d_has_invalid_unitAI_: "    Unit %d has invalid unitAI."
// [HELPER] s_____Unit__d_is_invalid_: "    Unit %d is invalid."
/* WARNING: Variable defined which should be unmapped: commanderObj */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TribeTacticalAIModule::taskActiveSoldiers(unsigned long,unsigned long) */

void __thiscall
TribeTacticalAIModule::taskActiveSoldiers(TribeTacticalAIModule *this,ulong param_1,ulong param_2)
{
  uchar uVar1;
  uchar uVar2;
  byte bVar3;
  int *piVar4;
  code *pcVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  XYPoint XVar9;
  XYPoint XVar10;
  byte bVar11;
  uchar uVar12;
  int iVar13;
  ulong uVar14;
  RGE_Static_Object *pRVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int *piVar19;
  Path *pPVar20;
  TacticalAIGroup *pTVar21;
  UnitAIModule *pUVar22;
  RGE_Action *pRVar23;
  Waypoint *pWVar24;
  int iVar25;
  AIModule *this_00;
  AIModule *this_01;
  RGE_Static_Object *pRVar26;
  ObjectMemory *pOVar27;
  uint uVar28;
  TacticalAIGroup *this_02;
  float10 fVar29;
  float fVar30;
  float fVar31;
  Waypoint *pWVar32;
  TribeMainDecisionAIModule *pTVar33;
  float fVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  RGE_Static_Object *commanderObj;
  int allInsideTransport;
  int allOutsideTransport;
  RGE_Static_Object *unitObj;
  XYPoint stagingPoint;
  XYZPoint point_ffffff44;
  uchar targetZone;
  XYZPoint point;
  XYZPoint point_ffffff60;
  XYZPoint point_ffffff6c;
  float pathDistance_ffffff78;
  RGE_Action_Object *transportObject;
  float pathDistance_ffffff80;
  float pathDistance;
  float pathDistance_ffffff88;
  XYPoint commanderPoint;
  XYZPoint point_ffffff94;
  RGE_Static_Object *targetObj;
  Waypoint tAreaMin;
  Waypoint tAreaMax;
  XYZPoint targetPoint;
  float gatherY;
  float gatherY_ffffffd4;
  XYPoint startPoint;
  float gatherX_ffffffe0;
  float gatherY_ffffffe4;
  float pathDistance_ffffffe8;
  float gatherX_ffffffec;
  float gatherX_fffffff0;
  float gatherX;
  float gatherY_fffffff8;
  undefined1 auStack_4 [4];
  
  this_02 = (this->groups).next;
  if (this->nextActiveSoldierGroupToTaskValue != -1) {
    while (((this_02 != &this->groups && (this_02 != (TacticalAIGroup *)0x0)) &&
           (iVar13 = TacticalAIGroup::id(this_02), iVar13 != this->nextActiveSoldierGroupToTaskValue
           ))) {
      this_02 = this_02->next;
    }
    iVar13 = TacticalAIGroup::id(this_02);
    if (iVar13 != this->nextActiveSoldierGroupToTaskValue) {
      this_02 = (this->groups).next;
    }
  }
  if (this_02 != &this->groups) {
    do {
      if (this_02 == (TacticalAIGroup *)0x0) break;
      iVar13 = TacticalAIGroup::type(this_02);
      if (((iVar13 == 0x6b) || (iVar13 = TacticalAIGroup::type(this_02), iVar13 == 0x6c)) ||
         ((iVar13 = TacticalAIGroup::type(this_02), iVar13 == 0x6a ||
          ((iVar13 = TacticalAIGroup::action(this_02), iVar13 == 0 ||
           (iVar13 = TacticalAIGroup::action(this_02), iVar13 == 1)))))) {
        this_02 = this_02->next;
      }
      else {
        iVar13 = TacticalAIGroup::allUnitsIdle(this_02,this->md,1);
        if (iVar13 == 0) {
          TacticalAIGroup::setConsecutiveIdleUnitCount
                    (this_02,*(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4));
        }
        iVar13 = TacticalAIGroup::inUse(this_02);
        if (iVar13 == 0) {
          pOVar27 = (ObjectMemory *)0x0;
          pRVar26 = (RGE_Static_Object *)0x0;
          allOutsideTransport = 1;
          iVar13 = TacticalAIGroup::type(this_02);
          if ((iVar13 != 100) && (iVar13 = TacticalAIGroup::type(this_02), iVar13 != 0x67)) {
            iVar13 = TacticalAIGroup::type(this_02);
            if ((iVar13 == 0x65) || (iVar13 = TacticalAIGroup::type(this_02), iVar13 == 0x68)) {
              iVar13 = TacticalAIGroup::commander(this_02);
              pOVar27 = TribeInformationAIModule::objectToDefend(&this->md->informationAI,iVar13);
              if (pOVar27 == (ObjectMemory *)0x0) {
                TacticalAIGroup::setAction(this_02,1);
              }
              else {
                iVar13 = TacticalAIGroup::commander(this_02);
                pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                if (pRVar26 != (RGE_Static_Object *)0x0) {
                  if (pOVar27->type == 0x6d) {
                    iVar13 = this->sn[0x16];
                  }
                  else {
                    iVar13 = this->sn[0x39];
                  }
                  uVar12 = pOVar27->x;
                  uVar1 = pOVar27->y;
                  uVar2 = pOVar27->z;
                  unitObj = (RGE_Static_Object *)pRVar26->_padding_;
                  fVar29 = (float10)(**(code **)&unitObj[1].inObstructionMapValue)
                                              (pOVar27->id,&commanderPoint,1,0xffffffff,0xffffffff);
                  iVar35 = (*(code *)unitObj[3]._padding_)(uVar12,uVar1,uVar2,(float)fVar29);
                  if (iVar35 != 0) {
                    pOVar27->attackAttempts = 1;
                    TacticalAIGroup::setTarget(this_02,pOVar27->id);
                    TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                    TacticalAIGroup::setTargetLocation
                              (this_02,(float)pOVar27->x,(float)pOVar27->y,(float)pOVar27->z);
                    fVar31 = (float)pOVar27->z;
                    fVar30 = (float)pOVar27->y;
                    fVar34 = (float)pOVar27->x;
LAB_004f27f4:
                    TacticalAIGroup::setGatherLocation(this_02,fVar34,fVar30,fVar31);
                    TacticalAIGroup::setInUse(this_02,1);
                    goto LAB_004f2d49;
                  }
                  iVar13 = (*(code *)unitObj[3].owner)
                                     (uVar12,uVar1,uVar2,(float)iVar13,pOVar27->id,&commanderPoint,1
                                      ,0x16,1,0xffffffff,0xffffffff);
                  if ((iVar13 != 0) &&
                     (iVar13 = (*(code *)unitObj[3].sprite)(2,&gatherX_fffffff0,auStack_4),
                     iVar13 == 1)) {
                    pOVar27->attackAttempts = 1;
                    TacticalAIGroup::task(this_02,this,this->md,0xe,1,0);
                    TacticalAIGroup::setAction(this_02,0xd);
                    TacticalAIGroup::setTarget(this_02,pOVar27->id);
                    TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                    TacticalAIGroup::setTargetLocation
                              (this_02,(float)pOVar27->x,(float)pOVar27->y,(float)pOVar27->z);
                    TacticalAIGroup::setInUse(this_02,1);
                    TacticalAIGroup::setWaitCode(this_02,200);
                    goto LAB_004f4548;
                  }
                  goto LAB_004f2afb;
                }
                TacticalAIGroup::setAction(this_02,1);
              }
            }
            else {
              iVar13 = TacticalAIGroup::type(this_02);
              if (iVar13 == 0x6d) {
                pTVar33 = this->md;
                uVar14 = TacticalAIGroup::consecutiveIdleUnitCount(this_02);
                if ((((RGE_Player *)pTVar33->_padding_)->world->world_time - uVar14) / 1000 < 0x3c)
{
                  TacticalAIGroup::setAction(this_02,1);
                }
                else {
                  pRVar15 = MainDecisionAIModule::object
                                      ((MainDecisionAIModule *)pTVar33,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,
                                       -1);
                  if (pRVar15 == (RGE_Static_Object *)0x0) {
                    TacticalAIGroup::setAction(this_02,1);
                  }
                  else {
                    iVar13 = TacticalAIGroup::commander(this_02);
                    pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                    if (pRVar26 == (RGE_Static_Object *)0x0) {
                      TacticalAIGroup::setAction(this_02,1);
                    }
                    else {
                      uVar16 = __ftol();
                      uVar17 = __ftol();
                      uVar18 = __ftol();
                      unitObj = (RGE_Static_Object *)pRVar26->_padding_;
                      iVar13 = (*(code *)unitObj[3]._padding_)
                                         (uVar16,uVar17,uVar18,(float)this->sn[0x17],pRVar15->id,
                                          &pathDistance,1,0xffffffff,0xffffffff);
                      if (iVar13 != 0) {
                        TacticalAIGroup::setTarget(this_02,pRVar15->id);
                        TacticalAIGroup::setTargetType(this_02,(uint)pRVar15->type);
                        TacticalAIGroup::setTargetLocation
                                  (this_02,pRVar15->world_x,pRVar15->world_y,pRVar15->world_z);
                        fVar31 = pRVar15->world_z;
                        fVar30 = pRVar15->world_y;
                        fVar34 = pRVar15->world_x;
                        goto LAB_004f27f4;
                      }
                      iVar13 = (*(code *)unitObj[3].owner)
                                         (uVar16,uVar17,uVar18,(float)this->sn[0x17],pRVar15->id,
                                          &pathDistance,1,0x16,1,0xffffffff,0xffffffff);
                      if (iVar13 == 0) {
                        TacticalAIGroup::setConsecutiveIdleUnitCount
                                  (this_02,*(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4));
                        TacticalAIGroup::setAction(this_02,1);
                      }
                      else {
                        iVar13 = (*(code *)unitObj[3].sprite)(2,&gatherX,&pathDistance_ffffffe8);
                        if (iVar13 != 1) goto LAB_004f2afb;
                        TacticalAIGroup::task(this_02,this,this->md,0xe,1,0);
                        TacticalAIGroup::setAction(this_02,0xd);
                        TacticalAIGroup::setTarget(this_02,pRVar15->id);
                        TacticalAIGroup::setTargetType(this_02,(uint)pRVar15->type);
                        TacticalAIGroup::setTargetLocation
                                  (this_02,pRVar15->world_x,pRVar15->world_y,pRVar15->world_z);
                        TacticalAIGroup::setInUse(this_02,1);
                        TacticalAIGroup::setWaitCode(this_02,200);
                      }
                    }
                  }
                }
              }
              else {
LAB_004f2d49:
                iVar13 = TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI);
                if ((iVar13 == 0xb) &&
                   ((((iVar13 = TacticalAIGroup::type(this_02), iVar13 == 100 ||
                      (iVar13 = TacticalAIGroup::type(this_02), iVar13 == 0x67)) &&
                     (this->sn[0x67] == 1)) &&
                    ((pOVar27 != (ObjectMemory *)0x0 && (pRVar26 != (RGE_Static_Object *)0x0)))))) {
                  TribeInformationAIModule::addEnemyInfluences
                            (&this->md->informationAI,(uint)pOVar27->owner,pOVar27->id);
                  TribeInformationAIModule::addPriorAttackInfluences
                            (&this->md->informationAI,(uint)pOVar27->owner,pOVar27->id);
                  targetPoint.z = (int)pOVar27->y;
                  targetPoint.y = (int)pOVar27->x;
                  unitObj = (RGE_Static_Object *)pRVar26->_padding_;
                  fVar29 = (float10)(**(code **)&unitObj[1].inObstructionMapValue)(pOVar27->id);
                  pPVar20 = (Path *)(**(code **)&unitObj[3].curr_damage_percent)
                                              (&targetPoint.y,(float)fVar29);
                  if (pPVar20 != (Path *)0x0) {
                    stuffAvoidancePath(this,this_02,pPVar20);
                  }
                }
                if ((allOutsideTransport != 0) ||
                   (iVar13 = TacticalAIGroup::action(this_02), iVar13 != 2)) {
LAB_004f452d:
                  iVar13 = 0;
                  iVar36 = 1;
                  iVar35 = TacticalAIGroup::action(this_02);
                  goto LAB_004f4539;
                }
                pTVar33 = this->md;
                iVar13 = 0;
                iVar36 = 1;
                iVar35 = 0x15;
LAB_004f4540:
                TacticalAIGroup::task(this_02,this,pTVar33,iVar35,iVar36,iVar13);
              }
            }
            goto LAB_004f4548;
          }
          if (this->attackEnabledValue == 0) {
            (this->attackStateValue).active = 0;
          }
          else {
            if ((this->sn[0xa2] != 0) && (iVar13 = TacticalAIGroup::type(this_02), iVar13 != 0x67))
{
              pOVar27 = TribeInformationAIModule::objectMemory
                                  (&this->md->informationAI,iRam00000000);
LAB_004f2ae2:
              iVar13 = TacticalAIGroup::commander(this_02);
              pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
              if (pRVar26 == (RGE_Static_Object *)0x0) {
LAB_004f2afb:
                TacticalAIGroup::setAction(this_02,1);
              }
              else {
                uVar12 = pOVar27->y;
                uVar1 = pOVar27->x;
                unitObj = (RGE_Static_Object *)pRVar26->_padding_;
                pcVar5 = *(code **)&unitObj[1].inObstructionMapValue;
                uVar2 = pOVar27->z;
                fVar29 = (float10)(*pcVar5)(pOVar27->id,&pathDistance_ffffff88,1,pOVar27->owner,0x1b
                                           );
                iVar13 = (*(code *)unitObj[3]._padding_)(uVar1,uVar12,uVar2,(float)fVar29);
                if (iVar13 != 0) {
                  this->lastGroupAttackTime = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
                  if (this->sn[0x47] == 1) {
                    this->lastAttackResponseTime =
                         *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
                  }
                  TacticalAIGroup::setTarget(this_02,pOVar27->id);
                  TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                  TacticalAIGroup::setTargetLocation
                            (this_02,(float)pOVar27->x,(float)pOVar27->y,(float)pOVar27->z);
                  TacticalAIGroup::setInUse(this_02,1);
                  checkForCoopAttack(this,(uint)pOVar27->owner,(uint)pOVar27->x,(uint)pOVar27->y);
                  goto LAB_004f2d49;
                }
                iVar13 = TacticalAIGroup::type(this_02);
                if (iVar13 != 0x67) {
                  fVar29 = (float10)(*pcVar5)(pOVar27->id,&pathDistance_ffffff88,1,0x16,1,
                                              pOVar27->owner,0x1b);
                  iVar13 = (*(code *)unitObj[3].owner)(uVar1,uVar12,uVar2,(float)fVar29);
                  if (iVar13 == 0) {
                    this_02->numberObjectsToDestroyValue = 0;
                    TacticalAIGroup::setAction(this_02,1);
                    this_02->playNumberValue = -1;
                    (this->attackStateValue).active = 0;
                    goto LAB_004f4552;
                  }
                  iVar13 = (*(code *)unitObj[3].sprite)(2,&gatherY_fffffff8,&gatherY_ffffffd4);
                  if (iVar13 == 1) {
                    TacticalAIGroup::task(this_02,this,this->md,0xe,1,0);
                    TacticalAIGroup::setAction(this_02,0xd);
                    TacticalAIGroup::setTarget(this_02,pOVar27->id);
                    TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                    bVar11 = pOVar27->z;
                    bVar3 = pOVar27->y;
                    uVar28 = (uint)pOVar27->x;
                    goto LAB_004f3cf9;
                  }
                }
                TacticalAIGroup::setAction(this_02,1);
                this_02->playNumberValue = -1;
              }
              goto LAB_004f4548;
            }
            uVar28 = (*(int *)(*(int *)(this->md->_padding_ + 0x3c) + 4) - this->lastGroupAttackTime
                     ) / 1000;
            if ((((this->lastGroupAttackTime == 0) || (this->sn[0x2f] != 2)) || (uVar28 == 0)) ||
               (uVar14 = attackLimiterTime(this,0x2e), uVar14 <= uVar28)) {
              if (((this->lastGroupAttackTime == 0) || (this->sn[0x2f] != 1)) ||
                 (uVar14 = attackLimiterTime(this,0x2e), uVar14 <= uVar28)) {
                iVar13 = TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI);
                if (iVar13 == 0) {
                  iVar13 = itemToCapture(this);
                  pOVar27 = TribeInformationAIModule::objectMemory(&this->md->informationAI,iVar13);
                  if (pOVar27 == (ObjectMemory *)0x0) {
                    if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                       (piVar19 = (int *)operator_new(4), piVar19 != (int *)0x0)) {
                      iVar13 = 0;
                      if (0 < (this->playersToAttack).maximumSizeValue) {
                        do {
                          if (0 < iVar13) break;
                          iVar35 = iVar13 + 1;
                          piVar19[iVar13] = (this->playersToAttack).value[iVar13];
                          iVar13 = iVar35;
                        } while (iVar35 < (this->playersToAttack).maximumSizeValue);
                      }
LAB_004f29d8:
                      operator_delete((this->playersToAttack).value);
                      (this->playersToAttack).value = piVar19;
                      (this->playersToAttack).maximumSizeValue = 1;
                    }
LAB_004f29f7:
                    piVar4 = (this->playersToAttack).value;
                    piVar19 = &allOutsideTransport;
                    iVar13 = TacticalAIGroup::commander(this_02);
                    pOVar27 = TribeInformationAIModule::objectToAttack
                                        (&this->md->informationAI,*piVar4,1,1,iVar13,piVar19);
LAB_004f2ac7:
                    if (pOVar27 == (ObjectMemory *)0x0) {
                      TacticalAIGroup::setAction(this_02,1);
                      (this->attackStateValue).active = 0;
                      goto LAB_004f4552;
                    }
                  }
                }
                else {
                  iVar13 = TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI);
                  if (iVar13 != 4) {
                    if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                       (piVar19 = (int *)operator_new(4), piVar19 != (int *)0x0)) {
                      iVar13 = 0;
                      if (0 < (this->playersToAttack).maximumSizeValue) {
                        do {
                          if (0 < iVar13) break;
                          iVar35 = iVar13 + 1;
                          piVar19[iVar13] = (this->playersToAttack).value[iVar13];
                          iVar13 = iVar35;
                        } while (iVar35 < (this->playersToAttack).maximumSizeValue);
                      }
                      operator_delete((this->playersToAttack).value);
                      (this->playersToAttack).value = piVar19;
                      (this->playersToAttack).maximumSizeValue = 1;
                    }
                    pOVar27 = TribeInformationAIModule::objectToAttackByGroup
                                        (&this->md->informationAI,*(this->playersToAttack).value,
                                         this_02,&this->attackStateValue,param_1);
                    if ((this->attackStateValue).active == 1) goto LAB_004f45bf;
                    goto LAB_004f2ac7;
                  }
                  iVar13 = itemToBringToArea(this);
                  pOVar27 = TribeInformationAIModule::objectMemory(&this->md->informationAI,iVar13);
                  if (pOVar27 == (ObjectMemory *)0x0) {
                    if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                       (piVar19 = (int *)operator_new(4), piVar19 != (int *)0x0)) {
                      iVar13 = 0;
                      if (0 < (this->playersToAttack).maximumSizeValue) {
                        do {
                          if (0 < iVar13) break;
                          iVar35 = iVar13 + 1;
                          piVar19[iVar13] = (this->playersToAttack).value[iVar13];
                          iVar13 = iVar35;
                        } while (iVar35 < (this->playersToAttack).maximumSizeValue);
                      }
                      goto LAB_004f29d8;
                    }
                    goto LAB_004f29f7;
                  }
                }
                pOVar27->attackAttempts = pOVar27->attackAttempts + 1;
                goto LAB_004f2ae2;
              }
              (this->attackStateValue).active = 0;
            }
            else {
              (this->attackStateValue).active = 0;
            }
          }
        }
        else {
          iVar13 = TacticalAIGroup::action(this_02);
          if (iVar13 == 0xd) {
            iVar13 = TacticalAIGroup::waitCode(this_02);
            if (iVar13 == 200) {
              iVar13 = TacticalAIGroup::assistGroupID(this_02);
              if (iVar13 == -1) {
                iVar13 = TacticalAIGroup::commander(this_02);
                pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                if (pRVar26 == (RGE_Static_Object *)0x0) {
                  (this->attackStateValue).active = 0;
                  goto LAB_004f4552;
                }
                commanderPoint.y = __ftol();
                __ftol();
                pTVar21 = bestGroup(this,0x6a,1,-1,(XYPoint *)&commanderPoint.y,-1);
                if ((pTVar21 != (TacticalAIGroup *)0x0) ||
                   (pTVar21 = bestGroup(this,0x6a,0,-1,(XYPoint *)&commanderPoint.y,-1),
                   pTVar21 != (TacticalAIGroup *)0x0)) {
                  iVar13 = TacticalAIGroup::id(pTVar21);
                  TacticalAIGroup::setAssistGroupID(this_02,iVar13);
                  iVar13 = TacticalAIGroup::type(pTVar21);
                  TacticalAIGroup::setAssistGroupType(this_02,iVar13);
                  TacticalAIGroup::setAction(pTVar21,0xc);
                  TacticalAIGroup::setInUse(pTVar21,1);
                  iVar13 = TacticalAIGroup::id(this_02);
                  TacticalAIGroup::setAssistGroupID(pTVar21,iVar13);
                  goto LAB_004f2f57;
                }
              }
              else {
                iVar38 = -1;
                iVar36 = -1;
                iVar35 = -1;
                iVar13 = TacticalAIGroup::assistGroupID(this_02);
                pTVar21 = group(this,iVar13,iVar35,iVar36,iVar38);
LAB_004f2f57:
                if (pTVar21 != (TacticalAIGroup *)0x0) {
                  iVar13 = TacticalAIGroup::commander(pTVar21);
                  pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                  if ((pRVar26 == (RGE_Static_Object *)0x0) ||
                     (pRVar26->objects->number_of_objects <
                      (short)(ushort)pRVar26->master_obj->obj_max)) {
                    unitObj = (RGE_Static_Object *)0x0;
                    allOutsideTransport = 0;
                    iVar13 = TacticalAIGroup::numberUnits(this_02);
                    if (0 < iVar13) {
                      do {
                        iVar13 = TacticalAIGroup::unit(this_02,allOutsideTransport);
                        pRVar26 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)this->md,iVar13);
                        if ((pRVar26 != (RGE_Static_Object *)0x0) &&
                           (pUVar22 = RGE_Static_Object::unitAI(pRVar26),
                           pUVar22 != (UnitAIModule *)0x0)) {
                          pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                          iVar35 = UnitAIModule::currentAction(pUVar22);
                          if (iVar35 == -1) {
                            unitObj = (RGE_Static_Object *)0x1;
                            iVar35 = TacticalAIGroup::commander(pTVar21);
                            taskToEnter(this,iVar13,iVar35);
                          }
                        }
                        iVar35 = allOutsideTransport + 1;
                        allOutsideTransport = iVar35;
                        iVar13 = TacticalAIGroup::numberUnits(this_02);
                      } while (iVar35 < iVar13);
                    }
                    if (unitObj != (RGE_Static_Object *)0x0) goto LAB_004f43ca;
                    TacticalAIGroup::setAction(this_02,0xf);
                    (this->attackStateValue).active = 0;
                  }
                  else {
                    TacticalAIGroup::setAction(this_02,0xf);
                    (this->attackStateValue).active = 0;
                  }
                  goto LAB_004f4552;
                }
              }
              TacticalAIGroup::setAssistGroupID(this_02,-1);
              TacticalAIGroup::setAssistGroupType(this_02,-1);
              (this->attackStateValue).active = 0;
              goto LAB_004f4552;
            }
LAB_004f43ca:
            (this->attackStateValue).active = 0;
          }
          else {
            iVar13 = TacticalAIGroup::action(this_02);
            if (iVar13 == 0xf) {
              iVar38 = -1;
              iVar36 = -1;
              iVar35 = -1;
              iVar13 = TacticalAIGroup::assistGroupID(this_02);
              pTVar21 = group(this,iVar13,iVar35,iVar36,iVar38);
              if (pTVar21 != (TacticalAIGroup *)0x0) {
                iVar13 = TacticalAIGroup::commander(pTVar21);
                pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                if (pRVar26 != (RGE_Static_Object *)0x0) {
                  if ((short)(ushort)pRVar26->master_obj->obj_max <=
                      pRVar26->objects->number_of_objects) {
                    TacticalAIGroup::removeUnboardedUnits(this_02,this,this->md);
                  }
                  point.x = 0xff;
                  unitObj = (RGE_Static_Object *)0x1;
                  allInsideTransport = 0;
                  iVar13 = TacticalAIGroup::numberUnits(this_02);
                  if (0 < iVar13) {
                    do {
                      iVar13 = TacticalAIGroup::unit(this_02,allInsideTransport);
                      allOutsideTransport =
                           (int)MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,iVar13);
                      if ((RGE_Static_Object *)allOutsideTransport == (RGE_Static_Object *)0x0) {
                        AIModule::logCommonHistory(this_00,(char *)this,s_____Unit__d_is_invalid_);
                      }
                      else {
                        pUVar22 = RGE_Static_Object::unitAI
                                            ((RGE_Static_Object *)allOutsideTransport);
                        if (pUVar22 == (UnitAIModule *)0x0) {
                          AIModule::logCommonHistory
                                    (this_01,(char *)this,s_____Unit__d_has_invalid_unitAI_);
                        }
                        else {
                          iVar13 = TacticalAIGroup::unit(this_02,allInsideTransport);
                          iVar35 = TacticalAIGroup::commander(this_02);
                          pRVar26 = (RGE_Static_Object *)allOutsideTransport;
                          if (iVar13 == iVar35) {
                            TacticalAIGroup::targetLocation(this_02);
                            iVar13 = __ftol();
                            TacticalAIGroup::targetLocation(this_02);
                            iVar35 = __ftol();
                            pRVar26 = (RGE_Static_Object *)allOutsideTransport;
                            XVar10.y = iVar35;
                            XVar10.x = iVar13;
                            bVar11 = RGE_Static_Object::lookupZone
                                               ((RGE_Static_Object *)allOutsideTransport,XVar10);
                            point.x = (int)bVar11;
                          }
                          allOutsideTransport = (int)pRVar26->inside_obj;
                          if (((RGE_Static_Object *)allOutsideTransport != (RGE_Static_Object *)0x0)
                             && (iVar13 = TacticalAIGroup::commander(pTVar21),
                                *(int *)(allOutsideTransport + 4) == iVar13)) {
                            pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                            iVar13 = UnitAIModule::currentAction(pUVar22);
                            if (iVar13 != -1) {
                              stopUnit(this,pRVar26->id,100);
                              goto LAB_004f323d;
                            }
                          }
                          allOutsideTransport = (int)pRVar26->inside_obj;
                          if (((RGE_Static_Object *)allOutsideTransport == (RGE_Static_Object *)0x0)
                             || (iVar13 = TacticalAIGroup::commander(pTVar21),
                                *(int *)(allOutsideTransport + 4) == iVar13)) {
                            if (pRVar26->inside_obj == (RGE_Static_Object *)0x0) {
                              unitObj = (RGE_Static_Object *)0x0;
                              pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                              iVar13 = UnitAIModule::currentOrder(pUVar22);
                              if (iVar13 != 700) {
                                pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                                iVar13 = UnitAIModule::currentOrder(pUVar22);
                                if (iVar13 != 0x2cd) {
                                  iVar13 = TacticalAIGroup::commander(pTVar21);
                                  iVar35 = TacticalAIGroup::unit(this_02,allInsideTransport);
                                  taskToEnter(this,iVar35,iVar13);
                                }
                              }
                            }
                          }
                          else {
                            TacticalAIGroup::removeUnit(this_02,pRVar26->id,this->md);
                          }
                        }
                      }
LAB_004f323d:
                      allInsideTransport = allInsideTransport + 1;
                      iVar13 = TacticalAIGroup::numberUnits(this_02);
                    } while (allInsideTransport < iVar13);
                  }
                  if (unitObj != (RGE_Static_Object *)0x0) {
                    TacticalAIGroup::targetLocation(this_02);
                    iVar13 = __ftol();
                    TacticalAIGroup::targetLocation(this_02);
                    iVar35 = __ftol();
                    iVar36 = TacticalAIGroup::commander(this_02);
                    iVar37 = 0xf;
                    iVar38 = TacticalAIGroup::target(this_02);
                    XVar9.y = iVar35;
                    XVar9.x = iVar13;
                    iVar13 = TribeInformationAIModule::findStagingPoint
                                       (&this->md->informationAI,XVar9,(XYPoint *)&stagingPoint.y,1,
                                        1,iVar38,iVar37,iVar36);
                    if (iVar13 == 0) {
                      TacticalAIGroup::targetLocation(this_02);
                      stagingPoint.y = __ftol();
                      TacticalAIGroup::targetLocation(this_02);
                      point_ffffff44.x = __ftol();
                    }
                    fVar31 = (float)point_ffffff44.x - _DAT_00575768;
                    fVar30 = (float)stagingPoint.y - _DAT_00575768;
                    iVar13 = TacticalAIGroup::commander(pTVar21);
                    taskTransporter(this,iVar13,fVar30,fVar31);
                    TacticalAIGroup::setTargetLocation
                              (pTVar21,(float)stagingPoint.y,(float)point_ffffff44.x,-1.0);
                    TacticalAIGroup::setAction(pTVar21,0xc);
                    TacticalAIGroup::setTargetType(pTVar21,point.x);
                    TacticalAIGroup::setAction(this_02,0x10);
                    TacticalAIGroup::task(this_02,this,this->md,0x16,0,1);
                    iVar13 = TacticalAIGroup::numberUnits(pTVar21);
                    if (1 < iVar13) {
                      iVar13 = 0;
                      allOutsideTransport = 0;
                      iVar35 = TacticalAIGroup::numberUnits(pTVar21);
                      if (0 < iVar35) {
                        do {
                          iVar35 = TacticalAIGroup::unit(pTVar21,iVar13);
                          iVar36 = TacticalAIGroup::commander(pTVar21);
                          iVar13 = allOutsideTransport;
                          if (iVar35 != iVar36) {
                            iVar35 = TacticalAIGroup::unit(pTVar21,allOutsideTransport);
                            pRVar26 = MainDecisionAIModule::object
                                                ((MainDecisionAIModule *)this->md,iVar35);
                            if (pRVar26 != (RGE_Static_Object *)0x0) {
                              iVar38 = 99;
                              fVar31 = pRVar26->master_obj->los * _DAT_005756fc;
                              iVar35 = TacticalAIGroup::commander(pTVar21);
                              iVar36 = TacticalAIGroup::unit(pTVar21,iVar13);
                              taskDefender(this,iVar36,iVar35,fVar31,iVar38);
                            }
                          }
                          iVar13 = iVar13 + 1;
                          allOutsideTransport = iVar13;
                          iVar35 = TacticalAIGroup::numberUnits(pTVar21);
                        } while (iVar13 < iVar35);
                      }
                    }
                  }
                  goto LAB_004f4548;
                }
              }
              goto LAB_004f37f1;
            }
            iVar13 = TacticalAIGroup::action(this_02);
            if (iVar13 == 0x10) {
              iVar38 = -1;
              iVar36 = -1;
              iVar35 = -1;
              iVar13 = TacticalAIGroup::assistGroupID(this_02);
              stagingPoint.x = (int)group(this,iVar13,iVar35,iVar36,iVar38);
              if ((TacticalAIGroup *)stagingPoint.x != (TacticalAIGroup *)0x0) {
                iVar13 = TacticalAIGroup::commander((TacticalAIGroup *)stagingPoint.x);
                pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                pathDistance_ffffff80 = (float)pRVar26;
                if (((pRVar26 != (RGE_Static_Object *)0x0) &&
                    (pUVar22 = RGE_Static_Object::unitAI(pRVar26), pUVar22 != (UnitAIModule *)0x0))
                   && (pRVar26->owner->id == *(short *)(this->md->_padding_ + 0x4a))) {
                  unitObj = (RGE_Static_Object *)0x1;
                  allOutsideTransport = 1;
                  allInsideTransport = 0;
                  iVar13 = TacticalAIGroup::numberUnits(this_02);
                  if (0 < iVar13) {
                    do {
                      iVar13 = TacticalAIGroup::unit(this_02,allInsideTransport);
                      pRVar26 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,iVar13);
                      if ((pRVar26 != (RGE_Static_Object *)0x0) &&
                         (pUVar22 = RGE_Static_Object::unitAI(pRVar26),
                         pUVar22 != (UnitAIModule *)0x0)) {
                        if (pRVar26->inside_obj == (RGE_Static_Object *)0x0) {
                          allOutsideTransport = 0;
                          iVar13 = TacticalAIGroup::target(this_02);
                          pRVar15 = MainDecisionAIModule::object
                                              ((MainDecisionAIModule *)this->md,iVar13);
                          iVar13 = TacticalAIGroup::type(this_02);
                          if ((iVar13 == 100) && (pRVar15 != (RGE_Static_Object *)0x0)) {
                            pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                            if (pUVar22 != (UnitAIModule *)0x0) {
                              pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                              iVar13 = UnitAIModule::currentTarget(pUVar22);
                              iVar35 = TacticalAIGroup::target(this_02);
                              if (iVar13 != iVar35) {
                                iVar13 = pRVar26->_padding_;
                                fVar29 = (float10)(**(code **)(iVar13 + 0x10c))
                                                            (0,1,0xffffffff,0xffffffff);
                                fVar31 = (float)fVar29;
                                iVar35 = TacticalAIGroup::target(this_02);
                                iVar13 = (**(code **)(iVar13 + 0x194))(iVar35,fVar31);
                                if (iVar13 == 1) {
                                  iVar25 = 0;
                                  iVar37 = -1;
                                  iVar38 = 0;
                                  pWVar32 = (Waypoint *)0x0;
                                  iVar36 = -1;
                                  iVar13 = TacticalAIGroup::target(this_02);
                                  pWVar24 = TacticalAIGroup::targetLocation(this_02);
                                  fVar31 = pWVar24->y;
                                  pWVar24 = TacticalAIGroup::targetLocation(this_02);
                                  fVar30 = pWVar24->x;
                                  iVar35 = TacticalAIGroup::unit(this_02,allInsideTransport);
                                  taskAttacker(this,iVar35,fVar30,fVar31,iVar13,iVar36,pWVar32,
                                               iVar38,iVar37,iVar25);
                                }
                              }
                            }
                          }
                          else {
                            iVar35 = 100;
                            iVar13 = TacticalAIGroup::unit(this_02,allInsideTransport);
                            stopUnit(this,iVar13,iVar35);
                          }
                        }
                        else {
                          unitObj = (RGE_Static_Object *)0x0;
                        }
                      }
                      allInsideTransport = allInsideTransport + 1;
                      iVar13 = TacticalAIGroup::numberUnits(this_02);
                    } while (allInsideTransport < iVar13);
                  }
                  fVar31 = pathDistance_ffffff80;
                  if (allOutsideTransport == 1) {
                    uVar12 = RGE_Action_List::have_action
                                       (*(RGE_Action_List **)((int)pathDistance_ffffff80 + 0x184));
                    if ((uVar12 == '\0') ||
                       (pRVar23 = RGE_Action_List::get_action
                                            (*(RGE_Action_List **)((int)fVar31 + 0x184)),
                       pRVar23->state == '\x02')) {
                      iVar13 = stagingPoint.x;
                      pWVar24 = TacticalAIGroup::targetLocation((TacticalAIGroup *)stagingPoint.x);
                      fVar31 = pWVar24->y - _DAT_00575768;
                      pWVar24 = TacticalAIGroup::targetLocation((TacticalAIGroup *)iVar13);
                      fVar30 = pWVar24->x - _DAT_00575768;
                      iVar35 = TacticalAIGroup::commander((TacticalAIGroup *)iVar13);
                      taskTransporter(this,iVar35,fVar30,fVar31);
                      TacticalAIGroup::setAction((TacticalAIGroup *)iVar13,0xc);
                    }
                  }
                  else if (unitObj != (RGE_Static_Object *)0x0) {
                    iVar38 = -1;
                    iVar36 = -1;
                    iVar35 = -1;
                    iVar13 = TacticalAIGroup::assistGroupID(this_02);
                    pTVar21 = group(this,iVar13,iVar35,iVar36,iVar38);
                    if (pTVar21 != (TacticalAIGroup *)0x0) {
                      TacticalAIGroup::setTarget(pTVar21,-1);
                      TacticalAIGroup::setTargetType(pTVar21,-1);
                      TacticalAIGroup::setAction(pTVar21,1);
                      TacticalAIGroup::setInUse(pTVar21,0);
                      pRVar26 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,
                                           -1,-1,-1);
                      if (pRVar26 != (RGE_Static_Object *)0x0) {
                        fVar31 = pRVar26->world_y;
                        fVar30 = pRVar26->world_x;
                        iVar35 = 0x32;
                        iVar13 = TacticalAIGroup::commander(pTVar21);
                        moveUnit(this,iVar13,fVar30,fVar31,iVar35);
                      }
                    }
                    iVar13 = TacticalAIGroup::type(this_02);
                    if (iVar13 != 100) {
                      iVar13 = TacticalAIGroup::type(this_02);
                      if ((iVar13 != 0x65) &&
                         (iVar13 = TacticalAIGroup::type(this_02), iVar13 != 0x6d))
                      goto LAB_004f3825;
                      pWVar24 = TacticalAIGroup::targetLocation(this_02);
                      fVar31 = pWVar24->z;
                      pWVar24 = TacticalAIGroup::targetLocation(this_02);
                      fVar30 = pWVar24->y;
                      pWVar24 = TacticalAIGroup::targetLocation(this_02);
                      TacticalAIGroup::setGatherLocation(this_02,pWVar24->x,fVar30,fVar31);
                      TacticalAIGroup::setInUse(this_02,0);
                      TacticalAIGroup::setAction(this_02,1);
                      pTVar33 = this->md;
                      iVar13 = 1;
                      iVar36 = 1;
                      iVar35 = 1;
                      goto LAB_004f4540;
                    }
                    iVar13 = TacticalAIGroup::commander(this_02);
                    pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                    if (pRVar26 == (RGE_Static_Object *)0x0) {
LAB_004f376c:
                      TacticalAIGroup::setInUse(this_02,1);
                      TacticalAIGroup::setAction(this_02,7);
                      pTVar33 = this->md;
                      iVar13 = 1;
                      iVar36 = 0;
                      iVar35 = 7;
                      goto LAB_004f4540;
                    }
                    iVar13 = pRVar26->_padding_;
                    fVar29 = (float10)(**(code **)(iVar13 + 0x10c))(0,1,0xffffffff,0xffffffff);
                    fVar31 = (float)fVar29;
                    iVar35 = TacticalAIGroup::target(this_02);
                    iVar13 = (**(code **)(iVar13 + 0x194))(iVar35,fVar31);
                    if (iVar13 != 1) goto LAB_004f376c;
                    this->lastGroupAttackTime = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4)
                    ;
                    if (this->sn[0x47] == 1) {
                      this->lastAttackResponseTime =
                           *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
                    }
                    iVar13 = 2;
LAB_004f4526:
                    TacticalAIGroup::setAction(this_02,iVar13);
                    goto LAB_004f452d;
                  }
                  goto LAB_004f4548;
                }
              }
LAB_004f37f1:
              TacticalAIGroup::setTarget(this_02,-1);
              this_02->numberObjectsToDestroyValue = 0;
              TacticalAIGroup::setTargetType(this_02,-1);
              TacticalAIGroup::setAction(this_02,1);
              TacticalAIGroup::setInUse(this_02,0);
              (this->attackStateValue).active = 0;
            }
            else {
LAB_004f3825:
              iVar13 = TacticalAIGroup::action(this_02);
              if (iVar13 != 0xc) {
                iVar13 = TacticalAIGroup::action(this_02);
                if (iVar13 != 0x13) {
                  iVar13 = TacticalAIGroup::action(this_02);
                  if (iVar13 != 3) {
LAB_004f3a51:
                    iVar13 = TacticalAIGroup::action(this_02);
                    if (iVar13 == 7) {
                      iVar13 = TacticalAIGroup::commander(this_02);
                      pRVar26 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,iVar13);
                      if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                         (piVar19 = (int *)operator_new(4), piVar19 != (int *)0x0)) {
                        iVar13 = 0;
                        if (0 < (this->playersToAttack).maximumSizeValue) {
                          do {
                            if (0 < iVar13) break;
                            iVar35 = iVar13 + 1;
                            piVar19[iVar13] = (this->playersToAttack).value[iVar13];
                            iVar13 = iVar35;
                          } while (iVar35 < (this->playersToAttack).maximumSizeValue);
                        }
                        operator_delete((this->playersToAttack).value);
                        (this->playersToAttack).value = piVar19;
                        (this->playersToAttack).maximumSizeValue = 1;
                      }
                      pOVar27 = TribeInformationAIModule::objectToAttackByGroup
                                          (&this->md->informationAI,*(this->playersToAttack).value,
                                           this_02,&this->attackStateValue,param_1);
                      if ((this->attackStateValue).active == 1) goto LAB_004f45bf;
                      pRVar15 = (RGE_Static_Object *)0x0;
                      if (pOVar27 != (ObjectMemory *)0x0) {
                        pRVar15 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)this->md,pOVar27->id);
                      }
                      if (((pRVar26 == (RGE_Static_Object *)0x0) || (pOVar27 == (ObjectMemory *)0x0)
                          ) || (pRVar15 == (RGE_Static_Object *)0x0)) {
LAB_004f3d28:
                        uVar14 = TacticalAIGroup::consecutiveIdleUnitCount(this_02);
                        if ((uint)(this->sn[0x58] << 2) <
                            (*(int *)(*(int *)(this->md->_padding_ + 0x3c) + 4) - uVar14) / 1000) {
                          TacticalAIGroup::setAction(this_02,7);
                          pTVar33 = this->md;
                          iVar13 = 1;
                          iVar36 = 0;
                          iVar35 = 7;
                          goto LAB_004f4540;
                        }
                        goto LAB_004f3d75;
                      }
                      uVar12 = pOVar27->y;
                      uVar1 = pOVar27->z;
                      uVar2 = pOVar27->x;
                      iVar13 = pRVar26->_padding_;
                      allOutsideTransport = *(undefined4 *)(iVar13 + 0x10c);
                      fVar29 = (float10)(*(code *)allOutsideTransport)
                                                  (pOVar27->id,&transportObject,1,pOVar27->owner,
                                                   0x1b);
                      iVar35 = (**(code **)(iVar13 + 0x198))(uVar2,uVar12,uVar1,(float)fVar29);
                      if (iVar35 == 1) {
                        TacticalAIGroup::setAction(this_02,2);
                        TacticalAIGroup::setTarget(this_02,pOVar27->id);
                        TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                        stagingPoint.x = (int)pOVar27->x;
                        TacticalAIGroup::setTargetLocation
                                  (this_02,(float)stagingPoint.x,(float)pOVar27->y,(float)pOVar27->z
                                  );
                        TacticalAIGroup::setInUse(this_02,1);
                        pTVar33 = this->md;
                        iVar13 = 1;
                        iVar36 = 0;
                        iVar35 = 2;
                        goto LAB_004f4540;
                      }
                      fVar29 = (float10)(*(code *)allOutsideTransport)
                                                  (pOVar27->id,&transportObject,1,0x16,1,
                                                   pOVar27->owner,0x1b);
                      iVar35 = (**(code **)(iVar13 + 0x1a4))(uVar2,uVar12,uVar1,(float)fVar29);
                      if ((iVar35 != 1) ||
                         (iVar13 = (**(code **)(iVar13 + 0x1a8))(2,&gatherY_ffffffe4,&startPoint),
                         iVar13 != 1)) goto LAB_004f3d28;
                      TacticalAIGroup::task(this_02,this,this->md,0xe,1,0);
                      TacticalAIGroup::setAction(this_02,0xd);
                      TacticalAIGroup::setTarget(this_02,pOVar27->id);
                      TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                      bVar11 = pOVar27->z;
                      bVar3 = pOVar27->y;
                      uVar28 = (uint)pOVar27->x;
                      stagingPoint.x = uVar28;
LAB_004f3cf9:
                      TacticalAIGroup::setTargetLocation
                                (this_02,(float)uVar28,(float)bVar3,(float)bVar11);
                      TacticalAIGroup::setInUse(this_02,1);
                      TacticalAIGroup::setWaitCode(this_02,200);
                      this_02->playNumberValue = -1;
                      goto LAB_004f4548;
                    }
LAB_004f3d75:
                    iVar13 = TacticalAIGroup::action(this_02);
                    if ((iVar13 == 2) && (this_02->playNumberValue == -1)) {
                      if (this->sn[0x5b] < 100) {
                        iVar35 = 0;
                        iVar13 = TacticalAIGroup::numberUnits(this_02);
                        if (0 < iVar13) {
                          do {
                            iVar13 = TacticalAIGroup::unit(this_02,iVar35);
                            stagingPoint.x =
                                 (int)MainDecisionAIModule::object
                                                ((MainDecisionAIModule *)this->md,iVar13);
                            if ((RGE_Static_Object *)stagingPoint.x == (RGE_Static_Object *)0x0) {
LAB_004f3e53:
                              iVar35 = iVar35 + 1;
                            }
                            else {
                              iVar13 = TacticalAIGroup::unitOriginalHitPoints(this_02,iVar35);
                              iVar36 = __ftol();
                              iVar38 = TacticalAIGroup::unitOriginalHitPoints(this_02,iVar35);
                              if (((iVar13 - iVar36) * 100) / iVar38 <= this->sn[0x5b])
                              goto LAB_004f3e53;
                              iVar36 = 100;
                              pWVar24 = TacticalAIGroup::retreatLocation(this_02);
                              fVar31 = pWVar24->y;
                              pWVar24 = TacticalAIGroup::retreatLocation(this_02);
                              fVar30 = pWVar24->x;
                              iVar13 = TacticalAIGroup::unit(this_02,iVar35);
                              moveUnit(this,iVar13,fVar30,fVar31,iVar36);
                              pTVar33 = this->md;
                              iVar13 = TacticalAIGroup::unit(this_02,iVar35);
                              TacticalAIGroup::removeUnit(this_02,iVar13,pTVar33);
                              iVar13 = TacticalAIGroup::numberUnits(this_02);
                              if (iVar13 == 0) break;
                            }
                            iVar13 = TacticalAIGroup::numberUnits(this_02);
                          } while (iVar35 < iVar13);
                        }
                      }
                      iVar13 = TacticalAIGroup::target(this_02);
                      pRVar26 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,iVar13);
                      if ((pRVar26 != (RGE_Static_Object *)0x0) && (pRVar26->object_state < 3)) {
                        iVar13 = TacticalAIGroup::subType(this_02);
                        if (iVar13 == -1) {
                          iVar13 = (**(code **)(*(int *)this->md->_padding_ + 0x1c))
                                             ((int)pRVar26->owner->id);
                          if (iVar13 == 0) {
                            iVar13 = TacticalAIGroup::allUnitsIdle(this_02,this->md,0);
                            if (iVar13 != 1) {
                              pTVar33 = this->md;
                              iVar13 = 1;
                              iVar36 = 0;
                              iVar35 = 0x14;
                              goto LAB_004f4540;
                            }
                            iVar13 = TacticalAIGroup::commander(this_02);
                            pRVar26 = MainDecisionAIModule::object
                                                ((MainDecisionAIModule *)this->md,iVar13);
                            if (pRVar26 == (RGE_Static_Object *)0x0) {
                              (this->attackStateValue).active = 0;
                              goto LAB_004f4552;
                            }
                            iVar13 = pRVar26->_padding_;
                            fVar29 = (float10)(**(code **)(iVar13 + 0x10c))
                                                        (0,1,0xffffffff,0xffffffff);
                            fVar31 = (float)fVar29;
                            iVar35 = TacticalAIGroup::target(this_02);
                            iVar13 = (**(code **)(iVar13 + 0x194))(iVar35,fVar31);
                            if (iVar13 == 1) {
                              iVar36 = 0;
                              iVar35 = 0x14;
                              iVar13 = 1;
                              goto LAB_004f4539;
                            }
                            TacticalAIGroup::setGatherLocation
                                      (this_02,pRVar26->world_x,pRVar26->world_y,pRVar26->world_z);
                            TacticalAIGroup::setInUse(this_02,0);
                            TacticalAIGroup::setAction(this_02,1);
                            TacticalAIGroup::setTarget(this_02,-1);
                            TacticalAIGroup::setTargetType(this_02,-1);
                            this_02->numberObjectsToDestroyValue = 0;
                            TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                          }
                          else {
                            TacticalAIGroup::setInUse(this_02,0);
                            TacticalAIGroup::setAction(this_02,1);
                            TacticalAIGroup::setTarget(this_02,-1);
                            TacticalAIGroup::setTargetType(this_02,-1);
                            TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                            this_02->numberObjectsToDestroyValue = 0;
                            iVar13 = TacticalAIGroup::commander(this_02);
                            pRVar26 = MainDecisionAIModule::object
                                                ((MainDecisionAIModule *)this->md,iVar13);
                            if (pRVar26 != (RGE_Static_Object *)0x0) {
                              TacticalAIGroup::setGatherLocation
                                        (this_02,pRVar26->world_x,pRVar26->world_y,pRVar26->world_z)
                              ;
                            }
                          }
                          goto LAB_004f4548;
                        }
                        iVar13 = TacticalAIGroup::subType(this_02);
                        if ((((iVar13 != 0) &&
                             (iVar13 = TacticalAIGroup::subType(this_02), iVar13 == 4)) &&
                            (pRVar26->owner->id == *(short *)(this->md->_padding_ + 0x4a))) &&
                           (iVar13 = TribeMainDecisionAIModule::isMoveable(this->md,pRVar26->id),
                           iVar13 != 0)) {
                          TacticalAIGroup::addUnit(this_02,pRVar26->id,this->md);
                          pWVar24 = TribeStrategyAIModule::targetPoint1(&this->md->strategyAI);
                          fVar31 = pWVar24->x;
                          fVar30 = pWVar24->y;
                          fVar34 = pWVar24->z;
                          pWVar24 = TribeStrategyAIModule::targetPoint2(&this->md->strategyAI);
                          fVar6 = pWVar24->x;
                          fVar7 = pWVar24->y;
                          fVar8 = pWVar24->z;
                          targetPoint.x = *(int *)&pWVar24->facetToNextWaypoint;
                          TacticalAIGroup::setInUse(this_02,0);
                          TacticalAIGroup::setAction(this_02,1);
                          TacticalAIGroup::setTarget(this_02,-1);
                          this_02->numberObjectsToDestroyValue = 0;
                          TacticalAIGroup::setTargetType(this_02,-1);
                          TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                          TacticalAIGroup::setGatherLocation
                                    (this_02,(fVar6 + fVar31) * _DAT_005756fc,
                                     (fVar7 + fVar30) * _DAT_005756fc,
                                     (fVar8 + fVar34) * _DAT_005756fc);
                        }
                        uVar14 = TacticalAIGroup::consecutiveIdleUnitCount(this_02);
                        if ((uint)this->sn[0x4c] <
                            (*(int *)(*(int *)(this->md->_padding_ + 0x3c) + 4) - uVar14) / 1000) {
                          TacticalAIGroup::setInUse(this_02,0);
                          TacticalAIGroup::setAction(this_02,1);
                          TacticalAIGroup::setTarget(this_02,-1);
                          TacticalAIGroup::setTargetType(this_02,-1);
                          TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                          this_02->numberObjectsToDestroyValue = 0;
                          (this->attackStateValue).active = 0;
                          goto LAB_004f4552;
                        }
                        goto LAB_004f436b;
                      }
                      if (this->sn[0x31] == 2) {
                        TacticalAIGroup::setAction(this_02,1);
                        TacticalAIGroup::setTarget(this_02,-1);
                        this_02->numberObjectsToDestroyValue = 0;
                        TacticalAIGroup::setTargetType(this_02,-1);
                        TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                        iVar13 = 0;
                        iVar36 = 1;
                        iVar35 = TacticalAIGroup::action(this_02);
                        pTVar33 = this->md;
                        goto LAB_004f4540;
                      }
                      iVar13 = TacticalAIGroup::commander(this_02);
                      pRVar26 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,iVar13);
                      if (pRVar26 == (RGE_Static_Object *)0x0) {
                        (this->attackStateValue).active = 0;
                        goto LAB_004f4552;
                      }
                      if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                         (piVar19 = (int *)operator_new(4), piVar19 != (int *)0x0)) {
                        iVar13 = 0;
                        if (0 < (this->playersToAttack).maximumSizeValue) {
                          do {
                            if (0 < iVar13) break;
                            iVar35 = iVar13 + 1;
                            piVar19[iVar13] = (this->playersToAttack).value[iVar13];
                            iVar13 = iVar35;
                          } while (iVar35 < (this->playersToAttack).maximumSizeValue);
                        }
                        operator_delete((this->playersToAttack).value);
                        (this->playersToAttack).value = piVar19;
                        (this->playersToAttack).maximumSizeValue = 1;
                      }
                      pOVar27 = TribeInformationAIModule::objectToAttackByGroup
                                          (&this->md->informationAI,*(this->playersToAttack).value,
                                           this_02,&this->attackStateValue,param_1);
                      if ((this->attackStateValue).active == 1) {
LAB_004f45bf:
                        iVar13 = TacticalAIGroup::id(this_02);
                        this->nextActiveSoldierGroupToTaskValue = iVar13;
                        return;
                      }
                      if (pOVar27 != (ObjectMemory *)0x0) {
                        uVar12 = pOVar27->y;
                        uVar1 = pOVar27->x;
                        uVar2 = pOVar27->z;
                        iVar13 = pRVar26->_padding_;
                        fVar29 = (float10)(**(code **)(iVar13 + 0x10c))
                                                    (pOVar27->id,&gatherX_ffffffec,1,pOVar27->owner,
                                                     0x1b);
                        iVar13 = (**(code **)(iVar13 + 0x198))(uVar1,uVar12,uVar2,(float)fVar29);
                        if (iVar13 == 1) {
                          TacticalAIGroup::setTarget(this_02,pOVar27->id);
                          TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                          stagingPoint.x = (int)pOVar27->x;
                          TacticalAIGroup::setTargetLocation
                                    (this_02,(float)stagingPoint.x,(float)pOVar27->y,
                                     (float)pOVar27->z);
                          TacticalAIGroup::setInUse(this_02,1);
                          pTVar33 = this->md;
                          iVar13 = 0;
                          iVar36 = 0;
                          iVar35 = 2;
                          goto LAB_004f4540;
                        }
                      }
                      iVar13 = TacticalAIGroup::targetType(this_02);
                      TacticalAIGroup::setInUse(this_02,0);
                      TacticalAIGroup::setAction(this_02,1);
                      TacticalAIGroup::setTarget(this_02,-1);
                      this_02->numberObjectsToDestroyValue = 0;
                      TacticalAIGroup::setTargetType(this_02,-1);
                      TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                      if (this->sn[0x31] == 0) {
                        TacticalAIGroup::setGatherLocation
                                  (this_02,pRVar26->world_x,pRVar26->world_y,pRVar26->world_z);
                        goto LAB_004f4548;
                      }
                      if (((this->sn[0x31] != 3) || (iVar13 == 0x7e)) || (iVar13 == 0x59))
                      goto LAB_004f4548;
                      if (this->sn[0x87] == 1) {
                        iVar35 = __ftol();
                        iVar13 = this->sn[0x88];
                        iVar36 = __ftol();
                        TribeInformationAIModule::blotExploredMap
                                  (&this->md->informationAI,iVar36 - iVar13,iVar35 - iVar13,
                                   iVar36 + iVar13,iVar13 + iVar35);
                      }
                      TacticalAIGroup::setInUse(this_02,1);
                      TacticalAIGroup::setAction(this_02,7);
                      iVar13 = 1;
                      iVar36 = 0;
                      iVar35 = 7;
                    }
                    else {
LAB_004f436b:
                      iVar13 = TacticalAIGroup::action(this_02);
                      if ((iVar13 == 2) && (this_02->playNumberValue != -1)) {
                        iVar13 = TacticalAIGroup::commander(this_02);
                        pRVar26 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)this->md,iVar13);
                        if ((pRVar26 != (RGE_Static_Object *)0x0) &&
                           ((pUVar22 = RGE_Static_Object::unitAI(pRVar26),
                            pUVar22 != (UnitAIModule *)0x0 &&
                            (pUVar22 = RGE_Static_Object::unitAI(pRVar26),
                            pUVar22->playStatus == (AIPlayStatus *)0x0)))) {
                          this_02->playNumberValue = -1;
                          (this->attackStateValue).active = 0;
                          goto LAB_004f4552;
                        }
                        goto LAB_004f43ca;
                      }
                      iVar13 = TacticalAIGroup::action(this_02);
                      if (iVar13 != 4) {
LAB_004f4499:
                        iVar13 = TacticalAIGroup::action(this_02);
                        if ((iVar13 != 3) &&
                           (iVar13 = TacticalAIGroup::action(this_02), iVar13 != 0xd)) {
                          iVar13 = TacticalAIGroup::currentHitPoints(this_02,this->md);
                          iVar35 = TacticalAIGroup::originalHitPoints(this_02);
                          iVar36 = TacticalAIGroup::originalHitPoints(this_02);
                          iVar38 = TacticalAIGroup::numberUnits(this_02);
                          iVar37 = TacticalAIGroup::originalUnitNumber(this_02);
                          iVar25 = TacticalAIGroup::originalUnitNumber(this_02);
                          if ((this->sn[0x1e] < ((iVar35 - iVar13) * 100) / iVar36) ||
                             (this->sn[0x1f] < ((iVar37 - iVar38) * 100) / iVar25)) {
                            iVar13 = 3;
                            goto LAB_004f4526;
                          }
                        }
                        goto LAB_004f4552;
                      }
                      iVar13 = TacticalAIGroup::allUnitsIdle(this_02,this->md,1);
                      if ((iVar13 != 1) ||
                         (iVar13 = TacticalAIGroup::isGathered(this_02,this,this->md), iVar13 != 0))
{
                        iVar13 = TacticalAIGroup::target(this_02);
                        pRVar26 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)this->md,iVar13);
                        if (pRVar26 != (RGE_Static_Object *)0x0) {
                          iVar36 = (int)pRVar26->master_obj->object_group;
                          iVar13 = TacticalAIGroup::targetType(this_02);
                          iVar35 = TacticalAIGroup::commander(this_02);
                          pOVar27 = TribeInformationAIModule::higherPriorityObjectToDefend
                                              (&this->md->informationAI,iVar35,iVar13,iVar36);
                          if (pOVar27 == (ObjectMemory *)0x0) goto LAB_004f4499;
                          iVar13 = TacticalAIGroup::target(this_02);
                          pOVar27 = TribeInformationAIModule::objectMemory
                                              (&this->md->informationAI,iVar13);
                          if (pOVar27 != (ObjectMemory *)0x0) {
                            pOVar27->attackAttempts = 0;
                          }
                        }
                        TacticalAIGroup::setAction(this_02,1);
                        TacticalAIGroup::setInUse(this_02,0);
                        goto LAB_004f448e;
                      }
                      iVar36 = 1;
                      iVar35 = 9;
                      iVar13 = 0;
                    }
LAB_004f4539:
                    pTVar33 = this->md;
                    goto LAB_004f4540;
                  }
                  pTVar33 = this->md;
                  uVar14 = TacticalAIGroup::consecutiveIdleUnitCount(this_02);
                  if ((uint)this->sn[0x4c] <
                      (*(int *)(*(int *)(pTVar33->_padding_ + 0x3c) + 4) - uVar14) / 1000) {
                    TacticalAIGroup::setInUse(this_02,0);
                    TacticalAIGroup::setAction(this_02,1);
                    TacticalAIGroup::setTarget(this_02,-1);
                    this_02->numberObjectsToDestroyValue = 0;
                    TacticalAIGroup::setTargetType(this_02,-1);
                    TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                    (this->attackStateValue).active = 0;
                    goto LAB_004f4552;
                  }
                  iVar13 = TacticalAIGroup::isGathered(this_02,this,pTVar33);
                  if (iVar13 == 0) goto LAB_004f3a51;
                  TacticalAIGroup::setAction(this_02,1);
                  TacticalAIGroup::setInUse(this_02,0);
                  iVar13 = TacticalAIGroup::type(this_02);
                  if ((iVar13 == 0x65) || (iVar13 = TacticalAIGroup::type(this_02), iVar13 == 0x68))
{
                    iVar13 = TacticalAIGroup::target(this_02);
                    pOVar27 = TribeInformationAIModule::objectMemory
                                        (&this->md->informationAI,iVar13);
                    if (pOVar27 != (ObjectMemory *)0x0) {
                      pOVar27->attackAttempts = 0;
                    }
                  }
                  iVar13 = BuildAIModule::buildListLength((BuildAIModule *)&this->md->buildAI);
                  if ((iVar13 == 0) &&
                     (((iVar13 = TacticalAIGroup::type(this_02), iVar13 == 100 &&
                       (iVar13 = numberGroups(this,100,-1), 1 < iVar13)) ||
                      (iVar13 = TacticalAIGroup::type(this_02), iVar13 != 100)))) {
                    iVar13 = TacticalAIGroup::type(this_02);
                    if (iVar13 == 0x66) {
                      this->sn[0x2a] = this->sn[0x2a] + -1;
                    }
                    else {
                      iVar13 = TacticalAIGroup::type(this_02);
                      if (iVar13 == 0x65) {
                        this->sn[0x26] = this->sn[0x26] + -1;
                      }
                      else {
                        iVar13 = TacticalAIGroup::type(this_02);
                        if (iVar13 == 100) {
                          this->sn[0x24] = this->sn[0x24] + -1;
                        }
                      }
                    }
                    TacticalAIGroup::removeUnits(this_02,this->md);
                    TacticalAIGroup::setAction(this_02,0);
                    (this->attackStateValue).active = 0;
                    goto LAB_004f4552;
                  }
LAB_004f448e:
                  (this->attackStateValue).active = 0;
                  goto LAB_004f4552;
                }
                iVar13 = TacticalAIGroup::isGathered(this_02,this,this->md);
                if (iVar13 == 0) {
                  pTVar33 = this->md;
                  uVar14 = TacticalAIGroup::consecutiveIdleUnitCount(this_02);
                  iVar13 = *(int *)(*(int *)(pTVar33->_padding_ + 0x3c) + 4);
                  iVar35 = TacticalAIGroup::allUnitsIdle(this_02,pTVar33,1);
                  if ((iVar35 == 1) && (5 < (iVar13 - uVar14) / 1000)) {
                    TacticalAIGroup::setConsecutiveIdleUnitCount
                              (this_02,*(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4));
                    pTVar33 = this->md;
                    iVar13 = 0;
                    iVar36 = 1;
                    iVar35 = 9;
                    goto LAB_004f4540;
                  }
                }
              }
LAB_004f4548:
              (this->attackStateValue).active = 0;
            }
          }
        }
LAB_004f4552:
                    /* Symbol Ref: {@symbol ContinueLoop} */
        if ((this->attackStateValue).active != 0) {
          return;
        }
        this_02 = this_02->next;
        if ((this_02 == &this->groups) || (this_02 == (TacticalAIGroup *)0x0)) {
          this->nextActiveSoldierGroupToTaskValue = -1;
        }
        else {
          iVar13 = TacticalAIGroup::id(this_02);
          this->nextActiveSoldierGroupToTaskValue = iVar13;
        }
        uVar14 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x14fe);
        if (param_2 <= uVar14 - param_1) {
          return;
        }
      }
    } while (this_02 != &this->groups);
  }
  this->nextActiveSoldierGroupToTaskValue = -1;
  return;
}

// --------------------------------------------------

// Function: playTaskSoldiers
// Address: 004f4760
/* WARNING: Variable defined which should be unmapped: countUnplayedSoldiers */
/* public: void __thiscall TribeTacticalAIModule::playTaskSoldiers(unsigned long,unsigned long) */

void __thiscall
TribeTacticalAIModule::playTaskSoldiers(TribeTacticalAIModule *this,ulong param_1,ulong param_2)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  ObjectMemory *pOVar5;
  RGE_Static_Object *pRVar6;
  int iVar7;
  int countUnplayedSoldiers;
  ObjectMemory *target;
  int numberPlayUnits;
  int playCommander;
  int playToRun;
  int unplayedSoldiers [50];
  int playUnits [50];
  
  if (this->sn[0xa2] != 0) {
    iVar7 = 0;
    target = (ObjectMemory *)0x0;
    pOVar5 = (ObjectMemory *)0x0;
    if (0 < (this->soldiers).numberValue) {
      numberPlayUnits = (int)(unplayedSoldiers + 1);
      do {
        if ((this->soldiers).maximumSizeValue + -1 < iVar7) {
          piVar1 = (int *)operator_new(iVar7 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->soldiers).maximumSizeValue) {
              do {
                if (iVar7 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (this->soldiers).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (this->soldiers).maximumSizeValue);
            }
            operator_delete((this->soldiers).value);
            (this->soldiers).value = piVar1;
            (this->soldiers).maximumSizeValue = iVar7 + 1;
          }
        }
        pTVar3 = groupUnitIsIn(this,(this->soldiers).value[iVar7]);
        if ((pTVar3 == (TacticalAIGroup *)0x0) ||
           (iVar4 = TacticalAIGroup::type(pTVar3), iVar4 != 100)) {
          if ((this->soldiers).maximumSizeValue + -1 < iVar7) {
            piVar1 = (int *)operator_new(iVar7 * 4 + 4);
            if (piVar1 != (int *)0x0) {
              iVar4 = 0;
              if (0 < (this->soldiers).maximumSizeValue) {
                do {
                  if (iVar7 + 1 <= iVar4) break;
                  iVar2 = iVar4 + 1;
                  piVar1[iVar4] = (this->soldiers).value[iVar4];
                  iVar4 = iVar2;
                } while (iVar2 < (this->soldiers).maximumSizeValue);
              }
              operator_delete((this->soldiers).value);
              (this->soldiers).value = piVar1;
              (this->soldiers).maximumSizeValue = iVar7 + 1;
            }
          }
          target = (ObjectMemory *)((int)&target->id + 1);
          *(int *)numberPlayUnits = (this->soldiers).value[iVar7];
          numberPlayUnits = numberPlayUnits + 4;
        }
        iVar7 = iVar7 + 1;
        pOVar5 = target;
      } while (iVar7 < (this->soldiers).numberValue);
    }
    if (pOVar5 != (ObjectMemory *)0x0) {
      unplayedSoldiers[0] = -1;
      playCommander = 0;
      playToRun = -1;
      if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
         (piVar1 = (int *)operator_new(4), piVar1 != (int *)0x0)) {
        iVar7 = 0;
        if (0 < (this->playersToAttack).maximumSizeValue) {
          do {
            if (0 < iVar7) break;
            iVar4 = iVar7 + 1;
            piVar1[iVar7] = (this->playersToAttack).value[iVar7];
            iVar7 = iVar4;
          } while (iVar4 < (this->playersToAttack).maximumSizeValue);
        }
        operator_delete((this->playersToAttack).value);
        (this->playersToAttack).value = piVar1;
        (this->playersToAttack).maximumSizeValue = 1;
      }
      pOVar5 = TribeInformationAIModule::objectToAttackWithPlay
                         (&this->md->informationAI,*(this->playersToAttack).value,
                          unplayedSoldiers + 1,(int)pOVar5,unplayedSoldiers,playUnits + 1,
                          &playCommander,&playToRun);
      if (((pOVar5 != (ObjectMemory *)0x0) &&
          (pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,playToRun),
          pRVar6 != (RGE_Static_Object *)0x0)) &&
         (pTVar3 = createGroup(this,1), pTVar3 != (TacticalAIGroup *)0x0)) {
        TacticalAIGroup::setType(pTVar3,100);
        TacticalAIGroup::setDesiredNumberUnits(pTVar3,playCommander);
        iVar7 = 0;
        if (0 < playCommander) {
          target = (ObjectMemory *)(playUnits + 1);
          do {
            TacticalAIGroup::addUnit(pTVar3,target->id,this->md);
            iVar7 = iVar7 + 1;
            target = (ObjectMemory *)&target->type;
          } while (iVar7 < playCommander);
        }
        TacticalAIGroup::setSpecificCommander(pTVar3,playToRun,this->md);
        TacticalAIGroup::setLocation(pTVar3,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
        TacticalAIGroup::setGatherLocation(pTVar3,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
        TacticalAIGroup::setRetreatLocation(pTVar3,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
        TacticalAIGroup::setTarget(pTVar3,pOVar5->id);
        pTVar3->playNumberValue = unplayedSoldiers[0];
        TacticalAIGroup::setAction(pTVar3,2);
        TacticalAIGroup::setInUse(pTVar3,1);
        TacticalAIGroup::task(pTVar3,this,this->md,2,1,1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: taskUngroupedSoldiers
// Address: 004f4aa0
/* WARNING: Variable defined which should be unmapped: i */
/* public: void __thiscall TribeTacticalAIModule::taskUngroupedSoldiers(void) */

void __thiscall TribeTacticalAIModule::taskUngroupedSoldiers(TribeTacticalAIModule *this)
{
  ManagedArray<int> *this_00;
  ManagedArray<int> *this_01;
  ulong uVar1;
  RGE_Static_Object *pRVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int i;
  int local_1c;
  RGE_Static_Object *soldierObj;
  XYPoint centerPoint;
  XYPoint gatherPoint;
  int local_4;
  
  uVar1 = ((RGE_Player *)this->md->_padding_)->world->world_time;
  if (0x3b < (uVar1 - this->lastUngroupedSoldierTaskTime) / 1000) {
    this->lastUngroupedSoldierTaskTime = uVar1;
    pRVar2 = MainDecisionAIModule::object
                       ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      centerPoint.y = __ftol();
      gatherPoint.x = __ftol();
      local_1c = 0;
      if (0 < (this->soldiers).numberValue) {
        this_00 = &this->soldiers;
        do {
          if ((this->soldiers).maximumSizeValue + -1 < local_1c) {
            ManagedArray<int>::resize(this_00,local_1c + 1);
          }
          pTVar3 = groupUnitIsIn(this,this_00->value[local_1c]);
          if (pTVar3 == (TacticalAIGroup *)0x0) {
            if ((this->soldiers).maximumSizeValue + -1 < local_1c) {
              ManagedArray<int>::resize(this_00,local_1c + 1);
            }
            centerPoint.x =
                 (int)MainDecisionAIModule::object
                                ((MainDecisionAIModule *)this->md,this_00->value[local_1c]);
            if ((RGE_Static_Object *)centerPoint.x != (RGE_Static_Object *)0x0) {
              if ((this->soldiers).maximumSizeValue + -1 < local_1c) {
                ManagedArray<int>::resize(this_00,local_1c + 1);
              }
              this_01 = &this->ungroupedSoldiers;
              iVar5 = 0;
              if (0 < (this->ungroupedSoldiers).numberValue) {
                do {
                  if ((this->ungroupedSoldiers).maximumSizeValue <= iVar5) break;
                  if (this_01->value[iVar5] == this_00->value[local_1c]) goto LAB_004f4d69;
                  iVar5 = iVar5 + 1;
                } while (iVar5 < (this->ungroupedSoldiers).numberValue);
              }
              if ((this->soldiers).maximumSizeValue + -1 < local_1c) {
                piVar6 = (int *)operator_new(local_1c * 4 + 4);
                if (piVar6 != (int *)0x0) {
                  iVar5 = 0;
                  if (0 < (this->soldiers).maximumSizeValue) {
                    do {
                      if (local_1c + 1 <= iVar5) break;
                      iVar4 = iVar5 + 1;
                      piVar6[iVar5] = this_00->value[iVar5];
                      iVar5 = iVar4;
                    } while (iVar4 < (this->soldiers).maximumSizeValue);
                  }
                  operator_delete(this_00->value);
                  this_00->value = piVar6;
                  (this->soldiers).maximumSizeValue = local_1c + 1;
                }
              }
              iVar7 = 0;
              iVar5 = this_00->value[local_1c];
              iVar4 = (this->ungroupedSoldiers).numberValue;
              if (0 < iVar4) {
                do {
                  if ((this->ungroupedSoldiers).maximumSizeValue <= iVar7) break;
                  if (this_01->value[iVar7] == iVar5) goto LAB_004f4cfa;
                  iVar7 = iVar7 + 1;
                } while (iVar7 < iVar4);
              }
              if ((this->ungroupedSoldiers).maximumSizeValue + -1 < iVar4) {
                ManagedArray<int>::resize(this_01,iVar4 + 1);
              }
              this_01->value[(this->ungroupedSoldiers).numberValue] = iVar5;
              (this->ungroupedSoldiers).numberValue = (this->ungroupedSoldiers).numberValue + 1;
LAB_004f4cfa:
              iVar5 = TribeInformationAIModule::findGatherPosition
                                (&this->md->informationAI,(XYPoint *)&centerPoint.y,1,1,
                                 this->sn[0x16],this->sn[0x48],(RGE_Static_Object *)centerPoint.x,
                                 (XYPoint *)&gatherPoint.y);
              if (iVar5 == 1) {
                if ((this->soldiers).maximumSizeValue + -1 < local_1c) {
                  ManagedArray<int>::resize(this_00,local_1c + 1);
                }
                moveUnit(this,this_00->value[local_1c],(float)gatherPoint.y,(float)local_4,0x32);
              }
            }
          }
          else {
            if ((this->soldiers).maximumSizeValue + -1 < local_1c) {
              ManagedArray<int>::resize(this_00,local_1c + 1);
            }
            iVar5 = (this->ungroupedSoldiers).maximumSizeValue;
            iVar4 = 0;
            if (0 < iVar5) {
              piVar6 = (this->ungroupedSoldiers).value;
              do {
                if (*piVar6 == this_00->value[local_1c]) break;
                iVar4 = iVar4 + 1;
                piVar6 = piVar6 + 1;
              } while (iVar4 < iVar5);
            }
            if (iVar4 < iVar5) {
              if (iVar4 < iVar5 + -1) {
                do {
                  piVar6 = (this->ungroupedSoldiers).value;
                  iVar5 = iVar4 + 1;
                  piVar6[iVar4] = piVar6[iVar5];
                  iVar4 = iVar5;
                } while (iVar5 < (this->ungroupedSoldiers).maximumSizeValue + -1);
              }
              iVar5 = (this->ungroupedSoldiers).numberValue + -1;
              (this->ungroupedSoldiers).numberValue = iVar5;
              if (iVar5 < 0) {
                (this->ungroupedSoldiers).numberValue = 0;
              }
            }
          }
LAB_004f4d69:
          local_1c = local_1c + 1;
        } while (local_1c < (this->soldiers).numberValue);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: taskBoats
// Address: 004f4d90
/* WARNING: Variable defined which should be unmapped: numExclusions */
/* public: void __thiscall TribeTacticalAIModule::taskBoats(void) */

void __thiscall TribeTacticalAIModule::taskBoats(TribeTacticalAIModule *this)
{
  uchar uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  undefined4 uVar6;
  ObjectMemory *pOVar7;
  UnitAIModule *pUVar8;
  RGE_Action_Object *this_00;
  RGE_Action *pRVar9;
  float fVar10;
  TacticalAIGroup *pTVar11;
  bool bVar12;
  float *pfVar13;
  float *pfVar14;
  TribeMainDecisionAIModule *pTVar15;
  float fVar16;
  float *pfVar17;
  float fVar18;
  int *piVar19;
  int iVar20;
  int numExclusions;
  float rXPos;
  float rYPos;
  int dropsiteID;
  int local_54;
  int dropsiteID_ffffffb0;
  float rYPos_ffffffb4;
  float rXPos_ffffffb8;
  float pathDistance;
  float pathDistance_ffffffc0;
  XYZPoint point;
  XYZPoint point_ffffffd0;
  XYZPoint point_ffffffdc;
  int exclusions [5];
  
  pTVar11 = (this->groups).next;
  if (pTVar11 != &this->groups) {
    do {
      if (pTVar11 == (TacticalAIGroup *)0x0) break;
      iVar2 = TacticalAIGroup::type(pTVar11);
      if (((((iVar2 != 100) && (iVar2 = TacticalAIGroup::type(pTVar11), iVar2 != 0x65)) &&
           (iVar2 = TacticalAIGroup::type(pTVar11), iVar2 != 0x66)) &&
          ((iVar2 = TacticalAIGroup::type(pTVar11), iVar2 != 0x67 &&
           (iVar2 = TacticalAIGroup::type(pTVar11), iVar2 != 0x68)))) &&
         ((iVar2 = TacticalAIGroup::type(pTVar11), iVar2 != 0x69 &&
          ((iVar2 = TacticalAIGroup::action(pTVar11), iVar2 == 0 ||
           (iVar2 = TacticalAIGroup::action(pTVar11), iVar2 == 1)))))) {
        bVar12 = true;
        iVar2 = TacticalAIGroup::isGathered(pTVar11,this,this->md);
        iVar3 = TacticalAIGroup::numberUnits(pTVar11);
        iVar4 = TacticalAIGroup::desiredNumberUnits(pTVar11);
        if ((iVar3 < iVar4) ||
           (((iVar2 == 0 && (iVar3 = TacticalAIGroup::numberUnits(pTVar11), 1 < iVar3)) ||
            (iVar3 = TacticalAIGroup::allUnitsIdle(pTVar11,this->md,1), iVar3 == 0)))) {
          bVar12 = false;
        }
        if (bVar12) {
          iVar2 = TacticalAIGroup::type(pTVar11);
          if (iVar2 == 0x6b) {
            iVar2 = 10;
          }
          else {
            iVar2 = TacticalAIGroup::type(pTVar11);
            if (iVar2 == 0x6c) {
              iVar2 = 0xb;
            }
            else {
              iVar2 = TacticalAIGroup::type(pTVar11);
              if (iVar2 != 0x6a) goto LAB_004f4edc;
              iVar2 = 1;
            }
          }
          TacticalAIGroup::setAction(pTVar11,iVar2);
        }
        else if (iVar2 == 0) {
          TacticalAIGroup::task(pTVar11,this,this->md,9,1,0);
        }
      }
LAB_004f4edc:
      pTVar11 = pTVar11->next;
    } while (pTVar11 != &this->groups);
  }
  pTVar11 = (this->groups).next;
  if (pTVar11 != &this->groups) {
    do {
      if (pTVar11 == (TacticalAIGroup *)0x0) {
        return;
      }
      iVar2 = TacticalAIGroup::type(pTVar11);
      if (((((iVar2 == 100) || (iVar2 = TacticalAIGroup::type(pTVar11), iVar2 == 0x65)) ||
           ((iVar2 = TacticalAIGroup::type(pTVar11), iVar2 == 0x66 ||
            ((iVar2 = TacticalAIGroup::type(pTVar11), iVar2 == 0x67 ||
             (iVar2 = TacticalAIGroup::type(pTVar11), iVar2 == 0x68)))))) ||
          (iVar2 = TacticalAIGroup::type(pTVar11), iVar2 == 0x69)) ||
         ((iVar2 = TacticalAIGroup::action(pTVar11), iVar2 == 0 ||
          (iVar2 = TacticalAIGroup::action(pTVar11), iVar2 == 1)))) goto LAB_004f579c;
      iVar2 = TacticalAIGroup::inUse(pTVar11);
      if (iVar2 == 0) {
        iVar2 = TacticalAIGroup::type(pTVar11);
        if (iVar2 == 0x6b) {
          iVar2 = TacticalAIGroup::commander(pTVar11);
          pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar2);
          if (pRVar5 == (RGE_Static_Object *)0x0) {
            TacticalAIGroup::setAction(pTVar11,1);
          }
          else {
            iVar3 = -1;
            rXPos = 0.0;
            local_54 = -1;
            iVar2 = numberWaterExplorers(this);
            if (0 < iVar2) {
              iVar2 = TacticalAIGroup::commander(pTVar11);
              iVar2 = TribeInformationAIModule::fullyExploredZone(&this->md->informationAI,iVar2);
              if (iVar2 == 1) {
                dropsiteID_ffffffb0 = (int)(exclusions + 1);
                rYPos_ffffffb4 = 0.0;
                do {
                  rYPos = 0.0;
                  dropsiteID = 0;
                  iVar3 = TribeInformationAIModule::gameIDOfResourceObject
                                    (&this->md->informationAI,0,pRVar5->id,&rYPos,
                                     (float *)&dropsiteID,&local_54,exclusions + 1,(int)rXPos);
                  point.y = __ftol();
                  point.z = __ftol();
                  uVar6 = __ftol();
                  if (local_54 == -1) {
                    iVar2 = (**(code **)(pRVar5->_padding_ + 0x198))
                                      (point.y,point.z,uVar6,0x3f800000,iVar3);
                  }
                  else {
                    iVar2 = (**(code **)(pRVar5->_padding_ + 0x19c))
                                      (iVar3,local_54,0x3f800000,0,1,0xffffffff,0xffffffff);
                  }
                  if (iVar2 == 0) {
                    rXPos = (float)((int)rXPos + 1);
                    *(int *)dropsiteID_ffffffb0 = iVar3;
                    dropsiteID_ffffffb0 = dropsiteID_ffffffb0 + 4;
                  }
                } while ((iVar2 != 1) &&
                        (rYPos_ffffffb4 = (float)((int)rYPos_ffffffb4 + 1), (int)rYPos_ffffffb4 < 5)
                        );
              }
            }
            pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar3);
            if ((-1 < iVar3) && (pRVar5 != (RGE_Static_Object *)0x0)) {
              TacticalAIGroup::setTarget(pTVar11,iVar3);
              TacticalAIGroup::setTargetType(pTVar11,(int)pRVar5->master_obj->id);
              fVar10 = pRVar5->world_z;
              fVar18 = pRVar5->world_y;
              fVar16 = pRVar5->world_x;
LAB_004f52da:
              TacticalAIGroup::setTargetLocation(pTVar11,fVar16,fVar18,fVar10);
              TacticalAIGroup::setInUse(pTVar11,1);
              goto LAB_004f52ea;
            }
            iVar2 = TacticalAIGroup::commander(pTVar11);
            iVar2 = TribeInformationAIModule::fullyExploredZone(&this->md->informationAI,iVar2);
            if (iVar2 == 1) {
              TacticalAIGroup::setAction(pTVar11,8);
              iVar4 = 0;
              iVar3 = 1;
              iVar2 = TacticalAIGroup::action(pTVar11);
              TacticalAIGroup::task(pTVar11,this,this->md,iVar2,iVar3,iVar4);
              TacticalAIGroup::setInUse(pTVar11,1);
              goto LAB_004f579c;
            }
LAB_004f571d:
            TacticalAIGroup::setAction(pTVar11,1);
          }
        }
        else {
          iVar2 = TacticalAIGroup::type(pTVar11);
          if (iVar2 == 0x6c) {
            iVar2 = TacticalAIGroup::commander(pTVar11);
            pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar2);
            if (pRVar5 == (RGE_Static_Object *)0x0) {
              TacticalAIGroup::setAction(pTVar11,1);
            }
            else {
              iVar2 = TacticalAIGroup::commander(pTVar11);
              pOVar7 = TribeInformationAIModule::objectToTradeWith(&this->md->informationAI,iVar2);
              if (pOVar7 == (ObjectMemory *)0x0) {
                iVar2 = TacticalAIGroup::commander(pTVar11);
                iVar2 = TribeInformationAIModule::fullyExploredZone(&this->md->informationAI,iVar2);
                if (iVar2 != 1) goto LAB_004f571d;
                TacticalAIGroup::setAction(pTVar11,8);
                iVar3 = 1;
                iVar2 = TacticalAIGroup::action(pTVar11);
                TacticalAIGroup::task(pTVar11,this,this->md,iVar2,iVar3,(int)pOVar7);
                TacticalAIGroup::setInUse(pTVar11,1);
              }
              else {
                iVar2 = (**(code **)(pRVar5->_padding_ + 0x198))
                                  (pOVar7->x,pOVar7->y,pOVar7->z,0x3f800000,pOVar7->id,
                                   &pathDistance_ffffffc0,1,0xffffffff,0xffffffff);
                if (iVar2 != 0) {
                  TacticalAIGroup::setTarget(pTVar11,pOVar7->id);
                  TacticalAIGroup::setTargetType(pTVar11,(int)pOVar7->type);
                  fVar10 = (float)pOVar7->z;
                  rYPos_ffffffb4 = (float)(uint)pOVar7->x;
                  fVar18 = (float)pOVar7->y;
                  fVar16 = (float)(int)rYPos_ffffffb4;
                  goto LAB_004f52da;
                }
                TacticalAIGroup::setAction(pTVar11,1);
              }
            }
            goto LAB_004f579c;
          }
LAB_004f52ea:
          iVar4 = 0;
LAB_004f5783:
          iVar3 = 1;
          iVar2 = TacticalAIGroup::action(pTVar11);
          pTVar15 = this->md;
LAB_004f5794:
          TacticalAIGroup::task(pTVar11,this,pTVar15,iVar2,iVar3,iVar4);
        }
      }
      else {
        iVar2 = TacticalAIGroup::action(pTVar11);
        if (iVar2 == 8) {
          iVar3 = 0;
          iVar2 = TacticalAIGroup::type(pTVar11);
          if (iVar2 == 0x6c) {
            iVar2 = TacticalAIGroup::commander(pTVar11);
            pOVar7 = TribeInformationAIModule::objectToTradeWith(&this->md->informationAI,iVar2);
            if (pOVar7 != (ObjectMemory *)0x0) {
              iVar3 = 1;
            }
          }
          iVar2 = TacticalAIGroup::type(pTVar11);
          if (iVar2 == 0x6b) {
            iVar2 = numberWaterExplorers(this);
            if (iVar2 < 2) {
              iVar2 = TacticalAIGroup::commander(pTVar11);
              pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar2);
              if ((pRVar5 != (RGE_Static_Object *)0x0) &&
                 (pUVar8 = RGE_Static_Object::unitAI(pRVar5), pUVar8 != (UnitAIModule *)0x0)) {
                pUVar8 = RGE_Static_Object::unitAI(pRVar5);
                iVar2 = UnitAIModule::currentOrder(pUVar8);
                if (iVar2 != 0x2c1) {
                  TacticalAIGroup::setAction(pTVar11,8);
                  iVar20 = 0;
                  iVar4 = 1;
                  iVar2 = TacticalAIGroup::action(pTVar11);
                  TacticalAIGroup::task(pTVar11,this,this->md,iVar2,iVar4,iVar20);
                  TacticalAIGroup::setInUse(pTVar11,1);
                }
              }
            }
            else {
              iVar4 = 0;
              pfVar17 = &rYPos_ffffffb4;
              piVar19 = (int *)0x0;
              pfVar14 = &rXPos_ffffffb8;
              pfVar13 = &pathDistance;
              pathDistance = 0.0;
              rXPos_ffffffb8 = 0.0;
              rYPos_ffffffb4 = -NAN;
              iVar2 = TacticalAIGroup::commander(pTVar11);
              iVar2 = TribeInformationAIModule::gameIDOfResourceObject
                                (&this->md->informationAI,0,iVar2,pfVar13,pfVar14,(int *)pfVar17,
                                 piVar19,iVar4);
              if (iVar2 != -1) {
                iVar3 = 1;
              }
            }
          }
          if (iVar3 != 1) goto LAB_004f5496;
          iVar2 = TacticalAIGroup::commander(pTVar11);
          pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar2);
          if (pRVar5 == (RGE_Static_Object *)0x0) goto LAB_004f579c;
          TacticalAIGroup::setInUse(pTVar11,0);
          TacticalAIGroup::setAction(pTVar11,1);
          TacticalAIGroup::setTarget(pTVar11,-1);
          pTVar11->numberObjectsToDestroyValue = 0;
          TacticalAIGroup::setTargetType(pTVar11,-1);
          TacticalAIGroup::setTargetLocation(pTVar11,-1.0,-1.0,-1.0);
          TacticalAIGroup::setGatherLocation
                    (pTVar11,pRVar5->world_x,pRVar5->world_y,pRVar5->world_z);
          iVar4 = 0;
          iVar2 = TacticalAIGroup::action(pTVar11);
          pTVar15 = this->md;
          goto LAB_004f5794;
        }
LAB_004f5496:
        iVar2 = TacticalAIGroup::action(pTVar11);
        if (iVar2 == 10) {
          iVar2 = TacticalAIGroup::target(pTVar11);
          pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar2);
          if (pRVar5 == (RGE_Static_Object *)0x0) {
            TacticalAIGroup::setInUse(pTVar11,0);
            TacticalAIGroup::setAction(pTVar11,1);
            TacticalAIGroup::setTarget(pTVar11,-1);
            TacticalAIGroup::setTargetType(pTVar11,-1);
            TacticalAIGroup::setTargetLocation(pTVar11,-1.0,-1.0,-1.0);
            pTVar11->numberObjectsToDestroyValue = 0;
            goto LAB_004f579c;
          }
          iVar2 = TacticalAIGroup::commander(pTVar11);
          pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar2);
          if ((pRVar5 != (RGE_Static_Object *)0x0) &&
             (pUVar8 = RGE_Static_Object::unitAI(pRVar5), pUVar8 != (UnitAIModule *)0x0)) {
            pUVar8 = RGE_Static_Object::unitAI(pRVar5);
            iVar2 = UnitAIModule::currentAction(pUVar8);
            if (iVar2 == -1) {
              TacticalAIGroup::setInUse(pTVar11,0);
              TacticalAIGroup::setAction(pTVar11,1);
              TacticalAIGroup::setTarget(pTVar11,-1);
              pTVar11->numberObjectsToDestroyValue = 0;
              TacticalAIGroup::setTargetType(pTVar11,-1);
              TacticalAIGroup::setTargetLocation(pTVar11,-1.0,-1.0,-1.0);
              pTVar11 = pTVar11->next;
            }
          }
        }
        iVar2 = TacticalAIGroup::action(pTVar11);
        if (iVar2 == 0xb) {
          iVar2 = TacticalAIGroup::target(pTVar11);
          pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar2);
          if (pRVar5 == (RGE_Static_Object *)0x0) {
            TacticalAIGroup::setInUse(pTVar11,0);
            TacticalAIGroup::setAction(pTVar11,1);
            TacticalAIGroup::setTarget(pTVar11,-1);
            pTVar11->numberObjectsToDestroyValue = 0;
            TacticalAIGroup::setTargetType(pTVar11,-1);
            TacticalAIGroup::setTargetLocation(pTVar11,-1.0,-1.0,-1.0);
          }
          else {
            iVar2 = TacticalAIGroup::commander(pTVar11);
            this_00 = (RGE_Action_Object *)
                      MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar2);
            if ((this_00 != (RGE_Action_Object *)0x0) &&
               (pUVar8 = RGE_Static_Object::unitAI((RGE_Static_Object *)this_00),
               pUVar8 != (UnitAIModule *)0x0)) {
              pUVar8 = RGE_Static_Object::unitAI((RGE_Static_Object *)this_00);
              iVar2 = UnitAIModule::currentAction(pUVar8);
              if (iVar2 == -1) {
                TacticalAIGroup::setInUse(pTVar11,0);
                TacticalAIGroup::setAction(pTVar11,1);
                TacticalAIGroup::setTarget(pTVar11,-1);
                pTVar11->numberObjectsToDestroyValue = 0;
                TacticalAIGroup::setTargetType(pTVar11,-1);
                TacticalAIGroup::setTargetLocation(pTVar11,-1.0,-1.0,-1.0);
                pTVar11 = pTVar11->next;
              }
              else {
                uVar1 = RGE_Action_Object::have_action(this_00);
                if (uVar1 != '\0') {
                  pRVar9 = RGE_Action_List::get_action(this_00->actions);
                  pOVar7 = TribeInformationAIModule::objectToTradeWith
                                     (&this->md->informationAI,pRVar9->target2ID);
                  if (pOVar7 != (ObjectMemory *)0x0) {
                    rYPos_ffffffb4 = (float)pOVar7->id;
                    fVar10 = (float)TacticalAIGroup::target(pTVar11);
                    if (rYPos_ffffffb4 != fVar10) {
                      exclusions[0] = (int)pOVar7->z;
                      iVar2 = (**(code **)(this_00->_padding_ + 0x198))
                                        (pOVar7->x,pOVar7->y,exclusions[0],0x3f800000,rYPos_ffffffb4
                                         ,&point,1,0xffffffff,0xffffffff);
                      if (iVar2 == 0) goto LAB_004f571d;
                      TacticalAIGroup::setTarget(pTVar11,pOVar7->id);
                      TacticalAIGroup::setTargetType(pTVar11,(int)pOVar7->type);
                      rYPos_ffffffb4 = (float)(uint)pOVar7->x;
                      TacticalAIGroup::setTargetLocation
                                (pTVar11,(float)(int)rYPos_ffffffb4,(float)pOVar7->y,
                                 (float)pOVar7->z);
                      TacticalAIGroup::setInUse(pTVar11,1);
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
      pTVar11 = pTVar11->next;
    } while (pTVar11 != &this->groups);
  }
  return;
}

// --------------------------------------------------

// Function: evaluateOpenTasks
// Address: 004f57c0
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TribeTacticalAIModule::evaluateOpenTasks(void) */

void __thiscall TribeTacticalAIModule::evaluateOpenTasks(TribeTacticalAIModule *this)
{
  ManagedArray<int> *this_00;
  ManagedArray<int> *this_01;
  char cVar1;
  byte bVar2;
  RGE_Static_Object *pRVar3;
  UnitAIModule *pUVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  int *piVar7;
  int iVar8;
  TacticalAIGroup *this_02;
  int iVar9;
  TacticalAIGroup *this_03;
  float10 fVar10;
  int iVar11;
  int i;
  int local_10;
  
  local_10 = 0;
  if (0 < (this->civilians).numberValue) {
    this_00 = &this->civilians;
    do {
      if ((this->civilians).maximumSizeValue + -1 < local_10) {
        ManagedArray<int>::resize(this_00,local_10 + 1);
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),this_00->value[local_10])
      ;
      if ((pRVar3 != (RGE_Static_Object *)0x0) &&
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 != (UnitAIModule *)0x0)) {
        if ((this->civilians).maximumSizeValue + -1 < local_10) {
          ManagedArray<int>::resize(this_00,local_10 + 1);
        }
        iVar9 = (this->unitsTaskedThisUpdate).numberValue;
        iVar5 = 0;
        if (0 < iVar9) {
          do {
            if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar5) break;
            if ((this->unitsTaskedThisUpdate).value[iVar5] == this_00->value[local_10])
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
            pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar9);
            if ((pRVar3 == (RGE_Static_Object *)0x0) || (2 < pRVar3->object_state)) {
              if ((this->civilians).maximumSizeValue + -1 < local_10) {
                ManagedArray<int>::resize(this_00,local_10 + 1);
              }
              iVar9 = this_00->value[local_10];
              goto LAB_004f5a79;
            }
          }
        }
        else {
          pRVar6 = TribeInformationAIModule::findClosestReturnDropsite
                             (&this->md->informationAI,pRVar3);
          if (pRVar6 == (RGE_Static_Object *)0x0) {
            if ((this->civilians).maximumSizeValue + -1 < local_10) {
              piVar7 = (int *)operator_new(local_10 * 4 + 4);
              if (piVar7 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (this->civilians).maximumSizeValue) {
                  do {
                    if (local_10 + 1 <= iVar9) break;
                    iVar5 = iVar9 + 1;
                    piVar7[iVar9] = this_00->value[iVar9];
                    iVar9 = iVar5;
                  } while (iVar5 < (this->civilians).maximumSizeValue);
                }
                operator_delete(this_00->value);
                this_00->value = piVar7;
                (this->civilians).maximumSizeValue = local_10 + 1;
              }
            }
            iVar9 = this_00->value[local_10];
LAB_004f5a79:
            stopUnit(this,iVar9,100);
          }
          else {
            (**(code **)(*(int *)this->md->_padding_ + 0x40))
                      (pRVar3,pRVar6,pRVar6->world_x,pRVar6->world_y);
            if ((this->civilians).maximumSizeValue + -1 < local_10) {
              piVar7 = (int *)operator_new(local_10 * 4 + 4);
              if (piVar7 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (this->civilians).maximumSizeValue) {
                  do {
                    if (local_10 + 1 <= iVar9) break;
                    iVar5 = iVar9 + 1;
                    piVar7[iVar9] = this_00->value[iVar9];
                    iVar9 = iVar5;
                  } while (iVar5 < (this->civilians).maximumSizeValue);
                }
                operator_delete(this_00->value);
                this_00->value = piVar7;
                (this->civilians).maximumSizeValue = local_10 + 1;
              }
            }
            this_01 = &this->unitsTaskedThisUpdate;
            iVar8 = 0;
            iVar9 = this_00->value[local_10];
            iVar5 = (this->unitsTaskedThisUpdate).numberValue;
            if (0 < iVar5) {
              do {
                if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar8) break;
                if (this_01->value[iVar8] == iVar9) goto LAB_004f5a80;
                iVar8 = iVar8 + 1;
              } while (iVar8 < iVar5);
            }
            if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar5) {
              ManagedArray<int>::resize(this_01,iVar5 + 1);
            }
            this_01->value[(this->unitsTaskedThisUpdate).numberValue] = iVar9;
            (this->unitsTaskedThisUpdate).numberValue =
                 (this->unitsTaskedThisUpdate).numberValue + 1;
          }
        }
      }
LAB_004f5a80:
      local_10 = local_10 + 1;
    } while (local_10 < (this->civilians).numberValue);
  }
  iVar9 = 0;
  if (0 < (this->civilians).numberValue) {
    do {
      if ((this->civilians).maximumSizeValue + -1 < iVar9) {
        piVar7 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar7 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (this->civilians).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar5) break;
              iVar8 = iVar5 + 1;
              piVar7[iVar5] = (this->civilians).value[iVar5];
              iVar5 = iVar8;
            } while (iVar8 < (this->civilians).maximumSizeValue);
          }
          operator_delete((this->civilians).value);
          (this->civilians).value = piVar7;
          (this->civilians).maximumSizeValue = iVar9 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),
                          (this->civilians).value[iVar9]);
      if (((pRVar3 == (RGE_Static_Object *)0x0) || (pRVar3->hp < _DAT_005756f4)) ||
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 == (UnitAIModule *)0x0)) {
        if ((this->civilians).maximumSizeValue + -1 < iVar9) {
          piVar7 = (int *)operator_new(iVar9 * 4 + 4);
          if (piVar7 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (this->civilians).maximumSizeValue) {
              do {
                if (iVar9 + 1 <= iVar5) break;
                iVar8 = iVar5 + 1;
                piVar7[iVar5] = (this->civilians).value[iVar5];
                iVar5 = iVar8;
              } while (iVar8 < (this->civilians).maximumSizeValue);
            }
            operator_delete((this->civilians).value);
            (this->civilians).value = piVar7;
            (this->civilians).maximumSizeValue = iVar9 + 1;
          }
        }
        removeObject(this,(this->civilians).value[iVar9]);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->civilians).numberValue);
  }
  iVar9 = 0;
  if (0 < (this->soldiers).numberValue) {
    do {
      if ((this->soldiers).maximumSizeValue + -1 < iVar9) {
        piVar7 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar7 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (this->soldiers).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar5) break;
              iVar8 = iVar5 + 1;
              piVar7[iVar5] = (this->soldiers).value[iVar5];
              iVar5 = iVar8;
            } while (iVar8 < (this->soldiers).maximumSizeValue);
          }
          operator_delete((this->soldiers).value);
          (this->soldiers).value = piVar7;
          (this->soldiers).maximumSizeValue = iVar9 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),
                          (this->soldiers).value[iVar9]);
      if (((pRVar3 == (RGE_Static_Object *)0x0) || (pRVar3->hp < _DAT_005756f4)) ||
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 == (UnitAIModule *)0x0)) {
        if ((this->soldiers).maximumSizeValue + -1 < iVar9) {
          piVar7 = (int *)operator_new(iVar9 * 4 + 4);
          if (piVar7 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (this->soldiers).maximumSizeValue) {
              do {
                if (iVar9 + 1 <= iVar5) break;
                iVar8 = iVar5 + 1;
                piVar7[iVar5] = (this->soldiers).value[iVar5];
                iVar5 = iVar8;
              } while (iVar8 < (this->soldiers).maximumSizeValue);
            }
            operator_delete((this->soldiers).value);
            (this->soldiers).value = piVar7;
            (this->soldiers).maximumSizeValue = iVar9 + 1;
          }
        }
        removeObject(this,(this->soldiers).value[iVar9]);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->soldiers).numberValue);
  }
  iVar9 = 0;
  if (0 < (this->boats).numberValue) {
    do {
      if ((this->boats).maximumSizeValue + -1 < iVar9) {
        piVar7 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar7 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (this->boats).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar5) break;
              iVar8 = iVar5 + 1;
              piVar7[iVar5] = (this->boats).value[iVar5];
              iVar5 = iVar8;
            } while (iVar8 < (this->boats).maximumSizeValue);
          }
          operator_delete((this->boats).value);
          (this->boats).value = piVar7;
          (this->boats).maximumSizeValue = iVar9 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),
                          (this->boats).value[iVar9]);
      if (((pRVar3 == (RGE_Static_Object *)0x0) || (pRVar3->hp < _DAT_005756f4)) ||
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 == (UnitAIModule *)0x0)) {
        if ((this->boats).maximumSizeValue + -1 < iVar9) {
          piVar7 = (int *)operator_new(iVar9 * 4 + 4);
          if (piVar7 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (this->boats).maximumSizeValue) {
              do {
                if (iVar9 + 1 <= iVar5) break;
                iVar8 = iVar5 + 1;
                piVar7[iVar5] = (this->boats).value[iVar5];
                iVar5 = iVar8;
              } while (iVar8 < (this->boats).maximumSizeValue);
            }
            operator_delete((this->boats).value);
            (this->boats).value = piVar7;
            (this->boats).maximumSizeValue = iVar9 + 1;
          }
        }
        removeObject(this,(this->boats).value[iVar9]);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->boats).numberValue);
  }
  this_03 = (this->groups).next;
  if (this_03 != &this->groups) {
    do {
      if (this_03 == (TacticalAIGroup *)0x0) {
        return;
      }
      iVar9 = TacticalAIGroup::type(this_03);
      if ((iVar9 == 0x6a) && (iVar9 = TacticalAIGroup::action(this_03), iVar9 == 0xc)) {
        iVar11 = -1;
        iVar8 = -1;
        iVar5 = -1;
        iVar9 = TacticalAIGroup::assistGroupID(this_03);
        this_02 = group(this,iVar9,iVar5,iVar8,iVar11);
        iVar9 = TacticalAIGroup::assistGroupID(this_03);
        if ((iVar9 == -1) || (this_02 == (TacticalAIGroup *)0x0)) {
          TacticalAIGroup::setAction(this_03,1);
          TacticalAIGroup::setTarget(this_03,-1);
          TacticalAIGroup::setTargetType(this_03,-1);
          TacticalAIGroup::setTargetLocation(this_03,-1.0,-1.0,-1.0);
          TacticalAIGroup::setGatherLocation(this_03,-1.0,-1.0,-1.0);
          TacticalAIGroup::setRetreatLocation(this_03,-1.0,-1.0,-1.0);
          TacticalAIGroup::setInUse(this_03,0);
          TacticalAIGroup::setWaitCode(this_03,-1);
          this_03->playNumberValue = -1;
        }
        else {
          iVar9 = TacticalAIGroup::commander(this_03);
          pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar9);
          if (((pRVar3 != (RGE_Static_Object *)0x0) &&
              (cVar1 = (**(code **)(pRVar3->_padding_ + 0x134))(), cVar1 == '\x02')) &&
             (iVar9 = TacticalAIGroup::action(this_02), iVar9 == 0x10)) {
            iVar9 = TacticalAIGroup::commander(this_02);
            pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar9);
            if ((pRVar3 != (RGE_Static_Object *)0x0) && (0 < pRVar3->objects->number_of_objects)) {
              TacticalAIGroup::setAction(this_02,0xf);
            }
          }
        }
      }
      this_03 = this_03->next;
    } while (this_03 != &this->groups);
  }
  return;
}

// --------------------------------------------------

// Function: evaluateBuildListInsertions
// Address: 004f5fb0
/* public: void __thiscall TribeTacticalAIModule::evaluateBuildListInsertions(void) */

void __thiscall TribeTacticalAIModule::evaluateBuildListInsertions(TribeTacticalAIModule *this)
{
  int iVar1;
  
  if (this->sn[0xcd] == 1) {
    iVar1 = BuildAIModule::haveBuildList((BuildAIModule *)&this->md->buildAI);
    if (((iVar1 != 0) && (this->builtFirstStoragePit == 0)) &&
       (this->sn[0xa9] <= (this->md->informationAI).numberFoundForestTilesValue)) {
                    /* language.dll match for 0x67: "Comic Sans MS" */
      TribeBuildAIModule::insert(&this->md->buildAI,0x67,1,0);
      this->builtFirstStoragePit = 1;
    }
    if (this->sn[0xcd] == 1) {
      iVar1 = BuildAIModule::haveBuildList((BuildAIModule *)&this->md->buildAI);
      if ((iVar1 != 0) && (this->builtFirstGranary == 0)) {
        if (this->builtFirstStoragePit != 1) {
          iVar1 = TribeResourceAIModule::resource(&this->md->resourceAI,1);
          if (iVar1 < 0xfa) goto LAB_004f607f;
        }
        if ((this->md->informationAI).closestDropsiteValue[0] != -1) {
          TribeBuildAIModule::insert(&this->md->buildAI,0x44,1,1);
          this->builtFirstGranary = 1;
          goto LAB_004f6093;
        }
      }
    }
  }
LAB_004f607f:
  if (this->builtFirstGranary == 1) {
    checkForBuildInsertion(this,0x44,1,0);
  }
LAB_004f6093:
  if ((this->sn[0xaf] != -1) &&
     ((uint)this->sn[0xb0] <= *(uint *)(*(int *)(this->md->_padding_ + 0x3c) + 4) / 60000)) {
    TribeBuildAIModule::insert(&this->md->buildAI,this->sn[0xaf],1,0);
    this->sn[0xaf] = -1;
  }
  checkForBuildInsertion(this,0x32,1,0);
  checkForBuildInsertion(this,0x4f,1,0);
  return;
}

// --------------------------------------------------

// Function: numberCivilians
// Address: 004f6100
/* public: int __thiscall TribeTacticalAIModule::numberCivilians(void)const  */

int __thiscall TribeTacticalAIModule::numberCivilians(TribeTacticalAIModule *this)
{
  return (this->civilians).numberValue;
}

// --------------------------------------------------

// Function: numberCivilianExplorers
// Address: 004f6110
/* public: int __thiscall TribeTacticalAIModule::numberCivilianExplorers(void)const  */

int __thiscall TribeTacticalAIModule::numberCivilianExplorers(TribeTacticalAIModule *this)
{
  return (this->civilianExplorers).numberValue;
}

// --------------------------------------------------

// Function: numberGatherers
// Address: 004f6120
/* public: int __thiscall TribeTacticalAIModule::numberGatherers(void)const  */

int __thiscall TribeTacticalAIModule::numberGatherers(TribeTacticalAIModule *this)
{
  return this->numberGatherersValue;
}

// --------------------------------------------------

// Function: desiredNumberCivilianExplorers
// Address: 004f6130
/* public: int __thiscall TribeTacticalAIModule::desiredNumberCivilianExplorers(void)const  */

int __thiscall TribeTacticalAIModule::desiredNumberCivilianExplorers(TribeTacticalAIModule *this)
{
  return (this->civilianExplorers).desiredNumberValue;
}

// --------------------------------------------------

// Function: desiredNumberGatherers
// Address: 004f6140
/* public: int __thiscall TribeTacticalAIModule::desiredNumberGatherers(void)const  */

int __thiscall TribeTacticalAIModule::desiredNumberGatherers(TribeTacticalAIModule *this)
{
  return this->desiredNumberGatherersValue;
}

// --------------------------------------------------

// Function: numberSoldiers
// Address: 004f6150
/* public: int __thiscall TribeTacticalAIModule::numberSoldiers(void)const  */

int __thiscall TribeTacticalAIModule::numberSoldiers(TribeTacticalAIModule *this)
{
  return (this->soldiers).numberValue;
}

// --------------------------------------------------

// Function: numberSoldierExplorers
// Address: 004f6160
/* public: int __thiscall TribeTacticalAIModule::numberSoldierExplorers(void) */

int __thiscall TribeTacticalAIModule::numberSoldierExplorers(TribeTacticalAIModule *this)
{
  int iVar1;
  
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
  iVar1 = numberUnitsInGroups(this,0x66);
  return iVar1;
}

// --------------------------------------------------

// Function: numberBoats
// Address: 004f6170
/* public: int __thiscall TribeTacticalAIModule::numberBoats(void)const  */

int __thiscall TribeTacticalAIModule::numberBoats(TribeTacticalAIModule *this)
{
  return (this->boats).numberValue;
}

// --------------------------------------------------

// Function: neededResource
// Address: 004f6180
/* public: int __thiscall TribeTacticalAIModule::neededResource(int)const  */

int __thiscall TribeTacticalAIModule::neededResource(TribeTacticalAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 4)) {
    return this->neededResourceValue[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: neededResourceAmount
// Address: 004f61a0
/* public: int __thiscall TribeTacticalAIModule::neededResourceAmount(int)const  */

int __thiscall TribeTacticalAIModule::neededResourceAmount(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 < 4)) {
    iVar1 = ResourceItem::value(&this->neededResources,this->neededResourceValue[param_1]);
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

// Function: detask
// Address: 004f61d0
// [HELPER] s_ERROR_DETASKING_Unit___d_: "ERROR DETASKING Unit #%d!"
/* public: void __thiscall TribeTacticalAIModule::detask(int) */

void __thiscall TribeTacticalAIModule::detask(TribeTacticalAIModule *this,int param_1)
{
  if (param_1 == -1) {
    AIModule::logCommonHistory((AIModule *)this,(char *)this,s_ERROR_DETASKING_Unit___d_,0xffffffff)
    ;
    return;
  }
  removeFromTaskLists(this,param_1);
  stopUnit(this,param_1,100);
  return;
}

// --------------------------------------------------

// Function: strategicNumber
// Address: 004f6210
/* public: int __thiscall TribeTacticalAIModule::strategicNumber(int) */

int __thiscall TribeTacticalAIModule::strategicNumber(TribeTacticalAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 0xe2)) {
    return this->sn[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: setStrategicNumber
// Address: 004f6230
/* public: void __thiscall TribeTacticalAIModule::setStrategicNumber(int,int) */

void __thiscall
TribeTacticalAIModule::setStrategicNumber(TribeTacticalAIModule *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 0xe2)) {
    this->sn[param_1] = param_2;
    if ((((param_1 == 0x75) || (((param_1 == 0x78 || (param_1 == 0x77)) || (param_1 == 0x76)))) ||
        (((param_1 == 0x9c || (param_1 == 0x9d)) || (param_1 == 0x9e)))) || (param_1 == 0x9f)) {
      if (param_2 < 0) {
        this->sn[param_1] = 0;
      }
      else if (100 < param_2) {
        this->sn[param_1] = 100;
      }
    }
    if (param_1 == 0x69) {
      TribeInformationAIModule::setSaveLearnInformation(&this->md->informationAI,param_2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: notify
// Address: 004f62c0
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Variable defined which should be unmapped: numberToRespond */
/* public: virtual void __thiscall TribeTacticalAIModule::notify(int,int,int,long,long,long) */

void __thiscall
TribeTacticalAIModule::notify
          (TribeTacticalAIModule *this,int param_1,int param_2,int param_3,long param_4,long param_5
          ,long param_6)
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
  TacticalAIGroup *this_00;
  RGE_Static_Object *pRVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  ulong uVar20;
  ObjectMemory *pOVar21;
  float10 fVar22;
  float fVar23;
  int unaff_retaddr;
  uchar uVar24;
  uchar uVar25;
  short sVar26;
  uchar uVar27;
  int numberToRespond;
  RGE_Static_Object *targetObj;
  ulong entryTime;
  RGE_Static_Object *callerObject;
  XYPoint attackPoint;
  XYZPoint point;
  XYZPoint point_fffffff0;
  
  attackPoint.x =
       (int)RGE_Game_World::object((RGE_Game_World *)this->md->aiPlayer->_padding_,param_1);
  if (((param_3 != 0x72) && (param_3 != 0x74)) &&
     ((RGE_Static_Object *)attackPoint.x == (RGE_Static_Object *)0x0)) {
    return;
  }
  pRVar5 = (RGE_Static_Object *)debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x1904);
  if ((param_3 == 0x72) || (param_3 == 0x74)) {
    if (param_3 == 0x72) {
      pOVar21 = TribeInformationAIModule::artifactToCapture(&this->md->informationAI,-1);
    }
    else {
      pOVar21 = TribeInformationAIModule::ruinToCapture(&this->md->informationAI,-1);
    }
    if (pOVar21 == (ObjectMemory *)0x0) {
      return;
    }
    iVar8 = numberSoldiersWithPriority(this,100,-1,1);
    param_3 = 3;
    if (iVar8 < 4) {
      param_3 = iVar8;
    }
    iVar8 = 0;
    param_1 = 0;
    if ((this->workingArea).numberValue < 1) {
      return;
    }
    do {
      if (param_3 <= param_1) {
        return;
      }
      if ((this->workingArea).maximumSizeValue + -1 < iVar8) {
        piVar16 = (int *)operator_new(iVar8 * 4 + 4);
        if (piVar16 != (int *)0x0) {
          iVar9 = 0;
          if (0 < (this->workingArea).maximumSizeValue) {
            do {
              if (iVar8 + 1 <= iVar9) break;
              iVar17 = iVar9 + 1;
              piVar16[iVar9] = (this->workingArea).value[iVar9];
              iVar9 = iVar17;
            } while (iVar17 < (this->workingArea).maximumSizeValue);
          }
          operator_delete((this->workingArea).value);
          (this->workingArea).value = piVar16;
          (this->workingArea).maximumSizeValue = iVar8 + 1;
        }
      }
      pRVar5 = RGE_Game_World::object
                         ((RGE_Game_World *)this->md->aiPlayer->_padding_,
                          (this->workingArea).value[iVar8]);
      if (((pRVar5 != (RGE_Static_Object *)0x0) &&
          (pUVar10 = RGE_Static_Object::unitAI(pRVar5), pUVar10 != (UnitAIModule *)0x0)) &&
         (iVar9 = (**(code **)(pRVar5->_padding_ + 0x194))
                            (pOVar21->id,0x40000000,0,1,0xffffffff,0xffffffff), iVar9 != 0)) {
        if ((this->workingArea).maximumSizeValue + -1 < iVar8) {
          piVar16 = (int *)operator_new(iVar8 * 4 + 4);
          if (piVar16 != (int *)0x0) {
            iVar9 = 0;
            if (0 < (this->workingArea).maximumSizeValue) {
              do {
                if (iVar8 + 1 <= iVar9) break;
                iVar17 = iVar9 + 1;
                piVar16[iVar9] = (this->workingArea).value[iVar9];
                iVar9 = iVar17;
              } while (iVar17 < (this->workingArea).maximumSizeValue);
            }
            operator_delete((this->workingArea).value);
            (this->workingArea).value = piVar16;
            (this->workingArea).maximumSizeValue = iVar8 + 1;
          }
        }
        iVar9 = taskDefender(this,(this->workingArea).value[iVar8],pOVar21->id,2.0,100);
        if (iVar9 == 1) {
          if ((this->workingArea).maximumSizeValue + -1 < iVar8) {
            piVar16 = (int *)operator_new(iVar8 * 4 + 4);
            if (piVar16 != (int *)0x0) {
              iVar9 = 0;
              if (0 < (this->workingArea).maximumSizeValue) {
                do {
                  if (iVar8 + 1 <= iVar9) break;
                  iVar17 = iVar9 + 1;
                  piVar16[iVar9] = (this->workingArea).value[iVar9];
                  iVar9 = iVar17;
                } while (iVar17 < (this->workingArea).maximumSizeValue);
              }
              operator_delete((this->workingArea).value);
              (this->workingArea).value = piVar16;
              (this->workingArea).maximumSizeValue = iVar8 + 1;
            }
          }
          removeFromGroup(this,(this->workingArea).value[iVar8]);
          param_1 = param_1 + 1;
        }
      }
      iVar8 = iVar8 + 1;
      if ((this->workingArea).numberValue <= iVar8) {
        return;
      }
    } while( true );
  }
  if (param_3 != 0x201) {
    return;
  }
  pRVar6 = RGE_Game_World::object((RGE_Game_World *)this->md->aiPlayer->_padding_,param_4);
  if (pRVar6 == (RGE_Static_Object *)0x0) {
    return;
  }
  if (pRVar6->owner->id == *(short *)(this->md->_padding_ + 0x4a)) {
    return;
  }
  pRVar7 = RGE_Game_World::object((RGE_Game_World *)this->md->aiPlayer->_padding_,param_1);
  if (pRVar7 == (RGE_Static_Object *)0x0) {
    return;
  }
  if ((pRVar6->owner->id == 0) &&
     (((this->zoomingToNextAge == 0 ||
       ((sVar26 = pRVar6->master_obj->id, sVar26 != 0x7e && (sVar26 != 0x59)))) &&
      (iVar8 = dealWithGAIAAttacker(this,pRVar6,pRVar7), iVar8 == 1)))) {
    return;
  }
  if (pRVar6->owner->id != 0) {
    iVar8 = (this->civilians).numberValue;
    iVar9 = 0;
    if (0 < iVar8) {
      do {
        if ((this->civilians).maximumSizeValue <= iVar9) break;
        if ((this->civilians).value[iVar9] == param_1) {
          iVar8 = (this->civilianExplorers).numberValue;
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
        iVar8 = RGE_Game_World::difficultyLevel(*(RGE_Game_World **)(this->md->_padding_ + 0x3c));
        if (iVar8 == 3) {
          this->sn[0x68] = this->sn[0x68] + -2;
        }
        else {
          iVar8 = RGE_Game_World::difficultyLevel(*(RGE_Game_World **)(this->md->_padding_ + 0x3c));
          if (iVar8 != 4) goto LAB_004f6466;
          this->sn[0x68] = this->sn[0x68] + -1;
        }
        goto LAB_004f6479;
      }
    }
  }
  goto LAB_004f6488;
  while( true ) {
    if ((this->civilianExplorers).value[iVar9] == param_1) goto LAB_004f63ff;
    iVar9 = iVar9 + 1;
    if (iVar8 <= iVar9) break;
LAB_004f72e6:
    if ((this->civilianExplorers).maximumSizeValue <= iVar9) break;
  }
LAB_004f72fe:
  iVar8 = RGE_Game_World::difficultyLevel(*(RGE_Game_World **)(this->md->_padding_ + 0x3c));
  if (iVar8 == 3) {
    this->sn[0x68] = this->sn[0x68] + -2;
  }
  else {
    iVar8 = RGE_Game_World::difficultyLevel(*(RGE_Game_World **)(this->md->_padding_ + 0x3c));
    if (iVar8 == 4) {
      this->sn[0x68] = this->sn[0x68] + -1;
    }
    else {
LAB_004f6466:
      enableAttack(&this->md->tacticalAI,3);
    }
  }
LAB_004f6479:
  checkForAttackResponseBuildInsertions(this,(int)pRVar6->owner->id);
LAB_004f6488:
  sVar26 = pRVar6->owner->id;
  this->hitsByPlayer[sVar26] = this->hitsByPlayer[sVar26] + 1;
  iVar9 = RGE_Player::computerPlayer(pRVar6->owner);
  iVar8 = *(int *)this->md->_padding_;
  if (iVar9 == 0) {
    iVar8 = (**(code **)(iVar8 + 0x1c))();
    if (((iVar8 == 1) &&
        (iVar8 = (int)pRVar6->owner->id, this->sn[0xdd] <= this->hitsByPlayer[iVar8])) &&
       (this->sn[0xd7] == 1)) {
LAB_004f657c:
      DiplomacyAIModule::setChangeable(&this->md->diplomacyAI,iVar8,'\x01');
      DiplomacyAIModule::setStance(&this->md->diplomacyAI,(int)pRVar6->owner->id,0,100);
      DiplomacyAIModule::setRelation(&this->md->diplomacyAI,(int)pRVar6->owner->id,3);
      DiplomacyAIModule::setChangeable(&this->md->diplomacyAI,(int)pRVar6->owner->id,'\0');
    }
    else {
      DiplomacyAIModule::changeStance
                (&this->md->diplomacyAI,(int)pRVar6->owner->id,2,this->sn[0xb2]);
      DiplomacyAIModule::changeStance
                (&this->md->diplomacyAI,(int)pRVar6->owner->id,0,this->sn[0xb2]);
    }
  }
  else {
    iVar8 = (**(code **)(iVar8 + 0x1c))((int)pRVar6->owner->id);
    if ((iVar8 == 1) &&
       (iVar8 = this->md->_padding_,
       iVar8 = (**(code **)(**(int **)(*(int *)(*(int *)(iVar8 + 0x3c) + 0x40) +
                                      pRVar6->owner->id * 4) + 0x18))((int)*(short *)(iVar8 + 0x4a))
       , iVar8 == 1)) {
      iVar8 = (int)pRVar6->owner->id;
      goto LAB_004f657c;
    }
  }
  if (((0 < this->sn[0x7c]) && (this->sn[0x80] == (int)pRVar6->owner->id)) && (this->sn[0x85] == 1))
{
    TribeMainDecisionAIModule::revokeTributeAlliance(this->md);
  }
  pTVar1 = this->md;
  iVar9 = -1;
  iVar8 = pTVar1->_padding_;
  uVar20 = *(ulong *)(*(int *)(iVar8 + 0x3c) + 4);
  uVar25 = *(uchar *)(iVar8 + 0x4a);
  uVar27 = '\0';
  sVar26 = 0;
  uVar24 = (uchar)pRVar6->owner->id;
  uVar3 = __ftol();
  uVar4 = __ftol();
  TribeInformationAIModule::storeAttackMemory
            (&pTVar1->informationAI,'\0',uVar4,uVar3,uVar24,uVar25,sVar26,uVar27,uVar20,iVar9);
  uVar20 = this->lastAttackResponseTime;
  iVar8 = *(int *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
  if ((uVar20 != 0) && (uVar11 = attackLimiterTime(this,0x30), (iVar8 - uVar20) / 1000 < uVar11)) {
    return;
  }
  attackPoint.x = __ftol();
  attackPoint.y = __ftol();
  iVar8 = TribeInformationAIModule::isBoat(&this->md->informationAI,pRVar6);
  if (iVar8 == 1) {
    iVar8 = this->sn[0x14];
LAB_004f66f3:
                    /* language.dll match for 0x67: "Comic Sans MS" */
    this_00 = readyAndIdleGroup(this,0x67,iVar8,&attackPoint);
    if (this_00 != (TacticalAIGroup *)0x0) goto LAB_004f6706;
  }
  else {
    this_00 = readyAndIdleGroup(this,100,this->sn[0x14],&attackPoint);
    if (this_00 == (TacticalAIGroup *)0x0) {
      iVar8 = this->sn[0x14];
      goto LAB_004f66f3;
    }
LAB_004f6706:
    iVar8 = TacticalAIGroup::commander(this_00);
    pRVar12 = RGE_Game_World::object(*(RGE_Game_World **)(this->md->_padding_ + 0x3c),iVar8);
    if (pRVar12 != (RGE_Static_Object *)0x0) {
      uVar13 = __ftol();
      uVar14 = __ftol();
      uVar15 = __ftol();
      iVar8 = pRVar12->_padding_;
      fVar22 = (float10)(**(code **)(iVar8 + 0x10c))(pRVar6->id,0,1,0xffffffff,0xffffffff);
      iVar8 = (**(code **)(iVar8 + 0x198))(uVar13,uVar14,uVar15,(float)fVar22);
      if (iVar8 == 1) {
        TacticalAIGroup::setTarget(this_00,(int)pRVar7);
        TacticalAIGroup::setTargetType(this_00,(int)pRVar6->master_obj->id);
        TacticalAIGroup::setTargetLocation(this_00,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
        TacticalAIGroup::setAction(this_00,2);
        TacticalAIGroup::task(this_00,this,this->md,2,1,0);
        this->lastAttackResponseTime = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
        if (this->sn[0x47] != 1) {
          return;
        }
        this->lastGroupAttackTime = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
        return;
      }
    }
  }
  pRVar7 = MainDecisionAIModule::object
                     ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  iVar8 = 1000;
  if (pRVar7 != (RGE_Static_Object *)0x0) {
    iVar8 = __ftol();
  }
  if (iVar8 < 0x14) {
    iVar8 = numberWarshipsWithPriority(this,100,-1);
    iVar9 = numberSoldiersWithPriority(this,100,-1,0);
    numberToRespond = iVar8 + iVar9;
    uVar2 = *(uint *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
    if ((((numberToRespond == 0) &&
         (iVar8 = TribeInformationAIModule::isBoat(&this->md->informationAI,pRVar6), iVar8 == 0)) &&
        (this->sn[0xe1] == 1)) && (uVar2 / 1000 < (uint)this->sn[0x68])) {
      iVar8 = 0;
      if (0 < (this->civilians).numberValue) {
        do {
          if ((this->civilians).maximumSizeValue + -1 < iVar8) {
            piVar16 = (int *)operator_new(iVar8 * 4 + 4);
            if (piVar16 != (int *)0x0) {
              iVar9 = 0;
              if (0 < (this->civilians).maximumSizeValue) {
                do {
                  if (iVar8 + 1 <= iVar9) break;
                  iVar17 = iVar9 + 1;
                  piVar16[iVar9] = (this->civilians).value[iVar9];
                  iVar9 = iVar17;
                } while (iVar17 < (this->civilians).maximumSizeValue);
              }
              operator_delete((this->civilians).value);
              (this->civilians).value = piVar16;
              (this->civilians).maximumSizeValue = iVar8 + 1;
            }
          }
          iVar9 = (this->workingArea).numberValue;
          iVar17 = (this->civilians).value[iVar8];
          iVar18 = 0;
          if (0 < iVar9) {
            do {
              if ((this->workingArea).maximumSizeValue <= iVar18) break;
              if ((this->workingArea).value[iVar18] == iVar17) goto LAB_004f6a3f;
              iVar18 = iVar18 + 1;
            } while (iVar18 < iVar9);
          }
          if ((this->workingArea).maximumSizeValue + -1 < iVar9) {
            iVar9 = iVar9 + 1;
            piVar16 = (int *)operator_new(iVar9 * 4);
            if (piVar16 != (int *)0x0) {
              iVar18 = 0;
              if (0 < (this->workingArea).maximumSizeValue) {
                do {
                  if (iVar9 <= iVar18) break;
                  iVar19 = iVar18 + 1;
                  piVar16[iVar18] = (this->workingArea).value[iVar18];
                  iVar18 = iVar19;
                } while (iVar19 < (this->workingArea).maximumSizeValue);
              }
              operator_delete((this->workingArea).value);
              (this->workingArea).value = piVar16;
              (this->workingArea).maximumSizeValue = iVar9;
            }
          }
          (this->workingArea).value[(this->workingArea).numberValue] = iVar17;
          (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004f6a3f:
          iVar8 = iVar8 + 1;
        } while (iVar8 < (this->civilians).numberValue);
      }
      numberToRespond = (this->civilians).numberValue;
    }
    iVar8 = __ftol();
  }
  else {
    iVar8 = TribeInformationAIModule::isBoat(&this->md->informationAI,pRVar6);
    if (iVar8 == 1) {
      iVar8 = numberWarshipsWithPriority(this,this->sn[0x14],-1);
    }
    else {
      iVar8 = numberWarshipsWithPriority(this,this->sn[0x14],-1);
      iVar9 = numberSoldiersWithPriority(this,this->sn[0x14],-1,0);
      iVar8 = iVar8 + iVar9;
    }
    numberToRespond = (this->sn[0x13] * iVar8) / 100;
    if (pRVar7 != (RGE_Static_Object *)0x0) {
      iVar8 = __ftol();
      iVar9 = __ftol();
      sVar26 = pRVar6->owner->id;
      goto LAB_004f6b18;
    }
    iVar8 = __ftol();
  }
  iVar9 = __ftol();
  sVar26 = pRVar6->owner->id;
LAB_004f6b18:
  checkForCoopAttack(this,(int)sVar26,iVar9,iVar8);
  param_2 = 0;
  param_3 = 0;
  if (0 < (this->workingArea).numberValue) {
    while ((param_2 < numberToRespond &&
           ((param_3 < 2 ||
            (uVar20 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x1a54),
            uVar20 - entryTime < 0xb))))) {
      if ((this->workingArea).maximumSizeValue + -1 < param_3) {
        piVar16 = (int *)operator_new(param_3 * 4 + 4);
        if (piVar16 != (int *)0x0) {
          iVar8 = 0;
          if (0 < (this->workingArea).maximumSizeValue) {
            do {
              if (param_3 + 1 <= iVar8) break;
              iVar9 = iVar8 + 1;
              piVar16[iVar8] = (this->workingArea).value[iVar8];
              iVar8 = iVar9;
            } while (iVar9 < (this->workingArea).maximumSizeValue);
          }
          operator_delete((this->workingArea).value);
          (this->workingArea).value = piVar16;
          (this->workingArea).maximumSizeValue = param_3 + 1;
        }
      }
      pRVar7 = RGE_Game_World::object
                         ((RGE_Game_World *)this->md->aiPlayer->_padding_,
                          (this->workingArea).value[param_3]);
      if ((pRVar7 != (RGE_Static_Object *)0x0) &&
         (pUVar10 = RGE_Static_Object::unitAI(pRVar7), pUVar10 != (UnitAIModule *)0x0)) {
        pUVar10 = RGE_Static_Object::unitAI(pRVar7);
        iVar8 = UnitAIModule::currentAction(pUVar10);
        if (iVar8 == 600) {
          pUVar10 = RGE_Static_Object::unitAI(pRVar7);
          iVar8 = UnitAIModule::currentTarget(pUVar10);
          if (iVar8 == -1) goto LAB_004f6d07;
          pUVar10 = RGE_Static_Object::unitAI(pRVar7);
          iVar8 = UnitAIModule::currentTarget(pUVar10);
          if (iVar8 != pRVar6->id) {
            pUVar10 = RGE_Static_Object::unitAI(pRVar7);
            iVar8 = UnitAIModule::currentTarget(pUVar10);
            pRVar12 = RGE_Game_World::object(*(RGE_Game_World **)(this->md->_padding_ + 0x3c),iVar8)
            ;
            if (pRVar12 != (RGE_Static_Object *)0x0) {
              if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                 (piVar16 = (int *)operator_new(4), piVar16 != (int *)0x0)) {
                iVar8 = 0;
                if (0 < (this->playersToAttack).maximumSizeValue) {
                  do {
                    if (0 < iVar8) break;
                    iVar9 = iVar8 + 1;
                    piVar16[iVar8] = (this->playersToAttack).value[iVar8];
                    iVar8 = iVar9;
                  } while (iVar9 < (this->playersToAttack).maximumSizeValue);
                }
                operator_delete((this->playersToAttack).value);
                (this->playersToAttack).value = piVar16;
                (this->playersToAttack).maximumSizeValue = 1;
              }
              if ((int)pRVar12->owner->id == *(this->playersToAttack).value) goto LAB_004f7055;
            }
            goto LAB_004f6d07;
          }
LAB_004f7051:
          param_2 = param_2 + 1;
        }
        else {
LAB_004f6d07:
          if (((this->workingArea).maximumSizeValue + -1 < param_3) &&
             (piVar16 = (int *)operator_new(param_3 * 4 + 4), piVar16 != (int *)0x0)) {
            iVar8 = 0;
            if (0 < (this->workingArea).maximumSizeValue) {
              do {
                if (param_3 + 1 <= iVar8) break;
                iVar9 = iVar8 + 1;
                piVar16[iVar8] = (this->workingArea).value[iVar8];
                iVar8 = iVar9;
              } while (iVar9 < (this->workingArea).maximumSizeValue);
            }
            operator_delete((this->workingArea).value);
            (this->workingArea).value = piVar16;
            (this->workingArea).maximumSizeValue = param_3 + 1;
          }
          if ((this->workingArea).value[param_3] == unaff_retaddr) {
            pUVar10 = RGE_Static_Object::unitAI(pRVar7);
            iVar8 = UnitAIModule::currentOrderPriority(pUVar10);
            if (iVar8 != 100) {
              uVar13 = __ftol();
              uVar14 = __ftol();
              uVar15 = __ftol();
              iVar8 = pRVar7->_padding_;
              fVar22 = (float10)(**(code **)(iVar8 + 0x10c))(pRVar6->id,0,1,0xffffffff,0xffffffff);
              iVar8 = (**(code **)(iVar8 + 0x198))(uVar13,uVar14,uVar15,(float)fVar22);
              if (iVar8 != 0) {
                if ((this->workingArea).maximumSizeValue + -1 < param_3) {
                  piVar16 = (int *)operator_new(param_3 * 4 + 4);
                  if (piVar16 != (int *)0x0) {
                    iVar8 = 0;
                    if (0 < (this->workingArea).maximumSizeValue) {
                      do {
                        if (param_3 + 1 <= iVar8) break;
                        iVar9 = iVar8 + 1;
                        piVar16[iVar8] = (this->workingArea).value[iVar8];
                        iVar8 = iVar9;
                      } while (iVar9 < (this->workingArea).maximumSizeValue);
                    }
                    operator_delete((this->workingArea).value);
                    (this->workingArea).value = piVar16;
                    (this->workingArea).maximumSizeValue = param_3 + 1;
                  }
                }
                iVar8 = taskAttacker(this,(this->workingArea).value[param_3],pRVar6->world_x,
                                     pRVar6->world_y,pRVar6->id,(int)pRVar6->owner->id,
                                     (Waypoint *)0x0,0,-1,0);
                if (iVar8 == 1) {
                  this->lastAttackResponseTime =
                       *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
                  if (this->sn[0x47] == 1) {
                    this->lastGroupAttackTime = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4)
                    ;
                  }
                  goto LAB_004f7051;
                }
              }
            }
          }
          else {
            fVar23 = RGE_Static_Object::distance_to_object(pRVar5,pRVar7);
            iVar8 = calculatePriority(this,fVar23);
            if (fVar23 < (float)this->sn[0x14]) {
              pUVar10 = RGE_Static_Object::unitAI(pRVar7);
              iVar9 = UnitAIModule::currentOrderPriority(pUVar10);
              if ((iVar9 < iVar8) && (0 < iVar8)) {
                uVar13 = __ftol();
                uVar14 = __ftol();
                uVar15 = __ftol();
                iVar8 = pRVar7->_padding_;
                fVar22 = (float10)(**(code **)(iVar8 + 0x10c))(pRVar6->id,0,1,0xffffffff,0xffffffff)
                ;
                iVar8 = (**(code **)(iVar8 + 0x198))(uVar13,uVar14,uVar15,(float)fVar22);
                if (iVar8 != 0) {
                  if ((this->workingArea).maximumSizeValue + -1 < param_3) {
                    piVar16 = (int *)operator_new(param_3 * 4 + 4);
                    if (piVar16 != (int *)0x0) {
                      iVar8 = 0;
                      if (0 < (this->workingArea).maximumSizeValue) {
                        do {
                          if (param_3 + 1 <= iVar8) break;
                          iVar9 = iVar8 + 1;
                          piVar16[iVar8] = (this->workingArea).value[iVar8];
                          iVar8 = iVar9;
                        } while (iVar9 < (this->workingArea).maximumSizeValue);
                      }
                      operator_delete((this->workingArea).value);
                      (this->workingArea).value = piVar16;
                      (this->workingArea).maximumSizeValue = param_3 + 1;
                    }
                  }
                  iVar8 = taskAttacker(this,(this->workingArea).value[param_3],pRVar6->world_x,
                                       pRVar6->world_y,pRVar6->id,(int)pRVar6->owner->id,
                                       (Waypoint *)0x0,0,-1,0);
                  if (iVar8 == 1) goto LAB_004f7051;
                }
              }
            }
          }
        }
      }
LAB_004f7055:
      param_3 = param_3 + 1;
      if ((this->workingArea).numberValue <= param_3) {
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: numberIdleSoldiers
// Address: 004f7350
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall TribeTacticalAIModule::numberIdleSoldiers(void) */

int __thiscall TribeTacticalAIModule::numberIdleSoldiers(TribeTacticalAIModule *this)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int count;
  int local_c;
  int i;
  int local_4;
  
  local_c = 0;
  local_4 = 0;
  (this->workingArea).numberValue = 0;
  if (0 < (this->soldiers).numberValue) {
    do {
      if ((this->soldiers).maximumSizeValue + -1 < local_4) {
        piVar1 = (int *)operator_new(local_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->soldiers).maximumSizeValue) {
            do {
              if (local_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->soldiers).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->soldiers).maximumSizeValue);
          }
          operator_delete((this->soldiers).value);
          (this->soldiers).value = piVar1;
          (this->soldiers).maximumSizeValue = local_4 + 1;
        }
      }
      this_00 = RGE_Game_World::object
                          ((RGE_Game_World *)this->md->aiPlayer->_padding_,
                           (this->soldiers).value[local_4]);
      if ((this_00 != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this_00), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 == -1) {
          if ((this->soldiers).maximumSizeValue + -1 < local_4) {
            piVar1 = (int *)operator_new(local_4 * 4 + 4);
            if (piVar1 != (int *)0x0) {
              iVar4 = 0;
              if (0 < (this->soldiers).maximumSizeValue) {
                do {
                  if (local_4 + 1 <= iVar4) break;
                  iVar2 = iVar4 + 1;
                  piVar1[iVar4] = (this->soldiers).value[iVar4];
                  iVar4 = iVar2;
                } while (iVar2 < (this->soldiers).maximumSizeValue);
              }
              operator_delete((this->soldiers).value);
              (this->soldiers).value = piVar1;
              (this->soldiers).maximumSizeValue = local_4 + 1;
            }
          }
          iVar5 = 0;
          iVar2 = (this->soldiers).value[local_4];
          iVar4 = (this->workingArea).numberValue;
          if (0 < iVar4) {
            do {
              if ((this->workingArea).maximumSizeValue <= iVar5) break;
              if ((this->workingArea).value[iVar5] == iVar2) goto LAB_004f755b;
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar4);
          }
          if ((this->workingArea).maximumSizeValue + -1 < iVar4) {
            iVar4 = iVar4 + 1;
            piVar1 = (int *)operator_new(iVar4 * 4);
            if (piVar1 != (int *)0x0) {
              iVar5 = 0;
              if (0 < (this->workingArea).maximumSizeValue) {
                do {
                  if (iVar4 <= iVar5) break;
                  iVar6 = iVar5 + 1;
                  piVar1[iVar5] = (this->workingArea).value[iVar5];
                  iVar5 = iVar6;
                } while (iVar6 < (this->workingArea).maximumSizeValue);
              }
              operator_delete((this->workingArea).value);
              (this->workingArea).value = piVar1;
              (this->workingArea).maximumSizeValue = iVar4;
            }
          }
          (this->workingArea).value[(this->workingArea).numberValue] = iVar2;
          (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004f755b:
          local_c = local_c + 1;
        }
      }
      local_4 = local_4 + 1;
    } while (local_4 < (this->soldiers).numberValue);
  }
  return local_c;
}

// --------------------------------------------------

// Function: numberSoldiersWithPriority
// Address: 004f7590
/* public: int __thiscall TribeTacticalAIModule::numberSoldiersWithPriority(int,int,int) */

int __thiscall
TribeTacticalAIModule::numberSoldiersWithPriority
          (TribeTacticalAIModule *this,int param_1,int param_2,int param_3)
{
  ManagedArray<int> *this_00;
  ManagedArray<int> *this_01;
  RGE_Static_Object *this_02;
  UnitAIModule *pUVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int count;
  int local_8;
  int local_4;
  
  local_8 = 0;
  if (param_3 == 1) {
    (this->workingArea).numberValue = 0;
  }
  param_3 = 0;
  if (0 < (this->soldiers).numberValue) {
    this_00 = &this->soldiers;
    do {
      if ((this->soldiers).maximumSizeValue + -1 < param_3) {
        ManagedArray<int>::resize(this_00,param_3 + 1);
      }
      this_02 = RGE_Game_World::object
                          ((RGE_Game_World *)this->md->aiPlayer->_padding_,this_00->value[param_3]);
      if ((this_02 != (RGE_Static_Object *)0x0) &&
         (pUVar1 = RGE_Static_Object::unitAI(this_02), pUVar1 != (UnitAIModule *)0x0)) {
        if ((this->soldiers).maximumSizeValue + -1 < param_3) {
          ManagedArray<int>::resize(this_00,param_3 + 1);
        }
        iVar3 = (this->unitsTaskedThisUpdate).numberValue;
        iVar2 = 0;
        if (0 < iVar3) {
          do {
            if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
            if ((this->unitsTaskedThisUpdate).value[iVar2] == this_00->value[param_3])
            goto LAB_004f7778;
            iVar2 = iVar2 + 1;
          } while (iVar2 < iVar3);
        }
        if (param_2 < 0) {
          pUVar1 = RGE_Static_Object::unitAI(this_02);
          iVar3 = UnitAIModule::currentAction(pUVar1);
          if (iVar3 != -1) {
            pUVar1 = RGE_Static_Object::unitAI(this_02);
            iVar3 = UnitAIModule::currentOrderPriority(pUVar1);
            if (param_1 <= iVar3) goto LAB_004f7778;
          }
          if ((this->soldiers).maximumSizeValue + -1 < param_3) {
            ManagedArray<int>::resize(this_00,param_3 + 1);
          }
          iVar3 = (this->workingArea).numberValue;
          iVar2 = this_00->value[param_3];
          iVar4 = 0;
          if (0 < iVar3) {
            do {
              if ((this->workingArea).maximumSizeValue <= iVar4) break;
              if ((this->workingArea).value[iVar4] == iVar2) goto LAB_004f7770;
              iVar4 = iVar4 + 1;
            } while (iVar4 < iVar3);
          }
LAB_004f7750:
          if ((this->workingArea).maximumSizeValue + -1 < iVar3) {
            ManagedArray<int>::resize(&this->workingArea,iVar3 + 1);
          }
          (this->workingArea).value[(this->workingArea).numberValue] = iVar2;
          (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004f7770:
          local_8 = local_8 + 1;
        }
        else if (param_2 < 1) {
          pUVar1 = RGE_Static_Object::unitAI(this_02);
          iVar3 = UnitAIModule::currentAction(pUVar1);
          if (iVar3 != -1) {
            pUVar1 = RGE_Static_Object::unitAI(this_02);
            iVar3 = UnitAIModule::currentOrderPriority(pUVar1);
            if (iVar3 == param_1) {
              if ((this->soldiers).maximumSizeValue + -1 < param_3) {
                piVar5 = (int *)operator_new(param_3 * 4 + 4);
                if (piVar5 != (int *)0x0) {
                  iVar3 = 0;
                  if (0 < (this->soldiers).maximumSizeValue) {
                    do {
                      if (param_3 + 1 <= iVar3) break;
                      iVar2 = iVar3 + 1;
                      piVar5[iVar3] = this_00->value[iVar3];
                      iVar3 = iVar2;
                    } while (iVar2 < (this->soldiers).maximumSizeValue);
                  }
                  operator_delete(this_00->value);
                  this_00->value = piVar5;
                  (this->soldiers).maximumSizeValue = param_3 + 1;
                }
              }
              this_01 = &this->workingArea;
              local_4 = this_00->value[param_3];
              iVar3 = ManagedArray<int>::contains(this_01,&local_4);
              if (iVar3 != 1) {
                iVar3 = (this->workingArea).numberValue;
                if ((this->workingArea).maximumSizeValue + -1 < iVar3) {
                  ManagedArray<int>::resize(this_01,iVar3 + 1);
                }
                this_01->value[(this->workingArea).numberValue] = local_4;
                (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
              }
              local_8 = local_8 + 1;
            }
          }
        }
        else {
          pUVar1 = RGE_Static_Object::unitAI(this_02);
          iVar3 = UnitAIModule::currentAction(pUVar1);
          if (iVar3 != -1) {
            pUVar1 = RGE_Static_Object::unitAI(this_02);
            iVar3 = UnitAIModule::currentOrderPriority(pUVar1);
            if (param_1 < iVar3) {
              if ((this->soldiers).maximumSizeValue + -1 < param_3) {
                ManagedArray<int>::resize(this_00,param_3 + 1);
              }
              iVar2 = this_00->value[param_3];
              iVar4 = 0;
              iVar3 = (this->workingArea).numberValue;
              if (0 < iVar3) {
                do {
                  if ((this->workingArea).maximumSizeValue <= iVar4) break;
                  if ((this->workingArea).value[iVar4] == iVar2) goto LAB_004f7770;
                  iVar4 = iVar4 + 1;
                } while (iVar4 < iVar3);
              }
              goto LAB_004f7750;
            }
          }
        }
      }
LAB_004f7778:
      param_3 = param_3 + 1;
    } while (param_3 < (this->soldiers).numberValue);
  }
  return local_8;
}

// --------------------------------------------------

// Function: numberWarshipsWithPriority
// Address: 004f7870
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall TribeTacticalAIModule::numberWarshipsWithPriority(int,int) */

int __thiscall
TribeTacticalAIModule::numberWarshipsWithPriority
          (TribeTacticalAIModule *this,int param_1,int param_2)
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
  TribeTacticalAIModule *pTVar10;
  TribeTacticalAIModule *pTVar11;
  int count;
  int i;
  int local_c;
  int local_8;
  TribeTacticalAIModule *local_4;
  
  (this->workingArea).numberValue = 0;
  i = 0;
  local_c = 0;
  local_4 = this;
  if (0 < (this->warBoats).numberValue) {
    pMVar1 = &this->warBoats;
    do {
      if ((this->warBoats).maximumSizeValue + -1 < local_c) {
        ManagedArray<int>::resize(pMVar1,local_c + 1);
      }
      local_8 = local_c * 4;
      pRVar4 = RGE_Game_World::object
                         ((RGE_Game_World *)this->md->aiPlayer->_padding_,pMVar1->value[local_c]);
      if ((pRVar4 != (RGE_Static_Object *)0x0) &&
         (pUVar5 = RGE_Static_Object::unitAI(pRVar4), pUVar5 != (UnitAIModule *)0x0)) {
        if ((this->warBoats).maximumSizeValue + -1 < local_c) {
          ManagedArray<int>::resize(pMVar1,local_c + 1);
        }
        iVar6 = 0;
        if (0 < (this->unitsTaskedThisUpdate).numberValue) {
          do {
            if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar6) break;
            if ((this->unitsTaskedThisUpdate).value[iVar6] == *(int *)((int)pMVar1->value + local_8)
               ) goto LAB_004f7aed;
            iVar6 = iVar6 + 1;
          } while (iVar6 < (this->unitsTaskedThisUpdate).numberValue);
        }
        if (param_2 < 0) {
          pUVar5 = RGE_Static_Object::unitAI(pRVar4);
          iVar6 = UnitAIModule::currentAction(pUVar5);
          if (iVar6 != -1) {
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            iVar6 = UnitAIModule::currentOrderPriority(pUVar5);
            if (param_1 <= iVar6) goto LAB_004f7aed;
          }
          if ((this->warBoats).maximumSizeValue + -1 < local_c) {
            ManagedArray<int>::resize(pMVar1,local_c + 1);
          }
          pMVar2 = &this->workingArea;
          local_8 = *(int *)((int)pMVar1->value + local_8);
          iVar6 = ManagedArray<int>::contains(pMVar2,&local_8);
          if (iVar6 != 1) {
            iVar6 = (this->workingArea).numberValue;
            if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
              ManagedArray<int>::resize(pMVar2,iVar6 + 1);
            }
            iVar6 = (this->workingArea).numberValue;
            piVar7 = pMVar2->value;
LAB_004f7add:
            piVar7[iVar6] = local_8;
LAB_004f7ae0:
            piVar7 = &(this->workingArea).numberValue;
            *piVar7 = *piVar7 + 1;
          }
LAB_004f7ae3:
          i = i + 1;
        }
        else if (param_2 < 1) {
          pUVar5 = RGE_Static_Object::unitAI(pRVar4);
          iVar6 = UnitAIModule::currentAction(pUVar5);
          if (iVar6 != -1) {
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            iVar6 = UnitAIModule::currentOrderPriority(pUVar5);
            if (iVar6 == param_1) {
              if ((this->warBoats).maximumSizeValue + -1 < local_c) {
                ManagedArray<int>::resize(pMVar1,local_c + 1);
              }
              pMVar2 = &this->workingArea;
              local_8 = *(int *)((int)pMVar1->value + local_8);
              iVar6 = ManagedArray<int>::contains(pMVar2,&local_8);
              if (iVar6 == 1) goto LAB_004f7ae3;
              iVar6 = (this->workingArea).numberValue;
              if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
                ManagedArray<int>::resize(pMVar2,iVar6 + 1);
              }
              iVar6 = (this->workingArea).numberValue;
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
            if (param_1 < iVar6) {
              if ((this->warBoats).maximumSizeValue + -1 < local_c) {
                ManagedArray<int>::resize(pMVar1,local_c + 1);
              }
              pMVar2 = &this->workingArea;
              local_8 = *(int *)((int)pMVar1->value + local_8);
              iVar6 = ManagedArray<int>::contains(pMVar2,&local_8);
              if (iVar6 == 1) goto LAB_004f7ae3;
              iVar6 = (this->workingArea).numberValue;
              if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
                ManagedArray<int>::resize(pMVar2,iVar6 + 1);
              }
              pMVar2->value[(this->workingArea).numberValue] = local_8;
              goto LAB_004f7ae0;
            }
          }
        }
      }
LAB_004f7aed:
      local_c = local_c + 1;
    } while (local_c < (this->warBoats).numberValue);
  }
  local_c = 0;
  if (0 < (this->soldiers).numberValue) {
    pMVar1 = &this->soldiers;
    pTVar11 = this;
    do {
      if ((this->soldiers).maximumSizeValue + -1 < local_c) {
        ManagedArray<int>::resize(pMVar1,local_c + 1);
      }
      pRVar4 = RGE_Game_World::object
                         ((RGE_Game_World *)pTVar11->md->aiPlayer->_padding_,pMVar1->value[local_c])
      ;
      if ((pRVar4 != (RGE_Static_Object *)0x0) &&
         (pUVar5 = RGE_Static_Object::unitAI(pRVar4), pUVar5 != (UnitAIModule *)0x0)) {
        if ((this->soldiers).maximumSizeValue + -1 < local_c) {
          ManagedArray<int>::resize(pMVar1,local_c + 1);
        }
        iVar6 = (pTVar11->unitsTaskedThisUpdate).numberValue;
        iVar8 = 0;
        pTVar10 = pTVar11;
        if (0 < iVar6) {
          do {
            pTVar11 = pTVar10;
            if ((pTVar10->unitsTaskedThisUpdate).maximumSizeValue <= iVar8) break;
            pTVar11 = local_4;
            if ((pTVar10->unitsTaskedThisUpdate).value[iVar8] == pMVar1->value[local_c])
            goto LAB_004f7d5f;
            iVar8 = iVar8 + 1;
            pTVar10 = local_4;
          } while (iVar8 < iVar6);
        }
        sVar3 = pRVar4->master_obj->object_group;
        if ((sVar3 == 0x12) || (sVar3 == 0xd)) {
          if (param_2 < 0) {
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            iVar6 = UnitAIModule::currentAction(pUVar5);
            if (iVar6 != -1) {
              pUVar5 = RGE_Static_Object::unitAI(pRVar4);
              iVar6 = UnitAIModule::currentOrderPriority(pUVar5);
              if (param_1 <= iVar6) goto LAB_004f7d5f;
            }
            if ((this->soldiers).maximumSizeValue + -1 < local_c) {
              ManagedArray<int>::resize(pMVar1,local_c + 1);
            }
            iVar6 = (pTVar11->workingArea).numberValue;
            iVar9 = 0;
            iVar8 = pMVar1->value[local_c];
            if (0 < iVar6) {
              do {
                if ((pTVar11->workingArea).maximumSizeValue <= iVar9) break;
                if ((pTVar11->workingArea).value[iVar9] == iVar8) goto LAB_004f7d55;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar6);
            }
LAB_004f7cbd:
            if ((pTVar11->workingArea).maximumSizeValue + -1 < iVar6) {
              ManagedArray<int>::resize(&pTVar11->workingArea,iVar6 + 1);
            }
            (pTVar11->workingArea).value[(pTVar11->workingArea).numberValue] = iVar8;
LAB_004f7d52:
            piVar7 = &(pTVar11->workingArea).numberValue;
            *piVar7 = *piVar7 + 1;
LAB_004f7d55:
            i = i + 1;
          }
          else if (param_2 < 1) {
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            iVar6 = UnitAIModule::currentAction(pUVar5);
            if (iVar6 != -1) {
              pUVar5 = RGE_Static_Object::unitAI(pRVar4);
              iVar6 = UnitAIModule::currentOrderPriority(pUVar5);
              if (iVar6 == param_1) {
                if ((this->soldiers).maximumSizeValue + -1 < local_c) {
                  ManagedArray<int>::resize(pMVar1,local_c + 1);
                }
                pMVar2 = &pTVar11->workingArea;
                local_8 = pMVar1->value[local_c];
                iVar6 = ManagedArray<int>::contains(pMVar2,&local_8);
                if (iVar6 != 1) {
                  iVar6 = (pTVar11->workingArea).numberValue;
                  if ((pTVar11->workingArea).maximumSizeValue + -1 < iVar6) {
                    ManagedArray<int>::resize(pMVar2,iVar6 + 1);
                  }
                  pMVar2->value[(pTVar11->workingArea).numberValue] = local_8;
                  goto LAB_004f7d52;
                }
                goto LAB_004f7d55;
              }
            }
          }
          else {
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            iVar6 = UnitAIModule::currentAction(pUVar5);
            if (iVar6 != -1) {
              pUVar5 = RGE_Static_Object::unitAI(pRVar4);
              iVar6 = UnitAIModule::currentOrderPriority(pUVar5);
              if (param_1 < iVar6) {
                if ((this->soldiers).maximumSizeValue + -1 < local_c) {
                  ManagedArray<int>::resize(pMVar1,local_c + 1);
                }
                iVar6 = (pTVar11->workingArea).numberValue;
                iVar9 = 0;
                iVar8 = pMVar1->value[local_c];
                if (0 < iVar6) {
                  do {
                    if ((pTVar11->workingArea).maximumSizeValue <= iVar9) break;
                    if ((pTVar11->workingArea).value[iVar9] == iVar8) goto LAB_004f7d55;
                    iVar9 = iVar9 + 1;
                  } while (iVar9 < iVar6);
                }
                goto LAB_004f7cbd;
              }
            }
          }
        }
      }
LAB_004f7d5f:
      local_c = local_c + 1;
    } while (local_c < (pTVar11->soldiers).numberValue);
  }
  return i;
}

// --------------------------------------------------

// Function: idleSoldier
// Address: 004f7d90
/* public: int __thiscall TribeTacticalAIModule::idleSoldier(void) */

int __thiscall TribeTacticalAIModule::idleSoldier(TribeTacticalAIModule *this)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if ((this->soldiers).numberValue < 1) {
    return -1;
  }
  do {
    if ((this->soldiers).maximumSizeValue + -1 < iVar5) {
      piVar1 = (int *)operator_new(iVar5 * 4 + 4);
      if (piVar1 != (int *)0x0) {
        iVar4 = 0;
        if (0 < (this->soldiers).maximumSizeValue) {
          do {
            if (iVar5 + 1 <= iVar4) break;
            iVar2 = iVar4 + 1;
            piVar1[iVar4] = (this->soldiers).value[iVar4];
            iVar4 = iVar2;
          } while (iVar2 < (this->soldiers).maximumSizeValue);
        }
        operator_delete((this->soldiers).value);
        (this->soldiers).value = piVar1;
        (this->soldiers).maximumSizeValue = iVar5 + 1;
      }
    }
    this_00 = RGE_Game_World::object
                        (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),
                         (this->soldiers).value[iVar5]);
    if (this_00 != (RGE_Static_Object *)0x0) {
      pUVar3 = RGE_Static_Object::unitAI(this_00);
      if (pUVar3 != (UnitAIModule *)0x0) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 == -1) {
          return this_00->id;
        }
      }
    }
    iVar5 = iVar5 + 1;
    if ((this->soldiers).numberValue <= iVar5) {
      return -1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: idleCivilian
// Address: 004f7e80
/* WARNING: Variable defined which should be unmapped: unitObj */
/* public: int __thiscall TribeTacticalAIModule::idleCivilian(int) */

int __thiscall TribeTacticalAIModule::idleCivilian(TribeTacticalAIModule *this,int param_1)
{
  undefined1 *puVar1;
  ManagedArray<int> *pMVar2;
  int iVar3;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  RGE_Static_Object *unitObj;
  RGE_Static_Object *unitObj_fffffff8;
  
  iVar7 = 0;
  if (0 < (this->civilians).numberValue) {
    pMVar2 = &this->civilians;
    do {
      if ((this->civilians).maximumSizeValue + -1 < iVar7) {
        ManagedArray<int>::resize(pMVar2,iVar7 + 1);
      }
      iVar5 = (this->unitsTaskedThisUpdate).numberValue;
      iVar3 = 0;
      if (0 < iVar5) {
        do {
          if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar3) break;
          if ((this->unitsTaskedThisUpdate).value[iVar3] == pMVar2->value[iVar7]) goto LAB_004f7fc0;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar5);
      }
      if ((this->civilians).maximumSizeValue + -1 < iVar7) {
        ManagedArray<int>::resize(pMVar2,iVar7 + 1);
      }
      this_00 = RGE_Game_World::object
                          (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),pMVar2->value[iVar7]);
      if ((this_00 != (RGE_Static_Object *)0x0) &&
         (pUVar4 = RGE_Static_Object::unitAI(this_00), pUVar4 != (UnitAIModule *)0x0)) {
        if ((this->civilians).maximumSizeValue + -1 < iVar7) {
          ManagedArray<int>::resize(pMVar2,iVar7 + 1);
        }
        iVar5 = isGatherer(this,pMVar2->value[iVar7]);
        if (iVar5 == 0) {
          if ((this->civilians).maximumSizeValue + -1 < iVar7) {
            ManagedArray<int>::resize(pMVar2,iVar7 + 1);
          }
          iVar5 = 0;
          if (0 < (this->civilianExplorers).numberValue) {
            do {
              if ((this->civilianExplorers).maximumSizeValue <= iVar5) break;
              if ((this->civilianExplorers).value[iVar5] == pMVar2->value[iVar7]) goto LAB_004f7fc0;
              iVar5 = iVar5 + 1;
            } while (iVar5 < (this->civilianExplorers).numberValue);
          }
          pUVar4 = RGE_Static_Object::unitAI(this_00);
          iVar5 = UnitAIModule::currentAction(pUVar4);
          if (iVar5 == -1) {
            pUVar4 = RGE_Static_Object::unitAI(this_00);
            iVar5 = UnitAIModule::currentOrder(pUVar4);
            if (iVar5 == -1) goto LAB_004f8180;
          }
        }
      }
LAB_004f7fc0:
      iVar7 = iVar7 + 1;
    } while (iVar7 < (this->civilians).numberValue);
  }
  unitObj_fffffff8 = (RGE_Static_Object *)0x0;
  if ((this->civilians).numberValue < 1) {
    return -1;
  }
  pMVar2 = &this->civilians;
  do {
    if ((this->civilians).maximumSizeValue + -1 < (int)unitObj_fffffff8) {
      ManagedArray<int>::resize(pMVar2,(int)((int)&unitObj_fffffff8->_padding_ + 1));
    }
    iVar7 = (this->unitsTaskedThisUpdate).numberValue;
    iVar5 = 0;
    if (0 < iVar7) {
      do {
        if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar5) break;
        if ((this->unitsTaskedThisUpdate).value[iVar5] == pMVar2->value[(int)unitObj_fffffff8])
        goto LAB_004f8160;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar7);
    }
    if ((this->civilians).maximumSizeValue + -1 < (int)unitObj_fffffff8) {
      ManagedArray<int>::resize(pMVar2,(int)((int)&unitObj_fffffff8->_padding_ + 1));
    }
    this_00 = RGE_Game_World::object
                        (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),
                         pMVar2->value[(int)unitObj_fffffff8]);
    if ((this_00 != (RGE_Static_Object *)0x0) &&
       (pUVar4 = RGE_Static_Object::unitAI(this_00), pUVar4 != (UnitAIModule *)0x0)) {
      if (param_1 != 0) {
        if (param_1 != 3) {
          if ((this->civilians).maximumSizeValue + -1 < (int)unitObj_fffffff8) {
            ManagedArray<int>::resize(pMVar2,(int)((int)&unitObj_fffffff8->_padding_ + 1));
          }
          iVar7 = isGatherer(this,pMVar2->value[(int)unitObj_fffffff8]);
          if (iVar7 != 0) goto LAB_004f8160;
        }
        if ((param_1 != 0) && (param_1 != 1)) {
          if ((this->civilians).maximumSizeValue + -1 < (int)unitObj_fffffff8) {
            puVar1 = (undefined1 *)((int)&unitObj_fffffff8->_padding_ + 1);
            piVar6 = (int *)operator_new((int)unitObj_fffffff8 * 4 + 4);
            if (piVar6 != (int *)0x0) {
              iVar7 = 0;
              if (0 < (this->civilians).maximumSizeValue) {
                do {
                  if ((int)puVar1 <= iVar7) break;
                  iVar5 = iVar7 + 1;
                  piVar6[iVar7] = pMVar2->value[iVar7];
                  iVar7 = iVar5;
                } while (iVar5 < (this->civilians).maximumSizeValue);
              }
              operator_delete(pMVar2->value);
              pMVar2->value = piVar6;
              (this->civilians).maximumSizeValue = (int)puVar1;
            }
          }
          iVar7 = (this->civilianExplorers).numberValue;
          iVar5 = 0;
          if (0 < iVar7) {
            do {
              if ((this->civilianExplorers).maximumSizeValue <= iVar5) break;
              if ((this->civilianExplorers).value[iVar5] == pMVar2->value[(int)unitObj_fffffff8])
              goto LAB_004f8160;
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar7);
          }
        }
      }
      pUVar4 = RGE_Static_Object::unitAI(this_00);
      iVar7 = UnitAIModule::currentAction(pUVar4);
      if (iVar7 == -1) {
        pUVar4 = RGE_Static_Object::unitAI(this_00);
        iVar7 = UnitAIModule::currentOrder(pUVar4);
        if (iVar7 == -1) {
LAB_004f8180:
          return this_00->id;
        }
      }
    }
LAB_004f8160:
    unitObj_fffffff8 = (RGE_Static_Object *)((int)&unitObj_fffffff8->_padding_ + 1);
    if ((this->civilians).numberValue <= (int)unitObj_fffffff8) {
      return -1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: idleCivilian
// Address: 004f81a0
/* WARNING: Variable defined which should be unmapped: bestUnitDistance */
/* public: int __thiscall TribeTacticalAIModule::idleCivilian(int,struct XYPoint &,int) */

int __thiscall
TribeTacticalAIModule::idleCivilian
          (TribeTacticalAIModule *this,int param_1,XYPoint *param_2,int param_3)
{
  ManagedArray<int> *pMVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  UnitAIModule *pUVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  RGE_Static_Object *pRVar8;
  float bestUnitDistance;
  RGE_Static_Object *unitObj;
  int bestUnitID;
  RGE_Static_Object *unitObj_fffffff8;
  
  iVar7 = 0;
  unitObj_fffffff8 = (RGE_Static_Object *)0xffffffff;
  unitObj = (RGE_Static_Object *)0x0;
  if (0 < (this->civilians).numberValue) {
    pMVar1 = &this->civilians;
    do {
      if ((this->civilians).maximumSizeValue + -1 < iVar7) {
        ManagedArray<int>::resize(pMVar1,iVar7 + 1);
      }
      iVar5 = (this->unitsTaskedThisUpdate).numberValue;
      iVar2 = 0;
      if (0 < iVar5) {
        do {
          if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
          if ((this->unitsTaskedThisUpdate).value[iVar2] == pMVar1->value[iVar7]) goto LAB_004f82f0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar5);
      }
      if ((this->civilians).maximumSizeValue + -1 < iVar7) {
        ManagedArray<int>::resize(pMVar1,iVar7 + 1);
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),pMVar1->value[iVar7]);
      if ((pRVar3 != (RGE_Static_Object *)0x0) &&
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 != (UnitAIModule *)0x0)) {
        if ((this->civilians).maximumSizeValue + -1 < iVar7) {
          ManagedArray<int>::resize(pMVar1,iVar7 + 1);
        }
        iVar5 = isGatherer(this,pMVar1->value[iVar7]);
        if (iVar5 == 0) {
          if ((this->civilians).maximumSizeValue + -1 < iVar7) {
            ManagedArray<int>::resize(pMVar1,iVar7 + 1);
          }
          iVar5 = 0;
          if (0 < (this->civilianExplorers).numberValue) {
            do {
              if ((this->civilianExplorers).maximumSizeValue <= iVar5) break;
              if ((this->civilianExplorers).value[iVar5] == pMVar1->value[iVar7]) goto LAB_004f82f0;
              iVar5 = iVar5 + 1;
            } while (iVar5 < (this->civilianExplorers).numberValue);
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
    } while (iVar7 < (this->civilians).numberValue);
  }
  bestUnitID = 0;
  if (0 < (this->civilians).numberValue) {
    pMVar1 = &this->civilians;
    do {
      if ((this->civilians).maximumSizeValue + -1 < bestUnitID) {
        ManagedArray<int>::resize(pMVar1,bestUnitID + 1);
      }
      iVar7 = (this->unitsTaskedThisUpdate).numberValue;
      iVar5 = 0;
      if (0 < iVar7) {
        do {
          if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar5) break;
          if ((this->unitsTaskedThisUpdate).value[iVar5] == pMVar1->value[bestUnitID])
          goto LAB_004f8542;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar7);
      }
      if (((this->civilians).maximumSizeValue + -1 < bestUnitID) &&
         (piVar6 = (int *)operator_new(bestUnitID * 4 + 4), piVar6 != (int *)0x0)) {
        iVar7 = 0;
        if (0 < (this->civilians).maximumSizeValue) {
          do {
            if (bestUnitID + 1 <= iVar7) break;
            iVar5 = iVar7 + 1;
            piVar6[iVar7] = pMVar1->value[iVar7];
            iVar7 = iVar5;
          } while (iVar5 < (this->civilians).maximumSizeValue);
        }
        operator_delete(pMVar1->value);
        pMVar1->value = piVar6;
        (this->civilians).maximumSizeValue = bestUnitID + 1;
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),pMVar1->value[bestUnitID]
                         );
      if ((pRVar3 != (RGE_Static_Object *)0x0) &&
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 != (UnitAIModule *)0x0)) {
        if (param_1 != 0) {
          if (param_1 != 3) {
            if ((this->civilians).maximumSizeValue + -1 < bestUnitID) {
              piVar6 = (int *)operator_new(bestUnitID * 4 + 4);
              if (piVar6 != (int *)0x0) {
                iVar7 = 0;
                if (0 < (this->civilians).maximumSizeValue) {
                  do {
                    if (bestUnitID + 1 <= iVar7) break;
                    iVar5 = iVar7 + 1;
                    piVar6[iVar7] = pMVar1->value[iVar7];
                    iVar7 = iVar5;
                  } while (iVar5 < (this->civilians).maximumSizeValue);
                }
                operator_delete(pMVar1->value);
                pMVar1->value = piVar6;
                (this->civilians).maximumSizeValue = bestUnitID + 1;
              }
            }
            iVar7 = isGatherer(this,pMVar1->value[bestUnitID]);
            if (iVar7 != 0) goto LAB_004f8542;
          }
          if ((param_1 != 0) && (param_1 != 1)) {
            if ((this->civilians).maximumSizeValue + -1 < bestUnitID) {
              ManagedArray<int>::resize(pMVar1,bestUnitID + 1);
            }
            iVar7 = 0;
            if (0 < (this->civilianExplorers).numberValue) {
              do {
                if ((this->civilianExplorers).maximumSizeValue <= iVar7) break;
                if ((this->civilianExplorers).value[iVar7] == pMVar1->value[bestUnitID])
                goto LAB_004f8542;
                iVar7 = iVar7 + 1;
              } while (iVar7 < (this->civilianExplorers).numberValue);
            }
          }
        }
        pUVar4 = RGE_Static_Object::unitAI(pRVar3);
        iVar7 = UnitAIModule::currentAction(pUVar4);
        if (iVar7 == -1) {
          pUVar4 = RGE_Static_Object::unitAI(pRVar3);
          iVar7 = UnitAIModule::currentOrder(pUVar4);
          if (iVar7 == -1) {
            pRVar8 = (RGE_Static_Object *)
                     RGE_Static_Object::distance_to_position
                               (pRVar3,(float)param_2->x,(float)param_2->y,pRVar3->world_z);
            if (unitObj_fffffff8 == (RGE_Static_Object *)0xffffffff) {
              unitObj_fffffff8 = (RGE_Static_Object *)pRVar3->id;
              unitObj = pRVar8;
            }
            else if (((param_3 == 1) && ((float)pRVar8 < (float)unitObj)) ||
                    ((param_3 == 0 && ((float)unitObj < (float)pRVar8)))) {
              unitObj_fffffff8 = (RGE_Static_Object *)pRVar3->id;
              unitObj = pRVar8;
            }
          }
        }
      }
LAB_004f8542:
      bestUnitID = bestUnitID + 1;
    } while (bestUnitID < (this->civilians).numberValue);
  }
  return (int)unitObj_fffffff8;
}

// --------------------------------------------------

// Function: civilian
// Address: 004f8570
/* WARNING: Variable defined which should be unmapped: bestUnitDistance */
/* public: int __thiscall TribeTacticalAIModule::civilian(struct XYPoint &,int,int,int,int,int) */

int __thiscall
TribeTacticalAIModule::civilian
          (TribeTacticalAIModule *this,XYPoint *param_1,int param_2,int param_3,int param_4,
          int param_5,int param_6)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float bestUnitDistance;
  int bestUnitID;
  long local_4;
  
  iVar5 = 0;
  local_4 = -1;
  bestUnitID = 0;
  if (0 < (this->civilians).numberValue) {
    do {
      if ((this->civilians).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->civilians).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->civilians).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->civilians).maximumSizeValue);
          }
          operator_delete((this->civilians).value);
          (this->civilians).value = piVar1;
          (this->civilians).maximumSizeValue = iVar5 + 1;
        }
      }
      iVar4 = (this->unitsTaskedThisUpdate).numberValue;
      iVar2 = 0;
      if (0 < iVar4) {
        do {
          if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
          if ((this->unitsTaskedThisUpdate).value[iVar2] == (this->civilians).value[iVar5])
          goto LAB_004f8790;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar4);
      }
      if ((this->civilians).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->civilians).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->civilians).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->civilians).maximumSizeValue);
          }
          operator_delete((this->civilians).value);
          (this->civilians).value = piVar1;
          (this->civilians).maximumSizeValue = iVar5 + 1;
        }
      }
      this_00 = RGE_Game_World::object
                          (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),
                           (this->civilians).value[iVar5]);
      if (((this_00 != (RGE_Static_Object *)0x0) &&
          (pUVar3 = RGE_Static_Object::unitAI(this_00), pUVar3 != (UnitAIModule *)0x0)) &&
         ((param_6 != 0 || (this_00->master_obj->id != 0x103)))) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentOrder(pUVar3);
        if (iVar4 != param_3) {
          pUVar3 = RGE_Static_Object::unitAI(this_00);
          iVar4 = UnitAIModule::currentOrder(pUVar3);
          if (iVar4 != param_4) {
            pUVar3 = RGE_Static_Object::unitAI(this_00);
            iVar4 = UnitAIModule::currentOrder(pUVar3);
            if (iVar4 != param_5) {
              fVar6 = RGE_Static_Object::distance_to_position
                                (this_00,(float)param_1->x,(float)param_1->y,this_00->world_z);
              if (local_4 == -1) {
                local_4 = this_00->id;
                bestUnitID = (int)fVar6;
              }
              else if (((param_2 == 1) && (fVar6 < (float)bestUnitID)) ||
                      ((param_2 == 0 && ((float)bestUnitID < fVar6)))) {
                local_4 = this_00->id;
                bestUnitID = (int)fVar6;
              }
            }
          }
        }
      }
LAB_004f8790:
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->civilians).numberValue);
  }
  return local_4;
}

// --------------------------------------------------

// Function: unit
// Address: 004f87b0
/* public: int __thiscall TribeTacticalAIModule::unit(int,int,int) */

int __thiscall
TribeTacticalAIModule::unit(TribeTacticalAIModule *this,int param_1,int param_2,int param_3)
{
  ManagedArray<int> *this_00;
  int *piVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  UnitAIModule *pUVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  if (0 < (this->civilians).numberValue) {
    this_00 = &this->civilians;
    do {
      if (((this->civilians).maximumSizeValue + -1 < iVar7) &&
         (piVar1 = (int *)operator_new(iVar7 * 4 + 4), piVar1 != (int *)0x0)) {
        iVar5 = 0;
        if (0 < (this->civilians).maximumSizeValue) {
          do {
            if (iVar7 + 1 <= iVar5) break;
            iVar2 = iVar5 + 1;
            piVar1[iVar5] = this_00->value[iVar5];
            iVar5 = iVar2;
          } while (iVar2 < (this->civilians).maximumSizeValue);
        }
        operator_delete(this_00->value);
        this_00->value = piVar1;
        (this->civilians).maximumSizeValue = iVar7 + 1;
      }
      pRVar3 = RGE_Game_World::object
                         ((RGE_Game_World *)this->md->aiPlayer->_padding_,this_00->value[iVar7]);
      if ((pRVar3 == (RGE_Static_Object *)0x0) &&
         (pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0),
         pUVar4 == (UnitAIModule *)0x0)) {
        if (param_1 != -1) {
          pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
          iVar5 = UnitAIModule::currentAction(pUVar4);
          if (iVar5 != param_1) goto LAB_004f88a1;
        }
        if (param_2 != -1) {
          pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
          iVar5 = UnitAIModule::currentTarget(pUVar4);
          if (iVar5 != param_2) goto LAB_004f88a1;
        }
        if (param_3 == -1) {
LAB_004f8bc0:
          if ((this->civilians).maximumSizeValue + -1 < iVar7) {
            ManagedArray<int>::resize(this_00,iVar7 + 1);
          }
          return this_00->value[iVar7];
        }
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
        iVar5 = UnitAIModule::currentTargetType(pUVar4);
        if (iVar5 == param_3) goto LAB_004f8bc0;
      }
LAB_004f88a1:
      iVar7 = iVar7 + 1;
    } while (iVar7 < (this->civilians).numberValue);
  }
  iVar7 = 0;
  if (0 < (this->soldiers).numberValue) {
    do {
      if ((this->soldiers).maximumSizeValue + -1 < iVar7) {
        piVar1 = (int *)operator_new(iVar7 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (this->soldiers).maximumSizeValue) {
            do {
              if (iVar7 + 1 <= iVar5) break;
              iVar2 = iVar5 + 1;
              piVar1[iVar5] = (this->soldiers).value[iVar5];
              iVar5 = iVar2;
            } while (iVar2 < (this->soldiers).maximumSizeValue);
          }
          operator_delete((this->soldiers).value);
          (this->soldiers).value = piVar1;
          (this->soldiers).maximumSizeValue = iVar7 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         ((RGE_Game_World *)this->md->aiPlayer->_padding_,
                          (this->soldiers).value[iVar7]);
      if ((pRVar3 == (RGE_Static_Object *)0x0) &&
         (pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0),
         pUVar4 == (UnitAIModule *)0x0)) {
        if (param_1 != -1) {
          pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
          iVar5 = UnitAIModule::currentAction(pUVar4);
          if (iVar5 != param_1) goto LAB_004f89a6;
        }
        if (param_2 != -1) {
          pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
          iVar5 = UnitAIModule::currentTarget(pUVar4);
          if (iVar5 != param_2) goto LAB_004f89a6;
        }
        if (param_3 != -1) {
          pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
          iVar5 = UnitAIModule::currentTargetType(pUVar4);
          if (iVar5 != param_3) goto LAB_004f89a6;
        }
        if (iVar7 <= (this->soldiers).maximumSizeValue + -1) goto LAB_004f8a1f;
        iVar5 = iVar7 + 1;
        piVar1 = (int *)operator_new(iVar5 * 4);
        if (piVar1 == (int *)0x0) goto LAB_004f8a1f;
        iVar2 = 0;
        if ((this->soldiers).maximumSizeValue < 1) goto LAB_004f8a04;
        goto LAB_004f89e7;
      }
LAB_004f89a6:
      iVar7 = iVar7 + 1;
    } while (iVar7 < (this->soldiers).numberValue);
  }
  iVar7 = 0;
  if ((this->boats).numberValue < 1) {
    return -1;
  }
  do {
    if ((this->boats).maximumSizeValue + -1 < iVar7) {
      piVar1 = (int *)operator_new(iVar7 * 4 + 4);
      if (piVar1 != (int *)0x0) {
        iVar5 = 0;
        if (0 < (this->boats).maximumSizeValue) {
          do {
            if (iVar7 + 1 <= iVar5) break;
            iVar2 = iVar5 + 1;
            piVar1[iVar5] = (this->boats).value[iVar5];
            iVar5 = iVar2;
          } while (iVar2 < (this->boats).maximumSizeValue);
        }
        operator_delete((this->boats).value);
        (this->boats).value = piVar1;
        (this->boats).maximumSizeValue = iVar7 + 1;
      }
    }
    pRVar3 = RGE_Game_World::object
                       ((RGE_Game_World *)this->md->aiPlayer->_padding_,(this->boats).value[iVar7]);
    if ((pRVar3 == (RGE_Static_Object *)0x0) &&
       (pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0), pUVar4 == (UnitAIModule *)0x0)
       ) {
      if (param_1 != -1) {
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
        iVar5 = UnitAIModule::currentAction(pUVar4);
        if (iVar5 != param_1) goto LAB_004f8b25;
      }
      if (param_2 != -1) {
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
        iVar5 = UnitAIModule::currentTarget(pUVar4);
        if (iVar5 != param_2) goto LAB_004f8b25;
      }
      if (param_3 != -1) {
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
        iVar5 = UnitAIModule::currentTargetType(pUVar4);
        if (iVar5 != param_3) goto LAB_004f8b25;
      }
      if (iVar7 <= (this->boats).maximumSizeValue + -1) goto LAB_004f8ba6;
      iVar5 = iVar7 + 1;
      piVar1 = (int *)operator_new(iVar5 * 4);
      if (piVar1 == (int *)0x0) goto LAB_004f8ba6;
      iVar2 = 0;
      if ((this->boats).maximumSizeValue < 1) goto LAB_004f8b8b;
      goto LAB_004f8b6e;
    }
LAB_004f8b25:
    iVar7 = iVar7 + 1;
    if ((this->boats).numberValue <= iVar7) {
      return -1;
    }
  } while( true );
  while( true ) {
    iVar6 = iVar2 + 1;
    piVar1[iVar2] = (this->soldiers).value[iVar2];
    iVar2 = iVar6;
    if ((this->soldiers).maximumSizeValue <= iVar6) break;
LAB_004f89e7:
    if (iVar5 <= iVar2) break;
  }
LAB_004f8a04:
  operator_delete((this->soldiers).value);
  (this->soldiers).value = piVar1;
  (this->soldiers).maximumSizeValue = iVar5;
LAB_004f8a1f:
  return (this->soldiers).value[iVar7];
  while( true ) {
    iVar6 = iVar2 + 1;
    piVar1[iVar2] = (this->boats).value[iVar2];
    iVar2 = iVar6;
    if ((this->boats).maximumSizeValue <= iVar6) break;
LAB_004f8b6e:
    if (iVar5 <= iVar2) break;
  }
LAB_004f8b8b:
  operator_delete((this->boats).value);
  (this->boats).value = piVar1;
  (this->boats).maximumSizeValue = iVar5;
LAB_004f8ba6:
  return (this->boats).value[iVar7];
}

// --------------------------------------------------

// Function: busyWithAction
// Address: 004f8be0
/* public: int __thiscall TribeTacticalAIModule::busyWithAction(int,int) */

int __thiscall
TribeTacticalAIModule::busyWithAction(TribeTacticalAIModule *this,int param_1,int param_2)
{
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar1;
  int iVar2;
  
  this_00 = RGE_Game_World::object((RGE_Game_World *)this->md->aiPlayer->_padding_,param_1);
  if (this_00 != (RGE_Static_Object *)0x0) {
    pUVar1 = RGE_Static_Object::unitAI(this_00);
    if (pUVar1 != (UnitAIModule *)0x0) {
      pUVar1 = RGE_Static_Object::unitAI(this_00);
      iVar2 = UnitAIModule::currentAction(pUVar1);
      if (iVar2 == param_2) {
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: displayCivilianDistribution
// Address: 004f8c30
/* public: void __thiscall TribeTacticalAIModule::displayCivilianDistribution(void) */

void __thiscall TribeTacticalAIModule::displayCivilianDistribution(TribeTacticalAIModule *this)
{
  return;
}

// --------------------------------------------------

// Function: updateNeededResources
// Address: 004f8c40
/* public: void __thiscall TribeTacticalAIModule::updateNeededResources(void) */

void __thiscall TribeTacticalAIModule::updateNeededResources(TribeTacticalAIModule *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int assignedResource [4];
  int tempNeededResource [4];
  int tempResourceDifference [4];
  
  TribeBuildAIModule::mostNeededResource(&this->md->buildAI,&this->neededResources,this->sn[0x93]);
  iVar6 = 0;
  tempResourceDifference[1] = -1;
  tempNeededResource[1] = -1;
  assignedResource[1] = 0;
  tempResourceDifference[2] = -1;
  tempNeededResource[2] = -1;
  assignedResource[2] = 0;
  tempResourceDifference[3] = -1;
  tempNeededResource[3] = -1;
  assignedResource[3] = 0;
  piVar4 = this->resourceDifferenceValue;
  tempResourceDifference[0] = -1;
  tempNeededResource[0] = 0;
  do {
    iVar1 = TribeResourceAIModule::resource(&this->md->resourceAI,iVar6);
    iVar2 = ResourceItem::value(&this->neededResources,iVar6);
    iVar6 = iVar6 + 1;
    *piVar4 = iVar1 - iVar2;
    piVar4 = piVar4 + 1;
  } while (iVar6 < 4);
  assignedResource[0] = 0;
  do {
    iVar1 = -1;
    iVar6 = 0x7fffffff;
    iVar2 = 0;
    do {
      if (iVar2 == 0) {
        iVar3 = TribeResourceAIModule::resource(&this->md->resourceAI,0);
        if (iVar3 < this->sn[0xbe]) goto LAB_004f8d09;
      }
      else {
LAB_004f8d09:
        if (iVar2 == 1) {
          iVar3 = TribeResourceAIModule::resource(&this->md->resourceAI,1);
          if (this->sn[0xbf] <= iVar3) goto LAB_004f8d95;
        }
        if (iVar2 == 3) {
          iVar3 = TribeResourceAIModule::resource(&this->md->resourceAI,3);
          if (this->sn[0xc1] <= iVar3) goto LAB_004f8d95;
        }
        if (iVar2 == 2) {
          iVar3 = TribeResourceAIModule::resource(&this->md->resourceAI,2);
          if (this->sn[0xc0] <= iVar3) goto LAB_004f8d95;
        }
        iVar3 = ResourceItem::value(&this->neededResources,iVar2);
        if ((0 < iVar3) &&
           (((iVar1 == -1 || (this->resourceDifferenceValue[iVar2] < iVar6)) &&
            (assignedResource[iVar2 + 1] == 0)))) {
          iVar6 = this->resourceDifferenceValue[iVar2];
          iVar1 = iVar2;
        }
      }
LAB_004f8d95:
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    if (iVar1 == -1) {
      iVar2 = 0;
      piVar5 = assignedResource;
      piVar4 = this->resourceDifferenceValue;
      do {
        piVar5 = piVar5 + 1;
        if (((iVar1 == -1) || (*piVar4 < iVar6)) && (*piVar5 == 0)) {
          iVar6 = *piVar4;
          iVar1 = iVar2;
        }
        iVar2 = iVar2 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar2 < 4);
    }
    assignedResource[iVar1 + 1] = 1;
    *(int *)((int)tempNeededResource + assignedResource[0] + 4) = iVar1;
    *(int *)((int)tempResourceDifference + assignedResource[0] + 4) = iVar6;
    assignedResource[0] = assignedResource[0] + 4;
    if (0xf < assignedResource[0]) {
      piVar4 = this->neededResourceValue;
      iVar6 = 0;
      do {
        iVar1 = *(int *)((int)tempNeededResource + iVar6 + 4);
        iVar2 = *(int *)((int)tempResourceDifference + iVar6 + 4);
        *piVar4 = iVar1;
        iVar6 = iVar6 + 4;
        piVar4 = piVar4 + 1;
        this->resourceDifferenceValue[iVar1] = iVar2;
      } while (iVar6 < 0x10);
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: updateGathererDistribution
// Address: 004f8e20
/* WARNING: Variable defined which should be unmapped: gSTT */
/* public: void __thiscall TribeTacticalAIModule::updateGathererDistribution(void) */

void __thiscall TribeTacticalAIModule::updateGathererDistribution(TribeTacticalAIModule *this)
{
  bool bVar1;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int gSTT;
  int gAction;
  int i;
  int local_4;
  
  this->actualGathererDistribution[0] = 0;
  this->actualGathererDistribution[1] = 0;
  local_4 = 0;
  this->actualGathererDistribution[2] = 0;
  this->actualGathererDistribution[3] = 0;
  if (0 < this->numberGatherersValue) {
    piVar7 = &this->gatherers[0].data1;
    do {
      this_00 = MainDecisionAIModule::object
                          ((MainDecisionAIModule *)this->md,((UnitData *)(piVar7 + -1))->id);
      if ((this_00 != (RGE_Static_Object *)0x0) &&
         (pUVar2 = RGE_Static_Object::unitAI(this_00), pUVar2 != (UnitAIModule *)0x0)) {
        pUVar2 = RGE_Static_Object::unitAI(this_00);
        iVar3 = UnitAIModule::currentAction(pUVar2);
        iVar6 = *piVar7;
        pUVar2 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentTarget(pUVar2);
        piVar7[3] = iVar4;
        if ((iVar3 == 0x261) && (this_00->master_obj->id == 0x103)) {
          if (iVar6 != 0) {
            iVar4 = (this->unitsTaskedThisUpdate).numberValue;
            iVar5 = 0;
            if (0 < iVar4) {
              do {
                if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar5) break;
                if ((this->unitsTaskedThisUpdate).value[iVar5] == this_00->id) goto LAB_004f8f06;
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
            this->actualGathererDistribution[iVar6] = this->actualGathererDistribution[iVar6] + 1;
          }
          else {
            iVar3 = (this->unitsTaskedThisUpdate).numberValue;
            iVar4 = 0;
            if (0 < iVar3) {
              do {
                if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar4) break;
                if ((this->unitsTaskedThisUpdate).value[iVar4] == ((UnitData *)(piVar7 + -1))->id)
                goto LAB_004f8f4c;
                iVar4 = iVar4 + 1;
              } while (iVar4 < iVar3);
            }
          }
        }
      }
LAB_004f8f53:
      local_4 = local_4 + 1;
      piVar7 = piVar7 + 6;
    } while (local_4 < this->numberGatherersValue);
  }
  piVar7 = this->desiredGathererDistribution;
  bVar1 = false;
  *piVar7 = 0;
  this->desiredGathererDistribution[1] = 0;
  this->desiredGathererDistribution[2] = 0;
  this->desiredGathererDistribution[3] = 0;
  iVar6 = inAge(this,1);
  if (iVar6 == 0) {
    iVar6 = inAge(this,2);
    if (iVar6 == 0) {
      iVar6 = inAge(this,3);
      if (iVar6 == 0) goto LAB_004f91ed;
      if (this->sn[0xb7] == 1) {
        iVar6 = TribeBuildAIModule::readyToResearch(&this->md->buildAI,4,1);
        if (iVar6 == 0) {
          iVar6 = this->desiredNumberGatherersValue / 3;
          this->zoomingToNextAge = 0;
          bVar1 = true;
          *piVar7 = iVar6;
          this->desiredGathererDistribution[3] = iVar6;
          this->desiredGathererDistribution[1] = iVar6;
        }
        else {
          iVar3 = 0;
          iVar6 = this->desiredNumberGatherersValue / 2;
          *piVar7 = iVar6;
          this->desiredGathererDistribution[3] = iVar6;
          if (0 < this->numberGatherersValue) {
            piVar7 = &this->gatherers[0].data1;
            do {
              iVar6 = *piVar7;
              if (((iVar6 != 0) && (iVar6 != 3)) && (iVar6 != -1)) {
                piVar7[1] = 5;
              }
              iVar3 = iVar3 + 1;
              piVar7 = piVar7 + 6;
            } while (iVar3 < this->numberGatherersValue);
          }
          this->zoomingToNextAge = 1;
          bVar1 = true;
        }
        goto LAB_004f91ed;
      }
    }
    else if (this->sn[0xb6] == 1) {
      iVar6 = TribeBuildAIModule::readyToResearch(&this->md->buildAI,3,1);
      if ((iVar6 != 0) &&
         ((iVar6 = TribeResourceAIModule::resource(&this->md->resourceAI,1), 0xf0 < iVar6 ||
          ((iVar6 = TribeResourceAIModule::resource(&this->md->resourceAI,1), 0x78 < iVar6 &&
           ((this->md->informationAI).closestDropsiteValue[0] < 0x14)))))) {
        *piVar7 = this->desiredNumberGatherersValue;
        iVar6 = 0;
        if (0 < this->numberGatherersValue) {
          piVar7 = &this->gatherers[0].data1;
          do {
            if ((*piVar7 != 0) && (*piVar7 != -1)) {
              piVar7[1] = 5;
            }
            iVar6 = iVar6 + 1;
            piVar7 = piVar7 + 6;
          } while (iVar6 < this->numberGatherersValue);
        }
        this->zoomingToNextAge = 1;
        bVar1 = true;
        goto LAB_004f91ed;
      }
      goto LAB_004f910b;
    }
  }
  else if (this->sn[0xb5] == 1) {
    iVar6 = TribeBuildAIModule::readyToResearch(&this->md->buildAI,2,1);
    if (((iVar6 != 0) && ((this->md->informationAI).closestDropsiteValue[0] != -1)) &&
       ((iVar6 = TribeResourceAIModule::resource(&this->md->resourceAI,1), 0x78 < iVar6 ||
        (this->builtFirstGranary == 1)))) {
      *piVar7 = this->desiredNumberGatherersValue;
      iVar6 = 0;
      if (0 < this->numberGatherersValue) {
        piVar7 = &this->gatherers[0].data1;
        do {
          if ((*piVar7 != 0) && (*piVar7 != -1)) {
            piVar7[1] = 5;
          }
          iVar6 = iVar6 + 1;
          piVar7 = piVar7 + 6;
        } while (iVar6 < this->numberGatherersValue);
      }
      this->zoomingToNextAge = 1;
      bVar1 = true;
      goto LAB_004f91ed;
    }
LAB_004f910b:
    this->zoomingToNextAge = 0;
    this->desiredGathererDistribution[1] = this->desiredNumberGatherersValue;
    bVar1 = true;
    goto LAB_004f91ed;
  }
  this->zoomingToNextAge = 0;
LAB_004f91ed:
  if (!bVar1) {
    iVar6 = this->desiredNumberGatherersValue;
    iVar3 = this->sn[0x76];
    this->desiredGathererDistribution[2] = ((this->sn[0x77] + this->sn[0x9e]) * iVar6) / 100;
    iVar4 = this->sn[0x78];
    this->desiredGathererDistribution[3] = ((iVar3 + this->sn[0x9f]) * iVar6) / 100;
    iVar3 = this->sn[0x75];
    iVar5 = this->sn[0x9c];
    this->desiredGathererDistribution[1] = ((iVar4 + this->sn[0x9d]) * iVar6) / 100;
    this->desiredGathererDistribution[0] = ((iVar3 + iVar5) * iVar6) / 100;
  }
  iVar6 = 0;
  piVar7 = this->desiredGathererDistribution;
  iVar3 = 4;
  do {
    iVar4 = *piVar7;
    piVar7 = piVar7 + 1;
    iVar6 = iVar6 + iVar4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = this->desiredNumberGatherersValue;
  local_4 = 0;
  iVar4 = 0;
  piVar7 = this->resourceDifferenceValue;
  iVar5 = 4;
  do {
    if (*piVar7 < 0) {
      iVar4 = iVar4 - *piVar7;
      local_4 = local_4 + 1;
    }
    piVar7 = piVar7 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (0 < local_4) {
    piVar7 = this->neededResourceValue;
    do {
      iVar5 = *piVar7;
      piVar7 = piVar7 + 1;
      local_4 = local_4 + -1;
      this->desiredGathererDistribution[iVar5] =
           this->desiredGathererDistribution[iVar5] -
           (this->resourceDifferenceValue[iVar5] * (iVar3 - iVar6)) / iVar4;
    } while (local_4 != 0);
  }
  iVar6 = 0;
  piVar7 = this->desiredGathererDistribution;
  iVar3 = 4;
  do {
    iVar4 = *piVar7;
    piVar7 = piVar7 + 1;
    iVar6 = iVar6 + iVar4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar8 = this->desiredNumberGatherersValue - iVar6;
  if (0 < (int)uVar8) {
    uVar9 = (int)uVar8 >> 0x1f;
    iVar3 = (int)uVar8 / 2;
    iVar6 = iVar3;
    if (((uVar8 ^ uVar9) - uVar9 & 1 ^ uVar9) - uVar9 == 1) {
      iVar6 = iVar3 + 1;
    }
    iVar4 = this->desiredGathererDistribution[1];
    this->desiredGathererDistribution[0] = this->desiredGathererDistribution[0] + iVar6;
    this->desiredGathererDistribution[1] = iVar4 + iVar3;
  }
  return;
}

// --------------------------------------------------

// Function: stopUnit
// Address: 004f9380
/* public: int __thiscall TribeTacticalAIModule::stopUnit(int,int) */

int __thiscall TribeTacticalAIModule::stopUnit(TribeTacticalAIModule *this,int param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = (int *)this->md->_padding_;
  (**(code **)(*piVar1 + 0x30))
            ((int)*(short *)((int)piVar1 + 0x4a),param_1,0x2c2,0xffffffff,0xffffffff,0xbf800000,
             0xbf800000,0xbf800000,0xbf800000,1,0,param_2);
  return 1;
}

// --------------------------------------------------

// Function: moveUnit
// Address: 004f93d0
/* public: int __thiscall TribeTacticalAIModule::moveUnit(int,float,float,int) */

int __thiscall
TribeTacticalAIModule::moveUnit
          (TribeTacticalAIModule *this,int param_1,float param_2,float param_3,int param_4)
{
  int *piVar1;
  
  piVar1 = (int *)this->md->_padding_;
  (**(code **)(*piVar1 + 0x30))
            ((int)*(short *)((int)piVar1 + 0x4a),param_1,0x2c6,0xffffffff,0xffffffff,param_2,param_3
             ,0x3f800000,0x3f800000,1,0,param_4);
  return 1;
}

// --------------------------------------------------

// Function: groupGatherUnit
// Address: 004f9420
/* public: int __thiscall
   TribeTacticalAIModule::groupGatherUnit(int,int,float,float,float,float,int) */

int __thiscall
TribeTacticalAIModule::groupGatherUnit
          (TribeTacticalAIModule *this,int param_1,int param_2,float param_3,float param_4,
          float param_5,float param_6,int param_7)
{
  int *piVar1;
  
  piVar1 = (int *)this->md->_padding_;
  (**(code **)(*piVar1 + 0x30))
            ((int)*(short *)((int)piVar1 + 0x4a),param_1,0x2d4,param_2,0xffffffff,param_3,param_4,
             param_5,param_6,1,0,param_7);
  return 1;
}

// --------------------------------------------------

// Function: highLevelTaskExplorer
// Address: 004f9470
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TribeTacticalAIModule::highLevelTaskExplorer(int,int) */

int __thiscall
TribeTacticalAIModule::highLevelTaskExplorer(TribeTacticalAIModule *this,int param_1,int param_2)
{
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar1;
  int iVar2;
  
  this_00 = RGE_Game_World::object(*(RGE_Game_World **)(this->md->_padding_ + 0x3c),param_1);
  if ((this_00 == (RGE_Static_Object *)0x0) ||
     (pUVar1 = RGE_Static_Object::unitAI(this_00), pUVar1 == (UnitAIModule *)0x0)) {
    return 0;
  }
  pUVar1 = RGE_Static_Object::unitAI(this_00);
  iVar2 = UnitAIModule::currentAction(pUVar1);
  if (iVar2 == 600) {
    return 1;
  }
  pUVar1 = RGE_Static_Object::unitAI(this_00);
  iVar2 = UnitAIModule::currentAction(pUVar1);
  if (iVar2 != 0x25a) {
    pUVar1 = RGE_Static_Object::unitAI(this_00);
    iVar2 = UnitAIModule::currentAction(pUVar1);
    if (iVar2 != 0x26a) {
      pUVar1 = RGE_Static_Object::unitAI(this_00);
      iVar2 = UnitAIModule::currentAction(pUVar1);
      if (iVar2 == 0x25d) {
        return 1;
      }
      if (_DAT_005756f0 < this_00->attribute_amount_held) {
        return 0;
      }
      pUVar1 = RGE_Static_Object::unitAI(this_00);
      iVar2 = UnitAIModule::currentOrder(pUVar1);
      if (iVar2 == 0x2c6) {
        pUVar1 = RGE_Static_Object::unitAI(this_00);
        iVar2 = UnitAIModule::currentOrderPriority(pUVar1);
        if (iVar2 == 100) {
          return 0;
        }
      }
      pUVar1 = RGE_Static_Object::unitAI(this_00);
      iVar2 = UnitAIModule::currentOrder(pUVar1);
      if (iVar2 == 0x2be) {
        return 0;
      }
      iVar2 = 0x2c1;
      pUVar1 = RGE_Static_Object::unitAI(this_00);
      iVar2 = UnitAIModule::hasOrderOnQueue(pUVar1,iVar2);
      if (iVar2 == 1) {
        return 0;
      }
      iVar2 = taskExplorer(this,param_1,param_2);
      return (uint)(iVar2 != 0);
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: highLevelTaskGatherer
// Address: 004f95b0
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TribeTacticalAIModule::highLevelTaskGatherer(int,unsigned long) */

int __thiscall
TribeTacticalAIModule::highLevelTaskGatherer(TribeTacticalAIModule *this,int param_1,ulong param_2)
{
  UnitData *pUVar1;
  ulong uVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  RGE_Static_Object *gathererObj;
  int triedTasking [4];
  
  iVar8 = 0;
  iVar4 = this->numberGatherersValue;
  triedTasking[1] = 0;
  triedTasking[2] = 0;
  triedTasking[3] = 0;
  if (0 < iVar4) {
    pUVar1 = this->gatherers;
    do {
      if (pUVar1->id == param_1) break;
      iVar8 = iVar8 + 1;
      pUVar1 = pUVar1 + 1;
    } while (iVar8 < iVar4);
  }
  if (iVar4 <= iVar8) {
    return 0;
  }
                    /* language.dll match for 0x1f5c: "Research Plow: +75 food production for Farms"
                        */
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x1f5c);
  if (uVar2 - this->gatherers[iVar8].lastTaskTime < 5000) {
    return 1;
  }
  this->gatherers[iVar8].lastTaskTime = uVar2;
  this_00 = RGE_Game_World::object(*(RGE_Game_World **)(this->md->_padding_ + 0x3c),param_1);
  if (this_00 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  triedTasking[0] = (int)this_00;
  pUVar3 = RGE_Static_Object::unitAI(this_00);
  if (pUVar3 == (UnitAIModule *)0x0) {
    return 0;
  }
  pUVar3 = RGE_Static_Object::unitAI(this_00);
  iVar4 = UnitAIModule::currentAction(pUVar3);
  if (iVar4 == 600) {
    return 1;
  }
  pUVar3 = RGE_Static_Object::unitAI(this_00);
  iVar4 = UnitAIModule::currentAction(pUVar3);
  if (iVar4 == 0x25a) {
    return 1;
  }
  pUVar3 = RGE_Static_Object::unitAI(this_00);
  iVar4 = UnitAIModule::currentAction(pUVar3);
  if (iVar4 == 0x26a) {
    return 1;
  }
  if (_DAT_005756f0 < this_00->attribute_amount_held) {
    return 1;
  }
  iVar4 = isFarmer(this,this_00);
  if (iVar4 == 1) {
    iVar4 = (this->civilians).numberValue;
    iVar5 = numberFarmers(this);
    iVar6 = TribeResourceAIModule::resource(&this->md->resourceAI,0);
    if ((iVar6 < 1000) && (3 < iVar4 - iVar5)) {
      return 1;
    }
  }
  pUVar3 = RGE_Static_Object::unitAI(this_00);
  iVar4 = UnitAIModule::currentOrder(pUVar3);
  if (iVar4 == 0x2c6) {
    pUVar3 = RGE_Static_Object::unitAI(this_00);
    iVar4 = UnitAIModule::currentOrderPriority(pUVar3);
    if (iVar4 == 100) {
      return 1;
    }
  }
  pUVar3 = RGE_Static_Object::unitAI(this_00);
  iVar4 = UnitAIModule::currentOrder(pUVar3);
  if (iVar4 == 0x2be) {
    return 1;
  }
  if (this->gatherers[iVar8].data3 < this->gatherers[iVar8].data2) {
    pUVar3 = RGE_Static_Object::unitAI(this_00);
    iVar4 = UnitAIModule::currentAction(pUVar3);
    if (iVar4 != -1) {
      return 1;
    }
    iVar4 = this->gatherers[iVar8].data1;
    triedTasking[iVar4 + 1] = 1;
    iVar4 = taskGatherer(this,this->gatherers[iVar8].id,iVar4,0,param_2,(int *)0x0);
    if (iVar4 == 1) {
      return 1;
    }
    this->gatherers[iVar8].data1 = -1;
    this->gatherers[iVar8].data2 = -1;
    this->gatherers[iVar8].data3 = -1;
  }
  param_1 = (int)triedTasking;
  piVar7 = this->desiredGathererDistribution;
  iVar4 = 0;
  iVar5 = 0;
  do {
    iVar6 = triedTasking[0];
    param_1 = param_1 + 4;
    if ((*(int *)param_1 != 1) && (piVar7[-4] < *piVar7)) {
      if (this->gatherers[iVar8].data1 == iVar5) {
        pUVar3 = RGE_Static_Object::unitAI((RGE_Static_Object *)triedTasking[0]);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 == 0x265) {
          return 1;
        }
        pUVar3 = RGE_Static_Object::unitAI((RGE_Static_Object *)iVar6);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 == 0x261) {
          return 1;
        }
      }
      iVar4 = this->gatherers[iVar8].id;
      *(undefined4 *)param_1 = 1;
      iVar4 = taskGatherer(this,iVar4,iVar5,0,param_2,(int *)0x0);
      if (iVar4 == 1) {
        return 1;
      }
    }
    iVar5 = iVar5 + 1;
    piVar7 = piVar7 + 1;
  } while (iVar5 < 4);
  iVar5 = inAge(this,1);
  if (((iVar5 == 0) || (this->sn[0xb5] != 1)) &&
     ((iVar5 = inAge(this,2), iVar5 == 0 || ((this->sn[0xb6] != 1 || (triedTasking[1] != 0)))))) {
    iVar5 = inAge(this,3);
    if ((iVar5 == 0) || (this->sn[0xb7] != 1)) goto LAB_004f9964;
    if (triedTasking[1] == 0) {
      iVar4 = taskGatherer(this,this->gatherers[iVar8].id,0,1,param_2,(int *)0x0);
      triedTasking[1] = 1;
    }
    if (iVar4 != 0) {
      return 1;
    }
    iVar4 = this->gatherers[iVar8].id;
    iVar5 = 3;
  }
  else {
    iVar4 = this->gatherers[iVar8].id;
    iVar5 = 0;
    triedTasking[1] = 1;
  }
  iVar4 = taskGatherer(this,iVar4,iVar5,1,param_2,(int *)0x0);
LAB_004f9964:
  if (iVar4 == 0) {
    taskGatherer(this,this->gatherers[iVar8].id,-1,1,param_2,triedTasking + 1);
  }
  return 1;
}

// --------------------------------------------------

// Function: taskPlay
// Address: 004f99b0
/* public: int __thiscall TribeTacticalAIModule::taskPlay(int,int *,int,int,int,struct Waypoint
   *,int) */

int __thiscall
TribeTacticalAIModule::taskPlay
          (TribeTacticalAIModule *this,int param_1,int *param_2,int param_3,int param_4,int param_5,
          Waypoint *param_6,int param_7)
{
  int iVar1;
  uchar uVar2;
  uchar uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if ((param_6 != (Waypoint *)0x0) && (0 < param_7)) {
    do {
      uVar2 = __ftol();
      uVar3 = __ftol();
      addWaypoint(this,param_1,uVar3,uVar2);
      param_7 = param_7 + -1;
    } while (param_7 != 0);
  }
  iVar1 = (this->unitsTaskedThisUpdate).numberValue;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar4) break;
      if ((this->unitsTaskedThisUpdate).value[iVar4] == param_1) goto LAB_004f9a97;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar5 = (int *)operator_new(iVar1 * 4);
    if (piVar5 != (int *)0x0) {
      iVar4 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar1 <= iVar4) break;
          iVar6 = iVar4 + 1;
          piVar5[iVar4] = (this->unitsTaskedThisUpdate).value[iVar4];
          iVar4 = iVar6;
        } while (iVar6 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar5;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar1;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004f9a97:
  (**(code **)(*(int *)this->md->_padding_ + 0x4c))(param_1,param_2,param_3,param_4,param_5);
  return 1;
}

// --------------------------------------------------

// Function: taskBuilder
// Address: 004f9ad0
/* WARNING: Variable defined which should be unmapped: position */
/* public: int __thiscall TribeTacticalAIModule::taskBuilder(int,class BuildItem *,class
   ConstructionItem *,unsigned long) */

int __thiscall
TribeTacticalAIModule::taskBuilder
          (TribeTacticalAIModule *this,int param_1,BuildItem *param_2,ConstructionItem *param_3,
          ulong param_4)
{
  RGE_Static_Object *this_00;
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
  BuildItem *this_01;
  BuildItem *pBVar12;
  XYPoint position;
  
  if (((param_2 != (BuildItem *)0x0) ||
      (param_2 = TribeBuildAIModule::nextBuildableItem(&this->md->buildAI,0),
      param_2 != (BuildItem *)0x0)) &&
     ((param_3 != (ConstructionItem *)0x0 ||
      (param_3 = TribeConstructionAIModule::placeStructure
                           (&this->md->constructionAI,param_2,param_1,&this->placementStateValue,
                            param_4), param_3 != (ConstructionItem *)0x0)))) {
    if (param_1 == -1) {
      BaseItem::x((BaseItem *)param_3);
      position.y = __ftol();
      BaseItem::y((BaseItem *)param_3);
      __ftol();
      param_1 = civilian(this,(XYPoint *)&position.y,1,0x2be,0x2ce,700,0);
    }
    this_00 = RGE_Game_World::object(*(RGE_Game_World **)(this->md->_padding_ + 0x3c),param_1);
    if ((this_00 == (RGE_Static_Object *)0x0) ||
       (pUVar1 = RGE_Static_Object::unitAI(this_00), pUVar1 == (UnitAIModule *)0x0)) {
      if (param_3 != (ConstructionItem *)0x0) {
        (**(code **)param_3->_padding_)(1);
      }
    }
    else {
      BaseItem::x((BaseItem *)param_3);
      uVar2 = __ftol();
      BaseItem::y((BaseItem *)param_3);
      uVar3 = __ftol();
      uVar4 = __ftol();
      this_01 = (BuildItem *)0xffffffff;
      iVar11 = -1;
      iVar5 = (**(code **)(this_00->_padding_ + 0x198))(uVar2,uVar3,uVar4,0x40000000,0xffffffff,0,1)
      ;
      if (iVar5 != 0) {
        pBVar12 = this_01;
        BuildItem::setInProgress(this_01,1);
        BuildItem::setBuilt(this_01,0);
        iVar5 = (this->civilianExplorers).maximumSizeValue;
        iVar6 = 0;
        if (0 < iVar5) {
          piVar7 = (this->civilianExplorers).value;
          do {
            if (*piVar7 == iVar11) break;
            iVar6 = iVar6 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar6 < iVar5);
        }
        if (iVar6 < iVar5) {
          if (iVar6 < iVar5 + -1) {
            do {
              piVar7 = (this->civilianExplorers).value;
              iVar5 = iVar6 + 1;
              piVar7[iVar6] = piVar7[iVar5];
              iVar6 = iVar5;
            } while (iVar5 < (this->civilianExplorers).maximumSizeValue + -1);
          }
          iVar5 = (this->civilianExplorers).numberValue + -1;
          (this->civilianExplorers).numberValue = iVar5;
          if (iVar5 < 0) {
            (this->civilianExplorers).numberValue = 0;
          }
        }
        iVar5 = (this->unitsTaskedThisUpdate).numberValue;
        iVar6 = 0;
        if (0 < iVar5) {
          do {
            if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar6) break;
            if ((this->unitsTaskedThisUpdate).value[iVar6] == iVar11) goto LAB_004f9d52;
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar5);
        }
        this_01 = pBVar12;
        if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar5) {
          iVar5 = iVar5 + 1;
          piVar7 = (int *)operator_new(iVar5 * 4);
          this_01 = pBVar12;
          if (piVar7 != (int *)0x0) {
            iVar6 = 0;
            if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
              do {
                if (iVar5 <= iVar6) break;
                iVar8 = iVar6 + 1;
                piVar7[iVar6] = (this->unitsTaskedThisUpdate).value[iVar6];
                iVar6 = iVar8;
              } while (iVar8 < (this->unitsTaskedThisUpdate).maximumSizeValue);
            }
            operator_delete((this->unitsTaskedThisUpdate).value);
            (this->unitsTaskedThisUpdate).value = piVar7;
            (this->unitsTaskedThisUpdate).maximumSizeValue = iVar5;
            this_01 = pBVar12;
          }
        }
        (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = iVar11;
        (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004f9d52:
        iVar5 = BaseItem::typeID(unaff_EDI);
        if (iVar5 == 0x114) {
          this->wonderInProgressValue = 1;
        }
        iVar5 = this->md->aiPlayer->_padding_;
        iVar6 = BaseItem::uniqueID((BaseItem *)this_01);
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

// Function: taskBuilder
// Address: 004f9e00
/* WARNING: Variable defined which should be unmapped: builderObj */
/* public: int __thiscall TribeTacticalAIModule::taskBuilder(int,class RGE_Static_Object *) */

int __thiscall
TribeTacticalAIModule::taskBuilder
          (TribeTacticalAIModule *this,int param_1,RGE_Static_Object *param_2)
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
  RGE_Static_Object *builderObj;
  
  pRVar1 = RGE_Game_World::object(*(RGE_Game_World **)(this->md->_padding_ + 0x3c),param_1);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  uVar2 = __ftol();
  uVar3 = __ftol();
  uVar4 = __ftol();
  if (param_2 == (RGE_Static_Object *)0x0) {
    iVar11 = 1;
    pRVar10 = (RGE_Static_Object *)0xffffffff;
    iVar5 = (**(code **)(pRVar1->_padding_ + 0x198))
                      (uVar2,uVar3,uVar4,0x3f800000,0xffffffff,0,1,0xffffffff,0xffffffff);
    if (iVar5 == 0) {
      return 0;
    }
  }
  else {
    pRVar10 = (RGE_Static_Object *)param_2->id;
    iVar11 = 1;
    iVar5 = (**(code **)(pRVar1->_padding_ + 0x198))
                      (uVar2,uVar3,uVar4,0x3f800000,pRVar10,0,1,0xffffffff,0xffffffff);
    if (iVar5 == 0) {
      if (param_2->master_obj->id != 0x114) {
        deleteUnit(this,param_2->id);
      }
      return 0;
    }
  }
  iVar5 = (this->unitsTaskedThisUpdate).numberValue;
  iVar6 = 0;
  if (0 < iVar5) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar6) break;
      if ((this->unitsTaskedThisUpdate).value[iVar6] == iVar11) goto LAB_004f9f95;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar5);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar5) {
    iVar5 = iVar5 + 1;
    piVar7 = (int *)operator_new(iVar5 * 4);
    if (piVar7 != (int *)0x0) {
      iVar6 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar5 <= iVar6) break;
          iVar8 = iVar6 + 1;
          piVar7[iVar6] = (this->unitsTaskedThisUpdate).value[iVar6];
          iVar6 = iVar8;
        } while (iVar8 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar7;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar5;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = iVar11;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004f9f95:
  fVar9 = RGE_Static_Object::distance_to_object(param_2,pRVar10);
  iVar5 = calculatePriority(this,fVar9);
  piVar7 = (int *)this->md->_padding_;
  iVar6 = (int)*(short *)((int)piVar7 + 0x4a);
  (**(code **)(*piVar7 + 0x30))
            (iVar6,iVar11,0x2be,param_2->id,iVar6,param_2->world_x,param_2->world_y,param_2->world_z
             ,0x3f800000,1,1,iVar5);
  return 1;
}

// --------------------------------------------------

// Function: taskRepairer
// Address: 004fa000
/* WARNING: Variable defined which should be unmapped: builderObj */
/* public: int __thiscall TribeTacticalAIModule::taskRepairer(int,class RGE_Static_Object *) */

int __thiscall
TribeTacticalAIModule::taskRepairer
          (TribeTacticalAIModule *this,int param_1,RGE_Static_Object *param_2)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int unaff_EDI;
  float fVar6;
  RGE_Static_Object *pRVar7;
  RGE_Static_Object *builderObj;
  
  pRVar1 = RGE_Game_World::object(*(RGE_Game_World **)(this->md->_padding_ + 0x3c),param_1);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  pRVar7 = (RGE_Static_Object *)0xffffffff;
  iVar2 = (**(code **)(pRVar1->_padding_ + 0x194))(param_2->id,0x3f800000,0,1,0xffffffff,0xffffffff)
  ;
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = (this->unitsTaskedThisUpdate).numberValue;
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar3) break;
      if ((this->unitsTaskedThisUpdate).value[iVar3] == param_1) goto LAB_004fa112;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar2) {
    iVar2 = iVar2 + 1;
    pRVar1 = pRVar7;
    piVar4 = (int *)operator_new(iVar2 * 4);
    param_1 = unaff_EDI;
    if (piVar4 != (int *)0x0) {
      iVar3 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar2 <= iVar3) break;
          iVar5 = iVar3 + 1;
          piVar4[iVar3] = (this->unitsTaskedThisUpdate).value[iVar3];
          iVar3 = iVar5;
        } while (iVar5 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar4;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar2;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fa112:
  fVar6 = RGE_Static_Object::distance_to_object(param_2,pRVar1);
  iVar2 = calculatePriority(this,fVar6);
  piVar4 = (int *)this->md->_padding_;
  iVar3 = (int)*(short *)((int)piVar4 + 0x4a);
  (**(code **)(*piVar4 + 0x30))
            (iVar3,param_1,0x2ce,param_2->id,iVar3,param_2->world_x,param_2->world_y,
             param_2->world_z,0x3f800000,1,0,iVar2);
  return 1;
}

// --------------------------------------------------

// Function: taskGatherer
// Address: 004fa170
/* WARNING: Variable defined which should be unmapped: numStoragePits */
/* public: int __thiscall TribeTacticalAIModule::taskGatherer(int,int,int,unsigned long,int *) */

int __thiscall
TribeTacticalAIModule::taskGatherer
          (TribeTacticalAIModule *this,int param_1,int param_2,int param_3,ulong param_4,
          int *param_5)
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
  int numStoragePits;
  RGE_Static_Object *gathererObj;
  float rYPos;
  float rXPos;
  int dropsiteID;
  int numUnbuiltStoragePits;
  int maximumResourceDistance;
  int exclusions [5];
  
  pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  rYPos = (float)pRVar3;
  pUVar4 = gatherer(this,param_1);
  if ((pUVar4 != (UnitData *)0x0) && (pUVar4->data3 < pUVar4->data2)) {
    param_2 = pUVar4->data1;
  }
  iVar10 = -1;
  dropsiteID = 0;
  rXPos = 0.0;
  gathererObj = (RGE_Static_Object *)0x0;
  if (param_2 == -1) {
    gathererObj = (RGE_Static_Object *)0x0;
    piVar7 = this->neededResourceValue;
    do {
      param_2 = *piVar7;
      if ((param_5 == (int *)0x0) || (param_5[param_2] != 1)) {
        numUnbuiltStoragePits = -1;
        iVar10 = TribeInformationAIModule::gameIDOfResourceObject
                           (&this->md->informationAI,param_2,param_1,(float *)&dropsiteID,&rXPos,
                            &numUnbuiltStoragePits,exclusions + 1,0);
        if (iVar10 != -1) {
          if (numUnbuiltStoragePits == -1) {
            (**(code **)(*(int *)rYPos + 0x194))(iVar10);
          }
          else {
            (**(code **)(*(int *)rYPos + 0x19c))
                      (iVar10,numUnbuiltStoragePits,0x3f800000,0,1,0xffffffff,0xffffffff);
          }
          break;
        }
      }
      piVar7 = piVar7 + 1;
      gathererObj = (RGE_Static_Object *)((int)&gathererObj->_padding_ + 1);
    } while ((int)gathererObj < 4);
    if (iVar10 == -1) {
      return 0;
    }
  }
  else {
    maximumResourceDistance = 0;
    param_5 = exclusions;
    do {
      param_5 = param_5 + 1;
      numUnbuiltStoragePits = -1;
      iVar10 = TribeInformationAIModule::gameIDOfResourceObject
                         (&this->md->informationAI,param_2,param_1,(float *)&dropsiteID,&rXPos,
                          &numUnbuiltStoragePits,exclusions + 1,(int)gathererObj);
      if (iVar10 == -1) {
        return 0;
      }
      if (numUnbuiltStoragePits == -1) {
        iVar5 = (**(code **)(pRVar3->_padding_ + 0x194))(iVar10);
      }
      else {
        iVar5 = (**(code **)(pRVar3->_padding_ + 0x19c))
                          (iVar10,numUnbuiltStoragePits,0x3f800000,0,1,0xffffffff,0xffffffff);
      }
      if (iVar5 != 0) break;
      if (param_2 == 0) {
        iVar5 = 2;
      }
      else {
        iVar5 = 0xf;
      }
      TribeInformationAIModule::setResourceObjectValid
                (&this->md->informationAI,param_2,iVar10,iVar5);
      gathererObj = (RGE_Static_Object *)((int)&gathererObj->_padding_ + 1);
      *param_5 = iVar10;
      iVar10 = -1;
      maximumResourceDistance = maximumResourceDistance + 1;
    } while (maximumResourceDistance < 3);
    if (iVar10 < 0) {
      return 0;
    }
  }
  pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar10);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  if (this->sn[0xcd] != 1) goto LAB_004fa558;
  if ((param_2 == 0) && (this->builtFirstGranary == 1)) {
    if (this->builtFirstStoragePit != 1) goto LAB_004fa558;
    if (pRVar3->master_obj->id != 0x3b) {
      sVar1 = pRVar3->master_obj->object_group;
      if (((sVar1 == 0x1f) || (sVar1 == 5)) || (sVar1 == 0x21)) goto LAB_004fa558;
      gathererObj = (RGE_Static_Object *)0x0;
      maximumResourceDistance = 0;
      iVar5 = numberAvailableStoragePits(this,(int *)&gathererObj,&maximumResourceDistance,0);
      if ((maximumResourceDistance != 0) || (iVar5 < 1)) goto LAB_004fa558;
      RGE_Static_Object::distance_to_object((RGE_Static_Object *)rYPos,pRVar3);
      iVar5 = __ftol();
      if (iVar5 < 0x10) goto joined_r0x004fa53f;
      goto LAB_004fa541;
    }
    gathererObj = (RGE_Static_Object *)0x0;
    maximumResourceDistance = 0;
    iVar5 = numberAvailableGranaries(this,(int *)&gathererObj,&maximumResourceDistance);
    if ((maximumResourceDistance != 0) || (iVar5 < 1)) goto LAB_004fa558;
    exclusions[0] = this->sn[0xa3];
    RGE_Static_Object::distance_to_object((RGE_Static_Object *)rYPos,pRVar3);
    iVar5 = __ftol();
    if ((iVar5 <= exclusions[0]) ||
       (pTVar2 = this->md, (pTVar2->informationAI).closestDropsiteValue[0] == -1))
    goto LAB_004fa558;
    iVar5 = __ftol();
    iVar6 = __ftol();
    iVar5 = TribeInformationAIModule::acceptablePotentialDropsiteArea
                      (&pTVar2->informationAI,iVar6,iVar5);
    if (iVar5 != 1) goto LAB_004fa558;
    iVar5 = 0x44;
  }
  else {
    if ((this->builtFirstStoragePit != 1) || (this->builtFirstGranary != 1)) goto LAB_004fa558;
    gathererObj = (RGE_Static_Object *)0x0;
    maximumResourceDistance = 0;
    iVar5 = numberAvailableStoragePits(this,(int *)&gathererObj,&maximumResourceDistance,param_2);
    if ((maximumResourceDistance != 0) || (iVar5 < 1)) goto LAB_004fa558;
    exclusions[0] = this->sn[pRVar3->attribute_type_held + 0xa3];
    RGE_Static_Object::distance_to_object((RGE_Static_Object *)rYPos,pRVar3);
    iVar5 = __ftol();
    if (iVar5 <= exclusions[0]) {
joined_r0x004fa53f:
      if (gathererObj != (RGE_Static_Object *)0x0) goto LAB_004fa558;
    }
LAB_004fa541:
                    /* language.dll match for 0x67: "Comic Sans MS" */
    iVar5 = 0x67;
  }
  TribeBuildAIModule::insert(&this->md->buildAI,iVar5,1,-1);
LAB_004fa558:
  iVar5 = (this->civilianExplorers).maximumSizeValue;
  iVar6 = 0;
  if (0 < iVar5) {
    piVar7 = (this->civilianExplorers).value;
    do {
      if (*piVar7 == param_1) break;
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar6 < iVar5);
  }
  if (iVar6 < iVar5) {
    if (iVar6 < iVar5 + -1) {
      do {
        piVar7 = (this->civilianExplorers).value;
        iVar5 = iVar6 + 1;
        piVar7[iVar6] = piVar7[iVar5];
        iVar6 = iVar5;
      } while (iVar5 < (this->civilianExplorers).maximumSizeValue + -1);
    }
    iVar5 = (this->civilianExplorers).numberValue + -1;
    (this->civilianExplorers).numberValue = iVar5;
    if (iVar5 < 0) {
      (this->civilianExplorers).numberValue = 0;
    }
  }
  maximumResourceDistance = (int)addGatherer(this,param_1);
  if ((UnitData *)maximumResourceDistance == (UnitData *)0x0) {
    return 0;
  }
  iVar6 = 0;
  this->actualGathererDistribution[param_2] = this->actualGathererDistribution[param_2] + 1;
  iVar5 = (this->unitsTaskedThisUpdate).numberValue;
  if (0 < iVar5) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar6) break;
      if ((this->unitsTaskedThisUpdate).value[iVar6] == param_1) goto LAB_004fa69e;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar5);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar5) {
    iVar5 = iVar5 + 1;
    piVar7 = (int *)operator_new(iVar5 * 4);
    if (piVar7 != (int *)0x0) {
      iVar6 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar5 <= iVar6) break;
          iVar8 = iVar6 + 1;
          piVar7[iVar6] = (this->unitsTaskedThisUpdate).value[iVar6];
          iVar6 = iVar8;
        } while (iVar8 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar7;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar5;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fa69e:
  *(int *)(maximumResourceDistance + 4) = param_2;
  iVar5 = requiredGatherAmount(this,param_2);
  if (param_3 == 1) {
    iVar5 = 10;
  }
  else {
    if (this->sn[0xcb] == 1) {
      if (pRVar3->master_obj->id == 0x3b) {
        iVar5 = __ftol();
      }
      else if (param_2 == 1) {
        iVar5 = 0x4b;
      }
      else if (param_2 == 3) {
        iVar5 = 0x32;
      }
      else if (param_2 == 2) {
        iVar5 = 0x32;
      }
    }
    else {
      iVar6 = this->sn[0x94];
      if ((iVar5 < this->sn[0x94]) || (iVar6 = this->sn[0x95], this->sn[0x95] < iVar5)) {
        iVar5 = iVar6;
      }
    }
    if (this->zoomingToNextAge == 1) {
      iVar5 = 0x14;
    }
  }
  *(int *)(maximumResourceDistance + 8) = iVar5;
  *(undefined4 *)(maximumResourceDistance + 0xc) = 0;
  (**(code **)(this->md->aiPlayer->_padding_ + 0x124))
            (param_1,iVar10,(int)pRVar3->owner->id,dropsiteID,rXPos);
  if (pRVar3->master_obj->id == 0x30) {
    taskElephantGatherers(this,param_1,this->sn[0xcc] + -1,iVar10);
  }
  if (pRVar3->master_obj->id == 0x32) {
    pTVar2 = this->md;
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

// Function: taskExplorer
// Address: 004fa820
/* WARNING: Variable defined which should be unmapped: targetPoint */
/* public: int __thiscall TribeTacticalAIModule::taskExplorer(int,int) */

int __thiscall
TribeTacticalAIModule::taskExplorer(TribeTacticalAIModule *this,int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  XYPoint targetPoint;
  int local_4;
  
  iVar1 = 0;
  iVar4 = (this->unitsTaskedThisUpdate).numberValue;
  if (0 < iVar4) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar1) break;
      if ((this->unitsTaskedThisUpdate).value[iVar1] == param_1) goto LAB_004fa8db;
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar4);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar4) {
    iVar4 = iVar4 + 1;
    piVar2 = (int *)operator_new(iVar4 * 4);
    if (piVar2 != (int *)0x0) {
      iVar1 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar4 <= iVar1) break;
          iVar3 = iVar1 + 1;
          piVar2[iVar1] = (this->unitsTaskedThisUpdate).value[iVar1];
          iVar1 = iVar3;
        } while (iVar3 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar2;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar4;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fa8db:
  if (param_2 == 1) {
    iVar1 = unexploredArea(this,param_1,(XYPoint *)&targetPoint.y);
    iVar4 = 1;
    if (iVar1 == 1) {
      iVar4 = taskExplorer(this,param_1,(float)targetPoint.y,(float)local_4,1);
      return iVar4;
    }
  }
  else {
    iVar4 = 0;
  }
  iVar4 = taskExplorer(this,param_1,-1.0,-1.0,iVar4);
  return iVar4;
}

// --------------------------------------------------

// Function: taskExplorer
// Address: 004fa940
/* WARNING: Variable defined which should be unmapped: targetPoint */
/* public: int __thiscall TribeTacticalAIModule::taskExplorer(int,float,float) */

int __thiscall
TribeTacticalAIModule::taskExplorer
          (TribeTacticalAIModule *this,int param_1,float param_2,float param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  XYPoint targetPoint;
  int local_4;
  
  iVar1 = 0;
  iVar4 = (this->unitsTaskedThisUpdate).numberValue;
  if (0 < iVar4) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar1) break;
      if ((this->unitsTaskedThisUpdate).value[iVar1] == param_1) goto LAB_004fa9fb;
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar4);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar4) {
    iVar4 = iVar4 + 1;
    piVar2 = (int *)operator_new(iVar4 * 4);
    if (piVar2 != (int *)0x0) {
      iVar1 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar4 <= iVar1) break;
          iVar3 = iVar1 + 1;
          piVar2[iVar1] = (this->unitsTaskedThisUpdate).value[iVar1];
          iVar1 = iVar3;
        } while (iVar3 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar2;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar4;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fa9fb:
  iVar4 = (this->civilians).numberValue;
  iVar1 = 0;
  if (0 < iVar4) {
    do {
      if ((this->civilians).maximumSizeValue <= iVar1) break;
      if ((this->civilians).value[iVar1] == param_1) {
        iVar4 = unexploredArea(this,param_1,(XYPoint *)&targetPoint.y);
        if (iVar4 == 1) {
          iVar4 = taskExplorer(this,param_1,(float)targetPoint.y,(float)local_4,1);
          return iVar4;
        }
        iVar4 = taskExplorer(this,param_1,param_2,param_3,1);
        return iVar4;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar4);
  }
  iVar4 = taskExplorer(this,param_1,param_2,param_3,0);
  return iVar4;
}

// --------------------------------------------------

// Function: taskExplorer
// Address: 004faaa0
/* public: int __thiscall TribeTacticalAIModule::taskExplorer(int,float,float,int) */

int __thiscall
TribeTacticalAIModule::taskExplorer
          (TribeTacticalAIModule *this,int param_1,float param_2,float param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar1 = (this->unitsTaskedThisUpdate).numberValue;
  if (0 < iVar1) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
      if ((this->unitsTaskedThisUpdate).value[iVar2] == param_1) goto LAB_004fab58;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar1 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (this->unitsTaskedThisUpdate).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar3;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar1;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fab58:
  if (param_4 == 1) {
    iVar1 = (this->civilianExplorers).numberValue;
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if ((this->civilianExplorers).maximumSizeValue <= iVar2) break;
        if ((this->civilianExplorers).value[iVar2] == param_1) goto LAB_004fac3b;
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    iVar1 = (this->civilianExplorers).numberValue;
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if ((this->civilianExplorers).maximumSizeValue <= iVar2) break;
        if ((this->civilianExplorers).value[iVar2] == param_1) goto LAB_004fac3b;
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    if ((this->civilianExplorers).maximumSizeValue + -1 < iVar1) {
      iVar1 = iVar1 + 1;
      piVar3 = (int *)operator_new(iVar1 * 4);
      if (piVar3 != (int *)0x0) {
        iVar2 = 0;
        if (0 < (this->civilianExplorers).maximumSizeValue) {
          do {
            if (iVar1 <= iVar2) break;
            iVar4 = iVar2 + 1;
            piVar3[iVar2] = (this->civilianExplorers).value[iVar2];
            iVar2 = iVar4;
          } while (iVar4 < (this->civilianExplorers).maximumSizeValue);
        }
        operator_delete((this->civilianExplorers).value);
        (this->civilianExplorers).value = piVar3;
        (this->civilianExplorers).maximumSizeValue = iVar1;
      }
    }
    (this->civilianExplorers).value[(this->civilianExplorers).numberValue] = param_1;
    (this->civilianExplorers).numberValue = (this->civilianExplorers).numberValue + 1;
LAB_004fac3b:
    removeGatherer(this,param_1);
  }
  piVar3 = (int *)this->md->_padding_;
  (**(code **)(*piVar3 + 0x30))
            ((int)*(short *)((int)piVar3 + 0x4a),param_1,0x2c1,0xffffffff,0xffffffff,param_2,param_3
             ,0xbf800000,0x3f800000,1,0,1);
  return 1;
}

// --------------------------------------------------

// Function: taskFollower
// Address: 004fac90
/* public: int __thiscall TribeTacticalAIModule::taskFollower(int,int,float,int) */

int __thiscall
TribeTacticalAIModule::taskFollower
          (TribeTacticalAIModule *this,int param_1,int param_2,float param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar1 = (this->unitsTaskedThisUpdate).numberValue;
  if (0 < iVar1) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
      if ((this->unitsTaskedThisUpdate).value[iVar2] == param_1) goto LAB_004fad48;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar1 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (this->unitsTaskedThisUpdate).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar3;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar1;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fad48:
  piVar3 = (int *)this->md->_padding_;
  (**(code **)(*piVar3 + 0x30))
            ((int)*(short *)((int)piVar3 + 0x4a),param_1,0x2c8,param_2,0xffffffff,0xbf800000,
             0xbf800000,0xbf800000,param_3,1,0,param_4);
  return 1;
}

// --------------------------------------------------

// Function: taskDefender
// Address: 004fada0
/* public: int __thiscall TribeTacticalAIModule::taskDefender(int,int,float,int) */

int __thiscall
TribeTacticalAIModule::taskDefender
          (TribeTacticalAIModule *this,int param_1,int param_2,float param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar1 = (this->unitsTaskedThisUpdate).numberValue;
  if (0 < iVar1) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
      if ((this->unitsTaskedThisUpdate).value[iVar2] == param_1) goto LAB_004fae58;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar1 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (this->unitsTaskedThisUpdate).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar3;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar1;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fae58:
  piVar3 = (int *)this->md->_padding_;
  (**(code **)(*piVar3 + 0x30))
            ((int)*(short *)((int)piVar3 + 0x4a),param_1,0x2bd,param_2,0xffffffff,0xbf800000,
             0xbf800000,0xbf800000,param_3,1,0,param_4);
  return 1;
}

// --------------------------------------------------

// Function: taskWaterExplorer
// Address: 004faeb0
/* public: int __thiscall TribeTacticalAIModule::taskWaterExplorer(int) */

int __thiscall TribeTacticalAIModule::taskWaterExplorer(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 == -1) {
    return 0;
  }
  iVar1 = (this->unitsTaskedThisUpdate).numberValue;
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
      if ((this->unitsTaskedThisUpdate).value[iVar2] == param_1) goto LAB_004faf74;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar1 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (this->unitsTaskedThisUpdate).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar3;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar1;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004faf74:
  piVar3 = (int *)this->md->_padding_;
  (**(code **)(*piVar3 + 0x30))
            ((int)*(short *)((int)piVar3 + 0x4a),param_1,0x2c1,0xffffffff,0xffffffff,0xbf800000,
             0xbf800000,0xbf800000,0x3f800000,1,0,1);
  return 1;
}

// --------------------------------------------------

// Function: taskWaterTrader
// Address: 004fafc0
/* WARNING: Variable defined which should be unmapped: targetObj */
/* public: int __thiscall TribeTacticalAIModule::taskWaterTrader(int,int) */

int __thiscall
TribeTacticalAIModule::taskWaterTrader(TribeTacticalAIModule *this,int param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  RGE_Static_Object *pRVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  RGE_Static_Object *targetObj;
  
  pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if ((param_1 != -1) && (pRVar1 != (RGE_Static_Object *)0x0)) {
    pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_2);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      uVar3 = __ftol();
      uVar4 = __ftol();
      uVar5 = __ftol();
      uVar11 = 0xffffffff;
      iVar10 = 1;
      iVar6 = (**(code **)(pRVar1->_padding_ + 0x198))
                        (uVar3,uVar4,uVar5,0x40000000,param_2,0,1,0xffffffff,0xffffffff);
      if (iVar6 != 0) {
        iVar6 = (this->unitsTaskedThisUpdate).numberValue;
        iVar7 = 0;
        if (0 < iVar6) {
          do {
            if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar7) break;
            if ((this->unitsTaskedThisUpdate).value[iVar7] == iVar10) goto LAB_004fb111;
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar6);
        }
        if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar6) {
          iVar6 = iVar6 + 1;
          piVar8 = (int *)operator_new(iVar6 * 4);
          if (piVar8 != (int *)0x0) {
            iVar7 = 0;
            if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
              do {
                if (iVar6 <= iVar7) break;
                iVar9 = iVar7 + 1;
                piVar8[iVar7] = (this->unitsTaskedThisUpdate).value[iVar7];
                iVar7 = iVar9;
              } while (iVar9 < (this->unitsTaskedThisUpdate).maximumSizeValue);
            }
            operator_delete((this->unitsTaskedThisUpdate).value);
            (this->unitsTaskedThisUpdate).value = piVar8;
            (this->unitsTaskedThisUpdate).maximumSizeValue = iVar6;
          }
        }
        (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = iVar10;
        (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fb111:
        (**(code **)(this->md->aiPlayer->_padding_ + 0x124))
                  (iVar10,uVar11,(int)*(short *)(*(int *)(param_2 + 0xc) + 0x4a),
                   *(undefined4 *)(param_2 + 0x38),*(undefined4 *)(param_2 + 0x3c));
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: taskWaterFisher
// Address: 004fb160
/* public: int __thiscall TribeTacticalAIModule::taskWaterFisher(int,int,float,float) */

int __thiscall
TribeTacticalAIModule::taskWaterFisher
          (TribeTacticalAIModule *this,int param_1,int param_2,float param_3,float param_4)
{
  RGE_Static_Object *pRVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if ((param_1 != -1) && (pRVar1 != (RGE_Static_Object *)0x0)) {
    uVar2 = __ftol();
    uVar3 = __ftol();
    uVar11 = 0xffffffff;
    uVar10 = 0xffffffff;
    uVar9 = 1;
    iVar8 = 0;
    iVar4 = (**(code **)(pRVar1->_padding_ + 0x198))
                      (uVar2,uVar3,1,0x3f800000,0xffffffff,0,1,0xffffffff,0xffffffff);
    if (iVar4 != 0) {
      iVar4 = (this->unitsTaskedThisUpdate).numberValue;
      iVar5 = 0;
      if (0 < iVar4) {
        do {
          if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar5) break;
          if ((this->unitsTaskedThisUpdate).value[iVar5] == iVar8) goto LAB_004fb288;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
      if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar4) {
        iVar4 = iVar4 + 1;
        piVar6 = (int *)operator_new(iVar4 * 4);
        if (piVar6 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
            do {
              if (iVar4 <= iVar5) break;
              iVar7 = iVar5 + 1;
              piVar6[iVar5] = (this->unitsTaskedThisUpdate).value[iVar5];
              iVar5 = iVar7;
            } while (iVar7 < (this->unitsTaskedThisUpdate).maximumSizeValue);
          }
          operator_delete((this->unitsTaskedThisUpdate).value);
          (this->unitsTaskedThisUpdate).value = piVar6;
          (this->unitsTaskedThisUpdate).maximumSizeValue = iVar4;
        }
      }
      (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = iVar8;
      (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fb288:
      (**(code **)(this->md->aiPlayer->_padding_ + 0x124))(iVar8,uVar9,0,uVar10,uVar11);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: taskAttacker
// Address: 004fb2d0
/* public: int __thiscall TribeTacticalAIModule::taskAttacker(int,float,float,int,int,struct
   Waypoint *,int,int,int) */

int __thiscall
TribeTacticalAIModule::taskAttacker
          (TribeTacticalAIModule *this,int param_1,float param_2,float param_3,int param_4,
          int param_5,Waypoint *param_6,int param_7,int param_8,int param_9)
{
  uchar uVar1;
  uchar uVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  float10 fVar9;
  float fVar10;
  
  if (((param_1 == -1) ||
      (this_00 = RGE_Game_World::object(*(RGE_Game_World **)(this->md->_padding_ + 0x3c),param_1),
      this_00 == (RGE_Static_Object *)0x0)) ||
     (pUVar3 = RGE_Static_Object::unitAI(this_00), pUVar3 == (UnitAIModule *)0x0)) {
    return 0;
  }
  if ((param_6 != (Waypoint *)0x0) && (0 < param_7)) {
    do {
      uVar1 = __ftol();
      uVar2 = __ftol();
      addWaypoint(this,param_1,uVar2,uVar1);
      param_7 = param_7 + -1;
    } while (param_7 != 0);
  }
  if (param_4 == -1) {
    fVar10 = RGE_Static_Object::distance_to_position(this_00,param_2,param_3,1.0);
    iVar6 = calculatePriority(this,fVar10);
    moveUnit(this,param_1,param_2,param_3,iVar6);
  }
  else {
    pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(this->md->_padding_ + 0x3c),param_4);
    if (pRVar4 == (RGE_Static_Object *)0x0) {
      return 0;
    }
    fVar10 = RGE_Static_Object::distance_to_object(this_00,pRVar4);
    iVar5 = calculatePriority(this,fVar10);
    iVar6 = this->md->_padding_;
    iVar7 = *(int *)this->md->_padding_;
    fVar9 = (float10)(**(code **)(this_00->_padding_ + 0x10c))(1,0,iVar5);
    (**(code **)(iVar7 + 0x30))
              ((int)*(short *)(iVar6 + 0x4a),param_1,(-(uint)(param_9 != 1) & 0xffffffe3) + 0x2d9,
               param_4,param_5,param_2,param_3,0x3f800000,(float)fVar9);
  }
  iVar6 = (this->unitsTaskedThisUpdate).numberValue;
  iVar7 = 0;
  if (0 < iVar6) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar7) break;
      if ((this->unitsTaskedThisUpdate).value[iVar7] == param_1) {
        return 1;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar6);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar6) {
    iVar6 = iVar6 + 1;
    piVar8 = (int *)operator_new(iVar6 * 4);
    if (piVar8 != (int *)0x0) {
      iVar7 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar6 <= iVar7) break;
          iVar5 = iVar7 + 1;
          piVar8[iVar7] = (this->unitsTaskedThisUpdate).value[iVar7];
          iVar7 = iVar5;
        } while (iVar5 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar8;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar6;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
  return 1;
}

// --------------------------------------------------

// Function: taskDefender
// Address: 004fb500
// [HELPER] s_ERROR__Unused_taskDefender_call_: "ERROR: Unused taskDefender call 2: defender=%d, target=(%f, %f)."
/* public: int __thiscall TribeTacticalAIModule::taskDefender(int,int) */

int __thiscall
TribeTacticalAIModule::taskDefender(TribeTacticalAIModule *this,int param_1,int param_2)
{
  AIModule::logCommonHistory
            ((AIModule *)this,(char *)this,s_ERROR__Unused_taskDefender_call_,param_1,param_2);
  return 0;
}

// --------------------------------------------------

// Function: taskDefender
// Address: 004fb520
// [HELPER] s_ERROR__Unused_taskDefender_call_: "ERROR: Unused taskDefender call 2: defender=%d, target=(%f, %f)."
/* public: int __thiscall TribeTacticalAIModule::taskDefender(int,float,float) */

int __thiscall
TribeTacticalAIModule::taskDefender
          (TribeTacticalAIModule *this,int param_1,float param_2,float param_3)
{
  AIModule::logCommonHistory
            ((AIModule *)this,(char *)this,s_ERROR__Unused_taskDefender_call_,param_1,
             (double)param_2,(double)param_3);
  return 0;
}

// --------------------------------------------------

// Function: taskTrain
// Address: 004fb550
// [HELPER] s_Could_not_find_a_building_to_tra: "Could not find a building to train type %d (UniqueID=%d) at, returning FALSE."
// [HELPER] s_Invalid_taskTrain_item__returnin: "Invalid taskTrain item, returning FALSE."
// [HELPER] s_Training_ID___d__UniqueID__d__fr: "Training ID #%d (UniqueID=%d) from building with gameID=%d."
/* public: int __thiscall TribeTacticalAIModule::taskTrain(class BuildItem *) */

int __thiscall TribeTacticalAIModule::taskTrain(TribeTacticalAIModule *this,BuildItem *param_1)
{
  int iVar1;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar2;
  int *piVar3;
  AIModule *this_01;
  AIModule *this_02;
  int iVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  
  if (param_1 == (BuildItem *)0x0) {
    AIModule::logCommonHistory((AIModule *)this,(char *)this,s_Invalid_taskTrain_item__returnin);
    return 0;
  }
  iVar8 = 2;
  iVar6 = 0x26c;
  iVar5 = 0x26b;
  iVar4 = -1;
  iVar1 = BuildItem::buildFrom(param_1);
  this_00 = MainDecisionAIModule::object
                      ((MainDecisionAIModule *)this->md,-1,iVar1,iVar4,iVar5,iVar6,iVar8);
  if ((this_00 == (RGE_Static_Object *)0x0) ||
     (pUVar2 = RGE_Static_Object::unitAI(this_00), pUVar2 == (UnitAIModule *)0x0)) {
    iVar1 = BaseItem::uniqueID((BaseItem *)param_1);
    iVar4 = BaseItem::typeID((BaseItem *)param_1);
    AIModule::logCommonHistory(this_02,(char *)this,s_Could_not_find_a_building_to_tra,iVar4,iVar1);
    return 0;
  }
  lVar7 = this_00->id;
  iVar1 = BaseItem::uniqueID((BaseItem *)param_1);
  iVar4 = BaseItem::typeID((BaseItem *)param_1);
  AIModule::logCommonHistory
            (this_01,(char *)this,s_Training_ID___d__UniqueID__d__fr,iVar4,iVar1,lVar7);
  BuildItem::setInProgress(param_1,1);
  BuildItem::setBuilt(param_1,0);
  iVar1 = (this->unitsTaskedThisUpdate).numberValue;
  iVar4 = this_00->id;
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar5) break;
      if ((this->unitsTaskedThisUpdate).value[iVar5] == iVar4) goto LAB_004fb6a7;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar5 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar1 <= iVar5) break;
          iVar6 = iVar5 + 1;
          piVar3[iVar5] = (this->unitsTaskedThisUpdate).value[iVar5];
          iVar5 = iVar6;
        } while (iVar6 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar3;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar1;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = iVar4;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fb6a7:
  iVar1 = this->md->aiPlayer->_padding_;
  iVar4 = BaseItem::uniqueID((BaseItem *)param_1);
  lVar7 = this_00->id;
  iVar5 = BaseItem::typeID((BaseItem *)param_1);
  (**(code **)(iVar1 + 0x108))(iVar5,lVar7,iVar4);
  return 1;
}

// --------------------------------------------------

// Function: taskResearch
// Address: 004fb710
// [HELPER] s_Could_not_find_a_building_to_res: "Could not find a building to research type %d (UniqueID=%d) at, returning FALSE."
// [HELPER] s_Invalid_taskResearch_item__retur: "Invalid taskResearch item, returning FALSE."
// [HELPER] s_Researching_ID___d__UniqueID__d_: "Researching ID #%d (UniqueID=%d) from building with gameID=%d."
/* public: int __thiscall TribeTacticalAIModule::taskResearch(class BuildItem *) */

int __thiscall TribeTacticalAIModule::taskResearch(TribeTacticalAIModule *this,BuildItem *param_1)
{
  int iVar1;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar2;
  int *piVar3;
  AIModule *this_01;
  AIModule *this_02;
  int iVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  
  if (param_1 == (BuildItem *)0x0) {
    AIModule::logCommonHistory((AIModule *)this,(char *)this,s_Invalid_taskResearch_item__retur);
    return 0;
  }
  iVar8 = 2;
  iVar6 = 0x26c;
  iVar5 = 0x26b;
  iVar4 = -1;
  iVar1 = BuildItem::buildFrom(param_1);
  this_00 = MainDecisionAIModule::object
                      ((MainDecisionAIModule *)this->md,-1,iVar1,iVar4,iVar5,iVar6,iVar8);
  if ((this_00 == (RGE_Static_Object *)0x0) ||
     (pUVar2 = RGE_Static_Object::unitAI(this_00), pUVar2 == (UnitAIModule *)0x0)) {
    iVar1 = BaseItem::uniqueID((BaseItem *)param_1);
    iVar4 = BaseItem::typeID((BaseItem *)param_1);
    AIModule::logCommonHistory(this_02,(char *)this,s_Could_not_find_a_building_to_res,iVar4,iVar1);
    return 0;
  }
  lVar7 = this_00->id;
  iVar1 = BaseItem::uniqueID((BaseItem *)param_1);
  iVar4 = BaseItem::typeID((BaseItem *)param_1);
  AIModule::logCommonHistory
            (this_01,(char *)this,s_Researching_ID___d__UniqueID__d_,iVar4,iVar1,lVar7);
  BuildItem::setInProgress(param_1,1);
  BuildItem::setBuilt(param_1,0);
  iVar1 = (this->unitsTaskedThisUpdate).numberValue;
  iVar4 = this_00->id;
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar5) break;
      if ((this->unitsTaskedThisUpdate).value[iVar5] == iVar4) goto LAB_004fb867;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar5 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar1 <= iVar5) break;
          iVar6 = iVar5 + 1;
          piVar3[iVar5] = (this->unitsTaskedThisUpdate).value[iVar5];
          iVar5 = iVar6;
        } while (iVar6 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar3;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar1;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = iVar4;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fb867:
  iVar1 = this->md->aiPlayer->_padding_;
  iVar4 = BaseItem::uniqueID((BaseItem *)param_1);
  lVar7 = this_00->id;
  iVar5 = BaseItem::typeID((BaseItem *)param_1);
  (**(code **)(iVar1 + 0x114))(iVar5,lVar7,iVar4);
  return 1;
}

// --------------------------------------------------

// Function: taskToEnter
// Address: 004fb8d0
/* public: int __thiscall TribeTacticalAIModule::taskToEnter(int,int) */

int __thiscall
TribeTacticalAIModule::taskToEnter(TribeTacticalAIModule *this,int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == -1) {
    return 0;
  }
  iVar4 = (this->unitsTaskedThisUpdate).numberValue;
  iVar1 = 0;
  if (0 < iVar4) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar1) break;
      if ((this->unitsTaskedThisUpdate).value[iVar1] == param_1) goto LAB_004fb994;
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar4);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar4) {
    iVar4 = iVar4 + 1;
    piVar2 = (int *)operator_new(iVar4 * 4);
    if (piVar2 != (int *)0x0) {
      iVar1 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar4 <= iVar1) break;
          iVar3 = iVar1 + 1;
          piVar2[iVar1] = (this->unitsTaskedThisUpdate).value[iVar1];
          iVar1 = iVar3;
        } while (iVar3 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar2;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar4;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fb994:
  piVar2 = (int *)this->md->_padding_;
  iVar4 = (int)*(short *)((int)piVar2 + 0x4a);
  (**(code **)(*piVar2 + 0x30))
            (iVar4,param_1,0x2cd,param_2,iVar4,0xbf800000,0xbf800000,0xbf800000,0x3f800000,1,0,100);
  return 1;
}

// --------------------------------------------------

// Function: taskTransporter
// Address: 004fb9e0
/* public: int __thiscall TribeTacticalAIModule::taskTransporter(int,float,float) */

int __thiscall
TribeTacticalAIModule::taskTransporter
          (TribeTacticalAIModule *this,int param_1,float param_2,float param_3)
{
  RGE_Static_Object *this_00;
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  
  this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if ((param_1 == -1) || (this_00 == (RGE_Static_Object *)0x0)) {
    return 0;
  }
  fVar6 = RGE_Static_Object::distance_to_position(this_00,param_2,param_3,1.0);
  iVar1 = calculatePriority(this,fVar6);
  iVar5 = (this->unitsTaskedThisUpdate).numberValue;
  iVar2 = 0;
  if (0 < iVar5) {
    do {
      if ((this->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
      if ((this->unitsTaskedThisUpdate).value[iVar2] == param_1) goto LAB_004fbadf;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar5);
  }
  if ((this->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar5) {
    iVar5 = iVar5 + 1;
    piVar3 = (int *)operator_new(iVar5 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar5 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (this->unitsTaskedThisUpdate).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (this->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((this->unitsTaskedThisUpdate).value);
      (this->unitsTaskedThisUpdate).value = piVar3;
      (this->unitsTaskedThisUpdate).maximumSizeValue = iVar5;
    }
  }
  (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = param_1;
  (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fbadf:
  piVar3 = (int *)this->md->_padding_;
  iVar5 = (int)*(short *)((int)piVar3 + 0x4a);
  (**(code **)(*piVar3 + 0x30))
            (iVar5,param_1,0x2ca,0xffffffff,iVar5,param_2,param_3,0x3f800000,0x3f800000,1,0,iVar1);
  return 1;
}

// --------------------------------------------------

// Function: removeFromTaskLists
// Address: 004fbb30
/* public: void __thiscall TribeTacticalAIModule::removeFromTaskLists(int) */

void __thiscall TribeTacticalAIModule::removeFromTaskLists(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  UnitData *pUVar4;
  int *piVar5;
  
  iVar1 = 0;
  iVar2 = (this->civilianExplorers).maximumSizeValue;
  if (0 < iVar2) {
    piVar5 = (this->civilianExplorers).value;
    do {
      if (*piVar5 == param_1) break;
      iVar1 = iVar1 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar1 < iVar2);
  }
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar5 = (this->civilianExplorers).value;
        iVar2 = iVar1 + 1;
        piVar5[iVar1] = piVar5[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (this->civilianExplorers).maximumSizeValue + -1);
    }
    iVar2 = (this->civilianExplorers).numberValue + -1;
    (this->civilianExplorers).numberValue = iVar2;
    if (iVar2 < 0) {
      (this->civilianExplorers).numberValue = 0;
    }
  }
  removeGatherer(this,param_1);
  this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if ((this_00 != (RGE_Static_Object *)0x0) &&
     (pUVar3 = RGE_Static_Object::unitAI(this_00), pUVar3 != (UnitAIModule *)0x0)) {
    pUVar3 = RGE_Static_Object::unitAI(this_00);
    iVar2 = UnitAIModule::currentAction(pUVar3);
    if (iVar2 != 0x261) {
      pUVar3 = RGE_Static_Object::unitAI(this_00);
      iVar2 = UnitAIModule::currentAction(pUVar3);
      if (iVar2 != 0x265) {
        return;
      }
    }
    pUVar4 = gatherer(this,param_1);
    if (pUVar4 != (UnitData *)0x0) {
      this->actualGathererDistribution[pUVar4->data1] =
           this->actualGathererDistribution[pUVar4->data1] + -1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: calculatePriority
// Address: 004fbc10
/* public: int __thiscall TribeTacticalAIModule::calculatePriority(float) */

int __thiscall TribeTacticalAIModule::calculatePriority(TribeTacticalAIModule *this,float param_1)
{
  int iVar1;
  
  iVar1 = __ftol();
  if (99 < iVar1) {
    iVar1 = 99;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: setupSoldierGroups
// Address: 004fbc30
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Variable defined which should be unmapped: numPotentialAGroups */
/* public: void __thiscall TribeTacticalAIModule::setupSoldierGroups(void) */

void __thiscall TribeTacticalAIModule::setupSoldierGroups(TribeTacticalAIModule *this)
{
  ulong uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  RGE_Static_Object *pRVar8;
  RGE_Static_Object *pRVar9;
  TacticalAIGroup *pTVar10;
  undefined4 *unaff_FS_OFFSET;
  int numPotentialAGroups;
  int newArtifact;
  int i;
  int numAGroups;
  int numDGroups;
  int numEGroups;
  int local_24;
  ManagedArray<int> groupsToRemove;
  int local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00560b48;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  groupsToRemove.numberValue = 0;
  groupsToRemove.desiredNumberValue = 0;
  groupsToRemove.maximumSizeValue = 0;
  local_10 = 0;
  pTVar10 = (this->groups).next;
  local_4 = 0;
  for (; (pTVar10 != &this->groups && (pTVar10 != (TacticalAIGroup *)0x0)); pTVar10 = pTVar10->next)
{
    iVar2 = TacticalAIGroup::numberUnits(pTVar10);
    if (iVar2 == 0) {
      iVar2 = TacticalAIGroup::id(pTVar10);
      iVar3 = 0;
      piVar5 = (int *)groupsToRemove.numberValue;
      if (0 < groupsToRemove.desiredNumberValue) {
        do {
          if (-1 < iVar3) break;
          if (*piVar5 == iVar2) goto LAB_004fbcda;
          iVar3 = iVar3 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar3 < groupsToRemove.desiredNumberValue);
      }
      if (-1 < groupsToRemove.desiredNumberValue) {
        ManagedArray<int>::resize
                  ((ManagedArray<int> *)&groupsToRemove.numberValue,
                   groupsToRemove.desiredNumberValue + 1);
      }
      *(int *)(groupsToRemove.numberValue + groupsToRemove.desiredNumberValue * 4) = iVar2;
      groupsToRemove.desiredNumberValue = groupsToRemove.desiredNumberValue + 1;
    }
LAB_004fbcda:
  }
  uVar1 = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
  if ((600 < (uVar1 - this->lastGroupAttackTime) / 1000) &&
     (600 < (uVar1 - this->lastGroupRebalanceTime) / 1000)) {
    pTVar10 = (this->groups).next;
    this->lastGroupRebalanceTime = uVar1;
    for (; (pTVar10 != &this->groups && (pTVar10 != (TacticalAIGroup *)0x0));
        pTVar10 = pTVar10->next) {
      iVar2 = TacticalAIGroup::type(pTVar10);
      if (iVar2 == 100) {
        iVar2 = TacticalAIGroup::id(pTVar10);
        iVar3 = 0;
        piVar5 = (int *)groupsToRemove.numberValue;
        if (0 < groupsToRemove.desiredNumberValue) {
          do {
            if (-1 < iVar3) break;
            if (*piVar5 == iVar2) goto LAB_004fbda8;
            iVar3 = iVar3 + 1;
            piVar5 = piVar5 + 1;
          } while (iVar3 < groupsToRemove.desiredNumberValue);
        }
        if (-1 < groupsToRemove.desiredNumberValue) {
          ManagedArray<int>::resize
                    ((ManagedArray<int> *)&groupsToRemove.numberValue,
                     groupsToRemove.desiredNumberValue + 1);
        }
        *(int *)(groupsToRemove.numberValue + groupsToRemove.desiredNumberValue * 4) = iVar2;
        groupsToRemove.desiredNumberValue = groupsToRemove.desiredNumberValue + 1;
      }
LAB_004fbda8:
    }
  }
  numAGroups = 0;
  if (0 < groupsToRemove.desiredNumberValue) {
    do {
      if (local_10 + -1 < numAGroups) {
        pvVar4 = operator_new(numAGroups * 4 + 4);
        if (pvVar4 != (void *)0x0) {
          iVar2 = 0;
          if (0 < local_10) {
            do {
              if (numAGroups + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar4 + iVar2 * 4 + -4) =
                   *(undefined4 *)(groupsToRemove.numberValue + -4 + iVar2 * 4);
            } while (iVar2 < local_10);
          }
          operator_delete((void *)groupsToRemove.numberValue);
          groupsToRemove.numberValue = (int)pvVar4;
          local_10 = numAGroups + 1;
        }
      }
      removeGroup(this,*(int *)(groupsToRemove.numberValue + numAGroups * 4));
      numAGroups = numAGroups + 1;
    } while (numAGroups < groupsToRemove.desiredNumberValue);
  }
  if (((this->soldiers).maximumSizeValue + -1 < 0) &&
     (piVar5 = (int *)operator_new(4), piVar5 != (int *)0x0)) {
    iVar2 = 0;
    if (0 < (this->soldiers).maximumSizeValue) {
      do {
        if (0 < iVar2) break;
        iVar3 = iVar2 + 1;
        piVar5[iVar2] = (this->soldiers).value[iVar2];
        iVar2 = iVar3;
      } while (iVar3 < (this->soldiers).maximumSizeValue);
    }
    operator_delete((this->soldiers).value);
    (this->soldiers).value = piVar5;
    (this->soldiers).maximumSizeValue = 1;
  }
  iVar2 = TribeInformationAIModule::fullyExploredZone
                    (&this->md->informationAI,*(this->soldiers).value);
  if (iVar2 == 0) {
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
    removeAllGroups(this,0x66);
    setStrategicNumber(this,0x2a,0);
  }
  iVar3 = numberGroups(this,100,-1);
                    /* language.dll match for 0x65: "1" */
  numEGroups = numberGroups(this,0x65,-1);
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
  local_24 = numberGroups(this,0x66,-1);
  numberGroups(this,0x6d,-1);
  numberUngroupedArtifacts(this);
  iVar2 = (this->workingArea).numberValue;
  while (0 < iVar2) {
    if ((this->workingArea).maximumSizeValue + -1 < numAGroups) {
      iVar2 = numAGroups + 1;
      piVar5 = (int *)operator_new(iVar2 * 4);
      if (piVar5 != (int *)0x0) {
        iVar6 = 0;
        if (0 < (this->workingArea).maximumSizeValue) {
          do {
            if (iVar2 <= iVar6) break;
            iVar7 = iVar6 + 1;
            piVar5[iVar6] = (this->workingArea).value[iVar6];
            iVar6 = iVar7;
          } while (iVar7 < (this->workingArea).maximumSizeValue);
        }
        operator_delete((this->workingArea).value);
        (this->workingArea).value = piVar5;
        (this->workingArea).maximumSizeValue = iVar2;
      }
    }
    iVar2 = (this->workingArea).value[numAGroups];
    pRVar8 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar2);
    if (pRVar8 == (RGE_Static_Object *)0x0) {
      iVar6 = (this->workingArea).maximumSizeValue;
      iVar7 = 0;
      if (0 < iVar6) {
        piVar5 = (this->workingArea).value;
        do {
          if (*piVar5 == iVar2) break;
          iVar7 = iVar7 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar7 < iVar6);
      }
      if (iVar7 < iVar6) {
        if (iVar7 < iVar6 + -1) {
          do {
            piVar5 = (this->workingArea).value;
            iVar2 = iVar7 + 1;
            piVar5[iVar7] = piVar5[iVar2];
            iVar7 = iVar2;
          } while (iVar2 < (this->workingArea).maximumSizeValue + -1);
        }
LAB_004fc050:
        iVar2 = (this->workingArea).numberValue + -1;
        (this->workingArea).numberValue = iVar2;
joined_r0x004fc13d:
        if (iVar2 < 0) {
          (this->workingArea).numberValue = 0;
        }
      }
    }
    else {
      pRVar9 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
      if (pRVar9 == (RGE_Static_Object *)0x0) {
        iVar6 = (this->workingArea).maximumSizeValue;
        iVar7 = 0;
        if (0 < iVar6) {
          piVar5 = (this->workingArea).value;
          do {
            if (*piVar5 == iVar2) break;
            iVar7 = iVar7 + 1;
            piVar5 = piVar5 + 1;
          } while (iVar7 < iVar6);
        }
        if (iVar7 < iVar6) {
          if (iVar7 < iVar6 + -1) {
            do {
              piVar5 = (this->workingArea).value;
              iVar2 = iVar7 + 1;
              piVar5[iVar7] = piVar5[iVar2];
              iVar7 = iVar2;
            } while (iVar2 < (this->workingArea).maximumSizeValue + -1);
          }
          goto LAB_004fc050;
        }
      }
      else {
        pTVar10 = createGroup(this,1);
        if (pTVar10 == (TacticalAIGroup *)0x0) break;
        TacticalAIGroup::setType(pTVar10,0x6d);
        TacticalAIGroup::setDesiredNumberUnits(pTVar10,1);
        TacticalAIGroup::addUnit(pTVar10,iVar2,this->md);
        TacticalAIGroup::setSpecificCommander(pTVar10,iVar2,this->md);
        TacticalAIGroup::setLocation(pTVar10,pRVar8->world_x,pRVar8->world_y,pRVar8->world_z);
        TacticalAIGroup::setGatherLocation(pTVar10,pRVar8->world_x,pRVar8->world_y,pRVar8->world_z);
        TacticalAIGroup::setRetreatLocation(pTVar10,pRVar9->world_x,pRVar9->world_y,pRVar9->world_z)
        ;
        iVar6 = (this->workingArea).maximumSizeValue;
        iVar7 = 0;
        if (0 < iVar6) {
          piVar5 = (this->workingArea).value;
          do {
            if (*piVar5 == iVar2) break;
            iVar7 = iVar7 + 1;
            piVar5 = piVar5 + 1;
          } while (iVar7 < iVar6);
        }
        if (iVar7 < iVar6) {
          if (iVar7 < iVar6 + -1) {
            do {
              piVar5 = (this->workingArea).value;
              iVar2 = iVar7 + 1;
              piVar5[iVar7] = piVar5[iVar2];
              iVar7 = iVar2;
            } while (iVar2 < (this->workingArea).maximumSizeValue + -1);
          }
          iVar2 = (this->workingArea).numberValue + -1;
          (this->workingArea).numberValue = iVar2;
          goto joined_r0x004fc13d;
        }
      }
    }
    iVar2 = (this->workingArea).numberValue;
  }
  i = 0;
  numAGroups = 0;
  if (this->sn[0x28] == 0) {
    ceil((double)(this->soldiers).numberValue / (double)this->sn[0x10]);
    newArtifact = __ftol();
    if (this->sn[0x24] < newArtifact) {
      newArtifact = this->sn[0x24];
    }
    iVar2 = newArtifact * this->sn[0x10];
    groupsToRemove.value = (int *)((this->soldiers).numberValue - iVar2);
    if ((int)groupsToRemove.value < 1) goto LAB_004fc280;
    ceil((double)(int)groupsToRemove.value / (double)this->sn[0x19]);
    i = __ftol();
    if (this->sn[0x26] < i) {
      i = this->sn[0x26];
    }
    groupsToRemove.value = (int *)(((this->soldiers).numberValue - i * this->sn[0x19]) - iVar2);
    if ((int)groupsToRemove.value < 1) goto LAB_004fc280;
    ceil((double)(int)groupsToRemove.value / (double)this->sn[0x2b]);
    numAGroups = __ftol();
    iVar6 = this->sn[0x2a];
    if (numAGroups <= iVar6) goto LAB_004fc280;
  }
  else {
    iVar2 = (this->soldiers).numberValue;
    newArtifact = iVar2;
    if (this->sn[0x24] <= iVar2) {
      newArtifact = this->sn[0x24];
    }
    iVar2 = iVar2 - newArtifact;
    if (iVar2 < 1) goto LAB_004fc280;
    i = this->sn[0x26];
    if (iVar2 < this->sn[0x26]) {
      i = iVar2;
    }
    iVar2 = iVar2 - i;
    if ((iVar2 < 1) || (iVar6 = this->sn[0x2a], numAGroups = iVar2, iVar2 < iVar6))
    goto LAB_004fc280;
  }
  numAGroups = iVar6;
LAB_004fc280:
  if (this->sn[0xa2] == 1) {
    newArtifact = 0;
  }
  for (; iVar3 < newArtifact; iVar3 = iVar3 + 1) {
    pTVar10 = (TacticalAIGroup *)0x0;
    if (numEGroups < 1) {
LAB_004fc2d8:
      if (pTVar10 == (TacticalAIGroup *)0x0) goto LAB_004fc2dc;
    }
    else {
                    /* language.dll match for 0x65: "1" */
      pTVar10 = group(this,-1,0x65,-1,-1);
      if (pTVar10 != (TacticalAIGroup *)0x0) {
        numEGroups = numEGroups + -1;
        goto LAB_004fc2d8;
      }
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
      pTVar10 = group(this,-1,0x66,-1,-1);
      if (pTVar10 != (TacticalAIGroup *)0x0) {
        local_24 = local_24 + -1;
        goto LAB_004fc2d8;
      }
LAB_004fc2dc:
      pTVar10 = createGroup(this,1);
      if (pTVar10 == (TacticalAIGroup *)0x0) break;
    }
    TacticalAIGroup::setType(pTVar10,100);
    TacticalAIGroup::setTarget(pTVar10,-1);
    TacticalAIGroup::setTargetType(pTVar10,-1);
    TacticalAIGroup::setAction(pTVar10,1);
    TacticalAIGroup::setInUse(pTVar10,0);
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x2560);
    iVar2 = iVar2 % (this->sn[0x62] + 1) + this->sn[0x10];
    if (this->sn[0x1a] < iVar2) {
      iVar2 = this->sn[0x1a];
    }
    TacticalAIGroup::setDesiredNumberUnits(pTVar10,iVar2);
  }
  while ((newArtifact < iVar3 &&
         ((pTVar10 = group(this,-1,100,0,-1), pTVar10 != (TacticalAIGroup *)0x0 ||
          (pTVar10 = group(this,-1,100,1,-1), pTVar10 != (TacticalAIGroup *)0x0))))) {
    iVar2 = TacticalAIGroup::id(pTVar10);
    removeGroup(this,iVar2);
    iVar3 = iVar3 + -1;
  }
  for (; numEGroups < i; numEGroups = numEGroups + 1) {
    pTVar10 = (TacticalAIGroup *)0x0;
    if (local_24 < 1) {
LAB_004fc3db:
      if (pTVar10 == (TacticalAIGroup *)0x0) goto LAB_004fc3df;
    }
    else {
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
      pTVar10 = group(this,-1,0x66,-1,-1);
      if (pTVar10 != (TacticalAIGroup *)0x0) {
        local_24 = local_24 + -1;
        goto LAB_004fc3db;
      }
LAB_004fc3df:
      pTVar10 = createGroup(this,1);
      if (pTVar10 == (TacticalAIGroup *)0x0) break;
    }
                    /* language.dll match for 0x65: "1" */
    TacticalAIGroup::setType(pTVar10,0x65);
    TacticalAIGroup::setTarget(pTVar10,-1);
    TacticalAIGroup::setTargetType(pTVar10,-1);
    TacticalAIGroup::setAction(pTVar10,1);
    TacticalAIGroup::setInUse(pTVar10,0);
    TacticalAIGroup::setDesiredNumberUnits(pTVar10,this->sn[0x19]);
  }
                    /* language.dll match for 0x65: "1" */
  while ((i < numEGroups && (pTVar10 = group(this,-1,0x65,-1,-1), pTVar10 != (TacticalAIGroup *)0x0)
         )) {
    iVar2 = TacticalAIGroup::id(pTVar10);
    removeGroup(this,iVar2);
    numEGroups = numEGroups + -1;
  }
  while ((local_24 < numAGroups &&
         (pTVar10 = createGroup(this,1), pTVar10 != (TacticalAIGroup *)0x0))) {
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
    TacticalAIGroup::setType(pTVar10,0x66);
    TacticalAIGroup::setDesiredNumberUnits(pTVar10,this->sn[0x2b]);
    local_24 = local_24 + 1;
  }
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
  while ((numAGroups < local_24 &&
         (pTVar10 = group(this,-1,0x66,-1,-1), pTVar10 != (TacticalAIGroup *)0x0))) {
    iVar2 = TacticalAIGroup::id(pTVar10);
    removeGroup(this,iVar2);
    local_24 = local_24 + -1;
  }
  local_4 = 0xffffffff;
  if (groupsToRemove.numberValue != 0) {
    operator_delete((void *)groupsToRemove.numberValue);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: fillSoldierGroups
// Address: 004fc500
/* WARNING: Variable defined which should be unmapped: unitZone */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TribeTacticalAIModule::fillSoldierGroups(void) */

void __thiscall TribeTacticalAIModule::fillSoldierGroups(TribeTacticalAIModule *this)
{
  undefined1 *puVar1;
  TacticalAIGroup *pTVar2;
  byte bVar3;
  uchar uVar4;
  uchar uVar5;
  int iVar6;
  int iVar7;
  Waypoint *pWVar8;
  int *piVar9;
  RGE_Static_Object *pRVar10;
  int iVar11;
  TacticalAIGroup *pTVar12;
  TacticalAIGroup *pTVar13;
  float fVar14;
  float fVar15;
  TribeMainDecisionAIModule *pTVar16;
  uchar unitZone;
  TacticalAIGroup *temp;
  TacticalAIGroup *bestGroup;
  float bestDistance;
  float bestDistance_ffffffec;
  int a;
  int bestUnit_fffffff4;
  int bestGroupDifference;
  int local_4;
  
  numberUngroupedSoldiers(this);
  numberExtraGroupedSoldiers(this);
  pTVar13 = (this->groups).next;
  do {
    if ((pTVar13 == &this->groups) || (pTVar13 == (TacticalAIGroup *)0x0)) {
      if (this->sn[0x28] == 0) {
        bestUnit_fffffff4 = 100;
        do {
          pTVar13 = (this->groups).next;
          if (pTVar13 != &this->groups) {
            do {
              if (pTVar13 == (TacticalAIGroup *)0x0) break;
              iVar6 = TacticalAIGroup::type(pTVar13);
              if (iVar6 == bestUnit_fffffff4) {
                iVar6 = TacticalAIGroup::desiredNumberUnits(pTVar13);
                iVar7 = TacticalAIGroup::numberUnits(pTVar13);
                if (iVar7 < iVar6) {
                  iVar6 = TacticalAIGroup::inUse(pTVar13);
                  if (iVar6 == 1) {
                    pTVar13 = pTVar13->next;
                  }
                  else {
                    bestDistance = -NAN;
                    iVar6 = TacticalAIGroup::commander(pTVar13);
                    pRVar10 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar6);
                    if (pRVar10 != (RGE_Static_Object *)0x0) {
                      bVar3 = RGE_Static_Object::currentZone(pRVar10);
                      bestDistance = (float)(uint)bVar3;
                    }
                    iVar6 = numberUngroupedSoldiers(this);
                    iVar7 = TacticalAIGroup::desiredNumberUnits(pTVar13);
                    iVar11 = TacticalAIGroup::numberUnits(pTVar13);
                    if (iVar7 - iVar11 < iVar6) {
                      iVar6 = TacticalAIGroup::desiredNumberUnits(pTVar13);
                      iVar7 = TacticalAIGroup::numberUnits(pTVar13);
                      if (iVar7 < iVar6) {
                        do {
                          iVar6 = 0;
                          local_4 = -1;
                          bestDistance_ffffffec = -1.0;
                          if (0 < (this->workingArea).numberValue) {
                            do {
                              if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
                                piVar9 = (int *)operator_new(iVar6 * 4 + 4);
                                if (piVar9 != (int *)0x0) {
                                  iVar7 = 0;
                                  if (0 < (this->workingArea).maximumSizeValue) {
                                    do {
                                      if (iVar6 + 1 <= iVar7) break;
                                      iVar11 = iVar7 + 1;
                                      piVar9[iVar7] = (this->workingArea).value[iVar7];
                                      iVar7 = iVar11;
                                    } while (iVar11 < (this->workingArea).maximumSizeValue);
                                  }
                                  operator_delete((this->workingArea).value);
                                  (this->workingArea).value = piVar9;
                                  (this->workingArea).maximumSizeValue = iVar6 + 1;
                                }
                              }
                              pRVar10 = MainDecisionAIModule::object
                                                  ((MainDecisionAIModule *)this->md,
                                                   (this->workingArea).value[iVar6]);
                              if ((pRVar10 != (RGE_Static_Object *)0x0) &&
                                 (bVar3 = RGE_Static_Object::currentZone(pRVar10),
                                 bestDistance == (float)(uint)bVar3)) {
                                pWVar8 = TacticalAIGroup::gatherLocation(pTVar13);
                                fVar14 = pWVar8->z;
                                pWVar8 = TacticalAIGroup::gatherLocation(pTVar13);
                                fVar15 = pWVar8->y;
                                pWVar8 = TacticalAIGroup::gatherLocation(pTVar13);
                                fVar14 = RGE_Static_Object::distance_to_position
                                                   (pRVar10,pWVar8->x,fVar15,fVar14);
                                if ((bestDistance_ffffffec == _DAT_00575758) ||
                                   (fVar14 < bestDistance_ffffffec)) {
                                  if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
                                    piVar9 = (int *)operator_new(iVar6 * 4 + 4);
                                    if (piVar9 != (int *)0x0) {
                                      iVar7 = 0;
                                      if (0 < (this->workingArea).maximumSizeValue) {
                                        do {
                                          if (iVar6 + 1 <= iVar7) break;
                                          iVar11 = iVar7 + 1;
                                          piVar9[iVar7] = (this->workingArea).value[iVar7];
                                          iVar7 = iVar11;
                                        } while (iVar11 < (this->workingArea).maximumSizeValue);
                                      }
                                      operator_delete((this->workingArea).value);
                                      (this->workingArea).value = piVar9;
                                      (this->workingArea).maximumSizeValue = iVar6 + 1;
                                    }
                                  }
                                  local_4 = (this->workingArea).value[iVar6];
                                  bestDistance_ffffffec = fVar14;
                                }
                              }
                              iVar6 = iVar6 + 1;
                            } while (iVar6 < (this->workingArea).numberValue);
                          }
                          if (local_4 == -1) break;
                          TacticalAIGroup::addUnit(pTVar13,local_4,this->md);
                          iVar6 = (this->workingArea).maximumSizeValue;
                          iVar7 = 0;
                          if (0 < iVar6) {
                            piVar9 = (this->workingArea).value;
                            do {
                              if (*piVar9 == local_4) break;
                              iVar7 = iVar7 + 1;
                              piVar9 = piVar9 + 1;
                            } while (iVar7 < iVar6);
                          }
                          if (iVar7 < iVar6) {
                            if (iVar7 < iVar6 + -1) {
                              do {
                                piVar9 = (this->workingArea).value;
                                iVar6 = iVar7 + 1;
                                piVar9[iVar7] = piVar9[iVar6];
                                iVar7 = iVar6;
                              } while (iVar6 < (this->workingArea).maximumSizeValue + -1);
                            }
                            iVar6 = (this->workingArea).numberValue + -1;
                            (this->workingArea).numberValue = iVar6;
                            if (iVar6 < 0) {
                              (this->workingArea).numberValue = 0;
                            }
                          }
                          iVar6 = TacticalAIGroup::desiredNumberUnits(pTVar13);
                          iVar7 = TacticalAIGroup::numberUnits(pTVar13);
                        } while (iVar7 < iVar6);
                      }
                    }
                    else {
                      iVar6 = 0;
                      if (0 < (this->workingArea).numberValue) {
                        do {
                          if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
                            piVar9 = (int *)operator_new(iVar6 * 4 + 4);
                            if (piVar9 != (int *)0x0) {
                              iVar7 = 0;
                              if (0 < (this->workingArea).maximumSizeValue) {
                                do {
                                  if (iVar6 + 1 <= iVar7) break;
                                  iVar11 = iVar7 + 1;
                                  piVar9[iVar7] = (this->workingArea).value[iVar7];
                                  iVar7 = iVar11;
                                } while (iVar11 < (this->workingArea).maximumSizeValue);
                              }
                              operator_delete((this->workingArea).value);
                              (this->workingArea).value = piVar9;
                              (this->workingArea).maximumSizeValue = iVar6 + 1;
                            }
                          }
                          pRVar10 = MainDecisionAIModule::object
                                              ((MainDecisionAIModule *)this->md,
                                               (this->workingArea).value[iVar6]);
                          if ((pRVar10 != (RGE_Static_Object *)0x0) &&
                             (bVar3 = RGE_Static_Object::currentZone(pRVar10),
                             bestDistance == (float)(uint)bVar3)) {
                            if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
                              piVar9 = (int *)operator_new(iVar6 * 4 + 4);
                              if (piVar9 != (int *)0x0) {
                                iVar7 = 0;
                                if (0 < (this->workingArea).maximumSizeValue) {
                                  do {
                                    if (iVar6 + 1 <= iVar7) break;
                                    iVar11 = iVar7 + 1;
                                    piVar9[iVar7] = (this->workingArea).value[iVar7];
                                    iVar7 = iVar11;
                                  } while (iVar11 < (this->workingArea).maximumSizeValue);
                                }
                                operator_delete((this->workingArea).value);
                                (this->workingArea).value = piVar9;
                                (this->workingArea).maximumSizeValue = iVar6 + 1;
                              }
                            }
                            TacticalAIGroup::addUnit
                                      (pTVar13,(this->workingArea).value[iVar6],this->md);
                          }
                          iVar6 = iVar6 + 1;
                        } while (iVar6 < (this->workingArea).numberValue);
                      }
                    }
                    iVar6 = TacticalAIGroup::desiredNumberUnits(pTVar13);
                    iVar7 = TacticalAIGroup::numberUnits(pTVar13);
                    if (iVar7 < iVar6) {
                      iVar6 = numberExtraGroupedSoldiers(this);
                      iVar7 = TacticalAIGroup::desiredNumberUnits(pTVar13);
                      iVar11 = TacticalAIGroup::numberUnits(pTVar13);
                      if (iVar7 - iVar11 < iVar6) {
                        iVar6 = TacticalAIGroup::desiredNumberUnits(pTVar13);
                        iVar7 = TacticalAIGroup::numberUnits(pTVar13);
                        if (iVar7 < iVar6) {
                          do {
                            iVar6 = 0;
                            bestGroupDifference = -1;
                            a = -0x40800000;
                            if (0 < (this->workingArea).numberValue) {
                              do {
                                if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
                                  piVar9 = (int *)operator_new(iVar6 * 4 + 4);
                                  if (piVar9 != (int *)0x0) {
                                    iVar7 = 0;
                                    if (0 < (this->workingArea).maximumSizeValue) {
                                      do {
                                        if (iVar6 + 1 <= iVar7) break;
                                        iVar11 = iVar7 + 1;
                                        piVar9[iVar7] = (this->workingArea).value[iVar7];
                                        iVar7 = iVar11;
                                      } while (iVar11 < (this->workingArea).maximumSizeValue);
                                    }
                                    operator_delete((this->workingArea).value);
                                    (this->workingArea).value = piVar9;
                                    (this->workingArea).maximumSizeValue = iVar6 + 1;
                                  }
                                }
                                pRVar10 = MainDecisionAIModule::object
                                                    ((MainDecisionAIModule *)this->md,
                                                     (this->workingArea).value[iVar6]);
                                if ((pRVar10 != (RGE_Static_Object *)0x0) &&
                                   (bVar3 = RGE_Static_Object::currentZone(pRVar10),
                                   bestDistance == (float)(uint)bVar3)) {
                                  pWVar8 = TacticalAIGroup::gatherLocation(pTVar13);
                                  fVar14 = pWVar8->z;
                                  pWVar8 = TacticalAIGroup::gatherLocation(pTVar13);
                                  fVar15 = pWVar8->y;
                                  pWVar8 = TacticalAIGroup::gatherLocation(pTVar13);
                                  fVar14 = RGE_Static_Object::distance_to_position
                                                     (pRVar10,pWVar8->x,fVar15,fVar14);
                                  if (((float)a == _DAT_00575758) || (fVar14 < (float)a)) {
                                    if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
                                      piVar9 = (int *)operator_new(iVar6 * 4 + 4);
                                      if (piVar9 != (int *)0x0) {
                                        iVar7 = 0;
                                        if (0 < (this->workingArea).maximumSizeValue) {
                                          do {
                                            if (iVar6 + 1 <= iVar7) break;
                                            iVar11 = iVar7 + 1;
                                            piVar9[iVar7] = (this->workingArea).value[iVar7];
                                            iVar7 = iVar11;
                                          } while (iVar11 < (this->workingArea).maximumSizeValue);
                                        }
                                        operator_delete((this->workingArea).value);
                                        (this->workingArea).value = piVar9;
                                        (this->workingArea).maximumSizeValue = iVar6 + 1;
                                      }
                                    }
                                    bestGroupDifference = (this->workingArea).value[iVar6];
                                    a = (int)fVar14;
                                  }
                                }
                                iVar6 = iVar6 + 1;
                              } while (iVar6 < (this->workingArea).numberValue);
                            }
                            if (bestGroupDifference == -1) break;
                            removeFromGroup(this,bestGroupDifference);
                            TacticalAIGroup::addUnit(pTVar13,bestGroupDifference,this->md);
                            iVar6 = (this->workingArea).maximumSizeValue;
                            iVar7 = 0;
                            if (0 < iVar6) {
                              piVar9 = (this->workingArea).value;
                              do {
                                if (*piVar9 == bestGroupDifference) break;
                                iVar7 = iVar7 + 1;
                                piVar9 = piVar9 + 1;
                              } while (iVar7 < iVar6);
                            }
                            if (iVar7 < iVar6) {
                              if (iVar7 < iVar6 + -1) {
                                do {
                                  piVar9 = (this->workingArea).value;
                                  iVar6 = iVar7 + 1;
                                  piVar9[iVar7] = piVar9[iVar6];
                                  iVar7 = iVar6;
                                } while (iVar6 < (this->workingArea).maximumSizeValue + -1);
                              }
                              iVar6 = (this->workingArea).numberValue + -1;
                              (this->workingArea).numberValue = iVar6;
                              if (iVar6 < 0) {
                                (this->workingArea).numberValue = 0;
                              }
                            }
                            iVar6 = TacticalAIGroup::desiredNumberUnits(pTVar13);
                            iVar7 = TacticalAIGroup::numberUnits(pTVar13);
                          } while (iVar7 < iVar6);
                        }
                      }
                      else {
                        iVar6 = 0;
                        if (0 < (this->workingArea).numberValue) {
                          do {
                            if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
                              piVar9 = (int *)operator_new(iVar6 * 4 + 4);
                              if (piVar9 != (int *)0x0) {
                                iVar7 = 0;
                                if (0 < (this->workingArea).maximumSizeValue) {
                                  do {
                                    if (iVar6 + 1 <= iVar7) break;
                                    iVar11 = iVar7 + 1;
                                    piVar9[iVar7] = (this->workingArea).value[iVar7];
                                    iVar7 = iVar11;
                                  } while (iVar11 < (this->workingArea).maximumSizeValue);
                                }
                                operator_delete((this->workingArea).value);
                                (this->workingArea).value = piVar9;
                                (this->workingArea).maximumSizeValue = iVar6 + 1;
                              }
                            }
                            pRVar10 = MainDecisionAIModule::object
                                                ((MainDecisionAIModule *)this->md,
                                                 (this->workingArea).value[iVar6]);
                            if ((pRVar10 != (RGE_Static_Object *)0x0) &&
                               (bVar3 = RGE_Static_Object::currentZone(pRVar10),
                               bestDistance == (float)(uint)bVar3)) {
                              if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
                                piVar9 = (int *)operator_new(iVar6 * 4 + 4);
                                if (piVar9 != (int *)0x0) {
                                  iVar7 = 0;
                                  if (0 < (this->workingArea).maximumSizeValue) {
                                    do {
                                      if (iVar6 + 1 <= iVar7) break;
                                      iVar11 = iVar7 + 1;
                                      piVar9[iVar7] = (this->workingArea).value[iVar7];
                                      iVar7 = iVar11;
                                    } while (iVar11 < (this->workingArea).maximumSizeValue);
                                  }
                                  operator_delete((this->workingArea).value);
                                  (this->workingArea).value = piVar9;
                                  (this->workingArea).maximumSizeValue = iVar6 + 1;
                                }
                              }
                              removeFromGroup(this,(this->workingArea).value[iVar6]);
                              if ((this->workingArea).maximumSizeValue + -1 < iVar6) {
                                piVar9 = (int *)operator_new(iVar6 * 4 + 4);
                                if (piVar9 != (int *)0x0) {
                                  iVar7 = 0;
                                  if (0 < (this->workingArea).maximumSizeValue) {
                                    do {
                                      if (iVar6 + 1 <= iVar7) break;
                                      iVar11 = iVar7 + 1;
                                      piVar9[iVar7] = (this->workingArea).value[iVar7];
                                      iVar7 = iVar11;
                                    } while (iVar11 < (this->workingArea).maximumSizeValue);
                                  }
                                  operator_delete((this->workingArea).value);
                                  (this->workingArea).value = piVar9;
                                  (this->workingArea).maximumSizeValue = iVar6 + 1;
                                }
                              }
                              TacticalAIGroup::addUnit
                                        (pTVar13,(this->workingArea).value[iVar6],this->md);
                            }
                            iVar6 = iVar6 + 1;
                          } while (iVar6 < (this->workingArea).numberValue);
                        }
                      }
                      pTVar13 = pTVar13->next;
                    }
                    else {
                      pTVar13 = pTVar13->next;
                    }
                  }
                }
                else {
                  pTVar13 = pTVar13->next;
                }
              }
              else {
                pTVar13 = pTVar13->next;
              }
            } while (pTVar13 != &this->groups);
          }
          bestUnit_fffffff4 = bestUnit_fffffff4 + 1;
        } while (bestUnit_fffffff4 < 0x67);
      }
      iVar6 = numberUngroupedSoldiers(this);
      if ((iVar6 != 0) && (bestGroup = (TacticalAIGroup *)0x0, 0 < (this->workingArea).numberValue))
{
        do {
          if ((this->workingArea).maximumSizeValue + -1 < (int)bestGroup) {
            puVar1 = (undefined1 *)((int)&bestGroup->_padding_ + 1);
            piVar9 = (int *)operator_new((int)bestGroup * 4 + 4);
            if (piVar9 != (int *)0x0) {
              iVar6 = 0;
              if (0 < (this->workingArea).maximumSizeValue) {
                do {
                  if ((int)puVar1 <= iVar6) break;
                  iVar7 = iVar6 + 1;
                  piVar9[iVar6] = (this->workingArea).value[iVar6];
                  iVar6 = iVar7;
                } while (iVar7 < (this->workingArea).maximumSizeValue);
              }
              operator_delete((this->workingArea).value);
              (this->workingArea).value = piVar9;
              (this->workingArea).maximumSizeValue = (int)puVar1;
            }
          }
          pRVar10 = MainDecisionAIModule::object
                              ((MainDecisionAIModule *)this->md,
                               (this->workingArea).value[(int)bestGroup]);
          if (pRVar10 != (RGE_Static_Object *)0x0) {
            uVar4 = RGE_Static_Object::currentZone(pRVar10);
            pTVar13 = (this->groups).next;
            iVar6 = 0;
            bestDistance = 0.0;
            if (pTVar13 != &this->groups) {
              do {
                if (pTVar13 == (TacticalAIGroup *)0x0) break;
                iVar7 = TacticalAIGroup::type(pTVar13);
                if ((((iVar7 == 100) || (iVar7 = TacticalAIGroup::type(pTVar13), iVar7 == 0x65)) ||
                    (iVar7 = TacticalAIGroup::type(pTVar13), iVar7 == 0x66)) &&
                   (iVar7 = TacticalAIGroup::inUse(pTVar13), iVar7 != 1)) {
                  iVar7 = TacticalAIGroup::commander(pTVar13);
                  pRVar10 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar7);
                  if ((pRVar10 != (RGE_Static_Object *)0x0) &&
                     (uVar5 = RGE_Static_Object::currentZone(pRVar10), uVar4 == uVar5)) {
                    iVar7 = TacticalAIGroup::desiredNumberUnits(pTVar13);
                    iVar11 = TacticalAIGroup::numberUnits(pTVar13);
                    if ((iVar11 < iVar7) &&
                       ((iVar7 = TacticalAIGroup::action(pTVar13), iVar7 == 1 ||
                        (iVar7 = TacticalAIGroup::action(pTVar13), iVar7 == 0)))) {
                      iVar7 = TacticalAIGroup::desiredNumberUnits(pTVar13);
                      iVar11 = TacticalAIGroup::numberUnits(pTVar13);
                      if ((bestDistance == 0.0) || (iVar6 < iVar7 - iVar11)) {
                        iVar6 = iVar7 - iVar11;
                        bestDistance = (float)pTVar13;
                      }
                    }
                  }
                }
                pTVar13 = pTVar13->next;
              } while (pTVar13 != &this->groups);
            }
            if (bestDistance == 0.0) {
              pTVar13 = (this->groups).next;
              bestDistance = 0.0;
              local_4 = 0;
              pTVar12 = (TacticalAIGroup *)0x0;
              pTVar2 = (TacticalAIGroup *)bestDistance;
              for (; (bestDistance = (float)pTVar12, pTVar13 != &this->groups &&
                     (pTVar13 != (TacticalAIGroup *)0x0)); pTVar13 = pTVar13->next) {
                iVar6 = TacticalAIGroup::type(pTVar13);
                pTVar12 = (TacticalAIGroup *)bestDistance;
                if (((((iVar6 == 100) ||
                      ((iVar6 = TacticalAIGroup::type(pTVar13), iVar6 == 0x65 ||
                       (iVar6 = TacticalAIGroup::type(pTVar13), iVar6 == 0x66)))) &&
                     (iVar6 = TacticalAIGroup::inUse(pTVar13), iVar6 != 1)) &&
                    (((iVar6 = TacticalAIGroup::action(pTVar13), iVar6 == 1 ||
                      (iVar6 = TacticalAIGroup::action(pTVar13), iVar6 == 0)) &&
                     ((iVar6 = TacticalAIGroup::type(pTVar13), iVar6 != 100 ||
                      (iVar6 = TacticalAIGroup::numberUnits(pTVar13), iVar6 < this->sn[0x1a]))))))
                   && (((iVar6 = TacticalAIGroup::type(pTVar13), iVar6 != 0x65 ||
                        (iVar6 = TacticalAIGroup::numberUnits(pTVar13), iVar6 < this->sn[0x1c])) &&
                       ((iVar6 = TacticalAIGroup::type(pTVar13), iVar6 != 0x66 ||
                        (iVar6 = TacticalAIGroup::numberUnits(pTVar13), iVar6 < this->sn[0x2c]))))))
{
                  iVar6 = TacticalAIGroup::commander(pTVar13);
                  pRVar10 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar6);
                  if ((pRVar10 != (RGE_Static_Object *)0x0) &&
                     (uVar5 = RGE_Static_Object::currentZone(pRVar10), uVar5 == uVar4)) {
                    iVar6 = TacticalAIGroup::desiredNumberUnits(pTVar13);
                    iVar7 = TacticalAIGroup::numberUnits(pTVar13);
                    if ((pTVar2 == (TacticalAIGroup *)0x0) ||
                       (pTVar12 = pTVar2, iVar7 - iVar6 < local_4)) {
                      pTVar12 = pTVar13;
                      pTVar2 = pTVar13;
                      local_4 = iVar7 - iVar6;
                    }
                  }
                }
                bestDistance = (float)pTVar2;
                pTVar2 = (TacticalAIGroup *)bestDistance;
              }
              if ((TacticalAIGroup *)bestDistance == (TacticalAIGroup *)0x0) {
                return;
              }
              if ((this->workingArea).maximumSizeValue + -1 < (int)bestGroup) {
                puVar1 = (undefined1 *)((int)&bestGroup->_padding_ + 1);
                piVar9 = (int *)operator_new((int)bestGroup * 4 + 4);
                if (piVar9 != (int *)0x0) {
                  iVar6 = 0;
                  if (0 < (this->workingArea).maximumSizeValue) {
                    do {
                      if ((int)puVar1 <= iVar6) break;
                      iVar7 = iVar6 + 1;
                      piVar9[iVar6] = (this->workingArea).value[iVar6];
                      iVar6 = iVar7;
                    } while (iVar7 < (this->workingArea).maximumSizeValue);
                  }
                  operator_delete((this->workingArea).value);
                  (this->workingArea).value = piVar9;
                  (this->workingArea).maximumSizeValue = (int)puVar1;
                }
              }
              pTVar16 = this->md;
              iVar6 = (this->workingArea).value[(int)bestGroup];
            }
            else {
              if ((this->workingArea).maximumSizeValue + -1 < (int)bestGroup) {
                puVar1 = (undefined1 *)((int)&bestGroup->_padding_ + 1);
                piVar9 = (int *)operator_new((int)bestGroup * 4 + 4);
                if (piVar9 != (int *)0x0) {
                  iVar6 = 0;
                  if (0 < (this->workingArea).maximumSizeValue) {
                    do {
                      if ((int)puVar1 <= iVar6) break;
                      iVar7 = iVar6 + 1;
                      piVar9[iVar6] = (this->workingArea).value[iVar6];
                      iVar6 = iVar7;
                    } while (iVar7 < (this->workingArea).maximumSizeValue);
                  }
                  operator_delete((this->workingArea).value);
                  (this->workingArea).value = piVar9;
                  (this->workingArea).maximumSizeValue = (int)puVar1;
                }
              }
              pTVar16 = this->md;
              iVar6 = (this->workingArea).value[(int)bestGroup];
            }
            TacticalAIGroup::addUnit((TacticalAIGroup *)bestDistance,iVar6,pTVar16);
          }
          bestGroup = (TacticalAIGroup *)((int)&bestGroup->_padding_ + 1);
        } while ((int)bestGroup < (this->workingArea).numberValue);
      }
      return;
    }
    iVar6 = TacticalAIGroup::type(pTVar13);
    if (((iVar6 == 100) ||
        ((iVar6 = TacticalAIGroup::type(pTVar13), iVar6 == 0x65 ||
         (iVar6 = TacticalAIGroup::type(pTVar13), iVar6 == 0x66)))) &&
       (iVar6 = TacticalAIGroup::commander(pTVar13), iVar6 == -1)) {
      iVar6 = numberUngroupedSoldiers(this);
      iVar7 = TacticalAIGroup::numberUnits(pTVar13);
      if (iVar7 < 1) {
        if (iVar6 == 0) {
          numberExtraGroupedSoldiers(this);
        }
        if ((this->workingArea).numberValue == 0) {
          return;
        }
        iVar6 = selectBestCommander(this,&this->workingArea);
        TacticalAIGroup::addUnit(pTVar13,iVar6,this->md);
        TacticalAIGroup::setSpecificCommander(pTVar13,iVar6,this->md);
        iVar6 = TacticalAIGroup::action(pTVar13);
        if (iVar6 != 0) {
          iVar6 = TacticalAIGroup::action(pTVar13);
          goto joined_r0x004fc609;
        }
      }
      else {
        iVar6 = selectBestCommander(this,pTVar13);
        TacticalAIGroup::setSpecificCommander(pTVar13,iVar6,this->md);
        iVar6 = TacticalAIGroup::action(pTVar13);
        if (iVar6 != 0) {
          iVar6 = TacticalAIGroup::action(pTVar13);
joined_r0x004fc609:
          if (iVar6 != 1) goto LAB_004fc613;
        }
      }
      setAllGroupLocations(this,pTVar13);
    }
LAB_004fc613:
    pTVar13 = pTVar13->next;
  } while( true );
}

// --------------------------------------------------

// Function: numberUngroupedSoldiers
// Address: 004fd2f0
/* WARNING: Variable defined which should be unmapped: rNum */
/* public: int __thiscall TribeTacticalAIModule::numberUngroupedSoldiers(void) */

int __thiscall TribeTacticalAIModule::numberUngroupedSoldiers(TribeTacticalAIModule *this)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int rNum;
  int local_c;
  int i;
  int local_4;
  
  local_c = 0;
  local_4 = 0;
  (this->workingArea).numberValue = 0;
  if (0 < (this->soldiers).numberValue) {
    do {
      if ((this->soldiers).maximumSizeValue + -1 < local_4) {
        piVar1 = (int *)operator_new(local_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->soldiers).maximumSizeValue) {
            do {
              if (local_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->soldiers).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->soldiers).maximumSizeValue);
          }
          operator_delete((this->soldiers).value);
          (this->soldiers).value = piVar1;
          (this->soldiers).maximumSizeValue = local_4 + 1;
        }
      }
      pTVar3 = groupUnitIsIn(this,(this->soldiers).value[local_4]);
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((this->soldiers).maximumSizeValue + -1 < local_4) {
          piVar1 = (int *)operator_new(local_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->soldiers).maximumSizeValue) {
              do {
                if (local_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (this->soldiers).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (this->soldiers).maximumSizeValue);
            }
            operator_delete((this->soldiers).value);
            (this->soldiers).value = piVar1;
            (this->soldiers).maximumSizeValue = local_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (this->soldiers).value[local_4];
        iVar4 = (this->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((this->workingArea).maximumSizeValue <= iVar5) break;
            if ((this->workingArea).value[iVar5] == iVar2) goto LAB_004fd4c2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((this->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (this->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (this->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (this->workingArea).maximumSizeValue);
            }
            operator_delete((this->workingArea).value);
            (this->workingArea).value = piVar1;
            (this->workingArea).maximumSizeValue = iVar4;
          }
        }
        (this->workingArea).value[(this->workingArea).numberValue] = iVar2;
        (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004fd4c2:
        local_c = local_c + 1;
      }
      local_4 = local_4 + 1;
    } while (local_4 < (this->soldiers).numberValue);
  }
  return local_c;
}

// --------------------------------------------------

// Function: numberExtraGroupedSoldiers
// Address: 004fd4f0
/* WARNING: Variable defined which should be unmapped: j */
/* public: int __thiscall TribeTacticalAIModule::numberExtraGroupedSoldiers(void) */

int __thiscall TribeTacticalAIModule::numberExtraGroupedSoldiers(TribeTacticalAIModule *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  TacticalAIGroup *this_00;
  int j;
  int tempCount;
  int rNum;
  int local_8;
  
  local_8 = 0;
  (this->workingArea).numberValue = 0;
  this_00 = (this->groups).next;
  if (this_00 != &this->groups) {
    do {
      if (this_00 == (TacticalAIGroup *)0x0) {
        return local_8;
      }
      iVar1 = TacticalAIGroup::type(this_00);
      if ((((iVar1 == 100) || (iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x65)) ||
          (iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x66)) &&
         ((iVar1 = TacticalAIGroup::action(this_00), iVar1 == 1 ||
          (iVar1 = TacticalAIGroup::action(this_00), iVar1 == 0)))) {
        iVar1 = TacticalAIGroup::desiredNumberUnits(this_00);
        iVar2 = TacticalAIGroup::numberUnits(this_00);
        if (iVar1 < iVar2) {
          rNum = TacticalAIGroup::numberUnits(this_00);
          tempCount = 0;
          iVar1 = TacticalAIGroup::desiredNumberUnits(this_00);
          if (iVar1 < rNum) {
            do {
              iVar1 = TacticalAIGroup::numberUnits(this_00);
              if (iVar1 <= tempCount) break;
              iVar1 = TacticalAIGroup::unit(this_00,tempCount);
              iVar2 = TacticalAIGroup::commander(this_00);
              if (iVar1 != iVar2) {
                rNum = rNum + -1;
                iVar2 = TacticalAIGroup::unit(this_00,tempCount);
                iVar1 = (this->workingArea).numberValue;
                iVar3 = 0;
                if (0 < iVar1) {
                  do {
                    if ((this->workingArea).maximumSizeValue <= iVar3) break;
                    if ((this->workingArea).value[iVar3] == iVar2) goto LAB_004fd692;
                    iVar3 = iVar3 + 1;
                  } while (iVar3 < iVar1);
                }
                if ((this->workingArea).maximumSizeValue + -1 < iVar1) {
                  iVar1 = iVar1 + 1;
                  piVar4 = (int *)operator_new(iVar1 * 4);
                  if (piVar4 != (int *)0x0) {
                    iVar3 = 0;
                    if (0 < (this->workingArea).maximumSizeValue) {
                      do {
                        if (iVar1 <= iVar3) break;
                        iVar5 = iVar3 + 1;
                        piVar4[iVar3] = (this->workingArea).value[iVar3];
                        iVar3 = iVar5;
                      } while (iVar5 < (this->workingArea).maximumSizeValue);
                    }
                    operator_delete((this->workingArea).value);
                    (this->workingArea).value = piVar4;
                    (this->workingArea).maximumSizeValue = iVar1;
                  }
                }
                (this->workingArea).value[(this->workingArea).numberValue] = iVar2;
                (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004fd692:
                local_8 = local_8 + 1;
              }
              tempCount = tempCount + 1;
              iVar1 = TacticalAIGroup::desiredNumberUnits(this_00);
            } while (iVar1 < rNum);
          }
        }
      }
      this_00 = this_00->next;
    } while (this_00 != &this->groups);
  }
  return local_8;
}

// --------------------------------------------------

// Function: numberUngroupedArtifacts
// Address: 004fd6d0
/* WARNING: Variable defined which should be unmapped: rNum */
/* public: int __thiscall TribeTacticalAIModule::numberUngroupedArtifacts(void) */

int __thiscall TribeTacticalAIModule::numberUngroupedArtifacts(TribeTacticalAIModule *this)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int rNum;
  int local_c;
  int i;
  int local_4;
  
  local_c = 0;
  local_4 = 0;
  (this->workingArea).numberValue = 0;
  if (0 < (this->artifacts).numberValue) {
    do {
      if ((this->artifacts).maximumSizeValue + -1 < local_4) {
        piVar1 = (int *)operator_new(local_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->artifacts).maximumSizeValue) {
            do {
              if (local_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->artifacts).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->artifacts).maximumSizeValue);
          }
          operator_delete((this->artifacts).value);
          (this->artifacts).value = piVar1;
          (this->artifacts).maximumSizeValue = local_4 + 1;
        }
      }
      pTVar3 = groupUnitIsIn(this,(this->artifacts).value[local_4]);
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((this->artifacts).maximumSizeValue + -1 < local_4) {
          piVar1 = (int *)operator_new(local_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->artifacts).maximumSizeValue) {
              do {
                if (local_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (this->artifacts).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (this->artifacts).maximumSizeValue);
            }
            operator_delete((this->artifacts).value);
            (this->artifacts).value = piVar1;
            (this->artifacts).maximumSizeValue = local_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (this->artifacts).value[local_4];
        iVar4 = (this->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((this->workingArea).maximumSizeValue <= iVar5) break;
            if ((this->workingArea).value[iVar5] == iVar2) goto LAB_004fd8a2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((this->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (this->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (this->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (this->workingArea).maximumSizeValue);
            }
            operator_delete((this->workingArea).value);
            (this->workingArea).value = piVar1;
            (this->workingArea).maximumSizeValue = iVar4;
          }
        }
        (this->workingArea).value[(this->workingArea).numberValue] = iVar2;
        (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004fd8a2:
        local_c = local_c + 1;
      }
      local_4 = local_4 + 1;
    } while (local_4 < (this->artifacts).numberValue);
  }
  return local_c;
}

// --------------------------------------------------

// Function: displaySoldierGroups
// Address: 004fd8d0
// [HELPER] s_____AssistGroupID__d__AssistGrou: "    AssistGroupID=%d, AssistGroupType=%d, ConsecIdleCount=%ld."
// [HELPER] s_____Current_waypoints__d_: "    Current waypoints=%d."
// [HELPER] s_____NumUnits__d__DesNumUnits__d_: "    NumUnits=%d, DesNumUnits=%d, OrgNumUnits=%d, Action=%d, inUse=%d."
// [HELPER] s_____NumberObjectsToDestroy__d_: "    NumberObjectsToDestroy=%d."
// [HELPER] s_____Play__d_: "    Play=%d."
// [HELPER] s_____Target__d__CommanderID__d__H: "    Target=%d, CommanderID=%d, HP(%d/%d), AssistGroup=%d."
// [HELPER] s_____Unit__d___s___state__d__acti: "    Unit %d (%s): state=%d, action=%d, target=%d, order=%d, pri=%d, loc=(%3f,..."
// [HELPER] s_______ObjectToDestroy___d___Unit: "      ObjectToDestroy #%d:  Unit #%d, but it's gone."
/* public: void __thiscall TribeTacticalAIModule::displaySoldierGroups(void) */

void __thiscall TribeTacticalAIModule::displaySoldierGroups(TribeTacticalAIModule *this)
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
  AIModule *this_17;
  uint uVar10;
  TacticalAIGroup *this_18;
  char *pcVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this);
  this_18 = (this->groups).next;
  if (this_18 != &this->groups) {
    do {
      if (this_18 == (TacticalAIGroup *)0x0) {
        return;
      }
      iVar3 = TacticalAIGroup::type(this_18);
      if ((((iVar3 == 100) || (iVar3 = TacticalAIGroup::type(this_18), iVar3 == 0x65)) ||
          (iVar3 = TacticalAIGroup::type(this_18), iVar3 == 0x66)) ||
         (iVar3 = TacticalAIGroup::type(this_18), iVar3 == 0x6d)) {
        iVar3 = TacticalAIGroup::type(this_18);
        if (iVar3 == 100) {
          TacticalAIGroup::type(this_18);
          TacticalAIGroup::id(this_18);
          this_00 = extraout_ECX;
LAB_004fd9b8:
          AIModule::logCommonHistory(this_00,(char *)this);
        }
        else {
          iVar3 = TacticalAIGroup::type(this_18);
          if (iVar3 == 0x65) {
            TacticalAIGroup::type(this_18);
            TacticalAIGroup::id(this_18);
            this_00 = extraout_ECX_00;
            goto LAB_004fd9b8;
          }
          iVar3 = TacticalAIGroup::type(this_18);
          if (iVar3 == 0x66) {
            TacticalAIGroup::type(this_18);
            TacticalAIGroup::id(this_18);
            this_00 = extraout_ECX_01;
            goto LAB_004fd9b8;
          }
          iVar3 = TacticalAIGroup::type(this_18);
          if (iVar3 == 0x6d) {
            TacticalAIGroup::type(this_18);
            TacticalAIGroup::id(this_18);
            this_00 = extraout_ECX_02;
            goto LAB_004fd9b8;
          }
        }
        iVar3 = TacticalAIGroup::inUse(this_18);
        iVar4 = TacticalAIGroup::action(this_18);
        uVar13 = CONCAT44(iVar3,iVar4);
        iVar3 = TacticalAIGroup::originalUnitNumber(this_18);
        iVar4 = TacticalAIGroup::desiredNumberUnits(this_18);
        uVar12 = CONCAT44(iVar3,iVar4);
        iVar3 = TacticalAIGroup::numberUnits(this_18);
        AIModule::logCommonHistory
                  (this_01,(char *)this,s_____NumUnits__d__DesNumUnits__d_,iVar3,uVar12,uVar13);
        iVar3 = TacticalAIGroup::target(this_18);
        pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar3);
        if (pRVar5 == (RGE_Static_Object *)0x0) {
          iVar3 = TacticalAIGroup::waitCode(this_18);
          iVar4 = TacticalAIGroup::originalHitPoints(this_18);
          uVar13 = CONCAT44(iVar3,iVar4);
          iVar3 = TacticalAIGroup::currentHitPoints(this_18,this->md);
          iVar4 = TacticalAIGroup::commander(this_18);
          uVar12 = CONCAT44(iVar3,iVar4);
          iVar3 = TacticalAIGroup::target(this_18);
          AIModule::logCommonHistory
                    (this_03,(char *)this,s_____Target__d__CommanderID__d__H,iVar3,uVar12,uVar13);
        }
        else {
          TacticalAIGroup::waitCode(this_18);
          TacticalAIGroup::originalHitPoints(this_18);
          TacticalAIGroup::currentHitPoints(this_18,this->md);
          TacticalAIGroup::commander(this_18);
          TacticalAIGroup::target(this_18);
          AIModule::logCommonHistory(this_02,(char *)this);
        }
        uVar6 = TacticalAIGroup::consecutiveIdleUnitCount(this_18);
        iVar3 = TacticalAIGroup::assistGroupType(this_18);
        uVar12 = CONCAT44(uVar6,iVar3);
        iVar3 = TacticalAIGroup::assistGroupID(this_18);
        AIModule::logCommonHistory
                  (this_04,(char *)this,s_____AssistGroupID__d__AssistGrou,iVar3,uVar12);
        TacticalAIGroup::location(this_18);
        TacticalAIGroup::location(this_18);
        AIModule::logCommonHistory(this_05,(char *)this);
        TacticalAIGroup::gatherLocation(this_18);
        TacticalAIGroup::gatherLocation(this_18);
        AIModule::logCommonHistory(this_06,(char *)this);
        TacticalAIGroup::retreatLocation(this_18);
        TacticalAIGroup::retreatLocation(this_18);
        AIModule::logCommonHistory(this_07,(char *)this);
        TacticalAIGroup::targetLocation(this_18);
        TacticalAIGroup::targetLocation(this_18);
        AIModule::logCommonHistory(this_08,(char *)this);
        AIModule::logCommonHistory((AIModule *)this_18->playNumberValue,(char *)this,s_____Play__d_)
        ;
        AIModule::logCommonHistory(this_09,(char *)this,s_____NumberObjectsToDestroy__d_);
        if ((0 < this_18->numberObjectsToDestroyValue) &&
           (iVar3 = 0, 0 < this_18->numberObjectsToDestroyValue)) {
          do {
            iVar4 = TacticalAIGroup::objectToDestroy(this_18,iVar3);
            pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar4);
            if (pRVar5 == (RGE_Static_Object *)0x0) {
              TacticalAIGroup::objectToDestroy(this_18,iVar3);
              AIModule::logCommonHistory(this_10,(char *)this);
            }
            else {
              iVar4 = TacticalAIGroup::objectToDestroy(this_18,iVar3);
              AIModule::logCommonHistory
                        (this_11,(char *)this,s_______ObjectToDestroy___d___Unit,iVar3,iVar4);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < this_18->numberObjectsToDestroyValue);
        }
        iVar4 = 0;
        iVar3 = TacticalAIGroup::numberUnits(this_18);
        if (0 < iVar3) {
          do {
            iVar3 = TacticalAIGroup::unit(this_18,iVar4);
            pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar3);
            if (pRVar5 == (RGE_Static_Object *)0x0) {
              AIModule::logCommonHistory(this_12,(char *)this);
            }
            else {
              pUVar7 = RGE_Static_Object::unitAI(pRVar5);
              if (pUVar7 == (UnitAIModule *)0x0) {
                AIModule::logCommonHistory(this_13,(char *)this);
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
                iVar9 = TacticalAIGroup::unit(this_18,iVar4);
                AIModule::logCommonHistory
                          (this_14,(char *)this,s_____Unit__d___s___state__d__acti,iVar9,pcVar11,
                           uVar10,iVar8,iVar3);
                pUVar7 = RGE_Static_Object::unitAI(pRVar5);
                iVar3 = UnitAIModule::currentTarget(pUVar7);
                if (iVar3 != -1) {
                  pUVar7 = RGE_Static_Object::unitAI(pRVar5);
                  iVar3 = UnitAIModule::currentTarget(pUVar7);
                  pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar3);
                  if (pRVar5 != (RGE_Static_Object *)0x0) {
                    AIModule::logCommonHistory((AIModule *)(int)pRVar5->owner->id,(char *)this);
                  }
                }
              }
            }
            iVar4 = iVar4 + 1;
            iVar3 = TacticalAIGroup::numberUnits(this_18);
          } while (iVar4 < iVar3);
        }
        uVar1 = TacticalAIGroup::numberAttackWaypoints(this_18);
        if (uVar1 == '\0') {
          AIModule::logCommonHistory(this_15,(char *)this);
        }
        else {
          AIModule::logCommonHistory(this_15,(char *)this);
          iVar3 = 0;
          uVar1 = TacticalAIGroup::numberAttackWaypoints(this_18);
          if (uVar1 != '\0') {
            do {
              TacticalAIGroup::attackWaypoint(this_18,(uchar)iVar3);
              TacticalAIGroup::attackWaypoint(this_18,(uchar)iVar3);
              AIModule::logCommonHistory(this_16,(char *)this);
              iVar3 = iVar3 + 1;
              bVar2 = TacticalAIGroup::numberAttackWaypoints(this_18);
            } while (iVar3 < (int)(uint)bVar2);
          }
          TacticalAIGroup::currentAttackWaypoint(this_18);
          AIModule::logCommonHistory(this_17,(char *)this,s_____Current_waypoints__d_);
        }
      }
      this_18 = this_18->next;
    } while (this_18 != &this->groups);
  }
  return;
}

// --------------------------------------------------

// Function: setupBoatGroups
// Address: 004fde00
/* WARNING: Variable defined which should be unmapped: i */
/* public: void __thiscall TribeTacticalAIModule::setupBoatGroups(void) */

void __thiscall TribeTacticalAIModule::setupBoatGroups(TribeTacticalAIModule *this)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  int iVar7;
  TacticalAIGroup *pTVar8;
  undefined4 *unaff_FS_OFFSET;
  int i;
  int numEGroups;
  int numPotentialAGroups;
  int numPotentialEGroups;
  int numDGroups;
  int numAGroups;
  ManagedArray<int> groupsToRemove;
  int local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00560b68;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  groupsToRemove.numberValue = 0;
  groupsToRemove.desiredNumberValue = 0;
  groupsToRemove.maximumSizeValue = 0;
  local_10 = 0;
  pTVar8 = (this->groups).next;
  local_4 = 0;
  while ((pTVar8 != &this->groups && (pTVar8 != (TacticalAIGroup *)0x0))) {
    iVar1 = TacticalAIGroup::type(pTVar8);
    if ((iVar1 == 0x67) ||
       ((iVar1 = TacticalAIGroup::type(pTVar8), iVar1 == 0x68 ||
        (iVar1 = TacticalAIGroup::type(pTVar8), iVar1 == 0x69)))) {
      iVar1 = TacticalAIGroup::numberUnits(pTVar8);
      if (iVar1 == 0) {
        iVar1 = TacticalAIGroup::id(pTVar8);
        iVar3 = 0;
        piVar4 = (int *)groupsToRemove.numberValue;
        if (0 < groupsToRemove.desiredNumberValue) {
          do {
            if (-1 < iVar3) break;
            if (*piVar4 == iVar1) goto LAB_004fdedf;
            iVar3 = iVar3 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar3 < groupsToRemove.desiredNumberValue);
        }
        if (-1 < groupsToRemove.desiredNumberValue) {
          ManagedArray<int>::resize
                    ((ManagedArray<int> *)&groupsToRemove.numberValue,
                     groupsToRemove.desiredNumberValue + 1);
        }
        *(int *)(groupsToRemove.numberValue + groupsToRemove.desiredNumberValue * 4) = iVar1;
        groupsToRemove.desiredNumberValue = groupsToRemove.desiredNumberValue + 1;
      }
LAB_004fdedf:
      pTVar8 = pTVar8->next;
    }
    else {
      pTVar8 = pTVar8->next;
    }
  }
  numEGroups = 0;
  if (0 < groupsToRemove.desiredNumberValue) {
    do {
      if (local_10 + -1 < numEGroups) {
        pvVar2 = operator_new(numEGroups * 4 + 4);
        if (pvVar2 != (void *)0x0) {
          iVar1 = 0;
          if (0 < local_10) {
            do {
              if (numEGroups + 1 <= iVar1) break;
              iVar1 = iVar1 + 1;
              *(undefined4 *)((int)pvVar2 + iVar1 * 4 + -4) =
                   *(undefined4 *)(groupsToRemove.numberValue + -4 + iVar1 * 4);
            } while (iVar1 < local_10);
          }
          operator_delete((void *)groupsToRemove.numberValue);
          groupsToRemove.numberValue = (int)pvVar2;
          local_10 = numEGroups + 1;
        }
      }
      removeGroup(this,*(int *)(groupsToRemove.numberValue + numEGroups * 4));
      numEGroups = numEGroups + 1;
    } while (numEGroups < groupsToRemove.desiredNumberValue);
  }
                    /* language.dll match for 0x67: "Comic Sans MS" */
  groupsToRemove.value = (int *)numberGroups(this,0x67,-1);
                    /* language.dll match for 0x68: "Arial" */
  iVar3 = numberGroups(this,0x68,-1);
  numPotentialAGroups = numberGroups(this,0x69,-1);
  numberGroups(this,0x6b,-1);
  numberGroups(this,0x6c,-1);
  numberGroups(this,0x6a,-1);
  numberUngroupedFishingBoats(this);
  iVar1 = (this->workingArea).numberValue;
  while (0 < iVar1) {
    if ((this->workingArea).maximumSizeValue + -1 < numEGroups) {
      iVar1 = numEGroups + 1;
      piVar4 = (int *)operator_new(iVar1 * 4);
      if (piVar4 != (int *)0x0) {
        iVar7 = 0;
        if (0 < (this->workingArea).maximumSizeValue) {
          do {
            if (iVar1 <= iVar7) break;
            iVar5 = iVar7 + 1;
            piVar4[iVar7] = (this->workingArea).value[iVar7];
            iVar7 = iVar5;
          } while (iVar5 < (this->workingArea).maximumSizeValue);
        }
        operator_delete((this->workingArea).value);
        (this->workingArea).value = piVar4;
        (this->workingArea).maximumSizeValue = iVar1;
      }
    }
    iVar1 = (this->workingArea).value[numEGroups];
    pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar1);
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      iVar7 = (this->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar4 = (this->workingArea).value;
        do {
          if (*piVar4 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar4 = (this->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar4[iVar5] = piVar4[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (this->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (this->workingArea).numberValue + -1;
        (this->workingArea).numberValue = iVar1;
joined_r0x004fe183:
        if (iVar1 < 0) {
          (this->workingArea).numberValue = 0;
        }
      }
    }
    else {
      pTVar8 = createGroup(this,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
      TacticalAIGroup::setType(pTVar8,0x6b);
      TacticalAIGroup::setDesiredNumberUnits(pTVar8,this->sn[0x41] + 1);
      TacticalAIGroup::addUnit(pTVar8,iVar1,this->md);
      TacticalAIGroup::setSpecificCommander(pTVar8,iVar1,this->md);
      TacticalAIGroup::setLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setGatherLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setRetreatLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      iVar7 = (this->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar4 = (this->workingArea).value;
        do {
          if (*piVar4 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar4 = (this->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar4[iVar5] = piVar4[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (this->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (this->workingArea).numberValue + -1;
        (this->workingArea).numberValue = iVar1;
        goto joined_r0x004fe183;
      }
    }
    iVar1 = (this->workingArea).numberValue;
  }
  numberUngroupedTradeBoats(this);
  iVar1 = (this->workingArea).numberValue;
  while (0 < iVar1) {
    if ((this->workingArea).maximumSizeValue + -1 < numEGroups) {
      iVar1 = numEGroups + 1;
      piVar4 = (int *)operator_new(iVar1 * 4);
      if (piVar4 != (int *)0x0) {
        iVar7 = 0;
        if (0 < (this->workingArea).maximumSizeValue) {
          do {
            if (iVar1 <= iVar7) break;
            iVar5 = iVar7 + 1;
            piVar4[iVar7] = (this->workingArea).value[iVar7];
            iVar7 = iVar5;
          } while (iVar5 < (this->workingArea).maximumSizeValue);
        }
        operator_delete((this->workingArea).value);
        (this->workingArea).value = piVar4;
        (this->workingArea).maximumSizeValue = iVar1;
      }
    }
    iVar1 = (this->workingArea).value[numEGroups];
    pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar1);
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      iVar7 = (this->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar4 = (this->workingArea).value;
        do {
          if (*piVar4 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar4 = (this->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar4[iVar5] = piVar4[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (this->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (this->workingArea).numberValue + -1;
        (this->workingArea).numberValue = iVar1;
joined_r0x004fe366:
        if (iVar1 < 0) {
          (this->workingArea).numberValue = 0;
        }
      }
    }
    else {
      pTVar8 = createGroup(this,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
      TacticalAIGroup::setType(pTVar8,0x6c);
      TacticalAIGroup::setDesiredNumberUnits(pTVar8,this->sn[0x40] + 1);
      TacticalAIGroup::addUnit(pTVar8,iVar1,this->md);
      TacticalAIGroup::setSpecificCommander(pTVar8,iVar1,this->md);
      TacticalAIGroup::setLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setGatherLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setRetreatLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      iVar7 = (this->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar4 = (this->workingArea).value;
        do {
          if (*piVar4 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar4 = (this->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar4[iVar5] = piVar4[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (this->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (this->workingArea).numberValue + -1;
        (this->workingArea).numberValue = iVar1;
        goto joined_r0x004fe366;
      }
    }
    iVar1 = (this->workingArea).numberValue;
  }
  numberUngroupedTransportBoats(this);
  iVar1 = (this->workingArea).numberValue;
  while (0 < iVar1) {
    if ((this->workingArea).maximumSizeValue + -1 < numEGroups) {
      iVar1 = numEGroups + 1;
      piVar4 = (int *)operator_new(iVar1 * 4);
      if (piVar4 != (int *)0x0) {
        iVar7 = 0;
        if (0 < (this->workingArea).maximumSizeValue) {
          do {
            if (iVar1 <= iVar7) break;
            iVar5 = iVar7 + 1;
            piVar4[iVar7] = (this->workingArea).value[iVar7];
            iVar7 = iVar5;
          } while (iVar5 < (this->workingArea).maximumSizeValue);
        }
        operator_delete((this->workingArea).value);
        (this->workingArea).value = piVar4;
        (this->workingArea).maximumSizeValue = iVar1;
      }
    }
    iVar1 = (this->workingArea).value[numEGroups];
    pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar1);
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      iVar7 = (this->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar4 = (this->workingArea).value;
        do {
          if (*piVar4 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar4 = (this->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar4[iVar5] = piVar4[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (this->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (this->workingArea).numberValue + -1;
        (this->workingArea).numberValue = iVar1;
joined_r0x004fe549:
        if (iVar1 < 0) {
          (this->workingArea).numberValue = 0;
        }
      }
    }
    else {
      pTVar8 = createGroup(this,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
      TacticalAIGroup::setType(pTVar8,0x6a);
      TacticalAIGroup::setDesiredNumberUnits(pTVar8,this->sn[0x42] + 1);
      TacticalAIGroup::addUnit(pTVar8,iVar1,this->md);
      TacticalAIGroup::setSpecificCommander(pTVar8,iVar1,this->md);
      TacticalAIGroup::setLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setGatherLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setRetreatLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      iVar7 = (this->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar4 = (this->workingArea).value;
        do {
          if (*piVar4 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar4 = (this->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar4[iVar5] = piVar4[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (this->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (this->workingArea).numberValue + -1;
        (this->workingArea).numberValue = iVar1;
        goto joined_r0x004fe549;
      }
    }
    iVar1 = (this->workingArea).numberValue;
  }
  if (((this->boats).maximumSizeValue + -1 < 0) &&
     (piVar4 = (int *)operator_new(4), piVar4 != (int *)0x0)) {
    iVar1 = 0;
    if (0 < (this->boats).maximumSizeValue) {
      do {
        if (0 < iVar1) break;
        iVar7 = iVar1 + 1;
        piVar4[iVar1] = (this->boats).value[iVar1];
        iVar1 = iVar7;
      } while (iVar7 < (this->boats).maximumSizeValue);
    }
    operator_delete((this->boats).value);
    (this->boats).value = piVar4;
    (this->boats).maximumSizeValue = 1;
  }
  iVar1 = TribeInformationAIModule::fullyExploredZone(&this->md->informationAI,*(this->boats).value)
  ;
  if (iVar1 == 0) {
    removeAllGroups(this,0x69);
    setStrategicNumber(this,0x3d,0);
  }
  numEGroups = 0;
  numDGroups = 0;
  if (this->sn[0x28] == 0) {
    ceil((double)(this->warBoats).numberValue / (double)this->sn[0x3b]);
    numPotentialEGroups = __ftol();
    if (this->sn[0x3a] < numPotentialEGroups) {
      numPotentialEGroups = this->sn[0x3a];
    }
    iVar7 = numPotentialEGroups * this->sn[0x3b];
    iVar1 = (this->warBoats).numberValue - iVar7;
    piVar4 = groupsToRemove.value;
    if (0 < iVar1) {
      ceil((double)iVar1 / (double)this->sn[0x44]);
      numEGroups = __ftol();
      if (this->sn[0x43] < numEGroups) {
        numEGroups = this->sn[0x43];
      }
      iVar1 = ((this->warBoats).numberValue - iVar7) - numEGroups * this->sn[0x44];
      piVar4 = groupsToRemove.value;
      if (0 < iVar1) {
        ceil((double)iVar1 / (double)this->sn[0x3e]);
        numDGroups = __ftol();
        piVar4 = groupsToRemove.value;
        if (this->sn[0x3d] < numDGroups) {
          numDGroups = this->sn[0x3d];
        }
      }
    }
  }
  else {
    iVar1 = (this->warBoats).numberValue;
    numPotentialEGroups = iVar1;
    if (this->sn[0x3a] <= iVar1) {
      numPotentialEGroups = this->sn[0x3a];
    }
    iVar1 = iVar1 - numPotentialEGroups;
    piVar4 = groupsToRemove.value;
    if (0 < iVar1) {
      numEGroups = this->sn[0x43];
      if (iVar1 < this->sn[0x43]) {
        numEGroups = iVar1;
      }
      iVar1 = iVar1 - numEGroups;
      if ((0 < iVar1) && (numDGroups = iVar1, this->sn[0x3d] <= iVar1)) {
        numDGroups = this->sn[0x3d];
      }
    }
  }
  for (; (int)piVar4 < numPotentialEGroups; piVar4 = (int *)((int)piVar4 + 1)) {
    pTVar8 = (TacticalAIGroup *)0x0;
    if (iVar3 < 1) {
LAB_004fe76d:
      if (pTVar8 == (TacticalAIGroup *)0x0) goto LAB_004fe771;
    }
    else {
                    /* language.dll match for 0x68: "Arial" */
      pTVar8 = group(this,-1,0x68,-1,-1);
      if (pTVar8 != (TacticalAIGroup *)0x0) {
        iVar3 = iVar3 + -1;
        goto LAB_004fe76d;
      }
      pTVar8 = group(this,-1,0x69,-1,-1);
      if (pTVar8 != (TacticalAIGroup *)0x0) {
        numPotentialAGroups = numPotentialAGroups + -1;
        goto LAB_004fe76d;
      }
LAB_004fe771:
      pTVar8 = createGroup(this,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
    }
                    /* language.dll match for 0x67: "Comic Sans MS" */
    TacticalAIGroup::setType(pTVar8,0x67);
    TacticalAIGroup::setTarget(pTVar8,-1);
    TacticalAIGroup::setTargetType(pTVar8,-1);
    TacticalAIGroup::setAction(pTVar8,1);
    TacticalAIGroup::setInUse(pTVar8,0);
    TacticalAIGroup::setDesiredNumberUnits(pTVar8,this->sn[0x3b]);
  }
                    /* language.dll match for 0x67: "Comic Sans MS" */
                    /* language.dll match for 0x67: "Comic Sans MS" */
  while ((numPotentialEGroups < (int)piVar4 &&
         ((pTVar8 = group(this,-1,0x67,0,-1), pTVar8 != (TacticalAIGroup *)0x0 ||
          (pTVar8 = group(this,-1,0x67,1,-1), pTVar8 != (TacticalAIGroup *)0x0))))) {
    iVar1 = TacticalAIGroup::id(pTVar8);
    removeGroup(this,iVar1);
    piVar4 = (int *)((int)piVar4 + -1);
  }
  for (; iVar3 < numEGroups; iVar3 = iVar3 + 1) {
    pTVar8 = (TacticalAIGroup *)0x0;
    if (numPotentialAGroups < 1) {
LAB_004fe837:
      if (pTVar8 == (TacticalAIGroup *)0x0) goto LAB_004fe83b;
    }
    else {
      pTVar8 = group(this,-1,0x69,-1,-1);
      if (pTVar8 != (TacticalAIGroup *)0x0) {
        numPotentialAGroups = numPotentialAGroups + -1;
        goto LAB_004fe837;
      }
LAB_004fe83b:
      pTVar8 = createGroup(this,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
    }
                    /* language.dll match for 0x68: "Arial" */
    TacticalAIGroup::setType(pTVar8,0x68);
    TacticalAIGroup::setTarget(pTVar8,-1);
    TacticalAIGroup::setTargetType(pTVar8,-1);
    TacticalAIGroup::setAction(pTVar8,1);
    TacticalAIGroup::setInUse(pTVar8,0);
    TacticalAIGroup::setDesiredNumberUnits(pTVar8,this->sn[0x44]);
  }
                    /* language.dll match for 0x68: "Arial" */
  while ((numEGroups < iVar3 &&
         (pTVar8 = group(this,-1,0x68,-1,-1), pTVar8 != (TacticalAIGroup *)0x0))) {
    iVar1 = TacticalAIGroup::id(pTVar8);
    removeGroup(this,iVar1);
    iVar3 = iVar3 + -1;
  }
  iVar1 = numPotentialAGroups - numDGroups;
  if (numPotentialAGroups < numDGroups) {
    do {
      pTVar8 = createGroup(this,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
      TacticalAIGroup::setType(pTVar8,0x69);
      TacticalAIGroup::setDesiredNumberUnits(pTVar8,this->sn[0x3e]);
      numPotentialAGroups = numPotentialAGroups + 1;
    } while (numPotentialAGroups < numDGroups);
    iVar1 = numPotentialAGroups - numDGroups;
  }
  if (numPotentialAGroups != numDGroups && SBORROW4(numPotentialAGroups,numDGroups) == iVar1 < 0) {
    do {
      pTVar8 = group(this,-1,0x69,-1,-1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
      iVar1 = TacticalAIGroup::id(pTVar8);
      removeGroup(this,iVar1);
      numPotentialAGroups = numPotentialAGroups + -1;
    } while (numDGroups < numPotentialAGroups);
  }
  local_4 = 0xffffffff;
  if (groupsToRemove.numberValue != 0) {
    operator_delete((void *)groupsToRemove.numberValue);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: fillBoatGroups
// Address: 004fe950
/* WARNING: Variable defined which should be unmapped: bestGroup */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TribeTacticalAIModule::fillBoatGroups(void) */

void __thiscall TribeTacticalAIModule::fillBoatGroups(TribeTacticalAIModule *this)
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
  TacticalAIGroup *bestGroup;
  float bestDistance;
  float bestDistance_ffffffec;
  int a;
  int bestUnit_fffffff4;
  int bestGroupDifference;
  int local_4;
  
  numberUngroupedWarBoats(this);
  numberExtraGroupedWarBoats(this);
  pTVar7 = (this->groups).next;
  do {
    if ((pTVar7 == &this->groups) || (pTVar7 == (TacticalAIGroup *)0x0)) {
      if (this->sn[0x28] == 0) {
                    /* language.dll match for 0x67: "Comic Sans MS" */
        bestUnit_fffffff4 = 0x67;
        do {
          bestDistance = (float)(this->groups).next;
          if ((TacticalAIGroup *)bestDistance != &this->groups) {
            do {
              if (bestDistance == 0.0) break;
              iVar1 = TacticalAIGroup::type((TacticalAIGroup *)bestDistance);
              if (iVar1 == bestUnit_fffffff4) {
                iVar1 = TacticalAIGroup::desiredNumberUnits((TacticalAIGroup *)bestDistance);
                iVar2 = TacticalAIGroup::numberUnits((TacticalAIGroup *)bestDistance);
                if (iVar2 < iVar1) {
                  iVar1 = numberUngroupedWarBoats(this);
                  iVar2 = TacticalAIGroup::desiredNumberUnits((TacticalAIGroup *)bestDistance);
                  iVar5 = TacticalAIGroup::numberUnits((TacticalAIGroup *)bestDistance);
                  if (iVar2 - iVar5 < iVar1) {
                    iVar1 = TacticalAIGroup::desiredNumberUnits((TacticalAIGroup *)bestDistance);
                    iVar2 = TacticalAIGroup::numberUnits((TacticalAIGroup *)bestDistance);
                    if (iVar2 < iVar1) {
                      do {
                        iVar1 = 0;
                        local_4 = -1;
                        bestDistance_ffffffec = -1.0;
                        if (0 < (this->workingArea).numberValue) {
                          do {
                            if ((this->workingArea).maximumSizeValue + -1 < iVar1) {
                              piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                              if (piVar6 != (int *)0x0) {
                                iVar2 = 0;
                                if (0 < (this->workingArea).maximumSizeValue) {
                                  do {
                                    if (iVar1 + 1 <= iVar2) break;
                                    iVar5 = iVar2 + 1;
                                    piVar6[iVar2] = (this->workingArea).value[iVar2];
                                    iVar2 = iVar5;
                                  } while (iVar5 < (this->workingArea).maximumSizeValue);
                                }
                                operator_delete((this->workingArea).value);
                                (this->workingArea).value = piVar6;
                                (this->workingArea).maximumSizeValue = iVar1 + 1;
                              }
                            }
                            pRVar3 = MainDecisionAIModule::object
                                               ((MainDecisionAIModule *)this->md,
                                                (this->workingArea).value[iVar1]);
                            if (pRVar3 != (RGE_Static_Object *)0x0) {
                              pWVar4 = TacticalAIGroup::gatherLocation
                                                 ((TacticalAIGroup *)bestDistance);
                              fVar8 = pWVar4->z;
                              pWVar4 = TacticalAIGroup::gatherLocation
                                                 ((TacticalAIGroup *)bestDistance);
                              fVar9 = pWVar4->y;
                              pWVar4 = TacticalAIGroup::gatherLocation
                                                 ((TacticalAIGroup *)bestDistance);
                              fVar8 = RGE_Static_Object::distance_to_position
                                                (pRVar3,pWVar4->x,fVar9,fVar8);
                              if ((bestDistance_ffffffec == _DAT_00575758) ||
                                 (fVar8 < bestDistance_ffffffec)) {
                                if ((this->workingArea).maximumSizeValue + -1 < iVar1) {
                                  piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                                  if (piVar6 != (int *)0x0) {
                                    iVar2 = 0;
                                    if (0 < (this->workingArea).maximumSizeValue) {
                                      do {
                                        if (iVar1 + 1 <= iVar2) break;
                                        iVar5 = iVar2 + 1;
                                        piVar6[iVar2] = (this->workingArea).value[iVar2];
                                        iVar2 = iVar5;
                                      } while (iVar5 < (this->workingArea).maximumSizeValue);
                                    }
                                    operator_delete((this->workingArea).value);
                                    (this->workingArea).value = piVar6;
                                    (this->workingArea).maximumSizeValue = iVar1 + 1;
                                  }
                                }
                                local_4 = (this->workingArea).value[iVar1];
                                bestDistance_ffffffec = fVar8;
                              }
                            }
                            iVar1 = iVar1 + 1;
                          } while (iVar1 < (this->workingArea).numberValue);
                        }
                        if (local_4 == -1) break;
                        TacticalAIGroup::addUnit((TacticalAIGroup *)bestDistance,local_4,this->md);
                        iVar1 = (this->workingArea).maximumSizeValue;
                        iVar2 = 0;
                        if (0 < iVar1) {
                          piVar6 = (this->workingArea).value;
                          do {
                            if (*piVar6 == local_4) break;
                            iVar2 = iVar2 + 1;
                            piVar6 = piVar6 + 1;
                          } while (iVar2 < iVar1);
                        }
                        if (iVar2 < iVar1) {
                          if (iVar2 < iVar1 + -1) {
                            do {
                              piVar6 = (this->workingArea).value;
                              iVar1 = iVar2 + 1;
                              piVar6[iVar2] = piVar6[iVar1];
                              iVar2 = iVar1;
                            } while (iVar1 < (this->workingArea).maximumSizeValue + -1);
                          }
                          iVar1 = (this->workingArea).numberValue + -1;
                          (this->workingArea).numberValue = iVar1;
                          if (iVar1 < 0) {
                            (this->workingArea).numberValue = 0;
                          }
                        }
                        iVar1 = TacticalAIGroup::desiredNumberUnits((TacticalAIGroup *)bestDistance)
                        ;
                        iVar2 = TacticalAIGroup::numberUnits((TacticalAIGroup *)bestDistance);
                      } while (iVar2 < iVar1);
                    }
                  }
                  else {
                    iVar1 = 0;
                    if (0 < (this->workingArea).numberValue) {
                      do {
                        if ((this->workingArea).maximumSizeValue + -1 < iVar1) {
                          piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                          if (piVar6 != (int *)0x0) {
                            iVar2 = 0;
                            if (0 < (this->workingArea).maximumSizeValue) {
                              do {
                                if (iVar1 + 1 <= iVar2) break;
                                iVar5 = iVar2 + 1;
                                piVar6[iVar2] = (this->workingArea).value[iVar2];
                                iVar2 = iVar5;
                              } while (iVar5 < (this->workingArea).maximumSizeValue);
                            }
                            operator_delete((this->workingArea).value);
                            (this->workingArea).value = piVar6;
                            (this->workingArea).maximumSizeValue = iVar1 + 1;
                          }
                        }
                        TacticalAIGroup::addUnit
                                  ((TacticalAIGroup *)bestDistance,(this->workingArea).value[iVar1],
                                   this->md);
                        iVar1 = iVar1 + 1;
                      } while (iVar1 < (this->workingArea).numberValue);
                    }
                  }
                  iVar1 = TacticalAIGroup::desiredNumberUnits((TacticalAIGroup *)bestDistance);
                  iVar2 = TacticalAIGroup::numberUnits((TacticalAIGroup *)bestDistance);
                  if (iVar2 < iVar1) {
                    iVar1 = numberExtraGroupedWarBoats(this);
                    iVar2 = TacticalAIGroup::desiredNumberUnits((TacticalAIGroup *)bestDistance);
                    iVar5 = TacticalAIGroup::numberUnits((TacticalAIGroup *)bestDistance);
                    if (iVar2 - iVar5 < iVar1) {
                      iVar1 = TacticalAIGroup::desiredNumberUnits((TacticalAIGroup *)bestDistance);
                      iVar2 = TacticalAIGroup::numberUnits((TacticalAIGroup *)bestDistance);
                      if (iVar2 < iVar1) {
                        do {
                          iVar1 = 0;
                          bestGroupDifference = -1;
                          a = -0x40800000;
                          if (0 < (this->workingArea).numberValue) {
                            do {
                              if ((this->workingArea).maximumSizeValue + -1 < iVar1) {
                                piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                                if (piVar6 != (int *)0x0) {
                                  iVar2 = 0;
                                  if (0 < (this->workingArea).maximumSizeValue) {
                                    do {
                                      if (iVar1 + 1 <= iVar2) break;
                                      iVar5 = iVar2 + 1;
                                      piVar6[iVar2] = (this->workingArea).value[iVar2];
                                      iVar2 = iVar5;
                                    } while (iVar5 < (this->workingArea).maximumSizeValue);
                                  }
                                  operator_delete((this->workingArea).value);
                                  (this->workingArea).value = piVar6;
                                  (this->workingArea).maximumSizeValue = iVar1 + 1;
                                }
                              }
                              pRVar3 = MainDecisionAIModule::object
                                                 ((MainDecisionAIModule *)this->md,
                                                  (this->workingArea).value[iVar1]);
                              if (pRVar3 != (RGE_Static_Object *)0x0) {
                                pWVar4 = TacticalAIGroup::gatherLocation
                                                   ((TacticalAIGroup *)bestDistance);
                                fVar8 = pWVar4->z;
                                pWVar4 = TacticalAIGroup::gatherLocation
                                                   ((TacticalAIGroup *)bestDistance);
                                fVar9 = pWVar4->y;
                                pWVar4 = TacticalAIGroup::gatherLocation
                                                   ((TacticalAIGroup *)bestDistance);
                                fVar8 = RGE_Static_Object::distance_to_position
                                                  (pRVar3,pWVar4->x,fVar9,fVar8);
                                if (((float)a == _DAT_00575758) || (fVar8 < (float)a)) {
                                  if ((this->workingArea).maximumSizeValue + -1 < iVar1) {
                                    piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                                    if (piVar6 != (int *)0x0) {
                                      iVar2 = 0;
                                      if (0 < (this->workingArea).maximumSizeValue) {
                                        do {
                                          if (iVar1 + 1 <= iVar2) break;
                                          iVar5 = iVar2 + 1;
                                          piVar6[iVar2] = (this->workingArea).value[iVar2];
                                          iVar2 = iVar5;
                                        } while (iVar5 < (this->workingArea).maximumSizeValue);
                                      }
                                      operator_delete((this->workingArea).value);
                                      (this->workingArea).value = piVar6;
                                      (this->workingArea).maximumSizeValue = iVar1 + 1;
                                    }
                                  }
                                  bestGroupDifference = (this->workingArea).value[iVar1];
                                  a = (int)fVar8;
                                }
                              }
                              iVar1 = iVar1 + 1;
                            } while (iVar1 < (this->workingArea).numberValue);
                          }
                          if (bestGroupDifference == -1) break;
                          removeFromGroup(this,bestGroupDifference);
                          TacticalAIGroup::addUnit
                                    ((TacticalAIGroup *)bestDistance,bestGroupDifference,this->md);
                          iVar1 = (this->workingArea).maximumSizeValue;
                          iVar2 = 0;
                          if (0 < iVar1) {
                            piVar6 = (this->workingArea).value;
                            do {
                              if (*piVar6 == bestGroupDifference) break;
                              iVar2 = iVar2 + 1;
                              piVar6 = piVar6 + 1;
                            } while (iVar2 < iVar1);
                          }
                          if (iVar2 < iVar1) {
                            if (iVar2 < iVar1 + -1) {
                              do {
                                piVar6 = (this->workingArea).value;
                                iVar1 = iVar2 + 1;
                                piVar6[iVar2] = piVar6[iVar1];
                                iVar2 = iVar1;
                              } while (iVar1 < (this->workingArea).maximumSizeValue + -1);
                            }
                            iVar1 = (this->workingArea).numberValue + -1;
                            (this->workingArea).numberValue = iVar1;
                            if (iVar1 < 0) {
                              (this->workingArea).numberValue = 0;
                            }
                          }
                          iVar1 = TacticalAIGroup::desiredNumberUnits
                                            ((TacticalAIGroup *)bestDistance);
                          iVar2 = TacticalAIGroup::numberUnits((TacticalAIGroup *)bestDistance);
                        } while (iVar2 < iVar1);
                      }
                    }
                    else {
                      iVar1 = 0;
                      if (0 < (this->workingArea).numberValue) {
                        do {
                          if ((this->workingArea).maximumSizeValue + -1 < iVar1) {
                            piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                            if (piVar6 != (int *)0x0) {
                              iVar2 = 0;
                              if (0 < (this->workingArea).maximumSizeValue) {
                                do {
                                  if (iVar1 + 1 <= iVar2) break;
                                  iVar5 = iVar2 + 1;
                                  piVar6[iVar2] = (this->workingArea).value[iVar2];
                                  iVar2 = iVar5;
                                } while (iVar5 < (this->workingArea).maximumSizeValue);
                              }
                              operator_delete((this->workingArea).value);
                              (this->workingArea).value = piVar6;
                              (this->workingArea).maximumSizeValue = iVar1 + 1;
                            }
                          }
                          removeFromGroup(this,(this->workingArea).value[iVar1]);
                          if ((this->workingArea).maximumSizeValue + -1 < iVar1) {
                            piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                            if (piVar6 != (int *)0x0) {
                              iVar2 = 0;
                              if (0 < (this->workingArea).maximumSizeValue) {
                                do {
                                  if (iVar1 + 1 <= iVar2) break;
                                  iVar5 = iVar2 + 1;
                                  piVar6[iVar2] = (this->workingArea).value[iVar2];
                                  iVar2 = iVar5;
                                } while (iVar5 < (this->workingArea).maximumSizeValue);
                              }
                              operator_delete((this->workingArea).value);
                              (this->workingArea).value = piVar6;
                              (this->workingArea).maximumSizeValue = iVar1 + 1;
                            }
                          }
                          TacticalAIGroup::addUnit
                                    ((TacticalAIGroup *)bestDistance,
                                     (this->workingArea).value[iVar1],this->md);
                          iVar1 = iVar1 + 1;
                        } while (iVar1 < (this->workingArea).numberValue);
                      }
                    }
                    bestDistance = *(float *)((int)bestDistance + 4);
                  }
                  else {
                    bestDistance = *(float *)((int)bestDistance + 4);
                  }
                }
                else {
                  bestDistance = *(float *)((int)bestDistance + 4);
                }
              }
              else {
                bestDistance = *(float *)((int)bestDistance + 4);
              }
            } while ((TacticalAIGroup *)bestDistance != &this->groups);
          }
          bestUnit_fffffff4 = bestUnit_fffffff4 + 1;
        } while (bestUnit_fffffff4 < 0x6b);
      }
      iVar1 = numberUngroupedWarBoats(this);
      if ((iVar1 != 0) && (bestDistance_ffffffec = 0.0, 0 < (this->workingArea).numberValue)) {
        do {
          pTVar7 = (this->groups).next;
          iVar1 = 0;
          bestDistance = 0.0;
          if (pTVar7 != &this->groups) {
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
                  if ((bestDistance == 0.0) || (iVar1 < iVar5 - iVar2)) {
                    iVar1 = iVar5 - iVar2;
                    bestDistance = (float)pTVar7;
                  }
                }
              }
              pTVar7 = pTVar7->next;
            } while (pTVar7 != &this->groups);
          }
          if (bestDistance == 0.0) {
            pTVar7 = (this->groups).next;
            bestDistance = 0.0;
            local_4 = 0;
            for (; (pTVar7 != &this->groups && (pTVar7 != (TacticalAIGroup *)0x0));
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
                    (iVar1 = TacticalAIGroup::numberUnits(pTVar7), iVar1 < this->sn[0x3c])) &&
                   ((iVar1 = TacticalAIGroup::type(pTVar7), iVar1 != 0x68 ||
                    (iVar1 = TacticalAIGroup::numberUnits(pTVar7), iVar1 < this->sn[0x45])))))) &&
                 ((iVar1 = TacticalAIGroup::type(pTVar7), iVar1 != 0x69 ||
                  (iVar1 = TacticalAIGroup::numberUnits(pTVar7), iVar1 < this->sn[0x3f])))) {
                iVar1 = TacticalAIGroup::numberUnits(pTVar7);
                iVar2 = TacticalAIGroup::desiredNumberUnits(pTVar7);
                if (((TacticalAIGroup *)bestDistance == (TacticalAIGroup *)0x0) ||
                   (iVar1 - iVar2 < local_4)) {
                  bestDistance = (float)pTVar7;
                  local_4 = iVar1 - iVar2;
                }
              }
            }
            if ((TacticalAIGroup *)bestDistance == (TacticalAIGroup *)0x0) {
              return;
            }
            if ((this->workingArea).maximumSizeValue + -1 < (int)bestDistance_ffffffec) {
              piVar6 = (int *)operator_new((int)bestDistance_ffffffec * 4 + 4);
              if (piVar6 != (int *)0x0) {
                iVar1 = 0;
                if (0 < (this->workingArea).maximumSizeValue) {
                  do {
                    if ((int)bestDistance_ffffffec + 1 <= iVar1) break;
                    iVar2 = iVar1 + 1;
                    piVar6[iVar1] = (this->workingArea).value[iVar1];
                    iVar1 = iVar2;
                  } while (iVar2 < (this->workingArea).maximumSizeValue);
                }
                operator_delete((this->workingArea).value);
                (this->workingArea).value = piVar6;
                (this->workingArea).maximumSizeValue = (int)bestDistance_ffffffec + 1;
              }
            }
            TacticalAIGroup::addUnit
                      ((TacticalAIGroup *)bestDistance,
                       (this->workingArea).value[(int)bestDistance_ffffffec],this->md);
          }
          else {
            if ((this->workingArea).maximumSizeValue + -1 < (int)bestDistance_ffffffec) {
              piVar6 = (int *)operator_new((int)bestDistance_ffffffec * 4 + 4);
              if (piVar6 != (int *)0x0) {
                iVar1 = 0;
                if (0 < (this->workingArea).maximumSizeValue) {
                  do {
                    if ((int)bestDistance_ffffffec + 1 <= iVar1) break;
                    iVar2 = iVar1 + 1;
                    piVar6[iVar1] = (this->workingArea).value[iVar1];
                    iVar1 = iVar2;
                  } while (iVar2 < (this->workingArea).maximumSizeValue);
                }
                operator_delete((this->workingArea).value);
                (this->workingArea).value = piVar6;
                (this->workingArea).maximumSizeValue = (int)bestDistance_ffffffec + 1;
              }
            }
            TacticalAIGroup::addUnit
                      ((TacticalAIGroup *)bestDistance,
                       (this->workingArea).value[(int)bestDistance_ffffffec],this->md);
          }
          bestDistance_ffffffec = (float)((int)bestDistance_ffffffec + 1);
        } while ((int)bestDistance_ffffffec < (this->workingArea).numberValue);
      }
      return;
    }
    iVar1 = TacticalAIGroup::type(pTVar7);
    if (((iVar1 == 0x67) ||
        ((iVar1 = TacticalAIGroup::type(pTVar7), iVar1 == 0x68 ||
         (iVar1 = TacticalAIGroup::type(pTVar7), iVar1 == 0x69)))) &&
       (iVar1 = TacticalAIGroup::commander(pTVar7), iVar1 == -1)) {
      iVar1 = numberUngroupedWarBoats(this);
      iVar2 = TacticalAIGroup::numberUnits(pTVar7);
      if (iVar2 < 1) {
        if (iVar1 == 0) {
          numberExtraGroupedWarBoats(this);
        }
        if ((this->workingArea).numberValue == 0) {
          return;
        }
        iVar1 = selectBestCommander(this,&this->workingArea);
        TacticalAIGroup::addUnit(pTVar7,iVar1,this->md);
        TacticalAIGroup::setSpecificCommander(pTVar7,iVar1,this->md);
        iVar1 = TacticalAIGroup::action(pTVar7);
        if (iVar1 != 0) {
          iVar1 = TacticalAIGroup::action(pTVar7);
          goto joined_r0x004fea59;
        }
      }
      else {
        iVar1 = selectBestCommander(this,pTVar7);
        TacticalAIGroup::setSpecificCommander(pTVar7,iVar1,this->md);
        iVar1 = TacticalAIGroup::action(pTVar7);
        if (iVar1 != 0) {
          iVar1 = TacticalAIGroup::action(pTVar7);
joined_r0x004fea59:
          if (iVar1 != 1) goto LAB_004fea63;
        }
      }
      setAllGroupLocations(this,pTVar7);
    }
LAB_004fea63:
    pTVar7 = pTVar7->next;
  } while( true );
}

// --------------------------------------------------

// Function: numberUngroupedWarBoats
// Address: 004ff4e0
/* WARNING: Variable defined which should be unmapped: rNum */
/* public: int __thiscall TribeTacticalAIModule::numberUngroupedWarBoats(void) */

int __thiscall TribeTacticalAIModule::numberUngroupedWarBoats(TribeTacticalAIModule *this)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int rNum;
  int local_c;
  int i;
  int local_4;
  
  local_c = 0;
  local_4 = 0;
  (this->workingArea).numberValue = 0;
  if (0 < (this->boats).numberValue) {
    do {
      if ((this->boats).maximumSizeValue + -1 < local_4) {
        piVar1 = (int *)operator_new(local_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->boats).maximumSizeValue) {
            do {
              if (local_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->boats).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->boats).maximumSizeValue);
          }
          operator_delete((this->boats).value);
          (this->boats).value = piVar1;
          (this->boats).maximumSizeValue = local_4 + 1;
        }
      }
      pTVar3 = groupUnitIsIn(this,(this->boats).value[local_4]);
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((this->boats).maximumSizeValue + -1 < local_4) {
          piVar1 = (int *)operator_new(local_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->boats).maximumSizeValue) {
              do {
                if (local_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (this->boats).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (this->boats).maximumSizeValue);
            }
            operator_delete((this->boats).value);
            (this->boats).value = piVar1;
            (this->boats).maximumSizeValue = local_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (this->boats).value[local_4];
        iVar4 = (this->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((this->workingArea).maximumSizeValue <= iVar5) break;
            if ((this->workingArea).value[iVar5] == iVar2) goto LAB_004ff6b2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((this->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (this->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (this->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (this->workingArea).maximumSizeValue);
            }
            operator_delete((this->workingArea).value);
            (this->workingArea).value = piVar1;
            (this->workingArea).maximumSizeValue = iVar4;
          }
        }
        (this->workingArea).value[(this->workingArea).numberValue] = iVar2;
        (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004ff6b2:
        local_c = local_c + 1;
      }
      local_4 = local_4 + 1;
    } while (local_4 < (this->boats).numberValue);
  }
  return local_c;
}

// --------------------------------------------------

// Function: numberExtraGroupedWarBoats
// Address: 004ff6e0
/* WARNING: Variable defined which should be unmapped: j */
/* public: int __thiscall TribeTacticalAIModule::numberExtraGroupedWarBoats(void) */

int __thiscall TribeTacticalAIModule::numberExtraGroupedWarBoats(TribeTacticalAIModule *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  TacticalAIGroup *this_00;
  int j;
  int tempCount;
  int rNum;
  int local_8;
  
  local_8 = 0;
  (this->workingArea).numberValue = 0;
  this_00 = (this->groups).next;
  if (this_00 != &this->groups) {
    do {
      if (this_00 == (TacticalAIGroup *)0x0) {
        return local_8;
      }
      iVar1 = TacticalAIGroup::type(this_00);
      if ((((((iVar1 == 0x67) || (iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x68)) ||
            (iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x69)) ||
           ((iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x6a ||
            (iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x6b)))) ||
          (iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x6c)) &&
         ((iVar1 = TacticalAIGroup::action(this_00), iVar1 == 1 ||
          (iVar1 = TacticalAIGroup::action(this_00), iVar1 == 0)))) {
        iVar1 = TacticalAIGroup::numberUnits(this_00);
        iVar2 = TacticalAIGroup::desiredNumberUnits(this_00);
        if (iVar2 < iVar1) {
          rNum = TacticalAIGroup::numberUnits(this_00);
          tempCount = 0;
          iVar1 = TacticalAIGroup::desiredNumberUnits(this_00);
          if (iVar1 < rNum) {
            do {
              iVar1 = TacticalAIGroup::numberUnits(this_00);
              if (iVar1 <= tempCount) break;
              iVar1 = TacticalAIGroup::unit(this_00,tempCount);
              iVar2 = TacticalAIGroup::commander(this_00);
              if (iVar1 != iVar2) {
                rNum = rNum + -1;
                iVar2 = TacticalAIGroup::unit(this_00,tempCount);
                iVar1 = (this->workingArea).numberValue;
                iVar3 = 0;
                if (0 < iVar1) {
                  do {
                    if ((this->workingArea).maximumSizeValue <= iVar3) break;
                    if ((this->workingArea).value[iVar3] == iVar2) goto LAB_004ff8a6;
                    iVar3 = iVar3 + 1;
                  } while (iVar3 < iVar1);
                }
                if ((this->workingArea).maximumSizeValue + -1 < iVar1) {
                  iVar1 = iVar1 + 1;
                  piVar4 = (int *)operator_new(iVar1 * 4);
                  if (piVar4 != (int *)0x0) {
                    iVar3 = 0;
                    if (0 < (this->workingArea).maximumSizeValue) {
                      do {
                        if (iVar1 <= iVar3) break;
                        iVar5 = iVar3 + 1;
                        piVar4[iVar3] = (this->workingArea).value[iVar3];
                        iVar3 = iVar5;
                      } while (iVar5 < (this->workingArea).maximumSizeValue);
                    }
                    operator_delete((this->workingArea).value);
                    (this->workingArea).value = piVar4;
                    (this->workingArea).maximumSizeValue = iVar1;
                  }
                }
                (this->workingArea).value[(this->workingArea).numberValue] = iVar2;
                (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004ff8a6:
                local_8 = local_8 + 1;
              }
              tempCount = tempCount + 1;
              iVar1 = TacticalAIGroup::desiredNumberUnits(this_00);
            } while (iVar1 < rNum);
          }
        }
      }
      this_00 = this_00->next;
    } while (this_00 != &this->groups);
  }
  return local_8;
}

// --------------------------------------------------

// Function: numberUngroupedFishingBoats
// Address: 004ff8e0
/* WARNING: Variable defined which should be unmapped: rNum */
/* public: int __thiscall TribeTacticalAIModule::numberUngroupedFishingBoats(void) */

int __thiscall TribeTacticalAIModule::numberUngroupedFishingBoats(TribeTacticalAIModule *this)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int rNum;
  int local_c;
  int i;
  int local_4;
  
  local_c = 0;
  local_4 = 0;
  (this->workingArea).numberValue = 0;
  if (0 < (this->fishingBoats).numberValue) {
    do {
      if ((this->fishingBoats).maximumSizeValue + -1 < local_4) {
        piVar1 = (int *)operator_new(local_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->fishingBoats).maximumSizeValue) {
            do {
              if (local_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->fishingBoats).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->fishingBoats).maximumSizeValue);
          }
          operator_delete((this->fishingBoats).value);
          (this->fishingBoats).value = piVar1;
          (this->fishingBoats).maximumSizeValue = local_4 + 1;
        }
      }
      pTVar3 = groupUnitIsIn(this,(this->fishingBoats).value[local_4]);
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((this->fishingBoats).maximumSizeValue + -1 < local_4) {
          piVar1 = (int *)operator_new(local_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->fishingBoats).maximumSizeValue) {
              do {
                if (local_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (this->fishingBoats).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (this->fishingBoats).maximumSizeValue);
            }
            operator_delete((this->fishingBoats).value);
            (this->fishingBoats).value = piVar1;
            (this->fishingBoats).maximumSizeValue = local_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (this->fishingBoats).value[local_4];
        iVar4 = (this->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((this->workingArea).maximumSizeValue <= iVar5) break;
            if ((this->workingArea).value[iVar5] == iVar2) goto LAB_004ffab2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((this->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (this->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (this->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (this->workingArea).maximumSizeValue);
            }
            operator_delete((this->workingArea).value);
            (this->workingArea).value = piVar1;
            (this->workingArea).maximumSizeValue = iVar4;
          }
        }
        (this->workingArea).value[(this->workingArea).numberValue] = iVar2;
        (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004ffab2:
        local_c = local_c + 1;
      }
      local_4 = local_4 + 1;
    } while (local_4 < (this->fishingBoats).numberValue);
  }
  return local_c;
}

// --------------------------------------------------

// Function: numberUngroupedTradeBoats
// Address: 004ffae0
/* WARNING: Variable defined which should be unmapped: rNum */
/* public: int __thiscall TribeTacticalAIModule::numberUngroupedTradeBoats(void) */

int __thiscall TribeTacticalAIModule::numberUngroupedTradeBoats(TribeTacticalAIModule *this)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int rNum;
  int local_c;
  int i;
  int local_4;
  
  local_c = 0;
  local_4 = 0;
  (this->workingArea).numberValue = 0;
  if (0 < (this->tradeBoats).numberValue) {
    do {
      if ((this->tradeBoats).maximumSizeValue + -1 < local_4) {
        piVar1 = (int *)operator_new(local_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->tradeBoats).maximumSizeValue) {
            do {
              if (local_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->tradeBoats).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->tradeBoats).maximumSizeValue);
          }
          operator_delete((this->tradeBoats).value);
          (this->tradeBoats).value = piVar1;
          (this->tradeBoats).maximumSizeValue = local_4 + 1;
        }
      }
      pTVar3 = groupUnitIsIn(this,(this->tradeBoats).value[local_4]);
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((this->tradeBoats).maximumSizeValue + -1 < local_4) {
          piVar1 = (int *)operator_new(local_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->tradeBoats).maximumSizeValue) {
              do {
                if (local_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (this->tradeBoats).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (this->tradeBoats).maximumSizeValue);
            }
            operator_delete((this->tradeBoats).value);
            (this->tradeBoats).value = piVar1;
            (this->tradeBoats).maximumSizeValue = local_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (this->tradeBoats).value[local_4];
        iVar4 = (this->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((this->workingArea).maximumSizeValue <= iVar5) break;
            if ((this->workingArea).value[iVar5] == iVar2) goto LAB_004ffcb2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((this->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (this->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (this->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (this->workingArea).maximumSizeValue);
            }
            operator_delete((this->workingArea).value);
            (this->workingArea).value = piVar1;
            (this->workingArea).maximumSizeValue = iVar4;
          }
        }
        (this->workingArea).value[(this->workingArea).numberValue] = iVar2;
        (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004ffcb2:
        local_c = local_c + 1;
      }
      local_4 = local_4 + 1;
    } while (local_4 < (this->tradeBoats).numberValue);
  }
  return local_c;
}

// --------------------------------------------------

// Function: numberUngroupedTransportBoats
// Address: 004ffce0
/* WARNING: Variable defined which should be unmapped: rNum */
/* public: int __thiscall TribeTacticalAIModule::numberUngroupedTransportBoats(void) */

int __thiscall TribeTacticalAIModule::numberUngroupedTransportBoats(TribeTacticalAIModule *this)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int rNum;
  int local_c;
  int i;
  int local_4;
  
  local_c = 0;
  local_4 = 0;
  (this->workingArea).numberValue = 0;
  if (0 < (this->transportBoats).numberValue) {
    do {
      if ((this->transportBoats).maximumSizeValue + -1 < local_4) {
        piVar1 = (int *)operator_new(local_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->transportBoats).maximumSizeValue) {
            do {
              if (local_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->transportBoats).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->transportBoats).maximumSizeValue);
          }
          operator_delete((this->transportBoats).value);
          (this->transportBoats).value = piVar1;
          (this->transportBoats).maximumSizeValue = local_4 + 1;
        }
      }
      pTVar3 = groupUnitIsIn(this,(this->transportBoats).value[local_4]);
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((this->transportBoats).maximumSizeValue + -1 < local_4) {
          piVar1 = (int *)operator_new(local_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->transportBoats).maximumSizeValue) {
              do {
                if (local_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (this->transportBoats).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (this->transportBoats).maximumSizeValue);
            }
            operator_delete((this->transportBoats).value);
            (this->transportBoats).value = piVar1;
            (this->transportBoats).maximumSizeValue = local_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (this->transportBoats).value[local_4];
        iVar4 = (this->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((this->workingArea).maximumSizeValue <= iVar5) break;
            if ((this->workingArea).value[iVar5] == iVar2) goto LAB_004ffeb2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((this->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (this->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (this->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (this->workingArea).maximumSizeValue);
            }
            operator_delete((this->workingArea).value);
            (this->workingArea).value = piVar1;
            (this->workingArea).maximumSizeValue = iVar4;
          }
        }
        (this->workingArea).value[(this->workingArea).numberValue] = iVar2;
        (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004ffeb2:
        local_c = local_c + 1;
      }
      local_4 = local_4 + 1;
    } while (local_4 < (this->transportBoats).numberValue);
  }
  return local_c;
}

// --------------------------------------------------

// Function: displayBoatGroups
// Address: 004ffee0
// [HELPER] s_____Gather_Location___f___f__: "    Gather Location=(%f, %f)."
// [HELPER] s_____Location___f___f__: "    Location=(%f, %f)."
// [HELPER] s_____NumUnits__d__DesNumUnits__d_: "    NumUnits=%d, DesNumUnits=%d, OrgNumUnits=%d, Action=%d, inUse=%d."
// [HELPER] s_____Retreat_Location___f___f__: "    Retreat Location=(%f, %f)."
// [HELPER] s_____Target_Location___f___f__: "    Target Location=(%f, %f)."
// [HELPER] s_____Target__d__CommanderID__d__H: "    Target=%d, CommanderID=%d, HP(%d/%d), AssistGroup=%d."
// [HELPER] s_____Unit___d_: "    Unit #%d."
// [HELPER] s_____Unit__d__state__d__action__d: "    Unit %d: state=%d, action=%d, target=%d, order=%d, priority=%d, location=..."
/* public: void __thiscall TribeTacticalAIModule::displayBoatGroups(void) */

void __thiscall TribeTacticalAIModule::displayBoatGroups(TribeTacticalAIModule *this)
{
  int iVar1;
  int iVar2;
  Waypoint *pWVar3;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar4;
  int iVar5;
  int iVar6;
  AIModule *extraout_ECX;
  AIModule *extraout_ECX_00;
  AIModule *extraout_ECX_01;
  AIModule *extraout_ECX_02;
  AIModule *extraout_ECX_03;
  AIModule *extraout_ECX_04;
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
  uint uVar7;
  AIModule *this_11;
  TacticalAIGroup *this_12;
  undefined8 uVar8;
  undefined8 uVar9;
  double dVar10;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this);
  this_12 = (this->groups).next;
  if (this_12 != &this->groups) {
    do {
      if (this_12 == (TacticalAIGroup *)0x0) {
        return;
      }
      iVar1 = TacticalAIGroup::type(this_12);
      if ((((iVar1 == 0x67) || (iVar1 = TacticalAIGroup::type(this_12), iVar1 == 0x68)) ||
          (iVar1 = TacticalAIGroup::type(this_12), iVar1 == 0x69)) ||
         (((iVar1 = TacticalAIGroup::type(this_12), iVar1 == 0x6b ||
           (iVar1 = TacticalAIGroup::type(this_12), iVar1 == 0x6c)) ||
          (iVar1 = TacticalAIGroup::type(this_12), iVar1 == 0x6a)))) {
        iVar1 = TacticalAIGroup::type(this_12);
        if (iVar1 == 0x67) {
          TacticalAIGroup::type(this_12);
          TacticalAIGroup::id(this_12);
          this_01 = extraout_ECX;
LAB_00500028:
          AIModule::logCommonHistory(this_01,(char *)this);
        }
        else {
          iVar1 = TacticalAIGroup::type(this_12);
          if (iVar1 == 0x68) {
            TacticalAIGroup::type(this_12);
            TacticalAIGroup::id(this_12);
            this_01 = extraout_ECX_00;
            goto LAB_00500028;
          }
          iVar1 = TacticalAIGroup::type(this_12);
          if (iVar1 == 0x69) {
            TacticalAIGroup::type(this_12);
            TacticalAIGroup::id(this_12);
            this_01 = extraout_ECX_01;
            goto LAB_00500028;
          }
          iVar1 = TacticalAIGroup::type(this_12);
          if (iVar1 == 0x6b) {
            TacticalAIGroup::type(this_12);
            TacticalAIGroup::id(this_12);
            this_01 = extraout_ECX_02;
            goto LAB_00500028;
          }
          iVar1 = TacticalAIGroup::type(this_12);
          if (iVar1 == 0x6c) {
            TacticalAIGroup::type(this_12);
            TacticalAIGroup::id(this_12);
            this_01 = extraout_ECX_03;
            goto LAB_00500028;
          }
          iVar1 = TacticalAIGroup::type(this_12);
          if (iVar1 == 0x6a) {
            TacticalAIGroup::type(this_12);
            TacticalAIGroup::id(this_12);
            this_01 = extraout_ECX_04;
            goto LAB_00500028;
          }
        }
        iVar1 = TacticalAIGroup::inUse(this_12);
        iVar2 = TacticalAIGroup::action(this_12);
        uVar9 = CONCAT44(iVar1,iVar2);
        iVar1 = TacticalAIGroup::originalUnitNumber(this_12);
        iVar2 = TacticalAIGroup::desiredNumberUnits(this_12);
        uVar8 = CONCAT44(iVar1,iVar2);
        iVar1 = TacticalAIGroup::numberUnits(this_12);
        AIModule::logCommonHistory
                  (this_02,(char *)this,s_____NumUnits__d__DesNumUnits__d_,iVar1,uVar8,uVar9);
        iVar1 = TacticalAIGroup::assistGroupID(this_12);
        iVar2 = TacticalAIGroup::originalHitPoints(this_12);
        uVar9 = CONCAT44(iVar1,iVar2);
        iVar1 = TacticalAIGroup::currentHitPoints(this_12,this->md);
        iVar2 = TacticalAIGroup::commander(this_12);
        uVar8 = CONCAT44(iVar1,iVar2);
        iVar1 = TacticalAIGroup::target(this_12);
        AIModule::logCommonHistory
                  (this_03,(char *)this,s_____Target__d__CommanderID__d__H,iVar1,uVar8,uVar9);
        pWVar3 = TacticalAIGroup::location(this_12);
        dVar10 = (double)pWVar3->y;
        pWVar3 = TacticalAIGroup::location(this_12);
        AIModule::logCommonHistory
                  (this_04,(char *)this,s_____Location___f___f__,(double)pWVar3->x,dVar10);
        pWVar3 = TacticalAIGroup::gatherLocation(this_12);
        dVar10 = (double)pWVar3->y;
        pWVar3 = TacticalAIGroup::gatherLocation(this_12);
        AIModule::logCommonHistory
                  (this_05,(char *)this,s_____Gather_Location___f___f__,(double)pWVar3->x,dVar10);
        pWVar3 = TacticalAIGroup::retreatLocation(this_12);
        dVar10 = (double)pWVar3->y;
        pWVar3 = TacticalAIGroup::retreatLocation(this_12);
        AIModule::logCommonHistory
                  (this_06,(char *)this,s_____Retreat_Location___f___f__,(double)pWVar3->x,dVar10);
        pWVar3 = TacticalAIGroup::targetLocation(this_12);
        dVar10 = (double)pWVar3->y;
        pWVar3 = TacticalAIGroup::targetLocation(this_12);
        AIModule::logCommonHistory
                  (this_07,(char *)this,s_____Target_Location___f___f__,(double)pWVar3->x,dVar10);
        iVar2 = 0;
        iVar1 = TacticalAIGroup::numberUnits(this_12);
        if (0 < iVar1) {
          do {
            TacticalAIGroup::unit(this_12,iVar2);
            AIModule::logCommonHistory(this_08,(char *)this,s_____Unit___d_);
            iVar1 = TacticalAIGroup::unit(this_12,iVar2);
            this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar1);
            if (this_00 == (RGE_Static_Object *)0x0) {
              AIModule::logCommonHistory(this_09,(char *)this);
            }
            else {
              pUVar4 = RGE_Static_Object::unitAI(this_00);
              if (pUVar4 == (UnitAIModule *)0x0) {
                AIModule::logCommonHistory(this_10,(char *)this);
              }
              else {
                pUVar4 = RGE_Static_Object::unitAI(this_00);
                UnitAIModule::currentOrderPriority(pUVar4);
                pUVar4 = RGE_Static_Object::unitAI(this_00);
                UnitAIModule::currentOrder(pUVar4);
                pUVar4 = RGE_Static_Object::unitAI(this_00);
                iVar1 = UnitAIModule::currentTarget(pUVar4);
                pUVar4 = RGE_Static_Object::unitAI(this_00);
                iVar5 = UnitAIModule::currentAction(pUVar4);
                uVar7 = (uint)this_00->object_state;
                iVar6 = TacticalAIGroup::unit(this_12,iVar2);
                AIModule::logCommonHistory
                          (this_11,(char *)this,s_____Unit__d__state__d__action__d,iVar6,uVar7,iVar5
                           ,iVar1);
              }
            }
            iVar2 = iVar2 + 1;
            iVar1 = TacticalAIGroup::numberUnits(this_12);
          } while (iVar2 < iVar1);
        }
      }
      this_12 = this_12->next;
    } while (this_12 != &this->groups);
  }
  return;
}

// --------------------------------------------------

// Function: createGroup
// Address: 00500260
/* public: class TacticalAIGroup * __thiscall TribeTacticalAIModule::createGroup(int) */

TacticalAIGroup * __thiscall
TribeTacticalAIModule::createGroup(TribeTacticalAIModule *this,int param_1)
{
  TacticalAIGroup *pTVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560b8b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar3 = (TacticalAIGroup *)operator_new(0x330);
  local_4 = 0;
  if (pTVar3 == (TacticalAIGroup *)0x0) {
    pTVar3 = (TacticalAIGroup *)0x0;
  }
  else {
    pTVar3 = (TacticalAIGroup *)TacticalAIGroup::TacticalAIGroup(pTVar3);
  }
  local_4 = 0xffffffff;
  if (pTVar3 == (TacticalAIGroup *)0x0) {
    *unaff_FS_OFFSET = local_c;
    return (TacticalAIGroup *)0x0;
  }
  pTVar3->next = &this->groups;
  pTVar1 = (this->groups).prev;
  pTVar3->prev = pTVar1;
  pTVar1->next = pTVar3;
  (this->groups).prev = pTVar3;
  if (param_1 == 1) {
    iVar2 = this->groupIDValue;
    this->groupIDValue = iVar2 + 1;
    TacticalAIGroup::setID(pTVar3,iVar2);
    this->numberGroupsValue = this->numberGroupsValue + 1;
  }
  *unaff_FS_OFFSET = local_c;
  return pTVar3;
}

// --------------------------------------------------

// Function: removeGroup
// Address: 00500320
/* public: int __thiscall TribeTacticalAIModule::removeGroup(int) */

int __thiscall TribeTacticalAIModule::removeGroup(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  TacticalAIGroup *this_00;
  
  this_00 = (this->groups).next;
  if (this_00 != &this->groups) {
    while (this_00 != (TacticalAIGroup *)0x0) {
      iVar1 = TacticalAIGroup::id(this_00);
      if (iVar1 == param_1) {
        this_00->prev->next = this_00->next;
        this_00->next->prev = this_00->prev;
        if (this_00 != (TacticalAIGroup *)0x0) {
          (**(code **)this_00->_padding_)(1);
        }
        this->numberGroupsValue = this->numberGroupsValue + -1;
        return 1;
      }
      this_00 = this_00->next;
      if (this_00 == &this->groups) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: removeAllGroups
// Address: 005003a0
/* public: int __thiscall TribeTacticalAIModule::removeAllGroups(int) */

int __thiscall TribeTacticalAIModule::removeAllGroups(TribeTacticalAIModule *this,int param_1)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *this_00;
  
  this_00 = (this->groups).next;
  if (this_00 != &this->groups) {
    do {
      if (this_00 == (TacticalAIGroup *)0x0) {
        return 1;
      }
      iVar2 = TacticalAIGroup::type(this_00);
      if ((iVar2 == param_1) || (param_1 == -1)) {
        this_00->prev->next = this_00->next;
        this_00->next->prev = this_00->prev;
        piVar1 = &this_00->_padding_;
        this_00 = this_00->prev;
        (**(code **)*piVar1)(1);
        this->numberGroupsValue = this->numberGroupsValue + -1;
      }
      this_00 = this_00->next;
    } while (this_00 != &this->groups);
  }
  return 1;
}

// --------------------------------------------------

// Function: group
// Address: 00500420
/* public: class TacticalAIGroup * __thiscall TribeTacticalAIModule::group(int,int,int,int) */

TacticalAIGroup * __thiscall
TribeTacticalAIModule::group
          (TribeTacticalAIModule *this,int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  TacticalAIGroup *this_00;
  
  this_00 = (this->groups).next;
  if (this_00 != &this->groups) {
    while (this_00 != (TacticalAIGroup *)0x0) {
      if (((((param_1 == -1) || (iVar1 = TacticalAIGroup::id(this_00), iVar1 == param_1)) &&
           ((param_2 == -1 || (iVar1 = TacticalAIGroup::type(this_00), iVar1 == param_2)))) &&
          ((param_3 == -1 || (iVar1 = TacticalAIGroup::action(this_00), iVar1 == param_3)))) &&
         ((param_4 == -1 || (iVar1 = TacticalAIGroup::target(this_00), iVar1 == param_4)))) {
        return this_00;
      }
      this_00 = this_00->next;
      if (this_00 == &this->groups) {
        return (TacticalAIGroup *)0x0;
      }
    }
  }
  return (TacticalAIGroup *)0x0;
}

// --------------------------------------------------

// Function: bestGroup
// Address: 005004c0
/* public: class TacticalAIGroup * __thiscall TribeTacticalAIModule::bestGroup(int,int,int,struct
   XYPoint &,int) */

TacticalAIGroup * __thiscall
TribeTacticalAIModule::bestGroup
          (TribeTacticalAIModule *this,int param_1,int param_2,int param_3,XYPoint *param_4,
          int param_5)
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  RGE_Static_Object *this_00;
  TacticalAIGroup *this_01;
  TacticalAIGroup *this_02;
  int bGValue;
  int local_10;
  TacticalAIGroup *bG;
  TacticalAIGroup *local_8;
  
  this_02 = (this->groups).next;
  local_8 = (TacticalAIGroup *)0x0;
  local_10 = -1;
  if (this_02 != &this->groups) {
    do {
      bG = &this->groups;
      if (this_02 == (TacticalAIGroup *)0x0) {
        return local_8;
      }
      if (((param_1 == -1) || (iVar3 = TacticalAIGroup::type(this_02), iVar3 == param_1)) &&
         ((param_2 == -1 || (iVar3 = TacticalAIGroup::action(this_02), iVar3 == param_2)))) {
        if (param_1 == 0x6a) {
          bVar1 = true;
          this_01 = (this->groups).next;
          if (this_01 != bG) {
            do {
              if (this_01 == (TacticalAIGroup *)0x0) break;
              if (!bVar1) goto LAB_00500651;
              iVar3 = TacticalAIGroup::id(this_02);
              iVar4 = TacticalAIGroup::assistGroupID(this_01);
              if (iVar4 == iVar3) {
                bVar1 = false;
              }
              this_01 = this_01->next;
            } while (this_01 != &this->groups);
          }
          if (!bVar1) goto LAB_00500651;
        }
        if (param_5 != -1) {
          iVar3 = TacticalAIGroup::commander(this_02);
          this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar3);
          if ((this_00 == (RGE_Static_Object *)0x0) ||
             (bVar2 = RGE_Static_Object::currentZone(this_00), (uint)bVar2 != param_5))
          goto LAB_00500651;
        }
        TacticalAIGroup::gatherLocation(this_02);
        __ftol();
        TacticalAIGroup::gatherLocation(this_02);
        __ftol();
        TacticalAIGroup::gatherLocation(this_02);
        __ftol();
        TacticalAIGroup::gatherLocation(this_02);
        __ftol();
        iVar3 = __ftol();
        if (((iVar3 < param_3) && (local_10 == -1)) || ((param_3 == -1 || (iVar3 < local_10)))) {
          local_10 = iVar3;
          local_8 = this_02;
        }
      }
LAB_00500651:
      bG = &this->groups;
      this_02 = this_02->next;
    } while (this_02 != bG);
  }
  return local_8;
}

// --------------------------------------------------

// Function: readyAndIdleGroup
// Address: 00500670
/* WARNING: Variable defined which should be unmapped: bGValue */
/* public: class TacticalAIGroup * __thiscall
   TribeTacticalAIModule::readyAndIdleGroup(int,int,struct XYPoint &) */

TacticalAIGroup * __thiscall
TribeTacticalAIModule::readyAndIdleGroup
          (TribeTacticalAIModule *this,int param_1,int param_2,XYPoint *param_3)
{
  int iVar1;
  int iVar2;
  TacticalAIGroup *this_00;
  int bGValue;
  int local_c;
  TacticalAIGroup *bG;
  TacticalAIGroup *local_4;
  
  this_00 = (this->groups).next;
  local_4 = (TacticalAIGroup *)0x0;
  local_c = -1;
  if (this_00 != &this->groups) {
    do {
      if (this_00 == (TacticalAIGroup *)0x0) {
        return local_4;
      }
      if ((param_1 == -1) || (iVar1 = TacticalAIGroup::type(this_00), iVar1 == param_1)) {
        iVar1 = TacticalAIGroup::desiredNumberUnits(this_00);
        iVar2 = TacticalAIGroup::numberUnits(this_00);
        if ((iVar1 <= iVar2) &&
           ((iVar1 = TacticalAIGroup::isGathered(this_00,this,this->md), iVar1 != 0 &&
            (iVar1 = TacticalAIGroup::allUnitsIdle(this_00,this->md,1), iVar1 != 0)))) {
          TacticalAIGroup::gatherLocation(this_00);
          __ftol();
          TacticalAIGroup::gatherLocation(this_00);
          __ftol();
          TacticalAIGroup::gatherLocation(this_00);
          __ftol();
          TacticalAIGroup::gatherLocation(this_00);
          __ftol();
          iVar1 = __ftol();
          if (((iVar1 < param_2) && (local_c == -1)) || (iVar1 < local_c)) {
            local_c = iVar1;
            local_4 = this_00;
          }
        }
      }
      this_00 = this_00->next;
    } while (this_00 != &this->groups);
  }
  return local_4;
}

// --------------------------------------------------

// Function: addToGroup
// Address: 005007b0
/* public: int __thiscall TribeTacticalAIModule::addToGroup(int,int) */

int __thiscall
TribeTacticalAIModule::addToGroup(TribeTacticalAIModule *this,int param_1,int param_2)
{
  TacticalAIGroup *this_00;
  int iVar1;
  
  this_00 = group(this,param_2,-1,-1,-1);
  if (this_00 == (TacticalAIGroup *)0x0) {
    return 0;
  }
  iVar1 = TacticalAIGroup::addUnit(this_00,param_1,this->md);
  return iVar1;
}

// --------------------------------------------------

// Function: removeFromGroup
// Address: 005007f0
/* public: int __thiscall TribeTacticalAIModule::removeFromGroup(int,int) */

int __thiscall
TribeTacticalAIModule::removeFromGroup(TribeTacticalAIModule *this,int param_1,int param_2)
{
  TacticalAIGroup *this_00;
  int iVar1;
  int iVar2;
  
  this_00 = group(this,param_2,-1,-1,-1);
  if (this_00 == (TacticalAIGroup *)0x0) {
    return 0;
  }
  iVar1 = TacticalAIGroup::removeUnit(this_00,param_1,this->md);
  iVar2 = TacticalAIGroup::numberUnits(this_00);
  if (iVar2 == 0) {
    removeGroup(this,param_2);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: removeFromGroup
// Address: 00500850
/* public: int __thiscall TribeTacticalAIModule::removeFromGroup(int) */

int __thiscall TribeTacticalAIModule::removeFromGroup(TribeTacticalAIModule *this,int param_1)
{
  TacticalAIGroup *this_00;
  int iVar1;
  int iVar2;
  
  this_00 = groupUnitIsIn(this,param_1);
  if (this_00 == (TacticalAIGroup *)0x0) {
    return 0;
  }
  iVar1 = TacticalAIGroup::removeUnit(this_00,param_1,this->md);
  iVar2 = TacticalAIGroup::numberUnits(this_00);
  if (iVar2 == 0) {
    iVar2 = TacticalAIGroup::id(this_00);
    removeGroup(this,iVar2);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: groupUnitIsIn
// Address: 005008a0
/* public: class TacticalAIGroup * __thiscall TribeTacticalAIModule::groupUnitIsIn(int) */

TacticalAIGroup * __thiscall
TribeTacticalAIModule::groupUnitIsIn(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  TacticalAIGroup *this_00;
  
  this_00 = (this->groups).next;
  if (this_00 != &this->groups) {
    while (this_00 != (TacticalAIGroup *)0x0) {
      iVar1 = TacticalAIGroup::containsUnit(this_00,param_1);
      if (iVar1 == 1) {
        return this_00;
      }
      this_00 = this_00->next;
      if (this_00 == &this->groups) {
        return (TacticalAIGroup *)0x0;
      }
    }
  }
  return (TacticalAIGroup *)0x0;
}

// --------------------------------------------------

// Function: numberGroups
// Address: 005008f0
/* WARNING: Variable defined which should be unmapped: rVal */
/* public: int __thiscall TribeTacticalAIModule::numberGroups(int,int) */

int __thiscall
TribeTacticalAIModule::numberGroups(TribeTacticalAIModule *this,int param_1,int param_2)
{
  TacticalAIGroup *this_00;
  int iVar1;
  int rVal;
  int local_4;
  
  this_00 = (this->groups).next;
  local_4 = 0;
  for (; (this_00 != &this->groups && (this_00 != (TacticalAIGroup *)0x0)); this_00 = this_00->next)
{
    if (((param_1 == -1) || (iVar1 = TacticalAIGroup::type(this_00), iVar1 == param_1)) &&
       ((param_2 == -1 || (iVar1 = TacticalAIGroup::action(this_00), iVar1 == param_2)))) {
      local_4 = local_4 + 1;
    }
  }
  return local_4;
}

// --------------------------------------------------

// Function: numberUnitsInGroups
// Address: 00500950
/* public: int __thiscall TribeTacticalAIModule::numberUnitsInGroups(int) */

int __thiscall TribeTacticalAIModule::numberUnitsInGroups(TribeTacticalAIModule *this,int param_1)
{
  TacticalAIGroup *this_00;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (this_00 = (this->groups).next;
      (this_00 != &this->groups && (this_00 != (TacticalAIGroup *)0x0)); this_00 = this_00->next) {
    if ((param_1 == -1) || (iVar1 = TacticalAIGroup::type(this_00), iVar1 == param_1)) {
      iVar1 = TacticalAIGroup::numberUnits(this_00);
      iVar2 = iVar2 + iVar1;
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: numberItemsToAttack
// Address: 005009a0
/* public: int __thiscall TribeTacticalAIModule::numberItemsToAttack(void) */

int __thiscall TribeTacticalAIModule::numberItemsToAttack(TribeTacticalAIModule *this)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if ((this->playersToAttack).maximumSizeValue + -1 < 0) {
    piVar1 = (int *)operator_new(4);
    if (piVar1 != (int *)0x0) {
      iVar3 = 0;
      if (0 < (this->playersToAttack).maximumSizeValue) {
        do {
          if (0 < iVar3) break;
          iVar2 = iVar3 + 1;
          piVar1[iVar3] = (this->playersToAttack).value[iVar3];
          iVar3 = iVar2;
        } while (iVar2 < (this->playersToAttack).maximumSizeValue);
      }
      operator_delete((this->playersToAttack).value);
      (this->playersToAttack).value = piVar1;
      (this->playersToAttack).maximumSizeValue = 1;
    }
  }
  iVar3 = TribeInformationAIModule::numberGameIDsOwnedBy
                    (&this->md->informationAI,-1,*(this->playersToAttack).value);
  return iVar3;
}

// --------------------------------------------------

// Function: itemToCapture
// Address: 00500a30
/* public: int __thiscall TribeTacticalAIModule::itemToCapture(void) */

int __thiscall TribeTacticalAIModule::itemToCapture(TribeTacticalAIModule *this)
{
  int iVar1;
  TacticalAIGroup *pTVar2;
  
  iVar1 = TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI);
  if (iVar1 == 0) {
    iVar1 = TribeStrategyAIModule::targetID(&this->md->strategyAI);
    pTVar2 = group(this,-1,-1,-1,iVar1);
    if (pTVar2 == (TacticalAIGroup *)0x0) {
      return iVar1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: itemToBringToArea
// Address: 00500a80
/* public: int __thiscall TribeTacticalAIModule::itemToBringToArea(void) */

int __thiscall TribeTacticalAIModule::itemToBringToArea(TribeTacticalAIModule *this)
{
  int iVar1;
  TacticalAIGroup *pTVar2;
  
  iVar1 = TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI);
  if (iVar1 == 4) {
    iVar1 = TribeStrategyAIModule::secondTargetID(&this->md->strategyAI);
    pTVar2 = group(this,-1,-1,-1,iVar1);
    if (pTVar2 == (TacticalAIGroup *)0x0) {
      return iVar1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: numberItemsToDefend
// Address: 00500ad0
/* public: int __thiscall TribeTacticalAIModule::numberItemsToDefend(void) */

int __thiscall TribeTacticalAIModule::numberItemsToDefend(TribeTacticalAIModule *this)
{
  int iVar1;
  
  iVar1 = TribeInformationAIModule::numberItemsToDefend(&this->md->informationAI);
  return iVar1;
}

// --------------------------------------------------

// Function: attackLimiterTime
// Address: 00500af0
/* public: unsigned long __thiscall TribeTacticalAIModule::attackLimiterTime(int) */

ulong __thiscall TribeTacticalAIModule::attackLimiterTime(TribeTacticalAIModule *this,int param_1)
{
  ulong uVar1;
  
  if (this->sn[0x47] == 1) {
    uVar1 = this->randomizedAttackSeparationTime;
    if (this->sn[0x30] <= (int)uVar1) {
      return this->sn[0x30];
    }
  }
  else {
    if (param_1 == 0x2e) {
      return this->randomizedAttackSeparationTime;
    }
    uVar1 = this->sn[0x30];
  }
  return uVar1;
}

// --------------------------------------------------

// Function: resetAttackSeparationTime
// Address: 00500b30
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* public: void __thiscall TribeTacticalAIModule::resetAttackSeparationTime(void) */

void __thiscall TribeTacticalAIModule::resetAttackSeparationTime(TribeTacticalAIModule *this)
{
  int iVar1;
  int iVar2;
  
  iVar1 = this->sn[0x66];
  if (iVar1 < 1) {
    this->randomizedAttackSeparationTime = this->sn[0x2e];
  }
  else {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x2d35);
    this->randomizedAttackSeparationTime = iVar2 % iVar1 + (this->sn[0x2e] - iVar1 / 2);
  }
  if (this->randomizedAttackSeparationTime < 0) {
    this->randomizedAttackSeparationTime = 0;
  }
  return;
}

// --------------------------------------------------

// Function: setGatherLocation
// Address: 00500ba0
/* WARNING: Variable defined which should be unmapped: centerPoint */
/* public: int __thiscall TribeTacticalAIModule::setGatherLocation(class TacticalAIGroup *) */

int __thiscall
TribeTacticalAIModule::setGatherLocation(TribeTacticalAIModule *this,TacticalAIGroup *param_1)
{
  TacticalAIGroup *this_00;
  int iVar1;
  RGE_Static_Object *pRVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  XYPoint *pXVar8;
  float fVar9;
  XYPoint centerPoint;
  XYPoint gatherPoint;
  int local_4;
  
  this_00 = param_1;
  iVar1 = TacticalAIGroup::commander(param_1);
  pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar1);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  iVar1 = TacticalAIGroup::type(param_1);
  if (iVar1 != 100) {
    iVar1 = TacticalAIGroup::type(param_1);
    if (iVar1 != 0x65) {
      iVar1 = TacticalAIGroup::type(param_1);
      param_1 = (TacticalAIGroup *)0x0;
      if (iVar1 != 0x66) goto LAB_00500c04;
    }
  }
  param_1 = (TacticalAIGroup *)0x1;
LAB_00500c04:
  pRVar3 = MainDecisionAIModule::object
                     ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  centerPoint.y = __ftol();
  gatherPoint.x = __ftol();
  iVar1 = this->sn[0x48];
  iVar5 = this->sn[0x16];
  pXVar8 = (XYPoint *)&gatherPoint.y;
  pRVar3 = pRVar2;
  iVar4 = TacticalAIGroup::desiredNumberUnits(this_00);
  iVar1 = TribeInformationAIModule::findGatherPosition
                    (&this->md->informationAI,(XYPoint *)&centerPoint.y,iVar4,(int)param_1,iVar5,
                     iVar1,pRVar3,pXVar8);
  if (iVar1 == 1) {
    fVar9 = pRVar2->world_z;
    fVar7 = (float)local_4;
    fVar6 = (float)gatherPoint.y;
  }
  else {
    fVar9 = pRVar2->world_z;
    fVar7 = pRVar2->world_y;
    fVar6 = pRVar2->world_x;
  }
  TacticalAIGroup::setGatherLocation(this_00,fVar6,fVar7,fVar9);
  return 1;
}

// --------------------------------------------------

// Function: setAllGroupLocations
// Address: 00500cc0
/* WARNING: Variable defined which should be unmapped: centerPoint */
/* public: int __thiscall TribeTacticalAIModule::setAllGroupLocations(class TacticalAIGroup *) */

int __thiscall
TribeTacticalAIModule::setAllGroupLocations(TribeTacticalAIModule *this,TacticalAIGroup *param_1)
{
  TacticalAIGroup *this_00;
  int iVar1;
  RGE_Static_Object *pRVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  XYPoint *pXVar8;
  float fVar9;
  XYPoint centerPoint;
  XYPoint gatherPoint;
  int local_4;
  
  this_00 = param_1;
  iVar1 = TacticalAIGroup::commander(param_1);
  pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar1);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  iVar1 = TacticalAIGroup::type(param_1);
  if (iVar1 == 100) {
LAB_00500d1c:
    param_1 = (TacticalAIGroup *)0x1;
  }
  else {
    iVar1 = TacticalAIGroup::type(param_1);
    if (iVar1 == 0x65) goto LAB_00500d1c;
    iVar1 = TacticalAIGroup::type(param_1);
    param_1 = (TacticalAIGroup *)0x0;
    if (iVar1 == 0x66) goto LAB_00500d1c;
  }
  pRVar3 = MainDecisionAIModule::object
                     ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  if (pRVar3 != (RGE_Static_Object *)0x0) {
    centerPoint.y = __ftol();
    gatherPoint.x = __ftol();
    iVar1 = this->sn[0x48];
    iVar5 = this->sn[0x16];
    pXVar8 = (XYPoint *)&gatherPoint.y;
    pRVar3 = pRVar2;
    iVar4 = TacticalAIGroup::desiredNumberUnits(this_00);
    iVar1 = TribeInformationAIModule::findGatherPosition
                      (&this->md->informationAI,(XYPoint *)&centerPoint.y,iVar4,(int)param_1,iVar5,
                       iVar1,pRVar3,pXVar8);
    if (iVar1 == 1) {
      fVar9 = pRVar2->world_z;
      fVar7 = (float)local_4;
      fVar6 = (float)gatherPoint.y;
      goto LAB_00500dbf;
    }
  }
  fVar9 = pRVar2->world_z;
  fVar7 = pRVar2->world_y;
  fVar6 = pRVar2->world_x;
LAB_00500dbf:
  TacticalAIGroup::setAllLocations(this_00,fVar6,fVar7,fVar9);
  return 1;
}

// --------------------------------------------------

// Function: setGroupInfluences
// Address: 00500de0
/* WARNING: Variable defined which should be unmapped: clearDistance */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TribeTacticalAIModule::setGroupInfluences(class InfluenceMap &) */

void __thiscall
TribeTacticalAIModule::setGroupInfluences(TribeTacticalAIModule *this,InfluenceMap *param_1)
{
  TacticalAIGroup *this_00;
  Waypoint *pWVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  int iVar6;
  int clearDistance;
  XYPoint min_ffffffec;
  XYPoint max;
  
  for (this_00 = (this->groups).next;
      (this_00 != &this->groups && (this_00 != (TacticalAIGroup *)0x0)); this_00 = this_00->next) {
    pWVar1 = TacticalAIGroup::gatherLocation(this_00);
    if (pWVar1->x != _DAT_00575758) {
      iVar2 = TacticalAIGroup::desiredNumberUnits(this_00);
      min_ffffffec.x =
           TribeInformationAIModule::groupInfluenceDimension(&this->md->informationAI,iVar2);
      TacticalAIGroup::gatherLocation(this_00);
      max.y = __ftol();
      TacticalAIGroup::gatherLocation(this_00);
      iVar2 = __ftol();
      TribeInformationAIModule::mapBound(&this->md->informationAI,(XYPoint *)&max.y);
      TacticalAIGroup::gatherLocation(this_00);
      min_ffffffec.y = __ftol();
      TacticalAIGroup::gatherLocation(this_00);
      max.x = __ftol();
      TribeInformationAIModule::mapBound(&this->md->informationAI,(XYPoint *)&min_ffffffec.y);
      InfluenceMap::setValue(param_1,max.y,iVar2,min_ffffffec.y,max.x,0xff);
      TacticalAIGroup::gatherLocation(this_00);
      max.y = __ftol();
      TacticalAIGroup::gatherLocation(this_00);
      iVar2 = __ftol();
      TribeInformationAIModule::mapBound(&this->md->informationAI,(XYPoint *)&max.y);
      TacticalAIGroup::gatherLocation(this_00);
      min_ffffffec.y = __ftol();
      TacticalAIGroup::gatherLocation(this_00);
      max.x = __ftol();
      TribeInformationAIModule::mapBound(&this->md->informationAI,(XYPoint *)&min_ffffffec.y);
      InfluenceMap::decrementValue(param_1,max.y,iVar2,min_ffffffec.y,max.x,'\n');
    }
  }
  iVar2 = 0;
  if (0 < (this->ungroupedSoldiers).numberValue) {
    do {
      if (((this->ungroupedSoldiers).maximumSizeValue + -1 < iVar2) &&
         (piVar3 = (int *)operator_new(iVar2 * 4 + 4), piVar3 != (int *)0x0)) {
        iVar6 = 0;
        if (0 < (this->ungroupedSoldiers).maximumSizeValue) {
          do {
            if (iVar2 + 1 <= iVar6) break;
            iVar4 = iVar6 + 1;
            piVar3[iVar6] = (this->ungroupedSoldiers).value[iVar6];
            iVar6 = iVar4;
          } while (iVar4 < (this->ungroupedSoldiers).maximumSizeValue);
        }
        operator_delete((this->ungroupedSoldiers).value);
        (this->ungroupedSoldiers).value = piVar3;
        (this->ungroupedSoldiers).maximumSizeValue = iVar2 + 1;
      }
      pRVar5 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,(this->ungroupedSoldiers).value[iVar2]);
      if (pRVar5 != (RGE_Static_Object *)0x0) {
        min_ffffffec.y = __ftol();
        max.x = __ftol();
        TribeInformationAIModule::mapBound(&this->md->informationAI,(XYPoint *)&min_ffffffec.y);
        max.y = __ftol();
        iVar6 = __ftol();
        TribeInformationAIModule::mapBound(&this->md->informationAI,(XYPoint *)&max.y);
        InfluenceMap::setValue(param_1,min_ffffffec.y,max.x,max.y,iVar6,0xff);
        TribeInformationAIModule::groupInfluenceDimension(&this->md->informationAI,1);
        min_ffffffec.y = __ftol();
        max.x = __ftol();
        TribeInformationAIModule::mapBound(&this->md->informationAI,(XYPoint *)&min_ffffffec.y);
        max.y = __ftol();
        iVar6 = __ftol();
        TribeInformationAIModule::mapBound(&this->md->informationAI,(XYPoint *)&max.y);
        InfluenceMap::decrementValue(param_1,min_ffffffec.y,max.x,max.y,iVar6,'\n');
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (this->ungroupedSoldiers).numberValue);
  }
  return;
}

// --------------------------------------------------

// Function: selectBestCommander
// Address: 00501190
/* WARNING: Variable defined which should be unmapped: bestUnit */
/* public: int __thiscall TribeTacticalAIModule::selectBestCommander(class TacticalAIGroup *) */

int __thiscall
TribeTacticalAIModule::selectBestCommander(TribeTacticalAIModule *this,TacticalAIGroup *param_1)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  int bestUnit;
  int local_8;
  
  iVar3 = -1;
  local_8 = -1;
  iVar4 = 0;
  iVar1 = TacticalAIGroup::numberUnits(param_1);
  if (0 < iVar1) {
    do {
      iVar1 = TacticalAIGroup::unit(param_1,iVar4);
      pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar1);
      if ((pRVar2 != (RGE_Static_Object *)0x0) && (pRVar2->master_obj->id != 0x7d)) {
        if (this->sn[0x4b] == 2) {
          (**(code **)(pRVar2->_padding_ + 0x10c))();
        }
        iVar1 = __ftol();
        if ((this->sn[0x4b] == 1) || (this->sn[0x4b] == 3)) {
          if ((iVar3 == -1) || (iVar1 < iVar3)) goto LAB_00501228;
        }
        else if ((iVar3 == -1) || (iVar3 < iVar1)) {
LAB_00501228:
          local_8 = TacticalAIGroup::unit(param_1,iVar4);
          iVar3 = iVar1;
        }
      }
      iVar4 = iVar4 + 1;
      iVar1 = TacticalAIGroup::numberUnits(param_1);
    } while (iVar4 < iVar1);
  }
  return local_8;
}

// --------------------------------------------------

// Function: selectBestCommander
// Address: 00501260
/* WARNING: Variable defined which should be unmapped: i */
/* public: int __thiscall TribeTacticalAIModule::selectBestCommander(class ManagedArray<int> &) */

int __thiscall
TribeTacticalAIModule::selectBestCommander(TribeTacticalAIModule *this,ManagedArray<int> *param_1)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  int i;
  int bestUnit;
  int local_8;
  
  iVar5 = -1;
  local_8 = -1;
  bestUnit = 0;
  if (0 < param_1->numberValue) {
    do {
      if (param_1->maximumSizeValue + -1 < bestUnit) {
        piVar1 = (int *)operator_new(bestUnit * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < param_1->maximumSizeValue) {
            do {
              if (bestUnit + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = param_1->value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < param_1->maximumSizeValue);
          }
          operator_delete(param_1->value);
          param_1->value = piVar1;
          param_1->maximumSizeValue = bestUnit + 1;
        }
      }
      pRVar3 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this->md,param_1->value[bestUnit]);
      if ((pRVar3 != (RGE_Static_Object *)0x0) && (pRVar3->master_obj->id != 0x7d)) {
        if (this->sn[0x4b] == 2) {
          (**(code **)(pRVar3->_padding_ + 0x10c))();
        }
        iVar4 = __ftol();
        if ((this->sn[0x4b] == 1) || (this->sn[0x4b] == 3)) {
          if ((iVar5 == -1) || (iVar4 < iVar5)) {
            if (param_1->maximumSizeValue + -1 < bestUnit) {
              piVar1 = (int *)operator_new(bestUnit * 4 + 4);
              if (piVar1 != (int *)0x0) {
                iVar5 = 0;
                if (0 < param_1->maximumSizeValue) {
                  do {
                    if (bestUnit + 1 <= iVar5) break;
                    iVar2 = iVar5 + 1;
                    piVar1[iVar5] = param_1->value[iVar5];
                    iVar5 = iVar2;
                  } while (iVar2 < param_1->maximumSizeValue);
                }
                operator_delete(param_1->value);
                param_1->value = piVar1;
                param_1->maximumSizeValue = bestUnit + 1;
              }
            }
            local_8 = param_1->value[bestUnit];
            iVar5 = iVar4;
          }
        }
        else if ((iVar5 == -1) || (iVar5 < iVar4)) {
          if (param_1->maximumSizeValue + -1 < bestUnit) {
            piVar1 = (int *)operator_new(bestUnit * 4 + 4);
            if (piVar1 != (int *)0x0) {
              iVar5 = 0;
              if (0 < param_1->maximumSizeValue) {
                do {
                  if (bestUnit + 1 <= iVar5) break;
                  iVar2 = iVar5 + 1;
                  piVar1[iVar5] = param_1->value[iVar5];
                  iVar5 = iVar2;
                } while (iVar2 < param_1->maximumSizeValue);
              }
              operator_delete(param_1->value);
              param_1->value = piVar1;
              param_1->maximumSizeValue = bestUnit + 1;
            }
          }
          local_8 = param_1->value[bestUnit];
          iVar5 = iVar4;
        }
      }
      bestUnit = bestUnit + 1;
    } while (bestUnit < param_1->numberValue);
  }
  return local_8;
}

// --------------------------------------------------

// Function: dealWithGAIAAttacker
// Address: 00501430
/* public: int __thiscall TribeTacticalAIModule::dealWithGAIAAttacker(class RGE_Static_Object
   *,class RGE_Static_Object *) */

int __thiscall
TribeTacticalAIModule::dealWithGAIAAttacker
          (TribeTacticalAIModule *this,RGE_Static_Object *param_1,RGE_Static_Object *param_2)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  float10 fVar9;
  XYPoint vPosition;
  XYZPoint point;
  
  pRVar1 = param_1;
  if ((param_1 == (RGE_Static_Object *)0x0) || (param_2 == (RGE_Static_Object *)0x0)) {
    return 0;
  }
  iVar3 = (this->civilianExplorers).numberValue;
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      if ((this->civilianExplorers).maximumSizeValue <= iVar2) break;
      if ((this->civilianExplorers).value[iVar2] == param_2->id) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  param_1 = (RGE_Static_Object *)0x0;
  vPosition.x = (int)this;
  vPosition.y = __ftol();
  __ftol();
  iVar3 = civilian(this,(XYPoint *)&vPosition.y,1,700,0x2c9,0x2c9,1);
  while (((iVar3 != -1 && ((int)param_1 < this->sn[100])) &&
         (pRVar4 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar3),
         pRVar4 != (RGE_Static_Object *)0x0))) {
    uVar5 = __ftol();
    uVar6 = __ftol();
    uVar7 = __ftol();
    iVar2 = pRVar4->_padding_;
    fVar9 = (float10)(**(code **)(iVar2 + 0x10c))(pRVar1->id,0,1,0xffffffff,0xffffffff);
    iVar8 = (**(code **)(iVar2 + 0x198))(uVar5,uVar6,uVar7,(float)fVar9);
    iVar2 = vPosition.x;
    if (iVar8 == 0) break;
    taskAttacker((TribeTacticalAIModule *)vPosition.x,iVar3,pRVar1->world_x,pRVar1->world_y,
                 pRVar1->id,(int)pRVar1->owner->id,(Waypoint *)0x0,0,-1,0);
    param_1 = (RGE_Static_Object *)((int)&param_1->_padding_ + 1);
    iVar3 = civilian((TribeTacticalAIModule *)iVar2,(XYPoint *)&vPosition.y,1,700,0x2c9,0x2c9,1);
    this = (TribeTacticalAIModule *)vPosition.x;
  }
  return (uint)(0 < (int)param_1);
}

// --------------------------------------------------

// Function: addWaypoint
// Address: 005015e0
/* public: void __thiscall TribeTacticalAIModule::addWaypoint(int,unsigned char,unsigned char) */

void __thiscall
TribeTacticalAIModule::addWaypoint
          (TribeTacticalAIModule *this,int param_1,uchar param_2,uchar param_3)
{
  uchar uStack00000009;
  undefined1 uStack0000000a;
  
  uStack00000009 = param_3;
  uStack0000000a = 1;
  (**(code **)(*(int *)this->md->_padding_ + 0x44))(param_1,&param_2,1);
  return;
}

// --------------------------------------------------

// Function: importantGroupLeader
// Address: 00501620
/* public: int __thiscall TribeTacticalAIModule::importantGroupLeader(int) */

int __thiscall TribeTacticalAIModule::importantGroupLeader(TribeTacticalAIModule *this,int param_1)
{
  short sVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
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

// Function: enableAttack
// Address: 00501660
/* public: void __thiscall TribeTacticalAIModule::enableAttack(int) */

void __thiscall TribeTacticalAIModule::enableAttack(TribeTacticalAIModule *this,int param_1)
{
  if ((this->attackEnabledValue != 1) && ((this->sn[0x86] == 0 || (this->sn[0x86] == param_1)))) {
    this->attackEnabledValue = 1;
  }
  return;
}

// --------------------------------------------------

// Function: unexploredArea
// Address: 00501690
/* WARNING: Variable defined which should be unmapped: unitZone */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TribeTacticalAIModule::unexploredArea(int,struct XYPoint &) */

int __thiscall
TribeTacticalAIModule::unexploredArea(TribeTacticalAIModule *this,int param_1,XYPoint *param_2)
{
  XYPoint *pXVar1;
  uchar uVar2;
  uchar uVar3;
  RGE_Static_Object *this_00;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  uchar unitZone;
  float bestDistance;
  RGE_Static_Object *unit;
  XYPoint bestPoint;
  int local_4;
  
  pXVar1 = param_2;
  this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if (this_00 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  uVar2 = RGE_Static_Object::currentZone(this_00);
  pRVar4 = MainDecisionAIModule::object
                     ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  unit = (RGE_Static_Object *)0xbf800000;
  bestPoint.y = -1;
  local_4 = -1;
  iVar5 = -1;
  iVar6 = -1;
  if (pRVar4 != (RGE_Static_Object *)0x0) {
    param_2 = (XYPoint *)0x0;
    do {
      iVar5 = __ftol();
      pXVar1->x = iVar5;
      iVar5 = __ftol();
      pXVar1->y = iVar5;
      switch(param_2) {
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
         (iVar5 = TribeInformationAIModule::mapXSize(&this->md->informationAI), pXVar1->x < iVar5))
{
        iVar5 = pXVar1->y;
        iVar6 = TribeInformationAIModule::mapYSize(&this->md->informationAI);
        if (((iVar5 < iVar6) &&
            (iVar5 = TribeInformationAIModule::tileUncovered
                               (&this->md->informationAI,pXVar1->x,iVar5), iVar5 != 1)) &&
           ((uVar3 = RGE_Static_Object::lookupZone(this_00,pXVar1->x,pXVar1->y), uVar2 == uVar3 &&
            ((pRVar4 = (RGE_Static_Object *)
                       RGE_Static_Object::distance_to_position
                                 (this_00,(float)pXVar1->x,(float)pXVar1->y,this_00->world_z),
             (float)unit == _DAT_00575758 || ((float)pRVar4 < (float)unit)))))) {
          bestPoint.y = pXVar1->x;
          local_4 = pXVar1->y;
          unit = pRVar4;
        }
      }
      param_2 = (XYPoint *)((int)&param_2->x + 1);
      iVar5 = bestPoint.y;
      iVar6 = local_4;
    } while ((int)param_2 < 8);
  }
  if ((float)unit == _DAT_00575758) {
    iVar5 = TribeInformationAIModule::unexploredPlayerLocation
                      (&this->md->informationAI,param_1,pXVar1);
    return (uint)(iVar5 != 0);
  }
  pXVar1->x = iVar5;
  pXVar1->y = iVar6;
  TribeInformationAIModule::setTileExplored(&this->md->informationAI,iVar5,iVar6);
  return 1;
}

// --------------------------------------------------

// Function: gatherer
// Address: 005018f0
/* public: struct UnitData * __thiscall TribeTacticalAIModule::gatherer(int) */

UnitData * __thiscall TribeTacticalAIModule::gatherer(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  UnitData *pUVar2;
  
  iVar1 = 0;
  pUVar2 = this->gatherers;
  do {
    if (pUVar2->id == param_1) {
      return this->gatherers + iVar1;
    }
    iVar1 = iVar1 + 1;
    pUVar2 = pUVar2 + 1;
  } while (iVar1 < 0x32);
  return (UnitData *)0x0;
}

// --------------------------------------------------

// Function: addGatherer
// Address: 00501920
// [HELPER] s_ERROR_adding_gatherer_id__1_: "ERROR adding gatherer id -1."
/* public: struct UnitData * __thiscall TribeTacticalAIModule::addGatherer(int) */

UnitData * __thiscall TribeTacticalAIModule::addGatherer(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  UnitData *pUVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == -1) {
    AIModule::logCommonHistory((AIModule *)this,(char *)this,s_ERROR_adding_gatherer_id__1_);
    return (UnitData *)0x0;
  }
  iVar1 = 0;
  pUVar2 = this->gatherers;
  iVar3 = -1;
  while (((pUVar2->id == -1 && (iVar4 = iVar1, iVar3 == -1)) ||
         (iVar4 = iVar3, pUVar2->id != param_1))) {
    iVar1 = iVar1 + 1;
    pUVar2 = pUVar2 + 1;
    iVar3 = iVar4;
    if (0x31 < iVar1) {
      if (iVar4 != -1) {
        this->gatherers[iVar4].id = param_1;
        this->gatherers[iVar4].target = -1;
        this->gatherers[iVar4].lastTaskTime = 0;
        this->numberGatherersValue = this->numberGatherersValue + 1;
        return this->gatherers + iVar4;
      }
      return (UnitData *)0x0;
    }
  }
  return this->gatherers + iVar1;
}

// --------------------------------------------------

// Function: removeGatherer
// Address: 005019c0
// [HELPER] s_ERROR_removing_gatherer_id__1_: "ERROR removing gatherer id -1."
/* public: int __thiscall TribeTacticalAIModule::removeGatherer(int) */

int __thiscall TribeTacticalAIModule::removeGatherer(TribeTacticalAIModule *this,int param_1)
{
  UnitData *pUVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 == -1) {
    AIModule::logCommonHistory((AIModule *)this,(char *)this,s_ERROR_removing_gatherer_id__1_);
    return 0;
  }
  iVar3 = 0;
  pUVar1 = this->gatherers;
  do {
    if (pUVar1->id == param_1) {
      piVar2 = &this->gatherers[iVar3].data1;
      this->gatherers[iVar3].id = -1;
      *piVar2 = -1;
      this->gatherers[iVar3].data2 = -1;
      this->gatherers[iVar3].data3 = -1;
      this->gatherers[iVar3].target = -1;
      this->numberGatherersValue = this->numberGatherersValue + -1;
      for (; (iVar3 < 0x31 && (piVar2[5] != -1)); piVar2 = piVar2 + 6) {
        ((UnitData *)(piVar2 + -1))->id = piVar2[5];
        *piVar2 = piVar2[6];
        piVar2[1] = piVar2[7];
        piVar2[2] = piVar2[8];
        piVar2[3] = piVar2[9];
        piVar2[5] = 0xffffffff;
        piVar2[6] = 0xffffffff;
        piVar2[7] = 0xffffffff;
        piVar2[8] = 0xffffffff;
        piVar2[9] = 0xffffffff;
        iVar3 = iVar3 + 1;
      }
      return 1;
    }
    iVar3 = iVar3 + 1;
    pUVar1 = pUVar1 + 1;
  } while (iVar3 < 0x32);
  return 0;
}

// --------------------------------------------------

// Function: isGatherer
// Address: 00501a80
/* public: int __thiscall TribeTacticalAIModule::isGatherer(int) */

int __thiscall TribeTacticalAIModule::isGatherer(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  UnitData *pUVar2;
  
  iVar1 = 0;
  pUVar2 = this->gatherers;
  do {
    if (pUVar2->id == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    pUVar2 = pUVar2 + 1;
  } while (iVar1 < 0x32);
  return 0;
}

// --------------------------------------------------

// Function: requiredGatherAmount
// Address: 00501ab0
/* public: int __thiscall TribeTacticalAIModule::requiredGatherAmount(int) */

int __thiscall TribeTacticalAIModule::requiredGatherAmount(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  
  if (this->desiredGathererDistribution[param_1] == 0) {
    return this->sn[0x94];
  }
  iVar1 = ResourceItem::value(&this->neededResources,param_1);
  return iVar1 / this->desiredGathererDistribution[param_1];
}

// --------------------------------------------------

// Function: trackUnitGather
// Address: 00501af0
/* public: void __thiscall TribeTacticalAIModule::trackUnitGather(int,int,int) */

void __thiscall
TribeTacticalAIModule::trackUnitGather
          (TribeTacticalAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  UnitData *pUVar2;
  
  if (this->resourceDifferenceValue[param_2] < 0) {
    iVar1 = TribeResourceAIModule::resource(&this->md->resourceAI,param_2);
    if (0 < iVar1 + this->resourceDifferenceValue[param_2]) {
      updateNeededResources(this);
    }
  }
  pUVar2 = gatherer(this,param_1);
  if ((pUVar2 != (UnitData *)0x0) && (pUVar2->data1 == param_2)) {
    pUVar2->data3 = pUVar2->data3 + param_3;
  }
  return;
}

// --------------------------------------------------

// Function: deleteUnit
// Address: 00501b50
/* public: int __thiscall TribeTacticalAIModule::deleteUnit(int) */

int __thiscall TribeTacticalAIModule::deleteUnit(TribeTacticalAIModule *this,int param_1)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if (pRVar2 != (RGE_Static_Object *)0x0) {
    uVar1 = TRIBE_Player::command_delete_object(this->md->aiPlayer,pRVar2);
    if (uVar1 == '\x01') {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: numberAvailableStoragePits
// Address: 00501b90
/* public: int __thiscall TribeTacticalAIModule::numberAvailableStoragePits(int &,int &,int) */

int __thiscall
TribeTacticalAIModule::numberAvailableStoragePits
          (TribeTacticalAIModule *this,int *param_1,int *param_2,int param_3)
{
  TribeMainDecisionAIModule *pTVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
                    /* language.dll match for 0x67: "Comic Sans MS" */
  iVar2 = BuildAIModule::numberUnbuiltItemsOfType((BuildAIModule *)&this->md->buildAI,0x67,0);
  *param_2 = iVar2;
  if (0 < iVar2) {
    return 0;
  }
  iVar2 = TribeResourceAIModule::resource(&this->md->resourceAI,param_3);
  if (this->sn[param_3 + 0xbe] <= iVar2) {
    return 0;
  }
  iVar2 = this->sn[0x96];
  if (iVar2 != -1) {
    pTVar1 = this->md;
    iVar3 = __ftol();
    if (iVar3 == 0) {
      iVar3 = 1;
    }
                    /* language.dll match for 0x67: "Comic Sans MS" */
    iVar4 = BuildAIModule::numberItemsOfType((BuildAIModule *)&pTVar1->buildAI,0x67,0);
    uVar5 = iVar3 * iVar2 - iVar4;
    *param_1 = iVar4;
    return ((int)uVar5 < 0) - 1 & uVar5;
  }
                    /* language.dll match for 0x67: "Comic Sans MS" */
  iVar2 = BuildAIModule::numberItemsOfType((BuildAIModule *)&this->md->buildAI,0x67,0);
  *param_1 = iVar2;
  iVar2 = TribeInformationAIModule::numberAvailableStoragePits(&this->md->informationAI,param_3);
  return iVar2;
}

// --------------------------------------------------

// Function: numberAvailableGranaries
// Address: 00501c70
/* public: int __thiscall TribeTacticalAIModule::numberAvailableGranaries(int &,int &) */

int __thiscall
TribeTacticalAIModule::numberAvailableGranaries
          (TribeTacticalAIModule *this,int *param_1,int *param_2)
{
  int iVar1;
  
  iVar1 = BuildAIModule::numberUnbuiltItemsOfType((BuildAIModule *)&this->md->buildAI,0x44,0);
  *param_2 = iVar1;
  if (0 < iVar1) {
    return 0;
  }
  iVar1 = TribeResourceAIModule::resource(&this->md->resourceAI,0);
  if (this->sn[0xbe] <= iVar1) {
    return 0;
  }
  if (this->sn[0x97] != -1) {
    iVar1 = BuildAIModule::numberItemsOfType((BuildAIModule *)&this->md->buildAI,0x44,0);
    *param_1 = iVar1;
    if (this->sn[0x97] <= iVar1) {
      return 0;
    }
  }
  iVar1 = BuildAIModule::numberItemsOfType((BuildAIModule *)&this->md->buildAI,0x44,0);
  *param_1 = iVar1;
  iVar1 = TribeInformationAIModule::numberAvailableGranaries(&this->md->informationAI);
  return iVar1;
}

// --------------------------------------------------

// Function: initialExplorationSatisfied
// Address: 00501d20
/* public: int __thiscall TribeTacticalAIModule::initialExplorationSatisfied(void) */

int __thiscall TribeTacticalAIModule::initialExplorationSatisfied(TribeTacticalAIModule *this)
{
  int iVar1;
  
  if (this->sn[0xa7] < 1) {
    return 1;
  }
  RGE_Visible_Map::percentExplored(*(RGE_Visible_Map **)(this->md->_padding_ + 0x38));
  iVar1 = __ftol();
  return (uint)(this->sn[0xa7] <= iVar1);
}

// --------------------------------------------------

// Function: checkForBuildInsertion
// Address: 00501d70
/* WARNING: Variable defined which should be unmapped: numUnbuiltGranaries */
/* public: void __thiscall TribeTacticalAIModule::checkForBuildInsertion(int,int,int) */

void __thiscall
TribeTacticalAIModule::checkForBuildInsertion
          (TribeTacticalAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  int numUnbuiltGranaries;
  int numGranaries;
  ResourceItem itemCost;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560bb0;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 == 0x32) {
    if ((this->sn[0xce] != 1) || (iVar2 = inAge(this,4), iVar2 == 0)) goto LAB_00502084;
    ResourceItem::ResourceItem((ResourceItem *)&itemCost.next,4);
    iVar2 = 0;
    local_4 = 0;
    if (0 < param_2) {
      do {
        iVar1 = ResourceItem::value((ResourceItem *)&itemCost.next,iVar2);
        ResourceItem::setValue((ResourceItem *)&itemCost.next,iVar2,iVar1 * param_2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_2);
    }
    TRIBE_Player::objectCost(this->md->aiPlayer,0x32,-1,(ResourceItem *)&itemCost.next,1);
    iVar2 = TribeResourceAIModule::resourcesAvailable
                      (&this->md->resourceAI,(ResourceItem *)&itemCost.next);
    if ((((iVar2 != 0) &&
         (iVar2 = TRIBE_Player::objectAvailable(this->md->aiPlayer,0x32), iVar2 != 0)) &&
        (iVar2 = TribeBuildAIModule::allBuilt(&this->md->buildAI,0,0), iVar2 != 0)) &&
       (iVar2 = (**(code **)((this->md->buildAI)._padding_ + 0x48))(0x32,0), iVar2 < this->sn[0xdc])
       ) {
      TribeBuildAIModule::insert(&this->md->buildAI,0x32,param_2,param_3);
    }
  }
  else {
    if (param_1 == 0x44) {
      if ((this->sn[0xcd] == 1) && ((this->md->informationAI).closestDropsiteValue[0] != -1)) {
        itemCost._padding_ = 0;
        numGranaries = 0;
        iVar2 = numberAvailableGranaries(this,&itemCost._padding_,&numGranaries);
        if ((numGranaries < 1) &&
           ((0 < iVar2 && (this->sn[0xa3] < (this->md->informationAI).closestDropsiteValue[0])))) {
          TribeBuildAIModule::insert(&this->md->buildAI,0x44,param_2,param_3);
        }
      }
      goto LAB_00502084;
    }
    if ((param_1 != 0x4f) || (this->sn[0xcf] != 1)) goto LAB_00502084;
    ResourceItem::ResourceItem((ResourceItem *)&itemCost.next,4);
    iVar2 = 0;
    local_4 = 1;
    if (0 < param_2) {
      do {
        iVar1 = ResourceItem::value((ResourceItem *)&itemCost.next,iVar2);
        ResourceItem::setValue((ResourceItem *)&itemCost.next,iVar2,iVar1 * param_2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_2);
    }
    TRIBE_Player::objectCost(this->md->aiPlayer,0x4f,-1,(ResourceItem *)&itemCost.next,1);
    iVar2 = TribeResourceAIModule::resourcesAvailable
                      (&this->md->resourceAI,(ResourceItem *)&itemCost.next);
    if ((((iVar2 != 0) &&
         (iVar2 = TRIBE_Player::objectAvailable(this->md->aiPlayer,0x4f), iVar2 != 0)) &&
        (iVar2 = TribeBuildAIModule::allBuilt(&this->md->buildAI,0,0), iVar2 != 0)) &&
       (iVar2 = (**(code **)((this->md->buildAI)._padding_ + 0x48))(0x4f,0), iVar2 < this->sn[0xde])
       ) {
      TribeBuildAIModule::insert(&this->md->buildAI,0x4f,param_2,param_3);
    }
  }
  local_4 = 0xffffffff;
  ResourceItem::~ResourceItem((ResourceItem *)&itemCost.next);
LAB_00502084:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: isFarmer
// Address: 005020a0
/* public: int __thiscall TribeTacticalAIModule::isFarmer(class RGE_Static_Object *) */

int __thiscall
TribeTacticalAIModule::isFarmer(TribeTacticalAIModule *this,RGE_Static_Object *param_1)
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

// Function: numberFarmers
// Address: 00502100
/* WARNING: Variable defined which should be unmapped: rVal */
/* public: int __thiscall TribeTacticalAIModule::numberFarmers(void) */

int __thiscall TribeTacticalAIModule::numberFarmers(TribeTacticalAIModule *this)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  int rVal;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  if (0 < (this->civilians).numberValue) {
    do {
      if ((this->civilians).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->civilians).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->civilians).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->civilians).maximumSizeValue);
          }
          operator_delete((this->civilians).value);
          (this->civilians).value = piVar1;
          (this->civilians).maximumSizeValue = iVar5 + 1;
        }
      }
      this_00 = MainDecisionAIModule::object
                          ((MainDecisionAIModule *)this->md,(this->civilians).value[iVar5]);
      if (((this_00 != (RGE_Static_Object *)0x0) &&
          (pUVar3 = RGE_Static_Object::unitAI(this_00), pUVar3 != (UnitAIModule *)0x0)) &&
         (this_00->master_obj->id == 0x103)) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 != 0x261) {
          pUVar3 = RGE_Static_Object::unitAI(this_00);
          iVar4 = UnitAIModule::currentAction(pUVar3);
          if (iVar4 != 0x262) goto LAB_005021e0;
        }
        local_4 = local_4 + 1;
      }
LAB_005021e0:
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->civilians).numberValue);
  }
  return local_4;
}

// --------------------------------------------------

// Function: inAge
// Address: 00502200
/* public: int __thiscall TribeTacticalAIModule::inAge(int) */

int __thiscall TribeTacticalAIModule::inAge(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  
  iVar1 = __ftol();
  return (uint)(iVar1 == param_1);
}

// --------------------------------------------------

// Function: stuffAvoidancePath
// Address: 00502230
/* WARNING: Variable defined which should be unmapped: divisionLength */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TribeTacticalAIModule::stuffAvoidancePath(class TacticalAIGroup *,class
   Path *) */

void __thiscall
TribeTacticalAIModule::stuffAvoidancePath
          (TribeTacticalAIModule *this,TacticalAIGroup *param_1,Path *param_2)
{
  Path *this_00;
  int iVar1;
  int iVar2;
  Waypoint *pWVar3;
  int iVar4;
  Path *pPVar5;
  float fVar6;
  float divisionLength;
  float local_4;
  
  this_00 = param_2;
  local_4 = Path::length(param_2);
  local_4 = local_4 * _DAT_00575778;
  if (local_4 < _DAT_0057577c) {
    local_4 = 10.0;
  }
  Path::initToStart(param_2);
  pPVar5 = (Path *)Path::distanceToNextWaypoint(param_2);
  Path::moveToNextWaypoint(param_2);
  iVar1 = Path::numberOfWaypoints(param_2);
  iVar4 = 1;
  iVar2 = Path::numberOfWaypoints(param_2);
  param_2 = pPVar5;
  if (1 < iVar2 + -1) {
    do {
      if (((iVar1 < 6) || (local_4 <= (float)param_2)) &&
         ((iVar1 >= 6 || (_DAT_00575780 <= (float)param_2)))) {
        pWVar3 = Path::currentWaypoint(this_00);
        fVar6 = pWVar3->y;
        pWVar3 = Path::currentWaypoint(this_00);
        TacticalAIGroup::addAttackWaypoint(param_1,pWVar3->x,fVar6);
      }
                    /* Symbol Ref: {@symbol IncTemp} */
      fVar6 = Path::distanceToNextWaypoint(this_00);
      iVar4 = iVar4 + 1;
      Path::moveToNextWaypoint(this_00);
      iVar2 = Path::numberOfWaypoints(this_00);
      param_2 = (Path *)(fVar6 + (float)param_2);
    } while (iVar4 < iVar2 + -1);
  }
  return;
}

// --------------------------------------------------

// Function: checkForAttackResponseBuildInsertions
// Address: 00502310
/* WARNING: Variable defined which should be unmapped: i */
/* public: void __thiscall TribeTacticalAIModule::checkForAttackResponseBuildInsertions(int) */

void __thiscall
TribeTacticalAIModule::checkForAttackResponseBuildInsertions
          (TribeTacticalAIModule *this,int param_1)
{
  ulong uVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int iVar5;
  int i;
  int insertedUnit;
  ResourceItem itemCost;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560bc8;
  *unaff_FS_OFFSET = &local_c;
  uVar1 = ((RGE_Player *)this->md->_padding_)->world->world_time;
  if (0xb3 < (int)(uVar1 - this->lastAttackResponseBuildInsertionTime) / 1000) {
    this->lastAttackResponseBuildInsertionTime = uVar1;
    pRVar2 = MainDecisionAIModule::object
                       ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      iVar5 = 0x14;
      iVar3 = __ftol();
      iVar4 = __ftol();
      iVar3 = TribeInformationAIModule::numberUnitsWithinXTiles
                        (&this->md->informationAI,param_1,iVar4,iVar3,iVar5);
      iVar3 = iVar3 - (this->soldiers).numberValue;
      if (0 < iVar3) {
        if (5 < iVar3) {
          iVar3 = 5;
        }
        insertedUnit = 0;
        itemCost._padding_ = 0;
        while (0 < iVar3) {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(insertedUnit) {
          case 0:
            iVar4 = TribeResourceAIModule::resource(&this->md->resourceAI,2);
            if ((0x95 < iVar4) && (2 < (this->civilians).numberValue)) {
              TribeBuildAIModule::insert(&this->md->buildAI,0x4f,1,0);
              iVar3 = iVar3 + -2;
            }
            insertedUnit = 1;
            break;
          case 1:
            iVar4 = TRIBE_Player::objectAvailable(this->md->aiPlayer,0x25);
            if (iVar4 == 0) {
              insertedUnit = insertedUnit + 1;
            }
            else {
              pRVar2 = MainDecisionAIModule::object
                                 ((MainDecisionAIModule *)this->md,-1,0x65,-1,-1,-1,-1,-1,-1,-1,-1);
              if (pRVar2 == (RGE_Static_Object *)0x0) {
                insertedUnit = insertedUnit + 1;
              }
              else {
                ResourceItem::ResourceItem((ResourceItem *)&itemCost.next,4);
                local_4 = 0;
                TRIBE_Player::objectCost
                          (this->md->aiPlayer,0x25,-1,(ResourceItem *)&itemCost.next,1);
                iVar4 = TribeResourceAIModule::resourcesAvailable
                                  (&this->md->resourceAI,(ResourceItem *)&itemCost.next);
                if (iVar4 == 1) {
                  TribeBuildAIModule::insert(&this->md->buildAI,0x25,1,0);
                  iVar3 = iVar3 + -1;
                  itemCost._padding_ = 1;
                }
                insertedUnit = insertedUnit + 1;
                local_4 = 0xffffffff;
                ResourceItem::~ResourceItem((ResourceItem *)&itemCost.next);
              }
            }
            break;
          default:
            if (itemCost._padding_ != 1) goto LAB_005025af;
            insertedUnit = 1;
            itemCost._padding_ = 0;
          }
        }
      }
    }
  }
LAB_005025af:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: checkForCoopTributeDemand
// Address: 00502600
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Variable defined which should be unmapped: amountDemandable */
/* public: void __thiscall TribeTacticalAIModule::checkForCoopTributeDemand(void) */

void __thiscall TribeTacticalAIModule::checkForCoopTributeDemand(TribeTacticalAIModule *this)
{
  ushort uVar1;
  ulong uVar2;
  int iVar3;
  RGE_Player *pRVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int amountDemandable;
  int tempRand;
  TRIBE_World *world;
  int i;
  int j;
  int local_8;
  
  if (this->sn[0xba] != -1) {
    uVar2 = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
    if (this->sn[0xba] <= (int)(uVar2 - this->lastCoopTributeDemandTime) / 1000) {
      this->lastCoopTributeDemandTime = uVar2;
      iVar3 = *(int *)(this->md->_padding_ + 0x3c);
      if (*(char *)(iVar3 + 0x11d) == -1) {
        iVar7 = 1;
        iVar6 = 0;
        if (1 < *(short *)(iVar3 + 0x3c)) {
          do {
            iVar5 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar7 * 4))
            ;
            if (iVar5 == 1) {
              iVar6 = iVar6 + 1;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(short *)(iVar3 + 0x3c));
        }
        if (iVar6 == 1) {
          *(undefined1 *)(iVar3 + 0x11d) = *(undefined1 *)(this->md->_padding_ + 0x4a);
        }
        else {
          iVar7 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x31f0);
          iVar5 = 1;
          world = (TRIBE_World *)(iVar7 % iVar6 + 1);
          if (1 < *(short *)(iVar3 + 0x3c)) {
            do {
              pRVar4 = *(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar5 * 4);
              iVar6 = RGE_Player::computerPlayer(pRVar4);
              if ((iVar6 == 1) &&
                 (world = (TRIBE_World *)((int)&world[-1].sent_zone_score + 3),
                 world == (TRIBE_World *)0x0)) {
                *(char *)(iVar3 + 0x11d) = (char)pRVar4->id;
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < *(short *)(iVar3 + 0x3c));
          }
        }
      }
      if (*(char *)(iVar3 + 0x11d) == *(char *)(this->md->_padding_ + 0x4a)) {
        tempRand = this->sn[0xbb];
        piVar8 = this->neededResourceValue;
        local_8 = 0;
        do {
          if (tempRand < 1) {
            return;
          }
          if (((((*piVar8 != 0) ||
                (iVar6 = TribeResourceAIModule::resource(&this->md->resourceAI,0),
                iVar6 < this->sn[0xbe])) &&
               ((*piVar8 != 1 ||
                (iVar6 = TribeResourceAIModule::resource(&this->md->resourceAI,1),
                iVar6 < this->sn[0xbf])))) &&
              (((*piVar8 != 3 ||
                (iVar6 = TribeResourceAIModule::resource(&this->md->resourceAI,3),
                iVar6 < this->sn[0xc1])) &&
               ((*piVar8 != 2 ||
                (iVar6 = TribeResourceAIModule::resource(&this->md->resourceAI,2),
                iVar6 < this->sn[0xc0])))))) &&
             ((piVar8[4] < 0 && (j = 1, 1 < *(short *)(iVar3 + 0x3c))))) {
            do {
              if (tempRand < 1) break;
              pRVar4 = *(RGE_Player **)(*(int *)(iVar3 + 0x40) + j * 4);
              if (((pRVar4->id != *(short *)(this->md->_padding_ + 0x4a)) &&
                  (iVar6 = RGE_Player::computerPlayer(pRVar4), iVar6 != 0)) &&
                 (iVar6 = (**(code **)(*(int *)this->md->_padding_ + 0x1c))(j), iVar6 != 0)) {
                iVar6 = pRVar4->_padding_;
                iVar7 = (**(code **)(iVar6 + 0x1c))((int)*(short *)(this->md->_padding_ + 0x4a));
                if (iVar7 != 0) {
                  uVar1 = *(ushort *)(this->md->_padding_ + 0x4a);
                  if ((((short)uVar1 < pRVar4->id) &&
                      (pRVar4->id != (ushort)*(byte *)(iVar3 + 0x11d))) ||
                     (uVar1 == *(byte *)(iVar3 + 0x11d))) {
                    iVar7 = *piVar8;
                    iVar5 = __ftol();
                    if (0x32 < iVar5) {
                      if (tempRand < iVar5) {
                        iVar5 = tempRand;
                      }
                      tempRand = tempRand - iVar5;
                      (**(code **)(iVar6 + 0x54))((int)(short)uVar1,1,iVar7,iVar5,0);
                    }
                  }
                }
              }
              j = j + 1;
            } while (j < *(short *)(iVar3 + 0x3c));
          }
          piVar8 = piVar8 + 1;
          local_8 = local_8 + 1;
        } while (local_8 < 4);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: checkForCoopTributeGift
// Address: 00502920
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Variable defined which should be unmapped: bestCP */
/* public: void __thiscall TribeTacticalAIModule::checkForCoopTributeGift(void) */

void __thiscall TribeTacticalAIModule::checkForCoopTributeGift(TribeTacticalAIModule *this)
{
  float *pfVar1;
  ulong uVar2;
  int iVar3;
  RGE_Player *pRVar4;
  TRIBE_Player *pTVar5;
  RGE_Static_Object *pRVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int bestCP;
  int j;
  int local_18;
  TRIBE_World *world;
  int i;
  float bestCPValue;
  float tributeAmount;
  
  if ((this->sn[0xba] != -1) &&
     (pRVar6 = RGE_Object_List::find_by_master_id
                         ((RGE_Object_List *)this->md->aiPlayer->_padding_,0x54,-1.0,-1.0,'\0',
                          '\x02',(RGE_Static_Object *)0x0), pRVar6 != (RGE_Static_Object *)0x0)) {
    uVar2 = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
    if (this->sn[0xba] <= (int)(uVar2 - this->lastCoopTributeGiftTime) / 1000) {
      this->lastCoopTributeGiftTime = uVar2;
      iVar3 = *(int *)(this->md->_padding_ + 0x3c);
      if (*(char *)(iVar3 + 0x11d) == -1) {
        iVar8 = 1;
        iVar9 = 0;
        if (1 < *(short *)(iVar3 + 0x3c)) {
          do {
            iVar7 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar8 * 4))
            ;
            if (iVar7 == 1) {
              iVar9 = iVar9 + 1;
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < *(short *)(iVar3 + 0x3c));
        }
        if (iVar9 == 1) {
          *(undefined1 *)(iVar3 + 0x11d) = *(undefined1 *)(this->md->_padding_ + 0x4a);
        }
        else {
          iVar8 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x3275);
          iVar7 = 1;
          bestCPValue = (float)(iVar8 % iVar9 + 1);
          if (1 < *(short *)(iVar3 + 0x3c)) {
            do {
              pRVar4 = *(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar7 * 4);
              iVar8 = RGE_Player::computerPlayer(pRVar4);
              if ((iVar8 == 1) && (bestCPValue = (float)((int)bestCPValue + -1), bestCPValue == 0.0)
                 ) {
                *(char *)(iVar3 + 0x11d) = (char)pRVar4->id;
              }
              iVar7 = iVar7 + 1;
            } while (iVar7 < *(short *)(iVar3 + 0x3c));
          }
        }
      }
      world = (TRIBE_World *)(this->sn + 0xbe);
      local_18 = 0;
      do {
        iVar8 = TribeResourceAIModule::resource(&this->md->resourceAI,local_18);
        if (world->_padding_ < iVar8) {
          j = -1;
          tributeAmount = 0.0;
          bestCPValue = 1.4013e-45;
          if (1 < *(short *)(iVar3 + 0x3c)) {
            do {
              pRVar4 = *(RGE_Player **)(*(int *)(iVar3 + 0x40) + (int)bestCPValue * 4);
              if (((pRVar4->id != *(short *)(this->md->_padding_ + 0x4a)) &&
                  (iVar8 = RGE_Player::computerPlayer(pRVar4), iVar8 != 0)) &&
                 (iVar8 = (**(code **)(*(int *)this->md->_padding_ + 0x1c))(bestCPValue), iVar8 != 0
                 )) {
                iVar8 = pRVar4->_padding_;
                iVar9 = (**(code **)(iVar8 + 0x1c))((int)*(short *)(this->md->_padding_ + 0x4a));
                if (iVar9 != 0) {
                  pfVar1 = pRVar4->attributes + local_18;
                  iVar8 = (**(code **)(iVar8 + 0x3c))(local_18 + 0xbe);
                  if ((*pfVar1 < (float)iVar8) && ((j == -1 || (*pfVar1 < tributeAmount)))) {
                    j = (int)pRVar4->id;
                    tributeAmount = *pfVar1;
                  }
                }
              }
              bestCPValue = (float)((int)bestCPValue + 1);
            } while ((int)bestCPValue < (int)*(short *)(iVar3 + 0x3c));
          }
          if (j != -1) {
            iVar8 = TribeResourceAIModule::resource(&this->md->resourceAI,local_18);
            pTVar5 = this->md->aiPlayer;
            (**(code **)(pTVar5->_padding_ + 0xf8))
                      (j,local_18,(float)(iVar8 - world->_padding_),
                       *(undefined4 *)(pTVar5->_padding_ + 0xb8));
          }
        }
        local_18 = local_18 + 1;
        world = (TRIBE_World *)&world->_padding_;
      } while (local_18 < 4);
    }
  }
  return;
}

// --------------------------------------------------

// Function: checkForASAPAgeResearch
// Address: 00502bf0
/* public: void __thiscall TribeTacticalAIModule::checkForASAPAgeResearch(void) */

void __thiscall TribeTacticalAIModule::checkForASAPAgeResearch(TribeTacticalAIModule *this)
{
  int iVar1;
  BuildItem *pBVar2;
  
  iVar1 = inAge(this,1);
  if ((((iVar1 == 0) || (this->sn[0xb5] != 1)) ||
      (iVar1 = TribeBuildAIModule::readyToResearch(&this->md->buildAI,2,1), iVar1 == 0)) ||
     (iVar1 = TribeResourceAIModule::resource(&this->md->resourceAI,0), iVar1 < 500)) {
    iVar1 = inAge(this,2);
    if (((iVar1 == 0) || (this->sn[0xb6] != 1)) ||
       ((iVar1 = TribeBuildAIModule::readyToResearch(&this->md->buildAI,3,1), iVar1 == 0 ||
        (iVar1 = TribeResourceAIModule::resource(&this->md->resourceAI,0), iVar1 < 800))))
    goto LAB_00502cc3;
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
    pBVar2 = TribeBuildAIModule::buildItem(&this->md->buildAI,0x66,1,4);
  }
  else {
                    /* language.dll match for 0x65: "1" */
    pBVar2 = TribeBuildAIModule::buildItem(&this->md->buildAI,0x65,1,4);
  }
  if (pBVar2 != (BuildItem *)0x0) {
    taskResearch(this,pBVar2);
  }
LAB_00502cc3:
  iVar1 = inAge(this,3);
                    /* language.dll match for 0x67: "Comic Sans MS" */
  if (((iVar1 != 0) && (this->sn[0xb7] == 1)) &&
     ((iVar1 = TribeBuildAIModule::readyToResearch(&this->md->buildAI,4,1), iVar1 != 0 &&
      (((iVar1 = TribeResourceAIModule::resource(&this->md->resourceAI,0), 899 < iVar1 &&
        (iVar1 = TribeResourceAIModule::resource(&this->md->resourceAI,3), 699 < iVar1)) &&
       (pBVar2 = TribeBuildAIModule::buildItem(&this->md->buildAI,0x67,1,4),
       pBVar2 != (BuildItem *)0x0)))))) {
    taskResearch(this,pBVar2);
  }
  return;
}

// --------------------------------------------------

// Function: checkForCoopAttack
// Address: 00502d50
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Variable defined which should be unmapped: tempRand */
/* public: void __thiscall TribeTacticalAIModule::checkForCoopAttack(int,int,int) */

void __thiscall
TribeTacticalAIModule::checkForCoopAttack
          (TribeTacticalAIModule *this,int param_1,int param_2,int param_3)
{
  ushort uVar1;
  ulong uVar2;
  int iVar3;
  RGE_Player *pRVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int tempRand;
  int local_4;
  
  if (this->sn[0xc4] == 1) {
    uVar2 = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
    if (this->sn[0xc5] <= (int)(uVar2 - this->lastCoopAttackDemandTime) / 1000) {
      this->lastCoopAttackDemandTime = uVar2;
      iVar3 = *(int *)(this->md->_padding_ + 0x3c);
      if (*(char *)(iVar3 + 0x11d) == -1) {
        iVar7 = 1;
        iVar6 = 0;
        if (1 < *(short *)(iVar3 + 0x3c)) {
          do {
            iVar5 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar7 * 4))
            ;
            if (iVar5 == 1) {
              iVar6 = iVar6 + 1;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(short *)(iVar3 + 0x3c));
        }
        if (iVar6 == 1) {
          *(undefined1 *)(iVar3 + 0x11d) = *(undefined1 *)(this->md->_padding_ + 0x4a);
        }
        else {
          iVar7 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x32f1);
          iVar5 = 1;
          local_4 = iVar7 % iVar6 + 1;
          if (1 < *(short *)(iVar3 + 0x3c)) {
            do {
              pRVar4 = *(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar5 * 4);
              iVar6 = RGE_Player::computerPlayer(pRVar4);
              if ((iVar6 == 1) && (local_4 = local_4 + -1, local_4 == 0)) {
                *(char *)(iVar3 + 0x11d) = (char)pRVar4->id;
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < *(short *)(iVar3 + 0x3c));
          }
        }
      }
      local_4 = 1;
      if (1 < *(short *)(iVar3 + 0x3c)) {
        do {
          pRVar4 = *(RGE_Player **)(*(int *)(iVar3 + 0x40) + local_4 * 4);
          if (((pRVar4->id != *(short *)(this->md->_padding_ + 0x4a)) &&
              (iVar6 = RGE_Player::computerPlayer(pRVar4), iVar6 != 0)) &&
             (iVar6 = (**(code **)(*(int *)this->md->_padding_ + 0x1c))(local_4), iVar6 != 0)) {
            iVar6 = pRVar4->_padding_;
            iVar7 = (**(code **)(iVar6 + 0x1c))((int)*(short *)(this->md->_padding_ + 0x4a));
            if (iVar7 != 0) {
              uVar1 = *(ushort *)(this->md->_padding_ + 0x4a);
              if ((((short)uVar1 < pRVar4->id) && (pRVar4->id != (ushort)*(byte *)(iVar3 + 0x11d)))
                 || (uVar1 == *(byte *)(iVar3 + 0x11d))) {
                (**(code **)(iVar6 + 0x54))((int)(short)uVar1,2,param_1,param_2,param_3);
              }
            }
          }
          local_4 = local_4 + 1;
        } while (local_4 < *(short *)(iVar3 + 0x3c));
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: processCoopAttack
// Address: 00502f30
/* public: int __thiscall TribeTacticalAIModule::processCoopAttack(int,int,int,int) */

int __thiscall
TribeTacticalAIModule::processCoopAttack
          (TribeTacticalAIModule *this,int param_1,int param_2,int param_3,int param_4)
{
  TacticalAIGroup *this_00;
  int iVar1;
  int iVar2;
  
  if (this->attackEnabledValue != 0) {
    DiplomacyAIModule::setStance(&this->md->diplomacyAI,param_2,0,100);
    for (this_00 = (this->groups).next;
        (this_00 != &this->groups && (this_00 != (TacticalAIGroup *)0x0)); this_00 = this_00->next)
{
      iVar1 = TacticalAIGroup::type(this_00);
      if ((iVar1 == 100) || (iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x67)) {
        iVar1 = TacticalAIGroup::numberUnits(this_00);
        iVar2 = TacticalAIGroup::desiredNumberUnits(this_00);
        if (iVar1 < iVar2) {
          iVar1 = TacticalAIGroup::numberUnits(this_00);
          TacticalAIGroup::setDesiredNumberUnits(this_00,iVar1);
        }
      }
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: resourceDifference
// Address: 00502fc0
/* public: int __thiscall TribeTacticalAIModule::resourceDifference(int) */

int __thiscall TribeTacticalAIModule::resourceDifference(TribeTacticalAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 4)) {
    return this->resourceDifferenceValue[this->neededResourceValue[param_1]];
  }
  return -1;
}

// --------------------------------------------------

// Function: actualGathererCount
// Address: 00502ff0
/* public: int __thiscall TribeTacticalAIModule::actualGathererCount(int) */

int __thiscall TribeTacticalAIModule::actualGathererCount(TribeTacticalAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 4)) {
    return this->actualGathererDistribution[this->neededResourceValue[param_1]];
  }
  return -1;
}

// --------------------------------------------------

// Function: actualGathererCountByRealResourceID
// Address: 00503020
/* public: int __thiscall TribeTacticalAIModule::actualGathererCountByRealResourceID(int) */

int __thiscall
TribeTacticalAIModule::actualGathererCountByRealResourceID(TribeTacticalAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 4)) {
    return this->actualGathererDistribution[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: desiredGathererCount
// Address: 00503040
/* public: int __thiscall TribeTacticalAIModule::desiredGathererCount(int) */

int __thiscall TribeTacticalAIModule::desiredGathererCount(TribeTacticalAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 4)) {
    return this->desiredGathererDistribution[this->neededResourceValue[param_1]];
  }
  return -1;
}

// --------------------------------------------------

// Function: taskElephantGatherers
// Address: 00503070
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TribeTacticalAIModule::taskElephantGatherers(int,int,int) */

void __thiscall
TribeTacticalAIModule::taskElephantGatherers
          (TribeTacticalAIModule *this,int param_1,int param_2,int param_3)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  UnitAIModule *pUVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  UnitData *pUVar9;
  undefined4 *unaff_FS_OFFSET;
  float fVar10;
  int bestValueID;
  RGE_Static_Object *targetObject;
  int count;
  ManagedArray<int> alreadyTasked;
  int local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560be8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_3);
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    alreadyTasked.numberValue = 0;
    alreadyTasked.desiredNumberValue = 0;
    alreadyTasked.maximumSizeValue = 0;
    local_10 = 0;
    local_4 = 0;
    ManagedArray<int>::resize((ManagedArray<int> *)&alreadyTasked.numberValue,1);
    alreadyTasked.value = (int *)0x0;
    *(int *)(alreadyTasked.numberValue + alreadyTasked.desiredNumberValue * 4) = param_1;
    alreadyTasked.desiredNumberValue = alreadyTasked.desiredNumberValue + 1;
    if (0 < param_2) {
      do {
        iVar8 = 0;
        param_1 = -0x40800000;
        targetObject = (RGE_Static_Object *)0xffffffff;
        pRVar3 = (RGE_Static_Object *)0xffffffff;
        if (0 < this->numberGatherersValue) {
          pUVar9 = this->gatherers;
          iVar6 = alreadyTasked.desiredNumberValue;
          do {
            iVar2 = 0;
            piVar7 = (int *)alreadyTasked.numberValue;
            if (0 < iVar6) {
              do {
                if (local_10 <= iVar2) break;
                if (*piVar7 == pUVar9->id) goto LAB_005031a6;
                iVar2 = iVar2 + 1;
                piVar7 = piVar7 + 1;
              } while (iVar2 < iVar6);
            }
            pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,pUVar9->id);
            iVar6 = alreadyTasked.desiredNumberValue;
            if ((((pRVar3 != (RGE_Static_Object *)0x0) &&
                 (pUVar4 = RGE_Static_Object::unitAI(pRVar3),
                 iVar6 = alreadyTasked.desiredNumberValue, pUVar4 != (UnitAIModule *)0x0)) &&
                (pUVar9->data1 == 0)) &&
               ((fVar10 = RGE_Static_Object::distance_to_object(pRVar3,pRVar1),
                iVar6 = alreadyTasked.desiredNumberValue, (float)param_1 == _DAT_00575758 ||
                (fVar10 < (float)param_1)))) {
              targetObject = (RGE_Static_Object *)pUVar9->id;
              param_1 = (int)fVar10;
            }
LAB_005031a6:
            iVar8 = iVar8 + 1;
            pUVar9 = pUVar9 + 1;
            pRVar3 = targetObject;
          } while (iVar8 < this->numberGatherersValue);
        }
        if (pRVar3 == (RGE_Static_Object *)0xffffffff) break;
        (**(code **)(this->md->aiPlayer->_padding_ + 0x124))
                  (pRVar3,param_3,0,pRVar1->world_x,pRVar1->world_y);
        iVar8 = 0;
        piVar7 = (int *)alreadyTasked.numberValue;
        if (0 < alreadyTasked.desiredNumberValue) {
          do {
            if (local_10 <= iVar8) break;
            if ((RGE_Static_Object *)*piVar7 == pRVar3) goto LAB_00503285;
            iVar8 = iVar8 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar8 < alreadyTasked.desiredNumberValue);
        }
        if (local_10 + -1 < alreadyTasked.desiredNumberValue) {
          iVar8 = alreadyTasked.desiredNumberValue + 1;
          pvVar5 = operator_new(iVar8 * 4);
          if (pvVar5 != (void *)0x0) {
            iVar6 = 0;
            if (0 < local_10) {
              do {
                if (iVar8 <= iVar6) break;
                iVar6 = iVar6 + 1;
                *(undefined4 *)((int)pvVar5 + iVar6 * 4 + -4) =
                     *(undefined4 *)(alreadyTasked.numberValue + -4 + iVar6 * 4);
              } while (iVar6 < local_10);
            }
            operator_delete((void *)alreadyTasked.numberValue);
            alreadyTasked.numberValue = (int)pvVar5;
            local_10 = iVar8;
          }
        }
        *(RGE_Static_Object **)(alreadyTasked.numberValue + alreadyTasked.desiredNumberValue * 4) =
             pRVar3;
        alreadyTasked.desiredNumberValue = alreadyTasked.desiredNumberValue + 1;
LAB_00503285:
        alreadyTasked.value = (int *)((int)alreadyTasked.value + 1);
      } while ((int)alreadyTasked.value < param_2);
    }
    if ((void *)alreadyTasked.numberValue != (void *)0x0) {
      local_4 = 0xffffffff;
      operator_delete((void *)alreadyTasked.numberValue);
    }
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: checkTradeBoats
// Address: 005032e0
/* WARNING: Variable defined which should be unmapped: i */
/* public: void __thiscall TribeTacticalAIModule::checkTradeBoats(void) */

void __thiscall TribeTacticalAIModule::checkTradeBoats(TribeTacticalAIModule *this)
{
  short sVar1;
  int *piVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  int i;
  int local_4;
  
  local_4 = 0;
  if ((this->tradeBoats).numberValue < 1) {
    return;
  }
LAB_005032fb:
  if ((this->tradeBoats).maximumSizeValue + -1 < local_4) {
    piVar2 = (int *)operator_new(local_4 * 4 + 4);
    if (piVar2 != (int *)0x0) {
      iVar5 = 0;
      if (0 < (this->tradeBoats).maximumSizeValue) {
        do {
          if (local_4 + 1 <= iVar5) break;
          iVar3 = iVar5 + 1;
          piVar2[iVar5] = (this->tradeBoats).value[iVar5];
          iVar5 = iVar3;
        } while (iVar3 < (this->tradeBoats).maximumSizeValue);
      }
      operator_delete((this->tradeBoats).value);
      (this->tradeBoats).value = piVar2;
      (this->tradeBoats).maximumSizeValue = local_4 + 1;
    }
  }
  pRVar4 = MainDecisionAIModule::object
                     ((MainDecisionAIModule *)this->md,(this->tradeBoats).value[local_4]);
  if (pRVar4 != (RGE_Static_Object *)0x0) {
    sVar1 = pRVar4->attribute_type_held;
    iVar5 = TribeResourceAIModule::resource(&this->md->resourceAI,(int)sVar1);
    if (iVar5 < this->sn[0xd8]) {
      iVar5 = 2;
      do {
        if ((iVar5 != sVar1) &&
           (iVar3 = TribeResourceAIModule::resource(&this->md->resourceAI,iVar5),
           this->sn[0xd8] <= iVar3)) {
          if (local_4 <= (this->tradeBoats).maximumSizeValue + -1) goto LAB_0050343d;
          piVar2 = (int *)operator_new(local_4 * 4 + 4);
          if (piVar2 == (int *)0x0) goto LAB_0050343d;
          iVar3 = 0;
          if (0 < (this->tradeBoats).maximumSizeValue) goto LAB_00503401;
          goto LAB_0050341e;
        }
        iVar5 = iVar5 + -1;
      } while (-1 < iVar5);
    }
  }
  goto LAB_0050345d;
  while( true ) {
    iVar6 = iVar3 + 1;
    piVar2[iVar3] = (this->tradeBoats).value[iVar3];
    iVar3 = iVar6;
    if ((this->tradeBoats).maximumSizeValue <= iVar6) break;
LAB_00503401:
    if (local_4 + 1 <= iVar3) break;
  }
LAB_0050341e:
  operator_delete((this->tradeBoats).value);
  (this->tradeBoats).value = piVar2;
  (this->tradeBoats).maximumSizeValue = local_4 + 1;
LAB_0050343d:
  TRIBE_Player::command_trade_attribute(this->md->aiPlayer,(this->tradeBoats).value[local_4],iVar5);
LAB_0050345d:
  local_4 = local_4 + 1;
  if ((this->tradeBoats).numberValue <= local_4) {
    return;
  }
  goto LAB_005032fb;
}

// --------------------------------------------------

// Function: numberGatherersWithTarget
// Address: 00503480
/* public: int __thiscall TribeTacticalAIModule::numberGatherersWithTarget(int) */

int __thiscall
TribeTacticalAIModule::numberGatherersWithTarget(TribeTacticalAIModule *this,int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = this->numberGatherersValue;
  iVar1 = 0;
  if (0 < iVar3) {
    piVar2 = &this->gatherers[0].target;
    do {
      if (*piVar2 == param_1) {
        iVar1 = iVar1 + 1;
      }
      piVar2 = piVar2 + 6;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: checkStaleAttackGroups
// Address: 005034b0
/* public: void __thiscall TribeTacticalAIModule::checkStaleAttackGroups(void) */

void __thiscall TribeTacticalAIModule::checkStaleAttackGroups(TribeTacticalAIModule *this)
{
  TacticalAIGroup *this_00;
  int iVar1;
  int iVar2;
  
  if (this->attackEnabledValue != 0) {
    for (this_00 = (this->groups).next;
        (this_00 != &this->groups && (this_00 != (TacticalAIGroup *)0x0)); this_00 = this_00->next)
{
      iVar1 = TacticalAIGroup::type(this_00);
      if ((iVar1 == 100) && (iVar1 = TacticalAIGroup::inUse(this_00), iVar1 != 1)) {
        iVar1 = TacticalAIGroup::numberUnits(this_00);
        iVar2 = TacticalAIGroup::desiredNumberUnits(this_00);
        iVar2 = iVar2 - iVar1;
        if (0 < iVar2) {
          if (5 < iVar2) {
            iVar2 = 5;
          }
          if (iVar2 <= (int)(*(int *)(*(int *)(this->md->_padding_ + 0x3c) + 4) -
                            this_00->lastAddedUnitTimeValue) / 60000) {
            iVar1 = TacticalAIGroup::numberUnits(this_00);
            TacticalAIGroup::setDesiredNumberUnits(this_00,iVar1);
          }
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: numberWaterExplorers
// Address: 00503580
/* public: int __thiscall TribeTacticalAIModule::numberWaterExplorers(void) */

int __thiscall TribeTacticalAIModule::numberWaterExplorers(TribeTacticalAIModule *this)
{
  TacticalAIGroup *this_00;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (this_00 = (this->groups).next;
      (this_00 != &this->groups && (this_00 != (TacticalAIGroup *)0x0)); this_00 = this_00->next) {
    iVar1 = TacticalAIGroup::type(this_00);
    if ((((iVar1 == 0x67) ||
         (((iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x68 ||
           (iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x69)) ||
          (iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x6a)))) ||
        ((iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x6b ||
         (iVar1 = TacticalAIGroup::type(this_00), iVar1 == 0x6c)))) &&
       (iVar1 = TacticalAIGroup::action(this_00), iVar1 == 8)) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: saveTheTown
// Address: 00503600
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TribeTacticalAIModule::saveTheTown(int) */

void __thiscall TribeTacticalAIModule::saveTheTown(TribeTacticalAIModule *this,int param_1)
{
  ulong uVar1;
  RGE_Static_Object *pRVar2;
  TacticalAIGroup *this_00;
  int iVar3;
  RGE_Static_Object *pRVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  ulong uVar8;
  int *piVar9;
  int iVar10;
  UnitAIModule *pUVar11;
  float10 fVar12;
  float fVar13;
  int i;
  int count;
  ulong entryTime;
  RGE_Static_Object *targetObj;
  XYPoint objPosition;
  XYZPoint point;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x3420);
  pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,param_1);
  if (pRVar2 != (RGE_Static_Object *)0x0) {
    objPosition.y = __ftol();
    __ftol();
    this_00 = readyAndIdleGroup(this,100,this->sn[0x14],(XYPoint *)&objPosition.y);
                    /* language.dll match for 0x67: "Comic Sans MS" */
    if ((this_00 != (TacticalAIGroup *)0x0) ||
       (this_00 = readyAndIdleGroup(this,0x67,this->sn[0x14],(XYPoint *)&objPosition.y),
       this_00 != (TacticalAIGroup *)0x0)) {
      iVar3 = TacticalAIGroup::commander(this_00);
      pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(this->md->_padding_ + 0x3c),iVar3);
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        uVar5 = __ftol();
        uVar6 = __ftol();
        uVar7 = __ftol();
        iVar3 = pRVar4->_padding_;
        fVar12 = (float10)(**(code **)(iVar3 + 0x10c))(param_1,0,1,0xffffffff,0xffffffff);
        iVar3 = (**(code **)(iVar3 + 0x198))(uVar5,uVar6,uVar7,(float)fVar12);
        if (iVar3 == 1) {
          TacticalAIGroup::setTarget(this_00,param_1);
          TacticalAIGroup::setTargetType(this_00,(int)pRVar2->master_obj->id);
          TacticalAIGroup::setTargetLocation
                    (this_00,pRVar2->world_x,pRVar2->world_y,pRVar2->world_z);
          TacticalAIGroup::setAction(this_00,2);
          TacticalAIGroup::task(this_00,this,this->md,2,1,0);
          return;
        }
      }
    }
    entryTime = 0;
    count = 0;
    if (0 < (this->soldiers).numberValue) {
      do {
        if (5 < (int)entryTime) break;
        if ((1 < count) &&
           (uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x3447), 10 < uVar8 - uVar1
           )) {
          return;
        }
        if ((this->soldiers).maximumSizeValue + -1 < count) {
          piVar9 = (int *)operator_new(count * 4 + 4);
          if (piVar9 != (int *)0x0) {
            iVar3 = 0;
            if (0 < (this->soldiers).maximumSizeValue) {
              do {
                if (count + 1 <= iVar3) break;
                iVar10 = iVar3 + 1;
                piVar9[iVar3] = (this->soldiers).value[iVar3];
                iVar3 = iVar10;
              } while (iVar10 < (this->soldiers).maximumSizeValue);
            }
            operator_delete((this->soldiers).value);
            (this->soldiers).value = piVar9;
            (this->soldiers).maximumSizeValue = count + 1;
          }
        }
        pRVar4 = RGE_Game_World::object
                           ((RGE_Game_World *)this->md->aiPlayer->_padding_,
                            (this->soldiers).value[count]);
        if ((pRVar4 != (RGE_Static_Object *)0x0) &&
           (pUVar11 = RGE_Static_Object::unitAI(pRVar4), pUVar11 != (UnitAIModule *)0x0)) {
          pUVar11 = RGE_Static_Object::unitAI(pRVar4);
          iVar3 = UnitAIModule::currentAction(pUVar11);
          if (iVar3 == 600) {
            pUVar11 = RGE_Static_Object::unitAI(pRVar4);
            iVar3 = UnitAIModule::currentTarget(pUVar11);
            if (iVar3 == -1) goto LAB_00503954;
            pUVar11 = RGE_Static_Object::unitAI(pRVar4);
            iVar3 = UnitAIModule::currentTarget(pUVar11);
            if (iVar3 != pRVar2->id) {
              pUVar11 = RGE_Static_Object::unitAI(pRVar4);
              iVar3 = UnitAIModule::currentTarget(pUVar11);
              objPosition.x =
                   (int)RGE_Game_World::object
                                  (*(RGE_Game_World **)(this->md->_padding_ + 0x3c),iVar3);
              if ((RGE_Static_Object *)objPosition.x != (RGE_Static_Object *)0x0) {
                if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                   (piVar9 = (int *)operator_new(4), piVar9 != (int *)0x0)) {
                  iVar3 = 0;
                  if (0 < (this->playersToAttack).maximumSizeValue) {
                    do {
                      if (0 < iVar3) break;
                      iVar10 = iVar3 + 1;
                      piVar9[iVar3] = (this->playersToAttack).value[iVar3];
                      iVar3 = iVar10;
                    } while (iVar10 < (this->playersToAttack).maximumSizeValue);
                  }
                  operator_delete((this->playersToAttack).value);
                  (this->playersToAttack).value = piVar9;
                  (this->playersToAttack).maximumSizeValue = 1;
                }
                if ((int)*(short *)(*(int *)(objPosition.x + 0xc) + 0x4a) ==
                    *(this->playersToAttack).value) goto LAB_00503a7a;
              }
              goto LAB_00503954;
            }
LAB_00503a76:
            entryTime = entryTime + 1;
          }
          else {
LAB_00503954:
            fVar13 = RGE_Static_Object::distance_to_object(pRVar4,pRVar2);
            if (fVar13 < _DAT_00575784) {
              uVar5 = __ftol();
              uVar6 = __ftol();
              uVar7 = __ftol();
              iVar3 = pRVar4->_padding_;
              fVar12 = (float10)(**(code **)(iVar3 + 0x10c))(pRVar2->id,0,1,0xffffffff,0xffffffff);
              iVar3 = (**(code **)(iVar3 + 0x198))(uVar5,uVar6,uVar7,(float)fVar12);
              if (iVar3 != 0) {
                if ((this->soldiers).maximumSizeValue + -1 < count) {
                  piVar9 = (int *)operator_new(count * 4 + 4);
                  if (piVar9 != (int *)0x0) {
                    iVar3 = 0;
                    if (0 < (this->soldiers).maximumSizeValue) {
                      do {
                        if (count + 1 <= iVar3) break;
                        iVar10 = iVar3 + 1;
                        piVar9[iVar3] = (this->soldiers).value[iVar3];
                        iVar3 = iVar10;
                      } while (iVar10 < (this->soldiers).maximumSizeValue);
                    }
                    operator_delete((this->soldiers).value);
                    (this->soldiers).value = piVar9;
                    (this->soldiers).maximumSizeValue = count + 1;
                  }
                }
                iVar3 = taskAttacker(this,(this->soldiers).value[count],pRVar2->world_x,
                                     pRVar2->world_y,pRVar2->id,(int)pRVar2->owner->id,
                                     (Waypoint *)0x0,0,-1,0);
                if (iVar3 == 1) goto LAB_00503a76;
              }
            }
          }
        }
LAB_00503a7a:
        count = count + 1;
      } while (count < (this->soldiers).numberValue);
    }
    iVar3 = civilian(this,(XYPoint *)&objPosition.y,1,700,-1000,-1000,1);
    while (((iVar3 != -1 && ((int)entryTime < 6)) &&
           (pRVar4 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar3),
           pRVar4 != (RGE_Static_Object *)0x0))) {
      uVar5 = __ftol();
      uVar6 = __ftol();
      uVar7 = __ftol();
      objPosition.x = pRVar4->_padding_;
      fVar12 = (float10)(**(code **)(objPosition.x + 0x10c))(param_1,0,1,0xffffffff,0xffffffff);
      iVar10 = (**(code **)(objPosition.x + 0x198))(uVar5,uVar6,uVar7,(float)fVar12);
      if (iVar10 == 0) {
        return;
      }
      taskAttacker(this,iVar3,pRVar2->world_x,pRVar2->world_y,param_1,(int)pRVar2->owner->id,
                   (Waypoint *)0x0,0,-1,0);
      entryTime = entryTime + 1;
      iVar3 = civilian(this,(XYPoint *)&objPosition.y,1,700,0x2c9,0x2c9,1);
    }
  }
  return;
}

// --------------------------------------------------

