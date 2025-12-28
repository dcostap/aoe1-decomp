// GLOBAL FUNCTIONS PART 6200
// Function: __set_osfhnd
// Address: 00554a30
// XREFS: FUN_00554bc4, __sopen
undefined4 __set_osfhnd(uint param_1,undefined4 param_2)
{
  int *piVar1;
  int iVar2;
  
  if (param_1 < __nhandle) {
    piVar1 = &___pioinfo + ((int)param_1 >> 5);
    iVar2 = (param_1 & 0x1f) * 8;
    if (*(int *)((&___pioinfo)[(int)param_1 >> 5] + iVar2) == -1) {
      if (___app_type == 1) {
        if (param_1 == 0) {
          SetStdHandle(0xfffffff6,param_2);
        }
        else {
          if (param_1 == 1) {
            SetStdHandle(0xfffffff5,param_2);
            *(undefined4 *)(*piVar1 + iVar2) = param_2;
            return 0;
          }
          if (param_1 == 2) {
            SetStdHandle(0xfffffff4,param_2);
            *(undefined4 *)(*piVar1 + iVar2) = param_2;
            return 0;
          }
        }
      }
      *(undefined4 *)(*piVar1 + iVar2) = param_2;
      return 0;
    }
  }
  _errno = 9;
  __doserrno = 0;
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00554ad3
// Address: 00554ad3
// XREFS: None
undefined4 FUN_00554ad3(uint param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < __nhandle) {
    iVar1 = (param_1 & 0x1f) * 8;
    if (((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar1) & 1) != 0) &&
       (*(int *)((&___pioinfo)[(int)param_1 >> 5] + iVar1) != -1)) {
      if (___app_type == 1) {
        if (param_1 == 0) {
          uVar2 = 0xfffffff6;
        }
        else if (param_1 == 1) {
          uVar2 = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00554b4a;
          uVar2 = 0xfffffff4;
        }
        SetStdHandle(uVar2,0);
      }
LAB_00554b4a:
      *(undefined4 *)((&___pioinfo)[(int)param_1 >> 5] + iVar1) = 0xffffffff;
      return 0;
    }
  }
  _errno = 9;
  __doserrno = 0;
  return 0xffffffff;
}

// --------------------------------------------------

// Function: __free_osfhnd
// Address: 00554ae0
// XREFS: close
undefined4 __free_osfhnd(uint param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < __nhandle) {
    iVar1 = (param_1 & 0x1f) * 8;
    if (((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar1) & 1) != 0) &&
       (*(int *)((&___pioinfo)[(int)param_1 >> 5] + iVar1) != -1)) {
      if (___app_type == 1) {
        if (param_1 == 0) {
          uVar2 = 0xfffffff6;
        }
        else if (param_1 == 1) {
          uVar2 = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00554b4a;
          uVar2 = 0xfffffff4;
        }
        SetStdHandle(uVar2,0);
      }
LAB_00554b4a:
      *(undefined4 *)((&___pioinfo)[(int)param_1 >> 5] + iVar1) = 0xffffffff;
      return 0;
    }
  }
  _errno = 9;
  __doserrno = 0;
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00554b74
// Address: 00554b74
// XREFS: None
undefined4 FUN_00554b74(uint param_1)
{
  if ((param_1 < __nhandle) &&
     ((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    return *(undefined4 *)((&___pioinfo)[(int)param_1 >> 5] + (param_1 & 0x1f) * 8);
  }
  _errno = 9;
  __doserrno = 0;
  return 0xffffffff;
}

// --------------------------------------------------

// Function: __get_osfhandle
// Address: 00554b80
// XREFS: __chsize, __commit, close, lseek
undefined4 __get_osfhandle(uint param_1)
{
  if ((param_1 < __nhandle) &&
     ((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    return *(undefined4 *)((&___pioinfo)[(int)param_1 >> 5] + (param_1 & 0x1f) * 8);
  }
  _errno = 9;
  __doserrno = 0;
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00554bc4
// Address: 00554bc4
// XREFS: None
uint FUN_00554bc4(undefined4 param_1,uint param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  
  bVar4 = 0;
  if ((param_2 & 8) != 0) {
    bVar4 = 0x20;
  }
  if ((param_2 & 0x4000) != 0) {
    bVar4 = bVar4 | 0x80;
  }
  iVar1 = GetFileType(param_1);
  if (iVar1 == 0) {
    uVar2 = GetLastError();
    __dosmaperr(uVar2);
    return 0xffffffff;
  }
  if (iVar1 == 2) {
    bVar4 = bVar4 | 0x40;
  }
  else if (iVar1 == 3) {
    bVar4 = bVar4 | 8;
  }
  uVar3 = __alloc_osfhnd();
  if (uVar3 == 0xffffffff) {
    _errno = 0x18;
    __doserrno = 0;
    return 0xffffffff;
  }
  __set_osfhnd(uVar3,param_1);
  *(byte *)((&___pioinfo)[(int)uVar3 >> 5] + 4 + (uVar3 & 0x1f) * 8) = bVar4 | 1;
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_00554c6c
// Address: 00554c6c
// XREFS: None
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int FUN_00554c6c(uint param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 auStack_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x554c7a;
  iVar5 = 0;
  if ((param_1 < __nhandle) &&
     ((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    iVar1 = lseek(param_1,0,1);
    if ((iVar1 != -1) && (iVar2 = lseek(param_1,0,2), iVar2 != -1)) {
      iVar2 = param_2 - iVar2;
      if (iVar2 < 1) {
        if (iVar2 < 0) {
          lseek(param_1,param_2,0);
          uVar3 = __get_osfhandle(param_1);
          iVar5 = SetEndOfFile(uVar3);
          iVar5 = (iVar5 != 0) - 1;
          if (iVar5 == -1) {
            _errno = 0xd;
            __doserrno = GetLastError();
          }
        }
        lseek(param_1,iVar1,0);
        return iVar5;
      }
      puVar6 = auStack_1000;
      for (iVar4 = 0x400; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      uVar3 = __setmode(param_1,0x8000);
      while( true ) {
        iVar4 = 0x1000;
        if (iVar2 < 0x1000) {
          iVar4 = iVar2;
        }
        iVar4 = write(param_1,auStack_1000,iVar4);
        if (iVar4 == -1) break;
        iVar2 = iVar2 - iVar4;
        if (iVar2 < 1) {
LAB_00554d51:
          __setmode(param_1,uVar3);
          lseek(param_1,iVar1,0);
          return iVar5;
        }
      }
      if (__doserrno == 5) {
        _errno = 0xd;
      }
      iVar5 = -1;
      goto LAB_00554d51;
    }
  }
  else {
    _errno = 9;
  }
  return -1;
}

// --------------------------------------------------

// Function: __chsize
// Address: 00554c70
// XREFS: __sopen
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int __chsize(uint param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x554c7a;
  iVar5 = 0;
  if ((param_1 < __nhandle) &&
     ((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    iVar1 = lseek(param_1,0,1);
    if ((iVar1 != -1) && (iVar2 = lseek(param_1,0,2), iVar2 != -1)) {
      iVar2 = param_2 - iVar2;
      if (iVar2 < 1) {
        if (iVar2 < 0) {
          lseek(param_1,param_2,0);
          uVar3 = __get_osfhandle(param_1);
          iVar5 = SetEndOfFile(uVar3);
          iVar5 = (iVar5 != 0) - 1;
          if (iVar5 == -1) {
            _errno = 0xd;
            __doserrno = GetLastError();
          }
        }
        lseek(param_1,iVar1,0);
        return iVar5;
      }
      puVar6 = local_1000;
      for (iVar4 = 0x400; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      uVar3 = __setmode(param_1,0x8000);
      while( true ) {
        iVar4 = 0x1000;
        if (iVar2 < 0x1000) {
          iVar4 = iVar2;
        }
        iVar4 = write(param_1,local_1000,iVar4);
        if (iVar4 == -1) break;
        iVar2 = iVar2 - iVar4;
        if (iVar2 < 1) {
LAB_00554d51:
          __setmode(param_1,uVar3);
          lseek(param_1,iVar1,0);
          return iVar5;
        }
      }
      if (__doserrno == 5) {
        _errno = 0xd;
      }
      iVar5 = -1;
      goto LAB_00554d51;
    }
  }
  else {
    _errno = 9;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_00554dea
// Address: 00554dea
// XREFS: None
undefined4 __fastcall
FUN_00554dea(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)
{
  byte *in_EAX;
  int iVar1;
  int extraout_ECX;
  undefined1 *puVar2;
  byte *unaff_ESI;
  int iVar3;
  int local_c;
  undefined4 local_8;
  
  *unaff_ESI = *unaff_ESI ^ (byte)((uint)param_2 >> 8) ^ *in_EAX;
  puVar2 = &stack0xfffffffc;
  if ((*(uint *)(param_3 + 4) & 6) == 0) {
    local_c = param_3;
    local_8 = param_5;
    *(int **)(param_4 + -4) = &local_c;
    iVar1 = *(int *)(param_4 + 8);
    for (iVar3 = *(int *)(param_4 + 0xc); iVar3 != -1; iVar3 = *(int *)(iVar1 + iVar3 * 0xc)) {
      if (*(int *)(iVar1 + 4 + iVar3 * 0xc) != 0) {
        iVar1 = (**(code **)(iVar1 + 4 + iVar3 * 0xc))();
        param_4 = *(int *)(puVar2 + 0xc);
        if (iVar1 != 0) {
          if (iVar1 < 0) {
            return 0;
          }
          iVar1 = *(int *)(param_4 + 8);
          __global_unwind2(param_4);
          puVar2 = (undefined1 *)(param_4 + 0x10);
          __local_unwind2(param_4,iVar3);
          __NLG_Notify(1);
          *(undefined4 *)(param_4 + 0xc) = *(undefined4 *)(iVar1 + extraout_ECX * 4);
          (**(code **)(iVar1 + 8 + extraout_ECX * 4))();
        }
      }
      iVar1 = *(int *)(param_4 + 8);
    }
  }
  else {
    __local_unwind2(param_4,0xffffffff,&stack0xfffffffc,&stack0xfffffffc);
  }
  return 1;
}

// --------------------------------------------------

// Function: __seh_longjmp_unwind@4
// Address: 00554eb5
// XREFS: None
void __seh_longjmp_unwind_4(int param_1)
{
  __local_unwind2(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
  return;
}

// --------------------------------------------------

// Function: __fltin
// Address: 00554ed0
// XREFS: atof
undefined * __fltin(int param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined1 local_c [12];
  
  iVar1 = param_1;
  uVar4 = 0;
  uVar2 = ___strgtold12(local_c,&param_1,param_1,0,0,0,0);
  if ((uVar2 & 4) == 0) {
    iVar3 = __ld12tod(local_c,&local_14);
    if (((uVar2 & 2) != 0) || (iVar3 == 1)) {
      uVar4 = 0x80;
    }
    if (((uVar2 & 1) != 0) || (iVar3 == 2)) {
      uVar4 = uVar4 | 0x100;
    }
  }
  else {
    uVar4 = 0x200;
    local_14 = 0;
    uStack_10 = 0;
  }
  *(uint *)PTR_DAT_00592454 = uVar4;
  *(int *)(PTR_DAT_00592454 + 4) = param_1 - iVar1;
  *(ulonglong *)(PTR_DAT_00592454 + 0x10) = CONCAT44(uStack_10,local_14);
  return PTR_DAT_00592454;
}

// --------------------------------------------------

// Function: FUN_00554f71
// Address: 00554f71
// XREFS: None
int FUN_00554f71(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                undefined4 param_6,int param_7)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  if (DAT_008882b0 == 0) {
    iVar1 = LCMapStringW(0,0x100,L"",1,0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_008882b0 = 2;
    }
    else {
      DAT_008882b0 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_00555190(param_3,param_4);
  }
  if (DAT_008882b0 == 1) {
    iVar1 = LCMapStringW(param_1,param_2,param_3,param_4,param_5,param_6);
    return iVar1;
  }
  if (DAT_008882b0 != 2) {
    return DAT_008882b0;
  }
  if (param_7 == 0) {
    param_7 = ___lc_codepage;
  }
  uVar8 = 0;
  uVar7 = 0x220;
  iVar1 = param_7;
  iVar2 = WideCharToMultiByte(param_7,0x220,param_3,param_4,0,0,0,0);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = malloc(iVar2);
  if (iVar3 == 0) {
    return 0;
  }
  uVar6 = 0;
  iVar5 = iVar2;
  iVar4 = WideCharToMultiByte(param_7,0x220,uVar8,param_4,iVar3,iVar2,0,0);
  if ((((iVar4 != 0) && (iVar4 = LCMapStringA(iVar5,uVar6,iVar3,iVar2,0,0), iVar4 != 0)) &&
      (iVar1 = malloc(iVar4), iVar1 != 0)) &&
     (iVar2 = LCMapStringA(iVar5,uVar6,iVar3,iVar2,iVar1,iVar4), iVar2 != 0)) {
    if ((uVar6 & 0x400) == 0) {
      if (param_3 == 0) {
        iVar4 = MultiByteToWideChar(param_7,1,iVar1,iVar4,0,0);
      }
      else {
        iVar4 = MultiByteToWideChar(param_7,1,iVar1,iVar4,uVar7,param_3);
      }
      if (iVar4 == 0) goto LAB_0055516a;
    }
    else if (param_3 != 0) {
      if (iVar4 <= param_3) {
        param_3 = iVar4;
      }
      strncpy(uVar7,iVar1,param_3);
    }
    free(iVar3);
    free(iVar1);
    return iVar4;
  }
LAB_0055516a:
  free(iVar3);
  free(iVar1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00555187
// Address: 00555187
// XREFS: None
int FUN_00555187(short *param_1,int param_2)
{
  short *psVar1;
  int iVar2;
  
  psVar1 = param_1;
  iVar2 = param_2;
  if (param_2 != 0) {
    do {
      iVar2 = iVar2 + -1;
      if (*psVar1 == 0) goto LAB_005551b9;
      psVar1 = psVar1 + 1;
    } while (iVar2 != 0);
  }
  if (*psVar1 != 0) {
    return param_2;
  }
LAB_005551b9:
  return (int)psVar1 - (int)param_1 >> 1;
}

// --------------------------------------------------

// Function: FUN_00555190
// Address: 00555190
// XREFS: FUN_00554f71
int FUN_00555190(short *param_1,int param_2)
{
  short *psVar1;
  int iVar2;
  
  psVar1 = param_1;
  iVar2 = param_2;
  if (param_2 != 0) {
    do {
      iVar2 = iVar2 + -1;
      if (*psVar1 == 0) goto LAB_005551b9;
      psVar1 = psVar1 + 1;
    } while (iVar2 != 0);
  }
  if (*psVar1 != 0) {
    return param_2;
  }
LAB_005551b9:
  return (int)psVar1 - (int)param_1 >> 1;
}

// --------------------------------------------------

// Function: FUN_005551c5
// Address: 005551c5
// XREFS: None
int FUN_005551c5(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                undefined4 param_6,uint param_7)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_ESI;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  
  if (DAT_008882b4 == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_008882b4 = 1;
    }
    else {
      DAT_008882b4 = 2;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_005553f0(param_3,param_4);
  }
  if (DAT_008882b4 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,param_5,param_6);
    return iVar1;
  }
  if (DAT_008882b4 != 1) {
    return DAT_008882b4;
  }
  if (param_7 == 0) {
    param_7 = ___lc_codepage;
  }
  uVar8 = 0;
  iVar7 = 0;
  uVar6 = param_7;
  iVar1 = param_4;
  iVar2 = MultiByteToWideChar(param_7,9,param_3,param_4,0,0);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = malloc(iVar2 * 2);
  if (iVar3 == 0) {
    return 0;
  }
  iVar5 = iVar2;
  iVar4 = MultiByteToWideChar(param_7,1,unaff_ESI,param_4,iVar3,iVar2);
  if ((iVar4 != 0) && (iVar4 = LCMapStringW(iVar5,uVar6,iVar3,iVar2,0,0), iVar4 != 0)) {
    if ((uVar6 & 0x400) == 0) {
      param_3 = malloc(iVar4 * 2);
      if ((param_3 == 0) ||
         (iVar2 = LCMapStringW(iVar5,uVar6,iVar3,iVar2,param_3,iVar4), iVar2 == 0))
      goto LAB_005553cf;
      if (iVar7 == 0) {
        iVar4 = WideCharToMultiByte(uVar8,0x220,param_3,iVar4,0,0,0,0);
        iVar1 = iVar4;
      }
      else {
        iVar4 = WideCharToMultiByte(uVar8,0x220,param_3,iVar4,iVar1,iVar7,0,0);
        iVar1 = iVar4;
      }
    }
    else {
      if (iVar7 == 0) goto LAB_00555334;
      if (iVar7 < iVar4) goto LAB_005553cf;
      iVar1 = LCMapStringW(iVar5,uVar6,iVar3,iVar2,iVar1,iVar7);
    }
    if (iVar1 != 0) {
LAB_00555334:
      free(iVar3);
      free(param_3);
      return iVar4;
    }
  }
LAB_005553cf:
  free(iVar3);
  free(param_3);
  return 0;
}

// --------------------------------------------------

// Function: ___crtLCMapStringA
// Address: 005551d0
// XREFS: __mbctoupper, __mbsupr, strupr, tolower, toupper
int ___crtLCMapStringA(undefined4 param_1,undefined4 param_2,int param_3,int param_4,
                      undefined4 param_5,undefined4 param_6,uint param_7)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_ESI;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  
  if (DAT_008882b4 == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_008882b4 = 1;
    }
    else {
      DAT_008882b4 = 2;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_005553f0(param_3,param_4);
  }
  if (DAT_008882b4 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,param_5,param_6);
    return iVar1;
  }
  if (DAT_008882b4 != 1) {
    return DAT_008882b4;
  }
  if (param_7 == 0) {
    param_7 = ___lc_codepage;
  }
  uVar8 = 0;
  iVar7 = 0;
  uVar6 = param_7;
  iVar1 = param_4;
  iVar2 = MultiByteToWideChar(param_7,9,param_3,param_4,0,0);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = malloc(iVar2 * 2);
  if (iVar3 == 0) {
    return 0;
  }
  iVar5 = iVar2;
  iVar4 = MultiByteToWideChar(param_7,1,unaff_ESI,param_4,iVar3,iVar2);
  if ((iVar4 != 0) && (iVar4 = LCMapStringW(iVar5,uVar6,iVar3,iVar2,0,0), iVar4 != 0)) {
    if ((uVar6 & 0x400) == 0) {
      param_3 = malloc(iVar4 * 2);
      if ((param_3 == 0) ||
         (iVar2 = LCMapStringW(iVar5,uVar6,iVar3,iVar2,param_3,iVar4), iVar2 == 0))
      goto LAB_005553cf;
      if (iVar7 == 0) {
        iVar4 = WideCharToMultiByte(uVar8,0x220,param_3,iVar4,0,0,0,0);
        iVar1 = iVar4;
      }
      else {
        iVar4 = WideCharToMultiByte(uVar8,0x220,param_3,iVar4,iVar1,iVar7,0,0);
        iVar1 = iVar4;
      }
    }
    else {
      if (iVar7 == 0) goto LAB_00555334;
      if (iVar7 < iVar4) goto LAB_005553cf;
      iVar1 = LCMapStringW(iVar5,uVar6,iVar3,iVar2,iVar1,iVar7);
    }
    if (iVar1 != 0) {
LAB_00555334:
      free(iVar3);
      free(param_3);
      return iVar4;
    }
  }
LAB_005553cf:
  free(iVar3);
  free(param_3);
  return 0;
}

// --------------------------------------------------

// Function: FUN_005553ec
// Address: 005553ec
// XREFS: None
int FUN_005553ec(char *param_1,int param_2)
{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = param_1;
  iVar2 = param_2;
  if (param_2 != 0) {
    do {
      iVar2 = iVar2 + -1;
      if (*pcVar1 == '\0') break;
      pcVar1 = pcVar1 + 1;
    } while (iVar2 != 0);
  }
  if (*pcVar1 == '\0') {
    return (int)pcVar1 - (int)param_1;
  }
  return param_2;
}

// --------------------------------------------------

// Function: FUN_005553f0
// Address: 005553f0
// XREFS: ___crtLCMapStringA
int FUN_005553f0(char *param_1,int param_2)
{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = param_1;
  iVar2 = param_2;
  if (param_2 != 0) {
    do {
      iVar2 = iVar2 + -1;
      if (*pcVar1 == '\0') break;
      pcVar1 = pcVar1 + 1;
    } while (iVar2 != 0);
  }
  if (*pcVar1 == '\0') {
    return (int)pcVar1 - (int)param_1;
  }
  return param_2;
}

// --------------------------------------------------

// Function: FUN_0055541f
// Address: 0055541f
// XREFS: None
uint FUN_0055541f(uint param_1)
{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint auStack_8 [2];
  
  uVar1 = param_1;
  if (param_1 < 0x100) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      return param_1 - 0x20;
    }
  }
  else {
    bVar2 = (byte)(param_1 >> 8);
    param_1 = CONCAT31(CONCAT21(param_1._2_2_,(char)param_1),bVar2);
    if (((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) != 0) &&
       (iVar3 = ___crtLCMapStringA(___mblcid,0x200,&param_1,2,auStack_8,2,___mbcodepage), iVar3 != 0
       )) {
      return (auStack_8[0] & 0xff) * 0x100 + (auStack_8[0] >> 8 & 0xff);
    }
  }
  return uVar1;
}

// --------------------------------------------------

// Function: __mbctoupper
// Address: 00555420
// XREFS: __chdir
uint __mbctoupper(uint param_1)
{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint local_8 [2];
  
  uVar1 = param_1;
  if (param_1 < 0x100) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      return param_1 - 0x20;
    }
  }
  else {
    bVar2 = (byte)(param_1 >> 8);
    param_1 = CONCAT31(CONCAT21(param_1._2_2_,(char)param_1),bVar2);
    if (((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) != 0) &&
       (iVar3 = ___crtLCMapStringA(___mblcid,0x200,&param_1,2,local_8,2,___mbcodepage), iVar3 != 0))
{
      return (local_8[0] & 0xff) * 0x100 + (local_8[0] >> 8 & 0xff);
    }
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_005554ae
// Address: 005554ae
// XREFS: None
byte * FUN_005554ae(byte *param_1,byte *param_2,uint param_3)
{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  
  if (___mbcodepage == 0) {
    pbVar3 = (byte *)strncpy(param_1,param_2,param_3);
    return pbVar3;
  }
  uVar4 = param_3;
  pbVar3 = param_1;
  pbVar5 = param_1;
  if (param_3 != 0) {
    do {
      bVar1 = *param_2;
      param_3 = uVar4 - 1;
      bVar2 = *(byte *)((int)&__mbctype + bVar1 + 1);
      *pbVar5 = bVar1;
      if ((bVar2 & 4) == 0) {
        pbVar3 = pbVar5 + 1;
        param_2 = param_2 + 1;
        if (bVar1 == 0) goto LAB_00555523;
      }
      else {
        pbVar3 = pbVar5 + 1;
        if (param_3 == 0) {
          *pbVar5 = 0;
          goto LAB_00555523;
        }
        bVar1 = param_2[1];
        param_3 = uVar4 - 2;
        *pbVar3 = bVar1;
        pbVar3 = pbVar5 + 2;
        param_2 = param_2 + 2;
        if (bVar1 == 0) {
          *pbVar5 = 0;
          goto LAB_00555523;
        }
      }
      uVar4 = param_3;
      pbVar5 = pbVar3;
    } while (param_3 != 0);
    param_3 = 0;
  }
LAB_00555523:
  if (param_3 != 0) {
    for (uVar4 = param_3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      pbVar3[0] = 0;
      pbVar3[1] = 0;
      pbVar3[2] = 0;
      pbVar3[3] = 0;
      pbVar3 = pbVar3 + 4;
    }
    for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
      *pbVar3 = 0;
      pbVar3 = pbVar3 + 1;
    }
  }
  return param_1;
}

// --------------------------------------------------

// Function: __mbsnbcpy
// Address: 005554b0
// XREFS: __splitpath
byte * __mbsnbcpy(byte *param_1,byte *param_2,uint param_3)
{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  
  if (___mbcodepage == 0) {
    pbVar3 = (byte *)strncpy(param_1,param_2,param_3);
    return pbVar3;
  }
  uVar4 = param_3;
  pbVar3 = param_1;
  pbVar5 = param_1;
  if (param_3 != 0) {
    do {
      bVar1 = *param_2;
      param_3 = uVar4 - 1;
      bVar2 = *(byte *)((int)&__mbctype + bVar1 + 1);
      *pbVar5 = bVar1;
      if ((bVar2 & 4) == 0) {
        pbVar3 = pbVar5 + 1;
        param_2 = param_2 + 1;
        if (bVar1 == 0) goto LAB_00555523;
      }
      else {
        pbVar3 = pbVar5 + 1;
        if (param_3 == 0) {
          *pbVar5 = 0;
          goto LAB_00555523;
        }
        bVar1 = param_2[1];
        param_3 = uVar4 - 2;
        *pbVar3 = bVar1;
        pbVar3 = pbVar5 + 2;
        param_2 = param_2 + 2;
        if (bVar1 == 0) {
          *pbVar5 = 0;
          goto LAB_00555523;
        }
      }
      uVar4 = param_3;
      pbVar5 = pbVar3;
    } while (param_3 != 0);
    param_3 = 0;
  }
LAB_00555523:
  if (param_3 != 0) {
    for (uVar4 = param_3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      pbVar3[0] = 0;
      pbVar3[1] = 0;
      pbVar3[2] = 0;
      pbVar3[3] = 0;
      pbVar3 = pbVar3 + 4;
    }
    for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
      *pbVar3 = 0;
      pbVar3 = pbVar3 + 1;
    }
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00555543
// Address: 00555543
// XREFS: None
float10 FUN_00555543(double param_1)
{
  return (float10)ROUND(param_1);
}

// --------------------------------------------------

// Function: __frnd
// Address: 00555550
// XREFS: ceil, floor
float10 __frnd(double param_1)
{
  return (float10)ROUND(param_1);
}

// --------------------------------------------------

// Function: FUN_00555565
// Address: 00555565
// XREFS: None
float10 FUN_00555565(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  float10 fVar1;
  
  if (__matherr_flag == 0) {
    fVar1 = (float10)__umatherr(1,param_1,param_2,param_3,0,0,param_2,param_3,param_4);
    return fVar1;
  }
  _errno = 0x21;
  __ctrlfp(param_4,0xffff);
  return (float10)(double)CONCAT44(param_3,param_2);
}

// --------------------------------------------------

// Function: __handle_qnan1
// Address: 00555570
// XREFS: ceil, floor
float10 __handle_qnan1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  float10 fVar1;
  
  if (__matherr_flag == 0) {
    fVar1 = (float10)__umatherr(1,param_1,param_2,param_3,0,0,param_2,param_3,param_4);
    return fVar1;
  }
  _errno = 0x21;
  __ctrlfp(param_4,0xffff);
  return (float10)(double)CONCAT44(param_3,param_2);
}

// --------------------------------------------------

// Function: FUN_005555bf
// Address: 005555bf
// XREFS: None
float10 FUN_005555bf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6)
{
  double dVar1;
  float10 fVar2;
  
  dVar1 = (double)CONCAT44(param_5,param_4) + (double)CONCAT44(param_3,param_2);
  if (__matherr_flag == 0) {
    fVar2 = (float10)__umatherr(1,param_1,param_2,param_3,param_4,param_5,dVar1,param_6);
    return fVar2;
  }
  _errno = 0x21;
  __ctrlfp(param_6,0xffff);
  return (float10)dVar1;
}

// --------------------------------------------------

// Function: FUN_00555632
// Address: 00555632
// XREFS: None
float10 FUN_00555632(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7)
{
  int iVar1;
  float10 fVar2;
  undefined1 auStack_58 [56];
  uint uStack_20;
  
  iVar1 = __handle_exc(param_1,&param_5,param_7);
  if (iVar1 == 0) {
    uStack_20 = uStack_20 & 0xfffffffe;
    __raise_exc(auStack_58,&param_7,param_1,param_2,&param_3,&param_5);
  }
  iVar1 = __errcode(param_1);
  if ((__matherr_flag == 0) && (iVar1 != 0)) {
    fVar2 = (float10)__umatherr(iVar1,param_2,param_3,param_4,0,0,param_5,param_6,param_7);
    return fVar2;
  }
  __set_errno(iVar1);
  __ctrlfp(param_7,0xffff);
  return (float10)(double)CONCAT44(param_6,param_5);
}

// --------------------------------------------------

// Function: __except1
// Address: 00555640
// XREFS: ceil, floor
float10 __except1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)
{
  int iVar1;
  float10 fVar2;
  undefined1 local_58 [56];
  uint local_20;
  
  iVar1 = __handle_exc(param_1,&param_5,param_7);
  if (iVar1 == 0) {
    local_20 = local_20 & 0xfffffffe;
    __raise_exc(local_58,&param_7,param_1,param_2,&param_3,&param_5);
  }
  iVar1 = __errcode(param_1);
  if ((__matherr_flag == 0) && (iVar1 != 0)) {
    fVar2 = (float10)__umatherr(iVar1,param_2,param_3,param_4,0,0,param_5,param_6,param_7);
    return fVar2;
  }
  __set_errno(iVar1);
  __ctrlfp(param_7,0xffff);
  return (float10)(double)CONCAT44(param_6,param_5);
}

// --------------------------------------------------

// Function: FUN_005556fc
// Address: 005556fc
// XREFS: None
float10 FUN_005556fc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                    undefined4 param_9)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  undefined1 local_58 [40];
  undefined4 local_30;
  undefined4 local_2c;
  uint local_20;
  
  iVar3 = __handle_exc(param_1,&param_7,param_9);
  uVar2 = param_6;
  uVar1 = param_5;
  if (iVar3 == 0) {
    local_20 = local_20 & 0xffffffe3 | 3;
    local_30 = param_5;
    local_2c = param_6;
    __raise_exc(local_58,&param_9,param_1,param_2,&param_3,&param_7);
  }
  iVar3 = __errcode(param_1);
  if ((__matherr_flag == 0) && (iVar3 != 0)) {
    fVar4 = (float10)__umatherr(iVar3,param_2,param_3,param_4,uVar1,uVar2,param_7,param_8,param_9);
    return fVar4;
  }
  __set_errno(iVar3);
  __ctrlfp(param_9,0xffff);
  return (float10)(double)CONCAT44(param_8,param_7);
}

// --------------------------------------------------

// Function: FUN_005557ee
// Address: 005557ee
// XREFS: None
void FUN_005557ee(uint *param_1,uint *param_2,byte param_3,uint param_4,uint *param_5,uint *param_6)
{
  uint *puVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  uint *puVar5;
  uint *unaff_ESI;
  
  puVar1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  puVar5 = param_1;
  if ((param_3 & 0x10) != 0) {
    param_1[1] = param_1[1] | 1;
    puVar5 = (uint *)0xc000008f;
  }
  if ((param_3 & 2) != 0) {
    puVar5 = (uint *)0xc0000093;
    param_1[1] = param_1[1] | 2;
  }
  if ((param_3 & 1) != 0) {
    puVar5 = (uint *)0xc0000091;
    param_1[1] = param_1[1] | 4;
  }
  if ((param_3 & 4) != 0) {
    puVar5 = (uint *)0xc000008e;
    param_1[1] = param_1[1] | 8;
  }
  if ((param_3 & 8) != 0) {
    puVar5 = (uint *)0xc0000090;
    param_1[1] = param_1[1] | 0x10;
  }
  param_1[2] = (~*param_2 & 1) << 4 | param_1[2] & 0xffffffef;
  param_1[2] = (~*param_2 & 4) << 1 | param_1[2] & 0xfffffff7;
  param_1[2] = ~*param_2 >> 1 & 4 | param_1[2] & 0xfffffffb;
  param_1[2] = ~*param_2 >> 3 & 2 | param_1[2] & 0xfffffffd;
  param_1[2] = ~*param_2 >> 5 & 1 | param_1[2] & 0xfffffffe;
  bVar3 = __statfp();
  puVar2 = param_6;
  if ((bVar3 & 1) != 0) {
    param_1[3] = param_1[3] | 0x10;
  }
  if ((bVar3 & 4) != 0) {
    param_1[3] = param_1[3] | 8;
  }
  if ((bVar3 & 8) != 0) {
    param_1[3] = param_1[3] | 4;
  }
  if ((bVar3 & 0x10) != 0) {
    param_1[3] = param_1[3] | 2;
  }
  if ((bVar3 & 0x20) != 0) {
    param_1[3] = param_1[3] | 1;
  }
  uVar4 = *puVar1 & 0xc00;
  if (uVar4 < 0x401) {
    if (uVar4 == 0x400) {
      *param_1 = *param_1 & 0xfffffffd | 1;
    }
    else if (uVar4 == 0) {
      *param_1 = *param_1 & 0xfffffffc;
    }
  }
  else if (uVar4 == 0x800) {
    *param_1 = *param_1 & 0xfffffffe | 2;
  }
  else if (uVar4 == 0xc00) {
    *param_1 = *param_1 | 3;
  }
  uVar4 = *puVar1 & 0x300;
  if (uVar4 == 0) {
    *param_1 = *param_1 & 0xffffffeb | 8;
  }
  else if (uVar4 == 0x200) {
    *param_1 = *param_1 & 0xffffffe7 | 4;
  }
  else if (uVar4 == 0x300) {
    *param_1 = *param_1 & 0xffffffe3;
  }
  *param_1 = *param_1 & 0xfffe001f | (param_4 & 0xfff) << 5;
  param_1[8] = param_1[8] | 1;
  param_1[8] = param_1[8] & 0xffffffe3 | 2;
  param_1[4] = *param_5;
  param_1[5] = param_5[1];
  param_1[0x14] = param_1[0x14] | 1;
  param_1[0x14] = param_1[0x14] & 0xffffffe3 | 2;
  param_1[0x10] = *param_6;
  param_1[0x11] = param_6[1];
  __clrfp();
  RaiseException(puVar5,0,1,&param_1);
  if ((unaff_ESI[2] & 0x10) != 0) {
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  if ((unaff_ESI[2] & 8) != 0) {
    *puVar1 = *puVar1 & 0xfffffffb;
  }
  if ((unaff_ESI[2] & 4) != 0) {
    *puVar1 = *puVar1 & 0xfffffff7;
  }
  if ((unaff_ESI[2] & 2) != 0) {
    *puVar1 = *puVar1 & 0xffffffef;
  }
  if ((unaff_ESI[2] & 1) != 0) {
    *puVar1 = *puVar1 & 0xffffffdf;
  }
  switch(*unaff_ESI & 3) {
  case 0:
    uVar4 = *puVar1 & 0xfffff3ff;
    break;
  case 1:
    *puVar1 = *puVar1 & 0xfffff7ff | 0x400;
    goto switchD_00555a8b_default;
  case 2:
    uVar4 = *puVar1 & 0xfffffbff | 0x800;
    break;
  case 3:
    uVar4 = *puVar1 | 0xc00;
    break;
  default:
    goto switchD_00555a8b_default;
  }
  *puVar1 = uVar4;
switchD_00555a8b_default:
  uVar4 = *unaff_ESI >> 2 & 7;
  if (uVar4 == 0) {
    *puVar1 = *puVar1 & 0xfffff3ff | 0x300;
  }
  else {
    if (uVar4 == 1) {
      *puVar1 = *puVar1 & 0xfffff3ff | 0x200;
      *puVar2 = unaff_ESI[0x10];
      puVar2[1] = unaff_ESI[0x11];
      return;
    }
    if (uVar4 == 2) {
      *puVar1 = *puVar1 & 0xfffff3ff;
      *puVar2 = unaff_ESI[0x10];
      puVar2[1] = unaff_ESI[0x11];
      return;
    }
  }
  *puVar2 = unaff_ESI[0x10];
  puVar2[1] = unaff_ESI[0x11];
  return;
}

// --------------------------------------------------

// Function: __raise_exc
// Address: 005557f0
// XREFS: FUN_005556fc, __except1
void __raise_exc(uint *param_1,uint *param_2,byte param_3,uint param_4,uint *param_5,uint *param_6)
{
  uint *puVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  uint *puVar5;
  uint *unaff_ESI;
  
  puVar1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  puVar5 = param_1;
  if ((param_3 & 0x10) != 0) {
    param_1[1] = param_1[1] | 1;
    puVar5 = (uint *)0xc000008f;
  }
  if ((param_3 & 2) != 0) {
    puVar5 = (uint *)0xc0000093;
    param_1[1] = param_1[1] | 2;
  }
  if ((param_3 & 1) != 0) {
    puVar5 = (uint *)0xc0000091;
    param_1[1] = param_1[1] | 4;
  }
  if ((param_3 & 4) != 0) {
    puVar5 = (uint *)0xc000008e;
    param_1[1] = param_1[1] | 8;
  }
  if ((param_3 & 8) != 0) {
    puVar5 = (uint *)0xc0000090;
    param_1[1] = param_1[1] | 0x10;
  }
  param_1[2] = (~*param_2 & 1) << 4 | param_1[2] & 0xffffffef;
  param_1[2] = (~*param_2 & 4) << 1 | param_1[2] & 0xfffffff7;
  param_1[2] = ~*param_2 >> 1 & 4 | param_1[2] & 0xfffffffb;
  param_1[2] = ~*param_2 >> 3 & 2 | param_1[2] & 0xfffffffd;
  param_1[2] = ~*param_2 >> 5 & 1 | param_1[2] & 0xfffffffe;
  bVar3 = __statfp();
  puVar2 = param_6;
  if ((bVar3 & 1) != 0) {
    param_1[3] = param_1[3] | 0x10;
  }
  if ((bVar3 & 4) != 0) {
    param_1[3] = param_1[3] | 8;
  }
  if ((bVar3 & 8) != 0) {
    param_1[3] = param_1[3] | 4;
  }
  if ((bVar3 & 0x10) != 0) {
    param_1[3] = param_1[3] | 2;
  }
  if ((bVar3 & 0x20) != 0) {
    param_1[3] = param_1[3] | 1;
  }
  uVar4 = *puVar1 & 0xc00;
  if (uVar4 < 0x401) {
    if (uVar4 == 0x400) {
      *param_1 = *param_1 & 0xfffffffd | 1;
    }
    else if (uVar4 == 0) {
      *param_1 = *param_1 & 0xfffffffc;
    }
  }
  else if (uVar4 == 0x800) {
    *param_1 = *param_1 & 0xfffffffe | 2;
  }
  else if (uVar4 == 0xc00) {
    *param_1 = *param_1 | 3;
  }
  uVar4 = *puVar1 & 0x300;
  if (uVar4 == 0) {
    *param_1 = *param_1 & 0xffffffeb | 8;
  }
  else if (uVar4 == 0x200) {
    *param_1 = *param_1 & 0xffffffe7 | 4;
  }
  else if (uVar4 == 0x300) {
    *param_1 = *param_1 & 0xffffffe3;
  }
  *param_1 = *param_1 & 0xfffe001f | (param_4 & 0xfff) << 5;
  param_1[8] = param_1[8] | 1;
  param_1[8] = param_1[8] & 0xffffffe3 | 2;
  param_1[4] = *param_5;
  param_1[5] = param_5[1];
  param_1[0x14] = param_1[0x14] | 1;
  param_1[0x14] = param_1[0x14] & 0xffffffe3 | 2;
  param_1[0x10] = *param_6;
  param_1[0x11] = param_6[1];
  __clrfp();
  RaiseException(puVar5,0,1,&param_1);
  if ((unaff_ESI[2] & 0x10) != 0) {
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  if ((unaff_ESI[2] & 8) != 0) {
    *puVar1 = *puVar1 & 0xfffffffb;
  }
  if ((unaff_ESI[2] & 4) != 0) {
    *puVar1 = *puVar1 & 0xfffffff7;
  }
  if ((unaff_ESI[2] & 2) != 0) {
    *puVar1 = *puVar1 & 0xffffffef;
  }
  if ((unaff_ESI[2] & 1) != 0) {
    *puVar1 = *puVar1 & 0xffffffdf;
  }
  switch(*unaff_ESI & 3) {
  case 0:
    uVar4 = *puVar1 & 0xfffff3ff;
    break;
  case 1:
    *puVar1 = *puVar1 & 0xfffff7ff | 0x400;
    goto switchD_00555a8b_default;
  case 2:
    uVar4 = *puVar1 & 0xfffffbff | 0x800;
    break;
  case 3:
    uVar4 = *puVar1 | 0xc00;
    break;
  default:
    goto switchD_00555a8b_default;
  }
  *puVar1 = uVar4;
switchD_00555a8b_default:
  uVar4 = *unaff_ESI >> 2 & 7;
  if (uVar4 == 0) {
    *puVar1 = *puVar1 & 0xfffff3ff | 0x300;
  }
  else {
    if (uVar4 == 1) {
      *puVar1 = *puVar1 & 0xfffff3ff | 0x200;
      *puVar2 = unaff_ESI[0x10];
      puVar2[1] = unaff_ESI[0x11];
      return;
    }
    if (uVar4 == 2) {
      *puVar1 = *puVar1 & 0xfffff3ff;
      *puVar2 = unaff_ESI[0x10];
      puVar2[1] = unaff_ESI[0x11];
      return;
    }
  }
  *puVar2 = unaff_ESI[0x10];
  puVar2[1] = unaff_ESI[0x11];
  return;
}

// --------------------------------------------------

// Function: __handle_exc
// Address: 00555b30
// XREFS: FUN_005556fc, __except1
bool __handle_exc(uint param_1,double *param_2,uint param_3)
{
  ulonglong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  float10 fVar6;
  int local_14;
  undefined8 local_10;
  
  uVar4 = param_1 & 0x1f;
  if (((param_1 & 8) == 0) || ((param_3 & 1) == 0)) {
    if (((param_1 & 4) == 0) || ((param_3 & 4) == 0)) {
      if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
        if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {
          bVar5 = (param_1 & 0x10) != 0;
          local_10 = *param_2;
          if (local_10 == (double)DAT_00577cd8._0_8_) {
            bVar5 = true;
          }
          else {
            fVar6 = (float10)__decomp(*(undefined4 *)param_2,*(undefined4 *)((int)param_2 + 4),
                                      &local_14);
            local_14 = local_14 + -0x600;
            if (local_14 < -0x432) {
              bVar5 = true;
              *(undefined4 *)param_2 = 0;
              local_10 = 0.0;
              *(undefined4 *)((int)param_2 + 4) = 0;
            }
            else {
              local_10 = (double)(ulonglong)
                                 (SUB87((double)fVar6,0) & 0xfffffffffffff | 0x10000000000000);
              if (local_14 < -0x3fd) {
                local_14 = -0x3fd - local_14;
                do {
                  if ((((ulonglong)local_10 & 1) != 0) && (!bVar5)) {
                    bVar5 = true;
                  }
                  uVar4 = (uint)local_10 >> 1;
                  uVar1 = (ulonglong)local_10 & 0x100000000;
                  local_10._0_4_ = uVar4;
                  if (uVar1 != 0) {
                    local_10._0_4_ = uVar4 | 0x80000000;
                  }
                  local_14 = local_14 + -1;
                  local_10 = (double)CONCAT44(local_10._4_4_ >> 1,(uint)local_10);
                } while (local_14 != 0);
              }
              if ((double)fVar6 < (double)DAT_00577cd8._0_8_) {
                local_10 = -local_10;
              }
              *(uint *)param_2 = (uint)local_10;
              *(uint *)((int)param_2 + 4) = local_10._4_4_;
            }
          }
          if (bVar5) {
            __set_statfp(0x10);
          }
          uVar4 = param_1 & 0x1d;
        }
      }
      else {
        __set_statfp(8);
        uVar3 = DAT_00592544;
        uVar2 = DAT_00592534;
        uVar4 = param_3 & 0xc00;
        if (uVar4 < 0x401) {
          if (uVar4 == 0x400) {
            if (*param_2 <= (double)DAT_00577cd8._0_8_) {
              local_10 = -(double)CONCAT44(DAT_00592534,__d_inf);
              *param_2 = local_10;
              uVar4 = param_1 & 0x1e;
            }
            else {
              *(undefined4 *)param_2 = __d_max;
              *(undefined4 *)((int)param_2 + 4) = uVar3;
              uVar4 = param_1 & 0x1e;
            }
            goto LAB_00555e3b;
          }
          if (uVar4 == 0) {
            if (*param_2 <= (double)DAT_00577cd8._0_8_) {
              local_10 = -(double)CONCAT44(DAT_00592534,__d_inf);
              *param_2 = local_10;
              uVar4 = param_1 & 0x1e;
            }
            else {
              *(undefined4 *)param_2 = __d_inf;
              *(undefined4 *)((int)param_2 + 4) = uVar2;
              uVar4 = param_1 & 0x1e;
            }
            goto LAB_00555e3b;
          }
        }
        else if (uVar4 == 0x800) {
          if ((double)DAT_00577cd8._0_8_ < *param_2) {
            *(undefined4 *)param_2 = __d_inf;
            *(undefined4 *)((int)param_2 + 4) = uVar2;
            uVar4 = param_1 & 0x1e;
            goto LAB_00555e3b;
          }
          local_10 = -(double)CONCAT44(DAT_00592544,__d_max);
          *param_2 = local_10;
        }
        else if (uVar4 == 0xc00) {
          if (*param_2 <= (double)DAT_00577cd8._0_8_) {
            local_10 = -(double)CONCAT44(DAT_00592544,__d_max);
            *param_2 = local_10;
            uVar4 = param_1 & 0x1e;
          }
          else {
            *(undefined4 *)param_2 = __d_max;
            *(undefined4 *)((int)param_2 + 4) = uVar3;
            uVar4 = param_1 & 0x1e;
          }
          goto LAB_00555e3b;
        }
        uVar4 = param_1 & 0x1e;
      }
    }
    else {
      __set_statfp(4);
      uVar4 = param_1 & 0x1b;
    }
  }
  else {
    __set_statfp(1);
    uVar4 = param_1 & 0x17;
  }
LAB_00555e3b:
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    __set_statfp(0x20);
    uVar4 = uVar4 & 0xffffffef;
  }
  return uVar4 == 0;
}

// --------------------------------------------------

// Function: __umatherr
// Address: 00555e60
// XREFS: FUN_005555bf, FUN_005556fc, __except1, __handle_qnan1
float10 __umatherr(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                  undefined4 param_9)
{
  int iVar1;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  local_1c = FUN_00555f40(param_2);
  if (local_1c != 0) {
    local_18 = param_3;
    local_c = param_6;
    local_14 = param_4;
    local_10 = param_5;
    local_20 = param_1;
    local_8 = param_7;
    uStack_4 = param_8;
    __ctrlfp(param_9,0xffff);
    iVar1 = __matherr(&local_20);
    if (iVar1 == 0) {
      __set_errno(param_1);
    }
    return (float10)(double)CONCAT44(uStack_4,local_8);
  }
  __ctrlfp(param_9,0xffff);
  __set_errno(param_1);
  return (float10)(double)CONCAT44(param_8,param_7);
}

// --------------------------------------------------

// Function: FUN_00555f0d
// Address: 00555f0d
// XREFS: None
void FUN_00555f0d(int param_1)
{
  if (param_1 == 1) {
    _errno = 0x21;
  }
  else if ((1 < param_1) && (param_1 < 4)) {
    _errno = 0x22;
    return;
  }
  return;
}

// --------------------------------------------------

// Function: __set_errno
// Address: 00555f10
// XREFS: FUN_005556fc, __except1, __umatherr
void __set_errno(int param_1)
{
  if (param_1 == 1) {
    _errno = 0x21;
  }
  else if ((1 < param_1) && (param_1 < 4)) {
    _errno = 0x22;
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00555f36
// Address: 00555f36
// XREFS: None
undefined4 FUN_00555f36(int param_1)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_00592458;
  do {
    if (*piVar1 == param_1) {
      return *(undefined4 *)(iVar2 * 8 + 0x59245c);
    }
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x592530);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00555f40
// Address: 00555f40
// XREFS: __umatherr
undefined4 FUN_00555f40(int param_1)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_00592458;
  do {
    if (*piVar1 == param_1) {
      return *(undefined4 *)(iVar2 * 8 + 0x59245c);
    }
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x592530);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00555f65
// Address: 00555f65
// XREFS: None
int FUN_00555f65(uint param_1)
{
  if ((param_1 & 0x20) != 0) {
    return 5;
  }
  if ((param_1 & 8) != 0) {
    return 1;
  }
  if ((param_1 & 4) != 0) {
    return 2;
  }
  if ((param_1 & 1) != 0) {
    return 3;
  }
  return (param_1 & 2) << 1;
}

// --------------------------------------------------

// Function: __errcode
// Address: 00555f70
// XREFS: FUN_005556fc, __except1
int __errcode(uint param_1)
{
  if ((param_1 & 0x20) != 0) {
    return 5;
  }
  if ((param_1 & 8) != 0) {
    return 1;
  }
  if ((param_1 & 4) != 0) {
    return 2;
  }
  if ((param_1 & 1) != 0) {
    return 3;
  }
  return (param_1 & 2) << 1;
}

// --------------------------------------------------

// Function: FUN_00555fa7
// Address: 00555fa7
// XREFS: None
float10 FUN_00555fa7(undefined4 param_1,undefined4 param_2,short param_3)
{
  return (float10)(double)CONCAT26(param_2._2_2_ & 0x800f | (param_3 + 0x3fe) * 0x10,
                                   CONCAT24((undefined2)param_2,param_1));
}

// --------------------------------------------------

// Function: __set_exp
// Address: 00555fb0
// XREFS: FUN_00556005, __decomp
float10 __set_exp(undefined4 param_1,undefined4 param_2,short param_3)
{
  return (float10)(double)CONCAT26(param_2._2_2_ & 0x800f | (param_3 + 0x3fe) * 0x10,
                                   CONCAT24((undefined2)param_2,param_1));
}

// --------------------------------------------------

// Function: FUN_00555fe9
// Address: 00555fe9
// XREFS: None
int FUN_00555fe9(undefined4 param_1,undefined8 param_2)
{
  return (int)(short)(((ushort)(param_2._2_4_ >> 4) & 0x7ff) - 0x3fe);
}

// --------------------------------------------------

// Function: FUN_00556005
// Address: 00556005
// XREFS: None
void FUN_00556005(undefined4 param_1,uint param_2,int param_3)
{
  __set_exp(param_1,param_2,(((param_2 >> 0x10 & 0x7ff0) >> 4) - 0x3fe) + param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0055603b
// Address: 0055603b
// XREFS: None
float10 FUN_0055603b(undefined4 param_1,undefined4 param_2,short param_3)
{
  return (float10)(double)CONCAT26(param_2._2_2_ & 0x800f | param_3 << 4,
                                   CONCAT24((undefined2)param_2,param_1));
}

// --------------------------------------------------

// Function: FUN_00556073
// Address: 00556073
// XREFS: None
undefined4 FUN_00556073(int param_1,uint param_2)
{
  if ((param_2 == 0x7ff00000) && (param_1 == 0)) {
    return 1;
  }
  if ((param_2 == 0xfff00000) && (param_1 == 0)) {
    return 2;
  }
  if ((param_2._2_2_ & 0x7ff8) == 0x7ff8) {
    return 3;
  }
  if (((param_2._2_2_ & 0x7ff8) == 0x7ff0) && (((param_2 & 0x7ffff) != 0 || (param_1 != 0)))) {
    return 4;
  }
  return 0;
}

// --------------------------------------------------

// Function: __sptype
// Address: 00556080
// XREFS: ceil, floor
undefined4 __sptype(int param_1,uint param_2)
{
  if ((param_2 == 0x7ff00000) && (param_1 == 0)) {
    return 1;
  }
  if ((param_2 == 0xfff00000) && (param_1 == 0)) {
    return 2;
  }
  if ((param_2._2_2_ & 0x7ff8) == 0x7ff8) {
    return 3;
  }
  if (((param_2._2_2_ & 0x7ff8) == 0x7ff0) && (((param_2 & 0x7ffff) != 0 || (param_1 != 0)))) {
    return 4;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005560dc
// Address: 005560dc
// XREFS: None
float10 FUN_005560dc(uint param_1,uint param_2,int *param_3)
{
  ushort uVar1;
  double dVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  
  if ((double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((undefined2)param_2,param_1)))
      == (double)DAT_00577cd8._8_8_) {
    *param_3 = 0;
    return (float10)0.0;
  }
  if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    dVar2 = (double)CONCAT17(param_2._3_1_,
                             CONCAT16(param_2._2_1_,CONCAT24((undefined2)param_2,param_1)));
    iVar5 = -0x3fd;
    uVar4 = param_2;
    for (uVar3 = param_2 & 0x100000; uVar3 == 0; uVar3 = uVar3 & 0x100000) {
      uVar3 = uVar4 << 1;
      param_2._0_2_ = (undefined2)uVar3;
      param_2._2_1_ = (undefined1)(uVar3 >> 0x10);
      param_2._3_1_ = (byte)(uVar3 >> 0x18);
      uVar4 = uVar3;
      if ((param_1 & 0x80000000) != 0) {
        uVar4 = uVar3 | 1;
        param_2._0_2_ = (undefined2)uVar4;
      }
      param_1 = param_1 << 1;
      iVar5 = iVar5 + -1;
    }
    uVar1 = CONCAT11(param_2._3_1_,param_2._2_1_) & 0xffef;
    param_2._2_1_ = (undefined1)uVar1;
    param_2._3_1_ = (byte)(uVar1 >> 8);
    if (dVar2 < (double)DAT_00577cd8._8_8_) {
      param_2._3_1_ = param_2._3_1_ | 0x80;
    }
    fVar6 = (float10)__set_exp(param_1,CONCAT13(param_2._3_1_,
                                                CONCAT12(param_2._2_1_,(undefined2)param_2)),0);
    *param_3 = iVar5;
    return (float10)(double)fVar6;
  }
  fVar6 = (float10)__set_exp(param_1,param_2,0);
  *param_3 = ((param_2 >> 0x10 & 0x7ff0) >> 4) - 0x3fe;
  return (float10)(double)fVar6;
}

// --------------------------------------------------

// Function: __decomp
// Address: 005560e0
// XREFS: __handle_exc
float10 __decomp(uint param_1,uint param_2,int *param_3)
{
  ushort uVar1;
  double dVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  
  if ((double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((undefined2)param_2,param_1)))
      == (double)DAT_00577cd8._8_8_) {
    *param_3 = 0;
    return (float10)0.0;
  }
  if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    dVar2 = (double)CONCAT17(param_2._3_1_,
                             CONCAT16(param_2._2_1_,CONCAT24((undefined2)param_2,param_1)));
    iVar5 = -0x3fd;
    uVar4 = param_2;
    for (uVar3 = param_2 & 0x100000; uVar3 == 0; uVar3 = uVar3 & 0x100000) {
      uVar3 = uVar4 << 1;
      param_2._0_2_ = (undefined2)uVar3;
      param_2._2_1_ = (undefined1)(uVar3 >> 0x10);
      param_2._3_1_ = (byte)(uVar3 >> 0x18);
      uVar4 = uVar3;
      if ((param_1 & 0x80000000) != 0) {
        uVar4 = uVar3 | 1;
        param_2._0_2_ = (undefined2)uVar4;
      }
      param_1 = param_1 << 1;
      iVar5 = iVar5 + -1;
    }
    uVar1 = CONCAT11(param_2._3_1_,param_2._2_1_) & 0xffef;
    param_2._2_1_ = (undefined1)uVar1;
    param_2._3_1_ = (byte)(uVar1 >> 8);
    if (dVar2 < (double)DAT_00577cd8._8_8_) {
      param_2._3_1_ = param_2._3_1_ | 0x80;
    }
    fVar6 = (float10)__set_exp(param_1,CONCAT13(param_2._3_1_,
                                                CONCAT12(param_2._2_1_,(undefined2)param_2)),0);
    *param_3 = iVar5;
    return (float10)(double)fVar6;
  }
  fVar6 = (float10)__set_exp(param_1,param_2,0);
  *param_3 = ((param_2 >> 0x10 & 0x7ff0) >> 4) - 0x3fe;
  return (float10)(double)fVar6;
}

// --------------------------------------------------

// Function: __statfp
// Address: 005561e0
// XREFS: __raise_exc
int __statfp(void)
{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}

// --------------------------------------------------

// Function: __clrfp
// Address: 005561f0
// XREFS: __raise_exc
int __clrfp(void)
{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}

// --------------------------------------------------

// Function: FUN_00556201
// Address: 00556201
// XREFS: None
int FUN_00556201(void)
{
  short in_FPUControlWord;
  
  return (int)in_FPUControlWord;
}

// --------------------------------------------------

// Function: __ctrlfp
// Address: 00556210
// XREFS: FUN_005555bf, FUN_005556fc, __except1, __handle_qnan1, __umatherr, ceil, floor
int __ctrlfp(void)
{
  short in_FPUControlWord;
  
  return (int)in_FPUControlWord;
}

// --------------------------------------------------

// Function: FUN_00556238
// Address: 00556238
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00556238(void)
{
  return;
}

// --------------------------------------------------

// Function: __set_statfp
// Address: 00556240
// XREFS: __handle_exc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __set_statfp(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00556299
// Address: 00556299
// XREFS: None
undefined4 * FUN_00556299(undefined4 *param_1,uint param_2)
{
  undefined4 *puVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)malloc(param_2);
    return puVar1;
  }
  if (param_2 == 0) {
    free(param_1);
    return (undefined4 *)0x0;
  }
  if (param_2 < 0xffffffe1) {
    if (param_2 == 0) {
      param_2 = 0x10;
    }
    else {
      param_2 = param_2 + 0xf & 0xfffffff0;
    }
  }
  do {
    puVar1 = (undefined4 *)0x0;
    if (param_2 < 0xffffffe1) {
      pbVar2 = (byte *)___sbh_find_block(param_1,&uStack_4,&uStack_8);
      if (pbVar2 == (byte *)0x0) {
        puVar1 = (undefined4 *)HeapReAlloc(__crtheap,0,param_1,param_2);
        goto LAB_0055640a;
      }
      if (param_2 < ___sbh_threshold) {
        iVar3 = ___sbh_resize_block(uStack_4,uStack_8,pbVar2,param_2 >> 4);
        puVar1 = param_1;
        if (iVar3 != 0) goto LAB_0055639f;
        puVar1 = (undefined4 *)___sbh_alloc_block(param_2 >> 4);
        if (puVar1 != (undefined4 *)0x0) {
          uVar5 = (uint)*pbVar2 << 4;
          if (param_2 <= (uint)*pbVar2 << 4) {
            uVar5 = param_2;
          }
          puVar6 = param_1;
          puVar7 = puVar1;
          for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
          ___sbh_free_block(uStack_4,uStack_8,pbVar2);
          goto LAB_0055639f;
        }
      }
      else {
LAB_0055639f:
        if (puVar1 != (undefined4 *)0x0) {
          return puVar1;
        }
      }
      puVar1 = (undefined4 *)HeapAlloc(__crtheap,0,param_2);
      if (puVar1 != (undefined4 *)0x0) {
        uVar5 = (uint)*pbVar2 << 4;
        if (param_2 <= (uint)*pbVar2 << 4) {
          uVar5 = param_2;
        }
        puVar6 = param_1;
        puVar7 = puVar1;
        for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        ___sbh_free_block(uStack_4,uStack_8,pbVar2);
        goto LAB_0055640a;
      }
    }
    else {
LAB_0055640a:
      if (puVar1 != (undefined4 *)0x0) {
        return puVar1;
      }
    }
    if (__newmode == 0) {
      return puVar1;
    }
    iVar3 = __callnewh(param_2);
    if (iVar3 == 0) {
      return (undefined4 *)0x0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: realloc
// Address: 005562a0
// XREFS: ___crtsetenv, __onexit
/* realloc */

undefined4 * __cdecl realloc(undefined4 *param_1,uint param_2)
{
  undefined4 *puVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)malloc(param_2);
    return puVar1;
  }
  if (param_2 == 0) {
    free(param_1);
    return (undefined4 *)0x0;
  }
  if (param_2 < 0xffffffe1) {
    if (param_2 == 0) {
      param_2 = 0x10;
    }
    else {
      param_2 = param_2 + 0xf & 0xfffffff0;
    }
  }
  do {
    puVar1 = (undefined4 *)0x0;
    if (param_2 < 0xffffffe1) {
      pbVar2 = (byte *)___sbh_find_block(param_1,&local_4,&local_8);
      if (pbVar2 == (byte *)0x0) {
        puVar1 = (undefined4 *)HeapReAlloc(__crtheap,0,param_1,param_2);
        goto LAB_0055640a;
      }
      if (param_2 < ___sbh_threshold) {
        iVar3 = ___sbh_resize_block(local_4,local_8,pbVar2,param_2 >> 4);
        puVar1 = param_1;
        if (iVar3 != 0) goto LAB_0055639f;
        puVar1 = (undefined4 *)___sbh_alloc_block(param_2 >> 4);
        if (puVar1 != (undefined4 *)0x0) {
          uVar5 = (uint)*pbVar2 << 4;
          if (param_2 <= (uint)*pbVar2 << 4) {
            uVar5 = param_2;
          }
          puVar6 = param_1;
          puVar7 = puVar1;
          for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
          ___sbh_free_block(local_4,local_8,pbVar2);
          goto LAB_0055639f;
        }
      }
      else {
LAB_0055639f:
        if (puVar1 != (undefined4 *)0x0) {
          return puVar1;
        }
      }
      puVar1 = (undefined4 *)HeapAlloc(__crtheap,0,param_2);
      if (puVar1 != (undefined4 *)0x0) {
        uVar5 = (uint)*pbVar2 << 4;
        if (param_2 <= (uint)*pbVar2 << 4) {
          uVar5 = param_2;
        }
        puVar6 = param_1;
        puVar7 = puVar1;
        for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        ___sbh_free_block(local_4,local_8,pbVar2);
        goto LAB_0055640a;
      }
    }
    else {
LAB_0055640a:
      if (puVar1 != (undefined4 *)0x0) {
        return puVar1;
      }
    }
    if (__newmode == 0) {
      return puVar1;
    }
    iVar3 = __callnewh(param_2);
    if (iVar3 == 0) {
      return (undefined4 *)0x0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0055643a
// Address: 0055643a
// XREFS: None
int FUN_0055643a(undefined4 param_1)
{
  undefined4 uVar1;
  byte *pbVar2;
  int iVar3;
  undefined1 auStack_4 [4];
  
  uVar1 = param_1;
  pbVar2 = (byte *)___sbh_find_block(param_1,auStack_4,&param_1);
  if (pbVar2 != (byte *)0x0) {
    return (uint)*pbVar2 << 4;
  }
  iVar3 = HeapSize(__crtheap,0,uVar1);
  return iVar3;
}

// --------------------------------------------------

// Function: __msize
// Address: 00556440
// XREFS: __onexit
int __msize(undefined4 param_1)
{
  undefined4 uVar1;
  byte *pbVar2;
  int iVar3;
  undefined1 local_4 [4];
  
  uVar1 = param_1;
  pbVar2 = (byte *)___sbh_find_block(param_1,local_4,&param_1);
  if (pbVar2 != (byte *)0x0) {
    return (uint)*pbVar2 << 4;
  }
  iVar3 = HeapSize(__crtheap,0,uVar1);
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_0055647b
// Address: 0055647b
// XREFS: None
int FUN_0055647b(undefined4 *param_1)
{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int iStack_8;
  int iStack_4;
  
  uVar1 = param_1[4];
  if ((int)param_1[1] < 0) {
    param_1[1] = 0;
  }
  iStack_4 = lseek(uVar1,0,1);
  if (iStack_4 < 0) {
    return -1;
  }
  uVar2 = param_1[3];
  if ((uVar2 & 0x108) == 0) {
    return iStack_4 - param_1[1];
  }
  pcVar8 = (char *)*param_1;
  pcVar3 = (char *)param_1[2];
  iStack_8 = (int)pcVar8 - (int)pcVar3;
  iVar4 = (int)uVar1 >> 5;
  if ((uVar2 & 3) == 0) {
    if ((uVar2 & 0x80) == 0) {
      _errno = 0x16;
      return -1;
    }
  }
  else {
    pcVar6 = pcVar3;
    if ((*(byte *)((&___pioinfo)[iVar4] + 4 + (uVar1 & 0x1f) * 8) & 0x80) != 0) {
      for (; pcVar6 < pcVar8; pcVar6 = pcVar6 + 1) {
        if (*pcVar6 == '\n') {
          iStack_8 = iStack_8 + 1;
        }
      }
    }
  }
  if (iStack_4 == 0) {
    return iStack_8;
  }
  if ((*(byte *)(param_1 + 3) & 1) == 0) goto LAB_005565f5;
  if (param_1[1] == 0) {
    return iStack_4;
  }
  pcVar8 = pcVar8 + (param_1[1] - (int)pcVar3);
  iVar7 = (uVar1 & 0x1f) * 8;
  if ((*(byte *)(iVar7 + 4 + (&___pioinfo)[iVar4]) & 0x80) != 0) {
    iVar5 = lseek(uVar1,0,2);
    if (iVar5 == iStack_4) {
      pcVar6 = (char *)param_1[2];
      pcVar3 = pcVar6 + (int)pcVar8;
      for (; pcVar6 < pcVar3; pcVar6 = pcVar6 + 1) {
        if (*pcVar6 == '\n') {
          pcVar8 = pcVar8 + 1;
        }
      }
      if ((param_1[3] & 0x2000) != 0) {
LAB_005565ec:
        pcVar8 = pcVar8 + 1;
      }
    }
    else {
      lseek(uVar1,iStack_4,0);
      if (((pcVar8 < (char *)0x201) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
        pcVar8 = (char *)0x200;
      }
      else {
        pcVar8 = (char *)param_1[6];
      }
      if ((*(byte *)(iVar7 + 4 + (&___pioinfo)[iVar4]) & 4) != 0) goto LAB_005565ec;
    }
  }
  iStack_4 = iStack_4 - (int)pcVar8;
LAB_005565f5:
  return iStack_4 + iStack_8;
}

// --------------------------------------------------

// Function: ftell
// Address: 00556480
// XREFS: fseek
/* ftell */

int __cdecl ftell(undefined4 *param_1)
{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int local_8;
  int local_4;
  
  uVar1 = param_1[4];
  if ((int)param_1[1] < 0) {
    param_1[1] = 0;
  }
  local_4 = lseek(uVar1,0,1);
  if (local_4 < 0) {
    return -1;
  }
  uVar2 = param_1[3];
  if ((uVar2 & 0x108) == 0) {
    return local_4 - param_1[1];
  }
  pcVar8 = (char *)*param_1;
  pcVar3 = (char *)param_1[2];
  local_8 = (int)pcVar8 - (int)pcVar3;
  iVar4 = (int)uVar1 >> 5;
  if ((uVar2 & 3) == 0) {
    if ((uVar2 & 0x80) == 0) {
      _errno = 0x16;
      return -1;
    }
  }
  else {
    pcVar6 = pcVar3;
    if ((*(byte *)((&___pioinfo)[iVar4] + 4 + (uVar1 & 0x1f) * 8) & 0x80) != 0) {
      for (; pcVar6 < pcVar8; pcVar6 = pcVar6 + 1) {
        if (*pcVar6 == '\n') {
          local_8 = local_8 + 1;
        }
      }
    }
  }
  if (local_4 == 0) {
    return local_8;
  }
  if ((*(byte *)(param_1 + 3) & 1) == 0) goto LAB_005565f5;
  if (param_1[1] == 0) {
    return local_4;
  }
  pcVar8 = pcVar8 + (param_1[1] - (int)pcVar3);
  iVar7 = (uVar1 & 0x1f) * 8;
  if ((*(byte *)(iVar7 + 4 + (&___pioinfo)[iVar4]) & 0x80) != 0) {
    iVar5 = lseek(uVar1,0,2);
    if (iVar5 == local_4) {
      pcVar6 = (char *)param_1[2];
      pcVar3 = pcVar6 + (int)pcVar8;
      for (; pcVar6 < pcVar3; pcVar6 = pcVar6 + 1) {
        if (*pcVar6 == '\n') {
          pcVar8 = pcVar8 + 1;
        }
      }
      if ((param_1[3] & 0x2000) != 0) {
LAB_005565ec:
        pcVar8 = pcVar8 + 1;
      }
    }
    else {
      lseek(uVar1,local_4,0);
      if (((pcVar8 < (char *)0x201) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
        pcVar8 = (char *)0x200;
      }
      else {
        pcVar8 = (char *)param_1[6];
      }
      if ((*(byte *)(iVar7 + 4 + (&___pioinfo)[iVar4]) & 4) != 0) goto LAB_005565ec;
    }
  }
  local_4 = local_4 - (int)pcVar8;
LAB_005565f5:
  return local_4 + local_8;
}

// --------------------------------------------------

// Function: FUN_00556621
// Address: 00556621
// XREFS: None
undefined4 FUN_00556621(undefined4 param_1,undefined4 param_2)
{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  piVar3 = (int *)FUN_00556770(param_1);
  uVar4 = __pxcptinfoptrs;
  if ((piVar3 == (int *)0x0) || (pcVar1 = (code *)piVar3[2], pcVar1 == (code *)0x0)) {
    uVar4 = UnhandledExceptionFilter(param_2);
    return uVar4;
  }
  if (pcVar1 == (code *)0x5) {
    piVar3[2] = 0;
    return 1;
  }
  if (pcVar1 != (code *)0x1) {
    __pxcptinfoptrs = param_2;
    if (piVar3[1] == 8) {
      if (__First_FPE_Indx < __Num_FPE + __First_FPE_Indx) {
        iVar6 = (__Num_FPE + __First_FPE_Indx) - __First_FPE_Indx;
        puVar5 = (undefined4 *)((int)&UNK_00592580 + __First_FPE_Indx * 0xc);
        do {
          *puVar5 = 0;
          puVar5 = puVar5 + 3;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      uVar2 = __fpecode;
      iVar6 = *piVar3;
      if (iVar6 == -0x3fffff72) {
        __fpecode = 0x83;
      }
      else if (iVar6 == -0x3fffff70) {
        __fpecode = 0x81;
      }
      else if (iVar6 == -0x3fffff6f) {
        __fpecode = 0x84;
      }
      else if (iVar6 == -0x3fffff6d) {
        __fpecode = 0x85;
      }
      else if (iVar6 == -0x3fffff73) {
        __fpecode = 0x82;
      }
      else if (iVar6 == -0x3fffff71) {
        __fpecode = 0x86;
      }
      else if (iVar6 == -0x3fffff6e) {
        __fpecode = 0x8a;
      }
      (*pcVar1)(8,__fpecode);
      __fpecode = uVar2;
      __pxcptinfoptrs = uVar4;
      return 0xffffffff;
    }
    piVar3[2] = 0;
    (*pcVar1)(piVar3[1]);
    __pxcptinfoptrs = uVar4;
    return 0xffffffff;
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: __XcptFilter
// Address: 00556630
// XREFS: FUN_0054f9ba
undefined4 __XcptFilter(undefined4 param_1,undefined4 param_2)
{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  piVar3 = (int *)FUN_00556770(param_1);
  uVar4 = __pxcptinfoptrs;
  if ((piVar3 == (int *)0x0) || (pcVar1 = (code *)piVar3[2], pcVar1 == (code *)0x0)) {
    uVar4 = UnhandledExceptionFilter(param_2);
    return uVar4;
  }
  if (pcVar1 == (code *)0x5) {
    piVar3[2] = 0;
    return 1;
  }
  if (pcVar1 != (code *)0x1) {
    __pxcptinfoptrs = param_2;
    if (piVar3[1] == 8) {
      if (__First_FPE_Indx < __Num_FPE + __First_FPE_Indx) {
        iVar6 = (__Num_FPE + __First_FPE_Indx) - __First_FPE_Indx;
        puVar5 = (undefined4 *)((int)&UNK_00592580 + __First_FPE_Indx * 0xc);
        do {
          *puVar5 = 0;
          puVar5 = puVar5 + 3;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      uVar2 = __fpecode;
      iVar6 = *piVar3;
      if (iVar6 == -0x3fffff72) {
        __fpecode = 0x83;
      }
      else if (iVar6 == -0x3fffff70) {
        __fpecode = 0x81;
      }
      else if (iVar6 == -0x3fffff6f) {
        __fpecode = 0x84;
      }
      else if (iVar6 == -0x3fffff6d) {
        __fpecode = 0x85;
      }
      else if (iVar6 == -0x3fffff73) {
                    /* language.dll match for 0x82: "B" */
        __fpecode = 0x82;
      }
      else if (iVar6 == -0x3fffff71) {
        __fpecode = 0x86;
      }
      else if (iVar6 == -0x3fffff6e) {
        __fpecode = 0x8a;
      }
      (*pcVar1)(8,__fpecode);
      __fpecode = uVar2;
      __pxcptinfoptrs = uVar4;
      return 0xffffffff;
    }
    piVar3[2] = 0;
    (*pcVar1)(piVar3[1]);
    __pxcptinfoptrs = uVar4;
    return 0xffffffff;
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0055676e
// Address: 0055676e
// XREFS: None
int * FUN_0055676e(int param_1)
{
  int *piVar1;
  
  piVar1 = &__XcptActTab;
  if (__XcptActTab != param_1) {
    do {
      piVar1 = piVar1 + 3;
      if (&__XcptActTab + __XcptActTabCount * 3 <= piVar1) break;
    } while (*piVar1 != param_1);
  }
  if ((&__XcptActTab + __XcptActTabCount * 3 <= piVar1) || (*piVar1 != param_1)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

// --------------------------------------------------

// Function: FUN_00556770
// Address: 00556770
// XREFS: __XcptFilter
int * FUN_00556770(int param_1)
{
  int *piVar1;
  
  piVar1 = &__XcptActTab;
  if (__XcptActTab != param_1) {
    do {
      piVar1 = piVar1 + 3;
      if (&__XcptActTab + __XcptActTabCount * 3 <= piVar1) break;
    } while (*piVar1 != param_1);
  }
  if ((&__XcptActTab + __XcptActTabCount * 3 <= piVar1) || (*piVar1 != param_1)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

// --------------------------------------------------

// Function: FUN_005567b5
// Address: 005567b5
// XREFS: None
void FUN_005567b5(undefined4 param_1)
{
  FUN_00556930(param_1,0,1);
  return;
}

// --------------------------------------------------

// Function: FUN_005567d2
// Address: 005567d2
// XREFS: None
void FUN_005567d2(undefined4 param_1)
{
  FUN_00556930(param_1,0,3);
  return;
}

// --------------------------------------------------

// Function: FUN_005567f2
// Address: 005567f2
// XREFS: None
void FUN_005567f2(undefined4 param_1)
{
  FUN_00556930(param_1,0,2);
  return;
}

// --------------------------------------------------

// Function: FUN_00556812
// Address: 00556812
// XREFS: None
void FUN_00556812(undefined4 param_1)
{
  FUN_00556930(param_1,0x107,1);
  return;
}

// --------------------------------------------------

// Function: FUN_00556835
// Address: 00556835
// XREFS: None
void FUN_00556835(undefined4 param_1)
{
  FUN_00556930(param_1,0x103,1);
  return;
}

// --------------------------------------------------

// Function: FUN_00556855
// Address: 00556855
// XREFS: None
void FUN_00556855(undefined4 param_1)
{
  FUN_00556930(param_1,0x117,3);
  return;
}

// --------------------------------------------------

// Function: FUN_00556875
// Address: 00556875
// XREFS: None
void FUN_00556875(undefined4 param_1)
{
  FUN_00556930(param_1,0x157,3);
  return;
}

// --------------------------------------------------

// Function: FUN_00556895
// Address: 00556895
// XREFS: None
void FUN_00556895(undefined4 param_1)
{
  FUN_00556930(param_1,0x10,2);
  return;
}

// --------------------------------------------------

// Function: FUN_005568b2
// Address: 005568b2
// XREFS: None
void FUN_005568b2(undefined4 param_1)
{
  FUN_00556930(param_1,0,4);
  return;
}

// --------------------------------------------------

// Function: __ismbblead
// Address: 005568c0
// XREFS: entry
void __ismbblead(undefined4 param_1)
{
  FUN_00556930(param_1,0,4);
  return;
}

// --------------------------------------------------

// Function: FUN_005568d2
// Address: 005568d2
// XREFS: None
void FUN_005568d2(undefined4 param_1)
{
  FUN_00556930(param_1,0,8);
  return;
}

// --------------------------------------------------

// Function: FUN_005568f2
// Address: 005568f2
// XREFS: None
undefined4 FUN_005568f2(undefined4 param_1)
{
  int iVar1;
  
  if (___mbcodepage == 0x3a4) {
    iVar1 = FUN_00556930(param_1,0,3);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0055692a
// Address: 0055692a
// XREFS: None
undefined4 FUN_0055692a(uint param_1,uint param_2,byte param_3)
{
  if ((*(byte *)((int)&__mbctype + (param_1 & 0xff) + 1) & param_3) == 0) {
    if (param_2 == 0) {
      param_2 = 0;
    }
    else {
      param_2 = *(ushort *)(&DAT_005920da + (param_1 & 0xff) * 2) & param_2;
    }
    if (param_2 == 0) {
      return 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00556930
// Address: 00556930
// XREFS: FUN_005567b5, FUN_005567d2, FUN_005567f2, FUN_00556812, FUN_00556835, FUN_00556855, FUN_00556875, FUN_00556895, FUN_005568d2, FUN_005568f2, __ismbblead
undefined4 FUN_00556930(uint param_1,uint param_2,byte param_3)
{
  if ((*(byte *)((int)&__mbctype + (param_1 & 0xff) + 1) & param_3) == 0) {
    if (param_2 == 0) {
      param_2 = 0;
    }
    else {
      param_2 = *(ushort *)(&DAT_005920da + (param_1 & 0xff) * 2) & param_2;
    }
    if (param_2 == 0) {
      return 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0055696a
// Address: 0055696a
// XREFS: None
void FUN_0055696a(void)
{
  char cVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int *piStack_4;
  
  iVar8 = 0;
  cVar2 = *__aenvptr;
  pcVar7 = __aenvptr;
  while (cVar2 != '\0') {
    if (cVar2 != '=') {
      iVar8 = iVar8 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar9 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar2 != '\0');
    pcVar9 = pcVar7 + ~uVar4;
    pcVar7 = pcVar7 + ~uVar4;
    cVar2 = *pcVar9;
  }
  piVar3 = (int *)malloc(iVar8 * 4 + 4);
  __environ = piVar3;
  if (piVar3 == (int *)0x0) {
    __amsg_exit(9);
  }
  cVar2 = *__aenvptr;
  piStack_4 = piVar3;
  pcVar7 = __aenvptr;
  do {
    if (cVar2 == '\0') {
      free(__aenvptr);
      __aenvptr = (char *)0x0;
      *piVar3 = 0;
      return;
    }
    uVar4 = 0xffffffff;
    pcVar9 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    if (cVar2 != '=') {
      iVar8 = malloc(uVar4);
      *piVar3 = iVar8;
      if (iVar8 == 0) {
        __amsg_exit(9);
      }
      uVar5 = 0xffffffff;
      pcVar9 = pcVar7;
      do {
        pcVar10 = pcVar9;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar10 = pcVar9 + 1;
        cVar2 = *pcVar9;
        pcVar9 = pcVar10;
      } while (cVar2 != '\0');
      uVar5 = ~uVar5;
      pcVar9 = pcVar10 + -uVar5;
      pcVar10 = (char *)*piStack_4;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      piVar3 = piStack_4 + 1;
      for (uVar5 = uVar5 & 3; piStack_4 = piVar3, uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    cVar2 = pcVar7[uVar4];
    pcVar7 = pcVar7 + uVar4;
  } while( true );
}

// --------------------------------------------------

// Function: __setenvp
// Address: 00556970
// XREFS: entry
void __setenvp(void)
{
  char cVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int *local_4;
  
  iVar8 = 0;
  cVar2 = *__aenvptr;
  pcVar7 = __aenvptr;
  while (cVar2 != '\0') {
    if (cVar2 != '=') {
      iVar8 = iVar8 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar9 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar2 != '\0');
    pcVar9 = pcVar7 + ~uVar4;
    pcVar7 = pcVar7 + ~uVar4;
    cVar2 = *pcVar9;
  }
  piVar3 = (int *)malloc(iVar8 * 4 + 4);
  __environ = piVar3;
  if (piVar3 == (int *)0x0) {
    __amsg_exit(9);
  }
  cVar2 = *__aenvptr;
  local_4 = piVar3;
  pcVar7 = __aenvptr;
  do {
    if (cVar2 == '\0') {
      free(__aenvptr);
      __aenvptr = (char *)0x0;
      *piVar3 = 0;
      return;
    }
    uVar4 = 0xffffffff;
    pcVar9 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    if (cVar2 != '=') {
      iVar8 = malloc(uVar4);
      *piVar3 = iVar8;
      if (iVar8 == 0) {
        __amsg_exit(9);
      }
      uVar5 = 0xffffffff;
      pcVar9 = pcVar7;
      do {
        pcVar10 = pcVar9;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar10 = pcVar9 + 1;
        cVar2 = *pcVar9;
        pcVar9 = pcVar10;
      } while (cVar2 != '\0');
      uVar5 = ~uVar5;
      pcVar9 = pcVar10 + -uVar5;
      pcVar10 = (char *)*local_4;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      piVar3 = local_4 + 1;
      for (uVar5 = uVar5 & 3; local_4 = piVar3, uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    cVar2 = pcVar7[uVar4];
    pcVar7 = pcVar7 + uVar4;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00556a5e
// Address: 00556a5e
// XREFS: None
void FUN_00556a5e(void)
{
  int iVar1;
  int unaff_EDI;
  Alignment *pAVar2;
  int iStack_14;
  
  iStack_14 = 0x104;
  GetModuleFileNameA(0,&DAT_008882d8);
  __pgmptr = &DAT_008882d8;
  pAVar2 = __acmdln;
  if (*(char *)__acmdln == '\0') {
    pAVar2 = &DAT_008882d8;
  }
  FUN_00556b00(pAVar2,0,0,&iStack_14,&stack0xfffffff0);
  iVar1 = malloc(unaff_EDI + iStack_14 * 4);
  if (iVar1 == 0) {
    __amsg_exit(8);
  }
  FUN_00556b00(pAVar2,iVar1,iVar1 + iStack_14 * 4,&iStack_14,&stack0xfffffff0);
  __osver._20_4_ = iVar1;
  __osver._16_4_ = iStack_14 + -1;
  return;
}

// --------------------------------------------------

// Function: __setargv
// Address: 00556a60
// XREFS: entry
void __setargv(void)
{
  int iVar1;
  int unaff_EDI;
  Alignment *pAVar2;
  int iStack_14;
  
  iStack_14 = 0x104;
  GetModuleFileNameA(0,&DAT_008882d8);
  __pgmptr = &DAT_008882d8;
  pAVar2 = __acmdln;
  if (*(char *)__acmdln == '\0') {
    pAVar2 = &DAT_008882d8;
  }
  FUN_00556b00(pAVar2,0,0,&iStack_14,&stack0xfffffff0);
  iVar1 = malloc(unaff_EDI + iStack_14 * 4);
  if (iVar1 == 0) {
    __amsg_exit(8);
  }
  FUN_00556b00(pAVar2,iVar1,iVar1 + iStack_14 * 4,&iStack_14,&stack0xfffffff0);
  __osver._20_4_ = iVar1;
  __osver._16_4_ = iStack_14 + -1;
  return;
}

// --------------------------------------------------

// Function: FUN_00556afe
// Address: 00556afe
// XREFS: None
void FUN_00556afe(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)
{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;
  
  piVar6 = param_5;
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    pbVar7 = param_1 + 1;
    bVar2 = param_1[1];
    while ((bVar2 != 0x22 && (bVar2 != 0))) {
      if (((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
        pbVar7 = pbVar7 + 1;
      }
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
      }
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar2 = *pbVar1;
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar7 == 0x22) {
      pbVar7 = pbVar7 + 1;
    }
  }
  else {
    do {
      *piVar6 = *piVar6 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar2 = *param_1;
      pbVar7 = param_1 + 1;
      param_5 = (int *)(uint)bVar2;
      if ((*(byte *)((int)&__mbctype + (int)param_5 + 1U) & 4) != 0) {
        *piVar6 = *piVar6 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar7;
          param_3 = param_3 + 1;
        }
        pbVar7 = param_1 + 2;
      }
      if (bVar2 == 0x20) break;
      if (bVar2 == 0) goto LAB_00556bd9;
      param_1 = pbVar7;
    } while (bVar2 != 9);
    if (bVar2 == 0) {
LAB_00556bd9:
      pbVar7 = pbVar7 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar4 = false;
  bVar5 = false;
  while (*pbVar7 != 0) {
    for (; (*pbVar7 == 0x20 || (*pbVar7 == 9)); pbVar7 = pbVar7 + 1) {
    }
    if (*pbVar7 == 0) break;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      uVar8 = 0;
      bVar3 = true;
      bVar2 = *pbVar7;
      while (bVar2 == 0x5c) {
        pbVar1 = pbVar7 + 1;
        pbVar7 = pbVar7 + 1;
        uVar8 = uVar8 + 1;
        bVar2 = *pbVar1;
      }
      if (*pbVar7 == 0x22) {
        if ((uVar8 & 1) == 0) {
          if ((bVar4) && (pbVar7[1] == 0x22)) {
            pbVar7 = pbVar7 + 1;
          }
          else {
            bVar3 = false;
          }
          bVar4 = !bVar5;
          bVar5 = bVar4;
        }
        uVar8 = uVar8 >> 1;
      }
      for (; uVar8 != 0; uVar8 = uVar8 - 1) {
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *piVar6 = *piVar6 + 1;
      }
      bVar2 = *pbVar7;
      if ((bVar2 == 0) || ((!bVar4 && ((bVar2 == 0x20 || (bVar2 == 9)))))) break;
      if (bVar3) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) != 0) {
            pbVar7 = pbVar7 + 1;
            *piVar6 = *piVar6 + 1;
          }
          *piVar6 = *piVar6 + 1;
          goto LAB_00556cd5;
        }
        if ((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) != 0) {
          *param_3 = bVar2;
          param_3 = param_3 + 1;
          pbVar7 = pbVar7 + 1;
          *piVar6 = *piVar6 + 1;
        }
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
        *piVar6 = *piVar6 + 1;
        pbVar7 = pbVar7 + 1;
      }
      else {
LAB_00556cd5:
        pbVar7 = pbVar7 + 1;
      }
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *piVar6 = *piVar6 + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00556b00
// Address: 00556b00
// XREFS: __setargv
void FUN_00556b00(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)
{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;
  
  piVar6 = param_5;
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    pbVar7 = param_1 + 1;
    bVar2 = param_1[1];
    while ((bVar2 != 0x22 && (bVar2 != 0))) {
      if (((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
        pbVar7 = pbVar7 + 1;
      }
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
      }
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar2 = *pbVar1;
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar7 == 0x22) {
      pbVar7 = pbVar7 + 1;
    }
  }
  else {
    do {
      *piVar6 = *piVar6 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar2 = *param_1;
      pbVar7 = param_1 + 1;
      param_5 = (int *)(uint)bVar2;
      if ((*(byte *)((int)&__mbctype + (int)param_5 + 1U) & 4) != 0) {
        *piVar6 = *piVar6 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar7;
          param_3 = param_3 + 1;
        }
        pbVar7 = param_1 + 2;
      }
      if (bVar2 == 0x20) break;
      if (bVar2 == 0) goto LAB_00556bd9;
      param_1 = pbVar7;
    } while (bVar2 != 9);
    if (bVar2 == 0) {
LAB_00556bd9:
      pbVar7 = pbVar7 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar4 = false;
  bVar5 = false;
  while (*pbVar7 != 0) {
    for (; (*pbVar7 == 0x20 || (*pbVar7 == 9)); pbVar7 = pbVar7 + 1) {
    }
    if (*pbVar7 == 0) break;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      uVar8 = 0;
      bVar3 = true;
      bVar2 = *pbVar7;
      while (bVar2 == 0x5c) {
        pbVar1 = pbVar7 + 1;
        pbVar7 = pbVar7 + 1;
        uVar8 = uVar8 + 1;
        bVar2 = *pbVar1;
      }
      if (*pbVar7 == 0x22) {
        if ((uVar8 & 1) == 0) {
          if ((bVar4) && (pbVar7[1] == 0x22)) {
            pbVar7 = pbVar7 + 1;
          }
          else {
            bVar3 = false;
          }
          bVar4 = !bVar5;
          bVar5 = bVar4;
        }
        uVar8 = uVar8 >> 1;
      }
      for (; uVar8 != 0; uVar8 = uVar8 - 1) {
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *piVar6 = *piVar6 + 1;
      }
      bVar2 = *pbVar7;
      if ((bVar2 == 0) || ((!bVar4 && ((bVar2 == 0x20 || (bVar2 == 9)))))) break;
      if (bVar3) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) != 0) {
            pbVar7 = pbVar7 + 1;
            *piVar6 = *piVar6 + 1;
          }
          *piVar6 = *piVar6 + 1;
          goto LAB_00556cd5;
        }
        if ((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) != 0) {
          *param_3 = bVar2;
          param_3 = param_3 + 1;
          pbVar7 = pbVar7 + 1;
          *piVar6 = *piVar6 + 1;
        }
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
        *piVar6 = *piVar6 + 1;
        pbVar7 = pbVar7 + 1;
      }
      else {
LAB_00556cd5:
        pbVar7 = pbVar7 + 1;
      }
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *piVar6 = *piVar6 + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00556d0f
// Address: 00556d0f
// XREFS: None
char * FUN_00556d0f(void)
{
  char cVar1;
  short sVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  short *psVar7;
  char *pcVar8;
  short *psVar9;
  short *local_8;
  int local_4;
  
  local_8 = (short *)0x0;
  local_4 = 0;
  if (DAT_008882d8._260_4_ == 0) {
    local_8 = (short *)GetEnvironmentStringsW();
    if (local_8 == (short *)0x0) {
      local_8 = (short *)GetEnvironmentStrings();
      if (local_8 == (short *)0x0) {
        return (char *)0x0;
      }
      DAT_008882d8._260_4_ = 2;
    }
    else {
      DAT_008882d8._260_4_ = 1;
    }
  }
  if (DAT_008882d8._260_4_ == 1) {
    if ((local_8 == (short *)0x0) &&
       (local_8 = (short *)GetEnvironmentStringsW(), local_8 == (short *)0x0)) {
      return (char *)0x0;
    }
    sVar2 = *local_8;
    psVar7 = local_8;
    while (sVar2 != 0) {
      do {
        psVar9 = psVar7;
        psVar7 = psVar9 + 1;
      } while (*psVar7 != 0);
      psVar7 = psVar9 + 2;
      sVar2 = *psVar7;
    }
    pcVar3 = (char *)((int)psVar7 + (2 - (int)local_8));
    pcVar4 = (char *)malloc(pcVar3);
    if (pcVar4 != (char *)0x0) {
      psVar7 = local_8;
      pcVar8 = pcVar4;
      for (uVar6 = (uint)pcVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)psVar7;
        psVar7 = psVar7 + 2;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar6 = (uint)pcVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = (char)*psVar7;
        psVar7 = (short *)((int)psVar7 + 1);
        pcVar8 = pcVar8 + 1;
      }
      FreeEnvironmentStringsW(local_8);
      return pcVar4;
    }
    FreeEnvironmentStringsW(local_8);
    return (char *)0x0;
  }
  pcVar3 = (char *)DAT_008882d8._260_4_;
  if (DAT_008882d8._260_4_ == 2) {
    if ((local_8 == (short *)0x0) &&
       (local_8 = (short *)GetEnvironmentStrings(), local_8 == (short *)0x0)) {
      return (char *)0x0;
    }
    cVar1 = (char)*local_8;
    psVar7 = local_8;
    while (cVar1 != '\0') {
      iVar5 = MultiByteToWideChar(___lc_codepage,1,psVar7,0xffffffff,0,0);
      if (iVar5 == 0) {
        return (char *)0x0;
      }
      local_4 = local_4 + iVar5;
      uVar6 = 0xffffffff;
      psVar9 = psVar7;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        sVar2 = *psVar9;
        psVar9 = (short *)((int)psVar9 + 1);
      } while ((char)sVar2 != '\0');
      pcVar3 = (char *)((int)psVar7 + ~uVar6);
      psVar7 = (short *)((int)psVar7 + ~uVar6);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)malloc((local_4 + 1) * 2);
    if (pcVar3 == (char *)0x0) {
      FreeEnvironmentStringsA(local_8);
      return (char *)0x0;
    }
    cVar1 = (char)*local_8;
    pcVar4 = pcVar3;
    psVar7 = local_8;
    while (cVar1 != '\0') {
      iVar5 = MultiByteToWideChar(___lc_codepage,1,psVar7,0xffffffff,pcVar4,
                                  (local_4 + 1) - ((int)pcVar4 - (int)pcVar3 >> 1));
      if (iVar5 == 0) {
        free(pcVar3);
        FreeEnvironmentStringsA(local_8);
        return (char *)0x0;
      }
      uVar6 = 0xffffffff;
      psVar9 = psVar7;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        sVar2 = *psVar9;
        psVar9 = (short *)((int)psVar9 + 1);
      } while ((char)sVar2 != '\0');
      psVar7 = (short *)((int)psVar7 + ~uVar6);
      iVar5 = wcslen(pcVar4);
      pcVar4 = pcVar4 + iVar5 * 2 + 2;
      cVar1 = (char)*psVar7;
    }
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    FreeEnvironmentStringsA(local_8);
  }
  return pcVar3;
}

// --------------------------------------------------

// Function: FUN_00556f0c
// Address: 00556f0c
// XREFS: None
char * FUN_00556f0c(void)
{
  char cVar1;
  short sVar2;
  short *psVar3;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  char *pcVar10;
  short *psVar11;
  char *pcVar12;
  char *pcVar13;
  short *psVar4;
  
  psVar11 = (short *)0x0;
  pcVar10 = (char *)0x0;
  if (DAT_008883e0 == 0) {
    psVar11 = (short *)GetEnvironmentStringsW();
    if (psVar11 == (short *)0x0) {
      pcVar10 = (char *)GetEnvironmentStrings();
      if (pcVar10 == (char *)0x0) {
        return (char *)0x0;
      }
      DAT_008883e0 = 2;
    }
    else {
      DAT_008883e0 = 1;
    }
  }
  if (DAT_008883e0 == 1) {
    if ((psVar11 != (short *)0x0) ||
       (psVar11 = (short *)GetEnvironmentStringsW(), psVar11 != (short *)0x0)) {
      sVar2 = *psVar11;
      psVar3 = psVar11;
      while (sVar2 != 0) {
        do {
          psVar4 = psVar3;
          psVar3 = psVar4 + 1;
        } while (*psVar3 != 0);
        psVar3 = psVar4 + 2;
        sVar2 = *psVar3;
      }
      iVar5 = ((int)psVar3 - (int)psVar11 >> 1) + 1;
      iVar6 = WideCharToMultiByte(0,0,psVar11,iVar5,0,0,0,0);
      if ((iVar6 != 0) && (pcVar10 = (char *)malloc(iVar6), pcVar10 != (char *)0x0)) {
        iVar5 = WideCharToMultiByte(0,0,psVar11,iVar5,pcVar10,iVar6,0,0);
        if (iVar5 == 0) {
          free(pcVar10);
          pcVar10 = (char *)0x0;
        }
        FreeEnvironmentStringsW(psVar11);
        return pcVar10;
      }
      FreeEnvironmentStringsW(psVar11);
      return (char *)0x0;
    }
  }
  else if ((DAT_008883e0 == 2) &&
          ((pcVar10 != (char *)0x0 ||
           (pcVar10 = (char *)GetEnvironmentStrings(), pcVar10 != (char *)0x0)))) {
    cVar1 = *pcVar10;
    pcVar7 = pcVar10;
    while (cVar1 != '\0') {
      do {
        pcVar8 = pcVar7;
        pcVar7 = pcVar8 + 1;
      } while (pcVar8[1] != '\0');
      pcVar7 = pcVar8 + 2;
      cVar1 = pcVar8[2];
    }
    pcVar7 = pcVar7 + (1 - (int)pcVar10);
    pcVar8 = (char *)malloc(pcVar7);
    if (pcVar8 != (char *)0x0) {
      pcVar12 = pcVar10;
      pcVar13 = pcVar8;
      for (uVar9 = (uint)pcVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar9 = (uint)pcVar7 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pcVar13 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar13 = pcVar13 + 1;
      }
      FreeEnvironmentStringsA(pcVar10);
      return pcVar8;
    }
    FreeEnvironmentStringsA(pcVar10);
    return (char *)0x0;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: ___crtGetEnvironmentStringsA
// Address: 00556f10
// XREFS: entry
char * ___crtGetEnvironmentStringsA(void)
{
  char cVar1;
  short sVar2;
  short *psVar3;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  char *pcVar10;
  short *psVar11;
  char *pcVar12;
  char *pcVar13;
  short *psVar4;
  
  psVar11 = (short *)0x0;
  pcVar10 = (char *)0x0;
  if (DAT_008883e0 == 0) {
    psVar11 = (short *)GetEnvironmentStringsW();
    if (psVar11 == (short *)0x0) {
      pcVar10 = (char *)GetEnvironmentStrings();
      if (pcVar10 == (char *)0x0) {
        return (char *)0x0;
      }
      DAT_008883e0 = 2;
    }
    else {
      DAT_008883e0 = 1;
    }
  }
  if (DAT_008883e0 == 1) {
    if ((psVar11 != (short *)0x0) ||
       (psVar11 = (short *)GetEnvironmentStringsW(), psVar11 != (short *)0x0)) {
      sVar2 = *psVar11;
      psVar3 = psVar11;
      while (sVar2 != 0) {
        do {
          psVar4 = psVar3;
          psVar3 = psVar4 + 1;
        } while (*psVar3 != 0);
        psVar3 = psVar4 + 2;
        sVar2 = *psVar3;
      }
      iVar5 = ((int)psVar3 - (int)psVar11 >> 1) + 1;
      iVar6 = WideCharToMultiByte(0,0,psVar11,iVar5,0,0,0,0);
      if ((iVar6 != 0) && (pcVar10 = (char *)malloc(iVar6), pcVar10 != (char *)0x0)) {
        iVar5 = WideCharToMultiByte(0,0,psVar11,iVar5,pcVar10,iVar6,0,0);
        if (iVar5 == 0) {
          free(pcVar10);
          pcVar10 = (char *)0x0;
        }
        FreeEnvironmentStringsW(psVar11);
        return pcVar10;
      }
      FreeEnvironmentStringsW(psVar11);
      return (char *)0x0;
    }
  }
  else if ((DAT_008883e0 == 2) &&
          ((pcVar10 != (char *)0x0 ||
           (pcVar10 = (char *)GetEnvironmentStrings(), pcVar10 != (char *)0x0)))) {
    cVar1 = *pcVar10;
    pcVar7 = pcVar10;
    while (cVar1 != '\0') {
      do {
        pcVar8 = pcVar7;
        pcVar7 = pcVar8 + 1;
      } while (pcVar8[1] != '\0');
      pcVar7 = pcVar8 + 2;
      cVar1 = pcVar8[2];
    }
    pcVar7 = pcVar7 + (1 - (int)pcVar10);
    pcVar8 = (char *)malloc(pcVar7);
    if (pcVar8 != (char *)0x0) {
      pcVar12 = pcVar10;
      pcVar13 = pcVar8;
      for (uVar9 = (uint)pcVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar9 = (uint)pcVar7 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pcVar13 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar13 = pcVar13 + 1;
      }
      FreeEnvironmentStringsA(pcVar10);
      return pcVar8;
    }
    FreeEnvironmentStringsA(pcVar10);
    return (char *)0x0;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: FUN_00557066
// Address: 00557066
// XREFS: None
void FUN_00557066(void)
{
  if ((___error_mode == 1) || ((___error_mode == 0 && (___app_type == 1)))) {
    __NMSG_WRITE(0xfc);
    if (__adbgmsg != (code *)0x0) {
      (*__adbgmsg)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}

// --------------------------------------------------

// Function: __FF_MSGBANNER
// Address: 00557070
// XREFS: __amsg_exit
void __FF_MSGBANNER(void)
{
  if ((___error_mode == 1) || ((___error_mode == 0 && (___app_type == 1)))) {
    __NMSG_WRITE(0xfc);
    if (__adbgmsg != (code *)0x0) {
      (*__adbgmsg)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005570ad
// Address: 005570ad
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Runtime_Error___Program__: "Runtime Error!\n\nProgram: "
// [HELPER] s___: "]\n"
void FUN_005570ad(int param_1)
{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *pcVar11;
  undefined1 auStack_1a8 [92];
  char acStack_14c [60];
  char acStack_110 [12];
  undefined1 auStack_104 [260];
  
  piVar2 = &DAT_00592600;
  iVar7 = 0;
  do {
    if (param_1 == *piVar2) break;
    piVar2 = piVar2 + 2;
    iVar7 = iVar7 + 1;
  } while (piVar2 < &DAT_00592690);
  if (param_1 == (&DAT_00592600)[iVar7 * 2]) {
    if ((___error_mode == 1) || ((___error_mode == 0 && (___app_type == 1)))) {
      if ((___pioinfo == 0) || (iVar3 = *(int *)(___pioinfo + 0x10), iVar3 == -1)) {
        iVar3 = GetStdHandle(0xfffffff4);
      }
      pcVar6 = *(char **)(iVar7 * 8 + 0x592604);
      uVar4 = 0xffffffff;
      pcVar11 = pcVar6;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar1 != '\0');
      WriteFile(iVar3,pcVar6,~uVar4 - 1,auStack_1a8,0);
    }
    else if (param_1 != 0xfc) {
      iVar3 = GetModuleFileNameA(0,auStack_104,0x104);
      if (iVar3 == 0) {
        puVar8 = &s_<program_name_unknown>;
        pcVar6 = acStack_110;
        for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined4 *)pcVar6 = *puVar8;
          puVar8 = puVar8 + 1;
          pcVar6 = pcVar6 + 4;
        }
        *(undefined2 *)pcVar6 = *(undefined2 *)puVar8;
        pcVar6[2] = *(char *)((int)puVar8 + 2);
      }
      uVar4 = 0xffffffff;
      pcVar6 = acStack_110;
      pcVar11 = acStack_110;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar1 != '\0');
      if (0x3c < ~uVar4) {
        uVar4 = 0xffffffff;
        pcVar6 = acStack_110;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        pcVar6 = acStack_14c + ~uVar4;
        strncpy(pcVar6,"...",3);
      }
      puVar8 = &s_Runtime_Error___Program__;
      puVar9 = (undefined4 *)&stack0xfffffe50;
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      *(undefined2 *)puVar9 = *(undefined2 *)puVar8;
      uVar4 = 0xffffffff;
      do {
        pcVar11 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar11 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar11;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar3 = -1;
      pcVar6 = &stack0xfffffe50;
      do {
        pcVar10 = pcVar6;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar10 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar10;
      } while (cVar1 != '\0');
      pcVar6 = pcVar11 + -uVar4;
      pcVar11 = pcVar10 + -1;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar11 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar4 = 0xffffffff;
      pcVar6 = &s___;
      do {
        pcVar11 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar11 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar11;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar3 = -1;
      pcVar6 = &stack0xfffffe50;
      do {
        pcVar10 = pcVar6;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar10 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar10;
      } while (cVar1 != '\0');
      pcVar6 = pcVar11 + -uVar4;
      pcVar11 = pcVar10 + -1;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar11 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar4 = 0xffffffff;
      pcVar6 = *(char **)(iVar7 * 8 + 0x592604);
      do {
        pcVar11 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar11 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar11;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar7 = -1;
      pcVar6 = &stack0xfffffe50;
      do {
        pcVar10 = pcVar6;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar10 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar10;
      } while (cVar1 != '\0');
      pcVar6 = pcVar11 + -uVar4;
      pcVar11 = pcVar10 + -1;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar11 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar11 = pcVar11 + 1;
      }
      ___crtMessageBoxA(&stack0xfffffe50,"Microsoft Visual C++ Runtime Library");
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: __NMSG_WRITE
// Address: 005570b0
// XREFS: __FF_MSGBANNER, __amsg_exit, abort
// [HELPER] s_: ""
// [HELPER] s_Runtime_Error___Program__: "Runtime Error!\n\nProgram: "
// [HELPER] s___: "]\n"
void __NMSG_WRITE(int param_1)
{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *pcVar11;
  undefined1 local_1a8 [92];
  char acStack_14c [60];
  char acStack_110 [12];
  undefined1 local_104 [260];
  
  piVar2 = &DAT_00592600;
  iVar7 = 0;
  do {
    if (param_1 == *piVar2) break;
    piVar2 = piVar2 + 2;
    iVar7 = iVar7 + 1;
  } while (piVar2 < &DAT_00592690);
  if (param_1 == (&DAT_00592600)[iVar7 * 2]) {
    if ((___error_mode == 1) || ((___error_mode == 0 && (___app_type == 1)))) {
      if ((___pioinfo == 0) || (iVar3 = *(int *)(___pioinfo + 0x10), iVar3 == -1)) {
        iVar3 = GetStdHandle(0xfffffff4);
      }
      pcVar6 = *(char **)(iVar7 * 8 + 0x592604);
      uVar4 = 0xffffffff;
      pcVar11 = pcVar6;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar1 != '\0');
      WriteFile(iVar3,pcVar6,~uVar4 - 1,local_1a8,0);
    }
    else if (param_1 != 0xfc) {
      iVar3 = GetModuleFileNameA(0,local_104,0x104);
      if (iVar3 == 0) {
        puVar8 = &s_<program_name_unknown>;
        pcVar6 = acStack_110;
        for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined4 *)pcVar6 = *puVar8;
          puVar8 = puVar8 + 1;
          pcVar6 = pcVar6 + 4;
        }
        *(undefined2 *)pcVar6 = *(undefined2 *)puVar8;
        pcVar6[2] = *(char *)((int)puVar8 + 2);
      }
      uVar4 = 0xffffffff;
      pcVar6 = acStack_110;
      pcVar11 = acStack_110;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar1 != '\0');
      if (0x3c < ~uVar4) {
        uVar4 = 0xffffffff;
        pcVar6 = acStack_110;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        pcVar6 = acStack_14c + ~uVar4;
        strncpy(pcVar6,"...",3);
      }
      puVar8 = &s_Runtime_Error___Program__;
      puVar9 = (undefined4 *)&stack0xfffffe50;
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      *(undefined2 *)puVar9 = *(undefined2 *)puVar8;
      uVar4 = 0xffffffff;
      do {
        pcVar11 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar11 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar11;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar3 = -1;
      pcVar6 = &stack0xfffffe50;
      do {
        pcVar10 = pcVar6;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar10 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar10;
      } while (cVar1 != '\0');
      pcVar6 = pcVar11 + -uVar4;
      pcVar11 = pcVar10 + -1;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar11 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar4 = 0xffffffff;
      pcVar6 = &s___;
      do {
        pcVar11 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar11 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar11;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar3 = -1;
      pcVar6 = &stack0xfffffe50;
      do {
        pcVar10 = pcVar6;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar10 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar10;
      } while (cVar1 != '\0');
      pcVar6 = pcVar11 + -uVar4;
      pcVar11 = pcVar10 + -1;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar11 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar4 = 0xffffffff;
      pcVar6 = *(char **)(iVar7 * 8 + 0x592604);
      do {
        pcVar11 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar11 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar11;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar7 = -1;
      pcVar6 = &stack0xfffffe50;
      do {
        pcVar10 = pcVar6;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar10 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar10;
      } while (cVar1 != '\0');
      pcVar6 = pcVar11 + -uVar4;
      pcVar11 = pcVar10 + -1;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar11 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar11 = pcVar11 + 1;
      }
      ___crtMessageBoxA(&stack0xfffffe50,"Microsoft Visual C++ Runtime Library");
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00557286
// Address: 00557286
// XREFS: None
undefined4 FUN_00557286(int param_1)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_00592600;
  do {
    if (param_1 == *piVar1) break;
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + 1;
  } while (piVar1 < &DAT_00592690);
  if (param_1 == (&DAT_00592600)[iVar2 * 2]) {
    return *(undefined4 *)(iVar2 * 8 + 0x592604);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005572be
// Address: 005572be
// XREFS: None
int FUN_005572be(int *param_1)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    terminate();
    return 1;
  }
  if (DAT_008883e8 != (_func_int *)0x0) {
    iVar2 = _ValidateExecute(DAT_008883e8);
    if (iVar2 != 0) {
      iVar2 = (*DAT_008883e8)(param_1);
      return iVar2;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: __CxxUnhandledExceptionFilter
// Address: 005572c0
// XREFS: __CxxSetUnhandledExceptionFilter
/* long __stdcall __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS *) */

long __CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS *param_1)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    terminate();
    return 1;
  }
  if (DAT_008883e8 != (_func_int *)0x0) {
    iVar2 = _ValidateExecute(DAT_008883e8);
    if (iVar2 != 0) {
      iVar2 = (*DAT_008883e8)(param_1);
      return iVar2;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00557313
// Address: 00557313
// XREFS: None
void FUN_00557313(void)
{
  DAT_008883e8 = SetUnhandledExceptionFilter(__CxxUnhandledExceptionFilter);
  return;
}

// --------------------------------------------------

// Function: __CxxSetUnhandledExceptionFilter
// Address: 00557320
// XREFS: None
/* void __cdecl __CxxSetUnhandledExceptionFilter(void) */

void __cdecl __CxxSetUnhandledExceptionFilter(void)
{
  DAT_008883e8 = SetUnhandledExceptionFilter(__CxxUnhandledExceptionFilter);
  return;
}

// --------------------------------------------------

// Function: FUN_00557331
// Address: 00557331
// XREFS: None
void FUN_00557331(void)
{
  SetUnhandledExceptionFilter(DAT_008883e8);
  return;
}

// --------------------------------------------------

// Function: __CxxRestoreUnhandledExceptionFilter
// Address: 00557340
// XREFS: None
/* void __cdecl __CxxRestoreUnhandledExceptionFilter(void) */

void __cdecl __CxxRestoreUnhandledExceptionFilter(void)
{
  SetUnhandledExceptionFilter(DAT_008883e8);
  return;
}

// --------------------------------------------------

// Function: FUN_0055734d
// Address: 0055734d
// XREFS: None
bool FUN_0055734d(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = IsBadReadPtr(param_1,param_2);
  return iVar1 == 0;
}

// --------------------------------------------------

// Function: _ValidateRead
// Address: 00557350
// XREFS: FUN_0054fb10, FUN_00550180
/* int __cdecl _ValidateRead(void const *,unsigned int) */

int __cdecl _ValidateRead(void *param_1,uint param_2)
{
  int iVar1;
  
  iVar1 = IsBadReadPtr(param_1,param_2);
  return (uint)(iVar1 == 0);
}

// --------------------------------------------------

// Function: _ValidateWrite
// Address: 00557370
// XREFS: FUN_00550180
/* int __cdecl _ValidateWrite(void *,unsigned int) */

int __cdecl _ValidateWrite(void *param_1,uint param_2)
{
  int iVar1;
  
  iVar1 = IsBadWritePtr(param_1,param_2);
  return (uint)(iVar1 == 0);
}

// --------------------------------------------------

// Function: _ValidateExecute
// Address: 00557390
// XREFS: FUN_00550180, __CxxUnhandledExceptionFilter
/* int __cdecl _ValidateExecute(int (__stdcall*)(void)) */

int __cdecl _ValidateExecute(_func_int *param_1)
{
  int iVar1;
  
  iVar1 = IsBadCodePtr(param_1);
  return (uint)(iVar1 == 0);
}

// --------------------------------------------------

// Function: FUN_005573ab
// Address: 005573ab
// XREFS: None
undefined4 * FUN_005573ab(undefined4 *param_1,undefined4 *param_2,uint param_3)
{
  uint uVar1;
  undefined4 *puVar2;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    param_2 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar2 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar2 & 3) == 0) {
      uVar1 = param_3 >> 2;
      param_3 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar2 = *param_2;
          param_2 = param_2 + -1;
          puVar2 = puVar2 + -1;
        }
        switch(param_3) {
        case 0:
          return param_1;
        case 2:
          goto switchD_00557567_caseD_2;
        case 3:
          goto switchD_00557567_caseD_3;
        }
        goto switchD_00557567_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_00557567_caseD_0;
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar2 & 3);
        switch((uint)puVar2 & 3) {
        case 1:
          param_3 = uVar1 & 3;
          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
          param_2 = (undefined4 *)((int)param_2 + -1);
          uVar1 = uVar1 >> 2;
          puVar2 = (undefined4 *)((int)puVar2 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar2 = *param_2;
              param_2 = param_2 + -1;
              puVar2 = puVar2 + -1;
            }
            switch(param_3) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00557567_caseD_2;
            case 3:
              goto switchD_00557567_caseD_3;
            }
            goto switchD_00557567_caseD_1;
          }
          break;
        case 2:
          param_3 = uVar1 & 3;
          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
          param_2 = (undefined4 *)((int)param_2 + -2);
          puVar2 = (undefined4 *)((int)puVar2 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar2 = *param_2;
              param_2 = param_2 + -1;
              puVar2 = puVar2 + -1;
            }
            switch(param_3) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00557567_caseD_2;
            case 3:
              goto switchD_00557567_caseD_3;
            }
            goto switchD_00557567_caseD_1;
          }
          break;
        case 3:
          param_3 = uVar1 & 3;
          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
          *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);
          param_2 = (undefined4 *)((int)param_2 + -3);
          puVar2 = (undefined4 *)((int)puVar2 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar2 = *param_2;
              param_2 = param_2 + -1;
              puVar2 = puVar2 + -1;
            }
            switch(param_3) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00557567_caseD_2;
            case 3:
              goto switchD_00557567_caseD_3;
            }
            goto switchD_00557567_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar2[7 - uVar1] = param_2[7 - uVar1];
    case 6:
      puVar2[6 - uVar1] = param_2[6 - uVar1];
    case 5:
      puVar2[5 - uVar1] = param_2[5 - uVar1];
    case 4:
      puVar2[4 - uVar1] = param_2[4 - uVar1];
    case 3:
      puVar2[3 - uVar1] = param_2[3 - uVar1];
    case 2:
      puVar2[2 - uVar1] = param_2[2 - uVar1];
    case 1:
      puVar2[1 - uVar1] = param_2[1 - uVar1];
      param_2 = param_2 + -uVar1;
      puVar2 = puVar2 + -uVar1;
    }
    switch(param_3) {
    case 1:
switchD_00557567_caseD_1:
      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
      return param_1;
    case 2:
switchD_00557567_caseD_2:
      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
      *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
      return param_1;
    case 3:
switchD_00557567_caseD_3:
      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
      *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
      *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);
      return param_1;
    }
switchD_00557567_caseD_0:
    return param_1;
  }
  puVar2 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    param_3 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar2 = *param_2;
        param_2 = param_2 + 1;
        puVar2 = puVar2 + 1;
      }
      switch(param_3) {
      case 0:
        return param_1;
      case 2:
        goto switchD_005573e5_caseD_2;
      case 3:
        goto switchD_005573e5_caseD_3;
      }
      goto switchD_005573e5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_005573e5_caseD_0;
    case 1:
      goto switchD_005573e5_caseD_1;
    case 2:
      goto switchD_005573e5_caseD_2;
    case 3:
      goto switchD_005573e5_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        param_3 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar2 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar2 = *param_2;
            param_2 = param_2 + 1;
            puVar2 = puVar2 + 1;
          }
          switch(param_3) {
          case 0:
            return param_1;
          case 2:
            goto switchD_005573e5_caseD_2;
          case 3:
            goto switchD_005573e5_caseD_3;
          }
          goto switchD_005573e5_caseD_1;
        }
        break;
      case 2:
        param_3 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar2 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar2 = *param_2;
            param_2 = param_2 + 1;
            puVar2 = puVar2 + 1;
          }
          switch(param_3) {
          case 0:
            return param_1;
          case 2:
            goto switchD_005573e5_caseD_2;
          case 3:
            goto switchD_005573e5_caseD_3;
          }
          goto switchD_005573e5_caseD_1;
        }
        break;
      case 3:
        param_3 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar2 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar2 = *param_2;
            param_2 = param_2 + 1;
            puVar2 = puVar2 + 1;
          }
          switch(param_3) {
          case 0:
            return param_1;
          case 2:
            goto switchD_005573e5_caseD_2;
          case 3:
            goto switchD_005573e5_caseD_3;
          }
          goto switchD_005573e5_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar2[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar2[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar2[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar2[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar2[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar2[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar2[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar2 = puVar2 + uVar1;
  }
  switch(param_3) {
  case 1:
switchD_005573e5_caseD_1:
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_005573e5_caseD_2:
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_005573e5_caseD_3:
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_005573e5_caseD_0:
  return param_1;
}

// --------------------------------------------------

// Function: memmove
// Address: 005573b0
// XREFS: FUN_00550180, FUN_00550b70, FUN_00554659
/* memmove */

undefined4 * __cdecl memmove(undefined4 *param_1,undefined4 *param_2,uint param_3)
{
  uint uVar1;
  undefined4 *puVar2;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    param_2 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar2 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar2 & 3) == 0) {
      uVar1 = param_3 >> 2;
      param_3 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar2 = *param_2;
          param_2 = param_2 + -1;
          puVar2 = puVar2 + -1;
        }
        switch(param_3) {
        case 0:
          return param_1;
        case 2:
          goto switchD_00557567_caseD_2;
        case 3:
          goto switchD_00557567_caseD_3;
        }
        goto switchD_00557567_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_00557567_caseD_0;
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar2 & 3);
        switch((uint)puVar2 & 3) {
        case 1:
          param_3 = uVar1 & 3;
          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
          param_2 = (undefined4 *)((int)param_2 + -1);
          uVar1 = uVar1 >> 2;
          puVar2 = (undefined4 *)((int)puVar2 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar2 = *param_2;
              param_2 = param_2 + -1;
              puVar2 = puVar2 + -1;
            }
            switch(param_3) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00557567_caseD_2;
            case 3:
              goto switchD_00557567_caseD_3;
            }
            goto switchD_00557567_caseD_1;
          }
          break;
        case 2:
          param_3 = uVar1 & 3;
          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
          param_2 = (undefined4 *)((int)param_2 + -2);
          puVar2 = (undefined4 *)((int)puVar2 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar2 = *param_2;
              param_2 = param_2 + -1;
              puVar2 = puVar2 + -1;
            }
            switch(param_3) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00557567_caseD_2;
            case 3:
              goto switchD_00557567_caseD_3;
            }
            goto switchD_00557567_caseD_1;
          }
          break;
        case 3:
          param_3 = uVar1 & 3;
          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
          *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);
          param_2 = (undefined4 *)((int)param_2 + -3);
          puVar2 = (undefined4 *)((int)puVar2 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar2 = *param_2;
              param_2 = param_2 + -1;
              puVar2 = puVar2 + -1;
            }
            switch(param_3) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00557567_caseD_2;
            case 3:
              goto switchD_00557567_caseD_3;
            }
            goto switchD_00557567_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar2[7 - uVar1] = param_2[7 - uVar1];
    case 6:
      puVar2[6 - uVar1] = param_2[6 - uVar1];
    case 5:
      puVar2[5 - uVar1] = param_2[5 - uVar1];
    case 4:
      puVar2[4 - uVar1] = param_2[4 - uVar1];
    case 3:
      puVar2[3 - uVar1] = param_2[3 - uVar1];
    case 2:
      puVar2[2 - uVar1] = param_2[2 - uVar1];
    case 1:
      puVar2[1 - uVar1] = param_2[1 - uVar1];
      param_2 = param_2 + -uVar1;
      puVar2 = puVar2 + -uVar1;
    }
    switch(param_3) {
    case 1:
switchD_00557567_caseD_1:
      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
      return param_1;
    case 2:
switchD_00557567_caseD_2:
      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
      *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
      return param_1;
    case 3:
switchD_00557567_caseD_3:
      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
      *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
      *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);
      return param_1;
    }
switchD_00557567_caseD_0:
    return param_1;
  }
  puVar2 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    param_3 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar2 = *param_2;
        param_2 = param_2 + 1;
        puVar2 = puVar2 + 1;
      }
      switch(param_3) {
      case 0:
        return param_1;
      case 2:
        goto switchD_005573e5_caseD_2;
      case 3:
        goto switchD_005573e5_caseD_3;
      }
      goto switchD_005573e5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_005573e5_caseD_0;
    case 1:
      goto switchD_005573e5_caseD_1;
    case 2:
      goto switchD_005573e5_caseD_2;
    case 3:
      goto switchD_005573e5_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        param_3 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar2 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar2 = *param_2;
            param_2 = param_2 + 1;
            puVar2 = puVar2 + 1;
          }
          switch(param_3) {
          case 0:
            return param_1;
          case 2:
            goto switchD_005573e5_caseD_2;
          case 3:
            goto switchD_005573e5_caseD_3;
          }
          goto switchD_005573e5_caseD_1;
        }
        break;
      case 2:
        param_3 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar2 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar2 = *param_2;
            param_2 = param_2 + 1;
            puVar2 = puVar2 + 1;
          }
          switch(param_3) {
          case 0:
            return param_1;
          case 2:
            goto switchD_005573e5_caseD_2;
          case 3:
            goto switchD_005573e5_caseD_3;
          }
          goto switchD_005573e5_caseD_1;
        }
        break;
      case 3:
        param_3 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar2 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar2 = *param_2;
            param_2 = param_2 + 1;
            puVar2 = puVar2 + 1;
          }
          switch(param_3) {
          case 0:
            return param_1;
          case 2:
            goto switchD_005573e5_caseD_2;
          case 3:
            goto switchD_005573e5_caseD_3;
          }
          goto switchD_005573e5_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar2[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar2[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar2[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar2[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar2[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar2[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar2[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar2 = puVar2 + uVar1;
  }
  switch(param_3) {
  case 1:
switchD_005573e5_caseD_1:
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_005573e5_caseD_2:
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_005573e5_caseD_3:
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_005573e5_caseD_0:
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055740b
// Address: 0055740b
// XREFS: None
void __fastcall FUN_0055740b(int param_1)
{
                    /* WARNING: Could not recover jumptable at 0x0055740c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&switchD_0055740c::switchdataD_0055748c)[param_1])();
  return;
}

// --------------------------------------------------

// Function: FUN_00557413
// Address: 00557413
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_00557413(uint param_1,uint param_2)
{
  uint *puVar1;
  byte *pbVar2;
  int in_EAX;
  uint uVar3;
  byte bVar4;
  char *unaff_EBX;
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined4 *puVar5;
  undefined1 *unaff_EDI;
  undefined4 *puVar6;
  
  pbVar2 = (byte *)(unaff_EBP + param_2 * 2);
  bVar4 = (byte)(param_2 >> 8);
  *pbVar2 = *pbVar2 & bVar4;
  if (&stack0x00000000 != (undefined1 *)0x1) {
    *(char *)(in_EAX + 0x74) = *(char *)(in_EAX + 0x74) + bVar4;
    *unaff_EBX = *unaff_EBX + (char)((uint)in_EAX >> 8);
    puVar1 = (uint *)(param_2 + 0x8a078806);
    *puVar1 = *puVar1 >> 1 | (uint)((*puVar1 & 1) != 0) << 0x1f;
    *(int *)(in_EAX + 0x468a0147) = *(int *)(in_EAX + 0x468a0147) + param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *unaff_EDI = *unaff_ESI;
  uVar3 = param_1 >> 2;
  puVar5 = (undefined4 *)(unaff_ESI + 1);
  puVar6 = (undefined4 *)(unaff_EDI + 1);
  switch(uVar3) {
  case 7:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -0x1b) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -0x1b);
  case 6:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -0x17) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -0x17);
  case 5:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -0x13) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -0x13);
  case 4:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -0xf) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -0xf);
  case 3:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -0xb) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -0xb);
  case 2:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -7) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -7);
  case 1:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -3) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -3);
  case 0:
                    /* WARNING: Could not recover jumptable at 0x005574ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  default:
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00557482. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_00557449
// Address: 00557449
// XREFS: None
void __fastcall FUN_00557449(uint param_1,uint param_2)
{
  uint uVar1;
  undefined1 *unaff_ESI;
  undefined4 *puVar2;
  undefined1 *unaff_EDI;
  undefined4 *puVar3;
  
  *unaff_EDI = *unaff_ESI;
  uVar1 = param_1 >> 2;
  unaff_EDI[1] = unaff_ESI[1];
  puVar2 = (undefined4 *)(unaff_ESI + 2);
  puVar3 = (undefined4 *)(unaff_EDI + 2);
  switch(uVar1) {
  case 7:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0x1a) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0x1a);
  case 6:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0x16) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0x16);
  case 5:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0x12) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0x12);
  case 4:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0xe) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0xe);
  case 3:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -10) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -10);
  case 2:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -6) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -6);
  case 1:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -2) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -2);
  case 0:
                    /* WARNING: Could not recover jumptable at 0x005574ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00557468. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_0055746f
// Address: 0055746f
// XREFS: None
void __fastcall FUN_0055746f(uint param_1,uint param_2)
{
  uint uVar1;
  undefined1 *unaff_ESI;
  undefined4 *puVar2;
  undefined1 *unaff_EDI;
  undefined4 *puVar3;
  
  *unaff_EDI = *unaff_ESI;
  uVar1 = param_1 >> 2;
  puVar2 = (undefined4 *)(unaff_ESI + 1);
  puVar3 = (undefined4 *)(unaff_EDI + 1);
  switch(uVar1) {
  case 7:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0x1b) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0x1b);
  case 6:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0x17) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0x17);
  case 5:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0x13) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0x13);
  case 4:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0xf) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0xf);
  case 3:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0xb) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0xb);
  case 2:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -7) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -7);
  case 1:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -3) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -3);
  case 0:
                    /* WARNING: Could not recover jumptable at 0x005574ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00557482. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_00557489
// Address: 00557489
// XREFS: None
/* WARNING: Instruction at (ram,0x005574f4) overlaps instruction at (ram,0x005574ef)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */

char * __fastcall FUN_00557489(uint param_1,uint param_2)
{
  char *pcVar1;
  char cVar2;
  char cVar4;
  uint in_EAX;
  undefined2 uVar5;
  char *pcVar3;
  char cVar6;
  char *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  bool in_ZF;
  bool bVar7;
  
  out((short)param_2,in_EAX);
  if (in_ZF) {
code_r0x005574e4:
                    /* WARNING: Could not recover jumptable at 0x005574ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar3 = (char *)(*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2])();
    return pcVar3;
  }
  uVar5 = (undefined2)(in_EAX >> 0x10);
  cVar2 = (char)in_EAX;
  cVar4 = (char)(in_EAX >> 8) + (char)unaff_EBX;
  pcVar3 = (char *)CONCAT22(uVar5,CONCAT11(cVar4,cVar2));
  if (cVar4 == '\0') {
    *pcVar3 = *pcVar3 + cVar2;
    *unaff_EBX = *unaff_EBX + cVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cVar4 = cVar4 + (char)param_2;
  if (cVar4 == '\0') {
    halt_baddata();
  }
  cVar6 = (char)param_1;
  cVar4 = cVar4 + cVar6;
  if (cVar4 == '\0') {
    pcVar3 = (char *)(CONCAT31((int3)(CONCAT22(uVar5,CONCAT11(cVar4,cVar2)) >> 8),cVar2) &
                     0xffffff95);
    if ((in_EAX & 0x95) != 0) goto code_r0x005574f5;
    unaff_EDI = (undefined4 *)((param_1 - 4) + (int)unaff_EDI);
    bVar7 = ((uint)unaff_EDI & 3) == 0;
  }
  else {
    pcVar3 = (char *)CONCAT22(uVar5,CONCAT11(cVar4 + cVar2,cVar2));
    if ((char)(cVar4 + cVar2) != '\0') {
      (&stack0x74b40055)[(int)unaff_ESI * 2] =
           (&stack0x74b40055)[(int)unaff_ESI * 2] + (char)((uint)unaff_EBX >> 8);
      (&stack0x448b0051)[(int)unaff_ESI * 2] =
           (&stack0x448b0051)[(int)unaff_ESI * 2] + (char)(param_1 >> 8);
      unaff_EDI[param_1 - 7] = pcVar3;
      unaff_EDI[param_1 - 6] = unaff_ESI[param_1 - 6];
      unaff_EDI[param_1 - 5] = unaff_ESI[param_1 - 5];
      unaff_EDI[param_1 - 4] = unaff_ESI[param_1 - 4];
      unaff_EDI[param_1 - 3] = unaff_ESI[param_1 - 3];
      unaff_EDI[param_1 - 2] = unaff_ESI[param_1 - 2];
      unaff_EDI[param_1 - 1] = unaff_ESI[param_1 - 1];
      goto code_r0x005574e4;
    }
code_r0x005574f5:
    unaff_EBX[0x557508c0] = unaff_EBX[0x557508c0] + cVar6;
    *pcVar3 = *pcVar3 + (char)param_2;
    if (*pcVar3 == '\0') {
      pcVar1 = (char *)((int)unaff_ESI * 2 + 0x75300055);
      *pcVar1 = *pcVar1 + (char)unaff_EBX;
      unaff_EBX[0x5f5e0845] = unaff_EBX[0x5f5e0845] + cVar6;
      return pcVar3;
    }
    *pcVar3 = *pcVar3 + (char)pcVar3;
    bVar7 = *pcVar3 == '\0';
  }
  if (bVar7) {
    param_1 = param_1 >> 2;
    param_2 = param_2 & 3;
    if (7 < param_1) {
      for (; param_1 != 0; param_1 = param_1 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(param_2) {
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
      goto switchD_00557567_caseD_0;
    }
  }
  else {
    switch(param_1) {
    case 0:
      goto switchD_00557567_caseD_0;
    case 1:
      goto switchD_00557567_caseD_1;
    case 2:
      goto switchD_00557567_caseD_2;
    case 3:
      goto switchD_00557567_caseD_3;
    default:
      param_1 = param_1 - ((uint)unaff_EDI & 3);
      switch((uint)unaff_EDI & 3) {
      case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 1:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -1);
        param_1 = param_1 >> 2;
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -1);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
        break;
      case 2:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        param_1 = param_1 >> 2;
        *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -2);
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -2);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
        break;
      case 3:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
        param_1 = param_1 >> 2;
        *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -3);
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -3);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
      }
    }
  }
  switch(param_1) {
  case 7:
    unaff_EDI[7 - param_1] = unaff_ESI[7 - param_1];
  case 6:
    unaff_EDI[6 - param_1] = unaff_ESI[6 - param_1];
  case 5:
    unaff_EDI[5 - param_1] = unaff_ESI[5 - param_1];
  case 4:
    unaff_EDI[4 - param_1] = unaff_ESI[4 - param_1];
  case 3:
    unaff_EDI[3 - param_1] = unaff_ESI[3 - param_1];
  case 2:
    unaff_EDI[2 - param_1] = unaff_ESI[2 - param_1];
  case 1:
    unaff_EDI[1 - param_1] = unaff_ESI[1 - param_1];
    unaff_ESI = unaff_ESI + -param_1;
    unaff_EDI = unaff_EDI + -param_1;
  }
  switch(param_2) {
  case 1:
switchD_00557567_caseD_1:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    return *(char **)(unaff_EBP + 8);
  case 2:
switchD_00557567_caseD_2:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    return *(char **)(unaff_EBP + 8);
  case 3:
switchD_00557567_caseD_3:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
    return *(char **)(unaff_EBP + 8);
  }
switchD_00557567_caseD_0:
  return *(char **)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_005574f6
// Address: 005574f6
// XREFS: None
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Control flow encountered bad instruction data */

char * __fastcall FUN_005574f6(uint param_1,uint param_2)
{
  char *pcVar1;
  char *in_EAX;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *(byte *)(unaff_EBP + 0x55) = *(byte *)(unaff_EBP + 0x55) | (byte)(param_2 >> 8);
  *in_EAX = *in_EAX + (char)param_2;
  if (*in_EAX == '\0') {
    pcVar1 = (char *)((int)unaff_ESI * 2 + 0x75300055);
    *pcVar1 = *pcVar1 + (char)unaff_EBX;
    *(char *)(unaff_EBX + 0x5f5e0845) = *(char *)(unaff_EBX + 0x5f5e0845) + (char)param_1;
    return in_EAX;
  }
  *in_EAX = *in_EAX + (char)in_EAX;
  if (*in_EAX == '\0') {
    param_1 = param_1 >> 2;
    param_2 = param_2 & 3;
    if (7 < param_1) {
      for (; param_1 != 0; param_1 = param_1 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(param_2) {
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
      goto switchD_00557567_caseD_0;
    }
  }
  else {
    switch(param_1) {
    case 0:
      goto switchD_00557567_caseD_0;
    case 1:
      goto switchD_00557567_caseD_1;
    case 2:
      goto switchD_00557567_caseD_2;
    case 3:
      goto switchD_00557567_caseD_3;
    default:
      param_1 = param_1 - ((uint)unaff_EDI & 3);
      switch((uint)unaff_EDI & 3) {
      case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 1:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -1);
        param_1 = param_1 >> 2;
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -1);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
        break;
      case 2:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        param_1 = param_1 >> 2;
        *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -2);
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -2);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
        break;
      case 3:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
        param_1 = param_1 >> 2;
        *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -3);
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -3);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
      }
    }
  }
  switch(param_1) {
  case 7:
    unaff_EDI[7 - param_1] = unaff_ESI[7 - param_1];
  case 6:
    unaff_EDI[6 - param_1] = unaff_ESI[6 - param_1];
  case 5:
    unaff_EDI[5 - param_1] = unaff_ESI[5 - param_1];
  case 4:
    unaff_EDI[4 - param_1] = unaff_ESI[4 - param_1];
  case 3:
    unaff_EDI[3 - param_1] = unaff_ESI[3 - param_1];
  case 2:
    unaff_EDI[2 - param_1] = unaff_ESI[2 - param_1];
  case 1:
    unaff_EDI[1 - param_1] = unaff_ESI[1 - param_1];
    unaff_ESI = unaff_ESI + -param_1;
    unaff_EDI = unaff_EDI + -param_1;
  }
  switch(param_2) {
  case 1:
switchD_00557567_caseD_1:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    return *(char **)(unaff_EBP + 8);
  case 2:
switchD_00557567_caseD_2:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    return *(char **)(unaff_EBP + 8);
  case 3:
switchD_00557567_caseD_3:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
    return *(char **)(unaff_EBP + 8);
  }
switchD_00557567_caseD_0:
  return *(char **)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0055750f
// Address: 0055750f
// XREFS: None
undefined4 FUN_0055750f(void)
{
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI;
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0055751b
// Address: 0055751b
// XREFS: None
undefined4 FUN_0055751b(void)
{
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI;
  unaff_EDI[1] = unaff_ESI[1];
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0055752d
// Address: 0055752d
// XREFS: None
undefined4 FUN_0055752d(void)
{
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI;
  unaff_EDI[1] = unaff_ESI[1];
  unaff_EDI[2] = unaff_ESI[2];
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_00557547
// Address: 00557547
// XREFS: None
/* WARNING (jumptable): Stack frame is not setup normally: Input value of stackpointer is not used
    */

undefined4 __fastcall FUN_00557547(uint param_1,uint param_2)
{
  int unaff_EBP;
  int unaff_ESI;
  undefined4 *puVar1;
  int unaff_EDI;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)((param_1 - 4) + unaff_ESI);
  puVar2 = (undefined4 *)((param_1 - 4) + unaff_EDI);
  if (((uint)puVar2 & 3) == 0) {
    param_1 = param_1 >> 2;
    param_2 = param_2 & 3;
    if (7 < param_1) {
      for (; param_1 != 0; param_1 = param_1 - 1) {
        *puVar2 = *puVar1;
        puVar1 = puVar1 + -1;
        puVar2 = puVar2 + -1;
      }
      switch(param_2) {
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
      goto switchD_00557567_caseD_0;
    }
  }
  else {
    switch(param_1) {
    case 0:
      goto switchD_00557567_caseD_0;
    case 1:
      goto switchD_00557567_caseD_1;
    case 2:
      goto switchD_00557567_caseD_2;
    case 3:
      goto switchD_00557567_caseD_3;
    default:
      param_1 = param_1 - ((uint)puVar2 & 3);
      switch((uint)puVar2 & 3) {
      case 1:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
        puVar1 = (undefined4 *)((int)puVar1 + -1);
        param_1 = param_1 >> 2;
        puVar2 = (undefined4 *)((int)puVar2 - 1);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *puVar2 = *puVar1;
            puVar1 = puVar1 + -1;
            puVar2 = puVar2 + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
        break;
      case 2:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
        param_1 = param_1 >> 2;
        *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar1 + 2);
        puVar1 = (undefined4 *)((int)puVar1 + -2);
        puVar2 = (undefined4 *)((int)puVar2 - 2);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *puVar2 = *puVar1;
            puVar1 = puVar1 + -1;
            puVar2 = puVar2 + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
        break;
      case 3:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
        *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar1 + 2);
        param_1 = param_1 >> 2;
        *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)puVar1 + 1);
        puVar1 = (undefined4 *)((int)puVar1 + -3);
        puVar2 = (undefined4 *)((int)puVar2 - 3);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *puVar2 = *puVar1;
            puVar1 = puVar1 + -1;
            puVar2 = puVar2 + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
      }
    }
  }
  switch(param_1) {
  case 7:
    puVar2[7 - param_1] = puVar1[7 - param_1];
  case 6:
    puVar2[6 - param_1] = puVar1[6 - param_1];
  case 5:
    puVar2[5 - param_1] = puVar1[5 - param_1];
  case 4:
    puVar2[4 - param_1] = puVar1[4 - param_1];
  case 3:
    puVar2[3 - param_1] = puVar1[3 - param_1];
  case 2:
    puVar2[2 - param_1] = puVar1[2 - param_1];
  case 1:
    puVar2[1 - param_1] = puVar1[1 - param_1];
    puVar1 = puVar1 + -param_1;
    puVar2 = puVar2 + -param_1;
  }
  switch(param_2) {
  case 1:
switchD_00557567_caseD_1:
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
    return *(undefined4 *)(unaff_EBP + 8);
  case 2:
switchD_00557567_caseD_2:
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar1 + 2);
    return *(undefined4 *)(unaff_EBP + 8);
  case 3:
switchD_00557567_caseD_3:
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar1 + 2);
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)puVar1 + 1);
    return *(undefined4 *)(unaff_EBP + 8);
  }
switchD_00557567_caseD_0:
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0055756e
// Address: 0055756e
// XREFS: None
void __fastcall FUN_0055756e(int param_1)
{
                    /* WARNING: Could not recover jumptable at 0x00557572. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_caseD_0_00557640)[-param_1])();
  return;
}

// --------------------------------------------------

// Function: FUN_00557579
// Address: 00557579
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Stack frame is not setup normally: Input value of stackpointer is not used
    */

undefined4 __fastcall FUN_00557579(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  switch(param_1) {
  case 0:
    goto switchD_00557567_caseD_0;
  case 1:
switchD_00557567_caseD_1:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    return *(undefined4 *)(unaff_EBP + 8);
  case 2:
switchD_00557567_caseD_2:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    return *(undefined4 *)(unaff_EBP + 8);
  case 3:
switchD_00557567_caseD_3:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
    return *(undefined4 *)(unaff_EBP + 8);
  default:
    uVar2 = param_1 - ((uint)unaff_EDI & 3);
    switch((uint)unaff_EDI & 3) {
    case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 1:
      *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
      unaff_ESI = (undefined4 *)((int)unaff_ESI + -1);
      uVar3 = uVar2 >> 2;
      unaff_EDI = (undefined4 *)((int)unaff_EDI + -1);
      if (uVar3 < 8) {
LAB_00557570:
                    /* WARNING: Could not recover jumptable at 0x00557572. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*(code *)(&PTR_caseD_0_00557640)[-(uVar2 >> 2)])();
        return uVar1;
      }
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(uVar2 & 3) {
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
      break;
    case 2:
      *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
      uVar3 = uVar2 >> 2;
      *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
      unaff_ESI = (undefined4 *)((int)unaff_ESI + -2);
      unaff_EDI = (undefined4 *)((int)unaff_EDI + -2);
      if (uVar3 < 8) goto LAB_00557570;
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(uVar2 & 3) {
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
      break;
    case 3:
      *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
      *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
      uVar3 = uVar2 >> 2;
      *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
      unaff_ESI = (undefined4 *)((int)unaff_ESI + -3);
      unaff_EDI = (undefined4 *)((int)unaff_EDI + -3);
      if (uVar3 < 8) goto LAB_00557570;
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(uVar2 & 3) {
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
    }
switchD_00557567_caseD_0:
    return *(undefined4 *)(unaff_EBP + 8);
  }
}

// --------------------------------------------------

// Function: FUN_0055759b
// Address: 0055759b
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x005575fe) overlaps instruction at (ram,0x005575fd)
    */

void __fastcall FUN_0055759b(uint param_1,int param_2)
{
  undefined4 in_EAX;
  char cVar1;
  uint uVar2;
  char cVar3;
  int unaff_ESI;
  undefined4 *puVar4;
  int unaff_EDI;
  undefined4 *puVar5;
  
  cVar1 = (char)param_1;
  if ((char)((char)in_EAX + cVar1) == '\0') {
    cVar3 = (char)((uint)param_2 >> 8);
    if (cVar3 != '\0') {
      *(byte *)(unaff_EDI + 1) =
           *(byte *)(unaff_EDI + 1) |
           cVar1 + *(char *)(param_2 + -0x163efeba) +
           *(char *)(CONCAT31((int3)((uint)in_EAX >> 8),cVar3) + -0x117cfeb9);
      *(char *)(param_2 + -1) = *(char *)(param_2 + -1) + '\x01';
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *(char *)(param_2 + -0x2edcfcba) = *(char *)(param_2 + -0x2edcfcba) + cVar1;
    *(undefined1 *)(unaff_EDI + 3) = 0;
    puVar4 = (undefined4 *)(unaff_ESI + -1);
    uVar2 = param_1 >> 2;
    puVar5 = (undefined4 *)(unaff_EDI + -1);
    if (7 < uVar2) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar5 = puVar5 + -1;
      }
                    /* WARNING: Could not recover jumptable at 0x005575be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2])();
      return;
    }
  }
  else {
    *(undefined1 *)(unaff_EDI + 2) = *(undefined1 *)(unaff_ESI + 2);
    uVar2 = param_1 >> 2;
    *(undefined1 *)(unaff_EDI + 1) = *(undefined1 *)(unaff_ESI + 1);
    puVar4 = (undefined4 *)(unaff_ESI + -3);
    puVar5 = (undefined4 *)(unaff_EDI + -3);
    if (7 < uVar2) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar5 = puVar5 + -1;
      }
                    /* WARNING: Could not recover jumptable at 0x0055761a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2])();
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00557572. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_caseD_0_00557640)[-(param_1 >> 2)])();
  return;
}

// --------------------------------------------------

// Function: FUN_005575c5
// Address: 005575c5
// XREFS: None
void __fastcall FUN_005575c5(uint param_1,uint param_2)
{
  uint uVar1;
  int unaff_ESI;
  undefined4 *puVar2;
  int unaff_EDI;
  undefined4 *puVar3;
  
  *(undefined1 *)(unaff_EDI + 3) = *(undefined1 *)(unaff_ESI + 3);
  uVar1 = param_1 >> 2;
  *(undefined1 *)(unaff_EDI + 2) = *(undefined1 *)(unaff_ESI + 2);
  puVar2 = (undefined4 *)(unaff_ESI + -2);
  puVar3 = (undefined4 *)(unaff_EDI + -2);
  switch(uVar1) {
  case 7:
    *(undefined4 *)(unaff_EDI + 0x1a + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0x1a + uVar1 * -4);
  case 6:
    *(undefined4 *)(unaff_EDI + 0x16 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0x16 + uVar1 * -4);
  case 5:
    *(undefined4 *)(unaff_EDI + 0x12 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0x12 + uVar1 * -4);
  case 4:
    *(undefined4 *)(unaff_EDI + 0xe + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0xe + uVar1 * -4);
  case 3:
    *(undefined4 *)(unaff_EDI + 10 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 10 + uVar1 * -4);
  case 2:
    *(undefined4 *)(unaff_EDI + 6 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 6 + uVar1 * -4);
  case 1:
    *(undefined4 *)(unaff_EDI + 2 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 2 + uVar1 * -4);
  case 0:
                    /* WARNING: Could not recover jumptable at 0x00557687. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + -1;
      puVar3 = puVar3 + -1;
    }
                    /* WARNING: Could not recover jumptable at 0x005575e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_005575ef
// Address: 005575ef
// XREFS: None
void __fastcall FUN_005575ef(uint param_1,uint param_2)
{
  uint uVar1;
  int unaff_ESI;
  undefined4 *puVar2;
  int unaff_EDI;
  undefined4 *puVar3;
  
  *(undefined1 *)(unaff_EDI + 3) = *(undefined1 *)(unaff_ESI + 3);
  *(undefined1 *)(unaff_EDI + 2) = *(undefined1 *)(unaff_ESI + 2);
  uVar1 = param_1 >> 2;
  *(undefined1 *)(unaff_EDI + 1) = *(undefined1 *)(unaff_ESI + 1);
  puVar2 = (undefined4 *)(unaff_ESI + -3);
  puVar3 = (undefined4 *)(unaff_EDI + -3);
  switch(uVar1) {
  case 7:
    *(undefined4 *)(unaff_EDI + 0x19 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0x19 + uVar1 * -4);
  case 6:
    *(undefined4 *)(unaff_EDI + 0x15 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0x15 + uVar1 * -4);
  case 5:
    *(undefined4 *)(unaff_EDI + 0x11 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0x11 + uVar1 * -4);
  case 4:
    *(undefined4 *)(unaff_EDI + 0xd + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0xd + uVar1 * -4);
  case 3:
    *(undefined4 *)(unaff_EDI + 9 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 9 + uVar1 * -4);
  case 2:
    *(undefined4 *)(unaff_EDI + 5 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 5 + uVar1 * -4);
  case 1:
    *(undefined4 *)(unaff_EDI + 1 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 1 + uVar1 * -4);
  case 0:
                    /* WARNING: Could not recover jumptable at 0x00557687. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + -1;
      puVar3 = puVar3 + -1;
    }
                    /* WARNING: Could not recover jumptable at 0x0055761a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_00557621
// Address: 00557621
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_00557621(undefined4 param_1,int param_2)
{
  char *pcVar1;
  undefined4 in_EAX;
  char unaff_BL;
  int unaff_ESI;
  int unaff_EDI;
  bool in_CF;
  
  if (!in_CF && &stack0x00000000 != (undefined1 *)0xffffffff) {
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + (char)param_1;
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + (char)param_2;
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + unaff_BL;
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + (char)((uint)in_EAX >> 8);
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + (char)((uint)param_1 >> 8);
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + (char)((uint)param_2 >> 8);
    *(char *)(unaff_EDI + -0x74ffaa8a) = *(char *)(unaff_EDI + -0x74ffaa8a) + (char)in_EAX;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Could not recover jumptable at 0x00557687. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2])();
  return;
}

// --------------------------------------------------

// Function: FUN_0055768e
// Address: 0055768e
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_0055768e(char param_1)
{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 in_EAX;
  byte bVar4;
  int unaff_EBX;
  bool in_CF;
  bool in_ZF;
  
  if (in_CF || in_ZF) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  pbVar1 = (byte *)(CONCAT31((int3)((uint)in_EAX >> 8),uRama8005576) + -0x33ffaa8a);
  bVar2 = *pbVar1;
  bVar4 = (byte)((uint)unaff_EBX >> 8);
  *pbVar1 = *pbVar1 + bVar4;
  if (!CARRY1(bVar2,bVar4) && *pbVar1 != 0) {
    *(char *)(unaff_EBX + 0x5f5e0845) = *(char *)(unaff_EBX + 0x5f5e0845) + param_1;
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_005576a7
// Address: 005576a7
// XREFS: None
undefined4 FUN_005576a7(void)
{
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 3) = *(undefined1 *)(unaff_ESI + 3);
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_005576b5
// Address: 005576b5
// XREFS: None
undefined4 FUN_005576b5(void)
{
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 3) = *(undefined1 *)(unaff_ESI + 3);
  *(undefined1 *)(unaff_EDI + 2) = *(undefined1 *)(unaff_ESI + 2);
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_005576cb
// Address: 005576cb
// XREFS: None
undefined4 FUN_005576cb(void)
{
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 3) = *(undefined1 *)(unaff_ESI + 3);
  *(undefined1 *)(unaff_EDI + 2) = *(undefined1 *)(unaff_ESI + 2);
  *(undefined1 *)(unaff_EDI + 1) = *(undefined1 *)(unaff_ESI + 1);
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: abort
// Address: 005576f0
// XREFS: FUN_005504fe
/* abort */

void __cdecl abort(void)
{
  __NMSG_WRITE(10);
  raise(0x16);
  __exit(3);
  return;
}

// --------------------------------------------------

// Function: FUN_0055770f
// Address: 0055770f
// XREFS: None
void FUN_0055770f(void)
{
  FUN_00557910();
  return;
}

// --------------------------------------------------

// Function: __statusfp
// Address: 00557710
// XREFS: None
void __statusfp(void)
{
  FUN_00557910();
  return;
}

// --------------------------------------------------

// Function: FUN_00557728
// Address: 00557728
// XREFS: None
void FUN_00557728(void)
{
  FUN_00557910();
  return;
}

// --------------------------------------------------

// Function: __clearfp
// Address: 00557730
// XREFS: None
void __clearfp(void)
{
  FUN_00557910();
  return;
}

// --------------------------------------------------

// Function: FUN_00557749
// Address: 00557749
// XREFS: None
uint FUN_00557749(uint param_1,uint param_2)
{
  uint uVar1;
  
  uVar1 = FUN_005577e0();
  uVar1 = param_2 & param_1 | ~param_2 & uVar1;
  FUN_00557880(uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: __control87
// Address: 00557750
// XREFS: __controlfp
uint __control87(uint param_1,uint param_2)
{
  uint uVar1;
  
  uVar1 = FUN_005577e0();
  uVar1 = param_2 & param_1 | ~param_2 & uVar1;
  FUN_00557880(uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0055778b
// Address: 0055778b
// XREFS: None
void FUN_0055778b(undefined4 param_1,uint param_2)
{
  __control87(param_1,param_2 & 0xfff7ffff);
  return;
}

// --------------------------------------------------

// Function: __controlfp
// Address: 00557790
// XREFS: __setdefaultprecision
void __controlfp(undefined4 param_1,uint param_2)
{
  __control87(param_1,param_2 & 0xfff7ffff);
  return;
}

// --------------------------------------------------

// Function: FUN_005577a8
// Address: 005577a8
// XREFS: None
void FUN_005577a8(void)
{
  uint *puVar1;
  int iVar2;
  
  iVar2 = __pxcptinfoptrs;
  __setdefaultprecision();
  if ((iVar2 != 0) && (puVar1 = *(uint **)(iVar2 + 4), (*puVar1 & 0x10008) != 0)) {
    puVar1[8] = 0;
    puVar1[9] = 0xffff;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005577dd
// Address: 005577dd
// XREFS: None
uint FUN_005577dd(uint param_1)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = param_1 & 0xc00;
  if (uVar2 < 0x401) {
    if (uVar2 == 0x400) {
      uVar1 = uVar1 | 0x100;
    }
  }
  else if (uVar2 == 0x800) {
    uVar1 = uVar1 | 0x200;
  }
  else if (uVar2 == 0xc00) {
    uVar1 = uVar1 | 0x300;
  }
  if ((param_1 & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((param_1 & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_1 & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_005577e0
// Address: 005577e0
// XREFS: __control87
uint FUN_005577e0(uint param_1)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = param_1 & 0xc00;
  if (uVar2 < 0x401) {
    if (uVar2 == 0x400) {
      uVar1 = uVar1 | 0x100;
    }
  }
  else if (uVar2 == 0x800) {
    uVar1 = uVar1 | 0x200;
  }
  else if (uVar2 == 0xc00) {
    uVar1 = uVar1 | 0x300;
  }
  if ((param_1 & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((param_1 & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_1 & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_00557876
// Address: 00557876
// XREFS: None
void FUN_00557876(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00557880
// Address: 00557880
// XREFS: __control87
void FUN_00557880(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0055790b
// Address: 0055790b
// XREFS: None
uint FUN_0055790b(byte param_1)
{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_00557910
// Address: 00557910
// XREFS: __clearfp, __statusfp
uint FUN_00557910(byte param_1)
{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_00557947
// Address: 00557947
// XREFS: None
undefined4 FUN_00557947(int param_1,int param_2)
{
  byte bVar1;
  int *piVar2;
  int iVar3;
  
  bVar1 = (byte)(param_2 >> 0x1f);
  iVar3 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  if ((*(uint *)(param_1 + iVar3 * 4) &
      ~(-1 << (0x1f - ((((byte)param_2 ^ bVar1) - bVar1 & 0x1f ^ bVar1) - bVar1) & 0x1f))) != 0) {
    return 0;
  }
  iVar3 = iVar3 + 1;
  if (iVar3 < 3) {
    piVar2 = (int *)(param_1 + iVar3 * 4);
    do {
      if (*piVar2 != 0) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < 3);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: __ZeroTail
// Address: 00557950
// XREFS: __RoundMan
undefined4 __ZeroTail(int param_1,int param_2)
{
  byte bVar1;
  int *piVar2;
  int iVar3;
  
  bVar1 = (byte)(param_2 >> 0x1f);
  iVar3 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  if ((*(uint *)(param_1 + iVar3 * 4) &
      ~(-1 << (0x1f - ((((byte)param_2 ^ bVar1) - bVar1 & 0x1f ^ bVar1) - bVar1) & 0x1f))) != 0) {
    return 0;
  }
  iVar3 = iVar3 + 1;
  if (iVar3 < 3) {
    piVar2 = (int *)(param_1 + iVar3 * 4);
    do {
      if (*piVar2 != 0) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < 3);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_005579b6
// Address: 005579b6
// XREFS: None
void FUN_005579b6(int param_1,int param_2)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  bVar1 = (byte)(param_2 >> 0x1f);
  iVar3 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  iVar2 = ___addl(*(undefined4 *)(param_1 + iVar3 * 4),
                  1 << (0x1f - ((((byte)param_2 ^ bVar1) - bVar1 & 0x1f ^ bVar1) - bVar1) & 0x1f),
                  param_1 + iVar3 * 4);
  iVar3 = iVar3 + -1;
  if (-1 < iVar3) {
    puVar4 = (undefined4 *)(param_1 + iVar3 * 4);
    do {
      if (iVar2 == 0) {
        return;
      }
      iVar2 = ___addl(*puVar4,1,puVar4);
      iVar3 = iVar3 + -1;
      puVar4 = puVar4 + -1;
    } while (-1 < iVar3);
  }
  return;
}

// --------------------------------------------------

// Function: __IncMan
// Address: 005579c0
// XREFS: __RoundMan
void __IncMan(int param_1,int param_2)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  bVar1 = (byte)(param_2 >> 0x1f);
  iVar3 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  iVar2 = ___addl(*(undefined4 *)(param_1 + iVar3 * 4),
                  1 << (0x1f - ((((byte)param_2 ^ bVar1) - bVar1 & 0x1f ^ bVar1) - bVar1) & 0x1f),
                  param_1 + iVar3 * 4);
  iVar3 = iVar3 + -1;
  if (-1 < iVar3) {
    puVar4 = (undefined4 *)(param_1 + iVar3 * 4);
    do {
      if (iVar2 == 0) {
        return;
      }
      iVar2 = ___addl(*puVar4,1,puVar4);
      iVar3 = iVar3 + -1;
      puVar4 = puVar4 + -1;
    } while (-1 < iVar3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00557a29
// Address: 00557a29
// XREFS: None
undefined4 FUN_00557a29(int param_1,int param_2)
{
  int iVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  bVar2 = (byte)(param_2 >> 0x1f);
  bVar2 = 0x1f - ((((byte)param_2 ^ bVar2) - bVar2 & 0x1f ^ bVar2) - bVar2);
  iVar3 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  if (((*(uint *)(param_1 + iVar3 * 4) & 1 << (bVar2 & 0x1f)) != 0) &&
     (iVar1 = __ZeroTail(param_1,param_2 + 1), iVar1 == 0)) {
    uStack_4 = __IncMan(param_1,param_2 + -1);
  }
  *(uint *)(param_1 + iVar3 * 4) = *(uint *)(param_1 + iVar3 * 4) & -1 << (bVar2 & 0x1f);
  iVar3 = iVar3 + 1;
  if (iVar3 < 3) {
    puVar4 = (undefined4 *)(param_1 + iVar3 * 4);
    for (iVar1 = 3 - iVar3; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  return uStack_4;
}

// --------------------------------------------------

// Function: __RoundMan
// Address: 00557a30
// XREFS: __ld12cvt, __ld12told
undefined4 __RoundMan(int param_1,int param_2)
{
  int iVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_4;
  
  local_4 = 0;
  bVar2 = (byte)(param_2 >> 0x1f);
  bVar2 = 0x1f - ((((byte)param_2 ^ bVar2) - bVar2 & 0x1f ^ bVar2) - bVar2);
  iVar3 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  if (((*(uint *)(param_1 + iVar3 * 4) & 1 << (bVar2 & 0x1f)) != 0) &&
     (iVar1 = __ZeroTail(param_1,param_2 + 1), iVar1 == 0)) {
    local_4 = __IncMan(param_1,param_2 + -1);
  }
  *(uint *)(param_1 + iVar3 * 4) = *(uint *)(param_1 + iVar3 * 4) & -1 << (bVar2 & 0x1f);
  iVar3 = iVar3 + 1;
  if (iVar3 < 3) {
    puVar4 = (undefined4 *)(param_1 + iVar3 * 4);
    for (iVar1 = 3 - iVar3; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  return local_4;
}

// --------------------------------------------------

// Function: FUN_00557acd
// Address: 00557acd
// XREFS: None
void FUN_00557acd(int param_1,undefined4 *param_2)
{
  int iVar1;
  
  param_1 = param_1 - (int)param_2;
  iVar1 = 3;
  do {
    *(undefined4 *)((int)param_2 + param_1) = *param_2;
    param_2 = param_2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// --------------------------------------------------

// Function: __CopyMan
// Address: 00557ad0
// XREFS: __ld12cvt
void __CopyMan(int param_1,undefined4 *param_2)
{
  int iVar1;
  
  param_1 = param_1 - (int)param_2;
  iVar1 = 3;
  do {
    *(undefined4 *)((int)param_2 + param_1) = *param_2;
    param_2 = param_2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_00557aed
// Address: 00557aed
// XREFS: None
void FUN_00557aed(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

// --------------------------------------------------

// Function: __FillZeroMan
// Address: 00557af0
// XREFS: __ld12cvt
void __FillZeroMan(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00557aff
// Address: 00557aff
// XREFS: None
undefined4 FUN_00557aff(int *param_1)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*param_1 != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
  } while (iVar1 < 3);
  return 1;
}

// --------------------------------------------------

// Function: __IsZeroMan
// Address: 00557b00
// XREFS: __ld12cvt
undefined4 __IsZeroMan(int *param_1)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*param_1 != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
  } while (iVar1 < 3);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00557b1d
// Address: 00557b1d
// XREFS: None
void FUN_00557b1d(uint *param_1,int param_2)
{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  
  iVar1 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  bVar2 = (byte)(param_2 >> 0x1f);
  uVar5 = 0;
  bVar2 = (((byte)param_2 ^ bVar2) - bVar2 & 0x1f ^ bVar2) - bVar2;
  param_2 = 3;
  puVar6 = param_1;
  do {
    uVar4 = *puVar6 >> (bVar2 & 0x1f) | uVar5;
    uVar5 = (~(-1 << (bVar2 & 0x1f)) & *puVar6) << (0x20 - bVar2 & 0x1f);
    *puVar6 = uVar4;
    param_2 = param_2 + -1;
    puVar6 = puVar6 + 1;
  } while (param_2 != 0);
  iVar7 = 2;
  iVar3 = 8;
  do {
    if (iVar7 < iVar1) {
      *(undefined4 *)((int)param_1 + iVar3) = 0;
    }
    else {
      *(undefined4 *)((int)param_1 + iVar3) = *(undefined4 *)((int)param_1 + iVar3 + iVar1 * -4);
    }
    iVar7 = iVar7 + -1;
    iVar3 = iVar3 + -4;
  } while (-1 < iVar3);
  return;
}

// --------------------------------------------------

// Function: __ShrMan
// Address: 00557b20
// XREFS: __ld12cvt
void __ShrMan(uint *param_1,int param_2)
{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  
  iVar1 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  bVar2 = (byte)(param_2 >> 0x1f);
  uVar5 = 0;
  bVar2 = (((byte)param_2 ^ bVar2) - bVar2 & 0x1f ^ bVar2) - bVar2;
  param_2 = 3;
  puVar6 = param_1;
  do {
    uVar4 = *puVar6 >> (bVar2 & 0x1f) | uVar5;
    uVar5 = (~(-1 << (bVar2 & 0x1f)) & *puVar6) << (0x20 - bVar2 & 0x1f);
    *puVar6 = uVar4;
    param_2 = param_2 + -1;
    puVar6 = puVar6 + 1;
  } while (param_2 != 0);
  iVar7 = 2;
  iVar3 = 8;
  do {
    if (iVar7 < iVar1) {
      *(undefined4 *)((int)param_1 + iVar3) = 0;
    }
    else {
      *(undefined4 *)((int)param_1 + iVar3) = *(undefined4 *)((int)param_1 + iVar3 + iVar1 * -4);
    }
    iVar7 = iVar7 + -1;
    iVar3 = iVar3 + -4;
  } while (-1 < iVar3);
  return;
}

// --------------------------------------------------

// Function: FUN_00557bd1
// Address: 00557bd1
// XREFS: None
undefined4 FUN_00557bd1(ushort *param_1,uint *param_2,int *param_3)
{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uStack_18;
  uint uStack_14;
  int iStack_10;
  undefined1 auStack_c [12];
  
  uVar1 = param_1[5];
  uStack_14 = *(uint *)(param_1 + 1);
  uStack_18 = *(uint *)(param_1 + 3);
  uVar4 = uVar1 & 0x7fff;
  iVar5 = uVar4 - 0x3fff;
  iStack_10 = (uint)*param_1 << 0x10;
  if (iVar5 == -0x3fff) {
    iVar5 = 0;
    iVar2 = __IsZeroMan(&uStack_18);
    if (iVar2 == 0) {
      __FillZeroMan(&uStack_18);
      uVar3 = 2;
      goto LAB_00557d61;
    }
  }
  else {
    __CopyMan(auStack_c,&uStack_18);
    iVar2 = __RoundMan(&uStack_18,param_3[2]);
    if (iVar2 != 0) {
      iVar5 = uVar4 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar5 < iVar2 - param_3[2]) {
      __FillZeroMan(&uStack_18);
      iVar5 = 0;
      uVar3 = 2;
      goto LAB_00557d61;
    }
    if (iVar5 <= iVar2) {
      __CopyMan(&uStack_18,auStack_c);
      __ShrMan(&uStack_18,iVar2 - iVar5);
      __RoundMan(&uStack_18,param_3[2]);
      __ShrMan(&uStack_18,param_3[3] + 1);
      iVar5 = 0;
      uVar3 = 2;
      goto LAB_00557d61;
    }
    if (*param_3 <= iVar5) {
      __FillZeroMan(&uStack_18);
      uStack_18 = uStack_18 | 0x80000000;
      __ShrMan(&uStack_18,param_3[3]);
      iVar5 = param_3[5] + *param_3;
      uVar3 = 1;
      goto LAB_00557d61;
    }
    iVar5 = param_3[5] + iVar5;
    uStack_18 = uStack_18 & 0x7fffffff;
    __ShrMan(&uStack_18,param_3[3]);
  }
  uVar3 = 0;
LAB_00557d61:
  uStack_18 = iVar5 << (0x1fU - (char)param_3[3] & 0x1f) |
              -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 | uStack_18;
  if (param_3[4] == 0x40) {
    param_2[1] = uStack_18;
    *param_2 = uStack_14;
    return uVar3;
  }
  if (param_3[4] == 0x20) {
    *param_2 = uStack_18;
  }
  return uVar3;
}

// --------------------------------------------------

// Function: __ld12cvt
// Address: 00557be0
// XREFS: __ld12tod, __ld12tof
undefined4 __ld12cvt(ushort *param_1,uint *param_2,int *param_3)
{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint local_18;
  uint local_14;
  int local_10;
  undefined1 local_c [12];
  
  uVar1 = param_1[5];
  local_14 = *(uint *)(param_1 + 1);
  local_18 = *(uint *)(param_1 + 3);
  uVar4 = uVar1 & 0x7fff;
  iVar5 = uVar4 - 0x3fff;
  local_10 = (uint)*param_1 << 0x10;
  if (iVar5 == -0x3fff) {
    iVar5 = 0;
    iVar2 = __IsZeroMan(&local_18);
    if (iVar2 == 0) {
      __FillZeroMan(&local_18);
      uVar3 = 2;
      goto LAB_00557d61;
    }
  }
  else {
    __CopyMan(local_c,&local_18);
    iVar2 = __RoundMan(&local_18,param_3[2]);
    if (iVar2 != 0) {
      iVar5 = uVar4 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar5 < iVar2 - param_3[2]) {
      __FillZeroMan(&local_18);
      iVar5 = 0;
      uVar3 = 2;
      goto LAB_00557d61;
    }
    if (iVar5 <= iVar2) {
      __CopyMan(&local_18,local_c);
      __ShrMan(&local_18,iVar2 - iVar5);
      __RoundMan(&local_18,param_3[2]);
      __ShrMan(&local_18,param_3[3] + 1);
      iVar5 = 0;
      uVar3 = 2;
      goto LAB_00557d61;
    }
    if (*param_3 <= iVar5) {
      __FillZeroMan(&local_18);
      local_18 = local_18 | 0x80000000;
      __ShrMan(&local_18,param_3[3]);
      iVar5 = param_3[5] + *param_3;
      uVar3 = 1;
      goto LAB_00557d61;
    }
    iVar5 = param_3[5] + iVar5;
    local_18 = local_18 & 0x7fffffff;
    __ShrMan(&local_18,param_3[3]);
  }
  uVar3 = 0;
LAB_00557d61:
  local_18 = iVar5 << (0x1fU - (char)param_3[3] & 0x1f) |
             -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 | local_18;
  if (param_3[4] == 0x40) {
    param_2[1] = local_18;
    *param_2 = local_14;
    return uVar3;
  }
  if (param_3[4] == 0x20) {
    *param_2 = local_18;
  }
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_00557daf
// Address: 00557daf
// XREFS: None
void FUN_00557daf(undefined4 param_1,undefined4 param_2)
{
  __ld12cvt(param_1,param_2,&DAT_00592690);
  return;
}

// --------------------------------------------------

// Function: __ld12tod
// Address: 00557db0
// XREFS: __atodbl, __fltin
void __ld12tod(undefined4 param_1,undefined4 param_2)
{
  __ld12cvt(param_1,param_2,&DAT_00592690);
  return;
}

// --------------------------------------------------

// Function: FUN_00557dc8
// Address: 00557dc8
// XREFS: None
void FUN_00557dc8(undefined4 param_1,undefined4 param_2)
{
  __ld12cvt(param_1,param_2,&DAT_005926a8);
  return;
}

// --------------------------------------------------

// Function: __ld12tof
// Address: 00557dd0
// XREFS: __atoflt
void __ld12tof(undefined4 param_1,undefined4 param_2)
{
  __ld12cvt(param_1,param_2,&DAT_005926a8);
  return;
}

// --------------------------------------------------

// Function: FUN_00557de8
// Address: 00557de8
// XREFS: None
bool FUN_00557de8(ushort *param_1,undefined4 *param_2)
{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
  uVar1 = param_1[5];
  uStack_8 = *(undefined4 *)(param_1 + 1);
  uStack_c = *(undefined4 *)(param_1 + 3);
  iStack_4 = (uint)*param_1 << 0x10;
  uVar3 = uVar1 & 0x7fff;
  iVar2 = __RoundMan(&uStack_c,0x40);
  if (iVar2 != 0) {
    uStack_c = 0x80000000;
    uVar3 = uVar3 + 1;
  }
  *(ushort *)(param_2 + 2) = uVar1 & 0x8000 | uVar3;
  param_2[1] = uStack_c;
  *param_2 = uStack_8;
  return uVar3 == 0x7fff;
}

// --------------------------------------------------

// Function: __ld12told
// Address: 00557df0
// XREFS: FUN_00557ea8
bool __ld12told(ushort *param_1,undefined4 *param_2)
{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  uVar1 = param_1[5];
  local_8 = *(undefined4 *)(param_1 + 1);
  local_c = *(undefined4 *)(param_1 + 3);
  local_4 = (uint)*param_1 << 0x10;
  uVar3 = uVar1 & 0x7fff;
  iVar2 = __RoundMan(&local_c,0x40);
  if (iVar2 != 0) {
    local_c = 0x80000000;
    uVar3 = uVar3 + 1;
  }
  *(ushort *)(param_2 + 2) = uVar1 & 0x8000 | uVar3;
  param_2[1] = local_c;
  *param_2 = local_8;
  return uVar3 == 0x7fff;
}

// --------------------------------------------------

// Function: __atodbl
// Address: 00557e70
// XREFS: FUN_0055074c
void __atodbl(undefined4 param_1,undefined4 param_2)
{
  undefined1 local_c [12];
  
  ___strgtold12(local_c,&param_2,param_2,0,0,0,0);
  __ld12tod(local_c,param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00557ea8
// Address: 00557ea8
// XREFS: None
void FUN_00557ea8(undefined4 param_1,undefined4 param_2)
{
  undefined1 local_c [12];
  
  ___strgtold12(local_c,&param_2,param_2,1,0,0,0);
  __ld12told(local_c,param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00557ee8
// Address: 00557ee8
// XREFS: None
void FUN_00557ee8(undefined4 param_1,undefined4 param_2)
{
  undefined1 auStack_c [12];
  
  ___strgtold12(auStack_c,&param_2,param_2,0,0,0,0);
  __ld12tof(auStack_c,param_1);
  return;
}

// --------------------------------------------------

// Function: __atoflt
// Address: 00557ef0
// XREFS: FUN_0055074c
void __atoflt(undefined4 param_1,undefined4 param_2)
{
  undefined1 local_c [12];
  
  ___strgtold12(local_c,&param_2,param_2,0,0,0,0);
  __ld12tof(local_c,param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00557f28
// Address: 00557f28
// XREFS: None
void FUN_00557f28(char *param_1,int param_2,int param_3)
{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  
  pcVar5 = *(char **)(param_3 + 0xc);
  pcVar7 = param_1 + 1;
  *param_1 = '0';
  pcVar1 = pcVar7;
  iVar6 = param_2;
  if (0 < param_2) {
    do {
      cVar2 = *pcVar5;
      if (cVar2 == '\0') {
        cVar2 = '0';
      }
      else {
        pcVar5 = pcVar5 + 1;
      }
      *pcVar1 = cVar2;
      pcVar1 = pcVar1 + 1;
      iVar6 = iVar6 + -1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  *pcVar1 = '\0';
  if ((-1 < iVar6) && ('4' < *pcVar5)) {
    cVar2 = pcVar1[-1];
    while (pcVar5 = pcVar1 + -1, cVar2 == '9') {
      *pcVar5 = '0';
      cVar2 = pcVar1[-2];
      pcVar1 = pcVar5;
    }
    *pcVar5 = *pcVar5 + '\x01';
  }
  if (*param_1 == '1') {
    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
    return;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar5 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar5;
  } while (cVar2 != '\0');
  uVar3 = ~uVar3;
  pcVar7 = pcVar5 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)param_1 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    param_1 = param_1 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: __fptostr
// Address: 00557f30
// XREFS: __cftoe, __cftof, __cftog
void __fptostr(char *param_1,int param_2,int param_3)
{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  
  pcVar5 = *(char **)(param_3 + 0xc);
  pcVar7 = param_1 + 1;
  *param_1 = '0';
  pcVar1 = pcVar7;
  iVar6 = param_2;
  if (0 < param_2) {
    do {
      cVar2 = *pcVar5;
      if (cVar2 == '\0') {
        cVar2 = '0';
      }
      else {
        pcVar5 = pcVar5 + 1;
      }
      *pcVar1 = cVar2;
      pcVar1 = pcVar1 + 1;
      iVar6 = iVar6 + -1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  *pcVar1 = '\0';
  if ((-1 < iVar6) && ('4' < *pcVar5)) {
    cVar2 = pcVar1[-1];
    while (pcVar5 = pcVar1 + -1, cVar2 == '9') {
      *pcVar5 = '0';
      cVar2 = pcVar1[-2];
      pcVar1 = pcVar5;
    }
    *pcVar5 = *pcVar5 + '\x01';
  }
  if (*param_1 == '1') {
    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
    return;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar5 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar5;
  } while (cVar2 != '\0');
  uVar3 = ~uVar3;
  pcVar7 = pcVar5 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)param_1 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    param_1 = param_1 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00557fc1
// Address: 00557fc1
// XREFS: None
undefined4 FUN_00557fc1(void)
{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined2 uStack_4;
  
  ___dtold(&uStack_c,&stack0x00000004);
  UNK_008883f3._37_4_ = __I10_OUTPUT(uStack_c,uStack_8,uStack_4,0x11,0,&DAT_008883f0);
  UNK_008883f3._29_4_ = (int)DAT_008883f2;
  UNK_008883f3._33_4_ = (int)DAT_008883f0;
  UNK_008883f3._41_4_ = 0x8883f4;
  return 0x888410;
}

// --------------------------------------------------

// Function: __fltout
// Address: 00557fd0
// XREFS: __cftoe, __cftof, __cftog
undefined4 __fltout(void)
{
  undefined4 local_c;
  undefined4 local_8;
  undefined2 local_4;
  
  ___dtold(&local_c,&stack0x00000004);
  UNK_008883f3._37_4_ = __I10_OUTPUT(local_c,local_8,local_4,0x11,0,&DAT_008883f0);
  UNK_008883f3._29_4_ = (int)DAT_008883f2;
  UNK_008883f3._33_4_ = (int)DAT_008883f0;
  UNK_008883f3._41_4_ = 0x8883f4;
  return 0x888410;
}

// --------------------------------------------------

// Function: FUN_00558043
// Address: 00558043
// XREFS: None
void FUN_00558043(uint *param_1,uint *param_2)
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  
  uVar4 = 0x80000000;
  uVar1 = *(ushort *)((int)param_2 + 6);
  uVar2 = *param_2;
  uVar3 = (uVar1 & 0x7ff0) >> 4;
  if (uVar3 == 0) {
    uVar4 = 0;
    if (((param_2[1] & 0xfffff) == 0) && (uVar2 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      *(undefined2 *)(param_1 + 2) = 0;
      return;
    }
    iVar6 = 0x3c01;
  }
  else if (uVar3 == 0x7ff) {
    iVar6 = 0x7fff;
  }
  else {
    iVar6 = uVar3 + 0x3c00;
  }
  uVar5 = (ushort)iVar6;
  uVar3 = uVar2 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | uVar4;
  param_1[1] = uVar3;
  *param_1 = uVar2 << 0xb;
  for (; uVar4 == 0; uVar4 = uVar4 & 0x80000000) {
    uVar4 = uVar3 * 2;
    uVar3 = *param_1 >> 0x1f | uVar4;
    iVar6 = iVar6 + 0xffff;
    uVar5 = (ushort)iVar6;
    param_1[1] = uVar3;
    *param_1 = *param_1 * 2;
  }
  *(ushort *)(param_1 + 2) = uVar5 | uVar1 & 0x8000;
  return;
}

// --------------------------------------------------

// Function: ___dtold
// Address: 00558050
// XREFS: __fltout
void ___dtold(uint *param_1,uint *param_2)
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  
  uVar4 = 0x80000000;
  uVar1 = *(ushort *)((int)param_2 + 6);
  uVar2 = *param_2;
  uVar3 = (uVar1 & 0x7ff0) >> 4;
  if (uVar3 == 0) {
    uVar4 = 0;
    if (((param_2[1] & 0xfffff) == 0) && (uVar2 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      *(undefined2 *)(param_1 + 2) = 0;
      return;
    }
    iVar6 = 0x3c01;
  }
  else if (uVar3 == 0x7ff) {
    iVar6 = 0x7fff;
  }
  else {
    iVar6 = uVar3 + 0x3c00;
  }
  uVar5 = (ushort)iVar6;
  uVar3 = uVar2 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | uVar4;
  param_1[1] = uVar3;
  *param_1 = uVar2 << 0xb;
  for (; uVar4 == 0; uVar4 = uVar4 & 0x80000000) {
    uVar4 = uVar3 * 2;
    uVar3 = *param_1 >> 0x1f | uVar4;
    iVar6 = iVar6 + 0xffff;
    uVar5 = (ushort)iVar6;
    param_1[1] = uVar3;
    *param_1 = *param_1 * 2;
  }
  *(ushort *)(param_1 + 2) = uVar5 | uVar1 & 0x8000;
  return;
}

// --------------------------------------------------

// Function: FUN_0055810e
// Address: 0055810e
// XREFS: None
void FUN_0055810e(void)
{
  __amsg_exit(2);
  return;
}

// --------------------------------------------------

// Function: __fptrap
// Address: 00558110
// XREFS: PTR___fptrap_0058fbcc, PTR___fptrap_0058fbd0, PTR___fptrap_0058fbd4, PTR___fptrap_0058fbd8, PTR___fptrap_0058fbdc, __cfltcvt_tab, __input, __output
void __fptrap(void)
{
  __amsg_exit(2);
  return;
}

// --------------------------------------------------

// Function: FUN_0055811b
// Address: 0055811b
// XREFS: None
byte FUN_0055811b(uint param_1)
{
  if (__nhandle <= param_1) {
    return 0;
  }
  return *(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 0x40;
}

// --------------------------------------------------

// Function: __isatty
// Address: 00558120
// XREFS: __flsbuf, __stbuf
byte __isatty(uint param_1)
{
  if (__nhandle <= param_1) {
    return 0;
  }
  return *(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 0x40;
}

// --------------------------------------------------

// Function: FUN_00558148
// Address: 00558148
// XREFS: None
undefined1 * FUN_00558148(undefined1 *param_1,ushort param_2)
{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = param_1;
  if (param_1 == (undefined1 *)0x0) {
    return param_1;
  }
  if (DAT_008882c0 == 0) {
    if (param_2 < 0x100) {
      *param_1 = (char)param_2;
      return (undefined1 *)0x1;
    }
  }
  else {
    iVar2 = 0x220;
    param_1 = (undefined1 *)0x0;
    puVar1 = (undefined1 *)
             WideCharToMultiByte(___lc_codepage,0x220,&param_2,1,puVar1,___mb_cur_max,0,&param_1);
    if ((puVar1 != (undefined1 *)0x0) && (iVar2 == 0)) {
      return puVar1;
    }
  }
  _errno = 0x2a;
  return (undefined1 *)0xffffffff;
}

// --------------------------------------------------

// Function: wctomb
// Address: 00558150
// XREFS: __output
/* wctomb */

undefined1 * __cdecl wctomb(undefined1 *param_1,ushort param_2)
{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = param_1;
  if (param_1 == (undefined1 *)0x0) {
    return param_1;
  }
  if (DAT_008882c0 == 0) {
    if (param_2 < 0x100) {
      *param_1 = (char)param_2;
      return (undefined1 *)0x1;
    }
  }
  else {
    iVar2 = 0x220;
    param_1 = (undefined1 *)0x0;
    puVar1 = (undefined1 *)
             WideCharToMultiByte(___lc_codepage,0x220,&param_2,1,puVar1,___mb_cur_max,0,&param_1);
    if ((puVar1 != (undefined1 *)0x0) && (iVar2 == 0)) {
      return puVar1;
    }
  }
  _errno = 0x2a;
  return (undefined1 *)0xffffffff;
}

// --------------------------------------------------

// Function: FUN_005581c1
// Address: 005581c1
// XREFS: None
undefined8 FUN_005581c1(uint param_1,uint param_2,uint param_3,uint param_4)
{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_1;
  uVar8 = param_4;
  uVar6 = param_2;
  uVar9 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar8 >> 1;
      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar8 = uVar5;
      uVar6 = uVar7;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}

// --------------------------------------------------

// Function: __aulldiv
// Address: 005581d0
// XREFS: FUN_0055be70, __output
undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)
{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_1;
  uVar8 = param_4;
  uVar6 = param_2;
  uVar9 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar8 >> 1;
      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar8 = uVar5;
      uVar6 = uVar7;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}

// --------------------------------------------------

// Function: __aullrem
// Address: 00558240
// XREFS: FUN_0055be70, __output
undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)
{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar3 = param_1;
  uVar4 = param_4;
  uVar9 = param_2;
  uVar10 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar4 >> 1;
      uVar10 = uVar10 >> 1 | (uint)((uVar4 & 1) != 0) << 0x1f;
      uVar8 = uVar9 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar4 = uVar5;
      uVar9 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar3) / (ulonglong)uVar10;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
{
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}

// --------------------------------------------------

// Function: mbtowc
// Address: 005582c0
// XREFS: __input
/* mbtowc */

uint __cdecl mbtowc(ushort *param_1,byte *param_2,uint param_3)
{
  byte bVar1;
  int iVar2;
  
  if ((param_2 != (byte *)0x0) && (param_3 != 0)) {
    bVar1 = *param_2;
    if (bVar1 != 0) {
      if (DAT_008882c0 == 0) {
        if (param_1 == (ushort *)0x0) {
          return 1;
        }
        *param_1 = (ushort)bVar1;
        return 1;
      }
      if ((__pctype[(uint)bVar1 * 2 + 1] & 0x80) == 0) {
        iVar2 = MultiByteToWideChar(___lc_codepage,9,param_2,1,param_1,param_1 != (ushort *)0x0);
        if (iVar2 != 0) {
          return 1;
        }
        _errno = 0x2a;
        return 0xffffffff;
      }
      if (((1 < (int)___mb_cur_max) && ((int)___mb_cur_max <= (int)param_3)) &&
         (iVar2 = MultiByteToWideChar(___lc_codepage,9,param_2,___mb_cur_max,param_1,
                                      param_1 != (ushort *)0x0), iVar2 != 0)) {
        return ___mb_cur_max;
      }
      if (param_3 < ___mb_cur_max) {
        _errno = 0x2a;
        return 0xffffffff;
      }
      if (param_2[1] != 0) {
        return ___mb_cur_max;
      }
      _errno = 0x2a;
      return 0xffffffff;
    }
    if (param_1 != (ushort *)0x0) {
      *param_1 = 0;
      return 0;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005583bc
// Address: 005583bc
// XREFS: None
longlong __fastcall FUN_005583bc(byte param_1,int param_2)
{
  uint in_EAX;
  
  if (0x3f < param_1) {
    return 0;
  }
  if (param_1 < 0x20) {
    return CONCAT44(param_2 << (param_1 & 0x1f) | in_EAX >> 0x20 - (param_1 & 0x1f),
                    in_EAX << (param_1 & 0x1f));
  }
  return (ulonglong)(in_EAX << (param_1 & 0x1f)) << 0x20;
}

// --------------------------------------------------

// Function: __allshl
// Address: 005583c0
// XREFS: __input
longlong __fastcall __allshl(byte param_1,int param_2)
{
  uint in_EAX;
  
  if (0x3f < param_1) {
    return 0;
  }
  if (param_1 < 0x20) {
    return CONCAT44(param_2 << (param_1 & 0x1f) | in_EAX >> 0x20 - (param_1 & 0x1f),
                    in_EAX << (param_1 & 0x1f));
  }
  return (ulonglong)(in_EAX << (param_1 & 0x1f)) << 0x20;
}

// --------------------------------------------------

// Function: ungetc
// Address: 005583e0
// XREFS: FUN_00553070
/* ungetc */

uint __cdecl ungetc(uint param_1,int *param_2)
{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
  if ((param_1 != 0xffffffff) &&
     ((uVar1 = param_2[3], (uVar1 & 1) != 0 || (((uVar1 & 0x80) != 0 && ((uVar1 & 2) == 0)))))) {
    if (param_2[2] == 0) {
      __getbuf(param_2);
    }
    if (*param_2 == param_2[2]) {
      if (param_2[1] != 0) {
        return 0xffffffff;
      }
      *param_2 = *param_2 + 1;
    }
    if ((*(byte *)(param_2 + 3) & 0x40) == 0) {
      iVar2 = *param_2;
      *param_2 = iVar2 + -1;
      *(char *)(iVar2 + -1) = (char)param_1;
    }
    else {
      iVar2 = *param_2;
      pcVar3 = (char *)(iVar2 + -1);
      *param_2 = (int)pcVar3;
      if (*pcVar3 != (char)param_1) {
        *param_2 = iVar2;
        return 0xffffffff;
      }
    }
    param_2[1] = param_2[1] + 1;
    param_2[3] = param_2[3] & 0xffffffefU | 1;
    return param_1 & 0xff;
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00558463
// Address: 00558463
// XREFS: None
void FUN_00558463(int *param_1)
{
  int iVar1;
  
  __cflush = __cflush + 1;
  iVar1 = malloc(0x1000);
  param_1[2] = iVar1;
  if (iVar1 != 0) {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
    *param_1 = param_1[2];
    param_1[1] = 0;
    return;
  }
  param_1[6] = 2;
  param_1[3] = param_1[3] | 4;
  param_1[2] = (int)(param_1 + 5);
  *param_1 = (int)(param_1 + 5);
  param_1[1] = 0;
  return;
}

// --------------------------------------------------

// Function: __getbuf
// Address: 00558470
// XREFS: __filbuf, __flsbuf, ungetc
void __getbuf(int *param_1)
{
  int iVar1;
  
  __cflush = __cflush + 1;
  iVar1 = malloc(0x1000);
  param_1[2] = iVar1;
  if (iVar1 != 0) {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
    *param_1 = param_1[2];
    param_1[1] = 0;
    return;
  }
  param_1[6] = 2;
  param_1[3] = param_1[3] | 4;
  param_1[2] = (int)(param_1 + 5);
  *param_1 = (int)(param_1 + 5);
  param_1[1] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_005584cd
// Address: 005584cd
// XREFS: None
ushort * FUN_005584cd(int param_1,ushort *param_2,ushort *param_3)
{
  char cVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iStack_24;
  ushort *puStack_20;
  ushort *puStack_1c;
  ushort *puStack_18;
  ushort auStack_4 [2];
  
  puVar2 = (ushort *)0x0;
  auStack_4[0] = 0;
  auStack_4[1] = 0;
  if ((param_1 != 0) && (param_3 == (ushort *)0x0)) {
    return puVar2;
  }
  if (param_1 == 0) {
    if (DAT_008882c0 == 0) {
      puStack_18 = param_2;
      puStack_1c = (ushort *)0x558667;
      uVar3 = wcslen();
      return (ushort *)uVar3;
    }
    puStack_18 = auStack_4;
    puStack_1c = (ushort *)0x0;
    puStack_20 = (ushort *)0x0;
    iStack_24 = 0;
    iVar4 = WideCharToMultiByte(___lc_codepage,0x220,param_2,0xffffffff);
    if ((iVar4 != 0) && (iStack_24 == 0)) {
      return (ushort *)(iVar4 - 1);
    }
  }
  else if (DAT_008882c0 == 0) {
    if (param_3 == (ushort *)0x0) {
      return (ushort *)0;
    }
    while (*param_2 < 0x100) {
      *(char *)((int)puVar2 + param_1) = (char)*param_2;
      if (*param_2 == 0) {
        return puVar2;
      }
      puVar2 = (ushort *)((int)puVar2 + 1);
      param_2 = param_2 + 1;
      if (param_3 <= puVar2) {
        return puVar2;
      }
    }
  }
  else if (___mb_cur_max == 1) {
    if (param_3 != (ushort *)0x0) {
      puStack_18 = param_3;
      puStack_1c = param_2;
      puStack_20 = (ushort *)0x558552;
      param_3 = (ushort *)FUN_005586c0();
    }
    puStack_18 = auStack_4;
    puStack_1c = (ushort *)0x0;
    iStack_24 = param_1;
    puStack_20 = param_3;
    uVar3 = WideCharToMultiByte(___lc_codepage,0x220,param_2,param_3);
    if ((uVar3 != 0) && (iStack_24 == 0)) {
      if (*(char *)(uVar3 + param_1 + -1) == '\0') {
        return (ushort *)(uVar3 - 1);
      }
      return (ushort *)uVar3;
    }
  }
  else {
    puStack_18 = auStack_4;
    puStack_1c = (ushort *)0x0;
    puStack_20 = param_3;
    iStack_24 = param_1;
    iVar4 = WideCharToMultiByte(___lc_codepage,0x220,param_2,0xffffffff);
    if (iVar4 == 0) {
      if ((iStack_24 == 0) && (iVar4 = GetLastError(), iVar4 == 0x7a)) {
        puVar2 = (ushort *)0x0;
        if (param_3 != (ushort *)0x0) {
          do {
            iVar4 = WideCharToMultiByte(___lc_codepage,0,param_2,1,&puStack_18,___mb_cur_max,0,
                                        &iStack_24);
            if (iVar4 == 0) {
              _errno = 0x2a;
              return (ushort *)0xffffffff;
            }
            if (iStack_24 != 0) {
              _errno = 0x2a;
              return (ushort *)0xffffffff;
            }
            if (param_3 < (ushort *)(iVar4 + (int)puVar2)) {
              return puVar2;
            }
            iVar5 = 0;
            if (0 < iVar4) {
              do {
                cVar1 = *(char *)((int)&puStack_18 + iVar5);
                *(char *)((int)puVar2 + param_1) = cVar1;
                if (cVar1 == '\0') {
                  return puVar2;
                }
                iVar5 = iVar5 + 1;
                puVar2 = (ushort *)((int)puVar2 + 1);
              } while (iVar5 < iVar4);
            }
            param_2 = param_2 + 1;
          } while (puVar2 < param_3);
        }
        return puVar2;
      }
    }
    else if (iStack_24 == 0) {
      return (ushort *)(iVar4 - 1);
    }
  }
  _errno = 0x2a;
  return (ushort *)0xffffffff;
}

// --------------------------------------------------

// Function: wcstombs
// Address: 005584d0
// XREFS: __tzset
/* wcstombs */

ushort * __cdecl wcstombs(int param_1,ushort *param_2,ushort *param_3)
{
  char cVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iStack_24;
  ushort *puStack_20;
  ushort *puStack_1c;
  ushort *puStack_18;
  ushort local_4 [2];
  
  puVar2 = (ushort *)0x0;
  local_4[0] = 0;
  local_4[1] = 0;
  if ((param_1 != 0) && (param_3 == (ushort *)0x0)) {
    return puVar2;
  }
  if (param_1 == 0) {
    if (DAT_008882c0 == 0) {
      puStack_18 = param_2;
      puStack_1c = (ushort *)0x558667;
      uVar3 = wcslen();
      return (ushort *)uVar3;
    }
    puStack_18 = local_4;
    puStack_1c = (ushort *)0x0;
    puStack_20 = (ushort *)0x0;
    iStack_24 = 0;
    iVar4 = WideCharToMultiByte(___lc_codepage,0x220,param_2,0xffffffff);
    if ((iVar4 != 0) && (iStack_24 == 0)) {
      return (ushort *)(iVar4 - 1);
    }
  }
  else if (DAT_008882c0 == 0) {
    if (param_3 == (ushort *)0x0) {
      return (ushort *)0;
    }
    while (*param_2 < 0x100) {
      *(char *)((int)puVar2 + param_1) = (char)*param_2;
      if (*param_2 == 0) {
        return puVar2;
      }
      puVar2 = (ushort *)((int)puVar2 + 1);
      param_2 = param_2 + 1;
      if (param_3 <= puVar2) {
        return puVar2;
      }
    }
  }
  else if (___mb_cur_max == 1) {
    if (param_3 != (ushort *)0x0) {
      puStack_18 = param_3;
      puStack_1c = param_2;
      puStack_20 = (ushort *)0x558552;
      param_3 = (ushort *)FUN_005586c0();
    }
    puStack_18 = local_4;
    puStack_1c = (ushort *)0x0;
    iStack_24 = param_1;
    puStack_20 = param_3;
    uVar3 = WideCharToMultiByte(___lc_codepage,0x220,param_2,param_3);
    if ((uVar3 != 0) && (iStack_24 == 0)) {
      if (*(char *)(uVar3 + param_1 + -1) == '\0') {
        return (ushort *)(uVar3 - 1);
      }
      return (ushort *)uVar3;
    }
  }
  else {
    puStack_18 = local_4;
    puStack_1c = (ushort *)0x0;
    puStack_20 = param_3;
    iStack_24 = param_1;
    iVar4 = WideCharToMultiByte(___lc_codepage,0x220,param_2,0xffffffff);
    if (iVar4 == 0) {
      if ((iStack_24 == 0) && (iVar4 = GetLastError(), iVar4 == 0x7a)) {
        puVar2 = (ushort *)0x0;
        if (param_3 != (ushort *)0x0) {
          do {
            iVar4 = WideCharToMultiByte(___lc_codepage,0,param_2,1,&puStack_18,___mb_cur_max,0,
                                        &iStack_24);
            if (iVar4 == 0) {
              _errno = 0x2a;
              return (ushort *)0xffffffff;
            }
            if (iStack_24 != 0) {
              _errno = 0x2a;
              return (ushort *)0xffffffff;
            }
            if (param_3 < (ushort *)(iVar4 + (int)puVar2)) {
              return puVar2;
            }
            iVar5 = 0;
            if (0 < iVar4) {
              do {
                cVar1 = *(char *)((int)&puStack_18 + iVar5);
                *(char *)((int)puVar2 + param_1) = cVar1;
                if (cVar1 == '\0') {
                  return puVar2;
                }
                iVar5 = iVar5 + 1;
                puVar2 = (ushort *)((int)puVar2 + 1);
              } while (iVar5 < iVar4);
            }
            param_2 = param_2 + 1;
          } while (puVar2 < param_3);
        }
        return puVar2;
      }
    }
    else if (iStack_24 == 0) {
      return (ushort *)(iVar4 - 1);
    }
  }
  _errno = 0x2a;
  return (ushort *)0xffffffff;
}

// --------------------------------------------------

// Function: FUN_005586b9
// Address: 005586b9
// XREFS: None
int FUN_005586b9(short *param_1,int param_2)
{
  short *psVar1;
  int iVar2;
  
  psVar1 = param_1;
  iVar2 = param_2;
  if (param_2 != 0) {
    do {
      if (*psVar1 == 0) break;
      psVar1 = psVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if ((iVar2 != 0) && (*psVar1 == 0)) {
      return ((int)psVar1 - (int)param_1 >> 1) + 1;
    }
  }
  return param_2;
}

// --------------------------------------------------

// Function: FUN_005586c0
// Address: 005586c0
// XREFS: wcstombs
int FUN_005586c0(short *param_1,int param_2)
{
  short *psVar1;
  int iVar2;
  
  psVar1 = param_1;
  iVar2 = param_2;
  if (param_2 != 0) {
    do {
      if (*psVar1 == 0) break;
      psVar1 = psVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if ((iVar2 != 0) && (*psVar1 == 0)) {
      return ((int)psVar1 - (int)param_1 >> 1) + 1;
    }
  }
  return param_2;
}

// --------------------------------------------------

// Function: FUN_005586f2
// Address: 005586f2
// XREFS: None
int FUN_005586f2(char *param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int *piVar7;
  char *pcVar8;
  
  if (((__environ != (int *)0x0) ||
      (((__wenviron == 0 || (iVar2 = ___wtomb_environ(), iVar2 == 0)) && (__environ != (int *)0x0)))
      ) && (param_1 != (char *)0x0)) {
    uVar3 = 0xffffffff;
    pcVar6 = (char *)*__environ;
    pcVar8 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar3 - 1;
    piVar7 = __environ;
    if (pcVar6 != (char *)0x0) {
      do {
        uVar5 = 0xffffffff;
        pcVar8 = pcVar6;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        if (((uVar4 < ~uVar5 - 1) && (pcVar6[uVar4] == '=')) &&
           (iVar2 = __mbsnbicoll(pcVar6,param_1,uVar4), iVar2 == 0)) {
          return ~uVar3 + *piVar7;
        }
        pcVar6 = (char *)piVar7[1];
        piVar7 = piVar7 + 1;
        if (pcVar6 == (char *)0x0) {
          return 0;
        }
      } while( true );
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: getenv
// Address: 00558700
// XREFS: __tzset
/* getenv */

int __cdecl getenv(char *param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int *piVar7;
  char *pcVar8;
  
  if (((__environ != (int *)0x0) ||
      (((__wenviron == 0 || (iVar2 = ___wtomb_environ(), iVar2 == 0)) && (__environ != (int *)0x0)))
      ) && (param_1 != (char *)0x0)) {
    uVar3 = 0xffffffff;
    pcVar6 = (char *)*__environ;
    pcVar8 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar3 - 1;
    piVar7 = __environ;
    if (pcVar6 != (char *)0x0) {
      do {
        uVar5 = 0xffffffff;
        pcVar8 = pcVar6;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        if (((uVar4 < ~uVar5 - 1) && (pcVar6[uVar4] == '=')) &&
           (iVar2 = __mbsnbicoll(pcVar6,param_1,uVar4), iVar2 == 0)) {
          return ~uVar3 + *piVar7;
        }
        pcVar6 = (char *)piVar7[1];
        piVar7 = piVar7 + 1;
        if (pcVar6 == (char *)0x0) {
          return 0;
        }
      } while( true );
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0055878e
// Address: 0055878e
// XREFS: None
int FUN_0055878e(void)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 3;
  iVar3 = 0;
  if (3 < __nstream) {
    do {
      iVar1 = *(int *)(___piob + iVar2 * 4);
      if (iVar1 != 0) {
        if (((*(byte *)(iVar1 + 0xc) & 0x83) != 0) && (iVar1 = fclose(iVar1), iVar1 != -1)) {
          iVar3 = iVar3 + 1;
        }
        if (0x13 < iVar2) {
          free(*(undefined4 *)(___piob + iVar2 * 4));
          *(undefined4 *)(___piob + iVar2 * 4) = 0;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < __nstream);
  }
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_005587f8
// Address: 005587f8
// XREFS: None
int FUN_005587f8(uint param_1,int param_2)
{
  byte bVar1;
  
  param_2 = param_2 + 1;
  switch(param_2) {
  case 0:
  case 1:
  case 3:
    bVar1 = *(byte *)((int)&__mbctype + (param_1 & 0xff) + 1);
    if ((bVar1 & 4) != 0) {
      return 1;
    }
    if (((*(ushort *)(&DAT_005920da + (param_1 & 0xff) * 2) & 0x157) == 0) && ((bVar1 & 3) == 0)) {
      return -1;
    }
    param_2 = 0;
    break;
  case 2:
    return (-(uint)((*(byte *)((int)&__mbctype + (param_1 & 0xff) + 1) & 8) != 0) & 3) - 1;
  }
  return param_2;
}

// --------------------------------------------------

// Function: __mbbtype
// Address: 00558800
// XREFS: __mbsbtype
int __mbbtype(uint param_1,int param_2)
{
  byte bVar1;
  
  param_2 = param_2 + 1;
  switch(param_2) {
  case 0:
  case 1:
  case 3:
    bVar1 = *(byte *)((int)&__mbctype + (param_1 & 0xff) + 1);
    if ((bVar1 & 4) != 0) {
      return 1;
    }
    if (((*(ushort *)(&DAT_005920da + (param_1 & 0xff) * 2) & 0x157) == 0) && ((bVar1 & 3) == 0)) {
      return -1;
    }
    param_2 = 0;
    break;
  case 2:
    return (-(uint)((*(byte *)((int)&__mbctype + (param_1 & 0xff) + 1) & 8) != 0) & 3) - 1;
  }
  return param_2;
}

// --------------------------------------------------

// Function: FUN_0055885e
// Address: 0055885e
// XREFS: None
int __fastcall FUN_0055885e(char *param_1,char param_2)
{
  uint uVar1;
  byte bVar2;
  undefined4 in_EAX;
  undefined3 uVar4;
  char *pcVar3;
  byte bVar5;
  int unaff_EBX;
  char *unaff_EBP;
  
  uVar4 = (undefined3)((uint)in_EAX >> 8);
  pcVar3 = (char *)(CONCAT31(uVar4,(char)in_EAX + 'x') + (int)param_1 * 4);
  *pcVar3 = *pcVar3 + (char)((uint)param_1 >> 8);
  *param_1 = *param_1 + param_2;
  *unaff_EBP = param_2;
  bVar2 = (char)in_EAX - 0x10;
  *(char *)(unaff_EBX + -0x74fbdbbc) = *(char *)(unaff_EBX + -0x74fbdbbc) + (char)param_1;
  pcVar3 = (char *)(CONCAT31(uVar4,bVar2) | 0x8885e0);
  if (pcVar3 < param_1) {
    uVar1 = bVar2 & 0x1f;
    bVar2 = *(byte *)((&___pioinfo)[(int)pcVar3 >> 5] + 4 + uVar1 * 8);
    if ((bVar2 & 1) != 0) {
      if (unaff_EBP == (char *)0x8000) {
        bVar5 = bVar2 & 0x7f;
      }
      else {
        if (unaff_EBP != (char *)0x4000) {
          _errno = 0x16;
          return -1;
        }
        bVar5 = bVar2 | 0x80;
      }
      *(byte *)((&___pioinfo)[(int)pcVar3 >> 5] + 4 + uVar1 * 8) = bVar5;
      return (-(uint)((bVar2 & 0x80) != 0) & 0xffffc000) + 0x8000;
    }
  }
  _errno = 9;
  return -1;
}

// --------------------------------------------------

// Function: __setmode
// Address: 00558870
// XREFS: __chsize
int __setmode(uint param_1,int param_2)
{
  byte bVar1;
  byte bVar2;
  
  if (param_1 < __nhandle) {
    bVar1 = *(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8);
    if ((bVar1 & 1) != 0) {
      if (param_2 == 0x8000) {
        bVar2 = bVar1 & 0x7f;
      }
      else {
        if (param_2 != 0x4000) {
          _errno = 0x16;
          return -1;
        }
        bVar2 = bVar1 | 0x80;
      }
      *(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) = bVar2;
      return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
    }
  }
  _errno = 9;
  return -1;
}

// --------------------------------------------------

// Function: FUN_005588ee
// Address: 005588ee
// XREFS: None
undefined4
FUN_005588ee(ushort *param_1,int *param_2,byte *param_3,undefined4 param_4,int param_5,int param_6,
            int param_7)
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  byte bVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint uVar13;
  byte *pbVar14;
  int iStack_60;
  char *pcStack_5c;
  uint uStack_54;
  byte *pbStack_50;
  int iStack_4c;
  int iStack_48;
  undefined4 uStack_30;
  ushort uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  byte *pbStack_26;
  ushort uStack_22;
  char acStack_1c [23];
  char cStack_5;
  
  pcStack_5c = acStack_1c;
  iVar8 = 0;
  uVar13 = 0;
  uVar7 = 0;
  iStack_4c = 1;
  uStack_54 = 0;
  bVar2 = false;
  bVar4 = false;
  bVar3 = false;
  bVar5 = false;
  bVar6 = false;
  iStack_48 = 0;
  iStack_60 = 0;
  uStack_30 = 0;
  pbStack_50 = param_3;
  for (pbVar11 = param_3;
      (((bVar10 = *pbVar11, bVar10 == 0x20 || (bVar10 == 9)) || (bVar10 == 10)) ||
      (pbVar14 = param_3, bVar10 == 0xd)); pbVar11 = pbVar11 + 1) {
  }
  do {
    bVar10 = *pbVar11;
    pbVar12 = pbVar11 + 1;
    param_3 = (byte *)CONCAT31(param_3._1_3_,bVar10);
    switch(iVar8) {
    case 0:
      if (('0' < (char)bVar10) && ((char)bVar10 < ':')) {
        iVar8 = 3;
        goto LAB_00558dc2;
      }
      if (bVar10 == ___decimal_point) {
        iVar8 = 5;
      }
      else if (bVar10 == 0x2b) {
        iVar8 = 2;
        uVar7 = 0;
      }
      else if (bVar10 == 0x2d) {
        iVar8 = 2;
        uVar7 = 0x8000;
      }
      else {
        if (bVar10 != 0x30) goto switchD_00558bb2_caseD_2c;
        iVar8 = 1;
      }
      break;
    case 1:
      bVar2 = true;
      if (('0' < (char)bVar10) && ((char)bVar10 < ':')) {
        iVar8 = 3;
        goto LAB_00558dc2;
      }
      if (bVar10 == ___decimal_point) {
        iVar8 = 4;
      }
      else {
        switch(bVar10) {
        case 0x2b:
        case 0x2d:
          goto switchD_00558bb2_caseD_2b;
        default:
          goto switchD_00558bb2_caseD_2c;
        case 0x30:
switchD_00558a26_caseD_30:
          iVar8 = 1;
          break;
        case 0x44:
        case 0x45:
        case 100:
        case 0x65:
          goto switchD_00558bb2_caseD_44;
        }
      }
      break;
    case 2:
      if (('0' < (char)bVar10) && ((char)bVar10 < ':')) {
        iVar8 = 3;
        goto LAB_00558dc2;
      }
      if (bVar10 == ___decimal_point) {
        iVar8 = 5;
      }
      else {
        if (bVar10 == 0x30) goto switchD_00558a26_caseD_30;
        iVar8 = 10;
        pbVar12 = pbVar14;
      }
      break;
    case 3:
      while( true ) {
        bVar2 = true;
        if (___mb_cur_max < 2) {
          uVar9 = (byte)__pctype[((uint)param_3 & 0xff) * 2] & 4;
        }
        else {
          uVar9 = __isctype((uint)param_3 & 0xff,4);
        }
        if (uVar9 == 0) break;
        if (uVar13 < 0x19) {
          uVar13 = uVar13 + 1;
          *pcStack_5c = bVar10 - 0x30;
          bVar10 = *pbVar12;
          pcStack_5c = pcStack_5c + 1;
          param_3 = (byte *)CONCAT31(param_3._1_3_,bVar10);
          pbVar12 = pbVar12 + 1;
        }
        else {
          bVar10 = *pbVar12;
          iStack_60 = iStack_60 + 1;
          param_3 = (byte *)CONCAT31(param_3._1_3_,bVar10);
          pbVar12 = pbVar12 + 1;
        }
      }
      uStack_54 = uVar13;
      if (bVar10 != ___decimal_point) {
        switch(bVar10) {
        case 0x2b:
        case 0x2d:
          goto switchD_00558bb2_caseD_2b;
        case 0x44:
        case 0x45:
        case 100:
        case 0x65:
          goto switchD_00558bb2_caseD_44;
        }
switchD_00558bb2_caseD_2c:
        iVar8 = 10;
        goto LAB_00558dc2;
      }
      iVar8 = 4;
      break;
    case 4:
      bVar4 = true;
      if (uVar13 == 0) {
        while (bVar10 == 0x30) {
          bVar10 = *pbVar12;
          iStack_60 = iStack_60 + -1;
          pbVar12 = pbVar12 + 1;
          param_3._1_3_ = (undefined3)((uint)param_3 >> 8);
          param_3 = (byte *)CONCAT31(param_3._1_3_,bVar10);
        }
      }
      while( true ) {
        bVar2 = true;
        if (___mb_cur_max < 2) {
          uVar9 = (byte)__pctype[((uint)param_3 & 0xff) * 2] & 4;
        }
        else {
          uVar9 = __isctype((uint)param_3 & 0xff,4);
        }
        if (uVar9 == 0) break;
        if (uVar13 < 0x19) {
          uVar13 = uVar13 + 1;
          *pcStack_5c = bVar10 - 0x30;
          pcStack_5c = pcStack_5c + 1;
          iStack_60 = iStack_60 + -1;
        }
        bVar10 = *pbVar12;
        pbVar12 = pbVar12 + 1;
        param_3 = (byte *)CONCAT31(param_3._1_3_,bVar10);
      }
      uStack_54 = uVar13;
      switch(bVar10) {
      case 0x2b:
      case 0x2d:
switchD_00558bb2_caseD_2b:
        bVar2 = true;
        pbVar12 = pbVar12 + -1;
        iVar8 = 0xb;
        break;
      default:
        goto switchD_00558bb2_caseD_2c;
      case 0x44:
      case 0x45:
      case 100:
      case 0x65:
switchD_00558bb2_caseD_44:
        bVar2 = true;
        iVar8 = 6;
      }
      break;
    case 5:
      bVar4 = true;
      if (___mb_cur_max < 2) {
        uVar9 = (byte)__pctype[(uint)bVar10 * 2] & 4;
      }
      else {
        uVar9 = __isctype(bVar10,4);
      }
      if (uVar9 == 0) {
        iVar8 = 10;
        pbVar12 = pbVar14;
      }
      else {
        iVar8 = 4;
        pbVar12 = pbVar11;
      }
      break;
    case 6:
      pbVar11 = pbVar11 + -1;
      pbVar14 = pbVar11;
      pbStack_50 = pbVar11;
      if (('0' < (char)bVar10) && ((char)bVar10 < ':')) {
        iVar8 = 9;
        goto LAB_00558dc2;
      }
      if (bVar10 == 0x2b) {
LAB_00558db6:
        iVar8 = 7;
        pbVar14 = pbVar11;
        pbStack_50 = pbVar11;
      }
      else {
        if (bVar10 != 0x2d) goto LAB_00558ca6;
LAB_00558da7:
        iVar8 = 7;
        iStack_4c = -1;
        pbVar14 = pbVar11;
        pbStack_50 = pbVar11;
      }
      break;
    case 7:
      if (('0' < (char)bVar10) && ((char)bVar10 < ':')) {
        iVar8 = 9;
        goto LAB_00558dc2;
      }
LAB_00558ca6:
      if (bVar10 == 0x30) {
        iVar8 = 8;
      }
      else {
        iVar8 = 10;
        pbVar12 = pbVar14;
      }
      break;
    case 8:
      bVar3 = true;
      while (bVar10 == 0x30) {
        bVar10 = *pbVar12;
        pbVar12 = pbVar12 + 1;
      }
      if (((char)bVar10 < '1') || ('9' < (char)bVar10)) goto switchD_00558bb2_caseD_2c;
      iVar8 = 9;
LAB_00558dc2:
      pbVar12 = pbVar12 + -1;
      break;
    case 9:
      bVar3 = true;
      iStack_48 = 0;
      while( true ) {
        if (___mb_cur_max < 2) {
          uVar13 = (byte)__pctype[((uint)param_3 & 0xff) * 2] & 4;
        }
        else {
          uVar13 = __isctype((uint)param_3 & 0xff,4);
        }
        if (uVar13 == 0) goto LAB_00558d2a;
        iStack_48 = (char)bVar10 + -0x30 + iStack_48 * 10;
        if (0x1450 < iStack_48) break;
        bVar10 = *pbVar12;
        pbVar12 = pbVar12 + 1;
        param_3 = (byte *)CONCAT31(param_3._1_3_,bVar10);
      }
      iStack_48 = 0x1451;
LAB_00558d2a:
      while( true ) {
        if (___mb_cur_max < 2) {
          uVar13 = (byte)__pctype[((uint)param_3 & 0xff) * 2] & 4;
        }
        else {
          uVar13 = __isctype((uint)param_3 & 0xff,4);
        }
        if (uVar13 == 0) break;
        bVar10 = *pbVar12;
        pbVar12 = pbVar12 + 1;
        param_3 = (byte *)CONCAT31(param_3._1_3_,bVar10);
      }
      iVar8 = 10;
      pbVar12 = pbVar12 + -1;
      uVar13 = uStack_54;
      pbVar14 = pbStack_50;
      break;
    case 0xb:
      if (param_7 == 0) goto switchD_00558bb2_caseD_2c;
      if (bVar10 == 0x2b) goto LAB_00558db6;
      if (bVar10 == 0x2d) goto LAB_00558da7;
      iVar8 = 10;
      pbVar12 = pbVar11;
      pbVar14 = pbVar11;
      pbStack_50 = pbVar11;
    }
    pbVar11 = pbVar12;
  } while (iVar8 != 10);
  *param_2 = (int)pbVar12;
  if (bVar2) {
    if (0x18 < uVar13) {
      if ('\x04' < cStack_5) {
        cStack_5 = cStack_5 + '\x01';
      }
      pcStack_5c = pcStack_5c + -1;
      iStack_60 = iStack_60 + 1;
      uVar13 = 0x18;
    }
    if (uVar13 == 0) {
      uStack_2c = 0;
      uStack_22 = 0;
      param_3 = (byte *)0x0;
      pbVar11 = (byte *)0x0;
      goto LAB_00558e94;
    }
    cVar1 = pcStack_5c[-1];
    while (cVar1 == '\0') {
      uVar13 = uVar13 - 1;
      iStack_60 = iStack_60 + 1;
      cVar1 = pcStack_5c[-2];
      pcStack_5c = pcStack_5c + -1;
    }
    ___mtold12(acStack_1c,uVar13,&uStack_2c);
    if (iStack_4c < 0) {
      iStack_48 = -iStack_48;
    }
    iStack_48 = iStack_48 + iStack_60;
    if (!bVar3) {
      iStack_48 = iStack_48 + param_5;
    }
    if (!bVar4) {
      iStack_48 = iStack_48 - param_6;
    }
    if (iStack_48 < 0x1451) {
      if (-0x1451 < iStack_48) {
        ___multtenpow12(&uStack_2c,iStack_48,param_4);
        pbVar11 = (byte *)CONCAT22(uStack_28,uStack_2a);
        param_3 = pbStack_26;
        goto LAB_00558e94;
      }
      bVar6 = true;
    }
    else {
      bVar5 = true;
    }
  }
  uStack_2c = (ushort)param_3;
  pbVar11 = param_3;
  uStack_22 = uStack_2c;
LAB_00558e94:
  if (bVar2) {
    if (bVar5) {
      pbVar11 = (byte *)0x0;
      uStack_22 = 0x7fff;
      param_3 = (byte *)0x80000000;
      uStack_2c = 0;
      uStack_30 = 2;
    }
    else if (bVar6) {
      uStack_2c = 0;
      uStack_22 = 0;
      param_3 = (byte *)0x0;
      pbVar11 = (byte *)0x0;
      uStack_30 = 1;
    }
  }
  else {
    uStack_2c = 0;
    uStack_22 = 0;
    param_3 = (byte *)0x0;
    pbVar11 = (byte *)0x0;
    uStack_30 = 4;
  }
  *param_1 = uStack_2c;
  *(byte **)(param_1 + 1) = pbVar11;
  *(byte **)(param_1 + 3) = param_3;
  param_1[5] = uStack_22 | uVar7;
  return uStack_30;
}

// --------------------------------------------------

