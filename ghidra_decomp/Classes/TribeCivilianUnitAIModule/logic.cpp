// Class: TribeCivilianUnitAIModule
// Function: TribeCivilianUnitAIModule
// Address: 00504b60
/* public: __thiscall TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(class RGE_Static_Object
   *,int) */

TribeCivilianUnitAIModule * __thiscall
TribeCivilianUnitAIModule::TribeCivilianUnitAIModule
          (TribeCivilianUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560c68;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)&this->field_0x128 = 0xb;
  puVar1 = (undefined4 *)operator_new(0x2c);
  *(undefined4 **)&this->field_0x124 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 3;
    *(undefined4 *)(*(int *)&this->field_0x124 + 4) = 7;
    *(undefined4 *)(*(int *)&this->field_0x124 + 8) = 8;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0xc) = 9;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x10) = 10;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x14) = 0xf;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x18) = 0x11;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x1c) = 0x12;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x20) = 0x20;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x24) = 0x21;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x28) = 0x1b;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00504c60
/* public: virtual void * __thiscall TribeCivilianUnitAIModule::`scalar deleting
   destructor'(unsigned int) */

void * __thiscall
TribeCivilianUnitAIModule::_scalar_deleting_destructor_
          (TribeCivilianUnitAIModule *this,uint param_1)
{
  ~TribeCivilianUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeCivilianUnitAIModule
// Address: 00504c80
/* public: virtual __thiscall TribeCivilianUnitAIModule::~TribeCivilianUnitAIModule(void) */

void __thiscall
TribeCivilianUnitAIModule::~TribeCivilianUnitAIModule(TribeCivilianUnitAIModule *this)
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
// Address: 00504c90
/* public: virtual int __thiscall TribeCivilianUnitAIModule::importantWhenDead(int) */

int __thiscall
TribeCivilianUnitAIModule::importantWhenDead(TribeCivilianUnitAIModule *this,int param_1)
{
  if ((((param_1 != 7) && (param_1 != 9)) && (param_1 != 10)) &&
     (((param_1 != 0xf && (param_1 != 8)) && (param_1 != 0x20)))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: attackObject
// Address: 00504cc0
/* public: virtual int __thiscall TribeCivilianUnitAIModule::attackObject(int,int) */

int __thiscall
TribeCivilianUnitAIModule::attackObject(TribeCivilianUnitAIModule *this,int param_1,int param_2)
{
  short sVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  
  pRVar2 = RGE_Game_World::object
                     (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),param_1)
  ;
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  sVar1 = pRVar2->master_obj->object_group;
  if (((sVar1 != 9) && (sVar1 != 10)) && (sVar1 != 0xf)) {
    iVar3 = UnitAIModule::attackObject((UnitAIModule *)this,param_1,param_2);
    return iVar3;
  }
  iVar3 = (**(code **)(*(int *)this + 100))(param_1,param_2);
  return iVar3;
}

// --------------------------------------------------

// Function: canAttackUnit
// Address: 00504d20
/* public: virtual int __thiscall TribeCivilianUnitAIModule::canAttackUnit(class RGE_Static_Object
   *) */

int __thiscall
TribeCivilianUnitAIModule::canAttackUnit(TribeCivilianUnitAIModule *this,RGE_Static_Object *param_1)
{
  if (param_1 == (RGE_Static_Object *)0x0) {
    return (int)param_1;
  }
  return (uint)(param_1->master_obj->object_group != 1);
}

// --------------------------------------------------

// Function: canAttackUnitAtNeutrality
// Address: 00504d40
/* public: virtual int __thiscall TribeCivilianUnitAIModule::canAttackUnitAtNeutrality(int) */

int __thiscall
TribeCivilianUnitAIModule::canAttackUnitAtNeutrality(TribeCivilianUnitAIModule *this,int param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: retryableOrder
// Address: 00504d50
/* public: virtual int __thiscall TribeCivilianUnitAIModule::retryableOrder(int) */

int __thiscall
TribeCivilianUnitAIModule::retryableOrder(TribeCivilianUnitAIModule *this,int param_1)
{
  if (((param_1 != 0x2c1) && (param_1 != 0x2c5)) && (param_1 != 0x2c9)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: convertToLOSResourceType
// Address: 00504d80
/* public: virtual int __thiscall TribeCivilianUnitAIModule::convertToLOSResourceType(int) */

int __thiscall
TribeCivilianUnitAIModule::convertToLOSResourceType(TribeCivilianUnitAIModule *this,int param_1)
{
  switch(param_1) {
  case 5:
  case 0x1f:
  case 0x21:
    return 2;
  default:
    return -1;
  case 7:
    return 1;
  case 8:
    return 3;
  case 0xf:
    return 0;
  case 0x20:
    return 4;
  }
}

// --------------------------------------------------

// Function: processNotify
// Address: 00504e10
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* WARNING: Variable defined which should be unmapped: tileX */
/* WARNING: Removing unreachable block (ram,0x00504ef5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribeCivilianUnitAIModule::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribeCivilianUnitAIModule::processNotify
          (TribeCivilianUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  code *pcVar1;
  char cVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int unaff_EBX;
  ulong unaff_ESI;
  float10 fVar9;
  float fVar10;
  int unaff_retaddr;
  undefined4 uVar11;
  int tileX;
  TribeCivilianUnitAIModule *local_4;
  
  local_4 = this;
  switch(param_1->mType) {
  case 500:
    goto switchD_00504e34_caseD_1f4;
  default:
    iVar8 = UnitAIModule::processNotify((UnitAIModule *)this,param_1,param_2);
    return iVar8;
  case 0x1f9:
    if (*(int *)&this->field_0x30 != param_1->p1) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar6 = 0xffffffff;
      }
      else {
        uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,uVar6,s_C__msdev_work_age1_x1_taiuaimd_c,0x3b9
             );
      iVar8 = *(int *)this;
      (**(code **)(iVar8 + 0x58))(1);
      (**(code **)(iVar8 + 0x1c))(param_1);
      return 2;
    }
    break;
  case 0x1fa:
    if (*(int *)&this->field_0x30 != param_1->p1) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar6 = 0xffffffff;
      }
      else {
        uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,uVar6,s_C__msdev_work_age1_x1_taiuaimd_c,0x3aa
             );
      iVar8 = *(int *)this;
      (**(code **)(iVar8 + 0x58))(1);
      (**(code **)(iVar8 + 0x1c))(param_1);
      return 2;
    }
    break;
  case 0x1fb:
  case 0x202:
    iVar8 = *(int *)&this->field_0x30;
    if (iVar8 == 0x265) {
      iVar7 = *(int *)&this->field_0x38;
      if ((iVar7 == -1) && (iVar7 = *(int *)&this->field_0x5c, iVar7 == -1)) {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar6 = 0xffffffff;
          }
          else {
            uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,uVar6,s_C__msdev_work_age1_x1_taiuaimd_c,
                  0x3d3);
        }
        iVar8 = *(int *)this;
        (**(code **)(iVar8 + 0x58))(1);
        (**(code **)(iVar8 + 0x1c))(unaff_retaddr);
        return 2;
      }
      iVar8 = *(int *)this;
      iVar4 = (**(code **)(iVar8 + 0xc0))(iVar7);
      if (iVar4 == -1) {
        iVar7 = (**(code **)(iVar8 + 0x40))(iVar7,0xffffffff,0xffffffff,0xffffffff,0);
      }
      else {
        iVar7 = (**(code **)(iVar8 + 0x44))(iVar4);
      }
      if (iVar7 == -1) {
        iVar7 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
        if (iVar7 != 1) goto LAB_00505747;
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar6 = 0xffffffff;
            uVar11 = 0x40f;
          }
          else {
            uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
            uVar11 = 0x40f;
          }
LAB_00505722:
          fprintf(actionFile,s___d_call_stopObject__s__d_,uVar6,s_C__msdev_work_age1_x1_taiuaimd_c,
                  uVar11);
        }
LAB_00505736:
        (**(code **)(iVar8 + 0x58))(1);
      }
      else {
        iVar7 = (**(code **)(iVar8 + 100))(iVar7,1);
        if (iVar7 == 1) {
          return 3;
        }
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar6 = 0xffffffff;
          }
          else {
            uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,uVar6,s_C__msdev_work_age1_x1_taiuaimd_c,
                  0x3f6);
        }
        (**(code **)(iVar8 + 0x58))(1);
      }
LAB_00505742:
      (**(code **)(iVar8 + 0x1c))(unaff_EBX);
    }
    else if (iVar8 == 0x261) {
      iVar7 = *(int *)&this->field_0x38;
      if ((iVar7 == -1) && (iVar7 = *(int *)&this->field_0x5c, iVar7 == -1)) {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar6 = 0xffffffff;
          }
          else {
            uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,uVar6,s_C__msdev_work_age1_x1_taiuaimd_c,
                  0x421);
        }
        iVar8 = *(int *)this;
        (**(code **)(iVar8 + 0x58))(1);
        (**(code **)(iVar8 + 0x1c))(unaff_retaddr);
        return 2;
      }
      iVar8 = *(int *)this;
      iVar4 = (**(code **)(iVar8 + 0xc0))(iVar7);
      if (iVar4 == -1) {
        if (*(int *)(unaff_retaddr + 0x10) == 0x32) {
          uVar11 = 0x32;
          uVar6 = 2;
        }
        else {
          uVar11 = 0xffffffff;
          uVar6 = 0xffffffff;
        }
        iVar7 = (**(code **)(iVar8 + 0x40))(iVar7,0xffffffff,uVar6,uVar11,0);
      }
      else {
        iVar7 = (**(code **)(iVar8 + 0x44))(iVar4,0);
      }
      if (iVar7 != -1) {
        iVar7 = (**(code **)(iVar8 + 0x68))(iVar7,1);
        if (iVar7 == 1) {
          return 3;
        }
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar6 = 0xffffffff;
            uVar11 = 0x446;
          }
          else {
            uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
            uVar11 = 0x446;
          }
          goto LAB_00505722;
        }
        goto LAB_00505736;
      }
      iVar7 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
      if (iVar7 == 1) {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile == (_iobuf *)0x0) {
LAB_005056e2:
          (**(code **)(iVar8 + 0x58))(1);
        }
        else {
          if (*(int *)&this->field_0x4 == 0) {
            uVar6 = 0xffffffff;
          }
          else {
            uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
          }
                    /* language.dll match for 0x453: "Saving game..." */
          fprintf(actionFile,s___d_call_stopObject__s__d_,uVar6,s_C__msdev_work_age1_x1_taiuaimd_c,
                  0x453);
          (**(code **)(iVar8 + 0x58))(1);
        }
        goto LAB_00505742;
      }
      if (param_1->p2 == 0x32) {
        iVar7 = *(int *)&this->field_0x4;
        fVar10 = _DAT_005758d0;
        if (_DAT_005758c8 < *(float *)(iVar7 + 0x38)) {
          fVar10 = _DAT_005758cc;
        }
        local_4 = (TribeCivilianUnitAIModule *)(*(float *)(iVar7 + 0x38) - fVar10);
        fVar10 = _DAT_005758d0;
        if (_DAT_005758c8 < *(float *)(iVar7 + 0x3c)) {
          fVar10 = _DAT_005758cc;
        }
        param_2 = (ulong)(*(float *)(iVar7 + 0x3c) - fVar10);
        (**(code **)(iVar8 + 0x9c))(local_4,param_2,*(undefined4 *)(iVar7 + 0x40),1);
      }
    }
    else if (iVar8 == 0x25a) {
      iVar8 = *(int *)this;
      pcVar1 = *(code **)(iVar8 + 0x40);
      iVar7 = (*pcVar1)(*(undefined4 *)&this->field_0x38,3,0,0xffffffff,0);
      if (iVar7 == -1) {
        if (*(int *)&this->field_0x38 == 0x1b) {
          uVar6 = 3;
        }
        else {
          uVar6 = 0x1b;
        }
        iVar7 = (*pcVar1)(uVar6,3,0,0xffffffff,0);
        if (iVar7 != -1) goto LAB_005055d9;
      }
      else {
LAB_005055d9:
        iVar4 = (**(code **)(**(int **)&this->field_0x4 + 0x194))
                          (iVar7,0x3f800000,0,0,0xffffffff,0xffffffff);
        if (iVar4 == 1) {
          iVar8 = (**(code **)(iVar8 + 0x78))(iVar7,1);
          if (iVar8 == 1) {
            return 3;
          }
          goto LAB_00505747;
        }
      }
      pRVar3 = UnitAIModule::lookupObject((UnitAIModule *)this,*(int *)&this->field_0x34);
      if ((pRVar3 == (RGE_Static_Object *)0x0) ||
         (fVar10 = RGE_Static_Object::distance_to_object
                             (*(RGE_Static_Object **)&this->field_0x4,pRVar3),
         _DAT_005758bc < fVar10)) {
        (**(code **)(iVar8 + 0x90))
                  (*(undefined4 *)&this->field_0x3c,*(undefined4 *)&this->field_0x40,
                   *(undefined4 *)&this->field_0x44,0x3f800000,1);
      }
    }
    else if (iVar8 == 0x25d) {
      iVar8 = *(int *)this;
      iVar7 = (**(code **)(iVar8 + 0x48))(&local_4,&param_2,1);
      if (iVar7 == 1) {
        UnitAIModule::addToWaypointQueue((UnitAIModule *)this,(int)local_4,param_2);
        iVar7 = (**(code **)(iVar8 + 0x80))(local_4,param_2,1);
        if (iVar7 != 0) {
          return 3;
        }
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar6 = 0xffffffff;
          }
          else {
            uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
          }
                    /* language.dll match for 0x4b4: "Waiting" */
          fprintf(actionFile,s___d_call_stopObject__s__d_,uVar6,s_C__msdev_work_age1_x1_taiuaimd_c,
                  0x4b4);
        }
        goto LAB_005056e2;
      }
      UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
      if (actionFile != (_iobuf *)0x0) {
        if (*(int *)&this->field_0x4 == 0) {
          uVar6 = 0xffffffff;
        }
        else {
          uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
        }
                    /* language.dll match for 0x4c3: "Creating multiplayer game...\\n\\n\\n\\nPlease
                       press ESC if the game is not\\ncreated within 15 seconds.\\n\\nAlso, make
                       sure you are connected to the Internet\\nbefore starting Age of Empires." */
        uVar11 = 0x4c3;
        goto LAB_00505722;
      }
      goto LAB_00505736;
    }
LAB_00505747:
    if (param_1->mType == 0x202) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar6 = 0xffffffff;
      }
      else {
        uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,uVar6,s_C__msdev_work_age1_x1_taiuaimd_c,0x4cc
             );
    }
    break;
  case 0x20f:
    iVar8 = RGE_Game_World::difficultyLevel
                      (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c));
    if (2 < iVar8) {
      return 2;
    }
switchD_00504e34_caseD_1f4:
    if (param_1->p2 < 1) {
      uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
      (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0xc) + 0xe8))
                (uVar6,uVar6,0x209,param_1->caller,0,0);
      UnitAIModule::purgeNotifyQueue((UnitAIModule *)this,unaff_ESI);
      return 4;
    }
    pRVar3 = UnitAIModule::lookupObject((UnitAIModule *)this,param_1->caller);
    param_2 = (ulong)pRVar3;
    local_4 = (TribeCivilianUnitAIModule *)
              UnitAIModule::lookupObject((UnitAIModule *)this,*(int *)&this->field_0x34);
    if (pRVar3 == (RGE_Static_Object *)0x0) {
      return 2;
    }
    iVar8 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
    if (iVar8 == 1) {
      if ((pRVar3->owner->id == 0) && (pRVar3->id == *(int *)&this->field_0x34)) goto LAB_00504f1d;
    }
    else if (*(int *)&this->field_0x64 != 0) goto LAB_00504f1d;
    uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
    (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0xc) + 0xe8))
              (uVar6,uVar6,0x201,param_1->caller,0,0);
LAB_00504f1d:
    iVar8 = 0;
    if (0 < *(int *)&this->field_0x64) {
      do {
        if (*(int *)&this->field_0x6c <= iVar8) break;
        if (*(int *)(*(int *)&this->field_0x60 + iVar8 * 4) == param_1->caller) goto LAB_00504f5e;
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)&this->field_0x64);
    }
    iVar8 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x4 + 0xc));
    if ((iVar8 == 0) && (*(int *)&this->field_0x34 != param_1->caller)) {
      UnitAIModule::askForHelp((UnitAIModule *)this,param_1->caller);
    }
LAB_00504f5e:
    iVar8 = *(int *)&this->field_0x64;
    iVar7 = param_1->caller;
    iVar4 = 0;
    if (0 < iVar8) {
      do {
        if (*(int *)&this->field_0x6c <= iVar4) break;
        if (*(int *)(*(int *)&this->field_0x60 + iVar4 * 4) == iVar7) goto LAB_00504fe4;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar8);
    }
    if (*(int *)&this->field_0x6c + -1 < iVar8) {
      iVar8 = iVar8 + 1;
      pvVar5 = operator_new(iVar8 * 4);
      if (pvVar5 != (void *)0x0) {
        iVar4 = 0;
        if (0 < *(int *)&this->field_0x6c) {
          do {
            if (iVar8 <= iVar4) break;
            iVar4 = iVar4 + 1;
            *(undefined4 *)((int)pvVar5 + iVar4 * 4 + -4) =
                 *(undefined4 *)(*(int *)&this->field_0x60 + -4 + iVar4 * 4);
          } while (iVar4 < *(int *)&this->field_0x6c);
        }
        operator_delete(*(void **)&this->field_0x60);
        *(void **)&this->field_0x60 = pvVar5;
        *(int *)&this->field_0x6c = iVar8;
      }
    }
    *(int *)(*(int *)&this->field_0x60 + *(int *)&this->field_0x64 * 4) = iVar7;
    *(int *)&this->field_0x64 = *(int *)&this->field_0x64 + 1;
LAB_00504fe4:
    (**(code **)(**(int **)&this->field_0x4 + 0xec))(1);
    fVar9 = (float10)(**(code **)(**(int **)&this->field_0x4 + 0xf4))();
    cVar2 = (**(code **)(**(int **)&this->field_0x4 + 0x134))();
    iVar8 = *(int *)&this->field_0x28;
    if ((iVar8 == 0x2c6) && (_DAT_005758c4 < (float)fVar9)) {
      return 2;
    }
    if (iVar8 == 700) {
      return 2;
    }
    if ((((iVar8 == 0x2c9) && (cVar2 == '\f')) && (unaff_EBX != 0)) &&
       ((*(short *)(*(int *)(unaff_EBX + 8) + 0x14) == 10 && (*(short *)(param_1->p1 + 0x4a) == 0)))
       ) {
      return 2;
    }
    if (iVar8 == 0x2ce) {
      return 2;
    }
    if (*(short *)(param_1->p1 + 0x4a) != 0) {
      if ((*(int *)&this->field_0x30 == 0x262) && ((float)fVar9 != _DAT_005758c4)) {
        return 3;
      }
      iVar7 = *(int *)this;
      (**(code **)(iVar7 + 0x10))
                (*(undefined4 *)(*(int *)&this->field_0x4 + 4),iVar8,
                 *(undefined4 *)&this->field_0x34,0xffffffff,*(undefined4 *)&this->field_0x3c,
                 *(undefined4 *)&this->field_0x40,*(undefined4 *)&this->field_0x44,
                 *(undefined4 *)&this->field_0x48,0,0,*(undefined4 *)&this->field_0x2c);
      if (actionFile != (_iobuf *)0x0) {
        if (*(int *)&this->field_0x4 == 0) {
          uVar6 = 0xffffffff;
        }
        else {
          uVar6 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,uVar6,s_C__msdev_work_age1_x1_taiuaimd_c,
                0x39a);
      }
      (**(code **)(iVar7 + 0x58))(1);
      (**(code **)(iVar7 + 0xa4))(1);
      return 3;
    }
    if (iVar8 != -1) {
      iVar7 = *(int *)this;
      (**(code **)(iVar7 + 0x10))
                (*(undefined4 *)(*(int *)&this->field_0x4 + 4),iVar8,
                 *(undefined4 *)&this->field_0x34,0xffffffff,*(undefined4 *)&this->field_0x3c,
                 *(undefined4 *)&this->field_0x40,*(undefined4 *)&this->field_0x44,
                 *(undefined4 *)&this->field_0x48,0,0,*(undefined4 *)&this->field_0x2c);
      *(undefined4 *)&this->field_0x28 = 700;
      *(undefined4 *)&this->field_0x2c = 100;
      (**(code **)(iVar7 + 0x5c))(param_1->caller,1);
      this->field_0x130 = 1;
      return 3;
    }
    (**(code **)(*(int *)this + 0x5c))(param_1->caller,1);
    return 3;
  }
  iVar8 = *(int *)this;
  (**(code **)(iVar8 + 0x58))(1);
  (**(code **)(iVar8 + 0x1c))(param_1);
  return 2;
}

// --------------------------------------------------

// Function: processIdle
// Address: 00505800
/* protected: virtual int __thiscall TribeCivilianUnitAIModule::processIdle(int) */

int __thiscall TribeCivilianUnitAIModule::processIdle(TribeCivilianUnitAIModule *this,int param_1)
{
  return 5;
}

// --------------------------------------------------

// Function: processMisc
// Address: 00505810
/* protected: virtual int __thiscall TribeCivilianUnitAIModule::processMisc(void) */

int __thiscall TribeCivilianUnitAIModule::processMisc(TribeCivilianUnitAIModule *this)
{
  return 9;
}

// --------------------------------------------------

