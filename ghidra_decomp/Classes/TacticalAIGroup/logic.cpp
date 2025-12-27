// Class: TacticalAIGroup
// Function: TacticalAIGroup
// Address: 004ea860
/* public: __thiscall TacticalAIGroup::TacticalAIGroup(void) */

TacticalAIGroup * __thiscall TacticalAIGroup::TacticalAIGroup(TacticalAIGroup *this)
{
  int *piVar1;
  int iVar2;
  
  this->idValue = -1;
  this->inUseValue = 0;
  this->typeValue = -1;
  this->subTypeValue = -1;
  this->numberUnitsValue = 0;
  this->desiredNumberUnitsValue = 0;
  this->commanderValue = -1;
  this->originalHitPointsValue = -1;
  this->originalUnitNumberValue = -1;
  this->actionValue = 0;
  this->targetValue = -1;
  this->targetTypeValue = -1;
  this->priorityValue = 0;
  this->waitCodeValue = -1;
  this->assistGroupIDValue = -1;
  this->assistGroupTypeValue = -1;
  this->consecutiveIdleUnitCountValue = 0;
  this->playNumberValue = -1;
  this->numberAttackWaypointsValue = '\0';
  this->currentAttackWaypointValue = '\0';
  this->consecutiveGatherAttemptsValue = '\0';
  this->numberObjectsToDestroyValue = 0;
  this->objectsToDestroyOwnerValue = -1;
  this->objectsToDestroyCommanderZoneValue = -1;
  this->lastAttackRoundupTime = 0;
  this->lastAddedUnitTimeValue = 0;
  this->_padding_ = (int)&_vftable_;
  setTargetLocation(this,-1.0,-1.0,-1.0);
  setGatherLocation(this,-1.0,-1.0,-1.0);
  setRetreatLocation(this,-1.0,-1.0,-1.0);
  setLocation(this,-1.0,-1.0,-1.0);
  piVar1 = this->unitsOriginalHitPointsValue;
  iVar2 = 0x28;
  do {
    piVar1[-0x28] = -1;
    *piVar1 = -1;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar1 = this->objectsToDestroyValue;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar1 = -1;
    piVar1 = piVar1 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004ea990
/* public: virtual void * __thiscall TacticalAIGroup::`scalar deleting destructor'(unsigned int) */

void * __thiscall TacticalAIGroup::_scalar_deleting_destructor_(TacticalAIGroup *this,uint param_1)
{
  ~TacticalAIGroup(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TacticalAIGroup
// Address: 004ea9b0
/* public: virtual __thiscall TacticalAIGroup::~TacticalAIGroup(void) */

void __thiscall TacticalAIGroup::~TacticalAIGroup(TacticalAIGroup *this)
{
  this->_padding_ = (int)&_vftable_;
  return;
}

// --------------------------------------------------

// Function: load
// Address: 004ea9c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TacticalAIGroup::load(int) */

int __thiscall TacticalAIGroup::load(TacticalAIGroup *this,int param_1)
{
  int *piVar1;
  int iVar2;
  
  rge_read(param_1,&this->idValue,4);
  rge_read(param_1,&this->inUseValue,4);
  piVar1 = this->unitsOriginalHitPointsValue;
  iVar2 = 0x28;
  do {
    rge_read(param_1,piVar1 + -0x28,4);
    rge_read(param_1,piVar1,4);
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  rge_read(param_1,&this->numberUnitsValue,4);
  rge_read(param_1,&this->desiredNumberUnitsValue,4);
  rge_read(param_1,&this->commanderValue,4);
  rge_read(param_1,&this->originalHitPointsValue,4);
  rge_read(param_1,&this->originalUnitNumberValue,4);
  rge_read(param_1,&this->locationValue,0x10);
  rge_read(param_1,&this->actionValue,4);
  rge_read(param_1,&this->targetValue,4);
  rge_read(param_1,&this->targetTypeValue,4);
  rge_read(param_1,&this->targetLocationValue,0x10);
  rge_read(param_1,&this->gatherLocationValue,0x10);
  rge_read(param_1,&this->retreatLocationValue,0x10);
  rge_read(param_1,&this->priorityValue,4);
  rge_read(param_1,&this->waitCodeValue,4);
  rge_read(param_1,&this->assistGroupIDValue,4);
  rge_read(param_1,&this->assistGroupTypeValue,4);
  rge_read(param_1,&this->typeValue,4);
  rge_read(param_1,&this->subTypeValue,4);
  rge_read(param_1,&this->consecutiveIdleUnitCountValue,4);
  rge_read(param_1,&this->numberAttackWaypointsValue,1);
  rge_read(param_1,&this->currentAttackWaypointValue,1);
  rge_read(param_1,this->attackWaypoints,0xf0);
  rge_read(param_1,&this->playNumberValue,4);
  if (save_game_version < _DAT_005756e0) {
    this->consecutiveGatherAttemptsValue = '\0';
  }
  else {
    rge_read(param_1,&this->consecutiveGatherAttemptsValue,1);
  }
  if (_DAT_005756e4 <= save_game_version) {
    rge_read(param_1,&this->numberObjectsToDestroyValue,4);
    rge_read(param_1,this->objectsToDestroyValue,0x50);
    rge_read(param_1,&this->objectsToDestroyOwnerValue,4);
    rge_read(param_1,&this->objectsToDestroyCommanderZoneValue,4);
  }
  if (_DAT_005756e8 <= save_game_version) {
    rge_read(param_1,&this->lastAttackRoundupTime,4);
  }
  if (_DAT_005756ec <= save_game_version) {
    rge_read(param_1,&this->lastAddedUnitTimeValue,4);
  }
  return 1;
}

// --------------------------------------------------

// Function: save
// Address: 004eaca0
/* public: int __thiscall TacticalAIGroup::save(int) */

int __thiscall TacticalAIGroup::save(TacticalAIGroup *this,int param_1)
{
  int *piVar1;
  int iVar2;
  
  rge_write(param_1,&this->idValue,4);
  rge_write(param_1,&this->inUseValue,4);
  piVar1 = this->unitsOriginalHitPointsValue;
  iVar2 = 0x28;
  do {
    rge_write(param_1,piVar1 + -0x28,4);
    rge_write(param_1,piVar1,4);
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  rge_write(param_1,&this->numberUnitsValue,4);
  rge_write(param_1,&this->desiredNumberUnitsValue,4);
  rge_write(param_1,&this->commanderValue,4);
  rge_write(param_1,&this->originalHitPointsValue,4);
  rge_write(param_1,&this->originalUnitNumberValue,4);
  rge_write(param_1,&this->locationValue,0x10);
  rge_write(param_1,&this->actionValue,4);
  rge_write(param_1,&this->targetValue,4);
  rge_write(param_1,&this->targetTypeValue,4);
  rge_write(param_1,&this->targetLocationValue,0x10);
  rge_write(param_1,&this->gatherLocationValue,0x10);
  rge_write(param_1,&this->retreatLocationValue,0x10);
  rge_write(param_1,&this->priorityValue,4);
  rge_write(param_1,&this->waitCodeValue,4);
  rge_write(param_1,&this->assistGroupIDValue,4);
  rge_write(param_1,&this->assistGroupTypeValue,4);
  rge_write(param_1,&this->typeValue,4);
  rge_write(param_1,&this->subTypeValue,4);
  rge_write(param_1,&this->consecutiveIdleUnitCountValue,4);
  rge_write(param_1,&this->numberAttackWaypointsValue,1);
  rge_write(param_1,&this->currentAttackWaypointValue,1);
  rge_write(param_1,this->attackWaypoints,0xf0);
  rge_write(param_1,&this->playNumberValue,4);
  rge_write(param_1,&this->consecutiveGatherAttemptsValue,1);
  rge_write(param_1,&this->numberObjectsToDestroyValue,4);
  rge_write(param_1,this->objectsToDestroyValue,0x50);
  rge_write(param_1,&this->objectsToDestroyOwnerValue,4);
  rge_write(param_1,&this->objectsToDestroyCommanderZoneValue,4);
  rge_write(param_1,&this->lastAttackRoundupTime,4);
  rge_write(param_1,&this->lastAddedUnitTimeValue,4);
  return 1;
}

// --------------------------------------------------

// Function: id
// Address: 004eaf20
/* public: int __thiscall TacticalAIGroup::id(void)const  */

int __thiscall TacticalAIGroup::id(TacticalAIGroup *this)
{
  return this->idValue;
}

// --------------------------------------------------

// Function: setID
// Address: 004eaf30
/* public: void __thiscall TacticalAIGroup::setID(int) */

void __thiscall TacticalAIGroup::setID(TacticalAIGroup *this,int param_1)
{
  this->idValue = param_1;
  return;
}

// --------------------------------------------------

// Function: inUse
// Address: 004eaf40
/* public: int __thiscall TacticalAIGroup::inUse(void)const  */

int __thiscall TacticalAIGroup::inUse(TacticalAIGroup *this)
{
  return this->inUseValue;
}

// --------------------------------------------------

// Function: setInUse
// Address: 004eaf50
/* public: void __thiscall TacticalAIGroup::setInUse(int) */

void __thiscall TacticalAIGroup::setInUse(TacticalAIGroup *this,int param_1)
{
  this->inUseValue = param_1;
  return;
}

// --------------------------------------------------

// Function: type
// Address: 004eaf60
/* public: int __thiscall TacticalAIGroup::type(void)const  */

int __thiscall TacticalAIGroup::type(TacticalAIGroup *this)
{
  return this->typeValue;
}

// --------------------------------------------------

// Function: setType
// Address: 004eaf70
/* public: void __thiscall TacticalAIGroup::setType(int) */

void __thiscall TacticalAIGroup::setType(TacticalAIGroup *this,int param_1)
{
  this->typeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: subType
// Address: 004eaf80
/* public: int __thiscall TacticalAIGroup::subType(void)const  */

int __thiscall TacticalAIGroup::subType(TacticalAIGroup *this)
{
  return this->subTypeValue;
}

// --------------------------------------------------

// Function: setSubType
// Address: 004eaf90
/* public: void __thiscall TacticalAIGroup::setSubType(int) */

void __thiscall TacticalAIGroup::setSubType(TacticalAIGroup *this,int param_1)
{
  this->subTypeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: addUnit
// Address: 004eafa0
/* public: int __thiscall TacticalAIGroup::addUnit(int,class TribeMainDecisionAIModule *) */

int __thiscall
TacticalAIGroup::addUnit(TacticalAIGroup *this,int param_1,TribeMainDecisionAIModule *param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = this->unitsValue;
  do {
    if (*piVar2 == -1) {
      this->unitsValue[iVar1] = param_1;
      this->unitsOriginalHitPointsValue[iVar1] = -1;
      this->numberUnitsValue = this->numberUnitsValue + 1;
      if (this->commanderValue != -1) {
        (**(code **)(*(int *)param_2->_padding_ + 200))(this->commanderValue,param_1,0x40800000);
      }
      this->lastAddedUnitTimeValue = *(ulong *)(*(int *)(param_2->_padding_ + 0x3c) + 4);
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0x28);
  return 0;
}

// --------------------------------------------------

// Function: removeUnit
// Address: 004eb030
/* public: int __thiscall TacticalAIGroup::removeUnit(int,class TribeMainDecisionAIModule *) */

int __thiscall
TacticalAIGroup::removeUnit(TacticalAIGroup *this,int param_1,TribeMainDecisionAIModule *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = this->unitsValue;
  do {
    if (*piVar2 == param_1) {
      iVar1 = this->commanderValue;
      if (param_1 == iVar1) {
        setSpecificCommander(this,-1,param_2);
      }
      else if (iVar1 != -1) {
        (**(code **)(*(int *)param_2->_padding_ + 0xcc))(iVar1,param_1);
      }
      this->unitsValue[iVar3] = -1;
      this->unitsOriginalHitPointsValue[iVar3] = -1;
      this->numberUnitsValue = this->numberUnitsValue + -1;
      return 1;
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar3 < 0x28);
  return 0;
}

// --------------------------------------------------

// Function: removeUnitByIndex
// Address: 004eb0c0
/* public: int __thiscall TacticalAIGroup::removeUnitByIndex(int,class TribeMainDecisionAIModule *)
    */

int __thiscall
TacticalAIGroup::removeUnitByIndex
          (TacticalAIGroup *this,int param_1,TribeMainDecisionAIModule *param_2)
{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 < 0x28)) {
    iVar1 = this->commanderValue;
    if (this->unitsValue[param_1] == iVar1) {
      setSpecificCommander(this,-1,param_2);
    }
    else if (iVar1 != -1) {
      (**(code **)(*(int *)param_2->_padding_ + 0xcc))(iVar1,this->unitsValue[param_1]);
    }
    this->unitsValue[param_1] = -1;
    this->unitsOriginalHitPointsValue[param_1] = -1;
    this->numberUnitsValue = this->numberUnitsValue + -1;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: removeUnits
// Address: 004eb140
/* public: void __thiscall TacticalAIGroup::removeUnits(class TribeMainDecisionAIModule *) */

void __thiscall
TacticalAIGroup::removeUnits(TacticalAIGroup *this,TribeMainDecisionAIModule *param_1)
{
  int *piVar1;
  int iVar2;
  
  setSpecificCommander(this,-1,param_1);
  this->numberUnitsValue = 0;
  piVar1 = this->unitsOriginalHitPointsValue;
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

// Function: removeExtraUnits
// Address: 004eb180
/* public: int __thiscall TacticalAIGroup::removeExtraUnits(class TribeMainDecisionAIModule *) */

int __thiscall
TacticalAIGroup::removeExtraUnits(TacticalAIGroup *this,TribeMainDecisionAIModule *param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = this->numberUnitsValue;
  if ((this->desiredNumberUnitsValue < iVar1) && (0 < iVar1)) {
    iVar3 = 0;
    if (this->desiredNumberUnitsValue < iVar1) {
      piVar2 = this->unitsValue;
      do {
        if (0x27 < iVar3) {
          return 1;
        }
        if (*piVar2 != -1) {
          removeUnitByIndex(this,iVar3,param_1);
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (this->desiredNumberUnitsValue < this->numberUnitsValue);
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: removeUnboardedUnits
// Address: 004eb1f0
/* public: int __thiscall TacticalAIGroup::removeUnboardedUnits(class TribeTacticalAIModule *,class
   TribeMainDecisionAIModule *) */

int __thiscall
TacticalAIGroup::removeUnboardedUnits
          (TacticalAIGroup *this,TribeTacticalAIModule *param_1,TribeMainDecisionAIModule *param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int *piVar3;
  int local_4;
  
  local_4 = 0x28;
  piVar3 = this->unitsValue;
  do {
    if (*piVar3 != -1) {
      pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar3);
      if ((pRVar2 == (RGE_Static_Object *)0x0) || (pRVar2->inside_obj == (RGE_Static_Object *)0x0))
{
        iVar1 = this->commanderValue;
        if (*piVar3 == iVar1) {
          setSpecificCommander(this,-1,param_2);
        }
        else if (iVar1 != -1) {
          (**(code **)(*(int *)param_2->_padding_ + 0xcc))(iVar1,*piVar3);
        }
        TribeTacticalAIModule::stopUnit(param_1,*piVar3,100);
        *piVar3 = -1;
        piVar3[0x28] = -1;
        this->numberUnitsValue = this->numberUnitsValue + -1;
      }
    }
    piVar3 = piVar3 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return 1;
}

// --------------------------------------------------

// Function: containsUnit
// Address: 004eb290
/* public: int __thiscall TacticalAIGroup::containsUnit(int) */

int __thiscall TacticalAIGroup::containsUnit(TacticalAIGroup *this,int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = this->unitsValue;
  do {
    if (*piVar2 == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0x28);
  return 0;
}

// --------------------------------------------------

// Function: numberUnits
// Address: 004eb2c0
/* public: int __thiscall TacticalAIGroup::numberUnits(void) */

int __thiscall TacticalAIGroup::numberUnits(TacticalAIGroup *this)
{
  return this->numberUnitsValue;
}

// --------------------------------------------------

// Function: unit
// Address: 004eb2d0
/* public: int __thiscall TacticalAIGroup::unit(int) */

int __thiscall TacticalAIGroup::unit(TacticalAIGroup *this,int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = -1;
  piVar2 = this->unitsValue;
  while( true ) {
    if (param_1 + 1 <= iVar3) {
      return -1;
    }
    if (*piVar2 != -1) {
      iVar3 = iVar3 + 1;
    }
    if (iVar3 == param_1) break;
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
    if (0x27 < iVar1) {
      return -1;
    }
  }
  return this->unitsValue[iVar1];
}

// --------------------------------------------------

// Function: unitOriginalHitPoints
// Address: 004eb320
/* public: int __thiscall TacticalAIGroup::unitOriginalHitPoints(int) */

int __thiscall TacticalAIGroup::unitOriginalHitPoints(TacticalAIGroup *this,int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = -1;
  piVar2 = this->unitsValue;
  while( true ) {
    if (param_1 + 1 <= iVar3) {
      return -1;
    }
    if (*piVar2 != -1) {
      iVar3 = iVar3 + 1;
    }
    if (iVar3 == param_1) break;
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
    if (0x27 < iVar1) {
      return -1;
    }
  }
  return this->unitsOriginalHitPointsValue[iVar1];
}

// --------------------------------------------------

// Function: desiredNumberUnits
// Address: 004eb370
/* public: int __thiscall TacticalAIGroup::desiredNumberUnits(void)const  */

int __thiscall TacticalAIGroup::desiredNumberUnits(TacticalAIGroup *this)
{
  return this->desiredNumberUnitsValue;
}

// --------------------------------------------------

// Function: setDesiredNumberUnits
// Address: 004eb380
/* public: void __thiscall TacticalAIGroup::setDesiredNumberUnits(int) */

void __thiscall TacticalAIGroup::setDesiredNumberUnits(TacticalAIGroup *this,int param_1)
{
  this->desiredNumberUnitsValue = param_1;
  return;
}

// --------------------------------------------------

// Function: commander
// Address: 004eb390
/* public: int __thiscall TacticalAIGroup::commander(void)const  */

int __thiscall TacticalAIGroup::commander(TacticalAIGroup *this)
{
  return this->commanderValue;
}

// --------------------------------------------------

// Function: setSpecificCommander
// Address: 004eb3a0
/* WARNING: Variable defined which should be unmapped: temp */
/* public: void __thiscall TacticalAIGroup::setSpecificCommander(int,class TribeMainDecisionAIModule
   *) */

void __thiscall
TacticalAIGroup::setSpecificCommander
          (TacticalAIGroup *this,int param_1,TribeMainDecisionAIModule *param_2)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int temp [40];
  
  if (this->commanderValue != -1) {
    (**(code **)(*(int *)param_2->_padding_ + 0xd0))(this->commanderValue);
  }
  this->commanderValue = param_1;
  if (param_1 != -1) {
    piVar2 = this->unitsValue;
    iVar5 = 0;
    piVar3 = temp + 1;
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
    (**(code **)(*(int *)param_2->_padding_ + 0xc4))(param_1,temp + 1,iVar5,0x40800000);
  }
  return;
}

// --------------------------------------------------

// Function: currentHitPoints
// Address: 004eb430
/* public: int __thiscall TacticalAIGroup::currentHitPoints(class TribeMainDecisionAIModule *)const
    */

int __thiscall
TacticalAIGroup::currentHitPoints(TacticalAIGroup *this,TribeMainDecisionAIModule *param_1)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  piVar5 = this->unitsValue;
  iVar3 = 0x28;
  do {
    if (*piVar5 != -1) {
      pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1,*piVar5);
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

// Function: originalHitPoints
// Address: 004eb470
/* public: int __thiscall TacticalAIGroup::originalHitPoints(void)const  */

int __thiscall TacticalAIGroup::originalHitPoints(TacticalAIGroup *this)
{
  return this->originalHitPointsValue;
}

// --------------------------------------------------

// Function: setOriginalHitPoints
// Address: 004eb480
/* public: void __thiscall TacticalAIGroup::setOriginalHitPoints(int) */

void __thiscall TacticalAIGroup::setOriginalHitPoints(TacticalAIGroup *this,int param_1)
{
  this->originalHitPointsValue = param_1;
  return;
}

// --------------------------------------------------

// Function: originalUnitNumber
// Address: 004eb490
/* public: int __thiscall TacticalAIGroup::originalUnitNumber(void)const  */

int __thiscall TacticalAIGroup::originalUnitNumber(TacticalAIGroup *this)
{
  return this->originalUnitNumberValue;
}

// --------------------------------------------------

// Function: setOriginalUnitNumber
// Address: 004eb4a0
/* public: void __thiscall TacticalAIGroup::setOriginalUnitNumber(int) */

void __thiscall TacticalAIGroup::setOriginalUnitNumber(TacticalAIGroup *this,int param_1)
{
  this->originalUnitNumberValue = param_1;
  return;
}

// --------------------------------------------------

// Function: location
// Address: 004eb4b0
/* public: struct Waypoint const & __thiscall TacticalAIGroup::location(void)const  */

Waypoint * __thiscall TacticalAIGroup::location(TacticalAIGroup *this)
{
  return &this->locationValue;
}

// --------------------------------------------------

// Function: setLocation
// Address: 004eb4c0
/* public: void __thiscall TacticalAIGroup::setLocation(float,float,float) */

void __thiscall
TacticalAIGroup::setLocation(TacticalAIGroup *this,float param_1,float param_2,float param_3)
{
  (this->locationValue).x = param_1;
  (this->locationValue).y = param_2;
  (this->locationValue).z = param_3;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 004eb4f0
/* public: int __thiscall TacticalAIGroup::action(void)const  */

int __thiscall TacticalAIGroup::action(TacticalAIGroup *this)
{
  return this->actionValue;
}

// --------------------------------------------------

// Function: setAction
// Address: 004eb500
/* public: void __thiscall TacticalAIGroup::setAction(int) */

void __thiscall TacticalAIGroup::setAction(TacticalAIGroup *this,int param_1)
{
  this->actionValue = param_1;
  return;
}

// --------------------------------------------------

// Function: target
// Address: 004eb510
/* public: int __thiscall TacticalAIGroup::target(void)const  */

int __thiscall TacticalAIGroup::target(TacticalAIGroup *this)
{
  return this->targetValue;
}

// --------------------------------------------------

// Function: setTarget
// Address: 004eb520
/* public: void __thiscall TacticalAIGroup::setTarget(int) */

void __thiscall TacticalAIGroup::setTarget(TacticalAIGroup *this,int param_1)
{
  this->targetValue = param_1;
  return;
}

// --------------------------------------------------

// Function: targetType
// Address: 004eb530
/* public: int __thiscall TacticalAIGroup::targetType(void)const  */

int __thiscall TacticalAIGroup::targetType(TacticalAIGroup *this)
{
  return this->targetTypeValue;
}

// --------------------------------------------------

// Function: setTargetType
// Address: 004eb540
/* public: void __thiscall TacticalAIGroup::setTargetType(int) */

void __thiscall TacticalAIGroup::setTargetType(TacticalAIGroup *this,int param_1)
{
  this->targetTypeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: targetLocation
// Address: 004eb550
/* public: struct Waypoint const & __thiscall TacticalAIGroup::targetLocation(void)const  */

Waypoint * __thiscall TacticalAIGroup::targetLocation(TacticalAIGroup *this)
{
  return &this->targetLocationValue;
}

// --------------------------------------------------

// Function: setAllLocations
// Address: 004eb560
/* public: void __thiscall TacticalAIGroup::setAllLocations(float,float,float) */

void __thiscall
TacticalAIGroup::setAllLocations(TacticalAIGroup *this,float param_1,float param_2,float param_3)
{
  (this->locationValue).x = param_1;
  (this->locationValue).y = param_2;
  (this->locationValue).z = param_3;
  (this->gatherLocationValue).x = param_1;
  (this->gatherLocationValue).y = param_2;
  (this->gatherLocationValue).z = param_3;
  (this->retreatLocationValue).x = param_1;
  (this->retreatLocationValue).y = param_2;
  (this->retreatLocationValue).z = param_3;
  return;
}

// --------------------------------------------------

// Function: setTargetLocation
// Address: 004eb5c0
/* public: void __thiscall TacticalAIGroup::setTargetLocation(float,float,float) */

void __thiscall
TacticalAIGroup::setTargetLocation(TacticalAIGroup *this,float param_1,float param_2,float param_3)
{
  (this->targetLocationValue).x = param_1;
  (this->targetLocationValue).y = param_2;
  (this->targetLocationValue).z = param_3;
  return;
}

// --------------------------------------------------

// Function: gatherLocation
// Address: 004eb5f0
/* public: struct Waypoint const & __thiscall TacticalAIGroup::gatherLocation(void)const  */

Waypoint * __thiscall TacticalAIGroup::gatherLocation(TacticalAIGroup *this)
{
  return &this->gatherLocationValue;
}

// --------------------------------------------------

// Function: setGatherLocation
// Address: 004eb600
/* public: void __thiscall TacticalAIGroup::setGatherLocation(float,float,float) */

void __thiscall
TacticalAIGroup::setGatherLocation(TacticalAIGroup *this,float param_1,float param_2,float param_3)
{
  (this->gatherLocationValue).x = param_1;
  (this->gatherLocationValue).y = param_2;
  (this->gatherLocationValue).z = param_3;
  return;
}

// --------------------------------------------------

// Function: retreatLocation
// Address: 004eb630
/* public: struct Waypoint const & __thiscall TacticalAIGroup::retreatLocation(void)const  */

Waypoint * __thiscall TacticalAIGroup::retreatLocation(TacticalAIGroup *this)
{
  return &this->retreatLocationValue;
}

// --------------------------------------------------

// Function: setRetreatLocation
// Address: 004eb640
/* public: void __thiscall TacticalAIGroup::setRetreatLocation(float,float,float) */

void __thiscall
TacticalAIGroup::setRetreatLocation(TacticalAIGroup *this,float param_1,float param_2,float param_3)
{
  (this->retreatLocationValue).x = param_1;
  (this->retreatLocationValue).y = param_2;
  (this->retreatLocationValue).z = param_3;
  return;
}

// --------------------------------------------------

// Function: priority
// Address: 004eb670
/* public: int __thiscall TacticalAIGroup::priority(void)const  */

int __thiscall TacticalAIGroup::priority(TacticalAIGroup *this)
{
  return this->priorityValue;
}

// --------------------------------------------------

// Function: setPriority
// Address: 004eb680
/* public: void __thiscall TacticalAIGroup::setPriority(int) */

void __thiscall TacticalAIGroup::setPriority(TacticalAIGroup *this,int param_1)
{
  this->priorityValue = param_1;
  return;
}

// --------------------------------------------------

// Function: waitCode
// Address: 004eb690
/* public: int __thiscall TacticalAIGroup::waitCode(void)const  */

int __thiscall TacticalAIGroup::waitCode(TacticalAIGroup *this)
{
  return this->waitCodeValue;
}

// --------------------------------------------------

// Function: setWaitCode
// Address: 004eb6a0
/* public: void __thiscall TacticalAIGroup::setWaitCode(int) */

void __thiscall TacticalAIGroup::setWaitCode(TacticalAIGroup *this,int param_1)
{
  this->waitCodeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: assistGroupID
// Address: 004eb6b0
/* public: int __thiscall TacticalAIGroup::assistGroupID(void)const  */

int __thiscall TacticalAIGroup::assistGroupID(TacticalAIGroup *this)
{
  return this->assistGroupIDValue;
}

// --------------------------------------------------

// Function: setAssistGroupID
// Address: 004eb6c0
/* public: void __thiscall TacticalAIGroup::setAssistGroupID(int) */

void __thiscall TacticalAIGroup::setAssistGroupID(TacticalAIGroup *this,int param_1)
{
  this->assistGroupIDValue = param_1;
  return;
}

// --------------------------------------------------

// Function: assistGroupType
// Address: 004eb6d0
/* public: int __thiscall TacticalAIGroup::assistGroupType(void)const  */

int __thiscall TacticalAIGroup::assistGroupType(TacticalAIGroup *this)
{
  return this->assistGroupTypeValue;
}

// --------------------------------------------------

// Function: setAssistGroupType
// Address: 004eb6e0
/* public: void __thiscall TacticalAIGroup::setAssistGroupType(int) */

void __thiscall TacticalAIGroup::setAssistGroupType(TacticalAIGroup *this,int param_1)
{
  this->assistGroupTypeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: task
// Address: 004eb6f0
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
/* WARNING: Variable defined which should be unmapped: oHP */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TacticalAIGroup::task(class TribeTacticalAIModule *,class
   TribeMainDecisionAIModule *,int,int,int) */

int __thiscall
TacticalAIGroup::task
          (TacticalAIGroup *this,TribeTacticalAIModule *param_1,TribeMainDecisionAIModule *param_2,
          int param_3,int param_4,int param_5)
{
  TribeInformationAIModule *this_00;
  byte bVar1;
  bool bVar2;
  uchar uVar3;
  uchar uVar4;
  char cVar5;
  RGE_Static_Object *pRVar6;
  UnitAIModule *pUVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
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
  TribeTacticalAIModule *pTVar11;
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
  int *piVar12;
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
  int *piVar13;
  float fVar14;
  float fVar15;
  TribeTacticalAIModule *pTVar16;
  undefined8 uVar17;
  int oHP;
  int firstTime;
  float distance;
  XYPoint min;
  XYPoint max;
  uchar local_4;
  
  pTVar16 = param_1;
  TribeTacticalAIModule::logGroupDebug
            ((TribeTacticalAIModule *)param_4,(int)param_1,(char *)this->idValue,
             s_Entering_task___taskID__d__reset,param_3,param_4);
  pTVar11 = (TribeTacticalAIModule *)this->commanderValue;
  if (pTVar11 == (TribeTacticalAIModule *)0xffffffff) {
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)0xffffffff,(int)param_1,(char *)this->idValue);
    return 0;
  }
  if ((param_3 != 9) && (param_3 != 0xe)) {
    this->consecutiveGatherAttemptsValue = '\0';
  }
  switch(param_3) {
  case 0:
  case 1:
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)this->idValue,(int)param_1,(char *)this->idValue);
    param_3 = 0;
    param_5 = 0;
    piVar10 = this->unitsValue;
    pTVar11 = extraout_ECX;
    do {
      if (*piVar10 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar11,(int)param_1,(char *)this->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar10);
        pTVar11 = extraout_ECX_00;
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pTVar11 = extraout_ECX_01,
           pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    (pTVar11,(int)param_1,(char *)this->idValue,s_______Unit___d_is_gone__removing);
          removeUnitByIndex(this,param_5,param_2);
          pTVar11 = extraout_ECX_03;
        }
        else {
          iVar8 = __ftol();
          piVar10[0x28] = iVar8;
          param_3 = param_3 + iVar8;
          TribeTacticalAIModule::stopUnit(param_1,*piVar10,100);
          pTVar11 = extraout_ECX_02;
        }
      }
      piVar10 = piVar10 + 1;
      param_5 = param_5 + 1;
    } while (param_5 < 0x28);
    this->inUseValue = 0;
    break;
  case 2:
  case 0x15:
    TribeTacticalAIModule::logGroupDebug
              (pTVar11,(int)param_1,(char *)this->idValue,s___Going_to_send_my_units_to_atta,
               this->targetValue);
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)this->idValue,(int)param_1,(char *)this->idValue,
               s_____Target_Location___f___f__,(double)(this->targetLocationValue).x,
               (double)(this->targetLocationValue).y);
    if (this->playNumberValue == -1) {
      TribeTacticalAIModule::logGroupDebug(this_05,(int)param_1,(char *)this->idValue);
    }
    else {
      TribeTacticalAIModule::logGroupDebug
                (this_05,(int)param_1,(char *)this->idValue,s_____Using_Attack_with_Play___d_);
    }
    bVar2 = true;
    firstTime = 0;
    param_1 = (TribeTacticalAIModule *)0x0;
    piVar10 = this->unitsValue;
    pTVar11 = *(TribeTacticalAIModule **)(*(int *)(param_2->_padding_ + 0x3c) + 4);
    this->lastAttackRoundupTime = (ulong)pTVar11;
    do {
      if (*piVar10 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar11,(int)pTVar16,(char *)this->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar10);
        pTVar11 = extraout_ECX_19;
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pTVar11 = extraout_ECX_20,
           pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    (pTVar11,(int)pTVar16,(char *)this->idValue,s_______Unit___d_is_gone__removing);
          removeUnitByIndex(this,(int)param_1,param_2);
          pTVar11 = extraout_ECX_27;
        }
        else {
          pUVar7 = RGE_Static_Object::unitAI(pRVar6);
          UnitAIModule::currentAction(pUVar7);
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,(char *)this->idValue,
                     s_______CurrentAction__d_);
          iVar8 = __ftol();
          piVar10[0x28] = iVar8;
          firstTime = firstTime + iVar8;
          pTVar11 = (TribeTacticalAIModule *)firstTime;
          if (this->playNumberValue == -1) {
            if (param_5 == 0) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              iVar8 = UnitAIModule::currentAction(pUVar7);
              if (iVar8 == 600) {
                pUVar7 = RGE_Static_Object::unitAI(pRVar6);
                iVar8 = UnitAIModule::currentTargetType(pUVar7);
                if (iVar8 != 0x1b) {
                  TribeTacticalAIModule::logGroupDebug
                            (this_06,(int)pTVar16,(char *)this->idValue,
                             s_______Unit__d_is_busy_with_an_no);
                  pTVar11 = extraout_ECX_21;
                  goto LAB_004ec625;
                }
              }
            }
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)this->subTypeValue,(int)pTVar16,
                       (char *)this->idValue);
            if ((this->subTypeValue == 0) || (this->subTypeValue == 4)) {
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)*piVar10,(int)pTVar16,(char *)this->idValue);
              TribeTacticalAIModule::taskDefender(pTVar16,*piVar10,this->targetValue,2.0,100);
              pTVar11 = extraout_ECX_26;
            }
            else {
              min.x = (int)MainDecisionAIModule::object
                                     ((MainDecisionAIModule *)param_2,this->targetValue);
              if ((RGE_Static_Object *)min.x == (RGE_Static_Object *)0x0) {
                TribeTacticalAIModule::logGroupDebug(this_07,(int)pTVar16,(char *)this->idValue);
                pTVar11 = extraout_ECX_25;
              }
              else {
                if (bVar2) {
                  TribeTacticalAIModule::logGroupDebug(this_07,(int)pTVar16,(char *)this->idValue);
                  iVar8 = __ftol();
                  min.y = iVar8 + -7;
                  iVar8 = __ftol();
                  max.x = iVar8 + -7;
                  this_00 = &param_2->informationAI;
                  TribeInformationAIModule::mapBound(this_00,(XYPoint *)&min.y);
                  iVar8 = __ftol();
                  max.y = iVar8 + 7;
                  cVar5 = __ftol();
                  local_4 = cVar5 + '\a';
                  TribeInformationAIModule::mapBound(this_00,(XYPoint *)&max.y);
                  bVar1 = this->numberAttackWaypointsValue;
                  if (1 < bVar1) {
                    if ((float)min.y <= this->attackWaypoints[bVar1 - 2].x) {
                      max.y = __ftol();
                    }
                    else {
                      min.y = __ftol();
                    }
                    if ((float)max.x <= this->attackWaypoints[bVar1 - 2].y) {
                      local_4 = __ftol();
                    }
                    else {
                      max.x = __ftol();
                    }
                  }
                  TribeInformationAIModule::storeAttackMemory
                            (this_00,'\0',(uchar)min.y,(uchar)max.x,(uchar)max.y,local_4,
                             *(uchar *)(param_2->_padding_ + 0x4a),
                             *(uchar *)(*(int *)(min.x + 0xc) + 0x4a),0,'\0',
                             *(ulong *)(*(int *)(param_2->_padding_ + 0x3c) + 4),-1);
                  TribeTacticalAIModule::resetAttackSeparationTime(pTVar16);
                  bVar2 = false;
                }
                iVar8 = min.x;
                TribeTacticalAIModule::logGroupDebug
                          ((TribeTacticalAIModule *)this->targetValue,(int)pTVar16,
                           (char *)this->idValue);
                    /* language.dll match for 0x79: "N" */
                if (((*piVar10 == this->commanderValue) ||
                    (iVar9 = TribeTacticalAIModule::importantGroupLeader
                                       (pTVar16,this->commanderValue), iVar9 == 0)) ||
                   (iVar9 = TribeTacticalAIModule::strategicNumber(pTVar16,0x79), iVar9 == 0)) {
                  TribeTacticalAIModule::logGroupDebug
                            ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,
                             (char *)this->idValue);
                  if (param_3 == 0x15) {
                    TribeTacticalAIModule::moveUnit
                              (pTVar16,*piVar10,(this->targetLocationValue).x,
                               (this->targetLocationValue).y,100);
                    pTVar11 = extraout_ECX_23;
                  }
                  else {
                    TribeTacticalAIModule::taskAttacker
                              (pTVar16,*piVar10,(this->targetLocationValue).x,
                               (this->targetLocationValue).y,this->targetValue,
                               (int)*(short *)(*(int *)(iVar8 + 0xc) + 0x4a),this->attackWaypoints,
                               (uint)this->numberAttackWaypointsValue,this->commanderValue,0);
                    pTVar11 = extraout_ECX_24;
                  }
                }
                else {
                  TribeTacticalAIModule::logGroupDebug
                            ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,
                             (char *)this->idValue);
                    /* language.dll match for 0x83: "Arial" */
                  iVar8 = 99;
                  min.x = TribeTacticalAIModule::strategicNumber(pTVar16,0x83);
                  TribeTacticalAIModule::taskDefender
                            (pTVar16,*piVar10,this->commanderValue,(float)min.x,iVar8);
                  pTVar11 = extraout_ECX_22;
                }
              }
            }
          }
        }
      }
LAB_004ec625:
      piVar10 = piVar10 + 1;
      param_1 = (TribeTacticalAIModule *)((int)&param_1->_padding_ + 1);
    } while ((int)param_1 < 0x28);
    if (this->playNumberValue != -1) {
      piVar10 = (int *)operator_new(this->numberUnitsValue << 2);
      if (piVar10 != (int *)0x0) {
        piVar12 = this->unitsValue;
        iVar8 = 0x28;
        piVar13 = piVar10;
        do {
          if (*piVar12 != -1) {
            *piVar13 = *piVar12;
            piVar13 = piVar13 + 1;
          }
          piVar12 = piVar12 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        TribeTacticalAIModule::taskPlay
                  (pTVar16,this->commanderValue,piVar10,this->numberUnitsValue,this->targetValue,
                   this->playNumberValue,this->attackWaypoints,
                   (uint)this->numberAttackWaypointsValue);
        operator_delete(piVar10);
        return 0;
      }
      TribeTacticalAIModule::logGroupDebug
                ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,(char *)this->idValue);
      return 0;
    }
    this->inUseValue = 1;
    param_1 = (TribeTacticalAIModule *)firstTime;
    goto joined_r0x004ec189;
  case 3:
    TribeTacticalAIModule::logGroupDebug(pTVar11,(int)param_1,(char *)this->idValue);
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)this->idValue,(int)param_1,(char *)this->idValue,
               s___Retreat_Position___f___f__,(double)(this->retreatLocationValue).x,
               (double)(this->retreatLocationValue).y);
    param_4 = 0;
    piVar10 = this->unitsValue;
    pTVar11 = extraout_ECX_04;
    do {
      if (*piVar10 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar11,(int)param_1,(char *)this->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar10);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)this->idValue,(int)param_1,(char *)this->idValue,
                     s_______Unit___d_is_gone__removing);
          removeUnitByIndex(this,param_4,param_2);
          pTVar11 = extraout_ECX_07;
        }
        else {
          fVar15 = RGE_Static_Object::distance_to_position
                             (pRVar6,(this->retreatLocationValue).x,(this->retreatLocationValue).y,
                              (this->retreatLocationValue).z);
          fVar14 = fVar15 - _DAT_005756f4;
          if (fVar15 - _DAT_005756f4 < _DAT_005756f0) {
            fVar14 = _DAT_005756f0;
          }
          if ((float)((TribeTacticalAIModule *)pRVar6->master_obj)->_padding_ * _DAT_005756f8 <=
              fVar14) {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)*piVar10,(int)param_1,(char *)this->idValue,
                       s_______Tasking_Unit___d_to_move_t);
            TribeTacticalAIModule::moveUnit
                      (param_1,*piVar10,(this->retreatLocationValue).x,
                       (this->retreatLocationValue).y,100);
            pTVar11 = extraout_ECX_06;
          }
          else {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)pRVar6->master_obj,(int)param_1,
                       (char *)this->idValue,s_______Unit__d_is_within_a_tile_o);
            pTVar11 = extraout_ECX_05;
          }
        }
      }
      piVar10 = piVar10 + 1;
      param_4 = param_4 + 1;
    } while (param_4 < 0x28);
    return 1;
  case 4:
    TribeTacticalAIModule::logGroupDebug
              (pTVar11,(int)param_1,(char *)this->idValue,s___Going_to_send_my_units_to_defe,
               this->targetValue,(double)(this->targetLocationValue).x,
               (double)(this->targetLocationValue).y);
    param_1 = (TribeTacticalAIModule *)0x0;
    param_3 = 0;
    piVar10 = this->unitsValue;
    do {
      if (*piVar10 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,(char *)this->idValue,
                   s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar10);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)*piVar10,(int)pTVar16,(char *)this->idValue,
                     s_______Unit___d_is_gone__removing);
          removeUnitByIndex(this,param_3,param_2);
        }
        else {
          iVar8 = __ftol();
          piVar10[0x28] = iVar8;
          param_1 = (TribeTacticalAIModule *)((int)&param_1->_padding_ + iVar8);
          if (param_5 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar8 = UnitAIModule::currentAction(pUVar7);
            if (iVar8 != -1) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              UnitAIModule::currentAction(pUVar7);
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,(char *)this->idValue);
              goto LAB_004ec8ac;
            }
          }
          min.x = (int)RGE_Static_Object::distance_to_position
                                 (pRVar6,(this->targetLocationValue).x,(this->targetLocationValue).y
                                  ,(this->targetLocationValue).z);
          iVar8 = TribeTacticalAIModule::calculatePriority(pTVar16,(float)min.x);
          if (this->targetTypeValue == 0x6d) {
            min.x = TribeTacticalAIModule::strategicNumber(pTVar16,0x16);
            TribeTacticalAIModule::taskDefender
                      (pTVar16,*piVar10,this->targetValue,(float)min.x,iVar8);
          }
          else {
            min.x = TribeTacticalAIModule::strategicNumber(pTVar16,0x39);
            TribeTacticalAIModule::taskDefender
                      (pTVar16,*piVar10,this->targetValue,(float)min.x,iVar8);
          }
        }
      }
LAB_004ec8ac:
      piVar10 = piVar10 + 1;
      param_3 = param_3 + 1;
    } while (param_3 < 0x28);
    this->inUseValue = 1;
    goto joined_r0x004eca61;
  case 5:
  case 6:
  case 0xc:
  case 0x13:
    TribeTacticalAIModule::logGroupDebug(pTVar11,(int)param_1,(char *)this->idValue);
    param_3 = 0;
    param_5 = 0;
    piVar10 = this->unitsValue;
    do {
      if (*piVar10 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  ((TribeTacticalAIModule *)this->idValue,(int)param_1,(char *)this->idValue,
                   s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar10);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)this->idValue,(int)param_1,(char *)this->idValue,
                     s_______Unit___d_is_gone__removing);
          removeUnitByIndex(this,param_5,param_2);
        }
        else {
          iVar8 = __ftol();
          piVar10[0x28] = iVar8;
          param_3 = param_3 + iVar8;
        }
      }
      piVar10 = piVar10 + 1;
      param_5 = param_5 + 1;
    } while (param_5 < 0x28);
    this->inUseValue = 1;
    if (param_4 != 1) {
      return 0;
    }
    this->originalHitPointsValue = param_3;
    this->originalUnitNumberValue = this->numberUnitsValue;
    return 0;
  case 7:
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)this->idValue,(int)param_1,(char *)this->idValue);
    param_1 = (TribeTacticalAIModule *)0x0;
    iVar8 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x3af);
    pTVar11 = (TribeTacticalAIModule *)0x64;
    min.x = iVar8 % 100;
    param_3 = 0;
    piVar10 = this->unitsValue;
    do {
      if (*piVar10 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar11,(int)pTVar16,(char *)this->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar10);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)*piVar10,(int)pTVar16,(char *)this->idValue,
                     s_______Unit___d_is_gone__removing);
          removeUnitByIndex(this,param_3,param_2);
          pTVar11 = extraout_ECX_12;
        }
        else {
          iVar8 = __ftol();
          piVar10[0x28] = iVar8;
          param_1 = (TribeTacticalAIModule *)((int)&param_1->_padding_ + iVar8);
          if (param_5 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar8 = UnitAIModule::currentAction(pUVar7);
            if (iVar8 != -1) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              UnitAIModule::currentAction(pUVar7);
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)*piVar10,(int)pTVar16,(char *)this->idValue);
              pTVar11 = extraout_ECX_08;
              goto LAB_004ebd75;
            }
          }
          if ((TribeTacticalAIModule *)*piVar10 == (TribeTacticalAIModule *)this->commanderValue) {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)this->commanderValue,(int)pTVar16,
                       (char *)this->idValue,s_______Unit__d_is_the_commander__);
            TribeTacticalAIModule::taskExplorer(pTVar16,*piVar10,0);
            pTVar11 = extraout_ECX_09;
          }
          else {
            iVar8 = TribeTacticalAIModule::strategicNumber(pTVar16,200);
            if (min.x < iVar8) {
              TribeTacticalAIModule::logGroupDebug
                        (this_01,(int)pTVar16,(char *)this->idValue,
                         s_______Unit__d_is_not_the_command);
              TribeTacticalAIModule::taskDefender
                        (pTVar16,*piVar10,this->commanderValue,
                         pRVar6->master_obj->los * _DAT_005756fc,99);
              pTVar11 = extraout_ECX_10;
            }
            else {
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)*piVar10,(int)pTVar16,(char *)this->idValue,
                         s_______Unit__d_is_not_the_command);
              TribeTacticalAIModule::taskExplorer(pTVar16,*piVar10,0);
              pTVar11 = extraout_ECX_11;
            }
          }
        }
      }
LAB_004ebd75:
      piVar10 = piVar10 + 1;
      param_3 = param_3 + 1;
    } while (param_3 < 0x28);
    this->inUseValue = 1;
    goto joined_r0x004eca61;
  case 8:
    TribeTacticalAIModule::logGroupDebug(pTVar11,(int)param_1,(char *)this->idValue);
    param_1 = (TribeTacticalAIModule *)0x0;
    param_3 = 0;
    piVar10 = this->unitsValue;
    pTVar11 = extraout_ECX_13;
    do {
      if (*piVar10 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar11,(int)pTVar16,(char *)this->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar10);
        pTVar11 = extraout_ECX_14;
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pTVar11 = extraout_ECX_15,
           pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    (pTVar11,(int)pTVar16,(char *)this->idValue,s_______Unit___d_is_gone__removing);
          removeUnitByIndex(this,param_3,param_2);
          pTVar11 = extraout_ECX_18;
        }
        else {
          iVar8 = __ftol();
          piVar10[0x28] = iVar8;
          param_1 = (TribeTacticalAIModule *)((int)&param_1->_padding_ + iVar8);
          if (param_5 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar8 = UnitAIModule::currentAction(pUVar7);
            if (iVar8 != -1) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              UnitAIModule::currentAction(pUVar7);
              TribeTacticalAIModule::logGroupDebug(this_02,(int)pTVar16,(char *)this->idValue);
              pTVar11 = extraout_ECX_16;
              goto LAB_004ebe91;
            }
          }
          TribeTacticalAIModule::taskExplorer(pTVar16,*piVar10,0);
          pTVar11 = extraout_ECX_17;
        }
      }
LAB_004ebe91:
      piVar10 = piVar10 + 1;
      param_3 = param_3 + 1;
    } while (param_3 < 0x28);
    this->inUseValue = 1;
    param_3 = (int)param_1;
    break;
  case 9:
  case 0xe:
    if (this->consecutiveGatherAttemptsValue != 0xff) {
      this->consecutiveGatherAttemptsValue = this->consecutiveGatherAttemptsValue + '\x01';
    }
    pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,(int)pTVar11);
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      return 0;
    }
    min.x = (int)pRVar6;
    uVar3 = RGE_Static_Object::currentZone(pRVar6);
    iVar8 = __ftol();
    iVar9 = __ftol();
    uVar4 = RGE_Static_Object::lookupZone(pRVar6,iVar9,iVar8);
    if (uVar3 != uVar4) {
      setGatherLocation(this,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
    }
    param_1 = (TribeTacticalAIModule *)0x0;
    piVar10 = this->unitsValue;
    do {
      if (*piVar10 != -1) {
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar10);
        if ((pRVar6 != (RGE_Static_Object *)0x0) &&
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 != (UnitAIModule *)0x0)) {
          iVar8 = __ftol();
          iVar9 = __ftol();
          uVar4 = RGE_Static_Object::lookupZone((RGE_Static_Object *)min.x,iVar9,iVar8);
          if (uVar4 == uVar3) {
            if (param_5 == 0) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              iVar8 = UnitAIModule::currentAction(pUVar7);
              if (iVar8 != -1) {
                pUVar7 = RGE_Static_Object::unitAI(pRVar6);
                iVar8 = UnitAIModule::currentAction(pUVar7);
                if (iVar8 != 0x266) goto LAB_004eba3c;
              }
            }
            if (param_3 == 0xe) {
              firstTime = 0;
            }
            else {
              iVar8 = TribeTacticalAIModule::strategicNumber(pTVar16,0x29);
              firstTime = (int)(float)iVar8;
            }
            fVar14 = RGE_Static_Object::distance_to_position
                               (pRVar6,(this->gatherLocationValue).x,(this->gatherLocationValue).y,
                                (this->gatherLocationValue).z);
            param_4 = (int)(fVar14 - _DAT_005756f4);
            if ((float)param_4 < _DAT_005756f0) {
              param_4 = 0;
            }
            if ((float)firstTime <= (float)param_4) {
              iVar8 = TribeTacticalAIModule::calculatePriority(pTVar16,(float)param_4);
              TribeTacticalAIModule::groupGatherUnit
                        (pTVar16,*piVar10,this->commanderValue,(this->gatherLocationValue).x,
                         (this->gatherLocationValue).y,(this->gatherLocationValue).z,
                         (float)firstTime,iVar8);
            }
            else {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              iVar8 = UnitAIModule::currentOrder(pUVar7);
              if (iVar8 != -1) {
                TribeTacticalAIModule::stopUnit(pTVar16,*piVar10,100);
              }
            }
            goto LAB_004eba3c;
          }
        }
        removeUnitByIndex(this,(int)param_1,param_2);
      }
LAB_004eba3c:
      piVar10 = piVar10 + 1;
      param_1 = (TribeTacticalAIModule *)((int)&param_1->_padding_ + 1);
      if (0x27 < (int)param_1) {
        return 1;
      }
    } while( true );
  case 10:
    TribeTacticalAIModule::logGroupDebug(pTVar11,(int)param_1,(char *)this->idValue);
    param_1 = (TribeTacticalAIModule *)0x0;
    param_3 = 0;
    piVar10 = this->unitsValue;
    pTVar11 = extraout_ECX_28;
    do {
      if (*piVar10 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar11,(int)pTVar16,(char *)this->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar10);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)*piVar10,(int)pTVar16,(char *)this->idValue,
                     s_______Unit___d_is_gone__removing);
          removeUnitByIndex(this,param_3,param_2);
          pTVar11 = extraout_ECX_32;
        }
        else {
          iVar8 = __ftol();
          piVar10[0x28] = iVar8;
          param_1 = (TribeTacticalAIModule *)((int)&param_1->_padding_ + iVar8);
          if (param_5 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar8 = UnitAIModule::currentAction(pUVar7);
            if (iVar8 != -1) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              UnitAIModule::currentAction(pUVar7);
              TribeTacticalAIModule::logGroupDebug(this_08,(int)pTVar16,(char *)this->idValue);
              pTVar11 = extraout_ECX_29;
              goto LAB_004eca3e;
            }
          }
          if ((TribeTacticalAIModule *)*piVar10 == (TribeTacticalAIModule *)this->commanderValue) {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,(char *)this->idValue,
                       s_______Unit__d_is_the_commander__);
            TribeTacticalAIModule::taskWaterFisher
                      (pTVar16,*piVar10,this->targetValue,(this->targetLocationValue).x,
                       (this->targetLocationValue).y);
            pTVar11 = extraout_ECX_30;
          }
          else {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)this->commanderValue,(int)pTVar16,
                       (char *)this->idValue,s_______Unit__d_is_not_the_command);
            TribeTacticalAIModule::taskDefender
                      (pTVar16,*piVar10,this->commanderValue,pRVar6->master_obj->los * _DAT_005756fc
                       ,99);
            pTVar11 = extraout_ECX_31;
          }
        }
      }
LAB_004eca3e:
      piVar10 = piVar10 + 1;
      param_3 = param_3 + 1;
    } while (param_3 < 0x28);
    this->inUseValue = 1;
joined_r0x004eca61:
    if (param_4 == 1) {
      this->originalHitPointsValue = (int)param_1;
      this->originalUnitNumberValue = this->numberUnitsValue;
      return 1;
    }
    return 1;
  case 0xb:
    TribeTacticalAIModule::logGroupDebug(pTVar11,(int)param_1,(char *)this->idValue);
    param_1 = (TribeTacticalAIModule *)0x0;
    param_3 = 0;
    piVar10 = this->unitsValue;
    pTVar11 = extraout_ECX_33;
    do {
      if (*piVar10 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar11,(int)pTVar16,(char *)this->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar10);
        pTVar11 = extraout_ECX_34;
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pTVar11 = extraout_ECX_35,
           pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    (pTVar11,(int)pTVar16,(char *)this->idValue,s_______Unit___d_is_gone__removing);
          removeUnitByIndex(this,param_3,param_2);
          pTVar11 = extraout_ECX_39;
        }
        else {
          iVar8 = __ftol();
          piVar10[0x28] = iVar8;
          param_1 = (TribeTacticalAIModule *)((int)&param_1->_padding_ + iVar8);
          if (param_5 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar8 = UnitAIModule::currentAction(pUVar7);
            if (iVar8 != -1) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              UnitAIModule::currentAction(pUVar7);
              TribeTacticalAIModule::logGroupDebug(this_09,(int)pTVar16,(char *)this->idValue);
              pTVar11 = extraout_ECX_36;
              goto LAB_004ecbd9;
            }
          }
          if (*piVar10 == this->commanderValue) {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,(char *)this->idValue,
                       s_______Unit__d_is_the_commander__);
            TribeTacticalAIModule::taskWaterTrader(pTVar16,*piVar10,this->targetValue);
            pTVar11 = extraout_ECX_37;
          }
          else {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,(char *)this->idValue,
                       s_______Unit__d_is_not_the_command);
            TribeTacticalAIModule::taskDefender
                      (pTVar16,*piVar10,this->commanderValue,pRVar6->master_obj->los * _DAT_005756fc
                       ,99);
            pTVar11 = extraout_ECX_38;
          }
        }
      }
LAB_004ecbd9:
      piVar10 = piVar10 + 1;
      param_3 = param_3 + 1;
    } while (param_3 < 0x28);
    this->inUseValue = 1;
    param_3 = (int)param_1;
    break;
  default:
    uVar17 = CONCAT44(param_3,s___Task_ID__d_is_an_unknown_group);
    pTVar16 = (TribeTacticalAIModule *)this->idValue;
LAB_004ecd0a:
    TribeTacticalAIModule::logGroupDebug(pTVar11,(int)param_1,(char *)pTVar16,uVar17);
    return 0;
  case 0x14:
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)this->idValue,(int)param_1,(char *)this->idValue,
               s___Going_to_send_my_units_to_atta,this->targetValue);
    TribeTacticalAIModule::logGroupDebug
              (this_03,(int)param_1,(char *)this->idValue,s_____Target_Location___f___f__,
               (double)(this->targetLocationValue).x,(double)(this->targetLocationValue).y);
    pTVar11 = (TribeTacticalAIModule *)
              (*(int *)(*(int *)(param_2->_padding_ + 0x3c) + 4) - this->lastAttackRoundupTime);
    iVar8 = (int)pTVar11 / 1000;
    if (iVar8 < 10) {
      pTVar11 = (TribeTacticalAIModule *)this->idValue;
      uVar17 = CONCAT44(iVar8,s_____We_ve_only_waited__d_seconds);
      pTVar16 = pTVar11;
      goto LAB_004ecd0a;
    }
    TribeTacticalAIModule::logGroupDebug
              (pTVar11,(int)param_1,(char *)this->idValue,s_____We_ve_waited__d_seconds__che);
    pTVar11 = *(TribeTacticalAIModule **)(param_2->_padding_ + 0x3c);
    this->lastAttackRoundupTime = pTVar11->_padding_;
    if (this->playNumberValue != -1) {
      TribeTacticalAIModule::logGroupDebug(pTVar11,(int)param_1,(char *)this->idValue);
      return 0;
    }
    param_1 = (TribeTacticalAIModule *)0x0;
    param_3 = 0;
    piVar10 = this->unitsValue;
    do {
      if (*piVar10 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,(char *)this->idValue,
                   s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar10);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)*piVar10,(int)pTVar16,(char *)this->idValue,
                     s_______Unit___d_is_gone__removing);
          removeUnitByIndex(this,param_3,param_2);
        }
        else {
          pUVar7 = RGE_Static_Object::unitAI(pRVar6);
          UnitAIModule::currentAction(pUVar7);
          TribeTacticalAIModule::logGroupDebug
                    (this_04,(int)pTVar16,(char *)this->idValue,s_______CurrentAction__d_);
          iVar8 = __ftol();
          piVar10[0x28] = iVar8;
          param_1 = (TribeTacticalAIModule *)((int)&param_1->_padding_ + iVar8);
          if (param_5 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar8 = UnitAIModule::currentAction(pUVar7);
            if (iVar8 != -1) {
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)*piVar10,(int)pTVar16,(char *)this->idValue,
                         s_______Unit__d_is_busy_with_an_ac);
              goto LAB_004ec166;
            }
          }
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)*piVar10,(int)pTVar16,(char *)this->idValue);
          if ((this->subTypeValue == 0) || (this->subTypeValue == 4)) {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,(char *)this->idValue);
            TribeTacticalAIModule::taskDefender(pTVar16,*piVar10,this->targetValue,2.0,100);
          }
          else {
            pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,this->targetValue)
            ;
            if (pRVar6 == (RGE_Static_Object *)0x0) {
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)this->idValue,(int)pTVar16,(char *)this->idValue);
            }
            else {
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)this->targetValue,(int)pTVar16,
                         (char *)this->idValue);
              TribeTacticalAIModule::taskAttacker
                        (pTVar16,*piVar10,(this->targetLocationValue).x,
                         (this->targetLocationValue).y,this->targetValue,(int)pRVar6->owner->id,
                         this->attackWaypoints,(uint)this->numberAttackWaypointsValue,
                         this->commanderValue,1);
            }
          }
        }
      }
LAB_004ec166:
      piVar10 = piVar10 + 1;
      param_3 = param_3 + 1;
    } while (param_3 < 0x28);
    this->inUseValue = 1;
joined_r0x004ec189:
    if (param_4 == 1) {
      this->originalHitPointsValue = (int)param_1;
      this->originalUnitNumberValue = this->numberUnitsValue;
      this->numberAttackWaypointsValue = '\0';
      return 1;
    }
    return 1;
  }
  if (param_4 == 1) {
    this->originalHitPointsValue = param_3;
    this->originalUnitNumberValue = this->numberUnitsValue;
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: isGathered
// Address: 004ecd80
/* WARNING: Variable defined which should be unmapped: distance */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TacticalAIGroup::isGathered(class TribeTacticalAIModule *,class
   TribeMainDecisionAIModule *) */

int __thiscall
TacticalAIGroup::isGathered
          (TacticalAIGroup *this,TribeTacticalAIModule *param_1,TribeMainDecisionAIModule *param_2)
{
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar1;
  int iVar2;
  int *piVar3;
  float distance;
  float local_8;
  int local_4;
  
  iVar2 = 0;
  piVar3 = this->unitsValue;
  do {
    if (*piVar3 != -1) {
      this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar3);
      if ((this_00 == (RGE_Static_Object *)0x0) ||
         (pUVar1 = RGE_Static_Object::unitAI(this_00), pUVar1 == (UnitAIModule *)0x0)) {
        removeUnitByIndex(this,iVar2,param_2);
      }
      else {
        local_8 = RGE_Static_Object::distance_to_position
                            (this_00,(this->gatherLocationValue).x,(this->gatherLocationValue).y,
                             (this->gatherLocationValue).z);
        local_8 = local_8 - _DAT_005756f4;
        if (local_8 < _DAT_005756f0) {
          local_8 = 0.0;
        }
        if (this->typeValue == 0x6d) {
          local_4 = TribeTacticalAIModule::strategicNumber(param_1,0x17);
        }
        else {
          local_4 = TribeTacticalAIModule::strategicNumber(param_1,0x29);
        }
        if ((float)local_4 < local_8) {
          return 0;
        }
      }
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
    if (0x27 < iVar2) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: isTightGathered
// Address: 004ece70
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TacticalAIGroup::isTightGathered(class TribeTacticalAIModule *,class
   TribeMainDecisionAIModule *) */

int __thiscall
TacticalAIGroup::isTightGathered
          (TacticalAIGroup *this,TribeTacticalAIModule *param_1,TribeMainDecisionAIModule *param_2)
{
  float fVar1;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar2;
  int *piVar3;
  int iVar4;
  float fVar5;
  
  iVar4 = 0;
  piVar3 = this->unitsValue;
  do {
    if (*piVar3 != -1) {
      this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar3);
      if ((this_00 == (RGE_Static_Object *)0x0) ||
         (pUVar2 = RGE_Static_Object::unitAI(this_00), pUVar2 == (UnitAIModule *)0x0)) {
        removeUnitByIndex(this,iVar4,param_2);
      }
      else {
        fVar5 = RGE_Static_Object::distance_to_position
                          (this_00,(this->gatherLocationValue).x,(this->gatherLocationValue).y,
                           (this->gatherLocationValue).z);
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

// Function: allUnitsIdle
// Address: 004ecf10
/* public: int __thiscall TacticalAIGroup::allUnitsIdle(class TribeMainDecisionAIModule *,int) */

int __thiscall
TacticalAIGroup::allUnitsIdle(TacticalAIGroup *this,TribeMainDecisionAIModule *param_1,int param_2)
{
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar3 = this->unitsValue;
  do {
    if (*piVar3 != -1) {
      this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1,*piVar3);
      if ((this_00 == (RGE_Static_Object *)0x0) ||
         (pUVar1 = RGE_Static_Object::unitAI(this_00), pUVar1 == (UnitAIModule *)0x0)) {
        removeUnitByIndex(this,iVar4,param_1);
      }
      else if (this_00->master_obj->id != 0x7d) {
        if (param_2 == 1) {
          pUVar1 = RGE_Static_Object::unitAI(this_00);
          iVar2 = UnitAIModule::currentAction(pUVar1);
          if ((iVar2 == 600) && ((this->typeValue == 100 || (this->typeValue == 0x67))))
          goto LAB_004ecfb3;
        }
        pUVar1 = RGE_Static_Object::unitAI(this_00);
        iVar2 = UnitAIModule::currentAction(pUVar1);
        if (iVar2 != -1) {
          pUVar1 = RGE_Static_Object::unitAI(this_00);
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

// Function: consecutiveIdleUnitCount
// Address: 004ecfe0
/* public: unsigned long __thiscall TacticalAIGroup::consecutiveIdleUnitCount(void)const  */

ulong __thiscall TacticalAIGroup::consecutiveIdleUnitCount(TacticalAIGroup *this)
{
  return this->consecutiveIdleUnitCountValue;
}

// --------------------------------------------------

// Function: setConsecutiveIdleUnitCount
// Address: 004ecff0
/* public: void __thiscall TacticalAIGroup::setConsecutiveIdleUnitCount(unsigned long) */

void __thiscall TacticalAIGroup::setConsecutiveIdleUnitCount(TacticalAIGroup *this,ulong param_1)
{
  this->consecutiveIdleUnitCountValue = param_1;
  return;
}

// --------------------------------------------------

// Function: incrementConsecutiveIdleUnitCount
// Address: 004ed000
/* public: void __thiscall TacticalAIGroup::incrementConsecutiveIdleUnitCount(unsigned long) */

void __thiscall
TacticalAIGroup::incrementConsecutiveIdleUnitCount(TacticalAIGroup *this,ulong param_1)
{
  this->consecutiveIdleUnitCountValue = this->consecutiveIdleUnitCountValue + param_1;
  return;
}

// --------------------------------------------------

// Function: numberAttackWaypoints
// Address: 004ed020
/* public: unsigned char __thiscall TacticalAIGroup::numberAttackWaypoints(void)const  */

uchar __thiscall TacticalAIGroup::numberAttackWaypoints(TacticalAIGroup *this)
{
  return this->numberAttackWaypointsValue;
}

// --------------------------------------------------

// Function: currentAttackWaypoint
// Address: 004ed030
/* public: unsigned char __thiscall TacticalAIGroup::currentAttackWaypoint(void)const  */

uchar __thiscall TacticalAIGroup::currentAttackWaypoint(TacticalAIGroup *this)
{
  return this->currentAttackWaypointValue;
}

// --------------------------------------------------

// Function: setCurrentAttackWaypoint
// Address: 004ed040
/* public: void __thiscall TacticalAIGroup::setCurrentAttackWaypoint(unsigned char) */

void __thiscall TacticalAIGroup::setCurrentAttackWaypoint(TacticalAIGroup *this,uchar param_1)
{
  if (param_1 < this->numberAttackWaypointsValue) {
    this->currentAttackWaypointValue = param_1;
  }
  return;
}

// --------------------------------------------------

// Function: addAttackWaypoint
// Address: 004ed060
/* public: void __thiscall TacticalAIGroup::addAttackWaypoint(float,float) */

void __thiscall
TacticalAIGroup::addAttackWaypoint(TacticalAIGroup *this,float param_1,float param_2)
{
  if (this->numberAttackWaypointsValue < 0xe) {
    this->attackWaypoints[this->numberAttackWaypointsValue].x = param_1;
    this->attackWaypoints[this->numberAttackWaypointsValue].y = param_2;
    this->attackWaypoints[this->numberAttackWaypointsValue].z = 1.0;
    this->numberAttackWaypointsValue = this->numberAttackWaypointsValue + '\x01';
  }
  return;
}

// --------------------------------------------------

// Function: attackWaypoint
// Address: 004ed0c0
/* public: struct Waypoint * __thiscall TacticalAIGroup::attackWaypoint(unsigned char) */

Waypoint * __thiscall TacticalAIGroup::attackWaypoint(TacticalAIGroup *this,uchar param_1)
{
  if (param_1 < this->numberAttackWaypointsValue) {
    return this->attackWaypoints + param_1;
  }
  return (Waypoint *)0x0;
}

// --------------------------------------------------

// Function: firstIdleUnit
// Address: 004ed0f0
/* public: int __thiscall TacticalAIGroup::firstIdleUnit(class TribeMainDecisionAIModule *) */

int __thiscall
TacticalAIGroup::firstIdleUnit(TacticalAIGroup *this,TribeMainDecisionAIModule *param_1)
{
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar3 = this->unitsValue;
  do {
    if (*piVar3 != -1) {
      this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1,*piVar3);
      if ((this_00 == (RGE_Static_Object *)0x0) ||
         (pUVar1 = RGE_Static_Object::unitAI(this_00), pUVar1 == (UnitAIModule *)0x0)) {
        removeUnitByIndex(this,iVar4,param_1);
      }
      else {
        pUVar1 = RGE_Static_Object::unitAI(this_00);
        iVar2 = UnitAIModule::currentAction(pUVar1);
        if (iVar2 == -1) {
          return this->unitsValue[iVar4];
        }
      }
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar4 < 0x28);
  return -1;
}

// --------------------------------------------------

// Function: objectToDestroy
// Address: 004ed170
/* public: int __thiscall TacticalAIGroup::objectToDestroy(int) */

int __thiscall TacticalAIGroup::objectToDestroy(TacticalAIGroup *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 0x14)) {
    return this->objectsToDestroyValue[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: addObjectToDestroy
// Address: 004ed190
/* public: int __thiscall TacticalAIGroup::addObjectToDestroy(int) */

int __thiscall TacticalAIGroup::addObjectToDestroy(TacticalAIGroup *this,int param_1)
{
  if (this->numberObjectsToDestroyValue < 0x13) {
    this->objectsToDestroyValue[this->numberObjectsToDestroyValue] = param_1;
    this->numberObjectsToDestroyValue = this->numberObjectsToDestroyValue + 1;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

