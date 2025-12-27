// Class: TribeLionUnitAIModule
// Function: TribeLionUnitAIModule
// Address: 005042e0
/* public: __thiscall TribeLionUnitAIModule::TribeLionUnitAIModule(class RGE_Static_Object *,int) */

TribeLionUnitAIModule * __thiscall
TribeLionUnitAIModule::TribeLionUnitAIModule
          (TribeLionUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560c48;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)&this->field_0x128 = 0x11;
  puVar1 = (undefined4 *)operator_new(0x44);
  *(undefined4 **)&this->field_0x124 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0x1d;
    *(undefined4 *)(*(int *)&this->field_0x124 + 4) = 9;
    *(undefined4 *)(*(int *)&this->field_0x124 + 8) = 0;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0xc) = 4;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x10) = 0x1a;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x14) = 0x18;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x18) = 6;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x1c) = 0x19;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x20) = 0x11;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x24) = 0xd;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x28) = 0xc;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x2c) = 0x23;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x30) = 0x17;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x34) = 0x24;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x38) = 0x1c;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x3c) = 0x12;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x40) = 0x27;
  }
  *(undefined4 *)&this->field_0x100 = 6000;
  UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00504440
/* public: virtual void * __thiscall TribeLionUnitAIModule::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
TribeLionUnitAIModule::_vector_deleting_destructor_(TribeLionUnitAIModule *this,uint param_1)
{
  ~TribeLionUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeLionUnitAIModule
// Address: 00504460
/* public: virtual __thiscall TribeLionUnitAIModule::~TribeLionUnitAIModule(void) */

void __thiscall TribeLionUnitAIModule::~TribeLionUnitAIModule(TribeLionUnitAIModule *this)
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

// Function: canAttackUnitAtNeutrality
// Address: 00504470
/* public: virtual int __thiscall TribeLionUnitAIModule::canAttackUnitAtNeutrality(int) */

int __thiscall
TribeLionUnitAIModule::canAttackUnitAtNeutrality(TribeLionUnitAIModule *this,int param_1)
{
  return 1;
}

// --------------------------------------------------

// Function: processNotify
// Address: 00504480
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* protected: virtual int __thiscall TribeLionUnitAIModule::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribeLionUnitAIModule::processNotify(TribeLionUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  RGE_Static_Object *pRVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  ulong unaff_retaddr;
  
  if (param_1->mType != 0x1fa) {
    if (param_1->mType == 0x1fc) {
      pRVar1 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),
                          *(int *)&this->field_0x34);
      if (pRVar1 != (RGE_Static_Object *)0x0) {
        fVar4 = RGE_Static_Object::distance_to_object
                          (*(RGE_Static_Object **)&this->field_0x4,pRVar1);
        if (fVar4 <= *(float *)(*(int *)(*(int *)&this->field_0x4 + 8) + 0x28)) {
          (**(code **)(*(int *)this + 0x5c))(*(undefined4 *)&this->field_0x34,1);
          return 3;
        }
      }
      UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
      if (actionFile != (_iobuf *)0x0) {
        if (*(int *)&this->field_0x4 == 0) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,uVar2,s_C__msdev_work_age1_x1_taiuaimd_c,
                0x1ac);
      }
      iVar3 = *(int *)this;
      (**(code **)(iVar3 + 0x58))(1);
      (**(code **)(iVar3 + 0x1c))(param_1);
      iVar3 = UnitAIModule::processNotify((UnitAIModule *)this,param_1,unaff_retaddr);
      return iVar3;
    }
    goto LAB_005045ea;
  }
  if (param_1->p1 != 600) goto LAB_005045ea;
  iVar3 = RGE_Base_Game::scenarioGame(rge_base_game);
  if (iVar3 == 1) {
    iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game);
    if (iVar3 != 1) goto LAB_00504597;
    iVar3 = RGE_Game_World::difficultyLevel
                      (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c));
    *(int *)&this->field_0x100 = (iVar3 + 3) * 5000;
  }
  else {
LAB_00504597:
    *(undefined4 *)&this->field_0x100 = 25000;
  }
  UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)this);
  UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
  if (actionFile != (_iobuf *)0x0) {
    if (*(int *)&this->field_0x4 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
    }
    fprintf(actionFile,s___d_call_stopObject__s__d_,uVar2,s_C__msdev_work_age1_x1_taiuaimd_c,0x191);
  }
  (**(code **)(*(int *)this + 0x58))(1);
LAB_005045ea:
  iVar3 = UnitAIModule::processNotify((UnitAIModule *)this,param_1,param_2);
  return iVar3;
}

// --------------------------------------------------

// Function: processIdle
// Address: 00504600
/* WARNING: Variable defined which should be unmapped: maxReactDistance */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribeLionUnitAIModule::processIdle(int) */

int __thiscall TribeLionUnitAIModule::processIdle(TribeLionUnitAIModule *this,int param_1)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  RGE_Static_Object *this_00;
  float fVar6;
  float fVar7;
  float maxReactDistance;
  RGE_Static_Object *newTarget;
  
  *(undefined4 *)&this->field_0x100 = 6000;
  UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)this);
  iVar1 = *(int *)this;
  iVar2 = (**(code **)(iVar1 + 0x40))(0xffffffff,0xffffffff,0xffffffff,0xffffffff,0);
  pRVar3 = UnitAIModule::lookupObject((UnitAIModule *)this,iVar2);
  if ((iVar2 != -1) && (pRVar3 != (RGE_Static_Object *)0x0)) {
    iVar4 = RGE_Game_World::difficultyLevel
                      (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c));
    iVar5 = RGE_Base_Game::scenarioGame(rge_base_game);
    if ((iVar5 == 1) &&
       ((iVar5 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar5 == 1 && (2 < iVar4)))) {
      fVar7 = _DAT_005758b8;
      if (iVar4 == 3) {
        fVar7 = _DAT_005758b4;
      }
      this_00 = *(RGE_Static_Object **)&this->field_0x4;
      fVar7 = fVar7 * this_00->master_obj->los;
      if (fVar7 < _DAT_005758bc) {
        fVar7 = 1.0;
      }
    }
    else {
      this_00 = *(RGE_Static_Object **)&this->field_0x4;
      fVar7 = this_00->master_obj->los;
      fVar7 = fVar7 + fVar7;
    }
    fVar6 = RGE_Static_Object::distance_to_object(this_00,pRVar3);
    if (fVar6 <= fVar7) {
      (**(code **)(iVar1 + 0x5c))(iVar2,0);
      return 6;
    }
  }
  return 5;
}

// --------------------------------------------------

