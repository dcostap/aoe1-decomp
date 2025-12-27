// Class: ResourceAIModule
// Function: ResourceAIModule
// Address: 00412310
// [HELPER] s_Resource_AI: "Resource AI"
/* public: __thiscall ResourceAIModule::ResourceAIModule(void *,int,int,int,int,int) */

ResourceAIModule * __thiscall
ResourceAIModule::ResourceAIModule
          (ResourceAIModule *this,void *param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  int *piVar1;
  int **ppiVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c808;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  AIModule::AIModule((AIModule *)this,s_Resource_AI,0x3ef,param_2,param_1);
  local_4 = 0;
  this->md = (MainDecisionAIModule *)0x0;
  this->numberResourcesValue = param_3;
  this->_padding_ = (int)&_vftable_;
  piVar1 = (int *)operator_new(param_3 * 4);
  this->resourceValue = piVar1;
  piVar1 = (int *)operator_new(this->numberResourcesValue << 2);
  this->minValue = piVar1;
  piVar1 = (int *)operator_new(this->numberResourcesValue << 2);
  this->maxValue = piVar1;
  ppiVar2 = (int **)operator_new(this->numberResourcesValue << 2);
  this->resourceTypesValue = ppiVar2;
  piVar1 = (int *)operator_new(this->numberResourcesValue << 2);
  this->numberResourceTypesValue = piVar1;
  iVar3 = 0;
  if (0 < this->numberResourcesValue) {
    do {
      iVar4 = iVar3 + 1;
      this->resourceValue[iVar3] = param_4;
      this->minValue[iVar3] = param_5;
      this->maxValue[iVar3] = param_6;
      this->numberResourceTypesValue[iVar3] = 0;
      this->resourceTypesValue[iVar3] = (int *)0x0;
      iVar3 = iVar4;
    } while (iVar4 < this->numberResourcesValue);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00412460
/* public: virtual void * __thiscall ResourceAIModule::`vector deleting destructor'(unsigned int) */

void * __thiscall
ResourceAIModule::_vector_deleting_destructor_(ResourceAIModule *this,uint param_1)
{
  ~ResourceAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~ResourceAIModule
// Address: 00412480
/* public: virtual __thiscall ResourceAIModule::~ResourceAIModule(void) */

void __thiscall ResourceAIModule::~ResourceAIModule(ResourceAIModule *this)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055c828;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  iVar1 = 0;
  local_4 = 0;
  operator_delete(this->resourceValue);
  operator_delete(this->minValue);
  operator_delete(this->maxValue);
  if (0 < this->numberResourcesValue) {
    do {
      operator_delete(this->resourceTypesValue[iVar1]);
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->numberResourcesValue);
  }
  operator_delete(this->resourceTypesValue);
  operator_delete(this->numberResourceTypesValue);
  local_4 = 0xffffffff;
  AIModule::~AIModule((AIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: processMessage
// Address: 00412540
/* public: virtual int __thiscall ResourceAIModule::processMessage(class AIModuleMessage *) */

int __thiscall ResourceAIModule::processMessage(ResourceAIModule *this,AIModuleMessage *param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: update
// Address: 00412550
/* public: virtual int __thiscall ResourceAIModule::update(int) */

int __thiscall ResourceAIModule::update(ResourceAIModule *this,int param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: setCallbackMessage
// Address: 00412560
/* public: virtual void __thiscall ResourceAIModule::setCallbackMessage(class AIModuleMessage *) */

void __thiscall
ResourceAIModule::setCallbackMessage(ResourceAIModule *this,AIModuleMessage *param_1)
{
  return;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 00412570
/* public: void __thiscall ResourceAIModule::setMainDecisionAI(class MainDecisionAIModule *) */

void __thiscall
ResourceAIModule::setMainDecisionAI(ResourceAIModule *this,MainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: numberResources
// Address: 00412580
/* public: int __thiscall ResourceAIModule::numberResources(void)const  */

int __thiscall ResourceAIModule::numberResources(ResourceAIModule *this)
{
  return this->numberResourcesValue;
}

// --------------------------------------------------

// Function: resource
// Address: 00412590
/* public: int __thiscall ResourceAIModule::resource(int)const  */

int __thiscall ResourceAIModule::resource(ResourceAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
    return this->resourceValue[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: resourcesAvailable
// Address: 004125c0
/* public: int __thiscall ResourceAIModule::resourcesAvailable(class ResourceItem *) */

int __thiscall ResourceAIModule::resourcesAvailable(ResourceAIModule *this,ResourceItem *param_1)
{
  int iVar1;
  int iVar2;
  
  if (param_1 == (ResourceItem *)0x0) {
    return 0;
  }
  iVar1 = ResourceItem::number(param_1);
  if (this->numberResourcesValue != iVar1) {
    return 0;
  }
  iVar2 = 0;
  iVar1 = ResourceItem::number(param_1);
  if (iVar1 < 1) {
    return 1;
  }
  do {
    iVar1 = ResourceItem::value(param_1,iVar2);
    if (this->resourceValue[iVar2] < iVar1) {
      return 0;
    }
    iVar2 = iVar2 + 1;
    iVar1 = ResourceItem::number(param_1);
  } while (iVar2 < iVar1);
  return 1;
}

// --------------------------------------------------

// Function: unavailableResource
// Address: 00412640
/* public: int __thiscall ResourceAIModule::unavailableResource(class ResourceItem *) */

int __thiscall ResourceAIModule::unavailableResource(ResourceAIModule *this,ResourceItem *param_1)
{
  int iVar1;
  int iVar2;
  
  if (param_1 == (ResourceItem *)0x0) {
    return 0;
  }
  iVar1 = ResourceItem::number(param_1);
  if (this->numberResourcesValue == iVar1) {
    iVar2 = 0;
    iVar1 = ResourceItem::number(param_1);
    if (0 < iVar1) {
      do {
        iVar1 = ResourceItem::value(param_1,iVar2);
        if (this->resourceValue[iVar2] < iVar1) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        iVar1 = ResourceItem::number(param_1);
      } while (iVar2 < iVar1);
      return -1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: minValueOfResource
// Address: 004126b0
/* public: int __thiscall ResourceAIModule::minValueOfResource(int)const  */

int __thiscall ResourceAIModule::minValueOfResource(ResourceAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
    return this->minValue[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: maxValueOfResource
// Address: 004126e0
/* public: int __thiscall ResourceAIModule::maxValueOfResource(int)const  */

int __thiscall ResourceAIModule::maxValueOfResource(ResourceAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
    return this->maxValue[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: setResource
// Address: 00412710
// [HELPER] s___setResource__r__d___d_: "  setResource: r[%d]=%d."
// [HELPER] s_setResource__n__d__v__d_: "setResource: n=%d, v=%d."
/* public: void __thiscall ResourceAIModule::setResource(int,int) */

void __thiscall ResourceAIModule::setResource(ResourceAIModule *this,int param_1,int param_2)
{
  AIModule::logCommonHistory
            ((AIModule *)this,(char *)this,s_setResource__n__d__v__d_,param_1,param_2);
  if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
    this->resourceValue[param_1] = param_2;
    AIModule::logCommonHistory
              ((AIModule *)this->resourceValue,(char *)this,s___setResource__r__d___d_,param_1,
               *(undefined4 *)
                ((((AIModule *)this->resourceValue)->idValue).name + param_1 * 4 + -0xc));
  }
  return;
}

// --------------------------------------------------

// Function: setResources
// Address: 00412770
/* public: void __thiscall ResourceAIModule::setResources(class ResourceItem *) */

void __thiscall ResourceAIModule::setResources(ResourceAIModule *this,ResourceItem *param_1)
{
  int iVar1;
  int iVar2;
  
  if (param_1 != (ResourceItem *)0x0) {
    iVar1 = ResourceItem::number(param_1);
    if (this->numberResourcesValue == iVar1) {
      iVar2 = 0;
      iVar1 = ResourceItem::number(param_1);
      if (0 < iVar1) {
        do {
          iVar1 = ResourceItem::value(param_1,iVar2);
          setResource(this,iVar2,iVar1);
          iVar2 = iVar2 + 1;
          iVar1 = ResourceItem::number(param_1);
        } while (iVar2 < iVar1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: incrementResource
// Address: 004127c0
// [HELPER] s___incrementResource__r__d___d_: "  incrementResource: r[%d]=%d."
// [HELPER] s_incrementResource__n__d__v__d_: "incrementResource: n=%d, v=%d."
/* public: void __thiscall ResourceAIModule::incrementResource(int,int) */

void __thiscall ResourceAIModule::incrementResource(ResourceAIModule *this,int param_1,int param_2)
{
  AIModule::logCommonHistory
            ((AIModule *)this,(char *)this,s_incrementResource__n__d__v__d_,param_1,param_2);
  if (((-1 < param_1) && (param_1 < this->numberResourcesValue)) &&
     (this->resourceValue[param_1] = this->resourceValue[param_1] + param_2, param_2 != 0)) {
    AIModule::logCommonHistory
              ((AIModule *)this->resourceValue,(char *)this,s___incrementResource__r__d___d_,param_1
               ,*(undefined4 *)
                 ((((AIModule *)this->resourceValue)->idValue).name + param_1 * 4 + -0xc));
  }
  return;
}

// --------------------------------------------------

// Function: incrementResources
// Address: 00412820
/* public: void __thiscall ResourceAIModule::incrementResources(class ResourceItem *) */

void __thiscall ResourceAIModule::incrementResources(ResourceAIModule *this,ResourceItem *param_1)
{
  int iVar1;
  int iVar2;
  
  if (param_1 != (ResourceItem *)0x0) {
    iVar1 = ResourceItem::number(param_1);
    if (this->numberResourcesValue == iVar1) {
      iVar2 = 0;
      iVar1 = ResourceItem::number(param_1);
      if (0 < iVar1) {
        do {
          iVar1 = ResourceItem::value(param_1,iVar2);
          incrementResource(this,iVar2,iVar1);
          iVar2 = iVar2 + 1;
          iVar1 = ResourceItem::number(param_1);
        } while (iVar2 < iVar1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: decrementResource
// Address: 00412870
// [HELPER] s___decrementResource__r__d___d_: "  decrementResource: r[%d]=%d."
// [HELPER] s_decrementResource__n__d__v__d_: "decrementResource: n=%d, v=%d."
/* public: void __thiscall ResourceAIModule::decrementResource(int,int) */

void __thiscall ResourceAIModule::decrementResource(ResourceAIModule *this,int param_1,int param_2)
{
  AIModule::logCommonHistory
            ((AIModule *)this,(char *)this,s_decrementResource__n__d__v__d_,param_1,param_2);
  if (((-1 < param_1) && (param_1 < this->numberResourcesValue)) &&
     (this->resourceValue[param_1] = this->resourceValue[param_1] - param_2, param_2 != 0)) {
    AIModule::logCommonHistory
              ((AIModule *)this->resourceValue,(char *)this,s___decrementResource__r__d___d_,param_1
               ,*(undefined4 *)
                 ((((AIModule *)this->resourceValue)->idValue).name + param_1 * 4 + -0xc));
  }
  return;
}

// --------------------------------------------------

// Function: decrementResources
// Address: 004128d0
/* public: void __thiscall ResourceAIModule::decrementResources(class ResourceItem *) */

void __thiscall ResourceAIModule::decrementResources(ResourceAIModule *this,ResourceItem *param_1)
{
  int iVar1;
  int iVar2;
  
  if (param_1 != (ResourceItem *)0x0) {
    iVar1 = ResourceItem::number(param_1);
    if (this->numberResourcesValue == iVar1) {
      iVar2 = 0;
      iVar1 = ResourceItem::number(param_1);
      if (0 < iVar1) {
        do {
          iVar1 = ResourceItem::value(param_1,iVar2);
          decrementResource(this,iVar2,iVar1);
          iVar2 = iVar2 + 1;
          iVar1 = ResourceItem::number(param_1);
        } while (iVar2 < iVar1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: setResourceMin
// Address: 00412920
/* public: void __thiscall ResourceAIModule::setResourceMin(int,int) */

void __thiscall ResourceAIModule::setResourceMin(ResourceAIModule *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
    this->minValue[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: setResourceMax
// Address: 00412940
/* public: void __thiscall ResourceAIModule::setResourceMax(int,int) */

void __thiscall ResourceAIModule::setResourceMax(ResourceAIModule *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
    this->maxValue[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: filterOutMessage
// Address: 00412960
/* protected: virtual int __thiscall ResourceAIModule::filterOutMessage(class AIModuleMessage *) */

int __thiscall ResourceAIModule::filterOutMessage(ResourceAIModule *this,AIModuleMessage *param_1)
{
  int iVar1;
  
  iVar1 = AIModule::filterOutMessage((AIModule *)this,param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: addResourceType
// Address: 00412970
/* public: void __thiscall ResourceAIModule::addResourceType(int,int) */

void __thiscall ResourceAIModule::addResourceType(ResourceAIModule *this,int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)operator_new(this->numberResourceTypesValue[param_1] * 4 + 4);
  iVar2 = 0;
  iVar3 = iVar2;
  if (0 < this->numberResourceTypesValue[param_1]) {
    do {
      iVar2 = iVar3 + 1;
      piVar1[iVar3] = this->resourceTypesValue[param_1][iVar3];
      iVar3 = iVar2;
    } while (iVar2 < this->numberResourceTypesValue[param_1]);
  }
  piVar1[iVar2] = param_2;
  if (this->resourceTypesValue[param_1] != (int *)0x0) {
    operator_delete(this->resourceTypesValue[param_1]);
  }
  this->resourceTypesValue[param_1] = piVar1;
  this->numberResourceTypesValue[param_1] = this->numberResourceTypesValue[param_1] + 1;
  return;
}

// --------------------------------------------------

// Function: isResourceType
// Address: 00412a10
// [HELPER] s_Entering_isResourceType__r__d__t: "Entering isResourceType: r=%d, t=%d."
// [HELPER] s___No_match___Returning_FALSE_: "  No match!  Returning FALSE."
// [HELPER] s___There_are__d_resource_types_fo: "  There are %d resource types for resource %d."
// [HELPER] s_____Checking_against_type__d_: "    Checking against type %d."
// [HELPER] s_______Match___Returning_TRUE_: "      Match!  Returning TRUE."
/* public: int __thiscall ResourceAIModule::isResourceType(int,int) */

int __thiscall ResourceAIModule::isResourceType(ResourceAIModule *this,int param_1,int param_2)
{
  int *piVar1;
  AIModule *extraout_ECX;
  AIModule *this_00;
  AIModule *this_01;
  int iVar2;
  
  AIModule::logCommonHistory
            ((AIModule *)this,(char *)this,s_Entering_isResourceType__r__d__t,param_1,param_2);
  AIModule::logCommonHistory
            ((AIModule *)this->numberResourceTypesValue[param_1],(char *)this,
             s___There_are__d_resource_types_fo,(AIModule *)this->numberResourceTypesValue[param_1],
             param_1);
  iVar2 = 0;
  this_01 = extraout_ECX;
  if (0 < this->numberResourceTypesValue[param_1]) {
    piVar1 = this->resourceTypesValue[param_1];
    do {
      AIModule::logCommonHistory
                ((AIModule *)piVar1[iVar2],(char *)this,s_____Checking_against_type__d_,
                 (AIModule *)piVar1[iVar2]);
      piVar1 = this->resourceTypesValue[param_1];
      if (piVar1[iVar2] == param_2) {
        AIModule::logCommonHistory(this_00,(char *)this,s_______Match___Returning_TRUE_);
        return 1;
      }
      this_01 = (AIModule *)this->numberResourceTypesValue;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((this_01->idValue).name + param_1 * 4 + -0xc));
  }
  AIModule::logCommonHistory(this_01,(char *)this,s___No_match___Returning_FALSE_);
  return 0;
}

// --------------------------------------------------

// Function: numberResourceTypes
// Address: 00412ad0
/* public: int __thiscall ResourceAIModule::numberResourceTypes(int) */

int __thiscall ResourceAIModule::numberResourceTypes(ResourceAIModule *this,int param_1)
{
  return this->numberResourceTypesValue[param_1];
}

// --------------------------------------------------

// Function: lowestResourceType
// Address: 00412ae0
/* public: int __thiscall ResourceAIModule::lowestResourceType(void)const  */

int __thiscall ResourceAIModule::lowestResourceType(ResourceAIModule *this)
{
  return 1;
}

// --------------------------------------------------

