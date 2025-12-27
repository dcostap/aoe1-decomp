undefined4 FUN_00547b30(void)

{
  int iVar1;
  
  while( true ) {
    iVar1 = FUN_0054a380();
    if ((iVar1 != 0) && (*(int *)(DAT_00887a80 + 0x38140) == 0)) {
      return 0;
    }
    if (*(int *)(DAT_00887a80 + 0x38144) != 0) {
      FUN_00547ef0(*(undefined4 *)(DAT_00887a80 + 0x38148));
    }
    FUN_00547f40(*(undefined4 *)(DAT_00887a80 + 0x38148),*(undefined4 *)(DAT_00887a80 + 0x38124));
    if (*(int *)(DAT_00887a80 + 0x38148) == 0) {
      FUN_00547c90(DAT_00887a80 + 0x8000,DAT_00887a80,0x1102);
    }
    iVar1 = FUN_00549460(*(undefined4 *)(DAT_00887a80 + 0x38148));
    if (iVar1 != 0) {
      return 1;
    }
    *(int *)(DAT_00887a80 + 0x38148) = *(int *)(DAT_00887a80 + 0x38148) + 0x1000;
    if (*(int *)(DAT_00887a80 + 0x38148) == 0x8000) {
      *(int *)(DAT_00887a80 + 0x38148) = 0;
      *(undefined4 *)(DAT_00887a80 + 0x38144) = 1;
    }
    if ((*(int *)(DAT_00887a80 + 0x38140) != 0) && (*(int *)(DAT_00887a80 + 0x38158) == 0)) break;
    *(undefined4 *)(DAT_00887a80 + 0x38124) = 0;
  }
  iVar1 = FUN_0054a360();
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = FUN_00548030();
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = FUN_00547d50();
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = FUN_00547cf0();
  if (iVar1 != 0) {
    return 1;
  }
  *(undefined4 *)(DAT_00887a80 + 0x38178) = 0xabcd1234;
  return 1;
}



void FUN_00547c90(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (0xf < (int)param_3) {
    uVar3 = param_3 >> 4;
    param_3 = param_3 + uVar3 * -0x10;
    puVar2 = param_1;
    puVar4 = param_2;
    do {
      param_2 = puVar4 + 4;
      *puVar2 = *puVar4;
      param_1 = puVar2 + 4;
      uVar3 = uVar3 - 1;
      puVar2[1] = puVar4[1];
      puVar2[2] = puVar4[2];
      puVar2[3] = puVar4[3];
      puVar2 = param_1;
      puVar4 = param_2;
    } while (uVar3 != 0);
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    uVar1 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    *(undefined1 *)param_1 = uVar1;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}



undefined4 FUN_00547cf0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(DAT_00887a80 + 0x3816c))
                    (*(undefined4 *)(DAT_00887a80 + 0x38164),
                     *(int *)(DAT_00887a80 + 0x38168) - DAT_00887a88);
  if (iVar1 != 0) {
    return 1;
  }
  DAT_00887a90 = *(undefined4 *)(DAT_00887a80 + 0x38164);
  DAT_00887a88 = *(undefined4 *)(DAT_00887a80 + 0x38168);
  return 0;
}



undefined4 FUN_00547d50(void)

{
  int iVar1;
  
  iVar1 = FUN_00547d80(0,7);
  if (iVar1 != 0) {
    return 1;
  }
  DAT_00886cf4 = 0;
  return 0;
}



undefined4 FUN_00547d80(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00887a88;
  if (DAT_00887a84 != 0) {
    *(int *)(DAT_00887a80 + 0x3811c) = *(int *)(DAT_00887a80 + 0x3811c) + param_2;
    return 0;
  }
  DAT_00887a8c = DAT_00887a8c | param_1 << ((byte)DAT_00886cf4 & 0x1f);
  DAT_00886cf4 = DAT_00886cf4 + param_2;
  if (DAT_00886cf4 < 8) {
    return 0;
  }
  if (DAT_00886cf4 < 0x10) {
    DAT_00887a88 = DAT_00887a88 + -1;
    if (-1 < DAT_00887a88) {
      *(undefined1 *)DAT_00887a90 = (undefined1)DAT_00887a8c;
      DAT_00887a8c = DAT_00887a8c >> 8;
      DAT_00886cf4 = DAT_00886cf4 + -8;
      DAT_00887a90 = (undefined2 *)((int)DAT_00887a90 + 1);
      return 0;
    }
    do {
      DAT_00887a88 = iVar2;
      iVar2 = DAT_00887a88;
      DAT_00887a88 = DAT_00887a88 + -1;
      if (-1 < DAT_00887a88) {
        *(undefined1 *)DAT_00887a90 = (undefined1)DAT_00887a8c;
        DAT_00887a8c = DAT_00887a8c >> 8;
        DAT_00886cf4 = DAT_00886cf4 + -8;
        DAT_00887a90 = (undefined2 *)((int)DAT_00887a90 + 1);
        return 0;
      }
      DAT_00887a88 = iVar2;
      iVar1 = FUN_00547cf0();
      iVar2 = DAT_00887a88;
    } while (iVar1 == 0);
    return 1;
  }
  DAT_00887a88 = DAT_00887a88 + -2;
  if (-1 < DAT_00887a88) {
    *DAT_00887a90 = (short)DAT_00887a8c;
    DAT_00887a90 = DAT_00887a90 + 1;
    DAT_00887a8c = DAT_00887a8c >> 0x10;
    DAT_00886cf4 = DAT_00886cf4 + -0x10;
    return 0;
  }
  do {
    DAT_00887a88 = iVar2;
    iVar2 = DAT_00887a88;
    DAT_00887a88 = DAT_00887a88 + -1;
    if (-1 < DAT_00887a88) {
      *(undefined1 *)DAT_00887a90 = (undefined1)DAT_00887a8c;
      DAT_00887a90 = (undefined2 *)((int)DAT_00887a90 + 1);
      do {
        iVar2 = DAT_00887a88;
        DAT_00887a88 = DAT_00887a88 + -1;
        if (-1 < DAT_00887a88) {
          *(char *)DAT_00887a90 = (char)(DAT_00887a8c >> 8);
          DAT_00887a8c = DAT_00887a8c >> 0x10;
          DAT_00886cf4 = DAT_00886cf4 + -0x10;
          DAT_00887a90 = (undefined2 *)((int)DAT_00887a90 + 1);
          return 0;
        }
        DAT_00887a88 = iVar2;
        iVar2 = FUN_00547cf0();
      } while (iVar2 == 0);
      return 1;
    }
    DAT_00887a88 = iVar2;
    iVar1 = FUN_00547cf0();
    iVar2 = DAT_00887a88;
  } while (iVar1 == 0);
  return 1;
}



void FUN_00547ef0(uint param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 < param_1 + 0x1000) {
    iVar5 = param_1 * 2;
    iVar4 = (param_1 + 0x1000) - param_1;
    do {
      uVar1 = *(ushort *)(DAT_00886cec + iVar5);
      uVar3 = (uint)uVar1;
      iVar2 = DAT_00886cf0;
      if ((uVar1 & 0x8000) == 0) {
LAB_00547f32:
        *(undefined2 *)(iVar2 + uVar3 * 2) = 0xffff;
      }
      else if (uVar3 != 0xffff) {
        uVar3 = uVar1 & 0x7fff;
        iVar2 = DAT_00887fa4;
        goto LAB_00547f32;
      }
      iVar5 = iVar5 + 2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}



void FUN_00547f40(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_2 - 2;
  if ((int)uVar3 < 1) {
    uVar3 = 0;
  }
  if (uVar3 < param_2) {
    iVar1 = param_2 - uVar3;
    iVar4 = (uVar3 + param_1) * 2;
    do {
      iVar4 = iVar4 + 2;
      *(undefined2 *)(DAT_00886cec + -2 + iVar4) = 0xffff;
      iVar1 = iVar1 + -1;
      *(undefined2 *)(DAT_00886cf0 + -2 + iVar4) = *(undefined2 *)(DAT_00886cec + -2 + iVar4);
    } while (iVar1 != 0);
  }
  if (2 < (int)param_2) {
    uVar3 = (param_2 - 2) + param_1;
    uVar2 = (uint)*(byte *)(DAT_00887a94 + param_1) << 5 ^
            (uint)((byte *)(DAT_00887a94 + param_1))[1];
    if (param_1 < uVar3) {
      iVar4 = param_1 * 2;
      do {
        uVar2 = (uint)*(byte *)(DAT_00887a94 + 2 + param_1) ^ (uVar2 & 0xff) << 5;
        *(ushort *)(DAT_00886cec + iVar4) = (ushort)uVar2 | 0x8000;
        *(undefined2 *)(DAT_00886cf0 + iVar4) = *(undefined2 *)(DAT_00887fa4 + uVar2 * 2);
        if (*(ushort *)(DAT_00886cf0 + iVar4) != 0xffff) {
          *(short *)(DAT_00886cec + (uint)*(ushort *)(DAT_00886cf0 + iVar4) * 2) = (short)param_1;
        }
        iVar4 = iVar4 + 2;
        *(short *)(DAT_00887fa4 + uVar2 * 2) = (short)param_1;
        param_1 = param_1 + 1;
      } while (param_1 < uVar3);
    }
  }
  return;
}



void FUN_00548030(void)

{
  int iVar1;
  
  if (*(int *)(DAT_00887a80 + 0x36710) != 0x20) {
    *(int *)(DAT_00887a80 + 0x36108) =
         *(int *)(DAT_00887a80 + 0x36108) + (0x20 - *(int *)(DAT_00887a80 + 0x36710));
    iVar1 = *(int *)(DAT_00887a80 + 0x36710);
    while (iVar1 != 0) {
      **(int **)(DAT_00887a80 + 0x3670c) = **(int **)(DAT_00887a80 + 0x3670c) << 1;
      *(int *)(DAT_00887a80 + 0x36710) = *(int *)(DAT_00887a80 + 0x36710) + -1;
      iVar1 = *(int *)(DAT_00887a80 + 0x36710);
    }
    *(int *)(DAT_00887a80 + 0x3670c) = *(int *)(DAT_00887a80 + 0x3670c) + 4;
    *(undefined4 *)(DAT_00887a80 + 0x36710) = 0x20;
  }
  FUN_005480b0(1);
  return;
}



undefined4 FUN_005480b0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  *(undefined4 *)(DAT_00887a80 + 0x36718) = *(undefined4 *)(DAT_00887a80 + 0x38120);
  if (*(int *)(DAT_00887a80 + 0x36108) != 0) {
    iVar1 = FUN_00547d80(0,1);
    if (iVar1 != 0) {
      return 1;
    }
    if (*(int *)(DAT_00887a80 + 0x38138) == 0) {
      FUN_00548660();
      iVar1 = FUN_005488f0();
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = FUN_00548410();
      if (iVar1 != 0) {
        return 1;
      }
    }
    else if (*(int *)(DAT_00887a80 + 0x38138) == 1) {
      FUN_00548910();
      iVar1 = FUN_00549120();
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = FUN_00548410();
      if (iVar1 != 0) {
        return 1;
      }
    }
    else if (*(int *)(DAT_00887a80 + 0x36108) < 0x80) {
      DAT_00887a84 = 1;
      *(undefined4 *)(DAT_00887a80 + 0x3811c) = 0;
      FUN_00548660();
      iVar1 = FUN_005488f0();
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = FUN_00548410();
      if (iVar1 != 0) {
        return 1;
      }
      uVar3 = *(uint *)(DAT_00887a80 + 0x3811c);
      *(undefined4 *)(DAT_00887a80 + 0x3811c) = 0;
      FUN_00548910();
      iVar1 = FUN_00549120();
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = FUN_00548410();
      if (iVar1 != 0) {
        return 1;
      }
      DAT_00887a84 = 0;
      uVar4 = *(int *)(DAT_00887a80 + 0x3671c) * 8 + 0x22;
      uVar2 = DAT_00886cf4 + 2U & 7;
      if (uVar2 != 0) {
        uVar4 = (uVar4 - uVar2) + 8;
      }
      if ((uVar4 < uVar3) && (uVar4 < *(uint *)(DAT_00887a80 + 0x3811c))) {
        iVar1 = FUN_005492f0();
        if (iVar1 != 0) {
          return 1;
        }
      }
      else if (uVar3 < *(uint *)(DAT_00887a80 + 0x3811c)) {
        FUN_00548660();
        iVar1 = FUN_005488f0();
        if (iVar1 != 0) {
          return 1;
        }
        iVar1 = FUN_00548410();
        if (iVar1 != 0) {
          return 1;
        }
      }
      else {
        iVar1 = FUN_00549120();
        if (iVar1 != 0) {
          return 1;
        }
        iVar1 = FUN_00548410();
        if (iVar1 != 0) {
          return 1;
        }
      }
    }
    else if (*(int *)(DAT_00887a80 + 0x3671c) < 0x3999) {
      DAT_00887a84 = 1;
      *(undefined4 *)(DAT_00887a80 + 0x3811c) = 0;
      FUN_00548910();
      iVar1 = FUN_00549120();
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = FUN_00548410();
      if (iVar1 != 0) {
        return 1;
      }
      DAT_00887a84 = 0;
      uVar3 = *(int *)(DAT_00887a80 + 0x3671c) * 8 + 0x22;
      uVar4 = DAT_00886cf4 + 2U & 7;
      if (uVar4 != 0) {
        uVar3 = (uVar3 - uVar4) + 8;
      }
      if (uVar3 < *(uint *)(DAT_00887a80 + 0x3811c)) {
        iVar1 = FUN_005492f0();
        if (iVar1 != 0) {
          return 1;
        }
      }
      else {
        iVar1 = FUN_00549120();
        if (iVar1 != 0) {
          return 1;
        }
        iVar1 = FUN_00548410();
        if (iVar1 != 0) {
          return 1;
        }
      }
    }
    else {
      FUN_00548910();
      iVar1 = FUN_00549120();
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = FUN_00548410();
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  *(int *)(DAT_00887a80 + 0x3670c) = DAT_00887a80 + 0x3610c;
  *(undefined4 *)(DAT_00887a80 + 0x36710) = 0x20;
  *(int *)(DAT_00887a80 + 0x36104) = DAT_00887a80 + 0x2d102;
  *(undefined4 *)(DAT_00887a80 + 0x36108) = 0;
  *(undefined4 *)(DAT_00887a80 + 0x3671c) = 0;
  *(undefined4 *)(DAT_00887a80 + 0x36714) = *(undefined4 *)(DAT_00887a80 + 0x36718);
  if (param_1 != 0) {
    iVar1 = FUN_00547d80(1,1);
    if (iVar1 != 0) {
      return 1;
    }
    FUN_00548660();
    iVar1 = FUN_005488f0();
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = FUN_00548410();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



bool FUN_00548410(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *local_c;
  int local_8;
  
  local_8 = 0;
  puVar3 = (undefined4 *)(DAT_00887a80 + 0x3610c);
  pbVar7 = (byte *)(DAT_00887a80 + 0x2d102);
  iVar5 = *(int *)(DAT_00887a80 + 0x36108);
  puVar2 = puVar3;
  do {
    if (iVar5 < 1) {
      iVar5 = FUN_00547d80(*(undefined4 *)(DAT_00887a80 + 0x375b8),
                           *(undefined4 *)(DAT_00887a80 + 0x3706c));
      return iVar5 != 0;
    }
    local_c = puVar2;
    if (local_8 == 0) {
      local_8 = 0x20;
      local_c = puVar2 + 1;
      puVar3 = (undefined4 *)*puVar2;
    }
    if (((uint)puVar3 & 0x80000000) == 0) {
      bVar1 = *pbVar7;
      pbVar7 = pbVar7 + 1;
      iVar4 = (uint)bVar1 * 4 + DAT_00887a80;
      iVar4 = FUN_00547d80(*(undefined4 *)(iVar4 + 0x371b8),*(undefined4 *)(iVar4 + 0x36c6c));
      if (iVar4 != 0) {
        return true;
      }
    }
    else {
      uVar8 = (uint)*(ushort *)(pbVar7 + 1);
      bVar1 = *pbVar7;
      uVar6 = (uint)bVar1;
      uVar9 = uVar8 - 1;
      iVar4 = (uint)*(ushort *)(&DAT_0058ef48 + uVar6 * 2) * 4 + DAT_00887a80;
      iVar4 = FUN_00547d80(*(undefined4 *)(iVar4 + 0x371b8),*(undefined4 *)(iVar4 + 0x36c6c));
      if (iVar4 != 0) {
        return true;
      }
      iVar4 = FUN_00547d80((&DAT_0058f248)[uVar6] & bVar1,(&DAT_0058f148)[uVar6]);
      if (iVar4 != 0) {
        return true;
      }
      if (uVar9 < 0x200) {
        iVar4 = (uint)(byte)(&DAT_0058f347)[uVar8] * 4 + DAT_00887a80;
        iVar4 = FUN_00547d80(*(undefined4 *)(iVar4 + 0x37638),*(undefined4 *)(iVar4 + 0x370ec));
        if (iVar4 != 0) {
          return true;
        }
        iVar4 = FUN_00547d80((byte)(&DAT_0058f747)[uVar8] & uVar9,(&DAT_0058f547)[uVar8]);
        if (iVar4 != 0) {
          return true;
        }
      }
      else {
        uVar6 = uVar9 >> 8;
        iVar4 = (uint)(byte)(&DAT_0058f948)[uVar6] * 4 + DAT_00887a80;
        iVar4 = FUN_00547d80(*(undefined4 *)(iVar4 + 0x37638),*(undefined4 *)(iVar4 + 0x370ec));
        if (iVar4 != 0) {
          return true;
        }
        iVar4 = FUN_00547d80(*(ushort *)(&DAT_0058fa48 + uVar6 * 2) & uVar9,(&DAT_0058f9c8)[uVar6]);
        if (iVar4 != 0) {
          return true;
        }
      }
      pbVar7 = pbVar7 + 3;
    }
    puVar3 = (undefined4 *)((int)puVar3 * 2);
    local_8 = local_8 + -1;
    iVar5 = iVar5 + -1;
    puVar2 = local_c;
  } while( true );
}



void FUN_00548660(void)

{
  FUN_00548750(DAT_00887a80 + 0x36c6c,8,0x90);
                    // language.dll match for 0x70: "B"
  FUN_00548750(DAT_00887a80 + 0x36eac,9,0x70);
  FUN_00548750(DAT_00887a80 + 0x3706c,7,0x18);
  FUN_00548750(DAT_00887a80 + 0x370cc,8,8);
  FUN_00548770(0x120,DAT_00887a80 + 0x36c6c);
  FUN_00548800(0x120,DAT_00887a80 + 0x36c6c,0xf,DAT_00887a80 + 0x371b8);
  FUN_00548750(DAT_00887a80 + 0x370ec,5,0x20);
  FUN_00548770(0x20,DAT_00887a80 + 0x370ec);
  FUN_00548800(0x20,DAT_00887a80 + 0x370ec,0xf,DAT_00887a80 + 0x37638);
  return;
}



void FUN_00548750(undefined4 *param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      *param_1 = param_2;
      param_1 = param_1 + 1;
    }
  }
  return;
}



void FUN_00548770(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  DAT_008875f8 = 0;
  FUN_00548750(&DAT_00887a98,0,0x21);
  iVar2 = param_1;
  piVar3 = param_2;
  if (0 < param_1) {
    do {
      piVar1 = (int *)((int)&DAT_00887a98 + *piVar3 * 4);
      *piVar1 = *piVar1 + 1;
      iVar2 = iVar2 + -1;
      piVar3 = piVar3 + 1;
    } while (iVar2 != 0);
  }
  iVar2 = 0;
  iVar4 = 4;
  do {
    *(int *)((int)&UNK_00886c64 + iVar4 + 4) = iVar2;
    iVar2 = iVar2 + *(int *)((int)&DAT_00887a98 + iVar4);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x81);
  iVar2 = 0;
  if (0 < param_1) {
    do {
      if (param_2[iVar2] != 0) {
        piVar3 = (int *)((int)&UNK_00886c64 + param_2[iVar2] * 4 + 4);
        DAT_008875f8 = DAT_008875f8 + 1;
        iVar4 = *piVar3 + 1;
        *piVar3 = iVar4;
        *(int *)((int)&UNK_00886d00 + iVar4 * 4 + 0x474) = iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1);
  }
  return;
}



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



bool FUN_005488f0(void)

{
  int iVar1;
  
  iVar1 = FUN_00547d80(1,2);
  return iVar1 != 0;
}



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



void FUN_00549460(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 - *(int *)(DAT_00887a80 + 0x38120) & 0x7fff;
  *(int *)(DAT_00887a80 + 0x38124) = *(int *)(DAT_00887a80 + 0x38124) + uVar1;
  *(uint *)(DAT_00887a80 + 0x38128) = *(int *)(DAT_00887a80 + 0x38120) + uVar1 + 0xefd;
  FUN_005494a0();
  return;
}



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



void FUN_0054a360(void)

{
  *(undefined4 *)(DAT_00887a80 + 0x38128) = 0xffff;
  FUN_005494a0();
  return;
}



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



// deflate_deinit

void __cdecl deflate_deinit(int param_1)

{
  DAT_00887a80 = param_1;
  *(undefined4 *)(param_1 + 0x38178) = 0xabcd1234;
  return;
}



// deflate_init

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



// deflate_buf_size

undefined4 __cdecl deflate_buf_size(void)

{
  return 0x3817c;
}



undefined4 _Inf32BufSize(void)

{
  return 0xad90;
}



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
                    // WARNING: Could not recover jumptable at 0x0054b167. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(&DAT_0054a854 + *(int *)(param_7 + 0xa958) * 4))();
  return;
}



void _ImmAssociateContext_8(void)

{
                    // WARNING: Could not recover jumptable at 0x0054b186. Too many branches
                    // WARNING: Treating indirect jump as call
  ImmAssociateContext();
  return;
}



void _ImmSetOpenStatus_8(void)

{
                    // WARNING: Could not recover jumptable at 0x0054b18c. Too many branches
                    // WARNING: Treating indirect jump as call
  ImmSetOpenStatus();
  return;
}



void _ImmReleaseContext_8(void)

{
                    // WARNING: Could not recover jumptable at 0x0054b192. Too many branches
                    // WARNING: Treating indirect jump as call
  ImmReleaseContext();
  return;
}



void _ImmNotifyIME_16(void)

{
                    // WARNING: Could not recover jumptable at 0x0054b198. Too many branches
                    // WARNING: Treating indirect jump as call
  ImmNotifyIME();
  return;
}



void _ImmGetContext_4(void)

{
                    // WARNING: Could not recover jumptable at 0x0054b19e. Too many branches
                    // WARNING: Treating indirect jump as call
  ImmGetContext();
  return;
}



void _ICInfo_12(void)

{
                    // WARNING: Could not recover jumptable at 0x0054b1a4. Too many branches
                    // WARNING: Treating indirect jump as call
  ICInfo();
  return;
}



void _MCIWndCreateA(void)

{
                    // WARNING: Could not recover jumptable at 0x0054b1aa. Too many branches
                    // WARNING: Treating indirect jump as call
  MCIWndCreateA();
  return;
}



// void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)*unaff_FS_OFFSET;
                    // WARNING: Could not recover jumptable at 0x0054b1fb. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)param_1)();
  return;
}



// void __stdcall _CallMemberFunction0(void *,void *)

void _CallMemberFunction0(void *param_1,void *param_2)

{
  LOCK();
  UNLOCK();
                    // WARNING: Could not recover jumptable at 0x0054b215. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)param_2)();
  return;
}



// void __stdcall _CallMemberFunction1(void *,void *,void *)

void _CallMemberFunction1(void *param_1,void *param_2,void *param_3)

{
  LOCK();
  UNLOCK();
                    // WARNING: Could not recover jumptable at 0x0054b225. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)param_2)();
  return;
}



// void __stdcall _CallMemberFunction2(void *,void *,void *,int)

void _CallMemberFunction2(void *param_1,void *param_2,void *param_3,int param_4)

{
  LOCK();
  UNLOCK();
                    // WARNING: Could not recover jumptable at 0x0054b235. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)param_2)();
  return;
}



// void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)

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



undefined4
___CxxFrameHandler(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = ___InternalCxxFrameHandler(param_1,param_2,param_3,param_4);
  return uVar1;
}



// void * __cdecl _CallCatchBlock2(struct EHRegistrationNode *,struct _s_FuncInfo const *,void
// *,int,unsigned long)

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



void FUN_0054b360(undefined4 param_1,int param_2,undefined4 param_3)

{
  ___InternalCxxFrameHandler
            (param_1,*(undefined4 *)(param_2 + 0xc),param_3,0,*(undefined4 *)(param_2 + 8),
             *(undefined4 *)(param_2 + 0x10),param_2,0);
  return;
}



// int __cdecl _CallSETranslator(struct EHExceptionRecord *,struct EHRegistrationNode *,void *,void
// *,struct _s_FuncInfo const *,int,struct EHRegistrationNode *)

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
                    // WARNING: Could not recover jumptable at 0x0054b4d4. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar1 = (**(code **)(param_2 + 0x18))();
  return uVar1;
}



// struct _s_TryBlockMapEntry const * __cdecl _GetRangeOfTrysToCheck(struct _s_FuncInfo const
// *,int,int,unsigned int *,unsigned int *)

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



void __global_unwind2(undefined4 param_1)

{
  _RtlUnwind_16(param_1,0x54b588,0,0,&stack0xfffffffc);
  return;
}



void __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  puStack_18 = &LAB_0054b590;
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



undefined4 __abnormal_termination(void)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_FS_OFFSET;
  
  uVar2 = 0;
  iVar1 = *unaff_FS_OFFSET;
  if ((*(undefined1 **)(iVar1 + 4) == &LAB_0054b590) &&
     (*(int *)(iVar1 + 8) == *(int *)(*(int *)(iVar1 + 0xc) + 0xc))) {
    uVar2 = 1;
  }
  return uVar2;
}



void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_0058fb58 = param_1;
  DAT_0058fb54 = in_EAX;
  DAT_0058fb5c = unaff_EBP;
  return;
}



void __NLG_Notify(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_0058fb58 = *(undefined4 *)(unaff_EBP + 8);
  DAT_0058fb54 = in_EAX;
  DAT_0058fb5c = unaff_EBP;
  return;
}



// void __cdecl operator delete(void *)

void __cdecl operator_delete(void *param_1)

{
  free(param_1);
  return;
}



void __fpmath(void)

{
  __cfltcvt_init();
  ___fastflag._4_4_ = __ms_p5_mp_test_fdiv();
  __setdefaultprecision();
  return;
}



void __cfltcvt_init(void)

{
  PTR___fptrap_0058fbcc = &__cropzeros;
  __cfltcvt_tab = &__cfltcvt;
  PTR___fptrap_0058fbd0 = &__fassign;
  PTR___fptrap_0058fbd4 = __forcdecpt;
  PTR___fptrap_0058fbd8 = &__positive;
  PTR___fptrap_0058fbdc = &__cfltcvt;
  return;
}



// void * __cdecl operator new(unsigned int)

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)__nh_malloc(param_1,1);
  return pvVar1;
}



longlong __ftol(void)

{
  float10 in_ST0;
  
  return (longlong)ROUND(in_ST0);
}



// calloc

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



// free

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



// fprintf

undefined4 __cdecl fprintf(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = __stbuf(param_1);
  uVar2 = __output(param_1,param_2,&stack0x0000000c);
  __ftbuf(uVar1,param_1);
  return uVar2;
}



// strncpy

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



// remove

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



void __unlink(undefined4 param_1)

{
  remove(param_1);
  return;
}



// strstr

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



// fclose

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



// sscanf

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



// fgets

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



// fopen

void __cdecl fopen(undefined4 param_1,undefined4 param_2)

{
  __fsopen(param_1,param_2,0x40);
  return;
}



// sprintf

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



// asctime

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



char * FUN_0054bd20(char *param_1,int param_2)

{
  *param_1 = (((char)(param_2 / 10) + (char)(param_2 >> 0x1f)) -
             (char)((longlong)param_2 * 0x66666667 >> 0x3f)) + '0';
  param_1[1] = (char)(param_2 % 10) + '0';
  return param_1 + 2;
}



// localtime

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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// time

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



// fflush

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



void __flushall(void)

{
  FUN_0054c150(1);
  return;
}



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



// vsprintf

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



// rewind

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



// malloc

void __cdecl malloc(undefined4 param_1)

{
  __nh_malloc(param_1,__newmode);
  return;
}



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



// atol

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



// atoi

void __cdecl atoi(undefined4 param_1)

{
  atol(param_1);
  return;
}



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



int __mbsninc(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = __mbsnbcnt(param_1,param_2);
  return iVar1 + param_1;
}



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



// mktime

void __cdecl mktime(undefined4 param_1)

{
  FUN_0054ca20(param_1,1);
  return;
}



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



// srand

void __cdecl srand(undefined4 param_1)

{
  DAT_0058fb80 = param_1;
  return;
}



// rand

uint __cdecl rand(void)

{
  DAT_0058fb80 = DAT_0058fb80 * 0x343fd + 0x269ec3;
  return DAT_0058fb80 >> 0x10 & 0x7fff;
}



// close

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



// read

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



void __open(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  __sopen(param_1,param_2,0x40,param_3);
  return;
}



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



void __tell(undefined4 param_1)

{
  lseek(param_1,0,1);
  return;
}



// lseek

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



// write

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



// fscanf

void __cdecl fscanf(undefined4 param_1,undefined4 param_2)

{
  __input(param_1,param_2,&stack0x0000000c);
  return;
}



// void __stdcall `eh vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
// *),void (__thiscall*)(void *))

void _eh_vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4,
               _func_void_void_ptr *param_5)

{
  int iVar1;
  void *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577a58;
  puStack_10 = &__except_handler3;
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



// void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
// *))

void _eh_vector_destructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577a68;
  puStack_10 = &__except_handler3;
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



// void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *))

void __ArrayUnwind(void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577a78;
  puStack_10 = &__except_handler3;
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



undefined4 FUN_0054d8a0(undefined4 *param_1)

{
  if (*(int *)*param_1 == -0x1f928c9d) {
    terminate();
  }
  return 0;
}



// fputs

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



// strncat

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



// ctime

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



// memset

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



// memcpy

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



// strtok

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



// WARNING: This is an inlined function
// WARNING: Unable to track spacebase fully for stack

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



// isupper

uint __cdecl isupper(int param_1)

{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,1);
    return uVar1;
  }
  return (byte)__pctype[param_1 * 2] & 1;
}



// isspace

uint __cdecl isspace(int param_1)

{
  uint uVar1;
  
  if (1 < ___mb_cur_max) {
    uVar1 = __isctype(param_1,8);
    return uVar1;
  }
  return (byte)__pctype[param_1 * 2] & 8;
}



// atof

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



// toupper

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



// tolower

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



void __getcwd(undefined4 param_1,undefined4 param_2)

{
  __getdcwd(0,param_1,param_2);
  return;
}



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



// floor

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
                             -1.0,uVar2);
  return fVar4;
}



// strchr

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



// atexit

int __cdecl atexit(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = __onexit(param_1);
  return (iVar1 != 0) - 1;
}



// stricmp

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



byte * __mbsinc(byte *param_1)

{
  byte *pbVar1;
  
  pbVar1 = param_1 + 1;
  if ((*(byte *)((int)&__mbctype + *param_1 + 1) & 4) != 0) {
    pbVar1 = param_1 + 2;
  }
  return pbVar1;
}



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



// strncmp

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



// qsort

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



// fseek

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



// fwrite

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



// ceil

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
                             -1.0,uVar2);
  return fVar4;
}



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



// strlen

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



void __cinit(void)

{
  if (__FPinit != (undefined *)0x0) {
    (*(code *)__FPinit)();
  }
  FUN_0054f7c0(&___xi_a,&___xi_z);
  FUN_0054f7c0(&___xc_a,&___xc_z);
  return;
}



void _exit(undefined4 param_1)

{
  FUN_0054f710(param_1,0,0);
  return;
}



void __exit(undefined4 param_1)

{
  FUN_0054f710(param_1,1,0);
  return;
}



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
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  byte *pbVar6;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00577a98;
  puStack_10 = &__except_handler3;
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



void __amsg_exit(undefined4 param_1)

{
  if (___error_mode == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)__aexit_rtn)(0xff);
  return;
}



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



void ___FrameUnwindToState(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577aa8;
  puStack_10 = &__except_handler3;
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



undefined4 FUN_0054ff50(undefined4 *param_1)

{
  if (*(int *)*param_1 == -0x1f928c9d) {
    terminate();
  }
  return 0;
}



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



void * FUN_00550000(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,
                   _s_FuncInfo *param_4,void *param_5,int param_6,ulong param_7)

{
  void *pvVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577ab8;
  puStack_10 = &__except_handler3;
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



undefined4 FUN_00550150(int *param_1)

{
  param_1 = (int *)*param_1;
  if ((((*param_1 == -0x1f928c9d) && (param_1[4] == 3)) && (param_1[5] == 0x19930520)) &&
     (param_1[7] == 0)) {
    return 1;
  }
  return 0;
}



void FUN_00550180(int param_1,int param_2,byte *param_3,byte *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577ad0;
  puStack_10 = &__except_handler3;
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



// void __cdecl _DestructExceptionObject(struct EHExceptionRecord *,unsigned char)

void __cdecl _DestructExceptionObject(EHExceptionRecord *param_1,uchar param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577ae0;
  puStack_10 = &__except_handler3;
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



// WARNING: Restarted to delay deadcode elimination for space: stack

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



// void __cdecl terminate(void)

void __cdecl terminate(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577af0;
  puStack_10 = &__except_handler3;
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



void FUN_005504fe(void)

{
  abort();
  return;
}



// void __cdecl unexpected(void)

void __cdecl unexpected(void)

{
  if (__pUnexpected != (_func_void *)0x0) {
    (*__pUnexpected)();
  }
  terminate();
  return;
}



// void __cdecl _inconsistency(void)

void __cdecl _inconsistency(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00577b08;
  puStack_10 = &__except_handler3;
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



void FUN_0055059e(void)

{
  terminate();
  return;
}



void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}



// WARNING: Removing unreachable block (ram,0x00550621)

undefined4 __ms_p5_test_fdiv(void)

{
  return 0;
}



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
  builtin_strncpy(puVar2 + param_3 + (uint)(DAT_00888060 == '\0'),"e+000",6);
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



void FUN_00550aa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DAT_00888060 = 1;
  __cftoe(param_1,param_2,param_3,param_4);
  DAT_00888060 = 0;
  return;
}



void FUN_00550ad0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_00888060 = 1;
  __cftof(param_1,param_2,param_3);
  DAT_00888060 = 0;
  return;
}



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



// int (__cdecl*__cdecl _set_new_handler(int (__cdecl*)(unsigned int)))(unsigned int)

_func_int_uint * __cdecl _set_new_handler(_func_int_uint *param_1)

{
  _func_int_uint *p_Var1;
  
  p_Var1 = _pnhHeap;
  _pnhHeap = param_1;
  return p_Var1;
}



// int (__cdecl*__cdecl _query_new_handler(void))(unsigned int)

_func_int_uint * __cdecl _query_new_handler(void)

{
  return _pnhHeap;
}



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



undefined4 FUN_005521b0(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}



undefined8 FUN_005521d0(int *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}



undefined4 FUN_005521f0(undefined4 *param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = (undefined2 *)*param_1;
  puVar2 = puVar1 + 2;
  *param_1 = puVar2;
  return CONCAT22((short)((uint)puVar2 >> 0x10),*puVar1);
}



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
                    // language.dll match for 0x65: "1"
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
                    // language.dll match for 0x6f: "12"
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
                    // language.dll match for 0x80: "Arial"
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
                    // language.dll match for 0x80: "Arial"
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



void FUN_00553070(int param_1,undefined4 param_2)

{
  if (param_1 != -1) {
    ungetc(param_1,param_2);
  }
  return;
}



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



void ___tzset(void)

{
  if (DAT_00888138 == 0) {
    __tzset();
    DAT_00888138 = DAT_00888138 + 1;
  }
  return;
}



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



// gmtime

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
                    // language.dll match for 0x81: "10"
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



longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



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



int FUN_00554510(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00888284 = 1;
                    // WARNING: Could not recover jumptable at 0x0055452d. Too many branches
                    // WARNING: Treating indirect jump as call
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00888284 = 1;
                    // WARNING: Could not recover jumptable at 0x00554542. Too many branches
                    // WARNING: Treating indirect jump as call
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



void ___initmbctable(void)

{
  __setmbcp(0xfffffffd);
  return;
}



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



// WARNING: Function: __alloca_probe replaced with injection: alloca_probe

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



void __seh_longjmp_unwind_4(int param_1)

{
  __local_unwind2(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
  return;
}



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



float10 __frnd(double param_1)

{
  return (float10)ROUND(param_1);
}



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
          if (local_10 == 0.0) {
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
              if ((double)fVar6 < 0.0) {
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
            if (*param_2 <= 0.0) {
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
            if (*param_2 <= 0.0) {
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
          if (0.0 < *param_2) {
            *(undefined4 *)param_2 = __d_inf;
            *(undefined4 *)((int)param_2 + 4) = uVar2;
            uVar4 = param_1 & 0x1e;
            goto LAB_00555e3b;
          }
          local_10 = -(double)CONCAT44(DAT_00592544,__d_max);
          *param_2 = local_10;
        }
        else if (uVar4 == 0xc00) {
          if (*param_2 <= 0.0) {
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



float10 __set_exp(undefined4 param_1,undefined4 param_2,short param_3)

{
  return (float10)(double)CONCAT26(param_2._2_2_ & 0x800f | (param_3 + 0x3fe) * 0x10,
                                   CONCAT24((undefined2)param_2,param_1));
}



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



float10 __decomp(uint param_1,uint param_2,int *param_3)

{
  ushort uVar1;
  double dVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  
  if ((double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((undefined2)param_2,param_1)))
      == 0.0) {
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
    if (dVar2 < 0.0) {
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



int __statfp(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}



int __clrfp(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}



int __ctrlfp(void)

{
  short in_FPUControlWord;
  
  return (int)in_FPUControlWord;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __set_statfp(void)

{
  return;
}



// realloc

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



// ftell

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
                    // language.dll match for 0x82: "B"
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



void __ismbblead(undefined4 param_1)

{
  FUN_00556930(param_1,0,4);
  return;
}



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



// long __stdcall __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS *)

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



// void __cdecl __CxxSetUnhandledExceptionFilter(void)

void __cdecl __CxxSetUnhandledExceptionFilter(void)

{
  DAT_008883e8 = SetUnhandledExceptionFilter(__CxxUnhandledExceptionFilter);
  return;
}



// void __cdecl __CxxRestoreUnhandledExceptionFilter(void)

void __cdecl __CxxRestoreUnhandledExceptionFilter(void)

{
  SetUnhandledExceptionFilter(DAT_008883e8);
  return;
}



// int __cdecl _ValidateRead(void const *,unsigned int)

int __cdecl _ValidateRead(void *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = IsBadReadPtr(param_1,param_2);
  return (uint)(iVar1 == 0);
}



// int __cdecl _ValidateWrite(void *,unsigned int)

int __cdecl _ValidateWrite(void *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = IsBadWritePtr(param_1,param_2);
  return (uint)(iVar1 == 0);
}



// int __cdecl _ValidateExecute(int (__stdcall*)(void))

int __cdecl _ValidateExecute(_func_int *param_1)

{
  int iVar1;
  
  iVar1 = IsBadCodePtr(param_1);
  return (uint)(iVar1 == 0);
}



// memmove

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



// abort

void __cdecl abort(void)

{
  __NMSG_WRITE(10);
  raise(0x16);
  __exit(3);
  return;
}



void __statusfp(void)

{
  FUN_00557910();
  return;
}



void __clearfp(void)

{
  FUN_00557910();
  return;
}



uint __control87(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_005577e0();
  uVar1 = param_2 & param_1 | ~param_2 & uVar1;
  FUN_00557880(uVar1);
  return uVar1;
}



void __controlfp(undefined4 param_1,uint param_2)

{
  __control87(param_1,param_2 & 0xfff7ffff);
  return;
}



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



void FUN_00557880(void)

{
  return;
}



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



void __FillZeroMan(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



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



void __ld12tod(undefined4 param_1,undefined4 param_2)

{
  __ld12cvt(param_1,param_2,&DAT_00592690);
  return;
}



void __ld12tof(undefined4 param_1,undefined4 param_2)

{
  __ld12cvt(param_1,param_2,&DAT_005926a8);
  return;
}



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



void __atodbl(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_c [12];
  
  ___strgtold12(local_c,&param_2,param_2,0,0,0,0);
  __ld12tod(local_c,param_1);
  return;
}



void __atoflt(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_c [12];
  
  ___strgtold12(local_c,&param_2,param_2,0,0,0,0);
  __ld12tof(local_c,param_1);
  return;
}



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



void __fptrap(void)

{
  __amsg_exit(2);
  return;
}



byte __isatty(uint param_1)

{
  if (__nhandle <= param_1) {
    return 0;
  }
  return *(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 0x40;
}



// wctomb

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



// mbtowc

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



// ungetc

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



// wcstombs

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



// getenv

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
                    // language.dll match for 0x1451: "Dead tree"
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



undefined4 __matherr(void)

{
  return 0;
}



// wcslen

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



// raise

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



void ___shr_12(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}



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



undefined4
__I10_OUTPUT(int param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  ushort uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  int iVar8;
  short sVar9;
  int iVar10;
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
  uVar4 = param_3 & 0x7fff;
  local_12 = 0xfb;
  local_11 = 0x3f;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar4 == 0) && (param_2 == 0)) && (param_1 == 0)) {
    *param_6 = 0;
LAB_0055992f:
    *(undefined1 *)(psVar1 + 1) = 0x20;
    *(undefined1 *)((int)psVar1 + 3) = 1;
    *(undefined1 *)(psVar1 + 2) = 0x30;
    *(undefined1 *)((int)psVar1 + 5) = 0;
    return 1;
  }
  if ((short)uVar4 == 0x7fff) {
    *param_6 = 1;
    if (((param_2 != 0x80000000) || (param_1 != 0)) && ((param_2 & 0x40000000) == 0)) {
      *(undefined4 *)(param_6 + 2) = 0x4e532331;
      param_6[4] = 0x4e41;
      *(undefined1 *)((int)param_6 + 3) = 6;
      *(undefined1 *)(param_6 + 5) = 0;
      return 0;
    }
    if ((((param_3 & 0x8000) != 0) && (param_2 == 0xc0000000)) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = 0x4e492331;
      *(undefined1 *)((int)param_6 + 3) = 5;
      param_6[4] = 0x44;
      return 0;
    }
    if ((param_2 == 0x80000000) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = 0x4e492331;
      *(undefined1 *)((int)param_6 + 3) = 5;
      param_6[4] = 0x46;
      return 0;
    }
    *(undefined4 *)(param_6 + 2) = 0x4e512331;
    param_6[4] = 0x4e41;
    *(undefined1 *)((int)param_6 + 3) = 6;
    *(undefined1 *)(param_6 + 5) = 0;
    return 0;
  }
  local_6 = (undefined1)uVar4;
  cStack_5 = (char)(uVar4 >> 8);
  uStack_a = (undefined2)param_2;
  uStack_8 = (undefined2)(param_2 >> 0x10);
  uStack_e = (undefined2)param_1;
  uStack_c = (undefined2)((uint)param_1 >> 0x10);
  local_10 = 0;
  sVar9 = (short)(((uVar4 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar4 * 0x4d10 >>
                 0x10);
  ___multtenpow12(&local_10,-(int)sVar9,1);
  if (0x3ffe < CONCAT11(cStack_5,local_6)) {
    sVar9 = sVar9 + 1;
    ___ld12mul(&local_10,&local_1c);
  }
  *psVar1 = sVar9;
  iVar8 = param_4;
  if (((param_5 & 1) != 0) && (iVar8 = param_4 + sVar9, param_4 + sVar9 < 1)) {
    *psVar1 = 0;
    goto LAB_0055992f;
  }
  if (0x15 < iVar8) {
    iVar8 = 0x15;
  }
  uVar2 = CONCAT11(cStack_5,local_6);
  local_6 = 0;
  cStack_5 = '\0';
  iVar5 = 8;
  iVar10 = uVar2 - 0x3ffe;
  do {
    ___shl_12(&local_10);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (iVar10 < 0) {
    for (uVar4 = -iVar10 & 0xff; uVar4 != 0; uVar4 = uVar4 - 1) {
      ___shr_12(&local_10);
    }
  }
  psVar1 = psVar1 + 2;
  iVar8 = iVar8 + 1;
  psVar6 = psVar1;
  if (0 < iVar8) {
    do {
      param_1 = CONCAT22(uStack_e,local_10);
      param_2 = CONCAT22(uStack_a,uStack_c);
      param_3 = CONCAT13(cStack_5,CONCAT12(local_6,uStack_8));
      ___shl_12(&local_10);
      ___shl_12(&local_10);
      ___add_12(&local_10,&param_1);
      ___shl_12(&local_10);
      cVar3 = cStack_5 + '0';
      cStack_5 = '\0';
      *(char *)psVar6 = cVar3;
      psVar6 = (short *)((int)psVar6 + 1);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  psVar7 = psVar6 + -1;
  if (*(char *)((int)psVar6 + -1) < '5') {
    if (psVar1 <= psVar7) {
      do {
        if ((char)*psVar7 != '0') break;
        psVar7 = (short *)((int)psVar7 + -1);
      } while (psVar1 <= psVar7);
      if (psVar1 <= psVar7) goto LAB_00559a86;
    }
    *(undefined1 *)psVar1 = 0x30;
    *param_6 = 0;
    *(undefined1 *)(param_6 + 1) = 0x20;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(undefined1 *)((int)param_6 + 5) = 0;
    return 1;
  }
  if (psVar1 <= psVar7) {
    do {
      if ((char)*psVar7 != '9') break;
      *(undefined1 *)psVar7 = 0x30;
      psVar7 = (short *)((int)psVar7 + -1);
    } while (psVar1 <= psVar7);
    if (psVar1 <= psVar7) {
      *(char *)psVar7 = (char)*psVar7 + '\x01';
      goto LAB_00559a86;
    }
  }
  psVar7 = (short *)((int)psVar7 + 1);
  *param_6 = *param_6 + 1;
  *(char *)psVar7 = *(char *)psVar7 + '\x01';
LAB_00559a86:
  cVar3 = ((char)psVar7 - (char)param_6) + -3;
  *(char *)((int)param_6 + 3) = cVar3;
  *(undefined1 *)((int)param_6 + cVar3 + 4) = 0;
  return 1;
}



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



// public: int __thiscall ostream::opfx(void)

int __thiscall ostream::opfx(ostream *this)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)this + 4);
  if (*(uint *)(&this->field_0x8 + iVar1) != 0) {
    *(uint *)(&this->field_0x8 + iVar1) = *(uint *)(&this->field_0x8 + iVar1) | 2;
    return 0;
  }
  if (*(ostream **)(&this->field_0x20 + iVar1) != (ostream *)0x0) {
    flush(*(ostream **)(&this->field_0x20 + iVar1));
  }
  return 1;
}



// public: void __thiscall ostream::osfx(void)

void __thiscall ostream::osfx(ostream *this)

{
  int iVar1;
  
  *(undefined4 *)(&this->field_0x30 + *(int *)(*(int *)this + 4)) = 0;
  if ((*(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) & 0x2000) != 0) {
    iVar1 = (**(code **)(**(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4)) + 4))();
    if (iVar1 == -1) {
      *(undefined4 *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) = 6;
    }
  }
  if ((*(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) & 0x4000) != 0) {
    iVar1 = fflush(&DAT_00591e68);
    if (iVar1 == -1) {
      *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
           *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 2;
    }
    iVar1 = fflush(&DAT_00591e88);
    if (iVar1 == -1) {
      *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
           *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 2;
    }
  }
  return;
}



// public: class ostream & __thiscall ostream::operator<<(char const *)

ostream * __thiscall ostream::operator<<(ostream *this,char *param_1)

{
  int iVar1;
  
  iVar1 = opfx(this);
  if (iVar1 != 0) {
    writepad(this,s_,param_1);
    osfx(this);
  }
  return this;
}



// public: class ostream & __thiscall ostream::flush(void)

ostream * __thiscall ostream::flush(ostream *this)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4)) + 4))();
  if (iVar1 == -1) {
    *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
         *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 2;
  }
  return this;
}



// protected: __thiscall ostream::ostream(void)

ostream * __thiscall ostream::ostream(ostream *this)

{
  int in_stack_00000004;
  
  if (in_stack_00000004 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0x8);
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  this->x_floatused = 0;
  return this;
}



// public: virtual void * __thiscall ostream::`scalar deleting destructor'(unsigned int)

void * __thiscall ostream::_scalar_deleting_destructor_(ostream *this,uint param_1)

{
  ~ostream(this);
  ios::~ios((ios *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(&this[-1].field_0x34);
  }
  return &this[-1].field_0x34;
}



// public: __thiscall ostream::ostream(class streambuf *)

ostream * __thiscall ostream::ostream(ostream *this,streambuf *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00561ef6;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (in_stack_00000008 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0x8);
    local_4 = 0;
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),param_1);
  this->x_floatused = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}



// protected: __thiscall ostream::ostream(class ostream const &)

ostream * __thiscall ostream::ostream(ostream *this,ostream *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00561f1a;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (in_stack_00000008 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0x8);
    local_4 = 0;
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),
            *(streambuf **)((int)&param_1->x_floatused + *(int *)(*(int *)param_1 + 4)));
  this->x_floatused = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}



// public: virtual __thiscall ostream::~ostream(void)

void __thiscall ostream::~ostream(ostream *this)

{
  *(undefined ***)(*(int *)(*(int *)&this[-1].field_0x34 + 4) + -8 + (int)this) = &_vftable_;
  return;
}



// protected: class ostream & __thiscall ostream::operator=(class streambuf *)

ostream * __thiscall ostream::operator=(ostream *this,streambuf *param_1)

{
  undefined4 *puVar1;
  ios *piVar2;
  undefined4 *unaff_FS_OFFSET;
  ios local_40;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00561f38;
  *unaff_FS_OFFSET = &uStack_c;
  if ((*(int *)(&this->field_0x1c + *(int *)(*(int *)this + 4)) != 0) &&
     (puVar1 = *(undefined4 **)((int)&this->x_floatused + *(int *)(*(int *)this + 4)),
     puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 *)((int)&this->x_floatused + *(int *)(*(int *)this + 4)) = 0;
  piVar2 = (ios *)ios::ios(&local_40);
  uStack_4 = 0;
  ios::operator=((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),piVar2);
  uStack_4 = 0xffffffff;
  ios::~ios(&local_40);
  *(undefined4 *)(&this->field_0x1c + *(int *)(*(int *)this + 4)) = 0;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),param_1);
  *unaff_FS_OFFSET = uStack_c;
  return this;
}



// public: __thiscall ostream_withassign::ostream_withassign(void)

ostream_withassign * __thiscall ostream_withassign::ostream_withassign(ostream_withassign *this)

{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000004;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00561f66;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (in_stack_00000004 != 0) {
    *(undefined8 **)this = &_vbtable_;
    ios::ios((ios *)(this + 8));
    local_4 = 0;
  }
  ostream::ostream((ostream *)this);
  *(undefined ***)(this + *(int *)(*(int *)this + 4)) = &_vftable_;
  *unaff_FS_OFFSET = this;
  return this;
}



// public: virtual void * __thiscall ostream_withassign::`vector deleting destructor'(unsigned int)

void * __thiscall
ostream_withassign::_vector_deleting_destructor_(ostream_withassign *this,uint param_1)

{
  ~ostream_withassign(this);
  ios::~ios((ios *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this + -8);
  }
  return this + -8;
}



// public: __thiscall ostream_withassign::ostream_withassign(class streambuf *)

ostream_withassign * __thiscall
ostream_withassign::ostream_withassign(ostream_withassign *this,streambuf *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00561f86;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (in_stack_00000008 != 0) {
    *(undefined8 **)this = &_vbtable_;
    ios::ios((ios *)(this + 8));
    local_4 = 0;
  }
  ostream::ostream((ostream *)this,param_1);
  *(undefined ***)(this + *(int *)(*(int *)this + 4)) = &_vftable_;
  *unaff_FS_OFFSET = this;
  return this;
}



// public: virtual __thiscall ostream_withassign::~ostream_withassign(void)

void __thiscall ostream_withassign::~ostream_withassign(ostream_withassign *this)

{
  *(undefined ***)(this + *(int *)(*(int *)(this + -8) + 4) + -8) = &_vftable_;
  ostream::~ostream((ostream *)this);
  return;
}



// private: class ostream & __thiscall ostream::writepad(char const *,char const *)

ostream * __thiscall ostream::writepad(ostream *this,char *param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  bool bVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  
  pcVar5 = param_1;
  uVar8 = 0xffffffff;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  iVar9 = ~uVar8 - 1;
  uVar8 = 0xffffffff;
  pcVar11 = param_2;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  iVar10 = ~uVar8 - 1;
  if ((uint)(iVar9 + iVar10) < *(uint *)(&this->field_0x30 + *(int *)(*(int *)this + 4))) {
    param_1 = (char *)((*(uint *)(&this->field_0x30 + *(int *)(*(int *)this + 4)) - iVar10) - iVar9)
    ;
  }
  else {
    param_1 = (char *)0x0;
  }
  if ((((&this->field_0x24)[*(int *)(*(int *)this + 4)] & 10) == 0) &&
     (pcVar6 = param_1 + -1, bVar4 = 0 < (int)param_1, pcVar11 = param_1, param_1 = pcVar6, bVar4))
  {
    do {
      bVar2 = (&this->field_0x2c)[*(int *)(*(int *)this + 4)];
      piVar3 = *(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4));
      if ((byte *)piVar3[7] < (byte *)piVar3[8]) {
        *(byte *)piVar3[7] = bVar2;
        uVar8 = (uint)bVar2;
        piVar3[7] = piVar3[7] + 1;
      }
      else {
        uVar8 = (**(code **)(*piVar3 + 0x1c))(bVar2);
      }
      if (uVar8 == 0xffffffff) {
        *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
             *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 6;
      }
      pcVar11 = pcVar11 + -1;
      param_1 = param_1 + -1;
    } while (pcVar11 != (char *)0x0);
  }
  if ((iVar9 != 0) &&
     (iVar7 = (**(code **)(**(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4)) + 0x14))
                        (pcVar5,iVar9), iVar7 != iVar9)) {
    *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
         *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 6;
  }
  if ((((&this->field_0x24)[*(int *)(*(int *)this + 4)] & 8) != 0) && (0 < (int)param_1)) {
    do {
      bVar2 = (&this->field_0x2c)[*(int *)(*(int *)this + 4)];
      piVar3 = *(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4));
      if ((byte *)piVar3[7] < (byte *)piVar3[8]) {
        *(byte *)piVar3[7] = bVar2;
        uVar8 = (uint)bVar2;
        piVar3[7] = piVar3[7] + 1;
      }
      else {
        uVar8 = (**(code **)(*piVar3 + 0x1c))(bVar2);
      }
      if (uVar8 == 0xffffffff) {
        *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
             *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 6;
      }
      param_1 = param_1 + -1;
    } while (param_1 != (char *)0x0);
  }
  iVar9 = (**(code **)(**(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4)) + 0x14))
                    (param_2,iVar10);
  if (iVar9 != iVar10) {
    *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
         *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 6;
  }
  if ((((&this->field_0x24)[*(int *)(*(int *)this + 4)] & 2) != 0) && (0 < iVar10)) {
    do {
      bVar2 = (&this->field_0x2c)[*(int *)(*(int *)this + 4)];
      piVar3 = *(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4));
      if ((byte *)piVar3[7] < (byte *)piVar3[8]) {
        *(byte *)piVar3[7] = bVar2;
        uVar8 = (uint)bVar2;
        piVar3[7] = piVar3[7] + 1;
      }
      else {
        uVar8 = (**(code **)(*piVar3 + 0x1c))(bVar2);
      }
      if (uVar8 == 0xffffffff) {
        *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
             *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 6;
      }
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  return this;
}



// protected: class istream & __thiscall istream::get(char *,int,int)

istream * __thiscall istream::get(istream *this,char *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = ipfx(this,1);
  if ((iVar1 != 0) && (param_2 != 0)) {
    if (param_2 != 1) {
      do {
        iVar1 = streambuf::sgetc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
        if (iVar1 == -1) {
          *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
               *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 1;
          if (uVar2 == 0) {
            *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
                 *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 2;
          }
          break;
        }
        if (iVar1 == param_3) {
          if (this->_fGline != 0) {
            this->x_gcount = this->x_gcount + 1;
            streambuf::stossc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
          }
          break;
        }
        if (param_1 != (char *)0x0) {
          param_1[uVar2] = (char)iVar1;
        }
        streambuf::stossc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_2 - 1U);
    }
    this->x_gcount = this->x_gcount + uVar2;
  }
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    param_1[uVar2] = '\0';
  }
  this->_fGline = 0;
  return this;
}



// public: class ostream & __thiscall ostream::operator<<(int)

ostream * __thiscall ostream::operator<<(ostream *this,int param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  ushort local_14;
  undefined1 local_12;
  undefined1 local_11;
  undefined2 local_10;
  undefined1 local_e;
  undefined1 local_d;
  char local_c [12];
  
  local_10 = s__d;
  local_e = DAT_00584612;
  local_d = 0;
  local_14 = 0;
  local_12 = 0;
  local_11 = 0;
  iVar3 = opfx(this);
  if (iVar3 != 0) {
    if (param_1 != 0) {
      uVar1 = *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4));
      if ((uVar1 & 0x60) == 0) {
        if ((0 < param_1) && ((uVar1 & 0x400) != 0)) {
          local_14 = CONCAT11(local_14._1_1_,0x2b);
        }
      }
      else {
        if ((uVar1 & 0x40) == 0) {
          local_10 = CONCAT11(0x6f,(undefined1)local_10);
        }
        else {
          bVar2 = ~(byte)(uVar1 >> 4);
          local_10 = CONCAT11(bVar2,(undefined1)local_10) & 0x20ff | 0x5800;
          local_14 = CONCAT11(bVar2,(undefined1)local_14) & 0x20ff | 0x5800;
        }
        if (((&this->field_0x24)[*(int *)(*(int *)this + 4)] & 0x80) != 0) {
          local_14 = CONCAT11(local_14._1_1_,0x30);
        }
      }
    }
    sprintf(local_c,&local_10,param_1);
    writepad(this,(char *)&local_14,local_c);
    osfx(this);
  }
  return this;
}



// WARNING: Function: __alloca_probe replaced with injection: alloca_probe
// public: class ostream & __thiscall ostream::operator<<(double)

ostream * __thiscall ostream::operator<<(ostream *this,double param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  char local_24 [12];
  char local_18;
  char local_17 [19];
  undefined4 uStack_4;
  
  uStack_4 = 0x55afda;
  iVar2 = this->x_floatused;
  this->x_floatused = 0;
  uVar6 = (-(uint)(iVar2 != 0) & 0xfffffff7) + 0xf;
  pcVar4 = &local_18;
  if (*(uint *)(&this->field_0x28 + *(int *)(*(int *)this + 4)) < uVar6) {
    uVar6 = *(uint *)(&this->field_0x28 + *(int *)(*(int *)this + 4));
  }
  iVar2 = opfx(this);
  if (iVar2 != 0) {
    bVar7 = (*(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) & 0x400) != 0;
    if (bVar7) {
      local_24[0] = '+';
    }
    uVar5 = (uint)bVar7;
    if ((*(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) & 0x100) != 0) {
      local_24[uVar5] = '#';
      uVar5 = uVar5 + 1;
    }
    local_24[uVar5] = '\0';
    iVar3 = sprintf(local_24 + 4,"%%%s.%.0ug",local_24,uVar6);
    iVar2 = *(int *)this;
    uVar6 = *(uint *)(&this->field_0x24 + *(int *)(iVar2 + 4)) & 0x1800;
    if (uVar6 == 0x1000) {
      local_24[iVar3 + 3] = 'f';
    }
    else {
      if (uVar6 == 0x800) {
                    // language.dll match for 0x65: "1"
        local_24[iVar3 + 3] = 'e';
      }
      if ((*(uint *)(&this->field_0x24 + *(int *)(iVar2 + 4)) & 0x200) != 0) {
        cVar1 = toupper((int)local_24[iVar3 + 3]);
        local_24[iVar3 + 3] = cVar1;
      }
    }
    sprintf(&local_18,local_24 + 4,param_1);
    iVar2 = 0;
    if ((local_18 == '+') || (local_18 == '-')) {
      local_24[0] = local_18;
      iVar2 = 1;
      pcVar4 = local_17;
    }
    local_24[iVar2] = '\0';
    writepad(this,local_24,pcVar4);
    osfx(this);
  }
  return this;
}



// protected: __thiscall ios::ios(void)

void __thiscall ios::ios(ios *this)

{
  this->_padding_ = (int)&_vftable_;
  this->bp = (streambuf *)0x0;
  this->state = 4;
  this->ispecial = 0;
  this->ospecial = 0;
  this->x_tie = (ostream *)0x0;
  this->x_flags = 0;
  this->x_precision = 6;
  this->x_fill = ' ';
  this->x_width = 0;
  this->x_delbuf = 0;
  return;
}



// public: virtual void * __thiscall ios::`vector deleting destructor'(unsigned int)

void * __thiscall ios::_vector_deleting_destructor_(ios *this,uint param_1)

{
  ~ios(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// public: __thiscall ios::ios(class streambuf *)

void __thiscall ios::ios(ios *this,streambuf *param_1)

{
  this->bp = param_1;
  this->_padding_ = (int)&_vftable_;
  this->x_precision = 6;
  this->x_fill = ' ';
  this->state = (-(uint)(param_1 != (streambuf *)0x0) & 0xfffffffc) + 4;
  this->ispecial = 0;
  this->ospecial = 0;
  this->x_tie = (ostream *)0x0;
  this->x_flags = 0;
  this->x_width = 0;
  this->x_delbuf = 0;
  return;
}



// protected: __thiscall ios::ios(class ios const &)

ios * __thiscall ios::ios(ios *this,ios *param_1)

{
  this->bp = (streambuf *)0x0;
  this->x_delbuf = 0;
  this->_padding_ = (int)&_vftable_;
  operator=(this,param_1);
  return this;
}



// public: virtual __thiscall ios::~ios(void)

void __thiscall ios::~ios(ios *this)

{
  this->_padding_ = (int)&_vftable_;
  if ((this->x_delbuf != 0) && (this->bp != (streambuf *)0x0)) {
    (**(code **)this->bp->_padding_)(1);
  }
  this->bp = (streambuf *)0x0;
  this->state = 4;
  return;
}



// protected: void __thiscall ios::init(class streambuf *)

void __thiscall ios::init(ios *this,streambuf *param_1)

{
  if ((this->x_delbuf != 0) && (this->bp != (streambuf *)0x0)) {
    (**(code **)this->bp->_padding_)(1);
  }
  this->bp = param_1;
  if (param_1 != (streambuf *)0x0) {
    this->state = this->state & 0xfffffffb;
    return;
  }
  this->state = this->state | 4;
  return;
}



// protected: class ios & __thiscall ios::operator=(class ios const &)

ios * __thiscall ios::operator=(ios *this,ios *param_1)

{
  uint uVar1;
  
  this->x_tie = param_1->x_tie;
  this->x_flags = param_1->x_flags;
  this->x_precision = (int)(char)param_1->x_precision;
  this->x_fill = param_1->x_fill;
  this->x_width = (int)(char)param_1->x_width;
  uVar1 = param_1->state;
  this->state = uVar1;
  if (this->bp == (streambuf *)0x0) {
    this->state = uVar1 | 4;
  }
  return this;
}



// public: static int __cdecl ios::xalloc(void)

int __cdecl ios::xalloc(void)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  
  plVar1 = (long *)operator_new(x_curindex * 4 + 8);
  if (plVar1 == (long *)0x0) {
    return -1;
  }
  iVar2 = 0;
  if (-1 < x_curindex) {
    do {
      iVar3 = iVar2 + 1;
      plVar1[iVar2] = x_statebuf[iVar2];
      iVar2 = iVar3;
    } while (iVar3 <= x_curindex);
  }
  x_curindex = x_curindex + 1;
  plVar1[x_curindex] = 0;
  if (x_statebuf != (long *)0x0) {
    operator_delete(x_statebuf);
  }
  x_statebuf = plVar1;
  return x_curindex;
}



// public: static long __cdecl ios::bitalloc(void)

long __cdecl ios::bitalloc(void)

{
  x_maxbit = x_maxbit << 1;
  return x_maxbit;
}



// public: int __thiscall streambuf::snextc(void)

int __thiscall streambuf::snextc(streambuf *this)

{
  int iVar1;
  byte *pbVar2;
  
  if (this->_fUnbuf != 0) {
    if (this->x_lastc == -1) {
      (**(code **)(this->_padding_ + 0x20))();
    }
    iVar1 = (**(code **)(this->_padding_ + 0x20))();
    this->x_lastc = iVar1;
    return iVar1;
  }
  if ((this->_egptr == (char *)0x0) || (this->_egptr <= this->_gptr)) {
    (**(code **)(this->_padding_ + 0x20))();
  }
  pbVar2 = (byte *)(this->_gptr + 1);
  this->_gptr = (char *)pbVar2;
  if (pbVar2 < this->_egptr) {
    return (uint)*pbVar2;
  }
  iVar1 = (**(code **)(this->_padding_ + 0x20))();
  return iVar1;
}



// public: int __thiscall streambuf::sbumpc(void)

int __thiscall streambuf::sbumpc(streambuf *this)

{
  byte bVar1;
  int iVar2;
  
  if (this->_fUnbuf == 0) {
    if (this->_gptr < this->_egptr) {
      bVar1 = *this->_gptr;
      this->_gptr = this->_gptr + 1;
      return (uint)bVar1;
    }
    iVar2 = (**(code **)(this->_padding_ + 0x20))();
    this->_gptr = this->_gptr + 1;
    return iVar2;
  }
  iVar2 = this->x_lastc;
  if (iVar2 == -1) {
    iVar2 = (**(code **)(this->_padding_ + 0x20))();
    return iVar2;
  }
  this->x_lastc = -1;
  return iVar2;
}



// public: void __thiscall streambuf::stossc(void)

void __thiscall streambuf::stossc(streambuf *this)

{
  if (this->_fUnbuf == 0) {
    if (this->_egptr <= this->_gptr) {
      (**(code **)(this->_padding_ + 0x20))();
    }
    if (this->_gptr < this->_egptr) {
      this->_gptr = this->_gptr + 1;
    }
    return;
  }
  if (this->x_lastc == -1) {
    (**(code **)(this->_padding_ + 0x20))();
    return;
  }
  this->x_lastc = -1;
  return;
}



// public: int __thiscall streambuf::sgetc(void)

int __thiscall streambuf::sgetc(streambuf *this)

{
  int iVar1;
  
  if (this->_fUnbuf != 0) {
    if (this->x_lastc == -1) {
      iVar1 = (**(code **)(this->_padding_ + 0x20))();
      this->x_lastc = iVar1;
    }
    return this->x_lastc;
  }
  iVar1 = (**(code **)(this->_padding_ + 0x20))();
  return iVar1;
}



// protected: __thiscall istream::istream(void)

istream * __thiscall istream::istream(istream *this)

{
  int in_stack_00000004;
  
  if (in_stack_00000004 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0xc);
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) =
       *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) | 1;
  this->x_gcount = 0;
  this->_fGline = 0;
  return this;
}



// public: virtual void * __thiscall istream::`scalar deleting destructor'(unsigned int)

void * __thiscall istream::_scalar_deleting_destructor_(istream *this,uint param_1)

{
  ~istream(this);
  ios::~ios((ios *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(&this[-1].field_0x34);
  }
  return &this[-1].field_0x34;
}



// public: __thiscall istream::istream(class streambuf *)

istream * __thiscall istream::istream(istream *this,streambuf *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00561faa;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (in_stack_00000008 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0xc);
    local_4 = 0;
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),param_1);
  *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) =
       *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) | 1;
  this->x_gcount = 0;
  this->_fGline = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}



// protected: __thiscall istream::istream(class istream const &)

istream * __thiscall istream::istream(istream *this,istream *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00561fda;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (in_stack_00000008 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0xc);
    local_4 = 0;
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),
            *(streambuf **)((int)&param_1->_fGline + *(int *)(*(int *)param_1 + 4)));
  *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) =
       *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) | 1;
  this->x_gcount = 0;
  this->_fGline = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}



// public: virtual __thiscall istream::~istream(void)

void __thiscall istream::~istream(istream *this)

{
  *(undefined ***)(*(int *)(*(int *)&this[-1].field_0x34 + 4) + -0xc + (int)this) = &_vftable_;
  return;
}



// protected: class istream & __thiscall istream::operator=(class streambuf *)

istream * __thiscall istream::operator=(istream *this,streambuf *param_1)

{
  undefined4 *puVar1;
  ios *piVar2;
  undefined4 *unaff_FS_OFFSET;
  ios local_40;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00561ff8;
  *unaff_FS_OFFSET = &uStack_c;
  if ((*(int *)(&this->field_0x1c + *(int *)(*(int *)this + 4)) != 0) &&
     (puVar1 = *(undefined4 **)((int)&this->_fGline + *(int *)(*(int *)this + 4)),
     puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 *)((int)&this->_fGline + *(int *)(*(int *)this + 4)) = 0;
  piVar2 = (ios *)ios::ios(&local_40);
  uStack_4 = 0;
  ios::operator=((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),piVar2);
  uStack_4 = 0xffffffff;
  ios::~ios(&local_40);
  *(undefined4 *)(&this->field_0x1c + *(int *)(*(int *)this + 4)) = 0;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),param_1);
  *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) =
       *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) | 1;
  this->x_gcount = 0;
  *unaff_FS_OFFSET = uStack_c;
  return this;
}



// public: int __thiscall istream::ipfx(int)

int __thiscall istream::ipfx(istream *this,int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 != 0) {
    this->x_gcount = 0;
  }
  iVar1 = *(int *)(*(int *)this + 4);
  uVar2 = *(uint *)((int)&this->x_gcount + iVar1);
  if (uVar2 != 0) {
    *(uint *)((int)&this->x_gcount + iVar1) = uVar2 | 2;
    return 0;
  }
  if (*(ostream **)(&this->field_0x20 + iVar1) != (ostream *)0x0) {
    if (param_1 != 0) {
      iVar4 = *(int *)((int)&this->_fGline + iVar1);
      uVar2 = *(uint *)(iVar4 + 0x2c);
      uVar3 = *(uint *)(iVar4 + 0x28);
      if (uVar3 < uVar2) {
        iVar4 = uVar2 - uVar3;
      }
      else {
        iVar4 = 0;
      }
      if (param_1 <= iVar4) goto LAB_0055b747;
    }
    ostream::flush(*(ostream **)(&this->field_0x20 + iVar1));
  }
LAB_0055b747:
  if ((param_1 == 0) && (((&this->field_0x24)[*(int *)(*(int *)this + 4)] & 1) != 0)) {
    eatwhite(this);
    uVar2 = *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4));
    if (uVar2 != 0) {
      *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) = uVar2 | 2;
      return 0;
    }
  }
  return 1;
}



// public: class istream & __thiscall istream::operator>>(char *)

istream * __thiscall istream::operator>>(istream *this,char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = ipfx(this,0);
  if (iVar1 != 0) {
    iVar1 = *(int *)(&this->field_0x30 + *(int *)(*(int *)this + 4));
    *(undefined4 *)(&this->field_0x30 + *(int *)(*(int *)this + 4)) = 0;
    if (param_1 == (char *)0x0) {
      *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
           *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 2;
      return this;
    }
    uVar4 = 0;
    if (iVar1 != 1) {
      do {
        iVar2 = streambuf::sgetc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
        if (iVar2 == -1) {
          *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
               *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 1;
          if (uVar4 != 0) goto LAB_0055b867;
          *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
               *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 6;
          break;
        }
        iVar3 = isspace(iVar2);
        if (iVar3 != 0) break;
        param_1[uVar4] = (char)iVar2;
        streambuf::stossc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
        uVar4 = uVar4 + 1;
      } while (uVar4 < iVar1 - 1U);
    }
    if (uVar4 == 0) {
      *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
           *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 2;
      return this;
    }
LAB_0055b867:
    param_1[uVar4] = '\0';
  }
  return this;
}



// public: int __thiscall istream::peek(void)

int __thiscall istream::peek(istream *this)

{
  int iVar1;
  
  iVar1 = ipfx(this,1);
  if (iVar1 != 0) {
    iVar1 = streambuf::sgetc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
    return iVar1;
  }
  return -1;
}



// public: class istream & __thiscall istream::putback(char)

istream * __thiscall istream::putback(istream *this,char param_1)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  
  if (*(int *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) == 0) {
    piVar1 = *(int **)((int)&this->_fGline + *(int *)(*(int *)this + 4));
    if ((uint)piVar1[9] < (uint)piVar1[10]) {
      pcVar2 = (char *)(piVar1[10] - 1);
      piVar1[10] = (int)pcVar2;
      *pcVar2 = param_1;
      iVar3 = (int)param_1;
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0x24))((int)param_1);
    }
    if (iVar3 == -1) {
      *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
           *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 2;
    }
  }
  return this;
}



// public: int __thiscall istream::sync(void)

int __thiscall istream::sync(istream *this)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)((int)&this->_fGline + *(int *)(*(int *)this + 4)) + 4))();
  if (iVar1 == -1) {
    *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
         *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 6;
  }
  return iVar1;
}



// public: void __thiscall istream::eatwhite(void)

void __thiscall istream::eatwhite(istream *this)

{
  int iVar1;
  
  iVar1 = streambuf::sgetc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
  while( true ) {
    if (iVar1 == -1) {
      *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
           *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 1;
      return;
    }
    iVar1 = isspace(iVar1);
    if (iVar1 == 0) break;
    iVar1 = streambuf::snextc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
  }
  return;
}



// public: __thiscall istream_withassign::istream_withassign(void)

istream_withassign * __thiscall istream_withassign::istream_withassign(istream_withassign *this)

{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000004;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00562026;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (in_stack_00000004 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)(this + 0xc));
    local_4 = 0;
  }
  istream::istream((istream *)this);
  *(undefined ***)(this + *(int *)(*(int *)this + 4)) = &_vftable_;
  *unaff_FS_OFFSET = this;
  return this;
}



// public: virtual void * __thiscall istream_withassign::`vector deleting destructor'(unsigned int)

void * __thiscall
istream_withassign::_vector_deleting_destructor_(istream_withassign *this,uint param_1)

{
  ~istream_withassign(this);
  ios::~ios((ios *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this + -0xc);
  }
  return this + -0xc;
}



// public: __thiscall istream_withassign::istream_withassign(class streambuf *)

istream_withassign * __thiscall
istream_withassign::istream_withassign(istream_withassign *this,streambuf *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00562046;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (in_stack_00000008 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)(this + 0xc));
    local_4 = 0;
  }
  istream::istream((istream *)this,param_1);
  *(undefined ***)(this + *(int *)(*(int *)this + 4)) = &_vftable_;
  *unaff_FS_OFFSET = this;
  return this;
}



// public: virtual __thiscall istream_withassign::~istream_withassign(void)

void __thiscall istream_withassign::~istream_withassign(istream_withassign *this)

{
  *(undefined ***)(this + *(int *)(*(int *)(this + -0xc) + 4) + -0xc) = &_vftable_;
  istream::~istream((istream *)this);
  return;
}



void _WSAStartup_8(void)

{
                    // WARNING: Could not recover jumptable at 0x0055bae0. Too many branches
                    // WARNING: Treating indirect jump as call
  WSAStartup();
  return;
}



void _WSACleanup_0(void)

{
                    // WARNING: Could not recover jumptable at 0x0055bae6. Too many branches
                    // WARNING: Treating indirect jump as call
  WSACleanup();
  return;
}



// __stdcall gethostname,8

void gethostname(void)

{
                    // WARNING: Could not recover jumptable at 0x0055baec. Too many branches
                    // WARNING: Treating indirect jump as call
  gethostname();
  return;
}



// __stdcall gethostbyname,4

void gethostbyname(void)

{
                    // WARNING: Could not recover jumptable at 0x0055baf2. Too many branches
                    // WARNING: Treating indirect jump as call
  gethostbyname();
  return;
}



void _RtlUnwind_16(void)

{
                    // WARNING: Could not recover jumptable at 0x0055baf8. Too many branches
                    // WARNING: Treating indirect jump as call
  RtlUnwind();
  return;
}



// strupr

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



// itoa

undefined4 __cdecl itoa(int param_1,undefined4 param_2,int param_3)

{
  if ((param_3 == 10) && (param_1 < 0)) {
    FUN_0055bd40(param_1,param_2,10,1);
    return param_2;
  }
  FUN_0055bd40(param_1,param_2,param_3,0);
  return param_2;
}



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



// public: virtual __thiscall type_info::~type_info(void)

void __thiscall type_info::~type_info(type_info *this)

{
  *(undefined ***)this = &_vftable_;
  if (*(int *)(this + 4) != 0) {
    free(*(int *)(this + 4));
  }
  return;
}



// public: virtual void * __thiscall type_info::`vector deleting destructor'(unsigned int)

void * __thiscall type_info::_vector_deleting_destructor_(type_info *this,uint param_1)

{
  ~type_info(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// public: int __thiscall type_info::operator==(class type_info const &)const 

int __thiscall type_info::operator==(type_info *this,type_info *param_1)

{
  type_info tVar1;
  type_info *ptVar2;
  type_info *ptVar3;
  bool bVar4;
  
  ptVar3 = this + 9;
  ptVar2 = param_1 + 9;
  while( true ) {
    tVar1 = *ptVar2;
    bVar4 = (byte)tVar1 < (byte)*ptVar3;
    if (tVar1 != *ptVar3) break;
    if (tVar1 == (type_info)0x0) {
      return 1;
    }
    tVar1 = ptVar2[1];
    bVar4 = (byte)tVar1 < (byte)ptVar3[1];
    if (tVar1 != ptVar3[1]) break;
    ptVar2 = ptVar2 + 2;
    ptVar3 = ptVar3 + 2;
    if (tVar1 == (type_info)0x0) {
      return 1;
    }
  }
  return (uint)(1 - bVar4 == (uint)(bVar4 != 0));
}



// public: int __thiscall type_info::operator!=(class type_info const &)const 

int __thiscall type_info::operator!=(type_info *this,type_info *param_1)

{
  type_info tVar1;
  type_info *ptVar2;
  type_info *ptVar3;
  bool bVar4;
  
  ptVar3 = this + 9;
  ptVar2 = param_1 + 9;
  while( true ) {
    tVar1 = *ptVar2;
    bVar4 = (byte)tVar1 < (byte)*ptVar3;
    if (tVar1 != *ptVar3) break;
    if (tVar1 == (type_info)0x0) {
      return 0;
    }
    tVar1 = ptVar2[1];
    bVar4 = (byte)tVar1 < (byte)ptVar3[1];
    if (tVar1 != ptVar3[1]) break;
    ptVar2 = ptVar2 + 2;
    ptVar3 = ptVar3 + 2;
    if (tVar1 == (type_info)0x0) {
      return 0;
    }
  }
  return (uint)(1 - bVar4 != (uint)(bVar4 != 0));
}



// public: int __thiscall type_info::before(class type_info const &)const 

int __thiscall type_info::before(type_info *this,type_info *param_1)

{
  type_info tVar1;
  uint uVar2;
  uint uVar3;
  type_info *ptVar4;
  type_info *ptVar5;
  bool bVar6;
  
  ptVar5 = this + 9;
  ptVar4 = param_1 + 9;
  while( true ) {
    tVar1 = *ptVar4;
    bVar6 = (byte)tVar1 < (byte)*ptVar5;
    if (tVar1 != *ptVar5) break;
    if (tVar1 == (type_info)0x0) {
      return 0;
    }
    tVar1 = ptVar4[1];
    bVar6 = (byte)tVar1 < (byte)ptVar5[1];
    if (tVar1 != ptVar5[1]) break;
    ptVar4 = ptVar4 + 2;
    ptVar5 = ptVar5 + 2;
    if (tVar1 == (type_info)0x0) {
      return 0;
    }
  }
  uVar2 = (uint)(bVar6 != 0);
  uVar3 = 1 - bVar6;
  return (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2));
}



// public: char const * __thiscall type_info::raw_name(void)const 

char * __thiscall type_info::raw_name(type_info *this)

{
  return (char *)(this + 8);
}



// private: __thiscall type_info::type_info(class type_info const &)

void __thiscall type_info::type_info(type_info *this,type_info *param_1)

{
  *(undefined ***)this = &_vftable_;
  return;
}



// private: class type_info & __thiscall type_info::operator=(class type_info const &)

type_info * __thiscall type_info::operator=(type_info *this,type_info *param_1)

{
  return this;
}



void _ASMSet_Shadowing(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DAT_0088c058._8_4_ = param_1;
  DAT_0088c058._16_4_ = param_1;
  DAT_0088c058._24_4_ = param_2;
  DAT_0088c058._32_4_ = param_2;
  DAT_0088c058._12_4_ = param_3;
  DAT_0088c058._20_4_ = param_3;
  DAT_0088c058._28_4_ = param_4;
  DAT_0088c058._36_4_ = param_4;
  return;
}



void _ASMSet_ShadowingEx(undefined4 *param_1)

{
  DAT_0088c058._8_4_ = *param_1;
  DAT_0088c058._12_4_ = param_1[1];
  DAT_0088c058._16_4_ = param_1[2];
  DAT_0088c058._20_4_ = param_1[3];
  DAT_0088c058._24_4_ = param_1[4];
  DAT_0088c058._28_4_ = param_1[5];
  DAT_0088c058._32_4_ = param_1[6];
  DAT_0088c058._36_4_ = param_1[7];
  return;
}



void _ASMSet_Surface_Info
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  DAT_0088c000 = param_1;
  DAT_0088c004 = param_2;
  DAT_0088c008 = param_3;
  DAT_0088c080 = param_5;
  DAT_0088c084 = param_7;
  DAT_0088c088 = param_4;
  DAT_0088c08c = param_6;
  return;
}



void _ASMSet_Color_Xform(byte param_1)

{
  DAT_0088c040 = CONCAT22((ushort)param_1 |
                          (ushort)(((uint)CONCAT11(param_1,param_1) << 0x18) >> 0x10),
                          CONCAT11(param_1,param_1));
  return;
}



uint _ASMGet_Color_Xform(void)

{
  return DAT_0088c040 & 0xff;
}



void _ASMSet_Xlate_Table(undefined4 param_1)

{
  DAT_0088c01c = param_1;
  return;
}



void _ASMDraw_HLine(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  iVar2 = param_1;
  if (param_3 < DAT_0088c080) {
    return;
  }
  if (DAT_0088c084 < param_3) {
    return;
  }
  if (param_2 < param_1) {
    param_1 = param_2;
    param_2 = iVar2;
  }
  if (param_2 < DAT_0088c088) {
    return;
  }
  if (DAT_0088c08c < param_1) {
    return;
  }
  if (param_1 < DAT_0088c088) {
    param_1 = DAT_0088c088;
  }
  if (DAT_0088c08c < param_2) {
    param_2 = DAT_0088c08c;
  }
  piVar1 = *(int **)(DAT_0088c004 + param_3 * 4);
  if (piVar1 == (int *)0x0) {
    return;
  }
  DAT_0088c038 = (param_2 - param_1) + 1;
  DAT_0088c044._0_4_ = 0x56c99a;
  DAT_0088c020 = *(int *)(DAT_0088c000 + param_3 * 4);
  DAT_0088c014 = DAT_0088c020 + param_1;
  piVar5 = piVar1;
  while( true ) {
    if (param_2 < piVar5[2]) {
      DAT_0088c03c = piVar1;
      DAT_0088c044._0_4_ = 0x56c99a;
      return;
    }
    if (param_1 <= piVar5[3]) break;
    piVar5 = (int *)*piVar5;
    if (piVar5 == (int *)0x0) {
      DAT_0088c03c = piVar1;
      DAT_0088c044._0_4_ = 0x56c99a;
      return;
    }
  }
  if ((piVar5[2] <= param_1) && (param_2 <= piVar5[3])) {
    uVar3 = DAT_0088c038 & 0x7f;
    if (0x7f < (int)DAT_0088c038) {
      uVar3 = (uint)(byte)((byte)uVar3 | 0x80);
    }
                    // WARNING: Could not recover jumptable at 0x0056c8eb. Too many branches
                    // WARNING: Treating indirect jump as call
    DAT_0088c03c = piVar1;
    (**(code **)(&LAB_0056a6ff_1 + (uint)((byte)DAT_0088c014 & 3 | (&LAB_0056b2ff_1)[uVar3]) * 4))()
    ;
    return;
  }
  while( true ) {
    DAT_0088c03c = piVar5;
    DAT_0088c044._0_4_ = 0x56c99a;
    if (param_2 < DAT_0088c03c[2]) {
      DAT_0088c044._0_4_ = 0x56c99a;
      return;
    }
    if (param_1 <= DAT_0088c03c[3]) break;
    piVar5 = (int *)*DAT_0088c03c;
    if ((int *)*DAT_0088c03c == (int *)0x0) {
      DAT_0088c044._0_4_ = 0x56c99a;
      return;
    }
  }
  DAT_0088c044._8_4_ = 0;
  uVar3 = DAT_0088c038;
  if (param_1 < DAT_0088c03c[2]) {
    DAT_0088c044._8_4_ = DAT_0088c03c[2] - param_1;
    uVar3 = DAT_0088c038 - DAT_0088c044._8_4_;
  }
  if (DAT_0088c03c[3] < param_2) {
    uVar3 = uVar3 - (param_2 - DAT_0088c03c[3]);
    DAT_0088c044._0_4_ = 0x56c8fa;
  }
  uVar4 = uVar3 & 0x7f;
  if (0x7f < (int)uVar3) {
    uVar4 = (uint)(byte)((byte)uVar4 | 0x80);
  }
                    // WARNING: Could not recover jumptable at 0x0056c993. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(&LAB_0056a6ff_1 +
              (uint)((byte)DAT_0088c014 + (char)DAT_0088c044._8_4_ & 3 | (&LAB_0056b2ff_1)[uVar4]) *
              4))();
  return;
}



void _ASMDraw_Sprite(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                    int param_7,uint param_8)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  byte bVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  byte *pbVar12;
  byte *pbVar13;
  
  iVar10 = 0;
  iVar9 = param_5 + -1 + param_3;
  if ((DAT_0088c080 <= iVar9) && (param_3 <= DAT_0088c084)) {
    if (param_3 < DAT_0088c080) {
      param_5 = param_5 - (DAT_0088c080 - param_3);
      iVar10 = (DAT_0088c080 - param_3) * 4;
      param_3 = 0;
    }
    if (DAT_0088c084 < iVar9) {
      param_5 = param_5 - (iVar9 - DAT_0088c084);
    }
    DAT_0088c038 = 0;
    DAT_0088c024 = param_2;
    if (param_2 <= DAT_0088c08c) {
      DAT_0088c028 = param_2 + param_4 + -1;
      if (DAT_0088c088 <= DAT_0088c028) {
        DAT_0088c00c = param_6 + param_1 + iVar10;
        DAT_0088c010 = param_7 + param_1 + iVar10;
        DAT_0088c044._4_4_ = 0;
        if ((param_8 & 1) == 0) {
          DAT_0088c02c._4_4_ = 0;
          DAT_0088c02c._0_4_ = 0xffffffff;
          DAT_0088c02c._8_4_ = DAT_0088c040;
        }
        else {
          DAT_0088c044._4_4_ = 0x80;
        }
        uVar5 = DAT_0088c044._4_4_;
        if ((param_8 & 2) != 0) {
          do {
            piVar11 = *(int **)(DAT_0088c008 + (param_3 + DAT_0088c038) * 4);
            piVar6 = DAT_0088c03c;
            if (piVar11 != (int *)0x0) {
              if (DAT_0088c044._4_1_ != '\0') {
                uVar7 = param_3 + DAT_0088c038 & 3;
                DAT_0088c02c._4_4_ = *(uint *)(&DAT_0088c058.field_0x18 + uVar7 * 4);
                DAT_0088c02c._0_4_ = *(uint *)(&DAT_0088c058.field_0x8 + uVar7 * 4);
                DAT_0088c02c._8_4_ = DAT_0088c040 & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
              }
              uVar2 = *(ushort *)(DAT_0088c010 + 2 + DAT_0088c038 * 4);
              piVar6 = piVar11;
              if ((uVar2 & 0x8000) == 0) {
                iVar10 = param_2 + (uint)uVar2;
                iVar9 = DAT_0088c028 - (uint)*(ushort *)(DAT_0088c010 + DAT_0088c038 * 4);
                DAT_0088c020 = *(int *)(DAT_0088c000 + (param_3 + DAT_0088c038) * 4);
                DAT_0088c014 = DAT_0088c020 + iVar9;
                DAT_0088c018 = (byte *)(*(int *)(DAT_0088c00c + DAT_0088c038 * 4) + param_1);
                DAT_0088c03c = piVar11;
                do {
                  if (DAT_0088c03c[3] < iVar10) break;
                  if (DAT_0088c03c[2] <= iVar9) {
                    if ((iVar10 < DAT_0088c03c[2]) || (DAT_0088c03c[3] < iVar9)) {
                      DAT_0088c044._0_4_ = 0x56d6c0;
                      DAT_0088c044._12_4_ = DAT_0088c018;
                      DAT_0088c054 = DAT_0088c014;
                      goto LAB_0056d6c0;
                    }
                    DAT_0088c044._0_4_ = 0x56d420;
                    pbVar12 = DAT_0088c018;
                    iVar9 = DAT_0088c014;
                    goto LAB_0056d420;
                  }
                  DAT_0088c03c = (int *)DAT_0088c03c[1];
                } while (DAT_0088c03c != (int *)0x0);
              }
            }
switchD_0056d42a_caseD_f:
            DAT_0088c03c = piVar6;
            DAT_0088c038 = DAT_0088c038 + 1;
            if (param_5 <= DAT_0088c038) {
              DAT_0088c044._4_4_ = uVar5;
              return;
            }
          } while( true );
        }
        do {
          piVar11 = *(int **)(DAT_0088c004 + (param_3 + DAT_0088c038) * 4);
          piVar6 = DAT_0088c03c;
          if (piVar11 != (int *)0x0) {
            if (DAT_0088c044._4_1_ != '\0') {
              uVar7 = param_3 + DAT_0088c038 & 3;
              DAT_0088c02c._4_4_ = *(uint *)(&DAT_0088c058.field_0x18 + uVar7 * 4);
              DAT_0088c02c._0_4_ = *(uint *)(&DAT_0088c058.field_0x8 + uVar7 * 4);
              DAT_0088c02c._8_4_ = DAT_0088c040 & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
            }
            uVar2 = *(ushort *)(DAT_0088c010 + DAT_0088c038 * 4);
            piVar6 = piVar11;
            if ((uVar2 & 0x8000) == 0) {
              iVar10 = param_2 + (uint)uVar2;
              iVar9 = DAT_0088c028 - (uint)*(ushort *)(DAT_0088c010 + 2 + DAT_0088c038 * 4);
              DAT_0088c020 = *(int *)(DAT_0088c000 + (param_3 + DAT_0088c038) * 4);
              DAT_0088c014 = DAT_0088c020 + iVar10;
              DAT_0088c018 = (byte *)(*(int *)(DAT_0088c00c + DAT_0088c038 * 4) + param_1);
              DAT_0088c03c = piVar11;
              do {
                if (iVar9 < DAT_0088c03c[2]) break;
                if (iVar10 <= DAT_0088c03c[3]) {
                  if ((iVar10 < DAT_0088c03c[2]) || (DAT_0088c03c[3] < iVar9)) {
                    DAT_0088c044._0_4_ = 0x56cc20;
                    DAT_0088c044._12_4_ = DAT_0088c018;
                    DAT_0088c054 = DAT_0088c014;
                    goto LAB_0056cc20;
                  }
                  DAT_0088c044._0_4_ = 0x56d0a0;
                  pbVar12 = DAT_0088c018;
                  iVar9 = DAT_0088c014;
                  goto LAB_0056d0a0;
                }
                DAT_0088c03c = (int *)*DAT_0088c03c;
              } while (DAT_0088c03c != (int *)0x0);
            }
          }
switchD_0056d0aa_caseD_f:
          DAT_0088c03c = piVar6;
          DAT_0088c038 = DAT_0088c038 + 1;
        } while (DAT_0088c038 < param_5);
      }
    }
  }
  return;
LAB_0056d420:
  do {
    bVar1 = *pbVar12;
    pbVar13 = pbVar12 + 1;
    bVar4 = (byte)iVar9;
    switch(bVar1 & 0xf) {
    default:
                    // WARNING: Could not recover jumptable at 0x0056d474. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar4 & 3 | (&LAB_0056b2ff_1)[bVar1 >> 2] | DAT_0088c044._4_1_) * 4))
                ();
      return;
    case 1:
    case 5:
    case 9:
    case 0xd:
      iVar9 = iVar9 - (uint)(bVar1 >> 2);
      pbVar12 = pbVar13;
      break;
    case 2:
                    // WARNING: Could not recover jumptable at 0x0056d4a0. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar4 & 3 | DAT_0088c044._4_1_ |
                              (&LAB_0056b2ff_1)[-(char)(((uint)bVar1 << 4) >> 8) & 0x80U | *pbVar13]
                              ) * 4))();
      return;
    case 3:
      pbVar12 = pbVar12 + 2;
      iVar9 = iVar9 - (uint)*pbVar13;
      break;
    case 6:
      uVar7 = (uint)(bVar1 >> 4);
      if (uVar7 == 0) {
        uVar7 = (uint)*pbVar13;
      }
                    // WARNING: Could not recover jumptable at 0x0056d4ff. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&DAT_0056be00 +
                  (uint)(byte)(bVar4 & 3 | (&LAB_0056b2ff_1)[uVar7] | DAT_0088c044._4_1_) * 4))();
      return;
    case 7:
      uVar7 = (uint)(bVar1 >> 4);
      if (uVar7 == 0) {
        uVar7 = (uint)*pbVar13;
      }
                    // WARNING: Could not recover jumptable at 0x0056d551. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar4 & 3 | (&LAB_0056b2ff_1)[uVar7] | DAT_0088c044._4_1_) * 4))();
      return;
    case 10:
      uVar7 = (uint)(bVar1 >> 4);
      if (uVar7 == 0) {
        uVar7 = (uint)*pbVar13;
      }
                    // WARNING: Could not recover jumptable at 0x0056d591. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar4 & 3 | (&LAB_0056b2ff_1)[uVar7] | DAT_0088c044._4_1_) * 4))();
      return;
    case 0xb:
      uVar7 = (uint)(bVar1 >> 4);
      if (uVar7 == 0) {
        uVar7 = (uint)*pbVar13;
      }
                    // WARNING: Could not recover jumptable at 0x0056d5c1. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(bVar4 & 3 | (&LAB_0056b2ff_1)[uVar7] | DAT_0088c044._4_1_) * 4))();
      return;
    case 0xe:
                    // WARNING: Could not recover jumptable at 0x0056d445. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&DAT_0056b5c0 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
      goto switchD_0056d42a_caseD_f;
    }
  } while( true );
LAB_0056d6c0:
  bVar1 = *(byte *)DAT_0088c044._12_4_;
  iVar9 = DAT_0088c054 - DAT_0088c020;
  pbVar12 = (byte *)(DAT_0088c044._12_4_ + 1);
  cVar3 = (char)DAT_0088c054;
  piVar6 = DAT_0088c03c;
  switch(bVar1 & 0xf) {
  default:
    uVar7 = (uint)(bVar1 >> 2);
    break;
  case 1:
  case 5:
  case 9:
  case 0xd:
    DAT_0088c054 = DAT_0088c054 - (uint)(bVar1 >> 2);
    DAT_0088c044._12_4_ = pbVar12;
    goto LAB_0056d6c0;
  case 2:
    uVar7 = CONCAT31((int3)(((uint)bVar1 << 4) >> 8),*pbVar12);
    pbVar12 = (byte *)(DAT_0088c044._12_4_ + 2);
    break;
  case 3:
    DAT_0088c044._12_4_ = DAT_0088c044._12_4_ + 2;
    DAT_0088c054 = DAT_0088c054 - CONCAT31((int3)(((uint)bVar1 << 4) >> 8),*pbVar12);
    goto LAB_0056d6c0;
  case 6:
    uVar7 = (uint)(bVar1 >> 4);
    if (uVar7 == 0) {
      uVar7 = (uint)*pbVar12;
      pbVar12 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar10 = (iVar9 - uVar7) + 1;
    piVar11 = DAT_0088c03c;
    while (iVar10 <= piVar11[3]) {
      if (piVar11[2] <= iVar9) {
        DAT_0088c044._8_4_ = 0;
        if (piVar11[3] < iVar9) {
          DAT_0088c044._8_4_ = iVar9 - piVar11[3];
          uVar7 = uVar7 - DAT_0088c044._8_4_;
        }
        if (iVar10 < piVar11[2]) {
          uVar7 = uVar7 - (piVar11[2] - iVar10);
          DAT_0088c044._0_4_ = &LAB_0056d660;
        }
                    // WARNING: Could not recover jumptable at 0x0056d865. Too many branches
                    // WARNING: Treating indirect jump as call
        (**(code **)(&DAT_0056be00 +
                    (uint)(byte)(cVar3 - (char)DAT_0088c044._8_4_ & 3U | (&LAB_0056b2ff_1)[uVar7] |
                                DAT_0088c044._4_1_) * 4))();
        return;
      }
      piVar11 = (int *)piVar11[1];
      if (piVar11 == (int *)0x0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = pbVar12 + uVar7;
    DAT_0088c054 = DAT_0088c054 - uVar7;
    goto LAB_0056d6c0;
  case 7:
    uVar7 = (uint)(bVar1 >> 4);
    if (uVar7 == 0) {
      uVar7 = (uint)*pbVar12;
      pbVar12 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar10 = (iVar9 - uVar7) + 1;
    piVar11 = DAT_0088c03c;
    while (iVar10 <= piVar11[3]) {
      if (piVar11[2] <= iVar9) {
        DAT_0088c044._8_4_ = 0;
        if (piVar11[3] < iVar9) {
          DAT_0088c044._8_4_ = iVar9 - piVar11[3];
          uVar7 = uVar7 - DAT_0088c044._8_4_;
        }
        if (iVar10 < piVar11[2]) {
          uVar7 = uVar7 - (piVar11[2] - iVar10);
          DAT_0088c044._0_4_ = &LAB_0056d660;
        }
                    // WARNING: Could not recover jumptable at 0x0056d915. Too many branches
                    // WARNING: Treating indirect jump as call
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar3 - (char)DAT_0088c044._8_4_ & 3U | (&LAB_0056b2ff_1)[uVar7] |
                                DAT_0088c044._4_1_) * 4))();
        return;
      }
      piVar11 = (int *)piVar11[1];
      if (piVar11 == (int *)0x0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = pbVar12 + 1;
    DAT_0088c054 = DAT_0088c054 - uVar7;
    goto LAB_0056d6c0;
  case 10:
    uVar7 = (uint)(bVar1 >> 4);
    if (uVar7 == 0) {
      uVar7 = (uint)*pbVar12;
      pbVar12 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar10 = (iVar9 - uVar7) + 1;
    piVar11 = DAT_0088c03c;
    while (iVar10 <= piVar11[3]) {
      if (piVar11[2] <= iVar9) {
        DAT_0088c044._8_4_ = 0;
        if (piVar11[3] < iVar9) {
          DAT_0088c044._8_4_ = iVar9 - piVar11[3];
          uVar7 = uVar7 - DAT_0088c044._8_4_;
        }
        if (iVar10 < piVar11[2]) {
          uVar7 = uVar7 - (piVar11[2] - iVar10);
          DAT_0088c044._0_4_ = &LAB_0056d660;
        }
                    // WARNING: Could not recover jumptable at 0x0056d9b5. Too many branches
                    // WARNING: Treating indirect jump as call
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar3 - (char)DAT_0088c044._8_4_ & 3U | (&LAB_0056b2ff_1)[uVar7] |
                                DAT_0088c044._4_1_) * 4))();
        return;
      }
      piVar11 = (int *)piVar11[1];
      if (piVar11 == (int *)0x0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = pbVar12 + 1;
    DAT_0088c054 = DAT_0088c054 - uVar7;
    goto LAB_0056d6c0;
  case 0xb:
    goto switchD_0056d6e2_caseD_b;
  case 0xe:
                    // WARNING: Could not recover jumptable at 0x0056d705. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(&DAT_0056b580 + (uint)(bVar1 >> 4) * 4))();
    return;
  case 0xf:
    goto switchD_0056d42a_caseD_f;
  }
  iVar10 = (iVar9 - uVar7) + 1;
  piVar11 = DAT_0088c03c;
  while (iVar10 <= piVar11[3]) {
    if (piVar11[2] <= iVar9) {
      DAT_0088c044._8_4_ = 0;
      if (piVar11[3] < iVar9) {
        DAT_0088c044._8_4_ = iVar9 - piVar11[3];
        uVar7 = uVar7 - DAT_0088c044._8_4_;
      }
      sVar8 = (short)uVar7;
      if (iVar10 < piVar11[2]) {
        sVar8 = sVar8 - ((short)piVar11[2] - (short)iVar10);
        DAT_0088c044._0_4_ = &LAB_0056d660;
      }
                    // WARNING: Could not recover jumptable at 0x0056d78b. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(cVar3 - (char)DAT_0088c044._8_4_ & 3U | DAT_0088c044._4_1_ |
                              (&LAB_0056b2ff_1)
                              [(byte)(-(char)((ushort)sVar8 >> 8) & 0x80U | (byte)sVar8)]) * 4))();
      return;
    }
    piVar11 = (int *)piVar11[1];
    if (piVar11 == (int *)0x0) goto switchD_0056d42a_caseD_f;
  }
  DAT_0088c054 = DAT_0088c054 - uVar7;
  DAT_0088c044._12_4_ = pbVar12 + uVar7;
  goto LAB_0056d6c0;
switchD_0056d6e2_caseD_b:
  uVar7 = (uint)(bVar1 >> 4);
  if (uVar7 == 0) {
    uVar7 = (uint)*pbVar12;
    pbVar12 = (byte *)(DAT_0088c044._12_4_ + 2);
  }
  iVar10 = (iVar9 - uVar7) + 1;
  piVar11 = DAT_0088c03c;
  while (iVar10 <= piVar11[3]) {
    if (piVar11[2] <= iVar9) {
      DAT_0088c044._8_4_ = 0;
      if (piVar11[3] < iVar9) {
        DAT_0088c044._8_4_ = iVar9 - piVar11[3];
        uVar7 = uVar7 - DAT_0088c044._8_4_;
      }
      if (iVar10 < piVar11[2]) {
        uVar7 = uVar7 - (piVar11[2] - iVar10);
        DAT_0088c044._0_4_ = &LAB_0056d660;
      }
                    // WARNING: Could not recover jumptable at 0x0056da45. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(cVar3 - (char)DAT_0088c044._8_4_ & 3U | (&LAB_0056b2ff_1)[uVar7] |
                              DAT_0088c044._4_1_) * 4))();
      return;
    }
    piVar11 = (int *)piVar11[1];
    if (piVar11 == (int *)0x0) goto switchD_0056d42a_caseD_f;
  }
  DAT_0088c054 = DAT_0088c054 - uVar7;
  DAT_0088c044._12_4_ = pbVar12;
  goto LAB_0056d6c0;
LAB_0056d0a0:
  do {
    bVar1 = *pbVar12;
    pbVar13 = pbVar12 + 1;
    bVar4 = (byte)iVar9;
    switch(bVar1 & 0xf) {
    default:
                    // WARNING: Could not recover jumptable at 0x0056d0f4. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&LAB_0056a300 +
                  (uint)(byte)(bVar4 & 3 | (&LAB_0056b2ff_1)[bVar1 >> 2] | DAT_0088c044._4_1_) * 4))
                ();
      return;
    case 1:
    case 5:
    case 9:
    case 0xd:
      iVar9 = iVar9 + (uint)(bVar1 >> 2);
      pbVar12 = pbVar13;
      break;
    case 2:
                    // WARNING: Could not recover jumptable at 0x0056d120. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&LAB_0056a300 +
                  (uint)(byte)(bVar4 & 3 | DAT_0088c044._4_1_ |
                              (&LAB_0056b2ff_1)[-(char)(((uint)bVar1 << 4) >> 8) & 0x80U | *pbVar13]
                              ) * 4))();
      return;
    case 3:
      pbVar12 = pbVar12 + 2;
      iVar9 = iVar9 + (uint)*pbVar13;
      break;
    case 6:
      uVar7 = (uint)(bVar1 >> 4);
      if (uVar7 == 0) {
        uVar7 = (uint)*pbVar13;
      }
                    // WARNING: Could not recover jumptable at 0x0056d17f. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&LAB_0056aaff_1 +
                  (uint)(byte)(bVar4 & 3 | (&LAB_0056b2ff_1)[uVar7] | DAT_0088c044._4_1_) * 4))();
      return;
    case 7:
      uVar7 = (uint)(bVar1 >> 4);
      if (uVar7 == 0) {
        uVar7 = (uint)*pbVar13;
      }
                    // WARNING: Could not recover jumptable at 0x0056d1d1. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&LAB_0056a6ff_1 +
                  (uint)(byte)(bVar4 & 3 | (&LAB_0056b2ff_1)[uVar7] | DAT_0088c044._4_1_) * 4))();
      return;
    case 10:
      uVar7 = (uint)(bVar1 >> 4);
      if (uVar7 == 0) {
        uVar7 = (uint)*pbVar13;
      }
                    // WARNING: Could not recover jumptable at 0x0056d211. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&LAB_0056a6ff_1 +
                  (uint)(byte)(bVar4 & 3 | (&LAB_0056b2ff_1)[uVar7] | DAT_0088c044._4_1_) * 4))();
      return;
    case 0xb:
      uVar7 = (uint)(bVar1 >> 4);
      if (uVar7 == 0) {
        uVar7 = (uint)*pbVar13;
      }
                    // WARNING: Could not recover jumptable at 0x0056d241. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&LAB_0056aeff_1 +
                  (uint)(byte)(bVar4 & 3 | (&LAB_0056b2ff_1)[uVar7] | DAT_0088c044._4_1_) * 4))();
      return;
    case 0xe:
                    // WARNING: Could not recover jumptable at 0x0056d0c5. Too many branches
                    // WARNING: Treating indirect jump as call
      DAT_0088c03c = piVar11;
      (**(code **)(&DAT_0056b4c0 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
      goto switchD_0056d0aa_caseD_f;
    }
  } while( true );
LAB_0056cc20:
  bVar1 = *(byte *)DAT_0088c044._12_4_;
  iVar9 = DAT_0088c054 - DAT_0088c020;
  pbVar12 = (byte *)(DAT_0088c044._12_4_ + 1);
  cVar3 = (char)DAT_0088c054;
  piVar6 = DAT_0088c03c;
  switch(bVar1 & 0xf) {
  default:
    uVar7 = (uint)(bVar1 >> 2);
    break;
  case 1:
  case 5:
  case 9:
  case 0xd:
    DAT_0088c054 = DAT_0088c054 + (uint)(bVar1 >> 2);
    DAT_0088c044._12_4_ = pbVar12;
    goto LAB_0056cc20;
  case 2:
    uVar7 = CONCAT31((int3)(((uint)bVar1 << 4) >> 8),*pbVar12);
    pbVar12 = (byte *)(DAT_0088c044._12_4_ + 2);
    break;
  case 3:
    DAT_0088c044._12_4_ = DAT_0088c044._12_4_ + 2;
    DAT_0088c054 = DAT_0088c054 + CONCAT31((int3)(((uint)bVar1 << 4) >> 8),*pbVar12);
    goto LAB_0056cc20;
  case 6:
    uVar7 = (uint)(bVar1 >> 4);
    if (uVar7 == 0) {
      uVar7 = (uint)*pbVar12;
      pbVar12 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar10 = iVar9 + uVar7 + -1;
    piVar11 = DAT_0088c03c;
    while (piVar11[2] <= iVar10) {
      if (iVar9 <= piVar11[3]) {
        DAT_0088c044._8_4_ = 0;
        if (iVar9 < piVar11[2]) {
          DAT_0088c044._8_4_ = piVar11[2] - iVar9;
          uVar7 = uVar7 - DAT_0088c044._8_4_;
        }
        if (piVar11[3] < iVar10) {
          uVar7 = uVar7 - (iVar10 - piVar11[3]);
          DAT_0088c044._0_4_ = &LAB_0056cbc0;
        }
                    // WARNING: Could not recover jumptable at 0x0056cdc5. Too many branches
                    // WARNING: Treating indirect jump as call
        (**(code **)(&LAB_0056aaff_1 +
                    (uint)(byte)(cVar3 + (char)DAT_0088c044._8_4_ & 3U | (&LAB_0056b2ff_1)[uVar7] |
                                DAT_0088c044._4_1_) * 4))();
        return;
      }
      piVar11 = (int *)*piVar11;
      if (piVar11 == (int *)0x0) goto switchD_0056d0aa_caseD_f;
    }
    DAT_0088c044._12_4_ = pbVar12 + uVar7;
    DAT_0088c054 = DAT_0088c054 + uVar7;
    goto LAB_0056cc20;
  case 7:
    uVar7 = (uint)(bVar1 >> 4);
    if (uVar7 == 0) {
      uVar7 = (uint)*pbVar12;
      pbVar12 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar10 = iVar9 + uVar7 + -1;
    piVar11 = DAT_0088c03c;
    while (piVar11[2] <= iVar10) {
      if (iVar9 <= piVar11[3]) {
        DAT_0088c044._8_4_ = 0;
        if (iVar9 < piVar11[2]) {
          DAT_0088c044._8_4_ = piVar11[2] - iVar9;
          uVar7 = uVar7 - DAT_0088c044._8_4_;
        }
        if (piVar11[3] < iVar10) {
          uVar7 = uVar7 - (iVar10 - piVar11[3]);
          DAT_0088c044._0_4_ = &LAB_0056cbc0;
        }
                    // WARNING: Could not recover jumptable at 0x0056ce75. Too many branches
                    // WARNING: Treating indirect jump as call
        (**(code **)(&LAB_0056a6ff_1 +
                    (uint)(byte)(cVar3 + (char)DAT_0088c044._8_4_ & 3U | (&LAB_0056b2ff_1)[uVar7] |
                                DAT_0088c044._4_1_) * 4))();
        return;
      }
      piVar11 = (int *)*piVar11;
      if (piVar11 == (int *)0x0) goto switchD_0056d0aa_caseD_f;
    }
    DAT_0088c044._12_4_ = pbVar12 + 1;
    DAT_0088c054 = DAT_0088c054 + uVar7;
    goto LAB_0056cc20;
  case 10:
    uVar7 = (uint)(bVar1 >> 4);
    if (uVar7 == 0) {
      uVar7 = (uint)*pbVar12;
      pbVar12 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar10 = iVar9 + uVar7 + -1;
    piVar11 = DAT_0088c03c;
    while (piVar11[2] <= iVar10) {
      if (iVar9 <= piVar11[3]) {
        DAT_0088c044._8_4_ = 0;
        if (iVar9 < piVar11[2]) {
          DAT_0088c044._8_4_ = piVar11[2] - iVar9;
          uVar7 = uVar7 - DAT_0088c044._8_4_;
        }
        if (piVar11[3] < iVar10) {
          uVar7 = uVar7 - (iVar10 - piVar11[3]);
          DAT_0088c044._0_4_ = &LAB_0056cbc0;
        }
                    // WARNING: Could not recover jumptable at 0x0056cf15. Too many branches
                    // WARNING: Treating indirect jump as call
        (**(code **)(&LAB_0056a6ff_1 +
                    (uint)(byte)(cVar3 + (char)DAT_0088c044._8_4_ & 3U | (&LAB_0056b2ff_1)[uVar7] |
                                DAT_0088c044._4_1_) * 4))();
        return;
      }
      piVar11 = (int *)*piVar11;
      if (piVar11 == (int *)0x0) goto switchD_0056d0aa_caseD_f;
    }
    DAT_0088c044._12_4_ = pbVar12 + 1;
    DAT_0088c054 = DAT_0088c054 + uVar7;
    goto LAB_0056cc20;
  case 0xb:
    goto switchD_0056cc42_caseD_b;
  case 0xe:
                    // WARNING: Could not recover jumptable at 0x0056cc65. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(&DAT_0056b480 + (uint)(bVar1 >> 4) * 4))();
    return;
  case 0xf:
    goto switchD_0056d0aa_caseD_f;
  }
  iVar10 = iVar9 + uVar7 + -1;
  piVar11 = DAT_0088c03c;
  while (piVar11[2] <= iVar10) {
    if (iVar9 <= piVar11[3]) {
      DAT_0088c044._8_4_ = 0;
      if (iVar9 < piVar11[2]) {
        DAT_0088c044._8_4_ = piVar11[2] - iVar9;
        uVar7 = uVar7 - DAT_0088c044._8_4_;
      }
      sVar8 = (short)uVar7;
      if (piVar11[3] < iVar10) {
        sVar8 = sVar8 - ((short)iVar10 - (short)piVar11[3]);
        DAT_0088c044._0_4_ = &LAB_0056cbc0;
      }
                    // WARNING: Could not recover jumptable at 0x0056cceb. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(&LAB_0056a300 +
                  (uint)(byte)(cVar3 + (char)DAT_0088c044._8_4_ & 3U | DAT_0088c044._4_1_ |
                              (&LAB_0056b2ff_1)
                              [(byte)(-(char)((ushort)sVar8 >> 8) & 0x80U | (byte)sVar8)]) * 4))();
      return;
    }
    piVar11 = (int *)*piVar11;
    if (piVar11 == (int *)0x0) goto switchD_0056d0aa_caseD_f;
  }
  DAT_0088c054 = DAT_0088c054 + uVar7;
  DAT_0088c044._12_4_ = pbVar12 + uVar7;
  goto LAB_0056cc20;
switchD_0056cc42_caseD_b:
  uVar7 = (uint)(bVar1 >> 4);
  if (uVar7 == 0) {
    uVar7 = (uint)*pbVar12;
    pbVar12 = (byte *)(DAT_0088c044._12_4_ + 2);
  }
  iVar10 = iVar9 + uVar7 + -1;
  piVar11 = DAT_0088c03c;
  while (piVar11[2] <= iVar10) {
    if (iVar9 <= piVar11[3]) {
      DAT_0088c044._8_4_ = 0;
      if (iVar9 < piVar11[2]) {
        DAT_0088c044._8_4_ = piVar11[2] - iVar9;
        uVar7 = uVar7 - DAT_0088c044._8_4_;
      }
      if (piVar11[3] < iVar10) {
        uVar7 = uVar7 - (iVar10 - piVar11[3]);
        DAT_0088c044._0_4_ = &LAB_0056cbc0;
      }
                    // WARNING: Could not recover jumptable at 0x0056cfa5. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(&LAB_0056aeff_1 +
                  (uint)(byte)(cVar3 + (char)DAT_0088c044._8_4_ & 3U | (&LAB_0056b2ff_1)[uVar7] |
                              DAT_0088c044._4_1_) * 4))();
      return;
    }
    piVar11 = (int *)*piVar11;
    if (piVar11 == (int *)0x0) goto switchD_0056d0aa_caseD_f;
  }
  DAT_0088c054 = DAT_0088c054 + uVar7;
  DAT_0088c044._12_4_ = pbVar12;
  goto LAB_0056cc20;
}



void FUN_0056db60(void)

{
  byte *unaff_ESI;
  
  switch(*unaff_ESI & 0xf) {
  default:
    return;
  case 1:
  case 5:
  case 9:
  case 0xd:
    return;
  case 2:
    return;
  case 3:
    return;
  case 6:
    return;
  case 7:
  case 10:
    return;
  case 0xb:
    return;
  case 0xe:
                    // WARNING: Could not recover jumptable at 0x0056dbae. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(&DAT_0056c640 + (uint)(*unaff_ESI >> 4) * 4))();
    return;
  case 0xf:
    return;
  }
}


