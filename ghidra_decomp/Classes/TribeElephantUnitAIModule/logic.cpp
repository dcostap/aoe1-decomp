// Class: TribeElephantUnitAIModule
// Function: TribeElephantUnitAIModule
// Address: 00504170
/* public: __thiscall TribeElephantUnitAIModule::TribeElephantUnitAIModule(class RGE_Static_Object
   *,int) */

TribeElephantUnitAIModule * __thiscall
TribeElephantUnitAIModule::TribeElephantUnitAIModule
          (TribeElephantUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00504190
/* public: virtual void * __thiscall TribeElephantUnitAIModule::`vector deleting
   destructor'(unsigned int) */

void * __thiscall
TribeElephantUnitAIModule::_vector_deleting_destructor_
          (TribeElephantUnitAIModule *this,uint param_1)
{
  ~TribeElephantUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeElephantUnitAIModule
// Address: 005041b0
/* public: virtual __thiscall TribeElephantUnitAIModule::~TribeElephantUnitAIModule(void) */

void __thiscall
TribeElephantUnitAIModule::~TribeElephantUnitAIModule(TribeElephantUnitAIModule *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055c8ab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)this = &UnitAIModule::_vftable_;
  uStack_4 = 0;
  if (*(void **)&this->field_0x18 != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x18);
    *(undefined4 *)&this->field_0x18 = 0;
  }
  if (*(void **)&this->field_0x24 != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x24);
    *(undefined4 *)&this->field_0x24 = 0;
  }
  if (*(void **)&this->field_0x124 != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x124);
    *(undefined4 *)&this->field_0x124 = 0;
  }
  if (*(void **)&this->field_0x12c != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x12c);
    *(undefined4 *)&this->field_0x12c = 0;
  }
  uStack_4 = 0xffffffff;
  if (*(void **)&this->field_0x60 != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x60);
    *(undefined4 *)&this->field_0x60 = 0;
  }
  *(undefined4 *)&this->field_0x64 = 0;
  *(undefined4 *)&this->field_0x68 = 0;
  *(undefined4 *)&this->field_0x6c = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: processNotify
// Address: 005041c0
/* protected: virtual int __thiscall TribeElephantUnitAIModule::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribeElephantUnitAIModule::processNotify
          (TribeElephantUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  
  if (param_1->mType != 500) {
    if (param_1->mType != 0x20f) {
      iVar2 = UnitAIModule::processNotify((UnitAIModule *)this,param_1,param_2);
      return iVar2;
    }
    return 2;
  }
  if (param_1->p2 < 1) {
    UnitAIModule::purgeNotifyQueue((UnitAIModule *)this,param_2);
    return 4;
  }
  iVar1 = param_1->caller;
  iVar2 = *(int *)&this->field_0x64;
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if (*(int *)&this->field_0x6c <= iVar3) break;
      if (*(int *)(*(int *)&this->field_0x60 + iVar3 * 4) == iVar1) goto LAB_0050429b;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  if (*(int *)&this->field_0x6c + -1 < iVar2) {
    iVar2 = iVar2 + 1;
    pvVar4 = operator_new(iVar2 * 4);
    if (pvVar4 != (void *)0x0) {
      iVar3 = 0;
      if (0 < *(int *)&this->field_0x6c) {
        do {
          if (iVar2 <= iVar3) break;
          iVar3 = iVar3 + 1;
          *(undefined4 *)((int)pvVar4 + iVar3 * 4 + -4) =
               *(undefined4 *)(*(int *)&this->field_0x60 + -4 + iVar3 * 4);
        } while (iVar3 < *(int *)&this->field_0x6c);
      }
      operator_delete(*(void **)&this->field_0x60);
      *(void **)&this->field_0x60 = pvVar4;
      *(int *)&this->field_0x6c = iVar2;
    }
  }
  *(int *)(*(int *)&this->field_0x60 + *(int *)&this->field_0x64 * 4) = iVar1;
  *(int *)&this->field_0x64 = *(int *)&this->field_0x64 + 1;
LAB_0050429b:
  (**(code **)(**(int **)&this->field_0x4 + 0xec))(1);
  iVar2 = *(int *)this;
  uVar5 = (**(code **)(iVar2 + 0x3c))(0);
  (**(code **)(iVar2 + 0x5c))(uVar5,0);
  return 3;
}

// --------------------------------------------------

// Function: processIdle
// Address: 005042d0
/* protected: virtual int __thiscall TribeElephantUnitAIModule::processIdle(int) */

int __thiscall TribeElephantUnitAIModule::processIdle(TribeElephantUnitAIModule *this,int param_1)
{
  return 5;
}

// --------------------------------------------------

