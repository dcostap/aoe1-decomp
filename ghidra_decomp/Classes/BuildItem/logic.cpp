// Class: BuildItem
// Function: BuildItem
// Address: 00408190
/* public: __thiscall BuildItem::BuildItem(void) */

BuildItem * __thiscall BuildItem::BuildItem(BuildItem *this)
{
  BaseItem::BaseItem((BaseItem *)this);
  this->next = (BuildItem *)0x0;
  this->prev = (BuildItem *)0x0;
  this->numberValue = 0;
  this->priorityValue = 0;
  this->progressValue = 0;
  this->builtValue = 0;
  this->buildAttemptsValue = 0;
  this->placeOnElevationValue = 0;
  this->numberBuildsValue = 0;
  this->skipCyclesValue = 0;
  this->permanentSkipValue = '\0';
  this->buildCategoryValue = -1;
  this->buildFromValue = -1;
  this->terrainSetValue = -1;
  this->buildCapValue = -1;
  this->_padding_ = (int)&_vftable_;
  this->terrainAdjacencyValue[0] = -1;
  this->terrainAdjacencyValue[1] = -1;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00408200
/* public: virtual void * __thiscall BuildItem::`vector deleting destructor'(unsigned int) */

void * __thiscall BuildItem::_vector_deleting_destructor_(BuildItem *this,uint param_1)
{
  ~BuildItem(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: BuildItem
// Address: 00408220
/* public: __thiscall BuildItem::BuildItem(int,int,int,int,int,int,char
   *,float,float,float,int,int,int,int) */

BuildItem * __thiscall
BuildItem::BuildItem
          (BuildItem *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
          char *param_7,float param_8,float param_9,float param_10,int param_11,int param_12,
          int param_13,int param_14)
{
  BaseItem::BaseItem((BaseItem *)this,param_2,-1,param_3,param_7,-1.0,-1.0,-1.0,param_8,param_9,
                     param_10);
  this->buildCategoryValue = param_1;
  this->numberValue = param_4;
  this->priorityValue = param_5;
  this->next = (BuildItem *)0x0;
  this->prev = (BuildItem *)0x0;
  this->progressValue = 0;
  this->builtValue = 0;
  this->buildAttemptsValue = 0;
  this->numberBuildsValue = 0;
  this->skipCyclesValue = 0;
  this->permanentSkipValue = '\0';
  this->buildFromValue = param_6;
  this->terrainSetValue = param_11;
  this->terrainAdjacencyValue[0] = param_12;
  this->placeOnElevationValue = param_14;
  this->buildCapValue = -1;
  this->_padding_ = (int)&_vftable_;
  this->terrainAdjacencyValue[1] = param_13;
  return this;
}

// --------------------------------------------------

// Function: BuildItem
// Address: 004082f0
/* public: __thiscall BuildItem::BuildItem(class BuildItem *) */

BuildItem * __thiscall BuildItem::BuildItem(BuildItem *this,BuildItem *param_1)
{
  BaseItem::BaseItem((BaseItem *)this,(BaseItem *)param_1);
  this->next = (BuildItem *)0x0;
  this->prev = (BuildItem *)0x0;
  this->buildCategoryValue = param_1->buildCategoryValue;
  this->numberValue = param_1->numberValue;
  this->priorityValue = param_1->priorityValue;
  this->progressValue = param_1->progressValue;
  this->builtValue = param_1->progressValue;
  this->buildAttemptsValue = param_1->buildAttemptsValue;
  this->buildFromValue = param_1->buildFromValue;
  this->terrainSetValue = param_1->terrainSetValue;
  this->placeOnElevationValue = param_1->placeOnElevationValue;
  this->numberBuildsValue = 0;
  this->buildCapValue = -1;
  this->skipCyclesValue = 0;
  this->permanentSkipValue = '\0';
  this->_padding_ = (int)&_vftable_;
  this->terrainAdjacencyValue[0] = param_1->terrainAdjacencyValue[0];
  this->terrainAdjacencyValue[1] = param_1->terrainAdjacencyValue[1];
  return this;
}

// --------------------------------------------------

// Function: BuildItem
// Address: 004083b0
/* public: __thiscall BuildItem::BuildItem(class BuildItem const &) */

BuildItem * __thiscall BuildItem::BuildItem(BuildItem *this,BuildItem *param_1)
{
  BaseItem::BaseItem((BaseItem *)this,(BaseItem *)param_1);
  this->next = (BuildItem *)0x0;
  this->prev = (BuildItem *)0x0;
  this->buildCategoryValue = param_1->buildCategoryValue;
  this->numberValue = param_1->numberValue;
  this->priorityValue = param_1->priorityValue;
  this->progressValue = param_1->progressValue;
  this->builtValue = param_1->progressValue;
  this->buildAttemptsValue = param_1->buildAttemptsValue;
  this->buildFromValue = param_1->buildFromValue;
  this->terrainSetValue = param_1->terrainSetValue;
  this->placeOnElevationValue = param_1->placeOnElevationValue;
  this->numberBuildsValue = 0;
  this->buildCapValue = -1;
  this->skipCyclesValue = 0;
  this->permanentSkipValue = '\0';
  this->_padding_ = (int)&_vftable_;
  this->terrainAdjacencyValue[0] = param_1->terrainAdjacencyValue[0];
  this->terrainAdjacencyValue[1] = param_1->terrainAdjacencyValue[1];
  return this;
}

// --------------------------------------------------

// Function: ~BuildItem
// Address: 00408470
/* public: virtual __thiscall BuildItem::~BuildItem(void) */

void __thiscall BuildItem::~BuildItem(BuildItem *this)
{
  this->_padding_ = (int)&_vftable_;
  BaseItem::~BaseItem((BaseItem *)this);
  return;
}

// --------------------------------------------------

// Function: buildCategory
// Address: 00408500
/* public: int __thiscall BuildItem::buildCategory(void)const  */

int __thiscall BuildItem::buildCategory(BuildItem *this)
{
  return this->buildCategoryValue;
}

// --------------------------------------------------

// Function: number
// Address: 00408510
/* public: int __thiscall BuildItem::number(void)const  */

int __thiscall BuildItem::number(BuildItem *this)
{
  return this->numberValue;
}

// --------------------------------------------------

// Function: priority
// Address: 00408520
/* public: int __thiscall BuildItem::priority(void)const  */

int __thiscall BuildItem::priority(BuildItem *this)
{
  return this->priorityValue;
}

// --------------------------------------------------

// Function: inProgress
// Address: 00408530
/* public: int __thiscall BuildItem::inProgress(void)const  */

int __thiscall BuildItem::inProgress(BuildItem *this)
{
  return this->progressValue;
}

// --------------------------------------------------

// Function: built
// Address: 00408540
/* public: int __thiscall BuildItem::built(void)const  */

int __thiscall BuildItem::built(BuildItem *this)
{
  return this->builtValue;
}

// --------------------------------------------------

// Function: buildAttempts
// Address: 00408550
/* public: int __thiscall BuildItem::buildAttempts(void)const  */

int __thiscall BuildItem::buildAttempts(BuildItem *this)
{
  return this->buildAttemptsValue;
}

// --------------------------------------------------

// Function: buildFrom
// Address: 00408560
/* public: int __thiscall BuildItem::buildFrom(void)const  */

int __thiscall BuildItem::buildFrom(BuildItem *this)
{
  return this->buildFromValue;
}

// --------------------------------------------------

// Function: terrainSet
// Address: 00408570
/* public: int __thiscall BuildItem::terrainSet(void)const  */

int __thiscall BuildItem::terrainSet(BuildItem *this)
{
  return this->terrainSetValue;
}

// --------------------------------------------------

// Function: terrainAdjacency
// Address: 00408580
/* public: int __thiscall BuildItem::terrainAdjacency(int)const  */

int __thiscall BuildItem::terrainAdjacency(BuildItem *this,int param_1)
{
  if ((0 < param_1) && (param_1 < 3)) {
    return this->terrainAdjacencyValue[param_1 + -1];
  }
  return -1;
}

// --------------------------------------------------

// Function: placeOnElevation
// Address: 004085a0
/* public: int __thiscall BuildItem::placeOnElevation(void)const  */

int __thiscall BuildItem::placeOnElevation(BuildItem *this)
{
  return this->placeOnElevationValue;
}

// --------------------------------------------------

// Function: setInProgress
// Address: 004085b0
/* public: void __thiscall BuildItem::setInProgress(int) */

void __thiscall BuildItem::setInProgress(BuildItem *this,int param_1)
{
  this->progressValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setBuilt
// Address: 004085c0
/* public: void __thiscall BuildItem::setBuilt(int) */

void __thiscall BuildItem::setBuilt(BuildItem *this,int param_1)
{
  this->builtValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setBuildAttempts
// Address: 004085d0
/* public: void __thiscall BuildItem::setBuildAttempts(int) */

void __thiscall BuildItem::setBuildAttempts(BuildItem *this,int param_1)
{
  this->buildAttemptsValue = param_1;
  return;
}

// --------------------------------------------------

// Function: incrementBuildAttempts
// Address: 004085e0
/* public: void __thiscall BuildItem::incrementBuildAttempts(void) */

void __thiscall BuildItem::incrementBuildAttempts(BuildItem *this)
{
  this->buildAttemptsValue = this->buildAttemptsValue + 1;
  return;
}

// --------------------------------------------------

// Function: decrementBuildAttempts
// Address: 004085f0
/* public: void __thiscall BuildItem::decrementBuildAttempts(void) */

void __thiscall BuildItem::decrementBuildAttempts(BuildItem *this)
{
  int iVar1;
  
  iVar1 = this->buildAttemptsValue + -1;
  this->buildAttemptsValue = iVar1;
  if (iVar1 < 0) {
    this->buildAttemptsValue = 0;
  }
  return;
}

// --------------------------------------------------

// Function: numberBuilds
// Address: 00408610
/* public: int __thiscall BuildItem::numberBuilds(void) */

int __thiscall BuildItem::numberBuilds(BuildItem *this)
{
  return this->numberBuildsValue;
}

// --------------------------------------------------

// Function: incrementNumberBuilds
// Address: 00408620
/* public: void __thiscall BuildItem::incrementNumberBuilds(void) */

void __thiscall BuildItem::incrementNumberBuilds(BuildItem *this)
{
  this->numberBuildsValue = this->numberBuildsValue + 1;
  return;
}

// --------------------------------------------------

// Function: setNumberBuilds
// Address: 00408630
/* public: void __thiscall BuildItem::setNumberBuilds(int) */

void __thiscall BuildItem::setNumberBuilds(BuildItem *this,int param_1)
{
  this->numberBuildsValue = param_1;
  return;
}

// --------------------------------------------------

// Function: buildCap
// Address: 00408640
/* public: int __thiscall BuildItem::buildCap(void) */

int __thiscall BuildItem::buildCap(BuildItem *this)
{
  return this->buildCapValue;
}

// --------------------------------------------------

// Function: setBuildCap
// Address: 00408650
/* public: void __thiscall BuildItem::setBuildCap(int) */

void __thiscall BuildItem::setBuildCap(BuildItem *this,int param_1)
{
  this->buildCapValue = param_1;
  return;
}

// --------------------------------------------------

// Function: skipCycles
// Address: 00408660
/* public: int __thiscall BuildItem::skipCycles(void) */

int __thiscall BuildItem::skipCycles(BuildItem *this)
{
  return this->skipCyclesValue;
}

// --------------------------------------------------

// Function: incrementSkipCycles
// Address: 00408670
/* public: void __thiscall BuildItem::incrementSkipCycles(void) */

void __thiscall BuildItem::incrementSkipCycles(BuildItem *this)
{
  this->skipCyclesValue = this->skipCyclesValue + 1;
  return;
}

// --------------------------------------------------

// Function: setSkipCycles
// Address: 00408680
/* public: void __thiscall BuildItem::setSkipCycles(int) */

void __thiscall BuildItem::setSkipCycles(BuildItem *this,int param_1)
{
  this->skipCyclesValue = param_1;
  return;
}

// --------------------------------------------------

// Function: permanentSkip
// Address: 00408690
/* public: unsigned char __thiscall BuildItem::permanentSkip(void) */

uchar __thiscall BuildItem::permanentSkip(BuildItem *this)
{
  return this->permanentSkipValue;
}

// --------------------------------------------------

// Function: setPermanentSkip
// Address: 004086a0
/* public: void __thiscall BuildItem::setPermanentSkip(unsigned char) */

void __thiscall BuildItem::setPermanentSkip(BuildItem *this,uchar param_1)
{
  this->permanentSkipValue = param_1;
  return;
}

// --------------------------------------------------

