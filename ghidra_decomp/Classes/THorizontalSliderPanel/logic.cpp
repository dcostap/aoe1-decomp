// Class: THorizontalSliderPanel
// Function: THorizontalSliderPanel
// Address: 0047bdf0
/* public: __thiscall THorizontalSliderPanel::THorizontalSliderPanel(void) */

THorizontalSliderPanel * __thiscall
THorizontalSliderPanel::THorizontalSliderPanel(THorizontalSliderPanel *this)
{
  TVerticalSliderPanel::TVerticalSliderPanel((TVerticalSliderPanel *)this);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0047be10
/* public: virtual void * __thiscall THorizontalSliderPanel::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
THorizontalSliderPanel::_scalar_deleting_destructor_(THorizontalSliderPanel *this,uint param_1)
{
  ~THorizontalSliderPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~THorizontalSliderPanel
// Address: 0047be30
/* public: virtual __thiscall THorizontalSliderPanel::~THorizontalSliderPanel(void) */

void __thiscall THorizontalSliderPanel::~THorizontalSliderPanel(THorizontalSliderPanel *this)
{
  *(undefined ***)this = &_vftable_;
  TVerticalSliderPanel::~TVerticalSliderPanel((TVerticalSliderPanel *)this);
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 0047be40
/* public: long __thiscall THorizontalSliderPanel::setup(class TDrawArea *,class TPanel
   *,long,long,long,long,char *,char *,long,long,long,long,int,int) */

long __thiscall
THorizontalSliderPanel::setup
          (THorizontalSliderPanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4
          ,long param_5,long param_6,char *param_7,char *param_8,long param_9,long param_10,
          long param_11,long param_12,int param_13,int param_14)
{
  long lVar1;
  
  *(int *)&this->field_0x1c4 = param_13;
  *(int *)&this->field_0x1c8 = param_14;
  lVar1 = TScrollBarPanel::setup
                    ((TScrollBarPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,param_7
                     ,(char *)0x0,(char *)0x0,param_8,0,param_9,(TPanel *)0x0,param_10,Horizontal);
  if (lVar1 == 0) {
    return 0;
  }
  *(long *)&this->field_0xfc = param_11;
  *(long *)&this->field_0x100 = param_12;
  return 1;
}

// --------------------------------------------------

// Function: set_rect
// Address: 0047bec0
/* public: virtual void __thiscall THorizontalSliderPanel::set_rect(long,long,long,long) */

void __thiscall
THorizontalSliderPanel::set_rect
          (THorizontalSliderPanel *this,long param_1,long param_2,long param_3,long param_4)
{
  int iVar1;
  int iVar2;
  
  TScrollBarPanel::set_rect((TScrollBarPanel *)this,param_1,param_2,param_3,param_4);
  iVar2 = *(int *)&this->field_0xc;
  *(int *)&this->field_0x164 = iVar2;
  *(int *)&this->field_0x16c = iVar2;
  iVar1 = *(int *)&this->field_0x14 + -1 + iVar2;
  *(int *)&this->field_0x174 = iVar1;
  *(int *)&this->field_0x17c = iVar1;
  *(int *)&this->field_0x138 = iVar2 + 1;
  *(int *)&this->field_0x134 = iVar2 + 1;
  *(int *)&this->field_0x13c = (iVar1 - *(int *)&this->field_0x18) + 2;
  TScrollBarPanel::calc_item_rects((TScrollBarPanel *)this);
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0047bf30
// [HELPER] s_pnl_scbr__draw: "pnl_scbr::draw"
/* public: virtual void __thiscall THorizontalSliderPanel::draw(void) */

void __thiscall THorizontalSliderPanel::draw(THorizontalSliderPanel *this)
{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  
  if (*(int **)&this->field_0x40 != (int *)0x0) {
    (**(code **)(**(int **)&this->field_0x40 + 0x3c))(&this->field_0x24);
  }
  iVar1 = *(int *)this;
  (**(code **)(iVar1 + 0x28))(0);
  puVar2 = TDrawArea::Lock(*(TDrawArea **)&this->field_0x20,s_pnl_scbr__draw,1);
  if (puVar2 != (uchar *)0x0) {
    TScrollBarPanel::draw_back_pic((TScrollBarPanel *)this);
    TScrollBarPanel::draw_border((TScrollBarPanel *)this,0,1,(tagRECT *)&this->field_0x8c);
    if ((*(int *)&this->field_0x168 != *(int *)&this->field_0x170) &&
       (*(int *)&this->field_0x164 != *(int *)&this->field_0x16c)) {
      if ((this->field_0x144 == '\x01') && (*(int *)&this->field_0x148 != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic
                ((TScrollBarPanel *)this,*(int *)&this->field_0x110,iVar3,
                 (tagRECT *)&this->field_0x164);
      if ((this->field_0x144 == '\x01') && (*(int *)&this->field_0x148 != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,iVar3,(tagRECT *)&this->field_0x164);
    }
    if ((*(int *)&this->field_0x178 != *(int *)&this->field_0x180) &&
       (*(int *)&this->field_0x174 != *(int *)&this->field_0x17c)) {
      if ((this->field_0x144 == '\x02') && (*(int *)&this->field_0x148 != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic
                ((TScrollBarPanel *)this,*(int *)&this->field_0x114,iVar3,
                 (tagRECT *)&this->field_0x174);
      if ((this->field_0x144 == '\x02') && (*(int *)&this->field_0x148 != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,iVar3,(tagRECT *)&this->field_0x174);
    }
    TScrollBarPanel::draw_button_pic
              ((TScrollBarPanel *)this,*(int *)&this->field_0x118,0,(tagRECT *)&this->field_0x184);
    TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,0,(tagRECT *)&this->field_0x184);
    TDrawArea::Unlock(*(TDrawArea **)&this->field_0x20,s_pnl_scbr__draw);
  }
  (**(code **)(iVar1 + 0x2c))();
  return;
}

// --------------------------------------------------

