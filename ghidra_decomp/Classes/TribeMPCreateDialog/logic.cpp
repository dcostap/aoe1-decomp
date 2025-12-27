// Class: TribeMPCreateDialog
// Function: TribeMPCreateDialog
// Address: 004920c0
// [HELPER] s_Create_Dialog: "Create Dialog"
// [HELPER] s_Default_Age_Of_Empires_MP_Gamena: "Default Age Of Empires MP Gamename"
/* WARNING: Variable defined which should be unmapped: tab_list */
/* public: __thiscall TribeMPCreateDialog::TribeMPCreateDialog(class TPanel *) */

TribeMPCreateDialog * __thiscall
TribeMPCreateDialog::TribeMPCreateDialog(TribeMPCreateDialog *this,TPanel *param_1)
{
  TEditPanel **ppTVar1;
  char cVar2;
  TButtonPanel *pTVar3;
  long lVar4;
  char *pcVar5;
  TDrawArea *pTVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 *unaff_FS_OFFSET;
  long lVar11;
  long lVar12;
  int iVar13;
  TPanel *tab_list [3];
  char str [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055ea5b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  str._0_4_ = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)this,s_Create_Dialog);
  ppTVar1 = &this->inputGamename;
  iVar13 = 1;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->title = (TTextPanel *)0x0;
  this->input_title = (TTextPanel *)0x0;
  *ppTVar1 = (TEditPanel *)0x0;
  this->okButton = (TButtonPanel *)0x0;
  this->cancelButton = (TButtonPanel *)0x0;
  lVar4 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)param_1);
  pcVar5 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)param_1);
  lVar12 = 0xe6;
  lVar11 = 500;
  pTVar6 = TPanel::renderArea(param_1);
  iVar13 = TDialogPanel::setup((TDialogPanel *)this,pTVar6,param_1,lVar11,lVar12,pcVar5,lVar4,iVar13
                              );
                    /* language.dll match for 0x25a6: "Create Game" */
                    /* language.dll match for 0x25aa: "Game Name" */
  if (((iVar13 != 0) &&
      (iVar13 = TEasy_Panel::create_text
                          ((TEasy_Panel *)this,(TPanel *)this,&this->title,0x25a6,0x14,0x14,0x1cc,
                           0x1e,1,1,1,0), iVar13 != 0)) &&
     (iVar13 = TEasy_Panel::create_text
                         ((TEasy_Panel *)this,(TPanel *)this,&this->input_title,0x25aa,0x28,0x55,
                          0x1a4,0x14,4,0,1,0), iVar13 != 0)) {
    pcVar5 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_MP_Gamena);
    if (pcVar5 == (char *)0x0) {
      str[4] = '\0';
    }
    else {
      pcVar7 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_MP_Gamena);
      uVar8 = 0xffffffff;
      pcVar5 = str;
      do {
        pcVar10 = pcVar7;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar10 = pcVar7 + 1;
        cVar2 = *pcVar7;
        pcVar7 = pcVar10;
      } while (cVar2 != '\0');
      uVar8 = ~uVar8;
      pcVar7 = pcVar10 + -uVar8;
      for (uVar9 = uVar8 >> 2; pcVar5 = pcVar5 + 4, uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar5 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar5 = pcVar5 + 1;
      }
    }
                    /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    iVar13 = TEasy_Panel::create_edit
                       ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,str + 4,0x28,FormatText,0x28,0x6e
                        ,0x1a4,0x17,0xb,1,0);
    if (iVar13 != 0) {
                    /* language.dll match for 0xfa1: "OK" */
      iVar13 = TEasy_Panel::create_button
                         ((TEasy_Panel *)this,(TPanel *)this,&this->okButton,0xfa1,0,0x3c,0xb4,0xb4,
                          0x1e,0,0,0);
      if (iVar13 != 0) {
                    /* language.dll match for 0xfa2: "Cancel" */
        iVar13 = TEasy_Panel::create_button
                           ((TEasy_Panel *)this,(TPanel *)this,&this->cancelButton,0xfa2,0,0x104,
                            0xb4,0xb4,0x1e,0,0,0);
        if (iVar13 != 0) {
          pTVar3 = this->cancelButton;
          pTVar3->hotkey = 0x1b;
          pTVar3->hotkey_shift = 0;
          tab_list[1] = (TPanel *)*ppTVar1;
          tab_list[2] = (TPanel *)this->okButton;
          TPanel::set_tab_order((TPanel *)this,tab_list + 1,3);
          TPanel::set_curr_child((TPanel *)this,(TPanel *)*ppTVar1);
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00492310
/* public: virtual void * __thiscall TribeMPCreateDialog::`vector deleting destructor'(unsigned int)
    */

void * __thiscall
TribeMPCreateDialog::_vector_deleting_destructor_(TribeMPCreateDialog *this,uint param_1)
{
  ~TribeMPCreateDialog(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeMPCreateDialog
// Address: 00492330
/* public: virtual __thiscall TribeMPCreateDialog::~TribeMPCreateDialog(void) */

void __thiscall TribeMPCreateDialog::~TribeMPCreateDialog(TribeMPCreateDialog *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055ea78;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->input_title);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->inputGamename);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->okButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->cancelButton);
  local_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel((TDialogPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 004923c0
// [HELPER] s_Create_Dialog: "Create Dialog"
// [HELPER] s_Default_Age_Of_Empires_MP_Gamena: "Default Age Of Empires MP Gamename"
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s_____CALLING_CreateMultiplayerGam: "$$$ CALLING CreateMultiplayerGame"
// [HELPER] s_____RETURNED_FROM_CreateMultipla: "$$$ RETURNED FROM CreateMultiplayerGame"
// [HELPER] s_closedpw: "closedpw"
// [HELPER] s_data_closedpw_exe: "data\closedpw.exe"
// [HELPER] s_scr3: "scr3"
/* protected: virtual long __thiscall TribeMPCreateDialog::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TribeMPCreateDialog::action
          (TribeMPCreateDialog *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  char cVar1;
  int *piVar2;
  TEasy_Panel *this_00;
  int iVar3;
  long lVar4;
  char *pcVar5;
  uchar *puVar6;
  int iVar7;
  TribeMPSetupScreen *this_01;
  uint uVar8;
  ulong *puVar9;
  undefined4 *unaff_FS_OFFSET;
  bool bVar10;
  ulong local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ea9b;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 != (TPanel *)0x0) {
    if ((((TButtonPanel *)param_1 == this->okButton) && (param_2 == 1)) ||
       (((TEditPanel *)param_1 == this->inputGamename && (param_2 == 0)))) {
      iVar3 = TEditPanel::is_blank(this->inputGamename);
      if (iVar3 == 0) {
        RGE_Base_Game::disable_input(rge_base_game);
        pcVar5 = TEditPanel::currentLine(this->inputGamename);
        uVar8 = 0xffffffff;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        uVar8 = ~uVar8;
        puVar6 = (uchar *)TEditPanel::currentLine(this->inputGamename);
        TRegistry::RegSetAscii(Regs,1,s_Default_Age_Of_Empires_MP_Gamena,puVar6,uVar8);
        pcVar5 = TEditPanel::currentLine(this->inputGamename);
        TCommunications_Handler::SetGameTitle(comm,pcVar5);
        piVar2 = (int *)this->_padding_;
        TDebuggingLog::Log(L,(char *)L,s_____CALLING_CreateMultiplayerGam);
        TPanelSystem::setCurrentPanel(&panel_system,s_Join_Screen,0);
        RGE_Base_Game::draw_window(rge_base_game);
        local_1c = (comm->ServiceGUID).Data1;
        local_18._0_2_ = (comm->ServiceGUID).Data2;
        local_18._2_2_ = (comm->ServiceGUID).Data3;
        local_14 = *(undefined4 *)(comm->ServiceGUID).Data4;
        bVar10 = true;
        local_10 = *(undefined4 *)((comm->ServiceGUID).Data4 + 4);
        iVar3 = 0x10;
        puVar9 = &local_1c;
        pcVar5 = &_DPSPGUID_TCPIP;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar10 = (char)*puVar9 == *pcVar5;
          puVar9 = (ulong *)((int)puVar9 + 1);
          pcVar5 = pcVar5 + 1;
        } while (bVar10);
        if (bVar10) {
          iVar3 = 0x4c3;
        }
        else {
                    /* language.dll match for 0x4c2: "Creating multiplayer game...\\n\\n\\n\\nPlease
                       press ESC if the game is not\\ncreated within 15 seconds." */
          iVar3 = 0x4c2;
        }
        TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,iVar3,&s_scr3,0xc385);
        RGE_Base_Game::draw_window(rge_base_game);
        WinExec(s_data_closedpw_exe,0);
        iVar3 = *piVar2;
        if ((*(char *)(iVar3 + 0x478) == '\x02') && (*(char *)(iVar3 + 0x479) == '\x02')) {
          (**(code **)(**(int **)(iVar3 + 0x18) + 0x28))(*(int **)(iVar3 + 0x18));
        }
        puVar9 = comm->PlayerStopTurn;
        for (iVar3 = 9; puVar9 = puVar9 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar9 = 0;
        }
        iVar3 = TCommunications_Handler::CreateMultiplayerGame(comm);
        TDebuggingLog::Log(L,(char *)L,s_____RETURNED_FROM_CreateMultipla);
        iVar7 = FindWindowA(s_closedpw,s_closedpw);
        if (iVar7 != 0) {
          SendMessageA(iVar7,0x10,0,0);
        }
        if (iVar3 == 0) {
          this_00 = (TEasy_Panel *)this->_padding_;
          TPanelSystem::destroyPanel(&panel_system,s_Create_Dialog);
          TPanelSystem::setCurrentPanel(&panel_system,s_Join_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
                    /* language.dll match for 0x25ad: "Unable to create game. For TCP/IP games, you
                       may need to connect to the Internet before starting Age of Empires." */
          TEasy_Panel::popupOKDialog(this_00,0x25ad,(char *)0x0,0x1c2,100);
          lVar4 = 1;
        }
        else {
          this_01 = (TribeMPSetupScreen *)operator_new(0x890);
          uStack_4 = 0;
          if (this_01 != (TribeMPSetupScreen *)0x0) {
            TribeMPSetupScreen::TribeMPSetupScreen(this_01);
          }
          uStack_4 = 0xffffffff;
          TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
          TPanelSystem::destroyPanel(&panel_system,s_Create_Dialog);
          TPanelSystem::destroyPanel(&panel_system,s_Join_Screen);
          lVar4 = 1;
        }
      }
      else {
        TPanel::set_curr_child((TPanel *)this,(TPanel *)this->inputGamename);
        lVar4 = 1;
      }
      goto LAB_004926c1;
    }
    if ((((TButtonPanel *)param_1 == this->cancelButton) && (param_2 == 1)) ||
       (((TEditPanel *)param_1 == this->inputGamename && (param_2 == 1)))) {
      TPanelSystem::setCurrentPanel(&panel_system,s_Join_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Create_Dialog);
      lVar4 = 1;
      goto LAB_004926c1;
    }
  }
  lVar4 = TPanel::action((TPanel *)this,param_1,param_2,param_3,param_4);
LAB_004926c1:
  *unaff_FS_OFFSET = local_c;
  return lVar4;
}

// --------------------------------------------------

