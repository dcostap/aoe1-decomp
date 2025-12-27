// Class: TribeTransportShipUnitAIModule
// Function: TribeTransportShipUnitAIModule
// Address: 005067d0
/* public: __thiscall TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(class
   RGE_Static_Object *,int) */

TribeTransportShipUnitAIModule * __thiscall
TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule
          (TribeTransportShipUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560cc8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)&this->field_0x128 = 5;
  puVar1 = (undefined4 *)operator_new(0x14);
  *(undefined4 **)&this->field_0x124 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 3;
    *(undefined4 *)(*(int *)&this->field_0x124 + 4) = 0x16;
    *(undefined4 *)(*(int *)&this->field_0x124 + 8) = 0x14;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0xc) = 2;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x10) = 0x15;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00506880
/* public: virtual void * __thiscall TribeTransportShipUnitAIModule::`scalar deleting
   destructor'(unsigned int) */

void * __thiscall
TribeTransportShipUnitAIModule::_scalar_deleting_destructor_
          (TribeTransportShipUnitAIModule *this,uint param_1)
{
  ~TribeTransportShipUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeTransportShipUnitAIModule
// Address: 005068a0
/* public: virtual __thiscall TribeTransportShipUnitAIModule::~TribeTransportShipUnitAIModule(void)
    */

void __thiscall
TribeTransportShipUnitAIModule::~TribeTransportShipUnitAIModule
          (TribeTransportShipUnitAIModule *this)
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
// Address: 005068b0
/* protected: virtual int __thiscall TribeTransportShipUnitAIModule::processNotify(struct
   NotifyEvent *,unsigned long) */

int __thiscall
TribeTransportShipUnitAIModule::processNotify
          (TribeTransportShipUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  undefined4 uVar1;
  int iVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  RGE_Action *pRVar7;
  ulong unaff_EDI;
  
  if ((param_1->mType != 500) && (param_1->mType != 0x20f)) {
    iVar4 = UnitAIModule::processNotify((UnitAIModule *)this,param_1,param_2);
    return iVar4;
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
  iVar4 = 0;
  if (0 < *(int *)&this->field_0x64) {
    do {
      if (*(int *)&this->field_0x6c <= iVar4) break;
      if (*(int *)(*(int *)&this->field_0x60 + iVar4 * 4) == param_1->caller) goto LAB_00506990;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)&this->field_0x64);
  }
  iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
  if ((iVar4 == 0) && (*(int *)&this->field_0x34 != param_1->caller)) {
    UnitAIModule::askForHelp((UnitAIModule *)this,param_1->caller);
  }
LAB_00506990:
  iVar4 = *(int *)&this->field_0x64;
  iVar2 = param_1->caller;
  iVar5 = 0;
  if (0 < iVar4) {
    do {
      if (*(int *)&this->field_0x6c <= iVar5) break;
      if (*(int *)(*(int *)&this->field_0x60 + iVar5 * 4) == iVar2) goto LAB_00506a12;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  if (*(int *)&this->field_0x6c + -1 < iVar4) {
    iVar4 = iVar4 + 1;
    pvVar6 = operator_new(iVar4 * 4);
    if (pvVar6 != (void *)0x0) {
      iVar5 = 0;
      if (0 < *(int *)&this->field_0x6c) {
        do {
          if (iVar4 <= iVar5) break;
          iVar5 = iVar5 + 1;
          *(undefined4 *)((int)pvVar6 + iVar5 * 4 + -4) =
               *(undefined4 *)(*(int *)&this->field_0x60 + -4 + iVar5 * 4);
        } while (iVar5 < *(int *)&this->field_0x6c);
      }
      operator_delete(*(void **)&this->field_0x60);
      *(void **)&this->field_0x60 = pvVar6;
      *(int *)&this->field_0x6c = iVar4;
    }
  }
  *(int *)(*(int *)&this->field_0x60 + *(int *)&this->field_0x64 * 4) = iVar2;
  *(int *)&this->field_0x64 = *(int *)&this->field_0x64 + 1;
LAB_00506a12:
  (**(code **)(**(int **)&this->field_0x4 + 0xec))(1);
  if (*(int *)&this->field_0x28 != -1) {
    return 2;
  }
  iVar4 = *(int *)&this->field_0x4;
  uVar3 = RGE_Action_List::have_action(*(RGE_Action_List **)(iVar4 + 0x184));
  if ((uVar3 != '\0') &&
     (pRVar7 = RGE_Action_List::get_action(*(RGE_Action_List **)(iVar4 + 0x184)),
     pRVar7->state != '\x02')) {
    return 3;
  }
  (**(code **)(*(int *)this + 0xa4))(1);
  return 3;
}

// --------------------------------------------------

// Function: processIdle
// Address: 00506a70
/* WARNING: Variable defined which should be unmapped: yDiff */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribeTransportShipUnitAIModule::processIdle(int) */

int __thiscall
TribeTransportShipUnitAIModule::processIdle(TribeTransportShipUnitAIModule *this,int param_1)
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

