// Class: TribePriestUnitAIModule
// Function: TribePriestUnitAIModule
// Address: 00505820
/* public: __thiscall TribePriestUnitAIModule::TribePriestUnitAIModule(class RGE_Static_Object
   *,int) */

TribePriestUnitAIModule * __thiscall
TribePriestUnitAIModule::TribePriestUnitAIModule
          (TribePriestUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560c88;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)&this->field_0x128 = 0x11;
  puVar1 = (undefined4 *)operator_new(0x44);
  *(undefined4 **)&this->field_0x124 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 3;
    *(undefined4 *)(*(int *)&this->field_0x124 + 4) = 0;
    *(undefined4 *)(*(int *)&this->field_0x124 + 8) = 4;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0xc) = 0x1a;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x10) = 0x18;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x14) = 6;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x18) = 0x19;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x1c) = 0x11;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x20) = 10;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x24) = 0xc;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x28) = 0x23;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x2c) = 0x17;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x30) = 0x24;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x34) = 0x1c;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x38) = 0x12;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x3c) = 0xd;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x40) = 0x27;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00505970
/* public: virtual void * __thiscall TribePriestUnitAIModule::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
TribePriestUnitAIModule::_vector_deleting_destructor_(TribePriestUnitAIModule *this,uint param_1)
{
  ~TribePriestUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribePriestUnitAIModule
// Address: 00505990
/* public: virtual __thiscall TribePriestUnitAIModule::~TribePriestUnitAIModule(void) */

void __thiscall TribePriestUnitAIModule::~TribePriestUnitAIModule(TribePriestUnitAIModule *this)
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

// Function: attackObject
// Address: 005059a0
/* public: virtual int __thiscall TribePriestUnitAIModule::attackObject(int,int) */

int __thiscall
TribePriestUnitAIModule::attackObject(TribePriestUnitAIModule *this,int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  iVar2 = *(int *)this;
  iVar1 = (**(code **)(iVar2 + 0xc4))(param_1);
  if (iVar1 != 0) {
    iVar2 = (**(code **)(iVar2 + 0x6c))(param_1,param_1);
    return iVar2;
  }
  if (*(int *)&this->field_0x28 == -1) {
    iVar1 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
    if (iVar1 != 0) {
      fVar3 = (float10)(**(code **)(**(int **)&this->field_0x4 + 0x10c))(param_1);
      iVar2 = (**(code **)(iVar2 + 0x94))(param_1,(float)fVar3);
      return iVar2;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: retryableOrder
// Address: 00505a10
/* public: virtual int __thiscall TribePriestUnitAIModule::retryableOrder(int) */

int __thiscall TribePriestUnitAIModule::retryableOrder(TribePriestUnitAIModule *this,int param_1)
{
  if ((param_1 != 0x2c0) && (param_1 != 0x2bf)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: canConvert
// Address: 00505a30
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall TribePriestUnitAIModule::canConvert(int) */

int __thiscall TribePriestUnitAIModule::canConvert(TribePriestUnitAIModule *this,int param_1)
{
  short sVar1;
  short sVar2;
  RGE_Static_Object *pRVar3;
  
  if (_DAT_005758d4 <= *(float *)(*(int *)&this->field_0x4 + 0x44)) {
    pRVar3 = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),
                        param_1);
    if (pRVar3 != (RGE_Static_Object *)0x0) {
      sVar1 = pRVar3->master_obj->object_group;
      sVar2 = pRVar3->master_obj->id;
      if ((((((sVar2 != 0x6d) && (sVar1 != 0x1b)) && (sVar2 != 0x9f)) &&
           ((sVar2 != 0x114 && (sVar2 != 0x9e)))) && ((sVar2 != 0xa3 && (sVar1 != 0x1e)))) &&
         (((sVar1 != 0x12 ||
           (_DAT_005758c4 <
            *(float *)(*(int *)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x50) + 0x6c))) &&
          ((sVar1 != 3 ||
           (_DAT_005758c4 <
            *(float *)(*(int *)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x50) + 0x70))))))) {
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: canAttackUnit
// Address: 00505ae0
/* public: virtual int __thiscall TribePriestUnitAIModule::canAttackUnit(class RGE_Static_Object *)
    */

int __thiscall
TribePriestUnitAIModule::canAttackUnit(TribePriestUnitAIModule *this,RGE_Static_Object *param_1)
{
  int iVar1;
  
  if (param_1 != (RGE_Static_Object *)0x0) {
    iVar1 = (**(code **)(*(int *)this + 0xc4))(param_1->id);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: bestUnitToHeal
// Address: 00505b00
/* WARNING: Variable defined which should be unmapped: allyToHealID */
/* protected: virtual int __thiscall TribePriestUnitAIModule::bestUnitToHeal(int,float *) */

int __thiscall
TribePriestUnitAIModule::bestUnitToHeal(TribePriestUnitAIModule *this,int param_1,float *param_2)
{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  int iVar6;
  int allyToHealID;
  int maxLimit;
  float allyNeed;
  int i;
  int a;
  int iStack_c;
  int iStack_8;
  
  (**(code **)(*(int *)this + 0x20))();
  iVar4 = -1;
  maxLimit = -1;
  i = 0;
  allyNeed = 2.8026e-45;
  if (*(short *)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x4a) == 0) {
    allyNeed = 5.60519e-45;
  }
  iStack_c = 1;
  if (allyNeed != 0.0) {
    iStack_8 = 0;
    do {
      a = 0;
      if (0 < *(int *)((int)&DAT_0087d7cc + iStack_8)) {
        piVar1 = (int *)((int)&DAT_0087d7e4 + iStack_8);
        do {
          iVar4 = a * 8;
          if ((((((*(int *)(iVar4 + *piVar1) != *(int *)(*(int *)&this->field_0x4 + 4)) &&
                 (pRVar5 = UnitAIModule::lookupObject
                                     ((UnitAIModule *)this,*(int *)(iVar4 + *piVar1)),
                 pRVar5 != (RGE_Static_Object *)0x0)) && (pRVar5->master_obj->object_group != 3)) &&
               (((pRVar5->hp < (float)(int)pRVar5->master_obj->hp && (pRVar5->object_state < 3)) &&
                ((param_1 != 0 || (*(byte *)(iVar4 + 4 + *piVar1) < 5)))))) &&
              ((*(short *)((*(int **)&this->field_0x4)[3] + 0x4a) != 0 ||
               (*(byte *)(iVar4 + 4 + *piVar1) < 3)))) &&
             (iVar6 = (**(code **)(**(int **)&this->field_0x4 + 0x194))
                                (*(undefined4 *)(iVar4 + *piVar1),0x3f800000,0,0,0xffffffff,
                                 0xffffffff), iVar6 != 0)) {
            fVar3 = (float)*(byte *)(iVar4 + 4 + *piVar1);
            fVar2 = (float)(int)pRVar5->master_obj->hp - pRVar5->hp / fVar3;
            if (((maxLimit == -1) || (fVar2 < (float)i)) &&
               (maxLimit = pRVar5->id, i = (int)fVar2, param_2 != (float *)0x0)) {
              *param_2 = fVar3;
            }
          }
          a = a + 1;
          iVar4 = maxLimit;
        } while (a < *(int *)((int)&DAT_0087d7cc + iStack_8));
      }
      if (iVar4 != -1) {
        return iVar4;
      }
      iStack_c = iStack_c + 1;
      iStack_8 = iStack_8 + 4;
    } while (iStack_c <= (int)allyNeed);
  }
  return -1;
}

// --------------------------------------------------

// Function: bestUnitToConvert
// Address: 00505cc0
/* WARNING: Variable defined which should be unmapped: targetValue */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribePriestUnitAIModule::bestUnitToConvert(float *) */

int __thiscall
TribePriestUnitAIModule::bestUnitToConvert(TribePriestUnitAIModule *this,float *param_1)
{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  long lVar6;
  float targetValue;
  int i;
  int iStack_8;
  
  (**(code **)(*(int *)this + 0x20))();
  lVar6 = -1;
  i = 0;
  iStack_8 = 0;
  if (0 < DAT_0087d7d8) {
    do {
      iVar1 = iStack_8 * 8;
      iVar4 = (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0xc) + 0x18))
                        (*(undefined1 *)(DAT_0087d7f0 + 5 + iVar1));
      if ((((iVar4 != 0) &&
           (pRVar5 = UnitAIModule::lookupObject((UnitAIModule *)this,*(int *)(DAT_0087d7f0 + iVar1))
           , pRVar5 != (RGE_Static_Object *)0x0)) && (pRVar5->object_state < 3)) &&
         (iVar4 = (**(code **)(*(int *)this + 0xc4))(pRVar5->id), iVar4 != 0)) {
        fVar2 = (float)*(byte *)(DAT_0087d7f0 + 4 + iVar1);
        if (fVar2 < _DAT_005758bc) {
          fVar2 = _DAT_005758bc;
        }
        fVar3 = (float)(int)pRVar5->master_obj->hp / fVar2;
        if (((lVar6 == -1) || ((float)i < fVar3)) &&
           (lVar6 = pRVar5->id, i = (int)fVar3, param_1 != (float *)0x0)) {
          *param_1 = fVar2;
        }
      }
      iStack_8 = iStack_8 + 1;
    } while (iStack_8 < DAT_0087d7d8);
  }
  return lVar6;
}

// --------------------------------------------------

// Function: processNotify
// Address: 00505dd0
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* protected: virtual int __thiscall TribePriestUnitAIModule::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribePriestUnitAIModule::processNotify
          (TribePriestUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  uchar uVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  undefined4 uVar5;
  
  switch(param_1->mType) {
  case 0x1f9:
  case 0x1fb:
  case 0x202:
    break;
  case 0x1fc:
    pRVar3 = UnitAIModule::lookupObject((UnitAIModule *)this,*(int *)&this->field_0x34);
    if (pRVar3 != (RGE_Static_Object *)0x0) {
      iVar4 = __ftol();
      iVar2 = __ftol();
      uVar1 = UnitAIModule::visibleStatus
                        ((UnitAIModule *)this,
                         *(RGE_Visible_Map **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x38),
                         iVar2,iVar4);
      if (uVar1 == '\x0f') {
        return 2;
      }
    }
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,uVar5,s_C__msdev_work_age1_x1_taiuaimd_c,0x68f
             );
    }
    iVar4 = *(int *)this;
    (**(code **)(iVar4 + 0x58))(1);
    (**(code **)(iVar4 + 0x1c))(param_1);
  default:
    iVar4 = UnitAIModule::processNotify((UnitAIModule *)this,param_1,param_2);
    return iVar4;
  }
  iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
  if ((iVar4 == 0) && (*(int *)&this->field_0x30 == 0x25c)) {
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,uVar5,s_C__msdev_work_age1_x1_taiuaimd_c,0x63b
             );
    }
    iVar4 = *(int *)this;
    uVar5 = 1;
  }
  else {
    if (*(int *)&this->field_0x30 == 0x25c) {
      iVar4 = *(int *)this;
      iVar2 = (**(code **)(iVar4 + 0xe4))(0);
      if ((iVar2 != -1) && (iVar4 = (**(code **)(iVar4 + 0x6c))(iVar2,1), iVar4 == 1)) {
        return 3;
      }
    }
    else if (*(int *)&this->field_0x30 == 0x25b) {
      iVar4 = *(int *)this;
      iVar2 = (**(code **)(iVar4 + 0xe0))(0,0);
      if ((iVar2 != -1) && (iVar4 = (**(code **)(iVar4 + 0x70))(iVar2,1), iVar4 == 1)) {
        return 3;
      }
    }
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,uVar5,s_C__msdev_work_age1_x1_taiuaimd_c,0x675
             );
    }
    iVar4 = *(int *)this;
    uVar5 = 0;
  }
  (**(code **)(iVar4 + 0x58))(uVar5);
  (**(code **)(iVar4 + 0x1c))(param_1);
  return 2;
}

// --------------------------------------------------

// Function: processIdle
// Address: 00505fd0
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
/* WARNING: Variable defined which should be unmapped: yDiff */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribePriestUnitAIModule::processIdle(int) */

int __thiscall TribePriestUnitAIModule::processIdle(TribePriestUnitAIModule *this,int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  float10 fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float yDiff;
  float xDiff;
  float distanceDiff;
  undefined1 local_4 [4];
  
  iVar2 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
  if (iVar2 != 0) {
    iVar3 = UnitAIModule::processIdle((UnitAIModule *)this,1);
    iVar2 = DAT_0087d7d8;
    if (iVar3 == 6) {
      return 6;
    }
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_taiuaimd_c,0x6ac);
    if ((0 < iVar2) && (iVar2 < iVar3 % (iVar2 + 2))) {
      iVar2 = *(int *)this;
      iVar3 = (**(code **)(iVar2 + 0xe0))(1,local_4);
      if (iVar3 != -1) {
        (**(code **)(iVar2 + 0x70))(iVar3,0);
        return 6;
      }
    }
    iVar2 = *(int *)this;
    iVar3 = (**(code **)(iVar2 + 0x40))(0xffffffff,2,0xffffffff,0xffffffff,0);
    if (iVar3 != -1) {
      pRVar4 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),
                          iVar3);
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        piVar1 = *(int **)&this->field_0x4;
        fVar7 = pRVar4->world_x - (float)piVar1[0xe];
        fVar6 = pRVar4->world_y - (float)piVar1[0xf];
        fVar8 = SQRT(fVar6 * fVar6 + fVar7 * fVar7);
        fVar5 = (float10)(**(code **)(*piVar1 + 0x10c))();
        fVar5 = fVar5 - (float10)fVar8;
        if (fVar5 <= (float10)_DAT_005758c4) {
          return 5;
        }
        iVar3 = *(int *)&this->field_0x4;
        (**(code **)(iVar2 + 0x9c))
                  ((float)(-(((float10)fVar7 / (float10)fVar8) * fVar5) +
                          (float10)*(float *)(iVar3 + 0x38)),
                   (float)(-(((float10)fVar6 / (float10)fVar8) * fVar5) +
                          (float10)*(float *)(iVar3 + 0x3c)),*(undefined4 *)(iVar3 + 0x40),1);
        return 6;
      }
    }
  }
  return 5;
}

// --------------------------------------------------

// Function: processMisc
// Address: 00506140
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribePriestUnitAIModule::processMisc(void) */

int __thiscall TribePriestUnitAIModule::processMisc(TribePriestUnitAIModule *this)
{
  uchar uVar1;
  int iVar2;
  RGE_Action *pRVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar2 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
  if (((iVar2 == 1) && (iVar2 = *(int *)&this->field_0x4, _DAT_005758d4 <= *(float *)(iVar2 + 0x44))
      ) && ((uVar1 = RGE_Action_List::have_action(*(RGE_Action_List **)(iVar2 + 0x184)),
            uVar1 != '\x01' ||
            (pRVar3 = RGE_Action_List::get_action(*(RGE_Action_List **)(iVar2 + 0x184)),
            pRVar3->state != '\a')))) {
    iVar2 = *(int *)this;
    iVar4 = (**(code **)(iVar2 + 0x30))(1,1,0);
    if ((iVar4 != -1) && (*(int *)&this->field_0x34 != iVar4)) {
      if (*(int *)&this->field_0x28 != -1) {
        (**(code **)(iVar2 + 0x10))
                  (*(undefined4 *)(*(int *)&this->field_0x4 + 4),*(int *)&this->field_0x28,
                   *(int *)&this->field_0x34,0xffffffff,*(undefined4 *)&this->field_0x3c,
                   *(undefined4 *)&this->field_0x40,*(undefined4 *)&this->field_0x44,
                   *(undefined4 *)&this->field_0x48,0,0,*(undefined4 *)&this->field_0x2c);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar5 = 0xffffffff;
          }
          else {
            uVar5 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,uVar5,s_C__msdev_work_age1_x1_taiuaimd_c,
                  0x6f8);
        }
        (**(code **)(iVar2 + 0x58))(1);
      }
      iVar2 = (**(code **)(iVar2 + 0x5c))(iVar4,1);
      if (iVar2 == 1) {
        return 10;
      }
    }
  }
  return 9;
}

// --------------------------------------------------

