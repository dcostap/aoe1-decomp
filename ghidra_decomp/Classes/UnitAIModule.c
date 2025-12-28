// Class: UnitAIModule
// Size:  0x134
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] save
// [02] load
// [03] owner
// [04] order
// [05] notify
// [06] notifyCommander
// [07] notifyCommander
// [08] search
// [09] importantWhenDead
// [10] retryableOrder
// [11] actionRequiresLiveTarget
// [12] bestUnitToAttack
// [13] mostDangerousEnemy
// [14] weakestEnemy
// [15] closestAttacker
// [16] closestObject
// [17] closestResourceObject
// [18] closestUndiscoveredTile
// [19] logDebug
// [20] canAttackUnit
// [21] canAttackUnitAtNeutrality
// [22] stopObject
// [23] attackObject
// [24] attackRoundupObject
// [25] huntObject
// [26] gatherObject
// [27] convertObject
// [28] healObject
// [29] repairObject
// [30] buildObject
// [31] tradeWithObject
// [32] explore
// [33] enterObject
// [34] unload
// [35] transportObject
// [36] moveTo
// [37] moveTo
// [38] moveTo
// [39] evasiveMoveTo
// [40] intelligentEvasiveMoveTo
// [41] runAwayFromAttackers
// [42] followObject
// [43] defendObject
// [44] defendPosition
// [45] seekAndDestroy
// [46] exploreAndDestroy
// [47] importantObject
// [48] convertToLOSResourceType
// [49] canConvert
// [50] processOrder
// [51] processNotify
// [52] processGroupNotify
// [53] processIdle
// [54] processMisc
// [55] processRetryableOrder
//
// Member Layout:
// [0x004] RGE_Static_Object * objectValue
// [0x008] int moodValue
// [0x00C] int objectCategoryValue
// [0x010] int orderQueueSizeValue
// [0x014] int orderQueueMaxSizeValue
// [0x018] OrderEvent * orderQueueValue
// [0x01C] int notifyQueueSizeValue
// [0x020] int notifyQueueMaxSizeValue
// [0x024] NotifyEvent * notifyQueueValue
// [0x028] int currentOrderValue
// [0x02C] int currentOrderPriorityValue
// [0x030] int currentActionValue
// [0x034] int currentTargetValue
// [0x038] int currentTargetTypeValue
// [0x03C] float currentTargetXValue
// [0x040] float currentTargetYValue
// [0x044] float currentTargetZValue
// [0x048] float desiredTargetDistanceValue
// [0x04C] int defendTargetValue
// [0x050] int lastOrderValue
// [0x054] int lastActionValue
// [0x058] int lastTargetValue
// [0x05C] int lastTargetTypeValue
// [0x060] ManagedArray<int> attackingUnitsValue (sz: 0x10)
// [0x070] Waypoint[8] waypointQueue (sz: 0x80)
// [0x0F0] int waypointQueueSizeValue
// [0x0F4] ulong lastUpdateTimeValue
// [0x0F8] ulong idleTimerValue
// [0x0FC] ulong adjustedIdleTimeoutValue
// [0x100] ulong idleTimeoutValue
// [0x104] ulong secondaryTimerValue
// [0x108] ulong lookAroundTimerValue
// [0x10C] ulong lookAroundTimeoutValue
// [0x110] Waypoint lastWorldPositionValue (sz: 0x10)
// [0x120] float defenseBufferValue
// [0x124] int * importantObjects
// [0x128] int numberImportantObjects
// [0x12C] AIPlayStatus * playStatus
// [0x130] uchar stopAfterTargetKilledValue
// ----------------------------------------------------------------

// Function: UnitAIModule
// Address: 00412f00
/* public: __thiscall UnitAIModule::UnitAIModule(class RGE_Static_Object *,int) */

UnitAIModule * __thiscall
UnitAIModule::UnitAIModule(UnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  int *piVar1;
  OrderEvent *pOVar2;
  NotifyEvent *pNVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c88b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->objectValue = param_1;
  this->moodValue = -1;
  this->objectCategoryValue = -1;
  this->orderQueueSizeValue = 0;
  this->orderQueueMaxSizeValue = param_2;
  this->notifyQueueSizeValue = 0;
  this->notifyQueueMaxSizeValue = param_2;
  this->currentOrderValue = -1;
  this->currentOrderPriorityValue = -1;
  this->currentActionValue = -1;
  this->currentTargetValue = -1;
  this->currentTargetTypeValue = -1;
  this->currentTargetXValue = -1.0;
  this->currentTargetYValue = -1.0;
  this->currentTargetZValue = -1.0;
  this->desiredTargetDistanceValue = 2.0;
  this->defendTargetValue = -1;
  this->lastOrderValue = -1;
  this->lastActionValue = -1;
  this->lastTargetValue = -1;
  this->lastTargetTypeValue = -1;
  (this->attackingUnitsValue).value = (int *)0x0;
  (this->attackingUnitsValue).numberValue = 0;
  (this->attackingUnitsValue).desiredNumberValue = 0;
  (this->attackingUnitsValue).maximumSizeValue = 10;
  piVar1 = (int *)operator_new(0x28);
  (this->attackingUnitsValue).value = piVar1;
  local_4 = 0;
  this->waypointQueueSizeValue = 0;
  this->lastUpdateTimeValue = 0;
  this->idleTimerValue = 0;
  this->idleTimeoutValue = 3000;
  this->secondaryTimerValue = 0;
  this->lookAroundTimerValue = 0;
  this->lookAroundTimeoutValue = 1000;
  this->defenseBufferValue = 1.0;
  this->importantObjects = (int *)0x0;
  this->numberImportantObjects = 0;
  this->playStatus = (AIPlayStatus *)0x0;
  this->stopAfterTargetKilledValue = '\0';
  this->_padding_ = (int)&_vftable_;
  if (param_1 != (RGE_Static_Object *)0x0) {
    this->objectCategoryValue = (int)param_1->master_obj->object_group;
    this->defenseBufferValue = param_1->master_obj->los;
  }
  pOVar2 = (OrderEvent *)operator_new(this->orderQueueMaxSizeValue * 0x24);
  this->orderQueueValue = pOVar2;
  pNVar3 = (NotifyEvent *)operator_new(this->notifyQueueMaxSizeValue * 0x18);
  this->notifyQueueValue = pNVar3;
  (this->lastWorldPositionValue).x = -1.0;
  (this->lastWorldPositionValue).y = -1.0;
  (this->lastWorldPositionValue).z = -1.0;
  setAdjustedIdleTimeout(this);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00413070
/* public: virtual void * __thiscall UnitAIModule::`scalar deleting destructor'(unsigned int) */

void * __thiscall UnitAIModule::_scalar_deleting_destructor_(UnitAIModule *this,uint param_1)
{
  ~UnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~UnitAIModule
// Address: 00413090
/* public: virtual __thiscall UnitAIModule::~UnitAIModule(void) */

void __thiscall UnitAIModule::~UnitAIModule(UnitAIModule *this)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055c8ab;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->orderQueueValue != (OrderEvent *)0x0) {
    operator_delete(this->orderQueueValue);
    this->orderQueueValue = (OrderEvent *)0x0;
  }
  if (this->notifyQueueValue != (NotifyEvent *)0x0) {
    operator_delete(this->notifyQueueValue);
    this->notifyQueueValue = (NotifyEvent *)0x0;
  }
  if (this->importantObjects != (int *)0x0) {
    operator_delete(this->importantObjects);
    this->importantObjects = (int *)0x0;
  }
  if (this->playStatus != (AIPlayStatus *)0x0) {
    operator_delete(this->playStatus);
    this->playStatus = (AIPlayStatus *)0x0;
  }
  piVar1 = (this->attackingUnitsValue).value;
  local_4 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->attackingUnitsValue).value = (int *)0x0;
  }
  (this->attackingUnitsValue).numberValue = 0;
  (this->attackingUnitsValue).desiredNumberValue = 0;
  (this->attackingUnitsValue).maximumSizeValue = 0;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00413150
/* public: virtual void __thiscall UnitAIModule::save(int) */

void __thiscall UnitAIModule::save(UnitAIModule *this,int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = param_1;
  rge_write(param_1,&this->moodValue,4);
  rge_write(iVar1,&this->currentOrderValue,4);
  rge_write(iVar1,&this->currentOrderPriorityValue,4);
  rge_write(iVar1,&this->currentActionValue,4);
  rge_write(iVar1,&this->currentTargetValue,4);
  rge_write(iVar1,&this->currentTargetTypeValue,4);
  rge_write(iVar1,&this->currentTargetXValue,4);
  rge_write(iVar1,&this->currentTargetYValue,4);
  rge_write(iVar1,&this->currentTargetZValue,4);
  rge_write(iVar1,&this->desiredTargetDistanceValue,4);
  rge_write(iVar1,&this->lastActionValue,4);
  rge_write(iVar1,&this->lastOrderValue,4);
  rge_write(iVar1,&this->lastTargetValue,4);
  rge_write(iVar1,&this->lastTargetTypeValue,4);
  rge_write(iVar1,&this->lastUpdateTimeValue,4);
  rge_write(iVar1,&this->idleTimerValue,4);
  rge_write(iVar1,&this->idleTimeoutValue,4);
  rge_write(iVar1,&this->adjustedIdleTimeoutValue,4);
  rge_write(iVar1,&this->secondaryTimerValue,4);
  rge_write(iVar1,&this->lookAroundTimerValue,4);
  rge_write(iVar1,&this->lookAroundTimeoutValue,4);
  rge_write(iVar1,&this->defendTargetValue,4);
  rge_write(iVar1,&this->defenseBufferValue,4);
  rge_write(iVar1,&this->lastWorldPositionValue,0x10);
  rge_write(iVar1,&this->orderQueueSizeValue,4);
  iVar4 = 0;
  if (0 < this->orderQueueSizeValue) {
    iVar5 = 0;
    do {
      rge_write(iVar1,(void *)((int)&this->orderQueueValue->issuer + iVar5),0x24);
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x24;
    } while (iVar4 < this->orderQueueSizeValue);
  }
  rge_write(iVar1,&this->notifyQueueSizeValue,4);
  iVar4 = 0;
  if (0 < this->notifyQueueSizeValue) {
    iVar5 = 0;
    do {
      rge_write(iVar1,(void *)((int)&this->notifyQueueValue->caller + iVar5),0x18);
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x18;
    } while (iVar4 < this->notifyQueueSizeValue);
  }
  param_1 = (this->attackingUnitsValue).numberValue;
  rge_write(iVar1,&param_1,4);
  iVar4 = 0;
  if (0 < (this->attackingUnitsValue).numberValue) {
    do {
      if ((this->attackingUnitsValue).maximumSizeValue + -1 < iVar4) {
        piVar2 = (int *)operator_new(iVar4 * 4 + 4);
        if (piVar2 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (this->attackingUnitsValue).maximumSizeValue) {
            do {
              if (iVar4 + 1 <= iVar5) break;
              iVar3 = iVar5 + 1;
              piVar2[iVar5] = (this->attackingUnitsValue).value[iVar5];
              iVar5 = iVar3;
            } while (iVar3 < (this->attackingUnitsValue).maximumSizeValue);
          }
          operator_delete((this->attackingUnitsValue).value);
          (this->attackingUnitsValue).value = piVar2;
          (this->attackingUnitsValue).maximumSizeValue = iVar4 + 1;
        }
      }
      param_1 = (this->attackingUnitsValue).value[iVar4];
      rge_write(iVar1,&param_1,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->attackingUnitsValue).numberValue);
  }
  if (this->playStatus == (AIPlayStatus *)0x0) {
    param_1 = 0;
    rge_write(iVar1,&param_1,4);
  }
  else {
    param_1 = 1;
    rge_write(iVar1,&param_1,4);
    AIPlayStatus::save(this->playStatus,iVar1);
  }
  rge_write(iVar1,&this->stopAfterTargetKilledValue,1);
  return;
}

// --------------------------------------------------

// Function: load
// Address: 00413450
/* WARNING: Variable defined which should be unmapped: numberNotifies */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall UnitAIModule::load(int) */

void __thiscall UnitAIModule::load(UnitAIModule *this,int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  AIPlayStatus *this_00;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  int numberNotifies;
  int i;
  int numberUnits;
  int tempInt_ffffffc0;
  int local_3c;
  int tempInt;
  NotifyEvent tempNotify;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c8cb;
  *unaff_FS_OFFSET = &local_c;
  rge_read(param_1,&this->moodValue,4);
  rge_read(iVar1,&this->currentOrderValue,4);
  rge_read(iVar1,&this->currentOrderPriorityValue,4);
  rge_read(iVar1,&this->currentActionValue,4);
  rge_read(iVar1,&this->currentTargetValue,4);
  rge_read(iVar1,&this->currentTargetTypeValue,4);
  rge_read(iVar1,&this->currentTargetXValue,4);
  rge_read(iVar1,&this->currentTargetYValue,4);
  rge_read(iVar1,&this->currentTargetZValue,4);
  rge_read(iVar1,&this->desiredTargetDistanceValue,4);
  rge_read(iVar1,&this->lastActionValue,4);
  rge_read(iVar1,&this->lastOrderValue,4);
  rge_read(iVar1,&this->lastTargetValue,4);
  rge_read(iVar1,&this->lastTargetTypeValue,4);
  rge_read(iVar1,&this->lastUpdateTimeValue,4);
  rge_read(iVar1,&this->idleTimerValue,4);
  rge_read(iVar1,&this->idleTimeoutValue,4);
  rge_read(iVar1,&this->adjustedIdleTimeoutValue,4);
  rge_read(iVar1,&this->secondaryTimerValue,4);
  if (save_game_version < _DAT_0056ebb8) {
    this->lookAroundTimerValue = 0;
    this->lookAroundTimeoutValue = 1000;
  }
  else {
    rge_read(iVar1,&this->lookAroundTimerValue,4);
    rge_read(iVar1,&this->lookAroundTimeoutValue,4);
  }
  rge_read(iVar1,&this->defendTargetValue,4);
  rge_read(iVar1,&this->defenseBufferValue,4);
  rge_read(iVar1,&this->lastWorldPositionValue,0x10);
  rge_read(iVar1,&param_1,4);
  iVar5 = 0;
  if (0 < param_1) {
    do {
      rge_read(iVar1,&tempNotify.recipient,0x24);
      addToOrderQueue(this,(OrderEvent *)&tempNotify.recipient,0);
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_1);
  }
  rge_read(iVar1,&i,4);
  iVar5 = 0;
  if (0 < i) {
    do {
      rge_read(iVar1,&tempNotify.recipient,0x18);
      addToNotifyQueue(this,(NotifyEvent *)&tempNotify.recipient);
      iVar5 = iVar5 + 1;
    } while (iVar5 < i);
  }
  rge_read(iVar1,&tempInt_ffffffc0,4);
  numberUnits = 0;
  if (0 < tempInt_ffffffc0) {
    do {
      rge_read(iVar1,&local_3c,4);
      iVar5 = (this->attackingUnitsValue).numberValue;
      iVar2 = 0;
      tempInt = local_3c;
      if (0 < iVar5) {
        do {
          if ((this->attackingUnitsValue).maximumSizeValue <= iVar2) break;
          if ((this->attackingUnitsValue).value[iVar2] == local_3c) goto LAB_0041375f;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar5);
      }
      if ((this->attackingUnitsValue).maximumSizeValue + -1 < iVar5) {
        iVar5 = iVar5 + 1;
        piVar3 = (int *)operator_new(iVar5 * 4);
        if (piVar3 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (this->attackingUnitsValue).maximumSizeValue) {
            do {
              if (iVar5 <= iVar2) break;
              iVar4 = iVar2 + 1;
              piVar3[iVar2] = (this->attackingUnitsValue).value[iVar2];
              iVar2 = iVar4;
            } while (iVar4 < (this->attackingUnitsValue).maximumSizeValue);
          }
          operator_delete((this->attackingUnitsValue).value);
          (this->attackingUnitsValue).value = piVar3;
          (this->attackingUnitsValue).maximumSizeValue = iVar5;
        }
      }
      (this->attackingUnitsValue).value[(this->attackingUnitsValue).numberValue] = tempInt;
      (this->attackingUnitsValue).numberValue = (this->attackingUnitsValue).numberValue + 1;
LAB_0041375f:
      numberUnits = numberUnits + 1;
    } while (numberUnits < tempInt_ffffffc0);
  }
  rge_read(iVar1,&tempNotify,4);
  if (tempNotify.caller == 1) {
    tempInt = (int)operator_new(0x1c8);
    local_4 = 0;
    if ((AIPlayStatus *)tempInt == (AIPlayStatus *)0x0) {
      this_00 = (AIPlayStatus *)0x0;
    }
    else {
      this_00 = (AIPlayStatus *)AIPlayStatus::AIPlayStatus((AIPlayStatus *)tempInt);
    }
    local_4 = 0xffffffff;
    this->playStatus = this_00;
    AIPlayStatus::load(this_00,iVar1);
  }
  if (_DAT_0056ebbc <= save_game_version) {
    rge_read(iVar1,&this->stopAfterTargetKilledValue,1);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: owner
// Address: 00413810
/* public: virtual class RGE_Player * __thiscall UnitAIModule::owner(void)const  */

RGE_Player * __thiscall UnitAIModule::owner(UnitAIModule *this)
{
  return this->objectValue->owner;
}

// --------------------------------------------------

// Function: object
// Address: 00413820
/* public: class RGE_Static_Object * __thiscall UnitAIModule::object(void)const  */

RGE_Static_Object * __thiscall UnitAIModule::object(UnitAIModule *this)
{
  return this->objectValue;
}

// --------------------------------------------------

// Function: objectID
// Address: 00413830
/* public: int __thiscall UnitAIModule::objectID(void)const  */

int __thiscall UnitAIModule::objectID(UnitAIModule *this)
{
  return this->objectValue->id;
}

// --------------------------------------------------

// Function: objectCategory
// Address: 00413840
/* public: int __thiscall UnitAIModule::objectCategory(void)const  */

int __thiscall UnitAIModule::objectCategory(UnitAIModule *this)
{
  return this->objectCategoryValue;
}

// --------------------------------------------------

// Function: mood
// Address: 00413850
/* public: int __thiscall UnitAIModule::mood(void)const  */

int __thiscall UnitAIModule::mood(UnitAIModule *this)
{
  return this->moodValue;
}

// --------------------------------------------------

// Function: lastUpdateTime
// Address: 00413860
/* public: unsigned long __thiscall UnitAIModule::lastUpdateTime(void)const  */

ulong __thiscall UnitAIModule::lastUpdateTime(UnitAIModule *this)
{
  return this->lastUpdateTimeValue;
}

// --------------------------------------------------

// Function: idleTimer
// Address: 00413870
/* public: unsigned long __thiscall UnitAIModule::idleTimer(void)const  */

ulong __thiscall UnitAIModule::idleTimer(UnitAIModule *this)
{
  return this->idleTimerValue;
}

// --------------------------------------------------

// Function: idleTimeout
// Address: 00413880
/* public: unsigned long __thiscall UnitAIModule::idleTimeout(void)const  */

ulong __thiscall UnitAIModule::idleTimeout(UnitAIModule *this)
{
  return this->idleTimeoutValue;
}

// --------------------------------------------------

// Function: secondaryTimer
// Address: 00413890
/* public: unsigned long __thiscall UnitAIModule::secondaryTimer(void)const  */

ulong __thiscall UnitAIModule::secondaryTimer(UnitAIModule *this)
{
  return this->secondaryTimerValue;
}

// --------------------------------------------------

// Function: defenseBuffer
// Address: 004138a0
/* public: float __thiscall UnitAIModule::defenseBuffer(void)const  */

float __thiscall UnitAIModule::defenseBuffer(UnitAIModule *this)
{
  return this->defenseBufferValue;
}

// --------------------------------------------------

// Function: canConvert
// Address: 004138b0
/* public: virtual int __thiscall UnitAIModule::canConvert(int) */

int __thiscall UnitAIModule::canConvert(UnitAIModule *this,int param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: setDefenseBuffer
// Address: 004138c0
/* public: void __thiscall UnitAIModule::setDefenseBuffer(float) */

void __thiscall UnitAIModule::setDefenseBuffer(UnitAIModule *this,float param_1)
{
  this->defenseBufferValue = param_1;
  return;
}

// --------------------------------------------------

// Function: orderQueueSize
// Address: 004138d0
/* public: int __thiscall UnitAIModule::orderQueueSize(void)const  */

int __thiscall UnitAIModule::orderQueueSize(UnitAIModule *this)
{
  return this->orderQueueSizeValue;
}

// --------------------------------------------------

// Function: orderQueueElement
// Address: 004138e0
/* public: struct OrderEvent * __thiscall UnitAIModule::orderQueueElement(int)const  */

OrderEvent * __thiscall UnitAIModule::orderQueueElement(UnitAIModule *this,int param_1)
{
  if (((-1 < param_1) && (param_1 < this->orderQueueSizeValue)) &&
     (this->orderQueueValue != (OrderEvent *)0x0)) {
    return this->orderQueueValue + param_1;
  }
  return (OrderEvent *)0x0;
}

// --------------------------------------------------

// Function: purgeOrderQueue
// Address: 00413910
/* public: void __thiscall UnitAIModule::purgeOrderQueue(void) */

void __thiscall UnitAIModule::purgeOrderQueue(UnitAIModule *this)
{
  this->orderQueueSizeValue = 0;
  return;
}

// --------------------------------------------------

// Function: currentOrder
// Address: 00413920
/* public: int __thiscall UnitAIModule::currentOrder(void)const  */

int __thiscall UnitAIModule::currentOrder(UnitAIModule *this)
{
  return this->currentOrderValue;
}

// --------------------------------------------------

// Function: setCurrentOrder
// Address: 00413930
/* public: void __thiscall UnitAIModule::setCurrentOrder(int) */

void __thiscall UnitAIModule::setCurrentOrder(UnitAIModule *this,int param_1)
{
  this->lastOrderValue = this->currentOrderValue;
  this->currentOrderValue = param_1;
  return;
}

// --------------------------------------------------

// Function: currentOrderPriority
// Address: 00413940
/* public: int __thiscall UnitAIModule::currentOrderPriority(void)const  */

int __thiscall UnitAIModule::currentOrderPriority(UnitAIModule *this)
{
  return this->currentOrderPriorityValue;
}

// --------------------------------------------------

// Function: setCurrentOrderPriority
// Address: 00413950
/* public: void __thiscall UnitAIModule::setCurrentOrderPriority(int) */

void __thiscall UnitAIModule::setCurrentOrderPriority(UnitAIModule *this,int param_1)
{
  this->currentOrderPriorityValue = param_1;
  return;
}

// --------------------------------------------------

// Function: currentAction
// Address: 00413960
/* public: int __thiscall UnitAIModule::currentAction(void)const  */

int __thiscall UnitAIModule::currentAction(UnitAIModule *this)
{
  return this->currentActionValue;
}

// --------------------------------------------------

// Function: setCurrentAction
// Address: 00413970
/* public: void __thiscall UnitAIModule::setCurrentAction(int) */

void __thiscall UnitAIModule::setCurrentAction(UnitAIModule *this,int param_1)
{
  this->lastActionValue = this->currentActionValue;
  this->currentActionValue = param_1;
  return;
}

// --------------------------------------------------

// Function: currentTarget
// Address: 00413980
/* public: int __thiscall UnitAIModule::currentTarget(void)const  */

int __thiscall UnitAIModule::currentTarget(UnitAIModule *this)
{
  return this->currentTargetValue;
}

// --------------------------------------------------

// Function: currentTargetType
// Address: 00413990
/* public: int __thiscall UnitAIModule::currentTargetType(void)const  */

int __thiscall UnitAIModule::currentTargetType(UnitAIModule *this)
{
  return this->currentTargetTypeValue;
}

// --------------------------------------------------

// Function: currentTargetX
// Address: 004139a0
/* public: float __thiscall UnitAIModule::currentTargetX(void)const  */

float __thiscall UnitAIModule::currentTargetX(UnitAIModule *this)
{
  return this->currentTargetXValue;
}

// --------------------------------------------------

// Function: currentTargetY
// Address: 004139b0
/* public: float __thiscall UnitAIModule::currentTargetY(void)const  */

float __thiscall UnitAIModule::currentTargetY(UnitAIModule *this)
{
  return this->currentTargetYValue;
}

// --------------------------------------------------

// Function: currentTargetZ
// Address: 004139c0
/* public: float __thiscall UnitAIModule::currentTargetZ(void)const  */

float __thiscall UnitAIModule::currentTargetZ(UnitAIModule *this)
{
  return this->currentTargetZValue;
}

// --------------------------------------------------

// Function: lastAction
// Address: 004139d0
/* public: int __thiscall UnitAIModule::lastAction(void)const  */

int __thiscall UnitAIModule::lastAction(UnitAIModule *this)
{
  return this->lastActionValue;
}

// --------------------------------------------------

// Function: lastOrder
// Address: 004139e0
/* public: int __thiscall UnitAIModule::lastOrder(void)const  */

int __thiscall UnitAIModule::lastOrder(UnitAIModule *this)
{
  return this->lastOrderValue;
}

// --------------------------------------------------

// Function: lastTarget
// Address: 004139f0
/* public: int __thiscall UnitAIModule::lastTarget(void)const  */

int __thiscall UnitAIModule::lastTarget(UnitAIModule *this)
{
  return this->lastTargetValue;
}

// --------------------------------------------------

// Function: lastTargetType
// Address: 00413a00
/* public: int __thiscall UnitAIModule::lastTargetType(void)const  */

int __thiscall UnitAIModule::lastTargetType(UnitAIModule *this)
{
  return this->lastTargetTypeValue;
}

// --------------------------------------------------

// Function: desiredTargetDistance
// Address: 00413a10
/* public: float __thiscall UnitAIModule::desiredTargetDistance(void)const  */

float __thiscall UnitAIModule::desiredTargetDistance(UnitAIModule *this)
{
  return this->desiredTargetDistanceValue;
}

// --------------------------------------------------

// Function: attackingUnitID
// Address: 00413a20
/* public: int __thiscall UnitAIModule::attackingUnitID(int) */

int __thiscall UnitAIModule::attackingUnitID(UnitAIModule *this,int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 < 0) || ((this->attackingUnitsValue).numberValue <= param_1)) {
    return -1;
  }
  if ((this->attackingUnitsValue).maximumSizeValue + -1 < param_1) {
    iVar1 = param_1 + 1;
    piVar2 = (int *)operator_new(iVar1 * 4);
    if (piVar2 != (int *)0x0) {
      iVar3 = 0;
      if (0 < (this->attackingUnitsValue).maximumSizeValue) {
        do {
          if (iVar1 <= iVar3) break;
          iVar4 = iVar3 + 1;
          piVar2[iVar3] = (this->attackingUnitsValue).value[iVar3];
          iVar3 = iVar4;
        } while (iVar4 < (this->attackingUnitsValue).maximumSizeValue);
      }
      operator_delete((this->attackingUnitsValue).value);
      (this->attackingUnitsValue).value = piVar2;
      (this->attackingUnitsValue).maximumSizeValue = iVar1;
    }
  }
  return (this->attackingUnitsValue).value[param_1];
}

// --------------------------------------------------

// Function: numberAttackingUnits
// Address: 00413aa0
/* public: int __thiscall UnitAIModule::numberAttackingUnits(void)const  */

int __thiscall UnitAIModule::numberAttackingUnits(UnitAIModule *this)
{
  return (this->attackingUnitsValue).numberValue;
}

// --------------------------------------------------

// Function: update
// Address: 00413ab0
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* WARNING: Variable defined which should be unmapped: haveGameAction */
/* public: int __thiscall UnitAIModule::update(unsigned long) */

int __thiscall UnitAIModule::update(UnitAIModule *this,ulong param_1)
{
  ulong uVar1;
  ulong uVar2;
  code *pcVar3;
  uchar uVar4;
  char cVar5;
  RGE_Static_Object *pRVar6;
  long lVar7;
  int *piVar8;
  UnitAIModule *pUVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  undefined4 uVar15;
  int haveGameAction;
  
  if (2 < this->objectValue->object_state) {
    return 1;
  }
  taskedThisUpdate = 0;
  searchedThisUpdate = 0;
  numberVisibleObjects = 0;
  numberDifferentPlayerObjectsVisible = 0;
  uVar4 = RGE_Action_List::have_action((RGE_Action_List *)this->objectValue[2].unitAIValue);
  if ((uVar4 == '\0') &&
     (cVar5 = (**(code **)(this->objectValue->_padding_ + 0x130))(), cVar5 == '\x01')) {
    (**(code **)(this->objectValue->_padding_ + 300))(0);
  }
  if (this->currentTargetValue != -1) {
    pRVar6 = lookupObject(this,this->currentTargetValue);
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      this->currentTargetValue = -1;
      if (this->currentActionValue == 600) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar7 = -1;
          }
          else {
            lVar7 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar7,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x306);
        }
        (**(code **)(this->_padding_ + 0x58))(1);
        this->idleTimerValue = this->idleTimeoutValue;
      }
    }
    else {
      if ((this->objectValue->object_state == '\x02') && (2 < pRVar6->object_state)) {
        iVar13 = this->_padding_;
        iVar12 = (**(code **)(iVar13 + 0x2c))(this->currentActionValue);
        if (iVar12 == 1) {
          this->stopAfterTargetKilledValue = '\0';
          if (this->currentActionValue == 600) {
            iVar11 = (**(code **)(iVar13 + 0xd4))(0);
            iVar12 = this->currentOrderValue;
            if (iVar11 == 5) {
              if (iVar12 != 0x2d5) {
                fVar14 = (float10)(**(code **)(this->objectValue->_padding_ + 0x10c))(1);
                iVar12 = (**(code **)(iVar13 + 0x90))
                                   (this->currentTargetXValue,this->currentTargetYValue,
                                    this->currentTargetZValue,(float)fVar14);
                if (iVar12 == 0) {
                  removeCurrentTarget(this);
                  if (actionFile != (_iobuf *)0x0) {
                    if (this->objectValue == (RGE_Static_Object *)0x0) {
                      lVar7 = -1;
                      uVar15 = 0x335;
                    }
                    else {
                      lVar7 = this->objectValue->id;
                      uVar15 = 0x335;
                    }
                    goto LAB_00413c86;
                  }
                  goto LAB_00413c9a;
                }
                iVar13 = this->currentOrderValue;
                this->currentOrderValue = -1;
                this->lastOrderValue = iVar13;
                this->currentOrderPriorityValue = -1;
              }
            }
            else if (iVar12 != 0x2d5) {
              this->lastOrderValue = iVar12;
              this->currentOrderValue = -1;
              this->currentOrderPriorityValue = -1;
            }
          }
          else {
            removeCurrentTarget(this);
            if (actionFile != (_iobuf *)0x0) {
              if (this->objectValue == (RGE_Static_Object *)0x0) {
                lVar7 = -1;
              }
              else {
                lVar7 = this->objectValue->id;
              }
              uVar15 = 0x356;
LAB_00413c86:
              fprintf(actionFile,s___d_call_stopObject__s__d_,lVar7,
                      s_C__msdev_work_age1_x1_aiuaimod_c,uVar15);
            }
LAB_00413c9a:
            (**(code **)(iVar13 + 0x58))(1);
          }
        }
      }
      iVar13 = RGE_Player::computerPlayer(this->objectValue->owner);
      if (((iVar13 == 1) && (this->currentOrderPriorityValue != -1)) &&
         (this->currentOrderPriorityValue < 100)) {
        RGE_Static_Object::distance_to_object(this->objectValue,pRVar6);
        iVar13 = __ftol();
        if (99 < iVar13) {
          iVar13 = 99;
        }
        this->currentOrderPriorityValue = iVar13;
      }
    }
  }
  if (((this->attackingUnitsValue).numberValue == 0) &&
     (cVar5 = (**(code **)(this->objectValue->_padding_ + 0xe8))(), cVar5 != '\0')) {
    (**(code **)(this->objectValue->_padding_ + 0xec))(0);
  }
  else {
    iVar13 = 0;
    if (0 < (this->attackingUnitsValue).numberValue) {
      do {
        if ((this->attackingUnitsValue).maximumSizeValue + -1 < iVar13) {
          piVar8 = (int *)operator_new(iVar13 * 4 + 4);
          if (piVar8 != (int *)0x0) {
            iVar12 = 0;
            if (0 < (this->attackingUnitsValue).maximumSizeValue) {
              do {
                if (iVar13 + 1 <= iVar12) break;
                iVar11 = iVar12 + 1;
                piVar8[iVar12] = (this->attackingUnitsValue).value[iVar12];
                iVar12 = iVar11;
              } while (iVar11 < (this->attackingUnitsValue).maximumSizeValue);
            }
            operator_delete((this->attackingUnitsValue).value);
            (this->attackingUnitsValue).value = piVar8;
            (this->attackingUnitsValue).maximumSizeValue = iVar13 + 1;
          }
        }
        pRVar6 = lookupObject(this,(this->attackingUnitsValue).value[iVar13]);
        if (((pRVar6 == (RGE_Static_Object *)0x0) ||
            (pUVar9 = RGE_Static_Object::unitAI(pRVar6), pUVar9 == (UnitAIModule *)0x0)) ||
           (2 < pRVar6->object_state)) {
LAB_00413db5:
          if (iVar13 <= (this->attackingUnitsValue).maximumSizeValue + -1) goto LAB_00413e08;
          iVar12 = iVar13 + 1;
          piVar8 = (int *)operator_new(iVar12 * 4);
          if (piVar8 == (int *)0x0) goto LAB_00413e08;
          iVar11 = 0;
          if ((this->attackingUnitsValue).maximumSizeValue < 1) goto LAB_00413df6;
          goto LAB_00413ddf;
        }
        pUVar9 = RGE_Static_Object::unitAI(pRVar6);
        iVar12 = currentTarget(pUVar9);
        if (iVar12 != this->objectValue->id) goto LAB_00413db5;
        iVar13 = iVar13 + 1;
      } while (iVar13 < (this->attackingUnitsValue).numberValue);
    }
  }
  goto LAB_00413e52;
  while( true ) {
    iVar10 = iVar11 + 1;
    piVar8[iVar11] = (this->attackingUnitsValue).value[iVar11];
    iVar11 = iVar10;
    if ((this->attackingUnitsValue).maximumSizeValue <= iVar10) break;
LAB_00413ddf:
    if (iVar12 <= iVar11) break;
  }
LAB_00413df6:
  operator_delete((this->attackingUnitsValue).value);
  (this->attackingUnitsValue).value = piVar8;
  (this->attackingUnitsValue).maximumSizeValue = iVar12;
LAB_00413e08:
  iVar12 = (this->attackingUnitsValue).maximumSizeValue;
  iVar11 = 0;
  if (0 < iVar12) {
    piVar8 = (this->attackingUnitsValue).value;
    do {
      if (*piVar8 == (this->attackingUnitsValue).value[iVar13]) break;
      iVar11 = iVar11 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar11 < iVar12);
  }
  if (iVar11 < iVar12) {
    if (iVar11 < iVar12 + -1) {
      do {
        piVar8 = (this->attackingUnitsValue).value;
        iVar13 = iVar11 + 1;
        piVar8[iVar11] = piVar8[iVar13];
        iVar11 = iVar13;
      } while (iVar13 < (this->attackingUnitsValue).maximumSizeValue + -1);
    }
    iVar13 = (this->attackingUnitsValue).numberValue + -1;
    (this->attackingUnitsValue).numberValue = iVar13;
    if (iVar13 < 0) {
      (this->attackingUnitsValue).numberValue = 0;
    }
  }
LAB_00413e52:
  pRVar6 = this->objectValue;
  uVar1 = this->idleTimerValue;
  iVar12 = 0;
  (this->lastWorldPositionValue).x = pRVar6->world_x;
  (this->lastWorldPositionValue).y = pRVar6->world_y;
  uVar2 = this->lookAroundTimerValue;
  iVar13 = this->notifyQueueSizeValue;
  (this->lastWorldPositionValue).z = pRVar6->world_z;
  this->idleTimerValue = uVar1 + param_1;
  this->secondaryTimerValue = this->secondaryTimerValue + param_1;
  this->lookAroundTimerValue = uVar2 + param_1;
  if (0 < iVar13) {
    iVar13 = 0;
    pcVar3 = *(code **)(this->_padding_ + 0xcc);
    do {
      iVar11 = (*pcVar3)((int)&this->notifyQueueValue->caller + iVar13,param_1);
      if (iVar11 == 4) {
        purgeNotifyQueue(this,param_1);
        return 0;
      }
      if (iVar11 == 3) break;
      iVar12 = iVar12 + 1;
      iVar13 = iVar13 + 0x18;
    } while (iVar12 < this->notifyQueueSizeValue);
  }
  purgeNotifyQueue(this,param_1);
  if (uVar4 == '\0') {
    switch(this->currentActionValue) {
    case 600:
    case 0x261:
    case 0x262:
    case 0x265:
    case 0x26b:
    case 0x26c:
      this->currentActionValue = -1;
      break;
    default:
      goto switchD_00413f02_caseD_259;
    }
  }
  else {
switchD_00413f02_caseD_259:
  }
  pRVar6 = this->objectValue;
  if (2 < pRVar6->object_state) {
    return 0;
  }
  if (pRVar6->groupCommanderValue == pRVar6->id) {
    updateGroup(this,param_1);
  }
  if ((this->currentActionValue == -1) && (iVar13 = 0, 0 < this->orderQueueSizeValue)) {
    iVar12 = 0;
    pcVar3 = *(code **)(this->_padding_ + 200);
    do {
      iVar11 = (*pcVar3)((int)&this->orderQueueValue->issuer + iVar12,iVar13);
      if (iVar11 == 1) break;
      iVar13 = iVar13 + 1;
      iVar12 = iVar12 + 0x24;
    } while (iVar13 < this->orderQueueSizeValue);
  }
  iVar13 = this->_padding_;
  (**(code **)(iVar13 + 0xd8))();
  if (this->adjustedIdleTimeoutValue < this->idleTimerValue) {
    if (this->currentActionValue == -1) {
      if (this->currentTargetValue == -1) {
        this->idleTimerValue = 0;
        (**(code **)(iVar13 + 0xd4))(1);
        goto LAB_00413fc6;
      }
      goto LAB_00413fb2;
    }
  }
  else {
LAB_00413fb2:
    if ((this->currentActionValue == -1) && (this->currentTargetValue == -1)) goto LAB_00413fc6;
  }
  this->idleTimerValue = 0;
LAB_00413fc6:
  iVar13 = RGE_Player::computerPlayer(this->objectValue->owner);
  if ((iVar13 == 1) && (this->lookAroundTimeoutValue < this->lookAroundTimerValue)) {
    lookAround(this);
  }
  return 1;
}

// --------------------------------------------------

// Function: updateGroup
// Address: 00414040
/* WARNING: Variable defined which should be unmapped: triggerSatisfied */
/* public: void __thiscall UnitAIModule::updateGroup(unsigned long) */

void __thiscall UnitAIModule::updateGroup(UnitAIModule *this,ulong param_1)
{
  code *pcVar1;
  bool bVar2;
  byte bVar3;
  AIPlay *this_00;
  int *piVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  UnitAIModule *pUVar7;
  int iVar8;
  undefined4 uVar9;
  AIPlayPhase *this_01;
  AIPlayPhaseTrigger *pAVar10;
  AIPlayPhaseCommand *pAVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  ManagedArray<int> *pMVar15;
  float fVar16;
  int triggerSatisfied;
  int deadCount;
  AIPlayPhaseTrigger *trigger;
  AIPlay *play;
  float gatherDistance;
  AIPlayPhase *phase;
  RGE_Static_Object *target;
  int i;
  int totalHitPoints [5];
  int groupList [50];
  
  if ((this->playStatus != (AIPlayStatus *)0x0) &&
     (this_00 = AIPlayBook::play(this->objectValue->owner->world->playbook,
                                 this->playStatus->playNumberValue), this_00 != (AIPlay *)0x0)) {
    i = (int)lookupObject(this,this->playStatus->targetValue);
    if ((RGE_Static_Object *)i == (RGE_Static_Object *)0x0) {
      trigger = (AIPlayPhaseTrigger *)(**(code **)(this->_padding_ + 0x30))(1,0,0);
      pRVar6 = this->objectValue;
      iVar13 = 0;
      if (0 < (pRVar6->groupMembers).numberValue) {
        do {
          if (trigger != (AIPlayPhaseTrigger *)0xffffffff) goto LAB_0041419e;
          pMVar15 = &pRVar6->groupMembers;
          if (((pRVar6->groupMembers).maximumSizeValue + -1 < iVar13) &&
             (piVar4 = (int *)operator_new(iVar13 * 4 + 4), piVar4 != (int *)0x0)) {
            iVar8 = 0;
            if (0 < (pRVar6->groupMembers).maximumSizeValue) {
              do {
                if (iVar13 + 1 <= iVar8) break;
                iVar5 = iVar8 + 1;
                piVar4[iVar8] = pMVar15->value[iVar8];
                iVar8 = iVar5;
              } while (iVar5 < (pRVar6->groupMembers).maximumSizeValue);
            }
            operator_delete(pMVar15->value);
            pMVar15->value = piVar4;
            (pRVar6->groupMembers).maximumSizeValue = iVar13 + 1;
          }
          pRVar6 = this->objectValue;
          if (pMVar15->value[iVar13] != pRVar6->id) {
            if ((pRVar6->groupMembers).maximumSizeValue + -1 < iVar13) {
              ManagedArray<int>::resize(&pRVar6->groupMembers,iVar13 + 1);
            }
            pRVar6 = lookupObject(this,(pRVar6->groupMembers).value[iVar13]);
            if ((pRVar6 != (RGE_Static_Object *)0x0) &&
               (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 != (UnitAIModule *)0x0)) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              trigger = (AIPlayPhaseTrigger *)(**(code **)(pUVar7->_padding_ + 0x30))(1,0,0);
            }
          }
          pRVar6 = this->objectValue;
          iVar13 = iVar13 + 1;
        } while (iVar13 < (pRVar6->groupMembers).numberValue);
      }
      if (trigger == (AIPlayPhaseTrigger *)0xffffffff) {
        operator_delete(this->playStatus);
        this->playStatus = (AIPlayStatus *)0x0;
        return;
      }
LAB_0041419e:
      this->playStatus->targetValue = (int)trigger;
      selectNewPlayPhase(this,(uint)this->playStatus->currentPhaseValue,0);
      i = (int)lookupObject(this,(int)trigger);
    }
    bVar3 = this->playStatus->currentPhaseValue;
    if (bVar3 == 0xfd) {
      pRVar6 = this->objectValue;
      totalHitPoints[1] = 0;
      totalHitPoints[2] = 0;
      totalHitPoints[3] = 0;
      totalHitPoints[4] = 0;
      play = (AIPlay *)0x0;
      groupList[0] = 0;
      deadCount = 0;
      if (0 < (pRVar6->groupMembers).numberValue) {
        trigger = (AIPlayPhaseTrigger *)(groupList + 1);
        do {
          if (((pRVar6->groupMembers).maximumSizeValue + -1 < deadCount) &&
             (piVar4 = (int *)operator_new(deadCount * 4 + 4), piVar4 != (int *)0x0)) {
            iVar13 = 0;
            if (0 < (pRVar6->groupMembers).maximumSizeValue) {
              do {
                if (deadCount + 1 <= iVar13) break;
                iVar8 = iVar13 + 1;
                piVar4[iVar13] = (pRVar6->groupMembers).value[iVar13];
                iVar13 = iVar8;
              } while (iVar8 < (pRVar6->groupMembers).maximumSizeValue);
            }
            operator_delete((pRVar6->groupMembers).value);
            (pRVar6->groupMembers).value = piVar4;
            (pRVar6->groupMembers).maximumSizeValue = deadCount + 1;
          }
          pRVar6 = lookupObject(this,(pRVar6->groupMembers).value[deadCount]);
          if (pRVar6 != (RGE_Static_Object *)0x0) {
            *(long *)trigger = pRVar6->id;
            play = (AIPlay *)(play->nameValue + 1);
            trigger = (AIPlayPhaseTrigger *)&trigger->value1Value;
            iVar8 = 0;
            iVar13 = (**(code **)(this->objectValue->_padding_ + 0x1c8))();
            if (0 < iVar13) {
              pcVar1 = *(code **)(pRVar6->_padding_ + 0x1bc);
              do {
                uVar9 = (**(code **)(this->objectValue->_padding_ + 0x1b8))(iVar8,1);
                (*pcVar1)(uVar9);
                iVar8 = iVar8 + 1;
                iVar13 = (**(code **)(this->objectValue->_padding_ + 0x1c8))();
              } while (iVar8 < iVar13);
            }
          }
          pRVar6 = this->objectValue;
          deadCount = deadCount + 1;
        } while (deadCount < (pRVar6->groupMembers).numberValue);
      }
      this->playStatus->lastPhaseChangeTimeValue = this->objectValue->owner->world->world_time;
      AIPlay::fillGroups(this_00,this->playStatus,groupList + 1,(int)play,
                         this->objectValue->owner->world);
      if (0 < (int)play) {
        piVar4 = groupList;
        trigger = (AIPlayPhaseTrigger *)play;
        do {
          piVar4 = piVar4 + 1;
          lookupObject(this,*piVar4);
          bVar3 = AIPlayStatus::group(this->playStatus,*piVar4);
          iVar13 = __ftol();
          trigger = (AIPlayPhaseTrigger *)((int)&trigger[-1].randomnessValue + 3);
          totalHitPoints[bVar3 + 1] = totalHitPoints[bVar3 + 1] + iVar13;
        } while (trigger != (AIPlayPhaseTrigger *)0x0);
      }
      iVar13 = 0;
      piVar4 = totalHitPoints;
      do {
        piVar4 = piVar4 + 1;
        AIPlayStatus::setOriginalHitPoints(this->playStatus,iVar13,*piVar4);
        iVar13 = iVar13 + 1;
      } while (iVar13 < 5);
      selectNewPlayPhase(this,0,0);
      return;
    }
    this_01 = AIPlay::phase(this_00,(uint)bVar3);
    if (this_01 != (AIPlayPhase *)0x0) {
      totalHitPoints[0] = 0;
      do {
        pAVar10 = AIPlayPhase::trigger(this_01,totalHitPoints[0]);
        iVar13 = 0;
        if ((pAVar10 != (AIPlayPhaseTrigger *)0x0) && (pAVar10->typeValue != '\0')) {
          bVar2 = false;
          switch(pAVar10->typeValue) {
          case '\x01':
            bVar2 = true;
            uVar14 = 0;
            do {
              if (!bVar2) break;
              iVar13 = AIPlay::groupGivenCommandOnPhase
                                 (this_00,uVar14,1,(uint)this->playStatus->currentPhaseValue);
              if (iVar13 != -1) {
                pAVar11 = AIPlayPhase::command(this_01,iVar13);
                iVar13 = 0;
                do {
                  if (!bVar2) break;
                  if ((((&this->playStatus->groupings[0].groupID)[iVar13] == uVar14) &&
                      (pRVar6 = lookupObject(this,*(int *)((int)&this->playStatus->groupings[0].id +
                                                          iVar13)),
                      pRVar6 != (RGE_Static_Object *)0x0)) &&
                     (fVar16 = RGE_Static_Object::distance_to_position
                                         (pRVar6,(float)pAVar11->value1Value + *(float *)(i + 0x38),
                                          (float)pAVar11->value2Value + *(float *)(i + 0x3c),
                                          (float)pAVar11->value2Value + *(float *)(i + 0x40)),
                     (float)pAVar10->value1Value < fVar16)) {
                    bVar2 = false;
                  }
                  iVar13 = iVar13 + 8;
                } while (iVar13 < 400);
              }
              uVar14 = uVar14 + 1;
            } while ((int)uVar14 < 5);
            break;
          case '\x02':
            iVar13 = 0;
            iVar8 = 0;
            trigger = (AIPlayPhaseTrigger *)0x0;
            do {
              if ((uint)(&this->playStatus->groupings[0].groupID)[iVar8] == pAVar10->value1Value) {
                iVar13 = iVar13 + 1;
                pRVar6 = lookupObject(this,*(int *)((int)&this->playStatus->groupings[0].id + iVar8)
                                     );
                if ((pRVar6 == (RGE_Static_Object *)0x0) || (2 < pRVar6->object_state)) {
                  trigger = (AIPlayPhaseTrigger *)&trigger->field_0x1;
                }
              }
              iVar8 = iVar8 + 8;
            } while (iVar8 < 400);
            if (iVar13 == 0) goto switchD_00414407_caseD_a;
            if (pAVar10->value2Value <= ((int)trigger * 100) / iVar13) {
              bVar2 = true;
            }
            break;
          case '\x03':
            iVar13 = 0;
            iVar8 = 0;
            do {
              piVar4 = (int *)((int)&this->playStatus->groupings[0].id + iVar8);
              if (((uint)*(byte *)(piVar4 + 1) == pAVar10->value1Value) &&
                 (pRVar6 = lookupObject(this,*piVar4), pRVar6 != (RGE_Static_Object *)0x0)) {
                iVar5 = __ftol();
                iVar13 = iVar13 + iVar5;
              }
              iVar8 = iVar8 + 8;
            } while (iVar8 < 400);
            iVar5 = AIPlayStatus::originalHitPoints(this->playStatus,pAVar10->value1Value);
            iVar8 = pAVar10->value2Value;
            iVar12 = AIPlayStatus::originalHitPoints(this->playStatus,pAVar10->value1Value);
            if (iVar8 <= ((iVar5 - iVar13) * 100) / iVar12) {
              bVar2 = true;
            }
            break;
          case '\b':
            bVar2 = true;
            do {
              if (!bVar2) break;
              if ((((uint)(&this->playStatus->groupings[0].groupID)[iVar13] == pAVar10->value1Value)
                  && (pRVar6 = lookupObject(this,*(int *)((int)&this->playStatus->groupings[0].id +
                                                         iVar13)),
                     pRVar6 != (RGE_Static_Object *)0x0)) && (pRVar6->object_state == '\x02')) {
                bVar2 = false;
              }
              iVar13 = iVar13 + 8;
            } while (iVar13 < 400);
            break;
          case '\t':
            bVar2 = true;
            iVar13 = 0;
            do {
              if (!bVar2) break;
              piVar4 = (int *)((int)&this->playStatus->groupings[0].id + iVar13);
              if ((((uint)*(byte *)(piVar4 + 1) == pAVar10->value1Value) &&
                  (pRVar6 = lookupObject(this,*piVar4), pRVar6 != (RGE_Static_Object *)0x0)) &&
                 (iVar8 = __ftol(), iVar8 < pRVar6->master_obj->hp)) {
                bVar2 = false;
              }
              iVar13 = iVar13 + 8;
            } while (iVar13 < 400);
            break;
          case '\n':
switchD_00414407_caseD_a:
            bVar2 = true;
            break;
          case '\v':
            if (pAVar10->value1Value <
                (int)(this->objectValue->owner->world->world_time -
                     this->playStatus->lastPhaseChangeTimeValue) / 1000)
            goto switchD_00414407_caseD_a;
          }
          if ((bVar2) &&
             (iVar13 = selectNewPlayPhase(this,(uint)pAVar10->nextPhaseValue,0), iVar13 == 1)) {
            return;
          }
        }
        totalHitPoints[0] = totalHitPoints[0] + 1;
      } while (totalHitPoints[0] < 3);
      selectNewPlayPhase(this,(uint)this->playStatus->currentPhaseValue,1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: selectNewPlayPhase
// Address: 00414800
/* WARNING: Variable defined which should be unmapped: a */
/* public: int __thiscall UnitAIModule::selectNewPlayPhase(int,int) */

int __thiscall UnitAIModule::selectNewPlayPhase(UnitAIModule *this,int param_1,int param_2)
{
  uchar uVar1;
  short sVar2;
  AIPlayStatus *pAVar3;
  int iVar4;
  uchar uVar5;
  AIPlay *this_00;
  AIPlayPhase *this_01;
  RGE_Static_Object *pRVar6;
  AIPlayPhaseCommand *pAVar7;
  RGE_Static_Object *pRVar8;
  UnitAIModule *pUVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  RGE_Static_Object *pRVar13;
  int iVar14;
  undefined4 uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  int a;
  int local_44;
  RGE_Static_Object *target;
  int i;
  AIPlayPhase *phase;
  AIPlay *play;
  RGE_Static_Object *member;
  
  if (this->playStatus == (AIPlayStatus *)0x0) {
    return 0;
  }
  this_00 = AIPlayBook::play(this->objectValue->owner->world->playbook,
                             this->playStatus->playNumberValue);
  if (this_00 == (AIPlay *)0x0) {
    return 0;
  }
  if (param_1 == 0xfe) {
    operator_delete(this->playStatus);
    this->playStatus = (AIPlayStatus *)0x0;
    return 1;
  }
  this_01 = AIPlay::phase(this_00,param_1);
  if (this_01 == (AIPlayPhase *)0x0) {
    return 0;
  }
  pRVar6 = lookupObject(this,this->playStatus->targetValue);
  if (pRVar6 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  phase = (AIPlayPhase *)0x0;
  this->playStatus->currentPhaseValue = (uchar)param_1;
  do {
    pAVar7 = AIPlayPhase::command(this_01,(int)phase);
    if ((pAVar7 != (AIPlayPhaseCommand *)0x0) && (uVar1 = pAVar7->typeValue, uVar1 != '\0')) {
      if (((uVar1 == '\x06') || (uVar1 == '\a')) && (param_2 == 0)) {
        if (uVar1 == '\x06') {
          AIPlayStatus::resetHitPoints
                    (this->playStatus,(uint)pAVar7->groupValue,this->objectValue->owner->world);
        }
        else if (uVar1 == '\a') {
          AIPlayStatus::removeDeadUnits
                    (this->playStatus,(uint)pAVar7->groupValue,this->objectValue->owner->world);
        }
      }
      else {
        pRVar8 = this->objectValue;
        local_44 = 0;
        if (0 < (pRVar8->groupMembers).numberValue) {
          do {
            if ((pRVar8->groupMembers).maximumSizeValue + -1 < local_44) {
              ManagedArray<int>::resize(&pRVar8->groupMembers,local_44 + 1);
            }
            pRVar8 = lookupObject(this,(pRVar8->groupMembers).value[local_44]);
            if (((pRVar8 == (RGE_Static_Object *)0x0) ||
                (pUVar9 = RGE_Static_Object::unitAI(pRVar8), pUVar9 == (UnitAIModule *)0x0)) ||
               (uVar1 = pAVar7->groupValue, uVar5 = AIPlayStatus::group(this->playStatus,pRVar8->id)
               , uVar5 != uVar1)) goto switchD_00414a03_caseD_6;
            if (param_2 == 1) {
              pUVar9 = RGE_Static_Object::unitAI(pRVar8);
              iVar10 = currentAction(pUVar9);
              if (iVar10 != -1) goto switchD_00414a03_caseD_6;
            }
            switch(pAVar7->typeValue) {
            case '\x01':
              RGE_Static_Object::distance_to_position
                        (pRVar8,(float)pAVar7->value1Value + pRVar6->world_x,
                         (float)pAVar7->value2Value + pRVar6->world_y,
                         (float)pAVar7->value3Value + pRVar6->world_z);
              iVar10 = __ftol();
              iVar11 = AIPlay::gatherTolerance
                                 (this_00,(uint)pAVar7->groupValue,
                                  (uint)this->playStatus->currentPhaseValue);
              if (iVar11 < iVar10) {
                iVar10 = pAVar7->value1Value;
                iVar11 = pAVar7->value3Value;
                iVar4 = pAVar7->value2Value;
                pUVar9 = RGE_Static_Object::unitAI(pRVar8);
                iVar14 = pUVar9->_padding_;
                fVar18 = (float)iVar11 + pRVar6->world_z;
                fVar17 = (float)iVar4 + pRVar6->world_y;
                fVar16 = (float)iVar10 + pRVar6->world_x;
                iVar10 = -1;
                param_1 = -1;
                uVar15 = 0x2c6;
                break;
              }
              goto switchD_00414a03_caseD_6;
            case '\x02':
              pUVar9 = RGE_Static_Object::unitAI(pRVar8);
              iVar10 = (int)pRVar6->owner->id;
              iVar14 = pUVar9->_padding_;
              fVar18 = -1.0;
              fVar17 = -1.0;
              fVar16 = -1.0;
              param_1 = pRVar6->id;
              uVar15 = 700;
              break;
            case '\x03':
              param_1 = this->playStatus->savedAttackerValue;
              pUVar9 = RGE_Static_Object::unitAI(pRVar8);
              iVar14 = pUVar9->_padding_;
              fVar18 = -1.0;
              fVar17 = -1.0;
              fVar16 = -1.0;
              iVar10 = -1;
              uVar15 = 700;
              break;
            case '\x04':
              pAVar3 = this->playStatus;
              iVar10 = (pAVar3->originalPointValue).zValue;
              iVar11 = (pAVar3->originalPointValue).yValue;
              iVar4 = (pAVar3->originalPointValue).xValue;
              pUVar9 = RGE_Static_Object::unitAI(pRVar8);
              fVar18 = (float)iVar10;
              iVar14 = pUVar9->_padding_;
              fVar17 = (float)iVar11;
              fVar16 = (float)iVar4;
              iVar10 = -1;
              param_1 = -1;
              uVar15 = 0x2c6;
              break;
            case '\x05':
              param_1 = -1;
              target = (RGE_Static_Object *)0x0;
              do {
                piVar12 = (int *)((int)&this->playStatus->groupings[0].id + (int)&target->_padding_)
                ;
                if ((((uint)*(byte *)(piVar12 + 1) == pAVar7->value1Value) &&
                    (pRVar13 = lookupObject(this,*piVar12), pRVar13 != (RGE_Static_Object *)0x0)) &&
                   (sVar2 = pRVar13->master_obj->hp, iVar10 = __ftol(), iVar10 + 1 < (int)sVar2)) {
                  param_1 = pRVar13->id;
                  break;
                }
                target = (RGE_Static_Object *)&target->master_obj;
              } while ((int)target < 400);
              if (param_1 != -1) {
                pUVar9 = RGE_Static_Object::unitAI(pRVar8);
                iVar14 = pUVar9->_padding_;
                fVar18 = -1.0;
                fVar17 = -1.0;
                fVar16 = -1.0;
                iVar10 = -1;
                uVar15 = 0x2bf;
                break;
              }
            default:
              goto switchD_00414a03_caseD_6;
            case '\b':
              iVar10 = pAVar7->value1Value;
              iVar11 = pAVar7->value3Value;
              iVar4 = pAVar7->value2Value;
              pUVar9 = RGE_Static_Object::unitAI(pRVar8);
              iVar14 = pUVar9->_padding_;
              fVar18 = (float)iVar11 + pRVar6->world_z;
              fVar17 = (float)iVar4 + pRVar6->world_y;
              fVar16 = (float)iVar10 + pRVar6->world_x;
              iVar10 = -1;
              param_1 = -1;
              uVar15 = 0x2d8;
            }
            (**(code **)(iVar14 + 0x10))
                      (this->objectValue->id,uVar15,param_1,iVar10,fVar16,fVar17,fVar18,0x3f800000,1
                       ,0,100);
switchD_00414a03_caseD_6:
            pRVar8 = this->objectValue;
            local_44 = local_44 + 1;
          } while (local_44 < (pRVar8->groupMembers).numberValue);
        }
      }
    }
    phase = (AIPlayPhase *)&phase->commands[0].typeValue;
    if (4 < (int)phase) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: order
// Address: 00414d40
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* public: virtual int __thiscall
   UnitAIModule::order(int,int,int,int,float,float,float,float,int,int,int) */

int __thiscall
UnitAIModule::order(UnitAIModule *this,int param_1,int param_2,int param_3,int param_4,float param_5
                   ,float param_6,float param_7,float param_8,int param_9,int param_10,int param_11)
{
  long lVar1;
  
  if (this->objectValue->object_state < 3) {
    if (param_9 == 0) {
      addToOrderQueue(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_10,
                      param_11);
      return 1;
    }
    if (param_10 == 1) {
      addToOrderQueue(this,this->objectValue->id,this->currentOrderValue,this->currentTargetValue,-1
                      ,this->currentTargetXValue,this->currentTargetYValue,this->currentTargetZValue
                      ,this->desiredTargetDistanceValue,1,this->currentOrderPriorityValue);
    }
    addToOrderQueue(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,1,param_11)
    ;
    if (param_2 != 0x2d9) {
      removeCurrentTarget(this);
      if (actionFile != (_iobuf *)0x0) {
        if (this->objectValue == (RGE_Static_Object *)0x0) {
          lVar1 = -1;
        }
        else {
          lVar1 = this->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar1,s_C__msdev_work_age1_x1_aiuaimod_c,
                0x6f3);
      }
      (**(code **)(this->_padding_ + 0x58))(1);
    }
    purgeNotifyQueue(this,0);
    (**(code **)(this->_padding_ + 200))(this->orderQueueValue,0);
  }
  return 1;
}

// --------------------------------------------------

// Function: notify
// Address: 00414e80
/* public: virtual int __thiscall UnitAIModule::notify(int,int,int,long,long,long) */

int __thiscall
UnitAIModule::notify
          (UnitAIModule *this,int param_1,int param_2,int param_3,long param_4,long param_5,
          long param_6)
{
  int iVar1;
  int iVar2;
  
  if (this->objectValue->object_state != '\x02') {
    return 0;
  }
  if (param_3 == 699) {
    iVar2 = (this->attackingUnitsValue).numberValue;
    iVar1 = 0;
    if (0 < iVar2) {
      while (iVar1 < (this->attackingUnitsValue).maximumSizeValue) {
        if ((this->attackingUnitsValue).value[iVar1] == param_1) goto LAB_00414ecf;
        iVar1 = iVar1 + 1;
        if (iVar2 <= iVar1) {
          return 0;
        }
      }
    }
  }
  else {
LAB_00414ecf:
    if ((param_3 != 0x1fb) || (param_4 == this->currentActionValue)) {
      if ((param_3 == 0x1fa) &&
         (((param_4 == 0x262 && (this->currentActionValue != 0x262)) &&
          (this->currentActionValue != 0x268)))) {
        return 1;
      }
      iVar2 = addToNotifyQueue(this,param_1,param_2,param_3,param_4,param_5,param_6);
      return iVar2;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: notifyCommander
// Address: 00414f40
/* public: virtual int __thiscall UnitAIModule::notifyCommander(struct NotifyEvent *) */

int __thiscall UnitAIModule::notifyCommander(UnitAIModule *this,NotifyEvent *param_1)
{
  int iVar1;
  
  iVar1 = (**(code **)(this->_padding_ + 0x18))
                    (param_1->caller,param_1->recipient,param_1->mType,param_1->p1,param_1->p2,
                     param_1->p3);
  return iVar1;
}

// --------------------------------------------------

// Function: notifyCommander
// Address: 00414f70
/* WARNING: Variable defined which should be unmapped: nEvent */
/* public: virtual int __thiscall UnitAIModule::notifyCommander(int,int,int,long,long,long) */

int __thiscall
UnitAIModule::notifyCommander
          (UnitAIModule *this,int param_1,int param_2,int param_3,long param_4,long param_5,
          long param_6)
{
  int iVar1;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar2;
  NotifyEvent nEvent;
  
  iVar1 = RGE_Static_Object::inGroup(this->objectValue);
  if (iVar1 == 1) {
    nEvent.recipient = param_1;
    nEvent.mType = param_2;
    nEvent.p1 = param_3;
    nEvent.p2 = param_4;
    nEvent.p3 = param_5;
    iVar1 = this->objectValue->groupCommanderValue;
    if (this->objectValue->id == iVar1) {
      (**(code **)(this->_padding_ + 0xd0))(&nEvent.recipient);
    }
    else {
      this_00 = lookupObject(this,iVar1);
      if (this_00 != (RGE_Static_Object *)0x0) {
        pUVar2 = RGE_Static_Object::unitAI(this_00);
        if (pUVar2 != (UnitAIModule *)0x0) {
          pUVar2 = RGE_Static_Object::unitAI(this_00);
          (**(code **)(pUVar2->_padding_ + 0xd0))(&nEvent.recipient);
        }
      }
    }
  }
  (**(code **)(this->objectValue->owner->_padding_ + 0xe8))
            (param_1,param_2,param_3,param_4,param_5,param_6);
  return 1;
}

// --------------------------------------------------

// Function: search
// Address: 00415040
/* public: virtual void __thiscall UnitAIModule::search(void) */

void __thiscall UnitAIModule::search(UnitAIModule *this)
{
  RGE_Master_Static_Object *pRVar1;
  RGE_Player *pRVar2;
  RGE_Static_Object *pRVar3;
  UnitAIModule *pUVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  
  if (searchedThisUpdate == 1) {
    return;
  }
  searchedThisUpdate = 1;
  if (this->importantObjects != (int *)0x0) {
    if ((((this->currentOrderValue == 0x2bd) && (this->defendTargetValue != -1)) &&
        (pRVar3 = lookupObject(this,this->defendTargetValue), pRVar3 != (RGE_Static_Object *)0x0))
       && (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 != (UnitAIModule *)0x0)) {
      iVar10 = this->numberImportantObjects;
      piVar9 = this->importantObjects;
      piVar11 = this->objectValue->owner->unitDiplomacy;
      iVar8 = (int)pRVar3->owner->id;
      iVar5 = __ftol();
    }
    else {
      pRVar3 = this->objectValue;
      pRVar1 = pRVar3->master_obj;
      iVar5 = __ftol();
      if (pRVar1->id == 0x76) {
        iVar5 = iVar5 * 2;
      }
      pRVar2 = pRVar3->owner;
      piVar11 = pRVar2->unitDiplomacy;
      iVar8 = (int)pRVar2->id;
      iVar10 = this->numberImportantObjects;
      piVar9 = this->importantObjects;
    }
    iVar6 = __ftol();
    iVar7 = __ftol();
    numberVisibleObjects =
         Visible_Unit_Manager::GetVisibleUnits
                   (VisibleUnitManager,iVar7,iVar6,iVar5,iVar8,piVar9,iVar10,piVar11);
    return;
  }
  searchedThisUpdate = 1;
  return;
}

// --------------------------------------------------

// Function: importantWhenDead
// Address: 00415120
/* public: virtual int __thiscall UnitAIModule::importantWhenDead(int) */

int __thiscall UnitAIModule::importantWhenDead(UnitAIModule *this,int param_1)
{
  if ((((param_1 != 7) && (param_1 != 9)) && (param_1 != 10)) &&
     (((param_1 != 0xf && (param_1 != 8)) && (param_1 != 0x20)))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: retryableOrder
// Address: 00415150
/* public: virtual int __thiscall UnitAIModule::retryableOrder(int) */

int __thiscall UnitAIModule::retryableOrder(UnitAIModule *this,int param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: actionRequiresLiveTarget
// Address: 00415160
/* public: virtual int __thiscall UnitAIModule::actionRequiresLiveTarget(int) */

int __thiscall UnitAIModule::actionRequiresLiveTarget(UnitAIModule *this,int param_1)
{
  if ((((this->stopAfterTargetKilledValue != '\x01') && (param_1 != 600)) && (param_1 != 0x259)) &&
     (((param_1 != 0x25b && (param_1 != 0x25c)) && ((param_1 != 0x26a && (param_1 != 0x264)))))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: bestUnitToAttack
// Address: 004151b0
/* WARNING: Variable defined which should be unmapped: largestThreat */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall UnitAIModule::bestUnitToAttack(int,int,float *) */

int __thiscall
UnitAIModule::bestUnitToAttack(UnitAIModule *this,int param_1,int param_2,float *param_3)
{
  byte bVar1;
  short sVar2;
  int iVar3;
  RGE_Player *pRVar4;
  RGE_Game_World *this_00;
  uchar uVar5;
  int iVar6;
  int iVar7;
  RGE_Static_Object *pRVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  float10 fVar12;
  float10 fVar13;
  float fVar14;
  float largestThreat;
  int numberMovingTargets;
  int numberDamagingUnits;
  int largestThreatIsBuilding;
  int i;
  RGE_Game_World *world;
  int maxReactDistance;
  int modifier;
  int numberNonCurrentTargets;
  int currentTargetIsWall;
  int numberObjectsInRange;
  float closestEnemyDistance;
  float enemyDistance;
  long lStack_4;
  
  iVar3 = this->_padding_;
  (**(code **)(iVar3 + 0x20))();
  iVar6 = RGE_Game_World::difficultyLevel(this->objectValue->owner->world);
  iVar7 = RGE_Base_Game::scenarioGame(rge_base_game);
  if (((((iVar7 == 1) && (iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar7 == 1)) &&
       (2 < iVar6)) && (this->objectValue->owner->id != 1)) ||
     (((iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar7 == 1 && (2 < iVar6)) &&
      ((pRVar4 = this->objectValue->owner, pRVar4->type == '\x03' &&
       ((iVar7 = (**(code **)(pRVar4->_padding_ + 0x3c))(0xdb), iVar7 != 100 ||
        (iVar7 = (**(code **)(this->objectValue->owner->_padding_ + 0x3c))(0xda), iVar7 != 100))))))
     )) {
    pRVar4 = this->objectValue->owner;
    if (1 < pRVar4->id) {
      if (iVar6 == 3) {
        (**(code **)(pRVar4->_padding_ + 0x3c))(0xdb);
      }
      else {
        (**(code **)(pRVar4->_padding_ + 0x3c))(0xda);
      }
    }
    pRVar8 = this->objectValue;
    modifier = __ftol();
    if (modifier < 1) {
      modifier = 1;
    }
  }
  else {
    pRVar8 = this->objectValue;
    iVar6 = __ftol();
    modifier = iVar6 << 1;
  }
  numberNonCurrentTargets = -1;
  this_00 = pRVar8->owner->world;
  numberMovingTargets = 0;
  i = 0;
  numberObjectsInRange = 0;
  if (((this->currentTargetValue != -1) &&
      (pRVar8 = lookupObject(this,this->currentTargetValue), pRVar8 != (RGE_Static_Object *)0x0)) &&
     (pRVar8->master_obj->object_group == 0x1b)) {
    numberObjectsInRange = 1;
  }
  lStack_4 = -1;
  numberDamagingUnits = 0;
  largestThreatIsBuilding = 0;
  currentTargetIsWall = 0;
  enemyDistance = 100000.0;
  closestEnemyDistance = 0.0;
  iVar6 = 4;
  do {
    iVar7 = 0;
    if (0 < (int)(&VisibleUnitList_Size)[iVar6]) {
      do {
        pRVar8 = RGE_Game_World::object(this_00,(int)(&VisibleUnitList)[iVar6][iVar7 * 2]);
        if ((((((pRVar8 != (RGE_Static_Object *)0x0) && (pRVar8->object_state < 3)) &&
              ((iVar9 = (**(code **)(this->objectValue->owner->_padding_ + 0x1c))
                                  ((int)pRVar8->owner->id), iVar9 != 1 &&
               (pRVar8->inside_obj == (RGE_Static_Object *)0x0)))) &&
             (((param_1 != 0 && (numberObjectsInRange != 0)) ||
              (pRVar8->master_obj->object_group != 0x1b)))) &&
            (((pRVar8->master_obj->object_group != 3 || (_DAT_0056ebd0 < pRVar8->hp)) ||
             ((sVar2 = this->objectValue->master_obj->id, sVar2 != 0x23 && (sVar2 != 0x24)))))) &&
           ((iVar9 = (**(code **)(iVar3 + 0x50))(pRVar8), iVar9 != 0 &&
            ((iVar6 != 3 ||
             (iVar9 = (**(code **)(iVar3 + 0x54))((int)pRVar8->master_obj->object_group), iVar9 != 0
             )))))) {
          fVar14 = RGE_Static_Object::distance_to_object(this->objectValue,pRVar8);
          fVar12 = (float10)(**(code **)(this->objectValue->_padding_ + 0x110))();
          if ((fVar12 <= (float10)fVar14) &&
             ((int)(uint)*(byte *)((&VisibleUnitList)[iVar6] + iVar7 * 2 + 1) <= modifier)) {
            if (pRVar8->id != this->currentTargetValue) {
              currentTargetIsWall = currentTargetIsWall + 1;
            }
            if (pRVar8->master_obj->object_group != 3) {
              numberDamagingUnits = numberDamagingUnits + 1;
            }
            fVar12 = (float10)(**(code **)(pRVar8->_padding_ + 0x108))();
            if ((float10)_DAT_0056ebc8 < fVar12) {
              largestThreatIsBuilding = largestThreatIsBuilding + 1;
            }
            if (pRVar8->master_obj->object_group != 3) {
              fVar12 = (float10)(**(code **)(this->objectValue->_padding_ + 0x10c))();
              if ((float10)fVar14 < fVar12 - (float10)_DAT_0056ebd4) {
                closestEnemyDistance = (float)((int)closestEnemyDistance + 1);
              }
              if (fVar14 < enemyDistance) {
                lStack_4 = pRVar8->id;
                enemyDistance = fVar14;
              }
            }
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)(&VisibleUnitList_Size)[iVar6]);
    }
    iVar6 = iVar6 + -1;
  } while (1 < iVar6);
  if ((((this->currentTargetValue != -1) && (param_2 == 0)) && (this->currentActionValue == 600)) &&
     (pRVar8 = lookupObject(this,this->currentTargetValue), pRVar8 != (RGE_Static_Object *)0x0)) {
    iVar6 = __ftol();
    iVar7 = __ftol();
    uVar5 = visibleStatus(this,this->objectValue->owner->visible,iVar7,iVar6);
    if (currentTargetIsWall != 0) {
      if (uVar5 != '\x0f') goto LAB_004156de;
      iVar6 = (**(code **)(this->objectValue->_padding_ + 0xe4))(pRVar8);
      if (iVar6 != 1) {
        iVar6 = this->objectValue->_padding_;
        fVar12 = (float10)(**(code **)(iVar6 + 0x10c))(0,0,0xffffffff,0xffffffff);
        iVar6 = (**(code **)(iVar6 + 0x194))(this->currentTargetValue,(float)fVar12);
        if (iVar6 != 1) goto LAB_004156de;
      }
    }
    pRVar8 = RGE_Game_World::object(this_00,this->currentTargetValue);
    if (((pRVar8 != (RGE_Static_Object *)0x0) && (pRVar8->object_state == '\x02')) &&
       (iVar6 = (**(code **)(this->objectValue->owner->_padding_ + 0x1c))((int)pRVar8->owner->id),
       iVar6 == 0)) {
      if (pRVar8->master_obj->id == 0x114) {
        return pRVar8->id;
      }
      numberNonCurrentTargets = this->currentTargetValue;
      fVar12 = (float10)(**(code **)(pRVar8->_padding_ + 0x108))();
      numberMovingTargets = (int)(float)(fVar12 * (float10)_DAT_0056ebd8);
      numberObjectsInRange =
           (**(code **)(pRVar8->master_obj->_padding_ + 0x28))(this->objectValue->master_obj);
      i = (int)RGE_Static_Object::distance_to_object(pRVar8,this->objectValue);
      bVar11 = pRVar8->master_obj->object_group == 3;
      if (!bVar11) {
        numberMovingTargets = numberMovingTargets + 1;
      }
      largestThreatIsBuilding = (int)bVar11;
      fVar12 = (float10)(*(code *)closestEnemyDistance)();
      if ((float10)_DAT_0056ebc8 < fVar12) {
        largestThreatIsBuilding = largestThreatIsBuilding + 1;
      }
    }
  }
LAB_004156de:
  if ((1 < numberDamagingUnits) &&
     (pRVar8 = RGE_Game_World::object(this_00,lStack_4), pRVar8 != (RGE_Static_Object *)0x0)) {
    iVar6 = (**(code **)(this->objectValue->_padding_ + 0xe4))(pRVar8);
    if (iVar6 == 1) {
      return lStack_4;
    }
    iVar6 = this->objectValue->_padding_;
    fVar12 = (float10)(**(code **)(iVar6 + 0x10c))(0,0,0xffffffff,0xffffffff);
    iVar6 = (**(code **)(iVar6 + 0x194))(lStack_4,(float)fVar12);
    if (iVar6 == 1) {
      return lStack_4;
    }
  }
  iVar6 = 4;
  do {
    world = (RGE_Game_World *)0x0;
    if (0 < (int)(&VisibleUnitList_Size)[iVar6]) {
      do {
        pRVar8 = RGE_Game_World::object(this_00,(int)(&VisibleUnitList)[iVar6][(int)world * 2]);
        if ((((((pRVar8 != (RGE_Static_Object *)0x0) && (pRVar8->object_state < 3)) &&
              (iVar7 = (**(code **)(this->objectValue->owner->_padding_ + 0x1c))
                                 ((int)pRVar8->owner->id), iVar7 != 1)) &&
             (pRVar8->inside_obj == (RGE_Static_Object *)0x0)) &&
            (((param_1 != 0 && (numberObjectsInRange != 0)) ||
             (pRVar8->master_obj->object_group != 0x1b)))) &&
           (((((pRVar8->master_obj->object_group != 3 || (_DAT_0056ebd0 < pRVar8->hp)) ||
              ((sVar2 = this->objectValue->master_obj->id, sVar2 != 0x23 && (sVar2 != 0x24)))) &&
             (iVar7 = (**(code **)(iVar3 + 0x50))(pRVar8), iVar7 != 0)) &&
            ((iVar6 != 3 ||
             (iVar7 = (**(code **)(iVar3 + 0x54))((int)pRVar8->master_obj->object_group), iVar7 != 0
             )))))) {
          fVar14 = RGE_Static_Object::distance_to_object(this->objectValue,pRVar8);
          fVar12 = (float10)(**(code **)(this->objectValue->_padding_ + 0x110))();
          if (((fVar12 <= (float10)fVar14) &&
              ((int)(uint)*(byte *)((&VisibleUnitList)[iVar6] + (int)world * 2 + 1) <= modifier)) &&
             ((param_2 != 1 ||
              (iVar7 = (**(code **)(this->objectValue->_padding_ + 0xe4))(pRVar8), iVar7 != 0)))) {
            if ((param_2 == 0) &&
               (iVar7 = (**(code **)(this->objectValue->_padding_ + 0xe4))(pRVar8), iVar7 == 0)) {
              iVar7 = this->objectValue->_padding_;
              fVar12 = (float10)(**(code **)(iVar7 + 0x10c))(0,0,0xffffffff,0xffffffff);
              iVar7 = (**(code **)(iVar7 + 0x194))
                                ((&VisibleUnitList)[iVar6][(int)world * 2],(float)fVar12);
              if (iVar7 == 0) goto LAB_004159dc;
            }
            fVar13 = (float10)(**(code **)(pRVar8->_padding_ + 0x108))();
            fVar12 = (float10)_DAT_0056ebd8;
            if ((largestThreatIsBuilding < 1) || ((float)(fVar13 * fVar12) != _DAT_0056ebc8)) {
              iVar7 = (**(code **)(pRVar8->master_obj->_padding_ + 0x28))
                                (this->objectValue->master_obj);
              fVar14 = (float)iVar7 * _DAT_0056ebc0 + (float)(fVar13 * fVar12);
              if (_DAT_0056ebc8 < pRVar8->hp) {
                fVar14 = fVar14 / pRVar8->hp;
              }
              bVar1 = *(byte *)((&VisibleUnitList)[iVar6] + (int)world * 2 + 1);
              if (bVar1 != 0) {
                fVar14 = fVar14 / (float)bVar1;
              }
              if (1 < numberDamagingUnits) {
                uVar10 = (uint)bVar1;
                fVar14 = fVar14 / (float)(uVar10 * uVar10 * uVar10);
              }
              sVar2 = pRVar8->master_obj->object_group;
              if ((numberNonCurrentTargets == -1) ||
                 (((i != 0 || (sVar2 != 3)) &&
                  ((numberNonCurrentTargets == -1 ||
                   (((i == 1 && (sVar2 != 3)) || ((float)numberMovingTargets < fVar14)))))))) {
                numberNonCurrentTargets = (int)(&VisibleUnitList)[iVar6][(int)world * 2];
                i = (int)(sVar2 == 3);
                numberMovingTargets = (int)fVar14;
              }
            }
          }
        }
LAB_004159dc:
        world = (RGE_Game_World *)((int)&world->_padding_ + 1);
      } while ((int)world < (int)(&VisibleUnitList_Size)[iVar6]);
    }
    iVar6 = iVar6 + -1;
    if (iVar6 < 2) {
      return numberNonCurrentTargets;
    }
  } while( true );
}

// --------------------------------------------------

// Function: mostDangerousEnemy
// Address: 00415a10
/* WARNING: Variable defined which should be unmapped: i */
/* public: virtual int __thiscall UnitAIModule::mostDangerousEnemy(float *) */

int __thiscall UnitAIModule::mostDangerousEnemy(UnitAIModule *this,float *param_1)
{
  RGE_Master_Static_Object *pRVar1;
  int iVar2;
  undefined4 uVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  float10 fVar6;
  int i;
  float largestThreat;
  float fStack_4;
  
  (**(code **)(this->_padding_ + 0x20))();
  iVar5 = -1;
  fStack_4 = 0.0;
  largestThreat = 0.0;
  if (0 < DAT_0087d7d8) {
    do {
      pRVar4 = lookupObject(this,*(int *)(DAT_0087d7f0 + (int)largestThreat * 8));
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        pRVar1 = pRVar4->master_obj;
        iVar2 = this->objectValue->_padding_;
        fVar6 = (float10)(**(code **)(iVar2 + 0xf0))(pRVar4,pRVar4->owner,pRVar4);
        uVar3._0_2_ = pRVar1[1].tile_req1;
        uVar3._2_2_ = pRVar1[1].tile_req2;
        fVar6 = (float10)(**(code **)(iVar2 + 0x74))
                                   ((int)pRVar1[1].portrait_pict,uVar3,(float)fVar6);
        if ((iVar5 == -1) || ((float10)fStack_4 < fVar6)) {
          fStack_4 = (float)fVar6;
          iVar5 = *(int *)(DAT_0087d7f0 + (int)largestThreat * 8);
        }
      }
      largestThreat = (float)((int)largestThreat + 1);
    } while ((int)largestThreat < DAT_0087d7d8);
  }
  if (param_1 != (float *)0x0) {
    *param_1 = fStack_4;
  }
  return iVar5;
}

// --------------------------------------------------

// Function: weakestEnemy
// Address: 00415ad0
/* WARNING: Variable defined which should be unmapped: smallestHP */
/* public: virtual int __thiscall UnitAIModule::weakestEnemy(float *) */

int __thiscall UnitAIModule::weakestEnemy(UnitAIModule *this,float *param_1)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  float smallestHP;
  float fStack_4;
  
  (**(code **)(this->_padding_ + 0x20))();
  iVar2 = -1;
  iVar3 = 0;
  fStack_4 = 0.0;
  if (0 < DAT_0087d7d8) {
    do {
      pRVar1 = lookupObject(this,*(int *)(DAT_0087d7f0 + iVar3 * 8));
      if ((pRVar1 != (RGE_Static_Object *)0x0) && ((iVar2 == -1 || (pRVar1->hp < fStack_4)))) {
        fStack_4 = pRVar1->hp;
        iVar2 = *(int *)(DAT_0087d7f0 + iVar3 * 8);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_0087d7d8);
  }
  if (param_1 != (float *)0x0) {
    *param_1 = fStack_4;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: closestAttacker
// Address: 00415b50
/* WARNING: Variable defined which should be unmapped: largestThreat */
/* public: virtual int __thiscall UnitAIModule::closestAttacker(float *) */

int __thiscall UnitAIModule::closestAttacker(UnitAIModule *this,float *param_1)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float largestThreat;
  int largestThreatID;
  float attackThreat;
  
  iVar5 = 0;
  attackThreat = -NAN;
  largestThreatID = 0;
  if (0 < (this->attackingUnitsValue).numberValue) {
    do {
      if ((this->attackingUnitsValue).maximumSizeValue + -1 < iVar5) {
        piVar1 = (int *)operator_new(iVar5 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->attackingUnitsValue).maximumSizeValue) {
            do {
              if (iVar5 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (this->attackingUnitsValue).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (this->attackingUnitsValue).maximumSizeValue);
          }
          operator_delete((this->attackingUnitsValue).value);
          (this->attackingUnitsValue).value = piVar1;
          (this->attackingUnitsValue).maximumSizeValue = iVar5 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         (this->objectValue->owner->world,(this->attackingUnitsValue).value[iVar5]);
      if (pRVar3 != (RGE_Static_Object *)0x0) {
        fVar6 = RGE_Static_Object::distance_to_object(this->objectValue,pRVar3);
        if ((attackThreat == -NAN) || (fVar6 < (float)largestThreatID)) {
          if ((this->attackingUnitsValue).maximumSizeValue + -1 < iVar5) {
            piVar1 = (int *)operator_new(iVar5 * 4 + 4);
            if (piVar1 != (int *)0x0) {
              iVar4 = 0;
              if (0 < (this->attackingUnitsValue).maximumSizeValue) {
                do {
                  if (iVar5 + 1 <= iVar4) break;
                  iVar2 = iVar4 + 1;
                  piVar1[iVar4] = (this->attackingUnitsValue).value[iVar4];
                  iVar4 = iVar2;
                } while (iVar2 < (this->attackingUnitsValue).maximumSizeValue);
              }
              operator_delete((this->attackingUnitsValue).value);
              (this->attackingUnitsValue).value = piVar1;
              (this->attackingUnitsValue).maximumSizeValue = iVar5 + 1;
            }
          }
          attackThreat = (float)(this->attackingUnitsValue).value[iVar5];
          largestThreatID = (int)fVar6;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (this->attackingUnitsValue).numberValue);
  }
  if (param_1 != (float *)0x0) {
    *param_1 = (float)largestThreatID;
  }
  return (int)attackThreat;
}

// --------------------------------------------------

// Function: closestObject
// Address: 00415ca0
/* WARNING: Variable defined which should be unmapped: closestDistance */
/* public: virtual int __thiscall UnitAIModule::closestObject(int,int,int,int,int *) */

int __thiscall
UnitAIModule::closestObject
          (UnitAIModule *this,int param_1,int param_2,int param_3,int param_4,int *param_5)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float closestDistance;
  int closestObjectID;
  int iStack_2c;
  int objectsOfPlayer [9];
  
  objectsOfPlayer[0] = (int)this;
  (**(code **)(this->_padding_ + 0x20))();
  piVar3 = objectsOfPlayer;
  for (iVar4 = 9; piVar3 = piVar3 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar3 = 0;
  }
  iStack_2c = -1;
  closestObjectID = -0x40800000;
  iVar4 = 0;
  do {
    iVar5 = 0;
    if (0 < *(int *)((int)&VisibleUnitList_Size + iVar4)) {
      piVar3 = (int *)((int)&VisibleUnitList + iVar4);
      do {
        iVar1 = *piVar3;
        objectsOfPlayer[*(byte *)(iVar1 + 5 + iVar5 * 8) + 1] = 1;
        if (*(int *)(*(int *)(objectsOfPlayer[0] + 4) + 4) != *(int *)(iVar1 + iVar5 * 8)) {
          pRVar2 = RGE_Game_World::object
                             (*(RGE_Game_World **)
                               (*(int *)(*(int *)(objectsOfPlayer[0] + 4) + 0xc) + 0x3c),
                              *(int *)(*piVar3 + iVar5 * 8));
          if (((((((pRVar2 != (RGE_Static_Object *)0x0) && (pRVar2->object_state < 7)) &&
                 ((param_2 != 0 || ((iVar4 == 8 || (iVar4 == 4)))))) &&
                ((param_2 != 2 || (iVar4 == 0x10)))) &&
               (((param_2 != 3 || (iVar4 == 4)) &&
                (((param_2 != 1 || (iVar4 == 0xc)) &&
                 ((param_1 == -1 || (pRVar2->master_obj->object_group == param_1)))))))) &&
              ((param_4 == -1 || (pRVar2->master_obj->id == param_4)))) &&
             ((param_3 == -1 || ((uint)pRVar2->object_state == param_3)))) {
            if (iStack_2c != -1) {
              if ((float)closestObjectID <= (float)*(byte *)(*piVar3 + 4 + iVar5 * 8))
              goto LAB_00415de5;
            }
            closestObjectID = (int)(float)*(byte *)(*piVar3 + 4 + iVar5 * 8);
            iStack_2c = *(int *)(*piVar3 + iVar5 * 8);
          }
        }
LAB_00415de5:
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)((int)&VisibleUnitList_Size + iVar4));
    }
    iVar4 = iVar4 + 4;
    if (0x10 < iVar4) {
      numberDifferentPlayerObjectsVisible = 0;
      piVar3 = objectsOfPlayer + 2;
      iVar4 = 8;
      do {
        if (*piVar3 == 1) {
          numberDifferentPlayerObjectsVisible = numberDifferentPlayerObjectsVisible + 1;
        }
        piVar3 = piVar3 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (param_5 != (int *)0x0) {
        iVar4 = __ftol();
        *param_5 = iVar4;
      }
      return iStack_2c;
    }
  } while( true );
}

// --------------------------------------------------

// Function: closestResourceObject
// Address: 00415e50
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall UnitAIModule::closestResourceObject(int,int *) */

int __thiscall UnitAIModule::closestResourceObject(UnitAIModule *this,int param_1,int *param_2)
{
  RGE_Static_Object *this_00;
  byte bVar1;
  int iVar3;
  int iVar4;
  VISIBLE_RESOURCE_REC *pVVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int excludeList [100];
  uint uVar2;
  
  piVar9 = excludeList;
  piVar8 = excludeList;
  for (iVar7 = 100; piVar9 = piVar9 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar9 = -0x80000000;
  }
  iVar7 = 0;
  do {
    piVar8 = piVar8 + 1;
    this_00 = this->objectValue;
    piVar9 = excludeList + 1;
    iVar6 = param_1;
    iVar10 = iVar7;
    bVar1 = RGE_Static_Object::currentZone(this_00);
    uVar2 = (uint)bVar1;
    iVar3 = __ftol();
    iVar4 = __ftol();
    pVVar5 = Visible_Resource_Manager::Get_Closest_Resource
                       (this_00->owner->VR_List,iVar4,iVar3,uVar2,iVar6,piVar9,iVar10);
    if (pVVar5 == (VISIBLE_RESOURCE_REC *)0x0) {
      return -1;
    }
    excludeList[0] = (int)pVVar5->distance;
    if (this->objectValue->master_obj->los - _DAT_0056ebe0 < (float)excludeList[0]) {
      return -1;
    }
    iVar6 = (**(code **)(this->objectValue->_padding_ + 0x194))
                      (pVVar5->object_id,0x3f800000,0,0,0xffffffff,0xffffffff);
    if (iVar6 == 1) break;
    iVar7 = iVar7 + 1;
    *piVar8 = pVVar5->object_id;
  } while (iVar7 < 100);
  if (param_2 != (int *)0x0) {
    *param_2 = (uint)pVVar5->distance;
  }
  return pVVar5->object_id;
}

// --------------------------------------------------

// Function: closestUndiscoveredTile
// Address: 00415f40
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
/* WARNING: Variable defined which should be unmapped: currentZone */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall UnitAIModule::closestUndiscoveredTile(int *,int *,int) */

int __thiscall
UnitAIModule::closestUndiscoveredTile(UnitAIModule *this,int *param_1,int *param_2,int param_3)
{
  RGE_Static_Object *pRVar1;
  RGE_Player *pRVar2;
  RGE_Visible_Map *pRVar3;
  RGE_Map *pRVar4;
  int iVar5;
  uchar uVar6;
  uchar uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  uchar currentZone;
  int lowX;
  int highX;
  int highY;
  int distance;
  int i;
  int searchRadius;
  RGE_Visible_Map *vMap;
  int currX;
  int currY;
  int randSelect;
  
  if (((this->currentOrderValue != 0x2c1) || (this->currentTargetXValue == -1.0)) ||
     (this->currentTargetYValue == -1.0)) {
    pRVar1 = this->objectValue;
    i = -1;
    iVar8 = __ftol();
    iVar9 = __ftol();
    __ftol();
    highX = __ftol();
    highY = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    pRVar2 = pRVar1->owner;
    pRVar3 = pRVar2->visible;
    pRVar4 = pRVar2->world->map;
    if (highX < 0) {
      highX = 0;
    }
    iVar16 = pRVar4->map_width + -1;
    if (iVar16 < highY) {
      highY = iVar16;
    }
    if (iVar10 < 0) {
      iVar10 = 0;
    }
    iVar16 = pRVar4->map_height + -1;
    if (iVar16 < iVar11) {
      iVar11 = iVar16;
    }
    iVar16 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xb2e);
    uVar6 = RGE_Static_Object::currentZone(this->objectValue);
    for (; iVar5 = highX, iVar10 <= iVar11; iVar10 = iVar10 + 1) {
      for (; iVar5 <= highY; iVar5 = iVar5 + 1) {
        uVar7 = visibleStatus(this,pRVar3,iVar5,iVar10);
        if (((uVar7 == '\0') &&
            (uVar7 = RGE_Static_Object::lookupZone(this->objectValue,iVar5,iVar10), uVar6 == uVar7))
           && ((iVar12 = (**(code **)(this->objectValue->_padding_ + 0x114))
                                   ((float)iVar5,(float)iVar10,0), iVar12 != 0 &&
               ((param_3 == 0 || (iVar12 = inWaypointQueue(this,iVar5,iVar10), iVar12 == 0)))))) {
          iVar12 = (iVar5 - iVar8) * (iVar5 - iVar8) + (iVar10 - iVar9) * (iVar10 - iVar9);
          if (this->currentTargetXValue != -1.0) {
            iVar13 = __ftol();
            iVar14 = __ftol();
            iVar12 = (iVar10 - iVar14) * (iVar10 - iVar14) + iVar12 +
                     (iVar5 - iVar13) * (iVar5 - iVar13);
          }
          if ((i == -1) || (iVar12 < iVar16 % 3 + i)) {
            *param_1 = iVar5;
            *param_2 = iVar10;
            i = iVar12;
          }
        }
      }
    }
    if (i != -1) {
      pRVar1 = this->objectValue;
      iVar10 = *param_1;
      iVar11 = *param_2;
      uVar15 = __ftol();
      iVar10 = (**(code **)(pRVar1->_padding_ + 0x198))
                         (iVar10,iVar11,uVar15,pRVar1->master_obj->los - _DAT_0056ebd0,0xffffffff,
                          &param_1,0,0xffffffff,0xffffffff);
      return iVar10;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: waypoint
// Address: 004161d0
/* public: struct Waypoint * __thiscall UnitAIModule::waypoint(int)const  */

Waypoint * __thiscall UnitAIModule::waypoint(UnitAIModule *this,int param_1)
{
  return (Waypoint *)0x0;
}

// --------------------------------------------------

// Function: waypointQueueSize
// Address: 004161e0
/* public: int __thiscall UnitAIModule::waypointQueueSize(void)const  */

int __thiscall UnitAIModule::waypointQueueSize(UnitAIModule *this)
{
  return this->waypointQueueSizeValue;
}

// --------------------------------------------------

// Function: addToWaypointQueue
// Address: 004161f0
/* public: int __thiscall UnitAIModule::addToWaypointQueue(int,int) */

int __thiscall UnitAIModule::addToWaypointQueue(UnitAIModule *this,int param_1,int param_2)
{
  if (7 < this->waypointQueueSizeValue) {
    this->waypointQueueSizeValue = 0;
  }
  this->waypointQueue[this->waypointQueueSizeValue].x = (float)param_1;
  this->waypointQueue[this->waypointQueueSizeValue].y = (float)param_2;
  this->waypointQueueSizeValue = this->waypointQueueSizeValue + 1;
  return 1;
}

// --------------------------------------------------

// Function: inWaypointQueue
// Address: 00416240
/* public: int __thiscall UnitAIModule::inWaypointQueue(int,int)const  */

int __thiscall UnitAIModule::inWaypointQueue(UnitAIModule *this,int param_1,int param_2)
{
  float *pfVar1;
  int iVar2;
  
  iVar2 = 0;
  if (this->waypointQueueSizeValue < 1) {
    return 0;
  }
  pfVar1 = &this->waypointQueue[0].y;
  do {
    if (((Waypoint *)(pfVar1 + -1))->x == (float)param_1) {
      if ((float)param_2 == *pfVar1) {
        return 1;
      }
    }
    iVar2 = iVar2 + 1;
    pfVar1 = pfVar1 + 4;
  } while (iVar2 < this->waypointQueueSizeValue);
  return 0;
}

// --------------------------------------------------

// Function: clearWaypointQueue
// Address: 00416290
/* public: void __thiscall UnitAIModule::clearWaypointQueue(void) */

void __thiscall UnitAIModule::clearWaypointQueue(UnitAIModule *this)
{
  this->waypointQueueSizeValue = 0;
  return;
}

// --------------------------------------------------

// Function: canAttackUnit
// Address: 004162a0
/* public: virtual int __thiscall UnitAIModule::canAttackUnit(class RGE_Static_Object *) */

int __thiscall UnitAIModule::canAttackUnit(UnitAIModule *this,RGE_Static_Object *param_1)
{
  return 1;
}

// --------------------------------------------------

// Function: canAttackUnitAtNeutrality
// Address: 004162b0
/* public: virtual int __thiscall UnitAIModule::canAttackUnitAtNeutrality(int) */

int __thiscall UnitAIModule::canAttackUnitAtNeutrality(UnitAIModule *this,int param_1)
{
  return 1;
}

// --------------------------------------------------

// Function: stopObject
// Address: 004162c0
// [HELPER] s_t_ld__U__d_sO__cOAA__d__: "t%ld, U#%d sO, cOAA=%d.\n"
/* public: virtual int __thiscall UnitAIModule::stopObject(int) */

int __thiscall UnitAIModule::stopObject(UnitAIModule *this,int param_1)
{
  int iVar1;
  
  if (actionFile != (_iobuf *)0x0) {
    fprintf(actionFile,s_t_ld__U__d_sO__cOAA__d__,this->objectValue->owner->world->world_time,
            this->objectValue->id,param_1);
  }
  this->lastActionValue = this->currentActionValue;
  if ((param_1 == 0) || (this->currentActionValue + 100 == this->currentOrderValue)) {
    iVar1 = this->currentOrderValue;
    this->currentOrderValue = -1;
    this->lastOrderValue = iVar1;
    this->currentOrderPriorityValue = -1;
  }
  (**(code **)(this->objectValue->_padding_ + 0x18c))();
  this->currentActionValue = -1;
  return 1;
}

// --------------------------------------------------

// Function: attackObject
// Address: 00416340
/* public: virtual int __thiscall UnitAIModule::attackObject(int,int) */

int __thiscall UnitAIModule::attackObject(UnitAIModule *this,int param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  
  if ((param_2 != 0) || (this->currentActionValue == -1)) {
    pRVar1 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      iVar2 = (**(code **)(this->_padding_ + 0x50))(pRVar1);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(this->objectValue->_padding_ + 0x150))(param_1,param_2);
        if (iVar2 == 1) {
          setCurrentAction(this,600);
          setCurrentTarget(this,param_1,pRVar1->world_x,pRVar1->world_y,pRVar1->world_z);
          return 1;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: attackRoundupObject
// Address: 004163c0
/* public: virtual int __thiscall UnitAIModule::attackRoundupObject(int) */

int __thiscall UnitAIModule::attackRoundupObject(UnitAIModule *this,int param_1)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  float10 fVar3;
  
  if (((this->currentTargetValue != param_1) &&
      (pRVar1 = RGE_Game_World::object(this->objectValue->owner->world,param_1),
      pRVar1 != (RGE_Static_Object *)0x0)) &&
     (iVar2 = (**(code **)(this->_padding_ + 0x50))(pRVar1), iVar2 != 0)) {
    if (this->currentActionValue != -1) {
      iVar2 = this->objectValue->_padding_;
      fVar3 = (float10)(**(code **)(iVar2 + 0x10c))(0,0,0xffffffff,0xffffffff);
      iVar2 = (**(code **)(iVar2 + 0x194))(param_1,(float)fVar3);
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar2 = (**(code **)(this->objectValue->_padding_ + 0x150))(param_1,1);
    if (iVar2 == 1) {
      setCurrentAction(this,600);
      setCurrentTarget(this,param_1,pRVar1->world_x,pRVar1->world_y,pRVar1->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: huntObject
// Address: 00416470
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* public: virtual int __thiscall UnitAIModule::huntObject(int,int) */

int __thiscall UnitAIModule::huntObject(UnitAIModule *this,int param_1,int param_2)
{
  long lVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int unaff_retaddr;
  
  if ((param_2 != 0) || (this->currentActionValue != 0x265)) {
    if (actionFile != (_iobuf *)0x0) {
      if (this->objectValue == (RGE_Static_Object *)0x0) {
        lVar1 = -1;
      }
      else {
        lVar1 = this->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar1,s_C__msdev_work_age1_x1_aiuaimod_c,0xc48
             );
    }
    (**(code **)(this->_padding_ + 0x58))(1);
    iVar2 = (**(code **)(this->objectValue->_padding_ + 0x164))(unaff_retaddr,param_2);
    if (iVar2 == 1) {
      pRVar3 = RGE_Game_World::object(this->objectValue->owner->world,unaff_retaddr);
      setCurrentAction(this,0x265);
      if (pRVar3 == (RGE_Static_Object *)0x0) {
        setCurrentTarget(this,unaff_retaddr,-1,0.0,0.0,0.0);
        return 1;
      }
      setCurrentTarget(this,unaff_retaddr,(int)pRVar3->master_obj->object_group,pRVar3->world_x,
                       pRVar3->world_y,pRVar3->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: convertObject
// Address: 00416550
/* public: virtual int __thiscall UnitAIModule::convertObject(int,int) */

int __thiscall UnitAIModule::convertObject(UnitAIModule *this,int param_1,int param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_2 != 0) || (this->currentActionValue != 0x25c)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x16c))(param_1,param_2);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
      setCurrentAction(this,0x25c);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        setCurrentTarget(this,param_1,-1,0.0,0.0,0.0);
        return 1;
      }
      setCurrentTarget(this,param_1,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                       pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: healObject
// Address: 004165f0
/* public: virtual int __thiscall UnitAIModule::healObject(int,int) */

int __thiscall UnitAIModule::healObject(UnitAIModule *this,int param_1,int param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_2 != 0) || (this->currentActionValue != 0x25b)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x88))(param_1,param_2);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
      setCurrentAction(this,0x25b);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        setCurrentTarget(this,param_1,-1,0.0,0.0,0.0);
        return 1;
      }
      setCurrentTarget(this,param_1,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                       pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: gatherObject
// Address: 00416690
/* public: virtual int __thiscall UnitAIModule::gatherObject(int,int) */

int __thiscall UnitAIModule::gatherObject(UnitAIModule *this,int param_1,int param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_2 != 0) || (this->currentActionValue != 0x261)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x168))(param_1,param_2);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
      setCurrentAction(this,0x261);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        setCurrentTarget(this,param_1,-1,0.0,0.0,0.0);
        return 1;
      }
      setCurrentTarget(this,param_1,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                       pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: repairObject
// Address: 00416730
/* public: virtual int __thiscall UnitAIModule::repairObject(int,int) */

int __thiscall UnitAIModule::repairObject(UnitAIModule *this,int param_1,int param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_2 != 0) || (this->currentActionValue != 0x26a)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x170))(param_1,param_2);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
      setCurrentAction(this,0x26a);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        setCurrentTarget(this,param_1,-1,0.0,0.0,0.0);
        return 1;
      }
      setCurrentTarget(this,param_1,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                       pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: buildObject
// Address: 004167d0
/* public: virtual int __thiscall UnitAIModule::buildObject(int,int) */

int __thiscall UnitAIModule::buildObject(UnitAIModule *this,int param_1,int param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_2 != 0) || (this->currentActionValue != 0x25a)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x174))(param_1,param_2);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
      setCurrentAction(this,0x25a);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        setCurrentTarget(this,param_1,-1,0.0,0.0,0.0);
        return 1;
      }
      setCurrentTarget(this,param_1,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                       pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: tradeWithObject
// Address: 00416870
/* public: virtual int __thiscall UnitAIModule::tradeWithObject(int,int) */

int __thiscall UnitAIModule::tradeWithObject(UnitAIModule *this,int param_1,int param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_2 != 0) || (this->currentActionValue != 0x267)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x178))(param_1,param_2);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
      setCurrentAction(this,0x267);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        setCurrentTarget(this,param_1,-1,0.0,0.0,0.0);
        return 1;
      }
      setCurrentTarget(this,param_1,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                       pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: explore
// Address: 00416910
/* public: virtual int __thiscall UnitAIModule::explore(int,int,int) */

int __thiscall UnitAIModule::explore(UnitAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  int unaff_ESI;
  
  if ((param_3 != 0) || (this->currentActionValue == -1)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x17c))(param_1,param_2);
    if (iVar1 == 1) {
      setCurrentAction(this,0x25d);
      setCurrentTarget(this,-1,(float)param_3,(float)unaff_ESI,1.0);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: enterObject
// Address: 00416980
/* public: virtual int __thiscall UnitAIModule::enterObject(int,int) */

int __thiscall UnitAIModule::enterObject(UnitAIModule *this,int param_1,int param_2)
{
  int iVar1;
  
  if ((param_2 != 0) || (this->currentActionValue == -1)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x180))(param_1,param_2);
    if (iVar1 == 1) {
      setCurrentAction(this,0x269);
      setCurrentTarget(this,param_1,-1.0,-1.0,-1.0);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: transportObject
// Address: 004169e0
/* public: virtual int __thiscall UnitAIModule::transportObject(float,float,float,int) */

int __thiscall
UnitAIModule::transportObject
          (UnitAIModule *this,float param_1,float param_2,float param_3,int param_4)
{
  int iVar1;
  
  if ((param_4 != 0) || (this->currentActionValue == -1)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x188))(param_1,param_2,param_3,param_4);
    if (iVar1 == 1) {
      setCurrentAction(this,0x266);
      setCurrentTarget(this,-1,param_1,param_2,param_3);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: unload
// Address: 00416a50
/* public: virtual int __thiscall UnitAIModule::unload(int,float,float) */

int __thiscall UnitAIModule::unload(UnitAIModule *this,int param_1,float param_2,float param_3)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  
  if ((param_1 != 0) || (this->currentActionValue == -1)) {
    iVar2 = (**(code **)(this->objectValue->_padding_ + 0x184))
                      (param_1,param_2,param_3,this->objectValue->world_z);
    if (iVar2 == 1) {
      pRVar1 = this->objectValue;
      setCurrentAction(this,0x26d);
      if (pRVar1 == (RGE_Static_Object *)0x0) {
        setCurrentTarget(this,this->objectValue->id,-1,0.0,0.0,0.0);
        return 1;
      }
      setCurrentTarget(this,this->objectValue->id,(int)pRVar1->master_obj->object_group,
                       pRVar1->world_x,pRVar1->world_y,pRVar1->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: moveTo
// Address: 00416af0
/* public: virtual int __thiscall UnitAIModule::moveTo(int,int) */

int __thiscall UnitAIModule::moveTo(UnitAIModule *this,int param_1,int param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_2 != 0) || (this->currentActionValue == -1)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x15c))(param_1,param_2);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
      setCurrentAction(this,0x262);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        setCurrentTarget(this,param_1,0.0,0.0,0.0);
        return 1;
      }
      setCurrentTarget(this,param_1,pRVar2->world_x,pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: moveTo
// Address: 00416b80
/* public: virtual int __thiscall UnitAIModule::moveTo(int,float,int) */

int __thiscall UnitAIModule::moveTo(UnitAIModule *this,int param_1,float param_2,int param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_3 != 0) || (this->currentActionValue == -1)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x158))(param_1,param_2,param_3);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
      setCurrentAction(this,0x262);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        setCurrentTarget(this,param_1,0.0,0.0,0.0);
        return 1;
      }
      setCurrentTarget(this,param_1,pRVar2->world_x,pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: moveTo
// Address: 00416c10
/* public: virtual int __thiscall UnitAIModule::moveTo(float,float,float,float,int) */

int __thiscall
UnitAIModule::moveTo
          (UnitAIModule *this,float param_1,float param_2,float param_3,float param_4,int param_5)
{
  int iVar1;
  
  if ((param_5 != 0) || (this->currentActionValue == -1)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x154))
                      (param_1,param_2,param_3,param_4,param_5);
    if (iVar1 == 1) {
      setCurrentAction(this,0x262);
      setCurrentTarget(this,-1,param_1,param_2,param_3);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: evasiveMoveTo
// Address: 00416c80
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall UnitAIModule::evasiveMoveTo(float,float,float,int) */

int __thiscall
UnitAIModule::evasiveMoveTo
          (UnitAIModule *this,float param_1,float param_2,float param_3,int param_4)
{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if ((param_4 != 0) || (this->currentActionValue == -1)) {
    if (_DAT_0056ebc8 <= param_1) {
      fVar1 = (float)this->objectValue->owner->world->map->map_width;
      if (fVar1 <= param_1) {
        param_1 = fVar1 - _DAT_0056ebd0;
      }
    }
    else {
      param_1 = 0.0;
    }
    if (_DAT_0056ebc8 <= param_2) {
      fVar1 = (float)this->objectValue->owner->world->map->map_height;
      if (fVar1 <= param_2) {
        param_2 = fVar1 - _DAT_0056ebd0;
      }
    }
    else {
      param_2 = 0.0;
    }
    iVar5 = 0;
    do {
      iVar2 = (**(code **)(this->objectValue->_padding_ + 0x114))(param_1,param_2,0);
      if (iVar2 == 1) break;
      uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xd9f);
      uVar4 = (int)uVar3 >> 0x1f;
      if (((uVar3 ^ uVar4) - uVar4 & 1 ^ uVar4) == uVar4) {
        uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xda2);
        uVar4 = (int)uVar3 >> 0x1f;
        param_1 = param_1 - (float)(int)(((uVar3 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4);
      }
      else {
        uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xda0);
        uVar4 = (int)uVar3 >> 0x1f;
        param_1 = (float)(int)(((uVar3 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4) + param_1;
      }
      uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xda3);
      uVar4 = (int)uVar3 >> 0x1f;
      if (((uVar3 ^ uVar4) - uVar4 & 1 ^ uVar4) == uVar4) {
        uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xda6);
        uVar4 = (int)uVar3 >> 0x1f;
        param_2 = param_2 - (float)(int)(((uVar3 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4);
      }
      else {
        uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xda4);
        uVar4 = (int)uVar3 >> 0x1f;
        param_2 = (float)(int)(((uVar3 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4) + param_2;
      }
      if (_DAT_0056ebc8 <= param_1) {
        fVar1 = (float)this->objectValue->owner->world->map->map_width;
        if (fVar1 <= param_1) {
          param_1 = fVar1 - _DAT_0056ebd0;
        }
      }
      else {
        param_1 = 0.0;
      }
      if (_DAT_0056ebc8 <= param_2) {
        fVar1 = (float)this->objectValue->owner->world->map->map_height;
        if (fVar1 <= param_2) {
          param_2 = fVar1 - _DAT_0056ebd0;
        }
      }
      else {
        param_2 = 0.0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 5);
    iVar5 = (**(code **)(this->objectValue->_padding_ + 0x154))(param_1,param_2,param_3,0,param_4);
    if (iVar5 == 1) {
      setCurrentAction(this,0x262);
      setCurrentTarget(this,-1,param_1,param_2,param_3);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: intelligentEvasiveMoveTo
// Address: 00416f30
/* WARNING: Variable defined which should be unmapped: baseDistance */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall UnitAIModule::intelligentEvasiveMoveTo(float,float,float,int,int)
    */

int __thiscall
UnitAIModule::intelligentEvasiveMoveTo
          (UnitAIModule *this,float param_1,float param_2,float param_3,int param_4,int param_5)
{
  RGE_Static_Object *pRVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  float unaff_EBX;
  float fVar6;
  float unaff_EBP;
  float unaff_ESI;
  float fVar7;
  float fVar8;
  float fStack_34;
  float fStack_30;
  int iStack_2c;
  float baseDistance;
  int facet;
  XYZPoint point;
  
  if ((param_5 != 0) || (this->currentActionValue == -1)) {
    fVar2 = (float)__ftol();
    iVar3 = __ftol();
    pRVar1 = this->objectValue;
    uVar4 = __ftol();
    iStack_2c = -1;
    fStack_30 = 0.0;
    fStack_34 = 0.0;
    iVar5 = (**(code **)(pRVar1->_padding_ + 0x198))(fVar2,iVar3,uVar4,0x3f800000,0xffffffff);
    if (iVar5 == 0) {
      fVar7 = RGE_Static_Object::distance_to_position
                        (this->objectValue,unaff_ESI,unaff_EBP,this->objectValue->world_z);
      fVar6 = -NAN;
LAB_0041704d:
      do {
        fStack_34 = (float)((int)fVar6 + 1);
        switch(fStack_34) {
        case 0.0:
          fVar2 = (float)((int)fVar2 + -2);
          fStack_30 = fVar2;
        case 9.80909e-45:
          iVar3 = iVar3 + -2;
          iStack_2c = iVar3;
          break;
        case 1.4013e-45:
        case 2.8026e-45:
          fVar2 = (float)((int)fVar2 + 2);
          fStack_30 = fVar2;
          break;
        case 4.2039e-45:
        case 5.60519e-45:
          iVar3 = iVar3 + 2;
          iStack_2c = iVar3;
          break;
        case 7.00649e-45:
        case 8.40779e-45:
          fVar2 = (float)((int)fVar2 + -2);
          fStack_30 = fVar2;
          break;
        default:
          goto switchD_0041705b_default;
        }
        if ((int)fVar2 < 0) {
          fVar2 = 0.0;
          fStack_30 = fVar2;
        }
        else {
          iVar5 = this->objectValue->owner->world->map->map_width;
          if (iVar5 <= (int)fVar2) {
            fVar2 = (float)(iVar5 + -1);
            fStack_30 = fVar2;
          }
        }
        if (iVar3 < 0) {
          iVar3 = 0;
          iStack_2c = iVar3;
        }
        else {
          iVar5 = this->objectValue->owner->world->map->map_height;
          if (iVar5 <= iVar3) {
            iVar3 = iVar5 + -1;
            iStack_2c = iVar3;
          }
        }
        if ((facet == 0) &&
           (fVar8 = RGE_Static_Object::distance_to_position
                              (this->objectValue,(float)(int)fStack_30 - _DAT_0056ebe4,
                               (float)iStack_2c - _DAT_0056ebe4,this->objectValue->world_z),
           fVar8 < fVar7)) {
          fVar6 = (float)((int)fVar6 + 2);
          goto LAB_0041704d;
        }
        iVar5 = (**(code **)(this->objectValue->_padding_ + 0x198))
                          (fVar2,iVar3,0xffffffff,0x3f800000,0xffffffff,0,0,0xffffffff,0xffffffff);
        fVar6 = fStack_34;
      } while (iVar5 != 1);
    }
    iVar3 = (**(code **)(this->objectValue->_padding_ + 0x154))
                      ((float)(int)fStack_30 - _DAT_0056ebe4,(float)iStack_2c - _DAT_0056ebe4,
                       unaff_EBX,0x3f000000,point.x);
    if (iVar3 == 1) {
      setCurrentAction(this,0x262);
      setCurrentTarget(this,-1,fStack_34,fStack_30,unaff_EBX);
      return 1;
    }
  }
switchD_0041705b_default:
  return 0;
}

// --------------------------------------------------

// Function: runAwayFromAttackers
// Address: 004171f0
/* WARNING: Variable defined which should be unmapped: xDiff */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall UnitAIModule::runAwayFromAttackers(int) */

int __thiscall UnitAIModule::runAwayFromAttackers(UnitAIModule *this,int param_1)
{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  int iVar6;
  float10 fVar7;
  float xDiff;
  float local_4;
  
  if ((param_1 == 0) && (this->currentActionValue != -1)) {
    return 0;
  }
  iVar6 = 0;
  local_4 = 0.0;
  param_1 = 0;
  if (0 < (this->attackingUnitsValue).numberValue) {
    do {
      if ((this->attackingUnitsValue).maximumSizeValue + -1 < iVar6) {
        piVar2 = (int *)operator_new(iVar6 * 4 + 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->attackingUnitsValue).maximumSizeValue) {
            do {
              if (iVar6 + 1 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->attackingUnitsValue).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->attackingUnitsValue).maximumSizeValue);
          }
          operator_delete((this->attackingUnitsValue).value);
          (this->attackingUnitsValue).value = piVar2;
          (this->attackingUnitsValue).maximumSizeValue = iVar6 + 1;
        }
      }
      pRVar5 = RGE_Game_World::object
                         (this->objectValue->owner->world,(this->attackingUnitsValue).value[iVar6]);
      if (pRVar5 != (RGE_Static_Object *)0x0) {
        local_4 = (pRVar5->world_x - this->objectValue->world_x) + local_4;
        param_1 = (int)((pRVar5->world_y - this->objectValue->world_y) + (float)param_1);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (this->attackingUnitsValue).numberValue);
  }
  fVar7 = (float10)(**(code **)(this->objectValue->_padding_ + 0xfc))();
  pRVar5 = this->objectValue;
  fVar1 = SQRT((float)param_1 * (float)param_1 + local_4 * local_4);
  iVar6 = (**(code **)(this->_padding_ + 0x9c))
                    (-((local_4 / fVar1) * (float)(fVar7 * (float10)_DAT_0056ebe8)) +
                     pRVar5->world_x,
                     -(((float)param_1 / fVar1) * (float)(fVar7 * (float10)_DAT_0056ebe8)) +
                     pRVar5->world_y,pRVar5->world_z,1);
  return iVar6;
}

// --------------------------------------------------

// Function: followObject
// Address: 00417360
/* public: virtual int __thiscall UnitAIModule::followObject(int,float,int) */

int __thiscall UnitAIModule::followObject(UnitAIModule *this,int param_1,float param_2,int param_3)
{
  RGE_Static_Object *pRVar1;
  
  if ((param_3 == 0) && (this->currentActionValue != -1)) {
    return 0;
  }
  pRVar1 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  setCurrentAction(this,0x264);
  setCurrentTarget(this,param_1,pRVar1->world_x,pRVar1->world_y,pRVar1->world_z);
  this->desiredTargetDistanceValue = param_2;
  return 1;
}

// --------------------------------------------------

// Function: defendObject
// Address: 004173d0
/* public: virtual int __thiscall UnitAIModule::defendObject(int,float,int) */

int __thiscall UnitAIModule::defendObject(UnitAIModule *this,int param_1,float param_2,int param_3)
{
  RGE_Static_Object *pRVar1;
  
  if ((param_3 == 0) && (this->currentActionValue != -1)) {
    return 0;
  }
  pRVar1 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  setCurrentAction(this,0x259);
  setCurrentTarget(this,param_1,pRVar1->world_x,pRVar1->world_y,pRVar1->world_z);
  this->defendTargetValue = param_1;
  this->desiredTargetDistanceValue = param_2;
  return 1;
}

// --------------------------------------------------

// Function: defendPosition
// Address: 00417440
/* public: virtual int __thiscall UnitAIModule::defendPosition(float,float,float,int) */

int __thiscall
UnitAIModule::defendPosition
          (UnitAIModule *this,float param_1,float param_2,float param_3,int param_4)
{
  if ((param_4 == 0) && (this->currentActionValue != -1)) {
    return 0;
  }
  setCurrentAction(this,0x259);
  setCurrentTarget(this,-1,param_1,param_2,this->objectValue->world_z);
  this->defendTargetValue = -1;
  this->desiredTargetDistanceValue = param_3;
  return 1;
}

// --------------------------------------------------

// Function: seekAndDestroy
// Address: 004174a0
/* public: virtual int __thiscall UnitAIModule::seekAndDestroy(int,int,int,int) */

int __thiscall
UnitAIModule::seekAndDestroy(UnitAIModule *this,int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int unaff_retaddr;
  
  if ((param_4 != 0) || (this->currentActionValue == -1)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x150))(param_1,param_4);
    if (iVar1 == 1) {
      setCurrentAction(this,0x26e);
      setCurrentTarget(this,param_1,(float)unaff_retaddr,(float)param_1,1.0);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: exploreAndDestroy
// Address: 00417510
/* public: virtual int __thiscall UnitAIModule::exploreAndDestroy(int,int,int) */

int __thiscall
UnitAIModule::exploreAndDestroy(UnitAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  int unaff_ESI;
  
  if ((param_3 != 0) || (this->currentActionValue == -1)) {
    iVar1 = (**(code **)(this->objectValue->_padding_ + 0x17c))(param_1,param_2);
    if (iVar1 == 1) {
      setCurrentAction(this,0x26f);
      setCurrentTarget(this,-1,(float)param_3,(float)unaff_ESI,1.0);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: removeCurrentTarget
// Address: 00417580
/* public: void __thiscall UnitAIModule::removeCurrentTarget(void) */

void __thiscall UnitAIModule::removeCurrentTarget(UnitAIModule *this)
{
  int iVar1;
  
  iVar1 = this->currentTargetTypeValue;
  this->lastTargetValue = this->currentTargetValue;
  this->currentTargetValue = -1;
  this->currentTargetTypeValue = -1;
  this->lastTargetTypeValue = iVar1;
  this->currentTargetXValue = -1.0;
  this->currentTargetYValue = -1.0;
  this->currentTargetZValue = -1.0;
  return;
}

// --------------------------------------------------

// Function: setCurrentTarget
// Address: 004175b0
/* public: void __thiscall UnitAIModule::setCurrentTarget(int,float,float,float) */

void __thiscall
UnitAIModule::setCurrentTarget
          (UnitAIModule *this,int param_1,float param_2,float param_3,float param_4)
{
  RGE_Static_Object *pRVar1;
  
  this->lastTargetValue = this->currentTargetValue;
  this->lastTargetTypeValue = this->currentTargetTypeValue;
  this->currentTargetValue = param_1;
  this->currentTargetXValue = param_2;
  this->currentTargetYValue = param_3;
  this->currentTargetZValue = param_4;
  pRVar1 = RGE_Game_World::object(this->objectValue->owner->world,param_1);
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    this->currentTargetTypeValue = (int)pRVar1->master_obj->object_group;
  }
  return;
}

// --------------------------------------------------

// Function: setCurrentTarget
// Address: 00417600
/* public: void __thiscall UnitAIModule::setCurrentTarget(int,int,float,float,float) */

void __thiscall
UnitAIModule::setCurrentTarget
          (UnitAIModule *this,int param_1,int param_2,float param_3,float param_4,float param_5)
{
  this->lastTargetValue = this->currentTargetValue;
  this->lastTargetTypeValue = this->currentTargetTypeValue;
  this->currentTargetValue = param_1;
  this->currentTargetTypeValue = param_2;
  this->currentTargetXValue = param_3;
  this->currentTargetYValue = param_4;
  this->currentTargetZValue = param_5;
  return;
}

// --------------------------------------------------

// Function: importantObject
// Address: 00417640
/* public: virtual int __thiscall UnitAIModule::importantObject(int) */

int __thiscall UnitAIModule::importantObject(UnitAIModule *this,int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (this->numberImportantObjects < 1) {
    return 0;
  }
  piVar2 = this->importantObjects;
  do {
    if (*piVar2 == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < this->numberImportantObjects);
  return 0;
}

// --------------------------------------------------

// Function: isEnemyOwner
// Address: 00417680
/* public: int __thiscall UnitAIModule::isEnemyOwner(int) */

int __thiscall UnitAIModule::isEnemyOwner(UnitAIModule *this,int param_1)
{
  RGE_Player *pRVar1;
  
  pRVar1 = this->objectValue->owner;
  if (pRVar1->id == param_1) {
    return 0;
  }
  return (uint)(pRVar1->relations[param_1] == '\x03');
}

// --------------------------------------------------

// Function: isAllyOwner
// Address: 004176b0
/* public: int __thiscall UnitAIModule::isAllyOwner(int) */

int __thiscall UnitAIModule::isAllyOwner(UnitAIModule *this,int param_1)
{
  RGE_Player *pRVar1;
  
  pRVar1 = this->objectValue->owner;
  if (pRVar1->id == param_1) {
    return 1;
  }
  if ((pRVar1->relations[param_1] == '\0') &&
     (pRVar1->world->players[param_1]->relations[pRVar1->id] == '\0')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: isNeutralOwner
// Address: 00417700
/* public: int __thiscall UnitAIModule::isNeutralOwner(int) */

int __thiscall UnitAIModule::isNeutralOwner(UnitAIModule *this,int param_1)
{
  RGE_Player *pRVar1;
  
  pRVar1 = this->objectValue->owner;
  if (pRVar1->id == param_1) {
    return 0;
  }
  return (uint)(pRVar1->relations[param_1] == '\x01');
}

// --------------------------------------------------

// Function: visibleStatus
// Address: 00417730
/* public: unsigned char __thiscall UnitAIModule::visibleStatus(class RGE_Visible_Map *,int,int) */

uchar __thiscall
UnitAIModule::visibleStatus(UnitAIModule *this,RGE_Visible_Map *param_1,int param_2,int param_3)
{
  RGE_Player *pRVar1;
  
  pRVar1 = this->objectValue->owner;
  if ((pRVar1->mutualVisibleMask & (uint)(&unified_map_offsets)[param_3][param_2]) != 0) {
    return '\x0f';
  }
  return -((pRVar1->mutualExploredMask & (uint)(&unified_map_offsets)[param_3][param_2]) != 0) &
         0x80;
}

// --------------------------------------------------

// Function: setAdjustedIdleTimeout
// Address: 00417770
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
/* public: void __thiscall UnitAIModule::setAdjustedIdleTimeout(void) */

void __thiscall UnitAIModule::setAdjustedIdleTimeout(UnitAIModule *this)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = this->idleTimeoutValue;
  uVar2 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xf4c);
  this->adjustedIdleTimeoutValue = uVar2 % (uVar1 >> 1) + (uVar1 * 3 >> 2);
  return;
}

// --------------------------------------------------

// Function: setTaskedByPlayer
// Address: 004177b0
/* public: void __thiscall UnitAIModule::setTaskedByPlayer(void) */

void __thiscall UnitAIModule::setTaskedByPlayer(UnitAIModule *this)
{
  purgeNotifyQueue(this,0);
  return;
}

// --------------------------------------------------

// Function: convertToLOSResourceType
// Address: 004177c0
/* public: virtual int __thiscall UnitAIModule::convertToLOSResourceType(int) */

int __thiscall UnitAIModule::convertToLOSResourceType(UnitAIModule *this,int param_1)
{
  return -1;
}

// --------------------------------------------------

// Function: setPlayStatus
// Address: 004177d0
/* public: void __thiscall UnitAIModule::setPlayStatus(class AIPlayStatus *) */

void __thiscall UnitAIModule::setPlayStatus(UnitAIModule *this,AIPlayStatus *param_1)
{
  AIPlayStatus *pAVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c8eb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (this->playStatus == (AIPlayStatus *)0x0) {
    pAVar1 = (AIPlayStatus *)operator_new(0x1c8);
    local_4 = 0;
    if (pAVar1 == (AIPlayStatus *)0x0) {
      pAVar1 = (AIPlayStatus *)0x0;
    }
    else {
      pAVar1 = (AIPlayStatus *)AIPlayStatus::AIPlayStatus(pAVar1);
    }
    this->playStatus = pAVar1;
  }
  local_4 = 0xffffffff;
  if ((this->playStatus != (AIPlayStatus *)0x0) && (param_1 != (AIPlayStatus *)0x0)) {
    AIPlayStatus::copy(this->playStatus,param_1);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: lookAround
// Address: 00417860
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
/* WARNING: Variable defined which should be unmapped: world */
/* public: void __thiscall UnitAIModule::lookAround(void) */

void __thiscall UnitAIModule::lookAround(UnitAIModule *this)
{
  short sVar1;
  long lVar2;
  RGE_Player *pRVar3;
  RGE_Game_World *this_00;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  RGE_Game_World *world;
  int ownerID;
  
  (**(code **)(this->_padding_ + 0x20))();
  iVar5 = 0;
  lVar2 = this->objectValue->id;
  pRVar3 = this->objectValue->owner;
  sVar1 = pRVar3->id;
  this_00 = pRVar3->world;
  do {
    iVar6 = 0;
    if (0 < *(int *)((int)&DAT_0087d7d8 + iVar5)) {
      do {
        pRVar4 = RGE_Game_World::object
                           (this_00,*(int *)(*(int *)((int)&DAT_0087d7f0 + iVar5) + iVar6 * 8));
        if ((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->object_state < 3)) {
          (**(code **)(this->objectValue->owner->_padding_ + 0xe8))
                    (lVar2,(int)sVar1,0x20d,pRVar4->id,0,0);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)((int)&DAT_0087d7d8 + iVar5));
    }
    iVar5 = iVar5 + -4;
  } while (-8 < iVar5);
  this->lookAroundTimerValue = 0;
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xf92);
  this->lookAroundTimeoutValue = iVar5 % 1000 + 4000;
  return;
}

// --------------------------------------------------

// Function: hasOrderOnQueue
// Address: 00417920
/* public: int __thiscall UnitAIModule::hasOrderOnQueue(int) */

int __thiscall UnitAIModule::hasOrderOnQueue(UnitAIModule *this,int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (this->orderQueueSizeValue < 1) {
    return 0;
  }
  piVar2 = &this->orderQueueValue->orderType;
  do {
    if (*piVar2 == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 9;
  } while (iVar1 < this->orderQueueSizeValue);
  return 0;
}

// --------------------------------------------------

// Function: askForHelp
// Address: 00417960
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall UnitAIModule::askForHelp(int) */

void __thiscall UnitAIModule::askForHelp(UnitAIModule *this,int param_1)
{
  short sVar1;
  RGE_Player *pRVar2;
  RGE_Static_Object *pRVar3;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar4;
  int iVar5;
  float10 fVar6;
  float fVar7;
  int i;
  int iStack_10;
  int iStack_c;
  
  pRVar3 = lookupObject(this,param_1);
  if (pRVar3 != (RGE_Static_Object *)0x0) {
    (**(code **)(this->_padding_ + 0x20))();
    iStack_c = 0;
    do {
      iStack_10 = 0;
      if (0 < *(int *)((int)&DAT_0087d7cc + iStack_c)) {
        do {
          if (((((this->objectValue->id !=
                  *(int *)(iStack_10 * 8 + *(int *)((int)&DAT_0087d7e4 + iStack_c))) &&
                (this_00 = lookupObject(this,*(int *)(iStack_10 * 8 +
                                                     *(int *)((int)&DAT_0087d7e4 + iStack_c))),
                this_00 != (RGE_Static_Object *)0x0)) &&
               (pUVar4 = RGE_Static_Object::unitAI(this_00), pUVar4 != (UnitAIModule *)0x0)) &&
              (((pRVar2 = this_00->owner, pRVar2 != (RGE_Player *)0x0 && (this_00->object_state < 3)
                ) && ((sVar1 = this_00->master_obj->object_group, sVar1 != 1 &&
                      ((sVar1 != 3 && (sVar1 != 4)))))))) &&
             ((sVar1 != 0x15 &&
              (((((sVar1 != 0x12 && (sVar1 != 0x14)) && (sVar1 != 0x1b)) &&
                ((sVar1 = this->objectValue->owner->id, pRVar2->id == sVar1 ||
                 (iVar5 = (**(code **)(pRVar2->_padding_ + 0x1c))((int)sVar1), iVar5 != 0)))) &&
               (fVar7 = RGE_Static_Object::distance_to_object(this->objectValue,this_00),
               fVar7 <= _DAT_0056ebec)))))) {
            pUVar4 = RGE_Static_Object::unitAI(this_00);
            iVar5 = currentAction(pUVar4);
            if (iVar5 == -1) {
              pUVar4 = RGE_Static_Object::unitAI(this_00);
              iVar5 = currentOrder(pUVar4);
              if (iVar5 == -1) {
                pUVar4 = RGE_Static_Object::unitAI(this_00);
                iVar5 = orderQueueSize(pUVar4);
                if (iVar5 < 1) {
                  pUVar4 = RGE_Static_Object::unitAI(this_00);
                  fVar7 = pRVar3->world_y;
                  iVar5 = pUVar4->_padding_;
                  fVar6 = (float10)(**(code **)(this_00->_padding_ + 0x10c))(1,0,0x32);
                  (**(code **)(iVar5 + 0x10))
                            ((int)this_00->owner->id,700,param_1,(int)pRVar3->owner->id,
                             pRVar3->world_x,fVar7,fVar7,(float)fVar6);
                }
              }
            }
          }
          iStack_10 = iStack_10 + 1;
        } while (iStack_10 < *(int *)((int)&DAT_0087d7cc + iStack_c));
      }
      iStack_c = iStack_c + 4;
    } while (iStack_c < 5);
  }
  return;
}

// --------------------------------------------------

// Function: processOrder
// Address: 00417b50
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* protected: virtual int __thiscall UnitAIModule::processOrder(struct OrderEvent *,int) */

int __thiscall UnitAIModule::processOrder(UnitAIModule *this,OrderEvent *param_1,int param_2)
{
  AIPlay *pAVar1;
  AIPlayStatus *pAVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c90b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar8 = 0;
  switch(param_1->orderType) {
  case 700:
    iVar8 = (**(code **)(this->_padding_ + 0x5c))(param_1->target,1);
    break;
  case 0x2bd:
    if (param_1->target == -1) {
      iVar8 = (**(code **)(this->_padding_ + 0xb0))
                        (param_1->targetX,param_1->targetY,param_1->range,1);
    }
    else {
      iVar8 = (**(code **)(this->_padding_ + 0xac))(param_1->target,param_1->range);
    }
    break;
  case 0x2be:
    iVar8 = (**(code **)(this->_padding_ + 0x78))(param_1->target,1);
    break;
  case 0x2bf:
    iVar8 = (**(code **)(this->_padding_ + 0x70))(param_1->target,1);
    break;
  case 0x2c0:
    iVar8 = (**(code **)(this->_padding_ + 0x6c))(param_1->target,1);
    break;
  case 0x2c1:
    iVar8 = this->_padding_;
    uVar5 = __ftol(1);
    uVar5 = __ftol(uVar5);
    iVar8 = (**(code **)(iVar8 + 0x80))(uVar5);
    break;
  case 0x2c2:
    removeCurrentTarget(this);
    if (actionFile != (_iobuf *)0x0) {
      if (this->objectValue == (RGE_Static_Object *)0x0) {
        lVar6 = -1;
      }
      else {
        lVar6 = this->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar6,s_C__msdev_work_age1_x1_aiuaimod_c,
              0x105d);
      (**(code **)(this->_padding_ + 0x58))(1);
      iVar8 = 1;
      break;
    }
    goto LAB_00417eeb;
  case 0x2c5:
    iVar8 = (**(code **)(this->_padding_ + 0x68))(param_1->target,1);
    break;
  case 0x2c6:
    iVar8 = (**(code **)(this->_padding_ + 0x90))
                      (param_1->targetX,param_1->targetY,param_1->targetZ,param_1->range,1);
    break;
  case 0x2c8:
    iVar8 = (**(code **)(this->_padding_ + 0xa8))(param_1->target,param_1->range,1);
    break;
  case 0x2c9:
    iVar8 = (**(code **)(this->_padding_ + 100))(param_1->target,1);
    break;
  case 0x2ca:
    iVar8 = (**(code **)(this->_padding_ + 0x8c))
                      (param_1->targetX,param_1->targetY,param_1->targetZ,1);
    break;
  case 0x2cd:
    iVar8 = (**(code **)(this->_padding_ + 0x84))(param_1->target,1);
    break;
  case 0x2ce:
    iVar8 = (**(code **)(this->_padding_ + 0x74))(param_1->target,1);
    break;
  case 0x2d1:
    iVar8 = (**(code **)(this->_padding_ + 0x88))(1,param_1->targetX,param_1->targetY);
    break;
  case 0x2d2:
    iVar8 = this->_padding_;
    uVar5 = __ftol(1);
    uVar5 = __ftol(uVar5);
    iVar8 = (**(code **)(iVar8 + 0xb4))(param_1->target,uVar5);
    break;
  case 0x2d3:
    iVar8 = this->_padding_;
    uVar5 = __ftol(1);
    uVar5 = __ftol(uVar5);
    iVar8 = (**(code **)(iVar8 + 0xb8))(uVar5);
    break;
  case 0x2d4:
    iVar8 = (**(code **)(this->_padding_ + 0x90))
                      (param_1->targetX,param_1->targetY,param_1->targetZ,param_1->range,1);
    break;
  case 0x2d5:
    removeCurrentTarget(this);
    if (actionFile != (_iobuf *)0x0) {
      if (this->objectValue == (RGE_Static_Object *)0x0) {
        lVar6 = -1;
      }
      else {
        lVar6 = this->objectValue->id;
      }
                    /* language.dll match for 0x10e9: "Time Limit" */
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar6,s_C__msdev_work_age1_x1_aiuaimod_c,
              0x10e9);
    }
LAB_00417eeb:
    (**(code **)(this->_padding_ + 0x58))(1);
LAB_00417ef4:
    iVar8 = 1;
    break;
  case 0x2d6:
    iVar8 = 1;
    pAVar1 = AIPlayBook::play(this->objectValue->owner->world->playbook,param_1->targetOwner);
    if (pAVar1 == (AIPlay *)0x0) {
      iVar8 = 0;
    }
    else {
      if (this->playStatus != (AIPlayStatus *)0x0) {
        operator_delete(this->playStatus);
      }
      pAVar2 = (AIPlayStatus *)operator_new(0x1c8);
      local_4 = 0;
      if (pAVar2 == (AIPlayStatus *)0x0) {
        pAVar2 = (AIPlayStatus *)0x0;
      }
      else {
        pAVar2 = (AIPlayStatus *)AIPlayStatus::AIPlayStatus(pAVar2);
      }
      this->playStatus = pAVar2;
      if (pAVar2 == (AIPlayStatus *)0x0) {
        iVar8 = 0;
      }
      else {
        pAVar2->playNumberValue = param_1->targetOwner;
        this->playStatus->targetValue = param_1->target;
        if (param_1->targetX == -1.0) {
          iVar7 = __ftol();
          iVar3 = __ftol();
          iVar4 = __ftol();
          pAVar2 = this->playStatus;
          (pAVar2->originalPointValue).xValue = iVar4;
          (pAVar2->originalPointValue).yValue = iVar3;
          (pAVar2->originalPointValue).zValue = iVar7;
        }
        else {
          iVar7 = __ftol();
          iVar3 = __ftol();
          pAVar2 = this->playStatus;
          iVar4 = __ftol();
          (pAVar2->originalPointValue).xValue = iVar4;
          (pAVar2->originalPointValue).yValue = iVar3;
          (pAVar2->originalPointValue).zValue = iVar7;
        }
      }
    }
    break;
  case 0x2d7:
    if (this->playStatus != (AIPlayStatus *)0x0) {
      operator_delete(this->playStatus);
      this->playStatus = (AIPlayStatus *)0x0;
      iVar8 = 1;
      break;
    }
    goto LAB_00417ef4;
  case 0x2d8:
    iVar8 = 1;
    this->currentActionValue = 0x274;
    this->currentOrderValue = 0x2d8;
    break;
  case 0x2d9:
    iVar8 = (**(code **)(this->_padding_ + 0x60))(param_1->target);
  }
  if (iVar8 == 1) {
    iVar7 = param_1->orderType;
    if (iVar7 == 0x2c2) {
      iVar7 = -1;
      this->currentOrderValue = -1;
    }
    else {
      if (iVar7 == 0x2d9) {
        this->currentOrderValue = 700;
      }
      else if ((iVar7 == 700) && (this->objectValue->master_obj->id == 0x7d)) {
        this->currentOrderValue = -1;
        this->currentTargetValue = -1;
      }
      else {
        this->currentOrderValue = iVar7;
      }
      iVar7 = param_1->priority;
    }
    this->currentOrderPriorityValue = iVar7;
  }
  if (((-1 < param_2) && (param_2 < this->orderQueueSizeValue)) &&
     (this->orderQueueValue != (OrderEvent *)0x0)) {
    if (param_2 < this->orderQueueSizeValue + -1) {
      iVar7 = param_2 * 0x24;
      do {
        *(undefined4 *)((int)&this->orderQueueValue->issuer + iVar7) =
             *(undefined4 *)((int)&this->orderQueueValue[1].issuer + iVar7);
        *(undefined4 *)((int)&this->orderQueueValue->orderType + iVar7) =
             *(undefined4 *)((int)&this->orderQueueValue[1].orderType + iVar7);
        *(undefined4 *)((int)&this->orderQueueValue->priority + iVar7) =
             *(undefined4 *)((int)&this->orderQueueValue[1].priority + iVar7);
        *(undefined4 *)((int)&this->orderQueueValue->target + iVar7) =
             *(undefined4 *)((int)&this->orderQueueValue[1].target + iVar7);
        *(undefined4 *)((int)&this->orderQueueValue->targetOwner + iVar7) =
             *(undefined4 *)((int)&this->orderQueueValue[1].targetOwner + iVar7);
        *(undefined4 *)((int)&this->orderQueueValue->targetX + iVar7) =
             *(undefined4 *)((int)&this->orderQueueValue[1].targetX + iVar7);
        *(undefined4 *)((int)&this->orderQueueValue->targetY + iVar7) =
             *(undefined4 *)((int)&this->orderQueueValue[1].targetY + iVar7);
        param_2 = param_2 + 1;
        *(undefined4 *)((int)&this->orderQueueValue->targetZ + iVar7) =
             *(undefined4 *)((int)&this->orderQueueValue[1].targetZ + iVar7);
        iVar7 = iVar7 + 0x24;
      } while (param_2 < this->orderQueueSizeValue + -1);
    }
    this->orderQueueSizeValue = this->orderQueueSizeValue + -1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return (uint)(iVar8 == 1);
}

// --------------------------------------------------

// Function: processNotify
// Address: 004180c0
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall UnitAIModule::processNotify(struct NotifyEvent *,unsigned long)
    */

int __thiscall UnitAIModule::processNotify(UnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  short sVar1;
  float fVar2;
  uchar uVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  ulong unaff_EBP;
  RGE_Static_Object *pRVar11;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar12;
  NotifyEvent *unaff_retaddr;
  RGE_Static_Object *pRVar13;
  NotifyEvent *pNVar14;
  undefined4 uVar15;
  code *pcVar16;
  int tileX;
  float lastTargetXValue;
  float local_4;
  
  switch(param_1->mType) {
  case 500:
  case 0x20f:
    pNVar14 = param_1;
    (**(code **)(this->_padding_ + 0x1c))();
    if (param_1->p2 < 1) {
      lVar10 = this->objectValue->id;
      (**(code **)(this->objectValue->owner->_padding_ + 0xe8))
                (lVar10,lVar10,0x209,param_1->caller,0,0);
      purgeNotifyQueue(this,unaff_EBP);
      return 4;
    }
    if (((this->attackingUnitsValue).numberValue == 0) ||
       (iVar9 = RGE_Player::computerPlayer(this->objectValue->owner), iVar9 == 1)) {
      lVar10 = this->objectValue->id;
      (**(code **)(this->objectValue->owner->_padding_ + 0xe8))
                (lVar10,lVar10,0x201,param_1->caller,0,0);
    }
    iVar9 = (this->attackingUnitsValue).numberValue;
    iVar8 = 0;
    if (0 < iVar9) {
      do {
        if ((this->attackingUnitsValue).maximumSizeValue <= iVar8) break;
        if ((this->attackingUnitsValue).value[iVar8] == param_1->caller) goto LAB_004181b7;
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar9);
    }
    iVar9 = RGE_Player::computerPlayer(this->objectValue->owner);
    if ((iVar9 == 0) && (this->currentTargetValue != param_1->caller)) {
      askForHelp(this,param_1->caller);
    }
LAB_004181b7:
    iVar9 = (this->attackingUnitsValue).numberValue;
    iVar8 = param_1->caller;
    iVar5 = 0;
    if (0 < iVar9) {
      do {
        if ((this->attackingUnitsValue).maximumSizeValue <= iVar5) break;
        if ((this->attackingUnitsValue).value[iVar5] == iVar8) goto LAB_0041823e;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar9);
    }
    if ((this->attackingUnitsValue).maximumSizeValue + -1 < iVar9) {
      iVar9 = iVar9 + 1;
      piVar6 = (int *)operator_new(iVar9 * 4);
      param_1 = unaff_retaddr;
      if (piVar6 != (int *)0x0) {
        iVar5 = 0;
        if (0 < (this->attackingUnitsValue).maximumSizeValue) {
          do {
            if (iVar9 <= iVar5) break;
            iVar7 = iVar5 + 1;
            piVar6[iVar5] = (this->attackingUnitsValue).value[iVar5];
            iVar5 = iVar7;
          } while (iVar7 < (this->attackingUnitsValue).maximumSizeValue);
        }
        operator_delete((this->attackingUnitsValue).value);
        (this->attackingUnitsValue).value = piVar6;
        (this->attackingUnitsValue).maximumSizeValue = iVar9;
      }
    }
    (this->attackingUnitsValue).value[(this->attackingUnitsValue).numberValue] = iVar8;
    (this->attackingUnitsValue).numberValue = (this->attackingUnitsValue).numberValue + 1;
LAB_0041823e:
    (**(code **)(this->objectValue->_padding_ + 0xec))(1);
    if (((this->currentOrderValue != 0x2d5) && (this->currentOrderValue != -1)) &&
       (iVar9 = RGE_Player::computerPlayer(this->objectValue->owner), iVar9 == 0)) {
      return 2;
    }
    if (this->currentOrderValue == 0x2d5) {
      return 2;
    }
    pRVar4 = lookupObject(this,param_1->caller);
    if (pRVar4 == (RGE_Static_Object *)0x0) {
      return 2;
    }
    if (pRVar4->owner->id == this->objectValue->owner->id) {
      return 2;
    }
    if ((this->currentActionValue == 0x25b) &&
       (iVar9 = (**(code **)(unaff_EBP + 0xa4))(1), iVar9 == 1)) {
      return 3;
    }
    pRVar11 = (RGE_Static_Object *)0x0;
    if (this->currentTargetValue != -1) {
      pRVar11 = lookupObject(this,this->currentTargetValue);
    }
    if (pRVar11 != (RGE_Static_Object *)0x0) {
      sVar1 = pRVar11->master_obj->object_group;
      if (((sVar1 == 3) || (sVar1 == 0x1b)) &&
         ((sVar1 = pRVar11->master_obj->id, sVar1 != 0x4f &&
          (((sVar1 != 199 && (sVar1 != 0x45)) &&
           (iVar9 = RGE_Player::computerPlayer(this->objectValue->owner), iVar9 == 0)))))) {
        iVar9 = (**(code **)(unaff_EBP + 0x50))(pRVar4);
        if (iVar9 != 1) {
LAB_0041844c:
          (**(code **)(unaff_EBP + 0xa4))(1);
          return 3;
        }
        iVar9 = (**(code **)(this->objectValue->_padding_ + 0xe4))(pRVar4);
        if (iVar9 != 1) {
          iVar9 = this->objectValue->_padding_;
          fVar12 = (float10)(**(code **)(iVar9 + 0x10c))(0,0,0xffffffff,0xffffffff);
          iVar9 = (**(code **)(iVar9 + 0x194))(*(undefined4 *)lastTargetXValue,(float)fVar12);
          if (iVar9 != 1) goto LAB_0041844c;
        }
        (**(code **)(unaff_EBP + 0x5c))(*(undefined4 *)lastTargetXValue,1);
        return 3;
      }
      iVar9 = RGE_Player::computerPlayer(this->objectValue->owner);
      if (iVar9 != 1) {
        return 2;
      }
      if (pRVar11->master_obj->id == 0x114) {
        return 2;
      }
      fVar2 = (float)pRVar11->_padding_;
      fVar12 = (float10)(**(code **)((int)fVar2 + 0x108))();
      if (fVar12 != (float10)_DAT_0056ebc8) {
        (**(code **)(this->objectValue->_padding_ + 0x104))(pRVar11);
      }
      pRVar13 = pRVar4;
      iVar9 = (**(code **)(unaff_EBP + 0x50))();
      if ((iVar9 == 1) && (local_4 == _DAT_0056ebc8)) {
        iVar9 = (**(code **)(this->objectValue->_padding_ + 0xe4))(pRVar4);
        if (iVar9 != 1) {
          iVar9 = this->objectValue->_padding_;
          fVar12 = (float10)(**(code **)(iVar9 + 0x10c))(0,0,0xffffffff,0xffffffff);
          iVar9 = (**(code **)(iVar9 + 0x194))(*(undefined4 *)lastTargetXValue,(float)fVar12);
          if (iVar9 != 1) goto LAB_00418533;
        }
        (**(code **)(unaff_ESI + 0x5c))(*(undefined4 *)lastTargetXValue,1);
      }
LAB_00418533:
      fVar12 = (float10)(**(code **)(unaff_EBP + 0x104))(this->objectValue);
      if (fVar12 <= (float10)_DAT_0056ebc8) {
        pcVar16 = (code *)0x46c35000;
      }
      else {
        pcVar16 = (code *)(float)((float10)pRVar11->hp / fVar12);
      }
      (**(code **)(pRVar4->_padding_ + 0x104))(this->objectValue);
      iVar9 = (*pcVar16)(pRVar4);
      if (iVar9 != 1) {
        return 2;
      }
      if ((float)pNVar14 <= fVar2) {
        return 2;
      }
      iVar9 = (**(code **)(this->objectValue->_padding_ + 0xe4))(pRVar4);
      if (iVar9 != 1) {
        iVar9 = this->objectValue->_padding_;
        fVar12 = (float10)(**(code **)(iVar9 + 0x10c))(0,0,0xffffffff,0xffffffff);
        iVar9 = (**(code **)(iVar9 + 0x194))(*(undefined4 *)pcVar16,(float)fVar12);
        if (iVar9 != 1) {
          return 2;
        }
      }
      (*(code *)(pRVar13->pathingGroupMembers).desiredNumberValue)(*(undefined4 *)pcVar16,1);
      return 2;
    }
    iVar9 = (**(code **)(unaff_EBP + 0x50))(pRVar4);
    if (iVar9 == 1) {
      iVar9 = (**(code **)(this->objectValue->_padding_ + 0xe4))(pRVar4);
      if (iVar9 != 1) {
        iVar9 = this->objectValue->_padding_;
        fVar12 = (float10)(**(code **)(iVar9 + 0x10c))(0,0,0xffffffff,0xffffffff);
        iVar9 = (**(code **)(iVar9 + 0x194))(*(undefined4 *)lastTargetXValue,(float)fVar12);
        if (iVar9 != 1) goto LAB_00418371;
      }
      iVar9 = (**(code **)(unaff_EBP + 0x5c))(*(undefined4 *)lastTargetXValue,1);
      if ((iVar9 == 1) && (this->currentOrderValue != 700)) {
        this->currentOrderValue = -1;
        return 3;
      }
    }
    else {
LAB_00418371:
      if (this->currentActionValue != 0x262) {
        (**(code **)(unaff_EBP + 0xa4))(1);
        return 3;
      }
    }
    return 3;
  default:
    removeCurrentTarget(this);
    if (actionFile != (_iobuf *)0x0) {
      if (this->objectValue == (RGE_Static_Object *)0x0) {
        lVar10 = -1;
      }
      else {
        lVar10 = this->objectValue->id;
      }
                    /* language.dll match for 0x1439: "Heavy Cavalry" */
      uVar15 = 0x1439;
LAB_004193c2:
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
              uVar15);
    }
    goto LAB_004193d6;
  case 0x1f6:
  case 0x1f7:
  case 0x1f8:
  case 0x1fd:
  case 0x1ff:
  case 0x200:
  case 0x203:
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
    goto switchD_004180e8_caseD_1f6;
  case 0x1f9:
    iVar9 = this->currentOrderValue;
    if ((iVar9 == 700) && (param_1->p1 == 600)) {
      iVar9 = this->_padding_;
      iVar8 = (**(code **)(iVar9 + 0xd4))(0);
      if (iVar8 != 5) {
        return 2;
      }
      if ((this->currentOrderValue == 0x2d5) ||
         (iVar8 = RGE_Player::computerPlayer(this->objectValue->owner), iVar8 == 0)) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
          }
          else {
            lVar10 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x12e9);
          (**(code **)(iVar9 + 0x58))(1);
          return 2;
        }
      }
      else {
        iVar8 = (**(code **)(iVar9 + 0x90))
                          (this->currentTargetXValue,this->currentTargetYValue,
                           this->currentTargetZValue,
                           this->desiredTargetDistanceValue - _DAT_0056ebf4,1);
        if (iVar8 != 0) {
LAB_00418d7d:
          iVar9 = this->currentOrderValue;
          this->currentOrderValue = -1;
          this->currentOrderPriorityValue = -1;
          this->lastOrderValue = iVar9;
          return 2;
        }
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
          }
          else {
            lVar10 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x12f3);
          (**(code **)(iVar9 + 0x58))(1);
          return 2;
        }
      }
LAB_00418dd4:
      (**(code **)(iVar9 + 0x58))(1);
      return 2;
    }
    if (iVar9 == -1) {
LAB_00418b8e:
      if (this->currentActionValue == param_1->p1) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
            uVar15 = 0x130d;
          }
          else {
            lVar10 = this->objectValue->id;
            uVar15 = 0x130d;
          }
          goto LAB_004193c2;
        }
        goto LAB_004193d6;
      }
    }
    else {
      if (this->currentActionValue + 100 == iVar9) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
            uVar15 = 0x1304;
          }
          else {
            lVar10 = this->objectValue->id;
            uVar15 = 0x1304;
          }
          goto LAB_004193c2;
        }
        goto LAB_004193d6;
      }
      if (iVar9 == -1) goto LAB_00418b8e;
    }
    if ((iVar9 != 0x2d4) || (param_1->p1 != 0x262)) {
      if ((iVar9 == 0x2bd) && (param_1->p1 == 0x262)) {
        setCurrentAction(this,-1);
        return 2;
      }
      if (iVar9 != 0x2d5) {
        return 2;
      }
      if (param_1->p1 != 600) {
        return 2;
      }
      removeCurrentTarget(this);
      if (actionFile != (_iobuf *)0x0) {
        if (this->objectValue == (RGE_Static_Object *)0x0) {
          lVar10 = -1;
        }
        else {
          lVar10 = this->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                0x1325);
        (**(code **)(this->_padding_ + 0x58))(1);
        return 2;
      }
      goto LAB_00419254;
    }
    removeCurrentTarget(this);
    if (actionFile == (_iobuf *)0x0) goto LAB_00418ebe;
    if (this->objectValue == (RGE_Static_Object *)0x0) {
      lVar10 = -1;
    }
    else {
      lVar10 = this->objectValue->id;
    }
    fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,0x1317
           );
    iVar9 = this->_padding_;
    uVar15 = 0;
    break;
  case 0x1fa:
    iVar9 = this->currentOrderValue;
    if ((iVar9 == 700) && (param_1->p1 == 600)) {
      iVar9 = this->_padding_;
      iVar8 = (**(code **)(iVar9 + 0xd4))(0);
      if (iVar8 != 5) {
        return 2;
      }
      if ((this->currentOrderValue == 0x2d5) ||
         (iVar8 = RGE_Player::computerPlayer(this->objectValue->owner), iVar8 == 0)) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
          }
          else {
            lVar10 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x128b);
        }
      }
      else {
        iVar8 = (**(code **)(iVar9 + 0x90))
                          (this->currentTargetXValue,this->currentTargetYValue,
                           this->currentTargetZValue,
                           this->desiredTargetDistanceValue - _DAT_0056ebf4,1);
        if (iVar8 != 0) {
          iVar9 = this->currentOrderValue;
          this->currentOrderValue = -1;
          this->currentOrderPriorityValue = -1;
          this->lastOrderValue = iVar9;
          return 2;
        }
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
          }
          else {
            lVar10 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x129b);
          (**(code **)(iVar9 + 0x58))(0);
          return 2;
        }
      }
      (**(code **)(iVar9 + 0x58))(0);
      return 2;
    }
    if (iVar9 == -1) {
LAB_004188d8:
      if (this->currentActionValue == param_1->p1) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
          }
          else {
            lVar10 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x12b7);
          (**(code **)(this->_padding_ + 0x58))(1);
          return 2;
        }
        goto LAB_00419254;
      }
    }
    else {
      if (this->currentActionValue + 100 == iVar9) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
          }
          else {
            lVar10 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x12af);
          (**(code **)(this->_padding_ + 0x58))(1);
          return 2;
        }
        goto LAB_00419254;
      }
      if (iVar9 == -1) goto LAB_004188d8;
    }
    if ((iVar9 == 0x2d4) && (param_1->p1 == 0x262)) {
      removeCurrentTarget(this);
      if (actionFile != (_iobuf *)0x0) {
        if (this->objectValue == (RGE_Static_Object *)0x0) {
          lVar10 = -1;
        }
        else {
          lVar10 = this->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                0x12c0);
      }
      (**(code **)(this->_padding_ + 0x58))(0);
      return 2;
    }
    if ((iVar9 == 0x2bd) && (param_1->p1 == 0x262)) {
      setCurrentAction(this,-1);
      return 2;
    }
    if (iVar9 != 0x2d5) {
      return 2;
    }
    if (param_1->p1 != 600) {
      return 2;
    }
    removeCurrentTarget(this);
    if (actionFile != (_iobuf *)0x0) {
      if (this->objectValue == (RGE_Static_Object *)0x0) {
        lVar10 = -1;
      }
      else {
        lVar10 = this->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
              0x12cd);
      (**(code **)(this->_padding_ + 0x58))(1);
      return 2;
    }
LAB_00419254:
    (**(code **)(this->_padding_ + 0x58))(1);
    return 2;
  case 0x1fb:
    iVar9 = this->currentOrderValue;
    if ((iVar9 == 700) && (param_1->p1 == 600)) {
      iVar9 = this->_padding_;
      iVar8 = (**(code **)(iVar9 + 0xd4))(0);
      if (iVar8 != 5) {
        return 2;
      }
      if ((this->currentOrderValue == 0x2d5) ||
         (iVar8 = RGE_Player::computerPlayer(this->objectValue->owner), iVar8 == 0)) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
          }
          else {
            lVar10 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x1341);
        }
      }
      else {
        iVar8 = (**(code **)(iVar9 + 0x90))
                          (this->currentTargetXValue,this->currentTargetYValue,
                           this->currentTargetZValue,
                           this->desiredTargetDistanceValue - _DAT_0056ebf4,1);
        if (iVar8 != 0) goto LAB_00418d7d;
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
          }
          else {
            lVar10 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x134b);
          (**(code **)(iVar9 + 0x58))(1);
          return 2;
        }
      }
      goto LAB_00418dd4;
    }
    if (iVar9 == -1) {
LAB_00418e34:
      if (this->currentActionValue == param_1->p1) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
            uVar15 = 0x1365;
          }
          else {
            lVar10 = this->objectValue->id;
            uVar15 = 0x1365;
          }
          goto LAB_004193c2;
        }
        goto LAB_004193d6;
      }
    }
    else {
      if (this->currentActionValue + 100 == iVar9) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
            uVar15 = 0x135c;
          }
          else {
            lVar10 = this->objectValue->id;
            uVar15 = 0x135c;
          }
          goto LAB_004193c2;
        }
        goto LAB_004193d6;
      }
      if (iVar9 == -1) goto LAB_00418e34;
    }
    if ((iVar9 != 0x2d4) || (param_1->p1 != 0x262)) {
      if ((iVar9 == 0x2bd) && (param_1->p1 == 0x262)) {
        setCurrentAction(this,-1);
        return 2;
      }
      if (iVar9 != 0x2d5) {
        return 2;
      }
      if (param_1->p1 != 600) {
        return 2;
      }
      removeCurrentTarget(this);
      if (actionFile != (_iobuf *)0x0) {
        if (this->objectValue == (RGE_Static_Object *)0x0) {
          lVar10 = -1;
        }
        else {
          lVar10 = this->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                0x137d);
        (**(code **)(this->_padding_ + 0x58))(1);
        return 2;
      }
      goto LAB_00419254;
    }
    removeCurrentTarget(this);
    if (actionFile != (_iobuf *)0x0) {
      if (this->objectValue == (RGE_Static_Object *)0x0) {
        lVar10 = -1;
      }
      else {
        lVar10 = this->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
              0x136f);
    }
LAB_00418ebe:
    iVar9 = this->_padding_;
    uVar15 = 0;
    break;
  case 0x1fc:
    pRVar4 = lookupObject(this,this->currentTargetValue);
    if (pRVar4 != (RGE_Static_Object *)0x0) {
      iVar9 = __ftol();
      iVar8 = __ftol();
      uVar3 = visibleStatus(this,this->objectValue->owner->visible,iVar8,iVar9);
      if (pRVar4->owner->id == 0) {
        return 2;
      }
      if (uVar3 == '\x0f') {
        return 2;
      }
      fVar2 = this->currentTargetZValue;
      local_4 = this->currentTargetXValue;
      param_2 = (ulong)this->currentTargetYValue;
      iVar9 = this->_padding_;
      iVar8 = (**(code **)(iVar9 + 0x30))(1,0,0);
      if (((iVar8 != -1) && (iVar8 != this->currentTargetValue)) &&
         (iVar8 = (**(code **)(iVar9 + 0x5c))(iVar8,1), iVar8 == 1)) {
        this->currentOrderValue = -1;
        return 3;
      }
      iVar8 = RGE_Player::computerPlayer(this->objectValue->owner);
      if ((iVar8 == 0) &&
         (iVar9 = (**(code **)(iVar9 + 0x90))(local_4,param_2,fVar2,0,1), iVar9 == 1)) {
        iVar9 = this->currentOrderValue;
        this->currentOrderValue = -1;
        this->lastOrderValue = iVar9;
        this->currentOrderPriorityValue = -1;
        return 3;
      }
    }
    removeCurrentTarget(this);
    if (actionFile != (_iobuf *)0x0) {
      if (this->objectValue == (RGE_Static_Object *)0x0) {
        lVar10 = -1;
        uVar15 = 0x1269;
      }
      else {
        lVar10 = this->objectValue->id;
        uVar15 = 0x1269;
      }
      goto LAB_004193c2;
    }
LAB_004193d6:
    iVar9 = this->_padding_;
    uVar15 = 1;
    break;
  case 0x1fe:
    (**(code **)(this->objectValue->_padding_ + 0x18c))();
    removeCurrentTarget(this);
    if (actionFile != (_iobuf *)0x0) {
      if (this->objectValue == (RGE_Static_Object *)0x0) {
        lVar10 = -1;
      }
      else {
        lVar10 = this->objectValue->id;
      }
                    /* language.dll match for 0x13f9: "Grass Clump 7" */
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
              0x13f9);
    }
    goto LAB_00419254;
  case 0x202:
    iVar9 = this->currentActionValue;
    if ((iVar9 == 0x25d) || (iVar9 == 0x26f)) {
      iVar8 = this->_padding_;
      uVar15 = 1;
      iVar5 = (**(code **)(iVar8 + 0x48))(&lastTargetXValue,&param_2,1);
      if (iVar5 == 1) {
        addToWaypointQueue(this,unaff_EDI,tileX);
        iVar5 = (**(code **)(iVar8 + 0x80))(unaff_EDI,tileX,1);
        if (iVar5 == 0) {
          removeCurrentTarget(this);
          if (actionFile != (_iobuf *)0x0) {
            if (this->objectValue == (RGE_Static_Object *)0x0) {
              lVar10 = -1;
            }
            else {
              lVar10 = this->objectValue->id;
            }
                    /* language.dll match for 0x1396: "Heavy Transport" */
            fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,
                    s_C__msdev_work_age1_x1_aiuaimod_c,0x1396);
          }
          (**(code **)(iVar8 + 0x58))(1);
          (**(code **)(iVar8 + 0x1c))(uVar15);
        }
        this->currentActionValue = iVar9;
        return 3;
      }
      removeCurrentTarget(this);
      if (actionFile != (_iobuf *)0x0) {
        if (this->objectValue == (RGE_Static_Object *)0x0) {
          lVar10 = -1;
        }
        else {
          lVar10 = this->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                0x13a6);
      }
    }
    else {
      if (iVar9 != 0x261) {
        return 2;
      }
      iVar9 = this->currentTargetTypeValue;
      if (iVar9 == -1) {
        iVar9 = this->lastTargetTypeValue;
      }
      iVar8 = this->_padding_;
      iVar5 = (**(code **)(iVar8 + 0xc0))(iVar9);
      if (iVar5 == -1) {
        iVar9 = (**(code **)(iVar8 + 0x40))(iVar9,0xffffffff,0xffffffff,0xffffffff,0);
      }
      else {
        iVar9 = (**(code **)(iVar8 + 0x44))(iVar5);
      }
      if (iVar9 == -1) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar10 = -1;
          }
          else {
            lVar10 = this->objectValue->id;
          }
                    /* language.dll match for 0x13da: "Desert Patch 3" */
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x13da);
        }
        (**(code **)(iVar8 + 0x58))(1);
        (**(code **)(iVar8 + 0x1c))(tileX);
        return 2;
      }
      iVar9 = (**(code **)(iVar8 + 0x68))(iVar9,1);
      if (iVar9 == 1) {
        return 3;
      }
      removeCurrentTarget(this);
      if (actionFile != (_iobuf *)0x0) {
        if (this->objectValue == (RGE_Static_Object *)0x0) {
          lVar10 = -1;
        }
        else {
          lVar10 = this->objectValue->id;
        }
                    /* language.dll match for 0x13ce: "Dead Lumber" */
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
                0x13ce);
        (**(code **)(iVar8 + 0x58))(1);
        (**(code **)(iVar8 + 0x1c))(unaff_EBP);
        return 2;
      }
    }
    (**(code **)(iVar8 + 0x58))(1);
    (**(code **)(iVar8 + 0x1c))(unaff_EBP);
    return 2;
  case 0x20b:
    (**(code **)(this->objectValue->_padding_ + 0x18c))();
    removeCurrentTarget(this);
    if (actionFile != (_iobuf *)0x0) {
      if (this->objectValue == (RGE_Static_Object *)0x0) {
        lVar10 = -1;
      }
      else {
        lVar10 = this->objectValue->id;
      }
                    /* language.dll match for 0x13e7: "Fish - Shore" */
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar10,s_C__msdev_work_age1_x1_aiuaimod_c,
              0x13e7);
    }
    (**(code **)(this->_padding_ + 0x58))(1);
    purgeNotifyQueue(this,(ulong)param_1);
    this->orderQueueSizeValue = 0;
    pRVar4 = lookupObject(this,this->objectValue->groupCommanderValue);
    if (pRVar4 == (RGE_Static_Object *)0x0) {
      return 2;
    }
    RGE_Static_Object::commanderRemoveFromGroup(pRVar4,this->objectValue->id);
    return 2;
  case 600:
    iVar9 = (this->attackingUnitsValue).numberValue;
    iVar8 = param_1->caller;
    iVar5 = 0;
    if (0 < iVar9) {
      do {
        if ((this->attackingUnitsValue).maximumSizeValue <= iVar5) break;
        if ((this->attackingUnitsValue).value[iVar5] == iVar8) goto LAB_004192f2;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar9);
    }
    if ((this->attackingUnitsValue).maximumSizeValue + -1 < iVar9) {
      iVar9 = iVar9 + 1;
      piVar6 = (int *)operator_new(iVar9 * 4);
      if (piVar6 != (int *)0x0) {
        iVar5 = 0;
        if (0 < (this->attackingUnitsValue).maximumSizeValue) {
          do {
            if (iVar9 <= iVar5) break;
            iVar7 = iVar5 + 1;
            piVar6[iVar5] = (this->attackingUnitsValue).value[iVar5];
            iVar5 = iVar7;
          } while (iVar7 < (this->attackingUnitsValue).maximumSizeValue);
        }
        operator_delete((this->attackingUnitsValue).value);
        (this->attackingUnitsValue).value = piVar6;
        (this->attackingUnitsValue).maximumSizeValue = iVar9;
      }
    }
    (this->attackingUnitsValue).value[(this->attackingUnitsValue).numberValue] = iVar8;
    (this->attackingUnitsValue).numberValue = (this->attackingUnitsValue).numberValue + 1;
LAB_004192f2:
    (**(code **)(this->objectValue->_padding_ + 0xec))(1);
    return 2;
  case 699:
    iVar9 = (this->attackingUnitsValue).numberValue;
    iVar8 = 0;
    if (0 < iVar9) {
      while (iVar8 < (this->attackingUnitsValue).maximumSizeValue) {
        if ((this->attackingUnitsValue).value[iVar8] == param_1->caller) {
          iVar9 = (this->attackingUnitsValue).maximumSizeValue;
          iVar8 = 0;
          if (iVar9 < 1) goto LAB_00419362;
          piVar6 = (this->attackingUnitsValue).value;
          goto LAB_00419356;
        }
        iVar8 = iVar8 + 1;
        if (iVar9 <= iVar8) {
          return 2;
        }
      }
    }
    goto switchD_004180e8_caseD_1f6;
  }
  (**(code **)(iVar9 + 0x58))(uVar15);
  (**(code **)(iVar9 + 0x1c))(param_1);
switchD_004180e8_caseD_1f6:
  return 2;
  while( true ) {
    iVar8 = iVar8 + 1;
    piVar6 = piVar6 + 1;
    if (iVar9 <= iVar8) break;
LAB_00419356:
    if (*piVar6 == param_1->caller) break;
  }
LAB_00419362:
  if (iVar9 <= iVar8) {
    return 2;
  }
  if (iVar8 < iVar9 + -1) {
    do {
      piVar6 = (this->attackingUnitsValue).value;
      iVar9 = iVar8 + 1;
      piVar6[iVar8] = piVar6[iVar9];
      iVar8 = iVar9;
    } while (iVar9 < (this->attackingUnitsValue).maximumSizeValue + -1);
  }
  iVar9 = (this->attackingUnitsValue).numberValue + -1;
  (this->attackingUnitsValue).numberValue = iVar9;
  if (-1 < iVar9) {
    return 2;
  }
  (this->attackingUnitsValue).numberValue = 0;
  return 2;
}

// --------------------------------------------------

// Function: processGroupNotify
// Address: 00419510
/* WARNING: Variable defined which should be unmapped: phase */
/* protected: virtual void __thiscall UnitAIModule::processGroupNotify(struct NotifyEvent *) */

void __thiscall UnitAIModule::processGroupNotify(UnitAIModule *this,NotifyEvent *param_1)
{
  uchar uVar1;
  uint uVar2;
  byte bVar3;
  AIPlay *this_00;
  AIPlayPhase *this_01;
  AIPlayPhaseTrigger *pAVar4;
  int iVar5;
  AIPlayPhase *phase;
  
  if ((((this->playStatus != (AIPlayStatus *)0x0) &&
       (this_00 = AIPlayBook::play(this->objectValue->owner->world->playbook,
                                   this->playStatus->playNumberValue), this_00 != (AIPlay *)0x0)) &&
      (this_01 = AIPlay::phase(this_00,(uint)this->playStatus->currentPhaseValue),
      this_01 != (AIPlayPhase *)0x0)) && (param_1->mType == 500)) {
    this->playStatus->savedAttackerValue = param_1->caller;
    iVar5 = 0;
    do {
      pAVar4 = AIPlayPhase::trigger(this_01,iVar5);
      if (((pAVar4 != (AIPlayPhaseTrigger *)0x0) && (uVar1 = pAVar4->typeValue, uVar1 != '\0')) &&
         ((uVar1 == '\x05' ||
          ((uVar1 == '\x04' &&
           (uVar2 = pAVar4->value1Value,
           bVar3 = AIPlayStatus::group(this->playStatus,param_1->recipient), uVar2 == bVar3)))))) {
        selectNewPlayPhase(this,(uint)pAVar4->nextPhaseValue,0);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
  }
  return;
}

// --------------------------------------------------

// Function: processIdle
// Address: 004195f0
/* protected: virtual int __thiscall UnitAIModule::processIdle(int) */

int __thiscall UnitAIModule::processIdle(UnitAIModule *this,int param_1)
{
  int iVar1;
  int iVar2;
  
  if ((param_1 == 1) && (iVar1 = (**(code **)(this->_padding_ + 0xdc))(), iVar1 == 8)) {
    return 6;
  }
  iVar1 = this->_padding_;
  iVar2 = (**(code **)(iVar1 + 0x30))(1,0,0);
  if ((iVar2 != -1) && (iVar1 = (**(code **)(iVar1 + 0x5c))(iVar2,1), iVar1 == 1)) {
    return 6;
  }
  return 5;
}

// --------------------------------------------------

// Function: processMisc
// Address: 00419650
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* WARNING: Variable defined which should be unmapped: yDiff */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall UnitAIModule::processMisc(void) */

int __thiscall UnitAIModule::processMisc(UnitAIModule *this)
{
  short sVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  UnitAIModule *pUVar8;
  int iVar9;
  RGE_Static_Object *pRVar10;
  int unaff_ESI;
  float10 fVar11;
  float fVar12;
  float yDiff;
  float local_4;
  
  iVar4 = this->currentOrderValue;
  if (iVar4 == -1) {
    if (this->currentActionValue == -1) {
      iVar4 = -1;
    }
    else {
      iVar4 = this->currentActionValue + 100;
    }
  }
  if (iVar4 == 700) {
    if ((((taskedThisUpdate != 1) &&
         (iVar4 = RGE_Player::computerPlayer(this->objectValue->owner), iVar4 != 0)) &&
        (cVar3 = (**(code **)(this->objectValue->_padding_ + 0x7c))(), cVar3 != '\0')) &&
       ((pRVar10 = lookupObject(this,this->currentTargetValue), pRVar10 == (RGE_Static_Object *)0x0
        || (pRVar10->master_obj->id != 0x114)))) {
      iVar4 = this->_padding_;
      iVar9 = (**(code **)(iVar4 + 0x30))(0,0,0);
      pRVar10 = lookupObject(this,iVar9);
      if ((iVar9 != -1) &&
         ((pRVar10 != (RGE_Static_Object *)0x0 && (iVar9 != this->currentTargetValue)))) {
        sVar1 = pRVar10->master_obj->object_group;
        if ((sVar1 == 3) || (sVar1 == 0x1b)) {
          if (pRVar10->master_obj->id == 0x114) {
            fVar11 = (float10)(**(code **)(this->objectValue->_padding_ + 0x10c))
                                        (1,0,this->currentOrderPriorityValue);
            (**(code **)(iVar4 + 0x10))
                      (this->objectValue->id,700,iVar9,(int)pRVar10->owner->id,pRVar10->world_x,
                       pRVar10->world_y,pRVar10->world_z,(float)fVar11);
          }
        }
        else if (((unaff_ESI == 0) ||
                 (sVar1 = *(short *)(*(int *)(unaff_ESI + 8) + 0x14), sVar1 == 3)) ||
                (sVar1 == 0x1b)) {
          fVar11 = (float10)(**(code **)(this->objectValue->_padding_ + 0x10c))
                                      (1,0,this->currentOrderPriorityValue);
          (**(code **)(iVar4 + 0x10))
                    (this->objectValue->id,700,iVar9,(int)pRVar10->owner->id,pRVar10->world_x,
                     pRVar10->world_y,pRVar10->world_z,(float)fVar11);
          return 9;
        }
      }
    }
  }
  else if (iVar4 == 0x2bd) {
    pRVar10 = (RGE_Static_Object *)0x0;
    if (this->defendTargetValue != -1) {
      pRVar10 = lookupObject(this,this->defendTargetValue);
      if (pRVar10 == (RGE_Static_Object *)0x0) {
        this->defendTargetValue = -1;
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar5 = -1;
          }
          else {
            lVar5 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar5,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x15c0);
        }
        (**(code **)(this->_padding_ + 0x58))(1);
        this->currentOrderValue = -1;
        return 9;
      }
      if (this->currentTargetXValue == -1.0) {
        this->currentTargetXValue = pRVar10->world_x;
        this->currentTargetYValue = pRVar10->world_y;
      }
      if ((2 < pRVar10->object_state) && (pRVar10->owner->id != 0)) {
        this->defendTargetValue = -1;
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar5 = -1;
          }
          else {
            lVar5 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar5,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x15d9);
        }
        goto LAB_004198c8;
      }
    }
    if ((this->currentActionValue != 600) &&
       ((this->currentActionValue != 0x262 ||
        (iVar4 = (**(code **)(this->objectValue->_padding_ + 0x11c))(),
        iVar4 != this->defendTargetValue)))) {
      if (this->defendTargetValue == -1) {
        fVar12 = RGE_Static_Object::distance_to_position
                           (this->objectValue,this->currentTargetXValue,this->currentTargetYValue,
                            this->objectValue->world_z);
      }
      else {
        this->currentTargetXValue = pRVar10->world_x;
        this->currentTargetYValue = pRVar10->world_y;
        this->currentTargetZValue = pRVar10->world_z;
        fVar12 = RGE_Static_Object::distance_to_object(this->objectValue,pRVar10);
      }
      fVar2 = this->desiredTargetDistanceValue;
      if (fVar2 - _DAT_0056ebd4 < fVar12) {
        if (this->defendTargetValue == -1) {
          uVar6 = __ftol();
          uVar7 = __ftol();
          iVar4 = (**(code **)(this->objectValue->_padding_ + 0x198))
                            (uVar6,uVar7,0xffffffff,fVar2,0xffffffff,0,0,0xffffffff,0xffffffff);
          if (iVar4 == 1) {
            (**(code **)(this->_padding_ + 0x90))
                      (this->currentTargetXValue,this->currentTargetYValue,this->currentTargetZValue
                       ,this->desiredTargetDistanceValue,1);
            return 10;
          }
        }
        else {
          iVar4 = (**(code **)(this->objectValue->_padding_ + 0x194))
                            (this->defendTargetValue,fVar2,0,0,0xffffffff,0xffffffff);
          if (iVar4 == 1) {
            (**(code **)(this->_padding_ + 0x94))
                      (this->defendTargetValue,this->desiredTargetDistanceValue,1);
            return 10;
          }
        }
        return 10;
      }
      if ((pRVar10 != (RGE_Static_Object *)0x0) &&
         (pUVar8 = RGE_Static_Object::unitAI(pRVar10), pUVar8 != (UnitAIModule *)0x0)) {
        pUVar8 = RGE_Static_Object::unitAI(pRVar10);
        iVar4 = (**(code **)(pUVar8->_padding_ + 0x3c))(0);
        if (iVar4 != -1) {
          (**(code **)(this->_padding_ + 0x5c))(iVar4,1);
          return 10;
        }
        iVar4 = (**(code **)(this->_padding_ + 0xd4))(0);
        if (iVar4 == 6) {
          return 10;
        }
      }
    }
  }
  else if (iVar4 == 0x2c8) {
    pRVar10 = (RGE_Static_Object *)0x0;
    if ((this->currentTargetValue != -1) &&
       ((pRVar10 = lookupObject(this,this->currentTargetValue), pRVar10 == (RGE_Static_Object *)0x0
        || (2 < pRVar10->object_state)))) {
      this->defendTargetValue = -1;
      removeCurrentTarget(this);
      if (actionFile != (_iobuf *)0x0) {
        if (this->objectValue == (RGE_Static_Object *)0x0) {
          lVar5 = -1;
        }
        else {
          lVar5 = this->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar5,s_C__msdev_work_age1_x1_aiuaimod_c,
                0x1582);
        (**(code **)(this->_padding_ + 0x58))(1);
        this->currentOrderValue = -1;
        return 9;
      }
LAB_004198c8:
      (**(code **)(this->_padding_ + 0x58))(1);
      this->currentOrderValue = -1;
      return 9;
    }
    if (pRVar10 == (RGE_Static_Object *)0x0) {
      local_4 = -10.0;
      fVar12 = _DAT_0056ebf8;
    }
    else {
      local_4 = pRVar10->world_y - this->currentTargetYValue;
      fVar12 = pRVar10->world_x - this->currentTargetXValue;
    }
    if ((((fVar12 < (float)_DAT_0056ec00) || ((float)_DAT_0056ec08 < fVar12)) ||
        (local_4 < (float)_DAT_0056ec00)) || ((float)_DAT_0056ec08 < local_4)) {
      if (this->currentTargetValue == -1) {
        fVar12 = RGE_Static_Object::distance_to_position
                           (this->objectValue,this->currentTargetXValue,this->currentTargetYValue,
                            this->objectValue->world_z);
      }
      else {
        this->currentTargetXValue = pRVar10->world_x;
        this->currentTargetYValue = pRVar10->world_y;
        this->currentTargetZValue = pRVar10->world_z;
        fVar12 = RGE_Static_Object::distance_to_object(this->objectValue,pRVar10);
      }
      fVar2 = this->desiredTargetDistanceValue;
      if (fVar2 < fVar12) {
        if (this->currentTargetValue == -1) {
          (**(code **)(this->_padding_ + 0x90))
                    (this->currentTargetXValue,this->currentTargetYValue,this->currentTargetZValue,
                     fVar2,1);
          return 10;
        }
        (**(code **)(this->_padding_ + 0x94))(this->currentTargetValue,fVar2);
        return 10;
      }
    }
  }
  return 9;
}

// --------------------------------------------------

// Function: processRetryableOrder
// Address: 00419bc0
/* protected: virtual int __thiscall UnitAIModule::processRetryableOrder(void) */

int __thiscall UnitAIModule::processRetryableOrder(UnitAIModule *this)
{
  int iVar1;
  int iVar2;
  
  iVar2 = this->_padding_;
  iVar1 = (**(code **)(iVar2 + 0x28))(this->lastOrderValue);
  if (iVar1 == 1) {
    iVar1 = (**(code **)(iVar2 + 0x40))
                      (this->lastTargetTypeValue,0xffffffff,0xffffffff,0xffffffff,0);
    if (iVar1 != -1) {
      if (this->lastOrderValue == 0x2c5) {
        iVar2 = (**(code **)(iVar2 + 0x68))(iVar1,0);
        return 8 - (uint)(iVar2 != 1);
      }
      if (this->lastOrderValue == 0x2c9) {
        iVar2 = (**(code **)(iVar2 + 100))(iVar1,0);
        return 8 - (uint)(iVar2 != 1);
      }
    }
  }
  return 7;
}

// --------------------------------------------------

// Function: addToOrderQueue
// Address: 00419c30
/* protected: int __thiscall UnitAIModule::addToOrderQueue(struct OrderEvent *,int) */

int __thiscall UnitAIModule::addToOrderQueue(UnitAIModule *this,OrderEvent *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = addToOrderQueue(this,param_1->issuer,param_1->orderType,param_1->target,
                          param_1->targetOwner,param_1->targetX,param_1->targetY,param_1->targetZ,
                          param_1->range,param_2,param_1->priority);
  return iVar1;
}

// --------------------------------------------------

// Function: addToOrderQueue
// Address: 00419c70
/* protected: int __thiscall
   UnitAIModule::addToOrderQueue(int,int,int,int,float,float,float,float,int,int) */

int __thiscall
UnitAIModule::addToOrderQueue
          (UnitAIModule *this,int param_1,int param_2,int param_3,int param_4,float param_5,
          float param_6,float param_7,float param_8,int param_9,int param_10)
{
  OrderEvent *pOVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (this->orderQueueMaxSizeValue == this->orderQueueSizeValue) {
    pOVar1 = (OrderEvent *)operator_new(this->orderQueueMaxSizeValue * 0x48);
    if (pOVar1 == (OrderEvent *)0x0) {
      return 0;
    }
    iVar4 = 0;
    if (0 < this->orderQueueSizeValue) {
      iVar2 = 0;
      piVar3 = &pOVar1->priority;
      do {
        iVar4 = iVar4 + 1;
        ((OrderEvent *)(piVar3 + -2))->issuer =
             *(int *)((int)&this->orderQueueValue->issuer + iVar2);
        piVar3[-1] = *(int *)((int)&this->orderQueueValue->orderType + iVar2);
        *piVar3 = *(int *)((int)&this->orderQueueValue->priority + iVar2);
        piVar3[1] = *(int *)((int)&this->orderQueueValue->target + iVar2);
        piVar3[2] = *(int *)((int)&this->orderQueueValue->targetOwner + iVar2);
        piVar3[3] = (int)*(float *)((int)&this->orderQueueValue->targetX + iVar2);
        piVar3[4] = (int)*(float *)((int)&this->orderQueueValue->targetY + iVar2);
        piVar3[5] = (int)*(float *)((int)&this->orderQueueValue->targetZ + iVar2);
        piVar3[6] = (int)*(float *)((int)&this->orderQueueValue->range + iVar2);
        iVar2 = iVar2 + 0x24;
        piVar3 = piVar3 + 9;
      } while (iVar4 < this->orderQueueSizeValue);
    }
    if (this->orderQueueValue != (OrderEvent *)0x0) {
      operator_delete(this->orderQueueValue);
    }
    this->orderQueueValue = pOVar1;
    this->orderQueueMaxSizeValue = this->orderQueueMaxSizeValue << 1;
  }
  if ((param_9 != 0) && (this->orderQueueSizeValue != 0)) {
    iVar4 = 0;
    if (0 < this->orderQueueSizeValue) {
      iVar2 = 0;
      do {
        *(undefined4 *)((int)&this->orderQueueValue[1].issuer + iVar2) =
             *(undefined4 *)((int)&this->orderQueueValue->issuer + iVar2);
        *(undefined4 *)((int)&this->orderQueueValue[1].orderType + iVar2) =
             *(undefined4 *)((int)&this->orderQueueValue->orderType + iVar2);
        *(undefined4 *)((int)&this->orderQueueValue[1].priority + iVar2) =
             *(undefined4 *)((int)&this->orderQueueValue->priority + iVar2);
        *(undefined4 *)((int)&this->orderQueueValue[1].target + iVar2) =
             *(undefined4 *)((int)&this->orderQueueValue->target + iVar2);
        *(undefined4 *)((int)&this->orderQueueValue[1].targetOwner + iVar2) =
             *(undefined4 *)((int)&this->orderQueueValue->targetOwner + iVar2);
        *(undefined4 *)((int)&this->orderQueueValue[1].targetX + iVar2) =
             *(undefined4 *)((int)&this->orderQueueValue->targetX + iVar2);
        *(undefined4 *)((int)&this->orderQueueValue[1].targetY + iVar2) =
             *(undefined4 *)((int)&this->orderQueueValue->targetY + iVar2);
        *(undefined4 *)((int)&this->orderQueueValue[1].targetZ + iVar2) =
             *(undefined4 *)((int)&this->orderQueueValue->targetZ + iVar2);
        iVar4 = iVar4 + 1;
        *(undefined4 *)((int)&this->orderQueueValue[1].range + iVar2) =
             *(undefined4 *)((int)&this->orderQueueValue->range + iVar2);
        iVar2 = iVar2 + 0x24;
      } while (iVar4 < this->orderQueueSizeValue);
    }
    this->orderQueueValue->issuer = param_1;
    this->orderQueueValue->orderType = param_2;
    this->orderQueueValue->priority = param_10;
    this->orderQueueValue->target = param_3;
    this->orderQueueValue->targetOwner = param_4;
    this->orderQueueValue->targetX = param_5;
    this->orderQueueValue->targetY = param_6;
    this->orderQueueValue->targetZ = param_7;
    this->orderQueueValue->range = param_8;
    this->orderQueueSizeValue = this->orderQueueSizeValue + 1;
    return 1;
  }
  this->orderQueueValue[this->orderQueueSizeValue].issuer = param_1;
  this->orderQueueValue[this->orderQueueSizeValue].orderType = param_2;
  this->orderQueueValue[this->orderQueueSizeValue].priority = param_10;
  this->orderQueueValue[this->orderQueueSizeValue].target = param_3;
  this->orderQueueValue[this->orderQueueSizeValue].targetOwner = param_4;
  this->orderQueueValue[this->orderQueueSizeValue].targetX = param_5;
  this->orderQueueValue[this->orderQueueSizeValue].targetY = param_6;
  this->orderQueueValue[this->orderQueueSizeValue].targetZ = param_7;
  this->orderQueueValue[this->orderQueueSizeValue].range = param_8;
  this->orderQueueSizeValue = this->orderQueueSizeValue + 1;
  return 1;
}

// --------------------------------------------------

// Function: addToNotifyQueue
// Address: 00419ed0
/* protected: int __thiscall UnitAIModule::addToNotifyQueue(struct NotifyEvent *) */

int __thiscall UnitAIModule::addToNotifyQueue(UnitAIModule *this,NotifyEvent *param_1)
{
  int iVar1;
  
  iVar1 = addToNotifyQueue(this,param_1->caller,param_1->recipient,param_1->mType,param_1->p1,
                           param_1->p2,param_1->p3);
  return iVar1;
}

// --------------------------------------------------

// Function: addToNotifyQueue
// Address: 00419f00
/* protected: int __thiscall UnitAIModule::addToNotifyQueue(int,int,int,long,long,long) */

int __thiscall
UnitAIModule::addToNotifyQueue
          (UnitAIModule *this,int param_1,int param_2,int param_3,long param_4,long param_5,
          long param_6)
{
  NotifyEvent *pNVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (this->notifyQueueMaxSizeValue == this->notifyQueueSizeValue) {
    pNVar1 = (NotifyEvent *)operator_new(this->notifyQueueMaxSizeValue * 0x30);
    if (pNVar1 == (NotifyEvent *)0x0) {
      return 0;
    }
    iVar4 = 0;
    if (0 < this->notifyQueueSizeValue) {
      iVar2 = 0;
      piVar3 = &pNVar1->mType;
      do {
        iVar4 = iVar4 + 1;
        ((NotifyEvent *)(piVar3 + -2))->caller =
             *(int *)((int)&this->notifyQueueValue->caller + iVar2);
        piVar3[-1] = *(int *)((int)&this->notifyQueueValue->recipient + iVar2);
        *piVar3 = *(int *)((int)&this->notifyQueueValue->mType + iVar2);
        piVar3[1] = *(long *)((int)&this->notifyQueueValue->p1 + iVar2);
        piVar3[2] = *(long *)((int)&this->notifyQueueValue->p2 + iVar2);
        piVar3[3] = *(long *)((int)&this->notifyQueueValue->p3 + iVar2);
        iVar2 = iVar2 + 0x18;
        piVar3 = piVar3 + 6;
      } while (iVar4 < this->notifyQueueSizeValue);
    }
    if (this->notifyQueueValue != (NotifyEvent *)0x0) {
      operator_delete(this->notifyQueueValue);
    }
    this->notifyQueueValue = pNVar1;
    this->notifyQueueMaxSizeValue = this->notifyQueueMaxSizeValue << 1;
  }
  this->notifyQueueValue[this->notifyQueueSizeValue].caller = param_1;
  this->notifyQueueValue[this->notifyQueueSizeValue].recipient = param_2;
  this->notifyQueueValue[this->notifyQueueSizeValue].mType = param_3;
  this->notifyQueueValue[this->notifyQueueSizeValue].p1 = param_4;
  this->notifyQueueValue[this->notifyQueueSizeValue].p2 = param_5;
  this->notifyQueueValue[this->notifyQueueSizeValue].p3 = param_6;
  this->notifyQueueSizeValue = this->notifyQueueSizeValue + 1;
  return 1;
}

// --------------------------------------------------

// Function: purgeNotifyQueue
// Address: 0041a020
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* public: void __thiscall UnitAIModule::purgeNotifyQueue(unsigned long) */

void __thiscall UnitAIModule::purgeNotifyQueue(UnitAIModule *this,ulong param_1)
{
  long lVar1;
  long *plVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < this->notifyQueueSizeValue) {
    plVar2 = &this->notifyQueueValue->p1;
    do {
      if (((plVar2[-1] == 0x1fa) &&
          (((*plVar2 != 0x262 || (this->currentActionValue == 0x262)) ||
           (this->currentActionValue == 0x268)))) &&
         ((this->currentOrderValue == -1 && (this->currentActionValue == *plVar2)))) {
        removeCurrentTarget(this);
        if (actionFile != (_iobuf *)0x0) {
          if (this->objectValue == (RGE_Static_Object *)0x0) {
            lVar1 = -1;
          }
          else {
            lVar1 = this->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar1,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x170e);
        }
        (**(code **)(this->_padding_ + 0x58))(1);
        break;
      }
      iVar3 = iVar3 + 1;
      plVar2 = plVar2 + 6;
    } while (iVar3 < this->notifyQueueSizeValue);
  }
  this->notifyQueueSizeValue = 0;
  this->lastUpdateTimeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: lookupObject
// Address: 0041a0d0
/* protected: class RGE_Static_Object * __thiscall UnitAIModule::lookupObject(int) */

RGE_Static_Object * __thiscall UnitAIModule::lookupObject(UnitAIModule *this,int param_1)
{
  RGE_Player *pRVar1;
  RGE_Game_World *this_00;
  RGE_Static_Object *pRVar2;
  
  if (((this->objectValue != (RGE_Static_Object *)0x0) &&
      (pRVar1 = this->objectValue->owner, pRVar1 != (RGE_Player *)0x0)) &&
     (this_00 = pRVar1->world, this_00 != (RGE_Game_World *)0x0)) {
    pRVar2 = RGE_Game_World::object(this_00,param_1);
    return pRVar2;
  }
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: logDebug
// Address: 0041a100
/* WARNING: Variable defined which should be unmapped: textOut */
/* public: virtual void __cdecl UnitAIModule::logDebug(char *,...) */

void __thiscall UnitAIModule::logDebug(UnitAIModule *this,char *param_1,...)
{
  undefined4 in_stack_00000008;
  char textOut [1024];
  
  if (*(int *)(param_1 + 4) != 0) {
    vsprintf(textOut + 4,in_stack_00000008,&stack0x0000000c);
    (**(code **)(**(int **)(param_1 + 4) + 0x144))(*(int **)(param_1 + 4),textOut + 4);
  }
  return;
}

// --------------------------------------------------

