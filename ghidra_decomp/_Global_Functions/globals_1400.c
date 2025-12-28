// GLOBAL FUNCTIONS PART 1400
// Function: FUN_00431dcc
// Address: 00431dcc
// XREFS: None
undefined4 __fastcall FUN_00431dcc(int param_1)
{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  uVar1 = 0;
  piVar3 = (int *)(*(int *)(param_1 + 0x114) + 0x14);
  do {
    if (*piVar3 != 0) {
      iVar4 = uVar1 * 0x1c;
      DAT_0062cf34 = *(undefined4 *)(*(int *)(param_1 + 0x114) + 0xc + iVar4);
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x114) + iVar4);
      *puVar2 = 0;
      puVar2[1] = 0;
      *(undefined1 *)(puVar2 + 2) = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x114) + 0xc + iVar4) = 0;
      return DAT_0062cf34;
    }
    uVar1 = uVar1 + 1;
    piVar3 = piVar3 + 7;
  } while (uVar1 <= *(uint *)(param_1 + 4));
  return 0;
}

// --------------------------------------------------

// Function: FUN_00431e34
// Address: 00431e34
// XREFS: None
char * __thiscall FUN_00431e34(RGE_Communications_Queue *param_1,uint param_2)
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  MsgQueue *pMVar5;
  int iVar6;
  uint uStack_4;
  
  uVar3 = 0xffffffff;
  uVar4 = 0;
  uStack_4 = 0xffffffff;
  iVar6 = 0;
  do {
    piVar2 = (int *)((int)&param_1->Queue->Code + iVar6);
    if ((*piVar2 != 0) && (piVar2[5] != 0)) {
      if ((uint)piVar2[1] < param_2) {
        RGE_Communications_Queue::TestShowQueue(param_1);
      }
      uVar1 = *(uint *)((int)&param_1->Queue->Code + iVar6);
      if ((uVar1 < uVar3) && (*(uint *)((int)&param_1->Queue->ExecTurn + iVar6) == param_2)) {
        uVar3 = uVar1;
        uStack_4 = uVar4;
      }
    }
    uVar4 = uVar4 + 1;
    iVar6 = iVar6 + 0x1c;
  } while (uVar4 <= param_1->HighQueueDepth);
  if (uStack_4 == 0xffffffff) {
    return (char *)0x0;
  }
  DAT_0062cf38 = param_1->Queue[uStack_4].msgptr;
  param_1->Queue[uStack_4].msgptr = (char *)0x0;
  pMVar5 = param_1->Queue + uStack_4;
  pMVar5->Code = 0;
  pMVar5->ExecTurn = 0;
  pMVar5->SeqNo = '\0';
  pMVar5->From = 0;
  pMVar5->Size = 0;
  pMVar5->ControlCommand = 0;
  return DAT_0062cf38;
}

// --------------------------------------------------

// Function: FUN_00431f01
// Address: 00431f01
// XREFS: None
byte __thiscall FUN_00431f01(int param_1,int param_2)
{
  byte bVar1;
  
  if (param_2 != *(int *)(param_1 + 0x10c)) {
    *(int *)(param_1 + 0x10c) = param_2;
    *(undefined1 *)(param_1 + 0x110) = 1;
    return 1;
  }
  bVar1 = *(char *)(param_1 + 0x110) + 1;
  *(byte *)(param_1 + 0x110) = bVar1;
  return -(bVar1 != 0xff) & bVar1;
}

// --------------------------------------------------

// Function: FUN_00431f4a
// Address: 00431f4a
// XREFS: None
void FUN_00431f4a(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00431f51
// Address: 00431f51
// XREFS: None
void __fastcall FUN_00431f51(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[3] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00431f79
// Address: 00431f79
// XREFS: None
void __fastcall FUN_00431f79(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  if ((void *)param_1[3] != (void *)0x0) {
    operator_delete((void *)param_1[3]);
  }
  param_1[3] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00431fad
// Address: 00431fad
// XREFS: None
// [HELPER] s_: ""
int __fastcall FUN_00431fad(int param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  
  *(undefined4 *)(param_1 + 0x2580) = 0;
  iVar5 = 100;
  puVar4 = (undefined4 *)(param_1 + 0x5c);
  do {
    uVar2 = 0xffffffff;
    pcVar6 = s_;
    do {
      pcVar7 = pcVar6;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar6 = pcVar7 + -uVar2;
    pcVar7 = (char *)(puVar4 + -0x17);
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    iVar5 = iVar5 + -1;
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    puVar4[-3] = 0;
    *puVar4 = 0;
    puVar4[-1] = 0;
    puVar4[-2] = 0;
    puVar4 = puVar4 + 0x18;
    if (iVar5 == 0) {
      _DirectPlayEnumerateA_8(DPEnumCallback,param_1);
      return param_1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00432021
// Address: 00432021
// XREFS: None
void FUN_00432021(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00432031
// Address: 00432031
// XREFS: None
undefined4 __fastcall FUN_00432031(int param_1)
{
  return *(undefined4 *)(param_1 + 0x2580);
}

// --------------------------------------------------

// Function: FUN_00432047
// Address: 00432047
// XREFS: None
void __fastcall FUN_00432047(int param_1)
{
  *(int *)(param_1 + 0x2580) = *(int *)(param_1 + 0x2580) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0043205e
// Address: 0043205e
// XREFS: None
int __thiscall FUN_0043205e(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 <= *(int *)(param_1 + 0x2580))) {
    return param_2 * 0x60 + param_1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004320b9
// Address: 004320b9
// XREFS: None
void __thiscall FUN_004320b9(int param_1,undefined4 *param_2,int param_3)
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_3 * 0x60 + 0x50 + param_1);
  *param_2 = *puVar1;
  param_2[1] = puVar1[1];
  param_2[2] = puVar1[2];
  param_2[3] = puVar1[3];
  return;
}

// --------------------------------------------------

// Function: FUN_004320ef
// Address: 004320ef
// XREFS: None
void __thiscall FUN_004320ef(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 <= *(int *)(param_1 + 0x2580))) {
    *(undefined4 *)(param_2 * 0x60 + 0x50 + param_1) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00432111
// Address: 00432111
// XREFS: None
undefined4 __thiscall FUN_00432111(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 <= *(int *)(param_1 + 0x2580))) {
    return *(undefined4 *)(param_1 + 0x5c + param_2 * 0x60);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00432142
// Address: 00432142
// XREFS: None
void __thiscall FUN_00432142(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 <= *(int *)(param_1 + 0x2580))) {
    *(undefined4 *)(param_2 * 0x60 + 0x5c + param_1) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00432171
// Address: 00432171
// XREFS: None
undefined4
FUN_00432171(_GUID *param_1,char *param_2,undefined4 param_3,undefined4 param_4,
            TCommunications_Services *param_5)
{
  TCommunications_Services *this;
  int iVar1;
  int iVar2;
  
  this = param_5;
  iVar1 = TCommunications_Services::GetServiceCount(param_5);
  TCommunications_Services::SetServiceName(this,iVar1,param_2);
  TCommunications_Services::EnumServiceGUID(this,iVar1,param_1);
  iVar2 = _DirectPlayCreate_12(param_1,&param_5,0);
  if (iVar2 == 0) {
    TCommunications_Services::SetServiceActive(this,iVar1,1);
    (**(code **)(*(int *)param_5->Service[0].Name + 8))(param_5);
    TCommunications_Services::IncServiceCount(this);
    return 1;
  }
  TCommunications_Services::SetServiceActive(this,iVar1,0);
  TCommunications_Services::IncServiceCount(this);
  return 1;
}

// --------------------------------------------------

// Function: DPEnumCallback
// Address: 00432180
// XREFS: TCommunications_Services
/* int __stdcall DPEnumCallback(struct _GUID *,char *,unsigned long,unsigned long,void *) */

int DPEnumCallback(_GUID *param_1,char *param_2,ulong param_3,ulong param_4,void *param_5)
{
  void *this;
  int iVar1;
  int iVar2;
  
  this = param_5;
  iVar1 = TCommunications_Services::GetServiceCount((TCommunications_Services *)param_5);
  TCommunications_Services::SetServiceName((TCommunications_Services *)this,iVar1,param_2);
  TCommunications_Services::EnumServiceGUID((TCommunications_Services *)this,iVar1,param_1);
  iVar2 = _DirectPlayCreate_12(param_1,&param_5,0);
  if (iVar2 == 0) {
    TCommunications_Services::SetServiceActive((TCommunications_Services *)this,iVar1,1);
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*param_5 + 8))(param_5);
    TCommunications_Services::IncServiceCount((TCommunications_Services *)this);
    return 1;
  }
  TCommunications_Services::SetServiceActive((TCommunications_Services *)this,iVar1,0);
  TCommunications_Services::IncServiceCount((TCommunications_Services *)this);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004321fd
// Address: 004321fd
// XREFS: None
TCommunications_Sessions * __thiscall
FUN_004321fd(TCommunications_Sessions *param_1,TCommunications_Handler *param_2)
{
  DAT_0062cf68 = param_2;
  glpSERV = TCommunications_Handler::GetDPInterface(param_2);
  ServGUID.Data1 = (DAT_0062cf68->ServiceGUID).Data1;
  ServGUID.Data2 = (DAT_0062cf68->ServiceGUID).Data2;
  ServGUID.Data3 = (DAT_0062cf68->ServiceGUID).Data3;
  ServGUID.Data4._0_4_ = *(undefined4 *)(DAT_0062cf68->ServiceGUID).Data4;
  ServGUID.Data4._4_4_ = *(undefined4 *)((DAT_0062cf68->ServiceGUID).Data4 + 4);
  ApplicationGUID.Data1 = (DAT_0062cf68->ApplicationGUID).Data1;
  ApplicationGUID.Data2 = (DAT_0062cf68->ApplicationGUID).Data2;
  ApplicationGUID.Data3 = (DAT_0062cf68->ApplicationGUID).Data3;
  ApplicationGUID.Data4._0_4_ = *(undefined4 *)(DAT_0062cf68->ApplicationGUID).Data4;
  ApplicationGUID.Data4._4_4_ = *(undefined4 *)((DAT_0062cf68->ApplicationGUID).Data4 + 4);
  param_1->SessionCount = 0;
  TCommunications_Sessions::EraseInformation(param_1);
  TCommunications_Sessions::Refresh(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00432286
// Address: 00432286
// XREFS: None
void FUN_00432286(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00432291
// Address: 00432291
// XREFS: None
void __fastcall FUN_00432291(undefined4 *param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = 0;
  puVar2 = param_1 + 1;
  for (iVar1 = 0x115e6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004322b7
// Address: 004322b7
// XREFS: None
undefined4 __fastcall FUN_004322b7(undefined4 *param_1)
{
  return *param_1;
}

// --------------------------------------------------

// Function: FUN_004322c3
// Address: 004322c3
// XREFS: None
int * __thiscall FUN_004322c3(int *param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 <= *param_1)) {
    return param_1 + param_2 * 0x8e + 1;
  }
  return (int *)0x0;
}

// --------------------------------------------------

// Function: FUN_00432313
// Address: 00432313
// XREFS: None
int __thiscall FUN_00432313(int *param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 <= *param_1)) {
    return param_1[param_2 * 0x8e + 0x89];
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00432343
// Address: 00432343
// XREFS: None
int * __thiscall FUN_00432343(int *param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 <= *param_1)) {
    return param_1 + param_2 * 0x8e + 0x85;
  }
  return (int *)0x0;
}

// --------------------------------------------------

// Function: FUN_00432373
// Address: 00432373
// XREFS: None
void __fastcall FUN_00432373(int *param_1)
{
  *param_1 = *param_1 + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00432386
// Address: 00432386
// XREFS: None
undefined4 __thiscall
FUN_00432386(TCommunications_Sessions *param_1,ulong param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,ulong param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,ulong param_10,ulong param_11,char *param_12,char *param_13,
            ulong param_14,ulong param_15,ulong param_16,ulong param_17)
{
  _GUID *p_Var1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  SEs *pSVar6;
  char *pcVar7;
  
  p_Var1 = &param_1->Session[param_1->SessionCount].AppGUID;
  p_Var1->Data1 = param_6;
  p_Var1->Data2 = (undefined2)param_7;
  p_Var1->Data3 = param_7._2_2_;
  *(undefined4 *)p_Var1->Data4 = param_8;
  *(undefined4 *)(p_Var1->Data4 + 4) = param_9;
  p_Var1 = &param_1->Session[param_1->SessionCount].SessGUID;
  p_Var1->Data1 = param_2;
  p_Var1->Data2 = (undefined2)param_3;
  p_Var1->Data3 = param_3._2_2_;
  *(undefined4 *)p_Var1->Data4 = param_4;
  *(undefined4 *)(p_Var1->Data4 + 4) = param_5;
  param_1->Session[param_1->SessionCount].MaxPlayers = param_10;
  param_1->Session[param_1->SessionCount].CurrentPlayers = param_11;
  param_1->Session[param_1->SessionCount].User1 = param_14;
  param_1->Session[param_1->SessionCount].User1 = param_15;
  param_1->Session[param_1->SessionCount].User1 = param_16;
  param_1->Session[param_1->SessionCount].User1 = param_17;
  if (param_12 != (char *)0x0) {
    uVar3 = 0xffffffff;
    do {
      pcVar5 = param_12;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar5 = param_12 + 1;
      cVar2 = *param_12;
      param_12 = pcVar5;
    } while (cVar2 != '\0');
    uVar3 = ~uVar3;
    pcVar5 = pcVar5 + -uVar3;
    pSVar6 = param_1->Session + param_1->SessionCount;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pSVar6->Name = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pSVar6 = (SEs *)(pSVar6->Name + 4);
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      pSVar6->Name[0] = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pSVar6 = (SEs *)(pSVar6->Name + 1);
    }
  }
  if (param_13 != (char *)0x0) {
    uVar3 = 0xffffffff;
    do {
      pcVar5 = param_13;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar5 = param_13 + 1;
      cVar2 = *param_13;
      param_13 = pcVar5;
    } while (cVar2 != '\0');
    uVar3 = ~uVar3;
    pcVar5 = pcVar5 + -uVar3;
    pcVar7 = param_1->Session[param_1->SessionCount].Password;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
  }
  TCommunications_Sessions::IncSessionCount(param_1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004324e6
// Address: 004324e6
// XREFS: None
void __fastcall FUN_004324e6(TCommunications_Sessions *param_1)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 auStack_50 [6];
  ulong uStack_38;
  ushort uStack_34;
  ushort uStack_32;
  uchar auStack_30 [4];
  uchar auStack_2c [44];
  
  TCommunications_Sessions::EraseInformation(param_1);
  puVar2 = auStack_50;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  uStack_38 = ApplicationGUID.Data1;
  auStack_2c[0] = ApplicationGUID.Data4[4];
  auStack_2c[1] = ApplicationGUID.Data4[5];
  auStack_2c[2] = ApplicationGUID.Data4[6];
  auStack_2c[3] = ApplicationGUID.Data4[7];
  auStack_30[0] = ApplicationGUID.Data4[0];
  auStack_30[1] = ApplicationGUID.Data4[1];
  auStack_30[2] = ApplicationGUID.Data4[2];
  auStack_30[3] = ApplicationGUID.Data4[3];
  uStack_34 = ApplicationGUID.Data2;
  uStack_32 = ApplicationGUID.Data3;
  auStack_50[0] = 0x50;
  (**(code **)((int)*glpSERV + 0x34))(glpSERV,auStack_50,0,EnumSessionCallback,param_1,1);
  return;
}

// --------------------------------------------------

// Function: FUN_00432557
// Address: 00432557
// XREFS: None
undefined4
FUN_00432557(int param_1,undefined4 param_2,byte param_3,TCommunications_Sessions *param_4)
{
  if ((param_3 & 1) != 0) {
    return 0;
  }
  TCommunications_Sessions::AddSession
            (param_4,*(_GUID *)(param_1 + 8),*(_GUID *)(param_1 + 0x18),*(ulong *)(param_1 + 0x28),
             *(ulong *)(param_1 + 0x2c),*(char **)(param_1 + 0x30),*(char **)(param_1 + 0x34),
             *(ulong *)(param_1 + 0x40),*(ulong *)(param_1 + 0x44),*(ulong *)(param_1 + 0x48),
             *(ulong *)(param_1 + 0x4c));
  return 1;
}

// --------------------------------------------------

// Function: EnumSessionCallback
// Address: 00432560
// XREFS: Refresh
/* int __stdcall EnumSessionCallback(struct DPSESSIONDESC2 *,unsigned long *,unsigned long,void *)
    */

int EnumSessionCallback(DPSESSIONDESC2 *param_1,ulong *param_2,ulong param_3,void *param_4)
{
  if ((param_3 & 1) != 0) {
    return 0;
  }
  TCommunications_Sessions::AddSession
            ((TCommunications_Sessions *)param_4,param_1->guidInstance,param_1->guidApplication,
             param_1->dwMaxPlayers,param_1->dwCurrentPlayers,(param_1->field6_0x30).lpszSessionNameA
             ,(param_1->field7_0x34).lpszPasswordA,param_1->dwUser1,param_1->dwUser2,
             param_1->dwUser3,param_1->dwUser4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004325df
// Address: 004325df
// XREFS: None
undefined4 FUN_004325df(int *param_1,int *param_2)
{
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) &&
     (param_1[3] == param_2[3])) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0043261e
// Address: 0043261e
// XREFS: None
int __thiscall FUN_0043261e(int param_1,undefined4 param_2)
{
  undefined4 *puVar1;
  RGE_TimeSinceLastCall *pRVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cf06;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = 10;
  *(undefined4 *)(param_1 + 0x108) = param_2;
  *(undefined4 *)(param_1 + 300) = 0x5a;
  *(undefined4 *)(param_1 + 0x218) = 0x5a;
  *(undefined4 *)(param_1 + 0x11c) = 10;
  *(undefined4 *)(param_1 + 0x214) = 10;
  *(undefined4 *)(param_1 + 0x118) = 1;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x224) = 0;
  *(undefined4 *)(param_1 + 0x238) = 0;
  *(undefined4 *)(param_1 + 0x23c) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x128) = 500;
  *(undefined4 *)(param_1 + 0x228) = 0;
  *(undefined4 *)(param_1 + 0x22c) = 0;
  *(undefined4 *)(param_1 + 0x230) = 0;
  *(undefined4 *)(param_1 + 0x234) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  puVar4 = (undefined2 *)(param_1 + 0x1a8);
  puVar1 = (undefined4 *)(param_1 + 0x16c);
  do {
    puVar1[-10] = 0x1e;
    *puVar1 = 0;
    *puVar4 = 0;
    puVar1[0x14] = 0;
    puVar1[0x1e] = 0;
    puVar4 = puVar4 + 1;
    puVar1 = puVar1 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined4 *)(param_1 + 0x20c) = 500;
  pRVar2 = (RGE_TimeSinceLastCall *)operator_new(0x2b4);
  uStack_4 = 0;
  if (pRVar2 == (RGE_TimeSinceLastCall *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = RGE_TimeSinceLastCall::RGE_TimeSinceLastCall(pRVar2);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x104) = uVar3;
  pRVar2 = (RGE_TimeSinceLastCall *)operator_new(0x2b4);
  uStack_4 = 1;
  if (pRVar2 == (RGE_TimeSinceLastCall *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = RGE_TimeSinceLastCall::RGE_TimeSinceLastCall(pRVar2);
  }
  *(undefined4 *)(param_1 + 0x100) = uVar3;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00432772
// Address: 00432772
// XREFS: None
void __fastcall FUN_00432772(int param_1)
{
  RGE_TimeSinceLastCall *pRVar1;
  
  pRVar1 = *(RGE_TimeSinceLastCall **)(param_1 + 0x104);
  if (pRVar1 != (RGE_TimeSinceLastCall *)0x0) {
    RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = *(RGE_TimeSinceLastCall **)(param_1 + 0x100);
  if (pRVar1 != (RGE_TimeSinceLastCall *)0x0) {
    RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall(pRVar1);
    operator_delete(pRVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004327bb
// Address: 004327bb
// XREFS: None
void __thiscall FUN_004327bb(int param_1,uint param_2,uint param_3,uint param_4)
{
  if ((param_2 != 0) && (param_2 < 10)) {
    *(uint *)(param_1 + 0x1bc + param_2 * 4) = param_3 & 0xff;
    *(uint *)(param_1 + 0x1e4 + param_2 * 4) = (param_4 & 0xff) * 10;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004327f6
// Address: 004327f6
// XREFS: None
void __thiscall FUN_004327f6(int param_1,uint param_2,uint param_3)
{
  if ((param_2 != 0) && (param_2 < 10)) {
    if (param_3 < 0x1e) {
      param_3 = 0x1e;
    }
    if (6000 < param_3) {
      param_3 = 6000;
    }
    *(uint *)(param_1 + 0x144 + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00432832
// Address: 00432832
// XREFS: None
void __thiscall FUN_00432832(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  if (*(int *)(param_1 + 0x140) == 0) {
    *(undefined4 *)(param_1 + 0x120) = param_2;
    *(undefined4 *)(param_1 + 0x130) = param_3;
    *(undefined4 *)(param_1 + 0x140) = param_4;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043286b
// Address: 0043286b
// XREFS: None
void __thiscall FUN_0043286b(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x118) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0043287d
// Address: 0043287d
// XREFS: None
undefined4 __fastcall FUN_0043287d(int param_1)
{
  return *(undefined4 *)(param_1 + 300);
}

// --------------------------------------------------

// Function: FUN_00432887
// Address: 00432887
// XREFS: None
undefined4 __fastcall FUN_00432887(int param_1)
{
  return *(undefined4 *)(param_1 + 0x238);
}

// --------------------------------------------------

// Function: FUN_00432897
// Address: 00432897
// XREFS: None
undefined4 __fastcall FUN_00432897(int param_1)
{
  *(undefined4 *)(param_1 + 0x23c) = 1;
  return *(undefined4 *)(param_1 + 300);
}

// --------------------------------------------------

// Function: FUN_004328b1
// Address: 004328b1
// XREFS: None
undefined4 __fastcall FUN_004328b1(int param_1)
{
  return *(undefined4 *)(param_1 + 0x124);
}

// --------------------------------------------------

// Function: FUN_004328c7
// Address: 004328c7
// XREFS: None
void __fastcall FUN_004328c7(int param_1)
{
  *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004328de
// Address: 004328de
// XREFS: None
void __fastcall FUN_004328de(int param_1)
{
  if ((*(uint *)(param_1 + 0x140) != 0) &&
     (*(undefined4 *)(param_1 + 0x224) = 0,
     *(uint *)(param_1 + 0x140) <= *(uint *)(*(int *)(param_1 + 0x108) + 0x10c8))) {
    *(undefined4 *)(param_1 + 0x140) = 0;
    *(int *)(param_1 + 0x238) = *(int *)(param_1 + 0x238) + 1;
    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x120);
    *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x130);
    *(undefined4 *)(param_1 + 0x120) = 0;
    *(undefined4 *)(param_1 + 0x130) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043293a
// Address: 0043293a
// XREFS: None
void __fastcall FUN_0043293a(RGE_Communications_Speed *param_1)
{
  RGE_TimeSinceLastCall::Set(param_1->TurnTSLC);
  param_1->DroppedFramesTurn = 0;
  RGE_Communications_Speed::AdjustLocalSpeed(param_1);
  param_1->TotalBufferFramesRemaining = param_1->CurrentBufferFrames;
  return;
}

// --------------------------------------------------

// Function: FUN_0043296d
// Address: 0043296d
// XREFS: None
int __thiscall FUN_0043296d(int param_1,uint param_2)
{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x23c) == 0) {
    RGE_TimeSinceLastCall::Skip(*(RGE_TimeSinceLastCall **)(param_1 + 0x104));
  }
  else {
    RGE_TimeSinceLastCall::Set(*(RGE_TimeSinceLastCall **)(param_1 + 0x104));
  }
  *(undefined4 *)(param_1 + 0x23c) = 0;
  if (*(int *)(param_1 + 0x124) == 0) {
    *(undefined4 *)(param_1 + 0x23c) = 0;
    return 0;
  }
  uVar1 = RGE_TimeSinceLastCall::Get(*(RGE_TimeSinceLastCall **)(param_1 + 0x100));
  *(ulong *)(param_1 + 0x228) = uVar1;
  iVar2 = TCommunications_Handler::AllPlayersAcknowledged
                    (*(TCommunications_Handler **)(param_1 + 0x108));
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x220) + *(int *)(param_1 + 0x124);
  }
  uVar3 = (*(int *)(param_1 + 0x11c) - *(int *)(param_1 + 0x124)) * *(int *)(param_1 + 300);
  *(uint *)(param_1 + 0x22c) = uVar3;
  if ((uint)(*(int *)(param_1 + 0x134) + *(int *)(param_1 + 0x228)) < uVar3) {
    if (6 < param_2) {
      *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) + 1;
      *(int *)(param_1 + 0x234) = *(int *)(param_1 + 0x234) + 1;
    }
    *(undefined4 *)(param_1 + 0x23c) = 0;
    return 0;
  }
  *(undefined4 *)(param_1 + 0x23c) = 1;
  *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + -1;
  return *(int *)(param_1 + 300);
}

// --------------------------------------------------

// Function: FUN_00432a64
// Address: 00432a64
// XREFS: None
void __fastcall FUN_00432a64(int param_1)
{
  RGE_TimeSinceLastCall::Skip(*(RGE_TimeSinceLastCall **)(param_1 + 0x104));
  *(undefined4 *)(param_1 + 0x23c) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00432a8a
// Address: 00432a8a
// XREFS: None
uint __fastcall FUN_00432a8a(int param_1)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar2 = 0;
  uVar3 = 1;
  puVar4 = (uint *)(param_1 + 0x148);
  do {
    iVar1 = TCommunications_Handler::IsPlayerHuman
                      (*(TCommunications_Handler **)(param_1 + 0x108),uVar3);
    if ((iVar1 != 0) && (uVar2 <= *puVar4)) {
      uVar2 = *puVar4;
    }
    uVar3 = uVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (uVar3 < 10);
  *(uint *)(param_1 + 0x20c) = uVar2;
  uVar2 = (uVar2 + 5) / 10;
  if (uVar2 < 2) {
    uVar2 = 1;
  }
  if (0xfe < uVar2) {
    uVar2 = 0xff;
  }
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_00432af4
// Address: 00432af4
// XREFS: None
undefined4 __thiscall FUN_00432af4(int param_1,uint param_2)
{
  if ((param_2 != 0) && (param_2 < 10)) {
    return *(undefined4 *)(param_1 + 0x144 + param_2 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00432b1d
// Address: 00432b1d
// XREFS: None
// [HELPER] s_P_d__d_: "P%d=%d "
char * __fastcall FUN_00432b1d(char *param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char acStack_18 [24];
  
  uVar3 = 0xffffffff;
  pcVar7 = &s_Latency>_;
  do {
    pcVar9 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  uVar5 = 1;
  pcVar7 = pcVar9 + -uVar3;
  pcVar9 = param_1;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  pcVar6 = param_1 + 0x148;
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  do {
    iVar2 = TCommunications_Handler::IsPlayerHuman
                      (*(TCommunications_Handler **)(param_1 + 0x108),uVar5);
    if (iVar2 != 0) {
      sprintf(acStack_18,s_P_d__d_,uVar5,*(undefined4 *)pcVar6);
      uVar3 = 0xffffffff;
      pcVar7 = acStack_18;
      do {
        pcVar9 = pcVar7;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar2 = -1;
      pcVar7 = param_1;
      do {
        pcVar8 = pcVar7;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar3;
      pcVar9 = pcVar8 + -1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
    }
    uVar5 = uVar5 + 1;
    pcVar6 = pcVar6 + 4;
    if (9 < uVar5) {
      return param_1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00432bc7
// Address: 00432bc7
// XREFS: None
// [HELPER] s_MeOptimal__Buf__3d_Gran__3d__Tar: "MeOptimal: Buf=%3d Gran=%3d  Target FPS=%3d  My expect turn=%4dms"
undefined4 __fastcall FUN_00432bc7(RGE_Communications_Speed *param_1)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = RGE_Communications_Speed::GetRecommendedBufferFrames(param_1);
  uVar2 = RGE_Communications_Speed::GetRecommendedBufferGranularity(param_1);
  sprintf(0x62d170,s_MeOptimal__Buf__3d_Gran__3d__Tar,uVar1,uVar2,(int)(1000 / (longlong)(int)uVar2)
          ,uVar2 * uVar1);
  return 0x62d170;
}

// --------------------------------------------------

// Function: FUN_00432c0d
// Address: 00432c0d
// XREFS: None
// [HELPER] s_Buf__3d____3d___Gran__3dms___tur: "Buf=%3d / %3d * Gran=%3dms = turn %4dms   %s"
Alignment * __thiscall FUN_00432c0d(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  if ((-1 < param_2) && (param_2 < 10)) {
    iVar1 = *(int *)(param_1 + 300);
    iVar2 = *(int *)(param_1 + 0x11c);
    pcVar3 = RGE_TimeSinceLastCall::GetHiLoInfo(*(RGE_TimeSinceLastCall **)(param_1 + 0x104),0x32);
    sprintf(&DAT_0062cf70,s_Buf__3d____3d___Gran__3dms___tur,*(undefined4 *)(param_1 + 0x124),iVar2,
            iVar1,iVar2 * iVar1,pcVar3);
    return &DAT_0062cf70;
  }
  return (Alignment *)0x0;
}

// --------------------------------------------------

// Function: FUN_00432d8a
// Address: 00432d8a
// XREFS: None
void __fastcall FUN_00432d8a(int param_1)
{
  RGE_TimeSinceLastCall::GetAvg(*(RGE_TimeSinceLastCall **)(param_1 + 0x104),0x32);
  return;
}

// --------------------------------------------------

// Function: FUN_00432d9e
// Address: 00432d9e
// XREFS: None
void __fastcall FUN_00432d9e(int param_1)
{
  uint uVar1;
  
  uVar1 = RGE_TimeSinceLastCall::GetAvg(*(RGE_TimeSinceLastCall **)(param_1 + 0x104),0x32);
  *(uint *)(param_1 + 0x218) = uVar1;
  if (0x96 < uVar1) {
    uVar1 = 0x96;
  }
  *(uint *)(param_1 + 0x218) = uVar1;
  if (uVar1 < 10) {
    uVar1 = 10;
  }
  *(uint *)(param_1 + 0x218) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_00432dda
// Address: 00432dda
// XREFS: None
undefined4 __thiscall
FUN_00432dda(RGE_Communications_Speed *param_1,uint *param_2,uint *param_3,int param_4)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong *puVar8;
  uint uVar9;
  
  iVar1 = TCommunications_Handler::IsHost(param_1->Comm);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_1->NextLatencyChangeTurn != 0) {
    return 0;
  }
  uVar2 = param_1->Comm->current_turn + (uint)(param_1->Comm->PlayerOptions).CommandTurnIncrement;
  if (uVar2 < 0x14) {
    return 0;
  }
  uVar4 = param_1->LastAdjusted + 1;
  param_1->LastAdjusted = uVar4;
  if (uVar4 < 5) {
    return 0;
  }
  uVar4 = 10;
  uVar7 = 0x1e;
  uVar9 = 1;
  puVar8 = param_1->PlayerHighLatencyMsec;
  do {
    puVar8 = puVar8 + 1;
    iVar1 = TCommunications_Handler::IsPlayerHuman(param_1->Comm,uVar9);
    if (iVar1 != 0) {
      if (uVar4 <= puVar8[-10]) {
        uVar4 = puVar8[-10];
      }
      if (uVar7 <= *puVar8) {
        uVar7 = *puVar8;
      }
    }
    uVar9 = uVar9 + 1;
  } while ((int)uVar9 < 10);
  uVar4 = ((uVar4 + 5) / 10) * 10;
  if (0x96 < uVar4) {
    uVar4 = 0x96;
  }
  uVar9 = param_1->CurrentBufferGranularity;
  uVar5 = (int)(uVar4 - uVar9) >> 0x1f;
  if ((uVar4 - uVar9 ^ uVar5) - uVar5 < 10) {
    uVar4 = uVar9;
  }
  uVar7 = uVar7 / uVar4 + 2;
  if (0x13 < uVar7) {
    uVar7 = 0x14;
  }
  if (uVar7 < 5) {
    uVar7 = 4;
  }
  if (uVar4 * uVar7 < 0xfa) {
    uVar7 = (int)(0xfa / (ulonglong)uVar4) + 1;
  }
  uVar5 = param_1->CurrentBufferFrames;
  uVar3 = uVar4 * uVar7 - uVar5 * uVar9;
  uVar6 = (int)uVar3 >> 0x1f;
  uVar6 = (uVar3 ^ uVar6) - uVar6;
  if (uVar6 < 0xb) {
    return 0;
  }
  if (((uVar4 * uVar7 < uVar5 * uVar9) && (100 < uVar6)) && (4 < uVar5)) {
    uVar7 = uVar5 - 1;
  }
  *param_2 = uVar4;
  *param_3 = uVar7;
  if ((param_4 != 0) && (param_1->SpeedControlEnabled != 0)) {
    RGE_Communications_Speed::SetFutureSpeedChange(param_1,uVar7,uVar4,uVar2);
    TCommunications_Handler::SendSpeedChange(param_1->Comm,uVar7,uVar4);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00432fa7
// Address: 00432fa7
// XREFS: None
// [HELPER] s_Speed_set_V1__d: "Speed set V1=%d"
void FUN_00432fa7(undefined4 param_1)
{
  TDebuggingLog::Log(L,(char *)L,s_Speed_set_V1__d,param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00432fcc
// Address: 00432fcc
// XREFS: None
// [HELPER] s_Speed_set_V2__d: "Speed set V2=%d"
void FUN_00432fcc(undefined4 param_1)
{
  TDebuggingLog::Log(L,(char *)L,s_Speed_set_V2__d,param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00432fec
// Address: 00432fec
// XREFS: None
// [HELPER] s_Check_turn____d: "Check turn = %d"
undefined4 * __thiscall FUN_00432fec(undefined4 *param_1,undefined4 param_2)
{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = param_2;
  param_1[1] = 1000;
  param_1[2] = 10;
  TDebuggingLog::Log(L,(char *)L,s_Check_turn____d,10);
  param_1[3] = 1;
  param_1[9] = 1;
  param_1[7] = 1;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  puVar1 = param_1 + 0xe;
  iVar2 = 0x37;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[-2] = 0;
    puVar1 = puVar1 + 9;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043306d
// Address: 0043306d
// XREFS: None
void __fastcall FUN_0043306d(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0x38);
  iVar2 = 0x37;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[-2] = 0;
    puVar1 = puVar1 + 9;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0043309b
// Address: 0043309b
// XREFS: None
int __thiscall
FUN_0043309b(RGE_Communications_Synchronize *param_1,uint param_2,ulong param_3,ulong param_4,
            ulong param_5,long param_6,long param_7,long param_8,long param_9,long param_10)
{
  int iVar1;
  uint uVar2;
  
  if (param_1->DoChecksums == 0) {
    return 0;
  }
  uVar2 = param_1->Offset + 1;
  param_1->Offset = uVar2;
  if (0x35 < uVar2) {
    param_1->Offset = 0;
  }
  param_1->Check[param_1->Offset].WTime = param_3;
  param_1->Check[param_1->Offset].WTurn = param_4;
  param_1->Check[param_1->Offset].cs1 = param_6;
  param_1->Check[param_1->Offset].cs2 = param_7;
  param_1->Check[param_1->Offset].cs3 = param_8;
  param_1->Check[param_1->Offset].cs4 = param_9;
  param_1->Check[param_1->Offset].cs5 = param_10;
  param_1->Check[param_1->Offset].Random = param_5;
  param_1->Check[param_1->Offset].PlayerNo = param_2;
  param_1->NewData = 1;
  iVar1 = RGE_Communications_Synchronize::ValidateChecksums
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     param_10);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00433171
// Address: 00433171
// XREFS: None
// [HELPER] s_P__d_In_Sync___Wtime__d_WTurn__d: "P#%d In Sync @ Wtime=%d WTurn=%d Wrand=%d Wchksum=%d"
int __thiscall
FUN_00433171(RGE_Communications_Synchronize *param_1,uint param_2,ulong param_3,ulong param_4,
            TDebuggingLog *param_5,int param_6,int param_7,int param_8,int param_9,int param_10)
{
  bool bVar1;
  ulong *puVar2;
  uint uVar3;
  
  bVar1 = false;
  if (param_1->NewData == 0) {
    return param_1->LastResult;
  }
  param_1->NewData = 0;
  param_1->LastResult = 0;
  uVar3 = 1;
  puVar2 = &param_1->Check[1].WTime;
  do {
    if (puVar2[1] == param_4) {
      if (*puVar2 != param_3) {
        bVar1 = true;
        goto LAB_004331bb;
      }
LAB_004331bf:
      if ((((puVar2[2] != param_6) || (puVar2[3] != param_7)) || (puVar2[4] != param_8)) ||
         (((puVar2[5] != param_9 || (puVar2[6] != param_10)) ||
          ((TDebuggingLog *)puVar2[7] != param_5)))) {
        bVar1 = true;
      }
    }
    else {
LAB_004331bb:
      if (*puVar2 == param_3) goto LAB_004331bf;
    }
    if (bVar1) {
      RGE_Communications_Synchronize::LogChecksums
                (param_1,param_2,param_3,param_4,param_6,param_7,param_8,param_9,param_10,
                 (ulong)param_5);
      TCommunications_Handler::NotifyWindowParam(param_1->Comm,COMM_SYNC_ERROR,param_4);
      param_1->LastResult = 0;
      return 0;
    }
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 9;
    if (0x36 < uVar3) {
      TDebuggingLog::Log(param_5,(char *)L,s_P__d_In_Sync___Wtime__d_WTurn__d,param_2,param_3,
                         param_4,param_5,param_6);
      param_1->LastResult = 1;
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00433283
// Address: 00433283
// XREFS: None
// [HELPER] s_Checksum__T__d_wt__d___rand__d__: "Checksum: T#%d wt=%d   rand=%d  csum=%d"
// [HELPER] s_Sync_check_at_turn___d: "Sync check at turn #%d"
// [HELPER] s_Worldtime__ld_Random__d_Checksum: "Worldtime=%ld Random=%d Checksum=%d"
undefined4 __thiscall FUN_00433283(RGE_Communications_Synchronize *param_1,uint param_2)
{
  RGE_Base_Game *pRVar1;
  ulong uVar2;
  RGE_Game_World *pRVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  int iVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lStack_10c;
  long lStack_108;
  long lStack_104;
  char acStack_100 [256];
  
  uVar7 = 0;
  if (param_1->DoChecksums == 0) {
    return 0;
  }
  if (rge_base_game->world != (RGE_Game_World *)0x0) {
    uVar7 = rge_base_game->world->world_time;
  }
  if (param_2 < param_1->CheckTurn) {
    return 0;
  }
  TDebuggingLog::Log(L,(char *)L,s_Sync_check_at_turn___d,param_1->CheckTurn);
  param_1->CheckTurn = param_1->CheckTurn + 4;
  lStack_108 = 0;
  lStack_10c = 0;
  lStack_104 = 0;
  RGE_Base_Game::GetWorldChecksums(rge_base_game,&lStack_108,&lStack_10c,&lStack_104);
  if (param_1->SendChatMsgs != 0) {
    sprintf(acStack_100,s_Worldtime__ld_Random__d_Checksum,uVar7,param_1->LastWorldRandom,
            param_1->GameWorldChecksum);
    TCommunications_Handler::SendChatMsgAll(param_1->Comm,acStack_100);
  }
  DAT_0062d230 = RGE_Visible_Map::checksumUnifiedVisible((*rge_base_game->world->players)->visible);
  iVar8 = 1;
  pRVar3 = rge_base_game->world;
  if (1 < pRVar3->player_num) {
    do {
      lVar4 = RGE_Visible_Map::checksumVisible(pRVar3->players[iVar8]->visible);
      pRVar1 = rge_base_game;
      (&DAT_0062d208)[iVar8] = lVar4;
      iVar8 = iVar8 + 1;
      pRVar3 = pRVar1->world;
    } while (iVar8 < pRVar3->player_num);
  }
  uVar2 = DAT_0062d230;
  lVar5 = PathingSystem::checksum(&pathSystem);
  uVar11 = param_1->LastWorldRandom;
  uVar9 = uVar7;
  uVar10 = param_2;
  uVar12 = uVar2;
  lVar4 = lStack_108;
  lVar13 = lStack_10c;
  lVar14 = lStack_104;
  lVar15 = lVar5;
  uVar6 = TCommunications_Handler::WhoAmI(param_1->Comm);
  RGE_Communications_Synchronize::Add
            (param_1,uVar6,uVar9,uVar10,uVar11,uVar12,lVar4,lVar13,lVar14,lVar15);
  TCommunications_Handler::SendChecksumMessage
            (param_1->Comm,uVar7,param_1->LastWorldRandom,uVar2,lStack_108,lStack_10c,lStack_104,
             lVar5);
  TDebuggingLog::Log((TDebuggingLog *)param_1->LastWorldRandom,(char *)L,
                     s_Checksum__T__d_wt__d___rand__d__,param_2,uVar7,
                     (TDebuggingLog *)param_1->LastWorldRandom,param_1->GameWorldChecksum);
  TDebuggingLog::FlushLog(L);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0043345a
// Address: 0043345a
// XREFS: None
// [HELPER] s_Adding___P__d__WTime__d__Turn__d: "Adding:  P#%d  WTime=%d  Turn=%d Cs1=%d  Cs2=%d  Cs3=%d  Cs4=%d  Cs5=%d  Rand=%d"
// [HELPER] s_C__aoesync_txt: "C:\aoesync.txt"
// [HELPER] s_PLAYER___s: "PLAYER: %s"
// [HELPER] s_P__d_CSum__d_: "P#%d CSum=%d "
// [HELPER] s_Player_Checksum_information_: "Player Checksum information:"
// [HELPER] s_Plr__Wrldtime_CommTurn_Random_WC: "Plr: Wrldtime CommTurn Random WChecksum CksumNew Position Actions  Unif. Visible"
// [HELPER] s_VISIBLE_Checksum____d: "VISIBLE Checksum = %d"
// [HELPER] s__: "}"
// [HELPER] s___: "]\n"
// [HELPER] s____2d____8d___8d___6d___8d___8d_: " %.2d: %.8d %.8d %.6d %.8d %.8d %.8d %.8d %.8d "
// [HELPER] s______: "---- "
// [HELPER] s____end_of_log: "...end of log"
// [HELPER] s_wt: "wt"
void __thiscall
FUN_0043345a(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10)
{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  long lVar5;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  char *pcVar10;
  undefined4 *puStack_20c;
  char acStack_204 [516];
  
  iVar2 = fopen(s_C__aoesync_txt,s_wt);
  sprintf(acStack_204,s_Adding___P__d__WTime__d__Turn__d,param_2,param_3,param_4,param_5,param_6,
          param_7,param_8,param_9,param_10);
  TDebuggingLog::Log(this,(char *)L,acStack_204);
  if (iVar2 != 0) {
    fputs(acStack_204,iVar2);
    fputs(&s__,iVar2);
  }
  sprintf(acStack_204,s_Plr__Wrldtime_CommTurn_Random_WC);
  TDebuggingLog::Log(L,(char *)L,acStack_204);
  if (iVar2 != 0) {
    fputs(acStack_204,iVar2);
    fputs(&s__,iVar2);
  }
  piVar9 = param_1 + 0x16;
  puStack_20c = (undefined4 *)0x35;
  do {
    sprintf(acStack_204,s____2d____8d___8d___6d___8d___8d_,piVar9[-1],*piVar9,piVar9[1],piVar9[7],
            piVar9[2],piVar9[3],piVar9[4],piVar9[5],piVar9[6]);
    TDebuggingLog::Log((TDebuggingLog *)acStack_204,(char *)L,(TDebuggingLog *)acStack_204);
    if (iVar2 != 0) {
      fputs(acStack_204,iVar2);
      fputs(&s__,iVar2);
    }
    if ((piVar9[1] == param_4) && (*piVar9 != param_3)) {
      sprintf(acStack_204,s______>__WORLD_TIME_IS_OUT_OF_SYN,param_3,*piVar9,param_4);
      TDebuggingLog::Log(this_00,(char *)L,acStack_204);
      if (iVar2 != 0) {
        fputs(acStack_204,iVar2);
        fputs(&s__,iVar2);
      }
    }
    if (*piVar9 == param_3) {
      if (piVar9[7] != param_10) {
        sprintf(acStack_204,s______>__MISMATCHED_RANDOM____d_s,param_10,piVar9[7]);
        TDebuggingLog::Log(L,(char *)L,acStack_204);
        if (iVar2 != 0) {
          fputs(acStack_204,iVar2);
          fputs(&s__,iVar2);
        }
      }
      if (piVar9[2] != param_5) {
        sprintf(acStack_204,s______>__MISMATCHED_Unified_Visib);
        TDebuggingLog::Log(this_01,(char *)L,acStack_204);
        if (iVar2 != 0) {
          fputs(acStack_204,iVar2);
          fputs(&s__,iVar2);
        }
      }
      if (piVar9[3] != param_6) {
        sprintf(acStack_204,s______>__MISMATCHED_CHECKSUM___Ne);
        TDebuggingLog::Log((TDebuggingLog *)acStack_204,(char *)L,(TDebuggingLog *)acStack_204);
        if (iVar2 != 0) {
          fputs(acStack_204,iVar2);
          fputs(&s__,iVar2);
        }
      }
      if (piVar9[4] != param_7) {
        sprintf(acStack_204,s______>__MISMATCHED__Position);
        TDebuggingLog::Log(L,(char *)L,acStack_204);
        if (iVar2 != 0) {
          fputs(acStack_204,iVar2);
          fputs(&s__,iVar2);
        }
      }
      if (piVar9[5] != param_8) {
        sprintf(acStack_204,s______>__MISMATCHED___Action);
        TDebuggingLog::Log(this_02,(char *)L,acStack_204);
        if (iVar2 != 0) {
          fputs(acStack_204,iVar2);
          fputs(&s__,iVar2);
        }
      }
      if (piVar9[6] != param_9) {
        sprintf(acStack_204,s______>__MISMATCHED___Obstruction);
        TDebuggingLog::Log((TDebuggingLog *)acStack_204,(char *)L,(TDebuggingLog *)acStack_204);
        if (iVar2 != 0) {
          fputs(acStack_204,iVar2);
          fputs(&s__,iVar2);
        }
      }
    }
    piVar9 = piVar9 + 9;
    puStack_20c = (undefined4 *)((int)puStack_20c + -1);
  } while (puStack_20c != (undefined4 *)0x0);
  uVar6 = 0xffffffff;
  pcVar4 = &s_Player_Checksum_information_;
  do {
    pcVar10 = pcVar4;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar4 = pcVar10 + -uVar6;
  pcVar10 = acStack_204;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar10 = pcVar10 + 1;
  }
  TDebuggingLog::Log((TDebuggingLog *)acStack_204,(char *)L,(TDebuggingLog *)acStack_204);
  if (iVar2 != 0) {
    fputs(acStack_204,iVar2);
    fputs(&s__,iVar2);
  }
  uVar6 = 0;
  puStack_20c = &DAT_0062d208;
  do {
    iVar3 = TCommunications_Handler::IsPlayerHuman((TCommunications_Handler *)*param_1,uVar6);
    if (iVar3 == 0) {
      iVar3 = TCommunications_Handler::IsPlayerComputer((TCommunications_Handler *)*param_1,uVar6);
      if (iVar3 != 0) goto LAB_004338b6;
    }
    else {
LAB_004338b6:
      uVar7 = 0xffffffff;
      pcVar4 = (char *)&s___;
      do {
        pcVar10 = pcVar4;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      pcVar4 = pcVar10 + -uVar7;
      pcVar10 = acStack_204;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar10 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar10 = pcVar10 + 1;
      }
      TDebuggingLog::Log((TDebuggingLog *)acStack_204,(char *)L,(TDebuggingLog *)acStack_204);
      if (iVar2 != 0) {
        fputs(acStack_204,iVar2);
        fputs(&s__,iVar2);
      }
      pcVar4 = TCommunications_Handler::GetPlayerName((TCommunications_Handler *)*param_1,uVar6);
      sprintf(acStack_204,s_PLAYER___s,pcVar4);
      TDebuggingLog::Log(L,(char *)L,acStack_204);
      if (iVar2 != 0) {
        fputs(acStack_204,iVar2);
        fputs(&s__,iVar2);
      }
      lVar5 = RGE_Base_Game::GetChecksum(rge_base_game,uVar6);
      sprintf(acStack_204,s_P__d_CSum__d_,uVar6,lVar5);
      TDebuggingLog::Log((TDebuggingLog *)acStack_204,(char *)L,(TDebuggingLog *)acStack_204);
      if (iVar2 != 0) {
        fputs(acStack_204,iVar2);
        fputs(&s__,iVar2);
      }
      sprintf(acStack_204,s_VISIBLE_Checksum____d,*puStack_20c);
      TDebuggingLog::Log((TDebuggingLog *)acStack_204,(char *)L,(TDebuggingLog *)acStack_204);
      if (iVar2 != 0) {
        fputs(acStack_204,iVar2);
        fputs(&s__,iVar2);
      }
    }
    uVar6 = uVar6 + 1;
    puStack_20c = puStack_20c + 1;
  } while (puStack_20c < &UNK_0062d210.field_0x1c);
  uVar6 = 0xffffffff;
  pcVar4 = &s____end_of_log;
  do {
    pcVar10 = pcVar4;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar4 = pcVar10 + -uVar6;
  pcVar10 = acStack_204;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar10 = pcVar10 + 1;
  }
  TDebuggingLog::Log((TDebuggingLog *)acStack_204,(char *)L,(TDebuggingLog *)acStack_204);
  if (iVar2 != 0) {
    fputs(acStack_204,iVar2);
    fputs(&s__,iVar2);
  }
  fclose(iVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_00433a8b
// Address: 00433a8b
// XREFS: None
void __thiscall FUN_00433a8b(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00433a9a
// Address: 00433a9a
// XREFS: None
void __thiscall FUN_00433a9a(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00433aaa
// Address: 00433aaa
// XREFS: None
void __thiscall FUN_00433aaa(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00433aba
// Address: 00433aba
// XREFS: None
void __thiscall FUN_00433aba(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00433aca
// Address: 00433aca
// XREFS: None
// [HELPER] s_OUTOFSYNC__DIDN_T_FIND_MY_VALUES: "OUTOFSYNC: DIDN'T FIND MY VALUES"
// [HELPER] s_OUTOFSYNC___d_diff___d__d__d__d_: "OUTOFSYNC: %d diff: %d %d %d %d %d %d"
// [HELPER] s_OUTOFSYNC___d_same___d__d__d__d_: "OUTOFSYNC: %d same: %d %d %d %d %d %d"
// [HELPER] s_OUTOFSYNC__my_values___d__d__d__: "OUTOFSYNC: my values: %d %d %d %d %d %d"
// [HELPER] s_OUTOFSYNC__numplayers__d__diff__: "OUTOFSYNC: numplayers=%d, diff=%d, same=%d"
// [HELPER] s_OUTOFSYNC__return_not_out: "OUTOFSYNC: return not out"
// [HELPER] s_OUTOFSYNC__return_not_out_2: "OUTOFSYNC: return not out 2"
// [HELPER] s_OUTOFSYNC__return_out: "OUTOFSYNC: return out"
undefined4 __thiscall FUN_00433aca(undefined4 *param_1,int param_2,int param_3)
{
  bool bVar1;
  int *piVar2;
  TDebuggingLog *this;
  TDebuggingLog *pTVar3;
  TDebuggingLog *this_00;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  char *pcVar8;
  TDebuggingLog *pTStack_28;
  TDebuggingLog *pTStack_24;
  TDebuggingLog *pTStack_20;
  TDebuggingLog *pTStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_8;
  
  iVar4 = 0;
  piVar7 = param_1 + 0x17;
  iStack_14 = 0;
  iStack_18 = 0;
  bVar1 = false;
  iVar5 = 0;
  pTStack_20 = (TDebuggingLog *)0x0;
  pTStack_24 = (TDebuggingLog *)0x0;
  pTStack_28 = (TDebuggingLog *)0x0;
  pTStack_1c = (TDebuggingLog *)0x0;
  iStack_8 = 0;
  iStack_10 = 0;
  piVar2 = piVar7;
  pTVar3 = (TDebuggingLog *)0x1;
  while ((piVar2[-2] != param_2 || (*piVar2 != param_3))) {
    this = (TDebuggingLog *)((int)&pTVar3->Timestamp + 1);
    piVar2 = piVar2 + 9;
    pTVar3 = this;
    if ((TDebuggingLog *)0x36 < this) {
LAB_00433b69:
      if (!bVar1) {
        TDebuggingLog::Log(this,(char *)L,s_OUTOFSYNC__DIDN_T_FIND_MY_VALUES);
        return 0;
      }
      TDebuggingLog::Log(pTStack_20,(char *)L,s_OUTOFSYNC__my_values___d__d__d__,iVar4,iVar5,
                         pTStack_20,pTStack_24,pTStack_28,pTStack_1c);
      uVar6 = 1;
      do {
        if ((piVar7[-2] != param_2) && (*piVar7 == param_3)) {
          if (((iVar4 == piVar7[-1]) &&
              (((iVar5 == piVar7[1] && (pTStack_20 == (TDebuggingLog *)piVar7[2])) &&
               (pTStack_24 == (TDebuggingLog *)piVar7[3])))) &&
             (((pTStack_28 == (TDebuggingLog *)piVar7[4] &&
               (pTStack_1c == (TDebuggingLog *)piVar7[5])) && (iStack_8 == piVar7[6])))) {
            iStack_18 = iStack_18 + 1;
            pcVar8 = s_OUTOFSYNC___d_same___d__d__d__d_;
            pTVar3 = pTStack_28;
          }
          else {
            iStack_14 = iStack_14 + 1;
            pcVar8 = s_OUTOFSYNC___d_diff___d__d__d__d_;
            pTVar3 = pTStack_24;
          }
          TDebuggingLog::Log(pTVar3,(char *)L,pcVar8,uVar6,iVar4,iVar5,pTStack_20,pTStack_24,
                             pTStack_28,pTStack_1c);
        }
        uVar6 = uVar6 + 1;
        piVar7 = piVar7 + 9;
      } while (uVar6 < 0x37);
      uVar6 = 1;
      do {
        iVar4 = TCommunications_Handler::GetPlayerHumanity
                          ((TCommunications_Handler *)*param_1,uVar6);
        if (iVar4 == 2) {
          iStack_10 = iStack_10 + 1;
        }
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < 10);
      TDebuggingLog::Log(L,(char *)L,s_OUTOFSYNC__numplayers__d__diff__,iStack_10,iStack_14,
                         iStack_18);
      if (iStack_10 + -1 <= iStack_18 + iStack_14) {
        if (iStack_14 <= iStack_18) {
          TDebuggingLog::Log(this_00,(char *)L,s_OUTOFSYNC__return_not_out_2);
          return 0;
        }
        TDebuggingLog::Log(L,(char *)L,s_OUTOFSYNC__return_out);
        return 1;
      }
      TDebuggingLog::Log(this_00,(char *)L,s_OUTOFSYNC__return_not_out);
      return 0;
    }
  }
  bVar1 = true;
  pTStack_20 = (TDebuggingLog *)param_1[(int)pTVar3 * 9 + 0x10];
  pTStack_24 = (TDebuggingLog *)param_1[(int)pTVar3 * 9 + 0x11];
  iVar4 = param_1[(int)pTVar3 * 9 + 0xd];
  pTStack_28 = (TDebuggingLog *)param_1[(int)((int)&pTVar3->Timestamp + 2) * 9];
  this = (TDebuggingLog *)param_1[(int)pTVar3 * 9 + 0x13];
  iVar5 = param_1[(int)pTVar3 * 9 + 0xf];
  iStack_8 = param_1[(int)pTVar3 * 9 + 0x14];
  pTStack_1c = this;
  goto LAB_00433b69;
}

// --------------------------------------------------

// Function: FUN_00433d32
// Address: 00433d32
// XREFS: None
void __thiscall FUN_00433d32(undefined4 *param_1,undefined4 param_2,undefined4 param_3)
{
  param_1[1] = param_2;
  param_1[5] = param_3;
  *param_1 = &RGE_Command::_vftable_;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00433d61
// Address: 00433d61
// XREFS: None
RGE_Command * __thiscall FUN_00433d61(RGE_Command *param_1,byte param_2)
{
  RGE_Command::~RGE_Command(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00433d8e
// Address: 00433d8e
// XREFS: None
void __fastcall FUN_00433d8e(undefined4 *param_1)
{
  *param_1 = &RGE_Command::_vftable_;
  param_1[1] = 0;
  param_1[5] = 0;
  if (param_1[2] != 0) {
    free(param_1[2]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00433daf
// Address: 00433daf
// XREFS: None
void __thiscall FUN_00433daf(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00433dba
// Address: 00433dba
// XREFS: None
RGE_Static_Object * __thiscall FUN_00433dba(int param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  
  if (param_2 == -1) {
    return (RGE_Static_Object *)0x0;
  }
  pRVar1 = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),param_2);
  return pRVar1;
}

// --------------------------------------------------

// Function: FUN_00433dda
// Address: 00433dda
// XREFS: None
void __fastcall FUN_00433dda(int *param_1)
{
  code *pcVar1;
  void *pvVar2;
  
  if (((TCommunications_Handler *)param_1[5] != (TCommunications_Handler *)0x0) &&
     (pvVar2 = TCommunications_Handler::get_command((TCommunications_Handler *)param_1[5]),
     pvVar2 != (void *)0x0)) {
    pcVar1 = *(code **)(*param_1 + 8);
    do {
      (*pcVar1)(pvVar2);
      if (pvVar2 != (void *)0x0) {
        operator_delete(pvVar2);
      }
      pvVar2 = TCommunications_Handler::get_command((TCommunications_Handler *)param_1[5]);
    } while (pvVar2 != (void *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004342d6
// Address: 004342d6
// XREFS: None
void __thiscall FUN_004342d6(RGE_Command *param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  uint uVar2;
  long *plVar3;
  
  plVar3 = (long *)(param_2 + 2);
  for (uVar2 = (uint)*(byte *)(param_2 + 1); uVar2 != 0; uVar2 = uVar2 - 1) {
    pRVar1 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plVar3);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 400))();
    }
    plVar3 = plVar3 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043431b
// Address: 0043431b
// XREFS: None
void __thiscall FUN_0043431b(RGE_Command *param_1,int param_2)
{
  int iVar1;
  RGE_Static_Object *this;
  uint uVar2;
  int unaff_EBX;
  long *plVar3;
  int iVar4;
  int unaff_retaddr;
  int iStack_18;
  long *plStack_14;
  
  uVar2 = (uint)*(byte *)(param_2 + 8);
  RGE_Command::get_obj(param_1,(RGE_Obj_Info)*(long *)(param_2 + 4));
  iStack_18 = 0;
  plStack_14 = (long *)(param_2 + 0x14);
  if (uVar2 != 0) {
    do {
      this = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plStack_14);
      if (this != (RGE_Static_Object *)0x0) {
        RGE_Static_Object::removeAllFromPathingGroup(this);
        iVar1 = this->_padding_;
        (**(code **)(iVar1 + 300))(1);
        iVar4 = 0;
        plVar3 = (long *)(param_2 + 0x14);
        do {
          if (iVar4 != unaff_EBX) {
            RGE_Static_Object::addToPathingGroup(this,*plVar3);
          }
          iVar4 = iVar4 + 1;
          plVar3 = plVar3 + 1;
        } while (iVar4 < (int)plStack_14);
        (**(code **)(iVar1 + 0xa0))
                  (uVar2,*(undefined4 *)(unaff_retaddr + 0xc),*(undefined4 *)(unaff_retaddr + 0x10),
                   0);
      }
      iStack_18 = iStack_18 + 1;
      plStack_14 = plStack_14 + 1;
    } while (iStack_18 < (int)uVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004343f8
// Address: 004343f8
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004343f8(RGE_Command *param_1,int param_2)
{
  byte bVar1;
  RGE_Master_Static_Object *pRVar2;
  RGE_Static_Object *pRVar3;
  RGE_Static_Object *pRVar4;
  UnitAIModule *pUVar5;
  float fVar6;
  int *piVar7;
  long *plVar8;
  float fVar9;
  long *plVar10;
  long *plVar11;
  int unaff_retaddr;
  float fVar12;
  long lVar13;
  int iVar14;
  float fVar15;
  float fStack_28;
  float fStack_24;
  float fStack_1c;
  float fStack_18;
  long *plStack_10;
  int *piStack_c;
  
  bVar1 = *(byte *)(param_2 + 8);
  fVar6 = (float)(uint)bVar1;
  plVar10 = (long *)(param_2 + 0x14);
  pRVar3 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*(long *)(param_2 + 4));
  if (1 < bVar1) {
    fStack_28 = 10000.0;
    fStack_24 = 0.0;
    piStack_c = (int *)0x461c4000;
    plStack_10 = (long *)0x0;
    fStack_1c = 0.0;
    fStack_18 = 0.0;
    plVar8 = plVar10;
    for (fVar9 = fVar6; fVar9 != 0.0; fVar9 = (float)((int)fVar9 + -1)) {
      pRVar4 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plVar8);
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        if (fStack_28 <= pRVar4->world_x) {
          if (fStack_24 < pRVar4->world_x) {
            fStack_24 = pRVar4->world_x;
          }
        }
        else {
          fStack_28 = pRVar4->world_x;
        }
        if ((float)piStack_c <= pRVar4->world_y) {
          if ((float)plStack_10 < pRVar4->world_y) {
            plStack_10 = (long *)pRVar4->world_y;
          }
        }
        else {
          piStack_c = (int *)pRVar4->world_y;
        }
        fStack_1c = fStack_1c + pRVar4->world_x;
        fStack_18 = fStack_18 + pRVar4->world_y;
      }
      plVar8 = plVar8 + 1;
    }
    if ((fStack_24 - fStack_28 <= (float)_DAT_0056f4d8) &&
       ((float)plStack_10 - (float)piStack_c <= (float)_DAT_0056f4d8)) {
      piStack_c = (int *)0x0;
      fVar9 = fStack_18 / (float)(int)fVar6;
      plStack_10 = plVar10;
      if (fVar6 == 0.0) {
        return;
      }
      do {
        pRVar4 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plStack_10);
        if (pRVar4 != (RGE_Static_Object *)0x0) {
          RGE_Static_Object::removeAllFromPathingGroup(pRVar4);
          iVar14 = pRVar4->_padding_;
          (**(code **)(iVar14 + 300))(1);
          plVar10 = (long *)0x0;
          piVar7 = piStack_c;
          do {
            if (plVar10 != plStack_10) {
              RGE_Static_Object::addToPathingGroup(pRVar4,*piVar7);
            }
            plVar10 = (long *)((int)plVar10 + 1);
            piVar7 = piVar7 + 1;
          } while ((int)plVar10 < (int)fStack_24);
          fStack_28 = (pRVar4->world_x - fVar6) + *(float *)(unaff_retaddr + 0xc);
          fVar15 = (pRVar4->world_y - fStack_1c / (float)(int)fVar6) +
                   *(float *)(unaff_retaddr + 0x10);
          if ((float)_DAT_0056f4e0 <= fStack_28) {
            fVar12 = (float)pRVar4->owner->world->map->map_width;
            if (fVar12 <= fStack_28) {
              fStack_28 = fVar12 - _DAT_0056f4e8;
            }
          }
          else {
            fStack_28 = 1.0;
          }
          if ((float)_DAT_0056f4e0 <= fVar15) {
            fVar12 = (float)pRVar4->owner->world->map->map_height;
            if (fVar12 <= fVar15) {
              fVar15 = fVar12 - _DAT_0056f4e8;
            }
          }
          else {
            fVar15 = 1.0;
          }
          if ((fVar9 == 0.0) ||
             ((fVar12 = fVar9, *(float *)(*(int *)((int)fVar9 + 8) + 0x30) <= (float)_DAT_0056f4e0
              && (*(float *)(*(int *)((int)fVar9 + 8) + 0x34) <= (float)_DAT_0056f4e0)))) {
            fVar12 = 0.0;
          }
          (**(code **)(iVar14 + 0x9c))(fVar12,fStack_28,fVar15,0);
          pUVar5 = RGE_Static_Object::unitAI(pRVar4);
          if (pUVar5 != (UnitAIModule *)0x0) {
            iVar14 = 0x2c6;
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            UnitAIModule::setCurrentOrder(pUVar5,iVar14);
            iVar14 = 0x262;
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            UnitAIModule::setCurrentAction(pUVar5,iVar14);
            if ((pRVar3 == (RGE_Static_Object *)0x0) ||
               ((pRVar2 = pRVar3->master_obj, pRVar2->radius_x <= (float)_DAT_0056f4e0 &&
                (pRVar2->radius_y <= (float)_DAT_0056f4e0)))) {
              iVar14 = -1;
              lVar13 = -1;
            }
            else {
              iVar14 = (int)pRVar2->object_group;
              lVar13 = pRVar3->id;
            }
            fVar12 = 0.0;
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            UnitAIModule::setCurrentTarget(pUVar5,lVar13,iVar14,fStack_28,fVar15,fVar12);
          }
        }
        piStack_c = (int *)((int)piStack_c + 1);
        plStack_10 = plStack_10 + 1;
      } while ((int)piStack_c < (int)fVar6);
      return;
    }
  }
  piStack_c = (int *)0x0;
  plStack_10 = plVar10;
  if (fVar6 != 0.0) {
    do {
      pRVar4 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plStack_10);
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        RGE_Static_Object::removeAllFromPathingGroup(pRVar4);
        iVar14 = pRVar4->_padding_;
        (**(code **)(iVar14 + 300))(1);
        plVar11 = (long *)0x0;
        plVar8 = plVar10;
        do {
          if (plVar11 != plStack_10) {
            RGE_Static_Object::addToPathingGroup(pRVar4,*plVar8);
          }
          plVar11 = (long *)((int)plVar11 + 1);
          plVar8 = plVar8 + 1;
        } while ((int)plVar11 < (int)fStack_24);
        (**(code **)(iVar14 + 0x9c))
                  (fStack_18,*(undefined4 *)(unaff_retaddr + 0xc),
                   *(undefined4 *)(unaff_retaddr + 0x10),0);
        pUVar5 = RGE_Static_Object::unitAI(pRVar4);
        if (pUVar5 != (UnitAIModule *)0x0) {
          iVar14 = 0x2c6;
          pUVar5 = RGE_Static_Object::unitAI(pRVar4);
          UnitAIModule::setCurrentOrder(pUVar5,iVar14);
          iVar14 = 0x262;
          pUVar5 = RGE_Static_Object::unitAI(pRVar4);
          UnitAIModule::setCurrentAction(pUVar5,iVar14);
          if ((pRVar3 == (RGE_Static_Object *)0x0) ||
             ((pRVar2 = pRVar3->master_obj, pRVar2->radius_x <= (float)_DAT_0056f4e0 &&
              (pRVar2->radius_y <= (float)_DAT_0056f4e0)))) {
            fVar9 = *(float *)(param_2 + 0x10);
            fVar15 = *(float *)(param_2 + 0xc);
            iVar14 = -1;
            lVar13 = -1;
          }
          else {
            iVar14 = (int)pRVar2->object_group;
            fVar9 = *(float *)(param_2 + 0x10);
            fVar15 = *(float *)(param_2 + 0xc);
            lVar13 = pRVar3->id;
          }
          fVar12 = 0.0;
          pUVar5 = RGE_Static_Object::unitAI(pRVar4);
          UnitAIModule::setCurrentTarget(pUVar5,lVar13,iVar14,fVar15,fVar9,fVar12);
        }
      }
      piStack_c = (int *)((int)piStack_c + 1);
      plStack_10 = plStack_10 + 1;
    } while ((int)piStack_c < (int)fVar6);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004348a2
// Address: 004348a2
// XREFS: None
void __thiscall FUN_004348a2(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)*(byte *)(param_2 + 4) * 4);
  (**(code **)(**(int **)(*(int *)(iVar1 + 0x24) + *(short *)(param_2 + 2) * 4) + 0x18))
            (iVar1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),
             *(undefined4 *)(param_2 + 0x10));
  return;
}

// --------------------------------------------------

// Function: FUN_004348e5
// Address: 004348e5
// XREFS: None
void __thiscall FUN_004348e5(int param_1,int param_2)
{
  (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)*(byte *)(param_2 + 1) * 4)
              + 0x78))(*(undefined1 *)(param_2 + 2),*(undefined4 *)(param_2 + 4),0);
  return;
}

// --------------------------------------------------

// Function: FUN_00434918
// Address: 00434918
// XREFS: None
void __thiscall FUN_00434918(int param_1,int param_2)
{
  byte bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x40);
  piVar3 = *(int **)(iVar2 + (uint)*(byte *)(param_2 + 1) * 4);
  if (*(float *)(param_2 + 4) <= *(float *)(piVar3[0x14] + (uint)*(byte *)(param_2 + 3) * 4)) {
    (**(code **)(*piVar3 + 0x78))
              (CONCAT22((short)((uint)iVar2 >> 0x10),(ushort)*(byte *)(param_2 + 3)),
               -*(float *)(param_2 + 4),0);
    (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) +
                           (uint)*(byte *)(param_2 + 2) * 4) + 0x78))
              (CONCAT22((short)((uint)*(undefined4 *)(param_2 + 4) >> 0x10),
                        (ushort)*(byte *)(param_2 + 3)),*(undefined4 *)(param_2 + 4),0);
    iVar2 = rge_base_game->_padding_;
    uVar4 = __ftol();
    (**(code **)(iVar2 + 0x40))
              (7,*(undefined1 *)(param_2 + 1),*(undefined1 *)(param_2 + 2),
               *(undefined1 *)(param_2 + 3),uVar4);
    bVar1 = *(byte *)(param_2 + 2);
    iVar2 = **(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) + (uint)bVar1 * 4);
    uVar4 = __ftol(0);
    (**(code **)(iVar2 + 0xe8))
              (*(undefined1 *)(param_2 + 1),(uint)bVar1,0x20a,*(undefined1 *)(param_2 + 3),uVar4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004349f2
// Address: 004349f2
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004349f2(RGE_Command *param_1,int param_2)
{
  long *plVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  RGE_Static_Object *pRVar5;
  long *plVar6;
  int iVar7;
  int iVar8;
  long *plVar9;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  RGE_Static_Object *pRStack_18;
  int iStack_10;
  float fStack_4;
  
  iVar2 = *(int *)(param_2 + 4);
  plVar1 = (long *)(param_2 + 0xc);
  if (1 < iVar2) {
    iVar7 = 0;
    pRStack_18 = (RGE_Static_Object *)0x0;
    plVar9 = plVar1;
    if (0 < iVar2) {
      do {
        pRVar5 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plVar9);
        if ((pRVar5 != (RGE_Static_Object *)0x0) &&
           ((fVar3 = SQRT(pRVar5->world_y * pRVar5->world_y + pRVar5->world_x * pRVar5->world_x),
            iVar7 == 0 || (fVar3 < fStack_4)))) {
          pRStack_18 = pRVar5;
          fStack_4 = fVar3;
        }
        iVar7 = iVar7 + 1;
        plVar9 = plVar9 + 1;
      } while (iVar7 < iVar2);
    }
    fStack_28 = 1.0;
    fStack_2c = 1.0;
    bVar4 = false;
    switch(*(undefined4 *)(param_2 + 8)) {
    case 0:
      fStack_28 = 1.0;
      fStack_2c = 1.0;
      break;
    case 1:
    case 4:
    case 5:
      fStack_28 = 1.5;
      fStack_2c = 1.5;
      break;
    case 2:
    case 3:
      fStack_28 = 2.0;
      fStack_2c = 2.0;
    }
    iStack_10 = 0;
    plVar9 = plVar1;
    if (0 < iVar2) {
      do {
        pRVar5 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plVar9);
        if (pRVar5 != (RGE_Static_Object *)0x0) {
          RGE_Static_Object::removeAllFromPathingGroup(pRVar5);
          iVar7 = pRVar5->_padding_;
          (**(code **)(iVar7 + 300))(1);
          iVar8 = 0;
          plVar6 = plVar1;
          do {
            if (iVar8 != iStack_10) {
              RGE_Static_Object::addToPathingGroup(pRVar5,*plVar6);
            }
            iVar8 = iVar8 + 1;
            plVar6 = plVar6 + 1;
          } while (iVar8 < iVar2);
          if (pRVar5 != pRStack_18) {
            fStack_20 = pRStack_18->world_x;
            fStack_24 = pRStack_18->world_y;
            switch(*(undefined4 *)(param_2 + 8)) {
            case 0:
              fStack_20 = fStack_20 + fStack_28;
              fStack_28 = fStack_28 - _DAT_0056f4f4;
              fStack_24 = fStack_24 + fStack_2c;
              fStack_2c = fStack_2c - _DAT_0056f4f4;
              break;
            case 1:
              fStack_20 = fStack_20 + fStack_28;
              fStack_28 = fStack_28 - _DAT_0056f4f8;
              fStack_24 = fStack_24 - fStack_2c;
              fStack_2c = fStack_2c - _DAT_0056f4f8;
              break;
            case 2:
              fStack_20 = fStack_20 + fStack_28;
              fVar3 = _DAT_0056f4fc;
LAB_00434cc0:
              fStack_28 = fStack_28 - fVar3;
              break;
            case 3:
              fStack_24 = fStack_24 + fStack_2c;
              fStack_2c = fStack_2c - _DAT_0056f4fc;
              break;
            case 4:
              fStack_20 = fStack_20 + fStack_28;
              if (bVar4) {
LAB_00434c8e:
                fStack_24 = fStack_24 + fStack_2c;
                fStack_2c = fStack_2c - _DAT_0056f4f8;
                bVar4 = false;
                fVar3 = _DAT_0056f4f8;
                goto LAB_00434cc0;
              }
              fStack_24 = fStack_24 - fStack_2c;
              bVar4 = true;
              break;
            case 5:
              fStack_20 = fStack_20 - fStack_28;
              if (bVar4) goto LAB_00434c8e;
              fStack_24 = fStack_24 - fStack_2c;
              bVar4 = true;
            }
            (**(code **)(iVar7 + 0x9c))(0,fStack_20,fStack_24,0x3f800000);
          }
        }
        iStack_10 = iStack_10 + 1;
        plVar9 = plVar9 + 1;
      } while (iStack_10 < iVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00434d07
// Address: 00434d07
// XREFS: None
void __fastcall FUN_00434d07(int param_1,int param_2)
{
  char *pcVar1;
  undefined4 in_EAX;
  RGE_Static_Object *this;
  int iVar2;
  char *pcVar3;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  int in_stack_00000002;
  char *pcVar4;
  
  pcVar4 = (char *)(unaff_EDI + 1);
  iVar2 = CONCAT31((int3)((uint)(param_2 + -1) >> 8),(char)(param_2 + -1) * '\x02') + -3;
  iVar2 = CONCAT31((int3)((uint)iVar2 >> 8),(char)iVar2 * '\x02') + -1;
  pcVar3 = (char *)(CONCAT31((int3)((uint)iVar2 >> 8),(char)iVar2 * '\x02') + -1);
  *(char *)(unaff_ESI + 0x4b) = *(char *)(unaff_ESI + 0x4b) + (char)((uint)param_1 >> 8);
  *(char *)(unaff_EBX + -0x7ffbcae) = *(char *)(unaff_EBX + -0x7ffbcae) + (char)((uint)pcVar3 >> 8);
  *pcVar4 = *pcVar4 + (char)pcVar3;
  (&stack0x00000042)[param_1 * 2] = (&stack0x00000042)[param_1 * 2] + (char)((uint)in_EAX >> 8);
  *pcVar3 = *pcVar3 + (char)((uint)(unaff_EBX + 8) >> 8);
  pcVar1 = (char *)(CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX << 2) + -0x6f6f6f70);
  *pcVar1 = *pcVar1 + (char)pcVar3;
  this = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),*(int *)(in_stack_00000002 + 4));
  if (this != (RGE_Static_Object *)0x0) {
    RGE_Static_Object::removeAllFromPathingGroup(this);
    (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) +
                           (uint)*(byte *)(in_stack_00000002 + 1) * 4) + 0x34))
              (*(undefined1 *)(in_stack_00000002 + 2),*(undefined4 *)(in_stack_00000002 + 4),
               (int)*(short *)(in_stack_00000002 + 8),*(undefined4 *)(in_stack_00000002 + 0xc),
               *(undefined1 *)(in_stack_00000002 + 0x10),*(undefined4 *)(in_stack_00000002 + 0x14),
               *(undefined4 *)(in_stack_00000002 + 0x18),*(undefined4 *)(in_stack_00000002 + 0x1c),
               *(undefined4 *)(in_stack_00000002 + 0x20),*(undefined1 *)(in_stack_00000002 + 0x24),
               *(undefined1 *)(in_stack_00000002 + 0x25),*(undefined1 *)(in_stack_00000002 + 10),
               pcVar4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00434db2
// Address: 00434db2
// XREFS: None
void __thiscall FUN_00434db2(RGE_Command *param_1,float param_2)
{
  int iVar1;
  RGE_Static_Object *this;
  uint uVar2;
  long *plVar3;
  float fStack_c;
  float fStack_8;
  
  iVar1 = (int)param_2;
  plVar3 = (long *)((int)param_2 + 0x24);
  for (uVar2 = (uint)*(byte *)((int)param_2 + 3); uVar2 != 0; uVar2 = uVar2 - 1) {
    this = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plVar3);
    if (this != (RGE_Static_Object *)0x0) {
      fStack_8 = *(float *)(iVar1 + 0x10);
      if (fStack_8 == -1.0) {
        fStack_8 = this->world_x;
      }
      fStack_c = *(float *)(iVar1 + 0x14);
      if (fStack_c == -1.0) {
        fStack_c = this->world_y;
      }
      param_2 = *(float *)(iVar1 + 0x18);
      if (param_2 == -1.0) {
        param_2 = this->world_z;
      }
      RGE_Static_Object::removeAllFromPathingGroup(this);
      (**(code **)(param_1->world->players[*(byte *)(iVar1 + 1)]->_padding_ + 0x34))
                (*(undefined1 *)(iVar1 + 2),this->id,(int)*(short *)(iVar1 + 4),
                 *(undefined4 *)(iVar1 + 8),*(undefined1 *)(iVar1 + 0xc),fStack_8,fStack_c,param_2,
                 *(undefined4 *)(iVar1 + 0x1c),*(undefined1 *)(iVar1 + 0x20),
                 *(undefined1 *)(iVar1 + 0x21),*(undefined1 *)(iVar1 + 6));
    }
    plVar3 = plVar3 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00434eaf
// Address: 00434eaf
// XREFS: None
void __thiscall FUN_00434eaf(int param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar1 == 0) {
    (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) +
                           (uint)*(byte *)(param_2 + 1) * 4) + 8))(*(undefined1 *)(param_2 + 3));
  }
  else {
    iVar4 = 0;
    iVar1 = 0;
    iVar3 = 1;
    rge_base_game->resigned[*(byte *)(param_2 + 2)] = '\x01';
    do {
      uVar2 = RGE_Base_Game::playerID(rge_base_game,iVar3);
      if ((uVar2 == *(byte *)(param_2 + 1)) &&
         (iVar4 = iVar4 + 1, rge_base_game->resigned[iVar3] != '\0')) {
        iVar1 = iVar1 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 9);
    if (iVar4 == iVar1) {
      (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) +
                             (uint)*(byte *)(param_2 + 1) * 4) + 8))(*(undefined1 *)(param_2 + 3));
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00434f65
// Address: 00434f65
// XREFS: None
void __thiscall FUN_00434f65(int param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),*(int *)(param_2 + 4));
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) +
                           (uint)*(byte *)(param_2 + 1) * 4) + 0x48))
              (*(undefined4 *)(param_2 + 4),param_2 + 9,*(undefined1 *)(param_2 + 8));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00434fae
// Address: 00434fae
// XREFS: None
void __thiscall FUN_00434fae(RGE_Command *param_1,long *param_2)
{
  long *plVar1;
  RGE_Static_Object *pRVar2;
  uint uVar3;
  long *plVar4;
  
  plVar1 = param_2;
  plVar4 = param_2;
  for (uVar3 = (uint)*(byte *)((int)param_2 + 1); uVar3 != 0; uVar3 = uVar3 - 1) {
    plVar4 = plVar4 + 1;
    pRVar2 = RGE_Command::get_obj(param_1,(RGE_Obj_Info)*plVar4);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      param_2._0_3_ = (uint3)*(ushort *)((int)plVar1 + 2);
      (**(code **)(pRVar2->owner->_padding_ + 0x48))(pRVar2->id,&param_2,1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00435015
// Address: 00435015
// XREFS: None
void __thiscall FUN_00435015(int param_1,int param_2)
{
  RGE_Static_Object *this;
  
  this = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),*(int *)(param_2 + 4));
  if ((this != (RGE_Static_Object *)0x0) && (this->owner->id == (ushort)*(byte *)(param_2 + 1))) {
    RGE_Static_Object::commanderCreateGroup
              (this,(int *)(param_2 + 0xc),(uint)*(byte *)(param_2 + 0x70),*(int *)(param_2 + 4),
               *(float *)(param_2 + 8));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00435096
// Address: 00435096
// XREFS: None
void __thiscall FUN_00435096(int param_1,int param_2)
{
  RGE_Static_Object *this;
  
  this = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),*(int *)(param_2 + 4));
  if ((this != (RGE_Static_Object *)0x0) && (this->owner->id == (ushort)*(byte *)(param_2 + 1))) {
    RGE_Static_Object::commanderRemoveFromGroup(this,*(int *)(param_2 + 8));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004350d2
// Address: 004350d2
// XREFS: None
void __thiscall FUN_004350d2(int param_1,int param_2)
{
  RGE_Static_Object *this;
  
  this = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),*(int *)(param_2 + 4));
  if ((this != (RGE_Static_Object *)0x0) && (this->owner->id == (ushort)*(byte *)(param_2 + 1))) {
    RGE_Static_Object::commanderDestroyGroup(this);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043510e
// Address: 0043510e
// XREFS: None
uint __thiscall FUN_0043510e(int param_1,int param_2)
{
  int iVar1;
  short sVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 8);
  uVar3 = (uint)*(byte *)(param_2 + 8);
  piVar4 = (int *)(iVar1 + 0x14);
  if (uVar3 == *(byte *)(iVar1 + 8)) {
    sVar2 = __ftol();
    piVar4 = (int *)__ftol();
    if ((short)piVar4 == sVar2) {
      sVar2 = __ftol();
      piVar4 = (int *)__ftol();
      if (((short)piVar4 == sVar2) &&
         (piVar4 = *(int **)(param_2 + 4), *(int **)(iVar1 + 4) == piVar4)) {
        iVar5 = 0;
        if (uVar3 != 0) {
          piVar4 = (int *)(param_2 + 0x14);
          do {
            if (*piVar4 != *(int *)(((iVar1 + 0x14) - (param_2 + 0x14)) + (int)piVar4))
            goto LAB_0043519f;
            iVar5 = iVar5 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar5 < (int)uVar3);
        }
        return CONCAT31((int3)((uint)piVar4 >> 8),1);
      }
    }
  }
LAB_0043519f:
  return (uint)piVar4 & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_004351a9
// Address: 004351a9
// XREFS: None
uint __thiscall FUN_004351a9(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = (uint)*(byte *)(param_2 + 1);
  piVar1 = (int *)(*(int *)(param_1 + 8) + 2);
  if (uVar3 != *(byte *)(*(int *)(param_1 + 8) + 1)) {
    return 0;
  }
  iVar2 = 0;
  if (uVar3 != 0) {
    iVar4 = (param_2 + 2) - (int)piVar1;
    do {
      if (*(int *)(iVar4 + (int)piVar1) != *piVar1) {
        return (uint)piVar1 & 0xffffff00;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < (int)uVar3);
    return CONCAT31((int3)((uint)piVar1 >> 8),1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00435209
// Address: 00435209
// XREFS: None
undefined4 __thiscall FUN_00435209(RGE_Command *param_1,RGE_Command_Order *param_2)
{
  uchar uVar1;
  
  switch(param_2->command) {
  case '\0':
  case '\x02':
  case '\x03':
    uVar1 = RGE_Command::duplicate_check_command_order(param_1,param_2);
    if (uVar1 != '\0') {
      return 1;
    }
    break;
  case '\x01':
    uVar1 = RGE_Command::duplicate_check_command_stop(param_1,(RGE_Command_Stop *)param_2);
    if (uVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00435247
// Address: 00435247
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Command_cp: "C:\msdev\work\age1_x1\Command.cpp"
uchar __fastcall FUN_00435247(RGE_Command *param_1,int param_2,int param_3)
{
  char *pcVar1;
  uchar uVar2;
  char cVar4;
  uint in_EAX;
  ulong uVar3;
  int unaff_EBX;
  uchar *unaff_retaddr;
  
  *(char *)(unaff_EBX + 1) = *(char *)(unaff_EBX + 1) + (char)((uint)param_2 >> 8);
  cVar4 = (char)((in_EAX & 0xffffff52) >> 8);
  *(char *)(param_2 * 3) = *(char *)(param_2 * 3) + cVar4;
  *(char *)(param_2 * 3) = *(char *)(param_2 * 3) + cVar4;
  pcVar1 = (char *)((in_EAX & 0xffffff52) + 0x90909090);
  *pcVar1 = *pcVar1 + (char)param_2;
  if (((param_1->last_order != (uchar *)0x0) && (param_1->last_order_size == param_3)) &&
     (*param_1->last_order == *unaff_retaddr)) {
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Command_cp,0x497);
    if ((int)(uVar3 - param_1->last_order_time) < 500) {
      uVar2 = RGE_Command::close_check_for_duplicate_orders(param_1,unaff_retaddr);
      return uVar2;
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_004352b2
// Address: 004352b2
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Command_cp: "C:\msdev\work\age1_x1\Command.cpp"
void __thiscall FUN_004352b2(RGE_Command *param_1,uchar *param_2,long param_3)
{
  uchar uVar1;
  ulong uVar2;
  
  uVar1 = RGE_Command::check_for_duplicate_orders(param_1,param_2,param_3);
  if (uVar1 == '\0') {
    TCommunications_Handler::new_command(param_1->com_hand,param_2,param_3);
  }
  if (param_1->last_order != (uchar *)0x0) {
    free(param_1->last_order);
  }
  param_1->last_order = param_2;
  param_1->last_order_size = param_3;
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Command_cp,0x4ac);
  param_1->last_order_time = uVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_00435313
// Address: 00435313
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
FUN_00435313(RGE_Command *param_1,int *param_2,short param_3,int param_4,undefined4 param_5,
            undefined4 param_6)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = (int)param_3;
  iVar1 = iVar8 * 4 + 0x14;
  if ((param_2 != (int *)0x0) && (0 < param_3)) {
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 0x14);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar8) {
        iVar6 = (int)param_2 - (int)puVar4;
        iVar9 = iVar8;
        do {
          iVar2 = *(int *)(iVar6 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      if (param_4 == 0) {
        *(undefined4 *)(puVar3 + 4) = 0xffffffff;
      }
      else {
        *(undefined4 *)(puVar3 + 4) = *(undefined4 *)(param_4 + 4);
      }
      *puVar3 = 0;
      puVar3[8] = (char)param_3;
      *(undefined4 *)(puVar3 + 0xc) = param_5;
      *(undefined4 *)(puVar3 + 0x10) = param_6;
      if (param_4 == 0) {
        pcVar7 = s_X;
      }
      else {
        pcVar7 = *(char **)(*(int *)(param_4 + 8) + 8);
      }
      iVar9 = *param_2;
      if (iVar9 == 0) {
        pcVar5 = s_X;
        iVar9 = -1;
      }
      else {
        pcVar5 = *(char **)(*(int *)(iVar9 + 8) + 8);
        iVar9 = (int)*(short *)(*(int *)(iVar9 + 0xc) + 0x4a);
      }
      TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_ORDER__CNT__d_OW,iVar8,iVar9,pcVar5,pcVar7);
      RGE_Command::submit(param_1,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004354e8
// Address: 004354e8
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall FUN_004354e8(RGE_Command *param_1,undefined4 param_2,int *param_3,int param_4)
{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  RGE_Static_Object *pRVar4;
  char *pcVar5;
  int iVar6;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *this;
  int iVar7;
  
  if ((param_3 != (int *)0x0) && (0 < param_4)) {
    iVar1 = param_4 * 4 + 2;
    puVar2 = (undefined1 *)calloc(1,iVar1);
    puVar3 = (undefined4 *)(puVar2 + 2);
    if (puVar2 != (undefined1 *)0x0) {
      if (0 < param_4) {
        iVar6 = (int)param_3 - (int)puVar3;
        iVar7 = param_4;
        do {
          *puVar3 = *(undefined4 *)(iVar6 + (int)puVar3);
          puVar3 = puVar3 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      *puVar2 = 1;
      puVar2[1] = (char)param_4;
      pRVar4 = RGE_Game_World::object(param_1->world,*param_3);
      if (pRVar4 == (RGE_Static_Object *)0x0) {
        pcVar5 = s_X;
        this = extraout_ECX;
      }
      else {
        this = (TDebuggingLog *)pRVar4->master_obj;
        pcVar5 = (char *)this->LogToFile;
      }
      TDebuggingLog::Log(this,(char *)L,s_______>SEND_CMD_STOP2__CNT__d_OW,param_4,param_2,pcVar5);
      RGE_Command::submit(param_1,puVar2,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043559b
// Address: 0043559b
// XREFS: None
// [HELPER] s_______: "      "
void __thiscall FUN_0043559b(RGE_Command *param_1,undefined4 param_2,int param_3,int param_4)
{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *this;
  int iVar4;
  
  if ((param_3 != 0) && (0 < param_4)) {
    iVar1 = param_4 * 4 + 2;
    puVar2 = (undefined1 *)calloc(1,iVar1);
    puVar3 = (undefined4 *)(puVar2 + 2);
    if (puVar2 != (undefined1 *)0x0) {
      this = extraout_ECX;
      if (0 < param_4) {
        this = (TDebuggingLog *)(param_3 - (int)puVar3);
        iVar4 = param_4;
        do {
          *puVar3 = *(undefined4 *)((int)puVar3 + (int)(this->TBuff + -0x28));
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      *puVar2 = 0xd;
      puVar2[1] = (char)param_4;
      TDebuggingLog::Log(this,(char *)L,s_______>SEND_CMD_PAUSE);
      RGE_Command::submit(param_1,puVar2,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00435616
// Address: 00435616
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
FUN_00435616(RGE_Command *param_1,int *param_2,short param_3,int param_4,undefined4 param_5,
            undefined4 param_6)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = (int)param_3;
  iVar1 = iVar8 * 4 + 0x14;
  if ((param_2 != (int *)0x0) && (0 < param_3)) {
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 0x14);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar8) {
        iVar6 = (int)param_2 - (int)puVar4;
        iVar9 = iVar8;
        do {
          iVar2 = *(int *)(iVar6 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      if (param_4 == 0) {
        *(undefined4 *)(puVar3 + 4) = 0xffffffff;
      }
      else {
        *(undefined4 *)(puVar3 + 4) = *(undefined4 *)(param_4 + 4);
      }
      *puVar3 = 2;
      puVar3[8] = (char)param_3;
      *(undefined4 *)(puVar3 + 0xc) = param_5;
      *(undefined4 *)(puVar3 + 0x10) = param_6;
      if (param_4 == 0) {
        pcVar7 = s_X;
      }
      else {
        pcVar7 = *(char **)(*(int *)(param_4 + 8) + 8);
      }
      iVar9 = *param_2;
      if (iVar9 == 0) {
        pcVar5 = s_X;
        iVar9 = -1;
      }
      else {
        pcVar5 = *(char **)(*(int *)(iVar9 + 8) + 8);
        iVar9 = (int)*(short *)(*(int *)(iVar9 + 0xc) + 0x4a);
      }
      TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_WORK__CNT__d_OWN,iVar8,iVar9,pcVar5,pcVar7);
      RGE_Command::submit(param_1,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00435807
// Address: 00435807
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
FUN_00435807(RGE_Command *param_1,int *param_2,short param_3,int param_4,undefined4 param_5,
            undefined4 param_6)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  char *this;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((param_2 != (int *)0x0) && (0 < param_3)) {
    iVar6 = (int)param_3;
    iVar1 = iVar6 * 4 + 0x14;
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 0x14);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar6) {
        iVar5 = (int)param_2 - (int)puVar4;
        iVar7 = iVar6;
        do {
          iVar2 = *(int *)(iVar5 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      if (param_4 == 0) {
        *(undefined4 *)(puVar3 + 4) = 0xffffffff;
      }
      else {
        *(undefined4 *)(puVar3 + 4) = *(undefined4 *)(param_4 + 4);
      }
      *puVar3 = 3;
      puVar3[8] = (char)param_3;
      *(undefined4 *)(puVar3 + 0xc) = param_5;
      *(undefined4 *)(puVar3 + 0x10) = param_6;
      iVar7 = *param_2;
      if (iVar7 == 0) {
        this = s_X;
        iVar7 = -1;
      }
      else {
        this = *(char **)(*(int *)(iVar7 + 8) + 8);
        iVar7 = (int)*(short *)(*(int *)(iVar7 + 0xc) + 0x4a);
      }
      TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_______>SEND_CMD_MOVE__CNT__d_OWN,iVar6,
                         iVar7,this);
      RGE_Command::submit(param_1,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004358ff
// Address: 004358ff
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
FUN_004358ff(RGE_Command *param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  RGE_Static_Object *pRVar4;
  char *pcVar5;
  int iVar6;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *this;
  int iVar7;
  
  if ((param_3 != (int *)0x0) && (0 < param_4)) {
    iVar1 = param_4 * 4 + 0x14;
    puVar2 = (undefined1 *)calloc(1,iVar1);
    puVar3 = (undefined4 *)(puVar2 + 0x14);
    if (puVar2 != (undefined1 *)0x0) {
      if (0 < param_4) {
        iVar6 = (int)param_3 - (int)puVar3;
        iVar7 = param_4;
        do {
          *puVar3 = *(undefined4 *)(iVar6 + (int)puVar3);
          puVar3 = puVar3 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      *puVar2 = 3;
      puVar2[8] = (char)param_4;
      *(undefined4 *)(puVar2 + 4) = param_5;
      *(undefined4 *)(puVar2 + 0xc) = param_7;
      *(undefined4 *)(puVar2 + 0x10) = param_8;
      pRVar4 = RGE_Game_World::object(param_1->world,*param_3);
      if (pRVar4 == (RGE_Static_Object *)0x0) {
        pcVar5 = s_X;
        this = extraout_ECX;
      }
      else {
        this = (TDebuggingLog *)pRVar4->master_obj;
        pcVar5 = (char *)this->LogToFile;
      }
      TDebuggingLog::Log(this,(char *)L,s_______>SEND_CMD_MOVE2__CNT__d_OW,param_4,param_2,pcVar5);
      RGE_Command::submit(param_1,puVar2,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00435a25
// Address: 00435a25
// XREFS: None
// [HELPER] s_______: "      "
void __thiscall
FUN_00435a25(RGE_Command *param_1,undefined4 param_2,TDebuggingLog *param_3,undefined4 param_4)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,8);
  *puVar1 = 5;
  puVar1[1] = (char)param_2;
  puVar1[2] = (char)param_3;
  *(undefined4 *)(puVar1 + 4) = param_4;
  TDebuggingLog::Log(param_3,(char *)L,s_______>SEND_CMD_ADD_ATTR__PLR__d,param_2,param_3);
  RGE_Command::submit(param_1,puVar1,8);
  return;
}

// --------------------------------------------------

// Function: FUN_00435a7e
// Address: 00435a7e
// XREFS: None
// [HELPER] s_______: "      "
void __thiscall
FUN_00435a7e(RGE_Command *param_1,undefined4 param_2,TDebuggingLog *param_3,undefined4 param_4,
            undefined4 param_5)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,8);
  *puVar1 = 7;
  puVar1[1] = (char)param_2;
  puVar1[2] = (char)param_3;
  puVar1[3] = (char)param_4;
  *(undefined4 *)(puVar1 + 4) = param_5;
  TDebuggingLog::Log(param_3,(char *)L,s_______>SEND_CMD_GIV_ATTR__FRM__d,param_2,param_3,param_4);
  RGE_Command::submit(param_1,puVar1,8);
  return;
}

// --------------------------------------------------

// Function: FUN_00435ad8
// Address: 00435ad8
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall FUN_00435ad8(RGE_Command *param_1,int *param_2,uint param_3,undefined4 param_4)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  char *this;
  int iVar5;
  uint uVar6;
  
  iVar1 = param_3 * 4 + 0xc;
  if ((param_2 != (int *)0x0) && (0 < (int)param_3)) {
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 0xc);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < (int)param_3) {
        iVar5 = (int)param_2 - (int)puVar4;
        uVar6 = param_3;
        do {
          iVar2 = *(int *)(iVar5 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
      *puVar3 = 6;
      *(uint *)(puVar3 + 4) = param_3 & 0xff;
      *(undefined4 *)(puVar3 + 8) = param_4;
      iVar5 = *param_2;
      if (iVar5 == 0) {
        this = s_X;
        iVar5 = -1;
      }
      else {
        this = *(char **)(*(int *)(iVar5 + 8) + 8);
        iVar5 = (int)*(short *)(*(int *)(iVar5 + 0xc) + 0x4a);
      }
      TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_______>SEND_CMD_FORMATION__CNT__,param_3,
                         iVar5,this);
      RGE_Command::submit(param_1,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00435baf
// Address: 00435baf
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
FUN_00435baf(RGE_Command *param_1,undefined4 param_2,undefined4 param_3,int *param_4,int param_5,
            undefined4 param_6)
{
  int iVar1;
  undefined1 *puVar2;
  int *piVar3;
  RGE_Static_Object *pRVar4;
  char *pcVar5;
  int *piVar6;
  int iVar7;
  
  puVar2 = (undefined1 *)calloc(1,0x74);
  *puVar2 = 8;
  puVar2[1] = (undefined1)param_2;
  *(undefined4 *)(puVar2 + 4) = param_3;
  if (0 < param_5) {
    piVar6 = (int *)(puVar2 + 0xc);
    piVar3 = param_4;
    iVar7 = param_5;
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      *piVar6 = iVar1;
      piVar6 = piVar6 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  puVar2[0x70] = (char)param_5;
  *(undefined4 *)(puVar2 + 8) = param_6;
  pRVar4 = RGE_Game_World::object(param_1->world,*param_4);
  if (pRVar4 == (RGE_Static_Object *)0x0) {
    pcVar5 = s_X;
  }
  else {
    pcVar5 = pRVar4->master_obj->name;
  }
  TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_CRT_GROUP__CNT__,param_5,param_2,pcVar5);
  RGE_Command::submit(param_1,puVar2,0x74);
  return;
}

// --------------------------------------------------

// Function: FUN_00435c49
// Address: 00435c49
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
FUN_00435c49(RGE_Command *param_1,undefined4 param_2,undefined4 param_3,int param_4,
            undefined4 param_5)
{
  undefined1 *puVar1;
  RGE_Static_Object *pRVar2;
  char *pcVar3;
  TDebuggingLog *this;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  *(undefined4 *)(puVar1 + 4) = param_3;
  *puVar1 = 0xe;
  puVar1[1] = (char)param_2;
  *(int *)(puVar1 + 0xc) = param_4;
  *(undefined4 *)(puVar1 + 8) = param_5;
  pRVar2 = RGE_Game_World::object(param_1->world,param_4);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    pcVar3 = s_X;
  }
  else {
    pcVar3 = pRVar2->master_obj->name;
  }
  TDebuggingLog::Log(this,(char *)L,s_______>SEND_CMD_ADD_GROUP__PLR__,param_2,pcVar3);
  RGE_Command::submit(param_1,puVar1,0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_00435cc1
// Address: 00435cc1
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall FUN_00435cc1(RGE_Command *param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  undefined1 *puVar1;
  RGE_Static_Object *pRVar2;
  char *pcVar3;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *this;
  
  puVar1 = (undefined1 *)calloc(1,0xc);
  *(undefined4 *)(puVar1 + 4) = param_3;
  *puVar1 = 0xf;
  puVar1[1] = (char)param_2;
  *(int *)(puVar1 + 8) = param_4;
  pRVar2 = RGE_Game_World::object(param_1->world,param_4);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    pcVar3 = s_X;
    this = extraout_ECX;
  }
  else {
    this = (TDebuggingLog *)pRVar2->master_obj;
    pcVar3 = (char *)this->LogToFile;
  }
  TDebuggingLog::Log(this,(char *)L,s_______>SEND_CMD_REM_GROUP__PLR__,param_2,pcVar3);
  RGE_Command::submit(param_1,puVar1,0xc);
  return;
}

// --------------------------------------------------

// Function: FUN_00435d3b
// Address: 00435d3b
// XREFS: None
// [HELPER] s_______: "      "
void __thiscall FUN_00435d3b(RGE_Command *param_1,undefined4 param_2,TDebuggingLog *param_3)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,8);
  *puVar1 = 9;
  puVar1[1] = (char)param_2;
  *(TDebuggingLog **)(puVar1 + 4) = param_3;
  TDebuggingLog::Log(param_3,(char *)L,s_______>SEND_CMD_DES_GROUP__PLR__,param_2);
  RGE_Command::submit(param_1,puVar1,8);
  return;
}

// --------------------------------------------------

// Function: FUN_00435d87
// Address: 00435d87
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
FUN_00435d87(RGE_Command *param_1,TDebuggingLog *param_2,undefined4 param_3,int param_4,
            undefined4 param_5,int param_6,undefined1 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined1 param_12,undefined1 param_13,
            undefined1 param_14)
{
  undefined1 *puVar1;
  RGE_Static_Object *pRVar2;
  RGE_Static_Object *pRVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined1 *)calloc(1,0x28);
  puVar1[1] = param_2._0_1_;
  puVar1[2] = (undefined1)param_3;
  *(undefined2 *)(puVar1 + 8) = (undefined2)param_5;
  puVar1[10] = param_14;
  puVar1[0x10] = param_7;
  *(undefined4 *)(puVar1 + 0x14) = param_8;
  *(undefined4 *)(puVar1 + 0x18) = param_9;
  *(undefined4 *)(puVar1 + 0x1c) = param_10;
  *puVar1 = 10;
  *(int *)(puVar1 + 4) = param_4;
  *(int *)(puVar1 + 0xc) = param_6;
  *(undefined4 *)(puVar1 + 0x20) = param_11;
  puVar1[0x24] = param_12;
  puVar1[0x25] = param_13;
  pRVar2 = RGE_Game_World::object(param_1->world,param_4);
  pRVar3 = RGE_Game_World::object(param_1->world,param_6);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    _param_14 = s_X;
  }
  else {
    _param_14 = pRVar3->master_obj->name;
  }
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    _param_12 = s_X;
  }
  else {
    _param_12 = pRVar2->master_obj->name;
  }
  uVar4 = __ftol();
  uVar4 = __ftol(uVar4);
  TDebuggingLog::Log(param_2,(char *)L,s_______>SEND_CMD_AI_ORD__PLR__d__,param_2,param_5,param_3,
                     param_4,_param_12,param_6,_param_14,uVar4);
  RGE_Command::submit(param_1,puVar1,0x28);
  return;
}

// --------------------------------------------------

// Function: FUN_00435e9f
// Address: 00435e9f
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
FUN_00435e9f(RGE_Command *param_1,undefined4 param_2,TDebuggingLog *param_3,int *param_4,
            short param_5,undefined4 param_6,int param_7,undefined1 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined1 param_13,
            undefined1 param_14,undefined1 param_15)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  RGE_Static_Object *pRVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if ((param_4 != (int *)0x0) && (0 < param_5)) {
    iVar9 = (int)param_5;
    iVar1 = iVar9 * 4 + 0x24;
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 0x24);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar9) {
        iVar8 = (int)param_4 - (int)puVar4;
        iVar10 = iVar9;
        do {
          iVar2 = *(int *)(iVar8 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      puVar3[2] = param_3._0_1_;
      puVar3[6] = param_15;
      puVar3[0xc] = param_8;
      puVar3[3] = (undefined1)param_5;
      *(undefined4 *)(puVar3 + 0x10) = param_9;
      *(undefined4 *)(puVar3 + 0x14) = param_10;
      *(int *)(puVar3 + 8) = param_7;
      *(undefined4 *)(puVar3 + 0x18) = param_11;
      *(undefined4 *)(puVar3 + 0x1c) = param_12;
      *puVar3 = 0x11;
      puVar3[1] = (char)param_2;
      *(short *)(puVar3 + 4) = (short)param_6;
      puVar3[0x20] = param_13;
      puVar3[0x21] = param_14;
      pRVar5 = RGE_Game_World::object(param_1->world,param_7);
      if (pRVar5 == (RGE_Static_Object *)0x0) {
        pcVar7 = s_X;
      }
      else {
        pcVar7 = pRVar5->master_obj->name;
      }
      if (*param_4 == 0) {
        pcVar6 = s_X;
      }
      else {
        pcVar6 = *(char **)(*(int *)(*param_4 + 8) + 8);
      }
      TDebuggingLog::Log(param_3,(char *)L,s_______>SEND_CMD_GRP_AI_ORD__PLR_,param_2,param_6,
                         param_3,iVar9,pcVar6,pcVar7);
      RGE_Command::submit(param_1,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00435fdb
// Address: 00435fdb
// XREFS: None
// [HELPER] s_______: "      "
void __thiscall
FUN_00435fdb(RGE_Command *param_1,undefined4 param_2,undefined1 param_3,TDebuggingLog *param_4)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,4);
  puVar1[2] = param_3;
  *puVar1 = 0xb;
  puVar1[1] = (char)param_2;
  puVar1[3] = (char)param_4;
  TDebuggingLog::Log(param_4,(char *)L,s_______>SEND_CMD_RESIGN__PLR__d_D,param_2,param_4);
  RGE_Command::submit(param_1,puVar1,4);
  return;
}

// --------------------------------------------------

// Function: FUN_0043602f
// Address: 0043602f
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
FUN_0043602f(RGE_Command *param_1,TDebuggingLog *param_2,int param_3,int param_4,int param_5)
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  RGE_Static_Object *pRVar3;
  char *pcVar4;
  undefined1 *puVar5;
  
  puVar1 = (undefined1 *)calloc(1,0x18);
  *puVar1 = 0xc;
  puVar1[1] = param_2._0_1_;
  *(int *)(puVar1 + 4) = param_3;
  puVar1[8] = (char)param_5;
  if (0 < param_5) {
    puVar5 = puVar1 + 10;
    puVar2 = (undefined1 *)(param_4 + 2);
    do {
      puVar5[-1] = puVar2[-2];
      *puVar5 = puVar2[-1];
      puVar5[1] = *puVar2;
      puVar5 = puVar5 + 3;
      param_5 = param_5 + -1;
      puVar2 = puVar2 + 3;
    } while (param_5 != 0);
  }
  pRVar3 = RGE_Game_World::object(param_1->world,param_3);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    pcVar4 = s_X;
  }
  else {
    pcVar4 = pRVar3->master_obj->name;
  }
  TDebuggingLog::Log(param_2,(char *)L,s_______>SEND_CMD_ADD_WAY__PLR__d_,param_2,pcVar4);
  RGE_Command::submit(param_1,puVar1,0x18);
  return;
}

// --------------------------------------------------

// Function: FUN_004360cb
// Address: 004360cb
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
FUN_004360cb(RGE_Command *param_1,undefined4 param_2,int param_3,undefined1 param_4,
            undefined1 param_5,undefined1 param_6)
{
  undefined1 *puVar1;
  RGE_Static_Object *pRVar2;
  char *pcVar3;
  TDebuggingLog *this;
  
  puVar1 = (undefined1 *)calloc(1,0x18);
  puVar1[9] = param_4;
  *puVar1 = 0xc;
  puVar1[1] = (char)param_2;
  *(int *)(puVar1 + 4) = param_3;
  puVar1[8] = 1;
  puVar1[10] = param_5;
  puVar1[0xb] = param_6;
  pRVar2 = RGE_Game_World::object(param_1->world,param_3);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    pcVar3 = s_X;
  }
  else {
    pcVar3 = pRVar2->master_obj->name;
  }
  TDebuggingLog::Log(this,(char *)L,s_______>SEND_CMD_ADD_WAY2__PLR__d,param_2,pcVar3);
  RGE_Command::submit(param_1,puVar1,0x18);
  return;
}

// --------------------------------------------------

// Function: FUN_0043614c
// Address: 0043614c
// XREFS: None
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
FUN_0043614c(RGE_Command *param_1,int *param_2,short param_3,undefined1 param_4,undefined1 param_5)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  char *this;
  int iVar5;
  int iVar6;
  
  iVar6 = (int)param_3;
  iVar1 = iVar6 * 4 + 4;
  if ((param_2 != (int *)0x0) && (0 < param_3)) {
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 4);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar6) {
        iVar5 = (int)param_2 - (int)puVar4;
        do {
          iVar2 = *(int *)(iVar5 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      *puVar3 = 0x10;
      puVar3[1] = (char)param_3;
      puVar3[2] = param_4;
      puVar3[3] = param_5;
      iVar6 = *param_2;
      if (iVar6 == 0) {
        this = s_X;
        iVar6 = -1;
      }
      else {
        this = *(char **)(*(int *)(iVar6 + 8) + 8);
        iVar6 = (int)*(short *)(*(int *)(iVar6 + 0xc) + 0x4a);
      }
      TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_______>SEND_CMD_GRP_WAY__PLR__d_,iVar6,
                         this);
      RGE_Command::submit(param_1,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043621c
// Address: 0043621c
// XREFS: None
// [HELPER] s_C__APPLOGERR_TXT: "C:\APPLOGERR.TXT"
// [HELPER] s____Logging___: "===Logging==="
TDebuggingLog * __fastcall FUN_0043621c(TDebuggingLog *param_1)
{
  char cVar1;
  TDebuggingLog *this;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  param_1->LogToFile = 0;
  param_1->LogToOutput = 0;
  param_1->LogError = 0;
  param_1->LogIsOpen = 0;
  TDebuggingLog::LogSequence(param_1,0);
  TDebuggingLog::LogTimestamp(param_1,0);
  TDebuggingLog::LogDateTimestamp(param_1,0);
  TDebuggingLog::FlushToDisk(param_1,0);
  TDebuggingLog::OpenLog(param_1);
  TDebuggingLog::Log(this,(char *)param_1,s____Logging___);
  TDebuggingLog::Time(param_1);
  uVar2 = 0xffffffff;
  pcVar4 = &s_C__APPLOGERR_TXT;
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
  pcVar5 = param_1->Filename;
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

// Function: FUN_004362a5
// Address: 004362a5
// XREFS: None
// [HELPER] s_Logging_to_File__s: "Logging to File %s"
void __thiscall FUN_004362a5(TDebuggingLog *param_1,int param_2)
{
  char *pcVar1;
  TDebuggingLog *this;
  
  if (param_2 == 0) {
    param_1->LogToFile = 0;
  }
  else {
    param_1->LogToFile = 1;
  }
  pcVar1 = TDebuggingLog::YesOrNo(param_1,param_2);
  TDebuggingLog::Log(this,(char *)param_1,s_Logging_to_File__s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_004362e6
// Address: 004362e6
// XREFS: None
// [HELPER] s_Logging_to_OUTPUT__s: "Logging to OUTPUT %s"
void __thiscall FUN_004362e6(TDebuggingLog *param_1,int param_2)
{
  char *pcVar1;
  TDebuggingLog *this;
  
  if (param_2 == 0) {
    param_1->LogToOutput = 0;
  }
  else {
    param_1->LogToOutput = 1;
  }
  pcVar1 = TDebuggingLog::YesOrNo(param_1,param_2);
  TDebuggingLog::Log(this,(char *)param_1,s_Logging_to_OUTPUT__s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00436326
// Address: 00436326
// XREFS: None
// [HELPER] s_Timestamp_milliseconds__s: "Timestamp milliseconds %s"
void __thiscall FUN_00436326(TDebuggingLog *param_1,int param_2)
{
  char *pcVar1;
  TDebuggingLog *this;
  
  param_1->Timestamp = (uint)(param_2 != 0);
  pcVar1 = TDebuggingLog::YesOrNo(param_1,(uint)(param_2 != 0));
  TDebuggingLog::Log(this,(char *)param_1,s_Timestamp_milliseconds__s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_0043635d
// Address: 0043635d
// XREFS: None
// [HELPER] s_Date___Time_stamp_s: "Date & Time stamp%s"
void __thiscall FUN_0043635d(TDebuggingLog *param_1,int param_2)
{
  char *pcVar1;
  TDebuggingLog *this;
  
  if (param_2 == 0) {
    param_1->DateTimestamp = 0;
  }
  else {
    param_1->DateTimestamp = 1;
  }
  pcVar1 = TDebuggingLog::YesOrNo(param_1,param_1->Timestamp);
  TDebuggingLog::Log(this,(char *)param_1,s_Date___Time_stamp_s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00436398
// Address: 00436398
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_Debuglog_c: "C:\msdev\work\age1_x1\Debuglog.cpp"
// [HELPER] s__: "}"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00436398(char *param_1)
{
  float fVar1;
  ulong uVar2;
  int iVar3;
  char *pcVar4;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *extraout_ECX_00;
  TDebuggingLog *this;
  
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Debuglog_c,0x78);
  time();
  iVar3 = localtime();
  fVar1 = (float)(uVar2 - *(int *)(param_1 + 0x20)) * _DAT_0056f500;
  if (iVar3 == 0) {
    pcVar4 = s__;
    this = extraout_ECX;
  }
  else {
    pcVar4 = (char *)asctime();
    this = extraout_ECX_00;
  }
  TDebuggingLog::Log(this,param_1,s_>>>TIME>>>___s_____7_1f_sec__ela,pcVar4,(double)fVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00436424
// Address: 00436424
// XREFS: None
// [HELPER] s_Flush_queue_each_message__s: "Flush queue each message %s"
void __thiscall FUN_00436424(TDebuggingLog *param_1,int param_2)
{
  char *pcVar1;
  TDebuggingLog *this;
  
  if (param_2 == 0) {
    param_1->Flush = 0;
  }
  else {
    param_1->Flush = 1;
  }
  pcVar1 = TDebuggingLog::YesOrNo(param_1,param_1->Flush);
  TDebuggingLog::Log(this,(char *)param_1,s_Flush_queue_each_message__s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00436469
// Address: 00436469
// XREFS: None
// [HELPER] s_Sequence_numbering_s: "Sequence numbering%s"
void __thiscall FUN_00436469(TDebuggingLog *param_1,int param_2)
{
  char *pcVar1;
  TDebuggingLog *this;
  
  if (param_2 == 0) {
    param_1->Sequence = 0;
  }
  else {
    param_1->Sequence = 1;
    param_1->SeqNo = 0;
  }
  pcVar1 = TDebuggingLog::YesOrNo(param_1,param_1->Sequence);
  TDebuggingLog::Log(this,(char *)param_1,s_Sequence_numbering_s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_004364aa
// Address: 004364aa
// XREFS: None
// [HELPER] s_C__AOELOG__2d_txt: "C:\AOELOG%.2d.txt"
// [HELPER] s_C__AOELOG_txt: "C:\AOELOG.txt"
// [HELPER] s_C__msdev_work_age1_x1_Debuglog_c: "C:\msdev\work\age1_x1\Debuglog.cpp"
// [HELPER] s_Log_file__s_is_opened: "Log file %s is opened"
// [HELPER] s_wt: "wt"
void __fastcall FUN_004364aa(TDebuggingLog *param_1)
{
  char *pcVar1;
  char cVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  int iStack_4;
  
  if ((param_1->LogToFile == 0) || ((param_1->LogIsOpen != 0 && (param_1->LogError == 0)))) {
    return;
  }
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Debuglog_c,0xa3);
  param_1->LogStartTickCount = uVar3;
  iStack_4 = 1;
  do {
    pcVar1 = param_1->Filename;
    if (iStack_4 == 1) {
      uVar4 = 0xffffffff;
      pcVar6 = &s_C__AOELOG_txt;
      do {
        pcVar7 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar7 = pcVar6 + 1;
        cVar2 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar2 != '\0');
      uVar4 = ~uVar4;
      pcVar6 = pcVar7 + -uVar4;
      pcVar7 = pcVar1;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
    }
    else {
      sprintf(pcVar1,s_C__AOELOG__2d_txt,iStack_4 + -1);
    }
    logstream = (_iobuf *)fopen(pcVar1,s_wt);
    if (logstream != (_iobuf *)0x0) {
      param_1->LogIsOpen = 1;
      TDebuggingLog::Log((TDebuggingLog *)param_1->Filename,(char *)param_1,s_Log_file__s_is_opened,
                         param_1->Filename);
      TDebuggingLog::Time(param_1);
      return;
    }
    iStack_4 = iStack_4 + 1;
    if (0x19 < iStack_4) {
      param_1->LogError = 1;
      param_1->LogIsOpen = 0;
      return;
    }
    logstream = (_iobuf *)0x0;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0043659f
// Address: 0043659f
// XREFS: None
void __fastcall FUN_0043659f(int param_1)
{
  if (*(int *)(param_1 + 8) != 0) {
    fflush(logstream);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004365b6
// Address: 004365b6
// XREFS: None
// [HELPER] s_Closing_debug_log_file___s__: "Closing debug log file '%s'."
// [HELPER] s_Log_file_is_closed: "Log file is closed"
void __fastcall FUN_004365b6(TDebuggingLog *param_1)
{
  TDebuggingLog *this;
  
  if (param_1->LogToFile != 0) {
    if (param_1->Filename != (char *)0x0) {
      TDebuggingLog::Log(param_1,(char *)param_1,s_Closing_debug_log_file___s__,param_1->Filename);
    }
    TDebuggingLog::Time(param_1);
    TDebuggingLog::Log(this,(char *)param_1,s_Log_file_is_closed);
    fclose(logstream);
    param_1->LogIsOpen = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043660f
// Address: 0043660f
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s___2f__: "%.2f |"
// [HELPER] s___: "]\n"
// [HELPER] s__ld__: "%ld |"
// [HELPER] s__s_s_s_s_s_: "%s%s%s%s%s\n"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043660f(TDebuggingLog *param_1,undefined4 param_2)
{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 auStack_84 [4];
  char acStack_80 [32];
  undefined1 auStack_60 [32];
  char acStack_40 [32];
  undefined1 auStack_20 [32];
  
  if (((param_1->LogToFile != 0) || (param_1->LogToOutput != 0)) && (param_1->LogError == 0)) {
    if ((param_1->LogIsOpen == 0) && (param_1->LogToFile != 0)) {
      TDebuggingLog::OpenLog(param_1);
    }
    if ((param_1->LogIsOpen == 0) && (param_1->LogToFile != 0)) {
      param_1->LogError = 1;
      return;
    }
    param_1->SeqNo = param_1->SeqNo + 1;
    vsprintf(param_1->TBuff,param_2,&stack0x0000000c);
    uVar2 = GetTickCount();
    acStack_40[0] = '\0';
    auStack_60[0] = 0;
    acStack_80[0] = '\0';
    auStack_20[0] = 0;
    if (param_1->Timestamp != 0) {
      sprintf(auStack_20,s___2f__,
              (double)(((float)uVar2 - (float)(int)param_1->LogStartTickCount) * _DAT_0056f500));
    }
    if (param_1->DateTimestamp != 0) {
      time();
      uVar3 = ctime(auStack_84,0x14);
      strncat(acStack_80,uVar3);
      uVar2 = 0xffffffff;
      pcVar6 = &s___;
      do {
        pcVar8 = pcVar6;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar8 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar8;
      } while (cVar1 != '\0');
      uVar2 = ~uVar2;
      iVar4 = -1;
      pcVar6 = acStack_80;
      do {
        pcVar7 = pcVar6;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      pcVar6 = pcVar8 + -uVar2;
      pcVar8 = pcVar7 + -1;
      for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar8 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      }
    }
    if (param_1->Sequence != 0) {
      sprintf(auStack_60,s__ld__,param_1->SeqNo);
    }
    uVar2 = 0xffffffff;
    pcVar6 = &s_>;
    do {
      pcVar8 = pcVar6;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar6 = pcVar8 + -uVar2;
    pcVar8 = acStack_40;
    for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar8 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    }
    sprintf(param_1->osbuf,s__s_s_s_s_s_,auStack_20,acStack_80,auStack_60,acStack_40,param_1->TBuff)
    ;
    if (param_1->LogToOutput != 0) {
      OutputDebugStringA();
    }
    if (((param_1->LogToFile != 0) && (param_1->LogIsOpen != 0)) &&
       (fputs(param_1->osbuf,logstream), param_1->Flush != 0)) {
      fflush();
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00436804
// Address: 00436804
// XREFS: None
// [HELPER] s__has_been_deactivated_: " has been deactivated."
// [HELPER] s__is_now_ACTIVE_: " is now ACTIVE."
char * FUN_00436804(int param_1)
{
  char *pcVar1;
  
  pcVar1 = s__is_now_ACTIVE_;
  if (param_1 == 0) {
    pcVar1 = s__has_been_deactivated_;
  }
  return pcVar1;
}

// --------------------------------------------------

// Function: FUN_00436825
// Address: 00436825
// XREFS: None
TPanel * __fastcall FUN_00436825(TPanel *param_1)
{
  TPanel::TPanel(param_1);
  param_1[1]._padding_ = 0;
  param_1[1].previousPanelValue = (TPanel *)0x0;
  param_1[1].previousModalPanelValue = (TPanel *)0x0;
  param_1[1].panelNameValue = (char *)0x0;
  param_1[1].clip_rect.bottom = 0;
  *(undefined2 *)&param_1[1].parent_panel = 0;
  param_1[1].position_mode = PositionFixed;
  param_1[1].need_redraw = RedrawNone;
  *(undefined2 *)((int)&param_1[1].parent_panel + 2) = 0;
  *(undefined2 *)&param_1[1].left_panel = 0;
  *(undefined2 *)((int)&param_1[1].left_panel + 2) = 0;
  param_1[1].top_panel = (TPanel *)0x0;
  *(undefined2 *)&param_1[1].node = 0;
  *(undefined2 *)((int)&param_1[1].node + 2) = 0;
  param_1[1].right_panel = (TPanel *)0x0;
  param_1[1].bottom_panel = (TPanel *)0x0;
  param_1[1].tab_stop = 0;
  param_1[1].visible = 0;
  param_1[1].render_area = (TDrawArea *)0x0;
  param_1[1].clip_rect.left = 0;
  param_1[1].clip_rect.top = 0;
  param_1[1].clip_rect.right = 0;
  param_1[1].last_child_node = (PanelNode *)0x0;
  param_1[1].tab_prev_panel = (TPanel *)0x0;
  param_1[1].mouse_captured = 0;
  param_1[1].active = 0;
  param_1->_padding_ = (int)&RGE_Diamond_Map::_vftable_;
  *(undefined2 *)&param_1[1].first_child_node = 0xffff;
  *(undefined2 *)((int)&param_1[1].first_child_node + 2) = 0xffff;
  param_1[1].pnl_y = 1;
  *(undefined1 *)&param_1[1].tab_next_panel = 0xff;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00436908
// Address: 00436908
// XREFS: None
RGE_Diamond_Map * __thiscall FUN_00436908(RGE_Diamond_Map *param_1,byte param_2)
{
  RGE_Diamond_Map::~RGE_Diamond_Map(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043692e
// Address: 0043692e
// XREFS: None
void __fastcall FUN_0043692e(RGE_Diamond_Map *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055cf18;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&RGE_Diamond_Map::_vftable_;
  uStack_4 = 0;
  RGE_Diamond_Map::delete_surfaces(param_1);
  if (param_1->map_tile_rows != (RGE_Map_Tile_Row *)0x0) {
    free(param_1->map_tile_rows);
    param_1->map_tile_rows = (RGE_Map_Tile_Row *)0x0;
  }
  if (param_1->map_image_lines != (RGE_Map_Image_Line *)0x0) {
    free(param_1->map_image_lines);
    param_1->map_image_lines = (RGE_Map_Image_Line *)0x0;
  }
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004369b9
// Address: 004369b9
// XREFS: None
undefined4 __thiscall
FUN_004369b9(TPanel *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            long param_6,long param_7,uchar param_8,undefined4 param_9,int param_10)
{
  param_1[1].tab_stop = param_10;
  param_1[1].visible = 0;
  TPanel::setup(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00436a04
// Address: 00436a04
// XREFS: None
undefined4 __thiscall FUN_00436a04(RGE_Diamond_Map *param_1,char *param_2,TPicture *param_3)
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  TPicture *this;
  undefined4 uVar6;
  RGE_Map_Image_Line *pRVar7;
  long lVar8;
  short sVar9;
  uchar *puVar10;
  uchar *puVar11;
  short sVar12;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cf3b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_1->map_image_lines != (RGE_Map_Image_Line *)0x0) {
    free(param_1->map_image_lines);
    param_1->map_image_lines = (RGE_Map_Image_Line *)0x0;
  }
  if (param_1->map_tile_rows != (RGE_Map_Tile_Row *)0x0) {
    free(param_1->map_tile_rows);
    param_1->map_tile_rows = (RGE_Map_Tile_Row *)0x0;
  }
  this = (TPicture *)operator_new(0x20);
  uStack_4 = 0;
  if (this == (TPicture *)0x0) {
    param_3 = (TPicture *)0x0;
  }
  else {
    param_3 = (TPicture *)TPicture::TPicture(this,param_2,(long)param_3,0,(void *)0x0,0);
  }
  uStack_4 = 0xffffffff;
  if (param_3 == (TPicture *)0x0) {
    uVar6 = 0;
  }
  else if (param_3->Dib == (tagBITMAPINFOHEADER *)0x0) {
    TPicture::~TPicture(param_3);
    operator_delete(param_3);
    uVar6 = 0;
  }
  else {
    sVar1 = (short)param_3->Height;
    sVar2 = (short)param_3->Width;
    pRVar7 = (RGE_Map_Image_Line *)calloc((int)sVar1,6);
    param_1->map_image_lines = pRVar7;
    if (param_3->Orien == 1) {
      puVar11 = param_3->Bits;
      lVar8 = TPicture::AlignedWidth(param_3);
      sVar3 = (short)lVar8;
    }
    else {
      lVar8 = TPicture::AlignedWidth(param_3);
      puVar11 = param_3->Bits + lVar8 * (sVar1 + -1);
      lVar8 = TPicture::AlignedWidth(param_3);
      sVar3 = -(short)lVar8;
    }
    param_1->map_image_start_y = -1;
    param_1->map_image_wid = 0;
    param_1->map_image_hgt = 0;
    sVar5 = 0;
    if (0 < sVar1) {
      do {
        sVar9 = 0;
        puVar10 = puVar11;
        sVar4 = -1;
        if (0 < sVar2) {
          do {
            sVar4 = sVar9;
            if (*puVar10 == 0xff) break;
            puVar10 = puVar10 + 1;
            sVar9 = sVar9 + 1;
            sVar4 = -1;
          } while (sVar9 < sVar2);
        }
        if (sVar4 != -1) {
          sVar12 = 0;
          for (; (sVar9 < sVar2 && (*puVar10 == 0xff)); puVar10 = puVar10 + 1) {
            sVar12 = sVar12 + 1;
            sVar9 = sVar9 + 1;
          }
          param_1->map_image_lines[param_1->map_image_hgt].start_x = sVar4;
          param_1->map_image_lines[param_1->map_image_hgt].line_len = sVar12;
          param_1->map_image_hgt = param_1->map_image_hgt + 1;
          if (param_1->map_image_wid < sVar12) {
            param_1->map_image_wid = sVar12;
          }
          if (param_1->map_image_start_y == -1) {
            param_1->map_image_start_y = sVar5;
          }
        }
        puVar11 = puVar11 + sVar3;
        sVar5 = sVar5 + 1;
      } while (sVar5 < sVar1);
    }
    TPicture::~TPicture(param_3);
    operator_delete(param_3);
    if (param_1->world != (RGE_Game_World *)0x0) {
      RGE_Diamond_Map::set_world(param_1,param_1->world);
    }
    uVar6 = 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar6;
}

// --------------------------------------------------

// Function: FUN_00436c2d
// Address: 00436c2d
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00436c2d(int *param_1,int param_2)
{
  short sVar1;
  float fVar2;
  short sVar3;
  undefined2 uVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  short sVar10;
  float10 fVar11;
  float10 fVar12;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  short sStack_10;
  
  param_1[0x3d] = param_2;
  if ((param_2 != 0) && (param_1[0x4a] != 0)) {
    iVar6 = *(int *)(param_2 + 0x28);
    param_1[0x3f] = iVar6;
    *(undefined2 *)(param_1 + 0x4c) = *(undefined2 *)(iVar6 + 8);
    sVar5 = *(short *)(param_1[0x3f] + 0xc);
    *(short *)((int)param_1 + 0x132) = sVar5;
    *(short *)((int)param_1 + 0x13a) = (short)param_1[0x4c] + sVar5 + -1;
    if (param_1[0x4b] != 0) {
      free(param_1[0x4b]);
    }
    iVar6 = calloc((int)*(short *)((int)param_1 + 0x13a),0x24);
    param_1[0x4b] = iVar6;
    param_1[0x4f] =
         (int)((float)(int)*(short *)((int)param_1 + 0x13a) / (float)(int)(short)param_1[0x4e]);
    sVar10 = 0;
    sStack_10 = 0;
    sVar5 = 0;
    if (0 < (short)param_1[0x4e]) {
      do {
        iVar6 = param_1[0x4a];
        sVar1 = *(short *)(iVar6 + 4 + sVar5 * 6);
        sVar3 = __ftol();
        if (*(short *)((int)param_1 + 0x13a) <= sVar3) {
          sVar3 = *(short *)((int)param_1 + 0x13a) + -1;
        }
        *(short *)(iVar6 + sVar5 * 6) = sVar3;
        if (sVar3 < (short)param_1[0x4c]) {
          sVar9 = *(short *)((int)param_1 + 0x132);
          if (sVar3 < sVar9) {
            sVar9 = sVar3 + 1;
          }
        }
        else {
          sVar9 = (*(short *)((int)param_1 + 0x132) - sVar3) + -1 + (short)param_1[0x4c];
        }
        fVar11 = (float10)(int)sVar9;
        fVar12 = fVar11 / (float10)(int)sVar1;
        sStack_10 = __ftol();
        if ((float10)(int)sStack_10 != extraout_ST0) {
          sStack_10 = sStack_10 + 1;
        }
        iVar6 = sVar3 * 0x24;
        *(short *)(param_1[0x4b] + iVar6) = sVar5;
        *(undefined1 *)(param_1[0x4b] + 2 + iVar6) = 1;
        *(short *)(param_1[0x4b] + 4 + iVar6) = sVar9;
        *(float *)(param_1[0x4b] + 8 + iVar6) = (float)fVar11;
        *(short *)(param_1[0x4b] + 0x14 + iVar6) = sStack_10;
        *(float *)(param_1[0x4b] + 0x18 + iVar6) = (float)extraout_ST0;
        fVar11 = extraout_ST1;
        uVar4 = __ftol();
        *(undefined2 *)(param_1[0x4b] + 0x1c + iVar6) = uVar4;
        *(float *)(param_1[0x4b] + 0x20 + iVar6) = (float)(extraout_ST1_00 / fVar11);
        fVar2 = (float)DAT_0056f5fc;
        if (*(float *)(param_1[0x4b] + 0x20 + iVar6) < _DAT_0056f604) {
          fVar2 = (float)fVar12 * ram0x0056f600;
        }
        *(float *)(param_1[0x4b] + iVar6 + 0xc) = fVar2;
        if (sVar3 < (short)param_1[0x4c]) {
          *(undefined2 *)(param_1[0x4b] + 0x12 + iVar6) = 0;
          *(short *)(param_1[0x4b] + 0x10 + iVar6) = ((short)param_1[0x4c] - sVar3) + -1;
        }
        else {
          *(short *)(param_1[0x4b] + 0x12 + iVar6) = (sVar3 - (short)param_1[0x4c]) + 1;
          *(undefined2 *)(param_1[0x4b] + 0x10 + iVar6) = 0;
        }
        sStack_10 = sVar10 + sStack_10;
        sVar5 = sVar5 + 1;
        sVar10 = sStack_10;
      } while (sVar5 < (short)param_1[0x4e]);
    }
    sVar5 = __ftol();
    *(short *)(param_1 + 0x52) = sVar5;
    if ((float10)(int)sVar5 != extraout_ST0_00) {
      *(short *)(param_1 + 0x52) = sVar5 + 1;
    }
    sStack_10 = sStack_10 / (short)param_1[0x4e];
    *(short *)((int)param_1 + 0x14a) = sStack_10;
    if (sStack_10 == 0) {
      *(undefined2 *)((int)param_1 + 0x14a) = 1;
    }
    sVar10 = 0;
    fVar11 = (float10)(int)(short)param_1[0x4e];
    param_1[0x50] = (int)(float)(extraout_ST1_01 / fVar11);
    param_1[0x51] = (int)(float)(fVar11 / (float10)(int)*(short *)((int)param_1 + 0x13a));
    sVar5 = 0;
    if (0 < *(short *)((int)param_1 + 0x13a)) {
      do {
        iVar6 = param_1[0x4b];
        iVar8 = sVar10 * 0x24;
        sVar3 = sVar10;
        if (*(char *)(iVar8 + 2 + iVar6) == '\0') {
          iVar7 = sVar5 * 0x24;
          *(undefined2 *)(iVar8 + iVar6) = *(undefined2 *)(iVar7 + iVar6);
          *(undefined2 *)(iVar8 + 4 + param_1[0x4b]) = *(undefined2 *)(iVar7 + 4 + param_1[0x4b]);
          *(undefined4 *)(iVar8 + 8 + param_1[0x4b]) = *(undefined4 *)(iVar7 + 8 + param_1[0x4b]);
          *(undefined2 *)(iVar8 + 0x14 + param_1[0x4b]) =
               *(undefined2 *)(iVar7 + 0x14 + param_1[0x4b]);
          *(undefined4 *)(iVar8 + 0x18 + param_1[0x4b]) =
               *(undefined4 *)(iVar7 + 0x18 + param_1[0x4b]);
          *(undefined2 *)(iVar8 + 0x1c + param_1[0x4b]) =
               *(undefined2 *)(iVar7 + 0x1c + param_1[0x4b]);
          *(undefined4 *)(iVar8 + 0x20 + param_1[0x4b]) =
               *(undefined4 *)(iVar7 + 0x20 + param_1[0x4b]);
          *(undefined4 *)(iVar8 + 0xc + param_1[0x4b]) =
               *(undefined4 *)(iVar7 + 0xc + param_1[0x4b]);
          sVar3 = sVar5;
        }
        sVar10 = sVar10 + 1;
        sVar5 = sVar3;
      } while (sVar10 < *(short *)((int)param_1 + 0x13a));
    }
    *(undefined2 *)(param_1 + 0x53) = 0xffff;
    *(undefined2 *)((int)param_1 + 0x14e) = 0xffff;
    (**(code **)(*param_1 + 0x20))(2);
    return;
  }
  param_1[0x3f] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00437069
// Address: 00437069
// XREFS: None
void __thiscall FUN_00437069(int *param_1,int param_2)
{
  param_1[0x3e] = param_2;
  (**(code **)(*param_1 + 0x20))(2);
  return;
}

// --------------------------------------------------

// Function: FUN_00437084
// Address: 00437084
// XREFS: None
void __thiscall FUN_00437084(TPanel *param_1,RedrawMode param_2)
{
  TPanel::set_redraw(param_1,param_2);
  if (param_2 == RedrawFull) {
    param_1[1].pnl_y = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004370b2
// Address: 004370b2
// XREFS: None
void __fastcall FUN_004370b2(int param_1)
{
  TDrawArea *this;
  
  this = *(TDrawArea **)(param_1 + 0x168);
  if ((this != (TDrawArea *)0x0) && (*(int *)(param_1 + 0x164) != 0)) {
    if (this != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(this);
      operator_delete(this);
    }
    *(undefined4 *)(param_1 + 0x168) = 0;
    *(undefined4 *)(param_1 + 0x164) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00437103
// Address: 00437103
// XREFS: None
undefined4 FUN_00437103(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00437115
// Address: 00437115
// XREFS: None
// [HELPER] s_Diamond_map__restored_: "Diamond map (restored)"
undefined4 __fastcall FUN_00437115(int param_1)
{
  TDrawArea *pTVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cf5b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(TDrawArea **)(param_1 + 0x168) == (TDrawArea *)0x0) {
    pTVar1 = (TDrawArea *)operator_new(0x100);
    uStack_4 = 0;
    if (pTVar1 == (TDrawArea *)0x0) {
      pTVar1 = (TDrawArea *)0x0;
    }
    else {
      pTVar1 = (TDrawArea *)TDrawArea::TDrawArea(pTVar1,s_Diamond_map__restored_,0);
    }
    uStack_4 = 0xffffffff;
    *(TDrawArea **)(param_1 + 0x168) = pTVar1;
    if (pTVar1 == (TDrawArea *)0x0) {
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
    iVar2 = TDrawArea::Init(pTVar1,(TDrawSystem *)**(undefined4 **)(param_1 + 0x20),
                            *(long *)(param_1 + 0x14),*(long *)(param_1 + 0x18),0,0);
    if (iVar2 == 0) {
      pTVar1 = *(TDrawArea **)(param_1 + 0x168);
      if (pTVar1 != (TDrawArea *)0x0) {
        TDrawArea::~TDrawArea(pTVar1);
        operator_delete(pTVar1);
      }
      *(undefined4 *)(param_1 + 0x168) = 0;
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
    *(undefined4 *)(param_1 + 0x164) = 1;
  }
  else if (*(int *)(param_1 + 0x164) != 0) {
    TDrawArea::SetSize(*(TDrawArea **)(param_1 + 0x168),*(long *)(param_1 + 0x14),
                       *(long *)(param_1 + 0x18),0);
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00437229
// Address: 00437229
// XREFS: None
undefined4 FUN_00437229(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00437235
// Address: 00437235
// XREFS: None
undefined4 FUN_00437235(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00437245
// Address: 00437245
// XREFS: None
undefined4 FUN_00437245(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00437255
// Address: 00437255
// XREFS: None
undefined4 FUN_00437255(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00437265
// Address: 00437265
// XREFS: None
undefined4 FUN_00437265(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00437275
// Address: 00437275
// XREFS: None
undefined4 FUN_00437275(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00437285
// Address: 00437285
// XREFS: None
undefined4 FUN_00437285(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00437295
// Address: 00437295
// XREFS: None
undefined4 FUN_00437295(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004372a5
// Address: 004372a5
// XREFS: None
undefined4 FUN_004372a5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004372b5
// Address: 004372b5
// XREFS: None
// [HELPER] s_diam_map__draw: "diam_map::draw"
void __fastcall FUN_004372b5(RGE_Diamond_Map *param_1)
{
  int iVar1;
  uchar *puVar2;
  
  if ((((param_1->_padding_ == 0) || (param_1->save_area == (TDrawArea *)0x0)) ||
      (param_1->_padding_ == 0)) || (param_1->_padding_ == 0)) {
    param_1->_padding_ = 0;
    return;
  }
  if (((param_1->map != (RGE_Map *)0x0) && (param_1->player != (RGE_Player *)0x0)) &&
     ((param_1->map_image_lines != (RGE_Map_Image_Line *)0x0 &&
      (param_1->map_tile_rows != (RGE_Map_Tile_Row *)0x0)))) {
    iVar1 = param_1->_padding_;
    (**(code **)(iVar1 + 0x28))(0);
    param_1->cur_player_bit = 1 << ((byte)param_1->world->curr_player & 0x1f);
    if (param_1->render_all == 0) {
      RGE_Diamond_Map::draw_explored_tiles(param_1);
    }
    else {
      if ((int *)param_1->_padding_ == (int *)0x0) {
        TDrawArea::Clear(param_1->save_area,(tagRECT *)0x0,
                         (uint)*(byte *)((int)&param_1->_padding_ + 3));
      }
      else {
        (**(code **)(*(int *)param_1->_padding_ + 0x34))(&param_1->_padding_);
        TDrawArea::Copy((TDrawArea *)param_1->_padding_,param_1->save_area,0,0,
                        (tagRECT *)&param_1->_padding_,0);
        RGE_Diamond_Map::clear_image(param_1);
      }
      RGE_Diamond_Map::draw_all_tiles(param_1);
      param_1->render_all = 0;
    }
    RGE_Diamond_Map::copy_image(param_1);
    if (rge_base_game->game_mode != 0x15) {
      (**(code **)(iVar1 + 0xe0))();
    }
    (**(code **)(iVar1 + 0xe4))();
    puVar2 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_diam_map__draw,1);
    if (puVar2 != (uchar *)0x0) {
      (**(code **)(iVar1 + 0xf0))();
      TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_diam_map__draw);
    }
    (**(code **)(iVar1 + 0x2c))();
    RGE_Tile_List::del_list(&param_1->player->diam_tile_list);
    return;
  }
  iVar1 = param_1->_padding_;
  (**(code **)(iVar1 + 0x28))(0);
  if (param_1->map_image_lines != (RGE_Map_Image_Line *)0x0) {
    RGE_Diamond_Map::clear_image(param_1);
    RGE_Diamond_Map::copy_image(param_1);
    (**(code **)(iVar1 + 0x2c))();
    return;
  }
  if ((int *)param_1->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1->_padding_ + 0x34))(&param_1->_padding_);
    (**(code **)(iVar1 + 0x2c))();
    return;
  }
  TDrawArea::Clear((TDrawArea *)param_1->_padding_,(tagRECT *)&param_1->_padding_,
                   (uint)*(byte *)((int)&param_1->_padding_ + 3));
  (**(code **)(iVar1 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_00437482
// Address: 00437482
// XREFS: None
undefined4 FUN_00437482(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00437495
// Address: 00437495
// XREFS: None
undefined4 FUN_00437495(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004374a5
// Address: 004374a5
// XREFS: None
undefined4 FUN_004374a5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004374b5
// Address: 004374b5
// XREFS: None
// [HELPER] s_diam_map__clear_image: "diam_map::clear_image"
void __fastcall FUN_004374b5(int param_1)
{
  short sVar1;
  short sVar2;
  uchar *puVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  short *psVar9;
  int iStack_8;
  
  puVar3 = TDrawArea::Lock(*(TDrawArea **)(param_1 + 0x168),s_diam_map__clear_image,1);
  if (puVar3 != (uchar *)0x0) {
    iVar4 = *(int *)(param_1 + 0x168);
    sVar5 = *(short *)(param_1 + 0x134);
    if (*(int *)(iVar4 + 0x24) == 1) {
      sVar1 = *(short *)(iVar4 + 0x20);
      iVar8 = (int)sVar5 * *(int *)(iVar4 + 0x20) + *(int *)(iVar4 + 8);
    }
    else {
      iVar8 = ((*(int *)(iVar4 + 0x1c) - (int)sVar5) + -1) * *(int *)(iVar4 + 0x20) +
              *(int *)(iVar4 + 8);
      sVar1 = -*(short *)(iVar4 + 0x20);
    }
    sVar5 = *(short *)(param_1 + 0x10) + sVar5;
    sVar7 = *(short *)(param_1 + 0x138) + sVar5;
    if (sVar5 < sVar7) {
      psVar9 = (short *)(*(int *)(param_1 + 0x128) + 4);
      iVar4 = (int)sVar5;
      iStack_8 = sVar7 - iVar4;
      do {
        if ((*(int *)(param_1 + 0x28) <= iVar4) && (iVar4 <= *(int *)(param_1 + 0x30))) {
          sVar5 = psVar9[-1];
          sVar2 = *(short *)(param_1 + 0xc) + sVar5;
          sVar6 = sVar2 + *psVar9 + -1;
          sVar7 = sVar2;
          if ((int)sVar2 < *(int *)(param_1 + 0x24)) {
            sVar7 = *(short *)(param_1 + 0x24);
            sVar5 = sVar5 + (sVar7 - sVar2);
          }
          if (*(int *)(param_1 + 0x2c) < (int)sVar6) {
            sVar6 = *(short *)(param_1 + 0x2c);
          }
          if ((*(int *)(param_1 + 0x24) <= (int)sVar7) && ((int)sVar6 <= *(int *)(param_1 + 0x2c)))
{
            memset(iVar8 + sVar5,*(undefined1 *)(param_1 + 0xef),((int)sVar6 - (int)sVar7) + 1);
          }
        }
        psVar9 = psVar9 + 3;
        iVar8 = iVar8 + sVar1;
        iVar4 = iVar4 + 1;
        iStack_8 = iStack_8 + -1;
      } while (iStack_8 != 0);
    }
    TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x168),s_diam_map__clear_image);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043760e
// Address: 0043760e
// XREFS: None
void FUN_0043760e(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00437611
// Address: 00437611
// XREFS: None
void __fastcall FUN_00437611(int param_1)
{
  tagRECT tStack_10;
  
  tStack_10.right = *(int *)(param_1 + 0x14) + -1;
  tStack_10.left = 0;
  tStack_10.bottom = *(int *)(param_1 + 0x18) + -1;
  tStack_10.top = 0;
  TDrawArea::Copy(*(TDrawArea **)(param_1 + 0x168),*(TDrawArea **)(param_1 + 0x20),
                  *(long *)(param_1 + 0xc),*(long *)(param_1 + 0x10),&tStack_10,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0043765e
// Address: 0043765e
// XREFS: None
// [HELPER] s_diam_map__draw_all_tiles: "diam_map::draw_all_tiles"
void __fastcall FUN_0043765e(RGE_Diamond_Map *param_1)
{
  uchar *puVar1;
  short sVar2;
  short sVar3;
  
  puVar1 = TDrawArea::Lock(param_1->save_area,s_diam_map__draw_all_tiles,1);
  if (puVar1 != (uchar *)0x0) {
    sVar2 = 0;
    if (0 < param_1->map_hgt) {
      do {
        sVar3 = 0;
        if (0 < param_1->map_wid) {
          do {
            RGE_Diamond_Map::draw_tile(param_1,sVar3,sVar2,0,'\0');
            sVar3 = sVar3 + 1;
          } while (sVar3 < param_1->map_wid);
        }
        sVar2 = sVar2 + 1;
      } while (sVar2 < param_1->map_hgt);
    }
    TDrawArea::Unlock(param_1->save_area,s_diam_map__draw_all_tiles);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004376c6
// Address: 004376c6
// XREFS: None
// [HELPER] s_diam_map__draw_explored_tiles: "diam_map::draw_explored_tiles"
void __fastcall FUN_004376c6(RGE_Diamond_Map *param_1)
{
  uchar *puVar1;
  int iVar2;
  RGE_Tile_List_Node *pRStack_8;
  int iStack_4;
  
  RGE_Tile_List::get_list_info(&param_1->player->diam_tile_list,&pRStack_8,&iStack_4);
  if ((0 < iStack_4) &&
     (puVar1 = TDrawArea::Lock(param_1->save_area,s_diam_map__draw_explored_tiles,1),
     puVar1 != (uchar *)0x0)) {
    iVar2 = 0;
    if (0 < iStack_4) {
      do {
        RGE_Diamond_Map::draw_tile(param_1,(short)pRStack_8->col,(short)pRStack_8->row,0,'\0');
        iVar2 = iVar2 + 1;
        pRStack_8 = pRStack_8 + 1;
      } while (iVar2 < iStack_4);
    }
    TDrawArea::Unlock(param_1->save_area,s_diam_map__draw_explored_tiles);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00437759
// Address: 00437759
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00437759(int param_1,short param_2,short param_3,int param_4,uchar param_5)
{
  int iVar1;
  short *psVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  short sVar7;
  int *piVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float10 extraout_ST0;
  
  iVar11 = (int)param_3;
  iVar12 = (int)param_2;
  psVar2 = (short *)(*(int *)(param_1 + 300) + -0x24 +
                    ((iVar11 + *(short *)(param_1 + 0x130)) - iVar12) * 0x24);
  if ((char)psVar2[1] == '\0') {
    return;
  }
  iVar4 = *(int *)(param_1 + 0xfc);
  iVar5 = *(int *)(iVar4 + 0x8d8c);
  iVar1 = *(int *)(iVar5 + iVar11 * 4) + iVar12 * 0x18;
  if ((*(char *)(iVar4 + 0x8db8) == '\0') &&
     ((*(uint *)(*(int *)(param_1 + 0xf8) + 0xd0) & (uint)(&unified_map_offsets)[iVar11][iVar12]) ==
      0)) {
    return;
  }
  bVar6 = false;
  if (_DAT_0056f604 <= *(float *)(psVar2 + 0x10)) {
    sVar7 = __ftol();
  }
  else {
    sVar7 = __ftol();
    if ((float10)*(float *)(psVar2 + 0x10) <= extraout_ST0 - (float10)(int)sVar7) goto LAB_0043785b;
  }
  bVar6 = true;
LAB_0043785b:
  if (bVar6) {
    iVar13 = (int)*(short *)(*(int *)(param_1 + 0x128) + 2 + *psVar2 * 6) + (int)sVar7;
    iVar10 = (int)*(short *)(param_1 + 0x134) + (int)*psVar2;
    bVar3 = *(byte *)(iVar1 + 5);
    if (param_4 == 0) {
      if (param_5 == '\0') {
        param_5 = '\0';
        switch(*(undefined1 *)(iVar1 + 4)) {
        case 0:
          param_5 = *(uchar *)(iVar4 + 0xb5 + (bVar3 & 0x1f) * 0x198);
          break;
        case 1:
        case 4:
        case 5:
        case 7:
        case 8:
        case 9:
        case 0xc:
        case 0xd:
        case 0xf:
          param_5 = *(uchar *)(iVar4 + 0xb6 + (bVar3 & 0x1f) * 0x198);
          break;
        case 2:
        case 3:
        case 6:
        case 10:
        case 0xb:
        case 0xe:
        case 0x10:
          param_5 = *(uchar *)(iVar4 + 0xb4 + (bVar3 & 0x1f) * 0x198);
        }
      }
      for (param_3 = param_3 + -1; (int)param_3 < iVar11 + 2; param_3 = param_3 + 1) {
        if ((-1 < param_3) && (param_3 < *(short *)(param_1 + 0x132))) {
          sVar7 = param_2 + -1;
          while ((int)sVar7 < iVar12 + 2) {
            if (((sVar7 < 0) || (*(short *)(param_1 + 0x130) <= sVar7)) ||
               (piVar8 = *(int **)(*(int *)(iVar5 + param_3 * 4) + 0x10 + sVar7 * 0x18),
               piVar8 == (int *)0x0)) {
LAB_004379bb:
              sVar7 = sVar7 + 1;
            }
            else {
              do {
                if (*(char *)(*(int *)(*piVar8 + 8) + 0x8e) == '\x04') {
                  param_5 = *(uchar *)(*(int *)(*piVar8 + 8) + 0x90);
                  goto LAB_004379bb;
                }
                piVar8 = (int *)piVar8[1];
              } while (piVar8 != (int *)0x0);
              sVar7 = sVar7 + 1;
            }
          }
        }
      }
      sVar7 = psVar2[10];
      if (*(short *)(param_1 + 0x148) == 1) {
        if (sVar7 == 1) {
          TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x168),iVar13,iVar10,param_5);
          return;
        }
        if (sVar7 == 2) {
          TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x168),iVar13,iVar10,param_5);
          TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x168),iVar13 + 1,iVar10,param_5);
          return;
        }
        if (0 < sVar7) {
          iVar11 = (int)sVar7;
          do {
            TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x168),iVar13,iVar10,param_5);
            iVar13 = iVar13 + 1;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
          return;
        }
      }
      else {
        sVar9 = 0;
        if (0 < *(short *)(param_1 + 0x148)) {
          do {
            if (0 < sVar7) {
              iVar12 = (int)sVar7;
              iVar11 = iVar13;
              do {
                TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x168),iVar11,iVar10 + sVar9,param_5);
                iVar11 = iVar11 + 1;
                iVar12 = iVar12 + -1;
              } while (iVar12 != 0);
            }
            sVar9 = sVar9 + 1;
          } while (sVar9 < *(short *)(param_1 + 0x148));
          return;
        }
      }
    }
    else {
      iVar10 = iVar10 + *(int *)(param_1 + 0x10);
      sVar7 = psVar2[10];
      iVar13 = iVar13 + *(int *)(param_1 + 0xc);
      if (*(short *)(param_1 + 0x148) == 1) {
        if (sVar7 == 1) {
          TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x20),iVar13,iVar10,
                              *(uchar *)(param_1 + 0x158));
          return;
        }
        if (sVar7 == 2) {
          TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x20),iVar13,iVar10,
                              *(uchar *)(param_1 + 0x158));
          TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x20),iVar13 + 1,iVar10,
                              *(uchar *)(param_1 + 0x158));
          return;
        }
        if (0 < sVar7) {
          iVar11 = (int)sVar7;
          do {
            TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x20),iVar13,iVar10,
                                *(uchar *)(param_1 + 0x158));
            iVar13 = iVar13 + 1;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
          return;
        }
      }
      else {
        sVar9 = 0;
        if (0 < *(short *)(param_1 + 0x148)) {
          do {
            if (0 < sVar7) {
              iVar12 = (int)sVar7;
              iVar11 = iVar13;
              do {
                TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x20),iVar11,iVar10 + sVar9,
                                    *(uchar *)(param_1 + 0x158));
                iVar11 = iVar11 + 1;
                iVar12 = iVar12 + -1;
              } while (iVar12 != 0);
            }
            sVar9 = sVar9 + 1;
          } while (sVar9 < *(short *)(param_1 + 0x148));
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00437bd9
// Address: 00437bd9
// XREFS: None
void FUN_00437bd9(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00437cb3
// Address: 00437cb3
// XREFS: None
// [HELPER] s_diam_map__draw_objects: "diam_map::draw_objects"
void __fastcall FUN_00437cb3(int *param_1)
{
  undefined1 uVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  uchar *puVar5;
  int iVar6;
  short sVar7;
  short sVar8;
  
  puVar5 = TDrawArea::Lock((TDrawArea *)param_1[8],s_diam_map__draw_objects,1);
  if (puVar5 != (uchar *)0x0) {
    param_1[0x57] = 1;
    for (piVar2 = *(int **)(*(int *)(**(int **)(param_1[0x3d] + 0x40) + 0x28) + 4);
        piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
      if (*piVar2 != 0) {
        (**(code **)(*param_1 + 0xe8))(*piVar2,0xff,0xff);
      }
    }
    iVar6 = param_1[0x3d];
    param_1[0x57] = 2;
    sVar7 = 1;
    if (1 < *(short *)(iVar6 + 0x3c)) {
      do {
        iVar6 = *(int *)(*(int *)(iVar6 + 0x40) + sVar7 * 4);
        uVar1 = *(undefined1 *)(*(int *)(iVar6 + 0x108) + 0x25);
        for (piVar2 = *(int **)(*(int *)(iVar6 + 0x30) + 4); piVar2 != (int *)0x0;
            piVar2 = (int *)piVar2[1]) {
          if (*piVar2 != 0) {
            (**(code **)(*param_1 + 0xe8))(*piVar2,uVar1,uVar1);
          }
        }
        for (piVar2 = *(int **)(*(int *)(iVar6 + 0x28) + 4); piVar2 != (int *)0x0;
            piVar2 = (int *)piVar2[1]) {
          piVar3 = (int *)*piVar2;
          if (((piVar3 != (int *)0x0) && ((*(byte *)((int)piVar3 + 0x36) & 1) == 0)) &&
             ((piVar3[3] != param_1[0x3e] ||
              (cVar4 = (**(code **)(*piVar3 + 0xe8))(), cVar4 == '\0')))) {
            (**(code **)(*param_1 + 0xe8))(piVar3,uVar1,uVar1);
          }
        }
        iVar6 = param_1[0x3d];
        sVar7 = sVar7 + 1;
      } while (sVar7 < *(short *)(iVar6 + 0x3c));
    }
    if (0 < *(short *)(param_1[0x3e] + 0x19c)) {
      sVar8 = 0;
      param_1[0x57] = 3;
      sVar7 = 0;
      do {
        if (*(short *)(param_1[0x3e] + 0x19c) <= sVar7) break;
        iVar6 = *(int *)(param_1[0x3e] + 0x134 + sVar8 * 4);
        if (iVar6 != 0) {
          (**(code **)(*param_1 + 0xe8))(iVar6,0xff,0xff);
          sVar7 = sVar7 + 1;
        }
        sVar8 = sVar8 + 1;
      } while (sVar8 < 0x19);
    }
    param_1[0x57] = 4;
    uVar1 = *(undefined1 *)(*(int *)(param_1[0x3e] + 0x108) + 0x25);
    for (piVar2 = *(int **)(*(int *)(param_1[0x3e] + 0x28) + 4); piVar2 != (int *)0x0;
        piVar2 = (int *)piVar2[1]) {
      piVar3 = (int *)*piVar2;
      if ((piVar3 != (int *)0x0) && (cVar4 = (**(code **)(*piVar3 + 0xe8))(), cVar4 != '\0')) {
        (**(code **)(*param_1 + 0xe8))(piVar3,uVar1,uVar1);
      }
    }
    TDrawArea::Unlock((TDrawArea *)param_1[8],s_diam_map__draw_objects);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00437eb2
// Address: 00437eb2
// XREFS: None
void __thiscall FUN_00437eb2(int *param_1,int param_2,undefined1 param_3,undefined1 param_4)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  char cVar6;
  undefined4 uVar7;
  
  iVar2 = param_2;
  if (*(int *)(param_2 + 0x1c) == 0) {
    return;
  }
  uVar3 = __ftol();
  uVar4 = __ftol();
  iVar5 = param_1[0x3e];
  if (*(int *)(iVar5 + 0x38) == 0) {
LAB_00437f58:
    cVar6 = '\x0f';
  }
  else {
    iVar1 = param_1[0x3f];
    if ((*(char *)(iVar1 + 0x8db8) != '\0') && (*(char *)(iVar1 + 0x8db9) == '\0'))
    goto LAB_00437f58;
    param_2._0_2_ = (short)uVar3;
    cVar6 = '\0';
    if ((*(uint *)(iVar5 + 0xd0) & (uint)(&unified_map_offsets)[(short)uVar4][(short)param_2]) != 0)
{
      cVar6 = -0x80;
    }
    if ((*(uint *)(iVar5 + 0xd4) & (uint)(&unified_map_offsets)[(short)uVar4][(short)param_2]) != 0)
{
      cVar6 = '\x0f';
    }
    if ((*(char *)(iVar1 + 0x8db8) != '\0') && (cVar6 == '\0')) {
      cVar6 = -0x80;
    }
    if ((*(char *)(iVar1 + 0x8db9) == '\0') && (cVar6 == -0x80)) goto LAB_00437f58;
  }
  if ((cVar6 == '\x0f') || ((cVar6 == -0x80 && (*(char *)(*(int *)(iVar2 + 8) + 0x65) != '\0')))) {
    if (*(char *)(iVar2 + 0x4e) == '\x19') {
      if (cVar6 == '\x0f') {
        return;
      }
      if ((*(int *)(iVar5 + 0xac + *(short *)(*(int *)(iVar2 + 0xc) + 0x4a) * 4) == 1) &&
         ((param_1[0x58] & *(uint *)(iVar2 + 0xa4)) == 0)) {
        cVar6 = *(char *)(iVar2 + 0xa8);
        param_3 = *(undefined1 *)(iVar2 + 0xa9);
        param_4 = param_3;
      }
      else {
        param_3 = 0xff;
        cVar6 = '\0';
        param_4 = 0xff;
      }
    }
    else {
      cVar6 = *(char *)(*(int *)(iVar2 + 8) + 0x8e);
      if (cVar6 == '\x03') {
        param_3 = *(undefined1 *)(*(int *)(iVar2 + 8) + 0x90);
      }
    }
    switch(cVar6) {
    default:
      goto switchD_00437ffe_caseD_0;
    case '\x01':
      iVar5 = *param_1;
      uVar7 = 1;
      break;
    case '\x02':
      (**(code **)(*param_1 + 0xec))(uVar3,uVar4,param_3,2,iVar2);
      return;
    case '\x03':
      iVar5 = *param_1;
      uVar7 = 2;
      param_4 = param_3;
    }
    (**(code **)(iVar5 + 0xec))(uVar3,uVar4,param_4,uVar7,iVar2);
  }
switchD_00437ffe_caseD_0:
  return;
}

// --------------------------------------------------

// Function: FUN_0043804d
// Address: 0043804d
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0043804d(int param_1,undefined4 param_2,short param_3,short param_4,uchar param_5,short param_6)
{
  short sVar1;
  short sVar2;
  char *unaff_EBX;
  int iVar3;
  int iVar4;
  
  *unaff_EBX = *unaff_EBX + '%';
  *unaff_EBX = *unaff_EBX + '\x05';
  *unaff_EBX = *unaff_EBX + '-';
  *unaff_EBX = *unaff_EBX + 'S';
  sVar2 = *(short *)(param_1 + 0x130);
  iVar3 = *(int *)(param_1 + 300);
  sVar1 = __ftol();
  sVar2 = *(short *)(iVar3 + -0x24 + (((int)sVar2 + (int)param_4) - (int)param_3) * 0x24);
  sVar1 = *(short *)(*(int *)(param_1 + 0x128) + 2 + sVar2 * 6) + *(short *)(param_1 + 0xc) + sVar1;
  sVar2 = *(short *)(param_1 + 0x10) + *(short *)(param_1 + 0x134) + sVar2;
  if (param_6 == 1) {
    TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),sVar1 + -1,sVar2 + -1,sVar1 + 1,sVar2 + 1,
                        param_5);
    return;
  }
  if (param_6 != 2) {
    if (param_6 == 3) {
      iVar4 = (int)sVar2;
      iVar3 = (int)sVar1;
      TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),iVar3 + -3,iVar4,iVar3 + 3,iVar4 + 1,
                          param_5);
      TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),iVar3 + -2,iVar4 + -1,iVar3 + 2,iVar4 + 2,
                          param_5);
      return;
    }
    if (param_6 == 4) {
      TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),sVar1 + -2,sVar2 + -2,sVar1 + 2,sVar2 + 2,
                          param_5);
    }
    return;
  }
  iVar4 = (int)sVar2;
  iVar3 = (int)sVar1;
  TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),iVar3,iVar4 + -1,iVar3,iVar4 + 1,param_5);
  TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),iVar3 + -1,iVar4,iVar3 + 1,iVar4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_004381cd
// Address: 004381cd
// XREFS: None
void __thiscall
FUN_004381cd(int param_1,short param_2,short param_3,short param_4,uchar param_5,int param_6)
{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)(param_6 + 2);
  iVar2 = *(int *)(param_1 + 0xc) + (int)sVar1;
  if (param_2 < iVar2) {
    param_2 = *(short *)(param_1 + 0xc) + sVar1;
  }
  if (*(short *)(param_6 + 4) + iVar2 <= param_4 + -1 + (int)param_2) {
    param_4 = (*(short *)(param_1 + 0xc) - param_2) + *(short *)(param_6 + 4) + sVar1;
  }
  TDrawArea::DrawHorzLine
            (*(TDrawArea **)(param_1 + 0x20),(int)param_2,(int)param_3,(int)param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0043824b
// Address: 0043824b
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0043824b(int param_1)
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float fStack_10;
  int iStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
  sVar1 = __ftol();
  uStack_8 = __ftol();
  sVar2 = (short)uStack_8;
  if ((sVar1 != *(short *)(param_1 + 0x14c)) || (sVar2 != *(short *)(param_1 + 0x14e))) {
    if (sVar1 < 0) {
      return;
    }
    if (*(int *)(*(int *)(param_1 + 0xfc) + 8) <= (int)sVar1) {
      return;
    }
    if (sVar2 < 0) {
      return;
    }
    if (*(int *)(*(int *)(param_1 + 0xfc) + 0xc) <= (int)sVar2) {
      return;
    }
    sVar2 = *(short *)(param_1 + 0x130);
    sVar3 = __ftol();
    sVar4 = __ftol();
    iVar5 = *(int *)(param_1 + 300);
    sVar8 = (short)uStack_8;
    if (sVar1 < (short)uStack_8) {
      sVar8 = sVar1;
    }
    iStack_c = (int)sVar8;
    __ftol();
    sVar2 = *(short *)(iVar5 + (((int)sVar2 - (int)sVar3) + -1 + (int)sVar4) * 0x24);
    sVar8 = *(short *)(param_1 + 0x10);
    sVar3 = *(short *)(param_1 + 0x134);
    RGE_View::get_max_size(*(RGE_View **)(param_1 + 0x150),(short *)&fStack_10,(short *)&iStack_c);
    iVar5 = (int)fStack_10._0_2_;
    iStack_4 = iVar5 / 2;
    uVar6 = __ftol();
    *(undefined4 *)(param_1 + 0x114) = uVar6;
    iVar10 = (int)(short)iStack_c;
    fStack_10 = (float)(int)(short)(sVar8 + sVar3 + sVar2);
    iStack_4 = iVar10;
    uVar6 = __ftol();
    iStack_4 = iVar5 / 2 + 2;
    *(undefined4 *)(param_1 + 0x118) = uVar6;
    uVar6 = __ftol();
    iStack_4 = iVar10 + 4;
    *(undefined4 *)(param_1 + 0x11c) = uVar6;
    uVar6 = __ftol();
    *(undefined4 *)(param_1 + 0x120) = uVar6;
    *(short *)(param_1 + 0x14c) = sVar1;
    *(undefined2 *)(param_1 + 0x14e) = (undefined2)uStack_8;
  }
  iVar5 = *(int *)(param_1 + 0x118);
  iVar10 = *(int *)(param_1 + 0x120);
  if (iVar5 <= iVar10) {
    do {
      iVar11 = *(int *)(param_1 + 0x10) + (int)*(short *)(param_1 + 0x134);
      if ((iVar11 <= iVar5) && (iVar5 <= *(short *)(param_1 + 0x138) + -1 + iVar11)) {
        iVar11 = *(int *)(param_1 + 0x11c);
        iVar9 = *(int *)(param_1 + 0x128) +
                ((iVar5 - *(short *)(param_1 + 0x134)) - *(int *)(param_1 + 0x10)) * 6;
        iVar7 = *(int *)(param_1 + 0x114);
        if ((iVar5 == *(int *)(param_1 + 0x118)) || (iVar5 == iVar10)) {
          iVar10 = (int)*(short *)(iVar9 + 2) + *(int *)(param_1 + 0xc);
          iVar9 = *(short *)(iVar9 + 4) + iVar10;
          if ((iVar7 < iVar9) && (iVar10 <= iVar11)) {
            if (iVar7 < iVar10) {
              iVar7 = iVar10;
            }
            if (iVar9 <= iVar11) {
              iVar11 = iVar9 + -1;
            }
            TDrawArea::DrawHorzLine
                      (*(TDrawArea **)(param_1 + 0x20),iVar7,iVar5,(iVar11 - iVar7) + 1,0xff);
          }
        }
        else {
          iVar10 = (int)*(short *)(iVar9 + 2) + *(int *)(param_1 + 0xc);
          if ((iVar7 < *(short *)(iVar9 + 4) + iVar10) && (iVar10 <= iVar7)) {
            TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x20),iVar7,iVar5,0xff);
          }
          iVar10 = (int)*(short *)(iVar9 + 2) + *(int *)(param_1 + 0xc);
          if ((iVar11 < *(short *)(iVar9 + 4) + iVar10) && (iVar10 <= iVar11)) {
            TDrawArea::SetPixel(*(TDrawArea **)(param_1 + 0x20),iVar11,iVar5,0xff);
          }
        }
      }
      iVar10 = *(int *)(param_1 + 0x120);
      iVar5 = iVar5 + 1;
    } while (iVar5 <= iVar10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043852c
// Address: 0043852c
// XREFS: None
undefined4 __thiscall
FUN_0043852c(int param_1,int param_2,int param_3,short *param_4,short *param_5,int *param_6)
{
  short *psVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  
  if ((*(int *)(param_1 + 0xfc) != 0) && (iVar2 = *(int *)(param_1 + 0x128), iVar2 != 0)) {
    param_3 = param_3 - *(int *)(param_1 + 0x10);
    param_2 = param_2 - *(int *)(param_1 + 0xc);
    iVar5 = (int)*(short *)(param_1 + 0x134);
    if ((iVar5 <= param_3) && (param_3 <= *(short *)(param_1 + 0x138) + -1 + iVar5)) {
      iVar6 = (int)*(short *)(iVar2 + 2 + (param_3 - iVar5) * 6);
      psVar1 = (short *)(iVar2 + (param_3 - iVar5) * 6);
      if ((iVar6 <= param_2) && (param_2 <= psVar1[2] + -1 + iVar6)) {
        iVar2 = *(int *)(param_1 + 300) + *psVar1 * 0x24;
        sVar3 = __ftol();
        sVar4 = *(short *)(iVar2 + 0x10) + sVar3;
        sVar3 = *(short *)(iVar2 + 0x12) + sVar3;
        if (param_4 != (short *)0x0) {
          *param_4 = sVar4;
        }
        if (param_5 != (short *)0x0) {
          *param_5 = sVar3;
        }
        if (param_6 != (int *)0x0) {
          *param_6 = *(int *)(*(int *)(*(int *)(param_1 + 0xfc) + 0x8d8c) + sVar3 * 4) +
                     sVar4 * 0x18;
        }
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00438626
// Address: 00438626
// XREFS: None
undefined4 __thiscall FUN_00438626(RGE_Diamond_Map *param_1,long param_2,long param_3)
{
  TPanel::handle_size((TPanel *)param_1,param_2,param_3);
  param_1->view_col = -1;
  param_1->view_row = -1;
  RGE_Diamond_Map::create_surfaces(param_1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00438662
// Address: 00438662
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00438662(RGE_Diamond_Map *param_1,long param_2,long param_3)
{
  float fVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  RGE_Tile *pRStack_4;
  
  lVar3 = param_3;
  lVar2 = param_2;
  iVar4 = RGE_Diamond_Map::pick_tile
                    (param_1,param_2,param_3,(short *)&param_2,(short *)&param_3,&pRStack_4);
  if (iVar4 != 0) {
    TPanel::capture_mouse((TPanel *)param_1);
    fVar1 = (float)(int)(short)param_3 - _DAT_0056f608;
    param_1->scrolling = 1;
    RGE_Player::set_view_loc(param_1->player,(float)(int)(short)param_2 - _DAT_0056f608,fVar1);
    (**(code **)(param_1->_padding_ + 0x20))(1);
    if (param_1->main_view != (RGE_View *)0x0) {
      (**(code **)(param_1->main_view->_padding_ + 0x20))(1);
    }
    param_1->mouse_last_x = lVar2;
    param_1->mouse_last_y = lVar3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00438715
// Address: 00438715
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00438715(RGE_Diamond_Map *param_1,long param_2,long param_3)
{
  long lVar1;
  long lVar2;
  int iVar3;
  RGE_Tile *pRStack_4;
  
  lVar2 = param_3;
  lVar1 = param_2;
  iVar3 = RGE_Diamond_Map::pick_tile
                    (param_1,param_2,param_3,(short *)&param_2,(short *)&param_3,&pRStack_4);
  if (iVar3 != 0) {
    RGE_Player::set_view_loc
              (param_1->player,(float)(int)(short)param_2 - _DAT_0056f608,
               (float)(int)(short)param_3 - _DAT_0056f608);
    (**(code **)(param_1->_padding_ + 0x20))(1);
    if (param_1->main_view != (RGE_View *)0x0) {
      (**(code **)(param_1->main_view->_padding_ + 0x20))(1);
    }
    param_1->mouse_last_x = lVar1;
    param_1->mouse_last_y = lVar2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004387b4
// Address: 004387b4
// XREFS: None
void __fastcall FUN_004387b4(TPanel *param_1)
{
  param_1[1].tab_prev_panel = (TPanel *)0x0;
  TPanel::release_mouse(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004387cf
// Address: 004387cf
// XREFS: None
int __thiscall FUN_004387cf(RGE_Diamond_Map *param_1,long param_2,long param_3)
{
  long lVar1;
  long lVar2;
  int iVar3;
  RGE_Diamond_Map *pRStack_4;
  
  lVar2 = param_3;
  lVar1 = param_2;
  pRStack_4 = param_1;
  iVar3 = TPanel::is_inside((TPanel *)param_1,param_2,param_3);
  if (iVar3 != 0) {
    iVar3 = RGE_Diamond_Map::pick_tile
                      (param_1,lVar1,lVar2,(short *)&param_2,(short *)&param_3,
                       (RGE_Tile **)&pRStack_4);
    return iVar3;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00438811
// Address: 00438811
// XREFS: None
void FUN_00438811(BITMAPINFO256 *param_1,int param_2,tagRECT *param_3,int param_4,int param_5,
                 int param_6,int param_7,BITMAPINFO256 *param_8,int param_9,int param_10,
                 int param_11,int param_12,int param_13,int param_14,int param_15,int param_16)
{
  long *plVar1;
  BITMAPINFO256 *pBVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long **pplVar7;
  int iVar8;
  int iStack_8;
  int iStack_4;
  
  iVar8 = param_16;
  pBVar2 = param_1;
  if ((param_14 != 0) &&
     (iVar3 = ClipDibBlt(param_1,param_3,&param_4,&param_5,&param_6,&param_7,&param_10,&param_11,
                         &param_12,&param_13,param_15,param_16), iVar3 == 0)) {
    return;
  }
  GetDibDim(pBVar2,&param_14,&iStack_4,&iStack_8);
  GetDibDim(param_8,&param_16,(long *)&param_3,(long *)&param_1);
  if (iVar8 != 0) {
    param_1 = (BITMAPINFO256 *)-(int)param_1;
  }
  iVar3 = (param_12 << 8) / param_6;
  iVar4 = (param_13 << 8) / param_7;
  iVar8 = param_5;
  if (iStack_8 != 1) {
    iVar8 = (iStack_4 - param_5) + -1;
  }
  iVar8 = param_14 * iVar8 + param_4 + param_2;
  if ((iVar3 == 0x100) && (iVar4 == 0x100)) {
    if (param_15 == 0) {
      iVar3 = param_11;
      if (param_1 != (BITMAPINFO256 *)0x1) {
        iVar3 = (int)param_3 + (-1 - param_11);
      }
      iVar3 = param_16 * iVar3;
      param_14 = iStack_8 * param_14;
      param_16 = (int)param_1 * param_16;
      iVar4 = iVar3 + param_10 + param_9;
      iVar3 = 0;
      if (param_7 < 1) {
        return;
      }
      param_8 = (BITMAPINFO256 *)0x100;
      do {
        memcpy(iVar8,iVar4,param_6);
        iVar8 = iVar8 + param_14;
        iVar4 = iVar4 + param_16;
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_7);
      return;
    }
  }
  else if (param_15 == 0) {
    if (0 < param_6) {
      pplVar7 = &SrcXTbl;
      iVar5 = param_10;
      iVar6 = param_6;
      do {
        *pplVar7 = (long *)(iVar5 >> 8);
        iVar5 = iVar5 + iVar3;
        iVar6 = iVar6 + -1;
        pplVar7 = pplVar7 + 1;
      } while (iVar6 != 0);
    }
    goto LAB_00438a00;
  }
  if (-1 < param_6 + -1) {
    pplVar7 = &SrcXTbl + param_6 + -1;
    iVar5 = param_10;
    iVar6 = param_6;
    do {
      *pplVar7 = (long *)(iVar5 >> 8);
      iVar5 = iVar5 + iVar3;
      iVar6 = iVar6 + -1;
      pplVar7 = pplVar7 + -1;
    } while (iVar6 != 0);
  }
LAB_00438a00:
  param_11 = param_11 << 8;
  param_15 = 0;
  if (0 < param_7) {
    do {
      iVar3 = param_11 >> 8;
      if (param_1 != (BITMAPINFO256 *)0x1) {
        iVar3 = (int)param_3 + (-1 - iVar3);
      }
      if (0 < param_6) {
        pplVar7 = &SrcXTbl;
        iVar5 = 0;
        do {
          plVar1 = *pplVar7;
          iVar6 = iVar5 + 1;
          pplVar7 = pplVar7 + 1;
          *(undefined1 *)(iVar5 + iVar8) =
               *(undefined1 *)(iVar3 * param_16 + param_10 + param_9 + (int)plVar1);
          iVar5 = iVar6;
        } while (iVar6 < param_6);
      }
      param_11 = param_11 + iVar4;
      iVar8 = iVar8 + iStack_8 * param_14;
      param_15 = param_15 + 1;
    } while (param_15 < param_7);
  }
  return;
}

// --------------------------------------------------

// Function: DibBlt
// Address: 00438820
// XREFS: Copy, DibWriteClipped, Draw, TileDibBlt, TransDibBlt
/* WARNING: Variable defined which should be unmapped: DestOrien */
/* void __cdecl DibBlt(struct BITMAPINFO256 *,unsigned char *,struct tagRECT
   *,long,long,long,long,struct BITMAPINFO256 *,unsigned char *,long,long,long,long,int,int,int) */

void __cdecl
DibBlt(BITMAPINFO256 *param_1,uchar *param_2,tagRECT *param_3,long param_4,long param_5,long param_6
      ,long param_7,BITMAPINFO256 *param_8,uchar *param_9,long param_10,long param_11,long param_12,
      long param_13,int param_14,int param_15,int param_16)
{
  long *plVar1;
  BITMAPINFO256 *pBVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  uchar *puVar10;
  long **pplVar11;
  uchar *puVar12;
  long DestOrien;
  long DestTotHgt;
  int local_4;
  
  iVar9 = param_16;
  pBVar2 = param_1;
  if ((param_14 != 0) &&
     (iVar3 = ClipDibBlt(param_1,param_3,&param_4,&param_5,&param_6,&param_7,&param_10,&param_11,
                         &param_12,&param_13,param_15,param_16), iVar3 == 0)) {
    return;
  }
  GetDibDim(pBVar2,&param_14,&local_4,&DestTotHgt);
  GetDibDim(param_8,&param_16,(long *)&param_3,(long *)&param_1);
  if (iVar9 != 0) {
    param_1 = (BITMAPINFO256 *)-(int)param_1;
  }
  iVar3 = (param_12 << 8) / param_6;
  iVar4 = (param_13 << 8) / param_7;
  iVar9 = param_5;
  if (DestTotHgt != 1) {
    iVar9 = (local_4 - param_5) + -1;
  }
  puVar12 = param_2 + param_14 * iVar9 + param_4;
  if ((iVar3 == 0x100) && (iVar4 == 0x100)) {
    if (param_15 == 0) {
      iVar9 = param_11;
      if (param_1 != (BITMAPINFO256 *)0x1) {
        iVar9 = (int)param_3 + (-1 - param_11);
      }
      iVar9 = param_16 * iVar9;
      param_14 = DestTotHgt * param_14;
      param_16 = (int)param_1 * param_16;
      puVar10 = param_9 + iVar9 + param_10;
      iVar9 = 0;
      if (param_7 < 1) {
        return;
      }
      param_8 = (BITMAPINFO256 *)0x100;
      do {
        memcpy(puVar12,puVar10,param_6);
        puVar12 = puVar12 + param_14;
        puVar10 = puVar10 + param_16;
        iVar9 = iVar9 + 1;
      } while (iVar9 < param_7);
      return;
    }
  }
  else if (param_15 == 0) {
    if (0 < param_6) {
      pplVar11 = &SrcXTbl;
      lVar5 = param_10;
      lVar8 = param_6;
      do {
        *pplVar11 = (long *)(lVar5 >> 8);
        lVar5 = lVar5 + iVar3;
        lVar8 = lVar8 + -1;
        pplVar11 = pplVar11 + 1;
      } while (lVar8 != 0);
    }
    goto LAB_00438a00;
  }
  if (-1 < param_6 + -1) {
    pplVar11 = &SrcXTbl + param_6 + -1;
    lVar5 = param_10;
    lVar8 = param_6;
    do {
      *pplVar11 = (long *)(lVar5 >> 8);
      lVar5 = lVar5 + iVar3;
      lVar8 = lVar8 + -1;
      pplVar11 = pplVar11 + -1;
    } while (lVar8 != 0);
  }
LAB_00438a00:
  iVar9 = param_11 << 8;
  param_15 = 0;
  if (0 < param_7) {
    do {
      iVar3 = iVar9 >> 8;
      if (param_1 != (BITMAPINFO256 *)0x1) {
        iVar3 = (int)param_3 + (-1 - iVar3);
      }
      if (0 < param_6) {
        pplVar11 = &SrcXTbl;
        iVar6 = 0;
        do {
          plVar1 = *pplVar11;
          iVar7 = iVar6 + 1;
          pplVar11 = pplVar11 + 1;
          puVar12[iVar6] = param_9[(int)plVar1 + iVar3 * param_16 + param_10];
          iVar6 = iVar7;
        } while (iVar7 < param_6);
      }
      iVar9 = iVar9 + iVar4;
      puVar12 = puVar12 + DestTotHgt * param_14;
      param_15 = param_15 + 1;
    } while (param_15 < param_7);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00438a98
// Address: 00438a98
// XREFS: None
void FUN_00438a98(BITMAPINFO256 *param_1,uchar *param_2,tagRECT *param_3,long param_4,long param_5,
                 long param_6,long param_7,BITMAPINFO256 *param_8,uchar *param_9,int *param_10,
                 long param_11,long param_12,long param_13,long param_14,int param_15,int param_16,
                 int param_17,uint param_18)
{
  byte bVar1;
  BITMAPINFO256 *pBVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  long **pplVar8;
  uchar *puVar9;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar5 = param_17;
  piVar7 = param_10;
  pBVar2 = param_1;
  if ((param_10 != (int *)0x0) && (*param_10 == 0)) {
    DibBlt(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_11,param_12
           ,param_13,param_14,param_15,param_16,param_17);
    return;
  }
  if ((int)param_18 < 0) {
    param_18 = 0;
  }
  if ((param_15 == 0) ||
     (iVar3 = ClipDibBlt(param_1,param_3,&param_4,&param_5,&param_6,&param_7,&param_11,&param_12,
                         &param_13,&param_14,param_16,param_17), iVar3 != 0)) {
    iVar3 = (param_13 << 8) / param_6;
    iStack_c = (param_14 << 8) / param_7;
    GetDibDim(pBVar2,&param_15,&iStack_4,&iStack_8);
    GetDibDim(param_8,(long *)&param_1,&iStack_10,&param_17);
    if (iVar5 != 0) {
      param_17 = -param_17;
    }
    param_3 = (tagRECT *)((param_6 << 8) / param_13);
    iVar5 = param_5;
    if (iStack_8 != 1) {
      iVar5 = (iStack_4 - param_5) + -1;
    }
    puVar9 = param_2 + param_15 * iVar5 + param_4;
    if (param_16 == 0) {
      if (0 < param_6) {
        pplVar8 = &SrcXTbl;
        iVar5 = param_11;
        iVar6 = param_6;
        do {
          *pplVar8 = (long *)(iVar5 >> 8);
          iVar5 = iVar5 + iVar3;
          iVar6 = iVar6 + -1;
          pplVar8 = pplVar8 + 1;
          piVar7 = param_10;
        } while (iVar6 != 0);
      }
    }
    else if (-1 < param_6 + -1) {
      pplVar8 = &SrcXTbl + param_6 + -1;
      iVar5 = param_11;
      iVar6 = param_6;
      do {
        *pplVar8 = (long *)(iVar5 >> 8);
        iVar5 = iVar5 + iVar3;
        iVar6 = iVar6 + -1;
        pplVar8 = pplVar8 + -1;
        piVar7 = param_10;
      } while (iVar6 != 0);
    }
    if (((param_16 == 0) && (piVar7 != (int *)0x0)) &&
       (param_8 = (BITMAPINFO256 *)piVar7[5], param_8 != (BITMAPINFO256 *)0x0)) {
      param_15 = iStack_8 * param_15;
      param_10 = (int *)(param_12 << 8);
      param_16 = 0;
      if (0 < param_7) {
        do {
          iVar3 = (int)param_10 >> 8;
          iVar5 = iVar3;
          if (param_17 != 1) {
            iVar5 = (iStack_10 - iVar3) + -1;
          }
          iVar6 = iVar5 * (int)param_1 + param_11;
          iVar5 = iVar3 * 0x10 + (int)param_8;
          if (*(int *)(iVar3 * 0x10 + (int)param_8) == 0) {
            if (*(int *)(iVar5 + 8) < param_11) {
              iVar3 = 0;
            }
            else {
              iVar3 = (*(int *)(iVar5 + 8) - param_11) * (int)param_3 >> 8;
            }
            iVar4 = ((*(int *)(iVar5 + 0xc) - param_11) + 1) * (int)param_3 >> 8;
            if (param_6 < iVar4) {
              iVar4 = param_6;
            }
            if (iVar3 < iVar4) {
              if ((param_3 == (tagRECT *)0x100) && (*(int *)(iVar5 + 4) != 0)) {
                memcpy(puVar9 + iVar3,param_9 + iVar3 + iVar6,iVar4 - iVar3);
              }
              else if (iVar3 < iVar4) {
                pplVar8 = &SrcXTbl + iVar3;
                do {
                  bVar1 = param_9[(int)*pplVar8 + iVar6];
                  param_2 = (uchar *)CONCAT31(param_2._1_3_,bVar1);
                  if (bVar1 != param_18) {
                    puVar9[iVar3] = bVar1;
                  }
                  iVar3 = iVar3 + 1;
                  pplVar8 = pplVar8 + 1;
                } while (iVar3 < iVar4);
              }
            }
          }
          puVar9 = puVar9 + param_15;
          param_10 = (int *)((int)param_10 + iStack_c);
          param_16 = param_16 + 1;
        } while (param_16 < param_7);
        return;
      }
    }
    else {
      param_16 = 0;
      iVar5 = param_12 << 8;
      if (0 < param_7) {
        do {
          iVar3 = iVar5 >> 8;
          if (param_17 != 1) {
            iVar3 = (iStack_10 - iVar3) + -1;
          }
          iVar6 = 0;
          if (0 < param_6) {
            pplVar8 = &SrcXTbl;
            do {
              param_2 = (uchar *)(uint)param_9[(int)*pplVar8 + iVar3 * (int)param_1 + param_11];
              if (param_2 != (uchar *)param_18) {
                puVar9[iVar6] = param_9[(int)*pplVar8 + iVar3 * (int)param_1 + param_11];
              }
              iVar6 = iVar6 + 1;
              pplVar8 = pplVar8 + 1;
            } while (iVar6 < param_6);
          }
          puVar9 = puVar9 + iStack_8 * param_15;
          iVar5 = iVar5 + iStack_c;
          param_16 = param_16 + 1;
        } while (param_16 < param_7);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: TransDibBlt
// Address: 00438aa0
// XREFS: Copy, Draw, TileDibBlt
/* WARNING: Variable defined which should be unmapped: SrcTotHgt */
/* void __cdecl TransDibBlt(struct BITMAPINFO256 *,unsigned char *,struct tagRECT
   *,long,long,long,long,struct BITMAPINFO256 *,unsigned char *,struct TRANSINFO
   *,long,long,long,long,int,int,int,int) */

void __cdecl
TransDibBlt(BITMAPINFO256 *param_1,uchar *param_2,tagRECT *param_3,long param_4,long param_5,
           long param_6,long param_7,BITMAPINFO256 *param_8,uchar *param_9,TRANSINFO *param_10,
           long param_11,long param_12,long param_13,long param_14,int param_15,int param_16,
           int param_17,int param_18)
{
  byte bVar1;
  BITMAPINFO256 *pBVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  TRANSINFO *pTVar9;
  long **pplVar10;
  uchar *puVar11;
  long SrcTotHgt;
  long sySkip;
  long DestOrien;
  long DestTotHgt;
  int local_4;
  
  iVar6 = param_17;
  pTVar9 = param_10;
  pBVar2 = param_1;
  if ((param_10 != (TRANSINFO *)0x0) && (param_10->AnyTrans == 0)) {
    DibBlt(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_11,param_12
           ,param_13,param_14,param_15,param_16,param_17);
    return;
  }
  if (param_18 < 0) {
    param_18 = 0;
  }
  if ((param_15 == 0) ||
     (iVar3 = ClipDibBlt(param_1,param_3,&param_4,&param_5,&param_6,&param_7,&param_11,&param_12,
                         &param_13,&param_14,param_16,param_17), iVar3 != 0)) {
    iVar3 = (param_13 << 8) / param_6;
    DestOrien = (param_14 << 8) / param_7;
    GetDibDim(pBVar2,&param_15,&local_4,&DestTotHgt);
    GetDibDim(param_8,(long *)&param_1,&sySkip,&param_17);
    if (iVar6 != 0) {
      param_17 = -param_17;
    }
    param_3 = (tagRECT *)((param_6 << 8) / param_13);
    iVar6 = param_5;
    if (DestTotHgt != 1) {
      iVar6 = (local_4 - param_5) + -1;
    }
    puVar11 = param_2 + param_15 * iVar6 + param_4;
    if (param_16 == 0) {
      if (0 < param_6) {
        pplVar10 = &SrcXTbl;
        lVar5 = param_11;
        lVar7 = param_6;
        do {
          *pplVar10 = (long *)(lVar5 >> 8);
          lVar5 = lVar5 + iVar3;
          lVar7 = lVar7 + -1;
          pplVar10 = pplVar10 + 1;
          pTVar9 = param_10;
        } while (lVar7 != 0);
      }
    }
    else if (-1 < param_6 + -1) {
      pplVar10 = &SrcXTbl + param_6 + -1;
      lVar5 = param_11;
      lVar7 = param_6;
      do {
        *pplVar10 = (long *)(lVar5 >> 8);
        lVar5 = lVar5 + iVar3;
        lVar7 = lVar7 + -1;
        pplVar10 = pplVar10 + -1;
        pTVar9 = param_10;
      } while (lVar7 != 0);
    }
    if (((param_16 == 0) && (pTVar9 != (TRANSINFO *)0x0)) &&
       (param_8 = (BITMAPINFO256 *)pTVar9->LineInfo, param_8 != (BITMAPINFO256 *)0x0)) {
      param_15 = DestTotHgt * param_15;
      param_10 = (TRANSINFO *)(param_12 << 8);
      param_16 = 0;
      if (0 < param_7) {
        do {
          iVar3 = (int)param_10 >> 8;
          iVar6 = iVar3;
          if (param_17 != 1) {
            iVar6 = (sySkip - iVar3) + -1;
          }
          iVar6 = iVar6 * (int)param_1 + param_11;
          if (param_8->bmiColors[iVar3 * 4 + -10] == (tagRGBQUAD)0x0) {
            if ((int)param_8->bmiColors[iVar3 * 4 + -8] < param_11) {
              iVar8 = 0;
            }
            else {
              iVar8 = ((int)param_8->bmiColors[iVar3 * 4 + -8] - param_11) * (int)param_3 >> 8;
            }
            iVar4 = (((int)param_8->bmiColors[iVar3 * 4 + -7] - param_11) + 1) * (int)param_3 >> 8;
            if (param_6 < iVar4) {
              iVar4 = param_6;
            }
            if (iVar8 < iVar4) {
              if ((param_3 == (tagRECT *)0x100) &&
                 (param_8->bmiColors[iVar3 * 4 + -9] != (tagRGBQUAD)0x0)) {
                memcpy(puVar11 + iVar8,param_9 + iVar8 + iVar6,iVar4 - iVar8);
              }
              else if (iVar8 < iVar4) {
                pplVar10 = &SrcXTbl + iVar8;
                do {
                  bVar1 = param_9[(int)*pplVar10 + iVar6];
                  param_2 = (uchar *)CONCAT31(param_2._1_3_,bVar1);
                  if ((uint)bVar1 != param_18) {
                    puVar11[iVar8] = bVar1;
                  }
                  iVar8 = iVar8 + 1;
                  pplVar10 = pplVar10 + 1;
                } while (iVar8 < iVar4);
              }
            }
          }
          puVar11 = puVar11 + param_15;
          param_10 = (TRANSINFO *)((int)&param_10->AnyTrans + DestOrien);
          param_16 = param_16 + 1;
        } while (param_16 < param_7);
        return;
      }
    }
    else {
      param_16 = 0;
      iVar6 = param_12 << 8;
      if (0 < param_7) {
        do {
          iVar3 = iVar6 >> 8;
          if (param_17 != 1) {
            iVar3 = (sySkip - iVar3) + -1;
          }
          iVar8 = 0;
          if (0 < param_6) {
            pplVar10 = &SrcXTbl;
            do {
              param_2 = (uchar *)(uint)param_9[(int)*pplVar10 + iVar3 * (int)param_1 + param_11];
              if (param_2 != (uchar *)param_18) {
                puVar11[iVar8] = param_9[(int)*pplVar10 + iVar3 * (int)param_1 + param_11];
              }
              iVar8 = iVar8 + 1;
              pplVar10 = pplVar10 + 1;
            } while (iVar8 < param_6);
          }
          puVar11 = puVar11 + DestTotHgt * param_15;
          iVar6 = iVar6 + DestOrien;
          param_16 = param_16 + 1;
        } while (param_16 < param_7);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00438e71
// Address: 00438e71
// XREFS: None
undefined4
FUN_00438e71(int param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
            int *param_7,int *param_8,int *param_9,int *param_10,int param_11,int param_12)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (param_2 == (int *)0x0) {
    iVar6 = 0;
    iVar7 = 0;
    iVar5 = *(int *)(param_1 + 4);
    iVar2 = *(int *)(param_1 + 8);
  }
  else {
    iVar6 = *param_2;
    iVar7 = param_2[1];
    iVar5 = param_2[2] + 1;
    iVar2 = param_2[3] + 1;
  }
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  iVar5 = iVar5 + -1;
  iVar2 = iVar2 + -1;
  iVar1 = *param_3;
  if (((((iVar1 <= iVar5) && (*param_4 <= iVar2)) && (iVar3 = *param_5, iVar6 <= iVar3 + -1 + iVar1)
       ) && ((iVar4 = *param_6, iVar7 <= iVar4 + -1 + *param_4 && (0 < iVar3)))) && (0 < iVar4)) {
    iVar3 = (*param_9 << 8) / iVar3;
    iVar4 = (*param_10 << 8) / iVar4;
    if (iVar1 < iVar6) {
      *param_3 = iVar6;
      *param_5 = *param_5 - (iVar6 - iVar1);
      iVar6 = (iVar6 - iVar1) * 0x100 * iVar3 >> 0x10;
      if (param_11 == 0) {
        *param_7 = *param_7 + iVar6;
      }
      *param_9 = *param_9 - iVar6;
    }
    iVar6 = *param_4;
    if (iVar6 < iVar7) {
      *param_4 = iVar7;
      iVar7 = iVar7 - iVar6;
      *param_6 = *param_6 - iVar7;
      iVar6 = iVar7 * 0x100 * iVar4 >> 0x10;
      if (param_12 == 0) {
        *param_8 = *param_8 + iVar6;
      }
      *param_10 = *param_10 - iVar6;
    }
    iVar6 = *param_3 + *param_5;
    if (iVar5 < iVar6 + -1) {
      iVar6 = (iVar6 - iVar5) + -1;
      *param_5 = *param_5 - iVar6;
      iVar6 = iVar6 * 0x100 * iVar3 >> 0x10;
      *param_9 = *param_9 - iVar6;
      if (param_11 != 0) {
        *param_7 = *param_7 + iVar6;
      }
    }
    iVar6 = *param_4 + *param_6;
    if (iVar2 < iVar6 + -1) {
      iVar6 = (iVar6 - iVar2) + -1;
      *param_6 = *param_6 - iVar6;
      iVar6 = iVar6 * 0x100 * iVar4 >> 0x10;
      *param_10 = *param_10 - iVar6;
      if (param_12 != 0) {
        *param_8 = *param_8 + iVar6;
      }
    }
    if (((0 < *param_5) && (0 < *param_6)) && ((0 < *param_9 && (0 < *param_10)))) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: ClipDibBlt
// Address: 00438e80
// XREFS: DibBlt, TransDibBlt
/* WARNING: Variable defined which should be unmapped: ey */
/* int __cdecl ClipDibBlt(struct BITMAPINFO256 *,struct tagRECT *,long &,long &,long &,long &,long
   &,long &,long &,long &,int,int) */

int __cdecl
ClipDibBlt(BITMAPINFO256 *param_1,tagRECT *param_2,long *param_3,long *param_4,long *param_5,
          long *param_6,long *param_7,long *param_8,long *param_9,long *param_10,int param_11,
          int param_12)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long ey;
  
  if (param_2 == (tagRECT *)0x0) {
    iVar6 = 0;
    iVar7 = 0;
    iVar5 = (param_1->bmiHeader).biWidth;
    iVar2 = (param_1->bmiHeader).biHeight;
  }
  else {
    iVar6 = param_2->left;
    iVar7 = param_2->top;
    iVar5 = param_2->right + 1;
    iVar2 = param_2->bottom + 1;
  }
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  iVar5 = iVar5 + -1;
  iVar2 = iVar2 + -1;
  iVar1 = *param_3;
  if (((((iVar1 <= iVar5) && (*param_4 <= iVar2)) && (iVar3 = *param_5, iVar6 <= iVar3 + -1 + iVar1)
       ) && ((iVar4 = *param_6, iVar7 <= iVar4 + -1 + *param_4 && (0 < iVar3)))) && (0 < iVar4)) {
    iVar3 = (*param_9 << 8) / iVar3;
    iVar4 = (*param_10 << 8) / iVar4;
    if (iVar1 < iVar6) {
      *param_3 = iVar6;
      *param_5 = *param_5 - (iVar6 - iVar1);
      iVar6 = (iVar6 - iVar1) * 0x100 * iVar3 >> 0x10;
      if (param_11 == 0) {
        *param_7 = *param_7 + iVar6;
      }
      *param_9 = *param_9 - iVar6;
    }
    iVar6 = *param_4;
    if (iVar6 < iVar7) {
      *param_4 = iVar7;
      iVar7 = iVar7 - iVar6;
      *param_6 = *param_6 - iVar7;
      iVar6 = iVar7 * 0x100 * iVar4 >> 0x10;
      if (param_12 == 0) {
        *param_8 = *param_8 + iVar6;
      }
      *param_10 = *param_10 - iVar6;
    }
    iVar6 = *param_3 + *param_5;
    if (iVar5 < iVar6 + -1) {
      iVar6 = (iVar6 - iVar5) + -1;
      *param_5 = *param_5 - iVar6;
      iVar6 = iVar6 * 0x100 * iVar3 >> 0x10;
      *param_9 = *param_9 - iVar6;
      if (param_11 != 0) {
        *param_7 = *param_7 + iVar6;
      }
    }
    iVar6 = *param_4 + *param_6;
    if (iVar2 < iVar6 + -1) {
      iVar6 = (iVar6 - iVar2) + -1;
      *param_6 = *param_6 - iVar6;
      iVar6 = iVar6 * 0x100 * iVar4 >> 0x10;
      *param_10 = *param_10 - iVar6;
      if (param_12 != 0) {
        *param_8 = *param_8 + iVar6;
      }
    }
    if (((0 < *param_5) && (0 < *param_6)) && ((0 < *param_9 && (0 < *param_10)))) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00439053
// Address: 00439053
// XREFS: None
void FUN_00439053(int param_1,uint *param_2,int *param_3,undefined4 *param_4)
{
  int iVar1;
  
  *param_2 = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  iVar1 = *(int *)(param_1 + 8);
  *param_3 = iVar1;
  if (iVar1 < 0) {
    *param_3 = -iVar1;
    *param_4 = 1;
    return;
  }
  *param_4 = 0xffffffff;
  return;
}

// --------------------------------------------------

// Function: GetDibDim
// Address: 00439060
// XREFS: DibBlt, DibCheckTrans, TransDibBlt
/* void __cdecl GetDibDim(struct BITMAPINFO256 *,long &,long &,long &) */

void __cdecl GetDibDim(BITMAPINFO256 *param_1,long *param_2,long *param_3,long *param_4)
{
  int iVar1;
  
  *param_2 = (param_1->bmiHeader).biWidth + 3U & 0xfffffffc;
  iVar1 = (param_1->bmiHeader).biHeight;
  *param_3 = iVar1;
  if (iVar1 < 0) {
    *param_3 = -iVar1;
    *param_4 = 1;
    return;
  }
  *param_4 = -1;
  return;
}

// --------------------------------------------------

// Function: FUN_0043909a
// Address: 0043909a
// XREFS: None
int FUN_0043909a(BITMAPINFO256 *param_1,uchar *param_2,tagRECT *param_3,int param_4,int param_5,
                int param_6,int param_7,int param_8,int param_9,BITMAPINFO256 *param_10,
                uchar *param_11,TRANSINFO *param_12,int param_13,int param_14,int param_15,
                int param_16,int param_17,int param_18,int param_19)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar13 = param_19;
  iVar14 = param_18;
  if (param_13 < 0) {
    param_13 = param_13 + param_15;
  }
  if (param_14 < 0) {
    param_14 = param_14 + param_16;
  }
  for (; param_15 <= param_13; param_13 = param_13 - param_15) {
  }
  for (; param_16 <= param_14; param_14 = param_14 - param_16) {
  }
  iVar2 = param_15 - param_13;
  iVar11 = param_16 - param_14;
  iVar5 = param_15 - iVar2;
  iVar7 = param_13 - iVar5;
  iVar9 = param_16 - iVar11;
  iVar8 = param_14 - iVar9;
  iVar10 = (iVar2 * 0x10000) / ((param_15 << 8) / param_8) >> 8;
  iVar6 = param_8 - iVar10;
  iVar12 = (iVar11 * 0x10000) / ((param_16 << 8) / param_9) >> 8;
  iVar3 = param_9 - iVar12;
  if ((param_8 < param_6) || (param_9 < param_7)) {
    iVar4 = param_6 / param_8;
    bVar1 = iVar4 * param_8 < param_6;
    param_6 = iVar4;
    if (bVar1) {
      param_6 = iVar4 + 1;
    }
    iVar4 = param_7 / param_9;
    bVar1 = iVar4 * param_9 < param_7;
    param_7 = iVar4;
    if (bVar1) {
      param_7 = iVar4 + 1;
    }
  }
  else {
    param_7 = 1;
    param_6 = 1;
  }
  if (param_17 == 0) {
    param_12 = (TRANSINFO *)param_5;
    if (0 < param_7) {
      param_17 = param_7;
      do {
        if (0 < param_6) {
          param_19 = param_6;
          iVar14 = param_4;
          do {
            if (iVar12 != 0) {
              if (iVar10 != 0) {
                DibBlt(param_1,param_2,param_3,iVar14,(long)param_12,iVar10,iVar12,param_10,param_11
                       ,param_13,param_14,iVar2,iVar11,1,param_18,iVar13);
              }
              if (iVar6 != 0) {
                DibBlt(param_1,param_2,param_3,iVar14 + iVar10,(long)param_12,iVar6,iVar12,param_10,
                       param_11,iVar7,param_14,iVar5,iVar11,1,param_18,iVar13);
              }
            }
            if (iVar3 != 0) {
              if (iVar10 != 0) {
                DibBlt(param_1,param_2,param_3,iVar14,(int)param_12 + iVar12,iVar10,iVar3,param_10,
                       param_11,param_13,iVar8,iVar2,iVar9,1,param_18,iVar13);
              }
              if (iVar6 != 0) {
                DibBlt(param_1,param_2,param_3,iVar14 + iVar10,(int)param_12 + iVar12,iVar6,iVar3,
                       param_10,param_11,iVar7,iVar8,iVar5,iVar9,1,param_18,iVar13);
              }
            }
            iVar14 = iVar14 + param_8;
            param_19 = param_19 + -1;
          } while (param_19 != 0);
        }
        param_12 = (TRANSINFO *)((int)param_12 + param_9);
        param_17 = param_17 + -1;
      } while (param_17 != 0);
    }
  }
  else if (0 < param_7) {
    param_17 = param_7;
    do {
      if (0 < param_6) {
        param_18 = param_6;
        iVar13 = param_4;
        do {
          if (iVar12 != 0) {
            if (iVar10 != 0) {
              TransDibBlt(param_1,param_2,param_3,iVar13,param_5,iVar10,iVar12,param_10,param_11,
                          param_12,param_13,param_14,iVar2,iVar11,1,iVar14,param_19,0);
            }
            if (iVar6 != 0) {
              TransDibBlt(param_1,param_2,param_3,iVar13 + iVar10,param_5,iVar6,iVar12,param_10,
                          param_11,param_12,iVar7,param_14,iVar5,iVar11,1,iVar14,param_19,0);
            }
          }
          if (iVar3 != 0) {
            if (iVar10 != 0) {
              TransDibBlt(param_1,param_2,param_3,iVar13,param_5 + iVar12,iVar10,iVar3,param_10,
                          param_11,param_12,param_13,iVar8,iVar2,iVar9,1,iVar14,param_19,0);
            }
            if (iVar6 != 0) {
              TransDibBlt(param_1,param_2,param_3,iVar13 + iVar10,param_5 + iVar12,iVar6,iVar3,
                          param_10,param_11,param_12,iVar7,iVar8,iVar5,iVar9,1,iVar14,param_19,0);
            }
          }
          iVar13 = iVar13 + param_8;
          param_18 = param_18 + -1;
        } while (param_18 != 0);
      }
      param_5 = param_5 + param_9;
      param_17 = param_17 + -1;
    } while (param_17 != 0);
    return param_7 * param_6;
  }
  return param_7 * param_6;
}

// --------------------------------------------------

// Function: TileDibBlt
// Address: 004390a0
// XREFS: Tile
/* WARNING: Variable defined which should be unmapped: SrcBotHgt */
/* long __cdecl TileDibBlt(struct BITMAPINFO256 *,unsigned char *,struct tagRECT
   *,long,long,long,long,long,long,struct BITMAPINFO256 *,unsigned char *,struct TRANSINFO
   *,long,long,long,long,int,int,int) */

long __cdecl
TileDibBlt(BITMAPINFO256 *param_1,uchar *param_2,tagRECT *param_3,long param_4,long param_5,
          long param_6,long param_7,long param_8,long param_9,BITMAPINFO256 *param_10,
          uchar *param_11,TRANSINFO *param_12,long param_13,long param_14,long param_15,
          long param_16,int param_17,int param_18,int param_19)
{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  long lVar15;
  long SrcBotHgt;
  long SrcRtWid;
  long DestBotHgt;
  long SrcTopHgt;
  long SrcLtWid;
  
  iVar3 = param_19;
  iVar1 = param_18;
  if (param_13 < 0) {
    param_13 = param_13 + param_15;
  }
  if (param_14 < 0) {
    param_14 = param_14 + param_16;
  }
  for (; param_15 <= param_13; param_13 = param_13 - param_15) {
  }
  for (; param_16 <= param_14; param_14 = param_14 - param_16) {
  }
  iVar4 = param_15 - param_13;
  iVar13 = param_16 - param_14;
  iVar7 = param_15 - iVar4;
  iVar9 = param_13 - iVar7;
  iVar11 = param_16 - iVar13;
  iVar10 = param_14 - iVar11;
  iVar12 = (iVar4 * 0x10000) / ((param_15 << 8) / param_8) >> 8;
  iVar8 = param_8 - iVar12;
  iVar14 = (iVar13 * 0x10000) / ((param_16 << 8) / param_9) >> 8;
  iVar5 = param_9 - iVar14;
  if ((param_8 < param_6) || (param_9 < param_7)) {
    iVar6 = param_6 / param_8;
    bVar2 = iVar6 * param_8 < param_6;
    param_6 = iVar6;
    if (bVar2) {
      param_6 = iVar6 + 1;
    }
    iVar6 = param_7 / param_9;
    bVar2 = iVar6 * param_9 < param_7;
    param_7 = iVar6;
    if (bVar2) {
      param_7 = iVar6 + 1;
    }
  }
  else {
    param_7 = 1;
    param_6 = 1;
  }
  if (param_17 == 0) {
    param_12 = (TRANSINFO *)param_5;
    if (0 < param_7) {
      param_17 = param_7;
      do {
        iVar1 = (int)&param_12->AnyTrans + iVar14;
        if (0 < param_6) {
          param_19 = param_6;
          lVar15 = param_4;
          do {
            if (iVar14 != 0) {
              if (iVar12 != 0) {
                DibBlt(param_1,param_2,param_3,lVar15,(long)param_12,iVar12,iVar14,param_10,param_11
                       ,param_13,param_14,iVar4,iVar13,1,param_18,iVar3);
              }
              if (iVar8 != 0) {
                DibBlt(param_1,param_2,param_3,lVar15 + iVar12,(long)param_12,iVar8,iVar14,param_10,
                       param_11,iVar9,param_14,iVar7,iVar13,1,param_18,iVar3);
              }
            }
            if (iVar5 != 0) {
              if (iVar12 != 0) {
                DibBlt(param_1,param_2,param_3,lVar15,iVar1,iVar12,iVar5,param_10,param_11,param_13,
                       iVar10,iVar4,iVar11,1,param_18,iVar3);
              }
              if (iVar8 != 0) {
                DibBlt(param_1,param_2,param_3,lVar15 + iVar12,iVar1,iVar8,iVar5,param_10,param_11,
                       iVar9,iVar10,iVar7,iVar11,1,param_18,iVar3);
              }
            }
            lVar15 = lVar15 + param_8;
            param_19 = param_19 + -1;
          } while (param_19 != 0);
        }
        param_12 = (TRANSINFO *)((int)&param_12->AnyTrans + param_9);
        param_17 = param_17 + -1;
      } while (param_17 != 0);
    }
  }
  else if (0 < param_7) {
    param_17 = param_7;
    do {
      if (0 < param_6) {
        param_18 = param_6;
        lVar15 = param_4;
        do {
          if (iVar14 != 0) {
            if (iVar12 != 0) {
              TransDibBlt(param_1,param_2,param_3,lVar15,param_5,iVar12,iVar14,param_10,param_11,
                          param_12,param_13,param_14,iVar4,iVar13,1,iVar1,param_19,0);
            }
            if (iVar8 != 0) {
              TransDibBlt(param_1,param_2,param_3,lVar15 + iVar12,param_5,iVar8,iVar14,param_10,
                          param_11,param_12,iVar9,param_14,iVar7,iVar13,1,iVar1,param_19,0);
            }
          }
          if (iVar5 != 0) {
            if (iVar12 != 0) {
              TransDibBlt(param_1,param_2,param_3,lVar15,param_5 + iVar14,iVar12,iVar5,param_10,
                          param_11,param_12,param_13,iVar10,iVar4,iVar11,1,iVar1,param_19,0);
            }
            if (iVar8 != 0) {
              TransDibBlt(param_1,param_2,param_3,lVar15 + iVar12,param_5 + iVar14,iVar8,iVar5,
                          param_10,param_11,param_12,iVar9,iVar10,iVar7,iVar11,1,iVar1,param_19,0);
            }
          }
          lVar15 = lVar15 + param_8;
          param_18 = param_18 + -1;
        } while (param_18 != 0);
      }
      param_5 = param_5 + param_9;
      param_17 = param_17 + -1;
    } while (param_17 != 0);
    return param_7 * param_6;
  }
  return param_7 * param_6;
}

// --------------------------------------------------

// Function: FUN_00439591
// Address: 00439591
// XREFS: None
int FUN_00439591(BITMAPINFO256 *param_1,int *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  GetDibDim(param_1,&iStack_c,&iStack_14,&iStack_4);
  iVar5 = (param_1->bmiHeader).biWidth;
  iStack_8 = iVar5;
  iVar1 = malloc(iStack_14 << 4);
  param_2[5] = iVar1;
  if (iVar1 == 0) {
    return 1;
  }
  iStack_10 = 0;
  param_1 = (BITMAPINFO256 *)0x0;
  if (0 < iStack_14) {
    iVar1 = 0;
    do {
      iVar7 = 1;
      iVar8 = (int)param_1;
      if (iStack_4 != 1) {
        iVar8 = (iStack_14 - (int)param_1) + -1;
      }
      iVar2 = iStack_c * iVar8 + param_3;
      iVar3 = 0;
      iVar8 = iVar5;
      if (0 < iVar5) {
        do {
          if (*(char *)(iVar2 + iVar3) == '\0') {
            if (iStack_10 == 0) {
              iStack_10 = 1;
            }
          }
          else if (iVar7 != 0) {
            iVar7 = 0;
            iVar8 = iVar3;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar5);
      }
      iVar4 = iVar8;
      iVar3 = iVar8;
      if (iVar7 == 0) {
        while (iVar3 = iVar3 + 1, iVar3 < iVar5) {
          if (*(char *)(iVar2 + iVar3) != '\0') {
            iVar4 = iVar3;
          }
        }
      }
      uVar6 = 1;
      iVar5 = iVar8;
      if (iVar7 == 0) {
        for (; iVar5 <= iVar4; iVar5 = iVar5 + 1) {
          if (*(char *)(iVar2 + iVar5) == '\0') {
            uVar6 = 0;
            break;
          }
        }
      }
      iVar1 = iVar1 + 0x10;
      *(int *)(param_2[5] + -0x10 + iVar1) = iVar7;
      *(undefined4 *)(param_2[5] + -0xc + iVar1) = uVar6;
      *(int *)(param_2[5] + -8 + iVar1) = iVar8;
      *(int *)(param_2[5] + -4 + iVar1) = iVar4;
      param_1 = (BITMAPINFO256 *)((int)param_1 + 1);
      iVar5 = iStack_8;
    } while ((int)param_1 < iStack_14);
  }
  iVar5 = iStack_10;
  *param_2 = iStack_10;
  if (iStack_10 == 0) {
    free(param_2[5]);
  }
  return iVar5;
}

// --------------------------------------------------

// Function: DibCheckTrans
// Address: 004395a0
// XREFS: Load, TPicture
/* WARNING: Variable defined which should be unmapped: h */
/* int __cdecl DibCheckTrans(struct BITMAPINFO256 *,struct TRANSINFO *,unsigned char *) */

int __cdecl DibCheckTrans(BITMAPINFO256 *param_1,TRANSINFO *param_2,uchar *param_3)
{
  BITMAPINFO256 *pBVar1;
  long lVar2;
  LINEINFO *pLVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  long h;
  int AnyTrans;
  long tw;
  long w;
  long orien;
  int local_4;
  
  GetDibDim(param_1,&w,&AnyTrans,&local_4);
  iVar7 = (param_1->bmiHeader).biWidth;
  orien = iVar7;
  pLVar3 = (LINEINFO *)malloc(AnyTrans << 4);
  param_2->LineInfo = pLVar3;
  if (pLVar3 == (LINEINFO *)0x0) {
    return 1;
  }
  tw = 0;
  param_1 = (BITMAPINFO256 *)0x0;
  if (0 < AnyTrans) {
    iVar9 = 0;
    do {
      iVar10 = 1;
      pBVar1 = param_1;
      if (local_4 != 1) {
        pBVar1 = (BITMAPINFO256 *)((AnyTrans - (int)param_1) + -1);
      }
      iVar4 = w * (int)pBVar1;
      iVar5 = 0;
      iVar11 = iVar7;
      if (0 < iVar7) {
        do {
          if (param_3[iVar5 + iVar4] == '\0') {
            if (tw == 0) {
              tw = 1;
            }
          }
          else if (iVar10 != 0) {
            iVar10 = 0;
            iVar11 = iVar5;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar7);
      }
      iVar6 = iVar11;
      iVar5 = iVar11;
      if (iVar10 == 0) {
        while (iVar5 = iVar5 + 1, iVar5 < iVar7) {
          if (param_3[iVar5 + iVar4] != '\0') {
            iVar6 = iVar5;
          }
        }
      }
      uVar8 = 1;
      iVar7 = iVar11;
      if (iVar10 == 0) {
        for (; iVar7 <= iVar6; iVar7 = iVar7 + 1) {
          if (param_3[iVar7 + iVar4] == '\0') {
            uVar8 = 0;
            break;
          }
        }
      }
      *(int *)((int)&param_2->LineInfo->AllTrans + iVar9) = iVar10;
      *(undefined4 *)((int)&param_2->LineInfo->MidSolid + iVar9) = uVar8;
      *(int *)((int)&param_2->LineInfo->StartX + iVar9) = iVar11;
      *(int *)((int)&param_2->LineInfo->EndX + iVar9) = iVar6;
      param_1 = (BITMAPINFO256 *)((int)&(param_1->bmiHeader).biSize + 1);
      iVar7 = orien;
      iVar9 = iVar9 + 0x10;
    } while ((int)param_1 < AnyTrans);
  }
  lVar2 = tw;
  param_2->AnyTrans = tw;
  if (tw == 0) {
    free(param_2->LineInfo);
  }
  return lVar2;
}

// --------------------------------------------------

// Function: FUN_004396f9
// Address: 004396f9
// XREFS: None
void * FUN_004396f9(char *param_1,int param_2)
{
  tagBITMAPINFOHEADER *ptVar1;
  void *pvVar2;
  
  ptVar1 = DibOpenFile(param_1);
  if (ptVar1 == (tagBITMAPINFOHEADER *)0x0) {
    return (void *)0x0;
  }
  pvVar2 = DibCreatePalette(ptVar1);
  if (param_2 != 0) {
    CreateIdentityPalette(pvVar2);
  }
  DibFree(ptVar1);
  return pvVar2;
}

// --------------------------------------------------

// Function: GetPaletteFromDib
// Address: 00439700
// XREFS: None
/* void * __cdecl GetPaletteFromDib(char *,int) */

void * __cdecl GetPaletteFromDib(char *param_1,int param_2)
{
  tagBITMAPINFOHEADER *ptVar1;
  void *pvVar2;
  
  ptVar1 = DibOpenFile(param_1);
  if (ptVar1 == (tagBITMAPINFOHEADER *)0x0) {
    return (void *)0x0;
  }
  pvVar2 = DibCreatePalette(ptVar1);
  if (param_2 != 0) {
    CreateIdentityPalette(pvVar2);
  }
  DibFree(ptVar1);
  return pvVar2;
}

// --------------------------------------------------

// Function: FUN_00439741
// Address: 00439741
// XREFS: None
// [HELPER] s___: "]\n"
// [HELPER] shape_file_first: " "
void * FUN_00439741(char *param_1,ulong param_2,int param_3)
{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  uchar *puVar4;
  undefined2 *puVar5;
  int iVar6;
  PAL_TABLE *pPVar7;
  int iVar8;
  undefined1 *puVar9;
  uchar *puStack_10;
  int iStack_c;
  void *pvStack_8;
  int iStack_4;
  
  iVar8 = 0;
  puStack_10 = (uchar *)0x0;
  iStack_c = -1;
  pvStack_8 = (void *)0x0;
  if ((((param_1 != (char *)0x0) && (*param_1 != '\0')) && (shape_file_first != '\0')) &&
     (iVar2 = __open(param_1,0x8000), iVar2 != -1)) {
    lseek(iVar2,0,2);
    uVar3 = __tell(iVar2);
    puStack_10 = (uchar *)malloc(uVar3);
    if (puStack_10 != (uchar *)0x0) {
      lseek(iVar2,0,0);
      read(iVar2,puStack_10,uVar3);
      iStack_c = 1;
    }
    close(iVar2);
  }
  if (((puStack_10 == (uchar *)0x0) && (param_2 != 0xffffffff)) &&
     (puStack_10 = RESFILE_load(0x62696e61,param_2,&iStack_c,&iStack_4), iStack_c == 0)) {
    puVar4 = (uchar *)malloc(iStack_4);
    memcpy(puVar4,puStack_10,iStack_4);
    iStack_c = 1;
    puStack_10 = puVar4;
  }
  if (puStack_10 == (uchar *)0x0) {
    return (void *)0x0;
  }
  param_1._0_3_ = CONCAT12(DAT_005837c6,s___);
  iVar2 = strtok(puStack_10,&param_1);
  if (((iVar2 != 0) && (iVar2 = strtok(0,&param_1), iVar2 != 0)) &&
     (iVar2 = strtok(0,&param_1), iVar2 != 0)) {
    iVar2 = atol(iVar2);
    puVar5 = (undefined2 *)malloc(iVar2 * 4 + 8);
    param_2 = 0;
    if (puVar5 != (undefined2 *)0x0) {
      puVar5[1] = (short)iVar2;
      *puVar5 = 0x300;
      if (0 < iVar2) {
        puVar9 = (undefined1 *)((int)puVar5 + 5);
        do {
          iVar6 = strtok(0,&param_1);
          if (iVar6 == 0) break;
          uVar1 = atoi(iVar6);
          puVar9[-1] = uVar1;
          iVar6 = strtok(0,&param_1);
          if (iVar6 == 0) break;
          uVar1 = atoi(iVar6);
          *puVar9 = uVar1;
          iVar6 = strtok(0,&param_1);
          if (iVar6 == 0) break;
          uVar1 = atoi(iVar6);
          puVar9[1] = uVar1;
          puVar9[2] = 0;
          if (iVar8 == iVar2 + -1) {
            param_2 = 1;
          }
          iVar8 = iVar8 + 1;
          puVar9 = puVar9 + 4;
        } while (iVar8 < iVar2);
      }
      if (param_2 != 0) {
        if ((iVar2 == 0x100) && (-1 < (int)System_color_Table)) {
          pPVar7 = System_color_Table;
          puVar9 = &DAT_005841e5;
          do {
            *(undefined1 *)(puVar5 + (int)pPVar7 * 2 + 2) = puVar9[-1];
            *(undefined1 *)((int)puVar5 + (int)pPVar7 * 4 + 5) = *puVar9;
            *(undefined1 *)(puVar5 + (int)pPVar7 * 2 + 3) = puVar9[1];
            *(undefined1 *)((int)puVar5 + (int)pPVar7 * 4 + 7) = 0;
            pPVar7 = *(PAL_TABLE **)(puVar9 + 3);
            puVar9 = puVar9 + 8;
          } while (-1 < (int)pPVar7);
        }
        if (((param_2 != 0) && (pvStack_8 = (void *)CreatePalette(puVar5), param_3 != 0)) &&
           ((rge_base_game->draw_system->DrawType == '\x01' ||
            (rge_base_game->draw_system->ScreenMode == '\x01')))) {
          CreateIdentityPalette(pvStack_8);
        }
      }
      free(puVar5);
    }
  }
  if (iStack_c == 1) {
    free(puStack_10);
  }
  return pvStack_8;
}

// --------------------------------------------------

// Function: ReadPalette
// Address: 00439750
// XREFS: get_palette
// [HELPER] s___: "]\n"
// [HELPER] shape_file_first: " "
/* WARNING: Variable defined which should be unmapped: data */
/* void * __cdecl ReadPalette(char *,long,int) */

void * __cdecl ReadPalette(char *param_1,long param_2,int param_3)
{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  PAL_TABLE *pPVar6;
  int iVar7;
  undefined1 *puVar8;
  char *data;
  int own_mem;
  void *hpal;
  int resDataSize;
  int local_4;
  
  iVar7 = 0;
  own_mem = 0;
  hpal = (void *)0xffffffff;
  resDataSize = 0;
  if ((((param_1 != (char *)0x0) && (*param_1 != '\0')) && (shape_file_first != '\0')) &&
     (iVar2 = __open(param_1,0x8000), iVar2 != -1)) {
    lseek(iVar2,0,2);
    uVar3 = __tell(iVar2);
    own_mem = malloc(uVar3);
    if (own_mem != 0) {
      lseek(iVar2,0,0);
      read(iVar2,own_mem,uVar3);
      hpal = (void *)0x1;
    }
    close(iVar2);
  }
  if (((own_mem == 0) && (param_2 != -1)) &&
     (own_mem = (int)RESFILE_load(0x62696e61,param_2,(int *)&hpal,&local_4), hpal == (void *)0x0)) {
    iVar2 = malloc(local_4);
    memcpy(iVar2,own_mem,local_4);
    hpal = (void *)0x1;
    own_mem = iVar2;
  }
  if (own_mem == 0) {
    return (void *)0x0;
  }
  param_1._0_3_ = CONCAT12(DAT_005837c6,s___);
  iVar2 = strtok(own_mem,&param_1);
  if (((iVar2 != 0) && (iVar2 = strtok(0,&param_1), iVar2 != 0)) &&
     (iVar2 = strtok(0,&param_1), iVar2 != 0)) {
    iVar2 = atol(iVar2);
    puVar4 = (undefined2 *)malloc(iVar2 * 4 + 8);
    param_2 = 0;
    if (puVar4 != (undefined2 *)0x0) {
      puVar4[1] = (short)iVar2;
      *puVar4 = 0x300;
      if (0 < iVar2) {
        puVar8 = (undefined1 *)((int)puVar4 + 5);
        do {
          iVar5 = strtok(0,&param_1);
          if (iVar5 == 0) break;
          uVar1 = atoi(iVar5);
          puVar8[-1] = uVar1;
          iVar5 = strtok(0,&param_1);
          if (iVar5 == 0) break;
          uVar1 = atoi(iVar5);
          *puVar8 = uVar1;
          iVar5 = strtok(0,&param_1);
          if (iVar5 == 0) break;
          uVar1 = atoi(iVar5);
          puVar8[1] = uVar1;
          puVar8[2] = 0;
          if (iVar7 == iVar2 + -1) {
            param_2 = 1;
          }
          iVar7 = iVar7 + 1;
          puVar8 = puVar8 + 4;
        } while (iVar7 < iVar2);
      }
      if (param_2 != 0) {
        if ((iVar2 == 0x100) && (-1 < (int)System_color_Table)) {
          pPVar6 = System_color_Table;
          puVar8 = &DAT_005841e5;
          do {
            *(undefined1 *)(puVar4 + (int)pPVar6 * 2 + 2) = puVar8[-1];
            *(undefined1 *)((int)puVar4 + (int)pPVar6 * 4 + 5) = *puVar8;
            *(undefined1 *)(puVar4 + (int)pPVar6 * 2 + 3) = puVar8[1];
            *(undefined1 *)((int)puVar4 + (int)pPVar6 * 4 + 7) = 0;
            pPVar6 = *(PAL_TABLE **)(puVar8 + 3);
            puVar8 = puVar8 + 8;
          } while (-1 < (int)pPVar6);
        }
        if (((param_2 != 0) && (resDataSize = CreatePalette(puVar4), param_3 != 0)) &&
           ((rge_base_game->draw_system->DrawType == '\x01' ||
            (rge_base_game->draw_system->ScreenMode == '\x01')))) {
          CreateIdentityPalette((void *)resDataSize);
        }
      }
      free(puVar4);
    }
  }
  if (hpal == (void *)0x1) {
    free(own_mem);
  }
  return (void *)resDataSize;
}

// --------------------------------------------------

// Function: FUN_00439a0a
// Address: 00439a0a
// XREFS: None
int * FUN_00439a0a(undefined4 param_1)
{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  tagBITMAPINFOHEADER *ptVar6;
  ulong uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 auStack_88 [136];
  
  iVar3 = OpenFile(param_1,auStack_88,0);
  if (iVar3 == -1) {
    uVar9 = 2;
    uVar4 = GetModuleHandleA(0,param_1,2);
    iVar3 = FindResourceA(uVar4,param_1,uVar9);
    if (iVar3 != 0) {
      uVar4 = GetModuleHandleA(0,iVar3);
      uVar4 = LoadResource(uVar4);
      piVar5 = (int *)LockResource(uVar4);
      return piVar5;
    }
    return (int *)0x0;
  }
  ptVar6 = DibReadBitmapInfo(iVar3);
  if (ptVar6 == (tagBITMAPINFOHEADER *)0x0) {
    return (int *)0x0;
  }
  uVar7 = ptVar6->biClrUsed;
  uVar1 = ptVar6->biSizeImage;
  if ((uVar7 == 0) && (ptVar6->biBitCount < 9)) {
    uVar7 = 1 << ((byte)ptVar6->biBitCount & 0x1f);
  }
  uVar2 = ptVar6->biSize;
  uVar4 = GlobalHandle(ptVar6);
  GlobalUnlock(uVar4);
  uVar8 = 0;
  uVar9 = GlobalHandle(ptVar6,uVar1 + uVar7 * 4 + uVar2,0);
  uVar9 = GlobalReAlloc(uVar9);
  piVar5 = (int *)GlobalLock(uVar9);
  if (piVar5 == (int *)0x0) {
    uVar9 = GlobalHandle(ptVar6);
    GlobalUnlock(uVar9);
    uVar9 = GlobalHandle(ptVar6);
    GlobalFree(uVar9);
    piVar5 = (int *)0x0;
  }
  if (piVar5 != (int *)0x0) {
    iVar3 = piVar5[8];
    if ((iVar3 == 0) && (*(ushort *)((int)piVar5 + 0xe) < 9)) {
      iVar3 = 1 << ((byte)*(ushort *)((int)piVar5 + 0xe) & 0x1f);
    }
    _hread(uVar8,(int)piVar5 + *piVar5 + iVar3 * 4,uVar4);
  }
  _lclose(uVar8);
  return piVar5;
}

// --------------------------------------------------

// Function: DibOpenFile
// Address: 00439a10
// XREFS: GetPaletteFromDib, Load
/* WARNING: Variable defined which should be unmapped: fh */
/* struct tagBITMAPINFOHEADER * __cdecl DibOpenFile(char *) */

tagBITMAPINFOHEADER * __cdecl DibOpenFile(char *param_1)
{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  tagBITMAPINFOHEADER *ptVar4;
  ulong uVar5;
  tagBITMAPINFOHEADER *ptVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int fh;
  ulong dwBits;
  _OFSTRUCT of;
  
  iVar2 = OpenFile(param_1,&of.Reserved1,0);
  if (iVar2 == -1) {
    uVar8 = 2;
    uVar3 = GetModuleHandleA(0,param_1,2);
    iVar2 = FindResourceA(uVar3,param_1,uVar8);
    if (iVar2 != 0) {
      uVar3 = GetModuleHandleA(0,iVar2);
      uVar3 = LoadResource(uVar3);
      ptVar4 = (tagBITMAPINFOHEADER *)LockResource(uVar3);
      return ptVar4;
    }
    return (tagBITMAPINFOHEADER *)0x0;
  }
  ptVar4 = DibReadBitmapInfo(iVar2);
  if (ptVar4 == (tagBITMAPINFOHEADER *)0x0) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  uVar5 = ptVar4->biClrUsed;
  of._0_4_ = ptVar4->biSizeImage;
  if ((uVar5 == 0) && (ptVar4->biBitCount < 9)) {
    uVar5 = 1 << ((byte)ptVar4->biBitCount & 0x1f);
  }
  uVar1 = ptVar4->biSize;
  iVar2 = of._0_4_ + uVar5 * 4;
  uVar3 = GlobalHandle(ptVar4);
  GlobalUnlock(uVar3);
  uVar7 = 0;
  uVar8 = GlobalHandle(ptVar4,iVar2 + uVar1,0);
  uVar8 = GlobalReAlloc(uVar8);
  ptVar6 = (tagBITMAPINFOHEADER *)GlobalLock(uVar8);
  if (ptVar6 == (tagBITMAPINFOHEADER *)0x0) {
    uVar8 = GlobalHandle(ptVar4);
    GlobalUnlock(uVar8);
    uVar8 = GlobalHandle(ptVar4);
    GlobalFree(uVar8);
    ptVar6 = (tagBITMAPINFOHEADER *)0x0;
  }
  if (ptVar6 != (tagBITMAPINFOHEADER *)0x0) {
    uVar5 = ptVar6->biClrUsed;
    if ((uVar5 == 0) && (ptVar6->biBitCount < 9)) {
      uVar5 = 1 << ((byte)ptVar6->biBitCount & 0x1f);
    }
    _hread(uVar7,(int)&ptVar6->biSize + ptVar6->biSize + uVar5 * 4,uVar3);
  }
  _lclose(uVar7);
  return ptVar6;
}

// --------------------------------------------------

// Function: FUN_00439b4e
// Address: 00439b4e
// XREFS: None
int FUN_00439b4e(undefined4 param_1)
{
  ulong uVar1;
  int iVar2;
  tagBITMAPINFOHEADER *ptVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 auStack_88 [136];
  
  iVar5 = 0;
  iVar2 = OpenFile(param_1,auStack_88,0);
  if (iVar2 == -1) {
    return 0;
  }
  ptVar3 = DibReadBitmapInfo(iVar2);
  if (ptVar3 != (tagBITMAPINFOHEADER *)0x0) {
    uVar1 = ptVar3->biSizeImage;
    uVar4 = GlobalHandle(ptVar3);
    GlobalUnlock(uVar4);
    uVar4 = GlobalHandle(ptVar3);
    GlobalFree(uVar4);
    iVar5 = malloc(uVar1);
    if (iVar5 != 0) {
      _hread(iVar2,iVar5,uVar1);
    }
  }
  _lclose(iVar2);
  return iVar5;
}

// --------------------------------------------------

// Function: ReadDibBits
// Address: 00439b50
// XREFS: None
/* WARNING: Variable defined which should be unmapped: of */
/* unsigned char * __cdecl ReadDibBits(char *) */

uchar * __cdecl ReadDibBits(char *param_1)
{
  ulong uVar1;
  int iVar2;
  tagBITMAPINFOHEADER *ptVar3;
  undefined4 uVar4;
  uchar *puVar5;
  _OFSTRUCT of;
  
  puVar5 = (uchar *)0x0;
  iVar2 = OpenFile(param_1,&of.Reserved1,0);
  if (iVar2 == -1) {
    return (uchar *)0x0;
  }
  ptVar3 = DibReadBitmapInfo(iVar2);
  if (ptVar3 != (tagBITMAPINFOHEADER *)0x0) {
    uVar1 = ptVar3->biSizeImage;
    uVar4 = GlobalHandle(ptVar3);
    GlobalUnlock(uVar4);
    uVar4 = GlobalHandle(ptVar3);
    GlobalFree(uVar4);
    puVar5 = (uchar *)malloc(uVar1);
    if (puVar5 != (uchar *)0x0) {
      _hread(iVar2,puVar5,uVar1);
    }
  }
  _lclose(iVar2);
  return puVar5;
}

// --------------------------------------------------

// Function: FUN_00439bd7
// Address: 00439bd7
// XREFS: None
undefined4
FUN_00439bd7(BITMAPINFO256 *param_1,char *param_2,long param_3,long param_4,int param_5,int param_6)
{
  ushort uVar1;
  BITMAPINFO256 *pBVar2;
  ulong uVar3;
  uchar *puVar4;
  uchar *puVar5;
  
  pBVar2 = (BITMAPINFO256 *)DibCreate(8,param_5,param_6);
  if (pBVar2 == (BITMAPINFO256 *)0x0) {
    return 0;
  }
  uVar3 = (param_1->bmiHeader).biClrUsed;
  if ((uVar3 == 0) && (uVar1 = (param_1->bmiHeader).biBitCount, uVar1 < 9)) {
    uVar3 = 1 << ((byte)uVar1 & 0x1f);
  }
  memcpy((int)&(((BITMAPINFO256 *)(pBVar2->bmiColors + -10))->bmiHeader).biSize +
         (pBVar2->bmiHeader).biSize,
         (int)&(((BITMAPINFO256 *)(param_1->bmiColors + -10))->bmiHeader).biSize +
         (param_1->bmiHeader).biSize,uVar3 << 2);
  if ((param_1->bmiHeader).biCompression == 3) {
    puVar5 = (uchar *)((int)(param_1->bmiColors + -7) + (param_1->bmiHeader).biSize);
  }
  else {
    puVar5 = &param_1->bmiColors[(param_1->bmiHeader).biClrUsed - 10].rgbBlue +
             (param_1->bmiHeader).biSize;
  }
  if ((pBVar2->bmiHeader).biCompression == 3) {
    puVar4 = (uchar *)((int)(pBVar2->bmiColors + -7) + (pBVar2->bmiHeader).biSize);
  }
  else {
    puVar4 = &pBVar2->bmiColors[(pBVar2->bmiHeader).biClrUsed - 10].rgbBlue +
             (pBVar2->bmiHeader).biSize;
  }
  DibBlt(pBVar2,puVar4,(tagRECT *)0x0,0,0,param_5,param_6,param_1,puVar5,param_3,param_4,param_5,
         param_6,1,0,0);
  DibWriteFile((tagBITMAPINFOHEADER *)pBVar2,param_2);
  DibFree((tagBITMAPINFOHEADER *)pBVar2);
  return 1;
}

// --------------------------------------------------

// Function: DibWriteClipped
// Address: 00439be0
// XREFS: None
/* int __cdecl DibWriteClipped(struct tagBITMAPINFOHEADER *,char *,long,long,long,long) */

int __cdecl
DibWriteClipped(tagBITMAPINFOHEADER *param_1,char *param_2,long param_3,long param_4,long param_5,
               long param_6)
{
  BITMAPINFO256 *pBVar1;
  ulong uVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  pBVar1 = (BITMAPINFO256 *)DibCreate(8,param_5,param_6);
  if (pBVar1 == (BITMAPINFO256 *)0x0) {
    return 0;
  }
  uVar2 = param_1->biClrUsed;
  if ((uVar2 == 0) && (param_1->biBitCount < 9)) {
    uVar2 = 1 << ((byte)param_1->biBitCount & 0x1f);
  }
  memcpy((int)&(((BITMAPINFO256 *)(pBVar1->bmiColors + -10))->bmiHeader).biSize +
         (pBVar1->bmiHeader).biSize,(int)&param_1->biSize + param_1->biSize,uVar2 << 2);
  if (param_1->biCompression == 3) {
    puVar4 = (uchar *)((int)&param_1->biPlanes + param_1->biSize);
  }
  else {
    puVar4 = (uchar *)((int)&param_1->biSize + param_1->biSize + param_1->biClrUsed * 4);
  }
  if ((pBVar1->bmiHeader).biCompression == 3) {
    puVar3 = (uchar *)((int)(pBVar1->bmiColors + -7) + (pBVar1->bmiHeader).biSize);
  }
  else {
    puVar3 = &pBVar1->bmiColors[(pBVar1->bmiHeader).biClrUsed - 10].rgbBlue +
             (pBVar1->bmiHeader).biSize;
  }
  DibBlt(pBVar1,puVar3,(tagRECT *)0x0,0,0,param_5,param_6,(BITMAPINFO256 *)param_1,puVar4,param_3,
         param_4,param_5,param_6,1,0,0);
  DibWriteFile((tagBITMAPINFOHEADER *)pBVar1,param_2);
  DibFree((tagBITMAPINFOHEADER *)pBVar1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00439cb4
// Address: 00439cb4
// XREFS: None
undefined4 FUN_00439cb4(int *param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uStack_98;
  int iStack_96;
  undefined2 uStack_92;
  undefined2 uStack_90;
  int iStack_8e;
  undefined1 auStack_88 [136];
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar1 = OpenFile(param_2,auStack_88,0x1002);
  if (iVar1 == -1) {
    return 0;
  }
  iVar2 = param_1[8];
  uStack_98 = 0x4d42;
  uStack_92 = 0;
  iVar3 = param_1[5] + iVar2 * 4 + *param_1;
  uStack_90 = 0;
  iStack_96 = iVar3 + 0xe;
  if ((iVar2 == 0) && (*(ushort *)((int)param_1 + 0xe) < 9)) {
    iVar2 = 1 << ((byte)*(ushort *)((int)param_1 + 0xe) & 0x1f);
  }
  iStack_8e = *param_1 + 0xe + iVar2 * 4;
  _lwrite(iVar1,&uStack_98,0xe);
  _hwrite(iVar1,param_1,iVar3);
  _lclose(iVar1);
  return 1;
}

// --------------------------------------------------

// Function: DibWriteFile
// Address: 00439cc0
// XREFS: DibWriteClipped
/* WARNING: Variable defined which should be unmapped: hdr */
/* int __cdecl DibWriteFile(struct tagBITMAPINFOHEADER *,char *) */

int __cdecl DibWriteFile(tagBITMAPINFOHEADER *param_1,char *param_2)
{
  int iVar1;
  int iVar2;
  tagBITMAPFILEHEADER hdr;
  _OFSTRUCT of;
  
  if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    return 0;
  }
  iVar1 = OpenFile(param_2,&of.Reserved1,0x1002);
  if (iVar1 != -1) {
    hdr.bfSize._2_2_ = 0x4d42;
    hdr.bfOffBits._0_2_ = 0;
    iVar2 = param_1->biSizeImage + param_1->biClrUsed * 4 + param_1->biSize;
    hdr.bfOffBits._2_2_ = 0;
    hdr._6_4_ = iVar2 + 0xe;
    _lwrite(iVar1,(undefined1 *)((int)&hdr.bfSize + 2),0xe);
    _hwrite(iVar1,param_1,iVar2);
    _lclose(iVar1);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00439d7e
// Address: 00439d7e
// XREFS: None
undefined4 FUN_00439d7e(int *param_1)
{
  int iVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_ESI;
  undefined1 *puVar5;
  undefined4 unaff_EDI;
  int iVar6;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar6 = param_1[8];
  if ((iVar6 == 0) && (*(ushort *)((int)param_1 + 0xe) < 9)) {
    iVar6 = 1 << ((byte)*(ushort *)((int)param_1 + 0xe) & 0x1f);
  }
  if ((iVar6 == 3) && (param_1[4] == 3)) {
    iVar6 = 0;
  }
  if (iVar6 < 1) {
    uVar4 = GetDC(0);
    unaff_ESI = CreateHalftonePalette(uVar4);
    ReleaseDC(0,uVar4);
  }
  else {
    iVar1 = *param_1;
    puVar2 = (undefined2 *)LocalAlloc(0x40,iVar6 * 4 + 8);
    if (puVar2 != (undefined2 *)0x0) {
      puVar2[1] = (short)iVar6;
      *puVar2 = 0x300;
      if (0 < iVar6) {
        puVar3 = (undefined1 *)((int)puVar2 + 5);
        puVar5 = (undefined1 *)((int)param_1 + iVar1);
        do {
          puVar3[-1] = puVar5[2];
          *puVar3 = puVar5[1];
          puVar3[1] = *puVar5;
          puVar3[2] = 0;
          puVar3 = puVar3 + 4;
          iVar6 = iVar6 + -1;
          puVar5 = puVar5 + 4;
        } while (iVar6 != 0);
      }
      CreatePalette(puVar2);
      LocalFree(puVar2);
      return unaff_EDI;
    }
  }
  return unaff_ESI;
}

// --------------------------------------------------

// Function: DibCreatePalette
// Address: 00439d80
// XREFS: GetPaletteFromDib
/* WARNING: Variable defined which should be unmapped: hpal */
/* void * __cdecl DibCreatePalette(struct tagBITMAPINFOHEADER *) */

void * __cdecl DibCreatePalette(tagBITMAPINFOHEADER *param_1)
{
  ulong uVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  void *unaff_ESI;
  undefined1 *puVar5;
  void *unaff_EDI;
  ulong uVar6;
  void *hpal;
  
  if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    return (void *)0x0;
  }
  uVar6 = param_1->biClrUsed;
  if ((uVar6 == 0) && (param_1->biBitCount < 9)) {
    uVar6 = 1 << ((byte)param_1->biBitCount & 0x1f);
  }
  if ((uVar6 == 3) && (param_1->biCompression == 3)) {
    uVar6 = 0;
  }
  if ((int)uVar6 < 1) {
    uVar4 = GetDC(0);
    unaff_ESI = (void *)CreateHalftonePalette(uVar4);
    ReleaseDC(0,uVar4);
  }
  else {
    uVar1 = param_1->biSize;
    puVar2 = (undefined2 *)LocalAlloc(0x40,uVar6 * 4 + 8);
    if (puVar2 != (undefined2 *)0x0) {
      puVar2[1] = (short)uVar6;
      *puVar2 = 0x300;
      if (0 < (int)uVar6) {
        puVar3 = (undefined1 *)((int)puVar2 + 5);
        puVar5 = (undefined1 *)((int)&param_1->biSize + uVar1);
        do {
          puVar3[-1] = puVar5[2];
          *puVar3 = puVar5[1];
          puVar3[1] = *puVar5;
          puVar3[2] = 0;
          puVar3 = puVar3 + 4;
          uVar6 = uVar6 - 1;
          puVar5 = puVar5 + 4;
        } while (uVar6 != 0);
      }
      CreatePalette(puVar2);
      LocalFree(puVar2);
      return unaff_EDI;
    }
  }
                    /* Symbol Ref: {@symbol exit} */
  return unaff_ESI;
}

// --------------------------------------------------

// Function: FUN_00439e4b
// Address: 00439e4b
// XREFS: None
int * FUN_00439e4b(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  uint *puVar6;
  int unaff_EBX;
  undefined4 unaff_EBP;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  short asStack_38 [2];
  int aiStack_34 [5];
  uint uStack_20;
  undefined2 uStack_1c;
  byte bStack_1a;
  undefined1 uStack_19;
  undefined2 uStack_18;
  undefined2 uStack_16;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_1 == -1) {
    return (int *)0x0;
  }
  uVar2 = _llseek(param_1,0,1);
  iVar3 = _lread(param_1,asStack_38,0xe);
  if (iVar3 != 0xe) {
    return (int *)0x0;
  }
  if (asStack_38[0] != 0x4d42) {
    aiStack_34._6_4_ = 0;
    _llseek(param_1,uVar2,0);
  }
  iVar3 = _lread(param_1,aiStack_34 + 3,0x28);
  if (iVar3 != 0x28) {
    return (int *)0x0;
  }
  if (aiStack_34[3] == 0xc) {
    uStack_3c = (undefined2)uStack_20;
    uStack_3a = (undefined2)(uStack_20 >> 0x10);
    uVar8 = (uint)aiStack_34[4] >> 0x10;
    aiStack_34[4] = aiStack_34[4] & 0xffff;
    aiStack_34[3] = 0x28;
    bStack_1a = (byte)(uStack_20 >> 0x10);
    uStack_19 = (undefined1)(uStack_20 >> 0x18);
    uStack_18 = 0;
    uStack_16 = 0;
    iStack_14 = 0;
    uStack_10 = 0;
    uStack_c = 0;
    uStack_8 = 0;
    uStack_4 = 0;
    uStack_20 = uVar8;
    uStack_1c = uStack_3c;
    _llseek(param_1,0xffffffe4,1);
  }
  uVar8 = uStack_8;
  if ((uStack_8 == 0) && (CONCAT11(uStack_19,bStack_1a) < 9)) {
    uVar8 = 1 << (bStack_1a & 0x1f);
  }
  if (iStack_14 == 0) {
    iStack_14 = (aiStack_34[4] * (uint)CONCAT11(uStack_19,bStack_1a) + 0x1f >> 3 & 0x1ffffffc) *
                uStack_20;
  }
  if ((uStack_8 == 0) && (CONCAT11(uStack_19,bStack_1a) < 9)) {
    uStack_8 = 1 << (bStack_1a & 0x1f);
  }
  uVar2 = GlobalAlloc(2,aiStack_34[3] + uVar8 * 4);
  piVar4 = (int *)GlobalLock(uVar2);
  if (piVar4 != (int *)0x0) {
    piVar7 = aiStack_34;
    piVar9 = piVar4;
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar9 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar9 = piVar9 + 1;
    }
    iVar3 = (int)piVar4 + *piVar4;
    if (uVar8 != 0) {
      if (uStack_8 == 0xc) {
        _lread(param_1,iVar3,uVar8 * 3);
        iVar1 = uVar8 - 1;
        if (-1 < iVar1) {
          puVar6 = (uint *)(iVar3 + iVar1 * 4);
          puVar5 = (undefined1 *)(uVar8 + iVar3 + iVar1 * 2);
          do {
            uStack_8._0_2_ = CONCAT11(*puVar5,puVar5[-1]);
            uStack_8 = (uint)CONCAT12(puVar5[1],(undefined2)uStack_8);
            *puVar6 = uStack_8;
            puVar6 = puVar6 + -1;
            uVar8 = uVar8 - 1;
            puVar5 = puVar5 + -3;
          } while (uVar8 != 0);
        }
      }
      else {
        _lread(param_1,iVar3,unaff_EBP);
      }
    }
    if (CONCAT22(asStack_38[0],uStack_3a) != 0) {
      _llseek(param_1,CONCAT22(asStack_38[0],uStack_3a) + unaff_EBX,0);
    }
    return piVar4;
  }
  return (int *)0x0;
}

// --------------------------------------------------

// Function: DibReadBitmapInfo
// Address: 00439e50
// XREFS: DibOpenFile, ReadDibBits
/* WARNING: Variable defined which should be unmapped: pdib */
/* struct tagBITMAPINFOHEADER * __cdecl DibReadBitmapInfo(int) */

tagBITMAPINFOHEADER * __cdecl DibReadBitmapInfo(int param_1)
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  tagBITMAPINFOHEADER *ptVar5;
  undefined1 *puVar6;
  ulong *puVar7;
  int unaff_EBX;
  undefined4 unaff_EBP;
  ushort *puVar8;
  ulong uVar9;
  tagBITMAPINFOHEADER *ptVar10;
  tagBITMAPINFOHEADER *pdib;
  ulong off;
  tagBITMAPCOREHEADER bc;
  tagBITMAPFILEHEADER bf;
  tagBITMAPINFOHEADER bi;
  
  if (param_1 == -1) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  uVar3 = _llseek(param_1,0,1);
  iVar4 = _lread(param_1,(undefined1 *)((int)&bf.bfSize + 2),0xe);
  if (iVar4 != 0xe) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  if (bf.bfSize._2_2_ != 0x4d42) {
    _llseek(param_1,uVar3,0);
  }
  iVar4 = _lread(param_1,&bi.biWidth,0x28);
  if (iVar4 != 0x28) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  if (bi.biWidth == 0xc) {
    bf.bfType = bi.biPlanes;
    bf.bfSize._0_2_ = bi.biBitCount;
    uVar2 = (uint)bi.biHeight >> 0x10;
    bi.biHeight = bi.biHeight & 0xffff;
    bi.biWidth = 0x28;
    bi.biCompression._2_1_ = (byte)bi.biBitCount;
    bi.biCompression._3_1_ = bi.biBitCount._1_1_;
    bi.biSizeImage._0_2_ = 0;
    bi.biSizeImage._2_2_ = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;
    bi._12_4_ = uVar2;
    bi.biCompression._0_2_ = bf.bfType;
    _llseek(param_1,0xffffffe4,1);
  }
  uVar9 = bi.biClrImportant;
  if ((bi.biClrImportant == 0) && (CONCAT11(bi.biCompression._3_1_,bi.biCompression._2_1_) < 9)) {
    uVar9 = 1 << (bi.biCompression._2_1_ & 0x1f);
  }
  if (bi.biXPelsPerMeter == 0) {
    bi.biXPelsPerMeter =
         (bi.biHeight * (uint)CONCAT11(bi.biCompression._3_1_,bi.biCompression._2_1_) + 0x1f >> 3 &
         0x1ffffffc) * bi._12_4_;
  }
  if ((bi.biClrImportant == 0) && (CONCAT11(bi.biCompression._3_1_,bi.biCompression._2_1_) < 9)) {
    bi.biClrImportant = 1 << (bi.biCompression._2_1_ & 0x1f);
  }
  uVar3 = GlobalAlloc(2,bi.biWidth + uVar9 * 4);
  ptVar5 = (tagBITMAPINFOHEADER *)GlobalLock(uVar3);
  if (ptVar5 != (tagBITMAPINFOHEADER *)0x0) {
    puVar8 = &bf.bfReserved2;
    ptVar10 = ptVar5;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      ptVar10->biSize = *(ulong *)puVar8;
      puVar8 = puVar8 + 2;
      ptVar10 = (tagBITMAPINFOHEADER *)&ptVar10->biWidth;
    }
    iVar4 = (int)&ptVar5->biSize + ptVar5->biSize;
    if (uVar9 != 0) {
      if (bi.biClrImportant == 0xc) {
        _lread(param_1,iVar4,uVar9 * 3);
        iVar1 = uVar9 - 1;
        if (-1 < iVar1) {
          puVar7 = (ulong *)(iVar4 + iVar1 * 4);
          puVar6 = (undefined1 *)(uVar9 + iVar4 + iVar1 * 2);
          do {
            bi.biClrImportant._0_2_ = CONCAT11(*puVar6,puVar6[-1]);
            bi.biClrImportant = (ulong)CONCAT12(puVar6[1],(undefined2)bi.biClrImportant);
            *puVar7 = bi.biClrImportant;
            puVar7 = puVar7 + -1;
            uVar9 = uVar9 - 1;
            puVar6 = puVar6 + -3;
          } while (uVar9 != 0);
        }
      }
      else {
        _lread(param_1,iVar4,unaff_EBP);
      }
    }
    if (CONCAT22(bf.bfSize._2_2_,(ushort)bf.bfSize) != 0) {
      _llseek(param_1,CONCAT22(bf.bfSize._2_2_,(ushort)bf.bfSize) + unaff_EBX,0);
    }
    return ptVar5;
  }
  return (tagBITMAPINFOHEADER *)0x0;
}

// --------------------------------------------------

// Function: DibFromBitmap
// Address: 0043a070
// XREFS: None
/* WARNING: Variable defined which should be unmapped: nColors */
/* struct tagBITMAPINFOHEADER * __cdecl DibFromBitmap(void *,unsigned long,unsigned int,void
   *,unsigned int) */

tagBITMAPINFOHEADER * __cdecl
DibFromBitmap(void *param_1,ulong param_2,uint param_3,void *param_4,uint param_5)
{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  tagBITMAPINFOHEADER *ptVar5;
  ulong uVar6;
  ulong uVar7;
  int unaff_EBX;
  undefined4 unaff_EBP;
  int nColors;
  tagBITMAP bm;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  bm.bmType = 0;
  if (param_1 == (void *)0x0) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  if (param_4 == (void *)0x0) {
    param_4 = (void *)GetStockObject(0xf);
  }
  GetObjectA(param_1,0x18,&bm.bmWidth);
  GetObjectA(param_4,4,&bm);
  if (param_3 == 0) {
    param_3 = (uint)(ushort)bm.bmBits * (uint)bm.bmBits._2_2_;
  }
  uVar1 = GlobalAlloc(2,0x428);
  piVar2 = (int *)GlobalLock(uVar1);
  if (piVar2 == (int *)0x0) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  *piVar2 = 0x28;
  piVar2[1] = unaff_EBX;
  piVar2[2] = bm.bmType;
  *(undefined2 *)(piVar2 + 3) = 1;
  *(ushort *)((int)piVar2 + 0xe) = (ushort)param_3;
  piVar2[4] = CONCAT22(uStack_2,uStack_4);
  piVar2[5] = 0;
  piVar2[6] = 0;
  piVar2[7] = 0;
  piVar2[8] = 0;
  piVar2[9] = 0;
  if ((ushort)param_3 < 9) {
    iVar3 = 1 << ((byte)param_3 & 0x1f);
  }
  else {
    iVar3 = 0;
  }
  piVar2[8] = iVar3;
  if (CONCAT22(uStack_2,uStack_4) == 3) {
    if (param_3 == 0x10) {
      piVar2[10] = 0xf800;
                    /* language.dll match for 0x7e0: "Age of Empires Expansion requires Age of
                       Empires 1.0, 1.0A, or 1.0B to be installed." */
      piVar2[0xb] = 0x7e0;
      piVar2[0xc] = 0x1f;
    }
    else if ((param_3 == 0x18) || (param_3 == 0x20)) {
      piVar2[10] = 0xff;
      piVar2[0xb] = 0xff00;
      piVar2[0xc] = 0xff0000;
    }
  }
  uVar1 = CreateCompatibleDC(0);
  SelectPalette(uVar1,param_4,0);
  RealizePalette(uVar1);
  SetStretchBltMode(uVar1,4);
  GetDIBits(uVar1,param_1,0,piVar2[2],0,piVar2,param_2);
  iVar3 = piVar2[8];
  if ((iVar3 == 0) && (*(ushort *)((int)piVar2 + 0xe) < 9)) {
    iVar3 = 1 << ((byte)*(ushort *)((int)piVar2 + 0xe) & 0x1f);
  }
  piVar2[8] = iVar3;
  iVar3 = piVar2[5];
  if (iVar3 == 0) {
    iVar3 = ((uint)*(ushort *)((int)piVar2 + 0xe) * piVar2[1] + 0x1f >> 3 & 0x1ffffffc) * piVar2[2];
  }
  piVar2[5] = iVar3;
  if (iVar3 == 0) {
    iVar3 = ((uint)*(ushort *)((int)piVar2 + 0xe) * piVar2[1] + 0x1f >> 3 & 0x1ffffffc) * piVar2[2];
    piVar2[5] = iVar3;
    if (CONCAT22(uStack_2,uStack_4) != 0) {
      piVar2[5] = (uint)(iVar3 * 3) >> 1;
    }
  }
  uVar4 = GlobalHandle(piVar2);
  GlobalUnlock(uVar4);
  uVar4 = GlobalHandle(piVar2,*piVar2 + piVar2[8] * 4 + piVar2[5],0);
  uVar4 = GlobalReAlloc(uVar4);
  ptVar5 = (tagBITMAPINFOHEADER *)GlobalLock(uVar4);
  if (ptVar5 == (tagBITMAPINFOHEADER *)0x0) {
    uVar4 = GlobalHandle(piVar2);
    GlobalUnlock(uVar4);
    uVar4 = GlobalHandle(piVar2);
    GlobalFree(uVar4);
  }
  else {
    if (ptVar5->biCompression == 3) {
      iVar3 = ptVar5->biSize + 0xc;
    }
    else {
      iVar3 = ptVar5->biSize + ptVar5->biClrUsed * 4;
    }
    iVar3 = GetDIBits(uVar1,unaff_EBP,0,ptVar5->biHeight,(int)&ptVar5->biSize + iVar3,ptVar5,
                      bm.bmHeight);
    uVar7 = ptVar5->biClrUsed;
    if ((uVar7 == 0) && (ptVar5->biBitCount < 9)) {
      uVar7 = 1 << ((byte)ptVar5->biBitCount & 0x1f);
    }
    uVar6 = ptVar5->biSizeImage;
    ptVar5->biClrUsed = uVar7;
    if (uVar6 == 0) {
      uVar6 = (ptVar5->biWidth * (uint)ptVar5->biBitCount + 0x1f >> 3 & 0x1ffffffc) *
              ptVar5->biHeight;
    }
    ptVar5->biSizeImage = uVar6;
    if (iVar3 != 0) goto LAB_0043a307;
    DibFree(ptVar5);
  }
  ptVar5 = (tagBITMAPINFOHEADER *)0x0;
LAB_0043a307:
                    /* Symbol Ref: {@symbol exit} */
  SelectPalette(uVar1,bm.bmWidth,0);
  DeleteDC(uVar1);
  return ptVar5;
}

// --------------------------------------------------

// Function: FUN_0043a326
// Address: 0043a326
// XREFS: None
undefined4 FUN_0043a326(int *param_1,int param_2,int param_3)
{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined1 auStack_400 [1024];
  
  if (param_2 == 0) {
    param_2 = GetStockObject(0xf);
  }
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar6 = param_1[8];
  if ((iVar6 == 0) && (*(ushort *)((int)param_1 + 0xe) < 9)) {
    iVar6 = 1 << ((byte)*(ushort *)((int)param_1 + 0xe) & 0x1f);
  }
  if ((iVar6 == 3) && (param_1[4] == 3)) {
    iVar6 = 0;
  }
  if (0 < iVar6) {
    puVar5 = (undefined2 *)(*param_1 + (int)param_1);
    if (param_3 == 1) {
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          *puVar5 = (short)iVar3;
          iVar3 = iVar3 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar3 < iVar6);
      }
    }
    else {
      if (0xff < iVar6) {
        iVar6 = 0x100;
      }
      GetPaletteEntries(param_2,0,iVar6,auStack_400);
      if (0 < iVar6) {
        puVar4 = auStack_400;
        puVar2 = (undefined1 *)((int)puVar5 + 1);
        do {
          uVar1 = *puVar4;
          puVar4 = puVar4 + 4;
          puVar2[1] = uVar1;
          *puVar2 = puVar2[(int)(auStack_400 + -(int)puVar5)];
          puVar2[-1] = puVar2[(int)(auStack_400 + (1 - (int)puVar5))];
          puVar2[2] = 0;
          puVar2 = puVar2 + 4;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        return 1;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: DibSetUsage
// Address: 0043a330
// XREFS: None
/* WARNING: Variable defined which should be unmapped: ape */
/* int __cdecl DibSetUsage(struct tagBITMAPINFOHEADER *,void *,unsigned int) */

int __cdecl DibSetUsage(tagBITMAPINFOHEADER *param_1,void *param_2,uint param_3)
{
  undefined1 *puVar1;
  int iVar2;
  tagPALETTEENTRY *ptVar3;
  undefined2 *puVar4;
  ulong uVar5;
  tagPALETTEENTRY ape [256];
  
  if (param_2 == (void *)0x0) {
    param_2 = (void *)GetStockObject(0xf);
  }
  if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    return 0;
  }
  uVar5 = param_1->biClrUsed;
  if ((uVar5 == 0) && (param_1->biBitCount < 9)) {
    uVar5 = 1 << ((byte)param_1->biBitCount & 0x1f);
  }
  if ((uVar5 == 3) && (param_1->biCompression == 3)) {
    uVar5 = 0;
  }
  if (0 < (int)uVar5) {
    puVar4 = (undefined2 *)((int)&param_1->biSize + param_1->biSize);
    if (param_3 == 1) {
      iVar2 = 0;
      if (0 < (int)uVar5) {
        do {
          *puVar4 = (short)iVar2;
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 1;
        } while (iVar2 < (int)uVar5);
      }
    }
    else {
      if (0xff < (int)uVar5) {
        uVar5 = 0x100;
      }
      GetPaletteEntries(param_2,0,uVar5,ape + 1);
      if (0 < (int)uVar5) {
        ptVar3 = ape;
        puVar1 = (undefined1 *)((int)puVar4 + 1);
        do {
          ptVar3 = ptVar3 + 1;
          puVar1[1] = ptVar3->peRed;
          *puVar1 = puVar1[(int)ape + (4 - (int)puVar4)];
          puVar1[-1] = puVar1[(int)ape + (5 - (int)puVar4)];
          puVar1[2] = 0;
          puVar1 = puVar1 + 4;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
        return 1;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: DibDraw
// Address: 0043a420
// XREFS: None
/* int __cdecl DibDraw(void *,int,int,int,int,struct tagBITMAPINFOHEADER
   *,int,int,int,int,long,unsigned int) */

int __cdecl
DibDraw(void *param_1,int param_2,int param_3,int param_4,int param_5,tagBITMAPINFOHEADER *param_6,
       int param_7,int param_8,int param_9,int param_10,long param_11,uint param_12)
{
  int iVar1;
  
  if (param_6 == (tagBITMAPINFOHEADER *)0x0) {
    return (int)param_6;
  }
  if ((param_9 == -1) && (param_10 == -1)) {
    param_9 = param_6->biWidth;
    param_10 = param_6->biHeight;
  }
  if ((param_4 == -1) && (param_5 == -1)) {
    param_4 = param_9;
    param_5 = param_10;
  }
  if (param_6->biCompression == 3) {
    iVar1 = param_6->biSize + 0xc;
  }
  else {
    iVar1 = param_6->biSize + param_6->biClrUsed * 4;
  }
  iVar1 = StretchDIBits(param_1,param_2,param_3,param_4,param_5,param_7,param_8,param_9,param_10,
                        (int)&param_6->biSize + iVar1,param_6,param_12,param_11);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0043a4a8
// Address: 0043a4a8
// XREFS: None
int FUN_0043a4a8(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  uVar1 = GlobalAlloc(2,*param_1 + param_1[8] * 4 + param_1[5]);
  iVar2 = GlobalLock(uVar1);
  if (iVar2 != 0) {
    memcpy(iVar2,param_1,*param_1 + param_1[8] * 4 + param_1[5]);
  }
  return iVar2;
}

// --------------------------------------------------

// Function: DibCopy
// Address: 0043a4b0
// XREFS: None
/* struct tagBITMAPINFOHEADER * __cdecl DibCopy(struct tagBITMAPINFOHEADER *) */

tagBITMAPINFOHEADER * __cdecl DibCopy(tagBITMAPINFOHEADER *param_1)
{
  undefined4 uVar1;
  tagBITMAPINFOHEADER *ptVar2;
  
  if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  uVar1 = GlobalAlloc(2,param_1->biSize + param_1->biClrUsed * 4 + param_1->biSizeImage);
  ptVar2 = (tagBITMAPINFOHEADER *)GlobalLock(uVar1);
  if (ptVar2 != (tagBITMAPINFOHEADER *)0x0) {
    memcpy(ptVar2,param_1,param_1->biSize + param_1->biClrUsed * 4 + param_1->biSizeImage);
  }
  return ptVar2;
}

// --------------------------------------------------

