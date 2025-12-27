// GLOBAL FUNCTIONS PART 4600
// Function: FUN_00508105
// Address: 00508105
uint __thiscall FUN_00508105(int param_1,uint param_2)
{
  if (param_2 == 0) {
    return param_2;
  }
  if (*(short *)(*(int *)(param_2 + 8) + 0x14) == 1) {
    return 0;
  }
  return (uint)(1 < *(byte *)(*(int *)(param_1 + 4) + 0x48));
}

// --------------------------------------------------

// Function: FUN_00508137
// Address: 00508137
undefined4 FUN_00508137(int param_1)
{
  if ((((param_1 != 3) && (param_1 != 0x1b)) && (param_1 != 4)) &&
     ((param_1 != 0x15 && (param_1 != 2)))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0050816a
// Address: 0050816a
UnitAIModule * __thiscall FUN_0050816a(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560d68;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeBuildingUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 0x15;
  piVar1 = (int *)operator_new(0x54);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 0;
    param_1->importantObjects[1] = 3;
    param_1->importantObjects[2] = 4;
    param_1->importantObjects[3] = 0x1a;
    param_1->importantObjects[4] = 0x18;
    param_1->importantObjects[5] = 6;
    param_1->importantObjects[6] = 0x23;
    param_1->importantObjects[7] = 0x19;
    param_1->importantObjects[8] = 0x11;
    param_1->importantObjects[9] = 0xc;
    param_1->importantObjects[10] = 0x17;
    param_1->importantObjects[0xb] = 0x24;
    param_1->importantObjects[0xc] = 0x1c;
    param_1->importantObjects[0xd] = 0x12;
    param_1->importantObjects[0xe] = 0xd;
    param_1->importantObjects[0xf] = 0x1b;
    param_1->importantObjects[0x10] = 0x16;
    param_1->importantObjects[0x11] = 0x14;
    param_1->importantObjects[0x12] = 2;
    param_1->importantObjects[0x13] = 0x15;
    param_1->importantObjects[0x14] = 0x27;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005082ec
// Address: 005082ec
TribeBuildingUnitAIModule * __thiscall FUN_005082ec(TribeBuildingUnitAIModule *param_1,byte param_2)
{
  TribeBuildingUnitAIModule::~TribeBuildingUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00508315
// Address: 00508315
undefined4 __thiscall FUN_00508315(UnitAIModule *param_1,int *param_2)
{
  ManagedArray<int> *this;
  long lVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong unaff_EDI;
  
  switch(param_2[2]) {
  case 500:
    break;
  default:
    return 2;
  case 600:
    iVar6 = (param_1->attackingUnitsValue).numberValue;
    iVar5 = *param_2;
    iVar2 = 0;
    if (0 < iVar6) {
      do {
        if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar2) break;
        if ((param_1->attackingUnitsValue).value[iVar2] == iVar5) goto LAB_005084e0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar6);
    }
    if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar6) {
      iVar6 = iVar6 + 1;
      piVar3 = (int *)operator_new(iVar6 * 4);
      if (piVar3 != (int *)0x0) {
        iVar2 = 0;
        if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
          do {
            if (iVar6 <= iVar2) break;
            iVar4 = iVar2 + 1;
            piVar3[iVar2] = (param_1->attackingUnitsValue).value[iVar2];
            iVar2 = iVar4;
          } while (iVar4 < (param_1->attackingUnitsValue).maximumSizeValue);
        }
        operator_delete((param_1->attackingUnitsValue).value);
        (param_1->attackingUnitsValue).value = piVar3;
        (param_1->attackingUnitsValue).maximumSizeValue = iVar6;
      }
    }
    (param_1->attackingUnitsValue).value[(param_1->attackingUnitsValue).numberValue] = iVar5;
    (param_1->attackingUnitsValue).numberValue = (param_1->attackingUnitsValue).numberValue + 1;
LAB_005084e0:
    (**(code **)(param_1->objectValue->_padding_ + 0xec))(1);
    return 2;
  case 699:
    iVar6 = (param_1->attackingUnitsValue).numberValue;
    iVar5 = 0;
    if (iVar6 < 1) {
      return 2;
    }
    while( true ) {
      if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar5) {
        return 2;
      }
      if ((param_1->attackingUnitsValue).value[iVar5] == *param_2) break;
      iVar5 = iVar5 + 1;
      if (iVar6 <= iVar5) {
        return 2;
      }
    }
    iVar6 = (param_1->attackingUnitsValue).maximumSizeValue;
    iVar5 = 0;
    if (0 < iVar6) {
      piVar3 = (param_1->attackingUnitsValue).value;
      do {
        if (*piVar3 == *param_2) break;
        iVar5 = iVar5 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar5 < iVar6);
    }
    if (iVar6 <= iVar5) {
      return 2;
    }
    if (iVar5 < iVar6 + -1) {
      do {
        piVar3 = (param_1->attackingUnitsValue).value;
        iVar6 = iVar5 + 1;
        piVar3[iVar5] = piVar3[iVar6];
        iVar5 = iVar6;
      } while (iVar6 < (param_1->attackingUnitsValue).maximumSizeValue + -1);
    }
    iVar6 = (param_1->attackingUnitsValue).numberValue + -1;
    (param_1->attackingUnitsValue).numberValue = iVar6;
    if (iVar6 < 0) {
      (param_1->attackingUnitsValue).numberValue = 0;
      return 2;
    }
    return 2;
  }
  if (param_2[4] < 1) {
    lVar1 = param_1->objectValue->id;
    (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))(lVar1,lVar1,0x209,*param_2,0,0);
    UnitAIModule::purgeNotifyQueue(param_1,unaff_EDI);
    return 4;
  }
  if (((param_1->attackingUnitsValue).numberValue == 0) ||
     (iVar6 = RGE_Player::computerPlayer(param_1->objectValue->owner), iVar6 == 1)) {
    lVar1 = param_1->objectValue->id;
    (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))(lVar1,lVar1,0x201,*param_2,0,0);
  }
  iVar6 = (param_1->attackingUnitsValue).numberValue;
  this = &param_1->attackingUnitsValue;
  iVar5 = 0;
  if (0 < iVar6) {
    do {
      if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar5) break;
      if (this->value[iVar5] == *param_2) goto LAB_00508402;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar6);
  }
  iVar6 = RGE_Player::computerPlayer(param_1->objectValue->owner);
  if ((iVar6 == 0) && (param_1->currentTargetValue != *param_2)) {
    UnitAIModule::askForHelp(param_1,*param_2);
  }
LAB_00508402:
  iVar6 = (param_1->attackingUnitsValue).numberValue;
  iVar5 = *param_2;
  iVar2 = 0;
  if (0 < iVar6) {
    do {
      if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar2) break;
      if (this->value[iVar2] == iVar5) goto LAB_005084e0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar6);
  }
  if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar6) {
    ManagedArray<int>::resize(this,iVar6 + 1);
  }
  this->value[(param_1->attackingUnitsValue).numberValue] = iVar5;
  (param_1->attackingUnitsValue).numberValue = (param_1->attackingUnitsValue).numberValue + 1;
  (**(code **)(param_1->objectValue->_padding_ + 0xec))(1);
  return 2;
}

// --------------------------------------------------

// Function: FUN_00508668
// Address: 00508668
void __thiscall FUN_00508668(undefined2 *param_1,undefined2 param_2)
{
  param_1[1] = param_2;
  *param_1 = 1;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[7] = 0xffff;
  param_1[10] = 0xffff;
  param_1[0xb] = 0xffff;
  param_1[0xc] = 0xffff;
  param_1[0xd] = 0xffff;
  *(undefined4 *)(param_1 + 0xe) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x16) = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)(param_1 + 9) = 0;
  *(undefined4 *)(param_1 + 0x1a) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x1e) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x22) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_005086e3
// Address: 005086e3
void FUN_005086e3(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_005086f1
// Address: 005086f1
void __thiscall FUN_005086f1(int param_1,int param_2)
{
  *(undefined1 *)(param_1 + 4) = *(undefined1 *)(param_2 + 4);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 6);
  *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 8);
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_2 + 10);
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_2 + 0xe);
  *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)(param_1 + 0x16) = *(undefined2 *)(param_2 + 0x16);
  *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(param_2 + 0x18);
  *(undefined2 *)(param_1 + 0x1a) = *(undefined2 *)(param_2 + 0x1a);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 0x24);
  *(undefined1 *)(param_1 + 0x28) = *(undefined1 *)(param_2 + 0x28);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined1 *)(param_1 + 0xc) = *(undefined1 *)(param_2 + 0xc);
  *(undefined1 *)(param_1 + 0xd) = *(undefined1 *)(param_2 + 0xd);
  *(undefined2 *)(param_1 + 0x30) = *(undefined2 *)(param_2 + 0x30);
  *(undefined2 *)(param_1 + 0x32) = *(undefined2 *)(param_2 + 0x32);
  *(undefined1 *)(param_1 + 0x10) = *(undefined1 *)(param_2 + 0x10);
  *(undefined1 *)(param_1 + 0x11) = *(undefined1 *)(param_2 + 0x11);
  *(undefined1 *)(param_1 + 0x12) = *(undefined1 *)(param_2 + 0x12);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_2 + 0x38);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_2 + 0x44);
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_2 + 0x48);
  return;
}

// --------------------------------------------------

// Function: FUN_005087bd
// Address: 005087bd
void __thiscall FUN_005087bd(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = param_2;
  rge_read(param_2,(void *)(param_1 + 2),2);
  rge_read(iVar1,(void *)(param_1 + 4),1);
  rge_read(iVar1,(void *)(param_1 + 6),2);
  rge_read(iVar1,(void *)(param_1 + 8),2);
  rge_read(iVar1,(void *)(param_1 + 10),2);
  rge_read(iVar1,(void *)(param_1 + 0xe),2);
  rge_read(iVar1,(void *)(param_1 + 0x14),2);
  rge_read(iVar1,(void *)(param_1 + 0x16),2);
  rge_read(iVar1,(void *)(param_1 + 0x18),2);
  rge_read(iVar1,(void *)(param_1 + 0x1a),2);
  rge_read(iVar1,(void *)(param_1 + 0x1c),4);
  rge_read(iVar1,(void *)(param_1 + 0x20),4);
  rge_read(iVar1,(void *)(param_1 + 0x24),4);
  rge_read(iVar1,(void *)(param_1 + 0x28),1);
  rge_read(iVar1,(void *)(param_1 + 0x2c),4);
  rge_read(iVar1,(void *)(param_1 + 0xc),1);
  rge_read(iVar1,(void *)(param_1 + 0xd),1);
  rge_read(iVar1,(void *)(param_1 + 0x30),2);
  rge_read(iVar1,(void *)(param_1 + 0x32),2);
  rge_read(iVar1,(void *)(param_1 + 0x10),1);
  rge_read(iVar1,(void *)(param_1 + 0x11),1);
  rge_read(iVar1,(void *)(param_1 + 0x12),1);
  rge_read(iVar1,&param_2,2);
  iVar2 = param_3;
  if ((short)param_2 == -1) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_3 + (short)param_2 * 4);
  }
  *(undefined4 *)(param_1 + 0x34) = uVar3;
  rge_read(iVar1,&param_2,2);
  if ((short)param_2 == -1) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar2 + (short)param_2 * 4);
  }
  *(undefined4 *)(param_1 + 0x38) = uVar3;
  rge_read(iVar1,&param_2,2);
  if ((short)param_2 == -1) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar2 + (short)param_2 * 4);
  }
  *(undefined4 *)(param_1 + 0x3c) = uVar3;
  rge_read(iVar1,&param_2,2);
  if ((short)param_2 == -1) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar2 + (short)param_2 * 4);
  }
  *(undefined4 *)(param_1 + 0x40) = uVar3;
  rge_read(iVar1,&param_2,2);
  iVar2 = param_4;
  if ((short)param_2 == -1) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_4 + (short)param_2 * 4);
  }
  *(undefined4 *)(param_1 + 0x44) = uVar3;
  rge_read(iVar1,&param_2,2);
  if ((short)param_2 == -1) {
    *(undefined4 *)(param_1 + 0x48) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(iVar2 + (short)param_2 * 4);
  return;
}

// --------------------------------------------------

// Function: FUN_00508a18
// Address: 00508a18
// [HELPER] s__hd__hd__hd__hd__hd__hd__hd__hd_: "%hd %hd %hd %hd %hd %hd %hd %hd %hd"
void __thiscall FUN_00508a18(int param_1,undefined4 param_2,int param_3,int param_4)
{
  undefined4 uVar1;
  undefined1 auStack_18 [2];
  undefined1 auStack_16 [2];
  undefined1 auStack_14 [2];
  undefined1 auStack_12 [2];
  undefined1 auStack_10 [2];
  undefined1 auStack_e [2];
  short sStack_c;
  short sStack_a;
  short sStack_8;
  short sStack_6;
  short sStack_4;
  short sStack_2;
  
  fscanf(param_2,s__hd__hd__hd__hd__hd__hd__hd__hd_,param_1 + 2,&param_2,param_1 + 6,param_1 + 8,
         param_1 + 10,param_1 + 0xe,param_1 + 0x14,param_1 + 0x16,param_1 + 0x18,param_1 + 0x1a,
         param_1 + 0x1c,param_1 + 0x20,param_1 + 0x24,auStack_14,param_1 + 0x2c,auStack_18,
         auStack_16,param_1 + 0x30,param_1 + 0x32,auStack_12,auStack_10,auStack_e,&sStack_c,
         &sStack_a,&sStack_8,&sStack_6,&sStack_4,&sStack_2);
  *(undefined1 *)(param_1 + 4) = (undefined1)param_2;
  *(undefined1 *)(param_1 + 0xc) = auStack_18[0];
  *(undefined1 *)(param_1 + 0xd) = auStack_16[0];
  *(undefined1 *)(param_1 + 0x28) = auStack_14[0];
  *(undefined1 *)(param_1 + 0x10) = auStack_12[0];
  *(undefined1 *)(param_1 + 0x11) = auStack_10[0];
  *(undefined1 *)(param_1 + 0x12) = auStack_e[0];
  if (sStack_c == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + sStack_c * 4);
  }
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  if (sStack_a == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + sStack_a * 4);
  }
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  if (sStack_8 == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + sStack_8 * 4);
  }
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  if (sStack_6 == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + sStack_6 * 4);
  }
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  if (sStack_4 == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_4 + sStack_4 * 4);
  }
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  if (sStack_2 == -1) {
    *(undefined4 *)(param_1 + 0x48) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_4 + sStack_2 * 4);
  return;
}

// --------------------------------------------------

// Function: FUN_00508ba5
// Address: 00508ba5
void __thiscall FUN_00508ba5(void *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  
  iVar2 = param_2;
  rge_write(param_2,param_1,2);
  rge_write(iVar2,(void *)((int)param_1 + 2),2);
  rge_write(iVar2,(void *)((int)param_1 + 4),1);
  rge_write(iVar2,(void *)((int)param_1 + 6),2);
  rge_write(iVar2,(void *)((int)param_1 + 8),2);
  rge_write(iVar2,(void *)((int)param_1 + 10),2);
  rge_write(iVar2,(void *)((int)param_1 + 0xe),2);
  rge_write(iVar2,(void *)((int)param_1 + 0x14),2);
  rge_write(iVar2,(void *)((int)param_1 + 0x16),2);
  rge_write(iVar2,(void *)((int)param_1 + 0x18),2);
  rge_write(iVar2,(void *)((int)param_1 + 0x1a),2);
  rge_write(iVar2,(void *)((int)param_1 + 0x1c),4);
  rge_write(iVar2,(void *)((int)param_1 + 0x20),4);
  rge_write(iVar2,(void *)((int)param_1 + 0x24),4);
  rge_write(iVar2,(void *)((int)param_1 + 0x28),1);
  rge_write(iVar2,(void *)((int)param_1 + 0x2c),4);
  rge_write(iVar2,(void *)((int)param_1 + 0xc),1);
  rge_write(iVar2,(void *)((int)param_1 + 0xd),1);
  rge_write(iVar2,(void *)((int)param_1 + 0x30),2);
  rge_write(iVar2,(void *)((int)param_1 + 0x32),2);
  rge_write(iVar2,(void *)((int)param_1 + 0x10),1);
  rge_write(iVar2,(void *)((int)param_1 + 0x11),1);
  rge_write(iVar2,(void *)((int)param_1 + 0x12),1);
  if (*(int *)((int)param_1 + 0x34) == 0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = CONCAT22(extraout_var,*(undefined2 *)(*(int *)((int)param_1 + 0x34) + 0x72));
  }
  rge_write(iVar2,&param_2,2);
  iVar1 = *(int *)((int)param_1 + 0x38);
  if (iVar1 == 0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x72));
  }
  rge_write(iVar2,&param_2,2);
  if (*(int *)((int)param_1 + 0x3c) == 0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = CONCAT22(extraout_var_01,*(undefined2 *)(*(int *)((int)param_1 + 0x3c) + 0x72));
  }
  rge_write(iVar2,&param_2,2);
  if (*(int *)((int)param_1 + 0x40) == 0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = CONCAT22(extraout_var_00,*(undefined2 *)(*(int *)((int)param_1 + 0x40) + 0x72));
  }
  rge_write(iVar2,&param_2,2);
  iVar1 = *(int *)((int)param_1 + 0x44);
  if (iVar1 == 0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0xc));
  }
  rge_write(iVar2,&param_2,2);
  if (*(int *)((int)param_1 + 0x48) == 0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = CONCAT22(extraout_var_02,*(undefined2 *)(*(int *)((int)param_1 + 0x48) + 0xc));
  }
  rge_write(iVar2,&param_2,2);
  return;
}

// --------------------------------------------------

// Function: FUN_00508df6
// Address: 00508df6
void __fastcall FUN_00508df6(undefined4 *param_1)
{
  *param_1 = &RGE_Task_List::_vftable_;
  *(undefined2 *)(param_1 + 2) = 0;
  param_1[1] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00508e12
// Address: 00508e12
void __fastcall FUN_00508e12(RGE_Task_List *param_1)
{
  param_1->_padding_ = (int)&RGE_Task_List::_vftable_;
  RGE_Task_List::delete_list(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00508e2b
// Address: 00508e2b
void __thiscall FUN_00508e2b(RGE_Task_List *param_1,int param_2)
{
  short sVar1;
  code *pcVar2;
  RGE_Task **ppRVar3;
  RGE_Task *pRVar4;
  int iVar5;
  int iVar6;
  
  if (param_1->list != (RGE_Task **)0x0) {
    RGE_Task_List::delete_list(param_1);
  }
  sVar1 = *(short *)(param_2 + 8);
  param_1->list_num = sVar1;
  if (0 < sVar1) {
    ppRVar3 = (RGE_Task **)calloc((int)sVar1,4);
    iVar5 = 0;
    param_1->list = ppRVar3;
    if (0 < param_1->list_num) {
      pcVar2 = *(code **)param_1->_padding_;
      do {
        iVar6 = (int)(short)iVar5;
        pRVar4 = (RGE_Task *)(*pcVar2)(**(undefined2 **)(*(int *)(param_2 + 4) + iVar6 * 4),iVar5);
        param_1->list[iVar6] = pRVar4;
        RGE_Task::copy(param_1->list[iVar6],*(RGE_Task **)(*(int *)(param_2 + 4) + iVar6 * 4));
        iVar5 = iVar5 + 1;
      } while ((short)iVar5 < param_1->list_num);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00508eb1
// Address: 00508eb1
void __thiscall
FUN_00508eb1(RGE_Task_List *param_1,int param_2,RGE_Sprite **param_3,RGE_Sound **param_4)
{
  short *psVar1;
  code *pcVar2;
  RGE_Task **ppRVar3;
  RGE_Task *pRVar4;
  int iVar5;
  RGE_Task_List *pRStack_4;
  
  pRStack_4 = param_1;
  if (param_1->list != (RGE_Task **)0x0) {
    RGE_Task_List::delete_list(param_1);
  }
  psVar1 = &param_1->list_num;
  rge_read(param_2,psVar1,2);
  if (0 < *psVar1) {
    ppRVar3 = (RGE_Task **)calloc((int)*psVar1,4);
    iVar5 = 0;
    param_1->list = ppRVar3;
    if (0 < *psVar1) {
      pcVar2 = *(code **)param_1->_padding_;
      do {
        rge_read(param_2,&pRStack_4,2);
        pRVar4 = (RGE_Task *)(*pcVar2)(pRStack_4,iVar5);
        param_1->list[(short)iVar5] = pRVar4;
        RGE_Task::load(param_1->list[(short)iVar5],param_2,param_3,param_4);
        iVar5 = iVar5 + 1;
      } while ((short)iVar5 < param_1->list_num);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00508f5b
// Address: 00508f5b
// [HELPER] s__hd: "%hd"
void __thiscall
FUN_00508f5b(RGE_Task_List *param_1,_iobuf *param_2,RGE_Sprite **param_3,RGE_Sound **param_4)
{
  short *psVar1;
  code *pcVar2;
  RGE_Task **ppRVar3;
  RGE_Task *pRVar4;
  int iVar5;
  RGE_Task_List *pRStack_4;
  
  pRStack_4 = param_1;
  if (param_1->list != (RGE_Task **)0x0) {
    RGE_Task_List::delete_list(param_1);
  }
  psVar1 = &param_1->list_num;
  fscanf(param_2,s__hd,psVar1);
  if (0 < *psVar1) {
    ppRVar3 = (RGE_Task **)calloc((int)*psVar1,4);
    iVar5 = 0;
    param_1->list = ppRVar3;
    if (0 < *psVar1) {
      pcVar2 = *(code **)param_1->_padding_;
      do {
        fscanf(param_2,s__hd,&pRStack_4);
        pRVar4 = (RGE_Task *)(*pcVar2)(pRStack_4,iVar5);
        param_1->list[(short)iVar5] = pRVar4;
        RGE_Task::load(param_1->list[(short)iVar5],param_2,param_3,param_4);
        iVar5 = iVar5 + 1;
      } while ((short)iVar5 < param_1->list_num);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00509001
// Address: 00509001
void __thiscall FUN_00509001(int param_1,int param_2)
{
  short *psVar1;
  short sVar2;
  
  psVar1 = (short *)(param_1 + 8);
  rge_write(param_2,psVar1,2);
  sVar2 = 0;
  if (0 < *psVar1) {
    do {
      RGE_Task::save(*(RGE_Task **)(*(int *)(param_1 + 4) + sVar2 * 4),param_2);
      sVar2 = sVar2 + 1;
    } while (sVar2 < *psVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050904c
// Address: 0050904c
void __fastcall FUN_0050904c(int param_1)
{
  RGE_Task *this;
  short sVar1;
  
  sVar1 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    if (0 < *(short *)(param_1 + 8)) {
      do {
        this = *(RGE_Task **)(*(int *)(param_1 + 4) + sVar1 * 4);
        if (this != (RGE_Task *)0x0) {
          RGE_Task::~RGE_Task(this);
          operator_delete(this);
          *(undefined4 *)(*(int *)(param_1 + 4) + sVar1 * 4) = 0;
        }
        sVar1 = sVar1 + 1;
      } while (sVar1 < *(short *)(param_1 + 8));
    }
    free(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined2 *)(param_1 + 8) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_005090ae
// Address: 005090ae
undefined4 FUN_005090ae(short param_1,short param_2)
{
  RGE_Task *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560d8b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_1 == 1) {
    this = (RGE_Task *)operator_new(0x4c);
    uStack_4 = 0;
    if (this != (RGE_Task *)0x0) {
      uVar1 = RGE_Task::RGE_Task(this,param_2);
      *unaff_FS_OFFSET = uStack_c;
      return uVar1;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00509117
// Address: 00509117
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_00509117(int *param_1,int param_2,int param_3,float param_4,float param_5)
{
  int iVar1;
  RGE_Map *this;
  byte bVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  if ((short)param_1[2] != 0) {
    if (param_3 != 0) {
      if ((*(char *)(param_3 + 0x48) == '\0') && (iVar6 = 0, 0 < (short)param_1[2])) {
        do {
          iVar1 = *(int *)(param_1[1] + iVar6 * 4);
          if ((*(char *)(iVar1 + 0x12) == '\x01') &&
             (iVar5 = (**(code **)(*param_1 + 0xc))(iVar1,param_2,param_3), iVar5 != 0)) {
            return iVar1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (short)param_1[2]);
      }
      iVar6 = 0;
      if (0 < (short)param_1[2]) {
        do {
          iVar1 = *(int *)(param_1[1] + iVar6 * 4);
          if ((*(short *)(iVar1 + 10) == *(short *)(*(int *)(param_3 + 8) + 0x10)) &&
             (iVar5 = (**(code **)(*param_1 + 0xc))(iVar1,param_2,param_3), iVar5 != 0)) {
            return iVar1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (short)param_1[2]);
      }
      iVar6 = 0;
      if (0 < (short)param_1[2]) {
        do {
          iVar1 = *(int *)(param_1[1] + iVar6 * 4);
          if ((*(short *)(iVar1 + 8) == *(short *)(*(int *)(param_3 + 8) + 0x14)) &&
             (iVar5 = (**(code **)(*param_1 + 0xc))(iVar1,param_2,param_3), iVar5 != 0)) {
            return iVar1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (short)param_1[2]);
      }
      if (((*(byte *)(param_3 + 0x48) < 3) && (*(char *)(*(int *)(param_3 + 8) + 0x8c) != '\0')) &&
         (iVar6 = 0, 0 < (short)param_1[2])) {
        do {
          iVar1 = *(int *)(param_1[1] + iVar6 * 4);
          if ((*(char *)(iVar1 + 0xc) != '\0') &&
             (iVar5 = (**(code **)(*param_1 + 0xc))(iVar1,param_2,param_3), iVar5 != 0)) {
            return iVar1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (short)param_1[2]);
      }
    }
    if ((param_4 != _DAT_00576540) && (param_5 != _DAT_00576540)) {
      sVar3 = __ftol();
      sVar4 = __ftol();
      this = *(RGE_Map **)(*(int *)(*(int *)(param_2 + 0xc) + 0x3c) + 0x28);
      if ((-1 < sVar3) &&
         ((((int)sVar3 < this->map_width && (-1 < sVar4)) && ((int)sVar4 < this->map_height)))) {
        bVar2 = RGE_Map::get_terrain(this,sVar3,sVar4);
        iVar6 = 0;
        if (0 < (short)param_1[2]) {
          piVar7 = (int *)param_1[1];
          do {
            if (*(ushort *)(*piVar7 + 0xe) == (ushort)bVar2) {
              return *piVar7;
            }
            iVar6 = iVar6 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar6 < (short)param_1[2]);
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005092ce
// Address: 005092ce
bool FUN_005092ce(int param_1)
{
  return *(short *)(param_1 + 6) == 7;
}

// --------------------------------------------------

// Function: FUN_005092e1
// Address: 005092e1
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_005092e1(int param_1,int param_2,int param_3)
{
  short sVar1;
  uchar uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x11) == '\x01') {
    if (*(short *)(param_3 + 0x4c) == -1) {
      return false;
    }
    if (*(float *)(param_3 + 0x44) <= _DAT_00576544) {
      return false;
    }
  }
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 1:
    if (*(int *)(param_3 + 0xc) != *(int *)(param_2 + 0xc)) {
      return false;
    }
    break;
  case 2:
    if (*(RGE_Player **)(param_3 + 0xc) == *(RGE_Player **)(param_2 + 0xc)) {
      return false;
    }
    sVar1 = (*(RGE_Player **)(param_3 + 0xc))->id;
    if (sVar1 == 0) {
      return false;
    }
    uVar2 = RGE_Player::relation(*(RGE_Player **)(param_2 + 0xc),(int)sVar1);
    if (uVar2 == '\0') {
      return false;
    }
    break;
  case 3:
    if (*(short *)(*(int *)(param_3 + 0xc) + 0x4a) != 0) {
      return false;
    }
    break;
  case 4:
    if (*(int **)(param_3 + 0xc) == *(int **)(param_2 + 0xc)) {
      return true;
    }
    sVar1 = *(short *)((int)*(int **)(param_3 + 0xc) + 0x4a);
    if (((sVar1 != 0) &&
        (iVar3 = (**(code **)(**(int **)(param_2 + 0xc) + 0x1c))((int)sVar1), iVar3 != 0)) &&
       (iVar3 = (**(code **)(**(int **)(param_3 + 0xc) + 0x1c))
                          ((int)*(short *)(*(int *)(param_2 + 0xc) + 0x4a)), iVar3 != 0)) {
      return true;
    }
    return false;
  case 5:
    if (*(RGE_Player **)(param_3 + 0xc) == *(RGE_Player **)(param_2 + 0xc)) {
      return false;
    }
    sVar1 = (*(RGE_Player **)(param_3 + 0xc))->id;
    if ((sVar1 != 0) &&
       (uVar2 = RGE_Player::relation(*(RGE_Player **)(param_2 + 0xc),(int)sVar1), uVar2 == '\0')) {
      return false;
    }
    if ((*(short *)(*(int *)(param_3 + 0xc) + 0x4a) == 0) &&
       (*(char *)(*(int *)(param_2 + 8) + 0x8c) == '\0')) {
      return false;
    }
  }
  return param_2 != param_3;
}

// --------------------------------------------------

// Function: FUN_0050942f
// Address: 0050942f
TTaunt * __fastcall FUN_0050942f(int param_1,int param_2)
{
  char *pcVar1;
  TSound_Driver *in_EAX;
  TTaunt *this;
  int unaff_EBX;
  
  *(char *)(param_1 + -0x6d) = *(char *)(param_1 + -0x6d) + (char)param_2;
  pcVar1 = (char *)(unaff_EBX + -0x6c66ffb0 + param_2 * 4);
  *pcVar1 = *pcVar1 + (char)in_EAX;
  this = (TTaunt *)
         CONCAT22((short)((uint)param_1 >> 0x10),
                  CONCAT11((char)((uint)param_1 >> 8) + (char)((uint)in_EAX >> 8),(char)param_1));
  *(char *)(unaff_EBX + -0x6f6f6f70) = *(char *)(unaff_EBX + -0x6f6f6f70) + (char)param_2;
  this->TauntDir[0] = '\0';
  TTaunt::RestartSoundSystem(this,in_EAX);
  this->Mute = 0;
  return this;
}

// --------------------------------------------------

// Function: FUN_00509474
// Address: 00509474
void __fastcall FUN_00509474(undefined4 *param_1)
{
  TDigital *this;
  int iVar1;
  
  iVar1 = 4;
  do {
    this = (TDigital *)*param_1;
    if (this != (TDigital *)0x0) {
      TDigital::~TDigital(this);
      operator_delete(this);
      *param_1 = 0;
    }
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_00509485
// Address: 00509485
int __thiscall FUN_00509485(TTaunt *param_1,char *param_2,char param_3)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  pcVar4 = "!MUTE";
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar2 = __strnicmp(param_2,&DAT_00576548,~uVar3 - 1);
  if ((iVar2 == 0) && (param_3 != '\0')) {
    param_1->Mute = 1;
  }
  uVar3 = 0xffffffff;
  pcVar4 = "!NOMUTE";
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar2 = __strnicmp(param_2,&DAT_00576550,~uVar3 - 1);
  if ((iVar2 == 0) && (param_3 != '\0')) {
    param_1->Mute = 0;
  }
  if (param_1->Mute != 0) {
    return 0;
  }
  iVar2 = TTaunt::GetTauntNo(param_1,param_2);
  if (iVar2 != 0) {
    TTaunt::PlayTauntNo(param_1,iVar2);
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0050952c
// Address: 0050952c
// [HELPER] s__sTaunt__3d_wav: "%sTaunt%.3d.wav"
int __thiscall FUN_0050952c(undefined4 *param_1,int param_2)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  char acStack_80 [128];
  
  if (((param_1[0x65] == 0) && ((int)param_1 + 0x113 != 0)) && (param_2 != 0)) {
    sprintf(acStack_80,s__sTaunt__3d_wav,(int)param_1 + 0x113,param_2);
    iVar3 = 4;
    puVar2 = param_1;
    do {
      if (((TDigital *)*puVar2 != (TDigital *)0x0) &&
         (iVar1 = TDigital::is_playing((TDigital *)*puVar2), iVar1 == 0)) {
        TDigital::unload((TDigital *)*puVar2);
      }
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 0;
    puVar2 = param_1;
    while (((TDigital *)*puVar2 == (TDigital *)0x0 ||
           (iVar1 = TDigital::is_playing((TDigital *)*puVar2), iVar1 != 0))) {
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
      if (3 < iVar3) {
        return 0;
      }
    }
    iVar1 = TDigital::load((TDigital *)param_1[iVar3],acStack_80,-1);
    if (iVar1 == 0) {
      TDigital::unload((TDigital *)param_1[iVar3]);
      return 0;
    }
    iVar3 = TDigital::play((TDigital *)param_1[iVar3]);
    return iVar3;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00509601
// Address: 00509601
uint FUN_00509601(char *param_1)
{
  uint uVar1;
  
  if (*param_1 == '!') {
    param_1 = param_1 + 1;
  }
  uVar1 = atoi(param_1);
  if (uVar1 == 0) {
    return 0;
  }
  return uVar1 & (999 < (int)uVar1) - 1;
}

// --------------------------------------------------

// Function: FUN_0050963a
// Address: 0050963a
// [HELPER] s_Taunts_you_: "Taunts you!"
char * __fastcall FUN_0050963a(int param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  pcVar4 = &s_Taunts_you_;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = (char *)(param_1 + 0x14);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return (char *)(param_1 + 0x14);
}

// --------------------------------------------------

// Function: FUN_0050966e
// Address: 0050966e
void __fastcall FUN_0050966e(undefined4 *param_1)
{
  TDigital *this;
  int iVar1;
  
  iVar1 = 4;
  do {
    this = (TDigital *)*param_1;
    if (this != (TDigital *)0x0) {
      TDigital::~TDigital(this);
      operator_delete(this);
      *param_1 = 0;
    }
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_00509719
// Address: 00509719
RGE_Command * __thiscall
FUN_00509719(RGE_Command *param_1,RGE_Game_World *param_2,TCommunications_Handler *param_3)
{
  RGE_Command::RGE_Command(param_1,param_2,param_3);
  param_1->_padding_ = (int)&TRIBE_Command::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00509765
// Address: 00509765
// [HELPER] s_C__msdev_work_age1_x1_tcommand_c: "C:\msdev\work\age1_x1\tcommand.cpp"
void __thiscall FUN_00509765(RGE_Command *param_1,TRIBE_Command_Build *param_2)
{
  debug_rand(s_C__msdev_work_age1_x1_tcommand_c,0x3f);
  switch(param_2->command) {
  case '\x04':
    TRIBE_Command::do_command_tribe_create((TRIBE_Command *)param_1,(RGE_Command_Create *)param_2);
    return;
  default:
    RGE_Command::do_command(param_1,param_2);
    return;
  case 'd':
    TRIBE_Command::do_command_make((TRIBE_Command *)param_1,(TRIBE_Command_Make *)param_2);
    return;
  case 'e':
    TRIBE_Command::do_command_research((TRIBE_Command *)param_1,(TRIBE_Command_Research *)param_2);
    return;
  case 'f':
    TRIBE_Command::do_command_build((TRIBE_Command *)param_1,param_2);
    return;
  case 'g':
    TRIBE_Command::do_command_game((TRIBE_Command *)param_1,(TRIBE_Command_Game *)param_2);
    return;
  case 'h':
    TRIBE_Command::do_command_explore((TRIBE_Command *)param_1,(TRIBE_Command_Explore *)param_2);
    return;
  case 'i':
    TRIBE_Command::do_command_build_wall
              ((TRIBE_Command *)param_1,(TRIBE_Command_Build_Wall *)param_2);
    return;
  case 'j':
    TRIBE_Command::do_command_cancel_build
              ((TRIBE_Command *)param_1,(TRIBE_Command_Cancel_Build *)param_2);
    return;
  case 'k':
    TRIBE_Command::do_command_attack_ground
              ((TRIBE_Command *)param_1,(TRIBE_Command_Attack_Ground *)param_2);
    return;
  case 'l':
    (**(code **)(param_1->_padding_ + 0x10))(param_2);
    return;
  case 'm':
    TRIBE_Command::do_command_trade_attribute
              ((TRIBE_Command *)param_1,(TRIBE_Command_Trade_Attribute *)param_2);
    return;
  case 'n':
    TRIBE_Command::do_command_repair((TRIBE_Command *)param_1,(TRIBE_Command_Repair *)param_2);
    return;
  case 'o':
    TRIBE_Command::do_command_unload((TRIBE_Command *)param_1,(TRIBE_Command_Unload *)param_2);
    return;
  case 'w':
    TRIBE_Command::do_command_queue((TRIBE_Command *)param_1,(TRIBE_Command_Queue *)param_2);
    return;
  }
}

// --------------------------------------------------

// Function: FUN_00509859
// Address: 00509859
void __fastcall FUN_00509859(undefined4 param_1,int *param_2)
{
  undefined4 uVar1;
  char *pcVar2;
  TRIBE_Building_Object *this;
  byte bVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  byte *unaff_EBX;
  int unaff_EBP;
  int iVar7;
  undefined4 unaff_EDI;
  undefined2 in_CS;
  int iStack_1b8;
  
  uVar1 = in((short)param_2);
  *(char *)(unaff_EBP + -0x4effaf69) =
       *(char *)(unaff_EBP + -0x4effaf69) + (char)((uint)unaff_EDI >> 8);
  cVar6 = (char)((uint)unaff_EBX >> 8);
  *(char *)(unaff_EBP + -0x1effaf69) = *(char *)(unaff_EBP + -0x1effaf69) + cVar6;
  bVar3 = (char)param_1 * '\x02' + cVar6;
  cRam11005098 = cRam11005098 + (char)uVar1;
  cRam29005098 = cRam29005098 + (char)unaff_EBX;
  cRam41005098 = cRam41005098 + (char)((uint)param_2 >> 8);
  pcVar2 = (char *)(int)(short)uVar1;
  *(char *)(unaff_EBP + -0x68) = *(char *)(unaff_EBP + -0x68) + bVar3;
  *pcVar2 = *pcVar2 + (char)uVar1;
  *param_2 = (int)(pcVar2 + *param_2);
  iVar4 = CONCAT31((int3)(CONCAT22((short)((uint)param_1 >> 0x10),
                                   CONCAT11((char)((uint)param_1 >> 8) + (char)param_2,(char)param_1
                                           )) >> 8),bVar3 | *unaff_EBX);
  iStack_1b8 = CONCAT22(iStack_1b8._2_2_,in_CS);
  iVar5 = (uint)*(byte *)(iStack_1b8 + 4) * 4;
  iVar7 = *(short *)(iStack_1b8 + 2) * 4;
  if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 0x40) + iVar5) + 0x24) +
                        iVar7) + 0x68) == '\x01') {
    *(undefined4 *)(iStack_1b8 + 0x10) = 0x40800000;
  }
  iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 4) + 0x40) + iVar5);
  this = (TRIBE_Building_Object *)
         (**(code **)(**(int **)(*(int *)(iVar4 + 0x24) + iVar7) + 0x18))
                   (iVar4,*(undefined4 *)(iStack_1b8 + 8),*(undefined4 *)(iStack_1b8 + 0xc),
                    *(undefined4 *)(iStack_1b8 + 0x10));
  if (*(char *)(this->_padding_ + 4) == 'P') {
    TRIBE_Building_Object::build(this,10000.0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050997c
// Address: 0050997c
void __thiscall FUN_0050997c(int param_1,int param_2)
{
  int *piVar1;
  TRIBE_Building_Object *this;
  int iVar2;
  UnitAIModule *pUVar3;
  undefined4 *unaff_FS_OFFSET;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  short sStack_78;
  short sStack_76;
  TRIBE_Action_Make_Obj *pTStack_74;
  char acStack_70 [100];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar4 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560dcb;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Building_Object *)
         RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),*(int *)(param_2 + 4));
  if (this == (TRIBE_Building_Object *)0x0) {
    piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)*(byte *)(iVar4 + 8) * 4);
  }
  else {
    TRIBE_Building_Object::work_status(this,(short *)&param_2,&sStack_76,&sStack_78,acStack_70,100);
    if (((short)param_2 != 0x67) && ((short)param_2 != 0x66)) {
      pTStack_74 = (TRIBE_Action_Make_Obj *)operator_new(0x50);
      uStack_4 = 0;
      if (pTStack_74 == (TRIBE_Action_Make_Obj *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj
                          (pTStack_74,(RGE_Action_Object *)this,*(short *)(iVar4 + 10),
                           *(int *)(iVar4 + 0xc),'\0');
      }
      uStack_4 = 0xffffffff;
      if (iVar2 != 0) {
        (**(code **)(this->_padding_ + 0x208))(iVar2);
      }
      pUVar3 = RGE_Static_Object::unitAI((RGE_Static_Object *)this);
      if (pUVar3 != (UnitAIModule *)0x0) {
        iVar2 = 0x26c;
        pUVar3 = RGE_Static_Object::unitAI((RGE_Static_Object *)this);
        UnitAIModule::setCurrentAction(pUVar3,iVar2);
        iVar4 = *(int *)(iVar4 + 0xc);
        fVar7 = -1.0;
        fVar6 = -1.0;
        fVar5 = -1.0;
        iVar2 = -1;
        pUVar3 = RGE_Static_Object::unitAI((RGE_Static_Object *)this);
        UnitAIModule::setCurrentTarget(pUVar3,iVar4,iVar2,fVar5,fVar6,fVar7);
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
      goto LAB_00509ada;
    }
    piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)*(byte *)(iVar4 + 8) * 4);
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10c))
              (0,(int)*(short *)(iVar4 + 10),*(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar4 + 0xc)
              );
  }
LAB_00509ada:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00509aee
// Address: 00509aee
void __thiscall FUN_00509aee(int param_1,int param_2)
{
  int *piVar1;
  TRIBE_Building_Object *this;
  int iVar2;
  UnitAIModule *pUVar3;
  undefined4 *unaff_FS_OFFSET;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  short sStack_78;
  short sStack_76;
  TRIBE_Action_Make_Tech *pTStack_74;
  char acStack_70 [100];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar4 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560deb;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Building_Object *)
         RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),*(int *)(param_2 + 4));
  if (this == (TRIBE_Building_Object *)0x0) {
    piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)*(byte *)(iVar4 + 8) * 4);
  }
  else {
    TRIBE_Building_Object::work_status(this,(short *)&param_2,&sStack_76,&sStack_78,acStack_70,100);
    if (((short)param_2 != 0x67) && ((short)param_2 != 0x66)) {
      pTStack_74 = (TRIBE_Action_Make_Tech *)operator_new(0x48);
      uStack_4 = 0;
      if (pTStack_74 == (TRIBE_Action_Make_Tech *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech
                          (pTStack_74,(RGE_Action_Object *)this,*(short *)(iVar4 + 10),
                           *(int *)(iVar4 + 0xc));
      }
      uStack_4 = 0xffffffff;
      if (iVar2 != 0) {
        (**(code **)(this->_padding_ + 0x208))(iVar2);
      }
      pUVar3 = RGE_Static_Object::unitAI((RGE_Static_Object *)this);
      if (pUVar3 != (UnitAIModule *)0x0) {
        iVar2 = 0x26c;
        pUVar3 = RGE_Static_Object::unitAI((RGE_Static_Object *)this);
        UnitAIModule::setCurrentAction(pUVar3,iVar2);
        iVar4 = *(int *)(iVar4 + 0xc);
        fVar7 = -1.0;
        fVar6 = -1.0;
        fVar5 = -1.0;
        iVar2 = -1;
        pUVar3 = RGE_Static_Object::unitAI((RGE_Static_Object *)this);
        UnitAIModule::setCurrentTarget(pUVar3,iVar4,iVar2,fVar5,fVar6,fVar7);
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
      goto LAB_00509c48;
    }
    piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)*(byte *)(iVar4 + 8) * 4);
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x118))
              ((int)*(short *)(iVar4 + 10),*(undefined4 *)(iVar4 + 4),0xffffffff,
               *(undefined4 *)(iVar4 + 0xc));
  }
LAB_00509c48:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00509c5c
// Address: 00509c5c
void __thiscall FUN_00509c5c(int param_1,int param_2)
{
  TRIBE_Player *this;
  int *piVar1;
  int iVar2;
  byte bVar3;
  uchar uVar4;
  RGE_Static_Object *pRVar5;
  undefined1 *puVar6;
  long *plVar7;
  RGE_Command *pRVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  undefined1 auStack_8 [8];
  
  this = *(TRIBE_Player **)
          (*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)*(byte *)(param_2 + 2) * 4);
  if (((this != (TRIBE_Player *)0x0) && (*(short *)(param_2 + 0xc) != -1)) &&
     (piVar1 = *(int **)(this->_padding_ + *(short *)(param_2 + 0xc) * 4), piVar1 != (int *)0x0)) {
    iVar2 = *piVar1;
    iVar11 = 1;
    uVar9 = 1;
    puVar6 = auStack_8;
    pRVar8 = (RGE_Command *)0x1;
    bVar3 = (**(code **)(iVar2 + 0x20))
                      (this,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),puVar6,1,1,1,1
                       ,1,1);
    uVar10 = (uint)bVar3;
    if (bVar3 == 0) {
      uVar4 = TRIBE_Player::pay_obj_cost(this,*(short *)(param_2 + 0xc),1.0,0);
      if (uVar4 == '\0') {
        if (0 < iVar11) {
          pRVar5 = RGE_Command::get_obj(pRVar8,(RGE_Obj_Info)*(long *)(param_2 + 0x14));
          if (pRVar5 != (RGE_Static_Object *)0x0) {
            (**(code **)(this->_padding_ + 0x100))
                      (0,uVar9,(int)*(short *)(param_2 + 0xc),*(undefined4 *)(param_2 + 4),
                       *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0x10),pRVar5->id);
            return;
          }
        }
      }
      else {
        pRVar8 = *(RGE_Command **)(param_2 + 0x10);
        uVar9 = (**(code **)(iVar2 + 0x3c))
                          (this,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),0);
        if (0 < (int)puVar6) {
          plVar7 = (long *)(param_2 + 0x14);
          do {
            pRVar5 = RGE_Command::get_obj(pRVar8,(RGE_Obj_Info)*plVar7);
            if (pRVar5 != (RGE_Static_Object *)0x0) {
              RGE_Static_Object::removeAllFromPathingGroup(pRVar5);
              (**(code **)(pRVar5->_padding_ + 0x98))
                        (uVar9,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),0);
            }
            plVar7 = plVar7 + 1;
            puVar6 = puVar6 + -1;
          } while (puVar6 != (undefined1 *)0x0);
        }
      }
    }
    else if (0 < iVar11) {
      pRVar5 = RGE_Command::get_obj(pRVar8,(RGE_Obj_Info)*(long *)(param_2 + 0x14));
      if (pRVar5 != (RGE_Static_Object *)0x0) {
        (**(code **)(this->_padding_ + 0x100))
                  (uVar10 & 0xff,uVar9,(int)*(short *)(param_2 + 0xc),*(undefined4 *)(param_2 + 4),
                   *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0x10),pRVar5->id);
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00509e02
// Address: 00509e02
void __thiscall FUN_00509e02(RGE_Command *param_1,RGE_Static_Object *param_2)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  TRIBE_Player *pTVar4;
  TRIBE_Master_Building_Object *pTVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  RGE_Static_Object *pRVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  RGE_Sprite **ppRVar14;
  RGE_Player *pRVar15;
  uint uVar16;
  
  pRVar10 = param_2;
  uVar13 = (uint)*(byte *)((int)&param_2->_padding_ + 1);
  ppRVar14 = &param_2->sprite;
  pTVar4 = (TRIBE_Player *)param_1->world->players[*(byte *)((int)&param_2->_padding_ + 2)];
  if (pTVar4 == (TRIBE_Player *)0x0) {
    return;
  }
  if (*(short *)&param_2->master_obj == -1) {
    return;
  }
  pTVar5 = *(TRIBE_Master_Building_Object **)
            (pTVar4->_padding_ + *(short *)&param_2->master_obj * 4);
  if (pTVar5 == (TRIBE_Master_Building_Object *)0x0) {
    return;
  }
  uVar16 = (uint)*(byte *)((int)&param_2->id + 2);
  uVar9 = (uint)(byte)param_2->id;
  uVar11 = (int)(uVar16 - uVar9) >> 0x1f;
  param_2 = (RGE_Static_Object *)0x0;
  iVar6 = (uVar16 - uVar9 ^ uVar11) - uVar11;
  uVar8 = (uint)*(byte *)((int)&pRVar10->_padding_ + 3);
  uVar11 = (uint)*(byte *)((int)&pRVar10->id + 1);
  uVar12 = (int)(uVar11 - uVar8) >> 0x1f;
  iVar7 = (uVar11 - uVar8 ^ uVar12) - uVar12;
  if (iVar6 == iVar7) {
    pRVar15 = pRVar10->owner;
  }
  else {
    if (iVar6 < iVar7) {
      TRIBE_Command::place_line_of_walls
                ((TRIBE_Command *)param_1,pTVar4,pTVar5,(int)pRVar10->owner,uVar8,uVar9,uVar11,uVar9
                 ,&param_2);
      bVar1 = *(byte *)((int)&pRVar10->id + 2);
      bVar2 = (byte)pRVar10->id;
      if (bVar2 < bVar1) {
        bVar3 = *(byte *)((int)&pRVar10->id + 1);
        uVar9 = bVar2 + 1;
      }
      else {
        if (bVar2 <= bVar1) goto LAB_00509fae;
        bVar3 = *(byte *)((int)&pRVar10->id + 1);
        uVar9 = bVar2 - 1;
      }
      uVar8 = (uint)bVar3;
      uVar16 = (uint)bVar1;
      uVar11 = uVar8;
    }
    else {
      TRIBE_Command::place_line_of_walls
                ((TRIBE_Command *)param_1,pTVar4,pTVar5,(int)pRVar10->owner,uVar8,uVar9,uVar8,uVar16
                 ,&param_2);
      bVar1 = *(byte *)((int)&pRVar10->id + 1);
      bVar2 = *(byte *)((int)&pRVar10->_padding_ + 3);
      if (bVar2 < bVar1) {
        uVar9 = (uint)*(byte *)((int)&pRVar10->id + 2);
        uVar8 = bVar2 + 1;
        uVar11 = (uint)bVar1;
        uVar16 = uVar9;
      }
      else {
        if (bVar2 <= bVar1) goto LAB_00509fae;
        uVar9 = (uint)*(byte *)((int)&pRVar10->id + 2);
        uVar8 = bVar2 - 1;
        uVar11 = (uint)bVar1;
        uVar16 = uVar9;
      }
    }
    pRVar15 = pRVar10->owner;
  }
  TRIBE_Command::place_line_of_walls
            ((TRIBE_Command *)param_1,pTVar4,pTVar5,(int)pRVar15,uVar8,uVar9,uVar11,uVar16,&param_2)
  ;
LAB_00509fae:
  if (param_2 != (RGE_Static_Object *)0x0) {
    for (; uVar13 != 0; uVar13 = uVar13 - 1) {
      pRVar10 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*ppRVar14);
      if (pRVar10 != (RGE_Static_Object *)0x0) {
        RGE_Static_Object::removeAllFromPathingGroup(pRVar10);
        (**(code **)(pRVar10->_padding_ + 0x98))(param_2,param_2->world_x,param_2->world_y,0);
      }
      ppRVar14 = ppRVar14 + 1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a004
// Address: 0050a004
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050a004(TRIBE_Player *param_1,int *param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6,int param_7,int *param_8)
{
  code *pcVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  uchar uVar5;
  int iVar6;
  int iStack_c;
  int iStack_8;
  
  iVar6 = param_4;
  if (param_4 == param_6) {
    iStack_c = 0;
  }
  else {
    iStack_c = ((param_6 <= param_4) - 1 & 2) - 1;
  }
  if (param_5 == param_7) {
    iStack_8 = 0;
  }
  else {
    iStack_8 = ((param_7 <= param_5) - 1 & 2) - 1;
  }
  param_4 = param_5;
  param_5 = iVar6;
  pcVar1 = *(code **)(*param_2 + 0x20);
  while( true ) {
    fVar2 = (float)param_5 - _DAT_00576570;
    fVar3 = (float)param_4 - _DAT_00576570;
    cVar4 = (*pcVar1)(param_1,fVar2,fVar3,0,1,(char)param_2[0x19],0,1,1,1);
    if (cVar4 == '\0') {
      uVar5 = TRIBE_Player::pay_obj_cost(param_1,(short)param_2[4],1.0,0);
      if (uVar5 == '\0') {
        return;
      }
      iVar6 = (**(code **)(*param_2 + 0x3c))(param_1,fVar2,fVar3,0,param_3);
      if ((iVar6 != 0) && (*param_8 == 0)) {
        *param_8 = iVar6;
      }
    }
    if ((param_5 == param_6) && (param_4 == param_7)) break;
    param_5 = param_5 + iStack_c;
    param_4 = param_4 + iStack_8;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a133
// Address: 0050a133
void __thiscall FUN_0050a133(RGE_Command *param_1,int param_2)
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *this;
  undefined4 uVar4;
  long *plVar5;
  
  iVar3 = param_2;
  plVar5 = (long *)(param_2 + 0xc);
  if ((param_1->world->players[*(byte *)(param_2 + 2)] != (RGE_Player *)0x0) &&
     (pcVar1 = (char *)(param_2 + 1), param_2 = 0, *pcVar1 != '\0')) {
    do {
      this = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plVar5);
      if (this != (RGE_Static_Object *)0x0) {
        RGE_Static_Object::removeAllFromPathingGroup(this);
        iVar2 = this->_padding_;
        uVar4 = __ftol(1);
        uVar4 = __ftol(uVar4);
        (**(code **)(iVar2 + 0x17c))(uVar4);
      }
      param_2 = param_2 + 1;
      plVar5 = plVar5 + 1;
    } while (param_2 < (int)(uint)*(byte *)(iVar3 + 1));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a1c8
// Address: 0050a1c8
// [HELPER] s_: ""
// [HELPER] s_Temp_Screen: "Temp Screen"
// [HELPER] s_syncerr_d_gam: "syncerr%d.gam"
void __thiscall FUN_0050a1c8(int param_1,int param_2)
{
  TDrawSystem *this;
  uchar uVar1;
  TRIBE_Screen_Status_Message *this_00;
  int iVar2;
  TEasy_Panel *this_01;
  void *pvVar3;
  undefined4 *unaff_FS_OFFSET;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560e0e;
  *unaff_FS_OFFSET = &uStack_c;
  switch(*(undefined1 *)(param_2 + 1)) {
  case 0:
    uVar1 = __ftol();
    RGE_Player::set_relation
              (*(RGE_Player **)
                (*(int *)(*(int *)(param_1 + 4) + 0x40) + *(short *)(param_2 + 2) * 4),
               (int)*(short *)(param_2 + 4),uVar1);
    (**(code **)(rge_base_game->_padding_ + 0x40))
              (8,(int)*(short *)(param_2 + 2),(int)*(short *)(param_2 + 4),
               (int)*(short *)(param_2 + 0xc),0);
    RGE_Game_World::update_mutual_allies(*(RGE_Game_World **)(param_1 + 4));
    break;
  case 1:
    RGE_Game_World::set_game_speed(*(RGE_Game_World **)(param_1 + 4),*(float *)(param_2 + 8));
    break;
  case 2:
    (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) + *(short *)(param_2 + 2) * 4) +
                0x78))(CONCAT22((short)((uint)*(undefined4 *)(param_2 + 8) >> 0x10),
                                *(undefined2 *)(param_2 + 4)),*(undefined4 *)(param_2 + 8),0);
    break;
  case 4:
    rge_base_game->quick_build = (int)*(short *)(param_2 + 2);
    break;
  case 5:
    RGE_Player::set_allied_victory
              (*(RGE_Player **)
                (*(int *)(*(int *)(param_1 + 4) + 0x40) + *(short *)(param_2 + 2) * 4),
               *(uchar *)(param_2 + 4));
    break;
  case 6:
    TRIBE_World::cheat(*(TRIBE_World **)(param_1 + 4),*(short *)(param_2 + 2),
                       (ushort)*(byte *)(param_2 + 4));
    break;
  case 7:
    (**(code **)(**(int **)(*(int *)(param_1 + 4) + 0x4c) + 8))
              (0x71,*(undefined4 *)
                     (*(int *)(*(int *)(param_1 + 4) + 0x40) + *(short *)(param_2 + 2) * 4));
    break;
  case 8:
    out_of_sync2 = 1;
    this_00 = (TRIBE_Screen_Status_Message *)operator_new(0x47c);
    uStack_4 = 0;
    if (this_00 != (TRIBE_Screen_Status_Message *)0x0) {
      TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message
                (this_00,s_Temp_Screen,s_,(char *)0x0,-1);
    }
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Temp_Screen,0);
    TRIBE_Game::close_game_screens((TRIBE_Game *)rge_base_game,1);
    if (do_debug_random != 0) {
      debug_random_write();
      dump_vismap_log();
      if (actionFile != (_iobuf *)0x0) {
        fclose(actionFile);
        actionFile = (_iobuf *)0x0;
      }
      if (DVlogf != (_iobuf *)0x0) {
        fclose(DVlogf);
        DVlogf = (_iobuf *)0x0;
      }
      if (DDlogf != (_iobuf *)0x0) {
        fclose(DDlogf);
        DDlogf = (_iobuf *)0x0;
      }
    }
    iVar2 = TCommunications_Handler::WhoAmI(comm);
    sprintf(acStack_110,s_syncerr_d_gam,iVar2);
    TRIBE_Game::save_game((TRIBE_Game *)rge_base_game,acStack_110);
    RGE_Player::loss_if_game_on
              (*(RGE_Player **)
                (*(int *)(*(int *)(param_1 + 4) + 0x40) +
                *(short *)(*(int *)(param_1 + 4) + 0x7c) * 4));
    TRIBE_Game::do_game_over((TRIBE_Game *)rge_base_game);
    this_01 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
    if (this_01 != (TEasy_Panel *)0x0) {
      this = rge_base_game->draw_system;
      pvVar3 = TEasy_Panel::get_palette(this_01);
      TDrawSystem::SetPalette(this,pvVar3);
      RGE_Base_Game::set_render_all(rge_base_game);
      RGE_Base_Game::draw_window(rge_base_game);
      TEasy_Panel::popupOKDialog(this_01,0x966,(char *)0x0,0x1c2,100);
    }
    TPanelSystem::destroyPanel(&panel_system,s_Temp_Screen);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0050a465
// Address: 0050a465
void __fastcall FUN_0050a465(int param_1,undefined4 param_2)
{
  byte bVar1;
  byte bVar2;
  undefined4 in_EAX;
  RGE_Static_Object *pRVar5;
  char *unaff_EBX;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  byte in_CF;
  byte in_AF;
  int iVar6;
  int iVar7;
  int iVar8;
  char cVar3;
  int iVar4;
  
  bVar1 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  bVar2 = (byte)in_EAX + bVar1 * '\x06';
  cVar3 = bVar2 + (0x90 < (bVar2 & 0xf0) | in_CF | bVar1 * (0xf9 < bVar2)) * '`';
  iVar4 = CONCAT31((int3)((uint)in_EAX >> 8),cVar3);
  cRam0c0050a4 = cRam0c0050a4 + (char)param_1;
  cRama2720050 = cVar3;
  cRama41e0050 = cVar3;
  iRama44b0050 = iVar4;
  *unaff_EBX = *unaff_EBX + (char)((uint)param_2 >> 8) + (char)((uint)param_1 >> 8);
  *unaff_EDI = *unaff_ESI;
  unaff_EBX[-0x6fffaf5e] = unaff_EBX[-0x6fffaf5e] + cVar3;
  iVar6 = iVar4;
  iVar7 = iVar4;
  iVar8 = iVar4;
  pRVar5 = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),*(int *)(iVar4 + 4));
  if (pRVar5 != (RGE_Static_Object *)0x0) {
    (**(code **)(pRVar5->_padding_ + 0x240))(iVar4,iVar6,iVar7,iVar8);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a4b1
// Address: 0050a4b1
void __thiscall FUN_0050a4b1(RGE_Command *param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  uint uVar2;
  long *plVar3;
  
  plVar3 = (long *)(param_2 + 0xc);
  for (uVar2 = (uint)*(byte *)(param_2 + 1); uVar2 != 0; uVar2 = uVar2 - 1) {
    pRVar1 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plVar3);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 0x14c))
                (*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),0,1);
    }
    plVar3 = plVar3 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a509
// Address: 0050a509
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0050a509(int param_1,undefined4 param_2,float param_3)
{
  float *pfVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  float fVar7;
  float unaff_EBX;
  float unaff_ESI;
  float fStack_4;
  
  iVar5 = (int)param_3;
  fStack_4 = 0.0;
  if (*(float *)((int)param_3 + 4) < _DAT_00576574) {
    param_3 = 0.0;
  }
  else {
    param_3 = *(float *)((int)param_3 + 4);
  }
  if ((float)_DAT_00576578 < param_3) {
    fStack_4 = *(float *)(iVar5 + 8) * param_3;
  }
  bVar2 = *(byte *)(iVar5 + 3);
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x40);
  iVar4 = *(int *)(*(int *)(iVar3 + (uint)*(byte *)(iVar5 + 1) * 4) + 0x50);
  pfVar1 = (float *)(iVar4 + (uint)bVar2 * 4);
  if (*(float *)(iVar4 + (uint)bVar2 * 4) < param_3 + fStack_4) {
    param_3 = *pfVar1 - *pfVar1 * *(float *)(iVar5 + 8);
  }
  fVar7 = (float)CONCAT22((short)((uint)param_2 >> 0x10),(ushort)bVar2);
  (**(code **)(**(int **)(iVar3 + (uint)*(byte *)(iVar5 + 2) * 4) + 0x78))(fVar7,param_3,0);
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x40);
  (**(code **)(**(int **)(iVar3 + (uint)*(byte *)(iVar5 + 1) * 4) + 0x78))
            (CONCAT22((short)((uint)iVar3 >> 0x10),(ushort)*(byte *)(iVar5 + 3)),
             -(unaff_EBX + unaff_ESI),0);
  (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)*(byte *)(iVar5 + 1) * 4) +
              0x78))(0x35,param_3,0);
  (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)*(byte *)(iVar5 + 2) * 4) +
              0x78))(0x35,-fVar7,0);
  iVar3 = rge_base_game->_padding_;
  uVar6 = __ftol();
  (**(code **)(iVar3 + 0x40))
            (7,*(undefined1 *)(iVar5 + 1),*(undefined1 *)(iVar5 + 2),*(undefined1 *)(iVar5 + 3),
             uVar6);
  bVar2 = *(byte *)(iVar5 + 2);
  iVar3 = **(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)bVar2 * 4);
  uVar6 = __ftol(0);
  (**(code **)(iVar3 + 0xe8))
            (*(undefined1 *)(iVar5 + 1),(uint)bVar2,0x20a,*(undefined1 *)(iVar5 + 3),uVar6);
  return;
}

// --------------------------------------------------

// Function: FUN_0050a695
// Address: 0050a695
void __thiscall FUN_0050a695(RGE_Command *param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  uint uVar2;
  long *plVar3;
  
  plVar3 = (long *)(param_2 + 8);
  for (uVar2 = (uint)*(byte *)(param_2 + 1); uVar2 != 0; uVar2 = uVar2 - 1) {
    pRVar1 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plVar3);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      pRVar1->attribute_type_held = *(short *)(param_2 + 4);
    }
    plVar3 = plVar3 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a6db
// Address: 0050a6db
void __thiscall FUN_0050a6db(RGE_Command *param_1,int param_2)
{
  byte bVar1;
  RGE_Static_Object *pRVar2;
  TRIBE_Combat_Object *this;
  long *plVar3;
  uint uVar4;
  
  bVar1 = *(byte *)(param_2 + 1);
  plVar3 = (long *)(param_2 + 8);
  pRVar2 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*(long *)(param_2 + 4));
  for (uVar4 = (uint)bVar1; uVar4 != 0; uVar4 = uVar4 - 1) {
    this = (TRIBE_Combat_Object *)RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plVar3);
    if (this != (TRIBE_Combat_Object *)0x0) {
      TRIBE_Combat_Object::do_repair(this,pRVar2);
    }
    plVar3 = plVar3 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a728
// Address: 0050a728
void __thiscall FUN_0050a728(RGE_Command *param_1,int param_2)
{
  RGE_Static_Object *this;
  int iVar1;
  uint uVar2;
  long *plVar3;
  
  plVar3 = (long *)(param_2 + 0xc);
  for (uVar2 = (uint)*(byte *)(param_2 + 1); uVar2 != 0; uVar2 = uVar2 - 1) {
    this = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plVar3);
    if (this != (RGE_Static_Object *)0x0) {
      RGE_Static_Object::removeAllFromPathingGroup(this);
      iVar1 = (int)this->owner->id;
      (**(code **)(this->owner->_padding_ + 0x34))
                (iVar1,this->id,0x2d1,this->id,iVar1,*(undefined4 *)(param_2 + 4),
                 *(undefined4 *)(param_2 + 8),0,0x3f800000,1,0,100);
    }
    plVar3 = plVar3 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a7a9
// Address: 0050a7a9
void __thiscall FUN_0050a7a9(int param_1,int param_2)
{
  short sVar1;
  TRIBE_Building_Object *this;
  
  this = (TRIBE_Building_Object *)
         RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),*(int *)(param_2 + 4));
  if (this != (TRIBE_Building_Object *)0x0) {
    sVar1 = *(short *)(param_2 + 10);
    if (0 < sVar1) {
      TRIBE_Building_Object::add_to_production_queue(this,*(short *)(param_2 + 8),sVar1);
      return;
    }
    TRIBE_Building_Object::remove_from_production_queue(this,*(short *)(param_2 + 8),-sVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a85f
// Address: 0050a85f
// [HELPER] s_______: "      "
void __thiscall
FUN_0050a85f(RGE_Command *param_1,undefined4 param_2,int param_3,TDebuggingLog *param_4,
            undefined4 param_5)
{
  undefined1 *puVar1;
  
  if (-1 < param_3) {
    puVar1 = (undefined1 *)calloc(1,0x10);
    if (puVar1 != (undefined1 *)0x0) {
      *(int *)(puVar1 + 4) = param_3;
      puVar1[8] = (char)param_2;
      *puVar1 = 100;
      *(short *)(puVar1 + 10) = (short)param_4;
      *(undefined4 *)(puVar1 + 0xc) = param_5;
      TDebuggingLog::Log(param_4,(char *)L,s_______>SEND_CMD_MAKE2__PLR__d_BL,param_2,param_3,
                         param_4);
      RGE_Command::submit(param_1,puVar1,0x10);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a8c1
// Address: 0050a8c1
// [HELPER] s_______: "      "
void __thiscall FUN_0050a8c1(RGE_Command *param_1,int param_2,short param_3)
{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  if (param_2 != 0) {
    puVar2 = (undefined1 *)calloc(1,0x10);
    if (puVar2 != (undefined1 *)0x0) {
      *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(param_2 + 4);
      uVar1 = *(undefined1 *)(*(int *)(param_2 + 0xc) + 0x4a);
      *puVar2 = 0x65;
      puVar2[8] = uVar1;
      *(short *)(puVar2 + 10) = param_3;
      *(undefined4 *)(puVar2 + 0xc) = 0xffffffff;
      TDebuggingLog::Log(*(TDebuggingLog **)(param_2 + 8),(char *)L,
                         s_______>SEND_CMD_RESEARCH__UNIT__,
                         (*(TDebuggingLog **)(param_2 + 8))->LogToFile,(int)param_3);
      RGE_Command::submit(param_1,puVar2,0x10);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a93f
// Address: 0050a93f
// [HELPER] s_______: "      "
void __thiscall
FUN_0050a93f(RGE_Command *param_1,undefined4 param_2,int param_3,TDebuggingLog *param_4,
            undefined4 param_5)
{
  undefined1 *puVar1;
  
  if (-1 < param_3) {
    puVar1 = (undefined1 *)calloc(1,0x10);
    if (puVar1 != (undefined1 *)0x0) {
      *(int *)(puVar1 + 4) = param_3;
      puVar1[8] = (char)param_2;
      *puVar1 = 0x65;
      *(short *)(puVar1 + 10) = (short)param_4;
      *(undefined4 *)(puVar1 + 0xc) = param_5;
      TDebuggingLog::Log(param_4,(char *)L,s_______>SEND_CMD_RESEARCH2__PLR__,param_2,param_3,
                         param_4);
      RGE_Command::submit(param_1,puVar1,0x10);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a9a1
// Address: 0050a9a1
// [HELPER] s_______: "      "
void __thiscall
FUN_0050a9a1(RGE_Command *param_1,int *param_2,short param_3,short param_4,undefined4 param_5,
            undefined4 param_6)
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if ((param_2 != (int *)0x0) && (0 < param_3)) {
    iVar8 = (int)param_3;
    iVar1 = iVar8 * 4 + 0x14;
    puVar4 = (undefined1 *)calloc(1,iVar1);
    puVar5 = (undefined4 *)(puVar4 + 0x14);
    if (puVar4 != (undefined1 *)0x0) {
      if (0 < iVar8) {
        iVar6 = (int)param_2 - (int)puVar5;
        iVar7 = iVar8;
        do {
          iVar2 = *(int *)(iVar6 + (int)puVar5);
          if (iVar2 == 0) {
            *puVar5 = 0xffffffff;
          }
          else {
            *puVar5 = *(undefined4 *)(iVar2 + 4);
          }
          puVar5 = puVar5 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      *puVar4 = 0x66;
      puVar4[1] = (undefined1)param_3;
      if (*param_2 == 0) {
        uVar3 = 0xff;
      }
      else {
        uVar3 = (undefined1)*(undefined2 *)(*(int *)(*param_2 + 0xc) + 0x4a);
      }
      puVar4[2] = uVar3;
      *(short *)(puVar4 + 0xc) = param_4;
      *(undefined4 *)(puVar4 + 4) = param_5;
      *(undefined4 *)(puVar4 + 8) = param_6;
      *(undefined4 *)(puVar4 + 0x10) = 0xffffffff;
      TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_BUILD__CNT__d_OB,iVar8,(int)param_4);
      RGE_Command::submit(param_1,puVar4,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050aa88
// Address: 0050aa88
// [HELPER] s_______: "      "
void __thiscall
FUN_0050aa88(RGE_Command *param_1,undefined1 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,TDebuggingLog *param_8)
{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((param_3 != 0) && (0 < param_4)) {
    iVar1 = param_4 * 4 + 0x14;
    puVar2 = (undefined1 *)calloc(1,iVar1);
    puVar3 = (undefined4 *)(puVar2 + 0x14);
    if (puVar2 != (undefined1 *)0x0) {
      if (0 < param_4) {
        param_3 = param_3 - (int)puVar3;
        iVar4 = param_4;
        do {
          *puVar3 = *(undefined4 *)(param_3 + (int)puVar3);
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      *(undefined4 *)(puVar2 + 4) = param_6;
      *(undefined4 *)(puVar2 + 8) = param_7;
      *puVar2 = 0x66;
      puVar2[1] = (char)param_4;
      *(short *)(puVar2 + 0xc) = (short)param_5;
      *(TDebuggingLog **)(puVar2 + 0x10) = param_8;
      puVar2[2] = param_2;
      TDebuggingLog::Log(param_8,(char *)L,s_______>SEND_CMD_BUILD2__CNT__d_O,param_4,param_5);
      RGE_Command::submit(param_1,puVar2,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050ac64
// Address: 0050ac64
// [HELPER] s_______: "      "
void __thiscall
FUN_0050ac64(RGE_Command *param_1,undefined1 param_2,int param_3,int param_4,TDebuggingLog *param_5,
            undefined4 param_6)
{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((param_3 != 0) && (0 < param_4)) {
    iVar1 = param_4 * 4 + 0xc;
    puVar2 = (undefined1 *)calloc(1,iVar1);
    puVar3 = (undefined4 *)(puVar2 + 0xc);
    if (puVar2 != (undefined1 *)0x0) {
      if (0 < param_4) {
        param_3 = param_3 - (int)puVar3;
        iVar4 = param_4;
        do {
          *puVar3 = *(undefined4 *)(param_3 + (int)puVar3);
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      *puVar2 = 0x68;
      puVar2[1] = (char)param_4;
      puVar2[2] = param_2;
      *(TDebuggingLog **)(puVar2 + 4) = param_5;
      *(undefined4 *)(puVar2 + 8) = param_6;
      TDebuggingLog::Log(param_5,(char *)L,s_______>SEND_CMD_EXPLORE__CNT__d_,param_4);
      RGE_Command::submit(param_1,puVar2,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050acfc
// Address: 0050acfc
// [HELPER] s_______: "      "
void __thiscall FUN_0050acfc(RGE_Command *param_1,short param_2,byte param_3)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *(short *)(puVar1 + 2) = param_2;
    *(ushort *)(puVar1 + 4) = (ushort)param_3;
    *(undefined4 *)(puVar1 + 8) = 0;
    *puVar1 = 0x67;
    puVar1[1] = 5;
    TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_ALLIED_VIC__PLR_,(int)param_2,(uint)param_3);
    RGE_Command::submit(param_1,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050ad67
// Address: 0050ad67
// [HELPER] s_______: "      "
void __thiscall FUN_0050ad67(RGE_Command *param_1,short param_2,short param_3,short param_4)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *(short *)(puVar1 + 4) = param_3;
    *(short *)(puVar1 + 0xc) = param_4;
    *(float *)(puVar1 + 8) = (float)(int)param_4;
    *(short *)(puVar1 + 2) = param_2;
    *puVar1 = 0x67;
    puVar1[1] = 0;
    TDebuggingLog::Log((TDebuggingLog *)(int)param_3,(char *)L,s_______>SEND_CMD_RELATION__PLR__d,
                       (int)param_2,(TDebuggingLog *)(int)param_3,(int)param_4);
    RGE_Command::submit(param_1,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050ade3
// Address: 0050ade3
// [HELPER] s_______: "      "
void __thiscall FUN_0050ade3(RGE_Command *param_1,undefined4 param_2)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x67;
    *(undefined4 *)(puVar1 + 8) = param_2;
    puVar1[1] = 1;
    TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_GAME_SPD);
    RGE_Command::submit(param_1,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050ae37
// Address: 0050ae37
// [HELPER] s_______: "      "
void __fastcall FUN_0050ae37(RGE_Command *param_1)
{
  undefined1 *puVar1;
  TDebuggingLog *this;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x67;
    puVar1[1] = 8;
    TDebuggingLog::Log(this,(char *)L,s_______>SEND_CMD_SAVEGAME);
    RGE_Command::submit(param_1,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050ae7d
// Address: 0050ae7d
// [HELPER] s_______: "      "
void __thiscall FUN_0050ae7d(RGE_Command *param_1,short param_2,short param_3,undefined4 param_4)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *(short *)(puVar1 + 4) = param_3;
    *(undefined4 *)(puVar1 + 8) = param_4;
    *(short *)(puVar1 + 2) = param_2;
    *puVar1 = 0x67;
    puVar1[1] = 2;
    TDebuggingLog::Log((TDebuggingLog *)(int)param_3,(char *)L,s_______>SEND_CMD_INV__PLR__d_INV_,
                       (int)param_2,(TDebuggingLog *)(int)param_3);
    RGE_Command::submit(param_1,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050af29
// Address: 0050af29
// [HELPER] s_______: "      "
void __thiscall FUN_0050af29(RGE_Command *param_1,undefined2 param_2)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x67;
    *(undefined2 *)(puVar1 + 2) = param_2;
    puVar1[1] = 4;
    TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_QUICKBLD);
    RGE_Command::submit(param_1,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050af79
// Address: 0050af79
// [HELPER] s_______: "      "
void __thiscall FUN_0050af79(RGE_Command *param_1,undefined2 param_2)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x67;
    *(undefined2 *)(puVar1 + 2) = param_2;
    puVar1[1] = 7;
    TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_SHAREDLOS);
    RGE_Command::submit(param_1,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050afc9
// Address: 0050afc9
// [HELPER] s_______: "      "
void __thiscall FUN_0050afc9(RGE_Command *param_1,int param_2)
{
  TDebuggingLog *this;
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,8);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x6a;
    this = *(TDebuggingLog **)(param_2 + 4);
    *(TDebuggingLog **)(puVar1 + 4) = this;
    TDebuggingLog::Log(this,(char *)L,s_______>SEND_CMD_CANCELBLD);
    RGE_Command::submit(param_1,puVar1,8);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050b016
// Address: 0050b016
// [HELPER] s_______: "      "
void __thiscall
FUN_0050b016(RGE_Command *param_1,int param_2,short param_3,undefined4 param_4,
            TDebuggingLog *param_5)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  if ((param_2 != 0) && (0 < param_3)) {
    iVar6 = (int)param_3;
    iVar1 = iVar6 * 4 + 0xc;
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 0xc);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar6) {
        param_2 = param_2 - (int)puVar4;
        iVar5 = iVar6;
        do {
          iVar2 = *(int *)(param_2 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      *puVar3 = 0x6b;
      puVar3[1] = (undefined1)param_3;
      *(undefined4 *)(puVar3 + 4) = param_4;
      *(TDebuggingLog **)(puVar3 + 8) = param_5;
      TDebuggingLog::Log(param_5,(char *)L,s_______>SEND_CMD_ATTACK_GRND__CNT,iVar6);
      RGE_Command::submit(param_1,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050b0c2
// Address: 0050b0c2
// [HELPER] s_______: "      "
void __thiscall FUN_0050b0c2(RGE_Command *param_1,undefined2 param_2,short param_3)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x67;
    *(undefined2 *)(puVar1 + 2) = param_2;
    *(short *)(puVar1 + 4) = param_3;
    puVar1[1] = 6;
    TDebuggingLog::Log((TDebuggingLog *)(int)param_3,(char *)L,s_______>SEND_CMD_CHEAT__d,
                       (TDebuggingLog *)(int)param_3);
    RGE_Command::submit(param_1,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050b126
// Address: 0050b126
// [HELPER] s_______: "      "
void __thiscall
FUN_0050b126(RGE_Command *param_1,undefined4 param_2,TDebuggingLog *param_3,undefined1 param_4,
            undefined4 param_5,undefined4 param_6)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0xc);
  puVar1[3] = param_4;
  *(undefined4 *)(puVar1 + 4) = param_5;
  *puVar1 = 0x6c;
  puVar1[1] = (char)param_2;
  puVar1[2] = (char)param_3;
  *(undefined4 *)(puVar1 + 8) = param_6;
  TDebuggingLog::Log(param_3,(char *)L,s_______>SEND_CMD_GIVE_ATTR__PLR__,param_2,param_3);
  RGE_Command::submit(param_1,puVar1,0xc);
  return;
}

// --------------------------------------------------

// Function: FUN_0050b18c
// Address: 0050b18c
// [HELPER] s_______: "      "
void __thiscall FUN_0050b18c(RGE_Command *param_1,int param_2,short param_3,undefined4 param_4)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  if ((param_2 != 0) && (0 < param_3)) {
    iVar6 = (int)param_3;
    iVar1 = iVar6 * 4 + 8;
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 8);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar6) {
        param_2 = param_2 - (int)puVar4;
        iVar5 = iVar6;
        do {
          iVar2 = *(int *)(param_2 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      *puVar3 = 0x6d;
      puVar3[1] = (undefined1)param_3;
      *(undefined4 *)(puVar3 + 4) = param_4;
      TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_TRADE_ATTR__CNT_,iVar6);
      RGE_Command::submit(param_1,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050b227
// Address: 0050b227
// [HELPER] s_______: "      "
void __thiscall
FUN_0050b227(RGE_Command *param_1,TDebuggingLog *param_2,undefined4 param_3,undefined4 param_4)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0xc);
  if ((puVar1 != (undefined1 *)0x0) && ((undefined4 *)(puVar1 + 8) != (undefined4 *)0x0)) {
    *(TDebuggingLog **)(puVar1 + 8) = param_2;
    *puVar1 = 0x6d;
    puVar1[1] = 1;
    *(undefined4 *)(puVar1 + 4) = param_4;
    TDebuggingLog::Log(param_2,(char *)L,s_______>SEND_CMD_TRADE_ATTR2);
    RGE_Command::submit(param_1,puVar1,0xc);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050b283
// Address: 0050b283
// [HELPER] s_______: "      "
void __thiscall FUN_0050b283(RGE_Command *param_1,int param_2,short param_3,int param_4)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 extraout_ECX;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = (int)param_3;
  iVar1 = iVar7 * 4 + 8;
  if ((param_2 != 0) && (0 < param_3)) {
    puVar4 = (undefined1 *)calloc(1,iVar1);
    puVar5 = (undefined4 *)(puVar4 + 8);
    if (puVar4 != (undefined1 *)0x0) {
      uVar6 = extraout_ECX;
      if (0 < iVar7) {
        param_2 = param_2 - (int)puVar5;
        iVar8 = iVar7;
        do {
          iVar2 = *(int *)(param_2 + (int)puVar5);
          if (iVar2 == 0) {
            *puVar5 = 0xffffffff;
            uVar6 = 0;
          }
          else {
            uVar6 = *(undefined4 *)(iVar2 + 4);
            *puVar5 = uVar6;
          }
          puVar5 = puVar5 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      uVar3 = *(undefined4 *)(param_4 + 4);
      *puVar4 = 0x6e;
      *(undefined4 *)(puVar4 + 4) = uVar3;
      puVar4[1] = (undefined1)param_3;
      TDebuggingLog::Log((TDebuggingLog *)CONCAT31((int3)((uint)uVar6 >> 8),(undefined1)param_3),
                         (char *)L,s_______>SEND_CMD_REPAIR__CNT__d_,iVar7);
      RGE_Command::submit(param_1,puVar4,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050b32a
// Address: 0050b32a
// [HELPER] s_______: "      "
void __thiscall
FUN_0050b32a(RGE_Command *param_1,int param_2,short param_3,undefined4 param_4,
            TDebuggingLog *param_5)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  if ((param_2 != 0) && (0 < param_3)) {
    iVar6 = (int)param_3;
    iVar1 = iVar6 * 4 + 0xc;
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 0xc);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar6) {
        param_2 = param_2 - (int)puVar4;
        iVar5 = iVar6;
        do {
          iVar2 = *(int *)(param_2 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      *puVar3 = 0x6f;
      puVar3[1] = (undefined1)param_3;
      *(undefined4 *)(puVar3 + 4) = param_4;
      *(TDebuggingLog **)(puVar3 + 8) = param_5;
      TDebuggingLog::Log(param_5,(char *)L,s_______>SEND_CMD_UNLOAD__CNT__d_,iVar6);
      RGE_Command::submit(param_1,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050b3d2
// Address: 0050b3d2
// [HELPER] s_______: "      "
void __thiscall FUN_0050b3d2(RGE_Command *param_1,int param_2,short param_3,short param_4)
{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)calloc(1,0xc);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 0x77;
    uVar1 = *(undefined4 *)(param_2 + 4);
    *(short *)(puVar2 + 10) = param_4;
    *(undefined4 *)(puVar2 + 4) = uVar1;
    *(short *)(puVar2 + 8) = param_3;
    TDebuggingLog::Log((TDebuggingLog *)(int)param_3,(char *)L,s_______>SEND_CMD_QUEUE__B__d_T__d,
                       *(undefined4 *)(param_2 + 4),(TDebuggingLog *)(int)param_3,(int)param_4);
    RGE_Command::submit(param_1,puVar2,0xc);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050b443
// Address: 0050b443
RGE_Dialog_List * __thiscall FUN_0050b443(RGE_Dialog_List *param_1,char *param_2)
{
  RGE_Dialog_List::RGE_Dialog_List(param_1,param_2);
  param_1->_padding_ = (int)&TRIBE_Dialog_List::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050b469
// Address: 0050b469
TRIBE_Dialog_List * __thiscall FUN_0050b469(TRIBE_Dialog_List *param_1,byte param_2)
{
  TRIBE_Dialog_List::~TRIBE_Dialog_List(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050b495
// Address: 0050b495
void __fastcall FUN_0050b495(RGE_Dialog_List *param_1)
{
  int iVar1;
  
  iVar1 = param_1->list_type;
  if (iVar1 == 100) {
    TRIBE_Dialog_List::create_build_list((TRIBE_Dialog_List *)param_1);
    return;
  }
  if (iVar1 != 0x65) {
    if (iVar1 != 0x66) {
      RGE_Dialog_List::create_list(param_1);
      return;
    }
    TRIBE_Dialog_List::create_research_list((TRIBE_Dialog_List *)param_1);
    return;
  }
  TRIBE_Dialog_List::create_train_list((TRIBE_Dialog_List *)param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0050b4c5
// Address: 0050b4c5
undefined4 __fastcall FUN_0050b4c5(int param_1)
{
  char cVar1;
  short sVar2;
  TRIBE_Player *this;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  char *pcVar7;
  char *pcVar8;
  Item_Avail *pIStack_c;
  short asStack_8 [4];
  
  this = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  sVar6 = 0;
  if (this == (TRIBE_Player *)0x0) {
    return 0;
  }
  iVar3 = RGE_Player::is_group_selected((RGE_Player *)this,4);
  if (iVar3 == 0) {
    return 0;
  }
  pIStack_c = (Item_Avail *)0x0;
  asStack_8[0] = 0;
  asStack_8[1] = 0;
  TRIBE_Player::interface_item_avail(this,&pIStack_c,asStack_8,0x76);
  sVar2 = (short)asStack_8._0_4_;
  if (sVar2 == 0) {
    return 0;
  }
  *(short *)(param_1 + 0x4b0) = sVar2;
  iVar3 = calloc((int)sVar2,0x66);
  *(int *)(param_1 + 0x4b4) = iVar3;
  if (iVar3 == 0) {
    return 0;
  }
  if (0 < *(short *)(param_1 + 0x4b0)) {
    do {
      iVar3 = (int)sVar6;
      *(short *)(*(int *)(param_1 + 0x4b4) + 100 + iVar3 * 0x66) = pIStack_c[iVar3].id;
      uVar4 = 0xffffffff;
      pcVar7 = pIStack_c[iVar3].name;
      do {
        pcVar8 = pcVar7;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar7 = pcVar8 + -uVar4;
      pcVar8 = (char *)(*(int *)(param_1 + 0x4b4) + iVar3 * 0x66);
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      sVar6 = sVar6 + 1;
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
    } while (sVar6 < *(short *)(param_1 + 0x4b0));
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0050b5df
// Address: 0050b5df
undefined4 __fastcall FUN_0050b5df(int param_1)
{
  char cVar1;
  short sVar2;
  TRIBE_Player *this;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  char *pcVar7;
  char *pcVar8;
  Item_Avail *pIStack_c;
  short asStack_8 [4];
  
  this = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  sVar6 = 0;
  if ((this != (TRIBE_Player *)0x0) && (this->_padding_ != 0)) {
    iVar3 = RGE_Player::own_selected((RGE_Player *)this);
    if (iVar3 != 0) {
      pIStack_c = (Item_Avail *)0x0;
      asStack_8[0] = 0;
      asStack_8[1] = 0;
      TRIBE_Player::interface_item_avail
                (this,&pIStack_c,asStack_8,*(short *)(*(int *)(this->_padding_ + 8) + 0x10));
      sVar2 = (short)asStack_8._0_4_;
      if (sVar2 != 0) {
        *(short *)(param_1 + 0x4b0) = sVar2;
        iVar3 = calloc((int)sVar2,0x66);
        *(int *)(param_1 + 0x4b4) = iVar3;
        if (iVar3 != 0) {
          if (0 < *(short *)(param_1 + 0x4b0)) {
            do {
              iVar3 = (int)sVar6;
              *(short *)(*(int *)(param_1 + 0x4b4) + 100 + iVar3 * 0x66) = pIStack_c[iVar3].id;
              uVar4 = 0xffffffff;
              pcVar7 = pIStack_c[iVar3].name;
              do {
                pcVar8 = pcVar7;
                if (uVar4 == 0) break;
                uVar4 = uVar4 - 1;
                pcVar8 = pcVar7 + 1;
                cVar1 = *pcVar7;
                pcVar7 = pcVar8;
              } while (cVar1 != '\0');
              uVar4 = ~uVar4;
              pcVar7 = pcVar8 + -uVar4;
              pcVar8 = (char *)(*(int *)(param_1 + 0x4b4) + iVar3 * 0x66);
              for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar8 = pcVar8 + 4;
              }
              sVar6 = sVar6 + 1;
              for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                *pcVar8 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar8 = pcVar8 + 1;
              }
            } while (sVar6 < *(short *)(param_1 + 0x4b0));
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0050b6f5
// Address: 0050b6f5
undefined4 __fastcall FUN_0050b6f5(int param_1)
{
  char cVar1;
  short sVar2;
  TRIBE_Player *this;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  char *pcVar7;
  char *pcVar8;
  Item_Avail *pIStack_c;
  short asStack_8 [4];
  
  this = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  sVar6 = 0;
  if ((this != (TRIBE_Player *)0x0) && (this->_padding_ != 0)) {
    iVar3 = RGE_Player::own_selected((RGE_Player *)this);
    if (iVar3 != 0) {
      pIStack_c = (Item_Avail *)0x0;
      asStack_8[0] = 0;
      asStack_8[1] = 0;
      TRIBE_Player::interface_tech_avail
                (this,&pIStack_c,asStack_8,*(short *)(*(int *)(this->_padding_ + 8) + 0x10));
      sVar2 = (short)asStack_8._0_4_;
      if (sVar2 != 0) {
        *(short *)(param_1 + 0x4b0) = sVar2;
        iVar3 = calloc((int)sVar2,0x66);
        *(int *)(param_1 + 0x4b4) = iVar3;
        if (iVar3 != 0) {
          if (0 < *(short *)(param_1 + 0x4b0)) {
            do {
              iVar3 = (int)sVar6;
              *(short *)(*(int *)(param_1 + 0x4b4) + 100 + iVar3 * 0x66) = pIStack_c[iVar3].id;
              uVar4 = 0xffffffff;
              pcVar7 = pIStack_c[iVar3].name;
              do {
                pcVar8 = pcVar7;
                if (uVar4 == 0) break;
                uVar4 = uVar4 - 1;
                pcVar8 = pcVar7 + 1;
                cVar1 = *pcVar7;
                pcVar7 = pcVar8;
              } while (cVar1 != '\0');
              uVar4 = ~uVar4;
              pcVar7 = pcVar8 + -uVar4;
              pcVar8 = (char *)(*(int *)(param_1 + 0x4b4) + iVar3 * 0x66);
              for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar8 = pcVar8 + 4;
              }
              sVar6 = sVar6 + 1;
              for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                *pcVar8 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar8 = pcVar8 + 1;
              }
            } while (sVar6 < *(short *)(param_1 + 0x4b0));
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0050b815
// Address: 0050b815
short __fastcall FUN_0050b815(RGE_Dialog_List *param_1)
{
  int iVar1;
  short sVar2;
  
  iVar1 = param_1->list_type;
  if (((iVar1 != 100) && (iVar1 != 0x65)) && (iVar1 != 0x66)) {
    sVar2 = RGE_Dialog_List::get_cur_id(param_1);
    return sVar2;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0050b83b
// Address: 0050b83b
int * __thiscall FUN_0050b83b(int *param_1,int param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  short sStack_10;
  short asStack_c [2];
  short sStack_8;
  
  param_1[2] = param_3;
  rge_read(param_2,param_1 + 1,2);
  if ((short)param_1[1] < 1) {
    *param_1 = 0;
  }
  else {
    iVar1 = calloc(0x3c,(int)(short)param_1[1]);
    *param_1 = iVar1;
    for (sStack_8 = 0; sStack_8 < (short)param_1[1]; sStack_8 = sStack_8 + 1) {
      for (sStack_10 = 0; sStack_10 < 4; sStack_10 = sStack_10 + 1) {
        rge_read(param_2,(void *)(*param_1 + sStack_8 * 0x3c + 4 + sStack_10 * 2),2);
      }
      for (sStack_10 = 0; sStack_10 < 3; sStack_10 = sStack_10 + 1) {
        rge_read(param_2,(void *)(*param_1 + sStack_8 * 0x3c + 0xe + sStack_10 * 2),2);
        rge_read(param_2,(void *)(*param_1 + sStack_8 * 0x3c + 0x14 + sStack_10 * 2),2);
        rge_read(param_2,(void *)(*param_1 + sStack_8 * 0x3c + 0x1a + (int)sStack_10),1);
      }
      rge_read(param_2,(void *)(*param_1 + 0xc + sStack_8 * 0x3c),2);
      rge_read(param_2,(void *)(*param_1 + 0x28 + sStack_8 * 0x3c),2);
      rge_read(param_2,(void *)(*param_1 + 0x2a + sStack_8 * 0x3c),2);
      rge_read(param_2,(void *)(*param_1 + 0x2c + sStack_8 * 0x3c),2);
      rge_read(param_2,(void *)(*param_1 + 0x1e + sStack_8 * 0x3c),2);
      rge_read(param_2,(void *)(*param_1 + 0x20 + sStack_8 * 0x3c),2);
      rge_read(param_2,(void *)(*param_1 + 0x22 + sStack_8 * 0x3c),2);
      rge_read(param_2,(void *)(*param_1 + 0x24 + sStack_8 * 0x3c),2);
      rge_read(param_2,(void *)(*param_1 + 0x26 + sStack_8 * 0x3c),1);
      rge_read(param_2,(void *)(*param_1 + 0x30 + sStack_8 * 0x3c),4);
      rge_read(param_2,(void *)(*param_1 + 0x34 + sStack_8 * 0x3c),4);
      rge_read(param_2,(void *)(*param_1 + 0x38 + sStack_8 * 0x3c),4);
      rge_read(param_2,asStack_c,2);
      if (asStack_c[0] < 1) {
        *(undefined4 *)(*param_1 + sStack_8 * 0x3c) = 0;
      }
      else {
        uVar2 = calloc(1,(int)asStack_c[0]);
        *(undefined4 *)(*param_1 + sStack_8 * 0x3c) = uVar2;
        rge_read(param_2,*(void **)(*param_1 + sStack_8 * 0x3c),(int)asStack_c[0]);
      }
    }
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050d479
// Address: 0050d479
TRIBE_Effects * __thiscall FUN_0050d479(TRIBE_Effects *param_1,byte param_2)
{
  TRIBE_Effects::~TRIBE_Effects(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050d4a5
// Address: 0050d4a5
RGE_Effects * __thiscall FUN_0050d4a5(RGE_Effects *param_1,char *param_2)
{
  RGE_Effects::RGE_Effects(param_1,param_2);
  param_1->_padding_ = (int)&TRIBE_Effects::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050d4c9
// Address: 0050d4c9
void __thiscall FUN_0050d4c9(RGE_Effects *param_1,short param_2,TRIBE_Player *param_3)
{
  RGE_Effect *pRVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  uchar uVar5;
  
  if (((int)param_2 < param_1->effect_num) &&
     (pRVar1 = param_1->effects + param_2, pRVar1 != (RGE_Effect *)0x0)) {
    iVar3 = 0;
    if (0 < pRVar1->effect_list_num) {
      iVar4 = 0;
      do {
        uVar5 = (&pRVar1->effect_list->command)[iVar4];
        if ((uVar5 != 'e') && (uVar5 == 'f')) {
          uVar5 = '\0';
          lVar2 = __ftol();
          TRIBE_Player::tech_abling(param_3,lVar2,uVar5);
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar3 < pRVar1->effect_list_num);
    }
    RGE_Effects::do_effect(param_1,param_2,(RGE_Player *)param_3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050d549
// Address: 0050d549
void __thiscall FUN_0050d549(int param_1,short param_2,TRIBE_Player *param_3)
{
  int iVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  uchar uVar6;
  
  iVar4 = 0;
  iVar1 = *(int *)(param_1 + 4) + param_2 * 0x2c;
  if (0 < *(short *)(*(int *)(param_1 + 4) + 0x24 + param_2 * 0x2c)) {
    iVar5 = 0;
    do {
      cVar2 = *(char *)(*(int *)(iVar1 + 0x28) + iVar5);
      if ((cVar2 != 'e') && (cVar2 == 'f')) {
        uVar6 = '\0';
        lVar3 = __ftol();
        TRIBE_Player::tech_abling(param_3,lVar3,uVar6);
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0xc;
    } while (iVar4 < *(short *)(iVar1 + 0x24));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050d5aa
// Address: 0050d5aa
undefined4 * __thiscall FUN_0050d5aa(undefined4 *param_1,int param_2,undefined4 *param_3)
{
  short *psVar1;
  int iVar2;
  void *pvVar3;
  RGE_Static_Object *pRVar4;
  short sStack_e;
  undefined4 *puStack_c;
  int iStack_8;
  short *psStack_4;
  
  iVar2 = param_2;
  psVar1 = (short *)(param_1 + 3);
  *param_1 = &RGE_Timeline::_vftable_;
  puStack_c = param_1;
  psStack_4 = psVar1;
  rge_read(param_2,psVar1,2);
  rge_read(iVar2,(void *)((int)param_1 + 0xe),2);
  rge_read(iVar2,param_1 + 4,4);
  param_1[1] = param_3;
  param_1[2] = 0;
  iStack_8 = 0;
  param_3 = param_1 + 2;
  if (0 < *psVar1) {
    do {
      pvVar3 = (void *)calloc(1,0x30);
      rge_read(iVar2,pvVar3,4);
      rge_read(iVar2,(void *)((int)pvVar3 + 4),1);
      rge_read(iVar2,(void *)((int)pvVar3 + 6),2);
      rge_read(iVar2,(void *)((int)pvVar3 + 8),1);
      rge_read(iVar2,(void *)((int)pvVar3 + 0xc),4);
      rge_read(iVar2,(void *)((int)pvVar3 + 0x10),4);
      rge_read(iVar2,(void *)((int)pvVar3 + 0x14),4);
      rge_read(iVar2,(void *)((int)pvVar3 + 0x18),2);
      rge_read(iVar2,(short *)((int)pvVar3 + 0x20),2);
      rge_read(iVar2,&param_2,2);
      rge_read(iVar2,(short *)((int)pvVar3 + 0x28),2);
      rge_read(iVar2,&sStack_e,2);
      if (((short)param_2 < 0) || (puStack_c[1] == 0)) {
        *(undefined4 *)((int)pvVar3 + 0x1c) = 0;
      }
      else {
        pRVar4 = RGE_Object_List::find_by_id
                           (*(RGE_Object_List **)
                             (*(int *)(*(int *)(puStack_c[1] + 0x40) + (short)param_2 * 4) + 0x28),
                            (int)*(short *)((int)pvVar3 + 0x20));
        *(RGE_Static_Object **)((int)pvVar3 + 0x1c) = pRVar4;
      }
      if ((sStack_e < 0) || (puStack_c[1] == 0)) {
        *(undefined4 *)((int)pvVar3 + 0x24) = 0;
      }
      else {
        pRVar4 = RGE_Object_List::find_by_id
                           (*(RGE_Object_List **)
                             (*(int *)(*(int *)(puStack_c[1] + 0x40) + (short)param_2 * 4) + 0x28),
                            (int)*(short *)((int)pvVar3 + 0x28));
        *(RGE_Static_Object **)((int)pvVar3 + 0x24) = pRVar4;
      }
      *(undefined4 *)((int)pvVar3 + 0x2c) = 0;
      *param_3 = pvVar3;
      iStack_8 = iStack_8 + 1;
      param_1 = puStack_c;
      param_3 = (undefined4 *)((int)pvVar3 + 0x2c);
    } while (iStack_8 < *psStack_4);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050d787
// Address: 0050d787
RGE_Timeline * __thiscall FUN_0050d787(RGE_Timeline *param_1,byte param_2)
{
  RGE_Timeline::~RGE_Timeline(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050d7ae
// Address: 0050d7ae
void __thiscall FUN_0050d7ae(undefined4 *param_1,undefined4 param_2)
{
  param_1[1] = param_2;
  *param_1 = &RGE_Timeline::_vftable_;
  param_1[2] = 0;
  *(undefined2 *)(param_1 + 3) = 0;
  *(undefined2 *)((int)param_1 + 0xe) = 0;
  param_1[4] = 0xbf800000;
  return;
}

// --------------------------------------------------

// Function: FUN_0050d7d6
// Address: 0050d7d6
void __fastcall FUN_0050d7d6(undefined4 *param_1)
{
  int iVar1;
  
  iVar1 = param_1[2];
  *param_1 = &RGE_Timeline::_vftable_;
  while (iVar1 != 0) {
    iVar1 = *(int *)(param_1[2] + 0x2c);
    free(param_1[2]);
    param_1[2] = iVar1;
  }
  *(undefined2 *)((int)param_1 + 0xe) = 0;
  param_1[4] = 0xbf800000;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 3) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0050d826
// Address: 0050d826
void __thiscall FUN_0050d826(int param_1,int param_2)
{
  short *psVar1;
  int iVar2;
  int iVar3;
  int extraout_EDX;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined4 uStack_c;
  int iStack_8;
  short *psStack_4;
  
  iVar3 = param_2;
  psVar1 = (short *)(param_1 + 0xc);
  iStack_8 = param_1;
  psStack_4 = psVar1;
  rge_write(param_2,psVar1,2);
  rge_write(iVar3,(void *)(param_1 + 0xe),2);
  rge_write(iVar3,(void *)(param_1 + 0x10),4);
  iVar5 = 0;
  if (0 < *psVar1) {
    iVar6 = 0;
    iVar4 = extraout_EDX;
    do {
      pvVar7 = (void *)(*(int *)(param_1 + 8) + iVar6);
      iVar2 = *(int *)((int)pvVar7 + 0x1c);
      if (iVar2 == 0) {
        param_2 = 0xffffffff;
      }
      else {
        iVar4 = *(int *)(iVar2 + 0xc);
        param_2 = CONCAT22((short)((uint)iVar2 >> 0x10),*(undefined2 *)(iVar4 + 0x4a));
      }
      if (*(int *)((int)pvVar7 + 0x24) == 0) {
        uStack_c = 0xffffffff;
      }
      else {
        uStack_c = CONCAT22((short)((uint)iVar4 >> 0x10),
                            *(undefined2 *)(*(int *)(*(int *)((int)pvVar7 + 0x24) + 0xc) + 0x4a));
      }
      rge_write(iVar3,pvVar7,4);
      rge_write(iVar3,(void *)((int)pvVar7 + 4),1);
      rge_write(iVar3,(void *)((int)pvVar7 + 6),2);
      rge_write(iVar3,(void *)((int)pvVar7 + 8),1);
      rge_write(iVar3,(void *)((int)pvVar7 + 0xc),4);
      rge_write(iVar3,(void *)((int)pvVar7 + 0x10),4);
      rge_write(iVar3,(void *)((int)pvVar7 + 0x14),4);
      rge_write(iVar3,(void *)((int)pvVar7 + 0x18),2);
      rge_write(iVar3,(void *)((int)pvVar7 + 0x20),2);
      rge_write(iVar3,&param_2,2);
      rge_write(iVar3,(void *)((int)pvVar7 + 0x28),2);
      rge_write(iVar3,&uStack_c,2);
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x30;
      iVar4 = (int)*psStack_4;
      param_1 = iStack_8;
    } while (iVar5 < iVar4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050d993
// Address: 0050d993
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0050d993(int param_1)
{
  int iVar1;
  int *piVar2;
  float fVar3;
  undefined4 uVar4;
  float *pfVar5;
  float *pfVar6;
  
  pfVar6 = (float *)0x0;
  pfVar5 = *(float **)(param_1 + 8);
  fVar3 = (float)*(uint *)(*(int *)(param_1 + 4) + 4) * _DAT_005766f8;
  if (pfVar5 != (float *)0x0) {
    do {
      if ((pfVar6 == (float *)0x0) && (*(float *)(param_1 + 0x10) < *pfVar5)) {
        pfVar6 = pfVar5;
      }
      if ((pfVar5[7] != 0.0) && (7 < *(byte *)((int)pfVar5[7] + 0x48))) {
        pfVar5[7] = 0.0;
      }
      if ((pfVar5[9] != 0.0) && (7 < *(byte *)((int)pfVar5[9] + 0x48))) {
        pfVar5[9] = 0.0;
      }
      pfVar5 = (float *)pfVar5[0xb];
    } while (pfVar5 != (float *)0x0);
    for (; (pfVar6 != (float *)0x0 && (*pfVar6 <= fVar3)); pfVar6 = (float *)pfVar6[0xb]) {
      switch(*(undefined1 *)(pfVar6 + 1)) {
      case 0:
        if (((int *)pfVar6[7] != (int *)0x0) && (pfVar6[9] != 0.0)) {
          (**(code **)(*(int *)pfVar6[7] + 0xa8))(pfVar6[9]);
        }
        break;
      case 1:
        iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)*(byte *)(pfVar6 + 2) * 4);
        piVar2 = *(int **)(*(int *)(iVar1 + 0x24) + *(short *)((int)pfVar6 + 6) * 4);
        if (piVar2 != (int *)0x0) {
          uVar4 = (**(code **)(*piVar2 + 0x18))(iVar1,pfVar6[3],pfVar6[4],0);
          for (iVar1 = *(int *)(param_1 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
            if (*(short *)(pfVar6 + 8) == *(short *)(iVar1 + 0x20)) {
              *(undefined4 *)(iVar1 + 0x1c) = uVar4;
            }
            if (*(short *)(pfVar6 + 8) == *(short *)(iVar1 + 0x28)) {
              *(undefined4 *)(iVar1 + 0x24) = uVar4;
            }
          }
        }
        break;
      case 2:
        if ((int *)pfVar6[7] != (int *)0x0) {
          (**(code **)(*(int *)pfVar6[7] + 0x9c))(0,pfVar6[3],pfVar6[4],pfVar6[5]);
        }
        break;
      case 4:
        if ((int *)pfVar6[7] != (int *)0x0) {
          (**(code **)(*(int *)pfVar6[7] + 0x68))();
        }
      }
    }
  }
  *(float *)(param_1 + 0x10) = fVar3;
  return;
}

// --------------------------------------------------

// Function: FUN_0050daf5
// Address: 0050daf5
void __fastcall FUN_0050daf5(int param_1,int param_2)
{
  char *pcVar1;
  int unaff_EBX;
  
  pcVar1 = (char *)(param_2 + 0x50 + unaff_EBX * 8);
  *pcVar1 = *pcVar1 + (char)unaff_EBX;
  *(char *)(param_1 + -0x24ffaf26) = *(char *)(param_1 + -0x24ffaf26) + (char)((uint)param_2 >> 8);
  return;
}

// --------------------------------------------------

// Function: FUN_0050dd21
// Address: 0050dd21
undefined4 __thiscall FUN_0050dd21(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    return 0xffff;
  }
  while ((*(char *)(iVar1 + 4) != '\x01' || (*(int *)(iVar1 + 0x1c) != param_2))) {
    iVar1 = *(int *)(iVar1 + 0x2c);
    if (iVar1 == 0) {
      return 0xffff;
    }
  }
  return CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x20));
}

// --------------------------------------------------

// Function: FUN_0050dd63
// Address: 0050dd63
float * __thiscall FUN_0050dd63(int param_1,float param_2)
{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  
  pfVar1 = *(float **)(param_1 + 8);
  pfVar3 = (float *)(param_1 + 8);
  if (pfVar1 == (float *)0x0) {
    pfVar1 = (float *)calloc(1,0x30);
    *pfVar3 = (float)pfVar1;
    *pfVar1 = param_2;
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
    return (float *)*pfVar3;
  }
  do {
    if (param_2 < *pfVar1) {
      pfVar2 = (float *)calloc(1,0x30);
      *pfVar2 = param_2;
      pfVar2[0xb] = (float)pfVar1;
      *pfVar3 = (float)pfVar2;
      *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
      return pfVar2;
    }
    pfVar3 = pfVar1 + 0xb;
    pfVar1 = (float *)pfVar1[0xb];
  } while (pfVar1 != (float *)0x0);
  pfVar1 = (float *)calloc(1,0x30);
  *pfVar1 = param_2;
  pfVar1[0xb] = 0.0;
  *pfVar3 = (float)pfVar1;
  *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
  return pfVar1;
}

// --------------------------------------------------

// Function: FUN_0050ddf8
// Address: 0050ddf8
RGE_Time_Entry * __thiscall
FUN_0050ddf8(RGE_Timeline *param_1,float param_2,RGE_Static_Object *param_3,
            RGE_Static_Object *param_4)
{
  short sVar1;
  RGE_Time_Entry *pRVar2;
  
  pRVar2 = RGE_Timeline::add(param_1,param_2);
  if (pRVar2 != (RGE_Time_Entry *)0x0) {
    pRVar2->this_obj = param_3;
    pRVar2->player = (uchar)param_3->owner->id;
    sVar1 = RGE_Timeline::find_id(param_1,param_3);
    pRVar2->this_obj_id = sVar1;
    pRVar2->target_obj = param_4;
    sVar1 = RGE_Timeline::find_id(param_1,param_3);
    pRVar2->target_obj_id = sVar1;
    pRVar2->command = '\0';
  }
  return pRVar2;
}

// --------------------------------------------------

// Function: FUN_0050dee5
// Address: 0050dee5
RGE_Time_Entry * __thiscall
FUN_0050dee5(RGE_Timeline *param_1,float param_2,RGE_Static_Object *param_3,float param_4,
            float param_5,float param_6)
{
  short sVar1;
  RGE_Time_Entry *pRVar2;
  
  pRVar2 = RGE_Timeline::add(param_1,param_2);
  if (pRVar2 != (RGE_Time_Entry *)0x0) {
    pRVar2->player = (uchar)param_3->owner->id;
    pRVar2->this_obj = param_3;
    sVar1 = RGE_Timeline::find_id(param_1,param_3);
    pRVar2->this_obj_id = sVar1;
    pRVar2->x = param_4;
    pRVar2->y = param_5;
    pRVar2->z = param_6;
    pRVar2->command = '\x02';
  }
  return pRVar2;
}

// --------------------------------------------------

// Function: FUN_0050e034
// Address: 0050e034
TRIBE_Master_Building_Object * __thiscall
FUN_0050e034(TRIBE_Master_Building_Object *param_1,TRIBE_Master_Building_Object *param_2,int param_3
            )
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560e28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
            ((TRIBE_Master_Combat_Object *)param_1,(TRIBE_Master_Combat_Object *)param_2,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Master_Building_Object::_vftable_;
  if (param_3 != 0) {
    TRIBE_Master_Building_Object::setup(param_1,param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050e09d
// Address: 0050e09d
TRIBE_Master_Building_Object * __thiscall
FUN_0050e09d(TRIBE_Master_Building_Object *param_1,byte param_2)
{
  TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050e0be
// Address: 0050e0be
TRIBE_Master_Building_Object * __thiscall
FUN_0050e0be(TRIBE_Master_Building_Object *param_1,int param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560e48;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
            ((TRIBE_Master_Combat_Object *)param_1,param_2,param_3,param_4,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Master_Building_Object::_vftable_;
  if (param_5 != 0) {
    TRIBE_Master_Building_Object::setup(param_1,param_2,param_3,param_4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050e12d
// Address: 0050e12d
TRIBE_Master_Building_Object * __thiscall
FUN_0050e12d(TRIBE_Master_Building_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560e68;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
            ((TRIBE_Master_Combat_Object *)param_1,param_2,param_3,param_4,param_5,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Master_Building_Object::_vftable_;
  if (param_6 != 0) {
    TRIBE_Master_Building_Object::setup(param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050e1a7
// Address: 0050e1a7
undefined4 __thiscall
FUN_0050e1a7(TRIBE_Master_Combat_Object *param_1,TRIBE_Master_Combat_Object *param_2)
{
  TRIBE_Master_Combat_Object::setup(param_1,param_2);
  *(undefined1 *)&param_1->_padding_ = 0x50;
  param_1[1]._padding_ = param_2[1]._padding_;
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)((int)&param_2[1]._padding_ + 2);
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)((int)&param_2[1]._padding_ + 2);
  *(short *)&param_1[1]._padding_ = (short)param_2[1]._padding_;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)((int)&param_2[1]._padding_ + 2);
  *(short *)&param_1[1]._padding_ = (short)param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0050e242
// Address: 0050e242
undefined4 __thiscall
FUN_0050e242(TRIBE_Master_Combat_Object *param_1,int param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4)
{
  RGE_Sprite **ppRVar1;
  RGE_Sound **ppRVar2;
  RGE_Sprite *pRVar3;
  
  ppRVar2 = param_4;
  ppRVar1 = param_3;
  TRIBE_Master_Combat_Object::setup(param_1,param_2,param_3,param_4);
  *(undefined1 *)&param_1->_padding_ = 0x50;
  rge_read(param_2,&param_4,2);
  rge_read(param_2,&param_1[1]._padding_,1);
  rge_read(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_read(param_2,&param_1[1]._padding_,1);
  rge_read(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_read(param_2,&param_1[1]._padding_,2);
  rge_read(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_read(param_2,&param_1[1]._padding_,2);
  rge_read(param_2,&param_3,2);
  if ((short)param_4 < 0) {
    pRVar3 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar3 = ppRVar1[(short)param_4];
  }
  param_1[1]._padding_ = (int)pRVar3;
  if (-1 < (short)param_3) {
    param_1[1]._padding_ = (int)ppRVar2[(short)param_3];
    return 1;
  }
  param_1[1]._padding_ = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0050e35f
// Address: 0050e35f
// [HELPER] s__hd__hd__hd__hd__hd__hd__hd__hd_: "%hd %hd %hd %hd %hd %hd %hd %hd %hd"
undefined4 __thiscall
FUN_0050e35f(TRIBE_Master_Combat_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,undefined4 param_5)
{
  _iobuf *p_Var1;
  RGE_Sprite **ppRVar2;
  RGE_Sound **ppRVar3;
  RGE_Sprite *pRVar4;
  
  ppRVar3 = param_4;
  ppRVar2 = param_3;
  p_Var1 = param_2;
  TRIBE_Master_Combat_Object::setup(param_1,param_2,param_3,param_4,(short)param_5);
  *(undefined1 *)&param_1->_padding_ = 0x50;
  fscanf(p_Var1,s__hd__hd__hd__hd__hd__hd__hd__hd_,&param_3,&param_5,
         (undefined1 *)((int)&param_1[1]._padding_ + 2),&param_4,
         (undefined1 *)((int)&param_1[1]._padding_ + 2),&param_1[1]._padding_,
         (undefined1 *)((int)&param_1[1]._padding_ + 2),&param_1[1]._padding_,&param_2);
  *(undefined1 *)&param_1[1]._padding_ = (undefined1)param_5;
  *(undefined1 *)&param_1[1]._padding_ = param_4._0_1_;
  if ((short)param_3 < 0) {
    pRVar4 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar4 = ppRVar2[(short)param_3];
  }
  param_1[1]._padding_ = (int)pRVar4;
  if (-1 < (short)param_2) {
    param_1[1]._padding_ = (int)ppRVar3[(short)param_2];
    return 1;
  }
  param_1[1]._padding_ = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0050e42f
// Address: 0050e42f
void __fastcall FUN_0050e42f(TRIBE_Master_Combat_Object *param_1)
{
  param_1->_padding_ = (int)&TRIBE_Master_Building_Object::_vftable_;
  TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0050e43b
// Address: 0050e43b
void __thiscall FUN_0050e43b(TRIBE_Master_Combat_Object *param_1,RGE_Master_Static_Object *param_2)
{
  TRIBE_Master_Combat_Object::copy_obj(param_1,param_2);
  param_1[1]._padding_ = (int)param_2[1].outline_radius_y;
  param_1[1]._padding_ = (int)param_2[1].outline_radius_x;
  *(undefined1 *)&param_1[1]._padding_ = *(undefined1 *)&param_2[1].outline_radius_z;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) =
       *(undefined2 *)((int)&param_2[1].outline_radius_z + 2);
  *(char *)&param_1[1]._padding_ = (char)param_2[2]._padding_;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)((int)&param_2[2]._padding_ + 2);
  *(undefined2 *)&param_1[1]._padding_ = *(undefined2 *)&param_2[2].master_type;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)&param_2[2].field_0x6;
  *(undefined2 *)&param_1[1]._padding_ = *(undefined2 *)&param_2[2].name;
  return;
}

// --------------------------------------------------

// Function: FUN_0050e4c9
// Address: 0050e4c9
void __thiscall FUN_0050e4c9(TRIBE_Master_Combat_Object *param_1,float param_2,uchar param_3)
{
  undefined2 uVar1;
  
  if (param_3 != '\x11') {
    TRIBE_Master_Combat_Object::modify(param_1,param_2,param_3);
    return;
  }
  uVar1 = __ftol();
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0050e4fe
// Address: 0050e4fe
void __thiscall FUN_0050e4fe(TRIBE_Master_Combat_Object *param_1,float param_2,uchar param_3)
{
  short *psVar1;
  short sVar2;
  
  if (param_3 != '\x11') {
    TRIBE_Master_Combat_Object::modify_delta(param_1,param_2,param_3);
    return;
  }
  sVar2 = __ftol();
  psVar1 = (short *)((int)&param_1[1]._padding_ + 2);
  *psVar1 = *psVar1 + sVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_0050e52e
// Address: 0050e52e
void __thiscall FUN_0050e52e(TRIBE_Master_Combat_Object *param_1,float param_2,uchar param_3)
{
  TRIBE_Master_Combat_Object::modify_percent(param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0050e542
// Address: 0050e542
void __thiscall FUN_0050e542(TRIBE_Master_Combat_Object *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  TRIBE_Master_Combat_Object *pTStack_4;
  
  iVar2 = param_2;
  pTStack_4 = param_1;
  TRIBE_Master_Combat_Object::save(param_1,param_2);
  iVar1 = param_1[1]._padding_;
  pTStack_4 = (TRIBE_Master_Combat_Object *)0xffffffff;
  if (iVar1 == 0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x72));
  }
  if (param_1[1]._padding_ != 0) {
    pTStack_4 = (TRIBE_Master_Combat_Object *)
                CONCAT22(0xffff,*(undefined2 *)(param_1[1]._padding_ + 0xc));
  }
  rge_write(iVar2,&param_2,2);
  rge_write(iVar2,&param_1[1]._padding_,1);
  rge_write(iVar2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_write(iVar2,&param_1[1]._padding_,1);
  rge_write(iVar2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_write(iVar2,&param_1[1]._padding_,2);
  rge_write(iVar2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_write(iVar2,&param_1[1]._padding_,2);
  rge_write(iVar2,&pTStack_4,2);
  return;
}

// --------------------------------------------------

// Function: FUN_0050e6af
// Address: 0050e6af
undefined4 __thiscall
FUN_0050e6af(TRIBE_Master_Building_Object *param_1,RGE_Player *param_2,float param_3,float param_4,
            float param_5)
{
  TRIBE_Building_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560eab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Building_Object *)operator_new(0x204);
  uStack_4 = 0;
  if (this != (TRIBE_Building_Object *)0x0) {
    uVar1 = TRIBE_Building_Object::TRIBE_Building_Object
                      (this,param_1,param_2,param_3,param_4,param_5,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0050e72a
// Address: 0050e72a
undefined4 __fastcall FUN_0050e72a(TRIBE_Master_Building_Object *param_1)
{
  TRIBE_Master_Building_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560ecb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Master_Building_Object *)operator_new(0x17c);
  uStack_4 = 0;
  if (this != (TRIBE_Master_Building_Object *)0x0) {
    uVar1 = TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(this,param_1,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0050e792
// Address: 0050e792
void __thiscall
FUN_0050e792(int param_1,TDrawArea *param_2,undefined4 param_3,undefined4 param_4,
            RGE_Color_Table *param_5,int param_6,undefined4 param_7,int param_8,uint param_9)
{
  RGE_Map *this;
  short sVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  short sStack_10;
  short sStack_e;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (*(RGE_Sprite **)(param_1 + 0x18) != (RGE_Sprite *)0x0) {
    sVar3 = (short)param_4;
    sVar1 = (short)param_3;
    if (*(char *)(param_1 + 0x16c) == '\0') {
      iVar4 = (int)*(short *)(param_1 + 0x16e);
    }
    else if (param_6 == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = param_6 + -1;
    }
    iVar2 = (int)sVar3;
    fStack_4 = (float)param_1;
    RGE_Sprite::draw(*(RGE_Sprite **)(param_1 + 0x18),iVar4,0,(int)sVar1,iVar2,(int)sVar1,iVar2,
                     param_5,param_2,'\0');
    if (param_8 != 0) {
      fStack_c = *(float *)((int)fStack_4 + 0x30);
      this = rge_base_game->world->map;
      fStack_8 = *(float *)((int)fStack_4 + 0x34);
      fStack_4 = -fStack_8;
      RGE_Map::get_point(this,&sStack_e,&sStack_10,fStack_c,fStack_4,0.0,sVar1,sVar3);
      RGE_Map::get_point(this,(short *)&param_8,(short *)&param_6,fStack_c,fStack_8,0.0,sVar1,sVar3)
      ;
      fStack_c = -fStack_c;
      RGE_Map::get_point(this,(short *)&param_5,(short *)&param_2,fStack_c,fStack_8,0.0,sVar1,sVar3)
      ;
      RGE_Map::get_point(this,(short *)&param_3,(short *)&param_4,fStack_c,fStack_4,0.0,sVar1,sVar3)
      ;
      DClipInfo_List::AddGDINode
                (SDI_List,1,iVar2,(int)sStack_e,(int)sStack_10,(int)(short)param_8,
                 (int)(short)param_6,(int)(short)param_5,(int)(short)param_2,(int)(short)param_3,
                 (int)(short)param_4,10,param_9 & 0xff,SDI_Object_ID);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050e944
// Address: 0050e944
void __thiscall
FUN_0050e944(RGE_Master_Static_Object *param_1,float *param_2,float *param_3,RGE_Game_World *param_4
            )
{
  RGE_Master_Static_Object::alignment(param_1,param_2,param_3,param_4,'\x01');
  return;
}

// --------------------------------------------------

// Function: FUN_0050e969
// Address: 0050e969
TRIBE_Master_Combat_Object * __thiscall
FUN_0050e969(TRIBE_Master_Combat_Object *param_1,TRIBE_Master_Combat_Object *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560ee8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)param_1,(RGE_Master_Combat_Object *)param_2,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Master_Combat_Object::_vftable_;
  if (param_3 != 0) {
    TRIBE_Master_Combat_Object::setup(param_1,param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050e9cd
// Address: 0050e9cd
TRIBE_Master_Combat_Object * __thiscall
FUN_0050e9cd(TRIBE_Master_Combat_Object *param_1,byte param_2)
{
  TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050e9ee
// Address: 0050e9ee
TRIBE_Master_Combat_Object * __thiscall
FUN_0050e9ee(TRIBE_Master_Combat_Object *param_1,int param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560f08;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)param_1,param_2,param_3,param_4,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Master_Combat_Object::_vftable_;
  if (param_5 != 0) {
    TRIBE_Master_Combat_Object::setup(param_1,param_2,param_3,param_4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050ea5d
// Address: 0050ea5d
TRIBE_Master_Combat_Object * __thiscall
FUN_0050ea5d(TRIBE_Master_Combat_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560f28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)param_1,param_2,param_3,param_4,param_5,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Master_Combat_Object::_vftable_;
  if (param_6 != 0) {
    TRIBE_Master_Combat_Object::setup(param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050ead7
// Address: 0050ead7
undefined4 __thiscall
FUN_0050ead7(RGE_Master_Combat_Object *param_1,RGE_Master_Combat_Object *param_2)
{
  int *piVar1;
  RGE_Master_Combat_Object *pRVar2;
  int iVar3;
  
  RGE_Master_Combat_Object::setup(param_1,param_2);
  *(undefined1 *)&param_1->_padding_ = 0x46;
  iVar3 = 3;
  pRVar2 = param_1 + 1;
  do {
    piVar1 = (int *)(((int)param_2 - (int)param_1) + (int)pRVar2);
    iVar3 = iVar3 + -1;
    pRVar2->_padding_ = *piVar1;
    *(short *)&pRVar2->_padding_ = (short)piVar1[1];
    pRVar2 = (RGE_Master_Combat_Object *)((int)&pRVar2->_padding_ + 2);
  } while (iVar3 != 0);
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)((int)&param_2[1]._padding_ + 2);
  *(short *)&param_1[1]._padding_ = (short)param_2[1]._padding_;
  *(undefined1 *)((int)&param_1[1]._padding_ + 2) = *(undefined1 *)((int)&param_2[1]._padding_ + 2);
  *(short *)&param_1[1]._padding_ = (short)param_2[1]._padding_;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0050ec85
// Address: 0050ec85
// [HELPER] s__hd__hd__hd: "%hd %hd %hd"
undefined4 __thiscall
FUN_0050ec85(RGE_Master_Combat_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,undefined4 param_5)
{
  RGE_Armor_Weapon_Info *pRVar1;
  int iVar2;
  RGE_Master_Combat_Object *pRVar3;
  int iVar4;
  
  RGE_Master_Combat_Object::setup(param_1,param_2,param_3,param_4,(short)param_5);
  *(undefined1 *)&param_1->_padding_ = 0x46;
  pRVar3 = param_1 + 1;
  iVar2 = 3;
  do {
    fscanf(param_2,s__hd__hd__hd,pRVar3,(undefined1 *)((int)&pRVar3->_padding_ + 2),&param_5);
    *(undefined1 *)&pRVar3->_padding_ = (undefined1)param_5;
    pRVar3 = (RGE_Master_Combat_Object *)((int)&pRVar3->_padding_ + 2);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  fscanf(param_2,s__hd__hd__hd,(undefined1 *)((int)&param_1[1]._padding_ + 2),&param_1[1]._padding_,
         &param_4);
  iVar2 = (int)param_1->armor_num;
  *(undefined1 *)((int)&param_1[1]._padding_ + 2) = param_4._0_1_;
  *(undefined2 *)&param_1[1]._padding_ = 0;
  if (0 < iVar2) {
    pRVar1 = param_1->armor;
    iVar4 = iVar2;
    do {
      if ((pRVar1->type == 3) && ((short)param_1[1]._padding_ < pRVar1->value)) {
        *(short *)&param_1[1]._padding_ = pRVar1->value;
      }
      pRVar1 = pRVar1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  param_1->orig_armor = (ushort)param_1->base_armor;
  if (0 < iVar2) {
    pRVar1 = param_1->armor;
    do {
      if ((pRVar1->type != 3) && (param_1->orig_armor < pRVar1->value)) {
        param_1->orig_armor = pRVar1->value;
      }
      pRVar1 = pRVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0050ed91
// Address: 0050ed91
void __fastcall FUN_0050ed91(RGE_Master_Combat_Object *param_1)
{
  param_1->_padding_ = (int)&TRIBE_Master_Combat_Object::_vftable_;
  RGE_Master_Combat_Object::~RGE_Master_Combat_Object(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0050edab
// Address: 0050edab
RGE_Task_List * FUN_0050edab(void)
{
  RGE_Task_List *this;
  RGE_Task_List *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560f4b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Task_List *)operator_new(0xc);
  uStack_4 = 0;
  pRVar1 = (RGE_Task_List *)0x0;
  if (this != (RGE_Task_List *)0x0) {
    RGE_Task_List::RGE_Task_List(this);
    this->_padding_ = (int)&TRIBE_Task_List::_vftable_;
    pRVar1 = this;
  }
  *unaff_FS_OFFSET = uStack_c;
  return pRVar1;
}

// --------------------------------------------------

// Function: FUN_0050ee77
// Address: 0050ee77
void __thiscall FUN_0050ee77(RGE_Master_Combat_Object *param_1,float param_2,uchar param_3)
{
  undefined2 uVar1;
  short *psVar2;
  short *psVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined2 *puVar7;
  
  if (param_3 == 'd') {
    puVar7 = (undefined2 *)((int)&param_1[1]._padding_ + 2);
    iVar6 = 3;
    do {
      if (*(char *)(puVar7 + 1) != '\0') {
        uVar1 = __ftol();
        *puVar7 = uVar1;
      }
      puVar7 = puVar7 + 3;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    return;
  }
  if (param_3 != 'e') {
    RGE_Master_Combat_Object::modify(param_1,param_2,param_3);
    return;
  }
  puVar7 = (undefined2 *)((int)&param_1[1]._padding_ + 2);
  iVar6 = 3;
  do {
    if (*(char *)(puVar7 + 1) == '\0') {
      uVar1 = __ftol();
      *puVar7 = uVar1;
    }
    puVar7 = puVar7 + 3;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  piVar5 = &param_1->_padding_;
  psVar3 = (short *)((int)&param_1->_padding_ + 2);
  iVar6 = 3;
  psVar2 = psVar3;
  piVar4 = piVar5;
  do {
    if (*psVar2 == 4) {
      *piVar4 = (int)param_2;
    }
    psVar2 = psVar2 + 1;
    piVar4 = piVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 3;
  psVar2 = psVar3;
  piVar4 = piVar5;
  do {
    if (*psVar2 == 0xb) {
      *piVar4 = (int)-param_2;
    }
    psVar2 = psVar2 + 1;
    piVar4 = piVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 3;
  do {
    if (*psVar3 == 0x13) {
      *piVar5 = (int)-param_2;
    }
    psVar3 = psVar3 + 1;
    piVar5 = piVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0050ef69
// Address: 0050ef69
void __thiscall FUN_0050ef69(RGE_Master_Combat_Object *param_1,float param_2,uchar param_3)
{
  short sVar1;
  short *psVar2;
  int iVar3;
  
  if (param_3 != 'd') {
    RGE_Master_Combat_Object::modify_delta(param_1,param_2,param_3);
    return;
  }
  psVar2 = (short *)((int)&param_1[1]._padding_ + 2);
  iVar3 = 3;
  do {
    if ((char)psVar2[1] != '\0') {
      sVar1 = __ftol();
      *psVar2 = *psVar2 + sVar1;
    }
    psVar2 = psVar2 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0050efb1
// Address: 0050efb1
void __thiscall FUN_0050efb1(RGE_Master_Combat_Object *param_1,float param_2,uchar param_3)
{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  
  if (param_3 != 'd') {
    RGE_Master_Combat_Object::modify_percent(param_1,param_2,param_3);
    return;
  }
  puVar2 = (undefined2 *)((int)&param_1[1]._padding_ + 2);
  iVar3 = 3;
  do {
    if (*(char *)(puVar2 + 1) != '\0') {
      uVar1 = __ftol();
      *puVar2 = uVar1;
    }
    puVar2 = puVar2 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0050f00c
// Address: 0050f00c
void __thiscall FUN_0050f00c(RGE_Master_Combat_Object *param_1,int param_2)
{
  int iVar1;
  RGE_Master_Combat_Object *pRVar2;
  
  RGE_Master_Combat_Object::save(param_1,param_2);
  pRVar2 = param_1 + 1;
  iVar1 = 3;
  do {
    rge_write(param_2,pRVar2,6);
    pRVar2 = (RGE_Master_Combat_Object *)((int)&pRVar2->_padding_ + 2);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  rge_write(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_write(param_2,&param_1[1]._padding_,2);
  rge_write(param_2,(void *)((int)&param_1[1]._padding_ + 2),1);
  rge_write(param_2,&param_1[1]._padding_,2);
  return;
}

// --------------------------------------------------

// Function: FUN_0050f08c
// Address: 0050f08c
undefined4 __thiscall
FUN_0050f08c(TRIBE_Master_Combat_Object *param_1,RGE_Player *param_2,float param_3,float param_4,
            float param_5)
{
  TRIBE_Combat_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560f6b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Combat_Object *)operator_new(0x1c8);
  uStack_4 = 0;
  if (this != (TRIBE_Combat_Object *)0x0) {
    uVar1 = TRIBE_Combat_Object::TRIBE_Combat_Object(this,param_1,param_2,param_3,param_4,param_5,1)
    ;
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0050f10a
// Address: 0050f10a
undefined4 __fastcall FUN_0050f10a(TRIBE_Master_Combat_Object *param_1)
{
  TRIBE_Master_Combat_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560f8b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Master_Combat_Object *)operator_new(0x164);
  uStack_4 = 0;
  if (this != (TRIBE_Master_Combat_Object *)0x0) {
    uVar1 = TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(this,param_1,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0050f172
// Address: 0050f172
RGE_Master_Static_Object * __thiscall
FUN_0050f172(RGE_Master_Static_Object *param_1,RGE_Master_Static_Object *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560fa8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object(param_1,param_2,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Master_Tree_Object::_vftable_;
  if (param_3 != 0) {
    RGE_Master_Static_Object::setup(param_1,param_2);
    param_1->master_type = 'Z';
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050f1e1
// Address: 0050f1e1
TRIBE_Master_Tree_Object * __thiscall FUN_0050f1e1(TRIBE_Master_Tree_Object *param_1,byte param_2)
{
  TRIBE_Master_Tree_Object::~TRIBE_Master_Tree_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050f215
// Address: 0050f215
RGE_Master_Static_Object * __thiscall
FUN_0050f215(RGE_Master_Static_Object *param_1,int param_2,RGE_Sprite **param_3,RGE_Sound **param_4,
            int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560fc8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object(param_1,param_2,param_3,param_4,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Master_Tree_Object::_vftable_;
  if (param_5 != 0) {
    RGE_Master_Static_Object::setup(param_1,param_2,param_3,param_4);
    param_1->master_type = 'Z';
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050f291
// Address: 0050f291
RGE_Master_Static_Object * __thiscall
FUN_0050f291(RGE_Master_Static_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560fe8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object(param_1,param_2,param_3,param_4,param_5,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Master_Tree_Object::_vftable_;
  if (param_6 != 0) {
    RGE_Master_Static_Object::setup(param_1,param_2,param_3,param_4,param_5);
    param_1->master_type = 'Z';
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050f31b
// Address: 0050f31b
undefined4 __thiscall
FUN_0050f31b(TRIBE_Master_Tree_Object *param_1,RGE_Player *param_2,float param_3,float param_4,
            float param_5)
{
  TRIBE_Tree_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056100b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Tree_Object *)operator_new(0x88);
  uStack_4 = 0;
  if (this != (TRIBE_Tree_Object *)0x0) {
    uVar1 = TRIBE_Tree_Object::TRIBE_Tree_Object(this,param_1,param_2,param_3,param_4,param_5,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0050f39a
// Address: 0050f39a
undefined4 __fastcall FUN_0050f39a(TRIBE_Master_Tree_Object *param_1)
{
  TRIBE_Master_Tree_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056102b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Master_Tree_Object *)operator_new(0xb8);
  uStack_4 = 0;
  if (this != (TRIBE_Master_Tree_Object *)0x0) {
    uVar1 = TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(this,param_1,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0050f402
// Address: 0050f402
TRIBE_Map * __thiscall FUN_0050f402(TRIBE_Map *param_1,int param_2,RGE_Sound **param_3,char param_4)
{
  float *pfVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561048;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Map::RGE_Map((RGE_Map *)param_1,param_2,param_3,'\0');
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Map::_vftable_;
  if (param_4 != '\0') {
    TRIBE_Map::data_load_random_map(param_1,param_2);
  }
  pfVar1 = &param_1->cliff_master_table[0].offset_y;
  param_1->old_cliff_x = -1;
  param_1->old_cliff_y = -1;
  param_1->safe_cliff_x = -1;
  param_1->safe_cliff_y = -1;
  iVar2 = 0x100;
  do {
    pfVar1[-1] = 0.0;
    *pfVar1 = 0.0;
    ((TRIBE_Cliff_Info *)(pfVar1 + -5))->info[0] = 0;
    pfVar1[-4] = 0.0;
    pfVar1[-3] = 0.0;
    pfVar1[-2] = 0.0;
    ((TRIBE_Master_Cliff_Info *)(pfVar1 + -9))->id = -1;
    pfVar1[-8] = -NAN;
    pfVar1[-7] = -NAN;
    pfVar1[-6] = -NAN;
    pfVar1 = pfVar1 + 10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TRIBE_Map::setup_cliff_type(param_1,1,0,0,0,0x108,0x10,-1,-1,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,0,1,0,0,0x108,0x12,-1,-1,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,0,0,1,0,0x108,0x11,-1,-1,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,0,0,0,1,0x108,0x13,-1,-1,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,-1,0,0,0,0x10a,0x14,-1,-1,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,0,-1,0,0,0x109,0x16,-1,-1,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,0,0,-1,0,0x10a,0x15,-1,-1,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,0,0,0,-1,0x109,0x17,-1,-1,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,-1,1,0,0,0x10e,0,-1,-1,1.5,2.0);
  TRIBE_Map::setup_cliff_type(param_1,0,-1,-1,0,0x110,9,-1,-1,1.0,2.0);
  TRIBE_Map::setup_cliff_type(param_1,0,0,1,-1,0x10c,6,-1,-1,1.0,1.5);
  TRIBE_Map::setup_cliff_type(param_1,1,0,0,1,0x108,3,-1,-1,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,1,-1,0,0,0x10b,0xc,-1,-1,2.0,1.5);
  TRIBE_Map::setup_cliff_type(param_1,0,1,1,0,0x108,0xf,-1,-1,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,0,0,-1,1,0x10d,0xe,-1,-1,1.5,1.0);
  TRIBE_Map::setup_cliff_type(param_1,-1,0,0,-1,0x10f,0xd,-1,-1,2.0,1.0);
  TRIBE_Map::setup_cliff_type(param_1,1,0,1,0,0x108,4,0x108,5,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,0,1,0,1,0x108,1,0x108,2,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,-1,0,-1,0,0x10a,0xb,0x10a,10,1.5,1.5);
  TRIBE_Map::setup_cliff_type(param_1,0,-1,0,-1,0x109,8,0x109,7,1.5,1.5);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050f735
// Address: 0050f735
TRIBE_Map * __thiscall FUN_0050f735(TRIBE_Map *param_1,byte param_2)
{
  TRIBE_Map::~TRIBE_Map(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050f75e
// Address: 0050f75e
RGE_Map * __thiscall
FUN_0050f75e(RGE_Map *param_1,char *param_2,undefined4 param_3,char *param_4,char *param_5,
            short param_6,short param_7,short param_8,RGE_Sound **param_9)
{
  RGE_Map::RGE_Map(param_1,param_2,param_4,param_5,param_6,param_7,param_8,param_9);
  param_1->_padding_ = (int)&TRIBE_Map::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050f799
// Address: 0050f799
void __fastcall FUN_0050f799(RGE_Map *param_1)
{
  param_1->_padding_ = (int)&TRIBE_Map::_vftable_;
  RGE_Map::~RGE_Map(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0050f7ab
// Address: 0050f7ab
void __thiscall FUN_0050f7ab(RGE_Map *param_1,int param_2)
{
  RGE_Map::save(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0050f7bd
// Address: 0050f7bd
void __thiscall
FUN_0050f7bd(TRIBE_Map *param_1,RGE_Player *param_2,RGE_Game_World *param_3,RGE_Player_Info *param_4
            ,uchar *param_5)
{
  param_1->rge_game_world = param_3;
  param_1->rge_player = param_2;
  param_1->zones = param_5;
  TRIBE_Map::map_generate(param_1,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_0050f7eb
// Address: 0050f7eb
void FUN_0050f7eb(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0050f7f3
// Address: 0050f7f3
void __thiscall FUN_0050f7f3(int param_1,int param_2)
{
  TRIBE_RMM_Database_Controller *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056106b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_RMM_Database_Controller *)operator_new(0x4f5c);
  uStack_4 = 0;
  if (this == (TRIBE_RMM_Database_Controller *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(this,param_2);
  }
  *(undefined4 *)(param_1 + 0x8dbc) = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0050f85e
// Address: 0050f85e
void __thiscall FUN_0050f85e(int param_1,char *param_2,char *param_3,char *param_4,char *param_5)
{
  TRIBE_RMM_Database_Controller *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056108b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_RMM_Database_Controller *)operator_new(0x4f5c);
  uStack_4 = 0;
  if (this == (TRIBE_RMM_Database_Controller *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller
                      (this,param_3,param_4,param_5,param_2);
  }
  *(undefined4 *)(param_1 + 0x8dbc) = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0050f8cd
// Address: 0050f8cd
void __thiscall FUN_0050f8cd(TRIBE_Map *param_1,short param_2,short param_3,RGE_Game_World *param_4)
{
  short sVar1;
  bool bVar2;
  bool bVar3;
  short sVar4;
  byte bVar5;
  short sVar6;
  int iVar7;
  byte *pbVar8;
  short sVar9;
  int iVar10;
  short sVar11;
  int *piVar12;
  
  sVar11 = param_3 + -1;
  sVar9 = param_3 + 1;
  iVar7 = *(int *)(param_1->_padding_ + param_3 * 4) + param_2 * 0x18;
  sVar1 = param_2 + -1;
  sVar6 = param_2 + 1;
  bVar2 = false;
  bVar3 = false;
  if (sVar1 < 0) {
    sVar1 = 0;
  }
  if (sVar11 < 0) {
    sVar11 = 0;
  }
  if (param_1->_padding_ <= (int)sVar6) {
    sVar6 = (short)param_1->_padding_ + -1;
  }
  if (param_1->_padding_ <= (int)sVar9) {
    sVar9 = (short)param_1->_padding_ + -1;
  }
  bVar5 = *(byte *)(iVar7 + 5) & 0x1f;
  if (bVar5 == 10) {
    piVar12 = (int *)(param_1->_padding_ + sVar11 * 4);
    iVar7 = *piVar12;
    if (sVar11 <= sVar9) {
      iVar10 = ((int)sVar9 - (int)sVar11) + 1;
      do {
        if (sVar1 <= sVar6) {
          pbVar8 = (byte *)(sVar1 * 0x18 + iVar7 + 5);
          iVar7 = ((int)sVar6 - (int)sVar1) + 1;
          do {
            if (((*pbVar8 & 0x1f) != 10) && ((*pbVar8 & 0x1f) != 0x12)) {
              bVar3 = true;
            }
            pbVar8 = pbVar8 + 0x18;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        iVar7 = piVar12[1];
        piVar12 = piVar12 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    if (bVar3) {
      TRIBE_Map::change_terrain(param_1,param_2,param_3,'\x12',param_4);
    }
  }
  else if (bVar5 == 0x12) {
    for (piVar12 = *(int **)(iVar7 + 0x10); piVar12 != (int *)0x0; piVar12 = (int *)piVar12[1]) {
      if ((*(short *)(*(int *)(*piVar12 + 8) + 0x14) == 0xf) && (*(byte *)(*piVar12 + 0x48) < 8)) {
        bVar2 = true;
      }
    }
    if ((!bVar2) &&
       (TRIBE_Map::change_terrain(param_1,param_2,param_3,'\0',param_4), sVar4 = sVar1,
       sVar11 <= sVar9)) {
      do {
        for (; sVar4 <= sVar6; sVar4 = sVar4 + 1) {
          if ((sVar4 != param_2) || (sVar11 != param_3)) {
            TRIBE_Map::check_tile_for_forest_change(param_1,sVar4,sVar11,param_4);
          }
        }
        sVar11 = sVar11 + 1;
        sVar4 = sVar1;
      } while (sVar11 <= sVar9);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050fa82
// Address: 0050fa82
void __thiscall FUN_0050fa82(RGE_Map *param_1,short param_2,short param_3,byte param_4,int param_5)
{
  byte bVar1;
  byte bVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  int iStack_18;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  sVar6 = param_2;
  iVar5 = (int)param_3;
  iVar7 = (int)param_2;
  bVar1 = param_1->map_row_offset[iVar5][iVar7].field_0x5;
  param_1->map_row_offset[iVar5][iVar7].field_0x5 = (param_4 ^ bVar1) & 0x1f ^ bVar1;
  sVar4 = *(short *)(param_5 + 0x7c);
  if ((sVar4 < 1) || (*(short *)(param_5 + 0x3c) <= sVar4)) {
    _param_2 = 0;
  }
  else {
    _param_2 = *(int *)(*(int *)(param_5 + 0x40) + sVar4 * 4);
  }
  if ((_param_2 != 0) && (*(char *)(param_5 + 0x1d) != '\x03')) {
    RGE_Tile_List::add_node((RGE_Tile_List *)(_param_2 + 0x6c),iVar7,iVar5);
  }
  if (sVar6 == 0) {
    iStack_10 = 0;
  }
  else {
    iStack_10 = iVar7 + -1;
  }
  if (param_3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = iVar5 + -1;
  }
  if (iVar7 != param_1->map_width + -1) {
    sVar6 = sVar6 + 1;
  }
  sVar4 = param_3;
  if (iVar5 != param_1->map_height + -1) {
    sVar4 = param_3 + 1;
  }
  if ((short)iVar3 <= sVar4) {
    iStack_c = (int)(short)iVar3;
    iStack_8 = iStack_c * 4;
    _param_3 = iVar3;
    do {
      if ((short)iStack_10 <= sVar6) {
        iStack_18 = (int)(short)iStack_10;
        iVar7 = iStack_18 * 0x18;
        iVar5 = iStack_10;
        do {
          iVar3 = *(int *)(iStack_8 + (int)param_1->map_row_offset) + iVar7;
          bVar1 = *(byte *)(iVar3 + 6);
          RGE_Map::get_border_type(param_1,(short)iVar5,(short)_param_3);
          if ((_param_2 != 0) &&
             (((bVar2 = *(byte *)(iVar3 + 6), (bVar2 & 0xf) != (bVar1 & 0xf) ||
               (bVar2 >> 4 != bVar1 >> 4)) && (*(char *)(param_5 + 0x1d) != '\x03')))) {
            RGE_Tile_List::add_node((RGE_Tile_List *)(_param_2 + 0x6c),iStack_18,iStack_c);
          }
          iVar5 = iVar5 + 1;
          iStack_18 = iStack_18 + 1;
          iVar7 = iVar7 + 0x18;
        } while ((short)iVar5 <= sVar6);
      }
      _param_3 = _param_3 + 1;
      iStack_c = iStack_c + 1;
      iStack_8 = iStack_8 + 4;
    } while ((short)_param_3 <= sVar4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050fc3b
// Address: 0050fc3b
undefined4 __thiscall
FUN_0050fc3b(TRIBE_Map *param_1,int param_2,int param_3,int param_4,uchar param_5)
{
  int iVar1;
  uchar uVar2;
  undefined3 uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_4 + param_2;
  param_2 = param_2 - param_4;
  iVar4 = param_3 - param_4;
  param_4 = param_3 + param_4;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_1->_padding_ <= iVar5) {
    iVar5 = param_1->_padding_ + -1;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (param_1->_padding_ <= param_4) {
    param_4 = param_1->_padding_ + -1;
  }
  uVar2 = TRIBE_Map::water(param_1,param_5);
  uVar3 = (undefined3)((uint)param_4 >> 8);
  if (uVar2 == '\0') {
    for (; iVar1 = param_2, iVar4 <= param_4; iVar4 = iVar4 + 1) {
      for (; iVar1 <= iVar5; iVar1 = iVar1 + 1) {
        RGE_Map::set_terrain
                  ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,(short)iVar1,(short)iVar4
                   ,param_5,0,0);
      }
    }
  }
  else {
    iVar1 = param_2;
    if (iVar4 <= param_4) {
      do {
        for (; iVar1 <= iVar5; iVar1 = iVar1 + 1) {
          uVar2 = TRIBE_Map::do_terrain_brush_check(param_1,iVar1,iVar4);
          if (uVar2 != '\0') {
            RGE_Map::set_terrain
                      ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,(short)iVar1,
                       (short)iVar4,param_5,0,0);
          }
        }
        iVar4 = iVar4 + 1;
        iVar1 = param_2;
      } while (iVar4 <= param_4);
      return CONCAT31(uVar3,1);
    }
  }
  return CONCAT31(uVar3,1);
}

// --------------------------------------------------

// Function: FUN_0050fd38
// Address: 0050fd38
undefined4 __thiscall
FUN_0050fd38(TRIBE_Map *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            uchar param_7)
{
  int iVar1;
  int iVar2;
  
  RGE_Map::do_terrain_brush_stroke
            ((RGE_Map *)param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  if (param_2 < param_4) {
    iVar2 = param_2 - param_6;
  }
  else {
    iVar2 = param_4 - param_6;
    param_4 = param_2;
  }
  if (param_3 < param_5) {
    iVar1 = param_3 - param_6;
    param_5 = param_5 + param_6;
  }
  else {
    iVar1 = param_5 - param_6;
    param_5 = param_3 + param_6;
  }
  TRIBE_Map::tribe_clean_terrain
            (param_1,iVar2 + -2,iVar1 + -2,param_4 + param_6 + 2,param_5 + 2,'\x01',param_7);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0050fdc5
// Address: 0050fdc5
undefined4 __thiscall
FUN_0050fdc5(TRIBE_Map *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            byte param_7)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  RGE_Map::do_elevation_brush_stroke
            ((RGE_Map *)param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  if (param_2 < param_4) {
    iVar3 = param_2 - (param_6 + (uint)param_7);
    param_4 = param_4 + param_6 + (uint)param_7;
  }
  else {
    iVar3 = (param_4 - param_6) - (uint)param_7;
    param_4 = param_2 + param_6 + (uint)param_7;
  }
  uVar1 = (uint)param_7;
  if (param_3 < param_5) {
    iVar2 = param_3 - (param_6 + uVar1);
    param_5 = param_5 + param_6 + uVar1;
  }
  else {
    iVar2 = (param_5 - param_6) - uVar1;
    param_5 = param_3 + param_6 + uVar1;
  }
  TRIBE_Map::tribe_clean_elevation(param_1,iVar3 + -2,iVar2 + -2,param_4 + 2,param_5 + 2);
  TRIBE_Map::tribe_clean_terrain(param_1,iVar3 + -2,iVar2 + -2,param_4 + 2,param_5 + 2,'\x01','\0');
  return 1;
}

// --------------------------------------------------

// Function: FUN_0050fe8c
// Address: 0050fe8c
void __thiscall
FUN_0050fe8c(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,
            undefined4 param_11)
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_5 + 0x55 + (param_4 + (param_3 + param_2 * 4) * 4) * 4;
  iVar1 = param_1 + iVar2 * 0x28;
  *(undefined4 *)(iVar1 + 0x8df8) = param_6;
  *(undefined4 *)(iVar1 + 0x8dfc) = param_7;
  *(undefined4 *)(iVar1 + 0x8e00) = param_8;
  *(undefined4 *)(iVar1 + 0x8e04) = param_9;
  *(undefined4 *)(iVar1 + 0x8e18) = param_10;
  *(undefined4 *)(iVar1 + 0x8e1c) = param_11;
  *(int *)(param_1 + (iVar2 + 0x38d) * 0x28) = param_2;
  *(int *)(iVar1 + 0x8e0c) = param_3;
  *(int *)(iVar1 + 0x8e10) = param_4;
  *(int *)(iVar1 + 0x8e14) = param_5;
  return;
}

// --------------------------------------------------

// Function: FUN_0050ff19
// Address: 0050ff19
int * __thiscall FUN_0050ff19(int param_1,int param_2,int param_3)
{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if ((param_2 * 3 + 2 <= *(int *)(param_1 + 8)) &&
     (iVar5 = param_3 * 3 + 2, iVar5 <= *(int *)(param_1 + 0xc))) {
    iVar4 = (param_2 * 3 + 1) * 0x18;
    iVar2 = *(int *)(*(int *)(param_1 + 0x8d8c) + (param_3 * 3 + 1) * 4);
    for (piVar3 = *(int **)(iVar2 + 0x10 + iVar4); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[1])
{
      sVar1 = *(short *)(*(int *)(*piVar3 + 8) + 0x10);
      if ((0x107 < sVar1) && (sVar1 < 0x112)) goto LAB_00510005;
    }
    iVar5 = iVar4 + *(int *)(*(int *)(param_1 + 0x8d8c) + iVar5 * 4);
    for (piVar3 = *(int **)(iVar5 + 0x10); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[1]) {
      sVar1 = *(short *)(*(int *)(*piVar3 + 8) + 0x10);
      if ((0x107 < sVar1) && (sVar1 < 0x112)) goto LAB_00510005;
    }
    for (piVar3 = *(int **)(iVar2 + iVar4 + 0x28); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[1])
{
      sVar1 = *(short *)(*(int *)(*piVar3 + 8) + 0x10);
      if ((0x107 < sVar1) && (sVar1 < 0x112)) goto LAB_00510005;
    }
    piVar3 = *(int **)(iVar5 + 0x28);
    if (piVar3 != (int *)0x0) {
      while ((sVar1 = *(short *)(*(int *)(*piVar3 + 8) + 0x10), sVar1 < 0x108 || (0x111 < sVar1))) {
        piVar3 = (int *)piVar3[1];
        if (piVar3 == (int *)0x0) {
          return piVar3;
        }
      }
LAB_00510005:
      return (int *)*piVar3;
    }
  }
  return (int *)0x0;
}

// --------------------------------------------------

// Function: FUN_00510015
// Address: 00510015
void __thiscall FUN_00510015(int param_1,undefined4 *param_2,int param_3)
{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    return;
  }
  iVar3 = 0;
  uVar4 = (uint)*(short *)(*(int *)(param_3 + 8) + 0x10);
  puVar2 = (uint *)(param_1 + 0x8dfc);
  while (((puVar2[-1] != uVar4 || (*puVar2 != (uint)*(byte *)(param_3 + 0x35))) &&
         ((puVar2[1] != uVar4 || (puVar2[2] != (uint)*(byte *)(param_3 + 0x35)))))) {
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 10;
    if (0xff < iVar3) {
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
      return;
    }
  }
  puVar1 = (undefined4 *)(param_1 + (iVar3 + 0x38d) * 0x28);
  *param_2 = *puVar1;
  param_2[1] = puVar1[1];
  param_2[2] = puVar1[2];
  param_2[3] = puVar1[3];
  return;
}

// --------------------------------------------------

// Function: FUN_005100cc
// Address: 005100cc
undefined4 __thiscall FUN_005100cc(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  param_5 = param_5 + (param_4 + (param_3 + param_2 * 4) * 4) * 4;
  return CONCAT31((int3)((uint)(param_5 * 5) >> 8),-1 < *(int *)(param_1 + 0x9b40 + param_5 * 0x28))
  ;
}

// --------------------------------------------------

// Function: FUN_00510101
// Address: 00510101
// [HELPER] s_C__msdev_work_age1_x1_tmap_cpp: "C:\msdev\work\age1_x1\tmap.cpp"
int __thiscall
FUN_00510101(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)
{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 unaff_SI;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar4 = param_1 + (param_7 + 0x55 + (param_6 + (param_5 + param_4 * 4) * 4) * 4) * 0x28;
  fVar1 = *(float *)(iVar4 + 0x8e18);
  fVar2 = *(float *)(iVar4 + 0x8e1c);
  if (-1 < *(int *)(iVar4 + 0x8e00)) {
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_tmap_cpp,0x221);
    if (0x7fff < iVar3 * 2) {
      iVar3 = *(int *)(iVar4 + 0x8e00);
      fStack_c = *(float *)(iVar4 + 0x8e04);
      goto LAB_005101bf;
    }
  }
  fStack_c = *(float *)(iVar4 + 0x8dfc);
  iVar3 = *(int *)(iVar4 + 0x8df8);
LAB_005101bf:
  if (-1 < iVar3) {
    uVar8 = 0;
    iVar4 = (**(code **)(*(int *)**(undefined4 **)(*(int *)(param_1 + 0x8dc0) + 0x40) + 0x94))
                      (iVar3,(float)(param_2 * 3) + fVar1,(float)(param_3 * 3) + fVar2,0);
    iStack_10 = -1;
    iVar3 = __ftol();
    iVar5 = __ftol();
    do {
      iVar7 = 3;
      iVar6 = iVar3 + -1;
      do {
        RGE_Tile_List::add_node
                  ((RGE_Tile_List *)
                   (*(int *)(*(int *)(*(int *)(param_1 + 0x8dc0) + 0x40) +
                            *(short *)(*(int *)(param_1 + 0x8dc0) + 0x7c) * 4) + 0x6c),
                   iStack_10 + iVar5,iVar6);
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iStack_10 = iStack_10 + 1;
    } while (iStack_10 < 2);
    if (iVar4 != 0) {
      *(undefined1 *)(iVar4 + 0x35) = unaff_SI;
    }
    TRIBE_World::check_destructables
              (*(TRIBE_World **)(param_1 + 0x8dc0),0,(short)uVar8,fStack_8,fStack_c,'\x01');
    return iVar4;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051029f
// Address: 0051029f
void __thiscall FUN_0051029f(TRIBE_Map *param_1,int param_2,int param_3,undefined4 param_4)
{
  int iVar1;
  TRIBE_Cliff_Info TVar2;
  RGE_Static_Object *pRVar3;
  TRIBE_Cliff_Info *pTVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  TRIBE_Map *unaff_EBX;
  int iVar8;
  int iVar9;
  long unaff_retaddr;
  TRIBE_Map *pTStack_24;
  long lStack_20;
  long lStack_1c;
  long lStack_18;
  long lStack_14;
  TRIBE_Cliff_Info TStack_10;
  
  switch(param_4) {
  case 0:
    param_2 = param_2 + 1;
    if (param_1->_padding_ <= param_2) {
      return;
    }
    break;
  case 1:
    param_3 = param_3 + 1;
    if (param_1->_padding_ <= param_3) {
      return;
    }
    break;
  case 2:
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    break;
  case 3:
    if (param_3 < 1) {
      return;
    }
    param_3 = param_3 + -1;
  }
  pTStack_24 = param_1;
  pRVar3 = TRIBE_Map::find_cliff(param_1,param_2,param_3);
  pTVar4 = TRIBE_Map::get_cliff_info(param_1,&TStack_10,pRVar3);
  lStack_20 = pTVar4->info[0];
  lStack_1c = pTVar4->info[1];
  lStack_18 = pTVar4->info[2];
  lStack_14 = pTVar4->info[3];
  if (pRVar3 != (RGE_Static_Object *)0x0) {
    iVar8 = -1;
    do {
      iVar9 = -1;
      do {
        iVar1 = pTStack_24->_padding_;
        iVar5 = __ftol();
        iVar5 = iVar9 + iVar5;
        iVar6 = __ftol();
        RGE_Tile_List::add_node
                  ((RGE_Tile_List *)
                   (*(int *)(*(int *)(iVar1 + 0x40) + *(short *)(iVar1 + 0x7c) * 4) + 0x6c),
                   iVar8 + iVar6,iVar5);
        iVar9 = iVar9 + 1;
      } while (iVar9 < 2);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 2);
    (**(code **)pRVar3->_padding_)(1);
    lVar7 = TRIBE_Map::reverse_cliff_direction(unaff_EBX,param_3);
    (&pTStack_24)[lVar7] = (TRIBE_Map *)0x0;
    TVar2.info[1] = lStack_20;
    TVar2.info[0] = (long)pTStack_24;
    TVar2.info[2] = lStack_1c;
    TVar2.info[3] = lStack_18;
    TRIBE_Map::make_new_cliff(unaff_EBX,unaff_retaddr,param_2,TVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005103f3
// Address: 005103f3
undefined8 __fastcall FUN_005103f3(char *param_1,undefined4 param_2)
{
  byte bVar1;
  undefined4 in_EAX;
  int iVar2;
  char cVar3;
  int unaff_retaddr;
  uint *puVar4;
  
  cVar3 = (char)param_2 + *param_1;
  puVar4 = (uint *)CONCAT31((int3)((uint)param_2 >> 8),cVar3);
  bVar1 = (byte)param_1 & 0x1f;
  *puVar4 = *puVar4 << bVar1 | *puVar4 >> 0x20 - bVar1;
  iVar2 = unaff_retaddr + 2;
  if (3 < iVar2) {
    iVar2 = unaff_retaddr + -2;
  }
  return CONCAT44(CONCAT31((int3)(CONCAT22((short)((uint)param_2 >> 0x10),
                                           CONCAT11((char)((uint)param_2 >> 8) +
                                                    (char)((uint)in_EAX >> 8),cVar3)) >> 8),
                           cVar3 + *param_1),iVar2);
}

// --------------------------------------------------

// Function: FUN_00510422
// Address: 00510422
int __thiscall
FUN_00510422(TRIBE_Map *param_1,long param_2,long param_3,int param_4,int param_5,int param_6)
{
  int iVar1;
  TRIBE_Cliff_Info TVar2;
  TRIBE_Cliff_Info TVar3;
  TRIBE_Cliff_Info TVar4;
  TRIBE_Cliff_Info TVar5;
  TRIBE_Cliff_Info TVar6;
  TRIBE_Cliff_Info TVar7;
  TRIBE_Cliff_Info TVar8;
  TRIBE_Cliff_Info TVar9;
  TRIBE_Cliff_Info TVar10;
  TRIBE_Cliff_Info TVar11;
  uchar uVar12;
  RGE_Static_Object *pRVar13;
  int iVar14;
  int iVar15;
  long *plVar16;
  int iVar17;
  bool bVar18;
  int iVar19;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  TRIBE_Cliff_Info TStack_10;
  
  pRVar13 = TRIBE_Map::find_cliff(param_1,param_2,param_3);
  TRIBE_Map::get_cliff_info(param_1,&TStack_10,pRVar13);
  iVar17 = -1;
  iStack_24 = 0;
  iVar19 = TStack_10.info[param_4];
  iStack_20 = -1;
  iStack_18 = -1;
  iStack_1c = 0;
  if (iVar19 != 0) {
    if (param_5 == 0) {
      return iVar19;
    }
    if (param_5 == iVar19) {
      return param_5;
    }
  }
  if (pRVar13 != (RGE_Static_Object *)0x0) {
    iVar19 = -1;
    while( true ) {
      do {
        iVar1 = param_1->_padding_;
        iVar14 = __ftol();
        iVar14 = iVar19 + iVar14;
        iVar15 = __ftol();
        RGE_Tile_List::add_node
                  ((RGE_Tile_List *)
                   (*(int *)(*(int *)(iVar1 + 0x40) + *(short *)(iVar1 + 0x7c) * 4) + 0x6c),
                   iVar17 + iVar15,iVar14);
        iVar19 = iVar19 + 1;
      } while (iVar19 < 2);
      iVar17 = iVar17 + 1;
      if (1 < iVar17) break;
      iVar19 = -1;
    }
    (**(code **)pRVar13->_padding_)(1);
  }
  if (param_6 == param_4) {
    param_6 = -1;
  }
  if (param_6 < 0) {
    iVar17 = 0;
    iVar19 = 0;
    plVar16 = TStack_10.info;
    do {
      if ((*plVar16 != 0) && (iVar19 != param_4)) {
        iVar17 = iVar17 + 1;
      }
      iVar19 = iVar19 + 1;
      plVar16 = plVar16 + 1;
    } while (iVar19 < 4);
    if (iVar17 == 2) {
      iVar19 = 0;
      plVar16 = TStack_10.info;
      do {
        iVar17 = *plVar16;
        if ((iVar17 != 0) && (iVar19 != param_4)) {
          iVar1 = iVar19;
          if (iStack_20 < 0) {
            iStack_24 = iVar17;
            iStack_20 = iVar19;
            iVar17 = iStack_1c;
            iVar1 = iStack_18;
          }
          iStack_18 = iVar1;
          iStack_1c = iVar17;
          *plVar16 = 0;
        }
        iVar19 = iVar19 + 1;
        plVar16 = plVar16 + 1;
      } while (iVar19 < 4);
    }
  }
  else {
    iVar19 = 0;
    plVar16 = TStack_10.info;
    do {
      if (iVar19 != param_6) {
        TRIBE_Map::remove_cliff_edge(param_1,param_2,param_3,iVar19);
        *plVar16 = 0;
      }
      iVar19 = iVar19 + 1;
      plVar16 = plVar16 + 1;
    } while (iVar19 < 4);
  }
  if (param_5 == 0) {
    param_5 = 1;
    bVar18 = false;
    TStack_10.info[param_4] = 1;
    if (-1 < iStack_20) {
      TStack_10.info[iStack_20] = iStack_24;
      TVar5.info[1] = TStack_10.info[1];
      TVar5.info[0] = TStack_10.info[0];
      TVar5.info[2] = TStack_10.info[2];
      TVar5.info[3] = TStack_10.info[3];
      uVar12 = TRIBE_Map::check_cliff_valid(param_1,TVar5);
      if (uVar12 == '\0') {
        TStack_10.info[iStack_20] = 0;
      }
      else {
        bVar18 = true;
        iStack_24 = 0;
      }
    }
    if (!bVar18) {
      bVar18 = false;
      if (-1 < iStack_18) {
        TStack_10.info[iStack_18] = iStack_1c;
        TVar6.info[1] = TStack_10.info[1];
        TVar6.info[0] = TStack_10.info[0];
        TVar6.info[2] = TStack_10.info[2];
        TVar6.info[3] = TStack_10.info[3];
        uVar12 = TRIBE_Map::check_cliff_valid(param_1,TVar6);
        if (uVar12 == '\0') {
          TStack_10.info[iStack_18] = 0;
        }
        else {
          bVar18 = true;
          iStack_1c = 0;
        }
      }
      if ((!bVar18) &&
         (TVar7.info[1] = TStack_10.info[1], TVar7.info[0] = TStack_10.info[0],
         TVar7.info[2] = TStack_10.info[2], TVar7.info[3] = TStack_10.info[3],
         uVar12 = TRIBE_Map::check_cliff_valid(param_1,TVar7), uVar12 == '\0')) {
        TStack_10.info[param_4] = -1;
        param_5 = -1;
        bVar18 = false;
        if (-1 < iStack_20) {
          TStack_10.info[iStack_20] = iStack_24;
          TVar8.info[1] = TStack_10.info[1];
          TVar8.info[0] = TStack_10.info[0];
          TVar8.info[2] = TStack_10.info[2];
          TVar8.info[3] = TStack_10.info[3];
          uVar12 = TRIBE_Map::check_cliff_valid(param_1,TVar8);
          if (uVar12 == '\0') {
            TStack_10.info[iStack_20] = 0;
          }
          else {
            bVar18 = true;
            iStack_24 = 0;
          }
        }
        if (!bVar18) {
          bVar18 = false;
          if (-1 < iStack_18) {
            TStack_10.info[iStack_18] = iStack_1c;
            TVar9.info[1] = TStack_10.info[1];
            TVar9.info[0] = TStack_10.info[0];
            TVar9.info[2] = TStack_10.info[2];
            TVar9.info[3] = TStack_10.info[3];
            uVar12 = TRIBE_Map::check_cliff_valid(param_1,TVar9);
            if (uVar12 == '\0') {
              TStack_10.info[iStack_18] = 0;
            }
            else {
              bVar18 = true;
              iStack_1c = 0;
            }
          }
          if ((!bVar18) &&
             (TVar10.info[1] = TStack_10.info[1], TVar10.info[0] = TStack_10.info[0],
             TVar10.info[2] = TStack_10.info[2], TVar10.info[3] = TStack_10.info[3],
             uVar12 = TRIBE_Map::check_cliff_valid(param_1,TVar10), uVar12 == '\0')) {
            plVar16 = TStack_10.info;
            iVar19 = 0;
            do {
              if ((iVar19 != param_4) && (*plVar16 != 0)) {
                TRIBE_Map::remove_cliff_edge(param_1,param_2,param_3,iVar19);
                *plVar16 = 0;
              }
              iVar19 = iVar19 + 1;
              plVar16 = plVar16 + 1;
            } while (iVar19 < 4);
          }
        }
      }
    }
    if (iStack_24 != 0) {
      TRIBE_Map::remove_cliff_edge(param_1,param_2,param_3,iStack_20);
    }
    if (iStack_1c != 0) {
      TRIBE_Map::remove_cliff_edge(param_1,param_2,param_3,iStack_18);
    }
  }
  else {
    TStack_10.info[param_4] = param_5;
    if (-1 < iStack_20) {
      TStack_10.info[iStack_20] = iStack_24;
      TVar2.info[1] = TStack_10.info[1];
      TVar2.info[0] = TStack_10.info[0];
      TVar2.info[2] = TStack_10.info[2];
      TVar2.info[3] = TStack_10.info[3];
      uVar12 = TRIBE_Map::check_cliff_valid(param_1,TVar2);
      if (uVar12 == '\0') {
        TStack_10.info[iStack_20] = 0;
        TRIBE_Map::remove_cliff_edge(param_1,param_2,param_3,iStack_20);
      }
    }
    if (-1 < iStack_18) {
      TStack_10.info[iStack_18] = iStack_1c;
      TVar3.info[1] = TStack_10.info[1];
      TVar3.info[0] = TStack_10.info[0];
      TVar3.info[2] = TStack_10.info[2];
      TVar3.info[3] = TStack_10.info[3];
      uVar12 = TRIBE_Map::check_cliff_valid(param_1,TVar3);
      if (uVar12 == '\0') {
        TStack_10.info[iStack_18] = 0;
        TRIBE_Map::remove_cliff_edge(param_1,param_2,param_3,iStack_18);
      }
    }
    TVar4.info[1] = TStack_10.info[1];
    TVar4.info[0] = TStack_10.info[0];
    TVar4.info[2] = TStack_10.info[2];
    TVar4.info[3] = TStack_10.info[3];
    uVar12 = TRIBE_Map::check_cliff_valid(param_1,TVar4);
    if (uVar12 == '\0') {
      iVar19 = 0;
      plVar16 = TStack_10.info;
      do {
        if ((iVar19 != param_4) && (*plVar16 != 0)) {
          TRIBE_Map::remove_cliff_edge(param_1,param_2,param_3,iVar19);
          *plVar16 = 0;
        }
        iVar19 = iVar19 + 1;
        plVar16 = plVar16 + 1;
      } while (iVar19 < 4);
    }
  }
  TVar11.info[1] = TStack_10.info[1];
  TVar11.info[0] = TStack_10.info[0];
  TVar11.info[2] = TStack_10.info[2];
  TVar11.info[3] = TStack_10.info[3];
  TRIBE_Map::make_new_cliff(param_1,param_2,param_3,TVar11);
  return param_5;
}

// --------------------------------------------------

// Function: FUN_00510955
// Address: 00510955
void __thiscall FUN_00510955(TRIBE_Map *param_1,long param_2,int param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  TRIBE_Cliff_Info *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long *plVar7;
  TRIBE_Cliff_Info TStack_20;
  TRIBE_Cliff_Info TStack_10;
  
  pRVar2 = TRIBE_Map::find_cliff(param_1,param_2,param_3);
  TRIBE_Map::get_cliff_info(param_1,&TStack_20,pRVar2);
  if (pRVar2 != (RGE_Static_Object *)0x0) {
    pTVar3 = TRIBE_Map::get_cliff_info(param_1,&TStack_10,pRVar2);
    iVar6 = 0;
    TStack_20.info[0] = pTVar3->info[0];
    plVar7 = TStack_20.info;
    TStack_20.info[1] = pTVar3->info[1];
    TStack_20.info[2] = pTVar3->info[2];
    TStack_20.info[3] = pTVar3->info[3];
    do {
      if (*plVar7 != 0) {
        TRIBE_Map::remove_cliff_edge(param_1,param_2,param_3,iVar6);
      }
      iVar6 = iVar6 + 1;
      plVar7 = plVar7 + 1;
    } while (iVar6 < 4);
    param_3 = -1;
    do {
      iVar6 = -1;
      do {
        iVar1 = param_1->_padding_;
        iVar4 = __ftol();
        iVar4 = iVar6 + iVar4;
        iVar5 = __ftol();
        RGE_Tile_List::add_node
                  ((RGE_Tile_List *)
                   (*(int *)(*(int *)(iVar1 + 0x40) + *(short *)(iVar1 + 0x7c) * 4) + 0x6c),
                   param_3 + iVar5,iVar4);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 2);
      param_3 = param_3 + 1;
    } while (param_3 < 2);
    (**(code **)pRVar2->_padding_)(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00510a44
// Address: 00510a44
undefined4 __thiscall
FUN_00510a44(TRIBE_Map *param_1,int param_2,int param_3,uchar param_4,uchar param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uchar uVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = param_2 / 3;
  iVar3 = param_3 / 3;
  uVar4 = RGE_Map::do_cliff_brush((RGE_Map *)param_1,param_2,param_3,param_4,param_5);
  if (uVar4 != '\0') {
    return 1;
  }
  iVar1 = param_1->old_cliff_x;
  param_1->safe_cliff_x = iVar9;
  param_1->safe_cliff_y = iVar3;
  if ((((iVar1 == iVar9) && (param_1->old_cliff_y == iVar3)) ||
      (param_1->_padding_ <= iVar9 * 3 + 2)) ||
     (((param_1->_padding_ <= iVar3 * 3 + 2 || (iVar9 < 0)) || (iVar3 < 0)))) {
    return 0;
  }
  iVar8 = iVar3;
  if ((iVar1 != -1) && (iVar2 = param_1->old_cliff_y, iVar2 != -1)) {
    param_2 = param_2 + iVar1 * -3;
    uVar6 = param_3 + iVar2 * -3;
    iVar8 = iVar2;
    if ((param_2 < 3) &&
       (((-1 < param_2 && (iVar8 = iVar3, iVar9 = iVar1, (int)uVar6 < 3)) && (uVar6 < 0x80000000))))
{
      return 0;
    }
  }
  if ((iVar9 == iVar1) && (iVar8 == param_1->old_cliff_y)) {
    return 1;
  }
  if (param_5 != '\0') {
    (**(code **)(param_1->_padding_ + 0x30))(iVar9,iVar8);
    return 1;
  }
  if (iVar1 == -1) {
    param_1->old_cliff_direction = -1;
    param_1->old_cliff_x = iVar9;
    param_1->old_cliff_y = iVar8;
    return 1;
  }
  if (iVar1 < iVar9) {
    lVar7 = 0;
  }
  else if (iVar9 < iVar1) {
    lVar7 = 2;
  }
  else {
    lVar7 = 1;
    if (iVar8 <= param_1->old_cliff_y) {
      lVar7 = 3;
    }
  }
  lVar5 = TRIBE_Map::add_cliff_edge
                    (param_1,iVar1,param_1->old_cliff_y,lVar7,0,param_1->old_cliff_direction);
  lVar7 = TRIBE_Map::reverse_cliff_direction(param_1,lVar7);
  param_1->old_cliff_direction = lVar7;
  param_1->old_cliff_x = iVar9;
  param_1->old_cliff_y = iVar8;
  TRIBE_Map::add_cliff_edge(param_1,iVar9,iVar8,lVar7,lVar5,-1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00510c02
// Address: 00510c02
undefined4 __thiscall
FUN_00510c02(RGE_Map *param_1,int param_2,int param_3,long param_4,long param_5,uchar param_6,
            uchar param_7)
{
  int iVar1;
  undefined3 extraout_var;
  
  if ((*(int *)&param_1[1].tilesizes[0].y_delta != param_2 / 3) ||
     (iVar1._0_2_ = param_1[1].tilesizes[1].height, iVar1._2_2_ = param_1[1].tilesizes[1].y_delta,
     iVar1 != param_3 / 3)) {
    param_1[1].world_height = -1;
    param_1[1].tilesizes[0].width = -1;
    param_1[1].tilesizes[0].height = -1;
    *(undefined4 *)&param_1[1].tilesizes[0].y_delta = 0xffffffff;
    param_1[1].tilesizes[1].height = -1;
    param_1[1].tilesizes[1].y_delta = -1;
    param_1[1].tilesizes[2].width = -1;
    param_1[1].tilesizes[2].height = -1;
  }
  RGE_Map::do_cliff_brush_stroke(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return CONCAT31(extraout_var,1);
}

// --------------------------------------------------

// Function: FUN_00510c8d
// Address: 00510c8d
char FUN_00510c8d(char param_1)
{
  if (param_1 == '\x01') {
    return param_1;
  }
  if (param_1 == '\x16') {
    return true;
  }
  return param_1 == '\x04';
}

// --------------------------------------------------

// Function: FUN_00510cac
// Address: 00510cac
void __thiscall
FUN_00510cac(TRIBE_Map *param_1,int param_2,int param_3,int param_4,int param_5,uchar param_6)
{
  int iVar1;
  int iVar2;
  bool bVar3;
  byte bVar4;
  uchar uVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = param_1->_padding_ + -1;
  iVar2 = param_1->_padding_ + -1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_1->_padding_ <= param_4) {
    param_4 = iVar2;
  }
  if (param_1->_padding_ <= param_5) {
    param_5 = iVar1;
  }
  for (; param_3 <= param_5; param_3 = param_3 + 1) {
    if (param_2 <= param_4) {
      iVar7 = param_2 * 0x18;
      iVar6 = param_2;
      do {
        bVar4 = *(byte *)(iVar7 + 5 + *(int *)(param_1->_padding_ + param_3 * 4)) & 0x1f;
        if (bVar4 == 2) {
          bVar3 = false;
          if (((0 < param_3) &&
              (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + param_3 * 4
                                                                  + -4) + 5 + iVar7) & 0x1f),
              uVar5 != '\0')) ||
             ((param_3 < iVar1 &&
              (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + 4 +
                                                                  param_3 * 4) + 5 + iVar7) & 0x1f),
              uVar5 != '\0')))) {
            bVar3 = true;
          }
          if ((0 < iVar7) &&
             (((uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + param_3 * 4
                                                                   ) + -0x13 + iVar7) & 0x1f),
               uVar5 != '\0' ||
               ((0 < param_3 &&
                (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + -4 +
                                                                    param_3 * 4) + -0x13 + iVar7) &
                                                  0x1f), uVar5 != '\0')))) ||
              ((param_3 < iVar1 &&
               (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + 4 +
                                                                   param_3 * 4) + -0x13 + iVar7) &
                                                 0x1f), uVar5 != '\0')))))) {
            bVar3 = true;
          }
          if ((iVar6 < iVar2) &&
             (((uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + param_3 * 4
                                                                   ) + 0x1d + iVar7) & 0x1f),
               uVar5 != '\0' ||
               ((0 < param_3 &&
                (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + -4 +
                                                                    param_3 * 4) + 0x1d + iVar7) &
                                                  0x1f), uVar5 != '\0')))) ||
              ((param_3 < iVar1 &&
               (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + 4 +
                                                                   param_3 * 4) + 0x1d + iVar7) &
                                                 0x1f), uVar5 != '\0')))))) {
            bVar3 = true;
          }
          if (!bVar3) {
            RGE_Map::set_terrain
                      ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,(short)iVar6,
                       (short)param_3,param_6,0,0);
          }
        }
        else {
          uVar5 = TRIBE_Map::water(param_1,bVar4);
          if (uVar5 == '\0') {
            bVar3 = false;
            if (((0 < param_3) &&
                (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + -4 +
                                                                    param_3 * 4) + 5 + iVar7) & 0x1f
                                         ), uVar5 != '\0')) ||
               ((param_3 < iVar1 &&
                (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + 4 +
                                                                    param_3 * 4) + 5 + iVar7) & 0x1f
                                         ), uVar5 != '\0')))) {
              bVar3 = true;
            }
            if ((0 < iVar7) &&
               (((uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ +
                                                                     param_3 * 4) + -0x13 + iVar7) &
                                                   0x1f), uVar5 != '\0' ||
                 ((0 < param_3 &&
                  (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + -4 +
                                                                      param_3 * 4) + -0x13 + iVar7)
                                                    & 0x1f), uVar5 != '\0')))) ||
                ((param_3 < iVar1 &&
                 (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + 4 +
                                                                     param_3 * 4) + -0x13 + iVar7) &
                                                   0x1f), uVar5 != '\0')))))) {
              bVar3 = true;
            }
            if ((iVar6 < iVar2) &&
               (((uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ +
                                                                     param_3 * 4) + 0x1d + iVar7) &
                                                   0x1f), uVar5 != '\0' ||
                 ((0 < param_3 &&
                  (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + -4 +
                                                                      param_3 * 4) + 0x1d + iVar7) &
                                                    0x1f), uVar5 != '\0')))) ||
                ((param_3 < iVar1 &&
                 (uVar5 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + 4 +
                                                                     param_3 * 4) + 0x1d + iVar7) &
                                                   0x1f), uVar5 != '\0')))))) {
              bVar3 = true;
            }
            if (bVar3) {
              RGE_Map::set_terrain
                        ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,(short)iVar6,
                         (short)param_3,'\x02',0,0);
            }
          }
        }
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 0x18;
      } while (iVar6 <= param_4);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00510ff8
// Address: 00510ff8
uint __thiscall FUN_00510ff8(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  uint3 uVar4;
  uint uVar3;
  int iVar5;
  
  uVar3 = *(uint *)(*(int *)(param_1 + 0x8d8c) + param_3 * 4);
  iVar2 = uVar3 + param_2 * 0x18;
  if ((0 < param_2) && (*(char *)(iVar2 + -0x14) != '\0')) {
    return uVar3 & 0xffffff00;
  }
  uVar3 = *(uint *)(param_1 + 8);
  iVar1 = uVar3 - 1;
  uVar4 = (uint3)(uVar3 >> 8);
  if ((param_2 < iVar1) && (*(char *)(iVar2 + 0x1c) != '\0')) {
    return (uint)uVar4 << 8;
  }
  if (0 < param_3) {
    iVar5 = iVar2 + uVar3 * -0x18;
    if (*(char *)(iVar5 + 4) != '\0') {
      return (uint)uVar4 << 8;
    }
    if ((0 < param_2) && (*(char *)(iVar5 + -0x14) != '\0')) {
      return (uint)uVar4 << 8;
    }
    if ((param_2 < iVar1) && (*(char *)(iVar5 + 0x1c) != '\0')) {
      return (uint)uVar4 << 8;
    }
  }
  if (param_3 < *(int *)(param_1 + 0xc) + -1) {
    iVar5 = uVar3 * 0x18;
    uVar3 = iVar2 + uVar3 * 0x18;
    if (*(char *)(iVar2 + 4 + iVar5) != '\0') {
      return uVar3 & 0xffffff00;
    }
    uVar4 = (uint3)(uVar3 >> 8);
    if ((0 < param_2) && (*(char *)(uVar3 - 0x14) != '\0')) {
      return (uint)uVar4 << 8;
    }
    if ((param_2 < iVar1) && (*(char *)(uVar3 + 0x1c) != '\0')) {
      return (uint)uVar4 << 8;
    }
  }
  return CONCAT31((int3)(uVar3 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_005110df
// Address: 005110df
void __thiscall FUN_005110df(TRIBE_Map *param_1,int param_2,int param_3,int param_4,int param_5)
{
  uchar uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_1->_padding_ <= param_4) {
    param_4 = param_1->_padding_ + -1;
  }
  if (param_1->_padding_ <= param_5) {
    param_5 = param_1->_padding_ + -1;
  }
  for (; param_3 <= param_5; param_3 = param_3 + 1) {
    if (param_2 <= param_4) {
      iVar2 = param_2 * 0x18;
      iVar3 = param_2;
      do {
        uVar1 = TRIBE_Map::water(param_1,*(byte *)(*(int *)(param_1->_padding_ + param_3 * 4) + 5 +
                                                  iVar2) & 0x1f);
        if ((uVar1 != '\0') &&
           (uVar1 = TRIBE_Map::do_terrain_brush_check(param_1,iVar3,param_3), uVar1 == '\0')) {
          RGE_Map::set_terrain
                    ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,(short)iVar3,
                     (short)param_3,'\0',0,0);
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x18;
      } while (iVar3 <= param_4);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00511195
// Address: 00511195
void __thiscall
FUN_00511195(TRIBE_Map *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            uchar param_7)
{
  short sVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  uchar uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  RGE_Game_World *pRVar20;
  short sVar21;
  short sVar22;
  int iStack_20;
  short sStack_1c;
  short sStack_14;
  short sStack_10;
  short sStack_c;
  short sStack_8;
  
  sVar1 = (short)param_1->_padding_;
  sStack_14 = -1 - sVar1;
  sStack_1c = -sVar1;
  sStack_10 = 1 - sVar1;
  sStack_8 = sVar1 + 1;
  sStack_c = sVar1 + -1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_1->_padding_ <= param_4) {
    param_4 = param_1->_padding_ + -1;
  }
  iVar13 = param_5;
  iVar15 = param_4;
  iVar16 = param_3;
  iVar18 = param_2;
  if (param_1->_padding_ <= param_5) {
    iVar13 = param_1->_padding_ + -1;
    param_5 = iVar13;
  }
  do {
    bVar4 = false;
    if (0 < iVar18) {
      iVar18 = iVar18 + -1;
      param_2 = iVar18;
    }
    if (0 < iVar16) {
      iVar16 = iVar16 + -1;
      param_3 = iVar16;
    }
    if (iVar15 < param_1->_padding_ + -1) {
      iVar15 = iVar15 + 1;
      param_4 = iVar15;
    }
    if (iVar13 < param_1->_padding_ + -1) {
      iVar13 = iVar13 + 1;
      param_5 = iVar13;
    }
    iStack_20 = 0;
    iVar17 = iVar16;
    do {
      iVar16 = iVar17;
      if (iVar17 <= iVar13) {
        iVar14 = iVar18 * 0x18;
        iVar19 = iVar18;
        do {
          iVar13 = *(int *)(param_1->_padding_ + iVar17 * 4) + iVar14;
          iVar18 = iVar19;
          if (iVar19 <= iVar15) {
            do {
              uVar12 = TRIBE_Map::water(param_1,*(byte *)(iVar13 + 5) & 0x1f);
              if (uVar12 == '\0') {
                bVar3 = false;
                bVar5 = false;
                bVar9 = false;
                bVar7 = false;
                bVar11 = false;
                bVar6 = false;
                bVar10 = false;
                bVar8 = false;
                if ((0 < iVar17) &&
                   (uVar12 = TRIBE_Map::water(param_1,*(byte *)(iVar13 + 5 + sStack_1c * 0x18) &
                                                      0x1f), uVar12 != '\0')) {
                  bVar5 = true;
                }
                if ((iVar17 < param_1->_padding_ + -1) &&
                   (uVar12 = TRIBE_Map::water(param_1,*(byte *)(iVar13 + 5 + sVar1 * 0x18) & 0x1f),
                   uVar12 != '\0')) {
                  bVar6 = true;
                }
                if ((0 < iVar19) &&
                   (uVar12 = TRIBE_Map::water(param_1,*(byte *)(iVar13 + -0x13) & 0x1f),
                   uVar12 != '\0')) {
                  bVar8 = true;
                }
                if ((iVar19 < param_1->_padding_ + -1) &&
                   (uVar12 = TRIBE_Map::water(param_1,*(byte *)(iVar13 + 0x1d) & 0x1f),
                   uVar12 != '\0')) {
                  bVar7 = true;
                }
                if (0 < iVar17) {
                  bVar3 = false;
                  if ((0 < iVar19) &&
                     (uVar12 = TRIBE_Map::water(param_1,*(byte *)(iVar13 + 5 + sStack_14 * 0x18) &
                                                        0x1f), uVar12 != '\0')) {
                    bVar3 = true;
                  }
                  if ((iVar19 < param_1->_padding_ + -1) &&
                     (uVar12 = TRIBE_Map::water(param_1,*(byte *)(iVar13 + 5 + sStack_10 * 0x18) &
                                                        0x1f), uVar12 != '\0')) {
                    bVar9 = true;
                  }
                }
                if (iVar17 < param_1->_padding_ + -1) {
                  bVar10 = false;
                  if ((0 < iVar19) &&
                     (uVar12 = TRIBE_Map::water(param_1,*(byte *)(iVar13 + 5 + sStack_c * 0x18) &
                                                        0x1f), uVar12 != '\0')) {
                    bVar10 = true;
                  }
                  if ((iVar19 < param_1->_padding_ + -1) &&
                     (uVar12 = TRIBE_Map::water(param_1,*(byte *)(iVar13 + 5 + sStack_8 * 0x18) &
                                                        0x1f), uVar12 != '\0')) {
                    bVar11 = true;
                  }
                }
                bVar2 = false;
                if (iStack_20 == 0) {
                  if (((bVar5) && (bVar6)) || ((bVar7 && (bVar8)))) {
LAB_005115bc:
                    bVar2 = true;
                  }
LAB_005115be:
                  if (!bVar2) goto LAB_0051172c;
                }
                else {
                  if (bVar3) {
                    if (((((bVar9) && (!bVar5)) || ((bVar7 && (!bVar9)))) || ((bVar10 && (!bVar8))))
                       || ((bVar6 && (!bVar10)))) {
                      bVar2 = true;
                    }
                    else if (((bVar11) && (!bVar6)) && (!bVar7)) {
                      bVar2 = true;
                    }
                  }
                  if (((bVar9) && (!bVar2)) &&
                     (((((bVar3 && (!bVar5)) || ((bVar8 && (!bVar3)))) || ((bVar11 && (!bVar7)))) ||
                      (((bVar6 && (!bVar11)) || ((bVar10 && ((!bVar8 && (!bVar6)))))))))) {
                    bVar2 = true;
                  }
                  if (((bVar11) && (!bVar2)) &&
                     ((((bVar9 && (!bVar7)) || (((bVar5 && (!bVar9)) || ((bVar10 && (!bVar6)))))) ||
                      (((bVar8 && (!bVar10)) || ((bVar3 && ((!bVar8 && (!bVar5)))))))))) {
                    bVar2 = true;
                  }
                  if (!bVar10) goto LAB_005115be;
                  if (!bVar2) {
                    if ((((bVar3) && (!bVar8)) || ((bVar5 && (!bVar3)))) ||
                       ((((bVar11 && (!bVar6)) || ((bVar7 && (!bVar11)))) ||
                        (((bVar9 && (!bVar7)) && (!bVar5)))))) goto LAB_005115bc;
                    goto LAB_005115be;
                  }
                }
                uVar12 = TRIBE_Map::water(param_1,param_7);
                sVar22 = (short)iVar17;
                if (uVar12 == '\0') {
                  sVar21 = (short)iVar19;
                  if (bVar3) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,sVar21 + -1,
                               sVar22 + -1,param_7,0,0);
                  }
                  if (bVar5) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,sVar21,
                               sVar22 + -1,param_7,0,0);
                  }
                  if (bVar9) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,sVar21 + 1,
                               sVar22 + -1,param_7,0,0);
                  }
                  if (bVar7) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,sVar21 + 1,
                               sVar22,param_7,0,0);
                  }
                  if (bVar11) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,sVar21 + 1,
                               sVar22 + 1,param_7,0,0);
                  }
                  if (bVar6) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,sVar21,
                               sVar22 + 1,param_7,0,0);
                  }
                  if (bVar10) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)param_1,(RGE_Game_World *)param_1->_padding_,sVar21 + -1,
                               sVar22 + 1,param_7,0,0);
                  }
                  if (bVar8) {
                    pRVar20 = (RGE_Game_World *)param_1->_padding_;
                    iVar15 = iVar19 + -1;
                    goto LAB_00511720;
                  }
                }
                else {
                  uVar12 = TRIBE_Map::do_terrain_brush_check(param_1,iVar19,iVar17);
                  if (uVar12 == '\0') goto LAB_0051172c;
                  pRVar20 = (RGE_Game_World *)param_1->_padding_;
                  iVar15 = iVar19;
LAB_00511720:
                  RGE_Map::set_terrain((RGE_Map *)param_1,pRVar20,(short)iVar15,sVar22,param_7,0,0);
                }
                bVar4 = true;
              }
LAB_0051172c:
              iVar13 = iVar13 + 0x18;
              iVar19 = iVar19 + 1;
              iVar15 = param_4;
              iVar18 = param_2;
            } while (iVar19 <= param_4);
          }
          iVar17 = iVar17 + 1;
          iVar13 = param_5;
          iVar16 = param_3;
          iVar19 = iVar18;
        } while (iVar17 <= param_5);
      }
      iStack_20 = iStack_20 + 1;
      iVar17 = iVar16;
    } while (iStack_20 < 2);
    if (!bVar4) {
      TRIBE_Map::clean_borders(param_1,iVar18,param_3,iVar15,param_5,param_7);
      RGE_Map::set_terrain
                ((RGE_Map *)param_1,(RGE_Player *)0x0,(RGE_Game_World *)0x0,(short)iVar18,
                 (short)param_3,(short)iVar15,(short)param_5,'\0','\0',0);
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_005117ba
// Address: 005117ba
RGE_Master_Player * __thiscall FUN_005117ba(RGE_Master_Player *param_1,_iobuf *param_2)
{
  RGE_Master_Player::RGE_Master_Player(param_1,param_2);
  param_1->_padding_ = (int)&TRIBE_Master_Player::_vftable_;
  param_1->type = '\x01';
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005117dd
// Address: 005117dd
TRIBE_Master_Player * __thiscall FUN_005117dd(TRIBE_Master_Player *param_1,byte param_2)
{
  TRIBE_Master_Player::~TRIBE_Master_Player(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005117fe
// Address: 005117fe
RGE_Master_Player * __thiscall FUN_005117fe(RGE_Master_Player *param_1,int param_2)
{
  RGE_Master_Player::RGE_Master_Player(param_1,param_2);
  param_1->_padding_ = (int)&TRIBE_Master_Player::_vftable_;
  param_1->type = '\x01';
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051181d
// Address: 0051181d
void __fastcall FUN_0051181d(RGE_Master_Player *param_1)
{
  param_1->_padding_ = (int)&TRIBE_Master_Player::_vftable_;
  RGE_Master_Player::~RGE_Master_Player(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0051182b
// Address: 0051182b
void __thiscall
FUN_0051182b(RGE_Master_Player *param_1,int param_2,uchar param_3,RGE_Sprite **param_4,
            RGE_Sound **param_5,short param_6)
{
  TRIBE_Master_Tree_Object *this;
  RGE_Master_Static_Object *pRVar1;
  TRIBE_Master_Building_Object *this_00;
  TRIBE_Master_Combat_Object *this_01;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005610c1;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 == 'F') {
    this_01 = (TRIBE_Master_Combat_Object *)operator_new(0x164);
    uStack_4 = 0;
    if (this_01 != (TRIBE_Master_Combat_Object *)0x0) {
      pRVar1 = (RGE_Master_Static_Object *)
               TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
                         (this_01,param_2,param_4,param_5,1);
      goto LAB_00511972;
    }
  }
  else {
    if (param_3 == 'P') {
      this_00 = (TRIBE_Master_Building_Object *)operator_new(0x17c);
      uStack_4 = 1;
      if (this_00 != (TRIBE_Master_Building_Object *)0x0) {
        pRVar1 = (RGE_Master_Static_Object *)
                 TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
                           (this_00,param_2,param_4,param_5,1);
        param_1->master_objects[param_6] = pRVar1;
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
      param_1->master_objects[param_6] = (RGE_Master_Static_Object *)0x0;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    if (param_3 != 'Z') {
      RGE_Master_Player::load_master_object(param_1,param_2,param_3,param_4,param_5,param_6);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    this = (TRIBE_Master_Tree_Object *)operator_new(0xb8);
    uStack_4 = 2;
    if (this != (TRIBE_Master_Tree_Object *)0x0) {
      pRVar1 = (RGE_Master_Static_Object *)
               TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(this,param_2,param_4,param_5,1);
      goto LAB_00511972;
    }
  }
  pRVar1 = (RGE_Master_Static_Object *)0x0;
LAB_00511972:
  param_1->master_objects[param_6] = pRVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0051198f
// Address: 0051198f
void __thiscall
FUN_0051198f(RGE_Master_Player *param_1,_iobuf *param_2,uchar param_3,RGE_Sprite **param_4,
            RGE_Sound **param_5,short param_6)
{
  TRIBE_Master_Tree_Object *this;
  RGE_Master_Static_Object *pRVar1;
  TRIBE_Master_Building_Object *this_00;
  TRIBE_Master_Combat_Object *this_01;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005610f1;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 == 'F') {
    this_01 = (TRIBE_Master_Combat_Object *)operator_new(0x164);
    uStack_4 = 0;
    if (this_01 != (TRIBE_Master_Combat_Object *)0x0) {
      pRVar1 = (RGE_Master_Static_Object *)
               TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
                         (this_01,param_2,param_4,param_5,param_6,1);
      goto LAB_00511ae1;
    }
  }
  else {
    if (param_3 == 'P') {
      this_00 = (TRIBE_Master_Building_Object *)operator_new(0x17c);
      uStack_4 = 1;
      if (this_00 != (TRIBE_Master_Building_Object *)0x0) {
        pRVar1 = (RGE_Master_Static_Object *)
                 TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
                           (this_00,param_2,param_4,param_5,param_6,1);
        param_1->master_objects[param_6] = pRVar1;
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
      param_1->master_objects[param_6] = (RGE_Master_Static_Object *)0x0;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    if (param_3 != 'Z') {
      RGE_Master_Player::load_object(param_1,param_2,param_3,param_4,param_5,param_6);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    this = (TRIBE_Master_Tree_Object *)operator_new(0xb8);
    uStack_4 = 2;
    if (this != (TRIBE_Master_Tree_Object *)0x0) {
      pRVar1 = (RGE_Master_Static_Object *)
               TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object
                         (this,param_2,param_4,param_5,param_6,1);
      goto LAB_00511ae1;
    }
  }
  pRVar1 = (RGE_Master_Static_Object *)0x0;
LAB_00511ae1:
  param_1->master_objects[param_6] = pRVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00511afd
// Address: 00511afd
void __thiscall
FUN_00511afd(RGE_Object_List *param_1,uchar param_2,int param_3,RGE_Game_World *param_4)
{
  TRIBE_Building_Object *this;
  TRIBE_Combat_Object *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561116;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == 'F') {
    this_00 = (TRIBE_Combat_Object *)operator_new(0x1c8);
    uStack_4 = 0;
    if (this_00 != (TRIBE_Combat_Object *)0x0) {
      TRIBE_Combat_Object::TRIBE_Combat_Object(this_00,param_3,param_4,1);
    }
  }
  else {
    if (param_2 != 'P') {
      RGE_Object_List::load(param_1,param_2,param_3,param_4);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    this = (TRIBE_Building_Object *)operator_new(0x204);
    uStack_4 = 1;
    if (this != (TRIBE_Building_Object *)0x0) {
      TRIBE_Building_Object::TRIBE_Building_Object(this,param_3,param_4,1);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00511bc4
// Address: 00511bc4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

TRIBE_Player * __thiscall
FUN_00511bc4(TRIBE_Player *param_1,int param_2,RGE_Game_World *param_3,TRIBE_History_Info *param_4)
{
  undefined1 uVar1;
  TRIBE_Player_Tech *pTVar2;
  TRIBE_History_Info *pTVar3;
  int iVar4;
  TribeMainDecisionAIModule *pTVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561154;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Player::RGE_Player((RGE_Player *)param_1,param_2,param_3,(uchar)param_4);
  uStack_4 = 0;
  param_1->playerAI = (TribeMainDecisionAIModule *)0x0;
  param_1->_padding_ = (int)&TRIBE_Player::_vftable_;
  rge_read(param_2,&param_1->_padding_,1);
  rge_read(param_2,&param_1->update_count,4);
  rge_read(param_2,&param_1->updateCountNeedHelp,4);
  rge_read(param_2,&param_1->fog_update,4);
  rge_read(param_2,&param_1->update_time,4);
  param_4 = (TRIBE_History_Info *)operator_new(0x10);
  uStack_4._0_1_ = 1;
  if (param_4 == (TRIBE_History_Info *)0x0) {
    pTVar2 = (TRIBE_Player_Tech *)0x0;
  }
  else {
    pTVar2 = (TRIBE_Player_Tech *)
             TRIBE_Player_Tech::TRIBE_Player_Tech
                       ((TRIBE_Player_Tech *)param_4,param_2,(TRIBE_Tech *)param_3[1]._padding_,
                        (RGE_Player *)param_1,'\0');
  }
  param_1->tech_tree = pTVar2;
  uStack_4._0_1_ = 0;
  uVar1 = (undefined1)uStack_4;
  uStack_4._0_1_ = 0;
  if (save_game_version <= _DAT_00576818) {
    param_1->update_history_count = 0;
    uStack_4._0_1_ = uVar1;
    param_4 = (TRIBE_History_Info *)operator_new(0x14);
    uStack_4 = CONCAT31(uStack_4._1_3_,3);
    if (param_4 != (TRIBE_History_Info *)0x0) {
      pTVar3 = (TRIBE_History_Info *)TRIBE_History_Info::TRIBE_History_Info(param_4,-1);
      goto LAB_00511d13;
    }
  }
  else {
    rge_read(param_2,&param_1->update_history_count,4);
    param_4 = (TRIBE_History_Info *)operator_new(0x14);
    uStack_4 = CONCAT31(uStack_4._1_3_,2);
    if (param_4 != (TRIBE_History_Info *)0x0) {
      pTVar3 = (TRIBE_History_Info *)TRIBE_History_Info::TRIBE_History_Info(param_4,param_2);
      goto LAB_00511d13;
    }
  }
  pTVar3 = (TRIBE_History_Info *)0x0;
LAB_00511d13:
  param_1->history = pTVar3;
  uStack_4 = uStack_4 & 0xffffff00;
  if (save_game_version < _DAT_0057681c) {
    param_1->ruin_held_time = -1.0;
    param_1->artifact_held_time = -1.0;
  }
  else {
    rge_read(param_2,&param_1->ruin_held_time,4);
    rge_read(param_2,&param_1->artifact_held_time,4);
  }
  if ((char)param_1->_padding_ == '\x03') {
    param_4 = (TRIBE_History_Info *)0x1;
    if (_DAT_00576820 <= save_game_version) {
      rge_read(param_2,&param_4,4);
    }
    iVar4 = TCommunications_Handler::IsHost(comm);
    if ((iVar4 == 1) && (param_4 == (TRIBE_History_Info *)0x1)) {
      pTVar5 = (TribeMainDecisionAIModule *)operator_new(0x125c8);
      uStack_4 = CONCAT31(uStack_4._1_3_,4);
      if (pTVar5 == (TribeMainDecisionAIModule *)0x0) {
        pTVar5 = (TribeMainDecisionAIModule *)0x0;
      }
      else {
        pTVar5 = (TribeMainDecisionAIModule *)
                 TribeMainDecisionAIModule::TribeMainDecisionAIModule
                           (pTVar5,(int)*(short *)((int)&param_1->_padding_ + 2),
                            (char *)param_1->_padding_,param_1,param_2);
      }
      param_1->playerAI = pTVar5;
    }
    param_1->_padding_ = 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00511dfe
// Address: 00511dfe
TRIBE_Player * __thiscall FUN_00511dfe(TRIBE_Player *param_1,byte param_2)
{
  TRIBE_Player::~TRIBE_Player(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00511e1e
// Address: 00511e1e
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
TRIBE_Player * __thiscall
FUN_00511e1e(TRIBE_Player *param_1,RGE_Game_World *param_2,RGE_Master_Player *param_3,uchar param_4,
            char *param_5,uchar param_6,char param_7,char param_8,char *param_9,char *param_10,
            char *param_11)
{
  undefined1 uVar1;
  Visible_Resource_Manager *this;
  int iVar2;
  TribeMainDecisionAIModule *pTVar3;
  RGE_Object_List *pRVar4;
  RGE_Visible_Map *this_00;
  TRIBE_History_Info *pTVar5;
  TRIBE_Player_Tech *pTVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005611c0;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Player::RGE_Player((RGE_Player *)param_1,param_2,param_3,param_4,param_5,param_6,'\0');
  uStack_4 = 0;
  param_1->playerAI = (TribeMainDecisionAIModule *)0x0;
  param_1->_padding_ = (int)&TRIBE_Player::_vftable_;
  this = (Visible_Resource_Manager *)operator_new(0x14);
  uStack_4._0_1_ = 1;
  if (this == (Visible_Resource_Manager *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = Visible_Resource_Manager::Visible_Resource_Manager(this,(RGE_Player *)param_1,5);
  }
  param_1->_padding_ = iVar2;
  uStack_4._0_1_ = 0;
  uVar1 = (undefined1)uStack_4;
  uStack_4._0_1_ = 0;
  if (param_7 == '\0') {
    *(undefined1 *)&param_1->_padding_ = 1;
    uStack_4._0_1_ = uVar1;
  }
  else {
    *(undefined1 *)&param_1->_padding_ = 3;
    param_1->_padding_ = 1;
    iVar2 = TCommunications_Handler::IsHost(comm);
    if (iVar2 == 1) {
      pTVar3 = (TribeMainDecisionAIModule *)operator_new(0x125c8);
      uStack_4._0_1_ = 2;
      if (pTVar3 == (TribeMainDecisionAIModule *)0x0) {
        pTVar3 = (TribeMainDecisionAIModule *)0x0;
      }
      else {
        pTVar3 = (TribeMainDecisionAIModule *)
                 TribeMainDecisionAIModule::TribeMainDecisionAIModule
                           (pTVar3,(void *)0x0,(int)*(short *)((int)&param_1->_padding_ + 2),
                            (char *)param_1->_padding_,param_1,param_9,param_10,param_11);
      }
      uStack_4._0_1_ = 0;
      param_1->playerAI = pTVar3;
    }
  }
  if (param_8 != '\0') {
    pRVar4 = (RGE_Object_List *)operator_new(0xc);
    uStack_4._0_1_ = 3;
    if (pRVar4 == (RGE_Object_List *)0x0) {
      pRVar4 = (RGE_Object_List *)0x0;
    }
    else {
      RGE_Object_List::RGE_Object_List(pRVar4);
      pRVar4->_padding_ = (int)&TRIBE_Object_List::_vftable_;
    }
    uStack_4._0_1_ = 0;
    param_1->_padding_ = (int)pRVar4;
    pRVar4 = (RGE_Object_List *)operator_new(0xc);
    uStack_4._0_1_ = 4;
    if (pRVar4 == (RGE_Object_List *)0x0) {
      pRVar4 = (RGE_Object_List *)0x0;
    }
    else {
      RGE_Object_List::RGE_Object_List(pRVar4);
      pRVar4->_padding_ = (int)&TRIBE_Object_List::_vftable_;
    }
    uStack_4._0_1_ = 0;
    param_1->_padding_ = (int)pRVar4;
    pRVar4 = (RGE_Object_List *)operator_new(0xc);
    uStack_4._0_1_ = 5;
    if (pRVar4 == (RGE_Object_List *)0x0) {
      pRVar4 = (RGE_Object_List *)0x0;
    }
    else {
      RGE_Object_List::RGE_Object_List(pRVar4);
      pRVar4->_padding_ = (int)&TRIBE_Object_List::_vftable_;
    }
    uStack_4._0_1_ = 0;
    param_1->_padding_ = (int)pRVar4;
    TRIBE_Player::new_victory(param_1);
    this_00 = (RGE_Visible_Map *)operator_new(0x38);
    uStack_4._0_1_ = 6;
    if (this_00 == (RGE_Visible_Map *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = RGE_Visible_Map::RGE_Visible_Map(this_00,param_2->map,(RGE_Player *)param_1);
    }
    uStack_4._0_1_ = 0;
    param_1->_padding_ = iVar2;
  }
  iVar2 = 1;
  if (1 < *(short *)(param_1->_padding_ + 0x3c)) {
    do {
      if (iVar2 != *(short *)((int)&param_1->_padding_ + 2)) {
        RGE_Player::set_relation((RGE_Player *)param_1,iVar2,'\x03');
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(short *)(param_1->_padding_ + 0x3c));
  }
  param_1->update_count = 0;
  param_1->update_history_count = 0;
  param_1->updateCountNeedHelp = 0;
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x140);
  param_1->update_time = 0.0;
  param_1->fog_update = (iVar2 * 3) / 0x7fff + 3;
  pTVar5 = (TRIBE_History_Info *)operator_new(0x14);
  uStack_4._0_1_ = 7;
  if (pTVar5 == (TRIBE_History_Info *)0x0) {
    pTVar5 = (TRIBE_History_Info *)0x0;
  }
  else {
    pTVar5 = (TRIBE_History_Info *)TRIBE_History_Info::TRIBE_History_Info(pTVar5,-1);
  }
  uStack_4._0_1_ = 0;
  param_1->history = pTVar5;
  pTVar6 = (TRIBE_Player_Tech *)operator_new(0x10);
  uStack_4 = CONCAT31(uStack_4._1_3_,8);
  if (pTVar6 == (TRIBE_Player_Tech *)0x0) {
    pTVar6 = (TRIBE_Player_Tech *)0x0;
  }
  else {
    pTVar6 = (TRIBE_Player_Tech *)
             TRIBE_Player_Tech::TRIBE_Player_Tech
                       (pTVar6,(TRIBE_Tech *)param_2[1]._padding_,(RGE_Player *)param_1,'\x01');
  }
  param_1->tech_tree = pTVar6;
  param_1->ruin_held_time = -1.0;
  param_1->artifact_held_time = -1.0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005120e2
// Address: 005120e2
// [HELPER] groups_used: "00000000"
void __fastcall FUN_005120e2(RGE_Player *param_1)
{
  TRIBE_Player_Tech *this;
  TRIBE_History_Info *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_005611d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Player::_vftable_;
  this = (TRIBE_Player_Tech *)param_1[1]._padding_;
  uStack_4 = 0;
  if (this != (TRIBE_Player_Tech *)0x0) {
    TRIBE_Player_Tech::~TRIBE_Player_Tech(this);
    operator_delete(this);
    param_1[1]._padding_ = 0;
  }
  if ((undefined4 *)param_1[1].position_checksum != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1].position_checksum)(1);
    param_1[1].position_checksum = 0;
  }
  this_00 = *(TRIBE_History_Info **)(param_1[3].groups_used + 0x3e);
  if (this_00 != (TRIBE_History_Info *)0x0) {
    TRIBE_History_Info::~TRIBE_History_Info(this_00);
    operator_delete(this_00);
    param_1[3].groups_used[0x3e] = '\0';
    param_1[3].groups_used[0x3f] = '\0';
    param_1[3].groups_used[0x40] = '\0';
    param_1[3].groups_used[0x41] = '\0';
  }
  uStack_4 = 0xffffffff;
  RGE_Player::~RGE_Player(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00512192
// Address: 00512192
TRIBE_Building_Object * __thiscall
FUN_00512192(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,short param_5)
{
  byte bVar1;
  int *piVar2;
  undefined1 uVar3;
  TRIBE_Building_Object *this;
  
  this = (TRIBE_Building_Object *)0x0;
  piVar2 = *(int **)(*(int *)(param_1 + 0x24) + param_5 * 4);
  if (piVar2 != (int *)0x0) {
    this = (TRIBE_Building_Object *)(**(code **)(*piVar2 + 0x18))(param_1,param_2,param_3,param_4);
    if ((byte)param_2 < 7) {
      if ((byte)param_2 < 3) {
        bVar1 = *(byte *)(this->_padding_ + 4);
        if ((bVar1 < 0x1f) || (0x59 < bVar1)) {
          uVar3 = __ftol();
          *(undefined1 *)((int)&this->_padding_ + 1) = uVar3;
        }
        else {
          (**(code **)(this->_padding_ + 0xb4))(param_3);
        }
      }
      else {
        (**(code **)(this->_padding_ + 0x6c))();
      }
    }
    else {
      (**(code **)(this->_padding_ + 0x68))();
    }
    if ((*(char *)(*(int *)(*(int *)(param_1 + 0x24) + param_5 * 4) + 4) == 'P') &&
       ((byte)param_2 == 2)) {
      TRIBE_Building_Object::build(this,10000.0);
    }
  }
  return this;
}

// --------------------------------------------------

// Function: FUN_00512242
// Address: 00512242
// [HELPER] groups_used: "00000000"
void __thiscall FUN_00512242(RGE_Player *param_1,int param_2)
{
  int iVar1;
  
  color_log('\x16','\x16',2);
  iVar1 = param_2;
  RGE_Player::save(param_1,param_2);
  color_log('\x16','$',2);
  rge_write(iVar1,&param_1->type,1);
  rge_write(iVar1,&param_1[1].pathingAttemptCapValue,4);
  rge_write(iVar1,&param_1[1].currentUpdatePathingAttemptsValue,4);
  rge_write(iVar1,&param_1[1].computerPlayerValue,4);
  rge_write(iVar1,&param_1[1].checksum,4);
  TRIBE_Player_Tech::save((TRIBE_Player_Tech *)param_1[1]._padding_,iVar1);
  rge_write(iVar1,&param_1[1].pathingDelayCapValue,4);
  TRIBE_History_Info::save(*(TRIBE_History_Info **)(param_1[3].groups_used + 0x3e),iVar1);
  rge_write(iVar1,param_1[3].groups_used + 0x42,4);
  rge_write(iVar1,param_1[3].groups_used + 0x46,4);
  color_log('\x16','L',2);
  if (param_1->computerPlayerValue == 1) {
    if (param_1[1].position_checksum != 0) {
      param_2 = TCommunications_Handler::IsHost(comm);
      if (param_2 == 1) {
        rge_write(iVar1,&param_2,4);
        (**(code **)(*(int *)param_1[1].position_checksum + 0x3c))(iVar1);
        color_log('\x16','_',2);
        return;
      }
    }
    param_2 = 0;
    rge_write(iVar1,&param_2,4);
  }
  color_log('\x16','_',2);
  return;
}

// --------------------------------------------------

// Function: FUN_005123af
// Address: 005123af
// [HELPER] groups_used: "00000000"
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005123af(RGE_Player *param_1)
{
  short sVar1;
  float *pfVar2;
  uchar uVar3;
  int iVar4;
  uint uVar5;
  RGE_Object_Node *pRVar6;
  int iVar7;
  float fVar8;
  
  fVar8 = param_1->world->world_time_delta_seconds + (float)param_1[1].checksum;
  param_1[1].checksum = (long)fVar8;
  if (_DAT_00576824 < fVar8) {
    do {
      iVar4 = param_1[1].pathingDelayCapValue;
      fVar8 = (float)param_1[1].checksum - _DAT_00576824;
      iVar7 = iVar4 + 1;
      param_1[1].pathingDelayCapValue = iVar7;
      param_1[1].checksum = (long)fVar8;
      if (0xe < iVar7) {
        pfVar2 = param_1->attributes;
        param_1[1].pathingDelayCapValue = iVar4 + -0xe;
        if (_DAT_00576828 <= pfVar2[0xb]) {
          uVar3 = __ftol();
        }
        else {
          uVar3 = '\0';
        }
        TRIBE_History_Info::add_history_entry
                  (*(TRIBE_History_Info **)(param_1[3].groups_used + 0x3e),'\0',uVar3);
      }
      iVar4 = RGE_Base_Game::fullVisibility(rge_base_game);
      if (iVar4 == 0) {
        fVar8 = RGE_Visible_Map::percentExplored(param_1->visible);
        param_1->attributes[0x16] = fVar8 * _DAT_0057682c;
      }
      else {
        param_1->attributes[0x16] = 100.0;
      }
      pfVar2 = param_1->attributes;
      pfVar2[0x2c] = pfVar2[0x14] - (pfVar2[0x13] - pfVar2[0xb]);
      if (param_1->attributes[0x2c] < (float)_DAT_00576830) {
        param_1->attributes[0x2c] = 0.0;
      }
      pfVar2 = param_1->attributes;
      pfVar2[9] = pfVar2[10] + pfVar2[9];
      if ((float)_DAT_00576838 < param_1->attributes[9]) {
        param_1->attributes[9] = 100.0;
      }
      if (0 < param_1[1].pathingAttemptCapValue) {
        param_1[1].pathingAttemptCapValue = param_1[1].pathingAttemptCapValue + -1;
      }
      if (0 < param_1[1].currentUpdatePathingAttemptsValue) {
        param_1[1].currentUpdatePathingAttemptsValue =
             param_1[1].currentUpdatePathingAttemptsValue + -1;
      }
      if (0 < param_1->id) {
        pRVar6 = param_1->objects->list;
        if (pRVar6 != (RGE_Object_Node *)0x0) {
          do {
            sVar1 = pRVar6->node->master_obj->object_group;
            if ((((((sVar1 != 0xb) && (sVar1 != 0x1e)) && (sVar1 != 0x1b)) &&
                 ((sVar1 != 1 && (sVar1 != 0x15)))) &&
                ((sVar1 != 0x14 && ((sVar1 != 2 && (sVar1 != 0x25)))))) &&
               (pRVar6->node->object_state == '\x02')) break;
            pRVar6 = pRVar6->next;
          } while (pRVar6 != (RGE_Object_Node *)0x0);
          if (pRVar6 != (RGE_Object_Node *)0x0) goto LAB_00512540;
        }
        (**(code **)(param_1->_padding_ + 4))(2);
        param_1->attributes[0x2d] = 0.0;
      }
LAB_00512540:
    } while (_DAT_00576824 < (float)param_1[1].checksum);
  }
  RGE_Player::update(param_1);
  pfVar2 = param_1->attributes;
  *pfVar2 = *pfVar2 - param_1->world->world_time_delta_seconds * pfVar2[0x21] * pfVar2[0xb] *
                      _DAT_00576840;
  if (*param_1->attributes < (float)_DAT_00576830) {
    *param_1->attributes = 0.0;
  }
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x25f);
  iVar4 = debug_random_on;
  global_save_debug_random_on1 = debug_random_on;
  debug_random_on = 0;
  if ((param_1[1].position_checksum != 0) &&
     (iVar7 = TCommunications_Handler::ComputerPlayerGameStart(comm), iVar7 == 1)) {
    if (param_1->world->currentUpdateComputerPlayer == -1) {
      RGE_Game_World::selectNextComputerPlayer(param_1->world,3);
    }
    (**(code **)(*(int *)param_1[1].position_checksum + 0x30))(0);
  }
  debug_random_on = iVar4;
  debug_srand(s_C__msdev_work_age1_x1_tplayer_cp,0x277,uVar5);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00512625
// Address: 00512625
void __thiscall FUN_00512625(RGE_Player *param_1,int param_2)
{
  RGE_Player::scenario_save(param_1,param_2);
  rge_write(param_2,param_1->attributes,4);
  rge_write(param_2,param_1->attributes + 1,4);
  rge_write(param_2,param_1->attributes + 3,4);
  rge_write(param_2,param_1->attributes + 2,4);
  return;
}

// --------------------------------------------------

// Function: FUN_00512688
// Address: 00512688
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00512688(TRIBE_Player *param_1,int param_2,long *param_3,float param_4)
{
  RGE_Master_Static_Object *this;
  float fVar1;
  TRIBE_Player_Tech *pTVar2;
  TRIBE_Effects *this_00;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  short sVar4;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561206;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Player::scenario_load((RGE_Player *)param_1,param_2,param_3,param_4);
  pTVar2 = param_1->tech_tree;
  if (pTVar2 != (TRIBE_Player_Tech *)0x0) {
    TRIBE_Player_Tech::~TRIBE_Player_Tech(pTVar2);
    operator_delete(pTVar2);
  }
  iVar3 = 0;
  if (0 < *(short *)((int)&param_1->_padding_ + 2)) {
    do {
      this = *(RGE_Master_Static_Object **)(param_1->_padding_ + iVar3 * 4);
      if (this != (RGE_Master_Static_Object *)0x0) {
        RGE_Master_Static_Object::make_available(this,'\0');
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(short *)((int)&param_1->_padding_ + 2));
  }
  if ((float)_DAT_00576848 < param_4) {
    rge_read(param_2,(void *)param_1->_padding_,4);
    rge_read(param_2,(void *)(param_1->_padding_ + 4),4);
    rge_read(param_2,(void *)(param_1->_padding_ + 0xc),4);
    rge_read(param_2,(void *)(param_1->_padding_ + 8),4);
  }
  fVar1 = (float)_DAT_00576850;
  *(undefined4 *)(param_1->_padding_ + 0x78) = 0;
  *(undefined4 *)(param_1->_padding_ + 0x54) = 0;
  if (param_4 <= fVar1) {
    pTVar2 = (TRIBE_Player_Tech *)operator_new(0x10);
    uStack_4 = 0;
    if (pTVar2 != (TRIBE_Player_Tech *)0x0) {
      pTVar2 = (TRIBE_Player_Tech *)
               TRIBE_Player_Tech::TRIBE_Player_Tech
                         (pTVar2,param_2,*(TRIBE_Tech **)(param_1->_padding_ + 0x104),
                          (RGE_Player *)param_1,'\x01');
      param_1->tech_tree = pTVar2;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    param_1->tech_tree = (TRIBE_Player_Tech *)0x0;
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  pTVar2 = (TRIBE_Player_Tech *)operator_new(0x10);
  uStack_4 = 1;
  if (pTVar2 == (TRIBE_Player_Tech *)0x0) {
    pTVar2 = (TRIBE_Player_Tech *)0x0;
  }
  else {
    pTVar2 = (TRIBE_Player_Tech *)
             TRIBE_Player_Tech::TRIBE_Player_Tech
                       (pTVar2,*(TRIBE_Tech **)(param_1->_padding_ + 0x104),(RGE_Player *)param_1,
                        '\0');
  }
  param_1->tech_tree = pTVar2;
  uStack_4 = 0xffffffff;
  if (-1 < param_1->_padding_) {
    iVar3 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
    if (iVar3 == 0) {
      iVar3 = T_Scenario::GetScenarioOption(*(T_Scenario **)(param_1->_padding_ + 0x5c),2);
      if (iVar3 == 0) {
        sVar4 = (short)param_1->_padding_;
        this_00 = *(TRIBE_Effects **)(param_1->_padding_ + 0x4c);
        goto LAB_00512861;
      }
    }
  }
  sVar4 = 0xd2;
  this_00 = *(TRIBE_Effects **)(param_1->_padding_ + 0x4c);
LAB_00512861:
  TRIBE_Effects::do_tech_effect(this_00,sVar4,(RGE_Player *)param_1);
  if (rge_base_game->game_mode != 7) {
    T_Scenario::set_player_tech(*(T_Scenario **)(param_1->_padding_ + 0x5c),param_1);
  }
  TRIBE_Player_Tech::check_for_new_tech(param_1->tech_tree);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00512a89
// Address: 00512a89
void __thiscall
FUN_00512a89(RGE_Player *param_1,int param_2,short param_3,uchar param_4,RGE_Sprite **param_5,
            RGE_Sound **param_6)
{
  TRIBE_Master_Tree_Object *this;
  RGE_Master_Static_Object *pRVar1;
  TRIBE_Master_Building_Object *this_00;
  TRIBE_Master_Combat_Object *this_01;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561281;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_4 == 'F') {
    this_01 = (TRIBE_Master_Combat_Object *)operator_new(0x164);
    uStack_4 = 0;
    if (this_01 != (TRIBE_Master_Combat_Object *)0x0) {
      pRVar1 = (RGE_Master_Static_Object *)
               TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
                         (this_01,param_2,param_5,param_6,1);
      goto LAB_00512bd2;
    }
  }
  else {
    if (param_4 == 'P') {
      this_00 = (TRIBE_Master_Building_Object *)operator_new(0x17c);
      uStack_4 = 1;
      if (this_00 != (TRIBE_Master_Building_Object *)0x0) {
        pRVar1 = (RGE_Master_Static_Object *)
                 TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
                           (this_00,param_2,param_5,param_6,1);
        param_1->master_objects[param_3] = pRVar1;
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
      param_1->master_objects[param_3] = (RGE_Master_Static_Object *)0x0;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    if (param_4 != 'Z') {
      RGE_Player::load_master_object(param_1,param_2,param_3,param_4,param_5,param_6);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    this = (TRIBE_Master_Tree_Object *)operator_new(0xb8);
    uStack_4 = 2;
    if (this != (TRIBE_Master_Tree_Object *)0x0) {
      pRVar1 = (RGE_Master_Static_Object *)
               TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(this,param_2,param_5,param_6,1);
      goto LAB_00512bd2;
    }
  }
  pRVar1 = (RGE_Master_Static_Object *)0x0;
LAB_00512bd2:
  param_1->master_objects[param_3] = pRVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00512bef
// Address: 00512bef
void __thiscall
FUN_00512bef(int param_1,short param_2,short *param_3,short *param_4,short *param_5,short *param_6,
            short *param_7,short *param_8)
{
  TRIBE_Player_Tech::tech_cost
            (*(TRIBE_Player_Tech **)(param_1 + 0x220),param_2,param_3,param_4,param_5,param_6,
             param_7,param_8);
  return;
}

// --------------------------------------------------

// Function: FUN_00512c21
// Address: 00512c21
void __thiscall
FUN_00512c21(TRIBE_Player *param_1,short param_2,undefined4 *param_3,short *param_4,short *param_5,
            short *param_6,short *param_7,short *param_8,short *param_9)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  short sVar4;
  short *psVar5;
  short sVar6;
  
  *param_4 = -1;
  *param_5 = 0;
  *param_6 = -1;
  *param_7 = 0;
  *param_8 = -1;
  *param_9 = 0;
  uVar2 = TRIBE_Player::check_obj_cost(param_1,param_2,(short *)0x0,1.0,0);
  iVar1 = *(int *)(param_1->_padding_ + param_2 * 4);
  if (iVar1 == 0) {
    return;
  }
  if (*(byte *)(iVar1 + 4) < 0x46) {
    return;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(iVar1 + 8);
  }
  sVar6 = 0;
  if ((*(char *)(iVar1 + 0x14c) != '\0') &&
     (sVar3 = *(short *)(iVar1 + 0x148), *param_4 = sVar3, -1 < sVar3)) {
    sVar3 = __ftol();
    *param_5 = sVar3;
    sVar6 = 0;
    if ((*(float *)(param_1->_padding_ + *param_4 * 4) < (float)(int)sVar3) && (uVar2 != '\0')) {
      sVar4 = __ftol();
      sVar6 = sVar3 - sVar4;
      *param_5 = sVar4;
    }
  }
  if ((*(char *)(iVar1 + 0x152) != '\0') &&
     (sVar3 = *(short *)(iVar1 + 0x14e), *param_6 = sVar3, -1 < sVar3)) {
    sVar3 = __ftol();
    *param_7 = sVar3;
    if ((*(float *)(param_1->_padding_ + *param_6 * 4) < (float)(int)sVar3) && (uVar2 != '\0')) {
      sVar4 = __ftol();
      sVar6 = sVar6 + (sVar3 - sVar4);
      *param_7 = sVar4;
    }
  }
  if ((*(char *)(iVar1 + 0x158) != '\0') &&
     (sVar3 = *(short *)(iVar1 + 0x154), *param_8 = sVar3, -1 < sVar3)) {
    sVar3 = __ftol();
    *param_9 = sVar3;
    if ((*(float *)(param_1->_padding_ + *param_8 * 4) < (float)(int)sVar3) && (uVar2 != '\0')) {
      sVar4 = __ftol();
      sVar6 = sVar6 + (sVar3 - sVar4);
      *param_9 = sVar4;
    }
  }
  if (0 < sVar6) {
    if ((*param_4 == 3) || (*param_4 == -1)) {
      *param_4 = 3;
      psVar5 = param_5;
    }
    else {
      if ((*param_6 != 3) && (*param_6 != -1)) {
        if ((*param_8 == 3) || (*param_8 == -1)) {
          *param_8 = 3;
          *param_9 = sVar6;
        }
        goto LAB_00512e79;
      }
      *param_6 = 3;
      psVar5 = param_7;
    }
    *psVar5 = *psVar5 + sVar6;
  }
LAB_00512e79:
  if (*param_5 < 1) {
    *param_4 = -1;
  }
  if (*param_7 < 1) {
    *param_6 = -1;
  }
  if (*param_9 < 1) {
    *param_8 = -1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00512eb2
// Address: 00512eb2
int __thiscall FUN_00512eb2(int param_1,short param_2,int param_3)
{
  int iVar1;
  bool bVar2;
  int *piVar3;
  
  if (param_3 != 0) {
    bVar2 = false;
    for (piVar3 = *(int **)(*(int *)(param_1 + 0x28) + 4); piVar3 != (int *)0x0;
        piVar3 = (int *)piVar3[1]) {
      iVar1 = *piVar3;
      if (iVar1 != 0) {
        if (bVar2) {
          if ((*(short *)(*(int *)(iVar1 + 8) + 0x10) == param_2) && (*(byte *)(iVar1 + 0x48) < 3))
{
            return *piVar3;
          }
        }
        else if (iVar1 == param_3) {
          bVar2 = true;
        }
      }
    }
  }
  piVar3 = *(int **)(*(int *)(param_1 + 0x28) + 4);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  while (((iVar1 = *piVar3, iVar1 == 0 || (*(short *)(*(int *)(iVar1 + 8) + 0x10) != param_2)) ||
         (*(char *)(iVar1 + 0x48) != '\x02'))) {
    piVar3 = (int *)piVar3[1];
    if (piVar3 == (int *)0x0) {
      return 0;
    }
  }
  return *piVar3;
}

// --------------------------------------------------

// Function: FUN_00512f52
// Address: 00512f52
TRIBE_Building_Object * __thiscall
FUN_00512f52(RGE_Player *param_1,long param_2,float param_3,float param_4,float param_5,int param_6)
{
  short sVar1;
  TRIBE_Building_Object *this;
  
  this = (TRIBE_Building_Object *)
         RGE_Player::make_new_object(param_1,param_2,param_3,param_4,param_5,param_6);
  if (this != (TRIBE_Building_Object *)0x0) {
    if (param_6 != 0) {
      TRIBE_World::check_destructables
                ((TRIBE_World *)param_1->world,param_1->id,(short)param_2,param_3,param_4,'\0');
      if (*(char *)(this->_padding_ + 4) == 'P') {
        TRIBE_Building_Object::build(this,10000.0);
      }
    }
    if ((rge_base_game->prog_mode == 7) &&
       ((sVar1 = *(short *)(this->_padding_ + 0x14), sVar1 == 5 || (sVar1 == 0x21)))) {
      (**(code **)(*(int *)this->_padding_ + 0x1c))(this->_padding_,5);
    }
  }
  return this;
}

// --------------------------------------------------

// Function: FUN_00512ff7
// Address: 00512ff7
void __thiscall FUN_00512ff7(int param_1,int *param_2,short *param_3,short param_4)
{
  undefined4 *puVar1;
  int *piVar2;
  short *psVar3;
  long lVar4;
  short *psVar5;
  int *piVar6;
  int iVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  short sStack_12;
  short sStack_10;
  short sStack_e;
  short sStack_c;
  short sStack_a;
  int iStack_8;
  int iStack_4;
  
  piVar2 = param_2;
  sVar8 = 0;
  sVar9 = (short)(*(int **)(param_1 + 0x220))[1];
  iVar10 = **(int **)(*(int *)(param_1 + 0x3c) + 0x104);
  if (0 < sVar9) {
    psVar5 = (short *)(iVar10 + 0x28);
    psVar3 = (short *)(**(int **)(param_1 + 0x220) + 4);
    iVar7 = (int)sVar9;
    sVar8 = 0;
    do {
      if ((*psVar3 == 1) && (*psVar5 == param_4)) {
        sVar8 = sVar8 + 1;
      }
      psVar3 = psVar3 + 4;
      psVar5 = psVar5 + 0x1e;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  iStack_4 = iVar10;
  if (*param_2 != 0) {
    free(*param_2);
    *piVar2 = 0;
  }
  *param_3 = sVar8;
  if (sVar8 != 0) {
    iVar7 = calloc((int)sVar8,0x28);
    *piVar2 = iVar7;
    piVar6 = *(int **)(param_1 + 0x220);
    sVar9 = 0;
    param_3 = (short *)0x0;
    if (0 < (short)piVar6[1]) {
      do {
        iVar7 = (int)sVar9;
        if ((*(short *)(*piVar6 + 4 + iVar7 * 8) == 1) &&
           (puVar1 = (undefined4 *)(iVar10 + iVar7 * 0x3c),
           *(short *)(iVar10 + 0x28 + iVar7 * 0x3c) == param_4)) {
          iVar10 = (short)param_3 * 0x28;
          *(short *)(*piVar2 + 4 + iVar10) = sVar9;
          *(undefined2 *)(*piVar2 + 6 + iVar10) = *(undefined2 *)(puVar1 + 9);
          *(undefined4 *)(*piVar2 + iVar10) = *puVar1;
          TRIBE_Player_Tech::tech_cost
                    (*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar9,(short *)&param_2,&sStack_12,
                     &sStack_10,&sStack_e,&sStack_c,&sStack_a);
          *(short *)(*piVar2 + 8 + iVar10) = (short)param_2;
          *(float *)(*piVar2 + 0xc + iVar10) = (float)(int)sStack_12;
          *(short *)(*piVar2 + 0x10 + iVar10) = sStack_10;
          *(float *)(*piVar2 + 0x14 + iVar10) = (float)(int)sStack_e;
          *(short *)(*piVar2 + 0x18 + iVar10) = sStack_c;
          iStack_8 = (int)sStack_a;
          *(float *)(*piVar2 + 0x1c + iVar10) = (float)iStack_8;
          lVar4 = TRIBE_Player_Tech::get_help_message
                            (*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar9);
          *(long *)(*piVar2 + 0x20 + iVar10) = lVar4;
          lVar4 = TRIBE_Player_Tech::get_help_page(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar9);
          *(long *)(*piVar2 + 0x24 + iVar10) = lVar4;
          param_3 = (short *)((int)param_3 + 1);
          iVar10 = iStack_4;
        }
        piVar6 = *(int **)(param_1 + 0x220);
        sVar9 = sVar9 + 1;
      } while (sVar9 < (short)piVar6[1]);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005131be
// Address: 005131be
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005131be(TRIBE_Player *param_1,int *param_2,short *param_3,int param_4)
{
  int iVar1;
  int *piVar2;
  short sVar3;
  long lVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  short sStack_16;
  short sStack_14;
  short sStack_12;
  short sStack_10;
  short sStack_e;
  undefined4 uStack_c;
  int iStack_8;
  int iStack_4;
  
  piVar2 = param_2;
  sVar8 = 0;
  sVar3 = *(short *)((int)&param_1->_padding_ + 2);
  uStack_c = 0;
  if (0 < sVar3) {
    piVar5 = (int *)param_1->_padding_;
    iVar6 = (int)sVar3;
    do {
      iVar1 = *piVar5;
      if ((((iVar1 != 0) && (0x45 < *(byte *)(iVar1 + 4))) && (*(char *)(iVar1 + 0x52) != '\0')) &&
         (*(short *)(iVar1 + 0x15c) == (short)param_4)) {
        sVar8 = sVar8 + 1;
      }
      piVar5 = piVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if ((((short)param_4 == 0x76) && (*(float *)(param_1->_padding_ + 0xc0) == _DAT_00576828)) &&
     (*(char *)(*(int *)(param_1->_padding_ + 0x1b4) + 0x52) == '\0')) {
    uStack_c = 1;
    for (piVar5 = *(int **)(param_1->_padding_ + 4); piVar5 != (int *)0x0; piVar5 = (int *)piVar5[1]
        ) {
      if (*(short *)(*(int *)(*piVar5 + 8) + 0x10) == 0x6d) {
        uStack_c = 0;
      }
    }
  }
  if ((short)uStack_c != 0) {
    sVar8 = sVar8 + 1;
  }
  if (*param_2 != 0) {
    free(*param_2);
    *piVar2 = 0;
  }
  *param_3 = sVar8;
  if (sVar8 != 0) {
    iVar6 = calloc((int)sVar8,0x28);
    *piVar2 = iVar6;
    iVar6 = 0;
    sVar3 = 0;
    param_3 = (short *)0x0;
    iStack_8 = 0;
    if (0 < *(short *)((int)&param_1->_padding_ + 2)) {
      do {
        sVar3 = (short)iStack_8;
        iVar7 = sVar3 * 4;
        iVar1 = *(int *)(iVar7 + param_1->_padding_);
        if (((iVar1 != 0) && (0x45 < *(byte *)(iVar1 + 4))) &&
           ((*(char *)(iVar1 + 0x52) != '\0' && (*(short *)(iVar1 + 0x15c) == (short)param_4)))) {
          iVar6 = (short)iVar6 * 0x28;
          *(short *)(*piVar2 + 4 + iVar6) = sVar3;
          *(undefined2 *)(*piVar2 + 6 + iVar6) =
               *(undefined2 *)(*(int *)(iVar7 + param_1->_padding_) + 0x4c);
          *(undefined4 *)(*piVar2 + iVar6) =
               *(undefined4 *)(*(int *)(iVar7 + param_1->_padding_) + 8);
          TRIBE_Player::obj_cost
                    (param_1,sVar3,(char **)0x0,(short *)&param_2,&sStack_16,&sStack_14,&sStack_12,
                     &sStack_10,&sStack_e,1.0);
          *(short *)(*piVar2 + 8 + iVar6) = (short)param_2;
          *(float *)(*piVar2 + 0xc + iVar6) = (float)(int)sStack_16;
          *(short *)(*piVar2 + 0x10 + iVar6) = sStack_14;
          *(float *)(*piVar2 + 0x14 + iVar6) = (float)(int)sStack_12;
          *(short *)(*piVar2 + 0x18 + iVar6) = sStack_10;
          iStack_4 = (int)sStack_e;
          *(float *)(*piVar2 + 0x1c + iVar6) = (float)iStack_4;
          lVar4 = RGE_Master_Static_Object::get_help_message
                            (*(RGE_Master_Static_Object **)(iVar7 + param_1->_padding_));
          *(long *)(*piVar2 + 0x20 + iVar6) = lVar4;
          lVar4 = RGE_Master_Static_Object::get_help_page
                            (*(RGE_Master_Static_Object **)(iVar7 + param_1->_padding_));
          *(long *)(*piVar2 + 0x24 + iVar6) = lVar4;
          iVar6 = (int)param_3 + 1;
          param_3 = (short *)iVar6;
        }
        sVar3 = (short)iVar6;
        iStack_8 = iStack_8 + 1;
      } while ((short)iStack_8 < *(short *)((int)&param_1->_padding_ + 2));
    }
    if ((short)uStack_c != 0) {
      iVar6 = sVar3 * 0x28;
      *(undefined2 *)(*piVar2 + 4 + iVar6) = 0x6d;
      *(undefined2 *)(*piVar2 + 6 + iVar6) =
           *(undefined2 *)(*(int *)(param_1->_padding_ + 0x1b4) + 0x4c);
      *(undefined4 *)(*piVar2 + iVar6) = *(undefined4 *)(*(int *)(param_1->_padding_ + 0x1b4) + 8);
      TRIBE_Player::obj_cost
                (param_1,0x6d,(char **)0x0,(short *)&param_2,&sStack_16,&sStack_14,&sStack_12,
                 &sStack_10,&sStack_e,1.0);
      *(short *)(*piVar2 + 8 + iVar6) = (short)param_2;
      *(float *)(*piVar2 + 0xc + iVar6) = (float)(int)sStack_16;
      *(short *)(*piVar2 + 0x10 + iVar6) = sStack_14;
      *(float *)(*piVar2 + 0x14 + iVar6) = (float)(int)sStack_12;
      *(short *)(*piVar2 + 0x18 + iVar6) = sStack_10;
      param_4 = (int)sStack_e;
      *(float *)(*piVar2 + 0x1c + iVar6) = (float)param_4;
      lVar4 = RGE_Master_Static_Object::get_help_message
                        (*(RGE_Master_Static_Object **)(param_1->_padding_ + 0x1b4));
      *(long *)(*piVar2 + 0x20 + iVar6) = lVar4;
      lVar4 = RGE_Master_Static_Object::get_help_page
                        (*(RGE_Master_Static_Object **)(param_1->_padding_ + 0x1b4));
      *(long *)(*piVar2 + 0x24 + iVar6) = lVar4;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005134e4
// Address: 005134e4
void __thiscall FUN_005134e4(int param_1,int *param_2,undefined2 *param_3)
{
  undefined4 uVar1;
  uchar uVar2;
  short sVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iStack_188;
  int aiStack_180 [96];
  
  iVar5 = *(int *)(param_1 + 0x3c);
  iVar8 = 0;
  iStack_188 = 1;
  if (1 < *(short *)(iVar5 + 0x3c)) {
    do {
      if ((iStack_188 != *(short *)(param_1 + 0x4a)) &&
         (piVar6 = *(int **)(*(int *)(*(int *)(*(int *)(iVar5 + 0x40) + iStack_188 * 4) + 0x28) + 4)
         , piVar6 != (int *)0x0)) {
        piVar7 = aiStack_180 + iVar8;
        do {
          if (*(short *)(*(int *)(*piVar6 + 8) + 0x10) == 0x2d) {
            sVar3 = __ftol();
            iVar5 = (int)sVar3;
            sVar3 = __ftol();
            uVar2 = RGE_Visible_Map::get_visible
                              (*(RGE_Visible_Map **)(param_1 + 0x38),(int)sVar3,iVar5);
            if (uVar2 != '\0') {
              iVar8 = iVar8 + 1;
              *piVar7 = *piVar6;
              piVar7 = piVar7 + 1;
            }
          }
          piVar6 = (int *)piVar6[1];
        } while (piVar6 != (int *)0x0);
      }
      iVar5 = *(int *)(param_1 + 0x3c);
      iStack_188 = iStack_188 + 1;
    } while (iStack_188 < *(short *)(iVar5 + 0x3c));
  }
  if (*param_2 != 0) {
    free(*param_2);
    *param_2 = 0;
  }
  *param_3 = (short)iVar8;
  if (iVar8 != 0) {
    puVar4 = (undefined4 *)calloc(iVar8,0xc);
    *param_2 = (int)puVar4;
    if (0 < iVar8) {
      piVar6 = aiStack_180;
      do {
        iVar5 = *piVar6;
        piVar6 = piVar6 + 1;
        iVar8 = iVar8 + -1;
        uVar1 = *(undefined4 *)(iVar5 + 0xc);
        puVar4[1] = iVar5;
        *puVar4 = uVar1;
        puVar4[2] = *(undefined4 *)(iVar5 + 0x44);
        puVar4 = puVar4 + 3;
      } while (iVar8 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005135f1
// Address: 005135f1
undefined4 __thiscall
FUN_005135f1(RGE_Player *param_1,RGE_Static_Object **param_2,float param_3,float param_4)
{
  uchar uVar1;
  short sVar2;
  RGE_Player *pRStack_4;
  
  sVar2 = (short)param_2;
  if ((param_1->master_objects[sVar2] != (RGE_Master_Static_Object *)0x0) &&
     ((param_1->master_objects[sVar2]->available != '\0' || (sVar2 == 0x6d)))) {
    pRStack_4 = param_1;
    uVar1 = RGE_Player::get_selected_objects_to_command
                      (param_1,&param_2,(short *)&pRStack_4,4,4,-1,-1);
    if (uVar1 != '\0') {
      (**(code **)(param_1->master_objects[0x76]->_padding_ + 0x2c))();
      TRIBE_Command::command_build
                ((TRIBE_Command *)param_1->world->commands,param_2,(short)pRStack_4,sVar2,param_3,
                 param_4);
      free(param_2);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051368b
// Address: 0051368b
undefined4 __thiscall
FUN_0051368b(RGE_Player *param_1,RGE_Static_Object **param_2,long param_3,long param_4,long param_5,
            long param_6)
{
  uchar uVar1;
  short sVar2;
  RGE_Player *pRStack_4;
  
  sVar2 = (short)param_2;
  if ((param_1->master_objects[sVar2] != (RGE_Master_Static_Object *)0x0) &&
     (param_1->master_objects[sVar2]->available != '\0')) {
    pRStack_4 = param_1;
    uVar1 = RGE_Player::get_selected_objects_to_command
                      (param_1,&param_2,(short *)&pRStack_4,4,4,-1,-1);
    if (uVar1 != '\0') {
      (**(code **)(param_1->master_objects[0x76]->_padding_ + 0x2c))();
      TRIBE_Command::command_build_wall
                ((TRIBE_Command *)param_1->world->commands,param_2,(short)pRStack_4,sVar2,param_3,
                 param_4,param_5,param_6);
      free(param_2);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051371f
// Address: 0051371f
undefined4 __thiscall FUN_0051371f(int param_1,short param_2)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = *(RGE_Static_Object **)(param_1 + 0x130);
  if ((pRVar1 != (RGE_Static_Object *)0x0) && (pRVar1->master_obj->master_type == 'P')) {
    TRIBE_Command::command_research
              (*(TRIBE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),pRVar1,param_2);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051374e
// Address: 0051374e
undefined4 __fastcall FUN_0051374e(RGE_Player *param_1)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = param_1->selected_obj;
  if ((pRVar2 != (RGE_Static_Object *)0x0) && (pRVar2->owner == param_1)) {
    uVar1 = pRVar2->master_obj->master_type;
    if (((uVar1 == 'P') || (uVar1 == 'F')) && (pRVar2->master_obj->object_group != 1)) {
      TRIBE_Command::command_cancel_build((TRIBE_Command *)param_1->world->commands,pRVar2);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051378b
// Address: 0051378b
undefined4 __thiscall FUN_0051378b(RGE_Player *param_1,RGE_Static_Object *param_2)
{
  uchar uVar1;
  
  if (((param_2 != (RGE_Static_Object *)0x0) && (param_2->owner == param_1)) &&
     ((uVar1 = param_2->master_obj->master_type, uVar1 == 'P' || (uVar1 == 'F')))) {
    TRIBE_Command::command_cancel_build((TRIBE_Command *)param_1->world->commands,param_2);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005137c3
// Address: 005137c3
undefined4 __thiscall FUN_005137c3(RGE_Player *param_1,long param_2)
{
  uchar uVar1;
  RGE_Static_Object **ppRStack_8;
  short asStack_4 [2];
  
  uVar1 = RGE_Player::get_selected_objects_to_command(param_1,&ppRStack_8,asStack_4,4,-1,-1,5);
  if (uVar1 != '\0') {
    (**(code **)((*ppRStack_8)->_padding_ + 0xac))();
    TRIBE_Command::command_trade_attribute
              ((TRIBE_Command *)param_1->world->commands,ppRStack_8,asStack_4[0],param_2);
    free(ppRStack_8);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051383a
// Address: 0051383a
undefined4 __thiscall FUN_0051383a(int param_1,int param_2,long param_3)
{
  TRIBE_Command::command_trade_attribute
            (*(TRIBE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),param_2,
             (int)*(short *)(param_1 + 0x4a),param_3);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0051385f
// Address: 0051385f
undefined4 __thiscall FUN_0051385f(RGE_Player *param_1,float param_2,float param_3)
{
  uchar uVar1;
  RGE_Static_Object **ppRStack_8;
  short asStack_4 [2];
  
  uVar1 = RGE_Player::get_selected_objects_to_command(param_1,&ppRStack_8,asStack_4,4,-1,-1,4);
  if (uVar1 != '\0') {
    (**(code **)((*ppRStack_8)->_padding_ + 0xac))();
    TRIBE_Command::command_attack_ground
              ((TRIBE_Command *)param_1->world->commands,ppRStack_8,asStack_4[0],param_2,param_3);
    free(ppRStack_8);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005138cf
// Address: 005138cf
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_005138cf(int param_1,undefined4 param_2,int param_3,float param_4,undefined4 param_5)
{
  if (param_3 != -1) {
    if (param_4 != _DAT_00576828) {
      (**(code **)(**(int **)(*(int *)(param_1 + 0x3c) + 0x58) + 0x14))
                ((int)*(short *)(param_1 + 0x4a),param_2,param_3,param_4,param_5);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051391c
// Address: 0051391c
undefined4 __thiscall FUN_0051391c(int param_1,short param_2)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = *(RGE_Static_Object **)(param_1 + 0x130);
  if ((pRVar1 != (RGE_Static_Object *)0x0) && (pRVar1->master_obj->master_type == 'P')) {
    TRIBE_Command::command_make(*(TRIBE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),pRVar1,param_2)
    ;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051394e
// Address: 0051394e
undefined4 __thiscall FUN_0051394e(RGE_Player *param_1,RGE_Static_Object *param_2)
{
  RGE_Static_Object *pRVar1;
  uchar uVar2;
  int iVar3;
  int *piVar4;
  RGE_Static_Object **unaff_ESI;
  short sVar5;
  short asStack_4 [2];
  
  pRVar1 = param_2;
  if ((((param_2->owner != param_1) &&
       (iVar3 = (**(code **)(param_1->_padding_ + 0x1c))((int)param_2->owner->id), iVar3 == 0)) ||
      (pRVar1->master_obj->master_type != 'P')) ||
     (((float)(int)pRVar1->master_obj->hp <= pRVar1->hp || (2 < pRVar1->object_state)))) {
    if (pRVar1->owner != param_1) {
      iVar3 = (**(code **)(param_1->_padding_ + 0x1c))((int)pRVar1->owner->id);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = (**(code **)(pRVar1->owner->_padding_ + 0x1c))((int)param_1->id);
      if (iVar3 == 0) {
        return 0;
      }
    }
    sVar5 = pRVar1->master_obj->object_group;
    if (((sVar5 != 2) && (sVar5 != 0x14)) && ((sVar5 != 0x15 && (sVar5 != 0x16)))) {
      return 0;
    }
    if ((float)(int)pRVar1->master_obj->hp <= pRVar1->hp) {
      return 0;
    }
    if (2 < pRVar1->object_state) {
      return 0;
    }
  }
  uVar2 = RGE_Player::get_selected_objects_to_command
                    (param_1,(RGE_Static_Object ***)&param_2,asStack_4,4,4,-1,-1);
  if (uVar2 == '\0') {
    return 0;
  }
  sVar5 = 0;
  piVar4 = (int *)(**(code **)(*(int *)param_2->_padding_ + 0xbc))(pRVar1,0,0);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x2c))();
  }
  TRIBE_Command::command_repair((TRIBE_Command *)param_1->world->commands,unaff_ESI,sVar5,pRVar1);
  free(unaff_ESI);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00513a78
// Address: 00513a78
undefined4 __thiscall FUN_00513a78(RGE_Player *param_1,float param_2,float param_3)
{
  uchar uVar1;
  RGE_Static_Object **ppRStack_8;
  short asStack_4 [2];
  
  uVar1 = RGE_Player::get_selected_objects_to_command(param_1,&ppRStack_8,asStack_4,4,-1,-1,7);
  if (uVar1 != '\0') {
    (**(code **)((*ppRStack_8)->_padding_ + 0xac))();
    TRIBE_Command::command_unload
              ((TRIBE_Command *)param_1->world->commands,ppRStack_8,asStack_4[0],param_2,param_3);
    free(ppRStack_8);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00513aef
// Address: 00513aef
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_00513aef(int param_1,short param_2,short *param_3,float param_4,int param_5)
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  bool bVar5;
  float fVar6;
  uint uVar7;
  uint uVar8;
  undefined2 uVar9;
  int iVar10;
  short *psVar11;
  int iVar12;
  
  fVar1 = *(float *)(*(int *)(param_1 + 0x50) + 0xc);
  if (param_3 != (short *)0x0) {
    *param_3 = -1;
  }
  iVar4 = *(int *)(param_1 + 0x50);
  bVar5 = (float)_DAT_00576860 <= *(float *)(iVar4 + 0x74);
  if (!bVar5) {
    fVar1 = _DAT_00576828;
  }
  uVar8 = *(uint *)(*(int *)(param_1 + 0x24) + param_2 * 4);
  if ((uVar8 == 0) || (*(byte *)(uVar8 + 4) < 0x46)) {
    if (param_3 != (short *)0x0) {
      *param_3 = -1;
    }
LAB_00513c41:
    return uVar8 & 0xffffff00;
  }
  iVar12 = 0;
  psVar11 = (short *)(uVar8 + 0x14a);
  do {
    iVar10 = (int)psVar11[-1];
    if (-1 < iVar10) {
      uVar7 = (uint)*psVar11;
      fVar6 = (float)(int)uVar7 * param_4;
      if ((iVar10 == 4) && (param_5 == 0)) {
        fVar2 = *(float *)(iVar4 + 0x2c);
        fVar3 = *(float *)(iVar4 + 0x80);
        uVar8 = CONCAT22(*psVar11 >> 0xf,
                         (ushort)(fVar2 < fVar3) << 8 | (ushort)(NAN(fVar2) || NAN(fVar3)) << 10 |
                         (ushort)(fVar2 == fVar3) << 0xe);
        uVar7 = uVar8;
        if (fVar2 >= fVar3) {
          if (param_3 != (short *)0x0) {
            *param_3 = 0x20;
            return uVar8;
          }
          goto LAB_00513c41;
        }
      }
      uVar8 = CONCAT31((int3)(uVar7 >> 8),bVar5);
      if ((bVar5) && (iVar10 == 3)) {
        fVar1 = fVar1 - fVar6;
        uVar8 = CONCAT22((short)(uVar7 >> 0x10),
                         (ushort)(fVar1 < _DAT_00576828) << 8 |
                         (ushort)(NAN(fVar1) || NAN(_DAT_00576828)) << 10 |
                         (ushort)(fVar1 == _DAT_00576828) << 0xe);
        if (fVar1 < _DAT_00576828) {
          if (param_3 != (short *)0x0) {
            *param_3 = 3;
            return uVar8;
          }
          goto LAB_00513c41;
        }
      }
      fVar2 = *(float *)(iVar4 + iVar10 * 4);
      uVar9 = (undefined2)(uVar8 >> 0x10);
      uVar8 = CONCAT22(uVar9,(ushort)(fVar2 < fVar6) << 8 | (ushort)(NAN(fVar2) || NAN(fVar6)) << 10
                             | (ushort)(fVar2 == fVar6) << 0xe);
      if ((fVar2 < fVar6 != 0) && ((iVar10 != 4 || (param_5 == 0)))) {
        uVar8 = CONCAT31((int3)(uVar8 >> 8),(char)psVar11[1]);
        if ((char)psVar11[1] != '\0') {
          fVar2 = fVar1 + *(float *)(iVar4 + iVar10 * 4);
          uVar8 = CONCAT22(uVar9,(ushort)(fVar2 < fVar6) << 8 |
                                 (ushort)(NAN(fVar2) || NAN(fVar6)) << 10 |
                                 (ushort)(fVar2 == fVar6) << 0xe);
          if (fVar2 >= fVar6) {
            fVar1 = fVar1 - (fVar6 - *(float *)(iVar4 + iVar10 * 4));
            goto LAB_00513be4;
          }
        }
        if (param_3 != (short *)0x0) {
          *param_3 = psVar11[-1];
          return uVar8 & 0xffffff00;
        }
        goto LAB_00513c41;
      }
    }
LAB_00513be4:
    iVar12 = iVar12 + 1;
    psVar11 = psVar11 + 3;
    if (2 < iVar12) {
      return CONCAT31((int3)(uVar8 >> 8),1);
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00513c4a
// Address: 00513c4a
undefined4 __thiscall FUN_00513c4a(TRIBE_Player *param_1,short param_2,float param_3,int param_4)
{
  int iVar1;
  float fVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  uVar3 = TRIBE_Player::check_obj_cost(param_1,param_2,(short *)0x0,param_3,param_4);
  if (uVar3 != '\0') {
    iVar5 = 3;
    pcVar6 = (char *)(*(int *)(param_1->_padding_ + param_2 * 4) + 0x14c);
    do {
      iVar4 = (int)*(short *)(pcVar6 + -4);
      if (((-1 < iVar4) && (*pcVar6 != '\0')) && ((param_4 == 0 || (iVar4 != 4)))) {
        iVar1 = param_1->_padding_;
        iVar4 = iVar4 * 4;
        fVar2 = (float)(int)*(short *)(pcVar6 + -2) * param_3;
        if (fVar2 <= *(float *)(iVar1 + iVar4)) {
          *(float *)(iVar1 + iVar4) = *(float *)(iVar1 + iVar4) - fVar2;
        }
        else {
          *(float *)(iVar1 + 0xc) = *(float *)(iVar1 + 0xc) - (fVar2 - *(float *)(iVar1 + iVar4));
          *(undefined4 *)(param_1->_padding_ + iVar4) = 0;
        }
      }
      pcVar6 = pcVar6 + 6;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00513cf4
// Address: 00513cf4
void __thiscall FUN_00513cf4(int param_1,short param_2)
{
  float *pfVar1;
  short *psVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x24) + param_2 * 4);
  if (0x45 < *(byte *)(iVar3 + 4)) {
    psVar2 = (short *)(iVar3 + 0x148);
    iVar3 = 3;
    do {
      if ((-1 < *psVar2) && ((char)psVar2[2] != '\0')) {
        pfVar1 = (float *)(*(int *)(param_1 + 0x50) + *psVar2 * 4);
        *pfVar1 = (float)(int)psVar2[1] + *pfVar1;
      }
      psVar2 = psVar2 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00513d52
// Address: 00513d52
void __thiscall FUN_00513d52(int param_1,short param_2,short *param_3)
{
  TRIBE_Player_Tech::check_tech_cost(*(TRIBE_Player_Tech **)(param_1 + 0x220),param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_00513d78
// Address: 00513d78
void __thiscall FUN_00513d78(int param_1,short param_2)
{
  TRIBE_Player_Tech::start_research
            (*(TRIBE_Player_Tech **)(param_1 + 0x220),param_2,'\x01',(short *)0x0);
  return;
}

// --------------------------------------------------

// Function: FUN_00513d97
// Address: 00513d97
void __thiscall FUN_00513d97(int param_1,short param_2,char param_3)
{
  if (param_3 != '\0') {
    TRIBE_Player_Tech::enable(*(TRIBE_Player_Tech **)(param_1 + 0x220),param_2);
    return;
  }
  TRIBE_Player_Tech::disable(*(TRIBE_Player_Tech **)(param_1 + 0x220),param_2);
  return;
}

// --------------------------------------------------

