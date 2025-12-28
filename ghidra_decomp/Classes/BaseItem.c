// Class: BaseItem
// Size:  0x6C
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] `vector_deleting_destructor'
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
// [18] displayBuildList
// [19] loadBuildList
// [20] numberBuiltOrInProgressItemsOfType
//
// Member Layout:
// [0x004] int typeIDValue
// [0x008] int gameIDValue
// [0x00C] int uniqueIDValue
// [0x010] char[64] nameValue (sz: 0x40)
// [0x050] float xValue
// [0x054] float yValue
// [0x058] float zValue
// [0x05C] float xSizeValue
// [0x060] float ySizeValue
// [0x064] float zSizeValue
// [0x068] int skipValue
// ----------------------------------------------------------------

// Function: BaseItem
// Address: 00407d80
// [HELPER] s_: ""
BaseItem * __thiscall BaseItem::BaseItem(BaseItem *this)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  this->typeIDValue = -1;
  this->gameIDValue = -1;
  this->uniqueIDValue = -1;
  this->xValue = 0.0;
  this->yValue = 0.0;
  this->zValue = 0.0;
  this->xSizeValue = 0.0;
  this->ySizeValue = 0.0;
  this->zSizeValue = 0.0;
  this->skipValue = 0;
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

// Function: `scalar_deleting_destructor'
// Address: 00407de0
void * __thiscall BaseItem::_scalar_deleting_destructor_(BaseItem *this,uint param_1)
{
  ~BaseItem(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: BaseItem
// Address: 00407e00
BaseItem * __thiscall
BaseItem::BaseItem(BaseItem *this,int param_1,int param_2,int param_3,char *param_4,float param_5,
                  float param_6,float param_7,float param_8,float param_9,float param_10)
{
  this->typeIDValue = param_1;
  this->gameIDValue = param_2;
  this->xValue = param_5;
  this->yValue = param_6;
  this->uniqueIDValue = param_3;
  this->xSizeValue = param_8;
  this->ySizeValue = param_9;
  this->zValue = param_7;
  this->zSizeValue = param_10;
  this->skipValue = 0;
  this->_padding_ = (int)&_vftable_;
  strncpy(this->nameValue,param_4,0x3f);
  return this;
}

// --------------------------------------------------

// Function: BaseItem
// Address: 00407e70
BaseItem * __thiscall BaseItem::BaseItem(BaseItem *this,BaseItem *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  this->typeIDValue = param_1->typeIDValue;
  this->gameIDValue = param_1->gameIDValue;
  this->uniqueIDValue = param_1->uniqueIDValue;
  this->xValue = param_1->xValue;
  this->yValue = param_1->yValue;
  this->zValue = param_1->zValue;
  this->xSizeValue = param_1->xSizeValue;
  this->ySizeValue = param_1->ySizeValue;
  this->zSizeValue = param_1->zSizeValue;
  this->skipValue = param_1->skipValue;
  uVar2 = 0xffffffff;
  this->_padding_ = (int)&_vftable_;
  pcVar4 = param_1->nameValue;
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

// Function: BaseItem
// Address: 00407ef0
BaseItem * __thiscall BaseItem::BaseItem(BaseItem *this,BaseItem *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  this->typeIDValue = param_1->typeIDValue;
  this->gameIDValue = param_1->gameIDValue;
  this->uniqueIDValue = param_1->uniqueIDValue;
  this->xValue = param_1->xValue;
  this->yValue = param_1->yValue;
  this->zValue = param_1->zValue;
  this->xSizeValue = param_1->xSizeValue;
  this->ySizeValue = param_1->ySizeValue;
  this->zSizeValue = param_1->zSizeValue;
  this->skipValue = param_1->skipValue;
  uVar2 = 0xffffffff;
  this->_padding_ = (int)&_vftable_;
  pcVar4 = param_1->nameValue;
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

// Function: ~BaseItem
// Address: 00407f70
void __thiscall BaseItem::~BaseItem(BaseItem *this)
{
  this->_padding_ = (int)&_vftable_;
  return;
}

// --------------------------------------------------

// Function: typeID
// Address: 00408020
int __thiscall BaseItem::typeID(BaseItem *this)
{
  return this->typeIDValue;
}

// --------------------------------------------------

// Function: gameID
// Address: 00408030
int __thiscall BaseItem::gameID(BaseItem *this)
{
  return this->gameIDValue;
}

// --------------------------------------------------

// Function: uniqueID
// Address: 00408040
int __thiscall BaseItem::uniqueID(BaseItem *this)
{
  return this->uniqueIDValue;
}

// --------------------------------------------------

// Function: name
// Address: 00408050
char * __thiscall BaseItem::name(BaseItem *this)
{
  return this->nameValue;
}

// --------------------------------------------------

// Function: x
// Address: 00408060
float __thiscall BaseItem::x(BaseItem *this)
{
  return this->xValue;
}

// --------------------------------------------------

// Function: y
// Address: 00408070
float __thiscall BaseItem::y(BaseItem *this)
{
  return this->yValue;
}

// --------------------------------------------------

// Function: z
// Address: 00408080
float __thiscall BaseItem::z(BaseItem *this)
{
  return this->zValue;
}

// --------------------------------------------------

// Function: xSize
// Address: 00408090
float __thiscall BaseItem::xSize(BaseItem *this)
{
  return this->xSizeValue;
}

// --------------------------------------------------

// Function: ySize
// Address: 004080a0
float __thiscall BaseItem::ySize(BaseItem *this)
{
  return this->ySizeValue;
}

// --------------------------------------------------

// Function: zSize
// Address: 004080b0
float __thiscall BaseItem::zSize(BaseItem *this)
{
  return this->zSizeValue;
}

// --------------------------------------------------

// Function: skip
// Address: 004080c0
int __thiscall BaseItem::skip(BaseItem *this)
{
  return this->skipValue;
}

// --------------------------------------------------

// Function: setTypeID
// Address: 004080d0
void __thiscall BaseItem::setTypeID(BaseItem *this,int param_1)
{
  this->typeIDValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setGameID
// Address: 004080e0
void __thiscall BaseItem::setGameID(BaseItem *this,int param_1)
{
  this->gameIDValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setUniqueID
// Address: 004080f0
void __thiscall BaseItem::setUniqueID(BaseItem *this,int param_1)
{
  this->uniqueIDValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setName
// Address: 00408100
void __thiscall BaseItem::setName(BaseItem *this,char *param_1)
{
  strncpy(this->nameValue,param_1,0x3f);
  return;
}

// --------------------------------------------------

// Function: setX
// Address: 00408120
void __thiscall BaseItem::setX(BaseItem *this,float param_1)
{
  this->xValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setY
// Address: 00408130
void __thiscall BaseItem::setY(BaseItem *this,float param_1)
{
  this->yValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setZ
// Address: 00408140
void __thiscall BaseItem::setZ(BaseItem *this,float param_1)
{
  this->zValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setXSize
// Address: 00408150
void __thiscall BaseItem::setXSize(BaseItem *this,float param_1)
{
  this->xSizeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setYSize
// Address: 00408160
void __thiscall BaseItem::setYSize(BaseItem *this,float param_1)
{
  this->ySizeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setZSize
// Address: 00408170
void __thiscall BaseItem::setZSize(BaseItem *this,float param_1)
{
  this->zSizeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setSkip
// Address: 00408180
void __thiscall BaseItem::setSkip(BaseItem *this,int param_1)
{
  this->skipValue = param_1;
  return;
}

// --------------------------------------------------

