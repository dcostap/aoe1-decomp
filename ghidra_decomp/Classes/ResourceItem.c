// Class: ResourceItem
// Size:  0x70
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
//
// Member Layout:
// [0x004] ResourceItem * next
// [0x008] ResourceItem * prev
// [0x00C] int[8] valueValue (sz: 0x20)
// [0x02C] int[8] sortedValue (sz: 0x20)
// [0x04C] int[8] sortedIndexValue (sz: 0x20)
// [0x06C] int numberValue
// ----------------------------------------------------------------

// Function: ResourceItem
// Address: 00411ec0
/* public: __thiscall ResourceItem::ResourceItem(void) */

void __thiscall ResourceItem::ResourceItem(ResourceItem *this)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = 8;
  this->next = (ResourceItem *)0x0;
  this->prev = (ResourceItem *)0x0;
  this->numberValue = 0;
  this->_padding_ = (int)&_vftable_;
  piVar1 = this->sortedValue;
  do {
    piVar1[-8] = -1;
    *piVar1 = -1;
    piVar1[8] = -1;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00411ef0
/* public: virtual void * __thiscall ResourceItem::`scalar deleting destructor'(unsigned int) */

void * __thiscall ResourceItem::_scalar_deleting_destructor_(ResourceItem *this,uint param_1)
{
  ~ResourceItem(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ResourceItem
// Address: 00411f10
/* public: __thiscall ResourceItem::ResourceItem(int) */

void __thiscall ResourceItem::ResourceItem(ResourceItem *this,int param_1)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  this->next = (ResourceItem *)0x0;
  this->prev = (ResourceItem *)0x0;
  this->numberValue = param_1;
  this->_padding_ = (int)&_vftable_;
  if (0 < param_1) {
    piVar1 = this->sortedValue;
    do {
      if (7 < iVar2) {
        return;
      }
      piVar1[-8] = 0;
      *piVar1 = -1;
      piVar1[8] = -1;
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < this->numberValue);
  }
  if (iVar2 < 8) {
    piVar1 = this->sortedValue + iVar2;
    iVar2 = 8 - iVar2;
    do {
      piVar1[-8] = -1;
      *piVar1 = -1;
      piVar1[8] = -1;
      piVar1 = piVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: ResourceItem
// Address: 00411f80
/* public: __thiscall ResourceItem::ResourceItem(int,int *) */

void __thiscall ResourceItem::ResourceItem(ResourceItem *this,int param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  this->next = (ResourceItem *)0x0;
  this->prev = (ResourceItem *)0x0;
  this->numberValue = param_1;
  this->_padding_ = (int)&_vftable_;
  if (0 < param_1) {
    piVar1 = this->sortedValue;
    do {
      if (7 < iVar2) {
        return;
      }
      iVar2 = iVar2 + 1;
      piVar1[-8] = *param_2;
      *piVar1 = -1;
      piVar1[8] = -1;
      param_2 = param_2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < this->numberValue);
  }
  if (iVar2 < 8) {
    piVar1 = this->sortedValue + iVar2;
    iVar2 = 8 - iVar2;
    do {
      piVar1[-8] = -1;
      *piVar1 = -1;
      piVar1[8] = -1;
      piVar1 = piVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: ResourceItem
// Address: 00411ff0
/* public: __thiscall ResourceItem::ResourceItem(class ResourceItem const &) */

void __thiscall ResourceItem::ResourceItem(ResourceItem *this,ResourceItem *param_1)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  this->next = (ResourceItem *)0x0;
  this->prev = (ResourceItem *)0x0;
  iVar1 = param_1->numberValue;
  this->_padding_ = (int)&_vftable_;
  this->numberValue = iVar1;
  if (0 < iVar1) {
    piVar3 = param_1->sortedIndexValue;
    piVar2 = this->valueValue;
    do {
      if (7 < iVar4) {
        return;
      }
      iVar4 = iVar4 + 1;
      *piVar2 = *(int *)(((int)param_1 - (int)this) + (int)piVar2);
      piVar2[8] = piVar3[-8];
      piVar2[0x10] = *piVar3;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < this->numberValue);
  }
  return;
}

// --------------------------------------------------

// Function: ResourceItem
// Address: 00412050
/* public: __thiscall ResourceItem::ResourceItem(class ResourceItem *) */

void __thiscall ResourceItem::ResourceItem(ResourceItem *this,ResourceItem *param_1)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  this->next = (ResourceItem *)0x0;
  this->prev = (ResourceItem *)0x0;
  iVar1 = param_1->numberValue;
  this->_padding_ = (int)&_vftable_;
  this->numberValue = iVar1;
  if (0 < iVar1) {
    piVar3 = param_1->sortedIndexValue;
    piVar2 = this->valueValue;
    do {
      if (7 < iVar4) {
        return;
      }
      iVar4 = iVar4 + 1;
      *piVar2 = *(int *)(((int)param_1 - (int)this) + (int)piVar2);
      piVar2[8] = piVar3[-8];
      piVar2[0x10] = *piVar3;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < this->numberValue);
  }
  return;
}

// --------------------------------------------------

// Function: ~ResourceItem
// Address: 004120b0
/* public: virtual __thiscall ResourceItem::~ResourceItem(void) */

void __thiscall ResourceItem::~ResourceItem(ResourceItem *this)
{
  this->_padding_ = (int)&_vftable_;
  return;
}

// --------------------------------------------------

// Function: operator+=
// Address: 004120c0
/* public: class ResourceItem & __thiscall ResourceItem::operator+=(class ResourceItem const &) */

ResourceItem * __thiscall ResourceItem::operator+=(ResourceItem *this,ResourceItem *param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((this->numberValue == param_1->numberValue) && (iVar2 = 0, 0 < this->numberValue)) {
    piVar1 = this->valueValue;
    do {
      iVar2 = iVar2 + 1;
      *piVar1 = *piVar1 + *(int *)(((int)param_1 - (int)this) + (int)piVar1);
      piVar1 = piVar1 + 1;
    } while (iVar2 < this->numberValue);
  }
  return this;
}

// --------------------------------------------------

// Function: value
// Address: 00412180
/* public: int __thiscall ResourceItem::value(int)const  */

int __thiscall ResourceItem::value(ResourceItem *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < this->numberValue)) {
    return this->valueValue[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: setValue
// Address: 004121a0
/* public: void __thiscall ResourceItem::setValue(int,int) */

void __thiscall ResourceItem::setValue(ResourceItem *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < this->numberValue)) {
    this->valueValue[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: incrementValue
// Address: 004121c0
/* public: void __thiscall ResourceItem::incrementValue(int,int) */

void __thiscall ResourceItem::incrementValue(ResourceItem *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < this->numberValue)) {
    this->valueValue[param_1] = this->valueValue[param_1] + param_2;
  }
  return;
}

// --------------------------------------------------

// Function: setAllValues
// Address: 004121e0
/* public: void __thiscall ResourceItem::setAllValues(int) */

void __thiscall ResourceItem::setAllValues(ResourceItem *this,int param_1)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = this->valueValue;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = param_1;
    piVar2 = piVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: number
// Address: 00412200
/* public: int __thiscall ResourceItem::number(void)const  */

int __thiscall ResourceItem::number(ResourceItem *this)
{
  return this->numberValue;
}

// --------------------------------------------------

// Function: largestValueIndex
// Address: 00412210
/* public: int __thiscall ResourceItem::largestValueIndex(int) */

int __thiscall ResourceItem::largestValueIndex(ResourceItem *this,int param_1)
{
  int iVar1;
  
  if (param_1 <= this->numberValue) {
    iVar1 = sortLarge(this);
    if (iVar1 == 1) {
      return this->sortedValue[param_1 + 7];
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: sortLarge
// Address: 00412240
/* protected: int __thiscall ResourceItem::sortLarge(void) */

int __thiscall ResourceItem::sortLarge(ResourceItem *this)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int i;
  int local_c;
  
  iVar4 = 0;
  if (0 < this->numberValue) {
    piVar2 = this->sortedValue;
    do {
      *piVar2 = piVar2[-8];
      piVar2[8] = iVar4;
      iVar4 = iVar4 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar4 < this->numberValue);
  }
  iVar4 = this->numberValue;
  local_c = 0;
  if (0 < iVar4) {
    piVar2 = this->sortedValue;
    do {
      iVar1 = local_c + 1;
      iVar5 = local_c;
      if (iVar1 < iVar4) {
        iVar6 = (-0x2c - (int)this) + (int)piVar2;
        iVar3 = iVar1;
        i = (int)piVar2;
        do {
          i = i + 4;
          if (*(int *)((int)this->sortedValue + iVar6) < *(int *)i) {
            iVar6 = iVar3 * 4;
            iVar5 = iVar3;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar4);
      }
      if (iVar5 != local_c) {
        iVar4 = *piVar2;
        *piVar2 = this->sortedValue[iVar5];
        this->sortedValue[iVar5] = iVar4;
        iVar4 = piVar2[8];
        piVar2[8] = this->sortedIndexValue[iVar5];
        this->sortedIndexValue[iVar5] = iVar4;
      }
      iVar4 = this->numberValue;
      piVar2 = piVar2 + 1;
      local_c = iVar1;
    } while (iVar1 < iVar4);
  }
  return 1;
}

// --------------------------------------------------

