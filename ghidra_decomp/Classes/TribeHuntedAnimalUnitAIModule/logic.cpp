// Class: TribeHuntedAnimalUnitAIModule
// Function: TribeHuntedAnimalUnitAIModule
// Address: 00503bb0
/* public: __thiscall TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(class
   RGE_Static_Object *,int) */

TribeHuntedAnimalUnitAIModule * __thiscall
TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule
          (TribeHuntedAnimalUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560c08;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)&this->field_0x128 = 0x10;
  puVar1 = (undefined4 *)operator_new(0x40);
  *(undefined4 **)&this->field_0x124 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined4 *)(*(int *)&this->field_0x124 + 4) = 4;
    *(undefined4 *)(*(int *)&this->field_0x124 + 8) = 0x1a;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0xc) = 0x18;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x10) = 6;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x14) = 0x19;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x18) = 0x11;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x1c) = 10;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x20) = 0xc;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x24) = 0x23;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x28) = 0x17;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x2c) = 0x24;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x30) = 0x1c;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x34) = 0x12;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x38) = 0xd;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x3c) = 0x27;
  }
  *(undefined4 *)&this->field_0x100 = 4000;
  UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00503d00
/* public: virtual void * __thiscall TribeHuntedAnimalUnitAIModule::`scalar deleting
   destructor'(unsigned int) */

void * __thiscall
TribeHuntedAnimalUnitAIModule::_scalar_deleting_destructor_
          (TribeHuntedAnimalUnitAIModule *this,uint param_1)
{
  ~TribeHuntedAnimalUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeHuntedAnimalUnitAIModule
// Address: 00503d20
/* public: virtual __thiscall TribeHuntedAnimalUnitAIModule::~TribeHuntedAnimalUnitAIModule(void) */

void __thiscall
TribeHuntedAnimalUnitAIModule::~TribeHuntedAnimalUnitAIModule(TribeHuntedAnimalUnitAIModule *this)
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
// Address: 00503d30
/* protected: virtual int __thiscall TribeHuntedAnimalUnitAIModule::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribeHuntedAnimalUnitAIModule::processNotify
          (TribeHuntedAnimalUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
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
      if (*(int *)(*(int *)&this->field_0x60 + iVar3 * 4) == iVar1) goto LAB_00503e0b;
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
LAB_00503e0b:
  (**(code **)(**(int **)&this->field_0x4 + 0xec))(1);
  (**(code **)(*(int *)this + 0xa4))(1);
  return 3;
}

// --------------------------------------------------

// Function: processIdle
// Address: 00503e30
/* WARNING: Variable defined which should be unmapped: yDiff */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribeHuntedAnimalUnitAIModule::processIdle(int) */

int __thiscall
TribeHuntedAnimalUnitAIModule::processIdle(TribeHuntedAnimalUnitAIModule *this,int param_1)
{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  float10 fVar7;
  float yDiff;
  float xDiff;
  
  iVar1 = *(int *)this;
  iVar5 = (**(code **)(iVar1 + 0x40))(0xffffffff,0xffffffff,0xffffffff,0xffffffff,0);
  if (iVar5 != -1) {
    pRVar6 = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),iVar5)
    ;
    if (pRVar6 != (RGE_Static_Object *)0x0) {
      fVar7 = (float10)(**(code **)(**(int **)&this->field_0x4 + 0xfc))();
      iVar5 = *(int *)&this->field_0x4;
      fVar4 = pRVar6->world_x - *(float *)(iVar5 + 0x38);
      fVar2 = pRVar6->world_y - *(float *)(iVar5 + 0x3c);
      fVar3 = SQRT(fVar2 * fVar2 + fVar4 * fVar4);
      (**(code **)(iVar1 + 0x9c))
                (-((fVar4 / fVar3) * (float)(fVar7 * (float10)_DAT_005758b0)) +
                 *(float *)(iVar5 + 0x38),
                 -((fVar2 / fVar3) * (float)(fVar7 * (float10)_DAT_005758b0)) +
                 *(float *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x40),1);
      return 6;
    }
  }
  return 5;
}

// --------------------------------------------------

