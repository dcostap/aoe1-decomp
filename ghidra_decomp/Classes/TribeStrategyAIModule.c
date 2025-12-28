// Class: TribeStrategyAIModule
// Size:  0x5F8
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] loggingHistory
// [02] setLogHistory
// [03] toggleLogHistory
// [04] setHistoryFilename
// [05] loggingCommonHistory
// [06] setLogCommonHistory
// [07] toggleLogCommonHistory
// [08] loadState
// [09] saveState
// [10] gleanState
// [11] processMessage
// [12] update
// [13] setCallbackMessage
// [14] filterOutMessage
// [15] save
// [16] `scalar_deleting_destructor'
//
// Member Layout:
// [0x0F0] TribeMainDecisionAIModule * md
// [0x0F4] int currentVictoryConditionValue
// [0x0F8] char[257] ruleSetNameValue (sz: 0x101)
// [0x1FC] int targetIDValue
// [0x200] int targetTypeValue
// [0x204] int secondTargetIDValue
// [0x208] int secondTargetTypeValue
// [0x20C] Waypoint targetPoint1Value (sz: 0x10)
// [0x21C] Waypoint targetPoint2Value (sz: 0x10)
// [0x22C] int targetAttributeValue
// [0x230] int targetNumberValue
// [0x234] int victoryConditionChangeTimeout
// [0x238] ManagedArray<int> vcRuleSet (sz: 0x10)
// [0x248] ManagedArray<int> executingRules (sz: 0x10)
// [0x258] ManagedArray<int> idleRules (sz: 0x10)
// [0x268] VictoryConditionRuleSystem vcRules (sz: 0x38C)
// [0x5F4] int difficultyLevel
// ----------------------------------------------------------------

// Function: TribeStrategyAIModule
// Address: 004e9100
// [HELPER] s_: ""
TribeStrategyAIModule * __thiscall
TribeStrategyAIModule::TribeStrategyAIModule(TribeStrategyAIModule *this,void *param_1,int param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005607b2;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  StrategyAIModule::StrategyAIModule((StrategyAIModule *)this,param_1,param_2);
  this->md = (TribeMainDecisionAIModule *)0x0;
  this->currentVictoryConditionValue = -1;
  this->targetIDValue = -1;
  this->targetTypeValue = -1;
  this->secondTargetIDValue = -1;
  this->secondTargetTypeValue = -1;
  this->targetAttributeValue = -1;
  this->targetNumberValue = -1;
  this->victoryConditionChangeTimeout = 0;
  (this->vcRuleSet).value = (int *)0x0;
  (this->vcRuleSet).numberValue = 0;
  (this->vcRuleSet).desiredNumberValue = 0;
  (this->vcRuleSet).maximumSizeValue = 0;
  (this->executingRules).value = (int *)0x0;
  (this->executingRules).numberValue = 0;
  (this->executingRules).desiredNumberValue = 0;
  (this->executingRules).maximumSizeValue = 0;
  (this->idleRules).value = (int *)0x0;
  (this->idleRules).numberValue = 0;
  (this->idleRules).desiredNumberValue = 0;
  (this->idleRules).maximumSizeValue = 0;
  local_4 = 3;
  VictoryConditionRuleSystem::VictoryConditionRuleSystem(&this->vcRules);
  (this->targetPoint1Value).x = -1.0;
  (this->targetPoint1Value).y = -1.0;
  (this->targetPoint1Value).z = -1.0;
  (this->targetPoint2Value).x = -1.0;
  (this->targetPoint2Value).y = -1.0;
  (this->targetPoint2Value).z = -1.0;
  uVar2 = 0xffffffff;
  this->difficultyLevel = 0;
  this->_padding_ = (int)&_vftable_;
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
  pcVar5 = this->ruleSetNameValue;
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
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004e9240
void * __thiscall
TribeStrategyAIModule::_vector_deleting_destructor_(TribeStrategyAIModule *this,uint param_1)
{
  ~TribeStrategyAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TribeStrategyAIModule
// Address: 004e9260
TribeStrategyAIModule * __thiscall
TribeStrategyAIModule::TribeStrategyAIModule(TribeStrategyAIModule *this,int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  int i;
  int tempIntNum;
  int local_18;
  int local_14;
  TribeStrategyAIModule *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560800;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_10 = this;
  StrategyAIModule::StrategyAIModule((StrategyAIModule *)this,(void *)0x0,param_1);
  this->md = (TribeMainDecisionAIModule *)0x0;
  (this->vcRuleSet).value = (int *)0x0;
  (this->vcRuleSet).numberValue = 0;
  (this->vcRuleSet).desiredNumberValue = 0;
  (this->vcRuleSet).maximumSizeValue = 0;
  (this->executingRules).value = (int *)0x0;
  (this->executingRules).numberValue = 0;
  (this->executingRules).desiredNumberValue = 0;
  (this->executingRules).maximumSizeValue = 0;
  (this->idleRules).value = (int *)0x0;
  (this->idleRules).numberValue = 0;
  (this->idleRules).desiredNumberValue = 0;
  (this->idleRules).maximumSizeValue = 0;
  local_4._0_1_ = 3;
  local_4._1_3_ = 0;
  VictoryConditionRuleSystem::VictoryConditionRuleSystem(&this->vcRules);
  iVar5 = param_2;
  piVar3 = &this->difficultyLevel;
  *piVar3 = 0;
  local_4 = CONCAT31(local_4._1_3_,4);
  this->_padding_ = (int)&_vftable_;
  rge_read(param_2,&this->currentVictoryConditionValue,4);
  rge_read(iVar5,&this->targetIDValue,4);
  rge_read(iVar5,&this->secondTargetIDValue,4);
  rge_read(iVar5,&this->secondTargetTypeValue,4);
  rge_read(iVar5,&this->targetPoint1Value,0x10);
  rge_read(iVar5,&this->targetPoint2Value,0x10);
  rge_read(iVar5,&this->targetAttributeValue,4);
  rge_read(iVar5,&this->targetNumberValue,4);
  rge_read(iVar5,&this->victoryConditionChangeTimeout,4);
  if (_DAT_00575690 <= save_game_version) {
    rge_read(iVar5,piVar3,4);
  }
  rge_read(iVar5,&param_1,4);
  rge_read(iVar5,this->ruleSetNameValue,param_1);
  this->ruleSetNameValue[param_1] = '\0';
  loadRules(this,this->ruleSetNameValue);
  setDifficultyLevel(this,*piVar3);
  rge_read(iVar5,&local_18,4);
  tempIntNum = 0;
  if (0 < local_18) {
    do {
      rge_read(iVar5,&param_1,4);
      iVar1 = (this->vcRuleSet).numberValue;
      iVar2 = 0;
      local_14 = param_1;
      if (0 < iVar1) {
        do {
          if ((this->vcRuleSet).maximumSizeValue <= iVar2) break;
          if ((this->vcRuleSet).value[iVar2] == param_1) goto LAB_004e94fb;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar1);
      }
      if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
        iVar1 = iVar1 + 1;
        piVar3 = (int *)operator_new(iVar1 * 4);
        if (piVar3 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (this->vcRuleSet).maximumSizeValue) {
            do {
              if (iVar1 <= iVar2) break;
              iVar4 = iVar2 + 1;
              piVar3[iVar2] = (this->vcRuleSet).value[iVar2];
              iVar2 = iVar4;
            } while (iVar4 < (this->vcRuleSet).maximumSizeValue);
          }
          operator_delete((this->vcRuleSet).value);
          (this->vcRuleSet).value = piVar3;
          (this->vcRuleSet).maximumSizeValue = iVar1;
        }
      }
      (this->vcRuleSet).value[(this->vcRuleSet).numberValue] = local_14;
      (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
LAB_004e94fb:
      tempIntNum = tempIntNum + 1;
    } while (tempIntNum < local_18);
  }
  rge_read(iVar5,&local_18,4);
  tempIntNum = 0;
  if (0 < local_18) {
    do {
      rge_read(iVar5,&param_1,4);
      iVar1 = (this->executingRules).numberValue;
      iVar2 = 0;
      local_14 = param_1;
      if (0 < iVar1) {
        do {
          if ((this->executingRules).maximumSizeValue <= iVar2) break;
          if ((this->executingRules).value[iVar2] == param_1) goto LAB_004e95ff;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar1);
      }
      if ((this->executingRules).maximumSizeValue + -1 < iVar1) {
        iVar1 = iVar1 + 1;
        piVar3 = (int *)operator_new(iVar1 * 4);
        if (piVar3 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (this->executingRules).maximumSizeValue) {
            do {
              if (iVar1 <= iVar2) break;
              iVar4 = iVar2 + 1;
              piVar3[iVar2] = (this->executingRules).value[iVar2];
              iVar2 = iVar4;
            } while (iVar4 < (this->executingRules).maximumSizeValue);
          }
          operator_delete((this->executingRules).value);
          (this->executingRules).value = piVar3;
          (this->executingRules).maximumSizeValue = iVar1;
        }
      }
      (this->executingRules).value[(this->executingRules).numberValue] = local_14;
      (this->executingRules).numberValue = (this->executingRules).numberValue + 1;
LAB_004e95ff:
      tempIntNum = tempIntNum + 1;
    } while (tempIntNum < local_18);
  }
  rge_read(iVar5,&local_18,4);
  tempIntNum = 0;
  if (0 < local_18) {
    do {
      rge_read(iVar5,&param_1,4);
      iVar1 = param_1;
      iVar5 = (this->idleRules).numberValue;
      iVar2 = 0;
      if (0 < iVar5) {
        do {
          if ((this->idleRules).maximumSizeValue <= iVar2) break;
          if ((this->idleRules).value[iVar2] == param_1) goto LAB_004e9703;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar5);
      }
      if ((this->idleRules).maximumSizeValue + -1 < iVar5) {
        iVar5 = iVar5 + 1;
        piVar3 = (int *)operator_new(iVar5 * 4);
        if (piVar3 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (this->idleRules).maximumSizeValue) {
            do {
              if (iVar5 <= iVar2) break;
              iVar4 = iVar2 + 1;
              piVar3[iVar2] = (this->idleRules).value[iVar2];
              iVar2 = iVar4;
            } while (iVar4 < (this->idleRules).maximumSizeValue);
          }
          operator_delete((this->idleRules).value);
          (this->idleRules).value = piVar3;
          (this->idleRules).maximumSizeValue = iVar5;
        }
      }
      (this->idleRules).value[(this->idleRules).numberValue] = iVar1;
      (this->idleRules).numberValue = (this->idleRules).numberValue + 1;
LAB_004e9703:
      tempIntNum = tempIntNum + 1;
      iVar5 = param_2;
    } while (tempIntNum < local_18);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TribeStrategyAIModule
// Address: 004e9730
void __thiscall TribeStrategyAIModule::~TribeStrategyAIModule(TribeStrategyAIModule *this)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00560842;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 3;
  VictoryConditionRuleSystem::~VictoryConditionRuleSystem(&this->vcRules);
  piVar1 = (this->idleRules).value;
  local_4._0_1_ = 2;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->idleRules).value = (int *)0x0;
  }
  (this->idleRules).numberValue = 0;
  (this->idleRules).desiredNumberValue = 0;
  (this->idleRules).maximumSizeValue = 0;
  piVar1 = (this->executingRules).value;
  local_4._0_1_ = 1;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->executingRules).value = (int *)0x0;
  }
  (this->executingRules).numberValue = 0;
  (this->executingRules).desiredNumberValue = 0;
  (this->executingRules).maximumSizeValue = 0;
  piVar1 = (this->vcRuleSet).value;
  local_4 = (uint)local_4._1_3_ << 8;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->vcRuleSet).value = (int *)0x0;
  }
  (this->vcRuleSet).numberValue = 0;
  (this->vcRuleSet).desiredNumberValue = 0;
  (this->vcRuleSet).maximumSizeValue = 0;
  local_4 = 0xffffffff;
  StrategyAIModule::~StrategyAIModule((StrategyAIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004e9820
int __thiscall TribeStrategyAIModule::update(TribeStrategyAIModule *this,int param_1)
{
  ManagedArray<int> *pMVar1;
  int iVar2;
  RGE_Victory_Entry *pRVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int worstRuleResult;
  int result;
  int local_4;
  
  iVar7 = 0;
  iVar2 = this->victoryConditionChangeTimeout + 1;
  this->victoryConditionChangeTimeout = iVar2;
  if (-1 < iVar2) {
    this->victoryConditionChangeTimeout = 0;
    uVar8 = 0xb;
    pRVar3 = RGE_Victory_Conditions::condition_raw_info
                       (*(RGE_Victory_Conditions **)(this->md->_padding_ + 0x34),0);
    if (pRVar3 != (RGE_Victory_Entry *)0x0) {
      uVar8 = (uint)pRVar3->command;
      if (pRVar3->target_obj != (RGE_Static_Object *)0x0) {
        this->targetIDValue = pRVar3->target_obj->id;
        this->targetTypeValue = (int)pRVar3->target_obj->master_obj->id;
      }
      if (pRVar3->this_obj != (RGE_Static_Object *)0x0) {
        this->secondTargetIDValue = pRVar3->this_obj->id;
        this->secondTargetTypeValue = (int)pRVar3->this_obj->master_obj->id;
      }
      (this->targetPoint1Value).x = pRVar3->x0;
      (this->targetPoint1Value).y = pRVar3->y0;
      (this->targetPoint1Value).z = 1.0;
      (this->targetPoint2Value).x = pRVar3->x1;
      (this->targetPoint2Value).y = pRVar3->y1;
      (this->targetPoint2Value).z = 1.0;
      this->targetAttributeValue = pRVar3->number;
      this->targetNumberValue = pRVar3->count;
    }
    if (uVar8 != this->currentVictoryConditionValue) {
      setVictoryCondition(this,uVar8);
    }
  }
  iVar2 = 0;
  result = -1;
  iVar4 = -1;
  if (0 < (this->idleRules).numberValue) {
    pMVar1 = &this->idleRules;
    do {
      if ((this->idleRules).maximumSizeValue + -1 < iVar7) {
        ManagedArray<int>::resize(pMVar1,iVar7 + 1);
      }
      iVar4 = VictoryConditionRuleSystem::evaluateAsNonInProgress
                        (&this->vcRules,this->md->aiPlayer,pMVar1->value[iVar7]);
      if (iVar2 < iVar4) {
        if (((this->idleRules).maximumSizeValue + -1 < iVar7) &&
           (piVar5 = (int *)operator_new(iVar7 * 4 + 4), piVar5 != (int *)0x0)) {
          iVar2 = 0;
          if (0 < (this->idleRules).maximumSizeValue) {
            do {
              if (iVar7 + 1 <= iVar2) break;
              iVar6 = iVar2 + 1;
              piVar5[iVar2] = pMVar1->value[iVar2];
              iVar2 = iVar6;
            } while (iVar6 < (this->idleRules).maximumSizeValue);
          }
          operator_delete(pMVar1->value);
          pMVar1->value = piVar5;
          (this->idleRules).maximumSizeValue = iVar7 + 1;
        }
        result = pMVar1->value[iVar7];
        iVar2 = iVar4;
      }
      iVar7 = iVar7 + 1;
      iVar4 = result;
    } while (iVar7 < (this->idleRules).numberValue);
  }
  if ((iVar4 != -1) &&
     (iVar2 = VictoryConditionRuleSystem::execute
                        (&this->vcRules,this->md->aiPlayer,this->currentVictoryConditionValue,iVar4)
     , iVar2 == 1)) {
    iVar2 = (this->executingRules).numberValue;
    pMVar1 = &this->executingRules;
    iVar7 = 0;
    if (0 < iVar2) {
      do {
        if ((this->executingRules).maximumSizeValue <= iVar7) break;
        if (pMVar1->value[iVar7] == iVar4) goto LAB_004e9a47;
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar2);
    }
    if ((this->executingRules).maximumSizeValue + -1 < iVar2) {
      ManagedArray<int>::resize(pMVar1,iVar2 + 1);
    }
    pMVar1->value[(this->executingRules).numberValue] = iVar4;
    (this->executingRules).numberValue = (this->executingRules).numberValue + 1;
LAB_004e9a47:
    iVar2 = (this->idleRules).maximumSizeValue;
    iVar7 = 0;
    if (0 < iVar2) {
      piVar5 = (this->idleRules).value;
      do {
        if (*piVar5 == iVar4) break;
        iVar7 = iVar7 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar7 < iVar2);
    }
    if (iVar7 < iVar2) {
      if (iVar7 < iVar2 + -1) {
        do {
          piVar5 = (this->idleRules).value;
          iVar2 = iVar7 + 1;
          piVar5[iVar7] = piVar5[iVar2];
          iVar7 = iVar2;
        } while (iVar2 < (this->idleRules).maximumSizeValue + -1);
      }
      iVar2 = (this->idleRules).numberValue + -1;
      (this->idleRules).numberValue = iVar2;
      if (iVar2 < 0) {
        (this->idleRules).numberValue = 0;
      }
    }
  }
  iVar7 = 0;
  local_4 = -1;
  result = 0x65;
  iVar2 = -1;
  if (0 < (this->executingRules).numberValue) {
    pMVar1 = &this->executingRules;
    do {
      if (((this->executingRules).maximumSizeValue + -1 < iVar7) &&
         (piVar5 = (int *)operator_new(iVar7 * 4 + 4), piVar5 != (int *)0x0)) {
        iVar2 = 0;
        if (0 < (this->executingRules).maximumSizeValue) {
          do {
            if (iVar7 + 1 <= iVar2) break;
            iVar4 = iVar2 + 1;
            piVar5[iVar2] = pMVar1->value[iVar2];
            iVar2 = iVar4;
          } while (iVar4 < (this->executingRules).maximumSizeValue);
        }
        operator_delete(pMVar1->value);
        pMVar1->value = piVar5;
        (this->executingRules).maximumSizeValue = iVar7 + 1;
      }
      iVar2 = VictoryConditionRuleSystem::evaluateAsInProgress
                        (&this->vcRules,this->md->aiPlayer,pMVar1->value[iVar7]);
      if (iVar2 < result) {
        if ((this->executingRules).maximumSizeValue + -1 < iVar7) {
          ManagedArray<int>::resize(pMVar1,iVar7 + 1);
        }
        local_4 = pMVar1->value[iVar7];
        result = iVar2;
      }
      iVar7 = iVar7 + 1;
      iVar2 = local_4;
    } while (iVar7 < (this->executingRules).numberValue);
  }
  if ((iVar2 != -1) &&
     (iVar7 = VictoryConditionRuleSystem::stopExecution(&this->vcRules,this->md->aiPlayer,iVar2),
     iVar7 == 1)) {
    iVar7 = (this->executingRules).maximumSizeValue;
    iVar4 = 0;
    if (0 < iVar7) {
      piVar5 = (this->executingRules).value;
      do {
        if (*piVar5 == iVar2) break;
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar4 < iVar7);
    }
    if (iVar4 < iVar7) {
      if (iVar4 < iVar7 + -1) {
        do {
          piVar5 = (this->executingRules).value;
          iVar7 = iVar4 + 1;
          piVar5[iVar4] = piVar5[iVar7];
          iVar4 = iVar7;
        } while (iVar7 < (this->executingRules).maximumSizeValue + -1);
      }
      iVar7 = (this->executingRules).numberValue + -1;
      (this->executingRules).numberValue = iVar7;
      if (iVar7 < 0) {
        (this->executingRules).numberValue = 0;
      }
    }
    iVar7 = (this->idleRules).numberValue;
    pMVar1 = &this->idleRules;
    iVar4 = 0;
    if (0 < iVar7) {
      do {
        if ((this->idleRules).maximumSizeValue <= iVar4) break;
        if (pMVar1->value[iVar4] == iVar2) goto LAB_004e9c3d;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar7);
    }
    if ((this->idleRules).maximumSizeValue + -1 < iVar7) {
      ManagedArray<int>::resize(pMVar1,iVar7 + 1);
    }
    pMVar1->value[(this->idleRules).numberValue] = iVar2;
    (this->idleRules).numberValue = (this->idleRules).numberValue + 1;
  }
LAB_004e9c3d:
  iVar2 = 0;
  if (0 < (this->vcRuleSet).numberValue) {
    do {
      if ((this->vcRuleSet).maximumSizeValue + -1 < iVar2) {
        piVar5 = (int *)operator_new(iVar2 * 4 + 4);
        if (piVar5 != (int *)0x0) {
          iVar7 = 0;
          if (0 < (this->vcRuleSet).maximumSizeValue) {
            do {
              if (iVar2 + 1 <= iVar7) break;
              iVar4 = iVar7 + 1;
              piVar5[iVar7] = (this->vcRuleSet).value[iVar7];
              iVar7 = iVar4;
            } while (iVar4 < (this->vcRuleSet).maximumSizeValue);
          }
          operator_delete((this->vcRuleSet).value);
          (this->vcRuleSet).value = piVar5;
          (this->vcRuleSet).maximumSizeValue = iVar2 + 1;
        }
      }
      iVar7 = VictoryConditionRuleSystem::evaluateAsNonInProgress
                        (&this->vcRules,this->md->aiPlayer,(this->vcRuleSet).value[iVar2]);
      if (iVar7 == -1) {
        if ((this->vcRuleSet).maximumSizeValue + -1 < iVar2) {
          piVar5 = (int *)operator_new(iVar2 * 4 + 4);
          if (piVar5 != (int *)0x0) {
            iVar7 = 0;
            if (0 < (this->vcRuleSet).maximumSizeValue) {
              do {
                if (iVar2 + 1 <= iVar7) break;
                iVar4 = iVar7 + 1;
                piVar5[iVar7] = (this->vcRuleSet).value[iVar7];
                iVar7 = iVar4;
              } while (iVar4 < (this->vcRuleSet).maximumSizeValue);
            }
            operator_delete((this->vcRuleSet).value);
            (this->vcRuleSet).value = piVar5;
            (this->vcRuleSet).maximumSizeValue = iVar2 + 1;
          }
        }
        VictoryConditionRuleSystem::execute
                  (&this->vcRules,this->md->aiPlayer,this->currentVictoryConditionValue,
                   (this->vcRuleSet).value[iVar2]);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (this->vcRuleSet).numberValue);
  }
  return 1;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 004e9d90
void __thiscall
TribeStrategyAIModule::setMainDecisionAI
          (TribeStrategyAIModule *this,TribeMainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004e9da0
int __thiscall TribeStrategyAIModule::save(TribeStrategyAIModule *this,int param_1)
{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int tempInt;
  char tempString [257];
  
  rge_write(param_1,&this->currentVictoryConditionValue,4);
  rge_write(param_1,&this->targetIDValue,4);
  rge_write(param_1,&this->secondTargetIDValue,4);
  rge_write(param_1,&this->secondTargetTypeValue,4);
  rge_write(param_1,&this->targetPoint1Value,0x10);
  rge_write(param_1,&this->targetPoint2Value,0x10);
  rge_write(param_1,&this->targetAttributeValue,4);
  rge_write(param_1,&this->targetNumberValue,4);
  rge_write(param_1,&this->victoryConditionChangeTimeout,4);
  rge_write(param_1,&this->difficultyLevel,4);
  uVar5 = 0xffffffff;
  pcVar8 = this->ruleSetNameValue;
  do {
    pcVar7 = pcVar8;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar7;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar8 = tempString;
  pcVar7 = pcVar7 + -uVar5;
  for (uVar6 = uVar5 >> 2; pcVar8 = pcVar8 + 4, uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar8 = tempString + 4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  tempString._0_4_ = ~uVar5 - 1;
  rge_write(param_1,tempString,4);
  uVar5 = 0xffffffff;
  pcVar8 = tempString + 4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  rge_write(param_1,tempString + 4,~uVar5 - 1);
  tempString._0_4_ = (this->vcRuleSet).numberValue;
  rge_write(param_1,tempString,4);
  iVar9 = 0;
  if (0 < (this->vcRuleSet).numberValue) {
    do {
      if (((this->vcRuleSet).maximumSizeValue + -1 < iVar9) &&
         (piVar2 = (int *)operator_new(iVar9 * 4 + 4), piVar2 != (int *)0x0)) {
        iVar4 = 0;
        if (0 < (this->vcRuleSet).maximumSizeValue) {
          do {
            if (iVar9 + 1 <= iVar4) break;
            iVar3 = iVar4 + 1;
            piVar2[iVar4] = (this->vcRuleSet).value[iVar4];
            iVar4 = iVar3;
          } while (iVar3 < (this->vcRuleSet).maximumSizeValue);
        }
        operator_delete((this->vcRuleSet).value);
        (this->vcRuleSet).value = piVar2;
        (this->vcRuleSet).maximumSizeValue = iVar9 + 1;
      }
      tempString._0_4_ = (this->vcRuleSet).value[iVar9];
      rge_write(param_1,tempString,4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->vcRuleSet).numberValue);
  }
  tempString._0_4_ = (this->executingRules).numberValue;
  rge_write(param_1,tempString,4);
  iVar9 = 0;
  if (0 < (this->executingRules).numberValue) {
    do {
      if (((this->executingRules).maximumSizeValue + -1 < iVar9) &&
         (piVar2 = (int *)operator_new(iVar9 * 4 + 4), piVar2 != (int *)0x0)) {
        iVar4 = 0;
        if (0 < (this->executingRules).maximumSizeValue) {
          do {
            if (iVar9 + 1 <= iVar4) break;
            iVar3 = iVar4 + 1;
            piVar2[iVar4] = (this->executingRules).value[iVar4];
            iVar4 = iVar3;
          } while (iVar3 < (this->executingRules).maximumSizeValue);
        }
        operator_delete((this->executingRules).value);
        (this->executingRules).value = piVar2;
        (this->executingRules).maximumSizeValue = iVar9 + 1;
      }
      tempString._0_4_ = (this->executingRules).value[iVar9];
      rge_write(param_1,tempString,4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->executingRules).numberValue);
  }
  tempString._0_4_ = (this->idleRules).numberValue;
  rge_write(param_1,tempString,4);
  iVar9 = 0;
  if (0 < (this->idleRules).numberValue) {
    do {
      if ((this->idleRules).maximumSizeValue + -1 < iVar9) {
        piVar2 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar2 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->idleRules).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar4) break;
              iVar3 = iVar4 + 1;
              piVar2[iVar4] = (this->idleRules).value[iVar4];
              iVar4 = iVar3;
            } while (iVar3 < (this->idleRules).maximumSizeValue);
          }
          operator_delete((this->idleRules).value);
          (this->idleRules).value = piVar2;
          (this->idleRules).maximumSizeValue = iVar9 + 1;
        }
      }
      tempString._0_4_ = (this->idleRules).value[iVar9];
      rge_write(param_1,tempString,4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (this->idleRules).numberValue);
  }
  return 1;
}

// --------------------------------------------------

// Function: ruleSetName
// Address: 004ea130
char * __thiscall TribeStrategyAIModule::ruleSetName(TribeStrategyAIModule *this)
{
  return this->ruleSetNameValue;
}

// --------------------------------------------------

// Function: loadRules
// Address: 004ea140
int __thiscall TribeStrategyAIModule::loadRules(TribeStrategyAIModule *this,char *param_1)
{
  int iVar1;
  
  if (param_1 == (char *)0x0) {
    return (int)param_1;
  }
  strncpy(this->ruleSetNameValue,param_1,0xff);
  iVar1 = VictoryConditionRuleSystem::loadRules(&this->vcRules,this->ruleSetNameValue);
  return iVar1;
}

// --------------------------------------------------

// Function: setRule
// Address: 004ea180
// [HELPER] s_Setting_SN__d__to__d_: "Setting SN[%d] to %d."
void __thiscall TribeStrategyAIModule::setRule(TribeStrategyAIModule *this,int param_1,int param_2)
{
  AIModule::logCommonHistory((AIModule *)this,(char *)this,s_Setting_SN__d__to__d_,param_1,param_2);
  VictoryConditionRuleSystem::setRule(&this->vcRules,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: rule
// Address: 004ea1b0
int __thiscall TribeStrategyAIModule::rule(TribeStrategyAIModule *this,int param_1)
{
  int iVar1;
  
  iVar1 = VictoryConditionRuleSystem::rule(&this->vcRules,param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: setDifficultyLevel
// Address: 004ea1d0
void __thiscall TribeStrategyAIModule::setDifficultyLevel(TribeStrategyAIModule *this,int param_1)
{
  VictoryConditionRuleSystem::modifyForDifficultyLevel(&this->vcRules,param_1);
  return;
}

// --------------------------------------------------

// Function: currentVictoryCondition
// Address: 004ea1f0
int __thiscall TribeStrategyAIModule::currentVictoryCondition(TribeStrategyAIModule *this)
{
  return this->currentVictoryConditionValue;
}

// --------------------------------------------------

// Function: targetID
// Address: 004ea200
int __thiscall TribeStrategyAIModule::targetID(TribeStrategyAIModule *this)
{
  return this->targetIDValue;
}

// --------------------------------------------------

// Function: targetType
// Address: 004ea210
int __thiscall TribeStrategyAIModule::targetType(TribeStrategyAIModule *this)
{
  return this->targetTypeValue;
}

// --------------------------------------------------

// Function: secondTargetID
// Address: 004ea220
int __thiscall TribeStrategyAIModule::secondTargetID(TribeStrategyAIModule *this)
{
  return this->secondTargetIDValue;
}

// --------------------------------------------------

// Function: secondTargetType
// Address: 004ea230
int __thiscall TribeStrategyAIModule::secondTargetType(TribeStrategyAIModule *this)
{
  return this->secondTargetTypeValue;
}

// --------------------------------------------------

// Function: targetPoint1
// Address: 004ea240
Waypoint * __thiscall TribeStrategyAIModule::targetPoint1(TribeStrategyAIModule *this)
{
  return &this->targetPoint1Value;
}

// --------------------------------------------------

// Function: targetPoint2
// Address: 004ea250
Waypoint * __thiscall TribeStrategyAIModule::targetPoint2(TribeStrategyAIModule *this)
{
  return &this->targetPoint2Value;
}

// --------------------------------------------------

// Function: targetAttribute
// Address: 004ea260
int __thiscall TribeStrategyAIModule::targetAttribute(TribeStrategyAIModule *this)
{
  return this->targetAttributeValue;
}

// --------------------------------------------------

// Function: targetNumber
// Address: 004ea270
int __thiscall TribeStrategyAIModule::targetNumber(TribeStrategyAIModule *this)
{
  return this->targetNumberValue;
}

// --------------------------------------------------

// Function: setVictoryCondition
// Address: 004ea280
void __thiscall TribeStrategyAIModule::setVictoryCondition(TribeStrategyAIModule *this,int param_1)
{
  ManagedArray<int> *this_00;
  int iVar1;
  int *piVar2;
  ManagedArray<int> *this_01;
  int iVar3;
  
  this_00 = &this->vcRuleSet;
  iVar3 = 0;
  this->currentVictoryConditionValue = param_1;
  (this->vcRuleSet).numberValue = 0;
  param_1 = 1;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 2;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 0xc;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 0xd;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 0xe;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 0x10;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 0x11;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 0x12;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 0x15;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 0x16;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 0x17;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 0x18;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  param_1 = 0x19;
  iVar1 = ManagedArray<int>::contains(this_00,&param_1);
  if (iVar1 != 1) {
    iVar1 = (this->vcRuleSet).numberValue;
    if ((this->vcRuleSet).maximumSizeValue + -1 < iVar1) {
      ManagedArray<int>::resize(this_00,iVar1 + 1);
    }
    this_00->value[(this->vcRuleSet).numberValue] = param_1;
    (this->vcRuleSet).numberValue = (this->vcRuleSet).numberValue + 1;
  }
  ManagedArray<int>::add(this_00,0x1a);
  ManagedArray<int>::add(this_00,0x1b);
  ManagedArray<int>::add(this_00,0x1c);
  ManagedArray<int>::add(this_00,0x1d);
  ManagedArray<int>::add(this_00,0x1e);
  ManagedArray<int>::add(this_00,0x1f);
  ManagedArray<int>::add(this_00,0x20);
  ManagedArray<int>::add(this_00,0x21);
  ManagedArray<int>::add(this_00,0x22);
  ManagedArray<int>::add(this_00,0x23);
  ManagedArray<int>::add(this_00,0x24);
  ManagedArray<int>::add(this_00,0x25);
  ManagedArray<int>::add(this_00,0x26);
  ManagedArray<int>::add(this_00,0x27);
  ManagedArray<int>::add(this_00,0x28);
  ManagedArray<int>::add(this_00,0x29);
  ManagedArray<int>::add(this_00,0x2a);
  ManagedArray<int>::add(this_00,0x2b);
  ManagedArray<int>::add(this_00,0x2c);
  ManagedArray<int>::add(this_00,0x2d);
  ManagedArray<int>::add(this_00,0x2e);
  ManagedArray<int>::add(this_00,0x2f);
  ManagedArray<int>::add(this_00,0x30);
  ManagedArray<int>::add(this_00,0x31);
  if (0 < (this->vcRuleSet).numberValue) {
    do {
      piVar2 = ManagedArray<int>::operator[](this_00,iVar3);
      iVar1 = VictoryConditionRuleSystem::evaluateAsNonInProgress
                        (&this->vcRules,this->md->aiPlayer,*piVar2);
      if (iVar1 == -2) {
        piVar2 = ManagedArray<int>::operator[](this_00,iVar3);
        iVar1 = VictoryConditionRuleSystem::execute
                          (&this->vcRules,this->md->aiPlayer,this->currentVictoryConditionValue,
                           *piVar2);
        if (iVar1 == 1) {
          piVar2 = ManagedArray<int>::operator[](this_00,iVar3);
          iVar1 = *piVar2;
          this_01 = &this->executingRules;
        }
        else {
          piVar2 = ManagedArray<int>::operator[](this_00,iVar3);
          iVar1 = *piVar2;
          this_01 = &this->idleRules;
        }
        ManagedArray<int>::add(this_01,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (this->vcRuleSet).numberValue);
  }
  return;
}

// --------------------------------------------------

// Function: isRuleExecuting
// Address: 004ea7c0
int __thiscall TribeStrategyAIModule::isRuleExecuting(TribeStrategyAIModule *this,int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = (this->executingRules).numberValue;
  iVar2 = 0;
  if (0 < iVar1) {
    while (iVar2 < (this->executingRules).maximumSizeValue) {
      if ((this->executingRules).value[iVar2] == param_1) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      if (iVar1 <= iVar2) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: isRuleIdle
// Address: 004ea810
int __thiscall TribeStrategyAIModule::isRuleIdle(TribeStrategyAIModule *this,int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = (this->idleRules).numberValue;
  iVar2 = 0;
  if (0 < iVar1) {
    while (iVar2 < (this->idleRules).maximumSizeValue) {
      if ((this->idleRules).value[iVar2] == param_1) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      if (iVar1 <= iVar2) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

