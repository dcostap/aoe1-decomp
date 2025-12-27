// Class: TribeTradeShipUnitAIModule
// Function: TribeTradeShipUnitAIModule
// Address: 00506240
/* public: __thiscall TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(class RGE_Static_Object
   *,int) */

TribeTradeShipUnitAIModule * __thiscall
TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule
          (TribeTradeShipUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560ca8;
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
// Address: 005062f0
/* public: virtual void * __thiscall TribeTradeShipUnitAIModule::`scalar deleting
   destructor'(unsigned int) */

void * __thiscall
TribeTradeShipUnitAIModule::_scalar_deleting_destructor_
          (TribeTradeShipUnitAIModule *this,uint param_1)
{
  ~TribeTradeShipUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeTradeShipUnitAIModule
// Address: 00506310
/* public: virtual __thiscall TribeTradeShipUnitAIModule::~TribeTradeShipUnitAIModule(void) */

void __thiscall
TribeTradeShipUnitAIModule::~TribeTradeShipUnitAIModule(TribeTradeShipUnitAIModule *this)
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
// Address: 00506320
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* protected: virtual int __thiscall TribeTradeShipUnitAIModule::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribeTradeShipUnitAIModule::processNotify
          (TribeTradeShipUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  code *pcVar1;
  NotifyEvent *pNVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  ulong unaff_EDI;
  undefined4 uVar8;
  
  pNVar2 = param_1;
  iVar3 = param_1->mType;
  if (iVar3 != 500) {
    if (iVar3 == 0x202) {
      if (*(int *)&this->field_0x30 == 0x267) {
        iVar3 = *(int *)this;
        pcVar1 = *(code **)(iVar3 + 0x40);
        iVar4 = (*pcVar1)(0xffffffff,0,2,0x2d,0);
        if (iVar4 != -1) {
          iVar4 = (**(code **)(iVar3 + 0x7c))(iVar4,1);
          if (iVar4 == 1) {
            return 6;
          }
        }
        iVar4 = (*pcVar1)(0xffffffff,1,2,0x2d,0);
        if (iVar4 != -1) {
          iVar3 = (**(code **)(iVar3 + 0x7c))(iVar4,1);
          if (iVar3 == 1) {
            return 6;
          }
        }
        goto LAB_00506485;
      }
      if (*(int *)&this->field_0x30 != 0x25d) goto LAB_00506485;
      iVar3 = *(int *)this;
      iVar4 = (**(code **)(iVar3 + 0x48))(&param_1,&param_2,1);
      if (iVar4 == 1) {
        UnitAIModule::addToWaypointQueue((UnitAIModule *)this,(int)param_1,param_2);
        iVar4 = (**(code **)(iVar3 + 0x80))(param_1,param_2,1);
        if (iVar4 != 0) goto LAB_00506485;
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar7 = 0xffffffff;
            uVar8 = 0x79c;
          }
          else {
            uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
            uVar8 = 0x79c;
          }
          goto LAB_00506464;
        }
      }
      else {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar7 = 0xffffffff;
          }
          else {
            uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
          }
          uVar8 = 0x7a8;
LAB_00506464:
          fprintf(actionFile,s___d_call_stopObject__s__d_,uVar7,s_C__msdev_work_age1_x1_taiuaimd_c,
                  uVar8);
        }
      }
      (**(code **)(iVar3 + 0x58))(1);
      (**(code **)(iVar3 + 0x1c))(pNVar2);
LAB_00506485:
      UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
      if (actionFile != (_iobuf *)0x0) {
        if (*(int *)&this->field_0x4 == 0) {
          uVar7 = 0xffffffff;
        }
        else {
          uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,uVar7,s_C__msdev_work_age1_x1_taiuaimd_c,
                0x7b0);
      }
      iVar3 = *(int *)this;
      (**(code **)(iVar3 + 0x58))(1);
      (**(code **)(iVar3 + 0x1c))(pNVar2);
      return 2;
    }
    if (iVar3 != 0x20f) {
      iVar3 = UnitAIModule::processNotify((UnitAIModule *)this,param_1,param_2);
      return iVar3;
    }
  }
  if (param_1->p2 < 1) {
    uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
    (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0xc) + 0xe8))
              (uVar7,uVar7,0x209,param_1->caller,0,0);
    UnitAIModule::purgeNotifyQueue((UnitAIModule *)this,unaff_EDI);
    return 4;
  }
  if (*(int *)&this->field_0x64 != 0) {
    iVar3 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
    if (iVar3 != 1) goto LAB_0050654f;
  }
  uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
  (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0xc) + 0xe8))
            (uVar7,uVar7,0x201,pNVar2->caller,0,0);
LAB_0050654f:
  iVar3 = 0;
  if (0 < *(int *)&this->field_0x64) {
    do {
      if (*(int *)&this->field_0x6c <= iVar3) break;
      if (*(int *)(*(int *)&this->field_0x60 + iVar3 * 4) == pNVar2->caller) goto LAB_00506592;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)&this->field_0x64);
  }
  iVar3 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
  if ((iVar3 == 0) && (*(int *)&this->field_0x34 != pNVar2->caller)) {
    UnitAIModule::askForHelp((UnitAIModule *)this,pNVar2->caller);
  }
LAB_00506592:
  iVar3 = *(int *)&this->field_0x64;
  iVar4 = pNVar2->caller;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      if (*(int *)&this->field_0x6c <= iVar5) break;
      if (*(int *)(*(int *)&this->field_0x60 + iVar5 * 4) == iVar4) goto LAB_00506615;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  if (*(int *)&this->field_0x6c + -1 < iVar3) {
    iVar3 = iVar3 + 1;
    pvVar6 = operator_new(iVar3 * 4);
    if (pvVar6 != (void *)0x0) {
      iVar5 = 0;
      if (0 < *(int *)&this->field_0x6c) {
        do {
          if (iVar3 <= iVar5) break;
          iVar5 = iVar5 + 1;
          *(undefined4 *)((int)pvVar6 + iVar5 * 4 + -4) =
               *(undefined4 *)(*(int *)&this->field_0x60 + -4 + iVar5 * 4);
        } while (iVar5 < *(int *)&this->field_0x6c);
      }
      operator_delete(*(void **)&this->field_0x60);
      *(void **)&this->field_0x60 = pvVar6;
      *(int *)&this->field_0x6c = iVar3;
    }
  }
  *(int *)(*(int *)&this->field_0x60 + *(int *)&this->field_0x64 * 4) = iVar4;
  *(int *)&this->field_0x64 = *(int *)&this->field_0x64 + 1;
LAB_00506615:
  (**(code **)(**(int **)&this->field_0x4 + 0xec))(1);
  iVar3 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
  if ((iVar3 == 0) && (*(int *)&this->field_0x28 != -1)) {
    return 2;
  }
  if (*(int *)&this->field_0x30 != 0x262) {
    iVar3 = *(int *)this;
    (**(code **)(iVar3 + 0x10))
              (*(undefined4 *)(*(int *)&this->field_0x4 + 4),*(undefined4 *)&this->field_0x28,
               *(undefined4 *)&this->field_0x34,0xffffffff,*(undefined4 *)&this->field_0x3c,
               *(undefined4 *)&this->field_0x40,*(undefined4 *)&this->field_0x44,
               *(undefined4 *)&this->field_0x48,0,0,*(undefined4 *)&this->field_0x2c);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar7 = 0xffffffff;
      }
      else {
        uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,uVar7,s_C__msdev_work_age1_x1_taiuaimd_c,0x761
             );
    }
    (**(code **)(iVar3 + 0x58))(1);
  }
  (**(code **)(*(int *)this + 0xa4))(1);
  return 3;
}

// --------------------------------------------------

// Function: processIdle
// Address: 005066d0
/* WARNING: Variable defined which should be unmapped: yDiff */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribeTradeShipUnitAIModule::processIdle(int) */

int __thiscall TribeTradeShipUnitAIModule::processIdle(TribeTradeShipUnitAIModule *this,int param_1)
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

