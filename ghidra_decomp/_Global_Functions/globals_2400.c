// GLOBAL FUNCTIONS PART 2400
// Function: FUN_0056d6e9
// Address: 0056d6e9
// XREFS: None
void __fastcall FUN_0056d6e9(uint param_1)
{
  (**(code **)(&DAT_0056b580 + (param_1 >> 4) * 4))();
  return;
}

// --------------------------------------------------

// Function: FUN_0056d70c
// Address: 0056d70c
// XREFS: None
void __fastcall FUN_0056d70c(uint param_1)
{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int unaff_EBX;
  int iVar11;
  int unaff_EBP;
  byte *pbVar12;
  byte *pbVar13;
  byte *unaff_ESI;
  int unaff_EDI;
  
switchD_0056d6e2_caseD_0:
  param_1 = param_1 >> 2;
LAB_0056d72b:
  iVar10 = (unaff_EDI - param_1) + 1;
  do {
    if (*(int *)(unaff_EBX + 0xc) < iVar10) {
      iVar10 = DAT_0088c054 - param_1;
      DAT_0088c044._12_4_ = unaff_ESI + param_1;
      goto LAB_0056d6c0;
    }
    if (*(int *)(unaff_EBX + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(unaff_EBX + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(unaff_EBX + 0xc);
        param_1 = param_1 - DAT_0088c044._8_4_;
      }
      sVar7 = (short)param_1;
      if (iVar10 < *(int *)(unaff_EBX + 8)) {
        sVar7 = sVar7 - ((short)*(undefined4 *)(unaff_EBX + 8) - (short)iVar10);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)((char)DAT_0088c054 - (char)DAT_0088c044._8_4_ & 3U |
                               DAT_0088c044._4_1_ |
                              *(byte *)((byte)(-(char)((ushort)sVar7 >> 8) & 0x80U | (byte)sVar7) +
                                       0x56b300)) * 4))();
      return;
    }
    unaff_EBX = *(int *)(unaff_EBX + 4);
    iVar5 = DAT_0088c03c;
  } while (unaff_EBX != 0);
  goto switchD_0056d42a_caseD_f;
LAB_0056d6c0:
  do {
    bVar1 = *(byte *)DAT_0088c044._12_4_;
    param_1 = (uint)bVar1;
    unaff_EDI = iVar10 - DAT_0088c020;
    unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 1);
    cVar4 = (char)iVar10;
    unaff_EBX = DAT_0088c03c;
    iVar5 = DAT_0088c03c;
    DAT_0088c054 = iVar10;
    switch(bVar1 & 0xf) {
    default:
      goto switchD_0056d6e2_caseD_0;
    case 1:
    case 5:
    case 9:
    case 0xd:
      (*(code *)DAT_0088c044._0_4_)();
      return;
    case 2:
      param_1 = CONCAT31((int3)((param_1 << 4) >> 8),*unaff_ESI);
      unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
      goto LAB_0056d72b;
    case 3:
      (*(code *)DAT_0088c044._0_4_)();
      return;
    case 6:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*unaff_ESI;
        unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
      }
      iVar8 = (unaff_EDI - uVar6) + 1;
      iVar11 = DAT_0088c03c;
      while (iVar8 <= *(int *)(iVar11 + 0xc)) {
        if (*(int *)(iVar11 + 8) <= unaff_EDI) {
          DAT_0088c044._8_4_ = 0;
          if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
            DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
            uVar6 = uVar6 - DAT_0088c044._8_4_;
          }
          if (iVar8 < *(int *)(iVar11 + 8)) {
            uVar6 = uVar6 - (*(int *)(iVar11 + 8) - iVar8);
            DAT_0088c044._0_4_ = 0x56d660;
          }
          (**(code **)(&DAT_0056be00 +
                      (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U |
                                   *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))();
          return;
        }
        iVar11 = *(int *)(iVar11 + 4);
        if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
      }
      DAT_0088c044._12_4_ = unaff_ESI + uVar6;
      iVar10 = iVar10 - uVar6;
      break;
    case 7:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*unaff_ESI;
        unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
      }
      iVar8 = (unaff_EDI - uVar6) + 1;
      iVar11 = DAT_0088c03c;
      while (iVar8 <= *(int *)(iVar11 + 0xc)) {
        if (*(int *)(iVar11 + 8) <= unaff_EDI) {
          DAT_0088c044._8_4_ = 0;
          if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
            DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
            uVar6 = uVar6 - DAT_0088c044._8_4_;
          }
          if (iVar8 < *(int *)(iVar11 + 8)) {
            uVar6 = uVar6 - (*(int *)(iVar11 + 8) - iVar8);
            DAT_0088c044._0_4_ = 0x56d660;
          }
          (**(code **)(&DAT_0056ba00 +
                      (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U |
                                   *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))();
          return;
        }
        iVar11 = *(int *)(iVar11 + 4);
        if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
      }
      DAT_0088c044._12_4_ = unaff_ESI + 1;
      iVar10 = iVar10 - uVar6;
      break;
    case 10:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*unaff_ESI;
        unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
      }
      iVar8 = (unaff_EDI - uVar6) + 1;
      iVar11 = DAT_0088c03c;
      while (iVar8 <= *(int *)(iVar11 + 0xc)) {
        if (*(int *)(iVar11 + 8) <= unaff_EDI) {
          DAT_0088c044._8_4_ = 0;
          if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
            DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
            uVar6 = uVar6 - DAT_0088c044._8_4_;
          }
          if (iVar8 < *(int *)(iVar11 + 8)) {
            uVar6 = uVar6 - (*(int *)(iVar11 + 8) - iVar8);
            DAT_0088c044._0_4_ = 0x56d660;
          }
          (**(code **)(&DAT_0056ba00 +
                      (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U |
                                   *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))();
          return;
        }
        iVar11 = *(int *)(iVar11 + 4);
        if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
      }
      DAT_0088c044._12_4_ = unaff_ESI + 1;
      iVar10 = iVar10 - uVar6;
      break;
    case 0xb:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*unaff_ESI;
        unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
      }
      iVar8 = (unaff_EDI - uVar6) + 1;
      iVar11 = DAT_0088c03c;
      while (iVar8 <= *(int *)(iVar11 + 0xc)) {
        if (*(int *)(iVar11 + 8) <= unaff_EDI) {
          DAT_0088c044._8_4_ = 0;
          if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
            DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
            uVar6 = uVar6 - DAT_0088c044._8_4_;
          }
          if (iVar8 < *(int *)(iVar11 + 8)) {
            uVar6 = uVar6 - (*(int *)(iVar11 + 8) - iVar8);
            DAT_0088c044._0_4_ = 0x56d660;
          }
          (**(code **)(&DAT_0056c200 +
                      (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U |
                                   *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))();
          return;
        }
        iVar11 = *(int *)(iVar11 + 4);
        if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
      }
      iVar10 = iVar10 - uVar6;
      DAT_0088c044._12_4_ = unaff_ESI;
      break;
    case 0xe:
      (**(code **)(&DAT_0056b580 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
switchD_0056d42a_caseD_f:
      do {
        do {
          do {
            DAT_0088c03c = iVar5;
            DAT_0088c038 = DAT_0088c038 + 1;
            if (*(int *)(unaff_EBP + 0x18) <= DAT_0088c038) {
              return;
            }
            uVar6 = *(int *)(unaff_EBP + 0x10) + DAT_0088c038;
            iVar11 = *(int *)(DAT_0088c008 + uVar6 * 4);
            iVar5 = DAT_0088c03c;
          } while (iVar11 == 0);
          if ((DAT_0088c044._4_1_ & 0x80) != 0) {
            uVar6 = uVar6 & 3;
            DAT_0088c02c._4_4_ = *(uint *)(&DAT_0088c058.field_0x18 + uVar6 * 4);
            DAT_0088c02c._0_4_ = *(uint *)(&DAT_0088c058.field_0x8 + uVar6 * 4);
            DAT_0088c02c._8_4_ = DAT_0088c040 & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
          }
          uVar2 = *(ushort *)(DAT_0088c010 + 2 + DAT_0088c038 * 4);
          iVar5 = iVar11;
        } while ((uVar2 & 0x8000) != 0);
        iVar9 = DAT_0088c024 + (uint)uVar2;
        iVar8 = DAT_0088c028 - (uint)*(ushort *)(DAT_0088c010 + DAT_0088c038 * 4);
        DAT_0088c020 = *(int *)(DAT_0088c000 + (*(int *)(unaff_EBP + 0x10) + DAT_0088c038) * 4);
        iVar10 = DAT_0088c020 + iVar8;
        DAT_0088c018 = (byte *)(*(int *)(DAT_0088c00c + DAT_0088c038 * 4) + *(int *)(unaff_EBP + 8))
        ;
        DAT_0088c03c = iVar11;
        do {
          DAT_0088c014 = iVar10;
          if (*(int *)(DAT_0088c03c + 0xc) < iVar9) break;
          if (*(int *)(DAT_0088c03c + 8) <= iVar8) {
            if ((iVar9 < *(int *)(DAT_0088c03c + 8)) || (*(int *)(DAT_0088c03c + 0xc) < iVar8)) {
              DAT_0088c044._0_4_ = 0x56d6c0;
              DAT_0088c044._12_4_ = DAT_0088c018;
              goto LAB_0056d6c0;
            }
            DAT_0088c044._0_4_ = 0x56d420;
            pbVar13 = DAT_0088c018;
            goto LAB_0056d420;
          }
          DAT_0088c03c = *(int *)(DAT_0088c03c + 4);
        } while (DAT_0088c03c != 0);
      } while( true );
    }
  } while( true );
LAB_0056d420:
  do {
    bVar1 = *pbVar13;
    pbVar12 = pbVar13 + 1;
    bVar3 = (byte)iVar10;
    switch(bVar1 & 0xf) {
    default:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)((bVar1 >> 2) + 0x56b300) | DAT_0088c044._4_1_)
                  * 4))();
      return;
    case 1:
    case 5:
    case 9:
    case 0xd:
      iVar10 = iVar10 - (uint)(bVar1 >> 2);
      pbVar13 = pbVar12;
      break;
    case 2:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | DAT_0088c044._4_1_ |
                              *(byte *)((-(char)(((uint)bVar1 << 4) >> 8) & 0x80U | *pbVar12) +
                                       0x56b300)) * 4))();
      return;
    case 3:
      pbVar13 = pbVar13 + 2;
      iVar10 = iVar10 - (uint)*pbVar12;
      break;
    case 6:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056be00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 7:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 10:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xb:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xe:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b5c0 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
      goto switchD_0056d42a_caseD_f;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0056d7ad
// Address: 0056d7ad
// XREFS: None
void FUN_0056d7ad(void)
{
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056d7e5
// Address: 0056d7e5
// XREFS: None
void __fastcall FUN_0056d7e5(uint param_1)
{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int unaff_EBX;
  int iVar11;
  int unaff_EBP;
  byte *pbVar12;
  byte *pbVar13;
  byte *unaff_ESI;
  int unaff_EDI;
  
switchD_0056d6e2_caseD_6:
  uVar8 = param_1 >> 4;
  if (uVar8 == 0) {
    uVar8 = CONCAT31((uint3)(param_1 >> 0xc),*unaff_ESI);
    unaff_ESI = unaff_ESI + 1;
  }
  iVar10 = (unaff_EDI - uVar8) + 1;
  do {
    if (*(int *)(unaff_EBX + 0xc) < iVar10) {
      iVar10 = DAT_0088c054 - uVar8;
      DAT_0088c044._12_4_ = unaff_ESI + uVar8;
      goto LAB_0056d6c0;
    }
    if (*(int *)(unaff_EBX + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(unaff_EBX + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(unaff_EBX + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      if (iVar10 < *(int *)(unaff_EBX + 8)) {
        uVar8 = uVar8 - (*(int *)(unaff_EBX + 8) - iVar10);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056be00 +
                  (uint)(byte)((char)DAT_0088c054 - (char)DAT_0088c044._8_4_ & 3U |
                               *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))();
      return;
    }
    unaff_EBX = *(int *)(unaff_EBX + 4);
    iVar5 = DAT_0088c03c;
  } while (unaff_EBX != 0);
  goto switchD_0056d42a_caseD_f;
LAB_0056d6c0:
  bVar1 = *(byte *)DAT_0088c044._12_4_;
  param_1 = (uint)bVar1;
  unaff_EDI = iVar10 - DAT_0088c020;
  unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 1);
  cVar4 = (char)iVar10;
  unaff_EBX = DAT_0088c03c;
  iVar5 = DAT_0088c03c;
  DAT_0088c054 = iVar10;
  switch(bVar1 & 0xf) {
  default:
    uVar8 = (uint)(bVar1 >> 2);
    break;
  case 1:
  case 5:
  case 9:
  case 0xd:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 2:
    uVar8 = CONCAT31((int3)((param_1 << 4) >> 8),*unaff_ESI);
    unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
    break;
  case 3:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 6:
    goto switchD_0056d6e2_caseD_6;
  case 7:
    uVar8 = (uint)(bVar1 >> 4);
    if (uVar8 == 0) {
      uVar8 = (uint)*unaff_ESI;
      unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar7 = (unaff_EDI - uVar8) + 1;
    iVar11 = DAT_0088c03c;
    while (iVar7 <= *(int *)(iVar11 + 0xc)) {
      if (*(int *)(iVar11 + 8) <= unaff_EDI) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
          DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
          uVar8 = uVar8 - DAT_0088c044._8_4_;
        }
        if (iVar7 < *(int *)(iVar11 + 8)) {
          uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar11 = *(int *)(iVar11 + 4);
      if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = unaff_ESI + 1;
    iVar10 = iVar10 - uVar8;
    goto LAB_0056d6c0;
  case 10:
    uVar8 = (uint)(bVar1 >> 4);
    if (uVar8 == 0) {
      uVar8 = (uint)*unaff_ESI;
      unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar7 = (unaff_EDI - uVar8) + 1;
    iVar11 = DAT_0088c03c;
    while (iVar7 <= *(int *)(iVar11 + 0xc)) {
      if (*(int *)(iVar11 + 8) <= unaff_EDI) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
          DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
          uVar8 = uVar8 - DAT_0088c044._8_4_;
        }
        if (iVar7 < *(int *)(iVar11 + 8)) {
          uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar11 = *(int *)(iVar11 + 4);
      if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = unaff_ESI + 1;
    iVar10 = iVar10 - uVar8;
    goto LAB_0056d6c0;
  case 0xb:
    goto switchD_0056d6e2_caseD_b;
  case 0xe:
    (**(code **)(&DAT_0056b580 + (uint)(bVar1 >> 4) * 4))();
    return;
  case 0xf:
switchD_0056d42a_caseD_f:
    do {
      do {
        do {
          DAT_0088c03c = iVar5;
          DAT_0088c038 = DAT_0088c038 + 1;
          if (*(int *)(unaff_EBP + 0x18) <= DAT_0088c038) {
            return;
          }
          uVar8 = *(int *)(unaff_EBP + 0x10) + DAT_0088c038;
          iVar11 = *(int *)(DAT_0088c008 + uVar8 * 4);
          iVar5 = DAT_0088c03c;
        } while (iVar11 == 0);
        if ((DAT_0088c044._4_1_ & 0x80) != 0) {
          uVar8 = uVar8 & 3;
          DAT_0088c02c._4_4_ = *(uint *)(&DAT_0088c058.field_0x18 + uVar8 * 4);
          DAT_0088c02c._0_4_ = *(uint *)(&DAT_0088c058.field_0x8 + uVar8 * 4);
          DAT_0088c02c._8_4_ = DAT_0088c040 & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
        }
        uVar2 = *(ushort *)(DAT_0088c010 + 2 + DAT_0088c038 * 4);
        iVar5 = iVar11;
      } while ((uVar2 & 0x8000) != 0);
      iVar9 = DAT_0088c024 + (uint)uVar2;
      iVar7 = DAT_0088c028 - (uint)*(ushort *)(DAT_0088c010 + DAT_0088c038 * 4);
      DAT_0088c020 = *(int *)(DAT_0088c000 + (*(int *)(unaff_EBP + 0x10) + DAT_0088c038) * 4);
      iVar10 = DAT_0088c020 + iVar7;
      DAT_0088c018 = (byte *)(*(int *)(DAT_0088c00c + DAT_0088c038 * 4) + *(int *)(unaff_EBP + 8));
      DAT_0088c03c = iVar11;
      do {
        DAT_0088c014 = iVar10;
        if (*(int *)(DAT_0088c03c + 0xc) < iVar9) break;
        if (*(int *)(DAT_0088c03c + 8) <= iVar7) {
          if ((iVar9 < *(int *)(DAT_0088c03c + 8)) || (*(int *)(DAT_0088c03c + 0xc) < iVar7)) {
            DAT_0088c044._0_4_ = 0x56d6c0;
            DAT_0088c044._12_4_ = DAT_0088c018;
            goto LAB_0056d6c0;
          }
          DAT_0088c044._0_4_ = 0x56d420;
          pbVar13 = DAT_0088c018;
          goto LAB_0056d420;
        }
        DAT_0088c03c = *(int *)(DAT_0088c03c + 4);
      } while (DAT_0088c03c != 0);
    } while( true );
  }
  iVar7 = (unaff_EDI - uVar8) + 1;
  iVar11 = DAT_0088c03c;
  while (iVar7 <= *(int *)(iVar11 + 0xc)) {
    if (*(int *)(iVar11 + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      sVar6 = (short)uVar8;
      if (iVar7 < *(int *)(iVar11 + 8)) {
        sVar6 = sVar6 - ((short)*(undefined4 *)(iVar11 + 8) - (short)iVar7);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | DAT_0088c044._4_1_ |
                              *(byte *)((byte)(-(char)((ushort)sVar6 >> 8) & 0x80U | (byte)sVar6) +
                                       0x56b300)) * 4))();
      return;
    }
    iVar11 = *(int *)(iVar11 + 4);
    if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
  }
  iVar10 = iVar10 - uVar8;
  DAT_0088c044._12_4_ = unaff_ESI + uVar8;
  goto LAB_0056d6c0;
LAB_0056d420:
  do {
    bVar1 = *pbVar13;
    pbVar12 = pbVar13 + 1;
    bVar3 = (byte)iVar10;
    switch(bVar1 & 0xf) {
    default:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)((bVar1 >> 2) + 0x56b300) | DAT_0088c044._4_1_)
                  * 4))();
      return;
    case 1:
    case 5:
    case 9:
    case 0xd:
      iVar10 = iVar10 - (uint)(bVar1 >> 2);
      pbVar13 = pbVar12;
      break;
    case 2:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | DAT_0088c044._4_1_ |
                              *(byte *)((-(char)(((uint)bVar1 << 4) >> 8) & 0x80U | *pbVar12) +
                                       0x56b300)) * 4))();
      return;
    case 3:
      pbVar13 = pbVar13 + 2;
      iVar10 = iVar10 - (uint)*pbVar12;
      break;
    case 6:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056be00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 7:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 10:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xb:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xe:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b5c0 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
      goto switchD_0056d42a_caseD_f;
    }
  } while( true );
switchD_0056d6e2_caseD_b:
  uVar8 = (uint)(bVar1 >> 4);
  if (uVar8 == 0) {
    uVar8 = (uint)*unaff_ESI;
    unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
  }
  iVar7 = (unaff_EDI - uVar8) + 1;
  iVar11 = DAT_0088c03c;
  while (iVar7 <= *(int *)(iVar11 + 0xc)) {
    if (*(int *)(iVar11 + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      if (iVar7 < *(int *)(iVar11 + 8)) {
        uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300) |
                              DAT_0088c044._4_1_) * 4))();
      return;
    }
    iVar11 = *(int *)(iVar11 + 4);
    if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
  }
  iVar10 = iVar10 - uVar8;
  DAT_0088c044._12_4_ = unaff_ESI;
  goto LAB_0056d6c0;
}

// --------------------------------------------------

// Function: FUN_0056d887
// Address: 0056d887
// XREFS: None
void __fastcall FUN_0056d887(uint param_1)
{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int unaff_EBX;
  int iVar11;
  int unaff_EBP;
  byte *pbVar12;
  byte *pbVar13;
  byte *unaff_ESI;
  int unaff_EDI;
  
switchD_0056d6e2_caseD_7:
  uVar8 = param_1 >> 4;
  if (uVar8 == 0) {
    uVar8 = CONCAT31((uint3)(param_1 >> 0xc),*unaff_ESI);
    unaff_ESI = unaff_ESI + 1;
  }
  iVar10 = (unaff_EDI - uVar8) + 1;
  do {
    if (*(int *)(unaff_EBX + 0xc) < iVar10) {
      iVar10 = DAT_0088c054 - uVar8;
      DAT_0088c044._12_4_ = unaff_ESI + 1;
      goto LAB_0056d6c0;
    }
    if (*(int *)(unaff_EBX + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(unaff_EBX + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(unaff_EBX + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      if (iVar10 < *(int *)(unaff_EBX + 8)) {
        uVar8 = uVar8 - (*(int *)(unaff_EBX + 8) - iVar10);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)((char)DAT_0088c054 - (char)DAT_0088c044._8_4_ & 3U |
                               *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))();
      return;
    }
    unaff_EBX = *(int *)(unaff_EBX + 4);
    iVar5 = DAT_0088c03c;
  } while (unaff_EBX != 0);
  goto switchD_0056d42a_caseD_f;
LAB_0056d6c0:
  bVar1 = *(byte *)DAT_0088c044._12_4_;
  param_1 = (uint)bVar1;
  unaff_EDI = iVar10 - DAT_0088c020;
  unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 1);
  cVar4 = (char)iVar10;
  unaff_EBX = DAT_0088c03c;
  iVar5 = DAT_0088c03c;
  DAT_0088c054 = iVar10;
  switch(bVar1 & 0xf) {
  default:
    uVar8 = (uint)(bVar1 >> 2);
    break;
  case 1:
  case 5:
  case 9:
  case 0xd:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 2:
    uVar8 = CONCAT31((int3)((param_1 << 4) >> 8),*unaff_ESI);
    unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
    break;
  case 3:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 6:
    uVar8 = (uint)(bVar1 >> 4);
    if (uVar8 == 0) {
      uVar8 = (uint)*unaff_ESI;
      unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar7 = (unaff_EDI - uVar8) + 1;
    iVar11 = DAT_0088c03c;
    while (iVar7 <= *(int *)(iVar11 + 0xc)) {
      if (*(int *)(iVar11 + 8) <= unaff_EDI) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
          DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
          uVar8 = uVar8 - DAT_0088c044._8_4_;
        }
        if (iVar7 < *(int *)(iVar11 + 8)) {
          uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056be00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar11 = *(int *)(iVar11 + 4);
      if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = unaff_ESI + uVar8;
    iVar10 = iVar10 - uVar8;
    goto LAB_0056d6c0;
  case 7:
    goto switchD_0056d6e2_caseD_7;
  case 10:
    uVar8 = (uint)(bVar1 >> 4);
    if (uVar8 == 0) {
      uVar8 = (uint)*unaff_ESI;
      unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar7 = (unaff_EDI - uVar8) + 1;
    iVar11 = DAT_0088c03c;
    while (iVar7 <= *(int *)(iVar11 + 0xc)) {
      if (*(int *)(iVar11 + 8) <= unaff_EDI) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
          DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
          uVar8 = uVar8 - DAT_0088c044._8_4_;
        }
        if (iVar7 < *(int *)(iVar11 + 8)) {
          uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar11 = *(int *)(iVar11 + 4);
      if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = unaff_ESI + 1;
    iVar10 = iVar10 - uVar8;
    goto LAB_0056d6c0;
  case 0xb:
    goto switchD_0056d6e2_caseD_b;
  case 0xe:
    (**(code **)(&DAT_0056b580 + (uint)(bVar1 >> 4) * 4))();
    return;
  case 0xf:
switchD_0056d42a_caseD_f:
    do {
      do {
        do {
          DAT_0088c03c = iVar5;
          DAT_0088c038 = DAT_0088c038 + 1;
          if (*(int *)(unaff_EBP + 0x18) <= DAT_0088c038) {
            return;
          }
          uVar8 = *(int *)(unaff_EBP + 0x10) + DAT_0088c038;
          iVar11 = *(int *)(DAT_0088c008 + uVar8 * 4);
          iVar5 = DAT_0088c03c;
        } while (iVar11 == 0);
        if ((DAT_0088c044._4_1_ & 0x80) != 0) {
          uVar8 = uVar8 & 3;
          DAT_0088c02c._4_4_ = *(uint *)(&DAT_0088c058.field_0x18 + uVar8 * 4);
          DAT_0088c02c._0_4_ = *(uint *)(&DAT_0088c058.field_0x8 + uVar8 * 4);
          DAT_0088c02c._8_4_ = DAT_0088c040 & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
        }
        uVar2 = *(ushort *)(DAT_0088c010 + 2 + DAT_0088c038 * 4);
        iVar5 = iVar11;
      } while ((uVar2 & 0x8000) != 0);
      iVar9 = DAT_0088c024 + (uint)uVar2;
      iVar7 = DAT_0088c028 - (uint)*(ushort *)(DAT_0088c010 + DAT_0088c038 * 4);
      DAT_0088c020 = *(int *)(DAT_0088c000 + (*(int *)(unaff_EBP + 0x10) + DAT_0088c038) * 4);
      iVar10 = DAT_0088c020 + iVar7;
      DAT_0088c018 = (byte *)(*(int *)(DAT_0088c00c + DAT_0088c038 * 4) + *(int *)(unaff_EBP + 8));
      DAT_0088c03c = iVar11;
      do {
        DAT_0088c014 = iVar10;
        if (*(int *)(DAT_0088c03c + 0xc) < iVar9) break;
        if (*(int *)(DAT_0088c03c + 8) <= iVar7) {
          if ((iVar9 < *(int *)(DAT_0088c03c + 8)) || (*(int *)(DAT_0088c03c + 0xc) < iVar7)) {
            DAT_0088c044._0_4_ = 0x56d6c0;
            DAT_0088c044._12_4_ = DAT_0088c018;
            goto LAB_0056d6c0;
          }
          DAT_0088c044._0_4_ = 0x56d420;
          pbVar13 = DAT_0088c018;
          goto LAB_0056d420;
        }
        DAT_0088c03c = *(int *)(DAT_0088c03c + 4);
      } while (DAT_0088c03c != 0);
    } while( true );
  }
  iVar7 = (unaff_EDI - uVar8) + 1;
  iVar11 = DAT_0088c03c;
  while (iVar7 <= *(int *)(iVar11 + 0xc)) {
    if (*(int *)(iVar11 + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      sVar6 = (short)uVar8;
      if (iVar7 < *(int *)(iVar11 + 8)) {
        sVar6 = sVar6 - ((short)*(undefined4 *)(iVar11 + 8) - (short)iVar7);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | DAT_0088c044._4_1_ |
                              *(byte *)((byte)(-(char)((ushort)sVar6 >> 8) & 0x80U | (byte)sVar6) +
                                       0x56b300)) * 4))();
      return;
    }
    iVar11 = *(int *)(iVar11 + 4);
    if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
  }
  iVar10 = iVar10 - uVar8;
  DAT_0088c044._12_4_ = unaff_ESI + uVar8;
  goto LAB_0056d6c0;
LAB_0056d420:
  do {
    bVar1 = *pbVar13;
    pbVar12 = pbVar13 + 1;
    bVar3 = (byte)iVar10;
    switch(bVar1 & 0xf) {
    default:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)((bVar1 >> 2) + 0x56b300) | DAT_0088c044._4_1_)
                  * 4))();
      return;
    case 1:
    case 5:
    case 9:
    case 0xd:
      iVar10 = iVar10 - (uint)(bVar1 >> 2);
      pbVar13 = pbVar12;
      break;
    case 2:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | DAT_0088c044._4_1_ |
                              *(byte *)((-(char)(((uint)bVar1 << 4) >> 8) & 0x80U | *pbVar12) +
                                       0x56b300)) * 4))();
      return;
    case 3:
      pbVar13 = pbVar13 + 2;
      iVar10 = iVar10 - (uint)*pbVar12;
      break;
    case 6:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056be00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 7:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 10:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xb:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xe:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b5c0 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
      goto switchD_0056d42a_caseD_f;
    }
  } while( true );
switchD_0056d6e2_caseD_b:
  uVar8 = (uint)(bVar1 >> 4);
  if (uVar8 == 0) {
    uVar8 = (uint)*unaff_ESI;
    unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
  }
  iVar7 = (unaff_EDI - uVar8) + 1;
  iVar11 = DAT_0088c03c;
  while (iVar7 <= *(int *)(iVar11 + 0xc)) {
    if (*(int *)(iVar11 + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      if (iVar7 < *(int *)(iVar11 + 8)) {
        uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300) |
                              DAT_0088c044._4_1_) * 4))();
      return;
    }
    iVar11 = *(int *)(iVar11 + 4);
    if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
  }
  iVar10 = iVar10 - uVar8;
  DAT_0088c044._12_4_ = unaff_ESI;
  goto LAB_0056d6c0;
}

// --------------------------------------------------

// Function: FUN_0056d93a
// Address: 0056d93a
// XREFS: None
void __fastcall FUN_0056d93a(uint param_1)
{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int unaff_EBX;
  int iVar11;
  int unaff_EBP;
  byte *pbVar12;
  byte *pbVar13;
  byte *unaff_ESI;
  int unaff_EDI;
  
switchD_0056d6e2_caseD_a:
  uVar8 = param_1 >> 4;
  if (uVar8 == 0) {
    uVar8 = CONCAT31((uint3)(param_1 >> 0xc),*unaff_ESI);
    unaff_ESI = unaff_ESI + 1;
  }
  iVar10 = (unaff_EDI - uVar8) + 1;
  do {
    if (*(int *)(unaff_EBX + 0xc) < iVar10) {
      iVar10 = DAT_0088c054 - uVar8;
      DAT_0088c044._12_4_ = unaff_ESI + 1;
      goto LAB_0056d6c0;
    }
    if (*(int *)(unaff_EBX + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(unaff_EBX + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(unaff_EBX + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      if (iVar10 < *(int *)(unaff_EBX + 8)) {
        uVar8 = uVar8 - (*(int *)(unaff_EBX + 8) - iVar10);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)((char)DAT_0088c054 - (char)DAT_0088c044._8_4_ & 3U |
                               *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))();
      return;
    }
    unaff_EBX = *(int *)(unaff_EBX + 4);
    iVar5 = DAT_0088c03c;
  } while (unaff_EBX != 0);
  goto switchD_0056d42a_caseD_f;
LAB_0056d6c0:
  bVar1 = *(byte *)DAT_0088c044._12_4_;
  param_1 = (uint)bVar1;
  unaff_EDI = iVar10 - DAT_0088c020;
  unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 1);
  cVar4 = (char)iVar10;
  unaff_EBX = DAT_0088c03c;
  iVar5 = DAT_0088c03c;
  DAT_0088c054 = iVar10;
  switch(bVar1 & 0xf) {
  default:
    uVar8 = (uint)(bVar1 >> 2);
    break;
  case 1:
  case 5:
  case 9:
  case 0xd:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 2:
    uVar8 = CONCAT31((int3)((param_1 << 4) >> 8),*unaff_ESI);
    unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
    break;
  case 3:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 6:
    uVar8 = (uint)(bVar1 >> 4);
    if (uVar8 == 0) {
      uVar8 = (uint)*unaff_ESI;
      unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar7 = (unaff_EDI - uVar8) + 1;
    iVar11 = DAT_0088c03c;
    while (iVar7 <= *(int *)(iVar11 + 0xc)) {
      if (*(int *)(iVar11 + 8) <= unaff_EDI) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
          DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
          uVar8 = uVar8 - DAT_0088c044._8_4_;
        }
        if (iVar7 < *(int *)(iVar11 + 8)) {
          uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056be00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar11 = *(int *)(iVar11 + 4);
      if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = unaff_ESI + uVar8;
    iVar10 = iVar10 - uVar8;
    goto LAB_0056d6c0;
  case 7:
    uVar8 = (uint)(bVar1 >> 4);
    if (uVar8 == 0) {
      uVar8 = (uint)*unaff_ESI;
      unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar7 = (unaff_EDI - uVar8) + 1;
    iVar11 = DAT_0088c03c;
    while (iVar7 <= *(int *)(iVar11 + 0xc)) {
      if (*(int *)(iVar11 + 8) <= unaff_EDI) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
          DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
          uVar8 = uVar8 - DAT_0088c044._8_4_;
        }
        if (iVar7 < *(int *)(iVar11 + 8)) {
          uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar11 = *(int *)(iVar11 + 4);
      if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = unaff_ESI + 1;
    iVar10 = iVar10 - uVar8;
    goto LAB_0056d6c0;
  case 10:
    goto switchD_0056d6e2_caseD_a;
  case 0xb:
    goto switchD_0056d6e2_caseD_b;
  case 0xe:
    (**(code **)(&DAT_0056b580 + (uint)(bVar1 >> 4) * 4))();
    return;
  case 0xf:
switchD_0056d42a_caseD_f:
    do {
      do {
        do {
          DAT_0088c03c = iVar5;
          DAT_0088c038 = DAT_0088c038 + 1;
          if (*(int *)(unaff_EBP + 0x18) <= DAT_0088c038) {
            return;
          }
          uVar8 = *(int *)(unaff_EBP + 0x10) + DAT_0088c038;
          iVar11 = *(int *)(DAT_0088c008 + uVar8 * 4);
          iVar5 = DAT_0088c03c;
        } while (iVar11 == 0);
        if ((DAT_0088c044._4_1_ & 0x80) != 0) {
          uVar8 = uVar8 & 3;
          DAT_0088c02c._4_4_ = *(uint *)(&DAT_0088c058.field_0x18 + uVar8 * 4);
          DAT_0088c02c._0_4_ = *(uint *)(&DAT_0088c058.field_0x8 + uVar8 * 4);
          DAT_0088c02c._8_4_ = DAT_0088c040 & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
        }
        uVar2 = *(ushort *)(DAT_0088c010 + 2 + DAT_0088c038 * 4);
        iVar5 = iVar11;
      } while ((uVar2 & 0x8000) != 0);
      iVar9 = DAT_0088c024 + (uint)uVar2;
      iVar7 = DAT_0088c028 - (uint)*(ushort *)(DAT_0088c010 + DAT_0088c038 * 4);
      DAT_0088c020 = *(int *)(DAT_0088c000 + (*(int *)(unaff_EBP + 0x10) + DAT_0088c038) * 4);
      iVar10 = DAT_0088c020 + iVar7;
      DAT_0088c018 = (byte *)(*(int *)(DAT_0088c00c + DAT_0088c038 * 4) + *(int *)(unaff_EBP + 8));
      DAT_0088c03c = iVar11;
      do {
        DAT_0088c014 = iVar10;
        if (*(int *)(DAT_0088c03c + 0xc) < iVar9) break;
        if (*(int *)(DAT_0088c03c + 8) <= iVar7) {
          if ((iVar9 < *(int *)(DAT_0088c03c + 8)) || (*(int *)(DAT_0088c03c + 0xc) < iVar7)) {
            DAT_0088c044._0_4_ = 0x56d6c0;
            DAT_0088c044._12_4_ = DAT_0088c018;
            goto LAB_0056d6c0;
          }
          DAT_0088c044._0_4_ = 0x56d420;
          pbVar13 = DAT_0088c018;
          goto LAB_0056d420;
        }
        DAT_0088c03c = *(int *)(DAT_0088c03c + 4);
      } while (DAT_0088c03c != 0);
    } while( true );
  }
  iVar7 = (unaff_EDI - uVar8) + 1;
  iVar11 = DAT_0088c03c;
  while (iVar7 <= *(int *)(iVar11 + 0xc)) {
    if (*(int *)(iVar11 + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      sVar6 = (short)uVar8;
      if (iVar7 < *(int *)(iVar11 + 8)) {
        sVar6 = sVar6 - ((short)*(undefined4 *)(iVar11 + 8) - (short)iVar7);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | DAT_0088c044._4_1_ |
                              *(byte *)((byte)(-(char)((ushort)sVar6 >> 8) & 0x80U | (byte)sVar6) +
                                       0x56b300)) * 4))();
      return;
    }
    iVar11 = *(int *)(iVar11 + 4);
    if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
  }
  iVar10 = iVar10 - uVar8;
  DAT_0088c044._12_4_ = unaff_ESI + uVar8;
  goto LAB_0056d6c0;
LAB_0056d420:
  do {
    bVar1 = *pbVar13;
    pbVar12 = pbVar13 + 1;
    bVar3 = (byte)iVar10;
    switch(bVar1 & 0xf) {
    default:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)((bVar1 >> 2) + 0x56b300) | DAT_0088c044._4_1_)
                  * 4))();
      return;
    case 1:
    case 5:
    case 9:
    case 0xd:
      iVar10 = iVar10 - (uint)(bVar1 >> 2);
      pbVar13 = pbVar12;
      break;
    case 2:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | DAT_0088c044._4_1_ |
                              *(byte *)((-(char)(((uint)bVar1 << 4) >> 8) & 0x80U | *pbVar12) +
                                       0x56b300)) * 4))();
      return;
    case 3:
      pbVar13 = pbVar13 + 2;
      iVar10 = iVar10 - (uint)*pbVar12;
      break;
    case 6:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056be00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 7:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 10:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xb:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xe:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b5c0 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
      goto switchD_0056d42a_caseD_f;
    }
  } while( true );
switchD_0056d6e2_caseD_b:
  uVar8 = (uint)(bVar1 >> 4);
  if (uVar8 == 0) {
    uVar8 = (uint)*unaff_ESI;
    unaff_ESI = (byte *)(DAT_0088c044._12_4_ + 2);
  }
  iVar7 = (unaff_EDI - uVar8) + 1;
  iVar11 = DAT_0088c03c;
  while (iVar7 <= *(int *)(iVar11 + 0xc)) {
    if (*(int *)(iVar11 + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      if (iVar7 < *(int *)(iVar11 + 8)) {
        uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300) |
                              DAT_0088c044._4_1_) * 4))();
      return;
    }
    iVar11 = *(int *)(iVar11 + 4);
    if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
  }
  iVar10 = iVar10 - uVar8;
  DAT_0088c044._12_4_ = unaff_ESI;
  goto LAB_0056d6c0;
}

// --------------------------------------------------

// Function: FUN_0056d9da
// Address: 0056d9da
// XREFS: None
void __fastcall FUN_0056d9da(uint param_1)
{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int unaff_EBX;
  int unaff_EBP;
  byte *pbVar12;
  byte *unaff_ESI;
  byte *pbVar13;
  int unaff_EDI;
  
switchD_0056d6e2_caseD_b:
  uVar8 = param_1 >> 4;
  pbVar13 = unaff_ESI;
  if (uVar8 == 0) {
    uVar8 = CONCAT31((uint3)(param_1 >> 0xc),*unaff_ESI);
    pbVar13 = unaff_ESI + 1;
  }
  iVar10 = (unaff_EDI - uVar8) + 1;
  do {
    if (*(int *)(unaff_EBX + 0xc) < iVar10) {
      iVar10 = DAT_0088c054 - uVar8;
      goto LAB_0056d6c0;
    }
    if (*(int *)(unaff_EBX + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(unaff_EBX + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(unaff_EBX + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      if (iVar10 < *(int *)(unaff_EBX + 8)) {
        uVar8 = uVar8 - (*(int *)(unaff_EBX + 8) - iVar10);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)((char)DAT_0088c054 - (char)DAT_0088c044._8_4_ & 3U |
                               *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))();
      return;
    }
    unaff_EBX = *(int *)(unaff_EBX + 4);
    iVar5 = DAT_0088c03c;
  } while (unaff_EBX != 0);
  goto switchD_0056d42a_caseD_f;
LAB_0056d6c0:
  bVar1 = *pbVar13;
  param_1 = (uint)bVar1;
  unaff_EDI = iVar10 - DAT_0088c020;
  unaff_ESI = pbVar13 + 1;
  cVar4 = (char)iVar10;
  unaff_EBX = DAT_0088c03c;
  iVar5 = DAT_0088c03c;
  DAT_0088c044._12_4_ = pbVar13;
  DAT_0088c054 = iVar10;
  switch(bVar1 & 0xf) {
  default:
    uVar8 = (uint)(bVar1 >> 2);
    break;
  case 1:
  case 5:
  case 9:
  case 0xd:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 2:
    uVar8 = CONCAT31((int3)((param_1 << 4) >> 8),*unaff_ESI);
    unaff_ESI = pbVar13 + 2;
    break;
  case 3:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 6:
    uVar8 = (uint)(bVar1 >> 4);
    if (uVar8 == 0) {
      uVar8 = (uint)*unaff_ESI;
      unaff_ESI = pbVar13 + 2;
    }
    iVar7 = (unaff_EDI - uVar8) + 1;
    iVar11 = DAT_0088c03c;
    while (iVar7 <= *(int *)(iVar11 + 0xc)) {
      if (*(int *)(iVar11 + 8) <= unaff_EDI) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
          DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
          uVar8 = uVar8 - DAT_0088c044._8_4_;
        }
        if (iVar7 < *(int *)(iVar11 + 8)) {
          uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056be00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar11 = *(int *)(iVar11 + 4);
      if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
    }
    pbVar13 = unaff_ESI + uVar8;
    iVar10 = iVar10 - uVar8;
    goto LAB_0056d6c0;
  case 7:
    uVar8 = (uint)(bVar1 >> 4);
    if (uVar8 == 0) {
      uVar8 = (uint)*unaff_ESI;
      unaff_ESI = pbVar13 + 2;
    }
    iVar7 = (unaff_EDI - uVar8) + 1;
    iVar11 = DAT_0088c03c;
    while (iVar7 <= *(int *)(iVar11 + 0xc)) {
      if (*(int *)(iVar11 + 8) <= unaff_EDI) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
          DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
          uVar8 = uVar8 - DAT_0088c044._8_4_;
        }
        if (iVar7 < *(int *)(iVar11 + 8)) {
          uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar11 = *(int *)(iVar11 + 4);
      if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
    }
    pbVar13 = unaff_ESI + 1;
    iVar10 = iVar10 - uVar8;
    goto LAB_0056d6c0;
  case 10:
    goto switchD_0056d6e2_caseD_a;
  case 0xb:
    goto switchD_0056d6e2_caseD_b;
  case 0xe:
    (**(code **)(&DAT_0056b580 + (uint)(bVar1 >> 4) * 4))();
    return;
  case 0xf:
switchD_0056d42a_caseD_f:
    do {
      do {
        do {
          DAT_0088c03c = iVar5;
          DAT_0088c038 = DAT_0088c038 + 1;
          if (*(int *)(unaff_EBP + 0x18) <= DAT_0088c038) {
            return;
          }
          uVar8 = *(int *)(unaff_EBP + 0x10) + DAT_0088c038;
          iVar11 = *(int *)(DAT_0088c008 + uVar8 * 4);
          iVar5 = DAT_0088c03c;
        } while (iVar11 == 0);
        if ((DAT_0088c044._4_1_ & 0x80) != 0) {
          uVar8 = uVar8 & 3;
          DAT_0088c02c._4_4_ = *(uint *)(&DAT_0088c058.field_0x18 + uVar8 * 4);
          DAT_0088c02c._0_4_ = *(uint *)(&DAT_0088c058.field_0x8 + uVar8 * 4);
          DAT_0088c02c._8_4_ = DAT_0088c040 & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
        }
        uVar2 = *(ushort *)(DAT_0088c010 + 2 + DAT_0088c038 * 4);
        iVar5 = iVar11;
      } while ((uVar2 & 0x8000) != 0);
      iVar9 = DAT_0088c024 + (uint)uVar2;
      iVar7 = DAT_0088c028 - (uint)*(ushort *)(DAT_0088c010 + DAT_0088c038 * 4);
      DAT_0088c020 = *(int *)(DAT_0088c000 + (*(int *)(unaff_EBP + 0x10) + DAT_0088c038) * 4);
      iVar10 = DAT_0088c020 + iVar7;
      pbVar13 = (byte *)(*(int *)(DAT_0088c00c + DAT_0088c038 * 4) + *(int *)(unaff_EBP + 8));
      DAT_0088c03c = iVar11;
      do {
        DAT_0088c014 = iVar10;
        DAT_0088c018 = pbVar13;
        if (*(int *)(DAT_0088c03c + 0xc) < iVar9) break;
        if (*(int *)(DAT_0088c03c + 8) <= iVar7) {
          if ((iVar9 < *(int *)(DAT_0088c03c + 8)) || (*(int *)(DAT_0088c03c + 0xc) < iVar7)) {
            DAT_0088c044._0_4_ = 0x56d6c0;
            goto LAB_0056d6c0;
          }
          DAT_0088c044._0_4_ = 0x56d420;
          goto LAB_0056d420;
        }
        DAT_0088c03c = *(int *)(DAT_0088c03c + 4);
      } while (DAT_0088c03c != 0);
    } while( true );
  }
  iVar7 = (unaff_EDI - uVar8) + 1;
  iVar11 = DAT_0088c03c;
  while (iVar7 <= *(int *)(iVar11 + 0xc)) {
    if (*(int *)(iVar11 + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      sVar6 = (short)uVar8;
      if (iVar7 < *(int *)(iVar11 + 8)) {
        sVar6 = sVar6 - ((short)*(undefined4 *)(iVar11 + 8) - (short)iVar7);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | DAT_0088c044._4_1_ |
                              *(byte *)((byte)(-(char)((ushort)sVar6 >> 8) & 0x80U | (byte)sVar6) +
                                       0x56b300)) * 4))();
      return;
    }
    iVar11 = *(int *)(iVar11 + 4);
    if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
  }
  pbVar13 = unaff_ESI + uVar8;
  iVar10 = iVar10 - uVar8;
  goto LAB_0056d6c0;
LAB_0056d420:
  do {
    bVar1 = *pbVar13;
    pbVar12 = pbVar13 + 1;
    bVar3 = (byte)iVar10;
    switch(bVar1 & 0xf) {
    default:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)((bVar1 >> 2) + 0x56b300) | DAT_0088c044._4_1_)
                  * 4))();
      return;
    case 1:
    case 5:
    case 9:
    case 0xd:
      iVar10 = iVar10 - (uint)(bVar1 >> 2);
      pbVar13 = pbVar12;
      break;
    case 2:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | DAT_0088c044._4_1_ |
                              *(byte *)((-(char)(((uint)bVar1 << 4) >> 8) & 0x80U | *pbVar12) +
                                       0x56b300)) * 4))();
      return;
    case 3:
      pbVar13 = pbVar13 + 2;
      iVar10 = iVar10 - (uint)*pbVar12;
      break;
    case 6:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056be00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 7:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 10:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xb:
      uVar8 = (uint)(bVar1 >> 4);
      if (uVar8 == 0) {
        uVar8 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar8 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xe:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b5c0 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
      goto switchD_0056d42a_caseD_f;
    }
  } while( true );
switchD_0056d6e2_caseD_a:
  uVar8 = (uint)(bVar1 >> 4);
  if (uVar8 == 0) {
    uVar8 = (uint)*unaff_ESI;
    unaff_ESI = pbVar13 + 2;
  }
  iVar7 = (unaff_EDI - uVar8) + 1;
  iVar11 = DAT_0088c03c;
  while (iVar7 <= *(int *)(iVar11 + 0xc)) {
    if (*(int *)(iVar11 + 8) <= unaff_EDI) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar11 + 0xc) < unaff_EDI) {
        DAT_0088c044._8_4_ = unaff_EDI - *(int *)(iVar11 + 0xc);
        uVar8 = uVar8 - DAT_0088c044._8_4_;
      }
      if (iVar7 < *(int *)(iVar11 + 8)) {
        uVar8 = uVar8 - (*(int *)(iVar11 + 8) - iVar7);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar8 + 0x56b300) |
                              DAT_0088c044._4_1_) * 4))();
      return;
    }
    iVar11 = *(int *)(iVar11 + 4);
    if (iVar11 == 0) goto switchD_0056d42a_caseD_f;
  }
  pbVar13 = unaff_ESI + 1;
  iVar10 = iVar10 - uVar8;
  goto LAB_0056d6c0;
}

// --------------------------------------------------

// Function: FUN_0056da65
// Address: 0056da65
// XREFS: None
void __fastcall FUN_0056da65(undefined4 param_1)
{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int unaff_EBX;
  int unaff_EBP;
  byte *pbVar12;
  byte *pbVar13;
  undefined1 *unaff_ESI;
  int unaff_EDI;
  
  iVar9 = CONCAT31((int3)((uint)param_1 >> 8),*unaff_ESI);
  if (unaff_ESI + 1 == (byte *)0x0) {
    iVar9 = 1;
  }
  if (DAT_0088c058._0_4_ != 0) {
    iVar11 = (unaff_EDI - iVar9) + 1;
    while (iVar11 <= *(int *)(unaff_EBX + 0xc)) {
      if (*(int *)(unaff_EBX + 8) <= unaff_EDI) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(unaff_EBX + 0xc) < unaff_EDI) {
          DAT_0088c044._8_4_ = unaff_EDI - *(int *)(unaff_EBX + 0xc);
          iVar9 = iVar9 - DAT_0088c044._8_4_;
        }
        if (iVar11 < *(int *)(unaff_EBX + 8)) {
          iVar9 = iVar9 - (*(int *)(unaff_EBX + 8) - iVar11);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)((char)DAT_0088c054 - (char)DAT_0088c044._8_4_ & 3U |
                                 *(byte *)(iVar9 + 0x56b300) | DAT_0088c044._4_1_) * 4))();
        return;
      }
      unaff_EBX = *(int *)(unaff_EBX + 4);
      iVar5 = DAT_0088c03c;
      if (unaff_EBX == 0) goto switchD_0056d42a_caseD_f;
    }
  }
  iVar9 = DAT_0088c054 - iVar9;
  DAT_0088c044._12_4_ = unaff_ESI + 1;
LAB_0056d6c0:
  bVar1 = *(byte *)DAT_0088c044._12_4_;
  iVar11 = iVar9 - DAT_0088c020;
  pbVar13 = (byte *)(DAT_0088c044._12_4_ + 1);
  cVar4 = (char)iVar9;
  iVar5 = DAT_0088c03c;
  DAT_0088c054 = iVar9;
  switch(bVar1 & 0xf) {
  default:
    uVar6 = (uint)(bVar1 >> 2);
    goto LAB_0056d72b;
  case 1:
  case 5:
  case 9:
  case 0xd:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 2:
    uVar6 = CONCAT31((int3)(((uint)bVar1 << 4) >> 8),*pbVar13);
    pbVar13 = (byte *)(DAT_0088c044._12_4_ + 2);
LAB_0056d72b:
    iVar10 = (iVar11 - uVar6) + 1;
    iVar8 = DAT_0088c03c;
    do {
      if (*(int *)(iVar8 + 0xc) < iVar10) {
        iVar9 = iVar9 - uVar6;
        DAT_0088c044._12_4_ = pbVar13 + uVar6;
        goto LAB_0056d6c0;
      }
      if (*(int *)(iVar8 + 8) <= iVar11) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar8 + 0xc) < iVar11) {
          DAT_0088c044._8_4_ = iVar11 - *(int *)(iVar8 + 0xc);
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        sVar7 = (short)uVar6;
        if (iVar10 < *(int *)(iVar8 + 8)) {
          sVar7 = sVar7 - ((short)*(undefined4 *)(iVar8 + 8) - (short)iVar10);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056b600 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | DAT_0088c044._4_1_ |
                                *(byte *)((byte)(-(char)((ushort)sVar7 >> 8) & 0x80U | (byte)sVar7)
                                         + 0x56b300)) * 4))();
        return;
      }
      iVar8 = *(int *)(iVar8 + 4);
    } while (iVar8 != 0);
    break;
  case 3:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 6:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar13;
      pbVar13 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar10 = (iVar11 - uVar6) + 1;
    iVar8 = DAT_0088c03c;
    do {
      if (*(int *)(iVar8 + 0xc) < iVar10) {
        DAT_0088c044._12_4_ = pbVar13 + uVar6;
        iVar9 = iVar9 - uVar6;
        goto LAB_0056d6c0;
      }
      if (*(int *)(iVar8 + 8) <= iVar11) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar8 + 0xc) < iVar11) {
          DAT_0088c044._8_4_ = iVar11 - *(int *)(iVar8 + 0xc);
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (iVar10 < *(int *)(iVar8 + 8)) {
          uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar10);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056be00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar8 = *(int *)(iVar8 + 4);
    } while (iVar8 != 0);
    break;
  case 7:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar13;
      pbVar13 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar10 = (iVar11 - uVar6) + 1;
    iVar8 = DAT_0088c03c;
    do {
      if (*(int *)(iVar8 + 0xc) < iVar10) {
        DAT_0088c044._12_4_ = pbVar13 + 1;
        iVar9 = iVar9 - uVar6;
        goto LAB_0056d6c0;
      }
      if (*(int *)(iVar8 + 8) <= iVar11) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar8 + 0xc) < iVar11) {
          DAT_0088c044._8_4_ = iVar11 - *(int *)(iVar8 + 0xc);
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (iVar10 < *(int *)(iVar8 + 8)) {
          uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar10);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar8 = *(int *)(iVar8 + 4);
    } while (iVar8 != 0);
    break;
  case 10:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar13;
      pbVar13 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar10 = (iVar11 - uVar6) + 1;
    iVar8 = DAT_0088c03c;
    do {
      if (*(int *)(iVar8 + 0xc) < iVar10) {
        DAT_0088c044._12_4_ = pbVar13 + 1;
        iVar9 = iVar9 - uVar6;
        goto LAB_0056d6c0;
      }
      if (*(int *)(iVar8 + 8) <= iVar11) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar8 + 0xc) < iVar11) {
          DAT_0088c044._8_4_ = iVar11 - *(int *)(iVar8 + 0xc);
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (iVar10 < *(int *)(iVar8 + 8)) {
          uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar10);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar8 = *(int *)(iVar8 + 4);
    } while (iVar8 != 0);
    break;
  case 0xb:
    goto switchD_0056d6e2_caseD_b;
  case 0xe:
    (**(code **)(&DAT_0056b580 + (uint)(bVar1 >> 4) * 4))();
    return;
  case 0xf:
    break;
  }
  goto switchD_0056d42a_caseD_f;
switchD_0056d6e2_caseD_b:
  uVar6 = (uint)(bVar1 >> 4);
  if (uVar6 == 0) {
    uVar6 = (uint)*pbVar13;
    pbVar13 = (byte *)(DAT_0088c044._12_4_ + 2);
  }
  iVar10 = (iVar11 - uVar6) + 1;
  iVar8 = DAT_0088c03c;
  do {
    if (*(int *)(iVar8 + 0xc) < iVar10) {
      iVar9 = iVar9 - uVar6;
      DAT_0088c044._12_4_ = pbVar13;
      goto LAB_0056d6c0;
    }
    if (*(int *)(iVar8 + 8) <= iVar11) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar8 + 0xc) < iVar11) {
        DAT_0088c044._8_4_ = iVar11 - *(int *)(iVar8 + 0xc);
        uVar6 = uVar6 - DAT_0088c044._8_4_;
      }
      if (iVar10 < *(int *)(iVar8 + 8)) {
        uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar10);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300) |
                              DAT_0088c044._4_1_) * 4))();
      return;
    }
    iVar8 = *(int *)(iVar8 + 4);
  } while (iVar8 != 0);
switchD_0056d42a_caseD_f:
  do {
    do {
      do {
        DAT_0088c03c = iVar5;
        DAT_0088c038 = DAT_0088c038 + 1;
        if (*(int *)(unaff_EBP + 0x18) <= DAT_0088c038) {
          return;
        }
        uVar6 = *(int *)(unaff_EBP + 0x10) + DAT_0088c038;
        iVar11 = *(int *)(DAT_0088c008 + uVar6 * 4);
        iVar5 = DAT_0088c03c;
      } while (iVar11 == 0);
      if ((DAT_0088c044._4_1_ & 0x80) != 0) {
        uVar6 = uVar6 & 3;
        DAT_0088c02c._4_4_ = *(uint *)(&DAT_0088c058.field_0x18 + uVar6 * 4);
        DAT_0088c02c._0_4_ = *(uint *)(&DAT_0088c058.field_0x8 + uVar6 * 4);
        DAT_0088c02c._8_4_ = DAT_0088c040 & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
      }
      uVar2 = *(ushort *)(DAT_0088c010 + 2 + DAT_0088c038 * 4);
      iVar5 = iVar11;
    } while ((uVar2 & 0x8000) != 0);
    iVar10 = DAT_0088c024 + (uint)uVar2;
    iVar8 = DAT_0088c028 - (uint)*(ushort *)(DAT_0088c010 + DAT_0088c038 * 4);
    DAT_0088c020 = *(int *)(DAT_0088c000 + (*(int *)(unaff_EBP + 0x10) + DAT_0088c038) * 4);
    iVar9 = DAT_0088c020 + iVar8;
    DAT_0088c018 = (byte *)(*(int *)(DAT_0088c00c + DAT_0088c038 * 4) + *(int *)(unaff_EBP + 8));
    DAT_0088c03c = iVar11;
    do {
      DAT_0088c014 = iVar9;
      if (*(int *)(DAT_0088c03c + 0xc) < iVar10) break;
      if (*(int *)(DAT_0088c03c + 8) <= iVar8) {
        if ((iVar10 < *(int *)(DAT_0088c03c + 8)) || (*(int *)(DAT_0088c03c + 0xc) < iVar8)) {
          DAT_0088c044._0_4_ = 0x56d6c0;
          DAT_0088c044._12_4_ = DAT_0088c018;
          goto LAB_0056d6c0;
        }
        DAT_0088c044._0_4_ = 0x56d420;
        pbVar13 = DAT_0088c018;
        goto LAB_0056d420;
      }
      DAT_0088c03c = *(int *)(DAT_0088c03c + 4);
    } while (DAT_0088c03c != 0);
  } while( true );
LAB_0056d420:
  do {
    bVar1 = *pbVar13;
    pbVar12 = pbVar13 + 1;
    bVar3 = (byte)iVar9;
    switch(bVar1 & 0xf) {
    default:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)((bVar1 >> 2) + 0x56b300) | DAT_0088c044._4_1_)
                  * 4))();
      return;
    case 1:
    case 5:
    case 9:
    case 0xd:
      iVar9 = iVar9 - (uint)(bVar1 >> 2);
      pbVar13 = pbVar12;
      break;
    case 2:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | DAT_0088c044._4_1_ |
                              *(byte *)((-(char)(((uint)bVar1 << 4) >> 8) & 0x80U | *pbVar12) +
                                       0x56b300)) * 4))();
      return;
    case 3:
      pbVar13 = pbVar13 + 2;
      iVar9 = iVar9 - (uint)*pbVar12;
      break;
    case 6:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056be00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 7:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 10:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xb:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar12;
      }
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xe:
      DAT_0088c03c = iVar11;
      (**(code **)(&DAT_0056b5c0 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
      goto switchD_0056d42a_caseD_f;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0056db16
// Address: 0056db16
// XREFS: None
void FUN_0056db16(void)
{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  int extraout_ECX;
  int iVar9;
  int unaff_EBP;
  byte *pbVar10;
  byte *pbVar11;
  byte *unaff_ESI;
  int iVar12;
  int unaff_EDI;
  
  FUN_0056db60();
  DAT_0088c044._12_4_ = unaff_ESI;
  DAT_0088c054 = unaff_EDI + extraout_ECX;
LAB_0056d6c0:
  bVar1 = *(byte *)DAT_0088c044._12_4_;
  iVar12 = DAT_0088c054 - DAT_0088c020;
  pbVar11 = (byte *)(DAT_0088c044._12_4_ + 1);
  cVar4 = (char)DAT_0088c054;
  iVar5 = DAT_0088c03c;
  switch(bVar1 & 0xf) {
  default:
    uVar6 = (uint)(bVar1 >> 2);
    goto LAB_0056d72b;
  case 1:
  case 5:
  case 9:
  case 0xd:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 2:
    uVar6 = CONCAT31((int3)(((uint)bVar1 << 4) >> 8),*pbVar11);
    pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
LAB_0056d72b:
    iVar9 = (iVar12 - uVar6) + 1;
    iVar8 = DAT_0088c03c;
    do {
      if (*(int *)(iVar8 + 0xc) < iVar9) {
        DAT_0088c054 = DAT_0088c054 - uVar6;
        DAT_0088c044._12_4_ = pbVar11 + uVar6;
        goto LAB_0056d6c0;
      }
      if (*(int *)(iVar8 + 8) <= iVar12) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar8 + 0xc) < iVar12) {
          DAT_0088c044._8_4_ = iVar12 - *(int *)(iVar8 + 0xc);
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        sVar7 = (short)uVar6;
        if (iVar9 < *(int *)(iVar8 + 8)) {
          sVar7 = sVar7 - ((short)*(undefined4 *)(iVar8 + 8) - (short)iVar9);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056b600 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | DAT_0088c044._4_1_ |
                                *(byte *)((byte)(-(char)((ushort)sVar7 >> 8) & 0x80U | (byte)sVar7)
                                         + 0x56b300)) * 4))();
        return;
      }
      iVar8 = *(int *)(iVar8 + 4);
    } while (iVar8 != 0);
    break;
  case 3:
    (*(code *)DAT_0088c044._0_4_)();
    return;
  case 6:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar11;
      pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar9 = (iVar12 - uVar6) + 1;
    iVar8 = DAT_0088c03c;
    do {
      if (*(int *)(iVar8 + 0xc) < iVar9) {
        DAT_0088c044._12_4_ = pbVar11 + uVar6;
        DAT_0088c054 = DAT_0088c054 - uVar6;
        goto LAB_0056d6c0;
      }
      if (*(int *)(iVar8 + 8) <= iVar12) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar8 + 0xc) < iVar12) {
          DAT_0088c044._8_4_ = iVar12 - *(int *)(iVar8 + 0xc);
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (iVar9 < *(int *)(iVar8 + 8)) {
          uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar9);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056be00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar8 = *(int *)(iVar8 + 4);
    } while (iVar8 != 0);
    break;
  case 7:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar11;
      pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar9 = (iVar12 - uVar6) + 1;
    iVar8 = DAT_0088c03c;
    do {
      if (*(int *)(iVar8 + 0xc) < iVar9) {
        DAT_0088c044._12_4_ = pbVar11 + 1;
        DAT_0088c054 = DAT_0088c054 - uVar6;
        goto LAB_0056d6c0;
      }
      if (*(int *)(iVar8 + 8) <= iVar12) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar8 + 0xc) < iVar12) {
          DAT_0088c044._8_4_ = iVar12 - *(int *)(iVar8 + 0xc);
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (iVar9 < *(int *)(iVar8 + 8)) {
          uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar9);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar8 = *(int *)(iVar8 + 4);
    } while (iVar8 != 0);
    break;
  case 10:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar11;
      pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar9 = (iVar12 - uVar6) + 1;
    iVar8 = DAT_0088c03c;
    do {
      if (*(int *)(iVar8 + 0xc) < iVar9) {
        DAT_0088c044._12_4_ = pbVar11 + 1;
        DAT_0088c054 = DAT_0088c054 - uVar6;
        goto LAB_0056d6c0;
      }
      if (*(int *)(iVar8 + 8) <= iVar12) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar8 + 0xc) < iVar12) {
          DAT_0088c044._8_4_ = iVar12 - *(int *)(iVar8 + 0xc);
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (iVar9 < *(int *)(iVar8 + 8)) {
          uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar9);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar8 = *(int *)(iVar8 + 4);
    } while (iVar8 != 0);
    break;
  case 0xb:
    goto switchD_0056d6e2_caseD_b;
  case 0xe:
    (**(code **)(&DAT_0056b580 + (uint)(bVar1 >> 4) * 4))();
    return;
  case 0xf:
    break;
  }
  goto switchD_0056d42a_caseD_f;
switchD_0056d6e2_caseD_b:
  uVar6 = (uint)(bVar1 >> 4);
  if (uVar6 == 0) {
    uVar6 = (uint)*pbVar11;
    pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
  }
  iVar9 = (iVar12 - uVar6) + 1;
  iVar8 = DAT_0088c03c;
  do {
    if (*(int *)(iVar8 + 0xc) < iVar9) {
      DAT_0088c054 = DAT_0088c054 - uVar6;
      DAT_0088c044._12_4_ = pbVar11;
      goto LAB_0056d6c0;
    }
    if (*(int *)(iVar8 + 8) <= iVar12) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar8 + 0xc) < iVar12) {
        DAT_0088c044._8_4_ = iVar12 - *(int *)(iVar8 + 0xc);
        uVar6 = uVar6 - DAT_0088c044._8_4_;
      }
      if (iVar9 < *(int *)(iVar8 + 8)) {
        uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar9);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300) |
                              DAT_0088c044._4_1_) * 4))();
      return;
    }
    iVar8 = *(int *)(iVar8 + 4);
  } while (iVar8 != 0);
switchD_0056d42a_caseD_f:
  do {
    do {
      do {
        DAT_0088c03c = iVar5;
        DAT_0088c038 = DAT_0088c038 + 1;
        if (*(int *)(unaff_EBP + 0x18) <= DAT_0088c038) {
          return;
        }
        uVar6 = *(int *)(unaff_EBP + 0x10) + DAT_0088c038;
        iVar12 = *(int *)(DAT_0088c008 + uVar6 * 4);
        iVar5 = DAT_0088c03c;
      } while (iVar12 == 0);
      if ((DAT_0088c044._4_1_ & 0x80) != 0) {
        uVar6 = uVar6 & 3;
        DAT_0088c02c._4_4_ = *(uint *)(&DAT_0088c058.field_0x18 + uVar6 * 4);
        DAT_0088c02c._0_4_ = *(uint *)(&DAT_0088c058.field_0x8 + uVar6 * 4);
        DAT_0088c02c._8_4_ = DAT_0088c040 & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
      }
      uVar2 = *(ushort *)(DAT_0088c010 + 2 + DAT_0088c038 * 4);
      iVar5 = iVar12;
    } while ((uVar2 & 0x8000) != 0);
    iVar9 = DAT_0088c024 + (uint)uVar2;
    iVar8 = DAT_0088c028 - (uint)*(ushort *)(DAT_0088c010 + DAT_0088c038 * 4);
    DAT_0088c020 = *(int *)(DAT_0088c000 + (*(int *)(unaff_EBP + 0x10) + DAT_0088c038) * 4);
    DAT_0088c014 = DAT_0088c020 + iVar8;
    DAT_0088c018 = (byte *)(*(int *)(DAT_0088c00c + DAT_0088c038 * 4) + *(int *)(unaff_EBP + 8));
    DAT_0088c03c = iVar12;
    do {
      if (*(int *)(DAT_0088c03c + 0xc) < iVar9) break;
      if (*(int *)(DAT_0088c03c + 8) <= iVar8) {
        if ((iVar9 < *(int *)(DAT_0088c03c + 8)) || (*(int *)(DAT_0088c03c + 0xc) < iVar8)) {
          DAT_0088c044._0_4_ = 0x56d6c0;
          DAT_0088c044._12_4_ = DAT_0088c018;
          DAT_0088c054 = DAT_0088c014;
          goto LAB_0056d6c0;
        }
        DAT_0088c044._0_4_ = 0x56d420;
        pbVar11 = DAT_0088c018;
        iVar8 = DAT_0088c014;
        goto LAB_0056d420;
      }
      DAT_0088c03c = *(int *)(DAT_0088c03c + 4);
    } while (DAT_0088c03c != 0);
  } while( true );
LAB_0056d420:
  do {
    bVar1 = *pbVar11;
    pbVar10 = pbVar11 + 1;
    bVar3 = (byte)iVar8;
    switch(bVar1 & 0xf) {
    default:
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)((bVar1 >> 2) + 0x56b300) | DAT_0088c044._4_1_)
                  * 4))();
      return;
    case 1:
    case 5:
    case 9:
    case 0xd:
      iVar8 = iVar8 - (uint)(bVar1 >> 2);
      pbVar11 = pbVar10;
      break;
    case 2:
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | DAT_0088c044._4_1_ |
                              *(byte *)((-(char)(((uint)bVar1 << 4) >> 8) & 0x80U | *pbVar10) +
                                       0x56b300)) * 4))();
      return;
    case 3:
      pbVar11 = pbVar11 + 2;
      iVar8 = iVar8 - (uint)*pbVar10;
      break;
    case 6:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar10;
      }
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056be00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 7:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar10;
      }
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 10:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar10;
      }
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xb:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar10;
      }
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xe:
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056b5c0 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
      goto switchD_0056d42a_caseD_f;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0056db2e
// Address: 0056db2e
// XREFS: None
void FUN_0056db2e(void)
{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int unaff_EBP;
  byte *pbVar10;
  byte *pbVar11;
  int iVar12;
  
  iVar5 = DAT_0088c03c;
switchD_0056d42a_caseD_f:
  do {
    do {
      do {
        DAT_0088c03c = iVar5;
        DAT_0088c038 = DAT_0088c038 + 1;
        if (*(int *)(unaff_EBP + 0x18) <= DAT_0088c038) {
          return;
        }
        uVar6 = *(int *)(unaff_EBP + 0x10) + DAT_0088c038;
        iVar12 = *(int *)(DAT_0088c008 + uVar6 * 4);
        iVar5 = DAT_0088c03c;
      } while (iVar12 == 0);
      if ((DAT_0088c044._4_1_ & 0x80) != 0) {
        uVar6 = uVar6 & 3;
        DAT_0088c02c._4_4_ = *(uint *)(&DAT_0088c058.field_0x18 + uVar6 * 4);
        DAT_0088c02c._0_4_ = *(uint *)(&DAT_0088c058.field_0x8 + uVar6 * 4);
        DAT_0088c02c._8_4_ = DAT_0088c040 & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
      }
      uVar2 = *(ushort *)(DAT_0088c010 + 2 + DAT_0088c038 * 4);
      iVar5 = iVar12;
    } while ((uVar2 & 0x8000) != 0);
    iVar9 = DAT_0088c024 + (uint)uVar2;
    iVar8 = DAT_0088c028 - (uint)*(ushort *)(DAT_0088c010 + DAT_0088c038 * 4);
    DAT_0088c020 = *(int *)(DAT_0088c000 + (*(int *)(unaff_EBP + 0x10) + DAT_0088c038) * 4);
    DAT_0088c014 = DAT_0088c020 + iVar8;
    DAT_0088c018 = (byte *)(*(int *)(DAT_0088c00c + DAT_0088c038 * 4) + *(int *)(unaff_EBP + 8));
    DAT_0088c03c = iVar12;
    do {
      if (*(int *)(DAT_0088c03c + 0xc) < iVar9) break;
      if (*(int *)(DAT_0088c03c + 8) <= iVar8) {
        if ((iVar9 < *(int *)(DAT_0088c03c + 8)) || (*(int *)(DAT_0088c03c + 0xc) < iVar8)) {
          DAT_0088c044._0_4_ = 0x56d6c0;
          DAT_0088c044._12_4_ = DAT_0088c018;
          DAT_0088c054 = DAT_0088c014;
          goto LAB_0056d6c0;
        }
        DAT_0088c044._0_4_ = 0x56d420;
        pbVar11 = DAT_0088c018;
        iVar8 = DAT_0088c014;
        goto LAB_0056d420;
      }
      DAT_0088c03c = *(int *)(DAT_0088c03c + 4);
    } while (DAT_0088c03c != 0);
  } while( true );
LAB_0056d420:
  do {
    bVar1 = *pbVar11;
    pbVar10 = pbVar11 + 1;
    bVar3 = (byte)iVar8;
    switch(bVar1 & 0xf) {
    default:
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)((bVar1 >> 2) + 0x56b300) | DAT_0088c044._4_1_)
                  * 4))();
      return;
    case 1:
    case 5:
    case 9:
    case 0xd:
      iVar8 = iVar8 - (uint)(bVar1 >> 2);
      pbVar11 = pbVar10;
      break;
    case 2:
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(bVar3 & 3 | DAT_0088c044._4_1_ |
                              *(byte *)((-(char)(((uint)bVar1 << 4) >> 8) & 0x80U | *pbVar10) +
                                       0x56b300)) * 4))();
      return;
    case 3:
      pbVar11 = pbVar11 + 2;
      iVar8 = iVar8 - (uint)*pbVar10;
      break;
    case 6:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar10;
      }
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056be00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 7:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar10;
      }
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 10:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar10;
      }
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056ba00 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xb:
      uVar6 = (uint)(bVar1 >> 4);
      if (uVar6 == 0) {
        uVar6 = (uint)*pbVar10;
      }
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(bVar3 & 3 | *(byte *)(uVar6 + 0x56b300) | DAT_0088c044._4_1_) * 4))()
      ;
      return;
    case 0xe:
      DAT_0088c03c = iVar12;
      (**(code **)(&DAT_0056b5c0 + (uint)(bVar1 >> 4) * 4))();
      return;
    case 0xf:
      goto switchD_0056d42a_caseD_f;
    }
  } while( true );
LAB_0056d6c0:
  bVar1 = *(byte *)DAT_0088c044._12_4_;
  iVar12 = DAT_0088c054 - DAT_0088c020;
  pbVar11 = (byte *)(DAT_0088c044._12_4_ + 1);
  cVar4 = (char)DAT_0088c054;
  iVar5 = DAT_0088c03c;
  switch(bVar1 & 0xf) {
  default:
    uVar6 = (uint)(bVar1 >> 2);
    break;
  case 1:
  case 5:
  case 9:
  case 0xd:
    DAT_0088c054 = DAT_0088c054 - (uint)(bVar1 >> 2);
    DAT_0088c044._12_4_ = pbVar11;
    goto LAB_0056d6c0;
  case 2:
    uVar6 = CONCAT31((int3)(((uint)bVar1 << 4) >> 8),*pbVar11);
    pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
    break;
  case 3:
    DAT_0088c044._12_4_ = DAT_0088c044._12_4_ + 2;
    DAT_0088c054 = DAT_0088c054 - CONCAT31((int3)(((uint)bVar1 << 4) >> 8),*pbVar11);
    goto LAB_0056d6c0;
  case 6:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar11;
      pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar9 = (iVar12 - uVar6) + 1;
    iVar8 = DAT_0088c03c;
    while (iVar9 <= *(int *)(iVar8 + 0xc)) {
      if (*(int *)(iVar8 + 8) <= iVar12) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar8 + 0xc) < iVar12) {
          DAT_0088c044._8_4_ = iVar12 - *(int *)(iVar8 + 0xc);
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (iVar9 < *(int *)(iVar8 + 8)) {
          uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar9);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056be00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar8 = *(int *)(iVar8 + 4);
      if (iVar8 == 0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = pbVar11 + uVar6;
    DAT_0088c054 = DAT_0088c054 - uVar6;
    goto LAB_0056d6c0;
  case 7:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar11;
      pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar9 = (iVar12 - uVar6) + 1;
    iVar8 = DAT_0088c03c;
    while (iVar9 <= *(int *)(iVar8 + 0xc)) {
      if (*(int *)(iVar8 + 8) <= iVar12) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar8 + 0xc) < iVar12) {
          DAT_0088c044._8_4_ = iVar12 - *(int *)(iVar8 + 0xc);
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (iVar9 < *(int *)(iVar8 + 8)) {
          uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar9);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar8 = *(int *)(iVar8 + 4);
      if (iVar8 == 0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = pbVar11 + 1;
    DAT_0088c054 = DAT_0088c054 - uVar6;
    goto LAB_0056d6c0;
  case 10:
    uVar6 = (uint)(bVar1 >> 4);
    if (uVar6 == 0) {
      uVar6 = (uint)*pbVar11;
      pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
    }
    iVar9 = (iVar12 - uVar6) + 1;
    iVar8 = DAT_0088c03c;
    while (iVar9 <= *(int *)(iVar8 + 0xc)) {
      if (*(int *)(iVar8 + 8) <= iVar12) {
        DAT_0088c044._8_4_ = 0;
        if (*(int *)(iVar8 + 0xc) < iVar12) {
          DAT_0088c044._8_4_ = iVar12 - *(int *)(iVar8 + 0xc);
          uVar6 = uVar6 - DAT_0088c044._8_4_;
        }
        if (iVar9 < *(int *)(iVar8 + 8)) {
          uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar9);
          DAT_0088c044._0_4_ = 0x56d660;
        }
        (**(code **)(&DAT_0056ba00 +
                    (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300)
                                | DAT_0088c044._4_1_) * 4))();
        return;
      }
      iVar8 = *(int *)(iVar8 + 4);
      if (iVar8 == 0) goto switchD_0056d42a_caseD_f;
    }
    DAT_0088c044._12_4_ = pbVar11 + 1;
    DAT_0088c054 = DAT_0088c054 - uVar6;
    goto LAB_0056d6c0;
  case 0xb:
    goto switchD_0056d6e2_caseD_b;
  case 0xe:
    (**(code **)(&DAT_0056b580 + (uint)(bVar1 >> 4) * 4))();
    return;
  case 0xf:
    goto switchD_0056d42a_caseD_f;
  }
  iVar9 = (iVar12 - uVar6) + 1;
  iVar8 = DAT_0088c03c;
  while (iVar9 <= *(int *)(iVar8 + 0xc)) {
    if (*(int *)(iVar8 + 8) <= iVar12) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar8 + 0xc) < iVar12) {
        DAT_0088c044._8_4_ = iVar12 - *(int *)(iVar8 + 0xc);
        uVar6 = uVar6 - DAT_0088c044._8_4_;
      }
      sVar7 = (short)uVar6;
      if (iVar9 < *(int *)(iVar8 + 8)) {
        sVar7 = sVar7 - ((short)*(undefined4 *)(iVar8 + 8) - (short)iVar9);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056b600 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | DAT_0088c044._4_1_ |
                              *(byte *)((byte)(-(char)((ushort)sVar7 >> 8) & 0x80U | (byte)sVar7) +
                                       0x56b300)) * 4))();
      return;
    }
    iVar8 = *(int *)(iVar8 + 4);
    if (iVar8 == 0) goto switchD_0056d42a_caseD_f;
  }
  DAT_0088c054 = DAT_0088c054 - uVar6;
  DAT_0088c044._12_4_ = pbVar11 + uVar6;
  goto LAB_0056d6c0;
switchD_0056d6e2_caseD_b:
  uVar6 = (uint)(bVar1 >> 4);
  if (uVar6 == 0) {
    uVar6 = (uint)*pbVar11;
    pbVar11 = (byte *)(DAT_0088c044._12_4_ + 2);
  }
  iVar9 = (iVar12 - uVar6) + 1;
  iVar8 = DAT_0088c03c;
  while (iVar9 <= *(int *)(iVar8 + 0xc)) {
    if (*(int *)(iVar8 + 8) <= iVar12) {
      DAT_0088c044._8_4_ = 0;
      if (*(int *)(iVar8 + 0xc) < iVar12) {
        DAT_0088c044._8_4_ = iVar12 - *(int *)(iVar8 + 0xc);
        uVar6 = uVar6 - DAT_0088c044._8_4_;
      }
      if (iVar9 < *(int *)(iVar8 + 8)) {
        uVar6 = uVar6 - (*(int *)(iVar8 + 8) - iVar9);
        DAT_0088c044._0_4_ = 0x56d660;
      }
      (**(code **)(&DAT_0056c200 +
                  (uint)(byte)(cVar4 - (char)DAT_0088c044._8_4_ & 3U | *(byte *)(uVar6 + 0x56b300) |
                              DAT_0088c044._4_1_) * 4))();
      return;
    }
    iVar8 = *(int *)(iVar8 + 4);
    if (iVar8 == 0) goto switchD_0056d42a_caseD_f;
  }
  DAT_0088c054 = DAT_0088c054 - uVar6;
  DAT_0088c044._12_4_ = pbVar11;
  goto LAB_0056d6c0;
}

// --------------------------------------------------

// Function: FUN_0056db59
// Address: 0056db59
// XREFS: None
void FUN_0056db59(void)
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
    (**(code **)(&DAT_0056c640 + (uint)(*unaff_ESI >> 4) * 4))();
    return;
  case 0xf:
    return;
  }
}

// --------------------------------------------------

// Function: FUN_0056db60
// Address: 0056db60
// XREFS: FUN_0056d078, FUN_0056d2a4, FUN_0056d624, FUN_0056db16
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
    (**(code **)(&DAT_0056c640 + (uint)(*unaff_ESI >> 4) * 4))();
    return;
  case 0xf:
    return;
  }
}

// --------------------------------------------------

