// Class: TribeBuildingUnitAIModule
// Function: TribeBuildingUnitAIModule
// Address: 00508170
/* public: __thiscall TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(class RGE_Static_Object
   *,int) */

TribeBuildingUnitAIModule * __thiscall
TribeBuildingUnitAIModule::TribeBuildingUnitAIModule
          (TribeBuildingUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560d68;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)&this->field_0x128 = 0x15;
  puVar1 = (undefined4 *)operator_new(0x54);
  *(undefined4 **)&this->field_0x124 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined4 *)(*(int *)&this->field_0x124 + 4) = 3;
    *(undefined4 *)(*(int *)&this->field_0x124 + 8) = 4;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0xc) = 0x1a;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x10) = 0x18;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x14) = 6;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x18) = 0x23;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x1c) = 0x19;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x20) = 0x11;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x24) = 0xc;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x28) = 0x17;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x2c) = 0x24;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x30) = 0x1c;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x34) = 0x12;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x38) = 0xd;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x3c) = 0x1b;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x40) = 0x16;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x44) = 0x14;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x48) = 2;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x4c) = 0x15;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x50) = 0x27;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 005082f0
/* public: virtual void * __thiscall TribeBuildingUnitAIModule::`scalar deleting
   destructor'(unsigned int) */

void * __thiscall
TribeBuildingUnitAIModule::_scalar_deleting_destructor_
          (TribeBuildingUnitAIModule *this,uint param_1)
{
  ~TribeBuildingUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeBuildingUnitAIModule
// Address: 00508310
/* public: virtual __thiscall TribeBuildingUnitAIModule::~TribeBuildingUnitAIModule(void) */

void __thiscall
TribeBuildingUnitAIModule::~TribeBuildingUnitAIModule(TribeBuildingUnitAIModule *this)
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
// Address: 00508320
/* protected: virtual int __thiscall TribeBuildingUnitAIModule::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribeBuildingUnitAIModule::processNotify
          (TribeBuildingUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  undefined1 *this_00;
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  ulong unaff_EDI;
  
  switch(param_1->mType) {
  case 500:
    break;
  default:
    return 2;
  case 600:
    iVar4 = *(int *)&this->field_0x64;
    iVar5 = param_1->caller;
    iVar2 = 0;
    if (0 < iVar4) {
      do {
        if (*(int *)&this->field_0x6c <= iVar2) break;
        if (*(int *)(*(int *)&this->field_0x60 + iVar2 * 4) == iVar5) goto LAB_005084e0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar4);
    }
    if (*(int *)&this->field_0x6c + -1 < iVar4) {
      iVar4 = iVar4 + 1;
      pvVar3 = operator_new(iVar4 * 4);
      if (pvVar3 != (void *)0x0) {
        iVar2 = 0;
        if (0 < *(int *)&this->field_0x6c) {
          do {
            if (iVar4 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar3 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)&this->field_0x60 + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)&this->field_0x6c);
        }
        operator_delete(*(void **)&this->field_0x60);
        *(void **)&this->field_0x60 = pvVar3;
        *(int *)&this->field_0x6c = iVar4;
      }
    }
    *(int *)(*(int *)&this->field_0x60 + *(int *)&this->field_0x64 * 4) = iVar5;
    *(int *)&this->field_0x64 = *(int *)&this->field_0x64 + 1;
LAB_005084e0:
    (**(code **)(**(int **)&this->field_0x4 + 0xec))(1);
    return 2;
  case 699:
    iVar4 = 0;
    if (*(int *)&this->field_0x64 < 1) {
      return 2;
    }
    while( true ) {
      if (*(int *)&this->field_0x6c <= iVar4) {
        return 2;
      }
      if (*(int *)(*(int *)&this->field_0x60 + iVar4 * 4) == param_1->caller) break;
      iVar4 = iVar4 + 1;
      if (*(int *)&this->field_0x64 <= iVar4) {
        return 2;
      }
    }
    iVar4 = *(int *)&this->field_0x6c;
    iVar5 = 0;
    if (0 < iVar4) {
      piVar6 = *(int **)&this->field_0x60;
      do {
        if (*piVar6 == param_1->caller) break;
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar5 < iVar4);
    }
    if (iVar4 <= iVar5) {
      return 2;
    }
    if (iVar5 < iVar4 + -1) {
      do {
        iVar5 = iVar5 + 1;
        *(undefined4 *)(*(int *)&this->field_0x60 + -4 + iVar5 * 4) =
             *(undefined4 *)(*(int *)&this->field_0x60 + iVar5 * 4);
      } while (iVar5 < *(int *)&this->field_0x6c + -1);
    }
    iVar4 = *(int *)&this->field_0x64 + -1;
    *(int *)&this->field_0x64 = iVar4;
    if (iVar4 < 0) {
      *(undefined4 *)&this->field_0x64 = 0;
      return 2;
    }
    return 2;
  }
  if (param_1->p2 < 1) {
    uVar1 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
    (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0xc) + 0xe8))
              (uVar1,uVar1,0x209,param_1->caller,0,0);
    UnitAIModule::purgeNotifyQueue((UnitAIModule *)this,unaff_EDI);
    return 4;
  }
  if ((*(int *)&this->field_0x64 == 0) ||
     (iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc)),
     iVar4 == 1)) {
    uVar1 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
    (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0xc) + 0xe8))
              (uVar1,uVar1,0x201,param_1->caller,0,0);
  }
  this_00 = &this->field_0x60;
  iVar4 = 0;
  if (0 < *(int *)&this->field_0x64) {
    do {
      if (*(int *)&this->field_0x6c <= iVar4) break;
      if (*(int *)(*(int *)this_00 + iVar4 * 4) == param_1->caller) goto LAB_00508402;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)&this->field_0x64);
  }
  iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
  if ((iVar4 == 0) && (*(int *)&this->field_0x34 != param_1->caller)) {
    UnitAIModule::askForHelp((UnitAIModule *)this,param_1->caller);
  }
LAB_00508402:
  iVar4 = *(int *)&this->field_0x64;
  iVar5 = param_1->caller;
  iVar2 = 0;
  if (0 < iVar4) {
    do {
      if (*(int *)&this->field_0x6c <= iVar2) break;
      if (*(int *)(*(int *)this_00 + iVar2 * 4) == iVar5) goto LAB_005084e0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar4);
  }
  if (*(int *)&this->field_0x6c + -1 < iVar4) {
    ManagedArray<int>::resize((ManagedArray<int> *)this_00,iVar4 + 1);
  }
  *(int *)(*(int *)this_00 + *(int *)&this->field_0x64 * 4) = iVar5;
  *(int *)&this->field_0x64 = *(int *)&this->field_0x64 + 1;
  (**(code **)(**(int **)&this->field_0x4 + 0xec))(1);
  return 2;
}

// --------------------------------------------------

// Function: processIdle
// Address: 00508660
/* protected: virtual int __thiscall TribeBuildingUnitAIModule::processIdle(int) */

int __thiscall TribeBuildingUnitAIModule::processIdle(TribeBuildingUnitAIModule *this,int param_1)
{
  return 5;
}

// --------------------------------------------------

