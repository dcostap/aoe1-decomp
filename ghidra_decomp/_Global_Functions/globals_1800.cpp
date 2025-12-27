// GLOBAL FUNCTIONS PART 1800
// Function: FUN_004471e9
// Address: 004471e9
void __fastcall FUN_004471e9(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055d418;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = 0;
  uStack_4 = 0;
  iVar1 = DString::length((DString *)&stack0x00000004);
  iVar2 = malloc(iVar1 + 1 + param_1[1]);
  iVar1 = iVar5;
  if (0 < param_1[1]) {
    do {
      iVar5 = iVar1 + 1;
      *(undefined1 *)(iVar1 + iVar2) = *(undefined1 *)(iVar1 + *param_1);
      iVar1 = iVar5;
    } while (iVar5 < param_1[1]);
  }
  iVar1 = param_1[1];
  iVar3 = DString::length((DString *)&stack0x00000004);
  if (iVar5 < iVar3 + iVar1) {
    do {
      pcVar4 = DString::operator[]((DString *)&stack0x00000004,iVar5 - iVar1);
      *(char *)(iVar5 + iVar2) = *pcVar4;
      iVar1 = param_1[1];
      iVar5 = iVar5 + 1;
      iVar3 = DString::length((DString *)&stack0x00000004);
    } while (iVar5 < iVar3 + iVar1);
  }
  *(undefined1 *)(iVar5 + iVar2) = 0;
  free(*param_1);
  *param_1 = iVar2;
  iVar1 = DString::length((DString *)&stack0x00000004);
  param_1[1] = param_1[1] + iVar1;
  param_1[2] = -1;
  uStack_4 = 0xffffffff;
  param_1[3] = 0;
  param_1[4] = 0;
  DString::~DString((DString *)&stack0x00000004);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004472cf
// Address: 004472cf
DString * __thiscall FUN_004472cf(DString *param_1,DString *param_2,char param_3)
{
  char cVar1;
  int iVar2;
  DString *pDVar3;
  char *pcVar4;
  undefined4 *unaff_FS_OFFSET;
  DString DStack_20;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d438;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = param_1->lengthValue;
  pcVar4 = param_1->stringValue + iVar2;
  cVar1 = pcVar4[-1];
  for (; (cVar1 == param_3 && (0 < iVar2)); iVar2 = iVar2 + -1) {
    cVar1 = pcVar4[-2];
    pcVar4 = pcVar4 + -1;
  }
  pDVar3 = DString::subString(param_1,&DStack_20,0,iVar2);
  uStack_4 = 0;
  DString::operator=(param_1,pDVar3);
  uStack_4 = 0xffffffff;
  DString::~DString(&DStack_20);
  DString::DString(param_2,param_1);
  *unaff_FS_OFFSET = uStack_c;
  return param_2;
}

// --------------------------------------------------

// Function: FUN_00447362
// Address: 00447362
DString * __thiscall FUN_00447362(DString *param_1,DString *param_2,char param_3)
{
  int iVar1;
  DString *pDVar2;
  undefined4 *unaff_FS_OFFSET;
  DString DStack_20;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d458;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = 0;
  if (*param_1->stringValue == param_3) {
    do {
      if (param_1->lengthValue <= iVar1) break;
      iVar1 = iVar1 + 1;
    } while (param_1->stringValue[iVar1] == param_3);
  }
  pDVar2 = DString::subString(param_1,&DStack_20,iVar1,param_1->lengthValue);
  uStack_4 = 0;
  DString::operator=(param_1,pDVar2);
  uStack_4 = 0xffffffff;
  DString::~DString(&DStack_20);
  DString::DString(param_2,param_1);
  *unaff_FS_OFFSET = uStack_c;
  return param_2;
}

// --------------------------------------------------

// Function: FUN_0044740c
// Address: 0044740c
void __fastcall FUN_0044740c(undefined4 *param_1)
{
  atof(*param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0044741c
// Address: 0044741c
void __fastcall FUN_0044741c(DString *param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = DString::length(param_1);
  if (0 < iVar2) {
    do {
      cVar1 = toupper((int)param_1->stringValue[iVar3]);
      param_1->stringValue[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
      iVar2 = DString::length(param_1);
    } while (iVar3 < iVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00447452
// Address: 00447452
DString * __thiscall FUN_00447452(undefined4 *param_1,DString *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  DString DStack_20;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d48b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  DString::DString(&DStack_20,(char *)*param_1);
  uStack_4 = 1;
  DString::uppercase(&DStack_20);
  DString::DString(param_2,&DStack_20);
  uStack_4 = uStack_4 & 0xffffff00;
  DString::~DString(&DStack_20);
  *unaff_FS_OFFSET = uStack_c;
  return param_2;
}

// --------------------------------------------------

// Function: FUN_004474d8
// Address: 004474d8
void __fastcall FUN_004474d8(DString *param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = DString::length(param_1);
  if (0 < iVar2) {
    do {
      cVar1 = tolower((int)param_1->stringValue[iVar3]);
      param_1->stringValue[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
      iVar2 = DString::length(param_1);
    } while (iVar3 < iVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00447512
// Address: 00447512
DString * __thiscall FUN_00447512(undefined4 *param_1,DString *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  DString DStack_20;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d4bb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  DString::DString(&DStack_20,(char *)*param_1);
  uStack_4 = 1;
  DString::lowercase(&DStack_20);
  DString::DString(param_2,&DStack_20);
  uStack_4 = uStack_4 & 0xffffff00;
  DString::~DString(&DStack_20);
  *unaff_FS_OFFSET = uStack_c;
  return param_2;
}

// --------------------------------------------------

// Function: FUN_00447598
// Address: 00447598
void __thiscall FUN_00447598(int *param_1,char param_2,char param_3)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_1[1]) {
    do {
      if (*(char *)(*param_1 + iVar1) == param_2) {
        *(char *)(*param_1 + iVar1) = param_3;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[1]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004475cc
// Address: 004475cc
// [HELPER] s_: ""
DString * __fastcall FUN_004475cc(DString *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d4d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  DString::DString(param_1,s_);
  uStack_4 = 0;
  DString::DString(param_1 + 1,s_);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044761e
// Address: 0044761e
DString * __fastcall FUN_0044761e(DString *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  pcStack_8 = FUN_0055d508;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iStack_4 = 1;
  DString::DString(param_1,(DString *)&stack0x00000004);
  iStack_4._0_1_ = 2;
  DString::DString(param_1 + 1,(DString *)&stack0x00000018);
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  DString::~DString((DString *)&stack0x00000004);
  iStack_4 = 0xffffffff;
  DString::~DString((DString *)&stack0x00000018);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00447694
// Address: 00447694
void __fastcall FUN_00447694(DString *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055d528;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  DString::~DString(param_1 + 1);
  uStack_4 = 0xffffffff;
  DString::~DString(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004476e7
// Address: 004476e7
DString * __thiscall FUN_004476e7(DString *param_1,DString *param_2)
{
  DString::DString(param_2,param_1);
  return param_2;
}

// --------------------------------------------------

// Function: FUN_0044770d
// Address: 0044770d
void __fastcall FUN_0044770d(DString *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055d548;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  DString::operator=(param_1,(DString *)&stack0x00000004);
  uStack_4 = 0xffffffff;
  DString::~DString((DString *)&stack0x00000004);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00447759
// Address: 00447759
DString * __thiscall FUN_00447759(int param_1,DString *param_2)
{
  DString::DString(param_2,(DString *)(param_1 + 0x14));
  return param_2;
}

// --------------------------------------------------

// Function: FUN_004477cc
// Address: 004477cc
void FUN_004477cc(void)
{
  return;
}

// --------------------------------------------------

// Function: _ShowErrMsg
// Address: 004477d0
void _ShowErrMsg(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004477d1
// Address: 004477d1
int * FUN_004477d1(int *param_1,undefined4 param_2)
{
  int iVar1;
  int *piStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  piStack_18 = (int *)0x0;
  uStack_14 = 0;
  iVar1 = _DSGetWaveResource(0,param_2,&uStack_4,&param_2,&uStack_c);
  if (iVar1 != 0) {
    uStack_14 = 0x14;
    uStack_10 = 0xe2;
    iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&uStack_14,&piStack_18,0);
    if (iVar1 < 0) {
      return (int *)0x0;
    }
    iVar1 = _DSFillSoundBuffer(piStack_18,param_2,uStack_c);
    if (iVar1 == 0) {
      (**(code **)(*piStack_18 + 8))(piStack_18);
      return (int *)0x0;
    }
  }
  return piStack_18;
}

// --------------------------------------------------

// Function: _DSLoadSoundBuffer
// Address: 004477e0
/* WARNING: Variable defined which should be unmapped: pDSB */

ulong _DSLoadSoundBuffer(int *param_1,undefined4 param_2)
{
  int iVar1;
  IDirectSoundBuffer *pDSB;
  _DSBUFFERDESC dsBD;
  undefined4 local_4;
  
  dsBD.dwBufferBytes = 0;
  dsBD.dwReserved = 0;
  dsBD.lpwfxFormat = (tWAVEFORMATEX *)0x0;
  local_4 = 0;
  dsBD.dwSize = 0;
  dsBD.dwFlags = 0;
  iVar1 = _DSGetWaveResource(0,param_2,&local_4,&param_2,&dsBD.dwReserved);
  if (iVar1 != 0) {
    dsBD.dwFlags = 0x14;
    dsBD.dwBufferBytes = 0xe2;
    iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&dsBD.dwFlags,&dsBD,0);
    if (iVar1 < 0) {
      return 0;
    }
    iVar1 = _DSFillSoundBuffer(dsBD.dwSize,param_2,dsBD.dwReserved);
    if (iVar1 == 0) {
      (**(code **)(*(int *)dsBD.dwSize + 8))(dsBD.dwSize);
      return 0;
    }
  }
  return dsBD.dwSize;
}

// --------------------------------------------------

// Function: FUN_0044788a
// Address: 0044788a
undefined4 FUN_0044788a(int *param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 uVar2;
  undefined1 auStack_4 [4];
  
  uVar2 = 0;
  iVar1 = _DSGetWaveResource(0,param_2,0,auStack_4,&param_2);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x50))(param_1);
    if (-1 < iVar1) {
      iVar1 = _DSFillSoundBuffer(param_1,unaff_ESI,param_1);
      if (iVar1 != 0) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

// --------------------------------------------------

// Function: _DSReloadSoundBuffer
// Address: 00447890
/* WARNING: Variable defined which should be unmapped: pbWaveData */

undefined4 _DSReloadSoundBuffer(int *param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 uVar2;
  uchar *pbWaveData;
  undefined1 local_4 [4];
  
  uVar2 = 0;
  iVar1 = _DSGetWaveResource(0,param_2,0,local_4,&param_2);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x50))(param_1);
    if (-1 < iVar1) {
      iVar1 = _DSFillSoundBuffer(param_1,unaff_ESI,param_1);
      if (iVar1 != 0) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_004478e2
// Address: 004478e2
undefined4 FUN_004478e2(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 unaff_retaddr;
  
  iVar1 = FindResourceA(param_1,param_2,&PTR_FUN_00570428);
  if (iVar1 != 0) {
    iVar1 = LoadResource(param_1,iVar1);
    if (iVar1 != 0) {
      iVar1 = LockResource(iVar1);
      if (iVar1 != 0) {
        iVar1 = _DSParseWaveResource(iVar1,unaff_retaddr,param_1,param_2);
        if (iVar1 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: _DSGetWaveResource
// Address: 004478f0
undefined4 _DSGetWaveResource(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 unaff_retaddr;
  
  iVar1 = FindResourceA(param_1,param_2,&PTR_FUN_00570428);
  if (iVar1 != 0) {
    iVar1 = LoadResource(param_1,iVar1);
    if (iVar1 != 0) {
      iVar1 = LockResource(iVar1);
      if (iVar1 != 0) {
        iVar1 = _DSParseWaveResource(iVar1,unaff_retaddr,param_1,param_2);
        if (iVar1 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00447948
// Address: 00447948
undefined4 * FUN_00447948(undefined4 param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 unaff_retaddr;
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  int *piStack_4;
  
  puVar4 = (undefined4 *)0x0;
  iVar1 = _DSGetWaveResource(0,param_2,&piStack_4,auStack_c,auStack_8);
  if (iVar1 != 0) {
    iVar1 = 1;
    if (param_3 < 1) {
      param_3 = 1;
    }
    puVar4 = (undefined4 *)LocalAlloc(0x40,param_3 * 4 + 0x10);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[2] = param_3;
      *puVar4 = unaff_EBP;
      puVar4[1] = unaff_EBX;
      uVar2 = _DSLoadSoundBuffer(piStack_4,param_2);
      puVar4[4] = uVar2;
      if (1 < (int)puVar4[2]) {
        piVar5 = puVar4 + 5;
        do {
          iVar3 = (**(code **)(*piStack_4 + 0x14))(piStack_4,puVar4[4],piVar5);
          if (iVar3 < 0) {
            iVar3 = _DSLoadSoundBuffer(piStack_4,unaff_retaddr);
            *piVar5 = iVar3;
            if (iVar3 == 0) {
              _SndObjDestroy(puVar4);
              return (undefined4 *)0x0;
            }
          }
          iVar1 = iVar1 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar1 < (int)puVar4[2]);
        return puVar4;
      }
    }
  }
  return puVar4;
}

// --------------------------------------------------

// Function: _SndObjCreate
// Address: 00447950
/* WARNING: Variable defined which should be unmapped: pbData */

undefined4 * _SndObjCreate(undefined4 param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 unaff_retaddr;
  uchar *pbData;
  uint cbData;
  tWAVEFORMATEX *pWaveHeader;
  int *local_4;
  
  puVar4 = (undefined4 *)0x0;
  iVar1 = _DSGetWaveResource(0,param_2,&local_4,&cbData,&pWaveHeader);
  if (iVar1 != 0) {
    iVar1 = 1;
    if (param_3 < 1) {
      param_3 = 1;
    }
    puVar4 = (undefined4 *)LocalAlloc(0x40,param_3 * 4 + 0x10);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[2] = param_3;
      *puVar4 = unaff_EBP;
      puVar4[1] = unaff_EBX;
      uVar2 = _DSLoadSoundBuffer(local_4,param_2);
      puVar4[4] = uVar2;
      if (1 < (int)puVar4[2]) {
        piVar5 = puVar4 + 5;
        do {
          iVar3 = (**(code **)(*local_4 + 0x14))(local_4,puVar4[4],piVar5);
          if (iVar3 < 0) {
            iVar3 = _DSLoadSoundBuffer(local_4,unaff_retaddr);
            *piVar5 = iVar3;
            if (iVar3 == 0) {
              _SndObjDestroy(puVar4);
              return (undefined4 *)0x0;
            }
          }
          iVar1 = iVar1 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar1 < (int)puVar4[2]);
        return puVar4;
      }
    }
  }
  return puVar4;
}

// --------------------------------------------------

// Function: FUN_00447a1b
// Address: 00447a1b
void FUN_00447a1b(int param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      piVar2 = (int *)(param_1 + 0x10);
      do {
        piVar1 = (int *)*piVar2;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *piVar2 = 0;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar3 < *(int *)(param_1 + 8));
    }
    LocalFree(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: _SndObjDestroy
// Address: 00447a20
void _SndObjDestroy(int param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      piVar2 = (int *)(param_1 + 0x10);
      do {
        piVar1 = (int *)*piVar2;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *piVar2 = 0;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar3 < *(int *)(param_1 + 8));
    }
    LocalFree(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00447a5f
// Address: 00447a5f
int * FUN_00447a5f(undefined4 *param_1)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  byte unaff_DI;
  
  puVar1 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    return (int *)0x0;
  }
  piVar3 = (int *)param_1[param_1[3] + 4];
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,&param_1);
    if (iVar2 < 0) {
      unaff_DI = 0;
    }
    if ((unaff_DI & 1) == 1) {
      if ((int)puVar1[2] < 2) {
        piVar3 = (int *)0x0;
      }
      else {
        iVar2 = puVar1[3];
        puVar1[3] = iVar2 + 1;
        if ((int)puVar1[2] <= iVar2 + 1) {
          puVar1[3] = 0;
        }
        piVar3 = (int *)puVar1[puVar1[3] + 4];
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,&stack0xfffffffc);
        if ((-1 < iVar2) && ((unaff_DI & 1) == 1)) {
          (**(code **)(*piVar3 + 0x48))(piVar3);
          (**(code **)(*piVar3 + 0x34))(piVar3,0);
        }
      }
    }
    if ((piVar3 != (int *)0x0) && ((unaff_DI & 2) != 0)) {
      iVar2 = (**(code **)(*piVar3 + 0x50))(piVar3);
      if ((-1 < iVar2) && (iVar2 = _DSFillSoundBuffer(piVar3,*puVar1,puVar1[1]), iVar2 != 0)) {
        return piVar3;
      }
      piVar3 = (int *)0x0;
    }
  }
  return piVar3;
}

// --------------------------------------------------

// Function: _SndObjGetFreeBuffer
// Address: 00447a60
int * _SndObjGetFreeBuffer(undefined4 *param_1)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  byte unaff_DI;
  
  puVar1 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    return (int *)0x0;
  }
  piVar3 = (int *)param_1[param_1[3] + 4];
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,&param_1);
    if (iVar2 < 0) {
      unaff_DI = 0;
    }
    if ((unaff_DI & 1) == 1) {
      if ((int)puVar1[2] < 2) {
        piVar3 = (int *)0x0;
      }
      else {
        iVar2 = puVar1[3];
        puVar1[3] = iVar2 + 1;
        if ((int)puVar1[2] <= iVar2 + 1) {
          puVar1[3] = 0;
        }
        piVar3 = (int *)puVar1[puVar1[3] + 4];
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,&stack0xfffffffc);
        if ((-1 < iVar2) && ((unaff_DI & 1) == 1)) {
          (**(code **)(*piVar3 + 0x48))(piVar3);
          (**(code **)(*piVar3 + 0x34))(piVar3,0);
        }
      }
    }
    if ((piVar3 != (int *)0x0) && ((unaff_DI & 2) != 0)) {
      iVar2 = (**(code **)(*piVar3 + 0x50))(piVar3);
      if ((-1 < iVar2) && (iVar2 = _DSFillSoundBuffer(piVar3,*puVar1,puVar1[1]), iVar2 != 0)) {
        return piVar3;
      }
      piVar3 = (int *)0x0;
    }
  }
  return piVar3;
}

// --------------------------------------------------

// Function: FUN_00447b1f
// Address: 00447b1f
uint FUN_00447b1f(uint param_1,uint param_2)
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1 == 0) {
    return param_1;
  }
  if (((param_2 & 1) == 0) || (*(int *)(param_1 + 8) == 1)) {
    piVar1 = (int *)_SndObjGetFreeBuffer(param_1);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,0,0,param_2);
      uVar3 = (uint)(-1 < iVar2);
    }
  }
  return uVar3;
}

// --------------------------------------------------

// Function: _SndObjPlay
// Address: 00447b20
uint _SndObjPlay(uint param_1,uint param_2)
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1 == 0) {
    return param_1;
  }
  if (((param_2 & 1) == 0) || (*(int *)(param_1 + 8) == 1)) {
    piVar1 = (int *)_SndObjGetFreeBuffer(param_1);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,0,0,param_2);
      uVar3 = (uint)(-1 < iVar2);
    }
  }
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_00447b63
// Address: 00447b63
undefined4 FUN_00447b63(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      puVar1 = (undefined4 *)(param_1 + 0x10);
      do {
        (**(code **)(*(int *)*puVar1 + 0x48))((int *)*puVar1);
        (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1,0);
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar2 < *(int *)(param_1 + 8));
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: _SndObjStop
// Address: 00447b70
undefined4 _SndObjStop(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      puVar1 = (undefined4 *)(param_1 + 0x10);
      do {
        (**(code **)(*(int *)*puVar1 + 0x48))((int *)*puVar1);
        (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1,0);
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar2 < *(int *)(param_1 + 8));
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00447bb1
// Address: 00447bb1
undefined4 FUN_00447bb1(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined1 auStack_4 [4];
  
  iVar2 = param_2;
  piVar1 = param_1;
  if (((param_1 != (int *)0x0) && (param_2 != 0)) && (param_3 != 0)) {
    puVar7 = &param_2;
    puVar6 = &param_3;
    puVar5 = &param_1;
    iVar4 = param_3;
    iVar3 = (**(code **)(*param_1 + 0x2c))(param_1,0,param_3,auStack_4,puVar5,puVar6,puVar7,0);
    if (-1 < iVar3) {
      memcpy(iVar4,iVar2,puVar5);
      if (puVar6 != (undefined4 *)0x0) {
        memcpy(puVar7,(int)puVar5 + iVar2,puVar6);
      }
      (**(code **)(*piVar1 + 0x4c))(piVar1,iVar4,puVar5,puVar7,puVar6);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: _DSFillSoundBuffer
// Address: 00447bc0
/* WARNING: Variable defined which should be unmapped: pMem1 */

undefined4 _DSFillSoundBuffer(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  void *pMem1;
  undefined1 local_4 [4];
  
  iVar2 = param_2;
  piVar1 = param_1;
  if (((param_1 != (int *)0x0) && (param_2 != 0)) && (param_3 != 0)) {
    puVar7 = &param_2;
    puVar6 = &param_3;
    puVar5 = &param_1;
    iVar4 = param_3;
    iVar3 = (**(code **)(*param_1 + 0x2c))(param_1,0,param_3,local_4,puVar5,puVar6,puVar7,0);
    if (-1 < iVar3) {
      memcpy(iVar4,iVar2,puVar5);
      if (puVar6 != (undefined4 *)0x0) {
        memcpy(puVar7,(int)puVar5 + iVar2,puVar6);
      }
      (**(code **)(*piVar1 + 0x4c))(piVar1,iVar4,puVar5,puVar7,puVar6);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00447c5b
// Address: 00447c5b
undefined4 FUN_00447c5b(int *param_1,uint *param_2,int *param_3,uint *param_4)
{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  
  if (param_2 != (uint *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  piVar5 = param_1 + 3;
  if (((*param_1 != 0x46464952) || (param_1[2] != 0x45564157)) ||
     (piVar1 = (int *)(param_1[1] + -4 + (int)piVar5), piVar1 <= piVar5)) {
    return 0;
  }
  do {
    uVar2 = piVar5[1];
    piVar4 = piVar5 + 2;
    if (*piVar5 == 0x20746d66) {
      if ((param_2 != (uint *)0x0) && (*param_2 == 0)) {
        if (uVar2 < 0xe) {
          return 0;
        }
        *param_2 = (uint)piVar4;
        if ((param_3 == (int *)0x0) || (*param_3 != 0)) {
          if (param_4 == (uint *)0x0) {
            return 1;
          }
          uVar3 = *param_4;
          goto joined_r0x00447d2c;
        }
      }
    }
    else if ((*piVar5 == 0x61746164) &&
            (((param_3 != (int *)0x0 && (*param_3 == 0)) ||
             ((param_4 != (uint *)0x0 && (*param_4 == 0)))))) {
      if (param_3 != (int *)0x0) {
        *param_3 = (int)piVar4;
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = uVar2;
      }
      if (param_2 == (uint *)0x0) {
        return 1;
      }
      uVar3 = *param_2;
joined_r0x00447d2c:
      if (uVar3 != 0) {
        return 1;
      }
    }
    piVar5 = (int *)((int)piVar4 + (uVar2 + 1 & 0xfffffffe));
    if (piVar1 <= piVar5) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: _DSParseWaveResource
// Address: 00447c60
undefined4 _DSParseWaveResource(int *param_1,uint *param_2,int *param_3,uint *param_4)
{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  
  if (param_2 != (uint *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  piVar5 = param_1 + 3;
  if (((*param_1 != 0x46464952) || (param_1[2] != 0x45564157)) ||
     (piVar1 = (int *)(param_1[1] + -4 + (int)piVar5), piVar1 <= piVar5)) {
                    /* Symbol Ref: {@symbol exit} */
    return 0;
  }
  do {
    uVar2 = piVar5[1];
    piVar4 = piVar5 + 2;
    if (*piVar5 == 0x20746d66) {
      if ((param_2 != (uint *)0x0) && (*param_2 == 0)) {
        if (uVar2 < 0xe) {
          return 0;
        }
        *param_2 = (uint)piVar4;
        if ((param_3 == (int *)0x0) || (*param_3 != 0)) {
          if (param_4 == (uint *)0x0) {
            return 1;
          }
          uVar3 = *param_4;
          goto joined_r0x00447d2c;
        }
      }
    }
    else if ((*piVar5 == 0x61746164) &&
            (((param_3 != (int *)0x0 && (*param_3 == 0)) ||
             ((param_4 != (uint *)0x0 && (*param_4 == 0)))))) {
      if (param_3 != (int *)0x0) {
        *param_3 = (int)piVar4;
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = uVar2;
      }
      if (param_2 == (uint *)0x0) {
        return 1;
      }
      uVar3 = *param_2;
joined_r0x00447d2c:
      if (uVar3 != 0) {
        return 1;
      }
    }
    piVar5 = (int *)((int)piVar4 + (uVar2 + 1 & 0xfffffffe));
    if (piVar1 <= piVar5) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: _WaveOpenFile
// Address: 00447d50
/* WARNING: Variable defined which should be unmapped: pcmWaveFormat */

int _WaveOpenFile(int *param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  uint uVar2;
  short unaff_SI;
  int iVar3;
  int *unaff_retaddr;
  pcmwaveformat_tag pcmWaveFormat;
  _MMCKINFO ckIn;
  int *piStack_4;
  
  *param_3 = 0;
  iVar1 = mmioOpenA(param_1,0,0x10000);
  if (iVar1 == 0) {
    iVar3 = 0xe100;
  }
  else {
    iVar3 = mmioDescend(iVar1,param_1,0,0);
    if (iVar3 == 0) {
      if ((*param_1 == 0x46464952) && (param_1[2] == 0x45564157)) {
        pcmWaveFormat.wf.nAvgBytesPerSec = 0x20746d66;
        iVar3 = mmioDescend(iVar1,&pcmWaveFormat.wf.nAvgBytesPerSec,param_1,0x10);
        if (iVar3 != 0) goto LAB_00447eb8;
        if (0xf < (uint)pcmWaveFormat._12_4_) {
          iVar3 = mmioRead(iVar1,&stack0xffffffd0,0x10);
          if (iVar3 != 0x10) {
            iVar3 = 0xe102;
            goto LAB_00447eb8;
          }
          if (unaff_SI == 1) {
            ckIn.dwFlags = 0;
          }
          else {
            iVar3 = mmioRead(iVar1,&ckIn.dwFlags,2);
            if (iVar3 != 2) {
              iVar3 = 0xe102;
              goto LAB_00447eb8;
            }
          }
          iVar3 = GlobalAlloc(0,(ckIn.dwFlags & 0xffff) + 0x12);
          *unaff_retaddr = iVar3;
          if (iVar3 == 0) {
            iVar3 = 0xe000;
            goto LAB_00447eb8;
          }
          memcpy(iVar3,&stack0xffffffd0,0x10);
          *(short *)(*unaff_retaddr + 0x10) = (short)ckIn.dwFlags;
          if (((short)ckIn.dwFlags == 0) ||
             (uVar2 = mmioRead(iVar1,*unaff_retaddr + 0x12,ckIn.dwFlags & 0xffff),
             uVar2 == (ckIn.dwFlags & 0xffff))) {
            iVar3 = mmioAscend(iVar1,&pcmWaveFormat.wf.nAvgBytesPerSec,0);
            if (iVar3 == 0) {
              *piStack_4 = iVar1;
              return 0;
            }
            goto LAB_00447eb8;
          }
        }
      }
      iVar3 = 0xe101;
    }
  }
LAB_00447eb8:
                    /* Symbol Ref: {@symbol ERROR_READING_WAVE} */
  if (*unaff_retaddr != 0) {
    GlobalFree(*unaff_retaddr);
    *unaff_retaddr = 0;
  }
  if (iVar1 != 0) {
    mmioClose(iVar1,0);
    iVar1 = 0;
  }
                    /* Symbol Ref: {@symbol TEMPCLEANUP} */
  *piStack_4 = iVar1;
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_00447eee
// Address: 00447eee
undefined4 FUN_00447eee(undefined4 *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  
  iVar1 = mmioSeek(*param_1,*(int *)(param_3 + 0xc) + 4,0);
  if (iVar1 == -1) {
    return 1;
  }
  *unaff_ESI = 0x61746164;
  uVar2 = mmioDescend(*param_1,unaff_ESI,param_3,0x10);
  return uVar2;
}

// --------------------------------------------------

// Function: _WaveStartDataRead
// Address: 00447ef0
undefined4 _WaveStartDataRead(undefined4 *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  
  iVar1 = mmioSeek(*param_1,*(int *)(param_3 + 0xc) + 4,0);
  if (iVar1 == -1) {
    return 1;
  }
  *unaff_ESI = 0x61746164;
  uVar2 = mmioDescend(*param_1,unaff_ESI,param_3,0x10);
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_00447f33
// Address: 00447f33
uint FUN_00447f33(int param_1,uint *param_2)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int unaff_retaddr;
  undefined1 auStack_48 [16];
  int iStack_38;
  int iStack_34;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = mmioGetInfo(param_1,auStack_48,0);
  uVar2 = (uint)(iVar1 != 0);
  if (uVar2 == 0) {
    uVar2 = *(uint *)(param_1 + 4);
    uVar3 = uStack_4;
    if (uVar2 < uStack_4) {
      uVar3 = uVar2;
    }
    uVar4 = 0;
    *(uint *)(param_1 + 4) = uVar2 - uVar3;
    if (uVar3 != 0) {
      do {
        if (iStack_38 == iStack_34) {
          uVar2 = mmioAdvance(uStack_8,&stack0xffffffac,0);
          if (uVar2 != 0) goto LAB_00447ffb;
          if (iStack_38 == iStack_34) {
            *param_2 = 0;
            return 0xe103;
          }
        }
        uVar2 = iStack_34 - iStack_38;
        if (uVar3 - uVar4 < uVar2) {
          uVar2 = uVar3 - uVar4;
        }
        memcpy(uVar4 + unaff_retaddr,iStack_38,uVar2);
        uVar4 = uVar4 + uVar2;
        iStack_38 = iStack_38 + uVar2;
      } while (uVar4 < uVar3);
    }
    uVar2 = mmioSetInfo(uStack_8,&stack0xffffffac,0);
    if (uVar2 == 0) {
      *param_2 = uVar3;
      return 0;
    }
  }
LAB_00447ffb:
  *param_2 = 0;
  return uVar2;
}

// --------------------------------------------------

// Function: _WaveReadFile
// Address: 00447f40
/* WARNING: Variable defined which should be unmapped: mmioinfoIn */

uint _WaveReadFile(int param_1,uint *param_2)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int unaff_retaddr;
  _MMIOINFO mmioinfoIn;
  uint uStack_4;
  
  iVar1 = mmioGetInfo(param_1,&mmioinfoIn.fccIOProc,0);
  uVar2 = (uint)(iVar1 != 0);
  if (uVar2 == 0) {
    uVar2 = *(uint *)(param_1 + 4);
    if (uVar2 < uStack_4) {
      uStack_4 = uVar2;
    }
    uVar3 = 0;
    *(uint *)(param_1 + 4) = uVar2 - uStack_4;
    if (uStack_4 != 0) {
      do {
        if ((char *)mmioinfoIn.cchBuffer == mmioinfoIn.pchBuffer) {
          uVar2 = mmioAdvance(mmioinfoIn.hmmio,&stack0xffffffac,0);
          if (uVar2 != 0) goto LAB_00447ffb;
          if ((char *)mmioinfoIn.cchBuffer == mmioinfoIn.pchBuffer) {
            *param_2 = 0;
            return 0xe103;
          }
        }
        uVar2 = (int)mmioinfoIn.pchBuffer - mmioinfoIn.cchBuffer;
        if (uStack_4 - uVar3 < uVar2) {
          uVar2 = uStack_4 - uVar3;
        }
        memcpy(uVar3 + unaff_retaddr,mmioinfoIn.cchBuffer,uVar2);
        uVar3 = uVar3 + uVar2;
        mmioinfoIn.cchBuffer = mmioinfoIn.cchBuffer + uVar2;
      } while (uVar3 < uStack_4);
    }
    uVar2 = mmioSetInfo(mmioinfoIn.hmmio,&stack0xffffffac,0);
    if (uVar2 == 0) {
      *param_2 = uStack_4;
      return 0;
    }
  }
LAB_00447ffb:
                    /* Symbol Ref: {@symbol ERROR_CANNOT_READ} */
  *param_2 = 0;
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_00448032
// Address: 00448032
undefined4 FUN_00448032(int *param_1,int *param_2)
{
  if (*param_2 != 0) {
    GlobalFree(*param_2);
    *param_2 = 0;
  }
  if (*param_1 != 0) {
    mmioClose(*param_1,0);
    *param_1 = 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: _WaveCloseReadFile
// Address: 00448040
undefined4 _WaveCloseReadFile(int *param_1,int *param_2)
{
  if (*param_2 != 0) {
    GlobalFree(*param_2);
    *param_2 = 0;
  }
  if (*param_1 != 0) {
    mmioClose(*param_1,0);
    *param_1 = 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00448075
// Address: 00448075
// Error: 
Low-level Error: Symbol $$undef0000009b extends beyond the end of the address space

// --------------------------------------------------

// Function: _WaveCreateFile
// Address: 00448080
// Error: 
Low-level Error: Symbol $$undef00000092 extends beyond the end of the address space

// --------------------------------------------------

// Function: FUN_0044819f
// Address: 0044819f
void FUN_0044819f(undefined4 *param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 unaff_retaddr;
  
  *param_2 = 0x61746164;
  param_2[1] = 0;
  iVar1 = mmioCreateChunk(*param_1,param_2,0);
  if (iVar1 == 0) {
    mmioGetInfo(*param_1,unaff_retaddr,0);
  }
  return;
}

// --------------------------------------------------

// Function: _WaveStartDataWrite
// Address: 004481a0
void _WaveStartDataWrite(undefined4 *param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 unaff_retaddr;
  
  *param_2 = 0x61746164;
  param_2[1] = 0;
  iVar1 = mmioCreateChunk(*param_1,param_2,0);
  if (iVar1 == 0) {
    mmioGetInfo(*param_1,unaff_retaddr,0);
  }
                    /* Symbol Ref: {@symbol ERROR_CANNOT_WRITE} */
  return;
}

// --------------------------------------------------

// Function: FUN_004481d7
// Address: 004481d7
void FUN_004481d7(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,int *param_5,
                 uint *param_6)
{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  *param_5 = 0;
  if (param_2 != 0) {
    do {
      if (param_6[7] == param_6[9]) {
        *param_6 = *param_6 | 0x10000000;
        iVar1 = mmioAdvance(param_1,param_6,1);
        if (iVar1 != 0) {
          return;
        }
      }
      *(undefined1 *)param_6[7] = *(undefined1 *)(uVar2 + param_3);
      param_6[7] = param_6[7] + 1;
      uVar2 = uVar2 + 1;
      *param_5 = *param_5 + 1;
    } while (uVar2 < param_2);
  }
  return;
}

// --------------------------------------------------

// Function: _WaveWriteFile
// Address: 004481e0
void _WaveWriteFile(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,int *param_5,
                   uint *param_6)
{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  *param_5 = 0;
  if (param_2 != 0) {
    do {
      if (param_6[7] == param_6[9]) {
        *param_6 = *param_6 | 0x10000000;
        iVar1 = mmioAdvance(param_1,param_6,1);
        if (iVar1 != 0) {
          return;
        }
      }
      *(undefined1 *)param_6[7] = *(undefined1 *)(uVar2 + param_3);
      param_6[7] = param_6[7] + 1;
      uVar2 = uVar2 + 1;
      *param_5 = *param_5 + 1;
    } while (uVar2 < param_2);
  }
                    /* Symbol Ref: {@symbol ERROR_CANNOT_WRITE} */
  return;
}

// --------------------------------------------------

// Function: FUN_00448246
// Address: 00448246
int FUN_00448246(int *param_1,undefined4 param_2,undefined4 param_3,uint *param_4)
{
  int iVar1;
  undefined4 *unaff_EBX;
  undefined4 unaff_retaddr;
  
  if (*param_1 == 0) {
    return 0;
  }
  *param_4 = *param_4 | 0x10000000;
  iVar1 = mmioSetInfo(*param_1,param_4,0);
  if (iVar1 == 0) {
    iVar1 = mmioAscend(*param_1,unaff_EBX,0);
    if (iVar1 == 0) {
      iVar1 = mmioAscend(*param_1,unaff_retaddr,0);
      if (iVar1 == 0) {
        mmioSeek(*param_1,0,0);
        iVar1 = mmioDescend(*param_1,unaff_retaddr,0,0);
        if (iVar1 == 0) {
          *unaff_EBX = 0x74636166;
          iVar1 = mmioDescend(*param_1,unaff_EBX,unaff_retaddr,0x10);
          if (iVar1 != 0) {
            return 1;
          }
          mmioWrite(*param_1,&stack0xfffffff8,4);
          mmioAscend(*param_1,unaff_EBX,0);
          iVar1 = mmioAscend(*param_1,unaff_retaddr,0);
        }
      }
    }
  }
  if (*param_1 != 0) {
    mmioClose(*param_1,0);
    *param_1 = 0;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: _WaveCloseWriteFile
// Address: 00448250
int _WaveCloseWriteFile(int *param_1,undefined4 param_2,undefined4 param_3,uint *param_4)
{
  int iVar1;
  undefined4 *unaff_EBX;
  undefined4 unaff_retaddr;
  
  if (*param_1 == 0) {
    return 0;
  }
  *param_4 = *param_4 | 0x10000000;
  iVar1 = mmioSetInfo(*param_1,param_4,0);
  if (iVar1 == 0) {
    iVar1 = mmioAscend(*param_1,unaff_EBX,0);
    if (iVar1 == 0) {
      iVar1 = mmioAscend(*param_1,unaff_retaddr,0);
      if (iVar1 == 0) {
        mmioSeek(*param_1,0,0);
        iVar1 = mmioDescend(*param_1,unaff_retaddr,0,0);
        if (iVar1 == 0) {
          *unaff_EBX = 0x74636166;
          iVar1 = mmioDescend(*param_1,unaff_EBX,unaff_retaddr,0x10);
          if (iVar1 != 0) {
            return 1;
          }
          mmioWrite(*param_1,&stack0xfffffff8,4);
          mmioAscend(*param_1,unaff_EBX,0);
          iVar1 = mmioAscend(*param_1,unaff_retaddr,0);
        }
      }
    }
  }
                    /* Symbol Ref: {@symbol ERROR_CANNOT_WRITE} */
  if (*param_1 != 0) {
    mmioClose(*param_1,0);
    *param_1 = 0;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00448334
// Address: 00448334
undefined4 FUN_00448334(undefined4 *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int *unaff_EBX;
  undefined4 uVar2;
  
  iVar1 = mmioSeek(*param_1,*(int *)(param_3 + 0xc) + 4,0);
  if (iVar1 == -1) {
    uVar2 = 0xe102;
  }
  else {
    uVar2 = 0;
    iVar1 = mmioDescend(*param_1,unaff_EBX,param_3,0);
    while ((iVar1 == 0 &&
           ((uint)(unaff_EBX[3] + unaff_EBX[1]) <=
            (uint)(*(int *)(param_3 + 4) + *(int *)(param_3 + 0xc))))) {
      iVar1 = *unaff_EBX;
      if ((iVar1 != 0x20444150) && ((iVar1 == 0x50534944 || (iVar1 == 0x74736c70)))) {
        riffCopyChunk(*param_1,*param_1,unaff_EBX);
      }
      mmioAscend(*param_1,unaff_EBX,0);
      iVar1 = mmioDescend(*param_1,unaff_EBX,param_3,0);
    }
  }
  mmioSeek(*param_1,*(int *)(param_3 + 0xc) + 4,0);
  return uVar2;
}

// --------------------------------------------------

// Function: _WaveCopyUselessChunks
// Address: 00448340
undefined4 _WaveCopyUselessChunks(undefined4 *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int *unaff_EBX;
  undefined4 uVar2;
  
  iVar1 = mmioSeek(*param_1,*(int *)(param_3 + 0xc) + 4,0);
  if (iVar1 == -1) {
    uVar2 = 0xe102;
  }
  else {
    uVar2 = 0;
    iVar1 = mmioDescend(*param_1,unaff_EBX,param_3,0);
    while ((iVar1 == 0 &&
           ((uint)(unaff_EBX[3] + unaff_EBX[1]) <=
            (uint)(*(int *)(param_3 + 4) + *(int *)(param_3 + 0xc))))) {
      iVar1 = *unaff_EBX;
      if ((iVar1 != 0x20444150) && ((iVar1 == 0x50534944 || (iVar1 == 0x74736c70)))) {
        riffCopyChunk(*param_1,*param_1,unaff_EBX);
      }
      mmioAscend(*param_1,unaff_EBX,0);
      iVar1 = mmioDescend(*param_1,unaff_EBX,param_3,0);
    }
  }
                    /* Symbol Ref: {@symbol ERROR_IN_PROC} */
  mmioSeek(*param_1,*(int *)(param_3 + 0xc) + 4,0);
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_004483fd
// Address: 004483fd
undefined4 FUN_004483fd(undefined4 param_1,undefined4 param_2,int param_3)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_14;
  undefined4 uStack_4;
  
  uStack_28 = *(undefined4 *)(param_3 + 4);
  uStack_2c = 0x42;
  uVar1 = GlobalAlloc();
  iVar2 = GlobalLock(uVar1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = mmioCreateChunk(uStack_4,&stack0xffffffe0,0);
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_3 + 4);
    iVar4 = mmioRead(uStack_14,iVar2,iVar3);
    if (iVar4 == iVar3) {
      iVar3 = mmioWrite(uStack_4,iVar2,iVar3);
      if (iVar3 == *(int *)(param_3 + 4)) {
        iVar3 = mmioAscend(uStack_4,&uStack_2c,0);
        if (iVar3 == 0) {
          uVar1 = GlobalHandle(iVar2);
          GlobalUnlock(uVar1);
          uVar1 = GlobalHandle(iVar2);
          GlobalFree(uVar1);
          return 1;
        }
      }
    }
  }
  uVar1 = GlobalHandle(iVar2);
  GlobalUnlock(uVar1);
  uVar1 = GlobalHandle(iVar2);
  GlobalFree(uVar1);
  return 0;
}

// --------------------------------------------------

// Function: riffCopyChunk
// Address: 00448400
/* WARNING: Variable defined which should be unmapped: ck */
/* riffCopyChunk */

undefined4 __cdecl riffCopyChunk(undefined4 param_1,undefined4 param_2,int param_3)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  _MMCKINFO ck;
  undefined4 uStack_4;
  
  uStack_28 = *(undefined4 *)(param_3 + 4);
  uStack_2c = 0x42;
  uVar1 = GlobalAlloc();
  iVar2 = GlobalLock(uVar1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = mmioCreateChunk(uStack_4,&stack0xffffffe0,0);
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_3 + 4);
    iVar4 = mmioRead(ck.cksize,iVar2,iVar3);
    if (iVar4 == iVar3) {
      iVar3 = mmioWrite(uStack_4,iVar2,iVar3);
      if (iVar3 == *(int *)(param_3 + 4)) {
        iVar3 = mmioAscend(uStack_4,&uStack_2c,0);
        if (iVar3 == 0) {
          uVar1 = GlobalHandle(iVar2);
          GlobalUnlock(uVar1);
          uVar1 = GlobalHandle(iVar2);
          GlobalFree(uVar1);
          return 1;
        }
      }
    }
  }
                    /* Symbol Ref: {@symbol rscc_Error} */
  uVar1 = GlobalHandle(iVar2);
  GlobalUnlock(uVar1);
  uVar1 = GlobalHandle(iVar2);
  GlobalFree(uVar1);
  return 0;
}

// --------------------------------------------------

// Function: _WaveLoadFile
// Address: 004484d0
/* WARNING: Variable defined which should be unmapped: ckIn */

int _WaveLoadFile(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int *param_4,
                 int *param_5)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  _MMCKINFO ckIn;
  _MMCKINFO ckInRiff;
  
  piVar3 = param_5;
  piVar2 = param_4;
  *param_5 = 0;
  *param_4 = 0;
  *param_2 = 0;
  iVar4 = _WaveOpenFile(param_1,&param_5,param_4,&ckInRiff.cksize);
  if (iVar4 == 0) {
    iVar4 = _WaveStartDataRead(&param_5,&ckIn.cksize,&ckInRiff.cksize);
    if (iVar4 == 0) {
      iVar4 = GlobalAlloc(0,ckIn.fccType);
      *piVar3 = iVar4;
      if (iVar4 == 0) {
        iVar4 = 0xe000;
      }
      else {
        iVar4 = _WaveReadFile(param_5,ckIn.fccType,iVar4,&ckIn.cksize,&param_4);
        if (iVar4 == 0) {
          *param_2 = param_4;
          goto LAB_0044859a;
        }
      }
    }
  }
                    /* Symbol Ref: {@symbol ERROR_LOADING} */
  if (*piVar3 != 0) {
    GlobalFree(*piVar3);
    *piVar3 = 0;
  }
  iVar1 = *piVar2;
  if (iVar1 != 0) {
    GlobalFree(iVar1);
    *piVar2 = 0;
  }
LAB_0044859a:
                    /* Symbol Ref: {@symbol DONE_LOADING} */
  if (param_5 != (int *)0x0) {
    mmioClose(param_5,0);
  }
  return iVar4;
}

// --------------------------------------------------

// Function: FUN_004485b5
// Address: 004485b5
void FUN_004485b5(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)
{
  int iVar1;
  undefined4 uStack_78;
  undefined1 auStack_74 [4];
  undefined1 auStack_70 [20];
  undefined1 auStack_5c [20];
  undefined1 auStack_48 [72];
  
  iVar1 = _WaveCreateFile(param_1,&uStack_78,param_4,auStack_70,auStack_5c);
  if (iVar1 == 0) {
    iVar1 = _WaveStartDataWrite(&uStack_78,auStack_70,auStack_48);
    if (iVar1 == 0) {
      iVar1 = _WaveWriteFile(uStack_78,param_2,param_5,auStack_70,auStack_74,auStack_48);
      if (iVar1 == 0) {
        _WaveCloseWriteFile(&uStack_78,auStack_70,auStack_5c,auStack_48,param_3);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: _WaveSaveFile
// Address: 004485c0
/* WARNING: Variable defined which should be unmapped: hmmioOut */

void _WaveSaveFile(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)
{
  int iVar1;
  void *hmmioOut;
  uint cbActualWrite;
  _MMCKINFO ckOut;
  _MMCKINFO ckOutRIFF;
  _MMIOINFO mmioinfoOut;
  
  iVar1 = _WaveCreateFile(param_1,&cbActualWrite,param_4,&ckOut.cksize,&ckOutRIFF.cksize);
  if (iVar1 == 0) {
    iVar1 = _WaveStartDataWrite(&cbActualWrite,&ckOut.cksize,&mmioinfoOut.fccIOProc);
    if (iVar1 == 0) {
      iVar1 = _WaveWriteFile(cbActualWrite,param_2,param_5,&ckOut.cksize,&ckOut,
                             &mmioinfoOut.fccIOProc);
      if (iVar1 == 0) {
        _WaveCloseWriteFile(&cbActualWrite,&ckOut.cksize,&ckOutRIFF.cksize,&mmioinfoOut.fccIOProc,
                            param_3);
      }
    }
  }
                    /* Symbol Ref: {@symbol ERROR_SAVING} */
  return;
}

// --------------------------------------------------

// Function: FUN_0044865e
// Address: 0044865e
void FUN_0044865e(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  _uLastPercent = 100;
  _lpDSBStreamBuffer = 0;
  _bFileOpen = 0;
  _bPlaying = 0;
  _bTimerInstalled = 0;
  _uTimerID = 0;
  _main_wnd = param_1;
  _lpBuffer._0_4_ = param_3;
  _lpDS = param_2;
  _ds_ready = 1;
  return;
}

// --------------------------------------------------

// Function: ds_stream_init
// Address: 00448660
/* ds_stream_init */

void __cdecl ds_stream_init(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  _uLastPercent = 100;
  _lpDSBStreamBuffer = 0;
  _bFileOpen = 0;
  _bPlaying = 0;
  _bTimerInstalled = 0;
  _uTimerID = 0;
  _main_wnd = param_1;
  _lpBuffer._0_4_ = param_3;
  _lpDS = param_2;
  _ds_ready = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004486ad
// Address: 004486ad
void FUN_004486ad(void)
{
  if (_ds_ready != 0) {
    if (((_bFileOpen != 0) || (_bPlaying != 0)) || (_bTimerInstalled != 0)) {
      ds_stream_stop();
    }
    _ds_ready = 0;
  }
  return;
}

// --------------------------------------------------

// Function: ds_stream_exit
// Address: 004486b0
/* ds_stream_exit */

void __cdecl ds_stream_exit(void)
{
  if (_ds_ready != 0) {
    if (((_bFileOpen != 0) || (_bPlaying != 0)) || (_bTimerInstalled != 0)) {
      ds_stream_stop();
    }
    _ds_ready = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004486e4
// Address: 004486e4
undefined4 FUN_004486e4(undefined4 param_1)
{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puStack_50;
  undefined4 uStack_4c;
  int *piStack_48;
  undefined4 *puStack_44;
  Alignment *pAStack_40;
  undefined4 *puStack_3c;
  undefined1 auStack_28 [20];
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  short *psStack_4;
  
  if (((_bFileOpen != 0) || (_bPlaying != 0)) || (_bTimerInstalled != 0)) {
    puStack_3c = (undefined4 *)0x448717;
    ds_stream_stop();
  }
  puStack_3c = (undefined4 *)0x88847c;
  pAStack_40 = (Alignment *)&_wiWave;
  puStack_44 = &DAT_00888464;
  piStack_48 = (int *)param_1;
  _stream_paused = 0;
  uStack_4c = 0x448736;
  iVar1 = _WaveOpenFile();
  if (iVar1 != 0) {
    return 0;
  }
  if (*_wiWave != 1) {
    puStack_3c = &_wiWave;
    pAStack_40 = (Alignment *)&DAT_00888464;
    puStack_44 = (undefined4 *)0x448766;
    _WaveCloseReadFile();
    return 0;
  }
  puStack_3c = (undefined4 *)0x88847c;
  pAStack_40 = &DAT_00888468;
  puStack_44 = &DAT_00888464;
  piStack_48 = (int *)0x448787;
  iVar1 = _WaveStartDataRead();
  if (iVar1 == 0) {
    puStack_3c = (undefined4 *)0x14;
    pAStack_40 = (Alignment *)0x0;
    DAT_00888498 = (uint)(*(int *)(_wiWave + 4) * 0x78) / 600;
    puStack_44 = &uStack_14;
    DAT_00888494 = DAT_00888498 * 6;
    piStack_48 = (int *)0x4487ee;
    memset();
    psStack_4 = _wiWave;
    puStack_44 = &uStack_14;
    puStack_3c = (undefined4 *)0x0;
    uStack_14 = 0x14;
    uStack_10 = 0xe0;
    iStack_c = DAT_00888494;
    pAStack_40 = (Alignment *)&_lpDSBStreamBuffer;
    piStack_48 = _lpDS;
    uStack_4c = 0x44882b;
    iVar1 = (**(code **)(*_lpDS + 0xc))();
    if (iVar1 != 0) {
      return 0;
    }
    puStack_50 = auStack_28;
    uStack_4c = 0;
    puVar3 = &stack0xffffffd4;
    puVar2 = &stack0xffffffc8;
    DAT_00888490 = _lpDSBStreamBuffer;
    DAT_008884b0 = 0;
    DAT_008884b4 = 0;
    iVar1 = (**(code **)(*_lpDSBStreamBuffer + 0x2c))
                      (_lpDSBStreamBuffer,0,DAT_00888494,&stack0xffffffcc,puVar2,puVar3);
    if (iVar1 == 0) {
      puVar4 = puVar3;
      if ((puVar2 != (undefined1 *)0x0) &&
         (_WaveReadFile(DAT_00888464,puVar2,puVar3,&DAT_00888468,&puStack_50), puVar4 = puVar3,
         puStack_50 < puVar2)) {
        if (DAT_008884ac == 0) {
          DAT_008884b4 = (uint)puStack_50 / DAT_00888498;
          DAT_008884b0 = 1;
          memset(puStack_50 + (int)puVar3,(_wiWave[7] != 8) - 1U & 0x80,
                 (int)puVar2 - (int)puStack_50);
          puVar4 = puVar3;
        }
        else {
          do {
            puVar2 = puVar2 + -(int)puStack_50;
            puVar3 = puVar3 + (int)puStack_50;
            _WaveStartDataRead(&DAT_00888464,&DAT_00888468,0x88847c);
            _WaveReadFile(DAT_00888464,puVar2,puVar3,&DAT_00888468,&puStack_50);
          } while (puStack_50 < puVar2);
        }
      }
      (**(code **)(*_lpDSBStreamBuffer + 0x4c))(_lpDSBStreamBuffer,puVar4,puVar2,uStack_4c,0);
      DAT_008884ac = (uint)puStack_3c & 0xff;
      DAT_008884a4 = 0;
      DAT_008884a0 = 0;
      DAT_0088849c = 0;
      DAT_008884a8 = 0;
      _bFileOpen = 1;
      SendMessageA(_main_wnd,0x502,0,0);
      (**(code **)(*_lpDSBStreamBuffer + 0x34))(_lpDSBStreamBuffer,0);
      (**(code **)(*_lpDSBStreamBuffer + 0x3c))(_lpDSBStreamBuffer,pAStack_40);
      (**(code **)(*_lpDSBStreamBuffer + 0x30))(_lpDSBStreamBuffer,0,0,1);
      iVar1 = timeBeginPeriod(0x32);
      if (iVar1 == 0) {
        _uTimerID = timeSetEvent(0x32,10,ds_stream_time_func,0,1);
        if (_uTimerID != 0) {
          _bTimerInstalled = 1;
        }
        _bPlaying = 1;
        return 1;
      }
      (**(code **)(*_lpDSBStreamBuffer + 0x48))(_lpDSBStreamBuffer);
      _bTimerInstalled = 0;
      _bPlaying = 0;
      return 0;
    }
    return 0;
  }
  puStack_3c = &_wiWave;
  pAStack_40 = (Alignment *)&DAT_00888464;
  puStack_44 = (undefined4 *)0x44879d;
  _WaveCloseReadFile();
  return 0;
}

// --------------------------------------------------

// Function: ds_stream_file
// Address: 004486f0
/* WARNING: Variable defined which should be unmapped: dwLen1 */
/* ds_stream_file */

undefined4 __cdecl ds_stream_file(undefined4 param_1)
{
  int iVar1;
  uchar **ppuVar2;
  ulong *puVar3;
  ulong *puVar4;
  uchar **ppuStack_50;
  undefined4 uStack_4c;
  int *piStack_48;
  ulong *puStack_44;
  Alignment *pAStack_40;
  undefined4 *puStack_3c;
  ulong dwLen1;
  uchar *lpWrite1;
  uint uChkErr;
  uchar *lpWrite2;
  ulong dwLen2;
  _DSBUFFERDESC dsbd;
  
  if (((_bFileOpen != 0) || (_bPlaying != 0)) || (_bTimerInstalled != 0)) {
    puStack_3c = (undefined4 *)0x448717;
    ds_stream_stop();
  }
  puStack_3c = (undefined4 *)0x88847c;
  pAStack_40 = (Alignment *)&_wiWave;
  puStack_44 = &DAT_00888464;
  piStack_48 = (int *)param_1;
  _stream_paused = 0;
  uStack_4c = 0x448736;
  iVar1 = _WaveOpenFile();
  if (iVar1 != 0) {
    return 0;
  }
  if (*_wiWave != 1) {
    puStack_3c = &_wiWave;
    pAStack_40 = (Alignment *)&DAT_00888464;
    puStack_44 = (ulong *)0x448766;
    _WaveCloseReadFile();
    return 0;
  }
  puStack_3c = (undefined4 *)0x88847c;
  pAStack_40 = &DAT_00888468;
  puStack_44 = &DAT_00888464;
  piStack_48 = (int *)0x448787;
  iVar1 = _WaveStartDataRead();
  if (iVar1 == 0) {
    puStack_3c = (undefined4 *)0x14;
    pAStack_40 = (Alignment *)0x0;
    DAT_00888498 = (uint)(*(int *)(_wiWave + 4) * 0x78) / 600;
    puStack_44 = &dsbd.dwFlags;
    DAT_00888494 = DAT_00888498 * 6;
    piStack_48 = (int *)0x4487ee;
    memset();
    puStack_44 = &dsbd.dwFlags;
    puStack_3c = (undefined4 *)0x0;
    dsbd.dwFlags = 0x14;
    dsbd.dwBufferBytes = 0xe0;
    dsbd.dwReserved = DAT_00888494;
    pAStack_40 = (Alignment *)&_lpDSBStreamBuffer;
    piStack_48 = _lpDS;
    uStack_4c = 0x44882b;
    iVar1 = (**(code **)(*_lpDS + 0xc))();
    if (iVar1 != 0) {
      return 0;
    }
    ppuStack_50 = &lpWrite1;
    uStack_4c = 0;
    puVar3 = &dwLen1;
    ppuVar2 = (uchar **)&stack0xffffffc8;
    DAT_00888490 = _lpDSBStreamBuffer;
    DAT_008884b0 = 0;
    DAT_008884b4 = 0;
    iVar1 = (**(code **)(*_lpDSBStreamBuffer + 0x2c))
                      (_lpDSBStreamBuffer,0,DAT_00888494,&stack0xffffffcc,ppuVar2,puVar3);
    if (iVar1 == 0) {
      puVar4 = puVar3;
      if ((ppuVar2 != (uchar **)0x0) &&
         (_WaveReadFile(DAT_00888464,ppuVar2,puVar3,&DAT_00888468,&ppuStack_50), puVar4 = puVar3,
         ppuStack_50 < ppuVar2)) {
        if (DAT_008884ac == 0) {
          DAT_008884b4 = (uint)ppuStack_50 / DAT_00888498;
          DAT_008884b0 = 1;
          memset((int)ppuStack_50 + (int)puVar3,(_wiWave[7] != 8) - 1U & 0x80,
                 (int)ppuVar2 - (int)ppuStack_50);
          puVar4 = puVar3;
        }
        else {
          do {
            ppuVar2 = (uchar **)((int)ppuVar2 - (int)ppuStack_50);
            puVar3 = (ulong *)((int)puVar3 + (int)ppuStack_50);
            _WaveStartDataRead(&DAT_00888464,&DAT_00888468,0x88847c);
            _WaveReadFile(DAT_00888464,ppuVar2,puVar3,&DAT_00888468,&ppuStack_50);
          } while (ppuStack_50 < ppuVar2);
        }
      }
      (**(code **)(*_lpDSBStreamBuffer + 0x4c))(_lpDSBStreamBuffer,puVar4,ppuVar2,uStack_4c,0);
      DAT_008884ac = (uint)puStack_3c & 0xff;
      DAT_008884a4 = 0;
      DAT_008884a0 = 0;
      DAT_0088849c = 0;
      DAT_008884a8 = 0;
      _bFileOpen = 1;
      SendMessageA(_main_wnd,0x502,0,0);
      (**(code **)(*_lpDSBStreamBuffer + 0x34))(_lpDSBStreamBuffer,0);
      (**(code **)(*_lpDSBStreamBuffer + 0x3c))(_lpDSBStreamBuffer,pAStack_40);
      (**(code **)(*_lpDSBStreamBuffer + 0x30))(_lpDSBStreamBuffer,0,0,1);
      iVar1 = timeBeginPeriod(0x32);
      if (iVar1 == 0) {
        _uTimerID = timeSetEvent(0x32,10,ds_stream_time_func,0,1);
        if (_uTimerID != 0) {
          _bTimerInstalled = 1;
        }
        _bPlaying = 1;
        return 1;
      }
      (**(code **)(*_lpDSBStreamBuffer + 0x48))(_lpDSBStreamBuffer);
      _bTimerInstalled = 0;
      _bPlaying = 0;
      return 0;
    }
    return 0;
  }
  puStack_3c = &_wiWave;
  pAStack_40 = (Alignment *)&DAT_00888464;
  puStack_44 = (ulong *)0x44879d;
  _WaveCloseReadFile();
  return 0;
}

// --------------------------------------------------

// Function: FUN_00448a33
// Address: 00448a33
bool FUN_00448a33(undefined4 param_1)
{
  int iVar1;
  
  if (_lpDSBStreamBuffer == (int *)0x0) {
    return false;
  }
  iVar1 = (**(code **)(*_lpDSBStreamBuffer + 0x3c))(_lpDSBStreamBuffer,param_1);
  return iVar1 == 0;
}

// --------------------------------------------------

// Function: ds_stream_volume
// Address: 00448a40
/* ds_stream_volume */

bool __cdecl ds_stream_volume(undefined4 param_1)
{
  int iVar1;
  
  if (_lpDSBStreamBuffer == (int *)0x0) {
    return false;
  }
  iVar1 = (**(code **)(*_lpDSBStreamBuffer + 0x3c))(_lpDSBStreamBuffer,param_1);
  return iVar1 == 0;
}

// --------------------------------------------------

// Function: FUN_00448a5f
// Address: 00448a5f
void FUN_00448a5f(void)
{
  _stream_paused = 1;
  return;
}

// --------------------------------------------------

// Function: ds_stream_pause
// Address: 00448a60
/* ds_stream_pause */

void __cdecl ds_stream_pause(void)
{
  _stream_paused = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00448a6b
// Address: 00448a6b
undefined4 FUN_00448a6b(void)
{
  _stream_paused = 0;
  return 1;
}

// --------------------------------------------------

// Function: ds_stream_resume
// Address: 00448a70
/* ds_stream_resume */

undefined4 __cdecl ds_stream_resume(void)
{
  _stream_paused = 0;
  return 1;
}

// --------------------------------------------------

// Function: ds_stream_stop
// Address: 00448a80
/* ds_stream_stop */

undefined4 __cdecl ds_stream_stop(void)
{
  DAT_008884a8 = 1;
  if (_bTimerInstalled != 0) {
    _bTimerInstalled = 0;
    timeKillEvent(_uTimerID);
    timeEndPeriod(0x32);
  }
  if ((_bPlaying != 0) && (_bPlaying = 0, _lpDSBStreamBuffer != (int *)0x0)) {
    (**(code **)(*_lpDSBStreamBuffer + 0x48))(_lpDSBStreamBuffer);
  }
  if (_bFileOpen != 0) {
    if (_wiWave != 0) {
      _WaveCloseReadFile(&DAT_00888464,&_wiWave);
      _wiWave = 0;
    }
    if (_lpDSBStreamBuffer != (int *)0x0) {
      (**(code **)(*_lpDSBStreamBuffer + 8))(_lpDSBStreamBuffer);
      _lpDSBStreamBuffer = (int *)0x0;
      DAT_00888490 = 0;
    }
    _bFileOpen = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00448b22
// Address: 00448b22
undefined4 FUN_00448b22(undefined4 param_1,int param_2)
{
  int iVar1;
  
  if (param_2 == 0x500) {
    ds_stream_stop();
  }
  else if (param_2 == 0x502) {
    if (DAT_00888480 < DAT_008884a4) {
      DAT_008884a4 = DAT_008884a4 - DAT_00888480;
    }
    iVar1 = __ftol((DAT_008884a4 * 100) / DAT_00888480,0);
    if (iVar1 != _uLastPercent) {
      _uLastPercent = iVar1;
      return 0;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: ds_stream_messages
// Address: 00448b30
/* ds_stream_messages */

undefined4 __cdecl ds_stream_messages(undefined4 param_1,int param_2)
{
  int iVar1;
  
  if (param_2 == 0x500) {
    ds_stream_stop();
  }
  else if (param_2 == 0x502) {
    if (DAT_00888480 < DAT_008884a4) {
      DAT_008884a4 = DAT_008884a4 - DAT_00888480;
    }
    iVar1 = __ftol((DAT_008884a4 * 100) / DAT_00888480,0);
    if (iVar1 != _uLastPercent) {
      _uLastPercent = iVar1;
      return 0;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00448b99
// Address: 00448b99
/* WARNING: Type propagation algorithm not settling */

void FUN_00448b99(void)
{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int *piVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  int *piStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined1 auStack_18 [4];
  int *piStack_14;
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  if (DAT_0062e658 != 0) {
    return;
  }
  if (_stream_paused != 0) {
    return;
  }
  DAT_0062e658 = 1;
  if (DAT_008884a8 != 0) {
    DAT_0062e658 = 0;
    return;
  }
  if (DAT_00888490 == (int *)0x0) {
    DAT_0062e658 = 0;
    return;
  }
  puStack_2c = auStack_4;
  puStack_30 = auStack_8;
  piStack_34 = DAT_00888490;
  puStack_38 = (undefined1 *)0x448bf6;
  (**(code **)(*DAT_00888490 + 0x10))();
  piVar1 = DAT_008884a0;
  if ((DAT_0088849c < piStack_14) && (piStack_14 < (int *)((int)DAT_0088849c + DAT_00888498))) {
    DAT_0062e658 = 0;
    return;
  }
  if ((DAT_008884b0 != 0) && (DAT_008884b4 == 0)) {
    if (DAT_008884a8 != 0) {
      DAT_0062e658 = 0;
      return;
    }
    puStack_38 = (undefined1 *)0x0;
    puStack_3c = (undefined1 *)0x0;
    DAT_008884a8 = 1;
    PostMessageA(_main_wnd,0x500);
    DAT_0062e658 = 0;
    return;
  }
  piVar5 = piStack_14;
  if (piStack_14 < DAT_008884a0) {
    piVar5 = (int *)((int)DAT_00888494 + (int)piStack_14);
  }
  DAT_008884a0 = piStack_14;
  puStack_38 = (undefined1 *)0x0;
  puStack_3c = (undefined1 *)0x0;
  DAT_008884a4 = (int)piVar5 + (DAT_008884a4 - (int)piVar1);
  PostMessageA(_main_wnd,0x502);
  if ((DAT_008884b0 == 0) || (DAT_008884b4 == 0)) {
    if (DAT_00888490 == (int *)0x0) {
      DAT_0062e658 = 0;
      return;
    }
    puStack_3c = &stack0xffffffdc;
    puStack_38 = (undefined1 *)0x0;
    puVar6 = auStack_18;
    puVar4 = &stack0xffffffd8;
    puVar3 = &stack0xffffffe0;
    iVar2 = (**(code **)(*DAT_00888490 + 0x2c))(DAT_00888490,DAT_0088849c,DAT_00888498);
    if (iVar2 != 0) {
      DAT_0062e658 = 0;
      return;
    }
    if ((puVar3 == (undefined1 *)0x0) || (DAT_008884a8 != 0)) {
      puVar8 = puVar6;
      if ((puVar3 != (undefined1 *)0x0) &&
         (((DAT_008884a8 != 0 && (_wiWave != 0)) && (puVar6 != (undefined1 *)0x0)))) {
        memset(puVar6,(*(short *)(_wiWave + 0xe) != 8) - 1U & 0x80,puVar3);
        puVar8 = puVar6;
      }
    }
    else {
      _WaveReadFile(DAT_00888464,puVar3,puVar6,&DAT_00888468,&puStack_3c);
      puVar8 = puVar6;
      if (puStack_3c < puVar3) {
        if (DAT_008884ac == 0) {
          if ((_wiWave != 0) && (puVar6 != (undefined1 *)0x0)) {
            if (*(short *)(_wiWave + 0xe) == 8) {
              uVar7 = 0x80;
            }
            else {
              if (*(short *)(_wiWave + 0xe) != 0x10) goto LAB_00448e44;
              uVar7 = 0;
            }
            memset(puStack_3c + (int)puVar6,uVar7,(int)puVar3 - (int)puStack_3c);
          }
LAB_00448e44:
          DAT_008884b0 = 1;
          puVar8 = puVar6;
          if (DAT_0088849c < piStack_34) {
            DAT_008884b4 = (uint)(((int)DAT_0088849c + (int)DAT_00888494) - (int)piStack_34) /
                           DAT_00888498;
          }
          else {
            DAT_008884b4 = (uint)((int)DAT_0088849c - (int)piStack_34) / DAT_00888498;
          }
        }
        else if (puVar6 != (undefined1 *)0x0) {
          do {
            puVar3 = puVar3 + -(int)puStack_3c;
            puVar6 = puVar6 + (int)puStack_3c;
            _WaveStartDataRead(&DAT_00888464,&DAT_00888468,0x88847c);
            _WaveReadFile(DAT_00888464,puVar3,puVar6,&DAT_00888468,&puStack_3c);
          } while (puStack_3c < puVar3);
        }
      }
    }
    if (puVar4 != (undefined1 *)0x0) {
      if (DAT_008884a8 == 0) {
        _WaveReadFile(DAT_00888464,puVar4,puStack_38,&DAT_00888468,&puStack_3c);
        if (puStack_3c < puVar4) {
          if (DAT_008884ac == 0) {
            if ((_wiWave != 0) && (puStack_38 != (undefined1 *)0x0)) {
              if (*(short *)(_wiWave + 0xe) == 8) {
                uVar7 = 0x80;
              }
              else {
                if (*(short *)(_wiWave + 0xe) != 0x10) goto LAB_00448faa;
                uVar7 = 0;
              }
              memset(puStack_3c + (int)puStack_38,uVar7,(int)puVar4 - (int)puStack_3c);
            }
LAB_00448faa:
            DAT_008884b0 = 1;
            if (DAT_0088849c < piStack_34) {
              DAT_008884b4 = (uint)(((int)DAT_0088849c + (int)DAT_00888494) - (int)piStack_34) /
                             DAT_00888498;
            }
            else {
              DAT_008884b4 = (uint)((int)DAT_0088849c - (int)piStack_34) / DAT_00888498;
            }
          }
          else {
            puVar6 = puStack_38;
            if (puStack_38 != (undefined1 *)0x0) {
              do {
                puVar4 = puVar4 + -(int)puStack_3c;
                puVar6 = puVar6 + (int)puStack_3c;
                _WaveStartDataRead(&DAT_00888464,&DAT_00888468,0x88847c);
                _WaveReadFile(DAT_00888464,puVar4,puVar6,&DAT_00888468,&puStack_3c);
              } while (puStack_3c < puVar4);
            }
          }
        }
      }
      else if (((puVar4 != (undefined1 *)0x0) && (DAT_008884a8 != 0)) &&
              ((_wiWave != 0 && (puStack_38 != (undefined1 *)0x0)))) {
        memset(puStack_38,(*(short *)(_wiWave + 0xe) != 8) - 1U & 0x80,puVar4);
      }
    }
    if (DAT_00888490 != (int *)0x0) {
      (**(code **)(*DAT_00888490 + 0x4c))(DAT_00888490,puVar8,puVar3,puStack_38,puVar4);
    }
    DAT_0088849c = (int *)((int)DAT_0088849c + DAT_00888498);
    if (DAT_0088849c < DAT_00888494) {
      DAT_0062e658 = 0;
      return;
    }
    goto LAB_004490be;
  }
  DAT_008884b4 = DAT_008884b4 - 1;
  if ((int)DAT_008884b4 < 2) {
    DAT_0062e658 = 0;
    return;
  }
  if (DAT_00888490 == (int *)0x0) {
    DAT_0062e658 = 0;
    return;
  }
  puStack_3c = &stack0xffffffdc;
  puStack_38 = (undefined1 *)0x0;
  puVar6 = auStack_18;
  puVar4 = &stack0xffffffd8;
  puVar3 = &stack0xffffffe0;
  iVar2 = (**(code **)(*DAT_00888490 + 0x2c))(DAT_00888490,DAT_0088849c,DAT_00888498,puVar3,puVar4);
  if (iVar2 != 0) {
    DAT_0062e658 = 0;
    return;
  }
  if ((_wiWave != 0) && (puVar6 != (undefined1 *)0x0)) {
    if (*(short *)(_wiWave + 0xe) == 8) {
      uVar7 = 0x80;
    }
    else {
      if (*(short *)(_wiWave + 0xe) != 0x10) goto LAB_00448d37;
      uVar7 = 0;
    }
    memset(puVar6,uVar7,puVar3);
  }
LAB_00448d37:
  (**(code **)(*DAT_00888490 + 0x4c))(DAT_00888490,puVar6,puVar3,puStack_38,puVar4);
  DAT_0088849c = (int *)((int)DAT_0088849c + DAT_00888498);
  if (DAT_0088849c < DAT_00888494) {
    DAT_0062e658 = 0;
    return;
  }
LAB_004490be:
  DAT_0088849c = (int *)((int)DAT_0088849c - (int)DAT_00888494);
  DAT_0062e658 = 0;
  return;
}

// --------------------------------------------------

// Function: ds_stream_time_func
// Address: 00448ba0
/* WARNING: Variable defined which should be unmapped: dwLen1 */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall ds_stream_time_func,20 */

void ds_stream_time_func(void)
{
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  uchar **ppuVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  uchar **ppuVar8;
  ulong *puStack_3c;
  undefined1 *puStack_38;
  int *piStack_34;
  ulong *puStack_30;
  undefined1 *puStack_2c;
  ulong dwLen1;
  ulong dwLen2;
  uchar *lpWrite1;
  uint uChkErr;
  uchar *lpWrite2;
  ulong dwPlay;
  ulong dwWrite;
  undefined1 local_4 [4];
  uint uVar4;
  
  if (DAT_0062e658 != 0) {
    return;
  }
  if (_stream_paused != 0) {
    return;
  }
  DAT_0062e658 = 1;
  if (DAT_008884a8 != 0) {
    DAT_0062e658 = 0;
    return;
  }
  if (DAT_00888490 == (int *)0x0) {
    DAT_0062e658 = 0;
    return;
  }
  puStack_2c = local_4;
  puStack_30 = &dwWrite;
  piStack_34 = DAT_00888490;
  puStack_38 = (undefined1 *)0x448bf6;
  (**(code **)(*DAT_00888490 + 0x10))();
  if ((DAT_0088849c < uChkErr) && (uChkErr < (int)DAT_0088849c + DAT_00888498)) {
    DAT_0062e658 = 0;
    return;
  }
  if ((DAT_008884b0 != 0) && (DAT_008884b4 == 0)) {
    if (DAT_008884a8 != 0) {
      DAT_0062e658 = 0;
      return;
    }
    puStack_38 = (undefined1 *)0x0;
    puStack_3c = (ulong *)0x0;
    DAT_008884a8 = 1;
    PostMessageA(_main_wnd,0x500);
    DAT_0062e658 = 0;
    return;
  }
  uVar4 = uChkErr;
  if (uChkErr < DAT_008884a0) {
    uVar4 = (int)DAT_00888494 + uChkErr;
  }
  iVar3 = uVar4 - DAT_008884a0;
  DAT_008884a0 = uChkErr;
  puStack_38 = (undefined1 *)0x0;
  puStack_3c = (ulong *)0x0;
  DAT_008884a4 = DAT_008884a4 + iVar3;
  PostMessageA(_main_wnd,0x502);
  if ((DAT_008884b0 == 0) || (DAT_008884b4 == 0)) {
    if (DAT_00888490 == (int *)0x0) {
      DAT_0062e658 = 0;
      return;
    }
    puStack_3c = (ulong *)&stack0xffffffdc;
    puStack_38 = (undefined1 *)0x0;
    ppuVar5 = &lpWrite1;
    puVar2 = (ulong *)&stack0xffffffd8;
    puVar1 = &dwLen1;
    iVar3 = (**(code **)(*DAT_00888490 + 0x2c))(DAT_00888490,DAT_0088849c,DAT_00888498);
    if (iVar3 != 0) {
      DAT_0062e658 = 0;
      return;
    }
    if ((puVar1 == (ulong *)0x0) || (DAT_008884a8 != 0)) {
      ppuVar8 = ppuVar5;
      if ((puVar1 != (ulong *)0x0) &&
         (((DAT_008884a8 != 0 && (_wiWave != 0)) && (ppuVar5 != (uchar **)0x0)))) {
        memset(ppuVar5,(*(short *)(_wiWave + 0xe) != 8) - 1U & 0x80,puVar1);
        ppuVar8 = ppuVar5;
      }
    }
    else {
      _WaveReadFile(DAT_00888464,puVar1,ppuVar5,&DAT_00888468,&puStack_3c);
      ppuVar8 = ppuVar5;
      if (puStack_3c < puVar1) {
        if (DAT_008884ac == 0) {
          if ((_wiWave != 0) && (ppuVar5 != (uchar **)0x0)) {
            if (*(short *)(_wiWave + 0xe) == 8) {
                    /* language.dll match for 0x80: "Arial" */
              uVar7 = 0x80;
            }
            else {
              if (*(short *)(_wiWave + 0xe) != 0x10) goto LAB_00448e44;
              uVar7 = 0;
            }
            memset((undefined1 *)((int)puStack_3c + (int)ppuVar5),uVar7,
                   (int)puVar1 - (int)puStack_3c);
          }
LAB_00448e44:
          DAT_008884b0 = 1;
          ppuVar8 = ppuVar5;
          if (DAT_0088849c < piStack_34) {
            DAT_008884b4 = (uint)(((int)DAT_0088849c + (int)DAT_00888494) - (int)piStack_34) /
                           DAT_00888498;
          }
          else {
            DAT_008884b4 = (uint)((int)DAT_0088849c - (int)piStack_34) / DAT_00888498;
          }
        }
        else if (ppuVar5 != (uchar **)0x0) {
          do {
            puVar1 = (ulong *)((int)puVar1 - (int)puStack_3c);
            ppuVar5 = (uchar **)((int)ppuVar5 + (int)puStack_3c);
            _WaveStartDataRead(&DAT_00888464,&DAT_00888468,0x88847c);
            _WaveReadFile(DAT_00888464,puVar1,ppuVar5,&DAT_00888468,&puStack_3c);
          } while (puStack_3c < puVar1);
        }
      }
    }
    if (puVar2 != (ulong *)0x0) {
      if (DAT_008884a8 == 0) {
        _WaveReadFile(DAT_00888464,puVar2,puStack_38,&DAT_00888468,&puStack_3c);
        if (puStack_3c < puVar2) {
          if (DAT_008884ac == 0) {
            if ((_wiWave != 0) && (puStack_38 != (undefined1 *)0x0)) {
              if (*(short *)(_wiWave + 0xe) == 8) {
                    /* language.dll match for 0x80: "Arial" */
                uVar7 = 0x80;
              }
              else {
                if (*(short *)(_wiWave + 0xe) != 0x10) goto LAB_00448faa;
                uVar7 = 0;
              }
              memset((undefined1 *)((int)puStack_3c + (int)puStack_38),uVar7,
                     (int)puVar2 - (int)puStack_3c);
            }
LAB_00448faa:
            DAT_008884b0 = 1;
            if (DAT_0088849c < piStack_34) {
              DAT_008884b4 = (uint)(((int)DAT_0088849c + (int)DAT_00888494) - (int)piStack_34) /
                             DAT_00888498;
            }
            else {
              DAT_008884b4 = (uint)((int)DAT_0088849c - (int)piStack_34) / DAT_00888498;
            }
          }
          else {
            puVar6 = puStack_38;
            if (puStack_38 != (undefined1 *)0x0) {
              do {
                puVar2 = (ulong *)((int)puVar2 - (int)puStack_3c);
                puVar6 = puVar6 + (int)puStack_3c;
                _WaveStartDataRead(&DAT_00888464,&DAT_00888468,0x88847c);
                _WaveReadFile(DAT_00888464,puVar2,puVar6,&DAT_00888468,&puStack_3c);
              } while (puStack_3c < puVar2);
            }
          }
        }
      }
      else if (((puVar2 != (ulong *)0x0) && (DAT_008884a8 != 0)) &&
              ((_wiWave != 0 && (puStack_38 != (undefined1 *)0x0)))) {
        memset(puStack_38,(*(short *)(_wiWave + 0xe) != 8) - 1U & 0x80,puVar2);
      }
    }
    if (DAT_00888490 != (int *)0x0) {
      (**(code **)(*DAT_00888490 + 0x4c))(DAT_00888490,ppuVar8,puVar1,puStack_38,puVar2);
    }
    DAT_0088849c = (int *)((int)DAT_0088849c + DAT_00888498);
    if (DAT_0088849c < DAT_00888494) {
      DAT_0062e658 = 0;
      return;
    }
    goto LAB_004490be;
  }
  DAT_008884b4 = DAT_008884b4 - 1;
  if ((int)DAT_008884b4 < 2) {
    DAT_0062e658 = 0;
    return;
  }
  if (DAT_00888490 == (int *)0x0) {
    DAT_0062e658 = 0;
    return;
  }
  puStack_3c = (ulong *)&stack0xffffffdc;
  puStack_38 = (undefined1 *)0x0;
  ppuVar5 = &lpWrite1;
  puVar6 = &stack0xffffffd8;
  puVar2 = &dwLen1;
  iVar3 = (**(code **)(*DAT_00888490 + 0x2c))(DAT_00888490,DAT_0088849c,DAT_00888498,puVar2,puVar6);
  if (iVar3 != 0) {
    DAT_0062e658 = 0;
    return;
  }
  if ((_wiWave != 0) && (ppuVar5 != (uchar **)0x0)) {
    if (*(short *)(_wiWave + 0xe) == 8) {
                    /* language.dll match for 0x80: "Arial" */
      uVar7 = 0x80;
    }
    else {
      if (*(short *)(_wiWave + 0xe) != 0x10) goto LAB_00448d37;
      uVar7 = 0;
    }
    memset(ppuVar5,uVar7,puVar2);
  }
LAB_00448d37:
  (**(code **)(*DAT_00888490 + 0x4c))(DAT_00888490,ppuVar5,puVar2,puStack_38,puVar6);
  DAT_0088849c = (int *)((int)DAT_0088849c + DAT_00888498);
  if (DAT_0088849c < DAT_00888494) {
    DAT_0062e658 = 0;
    return;
  }
LAB_004490be:
  DAT_0088849c = (int *)((int)DAT_0088849c - (int)DAT_00888494);
  DAT_0062e658 = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004490d4
// Address: 004490d4
undefined4 * __thiscall FUN_004490d4(undefined4 *param_1,int param_2)
{
  int *piVar1;
  short *psVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  int iStack_14;
  int iStack_10;
  
  iVar4 = param_2;
  piVar1 = param_1 + 2;
  *param_1 = &RGE_Effects::_vftable_;
  rge_read(param_2,piVar1,4);
  if (*piVar1 < 1) {
    param_1[1] = 0;
    *piVar1 = 0;
  }
  else {
    uVar5 = calloc(*piVar1,0x2c);
    param_1[1] = uVar5;
    iStack_10 = 0;
    if (0 < *piVar1) {
      iStack_14 = 0;
      do {
        iVar6 = param_1[1];
        rge_read(iVar4,(void *)(iVar6 + 2),0x1f);
        psVar2 = (short *)(iStack_14 + 0x24 + iVar6);
        rge_read(iVar4,psVar2,2);
        if (*psVar2 < 1) {
          *(undefined4 *)(iStack_14 + 0x28 + iVar6) = 0;
        }
        else {
          piVar3 = (int *)(iStack_14 + 0x28 + iVar6);
          iVar6 = calloc((int)*psVar2,0xc);
          iVar7 = 0;
          *piVar3 = iVar6;
          if (0 < *psVar2) {
            param_2 = 0;
            do {
              pvVar8 = (void *)(*piVar3 + param_2);
              rge_read(iVar4,pvVar8,1);
              rge_read(iVar4,(void *)((int)pvVar8 + 2),2);
              rge_read(iVar4,(void *)((int)pvVar8 + 4),2);
              rge_read(iVar4,(void *)((int)pvVar8 + 6),2);
              rge_read(iVar4,(void *)((int)pvVar8 + 8),4);
              iVar7 = iVar7 + 1;
              param_2 = param_2 + 0xc;
            } while (iVar7 < *psVar2);
          }
        }
        iStack_10 = iStack_10 + 1;
        iStack_14 = iStack_14 + 0x2c;
      } while (iStack_10 < *piVar1);
      return param_1;
    }
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044925e
// Address: 0044925e
// [HELPER] s__d: "%d"
// [HELPER] s__d__d: "%d+%d"
// [HELPER] s__hd__hd__hd__hd__f: "%hd %hd %hd %hd %f"
// [HELPER] s__s__hd: "%s %hd"
// [HELPER] s_r: "r"
undefined4 * __thiscall FUN_0044925e(undefined4 *param_1,undefined4 param_2)
{
  undefined4 *puVar1;
  undefined1 *puVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  short sVar7;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  *param_1 = &RGE_Effects::_vftable_;
  iVar4 = fopen(param_2,s_r);
  if (iVar4 == 0) {
    param_1[2] = 0;
    param_1[1] = 0;
    return param_1;
  }
  puVar1 = param_1 + 2;
  iVar5 = fscanf(iVar4,s__d__d,puVar1,&iStack_4);
  if (iVar5 == -1) {
    *puVar1 = 0;
    param_1[1] = 0;
  }
  else {
    uVar6 = calloc(*puVar1,0x2c);
    param_1[1] = uVar6;
    iStack_8 = 0;
    if (0 < iStack_4) {
      while( true ) {
        sVar7 = 0;
        fscanf(iVar4,&s__d,&iStack_c);
        iVar5 = param_1[1] + iStack_c * 0x2c;
        iVar5 = fscanf(iVar4,s__s__hd,iVar5 + 2,iVar5 + 0x24);
        if (iVar5 == -1) break;
        *(short *)(param_1[1] + iStack_c * 0x2c) = (short)iStack_c;
        sVar3 = *(short *)(param_1[1] + 0x24 + iStack_c * 0x2c);
        if (sVar3 < 1) {
          *(undefined4 *)(param_1[1] + iStack_c * 0x2c + 0x28) = 0;
        }
        else {
          uVar6 = calloc((int)sVar3,0xc);
          *(undefined4 *)(param_1[1] + 0x28 + iStack_c * 0x2c) = uVar6;
          iVar5 = param_1[1] + iStack_c * 0x2c;
          if (0 < *(short *)(param_1[1] + 0x24 + iStack_c * 0x2c)) {
            do {
              puVar2 = (undefined1 *)(*(int *)(iVar5 + 0x28) + sVar7 * 0xc);
              iVar5 = fscanf(iVar4,s__hd__hd__hd__hd__f,&param_2,puVar2 + 2,puVar2 + 4,puVar2 + 6,
                             puVar2 + 8);
              if (iVar5 == -1) break;
              sVar7 = sVar7 + 1;
              *puVar2 = (undefined1)param_2;
              iVar5 = param_1[1] + iStack_c * 0x2c;
            } while (sVar7 < *(short *)(param_1[1] + 0x24 + iStack_c * 0x2c));
          }
        }
        convert_us((char *)(param_1[1] + 2 + iStack_c * 0x2c));
        iStack_8 = iStack_8 + 1;
        if (iStack_4 <= iStack_8) {
          fclose(iVar4);
          return param_1;
        }
      }
    }
  }
  fclose(iVar4);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044943e
// Address: 0044943e
void __fastcall FUN_0044943e(undefined4 *param_1)
{
  int iVar1;
  int iVar2;
  short sVar3;
  
  sVar3 = 0;
  *param_1 = &RGE_Effects::_vftable_;
  if (0 < (int)param_1[2]) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(param_1[1] + 0x28 + iVar2 * 0x2c);
      if (iVar1 != 0) {
        free(iVar1);
      }
      sVar3 = sVar3 + 1;
      *(undefined4 *)(param_1[1] + 0x28 + iVar2 * 0x2c) = 0;
      iVar2 = (int)sVar3;
    } while (iVar2 < (int)param_1[2]);
  }
  if (param_1[1] != 0) {
    free(param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004494a3
// Address: 004494a3
void __thiscall FUN_004494a3(int param_1,int param_2)
{
  int *piVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int iStack_14;
  
  iVar4 = param_2;
  piVar1 = (int *)(param_1 + 8);
  rge_write(param_2,piVar1,4);
  iStack_14 = 0;
  if (0 < *piVar1) {
    param_2 = 0;
    do {
      iVar3 = *(int *)(param_1 + 4);
      rge_write(iVar4,(void *)(iVar3 + 2),0x1f);
      psVar2 = (short *)(param_2 + 0x24 + iVar3);
      rge_write(iVar4,psVar2,2);
      iVar5 = 0;
      if (0 < *psVar2) {
        iVar6 = 0;
        do {
          pvVar7 = (void *)(*(int *)(param_2 + 0x28 + iVar3) + iVar6);
          rge_write(iVar4,pvVar7,1);
          rge_write(iVar4,(void *)((int)pvVar7 + 2),2);
          rge_write(iVar4,(void *)((int)pvVar7 + 4),2);
          rge_write(iVar4,(void *)((int)pvVar7 + 6),2);
          rge_write(iVar4,(void *)((int)pvVar7 + 8),4);
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0xc;
        } while (iVar5 < *psVar2);
      }
      iStack_14 = iStack_14 + 1;
      param_2 = param_2 + 0x2c;
    } while (iStack_14 < *piVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004495b9
// Address: 004495b9
void __thiscall FUN_004495b9(int param_1,short param_2,RGE_Player *param_3)
{
  int iVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  
  if ((((int)param_2 < *(int *)(param_1 + 8)) &&
      (iVar1 = *(int *)(param_1 + 4) + param_2 * 0x2c, iVar1 != 0)) &&
     (sVar4 = 0, 0 < *(short *)(iVar1 + 0x24))) {
    do {
      iVar2 = *(int *)(iVar1 + 0x28) + sVar4 * 0xc;
      switch(*(undefined1 *)(*(int *)(iVar1 + 0x28) + sVar4 * 0xc)) {
      case 0:
        RGE_Player::modify_tobj
                  (param_3,*(short *)(iVar2 + 2),*(short *)(iVar2 + 4),*(float *)(iVar2 + 8),
                   (uchar)*(undefined2 *)(iVar2 + 6));
        break;
      case 1:
        sVar3 = *(short *)(iVar2 + 2);
        if (-1 < sVar3) {
          if (*(short *)(iVar2 + 4) == 0) {
            RGE_Player::new_attribute_num(param_3,sVar3,*(float *)(iVar2 + 8));
          }
          else {
            (**(code **)(param_3->_padding_ + 0x78))(sVar3,*(float *)(iVar2 + 8),0);
          }
        }
        break;
      case 2:
        if (-1 < *(short *)(iVar2 + 2)) {
          RGE_Player::make_available(param_3,*(short *)(iVar2 + 2),*(uchar *)(iVar2 + 4));
        }
        break;
      case 3:
        RGE_Player::copy_obj(param_3,*(short *)(iVar2 + 2),*(short *)(iVar2 + 4));
        break;
      case 4:
        RGE_Player::modify_tobj_delta
                  (param_3,*(short *)(iVar2 + 2),*(short *)(iVar2 + 4),*(float *)(iVar2 + 8),
                   (uchar)*(undefined2 *)(iVar2 + 6));
        break;
      case 5:
        RGE_Player::modify_tobj_percent
                  (param_3,*(short *)(iVar2 + 2),*(short *)(iVar2 + 4),*(float *)(iVar2 + 8),
                   (uchar)*(undefined2 *)(iVar2 + 6));
      }
      sVar4 = sVar4 + 1;
    } while (sVar4 < *(short *)(iVar1 + 0x24));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004496ed
// Address: 004496ed
/* WARNING: Unable to track spacebase fully for stack */

int __fastcall FUN_004496ed(undefined4 param_1,char *param_2)
{
  byte bVar1;
  char *in_EAX;
  byte *pbVar2;
  char cVar3;
  int unaff_EBX;
  undefined4 unaff_ESI;
  byte *pbVar4;
  bool bVar5;
  int unaff_retaddr;
  
  cVar3 = (char)((uint)unaff_EBX >> 8);
  *(char *)(unaff_EBX + -0x6a) = *(char *)(unaff_EBX + -0x6a) + cVar3;
  *(char *)(unaff_EBX + -0x34ffbb6a) =
       *(char *)(unaff_EBX + -0x34ffbb6a) + (char)((uint)param_2 >> 8);
  *in_EAX = *in_EAX + (char)unaff_EBX;
  *param_2 = *param_2 + cVar3;
  in_EAX[-0x6f6f6f70] = in_EAX[-0x6f6f6f70] + (char)param_2;
  pbVar2 = *(byte **)(unaff_retaddr + 9);
  *(int *)(unaff_retaddr + 1) = unaff_EBX;
  *(undefined4 *)(unaff_retaddr + -3) = unaff_ESI;
  pbVar4 = *(byte **)(unaff_retaddr + 0xd);
  while( true ) {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}

// --------------------------------------------------

// Function: compareFilenameStrings
// Address: 00449710
/* int __cdecl compareFilenameStrings(void const *,void const *) */

int __cdecl compareFilenameStrings(void *param_1,void *param_2)
{
  byte bVar1;
  bool bVar2;
  
  while( true ) {
                    /* WARNING: Load size is inaccurate */
    bVar1 = *param_1;
                    /* WARNING: Load size is inaccurate */
    bVar2 = bVar1 < *param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = *(byte *)((int)param_1 + 1);
    bVar2 = bVar1 < *(byte *)((int)param_2 + 1);
    if (bVar1 != *(byte *)((int)param_2 + 1)) break;
    param_1 = (void *)((int)param_1 + 2);
    param_2 = (void *)((int)param_2 + 2);
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (1 - (uint)bVar2) - (uint)(bVar2 != 0);
}

// --------------------------------------------------

// Function: FUN_0044974b
// Address: 0044974b
int FUN_0044974b(int param_1)
{
  return param_1 + 0x40;
}

// --------------------------------------------------

// Function: driveAsLetter
// Address: 00449750
/* char __cdecl driveAsLetter(int) */

char __cdecl driveAsLetter(int param_1)
{
  return (char)param_1 + '@';
}

// --------------------------------------------------

// Function: FUN_00449758
// Address: 00449758
int FUN_00449758(char param_1)
{
  return param_1 + -0x40;
}

// --------------------------------------------------

// Function: driveAsInt
// Address: 00449760
/* int __cdecl driveAsInt(char) */

int __cdecl driveAsInt(char param_1)
{
  return param_1 + -0x40;
}

// --------------------------------------------------

// Function: FUN_00449769
// Address: 00449769
DriveInformation * __fastcall FUN_00449769(DriveInformation *param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  iVar2 = __getdrive();
  param_1->initialDriveValue = iVar2;
  param_1->currentDriveValue = iVar2;
  DriveInformation::updateDirectory(param_1);
  uVar3 = 0xffffffff;
  pcVar5 = param_1->currentDirectoryValue;
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
  pcVar6 = param_1->initialDirectoryValue;
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
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004497b5
// Address: 004497b5
undefined4 __fastcall FUN_004497b5(undefined4 *param_1)
{
  return *param_1;
}

// --------------------------------------------------

// Function: FUN_004497c3
// Address: 004497c3
int __fastcall FUN_004497c3(int *param_1)
{
  return *param_1 + 0x40;
}

// --------------------------------------------------

// Function: FUN_004497d6
// Address: 004497d6
int __fastcall FUN_004497d6(int param_1)
{
  return param_1 + 4;
}

// --------------------------------------------------

// Function: FUN_004497e4
// Address: 004497e4
undefined4 __fastcall FUN_004497e4(int param_1)
{
  return *(undefined4 *)(param_1 + 0x104);
}

// --------------------------------------------------

// Function: FUN_004497f7
// Address: 004497f7
int __fastcall FUN_004497f7(int param_1)
{
  return *(int *)(param_1 + 0x104) + 0x40;
}

// --------------------------------------------------

// Function: FUN_0044980a
// Address: 0044980a
int __fastcall FUN_0044980a(int param_1)
{
  return param_1 + 0x108;
}

// --------------------------------------------------

// Function: FUN_00449817
// Address: 00449817
undefined4 __fastcall FUN_00449817(int param_1)
{
  return *(undefined4 *)(param_1 + 0x208);
}

// --------------------------------------------------

// Function: FUN_00449827
// Address: 00449827
undefined4 __thiscall FUN_00449827(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x208 + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_0044983e
// Address: 0044983e
void __fastcall FUN_0044983e(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x208) = 0;
  iVar3 = 1;
  puVar2 = (undefined4 *)(param_1 + 0x20c);
  do {
    iVar1 = __chdrive(iVar3);
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x208) = *(int *)(param_1 + 0x208) + 1;
      *puVar2 = 1;
    }
    else {
      *puVar2 = 0;
    }
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 0x1b);
  __chdrive(*(undefined4 *)(param_1 + 0x104));
  return;
}

// --------------------------------------------------

// Function: FUN_0044989e
// Address: 0044989e
int FUN_0044989e(undefined4 param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_118 [280];
  
  iVar1 = __findfirst(param_1,auStack_118);
  if (iVar1 != -1) {
    iVar3 = 1;
    iVar2 = __findnext(iVar1,auStack_118);
    while (iVar2 != -1) {
      iVar3 = iVar3 + 1;
      iVar2 = __findnext(iVar1,auStack_118);
    }
    return iVar3;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00449906
// Address: 00449906
// [HELPER] s____: "*.*"
int FUN_00449906(uint param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint auStack_118 [70];
  
  iVar1 = __findfirst(s____,auStack_118);
  if (iVar1 == -1) {
    return 0;
  }
  iVar3 = 1;
  iVar2 = __findnext(iVar1,auStack_118);
  while (iVar2 != -1) {
    if ((auStack_118[0] & param_1) != 0) {
      iVar3 = iVar3 + 1;
    }
    iVar2 = __findnext(iVar1,auStack_118);
  }
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_00449985
// Address: 00449985
// [HELPER] s____: "*.*"
int FUN_00449985(undefined4 param_1,uint param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint auStack_118 [5];
  undefined1 auStack_104 [260];
  
  iVar1 = __findfirst(s____,auStack_118);
  if (iVar1 == -1) {
    return 0;
  }
  iVar3 = 1;
  iVar2 = __findnext(iVar1,auStack_118);
  while (iVar2 != -1) {
    if (((auStack_118[0] & param_2) != 0) || (iVar2 = strstr(auStack_104,param_1), iVar2 != 0)) {
      iVar3 = iVar3 + 1;
    }
    iVar2 = __findnext(iVar1,auStack_118);
  }
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_00449a39
// Address: 00449a39
void __fastcall FUN_00449a39(DriveInformation *param_1)
{
  DriveInformation::changeDrive(param_1,param_1->initialDriveValue);
  return;
}

// --------------------------------------------------

// Function: FUN_00449a49
// Address: 00449a49
void __fastcall FUN_00449a49(DriveInformation *param_1)
{
  DriveInformation::changeDirectory(param_1,param_1->initialDirectoryValue);
  return;
}

// --------------------------------------------------

// Function: FUN_00449a5a
// Address: 00449a5a
undefined4 __thiscall FUN_00449a5a(int param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = __chdrive(param_2);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x104) = param_2;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00449a8c
// Address: 00449a8c
undefined4 __thiscall FUN_00449a8c(DriveInformation *param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = __chdir(param_2);
  if (iVar1 == 0) {
    DriveInformation::updateDirectory(param_1);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00449aba
// Address: 00449aba
// [HELPER] s__s_s_s: "%s%s%s"
void __fastcall FUN_00449aba(int param_1)
{
  undefined1 auStack_308 [4];
  undefined1 auStack_304 [256];
  undefined1 auStack_204 [256];
  undefined1 auStack_104 [260];
  
  __getcwd(auStack_104,0x104);
  param_1 = param_1 + 0x108;
  __splitpath(auStack_104,auStack_308,param_1,auStack_204,auStack_304);
  sprintf(param_1,s__s_s_s,param_1,auStack_204,auStack_304);
  return;
}

// --------------------------------------------------

// Function: FUN_00449b2b
// Address: 00449b2b
RGE_Flic_Player * __thiscall FUN_00449b2b(RGE_Flic_Player *param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 uVar2;
  uchar *puVar3;
  int iVar4;
  long *plVar5;
  FlicHead *pFVar6;
  
  iVar1 = __open(param_2,0x8000);
  if (-1 < iVar1) {
    lseek(iVar1,0,2);
    uVar2 = __tell(iVar1);
    puVar3 = (uchar *)calloc(uVar2,1);
    param_1->flic_buffer = puVar3;
    lseek(iVar1,0,0);
    read(iVar1,param_1->flic_buffer,uVar2);
    plVar5 = (long *)param_1->flic_buffer;
    pFVar6 = &param_1->flichead;
    for (iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
      pFVar6->size = *plVar5;
      plVar5 = plVar5 + 1;
      pFVar6 = (FlicHead *)&pFVar6->type;
    }
    param_1->flic_width = (int)(param_1->flichead).width;
    RGE_Flic_Player::start(param_1);
    close(iVar1);
    return param_1;
  }
  param_1->flic_buffer = (uchar *)0x0;
  param_1->flic_handle = -1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00449bd1
// Address: 00449bd1
RGE_Flic_Player * __thiscall FUN_00449bd1(RGE_Flic_Player *param_1,int param_2)
{
  if (-1 < param_2) {
    read(param_2,&param_1->flichead,0x84);
    param_1->flic_width = (int)(param_1->flichead).width;
    param_1->flic_handle = param_2;
    param_1->flic_buffer = (uchar *)0x0;
    RGE_Flic_Player::start(param_1);
    return param_1;
  }
  param_1->flic_buffer = (uchar *)0x0;
  param_1->flic_handle = -1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00449c34
// Address: 00449c34
void __fastcall FUN_00449c34(int *param_1)
{
  if (*param_1 != 0) {
    free(*param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00449de7
// Address: 00449de7
uint __fastcall FUN_00449de7(int param_1)
{
  return (int)*(short *)(param_1 + 0x10) << 0x10 | (int)*(short *)(param_1 + 0x12);
}

// --------------------------------------------------

// Function: FUN_00449dfe
// Address: 00449dfe
undefined4 __fastcall FUN_00449dfe(int param_1)
{
  return *(undefined4 *)(param_1 + 0x18);
}

// --------------------------------------------------

// Function: FUN_00449e04
// Address: 00449e04
undefined2 __fastcall FUN_00449e04(int param_1)
{
  return *(undefined2 *)(param_1 + 0xe);
}

// --------------------------------------------------

// Function: FUN_00449e15
// Address: 00449e15
void __fastcall FUN_00449e15(int *param_1)
{
  int iVar1;
  
  if ((short)param_1[3] == -0x50ef) {
    param_1[0x17] = *param_1 + 0x84;
    param_1[6] = (param_1[6] * 1000) / 0x46;
  }
  else if ((short)param_1[3] == -0x50ee) {
    iVar1 = param_1[0x17];
    param_1[0x17] = iVar1 + *param_1;
    param_1[0x18] = iVar1 + *param_1;
    return;
  }
  param_1[0x18] = param_1[0x17];
  return;
}

// --------------------------------------------------

// Function: FUN_00449e78
// Address: 00449e78
void __fastcall FUN_00449e78(int param_1)
{
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x5c);
  return;
}

// --------------------------------------------------

// Function: FUN_00449e87
// Address: 00449e87
undefined1 __thiscall
FUN_00449e87(RGE_Flic_Player *param_1,TDrawArea *param_2,int param_3,int param_4)
{
  short sVar1;
  short sVar2;
  uchar *puVar3;
  int *piVar4;
  int *piVar5;
  long lVar6;
  int iVar7;
  undefined1 uVar8;
  char *pcVar9;
  int *piStack_4;
  
  piStack_4 = (int *)0x0;
  if (param_1->flic_handle < 0) {
    piVar4 = (int *)(param_1->flichead).oframe2;
    piVar5 = piVar4 + 4;
  }
  else {
    piVar4 = (int *)calloc(1,0x10);
    lseek(param_1->flic_handle,(param_1->flichead).oframe2,0);
    read(param_1->flic_handle,piVar4,0x10);
    piVar5 = (int *)calloc(*piVar4,1);
    read(param_1->flic_handle,piVar5,*piVar4);
    piStack_4 = piVar5;
  }
  sVar1 = (param_1->flichead).width;
  param_1->x1 = param_3;
  param_1->drawarea = param_2;
  sVar2 = (param_1->flichead).height;
  param_1->x2 = sVar1 + param_3;
  param_1->y1 = param_4;
  param_1->y2 = sVar2 + param_4;
  lVar6 = TDrawArea::AlignedWidth(param_2);
  iVar7 = lVar6 * param_2->Orien;
  param_1->drawarea_width = iVar7;
  if (param_2->Orien < 1) {
    param_1->window_buffer =
         param_2->Bits + param_1->x1 + ((param_1->y1 - param_2->Height) + 1) * iVar7;
  }
  else {
    param_1->window_buffer = param_2->Bits + param_1->x1 + iVar7 * param_1->y1;
  }
  iVar7 = 0;
  param_1->save_buffer = param_1->window_buffer;
  if (0 < *(short *)((int)piVar4 + 6)) {
    do {
      param_1->chunk = (char *)((int)piVar5 + 6);
      switch((short)piVar5[1]) {
      case 7:
        RGE_Flic_Player::delta_flc(param_1);
        break;
      case 0xc:
        RGE_Flic_Player::delta_fli(param_1);
        break;
      case 0xd:
        RGE_Flic_Player::black(param_1);
        break;
      case 0xf:
        RGE_Flic_Player::byte_run(param_1);
        break;
      case 0x10:
        RGE_Flic_Player::literal(param_1);
      }
      piVar5 = (int *)((int)piVar5 + *piVar5);
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(short *)((int)piVar4 + 6));
  }
  puVar3 = param_1->flic_buffer;
  pcVar9 = (param_1->flichead).oframe2 + *piVar4;
  (param_1->flichead).oframe2 = pcVar9;
  if ((int)(pcVar9 + -(int)puVar3) < (param_1->flichead).size) {
    uVar8 = 0;
  }
  else {
    piVar5 = (int *)(param_1->flichead).oframe1;
    (param_1->flichead).oframe2 = (char *)piVar5;
    if (puVar3 != (uchar *)0x0) {
      (param_1->flichead).oframe2 = (char *)((int)piVar5 + *piVar5);
    }
    uVar8 = 2;
  }
  if (-1 < param_1->flic_handle) {
    if (piVar4 != (int *)0x0) {
      free(piVar4);
    }
    if (piStack_4 != (int *)0x0) {
      free(piStack_4);
    }
  }
  return uVar8;
}

// --------------------------------------------------

// Function: FUN_0044a05d
// Address: 0044a05d
void FUN_0044a05d(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}

// --------------------------------------------------

// Function: FUN_0044a0f8
// Address: 0044a0f8
void __fastcall FUN_0044a0f8(int param_1)
{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort uVar11;
  int iStack_8;
  int iStack_4;
  
  iStack_4 = (int)**(short **)(param_1 + 0xa0);
  puVar10 = (ushort *)(*(short **)(param_1 + 0xa0) + 1);
  if (0 < iStack_4) {
    do {
      bVar4 = false;
      puVar9 = puVar10;
      do {
        uVar2 = *puVar9;
        uVar11 = 0;
        puVar10 = puVar9 + 1;
        uVar3 = uVar2 >> 0xe;
        if (uVar3 == 0) {
LAB_0044a1a1:
          uVar11 = uVar2;
          bVar4 = true;
        }
        else {
          if (uVar3 == 2) {
            *(char *)(*(int *)(param_1 + 0x98) + -1 + *(int *)(param_1 + 0x94)) = (char)uVar2;
            uVar2 = *puVar10;
            puVar10 = puVar9 + 2;
            goto LAB_0044a1a1;
          }
          if (uVar3 == 3) {
            iVar5 = *(int *)(param_1 + 0x9c) + *(int *)(param_1 + 0x90) * (int)(short)-uVar2;
            *(int *)(param_1 + 0x9c) = iVar5;
            *(int *)(param_1 + 0x98) = iVar5;
          }
        }
        puVar9 = puVar10;
      } while (!bVar4);
      if (0 < (short)uVar11) {
        iStack_8 = (int)(short)uVar11;
        do {
          pcVar8 = (char *)(*(int *)(param_1 + 0x98) + (int)(char)*puVar10);
          *(char **)(param_1 + 0x98) = pcVar8;
          cVar1 = *(char *)((int)puVar10 + 1);
          puVar9 = puVar10 + 1;
          if (cVar1 < '\x01') {
            uVar6 = cVar1 * -2;
            if (1 < (int)uVar6) {
              uVar7 = uVar6 >> 1;
              do {
                uVar6 = uVar6 - 2;
                **(ushort **)(param_1 + 0x98) = *puVar9;
                uVar7 = uVar7 - 1;
                *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 2;
              } while (uVar7 != 0);
            }
            if (uVar6 == 1) {
              **(char **)(param_1 + 0x98) = (char)*puVar9;
              *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
            }
            puVar10 = puVar10 + 2;
          }
          else {
            uVar7 = cVar1 * 2;
            puVar10 = puVar9;
            for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *(undefined4 *)pcVar8 = *(undefined4 *)puVar10;
              puVar10 = puVar10 + 2;
              pcVar8 = pcVar8 + 4;
            }
            for (uVar6 = uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pcVar8 = (char)*puVar10;
              puVar10 = (ushort *)((int)puVar10 + 1);
              pcVar8 = pcVar8 + 1;
            }
            puVar10 = puVar9 + cVar1;
            *(uint *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + uVar7;
          }
          iStack_8 = iStack_8 + -1;
        } while (iStack_8 != 0);
      }
      iVar5 = *(int *)(param_1 + 0x9c) + *(int *)(param_1 + 0x90);
      *(int *)(param_1 + 0x98) = iVar5;
      iStack_4 = iStack_4 + -1;
      *(int *)(param_1 + 0x9c) = iVar5;
    } while (iStack_4 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044a29c
// Address: 0044a29c
void __fastcall FUN_0044a29c(int param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int iStack_c;
  int iStack_8;
  
  iStack_8 = **(int **)(param_1 + 0xa0);
  piVar5 = *(int **)(param_1 + 0xa0) + 2;
  if (0 < iStack_8) {
    do {
      iStack_c = (int)(char)*piVar5;
      iVar4 = 0;
      piVar5 = (int *)((int)piVar5 + 1);
      if (0 < iStack_c) {
        do {
          iVar4 = iVar4 + (char)*piVar5;
          cVar1 = *(char *)((int)piVar5 + 1);
          pcVar6 = (char *)((int)piVar5 + 2);
          if (cVar1 < '\0') {
            uVar3 = (uint)-cVar1;
            cVar1 = *pcVar6;
            pcVar6 = (char *)(iVar4 + *(int *)(param_1 + 0x98));
            for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
              *(uint *)pcVar6 = CONCAT22(CONCAT11(cVar1,cVar1),CONCAT11(cVar1,cVar1));
              pcVar6 = pcVar6 + 4;
            }
            piVar5 = (int *)((int)piVar5 + 3);
            for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
              *pcVar6 = cVar1;
              pcVar6 = pcVar6 + 1;
            }
          }
          else {
            uVar3 = (uint)cVar1;
            pcVar7 = pcVar6;
            pcVar8 = (char *)(iVar4 + *(int *)(param_1 + 0x98));
            for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
              *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
              pcVar7 = pcVar7 + 4;
              pcVar8 = pcVar8 + 4;
            }
            piVar5 = (int *)(pcVar6 + uVar3);
            for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
              *pcVar8 = *pcVar7;
              pcVar7 = pcVar7 + 1;
              pcVar8 = pcVar8 + 1;
            }
          }
          iVar4 = iVar4 + uVar3;
          iStack_c = iStack_c + -1;
        } while (iStack_c != 0);
      }
      iStack_8 = iStack_8 + -1;
      *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + *(int *)(param_1 + 0x90);
    } while (iStack_8 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044a388
// Address: 0044a388
void __fastcall FUN_0044a388(int param_1)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0xb8)) {
    do {
      uVar2 = *(uint *)(param_1 + 0xb4);
      puVar4 = *(undefined4 **)(param_1 + 0x98);
      for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      iVar3 = iVar3 + 1;
      *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + *(int *)(param_1 + 0x90);
    } while (iVar3 < *(int *)(param_1 + 0xb8));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044a4b9
// Address: 0044a4b9
void __fastcall FUN_0044a4b9(int param_1,char *param_2)
{
  int *piVar1;
  char cVar2;
  char cVar4;
  int in_EAX;
  char *pcVar3;
  char cVar5;
  char cVar6;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar12;
  int unaff_EBX;
  int iVar13;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  char *pcVar7;
  char *pcVar11;
  char cVar14;
  
  cVar5 = (char)param_1;
  *(char *)(in_EAX + -0x5a) = *(char *)(in_EAX + -0x5a) + cVar5;
  *(char *)(unaff_EDI + -0x59) = *(char *)(unaff_EDI + -0x59) + cVar5;
  cVar10 = (char)unaff_EBX;
  *(char *)(unaff_ESI + 0x44) = *(char *)(unaff_ESI + 0x44) + cVar10;
  cVar2 = (char)in_EAX;
  *(char *)(unaff_EBP + -0x1affbb57) = *(char *)(unaff_EBP + -0x1affbb57) + cVar2;
  param_2[-0x58] = param_2[-0x58] + cVar2;
  cVar4 = (char)((uint)in_EAX >> 8);
  param_2[0x20044a7] = param_2[0x20044a7] + cVar4;
  param_2[-0x55] = param_2[-0x55] + cVar5;
  cVar8 = (char)((uint)param_1 >> 8);
  *(char *)(unaff_EBP + 0x130044aa) = *(char *)(unaff_EBP + 0x130044aa) + cVar8;
  *(char *)(unaff_EDI + 5) = cVar2;
  cVar14 = (char)((uint)unaff_EBX >> 8);
  *(char *)(param_1 + -0x57) = *(char *)(param_1 + -0x57) + cVar14;
  cVar5 = cVar5 + cVar10;
  cVar12 = (char)((uint)param_2 >> 8);
  *(char *)(unaff_ESI + 4) = *(char *)(unaff_ESI + 4) + cVar12;
  cVar9 = (char)param_2;
  *(char *)(unaff_ESI + -0x9ffbb55) = *(char *)(unaff_ESI + -0x9ffbb55) + cVar9;
  *(char *)(unaff_ESI + 5) = *(char *)(unaff_ESI + 5) + cVar14;
  *(int *)(unaff_EDI + 7) = in_EAX;
  pcVar3 = (char *)(CONCAT31((int3)((uint)param_1 >> 8),cVar5) + 0x70044aa);
  *pcVar3 = *pcVar3 + cVar4;
  *(char *)(unaff_EDI + 0xb) = cVar2;
  *(char *)(unaff_EBP + -0x57) = *(char *)(unaff_EBP + -0x57) + cVar8;
  cVar8 = cVar8 + cVar5;
  *param_2 = *param_2 + cVar8;
  param_2[-0x15ffbb59] = param_2[-0x15ffbb59] + cVar5;
  piVar1 = (int *)(unaff_EDI + 0xd);
  *(char *)piVar1 = *(char *)piVar1 + cVar8;
  *piVar1 = in_EAX;
  param_2[-0x7ffbb56] = param_2[-0x7ffbb56] + cVar9;
  *(char *)(unaff_ESI + 0x1b0044ae) = *(char *)(unaff_ESI + 0x1b0044ae) + cVar14;
  *(char *)(unaff_EBX + -0x59) = *(char *)(unaff_EBX + -0x59) + cVar14;
  cVar10 = cVar10 * '\x02';
  pcVar3 = (char *)CONCAT31((int3)((uint)unaff_EBX >> 8),cVar10);
  *pcVar3 = *pcVar3 + cVar4;
  *(int *)(unaff_EDI + 0x12) = in_EAX;
  *(char *)(unaff_ESI + -0x13ffbb4f) = *(char *)(unaff_ESI + -0x13ffbb4f) + cVar2;
  param_2[0xf0044a8] = param_2[0xf0044a8] + cVar12;
  *(char *)(unaff_EDI + -0x43) = *(char *)(unaff_EDI + -0x43) + cVar8;
  cVar14 = cVar14 + cVar5;
  iVar13 = CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(cVar14,cVar10));
  pcVar3 = (char *)(iVar13 + unaff_EBP * 4);
  *pcVar3 = *pcVar3 + cVar9;
  *(char *)(unaff_EDI + -0x3f) = *(char *)(unaff_EDI + -0x3f) + cVar12;
  cVar8 = cVar8 + cVar10;
  *(char *)(iVar13 + 0x44a8) = *(char *)(iVar13 + 0x44a8) + cVar4;
  *(char *)(in_EAX + -0x59) = *(char *)(in_EAX + -0x59) + cVar4;
  cVar2 = cVar2 * '\x02';
  pcVar3 = (char *)CONCAT31((int3)((uint)in_EAX >> 8),cVar2);
  *pcVar3 = *pcVar3 + cVar5;
  *(char **)(unaff_EDI + 0x18) = pcVar3;
  *(char *)(iVar13 + -0x56) = *(char *)(iVar13 + -0x56) + cVar8;
  *(char *)(unaff_EDI + -0xbffbb3c) = *(char *)(unaff_EDI + -0xbffbb3c) + cVar9;
  *(char *)(unaff_EDI + 100) = *(char *)(unaff_EDI + 100) + cVar9;
  *(char *)(unaff_ESI + -0x5506ffaf) = *(char *)(unaff_ESI + -0x5506ffaf) + cVar12;
  param_2[unaff_EBP * 4 + 0x44] = param_2[unaff_EBP * 4 + 0x44] + cVar10;
  pcVar3[-0x1affbb58] = pcVar3[-0x1affbb58] + cVar5 + cVar9;
  *(char *)(unaff_EBP + -0x59) = *(char *)(unaff_EBP + -0x59) + cVar2;
  *(char *)(unaff_EBP + -0x12ffbb5a) = *(char *)(unaff_EBP + -0x12ffbb5a) + cVar4;
  *(char *)(unaff_EDI + 0x24) = cVar2;
  pcVar3[-0x56] = pcVar3[-0x56] + cVar9 + cVar2;
  *(char *)(unaff_ESI + 0x1c0044ba) = *(char *)(unaff_ESI + 0x1c0044ba) + cVar12;
  cVar6 = cVar5 + cVar9 + cVar10;
  pcVar7 = (char *)CONCAT31((int3)(CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar8,cVar5)) >>
                                  8),cVar6);
  *pcVar7 = *pcVar7 + cVar14;
  pcVar7[-0x21ffbb5a] = pcVar7[-0x21ffbb5a] + cVar10;
  *(char *)(unaff_EDI + 0x2d) = cVar2;
  pcVar7[-0x56] = pcVar7[-0x56] + cVar2;
  *(char *)(unaff_EDI + 0xd0044d7) = *(char *)(unaff_EDI + 0xd0044d7) + cVar4;
  cVar10 = cVar9 + cVar2 + cVar6;
  pcVar11 = (char *)CONCAT31((int3)((uint)param_2 >> 8),cVar10);
  *pcVar11 = *pcVar11 + cVar8;
  pcVar11[-0x2dffbb5a] = pcVar11[-0x2dffbb5a] + cVar6;
  *(char *)(unaff_EDI + 0x36) = cVar2;
  DAT_9b0044aa = DAT_9b0044aa + cVar12;
  pcVar7[-0x58] = pcVar7[-0x58] + cVar4;
  *(char *)(unaff_ESI + 0x1e0044c8) = *(char *)(unaff_ESI + 0x1e0044c8) + cVar14;
  *(char *)(unaff_ESI + -0x35) = *(char *)(unaff_ESI + -0x35) + cVar14;
  *(char *)(unaff_EDI + 0x3b) = cVar2;
  *(char *)(unaff_ESI + 0x25) = *(char *)(unaff_ESI + 0x25) + cVar4;
  *(char *)(unaff_EDI + 0x3c) = cVar2;
  pcVar7[unaff_EBP * 4 + -0x570dffbc] = pcVar7[unaff_EBP * 4 + -0x570dffbc] + cVar6;
  pcVar11[-0x58] = pcVar11[-0x58] + cVar10;
  *(char *)(unaff_EDI + 0xf0044e4) = *(char *)(unaff_EDI + 0xf0044e4) + cVar8;
  *(char *)(unaff_EDI + -0x19) = *(char *)(unaff_EDI + -0x19) + cVar8;
  *pcVar3 = *pcVar3 + cVar4;
  *pcVar3 = *pcVar3 + cVar2;
  *(undefined1 *)(unaff_EDI + 0x40) = *(undefined1 *)(unaff_ESI + 0x28);
  return;
}

// --------------------------------------------------

// Function: FUN_0044a64f
// Address: 0044a64f
void FUN_0044a64f(void)
{
  undefined1 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined1 *)(unaff_ESI + -1);
  *(undefined1 *)(unaff_EDI + -2) = *(undefined1 *)(unaff_ESI + -2);
  *(undefined1 *)(unaff_EDI + -1) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0044a65c
// Address: 0044a65c
void FUN_0044a65c(void)
{
  undefined1 uVar1;
  undefined1 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined1 *)(unaff_ESI + -2);
  uVar2 = *(undefined1 *)(unaff_ESI + -1);
  *(undefined1 *)(unaff_EDI + -3) = *(undefined1 *)(unaff_ESI + -3);
  *(undefined1 *)(unaff_EDI + -2) = uVar1;
  *(undefined1 *)(unaff_EDI + -1) = uVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044a66f
// Address: 0044a66f
void FUN_0044a66f(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x5c);
  *(undefined4 *)(unaff_EDI + -0x60) = *(undefined4 *)(unaff_ESI + -0x60);
  *(undefined4 *)(unaff_EDI + -0x5c) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x54);
  *(undefined4 *)(unaff_EDI + -0x58) = *(undefined4 *)(unaff_ESI + -0x58);
  *(undefined4 *)(unaff_EDI + -0x54) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x4c);
  *(undefined4 *)(unaff_EDI + -0x50) = *(undefined4 *)(unaff_ESI + -0x50);
  *(undefined4 *)(unaff_EDI + -0x4c) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x44);
  *(undefined4 *)(unaff_EDI + -0x48) = *(undefined4 *)(unaff_ESI + -0x48);
  *(undefined4 *)(unaff_EDI + -0x44) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x3c);
  *(undefined4 *)(unaff_EDI + -0x40) = *(undefined4 *)(unaff_ESI + -0x40);
  *(undefined4 *)(unaff_EDI + -0x3c) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x34);
  *(undefined4 *)(unaff_EDI + -0x38) = *(undefined4 *)(unaff_ESI + -0x38);
  *(undefined4 *)(unaff_EDI + -0x34) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x2c);
  *(undefined4 *)(unaff_EDI + -0x30) = *(undefined4 *)(unaff_ESI + -0x30);
  *(undefined4 *)(unaff_EDI + -0x2c) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x24);
  *(undefined4 *)(unaff_EDI + -0x28) = *(undefined4 *)(unaff_ESI + -0x28);
  *(undefined4 *)(unaff_EDI + -0x24) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x1c);
  *(undefined4 *)(unaff_EDI + -0x20) = *(undefined4 *)(unaff_ESI + -0x20);
  *(undefined4 *)(unaff_EDI + -0x1c) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x14);
  *(undefined4 *)(unaff_EDI + -0x18) = *(undefined4 *)(unaff_ESI + -0x18);
  *(undefined4 *)(unaff_EDI + -0x14) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0xc);
  *(undefined4 *)(unaff_EDI + -0x10) = *(undefined4 *)(unaff_ESI + -0x10);
  *(undefined4 *)(unaff_EDI + -0xc) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -4);
  *(undefined4 *)(unaff_EDI + -8) = *(undefined4 *)(unaff_ESI + -8);
  *(undefined4 *)(unaff_EDI + -4) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0044a70f
// Address: 0044a70f
void FUN_0044a70f(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x5b);
  *(undefined4 *)(unaff_EDI + -0x5f) = *(undefined4 *)(unaff_ESI + -0x5f);
  *(undefined4 *)(unaff_EDI + -0x5b) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x53);
  *(undefined4 *)(unaff_EDI + -0x57) = *(undefined4 *)(unaff_ESI + -0x57);
  *(undefined4 *)(unaff_EDI + -0x53) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x4b);
  *(undefined4 *)(unaff_EDI + -0x4f) = *(undefined4 *)(unaff_ESI + -0x4f);
  *(undefined4 *)(unaff_EDI + -0x4b) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x43);
  *(undefined4 *)(unaff_EDI + -0x47) = *(undefined4 *)(unaff_ESI + -0x47);
  *(undefined4 *)(unaff_EDI + -0x43) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x3b);
  *(undefined4 *)(unaff_EDI + -0x3f) = *(undefined4 *)(unaff_ESI + -0x3f);
  *(undefined4 *)(unaff_EDI + -0x3b) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x33);
  *(undefined4 *)(unaff_EDI + -0x37) = *(undefined4 *)(unaff_ESI + -0x37);
  *(undefined4 *)(unaff_EDI + -0x33) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x2b);
  *(undefined4 *)(unaff_EDI + -0x2f) = *(undefined4 *)(unaff_ESI + -0x2f);
  *(undefined4 *)(unaff_EDI + -0x2b) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x23);
  *(undefined4 *)(unaff_EDI + -0x27) = *(undefined4 *)(unaff_ESI + -0x27);
  *(undefined4 *)(unaff_EDI + -0x23) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x1b);
  *(undefined4 *)(unaff_EDI + -0x1f) = *(undefined4 *)(unaff_ESI + -0x1f);
  *(undefined4 *)(unaff_EDI + -0x1b) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x13);
  *(undefined4 *)(unaff_EDI + -0x17) = *(undefined4 *)(unaff_ESI + -0x17);
  *(undefined4 *)(unaff_EDI + -0x13) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0xb);
  *(undefined4 *)(unaff_EDI + -0xf) = *(undefined4 *)(unaff_ESI + -0xf);
  *(undefined4 *)(unaff_EDI + -0xb) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -4);
  *(undefined4 *)(unaff_EDI + -7) = *(undefined4 *)(unaff_ESI + -7);
  *(undefined4 *)(unaff_EDI + -4) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0044a7af
// Address: 0044a7af
void FUN_0044a7af(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x5a);
  *(undefined4 *)(unaff_EDI + -0x5e) = *(undefined4 *)(unaff_ESI + -0x5e);
  *(undefined4 *)(unaff_EDI + -0x5a) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x52);
  *(undefined4 *)(unaff_EDI + -0x56) = *(undefined4 *)(unaff_ESI + -0x56);
  *(undefined4 *)(unaff_EDI + -0x52) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x4a);
  *(undefined4 *)(unaff_EDI + -0x4e) = *(undefined4 *)(unaff_ESI + -0x4e);
  *(undefined4 *)(unaff_EDI + -0x4a) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x42);
  *(undefined4 *)(unaff_EDI + -0x46) = *(undefined4 *)(unaff_ESI + -0x46);
  *(undefined4 *)(unaff_EDI + -0x42) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x3a);
  *(undefined4 *)(unaff_EDI + -0x3e) = *(undefined4 *)(unaff_ESI + -0x3e);
  *(undefined4 *)(unaff_EDI + -0x3a) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x32);
  *(undefined4 *)(unaff_EDI + -0x36) = *(undefined4 *)(unaff_ESI + -0x36);
  *(undefined4 *)(unaff_EDI + -0x32) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x2a);
  *(undefined4 *)(unaff_EDI + -0x2e) = *(undefined4 *)(unaff_ESI + -0x2e);
  *(undefined4 *)(unaff_EDI + -0x2a) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x22);
  *(undefined4 *)(unaff_EDI + -0x26) = *(undefined4 *)(unaff_ESI + -0x26);
  *(undefined4 *)(unaff_EDI + -0x22) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x1a);
  *(undefined4 *)(unaff_EDI + -0x1e) = *(undefined4 *)(unaff_ESI + -0x1e);
  *(undefined4 *)(unaff_EDI + -0x1a) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x12);
  *(undefined4 *)(unaff_EDI + -0x16) = *(undefined4 *)(unaff_ESI + -0x16);
  *(undefined4 *)(unaff_EDI + -0x12) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -10);
  *(undefined4 *)(unaff_EDI + -0xe) = *(undefined4 *)(unaff_ESI + -0xe);
  *(undefined4 *)(unaff_EDI + -10) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -2);
  *(undefined4 *)(unaff_EDI + -6) = *(undefined4 *)(unaff_ESI + -6);
  *(char *)(unaff_EDI + -2) = (char)uVar1;
  *(char *)(unaff_EDI + -1) = (char)((uint)uVar1 >> 8);
  return;
}

// --------------------------------------------------

// Function: FUN_0044a852
// Address: 0044a852
void FUN_0044a852(void)
{
  undefined1 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar2 = *(undefined4 *)(unaff_ESI + -0x59);
  *(undefined4 *)(unaff_EDI + -0x5d) = *(undefined4 *)(unaff_ESI + -0x5d);
  *(undefined4 *)(unaff_EDI + -0x59) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x51);
  *(undefined4 *)(unaff_EDI + -0x55) = *(undefined4 *)(unaff_ESI + -0x55);
  *(undefined4 *)(unaff_EDI + -0x51) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x49);
  *(undefined4 *)(unaff_EDI + -0x4d) = *(undefined4 *)(unaff_ESI + -0x4d);
  *(undefined4 *)(unaff_EDI + -0x49) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x41);
  *(undefined4 *)(unaff_EDI + -0x45) = *(undefined4 *)(unaff_ESI + -0x45);
  *(undefined4 *)(unaff_EDI + -0x41) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x39);
  *(undefined4 *)(unaff_EDI + -0x3d) = *(undefined4 *)(unaff_ESI + -0x3d);
  *(undefined4 *)(unaff_EDI + -0x39) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x31);
  *(undefined4 *)(unaff_EDI + -0x35) = *(undefined4 *)(unaff_ESI + -0x35);
  *(undefined4 *)(unaff_EDI + -0x31) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x29);
  *(undefined4 *)(unaff_EDI + -0x2d) = *(undefined4 *)(unaff_ESI + -0x2d);
  *(undefined4 *)(unaff_EDI + -0x29) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x21);
  *(undefined4 *)(unaff_EDI + -0x25) = *(undefined4 *)(unaff_ESI + -0x25);
  *(undefined4 *)(unaff_EDI + -0x21) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x19);
  *(undefined4 *)(unaff_EDI + -0x1d) = *(undefined4 *)(unaff_ESI + -0x1d);
  *(undefined4 *)(unaff_EDI + -0x19) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x11);
  *(undefined4 *)(unaff_EDI + -0x15) = *(undefined4 *)(unaff_ESI + -0x15);
  *(undefined4 *)(unaff_EDI + -0x11) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -9);
  *(undefined4 *)(unaff_EDI + -0xd) = *(undefined4 *)(unaff_ESI + -0xd);
  *(undefined4 *)(unaff_EDI + -9) = uVar2;
  uVar1 = *(undefined1 *)(unaff_ESI + -1);
  *(undefined4 *)(unaff_EDI + -5) = *(undefined4 *)(unaff_ESI + -5);
  *(undefined1 *)(unaff_EDI + -1) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0044a8f2
// Address: 0044a8f2
void FUN_0044a8f2(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x58);
  *(undefined4 *)(unaff_EDI + -0x5c) = *(undefined4 *)(unaff_ESI + -0x5c);
  *(undefined4 *)(unaff_EDI + -0x58) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x50);
  *(undefined4 *)(unaff_EDI + -0x54) = *(undefined4 *)(unaff_ESI + -0x54);
  *(undefined4 *)(unaff_EDI + -0x50) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x48);
  *(undefined4 *)(unaff_EDI + -0x4c) = *(undefined4 *)(unaff_ESI + -0x4c);
  *(undefined4 *)(unaff_EDI + -0x48) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x40);
  *(undefined4 *)(unaff_EDI + -0x44) = *(undefined4 *)(unaff_ESI + -0x44);
  *(undefined4 *)(unaff_EDI + -0x40) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x38);
  *(undefined4 *)(unaff_EDI + -0x3c) = *(undefined4 *)(unaff_ESI + -0x3c);
  *(undefined4 *)(unaff_EDI + -0x38) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x30);
  *(undefined4 *)(unaff_EDI + -0x34) = *(undefined4 *)(unaff_ESI + -0x34);
  *(undefined4 *)(unaff_EDI + -0x30) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x28);
  *(undefined4 *)(unaff_EDI + -0x2c) = *(undefined4 *)(unaff_ESI + -0x2c);
  *(undefined4 *)(unaff_EDI + -0x28) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x20);
  *(undefined4 *)(unaff_EDI + -0x24) = *(undefined4 *)(unaff_ESI + -0x24);
  *(undefined4 *)(unaff_EDI + -0x20) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x18);
  *(undefined4 *)(unaff_EDI + -0x1c) = *(undefined4 *)(unaff_ESI + -0x1c);
  *(undefined4 *)(unaff_EDI + -0x18) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x10);
  *(undefined4 *)(unaff_EDI + -0x14) = *(undefined4 *)(unaff_ESI + -0x14);
  *(undefined4 *)(unaff_EDI + -0x10) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -8);
  *(undefined4 *)(unaff_EDI + -0xc) = *(undefined4 *)(unaff_ESI + -0xc);
  *(undefined4 *)(unaff_EDI + -8) = uVar1;
  *(undefined4 *)(unaff_EDI + -4) = *(undefined4 *)(unaff_ESI + -4);
  return;
}

// --------------------------------------------------

// Function: FUN_0044a98c
// Address: 0044a98c
void FUN_0044a98c(void)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x57);
  *(undefined4 *)(unaff_EDI + -0x5b) = *(undefined4 *)(unaff_ESI + -0x5b);
  *(undefined4 *)(unaff_EDI + -0x57) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x4f);
  *(undefined4 *)(unaff_EDI + -0x53) = *(undefined4 *)(unaff_ESI + -0x53);
  *(undefined4 *)(unaff_EDI + -0x4f) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x47);
  *(undefined4 *)(unaff_EDI + -0x4b) = *(undefined4 *)(unaff_ESI + -0x4b);
  *(undefined4 *)(unaff_EDI + -0x47) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x3f);
  *(undefined4 *)(unaff_EDI + -0x43) = *(undefined4 *)(unaff_ESI + -0x43);
  *(undefined4 *)(unaff_EDI + -0x3f) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x37);
  *(undefined4 *)(unaff_EDI + -0x3b) = *(undefined4 *)(unaff_ESI + -0x3b);
  *(undefined4 *)(unaff_EDI + -0x37) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x2f);
  *(undefined4 *)(unaff_EDI + -0x33) = *(undefined4 *)(unaff_ESI + -0x33);
  *(undefined4 *)(unaff_EDI + -0x2f) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x27);
  *(undefined4 *)(unaff_EDI + -0x2b) = *(undefined4 *)(unaff_ESI + -0x2b);
  *(undefined4 *)(unaff_EDI + -0x27) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x1f);
  *(undefined4 *)(unaff_EDI + -0x23) = *(undefined4 *)(unaff_ESI + -0x23);
  *(undefined4 *)(unaff_EDI + -0x1f) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x17);
  *(undefined4 *)(unaff_EDI + -0x1b) = *(undefined4 *)(unaff_ESI + -0x1b);
  *(undefined4 *)(unaff_EDI + -0x17) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0xf);
  *(undefined4 *)(unaff_EDI + -0x13) = *(undefined4 *)(unaff_ESI + -0x13);
  *(undefined4 *)(unaff_EDI + -0xf) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -7);
  uVar2 = *(undefined4 *)(unaff_ESI + -4);
  *(undefined4 *)(unaff_EDI + -0xb) = *(undefined4 *)(unaff_ESI + -0xb);
  *(undefined4 *)(unaff_EDI + -7) = uVar1;
  *(undefined4 *)(unaff_EDI + -4) = uVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044aa26
// Address: 0044aa26
void FUN_0044aa26(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x56);
  *(undefined4 *)(unaff_EDI + -0x5a) = *(undefined4 *)(unaff_ESI + -0x5a);
  *(undefined4 *)(unaff_EDI + -0x56) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x4e);
  *(undefined4 *)(unaff_EDI + -0x52) = *(undefined4 *)(unaff_ESI + -0x52);
  *(undefined4 *)(unaff_EDI + -0x4e) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x46);
  *(undefined4 *)(unaff_EDI + -0x4a) = *(undefined4 *)(unaff_ESI + -0x4a);
  *(undefined4 *)(unaff_EDI + -0x46) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x3e);
  *(undefined4 *)(unaff_EDI + -0x42) = *(undefined4 *)(unaff_ESI + -0x42);
  *(undefined4 *)(unaff_EDI + -0x3e) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x36);
  *(undefined4 *)(unaff_EDI + -0x3a) = *(undefined4 *)(unaff_ESI + -0x3a);
  *(undefined4 *)(unaff_EDI + -0x36) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x2e);
  *(undefined4 *)(unaff_EDI + -0x32) = *(undefined4 *)(unaff_ESI + -0x32);
  *(undefined4 *)(unaff_EDI + -0x2e) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x26);
  *(undefined4 *)(unaff_EDI + -0x2a) = *(undefined4 *)(unaff_ESI + -0x2a);
  *(undefined4 *)(unaff_EDI + -0x26) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x1e);
  *(undefined4 *)(unaff_EDI + -0x22) = *(undefined4 *)(unaff_ESI + -0x22);
  *(undefined4 *)(unaff_EDI + -0x1e) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x16);
  *(undefined4 *)(unaff_EDI + -0x1a) = *(undefined4 *)(unaff_ESI + -0x1a);
  *(undefined4 *)(unaff_EDI + -0x16) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0xe);
  *(undefined4 *)(unaff_EDI + -0x12) = *(undefined4 *)(unaff_ESI + -0x12);
  *(undefined4 *)(unaff_EDI + -0xe) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -6);
  *(undefined4 *)(unaff_EDI + -10) = *(undefined4 *)(unaff_ESI + -10);
  *(undefined4 *)(unaff_EDI + -6) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -2);
  *(char *)(unaff_EDI + -2) = (char)uVar1;
  *(char *)(unaff_EDI + -1) = (char)((uint)uVar1 >> 8);
  return;
}

// --------------------------------------------------

// Function: FUN_0044aac3
// Address: 0044aac3
void FUN_0044aac3(void)
{
  undefined1 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar2 = *(undefined4 *)(unaff_ESI + -0x55);
  *(undefined4 *)(unaff_EDI + -0x59) = *(undefined4 *)(unaff_ESI + -0x59);
  *(undefined4 *)(unaff_EDI + -0x55) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x4d);
  *(undefined4 *)(unaff_EDI + -0x51) = *(undefined4 *)(unaff_ESI + -0x51);
  *(undefined4 *)(unaff_EDI + -0x4d) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x45);
  *(undefined4 *)(unaff_EDI + -0x49) = *(undefined4 *)(unaff_ESI + -0x49);
  *(undefined4 *)(unaff_EDI + -0x45) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x3d);
  *(undefined4 *)(unaff_EDI + -0x41) = *(undefined4 *)(unaff_ESI + -0x41);
  *(undefined4 *)(unaff_EDI + -0x3d) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x35);
  *(undefined4 *)(unaff_EDI + -0x39) = *(undefined4 *)(unaff_ESI + -0x39);
  *(undefined4 *)(unaff_EDI + -0x35) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x2d);
  *(undefined4 *)(unaff_EDI + -0x31) = *(undefined4 *)(unaff_ESI + -0x31);
  *(undefined4 *)(unaff_EDI + -0x2d) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x25);
  *(undefined4 *)(unaff_EDI + -0x29) = *(undefined4 *)(unaff_ESI + -0x29);
  *(undefined4 *)(unaff_EDI + -0x25) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x1d);
  *(undefined4 *)(unaff_EDI + -0x21) = *(undefined4 *)(unaff_ESI + -0x21);
  *(undefined4 *)(unaff_EDI + -0x1d) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x15);
  *(undefined4 *)(unaff_EDI + -0x19) = *(undefined4 *)(unaff_ESI + -0x19);
  *(undefined4 *)(unaff_EDI + -0x15) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0xd);
  *(undefined4 *)(unaff_EDI + -0x11) = *(undefined4 *)(unaff_ESI + -0x11);
  *(undefined4 *)(unaff_EDI + -0xd) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -5);
  uVar1 = *(undefined1 *)(unaff_ESI + -1);
  *(undefined4 *)(unaff_EDI + -9) = *(undefined4 *)(unaff_ESI + -9);
  *(undefined4 *)(unaff_EDI + -5) = uVar2;
  *(undefined1 *)(unaff_EDI + -1) = uVar1;
  return;
}

// --------------------------------------------------

// Function: _x_StandardMemCopy
// Address: 0044ab5d
void __fastcall _x_StandardMemCopy(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *unaff_ESI;
  undefined4 *puVar4;
  undefined4 *unaff_EDI;
  undefined4 *puVar5;
  
  uVar2 = -(int)unaff_EDI & 3;
  *unaff_EDI = *unaff_ESI;
  uVar1 = param_1 - uVar2 & 3;
  puVar4 = (undefined4 *)((int)unaff_ESI + uVar2);
  puVar5 = (undefined4 *)((int)unaff_EDI + uVar2);
  for (uVar3 = param_1 - uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)((uVar1 - 4) + (int)puVar5) = *(undefined4 *)((uVar1 - 4) + (int)puVar4);
  return;
}

// --------------------------------------------------

// Function: FUN_0044ac42
// Address: 0044ac42
PointMaker * __fastcall FUN_0044ac42(PointMaker *param_1)
{
  param_1->ProbArray = (char *)0x0;
  param_1->PlacementArray = (char *)0x0;
  PointMaker::SetDefaultValues(param_1);
  PointMaker::MakeArrays(param_1);
  PointMaker::CreateMasks(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044ac78
// Address: 0044ac78
void __fastcall FUN_0044ac78(PointMaker *param_1)
{
  PointMaker::DeleteArrays(param_1);
  PointMaker::SetDefaultValues(param_1);
  param_1->ProbArray = (char *)0x0;
  param_1->PlacementArray = (char *)0x0;
  PointMaker::DeleteMasks(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0044aca6
// Address: 0044aca6
void __fastcall FUN_0044aca6(int param_1)
{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uStack_74;
  undefined1 uStack_70;
  undefined1 uStack_6f;
  undefined1 uStack_6e;
  undefined1 uStack_6d;
  undefined1 uStack_6c;
  undefined1 uStack_6b;
  undefined1 uStack_6a;
  undefined1 uStack_69;
  undefined1 uStack_68;
  undefined1 uStack_67;
  undefined1 uStack_66;
  undefined1 uStack_65;
  undefined1 uStack_64;
  undefined1 uStack_63;
  undefined1 uStack_62;
  undefined1 uStack_61;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  undefined1 uStack_5c;
  undefined4 uStack_58;
  undefined1 uStack_54;
  undefined1 uStack_53;
  undefined1 uStack_52;
  undefined1 uStack_51;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  undefined1 uStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined1 uStack_40;
  undefined1 uStack_3f;
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined4 uStack_34;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  
  pvVar1 = operator_new(0x10);
  *(void **)(param_1 + 0xfa8) = pvVar1;
  pvVar1 = operator_new(0x19);
  *(void **)(param_1 + 0xfac) = pvVar1;
  pvVar1 = operator_new(0x24);
  *(void **)(param_1 + 0xfb0) = pvVar1;
  pvVar1 = operator_new(0x31);
  *(void **)(param_1 + 0xfb4) = pvVar1;
  uStack_74._0_1_ = 0;
  uStack_74._1_1_ = 0;
  uStack_74._2_1_ = 0;
  uStack_74._3_1_ = 0;
  uStack_70 = 0;
  uStack_6f = 0;
  uStack_6e = 1;
  uStack_6d = 1;
  uStack_6c = 1;
  uStack_6b = 0;
  uStack_6a = 0;
  uStack_69 = 1;
  uStack_68 = 2;
  uStack_67 = 1;
  uStack_66 = 0;
  uStack_65 = 0;
  uStack_64 = 1;
  uStack_63 = 1;
  uStack_62 = 1;
  uStack_61 = 0;
  uStack_60 = 0;
  uStack_5f = 0;
  uStack_5e = 0;
  uStack_5d = 0;
  uStack_5c = 0;
  uStack_58._0_1_ = 0;
  uStack_58._1_1_ = 0;
  uStack_58._2_1_ = 0;
  uStack_58._3_1_ = 0;
  uStack_54 = 0;
  uStack_53 = 0;
  uStack_52 = 0;
  uStack_51 = 1;
  uStack_50 = 1;
  uStack_4f = 1;
  uStack_4e = 1;
  uStack_4d = 0;
  uStack_4c = 0;
  uStack_4b = 1;
  uStack_4a = 2;
  uStack_49 = 2;
  uStack_48 = 1;
  uStack_47 = 0;
  uStack_46 = 0;
  uStack_41 = 0;
  uStack_40 = 0;
  uStack_3b = 0;
  uStack_3a = 0;
  uStack_39 = 0;
  uStack_38 = 0;
  uStack_37 = 0;
  uStack_36 = 0;
  uStack_35 = 0;
  uStack_34._0_1_ = 0;
  uStack_34._1_1_ = 0;
  uStack_34._2_1_ = 0;
  uStack_34._3_1_ = 0;
  uStack_30 = 0;
  uStack_2f = 0;
  uStack_2e = 0;
  uStack_2d = 0;
  uStack_27 = 0;
  uStack_26 = 0;
  uStack_20 = 0;
  uStack_1f = 0;
  uStack_19 = 0;
  uStack_18 = 0;
  uStack_12 = 0;
  uStack_11 = 0;
  uStack_b = 0;
  uStack_a = 0;
  uStack_9 = 0;
  uStack_8 = 0;
  uStack_7 = 0;
  uStack_6 = 0;
  uStack_5 = 0;
  uStack_4 = 0;
  puVar3 = *(undefined4 **)(param_1 + 0xfa8);
  uStack_45 = 1;
  uStack_42 = 1;
  uStack_3f = 1;
  uStack_3e = 1;
  uStack_3d = 1;
  uStack_3c = 1;
  uStack_2c = 1;
  uStack_2b = 1;
  uStack_2a = 1;
  uStack_29 = 1;
  uStack_28 = 1;
  uStack_25 = 1;
  uStack_21 = 1;
  uStack_1e = 1;
  uStack_1a = 1;
  uStack_17 = 1;
  uStack_13 = 1;
  uStack_10 = 1;
  uStack_f = 1;
  uStack_e = 1;
  uStack_d = 1;
  uStack_c = 1;
  uStack_44 = 2;
  uStack_43 = 2;
  uStack_24 = 2;
  uStack_23 = 2;
  uStack_22 = 2;
  uStack_1d = 2;
  uStack_1b = 2;
  uStack_16 = 2;
  uStack_15 = 2;
  uStack_14 = 2;
  *puVar3 = 0;
  uStack_1c = 3;
  puVar3[1] = 0x10100;
  puVar3[2] = 0x10100;
  puVar3[3] = 0;
  puVar3 = &uStack_74;
  puVar4 = *(undefined4 **)(param_1 + 0xfac);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
  puVar3 = &uStack_58;
  puVar4 = *(undefined4 **)(param_1 + 0xfb0);
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = &uStack_34;
  puVar4 = *(undefined4 **)(param_1 + 0xfb4);
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
  return;
}

// --------------------------------------------------

// Function: FUN_0044af81
// Address: 0044af81
void __fastcall FUN_0044af81(int param_1)
{
  operator_delete(*(void **)(param_1 + 0xfa8));
  operator_delete(*(void **)(param_1 + 0xfac));
  operator_delete(*(void **)(param_1 + 0xfb0));
  operator_delete(*(void **)(param_1 + 0xfb4));
  return;
}

// --------------------------------------------------

// Function: FUN_0044afd1
// Address: 0044afd1
void __thiscall FUN_0044afd1(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = *(int *)(param_1 + 0xfd4);
  if ((((param_2 <= iVar9) && (iVar5 = *(int *)(param_1 + 0xfd8), param_3 <= iVar5)) &&
      (-1 < param_4 + 2 + param_2)) && (-1 < param_4 + 2 + param_3)) {
    iVar1 = param_4 + 2;
    iVar6 = param_3;
    if (param_4 == 2) {
      if ((param_2 + 4 <= iVar9) && (param_2 < 0)) {
        param_2 = 0;
      }
      iVar7 = param_2;
      if ((param_3 + 4 <= iVar5) && (param_3 < 0)) {
        iVar6 = 0;
      }
    }
    else {
      iVar7 = param_2;
      if (param_4 == 3) {
        if ((param_2 + 5 <= iVar9) && (param_2 < 0)) {
          param_2 = 0;
        }
        iVar6 = param_3 + (uint)(iVar5 < 5);
        iVar7 = param_2;
      }
    }
    if (param_4 == 4) {
      param_2 = *(int *)(param_1 + 0xfb0);
      param_3 = iVar7 + 6;
      if (iVar9 < param_3) {
        param_3 = iVar9 - iVar7;
      }
      else if (iVar7 < 0) {
        param_2 = param_2 - iVar7;
        iVar7 = 0;
      }
      else {
        param_3 = 6;
      }
      iVar8 = iVar6 + 6;
      if (iVar5 < iVar8) {
        iVar8 = iVar5 - iVar6;
      }
      else if (iVar6 < 0) {
        param_2 = param_2 - iVar6 * iVar9;
        iVar6 = 0;
      }
      else {
        iVar8 = 6;
      }
    }
    else {
      param_2 = *(int *)(param_1 + 0xfb4);
      param_3 = iVar7 + 7;
      if (iVar9 < param_3) {
        param_3 = iVar9 - iVar7;
      }
      else if (iVar7 < 0) {
        param_2 = param_2 - iVar7;
        iVar7 = 0;
      }
      else {
        param_3 = 7;
      }
      iVar8 = iVar6 + 7;
      if (iVar5 < iVar8) {
        iVar8 = iVar5 - iVar6;
      }
      else if (iVar6 < 0) {
        param_2 = param_2 - iVar6 * iVar9;
        iVar6 = 0;
      }
      else {
        iVar8 = 7;
      }
    }
    iVar7 = iVar6 * iVar9 + iVar7;
    for (; iVar8 != 0; iVar8 = iVar8 + -1) {
      if (0 < param_3) {
        iVar9 = iVar7;
        param_4 = param_3;
        do {
          cVar3 = *(char *)((param_2 - iVar7) + iVar9);
          if ((0 < iVar9) && (iVar9 < *(int *)(param_1 + 0x1004) + -1)) {
            cVar4 = *(char *)(*(int *)(param_1 + 0x1024) + iVar9);
            pcVar2 = (char *)(*(int *)(param_1 + 0x1024) + iVar9);
            if (cVar4 == '\0') {
              *pcVar2 = cVar3;
              *(int *)(param_1 + 0xfec) = *(int *)(param_1 + 0xfec) + 1;
            }
            else if ((int)cVar3 + (int)cVar4 < 0xff) {
              *pcVar2 = cVar3 + cVar4;
            }
            else {
              *pcVar2 = -1;
            }
          }
          iVar9 = iVar9 + 1;
          param_4 = param_4 + -1;
        } while (param_4 != 0);
      }
      param_2 = param_2 + iVar1;
      iVar7 = iVar7 + *(int *)(param_1 + 0xfd4);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044b206
// Address: 0044b206
void __fastcall FUN_0044b206(int param_1)
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if ((*(int *)(param_1 + 0x103c) == 0) && (*(undefined4 **)(param_1 + 0x1028) != (undefined4 *)0x0)
     ) {
    uVar2 = *(uint *)(param_1 + 0x1004);
    puVar3 = *(undefined4 **)(param_1 + 0x1028);
    for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  if (*(undefined4 **)(param_1 + 0x1024) != (undefined4 *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x1004);
    puVar3 = *(undefined4 **)(param_1 + 0x1024);
    for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044b261
// Address: 0044b261
void __fastcall FUN_0044b261(int param_1)
{
  if (*(void **)(param_1 + 0x1024) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x1024));
  }
  if (*(void **)(param_1 + 0x1028) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x1028));
  }
  *(undefined4 *)(param_1 + 0x1024) = 0;
  *(undefined4 *)(param_1 + 0x1028) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0044b2af
// Address: 0044b2af
void __fastcall FUN_0044b2af(int param_1)
{
  void *pvVar1;
  int iVar2;
  bool bVar3;
  
  *(int *)(param_1 + 0x1004) = *(int *)(param_1 + 0xfd8) * *(int *)(param_1 + 0xfd4);
  iVar2 = 9;
  do {
    if (*(int *)(param_1 + 0x1024) != 0) break;
    pvVar1 = operator_new(*(uint *)(param_1 + 0x1004));
    *(void **)(param_1 + 0x1024) = pvVar1;
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  iVar2 = 9;
  do {
    if (*(int *)(param_1 + 0x1028) != 0) {
      return;
    }
    pvVar1 = operator_new(*(uint *)(param_1 + 0x1004));
    *(void **)(param_1 + 0x1028) = pvVar1;
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  return;
}

// --------------------------------------------------

// Function: FUN_0044b46e
// Address: 0044b46e
int __thiscall FUN_0044b46e(PointMaker *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_1->NumNodes = 0;
  PointMaker::ClearArrays(param_1);
  PointMaker::PrepareLimits(param_1);
  param_1->y = param_3;
  (param_1->Prime).y = param_3;
  param_1->ProbabilityTiles = 0;
  param_1->NumNodes = 0;
  param_1->x = param_2;
  (param_1->Prime).x = param_2;
  PointMaker::DrawPrimaryIntoProbabilityArray(param_1);
  PointMaker::ErrorCheckingAndCorrection(param_1);
  iVar1 = param_1->MinimumNumTiles;
  iVar3 = param_1->ProbabilityTiles;
  param_1->NumTilesActuallyChosen = 0;
  iVar2 = 0;
  while ((iVar3 < iVar1 && (iVar2 < 0x5dc))) {
    iVar3 = (param_1->Prime).y;
    param_1->x = (param_1->Prime).x;
    param_1->y = iVar3;
    param_1->CurrentNumberOfBranchLevels = param_1->MaxNumberOfBranchLevels;
    param_1->NumNodes = 0;
    iVar3 = PointMaker::MakeFirstLink(param_1);
    PointMaker::Branch(param_1,iVar3);
    iVar3 = param_1->ProbabilityTiles;
    iVar2 = iVar2 + 1;
  }
  PointMaker::CreateMapBasedOnProbabilityArray(param_1);
  PointMaker::MapCleanUpEliminatingSinglesOnly(param_1);
  return param_1->ProbabilityTiles;
}

// --------------------------------------------------

// Function: FUN_0044b534
// Address: 0044b534
// [HELPER] s_C__msdev_work_age1_x1_fractal_cp: "C:\msdev\work\age1_x1\fractal.cpp"
void __thiscall FUN_0044b534(PointMaker *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  if (((1 < param_1->CurrentNumberOfBranchLevels) &&
      (iVar1 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x116),
      iVar1 % 100 < param_1->ChanceOfNextNode * 10)) &&
     (SBORROW4(param_1->ProbabilityTiles,param_1->MinimumNumTiles * 2) !=
      param_1->ProbabilityTiles + param_1->MinimumNumTiles * -2 < 0)) {
    iVar1 = 0;
    param_1->CurrentNumberOfBranchLevels = param_1->CurrentNumberOfBranchLevels + -1;
    if (0 < param_1->NumSplitsPerBranch) {
      do {
        param_1->x = param_1->Point[param_2].x;
        param_1->y = param_1->Point[param_2].y;
        iVar2 = PointMaker::MakeNewLink(param_1);
        PointMaker::DrawCurrentBranchIntoProbArray(param_1,iVar2);
        PointMaker::Branch(param_1,iVar2);
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1->NumSplitsPerBranch);
    }
  }
  iVar1 = 0;
  if (0 < param_1->NumberOfSatellites) {
    do {
      iVar2 = PointMaker::MakeSatelliteLink(param_1);
      PointMaker::DrawCurrentSatelliteIntoProbArray(param_1,iVar2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1->NumberOfSatellites);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044b75c
// Address: 0044b75c
// [HELPER] s_C__msdev_work_age1_x1_fractal_cp: "C:\msdev\work\age1_x1\fractal.cpp"
void __fastcall FUN_0044b75c(int param_1)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x14a);
  iVar2 = iVar2 % *(int *)(param_1 + 0x100c) + 1;
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x14a);
  uVar8 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar8) - uVar8 & 1 ^ uVar8) != uVar8) {
    iVar2 = -iVar2;
  }
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x14b);
  iVar4 = iVar4 % *(int *)(param_1 + 0x100c) + 1;
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x14b);
  uVar8 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar8) - uVar8 & 1 ^ uVar8) != uVar8) {
    iVar4 = -iVar4;
  }
  iVar6 = *(int *)(param_1 + 0xfb8);
  iVar2 = iVar2 + *(int *)(param_1 + 0x1010);
  iVar4 = iVar4 + *(int *)(param_1 + 0x1014);
  if (iVar2 + iVar6 < 5) {
    iVar2 = -iVar2;
    *(int *)(param_1 + 0x1010) = -*(int *)(param_1 + 0x1010);
  }
  iVar5 = *(int *)(param_1 + 0xfd4) + -5;
  if (iVar5 <= iVar2 + iVar6) {
    iVar2 = -iVar2;
    *(int *)(param_1 + 0x1010) = -*(int *)(param_1 + 0x1010);
  }
  iVar1 = *(int *)(param_1 + 0xfbc);
  if (iVar4 + iVar1 < 5) {
    iVar4 = -iVar2;
    *(int *)(param_1 + 0x1014) = -*(int *)(param_1 + 0x1014);
  }
  iVar7 = *(int *)(param_1 + 0xfd8) + -5;
  if (iVar7 <= iVar4 + iVar1) {
    iVar4 = -iVar4;
  }
  iVar2 = iVar2 + iVar6;
  iVar4 = iVar4 + iVar1;
  if (iVar2 < 5) {
    iVar2 = 5;
  }
  if (iVar5 <= iVar2) {
    iVar2 = iVar5;
  }
  if (iVar4 < 5) {
    iVar4 = 5;
  }
  if (iVar7 <= iVar4) {
    iVar4 = iVar7;
  }
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x15a);
  uVar8 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar8) - uVar8 & 1 ^ uVar8) != uVar8) {
    iVar6 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x15a);
    *(int *)(param_1 + 0x1010) = *(int *)(param_1 + 0x1010) + iVar6 % 3 + -1;
  }
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x15b);
  uVar8 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar8) - uVar8 & 1 ^ uVar8) != uVar8) {
    iVar6 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x15b);
    *(int *)(param_1 + 0x1014) = *(int *)(param_1 + 0x1014) + iVar6 % 3 + -1;
  }
  *(int *)(param_1 + 0xfb8) = iVar2;
  *(int *)(param_1 + 0xfbc) = iVar4;
  *(int *)(param_1 + 8 + *(int *)(param_1 + 0xfe0) * 8) = iVar2;
  *(undefined4 *)(param_1 + 0xc + *(int *)(param_1 + 0xfe0) * 8) = *(undefined4 *)(param_1 + 0xfbc);
  *(int *)(param_1 + 0xfe0) = *(int *)(param_1 + 0xfe0) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0044bb56
// Address: 0044bb56
void __thiscall FUN_0044bb56(PointMaker *param_1,int param_2)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_8;
  int iStack_4;
  
  iVar7 = param_1->Point[param_2].x;
  iVar2 = param_1->BranchRadius;
  iStack_8 = param_1->Point[param_2].y;
  iVar6 = iVar2 + iVar7;
  iVar7 = iVar7 - iVar2;
  iVar5 = iStack_8 - iVar2;
  iStack_8 = iStack_8 + iVar2;
  if ((((-1 < iVar6) && (-1 < iStack_8)) && (iVar7 < param_1->Width)) && (iVar5 < param_1->Height))
{
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    if (param_1->Width <= iVar6) {
      iVar6 = param_1->Width + -1;
    }
    if (param_1->Height <= iStack_8) {
      iStack_8 = param_1->Height + -1;
    }
    param_1->ProbabilityAdd = 1;
    iStack_4 = 0;
    if (0 < iVar2) {
      do {
        PointMaker::AddingRect(param_1,iVar7,iVar5,iVar6,iStack_8);
        iVar7 = iVar7 + 1;
        if (((param_1->Width <= iVar7) || (iVar5 = iVar5 + 1, param_1->Height <= iVar5)) ||
           ((iVar6 = iVar6 + -1, iVar6 < 0 || (iStack_8 = iStack_8 + -1, iStack_8 < 0)))) break;
        param_1->ProbabilityAdd = param_1->ProbabilityAdd + 1;
        iStack_4 = iStack_4 + 1;
      } while (iStack_4 < param_1->BranchRadius);
    }
    iVar6 = param_1->Width * param_1->Point[param_2].y + param_1->Point[param_2].x;
    if ((0 < iVar6) && (iVar6 < param_1->SizeArrays + -1)) {
      pcVar3 = param_1->ProbArray + iVar6;
      cVar1 = *pcVar3;
      cVar4 = (char)param_1->ProbabilityAdd;
      if (cVar1 == '\0') {
        *pcVar3 = cVar4;
        param_1->ProbabilityTiles = param_1->ProbabilityTiles + 1;
        return;
      }
      if (param_1->ProbabilityAdd + (int)cVar1 < 0xff) {
        *pcVar3 = cVar4 + cVar1;
        return;
      }
      *pcVar3 = -1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044bcc5
// Address: 0044bcc5
void __thiscall FUN_0044bcc5(PointMaker *param_1,int param_2)
{
  char cVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = param_1->SatelliteRadius;
  param_1->ProbabilityAdd = 2;
  for (; -1 < iVar4; iVar4 = iVar4 + -1) {
    PointMaker::AddingCircle(param_1,param_1->Point[param_2].x,param_1->Point[param_2].y,iVar4);
    param_1->ProbabilityAdd = param_1->ProbabilityAdd + 1;
  }
  iVar4 = param_1->Point[param_2].y * param_1->Width + param_1->Point[param_2].x;
  if ((0 < iVar4) && (iVar4 < param_1->SizeArrays + -1)) {
    pcVar2 = param_1->ProbArray + iVar4;
    cVar1 = *pcVar2;
    cVar3 = (char)param_1->ProbabilityAdd;
    if (cVar1 == '\0') {
      *pcVar2 = cVar3;
      param_1->ProbabilityTiles = param_1->ProbabilityTiles + 1;
      return;
    }
    if (param_1->ProbabilityAdd + (int)cVar1 < 0xff) {
      *pcVar2 = cVar3 + cVar1;
      return;
    }
    *pcVar2 = -1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044bd7b
// Address: 0044bd7b
void __thiscall FUN_0044bd7b(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  char cVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  iVar5 = param_3 * *(int *)(param_1 + 0xfd4) + param_2;
  param_2 = param_4 - param_2;
  iVar3 = (param_5 - param_3) + -1;
  iVar7 = iVar3 * *(int *)(param_1 + 0xfd4) + iVar5;
  if ((-1 < param_2) && (-1 < param_5 - param_3)) {
    if (-1 < param_2) {
      param_4 = param_2 + 1;
      iVar2 = iVar5;
      do {
        if ((0 < iVar2) && (iVar2 < *(int *)(param_1 + 0x1004) + -1)) {
          pcVar6 = (char *)(*(int *)(param_1 + 0x1024) + iVar2);
          cVar1 = *pcVar6;
          cVar4 = (char)*(int *)(param_1 + 0xff4);
          if (cVar1 == '\0') {
            *pcVar6 = cVar4;
            *(int *)(param_1 + 0xfec) = *(int *)(param_1 + 0xfec) + 1;
          }
          else if (*(int *)(param_1 + 0xff4) + (int)cVar1 < 0xff) {
            *pcVar6 = cVar4 + cVar1;
          }
          else {
            *pcVar6 = -1;
          }
        }
        if ((0 < iVar7) && (iVar7 < *(int *)(param_1 + 0x1004) + -1)) {
          pcVar6 = (char *)(*(int *)(param_1 + 0x1024) + iVar7);
          cVar1 = *(char *)(*(int *)(param_1 + 0x1024) + iVar7);
          cVar4 = (char)*(int *)(param_1 + 0xff4);
          if (cVar1 == '\0') {
            *pcVar6 = cVar4;
            *(int *)(param_1 + 0xfec) = *(int *)(param_1 + 0xfec) + 1;
          }
          else if (*(int *)(param_1 + 0xff4) + (int)cVar1 < 0xff) {
            *pcVar6 = cVar4 + cVar1;
          }
          else {
            *pcVar6 = -1;
          }
        }
        iVar7 = iVar7 + 1;
        iVar2 = iVar2 + 1;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
    iVar5 = iVar5 + *(int *)(param_1 + 0xfd4);
    if (-1 < iVar3) {
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        if ((0 < iVar5) && (iVar5 < *(int *)(param_1 + 0x1004) + -1)) {
          pcVar6 = (char *)(*(int *)(param_1 + 0x1024) + iVar5);
          cVar1 = *(char *)(*(int *)(param_1 + 0x1024) + iVar5);
          cVar4 = (char)*(int *)(param_1 + 0xff4);
          if (cVar1 == '\0') {
            *pcVar6 = cVar4;
            *(int *)(param_1 + 0xfec) = *(int *)(param_1 + 0xfec) + 1;
          }
          else if (*(int *)(param_1 + 0xff4) + (int)cVar1 < 0xff) {
            *pcVar6 = cVar4 + cVar1;
          }
          else {
            *pcVar6 = -1;
          }
        }
        iVar7 = param_2 + iVar5;
        if ((0 < iVar7) && (iVar7 < *(int *)(param_1 + 0x1004) + -1)) {
          pcVar6 = (char *)(*(int *)(param_1 + 0x1024) + iVar7);
          cVar1 = *pcVar6;
          cVar4 = (char)*(int *)(param_1 + 0xff4);
          if (cVar1 == '\0') {
            *pcVar6 = cVar4;
            *(int *)(param_1 + 0xfec) = *(int *)(param_1 + 0xfec) + 1;
          }
          else if (*(int *)(param_1 + 0xff4) + (int)cVar1 < 0xff) {
            *pcVar6 = cVar4 + cVar1;
          }
          else {
            *pcVar6 = -1;
          }
        }
        iVar5 = iVar5 + *(int *)(param_1 + 0xfd4);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044bf84
// Address: 0044bf84
// [HELPER] s_C__msdev_work_age1_x1_fractal_cp: "C:\msdev\work\age1_x1\fractal.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0044bf84(int param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  float10 extraout_ST0;
  float fVar9;
  float fVar10;
  float fStack_18;
  float fStack_14;
  
  if (param_4 == 0) {
    param_4 = 1;
  }
  fStack_18 = 0.0;
  fStack_14 = 0.0;
  iVar8 = 0;
  do {
    fVar9 = TRIGONOMETRY::sin360(&trig,iVar8);
    fVar9 = fVar9 * (float)param_4;
    fVar10 = TRIGONOMETRY::cos360(&trig,iVar8);
    if ((fVar9 != fStack_18) || (fVar10 * (float)param_4 != fStack_14)) {
      iVar2 = __ftol();
      if ((0 < iVar2) && (iVar2 < *(int *)(param_1 + 0x1004) + -1)) {
        pcVar3 = (char *)(iVar2 + *(int *)(param_1 + 0x1024));
        cVar1 = *pcVar3;
        cVar6 = (char)*(int *)(param_1 + 0xff4);
        if (cVar1 == '\0') {
          *pcVar3 = cVar6;
          *(int *)(param_1 + 0xfec) = *(int *)(param_1 + 0xfec) + 1;
        }
        else if (*(int *)(param_1 + 0xff4) + (int)cVar1 < 0xff) {
          *pcVar3 = cVar6 + cVar1;
        }
        else {
          *pcVar3 = -1;
        }
      }
      fStack_14 = (float)extraout_ST0;
      uVar4 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x1f1);
      uVar7 = (int)uVar4 >> 0x1f;
      fStack_18 = fVar9;
      if (((uVar4 ^ uVar7) - uVar7 & 1 ^ uVar7) != uVar7) {
        TRIGONOMETRY::sin360(&trig,iVar8);
        debug_rand(s_C__msdev_work_age1_x1_fractal_cp,499);
        TRIGONOMETRY::cos360(&trig,iVar8);
        debug_rand(s_C__msdev_work_age1_x1_fractal_cp,500);
        iVar2 = __ftol();
        iVar5 = *(int *)(param_1 + 0xff4) + 1;
        if ((0 < iVar2) && (iVar2 < *(int *)(param_1 + 0x1004) + -1)) {
          pcVar3 = (char *)(iVar2 + *(int *)(param_1 + 0x1024));
          cVar1 = *pcVar3;
          cVar6 = (char)iVar5;
          if (cVar1 == '\0') {
            *pcVar3 = cVar6;
            *(int *)(param_1 + 0xfec) = *(int *)(param_1 + 0xfec) + 1;
          }
          else if (iVar5 + cVar1 < 0xff) {
            *pcVar3 = cVar6 + cVar1;
          }
          else {
            *pcVar3 = -1;
          }
        }
      }
    }
    iVar8 = iVar8 + (int)(0x168 / (longlong)(param_4 * 3));
  } while (iVar8 < 0x168);
  return;
}

// --------------------------------------------------

// Function: FUN_0044c1ac
// Address: 0044c1ac
void __fastcall FUN_0044c1ac(int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x1004)) {
    do {
      if (*(char *)(iVar1 + *(int *)(param_1 + 0x1024)) != '\0') {
        iVar2 = iVar2 + 1;
        *(undefined1 *)(*(int *)(param_1 + 0x1028) + iVar1) = 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x1004));
  }
  *(int *)(param_1 + 0xfe4) = *(int *)(param_1 + 0xfe4) + iVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c1f1
// Address: 0044c1f1
void __thiscall FUN_0044c1f1(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0xfb8) = param_2;
  *(undefined4 *)(param_1 + 0xfbc) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c217
// Address: 0044c217
void __thiscall FUN_0044c217(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xfcc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c22d
// Address: 0044c22d
void __thiscall FUN_0044c22d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xfc8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c23d
// Address: 0044c23d
void __thiscall FUN_0044c23d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xfc4) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c24d
// Address: 0044c24d
void __thiscall FUN_0044c24d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xfc0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c25d
// Address: 0044c25d
void __thiscall FUN_0044c25d(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0xfd4) = param_2;
  *(undefined4 *)(param_1 + 0xfd8) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c277
// Address: 0044c277
void __thiscall FUN_0044c277(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1000) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c28d
// Address: 0044c28d
void __thiscall FUN_0044c28d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xff8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c29d
// Address: 0044c29d
void __thiscall FUN_0044c29d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xffc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c2ad
// Address: 0044c2ad
void __thiscall FUN_0044c2ad(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xfd0) = 1;
  *(undefined4 *)(param_1 + 0x1018) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c2c7
// Address: 0044c2c7
void __thiscall FUN_0044c2c7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1008) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c2dd
// Address: 0044c2dd
void __thiscall FUN_0044c2dd(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x100c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c2ed
// Address: 0044c2ed
void __thiscall FUN_0044c2ed(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xfdc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c2fd
// Address: 0044c2fd
void __fastcall FUN_0044c2fd(int param_1)
{
  *(undefined4 *)(param_1 + 0x103c) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c30b
// Address: 0044c30b
void __thiscall FUN_0044c30b(PointMaker *param_1,int param_2)
{
  param_1->BorderDepthPercentage = param_2;
  if (0x1e < param_2) {
    param_1->BorderDepthPercentage = 0x1e;
  }
  if (param_1->BorderDepthPercentage < 5) {
    param_1->BorderDepthPercentage = 5;
  }
  PointMaker::PrepareLimits(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0044c346
// Address: 0044c346
undefined4 __fastcall FUN_0044c346(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1028);
}

// --------------------------------------------------

// Function: FUN_0044c357
// Address: 0044c357
undefined4 __fastcall FUN_0044c357(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1024);
}

// --------------------------------------------------

// Function: FUN_0044c367
// Address: 0044c367
void __fastcall FUN_0044c367(int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xfd4);
  iVar2 = *(int *)(param_1 + 0xfd8) * iVar1;
  *(int *)(param_1 + 0x1004) = iVar2;
  if (iVar1 < *(int *)(param_1 + 0xff8)) {
    *(int *)(param_1 + 0xff8) = (iVar1 * 2) / 3;
  }
  if (iVar1 < *(int *)(param_1 + 0xffc)) {
    *(int *)(param_1 + 0xffc) = (iVar1 * 2) / 3;
  }
  if (iVar1 < *(int *)(param_1 + 0x1000)) {
    *(int *)(param_1 + 0x1000) = (iVar1 * 2) / 3;
  }
  if (4 < *(int *)(param_1 + 0xfc0)) {
    *(undefined4 *)(param_1 + 0xfc0) = 4;
  }
  if (4 < *(int *)(param_1 + 0xfc4)) {
    *(undefined4 *)(param_1 + 0xfc4) = 4;
  }
  iVar2 = iVar2 / *(int *)(param_1 + 0xfdc);
  *(undefined4 *)(param_1 + 0x103c) = 0;
  iVar1 = (10 - iVar2) * 10;
  *(int *)(param_1 + 0xfc8) = iVar1;
  if (iVar1 < 0x23) {
    *(undefined4 *)(param_1 + 0xfc8) = 0x23;
  }
  if (0x50 < *(int *)(param_1 + 0xfc8)) {
    *(undefined4 *)(param_1 + 0xfc8) = 0x50;
  }
  if (*(int *)(param_1 + 0xfd0) == 0) {
    *(int *)(param_1 + 0x1018) = iVar2 - *(int *)(param_1 + 0xfc8) / 5;
  }
  if (*(int *)(param_1 + 0x1018) < 10) {
    *(undefined4 *)(param_1 + 0x1018) = 10;
  }
  if (0x1e < *(int *)(param_1 + 0x1018)) {
    *(undefined4 *)(param_1 + 0x1018) = 0x1e;
  }
  *(undefined4 *)(param_1 + 0xfd0) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c4ae
// Address: 0044c4ae
void __fastcall FUN_0044c4ae(int param_1)
{
  int iVar1;
  
  iVar1 = (*(int *)(param_1 + 0x1040) * *(int *)(param_1 + 0xfd4)) / 100;
  *(int *)(param_1 + 0x1044) = iVar1;
  *(int *)(param_1 + 0x1048) = *(int *)(param_1 + 0xfd4) - iVar1;
  iVar1 = (*(int *)(param_1 + 0xfd8) * *(int *)(param_1 + 0x1040)) / 100;
  *(int *)(param_1 + 0x104c) = iVar1;
  *(int *)(param_1 + 0x1050) = *(int *)(param_1 + 0xfd8) - iVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0044c50f
// Address: 0044c50f
void __fastcall FUN_0044c50f(int param_1)
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  
  iVar4 = *(int *)(param_1 + 0xfd8) + -1;
  iVar5 = 1;
  iVar2 = *(int *)(param_1 + 0xfd4) + -1;
  if (1 < iVar4) {
    do {
      iVar7 = 1;
      if (1 < iVar2) {
        do {
          iVar1 = *(int *)(param_1 + 0xfd4);
          pcVar3 = (char *)(iVar5 * iVar1 + iVar7 + *(int *)(param_1 + 0x1028));
          cVar6 = '\0' < pcVar3[-iVar1];
          if ('\0' < pcVar3[-1]) {
            cVar6 = cVar6 + '\x01';
          }
          if ('\0' < pcVar3[1]) {
            cVar6 = cVar6 + '\x01';
          }
          if ('\0' < pcVar3[iVar1]) {
            cVar6 = cVar6 + '\x01';
          }
          if ((*pcVar3 != '\0') && (cVar6 == '\0')) {
            *pcVar3 = '\0';
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar2);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044c77a
// Address: 0044c77a
// [HELPER] s_: ""
char * __thiscall FUN_0044c77a(char *param_1,RGE_Campaign *param_2)
{
  char cVar1;
  char *pcVar2;
  long lVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  
  if (param_2 == (RGE_Campaign *)0x0) {
    uVar5 = 0xffffffff;
    param_1[0x110] = '\0';
    param_1[0x111] = '\0';
    param_1[0x112] = '\0';
    param_1[0x113] = '\0';
    pcVar2 = s_;
    do {
      pcVar7 = pcVar2;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar2 = pcVar7 + -uVar5;
    pcVar7 = param_1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar7 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar7 = pcVar7 + 1;
    }
    param_1[0x100] = '\0';
    param_1[0x101] = '\0';
    param_1[0x102] = '\0';
    param_1[0x103] = '\0';
    param_1[0x10c] = '\0';
    param_1[0x10d] = '\0';
    param_1[0x10e] = '\0';
    param_1[0x10f] = '\0';
    param_1[0x104] = '\0';
    param_1[0x105] = '\0';
    param_1[0x106] = '\0';
    param_1[0x107] = '\0';
    param_1[0x108] = '\0';
    param_1[0x109] = '\0';
    param_1[0x10a] = '\0';
    param_1[0x10b] = '\0';
    return param_1;
  }
  *(RGE_Campaign **)(param_1 + 0x110) = param_2;
  pcVar2 = RGE_Campaign::get_name(param_2);
  uVar5 = 0xffffffff;
  do {
    pcVar7 = pcVar2;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar7;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar2 = pcVar7 + -uVar5;
  pcVar7 = param_1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar7 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar7 = pcVar7 + 1;
  }
  lVar3 = RGE_Campaign::scenario_number(*(RGE_Campaign **)(param_1 + 0x110));
  *(long *)(param_1 + 0x104) = lVar3;
  if (0 < lVar3) {
    param_1[0x100] = '\0';
    param_1[0x101] = '\0';
    param_1[0x102] = '\0';
    param_1[0x103] = '\0';
    param_1[0x10c] = '\0';
    param_1[0x10d] = '\0';
    param_1[0x10e] = '\0';
    param_1[0x10f] = '\0';
    puVar4 = (undefined1 *)calloc(lVar3,1);
    *(undefined1 **)(param_1 + 0x108) = puVar4;
    *puVar4 = 2;
    return param_1;
  }
  param_1[0x108] = '\0';
  param_1[0x109] = '\0';
  param_1[0x10a] = '\0';
  param_1[0x10b] = '\0';
  param_1[0x100] = -1;
  param_1[0x101] = -1;
  param_1[0x102] = -1;
  param_1[0x103] = -1;
  param_1[0x10c] = -1;
  param_1[0x10d] = -1;
  param_1[0x10e] = -1;
  param_1[0x10f] = -1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044c863
// Address: 0044c863
void __fastcall FUN_0044c863(int param_1)
{
  if (*(int *)(param_1 + 0x108) != 0) {
    free(*(int *)(param_1 + 0x108));
    *(undefined4 *)(param_1 + 0x108) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044c892
// Address: 0044c892
// [HELPER] s____PIF_Saving_campaign_____d___s: "  (PIF)Saving campaign - (%d) %s"
void __thiscall FUN_0044c892(void *param_1,int param_2)
{
  int iVar1;
  
  TDebuggingLog::Log(L,(char *)L,s____PIF_Saving_campaign_____d___s,
                     *(undefined4 *)((int)param_1 + 0x10c),param_1);
  rge_write(param_2,param_1,0xff);
  rge_write(param_2,(void *)((int)param_1 + 0x100),4);
  rge_write(param_2,(int *)((int)param_1 + 0x104),4);
  rge_write(param_2,(void *)((int)param_1 + 0x10c),4);
  iVar1 = *(int *)((int)param_1 + 0x104);
  if (0 < iVar1) {
    rge_write(param_2,*(void **)((int)param_1 + 0x108),iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044c92a
// Address: 0044c92a
void __thiscall FUN_0044c92a(byte *param_1,undefined4 *param_2,undefined4 *param_3)
{
  byte bVar1;
  RGE_Campaign *this;
  byte *pbVar2;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  bool bVar11;
  undefined4 uVar12;
  
  iVar3 = (int)param_3;
  param_1[0x110] = 0;
  param_1[0x111] = 0;
  param_1[0x112] = 0;
  param_1[0x113] = 0;
  if (0 < (int)param_3) {
    param_3 = param_2;
    param_2 = (undefined4 *)iVar3;
    do {
      pbVar2 = (byte *)RGE_Campaign::get_name((RGE_Campaign *)*param_3);
      pbVar9 = param_1;
      do {
        bVar1 = *pbVar2;
        bVar11 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_0044c98c:
          iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_0044c991;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar11 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_0044c98c;
        pbVar2 = pbVar2 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_0044c991:
      if (iVar3 == 0) {
        this = (RGE_Campaign *)*param_3;
        *(RGE_Campaign **)(param_1 + 0x110) = this;
        lVar4 = RGE_Campaign::scenario_number(this);
        if (*(int *)(param_1 + 0x104) != lVar4) {
          uVar12 = 1;
          lVar4 = RGE_Campaign::scenario_number(*(RGE_Campaign **)(param_1 + 0x110));
          puVar5 = (undefined4 *)calloc(lVar4,uVar12);
          uVar7 = *(uint *)(param_1 + 0x104);
          lVar4 = RGE_Campaign::scenario_number(*(RGE_Campaign **)(param_1 + 0x110));
          puVar10 = puVar5;
          if ((int)uVar7 < lVar4) {
            puVar8 = *(undefined4 **)(param_1 + 0x108);
            for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *puVar10 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar10 = puVar10 + 1;
            }
          }
          else {
            uVar7 = RGE_Campaign::scenario_number(*(RGE_Campaign **)(param_1 + 0x110));
            puVar8 = *(undefined4 **)(param_1 + 0x108);
            for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *puVar10 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar10 = puVar10 + 1;
            }
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          free(*(undefined4 *)(param_1 + 0x108));
          *(undefined4 **)(param_1 + 0x108) = puVar5;
        }
        lVar4 = RGE_Campaign::scenario_number(*(RGE_Campaign **)(param_1 + 0x110));
        *(long *)(param_1 + 0x104) = lVar4;
        if (lVar4 <= *(int *)(param_1 + 0x10c)) {
          *(long *)(param_1 + 0x10c) = lVar4 + -1;
        }
        if (*(int *)(param_1 + 0x10c) < *(int *)(param_1 + 0x100)) {
          *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x10c);
        }
      }
      param_3 = param_3 + 1;
      param_2 = (undefined4 *)((int)param_2 + -1);
    } while (param_2 != (undefined4 *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044ca82
// Address: 0044ca82
undefined4 __thiscall FUN_0044ca82(int param_1,int param_2)
{
  if ((param_2 < *(int *)(param_1 + 0x104)) &&
     (*(char *)(*(int *)(param_1 + 0x108) + param_2) != '\0')) {
    if (*(int *)(param_1 + 0x10c) < param_2) {
      *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x10c);
      return 1;
    }
    *(int *)(param_1 + 0x100) = param_2;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044cacf
// Address: 0044cacf
undefined4 __thiscall FUN_0044cacf(byte *param_1,byte *param_2)
{
  byte bVar1;
  int iVar2;
  bool bVar3;
  
  while( true ) {
    bVar1 = *param_1;
    bVar3 = bVar1 < *param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 1;
    }
    bVar1 = param_1[1];
    bVar3 = bVar1 < param_2[1];
    if (bVar1 != param_2[1]) break;
    param_1 = param_1 + 2;
    param_2 = param_2 + 2;
    if (bVar1 == 0) {
      return 1;
    }
  }
  iVar2 = (1 - (uint)bVar3) - (uint)(bVar3 != 0);
  return CONCAT31((int3)((uint)iVar2 >> 8),iVar2 == 0);
}

// --------------------------------------------------

// Function: FUN_0044cb17
// Address: 0044cb17
int __thiscall FUN_0044cb17(int param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x110) != 0) {
    iVar1 = calloc(*(int *)(param_1 + 0x10c) + 1,4);
    iVar3 = 0;
    *param_2 = iVar1;
    if (-1 < *(int *)(param_1 + 0x10c)) {
      do {
        pcVar2 = RGE_Campaign::get_scenario_name(*(RGE_Campaign **)(param_1 + 0x110),iVar3);
        getstring((char **)(*param_2 + iVar3 * 4),pcVar2);
        iVar3 = iVar3 + 1;
      } while (iVar3 <= *(int *)(param_1 + 0x10c));
    }
    *param_3 = *(undefined4 *)(param_1 + 0x100);
    return *(int *)(param_1 + 0x10c) + 1;
  }
  *param_3 = 0xffffffff;
  return -1;
}

// --------------------------------------------------

// Function: FUN_0044cba3
// Address: 0044cba3
undefined4 __fastcall FUN_0044cba3(int param_1)
{
  return *(undefined4 *)(param_1 + 0x100);
}

// --------------------------------------------------

// Function: FUN_0044cbb7
// Address: 0044cbb7
void __fastcall FUN_0044cbb7(RGE_Campaign_Info *param_1)
{
  int iVar1;
  
  if (-1 < param_1->current_scenario) {
    param_1->scenario_info[param_1->current_scenario].scenario_status = '\x01';
    if (param_1->last_scenario <= param_1->current_scenario) {
      iVar1 = param_1->current_scenario + 1;
      param_1->last_scenario = iVar1;
      RGE_Campaign_Info::set_current_scenario(param_1,iVar1);
    }
    if (param_1->scenario_num <= param_1->last_scenario) {
      param_1->last_scenario = param_1->scenario_num + -1;
    }
    param_1->scenario_info[param_1->last_scenario].scenario_status = '\x02';
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044cc1e
// Address: 0044cc1e
int __fastcall FUN_0044cc1e(int param_1)
{
  int iVar1;
  
  if (-1 < *(int *)(param_1 + 0x100)) {
    iVar1 = RGE_Campaign::open_scenario
                      (*(RGE_Campaign **)(param_1 + 0x110),*(int *)(param_1 + 0x100));
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0044cc3c
// Address: 0044cc3c
void * __thiscall FUN_0044cc3c(void *param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  int *piVar1;
  undefined4 uVar2;
  RGE_Campaign_Info *this;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d58b;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined4 *)((int)param_1 + 0x10c) = param_4;
  *(undefined4 *)((int)param_1 + 0x110) = param_3;
  rge_read(param_2,param_1,0xff);
  rge_read(param_2,(void *)((int)param_1 + 0x100),4);
  piVar1 = (int *)((int)param_1 + 0x104);
  rge_read(param_2,piVar1,4);
  iVar3 = 0;
  if (*piVar1 < 1) {
    *(undefined4 *)((int)param_1 + 0x108) = 0;
  }
  else {
    uVar2 = calloc(*piVar1,4);
    *(undefined4 *)((int)param_1 + 0x108) = uVar2;
    if (0 < *piVar1) {
      do {
        this = (RGE_Campaign_Info *)operator_new(0x114);
        uStack_4 = 0;
        if (this == (RGE_Campaign_Info *)0x0) {
          uVar2 = 0;
        }
        else {
          uVar2 = RGE_Campaign_Info::RGE_Campaign_Info
                            (this,param_2,*(RGE_Campaign ***)((int)param_1 + 0x110),
                             *(long *)((int)param_1 + 0x10c));
        }
        iVar3 = iVar3 + 1;
        uStack_4 = 0xffffffff;
        *(undefined4 *)(*(int *)((int)param_1 + 0x108) + -4 + iVar3 * 4) = uVar2;
      } while (iVar3 < *piVar1);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044cd34
// Address: 0044cd34
char * __thiscall FUN_0044cd34(char *param_1,char *param_2,undefined4 param_3,undefined4 param_4)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
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
  pcVar5 = param_1;
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
  param_1[0x104] = '\0';
  param_1[0x105] = '\0';
  param_1[0x106] = '\0';
  param_1[0x107] = '\0';
  param_1[0x108] = '\0';
  param_1[0x109] = '\0';
  param_1[0x10a] = '\0';
  param_1[0x10b] = '\0';
  *(undefined4 *)(param_1 + 0x110) = param_3;
  param_1[0x100] = -1;
  param_1[0x101] = -1;
  param_1[0x102] = -1;
  param_1[0x103] = -1;
  *(undefined4 *)(param_1 + 0x10c) = param_4;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044cd98
// Address: 0044cd98
void __fastcall FUN_0044cd98(int param_1)
{
  RGE_Campaign_Info *this;
  int iVar1;
  
  if (*(int *)(param_1 + 0x108) != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x104)) {
      do {
        this = *(RGE_Campaign_Info **)(*(int *)(param_1 + 0x108) + iVar1 * 4);
        if (this != (RGE_Campaign_Info *)0x0) {
          RGE_Campaign_Info::~RGE_Campaign_Info(this);
          operator_delete(this);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x104));
    }
    free(*(undefined4 *)(param_1 + 0x108));
    *(undefined4 *)(param_1 + 0x108) = 0;
    *(undefined4 *)(param_1 + 0x104) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044ce0a
// Address: 0044ce0a
// [HELPER] s__PIF_Saving_player____s: "(PIF)Saving player - %s"
void __thiscall FUN_0044ce0a(TDebuggingLog *param_1,int param_2)
{
  char *pcVar1;
  int iVar2;
  
  TDebuggingLog::Log(param_1,(char *)L,s__PIF_Saving_player____s,param_1);
  rge_write(param_2,param_1,0xff);
  rge_write(param_2,param_1->TBuff + 0xd8,4);
  pcVar1 = param_1->TBuff + 0xdc;
  rge_write(param_2,pcVar1,4);
  iVar2 = 0;
  if (0 < *(int *)pcVar1) {
    do {
      RGE_Campaign_Info::save
                (*(RGE_Campaign_Info **)(*(int *)(param_1->TBuff + 0xe0) + iVar2 * 4),param_2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)pcVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044ce88
// Address: 0044ce88
void __thiscall FUN_0044ce88(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  iVar1 = 0;
  *(undefined4 *)(param_1 + 0x10c) = param_3;
  *(undefined4 *)(param_1 + 0x110) = param_2;
  if (0 < *(int *)(param_1 + 0x104)) {
    do {
      RGE_Campaign_Info::rehook_campaigns
                (*(RGE_Campaign_Info **)(*(int *)(param_1 + 0x108) + iVar1 * 4),
                 *(RGE_Campaign ***)(param_1 + 0x110),*(long *)(param_1 + 0x10c));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x104));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044cee3
// Address: 0044cee3
undefined4 __thiscall FUN_0044cee3(int param_1,int param_2)
{
  uchar uVar1;
  char *pcVar2;
  undefined4 *puVar3;
  RGE_Campaign_Info *this;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d5ab;
  *unaff_FS_OFFSET = &uStack_c;
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x10c))) {
    param_2 = param_2 * 4;
    if (*(int *)(*(int *)(param_1 + 0x110) + param_2) != 0) {
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x104)) {
        do {
          pcVar2 = RGE_Campaign::get_name(*(RGE_Campaign **)(*(int *)(param_1 + 0x110) + param_2));
          uVar1 = RGE_Campaign_Info::verify_campaign_name
                            (*(RGE_Campaign_Info **)(*(int *)(param_1 + 0x108) + iVar6 * 4),pcVar2);
          if (uVar1 != '\0') {
            *(int *)(param_1 + 0x100) = iVar6;
            uVar4 = 1;
            goto LAB_0044d022;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(int *)(param_1 + 0x104));
      }
      puVar3 = (undefined4 *)calloc(*(int *)(param_1 + 0x104) + 1,4);
      if (*(undefined4 **)(param_1 + 0x108) != (undefined4 *)0x0) {
        puVar7 = *(undefined4 **)(param_1 + 0x108);
        puVar8 = puVar3;
        for (uVar5 = *(uint *)(param_1 + 0x104) & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
      }
      free(*(undefined4 *)(param_1 + 0x108));
      *(undefined4 **)(param_1 + 0x108) = puVar3;
      this = (RGE_Campaign_Info *)operator_new(0x114);
      uStack_4 = 0;
      if (this == (RGE_Campaign_Info *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = RGE_Campaign_Info::RGE_Campaign_Info
                          (this,*(RGE_Campaign **)(*(int *)(param_1 + 0x110) + param_2));
      }
      *(undefined4 *)(*(int *)(param_1 + 0x108) + *(int *)(param_1 + 0x104) * 4) = uVar4;
      *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x104);
      *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 1;
      uVar4 = 1;
      goto LAB_0044d022;
    }
  }
  uVar4 = 0;
LAB_0044d022:
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}

// --------------------------------------------------

// Function: FUN_0044d041
// Address: 0044d041
int __fastcall FUN_0044d041(int param_1)
{
  uchar uVar1;
  char *pcVar2;
  int iVar3;
  
  if (((-1 < *(int *)(param_1 + 0x100)) && (*(int *)(param_1 + 0x100) < *(int *)(param_1 + 0x104)))
     && (iVar3 = 0, 0 < *(int *)(param_1 + 0x10c))) {
    do {
      pcVar2 = RGE_Campaign::get_name(*(RGE_Campaign **)(*(int *)(param_1 + 0x110) + iVar3 * 4));
      uVar1 = RGE_Campaign_Info::verify_campaign_name
                        (*(RGE_Campaign_Info **)
                          (*(int *)(param_1 + 0x108) + *(int *)(param_1 + 0x100) * 4),pcVar2);
      if (uVar1 != '\0') {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x10c));
    return -1;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0044d0b5
// Address: 0044d0b5
long __fastcall FUN_0044d0b5(int param_1)
{
  int iVar1;
  long lVar2;
  
  if ((-1 < *(int *)(param_1 + 0x100)) &&
     (iVar1 = *(int *)(param_1 + 0x100) * 4, *(int *)(*(int *)(param_1 + 0x110) + iVar1) != 0)) {
    lVar2 = RGE_Campaign_Info::get_current_scenario
                      (*(RGE_Campaign_Info **)(*(int *)(param_1 + 0x108) + iVar1));
    return lVar2;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0044d0ed
// Address: 0044d0ed
uchar __thiscall FUN_0044d0ed(int param_1,long param_2)
{
  uchar uVar1;
  int iVar2;
  
  if ((-1 < *(int *)(param_1 + 0x100)) &&
     (iVar2 = *(int *)(param_1 + 0x100) * 4, *(int *)(*(int *)(param_1 + 0x110) + iVar2) != 0)) {
    uVar1 = RGE_Campaign_Info::set_current_scenario
                      (*(RGE_Campaign_Info **)(*(int *)(param_1 + 0x108) + iVar2),param_2);
    return uVar1;
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_0044d125
// Address: 0044d125
long __thiscall FUN_0044d125(int param_1,char ***param_2,long *param_3)
{
  long lVar1;
  
  if (-1 < *(int *)(param_1 + 0x100)) {
    lVar1 = RGE_Campaign_Info::get_scenario_list
                      (*(RGE_Campaign_Info **)
                        (*(int *)(param_1 + 0x108) + *(int *)(param_1 + 0x100) * 4),param_2,param_3)
    ;
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044d15b
// Address: 0044d15b
void __fastcall FUN_0044d15b(int param_1)
{
  if (-1 < *(int *)(param_1 + 0x100)) {
    RGE_Campaign_Info::notify_of_scenario_complete
              (*(RGE_Campaign_Info **)(*(int *)(param_1 + 0x108) + *(int *)(param_1 + 0x100) * 4));
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044d17a
// Address: 0044d17a
int __fastcall FUN_0044d17a(int param_1)
{
  int iVar1;
  
  if (-1 < *(int *)(param_1 + 0x100)) {
    iVar1 = RGE_Campaign_Info::open_scenario
                      (*(RGE_Campaign_Info **)
                        (*(int *)(param_1 + 0x108) + *(int *)(param_1 + 0x100) * 4));
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0044d19d
// Address: 0044d19d
// [HELPER] s_1_00: "1.00"
RGE_Game_Info * __thiscall FUN_0044d19d(RGE_Game_Info *param_1,char *param_2)
{
  long *plVar1;
  char cVar2;
  int iVar3;
  RGE_Person_Info **ppRVar4;
  RGE_Person_Info *pRVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined4 *unaff_FS_OFFSET;
  RGE_Game_Info *pRStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d5cb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  plVar1 = &param_1->people_num;
  param_1->people_info = (RGE_Person_Info **)0x0;
  *plVar1 = 0;
  param_1->campaign_num = 0;
  param_1->campaigns = (RGE_Campaign **)0x0;
  pRStack_10 = param_1;
  RGE_Game_Info::find_campaigns(param_1);
  uVar6 = 0xffffffff;
  pcVar8 = param_2;
  do {
    pcVar11 = pcVar8;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar11 = pcVar8 + 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar11;
  } while (cVar2 != '\0');
  uVar6 = ~uVar6;
  pcVar8 = pcVar11 + -uVar6;
  pcVar11 = param_1->save_filename;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar11 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar11 = pcVar11 + 1;
  }
  iVar3 = rge_open(param_2,0x8000);
  if (-1 < iVar3) {
    rge_read(iVar3,&pRStack_10,4);
    if (pRStack_10 == (RGE_Game_Info *)s_1_00._0_4_) {
      rge_read(iVar3,param_1,4);
      rge_read(iVar3,plVar1,4);
      if (*plVar1 < 1) {
        param_1->people_info = (RGE_Person_Info **)0x0;
      }
      else {
        ppRVar4 = (RGE_Person_Info **)calloc(*plVar1,4);
        param_1->people_info = ppRVar4;
        iVar9 = 0;
        if (0 < *plVar1) {
          do {
            pRVar5 = (RGE_Person_Info *)operator_new(0x114);
            uStack_4 = 0;
            if (pRVar5 == (RGE_Person_Info *)0x0) {
              pRVar5 = (RGE_Person_Info *)0x0;
            }
            else {
              pRVar5 = (RGE_Person_Info *)
                       RGE_Person_Info::RGE_Person_Info
                                 (pRVar5,iVar3,param_1->campaigns,param_1->campaign_num);
            }
            iVar10 = iVar9 + 1;
            uStack_4 = 0xffffffff;
            param_1->people_info[iVar9] = pRVar5;
            iVar9 = iVar10;
          } while (iVar10 < *plVar1);
          rge_close(iVar3);
          goto LAB_0044d2e3;
        }
      }
      rge_close(iVar3);
      goto LAB_0044d2e3;
    }
  }
  param_1->current_person = -1;
  *plVar1 = 0;
  param_1->people_info = (RGE_Person_Info **)0x0;
LAB_0044d2e3:
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044d2fa
// Address: 0044d2fa
void __fastcall FUN_0044d2fa(RGE_Game_Info *param_1)
{
  RGE_Campaign *this;
  RGE_Person_Info *this_00;
  int iVar1;
  
  if (param_1->save_filename[0] != '\0') {
    RGE_Game_Info::save(param_1,param_1->save_filename);
  }
  if (param_1->campaigns != (RGE_Campaign **)0x0) {
    iVar1 = 0;
    if (0 < param_1->campaign_num) {
      do {
        this = param_1->campaigns[iVar1];
        if (this != (RGE_Campaign *)0x0) {
          RGE_Campaign::~RGE_Campaign(this);
          operator_delete(this);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1->campaign_num);
    }
    free(param_1->campaigns);
    param_1->campaigns = (RGE_Campaign **)0x0;
  }
  if (param_1->people_info != (RGE_Person_Info **)0x0) {
    iVar1 = 0;
    if (0 < param_1->people_num) {
      do {
        this_00 = param_1->people_info[iVar1];
        if (this_00 != (RGE_Person_Info *)0x0) {
          RGE_Person_Info::~RGE_Person_Info(this_00);
          operator_delete(this_00);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1->people_num);
    }
    free(param_1->people_info);
    param_1->people_info = (RGE_Person_Info **)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044d3a5
// Address: 0044d3a5
// [HELPER] s_1_00: "1.00"
// [HELPER] s__PIF_Creating_Player_Info_File: "(PIF)Creating Player Info File"
void __thiscall FUN_0044d3a5(TDebuggingLog *param_1,char *param_2)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int *piVar9;
  
  TDebuggingLog::Log(param_1,(char *)L,s__PIF_Creating_Player_Info_File);
  uVar3 = 0xffffffff;
  pcVar7 = param_2;
  do {
    pcVar8 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  piVar5 = (int *)(pcVar8 + -uVar3);
  piVar9 = &param_1->Flush;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *piVar9 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar9 = piVar9 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)piVar9 = (char)*piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
    piVar9 = (int *)((int)piVar9 + 1);
  }
  iVar2 = rge_open(param_2,0x8309,0x180);
  if (iVar2 != -1) {
    rge_write(iVar2,s_1_00,4);
    rge_write(iVar2,param_1,4);
    piVar5 = &param_1->DateTimestamp;
    rge_write(iVar2,piVar5,4);
    if ((0 < *piVar5) && (iVar6 = 0, 0 < *piVar5)) {
      do {
        RGE_Person_Info::save(*(RGE_Person_Info **)(param_1->LogToFile + iVar6 * 4),iVar2);
        iVar6 = iVar6 + 1;
      } while (iVar6 < *piVar5);
    }
    rge_close(iVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044d465
// Address: 0044d465
// [HELPER] s__s__cpn: "%s*.cpn"
// [HELPER] s__s__cpx: "%s*.cpx"
void __fastcall FUN_0044d465(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  RGE_Campaign *pRVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_228 [20];
  char acStack_214 [260];
  undefined1 auStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d5fc;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 0x10) != 0) {
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0xc)) {
      do {
        pRVar4 = *(RGE_Campaign **)(*(int *)(param_1 + 0x10) + iVar5 * 4);
        if (pRVar4 != (RGE_Campaign *)0x0) {
          RGE_Campaign::~RGE_Campaign(pRVar4);
          operator_delete(pRVar4);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(param_1 + 0xc));
    }
    free(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  sprintf(auStack_110,s__s__cpn,rge_base_game->prog_info->campaign_dir);
  iVar1 = __findfirst(auStack_110,auStack_228);
  *(undefined4 *)(param_1 + 0xc) = 0;
  iVar5 = iVar1;
  while (iVar5 != -1) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    iVar5 = __findnext(iVar1,auStack_228);
  }
  sprintf(auStack_110,s__s__cpx,rge_base_game->prog_info->campaign_dir);
  iVar1 = __findfirst(auStack_110,auStack_228);
  iVar5 = iVar1;
  while (iVar5 != -1) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    iVar5 = __findnext(iVar1,auStack_228);
  }
  iVar5 = 0;
  if (*(int *)(param_1 + 0xc) < 1) {
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    uVar2 = calloc(*(int *)(param_1 + 0xc),4);
    *(undefined4 *)(param_1 + 0x10) = uVar2;
    sprintf(auStack_110,s__s__cpn,rge_base_game->prog_info->campaign_dir);
    iVar3 = __findfirst(auStack_110,auStack_228);
    iVar1 = iVar3;
    while (iVar1 != -1) {
      pRVar4 = (RGE_Campaign *)operator_new(0x20c);
      uStack_4 = 0;
      if (pRVar4 == (RGE_Campaign *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = RGE_Campaign::RGE_Campaign(pRVar4,acStack_214);
      }
      uStack_4 = 0xffffffff;
      *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar5 * 4) = uVar2;
      iVar5 = iVar5 + 1;
      iVar1 = __findnext(iVar3,auStack_228);
    }
    sprintf(auStack_110,s__s__cpx,rge_base_game->prog_info->campaign_dir);
    iVar1 = __findfirst(auStack_110,auStack_228);
    if (iVar1 != -1) {
      iVar5 = iVar5 << 2;
      while( true ) {
        pRVar4 = (RGE_Campaign *)operator_new(0x20c);
        uStack_4 = 1;
        if (pRVar4 == (RGE_Campaign *)0x0) {
          uVar2 = 0;
        }
        else {
          uVar2 = RGE_Campaign::RGE_Campaign(pRVar4,acStack_214);
        }
        uStack_4 = 0xffffffff;
        *(undefined4 *)(iVar5 + *(int *)(param_1 + 0x10)) = uVar2;
        iVar3 = __findnext(iVar1,auStack_228);
        if (iVar3 == -1) break;
        iVar5 = iVar5 + 4;
      }
    }
  }
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      RGE_Person_Info::rehook_campaigns
                (*(RGE_Person_Info **)(*(int *)(param_1 + 8) + iVar5 * 4),
                 *(RGE_Campaign ***)(param_1 + 0x10),*(long *)(param_1 + 0xc));
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 4));
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0044d70f
// Address: 0044d70f
undefined4 __thiscall FUN_0044d70f(int *param_1,char *param_2)
{
  undefined4 *puVar1;
  RGE_Person_Info *this;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d61b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  puVar1 = (undefined4 *)calloc(param_1[1] + 1,4);
  puVar5 = (undefined4 *)param_1[2];
  puVar6 = puVar1;
  for (uVar3 = param_1[1] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  free(param_1[2]);
  param_1[2] = (int)puVar1;
  this = (RGE_Person_Info *)operator_new(0x114);
  uStack_4 = 0;
  if (this == (RGE_Person_Info *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = RGE_Person_Info::RGE_Person_Info(this,param_2,(RGE_Campaign **)param_1[4],param_1[3]);
  }
  *(undefined4 *)(param_1[2] + param_1[1] * 4) = uVar2;
  *param_1 = param_1[1];
  iVar4 = param_1[1] + 1;
  param_1[1] = iVar4;
  *unaff_FS_OFFSET = uStack_c;
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_0044d7c3
// Address: 0044d7c3
undefined4 __thiscall FUN_0044d7c3(int *param_1,int param_2)
{
  if (param_2 < param_1[1]) {
    *param_1 = param_2;
    return 1;
  }
  *param_1 = -1;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044d7ed
// Address: 0044d7ed
uchar __thiscall FUN_0044d7ed(int *param_1,long param_2)
{
  int iVar1;
  uchar uVar2;
  
  iVar1 = *param_1;
  if ((iVar1 < param_1[1]) && (-1 < iVar1)) {
    uVar2 = RGE_Person_Info::set_current_campaign
                      (*(RGE_Person_Info **)(param_1[2] + iVar1 * 4),param_2);
    return uVar2;
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_0044d815
// Address: 0044d815
uchar __thiscall FUN_0044d815(int *param_1,long param_2)
{
  int iVar1;
  uchar uVar2;
  
  iVar1 = *param_1;
  if ((-1 < iVar1) && (iVar1 < param_1[1])) {
    uVar2 = RGE_Person_Info::set_current_scenario
                      (*(RGE_Person_Info **)(param_1[2] + iVar1 * 4),param_2);
    return uVar2;
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_0044d843
// Address: 0044d843
undefined4 __thiscall FUN_0044d843(undefined4 *param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  if (0 < (int)param_1[1]) {
    iVar1 = calloc(param_1[1],4);
    iVar3 = 0;
    *param_2 = iVar1;
    if (0 < (int)param_1[1]) {
      do {
        pcVar2 = RGE_Person_Info::get_name(*(RGE_Person_Info **)(param_1[2] + iVar3 * 4));
        getstring((char **)(*param_2 + iVar3 * 4),pcVar2);
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)param_1[1]);
    }
    *param_3 = *param_1;
  }
  return param_1[1];
}

// --------------------------------------------------

// Function: FUN_0044d8b3
// Address: 0044d8b3
int __thiscall FUN_0044d8b3(int *param_1,int *param_2,long *param_3)
{
  int iVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  
  if (0 < param_1[3]) {
    iVar1 = calloc(param_1[3],4);
    iVar4 = 0;
    *param_2 = iVar1;
    if (0 < param_1[3]) {
      do {
        pcVar2 = RGE_Campaign::get_name(*(RGE_Campaign **)(param_1[4] + iVar4 * 4));
        getstring((char **)(*param_2 + iVar4 * 4),pcVar2);
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_1[3]);
    }
    iVar1 = *param_1;
    if ((iVar1 < param_1[1]) && (-1 < iVar1)) {
      lVar3 = RGE_Person_Info::get_current_campaign(*(RGE_Person_Info **)(param_1[2] + iVar1 * 4));
      *param_3 = lVar3;
    }
  }
  return param_1[3];
}

// --------------------------------------------------

// Function: FUN_0044d939
// Address: 0044d939
long __thiscall FUN_0044d939(int *param_1,char ***param_2,long *param_3)
{
  int iVar1;
  long lVar2;
  
  iVar1 = *param_1;
  if ((iVar1 < param_1[1]) && (-1 < iVar1)) {
    lVar2 = RGE_Person_Info::get_current_scenario(*(RGE_Person_Info **)(param_1[2] + iVar1 * 4));
    *param_3 = lVar2;
    lVar2 = RGE_Person_Info::get_scenario_list
                      (*(RGE_Person_Info **)(param_1[2] + *param_1 * 4),param_2,param_3);
    return lVar2;
  }
  *param_3 = -1;
  return -1;
}

// --------------------------------------------------

// Function: FUN_0044d989
// Address: 0044d989
long __fastcall FUN_0044d989(int *param_1)
{
  int iVar1;
  long lVar2;
  
  iVar1 = *param_1;
  if ((iVar1 < param_1[1]) && (-1 < iVar1)) {
    lVar2 = RGE_Person_Info::get_current_scenario(*(RGE_Person_Info **)(param_1[2] + iVar1 * 4));
    return lVar2;
  }
  return -1;
}

// --------------------------------------------------

