// GLOBAL FUNCTIONS PART 600
// Function: FUN_00548800
// Address: 00548800
// XREFS: FUN_00548660, FUN_00548910, FUN_00548d60
void FUN_00548800(int param_1,int *param_2,int param_3,uint *param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  
  if (DAT_008875f8 != 0) {
    iVar3 = param_1;
    puVar8 = param_4;
    if (0 < param_1) {
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
    }
    iVar3 = 1;
    iVar7 = 0;
    if (0 < param_3) {
      do {
        iVar2 = *(int *)((int)&DAT_00887a98 + iVar3 * 4);
        if (0 < iVar2) {
          piVar9 = &DAT_00886cf8 + iVar7;
          for (iVar4 = iVar2; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar9 = iVar3;
            piVar9 = piVar9 + 1;
          }
          iVar7 = iVar7 + iVar2;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= param_3);
    }
    iVar3 = 0;
    DAT_00886c6c = 0;
    if (1 < param_3) {
      param_3 = param_3 + -1;
      iVar7 = 8;
      do {
        param_3 = param_3 + -1;
        iVar3 = (*(int *)((int)&DAT_00887a94 + iVar7) + iVar3) * 2;
        *(int *)((int)&UNK_00886c64 + iVar7 + 4) = iVar3;
        iVar7 = iVar7 + 4;
      } while (param_3 != 0);
    }
    iVar7 = 0;
    iVar3 = 0;
    if (0 < DAT_008875f8) {
      do {
        piVar9 = (int *)((int)&DAT_00886cf8 + iVar7);
        piVar1 = (int *)((int)&DAT_00887178 + iVar7);
        iVar7 = iVar7 + 4;
        iVar3 = iVar3 + 1;
        param_2[*piVar1] = *piVar9;
      } while (iVar3 < DAT_008875f8);
    }
    if (0 < param_1) {
      do {
        if (*param_2 != 0) {
          puVar8 = (uint *)((int)&UNK_00886c64 + *param_2 * 4 + 4);
          uVar6 = *puVar8;
          *puVar8 = uVar6 + 1;
          iVar3 = *param_2;
          uVar5 = 0;
          if (0 < iVar3) {
            do {
              uVar5 = uVar5 * 2 | uVar6 & 1;
              iVar3 = iVar3 + -1;
              uVar6 = uVar6 >> 1;
            } while (iVar3 != 0);
          }
          *param_4 = uVar5;
        }
        param_4 = param_4 + 1;
        param_2 = param_2 + 1;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005488f0
// Address: 005488f0
// XREFS: FUN_005480b0
bool FUN_005488f0(void)
{
  int iVar1;
  
  iVar1 = FUN_00547d80(1,2);
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_00548910
// Address: 00548910
// XREFS: FUN_005480b0
void FUN_00548910(void)
{
  int *piVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint *puVar8;
  uint local_4;
  
  pbVar7 = (byte *)(DAT_00887a80 + 0x2d102);
  iVar6 = 0;
  puVar8 = (uint *)(DAT_00887a80 + 0x3610c);
  FUN_00548750(DAT_00887a80 + 0x36720,0,0x120);
  FUN_00548750(DAT_00887a80 + 0x36ba0,0,0x20);
  uVar5 = *(uint *)(DAT_00887a80 + 0x36108);
  local_4 = uVar5;
  if (0 < (int)uVar5) {
    do {
      if (iVar6 == 0) {
        uVar5 = *puVar8;
        puVar8 = puVar8 + 1;
        iVar6 = 0x20;
      }
      if ((uVar5 & 0x80000000) == 0) {
        bVar2 = *pbVar7;
        pbVar7 = pbVar7 + 1;
        piVar1 = (int *)(DAT_00887a80 + 0x36720 + (uint)bVar2 * 4);
        *piVar1 = *piVar1 + 1;
      }
      else {
        uVar3 = *(ushort *)(pbVar7 + 1);
        uVar4 = uVar3 - 1;
        piVar1 = (int *)(DAT_00887a80 + 0x36720 +
                        (uint)*(ushort *)(&DAT_0058ef48 + (uint)*pbVar7 * 2) * 4);
        *piVar1 = *piVar1 + 1;
        if (uVar4 < 0x200) {
          pbVar7 = pbVar7 + 3;
          piVar1 = (int *)(DAT_00887a80 + 0x36ba0 + (uint)(byte)(&DAT_0058f347)[uVar3] * 4);
          *piVar1 = *piVar1 + 1;
        }
        else {
          pbVar7 = pbVar7 + 3;
          piVar1 = (int *)(DAT_00887a80 + 0x36ba0 + (uint)(byte)(&DAT_0058f948)[uVar4 >> 8] * 4);
          *piVar1 = *piVar1 + 1;
        }
      }
      uVar5 = uVar5 * 2;
      iVar6 = iVar6 + -1;
      local_4 = local_4 - 1;
    } while (local_4 != 0);
  }
  *(int *)(DAT_00887a80 + 0x36b20) = *(int *)(DAT_00887a80 + 0x36b20) + 1;
  FUN_00548b00(0x120,DAT_00887a80 + 0x36720,DAT_00887a80 + 0x36c6c);
  FUN_00548770(0x120,DAT_00887a80 + 0x36c6c);
  FUN_00548cb0(0xf);
  FUN_00548800(0x120,DAT_00887a80 + 0x36c6c,0xf,DAT_00887a80 + 0x371b8);
  FUN_00548b00(0x20,DAT_00887a80 + 0x36ba0,DAT_00887a80 + 0x370ec);
  FUN_00548770(0x20,DAT_00887a80 + 0x370ec);
  FUN_00548cb0(0xf);
  FUN_00548800(0x20,DAT_00887a80 + 0x370ec,0xf,DAT_00887a80 + 0x37638);
  FUN_00548d60();
  return;
}

// --------------------------------------------------

// Function: FUN_00548b00
// Address: 00548b00
// XREFS: FUN_00548910, FUN_00548d60
void FUN_00548b00(int param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  if (0 < param_1) {
    puVar6 = &DAT_00887600;
    for (iVar2 = param_1; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = 0xffffffff;
      puVar6 = puVar6 + 1;
    }
    iVar2 = param_1;
    puVar6 = param_3;
    if (0 < param_1) {
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
    }
  }
  iVar7 = 1;
  iVar2 = 0;
  if (0 < param_1) {
    piVar4 = &DAT_00887b24;
    piVar3 = param_2;
    do {
      if (*piVar3 != 0) {
        *piVar4 = iVar2;
        piVar4 = piVar4 + 1;
        iVar7 = iVar7 + 1;
      }
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1);
  }
  iVar7 = iVar7 + -1;
  if (iVar7 < 2) {
    if (iVar7 != 0) {
      param_3[DAT_00887b24] = 1;
      return;
    }
  }
  else {
    for (iVar2 = iVar7 >> 1; iVar2 != 0; iVar2 = iVar2 + -1) {
      FUN_00548c20(&DAT_00887b20,param_2,iVar7,iVar2);
    }
    do {
      iVar2 = DAT_00887b24;
      DAT_00887b24 = (&DAT_00887b20)[iVar7];
      iVar7 = iVar7 + -1;
      FUN_00548c20(&DAT_00887b20,param_2,iVar7,1);
      iVar1 = DAT_00887b24;
      param_2[DAT_00887b24] = param_2[DAT_00887b24] + param_2[iVar2];
      FUN_00548c20(&DAT_00887b20,param_2,iVar7,1);
      do {
        iVar5 = iVar1;
        param_3[iVar5] = param_3[iVar5] + 1;
        iVar1 = (&DAT_00887600)[iVar5];
      } while ((&DAT_00887600)[iVar5] != -1);
      (&DAT_00887600)[iVar5] = iVar2;
      do {
        param_3[iVar2] = param_3[iVar2] + 1;
        iVar2 = (&DAT_00887600)[iVar2];
      } while (iVar2 != -1);
    } while (iVar7 != 1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00548c20
// Address: 00548c20
// XREFS: FUN_00548b00
void FUN_00548c20(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = param_4 * 2;
  iVar1 = *(int *)(param_1 + param_4 * 4);
  if (iVar6 - param_3 == 0 || iVar6 < param_3) {
    iVar5 = iVar6 - param_3;
    do {
      iVar7 = iVar6;
      if (SBORROW4(iVar6,param_3) != iVar5 < 0) {
        iVar5 = *(int *)(param_1 + 4 + iVar6 * 4);
        iVar2 = *(int *)(param_2 + iVar5 * 4);
        iVar3 = *(int *)(param_1 + iVar6 * 4);
        iVar4 = *(int *)(param_2 + iVar3 * 4);
        if ((iVar2 < iVar4) || ((iVar2 == iVar4 && (iVar3 < iVar5)))) {
          iVar7 = iVar6 + 1;
        }
      }
      iVar5 = *(int *)(param_1 + iVar7 * 4);
      iVar6 = *(int *)(param_2 + iVar5 * 4);
      iVar2 = *(int *)(param_2 + iVar1 * 4);
      if ((iVar2 < iVar6) || ((iVar6 == iVar2 && (iVar5 < iVar1)))) break;
      iVar6 = iVar7 * 2;
      *(int *)(param_1 + param_4 * 4) = iVar5;
      iVar5 = iVar6 - param_3;
      param_4 = iVar7;
    } while (iVar6 <= param_3);
  }
  *(int *)(param_1 + param_4 * 4) = iVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_00548cb0
// Address: 00548cb0
// XREFS: FUN_00548910, FUN_00548d60
void FUN_00548cb0(int param_1)
{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  if (1 < DAT_008875f8) {
    if (param_1 + 1 < 0x21) {
      piVar4 = (int *)((int)&DAT_00887a98 + (param_1 + 1) * 4);
      piVar3 = (int *)((int)&DAT_00887a98 + param_1 * 4);
      do {
        iVar2 = *piVar4;
        piVar4 = piVar4 + 1;
        *piVar3 = *piVar3 + iVar2;
      } while (piVar4 < &UNK_00887aa4.field_0x75);
    }
    iVar5 = 0;
    bVar1 = (byte)param_1;
    iVar2 = param_1;
    if (0 < param_1) {
      do {
        iVar5 = iVar5 + (*(int *)((int)&DAT_00887a98 + iVar2 * 4) << (bVar1 - (char)iVar2 & 0x1f));
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if (iVar5 != 1 << (bVar1 & 0x1f)) {
      piVar4 = (int *)((int)&DAT_00887a98 + param_1 * 4);
      param_1 = param_1 + -1;
      iVar5 = iVar5 + (-1 << (bVar1 & 0x1f));
      do {
        while (*piVar4 = *piVar4 + -1, 0 < param_1) {
          piVar3 = (int *)((int)&DAT_00887a98 + param_1 * 4);
          iVar2 = param_1;
          do {
            if (*piVar3 != 0) {
              piVar3 = (int *)((int)&DAT_00887a98 + iVar2 * 4);
              *piVar3 = *piVar3 + -1;
              (&DAT_00887a9c)[iVar2] = (&DAT_00887a9c)[iVar2] + 2;
              goto LAB_00548d5a;
            }
            piVar3 = piVar3 + -1;
            iVar2 = iVar2 + -1;
          } while (&DAT_00887a98 < piVar3);
          iVar5 = iVar5 + -1;
          if (iVar5 == 0) {
            return;
          }
        }
LAB_00548d5a:
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00548d60
// Address: 00548d60
// XREFS: FUN_00548910
void FUN_00548d60(void)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *local_8;
  int local_4;
  
  iVar4 = 0xff;
  iVar5 = 0;
  iVar7 = 0;
  FUN_00548750(DAT_00887a80 + 0x36c20,0,0x13);
  *(undefined4 *)(DAT_00887a80 + 0x38108) = 0x11d;
  iVar3 = *(int *)(DAT_00887a80 + 0x38108);
  while (-1 < iVar3) {
    if (*(int *)(DAT_00887a80 + 0x36c6c + *(int *)(DAT_00887a80 + 0x38108) * 4) != 0) break;
    *(int *)(DAT_00887a80 + 0x38108) = *(int *)(DAT_00887a80 + 0x38108) + -1;
    iVar3 = *(int *)(DAT_00887a80 + 0x38108);
  }
  iVar3 = *(int *)(DAT_00887a80 + 0x38108) + 1;
  if (iVar3 < 0x102) {
    iVar3 = 0x101;
  }
  *(int *)(DAT_00887a80 + 0x38108) = iVar3;
  *(undefined4 *)(DAT_00887a80 + 0x3810c) = 0x1d;
  iVar3 = *(int *)(DAT_00887a80 + 0x3810c);
  while (-1 < iVar3) {
    if (*(int *)(DAT_00887a80 + 0x370ec + *(int *)(DAT_00887a80 + 0x3810c) * 4) != 0) break;
    *(int *)(DAT_00887a80 + 0x3810c) = *(int *)(DAT_00887a80 + 0x3810c) + -1;
    iVar3 = *(int *)(DAT_00887a80 + 0x3810c);
  }
  iVar3 = *(int *)(DAT_00887a80 + 0x3810c) + 1;
  if (iVar3 < 2) {
    iVar3 = 1;
  }
  *(int *)(DAT_00887a80 + 0x3810c) = iVar3;
  FUN_00549020(DAT_00887a80 + 0x37704,DAT_00887a80 + 0x36c6c,*(undefined4 *)(DAT_00887a80 + 0x38108)
              );
  FUN_00549020(DAT_00887a80 + *(int *)(DAT_00887a80 + 0x38108) * 4 + 0x37704,DAT_00887a80 + 0x370ec,
               *(undefined4 *)(DAT_00887a80 + 0x3810c));
  piVar2 = (int *)(DAT_00887a80 + 0x37c04);
  local_4 = *(int *)(DAT_00887a80 + 0x38108) + *(int *)(DAT_00887a80 + 0x3810c);
  iVar3 = iVar4;
  iVar6 = iVar5;
  iVar8 = iVar7;
  local_8 = (int *)(DAT_00887a80 + 0x37704);
  if (0 < local_4) {
    do {
      iVar4 = *local_8;
      iVar7 = iVar8;
      if (iVar4 == 0) {
        if (iVar8 != 0) {
          iVar7 = 0;
          piVar2 = (int *)FUN_00549040(piVar2,iVar3,iVar8);
        }
        iVar5 = iVar6 + 1;
        if (iVar5 == 0x8a) {
          iVar5 = 0;
          piVar2 = (int *)FUN_005490a0(piVar2,0x8a);
        }
      }
      else {
        iVar5 = iVar6;
        if (iVar6 != 0) {
          iVar5 = 0;
          piVar2 = (int *)FUN_005490a0(piVar2,iVar6);
        }
        if (iVar3 == iVar4) {
          iVar7 = iVar8 + 1;
          if (iVar7 == 6) {
            iVar7 = 0;
            piVar2 = (int *)FUN_00549040(piVar2,iVar3,6);
          }
        }
        else {
          if (iVar8 != 0) {
            iVar7 = 0;
            piVar2 = (int *)FUN_00549040(piVar2,iVar3,iVar8);
          }
          piVar1 = (int *)(DAT_00887a80 + 0x36c20 + iVar4 * 4);
          *piVar1 = *piVar1 + 1;
          *piVar2 = iVar4;
          piVar2 = piVar2 + 1;
        }
      }
      local_4 = local_4 + -1;
      iVar3 = iVar4;
      iVar6 = iVar5;
      iVar8 = iVar7;
      local_8 = local_8 + 1;
    } while (local_4 != 0);
  }
  if (iVar7 == 0) {
    if (iVar5 != 0) {
      piVar2 = (int *)FUN_005490a0(piVar2,iVar5);
    }
  }
  else {
    piVar2 = (int *)FUN_00549040(piVar2,iVar4,iVar7);
  }
  *(int **)(DAT_00887a80 + 0x38104) = piVar2;
  FUN_00548b00(0x13,DAT_00887a80 + 0x36c20,DAT_00887a80 + 0x3716c);
  FUN_00548770(0x13,DAT_00887a80 + 0x3716c);
  FUN_00548cb0(7);
  FUN_00548800(0x13,DAT_00887a80 + 0x3716c,7,DAT_00887a80 + 0x376b8);
  return;
}

// --------------------------------------------------

// Function: FUN_00549020
// Address: 00549020
// XREFS: FUN_00548d60
void FUN_00549020(undefined4 *param_1,undefined4 *param_2,int param_3)
{
  undefined4 uVar1;
  
  if (param_3 != 0) {
    do {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00549040
// Address: 00549040
// XREFS: FUN_00548d60
int * FUN_00549040(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  
  if (2 < param_3) {
    *(int *)(DAT_00887a80 + 0x36c60) = *(int *)(DAT_00887a80 + 0x36c60) + 1;
    *param_1 = 0x10;
    param_1[1] = param_3 + -3;
    return param_1 + 2;
  }
  piVar1 = (int *)(DAT_00887a80 + 0x36c20 + param_2 * 4);
  *piVar1 = *piVar1 + param_3;
  if (param_3 != 0) {
    do {
      param_3 = param_3 + -1;
      *param_1 = param_2;
      param_1 = param_1 + 1;
    } while (param_3 != 0);
    return param_1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005490a0
// Address: 005490a0
// XREFS: FUN_00548d60
undefined4 * FUN_005490a0(undefined4 *param_1,int param_2)
{
  if (2 < param_2) {
    if (param_2 < 0xb) {
      *(int *)(DAT_00887a80 + 0x36c64) = *(int *)(DAT_00887a80 + 0x36c64) + 1;
      *param_1 = 0x11;
      param_1[1] = param_2 + -3;
      return param_1 + 2;
    }
    *(int *)(DAT_00887a80 + 0x36c68) = *(int *)(DAT_00887a80 + 0x36c68) + 1;
    *param_1 = 0x12;
    param_1[1] = param_2 + -0xb;
    return param_1 + 2;
  }
  *(int *)(DAT_00887a80 + 0x36c20) = *(int *)(DAT_00887a80 + 0x36c20) + param_2;
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      *param_1 = 0;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
    return param_1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00549120
// Address: 00549120
// XREFS: FUN_005480b0
bool FUN_00549120(void)
{
  int iVar1;
  
  iVar1 = FUN_00547d80(2,2);
  if (iVar1 != 0) {
    return true;
  }
  iVar1 = FUN_00549150();
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_00549150
// Address: 00549150
// XREFS: FUN_00549120
undefined4 FUN_00549150(void)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar1 = FUN_00547d80(*(int *)(DAT_00887a80 + 0x38108) + -0x101,5);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = FUN_00547d80(*(int *)(DAT_00887a80 + 0x3810c) + -1,5);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = 0x12;
  do {
    if (*(int *)(DAT_00887a80 + 0x3716c + (uint)(byte)(&DAT_0058ef30)[iVar1] * 4) != 0) break;
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  iVar1 = iVar1 + 1;
  if (iVar1 < 5) {
    iVar1 = 4;
  }
  iVar2 = FUN_00547d80(iVar1 + -4,4);
  if (iVar2 != 0) {
    return 1;
  }
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = FUN_00547d80(*(undefined4 *)
                            (DAT_00887a80 + 0x3716c + (uint)(byte)(&DAT_0058ef30)[iVar2] * 4),3);
      if (iVar3 != 0) {
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  piVar5 = (int *)(DAT_00887a80 + 0x37c04);
  while( true ) {
    piVar4 = piVar5;
    if (*(int **)(DAT_00887a80 + 0x38104) <= piVar4) {
      return 0;
    }
    iVar1 = *piVar4;
    piVar5 = piVar4 + 1;
    iVar2 = iVar1 * 4 + DAT_00887a80;
    iVar2 = FUN_00547d80(*(undefined4 *)(iVar2 + 0x376b8),*(undefined4 *)(iVar2 + 0x3716c));
    if (iVar2 != 0) break;
    if (iVar1 == 0x10) {
      iVar1 = FUN_00547d80(*piVar5,2);
      piVar5 = piVar4 + 2;
      if (iVar1 != 0) {
        return 1;
      }
    }
    else if (iVar1 == 0x11) {
      iVar1 = FUN_00547d80(*piVar5,3);
      piVar5 = piVar4 + 2;
      if (iVar1 != 0) {
        return 1;
      }
    }
    else if (iVar1 == 0x12) {
      iVar1 = FUN_00547d80(*piVar5,7);
      piVar5 = piVar4 + 2;
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_005492f0
// Address: 005492f0
// XREFS: FUN_005480b0
undefined4 FUN_005492f0(void)
{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = FUN_00547d80(0,2);
  if (iVar2 != 0) {
    return 1;
  }
  iVar2 = FUN_00547d50();
  if (iVar2 != 0) {
    return 1;
  }
  do {
    iVar2 = DAT_00887a88;
    DAT_00887a88 = DAT_00887a88 + -1;
    if (-1 < DAT_00887a88) {
      *DAT_00887a90 = *(undefined1 *)(DAT_00887a80 + 0x3671c);
      DAT_00887a90 = DAT_00887a90 + 1;
      do {
        iVar2 = DAT_00887a88;
        DAT_00887a88 = DAT_00887a88 + -1;
        if (-1 < DAT_00887a88) {
          *DAT_00887a90 = (char)((uint)*(undefined4 *)(DAT_00887a80 + 0x3671c) >> 8);
          DAT_00887a90 = DAT_00887a90 + 1;
          do {
            iVar2 = DAT_00887a88;
            DAT_00887a88 = DAT_00887a88 + -1;
            if (-1 < DAT_00887a88) {
              *DAT_00887a90 = ~(byte)*(undefined4 *)(DAT_00887a80 + 0x3671c);
              DAT_00887a90 = DAT_00887a90 + 1;
              do {
                iVar2 = DAT_00887a88;
                DAT_00887a88 = DAT_00887a88 + -1;
                if (-1 < DAT_00887a88) {
                  *DAT_00887a90 = ~(byte)((uint)*(undefined4 *)(DAT_00887a80 + 0x3671c) >> 8);
                  uVar4 = *(uint *)(DAT_00887a80 + 0x36714);
                  iVar2 = *(int *)(DAT_00887a80 + 0x3671c);
                  do {
                    DAT_00887a90 = DAT_00887a90 + 1;
                    if (iVar2 < 1) {
                      return 0;
                    }
                    while (iVar3 = DAT_00887a88, DAT_00887a88 = DAT_00887a88 + -1, DAT_00887a88 < 0)
{
                      DAT_00887a88 = iVar3;
                      iVar3 = FUN_00547cf0();
                      if (iVar3 != 0) {
                        return 1;
                      }
                    }
                    pbVar1 = (byte *)(DAT_00887a94 + uVar4);
                    iVar2 = iVar2 + -1;
                    uVar4 = uVar4 + 1 & 0x7fff;
                    *DAT_00887a90 = *pbVar1;
                  } while( true );
                }
                DAT_00887a88 = iVar2;
                iVar2 = FUN_00547cf0();
              } while (iVar2 == 0);
              return 1;
            }
            DAT_00887a88 = iVar2;
            iVar2 = FUN_00547cf0();
          } while (iVar2 == 0);
          return 1;
        }
        DAT_00887a88 = iVar2;
        iVar2 = FUN_00547cf0();
      } while (iVar2 == 0);
      return 1;
    }
    DAT_00887a88 = iVar2;
    iVar2 = FUN_00547cf0();
  } while (iVar2 == 0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00549460
// Address: 00549460
// XREFS: FUN_00547b30
void FUN_00549460(int param_1)
{
  uint uVar1;
  
  uVar1 = param_1 - *(int *)(DAT_00887a80 + 0x38120) & 0x7fff;
  *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + uVar1;
  *(uint *)(DAT_00887a80 + 0x38128) = *(int *)(DAT_00887a80 + 0x38120) + uVar1 + 0xefd;
  FUN_005494a0();
  return;
}

// --------------------------------------------------

// Function: FUN_005494a0
// Address: 005494a0
// XREFS: FUN_00549460, FUN_0054a360
undefined4 FUN_005494a0(void)
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(DAT_00887a80 + 0x3813c) != 0) {
    if (3 < DAT_00886c60) {
      uVar1 = FUN_00549b70();
      return uVar1;
    }
    uVar1 = FUN_00549f40();
    return uVar1;
  }
  while (*(int *)(DAT_00887a80 + 0x38124) != 0) {
    uVar3 = *(uint *)(DAT_00887a80 + 0x38120);
    if (*(uint *)(DAT_00887a80 + 0x38128) <= uVar3) break;
    if (*(short *)(DAT_00886cf0 + (uVar3 & 0x7fff) * 2) == -1) {
      **(undefined1 **)(DAT_00887a80 + 0x36104) = *(undefined1 *)(DAT_00887a94 + uVar3);
      *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
      *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
      *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
      *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
      **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
      *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
      if ((*(int *)(DAT_00887a80 + 0x36710) == 0) && (iVar2 = FUN_00549b20(), iVar2 != 0)) {
        return 1;
      }
    }
    else {
      DAT_00887b1c = 2;
      FUN_00549970(*(uint *)(DAT_00887a80 + 0x38120));
      iVar2 = DAT_00887b1c;
      iVar6 = DAT_00887fa8;
      if (DAT_00887b1c == 2) {
        **(undefined1 **)(DAT_00887a80 + 0x36104) =
             *(undefined1 *)(*(int *)(DAT_00887a80 + 0x38120) + DAT_00887a94);
        *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
        *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
        *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
        *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
        **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
        *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
        if ((*(int *)(DAT_00887a80 + 0x36710) == 0) && (iVar2 = FUN_00549b20(), iVar2 != 0)) {
          return 1;
        }
      }
      else {
        while ((iVar2 < 0x80 &&
               (uVar3 = *(int *)(DAT_00887a80 + 0x38120) + 1,
               *(short *)(DAT_00886cf0 + (uVar3 & 0x7fff) * 2) != -1))) {
          FUN_00549970(uVar3);
          iVar5 = DAT_00887fa8;
          iVar4 = *(int *)(DAT_00887a80 + 0x38124) + -1;
          if (iVar4 < DAT_00887b1c) {
            DAT_00887b1c = iVar4;
          }
          iVar4 = DAT_00887b1c;
          if (DAT_00887b1c <= iVar2) break;
          **(undefined1 **)(DAT_00887a80 + 0x36104) =
               *(undefined1 *)(*(int *)(DAT_00887a80 + 0x38120) + DAT_00887a94);
          *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
          *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
          *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
          *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
          **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
          *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
          iVar2 = iVar4;
          iVar6 = iVar5;
          if ((*(int *)(DAT_00887a80 + 0x36710) == 0) && (iVar5 = FUN_00549b20(), iVar5 != 0)) {
            return 1;
          }
        }
        iVar5 = *(int *)(DAT_00887a80 + 0x38124);
        if ((iVar5 < iVar2) && (iVar2 = iVar5, iVar5 < 3)) {
          **(undefined1 **)(DAT_00887a80 + 0x36104) =
               *(undefined1 *)(*(int *)(DAT_00887a80 + 0x38120) + DAT_00887a94);
          *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
          *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
          *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
          *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
          **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
          *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
          if ((*(int *)(DAT_00887a80 + 0x36710) == 0) && (iVar2 = FUN_00549b20(), iVar2 != 0)) {
            return 1;
          }
        }
        else {
          uVar3 = *(int *)(DAT_00887a80 + 0x38120) - iVar6 & 0x7fff;
          if ((iVar2 == 3) && (0x3fff < uVar3)) {
            **(undefined1 **)(DAT_00887a80 + 0x36104) =
                 *(undefined1 *)(DAT_00887a94 + *(int *)(DAT_00887a80 + 0x38120));
            *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
            *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
            *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
            *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
            **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
            *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
            if ((*(int *)(DAT_00887a80 + 0x36710) == 0) && (iVar2 = FUN_00549b20(), iVar2 != 0)) {
              return 1;
            }
          }
          else {
            **(char **)(DAT_00887a80 + 0x36104) = (char)iVar2 + -3;
            *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
            **(undefined2 **)(DAT_00887a80 + 0x36104) = (short)uVar3;
            *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 2;
            *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + iVar2;
            *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) - iVar2;
            *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + iVar2;
            **(uint **)(DAT_00887a80 + 0x3670c) = **(uint **)(DAT_00887a80 + 0x3670c) * 2 | 1;
            *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
            if ((*(int *)(DAT_00887a80 + 0x36710) == 0) && (iVar2 = FUN_00549b20(), iVar2 != 0)) {
              return 1;
            }
          }
        }
      }
    }
  }
  *(uint *)(DAT_00887a80 + 0x38120) = *(uint *)(DAT_00887a80 + 0x38120) & 0x7fff;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00549970
// Address: 00549970
// XREFS: FUN_005494a0, FUN_00549b70
void FUN_00549970(uint param_1)
{
  short *psVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  short *psVar9;
  short local_6;
  
  uVar4 = param_1 & 0x7fff;
  psVar1 = (short *)(param_1 + DAT_00887a94);
  local_6 = *(short *)(DAT_00887b1c + param_1 + -1 + DAT_00887a94);
  iVar7 = DAT_00887b1c + -1 + DAT_00887a94;
  iVar3 = DAT_00886c60;
  do {
    if (iVar3 < 1) {
      return;
    }
    uVar4 = (uint)*(ushort *)(DAT_00886cf0 + uVar4 * 2);
    if (uVar4 == 0xffff) {
      return;
    }
    iVar2 = iVar3 + -1;
    if (*(short *)(iVar7 + uVar4) == local_6) goto LAB_00549a52;
    uVar4 = (uint)*(ushort *)(DAT_00886cf0 + uVar4 * 2);
    if (uVar4 == 0xffff) {
      return;
    }
    iVar2 = iVar3 + -2;
    if (*(short *)(iVar7 + uVar4) == local_6) goto LAB_00549a52;
    uVar4 = (uint)*(ushort *)(DAT_00886cf0 + uVar4 * 2);
    if (uVar4 == 0xffff) {
      return;
    }
    iVar2 = iVar3 + -3;
    if (*(short *)(iVar7 + uVar4) == local_6) goto LAB_00549a52;
    iVar3 = iVar3 + -4;
    uVar4 = (uint)*(ushort *)(DAT_00886cf0 + uVar4 * 2);
    if (uVar4 == 0xffff) {
      return;
    }
    iVar2 = iVar3;
    if (*(short *)(iVar7 + uVar4) == local_6) {
LAB_00549a52:
      iVar3 = iVar2;
      if (*(short *)(DAT_00887a94 + uVar4) == *psVar1) {
        iVar2 = 0x20;
        psVar5 = (short *)(DAT_00887a94 + uVar4);
        psVar8 = psVar1;
        while( true ) {
          psVar9 = psVar8 + 1;
          psVar6 = psVar5 + 1;
          if (*psVar6 != psVar8[1]) break;
          psVar9 = psVar8 + 2;
          psVar6 = psVar5 + 2;
          if (*psVar6 != psVar8[2]) break;
          psVar9 = psVar8 + 3;
          psVar6 = psVar5 + 3;
          if (*psVar6 != psVar8[3]) break;
          psVar9 = psVar8 + 4;
          psVar6 = psVar5 + 4;
          if ((*psVar6 != psVar8[4]) ||
             (iVar2 = iVar2 + -1, psVar5 = psVar6, psVar8 = psVar9, iVar2 < 1)) break;
        }
        if (iVar2 == 0) {
          DAT_00887fa8 = uVar4;
          DAT_00887b1c = 0x102;
          return;
        }
        iVar2 = ((int)psVar9 - (int)psVar1 & 0xfffffffeU) + (uint)((char)*psVar6 == (char)*psVar9);
        if (DAT_00887b1c < iVar2) {
          local_6 = *(short *)(param_1 + iVar2 + -1 + DAT_00887a94);
          iVar7 = iVar2 + -1 + DAT_00887a94;
          DAT_00887b1c = iVar2;
          DAT_00887fa8 = uVar4;
        }
      }
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00549b20
// Address: 00549b20
// XREFS: FUN_005494a0, FUN_00549b70, FUN_00549f40
undefined4 FUN_00549b20(void)
{
  undefined4 uVar1;
  
  *(int *)(DAT_00887a80 + 0x3670c) = *(int *)(DAT_00887a80 + 0x3670c) + 4;
  *(undefined4 *)(DAT_00887a80 + 0x36710) = 0x20;
  *(int *)(DAT_00887a80 + 0x36108) = *(int *)(DAT_00887a80 + 0x36108) + 0x20;
  if (*(int *)(DAT_00887a80 + 0x36108) == 0x3000) {
    uVar1 = FUN_005480b0(0);
    return uVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00549b70
// Address: 00549b70
// XREFS: FUN_005494a0
undefined4 FUN_00549b70(void)
{
  int iVar1;
  uint uVar2;
  
  while (*(int *)(DAT_00887a80 + 0x38124) != 0) {
    uVar2 = *(uint *)(DAT_00887a80 + 0x38120);
    if (*(uint *)(DAT_00887a80 + 0x38128) <= uVar2) break;
    if (*(short *)(DAT_00886cf0 + (uVar2 & 0x7fff) * 2) == -1) {
      **(undefined1 **)(DAT_00887a80 + 0x36104) = *(undefined1 *)(DAT_00887a94 + uVar2);
      *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
      *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
      *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
      *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
      **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
      *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
      if (*(int *)(DAT_00887a80 + 0x36710) == 0) {
        iVar1 = FUN_00549b20();
        if (iVar1 != 0) {
          return 1;
        }
      }
    }
    else {
      DAT_00887b1c = 2;
      FUN_00549970(*(uint *)(DAT_00887a80 + 0x38120));
      if (DAT_00887b1c == 2) {
        **(undefined1 **)(DAT_00887a80 + 0x36104) =
             *(undefined1 *)(*(int *)(DAT_00887a80 + 0x38120) + DAT_00887a94);
        *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
        *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
        *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
        *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
        **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
        *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
        if (*(int *)(DAT_00887a80 + 0x36710) == 0) {
          iVar1 = FUN_00549b20();
          if (iVar1 != 0) {
            return 1;
          }
        }
      }
      else {
        iVar1 = *(int *)(DAT_00887a80 + 0x38124);
        if ((iVar1 < DAT_00887b1c) && (DAT_00887b1c = iVar1, iVar1 < 3)) {
          **(undefined1 **)(DAT_00887a80 + 0x36104) =
               *(undefined1 *)(*(int *)(DAT_00887a80 + 0x38120) + DAT_00887a94);
          *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
          *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
          *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
          *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
          **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
          *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
          if (*(int *)(DAT_00887a80 + 0x36710) == 0) {
            iVar1 = FUN_00549b20();
            if (iVar1 != 0) {
              return 1;
            }
          }
        }
        else {
          uVar2 = *(int *)(DAT_00887a80 + 0x38120) - DAT_00887fa8 & 0x7fff;
          if ((DAT_00887b1c == 3) && (0x3fff < uVar2)) {
            **(undefined1 **)(DAT_00887a80 + 0x36104) =
                 *(undefined1 *)(DAT_00887a94 + *(int *)(DAT_00887a80 + 0x38120));
            *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
            *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
            *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
            *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
            **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
            *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
            if (*(int *)(DAT_00887a80 + 0x36710) == 0) {
              iVar1 = FUN_00549b20();
              if (iVar1 != 0) {
                return 1;
              }
            }
          }
          else {
            **(char **)(DAT_00887a80 + 0x36104) = (char)DAT_00887b1c + -3;
            *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
            **(undefined2 **)(DAT_00887a80 + 0x36104) = (short)uVar2;
            *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 2;
            *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + DAT_00887b1c;
            *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) - DAT_00887b1c;
            *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + DAT_00887b1c;
            **(uint **)(DAT_00887a80 + 0x3670c) = **(uint **)(DAT_00887a80 + 0x3670c) * 2 | 1;
            *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
            if (*(int *)(DAT_00887a80 + 0x36710) == 0) {
              iVar1 = FUN_00549b20();
              if (iVar1 != 0) {
                return 1;
              }
            }
          }
        }
      }
    }
  }
  *(uint *)(DAT_00887a80 + 0x38120) = *(uint *)(DAT_00887a80 + 0x38120) & 0x7fff;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00549f40
// Address: 00549f40
// XREFS: FUN_005494a0
undefined4 FUN_00549f40(void)
{
  short sVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  int *piVar5;
  uint uVar6;
  short *psVar7;
  short *psVar8;
  
  while (*(int *)(DAT_00887a80 + 0x38124) != 0) {
    piVar5 = (int *)(DAT_00887a80 + 0x38120);
    if (*(uint *)(DAT_00887a80 + 0x38128) <= *(uint *)(DAT_00887a80 + 0x38120)) break;
    DAT_00887fa8 = (uint)*(ushort *)
                          (DAT_00886cf0 + (*(uint *)(DAT_00887a80 + 0x38120) & 0x7fff) * 2);
    if (DAT_00887fa8 == 0xffff) {
      **(undefined1 **)(DAT_00887a80 + 0x36104) = *(undefined1 *)(*piVar5 + DAT_00887a94);
      *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
      *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
      *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
      *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
      **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
      *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
      if (*(int *)(DAT_00887a80 + 0x36710) == 0) {
        iVar2 = FUN_00549b20();
        if (iVar2 != 0) {
          return 1;
        }
      }
    }
    else {
      sVar1 = *(short *)(*piVar5 + DAT_00887a94);
      if (*(short *)(DAT_00887fa8 + DAT_00887a94) == sVar1) {
        DAT_00887b1c = 0x20;
        psVar3 = (short *)(*piVar5 + DAT_00887a94);
        psVar7 = (short *)(DAT_00887fa8 + DAT_00887a94);
        while( true ) {
          psVar8 = psVar7 + 1;
          psVar4 = psVar3 + 1;
          if (*psVar4 != *psVar8) break;
          psVar8 = psVar7 + 2;
          psVar4 = psVar3 + 2;
          if (*psVar4 != *psVar8) break;
          psVar8 = psVar7 + 3;
          psVar4 = psVar3 + 3;
          if (*psVar4 != *psVar8) break;
          psVar8 = psVar7 + 4;
          psVar4 = psVar3 + 4;
          if ((*psVar4 != *psVar8) ||
             (DAT_00887b1c = DAT_00887b1c + -1, psVar3 = psVar4, psVar7 = psVar8, DAT_00887b1c < 1))
          break;
        }
        if (DAT_00887b1c == 0) {
          DAT_00887b1c = 0x102;
        }
        else {
          DAT_00887b1c = ((uint)((int)psVar8 + (-DAT_00887a94 - DAT_00887fa8)) & 0xfffffffe) +
                         (uint)((char)*psVar4 == (char)*psVar8);
        }
        iVar2 = *(int *)(DAT_00887a80 + 0x38124);
        if ((iVar2 < DAT_00887b1c) && (DAT_00887b1c = iVar2, iVar2 < 3)) {
          **(undefined1 **)(DAT_00887a80 + 0x36104) = *(undefined1 *)(*piVar5 + DAT_00887a94);
          *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
          *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
          *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
          *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
          **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
          *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
          if (*(int *)(DAT_00887a80 + 0x36710) == 0) {
            iVar2 = FUN_00549b20();
            if (iVar2 != 0) {
              return 1;
            }
          }
        }
        else {
          uVar6 = *piVar5 - DAT_00887fa8 & 0x7fff;
          if ((DAT_00887b1c == 3) && (0x3fff < uVar6)) {
            **(undefined1 **)(DAT_00887a80 + 0x36104) = *(undefined1 *)(DAT_00887a94 + *piVar5);
            *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
            *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
            *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
            *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
            **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
            *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
            if (*(int *)(DAT_00887a80 + 0x36710) == 0) {
              iVar2 = FUN_00549b20();
              if (iVar2 != 0) {
                return 1;
              }
            }
          }
          else {
            **(char **)(DAT_00887a80 + 0x36104) = (char)DAT_00887b1c + -3;
            *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
            **(undefined2 **)(DAT_00887a80 + 0x36104) = (short)uVar6;
            *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 2;
            *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + DAT_00887b1c;
            *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) - DAT_00887b1c;
            *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + DAT_00887b1c;
            **(uint **)(DAT_00887a80 + 0x3670c) = **(uint **)(DAT_00887a80 + 0x3670c) * 2 | 1;
            *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
            if (*(int *)(DAT_00887a80 + 0x36710) == 0) {
              iVar2 = FUN_00549b20();
              if (iVar2 != 0) {
                return 1;
              }
            }
          }
        }
      }
      else {
        **(undefined1 **)(DAT_00887a80 + 0x36104) = (char)sVar1;
        *(int *)(DAT_00887a80 + 0x38120) = *(int *)(DAT_00887a80 + 0x38120) + 1;
        *(int *)(DAT_00887a80 + 0x36104) = *(int *)(DAT_00887a80 + 0x36104) + 1;
        *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + -1;
        *(int *)(DAT_00887a80 + 0x3671c) = *(int *)(DAT_00887a80 + 0x3671c) + 1;
        **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
        *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
        if (*(int *)(DAT_00887a80 + 0x36710) == 0) {
          iVar2 = FUN_00549b20();
          if (iVar2 != 0) {
            return 1;
          }
        }
      }
    }
  }
  *(uint *)(DAT_00887a80 + 0x38120) = *(uint *)(DAT_00887a80 + 0x38120) & 0x7fff;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054a360
// Address: 0054a360
// XREFS: FUN_00547b30
void FUN_0054a360(void)
{
  *(undefined4 *)(DAT_00887a80 + 0x38128) = 0xffff;
  FUN_005494a0();
  return;
}

// --------------------------------------------------

// Function: FUN_0054a380
// Address: 0054a380
// XREFS: FUN_00547b30
undefined4 FUN_0054a380(void)
{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00887a80 + 0x38158);
  if (*(int *)(DAT_00887a80 + 0x38150) <= *(int *)(DAT_00887a80 + 0x38158)) {
    iVar1 = *(int *)(DAT_00887a80 + 0x38150);
  }
  FUN_00547c90(*(int *)(DAT_00887a80 + 0x3814c) + DAT_00887a94,
               *(undefined4 *)(DAT_00887a80 + 0x38154),iVar1);
  *(int *)(DAT_00887a80 + 0x38154) = *(int *)(DAT_00887a80 + 0x38154) + iVar1;
  *(int *)(DAT_00887a80 + 0x38158) = *(int *)(DAT_00887a80 + 0x38158) - iVar1;
  *(uint *)(DAT_00887a80 + 0x3814c) = *(int *)(DAT_00887a80 + 0x3814c) + iVar1 & 0x7fff;
  *(int *)(DAT_00887a80 + 0x38150) = *(int *)(DAT_00887a80 + 0x38150) - iVar1;
  *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + iVar1;
  if (*(int *)(DAT_00887a80 + 0x38150) != 0) {
    if (*(int *)(DAT_00887a80 + 0x38140) != 0) {
      FUN_0054a450(*(int *)(DAT_00887a80 + 0x3814c) + DAT_00887a94,0,
                   *(int *)(DAT_00887a80 + 0x38150));
    }
    return 1;
  }
  *(undefined4 *)(DAT_00887a80 + 0x38150) = 0x1000;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054a450
// Address: 0054a450
// XREFS: FUN_0054a380
void FUN_0054a450(undefined4 *param_1,undefined1 param_2,uint param_3)
{
  uint uVar1;
  
  if (param_3 != 0) {
    for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *param_1 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      param_1 = param_1 + 1;
    }
    for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)param_1 = param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: deflate_deinit
// Address: 0054a490
// XREFS: rge_close
/* deflate_deinit */

void __cdecl deflate_deinit(int param_1)
{
  DAT_00887a80 = param_1;
  *(undefined4 *)(param_1 + 0x38178) = 0xabcd1234;
  return;
}

// --------------------------------------------------

// Function: deflate_init
// Address: 0054a4b0
// XREFS: rge_write
/* deflate_init */

undefined4 __cdecl
deflate_init(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)
{
  DAT_00887a80 = param_1;
  if (param_2 < 2) {
    param_2 = 1;
  }
  if (0x5db < param_2) {
    param_2 = 0x5dc;
  }
  *(int *)(param_1 + 0x38134) = param_2;
  *(undefined4 *)(DAT_00887a80 + 0x38138) = param_3;
  *(undefined4 *)(DAT_00887a80 + 0x3813c) = param_4;
  *(undefined4 *)(DAT_00887a80 + 0x38164) = param_5;
  *(undefined4 *)(DAT_00887a80 + 0x38168) = param_6;
  *(undefined4 *)(DAT_00887a80 + 0x38170) = *(undefined4 *)(DAT_00887a80 + 0x38164);
  *(undefined4 *)(DAT_00887a80 + 0x38174) = *(undefined4 *)(DAT_00887a80 + 0x38168);
  *(undefined4 *)(DAT_00887a80 + 0x3816c) = param_7;
  *(undefined4 *)(DAT_00887a80 + 0x38150) = 0x1000;
  FUN_0054a580();
  *(undefined4 *)(DAT_00887a80 + 0x38178) = 0x12345678;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054a580
// Address: 0054a580
// XREFS: deflate_init
void FUN_0054a580(void)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 2;
    *(undefined2 *)(DAT_00887a80 + 0x1d100 + iVar1) = 0xffff;
    *(undefined2 *)(DAT_00887a80 + 0xd100 + iVar1) = 0xffff;
  } while (iVar1 < 0x10000);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 2;
    *(undefined2 *)(DAT_00887a80 + 0x9100 + iVar1) = 0xffff;
  } while (iVar1 < 0x4000);
  *(int *)(DAT_00887a80 + 0x3670c) = DAT_00887a80 + 0x3610c;
  *(undefined4 *)(DAT_00887a80 + 0x36710) = 0x20;
  *(int *)(DAT_00887a80 + 0x36104) = DAT_00887a80 + 0x2d102;
  return;
}

// --------------------------------------------------

// Function: deflate_buf_size
// Address: 0054a610
// XREFS: rge_write
/* deflate_buf_size */

undefined4 __cdecl deflate_buf_size(void)
{
  return 0x3817c;
}

// --------------------------------------------------

// Function: _Inf32BufSize
// Address: 0054b0c5
// XREFS: rge_read
undefined4 _Inf32BufSize(void)
{
  return 0xad90;
}

// --------------------------------------------------

// Function: _Inf32Decode
// Address: 0054b0cb
// XREFS: rge_read
void _Inf32Decode(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 *param_6,int param_7,undefined4 param_8)
{
  *(undefined1 **)(param_7 + 0xad88) = &stack0xfffffffc;
  *(undefined1 **)(param_7 + 0xad8c) = &stack0xffffffe8;
  *(undefined4 *)(param_7 + 0x8228) = param_1;
  *(undefined4 *)(param_7 + 0x8230) = param_2;
  *(undefined4 *)(param_7 + 0x822c) = *param_3;
  *(int *)(param_7 + 0x8220) = *(int *)(param_7 + 0x8228) + *(int *)(param_7 + 0x8230);
  *(undefined4 *)(param_7 + 0x8224) = *(undefined4 *)(param_7 + 0x822c);
  *(undefined4 *)(param_7 + 0x8214) = param_4;
  *(undefined4 *)(param_7 + 0x821c) = param_5;
  *(undefined4 *)(param_7 + 0x8218) = *param_6;
  *(int *)(param_7 + 0x820c) = *(int *)(param_7 + 0x8214) + *(int *)(param_7 + 0x821c);
  *(undefined4 *)(param_7 + 0x8210) = *(undefined4 *)(param_7 + 0x8218);
  *(undefined4 *)(param_7 + 0xad80) = param_8;
                    /* WARNING: Could not recover jumptable at 0x0054b167. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_0054a854 + *(int *)(param_7 + 0xa958) * 4))();
  return;
}

// --------------------------------------------------

// Function: FUN_0054b16f
// Address: 0054b16f
// XREFS: None
longlong FUN_0054b16f(undefined4 param_1,uint param_2)
{
  return (ulonglong)param_2 << 0x20;
}

// --------------------------------------------------

// Function: FUN_0054b178
// Address: 0054b178
// XREFS: None
undefined8 FUN_0054b178(undefined4 param_1,undefined4 param_2)
{
  return CONCAT44(param_2,0xffffffff);
}

// --------------------------------------------------

// Function: FUN_0054b17f
// Address: 0054b17f
// XREFS: None
undefined8 FUN_0054b17f(undefined4 param_1,undefined4 param_2)
{
  return CONCAT44(param_2,0xfffffffe);
}

// --------------------------------------------------

// Function: _ImmAssociateContext@8
// Address: 0054b186
// XREFS: DisableIME, EnableIME, set_focus
void _ImmAssociateContext_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054b186. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ImmAssociateContext();
  return;
}

// --------------------------------------------------

// Function: _ImmSetOpenStatus@8
// Address: 0054b18c
// XREFS: TurnIMEOff, TurnIMEOn, set_focus
void _ImmSetOpenStatus_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054b18c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ImmSetOpenStatus();
  return;
}

// --------------------------------------------------

// Function: _ImmReleaseContext@8
// Address: 0054b192
// XREFS: ~TEditPanel
void _ImmReleaseContext_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054b192. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ImmReleaseContext();
  return;
}

// --------------------------------------------------

// Function: _ImmNotifyIME@16
// Address: 0054b198
// XREFS: ~TEditPanel
void _ImmNotifyIME_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054b198. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ImmNotifyIME();
  return;
}

// --------------------------------------------------

// Function: _ImmGetContext@4
// Address: 0054b19e
// XREFS: set_focus
void _ImmGetContext_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054b19e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ImmGetContext();
  return;
}

// --------------------------------------------------

// Function: _ICInfo@12
// Address: 0054b1a4
// XREFS: setup
void _ICInfo_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054b1a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ICInfo();
  return;
}

// --------------------------------------------------

// Function: _MCIWndCreateA
// Address: 0054b1aa
// XREFS: start_video
void _MCIWndCreateA(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054b1aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MCIWndCreateA();
  return;
}

// --------------------------------------------------

// Function: _CoUninitialize@0
// Address: 0054b1b0
// XREFS: None
void _CoUninitialize_0(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054b1b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CoUninitialize();
  return;
}

// --------------------------------------------------

// Function: _CoCreateInstance@20
// Address: 0054b1b6
// XREFS: None
void _CoCreateInstance_20(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054b1b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CoCreateInstance();
  return;
}

// --------------------------------------------------

// Function: _CoInitialize@4
// Address: 0054b1bc
// XREFS: None
void _CoInitialize_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054b1bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CoInitialize();
  return;
}

// --------------------------------------------------

// Function: _JumpToContinuation
// Address: 0054b1d0
// XREFS: FUN_0054ff70
/* void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *) */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)*unaff_FS_OFFSET;
                    /* WARNING: Could not recover jumptable at 0x0054b1fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1)();
  return;
}

// --------------------------------------------------

// Function: FUN_0054b1fd
// Address: 0054b1fd
// XREFS: None
void FUN_0054b1fd(void)
{
  return;
}

// --------------------------------------------------

// Function: _CallMemberFunction0
// Address: 0054b210
// XREFS: _DestructExceptionObject
/* void __stdcall _CallMemberFunction0(void *,void *) */

void _CallMemberFunction0(void *param_1,void *param_2)
{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0054b215. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_2)();
  return;
}

// --------------------------------------------------

// Function: _CallMemberFunction1
// Address: 0054b220
// XREFS: FUN_00550180
/* void __stdcall _CallMemberFunction1(void *,void *,void *) */

void _CallMemberFunction1(void *param_1,void *param_2,void *param_3)
{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0054b225. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_2)();
  return;
}

// --------------------------------------------------

// Function: _CallMemberFunction2
// Address: 0054b230
// XREFS: FUN_00550180
/* void __stdcall _CallMemberFunction2(void *,void *,void *,int) */

void _CallMemberFunction2(void *param_1,void *param_2,void *param_3,int param_4)
{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0054b235. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_2)();
  return;
}

// --------------------------------------------------

// Function: _UnwindNestedFrames
// Address: 0054b240
// XREFS: FUN_0054b460, FUN_0054ff70
/* void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *) */

void _UnwindNestedFrames(EHRegistrationNode *param_1,EHExceptionRecord *param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  
  puVar1 = (undefined4 *)*unaff_FS_OFFSET;
  _RtlUnwind_16(param_1,0x54b26c,param_2,0);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
  *puVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = puVar1;
  return;
}

// --------------------------------------------------

// Function: ___CxxFrameHandler
// Address: 0054b2a0
// XREFS: FUN_0055c0b8, FUN_0055c0d8, FUN_0055c106, FUN_0055c11b, FUN_0055c138, FUN_0055c15b, FUN_0055c17b, FUN_0055c198, FUN_0055c1b8, FUN_0055c1f1, FUN_0055c24d, FUN_0055c2ad (... +591 more)
undefined4
___CxxFrameHandler(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 uVar1;
  
  uVar1 = ___InternalCxxFrameHandler(param_1,param_2,param_3,param_4);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0054b2dc
// Address: 0054b2dc
// XREFS: None
void FUN_0054b2dc(int param_1)
{
  ___FrameUnwindToState
            (*(undefined4 *)(param_1 + 0x18),0,*(undefined4 *)(param_1 + 0x28),
             *(undefined4 *)(param_1 + 0x1c));
  return;
}

// --------------------------------------------------

// Function: _CallCatchBlock2
// Address: 0054b300
// XREFS: FUN_00550000
/* void * __cdecl _CallCatchBlock2(struct EHRegistrationNode *,struct _s_FuncInfo const *,void
   *,int,unsigned long) */

void * __cdecl
_CallCatchBlock2(EHRegistrationNode *param_1,_s_FuncInfo *param_2,void *param_3,int param_4,
                ulong param_5)
{
  void *pvVar1;
  int *unaff_FS_OFFSET;
  int local_18;
  code *local_14;
  _s_FuncInfo *local_10;
  EHRegistrationNode *local_c;
  int local_8;
  
  local_8 = param_4 + 1;
  local_14 = FUN_0054b360;
  local_10 = param_2;
  local_c = param_1;
  local_18 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_18;
  pvVar1 = (void *)__CallSettingFrame_12(param_3,param_1,param_5);
  *unaff_FS_OFFSET = local_18;
  return pvVar1;
}

// --------------------------------------------------

// Function: FUN_0054b360
// Address: 0054b360
// XREFS: _CallCatchBlock2
void FUN_0054b360(undefined4 param_1,int param_2,undefined4 param_3)
{
  ___InternalCxxFrameHandler
            (param_1,*(undefined4 *)(param_2 + 0xc),param_3,0,*(undefined4 *)(param_2 + 8),
             *(undefined4 *)(param_2 + 0x10),param_2,0);
  return;
}

// --------------------------------------------------

// Function: _CallSETranslator
// Address: 0054b390
// XREFS: FUN_0054fdc0
/* int __cdecl _CallSETranslator(struct EHExceptionRecord *,struct EHRegistrationNode *,void *,void
   *,struct _s_FuncInfo const *,int,struct EHRegistrationNode *) */

int __cdecl
_CallSETranslator(EHExceptionRecord *param_1,EHRegistrationNode *param_2,void *param_3,void *param_4
                 ,_s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7)
{
  int *unaff_FS_OFFSET;
  EHExceptionRecord *local_34;
  void *local_30;
  undefined4 *local_2c;
  code *local_28;
  _s_FuncInfo *local_24;
  EHRegistrationNode *local_20;
  int local_1c;
  EHRegistrationNode *local_18;
  undefined4 local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;
  
  local_c = &stack0xfffffffc;
  local_10 = &stack0xffffffbc;
  local_28 = FUN_0054b460;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x54b42a;
  local_2c = (undefined4 *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_2c;
  local_34 = param_1;
  local_30 = param_3;
  (*__pSETranslator)(*(uint *)param_1,(_EXCEPTION_POINTERS *)&local_34);
  if (local_8 == 0) {
    *unaff_FS_OFFSET = (int)local_2c;
  }
  else {
    *local_2c = *(undefined4 *)*unaff_FS_OFFSET;
    *unaff_FS_OFFSET = (int)local_2c;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0054b460
// Address: 0054b460
// XREFS: _CallSETranslator
undefined4 FUN_0054b460(EHExceptionRecord *param_1,EHRegistrationNode *param_2,undefined4 param_3)
{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 4) & 0x66) != 0) {
    *(undefined4 *)(param_2 + 0x24) = 1;
    return 1;
  }
  ___InternalCxxFrameHandler
            (param_1,*(undefined4 *)(param_2 + 0xc),param_3,0,*(undefined4 *)(param_2 + 8),
             *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),1);
  if (*(int *)(param_2 + 0x24) == 0) {
    _UnwindNestedFrames(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x0054b4d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(param_2 + 0x18))();
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0054b4d7
// Address: 0054b4d7
// XREFS: None
undefined4 FUN_0054b4d7(void)
{
  return 1;
}

// --------------------------------------------------

// Function: _GetRangeOfTrysToCheck
// Address: 0054b4f0
// XREFS: FUN_0054fb10, FUN_0054fdc0
/* struct _s_TryBlockMapEntry const * __cdecl _GetRangeOfTrysToCheck(struct _s_FuncInfo const
   *,int,int,unsigned int *,unsigned int *) */

_s_TryBlockMapEntry * __cdecl
_GetRangeOfTrysToCheck(_s_FuncInfo *param_1,int param_2,int param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = *(int *)(param_1 + 0x10);
  uVar3 = *(uint *)(param_1 + 0xc);
  uVar4 = uVar3;
  uVar5 = uVar3;
  if (-1 < param_2) {
    do {
      if (uVar4 == 0xffffffff) {
        _inconsistency();
      }
      uVar4 = uVar4 - 1;
      iVar1 = iVar2 + uVar4 * 0x14;
      if (((*(int *)(iVar1 + 4) < param_3) && (param_3 <= *(int *)(iVar1 + 8))) ||
         (uVar4 == 0xffffffff)) {
        param_2 = param_2 + -1;
        uVar3 = uVar5;
        uVar5 = uVar4;
      }
    } while (-1 < param_2);
  }
  uVar4 = uVar4 + 1;
  *param_4 = uVar4;
  *param_5 = uVar3;
  if ((*(uint *)(param_1 + 0xc) < uVar3) || (uVar3 < uVar4)) {
    _inconsistency();
  }
  return (_s_TryBlockMapEntry *)(iVar2 + uVar4 * 0x14);
}

// --------------------------------------------------

// Function: __global_unwind2
// Address: 0054b570
// XREFS: FUN_00554dea
void __global_unwind2(undefined4 param_1)
{
  _RtlUnwind_16(param_1,0x54b588,0,0,&stack0xfffffffc);
  return;
}

// --------------------------------------------------

// Function: FUN_0054b590
// Address: 0054b590
// XREFS: __abnormal_termination, __local_unwind2
undefined4 FUN_0054b590(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(uint *)(param_1 + 4) & 6) != 0) {
    *param_4 = param_2;
    uVar1 = 3;
  }
  return uVar1;
}

// --------------------------------------------------

// Function: __local_unwind2
// Address: 0054b5b2
// XREFS: FUN_005500b6, FUN_00554dea, __seh_longjmp_unwind@4
void __local_unwind2(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  pcStack_18 = FUN_0054b590;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      __NLG_Notify(0x101);
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}

// --------------------------------------------------

// Function: __abnormal_termination
// Address: 0054b61a
// XREFS: FUN_005500ea
undefined4 __abnormal_termination(void)
{
  int iVar1;
  undefined4 uVar2;
  int *unaff_FS_OFFSET;
  
  uVar2 = 0;
  iVar1 = *unaff_FS_OFFSET;
  if ((*(code **)(iVar1 + 4) == FUN_0054b590) &&
     (*(int *)(iVar1 + 8) == *(int *)(*(int *)(iVar1 + 0xc) + 0xc))) {
    uVar2 = 1;
  }
  return uVar2;
}

// --------------------------------------------------

// Function: __NLG_Notify1
// Address: 0054b63d
// XREFS: __CallSettingFrame@12
void __fastcall __NLG_Notify1(undefined4 param_1)
{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_0058fb58 = param_1;
  DAT_0058fb54 = in_EAX;
  DAT_0058fb5c = unaff_EBP;
  return;
}

// --------------------------------------------------

// Function: __NLG_Notify
// Address: 0054b646
// XREFS: FUN_00554dea, __local_unwind2
void __NLG_Notify(void)
{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_0058fb58 = *(undefined4 *)(unaff_EBP + 8);
  DAT_0058fb54 = in_EAX;
  DAT_0058fb5c = unaff_EBP;
  return;
}

// --------------------------------------------------

// Function: operator_delete
// Address: 0054b660
// XREFS: AllocateQueue, ClearLobbyInfo, ClearRXForPlayer, ClearRXandTX, CommOut, DeleteArrays, DeleteMasks, DeleteSurfaces, ExecuteIncoming, FUN_0055c110, FUN_0055c400, FUN_0055c40b (... +267 more)
/* void __cdecl operator delete(void *) */

void __cdecl operator_delete(void *param_1)
{
  free(param_1);
  return;
}

// --------------------------------------------------

// Function: __fpmath
// Address: 0054b670
// XREFS: __FPinit, __cinit
void __fpmath(void)
{
  __cfltcvt_init();
  ___fastflag._4_4_ = __ms_p5_mp_test_fdiv();
  __setdefaultprecision();
  return;
}

// --------------------------------------------------

// Function: FUN_0054b687
// Address: 0054b687
// XREFS: None
void FUN_0054b687(void)
{
  return;
}

// --------------------------------------------------

// Function: __cfltcvt_init
// Address: 0054b6a0
// XREFS: __fpmath
void __cfltcvt_init(void)
{
  PTR___fptrap_0058fbcc = (undefined *)0x5506c0;
  __cfltcvt_tab = (undefined *)0x550b00;
  PTR___fptrap_0058fbd0 = (undefined *)0x550750;
  PTR___fptrap_0058fbd4 = __forcdecpt;
  PTR___fptrap_0058fbd8 = (undefined *)0x550730;
  PTR___fptrap_0058fbdc = (undefined *)0x550b00;
  return;
}

// --------------------------------------------------

// Function: FUN_0054b6d8
// Address: 0054b6d8
// XREFS: None
undefined4 FUN_0054b6d8(undefined4 param_1)
{
  undefined4 uVar1;
  
  uVar1 = ___fastflag._0_4_;
  ___fastflag._0_4_ = param_1;
  return uVar1;
}

// --------------------------------------------------

// Function: operator_new
// Address: 0054b6f0
// XREFS: AddItem, AllocateQueue, BaseObject, BuildAIModule, CheckForLobbyLaunch, CommOut, ConstructionAIModule, CreateMasks, CreateSurfaces, InfluenceMap, InitializeTextValues, IsDPlay501a (... +339 more)
/* void * __cdecl operator new(unsigned int) */

void * __cdecl operator_new(uint param_1)
{
  void *pvVar1;
  
  pvVar1 = (void *)__nh_malloc(param_1,1);
  return pvVar1;
}

// --------------------------------------------------

// Function: __ftol
// Address: 0054b700
// XREFS: AddResource, AddingCircle, Get_Closest_Resource, PathingSystem, RGE_Action_Enter, RGE_Active_Animated_Sprite, RGE_fade_palette, RGE_fade_palette_step, TRIBE_Building_Object, TribeDiplomacyDialog, action, addEnemyInfluences (... +254 more)
longlong __ftol(void)
{
  float10 in_ST0;
  
  return (longlong)ROUND(in_ST0);
}

// --------------------------------------------------

// Function: calloc
// Address: 0054b730
// XREFS: AddChatMsg, CreateBlitQueue, DClipInfo_List, DPlayGetSessionDesc, FUN_00553eeb, FUN_00554659, Init, Init_Tile_Edge_Tables, RGE_Campaign, RGE_Campaign_Info, RGE_Doppleganger_Creator, RGE_Effects (... +161 more)
/* calloc */

undefined4 * __cdecl calloc(int param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar4 = param_2 * param_1;
  if (uVar4 < 0xffffffe1) {
    if (uVar4 == 0) {
      uVar4 = 0x10;
    }
    else {
      uVar4 = uVar4 + 0xf & 0xfffffff0;
    }
  }
  do {
    puVar3 = (undefined4 *)0x0;
    if (uVar4 < 0xffffffe1) {
      if (___sbh_threshold < uVar4) {
LAB_0054b790:
        if (puVar3 != (undefined4 *)0x0) {
          return puVar3;
        }
      }
      else {
        puVar3 = (undefined4 *)___sbh_alloc_block(uVar4 >> 4);
        if (puVar3 != (undefined4 *)0x0) {
          puVar5 = puVar3;
          for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          for (uVar2 = uVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined1 *)puVar5 = 0;
            puVar5 = (undefined4 *)((int)puVar5 + 1);
          }
          goto LAB_0054b790;
        }
      }
      puVar3 = (undefined4 *)HeapAlloc(__crtheap,8,uVar4);
    }
    if ((puVar3 != (undefined4 *)0x0) || (__newmode == 0)) {
      return puVar3;
    }
    iVar1 = __callnewh(uVar4);
    if (iVar1 == 0) {
      return (undefined4 *)0x0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: free
// Address: 0054b7d0
// XREFS: AddChatMsg, AddResource, Build_Distance_Table, Check_shape, ClearChat, CreateBlitQueue, DPlayGetSessionDesc, DibCheckTrans, FUN_005541c8, FUN_00554659, FUN_00554f71, FUN_00556d0f (... +192 more)
/* free */

void __cdecl free(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 local_4;
  
  iVar1 = param_1;
  if (param_1 != 0) {
    iVar2 = ___sbh_find_block(param_1,&local_4,&param_1);
    if (iVar2 != 0) {
      ___sbh_free_block(local_4,param_1,iVar2);
      return;
    }
    HeapFree(__crtheap,0,iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: fprintf
// Address: 0054b820
// XREFS: add_doppleganger_check, calc_timings, debug_random_write, doMove, doTrivialMove, dump_vismap_log, expand_allocations, findPath, huntObject, load_game, logCommonHistory, logDebug (... +17 more)
/* fprintf */

undefined4 __cdecl fprintf(undefined4 param_1,undefined4 param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = __stbuf(param_1);
  uVar2 = __output(param_1,param_2,&stack0x0000000c);
  __ftbuf(uVar1,param_1);
  return uVar2;
}

// --------------------------------------------------

// Function: strncpy
// Address: 0054b860
// XREFS: AIModuleID, BaseItem, BaseObject, FUN_00554f71, MakeFileList, TDigital, TXChat, TribeMPStartupScreen, __NMSG_WRITE, __mbsnbcpy, __mbsncpy, __tzset (... +29 more)
/* strncpy */

uint * __cdecl strncpy(uint *param_1,uint *param_2,uint param_3)
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (param_3 == 0) {
    return param_1;
  }
  puVar5 = param_1;
  if (((uint)param_2 & 3) != 0) {
    while( true ) {
      uVar4 = *param_2;
      param_2 = (uint *)((int)param_2 + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      param_3 = param_3 - 1;
      if (param_3 == 0) {
        return param_1;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)param_2 & 3) == 0) {
        uVar4 = param_3 >> 2;
        goto joined_r0x0054b89e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = param_3 >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_0054b8db;
        goto LAB_0054b949;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      param_3 = param_3 - 1;
    } while (param_3 != 0);
    return param_1;
  }
  uVar4 = param_3 >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *param_2;
      uVar2 = *param_2;
      param_2 = param_2 + 1;
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x0054b945:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_0054b949:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          param_3 = param_3 & 3;
          if (param_3 != 0) goto LAB_0054b8db;
          return param_1;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x0054b945;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x0054b945;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x0054b945;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x0054b89e:
    } while (uVar4 != 0);
    param_3 = param_3 & 3;
    if (param_3 == 0) {
      return param_1;
    }
  }
  do {
    cVar3 = (char)*param_2;
    param_2 = (uint *)((int)param_2 + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (param_3 = param_3 - 1, param_3 != 0) {
LAB_0054b8db:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return param_1;
    }
    param_3 = param_3 - 1;
  } while (param_3 != 0);
  return param_1;
}

// --------------------------------------------------

// Function: remove
// Address: 0054b960
// XREFS: __unlink
/* remove */

undefined4 __cdecl remove(undefined4 param_1)
{
  int iVar1;
  
  iVar1 = DeleteFileA(param_1);
  if (iVar1 == 0) {
    iVar1 = GetLastError();
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 != 0) {
    __dosmaperr(iVar1);
    return 0xffffffff;
  }
  return 0;
}

// --------------------------------------------------

// Function: __unlink
// Address: 0054b990
// XREFS: Load, action, loadBuildList, loadConstructionPlan, loadRules, loadTechnologyTree, save_game, save_scenario
void __unlink(undefined4 param_1)
{
  remove(param_1);
  return;
}

// --------------------------------------------------

// Function: strstr
// Address: 0054b9a0
// XREFS: TRIBE_Screen_Sed, __mbsstr, check_prog_argument, contains, loadBuildList, loadConstructionPlan, loadRules, loadTechnologyTree, make_font, numberOfFilesWithFilenameOrAttribute, processCheatCode, setup (... +1 more)
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
// XREFS: CloseLog, FUN_0055878e, Load, LogChecksums, RESFILE_build_res_file, RGE_Color_Table, RGE_Effects, RGE_RMM_Database_Controller, TRIBE_Tech, action, data_load, data_load_color_tables (... +27 more)
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

// Function: sscanf
// Address: 0054baa0
// XREFS: loadBuildList, loadConstructionPlan, loadPlays, loadRules, loadTechnologyTree, processCheatCode, setup
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

// Function: fgets
// Address: 0054baf0
// XREFS: loadBuildList, loadConstructionPlan, loadPlays, loadRules, loadTechnologyTree
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

// Function: __fsopen
// Address: 0054bb70
// XREFS: fopen
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

// Function: fopen
// Address: 0054bba0
// XREFS: LogChecksums, OpenLog, RESFILE_Extract_to_File, RESFILE_build_res_file, RGE_Color_Table, RGE_Doppleganger_Creator, RGE_Effects, RGE_Game_World, RGE_RMM_Database_Controller, TRIBE_Tech, action, data_load (... +25 more)
/* fopen */

void __cdecl fopen(undefined4 param_1,undefined4 param_2)
{
  __fsopen(param_1,param_2,0x40);
  return;
}

// --------------------------------------------------

// Function: sprintf
// Address: 0054bbc0
// XREFS: AddChatMsg, DoChecksum, DoCycle, DropDeadPlayer, EnumPlayersCallback2, EvaluateSystemMessage, ExecuteIncoming, GetAvgInfo, GetCommInfo, GetElapsedFirstCall, GetHiLoInfo, GetHiLoMaxInfo (... +125 more)
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

// Function: asctime
// Address: 0054bc30
// XREFS: Time, ctime, logStatus, setLogCommonHistory
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

// Function: FUN_0054bd20
// Address: 0054bd20
// XREFS: asctime
char * FUN_0054bd20(char *param_1,int param_2)
{
  *param_1 = (((char)(param_2 / 10) + (char)(param_2 >> 0x1f)) -
             (char)((longlong)param_2 * 0x66666667 >> 0x3f)) + '0';
  param_1[1] = (char)(param_2 % 10) + '0';
  return param_1 + 2;
}

// --------------------------------------------------

// Function: localtime
// Address: 0054bd60
// XREFS: FUN_0054ca20, Time, ctime, logStatus, setLogCommonHistory
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

// Function: time
// Address: 0054bf50
// XREFS: Log, RGE_Scenario_Header, Time, check_expiration, logStatus, run_log, setLogCommonHistory
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

// Function: fflush
// Address: 0054c080
// XREFS: FUN_0054c150, FlushLog, Log, calc_timings, logCommonHistory, osfx, write_draw_log
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

// Function: __flush
// Address: 0054c0d0
// XREFS: __ftbuf, fclose, fflush, fseek, fwrite, rewind
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

// Function: __flushall
// Address: 0054c140
// XREFS: FUN_00553fa9
void __flushall(void)
{
  FUN_0054c150(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0054c150
// Address: 0054c150
// XREFS: __flushall, fflush
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

// Function: vsprintf
// Address: 0054c1d0
// XREFS: Log, logCommonHistory, logDebug, logMessage, sendChatMessage
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

// Function: rewind
// Address: 0054c240
// XREFS: loadPlays
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
// XREFS: MakeFileList, action, create_game, fillList, fill_campaign_drop, fill_scenario_list, find_campaigns, load_campaign, make_campaign, numberOfFilesWithAttribute, numberOfFilesWithFilename, numberOfFilesWithFilenameOrAttribute (... +6 more)
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
// XREFS: None
char __fastcall FUN_0054c39e(undefined4 param_1,undefined4 param_2)
{
  char in_AL;
  
  return in_AL + (char)((uint)param_2 >> 8);
}

// --------------------------------------------------

// Function: __findnext
// Address: 0054c3d0
// XREFS: MakeFileList, fillList, fill_campaign_drop, fill_scenario_list, find_campaigns, numberOfFilesWithAttribute, numberOfFilesWithFilename, numberOfFilesWithFilenameOrAttribute, reload_scenarios
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
// XREFS: None
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
// XREFS: __findfirst, __findnext
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

// Function: malloc
// Address: 0054c5a0
// XREFS: AddResource, Build_Distance_Table, DString, DibCheckTrans, FUN_0054eb25, FUN_00554659, FUN_00554f71, FUN_00556d0f, FUN_00559eba, FUN_0055a6a0, InitNewZone, Load (... +46 more)
/* malloc */

void __cdecl malloc(undefined4 param_1)
{
  __nh_malloc(param_1,__newmode);
  return;
}

// --------------------------------------------------

// Function: __nh_malloc
// Address: 0054c5c0
// XREFS: malloc, operator_new
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

// Function: __heap_alloc
// Address: 0054c610
// XREFS: __nh_malloc
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

// Function: atol
// Address: 0054c650
// XREFS: ReadPalette, __tzset, atoi, setup_cmd_options
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

// Function: atoi
// Address: 0054c6f0
// XREFS: GetTauntNo, ReadPalette, action, asInt, make_font, randomComputerName, save_multi_victory_cond_in_scenario, save_victory_cond_in_scenario, set_player
/* atoi */

void __cdecl atoi(undefined4 param_1)
{
  atol(param_1);
  return;
}

// --------------------------------------------------

// Function: __atoi64
// Address: 0054c700
// XREFS: None
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

// Function: __mbsncat
// Address: 0054c7d0
// XREFS: setup, setup_cmd_options
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

// Function: __ismbcspace
// Address: 0054c8a0
// XREFS: get_trimmed_str, is_blank, setup, setup_cmd_options, word_wrap_append
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

// Function: __mbsninc
// Address: 0054c940
// XREFS: delete_character, insert_character, paste, setup, setup_cmd_options, word_wrap_append
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

// Function: __mbsstr
// Address: 0054c960
// XREFS: setup, setup_cmd_options
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

// Function: mktime
// Address: 0054ca00
// XREFS: check_expiration
/* mktime */

void __cdecl mktime(undefined4 param_1)
{
  FUN_0054ca20(param_1,1);
  return;
}

// --------------------------------------------------

// Function: __mkgmtime
// Address: 0054ca10
// XREFS: None
void __mkgmtime(undefined4 param_1)
{
  FUN_0054ca20(param_1,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0054ca20
// Address: 0054ca20
// XREFS: __mkgmtime, mktime
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

// Function: srand
// Address: 0054cc60
// XREFS: debug_srand
/* srand */

void __cdecl srand(undefined4 param_1)
{
  DAT_0058fb80 = param_1;
  return;
}

// --------------------------------------------------

// Function: rand
// Address: 0054cc70
// XREFS: debug_rand
/* rand */

uint __cdecl rand(void)
{
  DAT_0058fb80 = DAT_0058fb80 * 0x343fd + 0x269ec3;
  return DAT_0058fb80 >> 0x10 & 0x7fff;
}

// --------------------------------------------------

// Function: close
// Address: 0054cca0
// XREFS: Get_BuildList, Get_CityPlan, Get_player_AI, Init_Tile_Edge_Tables, RESFILE_build_res_file, RESFILE_close_new_resource_file, RGE_Campaign, RGE_Flic_Player, ReadPalette, TRIBE_Credits_Screen, TShape, __sopen (... +8 more)
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

// Function: read
// Address: 0054cd80
// XREFS: Init_Tile_Edge_Tables, RESFILE_build_res_file, RESFILE_load, RESFILE_open_new_resource_file, RGE_Campaign, RGE_Flic_Player, ReadPalette, TRIBE_Credits_Screen, TShape, __filbuf, __sopen, create_file (... +7 more)
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

// Function: __open
// Address: 0054cfe0
// XREFS: Get_BuildList, Get_CityPlan, Get_player_AI, Init_Tile_Edge_Tables, RESFILE_build_res_file, RESFILE_open_new_resource_file, RGE_Campaign, RGE_Flic_Player, ReadPalette, TRIBE_Credits_Screen, TShape, create_file (... +8 more)
void __open(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  __sopen(param_1,param_2,0x40,param_3);
  return;
}

// --------------------------------------------------

// Function: __sopen
// Address: 0054d000
// XREFS: __open, __openfile
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
// XREFS: Init_Tile_Edge_Tables, RGE_Flic_Player, ReadPalette, TRIBE_Credits_Screen, TShape, create_file, rge_open, save, setup
void __tell(undefined4 param_1)
{
  lseek(param_1,0,1);
  return;
}

// --------------------------------------------------

// Function: lseek
// Address: 0054d3e0
// XREFS: Init_Tile_Edge_Tables, RESFILE_build_res_file, RESFILE_load, RESFILE_open_new_resource_file, RGE_Flic_Player, ReadPalette, TRIBE_Credits_Screen, TShape, __chsize, __flsbuf, __sopen, __tell (... +12 more)
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

// Function: write
// Address: 0054d4a0
// XREFS: Get_BuildList, Get_CityPlan, Get_player_AI, RESFILE_build_res_file, __chsize, __flsbuf, __flush, create_file, fwrite, rge_buffer_full, rge_write, rge_write_uncompressed (... +1 more)
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

// Function: fscanf
// Address: 0054d6c0
// XREFS: RESFILE_build_res_file, RGE_Color_Table, RGE_Effects, RGE_Master_Player, RGE_RMM_Database_Controller, RGE_Sound, RGE_Sprite, TRIBE_Tech, data_load_color_tables, data_load_objects, data_load_players, data_load_sounds (... +8 more)
/* fscanf */

void __cdecl fscanf(undefined4 param_1,undefined4 param_2)
{
  __input(param_1,param_2,&stack0x0000000c);
  return;
}

// --------------------------------------------------

// Function: `eh_vector_constructor_iterator'
// Address: 0054d6e0
// XREFS: AllocateQueue, RGE_Communications_Addresses, TCommunications_Handler
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
// XREFS: None
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
// XREFS: `eh_vector_constructor_iterator'
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
// XREFS: None
void FUN_0054d76c(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: `eh_vector_destructor_iterator'
// Address: 0054d780
// XREFS: AllocateQueue, `vector_deleting_destructor', ~RGE_Communications_Addresses, ~RGE_Communications_Queue, ~TCommunications_Handler
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
// XREFS: None
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
// XREFS: `eh_vector_destructor_iterator'
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
// XREFS: None
void FUN_0054d810(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: __ArrayUnwind
// Address: 0054d830
// XREFS: FUN_0054d758, FUN_0054d7f9
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
// XREFS: None
void FUN_0054d870(void)
{
  int unaff_EBP;
  
  FUN_0054d8a0(*(undefined4 *)(unaff_EBP + -0x14));
  return;
}

// --------------------------------------------------

// Function: FUN_0054d87d
// Address: 0054d87d
// XREFS: None
void FUN_0054d87d(void)
{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_0054d8a0
// Address: 0054d8a0
// XREFS: FUN_0054d870
undefined4 FUN_0054d8a0(undefined4 *param_1)
{
  if (*(int *)*param_1 == -0x1f928c9d) {
    terminate();
  }
  return 0;
}

// --------------------------------------------------

// Function: fputs
// Address: 0054d8c0
// XREFS: Log, LogChecksums
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

// Function: strncat
// Address: 0054d910
// XREFS: Log, __mbsncat
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
// XREFS: Log, run_log
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

// Function: memset
// Address: 0054da60
// XREFS: CheckSurface, CheckSurfaces, Clear, CreateSurfaces, DrawHorzLine, FillRect, Init, SetSize, TDrawArea, clear_image, ds_stream_file, ds_stream_time_func (... +8 more)
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
// XREFS: DibBlt, DibCopy, DibMapToPalette, DibWriteClipped, ReadPalette, TransDibBlt, _DSFillSoundBuffer, _WaveOpenFile, _WaveReadFile, shape_draw_clipped, shape_draw_unclipped
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void FUN_0054db99(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_0054dc06
// Address: 0054dc06
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: ReadPalette
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

// Function: __alloca_probe
// Address: 0054dee0
// XREFS: RGE_RMM_Controller, TribeAboutDialog, _WinMain@16, __chsize, action, add_object_module, fillList, new_game, operator<<, paste, set_text, setup
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
// XREFS: BUILDRES_get_files_resource_type
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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

// Function: isspace
// Address: 0054e000
// XREFS: FUN_00553090, __input, eatwhite, moveToNextWord, nextWord, numWords, operator>>, word
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
bool FUN_0054e11a(uint param_1)
{
  return param_1 < 0x80;
}

// --------------------------------------------------

// Function: FUN_0054e12d
// Address: 0054e12d
// XREFS: None
uint FUN_0054e12d(uint param_1)
{
  return param_1 & 0x7f;
}

// --------------------------------------------------

// Function: FUN_0054e138
// Address: 0054e138
// XREFS: None
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
// XREFS: None
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

// Function: atof
// Address: 0054e1e0
// XREFS: asDouble
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
// XREFS: None
int FUN_0054e237(int param_1)
{
  return param_1 + -0x20;
}

// --------------------------------------------------

// Function: toupper
// Address: 0054e250
// XREFS: __getdrive, char_action, operator<<, uppercase
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
// XREFS: None
int FUN_0054e34c(int param_1)
{
  return param_1 + 0x20;
}

// --------------------------------------------------

// Function: tolower
// Address: 0054e360
// XREFS: BUILDRES_get_files_resource_type, __forcdecpt, __strnicmp, lowercase, stricmp
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

// Function: __getdrive
// Address: 0054e460
// XREFS: DriveInformation
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

// Function: __chdrive
// Address: 0054e4b0
// XREFS: changeDrive, checkDrives
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

// Function: __chdir
// Address: 0054e510
// XREFS: changeDirectory
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

// Function: __splitpath
// Address: 0054e5b0
// XREFS: updateDirectory
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

// Function: __getcwd
// Address: 0054e730
// XREFS: updateDirectory
void __getcwd(undefined4 param_1,undefined4 param_2)
{
  __getdcwd(0,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: __getdcwd
// Address: 0054e750
// XREFS: __getcwd
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

// Function: __validdrive
// Address: 0054e880
// XREFS: __getdcwd
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
// XREFS: changeInfluenceMap, contains, doMove, doTrivialMove, findPath, findTilePath, passable
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
// XREFS: None
int __fastcall FUN_0054e9b9(undefined4 param_1,int param_2)
{
  return param_2 + -1;
}

// --------------------------------------------------

// Function: FUN_0054e9c5
// Address: 0054e9c5
// XREFS: None
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
// XREFS: TribeMPStartupScreen, __mbschr, get_palette, play, save_game, set_background, set_background2, set_button_pics, set_special_events, set_text, setup, setup_cmd_options
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
// XREFS: atexit
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

// Function: atexit
// Address: 0054eb10
// XREFS: $E11, $E16, $E21, $E3
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
// XREFS: None
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

// Function: stricmp
// Address: 0054eb70
// XREFS: check_for_cd, set_background, set_background2, set_button_pics, set_palette, set_special_events, setup
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
// XREFS: ___crtsetenv, char_action, load_game, set_text, verify_char
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

// Function: __mbscmp
// Address: 0054ecb0
// XREFS: char_action, verify_char
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

// Function: __mbsinc
// Address: 0054ed80
// XREFS: __mbsstr, delete_character, get_trimmed_str, insert_character, is_blank, word_wrap_append
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

// Function: __mbsdec
// Address: 0054eda0
// XREFS: delete_character, get_trimmed_str, word_wrap_append
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

// Function: __mbsncpy
// Address: 0054ee10
// XREFS: calc_line_pos, delete_character, get_trimmed_str, insert_character, paste, word_wrap_append
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

// Function: __mbslen
// Address: 0054eea0
// XREFS: calc_cur_line_col, calc_input_pos, calc_line_pos, char_action, key_down_action, paste, set_text, word_wrap_append
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

// Function: __mbscpy
// Address: 0054eef0
// XREFS: set_text
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
// XREFS: None
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

