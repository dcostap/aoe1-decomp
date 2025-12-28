// Class: TRegistry
// Size:  0x110
//
// Member Layout:
// [0x000] void * ghMachineKey
// [0x004] void * ghUserKey
// [0x008] void * ghMachineKeyRead
// [0x00C] ulong gdwDisp
// [0x010] char[255] Data (sz: 0xFF)
// ----------------------------------------------------------------

// Function: TRegistry
// Address: 0047eb80
/* public: __thiscall TRegistry::TRegistry(char const *) */

TRegistry * __thiscall TRegistry::TRegistry(TRegistry *this,char *param_1)
{
  ulong *puVar1;
  
  puVar1 = &this->gdwDisp;
  this->ghMachineKey = (void *)0x0;
  this->ghUserKey = (void *)0x0;
  this->ghMachineKeyRead = (void *)0x0;
  RegCreateKeyExA(0x80000001,param_1,0,0,0,0xf003f,0,&this->ghUserKey,puVar1);
  RegCreateKeyExA(0x80000002,param_1,0,0,0,0xf003f,0,this,puVar1);
  RegCreateKeyExA(0x80000002,param_1,0,0,0,1,0,&this->ghMachineKeyRead,puVar1);
  return this;
}

// --------------------------------------------------

// Function: ~TRegistry
// Address: 0047ec00
/* public: __thiscall TRegistry::~TRegistry(void) */

void __thiscall TRegistry::~TRegistry(TRegistry *this)
{
  if (this->ghUserKey != (void *)0x0) {
    RegCloseKey(this->ghUserKey);
    this->ghUserKey = (void *)0x0;
  }
  if (this->ghMachineKey != (void *)0x0) {
    RegCloseKey(this->ghMachineKey);
    this->ghMachineKey = (void *)0x0;
  }
  if (this->ghMachineKeyRead != (void *)0x0) {
    RegCloseKey(this->ghMachineKeyRead);
    this->ghMachineKeyRead = (void *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: RegSet
// Address: 0047ec40
/* public: int __thiscall TRegistry::RegSet(int,char const *,unsigned char *,unsigned long) */

int __thiscall
TRegistry::RegSet(TRegistry *this,int param_1,char *param_2,uchar *param_3,ulong param_4)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = RegSetValueExA(this->ghUserKey,param_2,0,4,param_3,param_4);
    return (uint)(iVar1 == 0);
  }
  iVar1 = RegSetValueExA(this->ghMachineKey,param_2,0,4,param_3,param_4);
  return (uint)(iVar1 == 0);
}

// --------------------------------------------------

// Function: RegSetInt
// Address: 0047eca0
/* public: int __thiscall TRegistry::RegSetInt(int,char const *,int) */

int __thiscall TRegistry::RegSetInt(TRegistry *this,int param_1,char *param_2,int param_3)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = RegSetValueExA(this->ghUserKey,param_2,0,4,&param_3,4);
    return (uint)(iVar1 == 0);
  }
  iVar1 = RegSetValueExA(this->ghMachineKey,param_2,0,4,&param_3,4);
  return (uint)(iVar1 == 0);
}

// --------------------------------------------------

// Function: RegSetAscii
// Address: 0047ed00
/* public: int __thiscall TRegistry::RegSetAscii(int,char const *,unsigned char *,unsigned long) */

int __thiscall
TRegistry::RegSetAscii(TRegistry *this,int param_1,char *param_2,uchar *param_3,ulong param_4)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = RegSetValueExA(this->ghUserKey,param_2,0,1,param_3,param_4);
    return (uint)(iVar1 == 0);
  }
  iVar1 = RegSetValueExA(this->ghMachineKey,param_2,0,1,param_3,param_4);
  return (uint)(iVar1 == 0);
}

// --------------------------------------------------

// Function: RegGetAscii
// Address: 0047ed60
/* WARNING: Variable defined which should be unmapped: dwSize */
/* public: char * __thiscall TRegistry::RegGetAscii(int,char const *) */

char * __thiscall TRegistry::RegGetAscii(TRegistry *this,int param_1,char *param_2)
{
  int iVar1;
  void *pvVar2;
  ulong dwSize;
  ulong dwType;
  undefined4 local_4;
  
  local_4 = 1;
  dwType = 0xff;
  if (param_1 == 0) {
    pvVar2 = this->ghMachineKeyRead;
  }
  else {
    pvVar2 = this->ghUserKey;
  }
  iVar1 = RegQueryValueExA(pvVar2,param_2,0,&local_4,this->Data,&dwType);
  return (char *)(~-(uint)(iVar1 != 0) & (uint)this->Data);
}

// --------------------------------------------------

// Function: RegGet
// Address: 0047edd0
/* public: long __thiscall TRegistry::RegGet(int,char const *,unsigned char *,unsigned long *) */

long __thiscall
TRegistry::RegGet(TRegistry *this,int param_1,char *param_2,uchar *param_3,ulong *param_4)
{
  long lVar1;
  
  if (param_1 != 0) {
    lVar1 = RegQueryValueExA(this->ghUserKey,param_2,0,&param_4,param_3,param_4);
    return lVar1;
  }
  lVar1 = RegQueryValueExA(this->ghMachineKeyRead,param_2,0,&param_4,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

// Function: RegGetInt
// Address: 0047ee20
/* WARNING: Variable defined which should be unmapped: Size */
/* public: int __thiscall TRegistry::RegGetInt(int,char const *) */

int __thiscall TRegistry::RegGetInt(TRegistry *this,int param_1,char *param_2)
{
  int iVar1;
  void *pvVar2;
  char **ppcVar3;
  ulong Size;
  ulong dwType;
  undefined4 local_4;
  
  dwType = 4;
  local_4 = 4;
  if (param_1 == 0) {
    pvVar2 = this->ghMachineKeyRead;
  }
  else {
    pvVar2 = this->ghUserKey;
  }
  Size = (ulong)&dwType;
  ppcVar3 = &param_2;
  iVar1 = RegQueryValueExA(pvVar2,param_2,0,&local_4,ppcVar3,Size);
  if (iVar1 == 0) {
    return (int)ppcVar3;
  }
  return -1;
}

// --------------------------------------------------

