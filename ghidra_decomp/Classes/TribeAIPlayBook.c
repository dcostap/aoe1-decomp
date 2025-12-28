// Class: TribeAIPlayBook
// Size:  0x50
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] convertTargetNameToIntType
// [02] convertTargetCharacteristicNameToIntType
// [03] convertUnitNameToIntType
// [04] convertUnitToIntType
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TribeAIPlayBook
// Address: 004e68b0
/* public: __thiscall TribeAIPlayBook::TribeAIPlayBook(void) */

TribeAIPlayBook * __thiscall TribeAIPlayBook::TribeAIPlayBook(TribeAIPlayBook *this)
{
  AIPlayBook::AIPlayBook((AIPlayBook *)this);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004e68d0
/* public: virtual void * __thiscall TribeAIPlayBook::`vector deleting destructor'(unsigned int) */

void * __thiscall TribeAIPlayBook::_vector_deleting_destructor_(TribeAIPlayBook *this,uint param_1)
{
  ~TribeAIPlayBook(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeAIPlayBook
// Address: 004e68f0
/* public: virtual __thiscall TribeAIPlayBook::~TribeAIPlayBook(void) */

void __thiscall TribeAIPlayBook::~TribeAIPlayBook(TribeAIPlayBook *this)
{
  *(undefined ***)this = &AIPlayBook::_vftable_;
  if (*(void **)&this->field_0x4c != (void *)0x0) {
    *(undefined4 *)&this->field_0x4 = 0;
    operator_delete(*(void **)&this->field_0x4c);
    *(undefined4 *)&this->field_0x4c = 0;
  }
  return;
}

// --------------------------------------------------

// Function: convertTargetNameToIntType
// Address: 004e6900
/* public: virtual int __thiscall TribeAIPlayBook::convertTargetNameToIntType(char *)const  */

int __thiscall TribeAIPlayBook::convertTargetNameToIntType(TribeAIPlayBook *this,char *param_1)
{
  int iVar1;
  
  iVar1 = AIPlayBook::convertTargetNameToIntType((AIPlayBook *)this,param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: convertTargetCharacteristicNameToIntType
// Address: 004e6910
/* public: virtual int __thiscall TribeAIPlayBook::convertTargetCharacteristicNameToIntType(char
   *)const  */

int __thiscall
TribeAIPlayBook::convertTargetCharacteristicNameToIntType(TribeAIPlayBook *this,char *param_1)
{
  int iVar1;
  
  iVar1 = AIPlayBook::convertTargetCharacteristicNameToIntType((AIPlayBook *)this,param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: convertUnitNameToIntType
// Address: 004e6920
// [HELPER] s_Cavalry: "Cavalry"
// [HELPER] s_Hand: "Hand"
// [HELPER] s_Legion: "Legion"
// [HELPER] s_Priest: "Priest"
// [HELPER] s_Ranged: "Ranged"
// [HELPER] s_Siege: "Siege"
/* public: virtual int __thiscall TribeAIPlayBook::convertUnitNameToIntType(char *)const  */

int __thiscall TribeAIPlayBook::convertUnitNameToIntType(TribeAIPlayBook *this,char *param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = &s_Hand;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e6959:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e695e;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e6959;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e695e:
  if (iVar3 == 0) {
    return 0;
  }
  pbVar4 = &s_Ranged;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e6998:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e699d;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e6998;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e699d:
  if (iVar3 == 0) {
    return 1;
  }
  pbVar4 = &s_Priest;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e69dc:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e69e1;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e69dc;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e69e1:
  if (iVar3 == 0) {
    return 4;
  }
  pbVar4 = &s_Siege;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e6a20:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e6a25;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e6a20;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e6a25:
  if (iVar3 == 0) {
    return 5;
  }
  pbVar4 = &s_Cavalry;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e6a64:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e6a69;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e6a64;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e6a69:
  if (iVar3 == 0) {
    return 2;
  }
  pbVar4 = &s_Legion;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e6aa8:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e6aad;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e6aa8;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e6aad:
  if (iVar3 == 0) {
    return 3;
  }
  iVar3 = AIPlayBook::convertUnitNameToIntType((AIPlayBook *)this,param_1);
  return iVar3;
}

// --------------------------------------------------

// Function: convertUnitToIntType
// Address: 004e6ad0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall TribeAIPlayBook::convertUnitToIntType(class RGE_Static_Object
   *)const  */

int __thiscall
TribeAIPlayBook::convertUnitToIntType(TribeAIPlayBook *this,RGE_Static_Object *param_1)
{
  short sVar1;
  float10 fVar2;
  
  sVar1 = param_1->master_obj->object_group;
  if (sVar1 == 0x12) {
    return 4;
  }
  if (sVar1 == 0x1c) {
    return 3;
  }
  if (sVar1 == 0xd) {
    return 5;
  }
  if ((sVar1 != 0xc) && (sVar1 != 0x23)) {
    fVar2 = (float10)(**(code **)(param_1->_padding_ + 0x10c))();
    if ((float10)_DAT_00575634 < fVar2) {
      return 1;
    }
    return 0;
  }
  return 2;
}

// --------------------------------------------------

