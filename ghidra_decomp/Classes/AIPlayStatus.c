// Class: AIPlayStatus
// Size:  0x1C8
//
// Member Layout:
// [0x000] GroupingStruct[50] groupings (sz: 0x190)
// [0x190] int playNumberValue
// [0x194] int targetValue
// [0x198] XYZ originalPointValue (sz: 0xC)
// [0x1A4] int[5] originalHitPointsValue (sz: 0x14)
// [0x1B8] uchar currentPhaseValue
// [0x1BC] int savedAttackerValue
// [0x1C0] ulong lastPhaseChangeTimeValue
// [0x1C4] uchar deviationValue
// ----------------------------------------------------------------

// Function: AIPlayStatus
// Address: 0040fc30
AIPlayStatus * __thiscall AIPlayStatus::AIPlayStatus(AIPlayStatus *this)
{
  uchar *puVar1;
  int iVar2;
  
  this->playNumberValue = -1;
  this->targetValue = -1;
  XYZ::XYZ(&this->originalPointValue,0,0,0);
  this->currentPhaseValue = 0xfd;
  this->savedAttackerValue = -1;
  this->lastPhaseChangeTimeValue = 0;
  this->deviationValue = '\0';
  puVar1 = &this->groupings[0].type;
  iVar2 = 0x32;
  do {
    ((GroupingStruct *)(puVar1 + -5))->id = -1;
    puVar1[-1] = 0xff;
    *puVar1 = 0xff;
    puVar1 = puVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->originalHitPointsValue[0] = -1;
  this->originalHitPointsValue[1] = -1;
  this->originalHitPointsValue[2] = -1;
  this->originalHitPointsValue[3] = -1;
  this->originalHitPointsValue[4] = -1;
  return this;
}

// --------------------------------------------------

// Function: originalHitPoints
// Address: 0040fcb0
int __thiscall AIPlayStatus::originalHitPoints(AIPlayStatus *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 5)) {
    return this->originalHitPointsValue[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: setOriginalHitPoints
// Address: 0040fcd0
void __thiscall AIPlayStatus::setOriginalHitPoints(AIPlayStatus *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 5)) {
    this->originalHitPointsValue[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: numberInPlay
// Address: 0040fcf0
uchar __thiscall AIPlayStatus::numberInPlay(AIPlayStatus *this)
{
  uchar uVar1;
  int iVar2;
  
  uVar1 = '\0';
  iVar2 = 0x32;
  do {
    if (this->groupings[0].id != -1) {
      uVar1 = uVar1 + '\x01';
    }
    this = (AIPlayStatus *)(this->groupings + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar1;
}

// --------------------------------------------------

// Function: numberInGroup
// Address: 0040fd10
uchar __thiscall AIPlayStatus::numberInGroup(AIPlayStatus *this,int param_1)
{
  uchar uVar1;
  int iVar2;
  
  uVar1 = '\0';
  iVar2 = 0x32;
  do {
    if ((this->groupings[0].id != -1) && ((uint)this->groupings[0].groupID == param_1)) {
      uVar1 = uVar1 + '\x01';
    }
    this = (AIPlayStatus *)(this->groupings + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar1;
}

// --------------------------------------------------

// Function: numberOfTypeInGroup
// Address: 0040fd40
uchar __thiscall AIPlayStatus::numberOfTypeInGroup(AIPlayStatus *this,int param_1,int param_2)
{
  uchar uVar1;
  uchar *puVar2;
  int iVar3;
  
  uVar1 = '\0';
  puVar2 = &this->groupings[0].type;
  iVar3 = 0x32;
  do {
    if (((((GroupingStruct *)(puVar2 + -5))->id != -1) && ((uint)puVar2[-1] == param_1)) &&
       ((uint)*puVar2 == param_2)) {
      uVar1 = uVar1 + '\x01';
    }
    puVar2 = puVar2 + 8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return uVar1;
}

// --------------------------------------------------

// Function: group
// Address: 0040fd80
uchar __thiscall AIPlayStatus::group(AIPlayStatus *this,int param_1)
{
  int iVar1;
  AIPlayStatus *pAVar2;
  
  if (param_1 < 0) {
    return 0xff;
  }
  iVar1 = 0;
  pAVar2 = this;
  do {
    if (pAVar2->groupings[0].id == param_1) {
      return this->groupings[iVar1].groupID;
    }
    iVar1 = iVar1 + 1;
    pAVar2 = (AIPlayStatus *)(pAVar2->groupings + 1);
  } while (iVar1 < 0x32);
  return 0xff;
}

// --------------------------------------------------

// Function: addGrouping
// Address: 0040fdb0
int __thiscall AIPlayStatus::addGrouping(AIPlayStatus *this,int param_1,uchar param_2,uchar param_3)
{
  int iVar1;
  AIPlayStatus *pAVar2;
  
  iVar1 = 0;
  pAVar2 = this;
  do {
    if (pAVar2->groupings[0].id == -1) {
      this->groupings[iVar1].id = param_1;
      this->groupings[iVar1].groupID = param_2;
      this->groupings[iVar1].type = param_3;
      return 1;
    }
    iVar1 = iVar1 + 1;
    pAVar2 = (AIPlayStatus *)(pAVar2->groupings + 1);
  } while (iVar1 < 0x32);
  return 0;
}

// --------------------------------------------------

// Function: removeGrouping
// Address: 0040fdf0
int __thiscall AIPlayStatus::removeGrouping(AIPlayStatus *this,int param_1)
{
  int iVar1;
  AIPlayStatus *pAVar2;
  
  iVar1 = 0;
  pAVar2 = this;
  do {
    if (pAVar2->groupings[0].id == param_1) {
      this->groupings[iVar1].id = -1;
      this->groupings[iVar1].groupID = 0xff;
      this->groupings[iVar1].type = 0xff;
      return 1;
    }
    iVar1 = iVar1 + 1;
    pAVar2 = (AIPlayStatus *)(pAVar2->groupings + 1);
  } while (iVar1 < 0x32);
  return 0;
}

// --------------------------------------------------

// Function: zeroAllGroupings
// Address: 0040fe30
void __thiscall AIPlayStatus::zeroAllGroupings(AIPlayStatus *this)
{
  uchar *puVar1;
  int iVar2;
  
  puVar1 = &this->groupings[0].type;
  iVar2 = 0x32;
  do {
    ((GroupingStruct *)(puVar1 + -5))->id = -1;
    puVar1[-1] = 0xff;
    *puVar1 = 0xff;
    puVar1 = puVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: copyUnits
// Address: 0040fe50
void __thiscall AIPlayStatus::copyUnits(AIPlayStatus *this,int *param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  
  *param_2 = 0;
  iVar2 = 0x32;
  do {
    iVar1 = this->groupings[0].id;
    if (iVar1 != -1) {
      param_1[*param_2] = iVar1;
      *param_2 = *param_2 + 1;
    }
    this = (AIPlayStatus *)(this->groupings + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: load
// Address: 0040fe90
void __thiscall AIPlayStatus::load(AIPlayStatus *this,int param_1)
{
  int iVar1;
  
  iVar1 = param_1;
  rge_read(param_1,&this->playNumberValue,4);
  rge_read(iVar1,&this->targetValue,4);
  rge_read(iVar1,&param_1,4);
  (this->originalPointValue).xValue = param_1;
  rge_read(iVar1,&param_1,4);
  (this->originalPointValue).yValue = param_1;
  rge_read(iVar1,&param_1,4);
  (this->originalPointValue).zValue = param_1;
  rge_read(iVar1,this->originalHitPointsValue,0x14);
  rge_read(iVar1,&this->currentPhaseValue,1);
  rge_read(iVar1,this,400);
  rge_read(iVar1,&this->savedAttackerValue,4);
  rge_read(iVar1,&this->lastPhaseChangeTimeValue,4);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0040ff70
void __thiscall AIPlayStatus::save(AIPlayStatus *this,int param_1)
{
  int iVar1;
  
  iVar1 = param_1;
  rge_write(param_1,&this->playNumberValue,4);
  rge_write(iVar1,&this->targetValue,4);
  param_1 = (this->originalPointValue).xValue;
  rge_write(iVar1,&param_1,4);
  param_1 = (this->originalPointValue).yValue;
  rge_write(iVar1,&param_1,4);
  param_1 = (this->originalPointValue).zValue;
  rge_write(iVar1,&param_1,4);
  rge_write(iVar1,this->originalHitPointsValue,0x14);
  rge_write(iVar1,&this->currentPhaseValue,1);
  rge_write(iVar1,this,400);
  rge_write(iVar1,&this->savedAttackerValue,4);
  rge_write(iVar1,&this->lastPhaseChangeTimeValue,4);
  return;
}

// --------------------------------------------------

// Function: copy
// Address: 00410050
void __thiscall AIPlayStatus::copy(AIPlayStatus *this,AIPlayStatus *param_1)
{
  int iVar1;
  uchar *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  AIPlayStatus *pAVar6;
  
  iVar5 = 0x32;
  this->playNumberValue = param_1->playNumberValue;
  this->targetValue = param_1->targetValue;
  iVar4 = (param_1->originalPointValue).zValue;
  iVar1 = (param_1->originalPointValue).yValue;
  (this->originalPointValue).xValue = (param_1->originalPointValue).xValue;
  (this->originalPointValue).yValue = iVar1;
  (this->originalPointValue).zValue = iVar4;
  this->currentPhaseValue = param_1->currentPhaseValue;
  this->savedAttackerValue = param_1->savedAttackerValue;
  this->lastPhaseChangeTimeValue = param_1->lastPhaseChangeTimeValue;
  puVar2 = &this->groupings[0].groupID;
  pAVar6 = param_1;
  do {
    ((GroupingStruct *)(puVar2 + -4))->id = pAVar6->groupings[0].id;
    *puVar2 = puVar2[(int)param_1 - (int)this];
    puVar2[1] = pAVar6->groupings[0].type;
    puVar2 = puVar2 + 8;
    iVar5 = iVar5 + -1;
    pAVar6 = (AIPlayStatus *)(pAVar6->groupings + 1);
  } while (iVar5 != 0);
  piVar3 = this->originalHitPointsValue;
  iVar4 = 5;
  do {
    *piVar3 = *(int *)((int)piVar3 + ((int)param_1 - (int)this));
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

// --------------------------------------------------

// Function: removeDeadUnits
// Address: 00410100
void __thiscall
AIPlayStatus::removeDeadUnits(AIPlayStatus *this,int param_1,RGE_Game_World *param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  
  iVar3 = 0x32;
  do {
    iVar1 = this->groupings[0].id;
    if (iVar1 != -1) {
      pRVar2 = RGE_Game_World::object(param_2,iVar1);
      if ((pRVar2 == (RGE_Static_Object *)0x0) || (2 < pRVar2->object_state)) {
        this->groupings[0].id = -1;
        this->groupings[0].groupID = 0xff;
        this->groupings[0].type = 0xff;
      }
    }
    this = (AIPlayStatus *)(this->groupings + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

// --------------------------------------------------

// Function: resetHitPoints
// Address: 00410150
void __thiscall AIPlayStatus::resetHitPoints(AIPlayStatus *this,int param_1,RGE_Game_World *param_2)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  AIPlayStatus *pAVar5;
  
  iVar4 = 0;
  iVar3 = 0x32;
  pAVar5 = this;
  do {
    iVar2 = pAVar5->groupings[0].id;
    if ((iVar2 != -1) && ((uint)pAVar5->groupings[0].groupID == param_1)) {
      pRVar1 = RGE_Game_World::object(param_2,iVar2);
      if (pRVar1 != (RGE_Static_Object *)0x0) {
        iVar2 = __ftol();
        iVar4 = iVar4 + iVar2;
      }
    }
    pAVar5 = (AIPlayStatus *)(pAVar5->groupings + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  setOriginalHitPoints(this,param_1,iVar4);
  return;
}

// --------------------------------------------------

