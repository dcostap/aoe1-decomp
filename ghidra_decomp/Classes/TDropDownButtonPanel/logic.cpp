// Class: TDropDownButtonPanel
// Function: TDropDownButtonPanel
// Address: 00475470
/* public: __thiscall TDropDownButtonPanel::TDropDownButtonPanel(class TDropDownPanel *) */

TDropDownButtonPanel * __thiscall
TDropDownButtonPanel::TDropDownButtonPanel(TDropDownButtonPanel *this,TDropDownPanel *param_1)
{
  TButtonPanel::TButtonPanel((TButtonPanel *)this);
  this->_padding_ = (int)&_vftable_;
  this->drop_down_panel = param_1;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00475490
/* public: virtual void * __thiscall TDropDownButtonPanel::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
TDropDownButtonPanel::_vector_deleting_destructor_(TDropDownButtonPanel *this,uint param_1)
{
  ~TDropDownButtonPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TDropDownButtonPanel
// Address: 004754b0
/* public: virtual __thiscall TDropDownButtonPanel::~TDropDownButtonPanel(void) */

void __thiscall TDropDownButtonPanel::~TDropDownButtonPanel(TDropDownButtonPanel *this)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 9;
  this->_padding_ = (int)&TButtonPanel::_vftable_;
  piVar2 = &this->_padding_;
  do {
    if (piVar2[-9] != 0) {
      free(piVar2[-9]);
      piVar2[-9] = 0;
    }
    if (*piVar2 != 0) {
      free(*piVar2);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (this->_padding_ != 0) {
    free(this->_padding_);
    this->_padding_ = 0;
  }
  TPanel::~TPanel((TPanel *)this);
  return;
}

// --------------------------------------------------

// Function: handle_mouse_move
// Address: 004754c0
/* public: virtual long __thiscall TDropDownButtonPanel::handle_mouse_move(long,long,int,int) */

long __thiscall
TDropDownButtonPanel::handle_mouse_move
          (TDropDownButtonPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined4 unaff_EBP;
  undefined4 unaff_EDI;
  
  if (this->_padding_ != 0) {
    iVar1 = (**(code **)(this->drop_down_panel->list_panel->_padding_ + 0xbc))(param_1,param_2);
    if (iVar1 != 0) {
      (**(code **)(this->_padding_ + 0x78))(1,param_1,param_2,param_1,param_2);
      lVar2 = (**(code **)(this->drop_down_panel->list_panel->_padding_ + 0x70))
                        (1,param_1,param_2,unaff_EDI,param_2);
      return lVar2;
    }
    iVar1 = (**(code **)(this->drop_down_panel->scbar_panel->_padding_ + 0xbc))(param_1,param_2);
    if (iVar1 != 0) {
      (**(code **)(this->_padding_ + 0x78))(1,param_1,param_2,param_3,param_4);
      lVar2 = TPanel::width((TPanel *)this->drop_down_panel->list_panel);
      lVar3 = TPanel::xPosition((TPanel *)this->drop_down_panel->list_panel);
      lVar2 = (**(code **)(this->drop_down_panel->list_panel->_padding_ + 0x70))
                        (1,lVar2 + -1 + lVar3,param_2,unaff_EBP,param_4);
      return lVar2;
    }
  }
  lVar2 = TPanel::handle_mouse_move((TPanel *)this,param_1,param_2,param_3,param_4);
  return lVar2;
}

// --------------------------------------------------

