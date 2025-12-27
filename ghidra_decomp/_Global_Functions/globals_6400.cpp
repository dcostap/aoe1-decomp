// GLOBAL FUNCTIONS PART 6400
// Function: ___strgtold12
// Address: 005588f0
undefined4
___strgtold12(ushort *param_1,int *param_2,byte *param_3,undefined4 param_4,int param_5,int param_6,
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
  int local_60;
  char *local_5c;
  uint local_54;
  byte *local_50;
  int local_4c;
  int local_48;
  undefined4 local_30;
  ushort local_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  byte *local_26;
  ushort local_22;
  char local_1c [23];
  char local_5;
  
  local_5c = local_1c;
  iVar8 = 0;
  uVar13 = 0;
  uVar7 = 0;
  local_4c = 1;
  local_54 = 0;
  bVar2 = false;
  bVar4 = false;
  bVar3 = false;
  bVar5 = false;
  bVar6 = false;
  local_48 = 0;
  local_60 = 0;
  local_30 = 0;
  local_50 = param_3;
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
          *local_5c = bVar10 - 0x30;
          bVar10 = *pbVar12;
          local_5c = local_5c + 1;
          param_3 = (byte *)CONCAT31(param_3._1_3_,bVar10);
          pbVar12 = pbVar12 + 1;
        }
        else {
          bVar10 = *pbVar12;
          local_60 = local_60 + 1;
          param_3 = (byte *)CONCAT31(param_3._1_3_,bVar10);
          pbVar12 = pbVar12 + 1;
        }
      }
      local_54 = uVar13;
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
          local_60 = local_60 + -1;
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
          *local_5c = bVar10 - 0x30;
          local_5c = local_5c + 1;
          local_60 = local_60 + -1;
        }
        bVar10 = *pbVar12;
        pbVar12 = pbVar12 + 1;
        param_3 = (byte *)CONCAT31(param_3._1_3_,bVar10);
      }
      local_54 = uVar13;
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
      local_50 = pbVar11;
      if (('0' < (char)bVar10) && ((char)bVar10 < ':')) {
        iVar8 = 9;
        goto LAB_00558dc2;
      }
      if (bVar10 == 0x2b) {
LAB_00558db6:
        iVar8 = 7;
        pbVar14 = pbVar11;
        local_50 = pbVar11;
      }
      else {
        if (bVar10 != 0x2d) goto LAB_00558ca6;
LAB_00558da7:
        iVar8 = 7;
        local_4c = -1;
        pbVar14 = pbVar11;
        local_50 = pbVar11;
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
      local_48 = 0;
      while( true ) {
        if (___mb_cur_max < 2) {
          uVar13 = (byte)__pctype[((uint)param_3 & 0xff) * 2] & 4;
        }
        else {
          uVar13 = __isctype((uint)param_3 & 0xff,4);
        }
        if (uVar13 == 0) goto LAB_00558d2a;
        local_48 = (char)bVar10 + -0x30 + local_48 * 10;
        if (0x1450 < local_48) break;
        bVar10 = *pbVar12;
        pbVar12 = pbVar12 + 1;
        param_3 = (byte *)CONCAT31(param_3._1_3_,bVar10);
      }
                    /* language.dll match for 0x1451: "Dead tree" */
      local_48 = 0x1451;
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
      uVar13 = local_54;
      pbVar14 = local_50;
      break;
    case 0xb:
      if (param_7 == 0) goto switchD_00558bb2_caseD_2c;
      if (bVar10 == 0x2b) goto LAB_00558db6;
      if (bVar10 == 0x2d) goto LAB_00558da7;
      iVar8 = 10;
      pbVar12 = pbVar11;
      pbVar14 = pbVar11;
      local_50 = pbVar11;
    }
    pbVar11 = pbVar12;
  } while (iVar8 != 10);
  *param_2 = (int)pbVar12;
  if (bVar2) {
    if (0x18 < uVar13) {
      if ('\x04' < local_5) {
        local_5 = local_5 + '\x01';
      }
      local_5c = local_5c + -1;
      local_60 = local_60 + 1;
      uVar13 = 0x18;
    }
    if (uVar13 == 0) {
      local_2c = 0;
      local_22 = 0;
      param_3 = (byte *)0x0;
      pbVar11 = (byte *)0x0;
      goto LAB_00558e94;
    }
    cVar1 = local_5c[-1];
    while (cVar1 == '\0') {
      uVar13 = uVar13 - 1;
      local_60 = local_60 + 1;
      cVar1 = local_5c[-2];
      local_5c = local_5c + -1;
    }
    ___mtold12(local_1c,uVar13,&local_2c);
    if (local_4c < 0) {
      local_48 = -local_48;
    }
    local_48 = local_48 + local_60;
    if (!bVar3) {
      local_48 = local_48 + param_5;
    }
    if (!bVar4) {
      local_48 = local_48 - param_6;
    }
    if (local_48 < 0x1451) {
      if (-0x1451 < local_48) {
        ___multtenpow12(&local_2c,local_48,param_4);
        pbVar11 = (byte *)CONCAT22(uStack_28,uStack_2a);
        param_3 = local_26;
        goto LAB_00558e94;
      }
      bVar6 = true;
    }
    else {
      bVar5 = true;
    }
  }
  local_2c = (ushort)param_3;
  pbVar11 = param_3;
  local_22 = local_2c;
LAB_00558e94:
  if (bVar2) {
    if (bVar5) {
      pbVar11 = (byte *)0x0;
      local_22 = 0x7fff;
      param_3 = (byte *)0x80000000;
      local_2c = 0;
      local_30 = 2;
    }
    else if (bVar6) {
      local_2c = 0;
      local_22 = 0;
      param_3 = (byte *)0x0;
      pbVar11 = (byte *)0x0;
      local_30 = 1;
    }
  }
  else {
    local_2c = 0;
    local_22 = 0;
    param_3 = (byte *)0x0;
    pbVar11 = (byte *)0x0;
    local_30 = 4;
  }
  *param_1 = local_2c;
  *(byte **)(param_1 + 1) = pbVar11;
  *(byte **)(param_1 + 3) = param_3;
  param_1[5] = local_22 | uVar7;
  return local_30;
}

// --------------------------------------------------

// Function: __matherr
// Address: 005590d0
undefined4 __matherr(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_005590d3
// Address: 005590d3
int FUN_005590d3(short *param_1)
{
  short sVar1;
  short *psVar2;
  
  sVar1 = *param_1;
  psVar2 = param_1 + 1;
  while (sVar1 != 0) {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  }
  return ((int)psVar2 - (int)param_1 >> 1) + -1;
}

// --------------------------------------------------

// Function: wcslen
// Address: 005590e0
/* wcslen */

int __cdecl wcslen(short *param_1)
{
  short sVar1;
  short *psVar2;
  
  sVar1 = *param_1;
  psVar2 = param_1 + 1;
  while (sVar1 != 0) {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  }
  return ((int)psVar2 - (int)param_1 >> 1) + -1;
}

// --------------------------------------------------

// Function: FUN_005590fe
// Address: 005590fe
undefined4 FUN_005590fe(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (DAT_00888424 != (code *)0x0) {
LAB_00559150:
    if (DAT_00888428 != (code *)0x0) {
      iVar3 = (*DAT_00888428)();
    }
    if ((iVar3 != 0) && (DAT_0088842c != (code *)0x0)) {
      iVar3 = (*DAT_0088842c)(iVar3);
    }
    uVar2 = (*DAT_00888424)(iVar3,param_1,param_2,param_3);
    return uVar2;
  }
  iVar1 = LoadLibraryA("user32.dll");
  if (iVar1 != 0) {
    DAT_00888424 = (code *)GetProcAddress(iVar1,"MessageBoxA");
    if (DAT_00888424 != (code *)0x0) {
      DAT_00888428 = (code *)GetProcAddress(iVar1,"GetActiveWindow");
      DAT_0088842c = (code *)GetProcAddress(iVar1,"GetLastActivePopup");
      goto LAB_00559150;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: ___crtMessageBoxA
// Address: 00559100
undefined4 ___crtMessageBoxA(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (DAT_00888424 != (code *)0x0) {
LAB_00559150:
    if (DAT_00888428 != (code *)0x0) {
      iVar3 = (*DAT_00888428)();
    }
    if ((iVar3 != 0) && (DAT_0088842c != (code *)0x0)) {
      iVar3 = (*DAT_0088842c)(iVar3);
    }
    uVar2 = (*DAT_00888424)(iVar3,param_1,param_2,param_3);
    return uVar2;
  }
  iVar1 = LoadLibraryA("user32.dll");
  if (iVar1 != 0) {
    DAT_00888424 = (code *)GetProcAddress(iVar1,"MessageBoxA");
    if (DAT_00888424 != (code *)0x0) {
      DAT_00888428 = (code *)GetProcAddress(iVar1,"GetActiveWindow");
      DAT_0088842c = (code *)GetProcAddress(iVar1,"GetLastActivePopup");
      goto LAB_00559150;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0055918f
// Address: 0055918f
int FUN_0055918f(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if ((param_2 == 4) || (param_2 == 3)) {
    _errno = 0x16;
    return -1;
  }
  if (param_1 != 2) {
    if (((param_1 != 0x15) && (param_1 != 0x16)) && (param_1 != 0xf)) {
      if (((param_1 != 8) && (param_1 != 4)) && (param_1 != 0xb)) {
        _errno = 0x16;
        return -1;
      }
      puVar5 = (undefined4 *)FUN_005594d0(param_1);
      if (puVar5 == (undefined4 *)0x0) {
        _errno = 0x16;
        return -1;
      }
      iVar6 = puVar5[2];
      if (puVar5[1] != param_1) {
        return iVar6;
      }
      do {
        puVar5[2] = param_2;
        if (&__XcptActTab + __XcptActTabCount * 3 <= puVar5 + 3) {
          return iVar6;
        }
        piVar1 = puVar5 + 4;
        puVar5 = puVar5 + 3;
      } while (*piVar1 == param_1);
      return iVar6;
    }
    if ((param_1 != 2) && (param_1 != 0x15)) goto LAB_00559244;
  }
  if ((int)DAT_00888440 == 0) {
    iVar6 = SetConsoleCtrlHandler(0x559300,1);
    if (iVar6 != 1) {
      __doserrno = GetLastError();
      _errno = 0x16;
      return -1;
    }
    DAT_00888440._0_4_ = 1;
  }
LAB_00559244:
  iVar4 = DAT_0088843c;
  iVar3 = DAT_00888438;
  iVar2 = DAT_00888434;
  iVar6 = DAT_00888430;
  switch(param_1) {
  case 2:
    DAT_00888430 = param_2;
    return iVar6;
  default:
    return param_2;
  case 0xf:
    DAT_0088843c = param_2;
    return iVar4;
  case 0x15:
    DAT_00888434 = param_2;
    return iVar2;
  case 0x16:
    DAT_00888438 = param_2;
    return iVar3;
  }
}

// --------------------------------------------------

// Function: FUN_005592d3
// Address: 005592d3
undefined4 __fastcall FUN_005592d3(char param_1)
{
  undefined4 in_EAX;
  undefined3 uVar3;
  int iVar1;
  code *pcVar2;
  undefined4 *puVar4;
  undefined4 uVar5;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 unaff_retaddr;
  
  *(char *)(unaff_ESI + 0x6c005592) = *(char *)(unaff_ESI + 0x6c005592) + param_1;
  *(char *)(unaff_EBP + -0x6e) = *(char *)(unaff_EBP + -0x6e) + (char)((uint)unaff_retaddr >> 8);
  *(char *)(unaff_EDI + 0x5592) = *(char *)(unaff_EDI + 0x5592) + (char)unaff_retaddr;
  uVar3 = (undefined3)((uint)in_EAX >> 8);
  iVar1 = CONCAT31(uVar3,(char)in_EAX + '\x18');
  *(int *)(&stack0xfffffff8 + iVar1) = *(int *)(&stack0xfffffff8 + iVar1) + iVar1;
  if ((CONCAT31(uVar3,(char)in_EAX + '\x1e') & 0xffffff04) == 0) {
    puVar4 = &DAT_00888430;
    uVar5 = 2;
    pcVar2 = DAT_00888430;
  }
  else {
    puVar4 = &DAT_00888434;
    uVar5 = 0x15;
    pcVar2 = DAT_00888434;
  }
  if (pcVar2 == (code *)0x0) {
    return 0;
  }
  if (pcVar2 != (code *)0x1) {
    *puVar4 = 0;
    (*pcVar2)(uVar5);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00559348
// Address: 00559348
undefined4 FUN_00559348(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar2 = param_1;
  switch(param_1) {
  case 2:
    puVar6 = &DAT_00888430;
    pcVar4 = DAT_00888430;
    break;
  default:
    return 0xffffffff;
  case 4:
  case 8:
  case 0xb:
    iVar3 = FUN_005594d0(param_1);
    puVar6 = (undefined4 *)(iVar3 + 8);
    pcVar4 = (code *)*puVar6;
    break;
  case 0xf:
    puVar6 = &DAT_0088843c;
    pcVar4 = DAT_0088843c;
    break;
  case 0x15:
    puVar6 = &DAT_00888434;
    pcVar4 = DAT_00888434;
    break;
  case 0x16:
    puVar6 = &DAT_00888438;
    pcVar4 = DAT_00888438;
  }
  if (pcVar4 == (code *)0x1) {
    return 0;
  }
  if (pcVar4 == (code *)0x0) {
    __exit(3);
  }
  iVar1 = __pxcptinfoptrs;
  iVar3 = __fpecode;
  if (((param_1 == 8) || (param_1 == 0xb)) || (iVar5 = param_1, param_1 == 4)) {
    __pxcptinfoptrs = 0;
    iVar5 = iVar1;
    if (param_1 == 8) {
      __fpecode = 0x8c;
      param_1 = iVar3;
      goto LAB_0055940f;
    }
  }
  else {
LAB_0055940f:
    if (iVar2 == 8) {
      if (__First_FPE_Indx < __Num_FPE + __First_FPE_Indx) {
        iVar3 = (__Num_FPE + __First_FPE_Indx) - __First_FPE_Indx;
        puVar6 = (undefined4 *)((int)&UNK_00592580 + __First_FPE_Indx * 0xc);
        do {
          *puVar6 = 0;
          puVar6 = puVar6 + 3;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      goto LAB_00559446;
    }
  }
  *puVar6 = 0;
LAB_00559446:
  if (iVar2 == 8) {
    (*pcVar4)(8,__fpecode);
  }
  else {
    (*pcVar4)(iVar2);
    if ((iVar2 != 0xb) && (iVar2 != 4)) {
      return 0;
    }
  }
  if (iVar2 == 8) {
    __fpecode = param_1;
  }
  __pxcptinfoptrs = iVar5;
  return 0;
}

// --------------------------------------------------

// Function: raise
// Address: 00559350
/* raise */

undefined4 __cdecl raise(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar2 = param_1;
  switch(param_1) {
  case 2:
    puVar6 = &DAT_00888430;
    pcVar4 = DAT_00888430;
    break;
  default:
    return 0xffffffff;
  case 4:
  case 8:
  case 0xb:
    iVar3 = FUN_005594d0(param_1);
    puVar6 = (undefined4 *)(iVar3 + 8);
    pcVar4 = (code *)*puVar6;
    break;
  case 0xf:
    puVar6 = &DAT_0088843c;
    pcVar4 = DAT_0088843c;
    break;
  case 0x15:
    puVar6 = &DAT_00888434;
    pcVar4 = DAT_00888434;
    break;
  case 0x16:
    puVar6 = &DAT_00888438;
    pcVar4 = DAT_00888438;
  }
  if (pcVar4 == (code *)0x1) {
    return 0;
  }
  if (pcVar4 == (code *)0x0) {
    __exit(3);
  }
  iVar1 = __pxcptinfoptrs;
  iVar3 = __fpecode;
  if (((param_1 == 8) || (param_1 == 0xb)) || (iVar5 = param_1, param_1 == 4)) {
    __pxcptinfoptrs = 0;
    iVar5 = iVar1;
    if (param_1 == 8) {
      __fpecode = 0x8c;
      param_1 = iVar3;
      goto LAB_0055940f;
    }
  }
  else {
LAB_0055940f:
    if (iVar2 == 8) {
      if (__First_FPE_Indx < __Num_FPE + __First_FPE_Indx) {
        iVar3 = (__Num_FPE + __First_FPE_Indx) - __First_FPE_Indx;
        puVar6 = (undefined4 *)((int)&UNK_00592580 + __First_FPE_Indx * 0xc);
        do {
          *puVar6 = 0;
          puVar6 = puVar6 + 3;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      goto LAB_00559446;
    }
  }
  *puVar6 = 0;
LAB_00559446:
  if (iVar2 == 8) {
    (*pcVar4)(8,__fpecode);
  }
  else {
    (*pcVar4)(iVar2);
    if ((iVar2 != 0xb) && (iVar2 != 4)) {
      return 0;
    }
  }
  if (iVar2 == 8) {
    __fpecode = param_1;
  }
  __pxcptinfoptrs = iVar5;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00559493
// Address: 00559493
undefined4 * __fastcall FUN_00559493(int param_1,int param_2)
{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  code *unaff_EBX;
  undefined4 unaff_EBP;
  int *unaff_EDI;
  bool in_CF;
  undefined4 in_stack_00000014;
  int in_stack_0000001c;
  
  if (!in_CF) {
    param_1 = param_1 - param_2;
    puVar2 = (undefined4 *)((int)&UNK_00592580 + in_EAX * 4);
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 3;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    if (unaff_EDI == (int *)0x8) {
      (*unaff_EBX)();
    }
    else {
      (*unaff_EBX)();
      if ((unaff_EDI != (int *)0xb) && (unaff_EDI != (int *)0x4)) {
        return (undefined4 *)0x0;
      }
    }
    if (unaff_EDI == (int *)0x8) {
      __fpecode = in_stack_00000014;
    }
    __pxcptinfoptrs = unaff_EBP;
    return (undefined4 *)0x0;
  }
  *(char *)((int)unaff_EDI + -0x58ffaa6d) =
       *(char *)((int)unaff_EDI + -0x58ffaa6d) + (char)((uint)in_EAX >> 8);
  *(char *)((int)unaff_EDI + -0x65ffaa6d) =
       *(char *)((int)unaff_EDI + -0x65ffaa6d) + (char)((uint)unaff_EBX >> 8);
  *(char *)(in_EAX + -0x72ffaa6d) = *(char *)(in_EAX + -0x72ffaa6d) + (char)in_EAX;
  *(char *)(in_EAX + 0x5594) = *(char *)(in_EAX + 0x5594) + (char)param_1;
  *unaff_EDI = (int)(unaff_EBX + *unaff_EDI);
  puVar2 = &__XcptActTab;
  if (DAT_0059257c != in_stack_0000001c) {
    puVar3 = puVar2;
    do {
      puVar2 = puVar3 + 3;
      if (&__XcptActTab + __XcptActTabCount * 3 <= puVar2) break;
      piVar1 = puVar3 + 4;
      puVar3 = puVar2;
    } while (*piVar1 != in_stack_0000001c);
  }
  if ((&__XcptActTab + __XcptActTabCount * 3 <= puVar2) || (puVar2[1] != in_stack_0000001c)) {
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}

// --------------------------------------------------

// Function: FUN_005594d0
// Address: 005594d0
undefined4 * FUN_005594d0(int param_1)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &__XcptActTab;
  if (DAT_0059257c != param_1) {
    puVar3 = puVar2;
    do {
      puVar2 = puVar3 + 3;
      if (&__XcptActTab + __XcptActTabCount * 3 <= puVar2) break;
      piVar1 = puVar3 + 4;
      puVar3 = puVar2;
    } while (*piVar1 != param_1);
  }
  if ((&__XcptActTab + __XcptActTabCount * 3 <= puVar2) || (puVar2[1] != param_1)) {
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}

// --------------------------------------------------

// Function: FUN_00559517
// Address: 00559517
undefined4 FUN_00559517(uint param_1,uint param_2,uint *param_3)
{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = param_2 + param_1;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}

// --------------------------------------------------

// Function: ___addl
// Address: 00559520
undefined4 ___addl(uint param_1,uint param_2,uint *param_3)
{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = param_2 + param_1;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_00559543
// Address: 00559543
void FUN_00559543(undefined4 *param_1,undefined4 *param_2)
{
  int iVar1;
  
  iVar1 = ___addl(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = ___addl(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = ___addl(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  ___addl(param_1[2],param_2[2],param_1 + 2);
  return;
}

// --------------------------------------------------

// Function: ___add_12
// Address: 00559550
void ___add_12(undefined4 *param_1,undefined4 *param_2)
{
  int iVar1;
  
  iVar1 = ___addl(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = ___addl(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = ___addl(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  ___addl(param_1[2],param_2[2],param_1 + 2);
  return;
}

// --------------------------------------------------

// Function: FUN_005595b8
// Address: 005595b8
void FUN_005595b8(uint *param_1)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] << 1 | uVar2 >> 0x1f;
  return;
}

// --------------------------------------------------

// Function: ___shl_12
// Address: 005595c0
void ___shl_12(uint *param_1)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] << 1 | uVar2 >> 0x1f;
  return;
}

// --------------------------------------------------

// Function: FUN_005595ee
// Address: 005595ee
void FUN_005595ee(uint *param_1)
{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}

// --------------------------------------------------

// Function: ___shr_12
// Address: 005595f0
void ___shr_12(uint *param_1)
{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}

// --------------------------------------------------

// Function: FUN_0055961d
// Address: 0055961d
void FUN_0055961d(char *param_1,int param_2,uint *param_3)
{
  uint uVar1;
  uint *puVar2;
  short sVar3;
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  puVar2 = param_3;
  sVar3 = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 != 0) {
    param_3 = (uint *)param_2;
    do {
      uStack_c = *puVar2;
      uStack_8 = puVar2[1];
      uStack_4 = puVar2[2];
      ___shl_12(puVar2);
      ___shl_12(puVar2);
      ___add_12(puVar2,&uStack_c);
      ___shl_12(puVar2);
      uStack_c = (uint)*param_1;
      uStack_8 = 0;
      uStack_4 = 0;
      ___add_12(puVar2,&uStack_c);
      param_1 = param_1 + 1;
      param_3 = (uint *)((int)param_3 + -1);
    } while (param_3 != (uint *)0x0);
  }
  uVar1 = puVar2[2];
  while (uVar1 == 0) {
    sVar3 = sVar3 + -0x10;
    puVar2[2] = puVar2[1] >> 0x10;
    uVar1 = puVar2[2];
    puVar2[1] = *puVar2 >> 0x10 | puVar2[1] << 0x10;
    *puVar2 = *puVar2 << 0x10;
  }
  uVar1 = puVar2[2];
  while ((uVar1 & 0x8000) == 0) {
    ___shl_12(puVar2);
    sVar3 = sVar3 + -1;
    uVar1 = puVar2[2];
  }
  *(short *)((int)puVar2 + 10) = sVar3;
  return;
}

// --------------------------------------------------

// Function: ___mtold12
// Address: 00559620
void ___mtold12(char *param_1,int param_2,uint *param_3)
{
  uint uVar1;
  uint *puVar2;
  short sVar3;
  uint local_c;
  uint local_8;
  uint local_4;
  
  puVar2 = param_3;
  sVar3 = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 != 0) {
    param_3 = (uint *)param_2;
    do {
      local_c = *puVar2;
      local_8 = puVar2[1];
      local_4 = puVar2[2];
      ___shl_12(puVar2);
      ___shl_12(puVar2);
      ___add_12(puVar2,&local_c);
      ___shl_12(puVar2);
      local_c = (uint)*param_1;
      local_8 = 0;
      local_4 = 0;
      ___add_12(puVar2,&local_c);
      param_1 = param_1 + 1;
      param_3 = (uint *)((int)param_3 + -1);
    } while (param_3 != (uint *)0x0);
  }
  uVar1 = puVar2[2];
  while (uVar1 == 0) {
    sVar3 = sVar3 + -0x10;
    puVar2[2] = puVar2[1] >> 0x10;
    uVar1 = puVar2[2];
    puVar2[1] = *puVar2 >> 0x10 | puVar2[1] << 0x10;
    *puVar2 = *puVar2 << 0x10;
  }
  uVar1 = puVar2[2];
  while ((uVar1 & 0x8000) == 0) {
    ___shl_12(puVar2);
    sVar3 = sVar3 + -1;
    uVar1 = puVar2[2];
  }
  *(short *)((int)puVar2 + 10) = sVar3;
  return;
}

// --------------------------------------------------

// Function: FUN_00559711
// Address: 00559711
// [HELPER] s_1_IND: "1#IND"
// [HELPER] s_1_INF: "1#INF"
// [HELPER] s_1_QNAN: "1#QNAN"
// [HELPER] s_1_SNAN: "1#SNAN"
undefined4
FUN_00559711(int param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)
{
  short *psVar1;
  ushort uVar2;
  undefined2 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  int iVar9;
  short sVar10;
  int iVar11;
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
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined2 uStack_8;
  undefined1 uStack_6;
  char cStack_5;
  
  psVar1 = param_6;
  uStack_1c = 0xcc;
  uStack_1b = 0xcc;
  uStack_1a = 0xcc;
  uStack_19 = 0xcc;
  uStack_18 = 0xcc;
  uStack_17 = 0xcc;
  uStack_16 = 0xcc;
  uStack_15 = 0xcc;
  uStack_14 = 0xcc;
  uStack_13 = 0xcc;
  uVar5 = param_3 & 0x7fff;
  uStack_12 = 0xfb;
  uStack_11 = 0x3f;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar5 == 0) && (param_2 == 0)) && (param_1 == 0)) {
    *param_6 = 0;
LAB_0055992f:
    *(undefined1 *)(psVar1 + 1) = 0x20;
    *(undefined1 *)((int)psVar1 + 3) = 1;
    *(undefined1 *)(psVar1 + 2) = 0x30;
    *(undefined1 *)((int)psVar1 + 5) = 0;
    return 1;
  }
  if ((short)uVar5 == 0x7fff) {
    *param_6 = 1;
    if (((param_2 != 0x80000000) || (param_1 != 0)) && ((param_2 & 0x40000000) == 0)) {
      *(undefined4 *)(param_6 + 2) = s_1_SNAN._0_4_;
      param_6[4] = s_1_SNAN._4_2_;
      cVar4 = s_1_SNAN[6];
      *(undefined1 *)((int)param_6 + 3) = 6;
      *(char *)(param_6 + 5) = cVar4;
      return 0;
    }
    if ((((param_3 & 0x8000) != 0) && (param_2 == 0xc0000000)) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = s_1_IND._0_4_;
      uVar3 = s_1_IND._4_2_;
      *(undefined1 *)((int)param_6 + 3) = 5;
      param_6[4] = uVar3;
      return 0;
    }
    if ((param_2 == 0x80000000) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = s_1_INF._0_4_;
      uVar3 = s_1_INF._4_2_;
      *(undefined1 *)((int)param_6 + 3) = 5;
      param_6[4] = uVar3;
      return 0;
    }
    *(undefined4 *)(param_6 + 2) = s_1_QNAN._0_4_;
    param_6[4] = s_1_QNAN._4_2_;
    cVar4 = s_1_QNAN[6];
    *(undefined1 *)((int)param_6 + 3) = 6;
    *(char *)(param_6 + 5) = cVar4;
    return 0;
  }
  uStack_6 = (undefined1)uVar5;
  cStack_5 = (char)(uVar5 >> 8);
  uStack_a = (undefined2)param_2;
  uStack_8 = (undefined2)(param_2 >> 0x10);
  uStack_e = (undefined2)param_1;
  uStack_c = (undefined2)((uint)param_1 >> 0x10);
  uStack_10 = 0;
  sVar10 = (short)(((uVar5 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar5 * 0x4d10 >>
                  0x10);
  ___multtenpow12(&uStack_10,-(int)sVar10,1);
  if (0x3ffe < CONCAT11(cStack_5,uStack_6)) {
    sVar10 = sVar10 + 1;
    ___ld12mul(&uStack_10,&uStack_1c);
  }
  *psVar1 = sVar10;
  iVar9 = param_4;
  if (((param_5 & 1) != 0) && (iVar9 = param_4 + sVar10, param_4 + sVar10 < 1)) {
    *psVar1 = 0;
    goto LAB_0055992f;
  }
  if (0x15 < iVar9) {
    iVar9 = 0x15;
  }
  uVar2 = CONCAT11(cStack_5,uStack_6);
  uStack_6 = 0;
  cStack_5 = '\0';
  iVar6 = 8;
  iVar11 = uVar2 - 0x3ffe;
  do {
    ___shl_12(&uStack_10);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (iVar11 < 0) {
    for (uVar5 = -iVar11 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
      ___shr_12(&uStack_10);
    }
  }
  psVar1 = psVar1 + 2;
  iVar9 = iVar9 + 1;
  psVar7 = psVar1;
  if (0 < iVar9) {
    do {
      param_1 = CONCAT22(uStack_e,uStack_10);
      param_2 = CONCAT22(uStack_a,uStack_c);
      param_3 = CONCAT13(cStack_5,CONCAT12(uStack_6,uStack_8));
      ___shl_12(&uStack_10);
      ___shl_12(&uStack_10);
      ___add_12(&uStack_10,&param_1);
      ___shl_12(&uStack_10);
      cVar4 = cStack_5 + '0';
      cStack_5 = '\0';
      *(char *)psVar7 = cVar4;
      psVar7 = (short *)((int)psVar7 + 1);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  psVar8 = psVar7 + -1;
  if (*(char *)((int)psVar7 + -1) < '5') {
    if (psVar1 <= psVar8) {
      do {
        if ((char)*psVar8 != '0') break;
        psVar8 = (short *)((int)psVar8 + -1);
      } while (psVar1 <= psVar8);
      if (psVar1 <= psVar8) goto LAB_00559a86;
    }
    *(undefined1 *)psVar1 = 0x30;
    *param_6 = 0;
    *(undefined1 *)(param_6 + 1) = 0x20;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(undefined1 *)((int)param_6 + 5) = 0;
    return 1;
  }
  if (psVar1 <= psVar8) {
    do {
      if ((char)*psVar8 != '9') break;
      *(undefined1 *)psVar8 = 0x30;
      psVar8 = (short *)((int)psVar8 + -1);
    } while (psVar1 <= psVar8);
    if (psVar1 <= psVar8) {
      *(char *)psVar8 = (char)*psVar8 + '\x01';
      goto LAB_00559a86;
    }
  }
  psVar8 = (short *)((int)psVar8 + 1);
  *param_6 = *param_6 + 1;
  *(char *)psVar8 = *(char *)psVar8 + '\x01';
LAB_00559a86:
  cVar4 = ((char)psVar8 - (char)param_6) + -3;
  *(char *)((int)param_6 + 3) = cVar4;
  *(undefined1 *)((int)param_6 + cVar4 + 4) = 0;
  return 1;
}

// --------------------------------------------------

// Function: _$I10_OUTPUT
// Address: 00559720
// [HELPER] s_1_IND: "1#IND"
// [HELPER] s_1_INF: "1#INF"
// [HELPER] s_1_QNAN: "1#QNAN"
// [HELPER] s_1_SNAN: "1#SNAN"
undefined4
__I10_OUTPUT(int param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)
{
  short *psVar1;
  ushort uVar2;
  undefined2 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  int iVar9;
  short sVar10;
  int iVar11;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined2 local_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined2 uStack_8;
  undefined1 local_6;
  char cStack_5;
  
  psVar1 = param_6;
  local_1c = 0xcc;
  local_1b = 0xcc;
  local_1a = 0xcc;
  local_19 = 0xcc;
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xcc;
  local_15 = 0xcc;
  local_14 = 0xcc;
  local_13 = 0xcc;
  uVar5 = param_3 & 0x7fff;
  local_12 = 0xfb;
  local_11 = 0x3f;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar5 == 0) && (param_2 == 0)) && (param_1 == 0)) {
    *param_6 = 0;
LAB_0055992f:
    *(undefined1 *)(psVar1 + 1) = 0x20;
    *(undefined1 *)((int)psVar1 + 3) = 1;
    *(undefined1 *)(psVar1 + 2) = 0x30;
    *(undefined1 *)((int)psVar1 + 5) = 0;
    return 1;
  }
  if ((short)uVar5 == 0x7fff) {
    *param_6 = 1;
    if (((param_2 != 0x80000000) || (param_1 != 0)) && ((param_2 & 0x40000000) == 0)) {
      *(undefined4 *)(param_6 + 2) = s_1_SNAN._0_4_;
      param_6[4] = s_1_SNAN._4_2_;
      cVar4 = s_1_SNAN[6];
      *(undefined1 *)((int)param_6 + 3) = 6;
      *(char *)(param_6 + 5) = cVar4;
      return 0;
    }
    if ((((param_3 & 0x8000) != 0) && (param_2 == 0xc0000000)) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = s_1_IND._0_4_;
      uVar3 = s_1_IND._4_2_;
      *(undefined1 *)((int)param_6 + 3) = 5;
      param_6[4] = uVar3;
      return 0;
    }
    if ((param_2 == 0x80000000) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = s_1_INF._0_4_;
      uVar3 = s_1_INF._4_2_;
      *(undefined1 *)((int)param_6 + 3) = 5;
      param_6[4] = uVar3;
      return 0;
    }
    *(undefined4 *)(param_6 + 2) = s_1_QNAN._0_4_;
    param_6[4] = s_1_QNAN._4_2_;
    cVar4 = s_1_QNAN[6];
    *(undefined1 *)((int)param_6 + 3) = 6;
    *(char *)(param_6 + 5) = cVar4;
    return 0;
  }
  local_6 = (undefined1)uVar5;
  cStack_5 = (char)(uVar5 >> 8);
  uStack_a = (undefined2)param_2;
  uStack_8 = (undefined2)(param_2 >> 0x10);
  uStack_e = (undefined2)param_1;
  uStack_c = (undefined2)((uint)param_1 >> 0x10);
  local_10 = 0;
  sVar10 = (short)(((uVar5 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar5 * 0x4d10 >>
                  0x10);
  ___multtenpow12(&local_10,-(int)sVar10,1);
  if (0x3ffe < CONCAT11(cStack_5,local_6)) {
    sVar10 = sVar10 + 1;
    ___ld12mul(&local_10,&local_1c);
  }
  *psVar1 = sVar10;
  iVar9 = param_4;
  if (((param_5 & 1) != 0) && (iVar9 = param_4 + sVar10, param_4 + sVar10 < 1)) {
    *psVar1 = 0;
    goto LAB_0055992f;
  }
  if (0x15 < iVar9) {
    iVar9 = 0x15;
  }
  uVar2 = CONCAT11(cStack_5,local_6);
  local_6 = 0;
  cStack_5 = '\0';
  iVar6 = 8;
  iVar11 = uVar2 - 0x3ffe;
  do {
    ___shl_12(&local_10);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (iVar11 < 0) {
    for (uVar5 = -iVar11 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
      ___shr_12(&local_10);
    }
  }
  psVar1 = psVar1 + 2;
  iVar9 = iVar9 + 1;
  psVar7 = psVar1;
  if (0 < iVar9) {
    do {
      param_1 = CONCAT22(uStack_e,local_10);
      param_2 = CONCAT22(uStack_a,uStack_c);
      param_3 = CONCAT13(cStack_5,CONCAT12(local_6,uStack_8));
      ___shl_12(&local_10);
      ___shl_12(&local_10);
      ___add_12(&local_10,&param_1);
      ___shl_12(&local_10);
      cVar4 = cStack_5 + '0';
      cStack_5 = '\0';
      *(char *)psVar7 = cVar4;
      psVar7 = (short *)((int)psVar7 + 1);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  psVar8 = psVar7 + -1;
  if (*(char *)((int)psVar7 + -1) < '5') {
    if (psVar1 <= psVar8) {
      do {
        if ((char)*psVar8 != '0') break;
        psVar8 = (short *)((int)psVar8 + -1);
      } while (psVar1 <= psVar8);
      if (psVar1 <= psVar8) goto LAB_00559a86;
    }
    *(undefined1 *)psVar1 = 0x30;
    *param_6 = 0;
    *(undefined1 *)(param_6 + 1) = 0x20;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(undefined1 *)((int)param_6 + 5) = 0;
    return 1;
  }
  if (psVar1 <= psVar8) {
    do {
      if ((char)*psVar8 != '9') break;
      *(undefined1 *)psVar8 = 0x30;
      psVar8 = (short *)((int)psVar8 + -1);
    } while (psVar1 <= psVar8);
    if (psVar1 <= psVar8) {
      *(char *)psVar8 = (char)*psVar8 + '\x01';
      goto LAB_00559a86;
    }
  }
  psVar8 = (short *)((int)psVar8 + 1);
  *param_6 = *param_6 + 1;
  *(char *)psVar8 = *(char *)psVar8 + '\x01';
LAB_00559a86:
  cVar4 = ((char)psVar8 - (char)param_6) + -3;
  *(char *)((int)param_6 + 3) = cVar4;
  *(undefined1 *)((int)param_6 + cVar4 + 4) = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00559aa2
// Address: 00559aa2
int FUN_00559aa2(undefined4 param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  
  if (param_3 == 0) {
    return param_3;
  }
  iVar1 = ___crtCompareStringA(___mblcid,1,param_1,param_3,param_2,param_3,___mbcodepage);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}

// --------------------------------------------------

// Function: __mbsnbicoll
// Address: 00559ab0
int __mbsnbicoll(undefined4 param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  
  if (param_3 == 0) {
    return param_3;
  }
  iVar1 = ___crtCompareStringA(___mblcid,1,param_1,param_3,param_2,param_3,___mbcodepage);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}

// --------------------------------------------------

// Function: FUN_00559aeb
// Address: 00559aeb
int FUN_00559aeb(void)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *__wenviron;
  piVar3 = __wenviron;
  if (iVar1 == 0) {
    return 0;
  }
  while (((iVar1 = WideCharToMultiByte(1,0,iVar1,0xffffffff,0,0,0,0), iVar1 != 0 &&
          (iVar2 = malloc(iVar1), iVar2 != 0)) &&
         (iVar1 = WideCharToMultiByte(1,0,*piVar3,0xffffffff,iVar2,iVar1,0,0), iVar1 != 0))) {
    ___crtsetenv(iVar2,0);
    iVar1 = piVar3[1];
    piVar3 = piVar3 + 1;
    if (iVar1 == 0) {
      return iVar1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: ___wtomb_environ
// Address: 00559af0
int ___wtomb_environ(void)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *__wenviron;
  piVar3 = __wenviron;
  if (iVar1 == 0) {
    return 0;
  }
  while (((iVar1 = WideCharToMultiByte(1,0,iVar1,0xffffffff,0,0,0,0), iVar1 != 0 &&
          (iVar2 = malloc(iVar1), iVar2 != 0)) &&
         (iVar1 = WideCharToMultiByte(1,0,*piVar3,0xffffffff,iVar2,iVar1,0,0), iVar1 != 0))) {
    ___crtsetenv(iVar2,0);
    iVar1 = piVar3[1];
    piVar3 = piVar3 + 1;
    if (iVar1 == 0) {
      return iVar1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_00559b6a
// Address: 00559b6a
void FUN_00559b6a(int *param_1,int *param_2)
{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  ushort uVar6;
  ushort *puVar7;
  ushort *puVar8;
  short *psStack_20;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  byte bStack_c;
  undefined1 uStack_b;
  undefined2 uStack_a;
  short sStack_8;
  undefined2 uStack_6;
  undefined2 uStack_4;
  ushort uStack_2;
  
  iStack_14 = 0;
  bStack_c = 0;
  uStack_b = 0;
  uStack_a = 0;
  sStack_8 = 0;
  uStack_6 = 0;
  uVar3 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar1 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar6 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar4 = uVar3 + uVar1;
  uStack_4 = 0;
  uStack_2 = 0;
  if (((0x7ffe < uVar1) || (0x7ffe < uVar3)) || (0xbffd < uVar4)) {
    param_1[1] = 0;
    *param_1 = 0;
    param_1[2] = (-(uint)(uVar6 != 0) & 0x80000000) + 0x7fff8000;
    return;
  }
  if (uVar4 < 0x3fc0) {
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return;
  }
  if (((uVar1 == 0) && (uVar4 = uVar4 + 1, (param_1[2] & 0x7fffffffU) == 0)) &&
     ((param_1[1] == 0 && (*param_1 == 0)))) {
    *(undefined2 *)((int)param_1 + 10) = 0;
    return;
  }
  if (((uVar3 == 0) && (uVar4 = uVar4 + 1, (param_2[2] & 0x7fffffffU) == 0)) &&
     ((param_2[1] == 0 && (*param_2 == 0)))) {
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return;
  }
  psStack_20 = &sStack_8;
  iStack_18 = 0;
  iVar5 = 5;
  do {
    if (0 < iVar5) {
      puVar8 = (ushort *)(param_2 + 2);
      puVar7 = (ushort *)(iStack_18 * 2 + (int)param_1);
      iStack_10 = iVar5;
      do {
        iVar2 = ___addl(*(undefined4 *)(psStack_20 + -2),(uint)*puVar8 * (uint)*puVar7,
                        psStack_20 + -2);
        if (iVar2 != 0) {
          *psStack_20 = *psStack_20 + 1;
        }
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + -1;
        iStack_10 = iStack_10 + -1;
      } while (iStack_10 != 0);
    }
    psStack_20 = psStack_20 + 1;
    iStack_18 = iStack_18 + 1;
    iVar5 = iVar5 + -1;
  } while (0 < iVar5);
  uVar4 = uVar4 + 0xc002;
  while ((0 < (short)uVar4 && ((uStack_2 & 0x8000) == 0))) {
    ___shl_12(&bStack_c);
    uVar4 = uVar4 - 1;
  }
  if ((short)uVar4 < 1) {
    uVar4 = uVar4 - 1;
    if ((short)uVar4 < 0) {
      iVar5 = -(int)(short)uVar4;
      uVar4 = uVar4 + (short)iVar5;
      do {
        if ((bStack_c & 1) != 0) {
          iStack_14 = iStack_14 + 1;
        }
        ___shr_12(&bStack_c);
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    if (iStack_14 != 0) {
      bStack_c = bStack_c | 1;
    }
  }
  if ((0x8000 < CONCAT11(uStack_b,bStack_c)) ||
     (iVar2 = CONCAT22(uStack_4,uStack_6), iVar5 = CONCAT22(sStack_8,uStack_a),
     (CONCAT22(uStack_a,CONCAT11(uStack_b,bStack_c)) & 0x1ffff) == 0x18000)) {
    if (CONCAT22(sStack_8,uStack_a) == -1) {
      iVar5 = 0;
      if (CONCAT22(uStack_4,uStack_6) == -1) {
        if (uStack_2 == 0xffff) {
          uStack_2 = 0x8000;
          uVar4 = uVar4 + 1;
          iVar2 = 0;
          iVar5 = 0;
        }
        else {
          uStack_2 = uStack_2 + 1;
          iVar2 = 0;
          iVar5 = 0;
        }
      }
      else {
        iVar2 = CONCAT22(uStack_4,uStack_6) + 1;
      }
    }
    else {
      iVar5 = CONCAT22(sStack_8,uStack_a) + 1;
      iVar2 = CONCAT22(uStack_4,uStack_6);
    }
  }
  sStack_8 = (short)((uint)iVar5 >> 0x10);
  uStack_a = (undefined2)iVar5;
  uStack_4 = (undefined2)((uint)iVar2 >> 0x10);
  uStack_6 = (undefined2)iVar2;
  if (0x7ffe < uVar4) {
    param_1[1] = 0;
    *param_1 = 0;
    param_1[2] = (-(uint)(uVar6 != 0) & 0x80000000) + 0x7fff8000;
    return;
  }
  *(undefined2 *)param_1 = uStack_a;
  *(uint *)((int)param_1 + 2) = CONCAT22(uStack_6,sStack_8);
  *(uint *)((int)param_1 + 6) = CONCAT22(uStack_2,uStack_4);
  *(ushort *)((int)param_1 + 10) = uVar4 | uVar6;
  return;
}

// --------------------------------------------------

// Function: ___ld12mul
// Address: 00559b70
void ___ld12mul(int *param_1,int *param_2)
{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  ushort uVar6;
  ushort *puVar7;
  ushort *puVar8;
  short *local_20;
  int local_18;
  int local_14;
  int local_10;
  byte local_c;
  undefined1 uStack_b;
  undefined2 uStack_a;
  short local_8;
  undefined2 uStack_6;
  undefined2 local_4;
  ushort uStack_2;
  
  local_14 = 0;
  local_c = 0;
  uStack_b = 0;
  uStack_a = 0;
  local_8 = 0;
  uStack_6 = 0;
  uVar3 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar1 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar6 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar4 = uVar3 + uVar1;
  local_4 = 0;
  uStack_2 = 0;
  if (((0x7ffe < uVar1) || (0x7ffe < uVar3)) || (0xbffd < uVar4)) {
    param_1[1] = 0;
    *param_1 = 0;
    param_1[2] = (-(uint)(uVar6 != 0) & 0x80000000) + 0x7fff8000;
    return;
  }
  if (uVar4 < 0x3fc0) {
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return;
  }
  if (((uVar1 == 0) && (uVar4 = uVar4 + 1, (param_1[2] & 0x7fffffffU) == 0)) &&
     ((param_1[1] == 0 && (*param_1 == 0)))) {
    *(undefined2 *)((int)param_1 + 10) = 0;
    return;
  }
  if (((uVar3 == 0) && (uVar4 = uVar4 + 1, (param_2[2] & 0x7fffffffU) == 0)) &&
     ((param_2[1] == 0 && (*param_2 == 0)))) {
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return;
  }
  local_20 = &local_8;
  local_18 = 0;
  iVar5 = 5;
  do {
    if (0 < iVar5) {
      puVar8 = (ushort *)(param_2 + 2);
      puVar7 = (ushort *)(local_18 * 2 + (int)param_1);
      local_10 = iVar5;
      do {
        iVar2 = ___addl(*(undefined4 *)(local_20 + -2),(uint)*puVar8 * (uint)*puVar7,local_20 + -2);
        if (iVar2 != 0) {
          *local_20 = *local_20 + 1;
        }
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + -1;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
    local_20 = local_20 + 1;
    local_18 = local_18 + 1;
    iVar5 = iVar5 + -1;
  } while (0 < iVar5);
  uVar4 = uVar4 + 0xc002;
  while ((0 < (short)uVar4 && ((uStack_2 & 0x8000) == 0))) {
    ___shl_12(&local_c);
    uVar4 = uVar4 - 1;
  }
  if ((short)uVar4 < 1) {
    uVar4 = uVar4 - 1;
    if ((short)uVar4 < 0) {
      iVar5 = -(int)(short)uVar4;
      uVar4 = uVar4 + (short)iVar5;
      do {
        if ((local_c & 1) != 0) {
          local_14 = local_14 + 1;
        }
        ___shr_12(&local_c);
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    if (local_14 != 0) {
      local_c = local_c | 1;
    }
  }
  if ((0x8000 < CONCAT11(uStack_b,local_c)) ||
     (iVar2 = CONCAT22(local_4,uStack_6), iVar5 = CONCAT22(local_8,uStack_a),
     (CONCAT22(uStack_a,CONCAT11(uStack_b,local_c)) & 0x1ffff) == 0x18000)) {
    if (CONCAT22(local_8,uStack_a) == -1) {
      iVar5 = 0;
      if (CONCAT22(local_4,uStack_6) == -1) {
        if (uStack_2 == 0xffff) {
          uStack_2 = 0x8000;
          uVar4 = uVar4 + 1;
          iVar2 = 0;
          iVar5 = 0;
        }
        else {
          uStack_2 = uStack_2 + 1;
          iVar2 = 0;
          iVar5 = 0;
        }
      }
      else {
        iVar2 = CONCAT22(local_4,uStack_6) + 1;
      }
    }
    else {
      iVar5 = CONCAT22(local_8,uStack_a) + 1;
      iVar2 = CONCAT22(local_4,uStack_6);
    }
  }
  local_8 = (short)((uint)iVar5 >> 0x10);
  uStack_a = (undefined2)iVar5;
  local_4 = (undefined2)((uint)iVar2 >> 0x10);
  uStack_6 = (undefined2)iVar2;
  if (0x7ffe < uVar4) {
    param_1[1] = 0;
    *param_1 = 0;
    param_1[2] = (-(uint)(uVar6 != 0) & 0x80000000) + 0x7fff8000;
    return;
  }
  *(undefined2 *)param_1 = uStack_a;
  *(uint *)((int)param_1 + 2) = CONCAT22(uStack_6,local_8);
  *(uint *)((int)param_1 + 6) = CONCAT22(uStack_2,local_4);
  *(ushort *)((int)param_1 + 10) = uVar4 | uVar6;
  return;
}

// --------------------------------------------------

// Function: FUN_00559e28
// Address: 00559e28
void FUN_00559e28(undefined2 *param_1,uint param_2,int param_3)
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 uStack_c;
  undefined4 uStack_a;
  undefined2 uStack_6;
  undefined4 uStack_4;
  
  iVar3 = 0x592668;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      iVar3 = 0x5927c8;
    }
    if (param_3 == 0) {
      *param_1 = 0;
    }
    while (param_2 != 0) {
      iVar3 = iVar3 + 0x54;
      uVar1 = param_2 & 7;
      param_2 = (int)param_2 >> 3;
      if (uVar1 != 0) {
        puVar2 = (undefined4 *)(iVar3 + uVar1 * 0xc);
        if (0x7fff < *(ushort *)(iVar3 + uVar1 * 0xc)) {
          uStack_c = (undefined2)*puVar2;
          uStack_a._0_2_ = (undefined2)((uint)*puVar2 >> 0x10);
          uStack_a._2_2_ = (undefined2)puVar2[1];
          uStack_6 = (undefined2)((uint)puVar2[1] >> 0x10);
          uStack_4 = puVar2[2];
          uStack_a = CONCAT22(uStack_a._2_2_,(undefined2)uStack_a) + -1;
          puVar2 = (undefined4 *)&uStack_c;
        }
        ___ld12mul(param_1,puVar2);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: ___multtenpow12
// Address: 00559e30
void ___multtenpow12(undefined2 *param_1,uint param_2,int param_3)
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 local_c;
  undefined4 uStack_a;
  undefined2 uStack_6;
  undefined4 local_4;
  
  iVar3 = 0x592668;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      iVar3 = 0x5927c8;
    }
    if (param_3 == 0) {
      *param_1 = 0;
    }
    while (param_2 != 0) {
      iVar3 = iVar3 + 0x54;
      uVar1 = param_2 & 7;
      param_2 = (int)param_2 >> 3;
      if (uVar1 != 0) {
        puVar2 = (undefined4 *)(iVar3 + uVar1 * 0xc);
        if (0x7fff < *(ushort *)(iVar3 + uVar1 * 0xc)) {
          local_c = (undefined2)*puVar2;
          uStack_a._0_2_ = (undefined2)((uint)*puVar2 >> 0x10);
          uStack_a._2_2_ = (undefined2)puVar2[1];
          uStack_6 = (undefined2)((uint)puVar2[1] >> 0x10);
          local_4 = puVar2[2];
          uStack_a = CONCAT22(uStack_a._2_2_,(undefined2)uStack_a) + -1;
          puVar2 = (undefined4 *)&local_c;
        }
        ___ld12mul(param_1,puVar2);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00559eba
// Address: 00559eba
int FUN_00559eba(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                undefined4 param_5,int param_6,int param_7)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  
  if (DAT_00888440._4_4_ == 0) {
    iVar1 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar1 == 0) {
      iVar1 = CompareStringA(0,0,"",1,"",1);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_00888440._4_4_ = 2;
    }
    else {
      DAT_00888440._4_4_ = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_0055a0d0(param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_0055a0d0(param_5,param_6);
  }
  if ((param_4 == 0) || (param_6 == 0)) {
    if (param_4 == param_6) {
      return 2;
    }
    param_6 = ((-1 < param_4 - param_6) - 1 & 0xfffffffe) + 3;
  }
  else {
    if (DAT_00888440._4_4_ == 1) {
      iVar1 = CompareStringW(param_1,param_2,param_3,param_4,param_5,param_6);
      return iVar1;
    }
    if (DAT_00888440._4_4_ == 2) {
      if (param_7 == 0) {
        param_7 = ___lc_codepage;
      }
      uVar9 = 0;
      uVar7 = 0x220;
      iVar1 = param_7;
      iVar8 = param_4;
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
      iVar3 = WideCharToMultiByte(param_7,0x220,uVar9,param_4,iVar3,iVar2,0,0);
      if ((((iVar3 != 0) &&
           (iVar3 = WideCharToMultiByte(param_7,0x220,uVar7,param_3,0,0,0,0), iVar3 != 0)) &&
          (iVar1 = malloc(iVar3), iVar1 != 0)) &&
         (iVar4 = WideCharToMultiByte(param_7,0x220,uVar7,param_3,iVar1,iVar3,0,0), iVar4 != 0)) {
        iVar2 = CompareStringA(iVar5,uVar6,iVar8,iVar2,iVar1,iVar3);
        free(iVar8);
        free(iVar1);
        return iVar2;
      }
      free(iVar8);
      free(iVar1);
      return 0;
    }
  }
  return param_6;
}

// --------------------------------------------------

// Function: FUN_0055a0c2
// Address: 0055a0c2
int FUN_0055a0c2(short *param_1,int param_2)
{
  short *psVar1;
  int iVar2;
  
  psVar1 = param_1;
  iVar2 = param_2;
  if (param_2 != 0) {
    do {
      iVar2 = iVar2 + -1;
      if (*psVar1 == 0) goto LAB_0055a0f9;
      psVar1 = psVar1 + 1;
    } while (iVar2 != 0);
  }
  if (*psVar1 != 0) {
    return param_2;
  }
LAB_0055a0f9:
  return (int)psVar1 - (int)param_1 >> 1;
}

// --------------------------------------------------

// Function: FUN_0055a0d0
// Address: 0055a0d0
int FUN_0055a0d0(short *param_1,int param_2)
{
  short *psVar1;
  int iVar2;
  
  psVar1 = param_1;
  iVar2 = param_2;
  if (param_2 != 0) {
    do {
      iVar2 = iVar2 + -1;
      if (*psVar1 == 0) goto LAB_0055a0f9;
      psVar1 = psVar1 + 1;
    } while (iVar2 != 0);
  }
  if (*psVar1 != 0) {
    return param_2;
  }
LAB_0055a0f9:
  return (int)psVar1 - (int)param_1 >> 1;
}

// --------------------------------------------------

// Function: FUN_0055a105
// Address: 0055a105
int FUN_0055a105(undefined4 param_1,undefined4 param_2,byte *param_3,int param_4,byte *param_5,
                int param_6,int param_7)
{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_EDI;
  undefined4 uVar6;
  uint uStack_14;
  byte abStack_e [2];
  undefined4 uStack_c;
  
  if (DAT_00888448 == 0) {
    iVar1 = CompareStringA(0,0,"",1,"",1);
    if (iVar1 == 0) {
      iVar1 = CompareStringW(0,0,L"",1,L"",1);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_00888448 = 1;
    }
    else {
      DAT_00888448 = 2;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_0055a3e0(param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_0055a3e0(param_5,param_6);
  }
  if (DAT_00888448 == 2) {
    iVar1 = CompareStringA(param_1,param_2,param_3,param_4,param_5,param_6);
    return iVar1;
  }
  iVar1 = DAT_00888448;
  if (DAT_00888448 == 1) {
    if (param_7 == 0) {
      param_7 = ___lc_codepage;
    }
    if ((param_4 == 0) || (param_6 == 0)) {
      if (param_4 == param_6) {
        return 2;
      }
      if (1 < param_6) {
        return 1;
      }
      if (1 < param_4) {
        return 3;
      }
      iVar1 = GetCPInfo(param_7,&uStack_14);
      if (iVar1 == 0) {
        return 0;
      }
      if (0 < param_4) {
        if (uStack_14 < 2) {
          return 3;
        }
        pbVar2 = abStack_e;
        while( true ) {
          if ((abStack_e[0] == 0) || (pbVar2[1] == 0)) {
            return 3;
          }
          if ((*pbVar2 <= *param_3) && (*param_3 <= pbVar2[1])) break;
          abStack_e[0] = pbVar2[2];
          pbVar2 = pbVar2 + 2;
        }
        return 2;
      }
      if (0 < param_6) {
        if (uStack_14 < 2) {
          return 1;
        }
        pbVar2 = abStack_e;
        while( true ) {
          if ((abStack_e[0] == 0) || (pbVar2[1] == 0)) {
            return 1;
          }
          if ((*pbVar2 <= *param_5) && (*param_5 <= pbVar2[1])) break;
          abStack_e[0] = pbVar2[2];
          pbVar2 = pbVar2 + 2;
        }
        return 2;
      }
    }
    uVar6 = 0;
    iVar3 = MultiByteToWideChar(param_7,9,param_3,param_4,0,0);
    if (iVar3 == 0) {
      return 0;
    }
    iVar1 = malloc(iVar3 * 2);
    if (iVar1 == 0) {
      return 0;
    }
    iVar4 = MultiByteToWideChar(param_7,1,uStack_c,param_4,iVar1,iVar3);
    if ((((iVar4 != 0) && (iVar4 = MultiByteToWideChar(param_7,9,unaff_EBX,0,0,0), iVar4 != 0)) &&
        (unaff_EBP = malloc(iVar4 * 2), unaff_EBP != 0)) &&
       (iVar5 = MultiByteToWideChar(param_7,1,unaff_EBX,0,unaff_EBP,iVar4), iVar5 != 0)) {
      iVar1 = CompareStringW(uVar6,unaff_EDI,uStack_14,iVar3,unaff_EBP,iVar4);
    }
    free(uStack_14);
    free(unaff_EBP);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: ___crtCompareStringA
// Address: 0055a110
int ___crtCompareStringA
              (undefined4 param_1,undefined4 param_2,byte *param_3,int param_4,byte *param_5,
              int param_6,int param_7)
{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_EDI;
  undefined4 uVar6;
  uint uStack_14;
  byte abStack_e [2];
  undefined4 uStack_c;
  
  if (DAT_00888448 == 0) {
    iVar1 = CompareStringA(0,0,"",1,"",1);
    if (iVar1 == 0) {
      iVar1 = CompareStringW(0,0,L"",1,L"",1);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_00888448 = 1;
    }
    else {
      DAT_00888448 = 2;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_0055a3e0(param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_0055a3e0(param_5,param_6);
  }
  if (DAT_00888448 == 2) {
    iVar1 = CompareStringA(param_1,param_2,param_3,param_4,param_5,param_6);
    return iVar1;
  }
  iVar1 = DAT_00888448;
  if (DAT_00888448 == 1) {
    if (param_7 == 0) {
      param_7 = ___lc_codepage;
    }
    if ((param_4 == 0) || (param_6 == 0)) {
      if (param_4 == param_6) {
        return 2;
      }
      if (1 < param_6) {
        return 1;
      }
      if (1 < param_4) {
        return 3;
      }
      iVar1 = GetCPInfo(param_7,&uStack_14);
      if (iVar1 == 0) {
        return 0;
      }
      if (0 < param_4) {
        if (uStack_14 < 2) {
          return 3;
        }
        pbVar2 = abStack_e;
        while( true ) {
          if ((abStack_e[0] == 0) || (pbVar2[1] == 0)) {
            return 3;
          }
          if ((*pbVar2 <= *param_3) && (*param_3 <= pbVar2[1])) break;
          abStack_e[0] = pbVar2[2];
          pbVar2 = pbVar2 + 2;
        }
        return 2;
      }
      if (0 < param_6) {
        if (uStack_14 < 2) {
          return 1;
        }
        pbVar2 = abStack_e;
        while( true ) {
          if ((abStack_e[0] == 0) || (pbVar2[1] == 0)) {
            return 1;
          }
          if ((*pbVar2 <= *param_5) && (*param_5 <= pbVar2[1])) break;
          abStack_e[0] = pbVar2[2];
          pbVar2 = pbVar2 + 2;
        }
        return 2;
      }
    }
    uVar6 = 0;
    iVar3 = MultiByteToWideChar(param_7,9,param_3,param_4,0,0);
    if (iVar3 == 0) {
      return 0;
    }
    iVar1 = malloc(iVar3 * 2);
    if (iVar1 == 0) {
      return 0;
    }
    iVar4 = MultiByteToWideChar(param_7,1,uStack_c,param_4,iVar1,iVar3);
    if ((((iVar4 != 0) && (iVar4 = MultiByteToWideChar(param_7,9,unaff_EBX,0,0,0), iVar4 != 0)) &&
        (unaff_EBP = malloc(iVar4 * 2), unaff_EBP != 0)) &&
       (iVar5 = MultiByteToWideChar(param_7,1,unaff_EBX,0,unaff_EBP,iVar4), iVar5 != 0)) {
      iVar1 = CompareStringW(uVar6,unaff_EDI,uStack_14,iVar3,unaff_EBP,iVar4);
    }
    free(uStack_14);
    free(unaff_EBP);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0055a3d5
// Address: 0055a3d5
int FUN_0055a3d5(char *param_1,int param_2)
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

// Function: FUN_0055a3e0
// Address: 0055a3e0
int FUN_0055a3e0(char *param_1,int param_2)
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

// Function: FUN_0055a40f
// Address: 0055a40f
undefined4 FUN_0055a40f(char *param_1,int param_2)
{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  pcVar4 = (char *)__mbschr(param_1,0x3d);
  if (pcVar4 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == pcVar4) {
    return 0xffffffff;
  }
  bVar12 = pcVar4[1] == '\0';
  if (__environ == ___initenv) {
    __environ = (int *)FUN_0055a6a0(__environ);
  }
  if (__environ == (int *)0x0) {
    if ((param_2 == 0) || (__wenviron == (undefined4 *)0x0)) {
      if (bVar12) {
        return 0;
      }
      __environ = (int *)malloc(4);
      if (__environ == (int *)0x0) {
        return 0xffffffff;
      }
      *__environ = 0;
      if (__wenviron == (undefined4 *)0x0) {
        __wenviron = (undefined4 *)malloc(4);
        if (__wenviron == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *__wenviron = 0;
      }
    }
    else {
      iVar5 = ___wtomb_environ();
      if (iVar5 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar7 = __environ;
  iVar6 = (int)pcVar4 - (int)param_1;
  iVar5 = FUN_0055a620(param_1,iVar6);
  if ((iVar5 < 0) || (*piVar7 == 0)) {
    if (bVar12) {
      return 0;
    }
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    piVar7 = (int *)realloc(piVar7,iVar5 * 4 + 8);
    if (piVar7 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar7[iVar5] = (int)param_1;
    piVar7[iVar5 + 1] = 0;
    __environ = piVar7;
  }
  else if (bVar12) {
    free(piVar7[iVar5]);
    iVar2 = piVar7[iVar5];
    piVar3 = piVar7 + iVar5;
    while (iVar2 != 0) {
      *piVar3 = piVar3[1];
      iVar5 = iVar5 + 1;
      iVar2 = piVar3[1];
      piVar3 = piVar3 + 1;
    }
    piVar7 = (int *)realloc(piVar7,iVar5 * 4);
    if (piVar7 != (int *)0x0) {
      __environ = piVar7;
    }
  }
  else {
    piVar7[iVar5] = (int)param_1;
  }
  if (param_2 != 0) {
    uVar8 = 0xffffffff;
    pcVar4 = param_1;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = (char *)malloc(~uVar8 + 1);
    if (pcVar4 != (char *)0x0) {
      uVar8 = 0xffffffff;
      do {
        pcVar10 = param_1;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar10 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar10;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      pcVar10 = pcVar10 + -uVar8;
      pcVar11 = pcVar4;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar11 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar11 = pcVar11 + 1;
      }
      pcVar4[iVar6] = '\0';
      SetEnvironmentVariableA(pcVar4,~-(uint)bVar12 & (uint)(pcVar4 + iVar6 + 1));
      free(pcVar4);
      return 0;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: ___crtsetenv
// Address: 0055a410
undefined4 ___crtsetenv(char *param_1,int param_2)
{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  pcVar4 = (char *)__mbschr(param_1,0x3d);
  if (pcVar4 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == pcVar4) {
    return 0xffffffff;
  }
  bVar12 = pcVar4[1] == '\0';
  if (__environ == ___initenv) {
    __environ = (int *)FUN_0055a6a0(__environ);
  }
  if (__environ == (int *)0x0) {
    if ((param_2 == 0) || (__wenviron == (undefined4 *)0x0)) {
      if (bVar12) {
        return 0;
      }
      __environ = (int *)malloc(4);
      if (__environ == (int *)0x0) {
        return 0xffffffff;
      }
      *__environ = 0;
      if (__wenviron == (undefined4 *)0x0) {
        __wenviron = (undefined4 *)malloc(4);
        if (__wenviron == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *__wenviron = 0;
      }
    }
    else {
      iVar5 = ___wtomb_environ();
      if (iVar5 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar7 = __environ;
  iVar6 = (int)pcVar4 - (int)param_1;
  iVar5 = FUN_0055a620(param_1,iVar6);
  if ((iVar5 < 0) || (*piVar7 == 0)) {
    if (bVar12) {
      return 0;
    }
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    piVar7 = (int *)realloc(piVar7,iVar5 * 4 + 8);
    if (piVar7 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar7[iVar5] = (int)param_1;
    piVar7[iVar5 + 1] = 0;
    __environ = piVar7;
  }
  else if (bVar12) {
    free(piVar7[iVar5]);
    iVar2 = piVar7[iVar5];
    piVar3 = piVar7 + iVar5;
    while (iVar2 != 0) {
      *piVar3 = piVar3[1];
      iVar5 = iVar5 + 1;
      iVar2 = piVar3[1];
      piVar3 = piVar3 + 1;
    }
    piVar7 = (int *)realloc(piVar7,iVar5 * 4);
    if (piVar7 != (int *)0x0) {
      __environ = piVar7;
    }
  }
  else {
    piVar7[iVar5] = (int)param_1;
  }
  if (param_2 != 0) {
    uVar8 = 0xffffffff;
    pcVar4 = param_1;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = (char *)malloc(~uVar8 + 1);
    if (pcVar4 != (char *)0x0) {
      uVar8 = 0xffffffff;
      do {
        pcVar10 = param_1;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar10 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar10;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      pcVar10 = pcVar10 + -uVar8;
      pcVar11 = pcVar4;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar11 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar11 = pcVar11 + 1;
      }
      pcVar4[iVar6] = '\0';
      SetEnvironmentVariableA(pcVar4,~-(uint)bVar12 & (uint)(pcVar4 + iVar6 + 1));
      free(pcVar4);
      return 0;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0055a613
// Address: 0055a613
int FUN_0055a613(undefined4 param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = *__environ;
  piVar2 = __environ;
  if (iVar1 == 0) {
    return 0;
  }
  while ((iVar1 = __mbsnbicoll(param_1,iVar1,param_2), iVar1 != 0 ||
         ((*(char *)(*piVar2 + param_2) != '=' && (*(char *)(*piVar2 + param_2) != '\0'))))) {
    iVar1 = piVar2[1];
    piVar2 = piVar2 + 1;
    if (iVar1 == 0) {
      return -((int)piVar2 - (int)__environ >> 2);
    }
  }
  return (int)piVar2 - (int)__environ >> 2;
}

// --------------------------------------------------

// Function: FUN_0055a620
// Address: 0055a620
int FUN_0055a620(undefined4 param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = *__environ;
  piVar2 = __environ;
  if (iVar1 == 0) {
    return 0;
  }
  while ((iVar1 = __mbsnbicoll(param_1,iVar1,param_2), iVar1 != 0 ||
         ((*(char *)(*piVar2 + param_2) != '=' && (*(char *)(*piVar2 + param_2) != '\0'))))) {
    iVar1 = piVar2[1];
    piVar2 = piVar2 + 1;
    if (iVar1 == 0) {
      return -((int)piVar2 - (int)__environ >> 2);
    }
  }
  return (int)piVar2 - (int)__environ >> 2;
}

// --------------------------------------------------

// Function: FUN_0055a694
// Address: 0055a694
undefined4 * FUN_0055a694(int *param_1)
{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = (undefined4 *)malloc(iVar5 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    iVar5 = *param_1;
    puVar6 = puVar3;
    while (iVar5 != 0) {
      param_1 = param_1 + 1;
      uVar4 = __strdup(iVar5);
      *puVar6 = uVar4;
      puVar6 = puVar6 + 1;
      iVar5 = *param_1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}

// --------------------------------------------------

// Function: FUN_0055a6a0
// Address: 0055a6a0
undefined4 * FUN_0055a6a0(int *param_1)
{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = (undefined4 *)malloc(iVar5 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    iVar5 = *param_1;
    puVar6 = puVar3;
    while (iVar5 != 0) {
      param_1 = param_1 + 1;
      uVar4 = __strdup(iVar5);
      *puVar6 = uVar4;
      puVar6 = puVar6 + 1;
      iVar5 = *param_1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}

// --------------------------------------------------

// Function: FUN_0055a70f
// Address: 0055a70f
char * FUN_0055a70f(char *param_1)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_1 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar2 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char *)malloc(~uVar3);
    if (pcVar2 != (char *)0x0) {
      uVar3 = 0xffffffff;
      do {
        pcVar5 = param_1;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar5 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar5;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar5 = pcVar5 + -uVar3;
      pcVar6 = pcVar2;
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
      return pcVar2;
    }
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: __strdup
// Address: 0055a710
char * __strdup(char *param_1)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_1 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar2 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char *)malloc(~uVar3);
    if (pcVar2 != (char *)0x0) {
      uVar3 = 0xffffffff;
      do {
        pcVar5 = param_1;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar5 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar5;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar5 = pcVar5 + -uVar3;
      pcVar6 = pcVar2;
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
      return pcVar2;
    }
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: FUN_0055a789
// Address: 0055a789
void __fastcall FUN_0055a789(int *param_1)
{
  int iVar1;
  
  *(undefined4 *)(*(int *)(*param_1 + 4) + 0x30 + (int)param_1) = 0;
  if ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0x24) & 0x2000) != 0) {
    iVar1 = (**(code **)(**(int **)((int)param_1 + *(int *)(*param_1 + 4) + 4) + 4))();
    if (iVar1 == -1) {
      *(undefined4 *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) = 6;
    }
  }
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) & 0x4000) != 0) {
    iVar1 = fflush(&DAT_00591e68);
    if (iVar1 == -1) {
      *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) =
           *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 2;
    }
    iVar1 = fflush(&DAT_00591e88);
    if (iVar1 == -1) {
      *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) =
           *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0055a821
// Address: 0055a821
// [HELPER] s_: ""
ostream * __thiscall FUN_0055a821(ostream *param_1,char *param_2)
{
  int iVar1;
  
  iVar1 = ostream::opfx(param_1);
  if (iVar1 != 0) {
    ostream::writepad(param_1,s_,param_2);
    ostream::osfx(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055a85a
// Address: 0055a85a
int * __fastcall FUN_0055a85a(int *param_1)
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 4))();
  if (iVar1 == -1) {
    *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) =
         *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 2;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055a88c
// Address: 0055a88c
int * __thiscall FUN_0055a88c(int *param_1,int param_2)
{
  if (param_2 != 0) {
    *param_1 = (int)&ostream::_vbtable_;
    ios::ios((ios *)(param_1 + 2));
  }
  *(undefined ***)(*(int *)(*param_1 + 4) + (int)param_1) = &ostream::_vftable_;
  param_1[1] = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055a8cc
// Address: 0055a8cc
char * __thiscall FUN_0055a8cc(ios *param_1,byte param_2)
{
  ostream::~ostream((ostream *)param_1);
  ios::~ios(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(&param_1[-1].x_fill);
  }
  return &param_1[-1].x_fill;
}

// --------------------------------------------------

// Function: FUN_0055a8fd
// Address: 0055a8fd
int * __thiscall FUN_0055a8fd(int *param_1,streambuf *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561ef6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 != 0) {
    *param_1 = (int)&ostream::_vbtable_;
    ios::ios((ios *)(param_1 + 2));
    uStack_4 = 0;
  }
  *(undefined ***)(*(int *)(*param_1 + 4) + (int)param_1) = &ostream::_vftable_;
  ios::init((ios *)(*(int *)(*param_1 + 4) + (int)param_1),param_2);
  param_1[1] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055a985
// Address: 0055a985
int * __thiscall FUN_0055a985(int *param_1,int *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561f1a;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 != 0) {
    *param_1 = (int)&ostream::_vbtable_;
    ios::ios((ios *)(param_1 + 2));
    uStack_4 = 0;
  }
  *(undefined ***)(*(int *)(*param_1 + 4) + (int)param_1) = &ostream::_vftable_;
  ios::init((ios *)(*(int *)(*param_1 + 4) + (int)param_1),
            *(streambuf **)(*(int *)(*param_2 + 4) + 4 + (int)param_2));
  param_1[1] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055aa1e
// Address: 0055aa1e
void __fastcall FUN_0055aa1e(int param_1)
{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -8) + 4) + -8 + param_1) = &ostream::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_0055aa2f
// Address: 0055aa2f
int * __thiscall FUN_0055aa2f(int *param_1,streambuf *param_2)
{
  undefined4 *puVar1;
  ios *piVar2;
  undefined4 *unaff_FS_OFFSET;
  ios iStack_40;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561f38;
  *unaff_FS_OFFSET = &uStack_c;
  if ((*(int *)(*(int *)(*param_1 + 4) + 0x1c + (int)param_1) != 0) &&
     (puVar1 = *(undefined4 **)((int)param_1 + *(int *)(*param_1 + 4) + 4),
     puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 *)(*(int *)(*param_1 + 4) + 4 + (int)param_1) = 0;
  piVar2 = (ios *)ios::ios(&iStack_40);
  uStack_4 = 0;
  ios::operator=((ios *)(*(int *)(*param_1 + 4) + (int)param_1),piVar2);
  uStack_4 = 0xffffffff;
  ios::~ios(&iStack_40);
  *(undefined4 *)(*(int *)(*param_1 + 4) + 0x1c + (int)param_1) = 0;
  ios::init((ios *)(*(int *)(*param_1 + 4) + (int)param_1),param_2);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055aad6
// Address: 0055aad6
ostream * __thiscall FUN_0055aad6(ostream *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561f66;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 != 0) {
    *(undefined8 **)param_1 = &ostream_withassign::_vbtable_;
    ios::ios((ios *)&param_1->field_0x8);
    uStack_4 = 0;
  }
  ostream::ostream(param_1);
  *(undefined ***)(&param_1->field_0x0 + *(int *)(*(int *)param_1 + 4)) =
       &ostream_withassign::_vftable_;
  *unaff_FS_OFFSET = param_1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055ab56
// Address: 0055ab56
char * __thiscall FUN_0055ab56(ios *param_1,byte param_2)
{
  ostream_withassign::~ostream_withassign((ostream_withassign *)param_1);
  ios::~ios(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(&param_1[-1].x_fill);
  }
  return &param_1[-1].x_fill;
}

// --------------------------------------------------

// Function: FUN_0055ab8d
// Address: 0055ab8d
ostream * __thiscall FUN_0055ab8d(ostream *param_1,streambuf *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561f86;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 != 0) {
    *(undefined8 **)param_1 = &ostream_withassign::_vbtable_;
    ios::ios((ios *)&param_1->field_0x8);
    uStack_4 = 0;
  }
  ostream::ostream(param_1,param_2);
  *(undefined ***)(&param_1->field_0x0 + *(int *)(*(int *)param_1 + 4)) =
       &ostream_withassign::_vftable_;
  *unaff_FS_OFFSET = param_1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055ac0b
// Address: 0055ac0b
void __fastcall FUN_0055ac0b(ostream *param_1)
{
  *(undefined ***)(*(int *)(*(int *)&param_1[-1].field_0x34 + 4) + -8 + (int)param_1) =
       &ostream_withassign::_vftable_;
  ostream::~ostream(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0055ac23
// Address: 0055ac23
int * __thiscall FUN_0055ac23(int *param_1,char *param_2,char *param_3)
{
  char cVar1;
  byte bVar2;
  int *piVar3;
  bool bVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  
  pcVar5 = param_2;
  uVar7 = 0xffffffff;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  iVar8 = ~uVar7 - 1;
  uVar7 = 0xffffffff;
  pcVar10 = param_3;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  iVar9 = ~uVar7 - 1;
  uVar7 = *(uint *)(*(int *)(*param_1 + 4) + 0x30 + (int)param_1);
  if ((uint)(iVar8 + iVar9) < uVar7) {
    param_2 = (char *)((uVar7 - iVar9) - iVar8);
  }
  else {
    param_2 = (char *)0x0;
  }
  if (((*(byte *)((int)param_1 + *(int *)(*param_1 + 4) + 0x24) & 10) == 0) &&
     (iVar6 = (int)param_2 + -1, bVar4 = 0 < (int)param_2, iVar11 = (int)param_2,
     param_2 = (char *)iVar6, bVar4)) {
    do {
      bVar2 = *(byte *)((int)param_1 + *(int *)(*param_1 + 4) + 0x2c);
      piVar3 = *(int **)((int)param_1 + *(int *)(*param_1 + 4) + 4);
      if ((byte *)piVar3[7] < (byte *)piVar3[8]) {
        *(byte *)piVar3[7] = bVar2;
        uVar7 = (uint)bVar2;
        piVar3[7] = piVar3[7] + 1;
      }
      else {
        uVar7 = (**(code **)(*piVar3 + 0x1c))(bVar2);
      }
      if (uVar7 == 0xffffffff) {
        *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) =
             *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 6;
      }
      iVar11 = iVar11 + -1;
      param_2 = (char *)((int)param_2 + -1);
    } while (iVar11 != 0);
  }
  if ((iVar8 != 0) &&
     (iVar11 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 0x14))
                         (pcVar5,iVar8), iVar11 != iVar8)) {
    *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) =
         *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 6;
  }
  if (((*(byte *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) & 8) != 0) && (0 < (int)param_2)) {
    do {
      bVar2 = *(byte *)((int)param_1 + *(int *)(*param_1 + 4) + 0x2c);
      piVar3 = *(int **)((int)param_1 + *(int *)(*param_1 + 4) + 4);
      if ((byte *)piVar3[7] < (byte *)piVar3[8]) {
        *(byte *)piVar3[7] = bVar2;
        uVar7 = (uint)bVar2;
        piVar3[7] = piVar3[7] + 1;
      }
      else {
        uVar7 = (**(code **)(*piVar3 + 0x1c))(bVar2);
      }
      if (uVar7 == 0xffffffff) {
        *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) =
             *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 6;
      }
      param_2 = (char *)((int)param_2 + -1);
    } while (param_2 != (char *)0x0);
  }
  iVar8 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 0x14))(param_3,iVar9)
  ;
  if (iVar8 != iVar9) {
    *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) =
         *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 6;
  }
  if (((*(byte *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) & 2) != 0) && (0 < iVar9)) {
    do {
      bVar2 = *(byte *)(*(int *)(*param_1 + 4) + 0x2c + (int)param_1);
      piVar3 = *(int **)((int)param_1 + *(int *)(*param_1 + 4) + 4);
      if ((byte *)piVar3[7] < (byte *)piVar3[8]) {
        *(byte *)piVar3[7] = bVar2;
        uVar7 = (uint)bVar2;
        piVar3[7] = piVar3[7] + 1;
      }
      else {
        uVar7 = (**(code **)(*piVar3 + 0x1c))(bVar2);
      }
      if (uVar7 == 0xffffffff) {
        *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) =
             *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 6;
      }
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055ae25
// Address: 0055ae25
istream * __thiscall FUN_0055ae25(istream *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = istream::ipfx(param_1,1);
  if ((iVar1 != 0) && (param_3 != 0)) {
    if (param_3 != 1) {
      do {
        iVar1 = streambuf::sgetc(*(streambuf **)
                                  ((int)&param_1->_fGline + *(int *)(*(int *)param_1 + 4)));
        if (iVar1 == -1) {
          *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) =
               *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) | 1;
          if (uVar2 == 0) {
            *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) =
                 *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) | 2;
          }
          break;
        }
        if (iVar1 == param_4) {
          if (param_1->_fGline != 0) {
            param_1->x_gcount = param_1->x_gcount + 1;
            streambuf::stossc(*(streambuf **)
                               ((int)&param_1->_fGline + *(int *)(*(int *)param_1 + 4)));
          }
          break;
        }
        if (param_2 != 0) {
          *(char *)(uVar2 + param_2) = (char)iVar1;
        }
        streambuf::stossc(*(streambuf **)((int)&param_1->_fGline + *(int *)(*(int *)param_1 + 4)));
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_3 - 1U);
    }
    param_1->x_gcount = param_1->x_gcount + uVar2;
  }
  if ((param_2 != 0) && (param_3 != 0)) {
    *(undefined1 *)(uVar2 + param_2) = 0;
  }
  param_1->_fGline = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055aef9
// Address: 0055aef9
// [HELPER] s__d: "%d"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ostream * __thiscall FUN_0055aef9(ostream *param_1,int param_2)
{
  uint uVar1;
  byte bVar2;
  int iVar3;
  ushort uStack_14;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined2 uStack_10;
  undefined1 uStack_e;
  undefined1 uStack_d;
  char acStack_c [12];
  
  uStack_10 = s__d;
  uStack_e = DAT_00584612;
  uStack_d = 0;
  uStack_14 = _s_;
  uStack_12 = DAT_00578052;
  uStack_11 = 0;
  iVar3 = ostream::opfx(param_1);
  if (iVar3 != 0) {
    if (param_2 != 0) {
      uVar1 = *(uint *)(&param_1->field_0x24 + *(int *)(*(int *)param_1 + 4));
      if ((uVar1 & 0x60) == 0) {
        if ((0 < param_2) && ((uVar1 & 0x400) != 0)) {
          uStack_14 = CONCAT11(uStack_14._1_1_,0x2b);
        }
      }
      else {
        if ((uVar1 & 0x40) == 0) {
          uStack_10 = CONCAT11(0x6f,(undefined1)uStack_10);
        }
        else {
          bVar2 = ~(byte)(uVar1 >> 4);
          uStack_10 = CONCAT11(bVar2,(undefined1)uStack_10) & 0x20ff | 0x5800;
          uStack_14 = CONCAT11(bVar2,(undefined1)uStack_14) & 0x20ff | 0x5800;
        }
        if (((&param_1->field_0x24)[*(int *)(*(int *)param_1 + 4)] & 0x80) != 0) {
          uStack_14 = CONCAT11(uStack_14._1_1_,0x30);
        }
      }
    }
    sprintf(acStack_c,&uStack_10,param_2);
    ostream::writepad(param_1,(char *)&uStack_14,acStack_c);
    ostream::osfx(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055afc9
// Address: 0055afc9
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

ostream * __thiscall FUN_0055afc9(ostream *param_1,undefined4 param_2,undefined4 param_3)
{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  char acStack_24 [12];
  char cStack_18;
  char acStack_17 [19];
  undefined4 uStack_4;
  
  uStack_4 = 0x55afda;
  iVar2 = param_1->x_floatused;
  param_1->x_floatused = 0;
  uVar6 = (-(uint)(iVar2 != 0) & 0xfffffff7) + 0xf;
  pcVar4 = &cStack_18;
  if (*(uint *)(&param_1->field_0x28 + *(int *)(*(int *)param_1 + 4)) < uVar6) {
    uVar6 = *(uint *)(&param_1->field_0x28 + *(int *)(*(int *)param_1 + 4));
  }
  iVar2 = ostream::opfx(param_1);
  if (iVar2 != 0) {
    bVar7 = (*(uint *)(&param_1->field_0x24 + *(int *)(*(int *)param_1 + 4)) & 0x400) != 0;
    if (bVar7) {
      acStack_24[0] = '+';
    }
    uVar5 = (uint)bVar7;
    if ((*(uint *)(&param_1->field_0x24 + *(int *)(*(int *)param_1 + 4)) & 0x100) != 0) {
      acStack_24[uVar5] = '#';
      uVar5 = uVar5 + 1;
    }
    acStack_24[uVar5] = '\0';
    iVar3 = sprintf(acStack_24 + 4,"%%%s.%.0ug",acStack_24,uVar6);
    iVar2 = *(int *)param_1;
    uVar6 = *(uint *)(&param_1->field_0x24 + *(int *)(iVar2 + 4)) & ios::floatfield;
    if (uVar6 == 0x1000) {
      acStack_24[iVar3 + 3] = 'f';
    }
    else {
      if (uVar6 == 0x800) {
        acStack_24[iVar3 + 3] = 'e';
      }
      if ((*(uint *)(&param_1->field_0x24 + *(int *)(iVar2 + 4)) & 0x200) != 0) {
        cVar1 = toupper((int)acStack_24[iVar3 + 3]);
        acStack_24[iVar3 + 3] = cVar1;
      }
    }
    sprintf(&cStack_18,acStack_24 + 4,param_2,param_3);
    iVar2 = 0;
    if ((cStack_18 == '+') || (cStack_18 == '-')) {
      acStack_24[0] = cStack_18;
      iVar2 = 1;
      pcVar4 = acStack_17;
    }
    acStack_24[iVar2] = '\0';
    ostream::writepad(param_1,acStack_24,pcVar4);
    ostream::osfx(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055b107
// Address: 0055b107
void __fastcall FUN_0055b107(undefined4 *param_1)
{
  *param_1 = &ios::_vftable_;
  param_1[1] = 0;
  param_1[2] = 4;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 6;
  *(undefined1 *)(param_1 + 0xb) = 0x20;
  param_1[0xc] = 0;
  param_1[7] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0055b142
// Address: 0055b142
ios * __thiscall FUN_0055b142(ios *param_1,byte param_2)
{
  ios::~ios(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055b16e
// Address: 0055b16e
void __thiscall FUN_0055b16e(undefined4 *param_1,int param_2)
{
  param_1[1] = param_2;
  *param_1 = &ios::_vftable_;
  param_1[10] = 6;
  *(undefined1 *)(param_1 + 0xb) = 0x20;
  param_1[2] = (-(uint)(param_2 != 0) & 0xfffffffc) + 4;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xc] = 0;
  param_1[7] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0055b1ae
// Address: 0055b1ae
ios * __thiscall FUN_0055b1ae(ios *param_1,ios *param_2)
{
  param_1->bp = (streambuf *)0x0;
  param_1->x_delbuf = 0;
  param_1->_padding_ = (int)&ios::_vftable_;
  ios::operator=(param_1,param_2);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055b1d1
// Address: 0055b1d1
void __fastcall FUN_0055b1d1(undefined4 *param_1)
{
  *param_1 = &ios::_vftable_;
  if ((param_1[7] != 0) && ((undefined4 *)param_1[1] != (undefined4 *)0x0)) {
    (*(code *)**(undefined4 **)param_1[1])(1);
  }
  param_1[1] = 0;
  param_1[2] = 4;
  return;
}

// --------------------------------------------------

// Function: FUN_0055b20d
// Address: 0055b20d
void __thiscall FUN_0055b20d(int param_1,int param_2)
{
  if ((*(int *)(param_1 + 0x1c) != 0) && (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0)) {
    (**(code **)**(undefined4 **)(param_1 + 4))(1);
  }
  *(int *)(param_1 + 4) = param_2;
  if (param_2 != 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffb;
    return;
  }
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  return;
}

// --------------------------------------------------

// Function: FUN_0055b247
// Address: 0055b247
void __thiscall FUN_0055b247(int param_1,int param_2)
{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 0x24);
  *(int *)(param_1 + 0x28) = (int)*(char *)(param_2 + 0x28);
  *(undefined1 *)(param_1 + 0x2c) = *(undefined1 *)(param_2 + 0x2c);
  *(int *)(param_1 + 0x30) = (int)*(char *)(param_2 + 0x30);
  uVar1 = *(uint *)(param_2 + 8);
  *(uint *)(param_1 + 8) = uVar1;
  if (*(int *)(param_1 + 4) == 0) {
    *(uint *)(param_1 + 8) = uVar1 | 4;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0055b28c
// Address: 0055b28c
int FUN_0055b28c(void)
{
  long *plVar1;
  int iVar2;
  int iVar3;
  
  plVar1 = (long *)operator_new(ios::x_curindex * 4 + 8);
  if (plVar1 == (long *)0x0) {
    return -1;
  }
  iVar2 = 0;
  if (-1 < ios::x_curindex) {
    do {
      iVar3 = iVar2 + 1;
      plVar1[iVar2] = ios::x_statebuf[iVar2];
      iVar2 = iVar3;
    } while (iVar3 <= ios::x_curindex);
  }
  ios::x_curindex = ios::x_curindex + 1;
  plVar1[ios::x_curindex] = 0;
  if (ios::x_statebuf != (long *)0x0) {
    operator_delete(ios::x_statebuf);
  }
  ios::x_statebuf = plVar1;
  return ios::x_curindex;
}

// --------------------------------------------------

// Function: FUN_0055b303
// Address: 0055b303
void FUN_0055b303(void)
{
  ios::x_maxbit = ios::x_maxbit << 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0055b31d
// Address: 0055b31d
uint __fastcall FUN_0055b31d(int *param_1)
{
  uint uVar1;
  byte *pbVar2;
  
  if (param_1[2] != 0) {
    if (param_1[3] == -1) {
      (**(code **)(*param_1 + 0x20))();
    }
    uVar1 = (**(code **)(*param_1 + 0x20))();
    param_1[3] = uVar1;
    return uVar1;
  }
  if ((param_1[0xb] == 0) || ((uint)param_1[0xb] <= (uint)param_1[10])) {
    (**(code **)(*param_1 + 0x20))();
  }
  pbVar2 = (byte *)(param_1[10] + 1);
  param_1[10] = (int)pbVar2;
  if (pbVar2 < (byte *)param_1[0xb]) {
    return (uint)*pbVar2;
  }
  uVar1 = (**(code **)(*param_1 + 0x20))();
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0055b375
// Address: 0055b375
uint __fastcall FUN_0055b375(int *param_1)
{
  byte bVar1;
  uint uVar2;
  
  if (param_1[2] == 0) {
    if ((byte *)param_1[10] < (byte *)param_1[0xb]) {
      bVar1 = *(byte *)param_1[10];
      param_1[10] = param_1[10] + 1;
      return (uint)bVar1;
    }
    uVar2 = (**(code **)(*param_1 + 0x20))();
    param_1[10] = param_1[10] + 1;
    return uVar2;
  }
  uVar2 = param_1[3];
  if (uVar2 == 0xffffffff) {
    uVar2 = (**(code **)(*param_1 + 0x20))();
    return uVar2;
  }
  param_1[3] = -1;
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_0055b3cb
// Address: 0055b3cb
void __fastcall FUN_0055b3cb(int *param_1)
{
  if (param_1[2] == 0) {
    if ((uint)param_1[0xb] <= (uint)param_1[10]) {
      (**(code **)(*param_1 + 0x20))();
    }
    if ((uint)param_1[10] < (uint)param_1[0xb]) {
      param_1[10] = param_1[10] + 1;
    }
    return;
  }
  if (param_1[3] == -1) {
    (**(code **)(*param_1 + 0x20))();
    return;
  }
  param_1[3] = -1;
  return;
}

// --------------------------------------------------

// Function: FUN_0055b413
// Address: 0055b413
int __fastcall FUN_0055b413(int *param_1)
{
  int iVar1;
  
  if (param_1[2] != 0) {
    if (param_1[3] == -1) {
      iVar1 = (**(code **)(*param_1 + 0x20))();
      param_1[3] = iVar1;
    }
    return param_1[3];
  }
  iVar1 = (**(code **)(*param_1 + 0x20))();
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0055b446
// Address: 0055b446
int * __thiscall FUN_0055b446(int *param_1,int param_2)
{
  if (param_2 != 0) {
    *param_1 = (int)&istream::_vbtable_;
    ios::ios((ios *)(param_1 + 3));
  }
  *(undefined ***)(*(int *)(*param_1 + 4) + (int)param_1) = &istream::_vftable_;
  *(uint *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) =
       *(uint *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) | 1;
  param_1[2] = 0;
  param_1[1] = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055b4a5
// Address: 0055b4a5
undefined1 * __thiscall FUN_0055b4a5(istream *param_1,byte param_2)
{
  istream::~istream(param_1);
  ios::~ios((ios *)param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(&param_1[-1].field_0x34);
  }
  return &param_1[-1].field_0x34;
}

// --------------------------------------------------

// Function: FUN_0055b4dd
// Address: 0055b4dd
int * __thiscall FUN_0055b4dd(int *param_1,streambuf *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561faa;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 != 0) {
    *param_1 = (int)&istream::_vbtable_;
    ios::ios((ios *)(param_1 + 3));
    uStack_4 = 0;
  }
  *(undefined ***)(*(int *)(*param_1 + 4) + (int)param_1) = &istream::_vftable_;
  ios::init((ios *)(*(int *)(*param_1 + 4) + (int)param_1),param_2);
  *(uint *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) =
       *(uint *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) | 1;
  param_1[2] = 0;
  param_1[1] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055b572
// Address: 0055b572
int * __thiscall FUN_0055b572(int *param_1,int *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561fda;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 != 0) {
    *param_1 = (int)&istream::_vbtable_;
    ios::ios((ios *)(param_1 + 3));
    uStack_4 = 0;
  }
  *(undefined ***)(*(int *)(*param_1 + 4) + (int)param_1) = &istream::_vftable_;
  ios::init((ios *)(*(int *)(*param_1 + 4) + (int)param_1),
            *(streambuf **)(*(int *)(*param_2 + 4) + 4 + (int)param_2));
  *(uint *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) =
       *(uint *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) | 1;
  param_1[2] = 0;
  param_1[1] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055b61b
// Address: 0055b61b
void __fastcall FUN_0055b61b(int param_1)
{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0xc) + 4) + -0xc + param_1) = &istream::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_0055b62f
// Address: 0055b62f
int * __thiscall FUN_0055b62f(int *param_1,streambuf *param_2)
{
  undefined4 *puVar1;
  ios *piVar2;
  undefined4 *unaff_FS_OFFSET;
  ios iStack_40;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561ff8;
  *unaff_FS_OFFSET = &uStack_c;
  if ((*(int *)(*(int *)(*param_1 + 4) + 0x1c + (int)param_1) != 0) &&
     (puVar1 = *(undefined4 **)((int)param_1 + *(int *)(*param_1 + 4) + 4),
     puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 *)(*(int *)(*param_1 + 4) + 4 + (int)param_1) = 0;
  piVar2 = (ios *)ios::ios(&iStack_40);
  uStack_4 = 0;
  ios::operator=((ios *)(*(int *)(*param_1 + 4) + (int)param_1),piVar2);
  uStack_4 = 0xffffffff;
  ios::~ios(&iStack_40);
  *(undefined4 *)(*(int *)(*param_1 + 4) + 0x1c + (int)param_1) = 0;
  ios::init((ios *)(*(int *)(*param_1 + 4) + (int)param_1),param_2);
  *(uint *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) =
       *(uint *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) | 1;
  param_1[2] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055b6e3
// Address: 0055b6e3
undefined4 __thiscall FUN_0055b6e3(istream *param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_2 != 0) {
    param_1->x_gcount = 0;
  }
  iVar1 = *(int *)(*(int *)param_1 + 4);
  uVar2 = *(uint *)((int)&param_1->x_gcount + iVar1);
  if (uVar2 != 0) {
    *(uint *)((int)&param_1->x_gcount + iVar1) = uVar2 | 2;
    return 0;
  }
  if (*(ostream **)(&param_1->field_0x20 + iVar1) != (ostream *)0x0) {
    if (param_2 != 0) {
      iVar4 = *(int *)((int)&param_1->_fGline + iVar1);
      uVar2 = *(uint *)(iVar4 + 0x2c);
      uVar3 = *(uint *)(iVar4 + 0x28);
      if (uVar3 < uVar2) {
        iVar4 = uVar2 - uVar3;
      }
      else {
        iVar4 = 0;
      }
      if (param_2 <= iVar4) goto LAB_0055b747;
    }
    ostream::flush(*(ostream **)(&param_1->field_0x20 + iVar1));
  }
LAB_0055b747:
  if ((param_2 == 0) && (((&param_1->field_0x24)[*(int *)(*(int *)param_1 + 4)] & 1) != 0)) {
    istream::eatwhite(param_1);
    uVar2 = *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4));
    if (uVar2 != 0) {
      *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) = uVar2 | 2;
      return 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0055b784
// Address: 0055b784
istream * __thiscall FUN_0055b784(istream *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = istream::ipfx(param_1,0);
  if (iVar1 != 0) {
    iVar1 = *(int *)(&param_1->field_0x30 + *(int *)(*(int *)param_1 + 4));
    *(undefined4 *)(&param_1->field_0x30 + *(int *)(*(int *)param_1 + 4)) = 0;
    if (param_2 == 0) {
      *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) =
           *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) | 2;
      return param_1;
    }
    uVar4 = 0;
    if (iVar1 != 1) {
      do {
        iVar2 = streambuf::sgetc(*(streambuf **)
                                  ((int)&param_1->_fGline + *(int *)(*(int *)param_1 + 4)));
        if (iVar2 == -1) {
          *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) =
               *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) | 1;
          if (uVar4 != 0) goto LAB_0055b867;
          *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) =
               *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) | 6;
          break;
        }
        iVar3 = isspace(iVar2);
        if (iVar3 != 0) break;
        *(char *)(uVar4 + param_2) = (char)iVar2;
        streambuf::stossc(*(streambuf **)((int)&param_1->_fGline + *(int *)(*(int *)param_1 + 4)));
        uVar4 = uVar4 + 1;
      } while (uVar4 < iVar1 - 1U);
    }
    if (uVar4 == 0) {
      *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) =
           *(uint *)((int)&param_1->x_gcount + *(int *)(*(int *)param_1 + 4)) | 2;
      return param_1;
    }
LAB_0055b867:
    *(undefined1 *)(uVar4 + param_2) = 0;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055b878
// Address: 0055b878
int __fastcall FUN_0055b878(istream *param_1)
{
  int iVar1;
  
  iVar1 = istream::ipfx(param_1,1);
  if (iVar1 != 0) {
    iVar1 = streambuf::sgetc(*(streambuf **)((int)&param_1->_fGline + *(int *)(*(int *)param_1 + 4))
                            );
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0055b8a3
// Address: 0055b8a3
int * __thiscall FUN_0055b8a3(int *param_1,char param_2)
{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  
  if (*(int *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) == 0) {
    piVar1 = *(int **)((int)param_1 + *(int *)(*param_1 + 4) + 4);
    if ((uint)piVar1[9] < (uint)piVar1[10]) {
      pcVar2 = (char *)(piVar1[10] - 1);
      piVar1[10] = (int)pcVar2;
      *pcVar2 = param_2;
      iVar3 = (int)param_2;
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0x24))((int)param_2);
    }
    if (iVar3 == -1) {
      *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) =
           *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 2;
    }
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055b906
// Address: 0055b906
void __fastcall FUN_0055b906(int *param_1)
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 4))();
  if (iVar1 == -1) {
    *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) =
         *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 6;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0055b93a
// Address: 0055b93a
void __fastcall FUN_0055b93a(int *param_1)
{
  int iVar1;
  
  iVar1 = streambuf::sgetc(*(streambuf **)(*(int *)(*param_1 + 4) + 4 + (int)param_1));
  while( true ) {
    if (iVar1 == -1) {
      *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) =
           *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 1;
      return;
    }
    iVar1 = isspace(iVar1);
    if (iVar1 == 0) break;
    iVar1 = streambuf::snextc(*(streambuf **)(*(int *)(*param_1 + 4) + 4 + (int)param_1));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0055b98a
// Address: 0055b98a
istream * __thiscall FUN_0055b98a(istream *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00562026;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 != 0) {
    *(undefined1 **)param_1 = &istream_withassign::_vbtable_;
    ios::ios((ios *)&param_1->field_0xc);
    uStack_4 = 0;
  }
  istream::istream(param_1);
  *(undefined ***)(&param_1->field_0x0 + *(int *)(*(int *)param_1 + 4)) =
       &istream_withassign::_vftable_;
  *unaff_FS_OFFSET = param_1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055ba06
// Address: 0055ba06
int * __thiscall FUN_0055ba06(ios *param_1,byte param_2)
{
  istream_withassign::~istream_withassign((istream_withassign *)param_1);
  ios::~ios(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(&param_1[-1].x_precision);
  }
  return &param_1[-1].x_precision;
}

// --------------------------------------------------

// Function: FUN_0055ba3d
// Address: 0055ba3d
istream * __thiscall FUN_0055ba3d(istream *param_1,streambuf *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00562046;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 != 0) {
    *(undefined1 **)param_1 = &istream_withassign::_vbtable_;
    ios::ios((ios *)&param_1->field_0xc);
    uStack_4 = 0;
  }
  istream::istream(param_1,param_2);
  *(undefined ***)(&param_1->field_0x0 + *(int *)(*(int *)param_1 + 4)) =
       &istream_withassign::_vftable_;
  *unaff_FS_OFFSET = param_1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055babb
// Address: 0055babb
void __fastcall FUN_0055babb(istream *param_1)
{
  *(undefined ***)(*(int *)(*(int *)&param_1[-1].field_0x34 + 4) + -0xc + (int)param_1) =
       &istream_withassign::_vftable_;
  istream::~istream(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0055bad3
// Address: 0055bad3
void FUN_0055bad3(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WSAStartup();
  return;
}

// --------------------------------------------------

// Function: _WSAStartup@8
// Address: 0055bae0
void _WSAStartup_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WSAStartup();
  return;
}

// --------------------------------------------------

// Function: _WSACleanup@0
// Address: 0055bae6
void _WSACleanup_0(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bae6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WSACleanup();
  return;
}

// --------------------------------------------------

// Function: gethostname
// Address: 0055baec
/* __stdcall gethostname,8 */

void gethostname(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055baec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  gethostname();
  return;
}

// --------------------------------------------------

// Function: gethostbyname
// Address: 0055baf2
/* __stdcall gethostbyname,4 */

void gethostbyname(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055baf2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  gethostbyname();
  return;
}

// --------------------------------------------------

// Function: _RtlUnwind@16
// Address: 0055baf8
void _RtlUnwind_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055baf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind();
  return;
}

// --------------------------------------------------

// Function: _HeapAlloc@12
// Address: 0055bafe
void _HeapAlloc_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bafe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapAlloc();
  return;
}

// --------------------------------------------------

// Function: _HeapFree@12
// Address: 0055bb04
void _HeapFree_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapFree();
  return;
}

// --------------------------------------------------

// Function: _DeleteFileA@4
// Address: 0055bb0a
void _DeleteFileA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteFileA();
  return;
}

// --------------------------------------------------

// Function: _GetTimeZoneInformation@4
// Address: 0055bb10
void _GetTimeZoneInformation_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetTimeZoneInformation();
  return;
}

// --------------------------------------------------

// Function: _GetSystemTime@4
// Address: 0055bb16
void _GetSystemTime_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetSystemTime();
  return;
}

// --------------------------------------------------

// Function: _GetLocalTime@4
// Address: 0055bb1c
void _GetLocalTime_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetLocalTime();
  return;
}

// --------------------------------------------------

// Function: _FindNextFileA@8
// Address: 0055bb22
void _FindNextFileA_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FindNextFileA();
  return;
}

// --------------------------------------------------

// Function: _FileTimeToLocalFileTime@8
// Address: 0055bb28
void _FileTimeToLocalFileTime_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FileTimeToLocalFileTime();
  return;
}

// --------------------------------------------------

// Function: _ReadFile@20
// Address: 0055bb2e
void _ReadFile_20(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReadFile();
  return;
}

// --------------------------------------------------

// Function: _GetFileType@4
// Address: 0055bb34
void _GetFileType_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetFileType();
  return;
}

// --------------------------------------------------

// Function: _SetFilePointer@16
// Address: 0055bb3a
void _SetFilePointer_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetFilePointer();
  return;
}

// --------------------------------------------------

// Function: _WriteFile@20
// Address: 0055bb40
void _WriteFile_20(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WriteFile();
  return;
}

// --------------------------------------------------

// Function: _SetCurrentDirectoryA@4
// Address: 0055bb46
void _SetCurrentDirectoryA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetCurrentDirectoryA();
  return;
}

// --------------------------------------------------

// Function: _SetEnvironmentVariableA@8
// Address: 0055bb4c
void _SetEnvironmentVariableA_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetEnvironmentVariableA();
  return;
}

// --------------------------------------------------

// Function: _GetFullPathNameA@16
// Address: 0055bb52
void _GetFullPathNameA_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetFullPathNameA();
  return;
}

// --------------------------------------------------

// Function: _ExitProcess@4
// Address: 0055bb58
void _ExitProcess_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ExitProcess();
  return;
}

// --------------------------------------------------

// Function: _TerminateProcess@8
// Address: 0055bb5e
void _TerminateProcess_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess();
  return;
}

// --------------------------------------------------

// Function: _GetCurrentProcess@0
// Address: 0055bb64
void _GetCurrentProcess_0(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetCurrentProcess();
  return;
}

// --------------------------------------------------

// Function: _GetStartupInfoA@4
// Address: 0055bb6a
void _GetStartupInfoA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetStartupInfoA();
  return;
}

// --------------------------------------------------

// Function: _GetCommandLineA@0
// Address: 0055bb70
void _GetCommandLineA_0(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetCommandLineA();
  return;
}

// --------------------------------------------------

// Function: _GetVersion@0
// Address: 0055bb76
void _GetVersion_0(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetVersion();
  return;
}

// --------------------------------------------------

// Function: _HeapDestroy@4
// Address: 0055bb7c
void _HeapDestroy_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapDestroy();
  return;
}

// --------------------------------------------------

// Function: _HeapCreate@12
// Address: 0055bb82
void _HeapCreate_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapCreate();
  return;
}

// --------------------------------------------------

// Function: _VirtualAlloc@16
// Address: 0055bb88
void _VirtualAlloc_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VirtualAlloc();
  return;
}

// --------------------------------------------------

// Function: _FlushFileBuffers@4
// Address: 0055bb8e
void _FlushFileBuffers_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FlushFileBuffers();
  return;
}

// --------------------------------------------------

// Function: _SetHandleCount@4
// Address: 0055bb94
void _SetHandleCount_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetHandleCount();
  return;
}

// --------------------------------------------------

// Function: _GetStdHandle@4
// Address: 0055bb9a
void _GetStdHandle_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bb9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetStdHandle();
  return;
}

// --------------------------------------------------

// Function: _GetCPInfo@8
// Address: 0055bba0
void _GetCPInfo_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetCPInfo();
  return;
}

// --------------------------------------------------

// Function: _GetACP@0
// Address: 0055bba6
void _GetACP_0(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bba6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetACP();
  return;
}

// --------------------------------------------------

// Function: _GetOEMCP@0
// Address: 0055bbac
void _GetOEMCP_0(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetOEMCP();
  return;
}

// --------------------------------------------------

// Function: _WideCharToMultiByte@32
// Address: 0055bbb2
void _WideCharToMultiByte_32(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WideCharToMultiByte();
  return;
}

// --------------------------------------------------

// Function: _GetStringTypeA@20
// Address: 0055bbb8
void _GetStringTypeA_20(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetStringTypeA();
  return;
}

// --------------------------------------------------

// Function: _GetStringTypeW@16
// Address: 0055bbbe
void _GetStringTypeW_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetStringTypeW();
  return;
}

// --------------------------------------------------

// Function: _MultiByteToWideChar@24
// Address: 0055bbc4
void _MultiByteToWideChar_24(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MultiByteToWideChar();
  return;
}

// --------------------------------------------------

// Function: _SetStdHandle@8
// Address: 0055bbca
void _SetStdHandle_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetStdHandle();
  return;
}

// --------------------------------------------------

// Function: _SetEndOfFile@4
// Address: 0055bbd0
void _SetEndOfFile_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetEndOfFile();
  return;
}

// --------------------------------------------------

// Function: _LCMapStringA@24
// Address: 0055bbd6
void _LCMapStringA_24(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LCMapStringA();
  return;
}

// --------------------------------------------------

// Function: _LCMapStringW@24
// Address: 0055bbdc
void _LCMapStringW_24(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LCMapStringW();
  return;
}

// --------------------------------------------------

// Function: _RaiseException@16
// Address: 0055bbe2
void _RaiseException_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbe2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RaiseException();
  return;
}

// --------------------------------------------------

// Function: _HeapReAlloc@16
// Address: 0055bbe8
void _HeapReAlloc_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbe8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapReAlloc();
  return;
}

// --------------------------------------------------

// Function: _HeapSize@12
// Address: 0055bbee
void _HeapSize_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapSize();
  return;
}

// --------------------------------------------------

// Function: _UnhandledExceptionFilter@4
// Address: 0055bbf4
void _UnhandledExceptionFilter_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UnhandledExceptionFilter();
  return;
}

// --------------------------------------------------

// Function: _GetModuleFileNameA@12
// Address: 0055bbfa
void _GetModuleFileNameA_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bbfa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetModuleFileNameA();
  return;
}

// --------------------------------------------------

// Function: _FreeEnvironmentStringsA@4
// Address: 0055bc00
void _FreeEnvironmentStringsA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bc00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FreeEnvironmentStringsA();
  return;
}

// --------------------------------------------------

// Function: _FreeEnvironmentStringsW@4
// Address: 0055bc06
void _FreeEnvironmentStringsW_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bc06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FreeEnvironmentStringsW();
  return;
}

// --------------------------------------------------

// Function: _GetEnvironmentStrings@0
// Address: 0055bc0c
void _GetEnvironmentStrings_0(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bc0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetEnvironmentStrings();
  return;
}

// --------------------------------------------------

// Function: _GetEnvironmentStringsW@0
// Address: 0055bc12
void _GetEnvironmentStringsW_0(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bc12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetEnvironmentStringsW();
  return;
}

// --------------------------------------------------

// Function: _SetUnhandledExceptionFilter@4
// Address: 0055bc18
void _SetUnhandledExceptionFilter_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bc18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetUnhandledExceptionFilter();
  return;
}

// --------------------------------------------------

// Function: _IsBadReadPtr@8
// Address: 0055bc1e
void _IsBadReadPtr_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bc1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IsBadReadPtr();
  return;
}

// --------------------------------------------------

// Function: _IsBadWritePtr@8
// Address: 0055bc24
void _IsBadWritePtr_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bc24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IsBadWritePtr();
  return;
}

// --------------------------------------------------

// Function: _IsBadCodePtr@4
// Address: 0055bc2a
void _IsBadCodePtr_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bc2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IsBadCodePtr();
  return;
}

// --------------------------------------------------

// Function: _SetConsoleCtrlHandler@8
// Address: 0055bc30
void _SetConsoleCtrlHandler_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bc30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetConsoleCtrlHandler();
  return;
}

// --------------------------------------------------

// Function: _CompareStringW@24
// Address: 0055bc36
void _CompareStringW_24(void)
{
                    /* WARNING: Could not recover jumptable at 0x0055bc36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CompareStringW();
  return;
}

// --------------------------------------------------

// Function: strupr
// Address: 0055bc40
/* strupr */

char * __cdecl strupr(char *param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  pcVar5 = (char *)0x0;
  if (DAT_008882c0 == 0) {
    pcVar5 = param_1;
    if (*param_1 != '\0') {
      do {
        cVar1 = *param_1;
        if (('`' < cVar1) && (cVar1 < '{')) {
          *param_1 = cVar1 + -0x20;
        }
        pcVar6 = param_1 + 1;
        param_1 = param_1 + 1;
      } while (*pcVar6 != '\0');
      return pcVar5;
    }
  }
  else {
    iVar2 = ___crtLCMapStringA(DAT_008882c0,0x200,param_1,0xffffffff,0,0,0);
    if (((iVar2 != 0) && (pcVar5 = (char *)malloc(iVar2), pcVar5 != (char *)0x0)) &&
       (iVar2 = ___crtLCMapStringA(DAT_008882c0,0x200,param_1,0xffffffff,pcVar5,iVar2,0), iVar2 != 0
       )) {
      uVar3 = 0xffffffff;
      pcVar6 = pcVar5;
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
      pcVar7 = param_1;
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
    }
    free(pcVar5);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055bcf6
// Address: 0055bcf6
undefined4 FUN_0055bcf6(int param_1,undefined4 param_2,int param_3)
{
  if ((param_3 == 10) && (param_1 < 0)) {
    FUN_0055bd40(param_1,param_2,10,1);
    return param_2;
  }
  FUN_0055bd40(param_1,param_2,param_3,0);
  return param_2;
}

// --------------------------------------------------

// Function: itoa
// Address: 0055bd00
/* itoa */

undefined4 __cdecl itoa(int param_1,undefined4 param_2,int param_3)
{
  if ((param_3 == 10) && (param_1 < 0)) {
    FUN_0055bd40(param_1,param_2,10,1);
    return param_2;
  }
  FUN_0055bd40(param_1,param_2,param_3,0);
  return param_2;
}

// --------------------------------------------------

// Function: FUN_0055bd3d
// Address: 0055bd3d
void FUN_0055bd3d(uint param_1,char *param_2,uint param_3,int param_4)
{
  ulonglong uVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  
  pcVar2 = param_2;
  if (param_4 != 0) {
    *param_2 = '-';
    param_2 = param_2 + 1;
    param_1 = -param_1;
    pcVar2 = param_2;
  }
  do {
    pcVar4 = pcVar2;
    uVar1 = (ulonglong)param_1;
    param_1 = param_1 / param_3;
    cVar3 = (char)(uVar1 % (ulonglong)param_3);
    if ((uint)(uVar1 % (ulonglong)param_3) < 10) {
      cVar3 = cVar3 + '0';
    }
    else {
      cVar3 = cVar3 + 'W';
    }
    *pcVar4 = cVar3;
    pcVar2 = pcVar4 + 1;
  } while (param_1 != 0);
  pcVar4[1] = '\0';
  do {
    cVar3 = *pcVar4;
    *pcVar4 = *param_2;
    *param_2 = cVar3;
    pcVar4 = pcVar4 + -1;
    param_2 = param_2 + 1;
  } while (param_2 < pcVar4);
  return;
}

// --------------------------------------------------

// Function: FUN_0055bd40
// Address: 0055bd40
void FUN_0055bd40(uint param_1,char *param_2,uint param_3,int param_4)
{
  ulonglong uVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  
  pcVar2 = param_2;
  if (param_4 != 0) {
    *param_2 = '-';
    param_2 = param_2 + 1;
    param_1 = -param_1;
    pcVar2 = param_2;
  }
  do {
    pcVar4 = pcVar2;
    uVar1 = (ulonglong)param_1;
    param_1 = param_1 / param_3;
    cVar3 = (char)(uVar1 % (ulonglong)param_3);
    if ((uint)(uVar1 % (ulonglong)param_3) < 10) {
      cVar3 = cVar3 + '0';
    }
    else {
      cVar3 = cVar3 + 'W';
    }
    *pcVar4 = cVar3;
    pcVar2 = pcVar4 + 1;
  } while (param_1 != 0);
  pcVar4[1] = '\0';
  do {
    cVar3 = *pcVar4;
    *pcVar4 = *param_2;
    *param_2 = cVar3;
    pcVar4 = pcVar4 + -1;
    param_2 = param_2 + 1;
  } while (param_2 < pcVar4);
  return;
}

// --------------------------------------------------

// Function: FUN_0055bda1
// Address: 0055bda1
undefined4 FUN_0055bda1(int param_1,undefined4 param_2,int param_3)
{
  if ((param_3 == 10) && (param_1 < 0)) {
    FUN_0055bd40(param_1,param_2,10,1);
    return param_2;
  }
  FUN_0055bd40(param_1,param_2,param_3,0);
  return param_2;
}

// --------------------------------------------------

// Function: FUN_0055bdf1
// Address: 0055bdf1
undefined4 FUN_0055bdf1(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_0055bd40(param_1,param_2,param_3,0);
  return param_2;
}

// --------------------------------------------------

// Function: FUN_0055be1e
// Address: 0055be1e
undefined4 FUN_0055be1e(undefined4 param_1,int param_2,undefined4 param_3,int param_4)
{
  if (((param_4 == 10) && (param_2 < 1)) && (param_2 < 0)) {
    FUN_0055be70(param_1,param_2,param_3,10,1);
    return param_3;
  }
  FUN_0055be70(param_1,param_2,param_3,param_4,0);
  return param_3;
}

// --------------------------------------------------

// Function: FUN_0055be6a
// Address: 0055be6a
void FUN_0055be6a(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,int param_5
                 )
{
  uint uVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  longlong lVar6;
  
  pcVar2 = param_3;
  lVar6 = CONCAT44(param_2,param_1);
  if (param_5 != 0) {
    *param_3 = '-';
    param_3 = param_3 + 1;
    pcVar2 = param_3;
    lVar6 = CONCAT44(param_2,param_1);
  }
  do {
    pcVar4 = pcVar2;
    uVar1 = __aullrem(lVar6,param_4,0);
    lVar6 = __aulldiv(lVar6,param_4,0);
    if (uVar1 < 10) {
      cVar3 = (char)uVar1 + '0';
    }
    else {
      cVar3 = (char)uVar1 + 'W';
    }
    *pcVar4 = cVar3;
    pcVar2 = pcVar4 + 1;
  } while (lVar6 != 0);
  pcVar4[1] = '\0';
  do {
    cVar3 = *pcVar4;
    pcVar5 = pcVar4 + -1;
    pcVar2 = param_3 + 1;
    *pcVar4 = *param_3;
    *param_3 = cVar3;
    pcVar4 = pcVar5;
    param_3 = pcVar2;
  } while (pcVar2 < pcVar5);
  return;
}

// --------------------------------------------------

// Function: FUN_0055be70
// Address: 0055be70
void FUN_0055be70(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,int param_5
                 )
{
  uint uVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  longlong lVar6;
  
  pcVar2 = param_3;
  lVar6 = CONCAT44(param_2,param_1);
  if (param_5 != 0) {
    *param_3 = '-';
    param_3 = param_3 + 1;
    pcVar2 = param_3;
    lVar6 = CONCAT44(param_2,param_1);
  }
  do {
    pcVar4 = pcVar2;
    uVar1 = __aullrem(lVar6,param_4,0);
    lVar6 = __aulldiv(lVar6,param_4,0);
    if (uVar1 < 10) {
      cVar3 = (char)uVar1 + '0';
    }
    else {
      cVar3 = (char)uVar1 + 'W';
    }
    *pcVar4 = cVar3;
    pcVar2 = pcVar4 + 1;
  } while (lVar6 != 0);
  pcVar4[1] = '\0';
  do {
    cVar3 = *pcVar4;
    pcVar5 = pcVar4 + -1;
    pcVar2 = param_3 + 1;
    *pcVar4 = *param_3;
    *param_3 = cVar3;
    pcVar4 = pcVar5;
    param_3 = pcVar2;
  } while (pcVar2 < pcVar5);
  return;
}

// --------------------------------------------------

// Function: FUN_0055bef1
// Address: 0055bef1
undefined4 FUN_0055bef1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  FUN_0055be70(param_1,param_2,param_3,param_4,0);
  return param_3;
}

// --------------------------------------------------

// Function: FUN_0055bf37
// Address: 0055bf37
type_info * __thiscall FUN_0055bf37(type_info *param_1,byte param_2)
{
  type_info::~type_info(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055bf5e
// Address: 0055bf5e
bool __thiscall FUN_0055bf5e(int param_1,int param_2)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)(param_1 + 9);
  pbVar2 = (byte *)(param_2 + 9);
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return true;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return true;
    }
  }
  return 1 - bVar4 == (uint)(bVar4 != 0);
}

// --------------------------------------------------

// Function: FUN_0055bfb3
// Address: 0055bfb3
bool __thiscall FUN_0055bfb3(int param_1,int param_2)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)(param_1 + 9);
  pbVar2 = (byte *)(param_2 + 9);
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  return 1 - bVar4 != (uint)(bVar4 != 0);
}

// --------------------------------------------------

// Function: FUN_0055c013
// Address: 0055c013
bool __thiscall FUN_0055c013(int param_1,int param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  pbVar5 = (byte *)(param_1 + 9);
  pbVar4 = (byte *)(param_2 + 9);
  while( true ) {
    bVar1 = *pbVar4;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = pbVar4[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) break;
    pbVar4 = pbVar4 + 2;
    pbVar5 = pbVar5 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  uVar2 = (uint)(bVar6 != 0);
  uVar3 = 1 - bVar6;
  return uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2);
}

// --------------------------------------------------

// Function: FUN_0055c073
// Address: 0055c073
int __fastcall FUN_0055c073(int param_1)
{
  return param_1 + 8;
}

// --------------------------------------------------

// Function: FUN_0055c084
// Address: 0055c084
void __fastcall FUN_0055c084(undefined4 *param_1)
{
  *param_1 = &type_info::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_0055c09b
// Address: 0055c09b
undefined4 __fastcall FUN_0055c09b(undefined4 param_1)
{
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0055c0a5
// Address: 0055c0a5
void FUN_0055c0a5(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L35541} */
  RGE_Action::~RGE_Action(*(RGE_Action **)(unaff_EBP + -0x10));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c0b8
// Address: 0055c0b8
void FUN_0055c0b8(void)
{
                    /* Symbol Ref: {@symbol $L35546} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c0d8
// Address: 0055c0d8
void FUN_0055c0d8(void)
{
                    /* Symbol Ref: {@symbol $L35565} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c106
// Address: 0055c106
void FUN_0055c106(void)
{
                    /* Symbol Ref: {@symbol $L35602} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c110
// Address: 0055c110
void FUN_0055c110(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L34845} */
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c11b
// Address: 0055c11b
void FUN_0055c11b(void)
{
                    /* Symbol Ref: {@symbol $L34851} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c138
// Address: 0055c138
void FUN_0055c138(void)
{
                    /* Symbol Ref: {@symbol $L34529} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c15b
// Address: 0055c15b
void FUN_0055c15b(void)
{
                    /* Symbol Ref: {@symbol $L34551} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c17b
// Address: 0055c17b
void FUN_0055c17b(void)
{
                    /* Symbol Ref: {@symbol $L33615} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c198
// Address: 0055c198
void FUN_0055c198(void)
{
                    /* Symbol Ref: {@symbol $L35503} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c1b8
// Address: 0055c1b8
void FUN_0055c1b8(void)
{
                    /* Symbol Ref: {@symbol $L35525} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c1f1
// Address: 0055c1f1
void FUN_0055c1f1(void)
{
                    /* Symbol Ref: {@symbol $L35560} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c24d
// Address: 0055c24d
void FUN_0055c24d(void)
{
                    /* Symbol Ref: {@symbol $L34153} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c2ad
// Address: 0055c2ad
void FUN_0055c2ad(void)
{
                    /* Symbol Ref: {@symbol $L34207} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c2c8
// Address: 0055c2c8
void FUN_0055c2c8(void)
{
                    /* Symbol Ref: {@symbol $L34841} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c2e8
// Address: 0055c2e8
void FUN_0055c2e8(void)
{
                    /* Symbol Ref: {@symbol $L34863} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c308
// Address: 0055c308
void FUN_0055c308(void)
{
                    /* Symbol Ref: {@symbol $L34509} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c328
// Address: 0055c328
void FUN_0055c328(void)
{
                    /* Symbol Ref: {@symbol $L34533} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c348
// Address: 0055c348
void FUN_0055c348(void)
{
                    /* Symbol Ref: {@symbol $L34543} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c368
// Address: 0055c368
void FUN_0055c368(void)
{
                    /* Symbol Ref: {@symbol $L35401} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c388
// Address: 0055c388
void FUN_0055c388(void)
{
                    /* Symbol Ref: {@symbol $L35497} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c3a8
// Address: 0055c3a8
void FUN_0055c3a8(void)
{
                    /* Symbol Ref: {@symbol $L35513} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c3cb
// Address: 0055c3cb
void FUN_0055c3cb(void)
{
                    /* Symbol Ref: {@symbol $L35536} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c3f6
// Address: 0055c3f6
void FUN_0055c3f6(void)
{
                    /* Symbol Ref: {@symbol $L35566} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c400
// Address: 0055c400
void FUN_0055c400(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L35738} */
  operator_delete(*(void **)(unaff_EBP + 4));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c40b
// Address: 0055c40b
void FUN_0055c40b(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L35739} */
  operator_delete(*(void **)(unaff_EBP + 4));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c416
// Address: 0055c416
void FUN_0055c416(void)
{
                    /* Symbol Ref: {@symbol $L35744} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c420
// Address: 0055c420
void FUN_0055c420(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L34795} */
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c42b
// Address: 0055c42b
void FUN_0055c42b(void)
{
                    /* Symbol Ref: {@symbol $L34800} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c456
// Address: 0055c456
void FUN_0055c456(void)
{
                    /* Symbol Ref: {@symbol $L31906} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

