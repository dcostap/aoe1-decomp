// Class: TribeSendQuickMessageDialog
// Function: TribeSendQuickMessageDialog
// Address: 00441530
// [HELPER] s_: ""
// [HELPER] s_Send_Quick_Message_Dialog: "Send Quick Message Dialog"
/* public: __thiscall TribeSendQuickMessageDialog::TribeSendQuickMessageDialog(class TScreenPanel
   *,enum TribeSendQuickMessageDialog::Mode) */

TribeSendQuickMessageDialog * __thiscall
TribeSendQuickMessageDialog::TribeSendQuickMessageDialog
          (TribeSendQuickMessageDialog *this,TScreenPanel *param_1,Mode param_2)
{
  long lVar1;
  char *pcVar2;
  TDrawArea *pTVar3;
  undefined4 *unaff_FS_OFFSET;
  long lVar4;
  long lVar5;
  int iVar6;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d258;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TDialogPanel::TDialogPanel((TDialogPanel *)this,s_Send_Quick_Message_Dialog);
  iVar6 = 1;
  local_4 = 0;
  this->modeValue = param_2;
  this->_padding_ = (int)&_vftable_;
  lVar1 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)param_1);
  pcVar2 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)param_1);
  lVar5 = 0x23;
  lVar4 = 0x21c;
  pTVar3 = TPanel::renderArea((TPanel *)param_1);
  iVar6 = TDialogPanel::setup((TDialogPanel *)this,pTVar3,(TPanel *)param_1,lVar4,lVar5,pcVar2,lVar1
                              ,iVar6);
  if (iVar6 != 0) {
                    /* language.dll match for 0x78: "10" */
    iVar6 = TEasy_Panel::create_text
                      ((TEasy_Panel *)this,(TPanel *)this,&this->chatTitle,
                       (-(uint)(this->modeValue != AsChat) & 5) + 0x2668,5,5,0x78,0x19,4,1,1,0);
    if (iVar6 != 0) {
                    /* language.dll match for 0x82: "B" */
      iVar6 = TEasy_Panel::create_edit
                        ((TEasy_Panel *)this,(TPanel *)this,&this->chatInput,s_,0x41,FormatText,0x82
                         ,5,0x195,0x19,0xb,1,0);
      if (iVar6 != 0) {
        TPanel::set_curr_child((TPanel *)this,(TPanel *)this->chatInput);
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00441630
/* public: virtual void * __thiscall TribeSendQuickMessageDialog::`vector deleting
   destructor'(unsigned int) */

void * __thiscall
TribeSendQuickMessageDialog::_vector_deleting_destructor_
          (TribeSendQuickMessageDialog *this,uint param_1)
{
  ~TribeSendQuickMessageDialog(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeSendQuickMessageDialog
// Address: 00441650
/* public: virtual __thiscall TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog(void) */

void __thiscall
TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog(TribeSendQuickMessageDialog *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055d278;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->chatInput != (TEditPanel *)0x0) {
    (**(code **)this->chatInput->_padding_)(1);
  }
  if (this->chatTitle != (TTextPanel *)0x0) {
    (**(code **)this->chatTitle->_padding_)(1);
  }
  local_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel((TDialogPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 004416c0
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Send_Quick_Message_Dialog: "Send Quick Message Dialog"
/* WARNING: Variable defined which should be unmapped: save_msg */
/* public: virtual long __thiscall TribeSendQuickMessageDialog::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TribeSendQuickMessageDialog::action
          (TribeSendQuickMessageDialog *this,TPanel *param_1,long param_2,ulong param_3,
          ulong param_4)
{
  char cVar1;
  TRIBE_Screen_Game *this_00;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char save_msg [66];
  
  if ((param_1 != (TPanel *)0x0) && ((TEditPanel *)param_1 == this->chatInput)) {
    if (param_2 == 0) {
      pcVar2 = TEditPanel::currentLine(this->chatInput);
      if ((pcVar2 != (char *)0x0) &&
         (pcVar2 = TEditPanel::currentLine(this->chatInput), *pcVar2 != '\0')) {
        this_00 = (TRIBE_Screen_Game *)this->_padding_;
        pcVar3 = TEditPanel::currentLine(this->chatInput);
        uVar6 = 0xffffffff;
        pcVar2 = save_msg;
        do {
          pcVar8 = pcVar3;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar8 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar8;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        pcVar3 = pcVar8 + -uVar6;
        for (uVar7 = uVar6 >> 2; pcVar2 = pcVar2 + 4, uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar2 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar2 = pcVar2 + 1;
        }
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Send_Quick_Message_Dialog);
        iVar4 = (**(code **)(rge_base_game->_padding_ + 0x54))
                          ((int)rge_base_game->world->curr_player,save_msg + 4);
        if (iVar4 != 0) {
          return 1;
        }
        iVar4 = RGE_Base_Game::multiplayerGame(rge_base_game);
        if (iVar4 == 0) {
          RGE_Base_Game::play_sound(rge_base_game,2);
          TRIBE_Screen_Game::display_system_message(this_00,&stack0xffffffb4);
          return 1;
        }
        if (rge_base_game->prog_mode == 5) {
          return 1;
        }
        TCommunications_Handler::SendGroupChatMsg(comm,&stack0xffffffb4);
        return 1;
      }
    }
    else if (param_2 != 1) goto LAB_00441819;
    TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
    TPanelSystem::destroyPanel(&panel_system,s_Send_Quick_Message_Dialog);
    return 1;
  }
LAB_00441819:
  lVar5 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar5;
}

// --------------------------------------------------

// Function: handle_mouse_down
// Address: 00441840
/* public: virtual long __thiscall TribeSendQuickMessageDialog::handle_mouse_down(unsigned
   char,long,long,int,int) */

long __thiscall
TribeSendQuickMessageDialog::handle_mouse_down
          (TribeSendQuickMessageDialog *this,uchar param_1,long param_2,long param_3,int param_4,
          int param_5)
{
  int iVar1;
  int iVar2;
  long lVar3;
  uchar unaff_BL;
  
  iVar1 = this->_padding_;
  iVar2 = (**(code **)(iVar1 + 0xbc))(param_2,param_3);
  if (iVar2 == 0) {
    (**(code **)(iVar1 + 0xb4))(this->chatInput,1,0,0);
    return 1;
  }
  lVar3 = TEasy_Panel::handle_mouse_down
                    ((TEasy_Panel *)this,unaff_BL,param_2,param_3,param_2,param_3);
  return lVar3;
}

// --------------------------------------------------

