// Class: TribeResourceAIModule
// Size:  0xF8
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
// [16] `scalar_deleting_destructor'
//
// Member Layout:
// [0x0F0] TribeMainDecisionAIModule * md
// [0x0F4] int numberResourcesValue
// ----------------------------------------------------------------

// Function: TribeResourceAIModule
// Address: 004e6b40
// [HELPER] s_Resource_AI: "Resource AI"
TribeResourceAIModule * __thiscall
TribeResourceAIModule::TribeResourceAIModule
          (TribeResourceAIModule *this,void *param_1,int param_2,int param_3,int param_4,int param_5
          ,int param_6)
{
  AIModule::AIModule((AIModule *)this,s_Resource_AI,0x3ef,param_2,param_1);
  this->md = (TribeMainDecisionAIModule *)0x0;
  this->numberResourcesValue = param_3;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004e6b80
void * __thiscall
TribeResourceAIModule::_scalar_deleting_destructor_(TribeResourceAIModule *this,uint param_1)
{
  ~TribeResourceAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TribeResourceAIModule
// Address: 004e6ba0
// [HELPER] s_ResAI: "ResAI"
TribeResourceAIModule * __thiscall
TribeResourceAIModule::TribeResourceAIModule(TribeResourceAIModule *this,int param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560768;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  AIModule::AIModule((AIModule *)this,s_ResAI,0x3ef,param_1,(void *)0x0);
  local_4 = 0;
  this->md = (TribeMainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  rge_read(param_2,&this->numberResourcesValue,4);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TribeResourceAIModule
// Address: 004e6c20
void __thiscall TribeResourceAIModule::~TribeResourceAIModule(TribeResourceAIModule *this)
{
  this->_padding_ = (int)&_vftable_;
  AIModule::~AIModule((AIModule *)this);
  return;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 004e6c30
void __thiscall
TribeResourceAIModule::setMainDecisionAI
          (TribeResourceAIModule *this,TribeMainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004e6c40
int __thiscall TribeResourceAIModule::save(TribeResourceAIModule *this,int param_1)
{
  rge_write(param_1,&this->numberResourcesValue,4);
  return 1;
}

// --------------------------------------------------

// Function: numberResources
// Address: 004e6c60
int __thiscall TribeResourceAIModule::numberResources(TribeResourceAIModule *this)
{
  return this->numberResourcesValue;
}

// --------------------------------------------------

// Function: resource
// Address: 004e6c70
int __thiscall TribeResourceAIModule::resource(TribeResourceAIModule *this,int param_1)
{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
    iVar1 = __ftol();
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

// Function: resourcesAvailable
// Address: 004e6ca0
int __thiscall
TribeResourceAIModule::resourcesAvailable(TribeResourceAIModule *this,ResourceItem *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (ResourceItem *)0x0) {
    return 0;
  }
  iVar1 = ResourceItem::number(param_1);
  if (this->numberResourcesValue != iVar1) {
    return 0;
  }
  iVar3 = 0;
  iVar1 = ResourceItem::number(param_1);
  if (iVar1 < 1) {
    return 1;
  }
  do {
    iVar1 = *(int *)(this->md->_padding_ + 0x50);
    iVar2 = ResourceItem::value(param_1,iVar3);
    if (*(float *)(iVar1 + iVar3 * 4) < (float)iVar2) {
      return 0;
    }
    iVar3 = iVar3 + 1;
    iVar1 = ResourceItem::number(param_1);
  } while (iVar3 < iVar1);
  return 1;
}

// --------------------------------------------------

// Function: unavailableResource
// Address: 004e6d40
int __thiscall
TribeResourceAIModule::unavailableResource(TribeResourceAIModule *this,ResourceItem *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (ResourceItem *)0x0) {
    return 0;
  }
  iVar1 = ResourceItem::number(param_1);
  if (this->numberResourcesValue == iVar1) {
    iVar3 = 0;
    iVar1 = ResourceItem::number(param_1);
    if (0 < iVar1) {
      do {
        iVar1 = *(int *)(this->md->_padding_ + 0x50);
        iVar2 = ResourceItem::value(param_1,iVar3);
        if (*(float *)(iVar1 + iVar3 * 4) < (float)iVar2) {
          return iVar3;
        }
        iVar3 = iVar3 + 1;
        iVar1 = ResourceItem::number(param_1);
      } while (iVar3 < iVar1);
      return -1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: resourceName
// Address: 004e6dd0
// [HELPER] s_Food: "Food"
// [HELPER] s_Gold: "Gold"
// [HELPER] s_Stone: "Stone"
// [HELPER] s_Unknown: "Unknown"
// [HELPER] s_Wood: "Wood"
char * __thiscall TribeResourceAIModule::resourceName(TribeResourceAIModule *this,int param_1)
{
  char *pcVar1;
  
  if (param_1 == 0) {
    return s_Food;
  }
  if (param_1 == 1) {
    return s_Wood;
  }
  if (param_1 == 2) {
    return s_Stone;
  }
  pcVar1 = s_Gold;
  if (param_1 != 3) {
    pcVar1 = &s_Unknown;
  }
  return pcVar1;
}

// --------------------------------------------------

