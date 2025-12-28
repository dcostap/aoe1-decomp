// Class: switchD_0054db0d
// Size:  0x0
//
// Member Layout:
// ----------------------------------------------------------------

// Function: caseD_1
// Address: 0054db30
void __fastcall switchD_0054db0d::caseD_1(uint param_1,uint param_2)
{
  uint uVar1;
  undefined1 *unaff_ESI;
  undefined4 *puVar2;
  undefined1 *unaff_EDI;
  undefined4 *puVar3;
  
  *unaff_EDI = *unaff_ESI;
  unaff_EDI[1] = unaff_ESI[1];
  uVar1 = param_1 >> 2;
  unaff_EDI[2] = unaff_ESI[2];
  puVar2 = (undefined4 *)(unaff_ESI + 3);
  puVar3 = (undefined4 *)(unaff_EDI + 3);
  switch(uVar1) {
  case 7:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0x19) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0x19);
  case 6:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0x15) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0x15);
  case 5:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0x11) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0x11);
  case 4:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -0xd) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -0xd);
  case 3:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -9) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -9);
  case 2:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -5) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -5);
  case 1:
    *(undefined4 *)(unaff_EDI + uVar1 * 4 + -1) = *(undefined4 *)(unaff_ESI + uVar1 * 4 + -1);
  case 0:
    (*(code *)(&switchD_0054daf5::switchdataD_0054dc08)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    (*(code *)(&switchD_0054daf5::switchdataD_0054dc08)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

