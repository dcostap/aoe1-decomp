// Class: THelpDialog
// Function: THelpDialog
// Address: 0043e840
// [HELPER] s_Help_Dialog: "Help Dialog"
/* public: __thiscall THelpDialog::THelpDialog(class TEasy_Panel *,char *,long,long,long,long) */

THelpDialog * __thiscall
THelpDialog::THelpDialog
          (THelpDialog *this,TEasy_Panel *param_1,char *param_2,long param_3,long param_4,
          long param_5,long param_6)
{
  char *pcVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d088;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TDialogPanel::TDialogPanel((TDialogPanel *)this,s_Help_Dialog);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  pcVar1 = TPanel::get_string((TPanel *)this,param_3);
  setup_help(this,param_1,param_2,pcVar1,param_4,param_5,param_6);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0043e8c0
/* public: virtual void * __thiscall THelpDialog::`scalar deleting destructor'(unsigned int) */

void * __thiscall THelpDialog::_scalar_deleting_destructor_(THelpDialog *this,uint param_1)
{
  ~THelpDialog(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: THelpDialog
// Address: 0043e8e0
// [HELPER] s_Help_Dialog: "Help Dialog"
/* public: __thiscall THelpDialog::THelpDialog(class TEasy_Panel *,char *,char *,long,long,long) */

THelpDialog * __thiscall
THelpDialog::THelpDialog
          (THelpDialog *this,TEasy_Panel *param_1,char *param_2,char *param_3,long param_4,
          long param_5,long param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d0a8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TDialogPanel::TDialogPanel((TDialogPanel *)this,s_Help_Dialog);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  setup_help(this,param_1,param_2,param_3,param_4,param_5,param_6);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~THelpDialog
// Address: 0043e950
/* public: virtual __thiscall THelpDialog::~THelpDialog(void) */

void __thiscall THelpDialog::~THelpDialog(THelpDialog *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055d0c8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->ok_button != (TButtonPanel *)0x0) {
    (**(code **)this->ok_button->_padding_)(1);
  }
  if (this->encyclopedia_button != (TButtonPanel *)0x0) {
    (**(code **)this->encyclopedia_button->_padding_)(1);
  }
  if (this->list != (TTextPanel *)0x0) {
    (**(code **)this->list->_padding_)(1);
  }
  if (this->title != (TTextPanel *)0x0) {
    (**(code **)this->title->_padding_)(1);
  }
  local_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel((TDialogPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: setup_help
// Address: 0043e9e0
/* WARNING: Variable defined which should be unmapped: rge_text_font */
/* protected: void __thiscall THelpDialog::setup_help(class TEasy_Panel *,char *,char
   *,long,long,long) */

void __thiscall
THelpDialog::setup_help
          (THelpDialog *this,TEasy_Panel *param_1,char *param_2,char *param_3,long param_4,
          long param_5,long param_6)
{
  TTextPanel **ppTVar1;
  TButtonPanel **ppTVar2;
  char cVar3;
  TButtonPanel *pTVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  undefined4 uVar14;
  TButtonPanel *pTStack_a4;
  TButtonPanel *pTStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  RGE_Font *rge_text_font;
  TPanel *tabList [2];
  
  ppTVar1 = &this->list;
  uVar11 = 0xffffffff;
  this->ok_button = (TButtonPanel *)0x0;
  this->encyclopedia_button = (TButtonPanel *)0x0;
  this->title = (TTextPanel *)0x0;
  *ppTVar1 = (TTextPanel *)0x0;
  do {
    pcVar10 = param_2;
    if (uVar11 == 0) break;
    uVar11 = uVar11 - 1;
    pcVar10 = param_2 + 1;
    cVar3 = *param_2;
    param_2 = pcVar10;
  } while (cVar3 != '\0');
  uVar11 = ~uVar11;
  pcVar10 = pcVar10 + -uVar11;
  pcVar13 = this->parent_panel;
  for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
    *pcVar13 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar13 = pcVar13 + 1;
  }
  this->help_page_id = param_4;
  RGE_Base_Game::get_font(rge_base_game,0xb);
  iVar6 = this->_padding_;
  TEasy_Panel::get_popup_info_id(param_1);
  TEasy_Panel::get_popup_info_file(param_1);
  TPanel::renderArea((TPanel *)param_1);
  iVar5 = (**(code **)(iVar6 + 300))();
  if (iVar5 != 0) {
    (**(code **)(iVar6 + 0x100))();
    iVar5 = (*ppTVar1)->bot_line + 2;
    iVar6 = iVar5 * iRam00000012;
    lVar7 = TPanel::width((TPanel *)param_1);
    lVar8 = TPanel::xPosition((TPanel *)param_1);
    if (lVar7 + lVar8 < (int)(param_1->info_file_name + 0x67)) {
      lVar7 = TPanel::xPosition((TPanel *)param_1);
      if ((int)((int)&param_1[-1].use_bevels + 3) < lVar7 + 10) {
        TPanel::width((TPanel *)param_1);
      }
      else {
        TPanel::xPosition((TPanel *)param_1);
      }
    }
    else {
      TPanel::xPosition((TPanel *)param_1);
    }
    lVar7 = TPanel::yPosition((TPanel *)param_1);
    if (0x14a - (iVar6 + 0x37) < lVar7) {
      lVar7 = TPanel::height((TPanel *)param_1);
      lVar8 = TPanel::yPosition((TPanel *)param_1);
      if (lVar7 + lVar8 < iVar6 + 0x195) {
        TPanel::height((TPanel *)param_1);
      }
      else {
        TPanel::yPosition((TPanel *)param_1);
      }
    }
    else {
      TPanel::yPosition((TPanel *)param_1);
    }
    iVar6 = this->_padding_;
    (**(code **)(iVar6 + 0x1c))();
    (**(code **)(iVar6 + 0xe4))();
    (**(code **)(this->list->_padding_ + 0x1c))();
    iVar9 = RGE_Base_Game::singlePlayerGame(rge_base_game);
    if ((iVar9 != 0) && (-1 < (int)ppTVar1)) {
      uStack_94 = 0x43ec61;
      pcVar10 = TPanel::get_string((TPanel *)this,(int)ppTVar1);
      if ((pcVar10 != (char *)0x0) && (*pcVar10 != '\0')) {
        uStack_94 = 0;
        uStack_98 = 0xb;
        uStack_9c = 0x19;
        pTStack_a4 = (TButtonPanel *)(iVar5 * iRam0000015c + 0x14);
        pTStack_a0 = (TButtonPanel *)0x78;
                    /* language.dll match for 0x243d: "More Help" */
        (**(code **)(iVar6 + 0xe8))(this,&this->encyclopedia_button,0x243d,0,0x19);
      }
    }
    uStack_94 = 0;
    uStack_98 = 0xb;
    uStack_9c = 0x19;
    pTStack_a0 = (TButtonPanel *)0x78;
    if (this->encyclopedia_button == (TButtonPanel *)0x0) {
      uVar14 = 0x6e;
    }
    else {
      uVar14 = 0xc3;
    }
    pTStack_a4 = (TButtonPanel *)(iVar5 * iRam0000015c + 0x14);
    ppTVar2 = &this->ok_button;
                    /* language.dll match for 0xfa1: "OK" */
    (**(code **)(iVar6 + 0xe8))(this,ppTVar2,0xfa1,0,uVar14);
    pTVar4 = *ppTVar2;
    pTVar4->hotkey = 0x1b;
    pTVar4->hotkey_shift = 0;
    TPanel::set_curr_child((TPanel *)this,(TPanel *)*ppTVar2);
    pTStack_a4 = *ppTVar2;
    uVar14 = 1;
    if (this->encyclopedia_button != (TButtonPanel *)0x0) {
      uVar14 = 2;
      pTStack_a0 = this->encyclopedia_button;
    }
    (**(code **)(iVar6 + 200))(&pTStack_a4,uVar14);
  }
  return;
}

// --------------------------------------------------

// Function: action
// Address: 0043ed40
// [HELPER] s_Help_Dialog: "Help Dialog"
// [HELPER] s_empires_hlp: "empires.hlp"
/* public: virtual long __thiscall THelpDialog::action(class TPanel *,long,unsigned long,unsigned
   long) */

long __thiscall
THelpDialog::action(THelpDialog *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  int iVar1;
  void *pvVar2;
  char *pcVar3;
  long lVar4;
  
  iVar1 = this->help_page_id;
  if (param_2 == 1) {
    if ((TButtonPanel *)param_1 == this->ok_button) {
      TPanelSystem::setCurrentPanel(&panel_system,this->parent_panel,0);
      TPanelSystem::destroyPanel(&panel_system,s_Help_Dialog);
      return 1;
    }
    if ((TButtonPanel *)param_1 == this->encyclopedia_button) {
      TPanelSystem::setCurrentPanel(&panel_system,this->parent_panel,0);
      TPanelSystem::destroyPanel(&panel_system,s_Help_Dialog);
      pvVar2 = rge_base_game->prog_window;
      pcVar3 = TPanel::get_string((TPanel *)this,iVar1);
      WinHelpA(pvVar2,s_empires_hlp,0x101,pcVar3);
      return 1;
    }
  }
  lVar4 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar4;
}

// --------------------------------------------------

// Function: handle_mouse_down
// Address: 0043ee10
/* public: virtual long __thiscall THelpDialog::handle_mouse_down(unsigned char,long,long,int,int)
    */

long __thiscall
THelpDialog::handle_mouse_down
          (THelpDialog *this,uchar param_1,long param_2,long param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  long lVar3;
  uchar unaff_BL;
  
  iVar1 = this->_padding_;
  iVar2 = (**(code **)(iVar1 + 0xbc))(param_2,param_3);
  if (iVar2 == 0) {
    (**(code **)(iVar1 + 0xb4))(this->ok_button,1,0,0);
    return 1;
  }
  lVar3 = TEasy_Panel::handle_mouse_down
                    ((TEasy_Panel *)this,unaff_BL,param_2,param_3,param_2,param_3);
  return lVar3;
}

// --------------------------------------------------

