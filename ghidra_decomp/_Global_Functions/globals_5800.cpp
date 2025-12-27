// GLOBAL FUNCTIONS PART 5800
// Function: FUN_0054b99e
// Address: 0054b99e
uint * FUN_0054b99e(uint *param_1,char *param_2)
{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  char cVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  uint *puVar10;
  
  cVar3 = *param_2;
  if (cVar3 == '\0') {
    return param_1;
  }
  if (param_2[1] == '\0') {
    uVar4 = (uint)param_1 & 3;
    while (uVar4 != 0) {
      if ((char)*param_1 == cVar3) {
        return param_1;
      }
      if ((char)*param_1 == '\0') {
        return (uint *)0x0;
      }
      uVar4 = (uint)((int)param_1 + 1) & 3;
      param_1 = (uint *)((int)param_1 + 1);
    }
    while( true ) {
      while( true ) {
        uVar4 = *param_1;
        uVar9 = uVar4 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));
        uVar7 = uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff;
        puVar10 = param_1 + 1;
        if (((uVar9 ^ 0xffffffff ^ uVar9 + 0x7efefeff) & 0x81010100) != 0) break;
        param_1 = puVar10;
        if ((uVar7 & 0x81010100) != 0) {
          if ((uVar7 & 0x1010100) != 0) {
            return (uint *)0x0;
          }
          if ((uVar4 + 0x7efefeff & 0x80000000) == 0) {
            return (uint *)0x0;
          }
        }
      }
      uVar4 = *param_1;
      if ((char)uVar4 == cVar3) {
        return param_1;
      }
      if ((char)uVar4 == '\0') {
        return (uint *)0x0;
      }
      cVar6 = (char)(uVar4 >> 8);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 1);
      }
      if (cVar6 == '\0') break;
      cVar6 = (char)(uVar4 >> 0x10);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 2);
      }
      if (cVar6 == '\0') {
        return (uint *)0x0;
      }
      cVar6 = (char)(uVar4 >> 0x18);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 3);
      }
      param_1 = puVar10;
      if (cVar6 == '\0') {
        return (uint *)0x0;
      }
    }
    return (uint *)0x0;
  }
  do {
    cVar6 = (char)*param_1;
    do {
      while (puVar10 = param_1, param_1 = (uint *)((int)puVar10 + 1), cVar6 != cVar3) {
        if (cVar6 == '\0') {
          return (uint *)0x0;
        }
        cVar6 = *(char *)param_1;
      }
      cVar6 = *(char *)param_1;
      pcVar8 = param_2;
      puVar5 = puVar10;
    } while (cVar6 != param_2[1]);
    do {
      if (pcVar8[2] == '\0') {
        return puVar10;
      }
      if (*(char *)((int)puVar5 + 2) != pcVar8[2]) break;
      pcVar1 = pcVar8 + 3;
      if (*pcVar1 == '\0') {
        return puVar10;
      }
      pcVar2 = (char *)((int)puVar5 + 3);
      pcVar8 = pcVar8 + 2;
      puVar5 = (uint *)((int)puVar5 + 2);
    } while (*pcVar1 == *pcVar2);
  } while( true );
}

// --------------------------------------------------

// Function: strstr
// Address: 0054b9a0
/* strstr */

uint * __cdecl strstr(uint *param_1,char *param_2)
{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  char cVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  uint *puVar10;
  
  cVar3 = *param_2;
  if (cVar3 == '\0') {
    return param_1;
  }
  if (param_2[1] == '\0') {
    uVar4 = (uint)param_1 & 3;
    while (uVar4 != 0) {
      if ((char)*param_1 == cVar3) {
        return param_1;
      }
      if ((char)*param_1 == '\0') {
        return (uint *)0x0;
      }
      uVar4 = (uint)((int)param_1 + 1) & 3;
      param_1 = (uint *)((int)param_1 + 1);
    }
    while( true ) {
      while( true ) {
        uVar4 = *param_1;
        uVar9 = uVar4 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));
        uVar7 = uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff;
        puVar10 = param_1 + 1;
        if (((uVar9 ^ 0xffffffff ^ uVar9 + 0x7efefeff) & 0x81010100) != 0) break;
        param_1 = puVar10;
        if ((uVar7 & 0x81010100) != 0) {
          if ((uVar7 & 0x1010100) != 0) {
            return (uint *)0x0;
          }
          if ((uVar4 + 0x7efefeff & 0x80000000) == 0) {
            return (uint *)0x0;
          }
        }
      }
      uVar4 = *param_1;
      if ((char)uVar4 == cVar3) {
        return param_1;
      }
      if ((char)uVar4 == '\0') {
        return (uint *)0x0;
      }
      cVar6 = (char)(uVar4 >> 8);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 1);
      }
      if (cVar6 == '\0') break;
      cVar6 = (char)(uVar4 >> 0x10);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 2);
      }
      if (cVar6 == '\0') {
        return (uint *)0x0;
      }
      cVar6 = (char)(uVar4 >> 0x18);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 3);
      }
      param_1 = puVar10;
      if (cVar6 == '\0') {
        return (uint *)0x0;
      }
    }
    return (uint *)0x0;
  }
  do {
    cVar6 = (char)*param_1;
    do {
      while (puVar10 = param_1, param_1 = (uint *)((int)puVar10 + 1), cVar6 != cVar3) {
        if (cVar6 == '\0') {
          return (uint *)0x0;
        }
        cVar6 = *(char *)param_1;
      }
      cVar6 = *(char *)param_1;
      pcVar8 = param_2;
      puVar5 = puVar10;
    } while (cVar6 != param_2[1]);
    do {
      if (pcVar8[2] == '\0') {
        return puVar10;
      }
      if (*(char *)((int)puVar5 + 2) != pcVar8[2]) break;
      pcVar1 = pcVar8 + 3;
      if (*pcVar1 == '\0') {
        return puVar10;
      }
      pcVar2 = (char *)((int)puVar5 + 3);
      pcVar8 = pcVar8 + 2;
      puVar5 = (uint *)((int)puVar5 + 2);
    } while (*pcVar1 == *pcVar2);
  } while( true );
}

// --------------------------------------------------

// Function: fclose
// Address: 0054ba20
/* fclose */

undefined4 __cdecl fclose(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((*(uint *)(param_1 + 0xc) & 0x40) != 0) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0xc) & 0x83) != 0) {
    uVar2 = __flush(param_1);
    __freebuf(param_1);
    iVar1 = close(*(undefined4 *)(param_1 + 0x10));
    if (iVar1 < 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      free(*(int *)(param_1 + 0x1c));
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_0054ba97
// Address: 0054ba97
void FUN_0054ba97(char *param_1,undefined4 param_2)
{
  char cVar1;
  uint uVar2;
  char *pcStack_20;
  int iStack_1c;
  char *pcStack_18;
  undefined4 uStack_14;
  
  uVar2 = 0xffffffff;
  pcStack_18 = param_1;
  pcStack_20 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  iStack_1c = ~uVar2 - 1;
  uStack_14 = 0x49;
  __input(&pcStack_20,param_2,&stack0x0000000c);
  return;
}

// --------------------------------------------------

// Function: sscanf
// Address: 0054baa0
/* sscanf */

void __cdecl sscanf(char *param_1,undefined4 param_2)
{
  char cVar1;
  uint uVar2;
  char *local_20;
  int local_1c;
  char *local_18;
  undefined4 local_14;
  
  uVar2 = 0xffffffff;
  local_18 = param_1;
  local_20 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  local_1c = ~uVar2 - 1;
  local_14 = 0x49;
  __input(&local_20,param_2,&stack0x0000000c);
  return;
}

// --------------------------------------------------

// Function: FUN_0054bae2
// Address: 0054bae2
char * FUN_0054bae2(char *param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_2 < 1) {
    return (char *)0x0;
  }
  param_2 = param_2 + -1;
  pcVar3 = param_1;
  if (param_2 != 0) {
    while( true ) {
      iVar1 = param_3[1];
      param_3[1] = iVar1 + -1;
      if (iVar1 + -1 < 0) {
        uVar2 = __filbuf(param_3);
      }
      else {
        uVar2 = (uint)*(byte *)*param_3;
        *param_3 = (byte *)*param_3 + 1;
      }
      if (uVar2 == 0xffffffff) break;
      *pcVar3 = (char)uVar2;
      pcVar3 = pcVar3 + 1;
      if ((char)uVar2 == '\n') goto LAB_0054bb56;
      param_2 = param_2 + -1;
      if (param_2 == 0) {
        *pcVar3 = '\0';
        return param_1;
      }
    }
    if (pcVar3 == param_1) {
      return (char *)0x0;
    }
  }
LAB_0054bb56:
  *pcVar3 = '\0';
  return param_1;
}

// --------------------------------------------------

// Function: fgets
// Address: 0054baf0
/* fgets */

char * __cdecl fgets(char *param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_2 < 1) {
    return (char *)0x0;
  }
  param_2 = param_2 + -1;
  pcVar3 = param_1;
  if (param_2 != 0) {
    while( true ) {
      iVar1 = param_3[1];
      param_3[1] = iVar1 + -1;
      if (iVar1 + -1 < 0) {
        uVar2 = __filbuf(param_3);
      }
      else {
        uVar2 = (uint)*(byte *)*param_3;
        *param_3 = (byte *)*param_3 + 1;
      }
      if (uVar2 == 0xffffffff) break;
      *pcVar3 = (char)uVar2;
      pcVar3 = pcVar3 + 1;
      if ((char)uVar2 == '\n') goto LAB_0054bb56;
      param_2 = param_2 + -1;
      if (param_2 == 0) {
        *pcVar3 = '\0';
        return param_1;
      }
    }
    if (pcVar3 == param_1) {
      return (char *)0x0;
    }
  }
LAB_0054bb56:
  *pcVar3 = '\0';
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0054bb62
// Address: 0054bb62
void FUN_0054bb62(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  iVar1 = __getstream();
  if (iVar1 == 0) {
    return;
  }
  __openfile(param_1,param_2,param_3,iVar1);
  return;
}

// --------------------------------------------------

// Function: __fsopen
// Address: 0054bb70
void __fsopen(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  iVar1 = __getstream();
  if (iVar1 == 0) {
    return;
  }
  __openfile(param_1,param_2,param_3,iVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_0054bb93
// Address: 0054bb93
void FUN_0054bb93(undefined4 param_1,undefined4 param_2)
{
  __fsopen(param_1,param_2,0x40);
  return;
}

// --------------------------------------------------

// Function: fopen
// Address: 0054bba0
/* fopen */

void __cdecl fopen(undefined4 param_1,undefined4 param_2)
{
  __fsopen(param_1,param_2,0x40);
  return;
}

// --------------------------------------------------

// Function: FUN_0054bbb5
// Address: 0054bbb5
undefined4 FUN_0054bbb5(undefined1 *param_1,undefined4 param_2)
{
  undefined4 uVar1;
  undefined1 *puStack_20;
  int iStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  puStack_18 = param_1;
  puStack_20 = param_1;
  uStack_14 = 0x42;
  iStack_1c = 0x7fffffff;
  uVar1 = __output(&puStack_20,param_2,&stack0x0000000c);
  iStack_1c = iStack_1c + -1;
  if (-1 < iStack_1c) {
    *puStack_20 = 0;
    return uVar1;
  }
  __flsbuf(0,&puStack_20);
  return uVar1;
}

// --------------------------------------------------

// Function: sprintf
// Address: 0054bbc0
/* sprintf */

undefined4 __cdecl sprintf(undefined1 *param_1,undefined4 param_2)
{
  undefined4 uVar1;
  undefined1 *local_20;
  int local_1c;
  undefined1 *local_18;
  undefined4 local_14;
  
  local_18 = param_1;
  local_20 = param_1;
  local_14 = 0x42;
  local_1c = 0x7fffffff;
  uVar1 = __output(&local_20,param_2,&stack0x0000000c);
  local_1c = local_1c + -1;
  if (-1 < local_1c) {
    *local_20 = 0;
    return uVar1;
  }
  __flsbuf(0,&local_20);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0054bc28
// Address: 0054bc28
undefined4 FUN_0054bc28(undefined4 *param_1)
{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  ___fastflag._15_1_ = 0x20;
  ___fastflag._19_1_ = 0x20;
  ___fastflag._16_2_ = *(undefined2 *)(&___mnames + param_1[4] * 3);
  ___fastflag._12_2_ = *(undefined2 *)(&___dnames + param_1[6] * 3);
  ___fastflag._18_1_ = "nFebMarAprMayJunJulAugSepOctNovDec"[param_1[4] * 3];
  ___fastflag._14_1_ = "nMonTueWedThuFriSat"[param_1[6] * 3];
  puVar1 = (undefined1 *)FUN_0054bd20(0x887fc0,param_1[3]);
  *puVar1 = 0x20;
  puVar1 = (undefined1 *)FUN_0054bd20(puVar1 + 1,param_1[2]);
  *puVar1 = 0x3a;
  puVar1 = (undefined1 *)FUN_0054bd20(puVar1 + 1,param_1[1]);
  *puVar1 = 0x3a;
  puVar1 = (undefined1 *)FUN_0054bd20(puVar1 + 1,*param_1);
  *puVar1 = 0x20;
  uVar2 = FUN_0054bd20(puVar1 + 1,(int)param_1[5] / 100 + 0x13);
  puVar1 = (undefined1 *)FUN_0054bd20(uVar2,(int)param_1[5] % 100);
  *puVar1 = 10;
  puVar1[1] = 0;
  return 0x887fb8;
}

// --------------------------------------------------

// Function: asctime
// Address: 0054bc30
/* asctime */

undefined4 __cdecl asctime(undefined4 *param_1)
{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  ___fastflag._15_1_ = 0x20;
  ___fastflag._19_1_ = 0x20;
  ___fastflag._16_2_ = *(undefined2 *)(&___mnames + param_1[4] * 3);
  ___fastflag._12_2_ = *(undefined2 *)(&___dnames + param_1[6] * 3);
  ___fastflag._18_1_ = "nFebMarAprMayJunJulAugSepOctNovDec"[param_1[4] * 3];
  ___fastflag._14_1_ = "nMonTueWedThuFriSat"[param_1[6] * 3];
  puVar1 = (undefined1 *)FUN_0054bd20(0x887fc0,param_1[3]);
  *puVar1 = 0x20;
  puVar1 = (undefined1 *)FUN_0054bd20(puVar1 + 1,param_1[2]);
  *puVar1 = 0x3a;
  puVar1 = (undefined1 *)FUN_0054bd20(puVar1 + 1,param_1[1]);
  *puVar1 = 0x3a;
  puVar1 = (undefined1 *)FUN_0054bd20(puVar1 + 1,*param_1);
  *puVar1 = 0x20;
  uVar2 = FUN_0054bd20(puVar1 + 1,(int)param_1[5] / 100 + 0x13);
  puVar1 = (undefined1 *)FUN_0054bd20(uVar2,(int)param_1[5] % 100);
  *puVar1 = 10;
  puVar1[1] = 0;
  return 0x887fb8;
}

// --------------------------------------------------

// Function: FUN_0054bd11
// Address: 0054bd11
char * FUN_0054bd11(char *param_1,int param_2)
{
  *param_1 = (((char)(param_2 / 10) + (char)(param_2 >> 0x1f)) -
             (char)((longlong)param_2 * 0x66666667 >> 0x3f)) + '0';
  param_1[1] = (char)(param_2 % 10) + '0';
  return param_1 + 2;
}

// --------------------------------------------------

// Function: FUN_0054bd20
// Address: 0054bd20
char * FUN_0054bd20(char *param_1,int param_2)
{
  *param_1 = (((char)(param_2 / 10) + (char)(param_2 >> 0x1f)) -
             (char)((longlong)param_2 * 0x66666667 >> 0x3f)) + '0';
  param_1[1] = (char)(param_2 % 10) + '0';
  return param_1 + 2;
}

// --------------------------------------------------

// Function: FUN_0054bd54
// Address: 0054bd54
int * FUN_0054bd54(int *param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = param_1;
  if (*param_1 < 0) {
    return (int *)0x0;
  }
  ___tzset();
  iVar2 = *piVar1;
  if ((iVar2 < 0x3f481) || (0x7ffc0b7e < iVar2)) {
    piVar1 = (int *)gmtime(piVar1);
    iVar3 = __isindst(piVar1);
    iVar2 = *piVar1;
    if (iVar3 != 0) {
      iVar2 = iVar2 - __dstbias;
    }
    param_1 = (int *)(iVar2 - __timezone);
    iVar2 = (int)param_1 % 0x3c;
    *piVar1 = iVar2;
    if (iVar2 < 0) {
      *piVar1 = iVar2 + 0x3c;
      param_1 = (int *)((int)param_1 + -0x3c);
    }
    param_1 = (int *)((int)param_1 / 0x3c + piVar1[1]);
    iVar2 = (int)param_1 % 0x3c;
    piVar1[1] = iVar2;
    if (iVar2 < 0) {
      piVar1[1] = iVar2 + 0x3c;
      param_1 = (int *)((int)param_1 + -0x3c);
    }
    param_1 = (int *)((int)param_1 / 0x3c + piVar1[2]);
    iVar2 = (int)param_1 % 0x18;
    piVar1[2] = iVar2;
    if (iVar2 < 0) {
      piVar1[2] = iVar2 + 0x18;
      param_1 = (int *)((int)param_1 + -0x18);
    }
    iVar2 = (int)param_1 / 0x18;
    if (0 < iVar2) {
      piVar1[6] = (iVar2 + piVar1[6]) % 7;
      piVar1[3] = piVar1[3] + iVar2;
      piVar1[7] = piVar1[7] + iVar2;
      return piVar1;
    }
    if (iVar2 < 0) {
      piVar1[6] = (iVar2 + 7 + piVar1[6]) % 7;
      iVar3 = piVar1[3] + iVar2;
      piVar1[3] = iVar3;
      if (iVar3 < 1) {
        piVar1[7] = 0x16c;
        piVar1[3] = iVar3 + 0x1f;
        piVar1[4] = 0xb;
        piVar1[5] = piVar1[5] + -1;
        return piVar1;
      }
      piVar1[7] = piVar1[7] + iVar2;
    }
  }
  else {
    param_1 = (int *)(iVar2 - __timezone);
    piVar1 = (int *)gmtime(&param_1);
    if (__daylight != 0) {
      iVar2 = __isindst(piVar1);
      if (iVar2 != 0) {
        param_1 = (int *)((int)param_1 - __dstbias);
        piVar1 = (int *)gmtime(&param_1);
        piVar1[8] = 1;
        return piVar1;
      }
    }
  }
  return piVar1;
}

// --------------------------------------------------

// Function: localtime
// Address: 0054bd60
/* localtime */

int * __cdecl localtime(int *param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = param_1;
  if (*param_1 < 0) {
    return (int *)0x0;
  }
  ___tzset();
  iVar2 = *piVar1;
  if ((iVar2 < 0x3f481) || (0x7ffc0b7e < iVar2)) {
    piVar1 = (int *)gmtime(piVar1);
    iVar3 = __isindst(piVar1);
    iVar2 = *piVar1;
    if (iVar3 != 0) {
      iVar2 = iVar2 - __dstbias;
    }
    param_1 = (int *)(iVar2 - __timezone);
    iVar2 = (int)param_1 % 0x3c;
    *piVar1 = iVar2;
    if (iVar2 < 0) {
      *piVar1 = iVar2 + 0x3c;
      param_1 = (int *)((int)param_1 + -0x3c);
    }
    param_1 = (int *)((int)param_1 / 0x3c + piVar1[1]);
    iVar2 = (int)param_1 % 0x3c;
    piVar1[1] = iVar2;
    if (iVar2 < 0) {
      piVar1[1] = iVar2 + 0x3c;
      param_1 = (int *)((int)param_1 + -0x3c);
    }
    param_1 = (int *)((int)param_1 / 0x3c + piVar1[2]);
    iVar2 = (int)param_1 % 0x18;
    piVar1[2] = iVar2;
    if (iVar2 < 0) {
      piVar1[2] = iVar2 + 0x18;
      param_1 = (int *)((int)param_1 + -0x18);
    }
    iVar2 = (int)param_1 / 0x18;
    if (0 < iVar2) {
      piVar1[6] = (iVar2 + piVar1[6]) % 7;
      piVar1[3] = piVar1[3] + iVar2;
      piVar1[7] = piVar1[7] + iVar2;
      return piVar1;
    }
    if (iVar2 < 0) {
      piVar1[6] = (iVar2 + 7 + piVar1[6]) % 7;
      iVar3 = piVar1[3] + iVar2;
      piVar1[3] = iVar3;
      if (iVar3 < 1) {
        piVar1[7] = 0x16c;
        piVar1[3] = iVar3 + 0x1f;
        piVar1[4] = 0xb;
        piVar1[5] = piVar1[5] + -1;
        return piVar1;
      }
      piVar1[7] = piVar1[7] + iVar2;
    }
  }
  else {
    param_1 = (int *)(iVar2 - __timezone);
    piVar1 = (int *)gmtime(&param_1);
    if (__daylight != 0) {
      iVar2 = __isindst(piVar1);
      if (iVar2 != 0) {
        param_1 = (int *)((int)param_1 - __dstbias);
        piVar1 = (int *)gmtime(&param_1);
        piVar1[8] = 1;
        return piVar1;
      }
    }
  }
  return piVar1;
}

// --------------------------------------------------

// Function: FUN_0054bf46
// Address: 0054bf46
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054bf46(void)
{
  int iVar1;
  undefined4 uVar2;
  short sStack_d4;
  short sStack_d2;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined2 uStack_c4;
  undefined2 uStack_c2;
  undefined2 uStack_be;
  undefined2 uStack_bc;
  undefined2 uStack_ba;
  undefined2 uStack_b8;
  undefined1 auStack_b4 [154];
  short sStack_1a;
  int iStack_c;
  undefined4 *puStack_4;
  
  uStack_d0 = &uStack_bc;
  GetLocalTime();
  GetSystemTime();
  if (uStack_cc._2_2_ == DAT_00887fea) {
    if ((short)uStack_cc == DAT_00887fe8) {
      if (uStack_d0._2_2_ == DAT_00887fe6) {
        sStack_d2 = (short)((uint)&uStack_d0 >> 0x10);
        if (sStack_d2 == DAT_00887fe2) {
          sStack_d4 = (short)&uStack_d0;
          if (sStack_d4 == DAT_00887fe0) goto LAB_0054c01f;
        }
      }
    }
  }
  iVar1 = GetTimeZoneInformation(auStack_b4);
  if (iVar1 == -1) {
    DAT_00887fd8 = 0xffffffff;
  }
  else if (((iVar1 == 2) && (sStack_1a != 0)) && (iStack_c != 0)) {
    DAT_00887fd8 = 1;
  }
  else {
    DAT_00887fd8 = 0;
  }
  _DAT_00887fe4 = uStack_d0;
  _DAT_00887fe8 = uStack_cc;
  DAT_00887fec = uStack_c8;
  _DAT_00887fe0 = &uStack_d0;
LAB_0054c01f:
  uVar2 = ___loctotime_t(uStack_c4,uStack_c2,uStack_be,uStack_bc,uStack_ba,uStack_b8,DAT_00887fd8);
  if (puStack_4 != (undefined4 *)0x0) {
    *puStack_4 = uVar2;
  }
  return;
}

// --------------------------------------------------

// Function: time
// Address: 0054bf50
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* time */

void __cdecl time(void)
{
  int iVar1;
  undefined4 uVar2;
  short sStack_d4;
  short sStack_d2;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined2 uStack_c4;
  undefined2 uStack_c2;
  undefined2 uStack_be;
  undefined2 local_bc;
  undefined2 uStack_ba;
  undefined2 uStack_b8;
  undefined1 auStack_b4 [154];
  short sStack_1a;
  int iStack_c;
  undefined4 *puStack_4;
  
  uStack_d0 = &local_bc;
  GetLocalTime();
  GetSystemTime();
  if (uStack_cc._2_2_ == DAT_00887fea) {
    if ((short)uStack_cc == DAT_00887fe8) {
      if (uStack_d0._2_2_ == DAT_00887fe6) {
        sStack_d2 = (short)((uint)&uStack_d0 >> 0x10);
        if (sStack_d2 == DAT_00887fe2) {
          sStack_d4 = (short)&uStack_d0;
          if (sStack_d4 == DAT_00887fe0) goto LAB_0054c01f;
        }
      }
    }
  }
  iVar1 = GetTimeZoneInformation(auStack_b4);
  if (iVar1 == -1) {
    DAT_00887fd8 = 0xffffffff;
  }
  else if (((iVar1 == 2) && (sStack_1a != 0)) && (iStack_c != 0)) {
    DAT_00887fd8 = 1;
  }
  else {
    DAT_00887fd8 = 0;
  }
  _DAT_00887fe4 = uStack_d0;
  _DAT_00887fe8 = uStack_cc;
  DAT_00887fec = uStack_c8;
  _DAT_00887fe0 = &uStack_d0;
LAB_0054c01f:
  uVar2 = ___loctotime_t(uStack_c4,uStack_c2,uStack_be,local_bc,uStack_ba,uStack_b8,DAT_00887fd8);
  if (puStack_4 != (undefined4 *)0x0) {
    *puStack_4 = uVar2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054c07c
// Address: 0054c07c
int FUN_0054c07c(int param_1)
{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = FUN_0054c150(0);
    return iVar1;
  }
  iVar1 = __flush(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(uint *)(param_1 + 0xc) & 0x4000) != 0) {
    iVar1 = __commit(*(undefined4 *)(param_1 + 0x10));
    return -(uint)(iVar1 != 0);
  }
  return 0;
}

// --------------------------------------------------

// Function: fflush
// Address: 0054c080
/* fflush */

int __cdecl fflush(int param_1)
{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = FUN_0054c150(0);
    return iVar1;
  }
  iVar1 = __flush(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(uint *)(param_1 + 0xc) & 0x4000) != 0) {
    iVar1 = __commit(*(undefined4 *)(param_1 + 0x10));
    return -(uint)(iVar1 != 0);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054c0c4
// Address: 0054c0c4
undefined4 FUN_0054c0c4(int *param_1)
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    iVar4 = *param_1 - param_1[2];
    if (0 < iVar4) {
      iVar2 = write(param_1[4],param_1[2],iVar4);
      uVar1 = param_1[3];
      if (iVar2 == iVar4) {
        if ((uVar1 & 0x80) != 0) {
          param_1[1] = 0;
          param_1[3] = uVar1 & 0xfffffffd;
          *param_1 = param_1[2];
          return 0;
        }
      }
      else {
        uVar3 = 0xffffffff;
        param_1[3] = uVar1 | 0x20;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return uVar3;
}

// --------------------------------------------------

// Function: __flush
// Address: 0054c0d0
undefined4 __flush(int *param_1)
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    iVar4 = *param_1 - param_1[2];
    if (0 < iVar4) {
      iVar2 = write(param_1[4],param_1[2],iVar4);
      uVar1 = param_1[3];
      if (iVar2 == iVar4) {
        if ((uVar1 & 0x80) != 0) {
          param_1[1] = 0;
          param_1[3] = uVar1 & 0xfffffffd;
          *param_1 = param_1[2];
          return 0;
        }
      }
      else {
        uVar3 = 0xffffffff;
        param_1[3] = uVar1 | 0x20;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_0054c13e
// Address: 0054c13e
void FUN_0054c13e(void)
{
  FUN_0054c150(1);
  return;
}

// --------------------------------------------------

// Function: __flushall
// Address: 0054c140
void __flushall(void)
{
  FUN_0054c150(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0054c14b
// Address: 0054c14b
int FUN_0054c14b(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  iVar3 = 0;
  if (0 < __nstream) {
    do {
      iVar1 = *(int *)(___piob + iVar3 * 4);
      if ((iVar1 != 0) && ((*(uint *)(iVar1 + 0xc) & 0x83) != 0)) {
        if (param_1 == 1) {
          iVar1 = fflush(iVar1);
          if (iVar1 != -1) {
            iVar2 = iVar2 + 1;
          }
        }
        else if ((param_1 == 0) && ((*(uint *)(iVar1 + 0xc) & 2) != 0)) {
          iVar1 = fflush(iVar1);
          if (iVar1 == -1) {
            iVar4 = -1;
          }
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < __nstream);
  }
  if (param_1 != 1) {
    iVar2 = iVar4;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0054c150
// Address: 0054c150
int FUN_0054c150(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  iVar3 = 0;
  if (0 < __nstream) {
    do {
      iVar1 = *(int *)(___piob + iVar3 * 4);
      if ((iVar1 != 0) && ((*(uint *)(iVar1 + 0xc) & 0x83) != 0)) {
        if (param_1 == 1) {
          iVar1 = fflush(iVar1);
          if (iVar1 != -1) {
            iVar2 = iVar2 + 1;
          }
        }
        else if ((param_1 == 0) && ((*(uint *)(iVar1 + 0xc) & 2) != 0)) {
          iVar1 = fflush(iVar1);
          if (iVar1 == -1) {
            iVar4 = -1;
          }
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < __nstream);
  }
  if (param_1 != 1) {
    iVar2 = iVar4;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0054c1c2
// Address: 0054c1c2
undefined4 FUN_0054c1c2(undefined1 *param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  undefined1 *puStack_20;
  int iStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  puStack_18 = param_1;
  puStack_20 = param_1;
  uStack_14 = 0x42;
  iStack_1c = 0x7fffffff;
  uVar1 = __output(&puStack_20,param_2,param_3);
  iStack_1c = iStack_1c + -1;
  if (-1 < iStack_1c) {
    *puStack_20 = 0;
    return uVar1;
  }
  __flsbuf(0,&puStack_20);
  return uVar1;
}

// --------------------------------------------------

// Function: vsprintf
// Address: 0054c1d0
/* vsprintf */

undefined4 __cdecl vsprintf(undefined1 *param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  undefined1 *local_20;
  int local_1c;
  undefined1 *local_18;
  undefined4 local_14;
  
  local_18 = param_1;
  local_20 = param_1;
  local_14 = 0x42;
  local_1c = 0x7fffffff;
  uVar1 = __output(&local_20,param_2,param_3);
  local_1c = local_1c + -1;
  if (-1 < local_1c) {
    *local_20 = 0;
    return uVar1;
  }
  __flsbuf(0,&local_20);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0054c238
// Address: 0054c238
void FUN_0054c238(int param_1)
{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  __flush(param_1);
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffcf;
  if (uVar1 == 0xffffffff) {
    puVar2 = &___badioinfo;
  }
  else {
    puVar2 = (undefined *)((&___pioinfo)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 8);
  }
  puVar2[4] = puVar2[4] & 0xfd;
  if ((*(uint *)(param_1 + 0xc) & 0x80) != 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffffc;
  }
  lseek(uVar1,0,0);
  return;
}

// --------------------------------------------------

// Function: rewind
// Address: 0054c240
/* rewind */

void __cdecl rewind(int param_1)
{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  __flush(param_1);
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffcf;
  if (uVar1 == 0xffffffff) {
    puVar2 = &___badioinfo;
  }
  else {
    puVar2 = (undefined *)((&___pioinfo)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 8);
  }
  puVar2[4] = puVar2[4] & 0xfd;
  if ((*(uint *)(param_1 + 0xc) & 0x80) != 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffffc;
  }
  lseek(uVar1,0,0);
  return;
}

// --------------------------------------------------

// Function: __findfirst
// Address: 0054c2a0
int __findfirst(undefined4 param_1)
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  char *pcVar7;
  char *pcVar8;
  uint *puVar9;
  uint *unaff_retaddr;
  undefined1 local_140 [4];
  undefined1 auStack_13c [8];
  undefined1 auStack_134 [12];
  uint uStack_128;
  char acStack_11c [284];
  
  iVar2 = FindFirstFileA(param_1);
  if (iVar2 == -1) {
    uVar3 = GetLastError();
    switch(uVar3) {
    case 2:
    case 3:
    case 0x12:
      _errno = 2;
      return -1;
    default:
      _errno = 0x16;
      return -1;
    case 8:
      _errno = 0xc;
      return -1;
    }
  }
  *unaff_retaddr = -(uint)(&stack0x00000000 != (undefined1 *)0x1c0) & (uint)local_140;
  uVar4 = ___timet_from_ft(&stack0xfffffebc);
  unaff_retaddr[1] = uVar4;
  uVar4 = ___timet_from_ft(auStack_13c);
  unaff_retaddr[2] = uVar4;
  uVar4 = ___timet_from_ft(auStack_134);
  unaff_retaddr[3] = uVar4;
  uVar4 = 0xffffffff;
  pcVar7 = acStack_11c;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  unaff_retaddr[4] = uStack_128;
  puVar6 = (uint *)(pcVar8 + -uVar4);
  puVar9 = unaff_retaddr + 5;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar9 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar9 = puVar9 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)puVar9 = (char)*puVar6;
    puVar6 = (uint *)((int)puVar6 + 1);
    puVar9 = (uint *)((int)puVar9 + 1);
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0054c39e
// Address: 0054c39e
char __fastcall FUN_0054c39e(undefined4 param_1,undefined4 param_2)
{
  char in_AL;
  
  return in_AL + (char)((uint)param_2 >> 8);
}

// --------------------------------------------------

// Function: __findnext
// Address: 0054c3d0
undefined4 __findnext(uint param_1)
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  char *pcVar7;
  char *pcVar8;
  uint *puVar9;
  uint *unaff_retaddr;
  undefined1 *puStack_144;
  undefined1 local_140 [4];
  undefined1 auStack_13c [8];
  undefined1 auStack_134 [12];
  uint uStack_128;
  char acStack_11c [284];
  
  puStack_144 = local_140;
  iVar2 = FindNextFileA();
  if (iVar2 == 0) {
    uVar3 = GetLastError();
    switch(uVar3) {
    case 2:
    case 3:
    case 0x12:
      _errno = 2;
      return 0xffffffff;
    default:
      _errno = 0x16;
      return 0xffffffff;
    case 8:
      _errno = 0xc;
      return 0xffffffff;
    }
  }
  *unaff_retaddr = -(uint)(param_1 != 0x80) & param_1;
  uVar4 = ___timet_from_ft(&puStack_144);
  unaff_retaddr[1] = uVar4;
  uVar4 = ___timet_from_ft(auStack_13c);
  unaff_retaddr[2] = uVar4;
  uVar4 = ___timet_from_ft(auStack_134);
  unaff_retaddr[3] = uVar4;
  uVar4 = 0xffffffff;
  pcVar7 = acStack_11c;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  unaff_retaddr[4] = uStack_128;
  puVar6 = (uint *)(pcVar8 + -uVar4);
  puVar9 = unaff_retaddr + 5;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar9 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar9 = puVar9 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)puVar9 = (char)*puVar6;
    puVar6 = (uint *)((int)puVar6 + 1);
    puVar9 = (uint *)((int)puVar9 + 1);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054c4c6
// Address: 0054c4c6
undefined4 FUN_0054c4c6(void)
{
  char in_AL;
  int iVar1;
  char *unaff_EBX;
  
  *unaff_EBX = *unaff_EBX + in_AL;
  iVar1 = FindClose();
  if (iVar1 == 0) {
    _errno = 0x16;
    return 0xffffffff;
  }
  return 0;
}

// --------------------------------------------------

// Function: ___timet_from_ft
// Address: 0054c510
undefined4 ___timet_from_ft(int *param_1)
{
  int iVar1;
  undefined4 uVar2;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined1 *puStack_1c;
  undefined2 local_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  puStack_1c = (undefined1 *)&local_18;
  if ((*param_1 != 0) || (param_1[1] != 0)) {
    uStack_20 = SUB42(param_1,0);
    uStack_1e = (undefined2)((uint)param_1 >> 0x10);
    iVar1 = FileTimeToLocalFileTime();
    if (iVar1 != 0) {
      iVar1 = FileTimeToSystemTime(&uStack_20,&local_18);
      if (iVar1 != 0) {
        uVar2 = ___loctotime_t(uStack_20,uStack_1e,(uint)puStack_1c >> 0x10,local_18,uStack_16,
                               uStack_14,0xffffffff);
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0054c59c
// Address: 0054c59c
void FUN_0054c59c(undefined4 param_1)
{
  __nh_malloc(param_1,__newmode);
  return;
}

// --------------------------------------------------

// Function: malloc
// Address: 0054c5a0
/* malloc */

void __cdecl malloc(undefined4 param_1)
{
  __nh_malloc(param_1,__newmode);
  return;
}

// --------------------------------------------------

// Function: FUN_0054c5b4
// Address: 0054c5b4
int FUN_0054c5b4(uint param_1,int param_2)
{
  int iVar1;
  
  if (param_1 < 0xffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      if (param_1 < 0xffffffe1) {
        iVar1 = __heap_alloc(param_1);
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 != 0) {
        return iVar1;
      }
      if (param_2 == 0) {
        return 0;
      }
      iVar1 = __callnewh(param_1);
    } while (iVar1 != 0);
  }
  return 0;
}

// --------------------------------------------------

// Function: __nh_malloc
// Address: 0054c5c0
int __nh_malloc(uint param_1,int param_2)
{
  int iVar1;
  
  if (param_1 < 0xffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      if (param_1 < 0xffffffe1) {
        iVar1 = __heap_alloc(param_1);
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 != 0) {
        return iVar1;
      }
      if (param_2 == 0) {
        return 0;
      }
      iVar1 = __callnewh(param_1);
    } while (iVar1 != 0);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054c604
// Address: 0054c604
void FUN_0054c604(int param_1)
{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0xfU & 0xfffffff0;
  if ((uVar2 <= ___sbh_threshold) && (iVar1 = ___sbh_alloc_block(param_1 + 0xfU >> 4), iVar1 != 0))
{
    return;
  }
  HeapAlloc(__crtheap,0,uVar2);
  return;
}

// --------------------------------------------------

// Function: __heap_alloc
// Address: 0054c610
void __heap_alloc(int param_1)
{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0xfU & 0xfffffff0;
  if ((uVar2 <= ___sbh_threshold) && (iVar1 = ___sbh_alloc_block(param_1 + 0xfU >> 4), iVar1 != 0))
{
    return;
  }
  HeapAlloc(__crtheap,0,uVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_0054c648
// Address: 0054c648
int FUN_0054c648(byte *param_1)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  
  while( true ) {
    if (___mb_cur_max < 2) {
      uVar2 = (byte)__pctype[(uint)*param_1 * 2] & 8;
    }
    else {
      uVar2 = __isctype(*param_1,8);
    }
    if (uVar2 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar2 = (uint)*param_1;
  pbVar6 = param_1 + 1;
  if ((uVar2 == 0x2d) || (uVar4 = uVar2, uVar2 == 0x2b)) {
    uVar4 = (uint)*pbVar6;
    pbVar6 = param_1 + 2;
  }
  iVar5 = 0;
  while( true ) {
    if (___mb_cur_max < 2) {
      uVar3 = (byte)__pctype[uVar4 * 2] & 4;
    }
    else {
      uVar3 = __isctype(uVar4,4);
    }
    if (uVar3 == 0) break;
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    iVar5 = (uVar4 - 0x30) + iVar5 * 10;
    uVar4 = (uint)bVar1;
  }
  if (uVar2 == 0x2d) {
    iVar5 = -iVar5;
  }
  return iVar5;
}

// --------------------------------------------------

// Function: atol
// Address: 0054c650
/* atol */

int __cdecl atol(byte *param_1)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  
  while( true ) {
    if (___mb_cur_max < 2) {
      uVar2 = (byte)__pctype[(uint)*param_1 * 2] & 8;
    }
    else {
      uVar2 = __isctype(*param_1,8);
    }
    if (uVar2 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar2 = (uint)*param_1;
  pbVar6 = param_1 + 1;
  if ((uVar2 == 0x2d) || (uVar4 = uVar2, uVar2 == 0x2b)) {
    uVar4 = (uint)*pbVar6;
    pbVar6 = param_1 + 2;
  }
  iVar5 = 0;
  while( true ) {
    if (___mb_cur_max < 2) {
      uVar3 = (byte)__pctype[uVar4 * 2] & 4;
    }
    else {
      uVar3 = __isctype(uVar4,4);
    }
    if (uVar3 == 0) break;
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    iVar5 = (uVar4 - 0x30) + iVar5 * 10;
    uVar4 = (uint)bVar1;
  }
  if (uVar2 == 0x2d) {
    iVar5 = -iVar5;
  }
  return iVar5;
}

// --------------------------------------------------

// Function: FUN_0054c6e9
// Address: 0054c6e9
void FUN_0054c6e9(undefined4 param_1)
{
  atol(param_1);
  return;
}

// --------------------------------------------------

// Function: atoi
// Address: 0054c6f0
/* atoi */

void __cdecl atoi(undefined4 param_1)
{
  atol(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0054c6fe
// Address: 0054c6fe
longlong FUN_0054c6fe(byte *param_1)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  longlong lVar5;
  
  while( true ) {
    if (___mb_cur_max < 2) {
      uVar1 = (byte)__pctype[(uint)*param_1 * 2] & 8;
    }
    else {
      uVar1 = __isctype(*param_1,8);
    }
    if (uVar1 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar1 = (uint)*param_1;
  pbVar4 = param_1 + 1;
  if ((uVar1 == 0x2d) || (uVar3 = uVar1, uVar1 == 0x2b)) {
    uVar3 = (uint)*pbVar4;
    pbVar4 = param_1 + 2;
  }
  lVar5 = 0;
  while( true ) {
    if (___mb_cur_max < 2) {
      uVar2 = (byte)__pctype[uVar3 * 2] & 4;
    }
    else {
      uVar2 = __isctype(uVar3,4);
    }
    if (uVar2 == 0) break;
    lVar5 = __allmul(lVar5,10,0);
    lVar5 = lVar5 + (int)(uVar3 - 0x30);
    uVar3 = (uint)*pbVar4;
    pbVar4 = pbVar4 + 1;
  }
  if (uVar1 == 0x2d) {
    return CONCAT44(-((int)((ulonglong)lVar5 >> 0x20) + (uint)((int)lVar5 != 0)),-(int)lVar5);
  }
  return lVar5;
}

// --------------------------------------------------

// Function: __atoi64
// Address: 0054c700
longlong __atoi64(byte *param_1)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  longlong lVar5;
  
  while( true ) {
    if (___mb_cur_max < 2) {
      uVar1 = (byte)__pctype[(uint)*param_1 * 2] & 8;
    }
    else {
      uVar1 = __isctype(*param_1,8);
    }
    if (uVar1 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar1 = (uint)*param_1;
  pbVar4 = param_1 + 1;
  if ((uVar1 == 0x2d) || (uVar3 = uVar1, uVar1 == 0x2b)) {
    uVar3 = (uint)*pbVar4;
    pbVar4 = param_1 + 2;
  }
  lVar5 = 0;
  while( true ) {
    if (___mb_cur_max < 2) {
      uVar2 = (byte)__pctype[uVar3 * 2] & 4;
    }
    else {
      uVar2 = __isctype(uVar3,4);
    }
    if (uVar2 == 0) break;
    lVar5 = __allmul(lVar5,10,0);
    lVar5 = lVar5 + (int)(uVar3 - 0x30);
    uVar3 = (uint)*pbVar4;
    pbVar4 = pbVar4 + 1;
  }
  if (uVar1 == 0x2d) {
    return CONCAT44(-((int)((ulonglong)lVar5 >> 0x20) + (uint)((int)lVar5 != 0)),-(int)lVar5);
  }
  return lVar5;
}

// --------------------------------------------------

// Function: FUN_0054c7c1
// Address: 0054c7c1
char * FUN_0054c7c1(char *param_1,byte *param_2,int param_3)
{
  char cVar1;
  byte bVar2;
  byte bVar3;
  char *pcVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  if (param_3 == 0) {
    return param_1;
  }
  if (___mbcodepage == 0) {
    pcVar4 = (char *)strncat(param_1,param_2,param_3);
    return pcVar4;
  }
  cVar1 = *param_1;
  pcVar4 = param_1 + 1;
  while (cVar1 != '\0') {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  }
  pbVar6 = (byte *)(pcVar4 + -1);
  iVar5 = __ismbslead(param_1,pbVar6);
  if (iVar5 != 0) {
    pbVar6 = (byte *)(pcVar4 + -2);
  }
  do {
    param_3 = param_3 + -1;
    bVar2 = *param_2;
    bVar3 = *(byte *)((int)&__mbctype + bVar2 + 1);
    *pbVar6 = bVar2;
    if ((bVar3 & 4) == 0) {
      pbVar7 = pbVar6 + 1;
      param_2 = param_2 + 1;
      if (bVar2 == 0) break;
    }
    else {
      bVar2 = param_2[1];
      pbVar6[1] = bVar2;
      pbVar7 = pbVar6 + 2;
      param_2 = param_2 + 2;
      if (bVar2 == 0) {
        *pbVar6 = 0;
        break;
      }
    }
    pbVar6 = pbVar7;
  } while (param_3 != 0);
  iVar5 = __mbsbtype(param_1,pbVar7 + (-1 - (int)param_1));
  if (iVar5 == 1) {
    pbVar7[-1] = 0;
    return param_1;
  }
  *pbVar7 = 0;
  return param_1;
}

// --------------------------------------------------

// Function: __mbsncat
// Address: 0054c7d0
char * __mbsncat(char *param_1,byte *param_2,int param_3)
{
  char cVar1;
  byte bVar2;
  byte bVar3;
  char *pcVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  if (param_3 == 0) {
    return param_1;
  }
  if (___mbcodepage == 0) {
    pcVar4 = (char *)strncat(param_1,param_2,param_3);
    return pcVar4;
  }
  cVar1 = *param_1;
  pcVar4 = param_1 + 1;
  while (cVar1 != '\0') {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  }
  pbVar6 = (byte *)(pcVar4 + -1);
  iVar5 = __ismbslead(param_1,pbVar6);
  if (iVar5 != 0) {
    pbVar6 = (byte *)(pcVar4 + -2);
  }
  do {
    param_3 = param_3 + -1;
    bVar2 = *param_2;
    bVar3 = *(byte *)((int)&__mbctype + bVar2 + 1);
    *pbVar6 = bVar2;
    if ((bVar3 & 4) == 0) {
      pbVar7 = pbVar6 + 1;
      param_2 = param_2 + 1;
      if (bVar2 == 0) break;
    }
    else {
      bVar2 = param_2[1];
      pbVar6[1] = bVar2;
      pbVar7 = pbVar6 + 2;
      param_2 = param_2 + 2;
      if (bVar2 == 0) {
        *pbVar6 = 0;
        break;
      }
    }
    pbVar6 = pbVar7;
  } while (param_3 != 0);
  iVar5 = __mbsbtype(param_1,pbVar7 + (-1 - (int)param_1));
  if (iVar5 == 1) {
    pbVar7[-1] = 0;
    return param_1;
  }
  *pbVar7 = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0054c893
// Address: 0054c893
uint FUN_0054c893(uint param_1)
{
  int iVar1;
  uint uVar2;
  undefined4 uStack_4;
  
  if (param_1 < 0x100) {
    if (1 < ___mb_cur_max) {
      uVar2 = __isctype(param_1,8);
      return uVar2;
    }
    return (byte)__pctype[param_1 * 2] & 8;
  }
  uStack_4 = 0;
  param_1 = CONCAT31(CONCAT21(param_1._2_2_,(char)param_1),(char)(param_1 >> 8));
  if (___mbcodepage == 0) {
    return 0;
  }
  iVar1 = ___crtGetStringTypeA(1,&param_1,2,&uStack_4,___mbcodepage,___mblcid);
  if (iVar1 == 0) {
    return 0;
  }
  if ((uStack_4._2_2_ == 0) && ((uStack_4 & 8) != 0)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: __ismbcspace
// Address: 0054c8a0
uint __ismbcspace(uint param_1)
{
  int iVar1;
  uint uVar2;
  undefined4 local_4;
  
  if (param_1 < 0x100) {
    if (1 < ___mb_cur_max) {
      uVar2 = __isctype(param_1,8);
      return uVar2;
    }
    return (byte)__pctype[param_1 * 2] & 8;
  }
  local_4 = 0;
  param_1 = CONCAT31(CONCAT21(param_1._2_2_,(char)param_1),(char)(param_1 >> 8));
  if (___mbcodepage == 0) {
    return 0;
  }
  iVar1 = ___crtGetStringTypeA(1,&param_1,2,&local_4,___mbcodepage,___mblcid);
  if (iVar1 == 0) {
    return 0;
  }
  if ((local_4._2_2_ == 0) && ((local_4 & 8) != 0)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054c934
// Address: 0054c934
int FUN_0054c934(int param_1,undefined4 param_2)
{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = __mbsnbcnt(param_1,param_2);
  return iVar1 + param_1;
}

// --------------------------------------------------

// Function: __mbsninc
// Address: 0054c940
int __mbsninc(int param_1,undefined4 param_2)
{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = __mbsnbcnt(param_1,param_2);
  return iVar1 + param_1;
}

// --------------------------------------------------

// Function: FUN_0054c95f
// Address: 0054c95f
char * FUN_0054c95f(char *param_1,char *param_2)
{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  
  if (___mbcodepage == 0) {
    pcVar3 = (char *)strstr(param_1,param_2);
    return pcVar3;
  }
  uVar5 = 0xffffffff;
  pcVar3 = param_2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  uVar6 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  pcVar3 = param_1 + ((~uVar6 - 1) - (~uVar5 - 1));
  if (*param_1 != '\0') {
    while (param_1 <= pcVar3) {
      pcVar4 = param_2;
      if (*param_1 != '\0') {
        do {
          if ((*pcVar4 == '\0') || (pcVar4[(int)param_1 - (int)param_2] != *pcVar4)) break;
          pcVar1 = pcVar4 + ((int)param_1 - (int)param_2) + 1;
          pcVar4 = pcVar4 + 1;
        } while (*pcVar1 != '\0');
      }
      if (*pcVar4 == '\0') {
        return param_1;
      }
      param_1 = (char *)__mbsinc(param_1);
      if (*param_1 == '\0') {
        return (char *)0x0;
      }
    }
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: __mbsstr
// Address: 0054c960
char * __mbsstr(char *param_1,char *param_2)
{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  
  if (___mbcodepage == 0) {
    pcVar3 = (char *)strstr(param_1,param_2);
    return pcVar3;
  }
  uVar5 = 0xffffffff;
  pcVar3 = param_2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  uVar6 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  pcVar3 = param_1 + ((~uVar6 - 1) - (~uVar5 - 1));
  if (*param_1 != '\0') {
    while (param_1 <= pcVar3) {
      pcVar4 = param_2;
      if (*param_1 != '\0') {
        do {
          if ((*pcVar4 == '\0') || (pcVar4[(int)param_1 - (int)param_2] != *pcVar4)) break;
          pcVar1 = pcVar4 + ((int)param_1 - (int)param_2) + 1;
          pcVar4 = pcVar4 + 1;
        } while (*pcVar1 != '\0');
      }
      if (*pcVar4 == '\0') {
        return param_1;
      }
      param_1 = (char *)__mbsinc(param_1);
      if (*param_1 == '\0') {
        return (char *)0x0;
      }
    }
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: FUN_0054c9fc
// Address: 0054c9fc
void FUN_0054c9fc(undefined4 param_1)
{
  FUN_0054ca20(param_1,1);
  return;
}

// --------------------------------------------------

// Function: mktime
// Address: 0054ca00
/* mktime */

void __cdecl mktime(undefined4 param_1)
{
  FUN_0054ca20(param_1,1);
  return;
}

// --------------------------------------------------

// Function: __mkgmtime
// Address: 0054ca10
void __mkgmtime(undefined4 param_1)
{
  FUN_0054ca20(param_1,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0054ca20
// Address: 0054ca20
int FUN_0054ca20(int *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = param_1;
  uVar3 = param_1[5];
  if ((int)uVar3 < 0x45) {
    return -1;
  }
  if (0x8b < (int)uVar3) {
    return -1;
  }
  iVar4 = param_1[4];
  if ((iVar4 < 0) || (0xb < iVar4)) {
    uVar3 = uVar3 + iVar4 / 0xc;
    iVar4 = iVar4 % 0xc;
    param_1[4] = iVar4;
    if (iVar4 < 0) {
      uVar3 = uVar3 - 1;
      param_1[4] = iVar4 + 0xc;
    }
    if ((int)uVar3 < 0x45) {
      return -1;
    }
    if (0x8b < (int)uVar3) {
      return -1;
    }
  }
  iVar4 = (&__days)[param_1[4]];
  if (((uVar3 & 3) == 0) && (1 < param_1[4])) {
    iVar4 = iVar4 + 1;
  }
  iVar1 = param_1[3];
  iVar5 = uVar3 * 0x16d + -0x63df + iVar4 + ((int)(uVar3 - 1) >> 2);
  iVar4 = iVar5 + iVar1;
  if (iVar5 < 0) {
LAB_0054cad0:
    if ((iVar1 < 0) && (-1 < iVar4)) {
      return -1;
    }
  }
  else {
    if ((-1 < iVar1) && (iVar4 < 0)) {
      return -1;
    }
    if (iVar5 < 0) goto LAB_0054cad0;
  }
  iVar5 = iVar4 * 0x18;
  if (iVar4 != 0 && iVar5 / iVar4 != 0x18) {
    return -1;
  }
  iVar1 = param_1[2];
  iVar4 = iVar1 + iVar5;
  if (iVar5 < 0) {
LAB_0054cb1b:
    if ((iVar1 < 0) && (-1 < iVar4)) {
      return -1;
    }
  }
  else {
    if ((-1 < iVar1) && (iVar4 < 0)) {
      return -1;
    }
    if (iVar5 < 0) goto LAB_0054cb1b;
  }
  iVar5 = iVar4 * 0x3c;
  if (iVar4 != 0 && iVar5 / iVar4 != 0x3c) {
    return -1;
  }
  iVar1 = param_1[1];
  iVar4 = iVar1 + iVar5;
  if (iVar5 < 0) {
LAB_0054cb6a:
    if ((iVar1 < 0) && (-1 < iVar4)) {
      return -1;
    }
  }
  else {
    if ((-1 < iVar1) && (iVar4 < 0)) {
      return -1;
    }
    if (iVar5 < 0) goto LAB_0054cb6a;
  }
  iVar5 = iVar4 * 0x3c;
  if (iVar4 != 0 && iVar5 / iVar4 != 0x3c) {
    return -1;
  }
  iVar4 = *param_1;
  param_1 = (int *)(iVar4 + iVar5);
  if (-1 < iVar5) {
    if ((-1 < iVar4) && ((int)param_1 < 0)) {
      return -1;
    }
    if (-1 < iVar5) goto LAB_0054cbc8;
  }
  if ((iVar4 < 0) && (-1 < (int)param_1)) {
    return -1;
  }
LAB_0054cbc8:
  if (param_2 == 0) {
    piVar2 = (int *)gmtime(&param_1);
    if (piVar2 == (int *)0x0) {
      return -1;
    }
  }
  else {
    ___tzset();
    param_1 = (int *)((int)param_1 + __timezone);
    piVar2 = (int *)localtime(&param_1);
    if (piVar2 == (int *)0x0) {
      return -1;
    }
    if ((0 < piVar6[8]) || ((piVar6[8] < 0 && (0 < piVar2[8])))) {
      param_1 = (int *)((int)param_1 + __dstbias);
      piVar2 = (int *)localtime(&param_1);
      for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar6 = *piVar2;
        piVar2 = piVar2 + 1;
        piVar6 = piVar6 + 1;
      }
      return (int)param_1;
    }
  }
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar6 = piVar6 + 1;
  }
  return (int)param_1;
}

// --------------------------------------------------

// Function: FUN_0054cc5c
// Address: 0054cc5c
void FUN_0054cc5c(undefined4 param_1)
{
  DAT_0058fb80 = param_1;
  return;
}

// --------------------------------------------------

// Function: srand
// Address: 0054cc60
/* srand */

void __cdecl srand(undefined4 param_1)
{
  DAT_0058fb80 = param_1;
  return;
}

// --------------------------------------------------

// Function: FUN_0054cc6a
// Address: 0054cc6a
uint FUN_0054cc6a(void)
{
  DAT_0058fb80 = DAT_0058fb80 * 0x343fd + 0x269ec3;
  return DAT_0058fb80 >> 0x10 & 0x7fff;
}

// --------------------------------------------------

// Function: rand
// Address: 0054cc70
/* rand */

uint __cdecl rand(void)
{
  DAT_0058fb80 = DAT_0058fb80 * 0x343fd + 0x269ec3;
  return DAT_0058fb80 >> 0x10 & 0x7fff;
}

// --------------------------------------------------

// Function: FUN_0054cc9a
// Address: 0054cc9a
undefined4 FUN_0054cc9a(uint param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (__nhandle <= param_1) {
    _errno = 9;
    __doserrno = 0;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 8;
  if ((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) {
    _errno = 9;
    __doserrno = 0;
    return 0xffffffff;
  }
  iVar1 = __get_osfhandle(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = __get_osfhandle(2);
      iVar2 = __get_osfhandle(1);
      if (iVar2 == iVar1) goto LAB_0054cd27;
    }
    uVar3 = __get_osfhandle(param_1);
    iVar1 = CloseHandle(uVar3);
    if (iVar1 == 0) {
      iVar1 = GetLastError();
      goto LAB_0054cd29;
    }
  }
LAB_0054cd27:
  iVar1 = 0;
LAB_0054cd29:
  __free_osfhnd(param_1);
  *(undefined1 *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar4) = 0;
  if (iVar1 == 0) {
    return 0;
  }
  __dosmaperr(iVar1);
  return 0xffffffff;
}

// --------------------------------------------------

// Function: close
// Address: 0054cca0
/* close */

undefined4 __cdecl close(uint param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (__nhandle <= param_1) {
    _errno = 9;
    __doserrno = 0;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 8;
  if ((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) {
    _errno = 9;
    __doserrno = 0;
    return 0xffffffff;
  }
  iVar1 = __get_osfhandle(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = __get_osfhandle(2);
      iVar2 = __get_osfhandle(1);
      if (iVar2 == iVar1) goto LAB_0054cd27;
    }
    uVar3 = __get_osfhandle(param_1);
    iVar1 = CloseHandle(uVar3);
    if (iVar1 == 0) {
      iVar1 = GetLastError();
      goto LAB_0054cd29;
    }
  }
LAB_0054cd27:
  iVar1 = 0;
LAB_0054cd29:
  __free_osfhnd(param_1);
  *(undefined1 *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar4) = 0;
  if (iVar1 == 0) {
    return 0;
  }
  __dosmaperr(iVar1);
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0054cd72
// Address: 0054cd72
int FUN_0054cd72(uint param_1,char *param_2,int param_3)
{
  int *piVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined4 unaff_EBX;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int *unaff_EDI;
  char *pcVar8;
  int iStack_20;
  char *pcStack_c;
  int *apiStack_8 [2];
  
  if (param_1 < __nhandle) {
    iVar5 = (param_1 & 0x1f) * 8;
    piVar1 = &___pioinfo + ((int)param_1 >> 5);
    pcStack_c = (char *)(iVar5 + (&___pioinfo)[(int)param_1 >> 5]);
    bVar3 = pcStack_c[4];
    if ((bVar3 & 1) != 0) {
      iVar6 = 0;
      if ((param_3 == 0) || ((bVar3 & 2) != 0)) {
        return 0;
      }
      pcVar8 = param_2;
      if (((bVar3 & 0x48) != 0) && (pcStack_c[5] != '\n')) {
        *param_2 = pcStack_c[5];
        pcVar8 = param_2 + 1;
        iVar6 = 1;
        param_3 = param_3 + -1;
        *(undefined1 *)(iVar5 + 5 + *piVar1) = 10;
      }
      iStack_20 = 0;
      apiStack_8[0] = piVar1;
      iVar4 = ReadFile(*(undefined4 *)(iVar5 + *piVar1),pcVar8,param_3,&pcStack_c);
      if (iVar4 == 0) {
        iVar5 = GetLastError();
        if (iVar5 == 5) {
          __doserrno = iVar5;
          _errno = 9;
          return -1;
        }
        if (iVar5 == 0x6d) {
          return 0;
        }
        __dosmaperr(iVar5);
        return -1;
      }
      iVar6 = iVar6 + iStack_20;
      bVar3 = *(byte *)(iVar5 + 4 + *piVar1);
      if ((bVar3 & 0x80) != 0) {
        if ((iStack_20 == 0) || (*param_2 != '\n')) {
          bVar3 = bVar3 & 0xfb;
        }
        else {
          bVar3 = bVar3 | 4;
        }
        *(byte *)(iVar5 + 4 + *piVar1) = bVar3;
        pcVar7 = pcStack_c + iVar6;
        pcVar8 = param_2;
        if (pcStack_c < pcVar7) {
          while (cVar2 = *pcVar8, cVar2 != '\x1a') {
            if (cVar2 == '\r') {
              if (pcVar8 < pcVar7 + -1) {
                if (pcVar8[1] == '\n') {
                  pcVar8 = pcVar8 + 2;
                  *param_2 = '\n';
                  goto LAB_0054cf68;
                }
                *param_2 = '\r';
                param_2 = param_2 + 1;
                pcVar8 = pcVar8 + 1;
              }
              else {
                iVar4 = 0;
                pcVar8 = pcVar8 + 1;
                iVar6 = ReadFile(*(undefined4 *)(iVar5 + *unaff_EDI),apiStack_8,1,&iStack_20,0);
                if (iVar6 == 0) {
                  iVar4 = GetLastError();
                }
                if ((iVar4 == 0) && (iStack_20 != 0)) {
                  if ((*(byte *)(iVar5 + 4 + *unaff_EDI) & 0x48) == 0) {
                    if ((param_2 == pcStack_c) && ((char)apiStack_8[0] == '\n')) {
                      *param_2 = '\n';
                      goto LAB_0054cf68;
                    }
                    lseek(unaff_EBX,0xffffffff,1);
                    if ((char)apiStack_8[0] != '\n') goto LAB_0054cf65;
                  }
                  else {
                    if ((char)apiStack_8[0] == '\n') {
                      *param_2 = '\n';
                      goto LAB_0054cf68;
                    }
                    *param_2 = '\r';
                    param_2 = param_2 + 1;
                    *(char *)(iVar5 + 5 + *unaff_EDI) = (char)apiStack_8[0];
                  }
                }
                else {
LAB_0054cf65:
                  *param_2 = '\r';
LAB_0054cf68:
                  param_2 = param_2 + 1;
                }
              }
            }
            else {
              *param_2 = cVar2;
              param_2 = param_2 + 1;
              pcVar8 = pcVar8 + 1;
            }
            if (pcVar7 <= pcVar8) {
              return (int)param_2 - (int)pcStack_c;
            }
          }
          bVar3 = *(byte *)(iVar5 + 4 + *unaff_EDI);
          if ((bVar3 & 0x40) == 0) {
            *(byte *)(iVar5 + 4 + *unaff_EDI) = bVar3 | 2;
          }
        }
        iVar6 = (int)param_2 - (int)pcStack_c;
      }
      return iVar6;
    }
  }
  _errno = 9;
  __doserrno = 0;
  return -1;
}

// --------------------------------------------------

// Function: read
// Address: 0054cd80
/* read */

int __cdecl read(uint param_1,char *param_2,int param_3)
{
  int *piVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined4 unaff_EBX;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int *unaff_EDI;
  char *pcVar8;
  int iStack_20;
  char *local_c;
  int *local_8 [2];
  
  if (param_1 < __nhandle) {
    iVar5 = (param_1 & 0x1f) * 8;
    piVar1 = &___pioinfo + ((int)param_1 >> 5);
    local_c = (char *)(iVar5 + (&___pioinfo)[(int)param_1 >> 5]);
    bVar3 = local_c[4];
    if ((bVar3 & 1) != 0) {
      iVar6 = 0;
      if ((param_3 == 0) || ((bVar3 & 2) != 0)) {
        return 0;
      }
      pcVar8 = param_2;
      if (((bVar3 & 0x48) != 0) && (local_c[5] != '\n')) {
        *param_2 = local_c[5];
        pcVar8 = param_2 + 1;
        iVar6 = 1;
        param_3 = param_3 + -1;
        *(undefined1 *)(iVar5 + 5 + *piVar1) = 10;
      }
      iStack_20 = 0;
      local_8[0] = piVar1;
      iVar4 = ReadFile(*(undefined4 *)(iVar5 + *piVar1),pcVar8,param_3,&local_c);
      if (iVar4 == 0) {
        iVar5 = GetLastError();
        if (iVar5 == 5) {
          __doserrno = iVar5;
          _errno = 9;
          return -1;
        }
        if (iVar5 == 0x6d) {
          return 0;
        }
        __dosmaperr(iVar5);
        return -1;
      }
      iVar6 = iVar6 + iStack_20;
      bVar3 = *(byte *)(iVar5 + 4 + *piVar1);
      if ((bVar3 & 0x80) != 0) {
        if ((iStack_20 == 0) || (*param_2 != '\n')) {
          bVar3 = bVar3 & 0xfb;
        }
        else {
          bVar3 = bVar3 | 4;
        }
        *(byte *)(iVar5 + 4 + *piVar1) = bVar3;
        pcVar7 = local_c + iVar6;
        pcVar8 = param_2;
        if (local_c < pcVar7) {
          while (cVar2 = *pcVar8, cVar2 != '\x1a') {
            if (cVar2 == '\r') {
              if (pcVar8 < pcVar7 + -1) {
                if (pcVar8[1] == '\n') {
                  pcVar8 = pcVar8 + 2;
                  *param_2 = '\n';
                  goto LAB_0054cf68;
                }
                *param_2 = '\r';
                param_2 = param_2 + 1;
                pcVar8 = pcVar8 + 1;
              }
              else {
                iVar4 = 0;
                pcVar8 = pcVar8 + 1;
                iVar6 = ReadFile(*(undefined4 *)(iVar5 + *unaff_EDI),local_8,1,&iStack_20,0);
                if (iVar6 == 0) {
                  iVar4 = GetLastError();
                }
                if ((iVar4 == 0) && (iStack_20 != 0)) {
                  if ((*(byte *)(iVar5 + 4 + *unaff_EDI) & 0x48) == 0) {
                    if ((param_2 == local_c) && ((char)local_8[0] == '\n')) {
                      *param_2 = '\n';
                      goto LAB_0054cf68;
                    }
                    lseek(unaff_EBX,0xffffffff,1);
                    if ((char)local_8[0] != '\n') goto LAB_0054cf65;
                  }
                  else {
                    if ((char)local_8[0] == '\n') {
                      *param_2 = '\n';
                      goto LAB_0054cf68;
                    }
                    *param_2 = '\r';
                    param_2 = param_2 + 1;
                    *(char *)(iVar5 + 5 + *unaff_EDI) = (char)local_8[0];
                  }
                }
                else {
LAB_0054cf65:
                  *param_2 = '\r';
LAB_0054cf68:
                  param_2 = param_2 + 1;
                }
              }
            }
            else {
              *param_2 = cVar2;
              param_2 = param_2 + 1;
              pcVar8 = pcVar8 + 1;
            }
            if (pcVar7 <= pcVar8) {
              return (int)param_2 - (int)local_c;
            }
          }
          bVar3 = *(byte *)(iVar5 + 4 + *unaff_EDI);
          if ((bVar3 & 0x40) == 0) {
            *(byte *)(iVar5 + 4 + *unaff_EDI) = bVar3 | 2;
          }
        }
        iVar6 = (int)param_2 - (int)local_c;
      }
      return iVar6;
    }
  }
  _errno = 9;
  __doserrno = 0;
  return -1;
}

// --------------------------------------------------

// Function: FUN_0054cfd4
// Address: 0054cfd4
void FUN_0054cfd4(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  __sopen(param_1,param_2,0x40,param_3);
  return;
}

// --------------------------------------------------

// Function: __open
// Address: 0054cfe0
void __open(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  __sopen(param_1,param_2,0x40,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0054cffa
// Address: 0054cffa
uint FUN_0054cffa(undefined4 param_1,uint param_2,undefined4 param_3,byte param_4)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint unaff_EBX;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  undefined4 *puVar10;
  char acStack_14 [3];
  byte bStack_11;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  bVar9 = (param_2 & 0x80) == 0;
  uStack_c = 0xc;
  uStack_8 = 0;
  if (bVar9) {
    bStack_11 = 0;
  }
  else {
    bStack_11 = 0x10;
  }
  uStack_4 = (uint)bVar9;
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (__fmode != 0x8000)))) {
    bStack_11 = bStack_11 | 0x80;
  }
  uVar2 = param_2 & 3;
  if (uVar2 == 0) {
    uStack_10 = 0x80000000;
  }
  else if (uVar2 == 1) {
    uStack_10 = 0x40000000;
  }
  else {
    if (uVar2 != 2) {
      _errno = 0x16;
      __doserrno = 0;
      return 0xffffffff;
    }
    uStack_10 = 0xc0000000;
  }
  switch(param_3) {
  case 0x10:
    uVar7 = 0;
    break;
  default:
    goto switchD_0054d098_caseD_11;
  case 0x20:
    uVar7 = 1;
    break;
  case 0x30:
    uVar7 = 2;
    break;
  case 0x40:
    uVar7 = 3;
  }
  uVar2 = param_2 & 0x700;
  if (uVar2 < 0x101) {
    if (uVar2 == 0x100) {
      uVar8 = 4;
    }
    else {
      if (uVar2 != 0) {
        _errno = 0x16;
        __doserrno = 0;
        return 0xffffffff;
      }
LAB_0054d106:
      uVar8 = 3;
    }
  }
  else if (uVar2 < 0x301) {
    if (uVar2 == 0x300) {
      uVar8 = 2;
    }
    else {
      if (uVar2 != 0x200) {
        _errno = 0x16;
        __doserrno = 0;
        return 0xffffffff;
      }
LAB_0054d126:
      uVar8 = 5;
    }
  }
  else {
    if (uVar2 < 0x501) {
      if (uVar2 != 0x500) {
        if (uVar2 != 0x400) {
switchD_0054d098_caseD_11:
          __doserrno = 0;
          _errno = 0x16;
          return 0xffffffff;
        }
        goto LAB_0054d106;
      }
    }
    else {
      if (uVar2 == 0x600) goto LAB_0054d126;
      if (uVar2 != 0x700) {
        _errno = 0x16;
        __doserrno = 0;
        return 0xffffffff;
      }
    }
    uVar8 = 1;
  }
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((param_4 & ~(byte)__umaskval & 0x80) == 0)) {
    uVar2 = 1;
  }
  if ((param_2 & 0x40) != 0) {
    uVar2 = uVar2 | 0x4000000;
    uStack_10 = uStack_10 | 0x10000;
  }
  if ((param_2 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((param_2 & 0x20) == 0) {
    if ((param_2 & 0x10) != 0) {
      uVar2 = uVar2 | 0x10000000;
    }
  }
  else {
    uVar2 = uVar2 | 0x8000000;
  }
  uVar3 = __alloc_osfhnd();
  if (uVar3 == 0xffffffff) {
    _errno = 0x18;
    __doserrno = 0;
    return 0xffffffff;
  }
  puVar10 = &uStack_c;
  iVar4 = CreateFileA(param_1,uStack_10,uVar7,puVar10,uVar8,uVar2,0);
  if (iVar4 == -1) {
    uVar7 = GetLastError();
    __dosmaperr(uVar7);
    return 0xffffffff;
  }
  iVar5 = GetFileType(iVar4);
  if (iVar5 == 0) {
    CloseHandle(iVar4);
    uVar7 = GetLastError();
    __dosmaperr(uVar7);
    return 0xffffffff;
  }
  bVar1 = (byte)((uint)puVar10 >> 0x18);
  if (iVar5 == 2) {
    bVar1 = bVar1 | 0x40;
  }
  else {
    if (iVar5 != 3) goto LAB_0054d233;
    bVar1 = bVar1 | 8;
  }
  puVar10 = (undefined4 *)((uint)bVar1 << 0x18);
LAB_0054d233:
  __set_osfhnd(uVar3,iVar4);
  iVar4 = (uVar3 & 0x1f) * 8;
  *(byte *)(iVar4 + 4 + (&___pioinfo)[(int)uVar3 >> 5]) = (byte)((uint)puVar10 >> 0x18) | 1;
  if (((((uint)puVar10 & 0x48000000) == 0) && (((uint)puVar10 & 0x80000000) != 0)) &&
     ((unaff_EBX & 2) != 0)) {
    iVar5 = lseek(uVar3,0xffffffff,2);
    if (iVar5 == -1) {
      if (__doserrno != 0x83) {
        close(uVar3);
        return 0xffffffff;
      }
    }
    else {
      acStack_14[0] = '\0';
      iVar6 = read(uVar3,acStack_14,1);
      if (((iVar6 == 0) && (acStack_14[0] == '\x1a')) &&
         (iVar5 = __chsize(uVar3,iVar5), iVar5 == -1)) {
        close(uVar3);
        return 0xffffffff;
      }
      iVar5 = lseek(uVar3,0,0);
      if (iVar5 == -1) {
        close(uVar3);
        return 0xffffffff;
      }
    }
  }
  if ((((uint)puVar10 & 0x48000000) == 0) && ((unaff_EBX & 8) != 0)) {
    *(byte *)(iVar4 + 4 + (&___pioinfo)[(int)uVar3 >> 5]) =
         *(byte *)(iVar4 + 4 + (&___pioinfo)[(int)uVar3 >> 5]) | 0x20;
  }
  return uVar3;
}

// --------------------------------------------------

// Function: __sopen
// Address: 0054d000
uint __sopen(undefined4 param_1,uint param_2,undefined4 param_3,byte param_4)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint unaff_EBX;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  undefined4 *puVar10;
  char acStack_14 [3];
  byte local_11;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  bVar9 = (param_2 & 0x80) == 0;
  local_c = 0xc;
  local_8 = 0;
  if (bVar9) {
    local_11 = 0;
  }
  else {
    local_11 = 0x10;
  }
  local_4 = (uint)bVar9;
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (__fmode != 0x8000)))) {
    local_11 = local_11 | 0x80;
  }
  uVar2 = param_2 & 3;
  if (uVar2 == 0) {
    local_10 = 0x80000000;
  }
  else if (uVar2 == 1) {
    local_10 = 0x40000000;
  }
  else {
    if (uVar2 != 2) {
      _errno = 0x16;
      __doserrno = 0;
      return 0xffffffff;
    }
    local_10 = 0xc0000000;
  }
  switch(param_3) {
  case 0x10:
    uVar7 = 0;
    break;
  default:
    goto switchD_0054d098_caseD_11;
  case 0x20:
    uVar7 = 1;
    break;
  case 0x30:
    uVar7 = 2;
    break;
  case 0x40:
    uVar7 = 3;
  }
  uVar2 = param_2 & 0x700;
  if (uVar2 < 0x101) {
    if (uVar2 == 0x100) {
      uVar8 = 4;
    }
    else {
      if (uVar2 != 0) {
        _errno = 0x16;
        __doserrno = 0;
        return 0xffffffff;
      }
LAB_0054d106:
      uVar8 = 3;
    }
  }
  else if (uVar2 < 0x301) {
    if (uVar2 == 0x300) {
      uVar8 = 2;
    }
    else {
      if (uVar2 != 0x200) {
        _errno = 0x16;
        __doserrno = 0;
        return 0xffffffff;
      }
LAB_0054d126:
      uVar8 = 5;
    }
  }
  else {
    if (uVar2 < 0x501) {
      if (uVar2 != 0x500) {
        if (uVar2 != 0x400) {
switchD_0054d098_caseD_11:
          __doserrno = 0;
          _errno = 0x16;
          return 0xffffffff;
        }
        goto LAB_0054d106;
      }
    }
    else {
      if (uVar2 == 0x600) goto LAB_0054d126;
      if (uVar2 != 0x700) {
        _errno = 0x16;
        __doserrno = 0;
        return 0xffffffff;
      }
    }
    uVar8 = 1;
  }
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((param_4 & ~(byte)__umaskval & 0x80) == 0)) {
    uVar2 = 1;
  }
  if ((param_2 & 0x40) != 0) {
    uVar2 = uVar2 | 0x4000000;
    local_10 = local_10 | 0x10000;
  }
  if ((param_2 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((param_2 & 0x20) == 0) {
    if ((param_2 & 0x10) != 0) {
      uVar2 = uVar2 | 0x10000000;
    }
  }
  else {
    uVar2 = uVar2 | 0x8000000;
  }
  uVar3 = __alloc_osfhnd();
  if (uVar3 == 0xffffffff) {
    _errno = 0x18;
    __doserrno = 0;
    return 0xffffffff;
  }
  puVar10 = &local_c;
  iVar4 = CreateFileA(param_1,local_10,uVar7,puVar10,uVar8,uVar2,0);
  if (iVar4 == -1) {
    uVar7 = GetLastError();
    __dosmaperr(uVar7);
    return 0xffffffff;
  }
  iVar5 = GetFileType(iVar4);
  if (iVar5 == 0) {
    CloseHandle(iVar4);
    uVar7 = GetLastError();
    __dosmaperr(uVar7);
    return 0xffffffff;
  }
  bVar1 = (byte)((uint)puVar10 >> 0x18);
  if (iVar5 == 2) {
    bVar1 = bVar1 | 0x40;
  }
  else {
    if (iVar5 != 3) goto LAB_0054d233;
    bVar1 = bVar1 | 8;
  }
  puVar10 = (undefined4 *)((uint)bVar1 << 0x18);
LAB_0054d233:
  __set_osfhnd(uVar3,iVar4);
  iVar4 = (uVar3 & 0x1f) * 8;
  *(byte *)(iVar4 + 4 + (&___pioinfo)[(int)uVar3 >> 5]) = (byte)((uint)puVar10 >> 0x18) | 1;
  if (((((uint)puVar10 & 0x48000000) == 0) && (((uint)puVar10 & 0x80000000) != 0)) &&
     ((unaff_EBX & 2) != 0)) {
    iVar5 = lseek(uVar3,0xffffffff,2);
    if (iVar5 == -1) {
      if (__doserrno != 0x83) {
        close(uVar3);
        return 0xffffffff;
      }
    }
    else {
      acStack_14[0] = '\0';
      iVar6 = read(uVar3,acStack_14,1);
      if (((iVar6 == 0) && (acStack_14[0] == '\x1a')) &&
         (iVar5 = __chsize(uVar3,iVar5), iVar5 == -1)) {
        close(uVar3);
        return 0xffffffff;
      }
      iVar5 = lseek(uVar3,0,0);
      if (iVar5 == -1) {
        close(uVar3);
        return 0xffffffff;
      }
    }
  }
  if ((((uint)puVar10 & 0x48000000) == 0) && ((unaff_EBX & 8) != 0)) {
    *(byte *)(iVar4 + 4 + (&___pioinfo)[(int)uVar3 >> 5]) =
         *(byte *)(iVar4 + 4 + (&___pioinfo)[(int)uVar3 >> 5]) | 0x20;
  }
  return uVar3;
}

// --------------------------------------------------

// Function: __tell
// Address: 0054d3c0
void __tell(undefined4 param_1)
{
  lseek(param_1,0,1);
  return;
}

// --------------------------------------------------

// Function: FUN_0054d3d2
// Address: 0054d3d2
int FUN_0054d3d2(uint param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 < __nhandle) {
    iVar3 = (param_1 & 0x1f) * 8;
    if ((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar3) & 1) != 0) {
      iVar1 = __get_osfhandle(param_1);
      if (iVar1 == -1) {
        _errno = 9;
        return -1;
      }
      iVar1 = SetFilePointer(iVar1,param_2,0,param_3);
      if (iVar1 == -1) {
        iVar2 = GetLastError();
      }
      else {
        iVar2 = 0;
      }
      if (iVar2 != 0) {
        __dosmaperr(iVar2);
        return -1;
      }
      *(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar3) =
           *(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar3) & 0xfd;
      return iVar1;
    }
  }
  _errno = 9;
  __doserrno = 0;
  return -1;
}

// --------------------------------------------------

// Function: lseek
// Address: 0054d3e0
/* lseek */

int __cdecl lseek(uint param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 < __nhandle) {
    iVar3 = (param_1 & 0x1f) * 8;
    if ((*(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar3) & 1) != 0) {
      iVar1 = __get_osfhandle(param_1);
      if (iVar1 == -1) {
        _errno = 9;
        return -1;
      }
      iVar1 = SetFilePointer(iVar1,param_2,0,param_3);
      if (iVar1 == -1) {
        iVar2 = GetLastError();
      }
      else {
        iVar2 = 0;
      }
      if (iVar2 != 0) {
        __dosmaperr(iVar2);
        return -1;
      }
      *(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar3) =
           *(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + iVar3) & 0xfd;
      return iVar1;
    }
  }
  _errno = 9;
  __doserrno = 0;
  return -1;
}

// --------------------------------------------------

// Function: FUN_0054d49d
// Address: 0054d49d
int FUN_0054d49d(uint param_1,char *param_2,uint param_3)
{
  int *piVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iStack_41c;
  int iStack_414;
  int iStack_410;
  int iStack_40c;
  int *piStack_408;
  char acStack_404 [1028];
  
  if (param_1 < __nhandle) {
    piVar1 = &___pioinfo + ((int)param_1 >> 5);
    iVar6 = (param_1 & 0x1f) * 8;
    bVar2 = *(byte *)(iVar6 + 4 + (&___pioinfo)[(int)param_1 >> 5]);
    if ((bVar2 & 1) != 0) {
      iStack_41c = 0;
      iStack_40c = 0;
      if (param_3 == 0) {
        return 0;
      }
      piStack_408 = piVar1;
      if ((bVar2 & 0x20) != 0) {
        lseek(param_1,0,2);
      }
      if ((*(byte *)((undefined4 *)(*piVar1 + iVar6) + 1) & 0x80) == 0) {
        iVar5 = WriteFile(*(undefined4 *)(*piVar1 + iVar6),param_2,param_3,&iStack_410,0);
        if (iVar5 == 0) {
          iStack_414 = GetLastError();
        }
        else {
          iStack_41c = iStack_410;
          iStack_414 = 0;
        }
      }
      else {
        iStack_414 = 0;
        pcVar7 = param_2;
        if (param_3 != 0) {
          do {
            pcVar4 = acStack_404;
            do {
              if (param_3 <= (uint)((int)pcVar7 - (int)param_2)) break;
              cVar3 = *pcVar7;
              pcVar7 = pcVar7 + 1;
              if (cVar3 == '\n') {
                *pcVar4 = '\r';
                iStack_40c = iStack_40c + 1;
                pcVar4 = pcVar4 + 1;
              }
              *pcVar4 = cVar3;
              pcVar4 = pcVar4 + 1;
            } while ((int)pcVar4 - (int)acStack_404 < 0x400);
            iVar5 = WriteFile(*(undefined4 *)(iVar6 + *piStack_408),acStack_404,
                              (int)pcVar4 - (int)acStack_404,&iStack_410,0);
            if (iVar5 == 0) {
              iStack_414 = GetLastError();
              break;
            }
            iStack_41c = iStack_41c + iStack_410;
            if ((iStack_410 < (int)pcVar4 - (int)acStack_404) ||
               (param_3 <= (uint)((int)pcVar7 - (int)param_2))) break;
          } while( true );
        }
      }
      if (iStack_41c != 0) {
        return iStack_41c - iStack_40c;
      }
      if (iStack_414 == 0) {
        if (((*(byte *)(iVar6 + 4 + *piStack_408) & 0x40) != 0) && (*param_2 == '\x1a')) {
          return 0;
        }
        _errno = 0x1c;
        __doserrno = 0;
        return -1;
      }
      if (iStack_414 == 5) {
        __doserrno = iStack_414;
        _errno = 9;
        return -1;
      }
      __dosmaperr(iStack_414);
      return -1;
    }
  }
  _errno = 9;
  __doserrno = 0;
  return -1;
}

// --------------------------------------------------

// Function: write
// Address: 0054d4a0
/* write */

int __cdecl write(uint param_1,char *param_2,uint param_3)
{
  int *piVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int local_41c;
  int local_414;
  int local_410;
  int local_40c;
  int *local_408;
  char local_404 [1028];
  
  if (param_1 < __nhandle) {
    piVar1 = &___pioinfo + ((int)param_1 >> 5);
    iVar6 = (param_1 & 0x1f) * 8;
    bVar2 = *(byte *)(iVar6 + 4 + (&___pioinfo)[(int)param_1 >> 5]);
    if ((bVar2 & 1) != 0) {
      local_41c = 0;
      local_40c = 0;
      if (param_3 == 0) {
        return 0;
      }
      local_408 = piVar1;
      if ((bVar2 & 0x20) != 0) {
        lseek(param_1,0,2);
      }
      if ((*(byte *)((undefined4 *)(*piVar1 + iVar6) + 1) & 0x80) == 0) {
        iVar5 = WriteFile(*(undefined4 *)(*piVar1 + iVar6),param_2,param_3,&local_410,0);
        if (iVar5 == 0) {
          local_414 = GetLastError();
        }
        else {
          local_41c = local_410;
          local_414 = 0;
        }
      }
      else {
        local_414 = 0;
        pcVar7 = param_2;
        if (param_3 != 0) {
          do {
            pcVar4 = local_404;
            do {
              if (param_3 <= (uint)((int)pcVar7 - (int)param_2)) break;
              cVar3 = *pcVar7;
              pcVar7 = pcVar7 + 1;
              if (cVar3 == '\n') {
                *pcVar4 = '\r';
                local_40c = local_40c + 1;
                pcVar4 = pcVar4 + 1;
              }
              *pcVar4 = cVar3;
              pcVar4 = pcVar4 + 1;
            } while ((int)pcVar4 - (int)local_404 < 0x400);
            iVar5 = WriteFile(*(undefined4 *)(iVar6 + *local_408),local_404,
                              (int)pcVar4 - (int)local_404,&local_410,0);
            if (iVar5 == 0) {
              local_414 = GetLastError();
              break;
            }
            local_41c = local_41c + local_410;
            if ((local_410 < (int)pcVar4 - (int)local_404) ||
               (param_3 <= (uint)((int)pcVar7 - (int)param_2))) break;
          } while( true );
        }
      }
      if (local_41c != 0) {
        return local_41c - local_40c;
      }
      if (local_414 == 0) {
        if (((*(byte *)(iVar6 + 4 + *local_408) & 0x40) != 0) && (*param_2 == '\x1a')) {
          return 0;
        }
        _errno = 0x1c;
        __doserrno = 0;
        return -1;
      }
      if (local_414 == 5) {
        __doserrno = local_414;
        _errno = 9;
        return -1;
      }
      __dosmaperr(local_414);
      return -1;
    }
  }
  _errno = 9;
  __doserrno = 0;
  return -1;
}

// --------------------------------------------------

// Function: FUN_0054d6be
// Address: 0054d6be
void FUN_0054d6be(undefined4 param_1,undefined4 param_2)
{
  __input(param_1,param_2,&stack0x0000000c);
  return;
}

// --------------------------------------------------

// Function: fscanf
// Address: 0054d6c0
/* fscanf */

void __cdecl fscanf(undefined4 param_1,undefined4 param_2)
{
  __input(param_1,param_2,&stack0x0000000c);
  return;
}

// --------------------------------------------------

// Function: FUN_0054d6d8
// Address: 0054d6d8
void FUN_0054d6d8(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &DAT_00577a58;
  uStack_10 = 0x554df8;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  uStack_8 = 0;
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
    (*param_4)();
  }
  uStack_8 = 0xffffffff;
  FUN_0054d758();
  *unaff_FS_OFFSET = uStack_14;
  return;
}

// --------------------------------------------------

// Function: `eh_vector_constructor_iterator'
// Address: 0054d6e0
/* void __stdcall `eh vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *),void (__thiscall*)(void *)) */

void _eh_vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4,
               _func_void_void_ptr *param_5)
{
  int iVar1;
  void *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577a58;
  uStack_10 = 0x554df8;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
    (*param_4)(unaff_EDI);
  }
  local_8 = 0xffffffff;
  FUN_0054d758();
  *unaff_FS_OFFSET = local_14;
  return;
}

// --------------------------------------------------

// Function: FUN_0054d74f
// Address: 0054d74f
void FUN_0054d74f(void)
{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054d758
// Address: 0054d758
void FUN_0054d758(void)
{
  uint unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  void *unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(unaff_EDI,unaff_EBX,unaff_ESI,*(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054d76c
// Address: 0054d76c
void FUN_0054d76c(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_0054d77f
// Address: 0054d77f
void FUN_0054d77f(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &DAT_00577a68;
  uStack_10 = 0x554df8;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  uStack_8 = 0;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)();
  }
  uStack_8 = 0xffffffff;
  FUN_0054d7f9();
  *unaff_FS_OFFSET = uStack_14;
  return;
}

// --------------------------------------------------

// Function: `eh_vector_destructor_iterator'
// Address: 0054d780
/* void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *)) */

void _eh_vector_destructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)
{
  void *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577a68;
  uStack_10 = 0x554df8;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(unaff_EDI);
  }
  local_8 = 0xffffffff;
  FUN_0054d7f9();
  *unaff_FS_OFFSET = local_14;
  return;
}

// --------------------------------------------------

// Function: FUN_0054d7f3
// Address: 0054d7f3
void FUN_0054d7f3(void)
{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054d7f9
// Address: 0054d7f9
void FUN_0054d7f9(void)
{
  int unaff_EBP;
  void *unaff_ESI;
  uint unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(unaff_ESI,unaff_EDI,*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054d810
// Address: 0054d810
void FUN_0054d810(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_0054d823
// Address: 0054d823
void FUN_0054d823(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &DAT_00577a78;
  uStack_10 = 0x554df8;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  uStack_8 = 0;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)();
  }
  *unaff_FS_OFFSET = uStack_14;
  return;
}

// --------------------------------------------------

// Function: __ArrayUnwind
// Address: 0054d830
/* void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *)) */

void __ArrayUnwind(void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)
{
  void *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577a78;
  uStack_10 = 0x554df8;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(unaff_EDI);
  }
  *unaff_FS_OFFSET = local_14;
  return;
}

// --------------------------------------------------

// Function: FUN_0054d870
// Address: 0054d870
void FUN_0054d870(void)
{
  int unaff_EBP;
  
  FUN_0054d8a0(*(undefined4 *)(unaff_EBP + -0x14));
  return;
}

// --------------------------------------------------

// Function: FUN_0054d87d
// Address: 0054d87d
void FUN_0054d87d(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_0054d89a
// Address: 0054d89a
undefined4 FUN_0054d89a(undefined4 *param_1)
{
  if (*(int *)*param_1 == -0x1f928c9d) {
    terminate();
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054d8a0
// Address: 0054d8a0
undefined4 FUN_0054d8a0(undefined4 *param_1)
{
  if (*(int *)*param_1 == -0x1f928c9d) {
    terminate();
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054d8b6
// Address: 0054d8b6
int FUN_0054d8b6(char *param_1,undefined4 param_2)
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = 0xffffffff;
  pcVar5 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = __stbuf(param_2);
  iVar3 = fwrite(param_1,1,~uVar4 - 1,param_2);
  __ftbuf(uVar2,param_2);
  return -(uint)(iVar3 != ~uVar4 - 1);
}

// --------------------------------------------------

// Function: fputs
// Address: 0054d8c0
/* fputs */

int __cdecl fputs(char *param_1,undefined4 param_2)
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = 0xffffffff;
  pcVar5 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = __stbuf(param_2);
  iVar3 = fwrite(param_1,1,~uVar4 - 1,param_2);
  __ftbuf(uVar2,param_2);
  return -(uint)(iVar3 != ~uVar4 - 1);
}

// --------------------------------------------------

// Function: FUN_0054d90b
// Address: 0054d90b
uint * FUN_0054d90b(uint *param_1,uint *param_2,uint param_3)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  if (param_3 != 0) {
    uVar4 = (uint)param_1 & 3;
    puVar5 = param_1;
    while (uVar4 != 0) {
      uVar4 = *puVar5;
      puVar5 = (uint *)((int)puVar5 + 1);
      if ((byte)uVar4 == 0) goto LAB_0054d96b;
      uVar4 = (uint)puVar5 & 3;
    }
    do {
      do {
        puVar6 = puVar5;
        puVar5 = puVar6 + 1;
      } while (((*puVar6 ^ 0xffffffff ^ *puVar6 + 0x7efefeff) & 0x81010100) == 0);
      uVar4 = *puVar6;
      if ((char)uVar4 == '\0') goto LAB_0054d97b;
      if ((char)(uVar4 >> 8) == '\0') {
        puVar6 = (uint *)((int)puVar6 + 1);
        goto LAB_0054d97b;
      }
      if ((uVar4 & 0xff0000) == 0) {
        puVar6 = (uint *)((int)puVar6 + 2);
        goto LAB_0054d97b;
      }
    } while ((uVar4 & 0xff000000) != 0);
LAB_0054d96b:
    puVar6 = (uint *)((int)puVar5 + -1);
LAB_0054d97b:
    if (((uint)param_2 & 3) == 0) {
      uVar3 = param_3 >> 2;
    }
    else {
      do {
        bVar1 = (byte)*param_2;
        uVar4 = (uint)bVar1;
        param_2 = (uint *)((int)param_2 + 1);
        if (bVar1 == 0) goto LAB_0054d9ca;
        *(byte *)puVar6 = bVar1;
        puVar6 = (uint *)((int)puVar6 + 1);
        param_3 = param_3 - 1;
        if (param_3 == 0) goto LAB_0054d9c0;
      } while (((uint)param_2 & 3) != 0);
      uVar3 = param_3 >> 2;
    }
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      uVar2 = *param_2;
      uVar4 = *param_2;
      param_2 = param_2 + 1;
      if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar4 == '\0') {
LAB_0054d9ca:
          *(byte *)puVar6 = (byte)uVar4;
          return param_1;
        }
        if ((char)(uVar4 >> 8) == '\0') {
          *(short *)puVar6 = (short)uVar4;
          return param_1;
        }
        if ((uVar4 & 0xff0000) == 0) {
          *(short *)puVar6 = (short)uVar4;
          *(byte *)((int)puVar6 + 2) = 0;
          return param_1;
        }
        if ((uVar4 & 0xff000000) == 0) {
          *puVar6 = uVar4;
          return param_1;
        }
      }
      *puVar6 = uVar4;
      puVar6 = puVar6 + 1;
    }
    for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
      uVar4 = *param_2;
      param_2 = (uint *)((int)param_2 + 1);
      *(byte *)puVar6 = (byte)uVar4;
      puVar6 = (uint *)((int)puVar6 + 1);
      if ((byte)uVar4 == 0) {
        return param_1;
      }
    }
LAB_0054d9c0:
    *(byte *)puVar6 = (byte)param_3;
  }
  return param_1;
}

// --------------------------------------------------

// Function: strncat
// Address: 0054d910
/* strncat */

uint * __cdecl strncat(uint *param_1,uint *param_2,uint param_3)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  if (param_3 != 0) {
    uVar4 = (uint)param_1 & 3;
    puVar5 = param_1;
    while (uVar4 != 0) {
      uVar4 = *puVar5;
      puVar5 = (uint *)((int)puVar5 + 1);
      if ((byte)uVar4 == 0) goto LAB_0054d96b;
      uVar4 = (uint)puVar5 & 3;
    }
    do {
      do {
        puVar6 = puVar5;
        puVar5 = puVar6 + 1;
      } while (((*puVar6 ^ 0xffffffff ^ *puVar6 + 0x7efefeff) & 0x81010100) == 0);
      uVar4 = *puVar6;
      if ((char)uVar4 == '\0') goto LAB_0054d97b;
      if ((char)(uVar4 >> 8) == '\0') {
        puVar6 = (uint *)((int)puVar6 + 1);
        goto LAB_0054d97b;
      }
      if ((uVar4 & 0xff0000) == 0) {
        puVar6 = (uint *)((int)puVar6 + 2);
        goto LAB_0054d97b;
      }
    } while ((uVar4 & 0xff000000) != 0);
LAB_0054d96b:
    puVar6 = (uint *)((int)puVar5 + -1);
LAB_0054d97b:
    if (((uint)param_2 & 3) == 0) {
      uVar3 = param_3 >> 2;
    }
    else {
      do {
        bVar1 = (byte)*param_2;
        uVar4 = (uint)bVar1;
        param_2 = (uint *)((int)param_2 + 1);
        if (bVar1 == 0) goto LAB_0054d9ca;
        *(byte *)puVar6 = bVar1;
        puVar6 = (uint *)((int)puVar6 + 1);
        param_3 = param_3 - 1;
        if (param_3 == 0) goto LAB_0054d9c0;
      } while (((uint)param_2 & 3) != 0);
      uVar3 = param_3 >> 2;
    }
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      uVar2 = *param_2;
      uVar4 = *param_2;
      param_2 = param_2 + 1;
      if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar4 == '\0') {
LAB_0054d9ca:
          *(byte *)puVar6 = (byte)uVar4;
          return param_1;
        }
        if ((char)(uVar4 >> 8) == '\0') {
          *(short *)puVar6 = (short)uVar4;
          return param_1;
        }
        if ((uVar4 & 0xff0000) == 0) {
          *(short *)puVar6 = (short)uVar4;
          *(byte *)((int)puVar6 + 2) = 0;
          return param_1;
        }
        if ((uVar4 & 0xff000000) == 0) {
          *puVar6 = uVar4;
          return param_1;
        }
      }
      *puVar6 = uVar4;
      puVar6 = puVar6 + 1;
    }
    for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
      uVar4 = *param_2;
      param_2 = (uint *)((int)param_2 + 1);
      *(byte *)puVar6 = (byte)uVar4;
      puVar6 = (uint *)((int)puVar6 + 1);
      if ((byte)uVar4 == 0) {
        return param_1;
      }
    }
LAB_0054d9c0:
    *(byte *)puVar6 = (byte)param_3;
  }
  return param_1;
}

// --------------------------------------------------

// Function: ctime
// Address: 0054da40
/* ctime */

undefined4 __cdecl ctime(undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = localtime(param_1);
  if (iVar1 != 0) {
    uVar2 = asctime(iVar1);
    return uVar2;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054da5e
// Address: 0054da5e
uint * FUN_0054da5e(uint *param_1,byte param_2,uint param_3)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_3 == 0) {
    return param_1;
  }
  uVar1 = (uint)param_2;
  puVar4 = param_1;
  if (3 < param_3) {
    uVar2 = -(int)param_1 & 3;
    uVar3 = param_3;
    if (uVar2 != 0) {
      uVar3 = param_3 - uVar2;
      do {
        *(byte *)puVar4 = param_2;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    param_3 = uVar3 & 3;
    uVar3 = uVar3 >> 2;
    if (uVar3 != 0) {
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (param_3 == 0) {
        return param_1;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    param_3 = param_3 - 1;
  } while (param_3 != 0);
  return param_1;
}

// --------------------------------------------------

// Function: memset
// Address: 0054da60
/* memset */

uint * __cdecl memset(uint *param_1,byte param_2,uint param_3)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_3 == 0) {
    return param_1;
  }
  uVar1 = (uint)param_2;
  puVar4 = param_1;
  if (3 < param_3) {
    uVar2 = -(int)param_1 & 3;
    uVar3 = param_3;
    if (uVar2 != 0) {
      uVar3 = param_3 - uVar2;
      do {
        *(byte *)puVar4 = param_2;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    param_3 = uVar3 & 3;
    uVar3 = uVar3 >> 2;
    if (uVar3 != 0) {
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (param_3 == 0) {
        return param_1;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    param_3 = param_3 - 1;
  } while (param_3 != 0);
  return param_1;
}

// --------------------------------------------------

// Function: memcpy
// Address: 0054dac0
/* memcpy */

undefined4 * __cdecl memcpy(undefined4 *param_1,undefined4 *param_2,uint param_3)
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
          goto switchD_0054dc77_caseD_2;
        case 3:
          goto switchD_0054dc77_caseD_3;
        }
        goto switchD_0054dc77_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_0054dc77_caseD_0;
      case 1:
        goto switchD_0054dc77_caseD_1;
      case 2:
        goto switchD_0054dc77_caseD_2;
      case 3:
        goto switchD_0054dc77_caseD_3;
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
              goto switchD_0054dc77_caseD_2;
            case 3:
              goto switchD_0054dc77_caseD_3;
            }
            goto switchD_0054dc77_caseD_1;
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
              goto switchD_0054dc77_caseD_2;
            case 3:
              goto switchD_0054dc77_caseD_3;
            }
            goto switchD_0054dc77_caseD_1;
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
              goto switchD_0054dc77_caseD_2;
            case 3:
              goto switchD_0054dc77_caseD_3;
            }
            goto switchD_0054dc77_caseD_1;
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
switchD_0054dc77_caseD_1:
      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
      return param_1;
    case 2:
switchD_0054dc77_caseD_2:
      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
      *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
      return param_1;
    case 3:
switchD_0054dc77_caseD_3:
      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);
      *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
      *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);
      return param_1;
    }
switchD_0054dc77_caseD_0:
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
        goto switchD_0054daf5_caseD_2;
      case 3:
        goto switchD_0054daf5_caseD_3;
      }
      goto switchD_0054daf5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_0054daf5_caseD_0;
    case 1:
      goto switchD_0054daf5_caseD_1;
    case 2:
      goto switchD_0054daf5_caseD_2;
    case 3:
      goto switchD_0054daf5_caseD_3;
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
            goto switchD_0054daf5_caseD_2;
          case 3:
            goto switchD_0054daf5_caseD_3;
          }
          goto switchD_0054daf5_caseD_1;
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
            goto switchD_0054daf5_caseD_2;
          case 3:
            goto switchD_0054daf5_caseD_3;
          }
          goto switchD_0054daf5_caseD_1;
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
            goto switchD_0054daf5_caseD_2;
          case 3:
            goto switchD_0054daf5_caseD_3;
          }
          goto switchD_0054daf5_caseD_1;
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
switchD_0054daf5_caseD_1:
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_0054daf5_caseD_2:
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_0054daf5_caseD_3:
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_0054daf5_caseD_0:
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0054db1b
// Address: 0054db1b
void __fastcall FUN_0054db1b(int param_1)
{
                    /* WARNING: Could not recover jumptable at 0x0054db1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&switchD_0054db1c::switchdataD_0054db9c)[param_1])();
  return;
}

// --------------------------------------------------

// Function: FUN_0054db23
// Address: 0054db23
/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_0054db23(int param_1,int param_2)
{
  uint *puVar1;
  undefined1 *puVar2;
  int in_EAX;
  uint unaff_EBX;
  
  puVar2 = (undefined1 *)((unaff_EBX >> 8) * 0x900 + 0x54);
  *puVar2 = *puVar2;
  *(char *)(in_EAX + 0x230054db) = *(char *)(in_EAX + 0x230054db) + (char)in_EAX;
  puVar1 = (uint *)(param_2 + -0x75f877fa);
  *puVar1 = *puVar1 >> 1 | (uint)((*puVar1 & 1) != 0) << 0x1f;
  *(int *)(in_EAX + 0x468a0147) = *(int *)(in_EAX + 0x468a0147) + param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_0054db59
// Address: 0054db59
void __fastcall FUN_0054db59(uint param_1,uint param_2)
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
                    /* WARNING: Could not recover jumptable at 0x0054dbff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0054daf5::switchdataD_0054dc08)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x0054db78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0054daf5::switchdataD_0054dc08)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_0054db7f
// Address: 0054db7f
void __fastcall FUN_0054db7f(uint param_1,uint param_2)
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
                    /* WARNING: Could not recover jumptable at 0x0054dbff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0054daf5::switchdataD_0054dc08)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x0054db92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0054daf5::switchdataD_0054dc08)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_0054db99
// Address: 0054db99
/* WARNING: Control flow encountered bad instruction data */

void FUN_0054db99(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_0054dc06
// Address: 0054dc06
void FUN_0054dc06(void)
{
  undefined4 in_EAX;
  char *pcVar1;
  byte unaff_BL;
  int unaff_ESI;
  char in_CF;
  char cVar2;
  
  cVar2 = ((char)((uint)in_EAX >> 8) - unaff_BL) - in_CF;
  pcVar1 = (char *)CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(cVar2,(char)in_EAX));
  *pcVar1 = *pcVar1 + cVar2;
  *(byte *)(unaff_ESI + 0x5f) = *(byte *)(unaff_ESI + 0x5f) | unaff_BL;
  return;
}

// --------------------------------------------------

// Function: FUN_0054dc1f
// Address: 0054dc1f
undefined4 FUN_0054dc1f(void)
{
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI;
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0054dc2b
// Address: 0054dc2b
undefined4 FUN_0054dc2b(void)
{
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI;
  unaff_EDI[1] = unaff_ESI[1];
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0054dc3d
// Address: 0054dc3d
undefined4 FUN_0054dc3d(void)
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

// Function: FUN_0054dc57
// Address: 0054dc57
/* WARNING (jumptable): Stack frame is not setup normally: Input value of stackpointer is not used
    */

undefined4 __fastcall FUN_0054dc57(uint param_1,uint param_2)
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
        goto switchD_0054dc77_caseD_1;
      case 2:
        goto switchD_0054dc77_caseD_2;
      case 3:
        goto switchD_0054dc77_caseD_3;
      }
      goto switchD_0054dc77_caseD_0;
    }
  }
  else {
    switch(param_1) {
    case 0:
      goto switchD_0054dc77_caseD_0;
    case 1:
      goto switchD_0054dc77_caseD_1;
    case 2:
      goto switchD_0054dc77_caseD_2;
    case 3:
      goto switchD_0054dc77_caseD_3;
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
            goto switchD_0054dc77_caseD_1;
          case 2:
            goto switchD_0054dc77_caseD_2;
          case 3:
            goto switchD_0054dc77_caseD_3;
          }
          goto switchD_0054dc77_caseD_0;
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
            goto switchD_0054dc77_caseD_1;
          case 2:
            goto switchD_0054dc77_caseD_2;
          case 3:
            goto switchD_0054dc77_caseD_3;
          }
          goto switchD_0054dc77_caseD_0;
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
            goto switchD_0054dc77_caseD_1;
          case 2:
            goto switchD_0054dc77_caseD_2;
          case 3:
            goto switchD_0054dc77_caseD_3;
          }
          goto switchD_0054dc77_caseD_0;
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
switchD_0054dc77_caseD_1:
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
    return *(undefined4 *)(unaff_EBP + 8);
  case 2:
switchD_0054dc77_caseD_2:
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar1 + 2);
    return *(undefined4 *)(unaff_EBP + 8);
  case 3:
switchD_0054dc77_caseD_3:
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar1 + 2);
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)puVar1 + 1);
    return *(undefined4 *)(unaff_EBP + 8);
  }
switchD_0054dc77_caseD_0:
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0054dc7e
// Address: 0054dc7e
void __fastcall FUN_0054dc7e(int param_1)
{
                    /* WARNING: Could not recover jumptable at 0x0054dc82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_caseD_0_0054dd50)[-param_1])();
  return;
}

// --------------------------------------------------

// Function: FUN_0054dc89
// Address: 0054dc89
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Stack frame is not setup normally: Input value of stackpointer is not used
    */

undefined4 __fastcall FUN_0054dc89(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  switch(param_1) {
  case 0:
    goto switchD_0054dc77_caseD_0;
  case 1:
switchD_0054dc77_caseD_1:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    return *(undefined4 *)(unaff_EBP + 8);
  case 2:
switchD_0054dc77_caseD_2:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    return *(undefined4 *)(unaff_EBP + 8);
  case 3:
switchD_0054dc77_caseD_3:
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
LAB_0054dc80:
                    /* WARNING: Could not recover jumptable at 0x0054dc82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*(code *)(&PTR_caseD_0_0054dd50)[-(uVar2 >> 2)])();
        return uVar1;
      }
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(uVar2 & 3) {
      case 1:
        goto switchD_0054dc77_caseD_1;
      case 2:
        goto switchD_0054dc77_caseD_2;
      case 3:
        goto switchD_0054dc77_caseD_3;
      }
      break;
    case 2:
      *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
      uVar3 = uVar2 >> 2;
      *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
      unaff_ESI = (undefined4 *)((int)unaff_ESI + -2);
      unaff_EDI = (undefined4 *)((int)unaff_EDI + -2);
      if (uVar3 < 8) goto LAB_0054dc80;
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(uVar2 & 3) {
      case 1:
        goto switchD_0054dc77_caseD_1;
      case 2:
        goto switchD_0054dc77_caseD_2;
      case 3:
        goto switchD_0054dc77_caseD_3;
      }
      break;
    case 3:
      *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
      *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
      uVar3 = uVar2 >> 2;
      *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
      unaff_ESI = (undefined4 *)((int)unaff_ESI + -3);
      unaff_EDI = (undefined4 *)((int)unaff_EDI + -3);
      if (uVar3 < 8) goto LAB_0054dc80;
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(uVar2 & 3) {
      case 1:
        goto switchD_0054dc77_caseD_1;
      case 2:
        goto switchD_0054dc77_caseD_2;
      case 3:
        goto switchD_0054dc77_caseD_3;
      }
    }
switchD_0054dc77_caseD_0:
    return *(undefined4 *)(unaff_EBP + 8);
  }
}

// --------------------------------------------------

// Function: FUN_0054dcab
// Address: 0054dcab
/* WARNING: Control flow encountered bad instruction data */

void FUN_0054dcab(void)
{
  float10 in_ST0;
  
  dRamb000a942 = (double)in_ST0;
  uRam994e5823 = uRam994e5823 >> 1 | (uint)((uRam994e5823 & 1) != 0) << 0x1f;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_0054dcd5
// Address: 0054dcd5
void __fastcall FUN_0054dcd5(uint param_1,uint param_2)
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
                    /* WARNING: Could not recover jumptable at 0x0054dd97. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0054dc77::switchdataD_0054dda0)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + -1;
      puVar3 = puVar3 + -1;
    }
                    /* WARNING: Could not recover jumptable at 0x0054dcf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0054dc77::switchdataD_0054dda0)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_0054dcff
// Address: 0054dcff
void __fastcall FUN_0054dcff(uint param_1,uint param_2)
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
                    /* WARNING: Could not recover jumptable at 0x0054dd97. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0054dc77::switchdataD_0054dda0)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + -1;
      puVar3 = puVar3 + -1;
    }
                    /* WARNING: Could not recover jumptable at 0x0054dd2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0054dc77::switchdataD_0054dda0)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_0054dd31
// Address: 0054dd31
/* WARNING: Control flow encountered bad instruction data */

void FUN_0054dd31(void)
{
  int in_EAX;
  float10 in_ST0;
  
  *(double *)(in_EAX * 2 + 0x5c) = (double)in_ST0;
  *(double *)(in_EAX * 2 + 100) = (double)in_ST0;
  *(double *)(in_EAX * 2 + 0x6c) = (double)in_ST0;
  *(double *)(in_EAX * 2 + 0x74) = (double)in_ST0;
  *(double *)(in_EAX * 2 + 0x7c) = (double)in_ST0;
  *(double *)(in_EAX * 2 + -0x7c) = (double)in_ST0;
  *(double *)(in_EAX * 2 + -0x69) = (double)in_ST0;
  *(double *)(in_EAX * 2 + -0x75) = (double)in_ST0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_0054dd9e
// Address: 0054dd9e
void FUN_0054dd9e(void)
{
  undefined4 in_EAX;
  int iVar1;
  byte unaff_BL;
  char unaff_BH;
  int unaff_ESI;
  float10 in_ST0;
  
  iVar1 = CONCAT31((int3)((uint)in_EAX >> 8),0xdd);
  *(char *)(iVar1 + -0x37ffab23) = *(char *)(iVar1 + -0x37ffab23) + unaff_BH;
  *(double *)(iVar1 * 2 + -0x24) = (double)in_ST0;
  *(double *)(iVar1 * 2 + -0x75) = (double)in_ST0;
  *(byte *)(unaff_ESI + 0x5f) = *(byte *)(unaff_ESI + 0x5f) | unaff_BL;
  return;
}

// --------------------------------------------------

// Function: FUN_0054ddb7
// Address: 0054ddb7
undefined4 FUN_0054ddb7(void)
{
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 3) = *(undefined1 *)(unaff_ESI + 3);
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0054ddc5
// Address: 0054ddc5
undefined4 FUN_0054ddc5(void)
{
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 3) = *(undefined1 *)(unaff_ESI + 3);
  *(undefined1 *)(unaff_EDI + 2) = *(undefined1 *)(unaff_ESI + 2);
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0054dddb
// Address: 0054dddb
undefined4 FUN_0054dddb(void)
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

// Function: strtok
// Address: 0054de00
/* strtok */

uint __cdecl strtok(byte *param_1,byte *param_2)
{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte local_20 [32];
  
  pbVar4 = local_20;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    pbVar4[0] = 0;
    pbVar4[1] = 0;
    pbVar4[2] = 0;
    pbVar4[3] = 0;
    pbVar4 = pbVar4 + 4;
  }
  do {
    bVar1 = *param_2;
    param_2 = param_2 + 1;
    local_20[bVar1 >> 3] = local_20[bVar1 >> 3] | '\x01' << (bVar1 & 7);
  } while (bVar1 != 0);
  if (param_1 == (byte *)0x0) {
    param_1 = DAT_00887ff0;
  }
  bVar1 = *param_1;
  bVar2 = local_20[bVar1 >> 3] & (byte)(1 << (bVar1 & 7));
  while ((bVar2 != 0 && (bVar1 != 0))) {
    bVar1 = param_1[1];
    param_1 = param_1 + 1;
    bVar2 = local_20[bVar1 >> 3] & (byte)(1 << (bVar1 & 7));
  }
  bVar1 = *param_1;
  DAT_00887ff0 = param_1;
  do {
    if (bVar1 == 0) {
LAB_0054dec7:
      return -(uint)(param_1 != DAT_00887ff0) & (uint)param_1;
    }
    if ((local_20[bVar1 >> 3] & (byte)(1 << (bVar1 & 7))) != 0) {
      *DAT_00887ff0 = 0;
      DAT_00887ff0 = DAT_00887ff0 + 1;
      goto LAB_0054dec7;
    }
    bVar1 = DAT_00887ff0[1];
    DAT_00887ff0 = DAT_00887ff0 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0054dedf
// Address: 0054dedf
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0054dedf(void)
{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &stack0x00000004;
  if (0xfff < in_EAX) {
    do {
      puVar1 = puVar1 + -0x1000;
      in_EAX = in_EAX - 0x1000;
    } while (0xfff < in_EAX);
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}

// --------------------------------------------------

// Function: __alloca_probe
// Address: 0054dee0
/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */

void __alloca_probe(void)
{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &stack0x00000004;
  if (0xfff < in_EAX) {
    do {
      puVar1 = puVar1 + -0x1000;
      in_EAX = in_EAX - 0x1000;
    } while (0xfff < in_EAX);
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}

// --------------------------------------------------

// Function: isupper
// Address: 0054df40
/* isupper */

uint __cdecl isupper(int param_1)
{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,1);
    return uVar1;
  }
  return (byte)__pctype[param_1 * 2] & 1;
}

// --------------------------------------------------

// Function: FUN_0054df6a
// Address: 0054df6a
uint FUN_0054df6a(int param_1)
{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,2);
    return uVar1;
  }
  return (byte)__pctype[param_1 * 2] & 2;
}

// --------------------------------------------------

// Function: FUN_0054df9a
// Address: 0054df9a
uint FUN_0054df9a(int param_1)
{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,4);
    return uVar1;
  }
  return (byte)__pctype[param_1 * 2] & 4;
}

// --------------------------------------------------

// Function: FUN_0054dfca
// Address: 0054dfca
uint FUN_0054dfca(int param_1)
{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
                    /* language.dll match for 0x80: "Arial" */
    uVar1 = __isctype(param_1,0x80);
    return uVar1;
  }
  return (byte)__pctype[param_1 * 2] & 0x80;
}

// --------------------------------------------------

// Function: FUN_0054dfff
// Address: 0054dfff
uint FUN_0054dfff(int param_1)
{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,8);
    return uVar1;
  }
  return (byte)__pctype[param_1 * 2] & 8;
}

// --------------------------------------------------

// Function: isspace
// Address: 0054e000
/* isspace */

uint __cdecl isspace(int param_1)
{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,8);
    return uVar1;
  }
  return (byte)__pctype[param_1 * 2] & 8;
}

// --------------------------------------------------

// Function: FUN_0054e02a
// Address: 0054e02a
uint FUN_0054e02a(int param_1)
{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,0x10);
    return uVar1;
  }
  return (byte)__pctype[param_1 * 2] & 0x10;
}

// --------------------------------------------------

// Function: FUN_0054e05a
// Address: 0054e05a
uint FUN_0054e05a(int param_1)
{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,0x107);
    return uVar1;
  }
  return *(ushort *)(__pctype + param_1 * 2) & 0x107;
}

// --------------------------------------------------

// Function: _isprint
// Address: 0054e090
uint _isprint(int param_1)
{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,0x157);
    return uVar1;
  }
  return *(ushort *)(__pctype + param_1 * 2) & 0x157;
}

// --------------------------------------------------

// Function: _isgraph
// Address: 0054e0c0
uint _isgraph(int param_1)
{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,0x117);
    return uVar1;
  }
  return *(ushort *)(__pctype + param_1 * 2) & 0x117;
}

// --------------------------------------------------

// Function: _iscntrl
// Address: 0054e0f0
uint _iscntrl(int param_1)
{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,0x20);
    return uVar1;
  }
  return (byte)__pctype[param_1 * 2] & 0x20;
}

// --------------------------------------------------

// Function: FUN_0054e11a
// Address: 0054e11a
bool FUN_0054e11a(uint param_1)
{
  return param_1 < 0x80;
}

// --------------------------------------------------

// Function: FUN_0054e12d
// Address: 0054e12d
uint FUN_0054e12d(uint param_1)
{
  return param_1 & 0x7f;
}

// --------------------------------------------------

// Function: FUN_0054e138
// Address: 0054e138
undefined4 FUN_0054e138(int param_1)
{
  uint uVar1;
  
  if (___mb_cur_max < 2) {
    uVar1 = *(ushort *)(__pctype + param_1 * 2) & 0x103;
  }
  else {
    uVar1 = __isctype(param_1,0x103);
  }
  if ((uVar1 == 0) && (param_1 != 0x5f)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0054e183
// Address: 0054e183
undefined4 FUN_0054e183(int param_1)
{
  uint uVar1;
  
  if (___mb_cur_max < 2) {
    uVar1 = *(ushort *)(__pctype + param_1 * 2) & 0x107;
  }
  else {
    uVar1 = __isctype(param_1,0x107);
  }
  if ((uVar1 == 0) && (param_1 != 0x5f)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0054e1d3
// Address: 0054e1d3
float10 FUN_0054e1d3(byte *param_1)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  while( true ) {
    if (___mb_cur_max < 2) {
      uVar2 = (byte)__pctype[(uint)*param_1 * 2] & 8;
    }
    else {
      uVar2 = __isctype(*param_1,8);
    }
    if (uVar2 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar2 = 0xffffffff;
  pbVar4 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar1 != 0);
  iVar3 = __fltin(param_1,~uVar2 - 1,0,0);
  return (float10)*(double *)(iVar3 + 0x10);
}

// --------------------------------------------------

// Function: atof
// Address: 0054e1e0
/* atof */

float10 __cdecl atof(byte *param_1)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  while( true ) {
    if (___mb_cur_max < 2) {
      uVar2 = (byte)__pctype[(uint)*param_1 * 2] & 8;
    }
    else {
      uVar2 = __isctype(*param_1,8);
    }
    if (uVar2 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar2 = 0xffffffff;
  pbVar4 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar1 != 0);
  iVar3 = __fltin(param_1,~uVar2 - 1,0,0);
  return (float10)*(double *)(iVar3 + 0x10);
}

// --------------------------------------------------

// Function: FUN_0054e237
// Address: 0054e237
int FUN_0054e237(int param_1)
{
  return param_1 + -0x20;
}

// --------------------------------------------------

// Function: FUN_0054e248
// Address: 0054e248
uint FUN_0054e248(uint param_1)
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint auStack_8 [2];
  
  uVar1 = param_1;
  if (DAT_008882c0 == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      return param_1 - 0x20;
    }
  }
  else {
    if ((int)param_1 < 0x100) {
      if (___mb_cur_max < 2) {
        uVar2 = (byte)__pctype[param_1 * 2] & 2;
      }
      else {
        uVar2 = __isctype(param_1,2);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    uVar2 = param_1;
    if ((__pctype[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1._0_2_ = (ushort)(byte)uVar1;
      uVar3 = 1;
    }
    else {
      param_1._0_2_ = CONCAT11((byte)uVar1,(char)(uVar1 >> 8));
      param_1._3_1_ = SUB41(uVar2,3);
      param_1._0_3_ = (uint3)(ushort)param_1;
      uVar3 = 2;
    }
    iVar4 = ___crtLCMapStringA(DAT_008882c0,0x200,&param_1,uVar3,auStack_8,3,0);
    if (iVar4 == 0) {
      return uVar1;
    }
    if (iVar4 == 1) {
      return auStack_8[0] & 0xff;
    }
    param_1 = (auStack_8[0] >> 8 & 0xff) << 8 | auStack_8[0] & 0xff;
  }
  return param_1;
}

// --------------------------------------------------

// Function: toupper
// Address: 0054e250
/* toupper */

uint __cdecl toupper(uint param_1)
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_8 [2];
  
  uVar1 = param_1;
  if (DAT_008882c0 == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      return param_1 - 0x20;
    }
  }
  else {
    if ((int)param_1 < 0x100) {
      if (___mb_cur_max < 2) {
        uVar2 = (byte)__pctype[param_1 * 2] & 2;
      }
      else {
        uVar2 = __isctype(param_1,2);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    uVar2 = param_1;
    if ((__pctype[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1._0_2_ = (ushort)(byte)uVar1;
      uVar3 = 1;
    }
    else {
      param_1._0_2_ = CONCAT11((byte)uVar1,(char)(uVar1 >> 8));
      param_1._3_1_ = SUB41(uVar2,3);
      param_1._0_3_ = (uint3)(ushort)param_1;
      uVar3 = 2;
    }
    iVar4 = ___crtLCMapStringA(DAT_008882c0,0x200,&param_1,uVar3,local_8,3,0);
    if (iVar4 == 0) {
      return uVar1;
    }
    if (iVar4 == 1) {
      return local_8[0] & 0xff;
    }
    param_1 = (local_8[0] >> 8 & 0xff) << 8 | local_8[0] & 0xff;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0054e34c
// Address: 0054e34c
int FUN_0054e34c(int param_1)
{
  return param_1 + 0x20;
}

// --------------------------------------------------

// Function: FUN_0054e358
// Address: 0054e358
uint FUN_0054e358(uint param_1)
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint auStack_8 [2];
  
  uVar1 = param_1;
  if (DAT_008882c0 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    if ((int)param_1 < 0x100) {
      if (___mb_cur_max < 2) {
        uVar2 = (byte)__pctype[param_1 * 2] & 1;
      }
      else {
        uVar2 = __isctype(param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    uVar2 = param_1;
    if ((__pctype[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1._0_2_ = (ushort)(byte)uVar1;
      uVar3 = 1;
    }
    else {
      param_1._0_2_ = CONCAT11((byte)uVar1,(char)(uVar1 >> 8));
      param_1._3_1_ = SUB41(uVar2,3);
      param_1._0_3_ = (uint3)(ushort)param_1;
      uVar3 = 2;
    }
    iVar4 = ___crtLCMapStringA(DAT_008882c0,0x100,&param_1,uVar3,auStack_8,3,0);
    if (iVar4 == 0) {
      return uVar1;
    }
    if (iVar4 == 1) {
      return auStack_8[0] & 0xff;
    }
    param_1 = (auStack_8[0] >> 8 & 0xff) << 8 | auStack_8[0] & 0xff;
  }
  return param_1;
}

// --------------------------------------------------

// Function: tolower
// Address: 0054e360
/* tolower */

uint __cdecl tolower(uint param_1)
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_8 [2];
  
  uVar1 = param_1;
  if (DAT_008882c0 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    if ((int)param_1 < 0x100) {
      if (___mb_cur_max < 2) {
        uVar2 = (byte)__pctype[param_1 * 2] & 1;
      }
      else {
        uVar2 = __isctype(param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    uVar2 = param_1;
    if ((__pctype[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1._0_2_ = (ushort)(byte)uVar1;
      uVar3 = 1;
    }
    else {
      param_1._0_2_ = CONCAT11((byte)uVar1,(char)(uVar1 >> 8));
      param_1._3_1_ = SUB41(uVar2,3);
      param_1._0_3_ = (uint3)(ushort)param_1;
      uVar3 = 2;
    }
    iVar4 = ___crtLCMapStringA(DAT_008882c0,0x100,&param_1,uVar3,local_8,3,0);
    if (iVar4 == 0) {
      return uVar1;
    }
    if (iVar4 == 1) {
      return local_8[0] & 0xff;
    }
    param_1 = (local_8[0] >> 8 & 0xff) << 8 | local_8[0] & 0xff;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0054e45c
// Address: 0054e45c
int FUN_0054e45c(void)
{
  int iVar1;
  int iVar2;
  undefined1 auStack_104 [260];
  
  iVar2 = 0;
  iVar1 = GetCurrentDirectoryA(0x104);
  if ((iVar1 != 0) && ((char)((uint)auStack_104 >> 8) == ':')) {
    iVar2 = toupper((uint)auStack_104 & 0xff);
    iVar2 = iVar2 + -0x40;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: __getdrive
// Address: 0054e460
int __getdrive(void)
{
  int iVar1;
  int iVar2;
  undefined1 local_104 [260];
  
  iVar2 = 0;
  iVar1 = GetCurrentDirectoryA(0x104);
  if ((iVar1 != 0) && ((char)((uint)local_104 >> 8) == ':')) {
    iVar2 = toupper((uint)local_104 & 0xff);
    iVar2 = iVar2 + -0x40;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0054e4a3
// Address: 0054e4a3
undefined4 FUN_0054e4a3(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1;
  if ((0 < param_1) && (param_1 < 0x20)) {
    param_1 = CONCAT31(0x3a,(char)param_1 + '@');
    uVar2 = param_1;
    param_1._3_1_ = SUB41(iVar1,3);
    param_1._0_3_ = (uint3)(ushort)uVar2;
    iVar1 = SetCurrentDirectoryA(&param_1);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = GetLastError();
    __dosmaperr(uVar2);
    return 0xffffffff;
  }
  _errno = 0xd;
  __doserrno = 0xf;
  return 0xffffffff;
}

// --------------------------------------------------

// Function: __chdrive
// Address: 0054e4b0
undefined4 __chdrive(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1;
  if ((0 < param_1) && (param_1 < 0x20)) {
    param_1 = CONCAT31(0x3a,(char)param_1 + '@');
    uVar2 = param_1;
    param_1._3_1_ = SUB41(iVar1,3);
    param_1._0_3_ = (uint3)(ushort)uVar2;
    iVar1 = SetCurrentDirectoryA(&param_1);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = GetLastError();
    __dosmaperr(uVar2);
    return 0xffffffff;
  }
  _errno = 0xd;
  __doserrno = 0xf;
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0054e50b
// Address: 0054e50b
undefined4 FUN_0054e50b(uint param_1)
{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_110;
  uint auStack_10c [67];
  
  uStack_110 = param_1;
  iVar3 = SetCurrentDirectoryA();
  if (iVar3 != 0) {
    iVar3 = GetCurrentDirectoryA(0x105,auStack_10c);
    if (iVar3 != 0) {
      cVar1 = (char)auStack_10c[0];
      if (((cVar1 == '\\') || (cVar1 == '/')) && (cVar1 == (char)(auStack_10c[0] >> 8))) {
        return 0;
      }
      uStack_110 = CONCAT31(uStack_110._1_3_,0x3d);
      uVar2 = __mbctoupper(auStack_10c[0] & 0xff);
      uStack_110 = (uint)CONCAT12(0x3a,CONCAT11(uVar2,(undefined1)uStack_110));
      iVar3 = SetEnvironmentVariableA(&uStack_110,auStack_10c);
      if (iVar3 != 0) {
        return 0;
      }
    }
  }
  uVar4 = GetLastError();
  __dosmaperr(uVar4);
  return 0xffffffff;
}

// --------------------------------------------------

// Function: __chdir
// Address: 0054e510
undefined4 __chdir(uint param_1)
{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_110;
  uint auStack_10c [67];
  
  uStack_110 = param_1;
  iVar3 = SetCurrentDirectoryA();
  if (iVar3 != 0) {
    iVar3 = GetCurrentDirectoryA(0x105,auStack_10c);
    if (iVar3 != 0) {
      cVar1 = (char)auStack_10c[0];
      if (((cVar1 == '\\') || (cVar1 == '/')) && (cVar1 == (char)(auStack_10c[0] >> 8))) {
        return 0;
      }
      uStack_110 = CONCAT31(uStack_110._1_3_,0x3d);
      uVar2 = __mbctoupper(auStack_10c[0] & 0xff);
      uStack_110 = (uint)CONCAT12(0x3a,CONCAT11(uVar2,(undefined1)uStack_110));
      iVar3 = SetEnvironmentVariableA(&uStack_110,auStack_10c);
      if (iVar3 != 0) {
        return 0;
      }
    }
  }
  uVar4 = GetLastError();
  __dosmaperr(uVar4);
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0054e5a9
// Address: 0054e5a9
void FUN_0054e5a9(byte *param_1,byte *param_2,undefined1 *param_3,int param_4,undefined1 *param_5)
{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbStack_4;
  
  iVar4 = -1;
  pbVar5 = param_1;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar2 = *pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar2 != 0);
  pbStack_4 = (byte *)0x0;
  if ((iVar4 == -2) || (param_1[1] != 0x3a)) {
    if (param_2 != (undefined1 *)0x0) {
      *param_2 = 0;
    }
  }
  else {
    if (param_2 != (undefined1 *)0x0) {
      __mbsnbcpy(param_2,param_1,2);
      param_2[2] = 0;
    }
    param_1 = param_1 + 2;
  }
  bVar2 = *param_1;
  param_2 = (byte *)0x0;
  pbVar5 = param_1;
  while (bVar2 != 0) {
    bVar2 = *pbVar5;
    if ((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) == 0) {
      if ((bVar2 == 0x2f) || (bVar2 == 0x5c)) {
        param_2 = pbVar5 + 1;
      }
      else if (bVar2 == 0x2e) {
        pbStack_4 = pbVar5;
      }
    }
    else {
      pbVar5 = pbVar5 + 1;
    }
    pbVar1 = pbVar5 + 1;
    pbVar5 = pbVar5 + 1;
    bVar2 = *pbVar1;
  }
  if (param_2 == (byte *)0x0) {
    param_2 = param_1;
    if (param_3 != (undefined1 *)0x0) {
      *param_3 = 0;
    }
  }
  else if (param_3 != (undefined1 *)0x0) {
    uVar3 = (int)param_2 - (int)param_1;
    if (0xfe < uVar3) {
      uVar3 = 0xff;
    }
    __mbsnbcpy(param_3,param_1,uVar3);
    param_3[uVar3] = 0;
  }
  if ((pbStack_4 == (byte *)0x0) || (pbStack_4 < param_2)) {
    if (param_4 != 0) {
      uVar3 = (int)pbVar5 - (int)param_2;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      __mbsnbcpy(param_4,param_2,uVar3);
      *(undefined1 *)(uVar3 + param_4) = 0;
    }
    if (param_5 != (undefined1 *)0x0) {
      *param_5 = 0;
    }
  }
  else {
    if (param_4 != 0) {
      uVar3 = (int)pbStack_4 - (int)param_2;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      __mbsnbcpy(param_4,param_2,uVar3);
      *(undefined1 *)(uVar3 + param_4) = 0;
    }
    if (param_5 != (undefined1 *)0x0) {
      uVar3 = (int)pbVar5 - (int)pbStack_4;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      __mbsnbcpy(param_5,pbStack_4,uVar3);
      param_5[uVar3] = 0;
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: __splitpath
// Address: 0054e5b0
void __splitpath(byte *param_1,byte *param_2,undefined1 *param_3,int param_4,undefined1 *param_5)
{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *local_4;
  
  iVar4 = -1;
  pbVar5 = param_1;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar2 = *pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar2 != 0);
  local_4 = (byte *)0x0;
  if ((iVar4 == -2) || (param_1[1] != 0x3a)) {
    if (param_2 != (undefined1 *)0x0) {
      *param_2 = 0;
    }
  }
  else {
    if (param_2 != (undefined1 *)0x0) {
      __mbsnbcpy(param_2,param_1,2);
      param_2[2] = 0;
    }
    param_1 = param_1 + 2;
  }
  bVar2 = *param_1;
  param_2 = (byte *)0x0;
  pbVar5 = param_1;
  while (bVar2 != 0) {
    bVar2 = *pbVar5;
    if ((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) == 0) {
      if ((bVar2 == 0x2f) || (bVar2 == 0x5c)) {
        param_2 = pbVar5 + 1;
      }
      else if (bVar2 == 0x2e) {
        local_4 = pbVar5;
      }
    }
    else {
      pbVar5 = pbVar5 + 1;
    }
    pbVar1 = pbVar5 + 1;
    pbVar5 = pbVar5 + 1;
    bVar2 = *pbVar1;
  }
  if (param_2 == (byte *)0x0) {
    param_2 = param_1;
    if (param_3 != (undefined1 *)0x0) {
      *param_3 = 0;
    }
  }
  else if (param_3 != (undefined1 *)0x0) {
    uVar3 = (int)param_2 - (int)param_1;
    if (0xfe < uVar3) {
      uVar3 = 0xff;
    }
    __mbsnbcpy(param_3,param_1,uVar3);
    param_3[uVar3] = 0;
  }
  if ((local_4 == (byte *)0x0) || (local_4 < param_2)) {
    if (param_4 != 0) {
      uVar3 = (int)pbVar5 - (int)param_2;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      __mbsnbcpy(param_4,param_2,uVar3);
      *(undefined1 *)(uVar3 + param_4) = 0;
    }
    if (param_5 != (undefined1 *)0x0) {
      *param_5 = 0;
    }
  }
  else {
    if (param_4 != 0) {
      uVar3 = (int)local_4 - (int)param_2;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      __mbsnbcpy(param_4,param_2,uVar3);
      *(undefined1 *)(uVar3 + param_4) = 0;
    }
    if (param_5 != (undefined1 *)0x0) {
      uVar3 = (int)pbVar5 - (int)local_4;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      __mbsnbcpy(param_5,local_4,uVar3);
      param_5[uVar3] = 0;
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054e721
// Address: 0054e721
void FUN_0054e721(undefined4 param_1,undefined4 param_2)
{
  __getdcwd(0,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: __getcwd
// Address: 0054e730
void __getcwd(undefined4 param_1,undefined4 param_2)
{
  __getdcwd(0,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0054e745
// Address: 0054e745
char * FUN_0054e745(int param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char acStack_10c [8];
  undefined1 auStack_104 [252];
  char *pcStack_8;
  uint uStack_4;
  
  if (param_1 == 0) {
    iVar2 = GetCurrentDirectoryA(0x104,auStack_104);
  }
  else {
    iVar2 = __validdrive(param_1);
    if (iVar2 == 0) {
      __doserrno = 0xf;
      _errno = 0xd;
      return (char *)0x0;
    }
    acStack_10c[0] = (char)param_1 + '@';
    acStack_10c[1] = 0x3a;
    acStack_10c[2] = 0x2e;
    acStack_10c[3] = 0;
    iVar2 = GetFullPathNameA(acStack_10c,0x104,auStack_104,acStack_10c + 4);
  }
  if ((iVar2 == 0) || (uVar3 = iVar2 + 1, 0x104 < uVar3)) {
    return (char *)0x0;
  }
  if (pcStack_8 == (char *)0x0) {
    if ((int)uVar3 <= (int)uStack_4) {
      uVar3 = uStack_4;
    }
    pcStack_8 = (char *)malloc(uVar3);
    if (pcStack_8 == (char *)0x0) {
      _errno = 0xc;
      return (char *)0x0;
    }
  }
  else if ((int)uStack_4 < (int)uVar3) {
    _errno = 0x22;
    return (char *)0x0;
  }
  uVar3 = 0xffffffff;
  pcVar5 = &stack0xfffffeec;
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
  pcVar6 = pcStack_8;
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
  return pcStack_8;
}

// --------------------------------------------------

// Function: __getdcwd
// Address: 0054e750
char * __getdcwd(int param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char local_10c [8];
  undefined1 local_104 [252];
  char *pcStack_8;
  uint uStack_4;
  
  if (param_1 == 0) {
    iVar2 = GetCurrentDirectoryA(0x104,local_104);
  }
  else {
    iVar2 = __validdrive(param_1);
    if (iVar2 == 0) {
      __doserrno = 0xf;
      _errno = 0xd;
      return (char *)0x0;
    }
    local_10c[0] = (char)param_1 + '@';
    local_10c[1] = 0x3a;
    local_10c[2] = 0x2e;
    local_10c[3] = 0;
    iVar2 = GetFullPathNameA(local_10c,0x104,local_104,local_10c + 4);
  }
  if ((iVar2 == 0) || (uVar3 = iVar2 + 1, 0x104 < uVar3)) {
    return (char *)0x0;
  }
  if (pcStack_8 == (char *)0x0) {
    if ((int)uVar3 <= (int)uStack_4) {
      uVar3 = uStack_4;
    }
    pcStack_8 = (char *)malloc(uVar3);
    if (pcStack_8 == (char *)0x0) {
      _errno = 0xc;
      return (char *)0x0;
    }
  }
  else if ((int)uStack_4 < (int)uVar3) {
    _errno = 0x22;
    return (char *)0x0;
  }
  uVar3 = 0xffffffff;
  pcVar5 = &stack0xfffffeec;
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
  pcVar6 = pcStack_8;
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
  return pcStack_8;
}

// --------------------------------------------------

// Function: FUN_0054e873
// Address: 0054e873
undefined4 FUN_0054e873(uint param_1)
{
  char cVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 1;
  }
  cVar1 = (char)param_1;
  param_1 = (uint)CONCAT12(0x5c,CONCAT11(0x3a,cVar1 + '@'));
  iVar2 = GetDriveTypeA(&param_1);
  if ((iVar2 != 0) && (iVar2 != 1)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: __validdrive
// Address: 0054e880
undefined4 __validdrive(uint param_1)
{
  char cVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 1;
  }
  cVar1 = (char)param_1;
  param_1 = (uint)CONCAT12(0x5c,CONCAT11(0x3a,cVar1 + '@'));
  iVar2 = GetDriveTypeA(&param_1);
  if ((iVar2 != 0) && (iVar2 != 1)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: floor
// Address: 0054e8c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* floor */

float10 __cdecl floor(undefined4 param_1,undefined4 param_2)
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
      fVar4 = (float10)__except1(0x10,0xb,param_1,param_2,dVar1,uVar2);
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
      fVar4 = (float10)__handle_qnan1(0xb,param_1,param_2,uVar2);
      return fVar4;
    }
  }
  fVar4 = (float10)__except1(8,0xb,param_1,param_2,
                             (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) -
                             _DAT_00577a88,uVar2);
  return fVar4;
}

// --------------------------------------------------

// Function: FUN_0054e9b9
// Address: 0054e9b9
int __fastcall FUN_0054e9b9(undefined4 param_1,int param_2)
{
  return param_2 + -1;
}

// --------------------------------------------------

// Function: FUN_0054e9c5
// Address: 0054e9c5
uint * FUN_0054e9c5(uint *param_1,char param_2)
{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar1 = (uint)param_1 & 3;
  while (uVar1 != 0) {
    if ((char)*param_1 == param_2) {
      return param_1;
    }
    if ((char)*param_1 == '\0') {
      return (uint *)0x0;
    }
    uVar1 = (uint)((int)param_1 + 1) & 3;
    param_1 = (uint *)((int)param_1 + 1);
  }
  while( true ) {
    while( true ) {
      uVar1 = *param_1;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = param_1 + 1;
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      param_1 = puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (uint *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (uint *)0x0;
        }
      }
    }
    uVar1 = *param_1;
    if ((char)uVar1 == param_2) {
      return param_1;
    }
    if ((char)uVar1 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 1);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 2);
    }
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 3);
    }
    param_1 = puVar5;
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
  }
  return (uint *)0x0;
}

// --------------------------------------------------

// Function: strchr
// Address: 0054e9d0
/* strchr */

uint * __cdecl strchr(uint *param_1,char param_2)
{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar1 = (uint)param_1 & 3;
  while (uVar1 != 0) {
    if ((char)*param_1 == param_2) {
      return param_1;
    }
    if ((char)*param_1 == '\0') {
      return (uint *)0x0;
    }
    uVar1 = (uint)((int)param_1 + 1) & 3;
    param_1 = (uint *)((int)param_1 + 1);
  }
  while( true ) {
    while( true ) {
      uVar1 = *param_1;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = param_1 + 1;
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      param_1 = puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (uint *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (uint *)0x0;
        }
      }
    }
    uVar1 = *param_1;
    if ((char)uVar1 == param_2) {
      return param_1;
    }
    if ((char)uVar1 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 1);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 2);
    }
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 3);
    }
    param_1 = puVar5;
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
  }
  return (uint *)0x0;
}

// --------------------------------------------------

// Function: __onexit
// Address: 0054ea90
void __onexit(undefined4 param_1)
{
  uint uVar1;
  int iVar2;
  
  uVar1 = __msize(___onexitbegin);
  if (uVar1 < (uint)((int)___onexitend + (4 - ___onexitbegin))) {
    iVar2 = __msize(___onexitbegin);
    iVar2 = realloc(___onexitbegin,iVar2 + 0x10);
    if (iVar2 == 0) {
      return;
    }
    ___onexitend = (undefined4 *)(iVar2 + ((int)___onexitend - ___onexitbegin >> 2) * 4);
    ___onexitbegin = iVar2;
  }
  *___onexitend = param_1;
  ___onexitend = ___onexitend + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0054eb0e
// Address: 0054eb0e
int FUN_0054eb0e(undefined4 param_1)
{
  int iVar1;
  
  iVar1 = __onexit(param_1);
  return (iVar1 != 0) - 1;
}

// --------------------------------------------------

// Function: atexit
// Address: 0054eb10
/* atexit */

int __cdecl atexit(undefined4 param_1)
{
  int iVar1;
  
  iVar1 = __onexit(param_1);
  return (iVar1 != 0) - 1;
}

// --------------------------------------------------

// Function: FUN_0054eb25
// Address: 0054eb25
void FUN_0054eb25(void)
{
                    /* language.dll match for 0x80: "Arial" */
  ___onexitbegin = (undefined4 *)malloc(0x80);
  if (___onexitbegin == (undefined4 *)0x0) {
    __amsg_exit(0x18);
  }
  *___onexitbegin = 0;
  ___onexitend = ___onexitbegin;
  return;
}

// --------------------------------------------------

// Function: FUN_0054eb66
// Address: 0054eb66
char FUN_0054eb66(byte *param_1,byte *param_2)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  
  if (DAT_008882c0 == 0) {
    bVar3 = 0xff;
    do {
      do {
        if (bVar3 == 0) {
          return '\0';
        }
        bVar3 = *param_2;
        param_2 = param_2 + 1;
        bVar2 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar2 == bVar3);
      bVar1 = bVar3 + 0xbf + (-((byte)(bVar3 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar2 = bVar2 + 0xbf;
      bVar3 = bVar2 + (-(bVar2 < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar3 < bVar1;
    } while (bVar3 == bVar1);
  }
  else {
    bVar3 = 0xff;
    do {
      do {
        if (bVar3 == 0) {
          return '\0';
        }
        bVar3 = *param_2;
        param_2 = param_2 + 1;
        bVar2 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar3 == bVar2);
      bVar2 = tolower(bVar2,bVar3);
      bVar3 = tolower();
      bVar4 = bVar2 < bVar3;
    } while (bVar2 == bVar3);
  }
  return bVar4 * -2 + '\x01';
}

// --------------------------------------------------

// Function: stricmp
// Address: 0054eb70
/* stricmp */

char __cdecl stricmp(byte *param_1,byte *param_2)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  
  if (DAT_008882c0 == 0) {
    bVar3 = 0xff;
    do {
      do {
        if (bVar3 == 0) {
          return '\0';
        }
        bVar3 = *param_2;
        param_2 = param_2 + 1;
        bVar2 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar2 == bVar3);
      bVar1 = bVar3 + 0xbf + (-((byte)(bVar3 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar2 = bVar2 + 0xbf;
      bVar3 = bVar2 + (-(bVar2 < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar3 < bVar1;
    } while (bVar3 == bVar1);
  }
  else {
    bVar3 = 0xff;
    do {
      do {
        if (bVar3 == 0) {
          return '\0';
        }
        bVar3 = *param_2;
        param_2 = param_2 + 1;
        bVar2 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar3 == bVar2);
      bVar2 = tolower(bVar2,bVar3);
      bVar3 = tolower();
      bVar4 = bVar2 < bVar3;
    } while (bVar2 == bVar3);
  }
  return bVar4 * -2 + '\x01';
}

// --------------------------------------------------

// Function: __mbschr
// Address: 0054ec00
byte * __mbschr(byte *param_1,uint param_2)
{
  byte *pbVar1;
  uint uVar2;
  
  if (___mbcodepage == 0) {
    pbVar1 = (byte *)strchr(param_1,param_2);
    return pbVar1;
  }
  uVar2 = (uint)(ushort)*param_1;
  if (*param_1 == 0) {
LAB_0054ec97:
    return (byte *)((param_2 != uVar2) - 1 & (uint)param_1);
  }
  do {
    if ((*(byte *)((int)&__mbctype + uVar2 + 1) & 4) == 0) {
      pbVar1 = param_1;
      if (param_2 == uVar2) goto LAB_0054ec97;
    }
    else {
      pbVar1 = param_1 + 1;
      if (param_1[1] == 0) {
        return (byte *)0x0;
      }
      if (param_2 == (uVar2 << 8 | (uint)param_1[1])) {
        return param_1;
      }
    }
    uVar2 = (uint)(ushort)pbVar1[1];
    param_1 = pbVar1 + 1;
    if (pbVar1[1] == 0) {
      return (byte *)((param_2 != 0) - 1 & (uint)param_1);
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0054ecab
// Address: 0054ecab
int FUN_0054ecab(byte *param_1,byte *param_2)
{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  ushort uVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  if (___mbcodepage != 0) {
    while( true ) {
      bVar1 = *param_1;
      uVar4 = (ushort)bVar1;
      pbVar6 = param_1 + 1;
      if ((*(byte *)((int)&__mbctype + bVar1 + 1) & 4) != 0) {
        bVar2 = *pbVar6;
        if (bVar2 == 0) {
          uVar4 = 0;
        }
        else {
          pbVar6 = param_1 + 2;
          uVar4 = CONCAT11(bVar1,bVar2);
        }
      }
      uVar3 = (uint)*param_2;
      pbVar5 = param_2 + 1;
      if ((*(byte *)((int)&__mbctype + uVar3 + 1) & 4) != 0) {
        bVar1 = *pbVar5;
        if (bVar1 == 0) {
          uVar3 = 0;
        }
        else {
          pbVar5 = param_2 + 2;
          uVar3 = (uint)CONCAT11(*param_2,bVar1);
        }
      }
      if ((ushort)uVar3 != uVar4) break;
      param_2 = pbVar5;
      param_1 = pbVar6;
      if (uVar4 == 0) {
        return 0;
      }
    }
    return (-(uint)((ushort)uVar3 < uVar4) & 2) - 1;
  }
  while( true ) {
    bVar1 = *param_1;
    bVar7 = bVar1 < *param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = param_1[1];
    bVar7 = bVar1 < param_2[1];
    if (bVar1 != param_2[1]) break;
    param_1 = param_1 + 2;
    param_2 = param_2 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (1 - (uint)bVar7) - (uint)(bVar7 != 0);
}

// --------------------------------------------------

// Function: __mbscmp
// Address: 0054ecb0
int __mbscmp(byte *param_1,byte *param_2)
{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  ushort uVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  if (___mbcodepage != 0) {
    while( true ) {
      bVar1 = *param_1;
      uVar4 = (ushort)bVar1;
      pbVar6 = param_1 + 1;
      if ((*(byte *)((int)&__mbctype + bVar1 + 1) & 4) != 0) {
        bVar2 = *pbVar6;
        if (bVar2 == 0) {
          uVar4 = 0;
        }
        else {
          pbVar6 = param_1 + 2;
          uVar4 = CONCAT11(bVar1,bVar2);
        }
      }
      uVar3 = (uint)*param_2;
      pbVar5 = param_2 + 1;
      if ((*(byte *)((int)&__mbctype + uVar3 + 1) & 4) != 0) {
        bVar1 = *pbVar5;
        if (bVar1 == 0) {
          uVar3 = 0;
        }
        else {
          pbVar5 = param_2 + 2;
          uVar3 = (uint)CONCAT11(*param_2,bVar1);
        }
      }
      if ((ushort)uVar3 != uVar4) break;
      param_2 = pbVar5;
      param_1 = pbVar6;
      if (uVar4 == 0) {
        return 0;
      }
    }
    return (-(uint)((ushort)uVar3 < uVar4) & 2) - 1;
  }
  while( true ) {
    bVar1 = *param_1;
    bVar7 = bVar1 < *param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = param_1[1];
    bVar7 = bVar1 < param_2[1];
    if (bVar1 != param_2[1]) break;
    param_1 = param_1 + 2;
    param_2 = param_2 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (1 - (uint)bVar7) - (uint)(bVar7 != 0);
}

// --------------------------------------------------

// Function: FUN_0054ed72
// Address: 0054ed72
byte * FUN_0054ed72(byte *param_1)
{
  byte *pbVar1;
  
  pbVar1 = param_1 + 1;
  if ((*(byte *)((int)&__mbctype + *param_1 + 1) & 4) != 0) {
    pbVar1 = param_1 + 2;
  }
  return pbVar1;
}

// --------------------------------------------------

// Function: __mbsinc
// Address: 0054ed80
byte * __mbsinc(byte *param_1)
{
  byte *pbVar1;
  
  pbVar1 = param_1 + 1;
  if ((*(byte *)((int)&__mbctype + *param_1 + 1) & 4) != 0) {
    pbVar1 = param_1 + 2;
  }
  return pbVar1;
}

// --------------------------------------------------

// Function: FUN_0054ed98
// Address: 0054ed98
byte * FUN_0054ed98(byte *param_1,byte *param_2)
{
  byte *pbVar1;
  
  if (param_2 <= param_1) {
    return (byte *)0x0;
  }
  if (___mbcodepage != 0) {
    if ((*(byte *)((int)&__mbctype + param_2[-1] + 1) & 4) == 0) {
      pbVar1 = param_2 + -2;
      while ((param_1 <= pbVar1 && ((*(byte *)((int)&__mbctype + *pbVar1 + 1) & 4) != 0))) {
        pbVar1 = pbVar1 + -1;
      }
      return param_2 + (-1 - ((int)param_2 - (int)pbVar1 & 1U));
    }
    return param_2 + -2;
  }
  return param_2 + -1;
}

// --------------------------------------------------

// Function: __mbsdec
// Address: 0054eda0
byte * __mbsdec(byte *param_1,byte *param_2)
{
  byte *pbVar1;
  
  if (param_2 <= param_1) {
    return (byte *)0x0;
  }
  if (___mbcodepage != 0) {
    if ((*(byte *)((int)&__mbctype + param_2[-1] + 1) & 4) == 0) {
      pbVar1 = param_2 + -2;
      while ((param_1 <= pbVar1 && ((*(byte *)((int)&__mbctype + *pbVar1 + 1) & 4) != 0))) {
        pbVar1 = pbVar1 + -1;
      }
      return param_2 + (-1 - ((int)param_2 - (int)pbVar1 & 1U));
    }
    return param_2 + -2;
  }
  return param_2 + -1;
}

// --------------------------------------------------

// Function: FUN_0054ee05
// Address: 0054ee05
byte * FUN_0054ee05(byte *param_1,byte *param_2,uint param_3)
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
  pbVar3 = param_1;
  pbVar5 = param_1;
  if (param_3 != 0) {
    do {
      bVar1 = *param_2;
      param_3 = param_3 - 1;
      bVar2 = *(byte *)((int)&__mbctype + bVar1 + 1);
      *pbVar5 = bVar1;
      if ((bVar2 & 4) == 0) {
        pbVar3 = pbVar5 + 1;
        param_2 = param_2 + 1;
        if (bVar1 == 0) break;
      }
      else {
        bVar1 = param_2[1];
        pbVar5[1] = bVar1;
        pbVar3 = pbVar5 + 2;
        param_2 = param_2 + 2;
        if (bVar1 == 0) {
          *pbVar5 = 0;
          break;
        }
      }
      pbVar5 = pbVar3;
    } while (param_3 != 0);
  }
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

// Function: __mbsncpy
// Address: 0054ee10
byte * __mbsncpy(byte *param_1,byte *param_2,uint param_3)
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
  pbVar3 = param_1;
  pbVar5 = param_1;
  if (param_3 != 0) {
    do {
      bVar1 = *param_2;
      param_3 = param_3 - 1;
      bVar2 = *(byte *)((int)&__mbctype + bVar1 + 1);
      *pbVar5 = bVar1;
      if ((bVar2 & 4) == 0) {
        pbVar3 = pbVar5 + 1;
        param_2 = param_2 + 1;
        if (bVar1 == 0) break;
      }
      else {
        bVar1 = param_2[1];
        pbVar5[1] = bVar1;
        pbVar3 = pbVar5 + 2;
        param_2 = param_2 + 2;
        if (bVar1 == 0) {
          *pbVar5 = 0;
          break;
        }
      }
      pbVar5 = pbVar3;
    } while (param_3 != 0);
  }
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

// Function: FUN_0054ee9c
// Address: 0054ee9c
int FUN_0054ee9c(byte *param_1)
{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  if (___mbcodepage != 0) {
    iVar3 = 0;
    bVar2 = *param_1;
    for (; (bVar2 != 0 &&
           (((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) == 0 ||
            (pbVar1 = param_1 + 1, param_1 = param_1 + 1, *pbVar1 != 0)))); param_1 = param_1 + 1) {
      bVar2 = param_1[1];
      iVar3 = iVar3 + 1;
    }
    return iVar3;
  }
  uVar4 = 0xffffffff;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    bVar2 = *param_1;
    param_1 = param_1 + 1;
  } while (bVar2 != 0);
  return ~uVar4 - 1;
}

// --------------------------------------------------

// Function: __mbslen
// Address: 0054eea0
int __mbslen(byte *param_1)
{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  if (___mbcodepage != 0) {
    iVar3 = 0;
    bVar2 = *param_1;
    for (; (bVar2 != 0 &&
           (((*(byte *)((int)&__mbctype + bVar2 + 1) & 4) == 0 ||
            (pbVar1 = param_1 + 1, param_1 = param_1 + 1, *pbVar1 != 0)))); param_1 = param_1 + 1) {
      bVar2 = param_1[1];
      iVar3 = iVar3 + 1;
    }
    return iVar3;
  }
  uVar4 = 0xffffffff;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    bVar2 = *param_1;
    param_1 = param_1 + 1;
  } while (bVar2 != 0);
  return ~uVar4 - 1;
}

// --------------------------------------------------

// Function: FUN_0054eeec
// Address: 0054eeec
uint * FUN_0054eeec(uint *param_1,uint *param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = (uint)param_2 & 3;
  puVar4 = param_1;
  while (uVar3 != 0) {
    bVar1 = (byte)*param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_0054efd8;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    uVar3 = (uint)param_2 & 3;
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_0054efd8:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: __mbscpy
// Address: 0054eef0
uint * __mbscpy(uint *param_1,uint *param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = (uint)param_2 & 3;
  puVar4 = param_1;
  while (uVar3 != 0) {
    bVar1 = (byte)*param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_0054efd8;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    uVar3 = (uint)param_2 & 3;
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_0054efd8:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0054eef7
// Address: 0054eef7
uint * FUN_0054eef7(uint *param_1,uint *param_2)
{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = (uint)param_1 & 3;
  puVar3 = param_1;
  while (uVar4 != 0) {
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
    if ((byte)uVar4 == 0) goto LAB_0054ef4f;
    uVar4 = (uint)puVar3 & 3;
  }
  do {
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto LAB_0054ef61;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto LAB_0054ef61;
    }
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto LAB_0054ef61;
    }
  } while ((uVar4 & 0xff000000) != 0);
LAB_0054ef4f:
  puVar5 = (uint *)((int)puVar3 + -1);
LAB_0054ef61:
  uVar4 = (uint)param_2 & 3;
  while (uVar4 != 0) {
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_0054efd8;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
    uVar4 = (uint)param_2 & 3;
  }
  do {
    uVar2 = *param_2;
    uVar4 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar4 == '\0') {
LAB_0054efd8:
        *(byte *)puVar5 = (byte)uVar4;
        return param_1;
      }
      if ((char)(uVar4 >> 8) == '\0') {
        *(short *)puVar5 = (short)uVar4;
        return param_1;
      }
      if ((uVar4 & 0xff0000) == 0) {
        *(short *)puVar5 = (short)uVar4;
        *(byte *)((int)puVar5 + 2) = 0;
        return param_1;
      }
      if ((uVar4 & 0xff000000) == 0) {
        *puVar5 = uVar4;
        return param_1;
      }
    }
    *puVar5 = uVar4;
    puVar5 = puVar5 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: __mbscat
// Address: 0054ef00
uint * __mbscat(uint *param_1,uint *param_2)
{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = (uint)param_1 & 3;
  puVar3 = param_1;
  while (uVar4 != 0) {
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
    if ((byte)uVar4 == 0) goto LAB_0054ef4f;
    uVar4 = (uint)puVar3 & 3;
  }
  do {
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto LAB_0054ef61;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto LAB_0054ef61;
    }
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto LAB_0054ef61;
    }
  } while ((uVar4 & 0xff000000) != 0);
LAB_0054ef4f:
  puVar5 = (uint *)((int)puVar3 + -1);
LAB_0054ef61:
  uVar4 = (uint)param_2 & 3;
  while (uVar4 != 0) {
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_0054efd8;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
    uVar4 = (uint)param_2 & 3;
  }
  do {
    uVar2 = *param_2;
    uVar4 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar4 == '\0') {
LAB_0054efd8:
        *(byte *)puVar5 = (byte)uVar4;
        return param_1;
      }
      if ((char)(uVar4 >> 8) == '\0') {
        *(short *)puVar5 = (short)uVar4;
        return param_1;
      }
      if ((uVar4 & 0xff0000) == 0) {
        *(short *)puVar5 = (short)uVar4;
        *(byte *)((int)puVar5 + 2) = 0;
        return param_1;
      }
      if ((uVar4 & 0xff000000) == 0) {
        *puVar5 = uVar4;
        return param_1;
      }
    }
    *puVar5 = uVar4;
    puVar5 = puVar5 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: strncmp
// Address: 0054efe0
/* strncmp */

uint __cdecl strncmp(char *param_1,char *param_2,uint param_3)
{
  char cVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  
  uVar3 = param_3;
  pcVar5 = param_1;
  if (param_3 != 0) {
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar4 = param_3 - uVar3;
    do {
      pcVar5 = param_2;
      pcVar6 = param_1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar6 = param_1 + 1;
      pcVar5 = param_2 + 1;
      cVar2 = *param_1;
      cVar1 = *param_2;
      param_2 = pcVar5;
      param_1 = pcVar6;
    } while (cVar1 == cVar2);
    param_3 = 0;
    if ((byte)pcVar5[-1] <= (byte)pcVar6[-1]) {
      if (pcVar5[-1] == pcVar6[-1]) {
        return 0;
      }
      param_3 = 0xfffffffe;
    }
    param_3 = ~param_3;
  }
  return param_3;
}

// --------------------------------------------------

// Function: qsort
// Address: 0054f020
/* qsort */

void __cdecl qsort(uint param_1,uint param_2,uint param_3,code *param_4)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint local_100;
  uint *local_fc;
  uint *local_f8;
  int local_f4;
  uint local_f0 [30];
  uint local_78 [30];
  
  if ((param_2 < 2) || (param_3 == 0)) {
    return;
  }
  local_100 = (param_2 - 1) * param_3 + param_1;
  local_fc = local_f0;
  local_f8 = local_78;
  local_f4 = 0;
LAB_0054f074:
  uVar1 = (local_100 - param_1) / param_3 + 1;
  if (8 < uVar1) {
    FUN_0054f230((uVar1 >> 1) * param_3 + param_1,param_1,param_3);
    uVar3 = local_100 + param_3;
    uVar1 = param_1;
LAB_0054f0ee:
    uVar1 = uVar1 + param_3;
    if (uVar1 <= local_100) goto code_r0x0054f0f8;
    goto LAB_0054f108;
  }
  FUN_0054f1d0(param_1,local_100,param_3,param_4);
  goto LAB_0054f095;
code_r0x0054f0f8:
  iVar2 = (*param_4)(uVar1,param_1);
  if (iVar2 < 1) goto LAB_0054f0ee;
LAB_0054f108:
  do {
    uVar3 = uVar3 - param_3;
    if (uVar3 <= param_1) break;
    iVar2 = (*param_4)(uVar3,param_1);
  } while (-1 < iVar2);
  if (uVar1 <= uVar3) {
    FUN_0054f230(uVar1,uVar3,param_3);
    goto LAB_0054f0ee;
  }
  FUN_0054f230(param_1,uVar3,param_3);
  if ((int)((uVar3 - param_1) + -1) < (int)(local_100 - uVar1)) {
    if (uVar1 < local_100) {
      *local_f8 = uVar1;
      *local_fc = local_100;
      local_f4 = local_f4 + 1;
      local_f8 = local_f8 + 1;
      local_fc = local_fc + 1;
    }
    if (param_1 + param_3 < uVar3) {
      local_100 = uVar3 - param_3;
      goto LAB_0054f074;
    }
  }
  else {
    if (param_1 + param_3 < uVar3) {
      *local_f8 = param_1;
      *local_fc = uVar3 - param_3;
      local_f4 = local_f4 + 1;
      local_f8 = local_f8 + 1;
      local_fc = local_fc + 1;
    }
    param_1 = uVar1;
    if (uVar1 < local_100) goto LAB_0054f074;
  }
LAB_0054f095:
  local_f4 = local_f4 + -1;
  local_f8 = local_f8 + -1;
  local_fc = local_fc + -1;
  if (local_f4 < 0) {
    return;
  }
  local_100 = *local_fc;
  param_1 = *local_f8;
  goto LAB_0054f074;
}

// --------------------------------------------------

// Function: FUN_0054f1c5
// Address: 0054f1c5
void FUN_0054f1c5(uint param_1,uint param_2,int param_3,code *param_4)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 < param_2) {
    uVar1 = param_3 + param_1;
    uVar3 = param_1;
    do {
      for (; uVar1 <= param_2; uVar1 = uVar1 + param_3) {
        iVar2 = (*param_4)(uVar1,uVar3);
        if (0 < iVar2) {
          uVar3 = uVar1;
        }
      }
      FUN_0054f230(uVar3,param_2,param_3);
      param_2 = param_2 - param_3;
      uVar1 = param_3 + param_1;
      uVar3 = param_1;
    } while (param_1 < param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054f1d0
// Address: 0054f1d0
void FUN_0054f1d0(uint param_1,uint param_2,int param_3,code *param_4)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 < param_2) {
    uVar1 = param_3 + param_1;
    uVar3 = param_1;
    do {
      for (; uVar1 <= param_2; uVar1 = uVar1 + param_3) {
        iVar2 = (*param_4)(uVar1,uVar3);
        if (0 < iVar2) {
          uVar3 = uVar1;
        }
      }
      FUN_0054f230(uVar3,param_2,param_3);
      param_2 = param_2 - param_3;
      uVar1 = param_3 + param_1;
      uVar3 = param_1;
    } while (param_1 < param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054f229
// Address: 0054f229
void FUN_0054f229(undefined1 *param_1,undefined1 *param_2,int param_3)
{
  undefined1 uVar1;
  
  if ((param_1 != param_2) && (param_3 != 0)) {
    do {
      uVar1 = *param_1;
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      *param_2 = uVar1;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054f230
// Address: 0054f230
void FUN_0054f230(undefined1 *param_1,undefined1 *param_2,int param_3)
{
  undefined1 uVar1;
  
  if ((param_1 != param_2) && (param_3 != 0)) {
    do {
      uVar1 = *param_1;
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      *param_2 = uVar1;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054f25c
// Address: 0054f25c
int FUN_0054f25c(int param_1,int param_2,int param_3)
{
  uint uVar1;
  int iVar2;
  
  if (((*(uint *)(param_1 + 0xc) & 0x83) != 0) &&
     (((param_3 == 0 || (param_3 == 1)) || (param_3 == 2)))) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = ftell(param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    __flush(param_1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if ((uVar1 & 0x80) == 0) {
      if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
        *(undefined4 *)(param_1 + 0x18) = 0x200;
      }
    }
    else {
      *(uint *)(param_1 + 0xc) = uVar1 & 0xfffffffc;
    }
    iVar2 = lseek(*(undefined4 *)(param_1 + 0x10),param_2,param_3);
    return (iVar2 != -1) - 1;
  }
  _errno = 0x16;
  return -1;
}

// --------------------------------------------------

// Function: fseek
// Address: 0054f260
/* fseek */

int __cdecl fseek(int param_1,int param_2,int param_3)
{
  uint uVar1;
  int iVar2;
  
  if (((*(uint *)(param_1 + 0xc) & 0x83) != 0) &&
     (((param_3 == 0 || (param_3 == 1)) || (param_3 == 2)))) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = ftell(param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    __flush(param_1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if ((uVar1 & 0x80) == 0) {
      if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
        *(undefined4 *)(param_1 + 0x18) = 0x200;
      }
    }
    else {
      *(uint *)(param_1 + 0xc) = uVar1 & 0xfffffffc;
    }
    iVar2 = lseek(*(undefined4 *)(param_1 + 0x10),param_2,param_3);
    return (iVar2 != -1) - 1;
  }
  _errno = 0x16;
  return -1;
}

// --------------------------------------------------

// Function: FUN_0054f2f6
// Address: 0054f2f6
uint FUN_0054f2f6(char *param_1,uint param_2,uint param_3,int *param_4)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
  piVar1 = param_4;
  uVar5 = param_3 * param_2;
  if (uVar5 == 0) {
    return 0;
  }
  uVar6 = uVar5;
  if ((param_4[3] & 0x10cU) == 0) {
    param_4 = (int *)0x1000;
  }
  else {
    param_4 = (int *)param_4[6];
  }
  do {
    if (((piVar1[3] & 0x108U) == 0) || (uVar2 = piVar1[1], uVar2 == 0)) {
      if (uVar6 < param_4) {
        iVar3 = __flsbuf((int)*param_1,piVar1);
        if (iVar3 == -1) goto LAB_0054f434;
        param_4 = (int *)piVar1[6];
        param_1 = param_1 + 1;
        uVar6 = uVar6 - 1;
        if ((int)param_4 < 1) {
          param_4 = (int *)0x1;
        }
      }
      else {
        if (((piVar1[3] & 0x108U) != 0) && (iVar3 = __flush(piVar1), iVar3 != 0)) {
LAB_0054f434:
          return (uVar5 - uVar6) / param_2;
        }
        uVar2 = uVar6;
        if (param_4 != (int *)0x0) {
          uVar2 = uVar6 - uVar6 % (uint)param_4;
        }
        uVar4 = write(piVar1[4],param_1,uVar2);
        if (uVar4 == 0xffffffff) {
LAB_0054f419:
          piVar1[3] = piVar1[3] | 0x20;
          return (uVar5 - uVar6) / param_2;
        }
        uVar6 = uVar6 - uVar4;
        param_1 = param_1 + uVar4;
        if (uVar4 < uVar2) goto LAB_0054f419;
      }
    }
    else {
      if (uVar6 < uVar2) {
        uVar2 = uVar6;
      }
      uVar6 = uVar6 - uVar2;
      pcVar7 = param_1;
      pcVar8 = (char *)*piVar1;
      for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar4 = uVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
      param_1 = param_1 + uVar2;
      piVar1[1] = piVar1[1] - uVar2;
      *piVar1 = *piVar1 + uVar2;
    }
    if (uVar6 == 0) {
      return param_3;
    }
  } while( true );
}

// --------------------------------------------------

// Function: fwrite
// Address: 0054f300
/* fwrite */

uint __cdecl fwrite(char *param_1,uint param_2,uint param_3,int *param_4)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
  piVar1 = param_4;
  uVar5 = param_3 * param_2;
  if (uVar5 == 0) {
    return 0;
  }
  uVar6 = uVar5;
  if ((param_4[3] & 0x10cU) == 0) {
    param_4 = (int *)0x1000;
  }
  else {
    param_4 = (int *)param_4[6];
  }
  do {
    if (((piVar1[3] & 0x108U) == 0) || (uVar2 = piVar1[1], uVar2 == 0)) {
      if (uVar6 < param_4) {
        iVar3 = __flsbuf((int)*param_1,piVar1);
        if (iVar3 == -1) goto LAB_0054f434;
        param_4 = (int *)piVar1[6];
        param_1 = param_1 + 1;
        uVar6 = uVar6 - 1;
        if ((int)param_4 < 1) {
          param_4 = (int *)0x1;
        }
      }
      else {
        if (((piVar1[3] & 0x108U) != 0) && (iVar3 = __flush(piVar1), iVar3 != 0)) {
LAB_0054f434:
          return (uVar5 - uVar6) / param_2;
        }
        uVar2 = uVar6;
        if (param_4 != (int *)0x0) {
          uVar2 = uVar6 - uVar6 % (uint)param_4;
        }
        uVar4 = write(piVar1[4],param_1,uVar2);
        if (uVar4 == 0xffffffff) {
LAB_0054f419:
          piVar1[3] = piVar1[3] | 0x20;
          return (uVar5 - uVar6) / param_2;
        }
        uVar6 = uVar6 - uVar4;
        param_1 = param_1 + uVar4;
        if (uVar4 < uVar2) goto LAB_0054f419;
      }
    }
    else {
      if (uVar6 < uVar2) {
        uVar2 = uVar6;
      }
      uVar6 = uVar6 - uVar2;
      pcVar7 = param_1;
      pcVar8 = (char *)*piVar1;
      for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar4 = uVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
      param_1 = param_1 + uVar2;
      piVar1[1] = piVar1[1] - uVar2;
      *piVar1 = *piVar1 + uVar2;
    }
    if (uVar6 == 0) {
      return param_3;
    }
  } while( true );
}

// --------------------------------------------------

