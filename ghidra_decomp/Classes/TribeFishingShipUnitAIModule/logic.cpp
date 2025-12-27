// Class: TribeFishingShipUnitAIModule
// Function: TribeFishingShipUnitAIModule
// Address: 00506b70
/* public: __thiscall TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(class
   RGE_Static_Object *,int) */

TribeFishingShipUnitAIModule * __thiscall
TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule
          (TribeFishingShipUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560ce8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)&this->field_0x128 = 8;
  puVar1 = (undefined4 *)operator_new(0x20);
  *(undefined4 **)&this->field_0x124 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 3;
    *(undefined4 *)(*(int *)&this->field_0x124 + 4) = 0x16;
    *(undefined4 *)(*(int *)&this->field_0x124 + 8) = 0x14;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0xc) = 2;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x10) = 0x15;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x14) = 5;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x18) = 0x1f;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x1c) = 0x21;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00506c40
/* public: virtual void * __thiscall TribeFishingShipUnitAIModule::`scalar deleting
   destructor'(unsigned int) */

void * __thiscall
TribeFishingShipUnitAIModule::_scalar_deleting_destructor_
          (TribeFishingShipUnitAIModule *this,uint param_1)
{
  ~TribeFishingShipUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeFishingShipUnitAIModule
// Address: 00506c60
/* public: virtual __thiscall TribeFishingShipUnitAIModule::~TribeFishingShipUnitAIModule(void) */

void __thiscall
TribeFishingShipUnitAIModule::~TribeFishingShipUnitAIModule(TribeFishingShipUnitAIModule *this)
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

// Function: importantWhenDead
// Address: 00506c70
/* public: virtual int __thiscall TribeFishingShipUnitAIModule::importantWhenDead(int) */

int __thiscall
TribeFishingShipUnitAIModule::importantWhenDead(TribeFishingShipUnitAIModule *this,int param_1)
{
  if ((param_1 != 0x1f) && (param_1 != 5)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: convertToLOSResourceType
// Address: 00506c90
/* public: virtual int __thiscall TribeFishingShipUnitAIModule::convertToLOSResourceType(int) */

int __thiscall
TribeFishingShipUnitAIModule::convertToLOSResourceType
          (TribeFishingShipUnitAIModule *this,int param_1)
{
  if (((param_1 != 0x1f) && (param_1 != 5)) && (param_1 != 0x21)) {
    return -1;
  }
  return 2;
}

// --------------------------------------------------

// Function: processNotify
// Address: 00506cc0
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* protected: virtual int __thiscall TribeFishingShipUnitAIModule::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribeFishingShipUnitAIModule::processNotify
          (TribeFishingShipUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  ulong unaff_EDI;
  
  if ((param_1->mType != 500) && (param_1->mType != 0x20f)) {
    iVar2 = UnitAIModule::processNotify((UnitAIModule *)this,param_1,param_2);
    return iVar2;
  }
  if (param_1->p2 < 1) {
    uVar5 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
    (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0xc) + 0xe8))
              (uVar5,uVar5,0x209,param_1->caller,0,0);
    UnitAIModule::purgeNotifyQueue((UnitAIModule *)this,unaff_EDI);
    return 4;
  }
  if (*(int *)&this->field_0x64 != 0) {
    iVar2 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
    if (iVar2 != 1) goto LAB_00506d5f;
  }
  uVar5 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
  (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0xc) + 0xe8))
            (uVar5,uVar5,0x201,param_1->caller,0,0);
LAB_00506d5f:
  iVar2 = 0;
  if (0 < *(int *)&this->field_0x64) {
    do {
      if (*(int *)&this->field_0x6c <= iVar2) break;
      if (*(int *)(*(int *)&this->field_0x60 + iVar2 * 4) == param_1->caller) goto LAB_00506da0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)&this->field_0x64);
  }
  iVar2 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
  if ((iVar2 == 0) && (*(int *)&this->field_0x34 != param_1->caller)) {
    UnitAIModule::askForHelp((UnitAIModule *)this,param_1->caller);
  }
LAB_00506da0:
  iVar2 = *(int *)&this->field_0x64;
  iVar1 = param_1->caller;
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if (*(int *)&this->field_0x6c <= iVar3) break;
      if (*(int *)(*(int *)&this->field_0x60 + iVar3 * 4) == iVar1) goto LAB_00506e22;
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
LAB_00506e22:
  (**(code **)(**(int **)&this->field_0x4 + 0xec))(1);
  iVar2 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
  if ((iVar2 == 0) && (*(int *)&this->field_0x28 != -1)) {
    return 2;
  }
  if (*(int *)&this->field_0x30 != 0x262) {
    iVar2 = *(int *)this;
    (**(code **)(iVar2 + 0x10))
              (*(undefined4 *)(*(int *)&this->field_0x4 + 4),*(undefined4 *)&this->field_0x28,
               *(undefined4 *)&this->field_0x34,0xffffffff,*(undefined4 *)&this->field_0x3c,
               *(undefined4 *)&this->field_0x40,*(undefined4 *)&this->field_0x44,
               *(undefined4 *)&this->field_0x48,0,0,*(undefined4 *)&this->field_0x2c);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,uVar5,s_C__msdev_work_age1_x1_taiuaimd_c,0x8d4
             );
    }
    (**(code **)(iVar2 + 0x58))(1);
  }
  (**(code **)(*(int *)this + 0xa4))(1);
  return 3;
}

// --------------------------------------------------

// Function: processIdle
// Address: 00506ee0
/* WARNING: Variable defined which should be unmapped: yDiff */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribeFishingShipUnitAIModule::processIdle(int) */

int __thiscall
TribeFishingShipUnitAIModule::processIdle(TribeFishingShipUnitAIModule *this,int param_1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  float10 fVar7;
  float yDiff;
  float xDiff;
  
  iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
  if (iVar4 != 0) {
    iVar4 = *(int *)this;
    iVar5 = (**(code **)(iVar4 + 0x40))(0xffffffff,0xffffffff,0xffffffff,0xffffffff,0);
    if (iVar5 != -1) {
      pRVar6 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),
                          iVar5);
      if (pRVar6 != (RGE_Static_Object *)0x0) {
        fVar7 = (float10)(**(code **)(**(int **)&this->field_0x4 + 0xfc))();
        iVar5 = *(int *)&this->field_0x4;
        fVar3 = pRVar6->world_x - *(float *)(iVar5 + 0x38);
        fVar1 = pRVar6->world_y - *(float *)(iVar5 + 0x3c);
        fVar2 = SQRT(fVar1 * fVar1 + fVar3 * fVar3);
        (**(code **)(iVar4 + 0x9c))
                  (-((fVar3 / fVar2) * (float)(fVar7 * (float10)_DAT_005758d8)) +
                   *(float *)(iVar5 + 0x38),
                   -((fVar1 / fVar2) * (float)(fVar7 * (float10)_DAT_005758d8)) +
                   *(float *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x40),1);
        return 6;
      }
    }
  }
  return 5;
}

// --------------------------------------------------

