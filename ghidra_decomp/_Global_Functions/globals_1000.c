// GLOBAL FUNCTIONS PART 1000
// Function: FUN_0055740b
// Address: 0055740b
// XREFS: None
void __fastcall FUN_0055740b(int param_1)
{
                    /* WARNING: Could not recover jumptable at 0x0055740c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&switchD_0055740c::switchdataD_0055748c)[param_1])();
  return;
}

// --------------------------------------------------

// Function: FUN_00557413
// Address: 00557413
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_00557413(uint param_1,uint param_2)
{
  uint *puVar1;
  byte *pbVar2;
  int in_EAX;
  uint uVar3;
  byte bVar4;
  char *unaff_EBX;
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined4 *puVar5;
  undefined1 *unaff_EDI;
  undefined4 *puVar6;
  
  pbVar2 = (byte *)(unaff_EBP + param_2 * 2);
  bVar4 = (byte)(param_2 >> 8);
  *pbVar2 = *pbVar2 & bVar4;
  if (&stack0x00000000 != (undefined1 *)0x1) {
    *(char *)(in_EAX + 0x74) = *(char *)(in_EAX + 0x74) + bVar4;
    *unaff_EBX = *unaff_EBX + (char)((uint)in_EAX >> 8);
    puVar1 = (uint *)(param_2 + 0x8a078806);
    *puVar1 = *puVar1 >> 1 | (uint)((*puVar1 & 1) != 0) << 0x1f;
    *(int *)(in_EAX + 0x468a0147) = *(int *)(in_EAX + 0x468a0147) + param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *unaff_EDI = *unaff_ESI;
  uVar3 = param_1 >> 2;
  puVar5 = (undefined4 *)(unaff_ESI + 1);
  puVar6 = (undefined4 *)(unaff_EDI + 1);
  switch(uVar3) {
  case 7:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -0x1b) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -0x1b);
  case 6:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -0x17) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -0x17);
  case 5:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -0x13) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -0x13);
  case 4:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -0xf) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -0xf);
  case 3:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -0xb) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -0xb);
  case 2:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -7) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -7);
  case 1:
    *(undefined4 *)(unaff_EDI + uVar3 * 4 + -3) = *(undefined4 *)(unaff_ESI + uVar3 * 4 + -3);
  case 0:
                    /* WARNING: Could not recover jumptable at 0x005574ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  default:
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00557482. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_00557449
// Address: 00557449
// XREFS: None
void __fastcall FUN_00557449(uint param_1,uint param_2)
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
                    /* WARNING: Could not recover jumptable at 0x005574ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00557468. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_0055746f
// Address: 0055746f
// XREFS: None
void __fastcall FUN_0055746f(uint param_1,uint param_2)
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
                    /* WARNING: Could not recover jumptable at 0x005574ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00557482. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_00557489
// Address: 00557489
// XREFS: None
/* WARNING: Instruction at (ram,0x005574f4) overlaps instruction at (ram,0x005574ef)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */

char * __fastcall FUN_00557489(uint param_1,uint param_2)
{
  char *pcVar1;
  char cVar2;
  char cVar4;
  uint in_EAX;
  undefined2 uVar5;
  char *pcVar3;
  char cVar6;
  char *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  bool in_ZF;
  bool bVar7;
  
  out((short)param_2,in_EAX);
  if (in_ZF) {
code_r0x005574e4:
                    /* WARNING: Could not recover jumptable at 0x005574ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar3 = (char *)(*(code *)(&switchD_005573e5::switchdataD_005574f8)[param_2])();
    return pcVar3;
  }
  uVar5 = (undefined2)(in_EAX >> 0x10);
  cVar2 = (char)in_EAX;
  cVar4 = (char)(in_EAX >> 8) + (char)unaff_EBX;
  pcVar3 = (char *)CONCAT22(uVar5,CONCAT11(cVar4,cVar2));
  if (cVar4 == '\0') {
    *pcVar3 = *pcVar3 + cVar2;
    *unaff_EBX = *unaff_EBX + cVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cVar4 = cVar4 + (char)param_2;
  if (cVar4 == '\0') {
    halt_baddata();
  }
  cVar6 = (char)param_1;
  cVar4 = cVar4 + cVar6;
  if (cVar4 == '\0') {
    pcVar3 = (char *)(CONCAT31((int3)(CONCAT22(uVar5,CONCAT11(cVar4,cVar2)) >> 8),cVar2) &
                     0xffffff95);
    if ((in_EAX & 0x95) != 0) goto code_r0x005574f5;
    unaff_EDI = (undefined4 *)((param_1 - 4) + (int)unaff_EDI);
    bVar7 = ((uint)unaff_EDI & 3) == 0;
  }
  else {
    pcVar3 = (char *)CONCAT22(uVar5,CONCAT11(cVar4 + cVar2,cVar2));
    if ((char)(cVar4 + cVar2) != '\0') {
      (&stack0x74b40055)[(int)unaff_ESI * 2] =
           (&stack0x74b40055)[(int)unaff_ESI * 2] + (char)((uint)unaff_EBX >> 8);
      (&stack0x448b0051)[(int)unaff_ESI * 2] =
           (&stack0x448b0051)[(int)unaff_ESI * 2] + (char)(param_1 >> 8);
      unaff_EDI[param_1 - 7] = pcVar3;
      unaff_EDI[param_1 - 6] = unaff_ESI[param_1 - 6];
      unaff_EDI[param_1 - 5] = unaff_ESI[param_1 - 5];
      unaff_EDI[param_1 - 4] = unaff_ESI[param_1 - 4];
      unaff_EDI[param_1 - 3] = unaff_ESI[param_1 - 3];
      unaff_EDI[param_1 - 2] = unaff_ESI[param_1 - 2];
      unaff_EDI[param_1 - 1] = unaff_ESI[param_1 - 1];
      goto code_r0x005574e4;
    }
code_r0x005574f5:
    unaff_EBX[0x557508c0] = unaff_EBX[0x557508c0] + cVar6;
    *pcVar3 = *pcVar3 + (char)param_2;
    if (*pcVar3 == '\0') {
      pcVar1 = (char *)((int)unaff_ESI * 2 + 0x75300055);
      *pcVar1 = *pcVar1 + (char)unaff_EBX;
      unaff_EBX[0x5f5e0845] = unaff_EBX[0x5f5e0845] + cVar6;
      return pcVar3;
    }
    *pcVar3 = *pcVar3 + (char)pcVar3;
    bVar7 = *pcVar3 == '\0';
  }
  if (bVar7) {
    param_1 = param_1 >> 2;
    param_2 = param_2 & 3;
    if (7 < param_1) {
      for (; param_1 != 0; param_1 = param_1 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(param_2) {
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
      goto switchD_00557567_caseD_0;
    }
  }
  else {
    switch(param_1) {
    case 0:
      goto switchD_00557567_caseD_0;
    case 1:
      goto switchD_00557567_caseD_1;
    case 2:
      goto switchD_00557567_caseD_2;
    case 3:
      goto switchD_00557567_caseD_3;
    default:
      param_1 = param_1 - ((uint)unaff_EDI & 3);
      switch((uint)unaff_EDI & 3) {
      case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 1:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -1);
        param_1 = param_1 >> 2;
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -1);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
        break;
      case 2:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        param_1 = param_1 >> 2;
        *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -2);
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -2);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
        break;
      case 3:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
        param_1 = param_1 >> 2;
        *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -3);
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -3);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
      }
    }
  }
  switch(param_1) {
  case 7:
    unaff_EDI[7 - param_1] = unaff_ESI[7 - param_1];
  case 6:
    unaff_EDI[6 - param_1] = unaff_ESI[6 - param_1];
  case 5:
    unaff_EDI[5 - param_1] = unaff_ESI[5 - param_1];
  case 4:
    unaff_EDI[4 - param_1] = unaff_ESI[4 - param_1];
  case 3:
    unaff_EDI[3 - param_1] = unaff_ESI[3 - param_1];
  case 2:
    unaff_EDI[2 - param_1] = unaff_ESI[2 - param_1];
  case 1:
    unaff_EDI[1 - param_1] = unaff_ESI[1 - param_1];
    unaff_ESI = unaff_ESI + -param_1;
    unaff_EDI = unaff_EDI + -param_1;
  }
  switch(param_2) {
  case 1:
switchD_00557567_caseD_1:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    return *(char **)(unaff_EBP + 8);
  case 2:
switchD_00557567_caseD_2:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    return *(char **)(unaff_EBP + 8);
  case 3:
switchD_00557567_caseD_3:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
    return *(char **)(unaff_EBP + 8);
  }
switchD_00557567_caseD_0:
  return *(char **)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_005574f6
// Address: 005574f6
// XREFS: None
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Control flow encountered bad instruction data */

char * __fastcall FUN_005574f6(uint param_1,uint param_2)
{
  char *pcVar1;
  char *in_EAX;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *(byte *)(unaff_EBP + 0x55) = *(byte *)(unaff_EBP + 0x55) | (byte)(param_2 >> 8);
  *in_EAX = *in_EAX + (char)param_2;
  if (*in_EAX == '\0') {
    pcVar1 = (char *)((int)unaff_ESI * 2 + 0x75300055);
    *pcVar1 = *pcVar1 + (char)unaff_EBX;
    *(char *)(unaff_EBX + 0x5f5e0845) = *(char *)(unaff_EBX + 0x5f5e0845) + (char)param_1;
    return in_EAX;
  }
  *in_EAX = *in_EAX + (char)in_EAX;
  if (*in_EAX == '\0') {
    param_1 = param_1 >> 2;
    param_2 = param_2 & 3;
    if (7 < param_1) {
      for (; param_1 != 0; param_1 = param_1 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(param_2) {
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
      goto switchD_00557567_caseD_0;
    }
  }
  else {
    switch(param_1) {
    case 0:
      goto switchD_00557567_caseD_0;
    case 1:
      goto switchD_00557567_caseD_1;
    case 2:
      goto switchD_00557567_caseD_2;
    case 3:
      goto switchD_00557567_caseD_3;
    default:
      param_1 = param_1 - ((uint)unaff_EDI & 3);
      switch((uint)unaff_EDI & 3) {
      case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 1:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -1);
        param_1 = param_1 >> 2;
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -1);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
        break;
      case 2:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        param_1 = param_1 >> 2;
        *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -2);
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -2);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
        break;
      case 3:
        param_2 = param_1 & 3;
        *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
        *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
        param_1 = param_1 >> 2;
        *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
        unaff_ESI = (undefined4 *)((int)unaff_ESI + -3);
        unaff_EDI = (undefined4 *)((int)unaff_EDI + -3);
        if (7 < param_1) {
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *unaff_EDI = *unaff_ESI;
            unaff_ESI = unaff_ESI + -1;
            unaff_EDI = unaff_EDI + -1;
          }
          switch(param_2) {
          case 1:
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
        }
      }
    }
  }
  switch(param_1) {
  case 7:
    unaff_EDI[7 - param_1] = unaff_ESI[7 - param_1];
  case 6:
    unaff_EDI[6 - param_1] = unaff_ESI[6 - param_1];
  case 5:
    unaff_EDI[5 - param_1] = unaff_ESI[5 - param_1];
  case 4:
    unaff_EDI[4 - param_1] = unaff_ESI[4 - param_1];
  case 3:
    unaff_EDI[3 - param_1] = unaff_ESI[3 - param_1];
  case 2:
    unaff_EDI[2 - param_1] = unaff_ESI[2 - param_1];
  case 1:
    unaff_EDI[1 - param_1] = unaff_ESI[1 - param_1];
    unaff_ESI = unaff_ESI + -param_1;
    unaff_EDI = unaff_EDI + -param_1;
  }
  switch(param_2) {
  case 1:
switchD_00557567_caseD_1:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    return *(char **)(unaff_EBP + 8);
  case 2:
switchD_00557567_caseD_2:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    return *(char **)(unaff_EBP + 8);
  case 3:
switchD_00557567_caseD_3:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
    return *(char **)(unaff_EBP + 8);
  }
switchD_00557567_caseD_0:
  return *(char **)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0055750f
// Address: 0055750f
// XREFS: None
undefined4 FUN_0055750f(void)
{
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI;
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0055751b
// Address: 0055751b
// XREFS: None
undefined4 FUN_0055751b(void)
{
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = *unaff_ESI;
  unaff_EDI[1] = unaff_ESI[1];
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0055752d
// Address: 0055752d
// XREFS: None
undefined4 FUN_0055752d(void)
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

// Function: FUN_00557547
// Address: 00557547
// XREFS: None
/* WARNING (jumptable): Stack frame is not setup normally: Input value of stackpointer is not used
    */

undefined4 __fastcall FUN_00557547(uint param_1,uint param_2)
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
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
      goto switchD_00557567_caseD_0;
    }
  }
  else {
    switch(param_1) {
    case 0:
      goto switchD_00557567_caseD_0;
    case 1:
      goto switchD_00557567_caseD_1;
    case 2:
      goto switchD_00557567_caseD_2;
    case 3:
      goto switchD_00557567_caseD_3;
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
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
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
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
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
            goto switchD_00557567_caseD_1;
          case 2:
            goto switchD_00557567_caseD_2;
          case 3:
            goto switchD_00557567_caseD_3;
          }
          goto switchD_00557567_caseD_0;
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
switchD_00557567_caseD_1:
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
    return *(undefined4 *)(unaff_EBP + 8);
  case 2:
switchD_00557567_caseD_2:
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar1 + 2);
    return *(undefined4 *)(unaff_EBP + 8);
  case 3:
switchD_00557567_caseD_3:
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar1 + 2);
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)puVar1 + 1);
    return *(undefined4 *)(unaff_EBP + 8);
  }
switchD_00557567_caseD_0:
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_0055756e
// Address: 0055756e
// XREFS: None
void __fastcall FUN_0055756e(int param_1)
{
                    /* WARNING: Could not recover jumptable at 0x00557572. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_caseD_0_00557640)[-param_1])();
  return;
}

// --------------------------------------------------

// Function: FUN_00557579
// Address: 00557579
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Stack frame is not setup normally: Input value of stackpointer is not used
    */

undefined4 __fastcall FUN_00557579(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  switch(param_1) {
  case 0:
    goto switchD_00557567_caseD_0;
  case 1:
switchD_00557567_caseD_1:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    return *(undefined4 *)(unaff_EBP + 8);
  case 2:
switchD_00557567_caseD_2:
    *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
    *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
    return *(undefined4 *)(unaff_EBP + 8);
  case 3:
switchD_00557567_caseD_3:
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
LAB_00557570:
                    /* WARNING: Could not recover jumptable at 0x00557572. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*(code *)(&PTR_caseD_0_00557640)[-(uVar2 >> 2)])();
        return uVar1;
      }
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(uVar2 & 3) {
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
      break;
    case 2:
      *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
      uVar3 = uVar2 >> 2;
      *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
      unaff_ESI = (undefined4 *)((int)unaff_ESI + -2);
      unaff_EDI = (undefined4 *)((int)unaff_EDI + -2);
      if (uVar3 < 8) goto LAB_00557570;
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(uVar2 & 3) {
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
      break;
    case 3:
      *(undefined1 *)((int)unaff_EDI + 3) = *(undefined1 *)((int)unaff_ESI + 3);
      *(undefined1 *)((int)unaff_EDI + 2) = *(undefined1 *)((int)unaff_ESI + 2);
      uVar3 = uVar2 >> 2;
      *(undefined1 *)((int)unaff_EDI + 1) = *(undefined1 *)((int)unaff_ESI + 1);
      unaff_ESI = (undefined4 *)((int)unaff_ESI + -3);
      unaff_EDI = (undefined4 *)((int)unaff_EDI + -3);
      if (uVar3 < 8) goto LAB_00557570;
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *unaff_EDI = *unaff_ESI;
        unaff_ESI = unaff_ESI + -1;
        unaff_EDI = unaff_EDI + -1;
      }
      switch(uVar2 & 3) {
      case 1:
        goto switchD_00557567_caseD_1;
      case 2:
        goto switchD_00557567_caseD_2;
      case 3:
        goto switchD_00557567_caseD_3;
      }
    }
switchD_00557567_caseD_0:
    return *(undefined4 *)(unaff_EBP + 8);
  }
}

// --------------------------------------------------

// Function: FUN_0055759b
// Address: 0055759b
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x005575fe) overlaps instruction at (ram,0x005575fd)
    */

void __fastcall FUN_0055759b(uint param_1,int param_2)
{
  undefined4 in_EAX;
  char cVar1;
  uint uVar2;
  char cVar3;
  int unaff_ESI;
  undefined4 *puVar4;
  int unaff_EDI;
  undefined4 *puVar5;
  
  cVar1 = (char)param_1;
  if ((char)((char)in_EAX + cVar1) == '\0') {
    cVar3 = (char)((uint)param_2 >> 8);
    if (cVar3 != '\0') {
      *(byte *)(unaff_EDI + 1) =
           *(byte *)(unaff_EDI + 1) |
           cVar1 + *(char *)(param_2 + -0x163efeba) +
           *(char *)(CONCAT31((int3)((uint)in_EAX >> 8),cVar3) + -0x117cfeb9);
      *(char *)(param_2 + -1) = *(char *)(param_2 + -1) + '\x01';
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *(char *)(param_2 + -0x2edcfcba) = *(char *)(param_2 + -0x2edcfcba) + cVar1;
    *(undefined1 *)(unaff_EDI + 3) = 0;
    puVar4 = (undefined4 *)(unaff_ESI + -1);
    uVar2 = param_1 >> 2;
    puVar5 = (undefined4 *)(unaff_EDI + -1);
    if (7 < uVar2) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar5 = puVar5 + -1;
      }
                    /* WARNING: Could not recover jumptable at 0x005575be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2])();
      return;
    }
  }
  else {
    *(undefined1 *)(unaff_EDI + 2) = *(undefined1 *)(unaff_ESI + 2);
    uVar2 = param_1 >> 2;
    *(undefined1 *)(unaff_EDI + 1) = *(undefined1 *)(unaff_ESI + 1);
    puVar4 = (undefined4 *)(unaff_ESI + -3);
    puVar5 = (undefined4 *)(unaff_EDI + -3);
    if (7 < uVar2) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar5 = puVar5 + -1;
      }
                    /* WARNING: Could not recover jumptable at 0x0055761a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2])();
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00557572. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_caseD_0_00557640)[-(param_1 >> 2)])();
  return;
}

// --------------------------------------------------

// Function: FUN_005575c5
// Address: 005575c5
// XREFS: None
void __fastcall FUN_005575c5(uint param_1,uint param_2)
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
                    /* WARNING: Could not recover jumptable at 0x00557687. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + -1;
      puVar3 = puVar3 + -1;
    }
                    /* WARNING: Could not recover jumptable at 0x005575e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_005575ef
// Address: 005575ef
// XREFS: None
void __fastcall FUN_005575ef(uint param_1,uint param_2)
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
                    /* WARNING: Could not recover jumptable at 0x00557687. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2 & param_1])();
    return;
  default:
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + -1;
      puVar3 = puVar3 + -1;
    }
                    /* WARNING: Could not recover jumptable at 0x0055761a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2 & param_1])();
    return;
  }
}

// --------------------------------------------------

// Function: FUN_00557621
// Address: 00557621
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_00557621(undefined4 param_1,int param_2)
{
  char *pcVar1;
  undefined4 in_EAX;
  char unaff_BL;
  int unaff_ESI;
  int unaff_EDI;
  bool in_CF;
  
  if (!in_CF && &stack0x00000000 != (undefined1 *)0xffffffff) {
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + (char)param_1;
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + (char)param_2;
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + unaff_BL;
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + (char)((uint)in_EAX >> 8);
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + (char)((uint)param_1 >> 8);
    pcVar1 = (char *)(unaff_ESI * 3 + 0x55);
    *pcVar1 = *pcVar1 + (char)((uint)param_2 >> 8);
    *(char *)(unaff_EDI + -0x74ffaa8a) = *(char *)(unaff_EDI + -0x74ffaa8a) + (char)in_EAX;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Could not recover jumptable at 0x00557687. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&switchD_00557567::switchdataD_00557690)[param_2])();
  return;
}

// --------------------------------------------------

// Function: FUN_0055768e
// Address: 0055768e
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_0055768e(char param_1)
{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 in_EAX;
  byte bVar4;
  int unaff_EBX;
  bool in_CF;
  bool in_ZF;
  
  if (in_CF || in_ZF) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  pbVar1 = (byte *)(CONCAT31((int3)((uint)in_EAX >> 8),uRama8005576) + -0x33ffaa8a);
  bVar2 = *pbVar1;
  bVar4 = (byte)((uint)unaff_EBX >> 8);
  *pbVar1 = *pbVar1 + bVar4;
  if (!CARRY1(bVar2,bVar4) && *pbVar1 != 0) {
    *(char *)(unaff_EBX + 0x5f5e0845) = *(char *)(unaff_EBX + 0x5f5e0845) + param_1;
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_005576a7
// Address: 005576a7
// XREFS: None
undefined4 FUN_005576a7(void)
{
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 3) = *(undefined1 *)(unaff_ESI + 3);
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_005576b5
// Address: 005576b5
// XREFS: None
undefined4 FUN_005576b5(void)
{
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 3) = *(undefined1 *)(unaff_ESI + 3);
  *(undefined1 *)(unaff_EDI + 2) = *(undefined1 *)(unaff_ESI + 2);
  return *(undefined4 *)(unaff_EBP + 8);
}

// --------------------------------------------------

// Function: FUN_005576cb
// Address: 005576cb
// XREFS: None
undefined4 FUN_005576cb(void)
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

// Function: abort
// Address: 005576f0
// XREFS: FUN_005504fe
/* abort */

void __cdecl abort(void)
{
  __NMSG_WRITE(10);
  raise(0x16);
  __exit(3);
  return;
}

// --------------------------------------------------

// Function: __statusfp
// Address: 00557710
// XREFS: None
void __statusfp(void)
{
  FUN_00557910();
  return;
}

// --------------------------------------------------

// Function: __clearfp
// Address: 00557730
// XREFS: None
void __clearfp(void)
{
  FUN_00557910();
  return;
}

// --------------------------------------------------

// Function: __control87
// Address: 00557750
// XREFS: __controlfp
uint __control87(uint param_1,uint param_2)
{
  uint uVar1;
  
  uVar1 = FUN_005577e0();
  uVar1 = param_2 & param_1 | ~param_2 & uVar1;
  FUN_00557880(uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: __controlfp
// Address: 00557790
// XREFS: __setdefaultprecision
void __controlfp(undefined4 param_1,uint param_2)
{
  __control87(param_1,param_2 & 0xfff7ffff);
  return;
}

// --------------------------------------------------

// Function: FUN_005577a8
// Address: 005577a8
// XREFS: None
void FUN_005577a8(void)
{
  uint *puVar1;
  int iVar2;
  
  iVar2 = __pxcptinfoptrs;
  __setdefaultprecision();
  if ((iVar2 != 0) && (puVar1 = *(uint **)(iVar2 + 4), (*puVar1 & 0x10008) != 0)) {
    puVar1[8] = 0;
    puVar1[9] = 0xffff;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005577e0
// Address: 005577e0
// XREFS: __control87
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

// --------------------------------------------------

// Function: FUN_00557880
// Address: 00557880
// XREFS: __control87
void FUN_00557880(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00557910
// Address: 00557910
// XREFS: __clearfp, __statusfp
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

// --------------------------------------------------

// Function: __ZeroTail
// Address: 00557950
// XREFS: __RoundMan
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

// --------------------------------------------------

// Function: __IncMan
// Address: 005579c0
// XREFS: __RoundMan
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

// --------------------------------------------------

// Function: __RoundMan
// Address: 00557a30
// XREFS: __ld12cvt, __ld12told
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

// --------------------------------------------------

// Function: __CopyMan
// Address: 00557ad0
// XREFS: __ld12cvt
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

// --------------------------------------------------

// Function: __FillZeroMan
// Address: 00557af0
// XREFS: __ld12cvt
void __FillZeroMan(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

// --------------------------------------------------

// Function: __IsZeroMan
// Address: 00557b00
// XREFS: __ld12cvt
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

// --------------------------------------------------

// Function: __ShrMan
// Address: 00557b20
// XREFS: __ld12cvt
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

// --------------------------------------------------

// Function: __ld12cvt
// Address: 00557be0
// XREFS: __ld12tod, __ld12tof
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

// --------------------------------------------------

// Function: __ld12tod
// Address: 00557db0
// XREFS: __atodbl, __fltin
void __ld12tod(undefined4 param_1,undefined4 param_2)
{
  __ld12cvt(param_1,param_2,&DAT_00592690);
  return;
}

// --------------------------------------------------

// Function: __ld12tof
// Address: 00557dd0
// XREFS: __atoflt
void __ld12tof(undefined4 param_1,undefined4 param_2)
{
  __ld12cvt(param_1,param_2,&DAT_005926a8);
  return;
}

// --------------------------------------------------

// Function: __ld12told
// Address: 00557df0
// XREFS: FUN_00557ea8
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

// --------------------------------------------------

// Function: __atodbl
// Address: 00557e70
// XREFS: FUN_0055074c
void __atodbl(undefined4 param_1,undefined4 param_2)
{
  undefined1 local_c [12];
  
  ___strgtold12(local_c,&param_2,param_2,0,0,0,0);
  __ld12tod(local_c,param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00557ea8
// Address: 00557ea8
// XREFS: None
void FUN_00557ea8(undefined4 param_1,undefined4 param_2)
{
  undefined1 local_c [12];
  
  ___strgtold12(local_c,&param_2,param_2,1,0,0,0);
  __ld12told(local_c,param_1);
  return;
}

// --------------------------------------------------

// Function: __atoflt
// Address: 00557ef0
// XREFS: FUN_0055074c
void __atoflt(undefined4 param_1,undefined4 param_2)
{
  undefined1 local_c [12];
  
  ___strgtold12(local_c,&param_2,param_2,0,0,0,0);
  __ld12tof(local_c,param_1);
  return;
}

// --------------------------------------------------

// Function: __fptostr
// Address: 00557f30
// XREFS: __cftoe, __cftof, __cftog
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

// --------------------------------------------------

// Function: __fltout
// Address: 00557fd0
// XREFS: __cftoe, __cftof, __cftog
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

// --------------------------------------------------

// Function: ___dtold
// Address: 00558050
// XREFS: __fltout
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

// --------------------------------------------------

// Function: __fptrap
// Address: 00558110
// XREFS: PTR___fptrap_0058fbcc, PTR___fptrap_0058fbd0, PTR___fptrap_0058fbd4, PTR___fptrap_0058fbd8, PTR___fptrap_0058fbdc, __cfltcvt_tab, __input, __output
void __fptrap(void)
{
  __amsg_exit(2);
  return;
}

// --------------------------------------------------

// Function: __isatty
// Address: 00558120
// XREFS: __flsbuf, __stbuf
byte __isatty(uint param_1)
{
  if (__nhandle <= param_1) {
    return 0;
  }
  return *(byte *)((&___pioinfo)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 0x40;
}

// --------------------------------------------------

// Function: wctomb
// Address: 00558150
// XREFS: __output
/* wctomb */

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

// --------------------------------------------------

// Function: __aulldiv
// Address: 005581d0
// XREFS: FUN_0055be70, __output
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

// --------------------------------------------------

// Function: __aullrem
// Address: 00558240
// XREFS: FUN_0055be70, __output
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

// --------------------------------------------------

// Function: mbtowc
// Address: 005582c0
// XREFS: __input
/* mbtowc */

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

// --------------------------------------------------

// Function: __allshl
// Address: 005583c0
// XREFS: __input
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

// --------------------------------------------------

// Function: ungetc
// Address: 005583e0
// XREFS: FUN_00553070
/* ungetc */

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

// --------------------------------------------------

// Function: __getbuf
// Address: 00558470
// XREFS: __filbuf, __flsbuf, ungetc
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

// --------------------------------------------------

// Function: wcstombs
// Address: 005584d0
// XREFS: __tzset
/* wcstombs */

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

// --------------------------------------------------

// Function: FUN_005586c0
// Address: 005586c0
// XREFS: wcstombs
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

// --------------------------------------------------

// Function: getenv
// Address: 00558700
// XREFS: __tzset
/* getenv */

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

// --------------------------------------------------

// Function: FUN_0055878e
// Address: 0055878e
// XREFS: None
int FUN_0055878e(void)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 3;
  iVar3 = 0;
  if (3 < __nstream) {
    do {
      iVar1 = *(int *)(___piob + iVar2 * 4);
      if (iVar1 != 0) {
        if (((*(byte *)(iVar1 + 0xc) & 0x83) != 0) && (iVar1 = fclose(iVar1), iVar1 != -1)) {
          iVar3 = iVar3 + 1;
        }
        if (0x13 < iVar2) {
          free(*(undefined4 *)(___piob + iVar2 * 4));
          *(undefined4 *)(___piob + iVar2 * 4) = 0;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < __nstream);
  }
  return iVar3;
}

// --------------------------------------------------

// Function: __mbbtype
// Address: 00558800
// XREFS: __mbsbtype
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

// --------------------------------------------------

// Function: FUN_0055885e
// Address: 0055885e
// XREFS: None
int __fastcall FUN_0055885e(char *param_1,char param_2)
{
  uint uVar1;
  byte bVar2;
  undefined4 in_EAX;
  undefined3 uVar4;
  char *pcVar3;
  byte bVar5;
  int unaff_EBX;
  char *unaff_EBP;
  
  uVar4 = (undefined3)((uint)in_EAX >> 8);
  pcVar3 = (char *)(CONCAT31(uVar4,(char)in_EAX + 'x') + (int)param_1 * 4);
  *pcVar3 = *pcVar3 + (char)((uint)param_1 >> 8);
  *param_1 = *param_1 + param_2;
  *unaff_EBP = param_2;
  bVar2 = (char)in_EAX - 0x10;
  *(char *)(unaff_EBX + -0x74fbdbbc) = *(char *)(unaff_EBX + -0x74fbdbbc) + (char)param_1;
  pcVar3 = (char *)(CONCAT31(uVar4,bVar2) | 0x8885e0);
  if (pcVar3 < param_1) {
    uVar1 = bVar2 & 0x1f;
    bVar2 = *(byte *)((&___pioinfo)[(int)pcVar3 >> 5] + 4 + uVar1 * 8);
    if ((bVar2 & 1) != 0) {
      if (unaff_EBP == (char *)0x8000) {
        bVar5 = bVar2 & 0x7f;
      }
      else {
        if (unaff_EBP != (char *)0x4000) {
          _errno = 0x16;
          return -1;
        }
        bVar5 = bVar2 | 0x80;
      }
      *(byte *)((&___pioinfo)[(int)pcVar3 >> 5] + 4 + uVar1 * 8) = bVar5;
      return (-(uint)((bVar2 & 0x80) != 0) & 0xffffc000) + 0x8000;
    }
  }
  _errno = 9;
  return -1;
}

// --------------------------------------------------

// Function: __setmode
// Address: 00558870
// XREFS: __chsize
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

// --------------------------------------------------

// Function: ___strgtold12
// Address: 005588f0
// XREFS: FUN_00557ea8, __atodbl, __atoflt, __fltin
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
// XREFS: __umatherr
undefined4 __matherr(void)
{
  return 0;
}

// --------------------------------------------------

// Function: wcslen
// Address: 005590e0
// XREFS: FUN_00556d0f, wcstombs
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

// Function: ___crtMessageBoxA
// Address: 00559100
// XREFS: __NMSG_WRITE
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
// XREFS: None
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
// XREFS: None
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

// Function: raise
// Address: 00559350
// XREFS: abort
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
// XREFS: None
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
// XREFS: FUN_0055918f, raise
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

// Function: ___addl
// Address: 00559520
// XREFS: __IncMan, ___add_12, ___ld12mul
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

// Function: ___add_12
// Address: 00559550
// XREFS: _$I10_OUTPUT, ___mtold12
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

// Function: ___shl_12
// Address: 005595c0
// XREFS: _$I10_OUTPUT, ___ld12mul, ___mtold12
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

// Function: ___shr_12
// Address: 005595f0
// XREFS: _$I10_OUTPUT, ___ld12mul
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

// Function: ___mtold12
// Address: 00559620
// XREFS: ___strgtold12
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

// Function: _$I10_OUTPUT
// Address: 00559720
// XREFS: __fltout
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

// Function: __mbsnbicoll
// Address: 00559ab0
// XREFS: FUN_0055a620, getenv
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

// Function: ___wtomb_environ
// Address: 00559af0
// XREFS: ___crtsetenv, getenv
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

// Function: ___ld12mul
// Address: 00559b70
// XREFS: _$I10_OUTPUT, ___multtenpow12
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

// Function: ___multtenpow12
// Address: 00559e30
// XREFS: _$I10_OUTPUT, ___strgtold12
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
// XREFS: None
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

// Function: FUN_0055a0d0
// Address: 0055a0d0
// XREFS: FUN_00559eba
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

// Function: ___crtCompareStringA
// Address: 0055a110
// XREFS: __mbsnbicoll
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

// Function: FUN_0055a3e0
// Address: 0055a3e0
// XREFS: ___crtCompareStringA
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

// Function: ___crtsetenv
// Address: 0055a410
// XREFS: ___wtomb_environ
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

// Function: FUN_0055a620
// Address: 0055a620
// XREFS: ___crtsetenv
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

// Function: FUN_0055a6a0
// Address: 0055a6a0
// XREFS: ___crtsetenv
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

// Function: __strdup
// Address: 0055a710
// XREFS: FUN_0055a6a0
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

// Function: _WSAStartup@8
// Address: 0055bae0
// XREFS: RGE_Communications_Addresses
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
// XREFS: ~RGE_Communications_Addresses
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
// XREFS: GetHostName
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
// XREFS: SetIPAddresses, SetIPAliases
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
// XREFS: _UnwindNestedFrames, __global_unwind2
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: None
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
// XREFS: get_palette
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

// Function: itoa
// Address: 0055bd00
// XREFS: action, load_multi_victory_cond_from_scenario, load_victory_cond_from_scenario, set_mode
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

// Function: FUN_0055bd40
// Address: 0055bd40
// XREFS: FUN_0055bda1, FUN_0055bdf1, itoa
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
// XREFS: None
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
// XREFS: None
undefined4 FUN_0055bdf1(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_0055bd40(param_1,param_2,param_3,0);
  return param_2;
}

// --------------------------------------------------

// Function: FUN_0055be1e
// Address: 0055be1e
// XREFS: None
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

// Function: FUN_0055be70
// Address: 0055be70
// XREFS: FUN_0055be1e, FUN_0055bef1
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
// XREFS: None
undefined4 FUN_0055bef1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  FUN_0055be70(param_1,param_2,param_3,param_4,0);
  return param_3;
}

// --------------------------------------------------

// Function: FUN_0055c0a5
// Address: 0055c0a5
// XREFS: None
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
// XREFS: RGE_Action_Attack
void FUN_0055c0b8(void)
{
                    /* Symbol Ref: {@symbol $L35546} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c0d8
// Address: 0055c0d8
// XREFS: RGE_Action_Attack
void FUN_0055c0d8(void)
{
                    /* Symbol Ref: {@symbol $L35565} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c106
// Address: 0055c106
// XREFS: set_state
void FUN_0055c106(void)
{
                    /* Symbol Ref: {@symbol $L35602} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c110
// Address: 0055c110
// XREFS: None
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
// XREFS: update
void FUN_0055c11b(void)
{
                    /* Symbol Ref: {@symbol $L34851} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c138
// Address: 0055c138
// XREFS: RGE_Action_Enter
void FUN_0055c138(void)
{
                    /* Symbol Ref: {@symbol $L34529} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c15b
// Address: 0055c15b
// XREFS: set_state
void FUN_0055c15b(void)
{
                    /* Symbol Ref: {@symbol $L34551} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c17b
// Address: 0055c17b
// XREFS: set_state
void FUN_0055c17b(void)
{
                    /* Symbol Ref: {@symbol $L33615} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c198
// Address: 0055c198
// XREFS: RGE_Action_Gather
void FUN_0055c198(void)
{
                    /* Symbol Ref: {@symbol $L35503} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c1b8
// Address: 0055c1b8
// XREFS: RGE_Action_Gather
void FUN_0055c1b8(void)
{
                    /* Symbol Ref: {@symbol $L35525} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c1f1
// Address: 0055c1f1
// XREFS: set_state
void FUN_0055c1f1(void)
{
                    /* Symbol Ref: {@symbol $L35560} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c24d
// Address: 0055c24d
// XREFS: create_action
void FUN_0055c24d(void)
{
                    /* Symbol Ref: {@symbol $L34153} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c2ad
// Address: 0055c2ad
// XREFS: create_task_action
void FUN_0055c2ad(void)
{
                    /* Symbol Ref: {@symbol $L34207} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c2c8
// Address: 0055c2c8
// XREFS: RGE_Action_Missile
void FUN_0055c2c8(void)
{
                    /* Symbol Ref: {@symbol $L34841} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c2e8
// Address: 0055c2e8
// XREFS: RGE_Action_Missile
void FUN_0055c2e8(void)
{
                    /* Symbol Ref: {@symbol $L34863} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c308
// Address: 0055c308
// XREFS: RGE_Action_Move_To
void FUN_0055c308(void)
{
                    /* Symbol Ref: {@symbol $L34509} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c328
// Address: 0055c328
// XREFS: RGE_Action_Move_To
void FUN_0055c328(void)
{
                    /* Symbol Ref: {@symbol $L34533} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c348
// Address: 0055c348
// XREFS: ~RGE_Action_Move_To
void FUN_0055c348(void)
{
                    /* Symbol Ref: {@symbol $L34543} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c368
// Address: 0055c368
// XREFS: RGE_Action_Object
void FUN_0055c368(void)
{
                    /* Symbol Ref: {@symbol $L35401} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c388
// Address: 0055c388
// XREFS: RGE_Action_Object
void FUN_0055c388(void)
{
                    /* Symbol Ref: {@symbol $L35497} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c3a8
// Address: 0055c3a8
// XREFS: ~RGE_Action_Object
void FUN_0055c3a8(void)
{
                    /* Symbol Ref: {@symbol $L35513} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c3cb
// Address: 0055c3cb
// XREFS: create_action_list
void FUN_0055c3cb(void)
{
                    /* Symbol Ref: {@symbol $L35536} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c3f6
// Address: 0055c3f6
// XREFS: move_to
void FUN_0055c3f6(void)
{
                    /* Symbol Ref: {@symbol $L35566} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c400
// Address: 0055c400
// XREFS: None
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
// XREFS: None
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
// XREFS: set_state
void FUN_0055c416(void)
{
                    /* Symbol Ref: {@symbol $L35744} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c420
// Address: 0055c420
// XREFS: None
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
// XREFS: create_action_list
void FUN_0055c42b(void)
{
                    /* Symbol Ref: {@symbol $L34800} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c456
// Address: 0055c456
// XREFS: BuildAIModule
void FUN_0055c456(void)
{
                    /* Symbol Ref: {@symbol $L31906} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c460
// Address: 0055c460
// XREFS: None
void FUN_0055c460(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L31928} */
  AIModule::~AIModule(*(AIModule **)(unaff_EBP + -0x118));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c46b
// Address: 0055c46b
// XREFS: None
void FUN_0055c46b(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L31929} */
  BuildItem::~BuildItem((BuildItem *)(*(int *)(unaff_EBP + -0x118) + 0xf0));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c47c
// Address: 0055c47c
// XREFS: None
void FUN_0055c47c(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L31930} */
  ManagedArray<int>::~ManagedArray<int>((ManagedArray<int> *)(*(int *)(unaff_EBP + -0x118) + 0x5ac))
  ;
  return;
}

// --------------------------------------------------

// Function: FUN_0055c48d
// Address: 0055c48d
// XREFS: None
void FUN_0055c48d(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L31931} */
  operator_delete(*(void **)(unaff_EBP + -0x114));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c49b
// Address: 0055c49b
// XREFS: BuildAIModule
void FUN_0055c49b(void)
{
                    /* Symbol Ref: {@symbol $L31943} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c4d4
// Address: 0055c4d4
// XREFS: ~BuildAIModule
void FUN_0055c4d4(void)
{
                    /* Symbol Ref: {@symbol $L31964} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c4ee
// Address: 0055c4ee
// XREFS: loadBuildList
void FUN_0055c4ee(void)
{
                    /* Symbol Ref: {@symbol $L32016} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c50b
// Address: 0055c50b
// XREFS: insertItem
void FUN_0055c50b(void)
{
                    /* Symbol Ref: {@symbol $L32052} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c536
// Address: 0055c536
// XREFS: ConstructionAIModule
void FUN_0055c536(void)
{
                    /* Symbol Ref: {@symbol $L30902} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

// Function: FUN_0055c540
// Address: 0055c540
// XREFS: None
void FUN_0055c540(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L30929} */
  AIModule::~AIModule(*(AIModule **)(unaff_EBP + -0x114));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c54b
// Address: 0055c54b
// XREFS: None
void FUN_0055c54b(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L30930} */
  ConstructionItem::~ConstructionItem((ConstructionItem *)(*(int *)(unaff_EBP + -0x114) + 0xf4));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c55c
// Address: 0055c55c
// XREFS: None
void FUN_0055c55c(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L30931} */
  ConstructionItem::~ConstructionItem((ConstructionItem *)(*(int *)(unaff_EBP + -0x114) + 0x178));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c56d
// Address: 0055c56d
// XREFS: None
void FUN_0055c56d(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L30932} */
  operator_delete(*(void **)(unaff_EBP + -0x118));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c57b
// Address: 0055c57b
// XREFS: None
void FUN_0055c57b(void)
{
  int unaff_EBP;
  
                    /* Symbol Ref: {@symbol $L30933} */
  operator_delete(*(void **)(unaff_EBP + -0x118));
  return;
}

// --------------------------------------------------

// Function: FUN_0055c589
// Address: 0055c589
// XREFS: ConstructionAIModule
void FUN_0055c589(void)
{
                    /* Symbol Ref: {@symbol $L30942} */
  ___CxxFrameHandler();
  return;
}

// --------------------------------------------------

