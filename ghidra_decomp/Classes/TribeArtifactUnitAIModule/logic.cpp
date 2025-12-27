// Class: TribeArtifactUnitAIModule
// Function: TribeArtifactUnitAIModule
// Address: 00507880
/* public: __thiscall TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(class RGE_Static_Object
   *,int) */

TribeArtifactUnitAIModule * __thiscall
TribeArtifactUnitAIModule::TribeArtifactUnitAIModule
          (TribeArtifactUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560d28;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)&this->field_0x128 = 0x13;
  puVar1 = (undefined4 *)operator_new(0x4c);
  *(undefined4 **)&this->field_0x124 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined4 *)(*(int *)&this->field_0x124 + 4) = 4;
    *(undefined4 *)(*(int *)&this->field_0x124 + 8) = 0x1a;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0xc) = 0x18;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x10) = 6;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x14) = 0x23;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x18) = 0x19;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x1c) = 0x11;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x20) = 0xc;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x24) = 0x17;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x28) = 0x24;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x2c) = 0x1c;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x30) = 0x12;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x34) = 0xd;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x38) = 0x16;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x3c) = 0x14;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x40) = 2;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x44) = 0x15;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x48) = 0x27;
  }
  *(undefined4 *)&this->field_0x100 = 5000;
  UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00507a00
/* public: virtual void * __thiscall TribeArtifactUnitAIModule::`vector deleting
   destructor'(unsigned int) */

void * __thiscall
TribeArtifactUnitAIModule::_vector_deleting_destructor_
          (TribeArtifactUnitAIModule *this,uint param_1)
{
  ~TribeArtifactUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeArtifactUnitAIModule
// Address: 00507a20
/* public: virtual __thiscall TribeArtifactUnitAIModule::~TribeArtifactUnitAIModule(void) */

void __thiscall
TribeArtifactUnitAIModule::~TribeArtifactUnitAIModule(TribeArtifactUnitAIModule *this)
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
// Address: 00507a30
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* protected: virtual int __thiscall TribeArtifactUnitAIModule::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribeArtifactUnitAIModule::processNotify
          (TribeArtifactUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  switch(param_1->mType) {
  case 500:
  case 0x1f6:
  case 0x1f7:
  case 0x1f8:
  case 0x1fd:
  case 0x1fe:
  case 0x1ff:
  case 0x200:
  case 0x202:
  case 0x203:
  case 0x20b:
  case 0x20f:
  case 0x259:
  case 0x25a:
  case 0x25b:
  case 0x25c:
  case 0x25d:
  case 0x25e:
  case 0x25f:
  case 0x260:
  case 0x261:
  case 0x262:
  case 0x265:
  case 0x266:
  case 0x267:
  case 0x268:
  case 0x269:
  case 699:
    goto switchD_00507a55_caseD_1f4;
  default:
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar7 = 0xffffffff;
      }
      else {
        uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
      }
      uVar8 = 0xb1f;
LAB_00507d51:
      fprintf(actionFile,s___d_call_stopObject__s__d_,uVar7,s_C__msdev_work_age1_x1_taiuaimd_c,uVar8
             );
    }
    break;
  case 0x1f9:
    iVar3 = *(int *)&this->field_0x28;
    if (iVar3 != -1) {
      if (*(int *)&this->field_0x30 + 100 == iVar3) {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar7 = 0xffffffff;
            uVar8 = 0xac6;
          }
          else {
            uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
            uVar8 = 0xac6;
          }
          goto LAB_00507d51;
        }
        break;
      }
      if (iVar3 != -1) {
        return 2;
      }
    }
    if (*(int *)&this->field_0x30 != param_1->p1) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar7 = 0xffffffff;
        uVar8 = 0xacf;
      }
      else {
        uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
        uVar8 = 0xacf;
      }
      goto LAB_00507d51;
    }
    break;
  case 0x1fa:
    iVar3 = *(int *)&this->field_0x28;
    if (iVar3 != -1) {
      if (*(int *)&this->field_0x30 + 100 == iVar3) {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar7 = 0xffffffff;
            uVar8 = 0xaae;
          }
          else {
            uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
            uVar8 = 0xaae;
          }
          goto LAB_00507d51;
        }
        break;
      }
      if (iVar3 != -1) {
        return 2;
      }
    }
    if (*(int *)&this->field_0x30 != param_1->p1) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar7 = 0xffffffff;
        uVar8 = 0xab7;
      }
      else {
        uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
        uVar8 = 0xab7;
      }
      goto LAB_00507d51;
    }
    break;
  case 0x1fb:
    iVar3 = *(int *)&this->field_0x28;
    if (iVar3 != -1) {
      if (*(int *)&this->field_0x30 + 100 == iVar3) {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
        if (actionFile != (_iobuf *)0x0) {
          if (*(int *)&this->field_0x4 == 0) {
            uVar7 = 0xffffffff;
            uVar8 = 0xade;
          }
          else {
            uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
            uVar8 = 0xade;
          }
          goto LAB_00507d51;
        }
        break;
      }
      if (iVar3 != -1) {
        return 2;
      }
    }
    if (*(int *)&this->field_0x30 != param_1->p1) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar7 = 0xffffffff;
        uVar8 = 0xae7;
      }
      else {
        uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
        uVar8 = 0xae7;
      }
      goto LAB_00507d51;
    }
    break;
  case 0x1fc:
    pRVar2 = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),
                        *(int *)&this->field_0x34);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      iVar3 = __ftol();
      iVar4 = __ftol();
      uVar1 = RGE_Visible_Map::get_visible
                        (*(RGE_Visible_Map **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x38),
                         iVar4,iVar3);
      if (uVar1 == '\x0f') {
        return 2;
      }
    }
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar7 = 0xffffffff;
        uVar8 = 0xa9f;
      }
      else {
        uVar7 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
        uVar8 = 0xa9f;
      }
      goto LAB_00507d51;
    }
    break;
  case 600:
    iVar3 = *(int *)&this->field_0x64;
    iVar4 = param_1->caller;
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        if (*(int *)&this->field_0x6c <= iVar5) break;
        if (*(int *)(*(int *)&this->field_0x60 + iVar5 * 4) == iVar4) goto LAB_00507d13;
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
LAB_00507d13:
    (**(code **)(**(int **)&this->field_0x4 + 0xec))(1);
    return 2;
  }
  iVar3 = *(int *)this;
  (**(code **)(iVar3 + 0x58))(1);
  (**(code **)(iVar3 + 0x1c))(param_1);
switchD_00507a55_caseD_1f4:
  return 2;
}

// --------------------------------------------------

// Function: processIdle
// Address: 00507e90
/* protected: virtual int __thiscall TribeArtifactUnitAIModule::processIdle(int) */

int __thiscall TribeArtifactUnitAIModule::processIdle(TribeArtifactUnitAIModule *this,int param_1)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  iVar1 = (**(code **)(*(int *)this + 0x40))(0xffffffff,0xffffffff,0xffffffff,0xffffffff,0);
  if ((numberDifferentPlayerObjectsVisible < 2) && (iVar1 != -1)) {
    pRVar2 = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),iVar1)
    ;
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      if ((RGE_Player *)(*(int **)&this->field_0x4)[3] != pRVar2->owner) {
        (**(code **)(**(int **)&this->field_0x4 + 0x44))(pRVar2->owner);
        return 6;
      }
    }
  }
  return 5;
}

// --------------------------------------------------

// Function: processMisc
// Address: 00507ef0
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* protected: virtual int __thiscall TribeArtifactUnitAIModule::processMisc(void) */

int __thiscall TribeArtifactUnitAIModule::processMisc(TribeArtifactUnitAIModule *this)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)this;
  iVar2 = (**(code **)(iVar1 + 0xd4))(1);
  if (iVar2 == 6) {
    UnitAIModule::removeCurrentTarget((UnitAIModule *)this);
    if (actionFile != (_iobuf *)0x0) {
      if (*(int *)&this->field_0x4 == 0) {
        uVar3 = 0xffffffff;
      }
      else {
        uVar3 = *(undefined4 *)(*(int *)&this->field_0x4 + 4);
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,uVar3,s_C__msdev_work_age1_x1_taiuaimd_c,0xb60
             );
    }
    (**(code **)(iVar1 + 0x58))(1);
    *(undefined4 *)&this->field_0xf8 = 0;
    return 10;
  }
  return 9;
}

// --------------------------------------------------

