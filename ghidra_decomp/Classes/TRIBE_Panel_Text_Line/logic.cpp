// Class: TRIBE_Panel_Text_Line
// Function: TRIBE_Panel_Text_Line
// Address: 00520d70
/* public: __thiscall TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line(class TDrawArea *,class TPanel
   *,void *) */

TRIBE_Panel_Text_Line * __thiscall
TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line
          (TRIBE_Panel_Text_Line *this,TDrawArea *param_1,TPanel *param_2,void *param_3)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561548;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TPanel::TPanel((TPanel *)this);
  this->font = param_3;
  local_4 = 0;
  this->text_type = '\0';
  this->text[0] = '\0';
  this->id = 0;
  this->_padding_ = (int)&_vftable_;
  lVar1 = TPanel::setup((TPanel *)this,param_1,param_2,0,0,0,0,'\0');
  if (lVar1 == 0) {
    this->_padding_ = 1;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00520e00
/* public: virtual void * __thiscall TRIBE_Panel_Text_Line::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TRIBE_Panel_Text_Line::_scalar_deleting_destructor_(TRIBE_Panel_Text_Line *this,uint param_1)
{
  ~TRIBE_Panel_Text_Line(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Panel_Text_Line
// Address: 00520e20
/* public: virtual __thiscall TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line(void) */

void __thiscall TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line(TRIBE_Panel_Text_Line *this)
{
  int iVar1;
  char *pcVar2;
  
  this->_padding_ = (int)&TPanel::_vftable_;
  TPanel::release_mouse((TPanel *)this);
  if (this->_padding_ != 0) {
    iVar1 = TPanelSystem::inSystem(&panel_system,(TPanel *)this);
    if (iVar1 != 0) {
      pcVar2 = TPanel::panelName((TPanel *)this);
      TPanelSystem::removePanel(&panel_system,pcVar2);
    }
  }
  if ((PanelNode *)this->_padding_ != (PanelNode *)0x0) {
    if ((TPanel *)this->_padding_ != (TPanel *)0x0) {
      TPanel::remove_panel_node((TPanel *)this->_padding_,(PanelNode *)this->_padding_);
    }
    free(this->_padding_);
    this->_padding_ = 0;
  }
  this->_padding_ = 0;
  if (this->_padding_ != 0) {
    DeleteObject(this->_padding_);
    this->_padding_ = 0;
  }
  if ((int *)this->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)this->_padding_ + 0x20))(2);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  return;
}

// --------------------------------------------------

// Function: set_info
// Address: 00520e30
/* public: void __thiscall TRIBE_Panel_Text_Line::set_info(unsigned char,char *,long) */

void __thiscall
TRIBE_Panel_Text_Line::set_info
          (TRIBE_Panel_Text_Line *this,uchar param_1,char *param_2,long param_3)
{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  
  if (param_1 == this->text_type) {
    pcVar7 = this->text;
    pbVar3 = (byte *)param_2;
    do {
      bVar2 = *pbVar3;
      bVar9 = bVar2 < (byte)*pcVar7;
      if (bVar2 != *pcVar7) {
LAB_00520e74:
        iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_00520e79;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar9 = bVar2 < (byte)pcVar7[1];
      if (bVar2 != pcVar7[1]) goto LAB_00520e74;
      pbVar3 = pbVar3 + 2;
      pcVar7 = pcVar7 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_00520e79:
    if ((iVar4 == 0) && (param_3 == this->id)) {
      return;
    }
  }
  uVar5 = 0xffffffff;
  this->text_type = param_1;
  do {
    pcVar7 = param_2;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar7;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar4 = this->_padding_;
  pcVar7 = pcVar7 + -uVar5;
  pcVar8 = this->text;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  this->id = param_3;
  (**(code **)(iVar4 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 00520ed0
// [HELPER] s_tpnl_txl__draw: "tpnl_txl::draw"
/* public: virtual void __thiscall TRIBE_Panel_Text_Line::draw(void) */

void __thiscall TRIBE_Panel_Text_Line::draw(TRIBE_Panel_Text_Line *this)
{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_ESI;
  char *pcVar5;
  int iVar6;
  
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 0x34))(&this->_padding_);
    }
    iVar6 = this->_padding_;
    (**(code **)(iVar6 + 0x28))(0);
    pvVar2 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_txl__draw);
    if (pvVar2 != (void *)0x0) {
      uVar3 = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->font);
      SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
      SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0);
      if (this->text[0] != '\0') {
        uVar4 = 0xffffffff;
        pcVar5 = this->text;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_,this->_padding_,this->text,
                 ~uVar4 - 1);
        iVar6 = unaff_ESI;
      }
      SelectObject(*(undefined4 *)(this->_padding_ + 0x38),uVar3);
      TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_txl__draw);
    }
    (**(code **)(iVar6 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

