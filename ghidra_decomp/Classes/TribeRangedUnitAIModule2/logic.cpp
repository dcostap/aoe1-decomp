// Class: TribeRangedUnitAIModule2
// Function: TribeRangedUnitAIModule2
// Address: 00504880
/* public: __thiscall TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(class RGE_Static_Object
   *,int) */

TribeRangedUnitAIModule2 * __thiscall
TribeRangedUnitAIModule2::TribeRangedUnitAIModule2
          (TribeRangedUnitAIModule2 *this,RGE_Static_Object *param_1,int param_2)
{
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 005048a0
/* public: virtual void * __thiscall TribeRangedUnitAIModule2::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
TribeRangedUnitAIModule2::_vector_deleting_destructor_(TribeRangedUnitAIModule2 *this,uint param_1)
{
  ~TribeRangedUnitAIModule2(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeRangedUnitAIModule2
// Address: 005048c0
/* public: virtual __thiscall TribeRangedUnitAIModule2::~TribeRangedUnitAIModule2(void) */

void __thiscall TribeRangedUnitAIModule2::~TribeRangedUnitAIModule2(TribeRangedUnitAIModule2 *this)
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
// Address: 005048d0
/* WARNING: Variable defined which should be unmapped: evasiveMoveDistance */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribeRangedUnitAIModule2::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribeRangedUnitAIModule2::processNotify
          (TribeRangedUnitAIModule2 *this,NotifyEvent *param_1,ulong param_2)
{
  int *piVar1;
  float fVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float evasiveMoveDistance;
  
  if (param_1->mType != 0x200) {
    iVar3 = UnitAIModule::processNotify((UnitAIModule *)this,param_1,param_2);
    return iVar3;
  }
  if (((*(int *)&this->field_0x30 != 600) ||
      (pRVar4 = RGE_Game_World::object
                          (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),
                           *(int *)&this->field_0x34), pRVar4 == (RGE_Static_Object *)0x0)) ||
     (fVar8 = (float10)(**(code **)(pRVar4->_padding_ + 0xf4))(), fVar8 == (float10)_DAT_005758c4))
{
    return 2;
  }
  iVar3 = *(int *)&this->field_0x40;
  iVar7 = *(int *)this;
  (**(code **)(iVar7 + 0x10))
            (*(undefined4 *)(*(int *)&this->field_0x4 + 4),700,*(undefined4 *)&this->field_0x34,
             0xffffffff,*(undefined4 *)&this->field_0x3c,iVar3,*(undefined4 *)&this->field_0x44,
             *(undefined4 *)&this->field_0x48,0,1,*(undefined4 *)&this->field_0x2c);
  piVar1 = *(int **)&this->field_0x4;
  fVar8 = (float10)(**(code **)(*piVar1 + 0x100))();
  fVar9 = (float)fVar8;
  fVar8 = (float10)(**(code **)(*piVar1 + 0xfc))();
  fVar9 = (float)(fVar8 * (float10)fVar9 * (float10)_DAT_005758b0);
  fVar11 = pRVar4->world_x - *(float *)(*(int *)&this->field_0x4 + 0x38);
  fVar10 = pRVar4->world_y - *(float *)(*(int *)&this->field_0x4 + 0x3c);
  if ((0 < *(int *)&this->field_0x64) && (iVar6 = 0, iVar7 = iVar3, 0 < *(int *)&this->field_0x64))
{
    do {
      if (*(int *)&this->field_0x6c + -1 < iVar6) {
        pvVar5 = operator_new(iVar6 * 4 + 4);
        if (pvVar5 != (void *)0x0) {
          iVar3 = 0;
          if (0 < *(int *)&this->field_0x6c) {
            do {
              if (iVar6 + 1 <= iVar3) break;
              iVar3 = iVar3 + 1;
              *(undefined4 *)((int)pvVar5 + iVar3 * 4 + -4) =
                   *(undefined4 *)(*(int *)&this->field_0x60 + -4 + iVar3 * 4);
            } while (iVar3 < *(int *)&this->field_0x6c);
          }
          operator_delete(*(void **)&this->field_0x60);
          *(void **)&this->field_0x60 = pvVar5;
          *(int *)&this->field_0x6c = iVar6 + 1;
        }
      }
      if (*(int *)(*(int *)&this->field_0x60 + iVar6 * 4) != *(int *)&this->field_0x34) {
        if (*(int *)&this->field_0x6c + -1 < iVar6) {
          pvVar5 = operator_new(iVar6 * 4 + 4);
          if (pvVar5 != (void *)0x0) {
            iVar3 = 0;
            if (0 < *(int *)&this->field_0x6c) {
              do {
                if (iVar6 + 1 <= iVar3) break;
                iVar3 = iVar3 + 1;
                *(undefined4 *)((int)pvVar5 + iVar3 * 4 + -4) =
                     *(undefined4 *)(*(int *)&this->field_0x60 + -4 + iVar3 * 4);
              } while (iVar3 < *(int *)&this->field_0x6c);
            }
            operator_delete(*(void **)&this->field_0x60);
            *(void **)&this->field_0x60 = pvVar5;
            *(int *)&this->field_0x6c = iVar6 + 1;
          }
        }
        pRVar4 = RGE_Game_World::object
                           (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),
                            *(int *)(*(int *)&this->field_0x60 + iVar6 * 4));
        if (pRVar4 != (RGE_Static_Object *)0x0) {
          fVar11 = (pRVar4->world_x - *(float *)(*(int *)&this->field_0x4 + 0x38)) + fVar11;
          fVar10 = (pRVar4->world_y - *(float *)(*(int *)&this->field_0x4 + 0x3c)) + fVar10;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)&this->field_0x64);
  }
  iVar3 = *(int *)&this->field_0x4;
  fVar2 = SQRT(fVar10 * fVar10 + fVar11 * fVar11);
  (**(code **)(iVar7 + 0x9c))
            (-((fVar11 / fVar2) * fVar9) + *(float *)(iVar3 + 0x38),
             -((fVar10 / fVar2) * fVar9) + *(float *)(iVar3 + 0x3c),*(undefined4 *)(iVar3 + 0x40),1)
  ;
  return 3;
}

// --------------------------------------------------

