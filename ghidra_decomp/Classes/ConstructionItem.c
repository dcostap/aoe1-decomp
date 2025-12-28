// Class: ConstructionItem
// Size:  0x80
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] `scalar_deleting_destructor'
// [02] loggingHistory
// [03] setLogHistory
// [04] toggleLogHistory
// [05] setHistoryFilename
// [06] loggingCommonHistory
// [07] setLogCommonHistory
// [08] toggleLogCommonHistory
// [09] loadState
// [10] saveState
// [11] gleanState
// [12] processMessage
// [13] update
// [14] setCallbackMessage
// [15] filterOutMessage
// [16] save
// [17] loadConstructionPlan
// [18] placeStructure
// [19] setBuilt
// [20] unplaceStructure
// [21] unplaceStructure
// [22] decrementBuildAttempts
// [23] incrementBuildAttempts
//
// Member Layout:
// [0x06C] ConstructionItem * next
// [0x070] ConstructionItem * prev
// [0x074] int inProgressValue
// [0x078] int builtValue
// [0x07C] int buildAttemptsValue
// ----------------------------------------------------------------

// Function: ConstructionItem
// Address: 0040a820
/* public: __thiscall ConstructionItem::ConstructionItem(void) */

ConstructionItem * __thiscall ConstructionItem::ConstructionItem(ConstructionItem *this)
{
  BaseItem::BaseItem((BaseItem *)this);
  this->_padding_ = (int)&_vftable_;
  this->next = (ConstructionItem *)0x0;
  this->prev = (ConstructionItem *)0x0;
  this->inProgressValue = 0;
  this->builtValue = 0;
  this->buildAttemptsValue = 0;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0040a850
/* public: virtual void * __thiscall ConstructionItem::`scalar deleting destructor'(unsigned int) */

void * __thiscall
ConstructionItem::_scalar_deleting_destructor_(ConstructionItem *this,uint param_1)
{
  ~ConstructionItem(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ConstructionItem
// Address: 0040a870
/* public: __thiscall
   ConstructionItem::ConstructionItem(float,float,float,float,float,float,int,char *) */

ConstructionItem * __thiscall
ConstructionItem::ConstructionItem
          (ConstructionItem *this,float param_1,float param_2,float param_3,float param_4,
          float param_5,float param_6,int param_7,char *param_8)
{
  BaseItem::BaseItem((BaseItem *)this,param_7,-1,-1,param_8,param_1,param_2,param_3,param_4,param_5,
                     param_6);
  this->_padding_ = (int)&_vftable_;
  this->next = (ConstructionItem *)0x0;
  this->prev = (ConstructionItem *)0x0;
  this->inProgressValue = 0;
  this->builtValue = 0;
  this->buildAttemptsValue = 0;
  return this;
}

// --------------------------------------------------

// Function: ConstructionItem
// Address: 0040a8d0
/* public: __thiscall ConstructionItem::ConstructionItem(class ConstructionItem *) */

ConstructionItem * __thiscall
ConstructionItem::ConstructionItem(ConstructionItem *this,ConstructionItem *param_1)
{
  BaseItem::BaseItem((BaseItem *)this,(BaseItem *)param_1);
  this->next = (ConstructionItem *)0x0;
  this->prev = (ConstructionItem *)0x0;
  this->inProgressValue = param_1->inProgressValue;
  this->builtValue = param_1->builtValue;
  this->buildAttemptsValue = param_1->buildAttemptsValue;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: ConstructionItem
// Address: 0040a910
/* public: __thiscall ConstructionItem::ConstructionItem(class ConstructionItem const &) */

ConstructionItem * __thiscall
ConstructionItem::ConstructionItem(ConstructionItem *this,ConstructionItem *param_1)
{
  BaseItem::BaseItem((BaseItem *)this,(BaseItem *)param_1);
  this->next = (ConstructionItem *)0x0;
  this->prev = (ConstructionItem *)0x0;
  this->inProgressValue = param_1->inProgressValue;
  this->builtValue = param_1->builtValue;
  this->buildAttemptsValue = param_1->buildAttemptsValue;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: ~ConstructionItem
// Address: 0040a950
/* public: virtual __thiscall ConstructionItem::~ConstructionItem(void) */

void __thiscall ConstructionItem::~ConstructionItem(ConstructionItem *this)
{
  this->_padding_ = (int)&_vftable_;
  BaseItem::~BaseItem((BaseItem *)this);
  return;
}

// --------------------------------------------------

// Function: inProgress
// Address: 0040aa00
/* public: int __thiscall ConstructionItem::inProgress(void)const  */

int __thiscall ConstructionItem::inProgress(ConstructionItem *this)
{
  return this->inProgressValue;
}

// --------------------------------------------------

// Function: built
// Address: 0040aa10
/* public: int __thiscall ConstructionItem::built(void)const  */

int __thiscall ConstructionItem::built(ConstructionItem *this)
{
  return this->builtValue;
}

// --------------------------------------------------

// Function: buildAttempts
// Address: 0040aa20
/* public: int __thiscall ConstructionItem::buildAttempts(void)const  */

int __thiscall ConstructionItem::buildAttempts(ConstructionItem *this)
{
  return this->buildAttemptsValue;
}

// --------------------------------------------------

// Function: setInProgress
// Address: 0040aa30
/* public: void __thiscall ConstructionItem::setInProgress(int) */

void __thiscall ConstructionItem::setInProgress(ConstructionItem *this,int param_1)
{
  this->inProgressValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setBuilt
// Address: 0040aa40
/* public: void __thiscall ConstructionItem::setBuilt(int) */

void __thiscall ConstructionItem::setBuilt(ConstructionItem *this,int param_1)
{
  this->builtValue = param_1;
  return;
}

// --------------------------------------------------

// Function: incrementBuildAttempts
// Address: 0040aa50
/* public: void __thiscall ConstructionItem::incrementBuildAttempts(void) */

void __thiscall ConstructionItem::incrementBuildAttempts(ConstructionItem *this)
{
  this->buildAttemptsValue = this->buildAttemptsValue + 1;
  return;
}

// --------------------------------------------------

// Function: decrementBuildAttempts
// Address: 0040aa60
/* public: void __thiscall ConstructionItem::decrementBuildAttempts(void) */

void __thiscall ConstructionItem::decrementBuildAttempts(ConstructionItem *this)
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

// Function: setBuildAttempts
// Address: 0040aa80
/* public: void __thiscall ConstructionItem::setBuildAttempts(int) */

void __thiscall ConstructionItem::setBuildAttempts(ConstructionItem *this,int param_1)
{
  this->buildAttemptsValue = param_1;
  return;
}

// --------------------------------------------------

