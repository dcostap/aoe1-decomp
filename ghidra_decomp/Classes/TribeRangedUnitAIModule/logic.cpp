// Class: TribeRangedUnitAIModule
// Function: TribeRangedUnitAIModule
// Address: 00504700
/* public: __thiscall TribeRangedUnitAIModule::TribeRangedUnitAIModule(class RGE_Static_Object
   *,int) */

TribeRangedUnitAIModule * __thiscall
TribeRangedUnitAIModule::TribeRangedUnitAIModule
          (TribeRangedUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00504720
/* public: virtual void * __thiscall TribeRangedUnitAIModule::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
TribeRangedUnitAIModule::_vector_deleting_destructor_(TribeRangedUnitAIModule *this,uint param_1)
{
  ~TribeRangedUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeRangedUnitAIModule
// Address: 00504740
/* public: virtual __thiscall TribeRangedUnitAIModule::~TribeRangedUnitAIModule(void) */

void __thiscall TribeRangedUnitAIModule::~TribeRangedUnitAIModule(TribeRangedUnitAIModule *this)
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
// Address: 00504750
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TribeRangedUnitAIModule::processNotify(struct NotifyEvent
   *,unsigned long) */

int __thiscall
TribeRangedUnitAIModule::processNotify
          (TribeRangedUnitAIModule *this,NotifyEvent *param_1,ulong param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float fVar8;
  
  if (param_1->mType != 0x200) {
    iVar3 = UnitAIModule::processNotify((UnitAIModule *)this,param_1,param_2);
    return iVar3;
  }
  if (*(int *)&this->field_0x30 == 600) {
    pRVar4 = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x4 + 0xc) + 0x3c),
                        *(int *)&this->field_0x34);
    if (pRVar4 != (RGE_Static_Object *)0x0) {
      fVar5 = (float10)(**(code **)(pRVar4->_padding_ + 0xf4))();
      if (fVar5 != (float10)_DAT_005758c4) {
        iVar3 = *(int *)this;
        (**(code **)(iVar3 + 0x10))
                  (*(undefined4 *)(*(int *)&this->field_0x4 + 4),700,
                   *(undefined4 *)&this->field_0x34,0xffffffff,*(undefined4 *)&this->field_0x3c,
                   *(undefined4 *)&this->field_0x40,*(undefined4 *)&this->field_0x44,
                   *(undefined4 *)&this->field_0x48,0,1,*(undefined4 *)&this->field_0x2c);
        piVar1 = *(int **)&this->field_0x4;
        fVar5 = (float10)(**(code **)(*piVar1 + 0x100))();
        fVar8 = (float)fVar5;
        fVar5 = (float10)(**(code **)(*piVar1 + 0xfc))();
        iVar2 = *(int *)&this->field_0x4;
        fVar5 = fVar5 * (float10)fVar8 * (float10)_DAT_005758b0;
        fVar6 = (float10)pRVar4->world_x - (float10)*(float *)(iVar2 + 0x38);
        fVar7 = (float10)pRVar4->world_y - (float10)*(float *)(iVar2 + 0x3c);
        fVar8 = (float)SQRT(fVar7 * fVar7 + fVar6 * fVar6);
        (**(code **)(iVar3 + 0x9c))
                  ((float)(-((fVar6 / (float10)fVar8) * fVar5) + (float10)*(float *)(iVar2 + 0x38)),
                   (float)(-((fVar7 / (float10)fVar8) * fVar5) + (float10)*(float *)(iVar2 + 0x3c)),
                   *(undefined4 *)(iVar2 + 0x40),1);
        return 3;
      }
    }
  }
  return 2;
}

// --------------------------------------------------

