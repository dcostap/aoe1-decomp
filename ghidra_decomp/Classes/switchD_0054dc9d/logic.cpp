// Class: switchD_0054dc9d
// Function: caseD_1
// Address: 0054dcb8
void __fastcall switchD_0054dc9d::caseD_1(uint param_1,uint param_2)
{
  uint uVar1;
  int unaff_ESI;
  undefined4 *puVar2;
  int unaff_EDI;
  undefined4 *puVar3;
  
  *(undefined1 *)(unaff_EDI + 3) = *(undefined1 *)(unaff_ESI + 3);
  puVar2 = (undefined4 *)(unaff_ESI + -1);
  uVar1 = param_1 >> 2;
  puVar3 = (undefined4 *)(unaff_EDI + -1);
  switch(uVar1) {
  case 7:
    *(undefined4 *)(unaff_EDI + 0x1b + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0x1b + uVar1 * -4);
  case 6:
    *(undefined4 *)(unaff_EDI + 0x17 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0x17 + uVar1 * -4);
  case 5:
    *(undefined4 *)(unaff_EDI + 0x13 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0x13 + uVar1 * -4);
  case 4:
    *(undefined4 *)(unaff_EDI + 0xf + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0xf + uVar1 * -4);
  case 3:
    *(undefined4 *)(unaff_EDI + 0xb + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 0xb + uVar1 * -4);
  case 2:
    *(undefined4 *)(unaff_EDI + 7 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 7 + uVar1 * -4);
  case 1:
    *(undefined4 *)(unaff_EDI + 3 + uVar1 * -4) = *(undefined4 *)(unaff_ESI + 3 + uVar1 * -4);
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
                    /* WARNING: Could not recover jumptable at 0x0054dcce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0054dc77::switchdataD_0054dda0)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

