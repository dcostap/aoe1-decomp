// GLOBAL FUNCTIONS PART 6000
// Function: FUN_0054f446
// Address: 0054f446
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0054f446(undefined4 param_1,undefined4 param_2)
{
  double dVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  
  uVar2 = __ctrlfp();
  if ((param_2._2_2_ & 0x7ff0) != 0x7ff0) {
    fVar4 = (float10)__frnd();
    dVar1 = (double)fVar4;
    if ((dVar1 != (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1))) &&
       ((uVar2 & 0x20) == 0)) {
      fVar4 = (float10)__except1(0x10,0xc,param_1,param_2,dVar1,uVar2);
      return fVar4;
    }
    __ctrlfp();
    return (float10)dVar1;
  }
  iVar3 = __sptype();
  if (0 < iVar3) {
    if (iVar3 < 3) {
      __ctrlfp();
      return (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
    }
    if (iVar3 == 3) {
      fVar4 = (float10)__handle_qnan1(0xc,param_1,param_2,uVar2);
      return fVar4;
    }
  }
  fVar4 = (float10)__except1(8,0xc,param_1,param_2,
                             (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) -
                             _DAT_00577a90,uVar2);
  return fVar4;
}

// --------------------------------------------------

// Function: ceil
// Address: 0054f450
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* ceil */

float10 __cdecl ceil(undefined4 param_1,undefined4 param_2)
{
  double dVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  
  uVar2 = __ctrlfp();
  if ((param_2._2_2_ & 0x7ff0) != 0x7ff0) {
    fVar4 = (float10)__frnd();
    dVar1 = (double)fVar4;
    if ((dVar1 != (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1))) &&
       ((uVar2 & 0x20) == 0)) {
      fVar4 = (float10)__except1(0x10,0xc,param_1,param_2,dVar1,uVar2);
      return fVar4;
    }
    __ctrlfp();
    return (float10)dVar1;
  }
  iVar3 = __sptype();
  if (0 < iVar3) {
    if (iVar3 < 3) {
      __ctrlfp();
      return (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
    }
    if (iVar3 == 3) {
      fVar4 = (float10)__handle_qnan1(0xc,param_1,param_2,uVar2);
      return fVar4;
    }
  }
  fVar4 = (float10)__except1(8,0xc,param_1,param_2,
                             (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) -
                             _DAT_00577a90,uVar2);
  return fVar4;
}

// --------------------------------------------------

// Function: FUN_0054f549
// Address: 0054f549
int FUN_0054f549(byte *param_1,char *param_2,int param_3)
{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  if (param_3 != 0) {
    if (DAT_008882c0 == 0) {
      do {
        bVar2 = *param_1;
        cVar1 = *param_2;
        uVar3 = CONCAT11(bVar2,cVar1);
        if (bVar2 == 0) break;
        uVar3 = CONCAT11(bVar2,cVar1);
        uVar5 = (uint)uVar3;
        if (cVar1 == '\0') break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
          uVar5 = (uint)CONCAT11(bVar2 + 0x20,cVar1);
        }
        uVar3 = (ushort)uVar5;
        bVar2 = (byte)uVar5;
        if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
          uVar3 = (ushort)CONCAT31((int3)(uVar5 >> 8),bVar2 + 0x20);
        }
        bVar2 = (byte)(uVar3 >> 8);
        bVar6 = bVar2 < (byte)uVar3;
        if (bVar2 != (byte)uVar3) goto LAB_0054f5ab;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      param_3 = 0;
      bVar2 = (byte)(uVar3 >> 8);
      bVar6 = bVar2 < (byte)uVar3;
      if (bVar2 != (byte)uVar3) {
LAB_0054f5ab:
        param_3 = -1;
        if (!bVar6) {
          param_3 = 1;
        }
      }
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      do {
        uVar4 = CONCAT31((int3)(uVar4 >> 8),*param_1);
        uVar5 = CONCAT31((int3)(uVar5 >> 8),*param_2);
        if ((uVar4 == 0) || (uVar5 == 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        uVar5 = tolower(uVar5,uVar4);
        uVar4 = tolower();
        bVar6 = uVar4 < uVar5;
        if (uVar4 != uVar5) goto LAB_0054f5ed;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      param_3 = 0;
      bVar6 = uVar4 < uVar5;
      if (uVar4 != uVar5) {
LAB_0054f5ed:
        param_3 = -1;
        if (!bVar6) {
          param_3 = 1;
        }
      }
    }
  }
  return param_3;
}

// --------------------------------------------------

// Function: __strnicmp
// Address: 0054f550
int __strnicmp(byte *param_1,char *param_2,int param_3)
{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  if (param_3 != 0) {
    if (DAT_008882c0 == 0) {
      do {
        bVar2 = *param_1;
        cVar1 = *param_2;
        uVar3 = CONCAT11(bVar2,cVar1);
        if (bVar2 == 0) break;
        uVar3 = CONCAT11(bVar2,cVar1);
        uVar5 = (uint)uVar3;
        if (cVar1 == '\0') break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
          uVar5 = (uint)CONCAT11(bVar2 + 0x20,cVar1);
        }
        uVar3 = (ushort)uVar5;
        bVar2 = (byte)uVar5;
        if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
          uVar3 = (ushort)CONCAT31((int3)(uVar5 >> 8),bVar2 + 0x20);
        }
        bVar2 = (byte)(uVar3 >> 8);
        bVar6 = bVar2 < (byte)uVar3;
        if (bVar2 != (byte)uVar3) goto LAB_0054f5ab;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      param_3 = 0;
      bVar2 = (byte)(uVar3 >> 8);
      bVar6 = bVar2 < (byte)uVar3;
      if (bVar2 != (byte)uVar3) {
LAB_0054f5ab:
        param_3 = -1;
        if (!bVar6) {
          param_3 = 1;
        }
      }
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      do {
        uVar4 = CONCAT31((int3)(uVar4 >> 8),*param_1);
        uVar5 = CONCAT31((int3)(uVar5 >> 8),*param_2);
        if ((uVar4 == 0) || (uVar5 == 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        uVar5 = tolower(uVar5,uVar4);
        uVar4 = tolower();
        bVar6 = uVar4 < uVar5;
        if (uVar4 != uVar5) goto LAB_0054f5ed;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      param_3 = 0;
      bVar6 = uVar4 < uVar5;
      if (uVar4 != uVar5) {
LAB_0054f5ed:
        param_3 = -1;
        if (!bVar6) {
          param_3 = 1;
        }
      }
    }
  }
  return param_3;
}

// --------------------------------------------------

// Function: strlen
// Address: 0054f600
/* strlen */

char * __cdecl strlen(uint *param_1)
{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  uVar1 = (uint)param_1 & 3;
  puVar2 = param_1;
  while (uVar1 != 0) {
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
    if ((char)uVar1 == '\0') goto LAB_0054f653;
    uVar1 = (uint)puVar2 & 3;
  }
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (char *)((int)puVar3 - (int)param_1);
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (char *)((int)puVar3 + (1 - (int)param_1));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (char *)((int)puVar3 + (2 - (int)param_1));
    }
  } while ((uVar1 & 0xff000000) != 0);
LAB_0054f653:
  return (char *)((int)puVar2 + (-1 - (int)param_1));
}

// --------------------------------------------------

// Function: __cinit
// Address: 0054f680
void __cinit(void)
{
  if (__FPinit != (undefined *)0x0) {
    (*(code *)__FPinit)();
  }
  FUN_0054f7c0(&___xi_a,&___xi_z);
  FUN_0054f7c0(&___xc_a,&___xc_z);
  return;
}

// --------------------------------------------------

// Function: _exit
// Address: 0054f6b0
void _exit(undefined4 param_1)
{
  FUN_0054f710(param_1,0,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0054f6c2
// Address: 0054f6c2
void FUN_0054f6c2(undefined4 param_1)
{
  FUN_0054f710(param_1,1,0);
  return;
}

// --------------------------------------------------

// Function: __exit
// Address: 0054f6d0
void __exit(undefined4 param_1)
{
  FUN_0054f710(param_1,1,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0054f6e2
// Address: 0054f6e2
void FUN_0054f6e2(void)
{
  FUN_0054f710(0,0,1);
  return;
}

// --------------------------------------------------

// Function: FUN_0054f6ff
// Address: 0054f6ff
void FUN_0054f6ff(void)
{
  FUN_0054f710(0,1,1);
  return;
}

// --------------------------------------------------

// Function: FUN_0054f70f
// Address: 0054f70f
void FUN_0054f70f(undefined4 param_1,int param_2,int param_3)
{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (__C_Exit_Done == 1) {
    uVar1 = GetCurrentProcess(param_1);
    TerminateProcess(uVar1);
  }
  __wpgmptr._8_4_ = 1;
  __wpgmptr._4_1_ = (undefined1)param_3;
  if (param_2 == 0) {
    if ((___onexitbegin != (undefined4 *)0x0) &&
       (puVar3 = (undefined4 *)(___onexitend + -4), puVar2 = ___onexitbegin,
       ___onexitbegin <= puVar3)) {
      do {
        if ((code *)*puVar3 != (code *)0x0) {
          (*(code *)*puVar3)();
          puVar2 = ___onexitbegin;
        }
        puVar3 = puVar3 + -1;
      } while (puVar2 <= puVar3);
    }
    FUN_0054f7c0(&___xp_a,&___xp_z);
  }
  FUN_0054f7c0(&___xt_a,&___xt_z);
  if (param_3 == 0) {
    __C_Exit_Done = 1;
    ExitProcess(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054f710
// Address: 0054f710
void FUN_0054f710(undefined4 param_1,int param_2,int param_3)
{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (__C_Exit_Done == 1) {
    uVar1 = GetCurrentProcess(param_1);
    TerminateProcess(uVar1);
  }
  __wpgmptr._8_4_ = 1;
  __wpgmptr._4_1_ = (undefined1)param_3;
  if (param_2 == 0) {
    if ((___onexitbegin != (undefined4 *)0x0) &&
       (puVar3 = (undefined4 *)(___onexitend + -4), puVar2 = ___onexitbegin,
       ___onexitbegin <= puVar3)) {
      do {
        if ((code *)*puVar3 != (code *)0x0) {
          (*(code *)*puVar3)();
          puVar2 = ___onexitbegin;
        }
        puVar3 = puVar3 + -1;
      } while (puVar2 <= puVar3);
    }
    FUN_0054f7c0(&___xp_a,&___xp_z);
  }
  FUN_0054f7c0(&___xt_a,&___xt_z);
  if (param_3 == 0) {
    __C_Exit_Done = 1;
    ExitProcess(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054f7b4
// Address: 0054f7b4
void FUN_0054f7b4(undefined4 *param_1,undefined4 *param_2)
{
  if (param_1 < param_2) {
    do {
      if ((code *)*param_1 != (code *)0x0) {
        (*(code *)*param_1)();
      }
      param_1 = param_1 + 1;
    } while (param_1 < param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054f7c0
// Address: 0054f7c0
void FUN_0054f7c0(undefined4 *param_1,undefined4 *param_2)
{
  if (param_1 < param_2) {
    do {
      if ((code *)*param_1 != (code *)0x0) {
        (*(code *)*param_1)();
      }
      param_1 = param_1 + 1;
    } while (param_1 < param_2);
  }
  return;
}

// --------------------------------------------------

// Function: __mbsupr
// Address: 0054f7e0
byte * __mbsupr(byte *param_1)
{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  
  pbVar2 = param_1;
  pbVar5 = param_1;
  if (*param_1 == 0) {
    return param_1;
  }
  do {
    bVar3 = *pbVar5;
    if ((*(byte *)((int)&__mbctype + bVar3 + 1) & 4) == 0) {
      if ((0x60 < bVar3) && (bVar3 < 0x7b)) {
        bVar3 = bVar3 - 0x20;
      }
      *pbVar5 = bVar3;
    }
    else {
      iVar4 = ___crtLCMapStringA(___mblcid,0x200,pbVar5,2,&param_1,2,___mbcodepage);
      if (iVar4 == 0) {
        return (byte *)0x0;
      }
      *pbVar5 = (byte)param_1;
      if (1 < iVar4) {
        pbVar5 = pbVar5 + 1;
        *pbVar5 = (byte)((uint)param_1 >> 8);
      }
    }
    pbVar1 = pbVar5 + 1;
    pbVar5 = pbVar5 + 1;
  } while (*pbVar1 != 0);
  return pbVar2;
}

// --------------------------------------------------

// Function: FUN_0054f862
// Address: 0054f862
void FUN_0054f862(void)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 auStack_60 [44];
  uint uStack_34;
  uint uStack_30;
  undefined1 *puStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  byte *pbVar6;
  
  uStack_8 = 0xffffffff;
  puStack_c = &DAT_00577a98;
  uStack_10 = 0x554df8;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  puStack_1c = &stack0xffffff88;
  uVar2 = GetVersion();
  __osver._12_4_ = uVar2 >> 8 & 0xff;
  __osver._8_4_ = uVar2 & 0xff;
  __osver._4_4_ = __osver._8_4_ * 0x100 + __osver._12_4_;
  __osver._0_4_ = uVar2 >> 0x10;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  uStack_8 = 0;
  __ioinit();
  ___initmbctable();
  __acmdln = (byte *)GetCommandLineA();
  __aenvptr = ___crtGetEnvironmentStringsA();
  if ((__aenvptr == 0) || (__acmdln == (byte *)0x0)) {
    _exit(0xffffffff);
  }
  __setargv();
  __setenvp();
  __cinit();
  pbVar5 = __acmdln;
  if (*__acmdln == 0x22) {
    while( true ) {
      pbVar6 = pbVar5;
      pbVar5 = pbVar6 + 1;
      bVar1 = *pbVar5;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar3 = __ismbblead(bVar1);
      if (iVar3 != 0) {
        pbVar5 = pbVar6 + 2;
      }
    }
    if (*pbVar5 == 0x22) {
      pbVar5 = pbVar6 + 2;
    }
  }
  else {
    for (; 0x20 < *pbVar5; pbVar5 = pbVar5 + 1) {
    }
  }
  for (; (*pbVar5 != 0 && (*pbVar5 < 0x21)); pbVar5 = pbVar5 + 1) {
  }
  uStack_34 = 0;
  GetStartupInfoA(auStack_60);
  if ((uStack_34 & 1) == 0) {
    uStack_30 = 10;
  }
  else {
    uStack_30 = uStack_30 & 0xffff;
  }
  uVar8 = 0;
  uVar7 = 0;
  uVar4 = GetModuleHandleA(0,0,pbVar5,uStack_30);
  uVar4 = _WinMain_16(uVar4,uVar7,uVar8,pbVar5);
  _exit(uVar4);
  *unaff_FS_OFFSET = uStack_14;
  return;
}

// --------------------------------------------------

// Function: entry
// Address: 0054f870
void entry(void)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 local_60 [44];
  uint local_34;
  uint local_30;
  undefined1 *local_1c;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  byte *pbVar6;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00577a98;
  uStack_10 = 0x554df8;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff88;
  uVar2 = GetVersion();
  __osver._12_4_ = uVar2 >> 8 & 0xff;
  __osver._8_4_ = uVar2 & 0xff;
  __osver._4_4_ = __osver._8_4_ * 0x100 + __osver._12_4_;
  __osver._0_4_ = uVar2 >> 0x10;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  __acmdln = (byte *)GetCommandLineA();
  __aenvptr = ___crtGetEnvironmentStringsA();
  if ((__aenvptr == 0) || (__acmdln == (byte *)0x0)) {
    _exit(0xffffffff);
  }
  __setargv();
  __setenvp();
  __cinit();
  pbVar5 = __acmdln;
  if (*__acmdln == 0x22) {
    while( true ) {
      pbVar6 = pbVar5;
      pbVar5 = pbVar6 + 1;
      bVar1 = *pbVar5;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar3 = __ismbblead(bVar1);
      if (iVar3 != 0) {
        pbVar5 = pbVar6 + 2;
      }
    }
    if (*pbVar5 == 0x22) {
      pbVar5 = pbVar6 + 2;
    }
  }
  else {
    for (; 0x20 < *pbVar5; pbVar5 = pbVar5 + 1) {
    }
  }
  for (; (*pbVar5 != 0 && (*pbVar5 < 0x21)); pbVar5 = pbVar5 + 1) {
  }
  local_34 = 0;
  GetStartupInfoA(local_60);
  if ((local_34 & 1) == 0) {
    local_30 = 10;
  }
  else {
    local_30 = local_30 & 0xffff;
  }
  uVar8 = 0;
  uVar7 = 0;
  uVar4 = GetModuleHandleA(0,0,pbVar5,local_30);
  uVar4 = _WinMain_16(uVar4,uVar7,uVar8,pbVar5);
  _exit(uVar4);
  *unaff_FS_OFFSET = uStack_14;
  return;
}

// --------------------------------------------------

// Function: FUN_0054f9ba
// Address: 0054f9ba
void FUN_0054f9ba(void)
{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = *(undefined4 *)**(undefined4 **)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x68) = uVar1;
  __XcptFilter(uVar1,*(undefined4 **)(unaff_EBP + -0x14));
  return;
}

// --------------------------------------------------

// Function: FUN_0054f9cf
// Address: 0054f9cf
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_0054f9cf(void)
{
  int iVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar1 + -4) = *(undefined4 *)(unaff_EBP + -0x68);
  *(undefined4 *)(iVar1 + -8) = 0x54f9db;
  __exit();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_0054fa05
// Address: 0054fa05
void FUN_0054fa05(undefined4 param_1)
{
  if (___error_mode == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)__aexit_rtn)(0xff);
  return;
}

// --------------------------------------------------

// Function: __amsg_exit
// Address: 0054fa10
void __amsg_exit(undefined4 param_1)
{
  if (___error_mode == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)__aexit_rtn)(0xff);
  return;
}

// --------------------------------------------------

// Function: FUN_0054fa3a
// Address: 0054fa3a
undefined4
FUN_0054fa3a(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5,
            int param_6,undefined4 param_7,undefined4 param_8)
{
  undefined4 uVar1;
  
  if (*param_5 != 0x19930520) {
    _inconsistency();
  }
  if ((*(byte *)(param_1 + 1) & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((*param_1 == -0x1f928c9d) && (0x19930520 < (uint)param_1[5])) &&
         (*(code **)(param_1[7] + 8) != (code *)0x0)) {
        uVar1 = (**(code **)(param_1[7] + 8))
                          (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar1;
      }
      FUN_0054fb10(param_1,param_2,param_3,param_4,param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    ___FrameUnwindToState(param_2,param_4,param_5,0xffffffff);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: ___InternalCxxFrameHandler
// Address: 0054fa40
undefined4
___InternalCxxFrameHandler
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5,
          int param_6,undefined4 param_7,undefined4 param_8)
{
  undefined4 uVar1;
  
  if (*param_5 != 0x19930520) {
    _inconsistency();
  }
  if ((*(byte *)(param_1 + 1) & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((*param_1 == -0x1f928c9d) && (0x19930520 < (uint)param_1[5])) &&
         (*(code **)(param_1[7] + 8) != (code *)0x0)) {
        uVar1 = (**(code **)(param_1[7] + 8))
                          (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar1;
      }
      FUN_0054fb10(param_1,param_2,param_3,param_4,param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    ___FrameUnwindToState(param_2,param_4,param_5,0xffffffff);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0054fb07
// Address: 0054fb07
void FUN_0054fb07(EHExceptionRecord *param_1,int param_2,_CONTEXT *param_3,undefined4 param_4,
                 _s_FuncInfo *param_5,char param_6,int param_7,undefined4 param_8)
{
  byte bVar1;
  EHExceptionRecord *pEVar2;
  int iVar3;
  byte *pbVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  uint uStack_20;
  _s_TryBlockMapEntry *p_Stack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  uint uStack_c;
  int *piStack_8;
  int iStack_4;
  
  iVar6 = *(int *)(param_2 + 8);
  iStack_10 = iVar6;
  if ((iVar6 < -1) || (*(int *)(param_5 + 4) <= iVar6)) {
    _inconsistency();
  }
  pEVar2 = _pCurrentException;
  if (*(int *)param_1 == -0x1f928c9d) {
    if (((*(int *)(param_1 + 0x10) == 3) && (*(int *)(param_1 + 0x14) == 0x19930520)) &&
       (*(int *)(param_1 + 0x1c) == 0)) {
      if (_pCurrentException == (EHExceptionRecord *)0x0) {
        return;
      }
      param_1 = _pCurrentException;
      param_3 = _pCurrentExContext;
      iVar3 = _ValidateRead(_pCurrentException,1);
      if (iVar3 == 0) {
        _inconsistency();
      }
      if (*(int *)pEVar2 != -0x1f928c9d) goto LAB_0054fd7b;
      if (((*(int *)(pEVar2 + 0x10) == 3) && (*(int *)(pEVar2 + 0x14) == 0x19930520)) &&
         (*(int *)(pEVar2 + 0x1c) == 0)) {
        _inconsistency();
      }
    }
    if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
       (*(int *)(param_1 + 0x14) == 0x19930520)) {
      p_Stack_1c = _GetRangeOfTrysToCheck(param_5,param_7,iVar6,&uStack_20,&uStack_c);
      if (uStack_20 < uStack_c) {
        do {
          if ((*(int *)p_Stack_1c <= iVar6) && (iVar6 <= *(int *)(p_Stack_1c + 4))) {
            iStack_14 = *(int *)(p_Stack_1c + 0xc);
            pbVar8 = *(byte **)(p_Stack_1c + 0x10);
            if (0 < iStack_14) {
              piStack_8 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc) + 1;
              iStack_4 = **(int **)(*(int *)(param_1 + 0x1c) + 0xc);
              do {
                iStack_18 = iStack_4;
                if (0 < iStack_4) {
                  iVar6 = *(int *)(pbVar8 + 4);
                  piVar5 = piStack_8;
                  do {
                    if ((iVar6 == 0) || (pbVar4 = (byte *)(iVar6 + 8), *(char *)(iVar6 + 8) == '\0')
                       ) {
LAB_0054fcd4:
                      bVar9 = true;
                    }
                    else {
                      iVar3 = *(int *)((byte *)*piVar5 + 4);
                      if (iVar6 == iVar3) {
LAB_0054fcaf:
                        if (((((*(byte *)*piVar5 & 2) == 0) || ((*pbVar8 & 8) != 0)) &&
                            (((**(uint **)(param_1 + 0x1c) & 1) == 0 || ((*pbVar8 & 1) != 0)))) &&
                           (((**(uint **)(param_1 + 0x1c) & 2) == 0 || ((*pbVar8 & 2) != 0))))
                        goto LAB_0054fcd4;
                        bVar9 = false;
                      }
                      else {
                        pbVar7 = (byte *)(iVar3 + 8);
                        do {
                          bVar1 = *pbVar4;
                          bVar9 = bVar1 < *pbVar7;
                          if (bVar1 != *pbVar7) {
LAB_0054fc92:
                            iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
                            goto LAB_0054fc97;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = pbVar4[1];
                          bVar9 = bVar1 < pbVar7[1];
                          if (bVar1 != pbVar7[1]) goto LAB_0054fc92;
                          pbVar4 = pbVar4 + 2;
                          pbVar7 = pbVar7 + 2;
                        } while (bVar1 != 0);
                        iVar3 = 0;
LAB_0054fc97:
                        if (iVar3 == 0) goto LAB_0054fcaf;
                        bVar9 = false;
                      }
                    }
                    if (bVar9) {
                      FUN_0054ff70(param_1,param_2,param_3,param_4,param_5,pbVar8,*piVar5,p_Stack_1c
                                   ,param_7,param_8);
                      iVar6 = iStack_10;
                      goto LAB_0054fd44;
                    }
                    piVar5 = piVar5 + 1;
                    iStack_18 = iStack_18 + -1;
                  } while (0 < iStack_18);
                }
                iStack_14 = iStack_14 + -1;
                pbVar8 = pbVar8 + 0x10;
                iVar6 = iStack_10;
              } while (0 < iStack_14);
            }
          }
LAB_0054fd44:
          uStack_20 = uStack_20 + 1;
          p_Stack_1c = p_Stack_1c + 0x14;
        } while (uStack_20 < uStack_c);
      }
      if (param_6 == '\0') {
        return;
      }
      _DestructExceptionObject(param_1,'\x01');
      return;
    }
  }
LAB_0054fd7b:
  if (param_6 != '\0') {
    terminate();
    return;
  }
  FUN_0054fdc0(param_1,param_2,param_3,param_4,param_5,iVar6,param_7,param_8);
  return;
}

// --------------------------------------------------

// Function: FUN_0054fb10
// Address: 0054fb10
void FUN_0054fb10(EHExceptionRecord *param_1,int param_2,_CONTEXT *param_3,undefined4 param_4,
                 _s_FuncInfo *param_5,char param_6,int param_7,undefined4 param_8)
{
  byte bVar1;
  EHExceptionRecord *pEVar2;
  int iVar3;
  byte *pbVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  uint local_20;
  _s_TryBlockMapEntry *local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int *local_8;
  int local_4;
  
  iVar6 = *(int *)(param_2 + 8);
  local_10 = iVar6;
  if ((iVar6 < -1) || (*(int *)(param_5 + 4) <= iVar6)) {
    _inconsistency();
  }
  pEVar2 = _pCurrentException;
  if (*(int *)param_1 == -0x1f928c9d) {
    if (((*(int *)(param_1 + 0x10) == 3) && (*(int *)(param_1 + 0x14) == 0x19930520)) &&
       (*(int *)(param_1 + 0x1c) == 0)) {
      if (_pCurrentException == (EHExceptionRecord *)0x0) {
        return;
      }
      param_1 = _pCurrentException;
      param_3 = _pCurrentExContext;
      iVar3 = _ValidateRead(_pCurrentException,1);
      if (iVar3 == 0) {
        _inconsistency();
      }
      if (*(int *)pEVar2 != -0x1f928c9d) goto LAB_0054fd7b;
      if (((*(int *)(pEVar2 + 0x10) == 3) && (*(int *)(pEVar2 + 0x14) == 0x19930520)) &&
         (*(int *)(pEVar2 + 0x1c) == 0)) {
        _inconsistency();
      }
    }
    if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
       (*(int *)(param_1 + 0x14) == 0x19930520)) {
      local_1c = _GetRangeOfTrysToCheck(param_5,param_7,iVar6,&local_20,&local_c);
      if (local_20 < local_c) {
        do {
          if ((*(int *)local_1c <= iVar6) && (iVar6 <= *(int *)(local_1c + 4))) {
            local_14 = *(int *)(local_1c + 0xc);
            pbVar8 = *(byte **)(local_1c + 0x10);
            if (0 < local_14) {
              local_8 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc) + 1;
              local_4 = **(int **)(*(int *)(param_1 + 0x1c) + 0xc);
              do {
                local_18 = local_4;
                if (0 < local_4) {
                  iVar6 = *(int *)(pbVar8 + 4);
                  piVar5 = local_8;
                  do {
                    if ((iVar6 == 0) || (pbVar4 = (byte *)(iVar6 + 8), *(char *)(iVar6 + 8) == '\0')
                       ) {
LAB_0054fcd4:
                      bVar9 = true;
                    }
                    else {
                      iVar3 = *(int *)((byte *)*piVar5 + 4);
                      if (iVar6 == iVar3) {
LAB_0054fcaf:
                        if (((((*(byte *)*piVar5 & 2) == 0) || ((*pbVar8 & 8) != 0)) &&
                            (((**(uint **)(param_1 + 0x1c) & 1) == 0 || ((*pbVar8 & 1) != 0)))) &&
                           (((**(uint **)(param_1 + 0x1c) & 2) == 0 || ((*pbVar8 & 2) != 0))))
                        goto LAB_0054fcd4;
                        bVar9 = false;
                      }
                      else {
                        pbVar7 = (byte *)(iVar3 + 8);
                        do {
                          bVar1 = *pbVar4;
                          bVar9 = bVar1 < *pbVar7;
                          if (bVar1 != *pbVar7) {
LAB_0054fc92:
                            iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
                            goto LAB_0054fc97;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = pbVar4[1];
                          bVar9 = bVar1 < pbVar7[1];
                          if (bVar1 != pbVar7[1]) goto LAB_0054fc92;
                          pbVar4 = pbVar4 + 2;
                          pbVar7 = pbVar7 + 2;
                        } while (bVar1 != 0);
                        iVar3 = 0;
LAB_0054fc97:
                        if (iVar3 == 0) goto LAB_0054fcaf;
                        bVar9 = false;
                      }
                    }
                    if (bVar9) {
                      FUN_0054ff70(param_1,param_2,param_3,param_4,param_5,pbVar8,*piVar5,local_1c,
                                   param_7,param_8);
                      iVar6 = local_10;
                      goto LAB_0054fd44;
                    }
                    piVar5 = piVar5 + 1;
                    local_18 = local_18 + -1;
                  } while (0 < local_18);
                }
                local_14 = local_14 + -1;
                pbVar8 = pbVar8 + 0x10;
                iVar6 = local_10;
              } while (0 < local_14);
            }
          }
LAB_0054fd44:
          local_20 = local_20 + 1;
          local_1c = local_1c + 0x14;
        } while (local_20 < local_c);
      }
      if (param_6 == '\0') {
        return;
      }
      _DestructExceptionObject(param_1,'\x01');
      return;
    }
  }
LAB_0054fd7b:
  if (param_6 != '\0') {
    terminate();
    return;
  }
  FUN_0054fdc0(param_1,param_2,param_3,param_4,param_5,iVar6,param_7,param_8);
  return;
}

// --------------------------------------------------

// Function: FUN_0054fdc0
// Address: 0054fdc0
void FUN_0054fdc0(EHExceptionRecord *param_1,EHRegistrationNode *param_2,void *param_3,void *param_4
                 ,_s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7,
                 EHRegistrationNode *param_8)
{
  EHRegistrationNode *pEVar1;
  EHRegistrationNode *pEVar2;
  int iVar3;
  _s_TryBlockMapEntry *p_Var4;
  int iVar5;
  
  pEVar2 = param_8;
  pEVar1 = param_7;
  if ((__pSETranslator != (_func_void_uint__EXCEPTION_POINTERS_ptr *)0x0) &&
     (iVar3 = _CallSETranslator(param_1,param_2,param_3,param_4,param_5,(int)param_7,param_8),
     iVar3 != 0)) {
    return;
  }
  p_Var4 = _GetRangeOfTrysToCheck(param_5,(int)pEVar1,param_6,(uint *)&param_8,(uint *)&param_7);
  if (param_8 < param_7) {
    do {
      if ((*(int *)p_Var4 <= param_6) && (param_6 <= *(int *)(p_Var4 + 4))) {
        iVar5 = *(int *)(p_Var4 + 0x10) + *(int *)(p_Var4 + 0xc) * 0x10;
        iVar3 = *(int *)(iVar5 + -0xc);
        if ((iVar3 == 0) || (*(char *)(iVar3 + 8) == '\0')) {
          FUN_0054ff70(param_1,param_2,param_3,param_4,param_5,iVar5 + -0x10,0,p_Var4,pEVar1,pEVar2)
          ;
        }
      }
      param_8 = param_8 + 1;
      p_Var4 = p_Var4 + 0x14;
    } while (param_8 < param_7);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054fe8e
// Address: 0054fe8e
void FUN_0054fe8e(int param_1,undefined4 param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &DAT_00577aa8;
  uStack_10 = 0x554df8;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  for (iVar2 = *(int *)(param_1 + 8); uStack_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      _inconsistency();
    }
    uStack_8 = 0;
    iVar1 = *(int *)(*(int *)(param_3 + 8) + 4 + iVar2 * 8);
    if (iVar1 != 0) {
      __CallSettingFrame_12(iVar1,param_1,0x103);
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  *unaff_FS_OFFSET = uStack_14;
  return;
}

// --------------------------------------------------

// Function: ___FrameUnwindToState
// Address: 0054fe90
void ___FrameUnwindToState(int param_1,undefined4 param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577aa8;
  uStack_10 = 0x554df8;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  for (iVar2 = *(int *)(param_1 + 8); local_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      _inconsistency();
    }
    local_8 = 0;
    iVar1 = *(int *)(*(int *)(param_3 + 8) + 4 + iVar2 * 8);
    if (iVar1 != 0) {
      __CallSettingFrame_12(iVar1,param_1,0x103);
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  *unaff_FS_OFFSET = local_14;
  return;
}

// --------------------------------------------------

// Function: FUN_0054ff06
// Address: 0054ff06
void FUN_0054ff06(void)
{
  int unaff_EBP;
  
  FUN_0054ff50(*(undefined4 *)(unaff_EBP + -0x14));
  return;
}

// --------------------------------------------------

// Function: FUN_0054ff13
// Address: 0054ff13
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_0054ff13(void)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  
  iVar2 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar3 = *(int *)(unaff_EBP + 0x10);
  iVar4 = *(int *)(unaff_EBP + 8);
  iVar5 = *(int *)(*(int *)(iVar3 + 8) + *(int *)(unaff_EBP + -0x1c) * 8);
  *(int *)(unaff_EBP + -0x1c) = iVar5;
  while (iVar5 != *(int *)(unaff_EBP + 0x14)) {
    if ((iVar5 < 0) || (*(int *)(iVar3 + 4) <= iVar5)) {
      *(undefined4 *)(iVar2 + -4) = 0x54fed6;
      _inconsistency();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar1 = *(int *)(*(int *)(iVar3 + 8) + 4 + iVar5 * 8);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar2 + -4) = 0x103;
      *(int *)(iVar2 + -8) = iVar4;
      *(int *)(iVar2 + -0xc) = iVar1;
      *(undefined4 *)(iVar2 + -0x10) = 0x54fef4;
      __CallSettingFrame_12();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar5 = *(int *)(*(int *)(iVar3 + 8) + iVar5 * 8);
    *(int *)(unaff_EBP + -0x1c) = iVar5;
  }
  *(int *)(iVar4 + 8) = iVar5;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_0054ff45
// Address: 0054ff45
undefined4 FUN_0054ff45(undefined4 *param_1)
{
  if (*(int *)*param_1 == -0x1f928c9d) {
    terminate();
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054ff50
// Address: 0054ff50
undefined4 FUN_0054ff50(undefined4 *param_1)
{
  if (*(int *)*param_1 == -0x1f928c9d) {
    terminate();
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054ff66
// Address: 0054ff66
void FUN_0054ff66(EHExceptionRecord *param_1,EHRegistrationNode *param_2,undefined4 param_3,
                 undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 *param_8,
                 undefined4 param_9,EHRegistrationNode *param_10)
{
  void *pvVar1;
  
  if (param_7 != 0) {
    FUN_00550180(param_1,param_2,param_6,param_7);
  }
  if (param_10 == (EHRegistrationNode *)0x0) {
    param_10 = param_2;
  }
  _UnwindNestedFrames(param_10,param_1);
  ___FrameUnwindToState(param_2,param_4,param_5,*param_8);
  *(int *)(param_2 + 8) = param_8[1] + 1;
  pvVar1 = (void *)FUN_00550000(param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),
                                param_9,0x100);
  if (pvVar1 != (void *)0x0) {
    _JumpToContinuation(pvVar1,param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054ff70
// Address: 0054ff70
void FUN_0054ff70(EHExceptionRecord *param_1,EHRegistrationNode *param_2,undefined4 param_3,
                 undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 *param_8,
                 undefined4 param_9,EHRegistrationNode *param_10)
{
  void *pvVar1;
  
  if (param_7 != 0) {
    FUN_00550180(param_1,param_2,param_6,param_7);
  }
  if (param_10 == (EHRegistrationNode *)0x0) {
    param_10 = param_2;
  }
  _UnwindNestedFrames(param_10,param_1);
  ___FrameUnwindToState(param_2,param_4,param_5,*param_8);
  *(int *)(param_2 + 8) = param_8[1] + 1;
  pvVar1 = (void *)FUN_00550000(param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),
                                param_9,0x100);
  if (pvVar1 != (void *)0x0) {
    _JumpToContinuation(pvVar1,param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054fff9
// Address: 0054fff9
void * FUN_0054fff9(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,
                   _s_FuncInfo *param_4,void *param_5,int param_6,ulong param_7)
{
  void *pvVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &DAT_00577ab8;
  uStack_10 = 0x554df8;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  _pCurrentException = param_1;
  _pCurrentExContext = param_3;
  uStack_8 = 1;
  pvVar1 = _CallCatchBlock2(param_2,param_4,param_5,param_6,param_7);
  uStack_8 = 0xffffffff;
  FUN_005500ea();
  *unaff_FS_OFFSET = uStack_14;
  return pvVar1;
}

// --------------------------------------------------

// Function: FUN_00550000
// Address: 00550000
void * FUN_00550000(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,
                   _s_FuncInfo *param_4,void *param_5,int param_6,ulong param_7)
{
  void *pvVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577ab8;
  uStack_10 = 0x554df8;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  _pCurrentException = param_1;
  _pCurrentExContext = param_3;
  local_8 = 1;
  pvVar1 = _CallCatchBlock2(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_005500ea();
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}

// --------------------------------------------------

// Function: FUN_005500a9
// Address: 005500a9
void FUN_005500a9(void)
{
  int unaff_EBP;
  
  FUN_00550150(*(undefined4 *)(unaff_EBP + -0x14));
  return;
}

// --------------------------------------------------

// Function: FUN_005500b6
// Address: 005500b6
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_005500b6(void)
{
  int iVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -4) = 0xffffffff;
  *(int *)(iVar1 + -8) = unaff_EBP + -0x10;
  *(undefined4 *)(iVar1 + -0xc) = 0x5500cb;
  __local_unwind2();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return 0;
}

// --------------------------------------------------

// Function: FUN_005500e1
// Address: 005500e1
void FUN_005500e1(void)
{
  EHExceptionRecord *pEVar1;
  int iVar2;
  uchar uVar3;
  int unaff_EBP;
  
  pEVar1 = *(EHExceptionRecord **)(unaff_EBP + 8);
  iVar2 = *(int *)(unaff_EBP + -0x2c);
  *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  _pCurrentException = *(EHExceptionRecord **)(unaff_EBP + -0x1c);
  _pCurrentExContext = *(_CONTEXT **)(unaff_EBP + -0x20);
  if ((((*(int *)pEVar1 == -0x1f928c9d) && (*(int *)(pEVar1 + 0x10) == 3)) &&
      (*(int *)(pEVar1 + 0x14) == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (iVar2 != 0)))) {
    uVar3 = __abnormal_termination();
    _DestructExceptionObject(pEVar1,uVar3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005500ea
// Address: 005500ea
void FUN_005500ea(void)
{
  uchar uVar1;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  EHExceptionRecord *unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  _pCurrentException = *(EHExceptionRecord **)(unaff_EBP + -0x1c);
  _pCurrentExContext = *(_CONTEXT **)(unaff_EBP + -0x20);
  if ((((*(int *)unaff_EDI == -0x1f928c9d) && (*(int *)(unaff_EDI + 0x10) == 3)) &&
      (*(int *)(unaff_EDI + 0x14) == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (unaff_EBX != 0)))) {
    uVar1 = __abnormal_termination();
    _DestructExceptionObject(unaff_EDI,uVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00550134
// Address: 00550134
void FUN_00550134(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_00550147
// Address: 00550147
undefined4 FUN_00550147(int *param_1)
{
  param_1 = (int *)*param_1;
  if ((((*param_1 == -0x1f928c9d) && (param_1[4] == 3)) && (param_1[5] == 0x19930520)) &&
     (param_1[7] == 0)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00550150
// Address: 00550150
undefined4 FUN_00550150(int *param_1)
{
  param_1 = (int *)*param_1;
  if ((((*param_1 == -0x1f928c9d) && (param_1[4] == 3)) && (param_1[5] == 0x19930520)) &&
     (param_1[7] == 0)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0055017d
// Address: 0055017d
void FUN_0055017d(int param_1,int param_2,byte *param_3,byte *param_4)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &DAT_00577ad0;
  uStack_10 = 0x554df8;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  if (((*(int *)(param_3 + 4) != 0) && (*(char *)(*(int *)(param_3 + 4) + 8) != '\0')) &&
     (*(int *)(param_3 + 8) != 0)) {
    piVar1 = (int *)(param_2 + 0xc + *(int *)(param_3 + 8));
    uStack_8 = 0;
    if ((*param_3 & 8) == 0) {
      if ((*param_4 & 1) == 0) {
        if (*(int *)(param_4 + 0x18) == 0) {
          iVar2 = _ValidateRead(*(void **)(param_1 + 0x18),1);
          if ((iVar2 != 0) && (iVar2 = _ValidateWrite(piVar1,1), iVar2 != 0)) {
            uVar3 = FUN_00550410(*(undefined4 *)(param_1 + 0x18),param_4 + 8,
                                 *(undefined4 *)(param_4 + 0x14));
            memmove(piVar1,uVar3);
            goto LAB_00550370;
          }
        }
        else {
          iVar2 = _ValidateRead(*(void **)(param_1 + 0x18),1);
          if (((iVar2 != 0) && (iVar2 = _ValidateWrite(piVar1,1), iVar2 != 0)) &&
             (iVar2 = _ValidateExecute(*(_func_int **)(param_4 + 0x18)), iVar2 != 0)) {
            if ((*param_4 & 4) == 0) {
              pvVar4 = (void *)FUN_00550410(*(undefined4 *)(param_1 + 0x18),param_4 + 8);
              _CallMemberFunction1(piVar1,*(void **)(param_4 + 0x18),pvVar4);
            }
            else {
              iVar2 = 1;
              pvVar4 = (void *)FUN_00550410(*(undefined4 *)(param_1 + 0x18),param_4 + 8);
              _CallMemberFunction2(piVar1,*(void **)(param_4 + 0x18),pvVar4,iVar2);
            }
            goto LAB_00550370;
          }
        }
      }
      else {
        iVar2 = _ValidateRead(*(void **)(param_1 + 0x18),1);
        if ((iVar2 != 0) && (iVar2 = _ValidateWrite(piVar1,1), iVar2 != 0)) {
          memmove(piVar1,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_4 + 0x14));
          if ((*(int *)(param_4 + 0x14) == 4) && (*piVar1 != 0)) {
            iVar2 = FUN_00550410(*piVar1,param_4 + 8);
            *piVar1 = iVar2;
          }
          goto LAB_00550370;
        }
      }
    }
    else {
      iVar2 = _ValidateRead(*(void **)(param_1 + 0x18),1);
      if ((iVar2 != 0) && (iVar2 = _ValidateWrite(piVar1,1), iVar2 != 0)) {
        iVar2 = *(int *)(param_1 + 0x18);
        *piVar1 = iVar2;
        iVar2 = FUN_00550410(iVar2,param_4 + 8);
        *piVar1 = iVar2;
        goto LAB_00550370;
      }
    }
    _inconsistency();
  }
LAB_00550370:
  *unaff_FS_OFFSET = uStack_14;
  return;
}

// --------------------------------------------------

// Function: FUN_00550180
// Address: 00550180
void FUN_00550180(int param_1,int param_2,byte *param_3,byte *param_4)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577ad0;
  uStack_10 = 0x554df8;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if (((*(int *)(param_3 + 4) != 0) && (*(char *)(*(int *)(param_3 + 4) + 8) != '\0')) &&
     (*(int *)(param_3 + 8) != 0)) {
    piVar1 = (int *)(param_2 + 0xc + *(int *)(param_3 + 8));
    local_8 = 0;
    if ((*param_3 & 8) == 0) {
      if ((*param_4 & 1) == 0) {
        if (*(int *)(param_4 + 0x18) == 0) {
          iVar2 = _ValidateRead(*(void **)(param_1 + 0x18),1);
          if ((iVar2 != 0) && (iVar2 = _ValidateWrite(piVar1,1), iVar2 != 0)) {
            uVar3 = FUN_00550410(*(undefined4 *)(param_1 + 0x18),param_4 + 8,
                                 *(undefined4 *)(param_4 + 0x14));
            memmove(piVar1,uVar3);
            goto LAB_00550370;
          }
        }
        else {
          iVar2 = _ValidateRead(*(void **)(param_1 + 0x18),1);
          if (((iVar2 != 0) && (iVar2 = _ValidateWrite(piVar1,1), iVar2 != 0)) &&
             (iVar2 = _ValidateExecute(*(_func_int **)(param_4 + 0x18)), iVar2 != 0)) {
            if ((*param_4 & 4) == 0) {
              pvVar4 = (void *)FUN_00550410(*(undefined4 *)(param_1 + 0x18),param_4 + 8);
              _CallMemberFunction1(piVar1,*(void **)(param_4 + 0x18),pvVar4);
            }
            else {
              iVar2 = 1;
              pvVar4 = (void *)FUN_00550410(*(undefined4 *)(param_1 + 0x18),param_4 + 8);
              _CallMemberFunction2(piVar1,*(void **)(param_4 + 0x18),pvVar4,iVar2);
            }
            goto LAB_00550370;
          }
        }
      }
      else {
        iVar2 = _ValidateRead(*(void **)(param_1 + 0x18),1);
        if ((iVar2 != 0) && (iVar2 = _ValidateWrite(piVar1,1), iVar2 != 0)) {
          memmove(piVar1,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_4 + 0x14));
          if ((*(int *)(param_4 + 0x14) == 4) && (*piVar1 != 0)) {
            iVar2 = FUN_00550410(*piVar1,param_4 + 8);
            *piVar1 = iVar2;
          }
          goto LAB_00550370;
        }
      }
    }
    else {
      iVar2 = _ValidateRead(*(void **)(param_1 + 0x18),1);
      if ((iVar2 != 0) && (iVar2 = _ValidateWrite(piVar1,1), iVar2 != 0)) {
        iVar2 = *(int *)(param_1 + 0x18);
        *piVar1 = iVar2;
        iVar2 = FUN_00550410(iVar2,param_4 + 8);
        *piVar1 = iVar2;
        goto LAB_00550370;
      }
    }
    _inconsistency();
  }
LAB_00550370:
  *unaff_FS_OFFSET = local_14;
  return;
}

// --------------------------------------------------

// Function: FUN_0055035b
// Address: 0055035b
undefined4 FUN_0055035b(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_00550361
// Address: 00550361
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00550361(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x550369;
  terminate();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_00550381
// Address: 00550381
void FUN_00550381(int param_1)
{
  void *pvVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &DAT_00577ae0;
  uStack_10 = 0x554df8;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  if ((param_1 != 0) && (pvVar1 = *(void **)(*(int *)(param_1 + 0x1c) + 4), pvVar1 != (void *)0x0))
{
    uStack_8 = 0;
    _CallMemberFunction0(*(void **)(param_1 + 0x18),pvVar1);
  }
  *unaff_FS_OFFSET = uStack_14;
  return;
}

// --------------------------------------------------

// Function: _DestructExceptionObject
// Address: 00550390
/* void __cdecl _DestructExceptionObject(struct EHExceptionRecord *,unsigned char) */

void __cdecl _DestructExceptionObject(EHExceptionRecord *param_1,uchar param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577ae0;
  uStack_10 = 0x554df8;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if ((param_1 != (EHExceptionRecord *)0x0) &&
     (*(void **)(*(int *)(param_1 + 0x1c) + 4) != (void *)0x0)) {
    local_8 = 0;
    _CallMemberFunction0(*(void **)(param_1 + 0x18),*(void **)(*(int *)(param_1 + 0x1c) + 4));
  }
  *unaff_FS_OFFSET = local_14;
  return;
}

// --------------------------------------------------

// Function: FUN_005503da
// Address: 005503da
bool FUN_005503da(void)
{
  int unaff_EBP;
  
  return *(char *)(unaff_EBP + 0xc) != '\0';
}

// --------------------------------------------------

// Function: FUN_005503e5
// Address: 005503e5
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_005503e5(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x5503ed;
  terminate();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_00550405
// Address: 00550405
int FUN_00550405(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + *param_2;
  iVar1 = param_2[1];
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(param_1 + iVar1) + param_2[2]) + iVar1;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_00550410
// Address: 00550410
int FUN_00550410(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + *param_2;
  iVar1 = param_2[1];
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(param_1 + iVar1) + param_2[2]) + iVar1;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_00550435
// Address: 00550435
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_00550435(undefined4 param_1,undefined4 param_2,int param_3)
{
  code *pcVar1;
  
  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}

// --------------------------------------------------

// Function: __CallSettingFrame@12
// Address: 00550440
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)
{
  code *pcVar1;
  
  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}

// --------------------------------------------------

// Function: terminate
// Address: 00550490
/* void __cdecl terminate(void) */

void __cdecl terminate(void)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577af0;
  uStack_10 = 0x554df8;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if (__pTerminate != (_func_void *)0x0) {
    local_8 = 1;
    (*__pTerminate)();
  }
  local_8 = 0xffffffff;
  FUN_005504fe();
  *unaff_FS_OFFSET = local_14;
  return;
}

// --------------------------------------------------

// Function: FUN_005504d1
// Address: 005504d1
undefined4 FUN_005504d1(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_005504d7
// Address: 005504d7
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_005504d7(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x5504ed;
  FUN_005504fe();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_005504fe
// Address: 005504fe
void FUN_005504fe(void)
{
  abort();
  return;
}

// --------------------------------------------------

// Function: FUN_00550504
// Address: 00550504
void FUN_00550504(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_00550515
// Address: 00550515
void FUN_00550515(void)
{
  if (__pUnexpected != (_func_void *)0x0) {
    (*__pUnexpected)();
  }
  terminate();
  return;
}

// --------------------------------------------------

// Function: unexpected
// Address: 00550520
/* void __cdecl unexpected(void) */

void __cdecl unexpected(void)
{
  if (__pUnexpected != (_func_void *)0x0) {
    (*__pUnexpected)();
  }
  terminate();
  return;
}

// --------------------------------------------------

// Function: _inconsistency
// Address: 00550530
/* void __cdecl _inconsistency(void) */

void __cdecl _inconsistency(void)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577b08;
  uStack_10 = 0x554df8;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if (__pInconsistency != (undefined *)0x0) {
    local_8 = 1;
    (*(code *)__pInconsistency)();
  }
  local_8 = 0xffffffff;
  FUN_0055059e();
  *unaff_FS_OFFSET = local_14;
  return;
}

// --------------------------------------------------

// Function: FUN_00550571
// Address: 00550571
undefined4 FUN_00550571(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_00550577
// Address: 00550577
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00550577(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x55058d;
  FUN_0055059e();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_0055059e
// Address: 0055059e
void FUN_0055059e(void)
{
  terminate();
  return;
}

// --------------------------------------------------

// Function: FUN_005505a4
// Address: 005505a4
void FUN_005505a4(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_005505b5
// Address: 005505b5
void FUN_005505b5(void)
{
  __controlfp(0x10000,0x30000);
  return;
}

// --------------------------------------------------

// Function: __setdefaultprecision
// Address: 005505c0
void __setdefaultprecision(void)
{
  __controlfp(0x10000,0x30000);
  return;
}

// --------------------------------------------------

// Function: FUN_005505d3
// Address: 005505d3
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005505d3(void)
{
  if (_DAT_00577b20 < 0.0) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: __ms_p5_test_fdiv
// Address: 005505e0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __ms_p5_test_fdiv(void)
{
  if (_DAT_00577b20 < 0.0) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: __ms_p5_mp_test_fdiv
// Address: 00550630
void __ms_p5_mp_test_fdiv(void)
{
  int iVar1;
  code *pcVar2;
  
  iVar1 = GetModuleHandleA("KERNEL32");
  if (iVar1 != 0) {
    pcVar2 = (code *)GetProcAddress(iVar1,"IsProcessorFeaturePresent");
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(0);
      return;
    }
  }
  __ms_p5_test_fdiv();
  return;
}

// --------------------------------------------------

// Function: FUN_00550659
// Address: 00550659
void FUN_00550659(char *param_1)
{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = tolower((int)*param_1);
  if (iVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (___mb_cur_max < 2) {
        uVar4 = (byte)__pctype[*param_1 * 2] & 4;
      }
      else {
        uVar4 = __isctype((int)*param_1,4);
      }
    } while (uVar4 != 0);
  }
  cVar2 = *param_1;
  *param_1 = ___decimal_point;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}

// --------------------------------------------------

// Function: __forcdecpt
// Address: 00550660
void __forcdecpt(char *param_1)
{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = tolower((int)*param_1);
  if (iVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (___mb_cur_max < 2) {
        uVar4 = (byte)__pctype[*param_1 * 2] & 4;
      }
      else {
        uVar4 = __isctype((int)*param_1,4);
      }
    } while (uVar4 != 0);
  }
  cVar2 = *param_1;
  *param_1 = ___decimal_point;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}

// --------------------------------------------------

// Function: FUN_005506bd
// Address: 005506bd
void FUN_005506bd(char *param_1)
{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  cVar1 = *param_1;
  while ((cVar1 != '\0' && (cVar1 != ___decimal_point))) {
    pcVar2 = param_1 + 1;
    param_1 = param_1 + 1;
    cVar1 = *pcVar2;
  }
  pcVar2 = param_1 + 1;
  if (*param_1 != '\0') {
    cVar1 = *pcVar2;
    while (((cVar1 != '\0' && (cVar1 != 'e')) && (cVar1 != 'E'))) {
      pcVar3 = pcVar2 + 1;
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar3;
    }
    cVar1 = pcVar2[-1];
    pcVar3 = pcVar2;
    while (pcVar4 = pcVar3 + -1, cVar1 == '0') {
      cVar1 = pcVar3[-2];
      pcVar3 = pcVar4;
    }
    if (*pcVar4 == ___decimal_point) {
      pcVar4 = pcVar3 + -2;
    }
    cVar1 = *pcVar2;
    pcVar4 = pcVar4 + 1;
    *pcVar4 = cVar1;
    while (cVar1 != '\0') {
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0055072b
// Address: 0055072b
undefined4 FUN_0055072b(double *param_1)
{
  if (UNK_00577b4d._3_8_ <= *param_1) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0055074c
// Address: 0055074c
void FUN_0055074c(int param_1,undefined4 *param_2,undefined4 param_3)
{
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 != 0) {
    __atodbl(&local_8,param_3);
    *param_2 = local_8;
    param_2[1] = local_4;
    return;
  }
  __atoflt(&param_3,param_3);
  *param_2 = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_005507a2
// Address: 005507a2
// [HELPER] s_e_000: "e+000"
undefined1 * FUN_005507a2(undefined4 *param_1,undefined1 *param_2,int param_3,int param_4)
{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  char *pcVar4;
  
  piVar1 = DAT_0088805c;
  if (DAT_00888060 == '\0') {
    piVar1 = (int *)__fltout(*param_1,param_1[1]);
    __fptostr(param_2 + (uint)(*piVar1 == 0x2d) + (uint)(0 < param_3),param_3 + 1,piVar1);
  }
  else {
    FUN_00550b70(param_2 + (*DAT_0088805c == 0x2d),0 < param_3);
  }
  puVar2 = param_2;
  if (*piVar1 == 0x2d) {
    *param_2 = 0x2d;
    puVar2 = param_2 + 1;
  }
  if (0 < param_3) {
    *puVar2 = puVar2[1];
    puVar2 = puVar2 + 1;
    *puVar2 = ___decimal_point;
  }
  pcVar4 = puVar2 + param_3 + (uint)(DAT_00888060 == '\0');
  *(undefined4 *)pcVar4 = s_e_000._0_4_;
  *(undefined2 *)(pcVar4 + 4) = s_e_000._4_2_;
  if (param_4 != 0) {
    *pcVar4 = 'E';
  }
  if (*(char *)piVar1[3] != '0') {
    iVar3 = piVar1[1] + -1;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
      pcVar4[1] = '-';
    }
    if (99 < iVar3) {
      pcVar4[2] = pcVar4[2] +
                  (((char)(iVar3 / 100) + (char)(iVar3 >> 0x1f)) -
                  (char)((longlong)iVar3 * 0x51eb851f >> 0x3f));
      iVar3 = iVar3 % 100;
    }
    if (9 < iVar3) {
      pcVar4[3] = pcVar4[3] +
                  (((char)(iVar3 / 10) + (char)(iVar3 >> 0x1f)) -
                  (char)((longlong)iVar3 * 0x66666667 >> 0x3f));
      iVar3 = iVar3 % 10;
    }
    pcVar4[4] = pcVar4[4] + (char)iVar3;
  }
  return param_2;
}

// --------------------------------------------------

// Function: __cftoe
// Address: 005507b0
// [HELPER] s_e_000: "e+000"
undefined1 * __cftoe(undefined4 *param_1,undefined1 *param_2,int param_3,int param_4)
{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  char *pcVar4;
  
  piVar1 = DAT_0088805c;
  if (DAT_00888060 == '\0') {
    piVar1 = (int *)__fltout(*param_1,param_1[1]);
    __fptostr(param_2 + (uint)(*piVar1 == 0x2d) + (uint)(0 < param_3),param_3 + 1,piVar1);
  }
  else {
    FUN_00550b70(param_2 + (*DAT_0088805c == 0x2d),0 < param_3);
  }
  puVar2 = param_2;
  if (*piVar1 == 0x2d) {
    *param_2 = 0x2d;
    puVar2 = param_2 + 1;
  }
  if (0 < param_3) {
    *puVar2 = puVar2[1];
    puVar2 = puVar2 + 1;
    *puVar2 = ___decimal_point;
  }
  pcVar4 = puVar2 + param_3 + (uint)(DAT_00888060 == '\0');
  *(undefined4 *)pcVar4 = s_e_000._0_4_;
  *(undefined2 *)(pcVar4 + 4) = s_e_000._4_2_;
  if (param_4 != 0) {
    *pcVar4 = 'E';
  }
  if (*(char *)piVar1[3] != '0') {
    iVar3 = piVar1[1] + -1;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
      pcVar4[1] = '-';
    }
    if (99 < iVar3) {
      pcVar4[2] = pcVar4[2] +
                  (((char)(iVar3 / 100) + (char)(iVar3 >> 0x1f)) -
                  (char)((longlong)iVar3 * 0x51eb851f >> 0x3f));
      iVar3 = iVar3 % 100;
    }
    if (9 < iVar3) {
      pcVar4[3] = pcVar4[3] +
                  (((char)(iVar3 / 10) + (char)(iVar3 >> 0x1f)) -
                  (char)((longlong)iVar3 * 0x66666667 >> 0x3f));
      iVar3 = iVar3 % 10;
    }
    pcVar4[4] = pcVar4[4] + (char)iVar3;
  }
  return param_2;
}

// --------------------------------------------------

// Function: FUN_005508ec
// Address: 005508ec
undefined1 * FUN_005508ec(undefined4 *param_1,undefined1 *param_2,uint param_3)
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  
  piVar2 = DAT_0088805c;
  if (DAT_00888060 == '\0') {
    piVar2 = (int *)__fltout(*param_1,param_1[1]);
    __fptostr(param_2 + (*piVar2 == 0x2d),piVar2[1] + param_3,piVar2);
  }
  else if (DAT_00888064 == param_3) {
    iVar1 = DAT_00888064 + (*DAT_0088805c == 0x2d);
    param_2[iVar1] = 0x30;
    (param_2 + iVar1)[1] = 0;
  }
  puVar4 = param_2;
  if (*piVar2 == 0x2d) {
    *param_2 = 0x2d;
    puVar4 = param_2 + 1;
  }
  if (piVar2[1] < 1) {
    FUN_00550b70(puVar4,1);
    *puVar4 = 0x30;
    puVar4 = puVar4 + 1;
  }
  else {
    puVar4 = puVar4 + piVar2[1];
  }
  if (0 < (int)param_3) {
    FUN_00550b70(puVar4,1);
    *puVar4 = ___decimal_point;
    iVar1 = piVar2[1];
    if (iVar1 < 0) {
      if ((DAT_00888060 != '\0') || (-iVar1 <= (int)param_3)) {
        param_3 = -iVar1;
      }
      FUN_00550b70(puVar4 + 1,param_3);
      puVar5 = (undefined4 *)(puVar4 + 1);
      for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = 0x30303030;
        puVar5 = puVar5 + 1;
      }
      for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
        *(undefined1 *)puVar5 = 0x30;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
    }
  }
  return param_2;
}

// --------------------------------------------------

// Function: __cftof
// Address: 005508f0
undefined1 * __cftof(undefined4 *param_1,undefined1 *param_2,uint param_3)
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  
  piVar2 = DAT_0088805c;
  if (DAT_00888060 == '\0') {
    piVar2 = (int *)__fltout(*param_1,param_1[1]);
    __fptostr(param_2 + (*piVar2 == 0x2d),piVar2[1] + param_3,piVar2);
  }
  else if (DAT_00888064 == param_3) {
    iVar1 = DAT_00888064 + (*DAT_0088805c == 0x2d);
    param_2[iVar1] = 0x30;
    (param_2 + iVar1)[1] = 0;
  }
  puVar4 = param_2;
  if (*piVar2 == 0x2d) {
    *param_2 = 0x2d;
    puVar4 = param_2 + 1;
  }
  if (piVar2[1] < 1) {
    FUN_00550b70(puVar4,1);
    *puVar4 = 0x30;
    puVar4 = puVar4 + 1;
  }
  else {
    puVar4 = puVar4 + piVar2[1];
  }
  if (0 < (int)param_3) {
    FUN_00550b70(puVar4,1);
    *puVar4 = ___decimal_point;
    iVar1 = piVar2[1];
    if (iVar1 < 0) {
      if ((DAT_00888060 != '\0') || (-iVar1 <= (int)param_3)) {
        param_3 = -iVar1;
      }
      FUN_00550b70(puVar4 + 1,param_3);
      puVar5 = (undefined4 *)(puVar4 + 1);
      for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = 0x30303030;
        puVar5 = puVar5 + 1;
      }
      for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
        *(undefined1 *)puVar5 = 0x30;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
    }
  }
  return param_2;
}

// --------------------------------------------------

// Function: FUN_005509e9
// Address: 005509e9
void FUN_005509e9(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)
{
  char cVar1;
  char *pcVar2;
  
  DAT_0088805c = (int *)__fltout(*param_1,param_1[1]);
  DAT_00888064 = DAT_0088805c[1] + -1;
  pcVar2 = (char *)((uint)(*DAT_0088805c == 0x2d) + param_2);
  __fptostr(pcVar2,param_3,DAT_0088805c);
  DAT_00888068._0_1_ = DAT_00888064 < DAT_0088805c[1] + -1;
  DAT_00888064 = DAT_0088805c[1] + -1;
  if ((-5 < DAT_00888064) && (DAT_00888064 < param_3)) {
    if ((bool)(undefined1)DAT_00888068) {
      cVar1 = *pcVar2;
      while (cVar1 != '\0') {
        cVar1 = pcVar2[1];
        pcVar2 = pcVar2 + 1;
      }
      pcVar2[-1] = '\0';
    }
    FUN_00550ad0(param_1,param_2,param_3);
    return;
  }
  FUN_00550aa0(param_1,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: __cftog
// Address: 005509f0
void __cftog(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)
{
  char cVar1;
  char *pcVar2;
  
  DAT_0088805c = (int *)__fltout(*param_1,param_1[1]);
  DAT_00888064 = DAT_0088805c[1] + -1;
  pcVar2 = (char *)((uint)(*DAT_0088805c == 0x2d) + param_2);
  __fptostr(pcVar2,param_3,DAT_0088805c);
  DAT_00888068._0_1_ = DAT_00888064 < DAT_0088805c[1] + -1;
  DAT_00888064 = DAT_0088805c[1] + -1;
  if ((-5 < DAT_00888064) && (DAT_00888064 < param_3)) {
    if ((bool)(undefined1)DAT_00888068) {
      cVar1 = *pcVar2;
      while (cVar1 != '\0') {
        cVar1 = pcVar2[1];
        pcVar2 = pcVar2 + 1;
      }
      pcVar2[-1] = '\0';
    }
    FUN_00550ad0(param_1,param_2,param_3);
    return;
  }
  FUN_00550aa0(param_1,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_00550a9e
// Address: 00550a9e
void FUN_00550a9e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  DAT_00888060 = 1;
  __cftoe(param_1,param_2,param_3,param_4);
  DAT_00888060 = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00550aa0
// Address: 00550aa0
void FUN_00550aa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  DAT_00888060 = 1;
  __cftoe(param_1,param_2,param_3,param_4);
  DAT_00888060 = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00550acb
// Address: 00550acb
void FUN_00550acb(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  DAT_00888060 = 1;
  __cftof(param_1,param_2,param_3);
  DAT_00888060 = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00550ad0
// Address: 00550ad0
void FUN_00550ad0(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  DAT_00888060 = 1;
  __cftof(param_1,param_2,param_3);
  DAT_00888060 = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00550af6
// Address: 00550af6
void FUN_00550af6(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5)
{
  if ((param_3 != 0x65) && (param_3 != 0x45)) {
    if (param_3 == 0x66) {
      __cftof(param_1,param_2,param_4);
      return;
    }
    __cftog(param_1,param_2,param_4,param_5);
    return;
  }
  __cftoe(param_1,param_2,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_00550b65
// Address: 00550b65
void FUN_00550b65(char *param_1,int param_2)
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_2 != 0) {
    uVar2 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    memmove(param_1 + param_2,param_1,~uVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00550b70
// Address: 00550b70
void FUN_00550b70(char *param_1,int param_2)
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_2 != 0) {
    uVar2 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    memmove(param_1 + param_2,param_1,~uVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00550b99
// Address: 00550b99
_func_int_uint * FUN_00550b99(_func_int_uint *param_1)
{
  _func_int_uint *p_Var1;
  
  p_Var1 = _pnhHeap;
  _pnhHeap = param_1;
  return p_Var1;
}

// --------------------------------------------------

// Function: _set_new_handler
// Address: 00550ba0
/* int (__cdecl*__cdecl _set_new_handler(int (__cdecl*)(unsigned int)))(unsigned int) */

_func_int_uint * __cdecl _set_new_handler(_func_int_uint *param_1)
{
  _func_int_uint *p_Var1;
  
  p_Var1 = _pnhHeap;
  _pnhHeap = param_1;
  return p_Var1;
}

// --------------------------------------------------

// Function: _query_new_handler
// Address: 00550bb0
/* int (__cdecl*__cdecl _query_new_handler(void))(unsigned int) */

_func_int_uint * __cdecl _query_new_handler(void)
{
  return _pnhHeap;
}

// --------------------------------------------------

// Function: FUN_00550bb6
// Address: 00550bb6
undefined4 FUN_00550bb6(uint param_1)
{
  int iVar1;
  
  if (_pnhHeap != (_func_int_uint *)0x0) {
    iVar1 = (*_pnhHeap)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: __callnewh
// Address: 00550bc0
undefined4 __callnewh(uint param_1)
{
  int iVar1;
  
  if (_pnhHeap != (_func_int_uint *)0x0) {
    iVar1 = (*_pnhHeap)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: __heap_init
// Address: 00550be0
undefined4 __heap_init(void)
{
  int iVar1;
  
  __crtheap = HeapCreate(1,0x1000,0);
  if (__crtheap == 0) {
    return 0;
  }
  iVar1 = ___sbh_new_region();
  if (iVar1 == 0) {
    HeapDestroy(__crtheap);
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00550c17
// Address: 00550c17
void FUN_00550c17(void)
{
  undefined **ppuVar1;
  
  ppuVar1 = &___small_block_heap;
  do {
    if (ppuVar1[4] != (undefined *)0x0) {
      VirtualFree(ppuVar1[4],0,0x8000);
    }
    ppuVar1 = (undefined **)*ppuVar1;
  } while (ppuVar1 != &___small_block_heap);
  HeapDestroy(__crtheap);
  return;
}

// --------------------------------------------------

// Function: FUN_00550c57
// Address: 00550c57
undefined4 FUN_00550c57(void)
{
  return ___sbh_threshold;
}

// --------------------------------------------------

// Function: FUN_00550c66
// Address: 00550c66
undefined4 FUN_00550c66(int param_1)
{
  uint uVar1;
  
  uVar1 = param_1 + 0xfU & 0xfffffff0;
  if (uVar1 < 0x781) {
    ___sbh_threshold = uVar1;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00550c8e
// Address: 00550c8e
undefined ** FUN_00550c8e(void)
{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  
  if (DAT_0058fbf8 == -1) {
    ppuVar5 = &___small_block_heap;
  }
  else {
    ppuVar5 = (undefined **)HeapAlloc(__crtheap,0,0x2020);
    if (ppuVar5 == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  puVar2 = (undefined4 *)VirtualAlloc(0,0x400000,0x2000,4);
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = VirtualAlloc(puVar2,0x10000,0x1000,4);
    if (iVar3 != 0) {
      if (ppuVar5 == &___small_block_heap) {
        if (___small_block_heap == (undefined *)0x0) {
          ___small_block_heap = (undefined *)&___small_block_heap;
        }
        if (PTR____small_block_heap_0058fbec == (undefined *)0x0) {
          PTR____small_block_heap_0058fbec = (undefined *)&___small_block_heap;
        }
      }
      else {
        *ppuVar5 = (undefined *)&___small_block_heap;
        ppuVar5[1] = PTR____small_block_heap_0058fbec;
        PTR____small_block_heap_0058fbec = (undefined *)ppuVar5;
        *(undefined ***)ppuVar5[1] = ppuVar5;
      }
      ppuVar5[5] = (undefined *)(puVar2 + 0x100000);
      ppuVar5[4] = (undefined *)puVar2;
      ppuVar5[2] = (undefined *)(ppuVar5 + 6);
      ppuVar5[3] = (undefined *)(ppuVar5 + 0x26);
      iVar3 = 0;
      ppuVar4 = ppuVar5 + 6;
      do {
        bVar1 = 0xf < iVar3;
        iVar3 = iVar3 + 1;
        *ppuVar4 = (undefined *)((bVar1 - 1 & 0xf1) - 1);
        ppuVar4[1] = (undefined *)0xf1;
        ppuVar4 = ppuVar4 + 2;
      } while (iVar3 < 0x400);
      puVar6 = puVar2;
      for (iVar3 = 0x4000; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      if (puVar2 < ppuVar5[4] + 0x10000) {
        do {
          puVar2[1] = 0xf0;
          *puVar2 = puVar2 + 2;
          *(undefined1 *)(puVar2 + 0x3e) = 0xff;
          puVar2 = puVar2 + 0x400;
        } while (puVar2 < ppuVar5[4] + 0x10000);
      }
      return ppuVar5;
    }
    VirtualFree(puVar2,0,0x8000);
  }
  if (ppuVar5 != &___small_block_heap) {
    HeapFree(__crtheap,0,ppuVar5);
  }
  return (undefined **)0x0;
}

// --------------------------------------------------

// Function: ___sbh_new_region
// Address: 00550c90
undefined ** ___sbh_new_region(void)
{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  
  if (DAT_0058fbf8 == -1) {
    ppuVar5 = &___small_block_heap;
  }
  else {
    ppuVar5 = (undefined **)HeapAlloc(__crtheap,0,0x2020);
    if (ppuVar5 == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  puVar2 = (undefined4 *)VirtualAlloc(0,0x400000,0x2000,4);
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = VirtualAlloc(puVar2,0x10000,0x1000,4);
    if (iVar3 != 0) {
      if (ppuVar5 == &___small_block_heap) {
        if (___small_block_heap == (undefined *)0x0) {
          ___small_block_heap = (undefined *)&___small_block_heap;
        }
        if (PTR____small_block_heap_0058fbec == (undefined *)0x0) {
          PTR____small_block_heap_0058fbec = (undefined *)&___small_block_heap;
        }
      }
      else {
        *ppuVar5 = (undefined *)&___small_block_heap;
        ppuVar5[1] = PTR____small_block_heap_0058fbec;
        PTR____small_block_heap_0058fbec = (undefined *)ppuVar5;
        *(undefined ***)ppuVar5[1] = ppuVar5;
      }
      ppuVar5[5] = (undefined *)(puVar2 + 0x100000);
      ppuVar5[4] = (undefined *)puVar2;
      ppuVar5[2] = (undefined *)(ppuVar5 + 6);
      ppuVar5[3] = (undefined *)(ppuVar5 + 0x26);
      iVar3 = 0;
      ppuVar4 = ppuVar5 + 6;
      do {
        bVar1 = 0xf < iVar3;
        iVar3 = iVar3 + 1;
        *ppuVar4 = (undefined *)((bVar1 - 1 & 0xf1) - 1);
        ppuVar4[1] = (undefined *)0xf1;
        ppuVar4 = ppuVar4 + 2;
      } while (iVar3 < 0x400);
      puVar6 = puVar2;
      for (iVar3 = 0x4000; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      if (puVar2 < ppuVar5[4] + 0x10000) {
        do {
          puVar2[1] = 0xf0;
          *puVar2 = puVar2 + 2;
          *(undefined1 *)(puVar2 + 0x3e) = 0xff;
          puVar2 = puVar2 + 0x400;
        } while (puVar2 < ppuVar5[4] + 0x10000);
      }
      return ppuVar5;
    }
    VirtualFree(puVar2,0,0x8000);
  }
  if (ppuVar5 != &___small_block_heap) {
    HeapFree(__crtheap,0,ppuVar5);
  }
  return (undefined **)0x0;
}

// --------------------------------------------------

// Function: FUN_00550df2
// Address: 00550df2
void FUN_00550df2(undefined **param_1)
{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR____small_block_heap_00591c08 == param_1) {
    PTR____small_block_heap_00591c08 = param_1[1];
  }
  if (param_1 != &___small_block_heap) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(__crtheap,0,param_1);
    return;
  }
  DAT_0058fbf8 = 0xffffffff;
  return;
}

// --------------------------------------------------

// Function: ___sbh_release_region
// Address: 00550e00
void ___sbh_release_region(undefined **param_1)
{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR____small_block_heap_00591c08 == param_1) {
    PTR____small_block_heap_00591c08 = param_1[1];
  }
  if (param_1 != &___small_block_heap) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(__crtheap,0,param_1);
    return;
  }
  DAT_0058fbf8 = 0xffffffff;
  return;
}

// --------------------------------------------------

// Function: FUN_00550e5b
// Address: 00550e5b
void FUN_00550e5b(int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  puVar5 = PTR____small_block_heap_0058fbec;
  do {
    puVar6 = puVar5;
    if (*(int *)(puVar5 + 0x10) != -1) {
      iVar4 = 0;
      piVar2 = (int *)(puVar5 + 0x2010);
      iVar3 = 0x3ff000;
      do {
        if (*piVar2 == 0xf0) {
          iVar1 = VirtualFree(*(int *)(puVar5 + 0x10) + iVar3,0x1000,0x4000);
          if (iVar1 != 0) {
            *piVar2 = -1;
            DAT_00888074 = DAT_00888074 + -1;
            if ((*(int **)(puVar5 + 0xc) == (int *)0x0) || (piVar2 < *(int **)(puVar5 + 0xc))) {
              *(int **)(puVar5 + 0xc) = piVar2;
            }
            iVar4 = iVar4 + 1;
            param_1 = param_1 + -1;
            if (param_1 == 0) break;
          }
        }
        iVar3 = iVar3 + -0x1000;
        piVar2 = piVar2 + -2;
      } while (-1 < iVar3);
      puVar6 = *(undefined **)(puVar5 + 4);
      if ((iVar4 != 0) && (*(int *)(puVar5 + 0x18) == -1)) {
        iVar3 = 1;
        piVar2 = (int *)(puVar5 + 0x20);
        do {
          if (*piVar2 != -1) break;
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 2;
        } while (iVar3 < 0x400);
        if (iVar3 == 0x400) {
          ___sbh_release_region(puVar5);
        }
      }
    }
    if ((puVar6 == PTR____small_block_heap_0058fbec) || (puVar5 = puVar6, param_1 < 1)) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: ___sbh_decommit_pages
// Address: 00550e60
void ___sbh_decommit_pages(int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  puVar5 = PTR____small_block_heap_0058fbec;
  do {
    puVar6 = puVar5;
    if (*(int *)(puVar5 + 0x10) != -1) {
      iVar4 = 0;
      piVar2 = (int *)(puVar5 + 0x2010);
      iVar3 = 0x3ff000;
      do {
        if (*piVar2 == 0xf0) {
          iVar1 = VirtualFree(*(int *)(puVar5 + 0x10) + iVar3,0x1000,0x4000);
          if (iVar1 != 0) {
            *piVar2 = -1;
            DAT_00888074 = DAT_00888074 + -1;
            if ((*(int **)(puVar5 + 0xc) == (int *)0x0) || (piVar2 < *(int **)(puVar5 + 0xc))) {
              *(int **)(puVar5 + 0xc) = piVar2;
            }
            iVar4 = iVar4 + 1;
            param_1 = param_1 + -1;
            if (param_1 == 0) break;
          }
        }
        iVar3 = iVar3 + -0x1000;
        piVar2 = piVar2 + -2;
      } while (-1 < iVar3);
      puVar6 = *(undefined **)(puVar5 + 4);
      if ((iVar4 != 0) && (*(int *)(puVar5 + 0x18) == -1)) {
        iVar3 = 1;
        piVar2 = (int *)(puVar5 + 0x20);
        do {
          if (*piVar2 != -1) break;
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 2;
        } while (iVar3 < 0x400);
        if (iVar3 == 0x400) {
          ___sbh_release_region(puVar5);
        }
      }
    }
    if ((puVar6 == PTR____small_block_heap_0058fbec) || (puVar5 = puVar6, param_1 < 1)) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00550f2d
// Address: 00550f2d
int FUN_00550f2d(undefined *param_1,undefined4 *param_2,uint *param_3)
{
  undefined **ppuVar1;
  uint uVar2;
  
  ppuVar1 = &___small_block_heap;
  while ((param_1 <= ppuVar1[4] || (ppuVar1[5] <= param_1))) {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &___small_block_heap) {
      return 0;
    }
  }
  if (((uint)param_1 & 0xf) != 0) {
    return 0;
  }
  if (((uint)param_1 & 0xfff) < 0x100) {
    return 0;
  }
  *param_2 = ppuVar1;
  uVar2 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar2;
  return ((int)(param_1 + (-0x100 - uVar2)) >> 4) + 8 + uVar2;
}

// --------------------------------------------------

// Function: ___sbh_find_block
// Address: 00550f30
int ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)
{
  undefined **ppuVar1;
  uint uVar2;
  
  ppuVar1 = &___small_block_heap;
  while ((param_1 <= ppuVar1[4] || (ppuVar1[5] <= param_1))) {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &___small_block_heap) {
      return 0;
    }
  }
  if (((uint)param_1 & 0xf) != 0) {
    return 0;
  }
  if (((uint)param_1 & 0xfff) < 0x100) {
    return 0;
  }
  *param_2 = ppuVar1;
  uVar2 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar2;
  return ((int)(param_1 + (-0x100 - uVar2)) >> 4) + 8 + uVar2;
}

// --------------------------------------------------

// Function: FUN_00550f89
// Address: 00550f89
void FUN_00550f89(int param_1,int param_2,byte *param_3)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_2 - *(int *)(param_1 + 0x10) >> 0xc;
  piVar1 = (int *)(param_1 + 0x18 + iVar2 * 8);
  *piVar1 = *(int *)(param_1 + 0x18 + iVar2 * 8) + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_00888074 = DAT_00888074 + 1, DAT_00888074 == 0x20)) {
    ___sbh_decommit_pages(0x10);
  }
  return;
}

// --------------------------------------------------

// Function: ___sbh_free_block
// Address: 00550f90
void ___sbh_free_block(int param_1,int param_2,byte *param_3)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_2 - *(int *)(param_1 + 0x10) >> 0xc;
  piVar1 = (int *)(param_1 + 0x18 + iVar2 * 8);
  *piVar1 = *(int *)(param_1 + 0x18 + iVar2 * 8) + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_00888074 = DAT_00888074 + 1, DAT_00888074 == 0x20)) {
    ___sbh_decommit_pages(0x10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00550fe3
// Address: 00550fe3
int * FUN_00550fe3(uint param_1)
{
  undefined **ppuVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined *puVar5;
  undefined **ppuVar6;
  undefined **unaff_EBP;
  undefined **ppuVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  int *piStack_4;
  
  piStack_4 = (int *)PTR____small_block_heap_00591c08;
  do {
    if (piStack_4[4] != -1) {
      piVar4 = (int *)piStack_4[2];
      iVar8 = ((int)piVar4 + (-0x18 - (int)piStack_4) >> 3) * 0x1000 + piStack_4[4];
      for (; piVar4 < piStack_4 + 0x806; piVar4 = piVar4 + 2) {
        if (((int)param_1 <= *piVar4) && (param_1 < (uint)piVar4[1])) {
          piVar2 = (int *)___sbh_alloc_block_from_page(iVar8,*piVar4,param_1);
          if (piVar2 != (int *)0x0) {
            PTR____small_block_heap_00591c08 = (undefined *)piStack_4;
            *piVar4 = *piVar4 - param_1;
            piStack_4[2] = (int)piVar4;
            return piVar2;
          }
          piVar4[1] = param_1;
        }
        iVar8 = iVar8 + 0x1000;
      }
      piVar2 = (int *)piStack_4[2];
      iVar8 = piStack_4[4];
      for (piVar4 = piStack_4 + 6; piVar4 < piVar2; piVar4 = piVar4 + 2) {
        if (((int)param_1 <= *piVar4) && (param_1 < (uint)piVar4[1])) {
          piVar3 = (int *)___sbh_alloc_block_from_page(iVar8,*piVar4,param_1);
          if (piVar3 != (int *)0x0) {
            PTR____small_block_heap_00591c08 = (undefined *)piStack_4;
            *piVar4 = *piVar4 - param_1;
            piStack_4[2] = (int)piVar4;
            return piVar3;
          }
          piVar4[1] = param_1;
        }
        iVar8 = iVar8 + 0x1000;
      }
    }
    piStack_4 = (int *)*piStack_4;
  } while (piStack_4 != (int *)PTR____small_block_heap_00591c08);
  ppuVar7 = &___small_block_heap;
  while ((ppuVar7[4] == (undefined *)0xffffffff || (ppuVar7[3] == (undefined *)0x0))) {
    ppuVar7 = (undefined **)*ppuVar7;
    if (ppuVar7 == &___small_block_heap) {
      puVar5 = (undefined *)___sbh_new_region();
      if (puVar5 == (undefined *)0x0) {
        return (int *)0x0;
      }
      piVar4 = *(int **)(puVar5 + 0x10);
      *(char *)(piVar4 + 2) = (char)param_1;
      PTR____small_block_heap_00591c08 = puVar5;
      *piVar4 = (int)piVar4 + param_1 + 8;
      piVar4[1] = 0xf0 - param_1;
      *(uint *)(puVar5 + 0x18) = *(int *)(puVar5 + 0x18) - (param_1 & 0xff);
      return piVar4 + 0x40;
    }
  }
  piVar4 = (int *)ppuVar7[3];
  iVar8 = *piVar4;
  piVar2 = (int *)(ppuVar7[4] + ((int)piVar4 + (-0x18 - (int)ppuVar7) >> 3) * 0x1000);
  for (iVar9 = 0; (iVar8 == -1 && (iVar9 < 0x10)); iVar9 = iVar9 + 1) {
    iVar8 = piVar4[2];
    piVar4 = piVar4 + 2;
  }
  piVar4 = (int *)VirtualAlloc(piVar2,iVar9 << 0xc,0x1000,4);
  if (piVar4 != piVar2) {
    return (int *)0x0;
  }
  ppuVar6 = unaff_EBP;
  if (0 < iVar9) {
    piVar4 = piVar2 + 1;
    do {
      *piVar4 = 0xf0;
      piVar4[-1] = (int)(piVar4 + 1);
      *(undefined1 *)(piVar4 + 0x3d) = 0xff;
      *ppuVar6 = (undefined *)0xf0;
      ppuVar6[1] = (undefined *)0xf1;
      piVar4 = piVar4 + 0x400;
      ppuVar6 = ppuVar6 + 2;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  ppuVar1 = ppuVar7 + 0x806;
  bVar10 = ppuVar6 < ppuVar1;
  if (bVar10) {
    do {
      if (*ppuVar6 == (undefined *)0xffffffff) break;
      ppuVar6 = ppuVar6 + 2;
    } while (ppuVar6 < ppuVar1);
    bVar10 = ppuVar6 < ppuVar1;
  }
  PTR____small_block_heap_00591c08 = (undefined *)ppuVar7;
  ppuVar7[3] = (undefined *)(-(uint)bVar10 & (uint)ppuVar6);
  *(char *)(piVar2 + 2) = (char)param_1;
  ppuVar7[2] = (undefined *)unaff_EBP;
  *unaff_EBP = *unaff_EBP + -param_1;
  piVar2[1] = piVar2[1] - param_1;
  *piVar2 = (int)piVar2 + param_1 + 8;
  return piVar2 + 0x40;
}

// --------------------------------------------------

// Function: ___sbh_alloc_block
// Address: 00550ff0
int * ___sbh_alloc_block(uint param_1)
{
  undefined **ppuVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined *puVar5;
  undefined **ppuVar6;
  undefined **unaff_EBP;
  undefined **ppuVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  int *local_4;
  
  local_4 = (int *)PTR____small_block_heap_00591c08;
  do {
    if (local_4[4] != -1) {
      piVar4 = (int *)local_4[2];
      iVar8 = ((int)piVar4 + (-0x18 - (int)local_4) >> 3) * 0x1000 + local_4[4];
      for (; piVar4 < local_4 + 0x806; piVar4 = piVar4 + 2) {
        if (((int)param_1 <= *piVar4) && (param_1 < (uint)piVar4[1])) {
          piVar2 = (int *)___sbh_alloc_block_from_page(iVar8,*piVar4,param_1);
          if (piVar2 != (int *)0x0) {
            PTR____small_block_heap_00591c08 = (undefined *)local_4;
            *piVar4 = *piVar4 - param_1;
            local_4[2] = (int)piVar4;
            return piVar2;
          }
          piVar4[1] = param_1;
        }
        iVar8 = iVar8 + 0x1000;
      }
      piVar2 = (int *)local_4[2];
      iVar8 = local_4[4];
      for (piVar4 = local_4 + 6; piVar4 < piVar2; piVar4 = piVar4 + 2) {
        if (((int)param_1 <= *piVar4) && (param_1 < (uint)piVar4[1])) {
          piVar3 = (int *)___sbh_alloc_block_from_page(iVar8,*piVar4,param_1);
          if (piVar3 != (int *)0x0) {
            PTR____small_block_heap_00591c08 = (undefined *)local_4;
            *piVar4 = *piVar4 - param_1;
            local_4[2] = (int)piVar4;
            return piVar3;
          }
          piVar4[1] = param_1;
        }
        iVar8 = iVar8 + 0x1000;
      }
    }
    local_4 = (int *)*local_4;
  } while (local_4 != (int *)PTR____small_block_heap_00591c08);
  ppuVar7 = &___small_block_heap;
  while ((ppuVar7[4] == (undefined *)0xffffffff || (ppuVar7[3] == (undefined *)0x0))) {
    ppuVar7 = (undefined **)*ppuVar7;
    if (ppuVar7 == &___small_block_heap) {
      puVar5 = (undefined *)___sbh_new_region();
      if (puVar5 == (undefined *)0x0) {
        return (int *)0x0;
      }
      piVar4 = *(int **)(puVar5 + 0x10);
      *(char *)(piVar4 + 2) = (char)param_1;
      PTR____small_block_heap_00591c08 = puVar5;
      *piVar4 = (int)piVar4 + param_1 + 8;
      piVar4[1] = 0xf0 - param_1;
      *(uint *)(puVar5 + 0x18) = *(int *)(puVar5 + 0x18) - (param_1 & 0xff);
      return piVar4 + 0x40;
    }
  }
  piVar4 = (int *)ppuVar7[3];
  iVar8 = *piVar4;
  piVar2 = (int *)(ppuVar7[4] + ((int)piVar4 + (-0x18 - (int)ppuVar7) >> 3) * 0x1000);
  for (iVar9 = 0; (iVar8 == -1 && (iVar9 < 0x10)); iVar9 = iVar9 + 1) {
    iVar8 = piVar4[2];
    piVar4 = piVar4 + 2;
  }
  piVar4 = (int *)VirtualAlloc(piVar2,iVar9 << 0xc,0x1000,4);
  if (piVar4 != piVar2) {
    return (int *)0x0;
  }
  ppuVar6 = unaff_EBP;
  if (0 < iVar9) {
    piVar4 = piVar2 + 1;
    do {
      *piVar4 = 0xf0;
      piVar4[-1] = (int)(piVar4 + 1);
      *(undefined1 *)(piVar4 + 0x3d) = 0xff;
      *ppuVar6 = (undefined *)0xf0;
      ppuVar6[1] = (undefined *)0xf1;
      piVar4 = piVar4 + 0x400;
      ppuVar6 = ppuVar6 + 2;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  ppuVar1 = ppuVar7 + 0x806;
  bVar10 = ppuVar6 < ppuVar1;
  if (bVar10) {
    do {
      if (*ppuVar6 == (undefined *)0xffffffff) break;
      ppuVar6 = ppuVar6 + 2;
    } while (ppuVar6 < ppuVar1);
    bVar10 = ppuVar6 < ppuVar1;
  }
  PTR____small_block_heap_00591c08 = (undefined *)ppuVar7;
  ppuVar7[3] = (undefined *)(-(uint)bVar10 & (uint)ppuVar6);
  *(char *)(piVar2 + 2) = (char)param_1;
  ppuVar7[2] = (undefined *)unaff_EBP;
  *unaff_EBP = *unaff_EBP + -param_1;
  piVar2[1] = piVar2[1] - param_1;
  *piVar2 = (int)piVar2 + param_1 + 8;
  return piVar2 + 0x40;
}

// --------------------------------------------------

// Function: FUN_00551223
// Address: 00551223
int FUN_00551223(int *param_1,uint param_2,uint param_3)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar2 = (byte *)*param_1;
  if (param_3 <= (uint)param_1[1]) {
    *pbVar2 = (byte)param_3;
    if (pbVar2 + param_3 < param_1 + 0x3e) {
      *param_1 = *param_1 + param_3;
      param_1[1] = param_1[1] - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    return (int)(pbVar2 + 8) * 0x10 + (int)param_1 * -0xf;
  }
  pbVar6 = pbVar2;
  if (pbVar2[param_1[1]] != 0) {
    pbVar6 = pbVar2 + param_1[1];
  }
  if (pbVar6 + param_3 < param_1 + 0x3e) {
    do {
      if (*pbVar6 == 0) {
        pbVar3 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = pbVar6[1];
        while (bVar1 == 0) {
          pbVar3 = pbVar3 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar3;
        }
        if (param_3 <= uVar5) {
          if (param_1 + 0x3e <= pbVar6 + param_3) {
            *param_1 = (int)(param_1 + 2);
            goto LAB_0055137f;
          }
          *param_1 = (int)(pbVar6 + param_3);
          param_1[1] = uVar5 - param_3;
          goto LAB_00551386;
        }
        if (pbVar6 == pbVar2) {
          param_1[1] = uVar5;
        }
        else {
          param_2 = param_2 - uVar5;
          if (param_2 < param_3) {
            return 0;
          }
        }
      }
      else {
        pbVar3 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar3;
    } while (pbVar3 + param_3 < param_1 + 0x3e);
  }
  pbVar3 = (byte *)(param_1 + 2);
  pbVar6 = pbVar3;
  if (pbVar3 < pbVar2) {
    while (pbVar6 + param_3 < param_1 + 0x3e) {
      if (*pbVar6 == 0) {
        pbVar4 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = pbVar6[1];
        while (bVar1 == 0) {
          pbVar4 = pbVar4 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar4;
        }
        if (param_3 <= uVar5) {
          if (pbVar6 + param_3 < param_1 + 0x3e) {
            *param_1 = (int)(pbVar6 + param_3);
            param_1[1] = uVar5 - param_3;
          }
          else {
            *param_1 = (int)pbVar3;
LAB_0055137f:
            param_1[1] = 0;
          }
LAB_00551386:
          *pbVar6 = (byte)param_3;
          return (int)(pbVar6 + 8) * 0x10 + (int)param_1 * -0xf;
        }
        param_2 = param_2 - uVar5;
        if (param_2 < param_3) {
          return 0;
        }
      }
      else {
        pbVar4 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar4;
      if (pbVar2 <= pbVar4) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: ___sbh_alloc_block_from_page
// Address: 00551230
int ___sbh_alloc_block_from_page(int *param_1,uint param_2,uint param_3)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar2 = (byte *)*param_1;
  if (param_3 <= (uint)param_1[1]) {
    *pbVar2 = (byte)param_3;
    if (pbVar2 + param_3 < param_1 + 0x3e) {
      *param_1 = *param_1 + param_3;
      param_1[1] = param_1[1] - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    return (int)(pbVar2 + 8) * 0x10 + (int)param_1 * -0xf;
  }
  pbVar6 = pbVar2;
  if (pbVar2[param_1[1]] != 0) {
    pbVar6 = pbVar2 + param_1[1];
  }
  if (pbVar6 + param_3 < param_1 + 0x3e) {
    do {
      if (*pbVar6 == 0) {
        pbVar3 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = pbVar6[1];
        while (bVar1 == 0) {
          pbVar3 = pbVar3 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar3;
        }
        if (param_3 <= uVar5) {
          if (param_1 + 0x3e <= pbVar6 + param_3) {
            *param_1 = (int)(param_1 + 2);
            goto LAB_0055137f;
          }
          *param_1 = (int)(pbVar6 + param_3);
          param_1[1] = uVar5 - param_3;
          goto LAB_00551386;
        }
        if (pbVar6 == pbVar2) {
          param_1[1] = uVar5;
        }
        else {
          param_2 = param_2 - uVar5;
          if (param_2 < param_3) {
            return 0;
          }
        }
      }
      else {
        pbVar3 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar3;
    } while (pbVar3 + param_3 < param_1 + 0x3e);
  }
  pbVar3 = (byte *)(param_1 + 2);
  pbVar6 = pbVar3;
  if (pbVar3 < pbVar2) {
    while (pbVar6 + param_3 < param_1 + 0x3e) {
      if (*pbVar6 == 0) {
        pbVar4 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = pbVar6[1];
        while (bVar1 == 0) {
          pbVar4 = pbVar4 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar4;
        }
        if (param_3 <= uVar5) {
          if (pbVar6 + param_3 < param_1 + 0x3e) {
            *param_1 = (int)(pbVar6 + param_3);
            param_1[1] = uVar5 - param_3;
          }
          else {
            *param_1 = (int)pbVar3;
LAB_0055137f:
            param_1[1] = 0;
          }
LAB_00551386:
          *pbVar6 = (byte)param_3;
          return (int)(pbVar6 + 8) * 0x10 + (int)param_1 * -0xf;
        }
        param_2 = param_2 - uVar5;
        if (param_2 < param_3) {
          return 0;
        }
      }
      else {
        pbVar4 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar4;
      if (pbVar2 <= pbVar4) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005513a2
// Address: 005513a2
undefined4 FUN_005513a2(int param_1,int *param_2,byte *param_3,uint param_4)
{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  
  uVar5 = 0;
  piVar3 = (int *)(param_1 + 0x18 + ((int)param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);
  uVar7 = (uint)*param_3;
  if (uVar7 <= param_4) {
    if ((uVar7 < param_4) && (pbVar1 = param_3 + param_4, pbVar1 <= param_2 + 0x3e)) {
      for (pbVar8 = param_3 + uVar7; (pbVar8 < pbVar1 && (*pbVar8 == 0)); pbVar8 = pbVar8 + 1) {
      }
      if (pbVar8 == pbVar1) {
        *param_3 = (byte)param_4;
        if ((param_3 <= (byte *)*param_2) && ((byte *)*param_2 < pbVar1)) {
          if (pbVar1 < param_2 + 0x3e) {
            *param_2 = (int)pbVar1;
            iVar6 = 0;
            bVar4 = *pbVar1;
            while (bVar4 == 0) {
              iVar2 = iVar6 + 1;
              iVar6 = iVar6 + 1;
              bVar4 = pbVar1[iVar2];
            }
            param_2[1] = iVar6;
          }
          else {
            param_2[1] = 0;
            *param_2 = (int)(param_2 + 2);
          }
        }
        *piVar3 = *piVar3 + (uVar7 - param_4);
        uVar5 = 1;
      }
    }
    return uVar5;
  }
  *param_3 = (byte)param_4;
  piVar3[1] = 0xf1;
  *piVar3 = *piVar3 + (uVar7 - param_4);
  return 1;
}

// --------------------------------------------------

// Function: ___sbh_resize_block
// Address: 005513b0
undefined4 ___sbh_resize_block(int param_1,int *param_2,byte *param_3,uint param_4)
{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  
  uVar5 = 0;
  piVar3 = (int *)(param_1 + 0x18 + ((int)param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);
  uVar7 = (uint)*param_3;
  if (uVar7 <= param_4) {
    if ((uVar7 < param_4) && (pbVar1 = param_3 + param_4, pbVar1 <= param_2 + 0x3e)) {
      for (pbVar8 = param_3 + uVar7; (pbVar8 < pbVar1 && (*pbVar8 == 0)); pbVar8 = pbVar8 + 1) {
      }
      if (pbVar8 == pbVar1) {
        *param_3 = (byte)param_4;
        if ((param_3 <= (byte *)*param_2) && ((byte *)*param_2 < pbVar1)) {
          if (pbVar1 < param_2 + 0x3e) {
            *param_2 = (int)pbVar1;
            iVar6 = 0;
            bVar4 = *pbVar1;
            while (bVar4 == 0) {
              iVar2 = iVar6 + 1;
              iVar6 = iVar6 + 1;
              bVar4 = pbVar1[iVar2];
            }
            param_2[1] = iVar6;
          }
          else {
            param_2[1] = 0;
            *param_2 = (int)(param_2 + 2);
          }
        }
        *piVar3 = *piVar3 + (uVar7 - param_4);
        uVar5 = 1;
      }
    }
    return uVar5;
  }
  *param_3 = (byte)param_4;
  piVar3[1] = 0xf1;
  *piVar3 = *piVar3 + (uVar7 - param_4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00551474
// Address: 00551474
int FUN_00551474(void)
{
  byte *pbVar1;
  undefined **ppuVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int local_1c;
  int local_18;
  undefined *local_14;
  undefined **local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_10 = &___small_block_heap;
  do {
    if ((undefined **)PTR____small_block_heap_00591c08 == local_10) {
      local_c = local_c + 1;
    }
    piVar6 = (int *)local_10[4];
    if (piVar6 != (int *)0xffffffff) {
      ppuVar2 = local_10 + 6;
      local_8 = 0;
      local_1c = 0;
      piVar7 = piVar6 + 2;
      do {
        iVar8 = 0;
        if (*ppuVar2 == (undefined *)0xffffffff) {
          if ((local_1c == 0) && ((undefined **)local_10[3] != ppuVar2)) {
            return -1;
          }
          local_1c = local_1c + 1;
        }
        else {
          if (piVar7 + 0x3c <= (int *)*piVar6) {
            return -2;
          }
          if ((char)piVar7[0x3c] != -1) {
            return -3;
          }
          iVar3 = 0;
          local_18 = 0;
          local_14 = (undefined *)0x0;
          iVar4 = 0;
          do {
            pbVar1 = (byte *)(iVar4 + (int)piVar7);
            if (pbVar1 == (byte *)*piVar6) {
              iVar3 = iVar3 + 1;
              local_18 = iVar3;
            }
            if (*pbVar1 == 0) {
              local_14 = local_14 + 1;
              iVar8 = iVar8 + 1;
              iVar5 = iVar4 + 1;
            }
            else {
              if ((int)ppuVar2[1] <= iVar8) {
                return -4;
              }
              if (iVar3 == 1) {
                if (iVar8 < piVar7[-1]) {
                  return -5;
                }
                local_18 = 2;
              }
              iVar5 = iVar4 + 1;
              iVar8 = 0;
              iVar3 = local_18;
              if (iVar5 < (int)(iVar4 + (uint)*pbVar1)) {
                do {
                  if (*(char *)(iVar5 + (int)piVar7) != '\0') {
                    return -6;
                  }
                  iVar5 = iVar5 + 1;
                } while (iVar5 < (int)((uint)*(byte *)(iVar4 + 8 + (int)piVar6) + iVar4));
              }
            }
            iVar4 = iVar5;
          } while (iVar5 < 0xf0);
          if (local_14 != *ppuVar2) {
            return -7;
          }
          if (iVar3 == 0) {
            return -8;
          }
        }
        ppuVar2 = ppuVar2 + 2;
        local_8 = local_8 + 1;
        piVar6 = piVar6 + 0x400;
        piVar7 = piVar7 + 0x400;
      } while (local_8 < 0x400);
    }
    local_10 = (undefined **)*local_10;
    if (local_10 == &___small_block_heap) {
      return (-(uint)(local_c != 0) & 9) - 9;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0055164e
// Address: 0055164e
undefined4 FUN_0055164e(undefined4 *param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = __isatty(param_1[4]);
  if (iVar2 != 0) {
    if (param_1 == (undefined4 *)&DAT_00591e68) {
      iVar2 = 0;
    }
    else {
      if (param_1 != (undefined4 *)&DAT_00591e88) {
        return 0;
      }
      iVar2 = 1;
    }
    __cflush = __cflush + 1;
    if ((param_1[3] & 0x10c) == 0) {
      if ((&__stdbuf)[iVar2] == 0) {
        iVar3 = malloc(0x1000);
        (&__stdbuf)[iVar2] = iVar3;
        if (iVar3 == 0) {
          return 0;
        }
      }
      uVar1 = (&__stdbuf)[iVar2];
      param_1[6] = 0x1000;
      param_1[2] = uVar1;
      *param_1 = uVar1;
      param_1[1] = 0x1000;
      param_1[3] = param_1[3] | 0x1102;
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: __stbuf
// Address: 00551650
undefined4 __stbuf(undefined4 *param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = __isatty(param_1[4]);
  if (iVar2 != 0) {
    if (param_1 == (undefined4 *)&DAT_00591e68) {
      iVar2 = 0;
    }
    else {
      if (param_1 != (undefined4 *)&DAT_00591e88) {
        return 0;
      }
      iVar2 = 1;
    }
    __cflush = __cflush + 1;
    if ((param_1[3] & 0x10c) == 0) {
      if ((&__stdbuf)[iVar2] == 0) {
        iVar3 = malloc(0x1000);
        (&__stdbuf)[iVar2] = iVar3;
        if (iVar3 == 0) {
          return 0;
        }
      }
      uVar1 = (&__stdbuf)[iVar2];
      param_1[6] = 0x1000;
      param_1[2] = uVar1;
      *param_1 = uVar1;
      param_1[1] = 0x1000;
      param_1[3] = param_1[3] | 0x1102;
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005516ef
// Address: 005516ef
void FUN_005516ef(int param_1,undefined4 *param_2)
{
  if (param_1 == 0) {
    if ((param_2[3] & 0x1000) != 0) {
      __flush(param_2);
    }
  }
  else if ((param_2[3] & 0x1000) != 0) {
    __flush(param_2);
    param_2[6] = 0;
    param_2[3] = param_2[3] & 0xffffeeff;
    *param_2 = 0;
    param_2[2] = 0;
    return;
  }
  return;
}

// --------------------------------------------------

// Function: __ftbuf
// Address: 005516f0
void __ftbuf(int param_1,undefined4 *param_2)
{
  if (param_1 == 0) {
    if ((param_2[3] & 0x1000) != 0) {
      __flush(param_2);
    }
  }
  else if ((param_2[3] & 0x1000) != 0) {
    __flush(param_2);
    param_2[6] = 0;
    param_2[3] = param_2[3] & 0xffffeeff;
    *param_2 = 0;
    param_2[2] = 0;
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00551744
// Address: 00551744
int FUN_00551744(undefined4 param_1,char *param_2,undefined4 *param_3)
{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  short *psVar5;
  int iVar6;
  char cVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  char *pcVar10;
  int iVar11;
  ulonglong uVar12;
  longlong lVar13;
  uint uStack_24c;
  short *psStack_248;
  int iStack_244;
  int iStack_240;
  undefined1 uStack_23a;
  char cStack_239;
  int iStack_238;
  int iStack_234;
  int iStack_230;
  int iStack_22c;
  int iStack_228;
  int iStack_224;
  int iStack_220;
  uint uStack_21c;
  undefined4 uStack_218;
  undefined1 auStack_214 [4];
  undefined4 uStack_210;
  undefined4 uStack_20c;
  int iStack_204;
  undefined1 auStack_200 [511];
  undefined1 uStack_1;
  
  iStack_220 = 0;
  puVar9 = (undefined1 *)0x0;
  iStack_240 = 0;
  cVar7 = *param_2;
  param_2 = param_2 + 1;
  uStack_21c = CONCAT31(uStack_21c._1_3_,cVar7);
  do {
    if ((cVar7 == '\0') || (iStack_240 < 0)) {
      return iStack_240;
    }
    if ((cVar7 < ' ') || ('x' < cVar7)) {
      uVar2 = 0;
    }
    else {
      uVar2 = (byte)"IsProcessorFeaturePresent"[cVar7 + 0x18] & 0xf;
    }
    iStack_220 = (int)(char)(&___lookuptable)[uVar2 * 8 + iStack_220] >> 4;
    switch(iStack_220) {
    case 0:
switchD_005517cd_caseD_0:
      iStack_230 = 0;
      if ((__pctype[(uStack_21c & 0xff) * 2 + 1] & 0x80) != 0) {
        FUN_005520e0((int)cVar7,param_1,&iStack_240);
        cVar7 = *param_2;
        param_2 = param_2 + 1;
      }
      FUN_005520e0((int)cVar7,param_1,&iStack_240);
      break;
    case 1:
      uStack_218 = 0;
      iStack_228 = 0;
      iStack_234 = 0;
      iStack_238 = 0;
      uStack_24c = 0;
      iStack_244 = -1;
      iStack_230 = 0;
      break;
    case 2:
      switch(cVar7) {
      case ' ':
        uStack_24c = uStack_24c | 2;
        break;
      case '#':
        uStack_24c = uStack_24c | 0x80;
        break;
      case '+':
        uStack_24c = uStack_24c | 1;
        break;
      case '-':
        uStack_24c = uStack_24c | 4;
        break;
      case '0':
        uStack_24c = uStack_24c | 8;
      }
      break;
    case 3:
      if (cVar7 == '*') {
        iStack_234 = FUN_005521b0(&param_3);
        if (iStack_234 < 0) {
          uStack_24c = uStack_24c | 4;
          iStack_234 = -iStack_234;
        }
      }
      else {
        iStack_234 = cVar7 + -0x30 + iStack_234 * 10;
      }
      break;
    case 4:
      iStack_244 = 0;
      break;
    case 5:
      if (cVar7 == '*') {
        iStack_244 = FUN_005521b0(&param_3);
        if (iStack_244 < 0) {
          iStack_244 = -1;
        }
      }
      else {
        iStack_244 = cVar7 + -0x30 + iStack_244 * 10;
      }
      break;
    case 6:
      switch(cVar7) {
      case 'I':
        if ((*param_2 != '6') || (param_2[1] != '4')) {
          iStack_220 = 0;
          goto switchD_005517cd_caseD_0;
        }
        param_2 = param_2 + 2;
        uStack_24c = uStack_24c | 0x8000;
        break;
      case 'h':
        uStack_24c = uStack_24c | 0x20;
        break;
      case 'l':
        uStack_24c = uStack_24c | 0x10;
        break;
      case 'w':
        uStack_24c = uStack_24c | 0x800;
      }
      break;
    case 7:
      switch(cVar7) {
      case 'C':
        if ((uStack_24c & 0x830) == 0) {
          uStack_24c = uStack_24c | 0x800;
        }
      case 'c':
        if ((uStack_24c & 0x810) == 0) {
          auStack_200[0] = FUN_005521b0(&param_3);
          puVar9 = (undefined1 *)0x1;
        }
        else {
          uVar3 = FUN_005521f0(&param_3);
          puVar9 = (undefined1 *)wctomb(auStack_200,uVar3);
          if ((int)puVar9 < 0) {
            psStack_248 = (short *)auStack_200;
            iStack_228 = 1;
            break;
          }
        }
        psStack_248 = (short *)auStack_200;
        break;
      case 'E':
      case 'G':
        uStack_218 = 1;
        cVar7 = cVar7 + ' ';
      case 'e':
      case 'f':
      case 'g':
        psStack_248 = (short *)auStack_200;
        if (iStack_244 < 0) {
          iStack_244 = 6;
        }
        else if ((iStack_244 == 0) && (cVar7 == 'g')) {
          iStack_244 = 1;
        }
        uStack_210 = *param_3;
        uStack_20c = param_3[1];
        param_3 = param_3 + 2;
        (*(code *)__cfltcvt_tab)(&uStack_210,auStack_200,(int)cVar7,iStack_244,uStack_218);
        if (((uStack_24c & 0x80) != 0) && (iStack_244 == 0)) {
          (*(code *)PTR___fptrap_0058fbd4)(auStack_200);
        }
        if ((cVar7 == 'g') && ((uStack_24c & 0x80) == 0)) {
          (*(code *)PTR___fptrap_0058fbcc)(auStack_200);
        }
        uVar2 = uStack_24c | 0x40;
        if (auStack_200[0] == '-') {
          psStack_248 = (short *)(auStack_200 + 1);
          uVar2 = uStack_24c | 0x140;
        }
        uStack_24c = uVar2;
        uVar2 = 0xffffffff;
        psVar5 = psStack_248;
        do {
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          sVar1 = *psVar5;
          psVar5 = (short *)((int)psVar5 + 1);
        } while ((char)sVar1 != '\0');
        puVar9 = (undefined1 *)(~uVar2 - 1);
        break;
      case 'S':
        if ((uStack_24c & 0x830) == 0) {
          uStack_24c = uStack_24c | 0x800;
        }
      case 's':
        iVar11 = 0x7fffffff;
        if (iStack_244 != -1) {
          iVar11 = iStack_244;
        }
        psStack_248 = (short *)FUN_005521b0(&param_3);
        if ((uStack_24c & 0x810) == 0) {
          psVar5 = psStack_248;
          if (psStack_248 == (short *)0x0) {
            psVar5 = (short *)___nullstring;
            psStack_248 = (short *)___nullstring;
          }
          for (; (iVar11 != 0 && (iVar11 = iVar11 + -1, (char)*psVar5 != '\0'));
              psVar5 = (short *)((int)psVar5 + 1)) {
          }
          puVar9 = (undefined1 *)((int)psVar5 - (int)psStack_248);
        }
        else {
          if (psStack_248 == (short *)0x0) {
            psStack_248 = (short *)___wnullstring;
          }
          iStack_230 = 1;
          for (psVar5 = psStack_248; (iVar11 != 0 && (iVar11 = iVar11 + -1, *psVar5 != 0));
              psVar5 = psVar5 + 1) {
          }
          puVar9 = (undefined1 *)((int)psVar5 - (int)psStack_248 >> 1);
        }
        break;
      case 'X':
        goto switchD_005519e1_caseD_58;
      case 'Z':
        psVar5 = (short *)FUN_005521b0(&param_3);
        if ((psVar5 == (short *)0x0) ||
           (psStack_248 = *(short **)(psVar5 + 2), psStack_248 == (short *)0x0)) {
          uVar2 = 0xffffffff;
          psStack_248 = (short *)___nullstring;
          pcVar10 = ___nullstring;
          do {
            if (uVar2 == 0) break;
            uVar2 = uVar2 - 1;
            cVar7 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar7 != '\0');
          puVar9 = (undefined1 *)(~uVar2 - 1);
        }
        else if ((uStack_24c & 0x800) == 0) {
          puVar9 = (undefined1 *)(int)*psVar5;
          iStack_230 = 0;
        }
        else {
          iStack_230 = 1;
          puVar9 = (undefined1 *)((uint)(int)*psVar5 >> 1);
        }
        break;
      case 'd':
      case 'i':
        iStack_22c = 10;
        uStack_24c = uStack_24c | 0x40;
        goto LAB_00551d17;
      case 'n':
        piVar4 = (int *)FUN_005521b0(&param_3);
        if ((uStack_24c & 0x20) == 0) {
          iStack_228 = 1;
          *piVar4 = iStack_240;
        }
        else {
          iStack_228 = 1;
          *(undefined2 *)piVar4 = (undefined2)iStack_240;
        }
        break;
      case 'o':
        iStack_22c = 8;
        if ((uStack_24c & 0x80) != 0) {
          uStack_24c = uStack_24c | 0x200;
        }
        goto LAB_00551d17;
      case 'p':
        iStack_244 = 8;
switchD_005519e1_caseD_58:
        iStack_224 = 7;
LAB_00551cd2:
        iStack_22c = 0x10;
        if ((uStack_24c & 0x80) != 0) {
          uStack_23a = 0x30;
          cStack_239 = (char)iStack_224 + 'Q';
          iStack_238 = 2;
        }
        goto LAB_00551d17;
      case 'u':
        iStack_22c = 10;
LAB_00551d17:
        if ((uStack_24c & 0x8000) == 0) {
          if ((uStack_24c & 0x20) == 0) {
            if ((uStack_24c & 0x40) == 0) {
              uVar2 = FUN_005521b0(&param_3);
              uVar12 = (ulonglong)uVar2;
            }
            else {
              iVar11 = FUN_005521b0(&param_3);
              uVar12 = (ulonglong)iVar11;
            }
          }
          else if ((uStack_24c & 0x40) == 0) {
            uVar2 = FUN_005521b0(&param_3);
            uVar12 = (ulonglong)(uVar2 & 0xffff);
          }
          else {
            sVar1 = FUN_005521b0(&param_3);
            uVar12 = (ulonglong)(int)sVar1;
          }
        }
        else {
          uVar12 = FUN_005521d0(&param_3);
        }
        if ((((uStack_24c & 0x40) != 0) && ((longlong)uVar12 < 0x100000000)) &&
           ((longlong)uVar12 < 0)) {
          uVar12 = CONCAT44(-((int)(uVar12 >> 0x20) + (uint)((int)uVar12 != 0)),-(int)uVar12);
          uStack_24c = uStack_24c | 0x100;
        }
        iVar11 = (int)(uVar12 >> 0x20);
        if ((uStack_24c & 0x8000) == 0) {
          iVar11 = 0;
        }
        lVar13 = CONCAT44(iVar11,(int)uVar12);
        if (iStack_244 < 0) {
          iStack_244 = 1;
        }
        else {
          uStack_24c = uStack_24c & 0xfffffff7;
        }
        if ((int)uVar12 == 0 && iVar11 == 0) {
          iStack_238 = 0;
        }
        psVar5 = (short *)&uStack_1;
        iVar11 = iStack_244;
        while ((iVar6 = iStack_22c, iStack_244 = iVar11 + -1, 0 < iVar11 || (lVar13 != 0))) {
          iStack_204 = iStack_22c >> 0x1f;
          iVar11 = __aullrem(lVar13,iStack_22c,iStack_204);
          iVar11 = iVar11 + 0x30;
          lVar13 = __aulldiv(lVar13,iVar6,iStack_204);
          if (0x39 < iVar11) {
            iVar11 = iVar11 + iStack_224;
          }
          *(char *)psVar5 = (char)iVar11;
          psVar5 = (short *)((int)psVar5 + -1);
          iVar11 = iStack_244;
        }
        puVar9 = &uStack_1 + -(int)psVar5;
        psStack_248 = (short *)((int)psVar5 + 1);
        if (((uStack_24c & 0x200) != 0) &&
           ((*(char *)psStack_248 != '0' || (puVar9 == (undefined1 *)0x0)))) {
          puVar9 = &stack0x00000000 + -(int)psVar5;
          *(char *)psVar5 = '0';
          psStack_248 = psVar5;
        }
        break;
      case 'x':
        iStack_224 = 0x27;
        goto LAB_00551cd2;
      }
      if (iStack_228 == 0) {
        if ((uStack_24c & 0x40) != 0) {
          if ((uStack_24c & 0x100) == 0) {
            if ((uStack_24c & 1) == 0) {
              if ((uStack_24c & 2) == 0) goto LAB_00551eaf;
              uStack_23a = 0x20;
            }
            else {
              uStack_23a = 0x2b;
            }
          }
          else {
            uStack_23a = 0x2d;
          }
          iStack_238 = 1;
        }
LAB_00551eaf:
        iVar11 = (iStack_234 - iStack_238) - (int)puVar9;
        if ((uStack_24c & 0xc) == 0) {
          FUN_00552130(0x20,iVar11,param_1,&iStack_240);
        }
        FUN_00552170(&uStack_23a,iStack_238,param_1,&iStack_240);
        if (((uStack_24c & 8) != 0) && ((uStack_24c & 4) == 0)) {
          FUN_00552130(0x30,iVar11,param_1,&iStack_240);
        }
        if ((iStack_230 == 0) || (psVar5 = psStack_248, puVar8 = puVar9, (int)puVar9 < 1)) {
          FUN_00552170(psStack_248,puVar9,param_1,&iStack_240);
        }
        else {
          do {
            puVar8 = puVar8 + -1;
            iVar6 = wctomb(auStack_214,*psVar5);
            if (iVar6 < 1) break;
            FUN_00552170(auStack_214,iVar6,param_1,&iStack_240);
            psVar5 = psVar5 + 1;
          } while (puVar8 != (undefined1 *)0x0);
        }
        if ((uStack_24c & 4) != 0) {
          FUN_00552130(0x20,iVar11,param_1,&iStack_240);
        }
      }
    }
    cVar7 = *param_2;
    param_2 = param_2 + 1;
    uStack_21c = CONCAT31(uStack_21c._1_3_,cVar7);
  } while( true );
}

// --------------------------------------------------

// Function: __output
// Address: 00551750
int __output(undefined4 param_1,char *param_2,undefined4 *param_3)
{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  short *psVar5;
  int iVar6;
  char cVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  char *pcVar10;
  int iVar11;
  ulonglong uVar12;
  longlong lVar13;
  uint local_24c;
  short *local_248;
  int local_244;
  int local_240;
  undefined1 local_23a;
  char local_239;
  int local_238;
  int local_234;
  int local_230;
  int local_22c;
  int local_228;
  int local_224;
  int local_220;
  uint local_21c;
  undefined4 local_218;
  undefined1 local_214 [4];
  undefined4 local_210;
  undefined4 local_20c;
  int local_204;
  undefined1 local_200 [511];
  undefined1 uStack_1;
  
  local_220 = 0;
  puVar9 = (undefined1 *)0x0;
  local_240 = 0;
  cVar7 = *param_2;
  param_2 = param_2 + 1;
  local_21c = CONCAT31(local_21c._1_3_,cVar7);
  do {
    if ((cVar7 == '\0') || (local_240 < 0)) {
      return local_240;
    }
    if ((cVar7 < ' ') || ('x' < cVar7)) {
      uVar2 = 0;
    }
    else {
      uVar2 = (byte)"IsProcessorFeaturePresent"[cVar7 + 0x18] & 0xf;
    }
    local_220 = (int)(char)(&___lookuptable)[uVar2 * 8 + local_220] >> 4;
    switch(local_220) {
    case 0:
switchD_005517cd_caseD_0:
      local_230 = 0;
      if ((__pctype[(local_21c & 0xff) * 2 + 1] & 0x80) != 0) {
        FUN_005520e0((int)cVar7,param_1,&local_240);
        cVar7 = *param_2;
        param_2 = param_2 + 1;
      }
      FUN_005520e0((int)cVar7,param_1,&local_240);
      break;
    case 1:
      local_218 = 0;
      local_228 = 0;
      local_234 = 0;
      local_238 = 0;
      local_24c = 0;
      local_244 = -1;
      local_230 = 0;
      break;
    case 2:
      switch(cVar7) {
      case ' ':
        local_24c = local_24c | 2;
        break;
      case '#':
        local_24c = local_24c | 0x80;
        break;
      case '+':
        local_24c = local_24c | 1;
        break;
      case '-':
        local_24c = local_24c | 4;
        break;
      case '0':
        local_24c = local_24c | 8;
      }
      break;
    case 3:
      if (cVar7 == '*') {
        local_234 = FUN_005521b0(&param_3);
        if (local_234 < 0) {
          local_24c = local_24c | 4;
          local_234 = -local_234;
        }
      }
      else {
        local_234 = cVar7 + -0x30 + local_234 * 10;
      }
      break;
    case 4:
      local_244 = 0;
      break;
    case 5:
      if (cVar7 == '*') {
        local_244 = FUN_005521b0(&param_3);
        if (local_244 < 0) {
          local_244 = -1;
        }
      }
      else {
        local_244 = cVar7 + -0x30 + local_244 * 10;
      }
      break;
    case 6:
      switch(cVar7) {
      case 'I':
        if ((*param_2 != '6') || (param_2[1] != '4')) {
          local_220 = 0;
          goto switchD_005517cd_caseD_0;
        }
        param_2 = param_2 + 2;
        local_24c = local_24c | 0x8000;
        break;
      case 'h':
        local_24c = local_24c | 0x20;
        break;
      case 'l':
        local_24c = local_24c | 0x10;
        break;
      case 'w':
        local_24c = local_24c | 0x800;
      }
      break;
    case 7:
      switch(cVar7) {
      case 'C':
        if ((local_24c & 0x830) == 0) {
          local_24c = local_24c | 0x800;
        }
      case 'c':
        if ((local_24c & 0x810) == 0) {
          local_200[0] = FUN_005521b0(&param_3);
          puVar9 = (undefined1 *)0x1;
        }
        else {
          uVar3 = FUN_005521f0(&param_3);
          puVar9 = (undefined1 *)wctomb(local_200,uVar3);
          if ((int)puVar9 < 0) {
            local_248 = (short *)local_200;
            local_228 = 1;
            break;
          }
        }
        local_248 = (short *)local_200;
        break;
      case 'E':
      case 'G':
        local_218 = 1;
        cVar7 = cVar7 + ' ';
      case 'e':
      case 'f':
      case 'g':
        local_248 = (short *)local_200;
        if (local_244 < 0) {
          local_244 = 6;
        }
        else if ((local_244 == 0) && (cVar7 == 'g')) {
          local_244 = 1;
        }
        local_210 = *param_3;
        local_20c = param_3[1];
        param_3 = param_3 + 2;
        (*(code *)__cfltcvt_tab)(&local_210,local_200,(int)cVar7,local_244,local_218);
        if (((local_24c & 0x80) != 0) && (local_244 == 0)) {
          (*(code *)PTR___fptrap_0058fbd4)(local_200);
        }
        if ((cVar7 == 'g') && ((local_24c & 0x80) == 0)) {
          (*(code *)PTR___fptrap_0058fbcc)(local_200);
        }
        uVar2 = local_24c | 0x40;
        if (local_200[0] == '-') {
          local_248 = (short *)(local_200 + 1);
          uVar2 = local_24c | 0x140;
        }
        local_24c = uVar2;
        uVar2 = 0xffffffff;
        psVar5 = local_248;
        do {
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          sVar1 = *psVar5;
          psVar5 = (short *)((int)psVar5 + 1);
        } while ((char)sVar1 != '\0');
        puVar9 = (undefined1 *)(~uVar2 - 1);
        break;
      case 'S':
        if ((local_24c & 0x830) == 0) {
          local_24c = local_24c | 0x800;
        }
      case 's':
        iVar11 = 0x7fffffff;
        if (local_244 != -1) {
          iVar11 = local_244;
        }
        local_248 = (short *)FUN_005521b0(&param_3);
        if ((local_24c & 0x810) == 0) {
          psVar5 = local_248;
          if (local_248 == (short *)0x0) {
            psVar5 = (short *)___nullstring;
            local_248 = (short *)___nullstring;
          }
          for (; (iVar11 != 0 && (iVar11 = iVar11 + -1, (char)*psVar5 != '\0'));
              psVar5 = (short *)((int)psVar5 + 1)) {
          }
          puVar9 = (undefined1 *)((int)psVar5 - (int)local_248);
        }
        else {
          if (local_248 == (short *)0x0) {
            local_248 = (short *)___wnullstring;
          }
          local_230 = 1;
          for (psVar5 = local_248; (iVar11 != 0 && (iVar11 = iVar11 + -1, *psVar5 != 0));
              psVar5 = psVar5 + 1) {
          }
          puVar9 = (undefined1 *)((int)psVar5 - (int)local_248 >> 1);
        }
        break;
      case 'X':
        goto switchD_005519e1_caseD_58;
      case 'Z':
        psVar5 = (short *)FUN_005521b0(&param_3);
        if ((psVar5 == (short *)0x0) ||
           (local_248 = *(short **)(psVar5 + 2), local_248 == (short *)0x0)) {
          uVar2 = 0xffffffff;
          local_248 = (short *)___nullstring;
          pcVar10 = ___nullstring;
          do {
            if (uVar2 == 0) break;
            uVar2 = uVar2 - 1;
            cVar7 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar7 != '\0');
          puVar9 = (undefined1 *)(~uVar2 - 1);
        }
        else if ((local_24c & 0x800) == 0) {
          puVar9 = (undefined1 *)(int)*psVar5;
          local_230 = 0;
        }
        else {
          local_230 = 1;
          puVar9 = (undefined1 *)((uint)(int)*psVar5 >> 1);
        }
        break;
      case 'd':
      case 'i':
        local_22c = 10;
        local_24c = local_24c | 0x40;
        goto LAB_00551d17;
      case 'n':
        piVar4 = (int *)FUN_005521b0(&param_3);
        if ((local_24c & 0x20) == 0) {
          local_228 = 1;
          *piVar4 = local_240;
        }
        else {
          local_228 = 1;
          *(undefined2 *)piVar4 = (undefined2)local_240;
        }
        break;
      case 'o':
        local_22c = 8;
        if ((local_24c & 0x80) != 0) {
          local_24c = local_24c | 0x200;
        }
        goto LAB_00551d17;
      case 'p':
        local_244 = 8;
switchD_005519e1_caseD_58:
        local_224 = 7;
LAB_00551cd2:
        local_22c = 0x10;
        if ((local_24c & 0x80) != 0) {
          local_23a = 0x30;
          local_239 = (char)local_224 + 'Q';
          local_238 = 2;
        }
        goto LAB_00551d17;
      case 'u':
        local_22c = 10;
LAB_00551d17:
        if ((local_24c & 0x8000) == 0) {
          if ((local_24c & 0x20) == 0) {
            if ((local_24c & 0x40) == 0) {
              uVar2 = FUN_005521b0(&param_3);
              uVar12 = (ulonglong)uVar2;
            }
            else {
              iVar11 = FUN_005521b0(&param_3);
              uVar12 = (ulonglong)iVar11;
            }
          }
          else if ((local_24c & 0x40) == 0) {
            uVar2 = FUN_005521b0(&param_3);
            uVar12 = (ulonglong)(uVar2 & 0xffff);
          }
          else {
            sVar1 = FUN_005521b0(&param_3);
            uVar12 = (ulonglong)(int)sVar1;
          }
        }
        else {
          uVar12 = FUN_005521d0(&param_3);
        }
        if ((((local_24c & 0x40) != 0) && ((longlong)uVar12 < 0x100000000)) &&
           ((longlong)uVar12 < 0)) {
          uVar12 = CONCAT44(-((int)(uVar12 >> 0x20) + (uint)((int)uVar12 != 0)),-(int)uVar12);
          local_24c = local_24c | 0x100;
        }
        iVar11 = (int)(uVar12 >> 0x20);
        if ((local_24c & 0x8000) == 0) {
          iVar11 = 0;
        }
        lVar13 = CONCAT44(iVar11,(int)uVar12);
        if (local_244 < 0) {
          local_244 = 1;
        }
        else {
          local_24c = local_24c & 0xfffffff7;
        }
        if ((int)uVar12 == 0 && iVar11 == 0) {
          local_238 = 0;
        }
        psVar5 = (short *)&uStack_1;
        iVar11 = local_244;
        while ((iVar6 = local_22c, local_244 = iVar11 + -1, 0 < iVar11 || (lVar13 != 0))) {
          local_204 = local_22c >> 0x1f;
          iVar11 = __aullrem(lVar13,local_22c,local_204);
          iVar11 = iVar11 + 0x30;
          lVar13 = __aulldiv(lVar13,iVar6,local_204);
          if (0x39 < iVar11) {
            iVar11 = iVar11 + local_224;
          }
          *(char *)psVar5 = (char)iVar11;
          psVar5 = (short *)((int)psVar5 + -1);
          iVar11 = local_244;
        }
        puVar9 = &uStack_1 + -(int)psVar5;
        local_248 = (short *)((int)psVar5 + 1);
        if (((local_24c & 0x200) != 0) &&
           ((*(char *)local_248 != '0' || (puVar9 == (undefined1 *)0x0)))) {
          puVar9 = &stack0x00000000 + -(int)psVar5;
          *(char *)psVar5 = '0';
          local_248 = psVar5;
        }
        break;
      case 'x':
        local_224 = 0x27;
        goto LAB_00551cd2;
      }
      if (local_228 == 0) {
        if ((local_24c & 0x40) != 0) {
          if ((local_24c & 0x100) == 0) {
            if ((local_24c & 1) == 0) {
              if ((local_24c & 2) == 0) goto LAB_00551eaf;
              local_23a = 0x20;
            }
            else {
              local_23a = 0x2b;
            }
          }
          else {
            local_23a = 0x2d;
          }
          local_238 = 1;
        }
LAB_00551eaf:
        iVar11 = (local_234 - local_238) - (int)puVar9;
        if ((local_24c & 0xc) == 0) {
          FUN_00552130(0x20,iVar11,param_1,&local_240);
        }
        FUN_00552170(&local_23a,local_238,param_1,&local_240);
        if (((local_24c & 8) != 0) && ((local_24c & 4) == 0)) {
          FUN_00552130(0x30,iVar11,param_1,&local_240);
        }
        if ((local_230 == 0) || (psVar5 = local_248, puVar8 = puVar9, (int)puVar9 < 1)) {
          FUN_00552170(local_248,puVar9,param_1,&local_240);
        }
        else {
          do {
            puVar8 = puVar8 + -1;
            iVar6 = wctomb(local_214,*psVar5);
            if (iVar6 < 1) break;
            FUN_00552170(local_214,iVar6,param_1,&local_240);
            psVar5 = psVar5 + 1;
          } while (puVar8 != (undefined1 *)0x0);
        }
        if ((local_24c & 4) != 0) {
          FUN_00552130(0x20,iVar11,param_1,&local_240);
        }
      }
    }
    cVar7 = *param_2;
    param_2 = param_2 + 1;
    local_21c = CONCAT31(local_21c._1_3_,cVar7);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_005520e0
// Address: 005520e0
void FUN_005520e0(uint param_1,int *param_2,int *param_3)
{
  int iVar1;
  
  iVar1 = param_2[1];
  param_2[1] = iVar1 + -1;
  if (iVar1 + -1 < 0) {
    param_1 = __flsbuf(param_1,param_2);
  }
  else {
    *(char *)*param_2 = (char)param_1;
    param_1 = param_1 & 0xff;
    *param_2 = *param_2 + 1;
  }
  if (param_1 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00552122
// Address: 00552122
void FUN_00552122(undefined4 param_1,int param_2,undefined4 param_3,int *param_4)
{
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      FUN_005520e0(param_1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00552130
// Address: 00552130
void FUN_00552130(undefined4 param_1,int param_2,undefined4 param_3,int *param_4)
{
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      FUN_005520e0(param_1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00552169
// Address: 00552169
void FUN_00552169(char *param_1,int param_2,undefined4 param_3,int *param_4)
{
  char cVar1;
  
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      FUN_005520e0((int)cVar1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00552170
// Address: 00552170
void FUN_00552170(char *param_1,int param_2,undefined4 param_3,int *param_4)
{
  char cVar1;
  
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      FUN_005520e0((int)cVar1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005521ad
// Address: 005521ad
undefined4 FUN_005521ad(int *param_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}

// --------------------------------------------------

// Function: FUN_005521b0
// Address: 005521b0
undefined4 FUN_005521b0(int *param_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}

// --------------------------------------------------

// Function: FUN_005521c1
// Address: 005521c1
undefined8 FUN_005521c1(int *param_1)
{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}

// --------------------------------------------------

// Function: FUN_005521d0
// Address: 005521d0
undefined8 FUN_005521d0(int *param_1)
{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}

// --------------------------------------------------

// Function: FUN_005521e2
// Address: 005521e2
undefined4 FUN_005521e2(undefined4 *param_1)
{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = (undefined2 *)*param_1;
  puVar2 = puVar1 + 2;
  *param_1 = puVar2;
  return CONCAT22((short)((uint)puVar2 >> 0x10),*puVar1);
}

// --------------------------------------------------

// Function: FUN_005521f0
// Address: 005521f0
undefined4 FUN_005521f0(undefined4 *param_1)
{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = (undefined2 *)*param_1;
  puVar2 = puVar1 + 2;
  *param_1 = puVar2;
  return CONCAT22((short)((uint)puVar2 >> 0x10),*puVar1);
}

// --------------------------------------------------

// Function: FUN_00552202
// Address: 00552202
// [HELPER] s_____00591d80: " 	-]"
void FUN_00552202(uint param_1)
{
  uint *puVar1;
  int iVar2;
  
  __doserrno = param_1;
  iVar2 = 0;
  puVar1 = &DAT_00591c18;
  do {
    if (param_1 == *puVar1) {
      _errno = *(undefined4 *)(iVar2 * 8 + 0x591c1c);
      return;
    }
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 1;
  } while (puVar1 < s_____00591d80);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    _errno = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (_errno = 8, 0xca < param_1)) {
    _errno = 0x16;
  }
  return;
}

// --------------------------------------------------

// Function: __dosmaperr
// Address: 00552210
// [HELPER] s_____00591d80: " 	-]"
void __dosmaperr(uint param_1)
{
  uint *puVar1;
  int iVar2;
  
  __doserrno = param_1;
  iVar2 = 0;
  puVar1 = &DAT_00591c18;
  do {
    if (param_1 == *puVar1) {
      _errno = *(undefined4 *)(iVar2 * 8 + 0x591c1c);
      return;
    }
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 1;
  } while (puVar1 < s_____00591d80);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    _errno = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (_errno = 8, 0xca < param_1)) {
    _errno = 0x16;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00552277
// Address: 00552277
void FUN_00552277(undefined4 *param_1)
{
  if (((param_1[3] & 0x83) != 0) && ((param_1[3] & 8) != 0)) {
    free(param_1[2]);
    param_1[3] = param_1[3] & 0xfffffbf7;
    *param_1 = 0;
    param_1[2] = 0;
    param_1[1] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: __freebuf
// Address: 00552280
void __freebuf(undefined4 *param_1)
{
  if (((param_1[3] & 0x83) != 0) && ((param_1[3] & 8) != 0)) {
    free(param_1[2]);
    param_1[3] = param_1[3] & 0xfffffbf7;
    *param_1 = 0;
    param_1[2] = 0;
    param_1[1] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005522b3
// Address: 005522b3
// [HELPER] s_____00591d80: " 	-]"
int FUN_005522b3(undefined4 param_1,byte *param_2,undefined4 *param_3)
{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  byte bVar11;
  byte *pbVar12;
  int iVar13;
  char *pcVar14;
  uint *puVar15;
  char *pcVar16;
  uint *puVar17;
  bool bVar18;
  longlong lVar19;
  char cStack_1cd;
  uint uStack_1cc;
  char cStack_1c7;
  char cStack_1c6;
  char cStack_1c5;
  int iStack_1c4;
  char cStack_1c0;
  char cStack_1bf;
  char cStack_1be;
  byte bStack_1bd;
  uint uStack_1bc;
  uint *puStack_1b8;
  uint uStack_1b4;
  int iStack_1b0;
  int iStack_1ac;
  int iStack_1a8;
  uint uStack_1a4;
  byte bStack_19e;
  undefined1 uStack_19d;
  undefined8 uStack_19c;
  undefined4 uStack_194;
  undefined2 uStack_18e;
  undefined4 *puStack_18c;
  int iStack_188;
  undefined4 uStack_184;
  byte abStack_180 [11];
  undefined1 uStack_175;
  char cStack_160;
  char acStack_15f [351];
  
  cStack_1bf = '\0';
  uStack_1cc = 0;
  iStack_1ac = 0;
  bVar11 = *param_2;
  puVar9 = puStack_18c;
  do {
    if (bVar11 == 0) {
LAB_00552f16:
      if ((puVar9 == (undefined4 *)0xffffffff) && ((iStack_1ac == 0 && (cStack_1bf == '\0')))) {
        iStack_1ac = -1;
      }
      return iStack_1ac;
    }
    iVar13 = 0;
    if (___mb_cur_max < 2) {
      uVar5 = (byte)__pctype[(uint)bVar11 * 2] & 8;
    }
    else {
      uVar5 = __isctype(bVar11,8);
    }
    if (uVar5 != 0) {
      uStack_1cc = uStack_1cc - 1;
      uVar6 = FUN_00553090(&uStack_1cc,param_1,param_1);
      FUN_00553070(uVar6);
      param_2 = param_2 + 1;
      iVar7 = isspace(*param_2);
      while (iVar7 != 0) {
        param_2 = param_2 + 1;
        iVar7 = isspace(*param_2);
      }
    }
    if (*param_2 != 0x25) {
      uStack_1cc = uStack_1cc + 1;
      puVar9 = (undefined4 *)FUN_00553040(param_1);
      if ((undefined4 *)(uint)*param_2 != puVar9) goto LAB_00552efd;
      pbVar12 = param_2 + 1;
      if ((__pctype[((uint)puVar9 & 0xff) * 2 + 1] & 0x80) != 0) {
        uStack_1cc = uStack_1cc + 1;
        uVar5 = FUN_00553040(param_1);
        if (param_2[1] != uVar5) {
          uStack_1cc = uStack_1cc - 1;
          FUN_00553070(uVar5,param_1);
          goto LAB_00552efd;
        }
        uStack_1cc = uStack_1cc - 1;
        pbVar12 = param_2 + 2;
      }
      goto LAB_00552ec3;
    }
    uStack_1a4 = 0;
    uStack_1b4 = uStack_1b4 & 0xffffff00;
    iStack_1a8 = 0;
    iStack_1b0 = 0;
    iStack_1c4 = 0;
    bStack_1bd = 0;
    cStack_1be = '\0';
    cStack_1c5 = '\0';
    cStack_1cd = '\0';
    cStack_1c0 = '\0';
    cStack_1c7 = '\0';
    cStack_1c6 = '\x01';
    iStack_188 = 0;
    do {
      pbVar12 = param_2 + 1;
      uVar5 = (uint)*pbVar12;
      if (___mb_cur_max < 2) {
        uVar8 = (byte)__pctype[uVar5 * 2] & 4;
      }
      else {
        uVar8 = __isctype(uVar5,4);
      }
      if (uVar8 == 0) {
        switch(uVar5) {
        case 0x2a:
          cStack_1c5 = cStack_1c5 + '\x01';
          break;
        default:
switchD_00552440_caseD_2b:
          cStack_1cd = cStack_1cd + '\x01';
          break;
        case 0x46:
        case 0x4e:
          break;
        case 0x49:
          if ((param_2[2] != 0x36) || (param_2[3] != 0x34)) goto switchD_00552440_caseD_2b;
          iVar13 = iVar13 + 1;
          uStack_19c = 0;
          pbVar12 = param_2 + 3;
          break;
        case 0x4c:
          cStack_1c6 = cStack_1c6 + '\x01';
          break;
        case 0x68:
          cStack_1c6 = cStack_1c6 + -1;
          cStack_1c7 = cStack_1c7 + -1;
          break;
        case 0x6c:
          cStack_1c6 = cStack_1c6 + '\x01';
        case 0x77:
          cStack_1c7 = cStack_1c7 + '\x01';
        }
      }
      else {
        iStack_1b0 = iStack_1b0 + 1;
        iStack_1c4 = (uVar5 - 0x30) + iStack_1c4 * 10;
      }
      param_2 = pbVar12;
    } while (cStack_1cd == '\0');
    puVar3 = param_3;
    if (cStack_1c5 == '\0') {
      puStack_1b8 = (uint *)*param_3;
      puVar3 = param_3 + 1;
      puStack_18c = param_3;
    }
    param_3 = puVar3;
    bVar18 = false;
    if ((cStack_1c7 == '\0') && ((*param_2 == 0x53 || (cStack_1c7 = -1, *param_2 == 0x43)))) {
      cStack_1c7 = '\x01';
    }
    uStack_1bc = *param_2 | 0x20;
    iStack_188 = iVar13;
    lVar19 = uStack_19c;
    if (uStack_1bc != 0x6e) {
      if ((uStack_1bc == 99) || (uStack_1bc == 0x7b)) {
        uStack_1cc = uStack_1cc + 1;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        lVar19 = uStack_19c;
      }
      else {
        puVar9 = (undefined4 *)FUN_00553090(&uStack_1cc,param_1);
        lVar19 = uStack_19c;
      }
    }
    puVar15 = puStack_1b8;
    uVar5 = uStack_1bc;
    uStack_19c = lVar19;
    if ((iStack_1b0 != 0) && (iStack_1c4 == 0)) {
LAB_00552efd:
      uStack_1cc = uStack_1cc - 1;
      FUN_00553070(puVar9,param_1);
      goto LAB_00552f16;
    }
    switch(uStack_1bc) {
    case 99:
      if (iStack_1b0 == 0) {
        iStack_1b0 = 1;
        iStack_1c4 = iStack_1c4 + 1;
      }
      if ('\0' < cStack_1c7) {
        cStack_1c0 = '\x01';
      }
      pcVar14 = &DAT_00591d88;
      goto LAB_005525be;
    case 100:
    case 0x6f:
    case 0x75:
      goto switchD_00552558_caseD_64;
    case 0x65:
    case 0x66:
    case 0x67:
      pcVar14 = &cStack_160;
      if (puVar9 == (undefined4 *)0x2d) {
        cStack_160 = '-';
        pcVar14 = acStack_15f;
LAB_00552c03:
        iStack_1c4 = iStack_1c4 + -1;
        uStack_1cc = uStack_1cc + 1;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        lVar19 = uStack_19c;
      }
      else if (puVar9 == (undefined4 *)0x2b) goto LAB_00552c03;
      iVar13 = iStack_1a8;
      if ((iStack_1b0 == 0) || (0x15d < iStack_1c4)) {
        iStack_1c4 = 0x15d;
      }
      while( true ) {
        if (___mb_cur_max < 2) {
          uVar5 = (byte)__pctype[(int)puVar9 * 2] & 4;
        }
        else {
          uStack_19c = lVar19;
          uVar5 = __isctype(puVar9,4);
          lVar19 = uStack_19c;
        }
        uStack_19c = lVar19;
        if ((uVar5 == 0) ||
           (iVar7 = iStack_1c4 + -1, bVar18 = iStack_1c4 == 0, iStack_1c4 = iVar7, bVar18)) break;
        *pcVar14 = (char)puVar9;
        pcVar14 = pcVar14 + 1;
        uStack_1cc = uStack_1cc + 1;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        iVar13 = iVar13 + 1;
        lVar19 = uStack_19c;
      }
      if ((___decimal_point == (char)puVar9) &&
         (iVar7 = iStack_1c4 + -1, bVar18 = iStack_1c4 != 0, iStack_1c4 = iVar7, bVar18)) {
        uStack_1cc = uStack_1cc + 1;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        *pcVar14 = ___decimal_point;
        while( true ) {
          pcVar14 = pcVar14 + 1;
          if (___mb_cur_max < 2) {
            uVar5 = (byte)__pctype[(int)puVar9 * 2] & 4;
            lVar19 = uStack_19c;
          }
          else {
            uVar5 = __isctype(puVar9,4);
            lVar19 = uStack_19c;
          }
          if ((uVar5 == 0) ||
             (iVar7 = iStack_1c4 + -1, bVar18 = iStack_1c4 == 0, iStack_1c4 = iVar7, bVar18)) break;
          *pcVar14 = (char)puVar9;
          iVar13 = iVar13 + 1;
          uStack_1cc = uStack_1cc + 1;
          uStack_19c = lVar19;
          puVar9 = (undefined4 *)FUN_00553040(param_1);
        }
      }
      pcVar16 = pcVar14;
      if ((iVar13 != 0) &&
         (((puVar9 == (undefined4 *)0x65 || (puVar9 == (undefined4 *)0x45)) &&
          (iVar7 = iStack_1c4 + -1, bVar18 = iStack_1c4 != 0, iStack_1c4 = iVar7, bVar18)))) {
        *pcVar14 = 'e';
        pcVar16 = pcVar14 + 1;
        uStack_1cc = uStack_1cc + 1;
        uStack_19c = lVar19;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        if (puVar9 == (undefined4 *)0x2d) {
          *pcVar16 = '-';
          pcVar16 = pcVar14 + 2;
LAB_00552d5e:
          iVar7 = iStack_1c4 + -1;
          lVar19 = uStack_19c;
          if (iStack_1c4 != 0) goto LAB_00552d73;
        }
        else if (puVar9 == (undefined4 *)0x2b) goto LAB_00552d5e;
        while( true ) {
          if (___mb_cur_max < 2) {
            uVar5 = (byte)__pctype[(int)puVar9 * 2] & 4;
            lVar19 = uStack_19c;
          }
          else {
            uVar5 = __isctype(puVar9,4);
            lVar19 = uStack_19c;
          }
          if ((uVar5 == 0) ||
             (iVar7 = iStack_1c4 + -1, bVar18 = iStack_1c4 == 0, iStack_1c4 = iVar7, bVar18)) break;
          iVar13 = iVar13 + 1;
          *pcVar16 = (char)puVar9;
          pcVar16 = pcVar16 + 1;
LAB_00552d73:
          iStack_1c4 = iVar7;
          uStack_1cc = uStack_1cc + 1;
          uStack_19c = lVar19;
          puVar9 = (undefined4 *)FUN_00553040(param_1);
        }
      }
      uStack_1cc = uStack_1cc - 1;
      uStack_19c = lVar19;
      FUN_00553070(puVar9,param_1);
      if (iVar13 == 0) goto LAB_00552f16;
      lVar19 = uStack_19c;
      if (cStack_1c5 == '\0') {
        iStack_1ac = iStack_1ac + 1;
        *pcVar16 = '\0';
        (*(code *)PTR___fptrap_0058fbd0)(cStack_1c6 + -1,puStack_1b8,&cStack_160);
        lVar19 = uStack_19c;
      }
      break;
    default:
      if ((undefined4 *)(uint)*param_2 != puVar9) goto LAB_00552efd;
      cStack_1bf = cStack_1bf + -1;
      if (cStack_1c5 == '\0') {
        param_3 = puStack_18c;
      }
      break;
    case 0x69:
      uStack_1bc = 100;
    case 0x78:
      uVar5 = uStack_1bc;
      if (puVar9 == (undefined4 *)0x2d) {
        cStack_1be = '\x01';
LAB_00552812:
        iStack_1c4 = iStack_1c4 + -1;
        if ((iStack_1c4 == 0) && (iStack_1b0 != 0)) {
          bVar18 = true;
        }
        else {
          uStack_1cc = uStack_1cc + 1;
          puVar9 = (undefined4 *)FUN_00553040(param_1);
          lVar19 = uStack_19c;
        }
      }
      else if (puVar9 == (undefined4 *)0x2b) goto LAB_00552812;
      if (puVar9 == (undefined4 *)0x30) {
        uStack_1cc = uStack_1cc + 1;
        uStack_19c = lVar19;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        if (((char)puVar9 == 'x') || ((char)puVar9 == 'X')) {
          uStack_1cc = uStack_1cc + 1;
          puVar9 = (undefined4 *)FUN_00553040(param_1);
          uVar5 = 0x78;
          uStack_1bc = 0x78;
          lVar19 = uStack_19c;
        }
        else {
          iStack_1a8 = 1;
          if (uVar5 == 0x78) {
            uStack_1cc = uStack_1cc - 1;
            FUN_00553070(puVar9,param_1);
            puVar9 = (undefined4 *)0x30;
            lVar19 = uStack_19c;
          }
          else {
            uVar5 = 0x6f;
            uStack_1bc = 0x6f;
            lVar19 = uStack_19c;
          }
        }
      }
      goto LAB_005528f4;
    case 0x6e:
      uVar5 = uStack_1cc;
      if (cStack_1c5 != '\0') break;
      goto LAB_00552bb5;
    case 0x70:
      cStack_1c6 = '\x01';
switchD_00552558_caseD_64:
      if (puVar9 == (undefined4 *)0x2d) {
        cStack_1be = '\x01';
LAB_005528ca:
        iStack_1c4 = iStack_1c4 + -1;
        if ((iStack_1c4 == 0) && (iStack_1b0 != 0)) {
          bVar18 = true;
        }
        else {
          uStack_1cc = uStack_1cc + 1;
          puVar9 = (undefined4 *)FUN_00553040(param_1);
          lVar19 = uStack_19c;
        }
      }
      else if (puVar9 == (undefined4 *)0x2b) goto LAB_005528ca;
LAB_005528f4:
      uVar8 = uStack_1a4;
      uStack_19c = lVar19;
      if (iVar13 == 0) {
        while (!bVar18) {
          uStack_19c = lVar19;
          if ((uVar5 == 0x78) || (uVar5 == 0x70)) {
            if (___mb_cur_max < 2) {
              uVar10 = (byte)__pctype[(int)puVar9 * 2] & 0x80;
            }
            else {
              uVar10 = __isctype(puVar9,0x80);
              lVar19 = uStack_19c;
            }
            if (uVar10 != 0) {
              uVar8 = uVar8 << 4;
              uStack_19c = lVar19;
              puVar9 = (undefined4 *)FUN_00553000(puVar9);
              goto LAB_00552aea;
            }
LAB_00552ae6:
            bVar18 = true;
            uStack_19c = lVar19;
          }
          else {
            if (___mb_cur_max < 2) {
              uVar10 = (byte)__pctype[(int)puVar9 * 2] & 4;
            }
            else {
              uVar10 = __isctype(puVar9,4);
              lVar19 = uStack_19c;
            }
            if (uVar10 == 0) goto LAB_00552ae6;
            uStack_19c = lVar19;
            if (uVar5 == 0x6f) {
              if (0x37 < (int)puVar9) goto LAB_00552ae6;
              uVar8 = uVar8 << 3;
            }
            else {
              uVar8 = uVar8 * 10;
            }
          }
LAB_00552aea:
          if (bVar18) {
            uStack_1cc = uStack_1cc - 1;
            FUN_00553070(puVar9,param_1);
            lVar19 = uStack_19c;
          }
          else {
            iStack_1a8 = iStack_1a8 + 1;
            uVar8 = (uVar8 - 0x30) + (int)puVar9;
            if ((iStack_1b0 == 0) || (iStack_1c4 = iStack_1c4 + -1, iStack_1c4 != 0)) {
              uStack_1cc = uStack_1cc + 1;
              puVar9 = (undefined4 *)FUN_00553040(param_1);
              lVar19 = uStack_19c;
            }
            else {
              bVar18 = true;
              lVar19 = uStack_19c;
            }
          }
        }
        uStack_1a4 = uVar8;
        if (cStack_1be != '\0') {
          uStack_1a4 = -uVar8;
        }
      }
      else {
        while (!bVar18) {
          if (uStack_1bc == 0x78) {
            if (___mb_cur_max < 2) {
              uVar5 = (byte)__pctype[(int)puVar9 * 2] & 0x80;
            }
            else {
              uVar5 = __isctype(puVar9,0x80);
            }
            if (uVar5 != 0) {
              lVar19 = __allshl();
              puVar9 = (undefined4 *)FUN_00553000(puVar9);
              goto LAB_005529c1;
            }
LAB_005529bd:
            bVar18 = true;
          }
          else {
            if (___mb_cur_max < 2) {
              uVar5 = (byte)__pctype[(int)puVar9 * 2] & 4;
            }
            else {
              uVar5 = __isctype(puVar9,4);
            }
            if (uVar5 == 0) goto LAB_005529bd;
            if (uStack_1bc == 0x6f) {
              if (0x37 < (int)puVar9) goto LAB_005529bd;
              lVar19 = __allshl();
            }
            else {
              lVar19 = __allmul(lVar19,10,0);
            }
          }
LAB_005529c1:
          if (bVar18) {
            uStack_1cc = uStack_1cc - 1;
            FUN_00553070(puVar9,param_1);
          }
          else {
            puVar3 = puVar9 + -0xc;
            iStack_1a8 = iStack_1a8 + 1;
            if ((iStack_1b0 == 0) || (iStack_1c4 = iStack_1c4 + -1, iStack_1c4 != 0)) {
              uStack_1cc = uStack_1cc + 1;
              puVar9 = (undefined4 *)FUN_00553040(param_1);
              lVar19 = lVar19 + (int)puVar3;
            }
            else {
              bVar18 = true;
              lVar19 = lVar19 + (int)puVar3;
            }
          }
        }
        uStack_19c._4_4_ = (int)((ulonglong)lVar19 >> 0x20);
        uStack_19c._0_4_ = (int)lVar19;
        if (cStack_1be != '\0') {
          lVar19 = CONCAT44(-(uStack_19c._4_4_ + (uint)((int)uStack_19c != 0)),-(int)uStack_19c);
        }
      }
      iVar13 = iStack_1a8;
      if (uStack_1bc == 0x46) {
        iVar13 = 0;
      }
      if (iVar13 == 0) goto LAB_00552f16;
      if (cStack_1c5 == '\0') {
        iStack_1ac = iStack_1ac + 1;
        uVar5 = uStack_1a4;
        iVar13 = iStack_188;
LAB_00552bb5:
        if (iVar13 == 0) {
          if (cStack_1c6 == '\0') {
            *(short *)puStack_1b8 = (short)uVar5;
          }
          else {
            *puStack_1b8 = uVar5;
          }
        }
        else {
          *(longlong *)puStack_1b8 = lVar19;
        }
      }
      break;
    case 0x73:
      if ('\0' < cStack_1c7) {
        cStack_1c0 = '\x01';
      }
      pcVar14 = s_____00591d80;
LAB_005525be:
      bStack_1bd = 0xff;
      pbVar12 = param_2;
LAB_005525c3:
      param_2 = pbVar12;
      pbVar12 = abStack_180;
      for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
        pbVar12[0] = 0;
        pbVar12[1] = 0;
        pbVar12[2] = 0;
        pbVar12[3] = 0;
        pbVar12 = pbVar12 + 4;
      }
      if ((uStack_1bc == 0x7b) && (*pcVar14 == 0x5d)) {
        uStack_1b4 = CONCAT31(uStack_1b4._1_3_,0x5d);
        pcVar14 = (char *)((byte *)pcVar14 + 1);
        uStack_175 = 0x20;
      }
      bVar11 = *pcVar14;
      uVar5 = uStack_1b4;
      while (bVar11 != 0x5d) {
        pbVar12 = (byte *)pcVar14 + 1;
        uVar8 = (uint)uStack_184 >> 8;
        uStack_184 = CONCAT31((int3)uVar8,bVar11);
        uStack_1b4._1_3_ = (undefined3)(uVar5 >> 8);
        if (((bVar11 == 0x2d) &&
            (uStack_1b4._0_1_ = (byte)uVar5, bVar2 = (byte)uStack_1b4, (byte)uStack_1b4 != 0)) &&
           (bVar1 = *pbVar12, bVar1 != 0x5d)) {
          pbVar12 = (byte *)pcVar14 + 2;
          uVar8 = (uint)uStack_194 >> 8;
          bVar11 = (byte)uStack_1b4;
          if (bVar1 <= (byte)uStack_1b4) {
            uStack_1b4 = CONCAT31(uStack_1b4._1_3_,bVar1);
            bVar11 = bVar1;
            uVar5 = uStack_1b4;
            bVar1 = bVar2;
          }
          uStack_1b4 = uVar5;
          uStack_194 = CONCAT31((int3)uVar8,bVar1);
          if (bVar11 <= bVar1) {
            uVar5 = uStack_1b4 & 0xff;
            iVar13 = (bVar1 - uVar5) + 1;
            do {
              uVar8 = uVar5 >> 3;
              bVar11 = (byte)uVar5;
              uVar5 = uVar5 + 1;
              iVar13 = iVar13 + -1;
              abStack_180[uVar8] = abStack_180[uVar8] | '\x01' << (bVar11 & 7);
            } while (iVar13 != 0);
          }
          uStack_1b4 = uStack_1b4 & 0xffffff00;
        }
        else {
          uStack_1b4 = CONCAT31(uStack_1b4._1_3_,bVar11);
          abStack_180[bVar11 >> 3] = abStack_180[bVar11 >> 3] | '\x01' << (bVar11 & 7);
        }
        pcVar14 = (char *)pbVar12;
        uVar5 = uStack_1b4;
        bVar11 = *pbVar12;
      }
      if (*pcVar14 == 0) goto LAB_00552f16;
      if (uStack_1bc == 0x7b) {
        param_2 = (byte *)pcVar14;
      }
      uStack_1cc = uStack_1cc - 1;
      uStack_1b4 = uVar5;
      FUN_00553070(puVar9,param_1);
      puVar17 = puVar15;
      while( true ) {
        if ((iStack_1b0 != 0) &&
           (iVar13 = iStack_1c4 + -1, bVar18 = iStack_1c4 == 0, iStack_1c4 = iVar13,
           puVar4 = puVar17, bVar18)) goto LAB_005527ac;
        uStack_1cc = uStack_1cc + 1;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        if ((puVar9 == (undefined4 *)0xffffffff) ||
           (bVar11 = (byte)puVar9,
           ((int)(char)(abStack_180[(int)puVar9 >> 3] ^ bStack_1bd) & 1 << (bVar11 & 7)) == 0))
        break;
        if (cStack_1c5 == '\0') {
          if (cStack_1c0 == '\0') {
            *(byte *)puVar17 = bVar11;
            puVar17 = (uint *)((int)puVar17 + 1);
          }
          else {
            bStack_19e = bVar11;
            if ((__pctype[((uint)puVar9 & 0xff) * 2 + 1] & 0x80) != 0) {
              uStack_1cc = uStack_1cc + 1;
              uStack_19d = FUN_00553040(param_1);
            }
            mbtowc(&uStack_18e,&bStack_19e,___mb_cur_max);
            *(undefined2 *)puVar17 = uStack_18e;
            puVar17 = (uint *)((int)puVar17 + 2);
          }
        }
        else {
          puVar15 = (uint *)((int)puVar15 + 1);
        }
      }
      uStack_1cc = uStack_1cc - 1;
      puStack_1b8 = puVar17;
      FUN_00553070(puVar9,param_1);
      puVar4 = puStack_1b8;
LAB_005527ac:
      puStack_1b8 = puVar4;
      if (puVar15 == puVar17) goto LAB_00552f16;
      lVar19 = uStack_19c;
      if ((cStack_1c5 == '\0') && (iStack_1ac = iStack_1ac + 1, uStack_1bc != 99)) {
        if (cStack_1c0 == '\0') {
          *(byte *)puStack_1b8 = 0;
        }
        else {
          *(undefined2 *)puStack_1b8 = 0;
        }
      }
      break;
    case 0x7b:
      if ('\0' < cStack_1c7) {
        cStack_1c0 = '\x01';
      }
      pbVar12 = param_2 + 1;
      pcVar14 = (char *)pbVar12;
      if (*pbVar12 == 0x5e) {
        pcVar14 = (char *)(param_2 + 2);
        param_2 = pbVar12;
        goto LAB_005525be;
      }
      goto LAB_005525c3;
    }
    cStack_1bf = cStack_1bf + '\x01';
    pbVar12 = param_2 + 1;
    uStack_19c = lVar19;
LAB_00552ec3:
    param_2 = pbVar12;
    if ((puVar9 == (undefined4 *)0xffffffff) && ((*param_2 != 0x25 || (param_2[1] != 0x6e))))
    goto LAB_00552f16;
    bVar11 = *param_2;
  } while( true );
}

// --------------------------------------------------

// Function: __input
// Address: 005522c0
// [HELPER] s_____00591d80: " 	-]"
int __input(undefined4 param_1,byte *param_2,undefined4 *param_3)
{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  byte bVar11;
  byte *pbVar12;
  int iVar13;
  char *pcVar14;
  uint *puVar15;
  char *pcVar16;
  uint *puVar17;
  bool bVar18;
  longlong lVar19;
  char local_1cd;
  uint local_1cc;
  char local_1c7;
  char local_1c6;
  char local_1c5;
  int local_1c4;
  char local_1c0;
  char local_1bf;
  char local_1be;
  byte local_1bd;
  uint local_1bc;
  uint *local_1b8;
  uint local_1b4;
  int local_1b0;
  int local_1ac;
  int local_1a8;
  uint local_1a4;
  byte local_19e;
  undefined1 local_19d;
  undefined8 local_19c;
  undefined4 local_194;
  undefined2 local_18e;
  undefined4 *local_18c;
  int local_188;
  undefined4 local_184;
  byte local_180 [11];
  undefined1 local_175;
  char local_160;
  char local_15f [351];
  
  local_1bf = '\0';
  local_1cc = 0;
  local_1ac = 0;
  bVar11 = *param_2;
  puVar9 = local_18c;
  do {
    if (bVar11 == 0) {
LAB_00552f16:
      if ((puVar9 == (undefined4 *)0xffffffff) && ((local_1ac == 0 && (local_1bf == '\0')))) {
        local_1ac = -1;
      }
      return local_1ac;
    }
    iVar13 = 0;
    if (___mb_cur_max < 2) {
      uVar5 = (byte)__pctype[(uint)bVar11 * 2] & 8;
    }
    else {
      uVar5 = __isctype(bVar11,8);
    }
    if (uVar5 != 0) {
      local_1cc = local_1cc - 1;
      uVar6 = FUN_00553090(&local_1cc,param_1,param_1);
      FUN_00553070(uVar6);
      param_2 = param_2 + 1;
      iVar7 = isspace(*param_2);
      while (iVar7 != 0) {
        param_2 = param_2 + 1;
        iVar7 = isspace(*param_2);
      }
    }
    if (*param_2 != 0x25) {
      local_1cc = local_1cc + 1;
      puVar9 = (undefined4 *)FUN_00553040(param_1);
      if ((undefined4 *)(uint)*param_2 != puVar9) goto LAB_00552efd;
      pbVar12 = param_2 + 1;
      if ((__pctype[((uint)puVar9 & 0xff) * 2 + 1] & 0x80) != 0) {
        local_1cc = local_1cc + 1;
        uVar5 = FUN_00553040(param_1);
        if (param_2[1] != uVar5) {
          local_1cc = local_1cc - 1;
          FUN_00553070(uVar5,param_1);
          goto LAB_00552efd;
        }
        local_1cc = local_1cc - 1;
        pbVar12 = param_2 + 2;
      }
      goto LAB_00552ec3;
    }
    local_1a4 = 0;
    local_1b4 = local_1b4 & 0xffffff00;
    local_1a8 = 0;
    local_1b0 = 0;
    local_1c4 = 0;
    local_1bd = 0;
    local_1be = '\0';
    local_1c5 = '\0';
    local_1cd = '\0';
    local_1c0 = '\0';
    local_1c7 = '\0';
    local_1c6 = '\x01';
    local_188 = 0;
    do {
      pbVar12 = param_2 + 1;
      uVar5 = (uint)*pbVar12;
      if (___mb_cur_max < 2) {
        uVar8 = (byte)__pctype[uVar5 * 2] & 4;
      }
      else {
        uVar8 = __isctype(uVar5,4);
      }
      if (uVar8 == 0) {
        switch(uVar5) {
        case 0x2a:
          local_1c5 = local_1c5 + '\x01';
          break;
        default:
switchD_00552440_caseD_2b:
          local_1cd = local_1cd + '\x01';
          break;
        case 0x46:
        case 0x4e:
          break;
        case 0x49:
          if ((param_2[2] != 0x36) || (param_2[3] != 0x34)) goto switchD_00552440_caseD_2b;
          iVar13 = iVar13 + 1;
          local_19c = 0;
          pbVar12 = param_2 + 3;
          break;
        case 0x4c:
          local_1c6 = local_1c6 + '\x01';
          break;
        case 0x68:
          local_1c6 = local_1c6 + -1;
          local_1c7 = local_1c7 + -1;
          break;
        case 0x6c:
          local_1c6 = local_1c6 + '\x01';
        case 0x77:
          local_1c7 = local_1c7 + '\x01';
        }
      }
      else {
        local_1b0 = local_1b0 + 1;
        local_1c4 = (uVar5 - 0x30) + local_1c4 * 10;
      }
      param_2 = pbVar12;
    } while (local_1cd == '\0');
    puVar3 = param_3;
    if (local_1c5 == '\0') {
      local_1b8 = (uint *)*param_3;
      puVar3 = param_3 + 1;
      local_18c = param_3;
    }
    param_3 = puVar3;
    bVar18 = false;
    if ((local_1c7 == '\0') && ((*param_2 == 0x53 || (local_1c7 = -1, *param_2 == 0x43)))) {
      local_1c7 = '\x01';
    }
    local_1bc = *param_2 | 0x20;
    local_188 = iVar13;
    lVar19 = local_19c;
    if (local_1bc != 0x6e) {
      if ((local_1bc == 99) || (local_1bc == 0x7b)) {
        local_1cc = local_1cc + 1;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        lVar19 = local_19c;
      }
      else {
        puVar9 = (undefined4 *)FUN_00553090(&local_1cc,param_1);
        lVar19 = local_19c;
      }
    }
    puVar15 = local_1b8;
    uVar5 = local_1bc;
    local_19c = lVar19;
    if ((local_1b0 != 0) && (local_1c4 == 0)) {
LAB_00552efd:
      local_1cc = local_1cc - 1;
      FUN_00553070(puVar9,param_1);
      goto LAB_00552f16;
    }
    switch(local_1bc) {
    case 99:
      if (local_1b0 == 0) {
        local_1b0 = 1;
        local_1c4 = local_1c4 + 1;
      }
      if ('\0' < local_1c7) {
        local_1c0 = '\x01';
      }
      pcVar14 = &DAT_00591d88;
      goto LAB_005525be;
    case 100:
    case 0x6f:
    case 0x75:
      goto switchD_00552558_caseD_64;
    case 0x65:
    case 0x66:
    case 0x67:
      pcVar14 = &local_160;
      if (puVar9 == (undefined4 *)0x2d) {
        local_160 = '-';
        pcVar14 = local_15f;
LAB_00552c03:
        local_1c4 = local_1c4 + -1;
        local_1cc = local_1cc + 1;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        lVar19 = local_19c;
      }
      else if (puVar9 == (undefined4 *)0x2b) goto LAB_00552c03;
      iVar13 = local_1a8;
      if ((local_1b0 == 0) || (0x15d < local_1c4)) {
        local_1c4 = 0x15d;
      }
      while( true ) {
        if (___mb_cur_max < 2) {
          uVar5 = (byte)__pctype[(int)puVar9 * 2] & 4;
        }
        else {
          local_19c = lVar19;
          uVar5 = __isctype(puVar9,4);
          lVar19 = local_19c;
        }
        local_19c = lVar19;
        if ((uVar5 == 0) ||
           (iVar7 = local_1c4 + -1, bVar18 = local_1c4 == 0, local_1c4 = iVar7, bVar18)) break;
        *pcVar14 = (char)puVar9;
        pcVar14 = pcVar14 + 1;
        local_1cc = local_1cc + 1;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        iVar13 = iVar13 + 1;
        lVar19 = local_19c;
      }
      if ((___decimal_point == (char)puVar9) &&
         (iVar7 = local_1c4 + -1, bVar18 = local_1c4 != 0, local_1c4 = iVar7, bVar18)) {
        local_1cc = local_1cc + 1;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        *pcVar14 = ___decimal_point;
        while( true ) {
          pcVar14 = pcVar14 + 1;
          if (___mb_cur_max < 2) {
            uVar5 = (byte)__pctype[(int)puVar9 * 2] & 4;
            lVar19 = local_19c;
          }
          else {
            uVar5 = __isctype(puVar9,4);
            lVar19 = local_19c;
          }
          if ((uVar5 == 0) ||
             (iVar7 = local_1c4 + -1, bVar18 = local_1c4 == 0, local_1c4 = iVar7, bVar18)) break;
          *pcVar14 = (char)puVar9;
          iVar13 = iVar13 + 1;
          local_1cc = local_1cc + 1;
          local_19c = lVar19;
          puVar9 = (undefined4 *)FUN_00553040(param_1);
        }
      }
      pcVar16 = pcVar14;
      if ((iVar13 != 0) &&
         (((puVar9 == (undefined4 *)0x65 || (puVar9 == (undefined4 *)0x45)) &&
          (iVar7 = local_1c4 + -1, bVar18 = local_1c4 != 0, local_1c4 = iVar7, bVar18)))) {
                    /* language.dll match for 0x65: "1" */
        *pcVar14 = 'e';
        pcVar16 = pcVar14 + 1;
        local_1cc = local_1cc + 1;
        local_19c = lVar19;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        if (puVar9 == (undefined4 *)0x2d) {
          *pcVar16 = '-';
          pcVar16 = pcVar14 + 2;
LAB_00552d5e:
          iVar7 = local_1c4 + -1;
          lVar19 = local_19c;
          if (local_1c4 != 0) goto LAB_00552d73;
        }
        else if (puVar9 == (undefined4 *)0x2b) goto LAB_00552d5e;
        while( true ) {
          if (___mb_cur_max < 2) {
            uVar5 = (byte)__pctype[(int)puVar9 * 2] & 4;
            lVar19 = local_19c;
          }
          else {
            uVar5 = __isctype(puVar9,4);
            lVar19 = local_19c;
          }
          if ((uVar5 == 0) ||
             (iVar7 = local_1c4 + -1, bVar18 = local_1c4 == 0, local_1c4 = iVar7, bVar18)) break;
          iVar13 = iVar13 + 1;
          *pcVar16 = (char)puVar9;
          pcVar16 = pcVar16 + 1;
LAB_00552d73:
          local_1c4 = iVar7;
          local_1cc = local_1cc + 1;
          local_19c = lVar19;
          puVar9 = (undefined4 *)FUN_00553040(param_1);
        }
      }
      local_1cc = local_1cc - 1;
      local_19c = lVar19;
      FUN_00553070(puVar9,param_1);
      if (iVar13 == 0) goto LAB_00552f16;
      lVar19 = local_19c;
      if (local_1c5 == '\0') {
        local_1ac = local_1ac + 1;
        *pcVar16 = '\0';
        (*(code *)PTR___fptrap_0058fbd0)(local_1c6 + -1,local_1b8,&local_160);
        lVar19 = local_19c;
      }
      break;
    default:
      if ((undefined4 *)(uint)*param_2 != puVar9) goto LAB_00552efd;
      local_1bf = local_1bf + -1;
      if (local_1c5 == '\0') {
        param_3 = local_18c;
      }
      break;
    case 0x69:
      local_1bc = 100;
    case 0x78:
      uVar5 = local_1bc;
      if (puVar9 == (undefined4 *)0x2d) {
        local_1be = '\x01';
LAB_00552812:
        local_1c4 = local_1c4 + -1;
        if ((local_1c4 == 0) && (local_1b0 != 0)) {
          bVar18 = true;
        }
        else {
          local_1cc = local_1cc + 1;
          puVar9 = (undefined4 *)FUN_00553040(param_1);
          lVar19 = local_19c;
        }
      }
      else if (puVar9 == (undefined4 *)0x2b) goto LAB_00552812;
      if (puVar9 == (undefined4 *)0x30) {
        local_1cc = local_1cc + 1;
        local_19c = lVar19;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        if (((char)puVar9 == 'x') || ((char)puVar9 == 'X')) {
          local_1cc = local_1cc + 1;
          puVar9 = (undefined4 *)FUN_00553040(param_1);
          uVar5 = 0x78;
          local_1bc = 0x78;
          lVar19 = local_19c;
        }
        else {
          local_1a8 = 1;
          if (uVar5 == 0x78) {
            local_1cc = local_1cc - 1;
            FUN_00553070(puVar9,param_1);
            puVar9 = (undefined4 *)0x30;
            lVar19 = local_19c;
          }
          else {
                    /* language.dll match for 0x6f: "12" */
            uVar5 = 0x6f;
            local_1bc = 0x6f;
            lVar19 = local_19c;
          }
        }
      }
      goto LAB_005528f4;
    case 0x6e:
      uVar5 = local_1cc;
      if (local_1c5 != '\0') break;
      goto LAB_00552bb5;
    case 0x70:
      local_1c6 = '\x01';
switchD_00552558_caseD_64:
      if (puVar9 == (undefined4 *)0x2d) {
        local_1be = '\x01';
LAB_005528ca:
        local_1c4 = local_1c4 + -1;
        if ((local_1c4 == 0) && (local_1b0 != 0)) {
          bVar18 = true;
        }
        else {
          local_1cc = local_1cc + 1;
          puVar9 = (undefined4 *)FUN_00553040(param_1);
          lVar19 = local_19c;
        }
      }
      else if (puVar9 == (undefined4 *)0x2b) goto LAB_005528ca;
LAB_005528f4:
      uVar8 = local_1a4;
      local_19c = lVar19;
      if (iVar13 == 0) {
        while (!bVar18) {
          local_19c = lVar19;
          if ((uVar5 == 0x78) || (uVar5 == 0x70)) {
            if (___mb_cur_max < 2) {
              uVar10 = (byte)__pctype[(int)puVar9 * 2] & 0x80;
            }
            else {
                    /* language.dll match for 0x80: "Arial" */
              uVar10 = __isctype(puVar9,0x80);
              lVar19 = local_19c;
            }
            if (uVar10 != 0) {
              uVar8 = uVar8 << 4;
              local_19c = lVar19;
              puVar9 = (undefined4 *)FUN_00553000(puVar9);
              goto LAB_00552aea;
            }
LAB_00552ae6:
            bVar18 = true;
            local_19c = lVar19;
          }
          else {
            if (___mb_cur_max < 2) {
              uVar10 = (byte)__pctype[(int)puVar9 * 2] & 4;
            }
            else {
              uVar10 = __isctype(puVar9,4);
              lVar19 = local_19c;
            }
            if (uVar10 == 0) goto LAB_00552ae6;
            local_19c = lVar19;
            if (uVar5 == 0x6f) {
              if (0x37 < (int)puVar9) goto LAB_00552ae6;
              uVar8 = uVar8 << 3;
            }
            else {
              uVar8 = uVar8 * 10;
            }
          }
LAB_00552aea:
          if (bVar18) {
            local_1cc = local_1cc - 1;
            FUN_00553070(puVar9,param_1);
            lVar19 = local_19c;
          }
          else {
            local_1a8 = local_1a8 + 1;
            uVar8 = (uVar8 - 0x30) + (int)puVar9;
            if ((local_1b0 == 0) || (local_1c4 = local_1c4 + -1, local_1c4 != 0)) {
              local_1cc = local_1cc + 1;
              puVar9 = (undefined4 *)FUN_00553040(param_1);
              lVar19 = local_19c;
            }
            else {
              bVar18 = true;
              lVar19 = local_19c;
            }
          }
        }
        local_1a4 = uVar8;
        if (local_1be != '\0') {
          local_1a4 = -uVar8;
        }
      }
      else {
        while (!bVar18) {
          if (local_1bc == 0x78) {
            if (___mb_cur_max < 2) {
              uVar5 = (byte)__pctype[(int)puVar9 * 2] & 0x80;
            }
            else {
                    /* language.dll match for 0x80: "Arial" */
              uVar5 = __isctype(puVar9,0x80);
            }
            if (uVar5 != 0) {
              lVar19 = __allshl();
              puVar9 = (undefined4 *)FUN_00553000(puVar9);
              goto LAB_005529c1;
            }
LAB_005529bd:
            bVar18 = true;
          }
          else {
            if (___mb_cur_max < 2) {
              uVar5 = (byte)__pctype[(int)puVar9 * 2] & 4;
            }
            else {
              uVar5 = __isctype(puVar9,4);
            }
            if (uVar5 == 0) goto LAB_005529bd;
            if (local_1bc == 0x6f) {
              if (0x37 < (int)puVar9) goto LAB_005529bd;
              lVar19 = __allshl();
            }
            else {
              lVar19 = __allmul(lVar19,10,0);
            }
          }
LAB_005529c1:
          if (bVar18) {
            local_1cc = local_1cc - 1;
            FUN_00553070(puVar9,param_1);
          }
          else {
            puVar3 = puVar9 + -0xc;
            local_1a8 = local_1a8 + 1;
            if ((local_1b0 == 0) || (local_1c4 = local_1c4 + -1, local_1c4 != 0)) {
              local_1cc = local_1cc + 1;
              puVar9 = (undefined4 *)FUN_00553040(param_1);
              lVar19 = lVar19 + (int)puVar3;
            }
            else {
              bVar18 = true;
              lVar19 = lVar19 + (int)puVar3;
            }
          }
        }
        local_19c._4_4_ = (int)((ulonglong)lVar19 >> 0x20);
        local_19c._0_4_ = (int)lVar19;
        if (local_1be != '\0') {
          lVar19 = CONCAT44(-(local_19c._4_4_ + (uint)((int)local_19c != 0)),-(int)local_19c);
        }
      }
      iVar13 = local_1a8;
      if (local_1bc == 0x46) {
        iVar13 = 0;
      }
      if (iVar13 == 0) goto LAB_00552f16;
      if (local_1c5 == '\0') {
        local_1ac = local_1ac + 1;
        uVar5 = local_1a4;
        iVar13 = local_188;
LAB_00552bb5:
        if (iVar13 == 0) {
          if (local_1c6 == '\0') {
            *(short *)local_1b8 = (short)uVar5;
          }
          else {
            *local_1b8 = uVar5;
          }
        }
        else {
          *(longlong *)local_1b8 = lVar19;
        }
      }
      break;
    case 0x73:
      if ('\0' < local_1c7) {
        local_1c0 = '\x01';
      }
      pcVar14 = s_____00591d80;
LAB_005525be:
      local_1bd = 0xff;
      pbVar12 = param_2;
LAB_005525c3:
      param_2 = pbVar12;
      pbVar12 = local_180;
      for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
        pbVar12[0] = 0;
        pbVar12[1] = 0;
        pbVar12[2] = 0;
        pbVar12[3] = 0;
        pbVar12 = pbVar12 + 4;
      }
      if ((local_1bc == 0x7b) && (*pcVar14 == 0x5d)) {
        local_1b4 = CONCAT31(local_1b4._1_3_,0x5d);
        pcVar14 = (char *)((byte *)pcVar14 + 1);
        local_175 = 0x20;
      }
      bVar11 = *pcVar14;
      uVar5 = local_1b4;
      while (bVar11 != 0x5d) {
        pbVar12 = (byte *)pcVar14 + 1;
        uVar8 = (uint)local_184 >> 8;
        local_184 = CONCAT31((int3)uVar8,bVar11);
        local_1b4._1_3_ = (undefined3)(uVar5 >> 8);
        if (((bVar11 == 0x2d) &&
            (local_1b4._0_1_ = (byte)uVar5, bVar2 = (byte)local_1b4, (byte)local_1b4 != 0)) &&
           (bVar1 = *pbVar12, bVar1 != 0x5d)) {
          pbVar12 = (byte *)pcVar14 + 2;
          uVar8 = (uint)local_194 >> 8;
          bVar11 = (byte)local_1b4;
          if (bVar1 <= (byte)local_1b4) {
            local_1b4 = CONCAT31(local_1b4._1_3_,bVar1);
            bVar11 = bVar1;
            uVar5 = local_1b4;
            bVar1 = bVar2;
          }
          local_1b4 = uVar5;
          local_194 = CONCAT31((int3)uVar8,bVar1);
          if (bVar11 <= bVar1) {
            uVar5 = local_1b4 & 0xff;
            iVar13 = (bVar1 - uVar5) + 1;
            do {
              uVar8 = uVar5 >> 3;
              bVar11 = (byte)uVar5;
              uVar5 = uVar5 + 1;
              iVar13 = iVar13 + -1;
              local_180[uVar8] = local_180[uVar8] | '\x01' << (bVar11 & 7);
            } while (iVar13 != 0);
          }
          local_1b4 = local_1b4 & 0xffffff00;
        }
        else {
          local_1b4 = CONCAT31(local_1b4._1_3_,bVar11);
          local_180[bVar11 >> 3] = local_180[bVar11 >> 3] | '\x01' << (bVar11 & 7);
        }
        pcVar14 = (char *)pbVar12;
        uVar5 = local_1b4;
        bVar11 = *pbVar12;
      }
      if (*pcVar14 == 0) goto LAB_00552f16;
      if (local_1bc == 0x7b) {
        param_2 = (byte *)pcVar14;
      }
      local_1cc = local_1cc - 1;
      local_1b4 = uVar5;
      FUN_00553070(puVar9,param_1);
      puVar17 = puVar15;
      while( true ) {
        if ((local_1b0 != 0) &&
           (iVar13 = local_1c4 + -1, bVar18 = local_1c4 == 0, local_1c4 = iVar13, puVar4 = puVar17,
           bVar18)) goto LAB_005527ac;
        local_1cc = local_1cc + 1;
        puVar9 = (undefined4 *)FUN_00553040(param_1);
        if ((puVar9 == (undefined4 *)0xffffffff) ||
           (bVar11 = (byte)puVar9,
           ((int)(char)(local_180[(int)puVar9 >> 3] ^ local_1bd) & 1 << (bVar11 & 7)) == 0)) break;
        if (local_1c5 == '\0') {
          if (local_1c0 == '\0') {
            *(byte *)puVar17 = bVar11;
            puVar17 = (uint *)((int)puVar17 + 1);
          }
          else {
            local_19e = bVar11;
            if ((__pctype[((uint)puVar9 & 0xff) * 2 + 1] & 0x80) != 0) {
              local_1cc = local_1cc + 1;
              local_19d = FUN_00553040(param_1);
            }
            mbtowc(&local_18e,&local_19e,___mb_cur_max);
            *(undefined2 *)puVar17 = local_18e;
            puVar17 = (uint *)((int)puVar17 + 2);
          }
        }
        else {
          puVar15 = (uint *)((int)puVar15 + 1);
        }
      }
      local_1cc = local_1cc - 1;
      local_1b8 = puVar17;
      FUN_00553070(puVar9,param_1);
      puVar4 = local_1b8;
LAB_005527ac:
      local_1b8 = puVar4;
      if (puVar15 == puVar17) goto LAB_00552f16;
      lVar19 = local_19c;
      if ((local_1c5 == '\0') && (local_1ac = local_1ac + 1, local_1bc != 99)) {
        if (local_1c0 == '\0') {
          *(byte *)local_1b8 = 0;
        }
        else {
          *(undefined2 *)local_1b8 = 0;
        }
      }
      break;
    case 0x7b:
      if ('\0' < local_1c7) {
        local_1c0 = '\x01';
      }
      pbVar12 = param_2 + 1;
      pcVar14 = (char *)pbVar12;
      if (*pbVar12 == 0x5e) {
        pcVar14 = (char *)(param_2 + 2);
        param_2 = pbVar12;
        goto LAB_005525be;
      }
      goto LAB_005525c3;
    }
    local_1bf = local_1bf + '\x01';
    pbVar12 = param_2 + 1;
    local_19c = lVar19;
LAB_00552ec3:
    param_2 = pbVar12;
    if ((puVar9 == (undefined4 *)0xffffffff) && ((*param_2 != 0x25 || (param_2[1] != 0x6e))))
    goto LAB_00552f16;
    bVar11 = *param_2;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00552f39
// Address: 00552f39
int * __fastcall FUN_00552f39(byte *param_1,int param_2)
{
  byte bVar1;
  byte bVar2;
  uint in_EAX;
  byte *pbVar4;
  int *piVar5;
  uint uVar6;
  byte bVar7;
  int *piVar9;
  uint *unaff_EBX;
  int *unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  byte in_AF;
  char cVar3;
  uint uVar8;
  
  pbVar4 = (byte *)(in_EAX & 0xffffff55);
  *(char *)(param_2 + 0x5d005524) = *(char *)(param_2 + 0x5d005524) + (char)unaff_EBX;
  bVar1 = (byte)pbVar4;
  pbVar4[-0x65ffaadc] = pbVar4[-0x65ffaadc] + bVar1;
  *(char *)(unaff_EDI + 0x24) = *(char *)(unaff_EDI + 0x24) + bVar1;
  *(char *)(unaff_ESI + -0x75ffaadc) = *(char *)(unaff_ESI + -0x75ffaadc) + bVar1;
  *(char *)(unaff_ESI + 0x5524) = *(char *)(unaff_ESI + 0x5524) + (char)param_2;
  bVar7 = (byte)param_1;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *param_1 = *param_1 | bVar1;
  *pbVar4 = *pbVar4 | bVar7;
  bVar7 = bVar7 + *pbVar4;
  uVar8 = CONCAT31((int3)((uint)param_1 >> 8),bVar7);
  *(byte *)unaff_EBX = (byte)*unaff_EBX | bVar1;
  pbVar4[uVar8] = pbVar4[uVar8] | bVar1;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  pbVar4 = pbVar4 + 0x6080808;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  *pbVar4 = *pbVar4 | bVar7;
  piVar9 = (int *)(param_2 - *unaff_EBP);
  bVar2 = (byte)((uint)pbVar4 & 0x28b90055);
  bVar1 = 9 < (bVar2 & 0xf) | in_AF;
  bVar2 = bVar2 + bVar1 * '\x06';
  cVar3 = bVar2 + (0x90 < (bVar2 & 0xf0) | bVar1 * (0xf9 < bVar2)) * '`';
  *(undefined1 *)(uVar8 + 0xb900552b) = *(undefined1 *)(uVar8 + 0xb900552b);
  *(char *)unaff_EBP = (char)*unaff_EBP - (char)piVar9;
  piVar5 = (int *)CONCAT22((short)(((uint)pbVar4 & 0x28b90055) >> 0x10),CONCAT11(0x28,cVar3));
  *(char *)((int)piVar5 + -0x46ffaadb) = *(char *)((int)piVar5 + -0x46ffaadb) + bVar7;
  *(char *)unaff_EBP = (char)*unaff_EBP - (char)piVar9;
  *piVar5 = (int)(*piVar5 + (int)unaff_EBP);
  *(char *)((int)unaff_EBP + 0x2e0f0055) = *(char *)((int)unaff_EBP + 0x2e0f0055) + (char)unaff_EBX;
  *(char *)piVar5 = (char)*piVar5 + cVar3;
  *piVar9 = (int)(*piVar9 + (int)piVar5);
  uVar6 = CONCAT31((int3)((uint)piVar5 >> 8),cVar3 + (char)*piVar9) | *unaff_EBX;
  *unaff_EBX = *unaff_EBX |
               uVar8 | *unaff_EBX | *unaff_EBX | *unaff_EBX |
               *(uint *)CONCAT31((int3)(uVar6 >> 8),(char)uVar6 + '\x05') | *unaff_EBX;
  if (___mb_cur_max < 2) {
    uVar6 = (byte)__pctype[(int)unaff_EBP * 2] & 4;
  }
  else {
    uVar6 = __isctype();
  }
  if (uVar6 == 0) {
    unaff_EBP = (int *)(((uint)unaff_EBP & 0xffffffdf) - 7);
  }
  return unaff_EBP;
}

// --------------------------------------------------

// Function: FUN_00553000
// Address: 00553000
uint FUN_00553000(uint param_1)
{
  uint uVar1;
  
  if (___mb_cur_max < 2) {
    uVar1 = (byte)__pctype[param_1 * 2] & 4;
  }
  else {
    uVar1 = __isctype(param_1,4);
  }
  if (uVar1 == 0) {
    param_1 = (param_1 & 0xffffffdf) - 7;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00553039
// Address: 00553039
uint FUN_00553039(undefined4 *param_1)
{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_1[1];
  param_1[1] = iVar2 + -1;
  if (-1 < iVar2 + -1) {
    bVar1 = *(byte *)*param_1;
    *param_1 = (byte *)*param_1 + 1;
    return (uint)bVar1;
  }
  uVar3 = __filbuf(param_1);
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_00553040
// Address: 00553040
uint FUN_00553040(undefined4 *param_1)
{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_1[1];
  param_1[1] = iVar2 + -1;
  if (-1 < iVar2 + -1) {
    bVar1 = *(byte *)*param_1;
    *param_1 = (byte *)*param_1 + 1;
    return (uint)bVar1;
  }
  uVar3 = __filbuf(param_1);
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_00553061
// Address: 00553061
void FUN_00553061(int param_1,undefined4 param_2)
{
  if (param_1 != -1) {
    ungetc(param_1,param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00553070
// Address: 00553070
void FUN_00553070(int param_1,undefined4 param_2)
{
  if (param_1 != -1) {
    ungetc(param_1,param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00553088
// Address: 00553088
undefined4 FUN_00553088(int *param_1,undefined4 param_2)
{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 + 1;
  uVar1 = FUN_00553040(param_2);
  iVar2 = isspace(uVar1);
  while (iVar2 != 0) {
    *param_1 = *param_1 + 1;
    uVar1 = FUN_00553040(param_2);
    iVar2 = isspace(uVar1);
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_00553090
// Address: 00553090
undefined4 FUN_00553090(int *param_1,undefined4 param_2)
{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 + 1;
  uVar1 = FUN_00553040(param_2);
  iVar2 = isspace(uVar1);
  while (iVar2 != 0) {
    *param_1 = *param_1 + 1;
    uVar1 = FUN_00553040(param_2);
    iVar2 = isspace(uVar1);
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_005530d8
// Address: 005530d8
uint FUN_005530d8(undefined4 *param_1)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar2 = param_1[3];
  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {
    if ((uVar2 & 2) != 0) {
      param_1[3] = uVar2 | 0x20;
      return 0xffffffff;
    }
    param_1[3] = uVar2 | 1;
    if ((uVar2 & 0x10c) == 0) {
      __getbuf(param_1);
    }
    else {
      *param_1 = param_1[2];
    }
    iVar3 = read(param_1[4],param_1[2],param_1[6]);
    param_1[1] = iVar3;
    if ((iVar3 != 0) && (iVar3 != -1)) {
      if ((param_1[3] & 0x82) == 0) {
        uVar2 = param_1[4];
        if (uVar2 == 0xffffffff) {
          puVar4 = &___badioinfo;
        }
        else {
          puVar4 = (undefined *)((&___pioinfo)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 8);
        }
        if ((puVar4[4] & 0x82) == 0x82) {
          param_1[3] = param_1[3] | 0x2000;
        }
      }
      if (((param_1[6] == 0x200) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
        param_1[6] = 0x1000;
      }
      param_1[1] = iVar3 + -1;
      bVar1 = *(byte *)*param_1;
      *param_1 = (byte *)*param_1 + 1;
      return (uint)bVar1;
    }
    param_1[1] = 0;
    param_1[3] = param_1[3] | (-(uint)(iVar3 != 0) & 0x10) + 0x10;
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: __filbuf
// Address: 005530e0
uint __filbuf(undefined4 *param_1)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar2 = param_1[3];
  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {
    if ((uVar2 & 2) != 0) {
      param_1[3] = uVar2 | 0x20;
      return 0xffffffff;
    }
    param_1[3] = uVar2 | 1;
    if ((uVar2 & 0x10c) == 0) {
      __getbuf(param_1);
    }
    else {
      *param_1 = param_1[2];
    }
    iVar3 = read(param_1[4],param_1[2],param_1[6]);
    param_1[1] = iVar3;
    if ((iVar3 != 0) && (iVar3 != -1)) {
      if ((param_1[3] & 0x82) == 0) {
        uVar2 = param_1[4];
        if (uVar2 == 0xffffffff) {
          puVar4 = &___badioinfo;
        }
        else {
          puVar4 = (undefined *)((&___pioinfo)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 8);
        }
        if ((puVar4[4] & 0x82) == 0x82) {
          param_1[3] = param_1[3] | 0x2000;
        }
      }
      if (((param_1[6] == 0x200) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
        param_1[6] = 0x1000;
      }
      param_1[1] = iVar3 + -1;
      bVar1 = *(byte *)*param_1;
      *param_1 = (byte *)*param_1 + 1;
      return (uint)bVar1;
    }
    param_1[1] = 0;
    param_1[3] = param_1[3] | (-(uint)(iVar3 != 0) & 0x10) + 0x10;
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_005531cc
// Address: 005531cc
undefined4 * FUN_005531cc(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 *param_4)
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  cVar1 = *param_2;
  bVar3 = false;
  bVar4 = false;
  if (cVar1 == 'a') {
    uVar5 = 0x109;
  }
  else {
    if (cVar1 == 'r') {
      uVar5 = 0;
      uVar7 = __commode | 1;
      goto LAB_0055320d;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    uVar5 = 0x301;
  }
  uVar7 = __commode | 2;
LAB_0055320d:
  param_2 = param_2 + 1;
  bVar2 = true;
  cVar1 = *param_2;
  do {
    if ((cVar1 == '\0') || (!bVar2)) {
      iVar6 = __sopen(param_1,uVar5,param_3,0x1a4);
      if (-1 < iVar6) {
        __cflush = __cflush + 1;
        param_4[3] = uVar7;
        param_4[1] = 0;
        *param_4 = 0;
        param_4[2] = 0;
        param_4[7] = 0;
        param_4[4] = iVar6;
        return param_4;
      }
      return (undefined4 *)0x0;
    }
    switch(cVar1) {
    case '+':
      if ((uVar5 & 2) != 0) break;
      uVar5 = uVar5 & 0xfffffffe | 2;
      uVar7 = uVar7 & 0xfffffffc | 0x80;
      goto LAB_005532be;
    case 'D':
      if ((uVar5 & 0x40) == 0) {
        uVar5 = uVar5 | 0x40;
        goto LAB_005532be;
      }
      break;
    case 'R':
      if (!bVar4) {
        bVar4 = true;
        uVar5 = uVar5 | 0x10;
        goto LAB_005532be;
      }
      break;
    case 'S':
      if (!bVar4) {
        bVar4 = true;
        uVar5 = uVar5 | 0x20;
        goto LAB_005532be;
      }
      break;
    case 'T':
      if ((uVar5 & 0x1000) == 0) {
        uVar5 = uVar5 | 0x1000;
        goto LAB_005532be;
      }
      break;
    case 'b':
      if ((uVar5 & 0xc000) == 0) {
        uVar5 = uVar5 | 0x8000;
        goto LAB_005532be;
      }
      break;
    case 'c':
      if (!bVar3) {
        bVar3 = true;
        uVar7 = uVar7 | 0x4000;
        goto LAB_005532be;
      }
      break;
    case 'n':
      if (!bVar3) {
        bVar3 = true;
        uVar7 = uVar7 & 0xffffbfff;
        goto LAB_005532be;
      }
      break;
    case 't':
      if ((uVar5 & 0xc000) == 0) {
        uVar5 = uVar5 | 0x4000;
        goto LAB_005532be;
      }
    }
    bVar2 = false;
LAB_005532be:
    param_2 = param_2 + 1;
    cVar1 = *param_2;
  } while( true );
}

// --------------------------------------------------

// Function: __openfile
// Address: 005531d0
undefined4 * __openfile(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 *param_4)
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  cVar1 = *param_2;
  bVar3 = false;
  bVar4 = false;
  if (cVar1 == 'a') {
    uVar5 = 0x109;
  }
  else {
    if (cVar1 == 'r') {
      uVar5 = 0;
      uVar7 = __commode | 1;
      goto LAB_0055320d;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    uVar5 = 0x301;
  }
  uVar7 = __commode | 2;
LAB_0055320d:
  param_2 = param_2 + 1;
  bVar2 = true;
  cVar1 = *param_2;
  do {
    if ((cVar1 == '\0') || (!bVar2)) {
      iVar6 = __sopen(param_1,uVar5,param_3,0x1a4);
      if (-1 < iVar6) {
        __cflush = __cflush + 1;
        param_4[3] = uVar7;
        param_4[1] = 0;
        *param_4 = 0;
        param_4[2] = 0;
        param_4[7] = 0;
        param_4[4] = iVar6;
        return param_4;
      }
      return (undefined4 *)0x0;
    }
    switch(cVar1) {
    case '+':
      if ((uVar5 & 2) != 0) break;
      uVar5 = uVar5 & 0xfffffffe | 2;
      uVar7 = uVar7 & 0xfffffffc | 0x80;
      goto LAB_005532be;
    case 'D':
      if ((uVar5 & 0x40) == 0) {
        uVar5 = uVar5 | 0x40;
        goto LAB_005532be;
      }
      break;
    case 'R':
      if (!bVar4) {
        bVar4 = true;
        uVar5 = uVar5 | 0x10;
        goto LAB_005532be;
      }
      break;
    case 'S':
      if (!bVar4) {
        bVar4 = true;
        uVar5 = uVar5 | 0x20;
        goto LAB_005532be;
      }
      break;
    case 'T':
      if ((uVar5 & 0x1000) == 0) {
        uVar5 = uVar5 | 0x1000;
        goto LAB_005532be;
      }
      break;
    case 'b':
      if ((uVar5 & 0xc000) == 0) {
        uVar5 = uVar5 | 0x8000;
        goto LAB_005532be;
      }
      break;
    case 'c':
      if (!bVar3) {
        bVar3 = true;
        uVar7 = uVar7 | 0x4000;
        goto LAB_005532be;
      }
      break;
    case 'n':
      if (!bVar3) {
        bVar3 = true;
        uVar7 = uVar7 & 0xffffbfff;
        goto LAB_005532be;
      }
      break;
    case 't':
      if ((uVar5 & 0xc000) == 0) {
        uVar5 = uVar5 | 0x4000;
        goto LAB_005532be;
      }
    }
    bVar2 = false;
LAB_005532be:
    param_2 = param_2 + 1;
    cVar1 = *param_2;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0055332b
// Address: 0055332b
undefined4 * __fastcall FUN_0055332b(uint *param_1)
{
  undefined1 *puVar1;
  uint *puVar2;
  undefined4 in_EAX;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  undefined3 uVar9;
  int *piVar8;
  undefined4 unaff_EBX;
  byte *unaff_EBP;
  undefined1 *unaff_ESI;
  int unaff_EDI;
  undefined4 *puVar10;
  
  uVar3 = CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(0x32,(char)in_EAX));
  unaff_EBP[-0x6fffaace] = unaff_EBP[-0x6fffaace] + (char)unaff_EBX;
  puVar2 = (uint *)(unaff_EDI + 2);
  *(char *)(unaff_EDI + 1) = (char)in_EAX;
  uVar9 = (undefined3)((uint)unaff_EBP >> 8);
  bVar7 = (byte)unaff_EBP ^ *unaff_EBP;
  puVar1 = unaff_ESI + 1;
  out(*unaff_ESI,(short)CONCAT31(uVar9,bVar7));
  bVar7 = bVar7 ^ *unaff_EBP;
  puVar4 = (uint *)CONCAT31(uVar9,bVar7);
  if ((char)bVar7 < '\x01') {
    puVar1[(int)puVar4 + 0x55] = puVar1[(int)puVar4 + 0x55] + '2';
    puVar1[(int)puVar4 + 0x9000055] = puVar1[(int)puVar4 + 0x9000055] + (char)((uint)unaff_EBX >> 8)
    ;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | uVar3;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *param_1 = *param_1 | (uint)param_1;
    *puVar4 = *puVar4 | uVar3;
  }
  iVar6 = *(int *)((int)param_1 * 2);
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  puVar4 = (uint *)(uVar3 + iVar6 + 0x9090906);
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *puVar2 = *puVar2 | (uint)puVar4;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *puVar4 = *puVar4 | (uint)param_1;
  puVar10 = (undefined4 *)0x0;
  iVar6 = 0;
  piVar8 = ___piob;
  if (0 < __nstream) {
    do {
      if (*piVar8 == 0) {
        iVar5 = malloc(0x20,puVar2,puVar1);
        ___piob[iVar6] = iVar5;
        if ((undefined4 *)___piob[iVar6] != (undefined4 *)0x0) {
          puVar10 = (undefined4 *)___piob[iVar6];
        }
        break;
      }
      if ((*(byte *)(*piVar8 + 0xc) & 0x83) == 0) {
        puVar10 = (undefined4 *)___piob[iVar6];
        break;
      }
      iVar6 = iVar6 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar6 < __nstream);
  }
  if (puVar10 != (undefined4 *)0x0) {
    puVar10[1] = 0;
    puVar10[3] = 0;
    puVar10[2] = 0;
    *puVar10 = 0;
    puVar10[7] = 0;
    puVar10[4] = 0xffffffff;
  }
  return puVar10;
}

// --------------------------------------------------

// Function: __getstream
// Address: 005533a0
undefined4 * __getstream(void)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  iVar2 = 0;
  piVar3 = ___piob;
  if (0 < __nstream) {
    do {
      if (*piVar3 == 0) {
        iVar1 = malloc(0x20);
        ___piob[iVar2] = iVar1;
        if ((undefined4 *)___piob[iVar2] != (undefined4 *)0x0) {
          puVar4 = (undefined4 *)___piob[iVar2];
        }
        break;
      }
      if ((*(byte *)(*piVar3 + 0xc) & 0x83) == 0) {
        puVar4 = (undefined4 *)___piob[iVar2];
        break;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < __nstream);
  }
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[1] = 0;
    puVar4[3] = 0;
    puVar4[2] = 0;
    *puVar4 = 0;
    puVar4[7] = 0;
    puVar4[4] = 0xffffffff;
  }
  return puVar4;
}

// --------------------------------------------------

// Function: FUN_00553424
// Address: 00553424
uint FUN_00553424(uint param_1,int *param_2)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  
  piVar4 = param_2;
  uVar1 = param_2[3];
  uVar2 = param_2[4];
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_00553550:
    param_2[3] = uVar1 | 0x20;
    return 0xffffffff;
  }
  iVar7 = 0;
  if ((uVar1 & 1) != 0) {
    param_2[1] = 0;
    if ((uVar1 & 0x10) == 0) goto LAB_00553550;
    *param_2 = param_2[2];
    param_2[3] = uVar1 & 0xfffffffe;
  }
  uVar1 = param_2[3];
  param_2[1] = 0;
  param_2[3] = uVar1 & 0xffffffef | 2;
  if ((uVar1 & 0x10c) == 0) {
    if ((param_2 == (int *)&DAT_00591e68) || (param_2 == (int *)&DAT_00591e88)) {
      iVar5 = __isatty(uVar2);
      if (iVar5 != 0) goto LAB_005534a3;
    }
    __getbuf(piVar4);
  }
LAB_005534a3:
  if ((piVar4[3] & 0x108U) == 0) {
    iVar5 = 1;
    iVar7 = write(uVar2,&param_1,1);
  }
  else {
    iVar3 = piVar4[2];
    iVar5 = *piVar4 - iVar3;
    *piVar4 = iVar3 + 1;
    piVar4[1] = piVar4[6] + -1;
    if (iVar5 < 1) {
      if (uVar2 == 0xffffffff) {
        puVar6 = &___badioinfo;
      }
      else {
        puVar6 = (undefined *)((&___pioinfo)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 8);
      }
      if ((puVar6[4] & 0x20) != 0) {
        lseek(uVar2,0,2);
      }
      *(undefined1 *)piVar4[2] = (undefined1)param_1;
    }
    else {
      iVar7 = write(uVar2,iVar3,iVar5);
      *(undefined1 *)piVar4[2] = (undefined1)param_1;
    }
  }
  if (iVar7 != iVar5) {
    piVar4[3] = piVar4[3] | 0x20;
    return 0xffffffff;
  }
  return param_1 & 0xff;
}

// --------------------------------------------------

// Function: __flsbuf
// Address: 00553430
uint __flsbuf(uint param_1,int *param_2)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  
  piVar4 = param_2;
  uVar1 = param_2[3];
  uVar2 = param_2[4];
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_00553550:
    param_2[3] = uVar1 | 0x20;
    return 0xffffffff;
  }
  iVar7 = 0;
  if ((uVar1 & 1) != 0) {
    param_2[1] = 0;
    if ((uVar1 & 0x10) == 0) goto LAB_00553550;
    *param_2 = param_2[2];
    param_2[3] = uVar1 & 0xfffffffe;
  }
  uVar1 = param_2[3];
  param_2[1] = 0;
  param_2[3] = uVar1 & 0xffffffef | 2;
  if ((uVar1 & 0x10c) == 0) {
    if ((param_2 == (int *)&DAT_00591e68) || (param_2 == (int *)&DAT_00591e88)) {
      iVar5 = __isatty(uVar2);
      if (iVar5 != 0) goto LAB_005534a3;
    }
    __getbuf(piVar4);
  }
LAB_005534a3:
  if ((piVar4[3] & 0x108U) == 0) {
    iVar5 = 1;
    iVar7 = write(uVar2,&param_1,1);
  }
  else {
    iVar3 = piVar4[2];
    iVar5 = *piVar4 - iVar3;
    *piVar4 = iVar3 + 1;
    piVar4[1] = piVar4[6] + -1;
    if (iVar5 < 1) {
      if (uVar2 == 0xffffffff) {
        puVar6 = &___badioinfo;
      }
      else {
        puVar6 = (undefined *)((&___pioinfo)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 8);
      }
      if ((puVar6[4] & 0x20) != 0) {
        lseek(uVar2,0,2);
      }
      *(undefined1 *)piVar4[2] = (undefined1)param_1;
    }
    else {
      iVar7 = write(uVar2,iVar3,iVar5);
      *(undefined1 *)piVar4[2] = (undefined1)param_1;
    }
  }
  if (iVar7 != iVar5) {
    piVar4[3] = piVar4[3] | 0x20;
    return 0xffffffff;
  }
  return param_1 & 0xff;
}

// --------------------------------------------------

// Function: FUN_0055355d
// Address: 0055355d
void FUN_0055355d(void)
{
  if (DAT_00888138 == 0) {
    __tzset();
    DAT_00888138 = DAT_00888138 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: ___tzset
// Address: 00553560
void ___tzset(void)
{
  if (DAT_00888138 == 0) {
    __tzset();
    DAT_00888138 = DAT_00888138 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00553575
// Address: 00553575
void FUN_00553575(void)
{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  
  DAT_00888080 = 0;
  DAT_00591e38 = 0xffffffff;
  DAT_00591e28 = 0xffffffff;
  pbVar3 = (byte *)getenv("TZ");
  if (pbVar3 == (byte *)0x0) {
    iVar4 = GetTimeZoneInformation(&DAT_00888088);
    if (iVar4 != -1) {
      DAT_00888080 = 1;
      __timezone = DAT_00888088 * 0x3c;
      if (DAT_008880ce != 0) {
        __timezone = __timezone + DAT_008880dc * 0x3c;
      }
      if ((DAT_00888122 == 0) || (DAT_00888130 == 0)) {
        __daylight = 0;
        __dstbias = 0;
      }
      else {
        __daylight = 1;
        __dstbias = (DAT_00888130 - DAT_008880dc) * 0x3c;
      }
      wcstombs(__tzname,&DAT_0088808c,0x40);
      wcstombs(PTR_DAT_00591e24,&DAT_008880e0,0x40);
      PTR_DAT_00591e24[0x3f] = 0;
      __tzname[0x3f] = 0;
      return;
    }
  }
  else if (*pbVar3 != 0) {
    pbVar7 = pbVar3;
    pbVar8 = DAT_00888134;
    if (DAT_00888134 != (byte *)0x0) {
      do {
        bVar1 = *pbVar7;
        bVar9 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_005536c3:
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_005536c8;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar7[1];
        bVar9 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_005536c3;
        pbVar7 = pbVar7 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_005536c8:
      if (iVar4 == 0) {
        return;
      }
    }
    free(DAT_00888134);
    uVar5 = 0xffffffff;
    pbVar7 = pbVar3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      bVar1 = *pbVar7;
      pbVar7 = pbVar7 + 1;
    } while (bVar1 != 0);
    DAT_00888134 = (byte *)malloc(~uVar5);
    if (DAT_00888134 != (byte *)0x0) {
      uVar5 = 0xffffffff;
      pbVar7 = pbVar3;
      do {
        pbVar8 = pbVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pbVar8 = pbVar7 + 1;
        bVar1 = *pbVar7;
        pbVar7 = pbVar8;
      } while (bVar1 != 0);
      uVar5 = ~uVar5;
      pbVar7 = pbVar8 + -uVar5;
      pbVar8 = DAT_00888134;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pbVar8 = *(undefined4 *)pbVar7;
        pbVar7 = pbVar7 + 4;
        pbVar8 = pbVar8 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pbVar8 = *pbVar7;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      }
      strncpy(__tzname,pbVar3,3);
      pbVar7 = pbVar3 + 3;
      __tzname[3] = 0;
      bVar1 = *pbVar7;
      if (bVar1 == 0x2d) {
        pbVar7 = pbVar3 + 4;
      }
      iVar4 = atol(pbVar7);
      __timezone = iVar4 * 0xe10;
      for (; (bVar2 = *pbVar7, bVar2 == 0x2b || (('/' < (char)bVar2 && ((char)bVar2 < ':'))));
          pbVar7 = pbVar7 + 1) {
      }
      if (*pbVar7 == 0x3a) {
        pbVar7 = pbVar7 + 1;
        iVar4 = atol(pbVar7);
        __timezone = __timezone + iVar4 * 0x3c;
        bVar2 = *pbVar7;
        while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
          pbVar3 = pbVar7 + 1;
          pbVar7 = pbVar7 + 1;
          bVar2 = *pbVar3;
        }
        if (*pbVar7 == 0x3a) {
          pbVar7 = pbVar7 + 1;
          iVar4 = atol(pbVar7);
          __timezone = __timezone + iVar4;
          bVar2 = *pbVar7;
          while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
            pbVar3 = pbVar7 + 1;
            pbVar7 = pbVar7 + 1;
            bVar2 = *pbVar3;
          }
        }
      }
      if (bVar1 == 0x2d) {
        __timezone = -__timezone;
      }
      __daylight = (int)(char)*pbVar7;
      if (__daylight != 0) {
        strncpy(PTR_DAT_00591e24,pbVar7,3);
        PTR_DAT_00591e24[3] = 0;
        return;
      }
      *PTR_DAT_00591e24 = 0;
    }
  }
  return;
}

// --------------------------------------------------

// Function: __tzset
// Address: 00553580
void __tzset(void)
{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  
  DAT_00888080 = 0;
  DAT_00591e38 = 0xffffffff;
  DAT_00591e28 = 0xffffffff;
  pbVar3 = (byte *)getenv("TZ");
  if (pbVar3 == (byte *)0x0) {
    iVar4 = GetTimeZoneInformation(&DAT_00888088);
    if (iVar4 != -1) {
      DAT_00888080 = 1;
      __timezone = DAT_00888088 * 0x3c;
      if (DAT_008880ce != 0) {
        __timezone = __timezone + DAT_008880dc * 0x3c;
      }
      if ((DAT_00888122 == 0) || (DAT_00888130 == 0)) {
        __daylight = 0;
        __dstbias = 0;
      }
      else {
        __daylight = 1;
        __dstbias = (DAT_00888130 - DAT_008880dc) * 0x3c;
      }
      wcstombs(__tzname,&DAT_0088808c,0x40);
      wcstombs(PTR_DAT_00591e24,&DAT_008880e0,0x40);
      PTR_DAT_00591e24[0x3f] = 0;
      __tzname[0x3f] = 0;
      return;
    }
  }
  else if (*pbVar3 != 0) {
    pbVar7 = pbVar3;
    pbVar8 = DAT_00888134;
    if (DAT_00888134 != (byte *)0x0) {
      do {
        bVar1 = *pbVar7;
        bVar9 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_005536c3:
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_005536c8;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar7[1];
        bVar9 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_005536c3;
        pbVar7 = pbVar7 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_005536c8:
      if (iVar4 == 0) {
        return;
      }
    }
    free(DAT_00888134);
    uVar5 = 0xffffffff;
    pbVar7 = pbVar3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      bVar1 = *pbVar7;
      pbVar7 = pbVar7 + 1;
    } while (bVar1 != 0);
    DAT_00888134 = (byte *)malloc(~uVar5);
    if (DAT_00888134 != (byte *)0x0) {
      uVar5 = 0xffffffff;
      pbVar7 = pbVar3;
      do {
        pbVar8 = pbVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pbVar8 = pbVar7 + 1;
        bVar1 = *pbVar7;
        pbVar7 = pbVar8;
      } while (bVar1 != 0);
      uVar5 = ~uVar5;
      pbVar7 = pbVar8 + -uVar5;
      pbVar8 = DAT_00888134;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pbVar8 = *(undefined4 *)pbVar7;
        pbVar7 = pbVar7 + 4;
        pbVar8 = pbVar8 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pbVar8 = *pbVar7;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      }
      strncpy(__tzname,pbVar3,3);
      pbVar7 = pbVar3 + 3;
      __tzname[3] = 0;
      bVar1 = *pbVar7;
      if (bVar1 == 0x2d) {
        pbVar7 = pbVar3 + 4;
      }
      iVar4 = atol(pbVar7);
      __timezone = iVar4 * 0xe10;
      for (; (bVar2 = *pbVar7, bVar2 == 0x2b || (('/' < (char)bVar2 && ((char)bVar2 < ':'))));
          pbVar7 = pbVar7 + 1) {
      }
      if (*pbVar7 == 0x3a) {
        pbVar7 = pbVar7 + 1;
        iVar4 = atol(pbVar7);
        __timezone = __timezone + iVar4 * 0x3c;
        bVar2 = *pbVar7;
        while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
          pbVar3 = pbVar7 + 1;
          pbVar7 = pbVar7 + 1;
          bVar2 = *pbVar3;
        }
        if (*pbVar7 == 0x3a) {
          pbVar7 = pbVar7 + 1;
          iVar4 = atol(pbVar7);
          __timezone = __timezone + iVar4;
          bVar2 = *pbVar7;
          while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
            pbVar3 = pbVar7 + 1;
            pbVar7 = pbVar7 + 1;
            bVar2 = *pbVar3;
          }
        }
      }
      if (bVar1 == 0x2d) {
        __timezone = -__timezone;
      }
      __daylight = (int)(char)*pbVar7;
      if (__daylight != 0) {
        strncpy(PTR_DAT_00591e24,pbVar7,3);
        PTR_DAT_00591e24[3] = 0;
        return;
      }
      *PTR_DAT_00591e24 = 0;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0055382b
// Address: 0055382b
bool FUN_0055382b(int *param_1)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  
  if (__daylight == 0) {
    return false;
  }
  iVar6 = param_1[5];
  if ((iVar6 == DAT_00591e28) && (iVar6 == DAT_00591e38)) goto LAB_00553a04;
  if (DAT_00888080 == 0) {
    FUN_00553aa0(1,1,iVar6,4,1,0,0,2,0,0,0);
    iVar6 = param_1[5];
    uVar8 = 0;
    uVar3 = 0;
    uVar10 = 0;
    uVar4 = 2;
    uVar1 = 0;
    uVar9 = 5;
    uVar7 = 10;
LAB_005539f8:
    uVar5 = 1;
    uVar11 = 0;
  }
  else {
    if (DAT_00888120 != 0) {
      uVar3 = 0;
      uVar8 = 0;
      uVar10 = DAT_00888124._2_2_;
    }
    else {
      uVar3 = DAT_00888124 & 0xffff;
      uVar8 = DAT_00888124._2_2_;
      uVar10 = 0;
    }
    FUN_00553aa0(1,DAT_00888120 == 0,iVar6,DAT_00888122,uVar8,uVar3,uVar10,DAT_00888128 & 0xffff,
                 DAT_00888128 >> 0x10,DAT_0088812c & 0xffff,DAT_0088812c >> 0x10);
    uVar8 = DAT_008880d8._2_2_;
    uVar10 = DAT_008880d4._2_2_;
    uVar7 = DAT_008880ce;
    if (DAT_008880cc == 0) {
      uVar3 = DAT_008880d8 & 0xffff;
      uVar4 = DAT_008880d4 & 0xffff;
      uVar1 = DAT_008880d0 & 0xffff;
      iVar6 = param_1[5];
      uVar9 = DAT_008880d0._2_2_;
      goto LAB_005539f8;
    }
    uVar3 = DAT_008880d8 & 0xffff;
    uVar4 = DAT_008880d4 & 0xffff;
    iVar6 = param_1[5];
    uVar1 = 0;
    uVar9 = 0;
    uVar5 = 0;
    uVar11 = DAT_008880d0._2_2_;
  }
  FUN_00553aa0(0,uVar5,iVar6,uVar7,uVar9,uVar1,uVar11,uVar4,uVar10,uVar3,uVar8);
LAB_00553a04:
  iVar6 = param_1[7];
  if (DAT_00591e2c < DAT_00591e3c) {
    if ((iVar6 < DAT_00591e2c) || (DAT_00591e3c < iVar6)) {
      return false;
    }
    if ((DAT_00591e2c < iVar6) && (iVar6 < DAT_00591e3c)) {
      return true;
    }
  }
  else {
    if ((iVar6 < DAT_00591e3c) || (DAT_00591e2c < iVar6)) {
      return true;
    }
    if ((DAT_00591e3c < iVar6) && (iVar6 < DAT_00591e2c)) {
      return false;
    }
  }
  iVar2 = (*param_1 + (param_1[1] + param_1[2] * 0x3c) * 0x3c) * 1000;
  if (iVar6 != DAT_00591e2c) {
    return iVar2 < DAT_00591e40;
  }
  return DAT_00591e30 <= iVar2;
}

// --------------------------------------------------

// Function: __isindst
// Address: 00553830
bool __isindst(int *param_1)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  
  if (__daylight == 0) {
    return false;
  }
  iVar6 = param_1[5];
  if ((iVar6 == DAT_00591e28) && (iVar6 == DAT_00591e38)) goto LAB_00553a04;
  if (DAT_00888080 == 0) {
    FUN_00553aa0(1,1,iVar6,4,1,0,0,2,0,0,0);
    iVar6 = param_1[5];
    uVar8 = 0;
    uVar3 = 0;
    uVar10 = 0;
    uVar4 = 2;
    uVar1 = 0;
    uVar9 = 5;
    uVar7 = 10;
LAB_005539f8:
    uVar5 = 1;
    uVar11 = 0;
  }
  else {
    if (DAT_00888120 != 0) {
      uVar3 = 0;
      uVar8 = 0;
      uVar10 = DAT_00888124._2_2_;
    }
    else {
      uVar3 = DAT_00888124 & 0xffff;
      uVar8 = DAT_00888124._2_2_;
      uVar10 = 0;
    }
    FUN_00553aa0(1,DAT_00888120 == 0,iVar6,DAT_00888122,uVar8,uVar3,uVar10,DAT_00888128 & 0xffff,
                 DAT_00888128 >> 0x10,DAT_0088812c & 0xffff,DAT_0088812c >> 0x10);
    uVar8 = DAT_008880d8._2_2_;
    uVar10 = DAT_008880d4._2_2_;
    uVar7 = DAT_008880ce;
    if (DAT_008880cc == 0) {
      uVar3 = DAT_008880d8 & 0xffff;
      uVar4 = DAT_008880d4 & 0xffff;
      uVar1 = DAT_008880d0 & 0xffff;
      iVar6 = param_1[5];
      uVar9 = DAT_008880d0._2_2_;
      goto LAB_005539f8;
    }
    uVar3 = DAT_008880d8 & 0xffff;
    uVar4 = DAT_008880d4 & 0xffff;
    iVar6 = param_1[5];
    uVar1 = 0;
    uVar9 = 0;
    uVar5 = 0;
    uVar11 = DAT_008880d0._2_2_;
  }
  FUN_00553aa0(0,uVar5,iVar6,uVar7,uVar9,uVar1,uVar11,uVar4,uVar10,uVar3,uVar8);
LAB_00553a04:
  iVar6 = param_1[7];
  if (DAT_00591e2c < DAT_00591e3c) {
    if ((iVar6 < DAT_00591e2c) || (DAT_00591e3c < iVar6)) {
      return false;
    }
    if ((DAT_00591e2c < iVar6) && (iVar6 < DAT_00591e3c)) {
      return true;
    }
  }
  else {
    if ((iVar6 < DAT_00591e3c) || (DAT_00591e2c < iVar6)) {
      return true;
    }
    if ((DAT_00591e3c < iVar6) && (iVar6 < DAT_00591e2c)) {
      return false;
    }
  }
  iVar2 = (*param_1 + (param_1[1] + param_1[2] * 0x3c) * 0x3c) * 1000;
  if (iVar6 != DAT_00591e2c) {
    return iVar2 < DAT_00591e40;
  }
  return DAT_00591e30 <= iVar2;
}

// --------------------------------------------------

// Function: FUN_00553a99
// Address: 00553a99
void FUN_00553a99(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10,int param_11)
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_005923e4 + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_0059241c + param_4 * 4);
    }
    iVar2 = (int)(((int)(param_3 - 1) >> 2) + -0x63db + param_3 * 0x16d + iVar1 + 1) % 7;
    if (iVar2 < param_6) {
      iVar1 = iVar1 + -6 + (param_5 * 7 - iVar2) + param_6;
    }
    else {
      iVar1 = iVar1 + 1 + (param_5 * 7 - iVar2) + param_6;
    }
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        iVar2 = *(int *)(&__lpdays + param_4 * 4);
      }
      else {
        iVar2 = (&__days)[param_4];
      }
      if (iVar2 < iVar1) {
        iVar1 = iVar1 + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_005923e4 + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_0059241c + param_4 * 4);
    }
    iVar1 = iVar1 + param_7;
  }
  if (param_1 == 1) {
    DAT_00591e2c = iVar1;
    DAT_00591e28 = param_3;
    DAT_00591e30 = param_11 + (param_10 + (param_9 + param_8 * 0x3c) * 0x3c) * 1000;
    return;
  }
  DAT_00591e3c = iVar1;
  DAT_00591e40 = param_11 + (param_10 + (param_9 + param_8 * 0x3c) * 0x3c + __dstbias) * 1000;
  if (DAT_00591e40 < 0) {
    DAT_00591e38 = param_3;
    DAT_00591e40 = DAT_00591e40 + 86399999;
    return;
  }
  if (86399999 < DAT_00591e40) {
    DAT_00591e40 = DAT_00591e40 + -86399999;
  }
  DAT_00591e38 = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00553aa0
// Address: 00553aa0
void FUN_00553aa0(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10,int param_11)
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_005923e4 + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_0059241c + param_4 * 4);
    }
    iVar2 = (int)(((int)(param_3 - 1) >> 2) + -0x63db + param_3 * 0x16d + iVar1 + 1) % 7;
    if (iVar2 < param_6) {
      iVar1 = iVar1 + -6 + (param_5 * 7 - iVar2) + param_6;
    }
    else {
      iVar1 = iVar1 + 1 + (param_5 * 7 - iVar2) + param_6;
    }
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        iVar2 = *(int *)(&__lpdays + param_4 * 4);
      }
      else {
        iVar2 = (&__days)[param_4];
      }
      if (iVar2 < iVar1) {
        iVar1 = iVar1 + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_005923e4 + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_0059241c + param_4 * 4);
    }
    iVar1 = iVar1 + param_7;
  }
  if (param_1 == 1) {
    DAT_00591e2c = iVar1;
    DAT_00591e28 = param_3;
    DAT_00591e30 = param_11 + (param_10 + (param_9 + param_8 * 0x3c) * 0x3c) * 1000;
    return;
  }
  DAT_00591e3c = iVar1;
  DAT_00591e40 = param_11 + (param_10 + (param_9 + param_8 * 0x3c) * 0x3c + __dstbias) * 1000;
  if (DAT_00591e40 < 0) {
    DAT_00591e38 = param_3;
    DAT_00591e40 = DAT_00591e40 + 86399999;
    return;
  }
  if (86399999 < DAT_00591e40) {
    DAT_00591e40 = DAT_00591e40 + -86399999;
  }
  DAT_00591e38 = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00553c3c
// Address: 00553c3c
undefined4 FUN_00553c3c(int *param_1)
{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  bVar1 = false;
  iVar5 = *param_1;
  if (-1 < iVar5) {
    iVar3 = iVar5 % 0x7861f80;
    iVar5 = (iVar5 / 0x7861f80) * 4;
    UNK_0088813c._24_4_ = iVar5 + 0x46;
    iVar4 = iVar3;
    if (0x1e1337f < iVar3) {
      iVar4 = iVar3 + -0x1e13380;
      UNK_0088813c._24_4_ = iVar5 + 0x47;
      if (0x1e1337f < iVar4) {
        iVar4 = iVar3 + -0x3c26700;
        UNK_0088813c._24_4_ = iVar5 + 0x48;
        if (iVar4 < 0x1e28500) {
          bVar1 = true;
        }
        else {
          UNK_0088813c._24_4_ = iVar5 + 0x49;
          iVar4 = iVar3 + -0x5a4ec00;
        }
      }
    }
    puVar6 = (undefined4 *)&__lpdays;
    UNK_0088813c._32_4_ = iVar4 / 0x15180;
    if (!bVar1) {
      puVar6 = &__days;
    }
    iVar3 = 1;
    iVar5 = puVar6[1];
    puVar2 = puVar6;
    while (iVar5 < (int)UNK_0088813c._32_4_) {
      iVar3 = iVar3 + 1;
      iVar5 = puVar2[2];
      puVar2 = puVar2 + 1;
    }
    UNK_0088813c._20_4_ = iVar3 + -1;
    UNK_0088813c._16_4_ = UNK_0088813c._32_4_ - puVar6[iVar3 + -1];
    UNK_0088813c._36_4_ = 0;
    UNK_0088813c._28_4_ = (*param_1 / 0x15180 + 4) % 7;
    UNK_0088813c._12_4_ = (iVar4 % 0x15180) / 0xe10;
    iVar5 = (iVar4 % 0x15180) % 0xe10;
    UNK_0088813c._8_4_ = iVar5 / 0x3c;
    UNK_0088813c._4_4_ = iVar5 % 0x3c;
    return 0x888140;
  }
  return 0;
}

// --------------------------------------------------

// Function: gmtime
// Address: 00553c40
/* gmtime */

undefined4 __cdecl gmtime(int *param_1)
{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  bVar1 = false;
  iVar5 = *param_1;
  if (-1 < iVar5) {
    iVar3 = iVar5 % 0x7861f80;
    iVar5 = (iVar5 / 0x7861f80) * 4;
    UNK_0088813c._24_4_ = iVar5 + 0x46;
    iVar4 = iVar3;
    if (0x1e1337f < iVar3) {
      iVar4 = iVar3 + -0x1e13380;
      UNK_0088813c._24_4_ = iVar5 + 0x47;
      if (0x1e1337f < iVar4) {
        iVar4 = iVar3 + -0x3c26700;
        UNK_0088813c._24_4_ = iVar5 + 0x48;
        if (iVar4 < 0x1e28500) {
          bVar1 = true;
        }
        else {
          UNK_0088813c._24_4_ = iVar5 + 0x49;
          iVar4 = iVar3 + -0x5a4ec00;
        }
      }
    }
    puVar6 = (undefined4 *)&__lpdays;
    UNK_0088813c._32_4_ = iVar4 / 0x15180;
    if (!bVar1) {
      puVar6 = &__days;
    }
    iVar3 = 1;
    iVar5 = puVar6[1];
    puVar2 = puVar6;
    while (iVar5 < (int)UNK_0088813c._32_4_) {
      iVar3 = iVar3 + 1;
      iVar5 = puVar2[2];
      puVar2 = puVar2 + 1;
    }
    UNK_0088813c._20_4_ = iVar3 + -1;
    UNK_0088813c._16_4_ = UNK_0088813c._32_4_ - puVar6[iVar3 + -1];
    UNK_0088813c._36_4_ = 0;
    UNK_0088813c._28_4_ = (*param_1 / 0x15180 + 4) % 7;
    UNK_0088813c._12_4_ = (iVar4 % 0x15180) / 0xe10;
    iVar5 = (iVar4 % 0x15180) % 0xe10;
    UNK_0088813c._8_4_ = iVar5 / 0x3c;
    UNK_0088813c._4_4_ = iVar5 % 0x3c;
    return 0x888140;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00553d9c
// Address: 00553d9c
int FUN_00553d9c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7
                )
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_24 [8];
  int iStack_1c;
  int iStack_14;
  uint uStack_10;
  int iStack_8;
  
  uVar3 = param_1 - 0x76c;
  if (((int)uVar3 < 0x46) || (0x8a < (int)uVar3)) {
    return -1;
  }
  param_3 = *(int *)(&DAT_0059241c + param_2 * 4) + param_3;
  if (((uVar3 & 3) == 0) && (2 < param_2)) {
    param_3 = param_3 + 1;
  }
  ___tzset();
  iStack_1c = param_4;
  iStack_14 = param_2 + -1;
  iVar1 = param_6 + (param_5 +
                    (param_4 + ((param_1 + -0x76d >> 2) + uVar3 * 0x16d + param_3) * 0x18) * 0x3c) *
                    0x3c + 0x7c558180 + __timezone;
  if (param_7 != 1) {
    if (param_7 != -1) {
      return iVar1;
    }
    if (__daylight == 0) {
      return iVar1;
    }
    uStack_10 = uVar3;
    iStack_8 = param_3;
    iVar2 = __isindst(auStack_24);
    if (iVar2 == 0) {
      return iVar1;
    }
  }
  return iVar1 + __dstbias;
}

// --------------------------------------------------

// Function: ___loctotime_t
// Address: 00553da0
int ___loctotime_t(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_24 [8];
  int local_1c;
  int local_14;
  uint local_10;
  int local_8;
  
  uVar3 = param_1 - 0x76c;
  if (((int)uVar3 < 0x46) || (0x8a < (int)uVar3)) {
    return -1;
  }
  param_3 = *(int *)(&DAT_0059241c + param_2 * 4) + param_3;
  if (((uVar3 & 3) == 0) && (2 < param_2)) {
    param_3 = param_3 + 1;
  }
  ___tzset();
  local_1c = param_4;
  local_14 = param_2 + -1;
  iVar1 = param_6 + (param_5 +
                    (param_4 + ((param_1 + -0x76d >> 2) + uVar3 * 0x16d + param_3) * 0x18) * 0x3c) *
                    0x3c + 0x7c558180 + __timezone;
  if (param_7 != 1) {
    if (param_7 != -1) {
      return iVar1;
    }
    if (__daylight == 0) {
      return iVar1;
    }
    local_10 = uVar3;
    local_8 = param_3;
    iVar2 = __isindst(local_24);
    if (iVar2 == 0) {
      return iVar1;
    }
  }
  return iVar1 + __dstbias;
}

// --------------------------------------------------

// Function: FUN_00553e82
// Address: 00553e82
undefined4 FUN_00553e82(uint param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = __doserrno;
  if ((param_1 < __nhandle) &&
     ((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    uVar1 = __get_osfhandle(param_1);
    iVar2 = FlushFileBuffers(uVar1);
    if (iVar2 == 0) {
      iVar2 = GetLastError();
    }
    else {
      iVar2 = 0;
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
  __doserrno = iVar2;
  _errno = 9;
  return 0xffffffff;
}

// --------------------------------------------------

// Function: __commit
// Address: 00553e90
undefined4 __commit(uint param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = __doserrno;
  if ((param_1 < __nhandle) &&
     ((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    uVar1 = __get_osfhandle(param_1);
    iVar2 = FlushFileBuffers(uVar1);
    if (iVar2 == 0) {
      iVar2 = GetLastError();
    }
    else {
      iVar2 = 0;
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
  __doserrno = iVar2;
  _errno = 9;
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00553eeb
// Address: 00553eeb
void FUN_00553eeb(void)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (__nstream == 0) {
    __nstream = 0x200;
  }
  else if (__nstream < 0x14) {
    __nstream = 0x14;
  }
  ___piob = calloc(__nstream,4);
  if (___piob == 0) {
    __nstream = 0x14;
    ___piob = calloc(0x14,4);
    if (___piob == 0) {
      __amsg_exit(0x1a);
    }
  }
  iVar3 = 0;
  iVar2 = 0x591e48;
  do {
    *(int *)(___piob + iVar3) = iVar2;
    iVar2 = iVar2 + 0x20;
    iVar3 = iVar3 + 4;
  } while (iVar2 < 0x5920c8);
  uVar1 = 0;
  puVar4 = &DAT_00591e58;
  do {
    iVar2 = *(int *)((&___pioinfo)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 8);
    if ((iVar2 == -1) || (iVar2 == 0)) {
      *puVar4 = 0xffffffff;
    }
    puVar4 = puVar4 + 8;
    uVar1 = uVar1 + 1;
  } while ((int)puVar4 < 0x591eb8);
  return;
}

// --------------------------------------------------

// Function: FUN_00553fa9
// Address: 00553fa9
char FUN_00553fa9(void)
{
  int iVar1;
  int iVar2;
  char cVar3;
  
  __flushall();
  if (__wpgmptr._4_1_ == '\0') {
    return __wpgmptr._4_1_;
  }
  iVar2 = 3;
  cVar3 = '\0';
  if (3 < __nstream) {
    do {
      iVar1 = *(int *)(___piob + iVar2 * 4);
      if (iVar1 != 0) {
        if (((*(byte *)(iVar1 + 0xc) & 0x83) != 0) && (iVar1 = fclose(iVar1), iVar1 != -1)) {
          cVar3 = cVar3 + '\x01';
        }
        if (0x13 < iVar2) {
          free(*(undefined4 *)(___piob + iVar2 * 4));
          *(undefined4 *)(___piob + iVar2 * 4) = 0;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < __nstream);
  }
  return cVar3;
}

// --------------------------------------------------

// Function: FUN_00553fc4
// Address: 00553fc4
void FUN_00553fc4(void)
{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  uint uVar7;
  byte *pbVar8;
  int iStack_48;
  undefined1 auStack_44 [50];
  short sStack_12;
  int *piStack_10;
  
  puVar2 = (undefined4 *)malloc(0x100);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  __nhandle = 0x20;
  ___pioinfo = puVar2;
  if (puVar2 < puVar2 + 0x40) {
    do {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar2 = puVar2 + 2;
    } while (puVar2 < ___pioinfo + 0x40);
  }
  GetStartupInfoA(auStack_44);
  if ((sStack_12 != 0) && (piStack_10 != (int *)0x0)) {
    iStack_48 = *piStack_10;
    pbVar8 = (byte *)(piStack_10 + 1);
    pbVar5 = pbVar8 + iStack_48;
    if (0x7ff < iStack_48) {
      iStack_48 = 0x800;
    }
    if (__nhandle < iStack_48) {
      piVar6 = &DAT_008884e4;
      do {
        puVar2 = (undefined4 *)malloc(0x100);
        if (puVar2 == (undefined4 *)0x0) {
          iStack_48 = __nhandle;
          break;
        }
        *piVar6 = (int)puVar2;
        __nhandle = __nhandle + 0x20;
        if (puVar2 < puVar2 + 0x40) {
          do {
            *(undefined1 *)(puVar2 + 1) = 0;
            *puVar2 = 0xffffffff;
            *(undefined1 *)((int)puVar2 + 5) = 10;
            puVar2 = puVar2 + 2;
          } while (puVar2 < (undefined4 *)(*piVar6 + 0x100));
        }
        piVar6 = piVar6 + 1;
      } while (__nhandle < iStack_48);
    }
    uVar7 = 0;
    if (0 < iStack_48) {
      do {
        if (((*(int *)pbVar5 != -1) && ((*pbVar8 & 1) != 0)) &&
           (((*pbVar8 & 8) != 0 || (iVar3 = GetFileType(*(int *)pbVar5), iVar3 != 0)))) {
          iVar3 = (int)(&___pioinfo)[(int)uVar7 >> 5];
          *(undefined4 *)(iVar3 + (uVar7 & 0x1f) * 8) = *(undefined4 *)pbVar5;
          *(byte *)(iVar3 + (uVar7 & 0x1f) * 8 + 4) = *pbVar8;
        }
        uVar7 = uVar7 + 1;
        pbVar8 = pbVar8 + 1;
        pbVar5 = pbVar5 + 4;
      } while ((int)uVar7 < iStack_48);
    }
  }
  iVar3 = 0;
  do {
    piVar6 = ___pioinfo + iVar3 * 2;
    if (___pioinfo[iVar3 * 2] == -1) {
      *(undefined1 *)(piVar6 + 1) = 0x81;
      if (iVar3 == 0) {
        iVar4 = -10;
      }
      else {
        iVar4 = -0xb - (uint)(iVar3 != 1);
      }
      iVar4 = GetStdHandle(iVar4);
      if ((iVar4 == -1) || (uVar7 = GetFileType(iVar4), uVar7 == 0)) {
        bVar1 = *(byte *)(piVar6 + 1) | 0x40;
        goto LAB_005541ab;
      }
      *piVar6 = iVar4;
      if ((uVar7 & 0xff) == 2) {
        bVar1 = *(byte *)(piVar6 + 1) | 0x40;
        goto LAB_005541ab;
      }
      if ((uVar7 & 0xff) == 3) {
        bVar1 = *(byte *)(piVar6 + 1) | 8;
        goto LAB_005541ab;
      }
    }
    else {
      bVar1 = *(byte *)(piVar6 + 1) | 0x80;
LAB_005541ab:
      *(byte *)(piVar6 + 1) = bVar1;
    }
    iVar3 = iVar3 + 1;
    if (2 < iVar3) {
      SetHandleCount(__nhandle);
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: __ioinit
// Address: 00553fd0
void __ioinit(void)
{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  uint uVar7;
  byte *pbVar8;
  int iStack_48;
  undefined1 local_44 [50];
  short sStack_12;
  int *piStack_10;
  
  puVar2 = (undefined4 *)malloc(0x100);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  __nhandle = 0x20;
  ___pioinfo = puVar2;
  if (puVar2 < puVar2 + 0x40) {
    do {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar2 = puVar2 + 2;
    } while (puVar2 < ___pioinfo + 0x40);
  }
  GetStartupInfoA(local_44);
  if ((sStack_12 != 0) && (piStack_10 != (int *)0x0)) {
    iStack_48 = *piStack_10;
    pbVar8 = (byte *)(piStack_10 + 1);
    pbVar5 = pbVar8 + iStack_48;
    if (0x7ff < iStack_48) {
      iStack_48 = 0x800;
    }
    if (__nhandle < iStack_48) {
      piVar6 = &DAT_008884e4;
      do {
        puVar2 = (undefined4 *)malloc(0x100);
        if (puVar2 == (undefined4 *)0x0) {
          iStack_48 = __nhandle;
          break;
        }
        *piVar6 = (int)puVar2;
        __nhandle = __nhandle + 0x20;
        if (puVar2 < puVar2 + 0x40) {
          do {
            *(undefined1 *)(puVar2 + 1) = 0;
            *puVar2 = 0xffffffff;
            *(undefined1 *)((int)puVar2 + 5) = 10;
            puVar2 = puVar2 + 2;
          } while (puVar2 < (undefined4 *)(*piVar6 + 0x100));
        }
        piVar6 = piVar6 + 1;
      } while (__nhandle < iStack_48);
    }
    uVar7 = 0;
    if (0 < iStack_48) {
      do {
        if (((*(int *)pbVar5 != -1) && ((*pbVar8 & 1) != 0)) &&
           (((*pbVar8 & 8) != 0 || (iVar3 = GetFileType(*(int *)pbVar5), iVar3 != 0)))) {
          iVar3 = (int)(&___pioinfo)[(int)uVar7 >> 5];
          *(undefined4 *)(iVar3 + (uVar7 & 0x1f) * 8) = *(undefined4 *)pbVar5;
          *(byte *)(iVar3 + (uVar7 & 0x1f) * 8 + 4) = *pbVar8;
        }
        uVar7 = uVar7 + 1;
        pbVar8 = pbVar8 + 1;
        pbVar5 = pbVar5 + 4;
      } while ((int)uVar7 < iStack_48);
    }
  }
  iVar3 = 0;
  do {
    piVar6 = ___pioinfo + iVar3 * 2;
    if (___pioinfo[iVar3 * 2] == -1) {
                    /* language.dll match for 0x81: "10" */
      *(undefined1 *)(piVar6 + 1) = 0x81;
      if (iVar3 == 0) {
        iVar4 = -10;
      }
      else {
        iVar4 = -0xb - (uint)(iVar3 != 1);
      }
      iVar4 = GetStdHandle(iVar4);
      if ((iVar4 == -1) || (uVar7 = GetFileType(iVar4), uVar7 == 0)) {
        bVar1 = *(byte *)(piVar6 + 1) | 0x40;
        goto LAB_005541ab;
      }
      *piVar6 = iVar4;
      if ((uVar7 & 0xff) == 2) {
        bVar1 = *(byte *)(piVar6 + 1) | 0x40;
        goto LAB_005541ab;
      }
      if ((uVar7 & 0xff) == 3) {
        bVar1 = *(byte *)(piVar6 + 1) | 8;
        goto LAB_005541ab;
      }
    }
    else {
      bVar1 = *(byte *)(piVar6 + 1) | 0x80;
LAB_005541ab:
      *(byte *)(piVar6 + 1) = bVar1;
    }
    iVar3 = iVar3 + 1;
    if (2 < iVar3) {
      SetHandleCount(__nhandle);
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_005541c8
// Address: 005541c8
void FUN_005541c8(void)
{
  int *piVar1;
  
  piVar1 = &___pioinfo;
  do {
    if (*piVar1 != 0) {
      free(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x8885e0);
  return;
}

// --------------------------------------------------

// Function: FUN_005541f8
// Address: 005541f8
uint FUN_005541f8(int param_1,uint param_2)
{
  undefined4 uVar1;
  int iVar2;
  uint uStack_4;
  
  iVar2 = param_1;
  if (param_1 + 1U < 0x101) {
    return *(ushort *)(__pctype + param_1 * 2) & param_2;
  }
  if ((__pctype[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
    param_1._0_2_ = (ushort)(byte)param_1;
    uVar1 = 1;
  }
  else {
    param_1._0_2_ = CONCAT11((byte)param_1,(char)((uint)param_1 >> 8));
    param_1._3_1_ = SUB41(iVar2,3);
    param_1._0_3_ = (uint3)(ushort)param_1;
    uVar1 = 2;
  }
  iVar2 = ___crtGetStringTypeA(1,&param_1,uVar1,&uStack_4,0,0);
  if (iVar2 == 0) {
    return 0;
  }
  return uStack_4 & 0xffff & param_2;
}

// --------------------------------------------------

// Function: __isctype
// Address: 00554200
uint __isctype(int param_1,uint param_2)
{
  undefined4 uVar1;
  int iVar2;
  uint local_4;
  
  iVar2 = param_1;
  if (param_1 + 1U < 0x101) {
    return *(ushort *)(__pctype + param_1 * 2) & param_2;
  }
  if ((__pctype[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
    param_1._0_2_ = (ushort)(byte)param_1;
    uVar1 = 1;
  }
  else {
    param_1._0_2_ = CONCAT11((byte)param_1,(char)((uint)param_1 >> 8));
    param_1._3_1_ = SUB41(iVar2,3);
    param_1._0_3_ = (uint3)(ushort)param_1;
    uVar1 = 2;
  }
  iVar2 = ___crtGetStringTypeA(1,&param_1,uVar1,&local_4,0,0);
  if (iVar2 == 0) {
    return 0;
  }
  return local_4 & 0xffff & param_2;
}

// --------------------------------------------------

// Function: FUN_00554293
// Address: 00554293
longlong FUN_00554293(uint param_1,int param_2,uint param_3,int param_4)
{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}

// --------------------------------------------------

// Function: __allmul
// Address: 005542a0
longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)
{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}

// --------------------------------------------------

// Function: __mbsbtype
// Address: 005542e0
undefined4 __mbsbtype(char *param_1,int param_2)
{
  char cVar1;
  undefined4 uVar2;
  
  if (___mbcodepage == 0) {
    return 0;
  }
  uVar2 = 0xffffffff;
  cVar1 = *param_1;
  while( true ) {
    if (cVar1 == '\0') {
      return 0xffffffff;
    }
    param_1 = param_1 + 1;
    uVar2 = __mbbtype(cVar1,uVar2);
    if (param_2 == 0) break;
    cVar1 = *param_1;
    param_2 = param_2 + -1;
  }
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_0055431f
// Address: 0055431f
undefined4 FUN_0055431f(undefined4 param_1)
{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  undefined4 unaff_EBX;
  uint unaff_EBP;
  byte *pbVar11;
  undefined4 *puVar12;
  byte abStack_14 [20];
  
  iVar4 = FUN_00554510(param_1);
  if (iVar4 == ___mbcodepage) {
    return 0;
  }
  if (iVar4 == 0) {
    FUN_005545c0();
    return 0;
  }
  iVar9 = 0;
  piVar5 = &DAT_005922f8;
  do {
    if (*piVar5 == iVar4) {
      puVar12 = &__mbctype;
      for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
      }
      *(undefined1 *)puVar12 = 0;
      uVar6 = 0;
      iVar9 = iVar9 * 0x30;
      pbVar10 = (byte *)(iVar9 + 0x592308);
      do {
        bVar2 = *pbVar10;
        for (pbVar11 = pbVar10; (bVar2 != 0 && (bVar2 = pbVar11[1], bVar2 != 0));
            pbVar11 = pbVar11 + 2) {
          uVar7 = (uint)*pbVar11;
          if (uVar7 <= bVar2) {
            bVar3 = (&DAT_005922f0)[uVar6];
            do {
              pbVar1 = (byte *)((int)&__mbctype + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar3;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= bVar2);
          }
          bVar2 = pbVar11[2];
        }
        uVar6 = uVar6 + 1;
        pbVar10 = pbVar10 + 8;
      } while (uVar6 < 4);
      ___mbcodepage = iVar4;
      ___mblcid = FUN_00554560(iVar4);
      UNK_00888274._4_4_ = *(undefined4 *)(iVar9 + 0x5922fc);
      UNK_00888274._8_4_ = *(undefined4 *)(iVar9 + 0x592300);
      UNK_00888274._12_4_ = *(undefined4 *)(iVar9 + 0x592304);
      return 0;
    }
    piVar5 = piVar5 + 0xc;
    iVar9 = iVar9 + 1;
  } while (piVar5 < &__lpdays);
  iVar9 = GetCPInfo(iVar4,abStack_14);
  if (iVar9 != 1) {
    if (DAT_00888284 == 0) {
      return 0xffffffff;
    }
    FUN_005545c0();
    return 0;
  }
  puVar12 = &__mbctype;
  for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  *(undefined1 *)puVar12 = 0;
  if (unaff_EBP < 2) {
    ___mbcodepage = 0;
    ___mblcid = 0;
  }
  else {
    if ((char)((uint)unaff_EBX >> 0x10) != '\0') {
      pbVar10 = &stack0xffffffeb;
      do {
        bVar2 = *pbVar10;
        if (bVar2 == 0) break;
        for (uVar6 = (uint)pbVar10[-1]; uVar6 <= bVar2; uVar6 = uVar6 + 1) {
          *(byte *)((int)&__mbctype + uVar6 + 1) = *(byte *)((int)&__mbctype + uVar6 + 1) | 4;
        }
        pbVar11 = pbVar10 + 1;
        pbVar10 = pbVar10 + 2;
      } while (*pbVar11 != 0);
    }
    uVar6 = 1;
    do {
      *(byte *)((int)&__mbctype + uVar6 + 1) = *(byte *)((int)&__mbctype + uVar6 + 1) | 8;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0xff);
    ___mbcodepage = iVar4;
    ___mblcid = FUN_00554560(iVar4);
  }
  UNK_00888274._4_4_ = 0;
  UNK_00888274._8_4_ = 0;
  UNK_00888274._12_4_ = 0;
  return 0;
}

// --------------------------------------------------

// Function: __setmbcp
// Address: 00554320
undefined4 __setmbcp(undefined4 param_1)
{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  undefined4 unaff_EBX;
  uint unaff_EBP;
  byte *pbVar11;
  undefined4 *puVar12;
  byte local_14 [20];
  
  iVar4 = FUN_00554510(param_1);
  if (iVar4 == ___mbcodepage) {
    return 0;
  }
  if (iVar4 == 0) {
    FUN_005545c0();
    return 0;
  }
  iVar9 = 0;
  piVar5 = &DAT_005922f8;
  do {
    if (*piVar5 == iVar4) {
      puVar12 = &__mbctype;
      for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
      }
      *(undefined1 *)puVar12 = 0;
      uVar6 = 0;
      iVar9 = iVar9 * 0x30;
      pbVar10 = (byte *)(iVar9 + 0x592308);
      do {
        bVar2 = *pbVar10;
        for (pbVar11 = pbVar10; (bVar2 != 0 && (bVar2 = pbVar11[1], bVar2 != 0));
            pbVar11 = pbVar11 + 2) {
          uVar7 = (uint)*pbVar11;
          if (uVar7 <= bVar2) {
            bVar3 = (&DAT_005922f0)[uVar6];
            do {
              pbVar1 = (byte *)((int)&__mbctype + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar3;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= bVar2);
          }
          bVar2 = pbVar11[2];
        }
        uVar6 = uVar6 + 1;
        pbVar10 = pbVar10 + 8;
      } while (uVar6 < 4);
      ___mbcodepage = iVar4;
      ___mblcid = FUN_00554560(iVar4);
      UNK_00888274._4_4_ = *(undefined4 *)(iVar9 + 0x5922fc);
      UNK_00888274._8_4_ = *(undefined4 *)(iVar9 + 0x592300);
      UNK_00888274._12_4_ = *(undefined4 *)(iVar9 + 0x592304);
      return 0;
    }
    piVar5 = piVar5 + 0xc;
    iVar9 = iVar9 + 1;
  } while (piVar5 < &__lpdays);
  iVar9 = GetCPInfo(iVar4,local_14);
  if (iVar9 != 1) {
    if (DAT_00888284 == 0) {
      return 0xffffffff;
    }
    FUN_005545c0();
    return 0;
  }
  puVar12 = &__mbctype;
  for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  *(undefined1 *)puVar12 = 0;
  if (unaff_EBP < 2) {
    ___mbcodepage = 0;
    ___mblcid = 0;
  }
  else {
    if ((char)((uint)unaff_EBX >> 0x10) != '\0') {
      pbVar10 = &stack0xffffffeb;
      do {
        bVar2 = *pbVar10;
        if (bVar2 == 0) break;
        for (uVar6 = (uint)pbVar10[-1]; uVar6 <= bVar2; uVar6 = uVar6 + 1) {
          *(byte *)((int)&__mbctype + uVar6 + 1) = *(byte *)((int)&__mbctype + uVar6 + 1) | 4;
        }
        pbVar11 = pbVar10 + 1;
        pbVar10 = pbVar10 + 2;
      } while (*pbVar11 != 0);
    }
    uVar6 = 1;
    do {
      *(byte *)((int)&__mbctype + uVar6 + 1) = *(byte *)((int)&__mbctype + uVar6 + 1) | 8;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0xff);
    ___mbcodepage = iVar4;
    ___mblcid = FUN_00554560(iVar4);
  }
  UNK_00888274._4_4_ = 0;
  UNK_00888274._8_4_ = 0;
  UNK_00888274._12_4_ = 0;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0055450a
// Address: 0055450a
int FUN_0055450a(int param_1)
{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00888284 = 1;
                    /* WARNING: Could not recover jumptable at 0x0055452d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00888284 = 1;
                    /* WARNING: Could not recover jumptable at 0x00554542. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = ___lc_codepage;
  }
  DAT_00888284 = (uint)bVar2;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00554510
// Address: 00554510
int FUN_00554510(int param_1)
{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00888284 = 1;
                    /* WARNING: Could not recover jumptable at 0x0055452d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00888284 = 1;
                    /* WARNING: Could not recover jumptable at 0x00554542. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = ___lc_codepage;
  }
  DAT_00888284 = (uint)bVar2;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055455d
// Address: 0055455d
undefined4 FUN_0055455d(undefined4 param_1)
{
  switch(param_1) {
  case 0x3a4:
    return 0x411;
  default:
    return 0;
  case 0x3a8:
    return 0x804;
  case 0x3b5:
    return 0x412;
  case 0x3b6:
    return 0x404;
  }
}

// --------------------------------------------------

// Function: FUN_00554560
// Address: 00554560
undefined4 FUN_00554560(undefined4 param_1)
{
  switch(param_1) {
  case 0x3a4:
    return 0x411;
  default:
    return 0;
  case 0x3a8:
    return 0x804;
  case 0x3b5:
    return 0x412;
  case 0x3b6:
    return 0x404;
  }
}

// --------------------------------------------------

// Function: FUN_005545c0
// Address: 005545c0
void FUN_005545c0(void)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &__mbctype;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  ___mbcodepage = 0;
  ___mblcid = 0;
  UNK_00888274._4_4_ = 0;
  UNK_00888274._8_4_ = 0;
  UNK_00888274._12_4_ = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_005545ed
// Address: 005545ed
undefined4 FUN_005545ed(void)
{
  return ___mbcodepage;
}

// --------------------------------------------------

// Function: FUN_005545f6
// Address: 005545f6
void FUN_005545f6(void)
{
  __setmbcp(0xfffffffd);
  return;
}

// --------------------------------------------------

// Function: ___initmbctable
// Address: 00554600
void ___initmbctable(void)
{
  __setmbcp(0xfffffffd);
  return;
}

// --------------------------------------------------

// Function: FUN_0055460b
// Address: 0055460b
undefined4 FUN_0055460b(byte *param_1,byte *param_2)
{
  byte *pbVar1;
  
  if ((___mbcodepage != 0) && (param_1 <= param_2)) {
    while (*param_1 != 0) {
      pbVar1 = param_1;
      if ((*(byte *)((int)&__mbctype + *param_1 + 1) & 4) != 0) {
        pbVar1 = param_1 + 1;
        if (param_1 == param_2) {
          return 0xffffffff;
        }
        if (*pbVar1 == 0) {
          return 0;
        }
      }
      param_1 = pbVar1 + 1;
      if (param_2 < param_1) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: __ismbslead
// Address: 00554610
undefined4 __ismbslead(byte *param_1,byte *param_2)
{
  byte *pbVar1;
  
  if ((___mbcodepage != 0) && (param_1 <= param_2)) {
    while (*param_1 != 0) {
      pbVar1 = param_1;
      if ((*(byte *)((int)&__mbctype + *param_1 + 1) & 4) != 0) {
        pbVar1 = param_1 + 1;
        if (param_1 == param_2) {
          return 0xffffffff;
        }
        if (*pbVar1 == 0) {
          return 0;
        }
      }
      param_1 = pbVar1 + 1;
      if (param_2 < param_1) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00554659
// Address: 00554659
int FUN_00554659(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_EBP;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_4;
  
  iVar6 = 0;
  if (DAT_00888288 == 0) {
    iVar1 = GetStringTypeW(1,L"",1,&local_4);
    if (iVar1 == 0) {
      iVar1 = GetStringTypeA(0,1,"",1,&local_4);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_00888288 = 2;
    }
    else {
      DAT_00888288 = 1;
    }
  }
  if (DAT_00888288 != 1) {
    iVar1 = DAT_00888288;
    if (DAT_00888288 == 2) {
      local_4 = 0;
      if (param_5 == 0) {
        param_5 = ___lc_codepage;
      }
      uVar9 = 0;
      uVar8 = 0x220;
      iVar5 = param_3;
      iVar2 = WideCharToMultiByte(param_5,0x220,param_2,param_3,0,0,0,0);
      if (iVar2 == 0) {
        return 0;
      }
      iVar3 = calloc(1,iVar2);
      if (iVar3 == 0) {
        return 0;
      }
      uVar7 = 0;
      iVar1 = iVar3;
      iVar4 = WideCharToMultiByte(unaff_EBP,0x220,uVar9,param_3,iVar3,iVar2,0,0);
      if ((iVar4 != 0) && (iVar6 = malloc(iVar2 * 2 + 2), iVar6 != 0)) {
        if (iVar5 == 0) {
          iVar5 = DAT_008882c0;
        }
        param_3 = param_3 * 2;
        *(undefined2 *)(iVar6 + param_3) = 0xffff;
        *(undefined2 *)(iVar6 + -2 + param_3) = 0xffff;
        iVar1 = GetStringTypeA(iVar5,uVar7,iVar3,iVar2,iVar6);
        if ((*(short *)(iVar6 + -2 + param_3) == -1) || (*(short *)(iVar6 + param_3) != -1)) {
          iVar1 = 0;
        }
        else {
          memmove(uVar8,iVar6,param_3);
        }
      }
      free(iVar3);
      free(iVar6);
    }
    return iVar1;
  }
  iVar6 = GetStringTypeW(param_1,param_2,param_3,param_4);
  return iVar6;
}

// --------------------------------------------------

// Function: FUN_005547e4
// Address: 005547e4
int FUN_005547e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int param_5,int param_6)
{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int iVar2;
  int unaff_retaddr;
  undefined1 auStack_2 [2];
  
  iVar2 = 0;
  if (DAT_0088828c == 0) {
    iVar1 = GetStringTypeA(0,1,"",1,auStack_2);
    if (iVar1 == 0) {
      iVar1 = GetStringTypeW(1,L"",1,auStack_2);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0088828c = 1;
    }
    else {
      DAT_0088828c = 2;
    }
  }
  if (DAT_0088828c == 2) {
    if (param_6 == 0) {
      param_6 = DAT_008882c0;
    }
    iVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
    return iVar2;
  }
  iVar1 = DAT_0088828c;
  if (DAT_0088828c == 1) {
    if (param_5 == 0) {
      param_5 = ___lc_codepage;
    }
    iVar1 = MultiByteToWideChar(param_5,9,param_2,param_3,0,0);
    if (iVar1 != 0) {
      iVar2 = calloc(2,iVar1);
      if (iVar2 != 0) {
        iVar1 = MultiByteToWideChar(param_5,1,unaff_ESI,param_3,iVar2,iVar1);
        if (iVar1 != 0) {
          iVar1 = GetStringTypeW(unaff_EDI,iVar2,iVar1,unaff_EBX);
          free(iVar2);
          return iVar1;
        }
      }
    }
    free(iVar2);
    iVar1 = unaff_retaddr;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: ___crtGetStringTypeA
// Address: 005547f0
int ___crtGetStringTypeA
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              int param_5,int param_6)
{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int iVar2;
  int unaff_retaddr;
  undefined1 local_2 [2];
  
  iVar2 = 0;
  if (DAT_0088828c == 0) {
    iVar1 = GetStringTypeA(0,1,"",1,local_2);
    if (iVar1 == 0) {
      iVar1 = GetStringTypeW(1,L"",1,local_2);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0088828c = 1;
    }
    else {
      DAT_0088828c = 2;
    }
  }
  if (DAT_0088828c == 2) {
    if (param_6 == 0) {
      param_6 = DAT_008882c0;
    }
    iVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
    return iVar2;
  }
  iVar1 = DAT_0088828c;
  if (DAT_0088828c == 1) {
    if (param_5 == 0) {
      param_5 = ___lc_codepage;
    }
    iVar1 = MultiByteToWideChar(param_5,9,param_2,param_3,0,0);
    if (iVar1 != 0) {
      iVar2 = calloc(2,iVar1);
      if (iVar2 != 0) {
        iVar1 = MultiByteToWideChar(param_5,1,unaff_ESI,param_3,iVar2,iVar1);
        if (iVar1 != 0) {
          iVar1 = GetStringTypeW(unaff_EDI,iVar2,iVar1,unaff_EBX);
          free(iVar2);
          return iVar1;
        }
      }
    }
    free(iVar2);
    iVar1 = unaff_retaddr;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0055491d
// Address: 0055491d
int FUN_0055491d(byte *param_1,int param_2)
{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar2 = param_1;
  if (param_2 != 0) {
    while( true ) {
      param_2 = param_2 + -1;
      if ((*pbVar2 == 0) ||
         ((pbVar1 = pbVar2, (*(byte *)((int)&__mbctype + *pbVar2 + 1) & 4) != 0 &&
          (pbVar1 = pbVar2 + 1, pbVar2[1] == 0)))) break;
      pbVar2 = pbVar1 + 1;
      if (param_2 == 0) {
        return (int)(pbVar1 + 1) - (int)param_1;
      }
    }
  }
  return (int)pbVar2 - (int)param_1;
}

// --------------------------------------------------

// Function: __mbsnbcnt
// Address: 00554920
int __mbsnbcnt(byte *param_1,int param_2)
{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar2 = param_1;
  if (param_2 != 0) {
    while( true ) {
      param_2 = param_2 + -1;
      if ((*pbVar2 == 0) ||
         ((pbVar1 = pbVar2, (*(byte *)((int)&__mbctype + *pbVar2 + 1) & 4) != 0 &&
          (pbVar1 = pbVar2 + 1, pbVar2[1] == 0)))) break;
      pbVar2 = pbVar1 + 1;
      if (param_2 == 0) {
        return (int)(pbVar1 + 1) - (int)param_1;
      }
    }
  }
  return (int)pbVar2 - (int)param_1;
}

// --------------------------------------------------

// Function: FUN_00554964
// Address: 00554964
int FUN_00554964(void)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = -1;
  iVar5 = 0;
  iVar6 = 0;
  piVar3 = &___pioinfo;
  do {
    puVar2 = (undefined4 *)*piVar3;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)malloc(0x100);
      if (puVar2 != (undefined4 *)0x0) {
        __nhandle = __nhandle + 0x20;
        (&___pioinfo)[iVar5] = puVar2;
        if (puVar2 < puVar2 + 0x40) {
          do {
            *(undefined1 *)(puVar2 + 1) = 0;
            *puVar2 = 0xffffffff;
            *(undefined1 *)((int)puVar2 + 5) = 10;
            puVar2 = puVar2 + 2;
          } while (puVar2 < (undefined4 *)((&___pioinfo)[iVar5] + 0x100));
        }
        iVar4 = iVar5 << 5;
      }
      return iVar4;
    }
    puVar1 = puVar2 + 0x40;
    for (; puVar2 < puVar1; puVar2 = puVar2 + 2) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        *puVar2 = 0xffffffff;
        iVar4 = ((int)puVar2 - *piVar3 >> 3) + iVar6;
        break;
      }
    }
    if (iVar4 != -1) {
      return iVar4;
    }
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x20;
    if (0x8885df < (int)piVar3) {
      return -1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: __alloc_osfhnd
// Address: 00554970
int __alloc_osfhnd(void)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = -1;
  iVar5 = 0;
  iVar6 = 0;
  piVar3 = &___pioinfo;
  do {
    puVar2 = (undefined4 *)*piVar3;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)malloc(0x100);
      if (puVar2 != (undefined4 *)0x0) {
        __nhandle = __nhandle + 0x20;
        (&___pioinfo)[iVar5] = puVar2;
        if (puVar2 < puVar2 + 0x40) {
          do {
            *(undefined1 *)(puVar2 + 1) = 0;
            *puVar2 = 0xffffffff;
            *(undefined1 *)((int)puVar2 + 5) = 10;
            puVar2 = puVar2 + 2;
          } while (puVar2 < (undefined4 *)((&___pioinfo)[iVar5] + 0x100));
        }
        iVar4 = iVar5 << 5;
      }
      return iVar4;
    }
    puVar1 = puVar2 + 0x40;
    for (; puVar2 < puVar1; puVar2 = puVar2 + 2) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        *puVar2 = 0xffffffff;
        iVar4 = ((int)puVar2 - *piVar3 >> 3) + iVar6;
        break;
      }
    }
    if (iVar4 != -1) {
      return iVar4;
    }
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x20;
    if (0x8885df < (int)piVar3) {
      return -1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00554a2c
// Address: 00554a2c
undefined4 FUN_00554a2c(uint param_1,undefined4 param_2)
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

