// Class: TCommunications_Sessions
// Function: TCommunications_Sessions
// Address: 00432200
/* public: __thiscall TCommunications_Sessions::TCommunications_Sessions(class
   TCommunications_Handler *) */

TCommunications_Sessions * __thiscall
TCommunications_Sessions::TCommunications_Sessions
          (TCommunications_Sessions *this,TCommunications_Handler *param_1)
{
  DAT_0062cf68 = param_1;
  glpSERV = TCommunications_Handler::GetDPInterface(param_1);
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
  this->SessionCount = 0;
  EraseInformation(this);
  Refresh(this);
  return this;
}

// --------------------------------------------------

// Function: ~TCommunications_Sessions
// Address: 00432290
/* public: __thiscall TCommunications_Sessions::~TCommunications_Sessions(void) */

void __thiscall TCommunications_Sessions::~TCommunications_Sessions(TCommunications_Sessions *this)
{
  return;
}

// --------------------------------------------------

// Function: EraseInformation
// Address: 004322a0
/* private: void __thiscall TCommunications_Sessions::EraseInformation(void) */

void __thiscall TCommunications_Sessions::EraseInformation(TCommunications_Sessions *this)
{
  int iVar1;
  SEs *pSVar2;
  
  this->SessionCount = 0;
  pSVar2 = this->Session;
  for (iVar1 = 0x115e6; iVar1 != 0; iVar1 = iVar1 + -1) {
    pSVar2->Name[0] = '\0';
    pSVar2->Name[1] = '\0';
    pSVar2->Name[2] = '\0';
    pSVar2->Name[3] = '\0';
    pSVar2 = (SEs *)(pSVar2->Name + 4);
  }
  return;
}

// --------------------------------------------------

// Function: GetSessionCount
// Address: 004322c0
/* public: int __thiscall TCommunications_Sessions::GetSessionCount(void) */

int __thiscall TCommunications_Sessions::GetSessionCount(TCommunications_Sessions *this)
{
  return this->SessionCount;
}

// --------------------------------------------------

// Function: GetSessionName
// Address: 004322d0
/* public: char * __thiscall TCommunications_Sessions::GetSessionName(int) */

char * __thiscall
TCommunications_Sessions::GetSessionName(TCommunications_Sessions *this,int param_1)
{
  if ((-1 < param_1) && (param_1 <= this->SessionCount)) {
    return this->Session[param_1].Name;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: GetSessionMaxPlayers
// Address: 004322f0
/* public: unsigned long __thiscall TCommunications_Sessions::GetSessionMaxPlayers(int) */

ulong __thiscall
TCommunications_Sessions::GetSessionMaxPlayers(TCommunications_Sessions *this,int param_1)
{
  if ((-1 < param_1) && (param_1 <= this->SessionCount)) {
    return this->Session[param_1].MaxPlayers;
  }
  return 0;
}

// --------------------------------------------------

// Function: GetSessionCurrentPlayers
// Address: 00432320
/* public: unsigned long __thiscall TCommunications_Sessions::GetSessionCurrentPlayers(int) */

ulong __thiscall
TCommunications_Sessions::GetSessionCurrentPlayers(TCommunications_Sessions *this,int param_1)
{
  if ((-1 < param_1) && (param_1 <= this->SessionCount)) {
    return this->Session[param_1].CurrentPlayers;
  }
  return 0;
}

// --------------------------------------------------

// Function: GetSessionGUID
// Address: 00432350
/* public: struct _GUID * __thiscall TCommunications_Sessions::GetSessionGUID(int) */

_GUID * __thiscall
TCommunications_Sessions::GetSessionGUID(TCommunications_Sessions *this,int param_1)
{
  if ((-1 < param_1) && (param_1 <= this->SessionCount)) {
    return &this->Session[param_1].SessGUID;
  }
  return (_GUID *)0x0;
}

// --------------------------------------------------

// Function: IncSessionCount
// Address: 00432380
/* public: int __thiscall TCommunications_Sessions::IncSessionCount(void) */

int __thiscall TCommunications_Sessions::IncSessionCount(TCommunications_Sessions *this)
{
  int iVar1;
  
  iVar1 = this->SessionCount + 1;
  this->SessionCount = iVar1;
  return iVar1;
}

// --------------------------------------------------

// Function: AddSession
// Address: 00432390
/* public: int __thiscall TCommunications_Sessions::AddSession(struct _GUID,struct _GUID,unsigned
   long,unsigned long,char *,char *,unsigned long,unsigned long,unsigned long,unsigned long) */

int __thiscall
TCommunications_Sessions::AddSession
          (TCommunications_Sessions *this,_GUID param_1,_GUID param_2,ulong param_3,ulong param_4,
          char *param_5,char *param_6,ulong param_7,ulong param_8,ulong param_9,ulong param_10)
{
  _GUID *p_Var1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  SEs *pSVar6;
  char *pcVar7;
  
  p_Var1 = &this->Session[this->SessionCount].AppGUID;
  p_Var1->Data1 = param_2.Data1;
  p_Var1->Data2 = param_2.Data2;
  p_Var1->Data3 = param_2.Data3;
  *(undefined4 *)p_Var1->Data4 = param_2.Data4._0_4_;
  *(undefined4 *)(p_Var1->Data4 + 4) = param_2.Data4._4_4_;
  p_Var1 = &this->Session[this->SessionCount].SessGUID;
  p_Var1->Data1 = param_1.Data1;
  p_Var1->Data2 = param_1.Data2;
  p_Var1->Data3 = param_1.Data3;
  *(undefined4 *)p_Var1->Data4 = param_1.Data4._0_4_;
  *(undefined4 *)(p_Var1->Data4 + 4) = param_1.Data4._4_4_;
  this->Session[this->SessionCount].MaxPlayers = param_3;
  this->Session[this->SessionCount].CurrentPlayers = param_4;
  this->Session[this->SessionCount].User1 = param_7;
  this->Session[this->SessionCount].User1 = param_8;
  this->Session[this->SessionCount].User1 = param_9;
  this->Session[this->SessionCount].User1 = param_10;
  if (param_5 != (char *)0x0) {
    uVar3 = 0xffffffff;
    do {
      pcVar5 = param_5;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar5 = param_5 + 1;
      cVar2 = *param_5;
      param_5 = pcVar5;
    } while (cVar2 != '\0');
    uVar3 = ~uVar3;
    pcVar5 = pcVar5 + -uVar3;
    pSVar6 = this->Session + this->SessionCount;
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
  if (param_6 != (char *)0x0) {
    uVar3 = 0xffffffff;
    do {
      pcVar5 = param_6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar5 = param_6 + 1;
      cVar2 = *param_6;
      param_6 = pcVar5;
    } while (cVar2 != '\0');
    uVar3 = ~uVar3;
    pcVar5 = pcVar5 + -uVar3;
    pcVar7 = this->Session[this->SessionCount].Password;
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
  IncSessionCount(this);
  return 1;
}

// --------------------------------------------------

// Function: Refresh
// Address: 004324f0
/* WARNING: Variable defined which should be unmapped: dpDesc */
/* public: int __thiscall TCommunications_Sessions::Refresh(void) */

int __thiscall TCommunications_Sessions::Refresh(TCommunications_Sessions *this)
{
  int iVar1;
  DPSESSIONDESC2 *pDVar2;
  DPSESSIONDESC2 dpDesc;
  
  EraseInformation(this);
  pDVar2 = &dpDesc;
  for (iVar1 = 0x14; pDVar2 = (DPSESSIONDESC2 *)&pDVar2->dwFlags, iVar1 != 0; iVar1 = iVar1 + -1) {
    *(ulong *)pDVar2 = 0;
  }
  dpDesc.guidApplication.Data2 = (undefined2)ApplicationGUID.Data1;
  dpDesc.guidApplication.Data3 = ApplicationGUID.Data1._2_2_;
  dpDesc.dwMaxPlayers._0_1_ = ApplicationGUID.Data4[4];
  dpDesc.dwMaxPlayers._1_1_ = ApplicationGUID.Data4[5];
  dpDesc.dwMaxPlayers._2_1_ = ApplicationGUID.Data4[6];
  dpDesc.dwMaxPlayers._3_1_ = ApplicationGUID.Data4[7];
  dpDesc.guidApplication.Data4[4] = ApplicationGUID.Data4[0];
  dpDesc.guidApplication.Data4[5] = ApplicationGUID.Data4[1];
  dpDesc.guidApplication.Data4[6] = ApplicationGUID.Data4[2];
  dpDesc.guidApplication.Data4[7] = ApplicationGUID.Data4[3];
  dpDesc.guidApplication.Data4._0_4_ = ApplicationGUID._4_4_;
  dpDesc.dwFlags = 0x50;
  iVar1 = (**(code **)((int)*glpSERV + 0x34))(glpSERV,&dpDesc.dwFlags,0,EnumSessionCallback,this,1);
  return iVar1;
}

// --------------------------------------------------

// Function: IsEqualGuid
// Address: 004325e0
/* public: int __thiscall TCommunications_Sessions::IsEqualGuid(struct _GUID *,struct _GUID *) */

int __thiscall
TCommunications_Sessions::IsEqualGuid(TCommunications_Sessions *this,_GUID *param_1,_GUID *param_2)
{
  int iVar1;
  int iVar2;
  
  if ((((param_1->Data1 == param_2->Data1) &&
       (iVar1._0_2_ = param_1->Data2, iVar1._2_2_ = param_1->Data3, iVar2._0_2_ = param_2->Data2,
       iVar2._2_2_ = param_2->Data3, iVar1 == iVar2)) &&
      (*(int *)param_1->Data4 == *(int *)param_2->Data4)) &&
     (*(int *)(param_1->Data4 + 4) == *(int *)(param_2->Data4 + 4))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

