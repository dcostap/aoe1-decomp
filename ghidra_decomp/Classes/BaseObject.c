// Class: BaseObject
// Size:  0xA0
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] `scalar_deleting_destructor'
// [02] `scalar_deleting_destructor'
// [03] loggingHistory
// [04] setLogHistory
// [05] toggleLogHistory
// [06] setHistoryFilename
// [07] loggingCommonHistory
// [08] setLogCommonHistory
// [09] toggleLogCommonHistory
// [10] loadState
// [11] saveState
// [12] gleanState
// [13] processMessage
// [14] update
// [15] setCallbackMessage
// [16] filterOutMessage
// [17] save
// [18] loadConstructionPlan
// [19] placeStructure
// [20] setBuilt
// [21] unplaceStructure
// [22] unplaceStructure
// [23] decrementBuildAttempts
// [24] incrementBuildAttempts
//
// Member Layout:
// [0x004] BaseObject * next
// [0x008] BaseObject * prev
// [0x00C] int numberGroupsValue
// [0x010] int * groupIDValue
// [0x014] int categoryIDValue
// [0x018] int typeIDValue
// [0x01C] int gameIDValue
// [0x020] char[64] nameValue (sz: 0x40)
// [0x060] float xPositionValue
// [0x064] float yPositionValue
// [0x068] float zPositionValue
// [0x06C] float xSizeValue
// [0x070] float ySizeValue
// [0x074] float zSizeValue
// [0x078] int hitPointValue
// [0x07C] int minHitPointValue
// [0x080] int maxHitPointValue
// [0x084] int busyValue
// [0x088] int currentTaskValue
// [0x08C] int currentTargetValue
// [0x090] int currentTargetTypeValue
// [0x094] float currentTargetXPositionValue
// [0x098] float currentTargetYPositionValue
// [0x09C] float currentTargetZPositionValue
// ----------------------------------------------------------------

// Function: BaseObject
// Address: 00409fa0
// [HELPER] s_: ""
/* public: __thiscall BaseObject::BaseObject(void) */

BaseObject * __thiscall BaseObject::BaseObject(BaseObject *this)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  this->next = (BaseObject *)0x0;
  this->prev = (BaseObject *)0x0;
  this->numberGroupsValue = 0;
  this->groupIDValue = (int *)0x0;
  this->categoryIDValue = -1;
  this->typeIDValue = -1;
  this->gameIDValue = -1;
  this->xPositionValue = -1.0;
  this->yPositionValue = -1.0;
  this->zPositionValue = -1.0;
  this->xSizeValue = -1.0;
  this->ySizeValue = -1.0;
  this->zSizeValue = -1.0;
  this->hitPointValue = 0;
  this->minHitPointValue = 0;
  this->maxHitPointValue = 0;
  this->busyValue = 0;
  this->currentTaskValue = -1;
  this->currentTargetValue = -1;
  this->currentTargetTypeValue = -1;
  this->currentTargetXPositionValue = 0.0;
  this->currentTargetYPositionValue = 0.0;
  this->currentTargetZPositionValue = 0.0;
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
  pcVar5 = this->nameValue;
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
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0040a040
/* public: virtual void * __thiscall BaseObject::`vector deleting destructor'(unsigned int) */

void * __thiscall BaseObject::_vector_deleting_destructor_(BaseObject *this,uint param_1)
{
  ~BaseObject(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: BaseObject
// Address: 0040a060
/* public: __thiscall BaseObject::BaseObject(int,int,int,int,char
   *,float,float,float,float,float,float,int,int,int) */

BaseObject * __thiscall
BaseObject::BaseObject
          (BaseObject *this,int param_1,int param_2,int param_3,int param_4,char *param_5,
          float param_6,float param_7,float param_8,float param_9,float param_10,float param_11,
          int param_12,int param_13,int param_14)
{
  int *piVar1;
  
  this->categoryIDValue = param_2;
  this->typeIDValue = param_3;
  this->gameIDValue = param_4;
  this->xPositionValue = param_9;
  this->yPositionValue = param_10;
  this->zPositionValue = param_11;
  this->xSizeValue = param_6;
  this->ySizeValue = param_7;
  this->zSizeValue = param_8;
  this->hitPointValue = param_12;
  this->minHitPointValue = param_13;
  this->next = (BaseObject *)0x0;
  this->prev = (BaseObject *)0x0;
  this->numberGroupsValue = 1;
  this->maxHitPointValue = param_14;
  this->busyValue = 0;
  this->currentTaskValue = -1;
  this->currentTargetValue = -1;
  this->currentTargetTypeValue = -1;
  this->currentTargetXPositionValue = 0.0;
  this->currentTargetYPositionValue = 0.0;
  this->currentTargetZPositionValue = 0.0;
  this->_padding_ = (int)&_vftable_;
  piVar1 = (int *)operator_new(4);
  this->groupIDValue = piVar1;
  *piVar1 = param_1;
  strncpy(this->nameValue,param_5,0x3f);
  return this;
}

// --------------------------------------------------

// Function: BaseObject
// Address: 0040a130
/* public: __thiscall BaseObject::BaseObject(class BaseObject *) */

BaseObject * __thiscall BaseObject::BaseObject(BaseObject *this,BaseObject *param_1)
{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  this->next = (BaseObject *)0x0;
  this->prev = (BaseObject *)0x0;
  this->numberGroupsValue = param_1->numberGroupsValue;
  this->categoryIDValue = param_1->categoryIDValue;
  this->typeIDValue = param_1->typeIDValue;
  this->gameIDValue = param_1->gameIDValue;
  this->xPositionValue = param_1->xPositionValue;
  this->yPositionValue = param_1->yPositionValue;
  this->zPositionValue = param_1->zPositionValue;
  this->xSizeValue = param_1->xSizeValue;
  this->ySizeValue = param_1->ySizeValue;
  this->zSizeValue = param_1->zSizeValue;
  this->hitPointValue = param_1->hitPointValue;
  this->minHitPointValue = param_1->minHitPointValue;
  this->maxHitPointValue = param_1->maxHitPointValue;
  this->busyValue = param_1->busyValue;
  this->currentTaskValue = param_1->currentTaskValue;
  this->currentTargetValue = param_1->currentTargetValue;
  this->currentTargetTypeValue = param_1->currentTargetTypeValue;
  this->currentTargetXPositionValue = param_1->currentTargetXPositionValue;
  this->currentTargetYPositionValue = param_1->currentTargetYPositionValue;
  fVar1 = param_1->currentTargetZPositionValue;
  this->_padding_ = (int)&_vftable_;
  this->currentTargetZPositionValue = fVar1;
  piVar2 = (int *)operator_new(this->numberGroupsValue << 2);
  this->groupIDValue = piVar2;
  iVar3 = 0;
  if (0 < this->numberGroupsValue) {
    do {
      this->groupIDValue[iVar3] = param_1->groupIDValue[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < this->numberGroupsValue);
  }
  strncpy(this->nameValue,param_1->nameValue,0x3f);
  return this;
}

// --------------------------------------------------

// Function: BaseObject
// Address: 0040a240
/* public: __thiscall BaseObject::BaseObject(class BaseObject const &) */

BaseObject * __thiscall BaseObject::BaseObject(BaseObject *this,BaseObject *param_1)
{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  this->next = (BaseObject *)0x0;
  this->prev = (BaseObject *)0x0;
  this->numberGroupsValue = param_1->numberGroupsValue;
  this->categoryIDValue = param_1->categoryIDValue;
  this->typeIDValue = param_1->typeIDValue;
  this->gameIDValue = param_1->gameIDValue;
  this->xPositionValue = param_1->xPositionValue;
  this->yPositionValue = param_1->yPositionValue;
  this->zPositionValue = param_1->zPositionValue;
  this->xSizeValue = param_1->xSizeValue;
  this->ySizeValue = param_1->ySizeValue;
  this->zSizeValue = param_1->zSizeValue;
  this->hitPointValue = param_1->hitPointValue;
  this->minHitPointValue = param_1->minHitPointValue;
  this->maxHitPointValue = param_1->maxHitPointValue;
  this->busyValue = param_1->busyValue;
  this->currentTaskValue = param_1->currentTaskValue;
  this->currentTargetValue = param_1->currentTargetValue;
  this->currentTargetTypeValue = param_1->currentTargetTypeValue;
  this->currentTargetXPositionValue = param_1->currentTargetXPositionValue;
  this->currentTargetYPositionValue = param_1->currentTargetYPositionValue;
  fVar1 = param_1->currentTargetZPositionValue;
  this->_padding_ = (int)&_vftable_;
  this->currentTargetZPositionValue = fVar1;
  piVar2 = (int *)operator_new(this->numberGroupsValue << 2);
  this->groupIDValue = piVar2;
  iVar3 = 0;
  if (0 < this->numberGroupsValue) {
    do {
      this->groupIDValue[iVar3] = param_1->groupIDValue[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < this->numberGroupsValue);
  }
  strncpy(this->nameValue,param_1->nameValue,0x3f);
  return this;
}

// --------------------------------------------------

// Function: ~BaseObject
// Address: 0040a350
/* public: virtual __thiscall BaseObject::~BaseObject(void) */

void __thiscall BaseObject::~BaseObject(BaseObject *this)
{
  this->_padding_ = (int)&_vftable_;
  operator_delete(this->groupIDValue);
  return;
}

// --------------------------------------------------

// Function: numberGroups
// Address: 0040a3f0
/* public: int __thiscall BaseObject::numberGroups(void)const  */

int __thiscall BaseObject::numberGroups(BaseObject *this)
{
  return this->numberGroupsValue;
}

// --------------------------------------------------

// Function: groupID
// Address: 0040a400
/* public: int __thiscall BaseObject::groupID(int)const  */

int __thiscall BaseObject::groupID(BaseObject *this,int param_1)
{
  if (((this->groupIDValue != (int *)0x0) && (-1 < param_1)) && (param_1 < this->numberGroupsValue))
{
    return this->groupIDValue[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: inGroup
// Address: 0040a420
/* public: int __thiscall BaseObject::inGroup(int)const  */

int __thiscall BaseObject::inGroup(BaseObject *this,int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (this->numberGroupsValue < 1) {
    return 0;
  }
  piVar2 = this->groupIDValue;
  do {
    if (*piVar2 == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < this->numberGroupsValue);
  return 0;
}

// --------------------------------------------------

// Function: addGroup
// Address: 0040a460
/* public: int __thiscall BaseObject::addGroup(int) */

int __thiscall BaseObject::addGroup(BaseObject *this,int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = inGroup(this,param_1);
  if (iVar1 != 0) {
    return 0;
  }
  piVar2 = (int *)operator_new(this->numberGroupsValue * 4 + 4);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  iVar1 = 0;
  if (0 < this->numberGroupsValue) {
    do {
      iVar3 = iVar1 + 1;
      piVar2[iVar1] = this->groupIDValue[iVar1];
      iVar1 = iVar3;
    } while (iVar3 < this->numberGroupsValue);
  }
  piVar2[this->numberGroupsValue] = param_1;
  this->numberGroupsValue = this->numberGroupsValue + 1;
  operator_delete(this->groupIDValue);
  this->groupIDValue = piVar2;
  return 1;
}

// --------------------------------------------------

// Function: removeGroup
// Address: 0040a4e0
/* public: int __thiscall BaseObject::removeGroup(int) */

int __thiscall BaseObject::removeGroup(BaseObject *this,int param_1)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = inGroup(this,param_1);
  if (iVar1 == 0) {
    return 0;
  }
  piVar2 = (int *)operator_new(this->numberGroupsValue * 4 - 4);
  if (piVar2 != (int *)0x0) {
    iVar1 = 0;
    piVar3 = piVar2;
    if (0 < this->numberGroupsValue) {
      do {
        if (this->groupIDValue[iVar1] != param_1) {
          *piVar3 = this->groupIDValue[iVar1];
          piVar3 = piVar3 + 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < this->numberGroupsValue);
    }
    this->numberGroupsValue = this->numberGroupsValue + -1;
    operator_delete(this->groupIDValue);
    this->groupIDValue = piVar2;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: categoryID
// Address: 0040a560
/* public: int __thiscall BaseObject::categoryID(void)const  */

int __thiscall BaseObject::categoryID(BaseObject *this)
{
  return this->categoryIDValue;
}

// --------------------------------------------------

// Function: typeID
// Address: 0040a570
/* public: int __thiscall BaseObject::typeID(void)const  */

int __thiscall BaseObject::typeID(BaseObject *this)
{
  return this->typeIDValue;
}

// --------------------------------------------------

// Function: gameID
// Address: 0040a580
/* public: int const & __thiscall BaseObject::gameID(void)const  */

int * __thiscall BaseObject::gameID(BaseObject *this)
{
  return &this->gameIDValue;
}

// --------------------------------------------------

// Function: name
// Address: 0040a590
/* public: char * __thiscall BaseObject::name(void) */

char * __thiscall BaseObject::name(BaseObject *this)
{
  return this->nameValue;
}

// --------------------------------------------------

// Function: xPosition
// Address: 0040a5a0
/* public: float __thiscall BaseObject::xPosition(void)const  */

float __thiscall BaseObject::xPosition(BaseObject *this)
{
  return this->xPositionValue;
}

// --------------------------------------------------

// Function: yPosition
// Address: 0040a5b0
/* public: float __thiscall BaseObject::yPosition(void)const  */

float __thiscall BaseObject::yPosition(BaseObject *this)
{
  return this->yPositionValue;
}

// --------------------------------------------------

// Function: zPosition
// Address: 0040a5c0
/* public: float __thiscall BaseObject::zPosition(void)const  */

float __thiscall BaseObject::zPosition(BaseObject *this)
{
  return this->zPositionValue;
}

// --------------------------------------------------

// Function: xSize
// Address: 0040a5d0
/* public: float __thiscall BaseObject::xSize(void)const  */

float __thiscall BaseObject::xSize(BaseObject *this)
{
  return this->xSizeValue;
}

// --------------------------------------------------

// Function: ySize
// Address: 0040a5e0
/* public: float __thiscall BaseObject::ySize(void)const  */

float __thiscall BaseObject::ySize(BaseObject *this)
{
  return this->ySizeValue;
}

// --------------------------------------------------

// Function: zSize
// Address: 0040a5f0
/* public: float __thiscall BaseObject::zSize(void)const  */

float __thiscall BaseObject::zSize(BaseObject *this)
{
  return this->zSizeValue;
}

// --------------------------------------------------

// Function: hitPoints
// Address: 0040a600
/* public: int __thiscall BaseObject::hitPoints(void)const  */

int __thiscall BaseObject::hitPoints(BaseObject *this)
{
  return this->hitPointValue;
}

// --------------------------------------------------

// Function: minHitPoints
// Address: 0040a610
/* public: int __thiscall BaseObject::minHitPoints(void)const  */

int __thiscall BaseObject::minHitPoints(BaseObject *this)
{
  return this->minHitPointValue;
}

// --------------------------------------------------

// Function: maxHitPoints
// Address: 0040a620
/* public: int __thiscall BaseObject::maxHitPoints(void)const  */

int __thiscall BaseObject::maxHitPoints(BaseObject *this)
{
  return this->maxHitPointValue;
}

// --------------------------------------------------

// Function: busy
// Address: 0040a630
/* public: int __thiscall BaseObject::busy(void)const  */

int __thiscall BaseObject::busy(BaseObject *this)
{
  return this->busyValue;
}

// --------------------------------------------------

// Function: currentTask
// Address: 0040a640
/* public: int __thiscall BaseObject::currentTask(void)const  */

int __thiscall BaseObject::currentTask(BaseObject *this)
{
  return this->currentTaskValue;
}

// --------------------------------------------------

// Function: currentTarget
// Address: 0040a650
/* public: int __thiscall BaseObject::currentTarget(void)const  */

int __thiscall BaseObject::currentTarget(BaseObject *this)
{
  return this->currentTargetValue;
}

// --------------------------------------------------

// Function: currentTargetType
// Address: 0040a660
/* public: int __thiscall BaseObject::currentTargetType(void)const  */

int __thiscall BaseObject::currentTargetType(BaseObject *this)
{
  return this->currentTargetTypeValue;
}

// --------------------------------------------------

// Function: currentTargetXPosition
// Address: 0040a670
/* public: float __thiscall BaseObject::currentTargetXPosition(void)const  */

float __thiscall BaseObject::currentTargetXPosition(BaseObject *this)
{
  return this->currentTargetXPositionValue;
}

// --------------------------------------------------

// Function: currentTargetYPosition
// Address: 0040a680
/* public: float __thiscall BaseObject::currentTargetYPosition(void)const  */

float __thiscall BaseObject::currentTargetYPosition(BaseObject *this)
{
  return this->currentTargetYPositionValue;
}

// --------------------------------------------------

// Function: currentTargetZPosition
// Address: 0040a690
/* public: float __thiscall BaseObject::currentTargetZPosition(void)const  */

float __thiscall BaseObject::currentTargetZPosition(BaseObject *this)
{
  return this->currentTargetZPositionValue;
}

// --------------------------------------------------

// Function: setXPosition
// Address: 0040a6a0
/* public: void __thiscall BaseObject::setXPosition(float) */

void __thiscall BaseObject::setXPosition(BaseObject *this,float param_1)
{
  this->xPositionValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setYPosition
// Address: 0040a6b0
/* public: void __thiscall BaseObject::setYPosition(float) */

void __thiscall BaseObject::setYPosition(BaseObject *this,float param_1)
{
  this->yPositionValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setZPosition
// Address: 0040a6c0
/* public: void __thiscall BaseObject::setZPosition(float) */

void __thiscall BaseObject::setZPosition(BaseObject *this,float param_1)
{
  this->zPositionValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setXSize
// Address: 0040a6d0
/* public: void __thiscall BaseObject::setXSize(float) */

void __thiscall BaseObject::setXSize(BaseObject *this,float param_1)
{
  this->xSizeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setYSize
// Address: 0040a6e0
/* public: void __thiscall BaseObject::setYSize(float) */

void __thiscall BaseObject::setYSize(BaseObject *this,float param_1)
{
  this->ySizeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setZSize
// Address: 0040a6f0
/* public: void __thiscall BaseObject::setZSize(float) */

void __thiscall BaseObject::setZSize(BaseObject *this,float param_1)
{
  this->zSizeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setHitPoints
// Address: 0040a700
/* public: void __thiscall BaseObject::setHitPoints(int) */

void __thiscall BaseObject::setHitPoints(BaseObject *this,int param_1)
{
  this->hitPointValue = param_1;
  return;
}

// --------------------------------------------------

// Function: incrementHitPoints
// Address: 0040a710
/* public: void __thiscall BaseObject::incrementHitPoints(int) */

void __thiscall BaseObject::incrementHitPoints(BaseObject *this,int param_1)
{
  this->hitPointValue = this->hitPointValue + param_1;
  return;
}

// --------------------------------------------------

// Function: decrementHitPoints
// Address: 0040a720
/* public: void __thiscall BaseObject::decrementHitPoints(int) */

void __thiscall BaseObject::decrementHitPoints(BaseObject *this,int param_1)
{
  this->hitPointValue = this->hitPointValue - param_1;
  return;
}

// --------------------------------------------------

// Function: setMinHitPoints
// Address: 0040a730
/* public: void __thiscall BaseObject::setMinHitPoints(int) */

void __thiscall BaseObject::setMinHitPoints(BaseObject *this,int param_1)
{
  this->minHitPointValue = param_1;
  return;
}

// --------------------------------------------------

// Function: incrementMinHitPoints
// Address: 0040a740
/* public: void __thiscall BaseObject::incrementMinHitPoints(int) */

void __thiscall BaseObject::incrementMinHitPoints(BaseObject *this,int param_1)
{
  this->minHitPointValue = this->minHitPointValue + param_1;
  return;
}

// --------------------------------------------------

// Function: decrementMinHitPoints
// Address: 0040a750
/* public: void __thiscall BaseObject::decrementMinHitPoints(int) */

void __thiscall BaseObject::decrementMinHitPoints(BaseObject *this,int param_1)
{
  this->minHitPointValue = this->minHitPointValue - param_1;
  return;
}

// --------------------------------------------------

// Function: setMaxHitPoints
// Address: 0040a760
/* public: void __thiscall BaseObject::setMaxHitPoints(int) */

void __thiscall BaseObject::setMaxHitPoints(BaseObject *this,int param_1)
{
  this->maxHitPointValue = param_1;
  return;
}

// --------------------------------------------------

// Function: incrementMaxHitPoints
// Address: 0040a770
/* public: void __thiscall BaseObject::incrementMaxHitPoints(int) */

void __thiscall BaseObject::incrementMaxHitPoints(BaseObject *this,int param_1)
{
  this->maxHitPointValue = this->maxHitPointValue + param_1;
  return;
}

// --------------------------------------------------

// Function: decrementMaxHitPoints
// Address: 0040a790
/* public: void __thiscall BaseObject::decrementMaxHitPoints(int) */

void __thiscall BaseObject::decrementMaxHitPoints(BaseObject *this,int param_1)
{
  this->maxHitPointValue = this->maxHitPointValue - param_1;
  return;
}

// --------------------------------------------------

// Function: setBusy
// Address: 0040a7b0
/* public: void __thiscall BaseObject::setBusy(int) */

void __thiscall BaseObject::setBusy(BaseObject *this,int param_1)
{
  this->busyValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setCurrentTask
// Address: 0040a7c0
/* public: void __thiscall BaseObject::setCurrentTask(int) */

void __thiscall BaseObject::setCurrentTask(BaseObject *this,int param_1)
{
  this->currentTaskValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setCurrentTarget
// Address: 0040a7d0
/* public: void __thiscall BaseObject::setCurrentTarget(int) */

void __thiscall BaseObject::setCurrentTarget(BaseObject *this,int param_1)
{
  this->currentTargetValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setCurrentTargetType
// Address: 0040a7e0
/* public: void __thiscall BaseObject::setCurrentTargetType(int) */

void __thiscall BaseObject::setCurrentTargetType(BaseObject *this,int param_1)
{
  this->currentTargetTypeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setCurrentTargetPosition
// Address: 0040a7f0
/* public: void __thiscall BaseObject::setCurrentTargetPosition(float,float,float) */

void __thiscall
BaseObject::setCurrentTargetPosition(BaseObject *this,float param_1,float param_2,float param_3)
{
  this->currentTargetXPositionValue = param_1;
  this->currentTargetYPositionValue = param_2;
  this->currentTargetZPositionValue = param_3;
  return;
}

// --------------------------------------------------

