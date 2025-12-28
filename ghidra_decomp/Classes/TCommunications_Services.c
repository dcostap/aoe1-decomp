// Class: TCommunications_Services
// Size:  0x2584
//
// Member Layout:
// [0x000] SPs[100] Service (sz: 0x2580)
// [0x2580] int ServiceCount
// ----------------------------------------------------------------

// Function: TCommunications_Services
// Address: 00431fb0
// [HELPER] s_: ""
TCommunications_Services * __thiscall
TCommunications_Services::TCommunications_Services(TCommunications_Services *this)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  SPs *pSVar8;
  
  this->ServiceCount = 0;
  iVar5 = 100;
  piVar4 = &this->Service[0].Active;
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
    pSVar8 = (SPs *)(piVar4 + -0x17);
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pSVar8->Name = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pSVar8 = (SPs *)(pSVar8->Name + 4);
    }
    iVar5 = iVar5 + -1;
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      pSVar8->Name[0] = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pSVar8 = (SPs *)(pSVar8->Name + 1);
    }
    piVar4[-3] = 0;
    *piVar4 = 0;
    piVar4[-1] = 0;
    piVar4[-2] = 0;
    piVar4 = piVar4 + 0x18;
    if (iVar5 == 0) {
      _DirectPlayEnumerateA_8(DPEnumCallback,this);
      return this;
    }
  } while( true );
}

// --------------------------------------------------

// Function: ~TCommunications_Services
// Address: 00432030
void __thiscall TCommunications_Services::~TCommunications_Services(TCommunications_Services *this)
{
  return;
}

// --------------------------------------------------

// Function: GetServiceCount
// Address: 00432040
int __thiscall TCommunications_Services::GetServiceCount(TCommunications_Services *this)
{
  return this->ServiceCount;
}

// --------------------------------------------------

// Function: IncServiceCount
// Address: 00432050
int __thiscall TCommunications_Services::IncServiceCount(TCommunications_Services *this)
{
  int iVar1;
  
  iVar1 = this->ServiceCount + 1;
  this->ServiceCount = iVar1;
  return iVar1;
}

// --------------------------------------------------

// Function: GetServiceName
// Address: 00432060
char * __thiscall
TCommunications_Services::GetServiceName(TCommunications_Services *this,int param_1)
{
  if ((-1 < param_1) && (param_1 <= this->ServiceCount)) {
    return this->Service[param_1].Name;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: SetServiceName
// Address: 00432080
int __thiscall
TCommunications_Services::SetServiceName(TCommunications_Services *this,int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  SPs *pSVar5;
  
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pSVar5 = this->Service + param_1;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pSVar5->Name = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pSVar5 = (SPs *)(pSVar5->Name + 4);
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    pSVar5->Name[0] = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pSVar5 = (SPs *)(pSVar5->Name + 1);
  }
  return 1;
}

// --------------------------------------------------

// Function: GetServiceGUID
// Address: 004320c0
_GUID * __thiscall
TCommunications_Services::GetServiceGUID
          (TCommunications_Services *this,_GUID *__return_storage_ptr__,int param_1)
{
  _GUID *p_Var1;
  ushort uVar2;
  
  p_Var1 = this->Service[param_1].GUID;
  __return_storage_ptr__->Data1 = p_Var1->Data1;
  uVar2 = p_Var1->Data3;
  __return_storage_ptr__->Data2 = p_Var1->Data2;
  __return_storage_ptr__->Data3 = uVar2;
  *(undefined4 *)__return_storage_ptr__->Data4 = *(undefined4 *)p_Var1->Data4;
  *(undefined4 *)(__return_storage_ptr__->Data4 + 4) = *(undefined4 *)(p_Var1->Data4 + 4);
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: EnumServiceGUID
// Address: 004320f0
void __thiscall
TCommunications_Services::EnumServiceGUID(TCommunications_Services *this,int param_1,_GUID *param_2)
{
  if ((-1 < param_1) && (param_1 <= this->ServiceCount)) {
    this->Service[param_1].GUID = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: GetServiceActive
// Address: 00432120
int __thiscall
TCommunications_Services::GetServiceActive(TCommunications_Services *this,int param_1)
{
  if ((-1 < param_1) && (param_1 <= this->ServiceCount)) {
    return this->Service[param_1].Active;
  }
  return 0;
}

// --------------------------------------------------

// Function: SetServiceActive
// Address: 00432150
void __thiscall
TCommunications_Services::SetServiceActive(TCommunications_Services *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 <= this->ServiceCount)) {
    this->Service[param_1].Active = param_2;
  }
  return;
}

// --------------------------------------------------

