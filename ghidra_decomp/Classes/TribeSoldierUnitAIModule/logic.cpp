// Class: TribeSoldierUnitAIModule
// Function: TribeSoldierUnitAIModule
// Address: 00506fe0
/* public: __thiscall TribeSoldierUnitAIModule::TribeSoldierUnitAIModule(class RGE_Static_Object
   *,int) */

TribeSoldierUnitAIModule * __thiscall
TribeSoldierUnitAIModule::TribeSoldierUnitAIModule
          (TribeSoldierUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560d08;
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
  *(undefined4 *)&this->field_0x100 = 0x5dc;
  UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00507170
/* public: virtual void * __thiscall TribeSoldierUnitAIModule::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TribeSoldierUnitAIModule::_scalar_deleting_destructor_(TribeSoldierUnitAIModule *this,uint param_1)
{
  ~TribeSoldierUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeSoldierUnitAIModule
// Address: 00507190
/* public: virtual __thiscall TribeSoldierUnitAIModule::~TribeSoldierUnitAIModule(void) */

void __thiscall TribeSoldierUnitAIModule::~TribeSoldierUnitAIModule(TribeSoldierUnitAIModule *this)
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

// Function: canAttackUnit
// Address: 005071a0
/* public: virtual int __thiscall TribeSoldierUnitAIModule::canAttackUnit(class RGE_Static_Object *)
    */

int __thiscall
TribeSoldierUnitAIModule::canAttackUnit(TribeSoldierUnitAIModule *this,RGE_Static_Object *param_1)
{
  if (param_1 == (RGE_Static_Object *)0x0) {
    return (int)param_1;
  }
  return (uint)(param_1->master_obj->object_group != 1);
}

// --------------------------------------------------

// Function: canAttackUnitAtNeutrality
// Address: 005071c0
/* public: virtual int __thiscall TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(int) */

int __thiscall
TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(TribeSoldierUnitAIModule *this,int param_1)
{
  if ((((param_1 != 3) && (param_1 != 0x1b)) && (param_1 != 4)) &&
     (((param_1 != 0x15 && (param_1 != 2)) && (param_1 != 0x14)))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: processNotify
// Address: 005071f0
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
/* WARNING: Variable defined which should be unmapped: evasiveMoveDistance */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribeSoldierUnitAIModule::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribeSoldierUnitAIModule::processNotify
          (TribeSoldierUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  short sVar1;
  float fVar2;
  NotifyEvent *pNVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  uint uVar6;
  void *pvVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float evasiveMoveDistance;
  float fStack_8;
  
  pNVar3 = param_1;
  if (param_1->mType == 0x200) {
    iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
    if (((iVar4 != 0) &&
        (fVar11 = (float10)(**(code **)(**(int **)&this->field_0x4 + 0x10c))(),
        (float10)_DAT_005758bc <= fVar11)) &&
       (*(short *)(*(int *)(*(int *)&this->field_0x4 + 8) + 0x14) != 0x1a)) {
      if (*(int *)&this->field_0x30 != 600) {
        return 2;
      }
      pRVar5 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),
                          *(int *)&this->field_0x34);
      if (pRVar5 != (RGE_Static_Object *)0x0) {
        fVar11 = (float10)(**(code **)(**(int **)&this->field_0x4 + 0x10c))();
        fVar12 = RGE_Static_Object::distance_to_object
                           (*(RGE_Static_Object **)&this->field_0x4,pRVar5);
        if (_DAT_005758bc <= (float)fVar11 - fVar12) {
          fVar12 = *(float *)&this->field_0x48;
          fVar14 = 0.0;
          iVar4 = *(int *)&this->field_0x40;
          fVar13 = *(float *)&this->field_0x3c;
          iVar10 = *(int *)this;
          (**(code **)(iVar10 + 0x10))
                    (*(undefined4 *)(*(int *)&this->field_0x4 + 4),700,
                     *(undefined4 *)&this->field_0x34,0xffffffff,fVar13,iVar4,
                     *(undefined4 *)&this->field_0x44,fVar12,0,1,*(undefined4 *)&this->field_0x2c);
          if ((0 < *(int *)&this->field_0x64) && (iVar9 = 0, 0 < *(int *)&this->field_0x64)) {
            do {
              iVar10 = iVar4;
              if (*(int *)&this->field_0x6c + -1 < iVar9) {
                pvVar7 = operator_new(iVar9 * 4 + 4);
                if (pvVar7 != (void *)0x0) {
                  iVar4 = 0;
                  if (0 < *(int *)&this->field_0x6c) {
                    do {
                      if (iVar9 + 1 <= iVar4) break;
                      iVar4 = iVar4 + 1;
                      *(undefined4 *)((int)pvVar7 + iVar4 * 4 + -4) =
                           *(undefined4 *)(*(int *)&this->field_0x60 + -4 + iVar4 * 4);
                    } while (iVar4 < *(int *)&this->field_0x6c);
                  }
                  operator_delete(*(void **)&this->field_0x60);
                  *(void **)&this->field_0x60 = pvVar7;
                  *(int *)&this->field_0x6c = iVar9 + 1;
                }
              }
              if (*(int *)(*(int *)&this->field_0x60 + iVar9 * 4) != *(int *)&this->field_0x34) {
                if (*(int *)&this->field_0x6c + -1 < iVar9) {
                  pvVar7 = operator_new(iVar9 * 4 + 4);
                  if (pvVar7 != (void *)0x0) {
                    iVar4 = 0;
                    if (0 < *(int *)&this->field_0x6c) {
                      do {
                        if (iVar9 + 1 <= iVar4) break;
                        iVar4 = iVar4 + 1;
                        *(undefined4 *)((int)pvVar7 + iVar4 * 4 + -4) =
                             *(undefined4 *)(*(int *)&this->field_0x60 + -4 + iVar4 * 4);
                      } while (iVar4 < *(int *)&this->field_0x6c);
                    }
                    operator_delete(*(void **)&this->field_0x60);
                    *(void **)&this->field_0x60 = pvVar7;
                    *(int *)&this->field_0x6c = iVar9 + 1;
                  }
                }
                pRVar5 = RGE_Game_World::object
                                   (*(RGE_Game_World **)
                                     (*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),
                                    *(int *)(*(int *)&this->field_0x60 + iVar9 * 4));
                if (pRVar5 != (RGE_Static_Object *)0x0) {
                  fVar14 = (pRVar5->world_x - *(float *)(*(int *)&this->field_0x4 + 0x38)) + fVar14;
                  fVar12 = (pRVar5->world_y - *(float *)(*(int *)&this->field_0x4 + 0x3c)) + fVar12;
                }
              }
              iVar9 = iVar9 + 1;
              iVar4 = iVar10;
            } while (iVar9 < *(int *)&this->field_0x64);
          }
          iVar4 = *(int *)&this->field_0x4;
          fVar2 = SQRT(fVar12 * fVar12 + fVar14 * fVar14);
          iVar4 = (**(code **)(iVar10 + 0xa0))
                            (-((fVar14 / fVar2) * fVar13) + *(float *)(iVar4 + 0x38),
                             -((fVar12 / fVar2) * fVar13) + *(float *)(iVar4 + 0x3c),
                             *(undefined4 *)(iVar4 + 0x40),0,1);
          if (iVar4 != 1) {
            return 2;
          }
          return 3;
        }
      }
    }
  }
  else if (((param_1->mType == 0x20f) &&
           (iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc)),
           iVar4 != 0)) &&
          ((pRVar5 = RGE_Game_World::object
                               (*(RGE_Game_World **)
                                 (*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),param_1->caller),
           pRVar5 != (RGE_Static_Object *)0x0 &&
           (((sVar1 = pRVar5->master_obj->id, sVar1 == 0x23 || (sVar1 == 0x24)) &&
            (*(int *)&this->field_0x30 != -1)))))) {
    if (*(int *)&this->field_0x28 != -1) {
      (**(code **)(*(int *)this + 0x10))
                (*(undefined4 *)(*(int *)&this->field_0x4 + 4),*(int *)&this->field_0x28,
                 *(undefined4 *)&this->field_0x34,0xffffffff,*(undefined4 *)&this->field_0x3c,
                 *(undefined4 *)&this->field_0x40,*(undefined4 *)&this->field_0x44,
                 *(undefined4 *)&this->field_0x48,0,0,*(undefined4 *)&this->field_0x2c);
    }
    iVar4 = *(int *)&this->field_0x4;
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_taiuaimd_c,0x97c);
    uVar8 = (int)uVar6 >> 0x1f;
    fStack_8 = (*(float *)(iVar4 + 0x38) - _DAT_005758dc) +
               (float)(int)(((uVar6 ^ uVar8) - uVar8 & 7 ^ uVar8) - uVar8);
    if (fStack_8 == *(float *)(iVar4 + 0x38)) {
      fVar12 = _DAT_005758e4;
      if (_DAT_005758e0 < fStack_8) {
        fVar12 = _DAT_005758c0;
      }
      fStack_8 = fStack_8 - fVar12;
    }
    iVar4 = *(int *)&this->field_0x4;
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_taiuaimd_c,0x983);
    uVar8 = (int)uVar6 >> 0x1f;
    param_1 = (NotifyEvent *)
              ((*(float *)(iVar4 + 0x3c) - _DAT_005758dc) +
              (float)(int)(((uVar6 ^ uVar8) - uVar8 & 7 ^ uVar8) - uVar8));
    if ((float)param_1 == *(float *)(iVar4 + 0x3c)) {
      fVar12 = _DAT_005758e4;
      if (_DAT_005758e0 < (float)param_1) {
        fVar12 = _DAT_005758c0;
      }
      param_1 = (NotifyEvent *)((float)param_1 - fVar12);
    }
    iVar4 = (**(code **)(*(int *)this + 0xa0))(fStack_8,param_1,*(undefined4 *)(iVar4 + 0x40),1,1);
    if (iVar4 == 1) {
      taskedThisUpdate = iVar4;
      return 3;
    }
  }
  iVar4 = UnitAIModule::processNotify((UnitAIModule *)this,pNVar3,param_2);
  return iVar4;
}

// --------------------------------------------------

// Function: processIdle
// Address: 00507640
/* WARNING: Variable defined which should be unmapped: xDiff */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribeSoldierUnitAIModule::processIdle(int) */

int __thiscall TribeSoldierUnitAIModule::processIdle(TribeSoldierUnitAIModule *this,int param_1)
{
  short sVar1;
  RGE_Player *this_00;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  RGE_Static_Object *pRVar7;
  float10 fVar8;
  float xDiff;
  
  if ((param_1 == 1) && (iVar5 = (**(code **)(*(int *)this + 0xdc))(), iVar5 == 8)) {
    return 6;
  }
  this_00 = *(RGE_Player **)(*(int *)&this->field_0x4 + 0xc);
  if (((this_00->id != 0) &&
      ((iVar5 = RGE_Player::computerPlayer(this_00), iVar5 != 0 ||
       (*(short *)(*(int *)(*(int *)&this->field_0x4 + 8) + 0x10) != 299)))) &&
     ((*(int *)&this->field_0x28 != 0x2d5 ||
      (((sVar1 = *(short *)(*(int *)(*(int *)&this->field_0x4 + 8) + 0x10), sVar1 != 0x23 &&
        (sVar1 != 0x24)) && (sVar1 != 0xfa)))))) {
    iVar5 = *(int *)this;
    iVar6 = (**(code **)(iVar5 + 0x30))(1,0,0);
    if ((iVar6 != -1) && (iVar6 = (**(code **)(iVar5 + 0x5c))(iVar6,1), iVar6 == 1)) {
      return 6;
    }
    iVar6 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
    if ((iVar6 != 0) &&
       (iVar6 = RGE_Static_Object::inGroup(*(RGE_Static_Object **)&this->field_0x4), iVar6 != 1)) {
      RGE_Game_World::difficultyLevel
                (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c));
      iVar6 = RGE_Base_Game::scenarioGame(rge_base_game);
      if ((iVar6 == 1) &&
         ((iVar6 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar6 == 1 &&
          (iVar6 = (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0xc) + 0x3c))(0x8f),
          iVar6 == 0)))) {
        return 5;
      }
      iVar6 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar6 == 1) &&
         (iVar6 = (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0xc) + 0x3c))(0x8f), iVar6 == 0
         )) {
        return 5;
      }
      if ((((*(int *)&this->field_0x28 != 0x2bd) && (*(int *)&this->field_0x28 != 0x2d5)) &&
          (iVar6 = (**(code **)(iVar5 + 0x40))(0xffffffff,0xffffffff,0xffffffff,0xffffffff,0),
          iVar6 != -1)) &&
         (pRVar7 = RGE_Game_World::object
                             (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),
                              iVar6), pRVar7 != (RGE_Static_Object *)0x0)) {
        fVar8 = (float10)(**(code **)(**(int **)&this->field_0x4 + 0xfc))();
        iVar6 = *(int *)&this->field_0x4;
        fVar4 = pRVar7->world_x - *(float *)(iVar6 + 0x38);
        fVar2 = pRVar7->world_y - *(float *)(iVar6 + 0x3c);
        fVar3 = SQRT(fVar2 * fVar2 + fVar4 * fVar4);
        (**(code **)(iVar5 + 0x9c))
                  (-((fVar4 / fVar3) * (float)(fVar8 * (float10)_DAT_005758b0)) +
                   *(float *)(iVar6 + 0x38),
                   -((fVar2 / fVar3) * (float)(fVar8 * (float10)_DAT_005758b0)) +
                   *(float *)(iVar6 + 0x3c),*(undefined4 *)(iVar6 + 0x40),1);
        return 6;
      }
    }
  }
  return 5;
}

// --------------------------------------------------

