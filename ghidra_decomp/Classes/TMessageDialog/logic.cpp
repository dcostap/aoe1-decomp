// Class: TMessageDialog
// Function: TMessageDialog
// Address: 0043fc70
/* public: __thiscall TMessageDialog::TMessageDialog(char *) */

TMessageDialog * __thiscall TMessageDialog::TMessageDialog(TMessageDialog *this,char *param_1)
{
  TDialogPanel::TDialogPanel((TDialogPanel *)this,param_1);
  this->dlg_type = '\0';
  this->text = (TTextPanel *)0x0;
  this->_padding_ = (int)&_vftable_;
  this->button[0] = (TButtonPanel *)0x0;
  this->button[1] = (TButtonPanel *)0x0;
  this->button[2] = (TButtonPanel *)0x0;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0043fcb0
/* public: virtual void * __thiscall TMessageDialog::`scalar deleting destructor'(unsigned int) */

void * __thiscall TMessageDialog::_scalar_deleting_destructor_(TMessageDialog *this,uint param_1)
{
  ~TMessageDialog(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TMessageDialog
// Address: 0043fcd0
/* public: virtual __thiscall TMessageDialog::~TMessageDialog(void) */

void __thiscall TMessageDialog::~TMessageDialog(TMessageDialog *this)
{
  TButtonPanel **ppTVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055d198;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->text != (TTextPanel *)0x0) {
    (**(code **)this->text->_padding_)(1);
  }
  ppTVar1 = this->button;
  iVar2 = 3;
  do {
    if (*ppTVar1 != (TButtonPanel *)0x0) {
      (**(code **)(*ppTVar1)->_padding_)(1);
    }
    ppTVar1 = ppTVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel((TDialogPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 0043fd50
// [HELPER] s_: ""
/* public: long __thiscall TMessageDialog::setup(class TPanel *,char *,long,long,long,unsigned
   char,char *,long,long) */

long __thiscall
TMessageDialog::setup
          (TMessageDialog *this,TPanel *param_1,char *param_2,long param_3,long param_4,long param_5
          ,uchar param_6,char *param_7,long param_8,long param_9)
{
  TDrawArea *pTVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  TButtonPanel *pTVar6;
  TButtonPanel **ppTVar7;
  undefined4 unaff_EBP;
  int unaff_ESI;
  long lVar8;
  int iVar9;
  code *pcVar10;
  int iVar11;
  
  iVar11 = 1;
  this->button[0] = (TButtonPanel *)0x0;
  this->button[1] = (TButtonPanel *)0x0;
  this->button[2] = (TButtonPanel *)0x0;
  pTVar1 = TPanel::renderArea(param_1);
  iVar11 = TDialogPanel::setup((TDialogPanel *)this,pTVar1,param_1,param_4,param_5,param_2,param_3,
                               iVar11);
  if (iVar11 == 0) {
switchD_0043fdf0_default:
    return 0;
  }
  iVar11 = this->_padding_;
  this->dlg_type = param_6;
  iVar2 = (**(code **)(iVar11 + 0x100))
                    (this,&this->text,param_7,3,3,this->_padding_ + -3,
                     (this->_padding_ - param_9) + -6,0xb,1,1,1);
  if (iVar2 == 0) {
    return 0;
  }
  switch(this->dlg_type) {
  case '\0':
    iVar2 = 1;
    break;
  case '\x01':
  case '\x02':
  case '\x03':
    iVar2 = 2;
    break;
  case '\x04':
    iVar2 = 3;
    break;
  default:
    goto switchD_0043fdf0_default;
  }
  iVar3 = this->_padding_ - iVar2 * unaff_ESI;
  if (iVar3 < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = iVar3 / (iVar2 + 1);
  }
  iVar4 = (this->_padding_ - param_9) + -7;
  iVar9 = 0;
  if (iVar2 != 0) {
    pcVar10 = *(code **)(iVar11 + 0xec);
    ppTVar7 = this->button;
    iVar11 = iVar3;
    do {
      iVar5 = (*pcVar10)(this,ppTVar7,s_,s_,iVar3,iVar4,unaff_ESI,unaff_EBP,0xb,0,0);
      if (iVar5 == 0) {
        return 0;
      }
      ppTVar7 = ppTVar7 + 1;
      iVar3 = iVar3 + iVar11 + unaff_ESI;
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar2);
  }
  switch(this->dlg_type) {
  case '\0':
                    /* language.dll match for 0xfa1: "OK" */
    TButtonPanel::set_text(this->button[0],0,0xfa1);
    goto switchD_0043fec6_default;
  case '\x01':
                    /* language.dll match for 0xfa1: "OK" */
    TButtonPanel::set_text(this->button[0],0,0xfa1);
    lVar8 = 0xfa2;
    break;
  case '\x02':
                    /* language.dll match for 0xfa3: "Yes" */
    TButtonPanel::set_text(this->button[0],0,0xfa3);
    lVar8 = 0xfa4;
    break;
  case '\x03':
                    /* language.dll match for 0xfa5: "Retry" */
    TButtonPanel::set_text(this->button[0],0,0xfa5);
                    /* language.dll match for 0xfa7: "Abort" */
    lVar8 = 0xfa7;
    break;
  case '\x04':
                    /* language.dll match for 0xfa3: "Yes" */
    TButtonPanel::set_text(this->button[0],0,0xfa3);
                    /* language.dll match for 0xfa4: "No" */
    TButtonPanel::set_text(this->button[1],0,0xfa4);
                    /* language.dll match for 0xfa2: "Cancel" */
    TButtonPanel::set_text(this->button[2],0,0xfa2);
    pTVar6 = this->button[2];
    goto LAB_0043ff7e;
  default:
    goto switchD_0043fec6_default;
  }
  TButtonPanel::set_text(this->button[1],0,lVar8);
  pTVar6 = this->button[1];
LAB_0043ff7e:
  pTVar6->hotkey = 0x1b;
  pTVar6->hotkey_shift = 0;
switchD_0043fec6_default:
  (**(code **)(this->_padding_ + 200))(this->button,iVar2);
  TPanel::set_curr_child((TPanel *)this,(TPanel *)this->button[0]);
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0043fff0
/* WARNING: Variable defined which should be unmapped: str */
/* public: long __thiscall TMessageDialog::setup(class TPanel *,char *,long,long,long,unsigned
   char,int,long,long) */

long __thiscall
TMessageDialog::setup
          (TMessageDialog *this,TPanel *param_1,char *param_2,long param_3,long param_4,long param_5
          ,uchar param_6,int param_7,long param_8,long param_9)
{
  long lVar1;
  char str [256];
  
  TPanel::get_string((TPanel *)this,param_7,str + 4,0x100);
  lVar1 = setup(this,param_1,param_2,param_3,param_4,param_5,param_6,str + 4,param_8,param_9);
  return lVar1;
}

// --------------------------------------------------

// Function: action
// Address: 00440070
/* public: virtual long __thiscall TMessageDialog::action(class TPanel *,long,unsigned long,unsigned
   long) */

long __thiscall
TMessageDialog::action
          (TMessageDialog *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  int *piVar1;
  long lVar2;
  
  piVar1 = (int *)this->_padding_;
  if ((piVar1 != (int *)0x0) && (param_2 == 1)) {
    if ((TButtonPanel *)param_1 == this->button[0]) {
      (**(code **)(*piVar1 + 0xb4))(this,0,0,0);
      return 1;
    }
    if ((TButtonPanel *)param_1 == this->button[1]) {
      (**(code **)(*piVar1 + 0xb4))(this,1,0,0);
      return 1;
    }
    if ((TButtonPanel *)param_1 == this->button[2]) {
      (**(code **)(*piVar1 + 0xb4))(this,2,0,0);
      return 1;
    }
  }
  lVar2 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar2;
}

// --------------------------------------------------

// Function: key_down_action
// Address: 00440100
/* public: virtual long __thiscall TMessageDialog::key_down_action(long,short,int,int,int) */

long __thiscall
TMessageDialog::key_down_action
          (TMessageDialog *this,long param_1,short param_2,int param_3,int param_4,int param_5)
{
  return 0;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 00440110
/* public: virtual long __thiscall TMessageDialog::handle_idle(void) */

long __thiscall TMessageDialog::handle_idle(TMessageDialog *this)
{
  long lVar1;
  
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  lVar1 = TPanel::handle_idle((TPanel *)this);
  return lVar1;
}

// --------------------------------------------------

