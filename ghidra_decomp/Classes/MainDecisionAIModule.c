// Class: MainDecisionAIModule
// Size:  0x104
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
// [16] addObject
// [17] removeObject
// [18] objectGroupThatCanPerformAction
// [19] canPerformAction
// [20] `vector_deleting_destructor'
// [21] `scalar_deleting_destructor'
// [22] `scalar_deleting_destructor'
// [23] loggingHistory
// [24] setLogHistory
// [25] toggleLogHistory
// [26] setHistoryFilename
// [27] loggingCommonHistory
// [28] setLogCommonHistory
// [29] toggleLogCommonHistory
// [30] loadState
// [31] saveState
// [32] gleanState
// [33] processMessage
// [34] update
// [35] setCallbackMessage
// [36] filterOutMessage
//
// Member Layout:
// [0x0F0] RGE_Player * player
// [0x0F4] ManagedArray<int> objects (sz: 0x10)
// ----------------------------------------------------------------

// Function: MainDecisionAIModule
// Address: 0040cdf0
// [HELPER] s_Main_Decision_AI: "Main Decision AI"
MainDecisionAIModule * __thiscall
MainDecisionAIModule::MainDecisionAIModule
          (MainDecisionAIModule *this,void *param_1,int param_2,RGE_Player *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c638;
  *unaff_FS_OFFSET = &local_c;
  AIModule::AIModule((AIModule *)this,s_Main_Decision_AI,1000,param_2,param_1);
  this->player = param_3;
  (this->objects).value = (int *)0x0;
  (this->objects).numberValue = 0;
  (this->objects).desiredNumberValue = 0;
  (this->objects).maximumSizeValue = 0;
  this->_padding_ = (int)&_vftable_;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0040ce70
void * __thiscall
MainDecisionAIModule::_vector_deleting_destructor_(MainDecisionAIModule *this,uint param_1)
{
  ~MainDecisionAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: MainDecisionAIModule
// Address: 0040ce90
// [HELPER] s_Main_Decision_AI: "Main Decision AI"
MainDecisionAIModule * __thiscall
MainDecisionAIModule::MainDecisionAIModule
          (MainDecisionAIModule *this,int param_1,RGE_Player *param_2,int param_3)
{
  int iVar1;
  RGE_Player *pRVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  int numberUnits;
  int local_14;
  MainDecisionAIModule *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c666;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_10 = this;
  AIModule::AIModule((AIModule *)this,s_Main_Decision_AI,1000,param_1,(void *)0x0);
  this->player = param_2;
  (this->objects).value = (int *)0x0;
  (this->objects).numberValue = 0;
  (this->objects).desiredNumberValue = 0;
  (this->objects).maximumSizeValue = 0;
  local_4 = 1;
  this->_padding_ = (int)&_vftable_;
  rge_read(param_3,&local_14,4);
  param_1 = 0;
  if (0 < local_14) {
    do {
      rge_read(param_3,&param_2,4);
      pRVar2 = param_2;
      iVar1 = (this->objects).numberValue;
      iVar3 = 0;
      if (0 < iVar1) {
        do {
          if ((this->objects).maximumSizeValue <= iVar3) break;
          if ((RGE_Player *)(this->objects).value[iVar3] == param_2) goto LAB_0040cfea;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar1);
      }
      if ((this->objects).maximumSizeValue + -1 < iVar1) {
        iVar1 = iVar1 + 1;
        piVar4 = (int *)operator_new(iVar1 * 4);
        if (piVar4 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->objects).maximumSizeValue) {
            do {
              if (iVar1 <= iVar3) break;
              iVar5 = iVar3 + 1;
              piVar4[iVar3] = (this->objects).value[iVar3];
              iVar3 = iVar5;
            } while (iVar5 < (this->objects).maximumSizeValue);
          }
          operator_delete((this->objects).value);
          (this->objects).value = piVar4;
          (this->objects).maximumSizeValue = iVar1;
        }
      }
      (this->objects).value[(this->objects).numberValue] = (int)pRVar2;
      (this->objects).numberValue = (this->objects).numberValue + 1;
LAB_0040cfea:
      param_1 = param_1 + 1;
    } while (param_1 < local_14);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~MainDecisionAIModule
// Address: 0040d020
void __thiscall MainDecisionAIModule::~MainDecisionAIModule(MainDecisionAIModule *this)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055c678;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  piVar1 = (this->objects).value;
  local_4 = 0;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->objects).value = (int *)0x0;
  }
  (this->objects).numberValue = 0;
  (this->objects).desiredNumberValue = 0;
  (this->objects).maximumSizeValue = 0;
  local_4 = 0xffffffff;
  AIModule::~AIModule((AIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: setLogHistory
// Address: 0040d090
void __thiscall MainDecisionAIModule::setLogHistory(MainDecisionAIModule *this,int param_1)
{
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0040d0a0
int __thiscall MainDecisionAIModule::save(MainDecisionAIModule *this,int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int tempInt;
  int local_4;
  
  local_4 = (this->objects).numberValue;
  rge_write(param_1,&local_4,4);
  iVar4 = 0;
  if (0 < (this->objects).numberValue) {
    do {
      if ((this->objects).maximumSizeValue + -1 < iVar4) {
        piVar1 = (int *)operator_new(iVar4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (this->objects).maximumSizeValue) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar3 = iVar2 + 1;
              piVar1[iVar2] = (this->objects).value[iVar2];
              iVar2 = iVar3;
            } while (iVar3 < (this->objects).maximumSizeValue);
          }
          operator_delete((this->objects).value);
          (this->objects).value = piVar1;
          (this->objects).maximumSizeValue = iVar4 + 1;
        }
      }
      local_4 = (this->objects).value[iVar4];
      rge_write(param_1,&local_4,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->objects).numberValue);
  }
  return 1;
}

// --------------------------------------------------

// Function: addObject
// Address: 0040d180
int __thiscall
MainDecisionAIModule::addObject(MainDecisionAIModule *this,RGE_Static_Object *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1 == (RGE_Static_Object *)0x0) {
    return (int)param_1;
  }
  iVar1 = (this->objects).numberValue;
  iVar2 = param_1->id;
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if ((this->objects).maximumSizeValue <= iVar3) break;
      if ((this->objects).value[iVar3] == iVar2) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  if ((this->objects).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar4 = (int *)operator_new(iVar1 * 4);
    if (piVar4 != (int *)0x0) {
      iVar3 = 0;
      if (0 < (this->objects).maximumSizeValue) {
        do {
          if (iVar1 <= iVar3) break;
          iVar5 = iVar3 + 1;
          piVar4[iVar3] = (this->objects).value[iVar3];
          iVar3 = iVar5;
        } while (iVar5 < (this->objects).maximumSizeValue);
      }
      operator_delete((this->objects).value);
      (this->objects).value = piVar4;
      (this->objects).maximumSizeValue = iVar1;
    }
  }
  (this->objects).value[(this->objects).numberValue] = iVar2;
  (this->objects).numberValue = (this->objects).numberValue + 1;
  return 1;
}

// --------------------------------------------------

// Function: removeObject
// Address: 0040d250
int __thiscall MainDecisionAIModule::removeObject(MainDecisionAIModule *this,int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = (this->objects).maximumSizeValue;
  iVar1 = 0;
  if (0 < iVar2) {
    piVar3 = (this->objects).value;
    do {
      if (*piVar3 == param_1) break;
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar1 < iVar2);
  }
  if (iVar2 <= iVar1) {
    return 0;
  }
  if (iVar1 < iVar2 + -1) {
    do {
      piVar3 = (this->objects).value;
      iVar2 = iVar1 + 1;
      piVar3[iVar1] = piVar3[iVar2];
      iVar1 = iVar2;
    } while (iVar2 < (this->objects).maximumSizeValue + -1);
  }
  iVar2 = (this->objects).numberValue + -1;
  (this->objects).numberValue = iVar2;
  if (iVar2 < 0) {
    (this->objects).numberValue = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: numberObjects
// Address: 0040d2c0
int __thiscall MainDecisionAIModule::numberObjects(MainDecisionAIModule *this)
{
  return (this->objects).numberValue;
}

// --------------------------------------------------

// Function: numberObjectsWithAction
// Address: 0040d2d0
int __thiscall MainDecisionAIModule::numberObjectsWithAction(MainDecisionAIModule *this,int param_1)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  int count;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  if (0 < (this->objects).numberValue) {
    do {
      if ((this->objects).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->objects).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->objects).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->objects).maximumSizeValue);
          }
          operator_delete((this->objects).value);
          (this->objects).value = piVar1;
          (this->objects).maximumSizeValue = iVar5 + 1;
        }
      }
      this_00 = RGE_Game_World::object(this->player->world,(this->objects).value[iVar5]);
      if ((this_00 != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this_00), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 == param_1) {
          local_4 = local_4 + 1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->objects).numberValue);
  }
  return local_4;
}

// --------------------------------------------------

// Function: numberObjectsWithGroup
// Address: 0040d3b0
int __thiscall MainDecisionAIModule::numberObjectsWithGroup(MainDecisionAIModule *this,int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int count;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  if (0 < (this->objects).numberValue) {
    do {
      if ((this->objects).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (this->objects).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar2) break;
              iVar3 = iVar2 + 1;
              piVar1[iVar2] = (this->objects).value[iVar2];
              iVar2 = iVar3;
            } while (iVar3 < (this->objects).maximumSizeValue);
          }
          operator_delete((this->objects).value);
          (this->objects).value = piVar1;
          (this->objects).maximumSizeValue = iVar5 + 1;
        }
      }
      pRVar4 = RGE_Game_World::object(this->player->world,(this->objects).value[iVar5]);
      if ((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->master_obj->object_group == param_1)) {
        local_4 = local_4 + 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->objects).numberValue);
  }
  return local_4;
}

// --------------------------------------------------

// Function: numberObjectsWithActionAndTarget
// Address: 0040d480
int __thiscall
MainDecisionAIModule::numberObjectsWithActionAndTarget
          (MainDecisionAIModule *this,int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  int count;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  if (0 < (this->objects).numberValue) {
    do {
      if ((this->objects).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->objects).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->objects).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->objects).maximumSizeValue);
          }
          operator_delete((this->objects).value);
          (this->objects).value = piVar1;
          (this->objects).maximumSizeValue = iVar5 + 1;
        }
      }
      this_00 = RGE_Game_World::object(this->player->world,(this->objects).value[iVar5]);
      if ((this_00 != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this_00), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 == param_1) {
          pUVar3 = RGE_Static_Object::unitAI(this_00);
          iVar4 = UnitAIModule::currentTarget(pUVar3);
          if (iVar4 == param_2) {
            local_4 = local_4 + 1;
          }
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->objects).numberValue);
  }
  return local_4;
}

// --------------------------------------------------

// Function: numberObjectsWithTargetType
// Address: 0040d580
int __thiscall
MainDecisionAIModule::numberObjectsWithTargetType(MainDecisionAIModule *this,int param_1)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  int count;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  if (0 < (this->objects).numberValue) {
    do {
      if ((this->objects).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->objects).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->objects).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->objects).maximumSizeValue);
          }
          operator_delete((this->objects).value);
          (this->objects).value = piVar1;
          (this->objects).maximumSizeValue = iVar5 + 1;
        }
      }
      this_00 = RGE_Game_World::object(this->player->world,(this->objects).value[iVar5]);
      if ((this_00 != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this_00), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentTargetType(pUVar3);
        if (iVar4 == param_1) {
          local_4 = local_4 + 1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->objects).numberValue);
  }
  return local_4;
}

// --------------------------------------------------

// Function: numberObjectsWithActionAndTargetType
// Address: 0040d660
int __thiscall
MainDecisionAIModule::numberObjectsWithActionAndTargetType
          (MainDecisionAIModule *this,int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  int count;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  if (0 < (this->objects).numberValue) {
    do {
      if ((this->objects).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->objects).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->objects).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->objects).maximumSizeValue);
          }
          operator_delete((this->objects).value);
          (this->objects).value = piVar1;
          (this->objects).maximumSizeValue = iVar5 + 1;
        }
      }
      this_00 = RGE_Game_World::object(this->player->world,(this->objects).value[iVar5]);
      if ((this_00 != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this_00), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 == param_1) {
          pUVar3 = RGE_Static_Object::unitAI(this_00);
          iVar4 = UnitAIModule::currentTargetType(pUVar3);
          if (iVar4 == param_2) {
            local_4 = local_4 + 1;
          }
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->objects).numberValue);
  }
  return local_4;
}

// --------------------------------------------------

// Function: object
// Address: 0040d760
RGE_Static_Object * __thiscall MainDecisionAIModule::object(MainDecisionAIModule *this,int param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = RGE_Game_World::object(this->player->world,param_1);
  return pRVar1;
}

// --------------------------------------------------

// Function: object
// Address: 0040d780
RGE_Static_Object * __thiscall
MainDecisionAIModule::object
          (MainDecisionAIModule *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6,int param_7,int param_8,int param_9,int param_10)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int i;
  int local_4;
  
  local_4 = 0;
  if ((this->objects).numberValue < 1) {
    return (RGE_Static_Object *)0x0;
  }
  do {
    if ((this->objects).maximumSizeValue + -1 < local_4) {
      piVar1 = (int *)operator_new(local_4 * 4 + 4);
      if (piVar1 != (int *)0x0) {
        iVar4 = 0;
        if (0 < (this->objects).maximumSizeValue) {
          do {
            if (local_4 + 1 <= iVar4) break;
            iVar2 = iVar4 + 1;
            piVar1[iVar4] = (this->objects).value[iVar4];
            iVar4 = iVar2;
          } while (iVar2 < (this->objects).maximumSizeValue);
        }
        operator_delete((this->objects).value);
        (this->objects).value = piVar1;
        (this->objects).maximumSizeValue = local_4 + 1;
      }
    }
    this_00 = RGE_Game_World::object(this->player->world,(this->objects).value[local_4]);
    if ((((this_00 != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this_00), pUVar3 != (UnitAIModule *)0x0)) &&
        ((param_1 == -1 || (this_00->id == param_1)))) &&
       (((param_2 == -1 || (this_00->master_obj->id == param_2)) &&
        ((param_3 == -1 || (this_00->master_obj->object_group == param_3)))))) {
      if (param_4 != -1) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 != param_4) goto LAB_0040d98d;
      }
      if (param_5 != -1) {
        if ((this->objects).maximumSizeValue + -1 < local_4) {
          piVar1 = (int *)operator_new(local_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (this->objects).maximumSizeValue) {
              do {
                if (local_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (this->objects).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (this->objects).maximumSizeValue);
            }
            operator_delete((this->objects).value);
            (this->objects).value = piVar1;
            (this->objects).maximumSizeValue = local_4 + 1;
          }
        }
        iVar4 = (**(code **)(this->_padding_ + 0x4c))((this->objects).value[local_4],param_5);
        if (iVar4 == 0) goto LAB_0040d98d;
      }
      if (param_6 != -1) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentTarget(pUVar3);
        if (iVar4 != param_6) goto LAB_0040d98d;
      }
      if (param_7 != -1) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentTargetType(pUVar3);
        if (iVar4 != param_7) goto LAB_0040d98d;
      }
      if (((param_9 == -1) || ((uint)this_00->object_state == param_9)) &&
         ((param_10 == -1 || (this_00->attribute_amount_held <= (float)param_10)))) {
        return this_00;
      }
    }
LAB_0040d98d:
    local_4 = local_4 + 1;
    if ((this->objects).numberValue <= local_4) {
      return (RGE_Static_Object *)0x0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: object
// Address: 0040d9d0
RGE_Static_Object * __thiscall
MainDecisionAIModule::object
          (MainDecisionAIModule *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if ((this->objects).numberValue < 1) {
    return (RGE_Static_Object *)0x0;
  }
  do {
    if ((this->objects).maximumSizeValue + -1 < iVar5) {
      piVar1 = (int *)operator_new(iVar5 * 4 + 4);
      if (piVar1 != (int *)0x0) {
        iVar4 = 0;
        if (0 < (this->objects).maximumSizeValue) {
          do {
            if (iVar5 + 1 <= iVar4) break;
            iVar2 = iVar4 + 1;
            piVar1[iVar4] = (this->objects).value[iVar4];
            iVar4 = iVar2;
          } while (iVar2 < (this->objects).maximumSizeValue);
        }
        operator_delete((this->objects).value);
        (this->objects).value = piVar1;
        (this->objects).maximumSizeValue = iVar5 + 1;
      }
    }
    this_00 = RGE_Game_World::object(this->player->world,(this->objects).value[iVar5]);
    if (this_00 != (RGE_Static_Object *)0x0) {
      pUVar3 = RGE_Static_Object::unitAI(this_00);
      if ((((pUVar3 != (UnitAIModule *)0x0) && ((param_1 == -1 || (this_00->id == param_1)))) &&
          ((param_2 == -1 || (this_00->master_obj->id == param_2)))) &&
         ((param_3 == -1 || (this_00->master_obj->object_group == param_3)))) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 != param_4) {
          pUVar3 = RGE_Static_Object::unitAI(this_00);
          iVar4 = UnitAIModule::currentAction(pUVar3);
          if ((iVar4 != param_5) && ((param_6 == -1 || ((uint)this_00->object_state == param_6)))) {
            return this_00;
          }
        }
      }
    }
    iVar5 = iVar5 + 1;
    if ((this->objects).numberValue <= iVar5) {
      return (RGE_Static_Object *)0x0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: objectGroupThatCanPerformAction
// Address: 0040db20
// [HELPER] s_ERROR____d_is_an_unrecognized_ac: "ERROR!  %d is an unrecognized action id."
int __thiscall
MainDecisionAIModule::objectGroupThatCanPerformAction(MainDecisionAIModule *this,int param_1)
{
  AIModule::logCommonHistory
            ((AIModule *)this,(char *)this,s_ERROR____d_is_an_unrecognized_ac,param_1);
  return -1;
}

// --------------------------------------------------

// Function: canPerformAction
// Address: 0040db40
int __thiscall
MainDecisionAIModule::canPerformAction(MainDecisionAIModule *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: numberBusyObjects
// Address: 0040db50
int __thiscall MainDecisionAIModule::numberBusyObjects(MainDecisionAIModule *this)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  int count;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  if (0 < (this->objects).numberValue) {
    do {
      if ((this->objects).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->objects).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->objects).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->objects).maximumSizeValue);
          }
          operator_delete((this->objects).value);
          (this->objects).value = piVar1;
          (this->objects).maximumSizeValue = iVar5 + 1;
        }
      }
      this_00 = RGE_Game_World::object(this->player->world,(this->objects).value[iVar5]);
      if ((this_00 != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this_00), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this_00);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 == -1) {
          local_4 = local_4 + 1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->objects).numberValue);
  }
  return local_4;
}

// --------------------------------------------------

// Function: mostDamaged
// Address: 0040dc30
RGE_Static_Object * __thiscall
MainDecisionAIModule::mostDamaged(MainDecisionAIModule *this,int param_1,int param_2)
{
  short sVar1;
  int *piVar2;
  int iVar3;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  int iVar7;
  int damagePercentage;
  RGE_Static_Object *mDB;
  RGE_Static_Object *local_8;
  
  iVar7 = 0;
  local_8 = (RGE_Static_Object *)0x0;
  mDB = (RGE_Static_Object *)0x0;
  if (0 < (this->objects).numberValue) {
    do {
      if ((this->objects).maximumSizeValue + -1 < iVar7) {
        piVar2 = (int *)operator_new(iVar7 * 4 + 4);
        if (piVar2 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (this->objects).maximumSizeValue) {
            do {
              if (iVar7 + 1 <= iVar5) break;
              iVar3 = iVar5 + 1;
              piVar2[iVar5] = (this->objects).value[iVar5];
              iVar5 = iVar3;
            } while (iVar3 < (this->objects).maximumSizeValue);
          }
          operator_delete((this->objects).value);
          (this->objects).value = piVar2;
          (this->objects).maximumSizeValue = iVar7 + 1;
        }
      }
      this_00 = RGE_Game_World::object(this->player->world,(this->objects).value[iVar7]);
      if (((((this_00 != (RGE_Static_Object *)0x0) &&
            (pUVar4 = RGE_Static_Object::unitAI(this_00), pUVar4 != (UnitAIModule *)0x0)) &&
           (this_00->object_state != '\0')) &&
          ((this_00->master_obj->object_group == param_1 &&
           (this_00->hp < (float)(int)this_00->master_obj->hp)))) &&
         ((iVar5 = (**(code **)(this_00->_padding_ + 0x90))(), iVar5 == 1 &&
          ((param_2 == -1 || (param_2 == this_00->master_obj->id)))))) {
        sVar1 = this_00->master_obj->hp;
        iVar5 = __ftol();
        pRVar6 = (RGE_Static_Object *)((iVar5 * 100) / (int)sVar1);
        if ((int)mDB < (int)pRVar6) {
          mDB = pRVar6;
          local_8 = this_00;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (this->objects).numberValue);
  }
  return local_8;
}

// --------------------------------------------------

