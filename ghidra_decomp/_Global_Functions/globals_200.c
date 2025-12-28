// GLOBAL FUNCTIONS PART 200
// Function: $E14
// Address: 0046b0b0
// XREFS: $E17
void _E14(void)
{
  PathingSystem::PathingSystem(&aiPathSystem,0xff,0xff,1,(RGE_Map *)0x0,(RGE_Game_World *)0x0);
  return;
}

// --------------------------------------------------

// Function: $E16
// Address: 0046b0d0
// XREFS: $E17
void _E16(void)
{
  atexit(_E15);
  return;
}

// --------------------------------------------------

// Function: $E15
// Address: 0046b0e0
// XREFS: $E16
void _E15(void)
{
  PathingSystem::~PathingSystem(&aiPathSystem);
  return;
}

// --------------------------------------------------

// Function: FUN_0046d202
// Address: 0046d202
// XREFS: None
void FUN_0046d202(void)
{
  uint *unaff_ESI;
  
  *unaff_ESI = *unaff_ESI << 0x11 | *unaff_ESI >> 0xf;
  *unaff_ESI = *unaff_ESI << 0x11 | *unaff_ESI >> 0xf;
  *unaff_ESI = *unaff_ESI << 0x19 | *unaff_ESI >> 7;
  *unaff_ESI = *unaff_ESI << 3 | *unaff_ESI >> 0x1d;
  *unaff_ESI = *unaff_ESI << 0x10 | *unaff_ESI >> 0x10;
  *unaff_ESI = *unaff_ESI << 0x10 | *unaff_ESI >> 0x10;
  *unaff_ESI = *unaff_ESI << 0x18 | *unaff_ESI >> 8;
  *unaff_ESI = *unaff_ESI << 0xf | *unaff_ESI >> 0x11;
  return;
}

// --------------------------------------------------

// Function: FUN_0046dc8a
// Address: 0046dc8a
// XREFS: None
int __fastcall FUN_0046dc8a(int param_1)
{
  int iVar1;
  int in_EAX;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  int iVar5;
  undefined2 in_CS;
  int *piStack_4;
  
  piStack_4 = (int *)CONCAT22(piStack_4._2_2_,in_CS);
  if (cRam00000000 != '\0' && SCARRY1(cRam00000000,'\0') == cRam00000000 < '\0') {
    *(undefined1 *)(unaff_EDI + 0x5e) = *(undefined1 *)(unaff_EDI + 0x5e);
    return 0;
  }
  *(char *)(unaff_EDI + -0x56ffb925) = *(char *)(unaff_EDI + -0x56ffb925) + (char)param_1;
  iVar5 = *(int *)(param_1 + 0x11dce8);
  do {
    if (iVar5 < 0) {
      return in_EAX;
    }
    if (*(int *)(param_1 + 0x11dcf0) + -1 < iVar5) {
      pvVar2 = operator_new(iVar5 * 4 + 4);
      if (pvVar2 != (void *)0x0) {
        iVar3 = 0;
        if (0 < *(int *)(param_1 + 0x11dcf0)) {
          do {
            if (iVar5 + 1 <= iVar3) break;
            iVar3 = iVar3 + 1;
            *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x11dce4) + -4 + iVar3 * 4);
          } while (iVar3 < *(int *)(param_1 + 0x11dcf0));
        }
        operator_delete(*(void **)(param_1 + 0x11dce4));
        *(void **)(param_1 + 0x11dce4) = pvVar2;
        *(int *)(param_1 + 0x11dcf0) = iVar5 + 1;
      }
    }
    iVar3 = piStack_4[1];
    iVar1 = *(int *)(*(int *)(param_1 + 0x11dce4) + iVar5 * 4);
    in_EAX = 0;
    if (0 < iVar3) {
      do {
        if (piStack_4[3] <= in_EAX) break;
        if (*(int *)(*piStack_4 + in_EAX * 4) == iVar1) goto LAB_0046ddc8;
        in_EAX = in_EAX + 1;
      } while (in_EAX < iVar3);
    }
    if (piStack_4[3] + -1 < iVar3) {
      iVar3 = iVar3 + 1;
      pvVar2 = operator_new(iVar3 * 4);
      if (pvVar2 != (void *)0x0) {
        iVar4 = 0;
        if (0 < piStack_4[3]) {
          do {
            if (iVar3 <= iVar4) break;
            iVar4 = iVar4 + 1;
            *(undefined4 *)((int)pvVar2 + iVar4 * 4 + -4) =
                 *(undefined4 *)(*piStack_4 + -4 + iVar4 * 4);
          } while (iVar4 < piStack_4[3]);
        }
        operator_delete((void *)*piStack_4);
        *piStack_4 = (int)pvVar2;
        piStack_4[3] = iVar3;
      }
    }
    *(int *)(*piStack_4 + piStack_4[1] * 4) = iVar1;
    in_EAX = piStack_4[1] + 1;
    piStack_4[1] = in_EAX;
LAB_0046ddc8:
    iVar5 = iVar5 + -1;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0046fea9
// Address: 0046fea9
// XREFS: None
void __fastcall FUN_0046fea9(undefined4 param_1,int param_2)
{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  int in_EAX;
  int *piVar4;
  byte unaff_BH;
  int unaff_EBP;
  char *unaff_ESI;
  int *unaff_EDI;
  char in_SF;
  char in_OF;
  undefined4 uStack00000078;
  undefined4 uStack0000007c;
  undefined4 uStack00000080;
  undefined4 uStack00000084;
  char *pcStack00000088;
  undefined4 in_stack_00000090;
  
  do {
  } while (in_OF != in_SF);
  pbVar1 = (byte *)(param_2 + 0x530046fc);
  bVar3 = *pbVar1;
  *pbVar1 = *pbVar1 + unaff_BH;
  unaff_ESI[1] = unaff_ESI[1] + '\x01';
  piVar4 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),
                           CONCAT11((char)((uint)param_1 >> 8) + unaff_BH + CARRY1(bVar3,unaff_BH),
                                    (char)param_1));
  pcVar2 = (char *)(unaff_EBP + -0x21dffba + (int)unaff_EDI * 8);
  *pcVar2 = *pcVar2 + (char)((uint)in_EAX >> 8);
  *unaff_ESI = *unaff_ESI + (char)param_1;
  pcStack00000088 = unaff_ESI + 4;
  *(char *)((int)unaff_EDI + 0x46fe) = *(char *)((int)unaff_EDI + 0x46fe) + (char)param_2;
  *unaff_EDI = *unaff_EDI + in_EAX;
  uStack00000084 = 1;
  uStack00000080 = 0;
  uStack0000007c = in_stack_00000090;
  uStack00000078 = 0x46ff16;
  (**(code **)(*piVar4 + 0xf0))();
  uStack00000078 = 0x46ff1e;
  RGE_Object_List::rehook_list((RGE_Object_List *)piVar4[10]);
  uStack00000078 = 0x46ff26;
  RGE_Object_List::rehook_list((RGE_Object_List *)piVar4[0xb]);
  uStack00000078 = 0x46ff2e;
  RGE_Object_List::rehook_list((RGE_Object_List *)piVar4[0xc]);
  return;
}

// --------------------------------------------------

// Function: FUN_004730f1
// Address: 004730f1
// XREFS: None
// Error: 
Low-level Error: Cannot properly adjust input varnodes

// --------------------------------------------------

// Function: FUN_00473857
// Address: 00473857
// XREFS: None
long __fastcall
FUN_00473857(TButtonPanel *param_1,char param_2,undefined4 param_3,void *param_4,uint param_5,
            uint param_6,long param_7)
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  char cVar9;
  undefined4 in_EAX;
  int iVar7;
  long lVar8;
  char unaff_BL;
  int unaff_EBP;
  uint unaff_retaddr;
  uint uVar5;
  char *pcVar6;
  
  bVar1 = 9 < ((byte)in_EAX & 0xf) || (unaff_retaddr & 0x10) != 0;
  bVar3 = (byte)in_EAX + bVar1 * '\x06' & 0xf;
  *(char *)(unaff_EBP + 0x54004737) = *(char *)(unaff_EBP + 0x54004737) + unaff_BL;
  bVar2 = 9 < bVar3 || bVar1;
  bVar3 = bVar3 + bVar2 * '\x06' & 0xf;
  cVar9 = (char)((uint)in_EAX >> 8) + bVar1 + bVar2;
  *(char *)&param_1->_padding_ = (char)param_1->_padding_ + cVar9;
  bVar2 = 9 < bVar3 || bVar2;
  uVar5 = CONCAT31((int3)((uint)in_EAX >> 8),bVar3 + bVar2 * '\x06') & 0xffff000f;
  cVar4 = (char)uVar5;
  pcVar6 = (char *)CONCAT22((short)(uVar5 >> 0x10),CONCAT11(cVar9 + bVar2,cVar4));
  pcVar6[0x38] = pcVar6[0x38] + param_2;
  *pcVar6 = *pcVar6 + cVar4;
  iVar7 = CONCAT31((int3)((uint)pcVar6 >> 8),cVar4 + '$');
  *(int *)((int)&param_3 + iVar7) = *(int *)((int)&param_3 + iVar7) + iVar7;
  if (((param_5 == 0x101) && (param_1->key_down != 0)) && (param_6 == param_1->key_down)) {
    param_1->key_down = 0;
    if (param_1->buttonTypeValue != Radio) {
      param_1->is_down = 0;
    }
    (**(code **)(param_1->_padding_ + 0x20))(1);
    SendMessageA(*(undefined4 *)(param_1->_padding_ + 4),0xf,0,0);
    TButtonPanel::do_action(param_1);
    return 1;
  }
  lVar8 = TPanel::wnd_proc((TPanel *)param_1,param_4,param_5,param_6,param_7);
  return lVar8;
}

// --------------------------------------------------

// Function: FUN_004747db
// Address: 004747db
// XREFS: None
void __fastcall
FUN_004747db(int param_1,char *param_2,undefined4 param_3,undefined4 param_4,TShape *param_5,
            short param_6,int param_7,int param_8,int param_9,int param_10)
{
  char *pcVar1;
  int in_EAX;
  int iVar2;
  char *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  TShape *pTVar4;
  char cVar3;
  
  pcVar1 = (char *)(unaff_ESI + 0x46ab0048 + in_EAX * 2);
  cVar3 = (char)((uint)in_EAX >> 8);
  *pcVar1 = *pcVar1 + cVar3;
  param_2[-0xaffb8ba] = param_2[-0xaffb8ba] + (char)((uint)param_2 >> 8);
  cVar3 = cVar3 + (char)((uint)unaff_EBX >> 8);
  iVar2 = CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(cVar3,(char)in_EAX));
  *unaff_EBX = *unaff_EBX + (char)in_EAX;
  *param_2 = *param_2 + (char)param_1;
  *(char *)(unaff_EBP + 0x47) = *(char *)(unaff_EBP + 0x47) + (char)param_1;
  pcVar1 = (char *)(unaff_EDI + 0x50 + iVar2 * 2);
  *pcVar1 = *pcVar1 + (char)param_2;
  unaff_EBX[0x47] = unaff_EBX[0x47] + (char)unaff_EBX;
  param_2[0x47] = param_2[0x47] + cVar3;
  *(char *)(unaff_ESI + -0x5affb8b6) = *(char *)(unaff_ESI + -0x5affb8b6) + (char)unaff_EBX;
  pcVar1 = (char *)(unaff_EDI + 0x47b30054 + iVar2 * 2);
  *pcVar1 = *pcVar1 + (char)((uint)param_1 >> 8);
  *(char *)(iVar2 + 0x56909090) = *(char *)(iVar2 + 0x56909090) + (char)param_2;
  if (*(TButtonPanel **)(param_1 + 0xf8) != (TButtonPanel *)0x0) {
    pTVar4 = param_5;
    if (param_5 == (TShape *)0x0) {
      param_6 = -1;
      pTVar4 = (TShape *)0x0;
    }
    TButtonPanel::set_picture(*(TButtonPanel **)(param_1 + 0xf8),0,pTVar4,param_6);
  }
  if (*(TScrollBarPanel **)(param_1 + 0x100) != (TScrollBarPanel *)0x0) {
    TScrollBarPanel::set_buttons
              (*(TScrollBarPanel **)(param_1 + 0x100),param_5,param_7,param_8,param_9,param_10);
  }
  return;
}

// --------------------------------------------------

// Function: pnl_sub_wnd_proc
// Address: 00475930
// XREFS: setup
long pnl_sub_wnd_proc(void *param_1,uint param_2,uint param_3,long param_4)
{
  TEditPanel *this;
  long lVar1;
  
  this = (TEditPanel *)GetWindowLongA(param_1,0xffffffeb);
  if (this != (TEditPanel *)0x0) {
    lVar1 = TEditPanel::sub_wnd_proc(this,param_1,param_2,param_3,param_4);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00476422
// Address: 00476422
// XREFS: None
// [HELPER] s_10: "10"
undefined4 __fastcall FUN_00476422(int param_1,int param_2)
{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  char cVar5;
  int unaff_EBX;
  undefined1 *puVar6;
  int unaff_EBP;
  undefined4 unaff_ESI;
  int unaff_EDI;
  byte in_CF;
  bool bVar7;
  int aiStack_10 [2];
  int aiStack_8 [2];
  TEditPanel *this;
  
  iVar4 = *(int *)(param_1 + 0x47);
  iVar3 = -(uint)in_CF;
  *(char *)(param_2 + 0x47) = *(char *)(param_2 + 0x47) + (char)in_EAX;
  *(char *)(unaff_EBX + 0x62) = *(char *)(unaff_EBX + 0x62) + (char)unaff_EBX;
  cVar5 = (char)param_1 + (char)unaff_EBX;
  this = (TEditPanel *)CONCAT31((int3)((uint)param_1 >> 8),cVar5);
  if (cVar5 != '\0') {
    *(char *)(unaff_EBP + 0xf5d75c0) = *(char *)(unaff_EBP + 0xf5d75c0) + (char)in_EAX;
    *(char *)(unaff_EBX + 0x10096) = *(char *)(unaff_EBX + 0x10096) + cVar5;
    pcVar2 = (char *)((int)&this->_padding_ + 3);
    *pcVar2 = *pcVar2 + cVar5;
    this[0xaf]._padding_ = this[0xaf]._padding_ >> 1;
    halt_baddata();
  }
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + (char)param_2;
  *(undefined4 *)((int)aiStack_8 + (iVar3 - iVar4) + 4) = unaff_ESI;
  *(int *)((int)aiStack_8 + (iVar3 - iVar4)) = unaff_EDI + 2;
  if (DAT_0086b244 != 0) {
    DAT_0086b244 = 0;
    return 0;
  }
  iVar1 = *(int *)(&stack0x00000004 + (iVar3 - iVar4));
  if (iVar1 == 9) {
    return 0;
  }
  if ((iVar1 == 0xd) && (this->format != FormatMultiLine)) {
    return 0;
  }
  if (iVar1 == 8) {
    return 1;
  }
  *(undefined4 *)((int)aiStack_10 + (iVar3 - iVar4) + 4) = 0x476493;
  TEditPanel::update_text(this);
  puVar6 = (undefined1 *)((int)aiStack_8 + (iVar3 - iVar4));
  if (this->sel_len == 0) {
    if (this->fixed_len + -1 <= this->text_len) {
      *(undefined4 *)((int)aiStack_10 + (iVar3 - iVar4) + 4) = 0xffffffff;
      *(undefined4 *)((int)aiStack_10 + (iVar3 - iVar4)) = 0x4764b7;
      MessageBeep();
      return 0;
    }
    puVar6 = (undefined1 *)((int)aiStack_8 + (iVar3 - iVar4));
    if (this->fixed_len + -2 <= this->text_len) {
      *(int *)((int)aiStack_10 + (iVar3 - iVar4) + 4) = iVar1;
      puVar6 = (undefined1 *)((int)aiStack_10 + (iVar3 - iVar4));
      *(undefined4 *)((int)aiStack_10 + (iVar3 - iVar4)) = 0x4764dd;
      iVar4 = IsDBCSLeadByte();
      if (iVar4 != 0) {
        *(undefined4 *)(puVar6 + -4) = 0xffffffff;
        DAT_0086b244 = 1;
        *(undefined4 *)(puVar6 + -8) = 0x4764f3;
        MessageBeep();
        return 0;
      }
    }
  }
  switch(this->format) {
  default:
    goto switchD_00476509_caseD_0;
  case FormatNumber:
  case FormatInteger:
  case FormatUnsignedInt:
    *(undefined4 *)(puVar6 + -4) = 0x47655a;
    TEditPanel::update_text(this);
    if ((0x2f < iVar1) && (iVar1 < 0x3a)) {
      return 1;
    }
    if (((iVar1 == 0x2d) && (*this->text == '\0')) && (this->format != FormatUnsignedInt)) {
      return 1;
    }
    if (iVar1 != 0x2e) goto LAB_00476634;
    pcVar2 = this->text;
    *(undefined4 *)(puVar6 + -4) = 0x2e;
    *(char **)(puVar6 + -8) = pcVar2;
    *(undefined4 *)(puVar6 + -0xc) = 0x47659b;
    iVar4 = __mbschr();
    if (iVar4 == 0) goto LAB_00476634;
    bVar7 = this->format == FormatNumber;
    break;
  case FormatFile:
  case FormatFileNoExt:
    *(undefined4 *)(puVar6 + -4) = 0x4765c9;
    TEditPanel::update_text(this);
    if (iVar1 == 0x2e) {
      if (this->format == FormatFile) {
        pcVar2 = this->text;
        *(undefined4 *)(puVar6 + -4) = 0x2e;
        *(char **)(puVar6 + -8) = pcVar2;
        *(undefined4 *)(puVar6 + -0xc) = 0x4765e4;
        iVar4 = __mbschr();
        if (iVar4 == 0) {
          return 1;
        }
      }
      goto LAB_00476634;
    }
    if ((iVar1 == 0x5c) || (iVar1 == 0x3a)) goto LAB_00476634;
    goto LAB_00476611;
  case FormatPath:
    *(undefined4 *)(puVar6 + -4) = 0x476603;
    TEditPanel::update_text(this);
    if ((iVar1 == 0x3a) && (this->text_len != 1)) goto LAB_00476634;
LAB_00476611:
    if (((iVar1 != 0x2f) && (((iVar1 != 0x22 && (iVar1 != 0x2a)) && (iVar1 != 0x3f)))) &&
       (((iVar1 != 0x3e && (iVar1 != 0x3c)) && (iVar1 != 0x7c)))) {
      return 1;
    }
LAB_00476634:
    *(undefined4 *)(puVar6 + -4) = 0xffffffff;
    *(undefined4 *)(puVar6 + -8) = 0x47663c;
    MessageBeep();
    return 0;
  case FormatPercent:
    if (((this->text_len < 2) && (0x2f < iVar1)) && (iVar1 < 0x3a)) {
      return 1;
    }
    if ((this->text_len != 2) || (iVar1 != 0x30)) goto LAB_00476634;
    *(char **)(puVar6 + -4) = this->text;
    *(char **)(puVar6 + -8) = s_10;
    *(undefined4 *)(puVar6 + -0xc) = 0x47654c;
    iVar4 = __mbscmp();
    bVar7 = iVar4 == 0;
  }
  if (!bVar7) {
    *(undefined4 *)(puVar6 + -4) = 0xffffffff;
    *(undefined4 *)(puVar6 + -8) = 0x4765bb;
    MessageBeep();
    return 0;
  }
switchD_00476509_caseD_0:
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047664d
// Address: 0047664d
// XREFS: None
// [HELPER] s_pnl_edit__draw: "pnl_edit::draw"
void __fastcall FUN_0047664d(int *param_1,char param_2)
{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  uchar uVar6;
  int *piVar7;
  char cVar8;
  byte bVar9;
  undefined4 in_EAX;
  char *pcVar10;
  uchar *puVar11;
  int iVar12;
  void *pvVar13;
  undefined4 uVar14;
  int iVar15;
  int unaff_EBX;
  int iVar16;
  undefined4 unaff_EDI;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  *(char *)(unaff_EBX + 0x66) = *(char *)(unaff_EBX + 0x66) + param_2;
  *(char *)(unaff_EBX + 0x66) = *(char *)(unaff_EBX + 0x66) + param_2;
  *(char *)(unaff_EBX + 0x66) = *(char *)(unaff_EBX + 0x66) + param_2;
  cVar8 = (char)in_EAX;
  param_2 = param_2 + cVar8 * '\x02';
  pcVar10 = (char *)CONCAT22((short)((uint)in_EAX >> 0x10),
                             CONCAT11((char)((uint)in_EAX >> 8) + (char)((uint)(unaff_EBX + 1) >> 8)
                                      ,cVar8));
  *(char *)(unaff_EBX + 0x67) = *(char *)(unaff_EBX + 0x67) + cVar8;
  *pcVar10 = *pcVar10 + param_2;
  pcVar10[-0x6f6f6f70] = pcVar10[-0x6f6f6f70] + param_2;
  param_1[0xe] = 0;
  if (param_1[0x1c] == 0) {
    return;
  }
  iVar16 = *param_1;
  iStack_14 = iVar16;
  (**(code **)(iVar16 + 0x28))
            (0,unaff_EBX + 1,CONCAT22((short)((uint)unaff_EDI >> 0x10),(short)unaff_EDI + 1) + 8);
  if (((param_1[0x42] == 0) || (param_1[0x1b] == 0)) || (param_1[0x1e] == 0)) {
    piVar7 = (int *)param_1[0x10];
    if (piVar7 == (int *)0x0) {
      bVar9 = *(byte *)((int)param_1 + 0xef);
      goto LAB_00476722;
    }
    if ((param_1[0x54] < 2) || (7 < param_1[0x54])) {
      if (piVar7[0x21] == 0) {
        (**(code **)(*piVar7 + 0x34))(param_1 + 9);
      }
    }
    else {
      (**(code **)(*piVar7 + 0x3c))(param_1 + 9);
    }
  }
  else {
    bVar9 = GetNearestPaletteIndex(*(undefined4 *)(*(int *)param_1[8] + 8),param_1[0x49]);
LAB_00476722:
    TDrawArea::Clear((TDrawArea *)param_1[8],(tagRECT *)(param_1 + 9),(uint)bVar9);
  }
  if (param_1[0x54] == 0) goto LAB_004768c7;
  puVar11 = TDrawArea::Lock((TDrawArea *)param_1[8],s_pnl_edit__draw,1);
  if (puVar11 == (uchar *)0x0) goto switchD_0047675d_default;
  switch(param_1[0x54]) {
  case 1:
    TDrawArea::DrawRect((TDrawArea *)param_1[8],param_1[3],param_1[4],param_1[5] + -1 + param_1[3],
                        param_1[6] + -1 + param_1[4],(uchar)param_1[0x55]);
    break;
  case 2:
    uVar3 = (uchar)param_1[0x55];
    iVar12 = param_1[4];
    iVar15 = param_1[3];
    uVar1 = *(uchar *)((int)param_1 + 0x159);
    goto LAB_00476812;
  case 3:
    uVar3 = (uchar)param_1[0x55];
    iVar12 = param_1[4];
    iVar15 = param_1[3];
    uVar1 = *(uchar *)((int)param_1 + 0x155);
    uVar4 = (uchar)param_1[0x56];
    uVar5 = *(uchar *)((int)param_1 + 0x159);
    goto LAB_00476853;
  case 4:
    uVar3 = (uchar)param_1[0x55];
    iVar12 = param_1[4];
    uVar1 = *(uchar *)((int)param_1 + 0x155);
    uVar4 = *(uchar *)((int)param_1 + 0x156);
    iVar15 = param_1[3];
    uVar5 = *(uchar *)((int)param_1 + 0x157);
    uVar6 = (uchar)param_1[0x56];
    uVar2 = *(uchar *)((int)param_1 + 0x159);
    goto LAB_0047689f;
  case 5:
    uVar3 = *(uchar *)((int)param_1 + 0x159);
    iVar12 = param_1[4];
    iVar15 = param_1[3];
    uVar1 = (uchar)param_1[0x55];
LAB_00476812:
    TDrawArea::DrawBevel
              ((TDrawArea *)param_1[8],iVar15,iVar12,param_1[5] + -1 + iVar15,
               param_1[6] + -1 + iVar12,uVar1,uVar3);
    break;
  case 6:
    uVar3 = *(uchar *)((int)param_1 + 0x159);
    iVar12 = param_1[4];
    iVar15 = param_1[3];
    uVar1 = (uchar)param_1[0x56];
    uVar4 = *(uchar *)((int)param_1 + 0x155);
    uVar5 = (uchar)param_1[0x55];
LAB_00476853:
    TDrawArea::DrawBevel2
              ((TDrawArea *)param_1[8],iVar15,iVar12,param_1[5] + -1 + iVar15,
               param_1[6] + -1 + iVar12,uVar5,uVar4,uVar1,uVar3);
    break;
  case 7:
    uVar3 = *(uchar *)((int)param_1 + 0x159);
    iVar12 = param_1[4];
    uVar1 = (uchar)param_1[0x56];
    uVar4 = *(uchar *)((int)param_1 + 0x157);
    iVar15 = param_1[3];
    uVar5 = *(uchar *)((int)param_1 + 0x156);
    uVar6 = *(uchar *)((int)param_1 + 0x155);
    uVar2 = (uchar)param_1[0x55];
LAB_0047689f:
    TDrawArea::DrawBevel3
              ((TDrawArea *)param_1[8],iVar15,iVar12,param_1[5] + -1 + iVar15,
               param_1[6] + -1 + iVar12,uVar2,uVar6,uVar5,uVar4,uVar1,uVar3);
  }
switchD_0047675d_default:
  TDrawArea::Unlock((TDrawArea *)param_1[8],s_pnl_edit__draw);
LAB_004768c7:
  iVar12 = param_1[0x3d];
  if ((iVar12 != 0) && (param_1[0x1b] != 0)) {
    if (param_1[0x1e] == 0) {
      if (param_1[0x41] == 0) {
        ShowWindow(iVar12,0);
        param_1[0x41] = 1;
      }
      pvVar13 = TDrawArea::GetDc((TDrawArea *)param_1[8],s_pnl_edit__draw);
      if (pvVar13 != (void *)0x0) {
        SelectClipRgn(pvVar13,param_1[0x22]);
        uVar14 = SelectObject(pvVar13,param_1[0x4b]);
        SetBkMode(pvVar13,1);
        SetTextColor(pvVar13,param_1[0x46]);
        iStack_14 = param_1[0x4d] + -1;
        iStack_10 = param_1[0x4e] + 1;
        iStack_c = param_1[0x4f] + -1;
        iStack_8 = param_1[0x50] + 1;
        DrawTextExA(pvVar13,param_1[0x3f],0xffffffff,&iStack_14,param_1[0x51],0);
        SetTextColor(pvVar13,param_1[0x45]);
        DrawTextExA(pvVar13,param_1[0x3f],0xffffffff,param_1 + 0x4d,param_1[0x51],0);
        SelectObject(pvVar13,uVar14);
        SelectClipRgn(pvVar13,0);
        TDrawArea::ReleaseDc((TDrawArea *)param_1[8],s_pnl_edit__draw);
        iVar16 = iStack_18;
      }
    }
    else if (param_1[0x41] != 0) {
      ShowWindow(iVar12,5);
      InvalidateRect(param_1[0x3d],0,1);
      param_1[0x41] = 0;
      (**(code **)(iVar16 + 0x2c))();
      return;
    }
  }
  (**(code **)(iVar16 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_00477729
// Address: 00477729
// XREFS: None
// [HELPER] s_pnl_inp__draw: "pnl_inp::draw"
void __fastcall FUN_00477729(TTextPanel *param_1,undefined4 param_2)
{
  byte *pbVar1;
  char *pcVar2;
  byte bVar6;
  char *in_EAX;
  void *pvVar3;
  undefined4 uVar4;
  uchar *puVar5;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  byte bVar11;
  int unaff_EBX;
  int unaff_EBP;
  byte *unaff_ESI;
  int unaff_EDI;
  int iVar12;
  bool in_CF;
  byte in_PF;
  byte in_AF;
  bool in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  int iStack_110;
  tagRECT atStack_10c [16];
  uint uStack_4;
  byte *pbVar10;
  
  uStack_4 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
             (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
             (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1) |
             (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
             (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  bVar7 = (byte)param_1;
  if (in_CF || in_ZF) {
code_r0x00477776:
    param_1 = (TTextPanel *)CONCAT31((int3)((uint)param_1 >> 8),bVar7 + *unaff_ESI);
  }
  else {
    pbVar10 = (byte *)(unaff_EBP + -0x16ffb88a);
    bVar9 = *pbVar10;
    bVar6 = (byte)((uint)param_1 >> 8);
    *pbVar10 = *pbVar10 + bVar6;
    if (!CARRY1(bVar9,bVar6) && *pbVar10 != 0) {
      *(byte *)&param_1->_padding_ = (char)param_1->_padding_ + bVar6;
      if ((char)param_1->_padding_ == '\0') {
        pcVar2 = (char *)(unaff_EBP + 0x746a0047 + (int)unaff_ESI * 2);
        *pcVar2 = *pcVar2 + bVar7;
        bVar11 = (byte)((uint)param_2 >> 8);
        bVar9 = (byte)param_2;
        pbVar10 = (byte *)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(bVar11 + bVar6,bVar9));
        if (CARRY1(bVar11,bVar6)) {
          *(char *)(unaff_EBX + 0x72) = *(char *)(unaff_EBX + 0x72) + (char)in_EAX;
          iVar12 = param_1->_padding_;
          *(byte *)&param_1->_padding_ = (char)param_1->_padding_ + bVar9;
          if (!CARRY1((byte)iVar12,bVar9)) goto code_r0x004777ae;
          pbVar1 = pbVar10 + -0x6cffb88e;
          bVar6 = *pbVar1;
          *pbVar1 = *pbVar1 + bVar7;
          if (!CARRY1(bVar6,bVar7)) goto code_r0x004777ae;
          bVar6 = (byte)((uint)in_EAX >> 8);
          *(char *)(unaff_EDI + 0x78) = *(char *)(unaff_EDI + 0x78) + bVar6;
          unaff_ESI[0x76] = unaff_ESI[0x76] + bVar9;
          iVar12 = param_1->_padding_;
          *(byte *)&param_1->_padding_ = (char)param_1->_padding_ + bVar7;
          if ((!CARRY1((byte)iVar12,bVar7) && (char)param_1->_padding_ != '\0') ||
             (bVar9 = *pbVar10, *pbVar10 = *pbVar10 + bVar6, !CARRY1(bVar9,bVar6) && *pbVar10 != 0))
          goto code_r0x004777ae;
          *in_EAX = *in_EAX + (char)in_EAX;
          *(int *)unaff_ESI = (int)&param_1->_padding_ + *(int *)unaff_ESI;
          goto code_r0x00477776;
        }
      }
      else {
        *(byte *)&param_1->_padding_ = (byte)param_1->_padding_ | bVar7;
      }
    }
  }
  uVar8 = CONCAT31((int3)((uint)param_1 >> 8),(byte)param_1 | *unaff_ESI);
  param_1 = (TTextPanel *)(uVar8 | *(uint *)(unaff_ESI + uVar8));
code_r0x004777ae:
  TTextPanel::draw(param_1);
  if ((((param_1->_padding_ != 0) && (param_1->_padding_ != 0)) && (param_1->_padding_ != 0)) &&
     (((param_1->_padding_ != 0 && (param_1[1]._padding_ != 0)) &&
      ((param_1->top_line <= param_1->cur_line && (param_1->cur_line <= param_1->bot_line)))))) {
    atStack_10c[0].left = param_1->_padding_;
    (**(code **)(atStack_10c[0].left + 0x28))(0);
    pvVar3 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_pnl_inp__draw);
    if (pvVar3 != (void *)0x0) {
      uVar4 = SelectObject(pvVar3,param_1->font);
      TTextPanel::calc_line_pos
                (param_1,pvVar3,param_1->cur_line - param_1->top_line,param_1->cur_line,atStack_10c,
                 (long *)&stack0xfffffeec);
      SelectObject(pvVar3,uVar4);
      TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_pnl_inp__draw);
      puVar5 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_pnl_inp__draw,1);
      if (puVar5 != (uchar *)0x0) {
        pbVar10 = unaff_ESI + atStack_10c[0].left;
        iVar12 = (atStack_10c[0].bottom - atStack_10c[0].top) + 1;
        if ((int)pbVar10 < param_1->_padding_) {
          TDrawArea::DrawVertLine
                    ((TDrawArea *)param_1->_padding_,(long)pbVar10,atStack_10c[0].top,iVar12,
                     (uchar)param_1[1]._padding_);
          TDrawArea::DrawVertLine
                    ((TDrawArea *)param_1->_padding_,(long)(pbVar10 + 1),atStack_10c[0].top,iVar12,
                     (uchar)param_1[1]._padding_);
        }
        TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_pnl_inp__draw);
      }
    }
    (**(code **)(iStack_110 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004783cf
// Address: 004783cf
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Pnl_lst_cp: "C:\msdev\work\age1_x1\Pnl_lst.cpp"
int __fastcall
FUN_004783cf(TListPanel *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
            int param_6,int param_7,int param_8,int param_9,int param_10)
{
  char *pcVar1;
  short sVar2;
  char cVar5;
  int extraout_EAX;
  int iVar3;
  int in_EAX;
  ulong uVar4;
  char cVar6;
  char unaff_BH;
  TTextPanel *unaff_ESI;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  if (in_ZF || in_OF != in_SF) {
    switch(param_1) {
    default:
      unaff_ESI->spacer_size = 1;
      break;
    case (TListPanel *)0x3:
    case (TListPanel *)0x6:
      unaff_ESI->spacer_size = 2;
      break;
    case (TListPanel *)0x4:
    case (TListPanel *)0x7:
      unaff_ESI->spacer_size = 3;
    }
    TTextPanel::set_bevel_info
              (unaff_ESI,(int)param_1,param_5,param_6,param_7,param_8,param_9,param_10);
    iVar3 = unaff_ESI->border_size;
    if (iVar3 == 0) {
      unaff_ESI->border_size = 1;
      TTextPanel::calc_draw_info(unaff_ESI,1);
      iVar3 = extraout_EAX;
    }
    return iVar3;
  }
  pcVar1 = (char *)((int)&unaff_ESI[-1].font_wid + 3);
  *pcVar1 = *pcVar1 + unaff_BH;
  pcVar1 = (char *)((int)&unaff_ESI[-1].font_wid + 3);
  cVar5 = (char)((uint)in_EAX >> 8);
  *pcVar1 = *pcVar1 + cVar5;
  cVar6 = (char)((uint)param_2 >> 8);
  *(char *)(param_2 + -0x7d) = *(char *)(param_2 + -0x7d) + cVar6;
  pcVar1 = (char *)((int)&unaff_ESI[-1].font_wid + 3);
  *pcVar1 = *pcVar1 + unaff_BH;
  pcVar1 = (char *)((int)&unaff_ESI[-1].font_wid + 3);
  *pcVar1 = *pcVar1 + cVar5;
  *(char *)(param_2 + -0x7d) = *(char *)(param_2 + -0x7d) + cVar6;
  *(char *)(in_EAX + 0x56909090) = *(char *)(in_EAX + 0x56909090) + (char)param_2;
  TPanel::handle_idle((TPanel *)param_1);
  if (((param_1->mouse_scroll_up != 0) || (param_1->mouse_scroll_down != 0)) &&
     (uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_lst_cp,0x6c),
     param_1->mouse_scroll_interval <= uVar4 - param_1->mouse_scroll_last_time)) {
    param_1->mouse_scroll_last_time = uVar4;
    if (param_1->mouse_scroll_up != 0) {
      sVar2 = (short)param_1->_padding_;
      if ((short)param_1->_padding_ != sVar2) {
        TListPanel::scroll_cur_line(param_1,'\x01',sVar2,1);
      }
      TListPanel::scroll_cur_line(param_1,'\x03',0,1);
      return 0;
    }
    sVar2 = *(short *)((int)&param_1->_padding_ + 2);
    if ((short)param_1->_padding_ != sVar2) {
      TListPanel::scroll_cur_line(param_1,'\x01',sVar2,1);
    }
    TListPanel::scroll_cur_line(param_1,'\x02',0,1);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00478807
// Address: 00478807
// XREFS: None
undefined4 __fastcall FUN_00478807(TListPanel *param_1,int *param_2)
{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  char *pcVar5;
  int iVar6;
  undefined2 in_ES;
  
  *(undefined2 *)(unaff_EDI + -0x7887ffb9) = in_ES;
  pcVar5 = (char *)(unaff_EDI + -0x785fffb8 + in_EAX * 4);
  *pcVar5 = *pcVar5 + (char)((uint)param_2 >> 8);
  pcVar5 = (char *)(unaff_EDI + 0x49 + in_EAX * 4);
  *pcVar5 = *pcVar5 + (char)((uint)in_EAX >> 8);
  *(char *)(in_EAX + -0x79) = *(char *)(in_EAX + -0x79) + (char)param_2;
  pcVar5 = (char *)(unaff_EDI + 3);
  cVar1 = (char)in_EAX;
  *(char *)&param_1->_padding_ = (char)param_1->_padding_ + cVar1;
  *pcVar5 = cVar1;
  *pcVar5 = *pcVar5 + cVar1;
  *param_2 = *param_2 + in_EAX;
  iVar2 = toupper();
  iVar6 = 0;
  for (puVar4 = (undefined4 *)param_1->_padding_; puVar4 != (undefined4 *)0x0;
      puVar4 = (undefined4 *)puVar4[3]) {
    if (((short)param_1->_padding_ < iVar6) &&
       (iVar3 = toupper((int)*(char *)*puVar4,pcVar5), iVar3 == iVar2)) goto LAB_004788da;
    iVar6 = iVar6 + 1;
  }
  if (0 < (short)param_1->_padding_) {
    puVar4 = (undefined4 *)param_1->_padding_;
    iVar6 = 0;
    if (puVar4 != (undefined4 *)0x0) {
      while (iVar3 = toupper((int)*(char *)*puVar4,pcVar5), iVar3 != iVar2) {
        iVar6 = iVar6 + 1;
        if ((short)param_1->_padding_ <= iVar6) {
          return 0;
        }
        puVar4 = (undefined4 *)puVar4[3];
        if (puVar4 == (undefined4 *)0x0) {
          return 0;
        }
      }
LAB_004788da:
      TListPanel::scroll_cur_line(param_1,'\x01',(short)iVar6,1);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00478ebb
// Address: 00478ebb
// XREFS: None
void __fastcall
FUN_00478ebb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  char cVar1;
  char cVar2;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  cVar2 = (char)((uint)param_2 >> 8);
  cVar1 = *(char *)(unaff_ESI + -0x71b9ffb9);
  *(char *)(unaff_EDI + -0x72) = *(char *)(unaff_EDI + -0x72) + cVar2;
  *(char *)(unaff_EBX + -0x2dffb873) = *(char *)(unaff_EBX + -0x2dffb873) + cVar2;
  *(int *)(unaff_EBP + -0x6f6fffb9) = *(int *)(unaff_EBP + -0x6f6fffb9) + -1;
  *(undefined4 *)(CONCAT31((int3)((uint)param_1 >> 8),(char)param_1 - cVar1) + 0x19c) = param_5;
  return;
}

// --------------------------------------------------

// Function: FUN_0047ae22
// Address: 0047ae22
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Pnl_scbr_c: "C:\msdev\work\age1_x1\Pnl_scbr.cpp"
undefined4 __thiscall FUN_0047ae22(TScrollBarPanel *param_1,int param_2,int param_3)
{
  char *pcVar1;
  TPanel *pTVar2;
  int iVar3;
  ulong uVar4;
  char unaff_BL;
  
  cRam500047ae = cRam500047ae + unaff_BL;
  pcVar1 = (char *)((int)&param_1[-0x3f6eda]._padding_ + 1);
  *pcVar1 = *pcVar1 + unaff_BL;
  TPanel::capture_mouse((TPanel *)param_1);
  iVar3 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->up_rect);
  if (iVar3 == 0) {
    iVar3 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->down_rect);
    if (iVar3 == 0) {
      iVar3 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->tab_rect);
      if (iVar3 == 0) {
        iVar3 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->top_rect);
        if (iVar3 == 0) {
          iVar3 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->bottom_rect);
          if (iVar3 == 0) {
            param_1->item_down = '\0';
          }
          else {
            param_1->item_down = '\x05';
            param_1->item_is_down = 1;
            TScrollBarPanel::scroll(param_1,ActionNext,0);
          }
        }
        else {
          param_1->item_down = '\x04';
          param_1->item_is_down = 1;
          TScrollBarPanel::scroll(param_1,ActionPrior,0);
        }
      }
      else {
        param_1->item_down = '\x03';
        if (param_1->orientationValue == Horizontal) {
          param_1->tab_mouse_x = param_2 - param_1->tab_x;
        }
        else {
          param_1->tab_mouse_y = param_3 - param_1->tab_y;
        }
      }
    }
    else {
      param_1->item_down = '\x02';
      param_1->item_is_down = 1;
      TScrollBarPanel::scroll(param_1,ActionDown,0);
    }
  }
  else {
    param_1->item_down = '\x01';
    param_1->item_is_down = 1;
    TScrollBarPanel::scroll(param_1,ActionUp,0);
  }
  if (param_1->item_down != '\0') {
    pTVar2 = param_1->list_panel;
    if (((pTVar2 != (TPanel *)0x0) && (pTVar2->tab_stop != 0)) &&
       (pTVar2->parent_panel != (TPanel *)0x0)) {
      TPanel::set_curr_child(pTVar2->parent_panel,pTVar2);
    }
    param_1->item_x = param_2;
    param_1->item_y = param_3;
    param_1->item_mode = '\x01';
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_scbr_c,0x185);
    param_1->item_last_time = uVar4;
    (**(code **)(param_1->_padding_ + 0x20))(1);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047b3af
// Address: 0047b3af
// XREFS: None
undefined4 __fastcall FUN_0047b3af(int param_1,undefined4 param_2)
{
  char *pcVar1;
  int iVar2;
  int in_EAX;
  TPanel *this;
  char *unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  *(char *)(unaff_EDI + -0x4b) = *(char *)(unaff_EDI + -0x4b) + (char)param_1;
  pcVar1 = (char *)(param_1 + -0x4f55ffb9 + unaff_ESI * 4);
  *pcVar1 = *pcVar1 + (char)((uint)unaff_EBX >> 8);
  *unaff_EBX = *unaff_EBX + (char)((uint)param_2 >> 8);
  this = (TPanel *)CONCAT31((int3)((uint)param_1 >> 8),0x47);
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + (char)param_2;
  if (this->parent_panel != (TPanel *)0x0) {
    (**(code **)(this->parent_panel->_padding_ + 0xb4))(this,5,this[1].pnl_y,0);
  }
  TPanel::release_mouse(this);
  iVar2 = this->_padding_;
  *(undefined1 *)&this[1].bottom_panel = 0;
  *(undefined1 *)&this[1].tab_prev_panel = 0;
  this[1].node = (PanelNode *)0x0;
  (**(code **)(iVar2 + 0x20))(1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047b4bf
// Address: 0047b4bf
// XREFS: None
// [HELPER] s_pnl_scbr__draw: "pnl_scbr::draw"
void __fastcall FUN_0047b4bf(TScrollBarPanel *param_1,undefined4 param_2)
{
  undefined4 in_EAX;
  int iVar1;
  uchar *puVar2;
  int iVar3;
  undefined4 unaff_EBX;
  int unaff_EDI;
  
  iVar1 = CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(0x47,(char)in_EAX));
  *(char *)(iVar1 + -0x4c) = *(char *)(iVar1 + -0x4c) + (char)((uint)param_1 >> 8);
  *(char *)(iVar1 + -0x4c) = *(char *)(iVar1 + -0x4c) + (char)((uint)param_2 >> 8);
  *(char *)(iVar1 + -0x4c) = *(char *)(iVar1 + -0x4c) + (char)((uint)unaff_EBX >> 8);
  *(char *)(iVar1 + -0x6fffb84c) = *(char *)(iVar1 + -0x6fffb84c) + (char)in_EAX;
  if ((int *)param_1->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1->_padding_ + 0x3c))(&param_1->_padding_,unaff_EDI + 3);
  }
  iVar1 = param_1->_padding_;
  (**(code **)(iVar1 + 0x28))(0);
  puVar2 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_pnl_scbr__draw,1);
  if (puVar2 != (uchar *)0x0) {
    TScrollBarPanel::draw_back_pic(param_1);
    TScrollBarPanel::draw_border(param_1,0,1,(tagRECT *)&param_1->_padding_);
    if (((param_1->up_rect).top != (param_1->up_rect).bottom) &&
       ((param_1->up_rect).left != (param_1->up_rect).right)) {
      if ((param_1->item_down == '\x01') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic(param_1,param_1->up_frame,iVar3,&param_1->up_rect);
      if ((param_1->item_down == '\x01') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border(param_1,1,iVar3,&param_1->up_rect);
    }
    if (((param_1->down_rect).top != (param_1->down_rect).bottom) &&
       ((param_1->down_rect).left != (param_1->down_rect).right)) {
      if ((param_1->item_down == '\x02') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic(param_1,param_1->down_frame,iVar3,&param_1->down_rect);
      if ((param_1->item_down == '\x02') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border(param_1,1,iVar3,&param_1->down_rect);
    }
    TScrollBarPanel::draw_button_pic(param_1,param_1->tab_frame,0,&param_1->tab_rect);
    TScrollBarPanel::draw_border(param_1,1,0,&param_1->tab_rect);
    TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_pnl_scbr__draw);
  }
  (**(code **)(iVar1 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_0047cde3
// Address: 0047cde3
// XREFS: None
void FUN_0047cde3(void)
{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  char cVar4;
  char extraout_AH;
  int in_EAX;
  undefined4 uVar5;
  TPanel *this;
  char extraout_DL;
  int unaff_EDI;
  int in_stack_00000018;
  char *pcVar6;
  
  pcVar3 = (code *)swi(0x47);
  (*pcVar3)();
  *(char *)(in_EAX + -0x58ffb833) = *(char *)(in_EAX + -0x58ffb833) + extraout_DL;
  pcVar3 = (code *)swi(0x47);
  (*pcVar3)();
  *(char *)(in_EAX + -0x6cffb833) = *(char *)(in_EAX + -0x6cffb833) + (char)((uint)in_EAX >> 8);
  pcVar3 = (code *)swi(0x47);
  (*pcVar3)();
  *(char *)(unaff_EDI + -0x44ffb833) = *(char *)(unaff_EDI + -0x44ffb833) + extraout_AH;
  pcVar3 = (code *)swi(0x47);
  uVar5 = (*pcVar3)();
  *(char *)(in_EAX + 0x6a042444) = *(char *)(in_EAX + 0x6a042444) + (char)this;
  piVar1 = (int *)((int)&this[0x197].render_rect.right + 1);
  *piVar1 = (int)&this->_padding_ + *piVar1;
  cVar4 = (char)uVar5 + (char)((uint)this >> 8);
  pcVar6 = (char *)CONCAT31((int3)((uint)uVar5 >> 8),cVar4);
  *pcVar6 = *pcVar6 + cVar4;
  TPanel::set_active(this,in_stack_00000018);
  if ((this[1].parent_panel != (TPanel *)0x0) && (this[1].curr_child != (TPanel *)0x0)) {
    iVar2 = (this[1].curr_child)->_padding_;
    if (this->active != 0) {
      (**(code **)(iVar2 + 0x14))();
      return;
    }
    (**(code **)(iVar2 + 0x14))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047d0f9
// Address: 0047d0f9
// XREFS: None
undefined4 __fastcall
FUN_0047d0f9(undefined4 param_1,char param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8)
{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char in_AL;
  char cVar8;
  undefined4 uVar9;
  TTextPanel *this;
  TTextPanel *unaff_ESI;
  int unaff_EDI;
  byte *pbVar10;
  int iVar11;
  char in_AF;
  bool in_SF;
  uchar uVar12;
  
  if (in_SF) {
    TTextPanel::calc_draw_info(unaff_ESI,param_6);
    uVar9 = (**(code **)(unaff_ESI->_padding_ + 0x20))(1);
    return uVar9;
  }
  pbVar10 = (byte *)(unaff_EDI + 1);
  piVar4 = &unaff_ESI[-0x4b19f1]._padding_;
  *(char *)piVar4 = (char)*piVar4 + in_AL;
  iVar5 = *piVar4;
  iVar6 = *piVar4;
  iVar7 = *piVar4;
  *pbVar10 = *pbVar10 << 1 | (char)*pbVar10 < '\0';
  bVar2 = *pbVar10;
  *pbVar10 = *pbVar10 << 1 | (char)bVar2 < '\0';
  cVar8 = (char)unaff_ESI;
  *pbVar10 = *pbVar10 << 1 | (char)*pbVar10 < '\0';
  pbVar10 = (byte *)(unaff_EDI + 2);
  this = (TTextPanel *)
         CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11((char)((uint)param_1 >> 8) + cVar8,0xd0));
  bVar3 = *pbVar10;
  *pbVar10 = *pbVar10 << 1 | (char)bVar3 < '\0';
  iVar11 = unaff_EDI + 3;
  pcVar1 = (char *)(CONCAT31((int3)(CONCAT22((short)((uint)unaff_ESI >> 0x10),
                                             CONCAT11(((char)iVar5 < '\0') << 7 |
                                                      ((char)iVar6 == '\0') << 6 | in_AF << 4 |
                                                      ((POPCOUNT((char)iVar7) & 1U) == 0) << 2 | 2U
                                                      | (char)bVar2 < '\0',cVar8)) >> 8),
                             cVar8 << 1 | (char)bVar3 < '\0') + 0x56909090);
  *pcVar1 = *pcVar1 + param_2;
  switch(param_4) {
  case 0x21:
    uVar12 = '\x05';
    break;
  case 0x22:
    uVar12 = '\x04';
    break;
  case 0x23:
    TTextPanel::scroll(this,'\a',0,1);
    return 1;
  case 0x24:
    TTextPanel::scroll(this,'\x06',0,1);
    return 1;
  default:
    return 0;
  case 0x26:
    uVar12 = '\x03';
    goto LAB_0047d149;
  case 0x28:
    uVar12 = '\x02';
LAB_0047d149:
    TTextPanel::scroll(this,uVar12,0,1);
    piVar4 = (int *)this->_padding_;
    if (piVar4 == (int *)0x0) {
      return 1;
    }
    iVar5 = this->_padding_;
    goto joined_r0x0047d15c;
  }
  TTextPanel::scroll(this,uVar12,0,1);
  piVar4 = (int *)this->_padding_;
  if (piVar4 != (int *)0x0) {
    iVar5 = this->_padding_;
joined_r0x0047d15c:
    if (iVar5 != 0) {
      (**(code **)(*piVar4 + 0xac))(param_4,param_5,param_6,param_7,param_8,iVar11);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047d1df
// Address: 0047d1df
// XREFS: None
long __fastcall FUN_0047d1df(int param_1,int param_2,long param_3,ulong param_4,ulong param_5)
{
  uint uVar1;
  long lVar2;
  TTextPanel *this;
  int unaff_EBX;
  char *pcVar3;
  uint *unaff_EDI;
  uint *puVar4;
  TScrollBarPanel *unaff_retaddr;
  
  uVar1 = *unaff_EDI;
  *unaff_EDI = *unaff_EDI << 1 | (uint)((int)uVar1 < 0);
  this = (TTextPanel *)(param_1 << 7 | (uint)(CONCAT14((int)uVar1 < 0,param_1) >> 0x1a));
  *(char *)(param_2 + -0x27ffb82f) =
       *(char *)(param_2 + -0x27ffb82f) + (char)((uint)(param_1 << 7) >> 8);
  *unaff_EDI = *unaff_EDI << 1 | (uint)((int)*unaff_EDI < 0);
  pcVar3 = (char *)(unaff_EBX + 1);
  *unaff_EDI = *unaff_EDI << 1 | (uint)((int)*unaff_EDI < 0);
  puVar4 = (uint *)((int)unaff_EDI + 1);
  *pcVar3 = *pcVar3 + (char)((uint)pcVar3 >> 8);
  *puVar4 = *puVar4 << 1 | (uint)((int)*puVar4 < 0);
  if ((this->scbar_panel != (TScrollBarPanel *)0x0) && (unaff_retaddr == this->scbar_panel)) {
    switch(param_3) {
    case 0:
      TTextPanel::scroll(this,'\x03',0,1);
      return 1;
    case 1:
      TTextPanel::scroll(this,'\x02',0,1);
      return 1;
    case 2:
      TTextPanel::scroll(this,'\x05',0,1);
      return 1;
    case 3:
      TTextPanel::scroll(this,'\x04',0,1);
      return 1;
    case 4:
      TTextPanel::scroll(this,'\x01',(short)param_4,0);
      return 1;
    }
  }
  lVar2 = TPanel::action((TPanel *)this,(TPanel *)unaff_retaddr,param_3,param_4,param_5);
  return lVar2;
}

// --------------------------------------------------

// Function: FUN_0047d29f
// Address: 0047d29f
// XREFS: None
// [HELPER] s_pnl_txt__draw: "pnl_txt::draw"
void __fastcall FUN_0047d29f(TTextPanel *param_1,undefined4 param_2)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  char *in_EAX;
  void *pvVar7;
  undefined4 uVar8;
  byte bVar9;
  byte bVar10;
  short sVar11;
  int unaff_EBX;
  int iVar12;
  int iVar13;
  short sVar14;
  int unaff_EDI;
  byte *pbVar15;
  byte *unaff_retaddr;
  ulong uVar16;
  ulong uVar17;
  int iStack_4;
  
  pbVar15 = (byte *)(unaff_EDI + 1);
  bVar1 = *pbVar15;
  bVar10 = (byte)((uint)param_2 >> 8);
  *pbVar15 = *pbVar15 + bVar10;
  bVar9 = (byte)param_1;
  *pbVar15 = *pbVar15 << (bVar9 & 7) | *pbVar15 >> 8 - (bVar9 & 7);
  bVar4 = ((uint)param_1 & 0x1f) == 0;
  bVar2 = *pbVar15;
  iVar12 = unaff_EBX + -1;
  *pbVar15 = *pbVar15 << (bVar9 & 7) | *pbVar15 >> 8 - (bVar9 & 7);
  bVar5 = ((uint)param_1 & 0x1f) == 0;
  bVar3 = *pbVar15;
  *unaff_retaddr = *unaff_retaddr << (bVar9 & 7) | *unaff_retaddr >> 8 - (bVar9 & 7);
  bVar6 = ((uint)param_1 & 0x1f) == 0;
  if (bVar6 && (bVar5 && (bVar4 && CARRY1(bVar1,bVar10) || !bVar4 && (bVar2 & 1) != 0) ||
               !bVar5 && (bVar3 & 1) != 0) || !bVar6 && (*unaff_retaddr & 1) != 0) {
    pbVar15 = unaff_retaddr + 1;
    in_EAX[-0x6f6f6f70] = in_EAX[-0x6f6f6f70] + (char)param_2;
    sVar14 = 0;
    param_1->_padding_ = 0;
    if (((param_1->_padding_ != 0) && (param_1->_padding_ != 0)) && (param_1->_padding_ != 0)) {
      TTextPanel::draw_background(param_1);
      iVar13 = param_1->_padding_;
      (**(code **)(iVar13 + 0x28))(0,iVar12,pbVar15);
      pvVar7 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_pnl_txt__draw);
      if (pvVar7 != (void *)0x0) {
        SelectClipRgn(pvVar7,param_1->_padding_);
        uVar8 = SelectObject(pvVar7,param_1->font);
        SetBkMode(pvVar7,1);
        sVar11 = param_1->top_line;
        if (sVar11 <= param_1->bot_line) {
          do {
            if (((param_1->_padding_ == 0) || (param_1->_padding_ == 0)) &&
               (param_1->_padding_ == 0)) {
              uVar17 = param_1->text_color2;
              uVar16 = param_1->text_color1;
            }
            else {
              uVar17 = param_1->highlightTextColor2;
              uVar16 = param_1->highlightTextColor1;
            }
            TTextPanel::draw_line(param_1,pvVar7,sVar14,sVar11,uVar16,uVar17);
            sVar11 = sVar11 + 1;
            sVar14 = sVar14 + 1;
          } while (sVar11 <= param_1->bot_line);
        }
        SelectObject(pvVar7,uVar8);
        SelectClipRgn(pvVar7,0);
        TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_pnl_txt__draw);
        iVar13 = iStack_4;
      }
      TTextPanel::draw_border(param_1);
      (**(code **)(iVar13 + 0x2c))();
    }
    return;
  }
  *in_EAX = *in_EAX + (char)in_EAX;
  return;
}

// --------------------------------------------------

// Function: FUN_0047d735
// Address: 0047d735
// XREFS: None
void __fastcall
FUN_0047d735(TTextPanel *param_1,undefined4 param_2,void *param_3,short param_4,short param_5,
            undefined4 param_6,undefined4 param_7)
{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  Style SVar4;
  undefined4 in_EAX;
  undefined1 *puVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  byte bVar9;
  undefined4 unaff_EBX;
  int unaff_ESI;
  char *pcVar10;
  short sStack_20;
  short sStack_18;
  tagRECT tStack_10;
  
  bVar9 = (char)param_2 + (char)((uint)unaff_EBX >> 8);
  puVar5 = (undefined1 *)
           CONCAT22((short)((uint)in_EAX >> 0x10),
                    (ushort)(byte)((char)in_EAX + (char)((uint)in_EAX >> 8) * 'G'));
  *puVar5 = *puVar5;
  pcVar6 = (char *)(unaff_ESI + 0x47 + CONCAT31((int3)((uint)param_2 >> 8),bVar9) * 8);
  *pcVar6 = *pcVar6 + bVar9;
  pbVar1 = (byte *)((int)&param_1[-0x17826e]._padding_ + 2);
  bVar2 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar9;
  pcVar6 = (char *)(CONCAT31((int3)((uint)puVar5 >> 8),-CARRY1(bVar2,bVar9)) + -0x6f6f6f70);
  *pcVar6 = *pcVar6 + bVar9;
  sStack_20 = 0;
  sStack_18 = 0;
  pcVar6 = TTextPanel::get_text(param_1,(int)param_5);
  pcVar7 = TTextPanel::get_text2(param_1,(int)param_5);
  if (pcVar6 == (char *)0x0) {
    if (pcVar7 == (char *)0x0) {
      return;
    }
  }
  else {
    iVar8 = -1;
    pcVar10 = pcVar6;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar3 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar3 != '\0');
    sStack_20 = ~(ushort)iVar8 - 1;
  }
  if (pcVar7 != (char *)0x0) {
    iVar8 = -1;
    pcVar10 = pcVar7;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar3 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar3 != '\0');
    sStack_18 = ~(ushort)iVar8 - 1;
  }
  TTextPanel::calc_line_pos(param_1,param_3,param_4,param_5,&tStack_10,(long *)0x0);
  _param_5 = tStack_10.left;
  if ((param_1->horz_align != AlignCenter) && (param_1->horz_align != AlignWordwrap)) {
    _param_5 = tStack_10.left + 5;
  }
  iVar8 = param_1->second_column_pos + _param_5;
  if (param_1->clip_rgn2 != (void *)0x0) {
    SelectClipRgn(param_3,param_1->clip_rgn2);
  }
  SVar4 = param_1->text_style;
  if (SVar4 == NormalStyle) {
    SetTextColor(param_3,param_6);
  }
  else if (SVar4 == BeveledStyle) {
    SetTextColor(param_3,param_6);
    if (pcVar6 != (char *)0x0) {
      TextOutA(param_3,_param_5 + -1,tStack_10.top + 1,pcVar6,(int)sStack_20);
    }
    SetTextColor(param_3,param_7);
  }
  else {
    if (SVar4 != ChiseledStyle) goto LAB_0047d8dd;
    SetTextColor(param_3,param_7);
    if (pcVar6 != (char *)0x0) {
      TextOutA(param_3,_param_5 + -1,tStack_10.top + 1,pcVar6,(int)sStack_20);
    }
    SetTextColor(param_3,param_6);
  }
  if (pcVar6 != (char *)0x0) {
    TextOutA(param_3,_param_5,tStack_10.top,pcVar6,(int)sStack_20);
  }
LAB_0047d8dd:
  if (pcVar7 != (char *)0x0) {
    if (param_1->clip_rgn2 != (void *)0x0) {
      SelectClipRgn(param_3,param_1->_padding_);
    }
    SVar4 = param_1->text_style;
    if (SVar4 == NormalStyle) {
      SetTextColor(param_3,param_6);
      TextOutA(param_3,iVar8,tStack_10.top,pcVar7,(int)sStack_18);
    }
    else {
      if (SVar4 == BeveledStyle) {
        SetTextColor(param_3,param_6);
        TextOutA(param_3,iVar8 + -1,tStack_10.top + 1,pcVar7,(int)sStack_18);
        SetTextColor(param_3,param_7);
        TextOutA(param_3,iVar8,tStack_10.top,pcVar7,(int)sStack_18);
        return;
      }
      if (SVar4 == ChiseledStyle) {
        SetTextColor(param_3,param_7);
        TextOutA(param_3,iVar8 + -1,tStack_10.top + 1,pcVar7,(int)sStack_18);
        SetTextColor(param_3,param_6);
        TextOutA(param_3,iVar8,tStack_10.top,pcVar7,(int)sStack_18);
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: operator==
// Address: 0047e4b0
// XREFS: None
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
// XREFS: None
int __cdecl operator!=(XYZ *param_1,XYZ *param_2)
{
  if (((param_1->xValue == param_2->xValue) && (param_1->yValue == param_2->yValue)) &&
     (param_1->zValue == param_2->zValue)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: rdlg_list_compare
// Address: 0047eaa0
// XREFS: sort_list
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

// Function: RESFILE_open_new_resource_file
// Address: 0047ee90
// XREFS: setup
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
// XREFS: None
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
// XREFS: RESFILE_open_new_resource_file
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

// Function: RESFILE_close_new_resource_file
// Address: 0047f180
// XREFS: ~TRIBE_Game
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

// Function: RESFILE_locate_resource
// Address: 0047f230
// XREFS: RESFILE_load
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

// Function: RESFILE_load
// Address: 0047f320
// XREFS: RESFILE_Extract_to_File, ReadPalette, TShape, load, setup
// [HELPER] s_ERROR__res_read_bin__resource_ty: "ERROR: res_read_bin, resource type %4.4c , id %d, not found"
// [HELPER] s_Error__Out_of_memory_in_res_read: "Error: Out of memory in res_read_bin."
// [HELPER] s_Error__unable_to_read_resource: "Error: unable to read resource"
// [HELPER] s_RESOURCE_ERROR: "RESOURCE ERROR"
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

// Function: RESFILE_Extract_to_File
// Address: 0047f480
// XREFS: Load
// [HELPER] s__: "}"
// [HELPER] s_temp: "temp"
// [HELPER] s_w_: "w+"
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

// Function: RESFILE_Set_Missing_Flag
// Address: 0047f580
// XREFS: setup_cmd_options
void __cdecl RESFILE_Set_Missing_Flag(int param_1)
{
  DAT_0086b258 = param_1;
  return;
}

// --------------------------------------------------

// Function: RESFILE_Decommit_Mapped_Memory
// Address: 0047f590
// XREFS: ~TShape
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

// Function: RESFILE_build_res_file
// Address: 0047f5c0
// XREFS: setup
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

// Function: BUILDRES_get_files_resource_type
// Address: 0047fc50
// XREFS: RESFILE_build_res_file
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

// Function: rge_fake_open
// Address: 0047fd30
// XREFS: open_scenario
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

// Function: rge_open
// Address: 0047fd90
// XREFS: RGE_Game_Info, RGE_Scenario_File_Info, get_scenario_header, get_scenario_info, init, loadLearnInfo, loadUnitHistory, load_game, load_scenario, reload_scenarios
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

// Function: rge_open
// Address: 0047fe20
// XREFS: base_save, save, save_game, save_scenario, ~TribeInformationAIModule
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

// Function: rge_fake_close
// Address: 0047feb0
// XREFS: None
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

// Function: rge_close
// Address: 0047ff30
// XREFS: RGE_Game_Info, RGE_Scenario_File_Info, base_save, get_scenario_header, get_scenario_info, init, loadLearnInfo, loadUnitHistory, load_game, load_scenario, load_scenario1, load_scenario2 (... +11 more)
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

// Function: rge_read_uncompressed
// Address: 00480000
// XREFS: RGE_Scenario_File_Info, RGE_Scenario_Header, TRIBE_Scenario_Header, get_scenario_header, get_scenario_info, load_scenario, load_scenario3, load_scenario4, load_scenario5, load_scenario6, load_scenario7, load_scenario8 (... +1 more)
void __cdecl rge_read_uncompressed(int param_1,void *param_2,int param_3)
{
  if ((-1 < param_1) && (param_1 == DAT_0086b260)) {
    read(param_1,param_2,param_3);
    DAT_0086b27c = DAT_0086b27c - param_3;
  }
  return;
}

// --------------------------------------------------

// Function: rge_write_uncompressed
// Address: 00480040
// XREFS: save, save_scenario, write_scenario_header
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

// Function: rge_read
// Address: 00480080
// XREFS: BuildAIModule, ConstructionAIModule, DiplomacyAIModule, EmotionalAIModule, MainDecisionAIModule, RGE_Action_Attack, RGE_Action_Gather, RGE_Action_Missile, RGE_Action_Move_To, RGE_Active_Animated_Sprite, RGE_Active_Sprite, RGE_Campaign_Info (... +62 more)
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

// Function: rge_buffer_full
// Address: 00480290
// XREFS: rge_write
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

// Function: rge_write
// Address: 004802c0
// XREFS: Save, base_save, save, save2, save_game, save_map, save_scenario, scenario_postsave, scenario_save, ~TribeInformationAIModule
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

// Function: FUN_00482081
// Address: 00482081
// XREFS: None
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

// Function: FUN_004826b2
// Address: 004826b2
// XREFS: None
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
// XREFS: None
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

// Function: FUN_0048790a
// Address: 0048790a
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_land_initilization__r: "Random Map land initilization, rand: %d"
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

// Function: FUN_00488675
// Address: 00488675
// XREFS: None
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

// Function: FUN_0048a5e3
// Address: 0048a5e3
// XREFS: None
void __fastcall FUN_0048a5e3(int *param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_EAX;
  char *pcVar8;
  int *piVar9;
  int *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *(char *)(in_EAX + -0x5c) = *(char *)(in_EAX + -0x5c) + (char)param_2;
  cRama5630048 = cRama5630048 + (char)((uint)unaff_EBX >> 8);
  pcVar8 = (char *)(in_EAX + -3);
  *pcVar8 = *pcVar8 + (char)pcVar8;
  *param_1 = (int)(pcVar8 + *param_1);
  iVar1 = *unaff_EBX;
  iVar2 = *unaff_EBX;
  iVar3 = *unaff_EBX;
  iVar4 = *unaff_EBX;
  iVar5 = *unaff_EBX;
  iVar6 = *unaff_EBX;
  iVar7 = *unaff_EBX;
  piVar9 = (int *)CONCAT31((int3)((uint)param_1 >> 8),
                           (char)param_1 + *(char *)((int)unaff_EBX + 0x48a57eff));
  *(char *)((int)unaff_EBX + -0x4cffb75b) =
       *(char *)((int)unaff_EBX + -0x4cffb75b) + (char)((uint)param_1 >> 8);
  *unaff_EDI = *unaff_ESI;
  *(char *)(unaff_EBP + -0x5a72ffb8) = *(char *)(unaff_EBP + -0x5a72ffb8) + (char)unaff_EBX;
  pcVar8 = pcVar8 + iVar7 + iVar6 + iVar5 + iVar4 + iVar3 + iVar2 + iVar1 + -2;
  unaff_EDI[1] = unaff_ESI[1];
  pcVar8 = (char *)(CONCAT22((short)((uint)pcVar8 >> 0x10),
                             CONCAT11((char)((uint)pcVar8 >> 8) + (char)param_2,(char)pcVar8)) + -1)
  ;
  *pcVar8 = *pcVar8 + (char)pcVar8;
  *param_2 = (int)(pcVar8 + *param_2);
  if (((piVar9[8] != 0) && (piVar9[0x1c] != 0)) && (piVar9[0x1b] != 0)) {
    iVar1 = *piVar9;
    (**(code **)(iVar1 + 0x28))(0,unaff_EDI + 2,unaff_ESI + 2);
    TDrawArea::Clear((TDrawArea *)piVar9[8],(tagRECT *)(piVar9 + 9),0);
    (**(code **)(iVar1 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048c33d
// Address: 0048c33d
// XREFS: None
void __fastcall FUN_0048c33d(undefined4 param_1,char param_2)
{
  int in_EAX;
  
  *(char *)(in_EAX + -1) = *(char *)(in_EAX + -1) + param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0048ce21
// Address: 0048ce21
// XREFS: None
undefined4 __fastcall FUN_0048ce21(undefined4 param_1,undefined2 param_2)
{
  char *pcVar1;
  undefined1 uVar2;
  code *pcVar3;
  int iVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  char extraout_DL;
  int unaff_EBP;
  undefined1 *unaff_EDI;
  undefined4 in_stack_00000010;
  
  uVar2 = in(param_2);
  *unaff_EDI = uVar2;
  pcVar3 = (code *)swi(0x48);
  (*pcVar3)();
  pcVar1 = (char *)(unaff_EBP + -0x3253ffb8 + extraout_ECX * 8);
  *pcVar1 = *pcVar1 + (char)extraout_ECX;
  pcVar3 = (code *)swi(0x48);
  (*pcVar3)();
  pcVar3 = (code *)swi(0x48);
  iVar4 = (*pcVar3)();
  *(char *)(iVar4 + -0x6f6f6f70) = *(char *)(iVar4 + -0x6f6f6f70) + extraout_DL;
  switch(in_stack_00000010) {
  case 0:
    return *(undefined4 *)(extraout_ECX_00 + 0x1014);
  case 1:
    return *(undefined4 *)(extraout_ECX_00 + 0x1018);
  case 2:
    return *(undefined4 *)(extraout_ECX_00 + 0x101c);
  case 3:
    return *(undefined4 *)(extraout_ECX_00 + 0x1020);
  case 4:
    return *(undefined4 *)(extraout_ECX_00 + 0x1024);
  default:
    return 0;
  }
}

// --------------------------------------------------

// Function: FUN_0048ce82
// Address: 0048ce82
// XREFS: None
RGE_Scenario_File_Info * __fastcall FUN_0048ce82(RGE_Scenario_File_Info *param_1,undefined4 param_2)
{
  long *plVar1;
  char cVar2;
  code *pcVar3;
  undefined4 in_EAX;
  int iVar4;
  RGE_Scenario_File_Entry *pRVar5;
  undefined4 uVar6;
  RGE_Scenario_File_Info *extraout_ECX;
  uint uVar7;
  uint uVar8;
  int unaff_EBX;
  int iVar9;
  int unaff_ESI;
  char *pcVar10;
  int iVar11;
  RGE_Scenario_File_Info *pRVar12;
  char in_OF;
  undefined8 uVar13;
  char *unaff_retaddr;
  
  uVar13 = CONCAT44(param_2,in_EAX);
  pcVar3 = (code *)swi(4);
  if (in_OF == '\x01') {
    uVar13 = (*pcVar3)();
    param_1 = extraout_ECX;
  }
  param_1[-1].filename[0xda] = param_1[-1].filename[0xda] + (char)unaff_EBX;
  pcVar10 = (char *)((int)((ulonglong)uVar13 >> 0x20) + -0x32);
  *pcVar10 = *pcVar10 + (char)((uint)((int)uVar13 + -2) >> 8);
  *(char *)(unaff_EBX + -0x32) = *(char *)(unaff_EBX + -0x32) + (char)((uint)param_1 >> 8);
  pcVar10 = (char *)(unaff_ESI + 0x48 + (int)param_1 * 8);
  *pcVar10 = *pcVar10 + (char)((ulonglong)uVar13 >> 0x28);
  pcVar10 = (char *)((int)uVar13 + -0x6f6f6f74);
  *pcVar10 = *pcVar10 + (char)((ulonglong)uVar13 >> 0x20);
  uVar7 = 0xffffffff;
  do {
    pcVar10 = unaff_retaddr;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar10 = unaff_retaddr + 1;
    cVar2 = *unaff_retaddr;
    unaff_retaddr = pcVar10;
  } while (cVar2 != '\0');
  uVar7 = ~uVar7;
  pcVar10 = pcVar10 + -uVar7;
  pRVar12 = param_1;
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pRVar12->filename = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pRVar12 = (RGE_Scenario_File_Info *)(pRVar12->filename + 4);
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    pRVar12->filename[0] = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pRVar12 = (RGE_Scenario_File_Info *)(pRVar12->filename + 1);
  }
  iVar4 = rge_open(param_1->filename,0x8000);
  if (iVar4 != -1) {
    plVar1 = &param_1->scenario_num;
    rge_read_uncompressed(iVar4,plVar1,4);
    iVar9 = 0;
    if (*plVar1 < 1) {
      param_1->scenarios = (RGE_Scenario_File_Entry *)0x0;
    }
    else {
      pRVar5 = (RGE_Scenario_File_Entry *)calloc(*plVar1,0x10c);
      param_1->scenarios = pRVar5;
      if (0 < *plVar1) {
        iVar11 = 0;
        do {
          rge_read_uncompressed(iVar4,param_1->scenarios->name + iVar11 + -8,4);
          rge_read_uncompressed(iVar4,param_1->scenarios->name + iVar11,0x104);
          uVar6 = (**(code **)(rge_base_game->_padding_ + 0x38))(iVar4);
          iVar9 = iVar9 + 1;
          *(undefined4 *)(param_1->scenarios->name + iVar11 + -4) = uVar6;
          iVar11 = iVar11 + 0x10c;
        } while (iVar9 < param_1->scenario_num);
        rge_close(iVar4);
        RGE_Scenario_File_Info::reload_scenarios(param_1);
        return param_1;
      }
    }
    rge_close(iVar4);
    RGE_Scenario_File_Info::reload_scenarios(param_1);
    return param_1;
  }
  param_1->scenario_num = 0;
  param_1->scenarios = (RGE_Scenario_File_Entry *)0x0;
  RGE_Scenario_File_Info::reload_scenarios(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048e1c6
// Address: 0048e1c6
// XREFS: None
void FUN_0048e1c6(void)
{
  undefined4 in_EAX;
  longlong *plVar1;
  int iVar2;
  undefined1 *unaff_ESI;
  float10 in_ST0;
  float10 in_ST1;
  
  plVar1 = (longlong *)CONCAT31((int3)((uint)in_EAX >> 8),*unaff_ESI);
  *plVar1 = (longlong)in_ST0;
  iVar2 = (int)plVar1 + -1;
  *(longlong *)CONCAT31((int3)((uint)iVar2 >> 8),(char)iVar2 * '\x02') = (longlong)in_ST1;
  return;
}

// --------------------------------------------------

// Function: FUN_0048f085
// Address: 0048f085
// XREFS: None
// [HELPER] s_scr_ach__draw: "scr_ach::draw"
void __fastcall FUN_0048f085(TScreenPanel *param_1,int param_2)
{
  code *pcVar1;
  TDrawArea *pTVar2;
  RGE_Game_World *pRVar3;
  TPanel *pTVar4;
  TShape *this;
  int in_EAX;
  uchar *puVar5;
  int iVar6;
  long lVar7;
  undefined4 unaff_EBX;
  undefined1 *puVar8;
  int unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 *puVar9;
  int iVar10;
  char *unaff_EDI;
  int aiStack_18 [6];
  
  unaff_EDI[0x48] = unaff_EDI[0x48] + (char)((uint)unaff_EBX >> 8);
  (&param_1->field_0x48)[unaff_EBP * 8] = (&param_1->field_0x48)[unaff_EBP * 8] + (char)param_2;
  unaff_EDI[-0x15] = unaff_EDI[-0x15] + (char)((uint)(in_EAX + -1) >> 8);
  *(char *)(param_2 + 0x6c0048ed) = *(char *)(param_2 + 0x6c0048ed) + (char)unaff_EBX;
  out((short)param_2,in_EAX + -2);
  *unaff_EDI = *unaff_EDI + (char)((uint)param_2 >> 8);
  out((short)param_2,in_EAX + -3);
  *(char *)(in_EAX + -0x6f6f6f74) = *(char *)(in_EAX + -0x6f6f6f74) + (char)param_2;
  *(char **)((int)aiStack_18 + unaff_EBP + 0xc) = unaff_EDI;
  *(undefined4 *)((int)aiStack_18 + unaff_EBP + 8) = 0x48f0bb;
  TScreenPanel::draw(param_1);
  if (*(int *)&param_1[1].field_0x4 < 5) {
    *(undefined4 *)((int)aiStack_18 + unaff_EBP + 8) = unaff_ESI;
    iVar10 = *(int *)param_1;
    *(undefined4 *)((int)aiStack_18 + unaff_EBP + 4) = 0;
    *(int *)((int)aiStack_18 + unaff_EBP + 0x14) = iVar10;
    pcVar1 = *(code **)(iVar10 + 0x28);
    puVar8 = (undefined1 *)((int)aiStack_18 + unaff_EBP);
    *(undefined4 *)((int)aiStack_18 + unaff_EBP) = 0x48f0d6;
    (*pcVar1)();
    if (*(int *)&param_1[1].field_0x178 != 0) {
      pTVar2 = *(TDrawArea **)&param_1->field_0x20;
      *(undefined4 *)(puVar8 + -4) = 1;
      *(char **)(puVar8 + -8) = s_scr_ach__draw;
      *(undefined4 *)(puVar8 + -0xc) = 0x48f0f3;
      puVar5 = TDrawArea::Lock(pTVar2,*(char **)(puVar8 + -8),*(int *)(puVar8 + -4));
      if (puVar5 != (uchar *)0x0) {
        *(undefined4 *)(puVar8 + -4) = unaff_EBX;
        pRVar3 = rge_base_game->world;
        iVar6 = pRVar3->player_num + -1;
        if (0 < iVar6) {
          *(int *)(puVar8 + -8) = unaff_EBP;
          puVar9 = (undefined4 *)&param_1[1].field_0x130;
          *(int *)(puVar8 + 8) = iVar6;
          do {
            if (*(char *)(*(int *)((int)pRVar3->players + (-0x5a4 - (int)param_1) + (int)puVar9) +
                         0x80) == '\x01') {
              pTVar4 = (TPanel *)*puVar9;
              *(undefined4 *)(puVar8 + -0xc) = 0;
              *(undefined4 *)(puVar8 + -0x10) = 0;
              *(undefined4 *)(puVar8 + -0x14) = 0;
              *(undefined4 *)(puVar8 + -0x18) = 0x48f140;
              lVar7 = TPanel::yPosition(pTVar4);
              pTVar4 = (TPanel *)*puVar9;
              *(long *)(puVar8 + -0x18) = lVar7;
              *(undefined4 *)(puVar8 + -0x1c) = 0x48f148;
              lVar7 = TPanel::xPosition(pTVar4);
              this = *(TShape **)&param_1[1].field_0x178;
              *(long *)(puVar8 + -0x1c) = lVar7 + -0x14;
              *(undefined4 *)(puVar8 + -0x20) = *(undefined4 *)&param_1->field_0x20;
              *(undefined4 *)(puVar8 + -0x24) = 0x48f15b;
              TShape::shape_draw(this,*(TDrawArea **)(puVar8 + -0x20),*(long *)(puVar8 + -0x1c),
                                 *(long *)(puVar8 + -0x18),*(long *)(puVar8 + -0x14),puVar8[-0x10],
                                 *(uchar **)(puVar8 + -0xc));
            }
            iVar10 = *(int *)(puVar8 + 8);
            puVar9 = puVar9 + 1;
            *(int *)(puVar8 + 8) = iVar10 + -1;
          } while (iVar10 + -1 != 0);
          iVar10 = *(int *)(puVar8 + 0xc);
        }
        pTVar2 = *(TDrawArea **)&param_1->field_0x20;
        *(char **)(puVar8 + -8) = s_scr_ach__draw;
        *(undefined4 *)(puVar8 + -0xc) = 0x48f17b;
        TDrawArea::Unlock(pTVar2,*(char **)(puVar8 + -8));
      }
    }
    pcVar1 = *(code **)(iVar10 + 0x2c);
    *(undefined4 *)(puVar8 + -4) = 0x48f181;
    (*pcVar1)();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00491c42
// Address: 00491c42
// XREFS: None
void FUN_00491c42(void)
{
  return;
}

// --------------------------------------------------

// Function: RGE_fade_palette_start
// Address: 00493420
// XREFS: handle_idle
// [HELPER] s_C__msdev_work_age1_x1_scr_cred_c: "C:\msdev\work\age1_x1\scr_cred.cpp"
void __cdecl
RGE_fade_palette_start
          (TDrawArea *param_1,tagPALETTEENTRY param_2,float param_3,uchar param_4,
          tagPALETTEENTRY *param_5,int param_6,int param_7)
{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  DAT_0086b2a8 = param_2;
  UNK_0086b28c._4_4_ = param_3;
  DAT_0086b2a4 = param_4;
  DAT_0086b298 = param_6;
  DAT_0086b29c = param_7;
  DAT_0086bab0 = param_1;
  iVar1 = 0;
  do {
    (&DAT_0086b2b0)[iVar1] = 0;
    (&DAT_0086b6b0)[iVar1] = 0;
    (&DAT_0086b2b2)[iVar1] = 0;
    (&DAT_0086b6b2)[iVar1] = 0;
    (&DAT_0086b2b1)[iVar1] = 0;
    (&DAT_0086b6b1)[iVar1] = 0;
    (&DAT_0086b2b3)[iVar1] = 0;
    (&DAT_0086b6b3)[iVar1] = 0;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x400);
  if (param_5 == (tagPALETTEENTRY *)0x0) {
    TDrawArea::GetPalette(param_1,(tagPALETTEENTRY *)&DAT_0086b2b0);
  }
  else {
    puVar4 = &DAT_0086b2b0;
    puVar2 = &param_5->peGreen;
    do {
      puVar3 = puVar2 + 4;
      *puVar4 = ((tagPALETTEENTRY *)(puVar2 + -1))->peRed;
      puVar3[0x86b2ad - (int)param_5] = puVar2[1];
      puVar3[(int)&DAT_0086b2ac - (int)param_5] = *puVar2;
      puVar3[0x86b2ae - (int)param_5] = puVar2[2];
      puVar4 = puVar4 + 4;
      puVar2 = puVar3;
    } while ((int)puVar4 < 0x86b6b0);
  }
  DAT_0086b294 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x2b5);
  DAT_0086b2ac = UNK_0086b28c._4_4_ * UNK_0086b28c._4_4_;
  DAT_0086b2a0 = -(uint)(DAT_0086b2a4 != '\x01') & 100;
  return;
}

// --------------------------------------------------

// Function: RGE_fade_palette_step
// Address: 00493540
// XREFS: handle_idle
// [HELPER] s_C__msdev_work_age1_x1_scr_cred_c: "C:\msdev\work\age1_x1\scr_cred.cpp"
int __cdecl RGE_fade_palette_step(void)
{
  float fVar1;
  ulong uVar2;
  float delta_time;
  uchar done;
  int local_4;
  
  local_4 = 0;
  if (DAT_0086b2a4 == '\x01') {
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x2c8);
    fVar1 = (float)(int)(uVar2 - DAT_0086b294) * _DAT_00572968;
    if (((UNK_0086b28c._4_4_ <= (float)_DAT_00572970) || (UNK_0086b28c._4_4_ < fVar1)) ||
       (fVar1 < _DAT_00572978)) {
      DAT_0086b2a0 = 100;
    }
    else {
      DAT_0086b2a0 = __ftol();
    }
    if (DAT_0086b2a0 < 100) goto LAB_00493687;
    DAT_0086b2a0 = 100;
  }
  else {
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x2dc);
    fVar1 = UNK_0086b28c._4_4_ - (float)(int)(uVar2 - DAT_0086b294) * _DAT_00572968;
    if (((UNK_0086b28c._4_4_ <= (float)_DAT_00572970) || (UNK_0086b28c._4_4_ < fVar1)) ||
       (fVar1 < _DAT_00572978)) {
      DAT_0086b2a0 = 0;
    }
    else {
      DAT_0086b2a0 = __ftol();
    }
    if (0 < DAT_0086b2a0) goto LAB_00493687;
    DAT_0086b2a0 = 0;
  }
  local_4 = 1;
LAB_00493687:
  RGE_translate_palette
            ((tagPALETTEENTRY *)&DAT_0086b2b0,(tagPALETTEENTRY *)&DAT_0086b6b0,DAT_0086b2a8,
             DAT_0086b2a0,DAT_0086b298,DAT_0086b29c);
  TDrawArea::SetPalette(DAT_0086bab0,(tagPALETTEENTRY *)&DAT_0086b6b0);
  return local_4;
}

// --------------------------------------------------

// Function: FUN_00498026
// Address: 00498026
// XREFS: None
undefined4 __fastcall FUN_00498026(uint *param_1,uint *param_2)
{
  byte *pbVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  uint in_EAX;
  undefined3 uVar11;
  undefined4 uVar8;
  int iVar9;
  byte bVar12;
  byte bVar13;
  char cVar14;
  char cVar18;
  byte *pbVar15;
  undefined2 uVar20;
  byte *pbVar16;
  byte *extraout_ECX;
  undefined3 uVar19;
  byte *pbVar17;
  TRIBE_Screen_Game *this;
  char cVar21;
  char cVar24;
  uint uVar22;
  char cVar25;
  char cVar26;
  char *unaff_EBX;
  byte *pbVar27;
  int unaff_EBP;
  char *unaff_ESI;
  char *pcVar28;
  byte *unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  bool in_CF;
  bool bVar29;
  bool bVar30;
  bool bVar31;
  undefined1 uVar32;
  undefined8 uVar33;
  char *unaff_retaddr;
  undefined2 auStack_4 [2];
  char *pcVar10;
  uint *puVar23;
  
  cVar25 = (char)in_EAX;
  bVar6 = (byte)unaff_EBX;
  if (!in_CF) {
    *(byte *)((int)param_2 + 0x76) = *(byte *)((int)param_2 + 0x76) + cVar25;
    *(byte *)(param_1 + 0x1d) = (char)param_1[0x1d] + bVar6;
    *(byte *)((int)param_2 + 0x76) =
         *(byte *)((int)param_2 + 0x76) + (char)((uint)((int)param_1 + -3) >> 8);
    puVar23 = param_1 + -1;
    pbVar15 = (byte *)(unaff_ESI + -0x3dffb68a);
    bVar5 = *pbVar15;
    bVar12 = (byte)param_2;
    *pbVar15 = *pbVar15 + bVar12;
    if (CARRY1(bVar5,bVar12) || *pbVar15 == 0) {
      *puVar23 = *puVar23 | (uint)puVar23;
      *puVar23 = *puVar23 | (uint)puVar23;
    }
    else {
      bVar5 = (byte)((uint)puVar23 >> 8);
      bVar13 = (byte)((uint)param_2 >> 8);
      cVar24 = bVar13 + bVar5;
      param_2 = (uint *)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(cVar24,bVar12));
      if (!CARRY1(bVar13,bVar5) && cVar24 != '\0') {
        uVar4 = *param_2;
        *(byte *)param_2 = (byte)*param_2 + bVar6;
        if (!CARRY1((byte)uVar4,bVar6) && (byte)*param_2 != 0) goto code_r0x00498090;
        unaff_ESI[0x77] = unaff_ESI[0x77] + cVar25;
        param_1 = (uint *)((int)param_1 + -5);
        *(char *)(unaff_EBP + 0x4977) = *(char *)(unaff_EBP + 0x4977) + cVar25;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 + in_EAX;
        *param_1 = *param_1 + in_EAX;
        *param_1 = *param_1 + in_EAX;
        *param_1 = *param_1 + in_EAX;
        *param_1 = *param_1 + in_EAX;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        goto code_r0x004980a1;
      }
    }
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
code_r0x00498090:
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *param_2 = *param_2 | in_EAX;
    uVar8 = (**(code **)(in_EAX + *(int *)(in_EAX + 0x8b080706) + -0x53ffb689))();
    return uVar8;
  }
code_r0x004980a1:
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  uVar11 = (undefined3)(in_EAX >> 8);
  bVar5 = cVar25 + *unaff_EBX + 5;
  pbVar17 = (byte *)CONCAT31(uVar11,bVar5);
  unaff_EBX[0x4977a8ff] = unaff_EBX[0x4977a8ff] | (byte)param_1;
  pbVar17[(int)unaff_EDI * 2 + 0x78560049] =
       pbVar17[(int)unaff_EDI * 2 + 0x78560049] + (char)((uint)param_1 >> 8);
  pbVar15 = (byte *)((int)param_1 + -1);
  uVar19 = (undefined3)((uint)unaff_EBX >> 8);
  cVar25 = bVar6 + bVar5;
  pbVar27 = (byte *)CONCAT31(uVar19,cVar25);
  auStack_4[0] = in_ES;
  if (CARRY1(bVar6,bVar5) || cVar25 == '\0') {
    bVar6 = (byte)((uint)unaff_EBX >> 8);
    *(char *)(unaff_EBP + 0x78) = *(char *)(unaff_EBP + 0x78) + bVar6;
    pbVar15 = (byte *)((int)param_1 + -2);
    cVar24 = bVar5 + bVar6;
    pbVar17 = (byte *)CONCAT31(uVar11,cVar24);
    if (!CARRY1(bVar5,bVar6) && cVar24 != '\0') {
      unaff_EDI = unaff_EDI + -1;
      if ((POPCOUNT((uint)unaff_EDI & 0xff) & 1U) != 0) {
        halt_baddata();
      }
      goto code_r0x00498123;
    }
    bVar5 = (byte)(in_EAX >> 8);
    bVar29 = CARRY1(*unaff_EDI,bVar5);
    *unaff_EDI = *unaff_EDI + bVar5;
    if (-1 < (char)*unaff_EDI) {
      bVar5 = cVar25 * '\x02';
      pbVar27 = (byte *)CONCAT31(uVar19,bVar5);
      bVar12 = (byte)pbVar15;
      uVar20 = (undefined2)((uint)pbVar15 >> 0x10);
      bVar13 = (byte)((uint)pbVar15 >> 8);
      if ((char)bVar5 < '\0') {
        unaff_EDI = *(byte **)(pbVar27 + 0x49);
        bVar6 = (byte)((uint)param_2 >> 8);
        bVar5 = CARRY1(bVar13,bVar6);
        cVar25 = bVar13 + bVar6;
        pbVar15 = (byte *)CONCAT22(uVar20,CONCAT11(cVar25,bVar12));
        uVar32 = (POPCOUNT(cVar25) & 1U) == 0;
        goto code_r0x0049812d;
      }
      cVar25 = bVar13 + bVar6;
      pbVar15 = (byte *)CONCAT22(uVar20,CONCAT11(cVar25,bVar12));
      uVar32 = (POPCOUNT(cVar25) & 1U) == 0;
      if (cVar25 != '\0' && SCARRY1(bVar13,bVar6) == cVar25 < '\0') {
        bVar5 = !CARRY1(bVar13,bVar6);
        goto code_r0x0049812d;
      }
      *pbVar17 = *pbVar17 + cVar24;
      *pbVar17 = *pbVar17 + cVar24;
      *pbVar17 = *pbVar17 + cVar24;
      *pbVar17 = *pbVar17 + cVar24;
      *pbVar17 = *pbVar17 + cVar24;
      *pbVar17 = *pbVar17 + bVar12;
      *pbVar17 = *pbVar17 | bVar12;
      *pbVar17 = *pbVar17 | bVar12;
      *pbVar17 = *pbVar17 | bVar12;
      *(byte **)pbVar17 = pbVar15 + *(int *)pbVar17;
      bVar12 = bVar12 + *pbVar17;
      *pbVar17 = *pbVar17 | bVar12;
      *pbVar17 = *pbVar17 | bVar12;
      pbVar15 = (byte *)(CONCAT31((int3)((uint)pbVar15 >> 8),bVar12) + *(int *)pbVar17);
      bVar6 = (byte)pbVar15;
      *pbVar17 = *pbVar17 | bVar6;
      *pbVar17 = *pbVar17 | bVar6;
      pbVar17 = (byte *)CONCAT31(uVar11,cVar24 + 5U);
      *pbVar17 = *pbVar17 | bVar6;
      *pbVar17 = *pbVar17 | bVar6;
      *pbVar17 = *pbVar17 | bVar6;
      bVar6 = (byte)((uint)pbVar15 >> 8);
      bVar30 = CARRY1((byte)param_2,bVar6);
      cVar25 = (byte)param_2 + bVar6;
      param_2 = (uint *)CONCAT31((int3)((uint)param_2 >> 8),cVar25);
      bVar29 = (POPCOUNT(cVar25) & 1U) == 0;
      if (bVar29) {
        unaff_ESI = unaff_retaddr;
        pcVar28 = unaff_retaddr;
        if (!bVar29) {
code_r0x00498163:
          pcVar28[0x7a] = pcVar28[0x7a] + (char)((uint)pbVar15 >> 8);
          pbVar15 = pbVar15 + -1;
          goto code_r0x00498167;
        }
        goto code_r0x004981ac;
      }
      bVar6 = *pbVar15;
      *pbVar15 = *pbVar15 + bVar5;
      bVar29 = (POPCOUNT(*pbVar15) & 1U) == 0;
      if (bVar29) goto code_r0x0049811b;
      pcVar28 = unaff_ESI + 1;
      out(*unaff_ESI,(short)param_2);
      if (bVar29) {
        bVar29 = (byte)(cVar24 + 5U) < 6 || (byte)(cVar24 - 1U) < CARRY1(bVar6,bVar5);
        pbVar17 = (byte *)CONCAT31(uVar11,(cVar24 - 1U) - CARRY1(bVar6,bVar5));
        unaff_ESI = pcVar28;
        goto code_r0x004981a1;
      }
code_r0x00498167:
      pcVar28[0x7a] = pcVar28[0x7a] + (char)((uint)pbVar27 >> 8);
      pbVar15 = pbVar15 + -1;
      pbVar16 = (byte *)(pcVar28 + -0x61ffb686);
      bVar6 = *pbVar16;
      bVar12 = (byte)pbVar15;
      *pbVar16 = *pbVar16 + bVar12;
      bVar13 = (byte)param_2;
      unaff_ESI = pcVar28;
      if ((POPCOUNT(*pbVar16) & 1U) == 0) {
        bVar29 = CARRY1(*pbVar15,bVar13) || CARRY1(*pbVar15 + bVar13,CARRY1(bVar6,bVar12));
        *pbVar15 = *pbVar15 + bVar13 + CARRY1(bVar6,bVar12);
        goto code_r0x004981a1;
      }
      pbVar16 = (byte *)(pcVar28 + -0x41ffb686);
      bVar6 = *pbVar16;
      bVar5 = (byte)((uint)pbVar15 >> 8);
      *pbVar16 = *pbVar16 + bVar5;
      if ((POPCOUNT(*pbVar16) & 1U) != 0) {
        bVar6 = (byte)((uint)param_2 >> 8);
        bVar5 = CARRY1(bVar6,bVar12);
        cVar25 = bVar6 + bVar12;
        uVar32 = (POPCOUNT(cVar25) & 1U) == 0;
        uVar33 = CONCAT44(CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(cVar25,bVar13)),pbVar17);
        goto code_r0x0049817d;
      }
      bVar12 = (byte)pbVar17 - 0x1c;
      bVar29 = (byte)pbVar17 < 0x1c || bVar12 < CARRY1(bVar6,bVar5);
      bVar12 = bVar12 - CARRY1(bVar6,bVar5);
      bVar6 = bVar12 - 0x1c;
      bVar5 = bVar12 < 0x1c || bVar6 < bVar29;
      uVar33 = CONCAT44(param_2,CONCAT31((int3)((uint)pbVar17 >> 8),bVar6 - bVar29));
      goto code_r0x004981c8;
    }
    if ((POPCOUNT(*unaff_EDI) & 1U) == 0) goto code_r0x00498126;
code_r0x004981a1:
    bVar6 = (byte)pbVar17 - 0x1c;
    bVar30 = (byte)pbVar17 < 0x1c || bVar6 < bVar29;
    bVar6 = bVar6 - bVar29;
    bVar5 = bVar6 - 0x1c;
    bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
    bVar5 = bVar5 - bVar30;
    bVar6 = bVar5 - 0x1c;
    iVar9 = CONCAT31((int3)((uint)pbVar17 >> 8),
                     ((bVar6 - bVar29) + -0x1c) - (bVar5 < 0x1c || bVar6 < bVar29));
    *param_2 = *param_2 + iVar9;
    pbVar27 = pbVar27 + *(int *)(&stack0x00000000 + iVar9);
    bVar6 = (byte)pbVar27;
    *(byte *)((int)pbVar15 * 2) = *(byte *)((int)pbVar15 * 2) | bVar6;
    pbVar15 = (byte *)CONCAT31((int3)((uint)pbVar15 >> 8),(byte)pbVar15 | *pbVar27);
    bVar12 = (byte)(iVar9 + 0x7061c1c) | 0xd;
    auStack_4[0] = in_CS;
    bVar29 = CARRY1(bVar6,*(byte *)((int)auStack_4 + (int)pbVar27));
    bVar6 = bVar6 + *(byte *)((int)auStack_4 + (int)pbVar27);
    pbVar27 = (byte *)CONCAT31((int3)((uint)pbVar27 >> 8),bVar6);
    bVar5 = bVar12 - 0x1c;
    bVar30 = bVar12 < 0x1c || bVar5 < bVar29;
    uVar11 = (undefined3)((uint)(iVar9 + 0x7061c1c) >> 8);
    bVar5 = bVar5 - bVar29;
    bVar12 = bVar5 - 0x1c;
    bVar29 = bVar5 < 0x1c || bVar12 < bVar30;
    bVar12 = bVar12 - bVar30;
    bVar5 = bVar12 - 0x1c;
    bVar30 = bVar12 < 0x1c || bVar5 < bVar29;
    bVar5 = bVar5 - bVar29;
    bVar12 = bVar5 - 0x1c;
    bVar29 = bVar5 < 0x1c || bVar12 < bVar30;
    bVar12 = bVar12 - bVar30;
    bVar5 = bVar12 - 0x1c;
    bVar30 = bVar12 < 0x1c || bVar5 < bVar29;
    bVar5 = bVar5 - bVar29;
    bVar12 = bVar5 - 0x1c;
    bVar29 = bVar5 < 0x1c || bVar12 < bVar30;
    bVar12 = bVar12 - bVar30;
    bVar5 = bVar12 - 0x1c;
    bVar30 = bVar12 < 0x1c || bVar5 < bVar29;
    bVar5 = bVar5 - bVar29;
    bVar12 = bVar5 - 0x1c;
    bVar29 = bVar5 < 0x1c || bVar12 < bVar30;
    bVar12 = bVar12 - bVar30;
    bVar5 = bVar12 - 0x1c;
    bVar30 = bVar12 < 0x1c || bVar5 < bVar29;
    bVar5 = bVar5 - bVar29;
    bVar12 = bVar5 - 0x13;
    bVar29 = bVar5 < 0x13 || bVar12 < bVar30;
    bVar12 = bVar12 - bVar30;
    bVar5 = bVar12 + 0x15;
    bVar30 = 0xea < bVar12 || CARRY1(bVar5,bVar29);
    cVar25 = bVar5 + bVar29;
    bVar29 = *pbVar15 < bVar6 || (byte)(*pbVar15 - bVar6) < bVar30;
    *pbVar15 = (*pbVar15 - bVar6) - bVar30;
    pcVar28 = unaff_ESI;
  }
  else {
    *(uint *)(pbVar27 + 0x49) =
         (*(int *)(pbVar27 + 0x49) - (int)unaff_EDI) - (uint)CARRY1(bVar6,bVar5);
code_r0x0049811b:
    pbVar27[(int)unaff_EDI * 2] = pbVar27[(int)unaff_EDI * 2] + (char)((uint)param_2 >> 8);
    unaff_EDI[0x7b] = unaff_EDI[0x7b] + (char)pbVar15 + -1;
    pbVar15 = pbVar15 + -2;
code_r0x00498123:
    pbVar27[0x7b] = pbVar27[0x7b] + (char)((uint)pbVar27 >> 8);
code_r0x00498126:
    pbVar15 = pbVar15 + -1;
    pbVar16 = pbVar27 + -0xaffb685;
    bVar5 = CARRY1(*pbVar16,(byte)pbVar15);
    *pbVar16 = *pbVar16 + (byte)pbVar15;
    uVar32 = (POPCOUNT(*pbVar16) & 1U) == 0;
code_r0x0049812d:
    uVar33 = CONCAT44(param_2,pbVar17);
    if ((bool)uVar32) {
      bVar12 = (byte)pbVar27;
      bVar5 = CARRY1(*pbVar17,bVar12);
      bVar6 = *pbVar17;
      *pbVar17 = *pbVar17 + bVar12;
      uVar32 = (POPCOUNT(*pbVar17) & 1U) == 0;
      if (SCARRY1(bVar6,bVar12) != (char)*pbVar17 < '\0') {
        pcVar3 = (code *)swi(4);
        uVar33 = CONCAT44(param_2,pbVar17);
        if (SCARRY1(bVar6,bVar12)) {
          uVar33 = (*pcVar3)();
          pbVar15 = extraout_ECX;
        }
        goto code_r0x0049817d;
      }
      bVar6 = *pbVar15;
      cVar25 = (char)((uint)pbVar27 >> 8);
      *pbVar15 = *pbVar15 + cVar25;
      if (SCARRY1(bVar6,cVar25) == (char)*pbVar15 < '\0') {
        bVar5 = (byte)param_2;
        *(byte *)(param_2 + 0x1f) = (byte)param_2[0x1f] + bVar5;
        pbVar16 = pbVar15 + -1;
        puVar23 = param_2 + -0x12bfeda1;
        bVar29 = CARRY1((byte)*puVar23,bVar12);
        uVar4 = *puVar23;
        *(byte *)puVar23 = (byte)*puVar23 + bVar12;
        bVar6 = (byte)pbVar17;
        if (SCARRY1((byte)uVar4,bVar12) == (char)(byte)*puVar23 < '\0') {
          bVar13 = (byte)pbVar16;
          bVar29 = CARRY1(bVar13,bVar6);
          pbVar16 = (byte *)CONCAT31((int3)((uint)pbVar16 >> 8),bVar13 + bVar6);
          if (SCARRY1(bVar13,bVar6) != (char)(bVar13 + bVar6) < '\0') goto code_r0x00498190;
          bVar29 = CARRY1(*unaff_EDI,bVar5);
          bVar6 = *unaff_EDI;
          *unaff_EDI = *unaff_EDI + bVar5;
          pbVar15 = pbVar16;
          if (SCARRY1(bVar6,bVar5) == (char)*unaff_EDI < '\0') goto code_r0x00498194;
          pbVar17[0x7d] = pbVar17[0x7d] + (char)((uint)pbVar17 >> 8);
          *(byte *)((int)param_2 + 0x7d) = *(byte *)((int)param_2 + 0x7d) + cVar25;
          pbVar15 = pbVar16 + -2;
          pbVar1 = unaff_EDI + -0x3affb683;
          bVar29 = CARRY1(*pbVar1,bVar12);
          bVar6 = *pbVar1;
          *pbVar1 = *pbVar1 + bVar12;
          if (SCARRY1(bVar6,bVar12) != (char)*pbVar1 < '\0') {
            unaff_EDI[0x7a] = unaff_EDI[0x7a] + (char)pbVar15;
            unaff_ESI[0x7a] = unaff_ESI[0x7a] + bVar12;
            pbVar15 = pbVar16 + -4;
            pcVar28 = unaff_ESI;
            goto code_r0x00498163;
          }
        }
        else {
          bVar30 = bVar6 < 0x1c || (byte)(bVar6 - 0x1c) < bVar29;
          bVar5 = (bVar6 - 0x1c) - bVar29;
          bVar6 = bVar5 - 0x1c;
          bVar29 = bVar5 < 0x1c || bVar6 < bVar30;
          pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),bVar6 - bVar30);
code_r0x00498190:
          bVar6 = (byte)pbVar17 - 0x1c;
          bVar30 = (byte)pbVar17 < 0x1c || bVar6 < bVar29;
          bVar6 = bVar6 - bVar29;
          bVar5 = bVar6 - 0x1c;
          bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
          pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),bVar5 - bVar30);
          pbVar15 = pbVar16;
code_r0x00498194:
          bVar6 = (byte)pbVar17 - 0x1c;
          bVar30 = (byte)pbVar17 < 0x1c || bVar6 < bVar29;
          bVar6 = bVar6 - bVar29;
          bVar5 = bVar6 - 0x1c;
          bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
          bVar5 = bVar5 - bVar30;
          bVar6 = bVar5 - 0x1c;
          bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
          bVar6 = bVar6 - bVar29;
          bVar5 = bVar6 - 0x1c;
          bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
          bVar5 = bVar5 - bVar30;
          bVar6 = bVar5 - 0x1c;
          bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
          bVar6 = bVar6 - bVar29;
          bVar5 = bVar6 - 0x1c;
          bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
          bVar5 = bVar5 - bVar30;
          bVar6 = bVar5 - 0x1c;
          bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
          bVar6 = bVar6 - bVar29;
          bVar5 = bVar6 - 0x1c;
          bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
          pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),bVar5 - bVar30);
        }
        bVar6 = (byte)pbVar17 - 0x1c;
        bVar30 = (byte)pbVar17 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar6 = ((bVar5 - bVar30) + -1) - (bVar6 < 0x1c || bVar5 < bVar30);
        bVar30 = CARRY1(bVar6,*pbVar27);
        pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),bVar6 + *pbVar27);
code_r0x004981ac:
        bVar6 = (byte)pbVar17 - 4;
        bVar29 = (byte)pbVar17 < 4 || bVar6 < bVar30;
        pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),bVar6 - bVar30);
        goto code_r0x004981a1;
      }
code_r0x0049817f:
      param_2 = (uint *)((ulonglong)uVar33 >> 0x20);
      pbVar17 = (byte *)uVar33;
      bVar6 = (byte)((uint)pbVar15 >> 8);
      bVar5 = (byte)((uint)pbVar27 >> 8);
      bVar30 = CARRY1(bVar6,bVar5);
      cVar25 = bVar6 + bVar5;
      pbVar15 = (byte *)CONCAT22((short)((uint)pbVar15 >> 0x10),CONCAT11(cVar25,(char)pbVar15));
      pcVar28 = unaff_ESI;
      if (cVar25 == '\0' || SCARRY1(bVar6,bVar5) != cVar25 < '\0') {
        bVar6 = *pbVar17;
        bVar5 = (byte)uVar33;
        *pbVar17 = *pbVar17 + bVar5;
        bVar29 = bVar5 < 0x1c || (byte)(bVar5 - 0x1c) < CARRY1(bVar6,bVar5);
        bVar5 = (bVar5 - 0x1c) - CARRY1(bVar6,bVar5);
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar31 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar29 = bVar5 < 0x1c || bVar6 < bVar31;
        pbVar17 = (byte *)CONCAT31((int3)((ulonglong)uVar33 >> 8),bVar6 - bVar31);
        goto code_r0x004981a1;
      }
    }
    else {
      unaff_ESI = (char *)0xce00497a;
code_r0x0049817d:
      pcVar28 = unaff_ESI;
      if (!(bool)uVar32) goto code_r0x0049817f;
code_r0x004981c8:
      bVar6 = (byte)uVar33 - 0x1c;
      bVar29 = (byte)uVar33 < 0x1c || bVar6 < bVar5;
      bVar6 = bVar6 - bVar5;
      bVar5 = bVar6 - 0x1c;
      bVar30 = bVar6 < 0x1c || bVar5 < bVar29;
      uVar33 = CONCAT44((int)((ulonglong)uVar33 >> 0x20),
                        CONCAT31((int3)((ulonglong)uVar33 >> 8),bVar5 - bVar29));
    }
    uVar22 = (uint)((ulonglong)uVar33 >> 0x20);
    bVar6 = (byte)uVar33 - 0x1c;
    bVar29 = (byte)uVar33 < 0x1c || bVar6 < bVar30;
    uVar11 = (undefined3)((ulonglong)uVar33 >> 8);
    bVar6 = bVar6 - bVar30;
    bVar5 = bVar6 - 0x1c;
    bVar30 = bVar6 < 0x1c || bVar5 < bVar29;
    bVar5 = bVar5 - bVar29;
    bVar6 = bVar5 - 0x1c;
    bVar29 = bVar5 < 0x1c || bVar6 < bVar30;
    bVar6 = bVar6 - bVar30;
    bVar5 = bVar6 - 0x1c;
    cVar25 = bVar5 - bVar29;
    uVar4 = (uint)(bVar6 < 0x1c || bVar5 < bVar29);
    uVar2 = uVar22 + *(uint *)(uVar22 + 0x19181716);
    bVar29 = CARRY4(uVar22,*(uint *)(uVar22 + 0x19181716)) || CARRY4(uVar2,uVar4);
    param_2 = (uint *)(uVar2 + uVar4);
  }
  cVar26 = ((char)pbVar27 - *pbVar27) - bVar29;
  bVar6 = (byte)pbVar15;
  *(int *)(pcVar28 + 0x49) = *(int *)(pcVar28 + 0x49) >> (bVar6 & 0x1f);
  uVar19 = (undefined3)((uint)pbVar15 >> 8);
  cVar24 = bVar6 + cVar26;
  pbVar17 = (byte *)CONCAT31(uVar19,cVar24);
  puVar23 = param_2;
  if (cVar24 != '\0' && SCARRY1(bVar6,cVar26) == cVar24 < '\0') {
code_r0x00498244:
    *puVar23 = *puVar23 | (uint)pbVar17;
    this = (TRIBE_Screen_Game *)((uint)pbVar17 | uRam9090900c);
    goto TRIBE_Screen_Game_char_action;
  }
  cVar14 = (char)param_2;
  cVar7 = cVar25 + cVar14;
  pcVar10 = (char *)CONCAT31(uVar11,cVar7);
  if (cVar7 != '\0' && SCARRY1(cVar25,cVar14) == cVar7 < '\0') goto code_r0x00498284;
  cVar25 = (char)uVar11;
  uVar11 = (undefined3)((uint)param_2 >> 8);
  cVar21 = cVar14 + cVar25;
  puVar23 = (uint *)CONCAT31(uVar11,cVar21);
  if (cVar21 != '\0' && SCARRY1(cVar14,cVar25) == cVar21 < '\0') goto code_r0x00498244;
  cVar18 = (char)((uint)pbVar15 >> 8);
  cVar14 = cVar24 + cVar18;
  pbVar17 = (byte *)CONCAT31(uVar19,cVar14);
  if (cVar14 == '\0' || SCARRY1(cVar24,cVar18) != cVar14 < '\0') {
    cVar24 = cVar21 + cVar7;
    if (cVar24 != '\0' && SCARRY1(cVar21,cVar7) == cVar24 < '\0') {
      cVar21 = cVar24 + cVar25;
      puVar23 = (uint *)CONCAT31(uVar11,cVar21);
      if (cVar21 == '\0' || SCARRY1(cVar24,cVar25) != cVar21 < '\0') goto code_r0x00498244;
      uVar4 = *puVar23;
      *(byte *)puVar23 = (byte)*puVar23 + cVar7;
      if ((((byte)*puVar23 == 0 || SCARRY1((byte)uVar4,cVar7) != (char)(byte)*puVar23 < '\0') &&
          (cVar24 = *pcVar28, *pcVar28 = *pcVar28 + cVar14,
          *pcVar28 == '\0' || SCARRY1(cVar24,cVar14) != *pcVar28 < '\0')) &&
         (bVar6 = *unaff_EDI, *unaff_EDI = *unaff_EDI + cVar25,
         *unaff_EDI == 0 || SCARRY1(bVar6,cVar25) != (char)*unaff_EDI < '\0')) {
        pcVar10[0x7f] = pcVar10[0x7f] + cVar7;
        pbVar17[0x7e] = pbVar17[0x7e] + cVar26;
        *(byte *)((int)puVar23 + 0x7f) = *(byte *)((int)puVar23 + 0x7f) + (char)((uint)param_2 >> 8)
        ;
        pbVar17 = pbVar17 + -3;
        cVar24 = (char)((uint)pbVar17 >> 8);
        cVar14 = (char)((uint)pbVar27 >> 8);
        cVar25 = cVar24 + cVar14;
        pbVar17 = (byte *)CONCAT22((short)((uint)pbVar17 >> 0x10),CONCAT11(cVar25,(char)pbVar17));
        if (cVar25 == '\0' || SCARRY1(cVar24,cVar14) != cVar25 < '\0') {
          *pcVar10 = *pcVar10 + cVar7;
        }
      }
      goto code_r0x00498284;
    }
  }
  else {
code_r0x00498284:
    *pbVar17 = *pbVar17 | (byte)pbVar17;
  }
  this = (TRIBE_Screen_Game *)
         CONCAT31((int3)((uint)pbVar17 >> 8),
                  (byte)pbVar17 | *(byte *)CONCAT31((int3)((uint)pbVar27 >> 8),cVar26));
TRIBE_Screen_Game_char_action:
  if (unaff_retaddr != (char *)0x2b) {
    if (unaff_retaddr == (char *)0x2d) {
      if (allow_user_commands == 0) {
        return 0;
      }
      TRIBE_Screen_Game::command_game_speed(this,0);
      return 0;
    }
    if (unaff_retaddr != (char *)0x3d) {
      return 0;
    }
  }
  if (allow_user_commands != 0) {
    TRIBE_Screen_Game::command_game_speed(this,1);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00498943
// Address: 00498943
// XREFS: None
void FUN_00498943(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004992c9
// Address: 004992c9
// XREFS: None
void __fastcall FUN_004992c9(undefined4 *param_1)
{
  TRIBE_Screen_Game *this;
  RGE_Static_Object *pRVar1;
  RGE_Static_Object *pRVar2;
  RGE_View *this_00;
  int iVar3;
  code *pcVar4;
  char cVar5;
  undefined4 in_EAX;
  RGE_Player *pRVar6;
  TButtonPanel *this_01;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  TRIBE_Screen_Game *unaff_ESI;
  undefined4 *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  char in_ZF;
  
  puRamd0004983 = unaff_EDI + 1;
  *unaff_EDI = in_EAX;
  this_01 = (TButtonPanel *)(*(int *)*param_1 + -1);
  if (this_01 == (TButtonPanel *)0x0 || in_ZF == '\0') {
    this = *(TRIBE_Screen_Game **)(*(int *)*param_1 + -2);
    puVar8 = (undefined1 *)0xd0004983;
    uRamd000497f = 0x4992ef;
    pTRamd0004987 = unaff_ESI;
    pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    pRVar1 = *(RGE_Static_Object **)((int)&this->game_obj + 3);
    pRVar2 = pRVar6->selected_obj;
    uRamd000497f = 0x49930f;
    pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    *(RGE_Static_Object **)((int)&this->game_obj + 3) = pRVar6->selected_obj;
    uRamd000497f = 0x499326;
    pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    *(short *)&this->field_0x5cc = pRVar6->sel_count;
    if (pRVar1 != pRVar2) {
      if (rge_base_game->game_mode == 0x15) {
        puVar8 = (undefined1 *)0xd000497f;
        uRamd000497f = 0x499355;
        (**(code **)(**(int **)((int)&this->main_view + 3) + 0xf0))();
        this_00 = *(RGE_View **)((int)&this->main_view + 3);
        *(undefined4 *)(puVar8 + -4) = 0xffffffff;
        *(undefined4 *)(puVar8 + -8) = 0xffffffff;
        *(undefined4 *)(puVar8 + -0xc) = 0xffffffff;
        *(undefined4 *)(puVar8 + -0x10) = 0xffffffff;
        *(undefined4 *)(puVar8 + -0x14) = 0x499368;
        RGE_View::set_selection_area
                  (this_00,*(long *)(puVar8 + -0x10),*(long *)(puVar8 + -0xc),*(long *)(puVar8 + -8)
                   ,*(long *)(puVar8 + -4));
      }
      cVar5 = (char)rge_base_game->game_mode;
      if (((((cVar5 != '\x01') && (cVar5 != '\x12')) && (cVar5 != '\x0e')) &&
          ((cVar5 != '\x02' && (cVar5 != '\x03')))) &&
         ((cVar5 != '\b' && ((cVar5 != '\t' && (cVar5 != '\n')))))) {
        iVar3 = rge_base_game->_padding_;
        *(undefined4 *)(puVar8 + -4) = 0;
        *(undefined4 *)(puVar8 + -8) = 0;
        pcVar4 = *(code **)(iVar3 + 0x10);
        puVar9 = (undefined4 *)(puVar8 + -0xc);
        puVar8 = puVar8 + -0xc;
        *puVar9 = 0x49939d;
        (*pcVar4)();
      }
    }
    *(undefined4 *)(puVar8 + -4) = 0x4993a4;
    TRIBE_Screen_Game::reset_buttons(this);
    return;
  }
  pTRamd0004987 = (TRIBE_Screen_Game *)0xffffff;
  puRamd0004983 = (undefined4 *)0x0;
  uRamd000497f = 0x499276;
  TButtonPanel::set_text_color(this_01,0,0xffffff,uRamd000498b);
  uRamd000498b = 0;
  pTRamd0004987 = (TRIBE_Screen_Game *)0xffffff;
  puRamd0004983 = (undefined4 *)0x0;
  uRamd000497f = 0x49928a;
  TButtonPanel::set_text_color(*(TButtonPanel **)((int)unaff_ESI->button_panel + 0x3f),0,0xffffff,0)
  ;
  uRamd000498b = 0;
  pTRamd0004987 = (TRIBE_Screen_Game *)0xffffff;
  puRamd0004983 = (undefined4 *)0x0;
  uRamd000497f = 0x49929e;
  TButtonPanel::set_text_color(*(TButtonPanel **)((int)unaff_ESI->button_panel + 0x43),0,0xffffff,0)
  ;
  uRamd000498b = 0x4992a5;
  TRIBE_Screen_Game::setup_buttons(unaff_ESI);
  uRamd000498b = 1;
  puVar7 = (undefined1 *)0xd0004987;
  pTRamd0004987 = (TRIBE_Screen_Game *)0x4992ae;
  (**(code **)(*(int *)unaff_ESI + 0x20))();
  *unaff_FS_OFFSET = *(undefined4 *)(puVar7 + 0x214);
  return;
}

// --------------------------------------------------

// Function: FUN_0049949d
// Address: 0049949d
// XREFS: None
void __fastcall
FUN_0049949d(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,byte *param_5)
{
  uint *puVar1;
  byte bVar2;
  undefined4 in_EAX;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int unaff_EDI;
  bool bVar6;
  
  puVar1 = (uint *)(param_1 * 3 + 0x49944c00);
  *puVar1 = *puVar1 ^ param_2;
  *(char *)(unaff_EDI + -0x6c) = *(char *)(unaff_EDI + -0x6c) + (char)((uint)in_EAX >> 8);
  *(char *)(param_2 + 0x53004994) = *(char *)(param_2 + 0x53004994) + (char)in_EAX;
  pbVar3 = (byte *)TTextPanel::get_text(*(TTextPanel **)(param_1 + 0x587));
  pbVar5 = param_5;
  if (pbVar3 != (byte *)0x0) {
    do {
      bVar2 = *pbVar3;
      bVar6 = bVar2 < *pbVar5;
      if (bVar2 != *pbVar5) {
LAB_004994f3:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_004994f8;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar6 = bVar2 < pbVar5[1];
      if (bVar2 != pbVar5[1]) goto LAB_004994f3;
      pbVar3 = pbVar3 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_004994f8:
    if (iVar4 == 0) {
      return;
    }
  }
  (**(code **)(**(int **)(param_1 + 0x587) + 0xe8))(param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0049ad3b
// Address: 0049ad3b
// XREFS: None
void __fastcall FUN_0049ad3b(int param_1,int param_2)
{
  uint *puVar1;
  TRIBE_Panel_Time *pTVar2;
  char cVar3;
  bool bVar4;
  uchar uVar5;
  undefined4 in_EAX;
  char *pcVar6;
  byte *pbVar7;
  int iVar8;
  int *piVar9;
  char cVar12;
  undefined4 unaff_EBX;
  int iVar11;
  int unaff_EBP;
  int iVar13;
  int unaff_ESI;
  undefined4 *puVar14;
  int iVar15;
  int iStack_50;
  undefined4 *puStack_4c;
  int aiStack_44 [17];
  char cVar10;
  
  puVar1 = (uint *)(param_1 * 3 + 0x49acd800);
  *puVar1 = *puVar1 >> 1;
  *(char *)(param_2 + -0x66ffb654) = *(char *)(param_2 + -0x66ffb654) + (char)param_2;
  cVar3 = (char)((uint)in_EAX >> 8);
  param_1 = param_1 + -1;
  iVar13 = CONCAT22((short)((uint)param_1 >> 0x10),
                    CONCAT11((char)((uint)param_1 >> 8) * '\x02',(char)param_1));
  pcVar6 = (char *)(CONCAT31((int3)((uint)in_EAX >> 8),*(undefined1 *)(unaff_ESI + 1)) + -0x58ffb654
                   );
  *pcVar6 = *pcVar6 + cVar3;
  *(char *)(unaff_ESI + -0x4affb651) =
       *(char *)(unaff_ESI + -0x4affb651) + (char)((uint)(iVar13 + -2) >> 8);
  cVar12 = (char)((uint)unaff_EBX >> 8);
  (&stack0xacc30049)[unaff_EBP * 4] = (&stack0xacc30049)[unaff_EBP * 4] + cVar12;
  cVar10 = (char)((uint)param_2 >> 8) + cVar3;
  piVar9 = (int *)CONCAT22((short)((uint)param_2 >> 0x10),
                           CONCAT11(cVar10,(char)param_2 + (char)param_1 + -4));
  pcVar6 = (char *)CONCAT31(CONCAT21((short)((uint)in_EAX >> 0x10),cVar3 + cVar10),
                            *(char *)(unaff_ESI + 7));
  *pcVar6 = *pcVar6 + *(char *)(unaff_ESI + 7);
  *piVar9 = (int)(pcVar6 + *piVar9);
  pbVar7 = (byte *)(iVar13 + -8 + *(int *)(unaff_ESI + 8));
  *pbVar7 = *pbVar7 | (byte)pbVar7;
  iVar8 = CONCAT31((int3)((uint)pbVar7 >> 8),
                   (byte)pbVar7 |
                   *(byte *)CONCAT22((short)((uint)unaff_EBX >> 0x10),
                                     CONCAT11(cVar12 + (char)unaff_EBX,(char)unaff_EBX)));
  iVar13 = *(int *)(*(int *)(iVar8 + 0x5b4) + 0x108);
  if (iVar13 == 2) {
    TRIBE_Panel_Time::set_clock_type(*(TRIBE_Panel_Time **)(iVar8 + 0x518),3,0);
    return;
  }
  if (iVar13 == 0) {
    iVar15 = 1;
    iVar13 = 0;
    if (1 < *(short *)(*(int *)(iVar8 + 0x5b4) + 0x3c)) {
      puStack_4c = (undefined4 *)(iVar8 + 0x518);
      iStack_50 = 4;
      do {
        RGE_Base_Game::get_countdown_timer(rge_base_game,iVar15,aiStack_44);
        if (0 < aiStack_44[0]) {
          iVar13 = iVar13 + 1;
          pTVar2 = (TRIBE_Panel_Time *)*puStack_4c;
          puStack_4c = puStack_4c + 1;
          TRIBE_Panel_Time::set_clock_type(pTVar2,4,iVar15);
          if (9 < iVar13) break;
        }
        iVar11 = *(int *)(*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iStack_50);
        if (*(int *)(iVar11 + 0x844) != -0x40800000) {
          bVar4 = false;
          if ((*(char *)(iVar11 + 0x104) != '\0') && (iVar11 = 1, 4 < iStack_50)) {
            do {
              uVar5 = RGE_Player::relation
                                (*(RGE_Player **)
                                  (*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iStack_50),iVar11);
              if ((uVar5 == '\0') &&
                 ((uVar5 = RGE_Player::relation
                                     (*(RGE_Player **)
                                       (*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iVar11 * 4),
                                      iVar15), uVar5 == '\0' &&
                  (*(char *)(*(int *)(*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iVar11 * 4) + 0x104
                            ) != '\0')))) {
                bVar4 = true;
                break;
              }
              iVar11 = iVar11 + 1;
            } while (iVar11 < iVar15);
          }
          if (!bVar4) {
            iVar13 = iVar13 + 1;
            pTVar2 = (TRIBE_Panel_Time *)*puStack_4c;
            puStack_4c = puStack_4c + 1;
            TRIBE_Panel_Time::set_clock_type(pTVar2,5,iVar15);
            if (9 < iVar13) break;
          }
        }
        iVar11 = *(int *)(*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iStack_50);
        if (*(int *)(iVar11 + 0x840) != -0x40800000) {
          bVar4 = false;
          if ((*(char *)(iVar11 + 0x104) != '\0') && (iVar11 = 1, 4 < iStack_50)) {
            do {
              uVar5 = RGE_Player::relation
                                (*(RGE_Player **)
                                  (*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iStack_50),iVar11);
              if ((uVar5 == '\0') &&
                 ((uVar5 = RGE_Player::relation
                                     (*(RGE_Player **)
                                       (*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iVar11 * 4),
                                      iVar15), uVar5 == '\0' &&
                  (*(char *)(*(int *)(*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iVar11 * 4) + 0x104
                            ) != '\0')))) {
                bVar4 = true;
                break;
              }
              iVar11 = iVar11 + 1;
            } while (iVar11 < iVar15);
          }
          if (!bVar4) {
            iVar13 = iVar13 + 1;
            pTVar2 = (TRIBE_Panel_Time *)*puStack_4c;
            puStack_4c = puStack_4c + 1;
            TRIBE_Panel_Time::set_clock_type(pTVar2,6,iVar15);
            if (9 < iVar13) break;
          }
        }
        iStack_50 = iStack_50 + 4;
        iVar15 = iVar15 + 1;
      } while (iVar15 < *(short *)(*(int *)(iVar8 + 0x5b4) + 0x3c));
    }
    if (iVar13 < 10) {
      puVar14 = (undefined4 *)(iVar8 + 0x518 + iVar13 * 4);
      iVar13 = 10 - iVar13;
      do {
        pTVar2 = (TRIBE_Panel_Time *)*puVar14;
        puVar14 = puVar14 + 1;
        TRIBE_Panel_Time::set_clock_type(pTVar2,0,0);
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: scr_game_score_compare
// Address: 0049b000
// XREFS: reset_score_display
int __cdecl scr_game_score_compare(void *param_1,void *param_2)
{
  UNK_0086bab9._3_4_ = param_2;
  UNK_0086bab9._7_4_ = param_1;
  if (*(int *)((int)param_1 + 0x10) < *(int *)((int)param_2 + 0x10)) {
    return 1;
  }
  if (*(int *)((int)param_2 + 0x10) < *(int *)((int)param_1 + 0x10)) {
    return -1;
  }
  if (*(int *)((int)param_1 + 8) < *(int *)((int)param_2 + 8)) {
    return 1;
  }
  if (*(int *)((int)param_2 + 8) < *(int *)((int)param_1 + 8)) {
    return -1;
  }
  if (*(int *)((int)param_1 + 0xc) < *(int *)((int)param_2 + 0xc)) {
    return 1;
  }
  if (*(int *)((int)param_2 + 0xc) < *(int *)((int)param_1 + 0xc)) {
    return -1;
  }
  if (*(int *)((int)param_1 + 4) < *(int *)((int)param_2 + 4)) {
    return 1;
  }
  return (*(int *)((int)param_1 + 4) <= *(int *)((int)param_2 + 4)) - 1;
}

// --------------------------------------------------

// Function: FUN_0049b536
// Address: 0049b536
// XREFS: None
// [HELPER] do_color_log: " "
// [HELPER] s_scr_game__draw2: "scr_game::draw2"
// [HELPER] s_scr_game__draw3: "scr_game::draw3"
// [HELPER] s_scr_game__draw: "scr_game::draw"
void __fastcall FUN_0049b536(undefined4 param_1,int param_2)
{
  tagRECT *ptVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  undefined4 in_EAX;
  uchar *puVar9;
  undefined4 uVar10;
  int *piVar11;
  undefined4 unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  TDrawArea *pTVar12;
  long lVar13;
  long lVar14;
  
  *(char *)(param_2 + -0x46ffb64d) = *(char *)(param_2 + -0x46ffb64d) + (char)((uint)param_2 >> 8);
  cVar8 = (char)in_EAX * '\x02';
  piVar11 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),
                            CONCAT11((char)((uint)param_1 >> 8) + (char)param_2,(char)param_1));
  pcVar2 = (char *)(CONCAT22((short)((uint)in_EAX >> 0x10),
                             CONCAT11((char)((uint)in_EAX >> 8) + 'I',cVar8)) + -0x6f6f6f70);
  *pcVar2 = *pcVar2 + (char)param_2;
  if (do_color_log != '\0') {
    ptVar1 = (tagRECT *)(piVar11 + 9);
    iVar3 = *piVar11;
    lVar14 = ptVar1->left;
    iVar4 = piVar11[10];
    iVar5 = piVar11[0xb];
    (**(code **)(iVar3 + 0x28))
              (0,CONCAT31(CONCAT21((short)((uint)unaff_EBX >> 0x10),
                                   (char)((uint)unaff_EBX >> 8) + cVar8),0x49));
    if (piVar11[0x130] != 0) {
      puVar9 = TDrawArea::Lock((TDrawArea *)piVar11[8],s_scr_game__draw,1);
      if (puVar9 != (uchar *)0x0) {
        iVar6 = piVar11[0x130];
        iVar7 = *(int *)(iVar6 + 0x98);
        TDrawArea::FillRect((TDrawArea *)piVar11[8],*(long *)(iVar6 + 0x8c),*(long *)(iVar6 + 0x90),
                            *(long *)(iVar6 + 0x94),iVar7,'t');
        TDrawArea::Unlock((TDrawArea *)piVar11[8],s_scr_game__draw);
        if (piVar11[10] < iVar7) {
          piVar11[10] = iVar7;
        }
        TDrawArea::SetClipRect((TDrawArea *)piVar11[8],ptVar1);
      }
    }
    if (piVar11[0x11e] != 0) {
      puVar9 = TDrawArea::Lock((TDrawArea *)piVar11[8],s_scr_game__draw2,1);
      if (puVar9 != (uchar *)0x0) {
        if ((piVar11[5] < 0x400) || (piVar11[6] < 0x300)) {
          if ((piVar11[5] < 800) || (piVar11[6] < 600)) {
            TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',
                               (uchar *)0x0);
            pTVar12 = (TDrawArea *)piVar11[8];
            lVar13 = 0x162;
          }
          else {
            TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',
                               (uchar *)0x0);
            pTVar12 = (TDrawArea *)piVar11[8];
            lVar13 = 0x1da;
          }
        }
        else {
          TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',
                             (uchar *)0x0);
          pTVar12 = (TDrawArea *)piVar11[8];
          lVar13 = 0x282;
        }
        TShape::shape_draw((TShape *)piVar11[0x11e],pTVar12,0,lVar13,1,'\0',(uchar *)0x0);
        TDrawArea::Unlock((TDrawArea *)piVar11[8],s_scr_game__draw2);
      }
    }
    (**(code **)(iVar3 + 0x2c))();
    ptVar1->left = unaff_ESI + 1;
    piVar11[10] = lVar14;
    piVar11[0xb] = iVar4;
    piVar11[0xc] = iVar5;
    TDrawArea::SetClipRect((TDrawArea *)piVar11[8],ptVar1);
    return;
  }
  if ((piVar11[0xe] == 2) || (piVar11[0x11e] == 0)) {
    uVar10 = 1;
  }
  else {
    uVar10 = 0;
  }
  iVar3 = *piVar11;
  (**(code **)(iVar3 + 0x28))(uVar10,unaff_EDI + 1);
  if (piVar11[0x11e] != 0) {
    puVar9 = TDrawArea::Lock((TDrawArea *)piVar11[8],s_scr_game__draw3,1);
    if (puVar9 != (uchar *)0x0) {
      if ((piVar11[5] < 0x400) || (piVar11[6] < 0x300)) {
        if ((piVar11[5] < 800) || (piVar11[6] < 600)) {
          TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',
                             (uchar *)0x0);
          pTVar12 = (TDrawArea *)piVar11[8];
          lVar14 = 0x162;
        }
        else {
          TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',
                             (uchar *)0x0);
          pTVar12 = (TDrawArea *)piVar11[8];
          lVar14 = 0x1da;
        }
      }
      else {
        TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',(uchar *)0x0)
        ;
        pTVar12 = (TDrawArea *)piVar11[8];
        lVar14 = 0x282;
      }
      TShape::shape_draw((TShape *)piVar11[0x11e],pTVar12,0,lVar14,1,'\0',(uchar *)0x0);
      TDrawArea::Unlock((TDrawArea *)piVar11[8],s_scr_game__draw3);
    }
  }
  (**(code **)(iVar3 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_0049cde3
// Address: 0049cde3
// XREFS: None
void FUN_0049cde3(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

// --------------------------------------------------

// Function: FUN_004a3747
// Address: 004a3747
// XREFS: None
undefined4 __fastcall FUN_004a3747(undefined4 param_1,uint param_2)
{
  int in_EAX;
  char *pcVar1;
  byte bVar2;
  uint *puVar3;
  char cVar4;
  char *unaff_EBX;
  byte *unaff_ESI;
  char *unaff_EDI;
  int unaff_retaddr;
  
  cVar4 = (char)((uint)unaff_EBX >> 8);
  *unaff_EBX = *unaff_EBX + cVar4;
  bVar2 = *(byte *)(in_EAX + -1);
  pcVar1 = (char *)(param_2 ^ 0x4a);
  (&stack0x34cc004e)[(int)unaff_ESI] = (&stack0x34cc004e)[(int)unaff_ESI] + cVar4;
  cRame0004a35 = cRame0004a35 + cVar4;
  unaff_ESI[0x3576004a] = unaff_ESI[0x3576004a] + (char)pcVar1;
  *unaff_ESI = *unaff_ESI + (char)in_EAX + -4;
  unaff_ESI[unaff_retaddr + 0x3680004a] =
       unaff_ESI[unaff_retaddr + 0x3680004a] + (char)((uint)param_1 >> 8);
  pcVar1[0x5004a2d] = pcVar1[0x5004a2d] + (char)unaff_EBX;
  bVar2 = (byte)param_1 ^ bVar2 ^ *(byte *)(in_EAX + -6);
  *unaff_EDI = *unaff_EDI - (char)((uint)(in_EAX + -6) >> 8);
  puVar3 = (uint *)(in_EAX + -7);
  *pcVar1 = *pcVar1 + (char)pcVar1;
  *puVar3 = (uint)(pcVar1 + *puVar3);
  *unaff_ESI = *unaff_ESI | bVar2;
  *puVar3 = *puVar3 | CONCAT31((int3)((uint)param_1 >> 8),bVar2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004a4f52
// Address: 004a4f52
// XREFS: None
// [HELPER] s_Kick_Dialog: "Kick Dialog"
void __fastcall FUN_004a4f52(char *param_1,int param_2,uint param_3)
{
  char cVar1;
  char cVar4;
  undefined4 in_EAX;
  char *pcVar2;
  char *pcVar3;
  char cVar5;
  char cVar7;
  int iVar6;
  char cVar8;
  int iVar9;
  int iVar10;
  char unaff_BL;
  char unaff_BH;
  char cVar11;
  char *unaff_ESI;
  int unaff_EDI;
  char in_CF;
  char acStack_100 [256];
  
  cVar1 = (char)in_EAX + *(char *)(unaff_EDI + 0x4a) + in_CF;
  pcVar2 = (char *)CONCAT31((int3)((uint)in_EAX >> 8),cVar1);
  *param_1 = *param_1 + unaff_BL;
  cVar4 = (char)((uint)in_EAX >> 8);
  *pcVar2 = *pcVar2 + cVar4;
  *(char *)(unaff_EDI + 2) = *(char *)(unaff_EDI + 2) + cVar4;
  cVar7 = (char)((uint)param_1 >> 8);
  *unaff_ESI = *unaff_ESI + cVar7;
  cRamc3004a47 = cRamc3004a47 + (char)((uint)(param_2 + -4) >> 8);
  cVar8 = (char)(param_2 + -5) + (char)param_1;
  cVar5 = (char)param_1 + cVar8 + -1;
  cVar11 = unaff_BH + unaff_BL;
  iVar9 = CONCAT31((int3)((uint)(param_2 + -5) >> 8),cVar8) + -4;
  iVar6 = CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar7 * '\x02',cVar5));
  iVar10 = CONCAT11((char)((uint)iVar9 >> 8) + cVar4,(char)iVar9) - 2;
  iVar9 = CONCAT22((short)((uint)in_EAX >> 0x10),
                   CONCAT11(cVar4 + (char)((uint)iVar10 >> 8),cVar1 + unaff_BL));
  *(char *)(iVar9 + 0x49) = *(char *)(iVar9 + 0x49) + cVar5;
  *(char *)(iVar9 + -0x47ffb5b7) = *(char *)(iVar9 + -0x47ffb5b7) + cVar11;
  *(char *)(iVar9 + -0x47ffb5b7) = *(char *)(iVar9 + -0x47ffb5b7) + cVar11;
  *(char *)(iVar9 + 0x52004a49) = *(char *)(iVar9 + 0x52004a49) + cVar11;
  *(char *)(iVar6 + 0x46) = *(char *)(iVar6 + 0x46) + unaff_BL + cVar11;
  *(char *)(iVar9 + -0x6f6f6f70) = *(char *)(iVar9 + -0x6f6f6f70) + (char)iVar10 + -8;
  *(uint *)(iVar6 + 0x720) = param_3;
  pcVar2 = TCommunications_Handler::GetPlayerName(comm,param_3);
  pcVar3 = TPanel::get_string((TPanel *)(iVar6 + -4),0x25c8);
  sprintf(acStack_100,pcVar3,pcVar2);
  TEasy_Panel::popupYesNoDialog((TEasy_Panel *)(iVar6 + -4),acStack_100,&s_Kick_Dialog,0x1c2,100);
  return;
}

// --------------------------------------------------

// Function: FUN_004a5115
// Address: 004a5115
// XREFS: None
void FUN_004a5115(void)
{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 in_EAX;
  int unaff_ESI;
  
  pbVar1 = (byte *)(CONCAT22((short)((uint)in_EAX >> 0x10),
                             CONCAT11((char)((uint)in_EAX >> 8) * '\x02',(char)in_EAX)) +
                   -0x7c6f6f70);
  bVar2 = *pbVar1;
  *pbVar1 = *pbVar1 + 0x4c;
  in(0x4a4c);
  *(char *)(unaff_ESI + -0x75) = *(char *)(unaff_ESI + -0x75) + 'L' + (0xb3 < bVar2);
  pcVar3 = (code *)swi(1);
  (*pcVar3)();
  return;
}

// --------------------------------------------------

// Function: FUN_004a55e3
// Address: 004a55e3
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Multiplayer_Wait_Screen: "Multiplayer Wait Screen"
// [HELPER] s_scr3: "scr3"
TEasy_Panel * __fastcall FUN_004a55e3(TEasy_Panel *param_1,int param_2)
{
  char cVar1;
  uchar uVar2;
  byte bVar3;
  int in_EAX;
  long lVar4;
  int iVar5;
  MapSize MVar6;
  MapType MVar7;
  VictoryType VVar8;
  char *pcVar9;
  Age AVar10;
  ResourceLevel RVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *piVar15;
  int unaff_EDI;
  int *piVar16;
  TEasy_Panel **ppTVar17;
  char *pcVar18;
  undefined4 *unaff_FS_OFFSET;
  undefined1 *puVar19;
  int iVar20;
  TEasy_Panel *pTStack_31c;
  char acStack_318 [188];
  undefined1 auStack_25c [8];
  undefined1 auStack_254 [8];
  undefined1 auStack_24c [8];
  undefined1 auStack_244 [8];
  undefined1 auStack_23c [8];
  char acStack_234 [540];
  undefined4 uStack_18;
  code *pcStack_14;
  undefined4 uStack_10;
  
  *(char *)(unaff_EBP + 0x55) = *(char *)(unaff_EBP + 0x55) + (char)((uint)param_1 >> 8);
  *(char *)(unaff_ESI + 0x55) = *(char *)(unaff_ESI + 0x55) + (char)((uint)(param_2 + -2) >> 8);
  *(char *)(unaff_EDI + 0x55) = *(char *)(unaff_EDI + 0x55) + (char)((uint)unaff_EBX >> 8);
  *(char *)(in_EAX + -0x6effb5ab) = *(char *)(in_EAX + -0x6effb5ab) + (char)param_1;
  *(char *)(param_2 + -0x5cffb5b0) = *(char *)(param_2 + -0x5cffb5b0) + (char)unaff_EBX;
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + (char)(param_2 + -2) + -4;
  uStack_10 = 0xffffffff;
  pcStack_14 = FUN_0055f25b;
  uStack_18 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_18;
  pTStack_31c = param_1;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Multiplayer_Wait_Screen);
  piVar15 = &param_1[1]._padding_;
  param_1->_padding_ = (int)&TRIBE_Screen_Wait::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  *piVar15 = 0;
  param_1[1]._padding_ = 0;
  piVar16 = &param_1[1]._padding_;
  for (iVar12 = 0x14; iVar12 != 0; iVar12 = iVar12 + -1) {
    *piVar16 = 0;
    piVar16 = piVar16 + 1;
  }
  uStack_10 = 0;
  lVar4 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,&s_scr3,0xc385,0);
  if (lVar4 == 0) {
    param_1->_padding_ = 1;
    goto LAB_004a5fb2;
  }
  TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
  TEasy_Panel::create_text
            (param_1,(TPanel *)param_1,(TTextPanel **)(param_1 + 1),s_,0x14,0x28,0x17c,400,4,1,1,1);
  iVar12 = TEasy_Panel::create_button
                     (param_1,(TPanel *)param_1,(TButtonPanel **)piVar15,0x3ea,0,0,0,0,0,-1,-1,0);
  if (iVar12 == 0) goto LAB_004a5fb2;
  (**(code **)(*(int *)*piVar15 + 0x14))();
  (**(code **)(*(int *)*piVar15 + 0x18))(9,4,4,4);
  iVar12 = TEasy_Panel::create_text
                     (param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,s_,0x1a4,0x54,
                      0xdc,0x44,0xb,0,0,1);
  if (iVar12 == 0) goto LAB_004a5fb2;
  iVar12 = 0x53;
  piVar15 = &param_1[1]._padding_;
  do {
    iVar5 = TEasy_Panel::create_text
                      (param_1,(TPanel *)param_1,(TTextPanel **)piVar15,s_,0x1a4,iVar12,0xdc,0x14,
                       0xb,0,0,0);
    if (iVar5 == 0) goto LAB_004a5fb2;
    iVar12 = iVar12 + 0x18;
    piVar15 = piVar15 + 1;
  } while (iVar12 < 0x233);
  piVar15 = &param_1[1]._padding_;
  iVar12 = 0x14;
  do {
    (**(code **)(*(int *)*piVar15 + 0x14))();
    piVar15 = piVar15 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar12 = RGE_Base_Game::scenarioGame(rge_base_game);
  if (iVar12 == 0) {
    uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
    if (uVar2 == '\0') {
      iVar12 = 0x25b5;
    }
    else {
      iVar12 = 0x2617;
    }
    TPanel::get_string((TPanel *)param_1,iVar12,acStack_318,0x100);
    TPanel::get_string((TPanel *)param_1,0x25ed);
    sprintf();
    (**(code **)(*(int *)param_1[1]._padding_ + 0xe8))();
    iVar12 = 1;
  }
  else {
    RGE_Base_Game::scenarioName(rge_base_game);
    TPanel::get_string((TPanel *)param_1,0x25ed);
    sprintf();
    (**(code **)(*(int *)param_1[1]._padding_ + 0xe8))();
    iVar12 = 3;
  }
  iVar5 = RGE_Base_Game::randomGame(rge_base_game);
  if (iVar5 != 0) {
    MVar6 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
    switch(MVar6) {
    case Tiny:
      iVar5 = 0x2973;
      break;
    case Small:
      iVar5 = 0x2974;
      break;
    case Medium:
      iVar5 = 0x2975;
      break;
    case Large:
      iVar5 = 0x2976;
      break;
    case Huge:
      iVar5 = 0x2977;
      break;
    case Humongous:
      iVar5 = 0x2978;
      break;
    default:
      goto switchD_004a589d_default;
    }
    pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar13 = 0xffffffff;
    do {
      pcVar18 = pcVar9;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar18 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar18;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar9 = pcVar18 + -uVar13;
    ppTVar17 = &pTStack_31c;
    for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
      *ppTVar17 = *(TEasy_Panel **)pcVar9;
      pcVar9 = pcVar9 + 4;
      ppTVar17 = ppTVar17 + 1;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(char *)ppTVar17 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      ppTVar17 = (TEasy_Panel **)((int)ppTVar17 + 1);
    }
switchD_004a589d_default:
    TPanel::get_string((TPanel *)param_1,0x25da);
    sprintf();
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
    MVar7 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
    switch(MVar7) {
    case AllWater:
      iVar5 = 0x296a;
      break;
    case MostlyWater:
      iVar5 = 0x296b;
      break;
    case WaterAndLand:
      iVar5 = 0x296c;
      break;
    case MostlyLand:
      iVar5 = 0x296d;
      break;
    case AllLand:
      iVar5 = 0x296e;
      break;
    case Continental:
      iVar5 = 0x296f;
      break;
    case Lake:
      iVar5 = 0x2970;
      break;
    case Hilly:
      iVar5 = 0x2971;
      break;
    case Isthmas:
      iVar5 = 0x2972;
      break;
    default:
      goto switchD_004a594e_default;
    }
    pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar13 = 0xffffffff;
    do {
      pcVar18 = pcVar9;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar18 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar18;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar9 = pcVar18 + -uVar13;
    pcVar18 = &stack0xfffffcdc;
    for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
      *(undefined4 *)pcVar18 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar18 = pcVar18 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar18 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar18 = pcVar18 + 1;
    }
switchD_004a594e_default:
    TPanel::get_string((TPanel *)param_1,0x25b6);
    sprintf();
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
    iVar12 = iVar12 + 2;
  }
  VVar8 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
  switch(VVar8) {
  case VictoryConquest:
    iVar5 = 0x10e1;
    break;
  default:
    iVar5 = RGE_Base_Game::randomGame(rge_base_game);
    if (iVar5 != 0) goto switchD_004a5a16_caseD_9;
    iVar5 = 0x10e7;
    break;
  case VictoryTime:
    iVar5 = 0x10e9;
    goto LAB_004a5a33;
  case VictoryScore:
    iVar5 = 0x10ea;
LAB_004a5a33:
    pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar13 = 0xffffffff;
    do {
      pcVar18 = pcVar9;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar18 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar18;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar9 = pcVar18 + -uVar13;
    ppTVar17 = &pTStack_31c;
    for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
      *ppTVar17 = *(TEasy_Panel **)pcVar9;
      pcVar9 = pcVar9 + 4;
      ppTVar17 = ppTVar17 + 1;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(char *)ppTVar17 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      ppTVar17 = (TEasy_Panel **)((int)ppTVar17 + 1);
    }
    TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
    TPanel::get_string((TPanel *)param_1,0x25be);
    sprintf();
    goto LAB_004a5af4;
  case VictoryStandard:
switchD_004a5a16_caseD_9:
    iVar5 = 0x10ec;
  }
  pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
  uVar13 = 0xffffffff;
  do {
    pcVar18 = pcVar9;
    if (uVar13 == 0) break;
    uVar13 = uVar13 - 1;
    pcVar18 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar18;
  } while (cVar1 != '\0');
  uVar13 = ~uVar13;
  pcVar9 = pcVar18 + -uVar13;
  ppTVar17 = &pTStack_31c;
  for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
    *ppTVar17 = *(TEasy_Panel **)pcVar9;
    pcVar9 = pcVar9 + 4;
    ppTVar17 = ppTVar17 + 1;
  }
  for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
    *(char *)ppTVar17 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    ppTVar17 = (TEasy_Panel **)((int)ppTVar17 + 1);
  }
  TPanel::get_string((TPanel *)param_1,0x25bc);
  sprintf();
LAB_004a5af4:
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
  AVar10 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  if (AVar10 == DefaultAge) {
    iVar5 = 0x10e7;
  }
  else if (AVar10 == NomadAge) {
    iVar5 = 0x106e;
  }
  else {
    iVar5 = AVar10 + 0x1067;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffcdc,0x100);
  TPanel::get_string((TPanel *)param_1,0x25e4);
  sprintf();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
  RVar11 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
  if (RVar11 == DefaultResources) {
    iVar5 = 0x10e7;
  }
  else {
    iVar5 = RVar11 + 0x25e5;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffcd4,0x100);
  TPanel::get_string((TPanel *)param_1,0x25e5);
  sprintf();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
  RGE_Base_Game::difficulty(rge_base_game);
  pcVar9 = &stack0xfffffccc;
  iVar20 = 0x100;
  iVar5 = RGE_Base_Game::difficulty(rge_base_game);
  TPanel::get_string((TPanel *)param_1,iVar5 + 0x2bd0,pcVar9,iVar20);
  TPanel::get_string((TPanel *)param_1,0x25e0,acStack_234,0x100);
  sprintf();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
  iVar5 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game);
  if (iVar5 == 0) {
    iVar5 = 0xfa3;
  }
  else {
    iVar5 = 0xfa4;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffcc4,0x100);
  pcVar9 = TPanel::get_string((TPanel *)param_1,0x25e9);
  sprintf(auStack_23c,pcVar9);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))(1);
  iVar5 = RGE_Base_Game::fullVisibility(rge_base_game);
  if (iVar5 == 0) {
    iVar5 = 0xfa4;
  }
  else {
    iVar5 = 0xfa3;
  }
  pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
  uVar13 = 0xffffffff;
  do {
    pcVar18 = pcVar9;
    if (uVar13 == 0) break;
    uVar13 = uVar13 - 1;
    pcVar18 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar18;
  } while (cVar1 != '\0');
  uVar13 = ~uVar13;
  pcVar9 = pcVar18 + -uVar13;
  pcVar18 = &stack0xfffffcbc;
  for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
    *(undefined4 *)pcVar18 = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
    pcVar18 = pcVar18 + 4;
  }
  for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
    *pcVar18 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar18 = pcVar18 + 1;
  }
  puVar19 = &stack0xfffffcbc;
  pcVar9 = TPanel::get_string((TPanel *)param_1,0x25b8);
  sprintf(auStack_244,pcVar9,puVar19);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))(auStack_244);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))(1);
  iVar5 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
  if (iVar5 == 0) {
    iVar5 = 0xfa4;
  }
  else {
    iVar5 = 0xfa3;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffcb4,0x100);
  puVar19 = &stack0xfffffcb4;
  pcVar9 = TPanel::get_string((TPanel *)param_1,0x25ec);
  sprintf(auStack_24c,pcVar9,puVar19);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))(auStack_24c);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))(1);
  iVar20 = iVar12 + 8;
  iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar5 != 0) {
    iVar5 = RGE_Base_Game::allowCheatCodes(rge_base_game);
    if (iVar5 == 0) {
      iVar5 = 0xfa4;
    }
    else {
      iVar5 = 0xfa3;
    }
    pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar13 = 0xffffffff;
    do {
      pcVar18 = pcVar9;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar18 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar18;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar9 = pcVar18 + -uVar13;
    pcVar18 = &stack0xfffffcac;
    for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
      *(undefined4 *)pcVar18 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar18 = pcVar18 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar18 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar18 = pcVar18 + 1;
    }
    puVar19 = &stack0xfffffcac;
    pcVar9 = TPanel::get_string((TPanel *)param_1,0x25bb);
    sprintf(auStack_254,pcVar9,puVar19);
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))(auStack_254);
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))(1);
    iVar20 = iVar12 + 9;
  }
  iVar12 = RGE_Base_Game::multiplayerGame(rge_base_game);
  iVar5 = 0x100;
  if (iVar12 == 0) {
    pcVar9 = &stack0xfffffcac;
    bVar3 = RGE_Base_Game::pathFinding(rge_base_game);
  }
  else {
    pcVar9 = &stack0xfffffcac;
    bVar3 = RGE_Base_Game::mpPathFinding(rge_base_game);
  }
  TPanel::get_string((TPanel *)param_1,bVar3 + 0x260e,pcVar9,iVar5);
  puVar19 = &stack0xfffffcac;
  pcVar9 = TPanel::get_string((TPanel *)param_1,0x25f1);
  sprintf(auStack_254,pcVar9,puVar19);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar20] + 0xe8))(auStack_254);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar20] + 0x14))(1);
  bVar3 = TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
  uVar13 = (uint)bVar3;
  pcVar9 = TPanel::get_string((TPanel *)param_1,0x25f0);
  sprintf(auStack_25c,pcVar9,uVar13);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar20] + 0xe8))(auStack_25c);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar20] + 0x14))(1);
LAB_004a5fb2:
  *unaff_FS_OFFSET = uStack_18;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a5fcd
// Address: 004a5fcd
// XREFS: None
void __fastcall
FUN_004a5fcd(int param_1,int param_2,undefined4 param_3,char param_4,int param_5,undefined4 param_6)
{
  char *pcVar1;
  code *pcVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar7;
  int unaff_EBX;
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  int in_stack_00000024;
  int iVar6;
  
  *unaff_EDI = *unaff_ESI;
  cVar4 = (char)((uint)param_1 >> 8);
  *(char *)(unaff_EBX + -0x4dffb5a8) = *(char *)(unaff_EBX + -0x4dffb5a8) + cVar4;
  cVar7 = (char)((uint)unaff_EBX >> 8);
  *(char *)(param_1 + -0x3fffb5a8) = *(char *)(param_1 + -0x3fffb5a8) + cVar7;
  cVar5 = (char)unaff_EBX;
  cVar7 = cVar7 + param_4;
  iVar6 = CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(cVar7,cVar5));
  *(char *)(unaff_EBP + 0x59) = *(char *)(unaff_EBP + 0x59) + (char)param_2 + -4;
  pcVar1 = (char *)(param_1 + 0x4a + iVar6 * 2);
  *pcVar1 = *pcVar1 + cVar5;
  cVar3 = (char)((uint)param_5 >> 8);
  *(char *)(iVar6 + 0x59) = *(char *)(iVar6 + 0x59) + cVar3;
  *(char *)(param_2 + 0x53) = *(char *)(param_2 + 0x53) + cVar4;
  *(char *)(param_1 + 0x59) = *(char *)(param_1 + 0x59) + (char)((uint)(param_2 + -7) >> 8);
  *(char *)(param_5 + 0x59) = *(char *)(param_5 + 0x59) + cVar7;
  unaff_EDI[0x5a] = unaff_EDI[0x5a] + cVar7;
  unaff_ESI[-0x72ffb5a6] = unaff_ESI[-0x72ffb5a6] + (char)param_5;
  cRam8d004a5a = cRam8d004a5a + cVar5;
  *(char *)(unaff_EBP + -0x72ffb5a6) = *(char *)(unaff_EBP + -0x72ffb5a6) + (char)param_6;
  *(char *)(unaff_EBP + -0x72ffb5a6) = *(char *)(unaff_EBP + -0x72ffb5a6) + (char)param_6;
  unaff_EDI[1] = unaff_EDI[1] + cVar3;
  unaff_ESI[1] = unaff_ESI[1] + (char)((uint)param_6 >> 8);
  pcVar1 = (char *)(in_stack_00000024 + -0x74a9ffb7 + iVar6 * 2);
  *pcVar1 = *pcVar1 + cVar5;
  pcVar2 = (code *)swi(1);
  (*pcVar2)();
  return;
}

// --------------------------------------------------

// Function: FUN_004aa6e6
// Address: 004aa6e6
// XREFS: None
void __fastcall FUN_004aa6e6(int param_1,int param_2)
{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  undefined4 in_EAX;
  char cVar4;
  char cVar5;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  cVar5 = (char)((uint)unaff_EBX >> 8);
  *(char *)(param_2 + -100) = *(char *)(param_2 + -100) + cVar5;
  *(char *)(param_2 + -2) = *(char *)(param_2 + -2) + (char)((uint)in_EAX >> 8);
  pcVar1 = (char *)(unaff_EDI + 0x4a + unaff_EBX * 4);
  cVar4 = (char)((uint)param_1 >> 8);
  *pcVar1 = *pcVar1 + cVar4;
  *(char *)(unaff_ESI + 0x9004aa4) = *(char *)(unaff_ESI + 0x9004aa4) + (char)param_2 + -3;
  iVar2 = iRama183004a;
  *(char *)(iRama183004a + 0x4aa5) = *(char *)(iRama183004a + 0x4aa5) + (char)unaff_EBX;
  cRama293004a = (char)iVar2;
  cRama317004a = cRama293004a;
  *(char *)(unaff_EDI + -0x5e) = *(char *)(unaff_EDI + -0x5e) + cVar4;
  *(char *)(iVar2 + -0x5e) = *(char *)(iVar2 + -0x5e) + cVar5;
  *(char *)(param_1 + -0x75ffb55e) = *(char *)(param_1 + -0x75ffb55e) + cRama293004a;
  *(char *)(iVar2 + -0x6f6f6f70) = *(char *)(iVar2 + -0x6f6f6f70) + (char)param_2 + -8;
  bVar3 = false;
  if ((((rge_base_game->master_obj_id != -1) &&
       (iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x928) + 0x40) +
                                          *(short *)(param_1 + 0x4b8) * 4) + 0x24) +
                        rge_base_game->master_obj_id * 4), iVar2 != 0)) &&
      (*(char *)(iVar2 + 4) == 'P')) && (*(char *)(iVar2 + 0x16c) != '\0')) {
    bVar3 = true;
  }
  if (bVar3) {
    (**(code **)(rge_base_game->_padding_ + 0x10))(0x15,0);
    return;
  }
  (**(code **)(rge_base_game->_padding_ + 0x10))(8,rge_base_game->sub_game_mode);
  return;
}

// --------------------------------------------------

// Function: FUN_004aab4a
// Address: 004aab4a
// XREFS: None
void FUN_004aab4a(void)
{
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_004aadbf
// Address: 004aadbf
// XREFS: None
void __fastcall FUN_004aadbf(int param_1,int param_2)
{
  char *pcVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  short unaff_retaddr;
  
  iVar2 = *unaff_ESI;
  pcVar1 = (char *)(unaff_EBP * 5 + 0x4a);
  *pcVar1 = *pcVar1 + (char)((uint)iVar2 >> 8);
  *(char *)(unaff_EBX + -0x53) = *(char *)(unaff_EBX + -0x53) + (char)((uint)param_1 >> 8);
  *(char *)(param_2 + -0x55) = *(char *)(param_2 + -0x55) + (char)((uint)(param_2 + -2) >> 8);
  *(char *)(param_1 + -0x53) = *(char *)(param_1 + -0x53) + (char)((uint)unaff_EBX >> 8);
  *(char *)(iVar2 + -0x78ffb553) = *(char *)(iVar2 + -0x78ffb553) + (char)iVar2;
  *(char *)((int)unaff_ESI + -0x6affb54b) = *(char *)((int)unaff_ESI + -0x6affb54b) + (char)param_1;
  *(char *)(unaff_ESI[2] + -0x6f6f6f70) =
       *(char *)(unaff_ESI[2] + -0x6f6f6f70) + (char)(param_2 + -2) + -4;
  rge_base_game->elevation_height = unaff_retaddr;
  TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x5a8),'\x01',unaff_retaddr,1);
  return;
}

// --------------------------------------------------

// Function: TRIBE_Screen_Sed_unit_list_compare
// Address: 004ab2d0
// XREFS: set_unit_player
int __cdecl TRIBE_Screen_Sed_unit_list_compare(void *param_1,void *param_2)
{
  int iVar1;
  
  iVar1 = CompareStringA(0x400,1,param_1,0xffffffff,param_2,0xffffffff);
  if (iVar1 == 1) {
    return -1;
  }
  return (uint)(iVar1 == 3);
}

// --------------------------------------------------

// Function: FUN_004abc31
// Address: 004abc31
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_sed_cp: "C:\msdev\work\age1_x1\scr_sed.cpp"
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
undefined4 FUN_004abc31(void)
{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  TEditPanel *pTVar6;
  TRIBE_World *pTVar7;
  RGE_Scenario *pRVar8;
  TDropDownPanel *pTVar9;
  TPanel *pTVar10;
  TRIBE_Main_View *pTVar11;
  TTextPanel *pTVar12;
  MapType MVar13;
  undefined4 *puVar14;
  RGE_Map *pRVar15;
  TRIBE_Scenario_Editor_Panel_Object *pTVar16;
  TButtonPanel *pTVar17;
  code *pcVar18;
  TRIBE_Main_View *pTVar19;
  T_Scenario *pTVar20;
  float fVar21;
  RGE_Base_Game *pRVar22;
  char in_AL;
  byte bVar23;
  short sVar24;
  int iVar25;
  undefined4 uVar26;
  RGE_Player *pRVar27;
  int iVar28;
  char *pcVar29;
  byte *pbVar30;
  long lVar31;
  int extraout_EAX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar33;
  TButtonPanel **ppTVar32;
  TRIBE_Screen_Sed_Open *this;
  TRIBE_Screen_Sed *this_00;
  TEditPanel **ppTVar34;
  undefined2 extraout_var_01;
  char *unaff_EBX;
  undefined1 *puVar35;
  undefined4 *puVar36;
  undefined4 *puVar37;
  undefined4 *puVar38;
  undefined4 *puVar39;
  undefined1 *puVar40;
  undefined1 *puVar41;
  undefined1 *puVar42;
  undefined1 *puVar43;
  undefined4 *puVar44;
  undefined4 *puVar45;
  undefined1 *puVar46;
  undefined4 *puVar47;
  undefined4 *puVar48;
  undefined4 *puVar49;
  undefined4 *puVar50;
  undefined4 *puVar51;
  undefined1 *puVar52;
  undefined1 *puVar53;
  undefined1 *puVar54;
  undefined1 *puVar55;
  undefined1 *puVar56;
  undefined1 *puVar57;
  undefined1 *puVar58;
  undefined4 unaff_EBP;
  int unaff_ESI;
  RGE_Static_Object *pRVar59;
  int unaff_EDI;
  byte *pbVar60;
  undefined4 *unaff_FS_OFFSET;
  char in_CF;
  bool bVar61;
  
  *(char *)(unaff_EDI + 0x66004ab9) = *(char *)(unaff_EDI + 0x66004ab9) + in_AL + -0x48 + in_CF;
  puVar1 = (undefined1 *)(unaff_EDI * 4 + -0x473effb6);
  *puVar1 = *puVar1;
  *(char *)(unaff_EDI + -0x48) = *(char *)(unaff_EDI + -0x48) + (char)((uint)unaff_EBX >> 8);
  *(char *)(unaff_ESI + -0x48) = *(char *)(unaff_ESI + -0x48) + (char)unaff_EBX;
  iVar25 = (CONCAT31(0xb83d00,(*unaff_EBX + 0x4aU | 0xc) + 0xc) | 0xc) + 0xc07060c;
  bVar5 = (byte)iVar25;
  bVar23 = bVar5 | 0xc;
  bRamb945004a = bRamb945004a | 0x4a;
  this_00 = (TRIBE_Screen_Sed *)CONCAT22(0xb945,CONCAT11(bVar5,*unaff_EBX) | 0xc4a);
  pcRam01000046 = unaff_EBX;
  *(byte *)&this_00->_padding_ = (char)this_00->_padding_ + bVar23;
  iVar25 = CONCAT31((int3)((uint)iVar25 >> 8),bVar23 + 0x20);
  piVar2 = (int *)(iVar25 + 0x400004a);
  *piVar2 = *piVar2 + iVar25;
  uRam0400003e = *unaff_FS_OFFSET;
  uRam04000046 = 0xffffffff;
  pcRam04000042 = FUN_0055f48b;
  *unaff_FS_OFFSET = 0x400003e;
  pTVar11 = pTRam0400004e;
  uRam04000012 = 0xb9ee004a;
  puVar35 = (undefined1 *)0x4000006;
  iRam04000006 = unaff_EDI;
  iRam0400000a = unaff_ESI;
  uRam0400000e = unaff_EBP;
  if (pTRam0400004e == (TRIBE_Main_View *)0x0) {
    uVar26 = 0;
    goto LAB_004abe5f;
  }
  if (pTRam0400004e != this_00->main_view) {
    if (this_00->SelectedObject != (RGE_Static_Object *)0x0) {
      iRam04000002 = 0;
      uRam03fffffa = 0x4abd1d;
      pRRam03fffffe = this_00->SelectedObject;
      pRVar27 = RGE_Base_Game::get_player(rge_base_game);
      uRam03fffffa = 0x4abd24;
      RGE_Player::select_one_object(pRVar27,pRRam03fffffe,iRam04000002);
    }
    if (this_00->DestinationObject != (RGE_Static_Object *)0x0) {
      iRam04000002 = 0;
      uRam03fffffa = 0x4abd3c;
      pRRam03fffffe = this_00->DestinationObject;
      pRVar27 = RGE_Base_Game::get_player(rge_base_game);
      uRam03fffffa = 0x4abd43;
      RGE_Player::select_one_object(pRVar27,pRRam03fffffe,iRam04000002);
    }
  }
  iVar25 = iRam04000052;
  puVar35 = (undefined1 *)0x4000006;
  if ((iRam04000052 == 0) &&
     (((((((pTVar11 == (TRIBE_Main_View *)this_00->random_seed_input ||
           (pTVar11 == (TRIBE_Main_View *)this_00->player_inven_input[0])) ||
          (pTVar11 == (TRIBE_Main_View *)this_00->player_inven_input[1])) ||
         ((pTVar11 == (TRIBE_Main_View *)this_00->player_inven_input[2] ||
          (pTVar11 == (TRIBE_Main_View *)this_00->player_inven_input[3])))) ||
        (pTVar11 == (TRIBE_Main_View *)this_00->player_inven_input[4])) ||
       (((pTVar11 == (TRIBE_Main_View *)this_00->player_setting_label[0] ||
         (pTVar11 == (TRIBE_Main_View *)this_00->victory_condition_explore)) ||
        ((pTVar11 == (TRIBE_Main_View *)this_00->victory_condition_ruins ||
         (((pTVar11 == (TRIBE_Main_View *)this_00->victory_condition_artifacts ||
           (pTVar11 == (TRIBE_Main_View *)this_00->victory_condition_discoveries)) ||
          (pTVar11 == (TRIBE_Main_View *)this_00->victory_condition_gold)))))))) ||
      ((pTVar11 == (TRIBE_Main_View *)this_00->victory_amount_input ||
       (pTVar11 == (TRIBE_Main_View *)this_00->message_input)))))) {
    this_00->need_to_save_flag = '\x01';
  }
  if (pTVar11 == this_00->main_view) {
    if (iVar25 != 0x10) {
      if ((iVar25 == 0x11) && (rge_base_game->game_mode == 0x11)) {
        iRam04000002 = 0;
        pRRam03fffffe = (RGE_Static_Object *)0x0;
        puVar35 = (undefined1 *)0x3fffffa;
        uRam03fffffa = 0x4abe90;
        (**(code **)(rge_base_game->_padding_ + 0x10))();
      }
      goto LAB_004abe90;
    }
    iRam04000002 = 0x4abde2;
    pRVar27 = RGE_Base_Game::get_player(rge_base_game);
    iRam04000002 = 0x4abde9;
    RGE_Player::unselect_object(pRVar27);
    pRVar59 = pRRam04000056;
    if (this_00->SelectRegionFlag == SELECT_OBJECT) {
      this_00->SelectedObject = pRRam04000056;
    }
    if (this_00->SelectRegionFlag == SELECT_DEST_OBJECT) {
      this_00->DestinationObject = pRVar59;
    }
    pRRam03fffffe = this_00->SelectedObject;
    if (pRRam03fffffe != (RGE_Static_Object *)0x0) {
      iRam04000002 = 0;
      uRam03fffffa = 0x4abe25;
      pRVar27 = RGE_Base_Game::get_player(rge_base_game);
      uRam03fffffa = 0x4abe2c;
      RGE_Player::select_one_object(pRVar27,pRRam03fffffe,iRam04000002);
    }
    pRRam03fffffe = this_00->DestinationObject;
    if (pRRam03fffffe != (RGE_Static_Object *)0x0) {
      iRam04000002 = 0;
      uRam03fffffa = 0x4abe44;
      pRVar27 = RGE_Base_Game::get_player(rge_base_game);
      uRam03fffffa = 0x4abe4b;
      RGE_Player::select_one_object(pRVar27,pRRam03fffffe,iRam04000002);
    }
    iRam04000002 = 0;
    pRRam03fffffe = (RGE_Static_Object *)0x0;
    puVar35 = (undefined1 *)0x3fffffa;
    uRam03fffffa = 0x4abe5a;
    (**(code **)(rge_base_game->_padding_ + 0x10))();
  }
  else {
LAB_004abe90:
    if (iVar25 == 1) {
      iVar28 = 0;
      ppTVar32 = this_00->scenario_mode_button;
      do {
        if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
          *(int *)(puVar35 + -4) = iVar28 + 1;
          *(undefined4 *)(puVar35 + -8) = 0x4ad069;
          TRIBE_Screen_Sed::set_scenario_mode(this_00,*(ScenarioMode *)(puVar35 + -4));
          goto LAB_004abe5a;
        }
        iVar28 = iVar28 + 1;
        ppTVar32 = ppTVar32 + 1;
      } while (iVar28 < 10);
      if (pTVar11 == (TRIBE_Main_View *)this_00->menu_button) {
        *(undefined4 *)(puVar35 + -4) = 0x4abebd;
        TRIBE_Screen_Sed::command_menu(this_00);
      }
      else {
        if (pTVar11 != (TRIBE_Main_View *)this_00->help_button) goto LAB_004abf01;
        *(undefined4 *)(puVar35 + -4) = 0x4abece;
        TEasy_Panel::setup_popup_help((TEasy_Panel *)this_00);
      }
    }
    else {
      iVar28 = 0;
      ppTVar32 = this_00->scenario_mode_button;
      do {
        if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) goto LAB_004abe5a;
        iVar28 = iVar28 + 1;
        ppTVar32 = ppTVar32 + 1;
      } while (iVar28 < 10);
      if ((pTVar11 != (TRIBE_Main_View *)this_00->menu_button) &&
         (pTVar11 != (TRIBE_Main_View *)this_00->help_button)) {
LAB_004abf01:
        *(undefined4 *)(puVar35 + -4) = 0x4abf08;
        pcVar29 = TPanel::panelName((TPanel *)pTVar11);
        if (pcVar29 != (char *)0x0) {
          pbVar60 = &s_OKDialog;
          *(undefined4 *)(puVar35 + -4) = 0x4abf18;
          pbVar30 = (byte *)TPanel::panelName((TPanel *)pTVar11);
          do {
            bVar5 = *pbVar30;
            bVar61 = bVar5 < *pbVar60;
            if (bVar5 != *pbVar60) {
LAB_004abf3c:
              iVar28 = (1 - (uint)bVar61) - (uint)(bVar61 != 0);
              goto LAB_004abf41;
            }
            if (bVar5 == 0) break;
            bVar5 = pbVar30[1];
            bVar61 = bVar5 < pbVar60[1];
            if (bVar5 != pbVar60[1]) goto LAB_004abf3c;
            pbVar30 = pbVar30 + 2;
            pbVar60 = pbVar60 + 2;
          } while (bVar5 != 0);
          iVar28 = 0;
LAB_004abf41:
          if (iVar28 == 0) {
            if (iVar25 == 0) {
              *(undefined1 **)(puVar35 + -4) = &s_OKDialog;
              *(undefined4 *)(puVar35 + -8) = 0x4abf5c;
              TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar35 + -4));
              *(undefined4 *)(puVar35 + -4) = 3;
              *(undefined4 *)(puVar35 + -8) = 0x4abf65;
              TRIBE_Screen_Sed::set_scenario_mode(this_00,*(ScenarioMode *)(puVar35 + -4));
            }
            goto LAB_004abe5a;
          }
        }
        switch(this_00->scenario_mode) {
        case ScenarioModeMap:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 1) {
            iVar28 = 0;
            ppTVar32 = this_00->map_type_button;
            do {
              if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
                *(undefined4 *)(puVar35 + -4) = 1;
                *(int *)(puVar35 + -8) = iVar28 + 1;
                *(undefined4 *)(puVar35 + -0xc) = 0x4ac4f8;
                TRIBE_Screen_Sed::set_map_type
                          (this_00,*(MapType *)(puVar35 + -8),*(int *)(puVar35 + -4));
                goto LAB_004abe5a;
              }
              iVar28 = iVar28 + 1;
              ppTVar32 = ppTVar32 + 1;
            } while (iVar28 < 3);
            if (pTVar11 == (TRIBE_Main_View *)this_00->generate_map_button) {
              pTVar12 = this_00->map_generating_text;
              *(undefined4 *)(puVar35 + -4) = 1;
              pcVar18 = *(code **)(pTVar12->_padding_ + 0x14);
              puVar40 = puVar35 + -8;
              *(undefined4 *)(puVar35 + -8) = 0x4ac516;
              (*pcVar18)();
              iVar25 = this_00->_padding_;
              *(undefined4 *)(puVar40 + -4) = 2;
              pcVar18 = *(code **)(iVar25 + 0x20);
              puVar41 = puVar40 + -8;
              *(undefined4 *)(puVar40 + -8) = 0x4ac51f;
              (*pcVar18)();
              pRVar22 = rge_base_game;
              *(undefined4 *)(puVar41 + -4) = 0;
              *(undefined4 *)(puVar41 + -8) = 0;
              *(void **)(puVar41 + -0xc) = pRVar22->prog_window;
              puVar42 = puVar41 + -0x10;
              *(undefined4 *)(puVar41 + -0x10) = 0x4ac533;
              InvalidateRect();
              pRVar22 = rge_base_game;
              *(undefined4 *)(puVar42 + -4) = 0x4ac53e;
              RGE_Base_Game::draw_window(pRVar22);
              pTVar9 = this_00->map_size_drop;
              *(undefined4 *)(puVar42 + -4) = 0x4ac549;
              iVar25 = TDropDownPanel::currentLineNumber(pTVar9);
              pTVar9 = this_00->map_style_drop;
              *(undefined4 *)(puVar42 + -4) = 0x4ac556;
              iVar28 = TDropDownPanel::currentLineNumber(pTVar9);
              *(int *)(puVar42 + 0x4c) = iVar28;
              switch(iVar25) {
              case 0:
                iVar25 = 0x48;
                break;
              case 1:
                iVar25 = 0x60;
                break;
              case 2:
                iVar25 = 0x78;
                break;
              case 3:
                iVar25 = 0x90;
                break;
              case 4:
                iVar25 = 200;
                break;
              case 5:
                iVar25 = 0xfa;
                break;
              default:
                iVar25 = *(int *)(puVar42 + 0x4c);
              }
              pTVar9 = this_00->player_number_list;
              *(undefined4 *)(puVar42 + -4) = 0x4ac59f;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              pRVar22 = rge_base_game;
              MVar13 = this_00->map_type;
              if (MVar13 == MapTypeBlank) {
                pTVar9 = this_00->default_terrain_drop;
                *(undefined4 *)(puVar42 + -4) = 0x4ac5bc;
                iVar28 = TDropDownPanel::currentLineNumber(pTVar9);
                switch(iVar28) {
                case 0:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 0;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac5e5;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 1:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 6;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac603;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 2:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 10;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac621;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 3:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 1;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac63f;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 4:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 0xd;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac65d;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 5:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 0x14;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac67b;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 6:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 4;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac699;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 7:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 0x13;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac6b7;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 8:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 0x16;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac6d5;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                }
              }
              else {
                *(int *)(puVar42 + 0x48) = rge_base_game->random_map_seed;
                if (MVar13 == MapTypeSeed) {
                  pTVar6 = this_00->random_seed_input;
                  *(undefined4 *)(puVar42 + -4) = 0x4ac6f7;
                  pcVar29 = TEditPanel::currentLine(pTVar6);
                  *(char **)(puVar42 + -4) = pcVar29;
                  *(undefined4 *)(puVar42 + -8) = 0x4ac6fd;
                  iVar28 = atoi();
                  rge_base_game->random_map_seed = iVar28;
                }
                else {
                  pRVar22->random_map_seed = -1;
                }
                iVar28 = 0;
                do {
                  pRVar27 = *(RGE_Player **)(this_00->world->_padding_ + iVar28);
                  *(undefined4 *)(puVar42 + -4) = 0x4ac725;
                  RGE_Player::reset_selected(pRVar27);
                  iVar28 = iVar28 + 4;
                } while (iVar28 < 0x24);
                pTVar7 = this_00->world;
                *(long *)(puVar42 + -4) = lVar31 + 1;
                piVar2 = (int *)pTVar7->_padding_;
                *(undefined4 *)(puVar42 + -8) = *(undefined4 *)(puVar42 + 0x4c);
                *(int *)(puVar42 + -0xc) = iVar25;
                *(int *)(puVar42 + -0x10) = iVar25;
                iVar28 = *piVar2;
                *(TRIBE_World **)(puVar42 + -0x14) = pTVar7;
                pcVar18 = *(code **)(iVar28 + 0x28);
                puVar43 = puVar42 + -0x18;
                *(undefined4 *)(puVar42 + -0x18) = 0x4ac744;
                (*pcVar18)();
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar43 + -4) = 10;
                pRVar22->random_map_seed = *(int *)(puVar43 + 0x48);
                pRVar22 = rge_base_game;
                *(undefined1 **)(puVar43 + -8) = puVar43 + 0x20;
                *(int *)(puVar43 + -0xc) = pRVar22->save_random_map_seed;
                *(undefined4 *)(puVar43 + -0x10) = 0x4ac765;
                itoa();
                iVar28 = this_00->random_seed_used_text->_padding_;
                *(undefined1 **)(puVar43 + -4) = puVar43 + 0x20;
                pcVar18 = *(code **)(iVar28 + 0xe8);
                puVar42 = puVar43 + -8;
                *(undefined4 *)(puVar43 + -8) = 0x4ac77b;
                (*pcVar18)();
                *(undefined4 *)(puVar42 + -4) = 0xb58;
                *(char **)(puVar42 + -8) = s_C__msdev_work_age1_x1_scr_sed_cp;
                *(undefined4 *)(puVar42 + -0xc) = 0x4ac78a;
                debug_rand(*(char **)(puVar42 + -8),*(int *)(puVar42 + -4));
              }
              iVar25 = iVar25 / 2;
              *(int *)(puVar42 + 0x4c) = iVar25;
              iVar28 = 0;
              *(float *)(puVar42 + 0x4c) = (float)*(int *)(puVar42 + 0x4c);
              uVar26 = *(undefined4 *)(puVar42 + 0x4c);
              do {
                pTVar7 = this_00->world;
                *(int *)(puVar42 + -4) = iVar25;
                *(int *)(puVar42 + -8) = iVar25;
                pRVar27 = *(RGE_Player **)(pTVar7->_padding_ + iVar28);
                *(undefined4 *)(puVar42 + -0xc) = 0x4ac7bb;
                RGE_Player::set_map_loc(pRVar27,*(short *)(puVar42 + -8),*(short *)(puVar42 + -4));
                pTVar7 = this_00->world;
                *(undefined4 *)(puVar42 + -4) = uVar26;
                *(undefined4 *)(puVar42 + -8) = uVar26;
                pRVar27 = *(RGE_Player **)(pTVar7->_padding_ + iVar28);
                *(undefined4 *)(puVar42 + -0xc) = 0x4ac7ce;
                RGE_Player::set_view_loc(pRVar27,*(float *)(puVar42 + -8),*(float *)(puVar42 + -4));
                iVar28 = iVar28 + 4;
              } while (iVar28 < 0x20);
              iVar25 = 0;
              do {
                iVar28 = *(int *)(this_00->world->_padding_ + iVar25);
                *(undefined4 *)(puVar42 + -4) = 0x4ac7ec;
                RGE_Tile_List::del_list((RGE_Tile_List *)(iVar28 + 0x58));
                pRVar27 = *(RGE_Player **)(this_00->world->_padding_ + iVar25);
                *(undefined4 *)(puVar42 + -4) = 0x4ac7fd;
                RGE_Player::set_map_visible(pRVar27);
                iVar25 = iVar25 + 4;
              } while (iVar25 < 0x20);
              *(undefined4 *)(puVar42 + -4) = 0x4ac80c;
              TRIBE_Screen_Sed::set_panel_info(this_00);
              pTVar12 = this_00->map_generating_text;
              *(undefined4 *)(puVar42 + -4) = 0;
              pcVar18 = *(code **)(pTVar12->_padding_ + 0x14);
              puVar35 = puVar42 + -8;
              *(undefined4 *)(puVar42 + -8) = 0x4ac81b;
              (*pcVar18)();
              goto LAB_004abe5a;
            }
          }
          break;
        case ScenarioModeTerrain:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if ((iVar25 == 2) || (iVar25 == 1)) {
            pTVar19 = (TRIBE_Main_View *)this_00->paint_terrain_list;
            if (pTVar11 == pTVar19) {
              *(undefined4 *)(puVar35 + -4) = 0x4ac84e;
              iVar25 = TTextPanel::currentLineNumber((TTextPanel *)pTVar19);
              *(int *)(puVar35 + -4) = iVar25;
              *(undefined4 *)(puVar35 + -8) = 0x4ac856;
              TRIBE_Screen_Sed::set_terrain(this_00,*(short *)(puVar35 + -4));
              pTVar17 = this_00->brush_size_button[0];
              *(undefined4 *)(puVar35 + -4) = 1;
              pcVar18 = *(code **)(pTVar17->_padding_ + 0x14);
              puVar44 = (undefined4 *)(puVar35 + -8);
              puVar35 = puVar35 + -8;
              *puVar44 = 0x4ac865;
              (*pcVar18)();
            }
            else {
              pTVar19 = (TRIBE_Main_View *)this_00->paint_elevation_list;
              if (pTVar11 != pTVar19) {
                if (iVar25 == 1) {
                  if (this_00->valid_save_spot_flag != '\0') {
                    this_00->need_to_save_flag = '\x01';
                  }
                  iVar28 = 0;
                  ppTVar32 = this_00->brush_size_button;
                  do {
                    if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
                      *(int *)(puVar35 + -4) = iVar28 + 1;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac8bf;
                      TRIBE_Screen_Sed::set_brush_size(this_00,*(BrushSize *)(puVar35 + -4));
                      goto LAB_004abe5a;
                    }
                    iVar28 = iVar28 + 1;
                    ppTVar32 = ppTVar32 + 1;
                  } while (iVar28 < 5);
                  iVar28 = 0;
                  ppTVar32 = this_00->paint_type_button;
                  do {
                    if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
                      *(undefined4 *)(puVar35 + -4) = 1;
                      *(int *)(puVar35 + -8) = iVar28 + 1;
                      *(undefined4 *)(puVar35 + -0xc) = 0x4ac8e9;
                      TRIBE_Screen_Sed::set_paint_type
                                (this_00,*(PaintType *)(puVar35 + -8),*(int *)(puVar35 + -4));
                      goto LAB_004abe5a;
                    }
                    iVar28 = iVar28 + 1;
                    ppTVar32 = ppTVar32 + 1;
                  } while (iVar28 < 3);
                }
                break;
              }
              *(undefined4 *)(puVar35 + -4) = 0x4ac879;
              iVar25 = TTextPanel::currentLineNumber((TTextPanel *)pTVar19);
              *(int *)(puVar35 + -4) = iVar25;
              *(undefined4 *)(puVar35 + -8) = 0x4ac881;
              TRIBE_Screen_Sed::set_elevation(this_00,*(short *)(puVar35 + -4));
            }
            goto LAB_004abe5a;
          }
          break;
        case ScenarioModePlayers:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 0) {
            iVar28 = 0;
            ppTVar34 = this_00->player_inven_input;
            do {
              if (pTVar11 == (TRIBE_Main_View *)*ppTVar34) {
                pTVar10 = this_00->bottom_panel;
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0x4ac92b;
                TPanel::set_curr_child(pTVar10,*(TPanel **)(puVar35 + -4));
                iVar28 = extraout_EAX;
                break;
              }
              iVar28 = iVar28 + 1;
              ppTVar34 = ppTVar34 + 1;
            } while (iVar28 < 5);
            uVar33 = (undefined2)((uint)iVar28 >> 0x10);
            if (this_00->valid_save_spot_flag != '\0') {
              this_00->need_to_save_flag = '\x01';
            }
            pTVar19 = (TRIBE_Main_View *)this_00->player_advance_civilization_drop;
            if (pTVar11 == pTVar19) {
              if (this_00->valid_save_spot_flag != '\0') {
                this_00->need_to_save_flag = '\x01';
              }
              *(undefined4 *)(puVar35 + -4) = 0x4ac964;
              iVar28 = TDropDownPanel::currentLineNumber((TDropDownPanel *)pTVar19);
              pTVar7 = this_00->world;
              *(int *)(puVar35 + -4) = iVar28;
              pTVar20 = (T_Scenario *)pTVar7->_padding_;
              *(int *)(puVar35 + -8) = this_00->player_num + -1;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac97c;
              T_Scenario::SetPlayerAge(pTVar20,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
              uVar33 = extraout_var;
            }
            pTVar19 = (TRIBE_Main_View *)this_00->player_list;
            if (pTVar11 == pTVar19) {
              *(undefined4 *)(puVar35 + -4) = 1;
              *(undefined4 *)(puVar35 + -8) = 1;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac98f;
              lVar31 = TDropDownPanel::get_line((TDropDownPanel *)pTVar19);
              *(long *)(puVar35 + -0xc) = lVar31 + 1;
              *(undefined4 *)(puVar35 + -0x10) = 0x4ac998;
              TRIBE_Screen_Sed::set_player
                        (this_00,*(short *)(puVar35 + -0xc),puVar35[-8],puVar35[-4]);
              pTVar9 = this_00->player_list;
              *(undefined4 *)(puVar35 + -4) = 0x4ac9a3;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              pTVar7 = this_00->world;
              *(long *)(puVar35 + -4) = lVar31;
              pTVar20 = (T_Scenario *)pTVar7->_padding_;
              *(undefined4 *)(puVar35 + -8) = 0x4ac9b2;
              iVar28 = T_Scenario::GetPlayerAge(pTVar20,*(int *)(puVar35 + -4));
              pTVar9 = this_00->player_advance_civilization_drop;
              *(int *)(puVar35 + -4) = iVar28;
              *(undefined4 *)(puVar35 + -8) = 0x4ac9be;
              TDropDownPanel::setCurrentLineNumber(pTVar9,*(int *)(puVar35 + -4));
              uVar33 = extraout_var_00;
            }
            if (pTVar11 == (TRIBE_Main_View *)this_00->player_number_list) {
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar35 + -4) = 0;
              *(undefined4 *)(puVar35 + -8) = 1;
              *(uint *)(puVar35 + -0xc) = CONCAT22(uVar33,sVar24);
              *(undefined4 *)(puVar35 + -0x10) = 0x4ac9d9;
              TRIBE_Screen_Sed::set_player
                        (this_00,*(short *)(puVar35 + -0xc),puVar35[-8],puVar35[-4]);
              *(undefined4 *)(puVar35 + -4) = 0x4ac9e0;
              TRIBE_Screen_Sed::SavePlayerActiveStatus(this_00);
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar35 + -4) = 1;
              *(undefined4 *)(puVar35 + -8) = 0;
              *(uint *)(puVar35 + -0xc) = CONCAT22(extraout_var_01,sVar24);
              *(undefined4 *)(puVar35 + -0x10) = 0x4ac9f3;
              TRIBE_Screen_Sed::set_player
                        (this_00,*(short *)(puVar35 + -0xc),puVar35[-8],puVar35[-4]);
            }
          }
          if ((iVar25 == 1) &&
             (pTVar19 = (TRIBE_Main_View *)this_00->player_advance_civilization_drop,
             pTVar11 == pTVar19)) {
            *(undefined4 *)(puVar35 + -4) = 0x4aca0f;
            iVar28 = TDropDownPanel::currentLineNumber((TDropDownPanel *)pTVar19);
            sVar24 = this_00->player_num;
            *(int *)(puVar35 + -4) = iVar28;
            pTVar20 = (T_Scenario *)this_00->world->_padding_;
            *(int *)(puVar35 + -8) = sVar24 + -1;
            *(undefined4 *)(puVar35 + -0xc) = 0x4aca27;
            T_Scenario::SetPlayerAge(pTVar20,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
          }
          break;
        case ScenarioModeUnits:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 0) {
            if (this_00->valid_save_spot_flag != '\0') {
              this_00->need_to_save_flag = '\x01';
            }
            pTVar19 = (TRIBE_Main_View *)this_00->unit_player_list;
            if (pTVar11 == pTVar19) {
              *(undefined4 *)(puVar35 + -4) = 0x4aca69;
              lVar31 = TDropDownPanel::get_line((TDropDownPanel *)pTVar19);
              *(long *)(puVar35 + -4) = lVar31;
              *(undefined4 *)(puVar35 + -8) = 0x4aca71;
              TRIBE_Screen_Sed::set_unit_player(this_00,*(short *)(puVar35 + -4));
              pTVar9 = this_00->unit_player_list;
              *(undefined4 *)(puVar35 + -4) = 0x4aca7c;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              iVar28 = rge_base_game->_padding_;
              if (lVar31 != 0) {
                iVar25 = rge_base_game->game_mode;
                *(undefined4 *)(puVar35 + -4) = 4;
                *(int *)(puVar35 + -8) = iVar25;
                pcVar18 = *(code **)(iVar28 + 0x10);
                puVar46 = puVar35 + -0xc;
                *(undefined4 *)(puVar35 + -0xc) = 0x4acaa5;
                (*pcVar18)();
                pRVar22 = rge_base_game;
                if (rge_base_game->master_obj_id == -1) {
LAB_004acaf8:
                  *(undefined4 *)(puVar46 + -4) = 0;
                  *(undefined4 *)(puVar46 + -8) = 0;
                }
                else {
                  *(undefined4 *)(puVar46 + -4) = 0x4acaba;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  pRVar22 = rge_base_game;
                  if (pRVar27 == (RGE_Player *)0x0) goto LAB_004acaf8;
                  sVar24 = rge_base_game->master_obj_id;
                  *(undefined4 *)(puVar46 + -4) = 0x4acad0;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  pRVar22 = rge_base_game;
                  *(RGE_Player **)(puVar46 + -4) = pRVar27;
                  *(undefined4 *)(puVar46 + -8) = 0x4acadc;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  *(undefined4 *)(puVar46 + -8) =
                       *(undefined4 *)
                        (*(int *)(*(int *)(this_00->world->_padding_ + pRVar27->id * 4) + 0x24) +
                        sVar24 * 4);
                }
                pTVar16 = this_00->object_panel;
                *(undefined4 *)(puVar46 + -0xc) = 0x4acb07;
                TRIBE_Scenario_Editor_Panel_Object::set_master_info
                          (pTVar16,*(RGE_Master_Static_Object **)(puVar46 + -8),
                           *(TRIBE_Player **)(puVar46 + -4));
                *(undefined4 *)(puVar46 + -4) = 0x4acb0e;
                TRIBE_Screen_Sed::set_paint_object_mode(this_00);
                pTVar16 = this_00->object_panel;
                *(undefined4 *)(puVar46 + -4) = 2;
                pcVar18 = *(code **)(pTVar16->_padding_ + 0x20);
                puVar35 = puVar46 + -8;
                *(undefined4 *)(puVar46 + -8) = 0x4acb1d;
                (*pcVar18)();
                goto LAB_004abe5a;
              }
              iVar3 = rge_base_game->game_mode;
              *(undefined4 *)(puVar35 + -4) = 3;
              *(int *)(puVar35 + -8) = iVar3;
              pcVar18 = *(code **)(iVar28 + 0x10);
              puVar45 = (undefined4 *)(puVar35 + -0xc);
              puVar35 = puVar35 + -0xc;
              *puVar45 = 0x4aca94;
              (*pcVar18)();
            }
          }
          pRVar22 = rge_base_game;
          if ((iVar25 == 2) || (iVar25 == 1)) {
            pTVar19 = (TRIBE_Main_View *)this_00->unit_list;
            if (pTVar11 == pTVar19) {
              *(undefined4 *)(puVar35 + -4) = 0x4acb43;
              iVar25 = TTextPanel::currentLineNumber((TTextPanel *)pTVar19);
              *(int *)(puVar35 + -4) = iVar25;
              *(undefined4 *)(puVar35 + -8) = 0x4acb4b;
              TRIBE_Screen_Sed::set_unit(this_00,*(short *)(puVar35 + -4));
              if ((rge_base_game->game_mode != 8) && (rge_base_game->game_mode != 0x15)) {
                pTVar17 = this_00->unit_mode_select[0];
                *(undefined4 *)(puVar35 + -4) = 0x4acb6c;
                TButtonPanel::set_radio_button(pTVar17);
              }
              pRVar22 = rge_base_game;
              if (rge_base_game->master_obj_id == -1) {
LAB_004acbbf:
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0;
              }
              else {
                *(undefined4 *)(puVar35 + -4) = 0x4acb81;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                pRVar22 = rge_base_game;
                if (pRVar27 == (RGE_Player *)0x0) goto LAB_004acbbf;
                sVar24 = rge_base_game->master_obj_id;
                *(undefined4 *)(puVar35 + -4) = 0x4acb97;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                pRVar22 = rge_base_game;
                *(RGE_Player **)(puVar35 + -4) = pRVar27;
                *(undefined4 *)(puVar35 + -8) = 0x4acba3;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                *(undefined4 *)(puVar35 + -8) =
                     *(undefined4 *)
                      (*(int *)(*(int *)(this_00->world->_padding_ + pRVar27->id * 4) + 0x24) +
                      sVar24 * 4);
              }
              pTVar16 = this_00->object_panel;
              *(undefined4 *)(puVar35 + -0xc) = 0x4acbce;
              TRIBE_Scenario_Editor_Panel_Object::set_master_info
                        (pTVar16,*(RGE_Master_Static_Object **)(puVar35 + -8),
                         *(TRIBE_Player **)(puVar35 + -4));
              *(undefined4 *)(puVar35 + -4) = 0x4acbd5;
              TRIBE_Screen_Sed::set_paint_object_mode(this_00);
              pTVar16 = this_00->object_panel;
              *(undefined4 *)(puVar35 + -4) = 1;
              pcVar18 = *(code **)(pTVar16->_padding_ + 0x20);
              puVar47 = (undefined4 *)(puVar35 + -8);
              puVar35 = puVar35 + -8;
              *puVar47 = 0x4acbe4;
              (*pcVar18)();
              goto LAB_004abe5a;
            }
            if (iVar25 == 1) {
              if (pTVar11 == (TRIBE_Main_View *)this_00->unit_mode_select[0]) {
                *(undefined4 *)(puVar35 + -4) = 0x4acc01;
                TRIBE_Screen_Sed::set_paint_object_mode(this_00);
              }
              else if (pTVar11 == (TRIBE_Main_View *)this_00->unit_mode_select[1]) {
                *(undefined4 *)(puVar35 + -4) = 0x4acc19;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                *(undefined4 *)(puVar35 + -4) = 0x4acc20;
                RGE_Player::unselect_object(pRVar27);
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0xe;
                pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                puVar48 = (undefined4 *)(puVar35 + -0xc);
                puVar35 = puVar35 + -0xc;
                *puVar48 = 0x4acc2f;
                (*pcVar18)();
              }
              else if (pTVar11 == (TRIBE_Main_View *)this_00->unit_mode_select[2]) {
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0xf;
                pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                puVar49 = (undefined4 *)(puVar35 + -0xc);
                puVar35 = puVar35 + -0xc;
                *puVar49 = 0x4acc4b;
                (*pcVar18)();
              }
              else if (pTVar11 == (TRIBE_Main_View *)this_00->unit_mode_select[3]) {
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0x14;
                pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                puVar50 = (undefined4 *)(puVar35 + -0xc);
                puVar35 = puVar35 + -0xc;
                *puVar50 = 0x4acc6b;
                (*pcVar18)();
              }
            }
          }
          break;
        case ScenarioModeDiplomacy:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if ((iVar25 == 0) || (iVar25 == 1)) {
            if (pTVar11 == (TRIBE_Main_View *)this_00->Diplomacy_player_list) {
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar35 + -4) = 1;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][0]->_padding_ + 0x14);
              puVar52 = puVar35 + -8;
              *(undefined4 *)(puVar35 + -8) = 0x4acd23;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar52 + -4) = 1;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][1]->_padding_ + 0x14);
              puVar53 = puVar52 + -8;
              *(undefined4 *)(puVar52 + -8) = 0x4acd3c;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar53 + -4) = 1;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][2]->_padding_ + 0x14);
              puVar54 = puVar53 + -8;
              *(undefined4 *)(puVar53 + -8) = 0x4acd54;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar54 + -4) = 0;
              pcVar18 = *(code **)(this_00->Diplomacy_AlliedVictory[sVar24 + -1]->_padding_ + 0x14);
              puVar55 = puVar54 + -8;
              *(undefined4 *)(puVar54 + -8) = 0x4acd69;
              (*pcVar18)();
              pTVar9 = this_00->Diplomacy_player_list;
              *(undefined4 *)(puVar55 + -4) = 0x4acd74;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              sVar24 = (short)lVar31 + 1;
              *(undefined4 *)(puVar55 + -4) = 0;
              this_00->player_num = sVar24;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][0]->_padding_ + 0x14);
              puVar56 = puVar55 + -8;
              *(undefined4 *)(puVar55 + -8) = 0x4acd90;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar56 + -4) = 0;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][1]->_padding_ + 0x14);
              puVar57 = puVar56 + -8;
              *(undefined4 *)(puVar56 + -8) = 0x4acda9;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar57 + -4) = 0;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][2]->_padding_ + 0x14);
              puVar58 = puVar57 + -8;
              *(undefined4 *)(puVar57 + -8) = 0x4acdc1;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar58 + -4) = 1;
              pcVar18 = *(code **)(this_00->Diplomacy_AlliedVictory[sVar24 + -1]->_padding_ + 0x14);
              puVar35 = puVar58 + -8;
              *(undefined4 *)(puVar58 + -8) = 0x4acdd6;
              (*pcVar18)();
              pTVar9 = this_00->Diplomacy_player_list;
              *(undefined4 *)(puVar35 + -4) = 0x4acde1;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              *(long *)(puVar35 + -4) = lVar31;
              *(undefined4 *)(puVar35 + -8) = 0x4acde9;
              TRIBE_Screen_Sed::load_diplomacy_from_scenario(this_00,*(int *)(puVar35 + -4));
            }
            if (iVar25 == 1) {
              *(int *)(puVar35 + -4) = this_00->player_num + -1;
              *(undefined4 *)(puVar35 + -8) = 0x4acdfe;
              TRIBE_Screen_Sed::save_diplomacy_in_scenario(this_00,*(int *)(puVar35 + -4));
              goto LAB_004abe5a;
            }
          }
          break;
        case ScenarioModeVictory:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (((iVar25 == 0) || (iVar25 == 1)) &&
             (pTVar11 == (TRIBE_Main_View *)this_00->victory_player_list)) {
            *(int *)(puVar35 + -4) = this_00->CurrentVictory;
            *(undefined4 *)(puVar35 + -8) = 0x4ac0b7;
            TRIBE_Screen_Sed::save_victory_cond_in_scenario(this_00,*(int *)(puVar35 + -4));
            *(undefined4 *)(puVar35 + -4) = 0;
            *(undefined4 *)(puVar35 + -8) = 0x4ac0c0;
            TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar35 + -4));
            *(undefined4 *)(puVar35 + -4) = 0;
            *(undefined4 *)(puVar35 + -8) = 0;
            *(undefined4 *)(puVar35 + -0xc) = 0x4ac0cb;
            TRIBE_Screen_Sed::activate_victory_proper_fields
                      (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
            pTVar9 = this_00->victory_player_list;
            *(undefined4 *)(puVar35 + -4) = 0x4ac0d6;
            lVar31 = TDropDownPanel::get_line(pTVar9);
            sVar24 = (short)lVar31 + 1;
            this_00->player_num = sVar24;
            pTVar20 = (T_Scenario *)this_00->world->_padding_;
            *(int *)(puVar35 + -4) = sVar24 + -1;
            *(undefined4 *)(puVar35 + -8) = 0x4ac0f1;
            T_Scenario::SetSPWhich(pTVar20,*(int *)(puVar35 + -4));
            *(undefined4 *)(puVar35 + -4) = 0;
            this_00->CurrentVictory = 0;
            *(undefined4 *)(puVar35 + -8) = 0x4ac104;
            TRIBE_Screen_Sed::load_victory_cond_from_scenario(this_00,*(int *)(puVar35 + -4));
            *(undefined4 *)(puVar35 + -4) = 1;
            *(undefined4 *)(puVar35 + -8) = 0x4ac10d;
            TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar35 + -4));
            pTVar9 = this_00->victory_drop_down;
            *(undefined4 *)(puVar35 + -4) = 1;
            *(undefined4 *)(puVar35 + -8) = 0x4ac11a;
            lVar31 = TDropDownPanel::get_line(pTVar9);
            *(long *)(puVar35 + -8) = lVar31;
            *(undefined4 *)(puVar35 + -0xc) = 0x4ac122;
            TRIBE_Screen_Sed::activate_victory_proper_fields
                      (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
          }
          if ((iVar25 == 0) && (pTVar11 == (TRIBE_Main_View *)this_00->victory_amount_input)) {
            pTVar10 = this_00->bottom_panel;
            *(undefined4 *)(puVar35 + -4) = 0;
            *(undefined4 *)(puVar35 + -8) = 0x4ac13a;
            TPanel::set_curr_child(pTVar10,*(TPanel **)(puVar35 + -4));
          }
          if ((iVar25 == 2) &&
             (pTVar19 = (TRIBE_Main_View *)this_00->victory_drop_down, pTVar11 == pTVar19)) {
            *(undefined4 *)(puVar35 + -4) = 1;
            *(undefined4 *)(puVar35 + -8) = 0x4ac150;
            lVar31 = TDropDownPanel::get_line((TDropDownPanel *)pTVar19);
            *(long *)(puVar35 + -8) = lVar31;
            *(undefined4 *)(puVar35 + -0xc) = 0x4ac158;
            TRIBE_Screen_Sed::activate_victory_proper_fields
                      (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
          }
          if (iVar25 == 1) {
            if (pTVar11 != (TRIBE_Main_View *)this_00->victory_amount_input) {
              pTVar9 = this_00->victory_drop_down;
              *(undefined4 *)(puVar35 + -4) = 0x4ac178;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              pRVar22 = rge_base_game;
              if (pTVar11 == (TRIBE_Main_View *)this_00->victory_drop_down) {
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0;
                pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                puVar36 = (undefined4 *)(puVar35 + -0xc);
                puVar35 = puVar35 + -0xc;
                *puVar36 = 0x4ac193;
                (*pcVar18)();
                this_00->DestinationObject = (RGE_Static_Object *)0x0;
                this_00->SelectedObject = (RGE_Static_Object *)0x0;
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar35 + -4) = 0x4ac1aa;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                *(undefined4 *)(puVar35 + -4) = 0x4ac1b1;
                RGE_Player::unselect_object(pRVar27);
              }
              if (lVar31 == 2) {
                this_00->DestinationObject = (RGE_Static_Object *)0x0;
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar35 + -4) = 0x4ac1cb;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                *(undefined4 *)(puVar35 + -4) = 0x4ac1d2;
                RGE_Player::unselect_object(pRVar27);
              }
              if (pTVar11 == (TRIBE_Main_View *)this_00->victory_button_set_object) {
                this_00->SelectRegionFlag = SELECT_OBJECT;
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0x10;
                pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                puVar37 = (undefined4 *)(puVar35 + -0xc);
                puVar35 = puVar35 + -0xc;
                *puVar37 = 0x4ac1f2;
                (*pcVar18)();
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar35 + -4) = 0x4ac1fd;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                *(undefined4 *)(puVar35 + -4) = 0x4ac204;
                RGE_Player::unselect_object(pRVar27);
                pRVar59 = this_00->DestinationObject;
LAB_004ac2a8:
                pRVar22 = rge_base_game;
                if (pRVar59 != (RGE_Static_Object *)0x0) {
                  *(undefined4 *)(puVar35 + -4) = 0;
                  *(RGE_Static_Object **)(puVar35 + -8) = pRVar59;
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac2bd;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac2c4;
                  RGE_Player::select_one_object
                            (pRVar27,*(RGE_Static_Object **)(puVar35 + -8),*(int *)(puVar35 + -4));
                }
              }
              else {
                if (pTVar11 == (TRIBE_Main_View *)this_00->victory_button_set_destination) {
                  if (lVar31 != 1) {
                    this_00->SelectRegionFlag = SELECT_AREA;
                    pRVar22 = rge_base_game;
                    *(undefined4 *)(puVar35 + -4) = 0x4ac237;
                    pRVar27 = RGE_Base_Game::get_player(pRVar22);
                    *(undefined4 *)(puVar35 + -4) = 0x4ac23e;
                    RGE_Player::unselect_object(pRVar27);
                    pRVar22 = rge_base_game;
                    pRVar59 = this_00->SelectedObject;
                    if (pRVar59 != (RGE_Static_Object *)0x0) {
                      *(undefined4 *)(puVar35 + -4) = 0;
                      *(RGE_Static_Object **)(puVar35 + -8) = pRVar59;
                      *(undefined4 *)(puVar35 + -0xc) = 0x4ac255;
                      pRVar27 = RGE_Base_Game::get_player(pRVar22);
                      *(undefined4 *)(puVar35 + -0xc) = 0x4ac25c;
                      RGE_Player::select_one_object
                                (pRVar27,*(RGE_Static_Object **)(puVar35 + -8),
                                 *(int *)(puVar35 + -4));
                    }
                    pRVar22 = rge_base_game;
                    *(undefined4 *)(puVar35 + -4) = 0;
                    *(undefined4 *)(puVar35 + -8) = 0x11;
                    pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                    puVar38 = (undefined4 *)(puVar35 + -0xc);
                    puVar35 = puVar35 + -0xc;
                    *puVar38 = 0x4ac26a;
                    (*pcVar18)();
                    goto LAB_004abe5a;
                  }
                  if (pTVar11 == (TRIBE_Main_View *)this_00->victory_button_set_destination) {
                    this_00->SelectRegionFlag = SELECT_DEST_OBJECT;
                    pRVar22 = rge_base_game;
                    *(undefined4 *)(puVar35 + -4) = 0;
                    *(undefined4 *)(puVar35 + -8) = 0x10;
                    pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                    puVar39 = (undefined4 *)(puVar35 + -0xc);
                    puVar35 = puVar35 + -0xc;
                    *puVar39 = 0x4ac290;
                    (*pcVar18)();
                    pRVar22 = rge_base_game;
                    *(undefined4 *)(puVar35 + -4) = 0x4ac29b;
                    pRVar27 = RGE_Base_Game::get_player(pRVar22);
                    *(undefined4 *)(puVar35 + -4) = 0x4ac2a2;
                    RGE_Player::unselect_object(pRVar27);
                    pRVar59 = this_00->SelectedObject;
                    goto LAB_004ac2a8;
                  }
                }
                if ((pTVar11 != (TRIBE_Main_View *)this_00->victory_button_go_to_dest) ||
                   (lVar31 == 1)) {
                  pTVar19 = (TRIBE_Main_View *)this_00->victory_drop_down;
                  if (pTVar11 == pTVar19) {
                    *(undefined4 *)(puVar35 + -4) = 0;
                    *(undefined4 *)(puVar35 + -8) = 0x4ac3da;
                    lVar31 = TDropDownPanel::get_line((TDropDownPanel *)pTVar19);
                    *(long *)(puVar35 + -8) = lVar31;
                    *(undefined4 *)(puVar35 + -0xc) = 0x4ac3e2;
                    TRIBE_Screen_Sed::activate_victory_proper_fields
                              (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
                  }
                  iVar25 = 0;
                  ppTVar32 = this_00->victory_button;
                  do {
                    if ((pTVar11 == (TRIBE_Main_View *)*ppTVar32) &&
                       (this_00->CurrentVictory != iVar25)) {
                      pTVar9 = this_00->victory_drop_down;
                      *(undefined4 *)(puVar35 + -4) = 0;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac40b;
                      lVar31 = TDropDownPanel::get_line(pTVar9);
                      *(long *)(puVar35 + -8) = lVar31;
                      *(undefined4 *)(puVar35 + -0xc) = 0x4ac413;
                      TRIBE_Screen_Sed::activate_victory_proper_fields
                                (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
                      *(int *)(puVar35 + -4) = this_00->CurrentVictory;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac421;
                      TRIBE_Screen_Sed::save_victory_cond_in_scenario
                                (this_00,*(int *)(puVar35 + -4));
                      *(undefined4 *)(puVar35 + -4) = 0;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac42a;
                      TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar35 + -4));
                      pRVar22 = rge_base_game;
                      *(undefined4 *)(puVar35 + -4) = 0x4ac435;
                      pRVar27 = RGE_Base_Game::get_player(pRVar22);
                      *(undefined4 *)(puVar35 + -4) = 0x4ac43c;
                      RGE_Player::unselect_object(pRVar27);
                      *(int *)(puVar35 + -4) = iVar25;
                      this_00->CurrentVictory = iVar25;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac44a;
                      TRIBE_Screen_Sed::load_victory_cond_from_scenario
                                (this_00,*(int *)(puVar35 + -4));
                      *(undefined4 *)(puVar35 + -4) = 1;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac453;
                      TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar35 + -4));
                      pTVar9 = this_00->victory_drop_down;
                      *(undefined4 *)(puVar35 + -4) = 1;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac460;
                      lVar31 = TDropDownPanel::get_line(pTVar9);
                      *(long *)(puVar35 + -8) = lVar31;
                      *(undefined4 *)(puVar35 + -0xc) = 0x4ac468;
                      TRIBE_Screen_Sed::activate_victory_proper_fields
                                (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
                      pRVar22 = rge_base_game;
                      pRVar59 = this_00->SelectedObject;
                      if (pRVar59 != (RGE_Static_Object *)0x0) {
                        *(undefined4 *)(puVar35 + -4) = 0;
                        *(RGE_Static_Object **)(puVar35 + -8) = pRVar59;
                        *(undefined4 *)(puVar35 + -0xc) = 0x4ac480;
                        pRVar27 = RGE_Base_Game::get_player(pRVar22);
                        *(undefined4 *)(puVar35 + -0xc) = 0x4ac487;
                        RGE_Player::select_one_object
                                  (pRVar27,*(RGE_Static_Object **)(puVar35 + -8),
                                   *(int *)(puVar35 + -4));
                      }
                      pRVar22 = rge_base_game;
                      pRVar59 = this_00->DestinationObject;
                      if (pRVar59 != (RGE_Static_Object *)0x0) {
                        *(undefined4 *)(puVar35 + -4) = 0;
                        *(RGE_Static_Object **)(puVar35 + -8) = pRVar59;
                        *(undefined4 *)(puVar35 + -0xc) = 4899999;
                        pRVar27 = RGE_Base_Game::get_player(pRVar22);
                        *(undefined4 *)(puVar35 + -0xc) = 0x4ac4a6;
                        RGE_Player::select_one_object
                                  (pRVar27,*(RGE_Static_Object **)(puVar35 + -8),
                                   *(int *)(puVar35 + -4));
                      }
                    }
                    iVar25 = iVar25 + 1;
                    ppTVar32 = ppTVar32 + 1;
                  } while (iVar25 < 0xc);
                  iVar25 = *(int *)(puVar35 + 0x4c);
                  break;
                }
                pTVar11 = this_00->main_view;
                *(undefined4 *)(puVar35 + -4) = 1;
                *(undefined1 **)(puVar35 + -8) = puVar35 + 0x1c;
                *(undefined1 **)(puVar35 + -0xc) = puVar35 + 0x10;
                *(undefined1 **)(puVar35 + -0x10) = puVar35 + 0x18;
                *(undefined1 **)(puVar35 + -0x14) = puVar35 + 0x14;
                *(undefined4 *)(puVar35 + -0x18) = 0x4ac2ff;
                RGE_View::get_selection_area
                          ((RGE_View *)pTVar11,*(long **)(puVar35 + -0x14),
                           *(long **)(puVar35 + -0x10),*(long **)(puVar35 + -0xc),
                           *(long **)(puVar35 + -8),*(int *)(puVar35 + -4));
                iVar25 = *(int *)(puVar35 + 0x10);
                fVar21 = (float)iVar25;
                iVar28 = *(int *)(puVar35 + 0x14);
                iVar3 = *(int *)(puVar35 + 0x18);
                bVar61 = fVar21 != _DAT_00573ae8;
                iVar4 = *(int *)(puVar35 + 0x1c);
                *(float *)(puVar35 + 0x48) = (float)iVar3;
                *(float *)(puVar35 + 0x4c) = (float)iVar4;
                this_00->px1 = (float)iVar28;
                this_00->py1 = (float)iVar3;
                this_00->SelectRegionFlag = SELECT_OFF;
                this_00->px2 = (float)iVar25;
                this_00->py2 = (float)iVar4;
                if (bVar61) {
                  *(float *)(puVar35 + 0x50) = fVar21 - (fVar21 - (float)iVar28) * _DAT_00573aec;
                  *(float *)(puVar35 + 0x4c) =
                       *(float *)(puVar35 + 0x4c) -
                       (*(float *)(puVar35 + 0x4c) - *(float *)(puVar35 + 0x48)) * _DAT_00573aec;
                  *(undefined4 *)(puVar35 + -4) = *(undefined4 *)(puVar35 + 0x4c);
                  pRVar22 = rge_base_game;
                  *(undefined4 *)(puVar35 + -8) = *(undefined4 *)(puVar35 + 0x50);
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac398;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac39f;
                  RGE_Player::set_view_loc
                            (pRVar27,*(float *)(puVar35 + -8),*(float *)(puVar35 + -4));
                  *(undefined4 *)(puVar35 + -4) = 0x4ac3a8;
                  uVar26 = __ftol();
                  *(undefined4 *)(puVar35 + -4) = uVar26;
                  *(undefined4 *)(puVar35 + -8) = 0x4ac3b2;
                  uVar26 = __ftol();
                  pRVar22 = rge_base_game;
                  *(undefined4 *)(puVar35 + -8) = uVar26;
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac3be;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac3c5;
                  RGE_Player::set_map_loc(pRVar27,*(short *)(puVar35 + -8),*(short *)(puVar35 + -4))
                  ;
                }
              }
            }
            goto LAB_004abe5a;
          }
          break;
        case ScenarioModeVictoryMulti:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 1) {
            iVar28 = 0;
            ppTVar32 = this_00->victory_cond_type;
            do {
              if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
                *(undefined4 *)(puVar35 + -4) = 1;
                *(int *)(puVar35 + -8) = iVar28 + 1;
                *(undefined4 *)(puVar35 + -0xc) = 0x4accb1;
                TRIBE_Screen_Sed::set_mp_victory_type
                          (this_00,*(VictoryType *)(puVar35 + -8),*(int *)(puVar35 + -4));
                if (iVar28 != 4) {
                  pTVar7 = this_00->world;
                  *(undefined4 *)(puVar35 + -4) = 1;
                  pTVar20 = (T_Scenario *)pTVar7->_padding_;
                  *(undefined4 *)(puVar35 + -8) = 0x4accca;
                  T_Scenario::Set_Multi_Conquest(pTVar20,*(int *)(puVar35 + -4));
                  pTVar17 = this_00->victory_cond_on[0];
                  *(undefined4 *)(puVar35 + -4) = 1;
                  pcVar18 = *(code **)(pTVar17->_padding_ + 0xe0);
                  puVar51 = (undefined4 *)(puVar35 + -8);
                  puVar35 = puVar35 + -8;
                  *puVar51 = 0x4accdc;
                  (*pcVar18)();
                }
                goto LAB_004abe5a;
              }
              iVar28 = iVar28 + 1;
              ppTVar32 = ppTVar32 + 1;
            } while (iVar28 < 5);
          }
          break;
        case ScenarioModeOptions:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 1) {
            *(undefined4 *)(puVar35 + -4) = 0x4ace20;
            TRIBE_Screen_Sed::SaveDisabledItemsInScenario(this_00);
            *(undefined4 *)(puVar35 + -4) = 0x4ace27;
            TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(this_00);
            pTVar19 = (TRIBE_Main_View *)this_00->options_button[0];
            if (pTVar11 == pTVar19) {
              *(undefined4 *)(puVar35 + -4) = 0x4ace36;
              iVar28 = TButtonPanel::get_state((TButtonPanel *)pTVar19);
              pTVar7 = this_00->world;
              *(int *)(puVar35 + -4) = iVar28;
              *(undefined4 *)(puVar35 + -8) = 2;
              pTVar20 = (T_Scenario *)pTVar7->_padding_;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ace47;
              T_Scenario::SetScenarioOption(pTVar20,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
            }
          }
          break;
        case ScenarioModeMessages:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 1) {
            pTVar6 = this_00->message_input;
            *(long *)(puVar35 + -4) = this_00->current_message;
            *(undefined4 *)(puVar35 + -8) = 0x4abfad;
            pcVar29 = TEditPanel::get_input_buffer(pTVar6);
            pTVar7 = this_00->world;
            *(char **)(puVar35 + -8) = pcVar29;
            pRVar8 = (RGE_Scenario *)pTVar7->_padding_;
            *(undefined4 *)(puVar35 + -0xc) = 0x4abfbc;
            RGE_Scenario::Set_message(pRVar8,*(char **)(puVar35 + -8),*(long *)(puVar35 + -4));
            iVar28 = 0;
            ppTVar32 = this_00->message_button;
            do {
              if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
                this_00->current_message = iVar28;
                break;
              }
              iVar28 = iVar28 + 1;
              ppTVar32 = ppTVar32 + 1;
            } while (iVar28 < 5);
            pTVar7 = this_00->world;
            *(long *)(puVar35 + -4) = this_00->current_message;
            pRVar8 = (RGE_Scenario *)pTVar7->_padding_;
            *(undefined4 *)(puVar35 + -8) = 0x4abfee;
            pcVar29 = RGE_Scenario::Get_message(pRVar8,*(long *)(puVar35 + -4));
            pTVar6 = this_00->message_input;
            *(char **)(puVar35 + -4) = pcVar29;
            *(undefined4 *)(puVar35 + -8) = 0x4abffa;
            TEditPanel::set_text(pTVar6,*(char **)(puVar35 + -4));
            switch(this_00->current_message) {
            case 0:
              pTVar6 = this_00->message_input;
              *(undefined4 *)(puVar35 + -4) = 0xffffffff;
              *(undefined4 *)(puVar35 + -8) = 0x7770;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac022;
              TPanel::set_help_info
                        ((TPanel *)pTVar6,*(long *)(puVar35 + -8),*(long *)(puVar35 + -4));
              break;
            case 1:
              pTVar6 = this_00->message_input;
              *(undefined4 *)(puVar35 + -4) = 0xffffffff;
              *(undefined4 *)(puVar35 + -8) = 0x7771;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac039;
              TPanel::set_help_info
                        ((TPanel *)pTVar6,*(long *)(puVar35 + -8),*(long *)(puVar35 + -4));
              break;
            case 2:
              pTVar6 = this_00->message_input;
              *(undefined4 *)(puVar35 + -4) = 0xffffffff;
              *(undefined4 *)(puVar35 + -8) = 0x7772;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac050;
              TPanel::set_help_info
                        ((TPanel *)pTVar6,*(long *)(puVar35 + -8),*(long *)(puVar35 + -4));
              break;
            case 3:
              pTVar6 = this_00->message_input;
              *(undefined4 *)(puVar35 + -4) = 0xffffffff;
              *(undefined4 *)(puVar35 + -8) = 0x7773;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac067;
              TPanel::set_help_info
                        ((TPanel *)pTVar6,*(long *)(puVar35 + -8),*(long *)(puVar35 + -4));
              break;
            case 4:
              pTVar6 = this_00->message_input;
              *(undefined4 *)(puVar35 + -4) = 0xffffffff;
              *(undefined4 *)(puVar35 + -8) = 0x7774;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac07e;
              TPanel::set_help_info
                        ((TPanel *)pTVar6,*(long *)(puVar35 + -8),*(long *)(puVar35 + -4));
            }
          }
        }
        *(undefined4 *)(puVar35 + -4) = 0x4ace4e;
        pcVar29 = TPanel::panelName((TPanel *)pTVar11);
        if (pcVar29 != (char *)0x0) {
          pbVar60 = &s_QuitSaveDialog;
          *(undefined4 *)(puVar35 + -4) = 0x4ace62;
          pbVar30 = (byte *)TPanel::panelName((TPanel *)pTVar11);
          do {
            bVar5 = *pbVar30;
            bVar61 = bVar5 < *pbVar60;
            if (bVar5 != *pbVar60) {
LAB_004ace86:
              iVar28 = (1 - (uint)bVar61) - (uint)(bVar61 != 0);
              goto LAB_004ace8b;
            }
            if (bVar5 == 0) break;
            bVar5 = pbVar30[1];
            bVar61 = bVar5 < pbVar60[1];
            if (bVar5 != pbVar60[1]) goto LAB_004ace86;
            pbVar30 = pbVar30 + 2;
            pbVar60 = pbVar60 + 2;
          } while (bVar5 != 0);
          iVar28 = 0;
LAB_004ace8b:
          if (iVar28 == 0) {
            *(undefined4 *)(puVar35 + -4) = 0;
            *(char **)(puVar35 + -8) = s_Scenario_Editor_Screen;
            *(undefined4 *)(puVar35 + -0xc) = 0x4ace9f;
            TPanelSystem::setCurrentPanel
                      (&panel_system,*(char **)(puVar35 + -8),*(int *)(puVar35 + -4));
            *(undefined **)(puVar35 + -4) = &s_QuitSaveDialog;
            *(undefined4 *)(puVar35 + -8) = 0x4aceae;
            TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar35 + -4));
            pRVar22 = rge_base_game;
            if (iVar25 == 0) {
              *(undefined4 *)(puVar35 + -4) = 1;
              *(undefined4 *)(puVar35 + -8) = 0;
              *(undefined4 *)(puVar35 + -0xc) = 0x4acebc;
              TRIBE_Screen_Sed::command_save(this_00,puVar35[-8],puVar35[-4]);
            }
            else if (iVar25 == 1) {
              *(undefined4 *)(puVar35 + -4) = 0x4aced5;
              iVar25 = TRIBE_Game::start_menu((TRIBE_Game *)pRVar22);
              pRVar22 = rge_base_game;
              if (iVar25 == 0) {
                *(undefined4 *)(puVar35 + -4) = 0x4acee4;
                RGE_Base_Game::close(pRVar22);
              }
              else {
                *(char **)(puVar35 + -4) = s_Scenario_Editor_Screen;
                *(undefined4 *)(puVar35 + -8) = 0x4acef8;
                TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar35 + -4));
              }
            }
            goto LAB_004abe5a;
          }
        }
        *(undefined4 *)(puVar35 + -4) = 0x4acf04;
        pcVar29 = TPanel::panelName((TPanel *)pTVar11);
        if (pcVar29 != (char *)0x0) {
          pbVar60 = &s_OpenSaveDialog;
          *(undefined4 *)(puVar35 + -4) = 0x4acf18;
          pbVar30 = (byte *)TPanel::panelName((TPanel *)pTVar11);
          do {
            bVar5 = *pbVar30;
            bVar61 = bVar5 < *pbVar60;
            if (bVar5 != *pbVar60) {
LAB_004acf3c:
              iVar28 = (1 - (uint)bVar61) - (uint)(bVar61 != 0);
              goto LAB_004acf41;
            }
            if (bVar5 == 0) break;
            bVar5 = pbVar30[1];
            bVar61 = bVar5 < pbVar60[1];
            if (bVar5 != pbVar60[1]) goto LAB_004acf3c;
            pbVar30 = pbVar30 + 2;
            pbVar60 = pbVar60 + 2;
          } while (bVar5 != 0);
          iVar28 = 0;
LAB_004acf41:
          if (iVar28 == 0) {
            *(undefined4 *)(puVar35 + -4) = 0;
            *(char **)(puVar35 + -8) = s_Scenario_Editor_Screen;
            *(undefined4 *)(puVar35 + -0xc) = 0x4acf55;
            TPanelSystem::setCurrentPanel
                      (&panel_system,*(char **)(puVar35 + -8),*(int *)(puVar35 + -4));
            *(undefined **)(puVar35 + -4) = &s_OpenSaveDialog;
            *(undefined4 *)(puVar35 + -8) = 0x4acf64;
            TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar35 + -4));
            if (iVar25 == 0) {
              *(undefined4 *)(puVar35 + -4) = 2;
              *(undefined4 *)(puVar35 + -8) = 0;
              *(undefined4 *)(puVar35 + -0xc) = 0x4acf72;
              TRIBE_Screen_Sed::command_save(this_00,puVar35[-8],puVar35[-4]);
            }
            else if (iVar25 == 1) {
              *(undefined4 *)(puVar35 + -4) = 0x490;
              *(undefined4 *)(puVar35 + -8) = 0x4acf8a;
              this = (TRIBE_Screen_Sed_Open *)operator_new(*(uint *)(puVar35 + -4));
              *(TRIBE_Screen_Sed_Open **)(puVar35 + 0x4c) = this;
              *(undefined4 *)(puVar35 + 0x40) = 0;
              if (this != (TRIBE_Screen_Sed_Open *)0x0) {
                *(undefined4 *)(puVar35 + -4) = 0x4acfa4;
                TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this);
              }
              *(undefined4 *)(puVar35 + -4) = 0;
              *(char **)(puVar35 + -8) = s_Scenario_Editor_Open;
              *(undefined4 *)(puVar35 + 0x40) = 0xffffffff;
              *(undefined4 *)(puVar35 + -0xc) = 0x4acfbd;
              TPanelSystem::setCurrentPanel
                        (&panel_system,*(char **)(puVar35 + -8),*(int *)(puVar35 + -4));
            }
            goto LAB_004abe5a;
          }
        }
        *(undefined4 *)(puVar35 + -4) = 0x4acfc9;
        pcVar29 = TPanel::panelName((TPanel *)pTVar11);
        if (pcVar29 != (char *)0x0) {
          pbVar60 = &s_NewSaveDialog;
          *(undefined4 *)(puVar35 + -4) = 0x4acfdd;
          pbVar30 = (byte *)TPanel::panelName((TPanel *)pTVar11);
          do {
            bVar5 = *pbVar30;
            bVar61 = bVar5 < *pbVar60;
            if (bVar5 != *pbVar60) {
LAB_004ad001:
              iVar28 = (1 - (uint)bVar61) - (uint)(bVar61 != 0);
              goto LAB_004ad006;
            }
            if (bVar5 == 0) break;
            bVar5 = pbVar30[1];
            bVar61 = bVar5 < pbVar60[1];
            if (bVar5 != pbVar60[1]) goto LAB_004ad001;
            pbVar30 = pbVar30 + 2;
            pbVar60 = pbVar60 + 2;
          } while (bVar5 != 0);
          iVar28 = 0;
LAB_004ad006:
          if (iVar28 == 0) {
            *(undefined4 *)(puVar35 + -4) = 0;
            *(char **)(puVar35 + -8) = s_Scenario_Editor_Screen;
            *(undefined4 *)(puVar35 + -0xc) = 0x4ad01a;
            TPanelSystem::setCurrentPanel
                      (&panel_system,*(char **)(puVar35 + -8),*(int *)(puVar35 + -4));
            *(undefined **)(puVar35 + -4) = &s_NewSaveDialog;
            *(undefined4 *)(puVar35 + -8) = 0x4ad029;
            TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar35 + -4));
            pRVar22 = rge_base_game;
            if (iVar25 == 0) {
              *(undefined4 *)(puVar35 + -4) = 3;
              *(undefined4 *)(puVar35 + -8) = 0;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ad037;
              TRIBE_Screen_Sed::command_save(this_00,puVar35[-8],puVar35[-4]);
            }
            else if (iVar25 == 1) {
              *(undefined4 *)(puVar35 + -4) = 0;
              *(undefined4 *)(puVar35 + -8) = 0;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ad054;
              TRIBE_Game::start_scenario_editor
                        ((TRIBE_Game *)pRVar22,*(char **)(puVar35 + -8),*(int *)(puVar35 + -4));
            }
            goto LAB_004abe5a;
          }
        }
        uVar26 = 0;
        goto LAB_004abe5f;
      }
    }
  }
LAB_004abe5a:
  uVar26 = 1;
LAB_004abe5f:
  *unaff_FS_OFFSET = *(undefined4 *)(puVar35 + 0x38);
  return uVar26;
}

// --------------------------------------------------

// Function: FUN_004ad06e
// Address: 004ad06e
// XREFS: None
void FUN_004ad06e(void)
{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_EBP;
  
  puVar2 = (undefined4 *)0x20004ac0;
  cVar1 = '\r';
  puVar3 = puVar2;
  puRam20004ac0 = unaff_EBP;
  do {
    unaff_EBP = unaff_EBP + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = *unaff_EBP;
    cVar1 = cVar1 + -1;
  } while ('\0' < cVar1);
  uRam20004a88 = 0x20004ac0;
  puVar3 = (undefined4 *)0x20004a3a;
  uRam20004a3a = 0x20004ac0;
  cVar1 = '\v';
  do {
    puVar2 = puVar2 + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = *puVar2;
    cVar1 = cVar1 + -1;
  } while ('\0' < cVar1);
  uRam20004a0a = 0x20004a3a;
  return;
}

// --------------------------------------------------

// Function: FUN_004ae05a
// Address: 004ae05a
// XREFS: None
void __fastcall FUN_004ae05a(int param_1,int param_2,int param_3)
{
  char in_AL;
  int iVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  T_Scenario *pTVar5;
  int unaff_EBX;
  int unaff_EBP;
  int iVar6;
  int unaff_EDI;
  bool in_CF;
  bool in_ZF;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  long lStack_8;
  
  if (!in_CF && !in_ZF) {
    lStack_8 = 0x4ae044;
    T_Scenario::Set_Multi_Gold(*(T_Scenario **)(param_2 + 0x5c),unaff_EDI);
    return;
  }
  pcVar2 = (char *)(unaff_EBP + -0x2277ffb6 + unaff_EBX * 8);
  *pcVar2 = *pcVar2 + in_AL;
  *(char *)(unaff_EBP + -0x6fffb523) = *(char *)(unaff_EBP + -0x6fffb523) + (char)param_2 + -2;
  iVar1 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x684));
  if (iVar1 == 0) {
    pTVar5 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  else {
    pTVar5 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  T_Scenario::Set_victory_all_flag(pTVar5,(uint)(iVar1 != 0));
  iVar1 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x668));
  if ((iVar1 == 0) &&
     (iVar1 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x6f0)), iVar1 != 0)) {
    iVar1 = 0;
    pTVar5 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  else {
    iVar1 = 1;
    pTVar5 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  T_Scenario::Set_Multi_Conquest(pTVar5,iVar1);
  if (param_3 < 0) {
    return;
  }
  pcVar2 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x76c));
  iVar1 = atoi(pcVar2);
  lVar3 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x734));
  lVar4 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x740));
  iVar6 = lVar4 + 1;
  lVar4 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x738));
  RGE_View::get_selection_area
            (*(RGE_View **)(param_1 + 0x4c8),&iStack_14,&iStack_10,&iStack_c,&lStack_8,1);
  *(float *)(param_1 + 0x488) = (float)iStack_14;
  *(float *)(param_1 + 0x48c) = (float)iStack_10;
  *(float *)(param_1 + 0x490) = (float)iStack_c;
  *(float *)(param_1 + 0x494) = (float)lStack_8;
  T_Scenario::ClearSPVictoryCondition(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3);
  switch(lVar3) {
  case 1:
    if ((*(int *)(param_1 + 0x480) != 0) && (*(int *)(param_1 + 0x484) != 0)) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,3);
      T_Scenario::SetSPObject
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(RGE_Static_Object **)(param_1 + 0x480));
      T_Scenario::SetSPDestObjectID
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(RGE_Static_Object **)(param_1 + 0x484));
      return;
    }
    break;
  case 2:
    if (*(int *)(param_1 + 0x480) != 0) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,3);
      T_Scenario::SetSPObject
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(RGE_Static_Object **)(param_1 + 0x480));
      T_Scenario::SetSPRectangle
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(float *)(param_1 + 0x488),*(float *)(param_1 + 0x48c),*(float *)(param_1 + 0x490)
                 ,*(float *)(param_1 + 0x494));
      return;
    }
    break;
  case 3:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,2);
    T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar4);
    goto LAB_004ae57f;
  case 4:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,2);
    T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar4);
    T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar1);
    T_Scenario::SetSPRectangle
              (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
               *(float *)(param_1 + 0x488),*(float *)(param_1 + 0x48c),*(float *)(param_1 + 0x490),
               *(float *)(param_1 + 0x494));
    return;
  case 5:
    if (((0 < iVar6) && (iVar6 < 9)) && (iVar1 != 0)) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,1);
      T_Scenario::SetSPPlayerID(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar6);
      T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar4);
      T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar1);
      return;
    }
    break;
  case 6:
    if (*(int *)(param_1 + 0x480) != 0) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,1);
      T_Scenario::SetSPObject
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(RGE_Static_Object **)(param_1 + 0x480));
      return;
    }
    break;
  case 7:
    if ((0 < iVar6) && (iVar6 < 9)) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,1);
      T_Scenario::SetSPPlayerID(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar6);
      T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar4);
      T_Scenario::SetSPAllFlag(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,1);
      return;
    }
    break;
  case 8:
    if ((0 < iVar6) && (iVar6 < 9)) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,1);
      T_Scenario::SetSPPlayerID(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar6);
      return;
    }
    break;
  case 9:
    if (*(int *)(param_1 + 0x480) != 0) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,5);
      T_Scenario::SetSPObject
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(RGE_Static_Object **)(param_1 + 0x480));
      return;
    }
    break;
  case 10:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 0;
    goto LAB_004ae570;
  case 0xb:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 3;
    goto LAB_004ae570;
  case 0xc:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 1;
    goto LAB_004ae570;
  case 0xd:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 2;
    goto LAB_004ae570;
  case 0xe:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 4;
    goto LAB_004ae570;
  case 0xf:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    T_Scenario::SetSPAttribType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,5);
    lVar3 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x748));
    T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar3 + 1);
    return;
  case 0x10:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 6;
    goto LAB_004ae570;
  case 0x11:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,6);
    lVar3 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x744));
LAB_004ae570:
    T_Scenario::SetSPAttribType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar3);
LAB_004ae57f:
    T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar1);
    return;
  case 0x12:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,7);
    lVar3 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x74c));
    T_Scenario::SetSPAttribType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ae5cf
// Address: 004ae5cf
// XREFS: None
void FUN_004ae5cf(void)
{
  float *pfVar1;
  char cVar2;
  char extraout_AH;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  RGE_Static_Object *pRVar7;
  RGE_Static_Object *pRVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  int extraout_ECX;
  int iVar12;
  int extraout_EDX;
  int unaff_EBX;
  char *unaff_ESI;
  int unaff_EDI;
  char acStack_34 [44];
  int iStack_8;
  
  iStack_8 = 0x4ae5db;
  func_0xfd004ae1();
  *(char *)(unaff_EDI + -0x1e) = *(char *)(unaff_EDI + -0x1e) + extraout_AH;
  *(char *)(extraout_ECX + -0x4ffb51e) =
       *(char *)(extraout_ECX + -0x4ffb51e) + (char)extraout_EDX + -1;
  *(char *)(unaff_EBX + 0x4a) = *(char *)(unaff_EBX + 0x4a) + extraout_AH;
  *(char *)(unaff_EBX + 0x5004ae3) = *(char *)(unaff_EBX + 0x5004ae3) + extraout_AH;
  cVar2 = in(0x4a);
  *(char *)(extraout_EDX + -0x1d) = *(char *)(extraout_EDX + -0x1d) + cVar2;
  *(char *)(extraout_ECX + -0x66ffb51d) = *(char *)(extraout_ECX + -0x66ffb51d) + cVar2;
  in(0x4a);
  *(char *)(extraout_ECX + -0x36ffb51d) =
       *(char *)(extraout_ECX + -0x36ffb51d) + (char)((uint)(extraout_EDX + -2) >> 8);
  in(0x4a);
  iVar12 = CONCAT31((int3)((uint)(extraout_ECX + -1) >> 8),(char)(extraout_ECX + -1) + extraout_AH);
  in(0x4a);
  in(0x4a);
  *unaff_ESI = *unaff_ESI + (char)((uint)unaff_EBX >> 8);
  in(0x4a);
  *(char *)(unaff_EBX + -0x1b) = *(char *)(unaff_EBX + -0x1b) + (char)(extraout_EDX + -2);
  *(char *)(iVar12 + -0x6fffb51b) = *(char *)(iVar12 + -0x6fffb51b) + (char)unaff_EBX;
  iVar3 = T_Scenario::Get_victory_all_flag(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c));
  if (iVar3 == 0) {
    (**(code **)(**(int **)(iVar12 + 0x680) + 0xe0))(1);
    iVar4 = **(int **)(iVar12 + 0x684);
  }
  else {
    (**(code **)(**(int **)(iVar12 + 0x680) + 0xe0))(0);
    iVar4 = **(int **)(iVar12 + 0x684);
  }
  (**(code **)(iVar4 + 0xe0))(iVar3 != 0);
  iVar3 = iStack_8;
  if (-1 < iStack_8) {
    *(undefined4 *)(iVar12 + 0x480) = 0;
    *(undefined4 *)(iVar12 + 0x484) = 0;
    (**(code **)(**(int **)(*(int *)(iVar12 + 0x928) + 0x5c) + 8))();
    T_Scenario::SetSPWhich
              (*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),*(short *)(iVar12 + 0x4b8) + -1);
    iVar4 = T_Scenario::GetSPAmount(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    itoa(iVar4,acStack_34,10);
    TEditPanel::set_text(*(TEditPanel **)(iVar12 + 0x76c),acStack_34);
    iVar5 = T_Scenario::GetSPPlayerID(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    TDropDownPanel::set_line(*(TDropDownPanel **)(iVar12 + 0x740),iVar5 + -1);
    iVar5 = T_Scenario::GetSPObjectType(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(iVar12 + 0x738),iVar5);
    TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x738),lVar6);
    pRVar7 = T_Scenario::GetSPObject(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    pRVar8 = T_Scenario::GetSPDestObjectID(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    *(RGE_Static_Object **)(iVar12 + 0x480) = pRVar7;
    *(RGE_Static_Object **)(iVar12 + 0x484) = pRVar8;
    iVar5 = T_Scenario::GetSPVictoryType(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    iStack_8 = T_Scenario::GetSPAttribType(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    pfVar1 = (float *)(iVar12 + 0x490);
    T_Scenario::GetSPRectangle
              (*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3,(float *)(iVar12 + 0x488),
               (float *)(iVar12 + 0x48c),pfVar1,(float *)(iVar12 + 0x494));
    lVar6 = __ftol();
    lVar9 = __ftol();
    lVar10 = __ftol();
    lVar11 = __ftol();
    RGE_View::set_selection_area(*(RGE_View **)(iVar12 + 0x4c8),-1,-1,-1,-1);
    if (*pfVar1 != _DAT_00573af0) {
      RGE_View::set_selection_area(*(RGE_View **)(iVar12 + 0x4c8),lVar6,lVar9,lVar10,lVar11);
    }
    switch(iVar5) {
    case 0:
      iVar3 = 0;
      break;
    case 1:
      if (iVar4 == 0) {
        if (pRVar7 == (RGE_Static_Object *)0x0) {
          iVar3 = T_Scenario::GetSPAllFlag(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
          if (iVar3 == 0) {
            iVar3 = 8;
          }
          else {
            iVar3 = 7;
          }
        }
        else {
          iVar3 = 6;
        }
      }
      else {
        iVar3 = 5;
      }
      break;
    case 2:
      T_Scenario::GetSPRectangle
                (*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3,(float *)(iVar12 + 0x488),
                 (float *)(iVar12 + 0x48c),pfVar1,(float *)(iVar12 + 0x494));
      if (*pfVar1 <= (float)_DAT_00573af8) {
        iVar3 = 3;
      }
      else {
        iVar3 = 4;
      }
      break;
    case 3:
      if (pRVar8 == (RGE_Static_Object *)0x0) {
        iVar3 = 2;
      }
      else {
        iVar3 = 1;
      }
      break;
    case 4:
      switch(iStack_8) {
      case 0:
        iVar3 = 10;
        break;
      case 1:
        iVar3 = 0xc;
        break;
      case 2:
        iVar3 = 0xd;
        break;
      case 3:
        iVar3 = 0xb;
        break;
      case 4:
        iVar3 = 0xe;
        break;
      case 5:
        TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x734),0xf);
        iVar3 = T_Scenario::GetSPAmount(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
        TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x748),iVar3 + -1);
        return;
      case 6:
        iVar3 = 0x10;
        break;
      default:
        goto switchD_004ae82a_default;
      }
      break;
    case 5:
      if (pRVar7 == (RGE_Static_Object *)0x0) {
        return;
      }
      iVar3 = 9;
      break;
    case 6:
      TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x734),0x11);
      TDropDownPanel::setCurrentLineId(*(TDropDownPanel **)(iVar12 + 0x744),iStack_8);
      return;
    case 7:
      TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x734),0x12);
      TDropDownPanel::setCurrentLineId(*(TDropDownPanel **)(iVar12 + 0x74c),iStack_8);
      return;
    default:
      goto switchD_004ae82a_default;
    }
    TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x734),iVar3);
  }
switchD_004ae82a_default:
  return;
}

// --------------------------------------------------

// Function: FUN_004aec95
// Address: 004aec95
// XREFS: None
void FUN_004aec95(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}

// --------------------------------------------------

// Function: FUN_004af2d2
// Address: 004af2d2
// XREFS: None
void FUN_004af2d2(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004b8042
// Address: 004b8042
// XREFS: None
// [HELPER] s_Assyrian: "Assyrian"
// [HELPER] s_Babylonian: "Babylonian"
// [HELPER] s_Egyptian: "Egyptian"
// [HELPER] s_Greek: "Greek"
// [HELPER] s_Hittite: "Hittite"
// [HELPER] s_Isrealite: "Isrealite"
// [HELPER] s_Minoan: "Minoan"
// [HELPER] s_No_Culture: "No Culture"
// [HELPER] s_Phoenician: "Phoenician"
// [HELPER] s_Sumerian: "Sumerian"
undefined6 __fastcall FUN_004b8042(int param_1,undefined2 param_2,undefined4 param_3)
{
  char *pcVar1;
  char cVar2;
  undefined4 in_EAX;
  char cVar3;
  char cVar4;
  char cVar5;
  byte *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  char unaff_retaddr;
  
  LOCK();
  *(int *)(unaff_EDI + 0x4b) = unaff_EDI;
  UNLOCK();
  pcVar1 = (char *)(param_1 + -0x51ffb481);
  cVar2 = *pcVar1;
  *pcVar1 = *pcVar1 + (char)unaff_EBX;
  cVar4 = (char)param_2;
  cVar5 = (char)((ushort)param_2 >> 8);
  if (*pcVar1 != '\0' && SCARRY1(cVar2,(char)unaff_EBX) == *pcVar1 < '\0') {
    out(*unaff_ESI,param_2);
    param_2 = CONCAT11(cVar5,cVar4 + unaff_retaddr);
switchD_004b8079_caseD_4:
    return CONCAT24(param_2,s_Hittite);
  }
  pcVar1 = (char *)(unaff_EBP + -0x2dffb481);
  cVar2 = *pcVar1;
  cVar3 = (char)((uint)unaff_EBX >> 8);
  *pcVar1 = *pcVar1 + cVar3;
  if (*pcVar1 == '\0' || SCARRY1(cVar2,cVar3) != *pcVar1 < '\0') {
    cVar2 = (char)((uint)in_EAX >> 8);
    cVar3 = (char)param_1 + cVar2;
    if (cVar3 == '\0' || SCARRY1((char)param_1,cVar2) != cVar3 < '\0') {
      cVar2 = cVar5 * '\x02';
      param_2 = CONCAT11(cVar2,cVar4);
      if (cVar2 == '\0' || SCARRY1(cVar5,cVar5) != cVar2 < '\0') {
        cRam1a004b80 = cRam1a004b80 + (char)in_EAX;
        *unaff_EBX = *unaff_EBX | 0x90;
        switch(param_3) {
        case 0:
          return CONCAT24(param_2,s_Assyrian);
        case 1:
          return CONCAT24(param_2,s_Babylonian);
        case 2:
          return CONCAT24(param_2,s_Egyptian);
        case 3:
          return CONCAT24(param_2,s_Greek);
        case 4:
          goto switchD_004b8079_caseD_4;
        case 5:
          goto switchD_004b8079_caseD_5;
        case 6:
          goto switchD_004b8079_caseD_6;
        case 7:
          return CONCAT24(param_2,s_Phoenician);
        case 8:
          return CONCAT24(param_2,s_Sumerian);
        default:
          return CONCAT24(param_2,s_No_Culture);
        }
      }
      out(*unaff_ESI,param_2);
      param_2 = CONCAT11(cVar2,cVar4 + unaff_retaddr);
switchD_004b8079_caseD_6:
      return CONCAT24(param_2,s_Minoan);
    }
  }
  else {
    out(*unaff_ESI,param_2);
    param_2 = CONCAT11(cVar5,cVar4 + unaff_retaddr);
  }
switchD_004b8079_caseD_5:
  return CONCAT24(param_2,s_Isrealite);
}

// --------------------------------------------------

// Function: FUN_004b93fd
// Address: 004b93fd
// XREFS: None
// [HELPER] s_RGL_shape_draw: "RGL_shape_draw"
uchar __fastcall FUN_004b93fd(TShape *param_1,char *param_2)
{
  char *pcVar1;
  SLhape_File_Header *pSVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uchar *puVar5;
  char cVar6;
  long lVar7;
  DClipInfo_List *this;
  uchar uVar8;
  char *in_EAX;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  char cVar14;
  Shape_Header *pSVar12;
  uint uVar13;
  int unaff_EBX;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 unaff_EBP;
  char *unaff_ESI;
  undefined4 unaff_EDI;
  SLhape_File_Header *pSVar18;
  char in_CF;
  int unaff_retaddr;
  
  param_2[-0x6da4ffb5] = (param_2[-0x6da4ffb5] - (char)param_2) - in_CF;
  cVar14 = (char)((uint)param_2 >> 8);
  *unaff_ESI = *unaff_ESI + cVar14;
  cVar6 = (char)unaff_EBX;
  pcVar1 = (char *)((int)in_EAX * 5 + 0x4b);
  *pcVar1 = *pcVar1 + (char)((uint)param_1 >> 8);
  *param_2 = *param_2 + cVar6 + -2;
  *(char *)(unaff_EBX + -0x71) = *(char *)(unaff_EBX + -0x71) + cVar6 + -3;
  pcVar1 = (char *)((int)param_2 * 5 + -0x6d59ffb5);
  *pcVar1 = *pcVar1 + (char)in_EAX;
  *in_EAX = *in_EAX + cVar6 + -5;
  *(char *)(unaff_EBX + -0x74) = *(char *)(unaff_EBX + -0x74) + cVar6 + -6;
  unaff_ESI[-0x38ffb46e] = unaff_ESI[-0x38ffb46e] + cVar14;
  *in_EAX = *in_EAX + cVar6 + -8;
  *(char *)(unaff_EBX + -0x77) = *(char *)(unaff_EBX + -0x77) + cVar6 + -9;
  iVar15 = unaff_EBX + -10;
  iVar15 = CONCAT22((short)((uint)iVar15 >> 0x10),
                    CONCAT11((char)((uint)iVar15 >> 8) + (char)((uint)in_EAX >> 8),(char)iVar15));
  iVar16 = iVar15 + -1;
  *(char *)(iVar15 + -0x74ace315) = *(char *)(iVar15 + -0x74ace315) + (char)param_2 + -1;
  *(undefined4 *)(unaff_retaddr + -4) = unaff_EBP;
  *(char **)(unaff_retaddr + -8) = unaff_ESI;
  *(undefined4 *)(unaff_retaddr + -0xc) = unaff_EDI;
  *(undefined1 *)(unaff_retaddr + 7) = 0;
  if (iVar16 < 0) {
    return '\0';
  }
  *(char **)(unaff_retaddr + -0x10) = s_RGL_shape_draw;
  *(int *)(unaff_retaddr + -0x14) = iVar16;
  *(undefined4 *)(unaff_retaddr + -0x18) = 0x4b9465;
  uVar8 = TShape::Check_shape(param_1,*(long *)(unaff_retaddr + -0x14),
                              *(char **)(unaff_retaddr + -0x10));
  iVar10 = SDI_Draw_Level;
  if (uVar8 != '\0') {
    return '\0';
  }
  if (param_1->FShape != (SLhape_File_Header *)0x0) {
    if (SDI_Capture_Info != 0) {
      pSVar18 = param_1->FShape + iVar15;
      *(long *)(unaff_retaddr + -0x10) = SDI_Object_ID;
      *(int *)(unaff_retaddr + -0x14) = iVar10;
      *(undefined4 *)(unaff_retaddr + -0x18) = 0x4b949c;
      uVar9 = _ASMGet_Color_Xform();
      iVar15 = *(int *)(pSVar18->Comment + 0x10);
      *(undefined4 *)(unaff_retaddr + -0x18) = uVar9;
      lVar7 = fog_next_shape;
      *(undefined4 *)(unaff_retaddr + -0x1c) = *(undefined4 *)(unaff_retaddr + 0x38);
      iVar16 = *(int *)(pSVar18->Comment + 0x14);
      *(long *)(unaff_retaddr + -0x20) = lVar7;
      iVar10 = SDI_Draw_Line;
      *(int *)(unaff_retaddr + -0x24) = *(int *)(unaff_retaddr + 0x2c) - iVar16;
      pSVar2 = param_1->FShape;
      *(int *)(unaff_retaddr + -0x28) = *(int *)(unaff_retaddr + 0x28) - iVar15;
      *(int *)(unaff_retaddr + -0x2c) = iVar10;
      *(SLhape_File_Header **)(unaff_retaddr + -0x30) = pSVar18;
      *(SLhape_File_Header **)(unaff_retaddr + -0x34) = pSVar2;
      this = SDI_List;
      *(undefined4 *)(unaff_retaddr + -0x38) = 0x4b94d2;
      DClipInfo_List::AddDrawNode
                (this,*(void **)(unaff_retaddr + -0x34),*(Shape_Info **)(unaff_retaddr + -0x30),
                 *(int *)(unaff_retaddr + -0x2c),*(int *)(unaff_retaddr + -0x28),
                 *(int *)(unaff_retaddr + -0x24),*(int *)(unaff_retaddr + -0x20),
                 *(uchar **)(unaff_retaddr + -0x1c),*(int *)(unaff_retaddr + -0x18),
                 *(int *)(unaff_retaddr + -0x14),*(int *)(unaff_retaddr + -0x10));
      return '\x01';
    }
    iVar16 = *(int *)(unaff_retaddr + 0x24);
    iVar10 = *(int *)(iVar16 + 0xd0);
    iVar11 = *(int *)(*(int *)(iVar16 + 0xcc) + 0x50);
    iVar17 = *(int *)(iVar10 + 0x50);
    if (iVar11 < iVar17) {
      iVar17 = iVar11;
    }
    uVar9 = *(undefined4 *)(iVar16 + 0xc0);
    *(int *)(unaff_retaddr + -0x10) = iVar17 + -1;
    *(undefined4 *)(unaff_retaddr + -0x14) = *(undefined4 *)(iVar10 + 0x5c);
    uVar3 = *(undefined4 *)(iVar10 + 0x40);
    uVar4 = *(undefined4 *)(iVar10 + 0x3c);
    *(undefined4 *)(unaff_retaddr + -0x18) = 0;
    *(undefined4 *)(unaff_retaddr + -0x1c) = 0;
    *(undefined4 *)(unaff_retaddr + -0x20) = uVar3;
    *(undefined4 *)(unaff_retaddr + -0x24) = uVar4;
    *(undefined4 *)(unaff_retaddr + -0x28) = uVar9;
    *(undefined4 *)(unaff_retaddr + -0x2c) = 0x4b951b;
    _ASMSet_Surface_Info();
    if (*(int *)(unaff_retaddr + 0x38) != 0) {
      *(int *)(unaff_retaddr + -0x10) = *(int *)(unaff_retaddr + 0x38);
      *(undefined4 *)(unaff_retaddr + -0x14) = 0x4b952c;
      _ASMSet_Xlate_Table();
    }
    pSVar2 = param_1->FShape;
    *(long *)(unaff_retaddr + -0x10) = fog_next_shape;
    pSVar18 = pSVar2 + iVar15;
    uVar9 = *(undefined4 *)pSVar18->Version;
    *(long *)(unaff_retaddr + -0x14) = pSVar18->Num_Shapes;
    uVar3 = *(undefined4 *)(pSVar18->Comment + 0xc);
    iVar15 = *(int *)(pSVar18->Comment + 0x10);
    *(undefined4 *)(unaff_retaddr + -0x18) = uVar9;
    uVar9 = *(undefined4 *)(pSVar18->Comment + 8);
    *(undefined4 *)(unaff_retaddr + -0x1c) = uVar3;
    *(undefined4 *)(unaff_retaddr + -0x20) = uVar9;
    *(int *)(unaff_retaddr + -0x24) =
         *(int *)(unaff_retaddr + 0x2c) - *(int *)(pSVar18->Comment + 0x14);
    *(int *)(unaff_retaddr + -0x28) = *(int *)(unaff_retaddr + 0x28) - iVar15;
    *(SLhape_File_Header **)(unaff_retaddr + -0x2c) = pSVar2;
    *(undefined4 *)(unaff_retaddr + -0x30) = 0x4b956a;
    _ASMDraw_Sprite();
    ASM_Fast_Count = ASM_Fast_Count + 1;
    return '\x01';
  }
  iVar15 = *(int *)(unaff_retaddr + 0x24);
  *(undefined4 *)(unaff_retaddr + 0x10) = *(undefined4 *)(iVar15 + 0x28);
  *(undefined4 *)(unaff_retaddr + 0x14) = *(undefined4 *)(iVar15 + 0x2c);
  *(undefined4 *)(unaff_retaddr + 0x18) = *(undefined4 *)(iVar15 + 0x30);
  puVar5 = param_1->shape;
  *(undefined4 *)(unaff_retaddr + 0x1c) = *(undefined4 *)(iVar15 + 0x34);
  if (puVar5 == (uchar *)0x0) {
    return '\0';
  }
  iVar10 = *(int *)(unaff_retaddr + 0x28);
  pSVar12 = (Shape_Header *)(puVar5 + param_1->offsets[iVar16].shape);
  param_1->shape_header = pSVar12;
  iVar11 = pSVar12->ymin;
  iVar16 = pSVar12->ymax;
  iVar17 = pSVar12->xmax + *(int *)(unaff_retaddr + 0x28);
  iVar10 = pSVar12->xmin + iVar10;
  *(int *)(unaff_retaddr + 0x24) = iVar10;
  iVar16 = iVar16 + *(int *)(unaff_retaddr + 0x2c);
  iVar11 = iVar11 + *(int *)(unaff_retaddr + 0x2c);
  *(int *)(unaff_retaddr + 8) = iVar16;
  *(int *)(unaff_retaddr + 0x2c) = iVar11;
  *(int *)(unaff_retaddr + 0xc) = iVar17;
  *(int *)(unaff_retaddr + 0x28) = iVar17;
  if (iVar10 < *(int *)(unaff_retaddr + 0x10)) {
    *(int *)(unaff_retaddr + 0x24) = *(int *)(unaff_retaddr + 0x10);
  }
  if (iVar11 < *(int *)(unaff_retaddr + 0x14)) {
    *(int *)(unaff_retaddr + 0x2c) = *(int *)(unaff_retaddr + 0x14);
  }
  if (*(int *)(unaff_retaddr + 0x18) < iVar17) {
    *(int *)(unaff_retaddr + 0x28) = *(int *)(unaff_retaddr + 0x18);
  }
  if (*(int *)(unaff_retaddr + 0x1c) < *(int *)(unaff_retaddr + 8)) {
    iVar16 = *(int *)(unaff_retaddr + 0x1c);
  }
  if (*(int *)(unaff_retaddr + 0x24) < 0) {
    *(undefined4 *)(unaff_retaddr + 0x24) = 0;
  }
  if (*(int *)(unaff_retaddr + 0x2c) < 0) {
    *(undefined4 *)(unaff_retaddr + 0x2c) = 0;
  }
  iVar17 = *(int *)(unaff_retaddr + 0x28);
  if (*(int *)(iVar15 + 0x18) <= iVar17) {
    iVar17 = *(int *)(iVar15 + 0x18) + -1;
    *(int *)(unaff_retaddr + 0x28) = iVar17;
  }
  if (*(int *)(iVar15 + 0x1c) <= iVar16) {
    iVar16 = *(int *)(iVar15 + 0x1c) + -1;
  }
  if (iVar17 < *(int *)(unaff_retaddr + 0x24)) {
    return '\0';
  }
  iVar17 = *(int *)(unaff_retaddr + 0x2c);
  if (iVar16 < iVar17) {
    return '\0';
  }
  if ((*(int *)(unaff_retaddr + 0x24) == iVar10) && (iVar17 == iVar11)) {
    if ((*(int *)(unaff_retaddr + 0x28) == *(int *)(unaff_retaddr + 0xc)) &&
       (iVar16 == *(int *)(unaff_retaddr + 8))) {
      uVar13 = *(uint *)(unaff_retaddr + 0x34) & 0xff;
      if (uVar13 == 0) {
        *(undefined4 *)(unaff_retaddr + -0x10) = *(undefined4 *)(unaff_retaddr + 0x30);
        *(int *)(unaff_retaddr + -0x14) = iVar11;
        *(int *)(unaff_retaddr + -0x18) = iVar10;
        *(int *)(unaff_retaddr + -0x1c) = iVar15;
        *(undefined4 *)(unaff_retaddr + -0x20) = 0x4b9731;
        uVar8 = TShape::shape_draw_unclipped
                          (param_1,*(TDrawArea **)(unaff_retaddr + -0x1c),
                           *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                           *(long *)(unaff_retaddr + -0x10));
        return uVar8;
      }
      if (uVar13 == 1) {
        if (*(int *)(unaff_retaddr + 0x38) == 0) {
          *(undefined4 *)(unaff_retaddr + -0x10) = *(undefined4 *)(unaff_retaddr + 0x30);
          *(int *)(unaff_retaddr + -0x14) = iVar11;
          *(int *)(unaff_retaddr + -0x18) = iVar10;
          *(int *)(unaff_retaddr + -0x1c) = iVar15;
          *(undefined4 *)(unaff_retaddr + -0x20) = 0x4b96fe;
          uVar8 = TShape::shape_draw_unclipped
                            (param_1,*(TDrawArea **)(unaff_retaddr + -0x1c),
                             *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                             *(long *)(unaff_retaddr + -0x10));
          return uVar8;
        }
        *(int *)(unaff_retaddr + -0x10) = *(int *)(unaff_retaddr + 0x38);
        *(undefined4 *)(unaff_retaddr + -0x14) = *(undefined4 *)(unaff_retaddr + 0x30);
        *(int *)(unaff_retaddr + -0x18) = iVar11;
        *(int *)(unaff_retaddr + -0x1c) = iVar10;
        *(int *)(unaff_retaddr + -0x20) = iVar15;
        *(undefined4 *)(unaff_retaddr + -0x24) = 0x4b9718;
        uVar8 = TShape::shape_color_trans_unclipped
                          (param_1,*(TDrawArea **)(unaff_retaddr + -0x20),
                           *(long *)(unaff_retaddr + -0x1c),*(long *)(unaff_retaddr + -0x18),
                           *(long *)(unaff_retaddr + -0x14),*(uchar **)(unaff_retaddr + -0x10));
        return uVar8;
      }
      if (uVar13 == 2) {
        if (*(int *)(unaff_retaddr + 0x38) == 0) {
          *(undefined4 *)(unaff_retaddr + -0x10) = *(undefined4 *)(unaff_retaddr + 0x30);
          *(int *)(unaff_retaddr + -0x14) = iVar11;
          *(int *)(unaff_retaddr + -0x18) = iVar10;
          *(int *)(unaff_retaddr + -0x1c) = iVar15;
          *(undefined4 *)(unaff_retaddr + -0x20) = 0x4b96c8;
          uVar8 = TShape::shape_draw_unclipped
                            (param_1,*(TDrawArea **)(unaff_retaddr + -0x1c),
                             *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                             *(long *)(unaff_retaddr + -0x10));
          return uVar8;
        }
        *(int *)(unaff_retaddr + -0x10) = *(int *)(unaff_retaddr + 0x38);
        *(int *)(unaff_retaddr + -0x14) = iVar11;
        *(int *)(unaff_retaddr + -0x18) = iVar10;
        *(int *)(unaff_retaddr + -0x1c) = iVar15;
        *(undefined4 *)(unaff_retaddr + -0x20) = 0x4b96dd;
        uVar8 = TShape::shape_shadow_unclipped
                          (param_1,*(TDrawArea **)(unaff_retaddr + -0x1c),
                           *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                           *(uchar **)(unaff_retaddr + -0x10));
        return uVar8;
      }
      goto LAB_004b97cb;
    }
    iVar17 = *(int *)(unaff_retaddr + 0x2c);
  }
  uVar13 = *(uint *)(unaff_retaddr + 0x34) & 0xff;
  if (uVar13 != 0) {
    if (uVar13 == 1) {
      if (*(int *)(unaff_retaddr + 0x38) != 0) {
        *(int *)(unaff_retaddr + -0x10) = *(int *)(unaff_retaddr + 0x38);
        *(int *)(unaff_retaddr + -0x14) = iVar16;
        *(undefined4 *)(unaff_retaddr + -0x18) = *(undefined4 *)(unaff_retaddr + 0x28);
        *(int *)(unaff_retaddr + -0x1c) = iVar17;
        *(undefined4 *)(unaff_retaddr + -0x20) = *(undefined4 *)(unaff_retaddr + 0x24);
        *(undefined4 *)(unaff_retaddr + -0x24) = *(undefined4 *)(unaff_retaddr + 0x30);
        *(int *)(unaff_retaddr + -0x28) = iVar11;
        *(int *)(unaff_retaddr + -0x2c) = iVar10;
        *(int *)(unaff_retaddr + -0x30) = iVar15;
        *(undefined4 *)(unaff_retaddr + -0x34) = 0x4b97a1;
        uVar8 = TShape::shape_color_trans_clipped
                          (param_1,*(TDrawArea **)(unaff_retaddr + -0x30),
                           *(long *)(unaff_retaddr + -0x2c),*(long *)(unaff_retaddr + -0x28),
                           *(long *)(unaff_retaddr + -0x24),*(long *)(unaff_retaddr + -0x20),
                           *(long *)(unaff_retaddr + -0x1c),*(long *)(unaff_retaddr + -0x18),
                           *(long *)(unaff_retaddr + -0x14),*(uchar **)(unaff_retaddr + -0x10));
        return uVar8;
      }
    }
    else {
      if (uVar13 != 2) {
LAB_004b97cb:
        return *(uchar *)(unaff_retaddr + 7);
      }
      if (*(int *)(unaff_retaddr + 0x38) != 0) {
        *(int *)(unaff_retaddr + -0x10) = *(int *)(unaff_retaddr + 0x38);
        *(int *)(unaff_retaddr + -0x14) = iVar16;
        *(undefined4 *)(unaff_retaddr + -0x18) = *(undefined4 *)(unaff_retaddr + 0x28);
        *(int *)(unaff_retaddr + -0x1c) = iVar17;
        *(undefined4 *)(unaff_retaddr + -0x20) = *(undefined4 *)(unaff_retaddr + 0x24);
        *(int *)(unaff_retaddr + -0x24) = iVar11;
        *(int *)(unaff_retaddr + -0x28) = iVar10;
        *(int *)(unaff_retaddr + -0x2c) = iVar15;
        *(undefined4 *)(unaff_retaddr + -0x30) = 0x4b9773;
        uVar8 = TShape::shape_shadow_clipped
                          (param_1,*(TDrawArea **)(unaff_retaddr + -0x2c),
                           *(long *)(unaff_retaddr + -0x28),*(long *)(unaff_retaddr + -0x24),
                           *(long *)(unaff_retaddr + -0x20),*(long *)(unaff_retaddr + -0x1c),
                           *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                           *(uchar **)(unaff_retaddr + -0x10));
        return uVar8;
      }
    }
  }
  *(int *)(unaff_retaddr + -0x10) = iVar16;
  *(undefined4 *)(unaff_retaddr + -0x14) = *(undefined4 *)(unaff_retaddr + 0x28);
  *(int *)(unaff_retaddr + -0x18) = iVar17;
  *(undefined4 *)(unaff_retaddr + -0x1c) = *(undefined4 *)(unaff_retaddr + 0x24);
  *(int *)(unaff_retaddr + -0x20) = iVar11;
  *(int *)(unaff_retaddr + -0x24) = iVar10;
  *(int *)(unaff_retaddr + -0x28) = iVar15;
  *(undefined4 *)(unaff_retaddr + -0x2c) = 0x4b97c1;
  uVar8 = TShape::shape_draw_clipped
                    (param_1,*(TDrawArea **)(unaff_retaddr + -0x28),*(long *)(unaff_retaddr + -0x24)
                     ,*(long *)(unaff_retaddr + -0x20),*(long *)(unaff_retaddr + -0x1c),
                     *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                     *(long *)(unaff_retaddr + -0x10));
  return uVar8;
}

// --------------------------------------------------

// Function: FUN_004bf499
// Address: 004bf499
// XREFS: None
// [HELPER] s__d: "%d"
// [HELPER] s__d__: "%d%%"
// [HELPER] s__d__d: "%d+%d"
void __fastcall FUN_004bf499(char *param_1,undefined4 param_2)
{
  int iVar1;
  char cVar4;
  char *in_EAX;
  uchar *puVar2;
  void *pvVar3;
  uint uVar5;
  int *piVar6;
  char cVar7;
  int unaff_EBX;
  char *pcVar8;
  char in_CF;
  int iStack0000000c;
  char in_stack_00000010;
  undefined2 in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  undefined4 in_stack_00000030;
  int in_stack_00000034;
  int in_stack_00000038;
  
  iVar1 = in_stack_0000002c;
  cVar7 = (char)unaff_EBX;
  piVar6 = (int *)CONCAT22((short)((uint)param_2 >> 0x10),
                           CONCAT11(((char)((uint)param_2 >> 8) - cVar7) - in_CF,(char)param_2));
  cVar4 = (char)((uint)in_EAX >> 8);
  *param_1 = *param_1 + cVar4;
  cRam2c004bf3 = cRam2c004bf3 + cVar4;
  *(char *)piVar6 = (char)*piVar6 + cVar7 + -3;
  *(char *)piVar6 = (char)*piVar6 + cVar7 + -4;
  *(char *)piVar6 = (char)*piVar6 + cVar7 + -5;
  *(char *)(unaff_EBX + -0x12) = *(char *)(unaff_EBX + -0x12) + (char)((uint)(unaff_EBX + -6) >> 8);
  iStack0000000c = unaff_EBX + -7;
  *in_EAX = *in_EAX + (char)in_EAX;
  *piVar6 = (int)(in_EAX + *piVar6);
  if (((*(int *)(param_1 + 0x104) != 0) && (in_stack_0000002c != -1)) &&
     (puVar2 = TDrawArea::Lock(*(TDrawArea **)(param_1 + 0x20),(char *)0x0,1),
     puVar2 != (uchar *)0x0)) {
    TShape::shape_draw(*(TShape **)(param_1 + 0x104),*(TDrawArea **)(param_1 + 0x20),
                       *(int *)(param_1 + 0xc) + 0x3c,
                       *(int *)(param_1 + 0x10) + 0x1e + in_stack_00000028 * 0x12,iVar1,'\0',
                       (uchar *)0x0);
    TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),(char *)0x0);
  }
  switch(in_stack_00000030) {
  case 0:
    sprintf(&stack0x00000010,&s__d,in_stack_00000034);
    break;
  case 1:
    if (in_stack_00000034 < in_stack_00000038) {
      sprintf(&stack0x00000010,s__d__d,in_stack_00000034,in_stack_00000038 - in_stack_00000034);
    }
    else {
      sprintf(&stack0x00000010,&s__d,in_stack_00000034);
    }
    break;
  case 2:
    sprintf(&stack0x00000010,s__d__d,in_stack_00000034,in_stack_00000038);
    break;
  case 3:
    sprintf(&stack0x00000010,s__d__,in_stack_00000034);
    break;
  default:
    in_stack_00000010 = '\0';
  }
  if ((in_stack_00000010 != '\0') &&
     (pvVar3 = TDrawArea::GetDc(*(TDrawArea **)(param_1 + 0x20),(char *)0x0), pvVar3 != (void *)0x0)
     ) {
    SetBkMode(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),1);
    SetTextColor(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),0xffffff);
    SelectClipRgn(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),*(undefined4 *)(param_1 + 0x88));
    in_stack_00000034 =
         SelectObject(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),
                      *(undefined4 *)(param_1 + 0xf4));
    uVar5 = 0xffffffff;
    pcVar8 = &stack0x00000010;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar4 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar4 != '\0');
    TextOutA(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),*(int *)(param_1 + 0xc) + 100,
             *(int *)(param_1 + 0x10) + 0x20 + in_stack_00000028 * 0x12,&stack0x00000010,~uVar5 - 1)
    ;
    SelectObject(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),in_stack_00000034);
    SelectClipRgn(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),0);
    TDrawArea::ReleaseDc(*(TDrawArea **)(param_1 + 0x20),(char *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bf6a5
// Address: 004bf6a5
// XREFS: None
undefined4 __fastcall FUN_004bf6a5(TPanel *param_1,char param_2)
{
  int in_EAX;
  char unaff_BL;
  int unaff_EBP;
  int unaff_ESI;
  
  *(char *)(unaff_EBP + -0xb) = *(char *)(unaff_EBP + -0xb) + unaff_BL + -1;
  *(char *)(unaff_ESI + -0x4bffb40b) = *(char *)(unaff_ESI + -0x4bffb40b) + param_2;
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + param_2;
  TPanel::release_mouse(param_1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c218d
// Address: 004c218d
// XREFS: None
void __fastcall
FUN_004c218d(RGE_Static_Object *param_1,short param_2,TDrawArea *param_3,TDrawArea *param_4,
            short param_5)
{
  uint *puVar1;
  int in_EAX;
  int iVar2;
  short unaff_retaddr;
  short sVar3;
  
  iVar2 = in_EAX + -1;
  puVar1 = (uint *)(in_EAX + 0x5e + iVar2);
  *puVar1 = *puVar1 & (uint)param_1;
  puVar1 = (uint *)(in_EAX + 0x75 + iVar2);
  *puVar1 = *puVar1 & (uint)param_1;
  puVar1 = (uint *)(in_EAX + 0x75 + iVar2);
  *puVar1 = *puVar1 & (uint)param_1;
  puVar1 = (uint *)(in_EAX + -0x60 + iVar2);
  *puVar1 = *puVar1 & (uint)param_1;
  if (*puVar1 == 0) {
    RGE_Static_Object::draw_frame_3d_cube_front(param_1,param_4,param_2,unaff_retaddr);
    return;
  }
  sVar3 = (short)param_4;
  if (*(int *)(in_EAX + 0x1b3) == 1) {
    RGE_Static_Object::draw_frame_3d_cube_back(param_1,param_3,sVar3,param_5);
    return;
  }
  switch(*(undefined1 *)(in_EAX + 0x4f)) {
  case 1:
    RGE_Static_Object::draw_frame_3d_cube_back(param_1,param_3,sVar3,param_5);
    return;
  case 2:
  case 3:
    RGE_Static_Object::draw_frame_3d_square_back(param_1,param_3,sVar3,param_5);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c2206
// Address: 004c2206
// XREFS: None
void __fastcall FUN_004c2206(RGE_Static_Object *param_1,int *param_2)
{
  uint *puVar1;
  int iVar2;
  undefined4 in_EAX;
  int iVar3;
  char unaff_BL;
  undefined4 auStack_11 [2];
  short asStack_9 [2];
  undefined4 uStack_5;
  
  iVar2 = *param_2;
  iVar3 = CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX + unaff_BL);
  puVar1 = (uint *)(iVar3 * 2 + -0x11);
  *puVar1 = *puVar1 & (uint)param_1;
  puVar1 = (uint *)(iVar3 * 2 + -0x11);
  *puVar1 = *puVar1 & (uint)param_1;
  puVar1 = (uint *)(iVar3 * 2 + -0x70);
  *puVar1 = *puVar1 & (uint)param_1;
  if (SDI_Capture_Info != 0) {
    if (rge_base_game->game_mode == 1) {
      *(undefined4 *)((int)&uStack_5 + iVar2) = *(undefined4 *)(&stack0x0000000b + iVar2);
      *(undefined4 *)((int)asStack_9 + iVar2) = *(undefined4 *)(&stack0x00000007 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2 + 4) = *(undefined4 *)(&stack0x00000003 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2) = 0x4c224b;
      RGE_Static_Object::capture_frame_3d_cube
                (param_1,*(TDrawArea **)((int)auStack_11 + iVar2 + 4),
                 *(short *)((int)asStack_9 + iVar2),*(short *)((int)&uStack_5 + iVar2));
      return;
    }
    switch(rge_base_game->outline_type) {
    case '\0':
      *(undefined4 *)((int)&uStack_5 + iVar2) = *(undefined4 *)(&stack0x0000000b + iVar2);
      *(undefined4 *)((int)asStack_9 + iVar2) = *(undefined4 *)(&stack0x00000007 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2 + 4) = *(undefined4 *)(&stack0x00000003 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2) = 0x4c2275;
      RGE_Static_Object::capture_square_frame
                (param_1,*(TDrawArea **)((int)auStack_11 + iVar2 + 4),
                 *(short *)((int)asStack_9 + iVar2),*(short *)((int)&uStack_5 + iVar2));
      return;
    case '\x01':
      *(undefined4 *)((int)&uStack_5 + iVar2) = *(undefined4 *)(&stack0x0000000b + iVar2);
      *(undefined4 *)((int)asStack_9 + iVar2) = *(undefined4 *)(&stack0x00000007 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2 + 4) = *(undefined4 *)(&stack0x00000003 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2) = 0x4c228c;
      RGE_Static_Object::capture_frame_3d_cube
                (param_1,*(TDrawArea **)((int)auStack_11 + iVar2 + 4),
                 *(short *)((int)asStack_9 + iVar2),*(short *)((int)&uStack_5 + iVar2));
      return;
    case '\x02':
    case '\x03':
      *(undefined4 *)((int)&uStack_5 + iVar2) = *(undefined4 *)(&stack0x0000000b + iVar2);
      *(undefined4 *)((int)asStack_9 + iVar2) = *(undefined4 *)(&stack0x00000007 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2 + 4) = *(undefined4 *)(&stack0x00000003 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2) = 0x4c22a3;
      RGE_Static_Object::capture_frame_3d_square
                (param_1,*(TDrawArea **)((int)auStack_11 + iVar2 + 4),
                 *(short *)((int)asStack_9 + iVar2),*(short *)((int)&uStack_5 + iVar2));
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c22a6
// Address: 004c22a6
// XREFS: None
void FUN_004c22a6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,int param_8,short param_9)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *this;
  int iVar3;
  int iVar4;
  
  this = (RGE_Static_Object *)
         CONCAT31((int3)((uint)param_6 >> 8),
                  (byte)param_6 & *(byte *)(param_7 * 2 + 0x78) & *(byte *)(param_7 * 2 + -0x71) &
                  *(byte *)(param_7 * 2 + -0x71) & *(byte *)(param_7 * 2 + -0x70));
  param_5 = param_4;
  param_4 = param_2;
  param_3 = param_1;
  if ((this->sprite != (RGE_Sprite *)0x0) && (this->sprite_list != (RGE_Active_Sprite_List *)0x0)) {
    (**(code **)(this->sprite_list->_padding_ + 0x28))();
    iVar2 = RGE_Static_Object::get_frame
                      (this,(short *)&param_4,(short *)((int)&param_4 + 2),
                       (short *)((int)register0x00000010 + 0x16),(short *)&param_5);
    if (iVar2 != 0) {
      iVar3 = (int)(short)param_8;
      iVar2 = (short)param_4 + iVar3 + -1 + (int)this->screen_x_offset;
      iVar1 = (int)param_4._2_2_ + (int)param_9 + -1 + (int)this->screen_y_offset;
      param_8 = (int)(short)param_5 + (int)param_9 + 1 + (int)this->screen_y_offset;
      DClipInfo_List::AddGDINode
                (SDI_List,4,param_8,iVar2,iVar1,
                 param_5._2_2_ + iVar3 + 1 + (int)this->screen_x_offset,param_8,0,0,0,0,10,0xff,
                 SDI_Object_ID);
      if (this->object_state < 3) {
        iVar3 = __ftol();
        if (iVar3 < 1) {
          iVar3 = 0;
        }
        iVar4 = (int)this->master_obj->hp;
        if (0 < iVar4) {
          iVar3 = (iVar3 * 0x19) / iVar4 + iVar2;
          if (iVar2 + 0x1a <= iVar3) {
            iVar3 = iVar2 + 0x19;
          }
          DClipInfo_List::AddGDINode
                    (SDI_List,2,param_8,iVar2,iVar1 + -6,iVar2 + 0x1a,iVar1 + -1,iVar3,0,iVar3 + 1,0
                     ,0x14,0xff,SDI_Object_ID);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c3f65
// Address: 004c3f65
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_stat_obj_c: "C:\msdev\work\age1_x1\stat_obj.cpp"
void __fastcall FUN_004c3f65(int param_1,char *param_2)
{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  undefined4 in_EAX;
  byte bVar7;
  byte *pbVar6;
  int *piVar8;
  int iVar9;
  char cVar11;
  int unaff_EBX;
  uint uVar12;
  char *unaff_EDI;
  int iVar13;
  int iVar14;
  byte in_AF;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  short unaff_retaddr;
  short sStack00000004;
  int iStack00000008;
  int iStack0000000c;
  float in_stack_00000010;
  float in_stack_00000014;
  RGE_Sprite *pRVar15;
  undefined1 uStack_3;
  char cVar10;
  
  bVar7 = (byte)in_EAX / 0x3d;
  bVar3 = (byte)in_EAX % 0x3d;
  cVar11 = (char)unaff_EBX;
  *(char *)(param_1 + 0x3f) = *(char *)(param_1 + 0x3f) + cVar11;
  cVar10 = (char)((uint)param_1 >> 8) + (char)param_1;
  piVar8 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar10,(char)param_1));
  *(char *)((int)piVar8 + 0x3f) = *(char *)((int)piVar8 + 0x3f) + cVar11;
  unaff_EDI[0x3e] = unaff_EDI[0x3e] + bVar7;
  *(char *)((int)piVar8 + 0x3f) = *(char *)((int)piVar8 + 0x3f) + cVar11;
  *param_2 = *param_2 + cVar11;
  bVar2 = 9 < (bVar3 & 0xf) | in_AF;
  bVar4 = bVar3 + bVar2 * -6 & 0xf;
  *unaff_EDI = *unaff_EDI + cVar10;
  bVar3 = 9 < bVar4 | bVar2;
  uVar12 = CONCAT31((int3)((uint)in_EAX >> 8),bVar4 + bVar3 * -6) & 0xffff000f;
  pbVar6 = (byte *)(CONCAT22((short)(uVar12 >> 0x10),CONCAT11((bVar7 - bVar2) - bVar3,(char)uVar12))
                   + -0x7c6f6f70);
  bVar2 = *pbVar6;
  bVar3 = (byte)param_2;
  *pbVar6 = *pbVar6 + bVar3;
  in((short)param_2);
  *(char *)(unaff_EBX + 0x55) = (*(char *)(unaff_EBX + 0x55) - bVar3) - CARRY1(bVar2,bVar3);
  iVar9 = piVar8[2];
  iStack0000000c = -1;
  iStack00000008 = -1;
  if (*(short *)(iVar9 + 0x26) < 1) {
    return;
  }
  bVar2 = *(byte *)(iVar9 + 0x93);
  if (bVar2 == 0) {
    return;
  }
  _sStack00000004 = (int)*(short *)(iVar9 + 0x26);
  cVar10 = __ftol();
  bVar3 = 100 - cVar10;
  if (bVar3 == *(byte *)(piVar8 + 0xd)) {
    return;
  }
  iVar14 = -1;
  if ((bVar3 < 100) && (bVar2 != 0)) {
    iVar13 = 0;
    pbVar6 = (byte *)(*(int *)(iVar9 + 0x94) + 4);
    uVar12 = (uint)bVar2;
    do {
      if (*pbVar6 < bVar3) {
        iStack0000000c = iVar13;
      }
      if (*pbVar6 < *(byte *)(piVar8 + 0xd)) {
        iStack00000008 = iVar13;
      }
      iVar13 = iVar13 + 1;
      pbVar6 = pbVar6 + 8;
      uVar12 = uVar12 - 1;
      iVar14 = iStack0000000c;
    } while (uVar12 != 0);
  }
  if (iVar14 == iStack00000008) goto LAB_004c41b6;
  if (-1 < iVar14) {
    puVar1 = (undefined4 *)(*(int *)(piVar8[2] + 0x94) + iVar14 * 8);
    cVar10 = *(char *)((int)puVar1 + 5);
    if (cVar10 == '\0') {
      pRVar15 = (RGE_Sprite *)*puVar1;
      iVar9 = 0;
      iVar13 = 0;
    }
    else {
      if (cVar10 != '\x01') {
        if (cVar10 == '\x02') {
          (**(code **)(*piVar8 + 0x38))(*puVar1);
        }
        goto LAB_004c415b;
      }
      in_stack_00000010 = (float)debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x774);
      sVar5 = __ftol();
      in_stack_00000010 = (float)(int)sVar5;
      in_stack_00000014 =
           (float)(((float10)(float)piVar8[0xe] - (float10)(int)in_stack_00000010) + extraout_ST0);
      in_stack_00000010 = (float)debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x775);
      sVar5 = __ftol();
      in_stack_00000010 =
           (float)(((float10)(float)piVar8[0xf] - (float10)(int)sVar5) + extraout_ST0_00);
      RGE_Map::get_point(*(RGE_Map **)(*(int *)(piVar8[3] + 0x3c) + 0x28),&stack0x00000004,
                         (short *)&stack0x00000002,in_stack_00000014,in_stack_00000010,
                         (float)piVar8[0x10],0,0);
      iVar9 = (int)unaff_retaddr;
      iVar13 = (int)sStack00000004;
      pRVar15 = *(RGE_Sprite **)(*(int *)(piVar8[2] + 0x94) + iVar14 * 8);
    }
    RGE_Active_Sprite_List::add_sprite((RGE_Active_Sprite_List *)piVar8[6],pRVar15,'Z',iVar13,iVar9)
    ;
  }
LAB_004c415b:
  if (-1 < iStack00000008) {
    iVar9 = *(int *)(piVar8[2] + 0x94);
    bVar2 = *(byte *)(iVar9 + 5 + iStack00000008 * 8);
    if (bVar2 < 2) {
      RGE_Active_Sprite_List::remove_sprite
                ((RGE_Active_Sprite_List *)piVar8[6],*(RGE_Sprite **)(iVar9 + iStack00000008 * 8));
    }
    else if ((bVar2 == 2) &&
            ((iStack0000000c < 0 || (*(char *)(iVar9 + 5 + iStack0000000c * 8) != '\x02')))) {
      (**(code **)(*piVar8 + 0x38))(*(undefined4 *)(piVar8[2] + 0x18));
      *(undefined1 *)(piVar8 + 0xd) = uStack_3;
      return;
    }
  }
LAB_004c41b6:
  *(byte *)(piVar8 + 0xd) = bVar3;
  return;
}

// --------------------------------------------------

// Function: FUN_004c4b85
// Address: 004c4b85
// XREFS: None
void FUN_004c4b85(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004c66a2
// Address: 004c66a2
// XREFS: None
void FUN_004c66a2(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004cbccb
// Address: 004cbccb
// XREFS: None
void __fastcall FUN_004cbccb(char *param_1)
{
  undefined4 in_EAX;
  char unaff_BL;
  uint unaff_EDI;
  
  *(uint *)(param_1 + -0x449fffb4) = *(uint *)(param_1 + -0x449fffb4) | unaff_EDI;
  *param_1 = *param_1 + 'L';
  cRambcbb004c = cRambcbb004c + (char)((uint)in_EAX >> 8) + unaff_BL;
  halt_baddata();
}

// --------------------------------------------------

// Function: lines_intersect
// Address: 004cbd30
// XREFS: higher_check_for_cliff
int __cdecl
lines_intersect(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6,
               float param_7,float param_8)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_004cceb7
// Address: 004cceb7
// XREFS: None
undefined4 __fastcall FUN_004cceb7(int param_1,char *param_2)
{
  char cVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  char *pcVar10;
  char cVar12;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  uint uVar11;
  short sVar13;
  int unaff_EBX;
  int iVar14;
  int iVar15;
  undefined4 *unaff_ESI;
  uint uVar16;
  int iVar17;
  char *pcVar18;
  char in_OF;
  undefined8 uVar19;
  short sStack_1c;
  short sStack_18;
  int iStack_14;
  int iStack_4;
  
  pcVar10 = (char *)*unaff_ESI;
  pcVar6 = (code *)swi(4);
  if (in_OF == '\x01') {
    uVar19 = (*pcVar6)();
    param_2 = (char *)((ulonglong)uVar19 >> 0x20);
    pcVar10 = (char *)uVar19;
    param_1 = extraout_ECX;
  }
  param_2[-0x32] = param_2[-0x32] + (char)unaff_EBX;
  cVar1 = *param_2;
  cVar12 = (char)((uint)param_1 >> 8);
  *param_2 = *param_2 + cVar12;
  pcVar6 = (code *)swi(4);
  if (SCARRY1(cVar1,cVar12)) {
    pcVar10 = (char *)(*pcVar6)();
    param_1 = extraout_ECX_00;
  }
  pcVar18 = (char *)(unaff_EBX + -0x4dffb332);
  cVar1 = *pcVar18;
  *pcVar18 = *pcVar18 + (char)param_1;
  pcVar6 = (code *)swi(4);
  if (SCARRY1(cVar1,(char)param_1)) {
    pcVar10 = (char *)(*pcVar6)();
    param_1 = extraout_ECX_01;
  }
  *pcVar10 = *pcVar10 + (char)pcVar10;
  iVar14 = CONCAT31((int3)((uint)pcVar10 >> 8),(char)pcVar10 + '\b');
  piVar4 = (int *)((int)&iStack_4 + iVar14);
  *piVar4 = *piVar4 + iVar14;
  iVar14 = *(int *)(param_1 + 8);
  sStack_18 = __ftol();
  sVar7 = __ftol();
  sStack_1c = __ftol();
  sVar8 = __ftol();
  iVar14 = *(int *)(*(int *)(iVar14 + 0xc) + 0x3c);
  iVar3 = *(int *)(iVar14 + 0x28);
  sVar2 = *(short *)(iVar14 + 0x3c);
  uVar16 = (uint)sVar2;
  pcVar10 = (char *)calloc(uVar16,1);
  if (0 < sVar2) {
    pcVar18 = pcVar10;
    for (uVar11 = uVar16 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      pcVar18[0] = '\0';
      pcVar18[1] = '\0';
      pcVar18[2] = '\0';
      pcVar18[3] = '\0';
      pcVar18 = pcVar18 + 4;
    }
    for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
      *pcVar18 = '\0';
      pcVar18 = pcVar18 + 1;
    }
  }
  if (sStack_18 < 0) {
    sStack_18 = 0;
  }
  if (sVar7 < 0) {
    sVar7 = 0;
  }
  if (*(int *)(iVar3 + 8) <= (int)sStack_1c) {
    sStack_1c = *(short *)(iVar3 + 8) + -1;
  }
  if (*(int *)(iVar3 + 0xc) <= (int)sVar8) {
    sVar8 = *(short *)(iVar3 + 0xc) + -1;
  }
  if (sVar7 <= sVar8) {
    iStack_14 = sVar7 * 4;
    iVar14 = ((int)sVar8 - (int)sVar7) + 1;
    do {
      if (sStack_18 <= sStack_1c) {
        iVar17 = sStack_18 * 0x18;
        iVar15 = ((int)sStack_1c - (int)sStack_18) + 1;
        do {
          for (piVar4 = *(int **)(*(int *)(iStack_14 + *(int *)(iVar3 + 0x8d8c)) + 0x10 + iVar17);
              piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
            iVar5 = *piVar4;
            sVar7 = *(short *)(*(int *)(iVar5 + 8) + 0x14);
            if ((((sVar7 != 1) && (sVar7 != 0xb)) && (sVar7 != 0x1e)) &&
               (*(char *)(iVar5 + 0x48) == '\x02')) {
              pcVar10[*(short *)(*(int *)(iVar5 + 0xc) + 0x4a)] =
                   pcVar10[*(short *)(*(int *)(iVar5 + 0xc) + 0x4a)] + '\x01';
            }
          }
          iVar17 = iVar17 + 0x18;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      iStack_14 = iStack_14 + 4;
      iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
  }
  sVar9 = 1;
  sVar7 = -1;
  sVar13 = 0;
  pcVar18 = pcVar10;
  sVar8 = 0;
  if (1 < sVar2) {
    do {
      sVar13 = sVar8;
      if (pcVar18[1] != '\0') {
        sVar13 = sVar13 + 1;
        sVar7 = sVar9;
      }
      sVar9 = sVar9 + 1;
      pcVar18 = pcVar18 + 1;
      sVar8 = sVar13;
    } while (sVar9 < sVar2);
  }
  free(pcVar10);
  if (((sVar13 == 1) && (0 < sVar7)) &&
     (iVar14 = *(int *)(*(int *)(param_1 + 8) + 0xc), sVar7 != *(short *)(iVar14 + 0x4a))) {
    return *(undefined4 *)(*(int *)(*(int *)(iVar14 + 0x3c) + 0x40) + sVar7 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004cd5a5
// Address: 004cd5a5
// XREFS: None
// Error: 
Low-level Error: Symbol $$undef0000000d extends beyond the end of the address space

// --------------------------------------------------

// Function: FUN_004ce02d
// Address: 004ce02d
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_tact_cnv_c: "C:\msdev\work\age1_x1\tact_cnv.cpp"
undefined4 __fastcall FUN_004ce02d(int *param_1)
{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  float fVar4;
  char cVar5;
  int in_EAX;
  RGE_Static_Object *pRVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  float10 in_ST0;
  float10 in_ST1;
  float10 in_ST2;
  
  *(short *)(in_EAX * 2 + 0x77) =
       (short)(in_ST0 * (float10)*(short *)(in_EAX * 2 + 0x4a) *
              (float10)*(short *)(in_EAX * 2 + 0x19));
  *(short *)(in_EAX * 2 + -0x3b) = (short)(in_ST1 * (float10)*(short *)(in_EAX * 2 + -0x4b));
  *(short *)(in_EAX * 2 + 0x77) = (short)in_ST2;
  if ((param_1[6] != -1) &&
     (pRVar6 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(param_1[2] + 0xc) + 0x3c),param_1[6]),
     pRVar6 == (RGE_Static_Object *)0x0)) {
LAB_004ce0c6:
    iVar7 = *param_1;
    (**(code **)(iVar7 + 0x54))(0);
    (**(code **)(iVar7 + 0x5c))(3);
    return 0;
  }
  if ((param_1[7] != -1) &&
     (pRVar6 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(param_1[2] + 0xc) + 0x3c),param_1[7]),
     pRVar6 == (RGE_Static_Object *)0x0)) {
    (**(code **)(*param_1 + 0x58))(0);
  }
  iVar7 = param_1[4];
  if (iVar7 != 0) {
    if (*(char *)(iVar7 + 0x48) != '\x02') goto LAB_004ce0c6;
    if ((iVar7 != 0) &&
       (iVar7 = (**(code **)(**(int **)(param_1[2] + 0xc) + 0x1c))
                          ((int)*(short *)(*(int *)(iVar7 + 0xc) + 0x4a)), iVar7 == 1)) {
      cVar5 = (char)param_1[3];
      if ((cVar5 == '\a') || ((cVar5 == '\x06' || (cVar5 == '\x04')))) {
        (**(code **)(*(int *)param_1[2] + 0x80))(0x22,0);
      }
      (**(code **)(*param_1 + 0x5c))(1);
      iVar7 = ((int *)param_1[2])[1];
      (**(code **)(*(int *)param_1[2] + 0x148))(iVar7,iVar7,0x1fb,0x25c,0,0);
      return 4;
    }
  }
  switch((char)param_1[3]) {
  case '\x01':
    return 1;
  case '\x04':
    uVar8 = (**(code **)(*(int *)param_1[0xd] + 0xc))();
    switch((uVar8 & 0xff) - 1) {
    case 0:
    case 1:
      (**(code **)(*param_1 + 0x5c))(6);
      return 0;
    case 2:
      (**(code **)(*param_1 + 0x5c))(0xd);
      return 0;
    case 3:
    case 4:
switchD_004ce17c_caseD_3:
      iVar7 = *param_1;
      (**(code **)(iVar7 + 0x54))(0);
      (**(code **)(iVar7 + 0x5c))(0xb);
      return 0;
    }
    break;
  case '\x06':
    if (param_1[4] == 0) {
      (**(code **)(*param_1 + 0x5c))(3);
      return 0;
    }
    cVar5 = (**(code **)(*(int *)param_1[2] + 0x1f0))(param_1[4],0,0);
    if (cVar5 != '\0') {
      (**(code **)(*param_1 + 0x5c))(7);
      return 0;
    }
    break;
  case '\a':
    piVar2 = (int *)param_1[4];
    if (piVar2 == (int *)0x0) {
switchD_004ce17c_caseD_0:
      (**(code **)(*param_1 + 0x5c))(3);
      return 0;
    }
    uVar3 = *(undefined4 *)(param_1[2] + 4);
    iVar7 = *piVar2;
    uVar9 = __ftol((int)*(short *)(piVar2[2] + 0x26));
    (**(code **)(iVar7 + 0x148))(uVar3,piVar2[1],500,uVar3,uVar9);
    iVar7 = param_1[2];
    fVar4 = (float)param_1[0xb] - *(float *)(*(int *)(*(int *)(iVar7 + 0xc) + 0x3c) + 0x84);
    param_1[0xb] = (int)fVar4;
    if (fVar4 <= _DAT_00574ff8) {
      if ((param_1[4] != 0) &&
         (piVar2 = *(int **)(param_1[4] + 0xc), 0 < *(short *)((int)piVar2 + 0x4a))) {
        (**(code **)(*piVar2 + 0x94))
                  (0x70,*(undefined4 *)(iVar7 + 0x38),*(undefined4 *)(iVar7 + 0x3c),
                   *(undefined4 *)(iVar7 + 0x40),0);
      }
      iVar10 = debug_rand(s_C__msdev_work_age1_x1_tact_cnv_c,0x1d7);
      iVar7 = *(int *)(param_1[4] + 0xc);
      fVar4 = (float)iVar10 * _DAT_00574ffc;
      if (*(char *)(iVar7 + 0x105) == '\x10') {
        fVar4 = fVar4 * _DAT_00575000;
      }
      else {
        sVar1 = *(short *)(*(int *)(param_1[4] + 8) + 0x14);
        if ((((sVar1 == 0x15) || (sVar1 == 2)) || (sVar1 == 0x14)) ||
           ((sVar1 == 0x16 || (sVar1 == 0x12)))) {
          fVar4 = fVar4 + fVar4;
        }
        else if ((sVar1 == 0x23) || (sVar1 == 0x17)) {
          fVar4 = fVar4 * _DAT_00575004;
        }
      }
      if (fVar4 <= *(float *)(param_1[0xc] + 0x1c) * *(float *)(*(int *)(param_1[2] + 8) + 0xe4)) {
        (**(code **)(rge_base_game->_padding_ + 0x40))
                  (0x7b,(int)*(short *)(*(int *)(param_1[2] + 0xc) + 0x4a),
                   (int)*(short *)(iVar7 + 0x4a),0,0);
        (**(code **)(*(int *)param_1[4] + 0x44))(*(undefined4 *)(param_1[2] + 0xc));
        (**(code **)(**(int **)(param_1[2] + 0xc) + 0x78))(0x29,0x3f800000,0);
        (**(code **)(*(int *)param_1[2] + 0x80))(0x22,0);
        (**(code **)(*param_1 + 0x5c))(3);
      }
      (**(code **)(*param_1 + 0x5c))(4);
      return 0;
    }
    break;
  case '\v':
    uVar8 = (**(code **)(*(int *)param_1[0xd] + 0xc))();
    switch((uVar8 & 0xff) - 1) {
    case 0:
    case 1:
    case 4:
      goto switchD_004ce17c_caseD_0;
    case 2:
      (**(code **)(*param_1 + 0x5c))(0xd);
      return 0;
    case 3:
      goto switchD_004ce17c_caseD_3;
    }
    break;
  case '\r':
    iVar7 = ((int *)param_1[2])[1];
    (**(code **)(*(int *)param_1[2] + 0x148))(iVar7,iVar7,0x1f9,0x25c,0,0);
    (**(code **)(*param_1 + 0x5c))(2);
    return 3;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004ce3fa
// Address: 004ce3fa
// XREFS: None
int __fastcall FUN_004ce3fa(int param_1,int param_2)
{
  byte *pbVar1;
  byte bVar2;
  undefined4 in_EAX;
  char *pcVar3;
  int iVar4;
  int *piVar6;
  int iVar7;
  char cVar8;
  byte bVar10;
  undefined3 uVar11;
  int iVar12;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  char in_ZF;
  bool bVar13;
  int in_stack_00000010;
  char cVar5;
  char *pcVar9;
  
  iVar12 = -0x6bffb31d;
  piVar6 = (int *)(param_1 + -1);
  if (piVar6 == (int *)0x0 || in_ZF == '\0') {
    bVar2 = (byte)in_EAX;
    cVar5 = (char)((uint)in_EAX >> 8) + (char)((uint)piVar6 >> 8);
    pcVar3 = (char *)CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(cVar5,bVar2));
    piVar6 = (int *)(param_1 + -2);
    if (piVar6 != (int *)0x0 && cVar5 == '\0') goto code_r0x004ce453;
    cRam65004ce2 = cRam65004ce2 + (char)((uint)piVar6 >> 8);
    bVar13 = cRam65004ce2 == '\0';
    if (param_1 != 3 && bVar13) goto code_r0x004ce45b;
    cVar5 = bVar2 - 0x1d;
    bVar10 = (byte)((uint)param_2 >> 8);
    if (param_1 == 3) {
      *(char *)(unaff_EBP + 0x1a) = *(char *)(unaff_EBP + 0x1a) + bVar10 + (0x1c < bVar2);
      goto code_r0x004ce462;
    }
    uVar11 = (undefined3)((uint)param_2 >> 8);
    cVar8 = (char)param_2 + bVar10;
    pcVar9 = (char *)CONCAT31(uVar11,cVar8);
    if (param_1 != 3) {
      *pcVar3 = *pcVar3 + bVar2;
      *unaff_ESI = (int)(pcVar3 + *unaff_ESI);
      iVar4 = CONCAT31((int3)((uint)pcVar3 >> 8),bVar2 + *(char *)CONCAT31(0x94004c,cVar5) + '\x06')
              + 0x34ff8b90;
      if (param_1 != 4) {
        return iVar4;
      }
      *pcVar9 = *pcVar9 + bVar10;
      pcVar3 = (char *)CONCAT31(0x94004c,cVar5) + -0x4dffb31f;
      *pcVar3 = *pcVar3 + (char)iVar4;
      if (*pcVar3 != '\0') {
        *pcVar9 = *pcVar9 + bVar10;
        iVar12 = CONCAT31(0x94004c,cVar5 * '\x02');
        iVar7 = -2;
        if ((char)(cVar5 * '\x02') == '\0') {
          *(byte *)(iVar12 + 0x4e893c4f) = *(byte *)(iVar12 + 0x4e893c4f) & 0xfe;
          goto code_r0x004ce48f;
        }
        iVar12 = CONCAT31(0x94004c,cVar5 * '\x04');
        iVar7 = -3;
        if ((char)(cVar5 * '\x04') == '\0') goto code_r0x004ce48f;
        cVar8 = cVar8 + -3;
        param_2 = CONCAT31(uVar11,cVar8);
        iVar7 = -4;
        if (cVar8 == '\0') goto code_r0x004ce48f;
        pbVar1 = (byte *)(param_2 + -0x4dffb31f);
        bVar2 = *pbVar1;
        *pbVar1 = *pbVar1 + bVar10;
        piVar6 = (int *)&DAT_fffffffb;
        if (*pbVar1 == 0) {
          cVar5 = ((char)iVar4 + 'H') - CARRY1(bVar2,bVar10);
          piVar6 = (int *)CONCAT31((int3)((uint)iVar4 >> 8),cVar5);
          *piVar6 = (int)(*piVar6 + (int)piVar6);
          *(char *)piVar6 = (char)*piVar6 + cVar5;
          return 1;
        }
        goto code_r0x004ce44f;
      }
      goto LAB_004ce47c;
    }
    unaff_ESI = (int *)((int)unaff_ESI + 1);
    bVar2 = (bVar2 | 0x3c) + 0x74 ^ 0x3c;
code_r0x004ce469:
    if (bVar2 == 6) {
      return 1;
    }
    if (bVar2 == 7) {
      return 1;
    }
  }
  else {
code_r0x004ce44f:
    *(char *)(iVar12 + 0x56) = *(char *)(iVar12 + 0x56) + (char)param_2;
code_r0x004ce453:
    bVar13 = in_stack_00000010 == 0;
    unaff_ESI = piVar6;
    unaff_EDI = in_stack_00000010;
code_r0x004ce45b:
    if (bVar13) {
      return 0;
    }
    if (unaff_EDI == unaff_ESI[4]) {
code_r0x004ce462:
      bVar2 = *(byte *)(unaff_ESI + 3);
      if (bVar2 == 4) {
        return 1;
      }
      goto code_r0x004ce469;
    }
  }
LAB_004ce47c:
  iVar12 = *unaff_ESI;
  (**(code **)(iVar12 + 0x54))(unaff_EDI);
  unaff_ESI[8] = *(int *)(unaff_EDI + 0x38);
  iVar7 = *(int *)(unaff_EDI + 0x3c);
code_r0x004ce48f:
  unaff_ESI[9] = iVar7;
  unaff_ESI[10] = *(int *)(unaff_EDI + 0x40);
  (**(code **)(iVar12 + 0x1c))();
  return 1;
}

// --------------------------------------------------

// Function: FUN_004cecc6
// Address: 004cecc6
// XREFS: None
void FUN_004cecc6(void)
{
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_004cefd3
// Address: 004cefd3
// XREFS: None
undefined4 FUN_004cefd3(void)
{
  char *pcVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  int *piVar5;
  char cVar7;
  undefined2 uVar8;
  undefined3 uVar9;
  char cVar10;
  char *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  char *unaff_EDI;
  undefined8 uVar11;
  int iStack_20;
  char cVar6;
  
  uVar11 = func_0xe9004cef();
  pcVar2 = (char *)uVar11;
  cVar6 = (char)((uint)unaff_EBX >> 8);
  *unaff_EBX = *unaff_EBX + cVar6;
  uVar8 = (undefined2)((ulonglong)uVar11 >> 0x20);
  out(uVar8,(char)uVar11);
  pcVar2[-0x12] = pcVar2[-0x12] + cVar6;
  pcVar1 = (char *)(unaff_EBP * 9 + -0x105fffb4);
  *pcVar1 = *pcVar1 + cVar6;
  cVar6 = (char)((uint)extraout_ECX >> 8) + (char)extraout_ECX;
  piVar5 = (int *)CONCAT22((short)((uint)extraout_ECX >> 0x10),CONCAT11(cVar6,(char)extraout_ECX));
  out(uVar8,pcVar2);
  *pcVar2 = *pcVar2 + (char)uVar11;
  *unaff_ESI = (int)(pcVar2 + *unaff_ESI);
  in(uVar8);
  uVar9 = (undefined3)((ulonglong)uVar11 >> 0x28);
  cVar10 = (char)unaff_EBX;
  cVar7 = (char)((ulonglong)uVar11 >> 0x20) + cVar10;
  uVar8 = (undefined2)CONCAT31(uVar9,cVar7);
  uVar3 = in(uVar8);
  cRam07004cee = cRam07004cee + cVar10;
  out(uVar8,(char)uVar3);
  cVar7 = cVar7 + cVar10;
  uVar8 = (undefined2)CONCAT31(uVar9,cVar7);
  iVar4 = in(uVar8);
  *(char *)(unaff_ESI + unaff_EBP * 2) = (char)unaff_ESI[unaff_EBP * 2] + cVar6;
  *(char *)(unaff_ESI + unaff_EBP * 2) = (char)unaff_ESI[unaff_EBP * 2] + cVar6;
  cRam07004cee = cRam07004cee + cVar10;
  cVar6 = (char)iVar4;
  out(uVar8,cVar6);
  *unaff_EDI = *unaff_EDI + cVar6;
  out(uVar8,cVar6);
  *(char *)(iVar4 + -0x6f6f6f70) = *(char *)(iVar4 + -0x6f6f6f70) + cVar7;
  if (iStack_20 == 0) {
    return 0;
  }
  if (iStack_20 == piVar5[4]) {
    cVar6 = (char)piVar5[3];
    if (cVar6 == '\x04') {
      return 1;
    }
    if (cVar6 == '\x06') {
      return 1;
    }
    if (cVar6 == '\a') {
      return 1;
    }
  }
  iVar4 = *piVar5;
  (**(code **)(iVar4 + 0x54))(iStack_20);
  piVar5[8] = *(int *)(iStack_20 + 0x38);
  piVar5[9] = *(int *)(iStack_20 + 0x3c);
  piVar5[10] = *(int *)(iStack_20 + 0x40);
  (**(code **)(iVar4 + 0x1c))(1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004cfe93
// Address: 004cfe93
// XREFS: None
int __fastcall FUN_004cfe93(char *param_1,int param_2)
{
  char *pcVar1;
  short sVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  pcVar1 = (char *)(in_EAX * 2 + -0xc);
  *pcVar1 = *pcVar1 + -1;
  cVar6 = (char)((uint)param_1 >> 8);
  cVar7 = (char)unaff_EBX;
  cVar8 = (char)((uint)unaff_EBX >> 8) + cVar6;
  iVar3 = CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(cVar8,cVar7));
  cVar5 = (char)param_1;
  param_1[-0x53ffb302] = param_1[-0x53ffb302] + cVar5;
  *param_1 = *param_1 + cVar7;
  *(char *)(in_EAX + -4) = *(char *)(in_EAX + -4) + cVar8;
  param_1[-0x76ffb302] = param_1[-0x76ffb302] + cVar5;
  pcVar1 = (char *)(in_EAX * 2 + 0x5c);
  *pcVar1 = *pcVar1 + -1;
  *(char *)(unaff_EDI + -6) = *(char *)(unaff_EDI + -6) + (char)in_EAX;
  *(char *)(unaff_EDI + -2) = *(char *)(unaff_EDI + -2) + cVar7;
  param_1[0x5c004cfe] = param_1[0x5c004cfe] + cVar5;
  pcVar1 = (char *)(iVar3 + -0x54ffb307);
  *pcVar1 = *pcVar1 + cVar6;
  *(char *)(param_2 + -7) = *(char *)(param_2 + -7) + cVar8;
  pcVar1 = (char *)(iVar3 + 0x34004cf9);
  *pcVar1 = *pcVar1 + cVar6;
  pcVar1 = (char *)(param_2 + unaff_EDI * 8);
  *pcVar1 = *pcVar1 + (char)((uint)param_2 >> 8);
  cRam65004cfa = cRam65004cfa + cVar5;
  *(char *)(unaff_EBP + -6) = *(char *)(unaff_EBP + -6) + (char)((uint)in_EAX >> 8);
  *(char *)(unaff_EDI + -6) = *(char *)(unaff_EDI + -6) + cVar8;
  *(char *)(unaff_EDI + -6) = *(char *)(unaff_EDI + -6) + cVar8;
  param_1[0x65004cfa] = param_1[0x65004cfa] + cVar7;
  *(char *)(unaff_EDI + -6) = *(char *)(unaff_EDI + -6) + cVar8;
  *param_1 = *param_1 + cVar5;
  *param_1 = *param_1 + cVar5;
  pcVar1 = (char *)(unaff_ESI + -0x75);
  cVar7 = *pcVar1;
  *pcVar1 = *pcVar1 + (char)param_2;
  if (SCARRY1(cVar7,(char)param_2)) {
    if (((*(short *)(unaff_ESI + 0x14) != -1) &&
        (*(short *)(unaff_ESI + 0x14) ==
         *(short *)(*(int *)(CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar6 << 3,cVar5)) + 8
                            ) + 0x4c))) &&
       ((iVar3 = __ftol(), 0 < iVar3 && (*(int *)(unaff_ESI + 0x40) != 0)))) {
      return *(int *)(unaff_ESI + 0x40);
    }
    return *(int *)(unaff_ESI + 0x34);
  }
  iVar3 = *(int *)(unaff_ESI + 0x30);
  sVar2 = *(short *)(iVar3 + 0x14);
  if ((((sVar2 != -1) && (sVar2 == *(short *)(*(int *)(unaff_ESI + 8) + 0x4c))) &&
      (iVar4 = __ftol(), 0 < iVar4)) && (iVar3 = *(int *)(iVar3 + 0x40), iVar3 != 0)) {
    return iVar3;
  }
  return *(int *)(*(int *)(*(int *)(unaff_ESI + 8) + 8) + 0x18);
}

// --------------------------------------------------

// Function: FUN_004d0517
// Address: 004d0517
// XREFS: None
void __fastcall FUN_004d0517(int param_1,int param_2)
{
  int in_EAX;
  char cVar1;
  int unaff_EBP;
  
  cVar1 = (char)((uint)param_1 >> 8);
  (&stack0x0000004d)[in_EAX] = (&stack0x0000004d)[in_EAX] + cVar1;
  *(char *)(param_2 + -0x15ffb2ff) = *(char *)(param_2 + -0x15ffb2ff) + cVar1;
  *(int *)(unaff_EBP + -1) = *(int *)(unaff_EBP + -1) + param_1;
  *(char *)(param_2 + 2) = *(char *)(param_2 + 2) + cVar1;
  *(char *)(param_2 + -0x15ffb2fe) = *(char *)(param_2 + -0x15ffb2fe) + cVar1;
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_004d1533
// Address: 004d1533
// XREFS: None
// [HELPER] s_Stopping_Train__8___obj_id__d__o: "Stopping Train #8:  obj_id=%d, obj->id=%d, uniqueID=%d."
undefined4 __fastcall FUN_004d1533(int *param_1,int param_2)
{
  byte *pbVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  byte bVar5;
  undefined4 in_EAX;
  int unaff_EBP;
  bool in_CF;
  bool in_ZF;
  
  if (!in_CF && !in_ZF) {
    pbVar1 = (byte *)(param_2 + -0x1dffb2ed);
    bVar2 = *pbVar1;
    bVar5 = (byte)((uint)in_EAX >> 8);
    *pbVar1 = *pbVar1 + bVar5;
    param_1 = (int *)((int)param_1 + (uint)CARRY1(bVar2,bVar5) + *(int *)(unaff_EBP + -1));
  }
  piVar3 = *(int **)(param_1[2] + 0xc);
  (**(code **)(*piVar3 + 0xe4))
            (piVar3,s_Stopping_Train__8___obj_id__d__o,(int)(short)param_1[0x10],
             *(undefined4 *)(param_1[2] + 4),param_1[0x12]);
  if ((char)param_1[3] != '\x01') {
    (**(code **)(*param_1 + 0x5c))(1);
    if ((char)param_1[0x13] == '\0') {
      TRIBE_Player::reimburse_obj_cost(*(TRIBE_Player **)(param_1[2] + 0xc),(short)param_1[0x10]);
    }
  }
  (**(code **)(rge_base_game->_padding_ + 0x40))
            (0x67,(int)*(short *)(*(int *)(param_1[2] + 0xc) + 0x4a),(int)(short)param_1[0x10],0,0);
  iVar4 = ((int *)param_1[2])[1];
  (**(code **)(*(int *)param_1[2] + 0x148))(iVar4,iVar4,0x1f9,0x26b,0,0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d1b79
// Address: 004d1b79
// XREFS: None
undefined2 __fastcall FUN_004d1b79(uint param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  float fVar6;
  char cVar7;
  RGE_Static_Object *pRVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  short sVar12;
  ushort uVar13;
  undefined2 uVar15;
  byte *pbVar14;
  int *unaff_EBX;
  int unaff_EBP;
  uint *puVar16;
  int unaff_EDI;
  bool bVar17;
  float fVar18;
  undefined4 uVar19;
  
  *unaff_EBX = *unaff_EBX - (int)unaff_EBX;
  *(char *)(unaff_EDI + 0x1b) = *(char *)(unaff_EDI + 0x1b) + (char)param_2;
  puVar16 = (uint *)(unaff_EBP + -2);
  bVar17 = CARRY1((byte)((uint)param_2 >> 8),(byte)(param_1 >> 8));
  bVar1 = *(byte *)puVar16;
  bVar11 = *(byte *)puVar16 - (byte)param_1;
  *(byte *)puVar16 = bVar11 - bVar17;
  uVar4 = (uint)(bVar1 < (byte)param_1 || bVar11 < bVar17);
  uVar10 = *puVar16;
  uVar2 = *puVar16;
  *puVar16 = (uVar2 - param_1) - uVar4;
  uVar3 = (ushort)(uVar10 < param_1 || uVar2 - param_1 < uVar4);
  uVar5 = (ushort)param_1 - *(short *)puVar16;
  bVar17 = (ushort)param_1 < *(ushort *)puVar16 || uVar5 < uVar3;
  uVar15 = (undefined2)(param_1 >> 0x10);
  sVar12 = uVar5 - uVar3;
  bVar11 = (byte)sVar12;
  bVar1 = bVar11 - *(byte *)puVar16;
  uVar3 = (ushort)(bVar11 < *(byte *)puVar16 || bVar1 < bVar17);
  uVar13 = (ushort)CONCAT31((int3)(CONCAT22(uVar15,sVar12) >> 8),bVar1 - bVar17);
  uVar5 = uVar13 - *(short *)puVar16;
  sVar12 = ((uVar5 - uVar3) - *(short *)puVar16) -
           (ushort)(uVar13 < *(ushort *)puVar16 || uVar5 < uVar3);
  pbVar14 = (byte *)CONCAT22(uVar15,sVar12);
  bVar1 = *pbVar14;
  bVar11 = (byte)sVar12;
  *pbVar14 = *pbVar14 + bVar11;
  *(int *)(unaff_EBP + -3) = (*(int *)(unaff_EBP + -3) - (int)pbVar14) - (uint)CARRY1(bVar1,bVar11);
  uVar19 = 0xf6004d1a;
  if ((*(int *)(pbVar14 + 0x18) == -1) ||
     (pRVar8 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)(pbVar14 + 8) + 0xc) + 0x3c),
                          *(int *)(pbVar14 + 0x18)), pRVar8 != (RGE_Static_Object *)0x0)) {
    if ((*(int *)(pbVar14 + 0x1c) != -1) &&
       (pRVar8 = RGE_Game_World::object
                           (*(RGE_Game_World **)(*(int *)(*(int *)(pbVar14 + 8) + 0xc) + 0x3c),
                            *(int *)(pbVar14 + 0x1c)), pRVar8 == (RGE_Static_Object *)0x0)) {
      (**(code **)(*(int *)pbVar14 + 0x58))(0);
    }
    iVar9 = *(int *)(pbVar14 + 0x10);
    if ((iVar9 == 0) ||
       ((*(char *)(iVar9 + 0x48) == '\x02' &&
        ((iVar9 == 0 ||
         (iVar9 = (**(code **)(**(int **)(*(int *)(pbVar14 + 8) + 0xc) + 0x1c))
                            ((int)*(short *)(*(int *)(iVar9 + 0xc) + 0x4a),uVar19), iVar9 != 0))))))
{
      fVar18 = _DAT_00575278;
      switch(pbVar14[0xc] - 1) {
      case 0:
        return 1;
      case 3:
        uVar10 = (**(code **)(**(int **)(pbVar14 + 0x34) + 0xc))();
        switch((uVar10 & 0xff) - 1) {
        case 0:
        case 1:
        case 2:
          fVar18 = RGE_Static_Object::distance_to_object
                             (*(RGE_Static_Object **)(pbVar14 + 8),
                              *(RGE_Static_Object **)(pbVar14 + 0x10));
          DAT_0086bc08._0_4_ = fVar18 - _DAT_0057526c;
          if ((float)DAT_0086bc08 <= (float)_DAT_00575270) {
            (**(code **)(*(int *)pbVar14 + 0x5c))(6);
            return 0;
          }
          (**(code **)(*(int *)pbVar14 + 0x5c))(10);
          return 0;
        case 3:
        case 4:
          goto switchD_004d1c93_caseD_3;
        }
        break;
      case 5:
        if (*(int *)(pbVar14 + 0x10) == 0) {
          (**(code **)(*(int *)pbVar14 + 0x5c))(1);
          return 0;
        }
        cVar7 = (**(code **)(**(int **)(pbVar14 + 8) + 0x1f0))(*(int *)(pbVar14 + 0x10),0,0);
        if (cVar7 != '\0') {
          (**(code **)(*(int *)pbVar14 + 0x5c))(7);
          return 0;
        }
        break;
      case 6:
        pRVar8 = *(RGE_Static_Object **)(pbVar14 + 0x10);
        if (pRVar8 == (RGE_Static_Object *)0x0) {
          (**(code **)(*(int *)pbVar14 + 0x5c))(1);
          return 0;
        }
        if ((pRVar8->world_x != *(float *)(pbVar14 + 0x20)) ||
           (*(float *)(pbVar14 + 0x24) != pRVar8->world_y)) {
          fVar18 = RGE_Static_Object::distance_to_object
                             (*(RGE_Static_Object **)(pbVar14 + 8),pRVar8);
          DAT_0086bc08._0_4_ = fVar18 - _DAT_0057526c;
          if ((float)_DAT_00575270 < (float)DAT_0086bc08) {
            (**(code **)(*(int *)pbVar14 + 0x5c))(3);
            return 0;
          }
          iVar9 = *(int *)(pbVar14 + 0x10);
          *(undefined4 *)(pbVar14 + 0x20) = *(undefined4 *)(iVar9 + 0x38);
          *(undefined4 *)(pbVar14 + 0x24) = *(undefined4 *)(iVar9 + 0x3c);
          *(undefined4 *)(pbVar14 + 0x28) = *(undefined4 *)(iVar9 + 0x40);
          return 0;
        }
        cVar7 = (**(code **)(pRVar8->_padding_ + 0x8c))
                          (*(float *)(*(int *)(pbVar14 + 0x30) + 0x1c) *
                           *(float *)(*(int *)(*(int *)(*(int *)(pbVar14 + 8) + 0xc) + 0x3c) + 0x84)
                           * *(float *)(*(int *)(*(int *)(pbVar14 + 8) + 8) + 0xe4));
        if (cVar7 == '\x01') {
          (**(code **)(*(int *)pbVar14 + 0x5c))(1);
          return 0;
        }
        if (cVar7 == '\x02') {
          iVar9 = (*(int **)(pbVar14 + 8))[1];
          (**(code **)(**(int **)(pbVar14 + 8) + 0x148))(iVar9,iVar9,0x1fb,0x26a,0,0);
          (**(code **)(rge_base_game->_padding_ + 0x40))
                    (0x6b,(int)*(short *)(*(int *)(*(int *)(pbVar14 + 8) + 0xc) + 0x4a),
                     *(undefined4 *)(*(int *)(pbVar14 + 0x10) + 4),0,0);
          (**(code **)(*(int *)pbVar14 + 0x5c))(2);
          return 0;
        }
        break;
      case 9:
        if (*(RGE_Static_Object **)(pbVar14 + 0x10) != (RGE_Static_Object *)0x0) {
          fVar6 = *(float *)(pbVar14 + 0x2c) -
                  (*(RGE_Static_Object **)(pbVar14 + 8))->owner->world->world_time_delta_seconds;
          *(float *)(pbVar14 + 0x2c) = fVar6;
          if (fVar6 <= fVar18) {
            fVar18 = RGE_Static_Object::distance_to_object
                               (*(RGE_Static_Object **)(pbVar14 + 8),
                                *(RGE_Static_Object **)(pbVar14 + 0x10));
            DAT_0086bc08._0_4_ = fVar18 - _DAT_0057526c;
            if ((float)DAT_0086bc08 <= (float)_DAT_00575270) {
              (**(code **)(*(int *)pbVar14 + 0x5c))(6);
              return 0;
            }
            pbVar14[0x2c] = 0;
            pbVar14[0x2d] = 0;
            pbVar14[0x2e] = 0x80;
            pbVar14[0x2f] = 0x3f;
            return 0;
          }
        }
        break;
      case 10:
        uVar10 = (**(code **)(**(int **)(pbVar14 + 0x34) + 0xc))();
        switch((uVar10 & 0xff) - 1) {
        case 0:
        case 1:
        case 2:
        case 4:
          (**(code **)(*(int *)pbVar14 + 0x5c))(1);
          return 0;
        case 3:
          iVar9 = *(int *)pbVar14;
          (**(code **)(iVar9 + 0x54))(0);
          (**(code **)(iVar9 + 0x5c))(0xb);
          return 0;
        }
        break;
      case 0xc:
        iVar9 = (*(int **)(pbVar14 + 8))[1];
        (**(code **)(**(int **)(pbVar14 + 8) + 0x148))(iVar9,iVar9,0x1f9,0x26a,0,0);
        (**(code **)(*(int *)pbVar14 + 0x5c))(2);
        return 3;
      }
      return 0;
    }
  }
switchD_004d1c93_caseD_3:
  iVar9 = *(int *)pbVar14;
  (**(code **)(iVar9 + 0x54))(0);
  (**(code **)(iVar9 + 0x5c))(1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004d5567
// Address: 004d5567
// XREFS: None
undefined4 __fastcall
FUN_004d5567(BuildAIModule *param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            int param_6)
{
  char *pcVar1;
  int in_EAX;
  BuildItem *this;
  char cVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  pcVar1 = (char *)(unaff_EBX + 0x4d + param_2 * 2);
  *pcVar1 = *pcVar1 + (char)((uint)(in_EAX + -1) >> 8);
  cVar2 = (char)((uint)param_1 >> 8);
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  pcVar1 = (char *)((int)&param_1->_padding_ + 3);
  *pcVar1 = *pcVar1 + (char)unaff_EBX;
  *(char *)(unaff_EBX + 0x560c2444) = *(char *)(unaff_EBX + 0x560c2444) + (char)param_1;
  this = BuildAIModule::specificBuildListItem(param_1,in_EAX + -1);
  if (this != (BuildItem *)0x0) {
    BuildItem::setInProgress(this,0);
    BuildItem::setBuilt(this,1);
    BaseItem::setGameID((BaseItem *)this,param_6);
    BuildItem::incrementNumberBuilds(this);
  }
  TribeMainDecisionAIModule::detask((TribeMainDecisionAIModule *)param_1[1]._padding_,param_4);
  TribeTacticalAIModule::updateNeededResources
            ((TribeTacticalAIModule *)(param_1[1]._padding_ + 0x1146c));
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d595e
// Address: 004d595e
// XREFS: None
// Error: 
Low-level Error: Cannot properly adjust input varnodes

// --------------------------------------------------

// Function: $E12
// Address: 004d6ac0
// XREFS: None
void _E12(void)
{
  _E9();
  _E11();
  return;
}

// --------------------------------------------------

// Function: $E9
// Address: 004d6ad0
// XREFS: $E12
void _E9(void)
{
  InfluenceMap::InfluenceMap(&iMap,0xfe,0xfe,'\0');
  return;
}

// --------------------------------------------------

// Function: $E11
// Address: 004d6af0
// XREFS: $E12
void _E11(void)
{
  atexit(_E10);
  return;
}

// --------------------------------------------------

// Function: $E10
// Address: 004d6b00
// XREFS: $E11
void _E10(void)
{
  InfluenceMap::~InfluenceMap(&iMap);
  return;
}

// --------------------------------------------------

// Function: $E17
// Address: 004d6b10
// XREFS: None
void _E17(void)
{
  _E14();
  _E16();
  return;
}

// --------------------------------------------------

// Function: $E14
// Address: 004d6b20
// XREFS: $E17
void _E14(void)
{
  InfluenceMap::InfluenceMap(&losMap,0x32,0x32,'\0');
  return;
}

// --------------------------------------------------

// Function: $E16
// Address: 004d6b40
// XREFS: $E17
void _E16(void)
{
  atexit(_E15);
  return;
}

// --------------------------------------------------

// Function: $E15
// Address: 004d6b50
// XREFS: $E16
void _E15(void)
{
  InfluenceMap::~InfluenceMap(&losMap);
  return;
}

// --------------------------------------------------

// Function: $E22
// Address: 004d6b60
// XREFS: None
void _E22(void)
{
  _E19();
  _E21();
  return;
}

// --------------------------------------------------

// Function: $E19
// Address: 004d6b70
// XREFS: $E22
void _E19(void)
{
  InfluenceMap::InfluenceMap(&attackMap,0x32,0x32,'\0');
  return;
}

// --------------------------------------------------

// Function: $E21
// Address: 004d6b90
// XREFS: $E22
void _E21(void)
{
  atexit(_E20);
  return;
}

// --------------------------------------------------

// Function: $E20
// Address: 004d6ba0
// XREFS: $E21
void _E20(void)
{
  InfluenceMap::~InfluenceMap(&attackMap);
  return;
}

// --------------------------------------------------

// Function: FUN_004d90f1
// Address: 004d90f1
// XREFS: None
undefined4 __thiscall FUN_004d90f1(int param_1,uint param_2)
{
  byte bVar1;
  RGE_Static_Object *this;
  
  this = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),param_2);
  if (this != (RGE_Static_Object *)0x0) {
    bVar1 = RGE_Static_Object::currentZone(this);
    param_2 = (uint)bVar1;
    if (*(char *)(param_2 + 0x308 + param_1) == '\0') {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004da16d
// Address: 004da16d
// XREFS: None
undefined4 __fastcall FUN_004da16d(char *param_1,int param_2)
{
  char cVar1;
  undefined4 in_EAX;
  char unaff_BL;
  int unaff_EDI;
  char in_CF;
  char *pcVar2;
  
  cVar1 = (char)((uint)in_EAX >> 8);
  param_1[-0x5e9bffb3] = param_1[-0x5e9bffb3] + cVar1 + in_CF;
  param_1[0x4d] = param_1[0x4d] + cVar1;
  *(char *)(unaff_EDI + -0x5f) = *(char *)(unaff_EDI + -0x5f) + cVar1;
  *(char *)(unaff_EDI + -0x5f) = *(char *)(unaff_EDI + -0x5f) + cVar1;
  cVar1 = (char)((uint)param_1 >> 8);
  *(char *)(param_2 + -0x5f) = *(char *)(param_2 + -0x5f) + cVar1;
  *(char *)(param_2 + -0x5f) = *(char *)(param_2 + -0x5f) + cVar1;
  *param_1 = *param_1 + unaff_BL;
  cVar1 = (char)uRamb983004d + '\x01';
  pcVar2 = (char *)CONCAT31((int3)((uint)uRamb983004d >> 8),cVar1);
  *pcVar2 = *pcVar2 + cVar1;
  *(undefined4 *)(param_1 + 0x104) =
       *(undefined4 *)
        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x1256c) + 0x3c) + 0x28) + 8);
  return *(undefined4 *)(param_1 + 0x104);
}

// --------------------------------------------------

// Function: FUN_004de8eb
// Address: 004de8eb
// XREFS: None
undefined4 __fastcall FUN_004de8eb(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)
{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  char *unaff_EBX;
  char *unaff_EDI;
  
  cVar1 = (char)in_EAX;
  out(0x4d,cVar1);
  *unaff_EDI = *unaff_EDI + (char)((uint)param_2 >> 8);
  out(0x4d,cVar1);
  unaff_EDI[0x4d] = unaff_EDI[0x4d] + (char)param_1;
  *unaff_EBX = *unaff_EBX + cVar1;
  out(0x4d,in_EAX);
  unaff_EDI[0x4d] = unaff_EDI[0x4d] + (char)param_1;
  unaff_EDI[0x4de7] = unaff_EDI[0x4de7] + (char)((uint)unaff_EBX >> 8);
  iVar2 = 0;
  if (0 < param_1[1]) {
    while (iVar2 < param_1[3]) {
      if (*(int *)(*param_1 + iVar2 * 4) == *param_4) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      if (param_1[1] <= iVar2) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e0165
// Address: 004e0165
// XREFS: None
void __fastcall
FUN_004e0165(byte *param_1,char *param_2,char param_3,char param_4,undefined1 param_5)
{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int in_EAX;
  byte *pbVar5;
  uint *puVar6;
  int *piVar7;
  void *pvVar8;
  undefined1 *puVar9;
  byte bVar10;
  int iVar12;
  byte bVar13;
  int iVar14;
  byte *unaff_EBX;
  uint *unaff_ESI;
  bool bVar15;
  bool bVar16;
  int unaff_retaddr;
  int iVar11;
  
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  uVar3 = *unaff_ESI;
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  pbVar5 = (byte *)((in_EAX + -0x5a009c02) - (uint)CARRY4(uVar3,(uint)param_1) & 0x1d004e01);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  bVar1 = *pbVar5;
  bVar13 = (byte)param_2;
  *pbVar5 = *pbVar5 + bVar13;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,CARRY1(bVar1,bVar13));
  *pbVar5 = *pbVar5 + bVar13 + CARRY1(bVar1,bVar13);
  bVar10 = (byte)pbVar5;
  bVar16 = CARRY1(*param_1,bVar10) || CARRY1(*param_1 + bVar10,bVar15);
  *param_1 = *param_1 + bVar10 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar1 = *pbVar5;
  bVar2 = *pbVar5;
  *pbVar5 = bVar2 + bVar13 + bVar15;
  *param_2 = *param_2 + bVar10 + (CARRY1(bVar1,bVar13) || CARRY1(bVar2 + bVar13,bVar15));
  pbVar5 = pbVar5 + *(int *)(pbVar5 + (int)param_2);
  puVar6 = (uint *)(pbVar5 + 0x10101010);
  bVar1 = (byte)*puVar6 + bVar13;
  bVar15 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,(byte *)0xefefefef < pbVar5);
  *(byte *)puVar6 = bVar1 + ((byte *)0xefefefef < pbVar5);
  bVar1 = (byte)*puVar6 + bVar13;
  bVar16 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar15);
  *(byte *)puVar6 = bVar1 + bVar15;
  bVar10 = (byte)param_1;
  bVar1 = (byte)*puVar6 + bVar10;
  bVar15 = CARRY1((byte)*puVar6,bVar10) || CARRY1(bVar1,bVar16);
  *(byte *)puVar6 = bVar1 + bVar16;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar16 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar15);
  *(byte *)puVar6 = bVar1 + bVar15;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar15 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar16);
  *(byte *)puVar6 = bVar1 + bVar16;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar16 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar15);
  *(byte *)puVar6 = bVar1 + bVar15;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar15 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar16);
  *(byte *)puVar6 = bVar1 + bVar16;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar16 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar15);
  *(byte *)puVar6 = bVar1 + bVar15;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar15 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar16);
  *(byte *)puVar6 = bVar1 + bVar16;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar16 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar15);
  *(byte *)puVar6 = bVar1 + bVar15;
  uVar3 = *puVar6;
  bVar1 = (byte)*puVar6 + bVar13;
  *(byte *)puVar6 = bVar1 + bVar16;
  *(byte *)puVar6 = (byte)*puVar6 + bVar13 + (CARRY1((byte)uVar3,bVar13) || CARRY1(bVar1,bVar16));
  *puVar6 = *puVar6 | (uint)param_2;
  uVar3 = *puVar6;
  *(byte *)puVar6 = (byte)*puVar6 + bVar13;
  *(byte *)puVar6 = (byte)*puVar6 + bVar13 + CARRY1((byte)uVar3,bVar13);
  bVar10 = bVar10 | *unaff_EBX;
  iVar11 = CONCAT31((int3)((uint)param_1 >> 8),bVar10);
  bVar15 = CARRY1((byte)*puVar6,bVar13);
  *(byte *)puVar6 = (byte)*puVar6 + bVar13;
  uVar3 = *puVar6;
  bVar1 = (byte)*puVar6 + bVar13;
  *(byte *)puVar6 = bVar1 + bVar15;
  *(byte *)puVar6 = (byte)*puVar6 + bVar13 + (CARRY1((byte)uVar3,bVar13) || CARRY1(bVar1,bVar15));
  pbVar5 = (byte *)((uint)puVar6 | 0x10);
  bVar1 = *pbVar5;
  *pbVar5 = *pbVar5 + bVar13;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,CARRY1(bVar1,bVar13));
  *pbVar5 = *pbVar5 + bVar13 + CARRY1(bVar1,bVar13);
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar1 = *pbVar5;
  bVar2 = *pbVar5;
  *pbVar5 = bVar2 + bVar13 + bVar15;
  *pbVar5 = *pbVar5 + bVar13 + (CARRY1(bVar1,bVar13) || CARRY1(bVar2 + bVar13,bVar15));
  pbVar5 = (byte *)((uint)puVar6 | 0x10101010);
  bVar1 = *pbVar5;
  *pbVar5 = *pbVar5 + bVar13;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,CARRY1(bVar1,bVar13));
  *pbVar5 = *pbVar5 + bVar13 + CARRY1(bVar1,bVar13);
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar1 = (byte)*unaff_ESI + bVar10;
  bVar15 = CARRY1((byte)*unaff_ESI,bVar10) || CARRY1(bVar1,bVar16);
  *(byte *)unaff_ESI = bVar1 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar1 = *pbVar5;
  bVar2 = *pbVar5;
  *pbVar5 = bVar2 + bVar13 + bVar16;
  pbVar5[-0x6f6f6f70] = SCARRY1(bVar1,bVar13) != SCARRY1(bVar2 + bVar13,bVar16);
  iVar14 = -1;
  iVar12 = 0;
  iVar4 = *(int *)(iVar11 + 500);
  if (0 < iVar4) {
    piVar7 = *(int **)(iVar11 + 0x1f8);
    do {
      if (((*piVar7 == unaff_retaddr) && (*(char *)((int)piVar7 + 5) == param_3)) &&
         (*(char *)((int)piVar7 + 6) == param_4)) {
        *(undefined1 *)(*(int **)(iVar11 + 0x1f8) + iVar12 * 2 + 1) = param_5;
        return;
      }
      if ((iVar14 == -1) && (*piVar7 == -1)) {
        iVar14 = iVar12;
      }
      iVar12 = iVar12 + 1;
      piVar7 = piVar7 + 2;
    } while (iVar12 < iVar4);
  }
  if (iVar14 == -1) {
    pvVar8 = operator_new(iVar4 << 4);
    if (pvVar8 != (void *)0x0) {
      iVar14 = 0;
      if (0 < *(int *)(iVar11 + 500)) {
        puVar9 = (undefined1 *)((int)pvVar8 + 6);
        do {
          iVar14 = iVar14 + 1;
          *(undefined4 *)(puVar9 + -6) = *(undefined4 *)(*(int *)(iVar11 + 0x1f8) + -8 + iVar14 * 8)
          ;
          puVar9[-1] = *(undefined1 *)(*(int *)(iVar11 + 0x1f8) + -3 + iVar14 * 8);
          *puVar9 = *(undefined1 *)(*(int *)(iVar11 + 0x1f8) + -2 + iVar14 * 8);
          puVar9[-2] = *(undefined1 *)(*(int *)(iVar11 + 0x1f8) + -4 + iVar14 * 8);
          puVar9 = puVar9 + 8;
        } while (iVar14 < *(int *)(iVar11 + 500));
      }
      if (iVar14 < *(int *)(iVar11 + 500) * 2) {
        puVar9 = (undefined1 *)((int)pvVar8 + iVar14 * 8 + 6);
        do {
          *(undefined4 *)(puVar9 + -6) = 0xffffffff;
          puVar9[-1] = 0;
          *puVar9 = 0;
          puVar9[-2] = param_5;
          iVar14 = iVar14 + 1;
          puVar9 = puVar9 + 8;
        } while (iVar14 < *(int *)(iVar11 + 500) * 2);
      }
      operator_delete(*(void **)(iVar11 + 0x1f8));
      *(void **)(iVar11 + 0x1f8) = pvVar8;
      *(int *)((int)pvVar8 + *(int *)(iVar11 + 500) * 8) = unaff_retaddr;
      *(char *)(*(int *)(iVar11 + 0x1f8) + 5 + *(int *)(iVar11 + 500) * 8) = param_3;
      *(char *)(*(int *)(iVar11 + 0x1f8) + 6 + *(int *)(iVar11 + 500) * 8) = param_4;
      *(undefined1 *)(*(int *)(iVar11 + 0x1f8) + 4 + *(int *)(iVar11 + 500) * 8) = param_5;
      *(int *)(iVar11 + 500) = *(int *)(iVar11 + 500) << 1;
      return;
    }
  }
  else {
    iVar14 = iVar14 * 8;
    *(int *)(iVar14 + *(int *)(iVar11 + 0x1f8)) = unaff_retaddr;
    *(char *)(iVar14 + 5 + *(int *)(iVar11 + 0x1f8)) = param_3;
    *(char *)(iVar14 + 6 + *(int *)(iVar11 + 0x1f8)) = param_4;
    *(undefined1 *)(iVar14 + 4 + *(int *)(iVar11 + 0x1f8)) = param_5;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e5d95
// Address: 004e5d95
// XREFS: None
undefined4 __thiscall
FUN_004e5d95(int param_1,undefined4 param_2,char param_3,undefined4 param_4,undefined4 param_5,
            int param_6)
{
  int in_EAX;
  char *pcVar1;
  MainDecisionAIModule *unaff_retaddr;
  
  pcVar1 = (char *)*(undefined6 *)(param_1 + 0x4e);
  *pcVar1 = *pcVar1 + (char)unaff_retaddr;
  cRam4f004e5a = cRam4f004e5a + (char)((uint)unaff_retaddr >> 8);
  *(char *)(in_EAX + 0x56909090) = *(char *)(in_EAX + 0x56909090) + param_3;
  MainDecisionAIModule::save(unaff_retaddr,param_6);
  (**(code **)(unaff_retaddr[1]._padding_ + 0x3c))();
  (**(code **)(unaff_retaddr[6]._padding_ + 0x3c))();
  (**(code **)(unaff_retaddr[9]._padding_ + 0x3c))(param_6);
  (**(code **)(unaff_retaddr[0xb]._padding_ + 0x3c))(param_6);
  TribeInformationAIModule::save((TribeInformationAIModule *)&unaff_retaddr[0xc]._padding_,param_6);
  (**(code **)(unaff_retaddr[0x109]._padding_ + 0x3c))(param_6);
  (**(code **)(unaff_retaddr[0x10a]._padding_ + 0x3c))(param_6);
  (**(code **)(unaff_retaddr[0x110]._padding_ + 0x3c))(param_6);
  (**(code **)(unaff_retaddr[0x11f].objects.desiredNumberValue + 0x3c))(param_6);
  rge_write(param_6,&unaff_retaddr[0x120].objects.numberValue,4);
  rge_write(param_6,&unaff_retaddr[0x120].objects.desiredNumberValue,4);
  rge_write(param_6,&unaff_retaddr[0x120].objects.maximumSizeValue,4);
  rge_write(param_6,unaff_retaddr + 0x121,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,0x24);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e605b
// Address: 004e605b
// XREFS: None
undefined4 __fastcall FUN_004e605b(MainDecisionAIModule *param_1,char param_2)
{
  byte bVar1;
  char cVar2;
  undefined4 in_EAX;
  RGE_Static_Object *pRVar5;
  int iVar6;
  char cVar7;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int unaff_ESI;
  char *unaff_EDI;
  byte in_AF;
  uint uVar3;
  char *pcVar4;
  
  bVar1 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  uVar3 = CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX + bVar1 * -6) & 0xffffff0f;
  cVar2 = (char)uVar3;
  pcVar4 = (char *)CONCAT22((short)(uVar3 >> 0x10),CONCAT11((char)((uint)in_EAX >> 8) - bVar1,cVar2)
                           );
  cVar7 = (char)((uint)unaff_EBX >> 8);
  *unaff_EDI = *unaff_EDI + cVar7;
  *unaff_EDI = *unaff_EDI + cVar7;
  *unaff_EDI = *unaff_EDI + cVar7;
  pcVar4[0x60] = pcVar4[0x60] + (char)param_1;
  *(char *)&param_1->_padding_ = (char)param_1->_padding_ + param_2;
  *pcVar4 = *pcVar4 + cVar2;
  pRVar5 = MainDecisionAIModule::object(param_1,unaff_ESI + -3);
  if (pRVar5 != (RGE_Static_Object *)0x0) {
    iVar6 = (**(code **)(param_1->_padding_ + 0x48))(unaff_EBP);
    if (pRVar5->master_obj->object_group == iVar6) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e6841
// Address: 004e6841
// XREFS: None
long __fastcall FUN_004e6841(char *param_1,char param_2)
{
  int iVar1;
  int in_EAX;
  long lVar2;
  char cVar3;
  char unaff_BL;
  char unaff_BH;
  int unaff_ESI;
  char *unaff_EDI;
  byte in_CF;
  int unaff_retaddr;
  
  *(int *)(unaff_ESI + 0x4e) = (*(int *)(unaff_ESI + 0x4e) - (int)&stack0x00000000) - (uint)in_CF;
  cVar3 = (char)((uint)param_1 >> 8);
  *unaff_EDI = *unaff_EDI + cVar3;
  param_1[-0x5effb19a] = param_1[-0x5effb19a] + (char)((uint)in_EAX >> 8);
  *param_1 = *param_1 + unaff_BH;
  *unaff_EDI = *unaff_EDI + (char)in_EAX;
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + param_2;
  if ((0 < unaff_retaddr) &&
     (iVar1 = *(int *)(*(int *)(CONCAT22((short)((uint)param_1 >> 0x10),
                                         CONCAT11(cVar3 + unaff_BL,(char)param_1)) + 0xf0) + 0x3c),
     unaff_retaddr <= *(short *)(iVar1 + 0x3c))) {
    lVar2 = RGE_Victory_Conditions::get_victory_points
                      (*(RGE_Victory_Conditions **)
                        (*(int *)(*(int *)(iVar1 + 0x40) + unaff_retaddr * 4) + 0x34));
    return lVar2;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_004e7646
// Address: 004e7646
// XREFS: None
undefined4 __fastcall
FUN_004e7646(byte *param_1,char *param_2,undefined4 param_3,undefined4 param_4,int param_5,
            undefined4 param_6,undefined4 param_7)
{
  byte bVar1;
  char cVar2;
  char *in_EAX;
  undefined3 uVar5;
  uint uVar3;
  char *pcVar4;
  int iVar6;
  byte bVar7;
  int *unaff_EBX;
  byte *unaff_ESI;
  int iVar8;
  int iVar9;
  
  bVar1 = *param_1;
  bVar7 = (byte)((uint)unaff_EBX >> 8);
  *param_1 = *param_1 + bVar7;
  if (CARRY1(bVar1,bVar7) || *param_1 == 0) {
    in_EAX = in_EAX + CARRY1(bVar1,bVar7) + 0xf8830000;
code_r0x004e76a2:
    pcVar4 = (char *)((uint)in_EAX | 0x15928d0f);
    *pcVar4 = *pcVar4 + (char)pcVar4;
  }
  else {
    bVar1 = *param_1;
    *param_1 = *param_1 + bVar7;
    if (CARRY1(bVar1,bVar7) || *param_1 == 0) goto code_r0x004e76a2;
    bVar1 = *param_1;
    *param_1 = *param_1 + bVar7;
    if (!CARRY1(bVar1,bVar7) && *param_1 != 0) {
      cVar2 = (char)in_EAX;
      param_1[0x76] = param_1[0x76] + cVar2;
      *in_EAX = *in_EAX + cVar2;
      in_EAX[(int)&stack0x00000000] = in_EAX[(int)&stack0x00000000] + cVar2;
      uVar5 = (undefined3)((uint)in_EAX >> 8);
      *(int *)param_1 = *(int *)param_1 + CONCAT31(uVar5,cVar2 + '\r');
      uVar3 = CONCAT31(uVar5,cVar2 + *param_2 + '\x13') + *unaff_EBX + *unaff_EBX + *unaff_EBX +
              *unaff_EBX + *unaff_EBX + *unaff_EBX + *unaff_EBX + *unaff_EBX + *unaff_EBX +
              *unaff_EBX + *unaff_EBX + *unaff_EBX + *unaff_EBX + *unaff_EBX & 0xffffff08;
      if ((int)uVar3 < 0) {
        return 0;
      }
      unaff_ESI = param_1;
      if (0xc < (int)uVar3) {
        return 0;
      }
    }
  }
  switch(param_7) {
  case 1:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0,
               *(int *)(unaff_ESI + 4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),1,
               *(int *)(unaff_ESI + 8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),2,
               *(int *)(unaff_ESI + 0xc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),3,
               *(int *)(unaff_ESI + 0x10));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),4,
               *(int *)(unaff_ESI + 0x14));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),5,
               *(int *)(unaff_ESI + 0x18));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x23,
               *(int *)(unaff_ESI + 0x90));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),100,
               *(int *)(unaff_ESI + 0x194));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xe1,
               *(int *)(unaff_ESI + 0x388));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x75,
               *(int *)(unaff_ESI + 0x1d8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x76,
               *(int *)(unaff_ESI + 0x1dc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x77,
               *(int *)(unaff_ESI + 0x1e0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x78,
               *(int *)(unaff_ESI + 0x1e4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x9c,
               *(int *)(unaff_ESI + 0x274));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x9f,
               *(int *)(unaff_ESI + 0x280));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x9e,
               *(int *)(unaff_ESI + 0x27c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x9d,
               *(int *)(unaff_ESI + 0x278));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa0,
               *(int *)(unaff_ESI + 0x284));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x8e,
               *(int *)(unaff_ESI + 0x23c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x94,
               *(int *)(unaff_ESI + 0x254));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x95,
               *(int *)(unaff_ESI + 600));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xcb,
               *(int *)(unaff_ESI + 0x330));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa3,
               *(int *)(unaff_ESI + 0x290));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa4,
               *(int *)(unaff_ESI + 0x294));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa6,
               *(int *)(unaff_ESI + 0x29c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa5,
               *(int *)(unaff_ESI + 0x298));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa7,
               *(int *)(unaff_ESI + 0x2a0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb3,
               *(int *)(unaff_ESI + 0x2d0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb4,
               *(int *)(unaff_ESI + 0x2d4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xcd,
               *(int *)(unaff_ESI + 0x338));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xcf,
               *(int *)(unaff_ESI + 0x340));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xce,
               *(int *)(unaff_ESI + 0x33c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xdc,
               *(int *)(unaff_ESI + 0x374));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xde,
               *(int *)(unaff_ESI + 0x37c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd0,
               *(int *)(unaff_ESI + 0x344));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd1,
               *(int *)(unaff_ESI + 0x348));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd2,
               *(int *)(unaff_ESI + 0x34c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd3,
               *(int *)(unaff_ESI + 0x350));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xdf,
               *(int *)(unaff_ESI + 0x380));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd4,
               *(int *)(unaff_ESI + 0x354));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd5,
               *(int *)(unaff_ESI + 0x358));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd6,
               *(int *)(unaff_ESI + 0x35c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xe0,
               *(int *)(unaff_ESI + 900));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa9,
               *(int *)(unaff_ESI + 0x2a8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xaa,
               *(int *)(unaff_ESI + 0x2ac));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xab,
               *(int *)(unaff_ESI + 0x2b0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xac,
               *(int *)(unaff_ESI + 0x2b4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xad,
               *(int *)(unaff_ESI + 0x2b8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xbe,
               *(int *)(unaff_ESI + 0x2fc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xbf,
               *(int *)(unaff_ESI + 0x300));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc0,
               *(int *)(unaff_ESI + 0x304));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc1,
               *(int *)(unaff_ESI + 0x308));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xae,
               *(int *)(unaff_ESI + 700));
    iVar9 = *(int *)(unaff_ESI + 0x334);
    iVar8 = 0xcc;
    break;
  case 2:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x10,
               *(int *)(unaff_ESI + 0x44));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x1a,
               *(int *)(unaff_ESI + 0x6c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x24,
               *(int *)(unaff_ESI + 0x94));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x25,
               *(int *)(unaff_ESI + 0x98));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x5d,
               *(int *)(unaff_ESI + 0x178));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x5e,
               *(int *)(unaff_ESI + 0x17c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x62,
               *(int *)(unaff_ESI + 0x18c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x79,
               *(int *)(unaff_ESI + 0x1e8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x83,
               *(int *)(unaff_ESI + 0x210));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x8f,
               *(int *)(unaff_ESI + 0x240));
    iVar9 = *(int *)(unaff_ESI + 0x28c);
    iVar8 = 0xa2;
    break;
  default:
    return 0;
  case 0xc:
    iVar9 = *(int *)(unaff_ESI + 0x4c);
    iVar8 = 0x12;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0xd:
    iVar9 = *(int *)(unaff_ESI + 0x50);
    iVar8 = 0x13;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0xe:
    iVar9 = *(int *)(unaff_ESI + 0x54);
    iVar8 = 0x14;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x10:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x16,
               *(int *)(unaff_ESI + 0x5c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x48,
               *(int *)(unaff_ESI + 0x124));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x39,
               *(int *)(unaff_ESI + 0xe8));
    iVar9 = *(int *)(unaff_ESI + 0x174);
    iVar8 = 0x5c;
    break;
  case 0x11:
    iVar9 = *(int *)(unaff_ESI + 0x60);
    iVar8 = 0x17;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x12:
    iVar9 = *(int *)(unaff_ESI + 100);
    iVar8 = 0x18;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x15:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x19,
               *(int *)(unaff_ESI + 0x68));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x1c,
               *(int *)(unaff_ESI + 0x74));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x26,
               *(int *)(unaff_ESI + 0x9c));
    iVar9 = *(int *)(unaff_ESI + 0xa0);
    iVar8 = 0x27;
    break;
  case 0x16:
    iVar9 = *(int *)(unaff_ESI + 0x78);
    iVar8 = 0x1d;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x17:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x20,
               *(int *)(unaff_ESI + 0x84));
    iVar9 = *(int *)(unaff_ESI + 0x248);
    iVar8 = 0x91;
    break;
  case 0x18:
    iVar9 = *(int *)(unaff_ESI + 0x8c);
    iVar8 = 0x22;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x19:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x28,
               *(int *)(unaff_ESI + 0xa4));
    iVar9 = *(int *)(unaff_ESI + 0x130);
    iVar8 = 0x4b;
    break;
  case 0x1a:
    iVar9 = *(int *)(unaff_ESI + 0xa8);
    iVar8 = 0x29;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x1b:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x2b,
               *(int *)(unaff_ESI + 0xb0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x2c,
               *(int *)(unaff_ESI + 0xb4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x2a,
               *(int *)(unaff_ESI + 0xac));
    iVar9 = *(int *)(unaff_ESI + 0xb8);
    iVar8 = 0x2d;
    break;
  case 0x1c:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x1e,
               *(int *)(unaff_ESI + 0x7c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x1f,
               *(int *)(unaff_ESI + 0x80));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x5b,
               *(int *)(unaff_ESI + 0x170));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x5f,
               *(int *)(unaff_ESI + 0x180));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x60,
               *(int *)(unaff_ESI + 0x184));
    iVar9 = *(int *)(unaff_ESI + 0x188);
    iVar8 = 0x61;
    break;
  case 0x1d:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x2e,
               *(int *)(unaff_ESI + 0xbc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x66,
               *(int *)(unaff_ESI + 0x19c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x2f,
               *(int *)(unaff_ESI + 0xc0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x67,
               *(int *)(unaff_ESI + 0x1a0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x68,
               *(int *)(unaff_ESI + 0x1a4));
    iVar9 = *(int *)(unaff_ESI + 0x21c);
    iVar8 = 0x86;
    break;
  case 0x1e:
    iVar9 = *(int *)(unaff_ESI + 0xc4);
    iVar8 = 0x30;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x1f:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x31,
               *(int *)(unaff_ESI + 200));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x87,
               *(int *)(unaff_ESI + 0x220));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x88,
               *(int *)(unaff_ESI + 0x224));
    iVar9 = *(int *)(unaff_ESI + 0x324);
    iVar8 = 200;
    break;
  case 0x20:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x32,
               *(int *)(unaff_ESI + 0xcc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x33,
               *(int *)(unaff_ESI + 0xd0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x34,
               *(int *)(unaff_ESI + 0xd4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x35,
               *(int *)(unaff_ESI + 0xd8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x36,
               *(int *)(unaff_ESI + 0xdc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x37,
               *(int *)(unaff_ESI + 0xe0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x38,
               *(int *)(unaff_ESI + 0xe4));
    iVar9 = *(int *)(unaff_ESI + 0x11c);
    iVar8 = 0x46;
    break;
  case 0x21:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x3a,
               *(int *)(unaff_ESI + 0xec));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x3b,
               *(int *)(unaff_ESI + 0xf0));
    iVar9 = *(int *)(unaff_ESI + 0xf4);
    iVar8 = 0x3c;
    break;
  case 0x22:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x3d,
               *(int *)(unaff_ESI + 0xf8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x3e,
               *(int *)(unaff_ESI + 0xfc));
    iVar9 = *(int *)(unaff_ESI + 0x100);
    iVar8 = 0x3f;
    break;
  case 0x23:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x40,
               *(int *)(unaff_ESI + 0x104));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x41,
               *(int *)(unaff_ESI + 0x108));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x42,
               *(int *)(unaff_ESI + 0x10c));
    iVar9 = *(int *)(unaff_ESI + 0x364);
    iVar8 = 0xd8;
    break;
  case 0x24:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x43,
               *(int *)(unaff_ESI + 0x110));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x44,
               *(int *)(unaff_ESI + 0x114));
    iVar9 = *(int *)(unaff_ESI + 0x118);
    iVar8 = 0x45;
    break;
  case 0x25:
    iVar9 = *(int *)(unaff_ESI + 0x120);
    iVar8 = 0x47;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x26:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x49,
               *(int *)(unaff_ESI + 0x128));
    iVar9 = *(int *)(unaff_ESI + 300);
    iVar8 = 0x4a;
    break;
  case 0x27:
    iVar9 = *(int *)(unaff_ESI + 0x134);
    iVar8 = 0x4c;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x28:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x4d,
               *(int *)(unaff_ESI + 0x138));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x4e,
               *(int *)(unaff_ESI + 0x13c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x4f,
               *(int *)(unaff_ESI + 0x140));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x50,
               *(int *)(unaff_ESI + 0x144));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x51,
               *(int *)(unaff_ESI + 0x148));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x52,
               *(int *)(unaff_ESI + 0x14c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x53,
               *(int *)(unaff_ESI + 0x150));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x59,
               *(int *)(unaff_ESI + 0x168));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x5a,
               *(int *)(unaff_ESI + 0x16c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6a,
               *(int *)(unaff_ESI + 0x1ac));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6b,
               *(int *)(unaff_ESI + 0x1b0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6c,
               *(int *)(unaff_ESI + 0x1b4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6d,
               *(int *)(unaff_ESI + 0x1b8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6e,
               *(int *)(unaff_ESI + 0x1bc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6f,
               *(int *)(unaff_ESI + 0x1c0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7a,
               *(int *)(unaff_ESI + 0x1ec));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7b,
               *(int *)(unaff_ESI + 0x1f0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x90,
               *(int *)(unaff_ESI + 0x244));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb8,
               *(int *)(unaff_ESI + 0x2e4));
    iVar9 = *(int *)(unaff_ESI + 0x2e8);
    iVar8 = 0xb9;
    break;
  case 0x29:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x54,
               *(int *)(unaff_ESI + 0x154));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x55,
               *(int *)(unaff_ESI + 0x158));
    iVar9 = *(int *)(unaff_ESI + 0x228);
    iVar8 = 0x89;
    break;
  case 0x2a:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x56,
               *(int *)(unaff_ESI + 0x15c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x57,
               *(int *)(unaff_ESI + 0x160));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xca,
               *(int *)(unaff_ESI + 0x32c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x96,
               *(int *)(unaff_ESI + 0x25c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x97,
               *(int *)(unaff_ESI + 0x260));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x98,
               *(int *)(unaff_ESI + 0x264));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa1,
               *(int *)(unaff_ESI + 0x288));
    iVar9 = *(int *)(unaff_ESI + 0x2a4);
    iVar8 = 0xa8;
    break;
  case 0x2b:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x58,
               *(int *)(unaff_ESI + 0x164));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x65,
               *(int *)(unaff_ESI + 0x198));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x9b,
               *(int *)(unaff_ESI + 0x270));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xaf,
               *(int *)(unaff_ESI + 0x2c0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb0,
               *(int *)(unaff_ESI + 0x2c4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb1,
               *(int *)(unaff_ESI + 0x2c8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb5,
               *(int *)(unaff_ESI + 0x2d8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb6,
               *(int *)(unaff_ESI + 0x2dc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb7,
               *(int *)(unaff_ESI + 0x2e0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xba,
               *(int *)(unaff_ESI + 0x2ec));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xbb,
               *(int *)(unaff_ESI + 0x2f0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc2,
               *(int *)(unaff_ESI + 0x30c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc4,
               *(int *)(unaff_ESI + 0x314));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc5,
               *(int *)(unaff_ESI + 0x318));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xbc,
               *(int *)(unaff_ESI + 0x2f4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc3,
               *(int *)(unaff_ESI + 0x310));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xbd,
               *(int *)(unaff_ESI + 0x2f8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc6,
               *(int *)(unaff_ESI + 0x31c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),199,
               *(int *)(unaff_ESI + 800));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd7,
               *(int *)(unaff_ESI + 0x360));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd9,
               *(int *)(unaff_ESI + 0x368));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xda,
               *(int *)(unaff_ESI + 0x36c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xdb,
               *(int *)(unaff_ESI + 0x370));
    iVar9 = *(int *)(unaff_ESI + 0x378);
    iVar8 = 0xdd;
    break;
  case 0x2c:
    iVar9 = *(int *)(unaff_ESI + 400);
    iVar8 = 99;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x2d:
    iVar9 = *(int *)(unaff_ESI + 0x1a8);
    iVar8 = 0x69;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x2e:
    iVar9 = *(int *)(unaff_ESI + 0x1c4);
    iVar8 = 0x70;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x2f:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x71,
               *(int *)(unaff_ESI + 0x1c8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x72,
               *(int *)(unaff_ESI + 0x1cc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x73,
               *(int *)(unaff_ESI + 0x1d0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x74,
               *(int *)(unaff_ESI + 0x1d4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x92,
               *(int *)(unaff_ESI + 0x24c));
    iVar9 = *(int *)(unaff_ESI + 0x250);
    iVar8 = 0x93;
    break;
  case 0x30:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7c,
               *(int *)(unaff_ESI + 500));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7d,
               *(int *)(unaff_ESI + 0x1f8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7e,
               *(int *)(unaff_ESI + 0x1fc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7f,
               *(int *)(unaff_ESI + 0x200));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x80,
               *(int *)(unaff_ESI + 0x204));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x81,
               *(int *)(unaff_ESI + 0x208));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x82,
               *(int *)(unaff_ESI + 0x20c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x84,
               *(int *)(unaff_ESI + 0x214));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x85,
               *(int *)(unaff_ESI + 0x218));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb2,
               *(int *)(unaff_ESI + 0x2cc));
    iVar9 = *(int *)(unaff_ESI + 0x328);
    iVar8 = 0xc9;
    break;
  case 0x31:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x8a,
               *(int *)(unaff_ESI + 0x22c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x8b,
               *(int *)(unaff_ESI + 0x230));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x8c,
               *(int *)(unaff_ESI + 0x234));
    iVar9 = *(int *)(unaff_ESI + 0x238);
    iVar8 = 0x8d;
  }
  iVar6 = *(int *)(param_5 + 0x238);
LAB_004e8c26:
  TribeTacticalAIModule::setStrategicNumber((TribeTacticalAIModule *)(iVar6 + 0x1146c),iVar8,iVar9);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e8c42
// Address: 004e8c42
// XREFS: None
undefined4 __fastcall FUN_004e8c42(uint param_1,undefined4 param_2)
{
  char *pcVar1;
  char cVar2;
  int in_EAX;
  char cVar3;
  uint uVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char *unaff_EBX;
  int unaff_EBP;
  uint *puVar10;
  int unaff_EDI;
  undefined2 in_CS;
  undefined1 in_ZF;
  char in_SF;
  char in_OF;
  float10 in_ST0;
  uint uVar4;
  
  cVar9 = (char)((uint)param_2 >> 8);
  cVar6 = (char)param_2;
  puVar10 = (uint *)0x9e004e76;
  uVar4 = param_1;
  if (in_OF == in_SF) {
    cVar8 = (char)((uint)unaff_EBX >> 8);
    *unaff_EBX = *unaff_EBX + cVar8;
    *unaff_EBX = *unaff_EBX + cVar8;
    *unaff_EBX = *unaff_EBX + cVar8;
    pcVar1 = (char *)(unaff_EDI + -0x33ffb183);
    cVar2 = *pcVar1;
    uRam9e004e76 = in_CS;
    *pcVar1 = *pcVar1 + cVar9;
    if (SCARRY1(cVar2,cVar9) == *pcVar1 < '\0') goto code_r0x004e8cc5;
    cVar2 = (char)((uint)in_EAX >> 8);
    cVar3 = (char)param_1 + cVar2;
    uVar4 = CONCAT31((int3)(param_1 >> 8),cVar3);
    if (SCARRY1((char)param_1,cVar2) != cVar3 < '\0') {
      *unaff_EBX = *unaff_EBX + cVar8;
      in_EAX = CONCAT22((short)((uint)in_EAX >> 0x10),
                        CONCAT11((char)((short)in_EAX % (short)*(char *)(unaff_EBP + 0x4e)),
                                 (char)((short)in_EAX / (short)*(char *)(unaff_EBP + 0x4e))));
      uRam9e004e76 = in_CS;
      unaff_EBX[0x7e] = unaff_EBX[0x7e] + cVar6;
      *(char *)(in_EAX + 0x7e) = *(char *)(in_EAX + 0x7e) + (char)(param_1 >> 8);
      puVar10 = (uint *)0x9e004e74;
      *unaff_EBX = *unaff_EBX + cVar8;
      in_OF = SCARRY1(cVar8,cVar6);
      cVar8 = cVar8 + cVar6;
      unaff_EBX = (char *)CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(cVar8,(char)unaff_EBX))
      ;
      in_SF = cVar8 < '\0';
      in_ZF = cVar8 == '\0';
      uRam9e004e74 = in_CS;
      goto code_r0x004e8c99;
    }
  }
  else {
code_r0x004e8c99:
    if ((bool)in_ZF || in_OF != in_SF) {
      LOCK();
      uVar5 = *puVar10;
      *(byte *)puVar10 = (byte)uVar4;
      uVar5 = CONCAT31((int3)(uVar4 >> 8),(byte)uVar5);
      UNLOCK();
code_r0x004e8cf1:
      *puVar10 = uVar5;
      halt_baddata();
    }
    cVar8 = (char)((uint)in_EAX >> 8);
    cVar3 = (char)(uVar4 >> 8);
    cVar2 = cVar8 + cVar3;
    if (cVar2 == '\0' || SCARRY1(cVar8,cVar3) != cVar2 < '\0') {
      LOCK();
      uVar5 = *puVar10;
      *puVar10 = uVar4;
      UNLOCK();
      goto code_r0x004e8cf1;
    }
    cVar8 = *unaff_EBX;
    cVar7 = (char)unaff_EBX;
    *unaff_EBX = *unaff_EBX + cVar7;
    uVar5 = uVar4;
    if (*unaff_EBX != '\0' && SCARRY1(cVar8,cVar7) == *unaff_EBX < '\0') goto code_r0x004e8cf1;
    cVar8 = *unaff_EBX;
    *unaff_EBX = *unaff_EBX + cVar9;
    if (*unaff_EBX != '\0' && SCARRY1(cVar8,cVar9) == *unaff_EBX < '\0') goto code_r0x004e8cf5;
    *(char *)(unaff_EDI + 0x7f) = *(char *)(unaff_EDI + 0x7f) + cVar7;
    *(char *)(unaff_EDI + 0x7f) = *(char *)(unaff_EDI + 0x7f) + cVar9;
    cVar8 = (char)((uint)unaff_EBX >> 8);
    cVar9 = cVar8 + cVar6;
    if (cVar9 != '\0' && SCARRY1(cVar8,cVar6) == cVar9 < '\0') {
      return 0;
    }
    pcVar1 = (char *)(CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(cVar2,(char)in_EAX)) + -0x80);
    *pcVar1 = *pcVar1 + cVar3;
    puVar10 = (uint *)((int)puVar10 + -3);
    *(byte *)puVar10 = *(byte *)puVar10 | 0x17;
    *puVar10 = *puVar10 | 0x4e8180;
code_r0x004e8cc5:
    *(byte *)puVar10 = (byte)*puVar10 | 0x8e;
  }
  *(byte *)puVar10 = (byte)*puVar10 | 0xd4;
  *(byte *)puVar10 = (byte)*puVar10 | 0x37;
  *puVar10 = *puVar10 | 0x7d;
  *puVar10 = *puVar10 | 0xffffff95;
  *puVar10 = *puVar10 | 0xffffffc1;
  *puVar10 = *puVar10 | 0xffffffd9;
  *puVar10 = *puVar10 | 0xffffffe2;
  puVar10 = (uint *)((int)puVar10 + -1);
  *(char *)(unaff_EDI + -0x38ffb177) = *(char *)(unaff_EDI + -0x38ffb177) + (char)(uVar4 >> 8);
code_r0x004e8cf5:
  *puVar10 = uVar4;
  *(short *)(uVar4 + 0x89f7004e) = (short)in_ST0;
  *(char *)(uVar4 + 0xb9004e8a) = *(char *)(uVar4 + 0xb9004e8a) + cVar6;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e90e9
// Address: 004e90e9
// XREFS: None
// [HELPER] s_: ""
StrategyAIModule * FUN_004e90e9(void)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int unaff_ESI;
  StrategyAIModule *this;
  char *pcVar4;
  undefined4 unaff_EDI;
  char *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  int unaff_retaddr;
  
  this = (StrategyAIModule *)(unaff_ESI + -1);
  *(undefined4 *)(unaff_retaddr + -4) = 0xffffffff;
  *(code **)(unaff_retaddr + -8) = FUN_005607b2;
  *(undefined4 *)(unaff_retaddr + -0xc) = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = unaff_retaddr + -0xc;
  *(StrategyAIModule **)(unaff_retaddr + -0x10) = this;
  *(undefined4 *)(unaff_retaddr + -0x14) = unaff_EBX;
  *(undefined4 *)(unaff_retaddr + -0x18) = unaff_EBP;
  *(StrategyAIModule **)(unaff_retaddr + -0x1c) = this;
  *(undefined4 *)(unaff_retaddr + -0x20) = unaff_EDI;
  *(undefined4 *)(unaff_retaddr + -0x24) = *(undefined4 *)(unaff_retaddr + 8);
  *(undefined4 *)(unaff_retaddr + -0x28) = *(undefined4 *)(unaff_retaddr + 4);
  *(StrategyAIModule **)(unaff_retaddr + -0x10) = this;
  *(undefined4 *)(unaff_retaddr + -0x2c) = 0x4e9131;
  StrategyAIModule::StrategyAIModule
            (this,*(void **)(unaff_retaddr + -0x28),*(int *)(unaff_retaddr + -0x24));
  *(undefined4 *)(unaff_ESI + 0xef) = 0;
  *(undefined4 *)(unaff_ESI + 0xf3) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x1fb) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x1ff) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x203) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x207) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x22b) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x22f) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x233) = 0;
  *(undefined4 *)(unaff_retaddr + -4) = 0;
  *(undefined4 *)(unaff_ESI + 0x237) = 0;
  *(undefined4 *)(unaff_ESI + 0x23b) = 0;
  *(undefined4 *)(unaff_ESI + 0x23f) = 0;
  *(undefined4 *)(unaff_ESI + 0x243) = 0;
  *(undefined4 *)(unaff_ESI + 0x247) = 0;
  *(undefined4 *)(unaff_ESI + 0x24b) = 0;
  *(undefined4 *)(unaff_ESI + 0x24f) = 0;
  *(undefined4 *)(unaff_ESI + 0x253) = 0;
  *(undefined4 *)(unaff_ESI + 599) = 0;
  *(undefined4 *)(unaff_ESI + 0x25b) = 0;
  *(undefined4 *)(unaff_ESI + 0x25f) = 0;
  *(undefined4 *)(unaff_ESI + 0x263) = 0;
  *(undefined1 *)(unaff_retaddr + -4) = 3;
  *(undefined4 *)(unaff_retaddr + -0x24) = 0x4e91c8;
  VictoryConditionRuleSystem::VictoryConditionRuleSystem
            ((VictoryConditionRuleSystem *)(unaff_ESI + 0x267));
  *(undefined4 *)(unaff_ESI + 0x20b) = 0xbf800000;
  *(undefined4 *)(unaff_ESI + 0x20f) = 0xbf800000;
  *(undefined4 *)(unaff_ESI + 0x213) = 0xbf800000;
  *(undefined4 *)(unaff_ESI + 0x21b) = 0xbf800000;
  *(undefined4 *)(unaff_ESI + 0x21f) = 0xbf800000;
  *(undefined4 *)(unaff_ESI + 0x223) = 0xbf800000;
  uVar2 = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x5f3) = 0;
  *(undefined ***)this = &TribeStrategyAIModule::_vftable_;
  pcVar4 = s_;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = (char *)(unaff_ESI + 0xf7);
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
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_retaddr + -0xc);
  return this;
}

// --------------------------------------------------

// Function: FUN_004ecd1f
// Address: 004ecd1f
// XREFS: None
void FUN_004ecd1f(void)
{
  code *pcVar1;
  int in_EAX;
  char unaff_BL;
  
  *(char *)(in_EAX + -0x46) = *(char *)(in_EAX + -0x46) + (char)((uint)in_EAX >> 8);
  cRam22004ec7 = cRam22004ec7 + unaff_BL;
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

// --------------------------------------------------

// Function: FUN_004f0b62
// Address: 004f0b62
// XREFS: None
char * __fastcall FUN_004f0b62(char param_1,uint *param_2)
{
  char *pcVar1;
  uint uVar2;
  uint in_EAX;
  char *pcVar3;
  char cVar4;
  char cVar5;
  undefined2 unaff_BX;
  int unaff_EDI;
  char *pcVar6;
  char *pcVar7;
  undefined2 in_DS;
  
  uVar2 = *param_2;
  pcVar6 = (char *)(unaff_EDI + -1);
  *pcVar6 = *pcVar6 + (char)param_2;
  cVar4 = param_1 + *pcVar6 + *pcVar6;
  pcVar1 = (char *)segment(in_DS,unaff_BX);
  cVar5 = cVar4 + *pcVar1;
  pcVar3 = (char *)((in_EAX | uVar2) - 1);
  pcVar7 = pcVar6;
  if (cVar5 != '\0' && SCARRY1(cVar4,*pcVar1) == cVar5 < '\0') {
    pcVar7 = (char *)((in_EAX | uVar2) + 3);
    pcVar3 = pcVar6;
  }
  pcVar7[-0x50ffb0ff] = pcVar7[-0x50ffb0ff] + (char)param_2;
  return pcVar3;
}

// --------------------------------------------------

// Function: FUN_004f0d4d
// Address: 004f0d4d
// XREFS: None
void __fastcall
FUN_004f0d4d(int param_1,char param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  char *pcVar1;
  short sVar2;
  uint in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  ManagedArray<int> *pMVar10;
  int unaff_EDI;
  
  iVar8 = param_5;
  iVar7 = CONCAT31((int3)((uint)param_1 >> 8),(byte)param_1 ^ *(byte *)(unaff_EDI + param_1 * 2));
  cVar9 = (char)((uint)param_1 >> 8);
  (&stack0x0000004f)[iVar7] = (&stack0x0000004f)[iVar7] + cVar9;
  *(char *)(in_EAX + 0xc) = *(char *)(in_EAX + 0xc) + param_2;
  *(char *)(in_EAX + 0x60004f0c) = *(char *)(in_EAX + 0x60004f0c) + param_2;
  (&stack0x0000004f)[iVar7] = (&stack0x0000004f)[iVar7] + cVar9;
  pcVar1 = (char *)((in_EAX | 0x4f) + 0x90004f0c);
  *pcVar1 = *pcVar1 + (char)(in_EAX | 0x4f);
  *(char *)(iVar7 + 0x53) = *(char *)(iVar7 + 0x53) + param_2;
  sVar2 = *(short *)(*(int *)(param_5 + 8) + 0x14);
  param_3 = iVar7;
  if (sVar2 == 4) {
    iVar8 = *(int *)(iVar7 + 0xf8);
    iVar4 = *(int *)(param_5 + 4);
    pMVar10 = (ManagedArray<int> *)(iVar7 + 0xf4);
    iVar3 = 0;
    if (0 < iVar8) {
      do {
        if (*(int *)(iVar7 + 0x100) <= iVar3) break;
        if (pMVar10->value[iVar3] == iVar4) {
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar8);
    }
    if (iVar8 <= *(int *)(iVar7 + 0x100) + -1) goto LAB_004f1077;
  }
  else {
    if ((((((sVar2 != 0) && (sVar2 != 0x18)) && (sVar2 != 6)) &&
         (((sVar2 != 0x19 && (sVar2 != 0x1a)) &&
          ((sVar2 != 0xc && ((sVar2 != 0x23 && (sVar2 != 0x17)))))))) && (sVar2 != 0x24)) &&
       ((((sVar2 != 0x1c && (sVar2 != 0x12)) && (sVar2 != 0xd)) && (sVar2 != 0x27)))) {
      if (((sVar2 != 2) && (sVar2 != 0x14)) && ((sVar2 != 0x16 && (sVar2 != 0x15)))) {
        if (*(short *)(*(int *)(param_5 + 8) + 0x10) != 0x9f) {
          return;
        }
        iVar4 = RGE_Game_World::difficultyLevel
                          (*(RGE_Game_World **)(*(int *)(*(int *)(iVar7 + 0xf0) + 0xf0) + 0x3c));
        if (3 < iVar4) {
          return;
        }
        ManagedArray<int>::add((ManagedArray<int> *)(iVar7 + 0x184),*(int *)(iVar8 + 4));
        return;
      }
      iVar4 = *(int *)(iVar7 + 0x138);
      iVar3 = *(int *)(param_5 + 4);
      pMVar10 = (ManagedArray<int> *)(iVar7 + 0x134);
      iVar5 = 0;
      if (0 < iVar4) {
        do {
          if (*(int *)(iVar7 + 0x140) <= iVar5) break;
          if (pMVar10->value[iVar5] == iVar3) goto LAB_004f0ee8;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
      if (*(int *)(iVar7 + 0x140) + -1 < iVar4) {
        ManagedArray<int>::resize(pMVar10,iVar4 + 1);
      }
      pMVar10->value[*(int *)(iVar7 + 0x138)] = iVar3;
      *(int *)(iVar7 + 0x138) = *(int *)(iVar7 + 0x138) + 1;
LAB_004f0ee8:
      iVar4 = iVar7;
      if (*(short *)(*(int *)(iVar8 + 8) + 0x14) == 2) {
        iVar3 = *(int *)(iVar7 + 0x168);
        iVar5 = *(int *)(iVar8 + 4);
        pMVar10 = (ManagedArray<int> *)(iVar7 + 0x164);
        iVar6 = 0;
        if (0 < iVar3) {
          do {
            if (*(int *)(iVar7 + 0x170) <= iVar6) break;
            iVar4 = param_3;
            if (pMVar10->value[iVar6] == iVar5) goto LAB_004f0f45;
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar3);
        }
        if (*(int *)(iVar7 + 0x170) + -1 < iVar3) {
          ManagedArray<int>::resize(pMVar10,iVar3 + 1);
        }
        pMVar10->value[*(int *)(iVar7 + 0x168)] = iVar5;
        *(int *)(iVar7 + 0x168) = *(int *)(iVar7 + 0x168) + 1;
      }
LAB_004f0f45:
      if (*(short *)(*(int *)(iVar8 + 8) + 0x14) == 0x14) {
        param_5 = *(int *)(iVar8 + 4);
        pMVar10 = (ManagedArray<int> *)(iVar4 + 0x174);
        iVar7 = ManagedArray<int>::contains(pMVar10,&param_5);
        if (iVar7 != 1) {
          if (*(int *)(iVar4 + 0x180) + -1 < *(int *)(iVar4 + 0x178)) {
            ManagedArray<int>::resize(pMVar10,*(int *)(iVar4 + 0x178) + 1);
          }
          pMVar10->value[*(int *)(iVar4 + 0x178)] = param_5;
          *(int *)(iVar4 + 0x178) = *(int *)(iVar4 + 0x178) + 1;
        }
      }
      if (*(short *)(*(int *)(iVar8 + 8) + 0x14) == 0x16) {
        param_5 = *(int *)(iVar8 + 4);
        pMVar10 = (ManagedArray<int> *)(iVar4 + 0x144);
        iVar7 = ManagedArray<int>::contains(pMVar10,&param_5);
        if (iVar7 != 1) {
          if (*(int *)(iVar4 + 0x150) + -1 < *(int *)(iVar4 + 0x148)) {
            ManagedArray<int>::resize(pMVar10,*(int *)(iVar4 + 0x148) + 1);
          }
          pMVar10->value[*(int *)(iVar4 + 0x148)] = param_5;
          *(int *)(iVar4 + 0x148) = *(int *)(iVar4 + 0x148) + 1;
        }
      }
      if (*(short *)(*(int *)(iVar8 + 8) + 0x14) != 0x15) {
        return;
      }
      param_5 = *(int *)(iVar8 + 4);
      pMVar10 = (ManagedArray<int> *)(iVar4 + 0x154);
      iVar8 = ManagedArray<int>::contains(pMVar10,&param_5);
      if (iVar8 == 1) {
        return;
      }
      if (*(int *)(iVar4 + 0x160) + -1 < *(int *)(iVar4 + 0x158)) {
        ManagedArray<int>::resize(pMVar10,*(int *)(iVar4 + 0x158) + 1);
      }
      pMVar10->value[*(int *)(iVar4 + 0x158)] = param_5;
      *(int *)(iVar4 + 0x158) = *(int *)(iVar4 + 0x158) + 1;
      return;
    }
    iVar8 = *(int *)(iVar7 + 0x118);
    iVar4 = *(int *)(param_5 + 4);
    pMVar10 = (ManagedArray<int> *)(iVar7 + 0x114);
    iVar3 = 0;
    if (0 < iVar8) {
      do {
        if (*(int *)(iVar7 + 0x120) <= iVar3) break;
        if (pMVar10->value[iVar3] == iVar4) {
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar8);
    }
    if (iVar8 <= *(int *)(iVar7 + 0x120) + -1) goto LAB_004f1077;
  }
  ManagedArray<int>::resize(pMVar10,iVar8 + 1);
LAB_004f1077:
  pMVar10->value[pMVar10->numberValue] = iVar4;
  pMVar10->numberValue = pMVar10->numberValue + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_005018c1
// Address: 005018c1
// XREFS: None
int __fastcall FUN_005018c1(int param_1,int param_2)
{
  int in_EAX;
  int iVar1;
  byte bVar2;
  int *piVar3;
  int unaff_EBX;
  int unaff_EBP;
  byte *unaff_EDI;
  
  bVar2 = (byte)param_2;
  *unaff_EDI = *unaff_EDI ^ bVar2;
  unaff_EDI[param_2 + 0x50] = unaff_EDI[param_2 + 0x50] + (char)param_1;
  *(char *)(param_2 + 0x17) = *(char *)(param_2 + 0x17) + (char)in_EAX;
  unaff_EDI[param_2 + 0x50] = unaff_EDI[param_2 + 0x50] + bVar2;
  *(char *)(unaff_EBX + 0x17) = *(char *)(unaff_EBX + 0x17) + (char)unaff_EBX;
  unaff_EDI[0x17] = unaff_EDI[0x17] + (char)((uint)param_2 >> 8);
  *(char *)(unaff_EBP + 0x17) = *(char *)(unaff_EBP + 0x17) + (char)((uint)param_1 >> 8);
  unaff_EDI[0x17] = unaff_EDI[0x17] + (char)((uint)unaff_EBX >> 8);
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + bVar2;
  iVar1 = 0;
  piVar3 = (int *)(param_1 + 0x51c);
  do {
    if (*piVar3 == in_EAX) {
      return param_1 + 0x51c + iVar1 * 0x18;
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 6;
  } while (iVar1 < 0x32);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00502451
// Address: 00502451
// XREFS: None
void FUN_00502451(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x00502451:
  iVar3 = 0x4b;
  iVar4 = 0xc;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      goto code_r0x00502451;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_0050245d
// Address: 0050245d
// XREFS: None
void FUN_0050245d(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x0050245d:
  iVar3 = 0x5d;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,unaff_EDI,-1,-1,-1,-1,-1,-1,
                        -1,-1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar1 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar1 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    unaff_EDI = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      unaff_EDI = 0xc;
      goto LAB_005024bd;
    case 3:
      goto code_r0x0050245d;
    case 4:
      iVar3 = 0x27;
      unaff_EDI = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      unaff_EDI = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      unaff_EDI = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      unaff_EDI = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      unaff_EDI = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      unaff_EDI = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  unaff_EDI = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_00502464
// Address: 00502464
// XREFS: None
void FUN_00502464(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x00502464:
  iVar3 = 0x27;
  iVar4 = 0x57;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      goto code_r0x00502464;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_00502470
// Address: 00502470
// XREFS: None
void FUN_00502470(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x00502470:
  iVar3 = 0x49;
  iVar4 = 0xc;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      goto code_r0x00502470;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_0050247c
// Address: 0050247c
// XREFS: None
void FUN_0050247c(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x0050247c:
  iVar3 = 5;
  iVar4 = 0x57;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      goto code_r0x0050247c;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_00502488
// Address: 00502488
// XREFS: None
void FUN_00502488(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x00502488:
  iVar3 = 299;
LAB_005024b8:
  iVar4 = 0x65;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      iVar3 = 0x25;
      goto LAB_005024b8;
    case 2:
      goto FUN_00502451;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      goto code_r0x00502488;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
FUN_00502451:
  iVar3 = 0x4b;
  iVar4 = 0xc;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_0050248f
// Address: 0050248f
// XREFS: None
void FUN_0050248f(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x0050248f:
  iVar3 = 4;
  iVar4 = 0x57;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      goto code_r0x0050248f;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_0050249b
// Address: 0050249b
// XREFS: None
void FUN_0050249b(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x0050249b:
  iVar3 = 0x7d;
  iVar4 = 0x68;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      goto code_r0x0050249b;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_005024a7
// Address: 005024a7
// XREFS: None
void FUN_005024a7(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x005024a7:
  iVar3 = 0x29;
  iVar4 = 0x57;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      goto code_r0x005024a7;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_005024b3
// Address: 005024b3
// XREFS: None
void FUN_005024b3(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x005024b3:
  iVar3 = 0x28;
LAB_005024b8:
  iVar4 = 0x65;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      iVar3 = 0x25;
      goto LAB_005024b8;
    case 2:
      goto FUN_00502451;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      goto code_r0x005024b3;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
FUN_00502451:
  iVar3 = 0x4b;
  iVar4 = 0xc;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_005025ca
// Address: 005025ca
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
uint __fastcall FUN_005025ca(int param_1,int param_2)
{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  RGE_Player *pRVar4;
  uint in_EAX;
  int iVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  int unaff_EBX;
  int unaff_EBP;
  int iVar9;
  int *piVar10;
  uint uStack_28;
  int iStack_24;
  int iStack_1c;
  uint uStack_18;
  
  piVar10 = (int *)(in_EAX + param_2 * 2);
  *piVar10 = (int)(&stack0x00000000 + *piVar10);
  *(char *)(param_2 + 0x24) = *(char *)(param_2 + 0x24) + (char)param_1;
  *(char *)(param_1 + 0x24) = *(char *)(param_1 + 0x24) + (char)param_2;
  *(char *)(unaff_EBP + 0x24) = *(char *)(unaff_EBP + 0x24) + (char)unaff_EBX;
  cVar8 = (char)((uint)param_2 >> 8);
  *(char *)(in_EAX + 0x24) = *(char *)(in_EAX + 0x24) + cVar8;
  *(char *)(in_EAX + 0x8f005024) = *(char *)(in_EAX + 0x8f005024) + (char)param_1;
  uStack_18 = in_EAX & 0xffffff50;
  *(char *)(unaff_EBX + -0x58ffafdc) = *(char *)(unaff_EBX + -0x58ffafdc) + (char)unaff_EBX;
  *(char *)(unaff_EBX + -0x6fffafdc) = *(char *)(unaff_EBX + -0x6fffafdc) + cVar8;
  if (*(int *)(param_1 + 0x47c) != -1) {
    iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 4);
    iVar7 = iVar3 - *(int *)(param_1 + 0xf98);
    uStack_18 = -(iVar7 >> 0x1f);
    if (*(int *)(param_1 + 0x47c) <= iVar7 / 1000) {
      *(int *)(param_1 + 0xf98) = iVar3;
      iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c);
      if (*(char *)(iVar3 + 0x11d) == -1) {
        iVar9 = 1;
        iVar7 = 0;
        if (1 < *(short *)(iVar3 + 0x3c)) {
          do {
            iVar5 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar9 * 4))
            ;
            if (iVar5 == 1) {
              iVar7 = iVar7 + 1;
            }
            uStack_18 = (uint)*(short *)(iVar3 + 0x3c);
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)uStack_18);
        }
        if (iVar7 == 1) {
          uVar1 = *(undefined1 *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a);
          uStack_18 = CONCAT31((int3)(uStack_18 >> 8),uVar1);
          *(undefined1 *)(iVar3 + 0x11d) = uVar1;
        }
        else {
          iVar9 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x31f0);
          uStack_18 = iVar9 / iVar7;
          iVar5 = 1;
          iStack_24 = iVar9 % iVar7 + 1;
          if (1 < *(short *)(iVar3 + 0x3c)) {
            do {
              pRVar4 = *(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar5 * 4);
              iVar7 = RGE_Player::computerPlayer(pRVar4);
              if ((iVar7 == 1) && (iStack_24 = iStack_24 + -1, iStack_24 == 0)) {
                *(char *)(iVar3 + 0x11d) = (char)pRVar4->id;
              }
              uStack_18 = (uint)*(short *)(iVar3 + 0x3c);
              iVar5 = iVar5 + 1;
            } while (iVar5 < (int)uStack_18);
          }
        }
      }
      uStack_18 = CONCAT31((int3)(uStack_18 >> 8),*(char *)(iVar3 + 0x11d));
      if (*(char *)(iVar3 + 0x11d) == *(char *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a)) {
        uStack_28 = *(uint *)(param_1 + 0x480);
        piVar10 = (int *)(param_1 + 0xd88);
        uStack_18 = 0;
        do {
          if ((int)uStack_28 < 1) {
            return uStack_28;
          }
          if (((((*piVar10 != 0) ||
                (iVar7 = TribeResourceAIModule::resource
                                   ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),0)
                , iVar7 < *(int *)(param_1 + 0x48c))) &&
               ((*piVar10 != 1 ||
                (iVar7 = TribeResourceAIModule::resource
                                   ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),1)
                , iVar7 < *(int *)(param_1 + 0x490))))) &&
              (((*piVar10 != 3 ||
                (iVar7 = TribeResourceAIModule::resource
                                   ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),3)
                , iVar7 < *(int *)(param_1 + 0x498))) &&
               ((*piVar10 != 2 ||
                (iVar7 = TribeResourceAIModule::resource
                                   ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),2)
                , iVar7 < *(int *)(param_1 + 0x494))))))) &&
             ((piVar10[4] < 0 && (iStack_1c = 1, 1 < *(short *)(iVar3 + 0x3c))))) {
            do {
              if ((int)uStack_28 < 1) break;
              pRVar4 = *(RGE_Player **)(*(int *)(iVar3 + 0x40) + iStack_1c * 4);
              if (((pRVar4->id != *(short *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a)) &&
                  (iVar7 = RGE_Player::computerPlayer(pRVar4), iVar7 != 0)) &&
                 (iVar7 = (**(code **)(**(int **)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x1c))
                                    (iStack_1c), iVar7 != 0)) {
                iVar7 = pRVar4->_padding_;
                iVar9 = (**(code **)(iVar7 + 0x1c))
                                  ((int)*(short *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a)
                                  );
                if (iVar9 != 0) {
                  uVar2 = *(ushort *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a);
                  if ((((short)uVar2 < pRVar4->id) &&
                      (pRVar4->id != (ushort)*(byte *)(iVar3 + 0x11d))) ||
                     (uVar2 == *(byte *)(iVar3 + 0x11d))) {
                    iVar9 = *piVar10;
                    uVar6 = __ftol();
                    if (0x32 < (int)uVar6) {
                      if ((int)uStack_28 < (int)uVar6) {
                        uVar6 = uStack_28;
                      }
                      uStack_28 = uStack_28 - uVar6;
                      (**(code **)(iVar7 + 0x54))((int)(short)uVar2,1,iVar9,uVar6,0);
                    }
                  }
                }
              }
              iStack_1c = iStack_1c + 1;
            } while (iStack_1c < *(short *)(iVar3 + 0x3c));
          }
          piVar10 = piVar10 + 1;
          uStack_18 = uStack_18 + 1;
        } while ((int)uStack_18 < 4);
      }
    }
  }
  return uStack_18;
}

// --------------------------------------------------

// Function: FUN_00504dc6
// Address: 00504dc6
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
int __fastcall FUN_00504dc6(UnitAIModule *param_1,int *param_2)
{
  code *pcVar1;
  char cVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  int unaff_EBX;
  int unaff_EBP;
  ulong unaff_ESI;
  float10 fVar10;
  float fVar11;
  int iStack00000034;
  UnitAIModule *pUStack0000003c;
  NotifyEvent *in_stack_00000044;
  ulong in_stack_00000048;
  
  *(char *)(unaff_EBX + -0x4cffafb3) =
       *(char *)(unaff_EBX + -0x4cffafb3) + (char)((uint)param_1 >> 8);
  cVar2 = (char)((uint)unaff_EBX >> 8);
  cRam3e00a09a = cRam3e00a09a + cVar2;
  cRam5b00a09a = cRam5b00a09a + cVar2;
  iStack00000034 = unaff_EBP + -4;
  cRam9b00504d = cRam9b00504d + 'M';
  *param_2 = *param_2 + -0x64ffafb3;
  pUStack0000003c = param_1;
  switch(in_stack_00000044->mType) {
  case 500:
    goto switchD_00504e34_caseD_1f4;
  default:
    iVar9 = UnitAIModule::processNotify(param_1,in_stack_00000044,in_stack_00000048);
    return iVar9;
  case 0x1f9:
    if (param_1->currentActionValue != in_stack_00000044->p1) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      fprintf();
      iVar9 = param_1->_padding_;
      (**(code **)(iVar9 + 0x58))();
      (**(code **)(iVar9 + 0x1c))();
      return 2;
    }
    break;
  case 0x1fa:
    if (param_1->currentActionValue != in_stack_00000044->p1) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      fprintf();
      iVar9 = param_1->_padding_;
      (**(code **)(iVar9 + 0x58))();
      (**(code **)(iVar9 + 0x1c))();
      return 2;
    }
    break;
  case 0x1fb:
  case 0x202:
    iVar9 = param_1->currentActionValue;
    if (iVar9 == 0x265) {
      if ((param_1->currentTargetTypeValue == -1) && (param_1->lastTargetTypeValue == -1)) {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          fprintf();
        }
        iVar9 = param_1->_padding_;
        (**(code **)(iVar9 + 0x58))();
        (**(code **)(iVar9 + 0x1c))();
        return 2;
      }
      iVar9 = param_1->_padding_;
      iVar4 = (**(code **)(iVar9 + 0xc0))();
      if (iVar4 == -1) {
        iVar4 = (**(code **)(iVar9 + 0x40))();
      }
      else {
        iVar4 = (**(code **)(iVar9 + 0x44))();
      }
      if (iVar4 == -1) {
        iVar4 = RGE_Player::computerPlayer(param_1->objectValue->owner);
        if (iVar4 == 1) {
          UnitAIModule::removeCurrentTarget(param_1);
          goto joined_r0x0050570c;
        }
      }
      else {
        iVar4 = (**(code **)(iVar9 + 100))();
        if (iVar4 == 1) {
          return 3;
        }
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          fprintf();
        }
        (**(code **)(iVar9 + 0x58))();
LAB_00505742:
        (**(code **)(iVar9 + 0x1c))();
      }
    }
    else if (iVar9 == 0x261) {
      if ((param_1->currentTargetTypeValue == -1) && (param_1->lastTargetTypeValue == -1)) {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          fprintf();
        }
        iVar9 = param_1->_padding_;
        (**(code **)(iVar9 + 0x58))();
        (**(code **)(iVar9 + 0x1c))();
        return 2;
      }
      iVar9 = param_1->_padding_;
      iVar4 = (**(code **)(iVar9 + 0xc0))();
      if (iVar4 == -1) {
        iVar4 = (**(code **)(iVar9 + 0x40))();
      }
      else {
        iVar4 = (**(code **)(iVar9 + 0x44))();
      }
      if (iVar4 != -1) {
        iVar4 = (**(code **)(iVar9 + 0x68))();
        if (iVar4 == 1) {
          return 3;
        }
        UnitAIModule::removeCurrentTarget(param_1);
joined_r0x0050570c:
        if (actionFile != (_iobuf *)0x0) {
          fprintf();
        }
        (**(code **)(iVar9 + 0x58))();
        goto LAB_00505742;
      }
      iVar4 = RGE_Player::computerPlayer(param_1->objectValue->owner);
      if (iVar4 == 1) {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile == (_iobuf *)0x0) {
LAB_005056e2:
          (**(code **)(iVar9 + 0x58))();
        }
        else {
          fprintf();
          (**(code **)(iVar9 + 0x58))();
        }
        goto LAB_00505742;
      }
      if (in_stack_00000044->p2 == 0x32) {
        fVar11 = _DAT_005758d0;
        if (_DAT_005758c8 < param_1->objectValue->world_x) {
          fVar11 = _DAT_005758cc;
        }
        pUStack0000003c = (UnitAIModule *)(param_1->objectValue->world_x - fVar11);
        (**(code **)(iVar9 + 0x9c))();
      }
    }
    else if (iVar9 == 0x25a) {
      iVar9 = param_1->_padding_;
      pcVar1 = *(code **)(iVar9 + 0x40);
      iVar4 = (*pcVar1)();
      if (((iVar4 == -1) && (iVar4 = (*pcVar1)(), iVar4 == -1)) ||
         (iVar4 = (**(code **)(param_1->objectValue->_padding_ + 0x194))(), iVar4 != 1)) {
        pRVar3 = UnitAIModule::lookupObject(param_1,param_1->currentTargetValue);
        if ((pRVar3 == (RGE_Static_Object *)0x0) ||
           (fVar11 = RGE_Static_Object::distance_to_object(param_1->objectValue,pRVar3),
           _DAT_005758bc < fVar11)) {
          (**(code **)(iVar9 + 0x90))();
        }
      }
      else {
        iVar9 = (**(code **)(iVar9 + 0x78))();
        if (iVar9 == 1) {
          return 3;
        }
      }
    }
    else if (iVar9 == 0x25d) {
      iVar9 = param_1->_padding_;
      iVar4 = (**(code **)(iVar9 + 0x48))();
      if (iVar4 == 1) {
        UnitAIModule::addToWaypointQueue(param_1,(int)pUStack0000003c,in_stack_00000048);
        iVar4 = (**(code **)(iVar9 + 0x80))();
        if (iVar4 != 0) {
          return 3;
        }
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          fprintf();
        }
        goto LAB_005056e2;
      }
      UnitAIModule::removeCurrentTarget(param_1);
      goto joined_r0x0050570c;
    }
    if (in_stack_00000044->mType == 0x202) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      fprintf();
    }
    break;
  case 0x20f:
    iVar9 = RGE_Game_World::difficultyLevel(param_1->objectValue->owner->world);
    if (2 < iVar9) {
      return 2;
    }
switchD_00504e34_caseD_1f4:
    if (in_stack_00000044->p2 < 1) {
      (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))();
      UnitAIModule::purgeNotifyQueue(param_1,unaff_ESI);
      return 4;
    }
    pRVar3 = UnitAIModule::lookupObject(param_1,in_stack_00000044->caller);
    pUStack0000003c =
         (UnitAIModule *)UnitAIModule::lookupObject(param_1,param_1->currentTargetValue);
    if (pRVar3 == (RGE_Static_Object *)0x0) {
      return 2;
    }
    iVar9 = RGE_Player::computerPlayer(param_1->objectValue->owner);
    if (iVar9 == 1) {
      if ((pRVar3->owner->id == 0) && (pRVar3->id == param_1->currentTargetValue))
      goto LAB_00504f1d;
    }
    else if ((param_1->attackingUnitsValue).numberValue != 0) goto LAB_00504f1d;
    (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))();
LAB_00504f1d:
    iVar9 = (param_1->attackingUnitsValue).numberValue;
    iVar4 = 0;
    if (0 < iVar9) {
      do {
        if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar4) break;
        if ((param_1->attackingUnitsValue).value[iVar4] == in_stack_00000044->caller)
        goto LAB_00504f5e;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar9);
    }
    iVar9 = RGE_Player::computerPlayer(param_1->objectValue->owner);
    if ((iVar9 == 0) && (param_1->currentTargetValue != in_stack_00000044->caller)) {
      UnitAIModule::askForHelp(param_1,in_stack_00000044->caller);
    }
LAB_00504f5e:
    iVar9 = (param_1->attackingUnitsValue).numberValue;
    iVar4 = in_stack_00000044->caller;
    iVar5 = 0;
    if (0 < iVar9) {
      do {
        if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar5) break;
        if ((param_1->attackingUnitsValue).value[iVar5] == iVar4) goto LAB_00504fe4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar9);
    }
    if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar9) {
      iVar9 = iVar9 + 1;
      piVar6 = (int *)operator_new(iVar9 * 4);
      if (piVar6 != (int *)0x0) {
        iVar5 = 0;
        if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
          do {
            if (iVar9 <= iVar5) break;
            iVar7 = iVar5 + 1;
            piVar6[iVar5] = (param_1->attackingUnitsValue).value[iVar5];
            iVar5 = iVar7;
          } while (iVar7 < (param_1->attackingUnitsValue).maximumSizeValue);
        }
        operator_delete((param_1->attackingUnitsValue).value);
        (param_1->attackingUnitsValue).value = piVar6;
        (param_1->attackingUnitsValue).maximumSizeValue = iVar9;
      }
    }
    (param_1->attackingUnitsValue).value[(param_1->attackingUnitsValue).numberValue] = iVar4;
    (param_1->attackingUnitsValue).numberValue = (param_1->attackingUnitsValue).numberValue + 1;
LAB_00504fe4:
    (**(code **)(param_1->objectValue->_padding_ + 0xec))();
    fVar10 = (float10)(**(code **)(param_1->objectValue->_padding_ + 0xf4))();
    cVar2 = (**(code **)(param_1->objectValue->_padding_ + 0x134))();
    iVar9 = param_1->currentOrderValue;
    if ((iVar9 == 0x2c6) && (_DAT_005758c4 < (float)fVar10)) {
      return 2;
    }
    if (iVar9 == 700) {
      return 2;
    }
    if ((((iVar9 == 0x2c9) && (cVar2 == '\f')) && (unaff_EBX != 0)) &&
       ((*(short *)(*(int *)(unaff_EBX + 8) + 0x14) == 10 &&
        (*(short *)(in_stack_00000044->p1 + 0x4a) == 0)))) {
      return 2;
    }
    if (iVar9 == 0x2ce) {
      return 2;
    }
    if (*(short *)(in_stack_00000044->p1 + 0x4a) != 0) {
      if ((param_1->currentActionValue == 0x262) && ((float)fVar10 != _DAT_005758c4)) {
        return 3;
      }
      iVar9 = param_1->_padding_;
      (**(code **)(iVar9 + 0x10))(param_1->objectValue->id);
      if (actionFile != (_iobuf *)0x0) {
        if (param_1->objectValue == (RGE_Static_Object *)0x0) {
          lVar8 = -1;
        }
        else {
          lVar8 = param_1->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar8,s_C__msdev_work_age1_x1_taiuaimd_c,
                0x39a);
      }
      (**(code **)(iVar9 + 0x58))(1);
      (**(code **)(iVar9 + 0xa4))(1);
      return 3;
    }
    if (iVar9 != -1) {
      iVar9 = param_1->_padding_;
      (**(code **)(iVar9 + 0x10))(param_1->objectValue->id);
      param_1->currentOrderValue = 700;
      param_1->currentOrderPriorityValue = 100;
      (**(code **)(iVar9 + 0x5c))(in_stack_00000044->caller,1);
      param_1->stopAfterTargetKilledValue = '\x01';
      return 3;
    }
    (**(code **)(param_1->_padding_ + 0x5c))();
    return 3;
  }
  iVar9 = param_1->_padding_;
  (**(code **)(iVar9 + 0x58))();
  (**(code **)(iVar9 + 0x1c))();
  return 2;
}

// --------------------------------------------------

// Function: FUN_005057be
// Address: 005057be
// XREFS: None
undefined4 __fastcall FUN_005057be(int param_1,int *param_2)
{
  int in_EAX;
  char cVar1;
  char *unaff_retaddr;
  
  *(char *)param_2 = (char)*param_2 + (char)in_EAX;
  unaff_retaddr[0x69005051] = unaff_retaddr[0x69005051] + (char)unaff_retaddr;
  cVar1 = (char)((uint)param_1 >> 8);
  *(char *)(param_1 + 0x52) = *(char *)(param_1 + 0x52) + cVar1;
  *unaff_retaddr = *unaff_retaddr + (char)((uint)unaff_retaddr >> 8);
  *(char *)(param_1 + 0x5057) = *(char *)(param_1 + 0x5057) + cVar1;
  *param_2 = *param_2 + in_EAX;
  return 5;
}

// --------------------------------------------------

// Function: FUN_00505dc7
// Address: 00505dc7
// XREFS: processNotify
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
int __thiscall FUN_00505dc7(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  uchar uVar1;
  long lVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  undefined4 uVar6;
  
  switch(param_2->mType) {
  case 0x1f9:
  case 0x1fb:
  case 0x202:
    break;
  case 0x1fc:
    pRVar4 = UnitAIModule::lookupObject(param_1,param_1->currentTargetValue);
    if (pRVar4 != (RGE_Static_Object *)0x0) {
      iVar5 = __ftol();
      iVar3 = __ftol();
      uVar1 = UnitAIModule::visibleStatus(param_1,param_1->objectValue->owner->visible,iVar3,iVar5);
      if (uVar1 == '\x0f') {
        return 2;
      }
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar2 = -1;
      }
      else {
        lVar2 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar2,s_C__msdev_work_age1_x1_taiuaimd_c,0x68f
             );
    }
    iVar5 = param_1->_padding_;
    (**(code **)(iVar5 + 0x58))(1);
    (**(code **)(iVar5 + 0x1c))(param_2);
  default:
    iVar5 = UnitAIModule::processNotify(param_1,param_2,param_3);
    return iVar5;
  }
  iVar5 = RGE_Player::computerPlayer(param_1->objectValue->owner);
  if ((iVar5 == 0) && (param_1->currentActionValue == 0x25c)) {
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar2 = -1;
      }
      else {
        lVar2 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar2,s_C__msdev_work_age1_x1_taiuaimd_c,0x63b
             );
    }
    iVar5 = param_1->_padding_;
    uVar6 = 1;
  }
  else {
    if (param_1->currentActionValue == 0x25c) {
      iVar5 = param_1->_padding_;
      iVar3 = (**(code **)(iVar5 + 0xe4))(0);
      if ((iVar3 != -1) && (iVar5 = (**(code **)(iVar5 + 0x6c))(iVar3,1), iVar5 == 1)) {
        return 3;
      }
    }
    else if (param_1->currentActionValue == 0x25b) {
      iVar5 = param_1->_padding_;
      iVar3 = (**(code **)(iVar5 + 0xe0))(0,0);
      if ((iVar3 != -1) && (iVar5 = (**(code **)(iVar5 + 0x70))(iVar3,1), iVar5 == 1)) {
        return 3;
      }
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar2 = -1;
      }
      else {
        lVar2 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar2,s_C__msdev_work_age1_x1_taiuaimd_c,0x675
             );
    }
    iVar5 = param_1->_padding_;
    uVar6 = 0;
  }
  (**(code **)(iVar5 + 0x58))(uVar6);
  (**(code **)(iVar5 + 0x1c))(param_2);
  return 2;
}

// --------------------------------------------------

// Function: FUN_00505fa9
// Address: 00505fa9
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
undefined4 __fastcall FUN_00505fa9(undefined4 param_1,char param_2)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  char cVar5;
  UnitAIModule *this;
  char cVar6;
  char *unaff_EBX;
  int unaff_ESI;
  float10 fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined1 auStack_4 [4];
  
  cVar6 = (char)((uint)unaff_EBX >> 8);
  cVar5 = (char)param_1 + cVar6;
  *unaff_EBX = *unaff_EBX + cVar5;
  this = (UnitAIModule *)CONCAT31((int3)((uint)param_1 >> 8),cVar5 + cVar6);
  *(char *)(unaff_ESI + 0x505f) = *(char *)(unaff_ESI + 0x505f) + param_2;
  iVar2 = RGE_Player::computerPlayer(this->objectValue->owner);
  if (iVar2 != 0) {
    iVar3 = UnitAIModule::processIdle(this,1);
    iVar2 = DAT_0087d7d8;
    if (iVar3 == 6) {
      return 6;
    }
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_taiuaimd_c,0x6ac);
    if ((0 < iVar2) && (iVar2 < iVar3 % (iVar2 + 2))) {
      iVar2 = this->_padding_;
      iVar3 = (**(code **)(iVar2 + 0xe0))(1,auStack_4);
      if (iVar3 != -1) {
        (**(code **)(iVar2 + 0x70))(iVar3,0);
        return 6;
      }
    }
    iVar2 = this->_padding_;
    iVar3 = (**(code **)(iVar2 + 0x40))(0xffffffff,2,0xffffffff,0xffffffff,0);
    if (iVar3 != -1) {
      pRVar4 = RGE_Game_World::object(this->objectValue->owner->world,iVar3);
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        pRVar1 = this->objectValue;
        fVar9 = pRVar4->world_x - pRVar1->world_x;
        fVar8 = pRVar4->world_y - pRVar1->world_y;
        fVar10 = SQRT(fVar8 * fVar8 + fVar9 * fVar9);
        fVar7 = (float10)(**(code **)(pRVar1->_padding_ + 0x10c))();
        fVar7 = fVar7 - (float10)fVar10;
        if (fVar7 <= (float10)_DAT_005758c4) {
          return 5;
        }
        pRVar4 = this->objectValue;
        (**(code **)(iVar2 + 0x9c))
                  ((float)(-(((float10)fVar9 / (float10)fVar10) * fVar7) + (float10)pRVar4->world_x)
                   ,(float)(-(((float10)fVar8 / (float10)fVar10) * fVar7) + (float10)pRVar4->world_y
                           ),pRVar4->world_z,1);
        return 6;
      }
    }
  }
  return 5;
}

// --------------------------------------------------

// Function: FUN_0050942f
// Address: 0050942f
// XREFS: None
TTaunt * __fastcall FUN_0050942f(int param_1,int param_2)
{
  char *pcVar1;
  TSound_Driver *in_EAX;
  TTaunt *this;
  int unaff_EBX;
  
  *(char *)(param_1 + -0x6d) = *(char *)(param_1 + -0x6d) + (char)param_2;
  pcVar1 = (char *)(unaff_EBX + -0x6c66ffb0 + param_2 * 4);
  *pcVar1 = *pcVar1 + (char)in_EAX;
  this = (TTaunt *)
         CONCAT22((short)((uint)param_1 >> 0x10),
                  CONCAT11((char)((uint)param_1 >> 8) + (char)((uint)in_EAX >> 8),(char)param_1));
  *(char *)(unaff_EBX + -0x6f6f6f70) = *(char *)(unaff_EBX + -0x6f6f6f70) + (char)param_2;
  this->TauntDir[0] = '\0';
  TTaunt::RestartSoundSystem(this,in_EAX);
  this->Mute = 0;
  return this;
}

// --------------------------------------------------

// Function: FUN_00509859
// Address: 00509859
// XREFS: None
void __fastcall FUN_00509859(undefined4 param_1,int *param_2)
{
  undefined4 uVar1;
  char *pcVar2;
  TRIBE_Building_Object *this;
  byte bVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  byte *unaff_EBX;
  int unaff_EBP;
  int iVar7;
  undefined4 unaff_EDI;
  undefined2 in_CS;
  int iStack_1b8;
  
  uVar1 = in((short)param_2);
  *(char *)(unaff_EBP + -0x4effaf69) =
       *(char *)(unaff_EBP + -0x4effaf69) + (char)((uint)unaff_EDI >> 8);
  cVar6 = (char)((uint)unaff_EBX >> 8);
  *(char *)(unaff_EBP + -0x1effaf69) = *(char *)(unaff_EBP + -0x1effaf69) + cVar6;
  bVar3 = (char)param_1 * '\x02' + cVar6;
  cRam11005098 = cRam11005098 + (char)uVar1;
  cRam29005098 = cRam29005098 + (char)unaff_EBX;
  cRam41005098 = cRam41005098 + (char)((uint)param_2 >> 8);
  pcVar2 = (char *)(int)(short)uVar1;
  *(char *)(unaff_EBP + -0x68) = *(char *)(unaff_EBP + -0x68) + bVar3;
  *pcVar2 = *pcVar2 + (char)uVar1;
  *param_2 = (int)(pcVar2 + *param_2);
  iVar4 = CONCAT31((int3)(CONCAT22((short)((uint)param_1 >> 0x10),
                                   CONCAT11((char)((uint)param_1 >> 8) + (char)param_2,(char)param_1
                                           )) >> 8),bVar3 | *unaff_EBX);
  iStack_1b8 = CONCAT22(iStack_1b8._2_2_,in_CS);
  iVar5 = (uint)*(byte *)(iStack_1b8 + 4) * 4;
  iVar7 = *(short *)(iStack_1b8 + 2) * 4;
  if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 0x40) + iVar5) + 0x24) +
                        iVar7) + 0x68) == '\x01') {
    *(undefined4 *)(iStack_1b8 + 0x10) = 0x40800000;
  }
  iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 4) + 0x40) + iVar5);
  this = (TRIBE_Building_Object *)
         (**(code **)(**(int **)(*(int *)(iVar4 + 0x24) + iVar7) + 0x18))
                   (iVar4,*(undefined4 *)(iStack_1b8 + 8),*(undefined4 *)(iStack_1b8 + 0xc),
                    *(undefined4 *)(iStack_1b8 + 0x10));
  if (*(char *)(this->_padding_ + 4) == 'P') {
    TRIBE_Building_Object::build(this,10000.0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050a465
// Address: 0050a465
// XREFS: None
void __fastcall FUN_0050a465(int param_1,undefined4 param_2)
{
  byte bVar1;
  byte bVar2;
  undefined4 in_EAX;
  RGE_Static_Object *pRVar5;
  char *unaff_EBX;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  byte in_CF;
  byte in_AF;
  int iVar6;
  int iVar7;
  int iVar8;
  char cVar3;
  int iVar4;
  
  bVar1 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  bVar2 = (byte)in_EAX + bVar1 * '\x06';
  cVar3 = bVar2 + (0x90 < (bVar2 & 0xf0) | in_CF | bVar1 * (0xf9 < bVar2)) * '`';
  iVar4 = CONCAT31((int3)((uint)in_EAX >> 8),cVar3);
  cRam0c0050a4 = cRam0c0050a4 + (char)param_1;
  cRama2720050 = cVar3;
  cRama41e0050 = cVar3;
  iRama44b0050 = iVar4;
  *unaff_EBX = *unaff_EBX + (char)((uint)param_2 >> 8) + (char)((uint)param_1 >> 8);
  *unaff_EDI = *unaff_ESI;
  unaff_EBX[-0x6fffaf5e] = unaff_EBX[-0x6fffaf5e] + cVar3;
  iVar6 = iVar4;
  iVar7 = iVar4;
  iVar8 = iVar4;
  pRVar5 = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),*(int *)(iVar4 + 4));
  if (pRVar5 != (RGE_Static_Object *)0x0) {
    (**(code **)(pRVar5->_padding_ + 0x240))(iVar4,iVar6,iVar7,iVar8);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0050daf5
// Address: 0050daf5
// XREFS: None
void __fastcall FUN_0050daf5(int param_1,int param_2)
{
  char *pcVar1;
  int unaff_EBX;
  
  pcVar1 = (char *)(param_2 + 0x50 + unaff_EBX * 8);
  *pcVar1 = *pcVar1 + (char)unaff_EBX;
  *(char *)(param_1 + -0x24ffaf26) = *(char *)(param_1 + -0x24ffaf26) + (char)((uint)param_2 >> 8);
  return;
}

// --------------------------------------------------

// Function: FUN_005103f3
// Address: 005103f3
// XREFS: None
undefined8 __fastcall FUN_005103f3(char *param_1,undefined4 param_2)
{
  byte bVar1;
  undefined4 in_EAX;
  int iVar2;
  char cVar3;
  int unaff_retaddr;
  uint *puVar4;
  
  cVar3 = (char)param_2 + *param_1;
  puVar4 = (uint *)CONCAT31((int3)((uint)param_2 >> 8),cVar3);
  bVar1 = (byte)param_1 & 0x1f;
  *puVar4 = *puVar4 << bVar1 | *puVar4 >> 0x20 - bVar1;
  iVar2 = unaff_retaddr + 2;
  if (3 < iVar2) {
    iVar2 = unaff_retaddr + -2;
  }
  return CONCAT44(CONCAT31((int3)(CONCAT22((short)((uint)param_2 >> 0x10),
                                           CONCAT11((char)((uint)param_2 >> 8) +
                                                    (char)((uint)in_EAX >> 8),cVar3)) >> 8),
                           cVar3 + *param_1),iVar2);
}

// --------------------------------------------------

// Function: FUN_00513f95
// Address: 00513f95
// XREFS: None
void FUN_00513f95(void)
{
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_005159ba
// Address: 005159ba
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
void __fastcall FUN_005159ba(int *param_1,int param_2)
{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  undefined4 in_EAX;
  undefined3 uVar7;
  uint uVar6;
  undefined4 unaff_EBX;
  byte in_CF;
  byte in_AF;
  undefined1 unaff_retaddr;
  undefined4 uStack00000005;
  undefined1 in_stack_00000001 [11];
  undefined3 uStack_f;
  undefined1 uStack_c;
  undefined3 uStack_b;
  int *piStack_8;
  char cVar5;
  
  bVar2 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  uVar7 = (undefined3)((uint)in_EAX >> 8);
  bVar4 = (byte)in_EAX + bVar2 * -6;
  cVar5 = bVar4 + (0x9f < bVar4 | in_CF | bVar2 * (bVar4 < 6)) * -0x60;
  cRam4b005154 = cRam4b005154 + (char)((uint)unaff_EBX >> 8);
  *(char *)(param_2 + 0x54) = *(char *)(param_2 + 0x54) + (char)param_2;
  pcVar1 = (char *)(CONCAT31(uVar7,cVar5) + 0x54);
  *pcVar1 = *pcVar1 + (char)((uint)in_EAX >> 8);
  *(char *)((int)param_1 + -0x75) = *(char *)((int)param_1 + -0x75) + (char)param_2;
  uVar6 = CONCAT31(uVar7,cVar5) & 0xffffff10;
  piStack_8 = param_1;
  if (uVar6 - 0x201 < 0xc) {
    (*(code *)(&switchD_005159f1::switchdataD_00515b88)[*(byte *)(uVar6 + 0x51599b)])();
    return;
  }
  uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x949);
  iVar3 = debug_random_on;
  global_save_debug_random_on4 = debug_random_on;
  debug_random_on = 0;
  if (param_1[0x8e] != 0) {
    uStack_b = (undefined3)((uint)&piStack_8 >> 8);
    uStack_f = (undefined3)((uint)param_1 >> 8);
    uStack_c = SUB41(&piStack_8,0);
    (**(code **)(*param_1 + 0x128))
              (CONCAT13(uStack_c,uStack_f),CONCAT13(piStack_8._0_1_,uStack_b),(uint)piStack_8 >> 8,
               CONCAT13(unaff_retaddr,(int3)((uint)&stack0x00000000 >> 8)),in_stack_00000001._0_4_,
               uStack00000005);
  }
  debug_random_on = iVar3;
  debug_srand(s_C__msdev_work_age1_x1_tplayer_cp,0x956,uVar6);
  return;
}

// --------------------------------------------------

// Function: FUN_00515dc3
// Address: 00515dc3
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
// [HELPER] s_RandomGameSpecialized: "RandomGameSpecialized"
undefined4 __fastcall FUN_00515dc3(int param_1,char param_2)
{
  char cVar1;
  uchar uVar2;
  char *in_EAX;
  int *piVar3;
  int iVar4;
  undefined4 extraout_EAX;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  TRIBE_Player *unaff_EBP;
  int unaff_ESI;
  int iVar10;
  int iVar11;
  char *pcVar12;
  int unaff_EDI;
  undefined4 *puVar13;
  char *pcVar14;
  bool in_ZF;
  int in_stack_00000010;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  int in_stack_00000030;
  int in_stack_00000034;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  int in_stack_00000044;
  int in_stack_00000048;
  int in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  int in_stack_0000006c;
  int in_stack_000000b8;
  int in_stack_000000bc;
  int in_stack_000000c0;
  int in_stack_000000c8;
  int in_stack_000000cc;
  int in_stack_000000d0;
  int in_stack_000000d4;
  int in_stack_000000d8;
  int in_stack_000000dc;
  int in_stack_000000e0;
  int in_stack_000000e4;
  int in_stack_000000ec;
  int in_stack_000000f0;
  int in_stack_000000f4;
  int in_stack_000000f8;
  int in_stack_000000fc;
  int in_stack_00000100;
  int in_stack_00000104;
  int in_stack_00000138;
  int in_stack_0000013c;
  int in_stack_00000140;
  int in_stack_00000158;
  int in_stack_0000015c;
  int in_stack_00000160;
  int in_stack_00000168;
  int in_stack_000001a0;
  int in_stack_000001a4;
  int in_stack_000001b0;
  int in_stack_000001b4;
  int in_stack_000001b8;
  int in_stack_000001c4;
  int in_stack_000001c8;
  int in_stack_000001cc;
  int in_stack_000001d8;
  int in_stack_000001dc;
  int in_stack_000001e0;
  char *in_stack_00000300;
  int in_stack_00000304;
  int in_stack_00000308;
  int in_stack_0000030c;
  int in_stack_0000031c;
  int in_stack_00000320;
  int in_stack_00000324;
  
  if (!in_ZF) {
    *(char *)(unaff_EDI + 0x1e00515c) = *(char *)(unaff_EDI + 0x1e00515c) + (char)param_1;
    *(char *)(unaff_EDI + 0x5d) = *(char *)(unaff_EDI + 0x5d) + param_2;
    *(char *)(unaff_ESI + -0x43ffaea3) =
         *(char *)(unaff_ESI + -0x43ffaea3) + (char)((uint)in_EAX >> 8);
    *in_EAX = *in_EAX + (char)in_EAX;
    pcRam05050505 = in_EAX + (int)pcRam05050505;
    return 0;
  }
  LOCK();
  *(int *)(param_1 + -0x46ebdbbc) = *(int *)(param_1 + -0x46ebdbbc) + -1;
  UNLOCK();
  *in_EAX = *in_EAX + (char)in_EAX;
  puVar13 = &stack0x00000018;
  for (; param_1 != 0; param_1 = param_1 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
  switch(*(undefined1 *)((int)&unaff_EBP->_padding_ + 1)) {
  case 1:
    TRIBE_Player::setupEgyptian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 2:
    TRIBE_Player::setupGreek
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 3:
    TRIBE_Player::setupBabylonian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 4:
    TRIBE_Player::setupAssyrian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 5:
    TRIBE_Player::setupMinoan
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 6:
    TRIBE_Player::setupHittite
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 7:
    TRIBE_Player::setupPhoenician
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 8:
    TRIBE_Player::setupSumerian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 9:
    TRIBE_Player::setupPersian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 10:
    TRIBE_Player::setupShang
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0xb:
    TRIBE_Player::setupYamato
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0xc:
    TRIBE_Player::setupChoson
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0xd:
    TRIBE_Player::setupRoman
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0xe:
    TRIBE_Player::setupCarthaginian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0xf:
    TRIBE_Player::setupPalmyran
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0x10:
    TRIBE_Player::setupMacedonian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
  }
  TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xc9,1);
  uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  iVar5 = unaff_ESI;
  if (uVar2 != '\0') goto LAB_005162c8;
  in_stack_00000010 = -1;
  TribeInformationAIModule::loadUnitHistory(&unaff_EBP->playerAI->informationAI);
  TribeInformationAIModule::unitsThatAreMostBuilt
            (&unaff_EBP->playerAI->informationAI,&stack0x00000010,(int *)&stack0x0000020c);
  iVar5 = unaff_ESI;
  switch(in_stack_00000010) {
  case 0:
    in_stack_00000030 = in_stack_00000030 + 0x19;
    in_stack_00000034 = in_stack_00000034 + 0x19;
    iVar5 = unaff_ESI;
    break;
  case 1:
    in_stack_00000030 = in_stack_00000030 + 0x1e;
    in_stack_00000034 = in_stack_00000034 + 0x1e;
    iVar5 = unaff_ESI;
    break;
  case 2:
    in_stack_0000005c = in_stack_0000005c + 0x14;
    in_stack_00000060 = in_stack_00000060 + 0x14;
    in_stack_00000024 = in_stack_00000024 + 0x28;
    in_stack_00000028 = in_stack_00000028 + 0x28;
    iVar5 = unaff_ESI;
    break;
  case 3:
    in_stack_0000005c = in_stack_0000005c + -0x3c;
    in_stack_00000018 = in_stack_00000018 + 0x28;
    in_stack_00000064 = in_stack_00000064 + 0x14;
    in_stack_00000068 = in_stack_00000068 + 0x14;
    in_stack_00000060 = in_stack_00000060 + -0x3c;
    in_stack_0000001c = in_stack_0000001c + 0x14;
    iVar5 = unaff_ESI;
    break;
  case 4:
    in_stack_00000030 = in_stack_00000030 + 0xf;
    in_stack_00000034 = in_stack_00000034 + 0xf;
    iVar5 = 0x14;
    goto LAB_00516297;
  case 5:
    in_stack_00000030 = in_stack_00000030 + 0xf;
    in_stack_00000034 = in_stack_00000034 + 0xf;
    in_stack_00000018 = in_stack_00000018 + 10;
    in_stack_0000001c = in_stack_0000001c + 10;
    iVar5 = unaff_ESI;
    break;
  case 6:
    in_stack_00000030 = in_stack_00000030 + 0xf;
    in_stack_00000034 = in_stack_00000034 + 0xf;
    iVar5 = unaff_ESI;
    break;
  case 7:
  case 10:
    in_stack_00000064 = in_stack_00000064 + -0x3c;
    in_stack_00000068 = in_stack_00000068 + -0x3c;
    iVar5 = unaff_ESI;
    break;
  case 8:
    in_stack_00000064 = in_stack_00000064 + 0x28;
    in_stack_00000068 = in_stack_00000068 + 0x28;
    iVar5 = unaff_ESI;
    break;
  case 9:
    iVar5 = 100;
LAB_00516297:
    in_stack_00000064 = in_stack_00000064 + iVar5;
    in_stack_00000068 = in_stack_00000068 + iVar5;
    iVar5 = unaff_ESI;
  }
LAB_005162c8:
  do {
    in_stack_00000010 = iVar5;
    switch(in_stack_00000010) {
    case 0:
      if (0 < in_stack_00000064) {
        in_stack_00000064 = in_stack_00000064 / 3;
      }
      if (0 < in_stack_00000068) {
        in_stack_00000068 = in_stack_00000068 / 3;
      }
      if (0 < in_stack_0000006c) {
        in_stack_0000006c = in_stack_0000006c / 3;
      }
      break;
    case 1:
      if (0 < in_stack_00000030) {
        in_stack_00000030 = in_stack_00000030 / 3;
      }
      if (0 < in_stack_00000034) {
        in_stack_00000034 = in_stack_00000034 / 3;
      }
      if (0 < in_stack_00000038) {
        in_stack_00000038 = in_stack_00000038 / 3;
      }
      if (0 < in_stack_00000104) {
        in_stack_00000104 = in_stack_00000104 / 3;
      }
      if (0 < in_stack_00000100) {
        in_stack_00000100 = in_stack_00000100 / 3;
      }
      if (0 < in_stack_000000f0) {
        in_stack_000000f0 = in_stack_000000f0 / 3;
      }
      if (0 < in_stack_000000f4) {
        in_stack_000000f4 = in_stack_000000f4 / 3;
      }
      if (0 < in_stack_000001b8) {
        in_stack_000001b8 = in_stack_000001b8 / 3;
      }
      break;
    case 2:
      if (0 < in_stack_00000058) {
        in_stack_00000058 = in_stack_00000058 / 3;
      }
      if (0 < in_stack_000000dc) {
        in_stack_000000dc = in_stack_000000dc / 3;
      }
      if (0 < in_stack_000001c8) {
        in_stack_000001c8 = in_stack_000001c8 / 3;
      }
      break;
    case 3:
      if (0 < in_stack_000000d0) {
        in_stack_000000d0 = in_stack_000000d0 / 3;
      }
      if (0 < in_stack_000000ec) {
        in_stack_000000ec = in_stack_000000ec / 3;
      }
      if (0 < in_stack_0000005c) {
        in_stack_0000005c = in_stack_0000005c / 3;
      }
      if (0 < in_stack_00000060) {
        in_stack_00000060 = in_stack_00000060 / 3;
      }
      if (0 < in_stack_000001a4) {
        in_stack_000001a4 = in_stack_000001a4 / 3;
      }
      if (0 < in_stack_000001b0) {
        in_stack_000001b0 = in_stack_000001b0 / 3;
      }
      if (0 < in_stack_000001cc) {
        in_stack_000001cc = in_stack_000001cc / 3;
      }
      if (0 < in_stack_00000060) {
        in_stack_00000060 = in_stack_00000060 / 3;
      }
      break;
    case 4:
      if (0 < in_stack_00000024) {
        in_stack_00000024 = in_stack_00000024 / 3;
      }
      if (0 < in_stack_00000028) {
        in_stack_00000028 = in_stack_00000028 / 3;
      }
      if (0 < in_stack_0000002c) {
        in_stack_0000002c = in_stack_0000002c / 3;
      }
      if (0 < in_stack_0000003c) {
        in_stack_0000003c = in_stack_0000003c / 3;
      }
      if (0 < in_stack_00000040) {
        in_stack_00000040 = in_stack_00000040 / 3;
      }
      if (0 < in_stack_00000044) {
        in_stack_00000044 = in_stack_00000044 / 3;
      }
      if (0 < in_stack_00000048) {
        in_stack_00000048 = in_stack_00000048 / 3;
      }
      if (0 < in_stack_000000c0) {
        in_stack_000000c0 = in_stack_000000c0 / 3;
      }
      if (0 < in_stack_000000c8) {
        in_stack_000000c8 = in_stack_000000c8 / 3;
      }
      if (0 < in_stack_000000cc) {
        in_stack_000000cc = in_stack_000000cc / 3;
      }
      if (0 < in_stack_000000d4) {
        in_stack_000000d4 = in_stack_000000d4 / 3;
      }
      if (0 < in_stack_000000d8) {
        in_stack_000000d8 = in_stack_000000d8 / 3;
      }
      if (0 < in_stack_000000f8) {
        in_stack_000000f8 = in_stack_000000f8 / 3;
      }
      if (0 < in_stack_00000140) {
        in_stack_00000140 = in_stack_00000140 / 3;
      }
      if (0 < in_stack_000001a0) {
        in_stack_000001a0 = in_stack_000001a0 / 3;
      }
      if (0 < in_stack_000001b4) {
        in_stack_000001b4 = in_stack_000001b4 / 3;
      }
      if (0 < in_stack_000001d8) {
        in_stack_000001d8 = in_stack_000001d8 / 3;
      }
      if (0 < in_stack_000001dc) {
        in_stack_000001dc = in_stack_000001dc / 3;
      }
      break;
    case 5:
      if (0 < in_stack_000000bc) {
        in_stack_000000bc = in_stack_000000bc / 3;
      }
      if (0 < in_stack_00000018) {
        in_stack_00000018 = in_stack_00000018 / 3;
      }
      if (0 < in_stack_0000001c) {
        in_stack_0000001c = in_stack_0000001c / 3;
      }
      if (0 < in_stack_00000020) {
        in_stack_00000020 = in_stack_00000020 / 3;
      }
      if (0 < in_stack_000000bc) {
        in_stack_000000bc = in_stack_000000bc / 3;
      }
      if (0 < in_stack_000000e0) {
        in_stack_000000e0 = in_stack_000000e0 / 3;
      }
      if (0 < in_stack_000000e4) {
        in_stack_000000e4 = in_stack_000000e4 / 3;
      }
      if (0 < in_stack_00000138) {
        in_stack_00000138 = in_stack_00000138 / 3;
      }
      if (0 < in_stack_0000013c) {
        in_stack_0000013c = in_stack_0000013c / 3;
      }
      if (0 < in_stack_000000e0) {
        in_stack_000000e0 = in_stack_000000e0 / 3;
      }
      if (0 < in_stack_000000e4) {
        in_stack_000000e4 = in_stack_000000e4 / 3;
      }
      if (0 < in_stack_00000158) {
        in_stack_00000158 = in_stack_00000158 / 3;
      }
      if (0 < in_stack_0000015c) {
        in_stack_0000015c = in_stack_0000015c / 3;
      }
      if (0 < in_stack_00000160) {
        in_stack_00000160 = in_stack_00000160 / 3;
      }
      if (0 < in_stack_000001c4) {
        in_stack_000001c4 = in_stack_000001c4 / 3;
      }
      break;
    case 6:
      if (0 < in_stack_000000b8) {
        in_stack_000000b8 = in_stack_000000b8 / 3;
      }
      if (0 < in_stack_000000fc) {
        in_stack_000000fc = in_stack_000000fc / 3;
      }
      if (0 < in_stack_000001e0) {
        in_stack_000001e0 = in_stack_000001e0 / 3;
      }
      if (0 < in_stack_00000168) {
        in_stack_00000168 = in_stack_00000168 / 3;
      }
    }
    in_stack_00000010 = in_stack_00000010 + 1;
    iVar5 = in_stack_00000010;
  } while (in_stack_00000010 < 7);
  piVar3 = &stack0x00000018;
  iVar5 = 0x7d;
  do {
    if (*piVar3 < 0) {
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar10 = 0;
  piVar3 = &stack0x00000018;
  iVar5 = 0x7d;
  do {
    iVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    iVar10 = iVar10 + iVar4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xc41);
  iVar11 = 0;
  iVar4 = 0;
  piVar3 = &stack0x00000018;
  do {
    iVar11 = iVar11 + *piVar3;
    iVar8 = iVar4;
    if (iVar5 % iVar10 < iVar11) break;
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
    iVar8 = 0;
  } while (iVar4 < 0x7d);
  iVar5 = 0x100;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  switch(iVar8) {
  case 0:
  case 1:
  case 2:
  case 0x29:
  case 0x32:
  case 0x33:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x6b:
    DAT_00886c2c = DAT_00886c2c + 1;
    break;
  default:
    DAT_00886c28 = DAT_00886c28 + 1;
    break;
  case 6:
  case 7:
  case 8:
  case 0x2b:
  case 0x36:
  case 0x37:
  case 0x3a:
  case 0x3b:
  case 0x68:
    DAT_00886c1c = DAT_00886c1c + 1;
    break;
  case 0xd:
  case 0xe:
  case 0xf:
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x3b,4);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x3c,10);
    DAT_00886c34 = DAT_00886c34 + 1;
    DAT_00886c48 = DAT_00886c48 + 1;
    goto LAB_00516be6;
  case 0x10:
  case 0x31:
  case 0x6c:
    DAT_00886c20._0_4_ = (int)DAT_00886c20 + 1;
    break;
  case 0x11:
  case 0x12:
  case 0x2e:
  case 0x34:
  case 0x35:
  case 99:
  case 0x66:
  case 0x6d:
    DAT_00886c20._4_4_ = DAT_00886c20._4_4_ + 1;
    break;
  case 0x13:
  case 0x14:
  case 0x15:
    computerPlayerSetup = (int *)((int)computerPlayerSetup + 1);
    break;
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
    break;
  case 0x28:
  case 0x39:
  case 0x54:
  case 0x72:
    DAT_00886c30 = DAT_00886c30 + 1;
    break;
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x53:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 100:
  case 0x65:
  case 0x69:
  case 0x6a:
  case 0x6e:
  case 0x6f:
  case 0x73:
  case 0x74:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
    DAT_00886c48 = DAT_00886c48 + 1;
    goto LAB_00516be6;
  case 0x48:
  case 0x49:
    DAT_00886c44 = DAT_00886c44 + 1;
    DAT_00886c2c = DAT_00886c2c + 1;
    goto LAB_00516be6;
  case 0x4a:
    DAT_00886c44 = DAT_00886c44 + 1;
    DAT_00886c28 = DAT_00886c28 + 1;
    goto LAB_00516be6;
  }
  DAT_00886c44 = DAT_00886c44 + 1;
LAB_00516be6:
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  AIModule::logCommonHistory
            ((AIModule *)(*(byte *)((int)&unaff_EBP->_padding_ + 1) - 1),(char *)unaff_EBP->playerAI
            );
  AIModule::logCommonHistory((AIModule *)unaff_EBP->playerAI,(char *)unaff_EBP->playerAI);
  uVar6 = 0xffffffff;
  pcVar12 = &s_RandomGameSpecialized;
  do {
    pcVar14 = pcVar12;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar14 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar14;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar12 = pcVar14 + -uVar6;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)in_stack_00000300 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    in_stack_00000300 = in_stack_00000300 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *in_stack_00000300 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    in_stack_00000300 = in_stack_00000300 + 1;
  }
  AIModule::logCommonHistory((AIModule *)0x0,(char *)unaff_EBP->playerAI);
  switch(in_stack_00000308) {
  case 0:
  case 1:
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x36,5);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x37,5);
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,1);
    if (iVar10 < 1) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0,0x32);
      iVar10 = 0x32;
    }
    else {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0,0x32);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,1,0x19);
      iVar10 = 0x19;
    }
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,2,iVar10);
    if (1 < in_stack_00000304) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,3,5);
    }
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x2a,2);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x3d,2);
    if (in_stack_00000308 != 2) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x26,in_stack_0000030c + 1);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x24,1);
      if (in_stack_00000308 == 3) {
        iVar10 = 1;
      }
      else {
        iVar10 = 5;
      }
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x36,iVar10);
      if (in_stack_00000308 == 4) {
        iVar10 = 1;
      }
      else {
        iVar10 = 5;
      }
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x37,iVar10);
    }
  }
  uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar2 == '\x01') {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,4,10);
  }
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe3a);
  iVar10 = (iVar10 % 0xc + 0x1c) * 0x3c;
  switch(iVar8) {
  case 0:
  case 3:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0x13:
  case 0x2f:
  case 0x30:
  case 0x33:
  case 0x37:
  case 0x39:
  case 0x48:
  case 0x4a:
  case 0x4b:
  case 0x4e:
  case 0x51:
  case 0x55:
  case 0x58:
  case 0x5a:
  case 0x5e:
  case 0x60:
  case 100:
  case 0x69:
  case 0x6e:
  case 0x73:
    DAT_00886c3c = DAT_00886c3c + 1;
    iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe58);
    iVar10 = (iVar10 % 6 + 0x14) * 0x3c;
    break;
  default:
    DAT_00886c40 = DAT_00886c40 + 1;
    break;
  case 9:
  case 0x38:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe69);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar10 = ((((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 5) * 0x3c;
    DAT_00886c38 = DAT_00886c38 + 1;
    break;
  case 10:
  case 0x29:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x32:
  case 0x3a:
  case 0x71:
    DAT_00886c38 = DAT_00886c38 + 1;
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe64);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar10 = ((((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7) + 0xb) * 0x3c;
  }
  iVar4 = iVar5;
  if ((iVar5 == 0) &&
     (iVar11 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe73), iVar11 % 3 == 0)) {
    iVar10 = iVar10 + -300;
  }
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x68,iVar10);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x10,2);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x1a,10);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x5d,1);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,99,4);
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe80);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xbc,(uint)(iVar10 % 3 != 0));
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe86);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xc3,iVar10 % 0x28 + 10);
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe8a);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xbd,iVar10 % 0x46 + 0x1e);
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe8e);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xc6,(iVar10 % 5 + 5) * iVar5);
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe92);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,199,(iVar10 % 10 + 10) * iVar5);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xa1,4);
  if (in_stack_00000304 == 0) {
    in_stack_0000030c = in_stack_0000030c + -2;
  }
  else if (in_stack_00000304 == 1) {
    in_stack_0000030c = in_stack_0000030c + -1;
  }
  switch(in_stack_0000030c) {
  case 0:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea7);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0xf);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea9);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar10 = iVar10 + 1 + (((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7);
    goto LAB_005172a1;
  case 1:
    iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeac);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x49,iVar10 % 3 + 0x10);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    iVar11 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeae);
    iVar8 = 5;
    iVar9 = iVar11 >> 0x1f;
    break;
  case 2:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb1);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0x11);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    iVar11 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb3);
    iVar8 = 6;
    iVar9 = iVar11 >> 0x1f;
    break;
  case 3:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb6);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0x12);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    iVar11 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb8);
    iVar8 = 7;
    iVar9 = iVar11 >> 0x1f;
    break;
  case 4:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xebb);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7) + 0x12);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xebd);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar10 = iVar10 + 1 + (((uVar6 ^ uVar7) - uVar7 & 7 ^ uVar7) - uVar7);
    goto LAB_005172a1;
  case -2:
  case -1:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea2);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0xe);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea4);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar10 = iVar10 + 1 + (((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7);
    goto LAB_005172a1;
  default:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xec1);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0x12);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    iVar11 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xec3);
    iVar8 = 9;
    iVar9 = iVar11 >> 0x1f;
  }
  iVar10 = iVar10 + 1 + (int)(CONCAT44(iVar9,iVar11) % (longlong)iVar8);
LAB_005172a1:
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x4a,iVar10);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd0,1);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd1,1);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd2,1);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xdf,1);
  if (in_stack_00000304 == 0) {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd4,3);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd5,6);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd6,2);
    iVar10 = 6;
LAB_00517478:
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xe0,iVar10);
  }
  else {
    if (in_stack_00000304 == 1) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd4,2);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd5,5);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd6,2);
      iVar10 = 4;
      goto LAB_00517478;
    }
    if ((((in_stack_00000304 == 2) || (in_stack_00000304 == 6)) || (in_stack_00000304 == 5)) ||
       (in_stack_00000304 == 8)) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd4,1);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd5,4);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd6,1);
      iVar10 = 3;
      goto LAB_00517478;
    }
    if (((in_stack_00000304 == 3) || (in_stack_00000304 == 4)) || (in_stack_00000304 == 7)) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd4,0);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd5,0);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd6,0);
      iVar10 = 0;
      goto LAB_00517478;
    }
  }
  if (allowAIToCheat != 0) {
    iVar5 = 0;
    iVar10 = 0;
    iVar11 = 0;
    iVar8 = 0;
    if (iVar4 == 0) {
      iVar5 = 2000;
      iVar11 = 2000;
      iVar8 = 2000;
      iVar10 = 2000;
    }
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x8a,iVar5);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x8b,iVar11);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x8c,iVar8);
    iVar5 = iVar4;
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x8d,iVar10);
  }
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xa8,0);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xa2,0);
  if (iVar5 < 3) {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xc2,1);
    iVar10 = 2;
  }
  else {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xc2,0);
    iVar10 = 1;
  }
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x2f,iVar10);
  if (iVar5 == 0) {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 200;
  }
  else if (iVar5 == 1) {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 0x96;
  }
  else if (iVar5 == 2) {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 100;
  }
  else {
    if (iVar5 != 3) goto LAB_00517639;
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 0x32;
  }
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xba,iVar5);
LAB_00517639:
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xf50);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xb5,(uint)(iVar5 % 6 < 5));
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xf56);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xb6,(uint)(iVar5 % 3 < 1));
  return extraout_EAX;
}

// --------------------------------------------------

// Function: FUN_005177e7
// Address: 005177e7
// XREFS: None
// [HELPER] s_Setting_up_as_Egyptians_: "Setting up as Egyptians."
ushort * __fastcall FUN_005177e7(char *param_1,int param_2,ushort *param_3)
{
  ushort *puVar1;
  char *pcVar2;
  undefined4 uVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  ushort uVar7;
  char cVar8;
  uchar uVar9;
  int in_EAX;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ushort *puVar13;
  int iVar14;
  ushort *puVar15;
  AIModule *this;
  char cVar16;
  byte bVar17;
  undefined2 uVar18;
  char cVar20;
  char *pcVar19;
  byte bVar21;
  byte bVar22;
  char *unaff_EBX;
  int unaff_ESI;
  bool bVar23;
  bool bVar24;
  undefined4 unaff_retaddr;
  ushort *puStack00000008;
  int in_stack_00000020;
  int in_stack_00000024;
  ushort *in_stack_0000003c;
  ushort *puStack00000040;
  undefined4 *in_stack_00000044;
  int in_stack_00000048;
  undefined4 uStack0000004c;
  char *in_stack_00000050;
  byte *in_stack_00000054;
  ushort *in_stack_00000058;
  int in_stack_0000005c;
  
  cVar20 = (char)((uint)param_2 >> 8);
  *(char *)(unaff_ESI + 0x5e) = *(char *)(unaff_ESI + 0x5e) + cVar20;
  *(char *)(param_2 + -0x61ffaea2) = *(char *)(param_2 + -0x61ffaea2) + (char)param_1;
  *(char *)(param_2 + -0x39ffaea2) = *(char *)(param_2 + -0x39ffaea2) + cVar20;
  cVar16 = (char)param_2 + (char)unaff_EBX;
  cVar8 = (char)((uint)param_1 >> 8);
  cVar20 = cVar20 + cVar8;
  pcVar19 = (char *)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(cVar20,cVar16));
  *pcVar19 = *pcVar19 + (char)in_EAX;
  *unaff_EBX = *unaff_EBX + cVar16;
  param_1[(int)unaff_EBX * 2] = param_1[(int)unaff_EBX * 2] + (char)((uint)in_EAX >> 8);
  cRam4600515f = cRam4600515f + cVar20;
  param_1[0x5f] = param_1[0x5f] + cVar16;
  *(char *)(in_EAX + 0x5f) = *(char *)(in_EAX + 0x5f) + cVar8;
  param_1[0x5f] = param_1[0x5f] + (char)((uint)unaff_EBX >> 8);
  *pcVar19 = *pcVar19 + (char)unaff_EBX;
  puStack00000008 = param_3;
  *param_1 = *param_1 + (char)((uint)unaff_retaddr >> 8);
  *(char *)(in_stack_00000020 + 0x51) =
       *(char *)(in_stack_00000020 + 0x51) + (char)in_stack_00000020;
  *(char *)(in_stack_00000024 + -0x36ffae9f) =
       *(char *)(in_stack_00000024 + -0x36ffae9f) + (char)in_stack_00000024;
  puStack00000040 = in_stack_0000003c;
  *in_stack_00000050 = *in_stack_00000050 + (char)((uint)in_stack_0000005c >> 8);
  uVar7 = *in_stack_00000058;
  bVar22 = (byte)((uint)in_stack_00000050 >> 8);
  *(byte *)in_stack_00000058 = (byte)*in_stack_00000058 + bVar22;
  *in_stack_00000058 =
       *in_stack_00000058 +
       (ushort)CARRY1((byte)uVar7,bVar22) *
       (((ushort)in_stack_0000005c & 3) - (*in_stack_00000058 & 3));
  *(byte *)(in_stack_00000044 + -0xeffeba7) = *(char *)(in_stack_00000044 + -0xeffeba7) + bVar22;
  cVar8 = (char)((uint)in_stack_00000058 >> 8);
  *in_stack_00000054 = *in_stack_00000054 + cVar8;
  uStack0000004c = 0x69db0051;
  *(char *)(in_stack_0000005c + -0x45ffae95) = *(char *)(in_stack_0000005c + -0x45ffae95) + bVar22;
  pcVar19 = (char *)(*(int *)in_stack_00000058 * -0x69);
  uVar18 = SUB42(pcVar19,0);
  bVar17 = in(uVar18);
  *(byte *)((int)in_stack_0000003c + -1) = bVar17;
  puVar13 = in_stack_0000003c + -0x21ffd74a;
  uVar7 = *puVar13;
  bVar17 = (byte)pcVar19;
  *(byte *)puVar13 = (byte)*puVar13 + bVar17;
  bVar21 = (byte)in_stack_00000050;
  if (CARRY1((byte)uVar7,bVar17) || (byte)*puVar13 == 0) {
    in_stack_00000058 =
         (ushort *)
         CONCAT22((short)((uint)in_stack_00000058 >> 0x10),
                  CONCAT11(cVar8 - *(char *)(in_stack_00000048 + 0x51),(char)in_stack_00000058));
  }
  else {
    pcVar2 = (char *)((int)in_stack_00000044 * 3 + 0x76bc0051);
    *pcVar2 = *pcVar2 + bVar22;
    puStack00000040 = in_stack_00000058;
    pcVar2 = (char *)((int)in_stack_00000044 * 3 + 0x6d2a0051);
    *pcVar2 = *pcVar2 + bVar22;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)in_stack_0000003c = uVar3;
    *(char *)((int)in_stack_00000044 + 0x5d00516d) =
         *(char *)((int)in_stack_00000044 + 0x5d00516d) + bVar17;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 2) = uVar3;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 4) = uVar3;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 6) = uVar3;
    *(char *)(in_stack_00000048 + 0x6d) = *(char *)(in_stack_00000048 + 0x6d) + bVar21;
    *(char *)(in_stack_00000048 + 0x6d) = *(char *)(in_stack_00000048 + 0x6d) + bVar21;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 8) = uVar3;
    *(char *)(in_stack_00000048 + 0x6d) = *(char *)(in_stack_00000048 + 0x6d) + bVar21;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 10) = uVar3;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 0xc) = uVar3;
    *(char *)((int)in_stack_00000044 + 0x2a00516d) =
         *(char *)((int)in_stack_00000044 + 0x2a00516d) + bVar17;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 0xe) = uVar3;
    *(char *)(in_stack_00000048 + 0x6d) = *(char *)(in_stack_00000048 + 0x6d) + bVar21;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 0x10) = uVar3;
    puStack00000008 = in_stack_00000058;
    *pcVar19 = *pcVar19 + cVar8;
    puVar13 = in_stack_0000003c + 0x14;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 0x12) = uVar3;
    *pcVar19 = *pcVar19 + cVar8;
    in_stack_0000003c = in_stack_0000003c + 0x16;
    uVar3 = in(uVar18);
    *(undefined4 *)puVar13 = uVar3;
  }
  cVar8 = (char)((uint)in_stack_00000058 >> 8);
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)in_stack_0000003c = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 2) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 4) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 6) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 8) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 10) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 0xc) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 0xe) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 0x10) = uVar3;
  *(char *)(in_stack_00000048 + 0x6d) = *(char *)(in_stack_00000048 + 0x6d) + bVar21;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 0x12) = uVar3;
  cVar16 = (char)in_stack_00000058;
  puVar15 = (ushort *)
            CONCAT22((short)((uint)in_stack_00000058 >> 0x10),CONCAT11(cVar8 + cVar16,cVar16));
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 0x14) = uVar3;
  bVar22 = *in_stack_00000054;
  *in_stack_00000054 = *in_stack_00000054 + (byte)in_stack_00000054;
  pbVar4 = (byte *)(uint)CARRY1(bVar22,(byte)in_stack_00000054);
  pbVar5 = in_stack_00000054 + -0x1d1d011d;
  cVar8 = (char)(pbVar5 + ((-0x3021d1d - (int)pbVar4) -
                          (uint)(in_stack_00000054 < (byte *)0x1d1d011d || pbVar5 < pbVar4)));
  uVar11 = CONCAT31((int3)((uint)(pbVar5 + ((-0x3021d1d - (int)pbVar4) -
                                           (uint)(in_stack_00000054 < (byte *)0x1d1d011d ||
                                                 pbVar5 < pbVar4))) >> 8),cVar8 + '!');
  uVar12 = (uint)(0xe2 < (byte)(cVar8 + 4U));
  uVar6 = uVar11 + 0xfae2e2e3;
  uVar10 = uVar6 - uVar12;
  uVar12 = (uint)(uVar11 < 0x51d1d1d || uVar6 < uVar12);
  uVar6 = uVar10 + 0xe2e2e2e3;
  uVar11 = uVar6 - uVar12;
  uVar12 = (uint)(uVar10 < 0x1d1d1d1d || uVar6 < uVar12);
  uVar6 = uVar11 + 0xe2e2e2e3;
  uVar10 = uVar6 - uVar12;
  uVar12 = (uint)(uVar11 < 0x1d1d1d1d || uVar6 < uVar12);
  uVar6 = uVar10 + 0xe2e2e2e3;
  uVar11 = uVar6 - uVar12;
  uVar12 = (uint)(uVar10 < 0x1d1d1d1d || uVar6 < uVar12);
  uVar6 = uVar11 + 0xe2e2e2e3;
  uVar10 = uVar6 - uVar12;
  uVar12 = (uint)(uVar11 < 0x1d1d1d1d || uVar6 < uVar12);
  uVar6 = uVar10 + 0xf8f8e2fa;
  bVar21 = bVar21 | bRam0c0b1d1d;
  uVar12 = ((uVar6 - uVar12) + -0x91d0808) - (uint)(uVar10 < 0x7071d06 || uVar6 < uVar12) |
           0x1d1d1d0e;
  bVar23 = uVar12 + 0xe2e2e2e3 < 0x1d1d1d1d || uVar12 + 0xc5c5c5c6 < (uint)(uVar12 < 0x1d1d1d1d);
  uVar11 = (uVar12 + 0xc5c5c5c6) - (uint)(uVar12 < 0x1d1d1d1d);
  bVar24 = CARRY1(bRam1d1d111d,bVar21) || CARRY1(bRam1d1d111d + bVar21,bVar23);
  bRam1d1d111d = bRam1d1d111d + bVar21 + bVar23;
  cVar20 = bVar21 + bRam1d131d1d + bVar24;
  uVar12 = (uint)(CARRY1(bVar21,bRam1d131d1d) || CARRY1(bVar21 + bRam1d131d1d,bVar24));
  uVar6 = uVar11 + 0xe2eae2ec;
  uVar10 = uVar6 - uVar12;
  uVar12 = (uint)(uVar11 < 0x1d151d14 || uVar6 < uVar12);
  uVar6 = uVar10 + 0xe8e2e9e3;
  uVar11 = uVar6 - uVar12;
  uVar12 = (uint)(uVar10 < 0x171d161d || uVar6 < uVar12);
  uVar6 = uVar11 + 0xe2e7e2e3;
  uVar10 = uVar6 - uVar12;
  uVar12 = (uint)(uVar11 < 0x1d181d1d || uVar6 < uVar12);
  uVar6 = uVar10 + 0xe2e6e2e3;
  uVar11 = uVar6 - uVar12;
  uVar12 = (uint)(uVar10 < 0x1d191d1d || uVar6 < uVar12);
  uVar6 = uVar11 + 0xe2e5e2e3;
  puVar13 = (ushort *)
            (((uVar6 - uVar12) + 0x4ae3e2e5) - (uint)(uVar11 < 0x1d1a1d1d || uVar6 < uVar12));
  out(*in_stack_00000044,uVar18);
  pcVar2 = (char *)(in_stack_00000048 + 0x2600516f);
  cVar8 = *pcVar2;
  bVar21 = (byte)((uint)pcVar19 >> 8);
  *pcVar2 = *pcVar2 + bVar21;
  if (SCARRY1(cVar8,bVar21)) {
    puVar13 = (ushort *)((uint)puVar13 ^ 0x7406f883);
    pbVar4 = (byte *)(CONCAT31((int3)((uint)in_stack_00000050 >> 8),cVar20) + 0x137405f8);
    *pbVar4 = *pbVar4 ^ (byte)puVar13;
  }
  else {
    puVar1 = puVar13 + -0x27fd748;
    uVar7 = *puVar1;
    *(byte *)puVar1 = (byte)*puVar1 + cVar20;
    if (SCARRY1((byte)uVar7,cVar20)) {
      pbVar4 = (byte *)((int)in_stack_00000044 + -0x71 + (int)puVar15);
      *pbVar4 = *pbVar4 | bVar21;
      puVar13 = (ushort *)((uint)(puVar13 + -0x3be7646) & 0xffffff04);
      goto code_r0x00517bd4;
    }
    pcVar19[0x71] = pcVar19[0x71] + (char)((uint)puVar13 >> 8);
    this = (AIModule *)CONCAT31((int3)((uint)puVar15 >> 8),cVar16 * '\x02');
    if (!SCARRY1(cVar16,cVar16)) goto code_r0x00517bd4;
    *(byte *)(puVar13 + -0x37b7b7b8) = (byte)puVar13[-0x37b7b7b8] + bVar17;
    AIModule::logCommonHistory
              (this,*(char **)(this[2].playerNameValue + 8),s_Setting_up_as_Egyptians_,puVar15,
               puVar15,in_stack_00000058,in_stack_00000058,in_stack_00000058,in_stack_00000058,
               in_stack_00000058,in_stack_00000058,in_stack_00000058,in_stack_00000058,
               in_stack_00000058,in_stack_00000058,in_stack_00000058);
    puVar13 = in_stack_00000058;
    uVar9 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
    if (uVar9 != '\x01') {
      iVar14 = RGE_Base_Game::difficulty(rge_base_game);
      if (iVar14 < 1) {
        puVar15[0x46] = 100;
        puVar15[0x47] = 0;
        return puVar15;
      }
      puVar15[6] = 10;
      puVar15[7] = 0;
      puVar15[0x12] = 10;
      puVar15[0x13] = 0;
      puVar15[0x14] = 10;
      puVar15[0x15] = 0;
      puVar15[0x22] = 0x28;
      puVar15[0x23] = 0;
      puVar15[0x24] = 0x28;
      puVar15[0x25] = 0;
      puVar15[0x5c] = 100;
      puVar15[0x5d] = 0;
      puVar15[0x26] = 0x32;
      puVar15[0x27] = 0;
      puVar15[0x28] = 0x32;
      puVar15[0x29] = 0;
      puVar15[0x5e] = 100;
      puVar15[0x5f] = 0;
      puVar15[0xa0] = 100;
      puVar15[0xa1] = 0;
      puVar15[0xa2] = 0x1e;
      puVar15[0xa3] = 0;
      puVar15[0xa4] = 0x14;
      puVar15[0xa5] = 0;
      if ((puVar13 == (ushort *)0x0) || (puVar13 == (ushort *)0x1)) {
        puVar15[0xa6] = 200;
        puVar15[0xa7] = 0;
      }
      else if ((((puVar13 == (ushort *)0x2) || (puVar13 == (ushort *)0x6)) ||
               (puVar13 == (ushort *)0x8)) || (puVar13 == (ushort *)0x5)) {
        puVar15[0xa6] = 100;
        puVar15[0xa7] = 0;
        return puVar15;
      }
      return puVar15;
    }
    if ((puVar13 == (ushort *)0x0) || (puVar13 == (ushort *)0x1)) {
      puVar15[0x7e] = 100;
      puVar15[0x7f] = 0;
      return puVar13;
    }
    if ((puVar13 == (ushort *)0x2) || (puVar13 == (ushort *)0x6)) {
      puVar15[0x32] = 0x3c;
      puVar15[0x33] = 0;
      puVar15[0x7e] = 0x28;
      puVar15[0x7f] = 0;
      return puVar15;
    }
    in_stack_00000058 = puVar13;
    if (puVar13 == (ushort *)0x5) goto LAB_00517be2;
  }
  if (puVar13 == (ushort *)0x8) {
LAB_00517be2:
    puVar13 = (ushort *)CONCAT31((int3)in_stack_00000058,(char)((uint)puVar15 >> 0x18));
    puVar13[0x32] = 0x50;
    puVar13[0x33] = 0;
    puVar13[0x7e] = 0x14;
    puVar13[0x7f] = 0;
    return puVar13;
  }
code_r0x00517bd4:
  *(undefined4 *)(CONCAT31((int3)in_stack_00000058,(char)((uint)puVar15 >> 0x18)) + 100) = 100;
  return puVar13;
}

// --------------------------------------------------

// Function: FUN_00519465
// Address: 00519465
// XREFS: None
void __fastcall FUN_00519465(undefined4 param_1,int param_2)
{
  int in_EAX;
  char cVar1;
  char cVar3;
  int unaff_EBX;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  undefined4 uVar2;
  
  uStack_4 = param_1;
  *(char *)(in_EAX + -0x6d) = *(char *)(in_EAX + -0x6d) + (char)((uint)param_2 >> 8);
  uStack_8 = param_1;
  *(char *)(unaff_EBX + -0x49ffae6d) = *(char *)(unaff_EBX + -0x49ffae6d) + (char)param_2;
  uStack_c = param_1;
  cVar3 = (char)in_EAX;
  cVar1 = (char)param_1 + cVar3;
  uVar2 = CONCAT31((int3)((uint)param_1 >> 8),cVar1);
  uStack_10 = uVar2;
  *(char *)(&uStack_10 + param_2) = *(char *)(&uStack_10 + param_2) + cVar3;
  uStack_14 = uVar2;
  *(char *)(&uStack_14 + param_2) = *(char *)(&uStack_14 + param_2) + cVar1;
  *(char *)(param_2 + -0x6c) = *(char *)(param_2 + -0x6c) + cVar3;
  *(char *)(in_EAX + 0x6a909090) = *(char *)(in_EAX + 0x6a909090) + (char)param_2;
  (**(code **)(in_EAX + -0x65))(uVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_00519ab2
// Address: 00519ab2
// XREFS: None
TRIBE_Player * __fastcall FUN_00519ab2(TRIBE_Player *param_1,undefined4 param_2)
{
  char *pcVar1;
  char cVar3;
  undefined4 in_EAX;
  int iVar2;
  char cVar4;
  char cVar6;
  int unaff_EBX;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_54;
  code *pcStack_50;
  TRIBE_Player *pTStack_4c;
  TRIBE_Player *pTStack_48;
  TRIBE_Player *pTStack_44;
  TRIBE_Player *pTStack_40;
  TRIBE_Player *pTStack_3c;
  TRIBE_Player *pTStack_38;
  TRIBE_Player *pTStack_34;
  TRIBE_Player *pTStack_30;
  TRIBE_Player *pTStack_2c;
  TRIBE_Player *pTStack_28;
  TRIBE_Player *pTStack_24;
  
  iVar2 = (int)(short)in_EAX;
  cVar4 = (char)((uint)param_1 >> 8);
  *(char *)(iVar2 + -0x68) = *(char *)(iVar2 + -0x68) + cVar4;
  *(char *)(iVar2 + -0x68) = *(char *)(iVar2 + -0x68) + (char)((uint)param_2 >> 8);
  cVar6 = (char)((uint)unaff_EBX >> 8);
  *(char *)(iVar2 + -0x68) = *(char *)(iVar2 + -0x68) + cVar6;
  *(char *)(iVar2 + 0x34005198) = *(char *)(iVar2 + 0x34005198) + (char)in_EAX;
  cVar3 = (char)((uint)in_EAX >> 8);
  *(char *)(unaff_EBX + 0x58005198) = *(char *)(unaff_EBX + 0x58005198) + cVar3;
  *(char *)(unaff_EBX + -0x67) = *(char *)(unaff_EBX + -0x67) + cVar3;
  param_1[-0x477c1].aiStatusInformationValue6[0xa5] =
       param_1[-0x477c1].aiStatusInformationValue6[0xa5] + (char)in_EAX;
  iVar5 = CONCAT31((int3)((uint)unaff_EBX >> 8),(char)unaff_EBX + (uchar)param_1);
  pcVar1 = (char *)((iVar2 >> 0x1f) + iVar5 * 4);
  *pcVar1 = *pcVar1 + cVar6;
  pcVar1 = (char *)(iVar5 + -0x34ffae68);
  *pcVar1 = *pcVar1 + cVar3;
  pcVar1 = (char *)((iVar2 >> 0x1f) + -1);
  *pcVar1 = *pcVar1 + cVar4;
  pcStack_50 = FUN_005612d8;
  uStack_54 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_54;
  pTStack_4c = param_1;
  pTStack_48 = param_1;
  pTStack_44 = param_1;
  pTStack_40 = param_1;
  pTStack_3c = param_1;
  pTStack_38 = param_1;
  pTStack_34 = param_1;
  pTStack_30 = param_1;
  pTStack_2c = param_1;
  pTStack_28 = param_1;
  pTStack_24 = param_1;
  TRIBE_Player::TRIBE_Player(param_1,(int)param_1,(TRIBE_World *)param_1,(uchar)param_1);
  pTStack_4c = (TRIBE_Player *)0x0;
  param_1->_padding_ = (int)&TRIBE_Gaia::_vftable_;
  *(undefined1 *)&param_1->_padding_ = 2;
  rge_read((int)param_1,param_1 + 1,4);
  rge_read((int)param_1,&param_1[1]._padding_,4);
  rge_read((int)param_1,&param_1[1]._padding_,4);
  rge_read((int)param_1,&param_1[1]._padding_,4);
  *unaff_FS_OFFSET = uStack_54;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051becb
// Address: 0051becb
// XREFS: None
void FUN_0051becb(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0051c1f6
// Address: 0051c1f6
// XREFS: None
// [HELPER] s__d: "%d"
// [HELPER] s__d__: "%d%%"
// [HELPER] s__d__d: "%d+%d"
// [HELPER] s_tpnl_obj__draw_item: "tpnl_obj::draw_item"
void FUN_0051c1f6(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)
{
  char cVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  byte *in_EAX;
  uchar *puVar5;
  void *pvVar6;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  undefined1 in_CF;
  char acStack_14 [20];
  
  uVar4 = CONCAT11(in_CF,*in_EAX) << 6 | CONCAT11(in_CF,*in_EAX) >> 3;
  *in_EAX = (byte)uVar4;
  bVar2 = *in_EAX;
  *in_EAX = bVar2 << 4 | (byte)(CONCAT11((uVar4 & 0x100) != 0,bVar2) >> 5);
  bVar3 = *in_EAX;
  *in_EAX = bVar3 << 6 | (byte)(CONCAT11((bVar2 & 0x10) != 0,bVar3) >> 3);
  bVar2 = *in_EAX;
  *in_EAX = bVar2 << 4 | (byte)(CONCAT11((bVar3 & 4) != 0,bVar2) >> 5);
  bVar3 = *in_EAX;
  *in_EAX = bVar3 << 2 | (byte)(CONCAT11((bVar2 & 0x10) != 0,bVar3) >> 7);
  *in_EAX = *in_EAX;
  bVar2 = *in_EAX;
  *in_EAX = bVar2 << 2 | (byte)(CONCAT11((bVar3 & 0x40) != 0,bVar2) >> 7);
  *in_EAX = *in_EAX << 7 | (byte)(CONCAT11((bVar2 & 0x40) != 0,*in_EAX) >> 2);
  if (((*(int *)(in_EAX + 0x104) != 0) && (param_2 != -1)) &&
     (puVar5 = TDrawArea::Lock(*(TDrawArea **)(in_EAX + 0x20),s_tpnl_obj__draw_item,1),
     puVar5 != (uchar *)0x0)) {
    TShape::shape_draw(*(TShape **)(in_EAX + 0x104),*(TDrawArea **)(in_EAX + 0x20),
                       *(int *)(in_EAX + 0xc) + 0x36,*(int *)(in_EAX + 0x10) + 0x1e + param_1 * 0x14
                       ,param_2,'\0',(uchar *)0x0);
    TDrawArea::Unlock(*(TDrawArea **)(in_EAX + 0x20),s_tpnl_obj__draw_item);
  }
  switch(param_3) {
  case 0:
    sprintf(acStack_14,&s__d,param_4);
    break;
  case 1:
    if (param_4 < param_5) {
      sprintf(acStack_14,s__d__d,param_4,param_5 - param_4);
    }
    else {
      sprintf(acStack_14,&s__d,param_4);
    }
    break;
  case 2:
    sprintf(acStack_14,s__d__d,param_4,param_5);
    break;
  case 3:
    sprintf(acStack_14,s__d__,param_4);
    break;
  default:
    acStack_14[0] = '\0';
  }
  if ((acStack_14[0] != '\0') &&
     (pvVar6 = TDrawArea::GetDc(*(TDrawArea **)(in_EAX + 0x20),s_tpnl_obj__draw_item),
     pvVar6 != (void *)0x0)) {
    SetBkMode(*(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x38),1);
    SetTextColor(*(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x38),0xffffff);
    uVar7 = SelectObject(*(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x38),
                         *(undefined4 *)(in_EAX + 0xf4));
    uVar8 = 0xffffffff;
    pcVar9 = acStack_14;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    TextOutA(*(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x38),*(int *)(in_EAX + 0xc) + 0x58,
             *(int *)(in_EAX + 0x10) + 0x21 + param_1 * 0x14,acStack_14,~uVar8 - 1);
    SelectObject(*(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x38),uVar7);
    TDrawArea::ReleaseDc(*(TDrawArea **)(in_EAX + 0x20),s_tpnl_obj__draw_item);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0051c3da
// Address: 0051c3da
// XREFS: None
void FUN_0051c3da(void)
{
  func_0xb30051c2();
  return;
}

// --------------------------------------------------

// Function: FUN_0051dc3f
// Address: 0051dc3f
// XREFS: None
int __fastcall FUN_0051dc3f(int *param_1,undefined4 param_2)
{
  char *pcVar1;
  int iVar2;
  int in_EAX;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  bool in_PF;
  float10 in_ST0;
  
  if (in_PF) {
    (**(code **)(unaff_EDI + 0x14))(1);
    (**(code **)(unaff_EDI + 0x20))(1);
    (**(code **)(**(int **)(unaff_ESI + 0x40) + 0x20))(1);
    iVar2 = (**(code **)(unaff_EDI + 0x4c))();
    return iVar2;
  }
  *(char *)(in_EAX + -0x63ffae25) = *(char *)(in_EAX + -0x63ffae25) + (char)param_2;
  *param_1 = (int)ROUND(in_ST0);
  pcVar1 = (char *)(unaff_EBX * 9 + -0x243fffaf);
  *pcVar1 = *pcVar1 + (char)((uint)param_2 >> 8);
  *param_1 = (int)ROUND(in_ST0);
  *(char *)(unaff_EBX + 0x10081) = *(char *)(unaff_EBX + 0x10081) + (char)param_1;
  if (param_1[0x46] != 0) {
    return (int)*(short *)(param_1[0x46] + 0x4a);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051e293
// Address: 0051e293
// XREFS: None
// [HELPER] s__02ld__02ld__02ld___3_1f_: "%02ld:%02ld:%02ld (%3.1f)"
// [HELPER] s_tpnl_tim__render_to_image_buffer: "tpnl_tim::render_to_image_buffer"
int * __fastcall FUN_0051e293(int param_1,undefined1 *param_2)
{
  TPanel *pTVar1;
  char cVar2;
  int *in_EAX;
  void *pvVar4;
  undefined4 uVar5;
  char *pcVar6;
  PanelNode *pPVar7;
  int iVar8;
  TPanel *pTVar9;
  char *unaff_EBX;
  int iVar10;
  TPanel *unaff_ESI;
  tagRECT *unaff_EDI;
  int iVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  int iStack_4;
  int *piVar3;
  
  pcVar6 = (char *)((int)&unaff_EDI[-2].left + 1);
  *pcVar6 = *pcVar6 + (char)((uint)param_1 >> 8);
  pcVar6 = (char *)((int)in_EAX + -0x43ffae1f);
  *pcVar6 = *pcVar6 + (char)((uint)in_EAX >> 8);
  if (param_1 != 1 && *pcVar6 == '\0') {
    return in_EAX;
  }
  cVar2 = (char)in_EAX + (char)unaff_EBX;
  piVar3 = (int *)CONCAT31((int3)((uint)in_EAX >> 8),cVar2);
  if (param_1 != 2 && cVar2 == '\0') {
    return piVar3;
  }
  *unaff_EBX = *unaff_EBX + cVar2;
  iStack_4 = param_1;
  if (param_1 == 3) {
    *param_2 = *param_2;
    cRam000114ec = cRam000114ec + cVar2;
    unaff_EBX[0x55] = unaff_EBX[0x55] + (char)param_2;
    if (pTRam00000134 == (TDrawArea *)0x0) {
      return (int *)0x0;
    }
    unaff_EDI = (tagRECT *)0x138;
    TDrawArea::PtrClear(pTRam00000134,(tagRECT *)0x138,1);
    pvVar4 = TDrawArea::GetDc(pTRam00000134,s_tpnl_tim__render_to_image_buffer);
    unaff_ESI = (TPanel *)0x0;
    if (pvVar4 == (void *)0x0) {
      return (int *)0x0;
    }
  }
  else {
    *piVar3 = *piVar3 + (int)piVar3;
  }
  TDrawArea::SetClipRect((TDrawArea *)unaff_ESI[1].parent_panel,unaff_EDI);
  SelectClipRgn((unaff_ESI[1].parent_panel)->need_redraw,unaff_ESI[1].curr_child);
  uVar5 = SelectObject((unaff_ESI[1].parent_panel)->need_redraw,unaff_ESI[1]._padding_);
  SetBkMode((unaff_ESI[1].parent_panel)->need_redraw,1);
  if (unaff_ESI[1].pnl_wid == 1) {
    iVar11 = unaff_ESI[1].clip_rect.right;
    iVar8 = 0;
    iVar10 = 0;
    if (0x3b < iVar11) {
      iVar8 = iVar11 / 0x3c;
      iVar11 = iVar11 % 0x3c;
      if (0x3b < iVar8) {
        iVar10 = iVar8 / 0x3c;
        iVar8 = iVar8 % 0x3c;
      }
    }
    sprintf(&stack0x00000010,s__02ld__02ld__02ld___3_1f_,iVar10,iVar8,iVar11,
            (double)rge_base_game->world->game_speed);
    uVar12 = 0x20;
    goto LAB_0051e459;
  }
  iVar11 = unaff_ESI[1].pnl_x;
  iVar8 = ((unaff_ESI[1].clip_rect.right + 4U) / 5) * 5;
  if (iVar11 == 4) {
    iVar11 = 0x2c25;
LAB_0051e43f:
    pcVar6 = TPanel::get_string(unaff_ESI,iVar11);
    uVar13 = CONCAT44(iVar8,pcVar6);
  }
  else if (iVar11 == 5) {
    pcVar6 = TPanel::get_string(unaff_ESI,0x2c26);
    uVar13 = CONCAT44(iVar8,pcVar6);
  }
  else {
    if (iVar11 != 6) {
      iVar11 = 0x2c24;
      goto LAB_0051e43f;
    }
    pcVar6 = TPanel::get_string(unaff_ESI,0x2c27);
    uVar13 = CONCAT44(iVar8,pcVar6);
  }
  sprintf(&stack0x00000010,uVar13);
  uVar12 = 0x22;
LAB_0051e459:
  SetTextColor((unaff_ESI[1].parent_panel)->need_redraw,unaff_ESI[1].previousModalPanelValue);
  iVar11 = unaff_ESI->pnl_wid;
  iVar8 = unaff_ESI->pnl_hgt;
  SetRect(&iStack_4,0,0,iVar11 + -3,iVar8 + -3);
  DrawTextA((unaff_ESI[1].parent_panel)->need_redraw,&stack0x00000010,0xffffffff,&iStack_4,uVar12);
  SetRect(&iStack_4,0,2,iVar11 + -3,iVar8 + -1);
  DrawTextA((unaff_ESI[1].parent_panel)->need_redraw,&stack0x00000010,0xffffffff,&iStack_4,uVar12);
  SetRect(&iStack_4,2,0,iVar11 + -1,iVar8 + -3);
  DrawTextA((unaff_ESI[1].parent_panel)->need_redraw,&stack0x00000010,0xffffffff,&iStack_4,uVar12);
  SetRect(&iStack_4,2,2,iVar11 + -1,iVar8 + -1);
  DrawTextA((unaff_ESI[1].parent_panel)->need_redraw,&stack0x00000010,0xffffffff,&iStack_4,uVar12);
  SetTextColor((unaff_ESI[1].parent_panel)->need_redraw,unaff_ESI[1].previousPanelValue);
  SetRect(&iStack_4,1,1,iVar11 + -2,iVar8 + -2);
  DrawTextA((unaff_ESI[1].parent_panel)->need_redraw,&stack0x00000010,0xffffffff,&iStack_4,uVar12);
  SelectObject((unaff_ESI[1].parent_panel)->need_redraw,uVar5);
  SelectClipRgn((unaff_ESI[1].parent_panel)->need_redraw,0);
  TDrawArea::ReleaseDc((TDrawArea *)unaff_ESI[1].parent_panel,s_tpnl_tim__render_to_image_buffer);
  iVar11 = unaff_ESI->pnl_wid;
  pTVar1 = (TPanel *)(unaff_ESI->render_rect).left;
  iVar8 = unaff_ESI->pnl_hgt;
  unaff_ESI[1].node = (PanelNode *)0x0;
  unaff_ESI[1].first_child_node = (PanelNode *)0x0;
  iVar10 = (unaff_ESI->render_rect).top;
  pPVar7 = (PanelNode *)(iVar11 + -1);
  unaff_ESI[1].tab_next_panel = pTVar1;
  pTVar9 = (TPanel *)(iVar8 + -1);
  unaff_ESI[1].mouse_captured = iVar10;
  unaff_ESI[1].last_child_node = pPVar7;
  unaff_ESI[1].tab_prev_panel = pTVar9;
  unaff_ESI[1].active = (int)pTVar1 + (int)pPVar7;
  unaff_ESI[1].visible = (int)&pTVar9->_padding_ + iVar10;
  unaff_ESI[1].need_redraw = unaff_ESI[1].position_mode;
  unaff_ESI[1].pnl_y = unaff_ESI[1].pnl_x;
  unaff_ESI[1].pnl_hgt = unaff_ESI[1].pnl_wid;
  unaff_ESI[1].tab_stop = 1;
  return (int *)0x1;
}

// --------------------------------------------------

// Function: FUN_0051f2e5
// Address: 0051f2e5
// XREFS: None
void FUN_0051f2e5(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}

// --------------------------------------------------

// Function: FUN_00520032
// Address: 00520032
// XREFS: None
void __fastcall FUN_00520032(char *param_1,undefined4 param_2)
{
  byte bVar1;
  short sVar2;
  char cVar3;
  char cVar5;
  undefined4 in_EAX;
  undefined4 extraout_ECX;
  char *pcVar6;
  char unaff_BL;
  char unaff_BH;
  byte *pbVar4;
  
  sVar2 = (short)(char)((uint)param_1 >> 8);
  cVar3 = (char)((short)in_EAX / sVar2);
  cVar5 = (char)((short)in_EAX % sVar2);
  pbVar4 = (byte *)CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(cVar5,cVar3));
  pcVar6 = (char *)CONCAT22((short)((uint)param_2 >> 0x10),
                            CONCAT11((char)((uint)param_2 >> 8) + unaff_BH,(char)param_2 + unaff_BH)
                           );
  *pbVar4 = *pbVar4 + cVar5;
  *param_1 = *param_1 + '\x01';
  bVar1 = *pbVar4;
  *pbVar4 = *pbVar4 + (byte)param_1;
  *param_1 = *param_1 + '\x01';
  *param_1 = *param_1 + '\x01';
  cRama10051fe = cVar3 + -2 + CARRY1(bVar1,(byte)param_1);
  *pcVar6 = *pcVar6 + unaff_BL;
  *param_1 = *param_1 + '\x01';
  (**(code **)param_1)(param_1);
  pcVar6 = (char *)CONCAT22((short)((uint)extraout_ECX >> 0x10),
                            CONCAT11((char)((uint)extraout_ECX >> 8) + (char)extraout_ECX,
                                     (char)extraout_ECX));
  *pcVar6 = *pcVar6 + '\x01';
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_00520abd
// Address: 00520abd
// XREFS: None
// [HELPER] s__1ld__02ld: "%1ld:%02ld"
// [HELPER] s__ld: "%ld"
// [HELPER] s__ld__1d: "%ld/%1d"
// [HELPER] s__s: "%s"
void __fastcall FUN_00520abd(int param_1,undefined4 param_2)
{
  uchar uVar1;
  int iVar2;
  Special_Events *pSVar3;
  uchar uVar4;
  int in_EAX;
  int iVar5;
  char cVar8;
  uint uVar6;
  int iVar7;
  byte *pbVar9;
  Time_Line_Panel *unaff_EBX;
  int unaff_EBP;
  char *pcVar10;
  char in_ZF;
  float10 in_ST0;
  Special_Events *in_stack_00000040;
  undefined4 in_stack_00000044;
  undefined4 in_stack_00000048;
  short sVar11;
  
  param_1 = param_1 + -1;
  cVar8 = (char)((uint)param_1 >> 8);
  if (param_1 == 0 || in_ZF == '\0') {
    in_EAX = CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX + cVar8);
    unaff_EBX = (Time_Line_Panel *)
                CONCAT22((short)((uint)unaff_EBX >> 0x10),
                         CONCAT11((char)((uint)unaff_EBX >> 8) + cVar8,(char)unaff_EBX));
  }
  pbVar9 = (byte *)CONCAT22((short)((uint)param_2 >> 0x10),
                            CONCAT11((char)((uint)param_2 >> 8) * '\x02',(byte)param_2));
  pcVar10 = (char *)(in_EAX + CONCAT22((short)((uint)param_1 >> 0x10),
                                       CONCAT11(cVar8 + (char)((uint)unaff_EBX >> 8),(char)param_1))
                    );
  *pcVar10 = *pcVar10 + (char)in_EAX;
  *(char *)&unaff_EBX->_padding_ = (char)unaff_EBX->_padding_ + (char)param_1;
  *pbVar9 = *pbVar9 | (byte)param_2;
  *(char *)&unaff_EBX[-0x168f3c]._padding_ = (char)unaff_EBX[-0x168f3c]._padding_ + (char)in_EAX;
  *(float *)(unaff_EBP + 0x56) = (float)in_ST0;
  GetNearestPaletteIndex(*(undefined4 *)(*(int *)unaff_EBX->_padding_ + 8),0xffffff);
  uVar4 = GetNearestPaletteIndex(*(undefined4 *)(*(int *)unaff_EBX->_padding_ + 8),0);
  pSVar3 = in_stack_00000040;
  switch(in_stack_00000040->event) {
  case '\0':
    iVar5 = TPanel::get_string((TPanel *)unaff_EBX,0x106a,&stack0x00000008,0x32);
    if (iVar5 == 0) goto switchD_00520b22_caseD_4;
    goto LAB_00520b72;
  case '\x01':
    iVar5 = TPanel::get_string((TPanel *)unaff_EBX,0x106b,&stack0x00000008,0x32);
    break;
  case '\x02':
    iVar5 = TPanel::get_string((TPanel *)unaff_EBX,0x106c,&stack0x00000008,0x32);
    break;
  case '\x03':
    goto switchD_00520b22_caseD_3;
  case '\x04':
  case '\x05':
  case '\a':
    goto switchD_00520b22_caseD_4;
  default:
    goto switchD_00520b22_caseD_6;
  case '\b':
    sprintf(&stack0x00000008,s__ld__1d,in_stack_00000040->interger_value_1,
            in_stack_00000040->interger_value_2);
    sprintf(pSVar3->text1,s__s,&stack0x00000008);
    goto switchD_00520b22_caseD_3;
  }
  if (iVar5 == 0) {
switchD_00520b22_caseD_4:
    pSVar3->text1[0] = '\0';
  }
  else {
LAB_00520b72:
    sprintf(pSVar3->text1,s__s,&stack0x00000008);
  }
switchD_00520b22_caseD_6:
  sVar11 = (short)in_stack_00000044;
  iVar5 = Time_Line_Panel::calculate_icon_location(unaff_EBX,pSVar3,sVar11,(uchar)in_stack_00000048)
  ;
  uVar1 = pSVar3->event;
  if (uVar1 == '\0') {
    TDrawArea::DrawVertLine
              ((TDrawArea *)unaff_EBX->_padding_,pSVar3->X_line_pos,pSVar3->Y_line_pos,
               pSVar3->intermediate_y_line_segment,uVar4);
  }
  else {
    if (uVar1 == '\x01') {
      TDrawArea::DrawVertLine
                ((TDrawArea *)unaff_EBX->_padding_,pSVar3->X_line_pos,pSVar3->Y_line_pos,
                 pSVar3->intermediate_y_line_segment,uVar4);
      return;
    }
    if (uVar1 == '\x02') {
      TDrawArea::DrawVertLine
                ((TDrawArea *)unaff_EBX->_padding_,pSVar3->X_line_pos,pSVar3->Y_line_pos,
                 pSVar3->intermediate_y_line_segment,uVar4);
      return;
    }
    if (iVar5 != 0) {
      TShape::shape_draw(unaff_EBX->special_events_pic,(TDrawArea *)unaff_EBX->_padding_,
                         pSVar3->start_x,pSVar3->start_y,(int)sVar11,'\0',(uchar *)0x0);
      return;
    }
  }
  return;
switchD_00520b22_caseD_3:
  sprintf(pSVar3->text1,s__ld,pSVar3->pop_total);
  uVar6 = 0xffffffff;
  iVar5 = 0;
  pcVar10 = pSVar3->text1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar8 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar8 != '\0');
  iVar2 = pSVar3->time_slice * 0xf;
  pSVar3->text_length1 = ~uVar6 - 1;
  iVar7 = 0;
  if ((0x3b < iVar2) && (iVar7 = iVar2 / 0x3c, 0x3b < iVar7)) {
    iVar5 = iVar7 / 0x3c;
    iVar7 = iVar7 % 0x3c;
  }
  sprintf(&stack0x00000008,s__1ld__02ld,iVar5,iVar7);
  sprintf(pSVar3->text2,s__s,&stack0x00000008);
  uVar6 = 0xffffffff;
  pcVar10 = pSVar3->text2;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar8 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar8 != '\0');
  pSVar3->text_length2 = ~uVar6 - 1;
  goto switchD_00520b22_caseD_6;
}

// --------------------------------------------------

// Function: FUN_00520d25
// Address: 00520d25
// XREFS: None
uint __fastcall FUN_00520d25(int param_1,int param_2)
{
  char *pcVar1;
  uint in_EAX;
  uint uVar2;
  char cVar3;
  TPanel *unaff_EBX;
  int unaff_EBP;
  
  unaff_EBX->_padding_ = unaff_EBX->_padding_ - param_1;
  *(char *)(param_2 + 0xb) = *(char *)(param_2 + 0xb) + (char)in_EAX;
  pcVar1 = (char *)((int)&unaff_EBX->previousModalPanelValue + 3);
  cVar3 = (char)unaff_EBX;
  *pcVar1 = *pcVar1 + cVar3;
  *(char *)(unaff_EBP + 0x6900520b) = *(char *)(unaff_EBP + 0x6900520b) + cVar3;
  uVar2 = in_EAX | 0x52;
  *(char *)(unaff_EBP + -0x69ffadf5) = *(char *)(unaff_EBP + -0x69ffadf5) + cVar3;
  if ((TShape *)unaff_EBX[5].pnl_y != (TShape *)0x0) {
    uVar2 = TShape::shape_count((TShape *)unaff_EBX[5].pnl_y);
    if (uVar2 != 0) {
      uVar2 = TPanel::width(unaff_EBX);
    }
  }
  return uVar2;
}

// --------------------------------------------------

// Function: encrypt_codes
// Address: 00520fc0
// XREFS: processCheatCode, setup_cmd_options
// [HELPER] s_1_tpnl_tim_cpp_0058b760: "1\tpnl_tim.cpp"
void __cdecl encrypt_codes(char *param_1,char *param_2,int param_3)
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  cVar1 = *param_1;
  iVar3 = 0;
  while ((cVar1 != '\0' && (param_1 = param_1 + 1, iVar3 < param_3))) {
    if ((cVar1 < 'A') || ('_' < cVar1)) {
      *param_2 = cVar1;
      param_2 = param_2 + 1;
      iVar3 = iVar3 + 1;
    }
    else {
      uVar2 = *(undefined4 *)(s_1_tpnl_tim_cpp_0058b760 + cVar1 * 4);
      *param_2 = (char)((uint)uVar2 >> 8);
      param_2[1] = (char)uVar2;
      param_2 = param_2 + 2;
      iVar3 = iVar3 + 2;
    }
    cVar1 = *param_1;
  }
  *param_2 = '\0';
  return;
}

// --------------------------------------------------

// Function: run_log
// Address: 00521020
// XREFS: let_game_begin, setup
// [HELPER] s__s_: "%s\n"
// [HELPER] s__s____s_: "%s - %s\n"
// [HELPER] s_a: "a"
// [HELPER] s_c__aoerun_txt: "c:\aoerun.txt"
// [HELPER] s_w: "w"
void __cdecl run_log(char *param_1,int param_2)
{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char stime [26];
  
  if (do_run_log != 0) {
    if (run_log_created == 0) {
      run_log_file = (_iobuf *)fopen(s_c__aoerun_txt,s_w);
      run_log_created = 1;
    }
    else {
      run_log_file = (_iobuf *)fopen(s_c__aoerun_txt,s_a);
    }
    if (run_log_file != (_iobuf *)0x0) {
      if (param_2 != 0) {
        time(&param_2);
        pcVar3 = stime;
        for (iVar2 = 6; pcVar3 = pcVar3 + 4, iVar2 != 0; iVar2 = iVar2 + -1) {
          pcVar3[0] = '\0';
          pcVar3[1] = '\0';
          pcVar3[2] = '\0';
          pcVar3[3] = '\0';
        }
        pcVar3[0] = '\0';
        pcVar3[1] = '\0';
        uVar1 = ctime(&param_2,0x18);
        strncpy(stime + 4,uVar1);
        fprintf(run_log_file,s__s____s_,stime + 4,param_1);
        fclose(run_log_file);
        return;
      }
      fprintf(run_log_file,s__s_,param_1);
      fclose(run_log_file);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052321f
// Address: 0052321f
// XREFS: None
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
TPanel * __fastcall FUN_0052321f(undefined4 param_1,int *param_2)
{
  char *pcVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte bVar9;
  int in_EAX;
  char *pcVar6;
  int iVar7;
  TPanel *pTVar8;
  char cVar10;
  byte bVar12;
  undefined4 extraout_ECX;
  undefined2 uVar13;
  int *piVar11;
  char cVar14;
  byte bVar15;
  byte bVar18;
  undefined3 uVar19;
  uint *puVar16;
  int iVar17;
  undefined2 uVar20;
  byte bVar21;
  char *unaff_EBX;
  undefined4 *puVar22;
  int *unaff_ESI;
  char *unaff_EDI;
  int in_GS_OFFSET;
  byte in_AF;
  undefined8 uVar23;
  undefined4 uStack0000004f;
  undefined4 uStack00000057;
  byte *pbStack000000c7;
  byte *pbStack000000cb;
  byte *pbStack000000cf;
  byte *pbStack000000d3;
  byte *pbStack000000d7;
  byte *pbStack000000db;
  byte *pbStack000000df;
  byte *pbStack000000e3;
  undefined4 uStack000000e7;
  undefined4 uStack000000eb;
  int *piStack000000ef;
  int *piStack000000f3;
  int *piStack000000f7;
  int *piStack000000fb;
  int *piStack000000ff;
  int *piStack00000103;
  int *piStack00000107;
  int *piStack0000010b;
  int *piStack0000010f;
  int *piStack00000113;
  int *piStack00000117;
  int *piStack0000011b;
  int *piStack00000138;
  int *piStack0000013c;
  int *piStack00000140;
  
  *param_2 = *param_2 + in_EAX;
  pcVar6 = (char *)(in_EAX + *(int *)(in_EAX + -0x746ffa));
  cVar14 = (char)((uint)param_1 >> 8);
  cVar5 = (char)((uint)param_2 >> 8);
  if ((int)pcVar6 < 0) {
    unaff_EDI[-0x5affadd7] = unaff_EDI[-0x5affadd7] + (char)param_1;
    *param_2 = *param_2 - (int)param_2;
    unaff_EBX = (char *)0xd1005229;
    *param_2 = *param_2 - (int)param_2;
    if (*param_2 < 0) {
      unaff_EDI[0x2a] = unaff_EDI[0x2a] + cVar5;
      *pcVar6 = *pcVar6 + (char)pcVar6;
      *param_2 = (int)(pcVar6 + *param_2);
      pcVar6 = (char *)CONCAT31((int3)((uint)(pcVar6 + *unaff_ESI) >> 8),
                                (char)(pcVar6 + *unaff_ESI) + '\x06');
    }
    else {
      cRamd1005253 = cRamd1005253 + cVar14;
    }
  }
  pcVar6 = pcVar6 + -0x74fafb;
  piVar11 = (int *)*param_2;
  *param_2 = *param_2 - (int)param_2;
  *pcVar6 = *pcVar6 + cVar14 + (char)*param_2 + (piVar11 < param_2);
  uVar19 = (undefined3)((uint)param_2 >> 8);
  cVar14 = (char)param_2 - (char)*param_2;
  piStack0000013c = (int *)CONCAT31(uVar19,cVar14 - *(char *)CONCAT31(uVar19,cVar14));
  puVar22 = (undefined4 *)(*piStack0000013c * 0x52);
  pcVar1 = (char *)((int)piStack0000013c + 0x2a9d0052 + (int)puVar22);
  *pcVar1 = *pcVar1 + (char)pcVar6;
  *(char *)((int)unaff_ESI + -0x30ffadd6) = *(char *)((int)unaff_ESI + -0x30ffadd6) + cVar5;
  piStack00000138 = (int *)0x523305;
  piStack00000140 = param_2;
  uVar23 = func_0x0152852f();
  puVar16 = (uint *)((ulonglong)uVar23 >> 0x20);
  iVar7 = (int)uVar23;
  piStack00000138 = (int *)((int)puVar16 - *puVar16);
  uVar13 = (undefined2)((uint)extraout_ECX >> 0x10);
  cVar14 = ((char)((uint)extraout_ECX >> 8) - *unaff_EBX) - (puVar16 < (uint *)*puVar16);
  *unaff_EBX = *unaff_EBX + (char)((uint)piStack00000138 >> 8);
  iVar17 = ((int)piStack00000138 - *piStack00000138) -
           *(int *)((int)piStack00000138 - *piStack00000138);
  piStack000000ef = (int *)(iVar17 - *(int *)(in_GS_OFFSET + iVar17));
  if (piStack000000ef == (int *)0x0 || iVar17 < *(int *)(in_GS_OFFSET + iVar17)) {
    cVar5 = (char)uVar23 + -0x52;
    iVar7 = CONCAT31((int3)((ulonglong)uVar23 >> 8),cVar5);
    iVar17 = CONCAT22(uVar13,CONCAT11(cVar14 + cVar5,(char)extraout_ECX));
code_r0x0052332a:
    cVar5 = (char)((uint)iVar17 >> 8);
    *unaff_EBX = *unaff_EBX + cVar5;
    cVar14 = (char)iVar7 + -0x52;
    *(char *)(iVar17 + 0x2c) = *(char *)(iVar17 + 0x2c) + cVar14;
    unaff_EDI[0x2c] = unaff_EDI[0x2c] + (char)piStack000000ef;
    *(char *)(puVar22 + 0xb) = *(char *)(puVar22 + 0xb) + cVar5;
    unaff_EBX[-0x66ffadd4] = unaff_EBX[-0x66ffadd4] + cVar14;
    unaff_EDI[-0x3affadd4] = unaff_EDI[-0x3affadd4] + cVar5;
    unaff_EBX = (char *)CONCAT31((int3)((uint)unaff_EBX >> 8),(char)unaff_EBX * '\x02');
    iVar17 = CONCAT31((int3)((uint)iVar17 >> 8),(char)iVar17 + (char)((uint)piStack000000ef >> 8));
    cVar14 = (char)iVar7 + 'f';
    iVar7 = CONCAT31((int3)((uint)iVar7 >> 8),cVar14);
    *unaff_EDI = *unaff_EDI + cVar14;
  }
  else {
    unaff_EDI[-0x4fffadd5] = unaff_EDI[-0x4fffadd5] + (char)piStack000000ef;
    puVar22 = (undefined4 *)*puVar22;
    piStack000000ef =
         (int *)(((int)piStack000000ef - *piStack000000ef) -
                *(int *)((int)piStack000000ef - *piStack000000ef));
    iVar17 = CONCAT22(uVar13,CONCAT11(cVar14,(char)extraout_ECX)) + -1;
    if (iVar17 == 0) goto code_r0x0052332a;
  }
  cVar14 = (char)((uint)piStack000000ef >> 8);
  *unaff_EBX = *unaff_EBX + cVar14;
  unaff_EDI[0x2d] = unaff_EDI[0x2d] + (char)unaff_EBX;
  *(char *)((int)puVar22 + 0x2d) = *(char *)((int)puVar22 + 0x2d) + cVar14;
  cVar10 = (char)iVar17;
  unaff_EBX[-0x5effadd3] = unaff_EBX[-0x5effadd3] + cVar10;
  uVar13 = (undefined2)((uint)iVar17 >> 0x10);
  bVar12 = (char)((uint)iVar17 >> 8) + cVar10;
  bVar21 = (byte)((uint)unaff_EBX >> 8);
  piVar11 = (int *)CONCAT31((int3)(CONCAT22(uVar13,CONCAT11(bVar12,cVar10)) >> 8),cVar10 + bVar21);
  iVar7 = iVar7 + 0x1bf0fe66;
  unaff_EDI[0x2a] = unaff_EDI[0x2a] + cVar14;
  *(char *)((int)puVar22 + 0x2e) = *(char *)((int)puVar22 + 0x2e) + bVar21;
  bVar15 = (byte)piStack000000ef;
  unaff_EBX[-0x56ffadd2] = unaff_EBX[-0x56ffadd2] + bVar15;
  bVar9 = (byte)((uint)iVar7 >> 8);
  cRam3b00522e = cRam3b00522e + bVar9;
  *(char *)((int)piVar11 + 0x2e) = *(char *)((int)piVar11 + 0x2e) + bVar15;
  unaff_EDI[0x2e] = unaff_EDI[0x2e] + bVar9;
  unaff_EDI[-0x2affadd2] = unaff_EDI[-0x2affadd2] + bVar21;
  uVar20 = (undefined2)((uint)piStack000000ef >> 0x10);
  uStack000000eb = CONCAT22(uVar20,CONCAT11(cVar14 + bVar21,bVar15));
  cVar14 = cVar14 + bVar21 + bVar21;
  uStack000000e7 = CONCAT22(uVar20,CONCAT11(cVar14,bVar15));
  bVar18 = cVar14 + bVar21;
  pbStack000000cf = (byte *)CONCAT22(uVar20,CONCAT11(bVar18,bVar15));
  unaff_EDI[(int)puVar22] = unaff_EDI[(int)puVar22] + bVar15;
  bVar4 = *pbStack000000cf;
  *pbStack000000cf = *pbStack000000cf + bVar12;
  in_AF = 9 < ((byte)iVar7 & 0xf) | in_AF;
  bVar3 = (byte)iVar7 + in_AF * -6;
  bVar3 = bVar3 + (0x9f < bVar3 | CARRY1(bVar4,bVar12) | in_AF * (bVar3 < 6)) * -0x60;
  pcVar6 = (char *)(CONCAT31((int3)((uint)iVar7 >> 8),bVar3) + 0x2f);
  *pcVar6 = *pcVar6 + bVar3;
  *(char *)((int)unaff_ESI + 0x2f) = *(char *)((int)unaff_ESI + 0x2f) + bVar15;
  in_AF = 9 < (bVar3 + bVar15 & 0xf) | in_AF;
  bVar4 = bVar3 + bVar15 + in_AF * -6;
  bVar4 = bVar4 + (0x9f < bVar4 | CARRY1(bVar3,bVar15) | in_AF * (bVar4 < 6)) * -0x60;
  pbStack000000c7 = (byte *)CONCAT22(uVar20,CONCAT11(bVar18 + bVar9,bVar15));
  in_AF = 9 < (bVar4 & 0xf) | in_AF;
  bVar4 = bVar4 + in_AF * -6;
  bVar4 = bVar4 + (0x9f < bVar4 | CARRY1(bVar18,bVar9) | in_AF * (bVar4 < 6)) * -0x60;
  in_AF = 9 < (bVar4 & 0xf) | in_AF;
  bVar3 = bVar4 + in_AF * -6;
  cVar5 = bVar3 + (0x9f < bVar3 | CARRY1(bVar9,bVar21) | in_AF * (bVar3 < 6)) * -0x60;
  pcVar6 = (char *)CONCAT31((int3)(CONCAT22((short)((uint)iVar7 >> 0x10),
                                            CONCAT11(bVar9 + bVar21,bVar4)) >> 8),cVar5);
  *pbStack000000c7 = *pbStack000000c7 + bVar15;
  *pbStack000000c7 = *pbStack000000c7 ^ bVar15;
  cVar14 = (byte)uRam2800522f;
  uRam2800522f = uRam2800522f ^ 0x2f;
  if (cVar14 == '/') {
    *pcVar6 = *pcVar6 + cVar5;
    pcVar1 = pcVar6 + uRam2800522f;
    pcVar6 = pcVar6 + *(int *)((int)unaff_ESI + (int)pcVar6) + -0x71007470;
    uRam2800522f = (uint)pcVar1 ^ 0x2f;
  }
  *unaff_EDI = (char)*unaff_ESI;
  uVar2 = uRam2800522f;
  bVar4 = (byte)uRam2800522f ^ 0x2f;
  uRam2800522f = uRam2800522f ^ 0x2f;
  if ((char)bVar4 < '\0') {
    piVar11 = (int *)CONCAT22(uVar13,CONCAT11(bVar12 * '\x02',cVar10 + bVar21));
code_r0x00523449:
    uRam2800522f = uRam2800522f ^ 0x2800522f;
    pcVar6 = (char *)piVar11[0x6c];
    if (((pcVar6 != (char *)0x4) && (pcVar6 != (char *)0x6)) && (pcVar6 != (char *)0x5))
    goto LAB_00523476;
  }
  else {
    cRamf800a45f = cRamf800a45f + bVar21;
    uRam2800522f = uVar2 ^ 0x2800522f;
    *piVar11 = (int)((int)unaff_ESI + *piVar11 + 1);
    unaff_EDI[1] = unaff_EDI[1] + (char)((uint)pcVar6 >> 8);
    if ((int)uRam2800522f < 1) {
      *(char *)((int)puVar22 + -0x54ffadcf) = *(char *)((int)puVar22 + -0x54ffadcf) + '/';
      uRam2800522f = uRam2800522f ^ 0x2800522f;
      *piVar11 = *piVar11 << 0x12;
      uRam2800522f = uRam2800522f ^ 0x2800522f;
      in(0x522f);
      goto code_r0x00523449;
    }
    pcVar6 = (char *)((uint)pcVar6 & 0xffffff0c);
    *pcVar6 = *pcVar6 + (char)pcVar6;
  }
  if (piVar11[0x309] != 0) {
    return *(TPanel **)(piVar11[0x309] + 0x4b8);
  }
LAB_00523476:
  uStack00000057 = 0x2800522f;
  if (pcVar6 == &DAT_00000007) {
    uStack0000004f = 0x52348a;
    pbStack000000cb = pbStack000000c7;
    pbStack000000d3 = pbStack000000cf;
    pbStack000000d7 = pbStack000000cf;
    pbStack000000db = pbStack000000cf;
    pbStack000000df = pbStack000000cf;
    pbStack000000e3 = pbStack000000cf;
    piStack000000f3 = piStack000000ef;
    piStack000000f7 = piStack000000ef;
    piStack000000fb = piStack000000ef;
    piStack000000ff = piStack000000ef;
    piStack00000103 = piStack000000ef;
    piStack00000107 = piStack000000ef;
    piStack0000010b = piStack000000ef;
    piStack0000010f = piStack000000ef;
    piStack00000113 = piStack000000ef;
    piStack00000117 = piStack000000ef;
    piStack0000011b = piStack000000ef;
    pTVar8 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Screen);
    if (pTVar8 != (TPanel *)0x0) {
      return pTVar8[5].previousPanelValue;
    }
  }
  return (TPanel *)0x0;
}

// --------------------------------------------------

// Function: video_sub_wnd_proc
// Address: 00523ae0
// XREFS: start_video
void video_sub_wnd_proc(void *param_1,uint param_2,uint param_3,long param_4)
{
  TRIBE_Game::video_wnd_proc((TRIBE_Game *)rge_base_game,param_1,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_00523ef6
// Address: 00523ef6
// XREFS: None
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_open_mid: "open.mid"
// [HELPER] s_open_wav: "open.wav"
undefined4 __fastcall FUN_00523ef6(TRIBE_Game *param_1,int param_2)
{
  uchar uVar1;
  TMusic_System *this;
  int in_EAX;
  TRIBE_Screen_Campaign_Selection *this_00;
  undefined4 *puVar2;
  int unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 uStack_18;
  code *pcStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  *(char *)(unaff_EBX + 0x3c) = *(char *)(unaff_EBX + 0x3c) + (char)param_1;
  *(char *)(in_EAX + 0x3c) = *(char *)(in_EAX + 0x3c) + (char)((uint)unaff_EBX >> 8);
  *(char *)(param_2 + 0x7e00523c) = *(char *)(param_2 + 0x7e00523c) + (char)((uint)in_EAX >> 8);
  *(char *)(param_2 + -1) = *(char *)(param_2 + -1) + (char)((uint)param_1 >> 8);
  pcStack_14 = FUN_0056178b;
  uStack_18 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_18;
  iStack_10 = param_2;
  iStack_c = param_2;
  iStack_8 = param_2;
  if (param_1->video_setup != 0) {
    TRIBE_Game::shutdown_video_system(param_1);
  }
  this_00 = (TRIBE_Screen_Campaign_Selection *)operator_new(0x4cc);
  iStack_10 = 0;
  if (this_00 == (TRIBE_Screen_Campaign_Selection *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection(this_00)
    ;
  }
  iStack_10 = 0xffffffff;
  if (puVar2 == (undefined4 *)0x0) {
    *unaff_FS_OFFSET = uStack_18;
    return 0;
  }
  if (puVar2[0x36] != 0) {
    (**(code **)*puVar2)(1);
    *unaff_FS_OFFSET = this_00;
    return 0;
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Campaign_Selection_Screen,0);
  (**(code **)(param_1->_padding_ + 0xc))(2);
  this = (TMusic_System *)param_1->_padding_;
  if ((this == (TMusic_System *)0x0) || (param_1->started_menu_music != 0)) goto LAB_0052400d;
  uVar1 = this->music_type;
  if (uVar1 == '\x01') {
    TMusic_System::play_track(this,2,0,0);
  }
  else {
    if (uVar1 == '\x02') {
      pcVar3 = s_open_mid;
    }
    else {
      if (uVar1 != '\x03') goto LAB_00524003;
      pcVar3 = s_open_wav;
    }
    TMusic_System::play_file(this,pcVar3,0,0);
  }
LAB_00524003:
  param_1->started_menu_music = 1;
LAB_0052400d:
  *unaff_FS_OFFSET = this_00;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00528d63
// Address: 00528d63
// XREFS: None
// [HELPER] s_Blank_Screen: "Blank Screen"
// [HELPER] s_Scenario_Editor_Menu: "Scenario Editor Menu"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_Status_Screen: "Status Screen"
undefined4 __fastcall FUN_00528d63(RGE_Base_Game *param_1,char *param_2)
{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  char cVar4;
  byte bVar5;
  char cVar8;
  byte *in_EAX;
  undefined3 uVar9;
  TRIBE_Screen_Sed *this;
  int iVar6;
  TPanel *pTVar7;
  char cVar10;
  undefined2 uVar11;
  byte bVar12;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar13;
  undefined4 uStack_2d;
  code *pcStack_29;
  undefined4 uStack_25;
  char *pcStack_21;
  char *pcStack_1d;
  int *piStack_19;
  int *piStack_15;
  int *piStack_11;
  undefined4 *puStack_d;
  undefined4 *puStack_8;
  char *pcStack_4;
  
  while( true ) {
    puVar1 = (uint *)((int)unaff_ESI + -0x7917ffae);
    *puVar1 = *puVar1 << 1 | (uint)((int)*puVar1 < 0);
    pcStack_4 = param_2;
    bVar5 = (byte)((uint)in_EAX >> 8);
    bVar12 = (byte)((uint)unaff_EBX >> 8);
    cVar4 = (char)in_EAX;
    cVar8 = bVar5 + bVar12;
    pcVar13 = (char *)CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(cVar8,cVar4));
    LOCK();
    cVar10 = *param_2;
    *param_2 = (char)param_2;
    puStack_8 = (undefined4 *)CONCAT31((int3)((uint)param_2 >> 8),cVar10);
    UNLOCK();
    *(char *)(unaff_EDI + -0x78dbffae) =
         *(char *)(unaff_EDI + -0x78dbffae) + cVar4 + CARRY1(bVar5,bVar12);
    *pcVar13 = *pcVar13 + bVar12;
    LOCK();
    puVar2 = (undefined4 *)*puStack_8;
    *puStack_8 = puStack_8;
    UNLOCK();
    LOCK();
    puStack_d = (undefined4 *)*puVar2;
    *puVar2 = puVar2;
    UNLOCK();
    *(char **)(unaff_EDI + -0x7868ffae) = pcVar13;
    *(char *)(unaff_EBP + -0x4cffad79) = *(char *)(unaff_EBP + -0x4cffad79) + cVar8;
    LOCK();
    piVar3 = (int *)*puStack_d;
    *puStack_d = puStack_d;
    UNLOCK();
    puVar1 = (uint *)(unaff_EDI + -0x7830ffae);
    *puVar1 = *puVar1 << 0x12 | *puVar1 >> 0xe;
    *(char *)&param_1[-1].save_check_for_cd = (char)param_1[-1].save_check_for_cd + cVar4;
    piStack_11 = piVar3;
    *(char *)(unaff_EDI + -0x78) = *(char *)(unaff_EDI + -0x78) + (char)param_1;
    piStack_15 = piVar3;
    *(char *)(unaff_ESI + -0x1e) = *(char *)(unaff_ESI + -0x1e) + (char)((uint)param_1 >> 8);
    piStack_19 = piVar3;
    *(char *)(unaff_EBP + -0x64ffad78) = *(char *)(unaff_EBP + -0x64ffad78) + (char)param_1;
    cVar10 = (char)piVar3;
    *(char *)piVar3 = cVar10;
    *(char *)((int)&piStack_19 + (int)pcVar13) = *(char *)((int)&piStack_19 + (int)pcVar13) + cVar4;
    uVar9 = (undefined3)((uint)pcVar13 >> 8);
    bVar5 = cVar4 + 8;
    *piVar3 = *piVar3 + CONCAT31(uVar9,bVar5);
    param_1 = (RGE_Base_Game *)(param_1->save_music_file + *(int *)(unaff_EBX + 0x5288f0ff) + -0x80)
    ;
    uVar11 = CONCAT11((char)((uint)piVar3 >> 8) + bVar12,cVar10);
    param_2 = (char *)CONCAT22((short)((uint)piVar3 >> 0x10),uVar11);
    *param_2 = cVar10;
    in_EAX = (byte *)(CONCAT31(uVar9,bVar5) | 0x89);
    *param_2 = *param_2 + (char)unaff_EBX;
    cVar10 = *param_2;
    *(char **)param_2 = param_2;
    *(char **)((int)unaff_FS_OFFSET + (int)param_2) = param_2;
    *(char **)param_2 = param_2;
    out(*unaff_ESI,uVar11);
    *(char **)param_2 = param_2;
    if ((POPCOUNT(cVar10) & 1U) != 0) break;
    *in_EAX = *in_EAX | bVar5 | 0x89;
    unaff_EBX = CONCAT31((int3)((uint)unaff_EBX >> 8),(char)unaff_EBX + (bVar5 | 0x89));
    unaff_ESI = unaff_ESI + 1;
  }
  *(char *)(unaff_EBP + -0x6fffad77) = *(char *)(unaff_EBP + -0x6fffad77) + (char)in_EAX;
  *(char **)param_2 = param_2;
  uStack_25 = 0xffffffff;
  pcStack_29 = FUN_0056180b;
  uStack_2d = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_2d;
  pcStack_21 = param_2;
  RGE_Base_Game::disable_input(param_1);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  this = (TRIBE_Screen_Sed *)operator_new(0x948);
  uStack_25 = 0;
  if (this == (TRIBE_Screen_Sed *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = TRIBE_Screen_Sed::TRIBE_Screen_Sed(this,pcStack_1d,(int)piStack_19);
  }
  uStack_25 = 0xffffffff;
  if ((iVar6 != 0) && (*(int *)(iVar6 + 0xd8) == 0)) {
    if (param_1->music_system != (TMusic_System *)0x0) {
      TMusic_System::stop_track(param_1->music_system);
      param_1[1].work_dir[0x10] = '\0';
      param_1[1].work_dir[0x11] = '\0';
      param_1[1].work_dir[0x12] = '\0';
      param_1[1].work_dir[0x13] = '\0';
    }
    TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Open);
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Menu);
    TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
    TMousePointer::center(param_1->mouse_pointer);
    RGE_Base_Game::enable_input(param_1);
    *unaff_FS_OFFSET = uStack_2d;
    return 1;
  }
  pTVar7 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Open);
  if (pTVar7 == (TPanel *)0x0) {
    pTVar7 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Menu);
    if (pTVar7 == (TPanel *)0x0) {
      pcVar13 = s_Blank_Screen;
    }
    else {
      pcVar13 = s_Scenario_Editor_Menu;
    }
  }
  else {
    pcVar13 = s_Scenario_Editor_Open;
  }
  TPanelSystem::setCurrentPanel(&panel_system,pcVar13,0);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  RGE_Base_Game::enable_input(param_1);
  *unaff_FS_OFFSET = uStack_2d;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00529edf
// Address: 00529edf
// XREFS: None
void FUN_00529edf(void)
{
  return;
}

// --------------------------------------------------

// Function: $E2
// Address: 0052a970
// XREFS: None
void _E2(void)
{
  TRIGONOMETRY::TRIGONOMETRY(&trig);
  return;
}

// --------------------------------------------------

// Function: $E1
// Address: 0052a980
// XREFS: $E2
void _E1(void)
{
  TRIGONOMETRY::TRIGONOMETRY(&trig);
  return;
}

// --------------------------------------------------

// Function: FUN_0052c3d3
// Address: 0052c3d3
// XREFS: None
void FUN_0052c3d3(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0052c8a1
// Address: 0052c8a1
// XREFS: None
int __fastcall FUN_0052c8a1(RGE_Task_List *param_1,RGE_Task *param_2)
{
  char *in_EAX;
  int iVar1;
  char cVar2;
  undefined4 unaff_EBX;
  bool in_OF;
  
  if (in_OF) {
    halt_baddata();
  }
  cVar2 = (char)((uint)param_2 >> 8);
  in_EAX[-0x3c] = in_EAX[-0x3c] + cVar2;
  (&stack0x0000004a)[(int)in_EAX * 8] =
       (&stack0x0000004a)[(int)in_EAX * 8] + (char)((uint)unaff_EBX >> 8);
  in_EAX[-0x3c] = in_EAX[-0x3c] + cVar2;
  in_EAX[0x52c4] = in_EAX[0x52c4] + (char)((uint)in_EAX >> 8);
  *in_EAX = *in_EAX + (char)in_EAX;
  if (param_2->action_type == 0x68) {
    return 1;
  }
  iVar1 = RGE_Task_List::is_attack_task(param_1,param_2);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_005310de
// Address: 005310de
// XREFS: None
void __fastcall FUN_005310de(byte *param_1,int param_2)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uchar uVar4;
  char cVar9;
  uint in_EAX;
  undefined1 (*pauVar5) [16];
  byte *pbVar6;
  int iVar7;
  long lVar8;
  char cVar13;
  int iVar10;
  uint uVar11;
  uint uVar12;
  byte bVar14;
  byte bVar15;
  char cVar16;
  char *unaff_EBX;
  int unaff_ESI;
  int iVar17;
  byte *unaff_EDI;
  long lVar18;
  char *pcVar19;
  char *pcVar20;
  byte *pbVar21;
  undefined2 in_CS;
  char in_CF;
  bool bVar22;
  bool bVar23;
  undefined1 in_XMM0 [16];
  int iStack_48;
  byte *pbStack_44;
  byte *pbStack_40;
  byte *pbStack_3c;
  byte *pbStack_38;
  byte *pbStack_34;
  char *pcStack_2c;
  char *pcStack_24;
  char *pcStack_20;
  char *pcStack_18;
  char *pcStack_14;
  
  bVar2 = (byte)param_1;
  *unaff_EBX = (*unaff_EBX - bVar2) - in_CF;
  cVar9 = (char)(in_EAX >> 8);
  *(char *)(unaff_ESI + 0xb) = *(char *)(unaff_ESI + 0xb) + cVar9;
  bVar14 = (byte)((uint)param_2 >> 8);
  (unaff_EBX + 0xbdd0053)[(int)param_1] = (unaff_EBX + 0xbdd0053)[(int)param_1] + bVar14;
  *param_1 = *param_1 + bVar2;
  cRam4f00530c = cRam4f00530c + bVar14;
  cVar16 = (char)((uint)unaff_EBX >> 8);
  unaff_EBX[0xc] = unaff_EBX[0xc] + cVar16;
  unaff_EDI[-0x2cffacf4] = unaff_EDI[-0x2cffacf4] + cVar9;
  cVar16 = cVar16 * '\x02';
  pcStack_14 = (char *)CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(cVar16,(char)unaff_EBX));
  cVar13 = (char)((uint)param_1 >> 8);
  *pcStack_14 = *pcStack_14 + cVar13;
  pcStack_14[-0x50ffacf3] = pcStack_14[-0x50ffacf3] + ((byte)in_EAX | 0x53);
  pauVar5 = (undefined1 (*) [16])(in_EAX | 0xdff0053);
  pcStack_18 = pcStack_14;
  *param_1 = *param_1 + cVar13;
  pcStack_20 = pcStack_14;
  unaff_EDI[0xe] = unaff_EDI[0xe] + bVar14;
  pcStack_24 = pcStack_14;
  unaff_EDI[-0x36ffacf2] = unaff_EDI[-0x36ffacf2] + cVar13;
  pcStack_2c = pcStack_14;
  bVar15 = (char)unaff_EBX + cVar9;
  pbStack_34 = (byte *)CONCAT31((int3)((uint)pcStack_14 >> 8),bVar15);
  (*pauVar5)[0xf] = (*pauVar5)[0xf] + cVar9;
  pbStack_38 = pbStack_34;
  *(char *)(unaff_ESI + -0x46ffacf1) = *(char *)(unaff_ESI + -0x46ffacf1) + bVar15;
  rcpps(in_XMM0,*pauVar5);
  *unaff_EDI = *unaff_EDI >> 1 | *unaff_EDI << 7;
  pbStack_3c = pbStack_34;
  (*pauVar5)[param_2] = (*pauVar5)[param_2] + cVar16;
  pbStack_40 = pbStack_34;
  *(char *)(param_2 + 0x10) = *(char *)(param_2 + 0x10) + cVar16;
  pbStack_44 = pbStack_34;
  pbVar6 = (byte *)(unaff_ESI + -0x28ffacf0);
  bVar1 = *pbVar6;
  *pbVar6 = *pbVar6 + bVar14;
  bVar3 = (byte)param_2;
  *pbStack_34 = *pbStack_34 + bVar3 + CARRY1(bVar1,bVar14);
  *param_1 = *param_1 + (char)pauVar5;
  bVar1 = *pbStack_34;
  *param_1 = *param_1 | bVar2;
  iVar10 = CONCAT31((int3)((uint)param_1 >> 8),bVar2 | *pbStack_34);
  bVar2 = (char)pauVar5 + bVar1 + 5 | 0xd;
  iStack_48 = CONCAT22((short)((uint)iStack_48 >> 0x10),in_CS);
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < CARRY1(bVar3,*pbStack_34);
  bVar1 = bVar1 - CARRY1(bVar3,*pbStack_34);
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 + 0x15;
  bVar22 = 0xea < bVar2 || CARRY1(bVar1,bVar23);
  bVar1 = bVar1 + bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  pbVar6 = (byte *)CONCAT31((int3)((uint)pauVar5 >> 8),bVar1);
  bVar23 = *pbVar6 < bVar15 || (byte)(*pbVar6 - bVar15) < bVar22;
  *pbVar6 = (*pbVar6 - bVar15) - bVar22;
  bVar22 = *pbVar6 < bVar15 || (byte)(*pbVar6 - bVar15) < bVar23;
  *pbVar6 = (*pbVar6 - bVar15) - bVar23;
  bVar23 = *pbVar6 < bVar15 || (byte)(*pbVar6 - bVar15) < bVar22;
  *pbVar6 = (*pbVar6 - bVar15) - bVar22;
  bVar22 = *pbVar6 < bVar15 || (byte)(*pbVar6 - bVar15) < bVar23;
  *pbVar6 = (*pbVar6 - bVar15) - bVar23;
  bVar23 = *pbVar6 < bVar15 || (byte)(*pbVar6 - bVar15) < bVar22;
  *pbVar6 = (*pbVar6 - bVar15) - bVar22;
  bVar22 = bVar1 < 0x1c || (byte)(bVar1 - 0x1c) < bVar23;
  bVar2 = (bVar1 - 0x1c) - bVar23;
  bVar1 = bVar2 - 0x1c;
  bVar23 = bVar2 < 0x1c || bVar1 < bVar22;
  bVar1 = bVar1 - bVar22;
  bVar2 = bVar1 - 0x1c;
  bVar22 = bVar1 < 0x1c || bVar2 < bVar23;
  bVar2 = bVar2 - bVar23;
  bVar1 = bVar2 - 0x1c;
  bVar3 = bVar1 - bVar22;
  *(uint *)((int)&iStack_48 + (int)pbStack_34) =
       (*(int *)((int)&iStack_48 + (int)pbStack_34) - (int)pbStack_34) -
       (uint)(bVar3 < 0x1c || (byte)(bVar3 - 0x1c) < (bVar2 < 0x1c || bVar1 < bVar22));
  pbVar6 = pbStack_3c;
  iVar17 = 1;
  lVar18 = 0;
  iStack_48 = 1;
  if (1 < *(short *)(iVar10 + 0x3c)) {
    do {
      iVar7 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar10 + 0x40) + iVar17 * 4));
      if (iVar7 == 0) {
        lVar8 = RGE_Victory_Conditions::get_victory_points_group
                          (*(RGE_Victory_Conditions **)
                            (*(int *)(*(int *)(iVar10 + 0x40) + iVar17 * 4) + 0x34),(uchar)pbVar6);
        if (lVar18 < lVar8) {
          lVar18 = RGE_Victory_Conditions::get_victory_points_group
                             (*(RGE_Victory_Conditions **)
                               (*(int *)(*(int *)(iVar10 + 0x40) + iVar17 * 4) + 0x34),(uchar)pbVar6
                             );
          iStack_48 = iVar17;
        }
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 < *(short *)(iVar10 + 0x3c));
  }
  *(long *)pbStack_40 = lVar18;
  iVar17 = iStack_48 * 4;
  pbStack_40[4] = *(byte *)(*(int *)(*(int *)(iVar10 + 0x40) + iVar17) + 0x54);
  uVar11 = 0xffffffff;
  pcVar19 = *(char **)(*(int *)(*(int *)(iVar10 + 0x40) + iVar17) + 0x44);
  do {
    pcVar20 = pcVar19;
    if (uVar11 == 0) break;
    uVar11 = uVar11 - 1;
    pcVar20 = pcVar19 + 1;
    cVar16 = *pcVar19;
    pcVar19 = pcVar20;
  } while (cVar16 != '\0');
  uVar11 = ~uVar11;
  pbStack_3c = (byte *)0x0;
  pbVar6 = (byte *)(pcVar20 + -uVar11);
  pbVar21 = pbStack_40 + 5;
  for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined4 *)pbVar21 = *(undefined4 *)pbVar6;
    pbVar6 = pbVar6 + 4;
    pbVar21 = pbVar21 + 4;
  }
  for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
    *pbVar21 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    pbVar21 = pbVar21 + 1;
  }
  iVar7 = 1;
  if (1 < *(short *)(iVar10 + 0x3c)) {
    do {
      if (((iVar7 != iStack_48) &&
          (uVar4 = RGE_Player::relation
                             (*(RGE_Player **)(*(int *)(iVar10 + 0x40) + iVar7 * 4),iStack_48),
          uVar4 == '\0')) &&
         (uVar4 = RGE_Player::relation(*(RGE_Player **)(*(int *)(iVar10 + 0x40) + iVar17),iVar7),
         uVar4 == '\0')) {
        pbStack_3c = (byte *)((int)pbStack_3c + 1);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(short *)(iVar10 + 0x3c));
  }
  pbStack_40[0x15] = (byte)pbStack_3c;
  return;
}

// --------------------------------------------------

// Function: FUN_005316bd
// Address: 005316bd
// XREFS: None
RGE_Victory_Conditions * __fastcall FUN_005316bd(undefined4 param_1,int *param_2)
{
  long *plVar1;
  RGE_Player *pRVar2;
  float fVar3;
  byte bVar10;
  undefined4 in_EAX;
  int iVar4;
  byte *pbVar5;
  RGE_Victory_Entry *pRVar6;
  RGE_Game_World *pRVar7;
  RGE_Static_Object *pRVar8;
  RGE_Victory_Point_Entry *pRVar9;
  byte bVar11;
  byte bVar12;
  int unaff_EBX;
  RGE_Player *pRVar13;
  int iVar14;
  int unaff_EBP;
  undefined2 in_ES;
  byte in_CF;
  char in_PF;
  char in_AF;
  char in_ZF;
  char in_SF;
  char unaff_retaddr;
  int iStack_28;
  RGE_Victory_Entry **ppRStack_24;
  int iStack_20;
  float fStack_1c;
  int iStack_18;
  long *plStack_14;
  RGE_Player *pRStack_10;
  RGE_Player *pRStack_c;
  RGE_Player *pRStack_8;
  RGE_Victory_Conditions *this;
  
  bVar11 = (byte)unaff_EBX;
  pRVar13 = (RGE_Player *)CONCAT31((int3)((uint)unaff_EBX >> 8),bVar11 * '\x02');
  pbVar5 = (byte *)(unaff_EBP + -0x38ffaceb);
  bVar10 = *pbVar5;
  bVar12 = (byte)((uint)unaff_EBX >> 8);
  *pbVar5 = *pbVar5 + bVar12;
  iVar4 = CONCAT22((short)((uint)in_EAX >> 0x10),
                   CONCAT11(in_SF << 7 | in_ZF << 6 | in_AF << 4 | in_PF << 2 | 2U | in_CF,
                            (char)in_EAX)) + (uint)in_CF + (uint)CARRY1(bVar11,bVar11) + 0x412d00f9
          + (uint)CARRY1(bVar10,bVar12);
  bVar10 = (byte)((uint)iVar4 >> 8);
  bVar12 = (byte)((uint)param_1 >> 8);
  bVar11 = (byte)param_1;
  this = (RGE_Victory_Conditions *)
         CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(bVar12 + bVar10,bVar11));
  pbVar5 = (byte *)(iVar4 + 0x15ef0053 + (uint)CARRY1(bVar12,bVar10));
  *pbVar5 = *pbVar5 + (byte)pbVar5;
  *param_2 = (int)(pbVar5 + *param_2);
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *(byte *)&pRVar13->_padding_ = (byte)pRVar13->_padding_ | (byte)pbVar5;
  plStack_14 = (long *)CONCAT22(plStack_14._2_2_,in_ES);
  this->_padding_ = (int)&RGE_Victory_Conditions::_vftable_;
  pRStack_10 = pRVar13;
  pRStack_c = pRVar13;
  pRStack_8 = pRVar13;
  if (unaff_retaddr == '\x01') {
    rge_read((int)pRVar13,&fStack_1c,4);
  }
  else {
    fStack_1c = 0.0;
  }
  plVar1 = &this->list_num;
  plStack_14 = plVar1;
  rge_read((int)pRVar13,plVar1,4);
  rge_read((int)pRVar13,&this->victory,1);
  ppRStack_24 = &this->victory_list;
  *ppRStack_24 = (RGE_Victory_Entry *)0x0;
  this->player = pRStack_c;
  iVar4 = 0;
  if (0 < *plVar1) {
    do {
      pRVar6 = (RGE_Victory_Entry *)calloc(1,0x34);
      rge_read((int)pRVar13,pRVar6,1);
      rge_read((int)pRVar13,&pRVar6->obj_type,4);
      rge_read((int)pRVar13,&iStack_20,4);
      rge_read((int)pRVar13,&pRVar6->x0,4);
      rge_read((int)pRVar13,&pRVar6->y0,4);
      rge_read((int)pRVar13,&pRVar6->x1,4);
      rge_read((int)pRVar13,&pRVar6->y1,4);
      rge_read((int)pRVar13,&pRVar6->number,4);
      rge_read((int)pRVar13,&pRVar6->count,4);
      rge_read((int)pRVar13,&pRStack_8,4);
      rge_read((int)pRVar13,&iStack_28,4);
      rge_read((int)pRVar13,&pRVar6->victory_group,1);
      rge_read((int)pRVar13,&pRVar6->ally_flag,1);
      pRStack_c = (RGE_Player *)&pRVar6->state;
      rge_read((int)pRVar13,pRStack_c,1);
      pRVar6->target_obj = (RGE_Static_Object *)0x0;
      pRVar6->this_obj = (RGE_Static_Object *)0x0;
      pRVar6->target_player = (RGE_Player *)0x0;
      *ppRStack_24 = pRVar6;
      ppRStack_24 = &pRVar6->next;
      if (-1 < (int)pRStack_8) {
        iVar14 = 0;
        pRVar7 = this->player->world;
        if (0 < pRVar7->player_num) {
          do {
            pRVar8 = RGE_Object_List::find_by_id(pRVar7->players[iVar14]->objects,(long)pRStack_8);
            pRVar6->this_obj = pRVar8;
            if (pRVar8 != (RGE_Static_Object *)0x0) break;
            iVar14 = iVar14 + 1;
            pRVar7 = this->player->world;
          } while (iVar14 < pRVar7->player_num);
        }
        if ((-1 < (int)pRStack_8) && (pRVar6->this_obj == (RGE_Static_Object *)0x0)) {
          *(uchar *)&pRStack_c->_padding_ = '\x03';
        }
      }
      if (-1 < iStack_28) {
        pRVar8 = RGE_Object_List::find_by_id(this->player->objects,iStack_28);
        pRVar6->target_obj = pRVar8;
      }
      if (iStack_20 < 0) {
        pRVar6->target_player = (RGE_Player *)0x0;
      }
      else {
        if (unaff_EBX != 0) {
          iStack_20 = *(int *)(unaff_EBX + iStack_20 * 4);
        }
        if (iStack_20 < 0) {
          *(uchar *)&pRStack_c->_padding_ = '\x03';
        }
        else {
          pRVar2 = this->player->world->players[iStack_20];
          pRVar6->target_player = pRVar2;
          if (((pRVar2 != (RGE_Player *)0x0) && (pRVar6->target_obj == (RGE_Static_Object *)0x0)) &&
             (-1 < iStack_28)) {
            pRVar8 = RGE_Object_List::find_by_id(pRVar2->objects,iStack_28);
            pRVar6->target_obj = pRVar8;
          }
        }
      }
      if ((-1 < iStack_28) && (pRVar6->target_obj == (RGE_Static_Object *)0x0)) {
        *(uchar *)&pRStack_c->_padding_ = '\x03';
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *plStack_14);
  }
  fVar3 = (float)_DAT_00577590;
  this->victory_point_list = (RGE_Victory_Point_Entry *)0x0;
  this->point_list_num = 0;
  if (fStack_1c < fVar3) {
    this->tot_victory_points = 0;
  }
  else {
    plVar1 = &this->tot_victory_points;
    rge_read((int)pRVar13,plVar1,4);
    rge_read((int)pRVar13,&iStack_18,4);
    iVar4 = 0;
    if (0 < iStack_18) {
      do {
        pRVar9 = RGE_Victory_Conditions::add_point(this,'\0','\0');
        rge_read((int)pRVar13,pRVar9,1);
        rge_read((int)pRVar13,&pRVar9->state,1);
        rge_read((int)pRVar13,&pRVar9->attribute,4);
        rge_read((int)pRVar13,&pRVar9->amount,4);
        rge_read((int)pRVar13,&pRVar9->points,4);
        rge_read((int)pRVar13,&pRVar9->curr_points,4);
        rge_read((int)pRVar13,&pRVar9->id,1);
        rge_read((int)pRVar13,&pRVar9->group,1);
        rge_read((int)pRVar13,&pRVar9->curr_attribute_amount,4);
        if (*plVar1 < 0) {
          pRVar9->points = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iStack_18);
    }
    if (*plVar1 < 0) {
      *plVar1 = 0;
      return this;
    }
  }
  return this;
}

// --------------------------------------------------

// Function: FUN_00531f71
// Address: 00531f71
// XREFS: None
void __fastcall FUN_00531f71(RGE_Victory_Conditions *param_1,char param_2)
{
  int in_EAX;
  RGE_Victory_Entry *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(char *)(unaff_EBP + 0x1f) = *(char *)(unaff_EBP + 0x1f) + (char)param_1;
  *(char *)(unaff_ESI + 0x1f) = *(char *)(unaff_ESI + 0x1f) + param_2;
  *(char *)(unaff_EDI + 0x1f) = *(char *)(unaff_EDI + 0x1f) + (char)unaff_EBX;
  *(char *)(in_EAX + 0x1f) = *(char *)(in_EAX + 0x1f) + (char)((uint)param_1 >> 8);
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + param_2;
  switch(unaff_EBX->command) {
  case '\0':
    RGE_Victory_Conditions::handle_capture(param_1,unaff_EBX);
    return;
  case '\x01':
    RGE_Victory_Conditions::handle_create(param_1,unaff_EBX);
    return;
  case '\x02':
    RGE_Victory_Conditions::handle_destroy(param_1,unaff_EBX);
    return;
  case '\x03':
    RGE_Victory_Conditions::handle_destroy_multiple(param_1,unaff_EBX);
    return;
  case '\x04':
    RGE_Victory_Conditions::handle_bring_area(param_1,unaff_EBX);
    return;
  case '\x05':
    RGE_Victory_Conditions::handle_bring_object(param_1,unaff_EBX);
    return;
  case '\x06':
    RGE_Victory_Conditions::handle_attribute(param_1,unaff_EBX);
    return;
  case '\a':
    RGE_Victory_Conditions::handle_explore(param_1,unaff_EBX);
    return;
  case '\b':
    RGE_Victory_Conditions::handle_create_in_area(param_1,unaff_EBX);
    return;
  case '\t':
    RGE_Victory_Conditions::handle_destroy_all(param_1,unaff_EBX);
    return;
  case '\n':
    RGE_Victory_Conditions::handle_destroy_player(param_1,unaff_EBX);
    return;
  case '\f':
    RGE_Victory_Conditions::handle_victory_points(param_1,unaff_EBX);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00532e9f
// Address: 00532e9f
// XREFS: None
void FUN_00532e9f(void)
{
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_00536912
// Address: 00536912
// XREFS: None
char FUN_00536912(void)
{
  uchar uVar1;
  RGE_Visible_Map *this;
  RGE_Tile *pRVar2;
  float fVar3;
  RGE_Map *pRVar4;
  byte bVar5;
  short sVar6;
  RGE_Map *pRVar7;
  undefined4 extraout_ECX;
  RGE_Map *extraout_ECX_00;
  RGE_Map *extraout_ECX_01;
  RGE_Map *extraout_ECX_02;
  RGE_Map *extraout_ECX_03;
  RGE_Map *extraout_ECX_04;
  RGE_Map *extraout_ECX_05;
  short sVar8;
  short sVar9;
  byte bVar10;
  bool bVar11;
  RGE_Tile *pRVar12;
  RGE_View *unaff_ESI;
  int iVar13;
  uchar uStack00000013;
  short sStack00000014;
  short sStack00000018;
  short sStack0000001c;
  short sStack00000020;
  undefined2 uStack00000022;
  short in_stack_00000024;
  short sStack00000028;
  char in_stack_0000002c;
  uchar uStack00000030;
  RGE_Map *in_stack_00000038;
  RGE_Map *in_stack_0000003c;
  char in_stack_00000040;
  RGE_Map *in_stack_00000048;
  uint uStack0000004c;
  uint uStack00000050;
  int iStack00000054;
  short in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  RGE_Map *in_stack_0000006c;
  short in_stack_00000070;
  short in_stack_00000074;
  short in_stack_00000078;
  short in_stack_0000007c;
  tagPOINT *in_stack_00000094;
  tagPOINT *in_stack_00000098;
  undefined4 *in_stack_0000009c;
  float *in_stack_000000a0;
  float *in_stack_000000a4;
  short *in_stack_000000a8;
  short *in_stack_000000ac;
  
code_r0x00536912:
  _sStack00000020 = CONCAT22(uStack00000022,sStack00000020 - unaff_ESI->tile_half_wid);
  _sStack00000028 = _sStack00000028 + 1;
  in_stack_00000038 = (RGE_Map *)((int)&in_stack_00000038[-1].unit_manager + 3);
  goto switchD_0053690b_default;
  do {
    switch(in_stack_00000040) {
    case '\x01':
      goto code_r0x00536912;
    case '\x02':
      _sStack00000028 = _sStack00000028 + -1;
      _sStack00000020 =
           _sStack00000020 +
           CONCAT22((short)((uint)_sStack00000028 >> 0x10),unaff_ESI->tile_half_wid);
      in_stack_0000003c = (RGE_Map *)((int)&in_stack_0000003c->_padding_ + 1);
    default:
switchD_0053690b_default:
      in_stack_00000024 = in_stack_00000024 + unaff_ESI->tile_half_hgt;
      in_stack_00000058 = in_stack_00000058 + 1;
      if (in_stack_0000007c <= in_stack_00000058) {
        if (unaff_ESI->function_mode == '\n') {
          pRVar7 = unaff_ESI->map;
          sVar9 = 0;
          if (0 < pRVar7->num_terrain) {
            do {
              iVar13 = (int)sVar9;
              sVar9 = sVar9 + 1;
              pRVar7->terrain_types[iVar13].frame_changed = '\0';
              pRVar7 = unaff_ESI->map;
            } while (sVar9 < pRVar7->num_terrain);
          }
        }
        uVar1 = unaff_ESI->function_mode;
        if ((((uVar1 == ')') || (uVar1 == '*')) || (uVar1 == '+')) && (in_stack_0000002c == '4')) {
          *in_stack_0000009c = in_stack_00000048;
        }
        return in_stack_0000002c;
      }
      _sStack00000014 = _sStack00000020;
      _sStack0000001c = in_stack_00000038;
      _sStack00000018 = in_stack_0000003c;
      iStack00000054 = 0;
      pRVar7 = in_stack_0000003c;
      if (0 < sStack00000028) {
        do {
          sVar8 = (short)_sStack0000001c;
          sVar9 = (short)_sStack00000018;
          if (((sVar8 < 0) || (pRVar7 = unaff_ESI->map, (int)pRVar7->map_width <= (int)sVar8)) ||
             ((sVar9 < 0 || ((int)pRVar7->map_height <= (int)sVar9)))) {
            uVar1 = unaff_ESI->function_mode;
            pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)pRVar7 >> 8),uVar1);
            bVar11 = false;
            if ((uVar1 == '(') || (uVar1 == '*')) goto LAB_00536221;
          }
          else {
            bVar11 = true;
LAB_00536221:
            if (bVar11) {
              this = unaff_ESI->player->visible;
              if ((this == (RGE_Visible_Map *)0x0) || (unaff_ESI->map->map_visible_flag != '\0')) {
                uStack00000013 = RGE_Visible_Map::get_visible(this,(int)sVar8,(int)sVar9);
                pRVar7 = extraout_ECX_00;
                if (uStack00000013 == '\0') {
                  uStack00000013 = 0x80;
                }
              }
              else {
                uStack00000013 = RGE_Visible_Map::get_visible(this,(int)sVar8,(int)sVar9);
                uVar1 = unaff_ESI->function_mode;
                pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)extraout_ECX >> 8),uVar1);
                if ((uVar1 == '\x1e') || (uVar1 == '\x1f')) {
                  uStack00000013 = '\x0f';
                }
              }
              if ((unaff_ESI->function_mode == '\v') &&
                 (pRVar12 = unaff_ESI->map->map_row_offset[sVar9],
                 pRVar7 = (RGE_Map *)(pRVar12 + sVar8),
                 pRVar12[sVar8].draw_as == *(uchar *)((int)&pRVar7->map + 3))) goto LAB_005362af;
            }
            else {
LAB_005362af:
              uStack00000013 = '\0';
            }
            if ((uStack00000013 != '\x0f') && (uStack00000013 != 0x80)) {
              uStack00000013 = '\0';
            }
            if (uStack00000013 == '\0') {
              uVar1 = unaff_ESI->function_mode;
              if ((((uVar1 != '\x0e') && (uVar1 != '(')) && (uVar1 != '<')) &&
                 (pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)pRVar7 >> 8),uVar1), uVar1 != '*'))
              goto LAB_005368a9;
            }
            if (bVar11) {
              pRVar2 = unaff_ESI->map->map_row_offset[sStack00000018];
              pRVar12 = pRVar2 + sStack0000001c;
              uStack00000050 = (uint)pRVar2[sStack0000001c].tile_type;
              bVar5 = (byte)pRVar12->field_0x5 >> 5;
            }
            else {
              uStack00000050 = 0;
              bVar5 = 0;
              pRVar12 = (RGE_Tile *)0x0;
            }
            sVar9 = in_stack_00000024 - (ushort)bVar5 * unaff_ESI->elev_hgt;
            switch(uStack00000050) {
            case 2:
            case 6:
            case 8:
            case 10:
            case 0xe:
            case 0xf:
            case 0x10:
              sVar9 = sVar9 - unaff_ESI->elev_hgt;
            }
            if ((((unaff_ESI->_padding_ < (int)sStack00000014) ||
                 (unaff_ESI->_padding_ < (int)sVar9)) ||
                (((int)unaff_ESI->map->tilesizes[uStack00000050].width + (int)sStack00000014 <=
                  unaff_ESI->_padding_ ||
                 (uStack00000050 =
                       (int)unaff_ESI->map->tilesizes[uStack00000050].height + (int)sVar9,
                 (int)uStack00000050 <= unaff_ESI->_padding_)))) ||
               ((unaff_ESI->function_mode == '\x0e' &&
                (((sStack0000001c < in_stack_0000005c || (in_stack_00000060 < sStack0000001c)) ||
                 ((sStack00000018 < in_stack_00000064 || (in_stack_00000068 < sStack00000018))))))))
{
              bVar11 = true;
            }
            else {
              bVar11 = false;
            }
            uVar1 = unaff_ESI->function_mode;
            pRVar7 = (RGE_Map *)CONCAT31((int3)(uStack00000050 >> 8),uVar1);
            if ((((uVar1 == '\n') || (uVar1 == '\x1e')) || (uVar1 == '\x1f')) ||
               (((uVar1 == ' ' || (uVar1 == '\x15')) || ((uVar1 == '\v' || (uVar1 == '\x0e')))))) {
              if ((!bVar11) &&
                 (((uVar1 = unaff_ESI->function_mode, uVar1 == '\n' || (uVar1 == '\v')) ||
                  (uVar1 == '\x0e')))) {
                bVar5 = pRVar12->field_0x5;
                pRVar7 = unaff_ESI->map;
                bVar10 = bVar5 & 0x1f;
                uStack0000004c = bVar5 & 0xffffff1f;
                sVar9 = pRVar7->terrain_types[bVar5 & 0x1f].terrain_to_draw;
                if (sVar9 != -1) {
                  bVar10 = (byte)sVar9;
                  uStack0000004c = (uint)bVar10;
                }
                if (((unaff_ESI->function_mode == '\n') && (unaff_ESI->calc_draw_count != 0)) &&
                   ((short)(ushort)bVar10 < pRVar7->num_terrain)) {
                  pRVar7->terrain_types[uStack0000004c].drawn =
                       pRVar7->terrain_types[uStack0000004c].drawn + '\x01';
                }
                pRVar7 = (RGE_Map *)0x0;
                if (unaff_ESI->function_mode == '\v') {
                  pRVar12->last_drawn_as = pRVar12->draw_as;
                }
              }
              if (((uStack00000013 == '\x0f') || (uStack00000013 == 0x80)) &&
                 (((uVar1 = unaff_ESI->function_mode, uVar1 == '\x1e' ||
                   ((uVar1 == '\x1f' || (uVar1 == ' ')))) || (uVar1 == '\x15')))) {
                pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)pRVar7 >> 8),uStack00000013);
                if ((uStack00000013 == '\x0f') ||
                   ((uStack00000013 == 0x80 && (pRVar7 = unaff_ESI->map, pRVar7->fog_flag == '\0')))
                   ) {
                  uStack00000030 = '\0';
                }
                else {
                  uStack00000030 = '\x01';
                }
                if (uVar1 == '\x1e') {
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Fog_Clip_Mask;
                  fog_next_shape = 1;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,sStack00000014,
                             in_stack_00000024,'\x01',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Clip_Mask;
                  fog_next_shape = 0;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\x01',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->cur_render_area->SpanList;
                  pRVar7 = extraout_ECX_03;
                }
                if (unaff_ESI->function_mode == '\x1f') {
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Fog_Clip_Mask;
                  fog_next_shape = 1;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\n',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Clip_Mask;
                  fog_next_shape = 0;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\n',uStack00000030);
                  pRVar7 = (RGE_Map *)unaff_ESI->cur_render_area->SpanList;
                  unaff_ESI->cur_render_area->CurSpanList = (TSpan_List_Manager *)pRVar7;
                }
                if (unaff_ESI->function_mode == ' ') {
                  if ((unaff_ESI->map->fog_flag != '\0') && (uStack00000013 == 0x80)) {
                    fog_next_shape = 1;
                  }
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\0',uStack00000030);
                  pRVar7 = extraout_ECX_04;
                }
                else {
                  if (unaff_ESI->function_mode != '\x15') goto LAB_005368a9;
                  if ((unaff_ESI->map->fog_flag != '\0') && (uStack00000013 == 0x80)) {
                    fog_next_shape = 1;
                  }
                  RGE_Object_List::normal_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,uStack00000030);
                  pRVar7 = extraout_ECX_05;
                }
                fog_next_shape = 0;
              }
            }
            else {
              if (((uStack00000013 == '\x0f') || (uStack00000013 == 0x80)) &&
                 ((uVar1 == ')' || (((uVar1 == '*' || (uVar1 == '+')) || (uVar1 == ',')))))) {
                if ((uStack00000013 == '\x0f') ||
                   ((uStack00000013 == 0x80 && (unaff_ESI->map->fog_flag == '\0')))) {
                  uStack00000030 = '\0';
                }
                else {
                  uStack00000030 = '\x01';
                }
                pRVar4 = (RGE_Map *)
                         RGE_View::hit_object
                                   (unaff_ESI,pRVar12,sStack00000014,in_stack_00000024,
                                    sStack0000001c,sStack00000018,in_stack_00000094,
                                    in_stack_00000098,in_stack_000000a8,in_stack_000000ac,
                                    (RGE_Static_Object *)in_stack_0000006c,uStack00000030);
                pRVar7 = extraout_ECX_01;
                if (pRVar4 != (RGE_Map *)0x0) {
                  if (unaff_ESI->function_mode == ',') {
                    in_stack_0000002c = '4';
                    pRVar7 = extraout_ECX_01;
                  }
                  else {
                    if (((in_stack_0000006c != (RGE_Map *)0x0) && (pRVar4 == in_stack_0000006c)) &&
                       (in_stack_0000002c == '4')) {
                      *in_stack_0000009c = in_stack_00000048;
                      return '4';
                    }
                    if (((in_stack_00000048 == (RGE_Map *)0x0) ||
                        (((RGE_Master_Static_Object *)in_stack_00000048->map_width)->select_level <=
                         ((RGE_Master_Static_Object *)pRVar4->map_width)->select_level)) ||
                       ((pRVar7 = in_stack_00000048, in_stack_00000048 == in_stack_0000006c &&
                        (pRVar4 != in_stack_0000006c)))) {
                      pRVar7 = *(RGE_Map **)&pRVar4->tilesizes[5].height;
                      *in_stack_000000a0 = (float)pRVar7;
                      *in_stack_000000a4 = *(float *)(pRVar4->tilesizes + 6);
                      in_stack_0000002c = '4';
                      in_stack_00000048 = pRVar4;
                    }
                  }
                }
              }
              uVar1 = unaff_ESI->function_mode;
              sVar6 = (short)_sStack0000001c;
              sVar8 = (short)_sStack00000018;
              if ((uVar1 == '(') || ((uVar1 == '*' && (in_stack_0000002c == '2')))) {
                iVar13 = RGE_View::hit_tile(unaff_ESI,pRVar12,sStack00000014,sVar9,sVar6,sVar8,
                                            in_stack_00000094);
                pRVar7 = extraout_ECX_02;
                if (iVar13 != 0) {
                  if (pRVar12 == (RGE_Tile *)0x0) {
                    iVar13 = (int)sStack00000018;
                    *in_stack_000000a0 = (float)(int)sStack0000001c;
                    fVar3 = (float)iVar13;
                  }
                  else {
                    RGE_Map::tile_map_coords
                              (unaff_ESI->map,(short)in_stack_00000094->x - sStack00000014,
                               (short)in_stack_00000094->y - sVar9,pRVar12,in_stack_000000a0,
                               in_stack_000000a4);
                    iVar13 = (int)sStack0000001c;
                    *in_stack_000000a0 = (float)iVar13 + *in_stack_000000a0;
                    fVar3 = (float)(int)sStack00000018 + *in_stack_000000a4;
                  }
                  *in_stack_000000a4 = fVar3;
                  *in_stack_000000a8 = sStack00000014;
                  in_stack_0000002c = '3';
                  *in_stack_000000ac = sVar9;
                  *in_stack_0000009c = pRVar12;
                  pRVar7 = (RGE_Map *)CONCAT22((short)((uint)iVar13 >> 0x10),sVar9);
                }
              }
              else if (((uVar1 == '<') && (pRVar7 = _sStack0000001c, sVar6 == in_stack_00000070)) &&
                      (sVar8 == in_stack_00000074)) {
                *in_stack_000000a0 = (float)(int)sVar6;
                *in_stack_000000a4 = (float)(int)sVar8;
                *in_stack_000000a8 = sStack00000014;
                *in_stack_000000ac = sVar9;
                *in_stack_0000009c = pRVar12;
                return '3';
              }
            }
          }
LAB_005368a9:
          pRVar7 = (RGE_Map *)CONCAT22((short)((uint)pRVar7 >> 0x10),unaff_ESI->tile_wid);
          _sStack00000014 = (int)&((RGE_Map *)(pRVar7->tilesizes + -4))->_padding_ + _sStack00000014
          ;
          _sStack0000001c = (RGE_Map *)((int)&_sStack0000001c->_padding_ + 1);
          _sStack00000018 = (RGE_Map *)((int)&_sStack00000018->_padding_ + 1);
          iStack00000054 = iStack00000054 + 1;
        } while ((short)iStack00000054 < sStack00000028);
      }
      if ((in_stack_00000040 == '\x01') && (sStack00000028 == in_stack_00000078)) {
        in_stack_00000040 = '\x02';
      }
      break;
    case '\x03':
      in_stack_00000040 = '\x04';
      _sStack00000020 = CONCAT22(uStack00000022,sStack00000020 - unaff_ESI->tile_half_wid);
      in_stack_00000038 = (RGE_Map *)((int)&in_stack_00000038[-1].unit_manager + 3);
      break;
    case '\x04':
      _sStack00000020 =
           _sStack00000020 + CONCAT22((short)((uint)pRVar7 >> 0x10),unaff_ESI->tile_half_wid);
      in_stack_0000003c = (RGE_Map *)((int)&in_stack_0000003c->_padding_ + 1);
      in_stack_00000040 = '\x03';
      break;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00536957
// Address: 00536957
// XREFS: None
char FUN_00536957(void)
{
  uchar uVar1;
  RGE_Visible_Map *this;
  RGE_Tile *pRVar2;
  float fVar3;
  char cVar4;
  RGE_Map *pRVar5;
  byte bVar6;
  short sVar7;
  RGE_Map *pRVar8;
  undefined4 extraout_ECX;
  RGE_Map *extraout_ECX_00;
  RGE_Map *extraout_ECX_01;
  RGE_Map *extraout_ECX_02;
  RGE_Map *extraout_ECX_03;
  RGE_Map *extraout_ECX_04;
  RGE_Map *extraout_ECX_05;
  short sVar9;
  short sVar10;
  byte bVar11;
  bool bVar12;
  RGE_Tile *pRVar13;
  RGE_View *unaff_ESI;
  int iVar14;
  uchar uStack00000013;
  short sStack00000014;
  short sStack00000018;
  short sStack0000001c;
  short sStack00000020;
  undefined2 uStack00000022;
  short in_stack_00000024;
  short sStack00000028;
  char in_stack_0000002c;
  uchar uStack00000030;
  RGE_Map *in_stack_00000038;
  RGE_Map *in_stack_0000003c;
  RGE_Map *in_stack_00000048;
  uint uStack0000004c;
  uint uStack00000050;
  int iStack00000054;
  short in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  RGE_Map *in_stack_0000006c;
  short in_stack_00000070;
  short in_stack_00000074;
  short in_stack_00000078;
  short in_stack_0000007c;
  tagPOINT *in_stack_00000094;
  tagPOINT *in_stack_00000098;
  undefined4 *in_stack_0000009c;
  float *in_stack_000000a0;
  float *in_stack_000000a4;
  short *in_stack_000000a8;
  short *in_stack_000000ac;
  
code_r0x00536957:
  cVar4 = '\x04';
  _sStack00000020 = CONCAT22(uStack00000022,sStack00000020 - unaff_ESI->tile_half_wid);
  in_stack_00000038 = (RGE_Map *)((int)&in_stack_00000038[-1].unit_manager + 3);
  goto switchD_0053690b_default;
  do {
    switch(cVar4) {
    case '\x01':
      _sStack00000020 = CONCAT22(uStack00000022,sStack00000020 - unaff_ESI->tile_half_wid);
      _sStack00000028 = _sStack00000028 + 1;
      in_stack_00000038 = (RGE_Map *)((int)&in_stack_00000038[-1].unit_manager + 3);
    default:
switchD_0053690b_default:
      in_stack_00000024 = in_stack_00000024 + unaff_ESI->tile_half_hgt;
      in_stack_00000058 = in_stack_00000058 + 1;
      if (in_stack_0000007c <= in_stack_00000058) {
        if (unaff_ESI->function_mode == '\n') {
          pRVar8 = unaff_ESI->map;
          sVar10 = 0;
          if (0 < pRVar8->num_terrain) {
            do {
              iVar14 = (int)sVar10;
              sVar10 = sVar10 + 1;
              pRVar8->terrain_types[iVar14].frame_changed = '\0';
              pRVar8 = unaff_ESI->map;
            } while (sVar10 < pRVar8->num_terrain);
          }
        }
        uVar1 = unaff_ESI->function_mode;
        if ((((uVar1 == ')') || (uVar1 == '*')) || (uVar1 == '+')) && (in_stack_0000002c == '4')) {
          *in_stack_0000009c = in_stack_00000048;
        }
        return in_stack_0000002c;
      }
      _sStack00000014 = _sStack00000020;
      _sStack0000001c = in_stack_00000038;
      _sStack00000018 = in_stack_0000003c;
      iStack00000054 = 0;
      pRVar8 = in_stack_0000003c;
      if (0 < sStack00000028) {
        do {
          sVar9 = (short)_sStack0000001c;
          sVar10 = (short)_sStack00000018;
          if (((sVar9 < 0) || (pRVar8 = unaff_ESI->map, (int)pRVar8->map_width <= (int)sVar9)) ||
             ((sVar10 < 0 || ((int)pRVar8->map_height <= (int)sVar10)))) {
            uVar1 = unaff_ESI->function_mode;
            pRVar8 = (RGE_Map *)CONCAT31((int3)((uint)pRVar8 >> 8),uVar1);
            bVar12 = false;
            if ((uVar1 == '(') || (uVar1 == '*')) goto LAB_00536221;
          }
          else {
            bVar12 = true;
LAB_00536221:
            if (bVar12) {
              this = unaff_ESI->player->visible;
              if ((this == (RGE_Visible_Map *)0x0) || (unaff_ESI->map->map_visible_flag != '\0')) {
                uStack00000013 = RGE_Visible_Map::get_visible(this,(int)sVar9,(int)sVar10);
                pRVar8 = extraout_ECX_00;
                if (uStack00000013 == '\0') {
                  uStack00000013 = 0x80;
                }
              }
              else {
                uStack00000013 = RGE_Visible_Map::get_visible(this,(int)sVar9,(int)sVar10);
                uVar1 = unaff_ESI->function_mode;
                pRVar8 = (RGE_Map *)CONCAT31((int3)((uint)extraout_ECX >> 8),uVar1);
                if ((uVar1 == '\x1e') || (uVar1 == '\x1f')) {
                  uStack00000013 = '\x0f';
                }
              }
              if ((unaff_ESI->function_mode == '\v') &&
                 (pRVar13 = unaff_ESI->map->map_row_offset[sVar10],
                 pRVar8 = (RGE_Map *)(pRVar13 + sVar9),
                 pRVar13[sVar9].draw_as == *(uchar *)((int)&pRVar8->map + 3))) goto LAB_005362af;
            }
            else {
LAB_005362af:
              uStack00000013 = '\0';
            }
            if ((uStack00000013 != '\x0f') && (uStack00000013 != 0x80)) {
              uStack00000013 = '\0';
            }
            if (uStack00000013 == '\0') {
              uVar1 = unaff_ESI->function_mode;
              if ((((uVar1 != '\x0e') && (uVar1 != '(')) && (uVar1 != '<')) &&
                 (pRVar8 = (RGE_Map *)CONCAT31((int3)((uint)pRVar8 >> 8),uVar1), uVar1 != '*'))
              goto LAB_005368a9;
            }
            if (bVar12) {
              pRVar2 = unaff_ESI->map->map_row_offset[sStack00000018];
              pRVar13 = pRVar2 + sStack0000001c;
              uStack00000050 = (uint)pRVar2[sStack0000001c].tile_type;
              bVar6 = (byte)pRVar13->field_0x5 >> 5;
            }
            else {
              uStack00000050 = 0;
              bVar6 = 0;
              pRVar13 = (RGE_Tile *)0x0;
            }
            sVar10 = in_stack_00000024 - (ushort)bVar6 * unaff_ESI->elev_hgt;
            switch(uStack00000050) {
            case 2:
            case 6:
            case 8:
            case 10:
            case 0xe:
            case 0xf:
            case 0x10:
              sVar10 = sVar10 - unaff_ESI->elev_hgt;
            }
            if ((((unaff_ESI->_padding_ < (int)sStack00000014) ||
                 (unaff_ESI->_padding_ < (int)sVar10)) ||
                (((int)unaff_ESI->map->tilesizes[uStack00000050].width + (int)sStack00000014 <=
                  unaff_ESI->_padding_ ||
                 (uStack00000050 =
                       (int)unaff_ESI->map->tilesizes[uStack00000050].height + (int)sVar10,
                 (int)uStack00000050 <= unaff_ESI->_padding_)))) ||
               ((unaff_ESI->function_mode == '\x0e' &&
                (((sStack0000001c < in_stack_0000005c || (in_stack_00000060 < sStack0000001c)) ||
                 ((sStack00000018 < in_stack_00000064 || (in_stack_00000068 < sStack00000018))))))))
{
              bVar12 = true;
            }
            else {
              bVar12 = false;
            }
            uVar1 = unaff_ESI->function_mode;
            pRVar8 = (RGE_Map *)CONCAT31((int3)(uStack00000050 >> 8),uVar1);
            if ((((uVar1 == '\n') || (uVar1 == '\x1e')) || (uVar1 == '\x1f')) ||
               (((uVar1 == ' ' || (uVar1 == '\x15')) || ((uVar1 == '\v' || (uVar1 == '\x0e')))))) {
              if ((!bVar12) &&
                 (((uVar1 = unaff_ESI->function_mode, uVar1 == '\n' || (uVar1 == '\v')) ||
                  (uVar1 == '\x0e')))) {
                bVar6 = pRVar13->field_0x5;
                pRVar8 = unaff_ESI->map;
                bVar11 = bVar6 & 0x1f;
                uStack0000004c = bVar6 & 0xffffff1f;
                sVar10 = pRVar8->terrain_types[bVar6 & 0x1f].terrain_to_draw;
                if (sVar10 != -1) {
                  bVar11 = (byte)sVar10;
                  uStack0000004c = (uint)bVar11;
                }
                if (((unaff_ESI->function_mode == '\n') && (unaff_ESI->calc_draw_count != 0)) &&
                   ((short)(ushort)bVar11 < pRVar8->num_terrain)) {
                  pRVar8->terrain_types[uStack0000004c].drawn =
                       pRVar8->terrain_types[uStack0000004c].drawn + '\x01';
                }
                pRVar8 = (RGE_Map *)0x0;
                if (unaff_ESI->function_mode == '\v') {
                  pRVar13->last_drawn_as = pRVar13->draw_as;
                }
              }
              if (((uStack00000013 == '\x0f') || (uStack00000013 == 0x80)) &&
                 (((uVar1 = unaff_ESI->function_mode, uVar1 == '\x1e' ||
                   ((uVar1 == '\x1f' || (uVar1 == ' ')))) || (uVar1 == '\x15')))) {
                pRVar8 = (RGE_Map *)CONCAT31((int3)((uint)pRVar8 >> 8),uStack00000013);
                if ((uStack00000013 == '\x0f') ||
                   ((uStack00000013 == 0x80 && (pRVar8 = unaff_ESI->map, pRVar8->fog_flag == '\0')))
                   ) {
                  uStack00000030 = '\0';
                }
                else {
                  uStack00000030 = '\x01';
                }
                if (uVar1 == '\x1e') {
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Fog_Clip_Mask;
                  fog_next_shape = 1;
                  RGE_Object_List::shadow_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,sStack00000014,
                             in_stack_00000024,'\x01',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Clip_Mask;
                  fog_next_shape = 0;
                  RGE_Object_List::shadow_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\x01',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->cur_render_area->SpanList;
                  pRVar8 = extraout_ECX_03;
                }
                if (unaff_ESI->function_mode == '\x1f') {
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Fog_Clip_Mask;
                  fog_next_shape = 1;
                  RGE_Object_List::shadow_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\n',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Clip_Mask;
                  fog_next_shape = 0;
                  RGE_Object_List::shadow_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\n',uStack00000030);
                  pRVar8 = (RGE_Map *)unaff_ESI->cur_render_area->SpanList;
                  unaff_ESI->cur_render_area->CurSpanList = (TSpan_List_Manager *)pRVar8;
                }
                if (unaff_ESI->function_mode == ' ') {
                  if ((unaff_ESI->map->fog_flag != '\0') && (uStack00000013 == 0x80)) {
                    fog_next_shape = 1;
                  }
                  RGE_Object_List::shadow_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\0',uStack00000030);
                  pRVar8 = extraout_ECX_04;
                }
                else {
                  if (unaff_ESI->function_mode != '\x15') goto LAB_005368a9;
                  if ((unaff_ESI->map->fog_flag != '\0') && (uStack00000013 == 0x80)) {
                    fog_next_shape = 1;
                  }
                  RGE_Object_List::normal_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,uStack00000030);
                  pRVar8 = extraout_ECX_05;
                }
                fog_next_shape = 0;
              }
            }
            else {
              if (((uStack00000013 == '\x0f') || (uStack00000013 == 0x80)) &&
                 ((uVar1 == ')' || (((uVar1 == '*' || (uVar1 == '+')) || (uVar1 == ',')))))) {
                if ((uStack00000013 == '\x0f') ||
                   ((uStack00000013 == 0x80 && (unaff_ESI->map->fog_flag == '\0')))) {
                  uStack00000030 = '\0';
                }
                else {
                  uStack00000030 = '\x01';
                }
                pRVar5 = (RGE_Map *)
                         RGE_View::hit_object
                                   (unaff_ESI,pRVar13,sStack00000014,in_stack_00000024,
                                    sStack0000001c,sStack00000018,in_stack_00000094,
                                    in_stack_00000098,in_stack_000000a8,in_stack_000000ac,
                                    (RGE_Static_Object *)in_stack_0000006c,uStack00000030);
                pRVar8 = extraout_ECX_01;
                if (pRVar5 != (RGE_Map *)0x0) {
                  if (unaff_ESI->function_mode == ',') {
                    in_stack_0000002c = '4';
                    pRVar8 = extraout_ECX_01;
                  }
                  else {
                    if (((in_stack_0000006c != (RGE_Map *)0x0) && (pRVar5 == in_stack_0000006c)) &&
                       (in_stack_0000002c == '4')) {
                      *in_stack_0000009c = in_stack_00000048;
                      return '4';
                    }
                    if (((in_stack_00000048 == (RGE_Map *)0x0) ||
                        (((RGE_Master_Static_Object *)in_stack_00000048->map_width)->select_level <=
                         ((RGE_Master_Static_Object *)pRVar5->map_width)->select_level)) ||
                       ((pRVar8 = in_stack_00000048, in_stack_00000048 == in_stack_0000006c &&
                        (pRVar5 != in_stack_0000006c)))) {
                      pRVar8 = *(RGE_Map **)&pRVar5->tilesizes[5].height;
                      *in_stack_000000a0 = (float)pRVar8;
                      *in_stack_000000a4 = *(float *)(pRVar5->tilesizes + 6);
                      in_stack_0000002c = '4';
                      in_stack_00000048 = pRVar5;
                    }
                  }
                }
              }
              uVar1 = unaff_ESI->function_mode;
              sVar7 = (short)_sStack0000001c;
              sVar9 = (short)_sStack00000018;
              if ((uVar1 == '(') || ((uVar1 == '*' && (in_stack_0000002c == '2')))) {
                iVar14 = RGE_View::hit_tile(unaff_ESI,pRVar13,sStack00000014,sVar10,sVar7,sVar9,
                                            in_stack_00000094);
                pRVar8 = extraout_ECX_02;
                if (iVar14 != 0) {
                  if (pRVar13 == (RGE_Tile *)0x0) {
                    iVar14 = (int)sStack00000018;
                    *in_stack_000000a0 = (float)(int)sStack0000001c;
                    fVar3 = (float)iVar14;
                  }
                  else {
                    RGE_Map::tile_map_coords
                              (unaff_ESI->map,(short)in_stack_00000094->x - sStack00000014,
                               (short)in_stack_00000094->y - sVar10,pRVar13,in_stack_000000a0,
                               in_stack_000000a4);
                    iVar14 = (int)sStack0000001c;
                    *in_stack_000000a0 = (float)iVar14 + *in_stack_000000a0;
                    fVar3 = (float)(int)sStack00000018 + *in_stack_000000a4;
                  }
                  *in_stack_000000a4 = fVar3;
                  *in_stack_000000a8 = sStack00000014;
                  in_stack_0000002c = '3';
                  *in_stack_000000ac = sVar10;
                  *in_stack_0000009c = pRVar13;
                  pRVar8 = (RGE_Map *)CONCAT22((short)((uint)iVar14 >> 0x10),sVar10);
                }
              }
              else if (((uVar1 == '<') && (pRVar8 = _sStack0000001c, sVar7 == in_stack_00000070)) &&
                      (sVar9 == in_stack_00000074)) {
                *in_stack_000000a0 = (float)(int)sVar7;
                *in_stack_000000a4 = (float)(int)sVar9;
                *in_stack_000000a8 = sStack00000014;
                *in_stack_000000ac = sVar10;
                *in_stack_0000009c = pRVar13;
                return '3';
              }
            }
          }
LAB_005368a9:
          pRVar8 = (RGE_Map *)CONCAT22((short)((uint)pRVar8 >> 0x10),unaff_ESI->tile_wid);
          _sStack00000014 = (int)&((RGE_Map *)(pRVar8->tilesizes + -4))->_padding_ + _sStack00000014
          ;
          _sStack0000001c = (RGE_Map *)((int)&_sStack0000001c->_padding_ + 1);
          _sStack00000018 = (RGE_Map *)((int)&_sStack00000018->_padding_ + 1);
          iStack00000054 = iStack00000054 + 1;
        } while ((short)iStack00000054 < sStack00000028);
      }
      if ((cVar4 == '\x01') && (sStack00000028 == in_stack_00000078)) {
        cVar4 = '\x02';
      }
      break;
    case '\x02':
      _sStack00000028 = _sStack00000028 + -1;
      _sStack00000020 =
           _sStack00000020 +
           CONCAT22((short)((uint)_sStack00000028 >> 0x10),unaff_ESI->tile_half_wid);
      in_stack_0000003c = (RGE_Map *)((int)&in_stack_0000003c->_padding_ + 1);
      break;
    case '\x03':
      goto code_r0x00536957;
    case '\x04':
      _sStack00000020 =
           _sStack00000020 + CONCAT22((short)((uint)pRVar8 >> 0x10),unaff_ESI->tile_half_wid);
      in_stack_0000003c = (RGE_Map *)((int)&in_stack_0000003c->_padding_ + 1);
      cVar4 = '\x03';
      break;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00536b03
// Address: 00536b03
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_view_cpp: "C:\msdev\work\age1_x1\view.cpp"
// [HELPER] s_view__view_function_terrain: "view::view_function_terrain"
undefined4 __fastcall FUN_00536b03(int param_1,char *param_2)
{
  byte *pbVar1;
  RGE_Tile *pRVar2;
  undefined1 uVar3;
  short sVar4;
  Tile_FogEdge_Table *pTVar5;
  uint uVar6;
  Ov_Sprite_Draw_Rec *pOVar7;
  Ov_Sprite_Draw_Rec *pOVar8;
  TSpan_List_Manager *pTVar9;
  undefined4 *puVar10;
  TMessagePanel *this;
  int *piVar11;
  int *piVar12;
  Shape_Info *pSVar13;
  longlong lVar14;
  char cVar15;
  char cVar16;
  byte bVar17;
  undefined4 in_EAX;
  undefined3 uVar25;
  RGE_Map *pRVar19;
  long lVar20;
  ulong uVar21;
  DClipInfo_Node *pDVar22;
  TDrawArea *pTVar23;
  DClipInfo_List *pDVar24;
  uchar uVar26;
  RGE_View *this_00;
  int iVar27;
  ushort uVar28;
  int iVar29;
  DClipInfo_Node *pDVar30;
  RGE_Visible_Map *unaff_EBX;
  RGE_View *unaff_EBP;
  uint uVar31;
  Shape_Info **ppSVar32;
  undefined1 *unaff_EDI;
  int iVar33;
  Shape_Info **ppSVar34;
  byte in_CF;
  bool bVar35;
  char cStack00000013;
  int iStack00000014;
  int iStack00000018;
  int iStack00000020;
  RGE_Visible_Map *in_stack_00000028;
  int in_stack_0000002c;
  uchar uStack00000030;
  uint in_stack_00000034;
  uchar uStack00000038;
  VSpanMiniList *in_stack_0000003c;
  uint in_stack_00000040;
  int in_stack_00000044;
  long in_stack_00000048;
  int in_stack_0000004c;
  long in_stack_00000050;
  Tile_BlackEdge_Table *in_stack_00000054;
  int in_stack_00000058;
  RGE_Visible_Map *in_stack_0000005c;
  ulong in_stack_00000060;
  VSpanMiniList *in_stack_00000064;
  int in_stack_00000068;
  int in_stack_0000006c;
  VSpanMiniList *in_stack_00000070;
  int in_stack_00000074;
  ulong in_stack_00000078;
  uint in_stack_0000007c;
  int in_stack_00000080;
  int in_stack_00000084;
  int in_stack_00000088;
  int in_stack_0000008c;
  int in_stack_00000090;
  int in_stack_00000094;
  int in_stack_00000098;
  int in_stack_0000009c;
  uchar in_stack_00000124;
  int in_stack_00000128;
  int in_stack_0000012c;
  short sVar36;
  short sVar37;
  char *pcVar18;
  
  uVar28 = (ushort)param_2;
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  uVar3 = in(uVar28);
  *unaff_EDI = uVar3;
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  cRam05010505 = cRam05010505 + (char)in_EAX;
  uVar25 = (undefined3)((uint)in_EAX >> 8);
  cVar15 = (char)in_EAX + cRam05050503;
  cVar16 = cVar15 + -0x6c;
  pcVar18 = (char *)CONCAT31(uVar25,cVar16);
  this_00 = (RGE_View *)
            CONCAT22((short)((uint)param_1 >> 0x10),
                     CONCAT11((char)((uint)param_1 >> 8) + *(char *)(param_1 + 0x53) +
                              (0x6f < (byte)(cVar15 + 4U)),(char)param_1));
  *param_2 = *param_2 + (char)((uint)param_2 >> 8);
  lVar14 = (longlong)(int)unaff_EBX->map_offsets * 0x536957;
  if ((int)lVar14 == lVar14) {
    *(char *)&this_00[-0x2378d9]._padding_ = (char)this_00[-0x2378d9]._padding_ + (char)param_1;
    *pcVar18 = *pcVar18 + cVar16;
  }
  else {
    pbVar1 = (byte *)(pcVar18 + -0x7e6f6f70);
    bVar17 = *pbVar1;
    *pbVar1 = *pbVar1 + (byte)lVar14;
    cVar15 = in((short)lVar14);
    pcVar18 = (char *)CONCAT31(uVar25,cVar15);
    *(char *)&this_00->_padding_ = (char)this_00->_padding_ + cVar15 + CARRY1(bVar17,(byte)lVar14);
    *pcVar18 = *pcVar18 + cVar15;
    unaff_EBX = (RGE_Visible_Map *)0x0;
    unaff_EBP = this_00;
    if (0 < this_00->DispSel_List_Size) {
      RGE_View::update_display_selected_objects(this_00);
    }
  }
  in_stack_00000068 = (int)unaff_EBP->start_map_col;
  in_stack_0000002c = (int)unaff_EBP->start_map_row;
  in_stack_00000074 = unaff_EBP->max_col_num + 5;
  iVar33 = unaff_EBP->max_row_num * 2 + 0xc;
  in_stack_00000048 = unaff_EBP->map->map_width;
  in_stack_00000050 = unaff_EBP->map->map_height;
  unaff_EBP->function_mode = in_stack_00000124;
  pRVar19 = unaff_EBP->map;
  iVar27 = 0;
  if ((short)unaff_EBX < pRVar19->num_terrain) {
    iVar29 = 0;
    do {
      *(undefined1 *)((int)pRVar19->terrain_types[0].tiles + iVar29 + -1) = 0;
      pRVar19 = unaff_EBP->map;
      iVar27 = iVar27 + 1;
      iVar29 = iVar29 + 0x198;
    } while (iVar27 < pRVar19->num_terrain);
  }
  in_stack_00000078 = unaff_EBP->player->mutualExploredMask;
  in_stack_00000060 = unaff_EBP->player->mutualVisibleMask;
  SDI_List = unaff_EBP->futur_objs;
  in_stack_00000080 = iVar33;
  DClipInfo_List::ReclaimAllNodes(unaff_EBP->futur_objs);
  iStack00000018 = -1;
  if ((unaff_EBP->player->visible == unaff_EBX) ||
     (in_stack_0000005c = unaff_EBX, unaff_EBP->map->map_visible_flag != '\0')) {
    in_stack_0000005c = (RGE_Visible_Map *)0x1;
  }
  in_stack_00000028 = unaff_EBX;
  if ((int)unaff_EBX < iVar33) {
    do {
      iVar33 = in_stack_00000068;
      in_stack_0000004c = in_stack_00000068;
      iStack00000020 = in_stack_0000002c;
      in_stack_00000028 = unaff_EBX;
      if ((((byte)unaff_EBX & 3) == 3) && (MouseSystem != (TMousePointer *)0x0)) {
        TMousePointer::Poll(MouseSystem);
      }
      uVar31 = (uint)unaff_EBX & 1;
      in_stack_0000007c = uVar31;
      if ((uVar31 == 1) && (unaff_EBP->Queued_Blits != 0)) {
        RGE_View::ProcessQueuedBlit(unaff_EBP,0);
      }
      in_stack_0000006c = 0;
      if (0 < in_stack_00000074) {
        do {
          if ((-1 < iStack00000020) && (-1 < iVar33)) {
            if ((iStack00000020 < in_stack_00000050) && (iVar33 < in_stack_00000048)) {
              pRVar19 = unaff_EBP->map;
              pRVar2 = pRVar19->map_row_offset[iStack00000020] + iVar33;
              iVar29 = (int)pRVar19->map_row_offset[iStack00000020][iVar33].screen_xpos -
                       unaff_EBP->map_scr_x_offset;
              iVar27 = (int)pRVar2->screen_ypos - unaff_EBP->map_scr_y_offset;
              in_stack_0000003c = (VSpanMiniList *)(unaff_EBP->tile_wid + iVar29);
              in_stack_00000034 = pRVar19->tilesizes[pRVar2->tile_type].height + iVar27;
              sVar36 = (short)iVar29;
              sVar37 = (short)iVar27;
              if (((uint)(&unified_map_offsets)[iStack00000020][iVar33] & in_stack_00000060) == 0) {
                if (((in_stack_00000078 & (uint)(&unified_map_offsets)[iStack00000020][iVar33]) != 0
                    ) || (in_stack_0000005c != (RGE_Visible_Map *)0x0)) {
                  uVar26 = (-(pRVar19->fog_flag != '\0') & 0x71U) + 0xf;
                  goto LAB_00536d7a;
                }
                uVar26 = '\0';
                pRVar2->last_drawn_as = '\0';
              }
              else {
                uVar26 = '\x0f';
LAB_00536d7a:
                if ((((iVar29 <= unaff_EBP->_padding_) && (iVar27 <= unaff_EBP->_padding_)) &&
                    (unaff_EBP->_padding_ < (int)in_stack_0000003c)) &&
                   (unaff_EBP->_padding_ < (int)in_stack_00000034)) {
                  if ((unaff_EBP->calc_draw_count != 0) &&
                     ((short)(ushort)(pRVar2->field_0x5 & 0x1f) < pRVar19->num_terrain)) {
                    uVar31 = (byte)pRVar2->field_0x5 & 0x1f;
                    pRVar19->terrain_types[uVar31].drawn =
                         pRVar19->terrain_types[uVar31].drawn + '\x01';
                  }
                  _uStack00000038 = 0xffffffff;
                  _uStack00000030 = 0xffffffff;
                  in_stack_00000044 = 0;
                  in_stack_00000058 = 0;
                  if ((unaff_EBP->render_terrain_mode != '\0') && (pRVar2->last_drawn_as == uVar26))
{
                    if (uVar26 == '\x0f') {
                      if (unaff_EBP->map->fog_flag == '\0') {
                        _uStack00000038 = 0;
                      }
                      else {
                        _uStack00000038 =
                             RGE_View::get_tile_mask_num
                                       (unaff_EBP,iVar33,iStack00000020,in_stack_00000048,
                                        in_stack_00000050,in_stack_00000060);
                      }
                      if (pRVar2->last_drawn_shape != _uStack00000038) goto LAB_00536f71;
                    }
                    if ((uVar26 == '\x0f') || (uVar26 == 0x80)) {
                      if (in_stack_0000005c == (RGE_Visible_Map *)0x0) {
                        _uStack00000030 =
                             RGE_View::get_tile_mask_num
                                       (unaff_EBP,iVar33,iStack00000020,in_stack_00000048,
                                        in_stack_00000050,in_stack_00000078);
                      }
                      else {
                        _uStack00000030 = 0;
                      }
                      if (pRVar2->last_drawn_shape2 != _uStack00000030) goto LAB_00536f71;
                    }
                    if (unaff_EBP->Limited_Render_Rect == 0) goto LAB_0053739b;
                    if ((unaff_EBP->Use_Rect2 != 0) &&
                       (((((unaff_EBP->Render_Rect2).right < iVar29 ||
                          ((int)in_stack_0000003c < (unaff_EBP->Render_Rect2).left)) ||
                         ((unaff_EBP->Render_Rect2).bottom < iVar27)) ||
                        (in_stack_00000058 = 1,
                        (int)in_stack_00000034 < (unaff_EBP->Render_Rect2).top)))) {
                      in_stack_00000058 = 0;
                    }
                    if ((((unaff_EBP->Render_Rect1).right < iVar29) ||
                        ((int)in_stack_0000003c < (unaff_EBP->Render_Rect1).left)) ||
                       (((unaff_EBP->Render_Rect1).bottom < iVar27 ||
                        ((int)in_stack_00000034 < (unaff_EBP->Render_Rect1).top)))) {
                      if (in_stack_00000058 == 0) goto LAB_0053739b;
                      in_stack_00000058 = 0;
                      in_stack_00000044 = 2;
                    }
                    else {
                      in_stack_00000044 = 1;
                    }
                  }
LAB_00536f71:
                  pTVar5 = unaff_EBP->Tile_Edge_Tables[pRVar2->tile_type];
                  in_stack_00000054 = unaff_EBP->Black_Edge_Tables[pRVar2->tile_type];
                  if (unaff_EBP->map->fog_flag == '\0') {
                    _uStack00000038 = 0;
                  }
                  if (in_stack_0000005c != (RGE_Visible_Map *)0x0) {
                    _uStack00000030 = 0;
                  }
                  if (_uStack00000038 == 0xffffffff) {
                    if (uVar26 == '\x0f') {
                      _uStack00000038 =
                           RGE_View::get_tile_mask_num
                                     (unaff_EBP,in_stack_0000004c,iStack00000020,in_stack_00000048,
                                      in_stack_00000050,in_stack_00000060);
                    }
                    else {
                      _uStack00000038 = 0;
                    }
                  }
                  uVar31 = _uStack00000030;
                  if ((_uStack00000030 == 0xffffffff) && (uVar31 = 0, uVar26 != '\0')) {
                    uVar31 = RGE_View::get_tile_mask_num
                                       (unaff_EBP,in_stack_0000004c,iStack00000020,in_stack_00000048
                                        ,in_stack_00000050,in_stack_00000078);
                  }
                  _uStack00000030 = uVar31;
                  in_stack_00000070 = pTVar5[_uStack00000038].normal_draw;
                  in_stack_00000064 = pTVar5[_uStack00000038].fog_draw;
                  in_stack_0000003c = in_stack_00000054[_uStack00000030].black_UNdraw;
                  if (uVar26 == 0x80) {
                    in_stack_00000064 = pTVar5->normal_draw;
                    in_stack_00000040 = 1;
                    in_stack_00000034 = 0;
                  }
                  else {
                    in_stack_00000034 = (uint)(in_stack_00000070 != (VSpanMiniList *)0x0);
                    in_stack_00000040 = (uint)(in_stack_00000064 != (VSpanMiniList *)0x0);
                  }
                  if (((int)_uStack00000030 < 1) ||
                     (in_stack_00000054 = (Tile_BlackEdge_Table *)0x1,
                     in_stack_0000003c == (VSpanMiniList *)0x0)) {
                    in_stack_00000054 = (Tile_BlackEdge_Table *)0x0;
                  }
                  if (in_stack_00000044 != iStack00000018) {
                    if (in_stack_00000044 == 0) {
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Clip_Mask,unaff_EBP->_padding_,
                                 unaff_EBP->_padding_,unaff_EBP->_padding_,unaff_EBP->_padding_);
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Fog_Clip_Mask,unaff_EBP->_padding_,
                                 unaff_EBP->_padding_,unaff_EBP->_padding_,unaff_EBP->_padding_);
                    }
                    if (in_stack_00000044 == 1) {
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Clip_Mask,(unaff_EBP->Render_Rect1).left,
                                 (unaff_EBP->Render_Rect1).top,(unaff_EBP->Render_Rect1).right,
                                 (unaff_EBP->Render_Rect1).bottom);
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Fog_Clip_Mask,(unaff_EBP->Render_Rect1).left,
                                 (unaff_EBP->Render_Rect1).top,(unaff_EBP->Render_Rect1).right,
                                 (unaff_EBP->Render_Rect1).bottom);
                    }
                    iStack00000018 = in_stack_00000044;
                    if (in_stack_00000044 == 2) {
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Clip_Mask,(unaff_EBP->Render_Rect2).left,
                                 (unaff_EBP->Render_Rect2).top,(unaff_EBP->Render_Rect2).right,
                                 (unaff_EBP->Render_Rect2).bottom);
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Fog_Clip_Mask,(unaff_EBP->Render_Rect2).left,
                                 (unaff_EBP->Render_Rect2).top,(unaff_EBP->Render_Rect2).right,
                                 (unaff_EBP->Render_Rect2).bottom);
                      iStack00000018 = in_stack_00000044;
                    }
                  }
                  if (in_stack_00000034 != 0) {
                    TSpan_List_Manager::AddMiniList
                              (unaff_EBP->Terrain_Clip_Mask,in_stack_00000070,iVar29,iVar27);
                  }
                  if (in_stack_00000040 != 0) {
                    TSpan_List_Manager::AddMiniList
                              (unaff_EBP->Terrain_Fog_Clip_Mask,in_stack_00000064,iVar29,iVar27);
                  }
                  if (in_stack_00000054 != (Tile_BlackEdge_Table *)0x0) {
                    if (in_stack_00000034 != 0) {
                      TSpan_List_Manager::SubtractMiniList
                                (unaff_EBP->Terrain_Clip_Mask,in_stack_0000003c,iVar29,iVar27);
                    }
                    if (in_stack_00000040 != 0) {
                      TSpan_List_Manager::SubtractMiniList
                                (unaff_EBP->Terrain_Fog_Clip_Mask,in_stack_0000003c,iVar29,iVar27);
                    }
                  }
                  if (in_stack_00000058 != 0) {
                    TSpan_List_Manager::SetSpanRegions
                              (unaff_EBP->Terrain_Clip_Mask,(unaff_EBP->Render_Rect2).left,
                               (unaff_EBP->Render_Rect2).top,(unaff_EBP->Render_Rect2).right,
                               (unaff_EBP->Render_Rect2).bottom);
                    TSpan_List_Manager::SetSpanRegions
                              (unaff_EBP->Terrain_Fog_Clip_Mask,(unaff_EBP->Render_Rect2).left,
                               (unaff_EBP->Render_Rect2).top,(unaff_EBP->Render_Rect2).right,
                               (unaff_EBP->Render_Rect2).bottom);
                    iStack00000018 = 2;
                    if (in_stack_00000034 != 0) {
                      TSpan_List_Manager::AddMiniList
                                (unaff_EBP->Terrain_Clip_Mask,in_stack_00000070,iVar29,iVar27);
                    }
                    if (in_stack_00000040 != 0) {
                      TSpan_List_Manager::AddMiniList
                                (unaff_EBP->Terrain_Fog_Clip_Mask,in_stack_00000064,iVar29,iVar27);
                    }
                    if (in_stack_00000054 != (Tile_BlackEdge_Table *)0x0) {
                      if (in_stack_00000034 != 0) {
                        TSpan_List_Manager::SubtractMiniList
                                  (unaff_EBP->Terrain_Clip_Mask,in_stack_0000003c,iVar29,iVar27);
                      }
                      if (in_stack_00000040 != 0) {
                        TSpan_List_Manager::SubtractMiniList
                                  (unaff_EBP->Terrain_Fog_Clip_Mask,in_stack_0000003c,iVar29,iVar27)
                        ;
                      }
                    }
                  }
                  bVar17 = pRVar2->field_0x5 & 0x1f;
                  sVar4 = unaff_EBP->map->terrain_types[(byte)pRVar2->field_0x5 & 0x1f].
                          terrain_to_draw;
                  if (sVar4 != -1) {
                    bVar17 = (byte)sVar4;
                  }
                  pRVar2->last_drawn_shape2 = uStack00000030;
                  pRVar2->last_drawn_shape = uStack00000038;
                  pRVar2->last_drawn_as = uVar26;
                  pRVar2->draw_as = uVar26;
                  pRVar2->draw_attribute = pRVar2->draw_attribute & 0xbf;
                  RGE_View::draw_tile(unaff_EBP,pRVar2,bVar17,sVar36,sVar37,(short)in_stack_0000004c
                                      ,(short)iStack00000020,uVar26,in_stack_00000034,
                                      in_stack_00000040);
                  tiles_drawn = tiles_drawn + 1;
                  iVar33 = in_stack_0000004c;
                }
              }
LAB_0053739b:
              if ((pRVar2 != (RGE_Tile *)0x0) && ((pRVar2->draw_attribute & 0x40) == 0x40)) {
                bVar17 = pRVar2->field_0x5 & 0x1f;
                sVar4 = unaff_EBP->map->terrain_types[(byte)pRVar2->field_0x5 & 0x1f].
                        terrain_to_draw;
                if (sVar4 != -1) {
                  bVar17 = (byte)sVar4;
                }
                RGE_View::draw_tile(unaff_EBP,pRVar2,bVar17,sVar36,sVar37,(short)iVar33,
                                    (short)iStack00000020,uVar26,1,1);
                pRVar2->draw_attribute = pRVar2->draw_attribute & 0xbf;
              }
              if ((view_debug_Objects == 0) && (pRVar2 != (RGE_Tile *)0x0)) {
                SDI_Capture_Info = 1;
                if (uVar26 == '\0') {
                  DClipInfo_List::SetCaptureLevel(unaff_EBP->futur_objs,0,5);
                }
                if (uVar26 != '\x0f') {
                  fog_next_shape = 1;
                }
                RGE_Object_List::draw
                          (&pRVar2->objects,unaff_EBP->save_area1,sVar36,
                           (ushort)((byte)pRVar2->field_0x5 >> 5) * unaff_EBP->tile_half_hgt +
                           sVar37,uVar26 == 0x80);
                DClipInfo_List::SetCaptureLevel(unaff_EBP->futur_objs,0,0x28);
                fog_next_shape = 0;
                SDI_Capture_Info = 0;
              }
            }
            else {
              in_stack_0000006c = in_stack_00000074;
            }
          }
          iVar33 = iVar33 + 1;
          iStack00000020 = iStack00000020 + 1;
          in_stack_0000006c = in_stack_0000006c + 1;
          unaff_EBX = in_stack_00000028;
          uVar31 = in_stack_0000007c;
          in_stack_0000004c = iVar33;
        } while (in_stack_0000006c < in_stack_00000074);
      }
      if (uVar31 == 1) {
        in_stack_0000002c = in_stack_0000002c + 1;
      }
      else {
        in_stack_00000068 = in_stack_00000068 + -1;
      }
      unaff_EBX = (RGE_Visible_Map *)((int)&unaff_EBX->map_offsets + 1);
      in_stack_00000028 = unaff_EBX;
    } while ((int)unaff_EBX < in_stack_00000080);
  }
  iVar33 = unaff_EBP->Queued_Blits;
  while (iVar33 != 0) {
    RGE_View::ProcessQueuedBlit(unaff_EBP,1);
    iVar33 = unaff_EBP->Queued_Blits;
  }
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_0000012c;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_0000012c;
  SDI_Capture_Info = 1;
  if (unaff_EBP->scroll_action == '\x02') {
    DClipInfo_List::AddGDINode
              (unaff_EBP->futur_objs,4,0x14,unaff_EBP->_padding_ - in_stack_00000128,
               unaff_EBP->_padding_ - in_stack_0000012c,unaff_EBP->mouse_last_x - in_stack_00000128,
               unaff_EBP->mouse_last_y - in_stack_0000012c,0,0,0,0,0x28,0xff,0);
  }
  iVar33 = rge_base_game->game_mode;
  if ((iVar33 == 1) || ((6 < iVar33 && (iVar33 < 9)))) {
    RGE_View::draw_object_outline(unaff_EBP);
  }
  if (rge_base_game->game_mode == 0x15) {
    (**(code **)(unaff_EBP->_padding_ + 0xf8))();
  }
  cStack00000013 = '\0';
  if (unaff_EBP->extra_sprites != (Ov_Sprite_Draw_Rec *)0x0) {
    in_stack_00000028 = (RGE_Visible_Map *)debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp,0xe3e)
    ;
    pOVar8 = unaff_EBP->extra_sprites;
    while (pOVar8 != (Ov_Sprite_Draw_Rec *)0x0) {
      bVar35 = false;
      if (pOVar8->theShape == (TShape *)0x0) {
LAB_005376e9:
        if (bVar35) goto LAB_005376ed;
        pOVar8 = pOVar8->next;
      }
      else {
        if (pOVar8->LastDrawTime == 0) {
          pOVar8->LastDrawTime = (ulong)in_stack_00000028;
        }
        else if (((pOVar8->displayfunction == 1) || (pOVar8->displayfunction == 2)) &&
                (uVar31 = (int)in_stack_00000028 - pOVar8->LastDrawTime,
                pOVar8->DrawTimeInterval <= uVar31)) {
          do {
            pOVar8->thefacet = pOVar8->thefacet + 1;
            lVar20 = TShape::shape_count(pOVar8->theShape);
            if ((lVar20 <= pOVar8->thefacet) && (pOVar8->thefacet = 0, pOVar8->displayfunction == 2)
               ) {
              bVar35 = true;
              cStack00000013 = '\x01';
            }
            uVar6 = pOVar8->DrawTimeInterval;
            uVar31 = uVar31 - uVar6;
            pOVar8->LastDrawTime = pOVar8->LastDrawTime + uVar6;
          } while (uVar6 <= uVar31);
        }
        if (!bVar35) {
          SDI_Draw_Level = pOVar8->drawLevel;
          SDI_Object_ID = -1;
          TShape::shape_draw(pOVar8->theShape,(TDrawArea *)unaff_EBP->_padding_,
                             pOVar8->world_x - unaff_EBP->map_scr_x_offset,
                             pOVar8->world_y - unaff_EBP->map_scr_y_offset,pOVar8->thefacet,
                             (uchar)pOVar8->flags,pOVar8->colortable);
          goto LAB_005376e9;
        }
LAB_005376ed:
        if (pOVar8->prev != (Ov_Sprite_Draw_Rec *)0x0) {
          pOVar8->prev->next = pOVar8->next;
        }
        if (pOVar8->next != (Ov_Sprite_Draw_Rec *)0x0) {
          pOVar8->next->prev = pOVar8->prev;
        }
        if (pOVar8->prev == (Ov_Sprite_Draw_Rec *)0x0) {
          unaff_EBP->extra_sprites = pOVar8->next;
        }
        pOVar7 = pOVar8->next;
        operator_delete(pOVar8);
        pOVar8 = pOVar7;
      }
    }
  }
  if (cStack00000013 != '\0') {
    RGE_View::reset_cyclic_overlay_sprites(unaff_EBP);
  }
  iVar33 = 0;
  SDI_Capture_Info = 0;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - in_stack_0000012c;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - in_stack_0000012c;
  pDVar24 = unaff_EBP->futur_objs;
  if (0 < pDVar24->YLine_Size) {
    do {
      for (pDVar22 = pDVar24->Draw_Clip_Nodes[iVar33]; pDVar22 != (DClipInfo_Node *)0x0;
          pDVar22 = pDVar22->Next) {
        iVar27 = pDVar22->Draw_Level;
        pDVar30 = unaff_EBP->futur_objs->Draw_Level_Tail[iVar27];
        if (pDVar30 == (DClipInfo_Node *)0x0) {
          unaff_EBP->futur_objs->Draw_Level_Head[iVar27] = pDVar22;
        }
        else {
          pDVar30->NextOnLevel = pDVar22;
        }
        unaff_EBP->futur_objs->Draw_Level_Tail[iVar27] = pDVar22;
      }
      pDVar24 = unaff_EBP->futur_objs;
      iVar33 = iVar33 + 1;
    } while (iVar33 < pDVar24->YLine_Size);
  }
  iVar33 = 0;
  Clip_draw = 0;
  Clip_remove = 0;
  if (iStack00000018 != 0) {
    TSpan_List_Manager::SetSpanRegions
              (unaff_EBP->Terrain_Clip_Mask,unaff_EBP->_padding_,unaff_EBP->_padding_,
               unaff_EBP->_padding_,unaff_EBP->_padding_);
    TSpan_List_Manager::SetSpanRegions
              (unaff_EBP->Terrain_Fog_Clip_Mask,unaff_EBP->_padding_,unaff_EBP->_padding_,
               unaff_EBP->_padding_,unaff_EBP->_padding_);
  }
  do {
    for (iVar27 = *(int *)((int)unaff_EBP->futur_objs->Draw_Level_Head + iVar33); iVar27 != 0;
        iVar27 = *(int *)(iVar27 + 4)) {
      if (*(int *)(iVar27 + 0x2c) == 0) {
        pTVar9 = unaff_EBP->Terrain_Clip_Mask;
        _ASMSet_Surface_Info
                  (unaff_EBP->save_area1->CurDisplayOffsets,pTVar9->Line_Head_Ptrs,
                   pTVar9->Line_Tail_Ptrs,pTVar9->Min_Span_Px,pTVar9->Min_Line,pTVar9->Max_Span_Px,
                   pTVar9->Max_Line);
        _ASMSet_Color_Xform(*(undefined4 *)(iVar27 + 0x28));
        _ASMSet_Xlate_Table(*(undefined4 *)(iVar27 + 0x24));
        puVar10 = *(undefined4 **)(iVar27 + 0xc);
        _ASMDraw_Sprite(*(undefined4 *)(iVar27 + 0x20),*(undefined4 *)(iVar27 + 0x14),
                        *(undefined4 *)(iVar27 + 0x18),puVar10[4],puVar10[5],*puVar10,puVar10[1],
                        *(uint *)(iVar27 + 0x1c) & 0xfe);
        pTVar9 = unaff_EBP->Terrain_Fog_Clip_Mask;
        _ASMSet_Surface_Info
                  (unaff_EBP->save_area1->CurDisplayOffsets,pTVar9->Line_Head_Ptrs,
                   pTVar9->Line_Tail_Ptrs,pTVar9->Min_Span_Px,pTVar9->Min_Line,pTVar9->Max_Span_Px,
                   pTVar9->Max_Line);
        _ASMDraw_Sprite(*(undefined4 *)(iVar27 + 0x20),*(undefined4 *)(iVar27 + 0x14),
                        *(undefined4 *)(iVar27 + 0x18),puVar10[4],puVar10[5],*puVar10,puVar10[1],
                        *(uint *)(iVar27 + 0x1c) | 1);
      }
    }
    iVar33 = iVar33 + 4;
  } while (iVar33 < 0x15);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  if (((rge_base_game->prog_mode == 4) && (unaff_EBP->_padding_ != 0)) &&
     (iVar33 = TMousePointer::get_game_enable(MouseSystem), iVar33 != 0)) {
    uVar21 = debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp,0xf11);
    iVar33 = RGE_View::Get_Cursor_Position
                       (unaff_EBP,(tagPOINT *)&stack0x00000088,-in_stack_00000128,-in_stack_0000012c
                       );
    if (iVar33 != 0) {
      iVar33 = RGE_View::pick_touched_object
                         (unaff_EBP,unaff_EBP->futur_objs,in_stack_00000088,in_stack_0000008c,10,
                          0x28,&stack0x00000084);
      if (iVar33 == 1) {
        if (((unaff_EBP->UC_ObjectTouched != 0) && (unaff_EBP->UC_TouchedObj == in_stack_00000084))
           || (unaff_EBP->UC_ObjectTouched = 1, unaff_EBP->UC_TouchedObj == in_stack_00000084))
        goto LAB_00537b2a;
        unaff_EBP->UC_StartTime = uVar21;
        unaff_EBP->UC_TouchedObj = in_stack_00000084;
        in_stack_00000028 = (RGE_Visible_Map *)0x0;
        in_stack_0000002c = 0;
        iVar33 = (**(code **)(unaff_EBP->player->_padding_ + 0x9c))
                           (in_stack_00000084,&stack0x00000028,&stack0x0000002c);
        if (iVar33 == 1) {
          TMousePointer::set_game_facet(MouseSystem,(int)in_stack_00000028);
          if ((unaff_EBP->message_panel != (TMessagePanel *)0x0) && (rge_base_game->rollover != 0))
{
            TPanel::get_string((TPanel *)unaff_EBP,in_stack_0000002c,&stack0x000000a0,0x7f);
            TMessagePanel::show_message
                      (unaff_EBP->message_panel,InfoMessage,&stack0x000000a0,'p','\0',(void *)0x0,0,
                       0);
          }
          goto LAB_00537b2a;
        }
        TMousePointer::set_game_facet(MouseSystem,0);
        this = unaff_EBP->message_panel;
        if (this == (TMessagePanel *)0x0) goto LAB_00537b2a;
        iVar33 = rge_base_game->rollover;
      }
      else {
        if (unaff_EBP->UC_ObjectTouched == 0) goto LAB_00537b2a;
        unaff_EBP->UC_ObjectTouched = 0;
        unaff_EBP->UC_TouchedObj = -0x80000000;
        TMousePointer::set_game_facet(MouseSystem,0);
        this = unaff_EBP->message_panel;
        if (this == (TMessagePanel *)0x0) goto LAB_00537b2a;
        iVar33 = rge_base_game->rollover;
      }
      if (iVar33 != 0) {
        TMessagePanel::remove_message(this);
      }
    }
  }
LAB_00537b2a:
  for (piVar11 = (int *)unaff_EBP->_padding_; piVar11 != (int *)0x0; piVar11 = (int *)piVar11[2]) {
    piVar12 = (int *)*piVar11;
    if ((piVar12[0x1b] != 0) && (piVar12[0xe] != 0)) {
      (**(code **)(*piVar12 + 0xb8))(&stack0x00000090);
      iVar27 = in_stack_00000094 - in_stack_0000012c;
      iVar33 = in_stack_00000090 - in_stack_00000128;
      if (iVar33 < 0) {
        iVar33 = 0;
      }
      if (iVar27 < 0) {
        iVar27 = 0;
      }
      pDVar22 = DClipInfo_List::AddGDINode
                          (unaff_EBP->futur_objs,3,in_stack_0000009c - in_stack_0000012c,iVar33,
                           iVar27,in_stack_00000098 - in_stack_00000128,
                           in_stack_0000009c - in_stack_0000012c,0,0,0,0,0x1e,piVar12[0x38],0);
      if (pDVar22 != (DClipInfo_Node *)0x0) {
        pDVar30 = unaff_EBP->futur_objs->Draw_Level_Tail[0x1e];
        if (pDVar30 == (DClipInfo_Node *)0x0) {
          unaff_EBP->futur_objs->Draw_Level_Head[0x1e] = pDVar22;
        }
        else {
          pDVar30->NextOnLevel = pDVar22;
        }
        unaff_EBP->futur_objs->Draw_Level_Tail[0x1e] = pDVar22;
      }
    }
  }
  if (unaff_EBP->render_terrain_mode == '\0') {
    pTVar23 = unaff_EBP->save_area1;
    iVar33 = 0;
    if (0 < pTVar23->Height) {
      do {
        TSpan_List_Manager::AddSpan(unaff_EBP->Master_Clip_Mask,0,pTVar23->Width + -1,iVar33);
        pTVar23 = unaff_EBP->save_area1;
        iVar33 = iVar33 + 1;
      } while (iVar33 < pTVar23->Height);
    }
    DClipInfo_List::ReclaimAllNodes(unaff_EBP->prior_objs);
  }
  else {
    TSpan_List_Manager::Merge_n_Align
              (unaff_EBP->Master_Clip_Mask,unaff_EBP->Terrain_Clip_Mask,
               unaff_EBP->Terrain_Fog_Clip_Mask);
    if (unaff_EBP->Limited_Render_Rect != 0) {
      if ((-1 < (unaff_EBP->Render_Rect1).left) &&
         (iVar33 = (unaff_EBP->Render_Rect1).top, iVar33 <= (unaff_EBP->Render_Rect1).bottom)) {
        do {
          TSpan_List_Manager::AddSpan
                    (unaff_EBP->Master_Clip_Mask,(unaff_EBP->Render_Rect1).left,
                     (unaff_EBP->Render_Rect1).right,iVar33);
          iVar33 = iVar33 + 1;
        } while (iVar33 <= (unaff_EBP->Render_Rect1).bottom);
      }
      if (((unaff_EBP->Use_Rect2 != 0) && (-1 < (unaff_EBP->Render_Rect2).left)) &&
         (iVar33 = (unaff_EBP->Render_Rect2).top, iVar33 <= (unaff_EBP->Render_Rect2).bottom)) {
        do {
          TSpan_List_Manager::AddSpan
                    (unaff_EBP->Master_Clip_Mask,(unaff_EBP->Render_Rect2).left,
                     (unaff_EBP->Render_Rect2).right,iVar33);
          iVar33 = iVar33 + 1;
        } while (iVar33 <= (unaff_EBP->Render_Rect2).bottom);
      }
    }
    pDVar24 = unaff_EBP->futur_objs;
    iStack00000014 = 0;
    if (0 < pDVar24->YLine_Size) {
      do {
        for (pDVar22 = pDVar24->Draw_Clip_Nodes[iStack00000014]; pDVar22 != (DClipInfo_Node *)0x0;
            pDVar22 = pDVar22->Next) {
          if (5 < pDVar22->Draw_Level) {
            pDVar30 = unaff_EBP->prior_objs->Draw_Clip_Nodes[iStack00000014];
            bVar35 = true;
            in_stack_0000002c = 1;
            if (pDVar30 != (DClipInfo_Node *)0x0) {
              do {
                bVar35 = true;
                iVar33 = (-(uint)(pDVar22->Node_Type != 0) & 0x10) + 0x24;
                ppSVar32 = &pDVar22->Shape;
                ppSVar34 = &pDVar30->Shape;
                do {
                  if (iVar33 == 0) break;
                  iVar33 = iVar33 + -1;
                  bVar35 = *(char *)ppSVar32 == *(char *)ppSVar34;
                  ppSVar32 = (Shape_Info **)((int)ppSVar32 + 1);
                  ppSVar34 = (Shape_Info **)((int)ppSVar34 + 1);
                } while (bVar35);
                if (bVar35) {
                  bVar35 = false;
                  Clip_remove = Clip_remove + 1;
                  pDVar30->Node_Type = -1;
                  goto LAB_00537d85;
                }
                pDVar30 = pDVar30->Next;
              } while (pDVar30 != (DClipInfo_Node *)0x0);
              bVar35 = true;
            }
LAB_00537d85:
            if (bVar35) {
              if (pDVar22->Node_Type == 0) {
                TSpan_List_Manager::AddShape_Align
                          (unaff_EBP->Master_Clip_Mask,pDVar22->Shape_Base,pDVar22->Shape,
                           pDVar22->Draw_X,pDVar22->Draw_Y,
                           (uint)(((byte)pDVar22->Draw_Flag & 2) == 2));
                Clip_draw = Clip_draw + 1;
              }
              else {
                RGE_View::Add_GDI_Clip_Mask(unaff_EBP,pDVar22,unaff_EBP->Master_Clip_Mask);
              }
            }
          }
        }
        for (pDVar22 = unaff_EBP->prior_objs->Draw_Clip_Nodes[iStack00000014];
            pDVar22 != (DClipInfo_Node *)0x0; pDVar22 = pDVar22->Next) {
          if ((5 < pDVar22->Draw_Level) && (pDVar22->Node_Type != -1)) {
            pDVar30 = unaff_EBP->futur_objs->Draw_Clip_Nodes[iStack00000014];
            bVar35 = true;
            in_stack_0000002c = 1;
            if (pDVar30 != (DClipInfo_Node *)0x0) {
              do {
                bVar35 = true;
                iVar33 = (-(uint)(pDVar22->Node_Type != 0) & 0x10) + 0x24;
                ppSVar32 = &pDVar30->Shape;
                ppSVar34 = &pDVar22->Shape;
                do {
                  if (iVar33 == 0) break;
                  iVar33 = iVar33 + -1;
                  bVar35 = *(char *)ppSVar32 == *(char *)ppSVar34;
                  ppSVar32 = (Shape_Info **)((int)ppSVar32 + 1);
                  ppSVar34 = (Shape_Info **)((int)ppSVar34 + 1);
                } while (bVar35);
                if (bVar35) {
                  bVar35 = false;
                  goto LAB_00537e5a;
                }
                pDVar30 = pDVar30->Next;
              } while (pDVar30 != (DClipInfo_Node *)0x0);
              bVar35 = true;
            }
LAB_00537e5a:
            if (bVar35) {
              if (pDVar22->Node_Type == 0) {
                TSpan_List_Manager::AddShape_Align
                          (unaff_EBP->Master_Clip_Mask,pDVar22->Shape_Base,pDVar22->Shape,
                           pDVar22->Draw_X,pDVar22->Draw_Y,
                           (uint)(((byte)pDVar22->Draw_Flag & 2) == 2));
                Clip_draw = Clip_draw + 1;
              }
              else {
                RGE_View::Add_GDI_Clip_Mask(unaff_EBP,pDVar22,unaff_EBP->Master_Clip_Mask);
              }
            }
          }
        }
        pDVar24 = unaff_EBP->futur_objs;
        iStack00000014 = iStack00000014 + 1;
      } while (iStack00000014 < pDVar24->YLine_Size);
    }
  }
  iVar27 = in_stack_0000012c;
  iVar33 = in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_0000012c;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_0000012c;
  TDrawArea::PtrSpanCopy
            (unaff_EBP->save_area1,(TDrawArea *)unaff_EBP->_padding_,unaff_EBP->_padding_,
             unaff_EBP->_padding_,&unaff_EBP->save_area1->ClipRect,
             (uchar **)unaff_EBP->Master_Clip_Mask->Line_Head_Ptrs);
  RGE_View::Update_Render_Pointers(unaff_EBP);
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - iVar33;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - iVar27;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - iVar33;
  pTVar9 = unaff_EBP->Master_Clip_Mask;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - iVar27;
  _ASMSet_Surface_Info
            (unaff_EBP->RenderOffsets,pTVar9->Line_Head_Ptrs,pTVar9->Line_Tail_Ptrs,
             pTVar9->Min_Span_Px,pTVar9->Min_Line,pTVar9->Max_Span_Px,pTVar9->Max_Line);
  *(TSpan_List_Manager **)(unaff_EBP->_padding_ + 0xd0) = unaff_EBP->Master_Clip_Mask;
  in_stack_00000028 = (RGE_Visible_Map *)0x18;
  do {
    for (pDVar22 = *(DClipInfo_Node **)
                    ((int)unaff_EBP->futur_objs->Draw_Level_Head + (int)in_stack_00000028);
        pDVar22 != (DClipInfo_Node *)0x0; pDVar22 = pDVar22->NextOnLevel) {
      if (pDVar22->Node_Type == 0) {
        bVar35 = false;
        uVar31 = pDVar22->Draw_Flag & 0xffc;
        if (uVar31 != 0) {
          if (((byte)uVar31 & 4) == 4) {
            _ASMSet_Shadowing(0xffffff,0,0xffff00ff,0);
          }
          if (((byte)uVar31 & 8) == 8) {
            uVar31 = ((int)uVar31 >> 4) << 0x10 | (int)uVar31 >> 4;
            _ASMSet_Shadowing(&DAT_ff00ff00,uVar31,0xff00ff,uVar31 << 8);
          }
          bVar35 = true;
        }
        _ASMSet_Color_Xform(pDVar22->Xform_Mask);
        _ASMSet_Xlate_Table(pDVar22->Color_Table);
        pSVar13 = pDVar22->Shape;
        _ASMDraw_Sprite(pDVar22->Shape_Base,pDVar22->Draw_X,pDVar22->Draw_Y,pSVar13->Width,
                        pSVar13->Height,pSVar13->Shape_Data_Offsets,pSVar13->Shape_Outline_Offset,
                        pDVar22->Draw_Flag & 3);
        if (bVar35) {
          _ASMSet_Shadowing(0xff00ff,0,&DAT_ff00ff00,0);
        }
      }
      else {
        RGE_View::Draw_GDI_Object(unaff_EBP,pDVar22,(TDrawArea *)unaff_EBP->_padding_);
      }
    }
    in_stack_00000028 = (RGE_Visible_Map *)((int)in_stack_00000028 + 4);
  } while ((int)in_stack_00000028 < 0xa1);
  if ((view_debug_spans != 0) && (unaff_EBP->render_terrain_mode != '\0')) {
    iVar33 = frame_count % 0xdc;
    pTVar23 = (TDrawArea *)unaff_EBP->_padding_;
    iVar27 = 0;
    if (0 < pTVar23->Height) {
      do {
        TDrawArea::DrawLine(pTVar23,0,iVar27,pTVar23->Width + -1,iVar27,(char)iVar33 + '\x10');
        pTVar23 = (TDrawArea *)unaff_EBP->_padding_;
        iVar27 = iVar27 + 1;
      } while (iVar27 < pTVar23->Height);
    }
  }
  if (view_debug_palette != 0) {
    cVar15 = '\0';
    iVar33 = 0x20;
    do {
      cVar16 = '\0';
      cStack00000013 = cVar15 << 4;
      iVar27 = 0;
      do {
        TDrawArea::FillRect((TDrawArea *)unaff_EBP->_padding_,iVar27,iVar33,iVar27 + 0x1f,
                            iVar33 + 0xf,cVar16 + cStack00000013);
        iVar27 = iVar27 + 0x20;
        cVar16 = cVar16 + '\x01';
      } while (iVar27 < 0x200);
      iVar33 = iVar33 + 0x10;
      cVar15 = cVar15 + '\x01';
    } while (iVar33 < 0x120);
  }
  TDrawArea::Unlock((TDrawArea *)unaff_EBP->_padding_,s_view__view_function_terrain);
  *(undefined4 *)(unaff_EBP->_padding_ + 0xd0) = *(undefined4 *)(unaff_EBP->_padding_ + 0xcc);
  pDVar24 = unaff_EBP->futur_objs;
  unaff_EBP->futur_objs = unaff_EBP->prior_objs;
  unaff_EBP->prior_objs = pDVar24;
  return 0;
}

// --------------------------------------------------

// Function: FUN_005396ad
// Address: 005396ad
// XREFS: None
int __fastcall FUN_005396ad(int param_1)
{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  short sVar4;
  uint in_EAX;
  int iVar5;
  RGE_Pick_Obj_Info *pRVar6;
  char cVar8;
  RGE_Pick_Obj_Info *unaff_EBX;
  RGE_Pick_Obj_Info **ppRVar7;
  undefined4 unaff_EBP;
  int iVar9;
  char unaff_SI;
  int iVar10;
  short *psVar11;
  byte unaff_retaddr;
  int iVar12;
  RGE_Pick_Obj_Info *pRVar13;
  RGE_Pick_Obj_Info *pRVar14;
  
  iVar5 = CONCAT31((int3)((uint)unaff_EBP >> 8),(char)unaff_EBP + (char)unaff_EBX);
  *(char *)&unaff_EBX->object_id = (char)unaff_EBX->object_id + (char)param_1;
  cVar8 = (char)((uint)unaff_EBX >> 8);
  cRamf400a72a = cRamf400a72a + cVar8;
  *(char *)&unaff_EBX->object_id = (char)unaff_EBX->object_id + (char)((uint)unaff_EBP >> 8);
  *(char *)(param_1 + -0x6a) = *(char *)(param_1 + -0x6a) + (char)in_EAX;
  cRamf400a72a = cRamf400a72a + cVar8;
  *(char *)(param_1 + -0x6a) = *(char *)(param_1 + -0x6a) + unaff_SI;
  pcVar1 = (char *)(iVar5 + -0x6a);
  *pcVar1 = *pcVar1 + (char)unaff_EBX;
  cRamf400a72a = cRamf400a72a + cVar8;
  pcVar1 = (char *)(iVar5 + 0x7ea54ea7);
  *pcVar1 = *pcVar1 + (char)(in_EAX >> 8);
  *(char *)&unaff_EBX[0x5b64113].draw_x = (char)unaff_EBX[0x5b64113].draw_x + (char)in_EAX;
  iVar9 = 0;
  iVar5 = *(int *)(param_1 + 0x8c);
  iVar12 = 0;
  if ((((((int)(in_EAX & 0xffffff18) < iVar5) || (*(int *)(param_1 + 0x94) < (int)unaff_EBX)) ||
       (iVar2 = *(int *)(param_1 + 0x90), (int)unaff_EBX < iVar2)) ||
      ((*(int *)(param_1 + 0x98) < (int)unaff_EBX || (0x28 < (int)unaff_EBX)))) ||
     ((int)unaff_EBX < 0)) {
    return 0;
  }
  pRVar13 = unaff_EBX;
  if ((int)unaff_EBX < 0) {
    pRVar13 = (RGE_Pick_Obj_Info *)0x0;
  }
  pRVar6 = unaff_EBX;
  if (0x28 < (int)unaff_EBX) {
    pRVar6 = (RGE_Pick_Obj_Info *)0x28;
  }
  pRVar14 = unaff_EBX;
  do {
    if ((int)pRVar6 < (int)pRVar13) {
      return iVar9;
    }
    iVar10 = *(int *)(*(int *)(*(int *)(param_1 + 0x334) + 0x5c) + (int)pRVar6 * 4);
    if (iVar10 != 0) {
      psVar11 = &DAT_0087d4a4 + iVar9 * 6;
      iVar9 = iVar12;
      do {
        sVar4 = 0;
        if ((*(int *)(iVar10 + 0x2c) == 0) &&
           (pRVar14 = *(RGE_Pick_Obj_Info **)(iVar10 + 8), -1 < (int)pRVar14)) {
          if (((((int)unaff_EBX - iVar5 <= (int)*(short *)(iVar10 + 0x34)) &&
               ((((int)*(short *)(iVar10 + 0x30) <= (int)unaff_EBX - iVar5 &&
                 ((int)unaff_EBX - iVar2 <= (int)*(short *)(iVar10 + 0x36))) &&
                ((int)*(short *)(iVar10 + 0x32) <= (int)unaff_EBX - iVar2)))) &&
              (((iVar12 = *(int *)(*(int *)(*(int *)(param_1 + 0xfc) + 0x88) + (int)pRVar14 * 4),
                unaff_EBX == (RGE_Pick_Obj_Info *)0xffffffff ||
                ((RGE_Pick_Obj_Info *)(int)*(short *)(*(int *)(iVar12 + 0xc) + 0x4a) == unaff_EBX))
               && (*(char *)(iVar12 + 0x48) == '\x02')))) &&
             (unaff_retaddr <= *(byte *)(*(int *)(iVar12 + 8) + 0x8d))) {
            sVar4 = 1;
          }
        }
        if (sVar4 != 0) {
          bVar3 = true;
          if ((0x87d4a4 < (int)psVar11) && (iVar12 = 0, 0x87d4a4 < (int)psVar11)) {
            ppRVar7 = &Picked_Objects;
            do {
              if (*ppRVar7 == pRVar14) {
                bVar3 = false;
                if (sVar4 < (short)(&DAT_0087d4a4)[iVar12 * 6]) {
                  (&DAT_0087d4a4)[iVar12 * 6] = sVar4;
                }
                break;
              }
              iVar12 = iVar12 + 1;
              ppRVar7 = ppRVar7 + 3;
            } while (iVar12 < iVar9);
          }
          if (bVar3) {
            *(RGE_Pick_Obj_Info **)(psVar11 + -2) = pRVar14;
            *psVar11 = sVar4;
            psVar11[1] = sVar4;
            psVar11[2] = *(short *)(iVar10 + 0x14);
            psVar11[3] = *(short *)(iVar10 + 0x18);
            iVar9 = iVar9 + 1;
            psVar11 = psVar11 + 6;
          }
          if (0x87d7a3 < (int)psVar11) {
            return 0x40;
          }
        }
        iVar10 = *(int *)(iVar10 + 4);
        iVar12 = iVar9;
      } while (iVar10 != 0);
    }
    pRVar6 = (RGE_Pick_Obj_Info *)((int)&pRVar6[-1].draw_y + 1);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0053a999
// Address: 0053a999
// XREFS: None
void __fastcall FUN_0053a999(RGE_View *param_1,undefined4 param_2)
{
  uchar uVar1;
  int iVar2;
  undefined4 in_EAX;
  int iVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int unaff_EDI;
  int iVar7;
  int iStack_1c;
  int iStack_18;
  
  iRama5020053 = CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX + -0x5d);
  cVar5 = (char)((uint)param_2 >> 8);
  *(char *)(unaff_EDI + -0x5a) = *(char *)(unaff_EDI + -0x5a) + cVar5;
  *(char *)(unaff_EDI + -0x5a) = *(char *)(unaff_EDI + -0x5a) + cVar5;
  *(char *)(unaff_EDI + -0x5a) = *(char *)(unaff_EDI + -0x5a) + cVar5;
  cRamd90053a3 = cRamd90053a3 + (char)((uint)param_1 >> 8);
  *(char *)(iRama5020053 + -0x6f6f6f70) = *(char *)(iRama5020053 + -0x6f6f6f70) + (char)param_2;
  switch(param_1->scroll_action) {
  case '\x01':
  case '\x06':
  case '\a':
  case '\b':
    iStack_1c = param_1->_padding_;
    iStack_18 = param_1->_padding_;
    ClientToScreen(*(undefined4 *)(param_1->_padding_ + 4),&iStack_1c);
    SetCursorPos(iStack_1c,iStack_18);
    break;
  case '\x02':
    iVar7 = param_1->_padding_;
    iVar2 = param_1->mouse_last_x;
    iVar6 = iVar2;
    if (iVar2 < iVar7) {
      iVar6 = iVar7;
      iVar7 = iVar2;
    }
    iVar2 = param_1->_padding_;
    iVar4 = param_1->mouse_last_y;
    iVar3 = iVar2;
    if (iVar4 < iVar2) {
      iVar3 = iVar4;
      iVar4 = iVar2;
    }
    RGE_View::pick_multi(param_1,'\x04',iVar7,iVar3,iVar6,iVar4);
    (**(code **)(param_1->_padding_ + 0x20))(1);
    break;
  case '\t':
    iVar7 = param_1->_padding_;
    (**(code **)(iVar7 + 0xf4))
              (param_1->_padding_,param_1->_padding_,param_1->_padding_,param_1->_padding_,0);
    (**(code **)(iVar7 + 0x20))(1);
  }
  uVar1 = param_1->scroll_action;
  if ((((uVar1 == '\x01') || (uVar1 == '\x02')) || (uVar1 == '\x06')) ||
     ((uVar1 == '\a' || (uVar1 == '\b')))) {
    RGE_Base_Game::mouse_on(rge_base_game);
  }
  TPanel::release_mouse((TPanel *)param_1);
  param_1->scroll_action = '\0';
  return;
}

// --------------------------------------------------

// Function: FUN_0053b475
// Address: 0053b475
// XREFS: None
void __fastcall FUN_0053b475(int param_1,char param_2)
{
  char cVar1;
  undefined4 in_EAX;
  undefined4 *puVar3;
  int iVar2;
  
  cVar1 = (char)in_EAX;
  iVar2 = CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(0x53,cVar1));
  *(char *)(iVar2 + -0x4c) = *(char *)(iVar2 + -0x4c) + cVar1;
  *(char *)(iVar2 + -0x4c) = *(char *)(iVar2 + -0x4c) + (char)param_1;
  *(char *)(iVar2 + -0x4c) = *(char *)(iVar2 + -0x4c) + param_2;
  *(char *)(iVar2 + -0x4c) = *(char *)(iVar2 + -0x4c) + param_2;
  *(char *)(iVar2 + -0x746f6f70) = *(char *)(iVar2 + -0x746f6f70) + param_2;
  puVar3 = (undefined4 *)(CONCAT31((int3)((uint)iVar2 >> 8),cVar1) & 0xffffff04);
  *puVar3 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 **)(param_1 + 0x10) = puVar3;
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  return;
}

// --------------------------------------------------

// Function: log_map_call
// Address: 0053d150
// XREFS: explore_all, explore_terrain, explore_terrain_sq, set_all, unexplore_terrain, unexplore_terrain_sq
void __cdecl
log_map_call(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9)
{
  int iVar1;
  
  iVar1 = VCALL_LOG_HEAD + 1;
  if (iVar1 < 0x400) {
    if ((-1 < VCALL_LOG_TAIL) && (VCALL_LOG_TAIL = VCALL_LOG_HEAD + 2, 0x3ff < VCALL_LOG_TAIL)) {
      VCALL_LOG_TAIL = 0;
    }
  }
  else {
    iVar1 = 0;
    VCALL_LOG_TAIL = 1;
  }
  VCALL_LOG_HEAD = iVar1;
  (&VCALL_LOG)[iVar1 * 9] = (VC_LOG *)param_1;
  (&DAT_0087d80c)[iVar1 * 9] = param_2;
  (&DAT_0087d810)[iVar1 * 9] = param_3;
  (&DAT_0087d814)[iVar1 * 9] = param_4;
  (&DAT_0087d818)[iVar1 * 9] = param_5;
  (&DAT_0087d81c)[iVar1 * 9] = param_6;
  (&DAT_0087d820)[iVar1 * 9] = param_7;
  (&DAT_0087d824)[iVar1 * 9] = param_8;
  (&DAT_0087d828)[iVar1 * 9] = param_9;
  return;
}

// --------------------------------------------------

// Function: dump_vismap_log
// Address: 0053d200
// XREFS: action_user_command, do_command_game, quit_game, ~RGE_Base_Game
// [HELPER] s_EXPLORE_ALL_: "EXPLORE ALL "
// [HELPER] s_EXPLORE_SQ__: "EXPLORE SQ  "
// [HELPER] s_EXPLORE_____: "EXPLORE     "
// [HELPER] s_NULL_LOG_: "NULL LOG\n"
// [HELPER] s_SET_ALL_____: "SET ALL     "
// [HELPER] s_UNEXPLORE_SQ: "UNEXPLORE SQ"
// [HELPER] s_UNEXPLORE___: "UNEXPLORE   "
// [HELPER] s__ERROR__Undef_Action____d_: "*ERROR* Undef Action = %d "
// [HELPER] s__wt____d__plyr____d__id____d__x1: " wt = %d, plyr = %d, id = %d, x1=%d, y1=%d, x2=%d, y2=%d, s=%d\n"
// [HELPER] s_c__aoeexlog_txt: "c:\aoeexlog.txt"
// [HELPER] s_w: "w"
void __cdecl dump_vismap_log(void)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  bVar1 = false;
  uVar2 = fopen(s_c__aoeexlog_txt,s_w);
  if (-1 < VCALL_LOG_HEAD) {
    iVar3 = VCALL_LOG_TAIL;
    if (VCALL_LOG_TAIL < 0) {
      iVar3 = 0;
    }
    do {
      switch((&DAT_0087d810)[iVar3 * 9]) {
      case 1:
        fprintf(uVar2,s_EXPLORE_____);
        break;
      case 2:
        fprintf(uVar2,s_EXPLORE_SQ__);
        break;
      case 3:
        fprintf(uVar2,s_UNEXPLORE___);
        break;
      case 4:
        fprintf(uVar2,s_UNEXPLORE_SQ);
        break;
      case 5:
        fprintf(uVar2,s_SET_ALL_____);
        break;
      case 6:
        fprintf(uVar2,s_EXPLORE_ALL_);
        break;
      default:
        fprintf(uVar2,s__ERROR__Undef_Action____d_,(&DAT_0087d810)[iVar3 * 9]);
      }
      fprintf(uVar2,s__wt____d__plyr____d__id____d__x1,(&VCALL_LOG)[iVar3 * 9],
              (&DAT_0087d80c)[iVar3 * 9],(&DAT_0087d814)[iVar3 * 9],(&DAT_0087d818)[iVar3 * 9],
              (&DAT_0087d81c)[iVar3 * 9],(&DAT_0087d820)[iVar3 * 9],(&DAT_0087d824)[iVar3 * 9],
              (&DAT_0087d828)[iVar3 * 9]);
      if (iVar3 == VCALL_LOG_HEAD) {
        bVar1 = true;
      }
      iVar3 = iVar3 + 1;
      if (0x3ff < iVar3) {
        iVar3 = 0;
      }
    } while (!bVar1);
    fclose(uVar2);
    return;
  }
  fprintf(uVar2,s_NULL_LOG_);
  fclose(uVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_0053e7b3
// Address: 0053e7b3
// XREFS: None
undefined4 __fastcall
FUN_0053e7b3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  byte bVar6;
  int *piVar7;
  TPanel *this;
  byte *pbVar8;
  byte *unaff_EBX;
  int unaff_EDI;
  undefined4 unaff_retaddr;
  
  pbVar8 = (byte *)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(0xe4,(char)param_2));
  bVar6 = (byte)param_1;
  uVar3 = in(0x53);
  *(char *)(unaff_EDI + 0x380053e5) = *(char *)(unaff_EDI + 0x380053e5) + (char)unaff_EBX;
  out(0x53,(char)uVar3);
  piVar7 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),
                           CONCAT11((char)((uint)param_1 >> 8) + -0x38,bVar6));
  in(0x53);
  pbVar8[-0x60ffac1d] = pbVar8[-0x60ffac1d] - 0x1c;
  pbVar4 = (byte *)in(0x53);
  *unaff_EBX = *unaff_EBX + (char)param_2;
  bVar2 = (byte)pbVar4;
  out(0x53,bVar2);
  unaff_EBX[0x53e7] = unaff_EBX[0x53e7] + bVar2;
  *piVar7 = (int)(pbVar4 + *piVar7);
  *pbVar4 = *pbVar4 | bVar6;
  *pbVar4 = *pbVar4 | bVar6;
  *pbVar8 = *pbVar8 | bVar2;
  this = (TPanel *)CONCAT31((int3)((uint)piVar7 >> 8),bVar6 + *pbVar4);
  *pbVar4 = *pbVar4 | bVar6 + *pbVar4;
  *unaff_EBX = *unaff_EBX | bVar2;
  pbVar4[-0x6ff8f7fa] = pbVar4[-0x6ff8f7fa] | bVar2;
  iVar5 = rge_base_game->prog_mode;
  if ((((iVar5 != 4) && (iVar5 != 6)) && (iVar5 != 7)) && (iVar5 != 5)) {
    return 0;
  }
  iVar5 = RGE_Base_Game::get_paused(rge_base_game);
  cVar1 = (char)this[1].tab_stop;
  if (iVar5 == 0) {
    if (cVar1 != '\0') {
      (**(code **)(this->_padding_ + 0xec))(unaff_retaddr,param_3);
      return 1;
    }
    switch(rge_base_game->game_mode) {
    case 0:
      TPanel::release_mouse(this);
      iVar5 = this->_padding_;
      (**(code **)(iVar5 + 0xe8))(2,this->mouse_down_x,this->mouse_down_y,param_4,param_5);
      (**(code **)(iVar5 + 0xec))(param_4,param_5);
      return 1;
    case 1:
    case 7:
    case 8:
      (**(code **)(this->_padding_ + 0x20))(1);
    }
    return 1;
  }
  if (cVar1 != '\0') {
    (**(code **)(this->_padding_ + 0xf0))();
    return 0;
  }
  TPanel::release_mouse(this);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053e8e9
// Address: 0053e8e9
// XREFS: None
void FUN_0053e8e9(void)
{
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_0054627a
// Address: 0054627a
// XREFS: None
// [HELPER] s__8_8x: "%8.8x"
// [HELPER] s___: "]\n"
// [HELPER] s___RemoveVisibleBits____: "  RemoveVisibleBits = ["
// [HELPER] s___allied_LOS_Enable____d___allie: "  allied_LOS_Enable = %d   allied_victory = %d \n"
// [HELPER] s___mutualExploredMask____8_8x___m: "  mutualExploredMask = %8.8x   mutualVisibleMask = %8.8x   nonMutualVisibleMa..."
// [HELPER] s___mututalAlly____: "  mututalAlly = ["
// [HELPER] s___unitDiplomacy____: "  unitDiplomacy = ["
// [HELPER] s__d: "%d"
// [HELPER] s_player__d_: "player %d\n"
// [HELPER] s_updating_player_visibilites___wt: "updating player visibilites @ wt=%d\n"
void FUN_0054627a(void)
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined1 *puStack0000001c;
  int in_stack_00000024;
  undefined4 in_stack_0000002c;
  undefined1 *puStack00000034;
  int iStack00000038;
  char cStack0000003c;
  undefined4 in_stack_00000044;
  int in_stack_0000004c;
  undefined1 *in_stack_00000050;
  undefined4 in_stack_000000a8;
  _iobuf *in_stack_000000ac;
  char *pcStack000000b0;
  char *pcStack000000b4;
  char *pcStack000000b8;
  char *pcStack000000bc;
  undefined1 *puStack000000c0;
  undefined4 *puStack000000c4;
  undefined4 uStack000000c8;
  undefined4 uStack000000cc;
  int in_stack_000000d0;
  int in_stack_000000d4;
  undefined4 in_stack_000000d8;
  undefined2 in_stack_000000dc;
  
  iVar3 = in_stack_0000004c;
  uStack000000c8 = _cStack0000003c;
  puStack0000001c = &stack0x00000020;
  puStack000000c4 = (undefined4 *)&stack0x0000003c;
  puStack00000034 = (undefined1 *)&stack0x00000038;
  puStack000000c0 = (undefined1 *)&stack0x00000038;
  *(char *)(in_stack_00000024 + 0x62) =
       *(char *)(in_stack_00000024 + 0x62) + (char)in_stack_0000002c;
  cStack0000003c = cStack0000003c + (char)in_stack_00000050;
  iStack00000038 = (int)&stack0x0000003c + (int)in_stack_00000050;
  uStack000000cc = in_stack_00000044;
  pcStack000000bc = *(char **)(in_stack_0000004c + 4);
  pcStack000000b8 = s_updating_player_visibilites___wt;
  pcStack000000b4 = (char *)DVlogf;
  pcStack000000b0 = (char *)0x5462ee;
  in_stack_00000050 = &stack0x00000054;
  fprintf();
  iVar8 = 0;
  if (0 < *(short *)(iVar3 + 0x3c)) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xd0) = 0;
      *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xd4) = 0;
      iVar4 = 0xdc;
      *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xd8) = 0;
      do {
        iVar4 = iVar4 + 4;
        *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + -4 + iVar4) = 0;
      } while (iVar4 < 0x100);
      puVar5 = (undefined4 *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xac);
      iVar4 = 0;
      do {
        if (iVar4 == iVar8) {
          *puVar5 = 1;
          *(int *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xd4) = 1 << ((byte)iVar8 & 0x1f);
          *(int *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xd0) =
               1 << ((byte)iVar8 + 0x10 & 0x1f);
        }
        else {
          *puVar5 = 0;
        }
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar4 < 9);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(short *)(iVar3 + 0x3c));
  }
  iVar8 = (int)*(short *)(iVar3 + 0x3c);
  iVar4 = 1;
  if (1 < iVar8) {
    do {
      if ((*(int *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar4 * 4) + 0x100) == 1) &&
         (iVar6 = 1, 1 < iVar8)) {
        do {
          if (iVar6 != iVar4) {
            iVar8 = *(int *)(*(int *)(iVar3 + 0x40) + iVar4 * 4);
            if ((*(char *)(*(int *)(iVar8 + 0x84) + iVar6) == '\0') &&
               (*(char *)(*(int *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar6 * 4) + 0x84) + iVar4) ==
                '\0')) {
              *(undefined4 *)(iVar8 + 0xac + iVar6 * 4) = 1;
              iVar8 = *(int *)(*(int *)(iVar3 + 0x40) + iVar4 * 4);
              *(uint *)(iVar8 + 0xd4) = *(uint *)(iVar8 + 0xd4) | 1 << ((byte)iVar6 & 0x1f);
              puVar1 = (uint *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar4 * 4) + 0xd0);
              *puVar1 = *puVar1 | 1 << ((byte)iVar6 + 0x10 & 0x1f);
            }
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(short *)(iVar3 + 0x3c));
      }
      iVar8 = (int)*(short *)(iVar3 + 0x3c);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar8);
  }
  iVar8 = (int)*(short *)(iVar3 + 0x3c);
  in_stack_000000d4 = 0;
  if (0 < iVar8) {
    iVar4 = 0;
    do {
      in_stack_000000d0 = 1;
      if (1 < iVar8) {
        iVar6 = 0xe0;
        do {
          if (((in_stack_000000d0 != in_stack_000000d4) &&
              (*(int *)(*(int *)(iVar4 + *(int *)(iVar3 + 0x40)) + -0x30 + iVar6) == 0)) &&
             (iVar9 = 1, 1 < iVar8)) {
            do {
              iVar8 = *(int *)(iVar3 + 0x40);
              if (((*(int *)(*(int *)(iVar4 + iVar8) + 0xac + iVar9 * 4) == 0) &&
                  (iVar2 = *(int *)(iVar8 + iVar9 * 4), *(int *)(iVar6 + -0x30 + iVar2) == 1)) &&
                 (*(int *)(iVar4 + 0xac + iVar2) == 1)) {
                in_stack_000000d8 = 1;
                *(uint *)(*(int *)(iVar4 + iVar8) + 0xd8) =
                     *(uint *)(*(int *)(iVar4 + iVar8) + 0xd8) |
                     1 << ((byte)in_stack_000000d0 & 0x1f);
                puVar1 = (uint *)(*(int *)(iVar4 + *(int *)(iVar3 + 0x40)) + iVar6);
                *puVar1 = *puVar1 | 1 << ((byte)iVar9 & 0x1f);
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 < *(short *)(iVar3 + 0x3c));
          }
          iVar8 = (int)*(short *)(iVar3 + 0x3c);
          in_stack_000000d0 = in_stack_000000d0 + 1;
          iVar6 = iVar6 + 4;
        } while (in_stack_000000d0 < iVar8);
      }
      iVar8 = (int)*(short *)(iVar3 + 0x3c);
      in_stack_000000d4 = in_stack_000000d4 + 1;
      iVar4 = iVar4 + 4;
    } while (in_stack_000000d4 < iVar8);
  }
  iVar8 = 0;
  if (0 < *(short *)(iVar3 + 0x3c)) {
    iVar4 = 0;
    do {
      pcStack000000b8 = s_player__d_;
      pcStack000000b4 = (char *)DVlogf;
      pcStack000000b0 = (char *)0x546531;
      pcStack000000bc = (char *)iVar8;
      fprintf();
      iVar6 = *(int *)(iVar4 + *(int *)(iVar3 + 0x40));
      pcStack000000bc = *(char **)(iVar6 + 0xd8);
      pcStack000000b8 = *(char **)(iVar6 + 0xd4);
      pcStack000000b4 = *(char **)(iVar6 + 0xd0);
      pcStack000000b0 = s___mutualExploredMask____8_8x___m;
      in_stack_000000ac = DVlogf;
      in_stack_000000a8 = 0x546560;
      fprintf();
      iVar6 = *(int *)(iVar4 + *(int *)(iVar3 + 0x40));
      pcStack000000bc = (char *)(uint)*(byte *)(iVar6 + 0x104);
      pcStack000000b8 = *(char **)(iVar6 + 0x100);
      pcStack000000b4 = s___allied_LOS_Enable____d___allie;
      pcStack000000b0 = (char *)DVlogf;
      in_stack_000000ac = (_iobuf *)0x546589;
      fprintf();
      pcStack000000bc = s___unitDiplomacy____;
      pcStack000000b8 = (char *)DVlogf;
      pcStack000000b4 = (char *)0x54659d;
      fprintf();
      iVar6 = 0x88;
      do {
        pcStack000000bc = *(char **)(*(int *)(iVar4 + *(int *)(iVar3 + 0x40)) + iVar6);
        pcStack000000b8 = (char *)&s__d;
        pcStack000000b4 = (char *)DVlogf;
        pcStack000000b0 = (char *)0x5465c0;
        fprintf();
        if (iVar6 < 0xa8) {
          pcStack000000bc = s___;
        }
        else {
          pcStack000000bc = s___;
        }
        pcStack000000b8 = (char *)DVlogf;
        pcStack000000b4 = (char *)0x5465e9;
        fprintf();
        iVar6 = iVar6 + 4;
      } while (iVar6 < 0xac);
      pcStack000000bc = s___mututalAlly____;
      pcStack000000b8 = (char *)DVlogf;
      pcStack000000b4 = (char *)0x546608;
      fprintf();
      iVar6 = 0xac;
      do {
        pcStack000000bc = *(char **)(*(int *)(iVar4 + *(int *)(iVar3 + 0x40)) + iVar6);
        pcStack000000b8 = (char *)&s__d;
        pcStack000000b4 = (char *)DVlogf;
        pcStack000000b0 = (char *)0x54662a;
        fprintf();
        if (iVar6 < 0xcc) {
          pcStack000000bc = s___;
        }
        else {
          pcStack000000bc = s___;
        }
        pcStack000000b8 = (char *)DVlogf;
        pcStack000000b4 = (char *)0x546654;
        fprintf();
        iVar6 = iVar6 + 4;
      } while (iVar6 < 0xd0);
      pcStack000000bc = s___RemoveVisibleBits____;
      pcStack000000b8 = (char *)DVlogf;
      pcStack000000b4 = (char *)0x546672;
      fprintf();
      iVar6 = 0xdc;
      do {
        pcStack000000bc = *(char **)(*(int *)(iVar4 + *(int *)(iVar3 + 0x40)) + iVar6);
        pcStack000000b8 = s__8_8x;
        pcStack000000b4 = (char *)DVlogf;
        pcStack000000b0 = (char *)0x546695;
        fprintf();
        if (iVar6 < 0xfc) {
          pcStack000000bc = s___;
        }
        else {
          pcStack000000bc = s___;
        }
        pcStack000000b8 = (char *)DVlogf;
        pcStack000000b4 = (char *)0x5466be;
        fprintf();
        iVar6 = iVar6 + 4;
      } while (iVar6 < 0x100);
      iVar8 = iVar8 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar8 < *(short *)(iVar3 + 0x3c));
  }
  pcStack000000bc = (char *)0x5466e7;
  piVar7 = (int *)(**(code **)(rge_base_game->_padding_ + 0x2c))();
  if (piVar7 != (int *)0x0) {
    pcStack000000bc = (char *)0x2;
    pcStack000000b8 = (char *)0x5466f4;
    (**(code **)(*piVar7 + 0x20))();
  }
  pcStack000000bc = (char *)0x5466ff;
  piVar7 = (int *)(**(code **)(rge_base_game->_padding_ + 0x30))();
  if (piVar7 != (int *)0x0) {
    pcStack000000bc = (char *)0x2;
    pcStack000000b8 = (char *)0x54670c;
    (**(code **)(*piVar7 + 0x20))();
  }
  return;
}

// --------------------------------------------------

// Function: zone_pop
// Address: 00546720
// XREFS: do_zone_map_area
uchar __cdecl zone_pop(Zone_Queue **param_1,Zone_Queue **param_2,long *param_3,long *param_4)
{
  Zone_Queue *pZVar1;
  
  pZVar1 = *param_1;
  if (pZVar1 == (Zone_Queue *)0x0) {
    return '\0';
  }
  *param_3 = pZVar1->x;
  *param_4 = pZVar1->y;
  *param_1 = pZVar1->next;
  free(pZVar1);
  if (*param_1 == (Zone_Queue *)0x0) {
    *param_2 = (Zone_Queue *)0x0;
  }
  return '\x01';
}

// --------------------------------------------------

// Function: zone_push
// Address: 00546770
// XREFS: do_zone_map_area
void __cdecl zone_push(Zone_Queue **param_1,Zone_Queue **param_2,long param_3,long param_4)
{
  Zone_Queue *pZVar1;
  
  pZVar1 = (Zone_Queue *)calloc(1,0xc);
  if (*param_2 != (Zone_Queue *)0x0) {
    (*param_2)->next = pZVar1;
  }
  pZVar1->x = param_3;
  pZVar1->y = param_4;
  *param_2 = pZVar1;
  if (*param_1 == (Zone_Queue *)0x0) {
    *param_1 = pZVar1;
  }
  return;
}

// --------------------------------------------------

// Function: _VerQueryValueA@16
// Address: 00547530
// XREFS: IsDPlay501a
void _VerQueryValueA_16(void)
{
  VerQueryValueA();
  return;
}

// --------------------------------------------------

// Function: _GetFileVersionInfoA@16
// Address: 00547536
// XREFS: IsDPlay501a
void _GetFileVersionInfoA_16(void)
{
  GetFileVersionInfoA();
  return;
}

// --------------------------------------------------

