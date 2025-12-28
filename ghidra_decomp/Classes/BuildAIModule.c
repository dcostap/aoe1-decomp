// Class: BuildAIModule
// Size:  0x5BC
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
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
// [16] displayBuildList
// [17] loadBuildList
// [18] numberBuiltOrInProgressItemsOfType
//
// Member Layout:
// [0x0F0] BuildItem buildList (sz: 0xB0)
// [0x1A0] int buildListLengthValue
// [0x1A4] char[257] buildListNameValue (sz: 0x101)
// [0x2A5] char[257] lastBuildItemRequestedValue (sz: 0x101)
// [0x3A6] char[257] currentBuildItemRequestedValue (sz: 0x101)
// [0x4A7] char[257] nextBuildItemRequestedValue (sz: 0x101)
// [0x5A8] int numberItemsIntoBuildListValue
// [0x5AC] ManagedArray<int> typesToIgnore (sz: 0x10)
// ----------------------------------------------------------------

// Function: BuildAIModule
// Address: 004086b0
// [HELPER] s_: ""
// [HELPER] s_Build_AI: "Build AI"
// [HELPER] s_None: "None"
/* public: __thiscall BuildAIModule::BuildAIModule(void *,int) */

BuildAIModule * __thiscall
BuildAIModule::BuildAIModule(BuildAIModule *this,void *param_1,int param_2)
{
  BuildItem *this_00;
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
  pcStack_8 = FUN_0055c456;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
                    /* language.dll match for 0x3e9: "Age of Empires" */
  AIModule::AIModule((AIModule *)this,s_Build_AI,0x3e9,param_2,param_1);
  this_00 = &this->buildList;
  local_4 = 0;
  BuildItem::BuildItem(this_00);
  this->buildListLengthValue = 0;
  this->numberItemsIntoBuildListValue = 0;
  (this->typesToIgnore).value = (int *)0x0;
  (this->typesToIgnore).numberValue = 0;
  (this->typesToIgnore).desiredNumberValue = 0;
  (this->typesToIgnore).maximumSizeValue = 0;
  uVar2 = 0xffffffff;
  this->_padding_ = (int)&_vftable_;
  (this->buildList).next = this_00;
  (this->buildList).prev = this_00;
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
  pcVar5 = this->buildListNameValue;
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
  uVar2 = 0xffffffff;
  pcVar4 = &s_None;
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
  pcVar5 = this->lastBuildItemRequestedValue;
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
  uVar2 = 0xffffffff;
  pcVar4 = &s_None;
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
  pcVar5 = this->currentBuildItemRequestedValue;
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
  uVar2 = 0xffffffff;
  pcVar4 = &s_None;
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
  pcVar5 = this->nextBuildItemRequestedValue;
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

// Function: `scalar_deleting_destructor'
// Address: 00408820
/* public: virtual void * __thiscall BuildAIModule::`scalar deleting destructor'(unsigned int) */

void * __thiscall BuildAIModule::_scalar_deleting_destructor_(BuildAIModule *this,uint param_1)
{
  ~BuildAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: BuildAIModule
// Address: 00408840
// [HELPER] s_Build_AI: "Build AI"
// [HELPER] s_None: "None"
/* WARNING: Variable defined which should be unmapped: tempInt */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall BuildAIModule::BuildAIModule(int,int) */

BuildAIModule * __thiscall BuildAIModule::BuildAIModule(BuildAIModule *this,int param_1,int param_2)
{
  char cVar1;
  BuildItem *pBVar2;
  int iVar3;
  BuildItem *pBVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  int tempInt;
  int buildCap;
  int builtValue;
  int inProgressValue;
  int buildAttemptsValue;
  int terrainAdjOne;
  int skipValue;
  float zSize;
  int gameID;
  float xSize;
  float x;
  int uniqueID;
  float y;
  int buildCategory;
  float z;
  int terrainAdjTwo;
  int numberBuilds;
  float ySize;
  int numberSkipCycles;
  int typeID;
  uchar permanentSkip;
  int terrainSet;
  int placeOnElevation;
  int buildFrom;
  int local_11c;
  BuildAIModule *local_118;
  char name [257];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c49b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_118 = this;
                    /* language.dll match for 0x3e9: "Age of Empires" */
  AIModule::AIModule((AIModule *)this,s_Build_AI,0x3e9,param_1,(void *)0x0);
  pBVar4 = &this->buildList;
  local_4 = 0;
  BuildItem::BuildItem(pBVar4);
  this->numberItemsIntoBuildListValue = 0;
  this->buildListLengthValue = 0;
  (this->typesToIgnore).value = (int *)0x0;
  (this->typesToIgnore).numberValue = 0;
  (this->typesToIgnore).desiredNumberValue = 0;
  (this->typesToIgnore).maximumSizeValue = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  this->_padding_ = (int)&_vftable_;
  (this->buildList).next = pBVar4;
  (this->buildList).prev = pBVar4;
  rge_read(param_2,&this->buildListLengthValue,4);
  rge_read(param_2,&buildCap,4);
  rge_read(param_2,this->buildListNameValue,buildCap);
  this->buildListNameValue[buildCap] = '\0';
  rge_read(param_2,&buildCap,4);
  rge_read(param_2,this->lastBuildItemRequestedValue,buildCap);
  this->lastBuildItemRequestedValue[buildCap] = '\0';
  rge_read(param_2,&buildCap,4);
  rge_read(param_2,this->currentBuildItemRequestedValue,buildCap);
  this->currentBuildItemRequestedValue[buildCap] = '\0';
  if (save_game_version < _DAT_0056e784) {
    uVar5 = 0xffffffff;
    pcVar7 = &s_None;
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar7 = pcVar8 + -uVar5;
    pcVar8 = this->nextBuildItemRequestedValue;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  else {
    rge_read(param_2,&buildCap,4);
    rge_read(param_2,this->nextBuildItemRequestedValue,buildCap);
    this->nextBuildItemRequestedValue[buildCap] = '\0';
  }
  iVar9 = 0;
  rge_read(param_2,&this->numberItemsIntoBuildListValue,4);
  if (0 < this->buildListLengthValue) {
    do {
      rge_read(param_2,&buildCap,4);
      rge_read(param_2,name + 4,buildCap);
      name[buildCap + 4] = '\0';
      rge_read(param_2,&permanentSkip,4);
      rge_read(param_2,&xSize,4);
      rge_read(param_2,&y,4);
      rge_read(param_2,&uniqueID,4);
      rge_read(param_2,&buildCategory,4);
      rge_read(param_2,&terrainAdjTwo,4);
      rge_read(param_2,&x,4);
      rge_read(param_2,&numberSkipCycles,4);
      rge_read(param_2,&gameID,4);
      rge_read(param_2,&zSize,4);
      rge_read(param_2,&z,4);
      rge_read(param_2,&buildAttemptsValue,4);
      rge_read(param_2,&inProgressValue,4);
      rge_read(param_2,&terrainAdjOne,4);
      rge_read(param_2,&local_11c,4);
      rge_read(param_2,&placeOnElevation,4);
      rge_read(param_2,&skipValue,4);
      rge_read(param_2,&numberBuilds,4);
      rge_read(param_2,&buildFrom,4);
      rge_read(param_2,&ySize,4);
      builtValue = -1;
      if (_DAT_0056e788 <= save_game_version) {
        rge_read(param_2,&builtValue,4);
      }
      rge_read(param_2,&typeID,4);
      rge_read(param_2,&terrainSet,1);
      name._0_4_ = operator_new(0xb0);
      local_4._0_1_ = 3;
      if ((BuildItem *)name._0_4_ == (BuildItem *)0x0) {
        pBVar4 = (BuildItem *)0x0;
      }
      else {
        pBVar4 = (BuildItem *)
                 BuildItem::BuildItem
                           ((BuildItem *)name._0_4_,(int)z,_permanentSkip,(int)y,1,0,local_11c,
                            name + 4,x,(float)numberSkipCycles,(float)gameID,placeOnElevation,
                            skipValue,numberBuilds,buildFrom);
      }
      local_4 = CONCAT31(local_4._1_3_,2);
      BuildItem::setBuilt(pBVar4,inProgressValue);
      BuildItem::setInProgress(pBVar4,buildAttemptsValue);
      BuildItem::setBuildAttempts(pBVar4,terrainAdjOne);
      BaseItem::setSkip((BaseItem *)pBVar4,(int)zSize);
      BaseItem::setGameID((BaseItem *)pBVar4,(int)xSize);
      BaseItem::setX((BaseItem *)pBVar4,(float)uniqueID);
      BaseItem::setY((BaseItem *)pBVar4,(float)buildCategory);
      BaseItem::setZ((BaseItem *)pBVar4,(float)terrainAdjTwo);
      BuildItem::setNumberBuilds(pBVar4,(int)ySize);
      BuildItem::setBuildCap(pBVar4,builtValue);
      BuildItem::setSkipCycles(pBVar4,typeID);
      BuildItem::setPermanentSkip(pBVar4,(uchar)terrainSet);
      iVar9 = iVar9 + 1;
      pBVar4->next = &this->buildList;
      pBVar2 = (this->buildList).prev;
      pBVar4->prev = pBVar2;
      pBVar2->next = pBVar4;
      iVar3 = this->buildListLengthValue;
      (this->buildList).prev = pBVar4;
    } while (iVar9 < iVar3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~BuildAIModule
// Address: 00408d50
/* public: virtual __thiscall BuildAIModule::~BuildAIModule(void) */

void __thiscall BuildAIModule::~BuildAIModule(BuildAIModule *this)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_0055c4d4;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 2;
  if (0 < this->buildListLengthValue) {
    removeOldList(this);
  }
  piVar1 = (this->typesToIgnore).value;
  local_4._0_1_ = 1;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (this->typesToIgnore).value = (int *)0x0;
  }
  (this->typesToIgnore).numberValue = 0;
  (this->typesToIgnore).desiredNumberValue = 0;
  (this->typesToIgnore).maximumSizeValue = 0;
  local_4 = (uint)local_4._1_3_ << 8;
  BuildItem::~BuildItem(&this->buildList);
  local_4 = 0xffffffff;
  AIModule::~AIModule((AIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00408df0
/* WARNING: Variable defined which should be unmapped: tempInt */
/* public: virtual int __thiscall BuildAIModule::save(int) */

int __thiscall BuildAIModule::save(BuildAIModule *this,int param_1)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  BuildItem *this_00;
  char *pcVar5;
  char *pcVar6;
  int tempInt;
  float tempFloat;
  int tempBOOL;
  int iStack_110;
  uchar tempBYTE;
  uchar local_109;
  char tempString [257];
  
  tempString._0_4_ = this;
  rge_write(param_1,&this->buildListLengthValue,4);
  uVar3 = 0xffffffff;
  pcVar6 = this->buildListNameValue;
  do {
    pcVar2 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar2 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar2;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = tempString;
  pcVar2 = pcVar2 + -uVar3;
  for (uVar4 = uVar3 >> 2; pcVar6 = pcVar6 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar6 = tempString + 4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  tempFloat = (float)(~uVar3 - 1);
  rge_write(param_1,&tempFloat,4);
  uVar3 = 0xffffffff;
  pcVar6 = tempString + 4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  rge_write(param_1,tempString + 4,~uVar3 - 1);
  uVar3 = 0xffffffff;
  pcVar6 = this->lastBuildItemRequestedValue;
  do {
    pcVar2 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar2 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar2;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = tempString;
  pcVar2 = pcVar2 + -uVar3;
  for (uVar4 = uVar3 >> 2; pcVar6 = pcVar6 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar6 = tempString + 4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  tempFloat = (float)(~uVar3 - 1);
  rge_write(param_1,&tempFloat,4);
  uVar3 = 0xffffffff;
  pcVar6 = tempString + 4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  rge_write(param_1,tempString + 4,~uVar3 - 1);
  uVar3 = 0xffffffff;
  pcVar6 = this->currentBuildItemRequestedValue;
  do {
    pcVar2 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar2 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar2;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = tempString;
  pcVar2 = pcVar2 + -uVar3;
  for (uVar4 = uVar3 >> 2; pcVar6 = pcVar6 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar6 = tempString + 4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  tempFloat = (float)(~uVar3 - 1);
  rge_write(param_1,&tempFloat,4);
  uVar3 = 0xffffffff;
  pcVar6 = tempString + 4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  rge_write(param_1,tempString + 4,~uVar3 - 1);
  uVar3 = 0xffffffff;
  pcVar6 = this->nextBuildItemRequestedValue;
  do {
    pcVar2 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar2 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar2;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = tempString;
  pcVar2 = pcVar2 + -uVar3;
  for (uVar4 = uVar3 >> 2; pcVar6 = pcVar6 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar6 = tempString + 4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  tempFloat = (float)(~uVar3 - 1);
  rge_write(param_1,&tempFloat,4);
  uVar3 = 0xffffffff;
  pcVar6 = tempString + 4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  rge_write(param_1,tempString + 4,~uVar3 - 1);
  rge_write(param_1,&this->numberItemsIntoBuildListValue,4);
  this_00 = (this->buildList).next;
  tempString._0_4_ = tempString._0_4_ + 0xf0;
  if (this_00 != (BuildItem *)tempString._0_4_) {
    do {
      if (this_00 == (BuildItem *)0x0) {
        return 1;
      }
      pcVar2 = BaseItem::name((BaseItem *)this_00);
      uVar3 = 0xffffffff;
      pcVar6 = tempString;
      do {
        pcVar5 = pcVar2;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar5 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar5;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar2 = pcVar5 + -uVar3;
      for (uVar4 = uVar3 >> 2; pcVar6 = pcVar6 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar6 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar6 = pcVar6 + 1;
      }
      uVar3 = 0xffffffff;
      pcVar6 = tempString + 4;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      tempFloat = (float)(~uVar3 - 1);
      rge_write(param_1,&tempFloat,4);
      uVar3 = 0xffffffff;
      pcVar6 = tempString + 4;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      rge_write(param_1,tempString + 4,~uVar3 - 1);
      tempFloat = (float)BaseItem::typeID((BaseItem *)this_00);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BaseItem::gameID((BaseItem *)this_00);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BaseItem::uniqueID((BaseItem *)this_00);
      rge_write(param_1,&tempFloat,4);
      tempBOOL = (int)BaseItem::x((BaseItem *)this_00);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::y((BaseItem *)this_00);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::z((BaseItem *)this_00);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::xSize((BaseItem *)this_00);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::ySize((BaseItem *)this_00);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::zSize((BaseItem *)this_00);
      rge_write(param_1,&tempBOOL,4);
      iStack_110 = BaseItem::skip((BaseItem *)this_00);
      rge_write(param_1,&stack0xfffffef0,4);
      tempFloat = (float)BuildItem::buildCategory(this_00);
      rge_write(param_1,&tempFloat,4);
      iStack_110 = BuildItem::inProgress(this_00);
      rge_write(param_1,&stack0xfffffef0,4);
      iStack_110 = BuildItem::built(this_00);
      rge_write(param_1,&stack0xfffffef0,4);
      tempFloat = (float)BuildItem::buildAttempts(this_00);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BuildItem::buildFrom(this_00);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BuildItem::terrainSet(this_00);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BuildItem::terrainAdjacency(this_00,1);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BuildItem::terrainAdjacency(this_00,2);
      rge_write(param_1,&tempFloat,4);
      iStack_110 = BuildItem::placeOnElevation(this_00);
      rge_write(param_1,&stack0xfffffef0,4);
      tempFloat = (float)BuildItem::numberBuilds(this_00);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BuildItem::buildCap(this_00);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BuildItem::skipCycles(this_00);
      rge_write(param_1,&tempFloat,4);
      local_109 = BuildItem::permanentSkip(this_00);
      rge_write(param_1,&local_109,1);
      this_00 = this_00->next;
    } while (this_00 != (BuildItem *)tempString._0_4_);
  }
  return 1;
}

// --------------------------------------------------

// Function: displayBuildList
// Address: 004092f0
// [HELPER] s_BLT_Type___4d___20s_gID___4d_Cat: "BLT Type=%-4d %-20s gID=%-4d Cat=%d uID=%-3d inProg=%d bldAtt=%-2d skip=%d #b..."
// [HELPER] s_Build_list___s__: "Build list '%s':"
// [HELPER] s_____Type___4d___20s_gID___4d_Cat: "    Type=%-4d %-20s gID=%-4d Cat=%d uID=%-3d inProg=%d bldAtt=%-2d skip=%d #b..."
/* public: virtual void __thiscall BuildAIModule::displayBuildList(void) */

void __thiscall BuildAIModule::displayBuildList(BuildAIModule *this)
{
  BuildItem *this_00;
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  AIModule *extraout_ECX;
  AIModule *extraout_ECX_00;
  AIModule *this_01;
  char *pcVar5;
  
  AIModule::logCommonHistory
            ((AIModule *)this,(char *)this,s_Build_list___s__,this->buildListNameValue);
  for (this_00 = (this->buildList).next;
      (this_00 != &this->buildList && (this_00 != (BuildItem *)0x0)); this_00 = this_00->next) {
    iVar1 = BuildItem::built(this_00);
    if (iVar1 == 1) {
      BuildItem::skipCycles(this_00);
      BuildItem::permanentSkip(this_00);
      BuildItem::buildFrom(this_00);
      BuildItem::buildCap(this_00);
      BuildItem::numberBuilds(this_00);
      BaseItem::skip((BaseItem *)this_00);
      BuildItem::buildAttempts(this_00);
      BuildItem::inProgress(this_00);
      BaseItem::uniqueID((BaseItem *)this_00);
      iVar1 = BuildItem::buildCategory(this_00);
      iVar2 = BaseItem::gameID((BaseItem *)this_00);
      pcVar3 = BaseItem::name((BaseItem *)this_00);
      iVar4 = BaseItem::typeID((BaseItem *)this_00);
      pcVar5 = s_BLT_Type___4d___20s_gID___4d_Cat;
      this_01 = extraout_ECX;
    }
    else {
      BuildItem::skipCycles(this_00);
      BuildItem::permanentSkip(this_00);
      BuildItem::buildFrom(this_00);
      BuildItem::buildCap(this_00);
      BuildItem::numberBuilds(this_00);
      BaseItem::skip((BaseItem *)this_00);
      BuildItem::buildAttempts(this_00);
      BuildItem::inProgress(this_00);
      BaseItem::uniqueID((BaseItem *)this_00);
      iVar1 = BuildItem::buildCategory(this_00);
      iVar2 = BaseItem::gameID((BaseItem *)this_00);
      pcVar3 = BaseItem::name((BaseItem *)this_00);
      iVar4 = BaseItem::typeID((BaseItem *)this_00);
      pcVar5 = s_____Type___4d___20s_gID___4d_Cat;
      this_01 = extraout_ECX_00;
    }
    AIModule::logCommonHistory(this_01,(char *)this,pcVar5,iVar4,pcVar3,iVar2,iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: loadBuildList
// Address: 00409430
// [HELPER] s_NONE: "NONE"
// [HELPER] s_NULL: "NULL"
// [HELPER] s_There_is_no_build_list_to_load_: "There is no build list to load."
// [HELPER] s_Trying_to_load_build_list_in_fil: "Trying to load build list in file '%s'."
// [HELPER] s___File_open_successful__nuking_a: "  File open successful, nuking any old items."
// [HELPER] s___I_cannot_do_it_cap_n_: "  I cannot do it cap'n!"
// [HELPER] s___c__d___s___d___d__d_: "%*c%*d %*s %*d %*d %d "
// [HELPER] s___c_c: " %c%c"
// [HELPER] s__c_d__s__d__d_: "%c%d %s %d %d "
// [HELPER] s__s: "%s"
// [HELPER] s__tmp: ".tmp"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: commentTemp2 */
/* public: virtual int __thiscall BuildAIModule::loadBuildList(char *,class RGE_Player *) */

int __thiscall BuildAIModule::loadBuildList(BuildAIModule *this,char *param_1,RGE_Player *param_2)
{
  char cVar1;
  byte bVar2;
  RGE_Master_Static_Object *pRVar3;
  BuildItem *pBVar4;
  float fVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  AIModule *extraout_ECX;
  undefined3 uVar12;
  uint uVar10;
  AIModule *this_00;
  AIModule *this_01;
  uint uVar11;
  byte *pbVar13;
  BuildItem *this_02;
  char *pcVar14;
  undefined4 *unaff_FS_OFFSET;
  bool bVar15;
  char commentTemp2;
  char buildCategoryAsChar;
  char commentTemp1;
  float ySize;
  float local_170;
  float xSize;
  int buildCap;
  int typeID;
  int quantity;
  int buildFrom;
  _iobuf *fileIn;
  int local_154;
  char name [64];
  char temp [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c4ee;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pcVar6 = this->buildListNameValue;
  xSize = (float)pcVar6;
  strncpy(pcVar6,param_1,0x3f);
  fVar5 = xSize;
  pbVar13 = &s_NONE;
  this_00 = extraout_ECX;
  do {
    bVar2 = *pcVar6;
    uVar12 = (undefined3)((uint)this_00 >> 8);
    this_00 = (AIModule *)CONCAT31(uVar12,bVar2);
    bVar15 = bVar2 < *pbVar13;
    if (bVar2 != *pbVar13) {
LAB_00409499:
      iVar7 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
      goto LAB_0040949e;
    }
    if (bVar2 == 0) break;
    bVar2 = pcVar6[1];
    this_00 = (AIModule *)CONCAT31(uVar12,bVar2);
    bVar15 = bVar2 < pbVar13[1];
    if (bVar2 != pbVar13[1]) goto LAB_00409499;
    pcVar6 = pcVar6 + 2;
    pbVar13 = pbVar13 + 2;
  } while (bVar2 != 0);
  iVar7 = 0;
LAB_0040949e:
  if ((iVar7 == 0) || (xSize == 0.0)) {
LAB_004097cf:
    if (xSize == 0.0) {
      uVar10 = 0xffffffff;
      pcVar6 = &s_NULL;
      do {
        pcVar14 = pcVar6;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        pcVar14 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar14;
      } while (cVar1 != '\0');
      uVar10 = ~uVar10;
      pcVar6 = pcVar14 + -uVar10;
      pcVar14 = (char *)0x0;
      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar14 = pcVar14 + 4;
      }
      for (this_00 = (AIModule *)(uVar10 & 3); this_00 != (AIModule *)0x0;
          this_00 = (AIModule *)((int)&this_00[-1].processFrameValue + 3)) {
        *pcVar14 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar14 = pcVar14 + 1;
      }
    }
    AIModule::logCommonHistory(this_00,(char *)this,s_There_is_no_build_list_to_load_);
  }
  else {
    uVar10 = 0xffffffff;
    pcVar6 = (char *)xSize;
    do {
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    this_00 = (AIModule *)(~uVar10 - 1);
    if (this_00 == (AIModule *)0x0) goto LAB_004097cf;
    AIModule::logCommonHistory(this_00,(char *)this,s_Trying_to_load_build_list_in_fil,param_1);
    sprintf(temp + 4,s__s,fVar5);
    iVar7 = fopen(temp + 4,s_r);
    local_154 = iVar7;
    if (iVar7 == 0) {
      AIModule::logCommonHistory(this_01,(char *)this,s___I_cannot_do_it_cap_n_);
      iVar7 = 0;
      goto LAB_0040980c;
    }
    AIModule::logCommonHistory(this_01,(char *)this,s___File_open_successful__nuking_a);
    if (0 < this->buildListLengthValue) {
      removeOldList(this);
    }
    this->buildListLengthValue = 0;
    iVar8 = fgets(temp + 4,0x100,iVar7);
    while (iVar8 != 0) {
      buildCap = 0x3fc00000;
      local_170 = 1.5;
      typeID = -1;
      sscanf(temp + 4,s___c_c,(int)&ySize + 3,(int)&ySize + 1);
      if ((ySize._3_1_ != '/') || (ySize._1_1_ != '/')) {
        sscanf(temp + 4,s__c_d__s__d__d_,(int)&ySize + 2,&quantity,name + 4,&buildFrom,&fileIn);
        switch(ySize._2_1_) {
        default:
          goto switchD_004095ec_caseD_a;
        case 0x41:
          iVar7 = 0;
          sscanf(temp + 4,s___c__d___s___d___d__d_,&typeID);
          break;
        case 0x42:
          iVar7 = 0;
          break;
        case 0x43:
          iVar7 = 4;
          break;
        case 0x45:
          iVar7 = 5;
          break;
        case 0x47:
          iVar7 = 6;
          break;
        case 0x4c:
          iVar7 = 3;
          break;
        case 0x52:
          iVar7 = 1;
          break;
        case 0x54:
          iVar7 = 2;
          sscanf(temp + 4,s___c__d___s___d___d__d_,&typeID);
          break;
        case 0x55:
          iVar7 = 2;
        }
        if (iVar7 == 0) {
          iVar8 = (this->typesToIgnore).numberValue;
          iVar9 = 0;
          if (0 < iVar8) {
            do {
              if ((this->typesToIgnore).maximumSizeValue <= iVar9) break;
              if ((this->typesToIgnore).value[iVar9] == quantity) goto switchD_004095ec_caseD_a;
              iVar9 = iVar9 + 1;
            } while (iVar9 < iVar8);
          }
        }
        if ((((iVar7 == 0) || (iVar7 == 2)) && (-1 < quantity)) &&
           ((quantity < param_2->master_object_num &&
            (pRVar3 = param_2->master_objects[quantity], pRVar3 != (RGE_Master_Static_Object *)0x0))
           )) {
          local_170 = pRVar3->radius_y;
          buildCap = (int)pRVar3->radius_x;
        }
        buildCap = (int)((float)buildCap + (float)buildCap);
        local_170 = local_170 + local_170;
        iVar8 = 0;
        if (0 < buildFrom) {
          do {
            name._0_4_ = operator_new(0xb0);
            this_02 = (BuildItem *)0x0;
            local_4 = 0;
            if ((BuildItem *)name._0_4_ != (BuildItem *)0x0) {
              this_02 = (BuildItem *)
                        BuildItem::BuildItem
                                  ((BuildItem *)name._0_4_,iVar7,quantity,this->buildListLengthValue
                                   ,1,0,(int)fileIn,name + 4,(float)buildCap,local_170,0.0,-1,-1,-1,
                                   0);
            }
            local_4 = 0xffffffff;
            this->buildListLengthValue = this->buildListLengthValue + 1;
            this_02->next = &this->buildList;
            pBVar4 = (this->buildList).prev;
            this_02->prev = pBVar4;
            pBVar4->next = this_02;
            BuildItem::setBuildCap(this_02,typeID);
            iVar8 = iVar8 + 1;
            (this->buildList).prev = this_02;
          } while (iVar8 < buildFrom);
        }
      }
switchD_004095ec_caseD_a:
      iVar7 = local_154;
      iVar8 = fgets(temp + 4,0x100,local_154);
      fVar5 = xSize;
    }
    fclose(iVar7);
    iVar7 = strstr(fVar5,s__tmp);
    if (iVar7 != 0) {
      __unlink(fVar5);
    }
  }
  iVar7 = 1;
LAB_0040980c:
  *unaff_FS_OFFSET = local_c;
  return iVar7;
}

// --------------------------------------------------

// Function: buildListLength
// Address: 004098a0
/* public: int __thiscall BuildAIModule::buildListLength(void)const  */

int __thiscall BuildAIModule::buildListLength(BuildAIModule *this)
{
  return this->buildListLengthValue;
}

// --------------------------------------------------

// Function: buildListName
// Address: 004098b0
/* public: char * __thiscall BuildAIModule::buildListName(void) */

char * __thiscall BuildAIModule::buildListName(BuildAIModule *this)
{
  return this->buildListNameValue;
}

// --------------------------------------------------

// Function: haveBuildList
// Address: 004098c0
// [HELPER] s_NONE: "NONE"
// [HELPER] s_NULL: "NULL"
/* public: int __thiscall BuildAIModule::haveBuildList(void)const  */

int __thiscall BuildAIModule::haveBuildList(BuildAIModule *this)
{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  bool bVar6;
  
  pcVar4 = this->buildListNameValue;
  if (pcVar4 != (char *)0x0) {
    pbVar5 = &s_NONE;
    pcVar2 = pcVar4;
    do {
      bVar1 = *pcVar2;
      bVar6 = bVar1 < *pbVar5;
      if (bVar1 != *pbVar5) {
LAB_004098fc:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_00409901;
      }
      if (bVar1 == 0) break;
      bVar1 = pcVar2[1];
      bVar6 = bVar1 < pbVar5[1];
      if (bVar1 != pbVar5[1]) goto LAB_004098fc;
      pcVar2 = pcVar2 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_00409901:
    if (iVar3 != 0) {
      pbVar5 = &s_NULL;
      do {
        bVar1 = *pcVar4;
        bVar6 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_00409934:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_00409939;
        }
        if (bVar1 == 0) break;
        bVar1 = pcVar4[1];
        bVar6 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_00409934;
        pcVar4 = pcVar4 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_00409939:
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: insertItem
// Address: 00409950
// [HELPER] s_AddedBuildListItem: "AddedBuildListItem"
// [HELPER] s_SetGatherPercentage: "SetGatherPercentage"
/* public: int __thiscall BuildAIModule::insertItem(class RGE_Player *,int,int,int,int,int,int) */

int __thiscall
BuildAIModule::insertItem
          (BuildAIModule *this,RGE_Player *param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6,int param_7)
{
  RGE_Master_Static_Object ***pppRVar1;
  float fVar2;
  BuildItem *pBVar3;
  BuildItem *pBVar4;
  int iVar5;
  int iVar6;
  BuildItem *this_00;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar7;
  char name [64];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c50b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (this->buildListLengthValue < param_7) {
    iVar5 = 0;
    goto LAB_00409b55;
  }
  pBVar3 = (this->buildList).next;
  for (iVar5 = 0; (pBVar3 != &this->buildList && (iVar5 < param_7)); iVar5 = iVar5 + 1) {
    pBVar3 = pBVar3->next;
  }
  if (param_4 == 6) {
    pcVar7 = s_SetGatherPercentage;
LAB_00409a0d:
    strncpy(name + 4,pcVar7,0x3f);
    param_1 = (RGE_Player *)0x40400000;
    param_7 = 0x40400000;
  }
  else {
    if (param_1->master_objects[param_2] == (RGE_Master_Static_Object *)0x0) {
      pcVar7 = s_AddedBuildListItem;
      goto LAB_00409a0d;
    }
    strncpy(name + 4,param_1->master_objects[param_2]->name,0x3f);
    pppRVar1 = &param_1->master_objects;
    fVar2 = (*pppRVar1)[param_2]->radius_x;
    param_1 = (RGE_Player *)(fVar2 + fVar2);
    fVar2 = (*pppRVar1)[param_2]->radius_y;
    param_7 = (int)(fVar2 + fVar2);
  }
  iVar5 = this->buildListLengthValue;
  iVar6 = 0;
  if (0 < param_3) {
    do {
      name._0_4_ = operator_new(0xb0);
      this_00 = (BuildItem *)0x0;
      local_4 = 0;
      if ((BuildItem *)name._0_4_ != (BuildItem *)0x0) {
        this_00 = (BuildItem *)
                  BuildItem::BuildItem
                            ((BuildItem *)name._0_4_,param_4,param_2,iVar5,1,0,param_5,name + 4,
                             (float)param_1,(float)param_7,1.0,-1,-1,-1,0);
      }
      local_4 = 0xffffffff;
      if (this_00 == (BuildItem *)0x0) {
        iVar5 = 0;
        goto LAB_00409b55;
      }
      BuildItem::setBuilt(this_00,0);
      BuildItem::setInProgress(this_00,0);
      BuildItem::setBuildAttempts(this_00,0);
      BaseItem::setSkip((BaseItem *)this_00,0);
      BaseItem::setGameID((BaseItem *)this_00,-1);
      BaseItem::setX((BaseItem *)this_00,-1.0);
      BaseItem::setY((BaseItem *)this_00,-1.0);
      BaseItem::setZ((BaseItem *)this_00,-1.0);
      BuildItem::setNumberBuilds(this_00,0);
      BuildItem::setBuildCap(this_00,param_6);
      BuildItem::setSkipCycles(this_00,0);
      BuildItem::setPermanentSkip(this_00,'\0');
      this_00->prev = pBVar3;
      pBVar4 = pBVar3->next;
      this_00->next = pBVar4;
      iVar5 = iVar5 + 1;
      pBVar4->prev = this_00;
      pBVar3->next = this_00;
      iVar6 = iVar6 + 1;
      this->buildListLengthValue = this->buildListLengthValue + 1;
    } while (iVar6 < param_3);
  }
  iVar5 = 1;
LAB_00409b55:
  *unaff_FS_OFFSET = local_c;
  return iVar5;
}

// --------------------------------------------------

// Function: numberItemsBuilt
// Address: 00409b70
/* public: int __thiscall BuildAIModule::numberItemsBuilt(void)const  */

int __thiscall BuildAIModule::numberItemsBuilt(BuildAIModule *this)
{
  BuildItem *this_00;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (this_00 = (this->buildList).next;
      (this_00 != &this->buildList && (this_00 != (BuildItem *)0x0)); this_00 = this_00->next) {
    iVar1 = BuildItem::built(this_00);
    if (iVar1 == 1) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: numberItemsInProgress
// Address: 00409bb0
/* public: int __thiscall BuildAIModule::numberItemsInProgress(void)const  */

int __thiscall BuildAIModule::numberItemsInProgress(BuildAIModule *this)
{
  BuildItem *this_00;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (this_00 = (this->buildList).next;
      (this_00 != &this->buildList && (this_00 != (BuildItem *)0x0)); this_00 = this_00->next) {
    iVar1 = BuildItem::inProgress(this_00);
    if (iVar1 == 1) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: numberItemsBuiltOrInProgress
// Address: 00409bf0
/* public: int __thiscall BuildAIModule::numberItemsBuiltOrInProgress(void)const  */

int __thiscall BuildAIModule::numberItemsBuiltOrInProgress(BuildAIModule *this)
{
  BuildItem *this_00;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (this_00 = (this->buildList).next;
      (this_00 != &this->buildList && (this_00 != (BuildItem *)0x0)); this_00 = this_00->next) {
    iVar1 = BuildItem::inProgress(this_00);
    if ((iVar1 == 1) || (iVar1 = BuildItem::built(this_00), iVar1 == 1)) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: numberItemsIntoBuildList
// Address: 00409c30
/* public: int __thiscall BuildAIModule::numberItemsIntoBuildList(void)const  */

int __thiscall BuildAIModule::numberItemsIntoBuildList(BuildAIModule *this)
{
  return this->numberItemsIntoBuildListValue;
}

// --------------------------------------------------

// Function: lastBuildItemRequested
// Address: 00409c40
/* public: char * __thiscall BuildAIModule::lastBuildItemRequested(void)const  */

char * __thiscall BuildAIModule::lastBuildItemRequested(BuildAIModule *this)
{
  return this->lastBuildItemRequestedValue;
}

// --------------------------------------------------

// Function: currentBuildItemRequested
// Address: 00409c50
/* public: char * __thiscall BuildAIModule::currentBuildItemRequested(void)const  */

char * __thiscall BuildAIModule::currentBuildItemRequested(BuildAIModule *this)
{
  return this->currentBuildItemRequestedValue;
}

// --------------------------------------------------

// Function: nextBuildItemRequested
// Address: 00409c60
/* public: char * __thiscall BuildAIModule::nextBuildItemRequested(void)const  */

char * __thiscall BuildAIModule::nextBuildItemRequested(BuildAIModule *this)
{
  return this->nextBuildItemRequestedValue;
}

// --------------------------------------------------

// Function: numberItemsOfType
// Address: 00409c70
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall BuildAIModule::numberItemsOfType(int,int) */

int __thiscall BuildAIModule::numberItemsOfType(BuildAIModule *this,int param_1,int param_2)
{
  BuildItem *this_00;
  int iVar1;
  int count;
  int local_4;
  
  this_00 = (this->buildList).next;
  local_4 = 0;
  for (; (this_00 != &this->buildList && (this_00 != (BuildItem *)0x0)); this_00 = this_00->next) {
    iVar1 = BaseItem::typeID((BaseItem *)this_00);
    if ((iVar1 == param_1) && (iVar1 = BuildItem::buildCategory(this_00), iVar1 == param_2)) {
      local_4 = local_4 + 1;
    }
  }
  return local_4;
}

// --------------------------------------------------

// Function: numberBuiltItemsOfType
// Address: 00409cd0
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall BuildAIModule::numberBuiltItemsOfType(int,int) */

int __thiscall BuildAIModule::numberBuiltItemsOfType(BuildAIModule *this,int param_1,int param_2)
{
  BuildItem *this_00;
  int iVar1;
  int count;
  int local_4;
  
  this_00 = (this->buildList).next;
  local_4 = 0;
  for (; (this_00 != &this->buildList && (this_00 != (BuildItem *)0x0)); this_00 = this_00->next) {
    iVar1 = BaseItem::typeID((BaseItem *)this_00);
    if ((iVar1 == param_1) &&
       ((iVar1 = BuildItem::buildCategory(this_00), iVar1 == param_2 &&
        (iVar1 = BuildItem::built(this_00), iVar1 == 1)))) {
      local_4 = local_4 + 1;
    }
  }
  return local_4;
}

// --------------------------------------------------

// Function: numberUnbuiltItemsOfType
// Address: 00409d40
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall BuildAIModule::numberUnbuiltItemsOfType(int,int) */

int __thiscall BuildAIModule::numberUnbuiltItemsOfType(BuildAIModule *this,int param_1,int param_2)
{
  BuildItem *this_00;
  int iVar1;
  int count;
  int local_4;
  
  this_00 = (this->buildList).next;
  local_4 = 0;
  for (; (this_00 != &this->buildList && (this_00 != (BuildItem *)0x0)); this_00 = this_00->next) {
    iVar1 = BaseItem::typeID((BaseItem *)this_00);
    if ((iVar1 == param_1) &&
       ((iVar1 = BuildItem::buildCategory(this_00), iVar1 == param_2 &&
        (iVar1 = BuildItem::built(this_00), iVar1 == 0)))) {
      local_4 = local_4 + 1;
    }
  }
  return local_4;
}

// --------------------------------------------------

// Function: numberBuiltOrInProgressItemsOfType
// Address: 00409db0
/* WARNING: Variable defined which should be unmapped: count */
/* public: virtual int __thiscall BuildAIModule::numberBuiltOrInProgressItemsOfType(int,int) */

int __thiscall
BuildAIModule::numberBuiltOrInProgressItemsOfType(BuildAIModule *this,int param_1,int param_2)
{
  BuildItem *this_00;
  int iVar1;
  int count;
  int local_4;
  
  this_00 = (this->buildList).next;
  local_4 = 0;
  for (; (this_00 != &this->buildList && (this_00 != (BuildItem *)0x0)); this_00 = this_00->next) {
    iVar1 = BaseItem::typeID((BaseItem *)this_00);
    if (((iVar1 == param_1) && (iVar1 = BuildItem::buildCategory(this_00), iVar1 == param_2)) &&
       ((iVar1 = BuildItem::built(this_00), iVar1 == 1 ||
        (iVar1 = BuildItem::inProgress(this_00), iVar1 == 1)))) {
      local_4 = local_4 + 1;
    }
  }
  return local_4;
}

// --------------------------------------------------

// Function: numberInProgressItemsOfType
// Address: 00409e20
/* WARNING: Variable defined which should be unmapped: count */
/* public: int __thiscall BuildAIModule::numberInProgressItemsOfType(int,int) */

int __thiscall
BuildAIModule::numberInProgressItemsOfType(BuildAIModule *this,int param_1,int param_2)
{
  BuildItem *this_00;
  int iVar1;
  int count;
  int local_4;
  
  this_00 = (this->buildList).next;
  local_4 = 0;
  for (; (this_00 != &this->buildList && (this_00 != (BuildItem *)0x0)); this_00 = this_00->next) {
    iVar1 = BaseItem::typeID((BaseItem *)this_00);
    if ((iVar1 == param_1) &&
       ((iVar1 = BuildItem::buildCategory(this_00), iVar1 == param_2 &&
        (iVar1 = BuildItem::inProgress(this_00), iVar1 == 1)))) {
      local_4 = local_4 + 1;
    }
  }
  return local_4;
}

// --------------------------------------------------

// Function: removeOldList
// Address: 00409e90
/* protected: void __thiscall BuildAIModule::removeOldList(void) */

void __thiscall BuildAIModule::removeOldList(BuildAIModule *this)
{
  BuildItem *pBVar1;
  BuildItem *pBVar2;
  int *piVar3;
  
  pBVar2 = (this->buildList).next;
  pBVar1 = &this->buildList;
  while ((pBVar2 != pBVar1 && (pBVar2 != (BuildItem *)0x0))) {
    piVar3 = &pBVar2->_padding_;
    pBVar2 = pBVar2->next;
    (**(code **)*piVar3)(1);
  }
  (this->buildList).next = pBVar1;
  (this->buildList).prev = pBVar1;
  this->buildListLengthValue = 0;
  return;
}

// --------------------------------------------------

// Function: anyBuildListItem
// Address: 00409ee0
/* protected: class BuildItem * __thiscall BuildAIModule::anyBuildListItem(int,int,int) */

BuildItem * __thiscall
BuildAIModule::anyBuildListItem(BuildAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  BuildItem *this_00;
  
  this_00 = (this->buildList).next;
  if (this_00 != &this->buildList) {
    while (this_00 != (BuildItem *)0x0) {
      iVar1 = BaseItem::typeID((BaseItem *)this_00);
      if ((iVar1 == param_1) &&
         ((param_2 == 0 || ((param_2 == 1 && (iVar1 = BuildItem::built(this_00), iVar1 == param_3)))
          ))) {
        return this_00;
      }
      this_00 = this_00->next;
      if (this_00 == &this->buildList) {
        return (BuildItem *)0x0;
      }
    }
  }
  return (BuildItem *)0x0;
}

// --------------------------------------------------

// Function: specificBuildListItem
// Address: 00409f50
/* protected: class BuildItem * __thiscall BuildAIModule::specificBuildListItem(int) */

BuildItem * __thiscall BuildAIModule::specificBuildListItem(BuildAIModule *this,int param_1)
{
  int iVar1;
  BuildItem *this_00;
  
  this_00 = (this->buildList).next;
  if (this_00 != &this->buildList) {
    while (this_00 != (BuildItem *)0x0) {
      iVar1 = BaseItem::uniqueID((BaseItem *)this_00);
      if (iVar1 == param_1) {
        return this_00;
      }
      this_00 = this_00->next;
      if (this_00 == &this->buildList) {
        return (BuildItem *)0x0;
      }
    }
  }
  return (BuildItem *)0x0;
}

// --------------------------------------------------

