// GLOBAL FUNCTIONS PART 2400
// Function: FUN_004648ae
// Address: 004648ae
void __fastcall FUN_004648ae(undefined4 *param_1)
{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 2;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 1;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 1;
  param_1[0x20] = 1;
  param_1[0x22] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  *(undefined1 *)(param_1 + 0x3b) = 0;
  *(undefined1 *)((int)param_1 + 0xed) = 0;
  *(undefined1 *)((int)param_1 + 0xee) = 0;
  *(undefined1 *)((int)param_1 + 0xef) = 0;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  *(undefined1 *)((int)param_1 + 0xf2) = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x2f] = 0xfa;
  *param_1 = &TPanel::_vftable_;
  param_1[0x39] = 0xffffffff;
  param_1[0x3a] = 0xffffffff;
  return;
}

// --------------------------------------------------

// Function: FUN_004649dc
// Address: 004649dc
void __fastcall FUN_004649dc(TPanel *param_1)
{
  int iVar1;
  char *pcVar2;
  
  param_1->_padding_ = (int)&TPanel::_vftable_;
  TPanel::release_mouse(param_1);
  if (param_1->panelNameValue != (char *)0x0) {
    iVar1 = TPanelSystem::inSystem(&panel_system,param_1);
    if (iVar1 != 0) {
      pcVar2 = TPanel::panelName(param_1);
      TPanelSystem::removePanel(&panel_system,pcVar2);
    }
  }
  if (param_1->node != (PanelNode *)0x0) {
    if (param_1->parent_panel != (TPanel *)0x0) {
      TPanel::remove_panel_node(param_1->parent_panel,param_1->node);
    }
    free(param_1->node);
    param_1->node = (PanelNode *)0x0;
  }
  param_1->first_child_node = (PanelNode *)0x0;
  if (param_1->clip_rgn != (void *)0x0) {
    DeleteObject(param_1->clip_rgn);
    param_1->clip_rgn = (void *)0x0;
  }
  if (param_1->parent_panel != (TPanel *)0x0) {
    (**(code **)(param_1->parent_panel->_padding_ + 0x20))(2);
  }
  if (param_1->panelNameValue != (char *)0x0) {
    free(param_1->panelNameValue);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00464a7f
// Address: 00464a7f
undefined4 __thiscall
FUN_00464a7f(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  param_1[0x10] = param_3;
  param_1[8] = param_2;
  if (param_1[0xd] == 0) {
    param_1[0x28] = param_5;
    param_1[0x2b] = param_6;
    param_1[0x2c] = param_6;
    param_1[0x27] = param_4;
    param_1[0x29] = 0;
    param_1[0x2a] = 0;
    param_1[0x2d] = param_7;
    param_1[0x2e] = param_7;
  }
  iVar1 = *param_1;
  if (param_2 == 0) {
    uVar4 = 0;
    uVar3 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(param_2 + 0x1c);
    uVar3 = *(undefined4 *)(param_2 + 0x18);
  }
  (**(code **)(iVar1 + 0x50))(uVar3,uVar4);
  (**(code **)(iVar1 + 0x10))(param_6);
  param_1[0x1a] = 0;
  if (param_1[0x15] == 0) {
    puVar2 = (undefined4 *)calloc(1,0xc);
    param_1[0x15] = (int)puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    *puVar2 = param_1;
    *(undefined4 *)(param_1[0x15] + 4) = 0;
    *(undefined4 *)(param_1[0x15] + 8) = 0;
    if ((TPanel *)param_1[0x10] != (TPanel *)0x0) {
      TPanel::add_panel_node((TPanel *)param_1[0x10],(PanelNode *)param_1[0x15],(PanelNode *)0x0,0);
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00464b4d
// Address: 00464b4d
void __thiscall FUN_00464b4d(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_3 == 0) {
    iVar1 = *(int *)(param_1 + 0x58);
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 4) = 0;
      *(undefined4 *)(param_2 + 8) = 0;
    }
    else {
      for (iVar3 = *(int *)(iVar1 + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
        iVar1 = iVar3;
      }
      *(int *)(iVar1 + 8) = param_2;
      *(int *)(param_2 + 4) = iVar1;
      *(undefined4 *)(param_2 + 8) = 0;
    }
  }
  else if (param_4 == 0) {
    uVar2 = *(undefined4 *)(param_3 + 4);
    *(int *)(param_2 + 8) = param_3;
    *(undefined4 *)(param_2 + 4) = uVar2;
    *(int *)(param_3 + 4) = param_2;
    if (*(int *)(param_2 + 4) != 0) {
      *(int *)(*(int *)(param_2 + 4) + 8) = param_2;
    }
  }
  else {
    *(int *)(param_2 + 4) = param_3;
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_3 + 8);
    *(int *)(param_3 + 8) = param_2;
    if (*(int *)(param_2 + 8) != 0) {
      *(int *)(*(int *)(param_2 + 8) + 4) = param_2;
    }
  }
  if (*(int *)(param_2 + 4) == 0) {
    *(int *)(param_1 + 0x58) = param_2;
  }
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_1 + 0x5c) = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00464be1
// Address: 00464be1
void __thiscall FUN_00464be1(int param_1,int *param_2)
{
  if (param_2 == *(int **)(param_1 + 0x58)) {
    *(int *)(param_1 + 0x58) = param_2[2];
  }
  if (param_2 == *(int **)(param_1 + 0x5c)) {
    *(int *)(param_1 + 0x5c) = param_2[1];
  }
  if (param_2[1] != 0) {
    *(int *)(param_2[1] + 8) = param_2[2];
  }
  if (param_2[2] != 0) {
    *(int *)(param_2[2] + 4) = param_2[1];
  }
  param_2[1] = 0;
  param_2[2] = 0;
  if (*(int *)(param_1 + 0x3c) == *param_2) {
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00464c49
// Address: 00464c49
void __thiscall FUN_00464c49(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[0x10];
  param_1[5] = param_4;
  param_1[6] = param_5;
  iVar3 = param_4 + -1 + param_2;
  iVar1 = param_5 + -1 + param_3;
  param_1[3] = param_2;
  param_1[4] = param_3;
  param_1[0x23] = param_2;
  param_1[0x24] = param_3;
  param_1[0x25] = iVar3;
  param_1[0x26] = iVar1;
  param_1[9] = param_2;
  param_1[10] = param_3;
  param_1[0xb] = iVar3;
  param_1[0xc] = iVar1;
  if ((iVar2 != 0) && (*(char *)((int)param_1 + 0xf1) != '\0')) {
    if (param_2 < *(int *)(iVar2 + 0x24)) {
      param_1[9] = *(int *)(iVar2 + 0x24);
    }
    if (param_3 < *(int *)(iVar2 + 0x28)) {
      param_1[10] = *(int *)(iVar2 + 0x28);
    }
    if (*(int *)(iVar2 + 0x2c) < iVar3) {
      param_1[0xb] = *(int *)(iVar2 + 0x2c);
    }
    if (*(int *)(iVar2 + 0x30) < iVar1) {
      param_1[0xc] = *(int *)(iVar2 + 0x30);
    }
  }
  if (param_1[9] < 0) {
    param_1[9] = 0;
  }
  if (param_1[10] < 0) {
    param_1[10] = 0;
  }
  iVar3 = param_1[8];
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x18) <= param_1[0xb]) {
      param_1[0xb] = *(int *)(iVar3 + 0x18) + -1;
    }
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x1c) <= param_1[0xc])) {
      param_1[0xc] = *(int *)(iVar3 + 0x1c) + -1;
    }
  }
  if (param_1[0x22] != 0) {
    DeleteObject(param_1[0x22]);
    param_1[0x22] = 0;
  }
  if (param_1[9] <= param_1[0xb]) {
    if (param_1[10] <= param_1[0xc]) {
      param_1[0x1c] = 1;
      iVar3 = CreateRectRgn(param_1[9],param_1[10],param_1[0xb],param_1[0xc]);
      param_1[0x22] = iVar3;
      goto LAB_00464d57;
    }
  }
  param_1[0x1c] = 0;
LAB_00464d57:
  if (param_1[0x1b] != 0) {
    (**(code **)(*param_1 + 0x20))(2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00464d6c
// Address: 00464d6c
void __thiscall FUN_00464d6c(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  (**(code **)(*param_1 + 0xc))(param_2,param_3,(param_4 - param_2) + 1,(param_5 - param_3) + 1);
  return;
}

// --------------------------------------------------

// Function: FUN_00464d96
// Address: 00464d96
void __thiscall FUN_00464d96(int *param_1,undefined1 param_2)
{
  *(undefined1 *)((int)param_1 + 0xef) = param_2;
  if (param_1[0x1b] != 0) {
    (**(code **)(*param_1 + 0x20))(2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00464dbb
// Address: 00464dbb
void __thiscall FUN_00464dbb(TPanel *param_1,int param_2)
{
  if (param_1->active != param_2) {
    param_1->active = param_2;
    if (param_2 != 0) {
      (**(code **)(param_1->_padding_ + 0x20))(1);
      return;
    }
    TPanel::release_mouse(param_1);
    if (param_1->parent_panel != (TPanel *)0x0) {
      (**(code **)(param_1->parent_panel->_padding_ + 0x20))(1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00464df9
// Address: 00464df9
void __thiscall
FUN_00464df9(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11,int param_12,int param_13,int param_14
            )
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  param_1[0xd] = param_2;
  param_1[0x29] = param_5;
  param_1[0x2c] = param_8;
  param_1[0x27] = param_3;
  param_1[0x28] = param_4;
  iVar1 = *param_1;
  param_1[0x11] = param_11;
  param_1[0x2a] = param_6;
  param_1[0x2b] = param_7;
  param_1[0x14] = param_14;
  iVar2 = param_1[8];
  param_1[0x2d] = param_9;
  param_1[0x2e] = param_10;
  param_1[0x12] = param_12;
  param_1[0x13] = param_13;
  if (iVar2 == 0) {
    uVar4 = 0;
    uVar3 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 0x1c);
    uVar3 = *(undefined4 *)(iVar2 + 0x18);
  }
  (**(code **)(iVar1 + 0x50))(uVar3,uVar4);
  if (param_1[0x1b] != 0) {
    (**(code **)(iVar1 + 0x20))(2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00464ea6
// Address: 00464ea6
void __thiscall
FUN_00464ea6(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  (**(code **)(*param_1 + 0x18))(0,param_2,param_3,0,0,param_4,param_4,param_5,param_5,0,0,0,0);
  return;
}

// --------------------------------------------------

// Function: FUN_00464edc
// Address: 00464edc
void __thiscall FUN_00464edc(int param_1,int param_2)
{
  if ((((param_2 != 1) || (*(int *)(param_1 + 0x38) != 2)) &&
      (*(int *)(param_1 + 0x38) = param_2, param_2 != 0)) &&
     (((*(int *)(param_1 + 0x20) != 0 && (*(int *)(param_1 + 0x70) != 0)) &&
      (*(int *)(param_1 + 0x6c) != 0)))) {
    InvalidateRect(*(undefined4 *)(*(int *)(param_1 + 0x20) + 4),param_1 + 0x24,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00464f1e
// Address: 00464f1e
void __thiscall FUN_00464f1e(int param_1,int *param_2,int *param_3,undefined4 param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar2 = param_2[9];
  iVar3 = param_2[10];
  iVar4 = param_2[0xb];
  iVar5 = param_2[0xc];
  for (piVar1 = *(int **)(param_1 + 0x58); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
    piVar6 = (int *)*piVar1;
    if (((piVar6 != param_2) && (piVar6 != param_3)) && (param_2[0x37] < piVar6[0x37])) {
      iVar7 = piVar6[9];
      iVar8 = piVar6[10];
      iVar9 = piVar6[0xb];
      iVar10 = piVar6[0xc];
      if (((((iVar7 < iVar2) || (iVar4 < iVar7)) && ((iVar9 < iVar2 || (iVar4 < iVar9)))) &&
          ((iVar2 <= iVar7 || (iVar9 <= iVar4)))) ||
         (((iVar8 < iVar3 || (iVar5 < iVar8)) &&
          (((iVar10 < iVar3 || (iVar5 < iVar10)) && ((iVar3 <= iVar8 || (iVar10 <= iVar5)))))))) {
        if (((((iVar7 <= iVar2) && (iVar2 <= iVar9)) || ((iVar7 <= iVar4 && (iVar4 <= iVar9)))) ||
            ((iVar2 < iVar7 && (iVar9 < iVar4)))) &&
           ((((iVar8 <= iVar3 && (iVar3 <= iVar10)) || ((iVar8 <= iVar5 && (iVar5 <= iVar10)))) ||
            ((iVar3 < iVar8 && (iVar10 < iVar5)))))) {
          (**(code **)(*piVar6 + 0x20))(param_4);
        }
      }
      else {
        (**(code **)(*piVar6 + 0x20))(param_4);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00465047
// Address: 00465047
void __thiscall FUN_00465047(int param_1,int *param_2,undefined4 param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar2 = param_2[9];
  iVar3 = param_2[10];
  iVar4 = param_2[0xb];
  iVar5 = param_2[0xc];
  for (piVar1 = *(int **)(param_1 + 0x58); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
    piVar6 = (int *)*piVar1;
    if (piVar6 != param_2) {
      iVar7 = piVar6[9];
      iVar8 = piVar6[10];
      iVar9 = piVar6[0xb];
      iVar10 = piVar6[0xc];
      if (((((iVar7 < iVar2) || (iVar4 < iVar7)) && ((iVar9 < iVar2 || (iVar4 < iVar9)))) &&
          ((iVar2 <= iVar7 || (iVar9 <= iVar4)))) ||
         (((iVar8 < iVar3 || (iVar5 < iVar8)) &&
          (((iVar10 < iVar3 || (iVar5 < iVar10)) && ((iVar3 <= iVar8 || (iVar10 <= iVar5)))))))) {
        if (((((iVar7 <= iVar2) && (iVar2 <= iVar9)) || ((iVar7 <= iVar4 && (iVar4 <= iVar9)))) ||
            ((iVar2 < iVar7 && (iVar9 < iVar4)))) &&
           ((((iVar8 <= iVar3 && (iVar3 <= iVar10)) || ((iVar8 <= iVar5 && (iVar5 <= iVar10)))) ||
            ((iVar3 < iVar8 && (iVar10 < iVar5)))))) {
          (**(code **)(*piVar6 + 0x20))(param_3);
        }
      }
      else {
        (**(code **)(*piVar6 + 0x20))(param_3);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00465157
// Address: 00465157
void __fastcall FUN_00465157(int param_1)
{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x38) = 0;
  if (((*(TDrawArea **)(param_1 + 0x20) != (TDrawArea *)0x0) && (*(int *)(param_1 + 0x70) != 0)) &&
     (*(int *)(param_1 + 0x6c) != 0)) {
    if ((*(char *)(param_1 + 0xf0) == '\0') && (*(int **)(param_1 + 0x40) != (int *)0x0)) {
      iVar1 = **(int **)(param_1 + 0x40);
      if (*(char *)(param_1 + 0xf2) != '\0') {
        (**(code **)(iVar1 + 0x3c))(param_1 + 0x24);
        return;
      }
      (**(code **)(iVar1 + 0x34))(param_1 + 0x24);
      return;
    }
    TDrawArea::Clear(*(TDrawArea **)(param_1 + 0x20),(tagRECT *)(param_1 + 0x24),
                     (uint)*(byte *)(param_1 + 0xef));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046521d
// Address: 0046521d
void __thiscall FUN_0046521d(int *param_1,int param_2,int param_3,int *param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  param_1[3] = param_1[3] + param_2;
  piVar1 = param_1 + 9;
  param_1[4] = param_1[4] + param_3;
  iVar2 = *piVar1;
  iVar3 = param_1[10];
  iVar4 = param_1[0xb];
  iVar5 = param_1[0xc];
  *piVar1 = *param_4;
  param_1[10] = param_4[1];
  param_1[0xb] = param_4[2];
  param_1[0xc] = param_4[3];
  (**(code **)(*param_1 + 0x30))();
  *piVar1 = iVar2;
  param_1[10] = iVar3;
  param_1[0xb] = iVar4;
  param_1[0xc] = iVar5;
  param_1[3] = param_1[3] - param_2;
  param_1[4] = param_1[4] - param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_004652b9
// Address: 004652b9
void __thiscall FUN_004652b9(int *param_1,undefined4 param_2)
{
  *(undefined1 *)((int)param_1 + 0xf2) = 1;
  (**(code **)(*param_1 + 0x34))(param_2);
  *(undefined1 *)((int)param_1 + 0xf2) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004652e1
// Address: 004652e1
void __thiscall FUN_004652e1(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined1 *)((int)param_1 + 0xf2) = 1;
  (**(code **)(*param_1 + 0x38))(param_2,param_3,param_4);
  *(undefined1 *)((int)param_1 + 0xf2) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0046531b
// Address: 0046531b
void __thiscall FUN_0046531b(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x38);
  if (iVar1 != 0) {
    SelectClipRgn(iVar1,*(undefined4 *)(param_1 + 0x88));
  }
  TDrawArea::SetClipRect(*(TDrawArea **)(param_1 + 0x20),(tagRECT *)(param_1 + 0x24));
  if (param_2 != 0) {
    TDrawArea::Clear(*(TDrawArea **)(param_1 + 0x20),(tagRECT *)(param_1 + 0x24),
                     (uint)*(byte *)(param_1 + 0xef));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00465367
// Address: 00465367
void __fastcall FUN_00465367(int param_1)
{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x38) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x38);
  if (iVar1 != 0) {
    SelectClipRgn(iVar1,0);
  }
  TDrawArea::SetClipRect(*(TDrawArea **)(param_1 + 0x20),(tagRECT *)0x0);
  *(undefined1 *)(param_1 + 0xf3) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004653d5
// Address: 004653d5
int __thiscall FUN_004653d5(TPanel *param_1,void *param_2,uint param_3,uint param_4,uint param_5)
{
  PanelNode *pPVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  TPanel *pTVar8;
  TPanel *pTVar9;
  tagPOINT tStack_8;
  
  lVar4 = param_5;
  uVar3 = param_4;
  uVar2 = param_3;
  if (param_1->active == 0) {
    return 0;
  }
  if (param_3 < 0x207) {
    if (param_3 < 0x200) {
      if (((param_3 != 0x100) && (param_3 != 0x102)) && (param_3 != 0x104)) goto LAB_00465435;
    }
    else {
      if (param_2 != param_1->render_area->Wnd) {
        return 0;
      }
      iVar7 = TPanelSystem::GetInputEnabled(&panel_system);
      if (iVar7 == 0) {
        return 0;
      }
      TPanel::get_mouse_info(param_1,param_4,lVar4,&tStack_8,(int *)&param_5,(int *)&param_3);
      pTVar9 = TPanelSystem::mouseOwner(&panel_system);
      if (pTVar9 == (TPanel *)0x0) {
        pTVar9 = TPanelSystem::keyboardOwner(&panel_system);
        if (pTVar9 == (TPanel *)0x0) {
          pTVar8 = TPanelSystem::modalPanel(&panel_system);
          pTVar9 = param_1;
          if (pTVar8 != (TPanel *)0x0) {
            pTVar9 = TPanelSystem::modalPanel(&panel_system);
          }
        }
        else {
          pTVar9 = TPanelSystem::keyboardOwner(&panel_system);
        }
      }
      else {
        pTVar9 = TPanelSystem::mouseOwner(&panel_system);
      }
      switch(uVar2) {
      case 0x200:
        iVar7 = (**(code **)(pTVar9->_padding_ + 0x74))(tStack_8.x,tStack_8.y,param_5,param_3);
        return iVar7;
      case 0x201:
        iVar7 = (**(code **)(pTVar9->_padding_ + 0x70))(1,tStack_8.x,tStack_8.y,param_5,param_3);
        return iVar7;
      case 0x202:
        iVar7 = (**(code **)(pTVar9->_padding_ + 0x78))(1,tStack_8.x,tStack_8.y,param_5,param_3);
        return iVar7;
      case 0x203:
        iVar7 = (**(code **)(pTVar9->_padding_ + 0x7c))(1,tStack_8.x,tStack_8.y,param_5,param_3);
        return iVar7;
      case 0x204:
        iVar7 = (**(code **)(pTVar9->_padding_ + 0x70))(2,tStack_8.x,tStack_8.y,param_5,param_3);
        return iVar7;
      case 0x205:
        iVar7 = (**(code **)(pTVar9->_padding_ + 0x78))(2,tStack_8.x,tStack_8.y,param_5,param_3);
        return iVar7;
      case 0x206:
        iVar7 = (**(code **)(pTVar9->_padding_ + 0x7c))(2,tStack_8.x,tStack_8.y,param_5,param_3);
        return iVar7;
      }
    }
    if ((param_2 == param_1->render_area->Wnd) &&
       (iVar7 = TPanelSystem::GetInputEnabled(&panel_system), iVar7 != 0)) {
      pTVar9 = TPanelSystem::keyboardOwner(&panel_system);
      if (pTVar9 == (TPanel *)0x0) {
        pTVar9 = TPanelSystem::modalPanel(&panel_system);
        if (pTVar9 != (TPanel *)0x0) {
          param_1 = TPanelSystem::modalPanel(&panel_system);
        }
      }
      else {
        param_1 = TPanelSystem::keyboardOwner(&panel_system);
      }
      if ((uVar2 != 0x100) && (uVar2 != 0x104)) {
        iVar7 = (**(code **)(param_1->_padding_ + 0x5c))(param_4,lVar4);
        return iVar7;
      }
      sVar5 = GetKeyState(0x12);
      sVar6 = GetKeyState(0x11);
      param_5 = (uint)(sVar6 < 0);
      sVar6 = GetKeyState(0x10);
      param_3 = (uint)(sVar6 < 0);
      iVar7 = (**(code **)(param_1->_padding_ + 0x58))(param_4,lVar4,sVar5 < 0,param_5,param_3);
      return iVar7;
    }
  }
  else {
LAB_00465435:
    for (pPVar1 = param_1->last_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->prev_node)
{
      iVar7 = (**(code **)(pPVar1->panel->_padding_ + 0x48))(param_2,uVar2,uVar3,lVar4);
      if (iVar7 != 0) {
        return iVar7;
      }
    }
    if (uVar2 < 0x401) {
      if (uVar2 == 0x400) {
        iVar7 = (**(code **)(param_1->_padding_ + 100))(uVar3,lVar4);
        return iVar7;
      }
      switch(uVar2) {
      case 0x111:
        iVar7 = (**(code **)(param_1->_padding_ + 0x60))(uVar3,lVar4);
        return iVar7;
      case 0x113:
        iVar7 = (**(code **)(param_1->_padding_ + 0x68))(uVar3,lVar4);
        return iVar7;
      case 0x114:
      case 0x115:
        iVar7 = (**(code **)(param_1->_padding_ + 0x6c))(uVar3 & 0xffff,uVar3 >> 0x10);
        return iVar7;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00465746
// Address: 00465746
// [HELPER] s_C__msdev_work_age1_x1_Panel_cpp: "C:\msdev\work\age1_x1\Panel.cpp"
/* WARNING: Instruction at (ram,0x0046579e) overlaps instruction at (ram,0x0046579d)
    */
/* WARNING: Control flow encountered bad instruction data */

int __fastcall FUN_00465746(undefined4 param_1,int param_2)
{
  char *pcVar1;
  undefined4 *puVar2;
  char *in_EAX;
  ulong uVar3;
  int iVar4;
  char cVar5;
  char cVar7;
  char *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int iVar8;
  int iVar9;
  int iVar10;
  int unaff_EDI;
  bool in_ZF;
  char in_SF;
  char in_OF;
  int *piVar6;
  
  if (in_ZF || in_OF != in_SF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cVar5 = (char)param_1;
  cVar7 = (char)((uint)param_1 >> 8) + cVar5;
  piVar6 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar7,cVar5));
  *(char *)(unaff_EDI + -0x5fffb9ac) = *(char *)(unaff_EDI + -0x5fffb9ac) + cVar5;
  in_EAX[0x71004654] = in_EAX[0x71004654] + (char)((uint)in_EAX >> 8);
  pcVar1 = (char *)(unaff_EBP + 0x55b90046 + param_2 * 2);
  *pcVar1 = *pcVar1 + (char)param_2;
  iVar8 = unaff_ESI + 6;
  *unaff_EBX = *unaff_EBX + (char)in_EAX;
  iVar9 = unaff_ESI + 7;
  *in_EAX = *in_EAX + cVar7;
  *(char *)(unaff_EBP + 0x56) = *(char *)(unaff_EBP + 0x56) + cVar5;
  iVar10 = unaff_ESI + 9;
  in_EAX[-0x6f6f6f70] = in_EAX[-0x6f6f6f70] + (char)param_2;
  if (((piVar6[0x1b] != 0) && ((char)piVar6[0x3b] == '\x01')) &&
     (uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Panel_cpp,0x5fd),
     piVar6[0x2f] <= (int)(uVar3 - piVar6[0x35]))) {
    *(undefined1 *)(piVar6 + 0x3b) = 2;
    if (*(char *)((int)piVar6 + 0xed) == '\x01') {
      (**(code **)(*piVar6 + 0x88))();
    }
    else {
      (**(code **)(*piVar6 + 0x9c))(piVar6[0x31],piVar6[0x32],piVar6[0x33],piVar6[0x34]);
    }
  }
  puVar2 = (undefined4 *)piVar6[0x17];
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    iVar4 = (**(code **)(*(int *)*puVar2 + 0x4c))(iVar10,iVar9,iVar8);
    if (iVar4 != 0) break;
    puVar2 = (undefined4 *)puVar2[1];
  }
  return iVar4;
}

// --------------------------------------------------

// Function: FUN_00465813
// Address: 00465813
int __thiscall FUN_00465813(int *param_1,int param_2,int param_3)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = param_1[0x10];
  if (iVar8 == 0) {
    iVar7 = 0;
    iVar2 = 0;
    iVar3 = param_2 + -1;
    iVar8 = param_3 + -1;
  }
  else {
    iVar3 = *(int *)(iVar8 + 0x94);
    iVar7 = *(int *)(iVar8 + 0x8c);
    iVar2 = *(int *)(iVar8 + 0x90);
    iVar8 = *(int *)(iVar8 + 0x98);
    param_2 = (iVar3 - iVar7) + 1;
    param_3 = (iVar8 - iVar2) + 1;
  }
  if (param_1[0xd] == 0) {
    iVar8 = param_1[0x2d];
    iVar7 = param_1[0x27] + iVar7;
    iVar2 = param_1[0x28] + iVar2;
    iVar3 = param_1[0x2b] + -1 + iVar7;
  }
  else {
    iVar5 = param_1[0x11];
    if ((iVar5 == 0) || (*(int *)(iVar5 + 0x6c) == 0)) {
      iVar7 = param_1[0x27] + iVar7;
    }
    else {
      iVar7 = param_1[0x27] + 1 + *(int *)(iVar5 + 0x94);
    }
    iVar5 = param_1[0x12];
    if ((iVar5 == 0) || (*(int *)(iVar5 + 0x6c) == 0)) {
      iVar2 = param_1[0x28] + iVar2;
    }
    else {
      iVar2 = param_1[0x28] + 1 + *(int *)(iVar5 + 0x98);
    }
    iVar5 = param_1[0x13];
    if ((iVar5 == 0) || (*(int *)(iVar5 + 0x6c) == 0)) {
      iVar3 = iVar3 - param_1[0x29];
    }
    else {
      iVar3 = (*(int *)(iVar5 + 0x8c) - param_1[0x29]) + -1;
    }
    iVar5 = param_1[0x14];
    if ((iVar5 == 0) || (*(int *)(iVar5 + 0x6c) == 0)) {
      iVar8 = iVar8 - param_1[0x2a];
    }
    else {
      iVar8 = (*(int *)(iVar5 + 0x90) - param_1[0x2a]) + -1;
    }
    iVar4 = (iVar3 - iVar7) + 1;
    iVar6 = (iVar8 - iVar2) + 1;
    iVar5 = param_1[0x2b];
    if ((iVar5 == 0) || (iVar5 <= iVar4)) {
      iVar5 = param_1[0x2c];
      if ((iVar5 != 0) && (iVar5 < iVar4)) {
        iVar4 = param_1[0xd];
        if (((iVar4 == 3) || (iVar4 == 7)) || (iVar4 == 8)) goto LAB_00465973;
        iVar7 = (iVar3 - iVar5) + 1;
      }
    }
    else {
LAB_00465973:
      iVar3 = iVar7 + -1 + iVar5;
    }
    iVar5 = param_1[0x2d];
    if ((iVar5 == 0) || (iVar5 <= iVar6)) {
      iVar5 = param_1[0x2e];
      if ((iVar5 != 0) && (iVar5 < iVar6)) {
        iVar4 = param_1[0xd];
        if (((iVar4 == 4) || (iVar4 == 7)) || (iVar4 == 9)) goto LAB_004659b0;
        iVar2 = (iVar8 - iVar5) + 1;
      }
    }
    else {
LAB_004659b0:
      iVar8 = iVar2 + -1 + iVar5;
    }
    if (param_1[0xd] != 2) goto LAB_00465a0e;
    iVar3 = iVar3 - iVar7;
    iVar7 = iVar3 + 1;
    iVar8 = (iVar8 - iVar2) + 1;
    if (iVar7 == param_2) {
      iVar7 = 0;
    }
    else {
      iVar7 = param_2 / 2 - iVar7 / 2;
    }
    iVar3 = iVar3 + iVar7;
    if (iVar8 == param_3) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_3 / 2 - iVar8 / 2;
    }
  }
  iVar8 = iVar8 + -1 + iVar2;
LAB_00465a0e:
  (**(code **)(*param_1 + 8))(iVar7,iVar2,iVar3,iVar8);
  iVar8 = 0;
  do {
    for (puVar1 = (undefined4 *)param_1[0x16]; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[2]) {
      iVar3 = (**(code **)(*(int *)*puVar1 + 0x50))(unaff_EBP,unaff_EBX);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00465a69
// Address: 00465a69
undefined4 __fastcall FUN_00465a69(int *param_1)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  if ((((param_1[8] != 0) && (param_1[0x1c] != 0)) && (param_1[0x1b] != 0)) &&
     ((rge_base_game->prog_active != 0 &&
      (iVar3 = IsIconic(*(undefined4 *)(param_1[8] + 4)), iVar3 == 0)))) {
    if (param_1[0xe] != 0) {
      for (puVar1 = (undefined4 *)param_1[0x16]; puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)puVar1[2]) {
        (**(code **)(*(int *)*puVar1 + 0x20))(param_1[0xe]);
      }
      piVar2 = (int *)param_1[0x10];
      if ((piVar2 != (int *)0x0) && (piVar2[0x1f] != 0)) {
        (**(code **)(*piVar2 + 0x24))(param_1,param_1,param_1[0xe]);
      }
      (**(code **)(*param_1 + 0x30))();
      param_1[0xe] = 0;
      param_1[0x21] = 1;
    }
    for (puVar1 = (undefined4 *)param_1[0x16]; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[2]) {
      (**(code **)(*(int *)*puVar1 + 0x54))();
    }
    param_1[0x21] = 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00465b25
// Address: 00465b25
int __thiscall
FUN_00465b25(int *param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  TPanel *pTVar4;
  
  if (param_1[0x1e] != 0) {
    for (puVar1 = (undefined4 *)param_1[0x17]; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[1]) {
      iVar2 = (**(code **)(*(int *)*puVar1 + 0x58))(param_2,param_3,param_4,param_5,param_6);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = param_6;
    iVar3 = (**(code **)(*param_1 + 0xac))(param_2,param_3,param_4,param_5);
    if (iVar3 != 0) {
      return iVar3;
    }
    if ((((param_4 == 0) && (param_5 == 0)) && (param_2 == 9)) &&
       ((*(int *)(iVar2 + 0x74) != 0 && (*(TPanel **)(iVar2 + 0x40) != (TPanel *)0x0)))) {
      if (param_6 == 0) {
        pTVar4 = *(TPanel **)(iVar2 + 100);
      }
      else {
        pTVar4 = *(TPanel **)(iVar2 + 0x60);
      }
      if (pTVar4 != (TPanel *)0x0) {
        TPanel::set_curr_child(*(TPanel **)(iVar2 + 0x40),pTVar4);
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00465bdf
// Address: 00465bdf
int __thiscall FUN_00465bdf(int *param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1[0x1e] == 0) {
    return 0;
  }
  puVar1 = (undefined4 *)param_1[0x17];
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      iVar2 = (**(code **)(*param_1 + 0xb0))(param_2,param_3);
      return iVar2;
    }
    iVar2 = (**(code **)(*(int *)*puVar1 + 0x5c))(param_2,param_3);
    if (iVar2 != 0) break;
    puVar1 = (undefined4 *)puVar1[1];
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_00465c2d
// Address: 00465c2d
undefined4 FUN_00465c2d(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00465c35
// Address: 00465c35
undefined4 FUN_00465c35(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00465c45
// Address: 00465c45
undefined4 FUN_00465c45(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00465c55
// Address: 00465c55
undefined4 FUN_00465c55(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00465c65
// Address: 00465c65
// [HELPER] s_C__msdev_work_age1_x1_Panel_cpp: "C:\msdev\work\age1_x1\Panel.cpp"
int __thiscall
FUN_00465c65(TPanel *param_1,undefined4 param_2,long param_3,long param_4,int param_5,int param_6)
{
  PanelNode *pPVar1;
  int iVar2;
  ulong uVar3;
  
  if (param_1->active == 0) {
    return 0;
  }
  if (param_1->mouse_captured == 0) {
    iVar2 = (**(code **)(param_1->_padding_ + 0xbc))(param_3,param_4);
    if (iVar2 == 0) {
      return 0;
    }
    for (pPVar1 = param_1->last_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->prev_node)
{
      iVar2 = (**(code **)(pPVar1->panel->_padding_ + 0x70))
                        (param_2,param_3,param_4,param_5,param_6);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    if (param_1->handle_mouse_input == 0) {
      return 0;
    }
    param_1->mouse_down_button = (uchar)param_2;
    param_1->mouse_down_x = param_3;
    param_1->mouse_down_y = param_4;
    param_1->mouse_down_ctrl = param_5;
    param_1->mouse_down_shift = param_6;
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Panel_cpp,0x72c);
    param_1->mouse_down_time = uVar3;
    param_1->mouse_action = '\x01';
    if (((param_1->tab_stop != 0) && (param_1->parent_panel != (TPanel *)0x0)) &&
       (param_1->mouse_down_button == '\x01')) {
      TPanel::set_curr_child(param_1->parent_panel,param_1);
    }
  }
  if (param_1->handle_mouse_input == 0) {
    return 0;
  }
  if (param_1->mouse_down_button != '\x01') {
    (**(code **)(param_1->_padding_ + 0x98))(param_3,param_4,param_5,param_6);
    return 1;
  }
  (**(code **)(param_1->_padding_ + 0x84))(param_3,param_4,param_5,param_6);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00465db5
// Address: 00465db5
int __thiscall
FUN_00465db5(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBP;
  
  if (param_1[0x1b] == 0) {
    return 0;
  }
  if (param_1[0x1a] == 0) {
    iVar2 = (**(code **)(*param_1 + 0xbc))(param_2,param_3);
    if (iVar2 == 0) {
      return 0;
    }
    puVar1 = (undefined4 *)param_1[0x17];
    while( true ) {
      if (puVar1 == (undefined4 *)0x0) {
        if (param_1[0x20] != 0) {
          iVar2 = (**(code **)(unaff_EBP + 0x80))(param_2,param_3,param_2,param_3);
          return iVar2;
        }
        return 0;
      }
      iVar2 = (**(code **)(*(int *)*puVar1 + 0x74))(param_2,param_3,param_2,param_3);
      if (iVar2 != 0) break;
      puVar1 = (undefined4 *)puVar1[1];
    }
    return iVar2;
  }
  if (param_1[0x20] == 0) {
    return 0;
  }
  if (((char)param_1[0x3b] == '\x01') || ((char)param_1[0x3b] == '\x02')) {
    if (*(char *)((int)param_1 + 0xed) == '\x01') {
      uVar3 = param_2 - param_1[0x31] >> 0x1f;
      if (((int)((param_2 - param_1[0x31] ^ uVar3) - uVar3) <= param_1[0x30]) &&
         (uVar3 = param_3 - param_1[0x32] >> 0x1f,
         (int)((param_3 - param_1[0x32] ^ uVar3) - uVar3) <= param_1[0x30])) {
        return 1;
      }
    }
    else {
      uVar3 = param_2 - param_1[0x31] >> 0x1f;
      if (((int)((param_2 - param_1[0x31] ^ uVar3) - uVar3) < 0xb) &&
         (uVar3 = param_3 - param_1[0x32] >> 0x1f,
         (int)((param_3 - param_1[0x32] ^ uVar3) - uVar3) < 0xb)) {
        return 1;
      }
    }
  }
  *(undefined1 *)(param_1 + 0x3b) = 3;
  if (*(char *)((int)param_1 + 0xed) == '\x01') {
    (**(code **)(*param_1 + 0x8c))(param_2,param_3,param_4,param_5);
    return 1;
  }
  if (*(char *)((int)param_1 + 0xed) != '\x02') {
    (**(code **)(*param_1 + 0x80))(param_2,param_3,param_4,param_5);
    return 1;
  }
  (**(code **)(*param_1 + 0xa0))();
  return 1;
}

// --------------------------------------------------

// Function: FUN_00465f66
// Address: 00465f66
int __thiscall
FUN_00465f66(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)
{
  int iVar1;
  undefined4 unaff_EBX;
  char unaff_SI;
  undefined4 *puVar2;
  undefined4 unaff_retaddr;
  
  if (param_1[0x1b] == 0) {
    return 0;
  }
  if (param_1[0x1a] == 0) {
    iVar1 = (**(code **)(*param_1 + 0xbc))(param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = (undefined4 *)param_1[0x17];
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    while (iVar1 = (**(code **)(*(int *)*puVar2 + 0x78))
                             (unaff_EBX,unaff_retaddr,param_2,param_3,param_4), iVar1 == 0) {
      puVar2 = (undefined4 *)puVar2[1];
      if (puVar2 == (undefined4 *)0x0) {
        return 0;
      }
    }
  }
  else {
    if (param_1[0x20] == 0) {
      return 0;
    }
    if (*(char *)((int)param_1 + 0xed) == '\x01') {
      iVar1 = (**(code **)(*param_1 + 0x90))();
    }
    else {
      iVar1 = (**(code **)(*param_1 + 0xa4))(param_3,param_4,param_5,param_6);
    }
    if (iVar1 != 0) {
      return 0;
    }
    if (unaff_SI == *(char *)((int)param_1 + 0xed)) {
      *(undefined1 *)((int)param_1 + 0xed) = 0;
      *(undefined1 *)(param_1 + 0x3b) = 0;
    }
    iVar1 = 1;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0046605d
// Address: 0046605d
int __thiscall
FUN_0046605d(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_EBP;
  undefined4 unaff_retaddr;
  
  if (param_1[0x1b] == 0) {
    return 0;
  }
  if (param_1[0x1a] == 0) {
    iVar2 = (**(code **)(*param_1 + 0xbc))(param_3,param_4);
    if (iVar2 == 0) {
      return 0;
    }
    for (puVar1 = (undefined4 *)param_1[0x17]; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[1]) {
      iVar2 = (**(code **)(*(int *)*puVar1 + 0x7c))(param_2,param_3,param_4,param_5,param_6);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
  }
  if (param_1[0x20] != 0) {
    if ((char)param_2 == '\x01') {
      iVar2 = (**(code **)(*param_1 + 0x94))(param_3,param_4,param_5);
    }
    else {
      iVar2 = (**(code **)(*param_1 + 0xa8))(param_3,param_4,param_5,param_6);
    }
    if (iVar2 == 0) {
      (**(code **)(param_2 + 0x70))(unaff_EBP,param_3,param_4,unaff_retaddr,param_6);
      iVar2 = 1;
    }
    return iVar2;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046613b
// Address: 0046613b
undefined4 __thiscall
FUN_0046613b(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x40) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x40) + 0xb4))(param_2,param_3,param_4,param_5);
    return uVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046616b
// Address: 0046616b
void FUN_0046616b(uint param_1,uint param_2,uint *param_3,uint *param_4,uint *param_5)
{
  uint uVar1;
  
  uVar1 = param_2 & 0xffff;
  param_2 = param_2 >> 0x10;
  *param_3 = uVar1;
  param_3[1] = param_2;
  if (60000 < uVar1) {
    *param_3 = uVar1 - 0x10000;
  }
  if (60000 < param_2) {
    param_3[1] = param_2 - 0x10000;
  }
  *param_4 = param_1 & 8;
  *param_5 = param_1 & 4;
  return;
}

// --------------------------------------------------

// Function: FUN_004661c1
// Address: 004661c1
void __thiscall FUN_004661c1(int param_1,int *param_2)
{
  GetCursorPos(param_2);
  if (*(char *)(**(int **)(param_1 + 0x20) + 0x479) != '\x02') {
    ScreenToClient((*(int **)(param_1 + 0x20))[1],param_2);
    if (60000 < *param_2) {
      *param_2 = *param_2 + -0x10000;
    }
    if (60000 < param_2[1]) {
      param_2[1] = param_2[1] + -0x10000;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046621f
// Address: 0046621f
undefined4 __fastcall FUN_0046621f(TPanel *param_1)
{
  TPanel *pTVar1;
  
  pTVar1 = TPanelSystem::mouseOwner(&panel_system);
  if (pTVar1 != (TPanel *)0x0) {
    pTVar1 = TPanelSystem::mouseOwner(&panel_system);
    if (pTVar1 != param_1) {
      return 0;
    }
  }
  pTVar1 = TPanelSystem::mouseOwner(&panel_system);
  if (pTVar1 == param_1) {
    return 1;
  }
  SetCapture(param_1->render_area->Wnd);
  TPanelSystem::setMouseOwner(&panel_system,param_1);
  param_1->mouse_captured = 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0046627a
// Address: 0046627a
void __fastcall FUN_0046627a(TPanel *param_1)
{
  TPanel *pTVar1;
  
  if (param_1->mouse_captured != 0) {
    pTVar1 = TPanelSystem::mouseOwner(&panel_system);
    if (pTVar1 == param_1) {
      TPanelSystem::setMouseOwner(&panel_system,(TPanel *)0x0);
      ReleaseCapture();
    }
    param_1->mouse_captured = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004662b3
// Address: 004662b3
uint __fastcall FUN_004662b3(int param_1)
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  if (((uVar1 != 0) && (uVar1 = *(uint *)(param_1 + 0x70), uVar1 != 0)) &&
     (uVar1 = *(uint *)(param_1 + 0x6c), uVar1 != 0)) {
    return CONCAT31((int3)(uVar1 >> 8),*(undefined1 *)(param_1 + 0x38));
  }
  return uVar1 & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_004662dc
// Address: 004662dc
undefined4 __thiscall FUN_004662dc(int param_1,int param_2,int param_3)
{
  if ((((*(int *)(param_1 + 0x6c) != 0) && (*(int *)(param_1 + 0x24) <= param_2)) &&
      (param_2 <= *(int *)(param_1 + 0x2c))) &&
     ((*(int *)(param_1 + 0x28) <= param_3 && (param_3 <= *(int *)(param_1 + 0x30))))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00466314
// Address: 00466314
undefined4 FUN_00466314(int param_1,int param_2,int *param_3)
{
  if ((((*param_3 <= param_1) && (param_1 <= param_3[2])) && (param_3[1] <= param_2)) &&
     (param_2 <= param_3[3])) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046634e
// Address: 0046634e
undefined4 __thiscall FUN_0046634e(int param_1,int *param_2,int *param_3)
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = *(int *)(param_1 + 0x24) + 1;
  if ((*param_2 < iVar2) || (iVar2 = *(int *)(param_1 + 0x2c) + -1, iVar2 < *param_2)) {
    *param_2 = iVar2;
    uVar1 = 1;
  }
  iVar2 = *(int *)(param_1 + 0x28) + 1;
  if (*param_3 < iVar2) {
    *param_3 = iVar2;
    return 1;
  }
  iVar2 = *(int *)(param_1 + 0x30) + -1;
  if (iVar2 < *param_3) {
    *param_3 = iVar2;
    uVar1 = 1;
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0046639f
// Address: 0046639f
void __thiscall FUN_0046639f(int param_1,int *param_2)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x3c);
  if (param_2 != piVar1) {
    if ((piVar1 != (int *)0x0) && (*(int *)(param_1 + 0x78) != 0)) {
      (**(code **)(*piVar1 + 0xc0))(0);
    }
    *(int **)(param_1 + 0x3c) = param_2;
    if ((param_2 != (int *)0x0) && (*(int *)(param_1 + 0x78) != 0)) {
      (**(code **)(*param_2 + 0xc0))(1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004663e3
// Address: 004663e3
void __thiscall FUN_004663e3(int *param_1,int param_2)
{
  if (param_2 != param_1[0x1e]) {
    param_1[0x1e] = param_2;
    (**(code **)(*param_1 + 0x20))(1);
    if ((int *)param_1[0xf] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0xf] + 0xc0))(param_1[0x1e]);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046641f
// Address: 0046641f
undefined4 __fastcall FUN_0046641f(int param_1)
{
  return *(undefined4 *)(param_1 + 0x78);
}

// --------------------------------------------------

// Function: FUN_00466424
// Address: 00466424
void __thiscall FUN_00466424(TPanel *param_1,uchar param_2,short param_3)
{
  if (param_1->parent_panel != (TPanel *)0x0) {
    TPanel::set_child_z_order(param_1->parent_panel,param_1,param_2,param_3);
    return;
  }
  if (param_2 == '\0') {
    param_1->z_order = (int)param_3;
  }
  else {
    if (param_2 == '\x01') {
      param_1->z_order = 0;
      return;
    }
    if (param_2 == '\x02') {
      param_1->z_order = 0;
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00466481
// Address: 00466481
void __thiscall FUN_00466481(TPanel *param_1,TPanel *param_2,char param_3,short param_4)
{
  TPanel *pTVar1;
  int iVar2;
  bool bVar3;
  PanelNode *pPVar4;
  PanelNode *pPVar5;
  short sVar6;
  
  if (param_3 == '\0') {
    pPVar5 = param_1->first_child_node;
    bVar3 = false;
    if (pPVar5 != (PanelNode *)0x0) {
      pPVar4 = pPVar5;
      do {
        if (pPVar4->panel->z_order == (int)param_4) {
          bVar3 = true;
          break;
        }
        pPVar4 = pPVar4->next_node;
      } while (pPVar4 != (PanelNode *)0x0);
    }
    if ((bVar3) && (pPVar5 != (PanelNode *)0x0)) {
      do {
        iVar2 = pPVar5->panel->z_order;
        if (param_4 <= iVar2) {
          pPVar5->panel->z_order = iVar2 + 1;
        }
        pPVar5 = pPVar5->next_node;
      } while (pPVar5 != (PanelNode *)0x0);
    }
    param_2->z_order = (int)param_4;
  }
  else if (param_3 == '\x01') {
    sVar6 = 0;
    for (pPVar5 = param_1->first_child_node; pPVar5 != (PanelNode *)0x0; pPVar5 = pPVar5->next_node)
{
      pTVar1 = pPVar5->panel;
      if ((pTVar1 != param_2) && ((int)sVar6 < pTVar1->z_order)) {
        sVar6 = (short)pTVar1->z_order;
      }
    }
    param_2->z_order = sVar6 + 1;
  }
  else if (param_3 == '\x02') {
    sVar6 = 0;
    for (pPVar5 = param_1->first_child_node; pPVar5 != (PanelNode *)0x0; pPVar5 = pPVar5->next_node)
{
      pTVar1 = pPVar5->panel;
      if ((pTVar1 != param_2) && (pTVar1->z_order < (int)sVar6)) {
        sVar6 = (short)pTVar1->z_order;
      }
    }
    param_2->z_order = sVar6 + -1;
  }
  pPVar5 = param_1->first_child_node;
  pTVar1 = param_1->curr_child;
  param_1->curr_child = (TPanel *)0x0;
  for (; pPVar4 = (PanelNode *)0x0, pPVar5 != (PanelNode *)0x0; pPVar5 = pPVar5->next_node) {
    if (pPVar5->panel == param_2) {
      TPanel::remove_panel_node(param_1,pPVar5);
      pPVar4 = pPVar5;
      break;
    }
  }
  if (pPVar4 != (PanelNode *)0x0) {
    pPVar5 = param_1->first_child_node;
    bVar3 = false;
    if (pPVar5 != (PanelNode *)0x0) {
      do {
        if (param_2->z_order < pPVar5->panel->z_order) {
          TPanel::add_panel_node(param_1,pPVar4,pPVar5,0);
          bVar3 = true;
          break;
        }
        pPVar5 = pPVar5->next_node;
      } while (pPVar5 != (PanelNode *)0x0);
    }
    if (!bVar3) {
      TPanel::add_panel_node(param_1,pPVar4,param_1->last_child_node,1);
    }
  }
  param_1->curr_child = pTVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_004665fe
// Address: 004665fe
void FUN_004665fe(undefined4 *param_1,short param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)param_2;
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      if (iVar4 == 0) {
        uVar2 = param_1[iVar3 + -1];
      }
      else {
        uVar2 = param_1[iVar4 + -1];
      }
      if (iVar4 == iVar3 + -1) {
        uVar1 = *param_1;
      }
      else {
        uVar1 = param_1[iVar4 + 1];
      }
      (**(code **)(*(int *)param_1[iVar4] + 0xc4))(uVar2,uVar1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00466649
// Address: 00466649
void __thiscall FUN_00466649(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x60) = param_2;
  *(undefined4 *)(param_1 + 100) = param_3;
  *(undefined4 *)(param_1 + 0x74) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00466668
// Address: 00466668
undefined4 __fastcall FUN_00466668(int param_1)
{
  return *(undefined4 *)(param_1 + 4);
}

// --------------------------------------------------

// Function: FUN_00466674
// Address: 00466674
void __thiscall FUN_00466674(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0046668a
// Address: 0046668a
undefined4 __fastcall FUN_0046668a(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_00466694
// Address: 00466694
void __thiscall FUN_00466694(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004666aa
// Address: 004666aa
undefined4 __fastcall FUN_004666aa(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1c);
}

// --------------------------------------------------

// Function: FUN_004666b4
// Address: 004666b4
void __thiscall FUN_004666b4(int param_1,char *param_2)
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  if (param_2 == (char *)0x0) {
LAB_00466748:
    if (*(int *)(param_1 + 0x1c) != 0) {
      free(*(int *)(param_1 + 0x1c));
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
    return;
  }
  iVar3 = -1;
  pcVar6 = param_2;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  if (iVar3 == -2) goto LAB_00466748;
  pcVar6 = *(char **)(param_1 + 0x1c);
  if (pcVar6 != (char *)0x0) {
    uVar4 = 0xffffffff;
    pcVar7 = param_2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar5 = 0xffffffff;
    pcVar7 = pcVar6;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (~uVar4 - 1 <= ~uVar5 - 1) goto LAB_00466721;
    if (pcVar6 != (char *)0x0) {
      free(pcVar6);
    }
  }
  uVar4 = 0xffffffff;
  pcVar6 = param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar2 = malloc(~uVar4);
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
LAB_00466721:
  uVar4 = 0xffffffff;
  do {
    pcVar6 = param_2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar6 + -uVar4;
  pcVar7 = *(char **)(param_1 + 0x1c);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00466766
// Address: 00466766
undefined4 __fastcall FUN_00466766(int param_1)
{
  return *(undefined4 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_00466774
// Address: 00466774
undefined4 __fastcall FUN_00466774(int param_1)
{
  return *(undefined4 *)(param_1 + 0x10);
}

// --------------------------------------------------

// Function: FUN_00466784
// Address: 00466784
undefined4 __fastcall FUN_00466784(int param_1)
{
  return *(undefined4 *)(param_1 + 0x14);
}

// --------------------------------------------------

// Function: FUN_00466794
// Address: 00466794
undefined4 __fastcall FUN_00466794(int param_1)
{
  return *(undefined4 *)(param_1 + 0x18);
}

// --------------------------------------------------

// Function: FUN_004667a4
// Address: 004667a4
undefined4 __fastcall FUN_004667a4(int param_1)
{
  return *(undefined4 *)(param_1 + 0x20);
}

// --------------------------------------------------

// Function: FUN_004667b4
// Address: 004667b4
void __thiscall FUN_004667b4(int param_1,undefined4 *param_2)
{
  *param_2 = *(undefined4 *)(param_1 + 0x24);
  param_2[1] = *(undefined4 *)(param_1 + 0x28);
  param_2[2] = *(undefined4 *)(param_1 + 0x2c);
  param_2[3] = *(undefined4 *)(param_1 + 0x30);
  return;
}

// --------------------------------------------------

// Function: FUN_004667e4
// Address: 004667e4
void __thiscall
FUN_004667e4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  *(undefined4 *)(param_1 + 0x28) = param_3;
  *(undefined4 *)(param_1 + 0x2c) = param_4;
  *(undefined4 *)(param_1 + 0x30) = param_5;
  return;
}

// --------------------------------------------------

// Function: FUN_00466811
// Address: 00466811
void FUN_00466811(int *param_1)
{
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*param_1)(1);
    *param_1 = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046683b
// Address: 0046683b
bool FUN_0046683b(undefined4 param_1,char *param_2,undefined4 param_3)
{
  (**(code **)(rge_base_game->_padding_ + 0x20))(param_1,param_2,param_3);
  return *param_2 != '\0';
}

// --------------------------------------------------

// Function: FUN_00466868
// Address: 00466868
undefined4 __thiscall FUN_00466868(TPanel *param_1,int param_2)
{
  TPanel::get_string(param_1,param_2,&UNK_0062e66c.field_0x4,0x200);
  return 0x62e670;
}

// --------------------------------------------------

// Function: FUN_0046688c
// Address: 0046688c
undefined4 __fastcall FUN_0046688c(int param_1)
{
  return *(undefined4 *)(param_1 + 0xe4);
}

// --------------------------------------------------

// Function: FUN_00466897
// Address: 00466897
undefined4 __fastcall FUN_00466897(int param_1)
{
  return *(undefined4 *)(param_1 + 0xe8);
}

// --------------------------------------------------

// Function: FUN_004668a7
// Address: 004668a7
void __thiscall FUN_004668a7(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0xe4) = param_2;
  *(undefined4 *)(param_1 + 0xe8) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_004668c7
// Address: 004668c7
undefined4 __thiscall
FUN_004668c7(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  TPanel *unaff_EBP;
  char *pcVar7;
  long *unaff_retaddr;
  
  if ((param_1[0x1b] != 0) && (iVar3 = (**(code **)(*param_1 + 0xbc))(param_4,param_5), iVar3 != 0))
{
    for (puVar1 = (undefined4 *)param_1[0x17]; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[1]) {
      cVar2 = (**(code **)(*(int *)*puVar1 + 0xcc))(param_1,unaff_retaddr,param_2,param_5);
      if (cVar2 != '\0') {
        return 1;
      }
    }
    if (-1 < unaff_EBP->help_string_id) {
      pcVar4 = TPanel::get_string(unaff_EBP,unaff_EBP->help_string_id);
      uVar5 = 0xffffffff;
      do {
        pcVar7 = pcVar4;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar7 = pcVar4 + 1;
        cVar2 = *pcVar4;
        pcVar4 = pcVar7;
      } while (cVar2 != '\0');
      uVar5 = ~uVar5;
      pcVar4 = pcVar7 + -uVar5;
      pcVar7 = (char *)*param_1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar7 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar7 = pcVar7 + 1;
      }
      *unaff_retaddr = unaff_EBP->help_page_id;
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046697e
// Address: 0046697e
void __fastcall FUN_0046697e(int param_1)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 0x58); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[2]) {
    (**(code **)(*(int *)*puVar1 + 0xd0))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046699b
// Address: 0046699b
undefined4 __fastcall FUN_0046699b(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  for (puVar1 = *(undefined4 **)(param_1 + 0x58); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[2]) {
    iVar2 = (**(code **)(*(int *)*puVar1 + 0xd4))();
    if (iVar2 == 0) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_004669ca
// Address: 004669ca
void __fastcall FUN_004669ca(int param_1)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 0x58); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[2]) {
    (**(code **)(*(int *)*puVar1 + 0xdc))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004669eb
// Address: 004669eb
void __thiscall FUN_004669eb(int param_1,undefined4 *param_2)
{
  *param_2 = *(undefined4 *)(param_1 + 0x8c);
  param_2[1] = *(undefined4 *)(param_1 + 0x90);
  param_2[2] = *(undefined4 *)(param_1 + 0x94);
  param_2[3] = *(undefined4 *)(param_1 + 0x98);
  return;
}

// --------------------------------------------------

// Function: FUN_00466a1a
// Address: 00466a1a
TEasy_Panel * __thiscall FUN_00466a1a(TEasy_Panel *param_1,char *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055de38;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel((TPanel *)param_1,param_2);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TEasy_Panel::_vftable_;
  TEasy_Panel::init_vars(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00466a8e
// Address: 00466a8e
// [HELPER] s__s: "%s"
// [HELPER] s__s__s__s__d__d____s__s__s__d__d_: "%s %s %s %d %d   %s %s %s %d %d   %s %s %s %d %d   %s %s %d   %s %s %d   %s %..."
// [HELPER] s__s_sin: "%s.sin"
// [HELPER] s_none: "none"
// [HELPER] shape_file_first: " "
undefined4 __thiscall
FUN_00466a8e(TEasy_Panel *param_1,TDrawArea *param_2,TPanel *param_3,char *param_4,long param_5,
            int param_6,long param_7,long param_8,long param_9,long param_10,int param_11)
{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 unaff_BL;
  int unaff_EBP;
  uchar *puVar4;
  char *pcVar5;
  char *pcVar6;
  uint uStack_cc8;
  long lStack_cc4;
  undefined1 auStack_cc0 [4];
  long lStack_cbc;
  undefined1 auStack_cb8 [4];
  long lStack_cb4;
  uint uStack_cb0;
  long lStack_cac;
  undefined1 auStack_ca8 [4];
  int iStack_ca4;
  undefined1 auStack_ca0 [4];
  uchar auStack_c9c [4];
  uint uStack_c98;
  uchar auStack_c94 [4];
  undefined1 auStack_c90 [4];
  uchar auStack_c8c [4];
  undefined1 auStack_c88 [4];
  undefined1 auStack_c84 [4];
  uint uStack_c80;
  uint uStack_c7c;
  long lStack_c78;
  undefined1 auStack_c74 [4];
  long lStack_c70;
  undefined1 auStack_c6c [4];
  uchar auStack_c68 [4];
  uchar auStack_c64 [4];
  long lStack_c60;
  uchar auStack_c5c [4];
  long lStack_c58;
  undefined1 auStack_c54 [4];
  long lStack_c50;
  undefined1 auStack_c4c [4];
  uchar auStack_c48 [4];
  uint uStack_c44;
  long lStack_c40;
  long lStack_c3c;
  int iStack_c38;
  undefined1 auStack_c34 [256];
  undefined1 auStack_b34 [260];
  char acStack_a30 [260];
  char acStack_92c [260];
  char acStack_828 [260];
  char acStack_724 [260];
  char acStack_620 [260];
  char acStack_51c [260];
  char acStack_418 [260];
  char acStack_314 [260];
  char acStack_210 [260];
  char acStack_10c [268];
  
  uStack_cc8 = 0xffffffff;
  param_1->allow_shadow_area = param_11;
  TEasy_Panel::set_info_file(param_1,param_4,param_5);
  if (param_6 == 0) {
    if (((0 < param_9) && (0 < param_10)) && (param_2 != (TDrawArea *)0x0)) {
      if (param_7 == -1) {
        param_7 = param_2->Width / 2 - param_9 / 2;
      }
      if (param_8 == -1) {
        param_8 = param_2->Height / 2 - param_10 / 2;
      }
    }
  }
  else {
    param_7 = 0;
    param_8 = 0;
    if (param_2 == (TDrawArea *)0x0) {
      param_9 = 0;
      param_10 = 0;
    }
    else {
      param_9 = param_2->Width;
      param_10 = param_2->Height;
    }
  }
  lVar1 = TPanel::setup((TPanel *)param_1,param_2,param_3,param_7,param_8,param_9,param_10,'\0');
  if (lVar1 != 0) {
    iVar2 = param_1->_padding_;
    (**(code **)(iVar2 + 0xe4))(param_9,param_10);
    if (param_4 != (char *)0x0) {
      (**(code **)(iVar2 + 0x18))(1,0,0,0,0,0,0,0,0,0,0,0,0);
    }
    puVar4 = (uchar *)0x0;
    if (((shape_file_first != '\0') && (pcVar6 = param_1->info_file_name, pcVar6 != (char *)0x0)) &&
       (*pcVar6 != '\0')) {
      iVar2 = strchr(pcVar6,0x2e);
      if (iVar2 == 0) {
        pcVar5 = s__s_sin;
      }
      else {
        pcVar5 = s__s;
      }
      sprintf(auStack_b34,pcVar5,pcVar6);
      iVar2 = __open(auStack_b34,0x8000);
      if (iVar2 != -1) {
        lseek(iVar2,0,2);
        uVar3 = __tell(iVar2);
        puVar4 = (uchar *)malloc(uVar3);
        if (puVar4 != (uchar *)0x0) {
          lseek(iVar2,0,0);
          read(iVar2,puVar4,uVar3);
          unaff_EBP = 1;
        }
        close(iVar2);
      }
    }
    if (puVar4 == (uchar *)0x0) {
      if (param_1->info_id != 0xffffffff) {
        puVar4 = RESFILE_load(0x62696e61,param_1->info_id,(int *)&stack0xfffff330,&iStack_c38);
      }
      if (puVar4 == (uchar *)0x0) {
        return 1;
      }
    }
    iVar2 = sscanf(puVar4,s__s__s__s__d__d____s__s__s__d__d_,auStack_c34,acStack_210,acStack_828,
                   &lStack_c60,&lStack_cb4,auStack_c34,acStack_a30,acStack_620,&lStack_c3c,
                   &lStack_cc4,auStack_c34,acStack_418,acStack_92c,&lStack_c50,&lStack_cbc,
                   auStack_c34,acStack_724,&lStack_cac,auStack_c34,acStack_51c,&lStack_c58,
                   auStack_c34,auStack_c34,&lStack_c40,auStack_c34,acStack_314,&lStack_c78,
                   auStack_c34,acStack_10c,&lStack_c70,auStack_c34,&iStack_ca4,auStack_c34,
                   auStack_c48,auStack_c34,auStack_c5c,auStack_c8c,auStack_c64,auStack_c94,
                   auStack_c68,auStack_c9c,auStack_c34,&uStack_c44,auStack_c74,auStack_c4c,
                   auStack_c34,&uStack_c7c,auStack_c54,auStack_c84,auStack_c34,&uStack_cb0,
                   auStack_cb8,auStack_cc0,auStack_c34,&uStack_cc8,&stack0xfffff334,auStack_c6c,
                   auStack_c34,&uStack_c80,auStack_c88,auStack_c90,auStack_c34,&uStack_c98,
                   auStack_ca0,auStack_ca8);
    if (iVar2 != -1) {
      TEasy_Panel::set_use_bevels(param_1,1);
      if ((*(int *)(param_1->_padding_ + 0x18) < 800) ||
         (iVar2 = stricmp(acStack_a30,s_none), iVar2 == 0)) {
        TEasy_Panel::set_background(param_1,acStack_210,lStack_c60);
        pcVar6 = acStack_828;
        lStack_cc4 = lStack_cb4;
      }
      else if (*(int *)(param_1->_padding_ + 0x18) < 0x400) {
        TEasy_Panel::set_background(param_1,acStack_a30,lStack_c3c);
        pcVar6 = acStack_620;
      }
      else {
        TEasy_Panel::set_background(param_1,acStack_418,lStack_c50);
        pcVar6 = acStack_92c;
        lStack_cc4 = lStack_cbc;
      }
      TEasy_Panel::set_background2(param_1,pcVar6,lStack_cc4);
      TEasy_Panel::set_shadow_amount(param_1,lStack_c40);
      TEasy_Panel::set_palette(param_1,acStack_724,lStack_cac);
      TEasy_Panel::set_cursor(param_1,acStack_51c,lStack_c58);
      TEasy_Panel::set_background_pos(param_1,iStack_ca4);
      TEasy_Panel::set_background_colors(param_1,auStack_c48[0],auStack_c48[0]);
      TEasy_Panel::set_bevel_colors
                (param_1,auStack_c5c[0],auStack_c8c[0],auStack_c64[0],auStack_c94[0],auStack_c68[0],
                 auStack_c9c[0]);
      TEasy_Panel::set_text_colors
                (param_1,(uint)CONCAT11(auStack_c4c[0],auStack_c74[0]) << 8 | uStack_c44 & 0xff,
                 (uint)CONCAT11(auStack_c84[0],auStack_c54[0]) << 8 | uStack_c7c & 0xff);
      TEasy_Panel::set_focus_colors
                (param_1,(uint)CONCAT11(auStack_cc0[0],auStack_cb8[0]) << 8 | uStack_cb0 & 0xff,
                 (uint)CONCAT11(auStack_c6c[0],unaff_BL) << 8 | uStack_cc8 & 0xff);
      TEasy_Panel::set_state_colors
                (param_1,(uint)CONCAT11(auStack_c90[0],auStack_c88[0]) << 8 | uStack_c80 & 0xff,
                 (uint)CONCAT11(auStack_ca8[0],auStack_ca0[0]) << 8 | uStack_c98 & 0xff);
      TEasy_Panel::set_button_pics(param_1,acStack_314,lStack_c78);
      TEasy_Panel::set_popup_info_file(param_1,acStack_10c,lStack_c70);
    }
    if (unaff_EBP == 1) {
      free(puVar4);
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004670f9
// Address: 004670f9
TEasy_Panel * __fastcall FUN_004670f9(TEasy_Panel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055de58;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel((TPanel *)param_1);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TEasy_Panel::_vftable_;
  TEasy_Panel::init_vars(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00467149
// Address: 00467149
void __fastcall FUN_00467149(int param_1)
{
  *(undefined4 *)(param_1 + 0xf4) = 0x280;
  *(undefined4 *)(param_1 + 0xf8) = 0x1e0;
  *(undefined1 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined4 *)(param_1 + 0x208) = 0;
  *(undefined4 *)(param_1 + 0x20c) = 0;
  *(undefined1 *)(param_1 + 0x210) = 0;
  *(undefined4 *)(param_1 + 0x314) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x318) = 0;
  *(undefined4 *)(param_1 + 0x31c) = 0;
  *(undefined1 *)(param_1 + 800) = 0;
  *(undefined1 *)(param_1 + 0x321) = 0;
  *(undefined1 *)(param_1 + 0x322) = 0;
  *(undefined1 *)(param_1 + 0x323) = 0;
  *(undefined1 *)(param_1 + 0x324) = 0;
  *(undefined1 *)(param_1 + 0x325) = 0;
  *(undefined4 *)(param_1 + 0x328) = 0xffffff;
  *(undefined4 *)(param_1 + 0x32c) = 0;
  *(undefined4 *)(param_1 + 0x330) = 0xffff;
  *(undefined4 *)(param_1 + 0x334) = 0;
  *(undefined4 *)(param_1 + 0x338) = 0xffffff;
  *(undefined4 *)(param_1 + 0x33c) = 0;
  *(undefined1 *)(param_1 + 0x340) = 0;
  *(undefined4 *)(param_1 + 0x444) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x448) = 0;
  *(undefined4 *)(param_1 + 0x44c) = 0;
  *(undefined1 *)(param_1 + 0x454) = 0;
  *(undefined1 *)(param_1 + 0x455) = 0;
  *(undefined4 *)(param_1 + 0x458) = 0;
  *(undefined1 *)(param_1 + 0x45c) = 0;
  *(undefined4 *)(param_1 + 0x460) = 0;
  *(undefined4 *)(param_1 + 0x464) = 0;
  *(undefined4 *)(param_1 + 0x468) = 0;
  *(undefined4 *)(param_1 + 0x450) = 0;
  *(undefined4 *)(param_1 + 0x46c) = 0;
  *(undefined4 *)(param_1 + 0x474) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00467248
// Address: 00467248
void __fastcall FUN_00467248(TEasy_Panel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055de78;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TEasy_Panel::_vftable_;
  uStack_4 = 0;
  TEasy_Panel::prepare_for_close(param_1);
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0046729f
// Address: 0046729f
void __fastcall FUN_0046729f(int param_1)
{
  TDrawArea *this;
  TShape *pTVar1;
  
  this = *(TDrawArea **)(param_1 + 0x46c);
  if (this != (TDrawArea *)0x0) {
    TDrawArea::~TDrawArea(this);
    operator_delete(this);
    *(undefined4 *)(param_1 + 0x46c) = 0;
  }
  if (*(int *)(param_1 + 0x464) != 0) {
    if (*(int *)(param_1 + 0x460) == 0) {
      DeleteObject(*(int *)(param_1 + 0x464));
    }
    *(undefined4 *)(param_1 + 0x464) = 0;
  }
  pTVar1 = *(TShape **)(param_1 + 0x204);
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)(param_1 + 0x204) = 0;
  }
  pTVar1 = *(TShape **)(param_1 + 0x208);
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)(param_1 + 0x208) = 0;
  }
  if (*(void **)(param_1 + 0x20c) != (void *)0x0) {
    TPanelSystem::release_palette(&panel_system,*(void **)(param_1 + 0x20c));
    *(undefined4 *)(param_1 + 0x20c) = 0;
  }
  if (*(undefined4 **)(param_1 + 0x44c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x44c))(1);
    *(undefined4 *)(param_1 + 0x44c) = 0;
  }
  pTVar1 = *(TShape **)(param_1 + 0x448);
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)(param_1 + 0x448) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046737b
// Address: 0046737b
// [HELPER] s__s_Shadow_Panel: "%s Shadow Panel"
// [HELPER] s_panel_ez__setup_shadow_area: "panel_ez::setup_shadow_area"
void __thiscall FUN_0046737b(int param_1,int param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  TDrawArea *pTStack_11c;
  int iStack_118;
  int iStack_114;
  int iStack_110;
  char acStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055de9e;
  *unaff_FS_OFFSET = &uStack_c;
  if ((((*(int *)(param_1 + 0x46c) == 0) || (param_2 != 0)) && (*(int *)(param_1 + 0x204) != 0)) &&
     (*(int *)(param_1 + 0x44c) != 0)) {
    iVar5 = **(int **)(param_1 + 0x20);
    uVar1 = *(undefined4 *)(iVar5 + 0x28);
    if (*(int *)(param_1 + 0x46c) == 0) {
      *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) & 1;
      sprintf(acStack_10c,s__s_Shadow_Panel,*(undefined4 *)(param_1 + 0x1c));
      pTStack_11c = (TDrawArea *)operator_new(0x100);
      uStack_4 = 0;
      if (pTStack_11c == (TDrawArea *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = TDrawArea::TDrawArea(pTStack_11c,acStack_10c,0);
      }
      *(undefined4 *)(param_1 + 0x46c) = uVar2;
    }
    uStack_4 = 0xffffffff;
    if (*(int *)(param_1 + 0x46c) != 0) {
      TShape::shape_minmax
                (*(TShape **)(param_1 + 0x204),&iStack_114,(long *)&pTStack_11c,&iStack_110,
                 &iStack_118,0);
      iVar6 = (iStack_110 - iStack_114) + 1;
      iVar5 = (iStack_118 - (int)pTStack_11c) + 1;
      if (*(int *)(param_1 + 0x14) < iVar6) {
        iVar6 = *(int *)(param_1 + 0x14);
      }
      if (*(int *)(param_1 + 0x18) < iVar5) {
        iVar5 = *(int *)(param_1 + 0x18);
      }
      iVar3 = TDrawArea::Init(*(TDrawArea **)(param_1 + 0x46c),
                              (TDrawSystem *)**(undefined4 **)(param_1 + 0x20),iVar6,iVar5,0,0);
      if (iVar3 != 0) {
        TDrawArea::Clear(*(TDrawArea **)(param_1 + 0x46c),(tagRECT *)0x0,
                         (uint)*(byte *)(param_1 + 0x454));
        puVar4 = TDrawArea::Lock(*(TDrawArea **)(param_1 + 0x46c),s_panel_ez__setup_shadow_area,1);
        if (puVar4 != (uchar *)0x0) {
          TShape::shape_draw(*(TShape **)(param_1 + 0x204),*(TDrawArea **)(param_1 + 0x46c),0,0,0,
                             '\0',(uchar *)0x0);
          TDrawArea::SetShadowTable
                    (*(TDrawArea **)(param_1 + 0x46c),*(RGE_Color_Table **)(param_1 + 0x44c));
          TDrawArea::DrawShadowBox(*(TDrawArea **)(param_1 + 0x46c),0,0,iVar6 + -1,iVar5 + -1);
          TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x46c),s_panel_ez__setup_shadow_area);
        }
      }
    }
    *(undefined4 *)(**(int **)(param_1 + 0x20) + 0x28) = uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00467558
// Address: 00467558
void __thiscall FUN_00467558(TPanel *param_1,int param_2)
{
  TPanel::draw_setup(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0046756d
// Address: 0046756d
void __fastcall FUN_0046756d(TEasy_Panel *param_1)
{
  if (*(char *)((int)&param_1->_padding_ + 3) != '\0') {
    if (param_1->shadow_area != (TDrawArea *)0x0) {
      TEasy_Panel::setup_shadow_area(param_1,1);
    }
    *(undefined1 *)((int)&param_1->_padding_ + 3) = 0;
  }
  if (*(char *)((int)&param_1->_padding_ + 2) != '\0') {
    (**(code **)(param_1->_padding_ + 0xe0))(1);
    return;
  }
  (**(code **)(param_1->_padding_ + 0xe0))(0);
  return;
}

// --------------------------------------------------

// Function: FUN_004675bb
// Address: 004675bb
// [HELPER] s_panel_ez__draw_background2: "panel_ez::draw_background2"
// [HELPER] s_panel_ez__draw_background: "panel_ez::draw_background"
void __fastcall FUN_004675bb(int *param_1)
{
  byte bVar1;
  TDrawArea *this;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  TShape *this_00;
  int unaff_retaddr;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iStack_4 = *param_1;
  (**(code **)(iStack_4 + 0x28))(0);
  if (unaff_retaddr == 0) {
LAB_004676fe:
    this_00 = (TShape *)param_1[0x81];
  }
  else {
    if (param_1[0x11b] != 0) {
      if (param_1[0xe] == 2) {
        TDrawArea::Clear((TDrawArea *)param_1[8],(tagRECT *)(param_1 + 9),
                         (uint)*(byte *)((int)param_1 + 0x455));
      }
      this = (TDrawArea *)param_1[0x11b];
      iVar3 = param_1[0xc6];
      iVar4 = this->Height;
      iVar5 = this->Width;
      if (iVar3 == 0) {
        TDrawArea::Copy(this,(TDrawArea *)param_1[8],param_1[3],param_1[4],(tagRECT *)0x0,0);
      }
      else if (iVar3 == 1) {
        TDrawArea::Copy(this,(TDrawArea *)param_1[8],
                        (int)(short)(((short)param_1[3] + (short)(param_1[5] / 2)) -
                                    (short)(iVar5 / 2)),
                        (int)(short)(((short)param_1[4] + (short)(param_1[6] / 2)) -
                                    (short)(iVar4 / 2)),(tagRECT *)0x0,0);
      }
      else if ((iVar3 == 2) && (iVar3 = 0, -1 < param_1[6])) {
        do {
          iVar6 = 0;
          if (-1 < param_1[5]) {
            do {
              TDrawArea::Copy((TDrawArea *)param_1[0x11b],(TDrawArea *)param_1[8],iVar6 + param_1[3]
                              ,iVar3 + param_1[4],(tagRECT *)0x0,0);
              iVar6 = iVar6 + iVar5;
            } while (iVar6 <= param_1[5]);
          }
          iVar3 = iVar3 + iVar4;
        } while (iVar3 <= param_1[6]);
      }
      goto LAB_0046790c;
    }
    if ((unaff_retaddr == 0) || (this_00 = (TShape *)param_1[0x82], this_00 == (TShape *)0x0))
    goto LAB_004676fe;
  }
  if ((param_1[0xe] == 2) || (this_00 == (TShape *)0x0)) {
    if (unaff_retaddr == 0) {
      bVar1 = *(byte *)(param_1 + 0x115);
    }
    else {
      bVar1 = *(byte *)((int)param_1 + 0x455);
    }
    TDrawArea::Clear((TDrawArea *)param_1[8],(tagRECT *)(param_1 + 9),(uint)bVar1);
    if (this_00 == (TShape *)0x0) goto LAB_0046790c;
  }
  puVar2 = TDrawArea::Lock((TDrawArea *)param_1[8],s_panel_ez__draw_background,1);
  if (puVar2 == (uchar *)0x0) goto LAB_0046790c;
  TShape::shape_minmax(this_00,&iStack_14,&iStack_c,&iStack_18,&iStack_10,0);
  iVar4 = (iStack_18 - iStack_14) + 1;
  iVar3 = (iStack_10 - iStack_c) + 1;
  if (param_1[0xc6] == 1) {
    iVar6 = (int)(short)(((short)param_1[3] + (short)(param_1[5] / 2)) - (short)(iVar4 / 2));
    iVar5 = (int)(short)(((short)param_1[4] + (short)(param_1[6] / 2)) - (short)(iVar3 / 2));
    TShape::shape_draw(this_00,(TDrawArea *)param_1[8],iVar6,iVar5,0,'\0',(uchar *)0x0);
    if ((unaff_retaddr != 0) && ((RGE_Color_Table *)param_1[0x113] != (RGE_Color_Table *)0x0)) {
      TDrawArea::SetShadowTable((TDrawArea *)param_1[8],(RGE_Color_Table *)param_1[0x113]);
      iVar4 = iVar6 + -1 + iVar4;
      iVar3 = iVar5 + -1 + iVar3;
      goto LAB_004678f7;
    }
  }
  else if (param_1[0xc6] == 2) {
    iVar5 = 0;
    if (-1 < param_1[6]) {
      do {
        iVar6 = 0;
        if (-1 < param_1[5]) {
          do {
            TShape::shape_draw(this_00,(TDrawArea *)param_1[8],iVar6 + param_1[3],iVar5 + param_1[4]
                               ,0,'\0',(uchar *)0x0);
            iVar6 = iVar6 + iVar4;
          } while (iVar6 <= param_1[5]);
        }
        iVar5 = iVar5 + iVar3;
      } while (iVar5 <= param_1[6]);
    }
    if ((unaff_retaddr != 0) && ((RGE_Color_Table *)param_1[0x113] != (RGE_Color_Table *)0x0)) {
      TDrawArea::SetShadowTable((TDrawArea *)param_1[8],(RGE_Color_Table *)param_1[0x113]);
      iVar5 = param_1[4];
      iVar6 = param_1[3];
      iVar3 = iVar5 + -1 + param_1[6];
      iVar4 = param_1[5] + -1 + iVar6;
      goto LAB_004678f7;
    }
  }
  else {
    TShape::shape_draw(this_00,(TDrawArea *)param_1[8],param_1[3],param_1[4],0,'\0',(uchar *)0x0);
    if ((unaff_retaddr != 0) && ((RGE_Color_Table *)param_1[0x113] != (RGE_Color_Table *)0x0)) {
      TDrawArea::SetShadowTable((TDrawArea *)param_1[8],(RGE_Color_Table *)param_1[0x113]);
      iVar5 = param_1[4];
      iVar6 = param_1[3];
      iVar3 = (iStack_10 - iStack_c) + iVar5;
      iVar4 = (iStack_18 - iStack_14) + iVar6;
LAB_004678f7:
      TDrawArea::DrawShadowBox((TDrawArea *)param_1[8],iVar6,iVar5,iVar4,iVar3);
    }
  }
  TDrawArea::Unlock((TDrawArea *)param_1[8],s_panel_ez__draw_background);
LAB_0046790c:
  if ((param_1[199] != 0) &&
     (puVar2 = TDrawArea::Lock((TDrawArea *)param_1[8],s_panel_ez__draw_background2,1),
     puVar2 != (uchar *)0x0)) {
    TDrawArea::DrawBevel3
              ((TDrawArea *)param_1[8],param_1[3],param_1[4],param_1[5] + -1 + param_1[3],
               param_1[6] + -1 + param_1[4],(uchar)param_1[200],*(uchar *)((int)param_1 + 0x321),
               *(uchar *)((int)param_1 + 0x322),*(uchar *)((int)param_1 + 0x323),
               (uchar)param_1[0xc9],*(uchar *)((int)param_1 + 0x325));
    TDrawArea::Unlock((TDrawArea *)param_1[8],s_panel_ez__draw_background2);
  }
  (**(code **)(iStack_8 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_00467993
// Address: 00467993
long __thiscall
FUN_00467993(TEasy_Panel *param_1,uchar param_2,long param_3,long param_4,int param_5,int param_6)
{
  long lVar1;
  
  lVar1 = TEasy_Panel::command_do_popup_help(param_1,param_2,param_3,param_4);
  if (lVar1 != 0) {
    return 1;
  }
  lVar1 = TPanel::handle_mouse_down((TPanel *)param_1,param_2,param_3,param_4,param_5,param_6);
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_004679e5
// Address: 004679e5
void __thiscall FUN_004679e5(int param_1,char *param_2,undefined4 param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    *(undefined1 *)(param_1 + 0xfc) = 0;
    *(undefined4 *)(param_1 + 0x200) = param_3;
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = (char *)(param_1 + 0xfc);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  *(undefined4 *)(param_1 + 0x200) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00467a45
// Address: 00467a45
void __thiscall FUN_00467a45(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0xf4) = param_2;
  *(undefined4 *)(param_1 + 0xf8) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00467a67
// Address: 00467a67
// [HELPER] s_: ""
// [HELPER] s__s: "%s"
// [HELPER] s__s_shp: "%s.shp"
// [HELPER] s_none: "none"
bool __thiscall FUN_00467a67(int param_1,char *param_2,int param_3)
{
  int iVar1;
  TShape *pTVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar4;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055decc;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar2 = *(TShape **)(param_1 + 0x204);
  if (pTVar2 != (TShape *)0x0) {
    TShape::~TShape(pTVar2);
    operator_delete(pTVar2);
    *(undefined4 *)(param_1 + 0x204) = 0;
  }
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
LAB_00467b36:
    if (param_3 == -1) goto LAB_00467b81;
    pTVar2 = (TShape *)operator_new(0x20);
    uStack_4 = 1;
    if (pTVar2 == (TShape *)0x0) goto LAB_00467b6e;
    uVar3 = TShape::TShape(pTVar2,s_,param_3);
  }
  else {
    iVar1 = stricmp(param_2,s_none);
    if (iVar1 == 0) goto LAB_00467b36;
    iVar1 = strchr(param_2,0x2e);
    if (iVar1 == 0) {
      pcVar4 = s__s_shp;
    }
    else {
      pcVar4 = s__s;
    }
    sprintf(acStack_110,pcVar4,param_2);
    pTVar2 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTVar2 == (TShape *)0x0) {
LAB_00467b6e:
      uVar3 = 0;
    }
    else {
      uVar3 = TShape::TShape(pTVar2,acStack_110,param_3);
    }
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x204) = uVar3;
LAB_00467b81:
  if (*(TShape **)(param_1 + 0x204) != (TShape *)0x0) {
    iVar1 = TShape::is_loaded(*(TShape **)(param_1 + 0x204));
    if (iVar1 == 0) {
      pTVar2 = *(TShape **)(param_1 + 0x204);
      if (pTVar2 != (TShape *)0x0) {
        TShape::~TShape(pTVar2);
        operator_delete(pTVar2);
      }
      *(undefined4 *)(param_1 + 0x204) = 0;
    }
  }
  iVar1 = *(int *)(param_1 + 0x204);
  *unaff_FS_OFFSET = uStack_c;
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_00467bde
// Address: 00467bde
// [HELPER] s_: ""
// [HELPER] s__s: "%s"
// [HELPER] s__s_shp: "%s.shp"
// [HELPER] s_none: "none"
bool __thiscall FUN_00467bde(int param_1,char *param_2,int param_3)
{
  int iVar1;
  TShape *pTVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar4;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055defc;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar2 = *(TShape **)(param_1 + 0x208);
  if (pTVar2 != (TShape *)0x0) {
    TShape::~TShape(pTVar2);
    operator_delete(pTVar2);
    *(undefined4 *)(param_1 + 0x208) = 0;
  }
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
LAB_00467ca6:
    if (param_3 == -1) goto LAB_00467cf1;
    pTVar2 = (TShape *)operator_new(0x20);
    uStack_4 = 1;
    if (pTVar2 == (TShape *)0x0) goto LAB_00467cde;
    uVar3 = TShape::TShape(pTVar2,s_,param_3);
  }
  else {
    iVar1 = stricmp(param_2,s_none);
    if (iVar1 == 0) goto LAB_00467ca6;
    iVar1 = strchr(param_2,0x2e);
    if (iVar1 == 0) {
      pcVar4 = s__s_shp;
    }
    else {
      pcVar4 = s__s;
    }
    sprintf(acStack_110,pcVar4,param_2);
    pTVar2 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTVar2 == (TShape *)0x0) {
LAB_00467cde:
      uVar3 = 0;
    }
    else {
      uVar3 = TShape::TShape(pTVar2,acStack_110,param_3);
    }
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x208) = uVar3;
LAB_00467cf1:
  if (*(TShape **)(param_1 + 0x208) != (TShape *)0x0) {
    iVar1 = TShape::is_loaded(*(TShape **)(param_1 + 0x208));
    if (iVar1 == 0) {
      pTVar2 = *(TShape **)(param_1 + 0x208);
      if (pTVar2 != (TShape *)0x0) {
        TShape::~TShape(pTVar2);
        operator_delete(pTVar2);
      }
      *(undefined4 *)(param_1 + 0x208) = 0;
    }
  }
  iVar1 = *(int *)(param_1 + 0x208);
  *unaff_FS_OFFSET = uStack_c;
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_00467d4e
// Address: 00467d4e
void __thiscall FUN_00467d4e(int *param_1,undefined4 param_2)
{
  int iVar1;
  
  (**(code **)(*param_1 + 0x10))(param_2);
  *(undefined1 *)(param_1 + 0x115) = (undefined1)param_2;
  *(undefined1 *)((int)param_1 + 0x455) = (undefined1)param_2;
  iVar1 = GetStockObject(4);
  param_1[0x119] = iVar1;
  param_1[0x118] = 1;
  param_1[0x11a] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00467d95
// Address: 00467d95
// [HELPER] s_none: "none"
undefined4 __thiscall FUN_00467d95(int param_1,char *param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  RGE_Color_Table *this;
  undefined4 *unaff_FS_OFFSET;
  tagPALETTEENTRY atStack_40c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055df1e;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(void **)(param_1 + 0x20c) != (void *)0x0) {
    TPanelSystem::release_palette(&panel_system,*(void **)(param_1 + 0x20c));
    *(undefined4 *)(param_1 + 0x20c) = 0;
  }
  if (*(undefined4 **)(param_1 + 0x44c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x44c))(1);
    *(undefined4 *)(param_1 + 0x44c) = 0;
  }
  if (param_3 == -1) {
    if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
      iVar1 = stricmp(param_2,s_none);
      if (iVar1 == 0) {
        uVar2 = 1;
        goto LAB_00467ec7;
      }
      goto LAB_00467e39;
    }
  }
  else {
LAB_00467e39:
    pvVar3 = TPanelSystem::get_palette(&panel_system,param_2,param_3);
    *(void **)(param_1 + 0x20c) = pvVar3;
    if ((pvVar3 == (void *)0x0) || (*(int *)(param_1 + 0x450) < 1)) {
      uVar2 = 0;
      goto LAB_00467ec7;
    }
    iVar1 = GetPaletteEntries(pvVar3,0,0x100,atStack_40c);
    if (iVar1 != 0) {
      this = (RGE_Color_Table *)operator_new(0x128);
      uStack_4 = 0;
      if (this != (RGE_Color_Table *)0x0) {
        uVar2 = RGE_Color_Table::RGE_Color_Table
                          (this,*(TDrawArea **)(param_1 + 0x20),*(long *)(param_1 + 0x450),
                           (tagPALETTEENTRY *)0x0,atStack_40c);
        *(undefined4 *)(param_1 + 0x44c) = uVar2;
        uVar2 = 1;
        goto LAB_00467ec7;
      }
      *(undefined4 *)(param_1 + 0x44c) = 0;
    }
  }
  uVar2 = 1;
LAB_00467ec7:
  *unaff_FS_OFFSET = uStack_c;
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_00467ee1
// Address: 00467ee1
undefined4 __thiscall FUN_00467ee1(int param_1,char *param_2,undefined4 param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = (char *)(param_1 + 0x210);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  *(undefined4 *)(param_1 + 0x314) = param_3;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00467f31
// Address: 00467f31
void __thiscall FUN_00467f31(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x31c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00467f4d
// Address: 00467f4d
void __thiscall FUN_00467f4d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x318) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00467f5d
// Address: 00467f5d
void __thiscall
FUN_00467f5d(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5
            ,undefined1 param_6,undefined1 param_7)
{
  *(undefined1 *)(param_1 + 800) = param_2;
  *(undefined1 *)(param_1 + 0x321) = param_3;
  *(undefined1 *)(param_1 + 0x322) = param_4;
  *(undefined1 *)(param_1 + 0x323) = param_5;
  *(undefined1 *)(param_1 + 0x324) = param_6;
  *(undefined1 *)(param_1 + 0x325) = param_7;
  return;
}

// --------------------------------------------------

// Function: FUN_00467f9f
// Address: 00467f9f
void __thiscall FUN_00467f9f(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x328) = param_2;
  *(undefined4 *)(param_1 + 0x32c) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00467fb7
// Address: 00467fb7
void __thiscall FUN_00467fb7(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x330) = param_2;
  *(undefined4 *)(param_1 + 0x334) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00467fd7
// Address: 00467fd7
void __thiscall FUN_00467fd7(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x338) = param_2;
  *(undefined4 *)(param_1 + 0x33c) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00467ff7
// Address: 00467ff7
void __thiscall FUN_00467ff7(int param_1,char *param_2,undefined4 param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    *(undefined1 *)(param_1 + 0x340) = 0;
    *(undefined4 *)(param_1 + 0x444) = param_3;
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = (char *)(param_1 + 0x340);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  *(undefined4 *)(param_1 + 0x444) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00468055
// Address: 00468055
// [HELPER] s_: ""
// [HELPER] s__s: "%s"
// [HELPER] s__s_shp: "%s.shp"
// [HELPER] s_none: "none"
void __thiscall FUN_00468055(int param_1,char *param_2,int param_3)
{
  int iVar1;
  TShape *pTVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar4;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055df4c;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar2 = *(TShape **)(param_1 + 0x448);
  if (pTVar2 != (TShape *)0x0) {
    TShape::~TShape(pTVar2);
    operator_delete(pTVar2);
    *(undefined4 *)(param_1 + 0x448) = 0;
  }
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
LAB_00468126:
    if (param_3 == -1) goto LAB_00468171;
    pTVar2 = (TShape *)operator_new(0x20);
    uStack_4 = 1;
    if (pTVar2 == (TShape *)0x0) goto LAB_0046815e;
    uVar3 = TShape::TShape(pTVar2,s_,param_3);
  }
  else {
    iVar1 = stricmp(param_2,s_none);
    if (iVar1 == 0) goto LAB_00468126;
    iVar1 = strchr(param_2,0x2e);
    if (iVar1 == 0) {
      pcVar4 = s__s_shp;
    }
    else {
      pcVar4 = s__s;
    }
    sprintf(acStack_110,pcVar4,param_2);
    pTVar2 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTVar2 == (TShape *)0x0) {
LAB_0046815e:
      uVar3 = 0;
    }
    else {
      uVar3 = TShape::TShape(pTVar2,acStack_110,param_3);
    }
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x448) = uVar3;
LAB_00468171:
  if (*(TShape **)(param_1 + 0x448) != (TShape *)0x0) {
    iVar1 = TShape::is_loaded(*(TShape **)(param_1 + 0x448));
    if (iVar1 == 0) {
      pTVar2 = *(TShape **)(param_1 + 0x448);
      if (pTVar2 != (TShape *)0x0) {
        TShape::~TShape(pTVar2);
        operator_delete(pTVar2);
      }
      *(undefined4 *)(param_1 + 0x448) = 0;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004681c1
// Address: 004681c1
void __thiscall FUN_004681c1(int *param_1,int param_2)
{
  int iVar1;
  RGE_Color_Table *this;
  undefined4 *unaff_FS_OFFSET;
  tagPALETTEENTRY atStack_40c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055df6e;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == -1) {
    param_1[0x114] = 0;
  }
  else {
    param_1[0x114] = param_2;
  }
  if ((undefined4 *)param_1[0x113] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x113])(1);
    param_1[0x113] = 0;
  }
  if ((param_1[0x83] != 0) && (0 < param_1[0x114])) {
    iVar1 = GetPaletteEntries(param_1[0x83],0,0x100,atStack_40c);
    if (iVar1 != 0) {
      this = (RGE_Color_Table *)operator_new(0x128);
      uStack_4 = 0;
      if (this == (RGE_Color_Table *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = RGE_Color_Table::RGE_Color_Table
                          (this,(TDrawArea *)param_1[8],param_1[0x114],(tagPALETTEENTRY *)0x0,
                           atStack_40c);
      }
      uStack_4 = 0xffffffff;
      param_1[0x113] = iVar1;
    }
  }
  if (param_1[0x1e] != 0) {
    (**(code **)(*param_1 + 0x20))(2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004682c4
// Address: 004682c4
void __thiscall FUN_004682c4(int param_1,int param_2)
{
  *(int *)(param_1 + 0x458) = param_2;
  if (*(int *)(param_1 + 0x78) != 0) {
    if (param_2 != 0) {
      TPanelSystem::EnableIME(&panel_system);
      return;
    }
    TPanelSystem::DisableIME(&panel_system);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004682fa
// Address: 004682fa
int __fastcall FUN_004682fa(int param_1)
{
  return param_1 + 0xfc;
}

// --------------------------------------------------

// Function: FUN_00468307
// Address: 00468307
undefined4 __fastcall FUN_00468307(int param_1)
{
  return *(undefined4 *)(param_1 + 0x200);
}

// --------------------------------------------------

// Function: FUN_00468317
// Address: 00468317
undefined4 __fastcall FUN_00468317(int param_1)
{
  return *(undefined4 *)(param_1 + 0x204);
}

// --------------------------------------------------

// Function: FUN_00468327
// Address: 00468327
undefined4 __fastcall FUN_00468327(int param_1)
{
  return *(undefined4 *)(param_1 + 0x208);
}

// --------------------------------------------------

// Function: FUN_00468337
// Address: 00468337
undefined4 __fastcall FUN_00468337(int param_1)
{
  return *(undefined4 *)(param_1 + 0x20c);
}

// --------------------------------------------------

// Function: FUN_00468347
// Address: 00468347
int __fastcall FUN_00468347(int param_1)
{
  return param_1 + 0x210;
}

// --------------------------------------------------

// Function: FUN_00468357
// Address: 00468357
undefined4 __fastcall FUN_00468357(int param_1)
{
  return *(undefined4 *)(param_1 + 0x31c);
}

// --------------------------------------------------

// Function: FUN_00468367
// Address: 00468367
undefined4 __fastcall FUN_00468367(int param_1)
{
  return *(undefined4 *)(param_1 + 0x318);
}

// --------------------------------------------------

// Function: FUN_00468377
// Address: 00468377
void __thiscall
FUN_00468377(int param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4,
            undefined1 *param_5,undefined1 *param_6,undefined1 *param_7)
{
  *param_2 = *(undefined1 *)(param_1 + 800);
  *param_3 = *(undefined1 *)(param_1 + 0x321);
  *param_4 = *(undefined1 *)(param_1 + 0x322);
  *param_5 = *(undefined1 *)(param_1 + 0x323);
  *param_6 = *(undefined1 *)(param_1 + 0x324);
  *param_7 = *(undefined1 *)(param_1 + 0x325);
  return;
}

// --------------------------------------------------

// Function: FUN_004683cb
// Address: 004683cb
void __thiscall FUN_004683cb(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  *param_2 = *(undefined4 *)(param_1 + 0x328);
  *param_3 = *(undefined4 *)(param_1 + 0x32c);
  return;
}

// --------------------------------------------------

// Function: FUN_004683eb
// Address: 004683eb
void __thiscall FUN_004683eb(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  *param_2 = *(undefined4 *)(param_1 + 0x330);
  *param_3 = *(undefined4 *)(param_1 + 0x334);
  return;
}

// --------------------------------------------------

// Function: FUN_0046840b
// Address: 0046840b
undefined4 __fastcall FUN_0046840b(int param_1)
{
  return *(undefined4 *)(param_1 + 0x450);
}

// --------------------------------------------------

// Function: FUN_00468417
// Address: 00468417
void __thiscall FUN_00468417(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  *param_2 = *(undefined4 *)(param_1 + 0x338);
  *param_3 = *(undefined4 *)(param_1 + 0x33c);
  return;
}

// --------------------------------------------------

// Function: FUN_0046843b
// Address: 0046843b
int __fastcall FUN_0046843b(int param_1)
{
  return param_1 + 0x340;
}

// --------------------------------------------------

// Function: FUN_00468447
// Address: 00468447
undefined4 __fastcall FUN_00468447(int param_1)
{
  return *(undefined4 *)(param_1 + 0x444);
}

// --------------------------------------------------

// Function: FUN_00468457
// Address: 00468457
undefined4 __fastcall FUN_00468457(int param_1)
{
  return *(undefined4 *)(param_1 + 0x448);
}

// --------------------------------------------------

// Function: FUN_00468467
// Address: 00468467
undefined4 __fastcall FUN_00468467(int param_1)
{
  return *(undefined4 *)(param_1 + 0x44c);
}

// --------------------------------------------------

// Function: FUN_00468477
// Address: 00468477
undefined4 __fastcall FUN_00468477(int param_1)
{
  return *(undefined4 *)(param_1 + 0x458);
}

// --------------------------------------------------

// Function: FUN_00468487
// Address: 00468487
void __thiscall
FUN_00468487(TPanel *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12)
{
  char acStack_f0 [120];
  char acStack_78 [120];
  
  TPanel::get_string(param_1,param_4,acStack_78,0x78);
  TPanel::get_string(param_1,param_5,acStack_f0,0x78);
  (**(code **)(param_1->_padding_ + 0xec))
            (param_2,param_3,acStack_78,acStack_f0,param_6,param_7,param_8,param_9,param_10,param_11
             ,param_12);
  return;
}

// --------------------------------------------------

// Function: FUN_0046852e
// Address: 0046852e
undefined4 __thiscall
FUN_0046852e(int param_1,TPanel *param_2,int *param_3,char *param_4,char *param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10,int param_11,long param_12)
{
  int iVar1;
  int iVar2;
  int iVar3;
  TButtonPanel *this;
  int iVar4;
  TDigital *pTVar5;
  long lVar6;
  RGE_Font *pRVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055df8b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar9 = *(int *)(param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 0xf4);
  iVar2 = *(int *)(param_1 + 0x18);
  iVar3 = *(int *)(param_1 + 0xf8);
  this = (TButtonPanel *)operator_new(0x2b8);
  uStack_4 = 0;
  if (this == (TButtonPanel *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = TButtonPanel::TButtonPanel(this);
  }
  uStack_4 = 0xffffffff;
  *param_3 = iVar4;
  if ((iVar4 != 0) && (*(int *)(iVar4 + 0xd8) == 0)) {
    if (param_11 < 0) {
      pTVar5 = (TDigital *)0x0;
    }
    else {
      pTVar5 = RGE_Base_Game::get_sound(rge_base_game,param_11);
    }
    lVar6 = TButtonPanel::setup((TButtonPanel *)*param_3,*(TDrawArea **)(param_1 + 0x20),param_2,
                                (param_6 * iVar9) / iVar1,(param_7 * iVar2) / iVar3,
                                (param_8 * iVar9) / iVar1,(param_9 * iVar2) / iVar3,DrawTextA,pTVar5
                                ,NotifyAction,param_12);
    if (lVar6 != 0) {
      TButtonPanel::set_sound_number((TButtonPanel *)*param_3,param_11);
      if (param_10 < 0) {
        param_10 = 10;
      }
      pRVar7 = RGE_Base_Game::get_font(rge_base_game,param_10);
      TButtonPanel::set_text_info
                ((TButtonPanel *)*param_3,param_4,pRVar7->font,pRVar7->font_wid,pRVar7->font_hgt,-1,
                 -1);
      if (param_5 != (char *)0x0) {
        TButtonPanel::set_text((TButtonPanel *)*param_3,1,param_5);
      }
      if (*(int *)(param_1 + 0x31c) != 0) {
        TButtonPanel::set_bevel_info
                  ((TButtonPanel *)*param_3,4,(uint)*(byte *)(param_1 + 800),
                   (uint)*(byte *)(param_1 + 0x321),(uint)*(byte *)(param_1 + 0x322),
                   (uint)*(byte *)(param_1 + 0x323),(uint)*(byte *)(param_1 + 0x324),
                   (uint)*(byte *)(param_1 + 0x325));
      }
      iVar9 = 0;
      do {
        TButtonPanel::set_text_color
                  ((TButtonPanel *)*param_3,iVar9,*(ulong *)(param_1 + 0x328),
                   *(ulong *)(param_1 + 0x32c));
        TButtonPanel::set_highlight_text_color
                  ((TButtonPanel *)*param_3,iVar9,*(ulong *)(param_1 + 0x330),
                   *(ulong *)(param_1 + 0x334));
        iVar9 = iVar9 + 1;
      } while (iVar9 < 9);
      TButtonPanel::set_text_color
                ((TButtonPanel *)*param_3,1,*(ulong *)(param_1 + 0x338),*(ulong *)(param_1 + 0x33c))
      ;
      TButtonPanel::set_highlight_text_color
                ((TButtonPanel *)*param_3,1,*(ulong *)(param_1 + 0x330),*(ulong *)(param_1 + 0x334))
      ;
      uVar8 = 1;
      goto LAB_0046873f;
    }
  }
  *(undefined4 *)(param_1 + 0xd8) = 1;
  uVar8 = 0;
LAB_0046873f:
  *unaff_FS_OFFSET = uStack_c;
  return uVar8;
}

// --------------------------------------------------

// Function: FUN_00468754
// Address: 00468754
// [HELPER] s_X: "X"
// [HELPER] s__: "}"
undefined4 __thiscall
FUN_00468754(int param_1,TPanel *param_2,int *param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,long param_9)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  TButtonPanel *this;
  int iVar5;
  TDigital *pTVar6;
  long lVar7;
  RGE_Font *pRVar8;
  undefined4 uVar9;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dfab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0xf4);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0xf8);
  this = (TButtonPanel *)operator_new(0x2b8);
  uStack_4 = 0;
  if (this == (TButtonPanel *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = TButtonPanel::TButtonPanel(this);
  }
  uStack_4 = 0xffffffff;
  *param_3 = iVar5;
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xd8) == 0)) {
    if (param_8 < 0) {
      pTVar6 = (TDigital *)0x0;
    }
    else {
      pTVar6 = RGE_Base_Game::get_sound(rge_base_game,param_8);
    }
    lVar7 = TButtonPanel::setup((TButtonPanel *)*param_3,*(TDrawArea **)(param_1 + 0x20),param_2,
                                (param_4 * iVar1) / iVar2,(param_5 * iVar3) / iVar4,
                                (param_6 * iVar1) / iVar2,(param_7 * iVar3) / iVar4,DrawBevelPicture
                                ,pTVar6,NotifyAction,param_9);
    if (lVar7 != 0) {
      TButtonPanel::set_sound_number((TButtonPanel *)*param_3,param_8);
      TButtonPanel::set_state_info((TButtonPanel *)*param_3,2);
      if (*(int *)(param_1 + 0x448) == 0) {
        pRVar8 = RGE_Base_Game::get_font(rge_base_game,0);
        TButtonPanel::set_text_info
                  ((TButtonPanel *)*param_3,&s__,pRVar8->font,pRVar8->font_wid,pRVar8->font_hgt,-1,
                   -1);
        TButtonPanel::set_text((TButtonPanel *)*param_3,1,s_X);
        TButtonPanel::setDrawType((TButtonPanel *)*param_3,DrawTextA);
      }
      else {
        TButtonPanel::setDrawType((TButtonPanel *)*param_3,DrawBevelPicture);
        TButtonPanel::set_picture((TButtonPanel *)*param_3,0,*(TShape **)(param_1 + 0x448),0);
        TButtonPanel::set_picture((TButtonPanel *)*param_3,1,*(TShape **)(param_1 + 0x448),2);
      }
      if (*(int *)(param_1 + 0x31c) != 0) {
        TButtonPanel::set_bevel_info
                  ((TButtonPanel *)*param_3,4,(uint)*(byte *)(param_1 + 800),
                   (uint)*(byte *)(param_1 + 0x321),(uint)*(byte *)(param_1 + 0x322),
                   (uint)*(byte *)(param_1 + 0x323),(uint)*(byte *)(param_1 + 0x324),
                   (uint)*(byte *)(param_1 + 0x325));
      }
      TButtonPanel::set_text_color
                ((TButtonPanel *)*param_3,0,*(ulong *)(param_1 + 0x328),*(ulong *)(param_1 + 0x32c))
      ;
      TButtonPanel::set_highlight_text_color
                ((TButtonPanel *)*param_3,0,*(ulong *)(param_1 + 0x330),*(ulong *)(param_1 + 0x334))
      ;
      TButtonPanel::set_text_color
                ((TButtonPanel *)*param_3,1,*(ulong *)(param_1 + 0x338),*(ulong *)(param_1 + 0x33c))
      ;
      TButtonPanel::set_highlight_text_color
                ((TButtonPanel *)*param_3,1,*(ulong *)(param_1 + 0x330),*(ulong *)(param_1 + 0x334))
      ;
      uVar9 = 1;
      goto LAB_004689a7;
    }
  }
  *(undefined4 *)(param_1 + 0xd8) = 1;
  uVar9 = 0;
LAB_004689a7:
  *unaff_FS_OFFSET = uStack_c;
  return uVar9;
}

// --------------------------------------------------

// Function: FUN_004689bc
// Address: 004689bc
// [HELPER] s_X: "X"
// [HELPER] s__: "}"
undefined4 __thiscall
FUN_004689bc(int param_1,TPanel *param_2,int *param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,long param_9)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  TButtonPanel *this;
  int iVar5;
  TDigital *pTVar6;
  long lVar7;
  RGE_Font *pRVar8;
  undefined4 uVar9;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dfcb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0xf4);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0xf8);
  this = (TButtonPanel *)operator_new(0x2b8);
  uStack_4 = 0;
  if (this == (TButtonPanel *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = TButtonPanel::TButtonPanel(this);
  }
  uStack_4 = 0xffffffff;
  *param_3 = iVar5;
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xd8) == 0)) {
    if (param_8 < 0) {
      pTVar6 = (TDigital *)0x0;
    }
    else {
      pTVar6 = RGE_Base_Game::get_sound(rge_base_game,param_8);
    }
    lVar7 = TButtonPanel::setup((TButtonPanel *)*param_3,*(TDrawArea **)(param_1 + 0x20),param_2,
                                (param_4 * iVar1) / iVar2,(param_5 * iVar3) / iVar4,
                                (param_6 * iVar1) / iVar2,(param_7 * iVar3) / iVar4,DrawPicture,
                                pTVar6,NotifyAction,param_9);
    if (lVar7 != 0) {
      TButtonPanel::set_sound_number((TButtonPanel *)*param_3,param_8);
      if (*(int *)(param_1 + 0x448) == 0) {
        TButtonPanel::setDrawType((TButtonPanel *)*param_3,DrawTextA);
        pRVar8 = RGE_Base_Game::get_font(rge_base_game,0);
        TButtonPanel::set_text_info
                  ((TButtonPanel *)*param_3,&s__,pRVar8->font,pRVar8->font_wid,pRVar8->font_hgt,-1,
                   -1);
        TButtonPanel::set_text((TButtonPanel *)*param_3,1,s_X);
      }
      else {
        TButtonPanel::setDrawType((TButtonPanel *)*param_3,DrawBevelPicture);
        TButtonPanel::set_picture((TButtonPanel *)*param_3,0,*(TShape **)(param_1 + 0x448),4);
        TButtonPanel::set_picture((TButtonPanel *)*param_3,1,*(TShape **)(param_1 + 0x448),6);
      }
      if (*(int *)(param_1 + 0x31c) != 0) {
        TButtonPanel::set_bevel_info
                  ((TButtonPanel *)*param_3,4,(uint)*(byte *)(param_1 + 800),
                   (uint)*(byte *)(param_1 + 0x321),(uint)*(byte *)(param_1 + 0x322),
                   (uint)*(byte *)(param_1 + 0x323),(uint)*(byte *)(param_1 + 0x324),
                   (uint)*(byte *)(param_1 + 0x325));
      }
      TButtonPanel::set_text_color
                ((TButtonPanel *)*param_3,0,*(ulong *)(param_1 + 0x328),*(ulong *)(param_1 + 0x32c))
      ;
      TButtonPanel::set_highlight_text_color
                ((TButtonPanel *)*param_3,0,*(ulong *)(param_1 + 0x330),*(ulong *)(param_1 + 0x334))
      ;
      TButtonPanel::set_text_color
                ((TButtonPanel *)*param_3,1,*(ulong *)(param_1 + 0x338),*(ulong *)(param_1 + 0x33c))
      ;
      TButtonPanel::set_highlight_text_color
                ((TButtonPanel *)*param_3,1,*(ulong *)(param_1 + 0x330),*(ulong *)(param_1 + 0x334))
      ;
      uVar9 = 1;
      goto LAB_00468bfe;
    }
  }
  *(undefined4 *)(param_1 + 0xd8) = 1;
  uVar9 = 0;
LAB_00468bfe:
  *unaff_FS_OFFSET = uStack_c;
  return uVar9;
}

// --------------------------------------------------

// Function: FUN_00468c13
// Address: 00468c13
void __thiscall
FUN_00468c13(TPanel *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12)
{
  char acStack_100 [256];
  
  TPanel::get_string(param_1,param_4,acStack_100,0x100);
  (**(code **)(param_1->_padding_ + 0x100))
            (param_2,param_3,acStack_100,param_5,param_6,param_7,param_8,param_9,param_10,param_11,
             param_12);
  return;
}

// --------------------------------------------------

// Function: FUN_00468cab
// Address: 00468cab
undefined4 __thiscall
FUN_00468cab(int param_1,TPanel *param_2,int *param_3,undefined4 param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10,int param_11,int param_12)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  TTextPanel *this;
  int iVar5;
  RGE_Font *pRVar6;
  long lVar7;
  undefined4 uVar8;
  undefined4 *unaff_FS_OFFSET;
  Alignment AVar9;
  Alignment AVar10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dfeb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0xf4);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0xf8);
  this = (TTextPanel *)operator_new(0x188);
  uStack_4 = 0;
  if (this == (TTextPanel *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = TTextPanel::TTextPanel(this);
  }
  uStack_4 = 0xffffffff;
  *param_3 = iVar5;
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xd8) == 0)) {
    if (param_9 < 0) {
      param_9 = 10;
    }
    pRVar6 = RGE_Base_Game::get_font(rge_base_game,param_9);
    lVar7 = TTextPanel::setup((TTextPanel *)*param_3,*(TDrawArea **)(param_1 + 0x20),param_2,
                              (param_5 * iVar1) / iVar2,(param_6 * iVar3) / iVar4,
                              (param_7 * iVar1) / iVar2,(param_8 * iVar3) / iVar4,pRVar6->font,
                              pRVar6->font_wid,pRVar6->font_hgt,(char *)0x0,0,'\0',0,'\0',0,
                              (char *)0x0);
    if (lVar7 != 0) {
      if ((param_10 == 0) || (param_11 == 0)) {
        if (param_10 == 0) {
          AVar10 = AlignLeft;
          if (param_11 != 0) {
            AVar9 = AlignCenter;
            goto LAB_00468dd9;
          }
        }
        else {
          AVar10 = AlignCenter;
        }
        AVar9 = AlignTop;
      }
      else {
        AVar10 = AlignCenter;
        AVar9 = AlignCenter;
      }
LAB_00468dd9:
      TTextPanel::set_alignment((TTextPanel *)*param_3,AVar9,AVar10);
      TTextPanel::set_word_wrap((TTextPanel *)*param_3,param_12);
      (**(code **)(*(int *)*param_3 + 0xe8))(param_4);
      TTextPanel::set_text_color
                ((TTextPanel *)*param_3,*(ulong *)(param_1 + 0x328),*(ulong *)(param_1 + 0x32c));
      TTextPanel::set_highlight_text_color
                ((TTextPanel *)*param_3,*(ulong *)(param_1 + 0x330),*(ulong *)(param_1 + 0x334));
      uVar8 = 1;
      goto LAB_00468e38;
    }
  }
  *(undefined4 *)(param_1 + 0xd8) = 1;
  uVar8 = 0;
LAB_00468e38:
  *unaff_FS_OFFSET = uStack_c;
  return uVar8;
}

// --------------------------------------------------

// Function: FUN_00468e4d
// Address: 00468e4d
undefined4 __thiscall
FUN_00468e4d(int param_1,TPanel *param_2,int *param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7,int param_8,int param_9,int param_10,int param_11,int param_12)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  TTextPanel *this;
  int iVar5;
  RGE_Font *pRVar6;
  long lVar7;
  undefined4 uVar8;
  undefined4 *unaff_FS_OFFSET;
  Alignment AVar9;
  Alignment AVar10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e00b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0xf4);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0xf8);
  this = (TTextPanel *)operator_new(0x188);
  uStack_4 = 0;
  if (this == (TTextPanel *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = TTextPanel::TTextPanel(this);
  }
  uStack_4 = 0xffffffff;
  *param_3 = iVar5;
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xd8) == 0)) {
    if (param_10 < 0) {
      param_10 = 10;
    }
    pRVar6 = RGE_Base_Game::get_font(rge_base_game,param_10);
    lVar7 = TTextPanel::setup((TTextPanel *)*param_3,*(TDrawArea **)(param_1 + 0x20),param_2,
                              (param_6 * iVar1) / iVar2,(param_7 * iVar3) / iVar4,
                              (param_8 * iVar1) / iVar2,(param_9 * iVar3) / iVar4,pRVar6->font,
                              pRVar6->font_wid,pRVar6->font_hgt,(char *)0x0,0,'\0',0,'\0',0,
                              (char *)0x0);
    if (lVar7 != 0) {
      (**(code **)(*(int *)*param_3 + 0xe0))(param_4,param_5);
      TTextPanel::scroll((TTextPanel *)*param_3,'\x06',0,1);
      if ((param_11 == 0) || (param_12 == 0)) {
        if (param_11 == 0) {
          AVar10 = AlignLeft;
          if (param_12 != 0) {
            AVar9 = AlignCenter;
            goto LAB_00468f9e;
          }
        }
        else {
          AVar10 = AlignCenter;
        }
        AVar9 = AlignTop;
      }
      else {
        AVar10 = AlignCenter;
        AVar9 = AlignCenter;
      }
LAB_00468f9e:
      TTextPanel::set_alignment((TTextPanel *)*param_3,AVar9,AVar10);
      TTextPanel::set_text_color
                ((TTextPanel *)*param_3,*(ulong *)(param_1 + 0x328),*(ulong *)(param_1 + 0x32c));
      TTextPanel::set_highlight_text_color
                ((TTextPanel *)*param_3,*(ulong *)(param_1 + 0x330),*(ulong *)(param_1 + 0x334));
      uVar8 = 1;
      goto LAB_00468fe2;
    }
  }
  *(undefined4 *)(param_1 + 0xd8) = 1;
  uVar8 = 0;
LAB_00468fe2:
  *unaff_FS_OFFSET = uStack_c;
  return uVar8;
}

// --------------------------------------------------

// Function: FUN_00468ff7
// Address: 00468ff7
undefined4 __thiscall
FUN_00468ff7(int param_1,TPanel *param_2,int *param_3,char *param_4,short param_5,FormatType param_6
            ,int param_7,int param_8,int param_9,int param_10,int param_11)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  TInputPanel *this;
  int iVar5;
  RGE_Font *pRVar6;
  long lVar7;
  undefined4 uVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e02b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0xf4);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0xf8);
  this = (TInputPanel *)operator_new(0x1b8);
  uStack_4 = 0;
  if (this == (TInputPanel *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = TInputPanel::TInputPanel(this);
  }
  uStack_4 = 0xffffffff;
  *param_3 = iVar5;
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xd8) == 0)) {
    if (param_11 < 0) {
      param_11 = 10;
    }
    pRVar6 = RGE_Base_Game::get_font(rge_base_game,param_11);
    lVar7 = TInputPanel::setup((TInputPanel *)*param_3,*(TDrawArea **)(param_1 + 0x20),param_2,
                               (param_7 * iVar1) / iVar2,(param_8 * iVar3) / iVar4,
                               (param_9 * iVar1) / iVar2,(param_10 * iVar3) / iVar4,pRVar6->font,
                               pRVar6->font_wid,pRVar6->font_hgt,(char *)0x0,0,'\0',1,0xff,0xff,
                               param_5,(TDigital *)0x0,param_4,param_6);
    if (lVar7 != 0) {
      if (*(int *)(param_1 + 0x31c) != 0) {
        (**(code **)(*(int *)*param_3 + 0xec))
                  (3,*(undefined1 *)(param_1 + 800),*(undefined1 *)(param_1 + 0x321),
                   *(undefined1 *)(param_1 + 0x322),*(undefined1 *)(param_1 + 0x323),
                   *(undefined1 *)(param_1 + 0x324),*(undefined1 *)(param_1 + 0x325));
      }
      TTextPanel::set_text_color
                ((TTextPanel *)*param_3,*(ulong *)(param_1 + 0x328),*(ulong *)(param_1 + 0x32c));
      TTextPanel::set_highlight_text_color
                ((TTextPanel *)*param_3,*(ulong *)(param_1 + 0x330),*(ulong *)(param_1 + 0x334));
      uVar8 = 1;
      goto LAB_0046919d;
    }
  }
  *(undefined4 *)(param_1 + 0xd8) = 1;
  uVar8 = 0;
LAB_0046919d:
  *unaff_FS_OFFSET = uStack_c;
  return uVar8;
}

// --------------------------------------------------

// Function: FUN_004691b2
// Address: 004691b2
undefined4 __thiscall
FUN_004691b2(int param_1,TPanel *param_2,int *param_3,char *param_4,short param_5,FormatType param_6
            ,int param_7,int param_8,int param_9,long param_10,int param_11,int param_12,
            int param_13)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  TEditPanel *this;
  int iVar5;
  RGE_Font *pRVar6;
  long lVar7;
  undefined4 uVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e04b;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0xf4);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0xf8);
  this = (TEditPanel *)operator_new(0x16c);
  uStack_4 = 0;
  if (this == (TEditPanel *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = TEditPanel::TEditPanel(this);
  }
  uStack_4 = 0xffffffff;
  *param_3 = iVar5;
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xd8) == 0)) {
    if (param_11 < 0) {
      param_11 = 10;
    }
    pRVar6 = RGE_Base_Game::get_font(rge_base_game,param_11);
    lVar7 = TEditPanel::setup((TEditPanel *)*param_3,*(TDrawArea **)(param_1 + 0x20),param_2,
                              (param_7 * iVar1) / iVar2,(iVar3 * param_8) / iVar4,
                              (param_9 * iVar1) / iVar2,param_10,pRVar6->font,param_5,param_4,
                              param_6,(uint)(param_6 != FormatMultiLine));
    if (lVar7 != 0) {
      if (*(int *)(param_1 + 0x31c) != 0) {
        TEditPanel::set_bevel_info
                  ((TEditPanel *)*param_3,3,(uint)*(byte *)(param_1 + 800),
                   (uint)*(byte *)(param_1 + 0x321),(uint)*(byte *)(param_1 + 0x322),
                   (uint)*(byte *)(param_1 + 0x323),(uint)*(byte *)(param_1 + 0x324),
                   (uint)*(byte *)(param_1 + 0x325));
      }
      TEditPanel::set_text_color
                ((TEditPanel *)*param_3,*(ulong *)(param_1 + 0x328),*(ulong *)(param_1 + 0x32c));
      TEditPanel::set_highlight_text_color
                ((TEditPanel *)*param_3,*(ulong *)(param_1 + 0x330),*(ulong *)(param_1 + 0x334));
      TEditPanel::set_back_color
                ((TEditPanel *)*param_3,*(void **)(param_1 + 0x464),*(ulong *)(param_1 + 0x468),
                 *(uchar *)(param_1 + 0x454));
      TEditPanel::set_ime_info((TEditPanel *)*param_3,param_12,param_13);
      uVar8 = 1;
      goto LAB_00469365;
    }
  }
  *(undefined4 *)(param_1 + 0xd8) = 1;
  uVar8 = 0;
LAB_00469365:
  *unaff_FS_OFFSET = uStack_c;
  return uVar8;
}

// --------------------------------------------------

// Function: FUN_0046937a
// Address: 0046937a
// [HELPER] s__: "}"
char * __thiscall
FUN_0046937a(int param_1,TPanel *param_2,int *param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10)
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  TTextPanel *this;
  int iVar5;
  int iVar6;
  char **ppcVar7;
  char *pcVar8;
  TDropDownPanel *this_00;
  int iVar9;
  RGE_Font *pRVar10;
  long lVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  char **ppcVar15;
  char *pcVar16;
  int iVar17;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e06b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar17 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0xf4);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0xf8);
  iVar5 = (param_9 * iVar3) / iVar4;
  iVar6 = (iVar17 * 0x12) / iVar2;
  iVar9 = param_10;
  if (param_10 < 0) {
    iVar9 = 10;
  }
  RGE_Base_Game::get_font(rge_base_game,iVar9);
  ppcVar7 = (char **)calloc(1,4);
  if (ppcVar7 == (char **)0x0) {
    *(undefined4 *)(param_1 + 0xd8) = 1;
    pcVar8 = (char *)0x0;
    goto LAB_00469696;
  }
  pcVar8 = (char *)calloc(0x14,1);
  *ppcVar7 = pcVar8;
  if (pcVar8 == (char *)0x0) goto LAB_00469696;
  uVar12 = 0xffffffff;
  pcVar14 = &s__;
  do {
    pcVar16 = pcVar14;
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    pcVar16 = pcVar14 + 1;
    cVar1 = *pcVar14;
    pcVar14 = pcVar16;
  } while (cVar1 != '\0');
  uVar12 = ~uVar12;
  pcVar14 = pcVar16 + -uVar12;
  for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar14;
    pcVar14 = pcVar14 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *pcVar8 = *pcVar14;
    pcVar14 = pcVar14 + 1;
    pcVar8 = pcVar8 + 1;
  }
  if (*(int *)(param_1 + 0xd8) == 0) {
    this_00 = (TDropDownPanel *)operator_new(0x144);
    uStack_4 = 0;
    if (this_00 == (TDropDownPanel *)0x0) {
      iVar9 = 0;
    }
    else {
      iVar9 = TDropDownPanel::TDropDownPanel(this_00);
    }
    uStack_4 = 0xffffffff;
    *param_3 = iVar9;
    if ((iVar9 != 0) && (*(int *)(iVar9 + 0xd8) == 0)) {
      pRVar10 = RGE_Base_Game::get_font(rge_base_game,param_10);
      lVar11 = TDropDownPanel::setup
                         ((TDropDownPanel *)*param_3,*(TDrawArea **)(param_1 + 0x20),param_2,
                          pRVar10->font,pRVar10->font_wid,pRVar10->font_hgt,0,'\0',1,0xff,
                          (param_6 * iVar17) / iVar2,(param_7 * iVar3) / iVar4,
                          (param_8 * iVar17) / iVar2,iVar5,0,0,iVar6,iVar5,(char *)0x0,
                          (param_4 * iVar17) / iVar2,(param_5 * iVar3) / iVar4,ppcVar7,1,iVar6,
                          (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0,iVar6,iVar6);
      if (lVar11 != 0) {
        if (*(TShape **)(param_1 + 0x448) != (TShape *)0x0) {
          TDropDownPanel::set_buttons
                    ((TDropDownPanel *)*param_3,*(TShape **)(param_1 + 0x448),0xe,-1,8,10,0xc);
        }
        if (*(int *)(param_1 + 0x31c) != 0) {
          TDropDownPanel::set_bevel_info
                    ((TDropDownPanel *)*param_3,3,(uint)*(byte *)(param_1 + 800),
                     (uint)*(byte *)(param_1 + 0x321),(uint)*(byte *)(param_1 + 0x322),
                     (uint)*(byte *)(param_1 + 0x323),(uint)*(byte *)(param_1 + 0x324),
                     (uint)*(byte *)(param_1 + 0x325));
        }
        TDropDownPanel::set_val_text_color
                  ((TDropDownPanel *)*param_3,*(ulong *)(param_1 + 0x328),
                   *(ulong *)(param_1 + 0x32c));
        this = *(TTextPanel **)(*param_3 + 0xfc);
        TTextPanel::set_text_color(this,*(ulong *)(param_1 + 0x328),*(ulong *)(param_1 + 0x32c));
        TTextPanel::set_highlight_text_color
                  (this,*(ulong *)(param_1 + 0x330),*(ulong *)(param_1 + 0x334));
        (**(code **)(**(int **)(*param_3 + 0xf4) + 0xec))
                  (3,*(undefined1 *)(param_1 + 800),*(undefined1 *)(param_1 + 0x321),
                   *(undefined1 *)(param_1 + 0x322),*(undefined1 *)(param_1 + 0x323),
                   *(undefined1 *)(param_1 + 0x324),*(undefined1 *)(param_1 + 0x325));
        goto LAB_0046965a;
      }
    }
    *(undefined4 *)(param_1 + 0xd8) = 1;
  }
LAB_0046965a:
  iVar17 = 1;
  ppcVar15 = ppcVar7;
  do {
    if (*ppcVar15 != (char *)0x0) {
      free(*ppcVar15);
      *ppcVar15 = (char *)0x0;
    }
    ppcVar15 = ppcVar15 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  free(ppcVar7);
  pcVar8 = (char *)(uint)(*(int *)(param_1 + 0xd8) == 0);
LAB_00469696:
  *unaff_FS_OFFSET = uStack_c;
  return pcVar8;
}

// --------------------------------------------------

// Function: FUN_004696ab
// Address: 004696ab
// [HELPER] s__: "}"
char * __thiscall
FUN_004696ab(int param_1,TPanel *param_2,int *param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8)
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char **ppcVar5;
  char *pcVar6;
  TListPanel *this;
  int iVar7;
  RGE_Font *pRVar8;
  long lVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  char **ppcVar14;
  char *pcVar15;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e08b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar12 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0xf4);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0xf8);
  iVar7 = param_8;
  if (param_8 < 0) {
    iVar7 = 10;
  }
  RGE_Base_Game::get_font(rge_base_game,iVar7);
  ppcVar5 = (char **)calloc(1,4);
  if (ppcVar5 == (char **)0x0) {
    *(undefined4 *)(param_1 + 0xd8) = 1;
    pcVar6 = (char *)0x0;
    goto LAB_004698fb;
  }
  pcVar6 = (char *)calloc(0x14,1);
  *ppcVar5 = pcVar6;
  if (pcVar6 == (char *)0x0) goto LAB_004698fb;
  uVar10 = 0xffffffff;
  pcVar13 = &s__;
  do {
    pcVar15 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar15 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar15;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  pcVar13 = pcVar15 + -uVar10;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar6 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar6 = pcVar6 + 1;
  }
  if (*(int *)(param_1 + 0xd8) == 0) {
    this = (TListPanel *)operator_new(0x1a0);
    uStack_4 = 0;
    if (this == (TListPanel *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TListPanel::TListPanel(this);
    }
    uStack_4 = 0xffffffff;
    *param_3 = iVar7;
    if ((iVar7 != 0) && (*(int *)(iVar7 + 0xd8) == 0)) {
      pRVar8 = RGE_Base_Game::get_font(rge_base_game,param_8);
      lVar9 = TTextPanel::setup((TTextPanel *)*param_3,*(TDrawArea **)(param_1 + 0x20),param_2,
                                (param_4 * iVar12) / iVar2,(param_5 * iVar3) / iVar4,
                                (param_6 * iVar12) / iVar2,(param_7 * iVar3) / iVar4,pRVar8->font,
                                pRVar8->font_wid,pRVar8->font_hgt,(char *)0x0,0,'\0',1,0xff,0,
                                ppcVar5,1);
      if (lVar9 != 0) {
        TListPanel::scroll_cur_line((TListPanel *)*param_3,'\x01',0,1);
        goto LAB_0046984f;
      }
    }
    *(undefined4 *)(param_1 + 0xd8) = 1;
  }
LAB_0046984f:
  iVar12 = 1;
  ppcVar14 = ppcVar5;
  do {
    if (*ppcVar14 != (char *)0x0) {
      free(*ppcVar14);
      *ppcVar14 = (char *)0x0;
    }
    ppcVar14 = ppcVar14 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  free(ppcVar5);
  if (*(int *)(param_1 + 0x31c) != 0) {
    (**(code **)(*(int *)*param_3 + 0xec))
              (3,*(undefined1 *)(param_1 + 800),*(undefined1 *)(param_1 + 0x321),
               *(undefined1 *)(param_1 + 0x322),*(undefined1 *)(param_1 + 0x323),
               *(undefined1 *)(param_1 + 0x324),*(undefined1 *)(param_1 + 0x325));
  }
  TTextPanel::set_text_color
            ((TTextPanel *)*param_3,*(ulong *)(param_1 + 0x328),*(ulong *)(param_1 + 0x32c));
  TTextPanel::set_highlight_text_color
            ((TTextPanel *)*param_3,*(ulong *)(param_1 + 0x330),*(ulong *)(param_1 + 0x334));
  pcVar6 = (char *)0x1;
LAB_004698fb:
  *unaff_FS_OFFSET = uStack_c;
  return pcVar6;
}

// --------------------------------------------------

// Function: FUN_00469ac4
// Address: 00469ac4
undefined4 __thiscall
FUN_00469ac4(int param_1,TPanel *param_2,undefined4 *param_3,long param_4,long param_5,long param_6,
            int param_7,int param_8,int param_9,int param_10)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  TVerticalSliderPanel *pTVar5;
  long lVar6;
  undefined4 uVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e0cb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0xf4);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0xf8);
  pTVar5 = (TVerticalSliderPanel *)operator_new(0x1cc);
  uStack_4 = 0;
  if (pTVar5 == (TVerticalSliderPanel *)0x0) {
    pTVar5 = (TVerticalSliderPanel *)0x0;
  }
  else {
    pTVar5 = (TVerticalSliderPanel *)TVerticalSliderPanel::TVerticalSliderPanel(pTVar5);
  }
  uStack_4 = 0xffffffff;
  *param_3 = pTVar5;
  if ((pTVar5 != (TVerticalSliderPanel *)0x0) && (pTVar5->_padding_ == 0)) {
    lVar6 = TVerticalSliderPanel::setup
                      (pTVar5,*(TDrawArea **)(param_1 + 0x20),param_2,(param_7 * iVar1) / iVar2,
                       (param_8 * iVar3) / iVar4,(param_9 * iVar1) / iVar2,
                       (param_10 * iVar3) / iVar4,(char *)0x0,(char *)0x0,0,param_4,param_5,param_6,
                       1,0);
    if (lVar6 != 0) {
      if (*(TShape **)(param_1 + 0x448) != (TShape *)0x0) {
        TScrollBarPanel::set_buttons
                  ((TScrollBarPanel *)*param_3,*(TShape **)(param_1 + 0x448),-1,8,10,0xc);
      }
      if (*(int *)(param_1 + 0x31c) != 0) {
        TScrollBarPanel::set_bevel_info
                  ((TScrollBarPanel *)*param_3,3,(uint)*(byte *)(param_1 + 800),
                   (uint)*(byte *)(param_1 + 0x321),(uint)*(byte *)(param_1 + 0x322),
                   (uint)*(byte *)(param_1 + 0x323),(uint)*(byte *)(param_1 + 0x324),
                   (uint)*(byte *)(param_1 + 0x325));
      }
      uVar7 = 1;
      goto LAB_00469c26;
    }
  }
  uVar7 = 0;
LAB_00469c26:
  *unaff_FS_OFFSET = uStack_c;
  return uVar7;
}

// --------------------------------------------------

// Function: FUN_00469c3b
// Address: 00469c3b
undefined4 __thiscall
FUN_00469c3b(int param_1,TPanel *param_2,undefined4 *param_3,long param_4,long param_5,long param_6,
            int param_7,int param_8,int param_9,int param_10)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  THorizontalSliderPanel *pTVar5;
  long lVar6;
  undefined4 uVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e0eb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0xf4);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0xf8);
  pTVar5 = (THorizontalSliderPanel *)operator_new(0x1cc);
  uStack_4 = 0;
  if (pTVar5 == (THorizontalSliderPanel *)0x0) {
    pTVar5 = (THorizontalSliderPanel *)0x0;
  }
  else {
    pTVar5 = (THorizontalSliderPanel *)THorizontalSliderPanel::THorizontalSliderPanel(pTVar5);
  }
  uStack_4 = 0xffffffff;
  *param_3 = pTVar5;
  if ((pTVar5 != (THorizontalSliderPanel *)0x0) && (*(int *)&pTVar5->field_0xd8 == 0)) {
    lVar6 = THorizontalSliderPanel::setup
                      (pTVar5,*(TDrawArea **)(param_1 + 0x20),param_2,(param_7 * iVar1) / iVar2,
                       (param_8 * iVar3) / iVar4,(param_9 * iVar1) / iVar2,
                       (param_10 * iVar3) / iVar4,(char *)0x0,(char *)0x0,0,param_4,param_5,param_6,
                       1,0);
    if (lVar6 != 0) {
      if (*(TShape **)(param_1 + 0x448) != (TShape *)0x0) {
        TScrollBarPanel::set_buttons
                  ((TScrollBarPanel *)*param_3,*(TShape **)(param_1 + 0x448),-1,8,10,0xc);
      }
      if (*(int *)(param_1 + 0x31c) != 0) {
        TScrollBarPanel::set_bevel_info
                  ((TScrollBarPanel *)*param_3,3,(uint)*(byte *)(param_1 + 800),
                   (uint)*(byte *)(param_1 + 0x321),(uint)*(byte *)(param_1 + 0x322),
                   (uint)*(byte *)(param_1 + 0x323),(uint)*(byte *)(param_1 + 0x324),
                   (uint)*(byte *)(param_1 + 0x325));
      }
      uVar7 = 1;
      goto LAB_00469d96;
    }
  }
  uVar7 = 0;
LAB_00469d96:
  *unaff_FS_OFFSET = uStack_c;
  return uVar7;
}

// --------------------------------------------------

// Function: FUN_00469dab
// Address: 00469dab
void __thiscall
FUN_00469dab(int param_1,int *param_2,int param_3,int param_4,int param_5,int param_6)
{
  (**(code **)(*param_2 + 0x1c))
            ((param_3 * *(int *)(param_1 + 0x14)) / *(int *)(param_1 + 0xf4),
             (param_4 * *(int *)(param_1 + 0x18)) / *(int *)(param_1 + 0xf8),
             (param_5 * *(int *)(param_1 + 0x14)) / *(int *)(param_1 + 0xf4),
             (param_6 * *(int *)(param_1 + 0x18)) / *(int *)(param_1 + 0xf8));
  return;
}

// --------------------------------------------------

// Function: FUN_00469e06
// Address: 00469e06
void __thiscall FUN_00469e06(TPanel *param_1,int param_2)
{
  TDrawArea *this;
  void *pvVar1;
  
  TPanel::set_focus(param_1,param_2);
  if (param_1->have_focus != 0) {
    if ((((char)param_1[2].clip_rect.top != '\0') || (-1 < (int)param_1[3].need_redraw)) &&
       (rge_base_game->mouse_pointer != (TMousePointer *)0x0)) {
      TMousePointer::LoadCursors
                (rge_base_game->mouse_pointer,(char *)&param_1[2].clip_rect.top,
                 param_1[3].need_redraw,0);
    }
    this = param_1->render_area;
    if ((((this != (TDrawArea *)0x0) && (this->DrawSystem != (TDrawSystem *)0x0)) &&
        ((pvVar1 = (void *)param_1[2].clip_rect.left, pvVar1 != (void *)0x0 ||
         (pvVar1 = rge_base_game->prog_palette, pvVar1 != (void *)0x0)))) &&
       (this->DrawSystem->Pal != pvVar1)) {
      TDrawArea::Clear(this,(tagRECT *)0x0,0);
      TDrawSystem::Paint(param_1->render_area->DrawSystem,(tagRECT *)0x0);
      TDrawSystem::SetPalette(param_1->render_area->DrawSystem,pvVar1);
      (**(code **)(param_1->_padding_ + 0x20))(2);
    }
  }
  if (param_1[4].clip_rgn != (void *)0x0) {
    if (param_1->have_focus != 0) {
      TPanelSystem::EnableIME(&panel_system);
      return;
    }
    TPanelSystem::DisableIME(&panel_system);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00469ede
// Address: 00469ede
void __thiscall FUN_00469ede(TEasy_Panel *param_1,int param_2,char *param_3,int param_4,int param_5)
{
  char acStack_100 [256];
  
  TPanel::get_string((TPanel *)param_1,param_2,acStack_100,0x100);
  TEasy_Panel::popupOKDialog(param_1,acStack_100,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0046a037
// Address: 0046a037
void __thiscall FUN_0046a037(TEasy_Panel *param_1,int param_2,char *param_3,int param_4,int param_5)
{
  char acStack_100 [256];
  
  TPanel::get_string((TPanel *)param_1,param_2,acStack_100,0x100);
  TEasy_Panel::popupYesNoDialog(param_1,acStack_100,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0046a2dd
// Address: 0046a2dd
void __thiscall
FUN_0046a2dd(TEasy_Panel *param_1,char *param_2,char *param_3,long param_4,long param_5,long param_6
            )
{
  THelpDialog *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e18b;
  *unaff_FS_OFFSET = &uStack_c;
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    this = (THelpDialog *)operator_new(0x5a4);
    uStack_4 = 0;
    if (this != (THelpDialog *)0x0) {
      THelpDialog::THelpDialog(this,param_1,param_2,param_3,param_4,param_5,param_6);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0046a353
// Address: 0046a353
void __fastcall FUN_0046a353(int param_1)
{
  void *pvVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x45c) = 1;
  pvVar1 = (void *)LoadCursorA(0,0x7f8b);
  RGE_Base_Game::set_mouse_cursor(rge_base_game,pvVar1);
  RGE_Base_Game::set_mouse_facet(rge_base_game,6);
  iVar2 = TMousePointer::get_game_enable(rge_base_game->mouse_pointer);
  *(int *)(param_1 + 0x474) = iVar2;
  TMousePointer::set_game_enable(rge_base_game->mouse_pointer,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0046a3bb
// Address: 0046a3bb
void __fastcall FUN_0046a3bb(int param_1)
{
  void *pvVar1;
  
  *(undefined1 *)(param_1 + 0x45c) = 0;
  pvVar1 = (void *)LoadCursorA(0,0x7f00);
  RGE_Base_Game::set_mouse_cursor(rge_base_game,pvVar1);
  RGE_Base_Game::set_mouse_facet(rge_base_game,0);
  TMousePointer::set_game_enable(rge_base_game->mouse_pointer,*(int *)(param_1 + 0x474));
  return;
}

// --------------------------------------------------

// Function: FUN_0046a40a
// Address: 0046a40a
undefined4 __thiscall FUN_0046a40a(TEasy_Panel *param_1,char param_2,long param_3,long param_4)
{
  char cVar1;
  void *pvVar2;
  long lVar3;
  undefined1 auStack_3f0 [4];
  undefined1 *puStack_3ec;
  undefined1 auStack_3e8 [1000];
  
  puStack_3ec = auStack_3e8;
  if (param_1->help_mode == '\x01') {
    param_1->help_mode = '\0';
    pvVar2 = (void *)LoadCursorA(0,0x7f00);
    RGE_Base_Game::set_mouse_cursor(rge_base_game,pvVar2);
    RGE_Base_Game::set_mouse_facet(rge_base_game,0);
    TMousePointer::set_game_enable(rge_base_game->mouse_pointer,param_1->saved_mouse_mode);
    if (param_2 == '\x01') {
      lVar3 = param_4;
      cVar1 = (**(code **)(param_1->_padding_ + 0xcc))(&puStack_3ec,auStack_3f0,param_3);
      if (cVar1 != '\0') {
        TEasy_Panel::command_help
                  (param_1,(char *)param_1->_padding_,&stack0xfffffc08,lVar3,param_3,param_4);
      }
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046a4dc
// Address: 0046a4dc
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s_YesNoCancelDialog: "YesNoCancelDialog"
// [HELPER] s_YesNoDialog: "YesNoDialog"
long __thiscall
FUN_0046a4dc(TPanel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  long lVar5;
  byte *pbVar6;
  bool bVar7;
  
  if (param_2 != (TPanel *)0x0) {
    pcVar2 = TPanel::panelName(param_2);
    if (pcVar2 != (char *)0x0) {
      pbVar6 = &s_OKDialog;
      pbVar3 = (byte *)TPanel::panelName(param_2);
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_0046a531:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0046a536;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_0046a531;
        pbVar3 = pbVar3 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_0046a536:
      if (iVar4 == 0) {
        if ((param_3 != 0) && (param_3 != 1)) {
          return 1;
        }
        TPanelSystem::destroyPanel(&panel_system,&s_OKDialog);
        return 1;
      }
    }
    pcVar2 = TPanel::panelName(param_2);
    if (pcVar2 != (char *)0x0) {
      pbVar6 = &s_YesNoDialog;
      pbVar3 = (byte *)TPanel::panelName(param_2);
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_0046a5a5:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0046a5aa;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_0046a5a5;
        pbVar3 = pbVar3 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_0046a5aa:
      if (iVar4 == 0) {
        if ((param_3 != 0) && (param_3 != 1)) {
          return 1;
        }
        TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
        return 1;
      }
    }
    pcVar2 = TPanel::panelName(param_2);
    if (pcVar2 != (char *)0x0) {
      pbVar6 = &s_YesNoCancelDialog;
      pbVar3 = (byte *)TPanel::panelName(param_2);
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_0046a619:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0046a61e;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_0046a619;
        pbVar3 = pbVar3 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_0046a61e:
      if (iVar4 == 0) {
        if (((param_3 == 0) || (param_3 == 1)) || (param_3 == 2)) {
          TPanelSystem::destroyPanel(&panel_system,&s_YesNoCancelDialog);
        }
        return 1;
      }
    }
  }
  lVar5 = TPanel::action(param_1,param_2,param_3,param_4,param_5);
  return lVar5;
}

// --------------------------------------------------

// Function: FUN_0046a66d
// Address: 0046a66d
/* WARNING: Type propagation algorithm not settling */

void __fastcall FUN_0046a66d(int param_1)
{
  uint auStack_10 [2];
  undefined1 uStack_8;
  undefined1 uStack_7;
  ushort uStack_6;
  
  GetPaletteEntries(*(undefined4 *)(param_1 + 0x20c),*(undefined1 *)(param_1 + 0xef),1,&uStack_8);
  auStack_10[0] =
       ((uStack_6 & 0xff) << 8 | CONCAT21(uStack_6,uStack_7) & 0xff) << 8 |
       CONCAT11(uStack_7,uStack_8) & 0xff;
  auStack_10[1] = 5;
  SetSysColors(1,auStack_10 + 1,auStack_10);
  GetPaletteEntries(*(undefined4 *)(param_1 + 0x20c),*(undefined4 *)(param_1 + 0x328),1,&uStack_8);
  auStack_10[0] =
       ((uStack_6 & 0xff) << 8 | CONCAT21(uStack_6,uStack_7) & 0xff) << 8 |
       CONCAT11(uStack_7,uStack_8) & 0xff;
  auStack_10[1] = 8;
  SetSysColors(1,auStack_10 + 1,auStack_10);
  return;
}

// --------------------------------------------------

// Function: FUN_0046a73d
// Address: 0046a73d
undefined4 * __thiscall FUN_0046a73d(undefined4 *param_1,int param_2)
{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  *param_1 = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if ((param_2 == 0) || (-1 < param_2)) {
    param_1[10] = param_2;
    pvVar2 = operator_new(param_2 << 4);
    iVar5 = 0;
    if (0 < (int)param_1[0xb]) {
      iVar3 = 0;
      puVar4 = (undefined4 *)((int)pvVar2 + 8);
      do {
        iVar5 = iVar5 + 1;
        puVar1 = (undefined4 *)(param_1[9] + iVar3);
        iVar3 = iVar3 + 0x10;
        puVar4[-2] = *puVar1;
        puVar4[-1] = *(undefined4 *)(param_1[9] + -0xc + iVar3);
        *puVar4 = *(undefined4 *)(param_1[9] + -8 + iVar3);
        *(undefined1 *)(puVar4 + 1) = *(undefined1 *)(param_1[9] + -4 + iVar3);
        puVar4 = puVar4 + 4;
      } while (iVar5 < (int)param_1[0xb]);
    }
    if ((void *)param_1[9] != (void *)0x0) {
      operator_delete((void *)param_1[9]);
    }
    param_1[9] = pvVar2;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0046a7e2
// Address: 0046a7e2
void __fastcall FUN_0046a7e2(int param_1)
{
  if (*(void **)(param_1 + 0x24) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x24));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046a801
// Address: 0046a801
// [HELPER] s__: "}"
// [HELPER] s___: "]\n"
ostream * FUN_0046a801(ostream *param_1,int param_2)
{
  float fVar1;
  ostream *poVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  iVar3 = 0;
  if (0 < *(int *)(param_2 + 0x2c)) {
    iVar4 = 0;
    do {
      poVar2 = ostream::operator<<(param_1,s__);
      fVar1 = *(float *)(*(int *)(param_2 + 0x24) + iVar4);
      poVar2->x_floatused = 1;
      poVar2 = ostream::operator<<(poVar2,(double)fVar1);
      poVar2 = ostream::operator<<(poVar2,s___);
      fVar1 = *(float *)(*(int *)(param_2 + 0x24) + 4 + iVar4);
      poVar2->x_floatused = 1;
      poVar2 = ostream::operator<<(poVar2,(double)fVar1);
      poVar2 = ostream::operator<<(poVar2,s___);
      pcVar5 = s___;
      fVar1 = *(float *)(*(int *)(param_2 + 0x24) + 8 + iVar4);
      poVar2->x_floatused = 1;
      poVar2 = ostream::operator<<(poVar2,(double)fVar1);
      ostream::operator<<(poVar2,pcVar5);
      pcVar5 = s___;
      poVar2 = ostream::operator<<(param_1,(uint)*(byte *)(*(int *)(param_2 + 0x24) + 0xc + iVar4));
      ostream::operator<<(poVar2,pcVar5);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x10;
    } while (iVar3 < *(int *)(param_2 + 0x2c));
  }
  return param_1;
}

// --------------------------------------------------

// Function: operator<<
// Address: 0046a810
// [HELPER] s__: "}"
// [HELPER] s___: "]\n"
/* class ostream & __cdecl operator<<(class ostream &,class Path const &) */

ostream * __cdecl operator<<(ostream *param_1,Path *param_2)
{
  float fVar1;
  ostream *poVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  iVar3 = 0;
  if (0 < param_2->currentSizeValue) {
    iVar4 = 0;
    do {
      poVar2 = ostream::operator<<(param_1,s__);
      fVar1 = *(float *)((int)&param_2->pathValue->x + iVar4);
      poVar2->x_floatused = 1;
      poVar2 = ostream::operator<<(poVar2,(double)fVar1);
      poVar2 = ostream::operator<<(poVar2,s___);
      fVar1 = *(float *)((int)&param_2->pathValue->y + iVar4);
      poVar2->x_floatused = 1;
      poVar2 = ostream::operator<<(poVar2,(double)fVar1);
      poVar2 = ostream::operator<<(poVar2,s___);
      pcVar5 = s___;
      fVar1 = *(float *)((int)&param_2->pathValue->z + iVar4);
      poVar2->x_floatused = 1;
      poVar2 = ostream::operator<<(poVar2,(double)fVar1);
      ostream::operator<<(poVar2,pcVar5);
      pcVar5 = s___;
      poVar2 = ostream::operator<<(param_1,(uint)(&param_2->pathValue->facetToNextWaypoint)[iVar4]);
      ostream::operator<<(poVar2,pcVar5);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x10;
    } while (iVar3 < param_2->currentSizeValue);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0046a8de
// Address: 0046a8de
ulong * __thiscall FUN_0046a8de(int param_1,ulong *param_2,int param_3)
{
  int iVar1;
  Path *pPVar2;
  int iVar3;
  ulong *puVar4;
  undefined4 *unaff_FS_OFFSET;
  Path PStack_40;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e1bf;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = 0;
  Path::Path(&PStack_40,*(int *)(param_1 + 0x28) + *(int *)(param_3 + 0x28));
  iVar3 = 0;
  uStack_4 = 1;
  if (0 < *(int *)(param_1 + 0x2c)) {
    do {
      Path::insertAtEnd(&PStack_40,*(Waypoint *)(*(int *)(param_1 + 0x24) + iVar1));
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0x10;
    } while (iVar3 < *(int *)(param_1 + 0x2c));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_3 + 0x2c)) {
    iVar3 = iVar3 << 4;
    do {
      Path::insertAtEnd(&PStack_40,*(Waypoint *)(*(int *)(param_3 + 0x24) + iVar3));
      iVar3 = iVar3 + 0x10;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_3 + 0x2c));
  }
  pPVar2 = &PStack_40;
  puVar4 = param_2;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = pPVar2->timeStampValue;
    pPVar2 = (Path *)&pPVar2->startValue;
    puVar4 = puVar4 + 1;
  }
  uStack_4 = uStack_4 & 0xffffff00;
  Path::~Path(&PStack_40);
  *unaff_FS_OFFSET = uStack_c;
  return param_2;
}

// --------------------------------------------------

// Function: FUN_0046a9dd
// Address: 0046a9dd
int __thiscall FUN_0046a9dd(int param_1,int param_2)
{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x28);
  iVar3 = *(int *)(param_2 + 0x28);
  if (iVar3 <= iVar5) goto LAB_0046aa70;
  if (iVar3 == 0) {
LAB_0046aa00:
    iVar3 = iVar5;
  }
  else {
    if (iVar3 < iVar5) goto LAB_0046aa70;
    if (iVar3 == 0) goto LAB_0046aa00;
  }
  *(int *)(param_1 + 0x28) = iVar3 + iVar5;
  pvVar2 = operator_new((iVar3 + iVar5) * 0x10);
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x2c)) {
    iVar3 = 0;
    puVar4 = (undefined4 *)((int)pvVar2 + 8);
    do {
      iVar5 = iVar5 + 1;
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0x24) + iVar3);
      iVar3 = iVar3 + 0x10;
      puVar4[-2] = *puVar1;
      puVar4[-1] = *(undefined4 *)(*(int *)(param_1 + 0x24) + -0xc + iVar3);
      *puVar4 = *(undefined4 *)(*(int *)(param_1 + 0x24) + -8 + iVar3);
      *(undefined1 *)(puVar4 + 1) = *(undefined1 *)(*(int *)(param_1 + 0x24) + -4 + iVar3);
      puVar4 = puVar4 + 4;
    } while (iVar5 < *(int *)(param_1 + 0x2c));
  }
  if (*(void **)(param_1 + 0x24) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x24));
  }
  *(void **)(param_1 + 0x24) = pvVar2;
LAB_0046aa70:
  iVar5 = 0;
  if (0 < *(int *)(param_2 + 0x2c)) {
    iVar3 = 0;
    do {
      iVar5 = iVar5 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x24) + iVar3) =
           *(undefined4 *)(iVar3 + *(int *)(param_2 + 0x24));
      *(undefined4 *)(*(int *)(param_1 + 0x24) + 4 + iVar3) =
           *(undefined4 *)(iVar3 + 4 + *(int *)(param_2 + 0x24));
      *(undefined4 *)(*(int *)(param_1 + 0x24) + 8 + iVar3) =
           *(undefined4 *)(iVar3 + 8 + *(int *)(param_2 + 0x24));
      *(undefined1 *)(*(int *)(param_1 + 0x24) + 0xc + iVar3) =
           *(undefined1 *)(iVar3 + 0xc + *(int *)(param_2 + 0x24));
      iVar3 = iVar3 + 0x10;
    } while (iVar5 < *(int *)(param_2 + 0x2c));
  }
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0046aad1
// Address: 0046aad1
undefined4 __thiscall FUN_0046aad1(int param_1,int param_2)
{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(param_1 + 0x2c) < 1) {
    return 1;
  }
  pfVar1 = *(float **)(param_2 + 0x24);
  pfVar2 = (float *)(*(int *)(param_1 + 0x24) + 8);
  iVar3 = *(int *)(param_1 + 0x24) - (int)pfVar1;
  while( true ) {
    if ((*(float *)(iVar3 + (int)pfVar1) != *pfVar1) || (pfVar2[-1] != pfVar1[1])) {
      return 0;
    }
    if (*pfVar2 != pfVar1[2]) {
      return 0;
    }
    if (*(char *)(pfVar2 + 1) != *(char *)(pfVar1 + 3)) break;
    iVar4 = iVar4 + 1;
    pfVar2 = pfVar2 + 4;
    pfVar1 = pfVar1 + 4;
    if (*(int *)(param_1 + 0x2c) <= iVar4) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046ab5a
// Address: 0046ab5a
undefined4 __thiscall FUN_0046ab5a(int param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (1000 < *(int *)(param_1 + 0x2c)) {
    return 0;
  }
  puVar2 = (undefined4 *)operator_new((*(int *)(param_1 + 0x2c) + 1) * 0x10);
  iVar5 = 0;
  *puVar2 = *param_2;
  puVar2[1] = param_2[1];
  puVar2[2] = param_2[2];
  *(undefined1 *)(puVar2 + 3) = *(undefined1 *)(param_2 + 3);
  if (0 < *(int *)(param_1 + 0x2c)) {
    iVar3 = 0;
    puVar4 = puVar2 + 5;
    do {
      iVar5 = iVar5 + 1;
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0x24) + iVar3);
      iVar3 = iVar3 + 0x10;
      puVar4[-1] = *puVar1;
      *puVar4 = *(undefined4 *)(*(int *)(param_1 + 0x24) + -0xc + iVar3);
      puVar4[1] = *(undefined4 *)(*(int *)(param_1 + 0x24) + -8 + iVar3);
      *(undefined1 *)(puVar4 + 2) = *(undefined1 *)(*(int *)(param_1 + 0x24) + -4 + iVar3);
      puVar4 = puVar4 + 4;
    } while (iVar5 < *(int *)(param_1 + 0x2c));
  }
  if (*(void **)(param_1 + 0x24) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x24));
  }
  *(undefined4 **)(param_1 + 0x24) = puVar2;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0046ac07
// Address: 0046ac07
undefined4 __thiscall
FUN_0046ac07(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5
            )
{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x28);
  if (*(int *)(param_1 + 0x2c) == iVar5) {
    *(int *)(param_1 + 0x28) = iVar5 * 2;
    pvVar2 = operator_new(iVar5 << 5);
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x2c)) {
      iVar3 = 0;
      puVar4 = (undefined4 *)((int)pvVar2 + 8);
      do {
        iVar5 = iVar5 + 1;
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x24) + iVar3);
        iVar3 = iVar3 + 0x10;
        puVar4[-2] = *puVar1;
        puVar4[-1] = *(undefined4 *)(*(int *)(param_1 + 0x24) + -0xc + iVar3);
        *puVar4 = *(undefined4 *)(*(int *)(param_1 + 0x24) + -8 + iVar3);
        *(undefined1 *)(puVar4 + 1) = *(undefined1 *)(*(int *)(param_1 + 0x24) + -4 + iVar3);
        puVar4 = puVar4 + 4;
      } while (iVar5 < *(int *)(param_1 + 0x2c));
    }
    if (*(void **)(param_1 + 0x24) != (void *)0x0) {
      operator_delete(*(void **)(param_1 + 0x24));
    }
    *(void **)(param_1 + 0x24) = pvVar2;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x2c) * 0x10 + *(int *)(param_1 + 0x24)) = param_2;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) * 0x10 + 4 + *(int *)(param_1 + 0x24)) = param_3;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) * 0x10 + 8 + *(int *)(param_1 + 0x24)) = param_4;
  *(undefined1 *)(*(int *)(param_1 + 0x2c) * 0x10 + 0xc + *(int *)(param_1 + 0x24)) = param_5;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0046acdd
// Address: 0046acdd
undefined4 __thiscall FUN_0046acdd(int param_1,float *param_2)
{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x2c) < 1) {
    return 0;
  }
  iVar2 = 0;
  do {
    fVar3 = (float10)floor((double)*(float *)(*(int *)(param_1 + 0x24) + iVar2));
    fVar4 = (float10)floor((double)*param_2);
    if ((float10)(double)fVar3 == fVar4) {
      fVar3 = (float10)floor((double)*(float *)(*(int *)(param_1 + 0x24) + 4 + iVar2));
      fVar4 = (float10)floor((double)param_2[1]);
      if ((float10)(double)fVar3 == fVar4) {
        return 1;
      }
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x10;
  } while (iVar1 < *(int *)(param_1 + 0x2c));
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046ad96
// Address: 0046ad96
void __fastcall FUN_0046ad96(int param_1)
{
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0046ada9
// Address: 0046ada9
undefined4 __fastcall FUN_0046ada9(int param_1)
{
  return *(undefined4 *)(param_1 + 0x28);
}

// --------------------------------------------------

// Function: FUN_0046adb4
// Address: 0046adb4
undefined4 __fastcall FUN_0046adb4(int param_1)
{
  return *(undefined4 *)(param_1 + 0x2c);
}

// --------------------------------------------------

// Function: FUN_0046adc4
// Address: 0046adc4
undefined4 __fastcall FUN_0046adc4(undefined4 *param_1)
{
  return *param_1;
}

// --------------------------------------------------

// Function: FUN_0046add3
// Address: 0046add3
void __thiscall FUN_0046add3(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0046ade9
// Address: 0046ade9
float10 __fastcall FUN_0046ade9(int param_1)
{
  float *pfVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  
  fVar3 = (float10)(float)DAT_00570e40;
  if (1 < *(int *)(param_1 + 0x2c)) {
    iVar2 = *(int *)(param_1 + 0x2c) + -1;
    pfVar1 = *(float **)(param_1 + 0x24);
    do {
      fVar4 = (float10)pfVar1[4] - (float10)*pfVar1;
      iVar2 = iVar2 + -1;
      fVar3 = SQRT(((float10)pfVar1[5] - (float10)pfVar1[1]) *
                   (float10)(float)((float10)pfVar1[5] - (float10)pfVar1[1]) +
                   fVar4 * fVar4 +
                   ((float10)pfVar1[6] - (float10)*pfVar1) *
                   ((float10)pfVar1[6] - (float10)pfVar1[2])) + fVar3;
      pfVar1 = pfVar1 + 4;
    } while (iVar2 != 0);
  }
  return fVar3;
}

// --------------------------------------------------

// Function: FUN_0046ae4b
// Address: 0046ae4b
int __fastcall FUN_0046ae4b(int param_1)
{
  return param_1 + 4;
}

// --------------------------------------------------

// Function: FUN_0046ae54
// Address: 0046ae54
int __fastcall FUN_0046ae54(int param_1)
{
  return param_1 + 0x14;
}

// --------------------------------------------------

// Function: FUN_0046ae64
// Address: 0046ae64
int __thiscall FUN_0046ae64(int param_1,int param_2)
{
  if (((*(int *)(param_1 + 0x24) != 0) && (-1 < param_2)) && (param_2 < *(int *)(param_1 + 0x2c))) {
    return param_2 * 0x10 + *(int *)(param_1 + 0x24);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046ae92
// Address: 0046ae92
int __fastcall FUN_0046ae92(int param_1)
{
  int iVar1;
  
  if (((*(int *)(param_1 + 0x24) != 0) && (iVar1 = *(int *)(param_1 + 0x30), -1 < iVar1)) &&
     (iVar1 < *(int *)(param_1 + 0x2c))) {
    return iVar1 * 0x10 + *(int *)(param_1 + 0x24);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046aebd
// Address: 0046aebd
undefined4 __fastcall FUN_0046aebd(int param_1)
{
  return *(undefined4 *)(param_1 + 0x30);
}

// --------------------------------------------------

// Function: FUN_0046aec4
// Address: 0046aec4
void __thiscall FUN_0046aec4(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0046aeda
// Address: 0046aeda
int __fastcall FUN_0046aeda(int param_1)
{
  int iVar1;
  
  if (((*(int *)(param_1 + 0x24) != 0) && (-1 < *(int *)(param_1 + 0x30))) &&
     (iVar1 = *(int *)(param_1 + 0x30) + 1, iVar1 < *(int *)(param_1 + 0x2c))) {
    return iVar1 * 0x10 + *(int *)(param_1 + 0x24);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046af03
// Address: 0046af03
int __fastcall FUN_0046af03(int param_1)
{
  int iVar1;
  
  if (((*(int *)(param_1 + 0x24) != 0) &&
      (iVar1 = *(int *)(param_1 + 0x30), iVar1 != -1 && -1 < iVar1 + 1)) &&
     (iVar1 < *(int *)(param_1 + 0x2c))) {
    return iVar1 * 0x10 + -0x10 + *(int *)(param_1 + 0x24);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046af34
// Address: 0046af34
int __fastcall FUN_0046af34(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0x2c) < 1)) {
    iVar1 = 0;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0046af51
// Address: 0046af51
int __fastcall FUN_0046af51(int param_1)
{
  if ((*(int *)(param_1 + 0x24) != 0) && (0 < *(int *)(param_1 + 0x2c))) {
    return *(int *)(param_1 + 0x2c) * 0x10 + -0x10 + *(int *)(param_1 + 0x24);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046af79
// Address: 0046af79
void __fastcall FUN_0046af79(int param_1)
{
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0046af88
// Address: 0046af88
void __fastcall FUN_0046af88(int param_1)
{
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x2c) + -1;
  return;
}

// --------------------------------------------------

// Function: FUN_0046af98
// Address: 0046af98
undefined4 __fastcall FUN_0046af98(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2c) + -1;
  if (*(int *)(param_1 + 0x30) < iVar1) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
    return 1;
  }
  *(int *)(param_1 + 0x30) = iVar1;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046afbb
// Address: 0046afbb
undefined4 __fastcall FUN_0046afbb(int param_1)
{
  if (0 < *(int *)(param_1 + 0x30)) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046afd4
// Address: 0046afd4
float10 __fastcall FUN_0046afd4(int param_1)
{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  iVar2 = *(int *)(param_1 + 0x24);
  fVar4 = (float10)(float)DAT_00570e40;
  if (((iVar2 != 0) && (iVar3 = *(int *)(param_1 + 0x30), -1 < iVar3)) &&
     (iVar3 < *(int *)(param_1 + 0x2c) + -1)) {
    pfVar1 = (float *)(iVar3 * 0x10 + iVar2);
    fVar4 = (float10)*(float *)((iVar3 + 1) * 0x10 + iVar2) - (float10)*pfVar1;
    fVar4 = SQRT(((float10)pfVar1[6] - (float10)pfVar1[2]) *
                 (float10)(float)((float10)pfVar1[6] - (float10)pfVar1[2]) +
                 ((float10)pfVar1[5] - (float10)pfVar1[1]) *
                 ((float10)pfVar1[5] - (float10)pfVar1[1]) + fVar4 * (float10)(float)fVar4);
  }
  return fVar4;
}

// --------------------------------------------------

// Function: FUN_0046b04e
// Address: 0046b04e
void FUN_0046b04e(void)
{
  _E9();
  _E11();
  return;
}

// --------------------------------------------------

// Function: $E12
// Address: 0046b050
void _E12(void)
{
  _E9();
  _E11();
  return;
}

// --------------------------------------------------

// Function: FUN_0046b05a
// Address: 0046b05a
void FUN_0046b05a(void)
{
  PathingSystem::PathingSystem(&pathSystem,0xff,0xff,0,(RGE_Map *)0x0,(RGE_Game_World *)0x0);
  return;
}

// --------------------------------------------------

// Function: $E9
// Address: 0046b060
void _E9(void)
{
  PathingSystem::PathingSystem(&pathSystem,0xff,0xff,0,(RGE_Map *)0x0,(RGE_Game_World *)0x0);
  return;
}

// --------------------------------------------------

// Function: FUN_0046b07b
// Address: 0046b07b
void FUN_0046b07b(void)
{
  atexit(_E10);
  return;
}

// --------------------------------------------------

// Function: $E11
// Address: 0046b080
void _E11(void)
{
  atexit(_E10);
  return;
}

// --------------------------------------------------

// Function: FUN_0046b08e
// Address: 0046b08e
void FUN_0046b08e(void)
{
  PathingSystem::~PathingSystem(&pathSystem);
  return;
}

// --------------------------------------------------

// Function: $E10
// Address: 0046b090
void _E10(void)
{
  PathingSystem::~PathingSystem(&pathSystem);
  return;
}

// --------------------------------------------------

// Function: FUN_0046b09a
// Address: 0046b09a
void FUN_0046b09a(void)
{
  _E14();
  _E16();
  return;
}

// --------------------------------------------------

// Function: $E17
// Address: 0046b0a0
void _E17(void)
{
  _E14();
  _E16();
  return;
}

// --------------------------------------------------

// Function: FUN_0046b0aa
// Address: 0046b0aa
void FUN_0046b0aa(void)
{
  PathingSystem::PathingSystem(&aiPathSystem,0xff,0xff,1,(RGE_Map *)0x0,(RGE_Game_World *)0x0);
  return;
}

// --------------------------------------------------

// Function: $E14
// Address: 0046b0b0
void _E14(void)
{
  PathingSystem::PathingSystem(&aiPathSystem,0xff,0xff,1,(RGE_Map *)0x0,(RGE_Game_World *)0x0);
  return;
}

// --------------------------------------------------

// Function: FUN_0046b0cb
// Address: 0046b0cb
void FUN_0046b0cb(void)
{
  atexit(_E15);
  return;
}

// --------------------------------------------------

// Function: $E16
// Address: 0046b0d0
void _E16(void)
{
  atexit(_E15);
  return;
}

// --------------------------------------------------

// Function: FUN_0046b0de
// Address: 0046b0de
void FUN_0046b0de(void)
{
  PathingSystem::~PathingSystem(&aiPathSystem);
  return;
}

// --------------------------------------------------

// Function: $E15
// Address: 0046b0e0
void _E15(void)
{
  PathingSystem::~PathingSystem(&aiPathSystem);
  return;
}

// --------------------------------------------------

// Function: FUN_0046b0ea
// Address: 0046b0ea
PathingSystem * __thiscall
FUN_0046b0ea(PathingSystem *param_1,int param_2,int param_3,int param_4,RGE_Map *param_5,
            RGE_Game_World *param_6)
{
  int *piVar1;
  int **ppiVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e1ec;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  (param_1->initialCollidingObjects).value = (int *)0x0;
  (param_1->initialCollidingObjects).numberValue = 0;
  (param_1->initialCollidingObjects).desiredNumberValue = 0;
  (param_1->initialCollidingObjects).maximumSizeValue = 0;
  (param_1->currentUnobstructibles).value = (int *)0x0;
  (param_1->currentUnobstructibles).numberValue = 0;
  (param_1->currentUnobstructibles).desiredNumberValue = 0;
  (param_1->currentUnobstructibles).maximumSizeValue = 0;
  param_1->aiPS = param_4;
  param_1->xSizeValue = -1;
  param_1->ySizeValue = -1;
  param_1->currentTerrainException1 = -1;
  param_1->currentTerrainException2 = -1;
  uStack_4 = 1;
  param_1->_padding_ = (int)&PathingSystem::_vftable_;
  param_1->numberOpenPathsValue = 0;
  param_1->numberTraversedPathsValue = 0;
  param_1->mapValue = (RGE_Map *)0x0;
  param_1->worldValue = (RGE_Game_World *)0x0;
  param_1->currentObject = (RGE_Moving_Object *)0x0;
  param_1->averageNumWaypoints = 0.0;
  param_1->averagePathLength = 0.0;
  param_1->averagePathIterations = 0.0;
  param_1->averageClosestTargetDistance = 0.0;
  param_1->numAttempts = 0;
  param_1->numFails = 0;
  param_1->numSuccesses = 0;
  param_1->numInitialPathsValue = 0;
  param_1->numContinuePathsValue = 0;
  param_1->numCanPathsValue = 0;
  param_1->averageSuccessTime = 0.0;
  param_1->averageFailTime = 0.0;
  PathingSystem::initialize(param_1,param_2,param_3,param_5,param_6);
  PathingSystem::initMisc(param_1,'\0');
  PathingSystem::zeroObstructionMap(param_1);
  ppiVar2 = &DiagionalDistance;
  do {
    piVar1 = (int *)__ftol();
    *ppiVar2 = piVar1;
    ppiVar2 = ppiVar2 + 1;
  } while ((int)ppiVar2 < 0x74d440);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0046b24d
// Address: 0046b24d
PathingSystem * __thiscall FUN_0046b24d(PathingSystem *param_1,byte param_2)
{
  PathingSystem::~PathingSystem(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0046b26e
// Address: 0046b26e
void __fastcall FUN_0046b26e(undefined4 *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055e20e;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &PathingSystem::_vftable_;
  uStack_4 = 0;
  if ((void *)param_1[0x47739] != (void *)0x0) {
    operator_delete((void *)param_1[0x47739]);
    param_1[0x47739] = 0;
  }
  param_1[0x4773a] = 0;
  param_1[0x4773b] = 0;
  param_1[0x4773c] = 0;
  uStack_4 = 0xffffffff;
  if ((void *)param_1[0x47719] != (void *)0x0) {
    operator_delete((void *)param_1[0x47719]);
    param_1[0x47719] = 0;
  }
  param_1[0x4771a] = 0;
  param_1[0x4771b] = 0;
  param_1[0x4771c] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0046b304
// Address: 0046b304
undefined4 __thiscall
FUN_0046b304(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)
{
  *(int *)(param_1 + 0x11dc3c) = param_4;
  *(undefined4 *)(param_1 + 0x11dc40) = param_5;
  if (param_4 != 0) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_4 + 8);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_4 + 0xc);
    *(undefined1 *)(param_1 + 0x11dcd8) = 0xf0;
    return 1;
  }
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined1 *)(param_1 + 0x11dcd8) = 0xf0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0046b546
// Address: 0046b546
undefined4 __thiscall FUN_0046b546(int param_1,int param_2,int param_3)
{
  param_3 = param_3 + param_2 * 0xff;
  return CONCAT31((int3)((uint)param_3 >> 8),*(undefined1 *)(param_1 + 0x10de28 + param_3));
}

// --------------------------------------------------

// Function: FUN_0046b56b
// Address: 0046b56b
void __thiscall FUN_0046b56b(int param_1,int param_2,int param_3,undefined1 param_4)
{
  *(undefined1 *)(param_2 * 0xff + param_1 + 0x10de28 + param_3) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_0046b58f
// Address: 0046b58f
void __thiscall FUN_0046b58f(int param_1,undefined1 param_2)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x10de28);
  for (iVar1 = 0x3f80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0046b5ba
// Address: 0046b5ba
void __fastcall FUN_0046b5ba(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0xce624);
  for (iVar1 = 0xfe01; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046b5d4
// Address: 0046b5d4
// [HELPER] ObstructionValueShift: "06040200"
byte __thiscall FUN_0046b5d4(int param_1,int param_2,uint param_3)
{
  return *(byte *)(param_2 * 0xff + 0xce624 + param_1 + ((int)param_3 >> 2)) >>
         (*(byte *)((int)&ObstructionValueShift + (param_3 & 3)) & 0x1f) & 3;
}

// --------------------------------------------------

// Function: FUN_0046b614
// Address: 0046b614
// [HELPER] ObstructionValueMask: "3fcff3fc"
// [HELPER] ObstructionValueShift: "06040200"
void __thiscall FUN_0046b614(int param_1,int param_2,uint param_3)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  param_1 = param_1 + ((int)param_3 >> 2);
  bVar1 = *(byte *)(param_2 * 0xff + 0xce624 + param_1);
  bVar2 = *(byte *)((int)&ObstructionValueShift + (param_3 & 3));
  bVar3 = bVar1 >> (bVar2 & 0x1f) & 3;
  if (bVar3 < 3) {
    *(byte *)(param_2 * 0xff + 0xce624 + param_1) =
         *(byte *)((int)&ObstructionValueMask + (param_3 & 3)) & bVar1 | bVar3 + 1 << (bVar2 & 0x1f)
    ;
  }
  return;
}

// --------------------------------------------------

