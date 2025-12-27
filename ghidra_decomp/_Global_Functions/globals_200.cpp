// GLOBAL FUNCTIONS PART 200
// Function: FUN_00407bf7
// Address: 00407bf7
void FUN_00407bf7(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00407c03
// Address: 00407c03
// [HELPER] s_Attack: "Attack"
// [HELPER] s_Delay: "Delay"
// [HELPER] s_Done: "Done"
// [HELPER] s_Failed: "Failed"
// [HELPER] s_Goto2: "Goto2"
// [HELPER] s_Goto: "Goto"
// [HELPER] s_Invalidated: "Invalidated"
// [HELPER] s_Move: "Move"
// [HELPER] s_MoveNoSearch: "MoveNoSearch"
// [HELPER] s_None: "None"
// [HELPER] s_Return: "Return"
// [HELPER] s_Search: "Search"
// [HELPER] s_Turn: "Turn"
// [HELPER] s_Unknown: "Unknown"
// [HELPER] s_Wait: "Wait"
// [HELPER] s_Work2: "Work2"
// [HELPER] s_Work: "Work"
void __thiscall FUN_00407c03(int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  switch(*(undefined1 *)(param_1 + 0xc)) {
  case 0:
    pcVar5 = &s_None;
    break;
  case 1:
    pcVar5 = s_Done;
    goto LAB_00407c9b;
  case 2:
    pcVar5 = &s_Wait;
    break;
  case 3:
    pcVar5 = s_Search;
    goto LAB_00407c9b;
  case 4:
    pcVar5 = s_Goto;
    break;
  case 5:
    pcVar5 = s_Goto2;
    goto LAB_00407c9b;
  case 6:
    pcVar5 = s_Work;
    break;
  case 7:
    pcVar5 = s_Work2;
    goto LAB_00407c9b;
  case 8:
    pcVar5 = s_Return;
    break;
  case 9:
    pcVar5 = s_Turn;
    goto LAB_00407c9b;
  case 10:
    pcVar5 = s_Delay;
    break;
  case 0xb:
    pcVar5 = &s_Move;
    goto LAB_00407c9b;
  case 0xc:
    pcVar5 = &s_Attack;
    break;
  case 0xd:
    pcVar5 = s_Failed;
    goto LAB_00407c9b;
  case 0xe:
    pcVar5 = &s_Invalidated;
    break;
  case 0xf:
    pcVar5 = &s_MoveNoSearch;
LAB_00407c9b:
    uVar2 = 0xffffffff;
    do {
      pcVar4 = pcVar5;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar4 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar4;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar5 = pcVar4 + -uVar2;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)param_2 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      param_2 = param_2 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      param_2 = param_2 + 1;
    }
    return;
  default:
    pcVar5 = &s_Unknown;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar5 = pcVar4 + -uVar2;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)param_2 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    param_2 = param_2 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    param_2 = param_2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00407d34
// Address: 00407d34
float10 __fastcall FUN_00407d34(int param_1)
{
  return (float10)*(float *)(param_1 + 0x24);
}

// --------------------------------------------------

// Function: FUN_00407d44
// Address: 00407d44
float10 __fastcall FUN_00407d44(int param_1)
{
  return (float10)*(float *)(param_1 + 0x28);
}

// --------------------------------------------------

// Function: FUN_00407d54
// Address: 00407d54
undefined1 __fastcall FUN_00407d54(int param_1)
{
  return *(undefined1 *)(param_1 + 0x3c);
}

// --------------------------------------------------

// Function: FUN_00407d64
// Address: 00407d64
void __thiscall FUN_00407d64(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x3c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00407d7a
// Address: 00407d7a
// [HELPER] s_: ""
undefined4 * __fastcall FUN_00407d7a(undefined4 *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[2] = 0xffffffff;
  param_1[3] = 0xffffffff;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  *param_1 = &BaseItem::_vftable_;
  pcVar4 = s_;
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
  pcVar5 = (char *)(param_1 + 4);
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
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00407dd4
// Address: 00407dd4
BaseItem * __thiscall FUN_00407dd4(BaseItem *param_1,byte param_2)
{
  BaseItem::~BaseItem(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00407dfe
// Address: 00407dfe
undefined4 * __thiscall
FUN_00407dfe(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11)
{
  param_1[1] = param_2;
  param_1[2] = param_3;
  param_1[0x14] = param_6;
  param_1[0x15] = param_7;
  param_1[3] = param_4;
  param_1[0x17] = param_9;
  param_1[0x18] = param_10;
  param_1[0x16] = param_8;
  param_1[0x19] = param_11;
  param_1[0x1a] = 0;
  *param_1 = &BaseItem::_vftable_;
  strncpy(param_1 + 4,param_5,0x3f);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00407e68
// Address: 00407e68
undefined4 * __thiscall FUN_00407e68(undefined4 *param_1,int param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  param_1[1] = *(undefined4 *)(param_2 + 4);
  param_1[2] = *(undefined4 *)(param_2 + 8);
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[0x14] = *(undefined4 *)(param_2 + 0x50);
  param_1[0x15] = *(undefined4 *)(param_2 + 0x54);
  param_1[0x16] = *(undefined4 *)(param_2 + 0x58);
  param_1[0x17] = *(undefined4 *)(param_2 + 0x5c);
  param_1[0x18] = *(undefined4 *)(param_2 + 0x60);
  param_1[0x19] = *(undefined4 *)(param_2 + 100);
  param_1[0x1a] = *(undefined4 *)(param_2 + 0x68);
  uVar2 = 0xffffffff;
  *param_1 = &BaseItem::_vftable_;
  pcVar4 = (char *)(param_2 + 0x10);
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
  pcVar5 = (char *)(param_1 + 4);
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
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00407ee6
// Address: 00407ee6
undefined4 * __thiscall FUN_00407ee6(undefined4 *param_1,int param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  param_1[1] = *(undefined4 *)(param_2 + 4);
  param_1[2] = *(undefined4 *)(param_2 + 8);
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[0x14] = *(undefined4 *)(param_2 + 0x50);
  param_1[0x15] = *(undefined4 *)(param_2 + 0x54);
  param_1[0x16] = *(undefined4 *)(param_2 + 0x58);
  param_1[0x17] = *(undefined4 *)(param_2 + 0x5c);
  param_1[0x18] = *(undefined4 *)(param_2 + 0x60);
  param_1[0x19] = *(undefined4 *)(param_2 + 100);
  param_1[0x1a] = *(undefined4 *)(param_2 + 0x68);
  uVar2 = 0xffffffff;
  *param_1 = &BaseItem::_vftable_;
  pcVar4 = (char *)(param_2 + 0x10);
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
  pcVar5 = (char *)(param_1 + 4);
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
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00407f66
// Address: 00407f66
void __fastcall FUN_00407f66(undefined4 *param_1)
{
  *param_1 = &BaseItem::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_00407f77
// Address: 00407f77
undefined4 FUN_00407f77(int param_1,int param_2)
{
  if (((*(int *)(param_1 + 8) == *(int *)(param_2 + 8)) &&
      (*(float *)(param_1 + 0x50) == *(float *)(param_2 + 0x50))) &&
     (*(float *)(param_1 + 0x54) == *(float *)(param_2 + 0x54))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: operator==
// Address: 00407f80
/* int __cdecl operator==(class BaseItem const &,class BaseItem const &) */

int __cdecl operator==(BaseItem *param_1,BaseItem *param_2)
{
  if (((param_1->gameIDValue == param_2->gameIDValue) && (param_1->xValue == param_2->xValue)) &&
     (param_1->yValue == param_2->yValue)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00407fb8
// Address: 00407fb8
bool FUN_00407fb8(BaseItem *param_1,BaseItem *param_2)
{
  int iVar1;
  
  iVar1 = operator==(param_1,param_2);
  return iVar1 == 0;
}

// --------------------------------------------------

// Function: operator!=
// Address: 00407fc0
/* int __cdecl operator!=(class BaseItem const &,class BaseItem const &) */

int __cdecl operator!=(BaseItem *param_1,BaseItem *param_2)
{
  int iVar1;
  
  iVar1 = operator==(param_1,param_2);
  return (uint)(iVar1 == 0);
}

// --------------------------------------------------

// Function: FUN_00407fd8
// Address: 00407fd8
bool FUN_00407fd8(int param_1,int param_2)
{
  return *(int *)(param_1 + 8) < *(int *)(param_2 + 8);
}

// --------------------------------------------------

// Function: operator<
// Address: 00407fe0
/* int __cdecl operator<(class BaseItem const &,class BaseItem const &) */

int __cdecl operator<(BaseItem *param_1,BaseItem *param_2)
{
  return (uint)(param_1->gameIDValue < param_2->gameIDValue);
}

// --------------------------------------------------

// Function: FUN_00407ff8
// Address: 00407ff8
bool FUN_00407ff8(int param_1,int param_2)
{
  return *(int *)(param_2 + 8) < *(int *)(param_1 + 8);
}

// --------------------------------------------------

// Function: operator>
// Address: 00408000
/* int __cdecl operator>(class BaseItem const &,class BaseItem const &) */

int __cdecl operator>(BaseItem *param_1,BaseItem *param_2)
{
  return (uint)(param_2->gameIDValue < param_1->gameIDValue);
}

// --------------------------------------------------

// Function: FUN_00408018
// Address: 00408018
undefined4 __fastcall FUN_00408018(int param_1)
{
  return *(undefined4 *)(param_1 + 4);
}

// --------------------------------------------------

// Function: FUN_00408024
// Address: 00408024
undefined4 __fastcall FUN_00408024(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_00408034
// Address: 00408034
undefined4 __fastcall FUN_00408034(int param_1)
{
  return *(undefined4 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_00408044
// Address: 00408044
int __fastcall FUN_00408044(int param_1)
{
  return param_1 + 0x10;
}

// --------------------------------------------------

// Function: FUN_00408054
// Address: 00408054
float10 __fastcall FUN_00408054(int param_1)
{
  return (float10)*(float *)(param_1 + 0x50);
}

// --------------------------------------------------

// Function: FUN_00408064
// Address: 00408064
float10 __fastcall FUN_00408064(int param_1)
{
  return (float10)*(float *)(param_1 + 0x54);
}

// --------------------------------------------------

// Function: FUN_00408074
// Address: 00408074
float10 __fastcall FUN_00408074(int param_1)
{
  return (float10)*(float *)(param_1 + 0x58);
}

// --------------------------------------------------

// Function: FUN_00408084
// Address: 00408084
float10 __fastcall FUN_00408084(int param_1)
{
  return (float10)*(float *)(param_1 + 0x5c);
}

// --------------------------------------------------

// Function: FUN_00408094
// Address: 00408094
float10 __fastcall FUN_00408094(int param_1)
{
  return (float10)*(float *)(param_1 + 0x60);
}

// --------------------------------------------------

// Function: FUN_004080a4
// Address: 004080a4
float10 __fastcall FUN_004080a4(int param_1)
{
  return (float10)*(float *)(param_1 + 100);
}

// --------------------------------------------------

// Function: FUN_004080b4
// Address: 004080b4
undefined4 __fastcall FUN_004080b4(int param_1)
{
  return *(undefined4 *)(param_1 + 0x68);
}

// --------------------------------------------------

// Function: FUN_004080c4
// Address: 004080c4
void __thiscall FUN_004080c4(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004080da
// Address: 004080da
void __thiscall FUN_004080da(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004080ea
// Address: 004080ea
void __thiscall FUN_004080ea(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004080fa
// Address: 004080fa
void __thiscall FUN_004080fa(int param_1,undefined4 param_2)
{
  strncpy(param_1 + 0x10,param_2,0x3f);
  return;
}

// --------------------------------------------------

// Function: FUN_00408116
// Address: 00408116
void __thiscall FUN_00408116(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x50) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040812a
// Address: 0040812a
void __thiscall FUN_0040812a(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x54) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040813a
// Address: 0040813a
void __thiscall FUN_0040813a(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x58) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040814a
// Address: 0040814a
void __thiscall FUN_0040814a(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x5c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040815a
// Address: 0040815a
void __thiscall FUN_0040815a(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x60) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040816a
// Address: 0040816a
void __thiscall FUN_0040816a(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 100) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040817a
// Address: 0040817a
void __thiscall FUN_0040817a(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x68) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040818a
// Address: 0040818a
BaseItem * __fastcall FUN_0040818a(BaseItem *param_1)
{
  BaseItem::BaseItem(param_1);
  param_1[1]._padding_ = 0;
  param_1[1].typeIDValue = 0;
  param_1[1].uniqueIDValue = 0;
  param_1[1].nameValue[0] = '\0';
  param_1[1].nameValue[1] = '\0';
  param_1[1].nameValue[2] = '\0';
  param_1[1].nameValue[3] = '\0';
  param_1[1].nameValue[4] = '\0';
  param_1[1].nameValue[5] = '\0';
  param_1[1].nameValue[6] = '\0';
  param_1[1].nameValue[7] = '\0';
  param_1[1].nameValue[8] = '\0';
  param_1[1].nameValue[9] = '\0';
  param_1[1].nameValue[10] = '\0';
  param_1[1].nameValue[0xb] = '\0';
  param_1[1].nameValue[0xc] = '\0';
  param_1[1].nameValue[0xd] = '\0';
  param_1[1].nameValue[0xe] = '\0';
  param_1[1].nameValue[0xf] = '\0';
  param_1[1].nameValue[0x20] = '\0';
  param_1[1].nameValue[0x21] = '\0';
  param_1[1].nameValue[0x22] = '\0';
  param_1[1].nameValue[0x23] = '\0';
  param_1[1].nameValue[0x24] = '\0';
  param_1[1].nameValue[0x25] = '\0';
  param_1[1].nameValue[0x26] = '\0';
  param_1[1].nameValue[0x27] = '\0';
  param_1[1].nameValue[0x2c] = '\0';
  param_1[1].nameValue[0x2d] = '\0';
  param_1[1].nameValue[0x2e] = '\0';
  param_1[1].nameValue[0x2f] = '\0';
  param_1[1].nameValue[0x30] = '\0';
  param_1[1].gameIDValue = -1;
  param_1[1].nameValue[0x10] = -1;
  param_1[1].nameValue[0x11] = -1;
  param_1[1].nameValue[0x12] = -1;
  param_1[1].nameValue[0x13] = -1;
  param_1[1].nameValue[0x14] = -1;
  param_1[1].nameValue[0x15] = -1;
  param_1[1].nameValue[0x16] = -1;
  param_1[1].nameValue[0x17] = -1;
  param_1[1].nameValue[0x28] = -1;
  param_1[1].nameValue[0x29] = -1;
  param_1[1].nameValue[0x2a] = -1;
  param_1[1].nameValue[0x2b] = -1;
  param_1->_padding_ = (int)&BuildItem::_vftable_;
  param_1[1].nameValue[0x18] = -1;
  param_1[1].nameValue[0x19] = -1;
  param_1[1].nameValue[0x1a] = -1;
  param_1[1].nameValue[0x1b] = -1;
  param_1[1].nameValue[0x1c] = -1;
  param_1[1].nameValue[0x1d] = -1;
  param_1[1].nameValue[0x1e] = -1;
  param_1[1].nameValue[0x1f] = -1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004081fe
// Address: 004081fe
BuildItem * __thiscall FUN_004081fe(BuildItem *param_1,byte param_2)
{
  BuildItem::~BuildItem(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040821e
// Address: 0040821e
BaseItem * __thiscall
FUN_0040821e(BaseItem *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            undefined4 param_7,char *param_8,float param_9,float param_10,float param_11,
            undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15)
{
  BaseItem::BaseItem(param_1,param_3,-1,param_4,param_8,-1.0,-1.0,-1.0,param_9,param_10,param_11);
  param_1[1].gameIDValue = param_2;
  param_1[1].uniqueIDValue = param_5;
  *(undefined4 *)param_1[1].nameValue = param_6;
  param_1[1]._padding_ = 0;
  param_1[1].typeIDValue = 0;
  param_1[1].nameValue[4] = '\0';
  param_1[1].nameValue[5] = '\0';
  param_1[1].nameValue[6] = '\0';
  param_1[1].nameValue[7] = '\0';
  param_1[1].nameValue[8] = '\0';
  param_1[1].nameValue[9] = '\0';
  param_1[1].nameValue[10] = '\0';
  param_1[1].nameValue[0xb] = '\0';
  param_1[1].nameValue[0xc] = '\0';
  param_1[1].nameValue[0xd] = '\0';
  param_1[1].nameValue[0xe] = '\0';
  param_1[1].nameValue[0xf] = '\0';
  param_1[1].nameValue[0x24] = '\0';
  param_1[1].nameValue[0x25] = '\0';
  param_1[1].nameValue[0x26] = '\0';
  param_1[1].nameValue[0x27] = '\0';
  param_1[1].nameValue[0x2c] = '\0';
  param_1[1].nameValue[0x2d] = '\0';
  param_1[1].nameValue[0x2e] = '\0';
  param_1[1].nameValue[0x2f] = '\0';
  param_1[1].nameValue[0x30] = '\0';
  *(undefined4 *)(param_1[1].nameValue + 0x10) = param_7;
  *(undefined4 *)(param_1[1].nameValue + 0x14) = param_12;
  *(undefined4 *)(param_1[1].nameValue + 0x18) = param_13;
  *(undefined4 *)(param_1[1].nameValue + 0x20) = param_15;
  param_1[1].nameValue[0x28] = -1;
  param_1[1].nameValue[0x29] = -1;
  param_1[1].nameValue[0x2a] = -1;
  param_1[1].nameValue[0x2b] = -1;
  param_1->_padding_ = (int)&BuildItem::_vftable_;
  *(undefined4 *)(param_1[1].nameValue + 0x1c) = param_14;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004082e2
// Address: 004082e2
BaseItem * __thiscall FUN_004082e2(BaseItem *param_1,BaseItem *param_2)
{
  BaseItem::BaseItem(param_1,param_2);
  param_1[1]._padding_ = 0;
  param_1[1].typeIDValue = 0;
  param_1[1].gameIDValue = param_2[1].gameIDValue;
  param_1[1].uniqueIDValue = param_2[1].uniqueIDValue;
  *(undefined4 *)param_1[1].nameValue = *(undefined4 *)param_2[1].nameValue;
  *(undefined4 *)(param_1[1].nameValue + 4) = *(undefined4 *)(param_2[1].nameValue + 4);
  *(undefined4 *)(param_1[1].nameValue + 8) = *(undefined4 *)(param_2[1].nameValue + 4);
  *(undefined4 *)(param_1[1].nameValue + 0xc) = *(undefined4 *)(param_2[1].nameValue + 0xc);
  *(undefined4 *)(param_1[1].nameValue + 0x10) = *(undefined4 *)(param_2[1].nameValue + 0x10);
  *(undefined4 *)(param_1[1].nameValue + 0x14) = *(undefined4 *)(param_2[1].nameValue + 0x14);
  *(undefined4 *)(param_1[1].nameValue + 0x20) = *(undefined4 *)(param_2[1].nameValue + 0x20);
  param_1[1].nameValue[0x24] = '\0';
  param_1[1].nameValue[0x25] = '\0';
  param_1[1].nameValue[0x26] = '\0';
  param_1[1].nameValue[0x27] = '\0';
  param_1[1].nameValue[0x28] = -1;
  param_1[1].nameValue[0x29] = -1;
  param_1[1].nameValue[0x2a] = -1;
  param_1[1].nameValue[0x2b] = -1;
  param_1[1].nameValue[0x2c] = '\0';
  param_1[1].nameValue[0x2d] = '\0';
  param_1[1].nameValue[0x2e] = '\0';
  param_1[1].nameValue[0x2f] = '\0';
  param_1[1].nameValue[0x30] = '\0';
  param_1->_padding_ = (int)&BuildItem::_vftable_;
  *(undefined4 *)(param_1[1].nameValue + 0x18) = *(undefined4 *)(param_2[1].nameValue + 0x18);
  *(undefined4 *)(param_1[1].nameValue + 0x1c) = *(undefined4 *)(param_2[1].nameValue + 0x1c);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004083a1
// Address: 004083a1
BaseItem * __thiscall FUN_004083a1(BaseItem *param_1,BaseItem *param_2)
{
  BaseItem::BaseItem(param_1,param_2);
  param_1[1]._padding_ = 0;
  param_1[1].typeIDValue = 0;
  param_1[1].gameIDValue = param_2[1].gameIDValue;
  param_1[1].uniqueIDValue = param_2[1].uniqueIDValue;
  *(undefined4 *)param_1[1].nameValue = *(undefined4 *)param_2[1].nameValue;
  *(undefined4 *)(param_1[1].nameValue + 4) = *(undefined4 *)(param_2[1].nameValue + 4);
  *(undefined4 *)(param_1[1].nameValue + 8) = *(undefined4 *)(param_2[1].nameValue + 4);
  *(undefined4 *)(param_1[1].nameValue + 0xc) = *(undefined4 *)(param_2[1].nameValue + 0xc);
  *(undefined4 *)(param_1[1].nameValue + 0x10) = *(undefined4 *)(param_2[1].nameValue + 0x10);
  *(undefined4 *)(param_1[1].nameValue + 0x14) = *(undefined4 *)(param_2[1].nameValue + 0x14);
  *(undefined4 *)(param_1[1].nameValue + 0x20) = *(undefined4 *)(param_2[1].nameValue + 0x20);
  param_1[1].nameValue[0x24] = '\0';
  param_1[1].nameValue[0x25] = '\0';
  param_1[1].nameValue[0x26] = '\0';
  param_1[1].nameValue[0x27] = '\0';
  param_1[1].nameValue[0x28] = -1;
  param_1[1].nameValue[0x29] = -1;
  param_1[1].nameValue[0x2a] = -1;
  param_1[1].nameValue[0x2b] = -1;
  param_1[1].nameValue[0x2c] = '\0';
  param_1[1].nameValue[0x2d] = '\0';
  param_1[1].nameValue[0x2e] = '\0';
  param_1[1].nameValue[0x2f] = '\0';
  param_1[1].nameValue[0x30] = '\0';
  param_1->_padding_ = (int)&BuildItem::_vftable_;
  *(undefined4 *)(param_1[1].nameValue + 0x18) = *(undefined4 *)(param_2[1].nameValue + 0x18);
  *(undefined4 *)(param_1[1].nameValue + 0x1c) = *(undefined4 *)(param_2[1].nameValue + 0x1c);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00408461
// Address: 00408461
void __fastcall FUN_00408461(BaseItem *param_1)
{
  param_1->_padding_ = (int)&BuildItem::_vftable_;
  BaseItem::~BaseItem(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0040847b
// Address: 0040847b
bool FUN_0040847b(int param_1,int param_2)
{
  return *(int *)(param_1 + 4) == *(int *)(param_2 + 4);
}

// --------------------------------------------------

// Function: operator==
// Address: 00408480
/* int __cdecl operator==(class BuildItem const &,class BuildItem const &) */

int __cdecl operator==(BuildItem *param_1,BuildItem *param_2)
{
  return (uint)(param_1->_padding_ == param_2->_padding_);
}

// --------------------------------------------------

// Function: FUN_00408498
// Address: 00408498
bool FUN_00408498(int param_1,int param_2)
{
  return *(int *)(param_1 + 4) != *(int *)(param_2 + 4);
}

// --------------------------------------------------

// Function: operator!=
// Address: 004084a0
/* int __cdecl operator!=(class BuildItem const &,class BuildItem const &) */

int __cdecl operator!=(BuildItem *param_1,BuildItem *param_2)
{
  return (uint)(param_1->_padding_ != param_2->_padding_);
}

// --------------------------------------------------

// Function: FUN_004084b8
// Address: 004084b8
bool FUN_004084b8(int param_1,int param_2)
{
  return *(int *)(param_1 + 4) < *(int *)(param_2 + 4);
}

// --------------------------------------------------

// Function: operator<
// Address: 004084c0
/* int __cdecl operator<(class BuildItem const &,class BuildItem const &) */

int __cdecl operator<(BuildItem *param_1,BuildItem *param_2)
{
  return (uint)(param_1->_padding_ < param_2->_padding_);
}

// --------------------------------------------------

// Function: FUN_004084d8
// Address: 004084d8
bool FUN_004084d8(int param_1,int param_2)
{
  return *(int *)(param_2 + 4) < *(int *)(param_1 + 4);
}

// --------------------------------------------------

// Function: operator>
// Address: 004084e0
/* int __cdecl operator>(class BuildItem const &,class BuildItem const &) */

int __cdecl operator>(BuildItem *param_1,BuildItem *param_2)
{
  return (uint)(param_2->_padding_ < param_1->_padding_);
}

// --------------------------------------------------

// Function: FUN_004084f8
// Address: 004084f8
undefined4 __fastcall FUN_004084f8(int param_1)
{
  return *(undefined4 *)(param_1 + 0x74);
}

// --------------------------------------------------

// Function: FUN_00408504
// Address: 00408504
undefined4 __fastcall FUN_00408504(int param_1)
{
  return *(undefined4 *)(param_1 + 0x78);
}

// --------------------------------------------------

// Function: FUN_00408514
// Address: 00408514
undefined4 __fastcall FUN_00408514(int param_1)
{
  return *(undefined4 *)(param_1 + 0x7c);
}

// --------------------------------------------------

// Function: FUN_00408524
// Address: 00408524
undefined4 __fastcall FUN_00408524(int param_1)
{
  return *(undefined4 *)(param_1 + 0x80);
}

// --------------------------------------------------

// Function: FUN_00408537
// Address: 00408537
undefined4 __fastcall FUN_00408537(int param_1)
{
  return *(undefined4 *)(param_1 + 0x84);
}

// --------------------------------------------------

// Function: FUN_00408547
// Address: 00408547
undefined4 __fastcall FUN_00408547(int param_1)
{
  return *(undefined4 *)(param_1 + 0x88);
}

// --------------------------------------------------

// Function: FUN_00408557
// Address: 00408557
undefined4 __fastcall FUN_00408557(int param_1)
{
  return *(undefined4 *)(param_1 + 0x8c);
}

// --------------------------------------------------

// Function: FUN_00408567
// Address: 00408567
undefined4 __fastcall FUN_00408567(int param_1)
{
  return *(undefined4 *)(param_1 + 0x90);
}

// --------------------------------------------------

// Function: FUN_00408577
// Address: 00408577
undefined4 __thiscall FUN_00408577(int param_1,int param_2)
{
  if ((0 < param_2) && (param_2 < 3)) {
    return *(undefined4 *)(param_1 + 0x90 + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0040859e
// Address: 0040859e
undefined4 __fastcall FUN_0040859e(int param_1)
{
  return *(undefined4 *)(param_1 + 0x9c);
}

// --------------------------------------------------

// Function: FUN_004085a7
// Address: 004085a7
void __thiscall FUN_004085a7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x80) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004085bd
// Address: 004085bd
void __thiscall FUN_004085bd(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x84) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004085cd
// Address: 004085cd
void __thiscall FUN_004085cd(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x88) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004085dd
// Address: 004085dd
void __fastcall FUN_004085dd(int param_1)
{
  *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004085e7
// Address: 004085e7
void __fastcall FUN_004085e7(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x88) + -1;
  *(int *)(param_1 + 0x88) = iVar1;
  if (iVar1 < 0) {
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040860a
// Address: 0040860a
undefined4 __fastcall FUN_0040860a(int param_1)
{
  return *(undefined4 *)(param_1 + 0xa0);
}

// --------------------------------------------------

// Function: FUN_00408617
// Address: 00408617
void __fastcall FUN_00408617(int param_1)
{
  *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00408627
// Address: 00408627
void __thiscall FUN_00408627(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xa0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040863d
// Address: 0040863d
undefined4 __fastcall FUN_0040863d(int param_1)
{
  return *(undefined4 *)(param_1 + 0xa4);
}

// --------------------------------------------------

// Function: FUN_00408647
// Address: 00408647
void __thiscall FUN_00408647(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xa4) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040865d
// Address: 0040865d
undefined4 __fastcall FUN_0040865d(int param_1)
{
  return *(undefined4 *)(param_1 + 0xa8);
}

// --------------------------------------------------

// Function: FUN_00408667
// Address: 00408667
void __fastcall FUN_00408667(int param_1)
{
  *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00408677
// Address: 00408677
void __thiscall FUN_00408677(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xa8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040868d
// Address: 0040868d
undefined1 __fastcall FUN_0040868d(int param_1)
{
  return *(undefined1 *)(param_1 + 0xac);
}

// --------------------------------------------------

// Function: FUN_00408697
// Address: 00408697
void __thiscall FUN_00408697(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xac) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004086ad
// Address: 004086ad
// [HELPER] s_: ""
// [HELPER] s_Build_AI: "Build AI"
// [HELPER] s_None: "None"
AIModule * __thiscall FUN_004086ad(AIModule *param_1,void *param_2,int param_3)
{
  AIModule *this;
  char cVar1;
  AIModule *pAVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c456;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  AIModule::AIModule(param_1,s_Build_AI,0x3e9,param_3,param_2);
  this = param_1 + 1;
  uStack_4 = 0;
  BuildItem::BuildItem((BuildItem *)this);
  param_1[1].historyLogFilename[0xc] = '\0';
  param_1[1].historyLogFilename[0xd] = '\0';
  param_1[1].historyLogFilename[0xe] = '\0';
  param_1[1].historyLogFilename[0xf] = '\0';
  param_1[6].idValue.id = 0;
  param_1[6].idValue.name[0] = '\0';
  param_1[6].idValue.name[1] = '\0';
  param_1[6].idValue.name[2] = '\0';
  param_1[6].idValue.name[3] = '\0';
  pAVar2 = param_1 + 6;
  (pAVar2->idValue).name[4] = '\0';
  (pAVar2->idValue).name[5] = '\0';
  (pAVar2->idValue).name[6] = '\0';
  (pAVar2->idValue).name[7] = '\0';
  pAVar2 = param_1 + 6;
  (pAVar2->idValue).name[8] = '\0';
  (pAVar2->idValue).name[9] = '\0';
  (pAVar2->idValue).name[10] = '\0';
  (pAVar2->idValue).name[0xb] = '\0';
  pAVar2 = param_1 + 6;
  (pAVar2->idValue).name[0xc] = '\0';
  (pAVar2->idValue).name[0xd] = '\0';
  (pAVar2->idValue).name[0xe] = '\0';
  (pAVar2->idValue).name[0xf] = '\0';
  uVar3 = 0xffffffff;
  param_1->_padding_ = (int)&BuildAIModule::_vftable_;
  *(AIModule **)(param_1[1].playerNameValue + 0x1c) = this;
  *(AIModule **)(param_1[1].playerNameValue + 0x20) = this;
  pcVar5 = s_;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = param_1[1].historyLogFilename + 0x10;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar5 = &s_None;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = param_1[2].historyLogFilename + 0x21;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar5 = &s_None;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = param_1[3].historyLogFilename + 0x32;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar5 = &s_None;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = (char *)((int)&param_1[4].intelligenceLevelValue + 3);
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004087e9
// Address: 004087e9
undefined4 FUN_004087e9(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004087f5
// Address: 004087f5
undefined4 FUN_004087f5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00408805
// Address: 00408805
undefined4 FUN_00408805(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00408815
// Address: 00408815
BuildAIModule * __thiscall FUN_00408815(BuildAIModule *param_1,byte param_2)
{
  BuildAIModule::~BuildAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040883e
// Address: 0040883e
// [HELPER] s_Build_AI: "Build AI"
// [HELPER] s_None: "None"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

AIModule * __thiscall FUN_0040883e(AIModule *param_1,int param_2,int param_3)
{
  AIModule *this;
  char cVar1;
  BuildItem *pBVar2;
  int iVar3;
  AIModule *pAVar4;
  BuildItem *this_00;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  int iStack_178;
  int iStack_174;
  int iStack_170;
  int iStack_16c;
  int iStack_168;
  int iStack_164;
  int iStack_160;
  float fStack_15c;
  int iStack_158;
  float fStack_154;
  float fStack_150;
  int iStack_14c;
  float fStack_148;
  int iStack_144;
  float fStack_140;
  int iStack_13c;
  int iStack_138;
  float fStack_134;
  int iStack_130;
  int iStack_12c;
  undefined1 auStack_128 [4];
  int iStack_124;
  int iStack_120;
  int iStack_11c;
  AIModule *pAStack_118;
  BuildItem *pBStack_114;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c49b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pAStack_118 = param_1;
  AIModule::AIModule(param_1,s_Build_AI,0x3e9,param_2,(void *)0x0);
  this = param_1 + 1;
  uStack_4 = 0;
  BuildItem::BuildItem((BuildItem *)this);
  pcVar7 = param_1[1].historyLogFilename + 0xc;
  param_1[6].idValue.id = 0;
  pcVar7[0] = '\0';
  pcVar7[1] = '\0';
  pcVar7[2] = '\0';
  pcVar7[3] = '\0';
  param_1[6].idValue.name[0] = '\0';
  param_1[6].idValue.name[1] = '\0';
  param_1[6].idValue.name[2] = '\0';
  param_1[6].idValue.name[3] = '\0';
  pAVar4 = param_1 + 6;
  (pAVar4->idValue).name[4] = '\0';
  (pAVar4->idValue).name[5] = '\0';
  (pAVar4->idValue).name[6] = '\0';
  (pAVar4->idValue).name[7] = '\0';
  pAVar4 = param_1 + 6;
  (pAVar4->idValue).name[8] = '\0';
  (pAVar4->idValue).name[9] = '\0';
  (pAVar4->idValue).name[10] = '\0';
  (pAVar4->idValue).name[0xb] = '\0';
  pAVar4 = param_1 + 6;
  (pAVar4->idValue).name[0xc] = '\0';
  (pAVar4->idValue).name[0xd] = '\0';
  (pAVar4->idValue).name[0xe] = '\0';
  (pAVar4->idValue).name[0xf] = '\0';
  uStack_4 = CONCAT31(uStack_4._1_3_,2);
  param_1->_padding_ = (int)&BuildAIModule::_vftable_;
  *(AIModule **)(param_1[1].playerNameValue + 0x1c) = this;
  *(AIModule **)(param_1[1].playerNameValue + 0x20) = this;
  rge_read(param_3,pcVar7,4);
  rge_read(param_3,&iStack_178,4);
  rge_read(param_3,param_1[1].historyLogFilename + 0x10,iStack_178);
  param_1[1].historyLogFilename[iStack_178 + 0x10] = '\0';
  rge_read(param_3,&iStack_178,4);
  rge_read(param_3,param_1[2].historyLogFilename + 0x21,iStack_178);
  param_1[2].historyLogFilename[iStack_178 + 0x21] = '\0';
  rge_read(param_3,&iStack_178,4);
  rge_read(param_3,param_1[3].historyLogFilename + 0x32,iStack_178);
  param_1[3].historyLogFilename[iStack_178 + 0x32] = '\0';
  if (save_game_version < _DAT_0056e784) {
    uVar5 = 0xffffffff;
    pcVar7 = &s_None;
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar7 = pcVar8 + -uVar5;
    pcVar8 = (char *)((int)&param_1[4].intelligenceLevelValue + 3);
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  else {
    rge_read(param_3,&iStack_178,4);
    rge_read(param_3,(void *)((int)&param_1[4].intelligenceLevelValue + 3),iStack_178);
    param_1[4].historyLogFilename[iStack_178 + 0x43] = '\0';
  }
  iVar9 = 0;
  rge_read(param_3,&param_1[6].idValue.id,4);
  if (0 < *(int *)(param_1[1].historyLogFilename + 0xc)) {
    do {
      rge_read(param_3,&iStack_178,4);
      rge_read(param_3,acStack_110,iStack_178);
      acStack_110[iStack_178] = '\0';
      rge_read(param_3,&iStack_12c,4);
      rge_read(param_3,&iStack_158,4);
      rge_read(param_3,&iStack_14c,4);
      rge_read(param_3,&fStack_150,4);
      rge_read(param_3,&fStack_148,4);
      rge_read(param_3,&fStack_140,4);
      rge_read(param_3,&fStack_154,4);
      rge_read(param_3,&fStack_134,4);
      rge_read(param_3,&fStack_15c,4);
      rge_read(param_3,&iStack_160,4);
      rge_read(param_3,&iStack_144,4);
      rge_read(param_3,&iStack_16c,4);
      rge_read(param_3,&iStack_170,4);
      rge_read(param_3,&iStack_168,4);
      rge_read(param_3,&iStack_11c,4);
      rge_read(param_3,&iStack_124,4);
      rge_read(param_3,&iStack_164,4);
      rge_read(param_3,&iStack_13c,4);
      rge_read(param_3,&iStack_120,4);
      rge_read(param_3,&iStack_138,4);
      iStack_174 = -1;
      if (_DAT_0056e788 <= save_game_version) {
        rge_read(param_3,&iStack_174,4);
      }
      rge_read(param_3,&iStack_130,4);
      rge_read(param_3,auStack_128,1);
      pBStack_114 = (BuildItem *)operator_new(0xb0);
      uStack_4._0_1_ = 3;
      if (pBStack_114 == (BuildItem *)0x0) {
        this_00 = (BuildItem *)0x0;
      }
      else {
        this_00 = (BuildItem *)
                  BuildItem::BuildItem
                            (pBStack_114,iStack_144,iStack_12c,iStack_14c,1,0,iStack_11c,acStack_110
                             ,fStack_154,fStack_134,fStack_15c,iStack_124,iStack_164,iStack_13c,
                             iStack_120);
      }
      uStack_4 = CONCAT31(uStack_4._1_3_,2);
      BuildItem::setBuilt(this_00,iStack_170);
      BuildItem::setInProgress(this_00,iStack_16c);
      BuildItem::setBuildAttempts(this_00,iStack_168);
      BaseItem::setSkip((BaseItem *)this_00,iStack_160);
      BaseItem::setGameID((BaseItem *)this_00,iStack_158);
      BaseItem::setX((BaseItem *)this_00,fStack_150);
      BaseItem::setY((BaseItem *)this_00,fStack_148);
      BaseItem::setZ((BaseItem *)this_00,fStack_140);
      BuildItem::setNumberBuilds(this_00,iStack_138);
      BuildItem::setBuildCap(this_00,iStack_174);
      BuildItem::setSkipCycles(this_00,iStack_130);
      BuildItem::setPermanentSkip(this_00,auStack_128[0]);
      iVar9 = iVar9 + 1;
      this_00->next = (BuildItem *)(param_1 + 1);
      pBVar2 = *(BuildItem **)(param_1[1].playerNameValue + 0x20);
      this_00->prev = pBVar2;
      pBVar2->next = this_00;
      iVar3 = *(int *)(param_1[1].historyLogFilename + 0xc);
      *(BuildItem **)(param_1[1].playerNameValue + 0x20) = this_00;
    } while (iVar9 < iVar3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00408d18
// Address: 00408d18
void __fastcall FUN_00408d18(undefined4 *param_1)
{
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00408d4f
// Address: 00408d4f
void __fastcall FUN_00408d4f(BuildAIModule *param_1)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  pcStack_8 = FUN_0055c4d4;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&BuildAIModule::_vftable_;
  iStack_4 = 2;
  if (0 < param_1->buildListLengthValue) {
    BuildAIModule::removeOldList(param_1);
  }
  piVar1 = (param_1->typesToIgnore).value;
  iStack_4._0_1_ = 1;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->typesToIgnore).value = (int *)0x0;
  }
  (param_1->typesToIgnore).numberValue = 0;
  (param_1->typesToIgnore).desiredNumberValue = 0;
  (param_1->typesToIgnore).maximumSizeValue = 0;
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  BuildItem::~BuildItem(&param_1->buildList);
  iStack_4 = 0xffffffff;
  AIModule::~AIModule((AIModule *)param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00408dec
// Address: 00408dec
undefined4 __thiscall FUN_00408dec(int param_1,int param_2)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  BuildItem *this;
  char *pcVar5;
  int iStack_118;
  float fStack_114;
  int iStack_110;
  uchar uStack_109;
  BuildItem *pBStack_108;
  char acStack_104 [260];
  
  pBStack_108 = (BuildItem *)param_1;
  rge_write(param_2,(void *)(param_1 + 0x1a0),4);
  uVar3 = 0xffffffff;
  pcVar2 = (char *)(param_1 + 0x1a4);
  do {
    pcVar5 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar5 + -uVar3;
  pcVar5 = acStack_104;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar5 = pcVar5 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar2 = acStack_104;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_118 = ~uVar3 - 1;
  rge_write(param_2,&iStack_118,4);
  uVar3 = 0xffffffff;
  pcVar2 = acStack_104;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  rge_write(param_2,acStack_104,~uVar3 - 1);
  uVar3 = 0xffffffff;
  pcVar2 = (char *)(param_1 + 0x2a5);
  do {
    pcVar5 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar5 + -uVar3;
  pcVar5 = acStack_104;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar5 = pcVar5 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar2 = acStack_104;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_118 = ~uVar3 - 1;
  rge_write(param_2,&iStack_118,4);
  uVar3 = 0xffffffff;
  pcVar2 = acStack_104;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  rge_write(param_2,acStack_104,~uVar3 - 1);
  uVar3 = 0xffffffff;
  pcVar2 = (char *)(param_1 + 0x3a6);
  do {
    pcVar5 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar5 + -uVar3;
  pcVar5 = acStack_104;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar5 = pcVar5 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar2 = acStack_104;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_118 = ~uVar3 - 1;
  rge_write(param_2,&iStack_118,4);
  uVar3 = 0xffffffff;
  pcVar2 = acStack_104;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  rge_write(param_2,acStack_104,~uVar3 - 1);
  uVar3 = 0xffffffff;
  pcVar2 = (char *)(param_1 + 0x4a7);
  do {
    pcVar5 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar5 + -uVar3;
  pcVar5 = acStack_104;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar5 = pcVar5 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar2 = acStack_104;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_118 = ~uVar3 - 1;
  rge_write(param_2,&iStack_118,4);
  uVar3 = 0xffffffff;
  pcVar2 = acStack_104;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  rge_write(param_2,acStack_104,~uVar3 - 1);
  rge_write(param_2,(void *)(param_1 + 0x5a8),4);
  this = *(BuildItem **)(param_1 + 0x15c);
  pBStack_108 = (BuildItem *)((int)pBStack_108 + 0xf0);
  if (this != pBStack_108) {
    do {
      if (this == (BuildItem *)0x0) {
        return 1;
      }
      pcVar2 = BaseItem::name((BaseItem *)this);
      uVar3 = 0xffffffff;
      do {
        pcVar5 = pcVar2;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar5 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar5;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar2 = pcVar5 + -uVar3;
      pcVar5 = acStack_104;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar5 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar5 = pcVar5 + 1;
      }
      uVar3 = 0xffffffff;
      pcVar2 = acStack_104;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      iStack_118 = ~uVar3 - 1;
      rge_write(param_2,&iStack_118,4);
      uVar3 = 0xffffffff;
      pcVar2 = acStack_104;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      rge_write(param_2,acStack_104,~uVar3 - 1);
      iStack_118 = BaseItem::typeID((BaseItem *)this);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BaseItem::gameID((BaseItem *)this);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BaseItem::uniqueID((BaseItem *)this);
      rge_write(param_2,&iStack_118,4);
      fStack_114 = BaseItem::x((BaseItem *)this);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::y((BaseItem *)this);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::z((BaseItem *)this);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::xSize((BaseItem *)this);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::ySize((BaseItem *)this);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::zSize((BaseItem *)this);
      rge_write(param_2,&fStack_114,4);
      iStack_110 = BaseItem::skip((BaseItem *)this);
      rge_write(param_2,&iStack_110,4);
      iStack_118 = BuildItem::buildCategory(this);
      rge_write(param_2,&iStack_118,4);
      iStack_110 = BuildItem::inProgress(this);
      rge_write(param_2,&iStack_110,4);
      iStack_110 = BuildItem::built(this);
      rge_write(param_2,&iStack_110,4);
      iStack_118 = BuildItem::buildAttempts(this);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BuildItem::buildFrom(this);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BuildItem::terrainSet(this);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BuildItem::terrainAdjacency(this,1);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BuildItem::terrainAdjacency(this,2);
      rge_write(param_2,&iStack_118,4);
      iStack_110 = BuildItem::placeOnElevation(this);
      rge_write(param_2,&iStack_110,4);
      iStack_118 = BuildItem::numberBuilds(this);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BuildItem::buildCap(this);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BuildItem::skipCycles(this);
      rge_write(param_2,&iStack_118,4);
      uStack_109 = BuildItem::permanentSkip(this);
      rge_write(param_2,&uStack_109,1);
      this = this->next;
    } while (this != pBStack_108);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004092e2
// Address: 004092e2
// [HELPER] s_BLT_Type___4d___20s_gID___4d_Cat: "BLT Type=%-4d %-20s gID=%-4d Cat=%d uID=%-3d inProg=%d bldAtt=%-2d skip=%d #b..."
// [HELPER] s_Build_list___s__: "Build list '%s':"
// [HELPER] s_____Type___4d___20s_gID___4d_Cat: "    Type=%-4d %-20s gID=%-4d Cat=%d uID=%-3d inProg=%d bldAtt=%-2d skip=%d #b..."
void __fastcall FUN_004092e2(AIModule *param_1)
{
  AIModule *this;
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  AIModule *extraout_ECX;
  AIModule *extraout_ECX_00;
  AIModule *this_00;
  char *pcVar5;
  
  AIModule::logCommonHistory
            (param_1,(char *)param_1,s_Build_list___s__,param_1[1].historyLogFilename + 0x10);
  for (this = *(AIModule **)(param_1[1].playerNameValue + 0x1c);
      (this != param_1 + 1 && (this != (AIModule *)0x0));
      this = *(AIModule **)((int)this->playerNameValue + 0x1c)) {
    iVar1 = BuildItem::built((BuildItem *)this);
    if (iVar1 == 1) {
      BuildItem::skipCycles((BuildItem *)this);
      BuildItem::permanentSkip((BuildItem *)this);
      BuildItem::buildFrom((BuildItem *)this);
      BuildItem::buildCap((BuildItem *)this);
      BuildItem::numberBuilds((BuildItem *)this);
      BaseItem::skip((BaseItem *)this);
      BuildItem::buildAttempts((BuildItem *)this);
      BuildItem::inProgress((BuildItem *)this);
      BaseItem::uniqueID((BaseItem *)this);
      iVar1 = BuildItem::buildCategory((BuildItem *)this);
      iVar2 = BaseItem::gameID((BaseItem *)this);
      pcVar3 = BaseItem::name((BaseItem *)this);
      iVar4 = BaseItem::typeID((BaseItem *)this);
      pcVar5 = s_BLT_Type___4d___20s_gID___4d_Cat;
      this_00 = extraout_ECX;
    }
    else {
      BuildItem::skipCycles((BuildItem *)this);
      BuildItem::permanentSkip((BuildItem *)this);
      BuildItem::buildFrom((BuildItem *)this);
      BuildItem::buildCap((BuildItem *)this);
      BuildItem::numberBuilds((BuildItem *)this);
      BaseItem::skip((BaseItem *)this);
      BuildItem::buildAttempts((BuildItem *)this);
      BuildItem::inProgress((BuildItem *)this);
      BaseItem::uniqueID((BaseItem *)this);
      iVar1 = BuildItem::buildCategory((BuildItem *)this);
      iVar2 = BaseItem::gameID((BaseItem *)this);
      pcVar3 = BaseItem::name((BaseItem *)this);
      iVar4 = BaseItem::typeID((BaseItem *)this);
      pcVar5 = s_____Type___4d___20s_gID___4d_Cat;
      this_00 = extraout_ECX_00;
    }
    AIModule::logCommonHistory(this_00,(char *)param_1,pcVar5,iVar4,pcVar3,iVar2,iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040942e
// Address: 0040942e
// [HELPER] s_NONE: "NONE"
// [HELPER] s_NULL: "NULL"
// [HELPER] s_There_is_no_build_list_to_load_: "There is no build list to load."
// [HELPER] s_Trying_to_load_build_list_in_fil: "Trying to load build list in file '%s'."
// [HELPER] s___File_open_successful__nuking_a: "  File open successful, nuking any old items."
// [HELPER] s___I_cannot_do_it_cap_n_: "  I cannot do it cap'n!"
// [HELPER] s___c__d___s___d___d__d_: "%*c%*d %*s %*d %*d %d "
// [HELPER] s___c_c: " %c%c"
// [HELPER] s__c_d__s__d__d_: "%c%d %s %d %d "
// [HELPER] s__s: "%s"
// [HELPER] s__tmp: ".tmp"
// [HELPER] s_r: "r"
undefined4 __thiscall FUN_0040942e(BuildAIModule *param_1,undefined4 param_2,int param_3)
{
  char cVar1;
  byte bVar2;
  BuildItem *pBVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  AIModule *extraout_ECX;
  undefined3 uVar11;
  uint uVar9;
  AIModule *this;
  AIModule *this_00;
  uint uVar10;
  byte *pbVar12;
  BuildItem *this_01;
  char *pcVar13;
  undefined4 *unaff_FS_OFFSET;
  bool bVar14;
  char cStack_173;
  undefined1 uStack_172;
  char cStack_171;
  float fStack_170;
  char *pcStack_16c;
  float fStack_168;
  int iStack_164;
  int iStack_160;
  int iStack_15c;
  int iStack_158;
  int iStack_154;
  BuildItem *pBStack_150;
  char acStack_14c [64];
  undefined1 auStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c4ee;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pcVar4 = param_1->buildListNameValue;
  pcStack_16c = pcVar4;
  strncpy(pcVar4,param_2,0x3f);
  pcVar13 = pcStack_16c;
  pbVar12 = &s_NONE;
  this = extraout_ECX;
  do {
    bVar2 = *pcVar4;
    uVar11 = (undefined3)((uint)this >> 8);
    this = (AIModule *)CONCAT31(uVar11,bVar2);
    bVar14 = bVar2 < *pbVar12;
    if (bVar2 != *pbVar12) {
LAB_00409499:
      iVar5 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
      goto LAB_0040949e;
    }
    if (bVar2 == 0) break;
    bVar2 = pcVar4[1];
    this = (AIModule *)CONCAT31(uVar11,bVar2);
    bVar14 = bVar2 < pbVar12[1];
    if (bVar2 != pbVar12[1]) goto LAB_00409499;
    pcVar4 = pcVar4 + 2;
    pbVar12 = pbVar12 + 2;
  } while (bVar2 != 0);
  iVar5 = 0;
LAB_0040949e:
  if ((iVar5 == 0) || (pcStack_16c == (char *)0x0)) {
LAB_004097cf:
    if (pcStack_16c == (char *)0x0) {
      uVar9 = 0xffffffff;
      pcVar4 = &s_NULL;
      do {
        pcVar13 = pcVar4;
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        pcVar13 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar13;
      } while (cVar1 != '\0');
      uVar9 = ~uVar9;
      pcVar4 = pcVar13 + -uVar9;
      pcVar13 = (char *)0x0;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (this = (AIModule *)(uVar9 & 3); this != (AIModule *)0x0;
          this = (AIModule *)((int)&this[-1].processFrameValue + 3)) {
        *pcVar13 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar13 = pcVar13 + 1;
      }
    }
    AIModule::logCommonHistory(this,(char *)param_1,s_There_is_no_build_list_to_load_);
  }
  else {
    uVar9 = 0xffffffff;
    pcVar4 = pcStack_16c;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    this = (AIModule *)(~uVar9 - 1);
    if (this == (AIModule *)0x0) goto LAB_004097cf;
    AIModule::logCommonHistory(this,(char *)param_1,s_Trying_to_load_build_list_in_fil,param_2);
    sprintf(auStack_10c,s__s,pcVar13);
    iVar5 = fopen(auStack_10c,s_r);
    iStack_154 = iVar5;
    if (iVar5 == 0) {
      AIModule::logCommonHistory(this_00,(char *)param_1,s___I_cannot_do_it_cap_n_);
      uVar6 = 0;
      goto LAB_0040980c;
    }
    AIModule::logCommonHistory(this_00,(char *)param_1,s___File_open_successful__nuking_a);
    if (0 < param_1->buildListLengthValue) {
      BuildAIModule::removeOldList(param_1);
    }
    param_1->buildListLengthValue = 0;
    iVar7 = fgets(auStack_10c,0x100,iVar5);
    while (iVar7 != 0) {
      fStack_168 = 1.5;
      fStack_170 = 1.5;
      iStack_164 = -1;
      sscanf(auStack_10c,s___c_c,&cStack_171,&cStack_173);
      if ((cStack_171 != '/') || (cStack_173 != '/')) {
        sscanf(auStack_10c,s__c_d__s__d__d_,&uStack_172,&iStack_160,acStack_14c,&iStack_15c,
               &iStack_158);
        switch(uStack_172) {
        default:
          goto switchD_004095ec_caseD_a;
        case 0x41:
          iVar5 = 0;
          sscanf(auStack_10c,s___c__d___s___d___d__d_,&iStack_164);
          break;
        case 0x42:
          iVar5 = 0;
          break;
        case 0x43:
          iVar5 = 4;
          break;
        case 0x45:
          iVar5 = 5;
          break;
        case 0x47:
          iVar5 = 6;
          break;
        case 0x4c:
          iVar5 = 3;
          break;
        case 0x52:
          iVar5 = 1;
          break;
        case 0x54:
          iVar5 = 2;
          sscanf(auStack_10c,s___c__d___s___d___d__d_,&iStack_164);
          break;
        case 0x55:
          iVar5 = 2;
        }
        if (iVar5 == 0) {
          iVar7 = (param_1->typesToIgnore).numberValue;
          iVar8 = 0;
          if (0 < iVar7) {
            do {
              if ((param_1->typesToIgnore).maximumSizeValue <= iVar8) break;
              if ((param_1->typesToIgnore).value[iVar8] == iStack_160)
              goto switchD_004095ec_caseD_a;
              iVar8 = iVar8 + 1;
            } while (iVar8 < iVar7);
          }
        }
        if ((((iVar5 == 0) || (iVar5 == 2)) && (-1 < iStack_160)) &&
           ((iStack_160 < *(short *)(param_3 + 0x22) &&
            (iVar7 = *(int *)(*(int *)(param_3 + 0x24) + iStack_160 * 4), iVar7 != 0)))) {
          fStack_170 = *(float *)(iVar7 + 0x34);
          fStack_168 = *(float *)(iVar7 + 0x30);
        }
        fStack_168 = fStack_168 + fStack_168;
        fStack_170 = fStack_170 + fStack_170;
        iVar7 = 0;
        if (0 < iStack_15c) {
          do {
            pBStack_150 = (BuildItem *)operator_new(0xb0);
            this_01 = (BuildItem *)0x0;
            uStack_4 = 0;
            if (pBStack_150 != (BuildItem *)0x0) {
              this_01 = (BuildItem *)
                        BuildItem::BuildItem
                                  (pBStack_150,iVar5,iStack_160,param_1->buildListLengthValue,1,0,
                                   iStack_158,acStack_14c,fStack_168,fStack_170,0.0,-1,-1,-1,0);
            }
            uStack_4 = 0xffffffff;
            param_1->buildListLengthValue = param_1->buildListLengthValue + 1;
            this_01->next = &param_1->buildList;
            pBVar3 = (param_1->buildList).prev;
            this_01->prev = pBVar3;
            pBVar3->next = this_01;
            BuildItem::setBuildCap(this_01,iStack_164);
            iVar7 = iVar7 + 1;
            (param_1->buildList).prev = this_01;
          } while (iVar7 < iStack_15c);
        }
      }
switchD_004095ec_caseD_a:
      iVar5 = iStack_154;
      iVar7 = fgets(auStack_10c,0x100,iStack_154);
      pcVar13 = pcStack_16c;
    }
    fclose(iVar5);
    iVar5 = strstr(pcVar13,s__tmp);
    if (iVar5 != 0) {
      __unlink(pcVar13);
    }
  }
  uVar6 = 1;
LAB_0040980c:
  *unaff_FS_OFFSET = uStack_c;
  return uVar6;
}

// --------------------------------------------------

// Function: FUN_00409827
// Address: 00409827
int __fastcall FUN_00409827(char *param_1,undefined4 param_2)
{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  byte bVar20;
  byte bVar21;
  byte bVar22;
  byte bVar23;
  byte bVar24;
  byte bVar25;
  byte bVar26;
  byte bVar27;
  byte bVar28;
  int in_EAX;
  char *pcVar29;
  int iVar30;
  int iVar31;
  uint uVar32;
  byte *pbVar33;
  char cVar34;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  byte *unaff_EDI;
  int iVar35;
  
  LOCK();
  bVar2 = unaff_EDI[-0x6a08ffc0];
  unaff_EDI[-0x6a08ffc0] = (byte)param_2;
  pbVar33 = (byte *)CONCAT31((int3)((uint)param_2 >> 8),bVar2);
  UNLOCK();
  cVar34 = (char)unaff_EBX + (char)((uint)param_2 >> 8);
  iVar35 = CONCAT31((int3)((uint)unaff_EBX >> 8),cVar34);
  *param_1 = *param_1 + cVar34;
  pcVar29 = (char *)(unaff_EBP + 0x41 + (int)pbVar33 * 4);
  *pcVar29 = *pcVar29 + (byte)param_1;
  pcVar29 = (char *)(iVar35 + -0x6a);
  *pcVar29 = *pcVar29 + bVar2;
  *(char *)(in_EAX + -0x69) = *(char *)(in_EAX + -0x69) + (char)unaff_ESI + '\x02';
  *pbVar33 = *pbVar33 + bVar2;
  *unaff_EDI = *unaff_EDI + (char)((uint)(unaff_EBP + 2) >> 8);
  pcVar29 = (char *)(unaff_ESI + 4);
  *pcVar29 = *pcVar29 + (char)((uint)pcVar29 >> 8);
  iVar30 = unaff_EBP + 3;
  *(char *)(unaff_ESI + 0x409b) = *(char *)(unaff_ESI + 0x409b) + (char)iVar30;
  bVar2 = *pbVar33;
  bVar3 = *pbVar33;
  bVar4 = *pbVar33;
  bVar5 = *pbVar33;
  bVar6 = *pbVar33;
  bVar7 = *pbVar33;
  bVar8 = *pbVar33;
  bVar9 = *pbVar33;
  bVar10 = *pbVar33;
  bVar11 = *pbVar33;
  bVar12 = *pbVar33;
  bVar13 = *pbVar33;
  bVar14 = *pbVar33;
  bVar15 = *pbVar33;
  bVar16 = *pbVar33;
  bVar17 = *pbVar33;
  bVar18 = *pbVar33;
  bVar19 = *pbVar33;
  bVar20 = *pbVar33;
  bVar21 = *pbVar33;
  bVar22 = *pbVar33;
  bVar23 = *pbVar33;
  bVar24 = *pbVar33;
  bVar25 = *pbVar33;
  bVar26 = *pbVar33;
  bVar27 = *pbVar33;
  bVar28 = *pbVar33;
  *(int *)pbVar33 = *(int *)pbVar33 + iVar30;
  iVar31 = CONCAT31((int3)((uint)param_1 >> 8),
                    (byte)param_1 | bVar2 | bVar3 | bVar4 | bVar5 | bVar6 | bVar7 | bVar8 | bVar9 |
                    bVar10 | bVar11 | bVar12 | bVar13 | bVar14 | bVar15 | bVar16 | bVar17 | bVar18 |
                    bVar19 | bVar20 | bVar21 | bVar22 | bVar23 | bVar24 | bVar25 | bVar26 | bVar27 |
                    bVar28) + *(int *)pbVar33;
  iVar30 = CONCAT31((int3)((uint)iVar30 >> 8),(char)iVar30 + '\n') + 0xa0a0a0a;
  uVar32 = CONCAT31((int3)((uint)iVar31 >> 8),
                    (byte)iVar31 | *pbVar33 | *pbVar33 |
                    *(byte *)CONCAT31((int3)((uint)iVar30 >> 8),(byte)iVar30 | *unaff_EDI));
  puVar1 = (uint *)(iVar35 + 0x1a081);
  *puVar1 = *puVar1 | uVar32;
  return uVar32 + 0x1a4;
}

// --------------------------------------------------

// Function: FUN_004098a7
// Address: 004098a7
int __fastcall FUN_004098a7(int param_1)
{
  return param_1 + 0x1a4;
}

// --------------------------------------------------

// Function: FUN_004098b7
// Address: 004098b7
// [HELPER] s_NONE: "NONE"
// [HELPER] s_NULL: "NULL"
undefined4 __fastcall FUN_004098b7(int param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  pbVar4 = (byte *)(param_1 + 0x1a4);
  if (pbVar4 != (byte *)0x0) {
    pbVar5 = &s_NONE;
    pbVar2 = pbVar4;
    do {
      bVar1 = *pbVar2;
      bVar6 = bVar1 < *pbVar5;
      if (bVar1 != *pbVar5) {
LAB_004098fc:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_00409901;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar6 = bVar1 < pbVar5[1];
      if (bVar1 != pbVar5[1]) goto LAB_004098fc;
      pbVar2 = pbVar2 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_00409901:
    if (iVar3 != 0) {
      pbVar2 = &s_NULL;
      do {
        bVar1 = *pbVar4;
        bVar6 = bVar1 < *pbVar2;
        if (bVar1 != *pbVar2) {
LAB_00409934:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_00409939;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar6 = bVar1 < pbVar2[1];
        if (bVar1 != pbVar2[1]) goto LAB_00409934;
        pbVar4 = pbVar4 + 2;
        pbVar2 = pbVar2 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_00409939:
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040994c
// Address: 0040994c
// [HELPER] s_AddedBuildListItem: "AddedBuildListItem"
// [HELPER] s_SetGatherPercentage: "SetGatherPercentage"
undefined4 __thiscall
FUN_0040994c(int param_1,float param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            float param_8)
{
  BuildItem *pBVar1;
  undefined4 uVar2;
  int iVar3;
  BuildItem *pBVar4;
  int iVar5;
  BuildItem *this;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar6;
  char acStack_4c [64];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c50b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 0x1a0) < (int)param_8) {
    uVar2 = 0;
    goto LAB_00409b55;
  }
  pBVar1 = *(BuildItem **)(param_1 + 0x15c);
  for (iVar3 = 0; (pBVar1 != (BuildItem *)(param_1 + 0xf0) && (iVar3 < (int)param_8));
      iVar3 = iVar3 + 1) {
    pBVar1 = pBVar1->next;
  }
  if (param_5 == 6) {
    pcVar6 = s_SetGatherPercentage;
LAB_00409a0d:
    strncpy(acStack_4c,pcVar6,0x3f);
    param_2 = 3.0;
    param_8 = 3.0;
  }
  else {
    iVar3 = *(int *)(*(int *)((int)param_2 + 0x24) + param_3 * 4);
    if (iVar3 == 0) {
      pcVar6 = s_AddedBuildListItem;
      goto LAB_00409a0d;
    }
    strncpy(acStack_4c,*(undefined4 *)(iVar3 + 8),0x3f);
    iVar3 = *(int *)(*(int *)((int)param_2 + 0x24) + param_3 * 4);
    param_2 = *(float *)(iVar3 + 0x30);
    param_2 = param_2 + param_2;
    param_8 = *(float *)(iVar3 + 0x34);
    param_8 = param_8 + param_8;
  }
  iVar3 = *(int *)(param_1 + 0x1a0);
  iVar5 = 0;
  if (0 < param_4) {
    do {
      pBVar4 = (BuildItem *)operator_new(0xb0);
      this = (BuildItem *)0x0;
      uStack_4 = 0;
      if (pBVar4 != (BuildItem *)0x0) {
        this = (BuildItem *)
               BuildItem::BuildItem
                         (pBVar4,param_5,param_3,iVar3,1,0,param_6,acStack_4c,param_2,param_8,1.0,-1
                          ,-1,-1,0);
      }
      uStack_4 = 0xffffffff;
      if (this == (BuildItem *)0x0) {
        uVar2 = 0;
        goto LAB_00409b55;
      }
      BuildItem::setBuilt(this,0);
      BuildItem::setInProgress(this,0);
      BuildItem::setBuildAttempts(this,0);
      BaseItem::setSkip((BaseItem *)this,0);
      BaseItem::setGameID((BaseItem *)this,-1);
      BaseItem::setX((BaseItem *)this,-1.0);
      BaseItem::setY((BaseItem *)this,-1.0);
      BaseItem::setZ((BaseItem *)this,-1.0);
      BuildItem::setNumberBuilds(this,0);
      BuildItem::setBuildCap(this,param_7);
      BuildItem::setSkipCycles(this,0);
      BuildItem::setPermanentSkip(this,'\0');
      this->prev = pBVar1;
      pBVar4 = pBVar1->next;
      this->next = pBVar4;
      iVar3 = iVar3 + 1;
      pBVar4->prev = this;
      pBVar1->next = this;
      iVar5 = iVar5 + 1;
      *(int *)(param_1 + 0x1a0) = *(int *)(param_1 + 0x1a0) + 1;
    } while (iVar5 < param_4);
  }
  uVar2 = 1;
LAB_00409b55:
  *unaff_FS_OFFSET = uStack_c;
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_00409b6e
// Address: 00409b6e
int __fastcall FUN_00409b6e(int param_1)
{
  BuildItem *this;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (this = *(BuildItem **)(param_1 + 0x15c);
      (this != (BuildItem *)(param_1 + 0xf0) && (this != (BuildItem *)0x0)); this = this->next) {
    iVar1 = BuildItem::built(this);
    if (iVar1 == 1) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_00409ba3
// Address: 00409ba3
int __fastcall FUN_00409ba3(int param_1)
{
  BuildItem *this;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (this = *(BuildItem **)(param_1 + 0x15c);
      (this != (BuildItem *)(param_1 + 0xf0) && (this != (BuildItem *)0x0)); this = this->next) {
    iVar1 = BuildItem::inProgress(this);
    if (iVar1 == 1) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_00409be3
// Address: 00409be3
int __fastcall FUN_00409be3(int param_1)
{
  BuildItem *this;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (this = *(BuildItem **)(param_1 + 0x15c);
      (this != (BuildItem *)(param_1 + 0xf0) && (this != (BuildItem *)0x0)); this = this->next) {
    iVar1 = BuildItem::inProgress(this);
    if ((iVar1 == 1) || (iVar1 = BuildItem::built(this), iVar1 == 1)) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_00409c2f
// Address: 00409c2f
undefined4 __fastcall FUN_00409c2f(int param_1)
{
  return *(undefined4 *)(param_1 + 0x5a8);
}

// --------------------------------------------------

// Function: FUN_00409c37
// Address: 00409c37
int __fastcall FUN_00409c37(int param_1)
{
  return param_1 + 0x2a5;
}

// --------------------------------------------------

// Function: FUN_00409c47
// Address: 00409c47
int __fastcall FUN_00409c47(int param_1)
{
  return param_1 + 0x3a6;
}

// --------------------------------------------------

// Function: FUN_00409c57
// Address: 00409c57
int __fastcall FUN_00409c57(int param_1)
{
  return param_1 + 0x4a7;
}

// --------------------------------------------------

// Function: FUN_00409c67
// Address: 00409c67
int __thiscall FUN_00409c67(int param_1,int param_2,int param_3)
{
  BuildItem *this;
  int iVar1;
  int iStack_4;
  
  this = *(BuildItem **)(param_1 + 0x15c);
  iStack_4 = 0;
  for (; (this != (BuildItem *)(param_1 + 0xf0) && (this != (BuildItem *)0x0)); this = this->next) {
    iVar1 = BaseItem::typeID((BaseItem *)this);
    if ((iVar1 == param_2) && (iVar1 = BuildItem::buildCategory(this), iVar1 == param_3)) {
      iStack_4 = iStack_4 + 1;
    }
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_00409cc6
// Address: 00409cc6
int __thiscall FUN_00409cc6(int param_1,int param_2,int param_3)
{
  BuildItem *this;
  int iVar1;
  int iStack_4;
  
  this = *(BuildItem **)(param_1 + 0x15c);
  iStack_4 = 0;
  for (; (this != (BuildItem *)(param_1 + 0xf0) && (this != (BuildItem *)0x0)); this = this->next) {
    iVar1 = BaseItem::typeID((BaseItem *)this);
    if ((iVar1 == param_2) &&
       ((iVar1 = BuildItem::buildCategory(this), iVar1 == param_3 &&
        (iVar1 = BuildItem::built(this), iVar1 == 1)))) {
      iStack_4 = iStack_4 + 1;
    }
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_00409d32
// Address: 00409d32
int __thiscall FUN_00409d32(int param_1,int param_2,int param_3)
{
  BuildItem *this;
  int iVar1;
  int iStack_4;
  
  this = *(BuildItem **)(param_1 + 0x15c);
  iStack_4 = 0;
  for (; (this != (BuildItem *)(param_1 + 0xf0) && (this != (BuildItem *)0x0)); this = this->next) {
    iVar1 = BaseItem::typeID((BaseItem *)this);
    if ((iVar1 == param_2) &&
       ((iVar1 = BuildItem::buildCategory(this), iVar1 == param_3 &&
        (iVar1 = BuildItem::built(this), iVar1 == 0)))) {
      iStack_4 = iStack_4 + 1;
    }
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_00409da1
// Address: 00409da1
int __thiscall FUN_00409da1(int param_1,int param_2,int param_3)
{
  BuildItem *this;
  int iVar1;
  int iStack_4;
  
  this = *(BuildItem **)(param_1 + 0x15c);
  iStack_4 = 0;
  for (; (this != (BuildItem *)(param_1 + 0xf0) && (this != (BuildItem *)0x0)); this = this->next) {
    iVar1 = BaseItem::typeID((BaseItem *)this);
    if (((iVar1 == param_2) && (iVar1 = BuildItem::buildCategory(this), iVar1 == param_3)) &&
       ((iVar1 = BuildItem::built(this), iVar1 == 1 ||
        (iVar1 = BuildItem::inProgress(this), iVar1 == 1)))) {
      iStack_4 = iStack_4 + 1;
    }
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_00409e1e
// Address: 00409e1e
int __thiscall FUN_00409e1e(int param_1,int param_2,int param_3)
{
  BuildItem *this;
  int iVar1;
  int iStack_4;
  
  this = *(BuildItem **)(param_1 + 0x15c);
  iStack_4 = 0;
  for (; (this != (BuildItem *)(param_1 + 0xf0) && (this != (BuildItem *)0x0)); this = this->next) {
    iVar1 = BaseItem::typeID((BaseItem *)this);
    if ((iVar1 == param_2) &&
       ((iVar1 = BuildItem::buildCategory(this), iVar1 == param_3 &&
        (iVar1 = BuildItem::inProgress(this), iVar1 == 1)))) {
      iStack_4 = iStack_4 + 1;
    }
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_00409e82
// Address: 00409e82
void __fastcall FUN_00409e82(int param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 0x15c);
  puVar1 = (undefined4 *)(param_1 + 0xf0);
  while ((puVar2 != puVar1 && (puVar2 != (undefined4 *)0x0))) {
    puVar3 = (undefined4 *)*puVar2;
    puVar2 = (undefined4 *)puVar2[0x1b];
    (*(code *)*puVar3)(1);
  }
  *(undefined4 **)(param_1 + 0x15c) = puVar1;
  *(undefined4 **)(param_1 + 0x160) = puVar1;
  *(undefined4 *)(param_1 + 0x1a0) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00409ed2
// Address: 00409ed2
BuildItem * __thiscall FUN_00409ed2(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  BuildItem *this;
  
  this = *(BuildItem **)(param_1 + 0x15c);
  if (this != (BuildItem *)(param_1 + 0xf0)) {
    while (this != (BuildItem *)0x0) {
      iVar1 = BaseItem::typeID((BaseItem *)this);
      if ((iVar1 == param_2) &&
         ((param_3 == 0 || ((param_3 == 1 && (iVar1 = BuildItem::built(this), iVar1 == param_4))))))
{
        return this;
      }
      this = this->next;
      if (this == (BuildItem *)(param_1 + 0xf0)) {
        return (BuildItem *)0x0;
      }
    }
  }
  return (BuildItem *)0x0;
}

// --------------------------------------------------

// Function: FUN_00409f43
// Address: 00409f43
BaseItem * __thiscall FUN_00409f43(int param_1,int param_2)
{
  int iVar1;
  BaseItem *this;
  
  this = *(BaseItem **)(param_1 + 0x15c);
  if (this != (BaseItem *)(param_1 + 0xf0)) {
    while (this != (BaseItem *)0x0) {
      iVar1 = BaseItem::uniqueID(this);
      if (iVar1 == param_2) {
        return this;
      }
      this = (BaseItem *)this[1]._padding_;
      if (this == (BaseItem *)(param_1 + 0xf0)) {
        return (BaseItem *)0x0;
      }
    }
  }
  return (BaseItem *)0x0;
}

// --------------------------------------------------

// Function: FUN_00409f95
// Address: 00409f95
// [HELPER] s_: ""
undefined4 * __fastcall FUN_00409f95(undefined4 *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0xffffffff;
  param_1[6] = 0xffffffff;
  param_1[7] = 0xffffffff;
  param_1[0x18] = 0xbf800000;
  param_1[0x19] = 0xbf800000;
  param_1[0x1a] = 0xbf800000;
  param_1[0x1b] = 0xbf800000;
  param_1[0x1c] = 0xbf800000;
  param_1[0x1d] = 0xbf800000;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0xffffffff;
  param_1[0x23] = 0xffffffff;
  param_1[0x24] = 0xffffffff;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  *param_1 = &BaseObject::_vftable_;
  pcVar4 = s_;
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
  pcVar5 = (char *)(param_1 + 8);
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
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040a038
// Address: 0040a038
BaseObject * __thiscall FUN_0040a038(BaseObject *param_1,byte param_2)
{
  BaseObject::~BaseObject(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040a05e
// Address: 0040a05e
undefined4 * __thiscall
FUN_0040a05e(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined4 param_13,undefined4 param_14,undefined4 param_15)
{
  undefined4 *puVar1;
  
  param_1[5] = param_3;
  param_1[6] = param_4;
  param_1[7] = param_5;
  param_1[0x18] = param_10;
  param_1[0x19] = param_11;
  param_1[0x1a] = param_12;
  param_1[0x1b] = param_7;
  param_1[0x1c] = param_8;
  param_1[0x1d] = param_9;
  param_1[0x1e] = param_13;
  param_1[0x1f] = param_14;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 1;
  param_1[0x20] = param_15;
  param_1[0x21] = 0;
  param_1[0x22] = 0xffffffff;
  param_1[0x23] = 0xffffffff;
  param_1[0x24] = 0xffffffff;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  *param_1 = &BaseObject::_vftable_;
  puVar1 = (undefined4 *)operator_new(4);
  param_1[4] = puVar1;
  *puVar1 = param_2;
  strncpy(param_1 + 8,param_6,0x3f);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040a128
// Address: 0040a128
undefined4 * __thiscall FUN_0040a128(undefined4 *param_1,int param_2)
{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[5] = *(undefined4 *)(param_2 + 0x14);
  param_1[6] = *(undefined4 *)(param_2 + 0x18);
  param_1[7] = *(undefined4 *)(param_2 + 0x1c);
  param_1[0x18] = *(undefined4 *)(param_2 + 0x60);
  param_1[0x19] = *(undefined4 *)(param_2 + 100);
  param_1[0x1a] = *(undefined4 *)(param_2 + 0x68);
  param_1[0x1b] = *(undefined4 *)(param_2 + 0x6c);
  param_1[0x1c] = *(undefined4 *)(param_2 + 0x70);
  param_1[0x1d] = *(undefined4 *)(param_2 + 0x74);
  param_1[0x1e] = *(undefined4 *)(param_2 + 0x78);
  param_1[0x1f] = *(undefined4 *)(param_2 + 0x7c);
  param_1[0x20] = *(undefined4 *)(param_2 + 0x80);
  param_1[0x21] = *(undefined4 *)(param_2 + 0x84);
  param_1[0x22] = *(undefined4 *)(param_2 + 0x88);
  param_1[0x23] = *(undefined4 *)(param_2 + 0x8c);
  param_1[0x24] = *(undefined4 *)(param_2 + 0x90);
  param_1[0x25] = *(undefined4 *)(param_2 + 0x94);
  param_1[0x26] = *(undefined4 *)(param_2 + 0x98);
  uVar1 = *(undefined4 *)(param_2 + 0x9c);
  *param_1 = &BaseObject::_vftable_;
  param_1[0x27] = uVar1;
  pvVar2 = operator_new(param_1[3] << 2);
  param_1[4] = pvVar2;
  iVar3 = 0;
  if (0 < (int)param_1[3]) {
    do {
      *(undefined4 *)(param_1[4] + iVar3 * 4) =
           *(undefined4 *)(*(int *)(param_2 + 0x10) + iVar3 * 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1[3]);
  }
  strncpy(param_1 + 8,param_2 + 0x20,0x3f);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040a23c
// Address: 0040a23c
undefined4 * __thiscall FUN_0040a23c(undefined4 *param_1,int param_2)
{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[5] = *(undefined4 *)(param_2 + 0x14);
  param_1[6] = *(undefined4 *)(param_2 + 0x18);
  param_1[7] = *(undefined4 *)(param_2 + 0x1c);
  param_1[0x18] = *(undefined4 *)(param_2 + 0x60);
  param_1[0x19] = *(undefined4 *)(param_2 + 100);
  param_1[0x1a] = *(undefined4 *)(param_2 + 0x68);
  param_1[0x1b] = *(undefined4 *)(param_2 + 0x6c);
  param_1[0x1c] = *(undefined4 *)(param_2 + 0x70);
  param_1[0x1d] = *(undefined4 *)(param_2 + 0x74);
  param_1[0x1e] = *(undefined4 *)(param_2 + 0x78);
  param_1[0x1f] = *(undefined4 *)(param_2 + 0x7c);
  param_1[0x20] = *(undefined4 *)(param_2 + 0x80);
  param_1[0x21] = *(undefined4 *)(param_2 + 0x84);
  param_1[0x22] = *(undefined4 *)(param_2 + 0x88);
  param_1[0x23] = *(undefined4 *)(param_2 + 0x8c);
  param_1[0x24] = *(undefined4 *)(param_2 + 0x90);
  param_1[0x25] = *(undefined4 *)(param_2 + 0x94);
  param_1[0x26] = *(undefined4 *)(param_2 + 0x98);
  uVar1 = *(undefined4 *)(param_2 + 0x9c);
  *param_1 = &BaseObject::_vftable_;
  param_1[0x27] = uVar1;
  pvVar2 = operator_new(param_1[3] << 2);
  param_1[4] = pvVar2;
  iVar3 = 0;
  if (0 < (int)param_1[3]) {
    do {
      *(undefined4 *)(param_1[4] + iVar3 * 4) =
           *(undefined4 *)(*(int *)(param_2 + 0x10) + iVar3 * 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1[3]);
  }
  strncpy(param_1 + 8,param_2 + 0x20,0x3f);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040a34c
// Address: 0040a34c
void __fastcall FUN_0040a34c(undefined4 *param_1)
{
  *param_1 = &BaseObject::_vftable_;
  operator_delete((void *)param_1[4]);
  return;
}

// --------------------------------------------------

// Function: FUN_0040a363
// Address: 0040a363
bool FUN_0040a363(int param_1,int param_2)
{
  return *(int *)(param_1 + 0x1c) == *(int *)(param_2 + 0x1c);
}

// --------------------------------------------------

// Function: operator==
// Address: 0040a370
/* int __cdecl operator==(class BaseObject const &,class BaseObject const &) */

int __cdecl operator==(BaseObject *param_1,BaseObject *param_2)
{
  return (uint)(param_1->gameIDValue == param_2->gameIDValue);
}

// --------------------------------------------------

// Function: FUN_0040a388
// Address: 0040a388
bool FUN_0040a388(int param_1,int param_2)
{
  return *(int *)(param_1 + 0x1c) != *(int *)(param_2 + 0x1c);
}

// --------------------------------------------------

// Function: operator!=
// Address: 0040a390
/* int __cdecl operator!=(class BaseObject const &,class BaseObject const &) */

int __cdecl operator!=(BaseObject *param_1,BaseObject *param_2)
{
  return (uint)(param_1->gameIDValue != param_2->gameIDValue);
}

// --------------------------------------------------

// Function: FUN_0040a3a8
// Address: 0040a3a8
bool FUN_0040a3a8(int param_1,int param_2)
{
  return *(int *)(param_1 + 0x1c) < *(int *)(param_2 + 0x1c);
}

// --------------------------------------------------

// Function: operator<
// Address: 0040a3b0
/* int __cdecl operator<(class BaseObject const &,class BaseObject const &) */

int __cdecl operator<(BaseObject *param_1,BaseObject *param_2)
{
  return (uint)(param_1->gameIDValue < param_2->gameIDValue);
}

// --------------------------------------------------

// Function: FUN_0040a3c8
// Address: 0040a3c8
bool FUN_0040a3c8(int param_1,int param_2)
{
  return *(int *)(param_2 + 0x1c) < *(int *)(param_1 + 0x1c);
}

// --------------------------------------------------

// Function: operator>
// Address: 0040a3d0
/* int __cdecl operator>(class BaseObject const &,class BaseObject const &) */

int __cdecl operator>(BaseObject *param_1,BaseObject *param_2)
{
  return (uint)(param_2->gameIDValue < param_1->gameIDValue);
}

// --------------------------------------------------

// Function: FUN_0040a3e8
// Address: 0040a3e8
undefined4 __fastcall FUN_0040a3e8(int param_1)
{
  return *(undefined4 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_0040a3f4
// Address: 0040a3f4
undefined4 __thiscall FUN_0040a3f4(int param_1,int param_2)
{
  if (((*(int *)(param_1 + 0x10) != 0) && (-1 < param_2)) && (param_2 < *(int *)(param_1 + 0xc))) {
    return *(undefined4 *)(*(int *)(param_1 + 0x10) + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0040a452
// Address: 0040a452
undefined4 __thiscall FUN_0040a452(BaseObject *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = BaseObject::inGroup(param_1,param_2);
  if (iVar1 != 0) {
    return 0;
  }
  piVar2 = (int *)operator_new(param_1->numberGroupsValue * 4 + 4);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  iVar1 = 0;
  if (0 < param_1->numberGroupsValue) {
    do {
      iVar3 = iVar1 + 1;
      piVar2[iVar1] = param_1->groupIDValue[iVar1];
      iVar1 = iVar3;
    } while (iVar3 < param_1->numberGroupsValue);
  }
  piVar2[param_1->numberGroupsValue] = param_2;
  param_1->numberGroupsValue = param_1->numberGroupsValue + 1;
  operator_delete(param_1->groupIDValue);
  param_1->groupIDValue = piVar2;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040a4dd
// Address: 0040a4dd
undefined4 __thiscall FUN_0040a4dd(BaseObject *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = BaseObject::inGroup(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  piVar2 = (int *)operator_new(param_1->numberGroupsValue * 4 - 4);
  if (piVar2 != (int *)0x0) {
    iVar1 = 0;
    piVar3 = piVar2;
    if (0 < param_1->numberGroupsValue) {
      do {
        if (param_1->groupIDValue[iVar1] != param_2) {
          *piVar3 = param_1->groupIDValue[iVar1];
          piVar3 = piVar3 + 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1->numberGroupsValue);
    }
    param_1->numberGroupsValue = param_1->numberGroupsValue + -1;
    operator_delete(param_1->groupIDValue);
    param_1->groupIDValue = piVar2;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040a55b
// Address: 0040a55b
undefined4 __fastcall FUN_0040a55b(int param_1)
{
  return *(undefined4 *)(param_1 + 0x14);
}

// --------------------------------------------------

// Function: FUN_0040a564
// Address: 0040a564
undefined4 __fastcall FUN_0040a564(int param_1)
{
  return *(undefined4 *)(param_1 + 0x18);
}

// --------------------------------------------------

// Function: FUN_0040a574
// Address: 0040a574
int __fastcall FUN_0040a574(int param_1)
{
  return param_1 + 0x1c;
}

// --------------------------------------------------

// Function: FUN_0040a584
// Address: 0040a584
int __fastcall FUN_0040a584(int param_1)
{
  return param_1 + 0x20;
}

// --------------------------------------------------

// Function: FUN_0040a594
// Address: 0040a594
float10 __fastcall FUN_0040a594(int param_1)
{
  return (float10)*(float *)(param_1 + 0x60);
}

// --------------------------------------------------

// Function: FUN_0040a5a4
// Address: 0040a5a4
float10 __fastcall FUN_0040a5a4(int param_1)
{
  return (float10)*(float *)(param_1 + 100);
}

// --------------------------------------------------

// Function: FUN_0040a5b4
// Address: 0040a5b4
float10 __fastcall FUN_0040a5b4(int param_1)
{
  return (float10)*(float *)(param_1 + 0x68);
}

// --------------------------------------------------

// Function: FUN_0040a5c4
// Address: 0040a5c4
float10 __fastcall FUN_0040a5c4(int param_1)
{
  return (float10)*(float *)(param_1 + 0x6c);
}

// --------------------------------------------------

// Function: FUN_0040a5d4
// Address: 0040a5d4
float10 __fastcall FUN_0040a5d4(int param_1)
{
  return (float10)*(float *)(param_1 + 0x70);
}

// --------------------------------------------------

// Function: FUN_0040a5e4
// Address: 0040a5e4
float10 __fastcall FUN_0040a5e4(int param_1)
{
  return (float10)*(float *)(param_1 + 0x74);
}

// --------------------------------------------------

// Function: FUN_0040a5f4
// Address: 0040a5f4
undefined4 __fastcall FUN_0040a5f4(int param_1)
{
  return *(undefined4 *)(param_1 + 0x78);
}

// --------------------------------------------------

// Function: FUN_0040a604
// Address: 0040a604
undefined4 __fastcall FUN_0040a604(int param_1)
{
  return *(undefined4 *)(param_1 + 0x7c);
}

// --------------------------------------------------

// Function: FUN_0040a614
// Address: 0040a614
undefined4 __fastcall FUN_0040a614(int param_1)
{
  return *(undefined4 *)(param_1 + 0x80);
}

// --------------------------------------------------

// Function: FUN_0040a627
// Address: 0040a627
undefined4 __fastcall FUN_0040a627(int param_1)
{
  return *(undefined4 *)(param_1 + 0x84);
}

// --------------------------------------------------

// Function: FUN_0040a637
// Address: 0040a637
undefined4 __fastcall FUN_0040a637(int param_1)
{
  return *(undefined4 *)(param_1 + 0x88);
}

// --------------------------------------------------

// Function: FUN_0040a647
// Address: 0040a647
undefined4 __fastcall FUN_0040a647(int param_1)
{
  return *(undefined4 *)(param_1 + 0x8c);
}

// --------------------------------------------------

// Function: FUN_0040a657
// Address: 0040a657
undefined4 __fastcall FUN_0040a657(int param_1)
{
  return *(undefined4 *)(param_1 + 0x90);
}

// --------------------------------------------------

// Function: FUN_0040a667
// Address: 0040a667
float10 __fastcall FUN_0040a667(int param_1)
{
  return (float10)*(float *)(param_1 + 0x94);
}

// --------------------------------------------------

// Function: FUN_0040a677
// Address: 0040a677
float10 __fastcall FUN_0040a677(int param_1)
{
  return (float10)*(float *)(param_1 + 0x98);
}

// --------------------------------------------------

// Function: FUN_0040a687
// Address: 0040a687
float10 __fastcall FUN_0040a687(int param_1)
{
  return (float10)*(float *)(param_1 + 0x9c);
}

// --------------------------------------------------

// Function: FUN_0040a697
// Address: 0040a697
void __thiscall FUN_0040a697(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x60) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a6aa
// Address: 0040a6aa
void __thiscall FUN_0040a6aa(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 100) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a6ba
// Address: 0040a6ba
void __thiscall FUN_0040a6ba(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x68) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a6ca
// Address: 0040a6ca
void __thiscall FUN_0040a6ca(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x6c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a6da
// Address: 0040a6da
void __thiscall FUN_0040a6da(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x70) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a6ea
// Address: 0040a6ea
void __thiscall FUN_0040a6ea(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x74) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a6fa
// Address: 0040a6fa
void __thiscall FUN_0040a6fa(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x78) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a70a
// Address: 0040a70a
void __thiscall FUN_0040a70a(int param_1,int param_2)
{
  *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a71f
// Address: 0040a71f
void __thiscall FUN_0040a71f(int param_1,int param_2)
{
  *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) - param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a72f
// Address: 0040a72f
void __thiscall FUN_0040a72f(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x7c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a73a
// Address: 0040a73a
void __thiscall FUN_0040a73a(int param_1,int param_2)
{
  *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a74f
// Address: 0040a74f
void __thiscall FUN_0040a74f(int param_1,int param_2)
{
  *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) - param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a75f
// Address: 0040a75f
void __thiscall FUN_0040a75f(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x80) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a76d
// Address: 0040a76d
void __thiscall FUN_0040a76d(int param_1,int param_2)
{
  *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a785
// Address: 0040a785
void __thiscall FUN_0040a785(int param_1,int param_2)
{
  *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) - param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a7a5
// Address: 0040a7a5
void __thiscall FUN_0040a7a5(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x84) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a7bd
// Address: 0040a7bd
void __thiscall FUN_0040a7bd(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x88) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a7cd
// Address: 0040a7cd
void __thiscall FUN_0040a7cd(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x8c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a7dd
// Address: 0040a7dd
void __thiscall FUN_0040a7dd(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x90) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a7ed
// Address: 0040a7ed
void __thiscall FUN_0040a7ed(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x94) = param_2;
  *(undefined4 *)(param_1 + 0x98) = param_3;
  *(undefined4 *)(param_1 + 0x9c) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_0040a811
// Address: 0040a811
BaseItem * __fastcall FUN_0040a811(BaseItem *param_1)
{
  BaseItem::BaseItem(param_1);
  param_1->_padding_ = (int)&ConstructionItem::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1].typeIDValue = 0;
  param_1[1].gameIDValue = 0;
  param_1[1].uniqueIDValue = 0;
  param_1[1].nameValue[0] = '\0';
  param_1[1].nameValue[1] = '\0';
  param_1[1].nameValue[2] = '\0';
  param_1[1].nameValue[3] = '\0';
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040a843
// Address: 0040a843
ConstructionItem * __thiscall FUN_0040a843(ConstructionItem *param_1,byte param_2)
{
  ConstructionItem::~ConstructionItem(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040a86e
// Address: 0040a86e
BaseItem * __thiscall
FUN_0040a86e(BaseItem *param_1,float param_2,float param_3,float param_4,float param_5,float param_6
            ,float param_7,int param_8,char *param_9)
{
  BaseItem::BaseItem(param_1,param_8,-1,-1,param_9,param_2,param_3,param_4,param_5,param_6,param_7);
  param_1->_padding_ = (int)&ConstructionItem::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1].typeIDValue = 0;
  param_1[1].gameIDValue = 0;
  param_1[1].uniqueIDValue = 0;
  param_1[1].nameValue[0] = '\0';
  param_1[1].nameValue[1] = '\0';
  param_1[1].nameValue[2] = '\0';
  param_1[1].nameValue[3] = '\0';
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040a8c3
// Address: 0040a8c3
BaseItem * __thiscall FUN_0040a8c3(BaseItem *param_1,BaseItem *param_2)
{
  BaseItem::BaseItem(param_1,param_2);
  param_1[1]._padding_ = 0;
  param_1[1].typeIDValue = 0;
  param_1[1].gameIDValue = param_2[1].gameIDValue;
  param_1[1].uniqueIDValue = param_2[1].uniqueIDValue;
  *(undefined4 *)param_1[1].nameValue = *(undefined4 *)param_2[1].nameValue;
  param_1->_padding_ = (int)&ConstructionItem::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040a905
// Address: 0040a905
BaseItem * __thiscall FUN_0040a905(BaseItem *param_1,BaseItem *param_2)
{
  BaseItem::BaseItem(param_1,param_2);
  param_1[1]._padding_ = 0;
  param_1[1].typeIDValue = 0;
  param_1[1].gameIDValue = param_2[1].gameIDValue;
  param_1[1].uniqueIDValue = param_2[1].uniqueIDValue;
  *(undefined4 *)param_1[1].nameValue = *(undefined4 *)param_2[1].nameValue;
  param_1->_padding_ = (int)&ConstructionItem::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040a945
// Address: 0040a945
void __fastcall FUN_0040a945(BaseItem *param_1)
{
  param_1->_padding_ = (int)&ConstructionItem::_vftable_;
  BaseItem::~BaseItem(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0040a95b
// Address: 0040a95b
undefined4 FUN_0040a95b(int param_1,int param_2)
{
  if ((*(float *)(param_1 + 0x50) == *(float *)(param_2 + 0x50)) &&
     (*(float *)(param_1 + 0x54) == *(float *)(param_2 + 0x54))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: operator==
// Address: 0040a960
/* int __cdecl operator==(class ConstructionItem const &,class ConstructionItem const &) */

int __cdecl operator==(ConstructionItem *param_1,ConstructionItem *param_2)
{
  if (((float)param_1->_padding_ == (float)param_2->_padding_) &&
     ((float)param_1->_padding_ == (float)param_2->_padding_)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040a98b
// Address: 0040a98b
undefined4 FUN_0040a98b(int param_1,int param_2)
{
  if ((*(float *)(param_1 + 0x50) == *(float *)(param_2 + 0x50)) &&
     (*(float *)(param_1 + 0x54) == *(float *)(param_2 + 0x54))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: operator!=
// Address: 0040a990
/* int __cdecl operator!=(class ConstructionItem const &,class ConstructionItem const &) */

int __cdecl operator!=(ConstructionItem *param_1,ConstructionItem *param_2)
{
  if (((float)param_1->_padding_ == (float)param_2->_padding_) &&
     ((float)param_1->_padding_ == (float)param_2->_padding_)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040a9bb
// Address: 0040a9bb
bool FUN_0040a9bb(int param_1,int param_2)
{
  return *(int *)(param_1 + 4) < *(int *)(param_2 + 4);
}

// --------------------------------------------------

// Function: operator<
// Address: 0040a9c0
/* int __cdecl operator<(class ConstructionItem const &,class ConstructionItem const &) */

int __cdecl operator<(ConstructionItem *param_1,ConstructionItem *param_2)
{
  return (uint)(param_1->_padding_ < param_2->_padding_);
}

// --------------------------------------------------

// Function: FUN_0040a9d8
// Address: 0040a9d8
bool FUN_0040a9d8(int param_1,int param_2)
{
  return *(int *)(param_2 + 4) < *(int *)(param_1 + 4);
}

// --------------------------------------------------

// Function: operator>
// Address: 0040a9e0
/* int __cdecl operator>(class ConstructionItem const &,class ConstructionItem const &) */

int __cdecl operator>(ConstructionItem *param_1,ConstructionItem *param_2)
{
  return (uint)(param_2->_padding_ < param_1->_padding_);
}

// --------------------------------------------------

// Function: FUN_0040a9f8
// Address: 0040a9f8
undefined4 __fastcall FUN_0040a9f8(int param_1)
{
  return *(undefined4 *)(param_1 + 0x74);
}

// --------------------------------------------------

// Function: FUN_0040aa04
// Address: 0040aa04
undefined4 __fastcall FUN_0040aa04(int param_1)
{
  return *(undefined4 *)(param_1 + 0x78);
}

// --------------------------------------------------

// Function: FUN_0040aa14
// Address: 0040aa14
undefined4 __fastcall FUN_0040aa14(int param_1)
{
  return *(undefined4 *)(param_1 + 0x7c);
}

// --------------------------------------------------

// Function: FUN_0040aa24
// Address: 0040aa24
void __thiscall FUN_0040aa24(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x74) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040aa3a
// Address: 0040aa3a
void __thiscall FUN_0040aa3a(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x78) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040aa4a
// Address: 0040aa4a
void __fastcall FUN_0040aa4a(int param_1)
{
  *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0040aa54
// Address: 0040aa54
void __fastcall FUN_0040aa54(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x7c) + -1;
  *(int *)(param_1 + 0x7c) = iVar1;
  if (iVar1 < 0) {
    *(undefined4 *)(param_1 + 0x7c) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040aa71
// Address: 0040aa71
void __thiscall FUN_0040aa71(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x7c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040aa8a
// Address: 0040aa8a
// [HELPER] s_: ""
// [HELPER] s_ConAI: "ConAI"
AIModule * __thiscall FUN_0040aa8a(AIModule *param_1,void *param_2,int param_3)
{
  AIModuleID *this;
  ConstructionItem *this_00;
  char cVar1;
  AIModule *pAVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c536;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  AIModule::AIModule(param_1,s_ConAI,0x3ea,param_3,param_2);
  this = &param_1[1].idValue;
  uStack_4 = 0;
  param_1[1]._padding_ = 0;
  ConstructionItem::ConstructionItem((ConstructionItem *)this);
  this_00 = (ConstructionItem *)(param_1[1].playerNameValue + 0x38);
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  param_1[1].playerNameValue[0x34] = '\0';
  param_1[1].playerNameValue[0x35] = '\0';
  param_1[1].playerNameValue[0x36] = '\0';
  param_1[1].playerNameValue[0x37] = '\0';
  ConstructionItem::ConstructionItem(this_00);
  uVar3 = 0xffffffff;
  pAVar2 = param_1 + 3;
  (pAVar2->idValue).name[0x20] = '\0';
  (pAVar2->idValue).name[0x21] = '\0';
  (pAVar2->idValue).name[0x22] = -0x80;
  (pAVar2->idValue).name[0x23] = -0x41;
  pAVar2 = param_1 + 3;
  (pAVar2->idValue).name[0x24] = '\0';
  (pAVar2->idValue).name[0x25] = '\0';
  (pAVar2->idValue).name[0x26] = -0x80;
  (pAVar2->idValue).name[0x27] = -0x41;
  pAVar2 = param_1 + 3;
  (pAVar2->idValue).name[0x28] = '\0';
  (pAVar2->idValue).name[0x29] = '\0';
  (pAVar2->idValue).name[0x2a] = -0x80;
  (pAVar2->idValue).name[0x2b] = -0x41;
  param_1[2].idValue._padding_ = (int)this_00;
  param_1[2].idValue.id = (int)this_00;
  pAVar2 = param_1 + 3;
  (pAVar2->idValue).name[0x2c] = -1;
  (pAVar2->idValue).name[0x2d] = -1;
  (pAVar2->idValue).name[0x2e] = -1;
  (pAVar2->idValue).name[0x2f] = -1;
  pAVar2 = param_1 + 3;
  (pAVar2->idValue).name[0x30] = -1;
  (pAVar2->idValue).name[0x31] = -1;
  (pAVar2->idValue).name[0x32] = -1;
  (pAVar2->idValue).name[0x33] = -1;
  pAVar2 = param_1 + 3;
  (pAVar2->idValue).name[0x34] = '\0';
  (pAVar2->idValue).name[0x35] = '\0';
  (pAVar2->idValue).name[0x36] = '\0';
  (pAVar2->idValue).name[0x37] = '\0';
  param_1->_padding_ = (int)&ConstructionAIModule::_vftable_;
  *(AIModuleID **)(param_1[1].playerNameValue + 0x20) = this;
  *(AIModuleID **)(param_1[1].playerNameValue + 0x24) = this;
  pcVar5 = s_;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = param_1[2].idValue.name + 0xc;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040ab82
// Address: 0040ab82
ConstructionAIModule * __thiscall FUN_0040ab82(ConstructionAIModule *param_1,byte param_2)
{
  ConstructionAIModule::~ConstructionAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040abae
// Address: 0040abae
// [HELPER] s_ConAI: "ConAI"
AIModule * __thiscall FUN_0040abae(AIModule *param_1,int param_2,int param_3)
{
  AIModule *pAVar1;
  AIModuleID *this;
  ConstructionItem *pCVar2;
  int iVar3;
  AIModule *pAVar4;
  ConstructionItem *pCVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  int iStack_154;
  float fStack_150;
  float fStack_14c;
  float fStack_148;
  float fStack_144;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  int iStack_12c;
  int iStack_128;
  float fStack_124;
  float fStack_120;
  int iStack_11c;
  ConstructionItem *pCStack_118;
  AIModule *pAStack_114;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c589;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pAStack_114 = param_1;
  AIModule::AIModule(param_1,s_ConAI,0x3ea,param_2,(void *)0x0);
  pAVar1 = param_1 + 1;
  this = &param_1[1].idValue;
  uStack_4 = 0;
  pAVar1->_padding_ = 0;
  ConstructionItem::ConstructionItem((ConstructionItem *)this);
  pCVar5 = (ConstructionItem *)(param_1[1].playerNameValue + 0x38);
  uStack_4._0_1_ = 1;
  param_1[1].playerNameValue[0x34] = '\0';
  param_1[1].playerNameValue[0x35] = '\0';
  param_1[1].playerNameValue[0x36] = '\0';
  param_1[1].playerNameValue[0x37] = '\0';
  ConstructionItem::ConstructionItem(pCVar5);
  *(AIModuleID **)(param_1[1].playerNameValue + 0x20) = this;
  *(AIModuleID **)(param_1[1].playerNameValue + 0x24) = this;
  uStack_4 = CONCAT31(uStack_4._1_3_,2);
  pAVar4 = param_1 + 3;
  (pAVar4->idValue).name[0x20] = '\0';
  (pAVar4->idValue).name[0x21] = '\0';
  (pAVar4->idValue).name[0x22] = -0x80;
  (pAVar4->idValue).name[0x23] = -0x41;
  pAVar4 = param_1 + 3;
  (pAVar4->idValue).name[0x24] = '\0';
  (pAVar4->idValue).name[0x25] = '\0';
  (pAVar4->idValue).name[0x26] = -0x80;
  (pAVar4->idValue).name[0x27] = -0x41;
  pAVar4 = param_1 + 3;
  (pAVar4->idValue).name[0x28] = '\0';
  (pAVar4->idValue).name[0x29] = '\0';
  (pAVar4->idValue).name[0x2a] = -0x80;
  (pAVar4->idValue).name[0x2b] = -0x41;
  pAVar4 = param_1 + 3;
  (pAVar4->idValue).name[0x2c] = -1;
  (pAVar4->idValue).name[0x2d] = -1;
  (pAVar4->idValue).name[0x2e] = -1;
  (pAVar4->idValue).name[0x2f] = -1;
  pAVar4 = param_1 + 3;
  (pAVar4->idValue).name[0x30] = -1;
  (pAVar4->idValue).name[0x31] = -1;
  (pAVar4->idValue).name[0x32] = -1;
  (pAVar4->idValue).name[0x33] = -1;
  pAVar4 = param_1 + 3;
  (pAVar4->idValue).name[0x34] = '\0';
  (pAVar4->idValue).name[0x35] = '\0';
  (pAVar4->idValue).name[0x36] = '\0';
  (pAVar4->idValue).name[0x37] = '\0';
  param_1->_padding_ = (int)&ConstructionAIModule::_vftable_;
  param_1[2].idValue._padding_ = (int)pCVar5;
  param_1[2].idValue.id = (int)pCVar5;
  rge_read(param_3,pAVar1,4);
  rge_read(param_3,&iStack_154,4);
  rge_read(param_3,param_1[2].idValue.name + 0xc,iStack_154);
  param_1[2].idValue.name[iStack_154 + 0xc] = '\0';
  rge_read(param_3,param_1[3].idValue.name + 0x20,4);
  rge_read(param_3,param_1[3].idValue.name + 0x24,4);
  rge_read(param_3,param_1[3].idValue.name + 0x28,4);
  rge_read(param_3,param_1[3].idValue.name + 0x2c,4);
  rge_read(param_3,param_1[3].idValue.name + 0x30,4);
  iStack_11c = 0;
  if (0 < pAVar1->_padding_) {
    do {
      rge_read(param_3,&iStack_154,4);
      rge_read(param_3,acStack_110,iStack_154);
      acStack_110[iStack_154] = '\0';
      rge_read(param_3,&iStack_12c,4);
      rge_read(param_3,&fStack_138,4);
      rge_read(param_3,&fStack_130,4);
      rge_read(param_3,&fStack_150,4);
      rge_read(param_3,&fStack_134,4);
      rge_read(param_3,&fStack_124,4);
      rge_read(param_3,&fStack_13c,4);
      rge_read(param_3,&fStack_120,4);
      rge_read(param_3,&fStack_144,4);
      rge_read(param_3,&iStack_128,4);
      rge_read(param_3,&fStack_14c,4);
      rge_read(param_3,&fStack_148,4);
      rge_read(param_3,&fStack_140,4);
      pCStack_118 = (ConstructionItem *)operator_new(0x80);
      uStack_4._0_1_ = 3;
      if (pCStack_118 == (ConstructionItem *)0x0) {
        pCVar5 = (ConstructionItem *)0x0;
      }
      else {
        pCVar5 = (ConstructionItem *)
                 ConstructionItem::ConstructionItem
                           (pCStack_118,fStack_150,fStack_134,fStack_124,fStack_13c,fStack_120,
                            fStack_144,iStack_12c,acStack_110);
      }
      uStack_4 = CONCAT31(uStack_4._1_3_,2);
      ConstructionItem::setInProgress(pCVar5,(int)fStack_14c);
      ConstructionItem::setBuilt(pCVar5,(int)fStack_148);
      ConstructionItem::setBuildAttempts(pCVar5,(int)fStack_140);
      BaseItem::setGameID((BaseItem *)pCVar5,(int)fStack_138);
      BaseItem::setUniqueID((BaseItem *)pCVar5,(int)fStack_130);
      BaseItem::setSkip((BaseItem *)pCVar5,iStack_128);
      pCVar5->next = (ConstructionItem *)&param_1[1].idValue;
      pCVar2 = *(ConstructionItem **)(param_1[1].playerNameValue + 0x24);
      pCVar5->prev = pCVar2;
      pCVar2->next = pCVar5;
      iVar6 = pAVar1->_padding_;
      iStack_11c = iStack_11c + 1;
      *(ConstructionItem **)(param_1[1].playerNameValue + 0x24) = pCVar5;
    } while (iStack_11c < iVar6);
  }
  rge_read(param_3,param_1[1].playerNameValue + 0x34,4);
  iVar6 = 0;
  if (0 < *(int *)(param_1[1].playerNameValue + 0x34)) {
    do {
      rge_read(param_3,&iStack_154,4);
      rge_read(param_3,acStack_110,iStack_154);
      acStack_110[iStack_154] = '\0';
      rge_read(param_3,&iStack_128,4);
      rge_read(param_3,&fStack_120,4);
      rge_read(param_3,&fStack_144,4);
      rge_read(param_3,&fStack_150,4);
      rge_read(param_3,&fStack_14c,4);
      rge_read(param_3,&fStack_148,4);
      rge_read(param_3,&fStack_140,4);
      rge_read(param_3,&fStack_138,4);
      rge_read(param_3,&fStack_130,4);
      rge_read(param_3,&iStack_12c,4);
      rge_read(param_3,&fStack_134,4);
      rge_read(param_3,&fStack_124,4);
      rge_read(param_3,&fStack_13c,4);
      pCStack_118 = (ConstructionItem *)operator_new(0x80);
      uStack_4._0_1_ = 4;
      if (pCStack_118 == (ConstructionItem *)0x0) {
        pCVar5 = (ConstructionItem *)0x0;
      }
      else {
        pCVar5 = (ConstructionItem *)
                 ConstructionItem::ConstructionItem
                           (pCStack_118,fStack_150,fStack_14c,fStack_148,fStack_140,fStack_138,
                            fStack_130,iStack_128,acStack_110);
      }
      uStack_4 = CONCAT31(uStack_4._1_3_,2);
      ConstructionItem::setInProgress(pCVar5,(int)fStack_134);
      ConstructionItem::setBuilt(pCVar5,(int)fStack_124);
      ConstructionItem::setBuildAttempts(pCVar5,(int)fStack_13c);
      BaseItem::setGameID((BaseItem *)pCVar5,(int)fStack_120);
      BaseItem::setUniqueID((BaseItem *)pCVar5,(int)fStack_144);
      BaseItem::setSkip((BaseItem *)pCVar5,iStack_12c);
      iVar6 = iVar6 + 1;
      pCVar5->next = (ConstructionItem *)(param_1[1].playerNameValue + 0x38);
      pCVar2 = (ConstructionItem *)param_1[2].idValue.id;
      pCVar5->prev = pCVar2;
      pCVar2->next = pCVar5;
      iVar3 = *(int *)(param_1[1].playerNameValue + 0x34);
      param_1[2].idValue.id = (int)pCVar5;
    } while (iVar6 < iVar3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040b113
// Address: 0040b113
void __fastcall FUN_0040b113(ConstructionAIModule *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  pcStack_8 = FUN_0055c5c4;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&ConstructionAIModule::_vftable_;
  iStack_4 = 2;
  if (0 < param_1->numberConstructionLotsValue) {
    ConstructionAIModule::removeOldLots(param_1);
  }
  iStack_4._0_1_ = 1;
  ConstructionItem::~ConstructionItem(&param_1->randomConstructionLots);
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  ConstructionItem::~ConstructionItem(&param_1->constructionLots);
  iStack_4 = 0xffffffff;
  AIModule::~AIModule((AIModule *)param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0040b199
// Address: 0040b199
undefined4 __thiscall FUN_0040b199(int param_1,int param_2)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  ConstructionItem *pCVar6;
  char *pcVar7;
  int iStack_118;
  float fStack_114;
  int iStack_110;
  ConstructionItem *pCStack_10c;
  int iStack_108;
  char acStack_104 [260];
  
  iStack_108 = param_1;
  rge_write(param_2,(void *)(param_1 + 0xf0),4);
  uVar4 = 0xffffffff;
  pcVar3 = (char *)(param_1 + 0x1f8);
  do {
    pcVar7 = pcVar3;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar3 = pcVar7 + -uVar4;
  pcVar7 = acStack_104;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar3 = acStack_104;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iStack_118 = ~uVar4 - 1;
  rge_write(param_2,&iStack_118,4);
  uVar4 = 0xffffffff;
  pcVar3 = acStack_104;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  rge_write(param_2,acStack_104,~uVar4 - 1);
  rge_write(param_2,(void *)(param_1 + 0x2fc),4);
  rge_write(param_2,(void *)(param_1 + 0x300),4);
  rge_write(param_2,(void *)(param_1 + 0x304),4);
  rge_write(param_2,(void *)(param_1 + 0x308),4);
  rge_write(param_2,(void *)(param_1 + 0x30c),4);
  pCVar6 = *(ConstructionItem **)(param_1 + 0x160);
  pCStack_10c = (ConstructionItem *)(iStack_108 + 0xf4);
  if (pCVar6 != pCStack_10c) {
    do {
      if (pCVar6 == (ConstructionItem *)0x0) break;
      pcVar3 = BaseItem::name((BaseItem *)pCVar6);
      uVar4 = 0xffffffff;
      do {
        pcVar7 = pcVar3;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar7 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar7;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar3 = pcVar7 + -uVar4;
      pcVar7 = acStack_104;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      }
      uVar4 = 0xffffffff;
      pcVar3 = acStack_104;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      iStack_118 = ~uVar4 - 1;
      rge_write(param_2,&iStack_118,4);
      rge_write(param_2,acStack_104,iStack_118);
      iStack_118 = BaseItem::typeID((BaseItem *)pCVar6);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BaseItem::gameID((BaseItem *)pCVar6);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BaseItem::uniqueID((BaseItem *)pCVar6);
      rge_write(param_2,&iStack_118,4);
      fStack_114 = BaseItem::x((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::y((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::z((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::xSize((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::ySize((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::zSize((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      iStack_110 = BaseItem::skip((BaseItem *)pCVar6);
      rge_write(param_2,&iStack_110,4);
      iStack_110 = ConstructionItem::inProgress(pCVar6);
      rge_write(param_2,&iStack_110,4);
      iStack_110 = ConstructionItem::built(pCVar6);
      rge_write(param_2,&iStack_110,4);
      iStack_118 = ConstructionItem::buildAttempts(pCVar6);
      rge_write(param_2,&iStack_118,4);
      pCVar6 = pCVar6->next;
    } while (pCVar6 != pCStack_10c);
  }
  iVar2 = iStack_108;
  rge_write(param_2,(void *)(iStack_108 + 0x174),4);
  pCVar6 = *(ConstructionItem **)(iVar2 + 0x1e4);
  pCStack_10c = (ConstructionItem *)(iVar2 + 0x178);
  if (pCVar6 != pCStack_10c) {
    do {
      if (pCVar6 == (ConstructionItem *)0x0) {
        return 1;
      }
      pcVar3 = BaseItem::name((BaseItem *)pCVar6);
      uVar4 = 0xffffffff;
      do {
        pcVar7 = pcVar3;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar7 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar7;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar3 = pcVar7 + -uVar4;
      pcVar7 = acStack_104;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      }
      uVar4 = 0xffffffff;
      pcVar3 = acStack_104;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      iStack_118 = ~uVar4 - 1;
      rge_write(param_2,&iStack_118,4);
      rge_write(param_2,acStack_104,iStack_118);
      iStack_118 = BaseItem::typeID((BaseItem *)pCVar6);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BaseItem::gameID((BaseItem *)pCVar6);
      rge_write(param_2,&iStack_118,4);
      iStack_118 = BaseItem::uniqueID((BaseItem *)pCVar6);
      rge_write(param_2,&iStack_118,4);
      fStack_114 = BaseItem::x((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::y((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::z((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::xSize((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::ySize((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      fStack_114 = BaseItem::zSize((BaseItem *)pCVar6);
      rge_write(param_2,&fStack_114,4);
      iStack_110 = BaseItem::skip((BaseItem *)pCVar6);
      rge_write(param_2,&iStack_110,4);
      iStack_110 = ConstructionItem::inProgress(pCVar6);
      rge_write(param_2,&iStack_110,4);
      iStack_110 = ConstructionItem::built(pCVar6);
      rge_write(param_2,&iStack_110,4);
      iStack_118 = ConstructionItem::buildAttempts(pCVar6);
      rge_write(param_2,&iStack_118,4);
      pCVar6 = pCVar6->next;
    } while (pCVar6 != pCStack_10c);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040b68f
// Address: 0040b68f
// [HELPER] s_Loading_construction_plan_in_fil: "Loading construction plan in file '%s'."
// [HELPER] s_NONE: "NONE"
// [HELPER] s_NULL: "NULL"
// [HELPER] s_There_is_no_construction_plan_to: "There is no construction plan to load."
// [HELPER] s___c_c: " %c%c"
// [HELPER] s__f__f__f__f__f__f__d__s_: "%f %f %f %f %f %f %d %s "
// [HELPER] s__s: "%s"
// [HELPER] s__tmp: ".tmp"
// [HELPER] s_r: "r"
int __thiscall
FUN_0040b68f(ConstructionAIModule *param_1,undefined4 param_2,int param_3,int param_4,float param_5,
            float param_6,float param_7)
{
  char cVar1;
  byte bVar2;
  ConstructionItem *pCVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  ConstructionItem *pCVar7;
  AIModule *extraout_ECX;
  undefined3 uVar10;
  uint uVar8;
  uint uVar9;
  AIModule *this;
  byte *pbVar11;
  char *pcVar12;
  undefined4 *unaff_FS_OFFSET;
  bool bVar13;
  char cStack_172;
  char cStack_171;
  float fStack_170;
  float fStack_16c;
  float fStack_168;
  float fStack_164;
  char *pcStack_160;
  int iStack_15c;
  float fStack_158;
  float fStack_154;
  ConstructionItem *pCStack_150;
  char acStack_14c [64];
  undefined1 auStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c5de;
  *unaff_FS_OFFSET = &uStack_c;
  ConstructionAIModule::setReferencePoint(param_1,param_3,param_4,param_5,param_6,param_7);
  if (0 < param_1->numberConstructionLotsValue) {
    ConstructionAIModule::removeOldLots(param_1);
  }
  pcVar12 = param_1->constructionPlanNameValue;
  pcStack_160 = pcVar12;
  strncpy(pcVar12,param_2,0x3f);
  pbVar11 = &s_NONE;
  pcVar4 = pcVar12;
  this = extraout_ECX;
  do {
    bVar2 = *pcVar4;
    uVar10 = (undefined3)((uint)this >> 8);
    this = (AIModule *)CONCAT31(uVar10,bVar2);
    bVar13 = bVar2 < *pbVar11;
    if (bVar2 != *pbVar11) {
LAB_0040b736:
      iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
      goto LAB_0040b73b;
    }
    if (bVar2 == 0) break;
    bVar2 = pcVar4[1];
    this = (AIModule *)CONCAT31(uVar10,bVar2);
    bVar13 = bVar2 < pbVar11[1];
    if (bVar2 != pbVar11[1]) goto LAB_0040b736;
    pcVar4 = pcVar4 + 2;
    pbVar11 = pbVar11 + 2;
  } while (bVar2 != 0);
  iVar5 = 0;
LAB_0040b73b:
  if (iVar5 == 0) {
    if (pcVar12 == (char *)0x0) goto LAB_0040b91b;
LAB_0040b93d:
    AIModule::logCommonHistory(this,(char *)param_1,s_There_is_no_construction_plan_to);
  }
  else {
    if (pcVar12 == (char *)0x0) {
LAB_0040b91b:
      uVar8 = 0xffffffff;
      pcVar12 = &s_NULL;
      do {
        pcVar4 = pcVar12;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar4 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar4;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      pcVar12 = pcVar4 + -uVar8;
      pcVar4 = (char *)0x0;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar4 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar4 = pcVar4 + 4;
      }
      for (this = (AIModule *)(uVar8 & 3); this != (AIModule *)0x0;
          this = (AIModule *)((int)&this[-1].processFrameValue + 3)) {
        *pcVar4 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar4 = pcVar4 + 1;
      }
      goto LAB_0040b93d;
    }
    AIModule::logCommonHistory(this,(char *)param_1,s_Loading_construction_plan_in_fil,param_2);
    sprintf(auStack_10c,s__s,pcVar12);
    iVar5 = fopen(auStack_10c,s_r);
    if (iVar5 == 0) goto LAB_0040b950;
    iVar6 = fgets(auStack_10c,0x100,iVar5);
    while (iVar6 != 0) {
      sscanf(auStack_10c,s___c_c,&cStack_172,&cStack_171);
      if ((cStack_172 != '/') || (cStack_171 != '/')) {
        sscanf(auStack_10c,s__f__f__f__f__f__f__d__s_,&fStack_16c,&fStack_170,&fStack_168,
               &fStack_158,&fStack_154,&fStack_164,&iStack_15c,acStack_14c);
        fStack_16c = param_1->xReferencePointValue + fStack_16c;
        fStack_170 = param_1->yReferencePointValue + fStack_170;
        fStack_168 = param_1->zReferencePointValue + fStack_168;
        pCVar7 = ConstructionAIModule::lot(param_1,fStack_16c,fStack_170);
        if (pCVar7 == (ConstructionItem *)0x0) {
          pCStack_150 = (ConstructionItem *)operator_new(0x80);
          uStack_4 = 0;
          if (pCStack_150 == (ConstructionItem *)0x0) {
            pCVar7 = (ConstructionItem *)0x0;
          }
          else {
            pCVar7 = (ConstructionItem *)
                     ConstructionItem::ConstructionItem
                               (pCStack_150,fStack_16c,fStack_170,fStack_168,fStack_158,fStack_154,
                                fStack_164,iStack_15c,acStack_14c);
          }
          uStack_4 = 0xffffffff;
          pCVar7->next = &param_1->constructionLots;
          pCVar3 = (param_1->constructionLots).prev;
          pCVar7->prev = pCVar3;
          pCVar3->next = pCVar7;
          (param_1->constructionLots).prev = pCVar7;
          param_1->numberConstructionLotsValue = param_1->numberConstructionLotsValue + 1;
        }
      }
      iVar6 = fgets(auStack_10c,0x100,iVar5);
      pcVar12 = pcStack_160;
    }
    fclose(iVar5);
    iVar5 = strstr(pcVar12,s__tmp);
    if (iVar5 != 0) {
      __unlink(pcVar12);
    }
  }
  iVar5 = 1;
LAB_0040b950:
  *unaff_FS_OFFSET = uStack_c;
  return iVar5;
}

// --------------------------------------------------

// Function: FUN_0040b96b
// Address: 0040b96b
int __fastcall FUN_0040b96b(int param_1)
{
  return param_1 + 0x1f8;
}

// --------------------------------------------------

// Function: FUN_0040b977
// Address: 0040b977
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0040b977(ConstructionAIModule *param_1,int param_2,int param_3,float param_4,float param_5,
            float param_6)
{
  ConstructionItem *this;
  ConstructionItem *pCVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)UNK_0056e7fc._4_8_;
  param_1->mapXSizeValue = param_2;
  param_1->yReferencePointValue = param_5;
  param_1->mapYSizeValue = param_3;
  param_1->xReferencePointValue = param_4;
  param_1->zReferencePointValue = param_6;
  if ((((param_4 <= fVar2) || (param_5 <= (float)UNK_0056e7fc._4_8_)) || ((float)param_2 <= param_4)
      ) || ((float)param_3 <= param_5)) {
    ConstructionAIModule::removeOldLots(param_1);
  }
  else {
    this = (param_1->constructionLots).next;
    if (this != &param_1->constructionLots) {
      while (this != (ConstructionItem *)0x0) {
        fVar2 = BaseItem::x((BaseItem *)this);
        BaseItem::setX((BaseItem *)this,fVar2 + param_4);
        fVar2 = BaseItem::y((BaseItem *)this);
        BaseItem::setY((BaseItem *)this,fVar2 + param_5);
        fVar2 = BaseItem::z((BaseItem *)this);
        BaseItem::setZ((BaseItem *)this,fVar2 + param_6);
        fVar2 = BaseItem::x((BaseItem *)this);
        fVar3 = BaseItem::xSize((BaseItem *)this);
        if (fVar2 - fVar3 * ram0x0056e808 < _DAT_0056e80c) {
LAB_0040bb29:
          param_1->numberConstructionLotsValue = param_1->numberConstructionLotsValue + -1;
          pCVar1 = this->next;
          this->prev->next = pCVar1;
          this->next->prev = this->prev;
          (**(code **)this->_padding_)(1);
        }
        else {
          fVar2 = BaseItem::y((BaseItem *)this);
          fVar3 = BaseItem::ySize((BaseItem *)this);
          if (fVar2 - fVar3 * ram0x0056e808 < _DAT_0056e80c) goto LAB_0040bb29;
          fVar2 = BaseItem::x((BaseItem *)this);
          fVar3 = BaseItem::xSize((BaseItem *)this);
          if ((float)(param_1->mapXSizeValue + -1) < fVar2 - fVar3 * _DAT_0056e810)
          goto LAB_0040bb29;
          fVar2 = BaseItem::y((BaseItem *)this);
          fVar3 = BaseItem::ySize((BaseItem *)this);
          if ((float)(param_1->mapYSizeValue + -1) < fVar2 - fVar3 * _DAT_0056e810)
          goto LAB_0040bb29;
          pCVar1 = this->next;
        }
        this = pCVar1;
        if (pCVar1 == &param_1->constructionLots) {
          return;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040bb6f
// Address: 0040bb6f
float10 __fastcall FUN_0040bb6f(int param_1)
{
  return (float10)*(float *)(param_1 + 0x2fc);
}

// --------------------------------------------------

