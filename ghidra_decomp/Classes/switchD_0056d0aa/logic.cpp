// Class: switchD_0056d0aa
// Function: caseD_f
// Address: 0056d2e0
void switchD_0056d0aa::caseD_f(void)
{
  byte bVar1;
  ushort uVar2;
  int *piVar3;
  char cVar4;
  byte bVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int unaff_EBP;
  byte *pbVar11;
  byte *pbVar12;
  
  piVar10 = DAT_0088c03c;
code_r0x0056d2e0:
  do {
    do {
      do {
        DAT_0088c03c = piVar10;
        DAT_0088c038 = DAT_0088c038 + 1;
        if (*(int *)(unaff_EBP + 0x18) <= DAT_0088c038) {
          return;
        }
        uVar6 = *(int *)(unaff_EBP + 0x10) + DAT_0088c038;
        piVar3 = *(int **)(DAT_0088c004 + uVar6 * 4);
        piVar10 = DAT_0088c03c;
      } while (piVar3 == (int *)0x0);
      if ((DAT_0088c044._4_1_ & 0x80) != 0) {
        uVar6 = uVar6 & 3;
        DAT_0088c02c._4_4_ = *(uint *)(&DAT_0088c058.field_0x18 + uVar6 * 4);
        DAT_0088c02c._0_4_ = *(uint *)(&DAT_0088c058.field_0x8 + uVar6 * 4);
        DAT_0088c02c._8_4_ = DAT_0088c040 & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
      }
      uVar2 = *(ushort *)(DAT_0088c010 + DAT_0088c038 * 4);
      piVar10 = piVar3;
    } while ((uVar2 & 0x8000) != 0);
    iVar9 = DAT_0088c024 + (uint)uVar2;
    iVar8 = DAT_0088c028 - (uint)*(ushort *)(DAT_0088c010 + 2 + DAT_0088c038 * 4);
    DAT_0088c020 = *(int *)(DAT_0088c000 + (*(int *)(unaff_EBP + 0x10) + DAT_0088c038) * 4);
    DAT_0088c014 = DAT_0088c020 + iVar9;
    DAT_0088c018 = (byte *)(*(int *)(DAT_0088c00c + DAT_0088c038 * 4) + *(int *)(unaff_EBP + 8));
    DAT_0088c03c = piVar3;
    while (DAT_0088c03c[2] <= iVar8) {
      if (iVar9 <= DAT_0088c03c[3]) {
        if ((iVar9 < DAT_0088c03c[2]) || (DAT_0088c03c[3] < iVar8)) {
          DAT_0088c044._0_4_ = 0x56cc20;
          DAT_0088c044._12_4_ = DAT_0088c018;
          DAT_0088c054 = DAT_0088c014;
          goto LAB_0056cc20;
        }
        DAT_0088c044._0_4_ = 0x56d0a0;
        pbVar11 = DAT_0088c018;
        iVar8 = DAT_0088c014;
        goto LAB_0056d0a0;
      }
      DAT_0088c03c = (int *)*DAT_0088c03c;
      if (DAT_0088c03c == (int *)0x0) {
        DAT_0088c03c = piVar3;
        caseD_f();
        return;
      }
    }
  } while( true );
LAB_0056cc20:
  bVar1 = *(byte *)DAT_0088c044._12_4_;
  iVar8 = DAT_0088c054 - DAT_0088c020;
  pbVar11 = (byte *)(DAT_0088c044._12_4_ + 1);
  cVar4 = (char)DAT_0088c054;
  piVar10 = DAT_0088c03c;
  switch(bVar1 & 0xf) {
  default:
    uVar6 = (uint)(bVar1 >> 2);
    break;
  case 1:
  case 5:
  case 9:
  case 0xd:
    DAT_0088c054 = DAT_0088c054 + (uint)(bVar1 >> 2);
    DAT_0088c044._12_4_ = pbVar11;
    goto LAB_0056cc20;
  case 2:
    uVar6 = CONCAT31((int3)(((uint)bVar1 << 4) >> 8),*pbVar11);
    pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
    break;
  case 3:
    DAT_0088c044._12_4_ = DAT_0088c044._12_4_ + 2;
    DAT_0088c054 = DAT_0088c054 + CONCAT31((int3)(((uint)bVar1 << 4) >> 8),*pbVar11);
    goto LAB_0056cc20;
  case 6:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar11;
      pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar9 = iVar8 + uVar6 + -1;
    while (piVar10[2] <= iVar9) {
      if (iVar8 <= piVar10[3]) {
        DAT_0088c044._8_4_ = 0;
        if (iVar8 < piVar10[2]) {
          DAT_0088c044._8_4_ = piVar10[2] - iVar8;
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (piVar10[3] < iVar9) {
          uVar6 = uVar6 - (iVar9 - piVar10[3]);
          DAT_0088c044._0_4_ = 0x56cbc0;
        }
                    /* WARNING: Could not recover jumptable at 0x0056cdc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)((uint)(byte)(cVar4 + (char)DAT_0088c044._8_4_ & 3U |
                                  *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4 + 0x56ab00))
                  ();
        return;
      }
      piVar10 = (int *)*piVar10;
      if (piVar10 == (int *)0x0) {
        caseD_f();
        return;
      }
    }
    DAT_0088c044._12_4_ = pbVar11 + uVar6;
    DAT_0088c054 = DAT_0088c054 + uVar6;
    goto LAB_0056cc20;
  case 7:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar11;
      pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar9 = iVar8 + uVar6 + -1;
    while (piVar10[2] <= iVar9) {
      if (iVar8 <= piVar10[3]) {
        DAT_0088c044._8_4_ = 0;
        if (iVar8 < piVar10[2]) {
          DAT_0088c044._8_4_ = piVar10[2] - iVar8;
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (piVar10[3] < iVar9) {
          uVar6 = uVar6 - (iVar9 - piVar10[3]);
          DAT_0088c044._0_4_ = 0x56cbc0;
        }
                    /* WARNING: Could not recover jumptable at 0x0056ce75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)((uint)(byte)(cVar4 + (char)DAT_0088c044._8_4_ & 3U |
                                  *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4 + 0x56a700))
                  ();
        return;
      }
      piVar10 = (int *)*piVar10;
      if (piVar10 == (int *)0x0) {
        caseD_f();
        return;
      }
    }
    DAT_0088c044._12_4_ = pbVar11 + 1;
    DAT_0088c054 = DAT_0088c054 + uVar6;
    goto LAB_0056cc20;
  case 10:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar11;
      pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar9 = iVar8 + uVar6 + -1;
    while (piVar10[2] <= iVar9) {
      if (iVar8 <= piVar10[3]) {
        DAT_0088c044._8_4_ = 0;
        if (iVar8 < piVar10[2]) {
          DAT_0088c044._8_4_ = piVar10[2] - iVar8;
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (piVar10[3] < iVar9) {
          uVar6 = uVar6 - (iVar9 - piVar10[3]);
          DAT_0088c044._0_4_ = 0x56cbc0;
        }
                    /* WARNING: Could not recover jumptable at 0x0056cf15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)((uint)(byte)(cVar4 + (char)DAT_0088c044._8_4_ & 3U |
                                  *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4 + 0x56a700))
                  ();
        return;
      }
      piVar10 = (int *)*piVar10;
      if (piVar10 == (int *)0x0) {
        caseD_f();
        return;
      }
    }
    DAT_0088c044._12_4_ = pbVar11 + 1;
    DAT_0088c054 = DAT_0088c054 + uVar6;
    goto LAB_0056cc20;
  case 0xb:
    goto switchD_0056cc42_caseD_b;
  case 0xe:
                    /* WARNING: Could not recover jumptable at 0x0056cc65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(&DAT_0056b480 + (uint)(bVar1 >> 4) * 4))();
    return;
  case 0xf:
    goto code_r0x0056d2e0;
  }
  iVar9 = iVar8 + uVar6 + -1;
  while (piVar10[2] <= iVar9) {
    if (iVar8 <= piVar10[3]) {
      DAT_0088c044._8_4_ = 0;
      if (iVar8 < piVar10[2]) {
        DAT_0088c044._8_4_ = piVar10[2] - iVar8;
        uVar6 = uVar6 - DAT_0088c044._8_4_;
      }
      sVar7 = (short)uVar6;
      if (piVar10[3] < iVar9) {
        sVar7 = sVar7 - ((short)iVar9 - (short)piVar10[3]);
        DAT_0088c044._0_4_ = 0x56cbc0;
      }
                    /* WARNING: Could not recover jumptable at 0x0056cceb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((uint)(byte)(cVar4 + (char)DAT_0088c044._8_4_ & 3U | DAT_0088c044._4_1_ |
                               *(byte *)((byte)(-(char)((ushort)sVar7 >> 8) & 0x80U | (byte)sVar7) +
                                        0x56b300)) * 4 + 0x56a300))();
      return;
    }
    piVar10 = (int *)*piVar10;
    if (piVar10 == (int *)0x0) {
      caseD_f();
      return;
    }
  }
  DAT_0088c054 = DAT_0088c054 + uVar6;
  DAT_0088c044._12_4_ = pbVar11 + uVar6;
  goto LAB_0056cc20;
switchD_0056cc42_caseD_b:
  uVar6 = (uint)(bVar1 >> 4);
  if (uVar6 == 0) {
    uVar6 = (uint)*pbVar11;
    pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
  }
  iVar9 = iVar8 + uVar6 + -1;
  while (piVar10[2] <= iVar9) {
    if (iVar8 <= piVar10[3]) {
      DAT_0088c044._8_4_ = 0;
      if (iVar8 < piVar10[2]) {
        DAT_0088c044._8_4_ = piVar10[2] - iVar8;
        uVar6 = uVar6 - DAT_0088c044._8_4_;
      }
      if (piVar10[3] < iVar9) {
        uVar6 = uVar6 - (iVar9 - piVar10[3]);
        DAT_0088c044._0_4_ = 0x56cbc0;
      }
                    /* WARNING: Could not recover jumptable at 0x0056cfa5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((uint)(byte)(cVar4 + (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300)
                               | DAT_0088c044._4_1_) * 4 + 0x56af00))();
      return;
    }
    piVar10 = (int *)*piVar10;
    if (piVar10 == (int *)0x0) {
      caseD_f();
      return;
    }
  }
  DAT_0088c054 = DAT_0088c054 + uVar6;
  DAT_0088c044._12_4_ = pbVar11;
  goto LAB_0056cc20;
LAB_0056d0a0:
  do {
    bVar1 = *pbVar11;
    pbVar12 = pbVar11 + 1;
    bVar5 = (byte)iVar8;
    switch(bVar1 & 0xf) {
    default:
                    /* WARNING: Could not recover jumptable at 0x0056d0f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      DAT_0088c03c = piVar3;
      (**(code **)((uint)(byte)(bVar5 & 3 | *(byte *)((bVar1 >> 2) + 0x56b300) | DAT_0088c044._4_1_)
                   * 4 + 0x56a300))();
      return;
    case 1:
    case 5:
    case 9:
    case 0xd:
      iVar8 = iVar8 + (uint)(bVar1 >> 2);
      pbVar11 = pbVar12;
      break;
    case 2:
                    /* WARNING: Could not recover jumptable at 0x0056d120. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      DAT_0088c03c = piVar3;
      (**(code **)((uint)(byte)(bVar5 & 3 | DAT_0088c044._4_1_ |
                               *(byte *)((-(char)(((uint)bVar1 << 4) >> 8) & 0x80U | *pbVar12) +
                                        0x56b300)) * 4 + 0x56a300))();
      return;
    case 3:
      pbVar11 = pbVar11 + 2;
      iVar8 = iVar8 + (uint)*pbVar12;
      break;
    case 6:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
                    /* WARNING: Could not recover jumptable at 0x0056d17f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      DAT_0088c03c = piVar3;
      (**(code **)((uint)(byte)(bVar5 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4 +
                  0x56ab00))();
      return;
    case 7:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
                    /* WARNING: Could not recover jumptable at 0x0056d1d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      DAT_0088c03c = piVar3;
      (**(code **)((uint)(byte)(bVar5 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4 +
                  0x56a700))();
      return;
    case 10:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
                    /* WARNING: Could not recover jumptable at 0x0056d211. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      DAT_0088c03c = piVar3;
      (**(code **)((uint)(byte)(bVar5 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4 +
                  0x56a700))();
      return;
    case 0xb:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
                    /* WARNING: Could not recover jumptable at 0x0056d241. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      DAT_0088c03c = piVar3;
      (**(code **)((uint)(byte)(bVar5 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4 +
                  0x56af00))();
      return;
    case 0xe:
                    /* WARNING: Could not recover jumptable at 0x0056d0c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      DAT_0088c03c = piVar3;
      (**(code **)(&DAT_0056b4c0 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
      goto code_r0x0056d2e0;
    }
  } while( true );
}

// --------------------------------------------------

