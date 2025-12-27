// GLOBAL FUNCTIONS PART 3000
// Function: FUN_0047dc0b
// Address: 0047dc0b
undefined4 __fastcall FUN_0047dc0b(int param_1)
{
  if (*(int **)(param_1 + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x40) + 0xb4))(param_1,1,0,0);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047dc2d
// Address: 0047dc2d
int __fastcall FUN_0047dc2d(int param_1)
{
  return (int)*(short *)(param_1 + 0xf8);
}

// --------------------------------------------------

// Function: FUN_0047dc38
// Address: 0047dc38
int __fastcall FUN_0047dc38(int param_1)
{
  return (int)*(short *)(param_1 + 0xfa);
}

// --------------------------------------------------

// Function: FUN_0047dc48
// Address: 0047dc48
int __fastcall FUN_0047dc48(int param_1)
{
  return (int)*(short *)(param_1 + 0x100);
}

// --------------------------------------------------

// Function: FUN_0047dc58
// Address: 0047dc58
void __thiscall FUN_0047dc58(TTextPanel *param_1,long param_2)
{
  TTextPanel::set_line(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0047dc75
// Address: 0047dc75
void __thiscall FUN_0047dc75(TTextPanel *param_1,short param_2)
{
  param_1->cur_line = param_2;
  TTextPanel::calc_draw_info(param_1,1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047dc96
// Address: 0047dc96
void __thiscall FUN_0047dc96(TTextPanel *param_1,int param_2)
{
  TextNode *pTVar1;
  int iVar2;
  
  pTVar1 = param_1->list;
  iVar2 = 0;
  if (pTVar1 != (TextNode *)0x0) {
    while (pTVar1->id != param_2) {
      pTVar1 = pTVar1->next_node;
      iVar2 = iVar2 + 1;
      if (pTVar1 == (TextNode *)0x0) {
        return;
      }
    }
    TTextPanel::set_line(param_1,iVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047dccc
// Address: 0047dccc
void __thiscall FUN_0047dccc(TTextPanel *param_1,char *param_2,long param_3)
{
  TTextPanel::insert_line(param_1,(int)param_1->num_lines,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0047dcea
// Address: 0047dcea
void __thiscall FUN_0047dcea(TTextPanel *param_1,char *param_2,char *param_3,long param_4)
{
  TTextPanel::insert_line(param_1,(int)param_1->num_lines,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_0047dd0f
// Address: 0047dd0f
void __thiscall FUN_0047dd0f(TTextPanel *param_1,long param_2,long param_3)
{
  TTextPanel::insert_line(param_1,(int)param_1->num_lines,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0047dd2a
// Address: 0047dd2a
void __thiscall FUN_0047dd2a(TTextPanel *param_1,long param_2,long param_3,long param_4)
{
  TTextPanel::insert_line(param_1,(int)param_1->num_lines,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_0047dd4f
// Address: 0047dd4f
void __thiscall FUN_0047dd4f(TTextPanel *param_1,long param_2,char *param_3,long param_4)
{
  TTextPanel::insert_line(param_1,param_2,param_3,(char *)0x0,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_0047dd69
// Address: 0047dd69
undefined4 __thiscall
FUN_0047dd69(TTextPanel *param_1,int param_2,char *param_3,char *param_4,long param_5)
{
  char cVar1;
  TextNode *pTVar2;
  uint uVar3;
  char *pcVar4;
  TextNode *pTVar5;
  uint uVar6;
  int iVar7;
  TextNode *pTVar8;
  TextNode *pTVar9;
  char *pcVar10;
  
  pTVar2 = (TextNode *)calloc(1,0x10);
  if (pTVar2 == (TextNode *)0x0) {
    return 0;
  }
  if (param_1->fixed_len == 0) {
    if (param_3 == (char *)0x0) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0xffffffff;
      pcVar4 = param_3;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
    }
  }
  else {
    uVar3 = (int)param_1->fixed_len + 1;
  }
  pcVar4 = (char *)calloc(uVar3,1);
  pTVar2->text = pcVar4;
  if (pcVar4 == (char *)0x0) {
    free(pTVar2);
    return 0;
  }
  if (param_4 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar4 = param_4;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = (char *)calloc(~uVar3,1);
    pTVar2->text2 = pcVar4;
    if (pcVar4 == (char *)0x0) {
      free(pTVar2->text);
      free(pTVar2);
      return 0;
    }
  }
  if (param_3 == (char *)0x0) {
    *pTVar2->text = '\0';
  }
  else if (param_1->fixed_len == 0) {
    uVar3 = 0xffffffff;
    do {
      pcVar4 = param_3;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar4 = param_3 + 1;
      cVar1 = *param_3;
      param_3 = pcVar4;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar4 = pcVar4 + -uVar3;
    pcVar10 = pTVar2->text;
    for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar10 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar10 = pcVar10 + 1;
    }
  }
  else {
    strncpy(pTVar2->text,param_3,(int)param_1->fixed_len);
    pTVar2->text[param_1->fixed_len] = '\0';
  }
  if (param_4 != (char *)0x0) {
    uVar3 = 0xffffffff;
    do {
      pcVar4 = param_4;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar4 = param_4 + 1;
      cVar1 = *param_4;
      param_4 = pcVar4;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar4 = pcVar4 + -uVar3;
    pcVar10 = pTVar2->text2;
    for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar10 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar10 = pcVar10 + 1;
    }
  }
  pTVar2->id = param_5;
  iVar7 = 0;
  pTVar2->next_node = (TextNode *)0x0;
  pTVar5 = param_1->list;
  if (pTVar5 == (TextNode *)0x0) {
    param_1->list = pTVar2;
  }
  else if (param_1->sorted == 0) {
    if (param_2 == 0) {
      pTVar2->next_node = pTVar5;
      param_1->list = pTVar2;
    }
    else if (param_2 < param_1->num_lines) {
      for (; iVar7 != param_2 + -1; iVar7 = iVar7 + 1) {
        pTVar5 = pTVar5->next_node;
      }
      pTVar2->next_node = pTVar5->next_node;
      pTVar5->next_node = pTVar2;
    }
    else {
      do {
        pTVar8 = pTVar5;
        pTVar5 = pTVar8->next_node;
      } while (pTVar5 != (TextNode *)0x0);
      pTVar8->next_node = pTVar2;
    }
  }
  else {
    pTVar8 = (TextNode *)0x0;
    if (pTVar5 != (TextNode *)0x0) {
      do {
        iVar7 = CompareStringA(0x400,1,pTVar2->text,0xffffffff,pTVar5->text,0xffffffff);
        if (iVar7 == 1) {
          pTVar2->next_node = pTVar5;
          pTVar9 = pTVar5;
          if (pTVar8 == (TextNode *)0x0) {
            param_1->list = pTVar2;
          }
          else {
            pTVar8->next_node = pTVar2;
          }
          break;
        }
        pTVar9 = pTVar5->next_node;
        pTVar8 = pTVar5;
        pTVar5 = pTVar9;
      } while (pTVar9 != (TextNode *)0x0);
      if (pTVar9 != (TextNode *)0x0) goto LAB_0047df25;
    }
    pTVar8->next_node = pTVar2;
  }
LAB_0047df25:
  param_1->num_lines = param_1->num_lines + 1;
  TTextPanel::calc_draw_info(param_1,1);
  (**(code **)(param_1->_padding_ + 0x20))(1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047df8d
// Address: 0047df8d
void __thiscall FUN_0047df8d(TTextPanel *param_1,long param_2,int param_3,long param_4)
{
  char acStack_100 [256];
  
  TPanel::get_string((TPanel *)param_1,param_3,acStack_100,0x100);
  TTextPanel::insert_line(param_1,param_2,acStack_100,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_0047dfd8
// Address: 0047dfd8
void __thiscall FUN_0047dfd8(TTextPanel *param_1,long param_2,int param_3,int param_4,long param_5)
{
  char acStack_200 [256];
  char acStack_100 [256];
  
  TPanel::get_string((TPanel *)param_1,param_3,acStack_100,0x100);
  TPanel::get_string((TPanel *)param_1,param_4,acStack_200,0x100);
  TTextPanel::insert_line(param_1,param_2,acStack_100,acStack_200,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0047e04c
// Address: 0047e04c
undefined4 __thiscall
FUN_0047e04c(TTextPanel *param_1,int param_2,char *param_3,char *param_4,long param_5)
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1->sorted;
  param_1->sorted = 0;
  iVar2 = TTextPanel::insert_line(param_1,param_2,param_3,param_4,param_5);
  if (iVar2 == 0) {
    param_1->sorted = iVar1;
    return 0;
  }
  TTextPanel::delete_line(param_1,param_2 + 1);
  param_1->sorted = iVar1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047e0aa
// Address: 0047e0aa
undefined4 __thiscall
FUN_0047e0aa(TTextPanel *param_1,int param_2,long param_3,long param_4,long param_5)
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1->sorted;
  param_1->sorted = 0;
  iVar2 = TTextPanel::insert_line(param_1,param_2,param_3,param_4,param_5);
  if (iVar2 == 0) {
    param_1->sorted = iVar1;
    return 0;
  }
  TTextPanel::delete_line(param_1,param_2 + 1);
  param_1->sorted = iVar1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047e10a
// Address: 0047e10a
undefined4 __thiscall FUN_0047e10a(TTextPanel *param_1,int param_2)
{
  short sVar1;
  TextNode *pTVar2;
  int iVar3;
  TextNode *pTVar4;
  
  if ((-1 < param_2) && (param_2 <= param_1->num_lines + -1)) {
    if (param_2 == 0) {
      pTVar4 = param_1->list;
      param_1->list = pTVar4->next_node;
    }
    else {
      pTVar2 = param_1->list;
      for (iVar3 = 0; iVar3 != param_2 + -1; iVar3 = iVar3 + 1) {
        pTVar2 = pTVar2->next_node;
      }
      pTVar4 = pTVar2->next_node;
      pTVar2->next_node = pTVar4->next_node;
    }
    if (pTVar4 != (TextNode *)0x0) {
      if (pTVar4->text != (char *)0x0) {
        free(pTVar4->text);
      }
      if (pTVar4->text2 != (char *)0x0) {
        free(pTVar4->text2);
      }
      free(pTVar4);
      param_1->num_lines = param_1->num_lines + -1;
      sVar1 = param_1->num_lines;
      if (sVar1 == 0) {
        param_1->cur_line = 0;
      }
      else if (sVar1 <= param_1->cur_line) {
        param_1->cur_line = sVar1 + -1;
      }
      TTextPanel::calc_draw_info(param_1,1);
      (**(code **)(param_1->_padding_ + 0x20))(1);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047e1dd
// Address: 0047e1dd
int __fastcall FUN_0047e1dd(int param_1)
{
  if (*(short *)(param_1 + 0xf8) == 0) {
    return -1;
  }
  return (int)*(short *)(param_1 + 0x100);
}

// --------------------------------------------------

// Function: FUN_0047e1f6
// Address: 0047e1f6
int __thiscall FUN_0047e1f6(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xf4);
  iVar2 = 0;
  while( true ) {
    if (iVar1 == 0) {
      return -1;
    }
    if (*(int *)(iVar1 + 8) == param_2) break;
    iVar1 = *(int *)(iVar1 + 0xc);
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0047e223
// Address: 0047e223
int __thiscall FUN_0047e223(int param_1,byte *param_2)
{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  
  puVar2 = *(undefined4 **)(param_1 + 0xf4);
  iVar3 = 0;
  do {
    if (puVar2 == (undefined4 *)0x0) {
      return -1;
    }
    pbVar4 = (byte *)*puVar2;
    pbVar6 = param_2;
    do {
      bVar1 = *pbVar4;
      bVar7 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_0047e26c:
        iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_0047e271;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar7 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_0047e26c;
      pbVar4 = pbVar4 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_0047e271:
    if (iVar5 == 0) {
      return iVar3;
    }
    puVar2 = (undefined4 *)puVar2[3];
    iVar3 = iVar3 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0047e287
// Address: 0047e287
void __fastcall FUN_0047e287(TTextPanel *param_1)
{
  TTextPanel::get_text(param_1,(int)param_1->cur_line);
  return;
}

// --------------------------------------------------

// Function: FUN_0047e29e
// Address: 0047e29e
undefined4 __thiscall FUN_0047e29e(int param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0xf4);
  iVar2 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_0086b24c._4_1_ = 0;
    return 0x86b250;
  }
  do {
    if (iVar2 == param_2) {
      return *puVar1;
    }
    puVar1 = (undefined4 *)puVar1[3];
    iVar2 = iVar2 + 1;
  } while (puVar1 != (undefined4 *)0x0);
  DAT_0086b24c._4_1_ = 0;
  return 0x86b250;
}

// --------------------------------------------------

// Function: FUN_0047e2dd
// Address: 0047e2dd
void __fastcall FUN_0047e2dd(TTextPanel *param_1)
{
  TTextPanel::get_text2(param_1,(int)param_1->cur_line);
  return;
}

// --------------------------------------------------

// Function: FUN_0047e2ee
// Address: 0047e2ee
Alignment * __thiscall FUN_0047e2ee(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xf4);
  iVar2 = 0;
  if (iVar1 == 0) {
    DAT_0086b24c._0_1_ = 0;
    return &DAT_0086b24c;
  }
  do {
    if (iVar2 == param_2) {
      return *(Alignment **)(iVar1 + 4);
    }
    iVar1 = *(int *)(iVar1 + 0xc);
    iVar2 = iVar2 + 1;
  } while (iVar1 != 0);
  DAT_0086b24c._0_1_ = 0;
  return &DAT_0086b24c;
}

// --------------------------------------------------

// Function: FUN_0047e32e
// Address: 0047e32e
void __fastcall FUN_0047e32e(TTextPanel *param_1)
{
  TTextPanel::get_id(param_1,(int)param_1->cur_line);
  return;
}

// --------------------------------------------------

// Function: FUN_0047e33e
// Address: 0047e33e
undefined4 __thiscall FUN_0047e33e(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xf4);
  iVar2 = 0;
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  do {
    if (iVar2 == param_2) {
      return *(undefined4 *)(iVar1 + 8);
    }
    iVar1 = *(int *)(iVar1 + 0xc);
    iVar2 = iVar2 + 1;
  } while (iVar1 != 0);
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0047e375
// Address: 0047e375
void __fastcall FUN_0047e375(TTextPanel *param_1)
{
  TextNode *pTVar1;
  TextNode *pTVar2;
  
  pTVar2 = param_1->list;
  if (param_1->list != (TextNode *)0x0) {
    do {
      if (pTVar2->text != (char *)0x0) {
        free(pTVar2->text);
      }
      if (pTVar2->text2 != (char *)0x0) {
        free(pTVar2->text2);
      }
      pTVar1 = pTVar2->next_node;
      free(pTVar2);
      pTVar2 = pTVar1;
    } while (pTVar1 != (TextNode *)0x0);
    param_1->list = (TextNode *)0x0;
  }
  param_1->num_lines = 0;
  TTextPanel::calc_draw_info(param_1,1);
  (**(code **)(param_1->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047e3e3
// Address: 0047e3e3
void __thiscall FUN_0047e3e3(int *param_1,int param_2)
{
  param_1[0x58] = param_2;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047e404
// Address: 0047e404
// [HELPER] s_pnl_txt__get_text_rect: "pnl_txt::get_text_rect"
undefined4 __thiscall FUN_0047e404(TTextPanel *param_1,tagRECT *param_2)
{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_pnl_txt__get_text_rect);
  if (pvVar1 != (void *)0x0) {
    uVar2 = SelectObject(pvVar1,param_1->font);
    TTextPanel::calc_line_pos(param_1,pvVar1,0,0,param_2,(long *)0x0);
    SelectObject(pvVar1,uVar2);
    TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_pnl_txt__get_text_rect);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047e472
// Address: 0047e472
void __fastcall FUN_0047e472(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0047e48d
// Address: 0047e48d
void __thiscall
FUN_0047e48d(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_0047e4a9
// Address: 0047e4a9
undefined4 FUN_0047e4a9(int *param_1,int *param_2)
{
  if (((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: operator==
// Address: 0047e4b0
/* int __cdecl operator==(class XYZ const &,class XYZ const &) */

int __cdecl operator==(XYZ *param_1,XYZ *param_2)
{
  if (((param_1->xValue == param_2->xValue) && (param_1->yValue == param_2->yValue)) &&
     (param_1->zValue == param_2->zValue)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: operator!=
// Address: 0047e4e0
/* int __cdecl operator!=(class XYZ const &,class XYZ const &) */

int __cdecl operator!=(XYZ *param_1,XYZ *param_2)
{
  if (((param_1->xValue == param_2->xValue) && (param_1->yValue == param_2->yValue)) &&
     (param_1->zValue == param_2->zValue)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047e529
// Address: 0047e529
void __thiscall FUN_0047e529(int *param_1,int *param_2,int *param_3)
{
  XYZ XStack_c;
  
  XYZ::XYZ(&XStack_c,*param_1 + *param_3,param_1[1] + param_3[1],param_3[2] + param_1[2]);
  *param_2 = XStack_c.xValue;
  param_2[1] = XStack_c.yValue;
  param_2[2] = XStack_c.zValue;
  return;
}

// --------------------------------------------------

// Function: FUN_0047e57b
// Address: 0047e57b
void __thiscall FUN_0047e57b(int *param_1,int *param_2,int *param_3)
{
  XYZ XStack_c;
  
  XYZ::XYZ(&XStack_c,*param_1 - *param_3,param_1[1] - param_3[1],param_1[2] - param_3[2]);
  *param_2 = XStack_c.xValue;
  param_2[1] = XStack_c.yValue;
  param_2[2] = XStack_c.zValue;
  return;
}

// --------------------------------------------------

// Function: FUN_0047e5cb
// Address: 0047e5cb
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0047e5cb(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,byte param_4)
{
  undefined4 uVar1;
  
  *param_3 = *param_1;
  param_3[1] = param_1[1];
  param_3[2] = param_1[2];
  if (param_4 != 0) {
    fsin((float10)param_4 * (float10)_DAT_00571ce8);
    fcos((float10)(float)((float10)param_4 * (float10)_DAT_00571ce8));
    uVar1 = __ftol();
    *param_3 = uVar1;
    uVar1 = __ftol();
    param_3[1] = uVar1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047e663
// Address: 0047e663
TListDialog * __thiscall FUN_0047e663(TListDialog *param_1,char *param_2)
{
  TListDialog::TListDialog(param_1,param_2);
  param_1->_padding_ = (int)&RGE_Dialog_List::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047e689
// Address: 0047e689
RGE_Dialog_List * __thiscall FUN_0047e689(RGE_Dialog_List *param_1,byte param_2)
{
  RGE_Dialog_List::~RGE_Dialog_List(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047e6ae
// Address: 0047e6ae
bool __thiscall
FUN_0047e6ae(RGE_Dialog_List *param_1,TPanel *param_2,char *param_3,long param_4,int param_5,
            char *param_6)
{
  char cVar1;
  int iVar2;
  char **ppcVar3;
  char *pcVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  
  param_1->list_type = param_5;
  param_1->list_info = (rdlg_list_info *)0x0;
  param_1->list_text = (char **)0x0;
  if (param_1->_padding_ != 0) {
    return false;
  }
  iVar2 = (**(code **)(param_1->_padding_ + 0x138))();
  if (iVar2 == 0) {
    return false;
  }
  RGE_Dialog_List::sort_list(param_1);
  RGE_Dialog_List::calc_list_line(param_1);
  ppcVar3 = (char **)calloc((int)param_1->list_size,4);
  param_1->list_text = ppcVar3;
  if (ppcVar3 == (char **)0x0) {
    return false;
  }
  iVar2 = 0;
  if (0 < param_1->list_size) {
    param_5 = 0;
    do {
      uVar6 = 0xffffffff;
      pcVar4 = param_1->list_info->text + param_5;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      pcVar4 = (char *)calloc(~uVar6,1);
      param_1->list_text[iVar2] = pcVar4;
      if (param_1->list_text[iVar2] == (char *)0x0) {
        return false;
      }
      uVar6 = 0xffffffff;
      pcVar4 = param_1->list_info->text + param_5;
      do {
        pcVar8 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar8 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar8;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      pcVar4 = pcVar8 + -uVar6;
      pcVar8 = param_1->list_text[iVar2];
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar8 = pcVar8 + 4;
      }
      iVar2 = iVar2 + 1;
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar8 = pcVar8 + 1;
      }
      param_5 = param_5 + 0x66;
    } while (iVar2 < param_1->list_size);
  }
  lVar5 = TListDialog::setup((TListDialog *)param_1,param_2,param_3,param_4,0x136,400,10,10,0x122,
                             0x19,param_6,10,0x2d,0x122,0x131,param_1->list_text,param_1->list_size,
                             param_1->list_line,10,0xa0,0x168,0x8c,0x1e);
  return lVar5 != 0;
}

// --------------------------------------------------

// Function: FUN_0047e828
// Address: 0047e828
void __fastcall FUN_0047e828(TListDialog *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[1]._padding_;
  param_1->_padding_ = (int)&RGE_Dialog_List::_vftable_;
  if (iVar2 != 0) {
    iVar2 = 0;
    if (0 < (short)param_1[1]._padding_) {
      do {
        iVar1 = *(int *)(param_1[1]._padding_ + iVar2 * 4);
        if (iVar1 != 0) {
          free(iVar1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (short)param_1[1]._padding_);
    }
    free(param_1[1]._padding_);
    param_1[1]._padding_ = 0;
  }
  if (param_1[1]._padding_ != 0) {
    free(param_1[1]._padding_);
    param_1[1]._padding_ = 0;
  }
  TListDialog::~TListDialog(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047e8b1
// Address: 0047e8b1
undefined2 __fastcall FUN_0047e8b1(int param_1)
{
  if (*(short *)(param_1 + 0x4a4) == -1) {
    return 0xffff;
  }
  return *(undefined2 *)(*(int *)(param_1 + 0x4b4) + 100 + *(short *)(param_1 + 0x4a4) * 0x66);
}

// --------------------------------------------------

// Function: FUN_0047e8ea
// Address: 0047e8ea
int __fastcall FUN_0047e8ea(RGE_Dialog_List *param_1)
{
  int iVar1;
  
  if (param_1->list_type != 1) {
    return 0;
  }
  iVar1 = RGE_Dialog_List::create_object_list(param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0047e901
// Address: 0047e901
// [HELPER] s__: "}"
undefined4 __fastcall FUN_0047e901(int param_1)
{
  char cVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  RGE_Player *pRVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  short sVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  
  pRVar5 = RGE_Base_Game::get_player(rge_base_game);
  if (pRVar5 == (RGE_Player *)0x0) {
    return 0;
  }
  *(undefined2 *)(param_1 + 0x4b0) = 1;
  sVar2 = pRVar5->master_object_num;
  if (0 < sVar2) {
    iVar9 = 0;
    iVar11 = (int)sVar2;
    do {
      iVar6 = *(int *)((int)pRVar5->master_objects + iVar9);
      if ((iVar6 != 0) && (*(char *)(iVar6 + 0x4e) == '\0')) {
        *(short *)(param_1 + 0x4b0) = *(short *)(param_1 + 0x4b0) + 1;
      }
      iVar9 = iVar9 + 4;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  if (*(short *)(param_1 + 0x4b0) == 0) {
    return 0;
  }
  iVar9 = calloc((int)*(short *)(param_1 + 0x4b0),0x66);
  *(int *)(param_1 + 0x4b4) = iVar9;
  if (iVar9 == 0) {
    return 0;
  }
  uVar7 = 0xffffffff;
  *(undefined2 *)(iVar9 + 100) = 0xffff;
  pcVar12 = &s__<None>_;
  do {
    pcVar13 = pcVar12;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar13 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar13;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  sVar4 = 1;
  pcVar12 = pcVar13 + -uVar7;
  pcVar13 = *(char **)(param_1 + 0x4b4);
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar13 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar13 = pcVar13 + 1;
  }
  sVar10 = 0;
  if (0 < sVar2) {
    iVar9 = 0;
    do {
      iVar11 = *(int *)((int)pRVar5->master_objects + iVar9);
      if ((iVar11 != 0) && (*(char *)(iVar11 + 0x4e) == '\0')) {
        iVar6 = sVar4 * 0x66;
        *(short *)(*(int *)(param_1 + 0x4b4) + 100 + iVar6) = sVar10;
        iVar11 = *(int *)((int)pRVar5->master_objects + iVar9);
        sVar3 = *(short *)(iVar11 + 0xc);
        if (sVar3 < 1) {
          uVar7 = 0xffffffff;
          pcVar12 = *(char **)(iVar11 + 8);
          do {
            pcVar13 = pcVar12;
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            pcVar13 = pcVar12 + 1;
            cVar1 = *pcVar12;
            pcVar12 = pcVar13;
          } while (cVar1 != '\0');
          uVar7 = ~uVar7;
          pcVar12 = pcVar13 + -uVar7;
          pcVar13 = (char *)(*(int *)(param_1 + 0x4b4) + iVar6);
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
            pcVar12 = pcVar12 + 4;
            pcVar13 = pcVar13 + 4;
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *pcVar13 = *pcVar12;
            pcVar12 = pcVar12 + 1;
            pcVar13 = pcVar13 + 1;
          }
        }
        else {
          (**(code **)(rge_base_game->_padding_ + 0x1c))
                    (2,(int)sVar3,*(int *)(param_1 + 0x4b4) + iVar6,100);
        }
        sVar4 = sVar4 + 1;
      }
      sVar10 = sVar10 + 1;
      iVar9 = iVar9 + 4;
    } while (sVar10 < sVar2);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047ea9c
// Address: 0047ea9c
uint FUN_0047ea9c(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = CompareStringA(0x400,1,param_1,0xffffffff,param_2,0xffffffff);
  if (iVar1 == 1) {
    return 0xffffffff;
  }
  return (uint)(iVar1 == 3);
}

// --------------------------------------------------

// Function: rdlg_list_compare
// Address: 0047eaa0
/* int __cdecl rdlg_list_compare(void const *,void const *) */

int __cdecl rdlg_list_compare(void *param_1,void *param_2)
{
  int iVar1;
  
  iVar1 = CompareStringA(0x400,1,param_1,0xffffffff,param_2,0xffffffff);
  if (iVar1 == 1) {
    return -1;
  }
  return (uint)(iVar1 == 3);
}

// --------------------------------------------------

// Function: FUN_0047eacf
// Address: 0047eacf
void __fastcall FUN_0047eacf(int param_1)
{
  qsort(*(undefined4 *)(param_1 + 0x4b4),(int)*(short *)(param_1 + 0x4b0),0x66,rdlg_list_compare);
  return;
}

// --------------------------------------------------

// Function: FUN_0047eaef
// Address: 0047eaef
void __fastcall FUN_0047eaef(int *param_1)
{
  short sVar1;
  short sVar2;
  
  *(undefined2 *)((int)param_1 + 0x4b2) = 0xffff;
  sVar1 = (**(code **)(*param_1 + 0x13c))();
  if (sVar1 != -1) {
    sVar2 = 0;
    if (0 < (short)param_1[300]) {
      do {
        if (*(short *)(param_1[0x12d] + 100 + sVar2 * 0x66) == sVar1) {
          *(short *)((int)param_1 + 0x4b2) = sVar2;
          break;
        }
        sVar2 = sVar2 + 1;
      } while (sVar2 < (short)param_1[300]);
    }
  }
  if (*(short *)((int)param_1 + 0x4b2) == -1) {
    *(undefined2 *)((int)param_1 + 0x4b2) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047eb5c
// Address: 0047eb5c
undefined4 __fastcall FUN_0047eb5c(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x4ac) + -1;
  if (iVar1 != 0) {
    return CONCAT22((short)((uint)iVar1 >> 0x10),0xffff);
  }
  return CONCAT22((short)((uint)rge_base_game >> 0x10),rge_base_game->master_obj_id);
}

// --------------------------------------------------

// Function: FUN_0047eb7b
// Address: 0047eb7b
undefined4 * __thiscall FUN_0047eb7b(undefined4 *param_1,undefined4 param_2)
{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 3;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  RegCreateKeyExA(0x80000001,param_2,0,0,0,0xf003f,0,param_1 + 1,puVar1);
  RegCreateKeyExA(0x80000002,param_2,0,0,0,0xf003f,0,param_1,puVar1);
  RegCreateKeyExA(0x80000002,param_2,0,0,0,1,0,param_1 + 2,puVar1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047ebfc
// Address: 0047ebfc
void __fastcall FUN_0047ebfc(int *param_1)
{
  if (param_1[1] != 0) {
    RegCloseKey(param_1[1]);
    param_1[1] = 0;
  }
  if (*param_1 != 0) {
    RegCloseKey(*param_1);
    *param_1 = 0;
  }
  if (param_1[2] != 0) {
    RegCloseKey(param_1[2]);
    param_1[2] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047ec3e
// Address: 0047ec3e
bool __thiscall
FUN_0047ec3e(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = RegSetValueExA(param_1[1],param_3,0,4,param_4,param_5);
    return iVar1 == 0;
  }
  iVar1 = RegSetValueExA(*param_1,param_3,0,4,param_4,param_5);
  return iVar1 == 0;
}

// --------------------------------------------------

// Function: FUN_0047ec99
// Address: 0047ec99
bool __thiscall FUN_0047ec99(undefined4 *param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = RegSetValueExA(param_1[1],param_3,0,4,&stack0x0000000c,4);
    return iVar1 == 0;
  }
  iVar1 = RegSetValueExA(*param_1,param_3,0,4,&stack0x0000000c,4);
  return iVar1 == 0;
}

// --------------------------------------------------

// Function: FUN_0047ecf1
// Address: 0047ecf1
bool __thiscall
FUN_0047ecf1(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = RegSetValueExA(param_1[1],param_3,0,1,param_4,param_5);
    return iVar1 == 0;
  }
  iVar1 = RegSetValueExA(*param_1,param_3,0,1,param_4,param_5);
  return iVar1 == 0;
}

// --------------------------------------------------

// Function: FUN_0047ed59
// Address: 0047ed59
uint __thiscall FUN_0047ed59(int param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 1;
  uStack_8 = 0xff;
  if (param_2 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 8);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 4);
  }
  iVar1 = RegQueryValueExA(uVar2,param_3,0,&uStack_4,param_1 + 0x10U,&uStack_8);
  return ~-(uint)(iVar1 != 0) & param_1 + 0x10U;
}

// --------------------------------------------------

// Function: FUN_0047edc2
// Address: 0047edc2
void __thiscall
FUN_0047edc2(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  if (param_2 != 0) {
    RegQueryValueExA(*(undefined4 *)(param_1 + 4),param_3,0,&param_5,param_4,param_5);
    return;
  }
  RegQueryValueExA(*(undefined4 *)(param_1 + 8),param_3,0,&param_5,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0047ee1e
// Address: 0047ee1e
undefined4 * __thiscall FUN_0047ee1e(int param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = 4;
  uStack_4 = 4;
  if (param_2 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 8);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 4);
  }
  puVar3 = &param_3;
  iVar1 = RegQueryValueExA(uVar2,param_3,0,&uStack_4,puVar3,&uStack_8);
  if (iVar1 == 0) {
    return puVar3;
  }
  return (undefined4 *)0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0047ee8b
// Address: 0047ee8b
// [HELPER] s_1_00: "1.00"
// [HELPER] s_Error__Open_Mapped_ResFile__Coul: "Error: Open_Mapped_ResFile, Could not map file(1)."
// [HELPER] s_Error__Open_ResFile__Corruption_: "Error: Open_ResFile, Corruption detected in resfile."
// [HELPER] s_Error__Open_ResFile__Resfile_not: "Error: Open_ResFile, Resfile not correct."
// [HELPER] s_Error__Open_new_ResFile__file__s: "Error: Open_new_ResFile, file %s not Found."
// [HELPER] s_Error__Open_new_ResFile__mapped_: "Error: Open_new_ResFile, mapped file %s not Found."
// [HELPER] s_Error__Out_of_memory_in_Open_res: "Error: Out of memory in Open_resfile."
// [HELPER] s_Error__Reading_resfile_header_da: "Error: Reading resfile header data."
// [HELPER] s_RESOURCE_ERROR: "RESOURCE ERROR"
// [HELPER] s__s_s: "%s%s"
void FUN_0047ee8b(char *param_1,byte *param_2,undefined4 param_3,int param_4)
{
  char cVar1;
  byte bVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int *piVar12;
  bool bVar13;
  char *pcVar14;
  undefined1 auStack_1a0 [260];
  undefined1 auStack_9c [80];
  undefined1 auStack_4c [60];
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iStack_8 = 0;
  iStack_c = -1;
  sprintf(auStack_1a0,s__s_s,param_3,param_1);
  if (param_4 == 0) {
    iVar5 = CreateFileA(auStack_1a0,0x80000000,1,0,4,0x80,0);
    if (iVar5 != -1) {
      iVar6 = CreateFileMappingA(iVar5,0,2,0,0,0);
      CloseHandle(iVar5);
      if (iVar6 == 0) {
        MessageBoxA(0,s_Error__Open_Mapped_ResFile__Coul,s_RESOURCE_ERROR,0x30);
        return;
      }
      iStack_8 = MapViewOfFile(iVar6,4,0,0,0);
      if (iStack_8 == 0) {
        MessageBoxA(0,s_Error__Open_Mapped_ResFile__Coul,s_RESOURCE_ERROR,0x30);
        return;
      }
      CloseHandle(iVar6);
LAB_0047ef6f:
      piVar7 = (int *)malloc(0x114);
      iVar5 = iStack_c;
      if (piVar7 == (int *)0x0) {
        MessageBoxA(0,s_Error__Out_of_memory_in_Open_res,s_RESOURCE_ERROR,0x30);
        return;
      }
      uVar9 = 0xffffffff;
      do {
        pcVar14 = param_1;
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        pcVar14 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar14;
      } while (cVar1 != '\0');
      uVar9 = ~uVar9;
      piVar11 = (int *)(pcVar14 + -uVar9);
      piVar12 = piVar7 + 4;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *piVar12 = *piVar11;
        piVar11 = piVar11 + 1;
        piVar12 = piVar12 + 1;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(char *)piVar12 = (char)*piVar11;
        piVar11 = (int *)((int)piVar11 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
      piVar7[3] = 0;
      if (param_4 == 0) {
        piVar7[1] = -1;
        *piVar7 = iStack_8;
        piVar7[2] = iStack_8;
        FUN_0047f076();
        return;
      }
      piVar7[1] = iStack_c;
      *piVar7 = 0;
      lseek(iStack_c,0,1);
      iVar6 = read(iVar5,auStack_4c,0x40);
      if (iVar6 != 0x40) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      iVar6 = malloc(iStack_10);
      piVar7[2] = iVar6;
      lseek(iVar5,0,0);
      iVar5 = read(iVar5,piVar7[2],iStack_10);
      if (iVar5 != iStack_10) {
        MessageBoxA(0,s_Error__Reading_resfile_header_da,s_RESOURCE_ERROR,0x30);
        return;
      }
      piVar11 = piVar7;
      if (DAT_0086b254 != (int *)0x0) {
        piVar12 = (int *)DAT_0086b254[3];
        piVar11 = DAT_0086b254;
        while (piVar4 = piVar12, piVar4 != (int *)0x0) {
          piVar11 = piVar4;
          piVar12 = (int *)piVar4[3];
        }
        piVar11[3] = (int)piVar7;
        piVar11 = DAT_0086b254;
      }
      DAT_0086b254 = piVar11;
      pbVar8 = (byte *)(piVar7[2] + 0x2c);
      do {
        bVar2 = *pbVar8;
        bVar13 = bVar2 < *param_2;
        if (bVar2 != *param_2) {
LAB_0047f0cc:
          iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          goto LAB_0047f0d1;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar8[1];
        bVar13 = bVar2 < param_2[1];
        if (bVar2 != param_2[1]) goto LAB_0047f0cc;
        pbVar8 = pbVar8 + 2;
        param_2 = param_2 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_0047f0d1:
      if (iVar5 != 0) {
        MessageBoxA(0,s_Error__Open_ResFile__Corruption_,s_RESOURCE_ERROR,0x30);
        return;
      }
      iVar5 = strncmp(piVar7[2] + 0x28,s_1_00,4);
      if (iVar5 != 0) {
        MessageBoxA(0,s_Error__Open_ResFile__Resfile_not,s_RESOURCE_ERROR,0x30);
      }
      return;
    }
    pcVar14 = s_Error__Open_new_ResFile__mapped_;
  }
  else {
    iStack_c = __open(auStack_1a0,0x8000);
    if (iStack_c != -1) goto LAB_0047ef6f;
    pcVar14 = s_Error__Open_new_ResFile__file__s;
    iStack_c = -1;
  }
  sprintf(auStack_9c,pcVar14,param_1);
  MessageBoxA(0,auStack_9c,s_RESOURCE_ERROR,0x30);
  return;
}

// --------------------------------------------------

// Function: RESFILE_open_new_resource_file
// Address: 0047ee90
// [HELPER] s_1_00: "1.00"
// [HELPER] s_Error__Open_Mapped_ResFile__Coul: "Error: Open_Mapped_ResFile, Could not map file(1)."
// [HELPER] s_Error__Open_ResFile__Corruption_: "Error: Open_ResFile, Corruption detected in resfile."
// [HELPER] s_Error__Open_ResFile__Resfile_not: "Error: Open_ResFile, Resfile not correct."
// [HELPER] s_Error__Open_new_ResFile__file__s: "Error: Open_new_ResFile, file %s not Found."
// [HELPER] s_Error__Open_new_ResFile__mapped_: "Error: Open_new_ResFile, mapped file %s not Found."
// [HELPER] s_Error__Out_of_memory_in_Open_res: "Error: Out of memory in Open_resfile."
// [HELPER] s_Error__Reading_resfile_header_da: "Error: Reading resfile header data."
// [HELPER] s_RESOURCE_ERROR: "RESOURCE ERROR"
// [HELPER] s__s_s: "%s%s"
/* void __cdecl RESFILE_open_new_resource_file(char *,char *,char *,int) */

void __cdecl RESFILE_open_new_resource_file(char *param_1,char *param_2,char *param_3,int param_4)
{
  char cVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  bool bVar15;
  char *pcVar16;
  char resFile [260];
  char error_msg [80];
  resfile_header rHeader;
  int fHandle;
  uchar *mapped_file_data;
  
  mapped_file_data = (uchar *)0x0;
  fHandle = -1;
  sprintf(resFile,s__s_s,param_3,param_1);
  if (param_4 == 0) {
                    /* language.dll match for 0x80: "Arial" */
    iVar7 = CreateFileA(resFile,0x80000000,1,0,4,0x80,0);
    if (iVar7 != -1) {
      iVar8 = CreateFileMappingA(iVar7,0,2,0,0,0);
      CloseHandle(iVar7);
      if (iVar8 == 0) {
        MessageBoxA(0,s_Error__Open_Mapped_ResFile__Coul,s_RESOURCE_ERROR,0x30);
        return;
      }
      mapped_file_data = (uchar *)MapViewOfFile(iVar8,4,0,0,0);
      if (mapped_file_data == (uchar *)0x0) {
        MessageBoxA(0,s_Error__Open_Mapped_ResFile__Coul,s_RESOURCE_ERROR,0x30);
        return;
      }
      CloseHandle(iVar8);
LAB_0047ef6f:
      puVar9 = (undefined4 *)malloc(0x114);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA(0,s_Error__Out_of_memory_in_Open_res,s_RESOURCE_ERROR,0x30);
        return;
      }
      uVar12 = 0xffffffff;
      do {
        pcVar16 = param_1;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar16 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar16;
      } while (cVar1 != '\0');
      uVar12 = ~uVar12;
      pcVar16 = pcVar16 + -uVar12;
      pcVar14 = (char *)(puVar9 + 4);
      for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)pcVar16;
        pcVar16 = pcVar16 + 4;
        pcVar14 = pcVar14 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar14 = *pcVar16;
        pcVar16 = pcVar16 + 1;
        pcVar14 = pcVar14 + 1;
      }
      puVar9[3] = 0;
      if (param_4 == 0) {
        puVar9[1] = 0xffffffff;
        *puVar9 = mapped_file_data;
        puVar9[2] = mapped_file_data;
        FUN_0047f076();
        return;
      }
      puVar9[1] = fHandle;
      *puVar9 = 0;
      lseek(fHandle,0,1);
      iVar7 = read(fHandle,&rHeader,0x40);
      if (iVar7 != 0x40) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      uVar10 = malloc(rHeader.directory_size);
      puVar9[2] = uVar10;
      lseek(fHandle,0,0);
      iVar7 = read(fHandle,puVar9[2],rHeader.directory_size);
      if (iVar7 != rHeader.directory_size) {
        MessageBoxA(0,s_Error__Reading_resfile_header_da,s_RESOURCE_ERROR,0x30);
        return;
      }
      puVar5 = puVar9;
      if (DAT_0086b254 != (undefined4 *)0x0) {
        puVar6 = (undefined4 *)DAT_0086b254[3];
        puVar5 = DAT_0086b254;
        while (puVar4 = puVar6, puVar4 != (undefined4 *)0x0) {
          puVar5 = puVar4;
          puVar6 = (undefined4 *)puVar4[3];
        }
        puVar5[3] = puVar9;
        puVar5 = DAT_0086b254;
      }
      DAT_0086b254 = puVar5;
      pbVar11 = (byte *)(puVar9[2] + 0x2c);
      do {
        bVar2 = *pbVar11;
        bVar15 = bVar2 < (byte)*param_2;
        if (bVar2 != *param_2) {
LAB_0047f0cc:
          iVar7 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
          goto LAB_0047f0d1;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar11[1];
        bVar15 = bVar2 < ((byte *)param_2)[1];
        if (bVar2 != ((byte *)param_2)[1]) goto LAB_0047f0cc;
        pbVar11 = pbVar11 + 2;
        param_2 = (char *)((byte *)param_2 + 2);
      } while (bVar2 != 0);
      iVar7 = 0;
LAB_0047f0d1:
      if (iVar7 != 0) {
        MessageBoxA(0,s_Error__Open_ResFile__Corruption_,s_RESOURCE_ERROR,0x30);
        return;
      }
      iVar7 = strncmp(puVar9[2] + 0x28,s_1_00,4);
      if (iVar7 != 0) {
        MessageBoxA(0,s_Error__Open_ResFile__Resfile_not,s_RESOURCE_ERROR,0x30);
      }
      return;
    }
    pcVar16 = s_Error__Open_new_ResFile__mapped_;
  }
  else {
    fHandle = __open(resFile,0x8000);
    if (fHandle != -1) goto LAB_0047ef6f;
    pcVar16 = s_Error__Open_new_ResFile__file__s;
  }
  sprintf(error_msg,pcVar16,param_1);
  MessageBoxA(0,error_msg,s_RESOURCE_ERROR,0x30);
  return;
}

// --------------------------------------------------

// Function: FUN_0047f00c
// Address: 0047f00c
// [HELPER] s_Error__Reading_resfile_header_: "Error: Reading resfile header."
// [HELPER] s_RESOURCE_ERROR: "RESOURCE ERROR"
void FUN_0047f00c(void)
{
  MessageBoxA(0,s_Error__Reading_resfile_header_,s_RESOURCE_ERROR,0x30);
  return;
}

// --------------------------------------------------

// Function: FUN_0047f076
// Address: 0047f076
// [HELPER] s_1_00: "1.00"
// [HELPER] s_Error__Open_ResFile__Corruption_: "Error: Open_ResFile, Corruption detected in resfile."
// [HELPER] s_Error__Open_ResFile__Resfile_not: "Error: Open_ResFile, Resfile not correct."
// [HELPER] s_RESOURCE_ERROR: "RESOURCE ERROR"
void FUN_0047f076(void)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int unaff_EBX;
  int unaff_EBP;
  byte *pbVar6;
  bool bVar7;
  
  iVar5 = unaff_EBX;
  if (DAT_0086b254 != 0) {
    iVar3 = *(int *)(DAT_0086b254 + 0xc);
    iVar5 = DAT_0086b254;
    while (iVar2 = iVar3, iVar2 != 0) {
      iVar5 = iVar2;
      iVar3 = *(int *)(iVar2 + 0xc);
    }
    *(int *)(iVar5 + 0xc) = unaff_EBX;
    iVar5 = DAT_0086b254;
  }
  DAT_0086b254 = iVar5;
  pbVar6 = *(byte **)(unaff_EBP + 0xc);
  pbVar4 = (byte *)(*(int *)(unaff_EBX + 8) + 0x2c);
  do {
    bVar1 = *pbVar4;
    bVar7 = bVar1 < *pbVar6;
    if (bVar1 != *pbVar6) {
LAB_0047f0cc:
      iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_0047f0d1;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar4[1];
    bVar7 = bVar1 < pbVar6[1];
    if (bVar1 != pbVar6[1]) goto LAB_0047f0cc;
    pbVar4 = pbVar4 + 2;
    pbVar6 = pbVar6 + 2;
  } while (bVar1 != 0);
  iVar5 = 0;
LAB_0047f0d1:
  if (iVar5 != 0) {
    MessageBoxA(0,s_Error__Open_ResFile__Corruption_,s_RESOURCE_ERROR,0x30);
    return;
  }
  iVar5 = strncmp(*(int *)(unaff_EBX + 8) + 0x28,s_1_00,4);
  if (iVar5 != 0) {
    MessageBoxA(0,s_Error__Open_ResFile__Resfile_not,s_RESOURCE_ERROR,0x30);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047f174
// Address: 0047f174
void FUN_0047f174(byte *param_1)
{
  int *piVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  int *piVar7;
  bool bVar8;
  
  piVar5 = (int *)0x0;
  piVar7 = DAT_0086b254;
  if (DAT_0086b254 == (int *)0x0) {
    return;
  }
  do {
    pbVar6 = (byte *)(piVar7 + 4);
    pbVar3 = param_1;
    do {
      bVar2 = *pbVar3;
      bVar8 = bVar2 < *pbVar6;
      if (bVar2 != *pbVar6) {
LAB_0047f1c1:
        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0047f1c6;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar8 = bVar2 < pbVar6[1];
      if (bVar2 != pbVar6[1]) goto LAB_0047f1c1;
      pbVar3 = pbVar3 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_0047f1c6:
    if (iVar4 == 0) {
      if (*piVar7 == 0) {
        free(piVar7[2]);
      }
      if (piVar5 == (int *)0x0) {
        DAT_0086b254 = (int *)piVar7[3];
      }
      else {
        piVar5[3] = piVar7[3];
      }
      if (piVar7[1] != -1) {
        close(piVar7[1]);
      }
      if (*piVar7 != 0) {
        UnmapViewOfFile(*piVar7);
      }
      free(piVar7);
      return;
    }
    piVar1 = piVar7 + 3;
    piVar5 = piVar7;
    piVar7 = (int *)*piVar1;
    if ((int *)*piVar1 == (int *)0x0) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: RESFILE_close_new_resource_file
// Address: 0047f180
/* void __cdecl RESFILE_close_new_resource_file(char *) */

void __cdecl RESFILE_close_new_resource_file(char *param_1)
{
  int *piVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  int *piVar7;
  bool bVar8;
  
  piVar5 = (int *)0x0;
  piVar7 = DAT_0086b254;
  if (DAT_0086b254 == (int *)0x0) {
    return;
  }
  do {
    pbVar6 = (byte *)(piVar7 + 4);
    pbVar3 = (byte *)param_1;
    do {
      bVar2 = *pbVar3;
      bVar8 = bVar2 < *pbVar6;
      if (bVar2 != *pbVar6) {
LAB_0047f1c1:
        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0047f1c6;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar8 = bVar2 < pbVar6[1];
      if (bVar2 != pbVar6[1]) goto LAB_0047f1c1;
      pbVar3 = pbVar3 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_0047f1c6:
    if (iVar4 == 0) {
      if (*piVar7 == 0) {
        free(piVar7[2]);
      }
      if (piVar5 == (int *)0x0) {
        DAT_0086b254 = (int *)piVar7[3];
      }
      else {
        piVar5[3] = piVar7[3];
      }
      if (piVar7[1] != -1) {
        close(piVar7[1]);
      }
      if (*piVar7 != 0) {
        UnmapViewOfFile(*piVar7);
      }
      free(piVar7);
      return;
    }
    piVar1 = piVar7 + 3;
    piVar5 = piVar7;
    piVar7 = (int *)*piVar1;
    if ((int *)*piVar1 == (int *)0x0) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0047f22a
// Address: 0047f22a
undefined4
FUN_0047f22a(int param_1,int param_2,undefined4 *param_3,int *param_4,undefined4 *param_5,
            int *param_6)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puStack_4;
  
  iVar2 = param_2;
  puStack_4 = DAT_0086b254;
  *param_3 = 0xffffffff;
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 0;
  if (puStack_4 == (undefined4 *)0x0) {
    return 0;
  }
  do {
    iVar1 = puStack_4[2];
    param_2 = 0;
    if (0 < *(int *)(iVar1 + 0x38)) {
      piVar6 = (int *)(iVar1 + 0x48);
      do {
        if (piVar6[-2] == param_1) {
          piVar4 = (int *)(piVar6[-1] + iVar1);
          iVar3 = 0;
          piVar5 = piVar4;
          if (0 < *piVar6) {
            do {
              if (*piVar5 == iVar2) {
                *param_3 = puStack_4[1];
                *param_4 = piVar4[iVar3 * 3 + 1];
                *param_5 = *puStack_4;
                *param_6 = piVar4[iVar3 * 3 + 2];
                return 1;
              }
              iVar3 = iVar3 + 1;
              piVar5 = piVar5 + 3;
            } while (iVar3 < *piVar6);
          }
        }
        param_2 = param_2 + 1;
        piVar6 = piVar6 + 3;
      } while (param_2 < *(int *)(iVar1 + 0x38));
    }
    puStack_4 = (undefined4 *)puStack_4[3];
  } while (puStack_4 != (undefined4 *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: RESFILE_locate_resource
// Address: 0047f230
/* WARNING: Variable defined which should be unmapped: p */
/* int __cdecl RESFILE_locate_resource(unsigned long,unsigned long,int &,int &,unsigned char * &,int
   &) */

int __cdecl
RESFILE_locate_resource
          (ulong param_1,ulong param_2,int *param_3,int *param_4,uchar **param_5,int *param_6)
{
  int iVar1;
  ulong uVar2;
  int iVar3;
  ulong *puVar4;
  ulong *puVar5;
  int *piVar6;
  ResFileHdr *p;
  undefined4 *local_4;
  
  uVar2 = param_2;
  local_4 = DAT_0086b254;
  *param_3 = -1;
  *param_4 = 0;
  *param_5 = (uchar *)0x0;
  *param_6 = 0;
  if (local_4 == (undefined4 *)0x0) {
    return 0;
  }
  do {
    iVar1 = local_4[2];
    param_2 = 0;
    if (0 < *(int *)(iVar1 + 0x38)) {
      piVar6 = (int *)(iVar1 + 0x48);
      do {
        if (piVar6[-2] == param_1) {
          puVar4 = (ulong *)(piVar6[-1] + iVar1);
          iVar3 = 0;
          puVar5 = puVar4;
          if (0 < *piVar6) {
            do {
              if (*puVar5 == uVar2) {
                *param_3 = local_4[1];
                *param_4 = puVar4[iVar3 * 3 + 1];
                *param_5 = (uchar *)*local_4;
                *param_6 = puVar4[iVar3 * 3 + 2];
                return 1;
              }
              iVar3 = iVar3 + 1;
              puVar5 = puVar5 + 3;
            } while (iVar3 < *piVar6);
          }
        }
        param_2 = param_2 + 1;
        piVar6 = piVar6 + 3;
      } while ((int)param_2 < *(int *)(iVar1 + 0x38));
    }
    local_4 = (undefined4 *)local_4[3];
  } while (local_4 != (undefined4 *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047f318
// Address: 0047f318
// [HELPER] s_ERROR__res_read_bin__resource_ty: "ERROR: res_read_bin, resource type %4.4c , id %d, not found"
// [HELPER] s_Error__Out_of_memory_in_res_read: "Error: Out of memory in res_read_bin."
// [HELPER] s_Error__unable_to_read_resource: "Error: unable to read resource"
// [HELPER] s_RESOURCE_ERROR: "RESOURCE ERROR"
int FUN_0047f318(uchar *param_1,ulong param_2,undefined4 *param_3,undefined4 *param_4)
{
  uchar *puVar1;
  ulong uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 auStack_64 [100];
  
  puVar3 = param_4;
  puVar5 = param_3;
  uVar2 = param_2;
  puVar1 = param_1;
  *param_3 = 0xffffffff;
  *param_4 = 0;
  iVar4 = RESFILE_locate_resource
                    ((ulong)param_1,param_2,(int *)&param_2,(int *)&param_4,&param_1,(int *)&param_3
                    );
  if (iVar4 == 0) {
    if (DAT_0086b258 != 0) {
      sprintf(auStack_64,s_ERROR__res_read_bin__resource_ty,puVar1,uVar2);
      MessageBoxA(0,auStack_64,s_RESOURCE_ERROR,0x30);
      return 0;
    }
  }
  else {
    if (param_1 != (uchar *)0x0) {
      *puVar5 = 0;
      *puVar3 = param_3;
      return (int)(uchar *)((int)param_4 + (int)param_1);
    }
    *puVar5 = 1;
    iVar4 = malloc(param_3);
    *puVar3 = param_3;
    if (iVar4 == 0) {
      MessageBoxA(0,s_Error__Out_of_memory_in_res_read,s_RESOURCE_ERROR,0x30);
      return 0;
    }
    lseek(param_2,param_4,0);
    puVar5 = (undefined4 *)read(param_2,iVar4,param_3);
    if (puVar5 == param_3) {
      return iVar4;
    }
    MessageBoxA(0,s_Error__unable_to_read_resource,s_RESOURCE_ERROR,0x30);
  }
  return 0;
}

// --------------------------------------------------

// Function: RESFILE_load
// Address: 0047f320
// [HELPER] s_ERROR__res_read_bin__resource_ty: "ERROR: res_read_bin, resource type %4.4c , id %d, not found"
// [HELPER] s_Error__Out_of_memory_in_res_read: "Error: Out of memory in res_read_bin."
// [HELPER] s_Error__unable_to_read_resource: "Error: unable to read resource"
// [HELPER] s_RESOURCE_ERROR: "RESOURCE ERROR"
/* WARNING: Variable defined which should be unmapped: error_string */
/* unsigned char * __cdecl RESFILE_load(unsigned long,unsigned long,int &,int &) */

uchar * __cdecl RESFILE_load(ulong param_1,ulong param_2,int *param_3,int *param_4)
{
  ulong uVar1;
  ulong uVar2;
  int *piVar3;
  int iVar4;
  uchar *puVar5;
  int *piVar6;
  char error_string [100];
  
  piVar3 = param_4;
  piVar6 = param_3;
  uVar2 = param_2;
  uVar1 = param_1;
  *param_3 = -1;
  *param_4 = 0;
  iVar4 = RESFILE_locate_resource
                    (param_1,param_2,(int *)&param_2,(int *)&param_4,(uchar **)&param_1,
                     (int *)&param_3);
  if (iVar4 == 0) {
    if (DAT_0086b258 != 0) {
      sprintf(error_string + 4,s_ERROR__res_read_bin__resource_ty,uVar1,uVar2);
      MessageBoxA(0,error_string + 4,s_RESOURCE_ERROR,0x30);
      return (uchar *)0x0;
    }
  }
  else {
    if (param_1 != 0) {
      *piVar6 = 0;
      *piVar3 = (int)param_3;
      return (uchar *)((int)param_4 + param_1);
    }
    *piVar6 = 1;
    puVar5 = (uchar *)malloc(param_3);
    *piVar3 = (int)param_3;
    if (puVar5 == (uchar *)0x0) {
      MessageBoxA(0,s_Error__Out_of_memory_in_res_read,s_RESOURCE_ERROR,0x30);
      return (uchar *)0x0;
    }
    lseek(param_2,param_4,0);
    piVar6 = (int *)read(param_2,puVar5,param_3);
    if (piVar6 == param_3) {
      return puVar5;
    }
    MessageBoxA(0,s_Error__unable_to_read_resource,s_RESOURCE_ERROR,0x30);
  }
  return (uchar *)0x0;
}

// --------------------------------------------------

// Function: FUN_0047f47a
// Address: 0047f47a
// [HELPER] s__: "}"
// [HELPER] s_temp: "temp"
// [HELPER] s_w_: "w+"
bool FUN_0047f47a(ulong param_1,ulong param_2,undefined4 param_3,int *param_4)
{
  char cVar1;
  uchar *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  char *pcVar8;
  int *piVar9;
  int iVar10;
  undefined1 *puVar11;
  int aiStack_10c [2];
  undefined1 auStack_104 [260];
  
  *param_4 = 0;
  puVar2 = RESFILE_load(param_1,param_2,aiStack_10c,aiStack_10c + 1);
  if (puVar2 == (uchar *)0x0) {
    return false;
  }
  puVar11 = auStack_104;
  iVar10 = 0x104;
  iVar3 = GetTempPathA();
  if (iVar3 == 0) {
    uVar4 = 0xffffffff;
    pcVar7 = &s__;
    do {
      pcVar8 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    piVar6 = (int *)(pcVar8 + -uVar4);
    piVar9 = aiStack_10c;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar9 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar9 = piVar9 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar9 = (char)*piVar6;
      piVar6 = (int *)((int)piVar6 + 1);
      piVar9 = (int *)((int)piVar9 + 1);
    }
  }
  iVar3 = GetTempFileNameA(aiStack_10c,s_temp,0,param_1);
  if (iVar3 != 0) {
    iVar3 = fopen(param_1,s_w_);
    *param_4 = iVar3;
    if ((iVar3 != 0) && (0 < (int)puVar11)) {
      fwrite(puVar2,puVar11,1,iVar3);
      fseek(*param_4,0,0);
    }
  }
  if (iVar10 == 1) {
    free(puVar2);
  }
  return *param_4 != 0;
}

// --------------------------------------------------

// Function: RESFILE_Extract_to_File
// Address: 0047f480
// [HELPER] s__: "}"
// [HELPER] s_temp: "temp"
// [HELPER] s_w_: "w+"
/* WARNING: Variable defined which should be unmapped: rLoadType */
/* int __cdecl RESFILE_Extract_to_File(unsigned long,unsigned long,char *,struct _iobuf * &) */

int __cdecl RESFILE_Extract_to_File(ulong param_1,ulong param_2,char *param_3,_iobuf **param_4)
{
  char cVar1;
  uchar *puVar2;
  int iVar3;
  _iobuf *p_Var4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  char *pcVar8;
  char *pcVar9;
  int *piVar10;
  int iVar11;
  char *pcVar12;
  int rLoadType;
  int rDataSize;
  char temp_path [260];
  
  *param_4 = (_iobuf *)0x0;
  puVar2 = RESFILE_load(param_1,param_2,&rDataSize,(int *)temp_path);
  if (puVar2 == (uchar *)0x0) {
    return 0;
  }
  pcVar12 = temp_path + 4;
  iVar11 = 0x104;
  iVar3 = GetTempPathA();
  if (iVar3 == 0) {
    uVar5 = 0xffffffff;
    pcVar8 = &s__;
    do {
      pcVar9 = pcVar8;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar9 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar9;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    piVar7 = (int *)(pcVar9 + -uVar5);
    piVar10 = &rDataSize;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *piVar10 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar10 = piVar10 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(char *)piVar10 = (char)*piVar7;
      piVar7 = (int *)((int)piVar7 + 1);
      piVar10 = (int *)((int)piVar10 + 1);
    }
  }
  iVar3 = GetTempFileNameA(&rDataSize,s_temp,0,param_1);
  if (iVar3 != 0) {
    p_Var4 = (_iobuf *)fopen(param_1,s_w_);
    *param_4 = p_Var4;
    if ((p_Var4 != (_iobuf *)0x0) && (0 < (int)pcVar12)) {
      fwrite(puVar2,pcVar12,1,p_Var4);
      fseek(*param_4,0,0);
    }
  }
  if (iVar11 == 1) {
    free(puVar2);
  }
  return (uint)(*param_4 != (_iobuf *)0x0);
}

// --------------------------------------------------

// Function: FUN_0047f577
// Address: 0047f577
void FUN_0047f577(undefined4 param_1)
{
  DAT_0086b258 = param_1;
  return;
}

// --------------------------------------------------

// Function: RESFILE_Set_Missing_Flag
// Address: 0047f580
/* void __cdecl RESFILE_Set_Missing_Flag(int) */

void __cdecl RESFILE_Set_Missing_Flag(int param_1)
{
  DAT_0086b258 = param_1;
  return;
}

// --------------------------------------------------

// Function: FUN_0047f58a
// Address: 0047f58a
undefined4 FUN_0047f58a(int param_1,int param_2)
{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (0 < param_2)) {
    uVar1 = VirtualFree(param_1,param_2,0x4000);
    return uVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: RESFILE_Decommit_Mapped_Memory
// Address: 0047f590
/* int __cdecl RESFILE_Decommit_Mapped_Memory(unsigned char *,int) */

int __cdecl RESFILE_Decommit_Mapped_Memory(uchar *param_1,int param_2)
{
  int iVar1;
  
  if ((param_1 != (uchar *)0x0) && (0 < param_2)) {
    iVar1 = VirtualFree(param_1,param_2,0x4000);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047f5b1
// Address: 0047f5b1
// [HELPER] header_message: "79706f43"
// [HELPER] s_1_00: "1.00"
// [HELPER] s_Error__could_not_determine_file_: "Error: could not determine file type of: %s"
// [HELPER] s_Error__could_not_find_resource_b: "Error: could not find resource build file: %s"
// [HELPER] s_Error__duplicate_resources___s__: "Error: duplicate resources: %s & %s"
// [HELPER] s_Error__error_reading_file___s: "Error: error reading file: %s"
// [HELPER] s_Error__file_is_empty_NULL___s: "Error: file is empty/NULL: %s"
// [HELPER] s_Error__out_of_memory__1: "Error: out of memory #1"
// [HELPER] s_Error__out_of_memory__2: "Error: out of memory #2"
// [HELPER] s_Error__out_of_memory__3: "Error: out of memory #3"
// [HELPER] s_Error__unable_to_create_resource: "Error: unable to create resource file file: %s"
// [HELPER] s_Error__unable_to_open_file___s: "Error: unable to open file: %s"
// [HELPER] s_Error_writing_resource_file__pos: "Error writing resource file: pos out of sync 1"
// [HELPER] s_Error_writing_resource_file_data: "Error writing resource file data: pos out of sync 2"
// [HELPER] s_Error_writing_resource_file_head: "Error writing resource file header"
// [HELPER] s__d: "%d"
// [HELPER] s__s: "%s"
// [HELPER] s__s__s: "%s\n%s"
// [HELPER] s__s_s: "%s%s"
// [HELPER] s_r: "r"
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0047f5b1(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  uint *puVar8;
  uint *puVar9;
  int iVar10;
  TDebuggingLog *this;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *extraout_ECX_00;
  uint uVar11;
  uint uVar12;
  TDebuggingLog *this_00;
  TDebuggingLog *extraout_ECX_01;
  uint uVar13;
  TDebuggingLog *extraout_ECX_02;
  TDebuggingLog *extraout_ECX_03;
  TDebuggingLog *extraout_ECX_04;
  TDebuggingLog *extraout_ECX_05;
  TDebuggingLog *pTVar14;
  int *piVar15;
  int *piVar16;
  uint *puVar17;
  uint *puVar18;
  char **ppcVar19;
  char **ppcVar20;
  char *pcVar21;
  char *pcVar22;
  uint *puStack_4a4;
  uint *puStack_4a0;
  int iStack_498;
  uint uStack_494;
  undefined4 uStack_490;
  undefined4 uStack_48c;
  undefined4 uStack_488;
  uint uStack_484;
  uint uStack_480;
  uint uStack_47c;
  char acStack_478 [40];
  int aiStack_450 [5];
  uint uStack_43c;
  char acStack_438 [40];
  char acStack_410 [260];
  char acStack_30c [260];
  undefined1 auStack_208 [260];
  undefined1 auStack_104 [260];
  
  puStack_4a4 = (uint *)0x0;
  iStack_498 = 0;
  sprintf(auStack_104,s__s_s,param_2,param_1);
  iVar5 = fopen(auStack_104,s_r);
  if (iVar5 == 0) {
    TDebuggingLog::Log(this,(char *)L,s_Error__could_not_find_resource_b,param_1);
    return 0;
  }
  fscanf(iVar5,s__s__s,acStack_30c,acStack_438);
  sprintf(auStack_208,s__s_s,param_3,acStack_30c);
  while ((iVar6 = fscanf(iVar5,s__s,acStack_30c), iVar6 != -1 &&
         (iVar6 = fscanf(iVar5,&s__d,&uStack_494), iVar6 != -1))) {
    sprintf(acStack_410,s__s_s,param_2,acStack_30c);
    uVar7 = BUILDRES_get_files_resource_type(acStack_30c);
    if (uVar7 == 0) {
      TDebuggingLog::Log(L,(char *)L,s_Error__could_not_determine_file_,acStack_30c);
      return 0;
    }
    puVar17 = (uint *)0x0;
    for (puVar9 = puStack_4a4;
        (puVar8 = (uint *)0x0, puVar9 != (uint *)0x0 && (puVar8 = puVar9, *puVar9 != uVar7));
        puVar9 = (uint *)puVar9[4]) {
      if (*puVar9 < uVar7) {
        puVar17 = puVar9;
      }
    }
    if (puVar8 == (uint *)0x0) {
      puVar8 = (uint *)operator_new(0x14);
      if (puVar8 == (uint *)0x0) {
        pcVar22 = s_Error__out_of_memory__1;
        pTVar14 = extraout_ECX;
        goto LAB_0047fba1;
      }
      *puVar8 = uVar7;
      puVar8[1] = 0;
      puVar8[2] = 0;
      puVar8[3] = 0;
      puVar8[4] = 0;
      if (puVar17 == (uint *)0x0) {
        puVar8[4] = (uint)puStack_4a4;
        puStack_4a4 = puVar8;
      }
      else {
        puVar8[4] = puVar17[4];
        puVar17[4] = (uint)puVar8;
      }
      iStack_498 = iStack_498 + 1;
    }
    puVar9 = (uint *)puVar8[3];
    puStack_4a0 = (uint *)0x0;
    for (; puVar9 != (uint *)0x0; puVar9 = (uint *)puVar9[4]) {
      if (*puVar9 == uStack_494) {
        TDebuggingLog::Log((TDebuggingLog *)acStack_410,(char *)L,s_Error__duplicate_resources___s__
                           ,puVar9 + 5,(TDebuggingLog *)acStack_410);
        return 0;
      }
      if (*puVar9 < uStack_494) {
        puStack_4a0 = puVar9;
      }
    }
    puVar9 = (uint *)operator_new(0x118);
    if (puVar9 == (uint *)0x0) {
      pcVar22 = s_Error__out_of_memory__2;
      pTVar14 = extraout_ECX_00;
      goto LAB_0047fbc2;
    }
    *puVar9 = uStack_494;
    uVar11 = 0xffffffff;
    puVar9[1] = 0;
    puVar9[2] = 0;
    puVar9[3] = 0;
    puVar9[4] = 0;
    pcVar22 = acStack_410;
    do {
      pcVar21 = pcVar22;
      if (uVar11 == 0) break;
      uVar11 = uVar11 - 1;
      pcVar21 = pcVar22 + 1;
      cVar1 = *pcVar22;
      pcVar22 = pcVar21;
    } while (cVar1 != '\0');
    uVar11 = ~uVar11;
    puVar17 = (uint *)(pcVar21 + -uVar11);
    puVar18 = puVar9 + 5;
    for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *puVar18 = *puVar17;
      puVar17 = puVar17 + 1;
      puVar18 = puVar18 + 1;
    }
    for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(char *)puVar18 = (char)*puVar17;
      puVar17 = (uint *)((int)puVar17 + 1);
      puVar18 = (uint *)((int)puVar18 + 1);
    }
    iVar6 = __open(acStack_410,0x8000);
    if (iVar6 == -1) {
      TDebuggingLog::Log(this_00,(char *)L,s_Error__unable_to_open_file___s,acStack_410);
      operator_delete(puVar9);
    }
    else {
      if (puStack_4a0 == (uint *)0x0) {
        puVar9[4] = puVar8[3];
        puVar8[3] = (uint)puVar9;
      }
      else {
        puVar9[4] = puStack_4a0[4];
        puStack_4a0[4] = (uint)puVar9;
      }
      puVar8[2] = puVar8[2] + 1;
      uVar11 = lseek(iVar6,0,2);
      lseek(iVar6,0,0);
      if ((int)uVar11 < 1) {
        pTVar14 = (TDebuggingLog *)acStack_410;
        pcVar22 = s_Error__file_is_empty_NULL___s;
        goto LAB_0047f96c;
      }
      uVar12 = malloc(uVar11);
      puVar9[2] = uVar12;
      if (uVar12 == 0) {
        pcVar22 = s_Error__out_of_memory__3;
        pTVar14 = extraout_ECX_01;
        goto LAB_0047fbc2;
      }
      puVar9[3] = uVar11;
      uVar12 = read(iVar6,uVar12,uVar11);
      if (uVar12 != uVar11) {
        pTVar14 = (TDebuggingLog *)acStack_410;
        pcVar22 = s_Error__error_reading_file___s;
        goto LAB_0047f96c;
      }
      close(iVar6);
    }
  }
  fclose(iVar5);
  iVar5 = __open(auStack_208,0x8301,0x180);
  if (iVar5 == -1) {
    pTVar14 = (TDebuggingLog *)auStack_208;
    pcVar22 = s_Error__unable_to_create_resource;
LAB_0047f96c:
    TDebuggingLog::Log(pTVar14,(char *)L,pcVar22,pTVar14);
    return 0;
  }
  uVar11 = iStack_498 * 0xc + 0x40;
  for (puVar9 = puStack_4a4; uVar12 = uVar11, puVar17 = puStack_4a4, puVar9 != (uint *)0x0;
      puVar9 = (uint *)puVar9[4]) {
    puVar9[1] = uVar11;
    uVar11 = uVar11 + puVar9[2] * 0xc;
  }
  for (; puVar17 != (uint *)0x0; puVar17 = (uint *)puVar17[4]) {
    for (uVar13 = puVar17[3]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
      *(uint *)(uVar13 + 4) = uVar12;
      uVar12 = uVar12 + *(int *)(uVar13 + 0xc);
    }
  }
  pcVar22 = acStack_478;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    pcVar22[0] = '\0';
    pcVar22[1] = '\0';
    pcVar22[2] = '\0';
    pcVar22[3] = '\0';
    pcVar22 = pcVar22 + 4;
  }
  uVar12 = 0xffffffff;
  ppcVar19 = &header_message;
  do {
    ppcVar20 = ppcVar19;
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    ppcVar20 = (char **)((int)ppcVar19 + 1);
    cVar1 = *(char *)ppcVar19;
    ppcVar19 = ppcVar20;
  } while (cVar1 != '\0');
  uVar12 = ~uVar12;
  pcVar22 = (char *)((int)ppcVar20 - uVar12);
  pcVar21 = acStack_478;
  for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *(undefined4 *)pcVar21 = *(undefined4 *)pcVar22;
    pcVar22 = pcVar22 + 4;
    pcVar21 = pcVar21 + 4;
  }
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *pcVar21 = *pcVar22;
    pcVar22 = pcVar22 + 1;
    pcVar21 = pcVar21 + 1;
  }
  uVar12 = 0xffffffff;
  pcVar22 = s_1_00;
  do {
    pcVar21 = pcVar22;
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    pcVar21 = pcVar22 + 1;
    cVar1 = *pcVar22;
    pcVar22 = pcVar21;
  } while (cVar1 != '\0');
  uVar12 = ~uVar12;
  piVar15 = (int *)(pcVar21 + -uVar12);
  piVar16 = aiStack_450;
  for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *piVar16 = *piVar15;
    piVar15 = piVar15 + 1;
    piVar16 = piVar16 + 1;
  }
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(char *)piVar16 = (char)*piVar15;
    piVar15 = (int *)((int)piVar15 + 1);
    piVar16 = (int *)((int)piVar16 + 1);
  }
  uVar12 = 0xffffffff;
  pcVar22 = acStack_438;
  do {
    pcVar21 = pcVar22;
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    pcVar21 = pcVar22 + 1;
    cVar1 = *pcVar22;
    pcVar22 = pcVar21;
  } while (cVar1 != '\0');
  uVar12 = ~uVar12;
  piVar15 = aiStack_450;
  piVar16 = (int *)(pcVar21 + -uVar12);
  for (uVar13 = uVar12 >> 2; piVar15 = (int *)((int)piVar15 + 4), uVar13 != 0; uVar13 = uVar13 - 1)
{
    *piVar15 = *piVar16;
    piVar16 = piVar16 + 1;
  }
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(char *)piVar15 = (char)*piVar16;
    piVar16 = (int *)((int)piVar16 + 1);
    piVar15 = (int *)((int)piVar15 + 1);
  }
  aiStack_450[4] = iStack_498;
  uStack_43c = uVar11;
  iVar6 = write(iVar5,acStack_478,0x40);
  pTVar14 = extraout_ECX_02;
  if (iVar6 == 0x40) {
    uVar11 = 0x40;
    for (puVar9 = puStack_4a4; puVar17 = puStack_4a4, puVar9 != (uint *)0x0;
        puVar9 = (uint *)puVar9[4]) {
      uStack_484 = *puVar9;
      uStack_480 = puVar9[1];
      uStack_47c = puVar9[2];
      iVar6 = write(iVar5,&uStack_484,0xc);
      if (iVar6 != 0xc) {
        pcVar22 = s_Error_writing_resource_file_head;
LAB_0047fb39:
        TDebuggingLog::Log(L,(char *)L,pcVar22);
        return 0;
      }
      uVar11 = uVar11 + 0xc;
      pTVar14 = extraout_ECX_03;
    }
    while( true ) {
      puVar9 = puStack_4a4;
      if (puVar17 == (uint *)0x0) {
        do {
          if (puVar9 == (uint *)0x0) {
            close(iVar5);
            while (puStack_4a4 != (uint *)0x0) {
              pvVar4 = (void *)puStack_4a4[3];
              while (pvVar4 != (void *)0x0) {
                if (*(int *)((int)pvVar4 + 8) != 0) {
                  free(*(int *)((int)pvVar4 + 8));
                }
                pvVar3 = *(void **)((int)pvVar4 + 0x10);
                operator_delete(pvVar4);
                pvVar4 = pvVar3;
              }
              puVar9 = (uint *)puStack_4a4[4];
              operator_delete(puStack_4a4);
              puStack_4a4 = puVar9;
            }
            return 1;
          }
          for (uVar12 = puVar9[3]; uVar12 != 0; uVar12 = *(uint *)(uVar12 + 0x10)) {
            if (uVar11 != *(uint *)(uVar12 + 4)) {
              pcVar22 = s_Error_writing_resource_file_data;
              goto LAB_0047fba1;
            }
            iVar6 = *(int *)(uVar12 + 0xc);
            iVar10 = write(iVar5,*(undefined4 *)(uVar12 + 8),iVar6);
            pTVar14 = extraout_ECX_05;
            if (iVar10 != iVar6) {
              pcVar22 = s_Error_writing_resource_file_data;
              goto LAB_0047fbc2;
            }
            uVar11 = uVar11 + iVar6;
          }
          puVar9 = (uint *)puVar9[4];
        } while( true );
      }
      if (uVar11 != puVar17[1]) break;
      for (puVar2 = (undefined4 *)puVar17[3]; puVar2 != (undefined4 *)0x0;
          puVar2 = (undefined4 *)puVar2[4]) {
        uStack_490 = *puVar2;
        uStack_48c = puVar2[1];
        uStack_488 = puVar2[3];
        iVar6 = write(iVar5,&uStack_490,0xc);
        if (iVar6 != 0xc) {
          pcVar22 = s_Error_writing_resource_file_head;
          goto LAB_0047fb39;
        }
        uVar11 = uVar11 + 0xc;
        pTVar14 = extraout_ECX_04;
      }
      puVar17 = (uint *)puVar17[4];
    }
    pcVar22 = s_Error_writing_resource_file__pos;
LAB_0047fbc2:
    TDebuggingLog::Log(pTVar14,(char *)L,pcVar22);
    return 0;
  }
  pcVar22 = s_Error_writing_resource_file_head;
LAB_0047fba1:
  TDebuggingLog::Log(pTVar14,(char *)L,pcVar22);
  return 0;
}

// --------------------------------------------------

// Function: RESFILE_build_res_file
// Address: 0047f5c0
// [HELPER] header_message: "79706f43"
// [HELPER] s_1_00: "1.00"
// [HELPER] s_Error__could_not_determine_file_: "Error: could not determine file type of: %s"
// [HELPER] s_Error__could_not_find_resource_b: "Error: could not find resource build file: %s"
// [HELPER] s_Error__duplicate_resources___s__: "Error: duplicate resources: %s & %s"
// [HELPER] s_Error__error_reading_file___s: "Error: error reading file: %s"
// [HELPER] s_Error__file_is_empty_NULL___s: "Error: file is empty/NULL: %s"
// [HELPER] s_Error__out_of_memory__1: "Error: out of memory #1"
// [HELPER] s_Error__out_of_memory__2: "Error: out of memory #2"
// [HELPER] s_Error__out_of_memory__3: "Error: out of memory #3"
// [HELPER] s_Error__unable_to_create_resource: "Error: unable to create resource file file: %s"
// [HELPER] s_Error__unable_to_open_file___s: "Error: unable to open file: %s"
// [HELPER] s_Error_writing_resource_file__pos: "Error writing resource file: pos out of sync 1"
// [HELPER] s_Error_writing_resource_file_data: "Error writing resource file data: pos out of sync 2"
// [HELPER] s_Error_writing_resource_file_head: "Error writing resource file header"
// [HELPER] s__d: "%d"
// [HELPER] s__s: "%s"
// [HELPER] s__s__s: "%s\n%s"
// [HELPER] s__s_s: "%s%s"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: ID_List */
/* int __cdecl RESFILE_build_res_file(char *,char *,char *) */

int __cdecl RESFILE_build_res_file(char *param_1,char *param_2,char *param_3)
{
  char cVar1;
  BuildRes_id_node *pBVar2;
  _iobuf *p_Var3;
  int iVar4;
  long *plVar5;
  void *pvVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  BuildRes_id_node *pBVar11;
  ulong *puVar12;
  ulong uVar13;
  int iVar14;
  TDebuggingLog *this;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *extraout_ECX_00;
  uint uVar15;
  uint uVar16;
  TDebuggingLog *this_00;
  TDebuggingLog *extraout_ECX_01;
  int iVar17;
  TDebuggingLog *extraout_ECX_02;
  TDebuggingLog *extraout_ECX_03;
  TDebuggingLog *extraout_ECX_04;
  TDebuggingLog *extraout_ECX_05;
  TDebuggingLog *pTVar18;
  ulong *puVar19;
  char *pcVar20;
  BuildRes_id_node *pBVar21;
  ulong *puVar22;
  char **ppcVar23;
  char **ppcVar24;
  char *pcVar25;
  BuildRes_type_node *ID_List;
  BuildRes_id_node *iq;
  _iobuf *buildFile;
  int numResTypes;
  ulong rId;
  resfile_id_dir_node idDirNode;
  resfile_type_dir_node typeDirNode;
  resfile_header theHeader;
  char rPassword [40];
  char data_filename [260];
  char temp_filename [260];
  char resource_filename [260];
  char build_filename [260];
  
  iq = (BuildRes_id_node *)0x0;
  rId = 0;
  sprintf(build_filename + 4,s__s_s,param_2,param_1);
  iVar8 = fopen(build_filename + 4,s_r);
  if (iVar8 == 0) {
    TDebuggingLog::Log(this,(char *)L,s_Error__could_not_find_resource_b,param_1);
    return 0;
  }
  fscanf(iVar8,s__s__s,temp_filename + 4,rPassword + 4);
  sprintf(resource_filename + 4,s__s_s,param_3,temp_filename + 4);
  while ((iVar9 = fscanf(iVar8,s__s,temp_filename + 4), iVar9 != -1 &&
         (iVar9 = fscanf(iVar8,&s__d,&idDirNode), iVar9 != -1))) {
    sprintf(data_filename + 4,s__s_s,param_2,temp_filename + 4);
    uVar10 = BUILDRES_get_files_resource_type(temp_filename + 4);
    if (uVar10 == 0) {
      TDebuggingLog::Log(L,(char *)L,s_Error__could_not_determine_file_,temp_filename + 4);
      return 0;
    }
    pBVar21 = (BuildRes_id_node *)0x0;
    for (pBVar2 = iq;
        (pBVar11 = (BuildRes_id_node *)0x0, pBVar2 != (BuildRes_id_node *)0x0 &&
        (pBVar11 = pBVar2, pBVar2->id != uVar10)); pBVar2 = pBVar2->next) {
      if (pBVar2->id < uVar10) {
        pBVar21 = pBVar2;
      }
    }
    if (pBVar11 == (BuildRes_id_node *)0x0) {
      pBVar11 = (BuildRes_id_node *)operator_new(0x14);
      if (pBVar11 == (BuildRes_id_node *)0x0) {
        pcVar25 = s_Error__out_of_memory__1;
        pTVar18 = extraout_ECX;
        goto LAB_0047fba1;
      }
      pBVar11->id = uVar10;
      pBVar11->dataOffset = 0;
      pBVar11->resData = (uchar *)0x0;
      pBVar11->resSize = 0;
      pBVar11->next = (BuildRes_id_node *)0x0;
      if (pBVar21 == (BuildRes_id_node *)0x0) {
        pBVar11->next = iq;
        iq = pBVar11;
      }
      else {
        pBVar11->next = pBVar21->next;
        pBVar21->next = pBVar11;
      }
      rId = rId + 1;
    }
    p_Var3 = (_iobuf *)pBVar11->resSize;
    buildFile = (_iobuf *)0x0;
    for (; p_Var3 != (_iobuf *)0x0; p_Var3 = (_iobuf *)p_Var3->_file) {
      if (p_Var3->_ptr == (char *)idDirNode.id) {
        TDebuggingLog::Log((TDebuggingLog *)(data_filename + 4),(char *)L,
                           s_Error__duplicate_resources___s__,&p_Var3->_charbuf,
                           (TDebuggingLog *)(data_filename + 4));
        return 0;
      }
      if (p_Var3->_ptr < idDirNode.id) {
        buildFile = p_Var3;
      }
    }
    puVar12 = (ulong *)operator_new(0x118);
    if (puVar12 == (ulong *)0x0) {
      pcVar25 = s_Error__out_of_memory__2;
      pTVar18 = extraout_ECX_00;
      goto LAB_0047fbc2;
    }
    *puVar12 = idDirNode.id;
    uVar15 = 0xffffffff;
    puVar12[1] = 0;
    puVar12[2] = 0;
    puVar12[3] = 0;
    puVar12[4] = 0;
    pcVar25 = data_filename + 4;
    do {
      pcVar20 = pcVar25;
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      pcVar20 = pcVar25 + 1;
      cVar1 = *pcVar25;
      pcVar25 = pcVar20;
    } while (cVar1 != '\0');
    uVar15 = ~uVar15;
    puVar19 = (ulong *)(pcVar20 + -uVar15);
    puVar22 = puVar12 + 5;
    for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
      *puVar22 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar22 = puVar22 + 1;
    }
    for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
      *(char *)puVar22 = (char)*puVar19;
      puVar19 = (ulong *)((int)puVar19 + 1);
      puVar22 = (ulong *)((int)puVar22 + 1);
    }
    iVar9 = __open(data_filename + 4,0x8000);
    if (iVar9 == -1) {
      TDebuggingLog::Log(this_00,(char *)L,s_Error__unable_to_open_file___s,data_filename + 4);
      operator_delete(puVar12);
    }
    else {
      if (buildFile == (_iobuf *)0x0) {
        puVar12[4] = pBVar11->resSize;
        pBVar11->resSize = (int)puVar12;
      }
      else {
        puVar12[4] = buildFile->_file;
        buildFile->_file = (int)puVar12;
      }
      pBVar11->resData = pBVar11->resData + 1;
      uVar10 = lseek(iVar9,0,2);
      lseek(iVar9,0,0);
      if ((int)uVar10 < 1) {
        pTVar18 = (TDebuggingLog *)(data_filename + 4);
        pcVar25 = s_Error__file_is_empty_NULL___s;
        goto LAB_0047f96c;
      }
      uVar13 = malloc(uVar10);
      puVar12[2] = uVar13;
      if (uVar13 == 0) {
        pcVar25 = s_Error__out_of_memory__3;
        pTVar18 = extraout_ECX_01;
        goto LAB_0047fbc2;
      }
      puVar12[3] = uVar10;
      uVar13 = read(iVar9,uVar13,uVar10);
      if (uVar13 != uVar10) {
        pTVar18 = (TDebuggingLog *)(data_filename + 4);
        pcVar25 = s_Error__error_reading_file___s;
        goto LAB_0047f96c;
      }
      close(iVar9);
    }
  }
  fclose(iVar8);
  iVar8 = __open(resource_filename + 4,0x8301,0x180);
  if (iVar8 == -1) {
    pTVar18 = (TDebuggingLog *)(resource_filename + 4);
    pcVar25 = s_Error__unable_to_create_resource;
LAB_0047f96c:
    TDebuggingLog::Log(pTVar18,(char *)L,pcVar25,pTVar18);
    return 0;
  }
  iVar9 = rId * 0xc + 0x40;
  for (pBVar2 = iq; iVar17 = iVar9, pBVar21 = iq, pBVar2 != (BuildRes_id_node *)0x0;
      pBVar2 = pBVar2->next) {
    pBVar2->dataOffset = iVar9;
    iVar9 = iVar9 + (int)pBVar2->resData * 0xc;
  }
  for (; pBVar21 != (BuildRes_id_node *)0x0; pBVar21 = pBVar21->next) {
    for (iVar4 = pBVar21->resSize; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {
      *(int *)(iVar4 + 4) = iVar17;
      iVar17 = iVar17 + *(int *)(iVar4 + 0xc);
    }
  }
  pcVar25 = theHeader.banner_msg;
  pcVar20 = theHeader.banner_msg;
  for (iVar17 = 0x10; pcVar25 = pcVar25 + 4, iVar17 != 0; iVar17 = iVar17 + -1) {
    pcVar25[0] = '\0';
    pcVar25[1] = '\0';
    pcVar25[2] = '\0';
    pcVar25[3] = '\0';
  }
  uVar15 = 0xffffffff;
  ppcVar23 = &header_message;
  do {
    ppcVar24 = ppcVar23;
    if (uVar15 == 0) break;
    uVar15 = uVar15 - 1;
    ppcVar24 = (char **)((int)ppcVar23 + 1);
    cVar1 = *(char *)ppcVar23;
    ppcVar23 = ppcVar24;
  } while (cVar1 != '\0');
  uVar15 = ~uVar15;
  pcVar25 = (char *)((int)ppcVar24 - uVar15);
  for (uVar16 = uVar15 >> 2; pcVar20 = pcVar20 + 4, uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)pcVar20 = *(undefined4 *)pcVar25;
    pcVar25 = pcVar25 + 4;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *pcVar20 = *pcVar25;
    pcVar25 = pcVar25 + 1;
    pcVar20 = pcVar20 + 1;
  }
  uVar15 = 0xffffffff;
  pcVar25 = s_1_00;
  do {
    pcVar20 = pcVar25;
    if (uVar15 == 0) break;
    uVar15 = uVar15 - 1;
    pcVar20 = pcVar25 + 1;
    cVar1 = *pcVar25;
    pcVar25 = pcVar20;
  } while (cVar1 != '\0');
  uVar15 = ~uVar15;
  pcVar25 = pcVar20 + -uVar15;
  pcVar20 = theHeader.password;
  for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)pcVar20 = *(undefined4 *)pcVar25;
    pcVar25 = pcVar25 + 4;
    pcVar20 = pcVar20 + 4;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *pcVar20 = *pcVar25;
    pcVar25 = pcVar25 + 1;
    pcVar20 = pcVar20 + 1;
  }
  uVar15 = 0xffffffff;
  pcVar25 = rPassword + 4;
  do {
    pcVar20 = pcVar25;
    if (uVar15 == 0) break;
    uVar15 = uVar15 - 1;
    pcVar20 = pcVar25 + 1;
    cVar1 = *pcVar25;
    pcVar25 = pcVar20;
  } while (cVar1 != '\0');
  uVar15 = ~uVar15;
  pcVar25 = theHeader.password;
  pcVar20 = pcVar20 + -uVar15;
  for (uVar16 = uVar15 >> 2; pcVar25 = pcVar25 + 4, uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)pcVar25 = *(undefined4 *)pcVar20;
    pcVar20 = pcVar20 + 4;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *pcVar25 = *pcVar20;
    pcVar20 = pcVar20 + 1;
    pcVar25 = pcVar25 + 1;
  }
  theHeader.directory_size = rId;
  rPassword._0_4_ = iVar9;
  iVar9 = write(iVar8,theHeader.banner_msg + 4,0x40);
  pTVar18 = extraout_ECX_02;
  if (iVar9 == 0x40) {
    iVar9 = 0x40;
    for (pBVar2 = iq; pBVar21 = iq, pBVar2 != (BuildRes_id_node *)0x0; pBVar2 = pBVar2->next) {
      typeDirNode.dirOffset = pBVar2->id;
      typeDirNode.numID = pBVar2->dataOffset;
      theHeader.banner_msg._0_4_ = pBVar2->resData;
      iVar17 = write(iVar8,&typeDirNode.dirOffset,0xc);
      if (iVar17 != 0xc) {
        pcVar25 = s_Error_writing_resource_file_head;
LAB_0047fb39:
        TDebuggingLog::Log(L,(char *)L,pcVar25);
        return 0;
      }
      iVar9 = iVar9 + 0xc;
      pTVar18 = extraout_ECX_03;
    }
    while( true ) {
      pBVar2 = iq;
      if (pBVar21 == (BuildRes_id_node *)0x0) {
        do {
          if (pBVar2 == (BuildRes_id_node *)0x0) {
            close(iVar8);
            while (iq != (BuildRes_id_node *)0x0) {
              pvVar7 = (void *)iq->resSize;
              while (pvVar7 != (void *)0x0) {
                if (*(int *)((int)pvVar7 + 8) != 0) {
                  free(*(int *)((int)pvVar7 + 8));
                }
                pvVar6 = *(void **)((int)pvVar7 + 0x10);
                operator_delete(pvVar7);
                pvVar7 = pvVar6;
              }
              pBVar2 = iq->next;
              operator_delete(iq);
              iq = pBVar2;
            }
            return 1;
          }
          for (iVar17 = pBVar2->resSize; iVar17 != 0; iVar17 = *(int *)(iVar17 + 0x10)) {
            if (iVar9 != *(int *)(iVar17 + 4)) {
              pcVar25 = s_Error_writing_resource_file_data;
              goto LAB_0047fba1;
            }
            iVar4 = *(int *)(iVar17 + 0xc);
            iVar14 = write(iVar8,*(undefined4 *)(iVar17 + 8),iVar4);
            pTVar18 = extraout_ECX_05;
            if (iVar14 != iVar4) {
              pcVar25 = s_Error_writing_resource_file_data;
              goto LAB_0047fbc2;
            }
            iVar9 = iVar9 + iVar4;
          }
          pBVar2 = pBVar2->next;
        } while( true );
      }
      if (iVar9 != pBVar21->dataOffset) break;
      for (plVar5 = (long *)pBVar21->resSize; plVar5 != (long *)0x0; plVar5 = (long *)plVar5[4]) {
        idDirNode.itemOffset = *plVar5;
        idDirNode.itemSize = plVar5[1];
        typeDirNode.type = plVar5[3];
        iVar17 = write(iVar8,&idDirNode.itemOffset,0xc);
        if (iVar17 != 0xc) {
          pcVar25 = s_Error_writing_resource_file_head;
          goto LAB_0047fb39;
        }
        iVar9 = iVar9 + 0xc;
        pTVar18 = extraout_ECX_04;
      }
      pBVar21 = pBVar21->next;
    }
    pcVar25 = s_Error_writing_resource_file__pos;
LAB_0047fbc2:
    TDebuggingLog::Log(pTVar18,(char *)L,pcVar25);
    return 0;
  }
  pcVar25 = s_Error_writing_resource_file_head;
LAB_0047fba1:
  TDebuggingLog::Log(pTVar18,(char *)L,pcVar25);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047fc45
// Address: 0047fc45
undefined * FUN_0047fc45(char *param_1)
{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined **ppuVar9;
  char *pcVar10;
  char acStack_8 [8];
  
  uVar5 = 0xffffffff;
  pcVar10 = param_1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar2 != '\0');
  iVar6 = ~uVar5 - 1;
  if ((4 < iVar6) && (iVar6 < 0x104)) {
    for (iVar3 = ~uVar5 - 2; (0 < iVar3 && (param_1[iVar3] != '.')); iVar3 = iVar3 + -1) {
    }
    if (iVar3 != 0) {
      iVar7 = (iVar6 - iVar3) + -1;
      if (iVar7 < 4) {
        iVar8 = 0;
        if (-1 < iVar7) {
          do {
            cVar2 = param_1[iVar8 + iVar3 + 1];
            iVar4 = isupper((int)cVar2);
            if (iVar4 != 0) {
              cVar2 = tolower((int)cVar2);
            }
            acStack_8[iVar8] = cVar2;
            iVar8 = iVar8 + 1;
          } while (iVar8 <= iVar7);
        }
        ppuVar9 = &res_extension_table;
        puVar1 = DAT_00585524;
        while( true ) {
          if (puVar1 == (undefined *)0x0) {
            return (undefined *)0x62696e61;
          }
          iVar7 = strncmp(ppuVar9,acStack_8,iVar6 - iVar3);
          if (iVar7 == 0) break;
          puVar1 = ppuVar9[3];
          ppuVar9 = ppuVar9 + 2;
        }
        return ppuVar9[1];
      }
    }
  }
  return (undefined *)0x0;
}

// --------------------------------------------------

// Function: BUILDRES_get_files_resource_type
// Address: 0047fc50
/* WARNING: Variable defined which should be unmapped: extension */
/* unsigned long __cdecl BUILDRES_get_files_resource_type(char *) */

ulong __cdecl BUILDRES_get_files_resource_type(char *param_1)
{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined **ppuVar9;
  char *pcVar10;
  char extension [8];
  
  uVar5 = 0xffffffff;
  pcVar10 = param_1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar2 != '\0');
  iVar6 = ~uVar5 - 1;
  if ((4 < iVar6) && (iVar6 < 0x104)) {
    for (iVar3 = ~uVar5 - 2; (0 < iVar3 && (param_1[iVar3] != '.')); iVar3 = iVar3 + -1) {
    }
    if (iVar3 != 0) {
      iVar7 = (iVar6 - iVar3) + -1;
      if (iVar7 < 4) {
        iVar8 = 0;
        if (-1 < iVar7) {
          do {
            cVar2 = param_1[iVar8 + iVar3 + 1];
            iVar4 = isupper((int)cVar2);
            if (iVar4 != 0) {
              cVar2 = tolower((int)cVar2);
            }
            extension[iVar8 + 4] = cVar2;
            iVar8 = iVar8 + 1;
          } while (iVar8 <= iVar7);
        }
        ppuVar9 = &res_extension_table;
        puVar1 = DAT_00585524;
        while( true ) {
          if (puVar1 == (undefined *)0x0) {
            return 0x62696e61;
          }
          iVar7 = strncmp(ppuVar9,extension + 4,iVar6 - iVar3);
          if (iVar7 == 0) break;
          puVar1 = ppuVar9[3];
          ppuVar9 = ppuVar9 + 2;
        }
        return (ulong)ppuVar9[1];
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047fd29
// Address: 0047fd29
int FUN_0047fd29(int param_1,undefined4 param_2)
{
  if (-1 < param_1) {
    DAT_0086b264 = 2;
    DAT_0086b268 = 0;
    DAT_0086b270 = calloc(0x10000,1);
    DAT_0086b280 = 0;
    DAT_0086b26c = 0;
    DAT_0086b260 = param_1;
    DAT_0086b27c = param_2;
    DAT_0086b278 = DAT_0086b270;
  }
  return param_1;
}

// --------------------------------------------------

// Function: rge_fake_open
// Address: 0047fd30
/* int __cdecl rge_fake_open(int,int) */

int __cdecl rge_fake_open(int param_1,int param_2)
{
  if (-1 < param_1) {
    DAT_0086b264 = 2;
    DAT_0086b268 = 0;
    DAT_0086b270 = calloc(0x10000,1);
    DAT_0086b280 = 0;
    DAT_0086b26c = 0;
    DAT_0086b260 = param_1;
    DAT_0086b27c = param_2;
    DAT_0086b278 = DAT_0086b270;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047fd8a
// Address: 0047fd8a
int FUN_0047fd8a(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = __open(param_1,param_2);
  if (-1 < iVar1) {
    DAT_0086b264 = 2;
    DAT_0086b268 = 0;
    DAT_0086b270 = calloc(0x10000,1);
    DAT_0086b280 = 0;
    DAT_0086b26c = 0;
    DAT_0086b260 = iVar1;
    DAT_0086b278 = DAT_0086b270;
    lseek(iVar1,0,2);
    DAT_0086b27c = __tell(iVar1);
    DAT_0086b274 = 0;
    lseek(iVar1,0,0);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: rge_open
// Address: 0047fd90
/* int __cdecl rge_open(char *,int) */

int __cdecl rge_open(char *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = __open(param_1,param_2);
  if (-1 < iVar1) {
    DAT_0086b264 = 2;
    DAT_0086b268 = 0;
    DAT_0086b270 = calloc(0x10000,1);
    DAT_0086b280 = 0;
    DAT_0086b26c = 0;
    DAT_0086b260 = iVar1;
    DAT_0086b278 = DAT_0086b270;
    lseek(iVar1,0,2);
    DAT_0086b27c = __tell(iVar1);
    DAT_0086b274 = 0;
    lseek(iVar1,0,0);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0047fe14
// Address: 0047fe14
int FUN_0047fe14(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  iVar1 = __open(param_1,param_2,param_3);
  if (-1 < iVar1) {
    DAT_0086b264 = 2;
    DAT_0086b268 = 0;
    DAT_0086b270 = calloc(0x10000,1);
    DAT_0086b280 = 0;
    DAT_0086b26c = 0;
    DAT_0086b260 = iVar1;
    DAT_0086b278 = DAT_0086b270;
    lseek(iVar1,0,2);
    DAT_0086b27c = __tell(iVar1);
    DAT_0086b274 = 0;
    lseek(iVar1,0,0);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: rge_open
// Address: 0047fe20
/* int __cdecl rge_open(char *,int,int) */

int __cdecl rge_open(char *param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = __open(param_1,param_2,param_3);
  if (-1 < iVar1) {
    DAT_0086b264 = 2;
    DAT_0086b268 = 0;
    DAT_0086b270 = calloc(0x10000,1);
    DAT_0086b280 = 0;
    DAT_0086b26c = 0;
    DAT_0086b260 = iVar1;
    DAT_0086b278 = DAT_0086b270;
    lseek(iVar1,0,2);
    DAT_0086b27c = __tell(iVar1);
    DAT_0086b274 = 0;
    lseek(iVar1,0,0);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0047fea9
// Address: 0047fea9
int FUN_0047fea9(int param_1)
{
  if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    if (DAT_0086b270 != 0) {
      free(DAT_0086b270);
      DAT_0086b270 = 0;
    }
    if (DAT_0086b26c != 0) {
      free(DAT_0086b26c);
      DAT_0086b26c = 0;
    }
    if (DAT_0086b280 != 0) {
      free(DAT_0086b280);
      DAT_0086b280 = 0;
    }
    DAT_0086b260 = -1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: rge_fake_close
// Address: 0047feb0
/* int __cdecl rge_fake_close(int) */

int __cdecl rge_fake_close(int param_1)
{
  if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    if (DAT_0086b270 != 0) {
      free(DAT_0086b270);
      DAT_0086b270 = 0;
    }
    if (DAT_0086b26c != 0) {
      free(DAT_0086b26c);
      DAT_0086b26c = 0;
    }
    if (DAT_0086b280 != 0) {
      free(DAT_0086b280);
      DAT_0086b280 = 0;
    }
    DAT_0086b260 = -1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047ff23
// Address: 0047ff23
int FUN_0047ff23(int param_1)
{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    if ((DAT_0086b264 == '\x01') && (DAT_0086b26c != 0)) {
      iVar1 = deflate_data(DAT_0086b26c,0,0,1);
      if (iVar1 == 2) {
        rge_write_error = 1;
      }
      deflate_deinit(DAT_0086b26c);
    }
    DAT_0086b260 = -1;
    if (DAT_0086b270 != 0) {
      free(DAT_0086b270);
      DAT_0086b270 = 0;
    }
    if (DAT_0086b26c != 0) {
      free(DAT_0086b26c);
      DAT_0086b26c = 0;
    }
    if (DAT_0086b280 != 0) {
      free(DAT_0086b280);
      DAT_0086b280 = 0;
    }
    param_1 = close(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: rge_close
// Address: 0047ff30
/* int __cdecl rge_close(int) */

int __cdecl rge_close(int param_1)
{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    if ((DAT_0086b264 == '\x01') && (DAT_0086b26c != 0)) {
      iVar1 = deflate_data(DAT_0086b26c,0,0,1);
      if (iVar1 == 2) {
        rge_write_error = 1;
      }
      deflate_deinit(DAT_0086b26c);
    }
    DAT_0086b260 = -1;
    if (DAT_0086b270 != 0) {
      free(DAT_0086b270);
      DAT_0086b270 = 0;
    }
    if (DAT_0086b26c != 0) {
      free(DAT_0086b26c);
      DAT_0086b26c = 0;
    }
    if (DAT_0086b280 != 0) {
      free(DAT_0086b280);
      DAT_0086b280 = 0;
    }
    param_1 = close(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047fff4
// Address: 0047fff4
void FUN_0047fff4(int param_1,undefined4 param_2,int param_3)
{
  if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    read(param_1,param_2,param_3);
    DAT_0086b27c = DAT_0086b27c - param_3;
  }
  return;
}

// --------------------------------------------------

// Function: rge_read_uncompressed
// Address: 00480000
/* void __cdecl rge_read_uncompressed(int,void *,int) */

void __cdecl rge_read_uncompressed(int param_1,void *param_2,int param_3)
{
  if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    read(param_1,param_2,param_3);
    DAT_0086b27c = DAT_0086b27c - param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00480032
// Address: 00480032
void FUN_00480032(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    iVar1 = write(param_1,param_2,param_3);
    if (iVar1 < 1) {
      rge_write_error = 1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: rge_write_uncompressed
// Address: 00480040
/* void __cdecl rge_write_uncompressed(int,void *,int) */

void __cdecl rge_write_uncompressed(int param_1,void *param_2,int param_3)
{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    iVar1 = write(param_1,param_2,param_3);
    if (iVar1 < 1) {
      rge_write_error = 1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00480072
// Address: 00480072
void FUN_00480072(int param_1,undefined4 *param_2,uint param_3)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uStack_4;
  
  uVar4 = param_3;
  iVar1 = param_1;
  if (ENABLE_COMPRESSION == 0) {
    if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
      read(param_1,param_2,param_3);
      DAT_0086b27c = DAT_0086b27c - uVar4;
      DAT_0086b274 = DAT_0086b274 + uVar4;
      return;
    }
  }
  else if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    if (DAT_0086b264 != '\0') {
      uVar2 = _Inf32BufSize();
      DAT_0086b26c = calloc(uVar2,1);
      DAT_0086b280 = calloc(DAT_0086b27c,1);
      read(iVar1,DAT_0086b280,DAT_0086b27c);
      param_1 = DAT_0086b27c;
      DAT_0086b25c = 0;
      uStack_4 = 0x10000;
      _Inf32Decode(DAT_0086b280,0,&param_1,DAT_0086b270,0,&uStack_4,DAT_0086b26c,1);
      DAT_0086b25c = DAT_0086b25c + param_1;
      DAT_0086b264 = '\0';
    }
    uVar4 = param_3;
    uVar3 = param_3 + DAT_0086b268;
    while (0xffff < (int)uVar3) {
      uVar5 = 0x10000 - DAT_0086b268;
      puVar6 = DAT_0086b278;
      puVar7 = param_2;
      for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar3 = uVar5 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      param_1 = DAT_0086b27c;
      uStack_4 = 0x10000;
      _Inf32Decode(DAT_0086b280,DAT_0086b25c,&param_1,DAT_0086b270,0,&uStack_4,DAT_0086b26c,1);
      DAT_0086b25c = DAT_0086b25c + param_1;
      param_2 = (undefined4 *)((int)param_2 + uVar5);
      DAT_0086b268 = 0;
      uVar4 = uVar4 - uVar5;
      DAT_0086b278 = DAT_0086b270;
      uVar3 = uVar4;
    }
    if (0 < (int)uVar4) {
      puVar6 = DAT_0086b278;
      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *param_2 = *puVar6;
        puVar6 = puVar6 + 1;
        param_2 = param_2 + 1;
      }
      for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)param_2 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        param_2 = (undefined4 *)((int)param_2 + 1);
      }
      DAT_0086b268 = DAT_0086b268 + uVar4;
      DAT_0086b278 = (undefined4 *)((int)DAT_0086b278 + uVar4);
    }
  }
  return;
}

// --------------------------------------------------

// Function: rge_read
// Address: 00480080
/* WARNING: Variable defined which should be unmapped: temp_max */
/* void __cdecl rge_read(int,void *,int) */

void __cdecl rge_read(int param_1,void *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int temp_max;
  undefined4 local_4;
  
  iVar2 = param_3;
  iVar1 = param_1;
  if (ENABLE_COMPRESSION == 0) {
    if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
      read(param_1,param_2,param_3);
      DAT_0086b27c = DAT_0086b27c - iVar2;
      DAT_0086b274 = DAT_0086b274 + iVar2;
      return;
    }
  }
  else if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    if (DAT_0086b264 != '\0') {
      uVar3 = _Inf32BufSize();
      DAT_0086b26c = calloc(uVar3,1);
      DAT_0086b280 = calloc(DAT_0086b27c,1);
      read(iVar1,DAT_0086b280,DAT_0086b27c);
      param_1 = DAT_0086b27c;
      DAT_0086b25c = 0;
      local_4 = 0x10000;
      _Inf32Decode(DAT_0086b280,0,&param_1,DAT_0086b270,0,&local_4,DAT_0086b26c,1);
      DAT_0086b25c = DAT_0086b25c + param_1;
      DAT_0086b264 = '\0';
    }
    uVar5 = param_3;
    uVar4 = param_3 + DAT_0086b268;
    while (0xffff < (int)uVar4) {
      uVar6 = 0x10000 - DAT_0086b268;
      puVar7 = DAT_0086b278;
      puVar8 = (undefined4 *)param_2;
      for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      param_1 = DAT_0086b27c;
      local_4 = 0x10000;
      _Inf32Decode(DAT_0086b280,DAT_0086b25c,&param_1,DAT_0086b270,0,&local_4,DAT_0086b26c,1);
      DAT_0086b25c = DAT_0086b25c + param_1;
      param_2 = (void *)((int)param_2 + uVar6);
      DAT_0086b268 = 0;
      uVar5 = uVar5 - uVar6;
      DAT_0086b278 = DAT_0086b270;
      uVar4 = uVar5;
    }
    if (0 < (int)uVar5) {
      puVar7 = DAT_0086b278;
      for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)param_2 = *puVar7;
        puVar7 = puVar7 + 1;
        param_2 = (undefined4 *)((int)param_2 + 4);
      }
      for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)param_2 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        param_2 = (undefined4 *)((int)param_2 + 1);
      }
      DAT_0086b268 = DAT_0086b268 + uVar5;
      DAT_0086b278 = (undefined4 *)((int)DAT_0086b278 + uVar5);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048028b
// Address: 0048028b
undefined4 FUN_0048028b(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = write(DAT_0086b260,param_1,param_2);
  if (iVar1 < 1) {
    rge_write_error = 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: rge_buffer_full
// Address: 00480290
/* int __cdecl rge_buffer_full(unsigned char *,int) */

int __cdecl rge_buffer_full(uchar *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = write(DAT_0086b260,param_1,param_2);
  if (iVar1 < 1) {
    rge_write_error = 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004802ba
// Address: 004802ba
void FUN_004802ba(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 uVar2;
  
  if (ENABLE_COMPRESSION == 0) {
    if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
      iVar1 = write(param_1,param_2,param_3);
      if (iVar1 < 1) {
        rge_write_error = 1;
        return;
      }
    }
  }
  else if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    if (DAT_0086b264 != '\x01') {
      DAT_0086b264 = '\x01';
      uVar2 = deflate_buf_size();
      DAT_0086b26c = calloc(uVar2,1);
      deflate_init(DAT_0086b26c,0x4b,2,1,DAT_0086b270,0x10000,rge_buffer_full);
    }
    iVar1 = deflate_data(DAT_0086b26c,param_2,param_3,0);
    if (iVar1 == 2) {
      rge_write_error = 1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: rge_write
// Address: 004802c0
/* void __cdecl rge_write(int,void *,int) */

void __cdecl rge_write(int param_1,void *param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  
  if (ENABLE_COMPRESSION == 0) {
    if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
      iVar1 = write(param_1,param_2,param_3);
      if (iVar1 < 1) {
        rge_write_error = 1;
        return;
      }
    }
  }
  else if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    if (DAT_0086b264 != '\x01') {
      DAT_0086b264 = '\x01';
      uVar2 = deflate_buf_size();
      DAT_0086b26c = calloc(uVar2,1);
      deflate_init(DAT_0086b26c,0x4b,2,1,DAT_0086b270,0x10000,rge_buffer_full);
    }
    iVar1 = deflate_data(DAT_0086b26c,param_2,param_3,0);
    if (iVar1 == 2) {
      rge_write_error = 1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00480383
// Address: 00480383
// [HELPER] s_C__msdev_work_age1_x1_RGE_TSLC_c: "C:\msdev\work\age1_x1\RGE_TSLC.cpp"
int __fastcall FUN_00480383(int param_1)
{
  ulong uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(param_1 + 0x100) = 99999;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x2a0) = 0;
  *(undefined4 *)(param_1 + 0x2b0) = 0;
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0xd);
  *(ulong *)(param_1 + 0x2a8) = uVar1;
  *(ulong *)(param_1 + 0x2ac) = uVar1;
  *(ulong *)(param_1 + 0x2a4) = uVar1;
  puVar3 = (undefined4 *)(param_1 + 0x10c);
  for (iVar2 = 0x65; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004803e7
// Address: 004803e7
void FUN_004803e7(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004803f1
// Address: 004803f1
uint __thiscall FUN_004803f1(int param_1,uint param_2)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if ((0 < (int)param_2) && ((int)param_2 < 0x65)) {
    iVar2 = *(int *)(param_1 + 0x2a0);
    iVar3 = 0;
    if (0 < (int)param_2) {
      do {
        iVar2 = iVar2 + -1;
        if (iVar2 < 1) {
          iVar2 = 100;
        }
        uVar1 = uVar1 + *(int *)(param_1 + 0x10c + iVar2 * 4);
        if (999 < uVar1) {
          *(int *)(param_1 + 0x2b0) = iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)param_2);
    }
    return uVar1 / param_2;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00480451
// Address: 00480451
// [HELPER] s_C__msdev_work_age1_x1_RGE_TSLC_c: "C:\msdev\work\age1_x1\RGE_TSLC.cpp"
int __fastcall FUN_00480451(int param_1)
{
  ulong uVar1;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0x56);
  return uVar1 - *(int *)(param_1 + 0x2a4);
}

// --------------------------------------------------

// Function: FUN_0048047c
// Address: 0048047c
// [HELPER] s_C__msdev_work_age1_x1_RGE_TSLC_c: "C:\msdev\work\age1_x1\RGE_TSLC.cpp"
uint __fastcall FUN_0048047c(int param_1)
{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0x5d);
  uVar1 = *(ulong *)(param_1 + 0x2a4);
  if (uVar1 == uVar3) {
    return 0;
  }
  *(ulong *)(param_1 + 0x2a4) = uVar3;
  iVar4 = *(int *)(param_1 + 0x2a0) + 1;
  *(ulong *)(param_1 + 0x108) = uVar3 - uVar1;
  *(int *)(param_1 + 0x2a0) = iVar4;
  if (100 < iVar4) {
    *(undefined4 *)(param_1 + 0x2a0) = 0;
  }
  *(undefined4 *)(param_1 + 0x10c + *(int *)(param_1 + 0x2a0) * 4) =
       *(undefined4 *)(param_1 + 0x108);
  uVar2 = *(uint *)(param_1 + 0x108);
  uVar5 = *(uint *)(param_1 + 0x100);
  if (uVar2 < *(uint *)(param_1 + 0x100)) {
    uVar5 = uVar2;
  }
  *(uint *)(param_1 + 0x100) = uVar5;
  uVar5 = *(uint *)(param_1 + 0x104);
  if (*(uint *)(param_1 + 0x104) < uVar2) {
    uVar5 = uVar2;
  }
  *(uint *)(param_1 + 0x104) = uVar5;
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_0048050d
// Address: 0048050d
// [HELPER] s_C__msdev_work_age1_x1_RGE_TSLC_c: "C:\msdev\work\age1_x1\RGE_TSLC.cpp"
void __fastcall FUN_0048050d(int param_1)
{
  ulong uVar1;
  
  debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0x78);
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0x79);
  *(ulong *)(param_1 + 0x2a4) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_00480539
// Address: 00480539
// [HELPER] s_Avg__d____d: "Avg %d / %d"
RGE_TimeSinceLastCall * __thiscall FUN_00480539(RGE_TimeSinceLastCall *param_1,int param_2)
{
  ulong uVar1;
  
  uVar1 = RGE_TimeSinceLastCall::GetAvg(param_1,param_2);
  sprintf(param_1,s_Avg__d____d,uVar1,param_2);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00480565
// Address: 00480565
int __thiscall FUN_00480565(int param_1,uint param_2)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = param_2;
  uVar2 = 0;
  uVar5 = 0;
  uVar6 = 999999;
  uVar3 = param_2;
  uVar7 = param_2;
  if ((0 < (int)param_2) && ((int)param_2 < 0x65)) {
    iVar4 = *(int *)(param_1 + 0x2a0);
    if (0 < (int)param_2) {
      do {
        iVar4 = iVar4 + -1;
        if (iVar4 < 1) {
          iVar4 = 100;
        }
        uVar3 = *(uint *)(param_1 + 0x10c + iVar4 * 4);
        uVar2 = uVar2 + uVar3;
        if (uVar3 < uVar6) {
          uVar6 = uVar3;
        }
        if (uVar5 < uVar3) {
          uVar5 = uVar3;
        }
        param_2 = param_2 - 1;
      } while (param_2 != 0);
    }
    param_2 = uVar2 / uVar1;
    uVar3 = uVar5;
    uVar7 = uVar6;
  }
  sprintf(param_1,s__LoLo__d__Lo__d_<_Avg__d____d_>_,*(undefined4 *)(param_1 + 0x100),uVar7,param_2,
          uVar1,uVar3,*(undefined4 *)(param_1 + 0x104));
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00480602
// Address: 00480602
int __thiscall FUN_00480602(int param_1,uint param_2)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = param_2;
  uVar2 = 0;
  uVar5 = 0;
  uVar6 = 999999;
  uVar3 = param_2;
  uVar7 = param_2;
  if ((0 < (int)param_2) && ((int)param_2 < 0x65)) {
    iVar4 = *(int *)(param_1 + 0x2a0);
    if (0 < (int)param_2) {
      do {
        iVar4 = iVar4 + -1;
        if (iVar4 < 1) {
          iVar4 = 100;
        }
        uVar3 = *(uint *)(param_1 + 0x10c + iVar4 * 4);
        uVar2 = uVar2 + uVar3;
        if (uVar3 < uVar6) {
          uVar6 = uVar3;
        }
        if (uVar5 < uVar3) {
          uVar5 = uVar3;
        }
        param_2 = param_2 - 1;
      } while (param_2 != 0);
    }
    param_2 = uVar2 / uVar1;
    uVar3 = uVar5;
    uVar7 = uVar6;
  }
  sprintf(param_1,s_Lo__d_<_Avg__d_>_Hi__d_of__d,uVar7,param_2,uVar3,uVar1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00480694
// Address: 00480694
ulong __fastcall FUN_00480694(RGE_TimeSinceLastCall *param_1)
{
  param_1->cps = 0;
  RGE_TimeSinceLastCall::GetAvg(param_1,100);
  return param_1->cps;
}

// --------------------------------------------------

// Function: FUN_004806bc
// Address: 004806bc
undefined4 __fastcall FUN_004806bc(int param_1)
{
  return *(undefined4 *)(param_1 + 0x2a8);
}

// --------------------------------------------------

// Function: FUN_004806c7
// Address: 004806c7
// [HELPER] s_C__msdev_work_age1_x1_RGE_TSLC_c: "C:\msdev\work\age1_x1\RGE_TSLC.cpp"
// [HELPER] s__02ld__02ld__02ld: "%02ld:%02ld:%02ld"
int __fastcall FUN_004806c7(int param_1)
{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0xb5);
  *(ulong *)(param_1 + 0x2ac) = uVar1;
  uVar2 = (uVar1 - *(int *)(param_1 + 0x2a8)) / 1000;
  if (0x3b < uVar2) {
    uVar4 = uVar2 / 0x3c;
    uVar2 = uVar2 % 0x3c;
    if (0x3b < uVar4) {
      uVar3 = uVar4 / 0x3c;
      uVar4 = uVar4 % 0x3c;
    }
  }
  sprintf(param_1,s__02ld__02ld__02ld,uVar3,uVar4,uVar2);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00480766
// Address: 00480766
void __fastcall FUN_00480766(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x10c);
  for (iVar1 = 100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 10;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00480785
// Address: 00480785
RGE_Random_Map_Module * __thiscall
FUN_00480785(RGE_Random_Map_Module *param_1,RGE_Map *param_2,RGE_Random_Map_Module *param_3,
            char param_4)
{
  RGE_Tile **ppRVar1;
  long lVar2;
  
  param_1->_padding_ = (int)&RGE_Random_Map_Module::_vftable_;
  param_1->parent = param_3;
  param_1->map = param_2;
  if (param_2 == (RGE_Map *)0x0) {
    param_1->map_row_offset = (RGE_Tile **)0x0;
    param_1->map_width = 0;
    param_1->map_height = 0;
  }
  else {
    ppRVar1 = RGE_Map::give_up_map_offsets(param_2);
    param_1->map_row_offset = ppRVar1;
    lVar2 = RGE_Map::get_map_width(param_1->map);
    param_1->map_width = lVar2;
    lVar2 = RGE_Map::get_map_height(param_1->map);
    param_1->map_height = lVar2;
  }
  param_1->list = (RGE_Random_Map_Module_List *)0x0;
  param_1->search_map = (uchar *)0x0;
  param_1->stack_array = (Map_Stack *)0x0;
  param_1->search_map_rows = (uchar **)0x0;
  param_1->stack_offsets = (Map_Stack **)0x0;
  if (param_1->parent == (RGE_Random_Map_Module *)0x0) {
    if (param_4 != '\0') {
      RGE_Random_Map_Module::create_shared_resources(param_1);
      return param_1;
    }
  }
  else {
    RGE_Random_Map_Module::add_module(param_1->parent,param_1);
    RGE_Random_Map_Module::share_resources
              (param_1->parent,&param_1->search_map,&param_1->search_map_rows,&param_1->stack_array,
               &param_1->stack_offsets);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00480835
// Address: 00480835
void __fastcall FUN_00480835(RGE_Random_Map_Module *param_1)
{
  RGE_Random_Map_Module_List *pRVar1;
  RGE_Random_Map_Module *this;
  
  pRVar1 = param_1->list;
  param_1->_padding_ = (int)&RGE_Random_Map_Module::_vftable_;
  while (pRVar1 != (RGE_Random_Map_Module_List *)0x0) {
    this = pRVar1->module;
    if (this != (RGE_Random_Map_Module *)0x0) {
      RGE_Random_Map_Module::~RGE_Random_Map_Module(this);
      operator_delete(this);
    }
    pRVar1 = param_1->list;
  }
  if (param_1->parent != (RGE_Random_Map_Module *)0x0) {
    RGE_Random_Map_Module::remove_module(param_1->parent,param_1);
    param_1->search_map = (uchar *)0x0;
    param_1->search_map_rows = (uchar **)0x0;
    param_1->stack_array = (Map_Stack *)0x0;
    param_1->stack_offsets = (Map_Stack **)0x0;
    param_1->map = (RGE_Map *)0x0;
    param_1->map_row_offset = (RGE_Tile **)0x0;
    param_1->map_width = 0;
    param_1->map_height = 0;
    return;
  }
  RGE_Random_Map_Module::destroy_shared_resources(param_1);
  param_1->map = (RGE_Map *)0x0;
  param_1->map_row_offset = (RGE_Tile **)0x0;
  param_1->map_width = 0;
  param_1->map_height = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004808b1
// Address: 004808b1
float10 __fastcall FUN_004808b1(int param_1)
{
  return (float10)*(float *)(param_1 + 0x1c);
}

// --------------------------------------------------

// Function: FUN_004808c4
// Address: 004808c4
// [HELPER] s_C__msdev_work_age1_x1_rmm_base_c: "C:\msdev\work\age1_x1\rmm_base.cpp"
// [HELPER] s_RGE_RANDOM_MAP_MODULE__map_start: "RGE_RANDOM_MAP_MODULE::map startped with random: %d."
// [HELPER] s_RGE_RANDOM_MAP_MODULE__module_co: "RGE_RANDOM_MAP_MODULE::module completed with random: %d."
undefined4 __fastcall FUN_004808c4(int param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  TDebuggingLog *this;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float fVar8;
  float fVar9;
  
  puVar2 = (undefined4 *)0x0;
  puVar7 = *(undefined4 **)(param_1 + 8);
joined_r0x004808e4:
  do {
    puVar3 = puVar7;
    if (puVar3 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 8) = puVar2;
      iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_base_c,0x8a);
      TDebuggingLog::Log(this,(char *)L,s_RGE_RANDOM_MAP_MODULE__map_start,iVar5);
      puVar7 = *(undefined4 **)(param_1 + 8);
      if (puVar7 == (undefined4 *)0x0) {
        return 1;
      }
      do {
        cVar4 = (*(code *)**(undefined4 **)*puVar7)();
        if (cVar4 == '\0') {
          return 0;
        }
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_base_c,0x8f);
        TDebuggingLog::Log(L,(char *)L,s_RGE_RANDOM_MAP_MODULE__module_co,iVar5);
        puVar7 = (undefined4 *)puVar7[1];
      } while (puVar7 != (undefined4 *)0x0);
      return 1;
    }
    puVar7 = (undefined4 *)puVar3[1];
    if (puVar2 != (undefined4 *)0x0) {
      fVar8 = RGE_Random_Map_Module::get_schedule((RGE_Random_Map_Module *)*puVar3);
      fVar9 = RGE_Random_Map_Module::get_schedule((RGE_Random_Map_Module *)*puVar2);
      puVar6 = puVar2;
      if (fVar9 <= fVar8) {
        do {
          if (puVar6[1] == 0) {
LAB_0048093c:
            puVar3[1] = puVar6[1];
            puVar6[1] = puVar3;
            break;
          }
          fVar8 = RGE_Random_Map_Module::get_schedule((RGE_Random_Map_Module *)*puVar3);
          fVar9 = RGE_Random_Map_Module::get_schedule(*(RGE_Random_Map_Module **)puVar6[1]);
          if (fVar8 < fVar9) goto LAB_0048093c;
          puVar1 = puVar6 + 1;
          puVar6 = (undefined4 *)*puVar1;
        } while ((undefined4 *)*puVar1 != (undefined4 *)0x0);
        goto joined_r0x004808e4;
      }
    }
    puVar3[1] = puVar2;
    puVar2 = puVar3;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004809dd
// Address: 004809dd
undefined4 __thiscall FUN_004809dd(int param_1,int param_2)
{
  int *piVar1;
  
  if (param_2 == 0) {
    return 0;
  }
  piVar1 = (int *)calloc(1,8);
  piVar1[1] = *(int *)(param_1 + 8);
  *piVar1 = param_2;
  *(int **)(param_1 + 8) = piVar1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00480a11
// Address: 00480a11
undefined4 __thiscall FUN_00480a11(int param_1,int param_2)
{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  piVar3 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 == param_2) {
      *(int *)(param_1 + 8) = piVar1[1];
      piVar3 = piVar1;
    }
    else {
      piVar2 = piVar1 + 1;
      piVar1 = (int *)piVar1[1];
      while (piVar1 != (int *)0x0) {
        if (*piVar1 == param_2) {
          *piVar2 = piVar1[1];
          piVar3 = piVar1;
        }
        piVar2 = (int *)(*piVar2 + 4);
        piVar1 = (int *)*piVar2;
      }
    }
  }
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  free(piVar3);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00480a7a
// Address: 00480a7a
void __fastcall FUN_00480a7a(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = calloc(*(int *)(param_1 + 0x18) * *(int *)(param_1 + 0x14),1);
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = calloc(*(undefined4 *)(param_1 + 0x18),4);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      *(int *)(*(int *)(param_1 + 0x24) + iVar2 * 4) =
           iVar2 * *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x20);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x18));
  }
  uVar1 = calloc(*(int *)(param_1 + 0x18) * *(int *)(param_1 + 0x14),0x18);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = calloc(*(undefined4 *)(param_1 + 0x18),4);
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      iVar3 = iVar2 * *(int *)(param_1 + 0x14);
      iVar2 = iVar2 + 1;
      *(int *)(*(int *)(param_1 + 0x2c) + -4 + iVar2 * 4) = *(int *)(param_1 + 0x28) + iVar3 * 0x18;
    } while (iVar2 < *(int *)(param_1 + 0x18));
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x14)) {
        iVar4 = 0;
        do {
          iVar4 = iVar4 + 0x18;
          *(int *)(*(int *)(*(int *)(param_1 + 0x2c) + iVar2 * 4) + -0x18 + iVar4) = iVar3;
          iVar3 = iVar3 + 1;
          *(int *)(*(int *)(*(int *)(param_1 + 0x2c) + iVar2 * 4) + -0x14 + iVar4) = iVar2;
        } while (iVar3 < *(int *)(param_1 + 0x14));
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x18));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00480b57
// Address: 00480b57
void __fastcall FUN_00480b57(int param_1)
{
  if (*(int *)(param_1 + 0x20) != 0) {
    free(*(int *)(param_1 + 0x20));
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (*(int *)(param_1 + 0x24) != 0) {
    free(*(int *)(param_1 + 0x24));
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (*(int *)(param_1 + 0x28) != 0) {
    free(*(int *)(param_1 + 0x28));
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (*(int *)(param_1 + 0x2c) != 0) {
    free(*(int *)(param_1 + 0x2c));
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00480bb5
// Address: 00480bb5
void __fastcall FUN_00480bb5(int param_1)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[1]) {
    RGE_Random_Map_Module::update_resources((RGE_Random_Map_Module *)*puVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00480bd8
// Address: 00480bd8
void __fastcall FUN_00480bd8(RGE_Random_Map_Module *param_1)
{
  RGE_Random_Map_Module::share_resources
            (param_1->parent,&param_1->search_map,&param_1->search_map_rows,&param_1->stack_array,
             &param_1->stack_offsets);
  RGE_Random_Map_Module::update_child_resources(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00480c04
// Address: 00480c04
void __fastcall FUN_00480c04(int param_1)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[1]) {
    RGE_Random_Map_Module::update_map_info
              ((RGE_Random_Map_Module *)*puVar1,*(RGE_Map **)(param_1 + 0xc));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00480c7d
// Address: 00480c7d
void __thiscall
FUN_00480c7d(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)
{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x20);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x24);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + 0x28);
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = *(undefined4 *)(param_1 + 0x2c);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00480cb7
// Address: 00480cb7
void FUN_00480cb7(undefined4 *param_1)
{
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00480ce2
// Address: 00480ce2
void FUN_00480ce2(int param_1)
{
  if (*(int *)(param_1 + 0x10) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00480d06
// Address: 00480d06
void __thiscall
FUN_00480d06(RGE_Random_Map_Module *param_1,Map_Stack *param_2,int param_3,int param_4,float param_5
            ,float param_6)
{
  Map_Stack *pMVar1;
  Map_Stack *pMVar2;
  Map_Stack *pMVar3;
  
  pMVar1 = param_1->stack_offsets[param_4] + param_3;
  RGE_Random_Map_Module::remove_stack_node(param_1,pMVar1);
  pMVar2 = param_2->next;
  if ((pMVar2 == (Map_Stack *)0x0) || (param_6 <= pMVar2->tot_cost)) {
    RGE_Random_Map_Module::add_stack_node(param_1,param_2,pMVar1);
    pMVar1->cost = param_5;
    pMVar1->tot_cost = param_6;
    return;
  }
  do {
    pMVar3 = pMVar2;
    pMVar2 = pMVar3->next;
    if (pMVar2 == (Map_Stack *)0x0) break;
  } while (pMVar2->tot_cost < param_6);
  RGE_Random_Map_Module::add_stack_node(param_1,pMVar3,pMVar1);
  pMVar1->cost = param_5;
  pMVar1->tot_cost = param_6;
  return;
}

// --------------------------------------------------

// Function: FUN_00480d98
// Address: 00480d98
Map_Stack * __thiscall
FUN_00480d98(RGE_Random_Map_Module *param_1,int param_2,long *param_3,long *param_4,float *param_5)
{
  Map_Stack *pMVar1;
  
  pMVar1 = *(Map_Stack **)(param_2 + 0x10);
  if (pMVar1 == (Map_Stack *)0x0) {
    return (Map_Stack *)0x0;
  }
  *param_3 = pMVar1->x;
  *param_4 = pMVar1->y;
  *param_5 = pMVar1->cost;
  RGE_Random_Map_Module::remove_stack_node(param_1,pMVar1);
  return pMVar1;
}

// --------------------------------------------------

// Function: FUN_00480dd8
// Address: 00480dd8
void __thiscall FUN_00480dd8(RGE_Random_Map_Module *param_1,Map_Stack *param_2,Map_Stack *param_3)
{
  Map_Stack *pMVar1;
  
  if ((param_3->next != (Map_Stack *)0x0) || (param_3->prev != (Map_Stack *)0x0)) {
    RGE_Random_Map_Module::remove_stack_node(param_1,param_3);
  }
  pMVar1 = param_2->next;
  param_3->prev = param_2;
  param_3->next = pMVar1;
  if (param_2->next != (Map_Stack *)0x0) {
    param_2->next->prev = param_3;
  }
  param_2->next = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00480e17
// Address: 00480e17
void FUN_00480e17(int param_1)
{
  if (*(int *)(param_1 + 0x14) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x10) = *(undefined4 *)(param_1 + 0x10);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x14) = *(undefined4 *)(param_1 + 0x14);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00480e4b
// Address: 00480e4b
void __fastcall FUN_00480e4b(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0x14)) {
        iVar1 = 0;
        do {
          iVar2 = iVar2 + 1;
          iVar1 = iVar1 + 0x18;
          *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2c) + iVar3 * 4) + -8 + iVar1) = 0;
          *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2c) + iVar3 * 4) + -4 + iVar1) = 0;
        } while (iVar2 < *(int *)(param_1 + 0x14));
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x18));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00480e94
// Address: 00480e94
undefined4 FUN_00480e94(int param_1)
{
  if ((*(int *)(param_1 + 0x10) == 0) && (*(int *)(param_1 + 0x14) == 0)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00480ebc
// Address: 00480ebc
// [HELPER] s_C__msdev_work_age1_x1_rmm_base_c: "C:\msdev\work\age1_x1\rmm_base.cpp"
void __thiscall FUN_00480ebc(RGE_Random_Map_Module *param_1,Map_Stack *param_2)
{
  int *piVar1;
  Map_Stack **ppMVar2;
  Map_Stack *pMVar3;
  int iVar4;
  int iStack_968;
  int iStack_964;
  Map_Stack aMStack_960 [100];
  
  pMVar3 = aMStack_960;
  iVar4 = 100;
  do {
    RGE_Random_Map_Module::init_stack(param_1,pMVar3);
    pMVar3 = pMVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iStack_968 = 2;
LAB_00480ef2:
  pMVar3 = param_2->next;
  while (pMVar3 != (Map_Stack *)0x0) {
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_base_c,0x1e8);
    RGE_Random_Map_Module::add_stack_node
              (param_1,aMStack_960 + (iVar4 * 100) / 0x7fff,param_2->next);
    pMVar3 = param_2->next;
  }
  ppMVar2 = &aMStack_960[0].next;
  iStack_964 = 0x18;
LAB_00480f4e:
  piVar1 = (int *)((int)&aMStack_960[0].next + iStack_964);
LAB_00480f52:
  if (*ppMVar2 == (Map_Stack *)0x0) {
    if (*piVar1 == 0) goto LAB_00480f7c;
  }
  else {
    RGE_Random_Map_Module::add_stack_node(param_1,param_2,*ppMVar2);
  }
  pMVar3 = (Map_Stack *)*piVar1;
  if (pMVar3 != (Map_Stack *)0x0) {
    RGE_Random_Map_Module::add_stack_node(param_1,param_2,pMVar3);
  }
  goto LAB_00480f52;
LAB_00480f7c:
  ppMVar2 = ppMVar2 + 0xc;
  iStack_964 = iStack_964 + 0x30;
  if (0x977 < iStack_964) goto code_r0x00480f91;
  goto LAB_00480f4e;
code_r0x00480f91:
  iStack_968 = iStack_968 + -1;
  if (iStack_968 == 0) {
    return;
  }
  goto LAB_00480ef2;
}

// --------------------------------------------------

// Function: FUN_00480fad
// Address: 00480fad
uchar __thiscall
FUN_00480fad(RGE_Random_Map_Module *param_1,long param_2,long param_3,long *param_4,long *param_5,
            float *param_6)
{
  uchar uVar1;
  Map_Stack MStack_18;
  
  RGE_Random_Map_Module::init_stack(param_1,&MStack_18);
  uVar1 = RGE_Random_Map_Module::find_path
                    (param_1,&MStack_18,param_2,param_3,param_4,param_5,param_6);
  RGE_Random_Map_Module::deinit_stack(param_1,&MStack_18);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_00480ffe
// Address: 00480ffe
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00480ffe(RGE_Random_Map_Module *param_1,Map_Stack *param_2,int param_3,int param_4,int *param_5,
            int *param_6,int param_7)
{
  byte bVar1;
  uchar uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  Map_Stack *pMVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uchar *puVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  float fStack_14;
  float fStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  fStack_10 = 0.0;
  iStack_4 = param_1->map_width + -1;
  iStack_8 = param_1->map_height + -1;
  RGE_Random_Map_Module::clear_stack(param_1);
  uVar7 = param_1->map_height * param_1->map_width;
  puVar10 = param_1->search_map;
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    puVar10[0] = '\0';
    puVar10[1] = '\0';
    puVar10[2] = '\0';
    puVar10[3] = '\0';
    puVar10 = puVar10 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar10 = '\0';
    puVar10 = puVar10 + 1;
  }
  param_1->search_map_rows[param_4][param_3] = '\x03';
  bVar1 = param_1->map_row_offset[*param_6][*param_5].field_0x5;
  param_1->search_map_rows[*param_6][*param_5] = '\x02';
  if (*(float *)(param_7 + (bVar1 & 0x1f) * 4) <= (float)UNK_00571e34._4_4_) {
    return 0;
  }
  iVar11 = *param_6;
  iStack_c = (param_3 - *param_5) * (param_3 - *param_5) + (param_4 - iVar11) * (param_4 - iVar11);
  fStack_14 = SQRT((float)iStack_c);
  if (fStack_14 != (float)(double)UNK_00571e34._12_8_) {
    do {
      if (param_4 < iStack_8) {
        fVar4 = _DAT_00571e4c;
        if (param_4 < iVar11) {
          fVar4 = ram0x00571e48;
        }
        iVar11 = param_4 + 1;
        puVar10 = param_1->search_map_rows[iVar11] + param_3;
        uVar2 = param_1->search_map_rows[iVar11][param_3];
        if (uVar2 == '\0') {
          uVar8 = (byte)param_1->map_row_offset[iVar11][param_3].field_0x5 & 0x1f;
          if (*(float *)(param_7 + uVar8 * 4) <= (float)(double)UNK_00571e34._12_8_) {
            *puVar10 = '\x01';
            bVar12 = false;
          }
          else {
            fVar3 = fStack_10 + *(float *)(param_7 + uVar8 * 4);
            *puVar10 = '\a';
            RGE_Random_Map_Module::push_stack
                      (param_1,param_2,param_3,iVar11,fVar3,fVar3 + (fStack_14 - fVar4));
            bVar12 = true;
          }
        }
        else {
          if (uVar2 == '\x02') {
            param_1->search_map_rows[iVar11][param_3] = '\a';
            *param_5 = param_3;
            *param_6 = iVar11;
            return 1;
          }
          bVar12 = uVar2 != '\x01';
        }
      }
      else {
        bVar12 = false;
      }
      if (param_4 < 1) {
        bVar13 = false;
      }
      else {
        fVar4 = _DAT_00571e4c;
        if (*param_6 < param_4) {
          fVar4 = ram0x00571e48;
        }
        iVar11 = param_4 + -1;
        puVar10 = param_1->search_map_rows[iVar11] + param_3;
        uVar2 = param_1->search_map_rows[iVar11][param_3];
        if (uVar2 == '\0') {
          uVar8 = (byte)param_1->map_row_offset[iVar11][param_3].field_0x5 & 0x1f;
          if (*(float *)(param_7 + uVar8 * 4) <= (float)(double)UNK_00571e34._12_8_) {
            *puVar10 = '\x01';
            bVar13 = false;
          }
          else {
            fVar3 = fStack_10 + *(float *)(param_7 + uVar8 * 4);
            *puVar10 = '\x06';
            RGE_Random_Map_Module::push_stack
                      (param_1,param_2,param_3,iVar11,fVar3,fVar3 + (fStack_14 - fVar4));
            bVar13 = true;
          }
        }
        else {
          if (uVar2 == '\x02') {
            param_1->search_map_rows[iVar11][param_3] = '\x06';
            *param_5 = param_3;
            *param_6 = iVar11;
            return 1;
          }
          bVar13 = uVar2 != '\x01';
        }
      }
      if (0 < param_3) {
        fVar4 = _DAT_00571e4c;
        if (*param_5 < param_3) {
          fVar4 = ram0x00571e48;
        }
        fVar4 = fStack_14 - fVar4;
        iVar11 = param_3 + -1;
        puVar10 = param_1->search_map_rows[param_4] + iVar11;
        uVar2 = param_1->search_map_rows[param_4][iVar11];
        if (uVar2 == '\0') {
          bVar1 = param_1->map_row_offset[param_4][iVar11].field_0x5;
          if (*(float *)(param_7 + (bVar1 & 0x1f) * 4) <= (float)UNK_00571e34._4_4_) {
            *puVar10 = '\x01';
            bVar14 = false;
          }
          else {
            fVar3 = *(float *)(param_7 + (bVar1 & 0x1f) * 4) + fStack_10;
            *puVar10 = '\x04';
            RGE_Random_Map_Module::push_stack(param_1,param_2,iVar11,param_4,fVar3,fVar3 + fVar4);
            bVar14 = true;
          }
        }
        else {
          if (uVar2 == '\x02') {
            param_1->search_map_rows[param_4][iVar11] = '\x04';
            *param_5 = iVar11;
            *param_6 = param_4;
            return 1;
          }
          bVar14 = uVar2 != '\x01';
        }
        if (0 < param_4) {
          iStack_c = param_4 + -1;
          puVar10 = param_1->search_map_rows[iStack_c] + iVar11;
          if (*puVar10 == '\0') {
            uVar8 = (byte)param_1->map_row_offset[iStack_c][iVar11].field_0x5 & 0x1f;
            if (*(float *)(param_7 + uVar8 * 4) <= (float)UNK_00571e34._4_4_) {
              *puVar10 = '\x01';
            }
            else if ((bVar13) && (bVar14)) {
              fVar3 = fStack_10 - *(float *)(param_7 + uVar8 * 4) * _DAT_00571e50;
              *puVar10 = '\b';
              fVar5 = _DAT_00571e58;
              if (*param_6 < param_4) {
                fVar5 = _DAT_00571e54;
              }
              RGE_Random_Map_Module::push_stack
                        (param_1,param_2,iVar11,iStack_c,fVar3,fVar3 + (fVar4 - fVar5));
            }
          }
          else if (*puVar10 == '\x02') {
            param_1->search_map_rows[iStack_c][iVar11] = '\b';
            *param_5 = iVar11;
            *param_6 = iStack_c;
            return 1;
          }
        }
        if (param_4 < iStack_8) {
          iStack_c = param_4 + 1;
          puVar10 = param_1->search_map_rows[iStack_c] + iVar11;
          if (*puVar10 == '\0') {
            uVar8 = (byte)param_1->map_row_offset[iStack_c][iVar11].field_0x5 & 0x1f;
            if (*(float *)(param_7 + uVar8 * 4) <= (float)UNK_00571e34._4_4_) {
              *puVar10 = '\x01';
            }
            else if ((bVar12) && (bVar14)) {
              fVar3 = fStack_10 - *(float *)(param_7 + uVar8 * 4) * _DAT_00571e50;
              *puVar10 = '\t';
              fVar5 = _DAT_00571e58;
              if (param_4 < *param_6) {
                fVar5 = _DAT_00571e54;
              }
              RGE_Random_Map_Module::push_stack
                        (param_1,param_2,iVar11,iStack_c,fVar3,fVar3 + (fVar4 - fVar5));
            }
          }
          else if (*puVar10 == '\x02') {
            param_1->search_map_rows[iStack_c][iVar11] = '\t';
            *param_5 = iVar11;
            *param_6 = iStack_c;
            return 1;
          }
        }
      }
      if (param_3 < iStack_4) {
        fVar4 = _DAT_00571e4c;
        if (param_3 < *param_5) {
          fVar4 = ram0x00571e48;
        }
        fStack_14 = fStack_14 - fVar4;
        iVar11 = param_3 + 1;
        puVar10 = param_1->search_map_rows[param_4] + iVar11;
        uVar2 = param_1->search_map_rows[param_4][iVar11];
        if (uVar2 == '\0') {
          uVar8 = (byte)param_1->map_row_offset[param_4][iVar11].field_0x5 & 0x1f;
          if (*(float *)(param_7 + uVar8 * 4) <= (float)UNK_00571e34._4_4_) {
            *puVar10 = '\x01';
            bVar14 = false;
          }
          else {
            fVar4 = fStack_10 + *(float *)(param_7 + uVar8 * 4);
            *puVar10 = '\x05';
            RGE_Random_Map_Module::push_stack
                      (param_1,param_2,iVar11,param_4,fVar4,fVar4 + fStack_14);
            bVar14 = true;
          }
        }
        else {
          if (uVar2 == '\x02') {
            param_1->search_map_rows[param_4][iVar11] = '\x05';
            *param_5 = iVar11;
            *param_6 = param_4;
            return 1;
          }
          bVar14 = uVar2 != '\x01';
        }
        if (0 < param_4) {
          iStack_c = param_4 + -1;
          puVar10 = param_1->search_map_rows[iStack_c] + iVar11;
          uVar2 = param_1->search_map_rows[iStack_c][iVar11];
          if (uVar2 == '\0') {
            uVar8 = (byte)param_1->map_row_offset[iStack_c][iVar11].field_0x5 & 0x1f;
            if (*(float *)(param_7 + uVar8 * 4) <= (float)UNK_00571e34._4_4_) {
              *puVar10 = '\x01';
            }
            else if ((bVar13) && (bVar14)) {
              fVar4 = fStack_10 - *(float *)(param_7 + uVar8 * 4) * _DAT_00571e50;
              *puVar10 = '\n';
              fVar3 = _DAT_00571e60;
              if (*param_6 < param_4) {
                fVar3 = _DAT_00571e5c;
              }
              RGE_Random_Map_Module::push_stack
                        (param_1,param_2,iVar11,iStack_c,fVar4,fVar4 + (fStack_14 - fVar3));
            }
          }
          else if (uVar2 == '\x02') {
            param_1->search_map_rows[iStack_c][iVar11] = '\n';
            *param_5 = iVar11;
            *param_6 = iStack_c;
            return 1;
          }
        }
        if (param_4 < iStack_8) {
          iVar9 = param_4 + 1;
          uVar2 = param_1->search_map_rows[iVar9][iVar11];
          puVar10 = param_1->search_map_rows[iVar9] + iVar11;
          if (uVar2 == '\0') {
            uVar8 = (byte)param_1->map_row_offset[iVar9][iVar11].field_0x5 & 0x1f;
            if (*(float *)(param_7 + uVar8 * 4) <= (float)UNK_00571e34._4_4_) {
              *puVar10 = '\x01';
            }
            else if ((bVar12) && (bVar14)) {
              fVar4 = fStack_10 - *(float *)(param_7 + uVar8 * 4) * _DAT_00571e50;
              *puVar10 = '\v';
              fVar3 = _DAT_00571e60;
              if (param_4 < *param_6) {
                fVar3 = _DAT_00571e5c;
              }
              RGE_Random_Map_Module::push_stack
                        (param_1,param_2,iVar11,iVar9,fVar4,fVar4 + (fStack_14 - fVar3));
            }
          }
          else if (uVar2 == '\x02') {
            param_1->search_map_rows[iVar9][iVar11] = '\v';
            *param_5 = iVar11;
            *param_6 = iVar9;
            return 1;
          }
        }
      }
      pMVar6 = RGE_Random_Map_Module::pop_stack(param_1,param_2,&param_3,&param_4,&fStack_10);
      if (pMVar6 == (Map_Stack *)0x0) {
        return 0;
      }
      iVar11 = *param_6;
      iStack_c = (param_3 - *param_5) * (param_3 - *param_5) +
                 (param_4 - iVar11) * (param_4 - iVar11);
      fStack_14 = SQRT((float)iStack_c);
    } while (fStack_14 != (float)(double)UNK_00571e34._12_8_);
  }
  if (param_2->next == (Map_Stack *)0x0) {
    return 1;
  }
  param_2->next->prev = (Map_Stack *)0x0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00481972
// Address: 00481972
RGE_Random_Map_Module * __thiscall
FUN_00481972(RGE_Random_Map_Module *param_1,RGE_Map *param_2,RGE_Random_Map_Module *param_3)
{
  int iVar1;
  int *piVar2;
  RGE_Random_Map_Module *pRVar3;
  
  RGE_Random_Map_Module::RGE_Random_Map_Module(param_1,param_2,param_3,'\x01');
  param_1->_padding_ = (int)&RGE_RMM_Cliffs_Generator::_vftable_;
  piVar2 = (int *)&stack0x0000000c;
  pRVar3 = param_1 + 1;
  for (iVar1 = 0x130; iVar1 != 0; iVar1 = iVar1 + -1) {
    pRVar3->_padding_ = *piVar2;
    piVar2 = piVar2 + 1;
    pRVar3 = (RGE_Random_Map_Module *)&pRVar3->parent;
  }
  param_1->schedule = 1.75;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004819bb
// Address: 004819bb
// [HELPER] s_C__msdev_work_age1_x1_rmm_clif_c: "C:\msdev\work\age1_x1\rmm_clif.cpp"
undefined4 __fastcall FUN_004819bb(RGE_RMM_Cliffs_Generator *param_1)
{
  int iVar1;
  int iVar2;
  
  RGE_RMM_Cliffs_Generator::setup_cliff_maps(param_1);
  debug_rand(s_C__msdev_work_age1_x1_rmm_clif_c,0x32);
  iVar1 = (param_1->info).number_of_cliffs;
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      RGE_RMM_Cliffs_Generator::generate_cliff(param_1);
      iVar1 = (param_1->info).number_of_cliffs;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_004819f5
// Address: 004819f5
void __fastcall FUN_004819f5(RGE_RMM_Cliffs_Generator *param_1)
{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  byte bVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  long *plVar13;
  int iVar14;
  undefined4 *puVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  int iStack_2c;
  int iStack_28;
  int iStack_20;
  int iStack_1c;
  int iStack_10;
  int iStack_c;
  
  iVar5 = param_1->_padding_ / 3;
  iVar6 = param_1->_padding_ / 3;
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)param_1);
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)param_1,&param_1->valid_cliff_sites);
  uVar10 = param_1->_padding_ * param_1->_padding_;
  puVar15 = (undefined4 *)param_1->_padding_;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *puVar15 = 0x1010101;
    puVar15 = puVar15 + 1;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined1 *)puVar15 = 1;
    puVar15 = (undefined4 *)((int)puVar15 + 1);
  }
  iStack_28 = 0;
  if (0 < iVar6) {
    iStack_1c = 0;
    do {
      iStack_2c = 0;
      if (0 < iVar5) {
        iStack_20 = 0;
        do {
          uVar11 = 0xffffffff;
          bVar4 = true;
          bVar7 = false;
          piVar16 = (int *)(iStack_1c + param_1->_padding_);
          iStack_c = 3;
          do {
            iStack_10 = 3;
            pbVar12 = (byte *)(*piVar16 + 5 + iStack_20);
            do {
              bVar8 = *pbVar12 & 0x1f;
              if ((bVar8 == 0) || (bVar8 == 6)) {
                bVar8 = *pbVar12 >> 5;
                if ((int)uVar11 < 0) {
                  uVar11 = (uint)bVar8;
                }
                else if (uVar11 != bVar8) {
                  bVar4 = false;
                }
              }
              else {
                bVar4 = false;
                if (((bVar8 == 1) || (bVar8 == 4)) || (bVar8 == 0x16)) {
                  bVar7 = true;
                }
              }
              pbVar12 = pbVar12 + 0x18;
              iStack_10 = iStack_10 + -1;
            } while (iStack_10 != 0);
            piVar16 = piVar16 + 1;
            iStack_c = iStack_c + -1;
          } while (iStack_c != 0);
          if (bVar4) {
            pcVar9 = (char *)(*(int *)(param_1->_padding_ + iStack_28 * 4) + iStack_2c);
            if (*pcVar9 != '\0') {
              *pcVar9 = (char)uVar11 + '\x01';
              RGE_Random_Map_Module::push_stack
                        ((RGE_Random_Map_Module *)param_1,&param_1->valid_cliff_sites,iStack_2c,
                         iStack_28,0.0,0.0);
            }
          }
          else {
            if (bVar7) {
              RGE_RMM_Cliffs_Generator::invalidate_cliff_area
                        (param_1,iStack_2c,iStack_28,(param_1->info).cliff_terrain_spacing);
            }
            *(undefined1 *)(*(int *)(param_1->_padding_ + iStack_28 * 4) + iStack_2c) = 0;
          }
          iStack_2c = iStack_2c + 1;
          iStack_20 = iStack_20 + 0x48;
        } while (iStack_2c < iVar5);
      }
      iStack_28 = iStack_28 + 1;
      iStack_1c = iStack_1c + 0xc;
    } while (iStack_28 < iVar6);
  }
  iVar17 = 0;
  if (0 < (param_1->info).hot_spot_num) {
    plVar13 = &(param_1->info).hot_spots[0].y;
    do {
      RGE_RMM_Cliffs_Generator::invalidate_cliff_area
                (param_1,((RGE_Cliffs_Hot_Spots *)(plVar13 + -1))->x / 3,*plVar13 / 3,
                 plVar13[1] / 3 + 2);
      iVar17 = iVar17 + 1;
      plVar13 = plVar13 + 3;
    } while (iVar17 < (param_1->info).hot_spot_num);
  }
  iVar17 = 0;
  if (0 < iVar6) {
    do {
      iVar14 = 0;
      if (0 < iVar5) {
        iVar18 = 0;
        do {
          iVar2 = param_1->_padding_;
          iVar3 = *(int *)(iVar2 + iVar17 * 4);
          puVar1 = (undefined1 *)(iVar14 + iVar3);
          if ((((*(char *)(iVar14 + iVar3) != '\0') &&
               ((iVar17 < 1 || (*(char *)(*(int *)(iVar2 + -4 + iVar17 * 4) + iVar14) == '\0')))) &&
              ((iVar18 < 1 || (puVar1[-1] == '\0')))) &&
             (((iVar6 + -1 <= iVar17 ||
               (*(char *)(*(int *)(iVar2 + 4 + iVar17 * 4) + iVar14) == '\0')) &&
              ((iVar5 + -1 <= iVar14 || (puVar1[1] == '\0')))))) {
            *puVar1 = 0;
            RGE_Random_Map_Module::remove_stack_node
                      ((RGE_Random_Map_Module *)param_1,
                       (Map_Stack *)(*(int *)(param_1->_padding_ + iVar17 * 4) + iVar18));
          }
          iVar14 = iVar14 + 1;
          iVar18 = iVar18 + 0x18;
        } while (iVar14 < iVar5);
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 < iVar6);
  }
  RGE_Random_Map_Module::randomize_stack
            ((RGE_Random_Map_Module *)param_1,&param_1->valid_cliff_sites);
  return;
}

// --------------------------------------------------

// Function: FUN_00481cc2
// Address: 00481cc2
// [HELPER] s_C__msdev_work_age1_x1_rmm_clif_c: "C:\msdev\work\age1_x1\rmm_clif.cpp"
void __fastcall FUN_00481cc2(RGE_RMM_Cliffs_Generator *param_1)
{
  bool bVar1;
  bool bVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  int iVar7;
  int iStack_30;
  int iStack_2c;
  uint uStack_28;
  int iStack_24;
  int iStack_20;
  float fStack_1c;
  Map_Stack MStack_18;
  
  iVar6 = -1;
  iVar5 = (param_1->info).cliff_size_variance;
  iVar7 = -1;
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_clif_c,0xc4);
  bVar1 = true;
  iStack_20 = ((iVar4 * iVar5 * 2) / 0x7fff + (param_1->info).average_cliff_size) - iVar5;
  if ((param_1->valid_cliff_sites).next == (Map_Stack *)0x0) {
    return;
  }
  if (iStack_20 < 3) {
    return;
  }
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)param_1,&MStack_18);
  while (RGE_Random_Map_Module::pop_stack
                   ((RGE_Random_Map_Module *)param_1,&param_1->valid_cliff_sites,&iStack_30,
                    &iStack_2c,&fStack_1c),
        *(char *)(*(int *)(param_1->_padding_ + iStack_2c * 4) + iStack_30) == '\0') {
    if ((param_1->valid_cliff_sites).next == (Map_Stack *)0x0) {
      return;
    }
  }
  uStack_28 = (uint)*(byte *)(*(int *)(param_1->_padding_ + iStack_2c * 4) + iStack_30);
  RGE_Random_Map_Module::push_stack
            ((RGE_Random_Map_Module *)param_1,&MStack_18,iStack_30,iStack_2c,0.0,0.0);
  *(undefined1 *)(*(int *)(param_1->_padding_ + iStack_2c * 4) + iStack_30) = 0;
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_clif_c,0xdd);
  iVar5 = (iVar5 * 4) / 0x7fff;
  iStack_24 = 0;
  if (0 < iStack_20) {
    do {
      bVar2 = false;
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_clif_c,0xe3);
      iVar4 = (iVar4 * 100) / 0x7fff;
      if (iVar4 < 0x12) {
        if (iVar5 < 1) {
          iVar5 = 3;
        }
        else {
          iVar5 = iVar5 + -1;
        }
      }
      else if (iVar4 < 0x24) {
        if (iVar5 < 3) {
          iVar5 = iVar5 + 1;
        }
        else {
          iVar5 = 0;
        }
      }
      uVar3 = RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site
                        (param_1,iVar5,&iStack_30,&iStack_2c,uStack_28);
      if ((((uVar3 == '\0') &&
           (uVar3 = RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site
                              (param_1,iVar5 + 1,&iStack_30,&iStack_2c,uStack_28), uVar3 == '\0'))
          && (uVar3 = RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site
                                (param_1,iVar5 + -1,&iStack_30,&iStack_2c,uStack_28), uVar3 == '\0')
          ) && ((!bVar1 ||
                (uVar3 = RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site
                                   (param_1,iVar5 + -2,&iStack_30,&iStack_2c,uStack_28),
                uVar3 == '\0')))) {
        bVar2 = true;
      }
      bVar1 = false;
      if (bVar2) break;
      RGE_Random_Map_Module::push_stack
                ((RGE_Random_Map_Module *)param_1,&MStack_18,iStack_30,iStack_2c,0.0,0.0);
      *(undefined1 *)(*(int *)(param_1->_padding_ + iStack_2c * 4) + iStack_30) = 0;
      iStack_24 = iStack_24 + 1;
    } while (iStack_24 < iStack_20);
  }
  while (MStack_18.next != (Map_Stack *)0x0) {
    RGE_Random_Map_Module::pop_stack
              ((RGE_Random_Map_Module *)param_1,&MStack_18,&iStack_30,&iStack_2c,&fStack_1c);
    if (iVar6 == -1) {
      iVar6 = iStack_30;
      iVar7 = iStack_2c;
    }
    iVar4 = 0x10;
    iVar5 = iVar7 * 3 + 1;
    iVar6 = iVar6 * 3 + 1;
    (**(code **)(*(int *)param_1->_padding_ + 0x10))
              (iVar6,iVar5,iStack_30 * 3 + 1,iStack_2c * 3 + 1,1,0x10);
    (**(code **)(*(int *)param_1->_padding_ + 0x20))
              (iVar6,iVar5,iVar4 * 3 + 1,unaff_EDI * 3 + 1,0,0);
    iVar7 = iStack_2c;
    iVar6 = iStack_30;
    RGE_RMM_Cliffs_Generator::invalidate_cliff_area
              (param_1,iStack_30,iStack_2c,(param_1->info).cliff_to_cliff_spacing);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00481fbf
// Address: 00481fbf
undefined4 __thiscall FUN_00481fbf(int param_1,int param_2,int *param_3,int *param_4,uint param_5)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_4;
  iVar3 = *param_3;
  if (3 < param_2) {
    uVar1 = (param_2 - 1U) / 3;
    do {
      param_2 = param_2 + -3;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  if (param_2 < 0) {
    param_2 = ((2U - param_2) / 3) * 3 + param_2;
  }
  switch(param_2) {
  case 0:
    if (iVar2 < 1) {
      return 0;
    }
    iVar2 = iVar2 + -1;
    break;
  case 1:
    if (*(int *)(param_1 + 0x14) / 3 + -1 <= iVar3) {
      return 0;
    }
    iVar3 = iVar3 + 1;
    break;
  case 2:
    if (*(int *)(param_1 + 0x18) / 3 + -1 <= iVar2) {
      return 0;
    }
    iVar2 = iVar2 + 1;
    break;
  case 3:
    if (iVar3 < 1) {
      return 0;
    }
    iVar3 = iVar3 + -1;
  }
  if (*(byte *)(*(int *)(*(int *)(param_1 + 0x24) + iVar2 * 4) + iVar3) != param_5) {
    return 0;
  }
  *param_3 = iVar3;
  *param_4 = iVar2;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00482081
// Address: 00482081
/* WARNING: Unable to track spacebase fully for stack */

void __fastcall FUN_00482081(RGE_Random_Map_Module *param_1,char *param_2)
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *in_EAX;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_EBX;
  int iVar8;
  undefined4 unaff_EBP;
  int iVar9;
  int unaff_ESI;
  int iVar10;
  undefined4 unaff_EDI;
  byte in_CF;
  int aiStack_20 [8];
  
  uVar4 = (uint)in_CF;
  iVar2 = *in_EAX;
  pbVar5 = (byte *)((int)in_EAX + -1);
  *param_2 = *param_2 + (char)unaff_EBX;
  *pbVar5 = *pbVar5 & (byte)param_1;
  *(char *)(unaff_ESI + 0x20) = *(char *)(unaff_ESI + 0x20) + (byte)param_1;
  pcVar1 = (char *)(((uint)pbVar5 ^ 0x20) + 0x9090908e);
  *pcVar1 = *pcVar1 + (char)param_2;
  *(undefined4 *)((int)aiStack_20 + uVar4 + iVar2 + 0x14) = unaff_EBX;
  *(undefined4 *)((int)aiStack_20 + uVar4 + iVar2 + 0x10) = unaff_EBP;
  *(int *)((int)aiStack_20 + uVar4 + iVar2 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)aiStack_20 + uVar4 + iVar2 + 8) = unaff_EDI;
  iVar8 = *(int *)(&stack0x00000004 + uVar4 + iVar2);
  iVar10 = *(int *)(&stack0x00000008 + uVar4 + iVar2);
  *(int *)((int)aiStack_20 + uVar4 + iVar2 + 0x18) = param_1->map_width / 3 + -1;
  iVar9 = *(int *)(&stack0x0000000c + uVar4 + iVar2);
  *(int *)((int)aiStack_20 + uVar4 + iVar2 + 0x1c) = param_1->map_height / 3 + -1;
  iVar6 = iVar8 - iVar9;
  iVar7 = iVar10 - iVar9;
  iVar8 = iVar9 + iVar8;
  *(int *)(&stack0x0000000c + uVar4 + iVar2) = iVar6;
  *(int *)(&stack0x00000004 + uVar4 + iVar2) = iVar8;
  if (iVar6 < 0) {
    *(undefined4 *)(&stack0x0000000c + uVar4 + iVar2) = 0;
    iVar6 = *(int *)(&stack0x0000000c + uVar4 + iVar2);
  }
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  iVar3 = *(int *)((int)aiStack_20 + uVar4 + iVar2 + 0x18);
  if (iVar3 < iVar8) {
    *(int *)(&stack0x00000004 + uVar4 + iVar2) = iVar3;
    iVar8 = iVar3;
  }
  iVar3 = *(int *)((int)aiStack_20 + uVar4 + iVar2 + 0x1c);
  iVar10 = iVar9 + iVar10;
  if (iVar3 < iVar8) {
    iVar10 = iVar3;
  }
  if (iVar7 <= iVar10) {
    iVar9 = iVar7 * 4;
    *(int *)(&stack0x00000008 + uVar4 + iVar2) = (iVar10 - iVar7) + 1;
    do {
      if (iVar6 <= iVar8) {
        iVar7 = iVar6 * 0x18;
        iVar10 = iVar6;
        do {
          iVar8 = *(int *)((int)param_1->search_map_rows + iVar9);
          if (*(char *)(iVar10 + iVar8) != '\0') {
            *(undefined1 *)(iVar10 + iVar8) = 0;
            *(int *)((int)aiStack_20 + uVar4 + iVar2 + 4) =
                 *(int *)((int)param_1->stack_offsets + iVar9) + iVar7;
            *(undefined4 *)((int)aiStack_20 + uVar4 + iVar2) = 0x482169;
            RGE_Random_Map_Module::remove_stack_node
                      (param_1,*(Map_Stack **)((int)aiStack_20 + uVar4 + iVar2 + 4));
            iVar6 = *(int *)(&stack0x0000000c + uVar4 + iVar2);
          }
          iVar8 = *(int *)(&stack0x00000004 + uVar4 + iVar2);
          iVar10 = iVar10 + 1;
          iVar7 = iVar7 + 0x18;
        } while (iVar10 <= iVar8);
      }
      iVar10 = *(int *)(&stack0x00000008 + uVar4 + iVar2);
      iVar9 = iVar9 + 4;
      *(int *)(&stack0x00000008 + uVar4 + iVar2) = iVar10 + -1;
    } while (iVar10 + -1 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00482193
// Address: 00482193
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

RGE_Random_Map_Module * __thiscall
FUN_00482193(RGE_Random_Map_Module *param_1,RGE_Map *param_2,RGE_Game_World *param_3,uint param_4,
            long param_5)
{
  undefined4 *unaff_FS_OFFSET;
  RGE_Terrain_Info RStack_26dc;
  RGE_Land_Info RStack_1444;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e5db;
  *unaff_FS_OFFSET = &uStack_c;
  RStack_1444.wall_fade = 0xbf;
  RStack_1444._5173_3_ = 0x4821;
  RGE_Random_Map_Module::RGE_Random_Map_Module(param_1,param_2,(RGE_Random_Map_Module *)0x0,'\x01');
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_RMM_Controller::_vftable_;
  RGE_RMM_Controller::add_land_module
            ((RGE_RMM_Controller *)param_1,&RStack_1444,param_4 & 0xff,param_5);
  RGE_RMM_Controller::add_terrain_module
            ((RGE_RMM_Controller *)param_1,&RStack_26dc,&RStack_1444,param_4 & 0xff);
  RGE_RMM_Controller::add_object_module((RGE_RMM_Controller *)param_1,param_3,&RStack_1444);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00482255
// Address: 00482255
// [HELPER] s_C__msdev_work_age1_x1_rmm_base_c: "C:\msdev\work\age1_x1\rmm_base.cpp"
// [HELPER] s_RGE_RANDOM_MAP_MODULE__map_start: "RGE_RANDOM_MAP_MODULE::map startped with random: %d."
// [HELPER] s_RGE_RANDOM_MAP_MODULE__module_co: "RGE_RANDOM_MAP_MODULE::module completed with random: %d."
undefined4 __fastcall FUN_00482255(int param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  TDebuggingLog *this;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float fVar8;
  float fVar9;
  
  puVar2 = (undefined4 *)0x0;
  puVar7 = *(undefined4 **)(param_1 + 8);
joined_r0x004808e4:
  do {
    puVar3 = puVar7;
    if (puVar3 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 8) = puVar2;
      iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_base_c,0x8a);
      TDebuggingLog::Log(this,(char *)L,s_RGE_RANDOM_MAP_MODULE__map_start,iVar5);
      puVar7 = *(undefined4 **)(param_1 + 8);
      if (puVar7 == (undefined4 *)0x0) {
        return 1;
      }
      do {
        cVar4 = (*(code *)**(undefined4 **)*puVar7)();
        if (cVar4 == '\0') {
          return 0;
        }
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_base_c,0x8f);
        TDebuggingLog::Log(L,(char *)L,s_RGE_RANDOM_MAP_MODULE__module_co,iVar5);
        puVar7 = (undefined4 *)puVar7[1];
      } while (puVar7 != (undefined4 *)0x0);
      return 1;
    }
    puVar7 = (undefined4 *)puVar3[1];
    if (puVar2 != (undefined4 *)0x0) {
      fVar8 = RGE_Random_Map_Module::get_schedule((RGE_Random_Map_Module *)*puVar3);
      fVar9 = RGE_Random_Map_Module::get_schedule((RGE_Random_Map_Module *)*puVar2);
      puVar6 = puVar2;
      if (fVar9 <= fVar8) {
        do {
          if (puVar6[1] == 0) {
LAB_0048093c:
            puVar3[1] = puVar6[1];
            puVar6[1] = puVar3;
            break;
          }
          fVar8 = RGE_Random_Map_Module::get_schedule((RGE_Random_Map_Module *)*puVar3);
          fVar9 = RGE_Random_Map_Module::get_schedule(*(RGE_Random_Map_Module **)puVar6[1]);
          if (fVar8 < fVar9) goto LAB_0048093c;
          puVar1 = puVar6 + 1;
          puVar6 = (undefined4 *)*puVar1;
        } while ((undefined4 *)*puVar1 != (undefined4 *)0x0);
        goto joined_r0x004808e4;
      }
    }
    puVar3[1] = puVar2;
    puVar2 = puVar3;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00482265
// Address: 00482265
// [HELPER] s_C__msdev_work_age1_x1_rmm_cntr_c: "C:\msdev\work\age1_x1\rmm_cntr.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00482265(RGE_Random_Map_Module *param_1,RGE_Land_Info *param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  RGE_RMM_Land_Generator *this;
  int iVar10;
  long *plVar11;
  long *plVar12;
  undefined4 *unaff_FS_OFFSET;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e5fb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_2->land_num = param_4;
  switch(param_3) {
  case 0:
    param_2->base_terrain = '\x01';
    param_2->wall_1_avoidance_line = 8;
    param_2->wall_2_avoidance_line = 8;
    iVar5 = 0x1e;
    param_2->wall_3_avoidance_line = param_1->map_width + -9;
    iVar1 = param_1->map_height;
    param_2->wall_fade = '\x14';
    param_2->wall_4_avoidance_line = iVar1 + -9;
    break;
  case 1:
    param_2->base_terrain = '\x01';
    param_2->wall_1_avoidance_line = 6;
    param_2->wall_2_avoidance_line = 6;
    iVar5 = 0x32;
    param_2->wall_3_avoidance_line = param_1->map_width + -7;
    iVar1 = param_1->map_height;
    param_2->wall_fade = '\x14';
    param_2->wall_4_avoidance_line = iVar1 + -7;
    break;
  case 2:
    param_2->base_terrain = '\x01';
    param_2->wall_1_avoidance_line = 4;
    param_2->wall_2_avoidance_line = 4;
    iVar5 = 0x46;
    param_2->wall_3_avoidance_line = param_1->map_width + -5;
    iVar1 = param_1->map_height;
    param_2->wall_fade = '\"';
    param_2->wall_4_avoidance_line = iVar1 + -5;
    break;
  case 3:
    param_2->base_terrain = '\x01';
    iVar5 = 0x5a;
    param_2->wall_1_avoidance_line = 0;
    param_2->wall_2_avoidance_line = 0;
    param_2->wall_3_avoidance_line = 0;
    param_2->wall_4_avoidance_line = 0;
    param_2->wall_fade = '\0';
    break;
  default:
    iVar5 = 0;
    param_2->base_terrain = '\0';
    param_2->wall_1_avoidance_line = 0;
    param_2->wall_2_avoidance_line = 0;
    param_2->wall_3_avoidance_line = 0;
    param_2->wall_4_avoidance_line = 0;
    param_2->wall_fade = '\0';
  }
  iVar1 = param_1->map_height;
  iVar2 = param_1->map_width;
  fVar3 = ((float)(iVar2 + -0x10) / SQRT((float)param_4)) * (float)_DAT_00571e70;
  iStack_38 = __ftol();
  iStack_30 = __ftol();
  iStack_34 = __ftol();
  iVar6 = __ftol();
  if (iStack_38 < 9) {
    iStack_38 = 9;
  }
  if (iStack_30 < 9) {
    iStack_30 = 9;
  }
  if (iVar2 + -9 <= iStack_34) {
    iStack_34 = iVar2 + -10;
  }
  if (param_1->map_height + -9 <= iVar6) {
    iVar6 = param_1->map_height + -10;
  }
  iStack_3c = 0;
  if (0 < param_4) {
    plVar12 = &param_2->land[0].area;
    do {
      switch(param_3) {
      case 0:
        plVar12[-4] = 0;
        *plVar12 = 7;
        goto LAB_0048251c;
      case 1:
        plVar12[-4] = 0;
        *plVar12 = 4;
LAB_0048251c:
        plVar12[-1] = 5;
        *(uchar *)(plVar12 + 1) = (uchar)iStack_3c;
        break;
      case 2:
      case 3:
      case 4:
        plVar12[-4] = 0;
        *plVar12 = 3;
        plVar12[-1] = 5;
        *(uchar *)(plVar12 + 1) = '\0';
      }
      do {
        bVar4 = false;
        iVar7 = debug_rand(s_C__msdev_work_age1_x1_rmm_cntr_c,0xd1);
        iVar7 = (iVar7 * (param_1->map_width + -0x10)) / 0x7fff + 8;
        iVar8 = debug_rand(s_C__msdev_work_age1_x1_rmm_cntr_c,0xd2);
        iVar8 = (iVar8 * (param_1->map_height + -0x10)) / 0x7fff + 8;
        if ((((iStack_38 < iVar7) && (iVar7 < iStack_34)) && (iStack_30 < iVar8)) && (iVar8 < iVar6)
           ) {
          bVar4 = true;
        }
        else {
          iStack_2c = 0;
          if (0 < iStack_3c) {
            plVar11 = &param_2->land[0].x;
            do {
              iVar10 = iVar7 - *plVar11;
              if (iVar10 < 0) {
                iVar10 = -iVar10;
              }
              iVar9 = iVar8 - plVar11[1];
              if (iVar9 < 0) {
                iVar9 = -iVar9;
              }
              if ((float)(iVar10 * iVar10 + iVar9 * iVar9) <= fVar3 * fVar3) {
                if ((!bVar4) && (iStack_2c == iStack_3c + -1)) {
                  plVar11[1] = iVar8;
                  *plVar11 = iVar7;
                }
                bVar4 = true;
              }
              iStack_2c = iStack_2c + 1;
              plVar11 = plVar11 + 0xd;
            } while (iStack_2c < iStack_3c);
          }
        }
      } while (bVar4);
      plVar12[-3] = iVar7;
      plVar12[-2] = iVar8;
      ((RGE_Land_Info_Line *)(plVar12 + -5))->land_size =
           ((iVar5 * iVar1 * iVar2) / 100) / param_2->land_num;
      iStack_3c = iStack_3c + 1;
      plVar12 = plVar12 + 0xd;
    } while (iStack_3c < param_2->land_num);
  }
  this = (RGE_RMM_Land_Generator *)operator_new(0x1468);
  uStack_4 = 0;
  if (this != (RGE_RMM_Land_Generator *)0x0) {
    RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(this,param_1->map,param_1,param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004826b2
// Address: 004826b2
void __fastcall
FUN_004826b2(uint param_1,int param_2,RGE_Terrain_Info *param_3,int param_4,undefined4 param_5)
{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int in_EAX;
  char *pcVar6;
  long *plVar7;
  RGE_RMM_Terrain_Generator *this;
  RGE_Random_Map_Module *pRVar8;
  long *plVar9;
  int iVar10;
  undefined4 *unaff_FS_OFFSET;
  int in_GS_OFFSET;
  byte in_AF;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  char cVar4;
  uint *puVar5;
  
  bVar2 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  bVar3 = (byte)in_EAX + bVar2 * '\x06';
  cVar4 = bVar3 + (0x90 < (bVar3 & 0xf0) | bVar2 * (0xf9 < bVar3)) * '`';
  puVar5 = (uint *)CONCAT31((int3)((uint)in_EAX >> 8),cVar4);
  pRVar8 = (RGE_Random_Map_Module *)(param_1 & *(uint *)(in_GS_OFFSET + in_EAX) & *puVar5);
  out(0x22,cVar4);
  cVar4 = (char)((uint)param_2 >> 8);
  *(char *)(param_2 + 0x25130048) = *(char *)(param_2 + 0x25130048) + cVar4;
  pcVar6 = (char *)((int)puVar5 + -2);
  *pcVar6 = *pcVar6 + (char)pRVar8;
  pcVar6 = (char *)((((uint)pcVar6 & 0x24f20048) - 1 & 0xffffff48) + 0x90909090);
  *pcVar6 = *pcVar6 + (char)param_2 + cVar4 * '\x02';
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e61b;
  *unaff_FS_OFFSET = &uStack_c;
  param_3->terrain_num = 2;
  switch(param_5) {
  case 0:
  case 1:
  case 2:
    iVar1 = pRVar8->map_height;
    iVar10 = pRVar8->map_width;
    param_3->terrain[0].terrain_type = 10;
    param_3->terrain[0].clumps = 0x14;
    param_3->terrain[0].base_terrain_type = 0;
    param_3->terrain[0].terrain_generated = 0;
    param_3->terrain[0].terrain_size = (iVar1 * iVar10 * 0x14) / 100;
    param_3->terrain[0].spacing = 2;
    iVar1 = pRVar8->map_height;
    iVar10 = pRVar8->map_width;
    param_3->terrain[1].terrain_type = 6;
    param_3->terrain[1].clumps = 7;
    param_3->terrain[1].terrain_size = (iVar1 * iVar10 * 0x1e) / 100;
    break;
  case 3:
  case 4:
    iVar1 = pRVar8->map_height;
    iVar10 = pRVar8->map_width;
    param_3->terrain[0].terrain_type = 10;
    param_3->terrain[0].clumps = 0x1e;
    param_3->terrain[0].base_terrain_type = 0;
    param_3->terrain[0].terrain_generated = 0;
    param_3->terrain[0].terrain_size = (iVar1 * iVar10 * 0x14) / 100;
    param_3->terrain[0].spacing = 2;
    iVar1 = pRVar8->map_height;
    iVar10 = pRVar8->map_width;
    param_3->terrain[1].terrain_type = 6;
    param_3->terrain[1].clumps = 0x11;
    param_3->terrain[1].terrain_size = (iVar1 * iVar10 * 0x1e) / 100;
    break;
  default:
    goto switchD_00482719_default;
  }
  param_3->terrain[1].base_terrain_type = 0;
  param_3->terrain[1].terrain_generated = 0;
  param_3->terrain[1].spacing = 0;
switchD_00482719_default:
  iVar10 = 0;
  iVar1 = *(int *)(param_4 + 0x141c);
  param_3->hot_spot_num = iVar1;
  if (0 < iVar1) {
    plVar7 = &param_3->hot_spots[0].y;
    plVar9 = (long *)(param_4 + 0xc);
    do {
      iVar10 = iVar10 + 1;
      ((RGE_Terrain_Hot_Spots *)(plVar7 + -1))->x = plVar9[-1];
      *plVar7 = *plVar9;
      plVar7[1] = 0xc;
      plVar7[2] = 0x14;
      plVar9 = plVar9 + 0xd;
      plVar7 = plVar7 + 4;
    } while (iVar10 < param_3->hot_spot_num);
  }
  this = (RGE_RMM_Terrain_Generator *)operator_new(0x12cc);
  uStack_4 = 0;
  if (this != (RGE_RMM_Terrain_Generator *)0x0) {
    RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(this,pRVar8->map,pRVar8,param_3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0048287e
// Address: 0048287e
int __fastcall FUN_0048287e(int param_1,int param_2)
{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar7;
  undefined4 in_EAX;
  int iVar5;
  byte *pbVar6;
  undefined1 *unaff_EDI;
  byte in_AF;
  
  iVar5 = CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(*unaff_EDI,(char)in_EAX)) + -1;
  pbVar6 = (byte *)(param_2 + -0x75ffb7d9);
  bVar2 = *pbVar6;
  *pbVar6 = *pbVar6 + (byte)param_1;
  bVar4 = (byte)iVar5;
  bVar3 = 9 < (bVar4 & 0xf) | in_AF;
  bVar4 = bVar4 + bVar3 * '\x06';
  pbVar6 = (byte *)(CONCAT31((int3)((uint)iVar5 >> 8),
                             bVar4 + (0x90 < (bVar4 & 0xf0) |
                                     CARRY1(bVar2,(byte)param_1) | bVar3 * (0xf9 < bVar4)) * '`') +
                   -1);
  bVar2 = *pbVar6;
  bVar7 = (byte)((uint)pbVar6 >> 8);
  *pbVar6 = *pbVar6 + bVar7;
  bVar3 = 9 < ((byte)pbVar6 & 0xf) | bVar3;
  bVar4 = (byte)pbVar6 + bVar3 * '\x06';
  pbVar6 = (byte *)(CONCAT31((int3)((uint)pbVar6 >> 8),
                             bVar4 + (0x90 < (bVar4 & 0xf0) |
                                     CARRY1(bVar2,bVar7) | bVar3 * (0xf9 < bVar4)) * '`') + -1);
  bVar2 = *pbVar6;
  bVar7 = (byte)((uint)pbVar6 >> 8);
  *pbVar6 = *pbVar6 + bVar7;
  bVar3 = 9 < ((byte)pbVar6 & 0xf) | bVar3;
  bVar4 = (byte)pbVar6 + bVar3 * '\x06';
  pcVar1 = (char *)(CONCAT31((int3)((uint)pbVar6 >> 8),
                             bVar4 + (0x90 < (bVar4 & 0xf0) |
                                     CARRY1(bVar2,bVar7) | bVar3 * (0xf9 < bVar4)) * '`') +
                   -0x6f6f6f71);
  *pcVar1 = *pcVar1 + (char)param_2;
  return *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x18);
}

// --------------------------------------------------

// Function: FUN_004828aa
// Address: 004828aa
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_004828aa(RGE_Random_Map_Module *param_1,RGE_Game_World *param_2,int param_3)
{
  int iVar1;
  long *plVar2;
  RGE_RMM_Object_Generator *this;
  int iVar3;
  long *plVar4;
  undefined4 *unaff_FS_OFFSET;
  RGE_Object_Info RStack_18d4;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055e63e;
  *unaff_FS_OFFSET = &uStack_c;
  RStack_18d4.object_num = 6;
  RStack_18d4.objects[1].land_outer_radius = 4;
  RStack_18d4.objects[2].object_number_per_group = 6;
  RStack_18d4.objects[3].object_number_per_group = 6;
  RStack_18d4.objects[3].group_area = 4;
  RStack_18d4.objects[4].object_number_per_group = 6;
  RStack_18d4.objects[0].obj_id = 0x6d;
  RStack_18d4.objects[0].terrain = 0;
  RStack_18d4.objects[0].group_flag = '\0';
  RStack_18d4.objects[0].scale_flag = '\0';
  RStack_18d4.objects[0].object_number_per_group = 1;
  RStack_18d4.objects[0].object_number_varience = 0;
  RStack_18d4.objects[0].number_of_groups = 1;
  RStack_18d4.objects[0].player_id = -1;
  RStack_18d4.objects[0].land_id = 0;
  RStack_18d4.objects[0].land_inner_radius = 0;
  RStack_18d4.objects[0].land_outer_radius = 0;
  RStack_18d4.objects[1].obj_id = 0x53;
  RStack_18d4.objects[1].terrain = 0;
  RStack_18d4.objects[1].group_flag = '\0';
  RStack_18d4.objects[1].scale_flag = '\0';
  RStack_18d4.objects[1].object_number_per_group = 1;
  RStack_18d4.objects[1].object_number_varience = 0;
  RStack_18d4.objects[1].number_of_groups = 3;
  RStack_18d4.objects[1].player_id = -1;
  RStack_18d4.objects[1].land_id = 0;
  RStack_18d4.objects[1].land_inner_radius = 2;
  RStack_18d4.objects[2].obj_id = 0x41;
  RStack_18d4.objects[2].terrain = 0;
  RStack_18d4.objects[2].group_flag = '\x01';
  RStack_18d4.objects[2].scale_flag = '\x01';
  RStack_18d4.objects[2].object_number_varience = 3;
  RStack_18d4.objects[2].number_of_groups = 10;
  RStack_18d4.objects[2].group_area = 3;
  RStack_18d4.objects[2].player_id = 0;
  RStack_18d4.objects[2].land_id = -1;
  RStack_18d4.objects[2].land_inner_radius = -1;
  RStack_18d4.objects[2].land_outer_radius = -1;
  RStack_18d4.objects[3].obj_id = 0x66;
  RStack_18d4.objects[3].terrain = -1;
  RStack_18d4.objects[3].group_flag = '\x02';
  RStack_18d4.objects[3].scale_flag = '\0';
  RStack_18d4.objects[3].object_number_varience = 2;
  RStack_18d4.objects[3].number_of_groups = 1;
  RStack_18d4.objects[3].player_id = 0;
  RStack_18d4.objects[3].land_id = 0;
  RStack_18d4.objects[3].land_inner_radius = 9;
  RStack_18d4.objects[3].land_outer_radius = 0xf;
  RStack_18d4.objects[4].obj_id = 0x42;
  RStack_18d4.objects[4].terrain = -1;
  RStack_18d4.objects[4].group_flag = '\x02';
  RStack_18d4.objects[4].scale_flag = '\0';
  RStack_18d4.objects[4].object_number_varience = 2;
  RStack_18d4.objects[4].number_of_groups = 1;
  RStack_18d4.objects[4].group_area = 4;
  RStack_18d4.objects[4].player_id = 0;
  RStack_18d4.objects[4].land_id = 0;
  RStack_18d4.objects[4].land_inner_radius = 9;
  RStack_18d4.objects[4].land_outer_radius = 0xf;
  RStack_18d4.objects[5].obj_id = 0x3b;
  RStack_18d4.objects[5].terrain = -1;
  RStack_18d4.objects[5].group_area = 3;
  RStack_18d4.objects[5].land_inner_radius = 9;
  RStack_18d4.objects[5].object_number_varience = 2;
  iVar1 = *(int *)(param_3 + 0x141c);
  iVar3 = 0;
  RStack_18d4.objects[5].group_flag = '\x01';
  RStack_18d4.objects[5].scale_flag = '\0';
  RStack_18d4.objects[5].object_number_per_group = 5;
  RStack_18d4.objects[5].number_of_groups = 1;
  RStack_18d4.objects[5].player_id = 0;
  RStack_18d4.objects[5].land_id = 0;
  RStack_18d4.objects[5].land_outer_radius = 0xf;
  RStack_18d4.land_num = iVar1;
  if (0 < iVar1) {
    plVar2 = &RStack_18d4.lands[0].y;
    plVar4 = (long *)(param_3 + 0xc);
    do {
      iVar3 = iVar3 + 1;
      ((RGE_Land_Point_Info_Line *)(plVar2 + -1))->x = plVar4[-1];
      *plVar2 = *plVar4;
      plVar2[1] = 0;
      plVar2[2] = iVar3;
      plVar4 = plVar4 + 0xd;
      plVar2 = plVar2 + 4;
    } while (iVar3 < iVar1);
  }
  this = (RGE_RMM_Object_Generator *)operator_new(0x1920);
  uStack_4 = 0;
  if (this != (RGE_RMM_Object_Generator *)0x0) {
    RGE_RMM_Object_Generator::RGE_RMM_Object_Generator
              (this,param_1->map,param_1,param_2,&RStack_18d4,'\x01');
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00482b67
// Address: 00482b67
// [HELPER] s___d: " %d"
// [HELPER] s__d: "%d"
// [HELPER] s__d__d__d__d__d: "%d %d %d %d %d"
// [HELPER] s__d__d__d__d__d__d__d__d__d: "%d %d %d %d %d %d %d %d %d"
// [HELPER] s__d__d__d__d__d__d__d__d__d__d__d: "%d %d %d %d %d %d %d %d %d %d %d %d"
// [HELPER] s_r: "r"
RGE_Random_Map_Module * __thiscall
FUN_00482b67(RGE_Random_Map_Module *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
            ,int param_5)
{
  int *piVar1;
  RGE_Random_Map_Module **ppRVar2;
  RGE_Random_Map_Module_List **ppRVar3;
  int iVar4;
  RGE_Random_Map_Module_List *pRVar5;
  undefined4 uVar6;
  int iVar7;
  RGE_Random_Map_Module_List *pRVar8;
  int iVar9;
  int iVar10;
  int iStack_30;
  RGE_Random_Map_Module *pRStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  iVar10 = 0;
  pRStack_2c = param_1;
  RGE_Random_Map_Module::RGE_Random_Map_Module
            (param_1,(RGE_Map *)0x0,(RGE_Random_Map_Module *)0x0,'\0');
  param_1->_padding_ = (int)&RGE_RMM_Database_Controller::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1].parent = (RGE_Random_Map_Module *)0xffffffff;
  param_1[1].list = (RGE_Random_Map_Module_List *)0x0;
  iVar4 = fopen(param_5,s_r);
  if (iVar4 == 0) {
    param_1[0x1a7].list = (RGE_Random_Map_Module_List *)0x0;
    param_1[0x1a7].parent = (RGE_Random_Map_Module *)0x0;
  }
  else {
    ppRVar2 = &param_1[0x1a7].parent;
    fscanf(iVar4,s___d,ppRVar2);
    if ((int)*ppRVar2 < 1) {
      param_1[0x1a7].list = (RGE_Random_Map_Module_List *)0x0;
    }
    else {
      pRVar5 = (RGE_Random_Map_Module_List *)calloc(*ppRVar2,0x48);
      param_1[0x1a7].list = pRVar5;
      if (0 < (int)*ppRVar2) {
        iVar9 = 0;
        do {
          fscanf(iVar4,&s__d,(int)&(param_1[0x1a7].list)->module + iVar9);
          iVar10 = iVar10 + 1;
          iVar9 = iVar9 + 0x48;
        } while (iVar10 < (int)*ppRVar2);
        fclose(iVar4);
        goto LAB_00482c49;
      }
    }
    fclose(iVar4);
  }
LAB_00482c49:
  if ((int)param_1[0x1a7].parent < 1) {
    param_1[0x1a7].parent = (RGE_Random_Map_Module *)0x0;
    param_1[0x1a7].list = (RGE_Random_Map_Module_List *)0x0;
  }
  else {
    iVar4 = fopen(param_2,s_r);
    if (iVar4 != 0) {
      fscanf(iVar4,&s__d,&iStack_28);
      param_5 = 0;
      if (0 < iStack_28) {
        do {
          fscanf(iVar4,&s__d,&iStack_30);
          ppRVar3 = &param_1[0x1a7].list[iStack_30 * 9].next;
          piVar1 = (int *)(ppRVar3 + 9);
          fscanf(iVar4,s__d__d__d__d__d__d__d__d__d,piVar1,ppRVar3,ppRVar3 + 1,ppRVar3 + 2,
                 ppRVar3 + 3,ppRVar3 + 4,ppRVar3 + 5,ppRVar3 + 6,ppRVar3 + 7);
          if (*piVar1 < 1) {
            ppRVar3[10] = (RGE_Random_Map_Module_List *)0x0;
          }
          else {
            uVar6 = calloc(*piVar1,0x2c);
            ppRVar3[10] = (RGE_Random_Map_Module_List *)uVar6;
            iVar10 = 0;
            if (0 < *piVar1) {
              iVar9 = 0;
              do {
                iVar7 = (int)ppRVar3[10] + iVar9;
                fscanf(iVar4,s__d__d__d__d__d__d__d__d__d__d__d,iVar7,auStack_1c,iVar7 + 8,
                       iVar7 + 0xc,auStack_18,auStack_14,iVar7 + 0x14,iVar7 + 0x18,auStack_10,
                       auStack_c,iVar7 + 0x20,iVar7 + 0x24);
                iVar10 = iVar10 + 1;
                *(undefined1 *)((int)ppRVar3[10] + 4 + iVar9) = auStack_1c[0];
                *(undefined1 *)((int)ppRVar3[10] + 0x10 + iVar9) = auStack_18[0];
                *(undefined1 *)((int)ppRVar3[10] + 0x11 + iVar9) = auStack_14[0];
                *(undefined1 *)((int)ppRVar3[10] + 0x1c + iVar9) = auStack_10[0];
                *(undefined1 *)((int)ppRVar3[10] + 0x1d + iVar9) = auStack_c[0];
                *(undefined4 *)((int)ppRVar3[10] + 0x28 + iVar9) = 8;
                iVar9 = iVar9 + 0x2c;
                param_1 = pRStack_2c;
              } while (iVar10 < *piVar1);
            }
          }
          param_5 = param_5 + 1;
        } while (param_5 < iStack_28);
      }
      fclose(iVar4);
    }
    iVar4 = fopen(param_3,s_r);
    if (iVar4 != 0) {
      fscanf(iVar4,&s__d,&iStack_24);
      param_5 = 0;
      if (0 < iStack_24) {
        do {
          fscanf(iVar4,&s__d,&iStack_30);
          pRVar5 = param_1[0x1a7].list + iStack_30 * 9 + 6;
          fscanf(iVar4,&s__d,pRVar5);
          iVar10 = 0;
          if ((int)pRVar5->module < 1) {
            pRVar5->next = (RGE_Random_Map_Module_List *)0x0;
          }
          else {
            pRVar8 = (RGE_Random_Map_Module_List *)calloc(pRVar5->module,0x18);
            pRVar5->next = pRVar8;
            if (0 < (int)pRVar5->module) {
              iVar9 = 0;
              do {
                iVar7 = (int)&pRVar5->next->module + iVar9;
                fscanf(iVar4,s__d__d__d__d__d,iVar7,iVar7 + 4,iVar7 + 8,iVar7 + 0xc,iVar7 + 0x10);
                iVar10 = iVar10 + 1;
                *(undefined4 *)((int)&pRVar5->next[2].next + iVar9) = 0x14;
                iVar9 = iVar9 + 0x18;
                param_1 = pRStack_2c;
              } while (iVar10 < (int)pRVar5->module);
            }
          }
          param_5 = param_5 + 1;
        } while (param_5 < iStack_24);
      }
      fclose(iVar4);
    }
    iVar4 = fopen(param_4,s_r);
    if (iVar4 != 0) {
      fscanf(iVar4,&s__d,&iStack_20);
      param_5 = 0;
      if (0 < iStack_20) {
        do {
          fscanf(iVar4,&s__d,&iStack_30);
          pRVar5 = param_1[0x1a7].list + iStack_30 * 9 + 7;
          fscanf(iVar4,&s__d,pRVar5);
          iVar10 = 0;
          if ((int)pRVar5->module < 1) {
            pRVar5->next = (RGE_Random_Map_Module_List *)0x0;
          }
          else {
            pRVar8 = (RGE_Random_Map_Module_List *)calloc(pRVar5->module,0x2c);
            pRVar5->next = pRVar8;
            if (0 < (int)pRVar5->module) {
              iVar9 = 0;
              do {
                iVar7 = (int)&pRVar5->next->module + iVar9;
                fscanf(iVar4,s__d__d__d__d__d__d__d__d__d__d__d,iVar7,iVar7 + 4,auStack_8,auStack_4,
                       iVar7 + 0xc,iVar7 + 0x10,iVar7 + 0x14,iVar7 + 0x18,iVar7 + 0x1c,iVar7 + 0x20,
                       iVar7 + 0x24,iVar7 + 0x28);
                iVar10 = iVar10 + 1;
                *(undefined1 *)((int)&pRVar5->next[1].module + iVar9) = auStack_8[0];
                *(undefined1 *)((int)&pRVar5->next[1].module + iVar9 + 1) = auStack_4[0];
                iVar9 = iVar9 + 0x2c;
                param_1 = pRStack_2c;
              } while (iVar10 < (int)pRVar5->module);
            }
          }
          param_5 = param_5 + 1;
        } while (param_5 < iStack_20);
      }
      fclose(iVar4);
      return param_1;
    }
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00483011
// Address: 00483011
RGE_Random_Map_Module * __thiscall FUN_00483011(RGE_Random_Map_Module *param_1,int param_2)
{
  int *piVar1;
  int *piVar2;
  RGE_Random_Map_Module **ppRVar3;
  int iVar4;
  int iVar5;
  RGE_Random_Map_Module_List *pRVar6;
  int *piVar7;
  void *pvVar8;
  undefined4 *unaff_FS_OFFSET;
  int iStack_1c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar5 = param_2;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e658;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Random_Map_Module::RGE_Random_Map_Module
            (param_1,(RGE_Map *)0x0,(RGE_Random_Map_Module *)0x0,'\0');
  ppRVar3 = &param_1[0x1a7].parent;
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_RMM_Database_Controller::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1].parent = (RGE_Random_Map_Module *)0xffffffff;
  param_1[1].list = (RGE_Random_Map_Module_List *)0x0;
  rge_read(param_2,ppRVar3,8);
  if (0 < (int)*ppRVar3) {
    pRVar6 = (RGE_Random_Map_Module_List *)calloc(*ppRVar3,0x48);
    param_1[0x1a7].list = pRVar6;
    rge_read(param_2,pRVar6,(int)*ppRVar3 * 0x48);
    iStack_1c = 0;
    if (0 < (int)*ppRVar3) {
      param_2 = 0;
      do {
        pRVar6 = param_1[0x1a7].list;
        piVar1 = (int *)((int)&pRVar6[6].module + param_2);
        piVar2 = (int *)((int)&pRVar6[7].module + param_2);
        piVar7 = (int *)((int)&pRVar6[8].module + param_2);
        rge_read(iVar5,(void *)((int)&pRVar6->next + param_2),0x2c);
        iVar4 = *(int *)((int)&pRVar6[5].module + param_2);
        if (0 < iVar4) {
          pvVar8 = (void *)calloc(iVar4,0x2c);
          *(void **)((int)&pRVar6[5].next + param_2) = pvVar8;
          rge_read(iVar5,pvVar8,*(int *)((int)&pRVar6[5].module + param_2) * 0x2c);
        }
        rge_read(iVar5,piVar1,8);
        if (0 < *piVar1) {
          pvVar8 = (void *)calloc(*piVar1,0x18);
          *(void **)((int)&pRVar6[6].next + param_2) = pvVar8;
          rge_read(iVar5,pvVar8,*piVar1 * 0x18);
        }
        rge_read(iVar5,piVar2,8);
        if (0 < *piVar2) {
          pvVar8 = (void *)calloc(*piVar2,0x2c);
          *(void **)((int)&pRVar6[7].next + param_2) = pvVar8;
          rge_read(iVar5,pvVar8,*piVar2 * 0x2c);
        }
        rge_read(iVar5,piVar7,8);
        if (0 < *piVar7) {
          pvVar8 = (void *)calloc(*piVar7,0x18);
          *(void **)((int)&pRVar6[8].next + param_2) = pvVar8;
          rge_read(iVar5,pvVar8,*piVar7 * 0x18);
        }
        iStack_1c = iStack_1c + 1;
        param_2 = param_2 + 0x48;
      } while (iStack_1c < (int)*ppRVar3);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004831f2
// Address: 004831f2
void __fastcall FUN_004831f2(RGE_Random_Map_Module *param_1)
{
  RGE_Random_Map_Module *pRVar1;
  int iVar2;
  int iVar3;
  
  pRVar1 = param_1[0x1a7].parent;
  param_1->_padding_ = (int)&RGE_RMM_Database_Controller::_vftable_;
  if ((0 < (int)pRVar1) && (param_1[0x1a7].list != (RGE_Random_Map_Module_List *)0x0)) {
    iVar2 = 0;
    if (0 < (int)pRVar1) {
      iVar3 = 0;
      do {
        if (0 < *(int *)((int)&param_1[0x1a7].list[5].module + iVar3)) {
          free(*(undefined4 *)((int)&param_1[0x1a7].list[5].next + iVar3));
        }
        if (0 < *(int *)((int)&param_1[0x1a7].list[6].module + iVar3)) {
          free(*(undefined4 *)((int)&param_1[0x1a7].list[6].next + iVar3));
        }
        if (0 < *(int *)((int)&param_1[0x1a7].list[7].module + iVar3)) {
          free(*(undefined4 *)((int)&param_1[0x1a7].list[7].next + iVar3));
        }
        if (0 < *(int *)((int)&param_1[0x1a7].list[8].module + iVar3)) {
          free(*(undefined4 *)((int)&param_1[0x1a7].list[8].next + iVar3));
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x48;
      } while (iVar2 < (int)param_1[0x1a7].parent);
    }
    free(param_1[0x1a7].list);
    param_1[0x1a7].parent = (RGE_Random_Map_Module *)0x0;
  }
  RGE_Random_Map_Module::~RGE_Random_Map_Module(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004832d5
// Address: 004832d5
undefined4 __thiscall FUN_004832d5(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_10;
  
  iVar3 = param_2;
  piVar1 = (int *)(param_1 + 0x4f54);
  rge_write(param_2,piVar1,8);
  iVar4 = *piVar1;
  if (0 < iVar4) {
    rge_write(param_2,*(void **)(param_1 + 0x4f58),iVar4 * 0x48);
    iVar4 = *piVar1;
    iStack_10 = 0;
    if (0 < iVar4) {
      param_2 = 0;
      do {
        iVar4 = param_2 + *(int *)(param_1 + 0x4f58);
        rge_write(iVar3,(void *)(iVar4 + 4),0x2c);
        if (0 < *(int *)(iVar4 + 0x28)) {
          rge_write(iVar3,*(void **)(iVar4 + 0x2c),*(int *)(iVar4 + 0x28) * 0x2c);
        }
        rge_write(iVar3,(int *)(iVar4 + 0x30),8);
        iVar2 = *(int *)(iVar4 + 0x30);
        if (0 < iVar2) {
          rge_write(iVar3,*(void **)(iVar4 + 0x34),iVar2 * 0x18);
        }
        rge_write(iVar3,(int *)(iVar4 + 0x38),8);
        iVar2 = *(int *)(iVar4 + 0x38);
        if (0 < iVar2) {
          rge_write(iVar3,*(void **)(iVar4 + 0x3c),iVar2 * 0x2c);
        }
        rge_write(iVar3,(int *)(iVar4 + 0x40),8);
        iVar2 = *(int *)(iVar4 + 0x40);
        if (0 < iVar2) {
          rge_write(iVar3,*(void **)(iVar4 + 0x44),iVar2 * 0x18);
        }
        iVar4 = iStack_10 + 1;
        param_2 = param_2 + 0x48;
        iStack_10 = iVar4;
      } while (iVar4 < *piVar1);
    }
  }
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_00483538
// Address: 00483538
undefined4 __thiscall
FUN_00483538(RGE_Random_Map_Module *param_1,RGE_Map *param_2,int param_3,uint param_4,
            RGE_Random_Map_Module_List *param_5,undefined4 param_6)
{
  int iVar1;
  
  param_1[1]._padding_ = param_3;
  param_1[1].parent = (RGE_Random_Map_Module *)(param_4 & 0xff);
  param_1[1].list = param_5;
  RGE_Random_Map_Module::update_map_info(param_1,param_2);
  RGE_Random_Map_Module::create_shared_resources(param_1);
  iVar1 = param_1->_padding_;
  (**(code **)(iVar1 + 4))(param_6);
  (**(code **)(iVar1 + 8))();
  (**(code **)(iVar1 + 0xc))();
  (**(code **)(iVar1 + 0x10))();
  return 1;
}

// --------------------------------------------------

// Function: FUN_00483594
// Address: 00483594
uint __fastcall FUN_00483594(RGE_Random_Map_Module *param_1)
{
  RGE_Random_Map_Module_List *pRVar1;
  RGE_Random_Map_Module *this;
  uint extraout_EAX;
  
  pRVar1 = param_1->list;
  param_1[1]._padding_ = 0;
  param_1[1].parent = (RGE_Random_Map_Module *)0xffffffff;
  param_1[1].list = (RGE_Random_Map_Module_List *)0x0;
  while (pRVar1 != (RGE_Random_Map_Module_List *)0x0) {
    this = pRVar1->module;
    if (this != (RGE_Random_Map_Module *)0x0) {
      RGE_Random_Map_Module::~RGE_Random_Map_Module(this);
      operator_delete(this);
    }
    pRVar1 = param_1->list;
  }
  RGE_Random_Map_Module::destroy_shared_resources(param_1);
  RGE_Random_Map_Module::update_map_info(param_1,(RGE_Map *)0x0);
  return extraout_EAX & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_004835f2
// Address: 004835f2
// [HELPER] s_C__msdev_work_age1_x1_rmm_dbct_c: "C:\msdev\work\age1_x1\rmm_dbct.cpp"
// [HELPER] s_________Random_Map_calc_land_end: "********Random Map calc land end (point3) "
// [HELPER] s_________Random_Map_calc_land_sta: "********Random Map calc land start, rand: %d"
// [HELPER] s_________Random_Map_calc_land_xy_: "********Random Map calc land xy player %d (%d, %d)"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004835f2(int param_1,TDebuggingLog *param_2,TDebuggingLog *param_3,int param_4,int param_5)
{
  int iVar1;
  char cVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  TDebuggingLog *this;
  TDebuggingLog *pTVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int *piStack_24;
  TDebuggingLog *pTStack_20;
  int iStack_1c;
  
  iVar5 = (int)param_3;
  iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_dbct_c,0x1c3);
  TDebuggingLog::Log(this,(char *)L,s_________Random_Map_calc_land_sta,iVar6);
  iVar6 = *(int *)(param_1 + 0x14);
  fVar3 = (float)(iVar6 + (int)param_3 * -2) / SQRT((float)param_4);
  if (param_4 < 4) {
    if (param_4 < 7) goto LAB_0048366e;
  }
  else if (param_4 < 7) {
    fVar3 = fVar3 * _DAT_00571ea8;
    goto LAB_0048366e;
  }
  fVar3 = fVar3 * _DAT_00571eac;
LAB_0048366e:
  iStack_30 = __ftol();
  iStack_28 = __ftol();
  iStack_2c = __ftol();
  pTStack_20 = (TDebuggingLog *)__ftol();
  if (iStack_30 <= (int)param_3) {
    iStack_30 = (int)param_3 + 1;
  }
  if (iStack_28 <= (int)param_3) {
    iStack_28 = (int)param_3 + 1;
  }
  iVar6 = iVar6 - (int)param_3;
  if (iVar6 + -1 <= iStack_2c) {
    iStack_2c = iVar6 + -2;
  }
  pTVar8 = (TDebuggingLog *)(*(int *)(param_1 + 0x18) - (int)param_3);
  if ((int)(pTVar8[-1].Filename + 0x7f) <= (int)pTStack_20) {
    pTVar8 = (TDebuggingLog *)(pTVar8[-1].Filename + 0x7e);
    pTStack_20 = pTVar8;
  }
  cVar2 = *(char *)(param_5 + 0x11);
  if (cVar2 == '\0') {
    TDebuggingLog::Log(pTVar8,(char *)L,s_________Random_Map_calc_land_end);
    if ((int)param_2 < (int)(param_2->TBuff + param_4 + -0x28)) {
      param_4 = (int)(param_2->TBuff + param_4 + -0x28) - (int)param_2;
      piVar11 = (int *)(param_1 + 0x48 + (int)param_2 * 0x34);
      do {
        iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_dbct_c,0x1e5);
        piVar11[-1] = (iVar6 * (*(int *)(param_1 + 0x14) + (int)param_3 * -2)) / 0x7fff +
                      (int)param_3;
        iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_dbct_c,0x1e6);
        param_4 = param_4 + -1;
        *piVar11 = (iVar6 * (*(int *)(param_1 + 0x18) + (int)param_3 * -2)) / 0x7fff + (int)param_3;
        piVar11 = piVar11 + 0xd;
      } while (param_4 != 0);
    }
  }
  else if (cVar2 == '\x01') {
    TDebuggingLog::Log(pTVar8,(char *)L,s_________Random_Map_calc_land_end);
    if ((int)param_2 < (int)(param_2->TBuff + param_4 + -0x28)) {
      iVar6 = (int)(param_2->TBuff + param_4 + -0x28) - (int)param_2;
      puVar7 = (undefined4 *)(param_1 + 0x48 + (int)param_2 * 0x34);
      do {
        puVar7[-1] = *(undefined4 *)(param_5 + 0x14);
        *puVar7 = *(undefined4 *)(param_5 + 0x18);
        puVar7 = puVar7 + 0xd;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else if (cVar2 == '\x02') {
    TDebuggingLog::Log(pTVar8,(char *)L,s_________Random_Map_calc_land_end);
    param_3 = param_2;
    if ((int)param_2 < (int)(param_2->TBuff + param_4 + -0x28)) {
      piVar11 = (int *)(param_1 + 0x48 + (int)param_2 * 0x34);
      piStack_24 = piVar11;
      do {
        do {
          bVar4 = false;
          iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_dbct_c,0x1fc);
          iVar9 = (iVar6 * (*(int *)(param_1 + 0x14) + iVar5 * -2)) / 0x7fff + iVar5;
          iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_dbct_c,0x1fd);
          iVar6 = (iVar6 * (*(int *)(param_1 + 0x18) + iVar5 * -2)) / 0x7fff + iVar5;
          if ((((iStack_30 < iVar9) && (iVar9 < iStack_2c)) && (iStack_28 < iVar6)) &&
             (iVar6 < (int)pTStack_20)) {
LAB_004838b7:
            bVar4 = true;
          }
          else {
            pTVar8 = param_2;
            piVar10 = piVar11;
            if ((int)param_2 < (int)param_3) {
              do {
                iStack_1c = iVar9 - piVar10[-1];
                if (iStack_1c < 0) {
                  iStack_1c = -iStack_1c;
                }
                param_5 = iVar6 - *piVar10;
                if (param_5 < 0) {
                  param_5 = -param_5;
                }
                if ((float)(iStack_1c * iStack_1c + param_5 * param_5) <= fVar3 * fVar3) {
                  if (pTVar8 == (TDebuggingLog *)(param_3[-1].Filename + 0x7f)) {
                    iVar1 = param_1 + (int)pTVar8 * 0x34;
                    *(int *)(iVar1 + 0x48) = iVar6;
                    *(int *)(iVar1 + 0x44) = iVar9;
                    TDebuggingLog::Log(pTVar8,(char *)L,s_________Random_Map_calc_land_xy_,pTVar8,
                                       iVar9,iVar6);
                  }
                  goto LAB_004838b7;
                }
                pTVar8 = (TDebuggingLog *)((int)&pTVar8->Timestamp + 1);
                piVar10 = piVar10 + 0xd;
              } while ((int)pTVar8 < (int)param_3);
            }
          }
        } while (bVar4);
        piStack_24[-1] = iVar9;
        *piStack_24 = iVar6;
        TDebuggingLog::Log(L,(char *)L,s_________Random_Map_calc_land_xy_,param_3,iVar9,iVar6);
        param_3 = (TDebuggingLog *)((int)&param_3->Timestamp + 1);
        piStack_24 = piStack_24 + 0xd;
      } while ((int)param_3 < (int)(param_2->TBuff + param_4 + -0x28));
    }
  }
  TDebuggingLog::Log(L,(char *)L,s_________Random_Map_calc_land_end);
  return;
}

// --------------------------------------------------

// Function: FUN_0048415d
// Address: 0048415d
void __fastcall FUN_0048415d(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iStack_c;
  int iStack_8;
  
  iStack_c = 0;
  iVar2 = *(int *)(param_1 + 0x4f58) + *(int *)(param_1 + 0x34) * 0x48;
  *(undefined4 *)(param_1 + 0x20d4) = *(undefined4 *)(iVar2 + 0x30);
  if (0 < *(int *)(iVar2 + 0x30)) {
    iVar6 = 0;
    puVar7 = (undefined4 *)(param_1 + 0x147c);
    do {
      uVar3 = __ftol();
      puVar7[-2] = uVar3;
      *puVar7 = *(undefined4 *)(iVar6 + 4 + *(int *)(iVar2 + 0x34));
      puVar7[1] = *(undefined4 *)(iVar6 + 8 + *(int *)(iVar2 + 0x34));
      puVar7[3] = *(undefined4 *)(iVar6 + 0x10 + *(int *)(iVar2 + 0x34));
      puVar7[-1] = 0;
      puVar7[2] = *(undefined4 *)(iVar6 + 0xc + *(int *)(iVar2 + 0x34));
      puVar7[4] = *(undefined4 *)(iVar6 + 0x14 + *(int *)(iVar2 + 0x34));
      puVar7[5] = 1;
      iStack_c = iStack_c + 1;
      iVar6 = iVar6 + 0x18;
      puVar7 = puVar7 + 8;
    } while (iStack_c < *(int *)(iVar2 + 0x30));
  }
  iVar8 = 0;
  iVar6 = 0;
  iStack_c = 0;
  if (0 < *(int *)(iVar2 + 0x28)) {
    do {
      if (-1 < *(int *)(iVar8 + 0x20 + *(int *)(iVar2 + 0x2c))) {
        if (*(char *)(iVar8 + *(int *)(iVar2 + 0x2c) + 0x1d) == '\0') {
          iVar5 = iVar6 * 0x10 + param_1;
          *(undefined4 *)(iVar5 + 0x20d8) = *(undefined4 *)(param_1 + 0x44 + iVar6 * 0x34);
          *(undefined4 *)(iVar5 + 0x20dc) = *(undefined4 *)(param_1 + iVar6 * 0x34 + 0x48);
          iVar1 = iVar6 + 0x20e;
          iVar6 = iVar6 + 1;
          *(undefined4 *)(iVar1 * 0x10 + param_1) =
               *(undefined4 *)(iVar8 + 0x20 + *(int *)(iVar2 + 0x2c));
          *(undefined4 *)(iVar5 + 0x20e4) = *(undefined4 *)(iVar8 + 0x24 + *(int *)(iVar2 + 0x2c));
        }
        else {
          iStack_8 = 0;
          if (0 < *(int *)(param_1 + 0x38)) {
            puVar7 = (undefined4 *)(param_1 + 0x48 + iVar6 * 0x34);
            puVar4 = (undefined4 *)(iVar6 * 0x10 + 0x20dc + param_1);
            do {
              iVar6 = iVar6 + 1;
              puVar4[-1] = puVar7[-1];
              *puVar4 = *puVar7;
              puVar7 = puVar7 + 0xd;
              puVar4[1] = *(undefined4 *)(iVar8 + 0x20 + *(int *)(iVar2 + 0x2c));
              puVar4[2] = *(undefined4 *)(iVar8 + 0x24 + *(int *)(iVar2 + 0x2c));
              iStack_8 = iStack_8 + 1;
              puVar4 = puVar4 + 4;
            } while (iStack_8 < *(int *)(param_1 + 0x38));
          }
        }
      }
      iStack_c = iStack_c + 1;
      iVar8 = iVar8 + 0x2c;
    } while (iStack_c < *(int *)(iVar2 + 0x28));
  }
  *(int *)(param_1 + 0x2708) = iVar6;
  return;
}

// --------------------------------------------------

// Function: FUN_00484465
// Address: 00484465
void __fastcall FUN_00484465(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iStack_8;
  int iStack_4;
  
  iVar1 = *(int *)(param_1 + 0x4f58) + 4 + *(int *)(param_1 + 0x34) * 0x48;
  iVar6 = 0;
  iVar5 = (*(int *)(param_1 + 0x14) * *(int *)(iVar1 + 0x1c) * *(int *)(param_1 + 0x18)) / 100;
  *(undefined4 *)(param_1 + 0x491c) = 4;
  *(undefined4 *)(param_1 + 0x3fd8) = 1;
  *(undefined4 *)(param_1 + 0x3fdc) = 10;
  *(undefined4 *)(param_1 + 0x3fe8) = 0;
  *(undefined4 *)(param_1 + 0x3fe4) = 0;
  *(undefined4 *)(param_1 + 0x3fe0) = 2;
  *(int *)(param_1 + 0x3fd4) = (iVar5 * 10) / 100;
  *(undefined4 *)(param_1 + 0x3ff0) = 2;
  *(int *)(param_1 + 0x3fec) = (iVar5 * 8) / 100;
  *(undefined4 *)(param_1 + 0x3ff4) = 8;
  *(int *)(param_1 + 0x4004) = (iVar5 * 6) / 100;
  *(undefined4 *)(param_1 + 0x4000) = 0;
  *(undefined4 *)(param_1 + 0x3ffc) = 1;
  *(undefined4 *)(param_1 + 0x3ff8) = 1;
  *(undefined4 *)(param_1 + 0x4008) = 3;
  *(undefined4 *)(param_1 + 0x400c) = 6;
  *(undefined4 *)(param_1 + 0x4018) = 0;
  *(undefined4 *)(param_1 + 0x4014) = 2;
  *(undefined4 *)(param_1 + 0x4010) = 1;
  *(int *)(param_1 + 0x401c) = (iVar5 * 4) / 100;
  *(undefined4 *)(param_1 + 0x4020) = 4;
  *(undefined4 *)(param_1 + 0x4024) = 4;
  *(undefined4 *)(param_1 + 0x4030) = 0;
  *(undefined4 *)(param_1 + 0x402c) = 3;
  *(undefined4 *)(param_1 + 0x4028) = 1;
  iVar5 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(iVar1 + 0x24)) {
    do {
      iVar2 = *(int *)(iVar1 + 0x28) + iVar6;
      if (-1 < *(int *)(iVar2 + 0x20)) {
        if (*(char *)(iVar2 + 0x1d) == '\0') {
          iVar2 = iVar5 * 0x34;
          *(undefined4 *)((iVar5 + 0x492) * 0x10 + param_1) =
               *(undefined4 *)(param_1 + 0x44 + iVar5 * 0x34);
          iVar4 = iVar5 * 0x10 + param_1;
          iVar5 = iVar5 + 1;
          *(undefined4 *)(iVar4 + 0x4924) = *(undefined4 *)(param_1 + iVar2 + 0x48);
          *(undefined4 *)(iVar4 + 0x4928) = *(undefined4 *)(iVar6 + 0x20 + *(int *)(iVar1 + 0x28));
          *(undefined4 *)(iVar4 + 0x492c) = *(undefined4 *)(iVar6 + 0x24 + *(int *)(iVar1 + 0x28));
        }
        else {
          iStack_8 = 0;
          if (0 < *(int *)(param_1 + 0x38)) {
            puVar7 = (undefined4 *)(param_1 + 0x48 + iVar5 * 0x34);
            puVar3 = (undefined4 *)(iVar5 * 0x10 + 0x4924 + param_1);
            do {
              iVar5 = iVar5 + 1;
              puVar3[-1] = puVar7[-1];
              *puVar3 = *puVar7;
              puVar7 = puVar7 + 0xd;
              puVar3[1] = *(undefined4 *)(iVar6 + 0x20 + *(int *)(iVar1 + 0x28));
              puVar3[2] = *(undefined4 *)(iVar6 + 0x24 + *(int *)(iVar1 + 0x28));
              iStack_8 = iStack_8 + 1;
              puVar3 = puVar3 + 4;
            } while (iStack_8 < *(int *)(param_1 + 0x38));
          }
        }
      }
      iStack_4 = iStack_4 + 1;
      iVar6 = iVar6 + 0x2c;
    } while (iStack_4 < *(int *)(iVar1 + 0x24));
  }
  *(int *)(param_1 + 0x4f50) = iVar5;
  return;
}

// --------------------------------------------------

// Function: FUN_004846b2
// Address: 004846b2
RGE_Random_Map_Module * __thiscall
FUN_004846b2(RGE_Random_Map_Module *param_1,RGE_Map *param_2,RGE_Random_Map_Module *param_3,
            int *param_4)
{
  int iVar1;
  RGE_Random_Map_Module *pRVar2;
  
  RGE_Random_Map_Module::RGE_Random_Map_Module(param_1,param_2,param_3,'\x01');
  param_1->_padding_ = (int)&RGE_RMM_Elevation_Generator::_vftable_;
  pRVar2 = param_1 + 1;
  for (iVar1 = 0x3e0; iVar1 != 0; iVar1 = iVar1 + -1) {
    pRVar2->_padding_ = *param_4;
    param_4 = param_4 + 1;
    pRVar2 = (RGE_Random_Map_Module *)&pRVar2->parent;
  }
  param_1->schedule = 1.5;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004846fb
// Address: 004846fb
undefined4 __fastcall FUN_004846fb(RGE_RMM_Elevation_Generator *param_1)
{
  int iVar1;
  RGE_Elevation_Info_Line RVar2;
  int iVar3;
  int iVar4;
  RGE_Elevation_Info *pRVar5;
  int iVar6;
  long *plVar7;
  long in_stack_ffffffd4;
  undefined4 in_stack_ffffffd8;
  undefined4 in_stack_ffffffdc;
  int in_stack_ffffffe0;
  int in_stack_ffffffe4;
  long lVar8;
  RGE_Elevation_Info *pRStack_4;
  
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)param_1);
  if ((0 < (param_1->info).elevation_num) && (iVar3 = 0, 0 < param_1->_padding_)) {
    do {
      iVar4 = 0;
      if (0 < param_1->_padding_) {
        iVar6 = 0;
        do {
          iVar1 = *(int *)(param_1->_padding_ + iVar3 * 4);
          iVar4 = iVar4 + 1;
          *(byte *)(iVar1 + 5 + iVar6) =
               *(byte *)(iVar1 + 5 + iVar6) & 0x1f |
               (char)(param_1->info).elevation[0].base_elevation << 5;
          iVar6 = iVar6 + 0x18;
        } while (iVar4 < param_1->_padding_);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1->_padding_);
  }
  lVar8 = 0x48475f;
  RGE_RMM_Elevation_Generator::generate_modifiers(param_1);
  iVar3 = (param_1->info).elevation_num;
  iVar4 = 0;
  if (0 < iVar3) {
    pRStack_4 = &param_1->info;
    do {
      pRVar5 = pRStack_4;
      plVar7 = (long *)&stack0xffffffd4;
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *plVar7 = pRVar5->elevation[0].elevation_size;
        pRVar5 = (RGE_Elevation_Info *)&pRVar5->elevation[0].elevation;
        plVar7 = plVar7 + 1;
      }
      RVar2.elevation = in_stack_ffffffd8;
      RVar2.elevation_size = in_stack_ffffffd4;
      RVar2.clumps = in_stack_ffffffdc;
      RVar2.spacing = in_stack_ffffffe0;
      RVar2.base_elevation = in_stack_ffffffe4;
      RVar2.base_terrain_type = lVar8;
      RGE_RMM_Elevation_Generator::base_elevation_generate(param_1,RVar2);
      in_stack_ffffffe4 = param_1->_padding_ + -1;
      lVar8 = 8;
      in_stack_ffffffe0 = param_1->_padding_ + -1;
      in_stack_ffffffdc = 0;
      in_stack_ffffffd8 = 0;
      in_stack_ffffffd4 = 0x4847a1;
      RGE_Map::clean_elevation
                ((RGE_Map *)param_1->_padding_,0,0,in_stack_ffffffe0,in_stack_ffffffe4,'\b');
      iVar3 = (param_1->info).elevation_num;
      iVar4 = iVar4 + 1;
      pRStack_4 = (RGE_Elevation_Info *)(pRStack_4->elevation + 1);
    } while (iVar4 < iVar3);
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_004847bf
// Address: 004847bf
uint __thiscall
FUN_004847bf(int param_1,int param_2,int *param_3,byte param_4,byte param_5,uint param_6)
{
  byte bVar1;
  uint uVar2;
  undefined3 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  
  uVar2 = param_6 & 0xff;
  iVar6 = param_2 - uVar2;
  iVar4 = (int)param_3 - uVar2;
  param_6 = (int)param_3 + uVar2;
  iVar5 = param_2 + uVar2;
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (*(int *)(param_1 + 0x14) <= iVar5) {
    iVar5 = *(int *)(param_1 + 0x14) + -1;
  }
  if (*(int *)(param_1 + 0x18) <= (int)param_6) {
    param_6 = *(int *)(param_1 + 0x18) + -1;
  }
  param_3 = (int *)(*(int *)(param_1 + 0x10) + iVar4 * 4);
  uVar2 = *param_3 + iVar6 * 0x18;
  param_2 = iVar4;
  if ((int)param_6 < iVar4) {
    return CONCAT31((int3)(uVar2 >> 8),1);
  }
  do {
    if (iVar6 <= iVar5) {
      pbVar7 = (byte *)(uVar2 + 5);
      iVar4 = iVar6;
      do {
        if (param_4 == 0xff) {
LAB_0048488c:
          return uVar2 & 0xffffff00;
        }
        bVar1 = *pbVar7;
        uVar3 = (undefined3)(uVar2 >> 8);
        uVar2 = CONCAT31(uVar3,bVar1);
        if (((bVar1 & 0x1f) != param_4) ||
           (uVar2 = CONCAT31(uVar3,bVar1 >> 5), bVar1 >> 5 < param_5)) goto LAB_0048488c;
        iVar4 = iVar4 + 1;
        pbVar7 = pbVar7 + 0x18;
      } while (iVar4 <= iVar5);
    }
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
    uVar2 = iVar6 * 0x18 + *param_3;
    if ((int)param_6 < param_2) {
      return CONCAT31((int3)(uVar2 >> 8),1);
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00484a38
// Address: 00484a38
void __fastcall FUN_00484a38(int param_1)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iStack_c;
  int iStack_8;
  
  uVar2 = *(int *)(param_1 + 0x18) * *(int *)(param_1 + 0x14);
  iVar4 = 0;
  puVar6 = *(undefined4 **)(param_1 + 0x20);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      iVar7 = 0;
      if (0 < *(int *)(param_1 + 0x14)) {
        do {
          iStack_8 = *(int *)(param_1 + 0xfac);
          iStack_c = 0;
          iVar1 = 0;
          if (0 < iStack_8) {
            iVar5 = param_1 + 0x980;
            do {
              iVar1 = __ftol();
              iVar1 = *(int *)(iVar5 + 4) - iVar1;
              if (0 < iVar1) {
                iStack_c = iStack_c + *(int *)(iVar5 + 8) * iVar1;
              }
              iVar5 = iVar5 + 0x10;
              iStack_8 = iStack_8 + -1;
              iVar1 = iStack_c;
            } while (iStack_8 != 0);
          }
          if (iVar1 < 0x65) {
            *(char *)(*(int *)(*(int *)(param_1 + 0x24) + iVar4 * 4) + iVar7) = (char)iVar1;
          }
          else {
            *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x24) + iVar4 * 4) + iVar7) = 0x65;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(param_1 + 0x14));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x18));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00484b4c
// Address: 00484b4c
int __thiscall FUN_00484b4c(int param_1,byte param_2)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = **(uint **)(param_1 + 0x10);
  uVar1 = uVar2 + *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x18) * 0x18;
  for (; uVar2 < uVar1; uVar2 = uVar2 + 0x18) {
    if ((*(byte *)(uVar2 + 5) & 0x1f) == param_2) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_00484b86
// Address: 00484b86
// [HELPER] s_C__msdev_work_age1_x1_rmm_elev_c: "C:\msdev\work\age1_x1\rmm_elev.cpp"
void __thiscall FUN_00484b86(RGE_Random_Map_Module *param_1,Map_Stack *param_2)
{
  Map_Stack *pMVar1;
  int iVar2;
  int iVar3;
  Map_Stack *pMVar4;
  int iVar5;
  int iVar6;
  int iStack_4;
  
  iVar2 = param_1->map_height;
  iVar3 = param_1->map_width;
  pMVar4 = param_1->stack_array;
  pMVar4->prev = param_2;
  pMVar1 = pMVar4 + iVar2 * iVar3 + -1;
  pMVar4->next = pMVar4 + 1;
  pMVar1->next = (Map_Stack *)0x0;
  pMVar1->prev = pMVar1 + -1;
  pMVar4 = pMVar4 + 1;
  while (pMVar4 < pMVar1) {
    pMVar4->next = pMVar4 + 1;
    pMVar4->prev = pMVar4 + -1;
    pMVar4 = pMVar4 + 1;
  }
  iVar5 = param_1->map_height * param_1->map_width;
  iStack_4 = (int)(iVar5 + (iVar5 >> 0x1f & 0xfU)) >> 4;
  if (0 < iStack_4) {
    do {
      iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_elev_c,0xfa);
      iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_elev_c,0xfb);
      RGE_Random_Map_Module::add_stack_node
                (param_1,param_2,
                 param_1->stack_offsets[(iVar6 * (iVar2 + -1)) / 0x7fff] +
                 (iVar5 * (iVar3 + -1)) / 0x7fff);
      iStack_4 = iStack_4 + -1;
    } while (iStack_4 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00484c7a
// Address: 00484c7a
void __thiscall FUN_00484c7a(RGE_Random_Map_Module *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2 - param_4;
  param_3 = param_3 - param_4;
  param_4 = param_4 + param_2;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_1->map_width <= param_4) {
    param_4 = param_1->map_width + -1;
  }
  for (; param_3 <= param_4; param_3 = param_3 + 1) {
    if (iVar1 <= param_4) {
      iVar2 = iVar1 * 0x18;
      iVar3 = (param_4 - iVar1) + 1;
      do {
        RGE_Random_Map_Module::remove_stack_node
                  (param_1,(Map_Stack *)((int)&param_1->stack_offsets[param_3]->x + iVar2));
        iVar2 = iVar2 + 0x18;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004851f9
// Address: 004851f9
RGE_Random_Map_Module * __thiscall
FUN_004851f9(RGE_Random_Map_Module *param_1,RGE_Map *param_2,RGE_Random_Map_Module *param_3,
            int *param_4)
{
  int iVar1;
  RGE_Random_Map_Module *pRVar2;
  
  RGE_Random_Map_Module::RGE_Random_Map_Module(param_1,param_2,param_3,'\x01');
  param_1->_padding_ = (int)&RGE_RMM_Land_Generator::_vftable_;
  param_1->schedule = 1.0;
  pRVar2 = param_1 + 1;
  for (iVar1 = 0x50e; iVar1 != 0; iVar1 = iVar1 + -1) {
    pRVar2->_padding_ = *param_4;
    param_4 = param_4 + 1;
    pRVar2 = (RGE_Random_Map_Module *)&pRVar2->parent;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048523b
// Address: 0048523b
undefined4 __fastcall FUN_0048523b(RGE_RMM_Land_Generator *param_1)
{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)param_1);
  uVar1 = (undefined1)(param_1->info).land_num;
  uVar2 = param_1->_padding_ * param_1->_padding_;
  puVar4 = (undefined4 *)param_1->_padding_;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar4 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
    puVar4 = puVar4 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar4 = uVar1;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  RGE_Map::set_terrain
            ((RGE_Map *)param_1->_padding_,(RGE_Player *)0x0,(RGE_Game_World *)0x0,0,0,
             (short)param_1->_padding_ + -1,(short)param_1->_padding_ + -1,
             (param_1->info).base_terrain,'\x01',0);
  RGE_RMM_Land_Generator::base_land_generate(param_1);
  RGE_Map::clean_terrain
            ((RGE_Map *)param_1->_padding_,0,0,param_1->_padding_,param_1->_padding_,
             (param_1->info).base_terrain);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004852c5
// Address: 004852c5
uint __thiscall FUN_004852c5(int param_1,undefined4 param_2,uint param_3,int param_4,int param_5)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uStack_1c;
  
  uStack_1c = 0;
  iVar1 = param_1 + (param_3 & 0xff) * 0x34;
  iVar3 = *(int *)(iVar1 + 0x44);
  uVar2 = param_5 + iVar3;
  iVar7 = param_5 - iVar3;
  uVar5 = __ftol();
  if ((uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x24) + param_5 * 4) + param_4) !=
      *(uint *)(param_1 + 0x144c)) {
    return uVar5 & 0xffffff00;
  }
  if ((int)uVar2 < iVar7) {
    return uVar2 & 0xffffff00;
  }
  piVar6 = (int *)(*(int *)(param_1 + 0x24) + iVar7 * 4);
  do {
    if (iVar7 < 0) {
      if (param_5 + -2 < iVar7) {
        uStack_1c = uStack_1c + 5;
      }
    }
    else {
      iVar4 = param_4 - iVar3;
      if (iVar7 < *(int *)(param_1 + 0x18)) {
        for (; iVar4 <= param_4 + iVar3; iVar4 = iVar4 + 1) {
          if (iVar4 < 0) {
            if (param_4 + -2 < iVar4) {
              uStack_1c = uStack_1c + 1;
            }
          }
          else if (iVar4 < *(int *)(param_1 + 0x14)) {
            if (*(byte *)(iVar4 + *piVar6) == *(byte *)(iVar1 + 0x48)) {
              if ((((param_5 + -2 <= iVar7) && (iVar7 <= param_5 + 2)) && (param_4 + -2 <= iVar4))
                 && (iVar4 <= param_4 + 2)) {
                uStack_1c = uStack_1c + 1;
              }
            }
            else if ((int)(uint)*(byte *)(iVar4 + *piVar6) < *(int *)(param_1 + 0x144c)) {
              return 0;
            }
          }
          else if (iVar4 < param_4 + 2) {
            uStack_1c = uStack_1c + 1;
          }
        }
      }
      else if (iVar7 < param_5 + 2) {
        uStack_1c = uStack_1c + 5;
      }
    }
    iVar7 = iVar7 + 1;
    piVar6 = piVar6 + 1;
  } while (iVar7 <= (int)uVar2);
  return uStack_1c & 0xff;
}

// --------------------------------------------------

// Function: FUN_00485471
// Address: 00485471
uint __thiscall FUN_00485471(int param_1,int param_2,int param_3,uint param_4)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = param_4 * 0xd;
  iVar5 = param_1 + param_4 * 0x34;
  bVar1 = *(byte *)(param_1 + 0x60 + param_4 * 0x34);
  param_4 = (uint)bVar1;
  if (bVar1 == 0) {
    param_4 = uVar2 & 0xffffff00;
  }
  else {
    iVar3 = *(int *)(iVar5 + 0x50) - param_2;
    param_2 = param_2 - *(int *)(iVar5 + 0x58);
    iVar6 = iVar3;
    if (iVar3 <= param_2) {
      iVar6 = param_2;
    }
    iVar3 = iVar3 + *(int *)(iVar5 + 0x50);
    param_2 = param_2 + (*(int *)(param_1 + 0x14) - *(int *)(iVar5 + 0x58));
    if (iVar3 <= param_2) {
      iVar3 = param_2;
    }
    if (iVar3 < 1) {
      iVar3 = *(int *)(iVar5 + 0x54) - param_3;
      iVar4 = -*(int *)(iVar5 + 0x5c);
    }
    else {
      iVar4 = iVar3 - *(int *)(iVar5 + 0x5c);
      iVar3 = (*(int *)(iVar5 + 0x54) + iVar3) - param_3;
    }
    iVar5 = iVar4 + param_3;
    if (iVar4 + param_3 < iVar3) {
      iVar5 = iVar3;
    }
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    param_4 = (iVar5 + iVar6) * param_4;
    if (99 < (int)param_4) {
      return CONCAT31((int3)(param_4 >> 8),0x65);
    }
  }
  return param_4;
}

// --------------------------------------------------

// Function: FUN_0048551f
// Address: 0048551f
// [HELPER] s_C__msdev_work_age1_x1_rmm_land_c: "C:\msdev\work\age1_x1\rmm_land.cpp"
undefined4 __fastcall FUN_0048551f(RGE_RMM_Land_Generator *param_1)
{
  uchar uVar1;
  int iVar2;
  float fVar3;
  Map_Stack *pMVar4;
  byte bVar5;
  byte bVar6;
  Map_Stack *pMVar7;
  int iVar8;
  int iVar10;
  Map_Stack *pMVar11;
  long *plVar12;
  float fVar13;
  uchar *puVar14;
  long lStack_b10;
  long lStack_b0c;
  Map_Stack *pMStack_b08;
  Map_Stack *pMStack_b04;
  int iStack_b00;
  float fStack_afc;
  long lStack_af8;
  char cStack_af1;
  uchar *puStack_af0;
  float fStack_aec;
  float fStack_ae8;
  Map_Stack *pMStack_ae4;
  int iStack_ae0;
  int iStack_adc;
  float fStack_ad8;
  Map_Stack aMStack_ad4 [16];
  Map_Stack aMStack_948 [99];
  uint uVar9;
  
  iStack_b00 = 0;
  iStack_adc = param_1->_padding_ + -1;
  iStack_ae0 = param_1->_padding_ + -1;
  if (0 < (param_1->info).land_num) {
    pMStack_b08 = aMStack_948;
    pMStack_ae4 = aMStack_ad4;
    plVar12 = &(param_1->info).land[0].base_size;
    do {
      pMStack_b04 = (Map_Stack *)plVar12;
      RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)param_1,pMStack_b08);
      iVar10 = plVar12[-2];
      iVar8 = plVar12[-1];
      pMStack_ae4->x = 0;
      iVar2 = *plVar12;
      fStack_ae8 = (float)(iVar10 - iVar2);
      fVar13 = (float)(iVar8 - iVar2);
      iVar10 = iVar10 + iVar2;
      iVar8 = iVar8 + iVar2;
      if ((int)fStack_ae8 < 0) {
        fStack_ae8 = 0.0;
      }
      if ((int)fVar13 < 0) {
        fVar13 = 0.0;
      }
      if (param_1->_padding_ <= iVar10) {
        iVar10 = param_1->_padding_ + -1;
      }
      if (param_1->_padding_ <= iVar8) {
        iVar8 = param_1->_padding_ + -1;
      }
      RGE_Map::set_terrain
                ((RGE_Map *)param_1->_padding_,(RGE_Player *)0x0,(RGE_Game_World *)0x0,
                 SUB42(fStack_ae8,0),SUB42(fVar13,0),(short)iVar10,(short)iVar8,
                 (uchar)*(long *)((int)pMStack_b04 + -0xc),'\x01',0);
      bVar5 = *(uchar *)((int)pMStack_b04 + 8);
      puStack_af0 = (uchar *)CONCAT31(puStack_af0._1_3_,bVar5);
      (&aMStack_ad4[0].x)[bVar5] = ((iVar10 - (int)fStack_ae8) + 1) * ((iVar8 - (int)fVar13) + 1);
      for (fStack_afc = fVar13; fVar3 = fStack_ae8, (int)fStack_afc <= iVar8;
          fStack_afc = (float)((int)fStack_afc + 1)) {
        while ((int)fVar3 <= iVar10) {
          *(byte *)(*(int *)(param_1->_padding_ + (int)fStack_afc * 4) + -1 + (int)fVar3 + 1) =
               bVar5;
          fVar3 = (float)((int)fVar3 + 1);
        }
      }
      if ((0 < (int)fStack_ae8) && (fStack_aec = fVar13, (int)fVar13 <= iVar8)) {
        fStack_afc = (float)iStack_b00;
        lStack_af8 = (int)fStack_ae8 + -1;
        do {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)param_1,pMStack_b08,lStack_af8,(long)fStack_aec,
                     fStack_afc,0.0);
          fStack_aec = (float)((int)fStack_aec + 1);
        } while ((int)fStack_aec <= iVar8);
      }
      if ((0 < (int)fVar13) && (fStack_aec = fStack_ae8, (int)fStack_ae8 <= iVar10)) {
        fStack_afc = (float)iStack_b00;
        do {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)param_1,pMStack_b08,(long)fStack_aec,(int)fVar13 + -1,
                     fStack_afc,0.0);
          fStack_aec = (float)((int)fStack_aec + 1);
        } while ((int)fStack_aec <= iVar10);
      }
      if ((iVar10 < param_1->_padding_ + -1) && ((int)fVar13 <= iVar8)) {
        fStack_afc = (float)iStack_b00;
        do {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)param_1,pMStack_b08,iVar10 + 1,(long)fVar13,fStack_afc
                     ,0.0);
          fVar13 = (float)((int)fVar13 + 1);
        } while ((int)fVar13 <= iVar8);
      }
      if ((iVar8 < param_1->_padding_ + -1) && ((int)fStack_ae8 <= iVar10)) {
        fStack_afc = (float)iStack_b00;
        fVar13 = fStack_ae8;
        do {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)param_1,pMStack_b08,(long)fVar13,iVar8 + 1,fStack_afc,
                     0.0);
          fVar13 = (float)((int)fVar13 + 1);
        } while ((int)fVar13 <= iVar10);
      }
      iStack_b00 = iStack_b00 + 1;
      pMStack_ae4 = (Map_Stack *)&pMStack_ae4->y;
      plVar12 = (long *)((int)pMStack_b04 + 0x34);
      pMStack_b08 = pMStack_b08 + 1;
      pMStack_b04 = (Map_Stack *)plVar12;
    } while (iStack_b00 < (param_1->info).land_num);
  }
  do {
    cStack_af1 = '\x01';
    iStack_b00 = 0;
    if (0 < (param_1->info).land_num) {
      pMStack_b04 = aMStack_ad4;
      pMStack_b08 = aMStack_948;
      plVar12 = &(param_1->info).land[0].clumpiness_factor;
      do {
        iVar10 = iStack_b00;
        puStack_af0 = (uchar *)pMStack_b04->x;
        if (((int)puStack_af0 < ((RGE_Land_Info_Line *)(plVar12 + -7))->land_size) &&
           (pMVar7 = RGE_Random_Map_Module::pop_stack
                               ((RGE_Random_Map_Module *)param_1,pMStack_b08,&lStack_b0c,&lStack_b10
                                ,&fStack_ad8), pMVar7 != (Map_Stack *)0x0)) {
          cStack_af1 = '\0';
          bVar5 = RGE_RMM_Land_Generator::chance(param_1,lStack_b0c,lStack_b10,iVar10);
          iVar8 = debug_rand(s_C__msdev_work_age1_x1_rmm_land_c,299);
          if ((iVar8 * 100) / 0x7fff < (int)(uint)bVar5) {
            *(undefined1 *)(*(int *)(param_1->_padding_ + lStack_b10 * 4) + lStack_b0c) = 0xff;
          }
          else {
            lStack_af8 = *(int *)(param_1->_padding_ + lStack_b10 * 4) + lStack_b0c * 0x18;
            bVar5 = (byte)plVar12[-6];
            pMStack_ae4 = (Map_Stack *)CONCAT31(pMStack_ae4._1_3_,bVar5);
            bVar6 = RGE_RMM_Land_Generator::check_terrain_and_zone
                              (param_1,bVar5,(uchar)iVar10,lStack_b0c,lStack_b10);
            uVar9 = (uint)bVar6;
            iVar10 = iStack_b00;
            if (((uint)*(byte *)(*(int *)(param_1->_padding_ + lStack_b10 * 4) + lStack_b0c) ==
                 (param_1->info).land_num) && (uVar9 != 0)) {
              *(byte *)(lStack_af8 + 5) =
                   (bVar5 ^ *(byte *)(lStack_af8 + 5)) & 0x1f ^ *(byte *)(lStack_af8 + 5);
              *(uchar *)(*(int *)(param_1->_padding_ + lStack_b10 * 4) + lStack_b0c) =
                   *(uchar *)(plVar12 + -1);
              pMVar7 = pMStack_b08;
              if ((0 < lStack_b0c) &&
                 ((uint)*(byte *)(*(int *)(param_1->_padding_ + lStack_b10 * 4) + -1 + lStack_b0c)
                  == (param_1->info).land_num)) {
                iVar10 = debug_rand(s_C__msdev_work_age1_x1_rmm_land_c,0x138);
                pMVar7 = pMStack_b08;
                lStack_af8 = ((iVar10 * 100) / 0x7fff - uVar9 * *plVar12) + 0xfa;
                RGE_Random_Map_Module::push_stack
                          ((RGE_Random_Map_Module *)param_1,pMStack_b08,lStack_b0c + -1,lStack_b10,
                           0.0,(float)lStack_af8);
              }
              if ((lStack_b0c < iStack_adc) &&
                 ((uint)*(byte *)(*(int *)(param_1->_padding_ + lStack_b10 * 4) + 1 + lStack_b0c) ==
                  (param_1->info).land_num)) {
                iVar10 = debug_rand(s_C__msdev_work_age1_x1_rmm_land_c,0x13b);
                lStack_af8 = ((iVar10 * 100) / 0x7fff - uVar9 * *plVar12) + 0xfa;
                RGE_Random_Map_Module::push_stack
                          ((RGE_Random_Map_Module *)param_1,pMVar7,lStack_b0c + 1,lStack_b10,0.0,
                           (float)lStack_af8);
              }
              if ((0 < lStack_b10) &&
                 ((uint)*(byte *)(*(int *)(param_1->_padding_ + -4 + lStack_b10 * 4) + lStack_b0c)
                  == (param_1->info).land_num)) {
                iVar10 = debug_rand(s_C__msdev_work_age1_x1_rmm_land_c,0x13e);
                lStack_af8 = ((iVar10 * 100) / 0x7fff - uVar9 * *plVar12) + 0xfa;
                RGE_Random_Map_Module::push_stack
                          ((RGE_Random_Map_Module *)param_1,pMVar7,lStack_b0c,lStack_b10 + -1,0.0,
                           (float)lStack_af8);
              }
              if ((lStack_b10 < iStack_ae0) &&
                 ((uint)*(byte *)(*(int *)(param_1->_padding_ + 4 + lStack_b10 * 4) + lStack_b0c) ==
                  (param_1->info).land_num)) {
                iVar10 = debug_rand(s_C__msdev_work_age1_x1_rmm_land_c,0x141);
                lStack_af8 = ((iVar10 * 100) / 0x7fff - uVar9 * *plVar12) + 0xfa;
                RGE_Random_Map_Module::push_stack
                          ((RGE_Random_Map_Module *)param_1,pMVar7,lStack_b0c,lStack_b10 + 1,0.0,
                           (float)lStack_af8);
              }
              pMStack_b04->x = (long)(puStack_af0 + 1);
              iVar10 = iStack_b00;
            }
          }
        }
        iStack_b00 = iVar10 + 1;
        plVar12 = plVar12 + 0xd;
        pMStack_b08 = pMStack_b08 + 1;
        pMStack_b04 = (Map_Stack *)&pMStack_b04->y;
      } while (iStack_b00 < (param_1->info).land_num);
    }
  } while (cStack_af1 == '\0');
  iStack_b00 = 0;
  if (0 < (param_1->info).land_num) {
    pMVar7 = aMStack_948;
    puVar14 = &(param_1->info).land[0].zone;
    do {
      uVar1 = *puVar14;
      pMStack_ae4 = (Map_Stack *)CONCAT31(pMStack_ae4._1_3_,(char)*(long *)(puVar14 + -0x14));
      pMStack_b04 = pMVar7;
      puStack_af0 = puVar14;
      pMVar11 = RGE_Random_Map_Module::pop_stack
                          ((RGE_Random_Map_Module *)param_1,pMVar7,&lStack_b0c,&lStack_b10,
                           &fStack_ad8);
      pMVar4 = pMStack_b04;
      while (pMVar11 != (Map_Stack *)0x0) {
        iVar10 = *(int *)(param_1->_padding_ + lStack_b10 * 4) + lStack_b0c * 0x18;
        if (((((0 < lStack_b0c) &&
              (iVar8 = *(int *)(param_1->_padding_ + lStack_b10 * 4) + lStack_b0c,
              *(uchar *)(iVar8 + -1) == uVar1)) && (lStack_b0c < iStack_adc)) &&
            (*(uchar *)(iVar8 + 1) == uVar1)) ||
           (((0 < lStack_b10 &&
             (*(uchar *)(*(int *)(param_1->_padding_ + -4 + lStack_b10 * 4) + lStack_b0c) == uVar1))
            && ((lStack_b10 < iStack_ae0 &&
                (*(uchar *)(*(int *)(param_1->_padding_ + 4 + lStack_b10 * 4) + lStack_b0c) == uVar1
                )))))) {
          bVar5 = *(byte *)(iVar10 + 5);
          *(byte *)(iVar10 + 5) = ((byte)pMStack_ae4 ^ bVar5) & 0x1f ^ bVar5;
        }
        pMStack_b04 = pMVar4;
        pMVar11 = RGE_Random_Map_Module::pop_stack
                            ((RGE_Random_Map_Module *)param_1,pMVar4,&lStack_b0c,&lStack_b10,
                             &fStack_ad8);
        pMVar7 = pMVar4;
        puVar14 = puStack_af0;
        pMVar4 = pMStack_b04;
      }
      iStack_b00 = iStack_b00 + 1;
      puVar14 = puVar14 + 0x34;
      pMVar7 = pMVar7 + 1;
      pMStack_b04 = pMVar7;
      puStack_af0 = puVar14;
    } while (iStack_b00 < (param_1->info).land_num);
  }
  iVar10 = (param_1->info).land_num;
  iVar8 = 0;
  if (0 < iVar10) {
    pMVar7 = aMStack_948;
    do {
      RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)param_1,pMVar7);
      iVar10 = (param_1->info).land_num;
      iVar8 = iVar8 + 1;
      pMVar7 = pMVar7 + 1;
    } while (iVar8 < iVar10);
  }
  return CONCAT31((int3)((uint)iVar10 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_00485c49
// Address: 00485c49
RGE_Random_Map_Module * __thiscall
FUN_00485c49(RGE_Random_Map_Module *param_1,RGE_Map *param_2,RGE_Random_Map_Module *param_3,
            int param_4,undefined4 *param_5,undefined1 param_6)
{
  int iVar1;
  RGE_Random_Map_Module **ppRVar2;
  
  RGE_Random_Map_Module::RGE_Random_Map_Module(param_1,param_2,param_3,'\x01');
  param_1->_padding_ = (int)&RGE_RMM_Object_Generator::_vftable_;
  param_1[1]._padding_ = param_4;
  if (param_5 == (undefined4 *)0x0) {
    param_1[100].parent = (RGE_Random_Map_Module *)0x0;
    param_1[0x85].list = (RGE_Random_Map_Module_List *)0x0;
  }
  else {
    ppRVar2 = &param_1[1].parent;
    for (iVar1 = 0x632; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppRVar2 = (RGE_Random_Map_Module *)*param_5;
      param_5 = param_5 + 1;
      ppRVar2 = ppRVar2 + 1;
    }
  }
  param_1->schedule = 3.0;
  *(undefined1 *)&param_1[0x85].stack_offsets = param_6;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00485dba
// Address: 00485dba
undefined4 __fastcall FUN_00485dba(RGE_RMM_Object_Generator *param_1)
{
  int iVar1;
  RGE_Object_Info_Line *pRVar2;
  uchar *puVar3;
  
  if (param_1->add_terrain != '\0') {
    RGE_Map::set_terrain
              ((RGE_Map *)param_1->_padding_,*param_1->world->players,param_1->world,0,0,
               (short)param_1->_padding_ + -1,(short)param_1->_padding_ + -1,'\x01','\0',0);
  }
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)param_1);
  puVar3 = param_1->terrain_table;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    puVar3[0] = '\0';
    puVar3[1] = '\0';
    puVar3[2] = '\0';
    puVar3[3] = '\0';
    puVar3 = puVar3 + 4;
  }
  iVar1 = 0;
  if (0 < (param_1->info).object_num) {
    pRVar2 = (param_1->info).objects;
    do {
      RGE_RMM_Object_Generator::generate_objects(param_1,pRVar2);
      iVar1 = iVar1 + 1;
      pRVar2 = pRVar2 + 1;
    } while (iVar1 < (param_1->info).object_num);
  }
  RGE_Zone_Map_List::delete_zone_maps(*(RGE_Zone_Map_List **)(param_1->_padding_ + 0x8dc4));
  return 1;
}

// --------------------------------------------------

// Function: FUN_00485e48
// Address: 00485e48
void __thiscall FUN_00485e48(RGE_RMM_Object_Generator *param_1,RGE_Object_Info_Line *param_2)
{
  int iVar1;
  long *plVar2;
  
  if (param_2->scale_flag != '\0') {
    iVar1 = (param_1->_padding_ * param_1->_padding_ * param_2->number_of_groups) / 0x5100;
    param_2->number_of_groups = iVar1;
    if (iVar1 < 1) {
      param_2->number_of_groups = 1;
    }
  }
  iVar1 = param_2->land_id;
  if (iVar1 < 0) {
    if (iVar1 == -1) {
      RGE_RMM_Object_Generator::place_objects(param_1,param_2);
      return;
    }
    if (iVar1 == -2) {
      RGE_RMM_Object_Generator::place_avoid_objects(param_1,param_2,param_2->land_inner_radius);
    }
  }
  else {
    iVar1 = 0;
    if (0 < (param_1->info).land_num) {
      plVar2 = &(param_1->info).lands[0].y;
      do {
        if (plVar2[1] == param_2->land_id) {
          RGE_RMM_Object_Generator::place_land_objects
                    (param_1,param_2,((RGE_Land_Point_Info_Line *)(plVar2 + -1))->x,*plVar2,
                     param_2->land_inner_radius,param_2->land_outer_radius,iVar1);
        }
        iVar1 = iVar1 + 1;
        plVar2 = plVar2 + 4;
      } while (iVar1 < (param_1->info).land_num);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00485f08
// Address: 00485f08
// [HELPER] s_C__msdev_work_age1_x1_rmm_obj_cp: "C:\msdev\work\age1_x1\rmm_obj.cpp"
void __thiscall
FUN_00485f08(RGE_Random_Map_Module *param_1,Map_Stack *param_2,int param_3,int param_4,
            undefined4 param_5,int param_6)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  Map_Stack *pMVar5;
  int iStack_10;
  Map_Stack *pMStack_c;
  int iStack_4;
  
  param_2->next = (Map_Stack *)0x0;
  param_2->prev = (Map_Stack *)0x0;
  if (((param_3 < 0) || (param_4 < 0)) || (param_6 < 0)) {
    param_3 = 0;
    param_6 = param_1->map_width + -1;
    param_4 = 0;
    iStack_10 = param_1->map_height + -1;
  }
  else {
    iVar4 = param_3 - param_6;
    iVar3 = param_4 - param_6;
    iVar1 = param_3 + param_6;
    iStack_10 = param_4 + param_6;
    param_3 = iVar4;
    if (iVar4 < 0) {
      param_3 = 0;
    }
    param_4 = iVar3;
    if (iVar3 < 0) {
      param_4 = 0;
    }
    if (param_1->map_width <= iVar1) {
      iVar1 = param_1->map_width + -1;
    }
    param_6 = iVar1;
    if (param_1->map_height <= iStack_10) {
      iStack_10 = param_1->map_height + -1;
    }
  }
  pMStack_c = param_2;
  if (param_4 <= iStack_10) {
    iVar1 = param_4 * 4;
    iStack_4 = (iStack_10 - param_4) + 1;
    do {
      if (param_3 <= param_6) {
        iVar4 = param_3 * 0x18;
        iVar3 = param_3;
        do {
          if (*(char *)(*(int *)((int)param_1->search_map_rows + iVar1) + iVar3) != '\0') {
            pMVar5 = (Map_Stack *)(*(int *)((int)param_1->stack_offsets + iVar1) + iVar4);
            RGE_Random_Map_Module::add_stack_node(param_1,pMStack_c,pMVar5);
            pMStack_c = pMVar5;
          }
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x18;
        } while (iVar3 <= param_6);
      }
      iVar1 = iVar1 + 4;
      iStack_4 = iStack_4 + -1;
    } while (iStack_4 != 0);
  }
  iVar1 = (param_6 - param_3) + -1;
  iVar3 = (iStack_10 - param_4) + -1;
  if (((1 < iVar1) && (1 < iVar3)) &&
     (param_6 = (int)(iVar3 * iVar1 + (iVar3 * iVar1 >> 0x1f & 3U)) >> 2, 0 < param_6)) {
    do {
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0xaf);
      iVar2 = (iVar4 * iVar1) / 0x7fff + param_3;
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0xb0);
      iVar4 = (iVar4 * iVar3) / 0x7fff + param_4;
      if (param_1->search_map_rows[iVar4][iVar2] != '\0') {
        RGE_Random_Map_Module::add_stack_node(param_1,param_2,param_1->stack_offsets[iVar4] + iVar2)
        ;
      }
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048610b
// Address: 0048610b
uint __thiscall FUN_0048610b(int param_1,int param_2,int param_3,int param_4)
{
  uint in_EAX;
  int iVar1;
  uint3 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  if (*(int *)(param_1 + 0x18f8) < 1) {
    return in_EAX & 0xffffff00;
  }
  piVar4 = (int *)(param_1 + 0x12cc);
  while( true ) {
    iVar3 = param_3 - piVar4[-1];
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    iVar1 = param_4 - *piVar4;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    uVar2 = (uint3)((uint)iVar1 >> 8);
    if ((iVar3 < *(int *)(param_2 + 0x24)) && (iVar1 < *(int *)(param_2 + 0x24))) break;
    iVar5 = iVar5 + 1;
    piVar4 = piVar4 + 4;
    if (*(int *)(param_1 + 0x18f8) <= iVar5) {
      return (uint)uVar2 << 8;
    }
  }
  return CONCAT31(uVar2,1);
}

// --------------------------------------------------

// Function: FUN_00486171
// Address: 00486171
void __thiscall FUN_00486171(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_2 - param_4;
  iVar2 = param_3 - param_4;
  param_2 = param_2 + param_4;
  param_4 = param_4 + param_3;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (*(int *)(param_1 + 0x14) <= param_2) {
    param_2 = *(int *)(param_1 + 0x14) + -1;
  }
  if (*(int *)(param_1 + 0x18) <= param_4) {
    param_4 = *(int *)(param_1 + 0x18) + -1;
  }
  for (; iVar2 <= param_4; iVar2 = iVar2 + 1) {
    if (iVar3 <= param_2) {
      iVar1 = iVar3;
      do {
        iVar1 = iVar1 + 1;
        *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x24) + iVar2 * 4) + -1 + iVar1) = param_5;
      } while (iVar1 <= param_2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00486206
// Address: 00486206
void __thiscall FUN_00486206(RGE_Random_Map_Module *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_2 - param_4;
  iVar1 = param_3 - param_4;
  param_2 = param_4 + param_2;
  param_4 = param_4 + param_3;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (param_1->map_width <= param_2) {
    param_2 = param_1->map_width + -1;
  }
  if (param_1->map_height <= param_4) {
    param_4 = param_1->map_height + -1;
  }
  for (; iVar1 <= param_4; iVar1 = iVar1 + 1) {
    if (iVar2 <= param_2) {
      iVar3 = iVar2 * 0x18;
      iVar4 = (param_2 - iVar2) + 1;
      do {
        RGE_Random_Map_Module::remove_stack_node
                  (param_1,(Map_Stack *)((int)&param_1->stack_offsets[iVar1]->x + iVar3));
        iVar3 = iVar3 + 0x18;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004862aa
// Address: 004862aa
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004862aa(RGE_RMM_Object_Generator *param_1,RGE_Object_Info_Line *param_2)
{
  uchar uVar1;
  RGE_Player *pRVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Object_Info_Line *pRVar4;
  char cVar5;
  short sVar6;
  Map_Stack *pMVar7;
  uint uVar8;
  uint uVar9;
  RGE_Land_Point_Info_Line *pRVar10;
  int iVar11;
  undefined4 *puVar12;
  int iStack_30;
  int iStack_2c;
  float fStack_28;
  int iStack_24;
  int iStack_20;
  float fStack_1c;
  Map_Stack MStack_18;
  
  pRVar4 = param_2;
  iVar11 = 0;
  uVar8 = param_1->_padding_ * param_1->_padding_;
  puVar12 = (undefined4 *)param_1->_padding_;
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar12 = 0x1010101;
    puVar12 = puVar12 + 1;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined1 *)puVar12 = 1;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  if (0 < (param_1->info).land_num) {
    pRVar10 = (param_1->info).lands;
    do {
      RGE_RMM_Object_Generator::set_search_area
                (param_1,pRVar10->x,pRVar10->y,param_2->land_inner_radius,'\0');
      iVar11 = iVar11 + 1;
      pRVar10 = pRVar10 + 1;
    } while (iVar11 < (param_1->info).land_num);
  }
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)param_1,&MStack_18);
  RGE_RMM_Object_Generator::make_placement_stack(param_1,&MStack_18,-1,-1,-1,-1);
  pRVar2 = param_1->world->players[param_2->player_id & (param_2->player_id < 0) - 1];
  iStack_24 = param_2->number_of_groups;
  pMVar7 = RGE_Random_Map_Module::pop_stack
                     ((RGE_Random_Map_Module *)param_1,&MStack_18,&iStack_2c,&iStack_30,&fStack_1c);
  while ((pMVar7 != (Map_Stack *)0x0 && (0 < iStack_24))) {
    if ((pRVar4->terrain < 0) ||
       ((*(byte *)(*(int *)(param_1->_padding_ + iStack_30 * 4) + 5 + iStack_2c * 0x18) & 0x1f) ==
        pRVar4->terrain)) {
      fStack_28 = (float)iStack_2c;
      param_2 = (RGE_Object_Info_Line *)(float)iStack_30;
      pRVar3 = pRVar2->master_objects[pRVar4->obj_id];
      sVar6 = __ftol();
      iStack_20 = (int)sVar6;
      if ((float)DAT_00571edc < pRVar3->radius_x - (float)iStack_20) {
        fStack_28 = fStack_28 - ram0x00571ee0;
      }
      sVar6 = __ftol();
      iStack_20 = (int)sVar6;
      if ((float)DAT_00571edc < pRVar3->radius_y - (float)iStack_20) {
        param_2 = (RGE_Object_Info_Line *)((float)param_2 - ram0x00571ee0);
      }
      cVar5 = (**(code **)(pRVar3->_padding_ + 0x20))(pRVar2,fStack_28,param_2,0,0,1,1,1,0,1);
      if (cVar5 == '\0') {
        RGE_RMM_Object_Generator::remove_area_from_lists
                  (param_1,iStack_2c,iStack_30,pRVar4->object_exclusion_zone);
        uVar1 = pRVar4->group_flag;
        if (uVar1 == '\0') {
          (**(code **)(pRVar2->_padding_ + 0x94))(pRVar4->obj_id,fStack_28,param_2,0,1);
        }
        else if (uVar1 == '\x01') {
          RGE_RMM_Object_Generator::place_group(param_1,pRVar4,iStack_2c,iStack_30,pRVar2);
        }
        else if (uVar1 == '\x02') {
          RGE_RMM_Object_Generator::place_cluster(param_1,pRVar4,iStack_2c,iStack_30,pRVar2);
        }
        iStack_24 = iStack_24 + -1;
      }
    }
    pMVar7 = RGE_Random_Map_Module::pop_stack
                       ((RGE_Random_Map_Module *)param_1,&MStack_18,&iStack_2c,&iStack_30,&fStack_1c
                       );
  }
  RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)param_1,&MStack_18);
  return;
}

// --------------------------------------------------

// Function: FUN_004864e8
// Address: 004864e8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004864e8(RGE_RMM_Object_Generator *param_1,RGE_Object_Info_Line *param_2)
{
  uchar uVar1;
  RGE_Player *pRVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Object_Info_Line *pRVar4;
  char cVar5;
  short sVar6;
  Map_Stack *pMVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iStack_30;
  int iStack_2c;
  float fStack_28;
  int iStack_24;
  int iStack_20;
  float fStack_1c;
  Map_Stack MStack_18;
  
  pRVar4 = param_2;
  uVar8 = param_1->_padding_ * param_1->_padding_;
  puVar10 = (undefined4 *)param_1->_padding_;
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar10 = 0x1010101;
    puVar10 = puVar10 + 1;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined1 *)puVar10 = 1;
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)param_1,&MStack_18);
  RGE_RMM_Object_Generator::make_placement_stack(param_1,&MStack_18,-1,-1,-1,-1);
  pRVar2 = param_1->world->players[param_2->player_id & (param_2->player_id < 0) - 1];
  iStack_24 = param_2->number_of_groups;
  pMVar7 = RGE_Random_Map_Module::pop_stack
                     ((RGE_Random_Map_Module *)param_1,&MStack_18,&iStack_2c,&iStack_30,&fStack_1c);
  while ((pMVar7 != (Map_Stack *)0x0 && (0 < iStack_24))) {
    if ((pRVar4->terrain < 0) ||
       ((*(byte *)(*(int *)(param_1->_padding_ + iStack_30 * 4) + 5 + iStack_2c * 0x18) & 0x1f) ==
        pRVar4->terrain)) {
      fStack_28 = (float)iStack_2c;
      param_2 = (RGE_Object_Info_Line *)(float)iStack_30;
      pRVar3 = pRVar2->master_objects[pRVar4->obj_id];
      sVar6 = __ftol();
      iStack_20 = (int)sVar6;
      if ((float)DAT_00571edc < pRVar3->radius_x - (float)iStack_20) {
        fStack_28 = fStack_28 - ram0x00571ee0;
      }
      sVar6 = __ftol();
      iStack_20 = (int)sVar6;
      if ((float)DAT_00571edc < pRVar3->radius_y - (float)iStack_20) {
        param_2 = (RGE_Object_Info_Line *)((float)param_2 - ram0x00571ee0);
      }
      cVar5 = (**(code **)(pRVar3->_padding_ + 0x20))(pRVar2,fStack_28,param_2,0,0,1,1,1,0,1);
      if (cVar5 == '\0') {
        RGE_RMM_Object_Generator::remove_area_from_lists
                  (param_1,iStack_2c,iStack_30,pRVar4->object_exclusion_zone);
        uVar1 = pRVar4->group_flag;
        if (uVar1 == '\0') {
          (**(code **)(pRVar2->_padding_ + 0x94))(pRVar4->obj_id,fStack_28,param_2,0,1);
        }
        else if (uVar1 == '\x01') {
          RGE_RMM_Object_Generator::place_group(param_1,pRVar4,iStack_2c,iStack_30,pRVar2);
        }
        else if (uVar1 == '\x02') {
          RGE_RMM_Object_Generator::place_cluster(param_1,pRVar4,iStack_2c,iStack_30,pRVar2);
        }
        iStack_24 = iStack_24 + -1;
      }
    }
    pMVar7 = RGE_Random_Map_Module::pop_stack
                       ((RGE_Random_Map_Module *)param_1,&MStack_18,&iStack_2c,&iStack_30,&fStack_1c
                       );
  }
  RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)param_1,&MStack_18);
  return;
}

// --------------------------------------------------

// Function: FUN_004866f3
// Address: 004866f3
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004866f3(RGE_RMM_Object_Generator *param_1,RGE_Object_Info_Line *param_2,float param_3,
            int param_4,long param_5,float param_6,RGE_Zone_Map *param_7)
{
  int iVar1;
  RGE_Player *pRVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Object_Info_Line *pRVar4;
  int iVar5;
  uchar uVar6;
  uchar uVar7;
  char cVar8;
  short sVar9;
  Map_Stack *pMVar10;
  uint uVar11;
  uint uVar12;
  RGE_Land_Point_Info_Line *pRVar13;
  undefined4 *puVar14;
  int iVar15;
  long lStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  float fStack_20;
  int iStack_1c;
  Map_Stack MStack_18;
  
  iVar5 = param_5;
  pRVar4 = param_2;
  iStack_28 = param_5 + param_4;
  iStack_34 = (int)param_3 - param_5;
  iStack_2c = param_4 - param_5;
  iStack_30 = (int)param_3 + param_5;
  if (iStack_34 < 0) {
    iStack_34 = 0;
  }
  if (iStack_2c < 0) {
    iStack_2c = 0;
  }
  iVar15 = param_1->_padding_;
  if (iVar15 <= iStack_30) {
    iStack_30 = iVar15 + -1;
  }
  iVar1 = param_1->_padding_;
  if (iVar1 <= iStack_28) {
    iStack_28 = iVar1 + -1;
  }
  puVar14 = (undefined4 *)param_1->_padding_;
  for (uVar11 = (uint)(iVar1 * iVar15) >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *puVar14 = 0x1010101;
    puVar14 = puVar14 + 1;
  }
  for (uVar11 = iVar1 * iVar15 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined1 *)puVar14 = 1;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
  }
  iVar15 = 0;
  if (0 < (param_1->info).land_num) {
    pRVar13 = (param_1->info).lands;
    do {
      RGE_RMM_Object_Generator::set_search_area(param_1,pRVar13->x,pRVar13->y,iVar5,'\0');
      iVar15 = iVar15 + 1;
      pRVar13 = pRVar13 + 1;
    } while (iVar15 < (param_1->info).land_num);
  }
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)param_1,&MStack_18);
  RGE_RMM_Object_Generator::make_placement_stack
            (param_1,&MStack_18,(long)param_3,param_4,iVar5,(long)param_6);
  uVar11 = param_2->player_id;
  if ((uVar11 < 0x80000000) ||
     (uVar11 = (param_1->info).lands[(int)param_7].player_id, uVar12 = 0, 0 < (int)uVar11)) {
    uVar12 = uVar11;
  }
  pRVar2 = param_1->world->players[uVar12];
  if (pRVar2->master_objects[param_2->obj_id] != (RGE_Master_Static_Object *)0x0) {
    param_7 = RGE_Zone_Map_List::get_zone_map
                        (*(RGE_Zone_Map_List **)(param_1->_padding_ + 0x8dc4),
                         param_1->world->terrains[pRVar2->master_objects[param_2->obj_id]->terrain],
                         0x20,&iStack_1c);
    uVar6 = RGE_Zone_Map::get_zone_info(param_7,(long)param_3,param_4);
    param_2 = (RGE_Object_Info_Line *)param_2->number_of_groups;
    pMVar10 = RGE_Random_Map_Module::pop_stack
                        ((RGE_Random_Map_Module *)param_1,&MStack_18,&param_5,&lStack_38,&fStack_20)
    ;
    while ((pMVar10 != (Map_Stack *)0x0 && (0 < (int)param_2))) {
      uVar7 = RGE_Zone_Map::get_zone_info(param_7,param_5,lStack_38);
      if (((uVar6 == uVar7) &&
          ((pRVar4->terrain < 0 ||
           ((*(byte *)(*(int *)(param_1->_padding_ + lStack_38 * 4) + 5 + param_5 * 0x18) & 0x1f) ==
            pRVar4->terrain)))) &&
         ((param_5 <= iStack_34 ||
          (((iStack_30 <= param_5 || (lStack_38 <= iStack_2c)) || (iStack_28 <= lStack_38)))))) {
        param_6 = (float)param_5;
        param_3 = (float)lStack_38;
        pRVar3 = pRVar2->master_objects[pRVar4->obj_id];
        sVar9 = __ftol();
        iStack_24 = (int)sVar9;
        if ((float)DAT_00571edc < pRVar3->radius_x - (float)iStack_24) {
          param_6 = param_6 - ram0x00571ee0;
        }
        sVar9 = __ftol();
        iStack_24 = (int)sVar9;
        if ((float)DAT_00571edc < pRVar3->radius_y - (float)iStack_24) {
          param_3 = param_3 - ram0x00571ee0;
        }
        cVar8 = (**(code **)(pRVar3->_padding_ + 0x20))(pRVar2,param_6,param_3,0,0,1,1,1,1,1);
        if (cVar8 == '\0') {
          RGE_RMM_Object_Generator::remove_area_from_lists
                    (param_1,param_5,lStack_38,pRVar4->object_exclusion_zone);
          uVar7 = pRVar4->group_flag;
          if (uVar7 == '\0') {
            (**(code **)(pRVar2->_padding_ + 0x94))(pRVar4->obj_id,param_6,param_3,0,1);
LAB_004869ee:
            param_2 = (RGE_Object_Info_Line *)((int)param_2 + -1);
          }
          else if (uVar7 == '\x01') {
            RGE_RMM_Object_Generator::place_group(param_1,pRVar4,param_5,lStack_38,pRVar2);
            param_2 = (RGE_Object_Info_Line *)((int)param_2 + -1);
          }
          else {
            if (uVar7 != '\x02') goto LAB_004869ee;
            RGE_RMM_Object_Generator::place_cluster(param_1,pRVar4,param_5,lStack_38,pRVar2);
            param_2 = (RGE_Object_Info_Line *)((int)param_2 + -1);
          }
        }
        else if ((pRVar4->group_flag == '\0') && (MStack_18.next == (Map_Stack *)0x0)) {
          (**(code **)(pRVar2->_padding_ + 0x94))(pRVar4->obj_id,param_6,param_3,0,1);
        }
      }
      pMVar10 = RGE_Random_Map_Module::pop_stack
                          ((RGE_Random_Map_Module *)param_1,&MStack_18,&param_5,&lStack_38,
                           &fStack_20);
    }
    RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)param_1,&MStack_18);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00486a57
// Address: 00486a57
// [HELPER] s_C__msdev_work_age1_x1_rmm_obj_cp: "C:\msdev\work\age1_x1\rmm_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00486a57(RGE_RMM_Object_Generator *param_1,int *param_2,float param_3,int param_4,int *param_5)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  Map_Stack *pMVar7;
  int iStack_2c;
  int iStack_28;
  RGE_RMM_Object_Generator *pRStack_24;
  int iStack_20;
  float fStack_1c;
  Map_Stack MStack_18;
  
  piVar3 = param_5;
  pRStack_24 = param_1;
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)param_1,&MStack_18);
  RGE_RMM_Object_Generator::make_placement_stack
            (param_1,&MStack_18,(long)param_3,param_4,0,param_2[6]);
  param_4 = param_2[3];
  iVar1 = param_2[4];
  iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x212);
  param_4 = param_4 + ((iVar6 * iVar1 * 2) / 0x7fff - iVar1);
  if (param_4 < 1) {
    param_4 = 1;
  }
  pMVar7 = RGE_Random_Map_Module::pop_stack
                     ((RGE_Random_Map_Module *)param_1,&MStack_18,&iStack_28,&iStack_2c,&fStack_1c);
  while ((pMVar7 != (Map_Stack *)0x0 && (0 < param_4))) {
    if ((param_2[1] < 0) ||
       (((byte)((RGE_Tile **)param_1->_padding_)[iStack_2c][iStack_28].field_0x5 & 0x1f) ==
        param_2[1])) {
      param_5 = (int *)(float)iStack_28;
      param_3 = (float)iStack_2c;
      piVar2 = *(int **)(piVar3[9] + *param_2 * 4);
      sVar5 = __ftol();
      iStack_20 = (int)sVar5;
      if ((float)DAT_00571edc < (float)piVar2[0xc] - (float)iStack_20) {
        param_5 = (int *)((float)param_5 - ram0x00571ee0);
      }
      sVar5 = __ftol();
      iStack_20 = (int)sVar5;
      if ((float)DAT_00571edc < (float)piVar2[0xd] - (float)iStack_20) {
        param_3 = param_3 - ram0x00571ee0;
      }
      cVar4 = (**(code **)(*piVar2 + 0x20))(piVar3,param_5,param_3,0,0,1,1,1,0,1);
      param_1 = pRStack_24;
      if (cVar4 == '\0') {
        (**(code **)(*piVar3 + 0x94))(*param_2,param_5,param_3,0,1);
        param_4 = param_4 + -1;
        param_1 = pRStack_24;
      }
    }
    pMVar7 = RGE_Random_Map_Module::pop_stack
                       ((RGE_Random_Map_Module *)param_1,&MStack_18,&iStack_28,&iStack_2c,&fStack_1c
                       );
  }
  RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)param_1,&MStack_18);
  return;
}

// --------------------------------------------------

// Function: FUN_00486c33
// Address: 00486c33
// [HELPER] s_C__msdev_work_age1_x1_rmm_obj_cp: "C:\msdev\work\age1_x1\rmm_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00486c33(RGE_Random_Map_Module *param_1,int *param_2,int param_3,int param_4,int *param_5)
{
  int *piVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  Map_Stack *pMVar5;
  int iVar6;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int iStack_38;
  int iStack_34;
  float fStack_30;
  float fStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  float fStack_1c;
  Map_Stack MStack_18;
  
  MStack_18.next = (Map_Stack *)0x0;
  MStack_18.prev = (Map_Stack *)0x0;
  RGE_Random_Map_Module::init_stack(param_1,&MStack_18);
  RGE_Random_Map_Module::add_stack_node
            (param_1,&MStack_18,param_1->stack_offsets[param_4] + param_3);
  iVar6 = param_2[6];
  iStack_24 = param_4 - iVar6;
  iStack_28 = param_3 + iVar6;
  iStack_20 = param_4 + iVar6;
  param_4 = param_3 - iVar6;
  if (param_3 - iVar6 < 0) {
    param_4 = 0;
  }
  if (iStack_24 < 0) {
    iStack_24 = 0;
  }
  if (param_1->map_width <= iStack_28) {
    iStack_28 = param_1->map_width + -1;
  }
  iStack_38 = iStack_24;
  if (param_1->map_height <= iStack_20) {
    iStack_20 = param_1->map_height + -1;
  }
  for (; iVar6 = param_4, iStack_38 <= iStack_20; iStack_38 = iStack_38 + 1) {
    while (iStack_34 = iVar6, iStack_34 <= iStack_28) {
      param_1->search_map_rows[iStack_38][iStack_34] = '\x01';
      iVar6 = iStack_34 + 1;
    }
  }
  param_3 = param_2[3];
  iVar6 = param_2[4];
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x256);
  param_3 = param_3 + ((iVar4 * iVar6 * 2) / 0x7fff - iVar6);
  if (param_3 < 1) {
    param_3 = 1;
  }
  pMVar5 = RGE_Random_Map_Module::pop_stack(param_1,&MStack_18,&iStack_34,&iStack_38,&fStack_1c);
  while ((pMVar5 != (Map_Stack *)0x0 && (0 < param_3))) {
    fStack_2c = (float)iStack_34;
    piVar1 = *(int **)(param_5[9] + *param_2 * 4);
    fStack_30 = (float)iStack_38;
    sVar3 = __ftol();
    if ((float)DAT_00571edc < (float)piVar1[0xc] - (float)(int)sVar3) {
      fStack_2c = fStack_2c - ram0x00571ee0;
    }
    sVar3 = __ftol();
    if ((float)DAT_00571edc < (float)piVar1[0xd] - (float)(int)sVar3) {
      fStack_30 = fStack_30 - ram0x00571ee0;
    }
    iVar6 = *piVar1;
    (**(code **)(iVar6 + 0x24))(&fStack_2c,&fStack_30,param_1[1]._padding_,1);
    cVar2 = (**(code **)(iVar6 + 0x20))(param_5,unaff_EBX,unaff_EBP,0,0,1,1,1,0,1);
    if (cVar2 == '\0') {
      (**(code **)(*param_5 + 0x94))(*param_2,fStack_2c,fStack_30,0,1);
      param_3 = param_3 + -1;
      param_1->search_map_rows[iStack_38][iStack_34] = '\0';
      if ((param_4 < iStack_34) && (param_1->search_map_rows[iStack_38][iStack_34 + -1] != '\0')) {
        iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x270);
        RGE_Random_Map_Module::push_stack
                  (param_1,&MStack_18,iStack_34 + -1,iStack_38,0.0,(float)iVar6);
      }
      if ((iStack_34 < iStack_28) && (param_1->search_map_rows[iStack_38][iStack_34 + 1] != '\0')) {
        iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x273);
        RGE_Random_Map_Module::push_stack
                  (param_1,&MStack_18,iStack_34 + 1,iStack_38,0.0,(float)iVar6);
      }
      if ((iStack_24 < iStack_38) && (param_1->search_map_rows[iStack_38 + -1][iStack_34] != '\0'))
{
        iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x276);
        RGE_Random_Map_Module::push_stack
                  (param_1,&MStack_18,iStack_34,iStack_38 + -1,0.0,(float)iVar6);
      }
      if ((iStack_38 < iStack_20) && (param_1->search_map_rows[iStack_38 + 1][iStack_34] != '\0')) {
        iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x279);
        RGE_Random_Map_Module::push_stack
                  (param_1,&MStack_18,iStack_34,iStack_38 + 1,0.0,(float)iVar6);
      }
    }
    pMVar5 = RGE_Random_Map_Module::pop_stack(param_1,&MStack_18,&iStack_34,&iStack_38,&fStack_1c);
  }
  RGE_Random_Map_Module::deinit_stack(param_1,&MStack_18);
  return;
}

// --------------------------------------------------

// Function: FUN_0048700e
// Address: 0048700e
RGE_Random_Map_Module * __thiscall
FUN_0048700e(RGE_Random_Map_Module *param_1,RGE_Map *param_2,RGE_Random_Map_Module *param_3,
            int *param_4)
{
  int iVar1;
  RGE_Random_Map_Module *pRVar2;
  
  RGE_Random_Map_Module::RGE_Random_Map_Module(param_1,param_2,param_3,'\x01');
  param_1->_padding_ = (int)&RGE_RMM_Shallows_Generator::_vftable_;
  param_1->schedule = 1.1;
  pRVar2 = param_1 + 1;
  for (iVar1 = 199; iVar1 != 0; iVar1 = iVar1 + -1) {
    pRVar2->_padding_ = *param_4;
    param_4 = param_4 + 1;
    pRVar2 = (RGE_Random_Map_Module *)&pRVar2->parent;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048704b
// Address: 0048704b
// [HELPER] s_C__msdev_work_age1_x1_rmm_shal_c: "C:\msdev\work\age1_x1\rmm_shal.cpp"
undefined4 __fastcall FUN_0048704b(RGE_RMM_Shallows_Generator *param_1)
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_4;
  
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)param_1);
  iVar3 = (param_1->info).shallows_num;
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      iVar5 = iVar4 + 1;
      iVar6 = iVar5;
      if (iVar5 < iVar3) {
        do {
          RGE_RMM_Shallows_Generator::make_tribe_connections(param_1,iVar4,iVar6);
          iVar6 = iVar6 + 1;
        } while (iVar6 < (param_1->info).shallows_num);
      }
      iVar3 = (param_1->info).shallows_num;
      iVar4 = iVar5;
    } while (iVar5 < iVar3);
  }
  iVar3 = (param_1->info).shallows_num;
  iStack_4 = 2;
  (param_1->info).shallows_num = iVar3 + 2;
  do {
    bVar1 = false;
    do {
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_shal_c,0x45);
      iVar4 = (iVar4 * (param_1->_padding_ + -1)) / 0x7fff;
      iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_shal_c,0x46);
      iVar5 = (iVar5 * (param_1->_padding_ + -1)) / 0x7fff;
      bVar2 = *(byte *)(*(int *)(param_1->_padding_ + iVar5 * 4) + 5 + iVar4 * 0x18) & 0x1f;
      if (((bVar2 != 1) && (bVar2 != 0x16)) && (bVar2 != 4)) {
        (param_1->info).shallows[iVar3 + 1].x = iVar4;
        bVar1 = true;
        (param_1->info).shallows[iVar3 + 1].y = iVar5;
      }
    } while (!bVar1);
    bVar1 = false;
    do {
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_shal_c,0x54);
      iVar4 = (iVar4 * (param_1->_padding_ + -1)) / 0x7fff;
      iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_shal_c,0x55);
      iVar5 = (iVar5 * (param_1->_padding_ + -1)) / 0x7fff;
      bVar2 = *(byte *)(*(int *)(param_1->_padding_ + iVar5 * 4) + 5 + iVar4 * 0x18) & 0x1f;
      if (((bVar2 != 1) && (bVar2 != 0x16)) && (bVar2 != 4)) {
        bVar1 = true;
        (param_1->info).shallows[iVar3].x = iVar4;
        (param_1->info).shallows[iVar3].y = iVar5;
      }
    } while (!bVar1);
    RGE_RMM_Shallows_Generator::make_tribe_connections(param_1,iVar3 + 1,iVar3);
    iStack_4 = iStack_4 + -1;
  } while (iStack_4 != 0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004871f2
// Address: 004871f2
// [HELPER] s_C__msdev_work_age1_x1_rmm_shal_c: "C:\msdev\work\age1_x1\rmm_shal.cpp"
void __thiscall FUN_004871f2(RGE_Random_Map_Module *param_1,int param_2,int param_3)
{
  undefined1 *puVar1;
  int iVar2;
  Map_Stack *pMVar3;
  int iVar4;
  byte bVar5;
  undefined4 *puVar6;
  RGE_Random_Map_Module *pRVar7;
  int iVar8;
  int iStack_e0;
  RGE_Random_Map_Module *pRStack_dc;
  long lStack_d8;
  int iStack_d4;
  int iStack_d0;
  RGE_Random_Map_Module *pRStack_cc;
  RGE_Random_Map_Module *pRStack_c8;
  int iStack_c4;
  int iStack_c0;
  float fStack_bc;
  Map_Stack MStack_b8;
  float fStack_a0;
  undefined4 auStack_9c [21];
  undefined4 uStack_48;
  
  fStack_a0 = 0.0;
  lStack_d8 = (&param_1[1]._padding_)[param_2 * 2];
  pRStack_c8 = (&param_1[1].parent)[param_2 * 2];
  iVar2 = (&param_1[1]._padding_)[param_3 * 2];
  pRVar7 = (&param_1[1].parent)[param_3 * 2];
  puVar6 = auStack_9c;
  for (iVar4 = 0x27; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  iStack_d4 = iVar2;
  pRStack_cc = pRVar7;
  RGE_Random_Map_Module::init_stack(param_1,&MStack_b8);
  fStack_a0 = 1.0;
  auStack_9c[1] = 0x3f800000;
  auStack_9c[0] = 0x40e00000;
  uStack_48 = 0x41600000;
  auStack_9c[3] = 0x40000000;
  RGE_Random_Map_Module::find_path
            (param_1,lStack_d8,(long)pRStack_c8,&iStack_d4,(long *)&pRStack_cc,&fStack_a0);
  if (((((iStack_d4 != iVar2) || (pRStack_cc != pRVar7)) || (iStack_d4 < 0)) ||
      ((param_1->map_width <= iStack_d4 || ((int)pRStack_cc < 0)))) ||
     (param_1->map_height <= (int)pRStack_cc)) {
    return;
  }
  MStack_b8.next = (Map_Stack *)0x0;
  MStack_b8.prev = (Map_Stack *)0x0;
  iStack_c4 = 0;
  do {
    pRStack_dc = pRStack_cc;
    iStack_e0 = iStack_d4;
    switch(param_1->search_map_rows[(int)pRStack_cc][iStack_d4]) {
    case '\x06':
      pRStack_dc = (RGE_Random_Map_Module *)((int)&pRStack_cc->_padding_ + 1);
      break;
    case '\a':
      pRStack_dc = (RGE_Random_Map_Module *)((int)&pRStack_cc[-1].stack_offsets + 3);
      break;
    case '\b':
      pRStack_dc = (RGE_Random_Map_Module *)((int)&pRStack_cc->_padding_ + 1);
    case '\x04':
      iStack_e0 = iStack_d4 + 1;
      break;
    case '\t':
      pRStack_dc = (RGE_Random_Map_Module *)((int)&pRStack_cc[-1].stack_offsets + 3);
      iStack_e0 = iStack_d4 + 1;
      break;
    case '\n':
      pRStack_dc = (RGE_Random_Map_Module *)((int)&pRStack_cc->_padding_ + 1);
    case '\x05':
      iStack_e0 = iStack_d4 + -1;
      break;
    case '\v':
      pRStack_dc = (RGE_Random_Map_Module *)((int)&pRStack_cc[-1].stack_offsets + 3);
      iStack_e0 = iStack_d4 + -1;
      break;
    default:
      iStack_c4 = 1;
    }
    if (((iStack_e0 < 0) || (param_1->map_width <= iStack_e0)) ||
       (((int)pRStack_dc < 0 || (param_1->map_height <= (int)pRStack_dc)))) {
      iStack_c4 = 1;
    }
    if (iStack_c4 != 0) {
      pMVar3 = RGE_Random_Map_Module::pop_stack
                         (param_1,&MStack_b8,&iStack_e0,(long *)&pRStack_dc,&fStack_bc);
      while (pMVar3 != (Map_Stack *)0x0) {
        puVar1 = &param_1->map_row_offset[(int)pRStack_dc][iStack_e0].field_0x5;
        *puVar1 = *puVar1 & 0xe4 | 4;
        pMVar3 = RGE_Random_Map_Module::pop_stack
                           (param_1,&MStack_b8,&iStack_e0,(long *)&pRStack_dc,&fStack_bc);
      }
      RGE_Random_Map_Module::deinit_stack(param_1,&MStack_b8);
      return;
    }
    bVar5 = param_1->map_row_offset[(int)pRStack_dc][iStack_e0].field_0x5 & 0x1f;
    if ((bVar5 == 1) || (bVar5 == 0x16)) {
      iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_shal_c,0xc6);
      iStack_d0 = (iStack_e0 - (iVar2 * 2) / 0x7fff) + -1;
      if (iStack_d0 < 0) {
        iStack_d0 = 0;
      }
      iVar2 = iStack_d0;
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_shal_c,0xca);
      pRVar7 = (RGE_Random_Map_Module *)((int)pRStack_dc + (-1 - (iVar4 * 2) / 0x7fff));
      if ((int)pRVar7 < 0) {
        pRVar7 = (RGE_Random_Map_Module *)0x0;
      }
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_shal_c,0xce);
      iStack_c0 = (iVar4 * 2) / 0x7fff + 1 + iStack_e0;
      if (param_1->map_width <= iStack_c0) {
        iStack_c0 = param_1->map_width + -1;
      }
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_shal_c,0xd2);
      lStack_d8 = (int)&pRStack_dc->_padding_ + (iVar4 * 3) / 0x7fff + 1;
      if (param_1->map_height <= lStack_d8) {
        lStack_d8 = param_1->map_height + -1;
      }
      pRStack_c8 = pRVar7;
      if ((int)pRVar7 <= lStack_d8) {
        iVar4 = (int)pRVar7 * 4;
        do {
          if (iStack_d0 <= iStack_c0) {
            iVar8 = iStack_d0 * 0x18;
            pRStack_c8 = pRVar7;
            do {
              if (((*(byte *)(*(int *)((int)param_1->map_row_offset + iVar4) + 5 + iVar8) & 0x1f) ==
                   1) || ((*(byte *)(*(int *)((int)param_1->map_row_offset + iVar4) + 5 + iVar8) &
                          0x1f) == 0x16)) {
                RGE_Random_Map_Module::push_stack(param_1,&MStack_b8,iVar2,(long)pRVar7,0.0,0.0);
                pRVar7 = pRStack_c8;
              }
              iVar2 = iVar2 + 1;
              iVar8 = iVar8 + 0x18;
            } while (iVar2 <= iStack_c0);
          }
          pRVar7 = (RGE_Random_Map_Module *)((int)&pRVar7->_padding_ + 1);
          iVar4 = iVar4 + 4;
          iVar2 = iStack_d0;
          pRStack_c8 = pRVar7;
        } while ((int)pRVar7 <= lStack_d8);
      }
    }
    else {
      if ((0 < iStack_e0) &&
         ((bVar5 = param_1->map_row_offset[(int)pRStack_dc][iStack_e0 + -1].field_0x5 & 0x1f,
          bVar5 == 1 || (bVar5 == 0x16)))) {
        RGE_Random_Map_Module::push_stack
                  (param_1,&MStack_b8,iStack_e0 + -1,(long)pRStack_dc,0.0,0.0);
      }
      if ((iStack_e0 < param_1->map_width + -1) &&
         ((bVar5 = param_1->map_row_offset[(int)pRStack_dc][iStack_e0 + 1].field_0x5 & 0x1f,
          bVar5 == 1 || (bVar5 == 0x16)))) {
        RGE_Random_Map_Module::push_stack(param_1,&MStack_b8,iStack_e0 + 1,(long)pRStack_dc,0.0,0.0)
        ;
      }
      if ((0 < (int)pRStack_dc) &&
         ((bVar5 = param_1->map_row_offset[(int)((int)&pRStack_dc[-1].stack_offsets + 3)][iStack_e0]
                   .field_0x5 & 0x1f, bVar5 == 1 || (bVar5 == 0x16)))) {
        RGE_Random_Map_Module::push_stack
                  (param_1,&MStack_b8,iStack_e0,(long)((int)&pRStack_dc[-1].stack_offsets + 3),0.0,
                   0.0);
      }
      if ((int)pRStack_dc < param_1->map_height + -1) {
        puVar1 = (undefined1 *)((int)&pRStack_dc->_padding_ + 1);
        bVar5 = param_1->map_row_offset[(int)puVar1][iStack_e0].field_0x5 & 0x1f;
        if ((bVar5 == 1) || (bVar5 == 0x16)) {
          RGE_Random_Map_Module::push_stack(param_1,&MStack_b8,iStack_e0,(long)puVar1,0.0,0.0);
        }
      }
    }
    param_1->search_map_rows[(int)pRStack_cc][iStack_d4] = 0xff;
    iStack_d4 = iStack_e0;
    pRStack_cc = pRStack_dc;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004876ea
// Address: 004876ea
RGE_RMM_Database_Controller * __thiscall
FUN_004876ea(RGE_RMM_Database_Controller *param_1,int param_2)
{
  RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(param_1,param_2);
  param_1->_padding_ = (int)&TRIBE_RMM_Database_Controller::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00487709
// Address: 00487709
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
undefined4 __thiscall
FUN_00487709(RGE_RMM_Database_Controller *param_1,RGE_Map *param_2,RGE_Game_World *param_3,
            uchar param_4,long param_5)
{
  int iVar1;
  long *plVar2;
  RGE_RMM_Cliffs_Generator *pRVar3;
  long *plVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *unaff_FS_OFFSET;
  int aiStack_99c [298];
  undefined4 uStack_4f4;
  int iStack_4d0;
  int aiStack_4cc [4];
  undefined4 uStack_4bc;
  undefined4 uStack_4b8;
  long alStack_4b0 [296];
  int iStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e6be;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game);
  uStack_4f4 = 0x487776;
  RGE_RMM_Database_Controller::init(param_1,param_2,param_3,param_4,param_5,'\x01' - (iVar1 != 0));
  iVar1 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x40);
  if (0x1fff < iVar1) {
    iVar1 = param_1->_padding_;
    if (iVar1 < 0x49) {
      iStack_4d0 = 3;
      aiStack_4cc[2] = 10;
    }
    else if (iVar1 < 0x61) {
      iStack_4d0 = 4;
      aiStack_4cc[2] = 0xc;
    }
    else if (iVar1 < 0x79) {
      iStack_4d0 = 6;
      aiStack_4cc[2] = 0xe;
    }
    else if (iVar1 < 0x91) {
      iStack_4d0 = 8;
      aiStack_4cc[2] = 0x10;
    }
    else if (iVar1 < 0xc9) {
      iStack_4d0 = 0x12;
      aiStack_4cc[2] = 0x14;
    }
    else {
      aiStack_4cc[2] = iStack_4d0;
      if (iVar1 < 0xfb) {
        iStack_4d0 = 0x1c;
        aiStack_4cc[2] = 0x14;
      }
    }
    switch(param_1->map_type) {
    case 0:
      iStack_4d0 = 0;
      aiStack_4cc[2] = 0;
      break;
    case 1:
      iStack_4d0 = iStack_4d0 + -5;
      aiStack_4cc[2] = aiStack_4cc[2] + -6;
      break;
    case 2:
      iStack_4d0 = iStack_4d0 + -3;
      aiStack_4cc[2] = aiStack_4cc[2] + -2;
      break;
    case 5:
    case 6:
    case 8:
      aiStack_4cc[2] = aiStack_4cc[2] + -4;
    }
    if (aiStack_4cc[2] < 3) {
      aiStack_4cc[2] = 3;
    }
    aiStack_4cc[1] = 2;
    uStack_4bc = 2;
    uStack_4b8 = 2;
    if (aiStack_4cc[2] + -3 < 1) {
      aiStack_4cc[3] = 0;
    }
    else {
      aiStack_4cc[3] = (aiStack_4cc[2] + -3) / 2;
    }
    iVar1 = (param_1->terrain_info).hot_spot_num;
    aiStack_4cc[2] = aiStack_4cc[2] - aiStack_4cc[3];
    iStack_10 = iVar1;
    if (0 < iVar1) {
      plVar4 = alStack_4b0;
      plVar2 = &(param_1->terrain_info).hot_spots[0].y;
      do {
        plVar4[-1] = ((RGE_Terrain_Hot_Spots *)(plVar2 + -1))->x;
        *plVar4 = *plVar2;
        plVar4[1] = plVar2[1];
        plVar4 = plVar4 + 3;
        iVar1 = iVar1 + -1;
        plVar2 = plVar2 + 4;
      } while (iVar1 != 0);
    }
    if ((0 < aiStack_4cc[2]) && (0 < iStack_4d0)) {
      aiStack_4cc[0] = iStack_4d0;
      pRVar3 = (RGE_RMM_Cliffs_Generator *)operator_new(0x508);
      uStack_4 = 0;
      if (pRVar3 != (RGE_RMM_Cliffs_Generator *)0x0) {
        iVar1 = param_1->_padding_;
        piVar6 = aiStack_4cc;
        piVar7 = aiStack_99c;
        for (iVar5 = 0x130; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar7 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar7 = piVar7 + 1;
        }
        RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Generator(pRVar3,iVar1,param_1);
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0048790a
// Address: 0048790a
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_land_initilization__r: "Random Map land initilization, rand: %d"
/* WARNING: Instruction at (ram,0x00487977) overlaps instruction at (ram,0x00487975)
    */

void __fastcall FUN_0048790a(RGE_RMM_Database_Controller *param_1,undefined4 param_2)
{
  byte *pbVar1;
  byte bVar2;
  RGE_Map_Data_Entry *pRVar3;
  byte *in_EAX;
  int iVar4;
  int iVar5;
  int iVar6;
  long *plVar7;
  RGE_RMM_Database_Controller *pRVar8;
  uchar *puVar9;
  TDebuggingLog *this;
  byte bVar10;
  byte *unaff_EBX;
  RGE_Land_Info *pRVar11;
  RGE_RMM_Database_Controller *unaff_ESI;
  int unaff_EDI;
  long lVar12;
  byte in_CF;
  uchar in_stack_00000014;
  
  lVar12 = (unaff_EDI - *(int *)(in_EAX + 0x48)) - (uint)in_CF;
  *(char *)&param_1->_padding_ = (char)param_1->_padding_ + (char)((uint)in_EAX >> 8);
  if ((char)param_1->_padding_ < '\0') {
    return;
  }
  *(char *)&param_1->_padding_ = (char)param_1->_padding_ + (char)((uint)param_1 >> 8);
  pRVar8 = param_1;
  if ((char)param_1->_padding_ < '\0') {
code_r0x0048795f:
    if (in_EAX == (byte *)0x8) {
LAB_00487964:
      in_EAX = (byte *)unaff_ESI->_padding_;
code_r0x00487967:
      param_1 = pRVar8;
      if ((int)in_EAX < 100) goto code_r0x0048796c;
    }
  }
  else {
    bVar2 = *unaff_EBX;
    bVar10 = (byte)((uint)param_2 >> 8);
    *unaff_EBX = *unaff_EBX + bVar10;
    if ((char)*unaff_EBX < '\0') {
      pbVar1 = unaff_EBX + -0x77cebba;
      iVar4 = *(int *)pbVar1;
      iVar5 = *(int *)pbVar1;
      *(uint *)pbVar1 = (iVar5 - (int)param_1) - (uint)CARRY1(bVar2,bVar10);
      if ((SBORROW4(iVar4,(int)param_1) != SBORROW4(iVar5 - (int)param_1,(uint)CARRY1(bVar2,bVar10))
          ) == *(int *)pbVar1 < 0) goto LAB_0048797d;
    }
    else {
      *unaff_EBX = *unaff_EBX + bVar10;
      if ((char)*unaff_EBX < '\0') goto code_r0x00487967;
      bVar2 = *in_EAX;
      *in_EAX = *in_EAX + bVar10;
      if ((char)*in_EAX < '\0') {
        *(uint *)unaff_EBX =
             (int)(unaff_ESI->land_info).land +
             (uint)CARRY1(bVar2,bVar10) + *(int *)unaff_EBX + -0x3c;
        pbVar1 = unaff_EBX + -0x62f0af08;
        bVar2 = (byte)param_1 & 7;
        *pbVar1 = *pbVar1 << bVar2 | *pbVar1 >> 8 - bVar2;
        return;
      }
      *in_EAX = *in_EAX + bVar10;
      if (-1 < (char)*in_EAX) {
        *unaff_EBX = *unaff_EBX + bVar10;
        if ((char)*unaff_EBX < '\0') {
          return;
        }
        *in_EAX = *in_EAX + bVar10;
        if (-1 < (char)*in_EAX) {
          in_EAX = (byte *)param_1->map_type;
          pRVar3 = (param_1->map_info).maps;
          lVar12 = pRVar3[(int)in_EAX].land_info.land_placement_edge;
          pRVar8 = (RGE_RMM_Database_Controller *)&pRVar3[(int)in_EAX].land_info.land_placement_edge
          ;
          unaff_ESI = param_1;
          if (in_EAX != (byte *)0x5) goto code_r0x0048795f;
          goto LAB_00487964;
        }
      }
    }
code_r0x0048796c:
    param_1->_padding_ = ((0x4f < (int)in_EAX) - 1 & 0xfffffffb) + 0x19;
  }
LAB_0048797d:
  RGE_RMM_Database_Controller::add_land_module(unaff_ESI,in_stack_00000014);
  (unaff_ESI->map_info).maps[unaff_ESI->map_type].land_info.land_placement_edge = lVar12;
  if (unaff_ESI->map_type < 5) {
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xb9);
    if (iVar4 < 0x3fff) {
      iVar4 = 0;
      (unaff_ESI->land_info).wall_1_avoidance_line = -1;
      if (0 < (unaff_ESI->land_info).land_num) {
        plVar7 = &(unaff_ESI->land_info).land[0].wall_1_avoidance_line;
        do {
          *plVar7 = -1;
          iVar4 = iVar4 + 1;
          plVar7 = plVar7 + 0xd;
        } while (iVar4 < (unaff_ESI->land_info).land_num);
      }
    }
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xc0);
    if (iVar4 < 0x3fff) {
      iVar4 = 0;
      (unaff_ESI->land_info).wall_2_avoidance_line = -1;
      if (0 < (unaff_ESI->land_info).land_num) {
        plVar7 = &(unaff_ESI->land_info).land[0].wall_2_avoidance_line;
        do {
          *plVar7 = -1;
          iVar4 = iVar4 + 1;
          plVar7 = plVar7 + 0xd;
        } while (iVar4 < (unaff_ESI->land_info).land_num);
      }
    }
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,199);
    if (iVar4 < 0x3fff) {
      (unaff_ESI->land_info).wall_3_avoidance_line = unaff_ESI->_padding_;
      iVar4 = 0;
      if (0 < (unaff_ESI->land_info).land_num) {
        plVar7 = &(unaff_ESI->land_info).land[0].wall_3_avoidance_line;
        do {
          iVar4 = iVar4 + 1;
          *plVar7 = unaff_ESI->_padding_;
          plVar7 = plVar7 + 0xd;
        } while (iVar4 < (unaff_ESI->land_info).land_num);
      }
    }
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xce);
    if (iVar4 < 0x3fff) {
      (unaff_ESI->land_info).wall_4_avoidance_line = unaff_ESI->_padding_;
      iVar4 = 0;
      if (0 < (unaff_ESI->land_info).land_num) {
        plVar7 = &(unaff_ESI->land_info).land[0].wall_4_avoidance_line;
        do {
          iVar4 = iVar4 + 1;
          *plVar7 = unaff_ESI->_padding_;
          plVar7 = plVar7 + 0xd;
        } while (iVar4 < (unaff_ESI->land_info).land_num);
      }
    }
  }
  if (unaff_ESI->map_type == 8) {
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xd8);
    if (iVar4 < 0x3fff) {
      iVar4 = 0;
      (unaff_ESI->land_info).wall_3_avoidance_line = unaff_ESI->_padding_;
      (unaff_ESI->land_info).wall_1_avoidance_line = -1;
      if (0 < (unaff_ESI->land_info).land_num) {
        plVar7 = &(unaff_ESI->land_info).land[0].wall_3_avoidance_line;
        do {
          plVar7[-2] = -1;
          *plVar7 = unaff_ESI->_padding_;
          iVar4 = iVar4 + 1;
          plVar7 = plVar7 + 0xd;
        } while (iVar4 < (unaff_ESI->land_info).land_num);
      }
    }
    else {
      iVar4 = 0;
      (unaff_ESI->land_info).wall_4_avoidance_line = unaff_ESI->_padding_;
      (unaff_ESI->land_info).wall_2_avoidance_line = -1;
      if (0 < (unaff_ESI->land_info).land_num) {
        plVar7 = &(unaff_ESI->land_info).land[0].wall_4_avoidance_line;
        do {
          plVar7[-2] = -1;
          *plVar7 = unaff_ESI->_padding_;
          iVar4 = iVar4 + 1;
          plVar7 = plVar7 + 0xd;
        } while (iVar4 < (unaff_ESI->land_info).land_num);
      }
    }
  }
  iVar4 = unaff_ESI->map_type;
  if (((1 < iVar4) && (iVar4 < 7)) || (iVar4 == 8)) {
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xf1);
    if (iVar4 < 0x3fff) {
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xf7);
      if (iVar4 < 0x3fff) {
        iVar4 = 0;
        if (0 < (unaff_ESI->land_info).land_num) {
          puVar9 = &(unaff_ESI->land_info).land[0].zone;
          do {
            *puVar9 = '\0';
            iVar4 = iVar4 + 2;
            puVar9 = puVar9 + 0x68;
          } while (iVar4 < (unaff_ESI->land_info).land_num);
        }
      }
      else {
        iVar4 = 0;
        if (0 < (unaff_ESI->land_info).land_num) {
          puVar9 = &(unaff_ESI->land_info).land[0].zone;
          do {
            *puVar9 = (uchar)iVar4;
            iVar4 = iVar4 + 2;
            puVar9 = puVar9 + 0x68;
          } while (iVar4 < (unaff_ESI->land_info).land_num);
        }
      }
      iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xff);
      iVar4 = (unaff_ESI->land_info).land_num;
      iVar6 = 1;
      if (iVar5 < 0x3fff) {
        if (1 < iVar4) {
          puVar9 = &(unaff_ESI->land_info).land[1].zone;
          do {
            *puVar9 = '\x01';
            iVar6 = iVar6 + 2;
            puVar9 = puVar9 + 0x68;
          } while (iVar6 < (unaff_ESI->land_info).land_num);
          TRIBE_RMM_Database_Controller::add_shallows_module
                    ((TRIBE_RMM_Database_Controller *)unaff_ESI);
          goto LAB_00487c90;
        }
      }
      else if (1 < iVar4) {
        puVar9 = &(unaff_ESI->land_info).land[1].zone;
        do {
          *puVar9 = (uchar)iVar6;
          iVar6 = iVar6 + 2;
          puVar9 = puVar9 + 0x68;
        } while (iVar6 < (unaff_ESI->land_info).land_num);
      }
      TRIBE_RMM_Database_Controller::add_shallows_module((TRIBE_RMM_Database_Controller *)unaff_ESI)
      ;
    }
    else if (unaff_ESI->map_type == 4) {
      iVar4 = 0;
      if (0 < (unaff_ESI->land_info).land_num) {
        puVar9 = &(unaff_ESI->land_info).land[0].zone;
        do {
          *puVar9 = '\0';
          iVar4 = iVar4 + 1;
          puVar9 = puVar9 + 0x34;
        } while (iVar4 < (unaff_ESI->land_info).land_num);
      }
      (unaff_ESI->land_info).base_terrain = '\0';
    }
    else if ((4 < unaff_ESI->map_type) && (iVar4 = 0, 0 < (unaff_ESI->land_info).land_num)) {
      puVar9 = &(unaff_ESI->land_info).land[0].zone;
      do {
        *puVar9 = '\0';
        iVar4 = iVar4 + 1;
        puVar9 = puVar9 + 0x34;
      } while (iVar4 < (unaff_ESI->land_info).land_num);
    }
  }
LAB_00487c90:
  if ((unaff_ESI->map_type == 5) || (unaff_ESI->map_type == 8)) {
    iVar4 = unaff_ESI->_padding_;
    if (iVar4 < 100) {
      iVar5 = ((0x4f < iVar4) - 1 & 0xfffffffb) + 0xf;
      if (0 < (unaff_ESI->land_info).wall_1_avoidance_line) {
        (unaff_ESI->land_info).wall_1_avoidance_line = iVar5;
      }
      if (0 < (unaff_ESI->land_info).wall_2_avoidance_line) {
        (unaff_ESI->land_info).wall_2_avoidance_line = iVar5;
      }
      if ((unaff_ESI->land_info).wall_3_avoidance_line < iVar4) {
        (unaff_ESI->land_info).wall_3_avoidance_line = iVar4 - iVar5;
      }
      if ((unaff_ESI->land_info).wall_4_avoidance_line < unaff_ESI->_padding_) {
        (unaff_ESI->land_info).wall_4_avoidance_line = unaff_ESI->_padding_ - iVar5;
      }
      iVar4 = 0;
      if (0 < (unaff_ESI->land_info).land_num) {
        plVar7 = &(unaff_ESI->land_info).land[0].wall_2_avoidance_line;
        do {
          if (0 < plVar7[-1]) {
            plVar7[-1] = iVar5;
          }
          if (0 < *plVar7) {
            *plVar7 = iVar5;
          }
          if (plVar7[1] < unaff_ESI->_padding_) {
            plVar7[1] = unaff_ESI->_padding_ - iVar5;
          }
          if (plVar7[2] < unaff_ESI->_padding_) {
            plVar7[2] = unaff_ESI->_padding_ - iVar5;
          }
          iVar4 = iVar4 + 1;
          plVar7 = plVar7 + 0xd;
        } while (iVar4 < (unaff_ESI->land_info).land_num);
      }
    }
    iVar5 = __ftol();
    iVar4 = (unaff_ESI->land_info).land_num;
    iVar6 = 0;
    if (0 < iVar4) {
      pRVar11 = &unaff_ESI->land_info;
      do {
        iVar6 = iVar6 + 1;
        pRVar11->land[0].land_size = iVar5 / iVar4;
        iVar4 = (unaff_ESI->land_info).land_num;
        pRVar11 = (RGE_Land_Info *)(pRVar11->land + 1);
      } while (iVar6 < iVar4);
    }
  }
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x137);
  TDebuggingLog::Log(this,(char *)L,s_Random_Map_land_initilization__r,iVar4);
  return;
}

// --------------------------------------------------

// Function: FUN_00487938
// Address: 00487938
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_land_initilization__r: "Random Map land initilization, rand: %d"
void __thiscall FUN_00487938(RGE_RMM_Database_Controller *param_1,uchar param_2)
{
  RGE_Map_Data_Entry *pRVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  uchar *puVar7;
  TDebuggingLog *this;
  RGE_Land_Info *pRVar8;
  
  iVar3 = param_1->map_type;
  pRVar1 = (param_1->map_info).maps;
  lVar2 = pRVar1[iVar3].land_info.land_placement_edge;
  if (((iVar3 == 5) || (iVar3 == 8)) && (param_1->_padding_ < 100)) {
    pRVar1[iVar3].land_info.land_placement_edge =
         ((0x4f < param_1->_padding_) - 1 & 0xfffffffb) + 0x19;
  }
  RGE_RMM_Database_Controller::add_land_module(param_1,param_2);
  (param_1->map_info).maps[param_1->map_type].land_info.land_placement_edge = lVar2;
  if (param_1->map_type < 5) {
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xb9);
    if (iVar3 < 0x3fff) {
      iVar3 = 0;
      (param_1->land_info).wall_1_avoidance_line = -1;
      if (0 < (param_1->land_info).land_num) {
        plVar6 = &(param_1->land_info).land[0].wall_1_avoidance_line;
        do {
          *plVar6 = -1;
          iVar3 = iVar3 + 1;
          plVar6 = plVar6 + 0xd;
        } while (iVar3 < (param_1->land_info).land_num);
      }
    }
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xc0);
    if (iVar3 < 0x3fff) {
      iVar3 = 0;
      (param_1->land_info).wall_2_avoidance_line = -1;
      if (0 < (param_1->land_info).land_num) {
        plVar6 = &(param_1->land_info).land[0].wall_2_avoidance_line;
        do {
          *plVar6 = -1;
          iVar3 = iVar3 + 1;
          plVar6 = plVar6 + 0xd;
        } while (iVar3 < (param_1->land_info).land_num);
      }
    }
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,199);
    if (iVar3 < 0x3fff) {
      (param_1->land_info).wall_3_avoidance_line = param_1->_padding_;
      iVar3 = 0;
      if (0 < (param_1->land_info).land_num) {
        plVar6 = &(param_1->land_info).land[0].wall_3_avoidance_line;
        do {
          iVar3 = iVar3 + 1;
          *plVar6 = param_1->_padding_;
          plVar6 = plVar6 + 0xd;
        } while (iVar3 < (param_1->land_info).land_num);
      }
    }
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xce);
    if (iVar3 < 0x3fff) {
      (param_1->land_info).wall_4_avoidance_line = param_1->_padding_;
      iVar3 = 0;
      if (0 < (param_1->land_info).land_num) {
        plVar6 = &(param_1->land_info).land[0].wall_4_avoidance_line;
        do {
          iVar3 = iVar3 + 1;
          *plVar6 = param_1->_padding_;
          plVar6 = plVar6 + 0xd;
        } while (iVar3 < (param_1->land_info).land_num);
      }
    }
  }
  if (param_1->map_type == 8) {
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xd8);
    if (iVar3 < 0x3fff) {
      iVar3 = 0;
      (param_1->land_info).wall_3_avoidance_line = param_1->_padding_;
      (param_1->land_info).wall_1_avoidance_line = -1;
      if (0 < (param_1->land_info).land_num) {
        plVar6 = &(param_1->land_info).land[0].wall_3_avoidance_line;
        do {
          plVar6[-2] = -1;
          *plVar6 = param_1->_padding_;
          iVar3 = iVar3 + 1;
          plVar6 = plVar6 + 0xd;
        } while (iVar3 < (param_1->land_info).land_num);
      }
    }
    else {
      iVar3 = 0;
      (param_1->land_info).wall_4_avoidance_line = param_1->_padding_;
      (param_1->land_info).wall_2_avoidance_line = -1;
      if (0 < (param_1->land_info).land_num) {
        plVar6 = &(param_1->land_info).land[0].wall_4_avoidance_line;
        do {
          plVar6[-2] = -1;
          *plVar6 = param_1->_padding_;
          iVar3 = iVar3 + 1;
          plVar6 = plVar6 + 0xd;
        } while (iVar3 < (param_1->land_info).land_num);
      }
    }
  }
  iVar3 = param_1->map_type;
  if (((1 < iVar3) && (iVar3 < 7)) || (iVar3 == 8)) {
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xf1);
    if (iVar3 < 0x3fff) {
      iVar3 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xf7);
      if (iVar3 < 0x3fff) {
        iVar3 = 0;
        if (0 < (param_1->land_info).land_num) {
          puVar7 = &(param_1->land_info).land[0].zone;
          do {
            *puVar7 = '\0';
            iVar3 = iVar3 + 2;
            puVar7 = puVar7 + 0x68;
          } while (iVar3 < (param_1->land_info).land_num);
        }
      }
      else {
        iVar3 = 0;
        if (0 < (param_1->land_info).land_num) {
          puVar7 = &(param_1->land_info).land[0].zone;
          do {
            *puVar7 = (uchar)iVar3;
            iVar3 = iVar3 + 2;
            puVar7 = puVar7 + 0x68;
          } while (iVar3 < (param_1->land_info).land_num);
        }
      }
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xff);
      iVar3 = (param_1->land_info).land_num;
      iVar5 = 1;
      if (iVar4 < 0x3fff) {
        if (1 < iVar3) {
          puVar7 = &(param_1->land_info).land[1].zone;
          do {
            *puVar7 = '\x01';
            iVar5 = iVar5 + 2;
            puVar7 = puVar7 + 0x68;
          } while (iVar5 < (param_1->land_info).land_num);
          TRIBE_RMM_Database_Controller::add_shallows_module
                    ((TRIBE_RMM_Database_Controller *)param_1);
          goto LAB_00487c90;
        }
      }
      else if (1 < iVar3) {
        puVar7 = &(param_1->land_info).land[1].zone;
        do {
          *puVar7 = (uchar)iVar5;
          iVar5 = iVar5 + 2;
          puVar7 = puVar7 + 0x68;
        } while (iVar5 < (param_1->land_info).land_num);
      }
      TRIBE_RMM_Database_Controller::add_shallows_module((TRIBE_RMM_Database_Controller *)param_1);
    }
    else if (param_1->map_type == 4) {
      iVar3 = 0;
      if (0 < (param_1->land_info).land_num) {
        puVar7 = &(param_1->land_info).land[0].zone;
        do {
          *puVar7 = '\0';
          iVar3 = iVar3 + 1;
          puVar7 = puVar7 + 0x34;
        } while (iVar3 < (param_1->land_info).land_num);
      }
      (param_1->land_info).base_terrain = '\0';
    }
    else if ((4 < param_1->map_type) && (iVar3 = 0, 0 < (param_1->land_info).land_num)) {
      puVar7 = &(param_1->land_info).land[0].zone;
      do {
        *puVar7 = '\0';
        iVar3 = iVar3 + 1;
        puVar7 = puVar7 + 0x34;
      } while (iVar3 < (param_1->land_info).land_num);
    }
  }
LAB_00487c90:
  if ((param_1->map_type == 5) || (param_1->map_type == 8)) {
    iVar3 = param_1->_padding_;
    if (iVar3 < 100) {
      iVar4 = ((0x4f < iVar3) - 1 & 0xfffffffb) + 0xf;
      if (0 < (param_1->land_info).wall_1_avoidance_line) {
        (param_1->land_info).wall_1_avoidance_line = iVar4;
      }
      if (0 < (param_1->land_info).wall_2_avoidance_line) {
        (param_1->land_info).wall_2_avoidance_line = iVar4;
      }
      if ((param_1->land_info).wall_3_avoidance_line < iVar3) {
        (param_1->land_info).wall_3_avoidance_line = iVar3 - iVar4;
      }
      if ((param_1->land_info).wall_4_avoidance_line < param_1->_padding_) {
        (param_1->land_info).wall_4_avoidance_line = param_1->_padding_ - iVar4;
      }
      iVar3 = 0;
      if (0 < (param_1->land_info).land_num) {
        plVar6 = &(param_1->land_info).land[0].wall_2_avoidance_line;
        do {
          if (0 < plVar6[-1]) {
            plVar6[-1] = iVar4;
          }
          if (0 < *plVar6) {
            *plVar6 = iVar4;
          }
          if (plVar6[1] < param_1->_padding_) {
            plVar6[1] = param_1->_padding_ - iVar4;
          }
          if (plVar6[2] < param_1->_padding_) {
            plVar6[2] = param_1->_padding_ - iVar4;
          }
          iVar3 = iVar3 + 1;
          plVar6 = plVar6 + 0xd;
        } while (iVar3 < (param_1->land_info).land_num);
      }
    }
    iVar4 = __ftol();
    iVar3 = (param_1->land_info).land_num;
    iVar5 = 0;
    if (0 < iVar3) {
      pRVar8 = &param_1->land_info;
      do {
        iVar5 = iVar5 + 1;
        pRVar8->land[0].land_size = iVar4 / iVar3;
        iVar3 = (param_1->land_info).land_num;
        pRVar8 = (RGE_Land_Info *)(pRVar8->land + 1);
      } while (iVar5 < iVar3);
    }
  }
  iVar3 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x137);
  TDebuggingLog::Log(this,(char *)L,s_Random_Map_land_initilization__r,iVar3);
  return;
}

// --------------------------------------------------

// Function: FUN_00487dc9
// Address: 00487dc9
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_terrain_initilization: "Random Map terrain initilization, rand: %d"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00487dc9(RGE_RMM_Database_Controller *param_1)
{
  int iVar1;
  int iVar2;
  float fVar3;
  long lVar4;
  int iVar5;
  long *plVar6;
  TDebuggingLog *this;
  int iVar7;
  
  iVar5 = (param_1->map_info).maps[param_1->map_type].land_info.grown_land_percent;
  iVar1 = param_1->_padding_;
  iVar2 = param_1->_padding_;
  RGE_RMM_Database_Controller::add_terrain_module(param_1);
  iVar7 = 0;
  fVar3 = (float)((iVar5 * iVar1 * iVar2) / 100) * _DAT_00571f28;
  if (0 < (param_1->terrain_info).terrain_num) {
    plVar6 = &(param_1->terrain_info).terrain[0].clumps;
    do {
      if ((plVar6[-1] != 6) && ((float)_DAT_00571f30 < fVar3)) {
        lVar4 = __ftol();
        *plVar6 = lVar4;
      }
      iVar7 = iVar7 + 1;
      plVar6 = plVar6 + 8;
    } while (iVar7 < (param_1->terrain_info).terrain_num);
  }
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x154);
  if (iVar5 < 0x1fff) {
    iVar5 = 0;
    if (0 < (param_1->terrain_info).terrain_num) {
      plVar6 = &(param_1->terrain_info).terrain[0].clumps;
      do {
        iVar1 = plVar6[-1];
        if (iVar1 == 0xd) {
          ((RGE_Terrain_Info_Line *)(plVar6 + -3))->terrain_size =
               ((RGE_Terrain_Info_Line *)(plVar6 + -3))->terrain_size * 3;
          *plVar6 = *plVar6 * 3;
          plVar6[4] = 2;
        }
        else if (iVar1 == 0x14) {
          ((RGE_Terrain_Info_Line *)(plVar6 + -3))->terrain_size =
               ((RGE_Terrain_Info_Line *)(plVar6 + -3))->terrain_size / 2;
          *plVar6 = *plVar6 / 2;
        }
        else if (iVar1 == 0x13) {
          ((RGE_Terrain_Info_Line *)(plVar6 + -3))->terrain_size =
               ((RGE_Terrain_Info_Line *)(plVar6 + -3))->terrain_size / 2;
          *plVar6 = *plVar6 / 2;
        }
        else if (iVar1 == 10) {
          ((RGE_Terrain_Info_Line *)(plVar6 + -3))->terrain_size =
               ((RGE_Terrain_Info_Line *)(plVar6 + -3))->terrain_size / 2;
          *plVar6 = *plVar6 / 2;
          plVar6[4] = 2;
        }
        else if (iVar1 == 6) {
          ((RGE_Terrain_Info_Line *)(plVar6 + -3))->terrain_size =
               ((RGE_Terrain_Info_Line *)(plVar6 + -3))->terrain_size << 1;
          plVar6[4] = 0;
        }
        iVar5 = iVar5 + 1;
        plVar6 = plVar6 + 8;
      } while (iVar5 < (param_1->terrain_info).terrain_num);
    }
  }
  else {
    iVar5 = 0;
    if (0 < (param_1->terrain_info).terrain_num) {
      plVar6 = &(param_1->terrain_info).terrain[0].avoid_hot_spots;
      do {
        iVar1 = plVar6[-5];
        if (iVar1 == 6) {
          *plVar6 = 0;
        }
        else if ((iVar1 == 10) || (iVar1 == 0xd)) {
          *plVar6 = 2;
        }
        iVar5 = iVar5 + 1;
        plVar6 = plVar6 + 8;
      } while (iVar5 < (param_1->terrain_info).terrain_num);
    }
  }
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x180);
  TDebuggingLog::Log(this,(char *)L,s_Random_Map_terrain_initilization,iVar5);
  return;
}

// --------------------------------------------------

// Function: FUN_00487f9d
// Address: 00487f9d
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_object_initilization_: "Random Map object initilization, rand: %d"
void __fastcall FUN_00487f9d(RGE_RMM_Database_Controller *param_1)
{
  bool bVar1;
  Age AVar2;
  long *plVar3;
  RGE_Land_Info_Line *pRVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  RGE_Land_Info *pRVar10;
  int iVar11;
  RGE_Land_Info_Line *pRVar12;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  RGE_RMM_Database_Controller::add_object_module(param_1);
  debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x198);
  AVar2 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  if (AVar2 == NomadAge) {
    iVar8 = 0;
    if (0 < (param_1->object_info).object_num) {
      plVar3 = &(param_1->object_info).objects[0].number_of_groups;
      do {
        if (((RGE_Object_Info_Line *)(plVar3 + -5))->obj_id == 0x53) {
          *plVar3 = 1;
        }
        iVar8 = iVar8 + 1;
        plVar3 = plVar3 + 0xc;
      } while (iVar8 < (param_1->object_info).object_num);
    }
    iVar8 = 0;
    if (0 < (param_1->object_info).object_num) {
      plVar3 = &(param_1->object_info).objects[0].number_of_groups;
      do {
        if (((RGE_Object_Info_Line *)(plVar3 + -5))->obj_id == 0x6d) {
          *plVar3 = 0;
        }
        iVar8 = iVar8 + 1;
        plVar3 = plVar3 + 0xc;
      } while (iVar8 < (param_1->object_info).object_num);
    }
  }
  if (param_1->map_type == 6) {
    iVar8 = (param_1->land_info).land_num;
    if (0 < iVar8) {
      pRVar4 = (param_1->land_info).land + iVar8;
      do {
        iVar8 = iVar8 + -1;
        iVar9 = 0xd;
        plVar3 = &pRVar4[-1].land_size;
        pRVar12 = pRVar4;
        for (; iVar9 != 0; iVar9 = iVar9 + -1) {
          pRVar12->land_size = *plVar3;
          plVar3 = plVar3 + 1;
          pRVar12 = (RGE_Land_Info_Line *)&pRVar12->terrain_type;
        }
        pRVar4 = pRVar4 + -1;
      } while (iVar8 != 0);
    }
    iVar8 = param_1->_padding_;
    iVar11 = iVar8 / 6;
    iVar9 = param_1->_padding_;
    (param_1->land_info).land[0].zone = (uchar)(param_1->land_info).land_num;
    (param_1->land_info).land[0].terrain_type = 1;
    (param_1->land_info).land[0].area = 7;
    (param_1->land_info).land[0].base_size = 2;
    lVar5 = __ftol();
    iVar6 = param_1->_padding_;
    (param_1->land_info).land[0].land_size = lVar5;
    (param_1->land_info).land[0].clumpiness_factor = 10;
    (param_1->land_info).land[0].x = *(int *)(iVar6 + 8) / 2;
    iVar6 = *(int *)(iVar6 + 0xc);
    (param_1->land_info).land[0].wall_1_avoidance_line = iVar11;
    (param_1->land_info).land[0].y = iVar6 / 2;
    iVar6 = (param_1->land_info).land_num;
    (param_1->land_info).land[0].wall_2_avoidance_line = iVar11;
    (param_1->land_info).land[0].wall_3_avoidance_line = iVar8 - iVar11;
    (param_1->land_info).land[0].wall_4_avoidance_line = iVar9 - iVar11;
    (param_1->land_info).land[0].wall_fade = '\n';
    (param_1->land_info).land_num = iVar6 + 1;
  }
  if (param_1->map_type < 2) {
    iVar8 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x1c3);
    iStack_10 = (iVar8 * 4) / 0x7fff + 1;
    if (10 < iStack_10 + param_1->number_of_players) {
      iStack_10 = 10 - param_1->number_of_players;
    }
    iVar8 = param_1->_padding_;
    iVar9 = param_1->_padding_;
    iVar6 = (param_1->land_info).land_num;
    iVar11 = 0;
    if (0 < iVar6) {
      pRVar10 = &param_1->land_info;
      do {
        iVar11 = iVar11 + 1;
        pRVar10->land[0].land_size =
             pRVar10->land[0].land_size - ((iVar8 + iVar9) * iStack_10) / iVar6;
        pRVar10 = (RGE_Land_Info *)(pRVar10->land + 1);
      } while (iVar11 < (param_1->land_info).land_num);
    }
    iVar8 = 0;
    if (0 < iStack_10) {
      do {
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].terrain_type = 0;
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].area = 7;
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].base_size = 3;
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].zone =
             (char)iVar8 + (char)(param_1->land_info).land_num;
        lVar5 = __ftol();
        iStack_c = 0;
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].land_size = lVar5;
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].clumpiness_factor = 10;
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].wall_1_avoidance_line =
             (param_1->land_info).wall_1_avoidance_line;
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].wall_2_avoidance_line =
             (param_1->land_info).wall_2_avoidance_line;
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].wall_3_avoidance_line =
             (param_1->land_info).wall_3_avoidance_line;
        (param_1->land_info).land[(param_1->land_info).land_num + iVar8].wall_4_avoidance_line =
             (param_1->land_info).wall_4_avoidance_line;
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].wall_fade =
             (param_1->land_info).wall_fade;
        do {
          iStack_c = iStack_c + 1;
          bVar1 = true;
          iVar9 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x1de);
          iVar9 = (iVar9 * (param_1->_padding_ + -0x10)) / 0x7fff + 8;
          iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x1df);
          iStack_8 = 0;
          iVar6 = (iVar6 * (param_1->_padding_ + -0x10)) / 0x7fff + 8;
          if (0 < (param_1->land_info).land_num) {
            plVar3 = &(param_1->land_info).land[0].y;
            do {
              if (!bVar1) goto LAB_00488399;
              if ((iVar9 - plVar3[-1]) * (iVar9 - plVar3[-1]) +
                  (iVar6 - *plVar3) * (iVar6 - *plVar3) < 400) {
                bVar1 = false;
              }
              iStack_8 = iStack_8 + 1;
              plVar3 = plVar3 + 0xd;
            } while (iStack_8 < (param_1->land_info).land_num);
          }
          if (bVar1) break;
LAB_00488399:
        } while (iStack_c < 1000);
        if (999 < iStack_c) {
          iStack_10 = iVar8;
        }
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].x = iVar9;
        (param_1->land_info).land[iVar8 + (param_1->land_info).land_num].y = iVar6;
        (param_1->object_info).objects[(param_1->object_info).object_num].terrain = -1;
        (param_1->object_info).objects[(param_1->object_info).object_num].group_flag = '\x02';
        (param_1->object_info).objects[(param_1->object_info).object_num].scale_flag = '\0';
        (param_1->object_info).objects[(param_1->object_info).object_num].object_number_per_group =
             8;
        (param_1->object_info).objects[(param_1->object_info).object_num].object_number_varience = 0
        ;
        (param_1->object_info).objects[(param_1->object_info).object_num].number_of_groups = 1;
        (param_1->object_info).objects[(param_1->object_info).object_num].group_area = 4;
        (param_1->object_info).objects[(param_1->object_info).object_num].player_id = 0;
        (param_1->object_info).objects[(param_1->object_info).object_num].land_id =
             iVar8 + (param_1->land_info).land_num;
        (param_1->object_info).objects[(param_1->object_info).object_num].land_inner_radius = 0;
        (param_1->object_info).objects[(param_1->object_info).object_num].land_outer_radius = 0x1a;
        (param_1->object_info).objects[(param_1->object_info).object_num].object_exclusion_zone = 0;
        iVar7 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x1fd);
        iVar11 = (param_1->object_info).object_num;
        if (iVar7 < 0x3fff) {
          (param_1->object_info).objects[iVar11].obj_id = 0x66;
        }
        else {
          (param_1->object_info).objects[iVar11].obj_id = 0x42;
        }
        (param_1->object_info).object_num = (param_1->object_info).object_num + 1;
        (param_1->object_info).lands[(param_1->object_info).land_num].y = iVar6;
        (param_1->object_info).lands[(param_1->object_info).land_num].x = iVar9;
        (param_1->object_info).lands[(param_1->object_info).land_num].id =
             iVar8 + (param_1->land_info).land_num;
        (param_1->object_info).lands[(param_1->object_info).land_num].player_id = 0;
        iVar8 = iVar8 + 1;
        (param_1->object_info).land_num = (param_1->object_info).land_num + 1;
      } while (iVar8 < iStack_10);
    }
    plVar3 = &(param_1->land_info).land_num;
    *plVar3 = *plVar3 + iStack_10;
  }
  iVar8 = 0;
  if (0 < (param_1->object_info).object_num) {
    plVar3 = &(param_1->object_info).objects[0].object_exclusion_zone;
    do {
      if (-1 < plVar3[-3]) {
        switch(((RGE_Object_Info_Line *)(plVar3 + -0xb))->obj_id) {
        case 0x3b:
        case 0x41:
        case 0x42:
        case 0x66:
          *plVar3 = 0xc;
        }
        goto switchD_004885d5_caseD_3c;
      }
      if (plVar3[-3] != -2) goto switchD_004885d5_caseD_3c;
      switch(((RGE_Object_Info_Line *)(plVar3 + -0xb))->obj_id) {
      case 0x3b:
      case 0x42:
        iVar9 = *(int *)(param_1->_padding_ + 8);
        goto LAB_00488624;
      case 0x41:
        iVar9 = *(int *)(param_1->_padding_ + 8);
        *plVar3 = (int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3;
        break;
      case 0x66:
        iVar9 = *(int *)(param_1->_padding_ + 8);
LAB_00488624:
        *plVar3 = iVar9 / 6;
      }
switchD_004885d5_caseD_3c:
      iVar8 = iVar8 + 1;
      plVar3 = plVar3 + 0xc;
    } while (iVar8 < (param_1->object_info).object_num);
  }
  iVar8 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x236);
  TDebuggingLog::Log(L,(char *)L,s_Random_Map_object_initilization_,iVar8);
  return;
}

// --------------------------------------------------

// Function: FUN_00488675
// Address: 00488675
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_elevation_initilizati: "Random Map elevation initilization, rand: %d"
void __fastcall FUN_00488675(undefined4 param_1)
{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  int in_EAX;
  int iVar4;
  char *pcVar5;
  undefined3 uVar8;
  undefined1 *puVar6;
  long lVar7;
  RGE_RMM_Database_Controller *this;
  TDebuggingLog *this_00;
  char unaff_BL;
  char *unaff_ESI;
  RGE_Elevation_Info *pRVar9;
  
  iVar4 = in_EAX + -1;
  pcVar5 = (char *)(CONCAT22((short)((uint)iVar4 >> 0x10),
                             CONCAT11((char)((uint)iVar4 >> 8) + unaff_BL,(char)iVar4)) + -1);
  *pcVar5 = *pcVar5 + (char)pcVar5;
  uVar8 = (undefined3)((uint)pcVar5 >> 8);
  cVar3 = (char)pcVar5 + '\t';
  puVar6 = (undefined1 *)CONCAT31(uVar8,cVar3 + (&stack0x00000000)[CONCAT31(uVar8,cVar3)] + 'C');
  LOCK();
  uVar1 = *puVar6;
  *puVar6 = (char)param_1;
  UNLOCK();
  puVar6 = puVar6 + *(int *)(unaff_ESI + -0x79e9ffb8) + -1;
  *unaff_ESI = *unaff_ESI + unaff_BL;
  LOCK();
  uVar2 = *puVar6;
  *puVar6 = uVar1;
  this = (RGE_RMM_Database_Controller *)CONCAT31((int3)((uint)param_1 >> 8),uVar2);
  UNLOCK();
  pcVar5 = (char *)(((uint)puVar6 ^ 0x86) - 1);
  *pcVar5 = *pcVar5 + (char)pcVar5;
  RGE_RMM_Database_Controller::add_elevation_module(this);
  debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x243);
  iVar4 = 0;
  if (0 < (this->elevation_info).elevation_num) {
    pRVar9 = &this->elevation_info;
    do {
      lVar7 = __ftol();
      pRVar9->elevation[0].elevation_size = lVar7;
      iVar4 = iVar4 + 1;
      pRVar9 = (RGE_Elevation_Info *)(pRVar9->elevation + 1);
    } while (iVar4 < (this->elevation_info).elevation_num);
  }
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x24b);
  TDebuggingLog::Log(this_00,(char *)L,s_Random_Map_elevation_initilizati,iVar4);
  return;
}

// --------------------------------------------------

// Function: FUN_0048879d
// Address: 0048879d
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_shallows_initilizatio: "Random Map shallows initilization, rand: %d"
void __fastcall FUN_0048879d(RGE_Random_Map_Module *param_1)
{
  long *plVar1;
  RGE_RMM_Shallows_Generator *this;
  long *plVar2;
  TDebuggingLog *this_00;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  RGE_Shallows_Info RStack_328;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e6de;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar3 = 0;
  RStack_328.shallows_num = param_1[0x6c].map_height;
  if (0 < RStack_328.shallows_num) {
    plVar2 = &RStack_328.shallows[0].y;
    plVar1 = &param_1[1].map_height;
    do {
      iVar3 = iVar3 + 1;
      ((RGE_Shallows_Info_Line *)(plVar2 + -1))->x = plVar1[-1];
      *plVar2 = *plVar1;
      plVar1 = plVar1 + 0xd;
      plVar2 = plVar2 + 2;
    } while (iVar3 < RStack_328.shallows_num);
  }
  this = (RGE_RMM_Shallows_Generator *)operator_new(0x34c);
  uStack_4 = 0;
  if (this != (RGE_RMM_Shallows_Generator *)0x0) {
    RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator(this,param_1->map,param_1,&RStack_328);
  }
  uStack_4 = 0xffffffff;
  iVar3 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x25f);
  TDebuggingLog::Log(this_00,(char *)L,s_Random_Map_shallows_initilizatio,iVar3);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0048886e
// Address: 0048886e
undefined4 __fastcall FUN_0048886e(RGE_RMM_Database_Controller *param_1)
{
  int iVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = RGE_RMM_Database_Controller::generate(param_1);
  iVar6 = param_1->_padding_;
  iVar4 = 0;
  if (0 < iVar6) {
    iVar5 = 0;
    do {
      iVar6 = 0;
      if (0 < param_1->_padding_) {
        iVar3 = 0;
        do {
          if ((*(byte *)(*(int *)(param_1->_padding_ + iVar5) + 5 + iVar3) & 0x1f) == 0x10) {
            iVar1 = *(int *)(param_1->_padding_ + iVar5);
            *(byte *)(iVar1 + 5 + iVar3) = *(byte *)(iVar1 + 5 + iVar3) & 0xe0;
          }
          iVar6 = iVar6 + 1;
          iVar3 = iVar3 + 0x18;
        } while (iVar6 < param_1->_padding_);
      }
      iVar6 = param_1->_padding_;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar4 < iVar6);
  }
  return CONCAT31((int3)((uint)iVar6 >> 8),uVar2);
}

// --------------------------------------------------

// Function: FUN_004888d7
// Address: 004888d7
RGE_Random_Map_Module * __thiscall
FUN_004888d7(RGE_Random_Map_Module *param_1,RGE_Map *param_2,RGE_Random_Map_Module *param_3,
            int *param_4)
{
  int iVar1;
  RGE_Random_Map_Module *pRVar2;
  
  RGE_Random_Map_Module::RGE_Random_Map_Module(param_1,param_2,param_3,'\x01');
  param_1->_padding_ = (int)&RGE_RMM_Terrain_Generator::_vftable_;
  pRVar2 = param_1 + 1;
  for (iVar1 = 0x4a6; iVar1 != 0; iVar1 = iVar1 + -1) {
    pRVar2->_padding_ = *param_4;
    param_4 = param_4 + 1;
    pRVar2 = (RGE_Random_Map_Module *)&pRVar2->parent;
  }
  param_1->schedule = 2.0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048891b
// Address: 0048891b
undefined4 __fastcall FUN_0048891b(RGE_RMM_Terrain_Generator *param_1)
{
  float fVar1;
  RGE_Terrain_Info_Line RVar2;
  long lVar3;
  RGE_Zone_Map *pRVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  RGE_Terrain_Info *pRVar8;
  long *plVar9;
  undefined1 in_stack_fffffe40 [20];
  undefined4 uVar10;
  undefined4 uVar11;
  RGE_Terrain_Info *pRStack_190;
  float afStack_18c [99];
  
  RGE_RMM_Terrain_Generator::generate_modifiers(param_1);
  pRStack_190 = (RGE_Terrain_Info *)0x0;
  pfVar5 = afStack_18c;
  do {
    fVar1 = (float)(int)pRStack_190;
    pRStack_190 = (RGE_Terrain_Info *)((int)pRStack_190 + 1);
    *pfVar5 = fVar1;
    pfVar5 = pfVar5 + 1;
  } while ((int)pRStack_190 < 99);
  uVar10 = 0x488964;
  lVar3 = RGE_Zone_Map_List::create_zone_map
                    (*(RGE_Zone_Map_List **)(param_1->_padding_ + 0x8dc4),afStack_18c,99);
  uVar11 = 0x488973;
  pRVar4 = RGE_Zone_Map_List::get_zone_map
                     (*(RGE_Zone_Map_List **)(param_1->_padding_ + 0x8dc4),lVar3);
  param_1->map_zone = pRVar4;
  iVar7 = 0;
  if (0 < (param_1->info).terrain_num) {
    pRStack_190 = &param_1->info;
    do {
      pRVar8 = pRStack_190;
      plVar9 = (long *)&stack0xfffffe40;
      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
        *plVar9 = pRVar8->terrain[0].terrain_size;
        pRVar8 = (RGE_Terrain_Info *)&pRVar8->terrain[0].terrain_generated;
        plVar9 = plVar9 + 1;
      }
      RVar2.base_terrain_type = uVar10;
      RVar2.terrain_size = in_stack_fffffe40._0_4_;
      RVar2.terrain_generated = in_stack_fffffe40._4_4_;
      RVar2.terrain_type = in_stack_fffffe40._8_4_;
      RVar2.clumps = in_stack_fffffe40._12_4_;
      RVar2.spacing = in_stack_fffffe40._16_4_;
      RVar2.clumpiness_factor = uVar11;
      RVar2.avoid_hot_spots = lVar3;
      RGE_RMM_Terrain_Generator::base_terrain_generate(param_1,RVar2);
      iVar7 = iVar7 + 1;
      pRStack_190 = (RGE_Terrain_Info *)(pRStack_190->terrain + 1);
    } while (iVar7 < (param_1->info).terrain_num);
  }
  RGE_RMM_Terrain_Generator::check_borders(param_1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004889cd
// Address: 004889cd
char FUN_004889cd(char param_1)
{
  if (param_1 == '\x01') {
    return param_1;
  }
  if (param_1 == '\x04') {
    return true;
  }
  return param_1 == '\x16';
}

// --------------------------------------------------

// Function: FUN_004889ec
// Address: 004889ec
void __fastcall FUN_004889ec(RGE_RMM_Terrain_Generator *param_1)
{
  int iVar1;
  int iVar2;
  bool bVar3;
  uchar uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_8;
  
  iVar6 = 0;
  iVar1 = param_1->_padding_ + -1;
  iVar5 = param_1->_padding_;
  iVar2 = iVar5 + -1;
  if (0 < param_1->_padding_) {
    do {
      iVar7 = 0;
      iStack_8 = 0;
      if (0 < iVar5) {
        do {
          uVar4 = RGE_RMM_Terrain_Generator::water
                            (param_1,*(byte *)(*(int *)(param_1->_padding_ + iVar6 * 4) + 5 + iVar7)
                                     & 0x1f);
          if (uVar4 == '\0') {
            bVar3 = false;
            if (((0 < iVar6) &&
                (uVar4 = RGE_RMM_Terrain_Generator::water
                                   (param_1,*(byte *)(*(int *)(param_1->_padding_ + -4 + iVar6 * 4)
                                                      + 5 + iVar7) & 0x1f), uVar4 != '\0')) ||
               ((iVar6 < iVar1 &&
                (uVar4 = RGE_RMM_Terrain_Generator::water
                                   (param_1,*(byte *)(*(int *)(param_1->_padding_ + 4 + iVar6 * 4) +
                                                      5 + iVar7) & 0x1f), uVar4 != '\0')))) {
              bVar3 = true;
            }
            if ((0 < iVar7) &&
               (((uVar4 = RGE_RMM_Terrain_Generator::water
                                    (param_1,*(byte *)(*(int *)(param_1->_padding_ + iVar6 * 4) +
                                                       -0x13 + iVar7) & 0x1f), uVar4 != '\0' ||
                 ((0 < iVar6 &&
                  (uVar4 = RGE_RMM_Terrain_Generator::water
                                     (param_1,*(byte *)(*(int *)(param_1->_padding_ + -4 + iVar6 * 4
                                                                ) + -0x13 + iVar7) & 0x1f),
                  uVar4 != '\0')))) ||
                ((iVar6 < iVar1 &&
                 (uVar4 = RGE_RMM_Terrain_Generator::water
                                    (param_1,*(byte *)(*(int *)(param_1->_padding_ + 4 + iVar6 * 4)
                                                       + -0x13 + iVar7) & 0x1f), uVar4 != '\0'))))))
{
              bVar3 = true;
            }
            if ((iStack_8 < iVar2) &&
               (((uVar4 = RGE_RMM_Terrain_Generator::water
                                    (param_1,*(byte *)(*(int *)(param_1->_padding_ + iVar6 * 4) +
                                                       0x1d + iVar7) & 0x1f), uVar4 != '\0' ||
                 ((0 < iVar6 &&
                  (uVar4 = RGE_RMM_Terrain_Generator::water
                                     (param_1,*(byte *)(*(int *)(param_1->_padding_ + -4 + iVar6 * 4
                                                                ) + 0x1d + iVar7) & 0x1f),
                  uVar4 != '\0')))) ||
                ((iVar6 < iVar1 &&
                 (uVar4 = RGE_RMM_Terrain_Generator::water
                                    (param_1,*(byte *)(*(int *)(param_1->_padding_ + 4 + iVar6 * 4)
                                                       + 0x1d + iVar7) & 0x1f), uVar4 != '\0'))))))
{
              bVar3 = true;
            }
            if (bVar3) {
              iVar5 = *(int *)(param_1->_padding_ + iVar6 * 4);
              *(byte *)(iVar5 + 5 + iVar7) = *(byte *)(iVar5 + 5 + iVar7) & 0xe2 | 2;
            }
          }
          iVar5 = param_1->_padding_;
          iStack_8 = iStack_8 + 1;
          iVar7 = iVar7 + 0x18;
        } while (iStack_8 < iVar5);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1->_padding_);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00488b89
// Address: 00488b89
uint __thiscall
FUN_00488b89(int param_1,byte param_2,int param_3,int param_4,int param_5,byte param_6)
{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  char cStack_14;
  
  cStack_14 = '\x01';
  if (0 < param_5) {
    iVar4 = param_3 - param_5;
    iVar5 = param_4 - param_5;
    uVar2 = param_3 + param_5;
    param_5 = param_4 + param_5;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    if (*(int *)(param_1 + 0x14) <= (int)uVar2) {
      uVar2 = *(int *)(param_1 + 0x14) - 1;
    }
    if (*(int *)(param_1 + 0x18) <= param_5) {
      param_5 = *(int *)(param_1 + 0x18) + -1;
    }
    iVar7 = *(int *)(*(int *)(param_1 + 0x10) + iVar5 * 4);
    piVar8 = (int *)(*(int *)(param_1 + 0x10) + iVar5 * 4);
    for (; iVar5 <= param_5; iVar5 = iVar5 + 1) {
      if (iVar4 <= (int)uVar2) {
        pbVar6 = (byte *)(iVar7 + iVar4 * 0x18 + 5);
        iVar7 = iVar4;
        do {
          bVar3 = *pbVar6 & 0x1f;
          if (((bVar3 != param_6) &&
              ((*pbVar6 & 0x1f) != *(byte *)(*(int *)(param_1 + 0xc) + 0xba + (uint)param_6 * 0x198)
              )) && (bVar3 != param_2)) {
            return uVar2 & 0xffffff00;
          }
          iVar7 = iVar7 + 1;
          pbVar6 = pbVar6 + 0x18;
        } while (iVar7 <= (int)uVar2);
      }
      piVar8 = piVar8 + 1;
      iVar7 = *piVar8;
    }
  }
  iVar5 = param_3 + -2;
  iVar4 = param_4 + -2;
  iVar7 = param_3 + 2;
  param_4 = param_4 + 2;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (*(int *)(param_1 + 0x14) <= iVar7) {
    iVar7 = *(int *)(param_1 + 0x14) + -1;
  }
  if (*(int *)(param_1 + 0x18) <= param_4) {
    param_4 = *(int *)(param_1 + 0x18) + -1;
  }
  iVar9 = *(int *)(param_1 + 0x10) + iVar4 * 4;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + iVar4 * 4);
  if (iVar4 <= param_4) {
    param_3 = (param_4 - iVar4) + 1;
    cStack_14 = '\x01';
    do {
      if (iVar5 <= iVar7) {
        pbVar6 = (byte *)(iVar1 + iVar5 * 0x18 + 5);
        iVar4 = (iVar7 - iVar5) + 1;
        do {
          if ((*pbVar6 & 0x1f) == param_2) {
            cStack_14 = cStack_14 + '\x01';
          }
          pbVar6 = pbVar6 + 0x18;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      iVar1 = *(int *)(iVar9 + 4);
      iVar9 = iVar9 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return CONCAT31((int3)((uint)iVar7 >> 8),cStack_14);
}

// --------------------------------------------------

// Function: FUN_00488d45
// Address: 00488d45
void __fastcall FUN_00488d45(int param_1)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iStack_c;
  int iStack_8;
  
  uVar2 = *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x18);
  iVar4 = 0;
  puVar6 = *(undefined4 **)(param_1 + 0x20);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      iVar7 = 0;
      if (0 < *(int *)(param_1 + 0x14)) {
        do {
          iStack_8 = *(int *)(param_1 + 0x12c4);
          iStack_c = 0;
          iVar1 = 0;
          if (0 < iStack_8) {
            iVar5 = param_1 + 0xc98;
            do {
              iVar1 = __ftol();
              iVar1 = *(int *)(iVar5 + 4) - iVar1;
              if (0 < iVar1) {
                iStack_c = iStack_c + *(int *)(iVar5 + 8) * iVar1;
              }
              iVar5 = iVar5 + 0x10;
              iStack_8 = iStack_8 + -1;
              iVar1 = iStack_c;
            } while (iStack_8 != 0);
          }
          if (iVar1 < 0x65) {
            *(char *)(*(int *)(*(int *)(param_1 + 0x24) + iVar4 * 4) + iVar7) = (char)iVar1;
          }
          else {
            *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x24) + iVar4 * 4) + iVar7) = 0x65;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(param_1 + 0x14));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x18));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00488e5b
// Address: 00488e5b
int __thiscall FUN_00488e5b(int param_1,byte param_2)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = **(uint **)(param_1 + 0x10);
  uVar1 = uVar2 + *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x18) * 0x18;
  for (; uVar2 < uVar1; uVar2 = uVar2 + 0x18) {
    if ((*(byte *)(uVar2 + 5) & 0x1f) == param_2) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_00488e96
// Address: 00488e96
// [HELPER] s_C__msdev_work_age1_x1_rmm_terr_c: "C:\msdev\work\age1_x1\rmm_terr.cpp"
void __thiscall FUN_00488e96(RGE_Random_Map_Module *param_1,Map_Stack *param_2)
{
  Map_Stack *pMVar1;
  int iVar2;
  int iVar3;
  Map_Stack *pMVar4;
  Map_Stack *pMVar5;
  int iVar6;
  int iVar7;
  
  pMVar5 = param_2;
  iVar2 = param_1->map_height;
  iVar3 = param_1->map_width;
  pMVar4 = param_1->stack_array;
  pMVar4->prev = param_2;
  pMVar1 = pMVar4 + iVar2 * iVar3 + -1;
  pMVar4->next = pMVar4 + 1;
  param_2->next = pMVar4;
  pMVar1->next = (Map_Stack *)0x0;
  pMVar1->prev = pMVar1 + -1;
  pMVar4 = pMVar4 + 1;
  while (pMVar4 < pMVar1) {
    pMVar4->next = pMVar4 + 1;
    pMVar4->prev = pMVar4 + -1;
    pMVar4 = pMVar4 + 1;
  }
  iVar6 = param_1->map_height * param_1->map_width;
  param_2 = (Map_Stack *)((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3);
  if (0 < (int)param_2) {
    do {
      iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_terr_c,0x10f);
      iVar7 = debug_rand(s_C__msdev_work_age1_x1_rmm_terr_c,0x110);
      RGE_Random_Map_Module::add_stack_node
                (param_1,pMVar5,
                 param_1->stack_offsets[(iVar7 * (iVar2 + -1)) / 0x7fff] +
                 (iVar6 * (iVar3 + -1)) / 0x7fff);
      param_2 = (Map_Stack *)((int)param_2 + -1);
    } while (param_2 != (Map_Stack *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00488f8f
// Address: 00488f8f
void __thiscall FUN_00488f8f(RGE_Random_Map_Module *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_2 - param_4;
  iVar1 = param_3 - param_4;
  param_2 = param_4 + param_2;
  param_4 = param_4 + param_3;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (param_1->map_width <= param_2) {
    param_2 = param_1->map_width + -1;
  }
  if (param_1->map_height <= param_4) {
    param_4 = param_1->map_height + -1;
  }
  for (; iVar1 <= param_4; iVar1 = iVar1 + 1) {
    if (iVar2 <= param_2) {
      iVar3 = iVar2 * 0x18;
      iVar4 = (param_2 - iVar2) + 1;
      do {
        RGE_Random_Map_Module::remove_stack_node
                  (param_1,(Map_Stack *)((int)&param_1->stack_offsets[iVar1]->x + iVar3));
        iVar3 = iVar3 + 0x18;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  return;
}

// --------------------------------------------------

