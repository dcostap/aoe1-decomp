// Class: ConstructionAIModule
// Function: ConstructionAIModule
// Address: 0040aa90
// [HELPER] s_: ""
// [HELPER] s_ConAI: "ConAI"
/* public: __thiscall ConstructionAIModule::ConstructionAIModule(void *,int) */

ConstructionAIModule * __thiscall
ConstructionAIModule::ConstructionAIModule(ConstructionAIModule *this,void *param_1,int param_2)
{
  ConstructionItem *this_00;
  ConstructionItem *this_01;
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
  pcStack_8 = FUN_0055c536;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
                    /* language.dll match for 0x3ea: "X" */
  AIModule::AIModule((AIModule *)this,s_ConAI,0x3ea,param_2,param_1);
  this_00 = &this->constructionLots;
  local_4 = 0;
  this->numberConstructionLotsValue = 0;
  ConstructionItem::ConstructionItem(this_00);
  this_01 = &this->randomConstructionLots;
  local_4 = CONCAT31(local_4._1_3_,1);
  this->numberRandomConstructionLotsValue = 0;
  ConstructionItem::ConstructionItem(this_01);
  uVar2 = 0xffffffff;
  this->xReferencePointValue = -1.0;
  this->yReferencePointValue = -1.0;
  this->zReferencePointValue = -1.0;
  (this->randomConstructionLots).next = this_01;
  (this->randomConstructionLots).prev = this_01;
  this->mapXSizeValue = -1;
  this->mapYSizeValue = -1;
  this->lastPlacementReturnCodeValue = PlacementOk;
  this->_padding_ = (int)&_vftable_;
  (this->constructionLots).next = this_00;
  (this->constructionLots).prev = this_00;
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
  pcVar5 = this->constructionPlanNameValue;
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
// Address: 0040ab90
/* public: virtual void * __thiscall ConstructionAIModule::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
ConstructionAIModule::_scalar_deleting_destructor_(ConstructionAIModule *this,uint param_1)
{
  ~ConstructionAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ConstructionAIModule
// Address: 0040abb0
// [HELPER] s_ConAI: "ConAI"
/* WARNING: Variable defined which should be unmapped: tempInt */
/* public: __thiscall ConstructionAIModule::ConstructionAIModule(int,int) */

ConstructionAIModule * __thiscall
ConstructionAIModule::ConstructionAIModule(ConstructionAIModule *this,int param_1,int param_2)
{
  int *piVar1;
  ConstructionItem *pCVar2;
  int iVar3;
  ConstructionItem *pCVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  int tempInt;
  float x;
  float y;
  float z_fffffeb4;
  int uniqueID_fffffeb8;
  float xSize;
  int buildAttemptsValue_fffffec0;
  float ySize_fffffec4;
  int inProgressValue_fffffec8;
  float zSize;
  int skipValue;
  int typeID_fffffed4;
  int builtValue;
  int gameID;
  int i;
  int local_11c;
  ConstructionItem *local_118;
  char name [257];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c589;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  name._0_4_ = this;
                    /* language.dll match for 0x3ea: "X" */
  AIModule::AIModule((AIModule *)this,s_ConAI,0x3ea,param_1,(void *)0x0);
  piVar1 = &this->numberConstructionLotsValue;
  pCVar4 = &this->constructionLots;
  local_4 = 0;
  *piVar1 = 0;
  ConstructionItem::ConstructionItem(pCVar4);
  pCVar2 = &this->randomConstructionLots;
  local_4._0_1_ = 1;
  this->numberRandomConstructionLotsValue = 0;
  ConstructionItem::ConstructionItem(pCVar2);
  (this->constructionLots).next = pCVar4;
  (this->constructionLots).prev = pCVar4;
  local_4 = CONCAT31(local_4._1_3_,2);
  this->xReferencePointValue = -1.0;
  this->yReferencePointValue = -1.0;
  this->zReferencePointValue = -1.0;
  this->mapXSizeValue = -1;
  this->mapYSizeValue = -1;
  this->lastPlacementReturnCodeValue = PlacementOk;
  this->_padding_ = (int)&_vftable_;
  (this->randomConstructionLots).next = pCVar2;
  (this->randomConstructionLots).prev = pCVar2;
  rge_read(param_2,piVar1,4);
  rge_read(param_2,&x,4);
  rge_read(param_2,this->constructionPlanNameValue,(int)x);
  this->constructionPlanNameValue[(int)x] = '\0';
  rge_read(param_2,&this->xReferencePointValue,4);
  rge_read(param_2,&this->yReferencePointValue,4);
  rge_read(param_2,&this->zReferencePointValue,4);
  rge_read(param_2,&this->mapXSizeValue,4);
  rge_read(param_2,&this->mapYSizeValue,4);
  local_11c = 0;
  if (0 < *piVar1) {
    do {
      rge_read(param_2,&x,4);
      rge_read(param_2,name + 4,(int)x);
      name[(int)x + 4] = '\0';
      rge_read(param_2,&typeID_fffffed4,4);
      rge_read(param_2,&inProgressValue_fffffec8,4);
      rge_read(param_2,&skipValue,4);
      rge_read(param_2,&y,4);
      rge_read(param_2,&zSize,4);
      rge_read(param_2,&gameID,4);
      rge_read(param_2,&ySize_fffffec4,4);
      rge_read(param_2,&i,4);
      rge_read(param_2,&xSize,4);
      rge_read(param_2,&builtValue,4);
      rge_read(param_2,&z_fffffeb4,4);
      rge_read(param_2,&uniqueID_fffffeb8,4);
      rge_read(param_2,&buildAttemptsValue_fffffec0,4);
                    /* language.dll match for 0x80: "Arial" */
      local_118 = (ConstructionItem *)operator_new(0x80);
      local_4._0_1_ = 3;
      if (local_118 == (ConstructionItem *)0x0) {
        pCVar4 = (ConstructionItem *)0x0;
      }
      else {
        pCVar4 = (ConstructionItem *)
                 ConstructionItem::ConstructionItem
                           (local_118,y,zSize,(float)gameID,ySize_fffffec4,(float)i,xSize,
                            typeID_fffffed4,name + 4);
      }
      local_4 = CONCAT31(local_4._1_3_,2);
      ConstructionItem::setInProgress(pCVar4,(int)z_fffffeb4);
      ConstructionItem::setBuilt(pCVar4,uniqueID_fffffeb8);
      ConstructionItem::setBuildAttempts(pCVar4,buildAttemptsValue_fffffec0);
      BaseItem::setGameID((BaseItem *)pCVar4,inProgressValue_fffffec8);
      BaseItem::setUniqueID((BaseItem *)pCVar4,skipValue);
      BaseItem::setSkip((BaseItem *)pCVar4,builtValue);
      pCVar4->next = &this->constructionLots;
      pCVar2 = (this->constructionLots).prev;
      pCVar4->prev = pCVar2;
      pCVar2->next = pCVar4;
      iVar5 = *piVar1;
      local_11c = local_11c + 1;
      (this->constructionLots).prev = pCVar4;
    } while (local_11c < iVar5);
  }
  rge_read(param_2,&this->numberRandomConstructionLotsValue,4);
  iVar5 = 0;
  if (0 < this->numberRandomConstructionLotsValue) {
    do {
      rge_read(param_2,&x,4);
      rge_read(param_2,name + 4,(int)x);
      name[(int)x + 4] = '\0';
      rge_read(param_2,&builtValue,4);
      rge_read(param_2,&i,4);
      rge_read(param_2,&xSize,4);
      rge_read(param_2,&y,4);
      rge_read(param_2,&z_fffffeb4,4);
      rge_read(param_2,&uniqueID_fffffeb8,4);
      rge_read(param_2,&buildAttemptsValue_fffffec0,4);
      rge_read(param_2,&inProgressValue_fffffec8,4);
      rge_read(param_2,&skipValue,4);
      rge_read(param_2,&typeID_fffffed4,4);
      rge_read(param_2,&zSize,4);
      rge_read(param_2,&gameID,4);
      rge_read(param_2,&ySize_fffffec4,4);
                    /* language.dll match for 0x80: "Arial" */
      local_118 = (ConstructionItem *)operator_new(0x80);
      local_4._0_1_ = 4;
      if (local_118 == (ConstructionItem *)0x0) {
        pCVar4 = (ConstructionItem *)0x0;
      }
      else {
        pCVar4 = (ConstructionItem *)
                 ConstructionItem::ConstructionItem
                           (local_118,y,z_fffffeb4,(float)uniqueID_fffffeb8,
                            (float)buildAttemptsValue_fffffec0,(float)inProgressValue_fffffec8,
                            (float)skipValue,builtValue,name + 4);
      }
      local_4 = CONCAT31(local_4._1_3_,2);
      ConstructionItem::setInProgress(pCVar4,(int)zSize);
      ConstructionItem::setBuilt(pCVar4,gameID);
      ConstructionItem::setBuildAttempts(pCVar4,(int)ySize_fffffec4);
      BaseItem::setGameID((BaseItem *)pCVar4,i);
      BaseItem::setUniqueID((BaseItem *)pCVar4,(int)xSize);
      BaseItem::setSkip((BaseItem *)pCVar4,typeID_fffffed4);
      iVar5 = iVar5 + 1;
      pCVar4->next = &this->randomConstructionLots;
      pCVar2 = (this->randomConstructionLots).prev;
      pCVar4->prev = pCVar2;
      pCVar2->next = pCVar4;
      iVar3 = this->numberRandomConstructionLotsValue;
      (this->randomConstructionLots).prev = pCVar4;
    } while (iVar5 < iVar3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~ConstructionAIModule
// Address: 0040b120
/* public: virtual __thiscall ConstructionAIModule::~ConstructionAIModule(void) */

void __thiscall ConstructionAIModule::~ConstructionAIModule(ConstructionAIModule *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_0055c5c4;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 2;
  if (0 < this->numberConstructionLotsValue) {
    removeOldLots(this);
  }
  local_4._0_1_ = 1;
  ConstructionItem::~ConstructionItem(&this->randomConstructionLots);
  local_4 = (uint)local_4._1_3_ << 8;
  ConstructionItem::~ConstructionItem(&this->constructionLots);
  local_4 = 0xffffffff;
  AIModule::~AIModule((AIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0040b1a0
/* WARNING: Variable defined which should be unmapped: tempInt */
/* public: virtual int __thiscall ConstructionAIModule::save(int) */

int __thiscall ConstructionAIModule::save(ConstructionAIModule *this,int param_1)
{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  ConstructionItem *pCVar6;
  char *pcVar7;
  char *pcVar8;
  int tempInt;
  float tempFloat;
  int tempBOOL;
  int local_110;
  ConstructionItem *local_10c;
  char tempString [257];
  
  tempString._0_4_ = this;
  rge_write(param_1,&this->numberConstructionLotsValue,4);
  uVar4 = 0xffffffff;
  pcVar8 = this->constructionPlanNameValue;
  do {
    pcVar3 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar3 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar3;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = tempString;
  pcVar3 = pcVar3 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar8 = pcVar8 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar8 = tempString + 4;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  tempFloat = (float)(~uVar4 - 1);
  rge_write(param_1,&tempFloat,4);
  uVar4 = 0xffffffff;
  pcVar8 = tempString + 4;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  rge_write(param_1,tempString + 4,~uVar4 - 1);
  rge_write(param_1,&this->xReferencePointValue,4);
  rge_write(param_1,&this->yReferencePointValue,4);
  rge_write(param_1,&this->zReferencePointValue,4);
  rge_write(param_1,&this->mapXSizeValue,4);
  rge_write(param_1,&this->mapYSizeValue,4);
  pCVar6 = (this->constructionLots).next;
  local_10c = (ConstructionItem *)(tempString._0_4_ + 0xf4);
  if (pCVar6 != local_10c) {
    do {
      if (pCVar6 == (ConstructionItem *)0x0) break;
      pcVar3 = BaseItem::name((BaseItem *)pCVar6);
      uVar4 = 0xffffffff;
      pcVar8 = tempString;
      do {
        pcVar7 = pcVar3;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar7 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar7;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar3 = pcVar7 + -uVar4;
      for (uVar5 = uVar4 >> 2; pcVar8 = pcVar8 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar8 = pcVar8 + 1;
      }
      uVar4 = 0xffffffff;
      pcVar8 = tempString + 4;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      tempFloat = (float)(~uVar4 - 1);
      rge_write(param_1,&tempFloat,4);
      rge_write(param_1,tempString + 4,(int)tempFloat);
      tempFloat = (float)BaseItem::typeID((BaseItem *)pCVar6);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BaseItem::gameID((BaseItem *)pCVar6);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BaseItem::uniqueID((BaseItem *)pCVar6);
      rge_write(param_1,&tempFloat,4);
      tempBOOL = (int)BaseItem::x((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::y((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::z((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::xSize((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::ySize((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::zSize((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      local_110 = BaseItem::skip((BaseItem *)pCVar6);
      rge_write(param_1,&local_110,4);
      local_110 = ConstructionItem::inProgress(pCVar6);
      rge_write(param_1,&local_110,4);
      local_110 = ConstructionItem::built(pCVar6);
      rge_write(param_1,&local_110,4);
      tempFloat = (float)ConstructionItem::buildAttempts(pCVar6);
      rge_write(param_1,&tempFloat,4);
      pCVar6 = pCVar6->next;
    } while (pCVar6 != local_10c);
  }
  uVar2 = tempString._0_4_;
  rge_write(param_1,(void *)(tempString._0_4_ + 0x174),4);
  pCVar6 = *(ConstructionItem **)(uVar2 + 0x1e4);
  local_10c = (ConstructionItem *)(uVar2 + 0x178);
  if (pCVar6 != local_10c) {
    do {
      if (pCVar6 == (ConstructionItem *)0x0) {
        return 1;
      }
      pcVar3 = BaseItem::name((BaseItem *)pCVar6);
      uVar4 = 0xffffffff;
      pcVar8 = tempString;
      do {
        pcVar7 = pcVar3;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar7 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar7;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar3 = pcVar7 + -uVar4;
      for (uVar5 = uVar4 >> 2; pcVar8 = pcVar8 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar8 = pcVar8 + 1;
      }
      uVar4 = 0xffffffff;
      pcVar8 = tempString + 4;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      tempFloat = (float)(~uVar4 - 1);
      rge_write(param_1,&tempFloat,4);
      rge_write(param_1,tempString + 4,(int)tempFloat);
      tempFloat = (float)BaseItem::typeID((BaseItem *)pCVar6);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BaseItem::gameID((BaseItem *)pCVar6);
      rge_write(param_1,&tempFloat,4);
      tempFloat = (float)BaseItem::uniqueID((BaseItem *)pCVar6);
      rge_write(param_1,&tempFloat,4);
      tempBOOL = (int)BaseItem::x((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::y((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::z((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::xSize((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::ySize((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      tempBOOL = (int)BaseItem::zSize((BaseItem *)pCVar6);
      rge_write(param_1,&tempBOOL,4);
      local_110 = BaseItem::skip((BaseItem *)pCVar6);
      rge_write(param_1,&local_110,4);
      local_110 = ConstructionItem::inProgress(pCVar6);
      rge_write(param_1,&local_110,4);
      local_110 = ConstructionItem::built(pCVar6);
      rge_write(param_1,&local_110,4);
      tempFloat = (float)ConstructionItem::buildAttempts(pCVar6);
      rge_write(param_1,&tempFloat,4);
      pCVar6 = pCVar6->next;
    } while (pCVar6 != local_10c);
  }
  return 1;
}

// --------------------------------------------------

// Function: loadConstructionPlan
// Address: 0040b690
// [HELPER] s_Loading_construction_plan_in_fil: "Loading construction plan in file '%s'."
// [HELPER] s_NONE: "NONE"
// [HELPER] s_NULL: "NULL"
// [HELPER] s_There_is_no_construction_plan_to: "There is no construction plan to load."
// [HELPER] s___c_c: " %c%c"
// [HELPER] s__f__f__f__f__f__f__d__s_: "%f %f %f %f %f %f %d %s "
// [HELPER] s__s: "%s"
// [HELPER] s__tmp: ".tmp"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: commentTemp1 */
/* public: virtual int __thiscall ConstructionAIModule::loadConstructionPlan(char
   *,int,int,float,float,float) */

int __thiscall
ConstructionAIModule::loadConstructionPlan
          (ConstructionAIModule *this,char *param_1,int param_2,int param_3,float param_4,
          float param_5,float param_6)
{
  char cVar1;
  byte bVar2;
  ConstructionItem *pCVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  ConstructionItem *pCVar7;
  AIModule *extraout_ECX;
  undefined3 uVar10;
  uint uVar8;
  uint uVar9;
  AIModule *this_00;
  byte *pbVar11;
  char *pcVar12;
  undefined4 *unaff_FS_OFFSET;
  bool bVar13;
  char commentTemp1;
  char commentTemp2;
  float y;
  float x;
  float z;
  float zSize;
  float local_164;
  int id;
  float xSize;
  float ySize;
  float local_154;
  char name [64];
  char temp [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c5de;
  *unaff_FS_OFFSET = &local_c;
  setReferencePoint(this,param_2,param_3,param_4,param_5,param_6);
  if (0 < this->numberConstructionLotsValue) {
    removeOldLots(this);
  }
  pcVar12 = this->constructionPlanNameValue;
  id = (int)pcVar12;
  strncpy(pcVar12,param_1,0x3f);
  pbVar11 = &s_NONE;
  pcVar4 = pcVar12;
  this_00 = extraout_ECX;
  do {
    bVar2 = *pcVar4;
    uVar10 = (undefined3)((uint)this_00 >> 8);
    this_00 = (AIModule *)CONCAT31(uVar10,bVar2);
    bVar13 = bVar2 < *pbVar11;
    if (bVar2 != *pbVar11) {
LAB_0040b736:
      iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
      goto LAB_0040b73b;
    }
    if (bVar2 == 0) break;
    bVar2 = pcVar4[1];
    this_00 = (AIModule *)CONCAT31(uVar10,bVar2);
    bVar13 = bVar2 < pbVar11[1];
    if (bVar2 != pbVar11[1]) goto LAB_0040b736;
    pcVar4 = pcVar4 + 2;
    pbVar11 = pbVar11 + 2;
  } while (bVar2 != 0);
  iVar5 = 0;
LAB_0040b73b:
  if (iVar5 == 0) {
    if (pcVar12 == (char *)0x0) goto LAB_0040b91b;
LAB_0040b93d:
    AIModule::logCommonHistory(this_00,(char *)this,s_There_is_no_construction_plan_to);
  }
  else {
    if (pcVar12 == (char *)0x0) {
LAB_0040b91b:
      uVar8 = 0xffffffff;
      pcVar12 = &s_NULL;
      do {
        pcVar4 = pcVar12;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar4 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar4;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      pcVar12 = pcVar4 + -uVar8;
      pcVar4 = (char *)0x0;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar4 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar4 = pcVar4 + 4;
      }
      for (this_00 = (AIModule *)(uVar8 & 3); this_00 != (AIModule *)0x0;
          this_00 = (AIModule *)((int)&this_00[-1].processFrameValue + 3)) {
        *pcVar4 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar4 = pcVar4 + 1;
      }
      goto LAB_0040b93d;
    }
    AIModule::logCommonHistory(this_00,(char *)this,s_Loading_construction_plan_in_fil,param_1);
    sprintf(temp + 4,s__s,pcVar12);
    iVar5 = fopen(temp + 4,s_r);
    if (iVar5 == 0) goto LAB_0040b950;
    iVar6 = fgets(temp + 4,0x100,iVar5);
    while (iVar6 != 0) {
      sscanf(temp + 4,s___c_c,(int)&y + 2,(int)&y + 3);
      if ((y._2_1_ != '/') || (y._3_1_ != '/')) {
        sscanf(temp + 4,s__f__f__f__f__f__f__d__s_,&z,&x,&zSize,&ySize,&local_154,&local_164,&xSize,
               name + 4);
        z = this->xReferencePointValue + z;
        x = this->yReferencePointValue + x;
        zSize = this->zReferencePointValue + zSize;
        pCVar7 = lot(this,z,x);
        if (pCVar7 == (ConstructionItem *)0x0) {
                    /* language.dll match for 0x80: "Arial" */
          name._0_4_ = operator_new(0x80);
          local_4 = 0;
          if ((ConstructionItem *)name._0_4_ == (ConstructionItem *)0x0) {
            pCVar7 = (ConstructionItem *)0x0;
          }
          else {
            pCVar7 = (ConstructionItem *)
                     ConstructionItem::ConstructionItem
                               ((ConstructionItem *)name._0_4_,z,x,zSize,ySize,local_154,local_164,
                                (int)xSize,name + 4);
          }
          local_4 = 0xffffffff;
          pCVar7->next = &this->constructionLots;
          pCVar3 = (this->constructionLots).prev;
          pCVar7->prev = pCVar3;
          pCVar3->next = pCVar7;
          (this->constructionLots).prev = pCVar7;
          this->numberConstructionLotsValue = this->numberConstructionLotsValue + 1;
        }
      }
      iVar6 = fgets(temp + 4,0x100,iVar5);
      pcVar12 = (char *)id;
    }
    fclose(iVar5);
    iVar5 = strstr(pcVar12,s__tmp);
    if (iVar5 != 0) {
      __unlink(pcVar12);
    }
  }
  iVar5 = 1;
LAB_0040b950:
  *unaff_FS_OFFSET = local_c;
  return iVar5;
}

// --------------------------------------------------

// Function: constructionPlanName
// Address: 0040b970
/* public: char * __thiscall ConstructionAIModule::constructionPlanName(void) */

char * __thiscall ConstructionAIModule::constructionPlanName(ConstructionAIModule *this)
{
  return this->constructionPlanNameValue;
}

// --------------------------------------------------

// Function: setReferencePoint
// Address: 0040b980
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall ConstructionAIModule::setReferencePoint(int,int,float,float,float) */

void __thiscall
ConstructionAIModule::setReferencePoint
          (ConstructionAIModule *this,int param_1,int param_2,float param_3,float param_4,
          float param_5)
{
  ConstructionItem *this_00;
  ConstructionItem *pCVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)UNK_0056e7fc._4_8_;
  this->mapXSizeValue = param_1;
  this->yReferencePointValue = param_4;
  this->mapYSizeValue = param_2;
  this->xReferencePointValue = param_3;
  this->zReferencePointValue = param_5;
  if ((((param_3 <= fVar2) || (param_4 <= (float)UNK_0056e7fc._4_8_)) || ((float)param_1 <= param_3)
      ) || ((float)param_2 <= param_4)) {
    removeOldLots(this);
  }
  else {
    this_00 = (this->constructionLots).next;
    if (this_00 != &this->constructionLots) {
      while (this_00 != (ConstructionItem *)0x0) {
        fVar2 = BaseItem::x((BaseItem *)this_00);
        BaseItem::setX((BaseItem *)this_00,fVar2 + param_3);
        fVar2 = BaseItem::y((BaseItem *)this_00);
        BaseItem::setY((BaseItem *)this_00,fVar2 + param_4);
        fVar2 = BaseItem::z((BaseItem *)this_00);
        BaseItem::setZ((BaseItem *)this_00,fVar2 + param_5);
        fVar2 = BaseItem::x((BaseItem *)this_00);
        fVar3 = BaseItem::xSize((BaseItem *)this_00);
        if (fVar2 - fVar3 * ram0x0056e808 < _DAT_0056e80c) {
LAB_0040bb29:
          this->numberConstructionLotsValue = this->numberConstructionLotsValue + -1;
          pCVar1 = this_00->next;
          this_00->prev->next = pCVar1;
          this_00->next->prev = this_00->prev;
          (**(code **)this_00->_padding_)(1);
        }
        else {
          fVar2 = BaseItem::y((BaseItem *)this_00);
          fVar3 = BaseItem::ySize((BaseItem *)this_00);
          if (fVar2 - fVar3 * ram0x0056e808 < _DAT_0056e80c) goto LAB_0040bb29;
          fVar2 = BaseItem::x((BaseItem *)this_00);
          fVar3 = BaseItem::xSize((BaseItem *)this_00);
          if ((float)(this->mapXSizeValue + -1) < fVar2 - fVar3 * _DAT_0056e810) goto LAB_0040bb29;
          fVar2 = BaseItem::y((BaseItem *)this_00);
          fVar3 = BaseItem::ySize((BaseItem *)this_00);
          if ((float)(this->mapYSizeValue + -1) < fVar2 - fVar3 * _DAT_0056e810) goto LAB_0040bb29;
          pCVar1 = this_00->next;
        }
        this_00 = pCVar1;
        if (pCVar1 == &this->constructionLots) {
          return;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: xReferencePoint
// Address: 0040bb70
/* public: float __thiscall ConstructionAIModule::xReferencePoint(void) */

float __thiscall ConstructionAIModule::xReferencePoint(ConstructionAIModule *this)
{
  return this->xReferencePointValue;
}

// --------------------------------------------------

// Function: yReferencePoint
// Address: 0040bb80
/* public: float __thiscall ConstructionAIModule::yReferencePoint(void) */

float __thiscall ConstructionAIModule::yReferencePoint(ConstructionAIModule *this)
{
  return this->yReferencePointValue;
}

// --------------------------------------------------

// Function: placeStructure
// Address: 0040bb90
/* public: virtual class ConstructionItem * __thiscall ConstructionAIModule::placeStructure(class
   BuildItem *) */

ConstructionItem * __thiscall
ConstructionAIModule::placeStructure(ConstructionAIModule *this,BuildItem *param_1)
{
  return (ConstructionItem *)0x0;
}

// --------------------------------------------------

// Function: lastPlacementReturnCode
// Address: 0040bba0
/* public: enum ConstructionAIModule::PlacementResult __thiscall
   ConstructionAIModule::lastPlacementReturnCode(void) */

PlacementResult __thiscall ConstructionAIModule::lastPlacementReturnCode(ConstructionAIModule *this)
{
  return this->lastPlacementReturnCodeValue;
}

// --------------------------------------------------

// Function: setBuilt
// Address: 0040bbb0
/* public: virtual void __thiscall ConstructionAIModule::setBuilt(class ConstructionItem *,int) */

void __thiscall
ConstructionAIModule::setBuilt(ConstructionAIModule *this,ConstructionItem *param_1,int param_2)
{
  int iVar1;
  ConstructionItem *this_00;
  
  this_00 = (this->constructionLots).next;
  if (this_00 != &this->constructionLots) {
    while (this_00 != (ConstructionItem *)0x0) {
      iVar1 = operator==(this_00,param_1);
      if (iVar1 != 0) {
        ConstructionItem::setBuilt(this_00,param_2);
        return;
      }
      this_00 = this_00->next;
      if (this_00 == &this->constructionLots) {
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: unplaceStructure
// Address: 0040bc00
/* public: virtual int __thiscall ConstructionAIModule::unplaceStructure(class ConstructionItem
   *,int) */

int __thiscall
ConstructionAIModule::unplaceStructure
          (ConstructionAIModule *this,ConstructionItem *param_1,int param_2)
{
  int iVar1;
  ConstructionItem *this_00;
  
  this_00 = (this->constructionLots).next;
  if (this_00 != &this->constructionLots) {
    while (this_00 != (ConstructionItem *)0x0) {
      iVar1 = operator==(this_00,param_1);
      if (iVar1 != 0) {
        ConstructionItem::setInProgress(this_00,0);
        ConstructionItem::setBuilt(this_00,0);
        iVar1 = BaseItem::uniqueID((BaseItem *)this_00);
        BaseItem::setUniqueID((BaseItem *)this_00,-1);
        if (param_2 == 1) {
          ConstructionItem::decrementBuildAttempts(this_00);
        }
        return iVar1;
      }
      this_00 = this_00->next;
      if (this_00 == &this->constructionLots) {
        return -1;
      }
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: unplaceStructure
// Address: 0040bc80
/* public: virtual int __thiscall ConstructionAIModule::unplaceStructure(float,float,int) */

int __thiscall
ConstructionAIModule::unplaceStructure
          (ConstructionAIModule *this,float param_1,float param_2,int param_3)
{
  int iVar1;
  ConstructionItem *this_00;
  float fVar2;
  
  this_00 = (this->constructionLots).next;
  if (this_00 != &this->constructionLots) {
    while (this_00 != (ConstructionItem *)0x0) {
      fVar2 = BaseItem::x((BaseItem *)this_00);
      if (fVar2 == param_1) {
        fVar2 = BaseItem::y((BaseItem *)this_00);
        if (fVar2 == param_2) {
          ConstructionItem::setInProgress(this_00,0);
          ConstructionItem::setBuilt(this_00,0);
          iVar1 = BaseItem::uniqueID((BaseItem *)this_00);
          BaseItem::setUniqueID((BaseItem *)this_00,-1);
          if (param_3 == 1) {
            ConstructionItem::decrementBuildAttempts(this_00);
          }
          return iVar1;
        }
      }
      this_00 = this_00->next;
      if (this_00 == &this->constructionLots) {
        return -1;
      }
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: decrementBuildAttempts
// Address: 0040bd10
/* public: virtual void __thiscall ConstructionAIModule::decrementBuildAttempts(float,float,int) */

void __thiscall
ConstructionAIModule::decrementBuildAttempts
          (ConstructionAIModule *this,float param_1,float param_2,int param_3)
{
  ConstructionItem *this_00;
  
  this_00 = lot(this,param_1,param_2);
  if ((this_00 != (ConstructionItem *)0x0) && (0 < param_3)) {
    do {
      ConstructionItem::decrementBuildAttempts(this_00);
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: incrementBuildAttempts
// Address: 0040bd40
/* public: virtual void __thiscall ConstructionAIModule::incrementBuildAttempts(float,float,int) */

void __thiscall
ConstructionAIModule::incrementBuildAttempts
          (ConstructionAIModule *this,float param_1,float param_2,int param_3)
{
  ConstructionItem *this_00;
  
  this_00 = lot(this,param_1,param_2);
  if ((this_00 != (ConstructionItem *)0x0) && (0 < param_3)) {
    do {
      ConstructionItem::incrementBuildAttempts(this_00);
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: lot
// Address: 0040bd70
/* public: class ConstructionItem * __thiscall ConstructionAIModule::lot(float,float) */

ConstructionItem * __thiscall
ConstructionAIModule::lot(ConstructionAIModule *this,float param_1,float param_2)
{
  ConstructionItem *pCVar1;
  float fVar2;
  
  pCVar1 = (this->constructionLots).next;
  while( true ) {
    if ((pCVar1 == &this->constructionLots) || (pCVar1 == (ConstructionItem *)0x0)) {
      pCVar1 = (this->randomConstructionLots).next;
      if (pCVar1 != &this->randomConstructionLots) {
        while (pCVar1 != (ConstructionItem *)0x0) {
          fVar2 = BaseItem::x((BaseItem *)pCVar1);
          if ((fVar2 == param_1) && (fVar2 = BaseItem::y((BaseItem *)pCVar1), fVar2 == param_2)) {
            return pCVar1;
          }
          pCVar1 = pCVar1->next;
          if (pCVar1 == &this->randomConstructionLots) {
            return (ConstructionItem *)0x0;
          }
        }
      }
      return (ConstructionItem *)0x0;
    }
    fVar2 = BaseItem::x((BaseItem *)pCVar1);
    if ((fVar2 == param_1) && (fVar2 = BaseItem::y((BaseItem *)pCVar1), fVar2 == param_2)) break;
    pCVar1 = pCVar1->next;
  }
  return pCVar1;
}

// --------------------------------------------------

// Function: randomLot
// Address: 0040be10
/* public: class ConstructionItem * __thiscall ConstructionAIModule::randomLot(float,float) */

ConstructionItem * __thiscall
ConstructionAIModule::randomLot(ConstructionAIModule *this,float param_1,float param_2)
{
  ConstructionItem *this_00;
  float fVar1;
  
  this_00 = (this->randomConstructionLots).next;
  if (this_00 != &this->randomConstructionLots) {
    while (this_00 != (ConstructionItem *)0x0) {
      fVar1 = BaseItem::x((BaseItem *)this_00);
      if (fVar1 == param_1) {
        fVar1 = BaseItem::y((BaseItem *)this_00);
        if (fVar1 == param_2) {
          return this_00;
        }
      }
      this_00 = this_00->next;
      if (this_00 == &this->randomConstructionLots) {
        return (ConstructionItem *)0x0;
      }
    }
  }
  return (ConstructionItem *)0x0;
}

// --------------------------------------------------

// Function: removeOldLots
// Address: 0040be70
/* protected: void __thiscall ConstructionAIModule::removeOldLots(void) */

void __thiscall ConstructionAIModule::removeOldLots(ConstructionAIModule *this)
{
  ConstructionItem *pCVar1;
  ConstructionItem *pCVar2;
  int *piVar3;
  
  pCVar2 = (this->constructionLots).next;
  pCVar1 = &this->constructionLots;
  while ((pCVar2 != pCVar1 && (pCVar2 != (ConstructionItem *)0x0))) {
    piVar3 = &pCVar2->_padding_;
    pCVar2 = pCVar2->next;
    (**(code **)*piVar3)(1);
  }
  (this->constructionLots).next = pCVar1;
  (this->constructionLots).prev = pCVar1;
  this->numberConstructionLotsValue = 0;
  return;
}

// --------------------------------------------------

