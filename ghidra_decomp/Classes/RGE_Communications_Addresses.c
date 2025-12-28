// Class: RGE_Communications_Addresses
// Size:  0x224
//
// Member Layout:
// [0x000] TCommunications_Handler * comm
// [0x004] WSAData wsaData (sz: 0x190)
// [0x194] char[128] hostname (sz: 0x80)
// [0x214] int Status
// [0x218] uint AddressesAvailable
// [0x21C] uint AliasesAvailable
// [0x220] IPAD * pIPAD
// ----------------------------------------------------------------

// Function: RGE_Communications_Addresses
// Address: 004249d0
/* public: __thiscall RGE_Communications_Addresses::RGE_Communications_Addresses(class
   TCommunications_Handler *) */

RGE_Communications_Addresses * __thiscall
RGE_Communications_Addresses::RGE_Communications_Addresses
          (RGE_Communications_Addresses *this,TCommunications_Handler *param_1)
{
  int iVar1;
  char *pcVar2;
  undefined4 unaff_ESI;
  IPAD *pIVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 *puStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_4 = (undefined4 *)0xffffffff;
  pcStack_8 = FUN_0055cc5b;
  *unaff_FS_OFFSET = &uStack_c;
  this->comm = param_1;
  EraseInformation(this);
  iVar1 = _WSAStartup_8(0x101,&this->wsaData);
  puStack_4 = (undefined4 *)operator_new(0x504);
  uStack_c = 0;
  if (puStack_4 == (undefined4 *)0x0) {
    pIVar3 = (IPAD *)0x0;
  }
  else {
    pIVar3 = (IPAD *)(puStack_4 + 1);
    *puStack_4 = 8;
    _eh_vector_constructor_iterator_(pIVar3,0xa0,8,IPAD::IPAD,IPAD::~IPAD);
  }
  uStack_c = 0xffffffff;
  this->pIPAD = pIVar3;
  if (iVar1 == 0) {
    this->Status = 1;
    GetHostName(this);
    pcVar2 = (char *)operator_new(0xff);
    SetIPAddresses(this,pcVar2);
    SetIPAliases(this,pcVar2);
    operator_delete(pcVar2);
  }
  else {
    this->Status = 0;
  }
  *unaff_FS_OFFSET = unaff_ESI;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Communications_Addresses
// Address: 00424b10
/* public: __thiscall RGE_Communications_Addresses::~RGE_Communications_Addresses(void) */

void __thiscall
RGE_Communications_Addresses::~RGE_Communications_Addresses(RGE_Communications_Addresses *this)
{
  IPAD *pIVar1;
  
  EraseInformation(this);
  if (this->Status != 0) {
    _WSACleanup_0();
  }
  pIVar1 = this->pIPAD;
  if (pIVar1 != (IPAD *)0x0) {
    _eh_vector_destructor_iterator_(pIVar1,0xa0,*(int *)(pIVar1[-1].Alias + 0x7c),IPAD::~IPAD);
    operator_delete(pIVar1[-1].Alias + 0x7c);
  }
  return;
}

// --------------------------------------------------

// Function: GetHostName
// Address: 00424b60
/* public: char * __thiscall RGE_Communications_Addresses::GetHostName(void) */

char * __thiscall RGE_Communications_Addresses::GetHostName(RGE_Communications_Addresses *this)
{
                    /* language.dll match for 0x80: "Arial" */
  gethostname(this->hostname,0x80);
  return this->hostname;
}

// --------------------------------------------------

// Function: SetIPAliases
// Address: 00424b80
/* protected: int __thiscall RGE_Communications_Addresses::SetIPAliases(char *) */

int __thiscall
RGE_Communications_Addresses::SetIPAliases(RGE_Communications_Addresses *this,char *param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 *unaff_retaddr;
  
  pcVar6 = this->hostname;
  if (pcVar6 == (char *)0x0) {
    return (int)pcVar6;
  }
  iVar2 = gethostbyname(pcVar6);
  if (iVar2 == 0) {
    return 0;
  }
  *unaff_retaddr = 0;
  puVar5 = *(undefined4 **)(iVar2 + 4);
  this->AliasesAvailable = 0;
  pcVar6 = (char *)*puVar5;
  do {
    if (pcVar6 == (char *)0x0) {
      return this->AliasesAvailable;
    }
    puVar5 = puVar5 + 1;
    uVar3 = 0xffffffff;
    do {
      pcVar7 = pcVar6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar6 = pcVar7 + -uVar3;
    pcVar7 = this->pIPAD[this->AliasesAvailable].Alias;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    this->AliasesAvailable = this->AliasesAvailable + 1;
    pcVar6 = (char *)*puVar5;
  } while( true );
}

// --------------------------------------------------

// Function: GetAddress
// Address: 00424c20
// [HELPER] s__: "}"
/* public: char * __thiscall RGE_Communications_Addresses::GetAddress(unsigned int) */

char * __thiscall
RGE_Communications_Addresses::GetAddress(RGE_Communications_Addresses *this,uint param_1)
{
  IPAD *pIVar1;
  
  pIVar1 = this->pIPAD + param_1;
  if ((pIVar1 == (IPAD *)0x0) || (this->AddressesAvailable < param_1)) {
    pIVar1 = (IPAD *)&s__;
  }
  return pIVar1->DottedIPAddress;
}

// --------------------------------------------------

// Function: GetAlias
// Address: 00424c50
// [HELPER] s__: "}"
/* public: char * __thiscall RGE_Communications_Addresses::GetAlias(unsigned int) */

char * __thiscall
RGE_Communications_Addresses::GetAlias(RGE_Communications_Addresses *this,uint param_1)
{
  char *pcVar1;
  
  if ((this->AliasesAvailable < param_1) ||
     (pcVar1 = this->pIPAD[param_1].Alias, pcVar1 == (char *)0x0)) {
    pcVar1 = &s__;
  }
  return pcVar1;
}

// --------------------------------------------------

// Function: SetIPAddresses
// Address: 00424c80
// [HELPER] s__d__d__d__d_: "%d.%d.%d.%d\n"
/* WARNING: Variable defined which should be unmapped: temp */
/* protected: int __thiscall RGE_Communications_Addresses::SetIPAddresses(char *) */

int __thiscall
RGE_Communications_Addresses::SetIPAddresses(RGE_Communications_Addresses *this,char *param_1)
{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  IPAD *pIVar10;
  char *unaff_retaddr;
  char temp [25];
  
  pcVar7 = this->hostname;
  if (pcVar7 == (char *)0x0) {
    return (int)pcVar7;
  }
  iVar3 = gethostbyname(pcVar7);
  if (iVar3 == 0) {
    return 0;
  }
  *unaff_retaddr = '\0';
  puVar6 = *(undefined4 **)(iVar3 + 0xc);
  this->AddressesAvailable = 0;
  puVar2 = (undefined1 *)*puVar6;
  do {
    if (puVar2 == (undefined1 *)0x0) {
      return this->AddressesAvailable;
    }
    sprintf(temp,s__d__d__d__d_,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    uVar4 = 0xffffffff;
    pcVar7 = temp;
    do {
      pcVar9 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    puVar6 = puVar6 + 1;
    iVar3 = -1;
    pcVar7 = unaff_retaddr;
    do {
      pcVar8 = pcVar7;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    pcVar7 = pcVar9 + -uVar4;
    pcVar9 = pcVar8 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar7 = temp;
    do {
      pcVar9 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar7 = pcVar9 + -uVar4;
    pIVar10 = this->pIPAD + this->AddressesAvailable;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pIVar10->DottedIPAddress = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pIVar10 = (IPAD *)(pIVar10->DottedIPAddress + 4);
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      pIVar10->DottedIPAddress[0] = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pIVar10 = (IPAD *)(pIVar10->DottedIPAddress + 1);
    }
    this->AddressesAvailable = this->AddressesAvailable + 1;
    puVar2 = (undefined1 *)*puVar6;
  } while( true );
}

// --------------------------------------------------

// Function: EraseInformation
// Address: 00424d90
// [HELPER] s_: ""
/* protected: void __thiscall RGE_Communications_Addresses::EraseInformation(void) */

void __thiscall RGE_Communications_Addresses::EraseInformation(RGE_Communications_Addresses *this)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
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
  pcVar5 = this->hostname;
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
  this->AliasesAvailable = 0;
  this->AddressesAvailable = 0;
  return;
}

// --------------------------------------------------

