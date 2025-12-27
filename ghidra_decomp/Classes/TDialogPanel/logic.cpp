// Class: TDialogPanel
// Function: TDialogPanel
// Address: 00473c10
/* public: __thiscall TDialogPanel::TDialogPanel(char *) */

TDialogPanel * __thiscall TDialogPanel::TDialogPanel(TDialogPanel *this,char *param_1)
{
  TEasy_Panel::TEasy_Panel((TEasy_Panel *)this,param_1);
  this->text_font_id = 0xb;
  this->input_font_id = 0xb;
  this->button_font_id = 0xb;
  this->dlg_wnd = (void *)0x0;
  this->save_parent_child = (TPanel *)0x0;
  this->button_sound_id = 0;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00473c60
/* public: virtual void * __thiscall TDialogPanel::`vector deleting destructor'(unsigned int) */

void * __thiscall TDialogPanel::_vector_deleting_destructor_(TDialogPanel *this,uint param_1)
{
  ~TDialogPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: setup
// Address: 00473c80
/* public: virtual int __thiscall TDialogPanel::setup(class TDrawArea *,class TPanel
   *,long,long,char *,long,int) */

int __thiscall
TDialogPanel::setup(TDialogPanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
                   char *param_5,long param_6,int param_7)
{
  TPanel *this_00;
  int iVar1;
  int iVar2;
  long lVar3;
  
  if (param_2 == (TPanel *)0x0) {
    iVar1 = param_1->Width;
    iVar2 = param_1->Height;
  }
  else {
    iVar1 = TPanel::width(param_2);
    iVar2 = TPanel::height(param_2);
    TPanel::xPosition(param_2);
    TPanel::yPosition(param_2);
  }
  lVar3 = TEasy_Panel::setup((TEasy_Panel *)this,param_1,param_2,param_5,param_6,0,
                             iVar1 / 2 - param_3 / 2,iVar2 / 2 - param_4 / 2,param_3,param_4,param_7
                            );
  if (lVar3 == 0) {
    this->_padding_ = 1;
    return 0;
  }
  this_00 = (TPanel *)this->_padding_;
  if (this_00 != (TPanel *)0x0) {
    this->save_parent_child = this_00->curr_child;
    TPanel::set_curr_child(this_00,(TPanel *)this);
  }
  TPanel::set_z_order((TPanel *)this,'\x01',0);
  TPanelSystem::setModalPanel(&panel_system,(TPanel *)this);
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00473d60
/* public: virtual int __thiscall TDialogPanel::setup(class TDrawArea *,class TPanel
   *,long,long,unsigned char,int) */

int __thiscall
TDialogPanel::setup(TDialogPanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
                   uchar param_5,int param_6)
{
  TPanel *this_00;
  int iVar1;
  int iVar2;
  long lVar3;
  undefined3 in_stack_00000015;
  
  if (param_2 == (TPanel *)0x0) {
    iVar1 = param_1->Width;
    iVar2 = param_1->Height;
  }
  else {
    iVar1 = TPanel::width(param_2);
    iVar2 = TPanel::height(param_2);
  }
  lVar3 = TEasy_Panel::setup((TEasy_Panel *)this,param_1,param_2,(char *)0x0,-1,0,
                             iVar1 / 2 - param_3 / 2,iVar2 / 2 - param_4 / 2,param_3,param_4,param_6
                            );
  if (lVar3 == 0) {
    this->_padding_ = 1;
    return 0;
  }
  (**(code **)(this->_padding_ + 0x10))(_param_5);
  TPanel::set_z_order((TPanel *)this,'\x01',0);
  TPanelSystem::setModalPanel(&panel_system,(TPanel *)this);
  this_00 = (TPanel *)this->_padding_;
  if (this_00 != (TPanel *)0x0) {
    this->save_parent_child = this_00->curr_child;
    TPanel::set_curr_child(this_00,(TPanel *)this);
  }
  return 1;
}

// --------------------------------------------------

// Function: ~TDialogPanel
// Address: 00473e40
/* public: virtual __thiscall TDialogPanel::~TDialogPanel(void) */

void __thiscall TDialogPanel::~TDialogPanel(TDialogPanel *this)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055e3e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  iVar1 = TPanelSystem::restorePreviousModalPanel(&panel_system);
  if (iVar1 == 0) {
    TPanelSystem::setModalPanel(&panel_system,(TPanel *)0x0);
  }
  if ((int *)this->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)this->_padding_ + 0x20))(2);
    TPanel::set_curr_child((TPanel *)this->_padding_,this->save_parent_child);
  }
  local_4 = 0xffffffff;
  TEasy_Panel::~TEasy_Panel((TEasy_Panel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: set_focus
// Address: 00473ec0
/* public: virtual void __thiscall TDialogPanel::set_focus(int) */

void __thiscall TDialogPanel::set_focus(TDialogPanel *this,int param_1)
{
  TEasy_Panel::set_focus((TEasy_Panel *)this,param_1);
  return;
}

// --------------------------------------------------

