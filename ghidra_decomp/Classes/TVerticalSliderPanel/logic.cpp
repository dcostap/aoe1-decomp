// Class: TVerticalSliderPanel
// Function: TVerticalSliderPanel
// Address: 0047bce0
/* public: __thiscall TVerticalSliderPanel::TVerticalSliderPanel(void) */

TVerticalSliderPanel * __thiscall
TVerticalSliderPanel::TVerticalSliderPanel(TVerticalSliderPanel *this)
{
  TScrollBarPanel::TScrollBarPanel((TScrollBarPanel *)this);
  this->drawBox = 1;
  this->spineWidth = 0;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0047bd10
/* public: virtual void * __thiscall TVerticalSliderPanel::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TVerticalSliderPanel::_scalar_deleting_destructor_(TVerticalSliderPanel *this,uint param_1)
{
  ~TVerticalSliderPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TVerticalSliderPanel
// Address: 0047bd30
/* public: virtual __thiscall TVerticalSliderPanel::~TVerticalSliderPanel(void) */

void __thiscall TVerticalSliderPanel::~TVerticalSliderPanel(TVerticalSliderPanel *this)
{
  this->_padding_ = (int)&_vftable_;
  TScrollBarPanel::~TScrollBarPanel((TScrollBarPanel *)this);
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 0047bd40
/* public: long __thiscall TVerticalSliderPanel::setup(class TDrawArea *,class TPanel
   *,long,long,long,long,char *,char *,long,long,long,long,int,int) */

long __thiscall
TVerticalSliderPanel::setup
          (TVerticalSliderPanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
          long param_5,long param_6,char *param_7,char *param_8,long param_9,long param_10,
          long param_11,long param_12,int param_13,int param_14)
{
  long lVar1;
  
  this->drawBox = param_13;
  this->spineWidth = param_14;
  lVar1 = TScrollBarPanel::setup
                    ((TScrollBarPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,param_7
                     ,(char *)0x0,(char *)0x0,param_8,0,param_9,(TPanel *)0x0,param_10,Vertical);
  if (lVar1 == 0) {
    return 0;
  }
  this->_padding_ = param_11;
  this->_padding_ = param_12;
  return 1;
}

// --------------------------------------------------

// Function: set_rect
// Address: 0047bdc0
/* public: virtual void __thiscall TVerticalSliderPanel::set_rect(long,long,long,long) */

void __thiscall
TVerticalSliderPanel::set_rect
          (TVerticalSliderPanel *this,long param_1,long param_2,long param_3,long param_4)
{
  TScrollBarPanel::set_rect((TScrollBarPanel *)this,param_1,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0047bde0
// [HELPER] s_pnl_scbr__draw: "pnl_scbr::draw"
/* public: virtual void __thiscall TVerticalSliderPanel::draw(void) */

void __thiscall TVerticalSliderPanel::draw(TVerticalSliderPanel *this)
{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  
  if ((int *)this->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)this->_padding_ + 0x3c))(&this->_padding_);
  }
  iVar1 = this->_padding_;
  (**(code **)(iVar1 + 0x28))(0);
  puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_pnl_scbr__draw,1);
  if (puVar2 != (uchar *)0x0) {
    TScrollBarPanel::draw_back_pic((TScrollBarPanel *)this);
    TScrollBarPanel::draw_border((TScrollBarPanel *)this,0,1,(tagRECT *)&this->_padding_);
    if ((this->_padding_ != this->_padding_) && (this->_padding_ != this->_padding_)) {
      if (((char)this->_padding_ == '\x01') && (this->_padding_ != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic
                ((TScrollBarPanel *)this,this->_padding_,iVar3,(tagRECT *)&this->_padding_);
      if (((char)this->_padding_ == '\x01') && (this->_padding_ != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,iVar3,(tagRECT *)&this->_padding_);
    }
    if ((this->_padding_ != this->_padding_) && (this->_padding_ != this->_padding_)) {
      if (((char)this->_padding_ == '\x02') && (this->_padding_ != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic
                ((TScrollBarPanel *)this,this->_padding_,iVar3,(tagRECT *)&this->_padding_);
      if (((char)this->_padding_ == '\x02') && (this->_padding_ != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,iVar3,(tagRECT *)&this->_padding_);
    }
    TScrollBarPanel::draw_button_pic
              ((TScrollBarPanel *)this,this->_padding_,0,(tagRECT *)&this->_padding_);
    TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,0,(tagRECT *)&this->_padding_);
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_pnl_scbr__draw);
  }
  (**(code **)(iVar1 + 0x2c))();
  return;
}

// --------------------------------------------------

