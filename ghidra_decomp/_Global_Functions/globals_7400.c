// GLOBAL FUNCTIONS PART 7400
// Function: FUN_00565a59
// Address: 00565a59
// XREFS: None
void __fastcall FUN_00565a59(undefined4 param_1,undefined4 param_2)
{
  int unaff_EBX;
  byte *unaff_EDI;
  
  *unaff_EDI = (*(byte *)(CONCAT31((int3)((uint)param_2 >> 8),*unaff_EDI) + unaff_EBX) |
               (byte)((uint)DAT_0088c02c._4_4_ >> 8)) & (byte)((uint)(undefined4)DAT_0088c02c >> 8);
                    /* WARNING: Could not recover jumptable at 0x00565a6d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565a73
// Address: 00565a73
// XREFS: None
void __fastcall FUN_00565a73(undefined4 param_1,undefined4 param_2)
{
  undefined3 uVar1;
  int unaff_EBX;
  ushort *unaff_EDI;
  
  uVar1 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (CONCAT11(*(undefined1 *)(CONCAT31(uVar1,(char)(*unaff_EDI >> 8)) + unaff_EBX),
                         *(undefined1 *)(CONCAT31(uVar1,(char)*unaff_EDI) + unaff_EBX)) |
               (ushort)DAT_0088c02c._4_4_) & (ushort)(undefined4)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565a92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565a98
// Address: 00565a98
// XREFS: None
void __fastcall FUN_00565a98(undefined4 param_1,undefined4 param_2)
{
  undefined3 uVar1;
  int unaff_EBX;
  ushort *unaff_EDI;
  
  uVar1 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (CONCAT11(*(undefined1 *)(CONCAT31(uVar1,(char)(*unaff_EDI >> 8)) + unaff_EBX),
                         *(undefined1 *)(CONCAT31(uVar1,(char)*unaff_EDI) + unaff_EBX)) |
               (ushort)((uint)DAT_0088c02c._4_4_ >> 8)) &
               (ushort)((uint)(undefined4)DAT_0088c02c >> 8);
                    /* WARNING: Could not recover jumptable at 0x00565abd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565ac3
// Address: 00565ac3
// XREFS: None
void __fastcall FUN_00565ac3(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  uint3 uVar3;
  uint uVar4;
  undefined3 uVar5;
  int unaff_EBX;
  uint *unaff_EDI;
  
  uVar2 = *unaff_EDI;
  uVar5 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar5,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar4 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar5,(char)uVar2) + unaff_EBX)) & 0xff |
           ((uint)bVar1 << 0x10) >> 8 |
           (uint)*(byte *)(CONCAT31(uVar5,(char)(uVar2 >> 0x10)) + unaff_EBX) << 0x10 |
          DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar3 = (uint3)((ushort)(uVar4 >> 0x10) & 0xff) | (uint3)uVar4 & 0xff00;
  *unaff_EDI = uVar4 & 0xff | uVar3 & 0xff00 | (uVar3 & 0xff) << 0x10 | uVar2 & 0xff000000;
                    /* WARNING: Could not recover jumptable at 0x00565af1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565af7
// Address: 00565af7
// XREFS: None
void __fastcall FUN_00565af7(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined3 uVar4;
  int unaff_EBX;
  int unaff_EDI;
  
  uVar2 = *(undefined4 *)(unaff_EDI + -1);
  uVar4 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar4,(char)((uint)uVar2 >> 8)) + unaff_EBX);
  uVar3 = (undefined1)((uint)uVar2 >> 0x18);
  *(uint *)(unaff_EDI + -1) =
       CONCAT31(((uint3)bVar1 |
                 (uint3)((((uint3)(CONCAT12(bVar1,CONCAT11(*(undefined1 *)
                                                            (CONCAT31(uVar4,(char)((uint)uVar2 >>
                                                                                  0x10)) + unaff_EBX
                                                            ),uVar3)) >> 8) & 0xff) << 0x10) >> 8) |
                 (uint3)(((uint)*(byte *)(CONCAT31(uVar4,uVar3) + unaff_EBX) << 0x18) >> 8) |
                (uint3)((uint)DAT_0088c02c._4_4_ >> 8)) &
                (uint3)((uint)(undefined4)DAT_0088c02c >> 8),(char)uVar2);
                    /* WARNING: Could not recover jumptable at 0x00565b23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565b29
// Address: 00565b29
// XREFS: None
void __fastcall FUN_00565b29(undefined4 param_1,undefined4 param_2)
{
  undefined3 uVar1;
  int unaff_EBX;
  ushort *unaff_EDI;
  
  uVar1 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (CONCAT11(*(undefined1 *)(CONCAT31(uVar1,(char)(*unaff_EDI >> 8)) + unaff_EBX),
                         *(undefined1 *)(CONCAT31(uVar1,(char)*unaff_EDI) + unaff_EBX)) |
               (ushort)DAT_0088c02c._4_4_) & (ushort)(undefined4)DAT_0088c02c;
  *(byte *)(unaff_EDI + 1) =
       (*(byte *)(CONCAT31(uVar1,(byte)unaff_EDI[1]) + unaff_EBX) | (byte)DAT_0088c02c._4_4_) &
       (byte)(undefined4)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565b5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565b62
// Address: 00565b62
// XREFS: None
void __fastcall FUN_00565b62(undefined4 param_1,undefined4 param_2)
{
  ushort uVar1;
  undefined3 uVar2;
  int unaff_EBX;
  byte *unaff_EDI;
  
  uVar2 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (*(byte *)(CONCAT31(uVar2,*unaff_EDI) + unaff_EBX) |
               (byte)((uint)DAT_0088c02c._4_4_ >> 8)) & (byte)((uint)(undefined4)DAT_0088c02c >> 8);
  uVar1 = *(ushort *)(unaff_EDI + 1);
  *(ushort *)(unaff_EDI + 1) =
       (CONCAT11(*(undefined1 *)(CONCAT31(uVar2,(char)(uVar1 >> 8)) + unaff_EBX),
                 *(undefined1 *)(CONCAT31(uVar2,(char)uVar1) + unaff_EBX)) |
       (ushort)DAT_0088c02c._4_4_) & (ushort)(undefined4)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565b95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565b9b
// Address: 00565b9b
// XREFS: None
void __fastcall FUN_00565b9b(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  undefined3 uVar4;
  int unaff_EBX;
  uint *unaff_EDI;
  
  uVar2 = *unaff_EDI;
  uVar4 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar4,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar3 = CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x10)) + unaff_EBX),
                   *(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x18)) + unaff_EBX));
  *unaff_EDI = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar4,(char)uVar2) + unaff_EBX)) & 0xff |
                ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
               DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565bc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565bcc
// Address: 00565bcc
// XREFS: None
void __fastcall FUN_00565bcc(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined3 uVar4;
  int unaff_EBX;
  int unaff_EDI;
  
  uVar2 = *(undefined4 *)(unaff_EDI + -1);
  uVar4 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar4,(char)((uint)uVar2 >> 8)) + unaff_EBX);
  uVar3 = (undefined1)((uint)uVar2 >> 0x18);
  *(uint *)(unaff_EDI + -1) =
       CONCAT31(((uint3)bVar1 |
                 (uint3)((((uint3)(CONCAT12(bVar1,CONCAT11(*(undefined1 *)
                                                            (CONCAT31(uVar4,(char)((uint)uVar2 >>
                                                                                  0x10)) + unaff_EBX
                                                            ),uVar3)) >> 8) & 0xff) << 0x10) >> 8) |
                 (uint3)(((uint)*(byte *)(CONCAT31(uVar4,uVar3) + unaff_EBX) << 0x18) >> 8) |
                (uint3)((uint)DAT_0088c02c._4_4_ >> 8)) &
                (uint3)((uint)(undefined4)DAT_0088c02c >> 8),(char)uVar2);
  *(byte *)(unaff_EDI + 3) =
       (*(byte *)(CONCAT31(uVar4,*(byte *)(unaff_EDI + 3)) + unaff_EBX) | (byte)DAT_0088c02c._4_4_)
       & (byte)(undefined4)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565c0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565c12
// Address: 00565c12
// XREFS: None
void __fastcall FUN_00565c12(undefined4 param_1,undefined4 param_2)
{
  ushort uVar1;
  undefined3 uVar2;
  int unaff_EBX;
  ushort *unaff_EDI;
  
  uVar2 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (CONCAT11(*(undefined1 *)(CONCAT31(uVar2,(char)(*unaff_EDI >> 8)) + unaff_EBX),
                         *(undefined1 *)(CONCAT31(uVar2,(char)*unaff_EDI) + unaff_EBX)) |
               (ushort)DAT_0088c02c._4_4_) & (ushort)(undefined4)DAT_0088c02c;
  uVar1 = unaff_EDI[1];
  unaff_EDI[1] = (CONCAT11(*(undefined1 *)(CONCAT31(uVar2,(char)(uVar1 >> 8)) + unaff_EBX),
                           *(undefined1 *)(CONCAT31(uVar2,(char)uVar1) + unaff_EBX)) |
                 (ushort)DAT_0088c02c._4_4_) & (ushort)(undefined4)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565c50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565c56
// Address: 00565c56
// XREFS: None
void __fastcall FUN_00565c56(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  uint3 uVar3;
  uint uVar4;
  undefined3 uVar5;
  int unaff_EBX;
  byte *unaff_EDI;
  
  uVar5 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (*(byte *)(CONCAT31(uVar5,*unaff_EDI) + unaff_EBX) | (byte)(DAT_0088c02c._4_4_ >> 8))
               & (byte)((uint)DAT_0088c02c >> 8);
  uVar2 = *(uint *)(unaff_EDI + 1);
  bVar1 = *(byte *)(CONCAT31(uVar5,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar4 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar5,(char)uVar2) + unaff_EBX)) & 0xff |
           ((uint)bVar1 << 0x10) >> 8 |
           (uint)*(byte *)(CONCAT31(uVar5,(char)(uVar2 >> 0x10)) + unaff_EBX) << 0x10 |
          DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar3 = (uint3)((ushort)(uVar4 >> 0x10) & 0xff) | (uint3)uVar4 & 0xff00;
  *(uint *)(unaff_EDI + 1) =
       uVar4 & 0xff | uVar3 & 0xff00 | (uVar3 & 0xff) << 0x10 | uVar2 & 0xff000000;
                    /* WARNING: Could not recover jumptable at 0x00565c98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565c9e
// Address: 00565c9e
// XREFS: None
void __fastcall FUN_00565c9e(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  undefined3 uVar4;
  int unaff_EBX;
  uint *unaff_EDI;
  
  uVar2 = *unaff_EDI;
  uVar4 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar4,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar3 = CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x10)) + unaff_EBX),
                   *(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x18)) + unaff_EBX));
  *unaff_EDI = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar4,(char)uVar2) + unaff_EBX)) & 0xff |
                ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
               DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  *(byte *)(unaff_EDI + 1) =
       (*(byte *)(CONCAT31(uVar4,(byte)unaff_EDI[1]) + unaff_EBX) | (byte)DAT_0088c02c._4_4_) &
       (byte)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565cdd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565ce3
// Address: 00565ce3
// XREFS: None
void __fastcall FUN_00565ce3(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined3 uVar5;
  int unaff_EBX;
  int unaff_EDI;
  
  uVar3 = *(undefined4 *)(unaff_EDI + -1);
  uVar5 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar5,(char)((uint)uVar3 >> 8)) + unaff_EBX);
  uVar4 = (undefined1)((uint)uVar3 >> 0x18);
  *(uint *)(unaff_EDI + -1) =
       CONCAT31(((uint3)bVar1 |
                 (uint3)((((uint3)(CONCAT12(bVar1,CONCAT11(*(undefined1 *)
                                                            (CONCAT31(uVar5,(char)((uint)uVar3 >>
                                                                                  0x10)) + unaff_EBX
                                                            ),uVar4)) >> 8) & 0xff) << 0x10) >> 8) |
                 (uint3)(((uint)*(byte *)(CONCAT31(uVar5,uVar4) + unaff_EBX) << 0x18) >> 8) |
                (uint3)((uint)DAT_0088c02c._4_4_ >> 8)) &
                (uint3)((uint)(undefined4)DAT_0088c02c >> 8),(char)uVar3);
  uVar2 = *(ushort *)(unaff_EDI + 3);
  *(ushort *)(unaff_EDI + 3) =
       (CONCAT11(*(undefined1 *)(CONCAT31(uVar5,(char)(uVar2 >> 8)) + unaff_EBX),
                 *(undefined1 *)(CONCAT31(uVar5,(char)uVar2) + unaff_EBX)) |
       (ushort)DAT_0088c02c._4_4_) & (ushort)(undefined4)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565d2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565d34
// Address: 00565d34
// XREFS: None
void __fastcall FUN_00565d34(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  uint3 uVar3;
  uint uVar4;
  undefined3 uVar5;
  int unaff_EBX;
  ushort *unaff_EDI;
  
  uVar5 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (CONCAT11(*(undefined1 *)(CONCAT31(uVar5,(char)(*unaff_EDI >> 8)) + unaff_EBX),
                         *(undefined1 *)(CONCAT31(uVar5,(char)*unaff_EDI) + unaff_EBX)) |
               (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
  uVar2 = *(uint *)(unaff_EDI + 1);
  bVar1 = *(byte *)(CONCAT31(uVar5,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar4 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar5,(char)uVar2) + unaff_EBX)) & 0xff |
           ((uint)bVar1 << 0x10) >> 8 |
           (uint)*(byte *)(CONCAT31(uVar5,(char)(uVar2 >> 0x10)) + unaff_EBX) << 0x10 |
          DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar3 = (uint3)((ushort)(uVar4 >> 0x10) & 0xff) | (uint3)uVar4 & 0xff00;
  *(uint *)(unaff_EDI + 1) =
       uVar4 & 0xff | uVar3 & 0xff00 | (uVar3 & 0xff) << 0x10 | uVar2 & 0xff000000;
                    /* WARNING: Could not recover jumptable at 0x00565d81. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565d87
// Address: 00565d87
// XREFS: None
void __fastcall FUN_00565d87(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  undefined3 uVar4;
  int unaff_EBX;
  byte *unaff_EDI;
  
  uVar4 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (*(byte *)(CONCAT31(uVar4,*unaff_EDI) + unaff_EBX) | (byte)(DAT_0088c02c._4_4_ >> 8))
               & (byte)((uint)DAT_0088c02c >> 8);
  uVar2 = *(uint *)(unaff_EDI + 1);
  bVar1 = *(byte *)(CONCAT31(uVar4,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar3 = CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x10)) + unaff_EBX),
                   *(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x18)) + unaff_EBX));
  *(uint *)(unaff_EDI + 1) =
       (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar4,(char)uVar2) + unaff_EBX)) & 0xff |
        ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
       DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565dc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565dcc
// Address: 00565dcc
// XREFS: None
void __fastcall FUN_00565dcc(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  undefined3 uVar4;
  int unaff_EBX;
  uint *unaff_EDI;
  
  uVar2 = *unaff_EDI;
  uVar4 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar4,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar3 = CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x10)) + unaff_EBX),
                   *(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x18)) + unaff_EBX));
  *unaff_EDI = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar4,(char)uVar2) + unaff_EBX)) & 0xff |
                ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
               DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar3 = (ushort)unaff_EDI[1];
  *(ushort *)(unaff_EDI + 1) =
       (CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(uVar3 >> 8)) + unaff_EBX),
                 *(undefined1 *)(CONCAT31(uVar4,(char)uVar3) + unaff_EBX)) |
       (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565e16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565e1c
// Address: 00565e1c
// XREFS: None
void __fastcall FUN_00565e1c(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint3 uVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined3 uVar7;
  int unaff_EBX;
  int unaff_EDI;
  
  uVar2 = *(undefined4 *)(unaff_EDI + -1);
  uVar7 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar7,(char)((uint)uVar2 >> 8)) + unaff_EBX);
  uVar5 = (undefined1)((uint)uVar2 >> 0x18);
  *(uint *)(unaff_EDI + -1) =
       CONCAT31(((uint3)bVar1 |
                 (uint3)((((uint3)(CONCAT12(bVar1,CONCAT11(*(undefined1 *)
                                                            (CONCAT31(uVar7,(char)((uint)uVar2 >>
                                                                                  0x10)) + unaff_EBX
                                                            ),uVar5)) >> 8) & 0xff) << 0x10) >> 8) |
                 (uint3)(((uint)*(byte *)(CONCAT31(uVar7,uVar5) + unaff_EBX) << 0x18) >> 8) |
                (uint3)(DAT_0088c02c._4_4_ >> 8)) & (uint3)((uint)DAT_0088c02c >> 8),(char)uVar2);
  uVar3 = *(uint *)(unaff_EDI + 3);
  bVar1 = *(byte *)(CONCAT31(uVar7,(char)(uVar3 >> 8)) + unaff_EBX);
  uVar6 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar7,(char)uVar3) + unaff_EBX)) & 0xff |
           ((uint)bVar1 << 0x10) >> 8 |
           (uint)*(byte *)(CONCAT31(uVar7,(char)(uVar3 >> 0x10)) + unaff_EBX) << 0x10 |
          DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar4 = (uint3)((ushort)(uVar6 >> 0x10) & 0xff) | (uint3)uVar6 & 0xff00;
  *(uint *)(unaff_EDI + 3) =
       uVar6 & 0xff | uVar4 & 0xff00 | (uVar4 & 0xff) << 0x10 | uVar3 & 0xff000000;
                    /* WARNING: Could not recover jumptable at 0x00565e76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565e7c
// Address: 00565e7c
// XREFS: None
void __fastcall FUN_00565e7c(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  undefined3 uVar4;
  int unaff_EBX;
  ushort *unaff_EDI;
  
  uVar4 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(*unaff_EDI >> 8)) + unaff_EBX),
                         *(undefined1 *)(CONCAT31(uVar4,(char)*unaff_EDI) + unaff_EBX)) |
               (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
  uVar2 = *(uint *)(unaff_EDI + 1);
  bVar1 = *(byte *)(CONCAT31(uVar4,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar3 = CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x10)) + unaff_EBX),
                   *(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x18)) + unaff_EBX));
  *(uint *)(unaff_EDI + 1) =
       (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar4,(char)uVar2) + unaff_EBX)) & 0xff |
        ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
       DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565ec6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565ecc
// Address: 00565ecc
// XREFS: None
void __fastcall FUN_00565ecc(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  undefined3 uVar4;
  int unaff_EBX;
  byte *unaff_EDI;
  
  uVar4 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (*(byte *)(CONCAT31(uVar4,*unaff_EDI) + unaff_EBX) | (byte)(DAT_0088c02c._4_4_ >> 8))
               & (byte)((uint)DAT_0088c02c >> 8);
  uVar2 = *(uint *)(unaff_EDI + 1);
  bVar1 = *(byte *)(CONCAT31(uVar4,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar3 = CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x10)) + unaff_EBX),
                   *(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x18)) + unaff_EBX));
  *(uint *)(unaff_EDI + 1) =
       (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar4,(char)uVar2) + unaff_EBX)) & 0xff |
        ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
       DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  unaff_EDI[5] = (*(byte *)(CONCAT31(uVar4,unaff_EDI[5]) + unaff_EBX) | (byte)DAT_0088c02c._4_4_) &
                 (byte)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565f1f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565f25
// Address: 00565f25
// XREFS: None
void __fastcall FUN_00565f25(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  uint3 uVar3;
  ushort uVar4;
  uint uVar5;
  undefined3 uVar6;
  int unaff_EBX;
  uint *unaff_EDI;
  
  uVar2 = *unaff_EDI;
  uVar6 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar6,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar4 = CONCAT11(*(undefined1 *)(CONCAT31(uVar6,(char)(uVar2 >> 0x10)) + unaff_EBX),
                   *(undefined1 *)(CONCAT31(uVar6,(char)(uVar2 >> 0x18)) + unaff_EBX));
  *unaff_EDI = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar6,(char)uVar2) + unaff_EBX)) & 0xff |
                ((uint)bVar1 << 0x10) >> 8 | (uVar4 & 0xff00) << 8 | (uint)uVar4 << 0x18 |
               DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar2 = unaff_EDI[1];
  bVar1 = *(byte *)(CONCAT31(uVar6,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar5 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar6,(char)uVar2) + unaff_EBX)) & 0xff |
           ((uint)bVar1 << 0x10) >> 8 |
           (uint)*(byte *)(CONCAT31(uVar6,(char)(uVar2 >> 0x10)) + unaff_EBX) << 0x10 |
          DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar3 = (uint3)((ushort)(uVar5 >> 0x10) & 0xff) | (uint3)uVar5 & 0xff00;
  unaff_EDI[1] = uVar5 & 0xff | uVar3 & 0xff00 | (uVar3 & 0xff) << 0x10 | uVar2 & 0xff000000;
                    /* WARNING: Could not recover jumptable at 0x00565f7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565f84
// Address: 00565f84
// XREFS: None
void __fastcall FUN_00565f84(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 uVar4;
  ushort uVar5;
  undefined3 uVar6;
  int unaff_EBX;
  int unaff_EDI;
  
  uVar2 = *(undefined4 *)(unaff_EDI + -1);
  uVar6 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar6,(char)((uint)uVar2 >> 8)) + unaff_EBX);
  uVar4 = (undefined1)((uint)uVar2 >> 0x18);
  *(uint *)(unaff_EDI + -1) =
       CONCAT31(((uint3)bVar1 |
                 (uint3)((((uint3)(CONCAT12(bVar1,CONCAT11(*(undefined1 *)
                                                            (CONCAT31(uVar6,(char)((uint)uVar2 >>
                                                                                  0x10)) + unaff_EBX
                                                            ),uVar4)) >> 8) & 0xff) << 0x10) >> 8) |
                 (uint3)(((uint)*(byte *)(CONCAT31(uVar6,uVar4) + unaff_EBX) << 0x18) >> 8) |
                (uint3)(DAT_0088c02c._4_4_ >> 8)) & (uint3)((uint)DAT_0088c02c >> 8),(char)uVar2);
  uVar3 = *(uint *)(unaff_EDI + 3);
  bVar1 = *(byte *)(CONCAT31(uVar6,(char)(uVar3 >> 8)) + unaff_EBX);
  uVar5 = CONCAT11(*(undefined1 *)(CONCAT31(uVar6,(char)(uVar3 >> 0x10)) + unaff_EBX),
                   *(undefined1 *)(CONCAT31(uVar6,(char)(uVar3 >> 0x18)) + unaff_EBX));
  *(uint *)(unaff_EDI + 3) =
       (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar6,(char)uVar3) + unaff_EBX)) & 0xff |
        ((uint)bVar1 << 0x10) >> 8 | (uVar5 & 0xff00) << 8 | (uint)uVar5 << 0x18 |
       DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00565fdb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00565fe1
// Address: 00565fe1
// XREFS: None
void __fastcall FUN_00565fe1(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  undefined3 uVar4;
  int unaff_EBX;
  ushort *unaff_EDI;
  
  uVar4 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(*unaff_EDI >> 8)) + unaff_EBX),
                         *(undefined1 *)(CONCAT31(uVar4,(char)*unaff_EDI) + unaff_EBX)) |
               (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
  uVar2 = *(uint *)(unaff_EDI + 1);
  bVar1 = *(byte *)(CONCAT31(uVar4,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar3 = CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x10)) + unaff_EBX),
                   *(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x18)) + unaff_EBX));
  *(uint *)(unaff_EDI + 1) =
       (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar4,(char)uVar2) + unaff_EBX)) & 0xff |
        ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
       DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  *(byte *)(unaff_EDI + 3) =
       (*(byte *)(CONCAT31(uVar4,(byte)unaff_EDI[3]) + unaff_EBX) | (byte)DAT_0088c02c._4_4_) &
       (byte)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x0056603f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566045
// Address: 00566045
// XREFS: None
void __fastcall FUN_00566045(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  undefined3 uVar4;
  int unaff_EBX;
  byte *unaff_EDI;
  
  uVar4 = (undefined3)((uint)param_2 >> 8);
  *unaff_EDI = (*(byte *)(CONCAT31(uVar4,*unaff_EDI) + unaff_EBX) | (byte)(DAT_0088c02c._4_4_ >> 8))
               & (byte)((uint)DAT_0088c02c >> 8);
  uVar2 = *(uint *)(unaff_EDI + 1);
  bVar1 = *(byte *)(CONCAT31(uVar4,(char)(uVar2 >> 8)) + unaff_EBX);
  uVar3 = CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x10)) + unaff_EBX),
                   *(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x18)) + unaff_EBX));
  *(uint *)(unaff_EDI + 1) =
       (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar4,(char)uVar2) + unaff_EBX)) & 0xff |
        ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
       DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar3 = *(ushort *)(unaff_EDI + 5);
  *(ushort *)(unaff_EDI + 5) =
       (CONCAT11(*(undefined1 *)(CONCAT31(uVar4,(char)(uVar3 >> 8)) + unaff_EBX),
                 *(undefined1 *)(CONCAT31(uVar4,(char)uVar3) + unaff_EBX)) |
       (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x005660a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005660a9
// Address: 005660a9
// XREFS: FUN_005660a9
void __fastcall FUN_005660a9(uint param_1,int param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  undefined3 uVar4;
  int unaff_EBX;
  uint *unaff_EDI;
  bool bVar5;
  
  do {
    uVar2 = *unaff_EDI;
    uVar4 = (undefined3)((uint)param_2 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar4,(char)(uVar2 >> 8)) + unaff_EBX);
    param_2 = CONCAT31(uVar4,(char)(uVar2 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(param_2 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar4,(char)(uVar2 >> 0x18)) + unaff_EBX));
    *unaff_EDI = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar4,(char)uVar2) + unaff_EBX)) & 0xff |
                  ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
                 DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    unaff_EDI = unaff_EDI + 1;
    bVar5 = 3 < param_1;
    param_1 = param_1 - 4;
  } while (bVar5 && param_1 != 0);
                    /* WARNING: Could not recover jumptable at 0x005660d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005660df
// Address: 005660df
// XREFS: None
void __fastcall FUN_005660df(int param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined3 uVar6;
  int unaff_EBX;
  byte *unaff_EDI;
  uint *puVar7;
  bool bVar8;
  
  iVar5 = CONCAT31((int3)((uint)param_2 >> 8),*unaff_EDI);
  *unaff_EDI = (*(byte *)(iVar5 + unaff_EBX) | (byte)(DAT_0088c02c._4_4_ >> 8)) &
               (byte)((uint)DAT_0088c02c >> 8);
  puVar7 = (uint *)(unaff_EDI + 1);
  uVar4 = param_1 - 1;
  do {
    uVar2 = *puVar7;
    uVar6 = (undefined3)((uint)iVar5 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar6,(char)(uVar2 >> 8)) + unaff_EBX);
    iVar5 = CONCAT31(uVar6,(char)(uVar2 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(iVar5 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar6,(char)(uVar2 >> 0x18)) + unaff_EBX));
    *puVar7 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar6,(char)uVar2) + unaff_EBX)) & 0xff |
               ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
              DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar7 = puVar7 + 1;
    bVar8 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar8 && uVar4 != 0);
                    /* WARNING: Could not recover jumptable at 0x00566124. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056612a
// Address: 0056612a
// XREFS: None
void __fastcall FUN_0056612a(int param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  undefined3 uVar6;
  int iVar5;
  int unaff_EBX;
  ushort *unaff_EDI;
  uint *puVar7;
  bool bVar8;
  
  uVar6 = (undefined3)((uint)param_2 >> 8);
  iVar5 = CONCAT31(uVar6,(char)(*unaff_EDI >> 8));
  *unaff_EDI = (CONCAT11(*(undefined1 *)(iVar5 + unaff_EBX),
                         *(undefined1 *)(CONCAT31(uVar6,(char)*unaff_EDI) + unaff_EBX)) |
               (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
  puVar7 = (uint *)(unaff_EDI + 1);
  uVar4 = param_1 - 2;
  do {
    uVar2 = *puVar7;
    uVar6 = (undefined3)((uint)iVar5 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar6,(char)(uVar2 >> 8)) + unaff_EBX);
    iVar5 = CONCAT31(uVar6,(char)(uVar2 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(iVar5 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar6,(char)(uVar2 >> 0x18)) + unaff_EBX));
    *puVar7 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar6,(char)uVar2) + unaff_EBX)) & 0xff |
               ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
              DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar7 = puVar7 + 1;
    bVar8 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar8 && uVar4 != 0);
                    /* WARNING: Could not recover jumptable at 0x0056617c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566182
// Address: 00566182
// XREFS: None
void __fastcall FUN_00566182(int param_1,undefined4 param_2)
{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 uVar4;
  ushort uVar5;
  uint uVar6;
  undefined3 uVar8;
  int iVar7;
  int unaff_EBX;
  int unaff_EDI;
  uint *puVar9;
  bool bVar10;
  
  uVar2 = *(undefined4 *)(unaff_EDI + -1);
  uVar8 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar8,(char)((uint)uVar2 >> 8)) + unaff_EBX);
  uVar4 = (undefined1)((uint)uVar2 >> 0x18);
  iVar7 = CONCAT31(uVar8,(char)uVar2);
  *(uint *)(unaff_EDI + -1) =
       CONCAT31(((uint3)bVar1 |
                 (uint3)((((uint3)(CONCAT12(bVar1,CONCAT11(*(undefined1 *)
                                                            (CONCAT31(uVar8,(char)((uint)uVar2 >>
                                                                                  0x10)) + unaff_EBX
                                                            ),uVar4)) >> 8) & 0xff) << 0x10) >> 8) |
                 (uint3)(((uint)*(byte *)(CONCAT31(uVar8,uVar4) + unaff_EBX) << 0x18) >> 8) |
                (uint3)(DAT_0088c02c._4_4_ >> 8)) & (uint3)((uint)DAT_0088c02c >> 8),(char)uVar2);
  puVar9 = (uint *)(unaff_EDI + 3);
  uVar6 = param_1 - 3;
  do {
    uVar3 = *puVar9;
    uVar8 = (undefined3)((uint)iVar7 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar8,(char)(uVar3 >> 8)) + unaff_EBX);
    iVar7 = CONCAT31(uVar8,(char)(uVar3 >> 0x10));
    uVar5 = CONCAT11(*(undefined1 *)(iVar7 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar8,(char)(uVar3 >> 0x18)) + unaff_EBX));
    *puVar9 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar8,(char)uVar3) + unaff_EBX)) & 0xff |
               ((uint)bVar1 << 0x10) >> 8 | (uVar5 & 0xff00) << 8 | (uint)uVar5 << 0x18 |
              DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar9 = puVar9 + 1;
    bVar10 = 3 < uVar6;
    uVar6 = uVar6 - 4;
  } while (bVar10 && uVar6 != 0);
                    /* WARNING: Could not recover jumptable at 0x005661e1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005661e7
// Address: 005661e7
// XREFS: None
void __fastcall FUN_005661e7(int param_1,int param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  undefined3 uVar5;
  int unaff_EBX;
  uint *unaff_EDI;
  bool bVar6;
  
  uVar4 = param_1 - 1;
  do {
    uVar2 = *unaff_EDI;
    uVar5 = (undefined3)((uint)param_2 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar5,(char)(uVar2 >> 8)) + unaff_EBX);
    param_2 = CONCAT31(uVar5,(char)(uVar2 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(param_2 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar5,(char)(uVar2 >> 0x18)) + unaff_EBX));
    *unaff_EDI = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar5,(char)uVar2) + unaff_EBX)) & 0xff |
                  ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
                 DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    unaff_EDI = unaff_EDI + 1;
    bVar6 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar6 && uVar4 != 0);
  *(byte *)unaff_EDI =
       (*(byte *)(CONCAT31(uVar5,(byte)*unaff_EDI) + unaff_EBX) | (byte)DAT_0088c02c._4_4_) &
       (byte)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x0056622c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566232
// Address: 00566232
// XREFS: None
void __fastcall FUN_00566232(int param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined3 uVar6;
  int unaff_EBX;
  byte *unaff_EDI;
  uint *puVar7;
  bool bVar8;
  
  iVar5 = CONCAT31((int3)((uint)param_2 >> 8),*unaff_EDI);
  *unaff_EDI = (*(byte *)(iVar5 + unaff_EBX) | (byte)(DAT_0088c02c._4_4_ >> 8)) &
               (byte)((uint)DAT_0088c02c >> 8);
  puVar7 = (uint *)(unaff_EDI + 1);
  uVar4 = param_1 - 2;
  do {
    uVar2 = *puVar7;
    uVar6 = (undefined3)((uint)iVar5 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar6,(char)(uVar2 >> 8)) + unaff_EBX);
    iVar5 = CONCAT31(uVar6,(char)(uVar2 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(iVar5 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar6,(char)(uVar2 >> 0x18)) + unaff_EBX));
    *puVar7 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar6,(char)uVar2) + unaff_EBX)) & 0xff |
               ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
              DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar7 = puVar7 + 1;
    bVar8 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar8 && uVar4 != 0);
  *(byte *)puVar7 =
       (*(byte *)(CONCAT31(uVar6,(byte)*puVar7) + unaff_EBX) | (byte)DAT_0088c02c._4_4_) &
       (byte)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x0056628d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566293
// Address: 00566293
// XREFS: None
void __fastcall FUN_00566293(int param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  undefined3 uVar6;
  int iVar5;
  int unaff_EBX;
  ushort *unaff_EDI;
  uint *puVar7;
  bool bVar8;
  
  uVar6 = (undefined3)((uint)param_2 >> 8);
  iVar5 = CONCAT31(uVar6,(char)(*unaff_EDI >> 8));
  *unaff_EDI = (CONCAT11(*(undefined1 *)(iVar5 + unaff_EBX),
                         *(undefined1 *)(CONCAT31(uVar6,(char)*unaff_EDI) + unaff_EBX)) |
               (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
  puVar7 = (uint *)(unaff_EDI + 1);
  uVar4 = param_1 - 3;
  do {
    uVar2 = *puVar7;
    uVar6 = (undefined3)((uint)iVar5 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar6,(char)(uVar2 >> 8)) + unaff_EBX);
    iVar5 = CONCAT31(uVar6,(char)(uVar2 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(iVar5 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar6,(char)(uVar2 >> 0x18)) + unaff_EBX));
    *puVar7 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar6,(char)uVar2) + unaff_EBX)) & 0xff |
               ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
              DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar7 = puVar7 + 1;
    bVar8 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar8 && uVar4 != 0);
  *(byte *)puVar7 =
       (*(byte *)(CONCAT31(uVar6,(byte)*puVar7) + unaff_EBX) | (byte)DAT_0088c02c._4_4_) &
       (byte)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x005662f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005662ff
// Address: 005662ff
// XREFS: None
void __fastcall FUN_005662ff(int param_1,undefined4 param_2)
{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 uVar4;
  ushort uVar5;
  uint uVar6;
  undefined3 uVar8;
  int iVar7;
  int unaff_EBX;
  int unaff_EDI;
  uint *puVar9;
  bool bVar10;
  
  uVar2 = *(undefined4 *)(unaff_EDI + -1);
  uVar8 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar8,(char)((uint)uVar2 >> 8)) + unaff_EBX);
  uVar4 = (undefined1)((uint)uVar2 >> 0x18);
  iVar7 = CONCAT31(uVar8,(char)uVar2);
  *(uint *)(unaff_EDI + -1) =
       CONCAT31(((uint3)bVar1 |
                 (uint3)((((uint3)(CONCAT12(bVar1,CONCAT11(*(undefined1 *)
                                                            (CONCAT31(uVar8,(char)((uint)uVar2 >>
                                                                                  0x10)) + unaff_EBX
                                                            ),uVar4)) >> 8) & 0xff) << 0x10) >> 8) |
                 (uint3)(((uint)*(byte *)(CONCAT31(uVar8,uVar4) + unaff_EBX) << 0x18) >> 8) |
                (uint3)(DAT_0088c02c._4_4_ >> 8)) & (uint3)((uint)DAT_0088c02c >> 8),(char)uVar2);
  puVar9 = (uint *)(unaff_EDI + 3);
  uVar6 = param_1 - 4;
  do {
    uVar3 = *puVar9;
    uVar8 = (undefined3)((uint)iVar7 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar8,(char)(uVar3 >> 8)) + unaff_EBX);
    iVar7 = CONCAT31(uVar8,(char)(uVar3 >> 0x10));
    uVar5 = CONCAT11(*(undefined1 *)(iVar7 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar8,(char)(uVar3 >> 0x18)) + unaff_EBX));
    *puVar9 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar8,(char)uVar3) + unaff_EBX)) & 0xff |
               ((uint)bVar1 << 0x10) >> 8 | (uVar5 & 0xff00) << 8 | (uint)uVar5 << 0x18 |
              DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar9 = puVar9 + 1;
    bVar10 = 3 < uVar6;
    uVar6 = uVar6 - 4;
  } while (bVar10 && uVar6 != 0);
  *(byte *)puVar9 =
       (*(byte *)(CONCAT31(uVar8,(byte)*puVar9) + unaff_EBX) | (byte)DAT_0088c02c._4_4_) &
       (byte)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00566372. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566378
// Address: 00566378
// XREFS: None
void __fastcall FUN_00566378(int param_1,int param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  undefined3 uVar5;
  int unaff_EBX;
  uint *unaff_EDI;
  bool bVar6;
  
  uVar4 = param_1 - 2;
  do {
    uVar2 = *unaff_EDI;
    uVar5 = (undefined3)((uint)param_2 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar5,(char)(uVar2 >> 8)) + unaff_EBX);
    param_2 = CONCAT31(uVar5,(char)(uVar2 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(param_2 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar5,(char)(uVar2 >> 0x18)) + unaff_EBX));
    *unaff_EDI = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar5,(char)uVar2) + unaff_EBX)) & 0xff |
                  ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
                 DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    unaff_EDI = unaff_EDI + 1;
    bVar6 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar6 && uVar4 != 0);
  *(ushort *)unaff_EDI =
       (CONCAT11(*(undefined1 *)(CONCAT31(uVar5,(char)((ushort)*unaff_EDI >> 8)) + unaff_EBX),
                 *(undefined1 *)(CONCAT31(uVar5,(char)(ushort)*unaff_EDI) + unaff_EBX)) |
       (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x005663ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005663d0
// Address: 005663d0
// XREFS: None
void __fastcall FUN_005663d0(int param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined3 uVar6;
  int unaff_EBX;
  byte *unaff_EDI;
  uint *puVar7;
  bool bVar8;
  
  iVar5 = CONCAT31((int3)((uint)param_2 >> 8),*unaff_EDI);
  *unaff_EDI = (*(byte *)(iVar5 + unaff_EBX) | (byte)(DAT_0088c02c._4_4_ >> 8)) &
               (byte)((uint)DAT_0088c02c >> 8);
  puVar7 = (uint *)(unaff_EDI + 1);
  uVar4 = param_1 - 3;
  do {
    uVar2 = *puVar7;
    uVar6 = (undefined3)((uint)iVar5 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar6,(char)(uVar2 >> 8)) + unaff_EBX);
    iVar5 = CONCAT31(uVar6,(char)(uVar2 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(iVar5 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar6,(char)(uVar2 >> 0x18)) + unaff_EBX));
    *puVar7 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar6,(char)uVar2) + unaff_EBX)) & 0xff |
               ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
              DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar7 = puVar7 + 1;
    bVar8 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar8 && uVar4 != 0);
  *(ushort *)puVar7 =
       (CONCAT11(*(undefined1 *)(CONCAT31(uVar6,(char)((ushort)*puVar7 >> 8)) + unaff_EBX),
                 *(undefined1 *)(CONCAT31(uVar6,(char)(ushort)*puVar7) + unaff_EBX)) |
       (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00566436. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056643c
// Address: 0056643c
// XREFS: None
void __fastcall FUN_0056643c(int param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  undefined3 uVar6;
  int iVar5;
  int unaff_EBX;
  ushort *unaff_EDI;
  uint *puVar7;
  bool bVar8;
  
  uVar6 = (undefined3)((uint)param_2 >> 8);
  iVar5 = CONCAT31(uVar6,(char)(*unaff_EDI >> 8));
  *unaff_EDI = (CONCAT11(*(undefined1 *)(iVar5 + unaff_EBX),
                         *(undefined1 *)(CONCAT31(uVar6,(char)*unaff_EDI) + unaff_EBX)) |
               (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
  puVar7 = (uint *)(unaff_EDI + 1);
  uVar4 = param_1 - 4;
  do {
    uVar2 = *puVar7;
    uVar6 = (undefined3)((uint)iVar5 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar6,(char)(uVar2 >> 8)) + unaff_EBX);
    iVar5 = CONCAT31(uVar6,(char)(uVar2 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(iVar5 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar6,(char)(uVar2 >> 0x18)) + unaff_EBX));
    *puVar7 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar6,(char)uVar2) + unaff_EBX)) & 0xff |
               ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
              DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar7 = puVar7 + 1;
    bVar8 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar8 && uVar4 != 0);
  *(ushort *)puVar7 =
       (CONCAT11(*(undefined1 *)(CONCAT31(uVar6,(char)((ushort)*puVar7 >> 8)) + unaff_EBX),
                 *(undefined1 *)(CONCAT31(uVar6,(char)(ushort)*puVar7) + unaff_EBX)) |
       (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x005664ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005664b3
// Address: 005664b3
// XREFS: None
void __fastcall FUN_005664b3(int param_1,undefined4 param_2)
{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 uVar4;
  ushort uVar5;
  uint uVar6;
  undefined3 uVar8;
  int iVar7;
  int unaff_EBX;
  int unaff_EDI;
  uint *puVar9;
  bool bVar10;
  
  uVar2 = *(undefined4 *)(unaff_EDI + -1);
  uVar8 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar8,(char)((uint)uVar2 >> 8)) + unaff_EBX);
  uVar4 = (undefined1)((uint)uVar2 >> 0x18);
  iVar7 = CONCAT31(uVar8,(char)uVar2);
  *(uint *)(unaff_EDI + -1) =
       CONCAT31(((uint3)bVar1 |
                 (uint3)((((uint3)(CONCAT12(bVar1,CONCAT11(*(undefined1 *)
                                                            (CONCAT31(uVar8,(char)((uint)uVar2 >>
                                                                                  0x10)) + unaff_EBX
                                                            ),uVar4)) >> 8) & 0xff) << 0x10) >> 8) |
                 (uint3)(((uint)*(byte *)(CONCAT31(uVar8,uVar4) + unaff_EBX) << 0x18) >> 8) |
                (uint3)(DAT_0088c02c._4_4_ >> 8)) & (uint3)((uint)DAT_0088c02c >> 8),(char)uVar2);
  puVar9 = (uint *)(unaff_EDI + 3);
  uVar6 = param_1 - 5;
  do {
    uVar3 = *puVar9;
    uVar8 = (undefined3)((uint)iVar7 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar8,(char)(uVar3 >> 8)) + unaff_EBX);
    iVar7 = CONCAT31(uVar8,(char)(uVar3 >> 0x10));
    uVar5 = CONCAT11(*(undefined1 *)(iVar7 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar8,(char)(uVar3 >> 0x18)) + unaff_EBX));
    *puVar9 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar8,(char)uVar3) + unaff_EBX)) & 0xff |
               ((uint)bVar1 << 0x10) >> 8 | (uVar5 & 0xff00) << 8 | (uint)uVar5 << 0x18 |
              DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar9 = puVar9 + 1;
    bVar10 = 3 < uVar6;
    uVar6 = uVar6 - 4;
  } while (bVar10 && uVar6 != 0);
  *(ushort *)puVar9 =
       (CONCAT11(*(undefined1 *)(CONCAT31(uVar8,(char)((ushort)*puVar9 >> 8)) + unaff_EBX),
                 *(undefined1 *)(CONCAT31(uVar8,(char)(ushort)*puVar9) + unaff_EBX)) |
       (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
                    /* WARNING: Could not recover jumptable at 0x00566531. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566537
// Address: 00566537
// XREFS: None
void __fastcall FUN_00566537(int param_1,int param_2)
{
  byte bVar1;
  uint3 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  undefined3 uVar6;
  int unaff_EBX;
  uint *unaff_EDI;
  bool bVar7;
  
  uVar5 = param_1 - 3;
  do {
    uVar4 = *unaff_EDI;
    uVar6 = (undefined3)((uint)param_2 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar6,(char)(uVar4 >> 8)) + unaff_EBX);
    param_2 = CONCAT31(uVar6,(char)(uVar4 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(param_2 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar6,(char)(uVar4 >> 0x18)) + unaff_EBX));
    *unaff_EDI = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar6,(char)uVar4) + unaff_EBX)) & 0xff |
                  ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
                 DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    unaff_EDI = unaff_EDI + 1;
    bVar7 = 3 < uVar5;
    uVar5 = uVar5 - 4;
  } while (bVar7 && uVar5 != 0);
  uVar5 = *unaff_EDI;
  bVar1 = *(byte *)(CONCAT31(uVar6,(char)(uVar5 >> 8)) + unaff_EBX);
  uVar4 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar6,(char)uVar5) + unaff_EBX)) & 0xff |
           ((uint)bVar1 << 0x10) >> 8 |
           (uint)*(byte *)(CONCAT31(uVar6,(char)(uVar5 >> 0x10)) + unaff_EBX) << 0x10 |
          DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar2 = (uint3)((ushort)(uVar4 >> 0x10) & 0xff) | (uint3)uVar4 & 0xff00;
  *unaff_EDI = uVar4 & 0xff | uVar2 & 0xff00 | (uVar2 & 0xff) << 0x10 | uVar5 & 0xff000000;
                    /* WARNING: Could not recover jumptable at 0x00566598. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056659e
// Address: 0056659e
// XREFS: None
void __fastcall FUN_0056659e(int param_1,undefined4 param_2)
{
  byte bVar1;
  uint3 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined3 uVar7;
  int unaff_EBX;
  byte *unaff_EDI;
  uint *puVar8;
  bool bVar9;
  
  iVar6 = CONCAT31((int3)((uint)param_2 >> 8),*unaff_EDI);
  *unaff_EDI = (*(byte *)(iVar6 + unaff_EBX) | (byte)(DAT_0088c02c._4_4_ >> 8)) &
               (byte)((uint)DAT_0088c02c >> 8);
  puVar8 = (uint *)(unaff_EDI + 1);
  uVar5 = param_1 - 4;
  do {
    uVar4 = *puVar8;
    uVar7 = (undefined3)((uint)iVar6 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar7,(char)(uVar4 >> 8)) + unaff_EBX);
    iVar6 = CONCAT31(uVar7,(char)(uVar4 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(iVar6 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar7,(char)(uVar4 >> 0x18)) + unaff_EBX));
    *puVar8 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar7,(char)uVar4) + unaff_EBX)) & 0xff |
               ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
              DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar8 = puVar8 + 1;
    bVar9 = 3 < uVar5;
    uVar5 = uVar5 - 4;
  } while (bVar9 && uVar5 != 0);
  uVar5 = *puVar8;
  bVar1 = *(byte *)(CONCAT31(uVar7,(char)(uVar5 >> 8)) + unaff_EBX);
  uVar4 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar7,(char)uVar5) + unaff_EBX)) & 0xff |
           ((uint)bVar1 << 0x10) >> 8 |
           (uint)*(byte *)(CONCAT31(uVar7,(char)(uVar5 >> 0x10)) + unaff_EBX) << 0x10 |
          DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar2 = (uint3)((ushort)(uVar4 >> 0x10) & 0xff) | (uint3)uVar4 & 0xff00;
  *puVar8 = uVar4 & 0xff | uVar2 & 0xff00 | (uVar2 & 0xff) << 0x10 | uVar5 & 0xff000000;
                    /* WARNING: Could not recover jumptable at 0x00566613. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566619
// Address: 00566619
// XREFS: None
void __fastcall FUN_00566619(int param_1,undefined4 param_2)
{
  byte bVar1;
  uint3 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  undefined3 uVar7;
  int iVar6;
  int unaff_EBX;
  ushort *unaff_EDI;
  uint *puVar8;
  bool bVar9;
  
  uVar7 = (undefined3)((uint)param_2 >> 8);
  iVar6 = CONCAT31(uVar7,(char)(*unaff_EDI >> 8));
  *unaff_EDI = (CONCAT11(*(undefined1 *)(iVar6 + unaff_EBX),
                         *(undefined1 *)(CONCAT31(uVar7,(char)*unaff_EDI) + unaff_EBX)) |
               (ushort)DAT_0088c02c._4_4_) & (ushort)(uint)DAT_0088c02c;
  puVar8 = (uint *)(unaff_EDI + 1);
  uVar5 = param_1 - 5;
  do {
    uVar4 = *puVar8;
    uVar7 = (undefined3)((uint)iVar6 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar7,(char)(uVar4 >> 8)) + unaff_EBX);
    iVar6 = CONCAT31(uVar7,(char)(uVar4 >> 0x10));
    uVar3 = CONCAT11(*(undefined1 *)(iVar6 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar7,(char)(uVar4 >> 0x18)) + unaff_EBX));
    *puVar8 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar7,(char)uVar4) + unaff_EBX)) & 0xff |
               ((uint)bVar1 << 0x10) >> 8 | (uVar3 & 0xff00) << 8 | (uint)uVar3 << 0x18 |
              DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar8 = puVar8 + 1;
    bVar9 = 3 < uVar5;
    uVar5 = uVar5 - 4;
  } while (bVar9 && uVar5 != 0);
  uVar5 = *puVar8;
  bVar1 = *(byte *)(CONCAT31(uVar7,(char)(uVar5 >> 8)) + unaff_EBX);
  uVar4 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar7,(char)uVar5) + unaff_EBX)) & 0xff |
           ((uint)bVar1 << 0x10) >> 8 |
           (uint)*(byte *)(CONCAT31(uVar7,(char)(uVar5 >> 0x10)) + unaff_EBX) << 0x10 |
          DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar2 = (uint3)((ushort)(uVar4 >> 0x10) & 0xff) | (uint3)uVar4 & 0xff00;
  *puVar8 = uVar4 & 0xff | uVar2 & 0xff00 | (uVar2 & 0xff) << 0x10 | uVar5 & 0xff000000;
                    /* WARNING: Could not recover jumptable at 0x00566699. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056669f
// Address: 0056669f
// XREFS: None
void __fastcall FUN_0056669f(int param_1,undefined4 param_2)
{
  byte bVar1;
  undefined4 uVar2;
  uint3 uVar3;
  undefined1 uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  undefined3 uVar9;
  int iVar8;
  int unaff_EBX;
  int unaff_EDI;
  uint *puVar10;
  bool bVar11;
  
  uVar2 = *(undefined4 *)(unaff_EDI + -1);
  uVar9 = (undefined3)((uint)param_2 >> 8);
  bVar1 = *(byte *)(CONCAT31(uVar9,(char)((uint)uVar2 >> 8)) + unaff_EBX);
  uVar4 = (undefined1)((uint)uVar2 >> 0x18);
  iVar8 = CONCAT31(uVar9,(char)uVar2);
  *(uint *)(unaff_EDI + -1) =
       CONCAT31(((uint3)bVar1 |
                 (uint3)((((uint3)(CONCAT12(bVar1,CONCAT11(*(undefined1 *)
                                                            (CONCAT31(uVar9,(char)((uint)uVar2 >>
                                                                                  0x10)) + unaff_EBX
                                                            ),uVar4)) >> 8) & 0xff) << 0x10) >> 8) |
                 (uint3)(((uint)*(byte *)(CONCAT31(uVar9,uVar4) + unaff_EBX) << 0x18) >> 8) |
                (uint3)(DAT_0088c02c._4_4_ >> 8)) & (uint3)((uint)DAT_0088c02c >> 8),(char)uVar2);
  puVar10 = (uint *)(unaff_EDI + 3);
  uVar7 = param_1 - 6;
  do {
    uVar6 = *puVar10;
    uVar9 = (undefined3)((uint)iVar8 >> 8);
    bVar1 = *(byte *)(CONCAT31(uVar9,(char)(uVar6 >> 8)) + unaff_EBX);
    iVar8 = CONCAT31(uVar9,(char)(uVar6 >> 0x10));
    uVar5 = CONCAT11(*(undefined1 *)(iVar8 + unaff_EBX),
                     *(undefined1 *)(CONCAT31(uVar9,(char)(uVar6 >> 0x18)) + unaff_EBX));
    *puVar10 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar9,(char)uVar6) + unaff_EBX)) & 0xff |
                ((uint)bVar1 << 0x10) >> 8 | (uVar5 & 0xff00) << 8 | (uint)uVar5 << 0x18 |
               DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
    puVar10 = puVar10 + 1;
    bVar11 = 3 < uVar7;
    uVar7 = uVar7 - 4;
  } while (bVar11 && uVar7 != 0);
  uVar7 = *puVar10;
  bVar1 = *(byte *)(CONCAT31(uVar9,(char)(uVar7 >> 8)) + unaff_EBX);
  uVar6 = (CONCAT11(bVar1,*(undefined1 *)(CONCAT31(uVar9,(char)uVar7) + unaff_EBX)) & 0xff |
           ((uint)bVar1 << 0x10) >> 8 |
           (uint)*(byte *)(CONCAT31(uVar9,(char)(uVar7 >> 0x10)) + unaff_EBX) << 0x10 |
          DAT_0088c02c._4_4_) & (uint)DAT_0088c02c;
  uVar3 = (uint3)((ushort)(uVar6 >> 0x10) & 0xff) | (uint3)uVar6 & 0xff00;
  *puVar10 = uVar6 & 0xff | uVar3 & 0xff00 | (uVar3 & 0xff) << 0x10 | uVar7 & 0xff000000;
                    /* WARNING: Could not recover jumptable at 0x0056672c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566732
// Address: 00566732
// XREFS: None
void FUN_00566732(void)
{
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI;
                    /* WARNING: Could not recover jumptable at 0x00566738. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056673e
// Address: 0056673e
// XREFS: None
void FUN_0056673e(void)
{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[2] = (char)((uint)uVar1 >> 8);
                    /* WARNING: Could not recover jumptable at 0x0056674b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566751
// Address: 00566751
// XREFS: None
void FUN_00566751(void)
{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[2] = (char)((uint)uVar1 >> 8);
  unaff_EDI[4] = (char)((uint)uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00566764. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056676a
// Address: 0056676a
// XREFS: None
void FUN_0056676a(void)
{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[2] = (char)((uint)uVar1 >> 8);
  unaff_EDI[4] = (char)((uint)uVar1 >> 0x10);
  unaff_EDI[6] = (char)((uint)uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00566780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566786
// Address: 00566786
// XREFS: None
void FUN_00566786(void)
{
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI;
                    /* WARNING: Could not recover jumptable at 0x0056678c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566792
// Address: 00566792
// XREFS: None
void FUN_00566792(void)
{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
                    /* WARNING: Could not recover jumptable at 0x0056679f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005667a5
// Address: 005667a5
// XREFS: None
void FUN_005667a5(void)
{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  unaff_EDI[-2] = (char)((uint)uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x005667b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005667be
// Address: 005667be
// XREFS: None
void FUN_005667be(void)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *(uint *)(unaff_EDI + -3) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
                    /* WARNING: Could not recover jumptable at 0x005667cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005667d1
// Address: 005667d1
// XREFS: None
void FUN_005667d1(void)
{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  unaff_EDI[-2] = (char)((uint)uVar1 >> 0x10);
  unaff_EDI[-3] = (char)((uint)uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x005667e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005667ed
// Address: 005667ed
// XREFS: None
void FUN_005667ed(void)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  uVar2 = unaff_ESI[1];
  *(uint *)(unaff_EDI + -3) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  *(char *)(unaff_EDI + -4) = (char)uVar2;
                    /* WARNING: Could not recover jumptable at 0x00566800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566806
// Address: 00566806
// XREFS: None
void FUN_00566806(void)
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar2 = *unaff_ESI;
  uVar1 = *(undefined1 *)(unaff_ESI + 1);
  *unaff_EDI = (char)uVar2;
  unaff_EDI[-4] = uVar1;
  unaff_EDI[-1] = (char)((uint)uVar2 >> 8);
  unaff_EDI[-2] = (char)((uint)uVar2 >> 0x10);
  unaff_EDI[-3] = (char)((uint)uVar2 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00566822. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566828
// Address: 00566828
// XREFS: None
void FUN_00566828(void)
{
  uint uVar1;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + 1);
  *unaff_EDI = *unaff_ESI;
  *(uint *)(unaff_EDI + -4) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
                    /* WARNING: Could not recover jumptable at 0x0056683a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566840
// Address: 00566840
// XREFS: None
void FUN_00566840(void)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  uVar2 = unaff_ESI[1];
  *(uint *)(unaff_EDI + -3) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  *(char *)(unaff_EDI + -4) = (char)uVar2;
  *(char *)(unaff_EDI + -5) = (char)(uVar2 >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566856. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056685c
// Address: 0056685c
// XREFS: None
void FUN_0056685c(void)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI;
  uVar2 = unaff_ESI[1];
  unaff_EDI[-5] = (char)((uint)uVar2 >> 8);
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  unaff_EDI[-4] = (char)uVar2;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-2] = (char)((uint)uVar1 >> 0x10);
  unaff_EDI[-3] = (char)((uint)uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x0056687b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566881
// Address: 00566881
// XREFS: None
void FUN_00566881(void)
{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI;
  uVar2 = *(uint *)((int)unaff_ESI + 2);
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  *(uint *)(unaff_EDI + -5) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
                    /* WARNING: Could not recover jumptable at 0x00566896. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056689c
// Address: 0056689c
// XREFS: None
void FUN_0056689c(void)
{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = unaff_ESI[5];
  uVar2 = *(uint *)(unaff_ESI + 1);
  *unaff_EDI = *unaff_ESI;
  *(uint *)(unaff_EDI + -4) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  unaff_EDI[-5] = uVar1;
                    /* WARNING: Could not recover jumptable at 0x005668b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005668ba
// Address: 005668ba
// XREFS: None
void FUN_005668ba(void)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  uVar2 = unaff_ESI[1];
  *(char *)(unaff_EDI + -4) = (char)uVar2;
  *(uint *)(unaff_EDI + -3) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  *(char *)(unaff_EDI + -5) = (char)(uVar2 >> 8);
  *(char *)(unaff_EDI + -6) = (char)(uVar2 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x005668d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005668dc
// Address: 005668dc
// XREFS: None
void FUN_005668dc(void)
{
  undefined4 uVar1;
  uint uVar2;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -1);
  uVar2 = *(uint *)(unaff_ESI + 3);
  *unaff_EDI = (char)((uint)uVar1 >> 8);
  unaff_EDI[-1] = (char)((uint)uVar1 >> 0x10);
  unaff_EDI[-2] = (char)((uint)uVar1 >> 0x18);
  *(uint *)(unaff_EDI + -6) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
                    /* WARNING: Could not recover jumptable at 0x005668f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005668fe
// Address: 005668fe
// XREFS: None
void FUN_005668fe(void)
{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar2 = *(uint *)((int)unaff_ESI + 2);
  *(uint *)(unaff_EDI + -5) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar3 = *unaff_ESI;
  uVar1 = *(undefined1 *)((int)unaff_ESI + 6);
  *unaff_EDI = (char)uVar3;
  unaff_EDI[-6] = uVar1;
  unaff_EDI[-1] = (char)((uint)uVar3 >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566919. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056691f
// Address: 0056691f
// XREFS: None
void FUN_0056691f(void)
{
  uint uVar1;
  undefined4 uVar2;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + 1);
  *unaff_EDI = *unaff_ESI;
  uVar2 = *(undefined4 *)(unaff_ESI + 5);
  *(uint *)(unaff_EDI + -4) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  unaff_EDI[-5] = (char)uVar2;
  unaff_EDI[-6] = (char)((uint)uVar2 >> 8);
                    /* WARNING: Could not recover jumptable at 0x0056693a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566940
// Address: 00566940
// XREFS: FUN_00566940
void __fastcall FUN_00566940(uint param_1)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  bool bVar2;
  
  do {
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(unaff_EDI + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    unaff_EDI = unaff_EDI + -4;
    bVar2 = 3 < param_1;
    param_1 = param_1 - 4;
  } while (bVar2 && param_1 != 0);
                    /* WARNING: Could not recover jumptable at 0x00566952. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566958
// Address: 00566958
// XREFS: None
void __fastcall FUN_00566958(int param_1)
{
  uint uVar1;
  uint uVar2;
  undefined1 *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  undefined1 *puVar4;
  bool bVar5;
  
  puVar3 = (uint *)(unaff_ESI + 1);
  *unaff_EDI = *unaff_ESI;
  puVar4 = unaff_EDI + -1;
  uVar2 = param_1 - 1;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(puVar4 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    puVar4 = puVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
                    /* WARNING: Could not recover jumptable at 0x00566971. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566977
// Address: 00566977
// XREFS: None
void __fastcall FUN_00566977(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *unaff_ESI;
  uint *puVar4;
  undefined1 *unaff_EDI;
  undefined1 *puVar5;
  bool bVar6;
  
  uVar1 = *unaff_ESI;
  puVar4 = (uint *)((int)unaff_ESI + 2);
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  puVar5 = unaff_EDI + -2;
  uVar3 = param_1 - 2;
  do {
    uVar2 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(puVar5 + -3) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    puVar5 = puVar5 + -4;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
  } while (bVar6 && uVar3 != 0);
                    /* WARNING: Could not recover jumptable at 0x00566999. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056699f
// Address: 0056699f
// XREFS: None
void __fastcall FUN_0056699f(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *unaff_ESI;
  uint *puVar4;
  undefined1 *unaff_EDI;
  undefined1 *puVar5;
  bool bVar6;
  
  uVar1 = *unaff_ESI;
  puVar4 = (uint *)((int)unaff_ESI + 3);
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  unaff_EDI[-2] = (char)((uint)uVar1 >> 0x10);
  puVar5 = unaff_EDI + -3;
  uVar3 = param_1 - 3;
  do {
    uVar2 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(puVar5 + -3) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    puVar5 = puVar5 + -4;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
  } while (bVar6 && uVar3 != 0);
                    /* WARNING: Could not recover jumptable at 0x005669c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005669cd
// Address: 005669cd
// XREFS: None
void __fastcall FUN_005669cd(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  bool bVar3;
  
  uVar2 = param_1 - 1;
  do {
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(unaff_EDI + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    unaff_EDI = unaff_EDI + -4;
    bVar3 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar3 && uVar2 != 0);
  *unaff_EDI = (char)*unaff_ESI;
                    /* WARNING: Could not recover jumptable at 0x005669e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005669ec
// Address: 005669ec
// XREFS: None
void __fastcall FUN_005669ec(int param_1)
{
  uint uVar1;
  uint uVar2;
  undefined1 *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  undefined1 *puVar4;
  bool bVar5;
  
  puVar3 = (uint *)(unaff_ESI + 1);
  *unaff_EDI = *unaff_ESI;
  puVar4 = unaff_EDI + -1;
  uVar2 = param_1 - 2;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(puVar4 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    puVar4 = puVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
  *puVar4 = (char)*puVar3;
                    /* WARNING: Could not recover jumptable at 0x00566a0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566a13
// Address: 00566a13
// XREFS: None
void __fastcall FUN_00566a13(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *unaff_ESI;
  uint *puVar4;
  undefined1 *unaff_EDI;
  undefined1 *puVar5;
  bool bVar6;
  
  uVar1 = *unaff_ESI;
  puVar4 = (uint *)((int)unaff_ESI + 2);
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  puVar5 = unaff_EDI + -2;
  uVar3 = param_1 - 3;
  do {
    uVar2 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(puVar5 + -3) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    puVar5 = puVar5 + -4;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
  } while (bVar6 && uVar3 != 0);
  *puVar5 = (char)*puVar4;
                    /* WARNING: Could not recover jumptable at 0x00566a3b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566a41
// Address: 00566a41
// XREFS: None
void __fastcall FUN_00566a41(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *unaff_ESI;
  uint *puVar4;
  undefined1 *unaff_EDI;
  undefined1 *puVar5;
  bool bVar6;
  
  uVar1 = *unaff_ESI;
  puVar4 = (uint *)((int)unaff_ESI + 3);
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  unaff_EDI[-2] = (char)((uint)uVar1 >> 0x10);
  puVar5 = unaff_EDI + -3;
  uVar3 = param_1 - 4;
  do {
    uVar2 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(puVar5 + -3) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    puVar5 = puVar5 + -4;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
  } while (bVar6 && uVar3 != 0);
  *puVar5 = (char)*puVar4;
                    /* WARNING: Could not recover jumptable at 0x00566a6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566a75
// Address: 00566a75
// XREFS: None
void __fastcall FUN_00566a75(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  undefined1 *puVar3;
  bool bVar4;
  
  uVar2 = param_1 - 2;
  do {
    puVar3 = unaff_EDI;
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(puVar3 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    bVar4 = 3 < uVar2;
    uVar2 = uVar2 - 4;
    unaff_EDI = puVar3 + -4;
  } while (bVar4 && uVar2 != 0);
  uVar2 = *unaff_ESI;
  puVar3[-4] = (char)uVar2;
  puVar3[-5] = (char)(uVar2 >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566a97. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566a9d
// Address: 00566a9d
// XREFS: None
void __fastcall FUN_00566a9d(int param_1)
{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *unaff_ESI;
  uint *puVar4;
  undefined1 *unaff_EDI;
  undefined1 *puVar5;
  bool bVar6;
  
  puVar4 = (uint *)(unaff_ESI + 1);
  *unaff_EDI = *unaff_ESI;
  uVar3 = param_1 - 3;
  puVar2 = unaff_EDI + -1;
  do {
    puVar5 = puVar2;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(puVar5 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
    puVar2 = puVar5 + -4;
  } while (bVar6 && uVar3 != 0);
  uVar3 = *puVar4;
  puVar5[-4] = (char)uVar3;
  puVar5[-5] = (char)(uVar3 >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566ac5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566acb
// Address: 00566acb
// XREFS: None
void __fastcall FUN_00566acb(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *unaff_ESI;
  uint *puVar5;
  undefined1 *unaff_EDI;
  undefined1 *puVar6;
  bool bVar7;
  
  uVar1 = *unaff_ESI;
  puVar5 = (uint *)((int)unaff_ESI + 2);
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  uVar4 = param_1 - 4;
  puVar3 = unaff_EDI + -2;
  do {
    puVar6 = puVar3;
    uVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    *(uint *)(puVar6 + -3) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar3 = puVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *puVar5;
  puVar6[-4] = (char)uVar4;
  puVar6[-5] = (char)(uVar4 >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566afa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566b00
// Address: 00566b00
// XREFS: None
void __fastcall FUN_00566b00(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *unaff_ESI;
  uint *puVar5;
  undefined1 *unaff_EDI;
  undefined1 *puVar6;
  bool bVar7;
  
  uVar1 = *unaff_ESI;
  puVar5 = (uint *)((int)unaff_ESI + 3);
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  unaff_EDI[-2] = (char)((uint)uVar1 >> 0x10);
  uVar4 = param_1 - 5;
  puVar3 = unaff_EDI + -3;
  do {
    puVar6 = puVar3;
    uVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    *(uint *)(puVar6 + -3) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar3 = puVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *puVar5;
  puVar6[-4] = (char)uVar4;
  puVar6[-5] = (char)(uVar4 >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566b35. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566b3b
// Address: 00566b3b
// XREFS: None
void __fastcall FUN_00566b3b(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  undefined1 *puVar3;
  bool bVar4;
  
  uVar2 = param_1 - 3;
  do {
    puVar3 = unaff_EDI;
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(puVar3 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    bVar4 = 3 < uVar2;
    uVar2 = uVar2 - 4;
    unaff_EDI = puVar3 + -4;
  } while (bVar4 && uVar2 != 0);
  uVar2 = *unaff_ESI;
  puVar3[-4] = (char)uVar2;
  puVar3[-5] = (char)(uVar2 >> 8);
  puVar3[-6] = (char)(uVar2 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00566b63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566b69
// Address: 00566b69
// XREFS: None
void __fastcall FUN_00566b69(int param_1)
{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *unaff_ESI;
  uint *puVar4;
  undefined1 *unaff_EDI;
  undefined1 *puVar5;
  bool bVar6;
  
  puVar4 = (uint *)(unaff_ESI + 1);
  *unaff_EDI = *unaff_ESI;
  uVar3 = param_1 - 4;
  puVar2 = unaff_EDI + -1;
  do {
    puVar5 = puVar2;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(puVar5 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
    puVar2 = puVar5 + -4;
  } while (bVar6 && uVar3 != 0);
  uVar3 = *puVar4;
  puVar5[-4] = (char)uVar3;
  puVar5[-5] = (char)(uVar3 >> 8);
  puVar5[-6] = (char)(uVar3 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00566b97. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566b9d
// Address: 00566b9d
// XREFS: None
void __fastcall FUN_00566b9d(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *unaff_ESI;
  uint *puVar5;
  undefined1 *unaff_EDI;
  undefined1 *puVar6;
  bool bVar7;
  
  uVar1 = *unaff_ESI;
  puVar5 = (uint *)((int)unaff_ESI + 2);
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  uVar4 = param_1 - 5;
  puVar3 = unaff_EDI + -2;
  do {
    puVar6 = puVar3;
    uVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    *(uint *)(puVar6 + -3) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar3 = puVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *puVar5;
  puVar6[-4] = (char)uVar4;
  puVar6[-5] = (char)(uVar4 >> 8);
  puVar6[-6] = (char)(uVar4 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00566bd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566bd8
// Address: 00566bd8
// XREFS: None
void __fastcall FUN_00566bd8(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *unaff_ESI;
  uint *puVar5;
  undefined1 *unaff_EDI;
  undefined1 *puVar6;
  bool bVar7;
  
  uVar1 = *unaff_ESI;
  puVar5 = (uint *)((int)unaff_ESI + 3);
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)((uint)uVar1 >> 8);
  unaff_EDI[-2] = (char)((uint)uVar1 >> 0x10);
  uVar4 = param_1 - 6;
  puVar3 = unaff_EDI + -3;
  do {
    puVar6 = puVar3;
    uVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    *(uint *)(puVar6 + -3) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar3 = puVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *puVar5;
  puVar6[-4] = (char)uVar4;
  puVar6[-5] = (char)(uVar4 >> 8);
  puVar6[-6] = (char)(uVar4 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00566c13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566c19
// Address: 00566c19
// XREFS: None
void FUN_00566c19(void)
{
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI & (byte)(undefined4)DAT_0088c02c | (byte)DAT_0088c02c._4_4_;
                    /* WARNING: Could not recover jumptable at 0x00566c2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566c31
// Address: 00566c31
// XREFS: None
void FUN_00566c31(void)
{
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI & (byte)((uint)(undefined4)DAT_0088c02c >> 8) |
               (byte)((uint)DAT_0088c02c._4_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566c43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566c49
// Address: 00566c49
// XREFS: None
void FUN_00566c49(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566c62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566c68
// Address: 00566c68
// XREFS: None
void FUN_00566c68(void)
{
  uint uVar1;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)(uVar1 >> 8);
  unaff_EDI[-1] = (char)(uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00566c85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566c8b
// Address: 00566c8b
// XREFS: None
void FUN_00566c8b(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566ca4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566caa
// Address: 00566caa
// XREFS: None
void FUN_00566caa(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00566cc9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566ccf
// Address: 00566ccf
// XREFS: None
void FUN_00566ccf(void)
{
  uint uVar1;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)(uVar1 >> 8);
  unaff_EDI[-1] = (char)(uVar1 >> 0x10);
  unaff_EDI[-2] = (char)(uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00566cef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566cf5
// Address: 00566cf5
// XREFS: None
void FUN_00566cf5(void)
{
  uint uVar1;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)(uVar1 >> 8);
  unaff_EDI[-1] = (char)(uVar1 >> 0x10);
  unaff_EDI[-2] =
       *(byte *)(unaff_ESI + 2) & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._4_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566d2a
// Address: 00566d2a
// XREFS: None
void FUN_00566d2a(void)
{
  uint uVar1;
  uint *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = (byte)*unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._4_4_;
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  unaff_EDI[-1] = (byte)(uVar1 >> 8);
  unaff_EDI[-2] = (byte)(uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00566d59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566d5f
// Address: 00566d5f
// XREFS: None
void FUN_00566d5f(void)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *(uint *)(unaff_EDI + -3) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
                    /* WARNING: Could not recover jumptable at 0x00566d78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566d7e
// Address: 00566d7e
// XREFS: None
void FUN_00566d7e(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  unaff_EDI[-3] =
       *(byte *)((int)unaff_ESI + 3) & (byte)((uint)DAT_0088c02c >> 8) |
       (byte)(DAT_0088c02c._4_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566daf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566db5
// Address: 00566db5
// XREFS: None
void FUN_00566db5(void)
{
  uint uVar1;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)(uVar1 >> 8);
  unaff_EDI[-1] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)(unaff_ESI + 1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  unaff_EDI[-2] = (char)(uVar1 >> 8);
  unaff_EDI[-3] = (char)(uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00566def. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566df5
// Address: 00566df5
// XREFS: None
void FUN_00566df5(void)
{
  uint uVar1;
  uint *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = (byte)*unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._4_4_;
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  unaff_EDI[-1] = (byte)(uVar1 >> 8);
  unaff_EDI[-2] = (byte)(uVar1 >> 0x10);
  unaff_EDI[-3] = (byte)(uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00566e27. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566e2d
// Address: 00566e2d
// XREFS: None
void FUN_00566e2d(void)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *(uint *)(unaff_EDI + -3) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *(byte *)(unaff_EDI + -4) =
       (byte)unaff_ESI[1] & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._4_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00566e58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566e5e
// Address: 00566e5e
// XREFS: None
void FUN_00566e5e(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)((int)unaff_ESI + 2) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  unaff_EDI[-3] = (char)(uVar1 >> 8);
  unaff_EDI[-4] = (char)(uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00566e9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566ea0
// Address: 00566ea0
// XREFS: None
void FUN_00566ea0(void)
{
  uint uVar1;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)(uVar1 >> 8);
  unaff_EDI[-1] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)(unaff_ESI + 1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  unaff_EDI[-2] = (char)(uVar1 >> 8);
  unaff_EDI[-3] = (char)(uVar1 >> 0x10);
  unaff_EDI[-4] = (char)(uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00566edd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566ee3
// Address: 00566ee3
// XREFS: None
void FUN_00566ee3(void)
{
  uint uVar1;
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._4_4_;
  uVar1 = *(uint *)(unaff_ESI + 1);
  *(uint *)(unaff_EDI + -4) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
                    /* WARNING: Could not recover jumptable at 0x00566f0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566f14
// Address: 00566f14
// XREFS: None
void FUN_00566f14(void)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *(uint *)(unaff_EDI + -3) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  uVar1 = *(uint *)((int)unaff_ESI + 3) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *(char *)(unaff_EDI + -4) = (char)(uVar1 >> 8);
  *(char *)(unaff_EDI + -5) = (char)(uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00566f4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566f50
// Address: 00566f50
// XREFS: None
void FUN_00566f50(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)((int)unaff_ESI + 2) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  unaff_EDI[-3] = (char)(uVar1 >> 8);
  unaff_EDI[-4] = (char)(uVar1 >> 0x10);
  unaff_EDI[-5] = (char)(uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00566f8f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566f95
// Address: 00566f95
// XREFS: None
void FUN_00566f95(void)
{
  uint uVar1;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)(uVar1 >> 8);
  unaff_EDI[-1] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)(unaff_ESI + 2);
  *(uint *)(unaff_EDI + -5) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
                    /* WARNING: Could not recover jumptable at 0x00566fcb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00566fd1
// Address: 00566fd1
// XREFS: None
void FUN_00566fd1(void)
{
  uint uVar1;
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._4_4_;
  uVar1 = *(uint *)(unaff_ESI + 1);
  *(uint *)(unaff_EDI + -4) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  unaff_EDI[-5] = unaff_ESI[5] & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._4_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x0056700e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567014
// Address: 00567014
// XREFS: None
void FUN_00567014(void)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *(uint *)(unaff_EDI + -3) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  uVar1 = *(uint *)((int)unaff_ESI + 3) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *(char *)(unaff_EDI + -4) = (char)(uVar1 >> 8);
  *(char *)(unaff_EDI + -5) = (char)(uVar1 >> 0x10);
  *(char *)(unaff_EDI + -6) = (char)(uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x0056704d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567053
// Address: 00567053
// XREFS: None
void FUN_00567053(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)((int)unaff_ESI + 3);
  *(uint *)(unaff_EDI + -6) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
                    /* WARNING: Could not recover jumptable at 0x0056708b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567091
// Address: 00567091
// XREFS: None
void FUN_00567091(void)
{
  uint uVar1;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)(uVar1 >> 8);
  unaff_EDI[-1] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)(unaff_ESI + 2);
  *(uint *)(unaff_EDI + -5) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  unaff_EDI[-6] =
       *(byte *)(unaff_ESI + 6) & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._4_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x005670d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005670df
// Address: 005670df
// XREFS: None
void FUN_005670df(void)
{
  uint uVar1;
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._4_4_;
  uVar1 = *(uint *)(unaff_ESI + 1);
  *(uint *)(unaff_EDI + -4) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  uVar1 = *(uint *)(unaff_ESI + 4) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  unaff_EDI[-5] = (byte)(uVar1 >> 8);
  unaff_EDI[-6] = (byte)(uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00567127. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056712d
// Address: 0056712d
// XREFS: FUN_0056712d
void __fastcall FUN_0056712d(uint param_1)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  bool bVar2;
  
  do {
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(unaff_EDI + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    unaff_EDI = unaff_EDI + -4;
    bVar2 = 3 < param_1;
    param_1 = param_1 - 4;
  } while (bVar2 && param_1 != 0);
                    /* WARNING: Could not recover jumptable at 0x0056714b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567151
// Address: 00567151
// XREFS: None
void __fastcall FUN_00567151(int param_1)
{
  uint uVar1;
  uint uVar2;
  byte *unaff_ESI;
  uint *puVar3;
  byte *unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  puVar3 = (uint *)(unaff_ESI + 1);
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._4_4_;
  pbVar4 = unaff_EDI + -1;
  uVar2 = param_1 - 1;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
                    /* WARNING: Could not recover jumptable at 0x00567182. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567188
// Address: 00567188
// XREFS: None
void __fastcall FUN_00567188(int param_1)
{
  uint uVar1;
  uint uVar2;
  int unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  undefined1 *puVar4;
  bool bVar5;
  
  puVar3 = (uint *)(unaff_ESI + 2);
  uVar2 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)(uVar2 >> 8);
  unaff_EDI[-1] = (char)(uVar2 >> 0x10);
  puVar4 = unaff_EDI + -2;
  uVar2 = param_1 - 2;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(puVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    puVar4 = puVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
                    /* WARNING: Could not recover jumptable at 0x005671c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005671cc
// Address: 005671cc
// XREFS: None
void __fastcall FUN_005671cc(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  undefined1 *puVar4;
  bool bVar5;
  
  uVar2 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)uVar2;
  unaff_EDI[-1] = (char)(uVar2 >> 8);
  unaff_EDI[-2] = (char)(uVar2 >> 0x10);
  puVar3 = (uint *)((int)unaff_ESI + 3);
  puVar4 = unaff_EDI + -3;
  uVar2 = param_1 - 3;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(puVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    puVar4 = puVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
                    /* WARNING: Could not recover jumptable at 0x0056720c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567212
// Address: 00567212
// XREFS: None
void __fastcall FUN_00567212(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  byte *unaff_EDI;
  bool bVar3;
  
  uVar2 = param_1 - 1;
  do {
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(unaff_EDI + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    unaff_EDI = unaff_EDI + -4;
    bVar3 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar3 && uVar2 != 0);
  *unaff_EDI = (byte)*unaff_ESI & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._4_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567243. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567249
// Address: 00567249
// XREFS: None
void __fastcall FUN_00567249(int param_1)
{
  uint uVar1;
  uint uVar2;
  byte *unaff_ESI;
  uint *puVar3;
  byte *unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  puVar3 = (uint *)(unaff_ESI + 1);
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._4_4_;
  pbVar4 = unaff_EDI + -1;
  uVar2 = param_1 - 2;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
  *pbVar4 = (byte)*puVar3 & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._4_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x0056728e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567294
// Address: 00567294
// XREFS: None
void __fastcall FUN_00567294(int param_1)
{
  uint uVar1;
  uint uVar2;
  int unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  puVar3 = (uint *)(unaff_ESI + 2);
  uVar2 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)(uVar2 >> 8);
  unaff_EDI[-1] = (char)(uVar2 >> 0x10);
  pbVar4 = unaff_EDI + -2;
  uVar2 = param_1 - 3;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
  *pbVar4 = (byte)*puVar3 & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._4_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x005672e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005672ea
// Address: 005672ea
// XREFS: None
void __fastcall FUN_005672ea(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  uVar2 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)uVar2;
  unaff_EDI[-1] = (char)(uVar2 >> 8);
  unaff_EDI[-2] = (char)(uVar2 >> 0x10);
  puVar3 = (uint *)((int)unaff_ESI + 3);
  pbVar4 = unaff_EDI + -3;
  uVar2 = param_1 - 4;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
  *pbVar4 = (byte)*puVar3 & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._4_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x0056733c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567342
// Address: 00567342
// XREFS: None
void __fastcall FUN_00567342(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  undefined1 *puVar4;
  bool bVar5;
  
  uVar2 = param_1 - 2;
  do {
    puVar4 = unaff_EDI;
    puVar3 = unaff_ESI;
    uVar1 = *puVar3;
    *(uint *)(puVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
    unaff_ESI = puVar3 + 1;
    unaff_EDI = puVar4 + -4;
  } while (bVar5 && uVar2 != 0);
  uVar2 = *(uint *)((int)puVar3 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  puVar4[-4] = (char)(uVar2 >> 8);
  puVar4[-5] = (char)(uVar2 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00567380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567386
// Address: 00567386
// XREFS: None
void __fastcall FUN_00567386(int param_1)
{
  uint uVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  byte *unaff_ESI;
  uint *puVar5;
  byte *unaff_EDI;
  byte *pbVar6;
  bool bVar7;
  
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._4_4_;
  uVar4 = param_1 - 3;
  puVar2 = (uint *)(unaff_ESI + 1);
  pbVar3 = unaff_EDI + -1;
  do {
    pbVar6 = pbVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(pbVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    pbVar3 = pbVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  pbVar6[-4] = (byte)(uVar4 >> 8);
  pbVar6[-5] = (byte)(uVar4 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x005673d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005673dc
// Address: 005673dc
// XREFS: None
void __fastcall FUN_005673dc(int param_1)
{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  int unaff_ESI;
  uint *puVar5;
  undefined1 *unaff_EDI;
  undefined1 *puVar6;
  bool bVar7;
  
  uVar4 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)(uVar4 >> 8);
  unaff_EDI[-1] = (char)(uVar4 >> 0x10);
  uVar4 = param_1 - 4;
  puVar2 = (uint *)(unaff_ESI + 2);
  puVar3 = unaff_EDI + -2;
  do {
    puVar6 = puVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(puVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    puVar3 = puVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  puVar6[-4] = (char)(uVar4 >> 8);
  puVar6[-5] = (char)(uVar4 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00567437. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056743d
// Address: 0056743d
// XREFS: None
void __fastcall FUN_0056743d(int param_1)
{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint *unaff_ESI;
  uint *puVar5;
  undefined1 *unaff_EDI;
  undefined1 *puVar6;
  bool bVar7;
  
  uVar4 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)uVar4;
  unaff_EDI[-1] = (char)(uVar4 >> 8);
  unaff_EDI[-2] = (char)(uVar4 >> 0x10);
  uVar4 = param_1 - 5;
  puVar2 = (uint *)((int)unaff_ESI + 3);
  puVar3 = unaff_EDI + -3;
  do {
    puVar6 = puVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(puVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    puVar3 = puVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  puVar6[-4] = (char)(uVar4 >> 8);
  puVar6[-5] = (char)(uVar4 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x0056749a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005674a0
// Address: 005674a0
// XREFS: None
void __fastcall FUN_005674a0(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  undefined1 *puVar4;
  bool bVar5;
  
  uVar2 = param_1 - 3;
  do {
    puVar4 = unaff_EDI;
    puVar3 = unaff_ESI;
    uVar1 = *puVar3;
    *(uint *)(puVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
    unaff_ESI = puVar3 + 1;
    unaff_EDI = puVar4 + -4;
  } while (bVar5 && uVar2 != 0);
  uVar2 = *(uint *)((int)puVar3 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  puVar4[-4] = (char)(uVar2 >> 8);
  puVar4[-5] = (char)(uVar2 >> 0x10);
  puVar4[-6] = (char)(uVar2 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x005674e1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005674e7
// Address: 005674e7
// XREFS: None
void __fastcall FUN_005674e7(int param_1)
{
  uint uVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  byte *unaff_ESI;
  uint *puVar5;
  byte *unaff_EDI;
  byte *pbVar6;
  bool bVar7;
  
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._4_4_;
  uVar4 = param_1 - 4;
  puVar2 = (uint *)(unaff_ESI + 1);
  pbVar3 = unaff_EDI + -1;
  do {
    pbVar6 = pbVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(pbVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    pbVar3 = pbVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  pbVar6[-4] = (byte)(uVar4 >> 8);
  pbVar6[-5] = (byte)(uVar4 >> 0x10);
  pbVar6[-6] = (byte)(uVar4 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x0056753a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567540
// Address: 00567540
// XREFS: None
void __fastcall FUN_00567540(int param_1)
{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  int unaff_ESI;
  uint *puVar5;
  undefined1 *unaff_EDI;
  undefined1 *puVar6;
  bool bVar7;
  
  uVar4 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)(uVar4 >> 8);
  unaff_EDI[-1] = (char)(uVar4 >> 0x10);
  uVar4 = param_1 - 5;
  puVar2 = (uint *)(unaff_ESI + 2);
  puVar3 = unaff_EDI + -2;
  do {
    puVar6 = puVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(puVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    puVar3 = puVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  puVar6[-4] = (char)(uVar4 >> 8);
  puVar6[-5] = (char)(uVar4 >> 0x10);
  puVar6[-6] = (char)(uVar4 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x0056759e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005675a4
// Address: 005675a4
// XREFS: None
void __fastcall FUN_005675a4(int param_1)
{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint *unaff_ESI;
  uint *puVar5;
  undefined1 *unaff_EDI;
  undefined1 *puVar6;
  bool bVar7;
  
  uVar4 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  *unaff_EDI = (char)uVar4;
  unaff_EDI[-1] = (char)(uVar4 >> 8);
  unaff_EDI[-2] = (char)(uVar4 >> 0x10);
  uVar4 = param_1 - 6;
  puVar2 = (uint *)((int)unaff_ESI + 3);
  puVar3 = unaff_EDI + -3;
  do {
    puVar6 = puVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(puVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    puVar3 = puVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._4_4_;
  puVar6[-4] = (char)(uVar4 >> 8);
  puVar6[-5] = (char)(uVar4 >> 0x10);
  puVar6[-6] = (char)(uVar4 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00567604. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056760a
// Address: 0056760a
// XREFS: None
void FUN_0056760a(void)
{
  byte unaff_BL;
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI | unaff_BL;
                    /* WARNING: Could not recover jumptable at 0x00567612. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567618
// Address: 00567618
// XREFS: None
void FUN_00567618(void)
{
  ushort uVar1;
  uint unaff_EBX;
  ushort *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *unaff_EDI = (char)(uVar1 | unaff_EBX);
  unaff_EDI[-1] = (char)((uVar1 | unaff_EBX) >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567628. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056762e
// Address: 0056762e
// XREFS: None
void FUN_0056762e(void)
{
  uint uVar1;
  uint unaff_EBX;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI | unaff_EBX;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00567643. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567649
// Address: 00567649
// XREFS: None
void FUN_00567649(void)
{
  uint uVar1;
  uint unaff_EBX;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *(uint *)(unaff_EDI + -3) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX;
                    /* WARNING: Could not recover jumptable at 0x00567658. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056765e
// Address: 0056765e
// XREFS: None
void FUN_0056765e(void)
{
  uint uVar1;
  uint unaff_EBX;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI | unaff_EBX;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  unaff_EDI[-3] = (char)(uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00567676. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056767c
// Address: 0056767c
// XREFS: None
void FUN_0056767c(void)
{
  uint uVar1;
  uint unaff_EBX;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI | unaff_EBX;
  *(byte *)(unaff_EDI + -4) = (byte)unaff_ESI[1] | (byte)unaff_EBX;
  *(uint *)(unaff_EDI + -3) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
                    /* WARNING: Could not recover jumptable at 0x00567693. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567699
// Address: 00567699
// XREFS: None
void FUN_00567699(void)
{
  uint uVar1;
  uint unaff_EBX;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI | unaff_EBX;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)((int)unaff_ESI + 3) | unaff_EBX;
  unaff_EDI[-3] = (char)uVar1;
  unaff_EDI[-4] = (char)(uVar1 >> 8);
                    /* WARNING: Could not recover jumptable at 0x005676bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005676c3
// Address: 005676c3
// XREFS: None
void FUN_005676c3(void)
{
  uint uVar1;
  uint unaff_EBX;
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + 1) | unaff_EBX;
  *unaff_EDI = *unaff_ESI | (byte)unaff_EBX;
  *(uint *)(unaff_EDI + -4) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
                    /* WARNING: Could not recover jumptable at 0x005676d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005676df
// Address: 005676df
// XREFS: None
void FUN_005676df(void)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = unaff_ESI[1];
  uVar2 = *unaff_ESI | unaff_EBX;
  *(uint *)(unaff_EDI + -3) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  *(char *)(unaff_EDI + -4) = (char)(uVar1 | unaff_EBX);
  *(char *)(unaff_EDI + -5) = (char)((uVar1 | unaff_EBX) >> 8);
                    /* WARNING: Could not recover jumptable at 0x005676f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005676ff
// Address: 005676ff
// XREFS: None
void FUN_005676ff(void)
{
  uint uVar1;
  uint unaff_EBX;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI | unaff_EBX;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)((int)unaff_ESI + 3) | unaff_EBX;
  unaff_EDI[-3] = (char)uVar1;
  unaff_EDI[-4] = (char)(uVar1 >> 8);
  unaff_EDI[-5] = (char)(uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00567729. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056772f
// Address: 0056772f
// XREFS: None
void FUN_0056772f(void)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI;
  uVar2 = *(uint *)((int)unaff_ESI + 2) | unaff_EBX;
  *unaff_EDI = (char)(uVar1 | unaff_EBX);
  unaff_EDI[-1] = (char)((uVar1 | unaff_EBX) >> 8);
  *(uint *)(unaff_EDI + -5) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
                    /* WARNING: Could not recover jumptable at 0x00567748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056774e
// Address: 0056774e
// XREFS: None
void FUN_0056774e(void)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + 1) | unaff_EBX;
  uVar2 = CONCAT11(unaff_ESI[5],*unaff_ESI) | unaff_EBX;
  *unaff_EDI = (char)uVar2;
  *(uint *)(unaff_EDI + -4) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  unaff_EDI[-5] = (char)(uVar2 >> 8);
                    /* WARNING: Could not recover jumptable at 0x0056776a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567770
// Address: 00567770
// XREFS: None
void FUN_00567770(void)
{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  uint unaff_EBX;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = unaff_ESI[1];
  uVar2 = *unaff_ESI | unaff_EBX;
  *(uint *)(unaff_EDI + -3) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar3 = (undefined1)(uVar1 | unaff_EBX);
  *(undefined1 *)(unaff_EDI + -4) = uVar3;
  *(char *)(unaff_EDI + -5) = (char)((uVar1 | unaff_EBX) >> 8);
  *(undefined1 *)(unaff_EDI + -6) = uVar3;
                    /* WARNING: Could not recover jumptable at 0x00567790. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567796
// Address: 00567796
// XREFS: None
void FUN_00567796(void)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI | unaff_EBX;
  uVar2 = *(uint *)((int)unaff_ESI + 3) | unaff_EBX;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  *(uint *)(unaff_EDI + -6) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
                    /* WARNING: Could not recover jumptable at 0x005677b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005677bb
// Address: 005677bb
// XREFS: None
void FUN_005677bb(void)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI;
  uVar2 = *(uint *)((int)unaff_ESI + 2) | unaff_EBX;
  *unaff_EDI = (char)(uVar1 | unaff_EBX);
  unaff_EDI[-1] = (char)((uVar1 | unaff_EBX) >> 8);
  *(uint *)(unaff_EDI + -5) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  unaff_EDI[-6] = *(byte *)((int)unaff_ESI + 6) | (byte)unaff_EBX;
                    /* WARNING: Could not recover jumptable at 0x005677dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005677e2
// Address: 005677e2
// XREFS: None
void FUN_005677e2(void)
{
  uint uVar1;
  uint unaff_EBX;
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + 1) | unaff_EBX;
  *unaff_EDI = *unaff_ESI | (byte)unaff_EBX;
  *(uint *)(unaff_EDI + -4) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = *(uint *)(unaff_ESI + 5);
  unaff_EDI[-5] = (byte)(uVar1 | unaff_EBX);
  unaff_EDI[-6] = (byte)((uVar1 | unaff_EBX) >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567803. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567809
// Address: 00567809
// XREFS: FUN_00567809
void __fastcall FUN_00567809(uint param_1)
{
  uint uVar1;
  uint unaff_EBX;
  uint *unaff_ESI;
  int unaff_EDI;
  bool bVar2;
  
  do {
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(unaff_EDI + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    unaff_EDI = unaff_EDI + -4;
    bVar2 = 3 < param_1;
    param_1 = param_1 - 4;
  } while (bVar2 && param_1 != 0);
                    /* WARNING: Could not recover jumptable at 0x0056781d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567823
// Address: 00567823
// XREFS: None
void __fastcall FUN_00567823(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  byte *unaff_ESI;
  uint *puVar3;
  byte *unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  *unaff_EDI = *unaff_ESI | (byte)unaff_EBX;
  puVar3 = (uint *)(unaff_ESI + 1);
  pbVar4 = unaff_EDI + -1;
  uVar2 = param_1 - 1;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
                    /* WARNING: Could not recover jumptable at 0x00567840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567846
// Address: 00567846
// XREFS: None
void __fastcall FUN_00567846(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  undefined1 *puVar4;
  bool bVar5;
  
  uVar2 = *unaff_ESI;
  *unaff_EDI = (char)(uVar2 | unaff_EBX);
  unaff_EDI[-1] = (char)((uVar2 | unaff_EBX) >> 8);
  puVar3 = (uint *)((int)unaff_ESI + 2);
  puVar4 = unaff_EDI + -2;
  uVar2 = param_1 - 2;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(puVar4 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    puVar4 = puVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
                    /* WARNING: Could not recover jumptable at 0x0056786c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567872
// Address: 00567872
// XREFS: None
void __fastcall FUN_00567872(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  undefined1 *puVar4;
  bool bVar5;
  
  uVar2 = *unaff_ESI | unaff_EBX;
  *unaff_EDI = (char)uVar2;
  unaff_EDI[-1] = (char)(uVar2 >> 8);
  unaff_EDI[-2] = (char)(uVar2 >> 0x10);
  puVar3 = (uint *)((int)unaff_ESI + 3);
  puVar4 = unaff_EDI + -3;
  uVar2 = param_1 - 3;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(puVar4 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    puVar4 = puVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
                    /* WARNING: Could not recover jumptable at 0x0056789e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005678a4
// Address: 005678a4
// XREFS: None
void __fastcall FUN_005678a4(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint *unaff_ESI;
  byte *unaff_EDI;
  bool bVar3;
  
  uVar2 = param_1 - 1;
  do {
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(unaff_EDI + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    unaff_EDI = unaff_EDI + -4;
    bVar3 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar3 && uVar2 != 0);
  *unaff_EDI = (byte)*unaff_ESI | (byte)unaff_EBX;
                    /* WARNING: Could not recover jumptable at 0x005678c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005678c7
// Address: 005678c7
// XREFS: None
void __fastcall FUN_005678c7(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  byte *unaff_ESI;
  uint *puVar3;
  byte *unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  *unaff_EDI = *unaff_ESI | (byte)unaff_EBX;
  puVar3 = (uint *)(unaff_ESI + 1);
  pbVar4 = unaff_EDI + -1;
  uVar2 = param_1 - 2;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
  *pbVar4 = (byte)*puVar3 | (byte)unaff_EBX;
                    /* WARNING: Could not recover jumptable at 0x005678ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005678f4
// Address: 005678f4
// XREFS: None
void __fastcall FUN_005678f4(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  uVar2 = *unaff_ESI;
  *unaff_EDI = (char)(uVar2 | unaff_EBX);
  unaff_EDI[-1] = (char)((uVar2 | unaff_EBX) >> 8);
  puVar3 = (uint *)((int)unaff_ESI + 2);
  pbVar4 = unaff_EDI + -2;
  uVar2 = param_1 - 3;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
  *pbVar4 = (byte)*puVar3 | (byte)unaff_EBX;
                    /* WARNING: Could not recover jumptable at 0x00567922. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567928
// Address: 00567928
// XREFS: None
void __fastcall FUN_00567928(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  uVar2 = *unaff_ESI | unaff_EBX;
  *unaff_EDI = (char)uVar2;
  unaff_EDI[-1] = (char)(uVar2 >> 8);
  unaff_EDI[-2] = (char)(uVar2 >> 0x10);
  puVar3 = (uint *)((int)unaff_ESI + 3);
  pbVar4 = unaff_EDI + -3;
  uVar2 = param_1 - 4;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
  *pbVar4 = (byte)*puVar3 | (byte)unaff_EBX;
                    /* WARNING: Could not recover jumptable at 0x0056795c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567962
// Address: 00567962
// XREFS: None
void __fastcall FUN_00567962(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  undefined1 *puVar3;
  bool bVar4;
  
  uVar2 = param_1 - 2;
  do {
    puVar3 = unaff_EDI;
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(puVar3 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    bVar4 = 3 < uVar2;
    uVar2 = uVar2 - 4;
    unaff_EDI = puVar3 + -4;
  } while (bVar4 && uVar2 != 0);
  uVar2 = *unaff_ESI;
  puVar3[-4] = (char)(uVar2 | unaff_EBX);
  puVar3[-5] = (char)((uVar2 | unaff_EBX) >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567988. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056798e
// Address: 0056798e
// XREFS: None
void __fastcall FUN_0056798e(int param_1)
{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  uint unaff_EBX;
  byte *unaff_ESI;
  uint *puVar4;
  byte *unaff_EDI;
  byte *pbVar5;
  bool bVar6;
  
  *unaff_EDI = *unaff_ESI | (byte)unaff_EBX;
  puVar4 = (uint *)(unaff_ESI + 1);
  uVar3 = param_1 - 3;
  pbVar2 = unaff_EDI + -1;
  do {
    pbVar5 = pbVar2;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(pbVar5 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
    pbVar2 = pbVar5 + -4;
  } while (bVar6 && uVar3 != 0);
  uVar3 = *puVar4;
  pbVar5[-4] = (byte)(uVar3 | unaff_EBX);
  pbVar5[-5] = (byte)((uVar3 | unaff_EBX) >> 8);
                    /* WARNING: Could not recover jumptable at 0x005679bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005679c2
// Address: 005679c2
// XREFS: None
void __fastcall FUN_005679c2(int param_1)
{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint unaff_EBX;
  uint *unaff_ESI;
  uint *puVar4;
  undefined1 *unaff_EDI;
  undefined1 *puVar5;
  bool bVar6;
  
  uVar3 = *unaff_ESI;
  *unaff_EDI = (char)(uVar3 | unaff_EBX);
  unaff_EDI[-1] = (char)((uVar3 | unaff_EBX) >> 8);
  puVar4 = (uint *)((int)unaff_ESI + 2);
  uVar3 = param_1 - 4;
  puVar2 = unaff_EDI + -2;
  do {
    puVar5 = puVar2;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(puVar5 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
    puVar2 = puVar5 + -4;
  } while (bVar6 && uVar3 != 0);
  uVar3 = *puVar4;
  puVar5[-4] = (char)(uVar3 | unaff_EBX);
  puVar5[-5] = (char)((uVar3 | unaff_EBX) >> 8);
                    /* WARNING: Could not recover jumptable at 0x005679f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005679fd
// Address: 005679fd
// XREFS: None
void __fastcall FUN_005679fd(int param_1)
{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint unaff_EBX;
  uint *unaff_ESI;
  uint *puVar4;
  undefined1 *unaff_EDI;
  undefined1 *puVar5;
  bool bVar6;
  
  uVar3 = *unaff_ESI | unaff_EBX;
  *unaff_EDI = (char)uVar3;
  unaff_EDI[-1] = (char)(uVar3 >> 8);
  unaff_EDI[-2] = (char)(uVar3 >> 0x10);
  puVar4 = (uint *)((int)unaff_ESI + 3);
  uVar3 = param_1 - 5;
  puVar2 = unaff_EDI + -3;
  do {
    puVar5 = puVar2;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(puVar5 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
    puVar2 = puVar5 + -4;
  } while (bVar6 && uVar3 != 0);
  uVar3 = *puVar4;
  puVar5[-4] = (char)(uVar3 | unaff_EBX);
  puVar5[-5] = (char)((uVar3 | unaff_EBX) >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567a38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567a3e
// Address: 00567a3e
// XREFS: None
void __fastcall FUN_00567a3e(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  undefined1 *puVar3;
  bool bVar4;
  
  uVar2 = param_1 - 3;
  do {
    puVar3 = unaff_EDI;
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(puVar3 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    bVar4 = 3 < uVar2;
    uVar2 = uVar2 - 4;
    unaff_EDI = puVar3 + -4;
  } while (bVar4 && uVar2 != 0);
  uVar2 = *unaff_ESI | unaff_EBX;
  puVar3[-4] = (char)uVar2;
  puVar3[-5] = (char)(uVar2 >> 8);
  puVar3[-6] = (char)(uVar2 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00567a6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567a70
// Address: 00567a70
// XREFS: None
void __fastcall FUN_00567a70(int param_1)
{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  uint unaff_EBX;
  byte *unaff_ESI;
  uint *puVar4;
  byte *unaff_EDI;
  byte *pbVar5;
  bool bVar6;
  
  *unaff_EDI = *unaff_ESI | (byte)unaff_EBX;
  puVar4 = (uint *)(unaff_ESI + 1);
  uVar3 = param_1 - 4;
  pbVar2 = unaff_EDI + -1;
  do {
    pbVar5 = pbVar2;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(pbVar5 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
    pbVar2 = pbVar5 + -4;
  } while (bVar6 && uVar3 != 0);
  uVar3 = *puVar4 | unaff_EBX;
  pbVar5[-4] = (byte)uVar3;
  pbVar5[-5] = (byte)(uVar3 >> 8);
  pbVar5[-6] = (byte)(uVar3 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00567aa4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567aaa
// Address: 00567aaa
// XREFS: None
void __fastcall FUN_00567aaa(int param_1)
{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint unaff_EBX;
  uint *unaff_ESI;
  uint *puVar4;
  undefined1 *unaff_EDI;
  undefined1 *puVar5;
  bool bVar6;
  
  uVar3 = *unaff_ESI;
  *unaff_EDI = (char)(uVar3 | unaff_EBX);
  unaff_EDI[-1] = (char)((uVar3 | unaff_EBX) >> 8);
  puVar4 = (uint *)((int)unaff_ESI + 2);
  uVar3 = param_1 - 5;
  puVar2 = unaff_EDI + -2;
  do {
    puVar5 = puVar2;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(puVar5 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
    puVar2 = puVar5 + -4;
  } while (bVar6 && uVar3 != 0);
  uVar3 = *puVar4 | unaff_EBX;
  puVar5[-4] = (char)uVar3;
  puVar5[-5] = (char)(uVar3 >> 8);
  puVar5[-6] = (char)(uVar3 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00567ae5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567aeb
// Address: 00567aeb
// XREFS: None
void __fastcall FUN_00567aeb(int param_1)
{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint unaff_EBX;
  uint *unaff_ESI;
  uint *puVar4;
  undefined1 *unaff_EDI;
  undefined1 *puVar5;
  bool bVar6;
  
  uVar3 = *unaff_ESI | unaff_EBX;
  *unaff_EDI = (char)uVar3;
  unaff_EDI[-1] = (char)(uVar3 >> 8);
  unaff_EDI[-2] = (char)(uVar3 >> 0x10);
  puVar4 = (uint *)((int)unaff_ESI + 3);
  uVar3 = param_1 - 6;
  puVar2 = unaff_EDI + -3;
  do {
    puVar5 = puVar2;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *(uint *)(puVar5 + -3) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18 | unaff_EBX
    ;
    bVar6 = 3 < uVar3;
    uVar3 = uVar3 - 4;
    puVar2 = puVar5 + -4;
  } while (bVar6 && uVar3 != 0);
  uVar3 = *puVar4 | unaff_EBX;
  puVar5[-4] = (char)uVar3;
  puVar5[-5] = (char)(uVar3 >> 8);
  puVar5[-6] = (char)(uVar3 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00567b2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567b32
// Address: 00567b32
// XREFS: None
void FUN_00567b32(void)
{
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI & (byte)(undefined4)DAT_0088c02c | (byte)DAT_0088c02c._8_4_;
                    /* WARNING: Could not recover jumptable at 0x00567b44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567b4a
// Address: 00567b4a
// XREFS: None
void FUN_00567b4a(void)
{
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI & (byte)((uint)(undefined4)DAT_0088c02c >> 8) |
               (byte)((uint)DAT_0088c02c._8_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567b5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567b62
// Address: 00567b62
// XREFS: None
void FUN_00567b62(void)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -1) = (short)CONCAT31((int3)uVar1,(char)(uVar1 >> 8));
                    /* WARNING: Could not recover jumptable at 0x00567b7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567b82
// Address: 00567b82
// XREFS: None
void FUN_00567b82(void)
{
  uint uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -1) = (short)CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 >> 0x10));
                    /* WARNING: Could not recover jumptable at 0x00567ba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567ba6
// Address: 00567ba6
// XREFS: None
void FUN_00567ba6(void)
{
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI & (byte)(undefined4)DAT_0088c02c | (byte)DAT_0088c02c._8_4_;
  unaff_EDI[-1] =
       unaff_ESI[1] & (byte)((uint)(undefined4)DAT_0088c02c >> 8) |
       (byte)((uint)DAT_0088c02c._8_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567bca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567bd0
// Address: 00567bd0
// XREFS: None
void FUN_00567bd0(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567be9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567bef
// Address: 00567bef
// XREFS: None
void FUN_00567bef(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x00567c0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567c14
// Address: 00567c14
// XREFS: None
void FUN_00567c14(void)
{
  uint uVar1;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *unaff_EDI = (char)(uVar1 >> 8);
  unaff_EDI[-1] = (char)(uVar1 >> 0x10);
  unaff_EDI[-2] = (char)(uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00567c34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567c3a
// Address: 00567c3a
// XREFS: None
void FUN_00567c3a(void)
{
  uint uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -1) = (short)CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 >> 0x10));
  *(byte *)(unaff_EDI + -2) =
       *(byte *)(unaff_ESI + 2) & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._8_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567c6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567c70
// Address: 00567c70
// XREFS: None
void FUN_00567c70(void)
{
  uint uVar1;
  uint *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = (byte)*unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._8_4_;
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -2) = (short)CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 >> 0x10));
                    /* WARNING: Could not recover jumptable at 0x00567ca0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567ca6
// Address: 00567ca6
// XREFS: None
void FUN_00567ca6(void)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *(uint *)(unaff_EDI + -3) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
                    /* WARNING: Could not recover jumptable at 0x00567cbf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567cc5
// Address: 00567cc5
// XREFS: None
void FUN_00567cc5(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  unaff_EDI[-3] =
       *(byte *)((int)unaff_ESI + 3) & (byte)((uint)DAT_0088c02c >> 8) |
       (byte)(DAT_0088c02c._8_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567cf6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567cfc
// Address: 00567cfc
// XREFS: None
void FUN_00567cfc(void)
{
  uint uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -1) = (short)CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 >> 0x10));
  uVar1 = *(uint *)(unaff_ESI + 1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -3) = (short)CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 >> 0x10));
                    /* WARNING: Could not recover jumptable at 0x00567d38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567d3e
// Address: 00567d3e
// XREFS: None
void FUN_00567d3e(void)
{
  uint uVar1;
  uint *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = (byte)*unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._8_4_;
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  unaff_EDI[-1] = (byte)(uVar1 >> 8);
  unaff_EDI[-2] = (byte)(uVar1 >> 0x10);
  unaff_EDI[-3] = (byte)(uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00567d70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567d76
// Address: 00567d76
// XREFS: None
void FUN_00567d76(void)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *(uint *)(unaff_EDI + -3) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(byte *)(unaff_EDI + -4) =
       (byte)unaff_ESI[1] & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._8_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567da1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567da7
// Address: 00567da7
// XREFS: None
void FUN_00567da7(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)((int)unaff_ESI + 2) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -4) = (short)CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 >> 0x10));
                    /* WARNING: Could not recover jumptable at 0x00567de4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567dea
// Address: 00567dea
// XREFS: None
void FUN_00567dea(void)
{
  uint uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -1) = (short)CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 >> 0x10));
  uVar1 = *(uint *)(unaff_ESI + 1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(char *)(unaff_EDI + -2) = (char)(uVar1 >> 8);
  *(char *)(unaff_EDI + -3) = (char)(uVar1 >> 0x10);
  *(char *)(unaff_EDI + -4) = (char)(uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00567e28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567e2e
// Address: 00567e2e
// XREFS: None
void FUN_00567e2e(void)
{
  uint uVar1;
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._8_4_;
  uVar1 = *(uint *)(unaff_ESI + 1);
  *(uint *)(unaff_EDI + -4) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
                    /* WARNING: Could not recover jumptable at 0x00567e59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567e5f
// Address: 00567e5f
// XREFS: None
void FUN_00567e5f(void)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *(uint *)(unaff_EDI + -3) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  uVar1 = *(uint *)((int)unaff_ESI + 3) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -5) = (short)CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 >> 0x10));
                    /* WARNING: Could not recover jumptable at 0x00567e96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567e9c
// Address: 00567e9c
// XREFS: None
void FUN_00567e9c(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)((int)unaff_ESI + 2) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  unaff_EDI[-3] = (char)(uVar1 >> 8);
  unaff_EDI[-4] = (char)(uVar1 >> 0x10);
  unaff_EDI[-5] = (char)(uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00567edb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567ee1
// Address: 00567ee1
// XREFS: None
void FUN_00567ee1(void)
{
  uint uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -1) = (short)CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 >> 0x10));
  uVar1 = *(uint *)(unaff_ESI + 2);
  *(uint *)(unaff_EDI + -5) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
                    /* WARNING: Could not recover jumptable at 0x00567f18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567f1e
// Address: 00567f1e
// XREFS: None
void FUN_00567f1e(void)
{
  uint uVar1;
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._8_4_;
  uVar1 = *(uint *)(unaff_ESI + 1);
  *(uint *)(unaff_EDI + -4) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  unaff_EDI[-5] = unaff_ESI[5] & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._8_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00567f5b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567f61
// Address: 00567f61
// XREFS: None
void FUN_00567f61(void)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *unaff_ESI;
  *(uint *)(unaff_EDI + -3) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  uVar1 = *(uint *)((int)unaff_ESI + 3) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(char *)(unaff_EDI + -4) = (char)(uVar1 >> 8);
  *(char *)(unaff_EDI + -5) = (char)(uVar1 >> 0x10);
  *(char *)(unaff_EDI + -6) = (char)(uVar1 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00567f9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567fa0
// Address: 00567fa0
// XREFS: None
void FUN_00567fa0(void)
{
  uint uVar1;
  uint *unaff_ESI;
  undefined1 *unaff_EDI;
  
  uVar1 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *unaff_EDI = (char)uVar1;
  unaff_EDI[-1] = (char)(uVar1 >> 8);
  unaff_EDI[-2] = (char)(uVar1 >> 0x10);
  uVar1 = *(uint *)((int)unaff_ESI + 3);
  *(uint *)(unaff_EDI + -6) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
                    /* WARNING: Could not recover jumptable at 0x00567fd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00567fde
// Address: 00567fde
// XREFS: None
void FUN_00567fde(void)
{
  uint uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -1) = (short)CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 >> 0x10));
  uVar1 = *(uint *)(unaff_ESI + 2);
  *(uint *)(unaff_EDI + -5) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(byte *)(unaff_EDI + -6) =
       *(byte *)(unaff_ESI + 6) & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._8_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00568027. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056802d
// Address: 0056802d
// XREFS: None
void FUN_0056802d(void)
{
  uint uVar1;
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._8_4_;
  uVar1 = *(uint *)(unaff_ESI + 1);
  *(uint *)(unaff_EDI + -4) =
       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
       (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  uVar1 = *(uint *)(unaff_ESI + 4) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -6) = (short)CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 >> 0x10));
                    /* WARNING: Could not recover jumptable at 0x00568076. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056807c
// Address: 0056807c
// XREFS: FUN_0056807c
void __fastcall FUN_0056807c(uint param_1)
{
  uint uVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  bool bVar2;
  
  do {
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(unaff_EDI + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    unaff_EDI = unaff_EDI + -4;
    bVar2 = 3 < param_1;
    param_1 = param_1 - 4;
  } while (bVar2 && param_1 != 0);
                    /* WARNING: Could not recover jumptable at 0x0056809a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005680a0
// Address: 005680a0
// XREFS: None
void __fastcall FUN_005680a0(int param_1)
{
  uint uVar1;
  uint uVar2;
  byte *unaff_ESI;
  uint *puVar3;
  byte *unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  puVar3 = (uint *)(unaff_ESI + 1);
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._8_4_;
  pbVar4 = unaff_EDI + -1;
  uVar2 = param_1 - 1;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
                    /* WARNING: Could not recover jumptable at 0x005680d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005680d7
// Address: 005680d7
// XREFS: None
void __fastcall FUN_005680d7(int param_1)
{
  uint uVar1;
  uint uVar2;
  int unaff_ESI;
  uint *puVar3;
  int unaff_EDI;
  int iVar4;
  bool bVar5;
  
  puVar3 = (uint *)(unaff_ESI + 2);
  uVar2 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -1) = (short)CONCAT31((int3)(uVar2 >> 8),(char)(uVar2 >> 0x10));
  iVar4 = unaff_EDI + -2;
  uVar2 = param_1 - 2;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(iVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    iVar4 = iVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
                    /* WARNING: Could not recover jumptable at 0x00568116. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056811c
// Address: 0056811c
// XREFS: None
void __fastcall FUN_0056811c(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  undefined1 *puVar4;
  bool bVar5;
  
  puVar3 = (uint *)((int)unaff_ESI + 3);
  uVar2 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *unaff_EDI = (char)uVar2;
  unaff_EDI[-1] = (char)(uVar2 >> 8);
  unaff_EDI[-2] = (char)(uVar2 >> 0x10);
  puVar4 = unaff_EDI + -3;
  uVar2 = param_1 - 3;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(puVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    puVar4 = puVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
                    /* WARNING: Could not recover jumptable at 0x0056815c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00568162
// Address: 00568162
// XREFS: None
void __fastcall FUN_00568162(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  byte *unaff_EDI;
  bool bVar3;
  
  uVar2 = param_1 - 1;
  do {
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(uint *)(unaff_EDI + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    unaff_EDI = unaff_EDI + -4;
    bVar3 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar3 && uVar2 != 0);
  *unaff_EDI = (byte)*unaff_ESI & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._8_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00568193. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00568199
// Address: 00568199
// XREFS: None
void __fastcall FUN_00568199(int param_1)
{
  uint uVar1;
  uint uVar2;
  byte *unaff_ESI;
  uint *puVar3;
  byte *unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  puVar3 = (uint *)(unaff_ESI + 1);
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._8_4_;
  pbVar4 = unaff_EDI + -1;
  uVar2 = param_1 - 2;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
  *pbVar4 = (byte)*puVar3 & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._8_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x005681de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005681e4
// Address: 005681e4
// XREFS: None
void __fastcall FUN_005681e4(int param_1)
{
  uint uVar1;
  uint uVar2;
  int unaff_ESI;
  uint *puVar3;
  int unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  puVar3 = (uint *)(unaff_ESI + 2);
  uVar2 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -1) = (short)CONCAT31((int3)(uVar2 >> 8),(char)(uVar2 >> 0x10));
  pbVar4 = (byte *)(unaff_EDI + -2);
  uVar2 = param_1 - 3;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
  *pbVar4 = (byte)*puVar3 & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._8_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x00568235. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056823b
// Address: 0056823b
// XREFS: None
void __fastcall FUN_0056823b(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  byte *pbVar4;
  bool bVar5;
  
  puVar3 = (uint *)((int)unaff_ESI + 3);
  uVar2 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *unaff_EDI = (char)uVar2;
  unaff_EDI[-1] = (char)(uVar2 >> 8);
  unaff_EDI[-2] = (char)(uVar2 >> 0x10);
  pbVar4 = unaff_EDI + -3;
  uVar2 = param_1 - 4;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *(uint *)(pbVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    pbVar4 = pbVar4 + -4;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
  } while (bVar5 && uVar2 != 0);
  *pbVar4 = (byte)*puVar3 & (byte)((uint)DAT_0088c02c >> 8) | (byte)(DAT_0088c02c._8_4_ >> 8);
                    /* WARNING: Could not recover jumptable at 0x0056828d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00568293
// Address: 00568293
// XREFS: None
void __fastcall FUN_00568293(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  uint *puVar3;
  int unaff_EDI;
  int iVar4;
  bool bVar5;
  
  uVar2 = param_1 - 2;
  do {
    iVar4 = unaff_EDI;
    puVar3 = unaff_ESI;
    uVar1 = *puVar3;
    *(uint *)(iVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
    unaff_ESI = puVar3 + 1;
    unaff_EDI = iVar4 + -4;
  } while (bVar5 && uVar2 != 0);
  uVar2 = *(uint *)((int)puVar3 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(iVar4 + -5) = (short)CONCAT31((int3)(uVar2 >> 8),(char)(uVar2 >> 0x10));
                    /* WARNING: Could not recover jumptable at 0x005682d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005682d8
// Address: 005682d8
// XREFS: None
void __fastcall FUN_005682d8(int param_1)
{
  uint uVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  byte *unaff_ESI;
  uint *puVar5;
  byte *unaff_EDI;
  byte *pbVar6;
  bool bVar7;
  
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._8_4_;
  uVar4 = param_1 - 3;
  puVar2 = (uint *)(unaff_ESI + 1);
  pbVar3 = unaff_EDI + -1;
  do {
    pbVar6 = pbVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(pbVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    pbVar3 = pbVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(pbVar6 + -5) = (short)CONCAT31((int3)(uVar4 >> 8),(char)(uVar4 >> 0x10));
                    /* WARNING: Could not recover jumptable at 0x00568329. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056832f
// Address: 0056832f
// XREFS: None
void __fastcall FUN_0056832f(int param_1)
{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int unaff_ESI;
  uint *puVar5;
  int unaff_EDI;
  int iVar6;
  bool bVar7;
  
  uVar4 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -1) = (short)CONCAT31((int3)(uVar4 >> 8),(char)(uVar4 >> 0x10));
  uVar4 = param_1 - 4;
  puVar2 = (uint *)(unaff_ESI + 2);
  iVar3 = unaff_EDI + -2;
  do {
    iVar6 = iVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(iVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    iVar3 = iVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(iVar6 + -5) = (short)CONCAT31((int3)(uVar4 >> 8),(char)(uVar4 >> 0x10));
                    /* WARNING: Could not recover jumptable at 0x0056838c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00568392
// Address: 00568392
// XREFS: None
void __fastcall FUN_00568392(int param_1)
{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint *unaff_ESI;
  uint *puVar5;
  undefined1 *unaff_EDI;
  undefined1 *puVar6;
  bool bVar7;
  
  uVar4 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *unaff_EDI = (char)uVar4;
  unaff_EDI[-1] = (char)(uVar4 >> 8);
  unaff_EDI[-2] = (char)(uVar4 >> 0x10);
  uVar4 = param_1 - 5;
  puVar2 = (uint *)((int)unaff_ESI + 3);
  puVar3 = unaff_EDI + -3;
  do {
    puVar6 = puVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(puVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    puVar3 = puVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(puVar6 + -5) = (short)CONCAT31((int3)(uVar4 >> 8),(char)(uVar4 >> 0x10));
                    /* WARNING: Could not recover jumptable at 0x005683f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005683f6
// Address: 005683f6
// XREFS: None
void __fastcall FUN_005683f6(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  uint *puVar3;
  undefined1 *unaff_EDI;
  undefined1 *puVar4;
  bool bVar5;
  
  uVar2 = param_1 - 3;
  do {
    puVar4 = unaff_EDI;
    puVar3 = unaff_ESI;
    uVar1 = *puVar3;
    *(uint *)(puVar4 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    bVar5 = 3 < uVar2;
    uVar2 = uVar2 - 4;
    unaff_ESI = puVar3 + 1;
    unaff_EDI = puVar4 + -4;
  } while (bVar5 && uVar2 != 0);
  uVar2 = *(uint *)((int)puVar3 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  puVar4[-4] = (char)(uVar2 >> 8);
  puVar4[-5] = (char)(uVar2 >> 0x10);
  puVar4[-6] = (char)(uVar2 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00568437. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056843d
// Address: 0056843d
// XREFS: None
void __fastcall FUN_0056843d(int param_1)
{
  uint uVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  byte *unaff_ESI;
  uint *puVar5;
  byte *unaff_EDI;
  byte *pbVar6;
  bool bVar7;
  
  *unaff_EDI = *unaff_ESI & (byte)(uint)DAT_0088c02c | (byte)DAT_0088c02c._8_4_;
  uVar4 = param_1 - 4;
  puVar2 = (uint *)(unaff_ESI + 1);
  pbVar3 = unaff_EDI + -1;
  do {
    pbVar6 = pbVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(pbVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    pbVar3 = pbVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  pbVar6[-4] = (byte)(uVar4 >> 8);
  pbVar6[-5] = (byte)(uVar4 >> 0x10);
  pbVar6[-6] = (byte)(uVar4 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x00568490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00568496
// Address: 00568496
// XREFS: None
void __fastcall FUN_00568496(int param_1)
{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  int unaff_ESI;
  uint *puVar5;
  int unaff_EDI;
  undefined1 *puVar6;
  bool bVar7;
  
  uVar4 = *(uint *)(unaff_ESI + -1) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *(short *)(unaff_EDI + -1) = (short)CONCAT31((int3)(uVar4 >> 8),(char)(uVar4 >> 0x10));
  uVar4 = param_1 - 5;
  puVar2 = (uint *)(unaff_ESI + 2);
  puVar3 = (undefined1 *)(unaff_EDI + -2);
  do {
    puVar6 = puVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(puVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    puVar3 = puVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  puVar6[-4] = (char)(uVar4 >> 8);
  puVar6[-5] = (char)(uVar4 >> 0x10);
  puVar6[-6] = (char)(uVar4 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x005684f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005684fb
// Address: 005684fb
// XREFS: None
void __fastcall FUN_005684fb(int param_1)
{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint *unaff_ESI;
  uint *puVar5;
  undefined1 *unaff_EDI;
  undefined1 *puVar6;
  bool bVar7;
  
  uVar4 = *unaff_ESI & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  *unaff_EDI = (char)uVar4;
  unaff_EDI[-1] = (char)(uVar4 >> 8);
  unaff_EDI[-2] = (char)(uVar4 >> 0x10);
  uVar4 = param_1 - 6;
  puVar2 = (uint *)((int)unaff_ESI + 3);
  puVar3 = unaff_EDI + -3;
  do {
    puVar6 = puVar3;
    puVar5 = puVar2;
    uVar1 = *puVar5;
    *(uint *)(puVar6 + -3) =
         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
         (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
    bVar7 = 3 < uVar4;
    uVar4 = uVar4 - 4;
    puVar2 = puVar5 + 1;
    puVar3 = puVar6 + -4;
  } while (bVar7 && uVar4 != 0);
  uVar4 = *(uint *)((int)puVar5 + 3) & (uint)DAT_0088c02c | DAT_0088c02c._8_4_;
  puVar6[-4] = (char)(uVar4 >> 8);
  puVar6[-5] = (char)(uVar4 >> 0x10);
  puVar6[-6] = (char)(uVar4 >> 0x18);
                    /* WARNING: Could not recover jumptable at 0x0056855b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00568561
// Address: 00568561
// XREFS: None
void FUN_00568561(void)
{
  undefined1 in_AL;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = in_AL;
                    /* WARNING: Could not recover jumptable at 0x00568564. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_0056856a
// Address: 0056856a
// XREFS: None
void FUN_0056856a(void)
{
  undefined2 in_AX;
  int unaff_EDI;
  
  *(undefined2 *)(unaff_EDI + -1) = in_AX;
                    /* WARNING: Could not recover jumptable at 0x00568571. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00568577
// Address: 00568577
// XREFS: None
void FUN_00568577(void)
{
  undefined1 in_AL;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = in_AL;
  unaff_EDI[-1] = in_AL;
                    /* WARNING: Could not recover jumptable at 0x0056857d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00568583
// Address: 00568583
// XREFS: None
void FUN_00568583(void)
{
  undefined2 in_AX;
  undefined1 *unaff_EDI;
  
  *(undefined2 *)(unaff_EDI + -2) = in_AX;
  *unaff_EDI = (char)in_AX;
                    /* WARNING: Could not recover jumptable at 0x0056858c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_00568592
// Address: 00568592
// XREFS: None
void FUN_00568592(void)
{
  undefined2 in_AX;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = (char)in_AX;
  *(undefined2 *)(unaff_EDI + -2) = in_AX;
                    /* WARNING: Could not recover jumptable at 0x0056859c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005685a2
// Address: 005685a2
// XREFS: None
void FUN_005685a2(void)
{
  undefined4 in_EAX;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + -3) = in_EAX;
                    /* WARNING: Could not recover jumptable at 0x005685a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005685ae
// Address: 005685ae
// XREFS: None
void FUN_005685ae(void)
{
  undefined2 in_AX;
  undefined1 *unaff_EDI;
  
  *(undefined2 *)(unaff_EDI + -2) = in_AX;
  *unaff_EDI = (char)in_AX;
  unaff_EDI[-3] = (char)in_AX;
                    /* WARNING: Could not recover jumptable at 0x005685ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005685c0
// Address: 005685c0
// XREFS: None
void FUN_005685c0(void)
{
  undefined2 in_AX;
  int unaff_EDI;
  
  *(undefined2 *)(unaff_EDI + -1) = in_AX;
  *(undefined2 *)(unaff_EDI + -3) = in_AX;
                    /* WARNING: Could not recover jumptable at 0x005685ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005685d4
// Address: 005685d4
// XREFS: None
void FUN_005685d4(void)
{
  undefined2 in_AX;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = (char)in_AX;
  *(undefined2 *)(unaff_EDI + -3) = in_AX;
  unaff_EDI[-1] = (char)in_AX;
                    /* WARNING: Could not recover jumptable at 0x005685e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

// Function: FUN_005685e6
// Address: 005685e6
// XREFS: None
void FUN_005685e6(void)
{
  undefined4 in_EAX;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + -3) = in_EAX;
  *(char *)(unaff_EDI + -4) = (char)in_EAX;
                    /* WARNING: Could not recover jumptable at 0x005685ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0088c044._0_4_)();
  return;
}

// --------------------------------------------------

