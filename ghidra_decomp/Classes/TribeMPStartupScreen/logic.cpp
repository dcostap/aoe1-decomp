// Class: TribeMPStartupScreen
// Function: TribeMPStartupScreen
// Address: 0049f370
// [HELPER] s_Default_Age_Of_Empires_Player_Na: "Default Age Of Empires Player Name"
// [HELPER] s_MP_Startup_Screen: "MP Startup Screen"
// [HELPER] s_Zone: "Zone"
// [HELPER] s_http_shell_open_command: "http\shell\open\command"
// [HELPER] s_scr3: "scr3"
/* WARNING: Variable defined which should be unmapped: ghUserKey */
/* public: __thiscall TribeMPStartupScreen::TribeMPStartupScreen(void) */

TribeMPStartupScreen * __thiscall
TribeMPStartupScreen::TribeMPStartupScreen(TribeMPStartupScreen *this)
{
  TButtonPanel **ppTVar1;
  TListPanel **ppTVar2;
  char cVar3;
  TButtonPanel *pTVar4;
  long lVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar12;
  undefined4 uStack_38c;
  undefined4 uStack_388;
  undefined1 *puStack_384;
  undefined1 *puStack_380;
  undefined4 uStack_37c;
  undefined4 uStack_378;
  void *ghUserKey;
  ulong dwSize;
  ulong dwType;
  TPanel *tabList [5];
  ulong gdwDisp;
  char Data [255];
  char temp_str [255];
  char str [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f0fb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  Data._0_4_ = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_MP_Startup_Screen);
  ppTVar1 = &this->cancelButton;
  this->_padding_ = (int)&_vftable_;
  this->help_button = (TButtonPanel *)0x0;
  this->okButton = (TButtonPanel *)0x0;
  *ppTVar1 = (TButtonPanel *)0x0;
  this->close_button = (TButtonPanel *)0x0;
  local_4 = 0;
  RGE_Base_Game::setMultiplayerGame(rge_base_game,0);
  lVar5 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,&s_scr3,0xc385,1);
  if (lVar5 == 0) {
    this->_padding_ = 1;
  }
  else {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)this,0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
                    /* language.dll match for 0x258b: "Multiplayer Connection" */
    iVar6 = TEasy_Panel::create_text
                      ((TEasy_Panel *)this,(TPanel *)this,&this->title,0x258b,0x14,0x14,600,0x1e,1,1
                       ,0,0);
                    /* language.dll match for 0x258c: "Name" */
    if ((iVar6 != 0) &&
       (iVar6 = TEasy_Panel::create_text
                          ((TEasy_Panel *)this,(TPanel *)this,&this->inputTitle,0x258c,0x14,0x4b,500
                           ,0x14,4,0,0,0), iVar6 != 0)) {
      pcVar7 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_Player_Na);
      if (pcVar7 == (char *)0x0) {
        str[4] = '\0';
      }
      else {
        pcVar8 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_Player_Na);
        uVar9 = 0xffffffff;
        pcVar7 = str;
        do {
          pcVar11 = pcVar8;
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          pcVar11 = pcVar8 + 1;
          cVar3 = *pcVar8;
          pcVar8 = pcVar11;
        } while (cVar3 != '\0');
        uVar9 = ~uVar9;
        pcVar8 = pcVar11 + -uVar9;
        for (uVar10 = uVar9 >> 2; pcVar7 = pcVar7 + 4, uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
        }
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar7 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar7 = pcVar7 + 1;
        }
      }
      uStack_378 = 0x49f4fa;
      iVar6 = TEasy_Panel::create_edit
                        ((TEasy_Panel *)this,(TPanel *)this,&this->input,str + 4,0xf,FormatText,0x14
                         ,100,600,0x17,0xb,1,0);
      if (iVar6 != 0) {
                    /* language.dll match for 0x7595: "Type your player name." */
        TPanel::set_help_info((TPanel *)this->input,0x7595,-1);
                    /* language.dll match for 0x258d: "Connection Type" */
        iVar6 = TEasy_Panel::create_text
                          ((TEasy_Panel *)this,(TPanel *)this,&this->connectionTitle,0x258d,0x14,
                           0xa5,600,0x14,4,0,0,0);
        if (iVar6 != 0) {
          ppTVar2 = &this->list;
          iVar6 = TEasy_Panel::create_list
                            ((TEasy_Panel *)this,(TPanel *)this,ppTVar2,0x14,0xbe,600,0xd2,0xb);
          if ((iVar6 != 0) &&
             (iVar6 = TEasy_Panel::create_auto_scrollbar
                                ((TEasy_Panel *)this,&this->scrollbar,(TTextPanel *)*ppTVar2,0x14),
             iVar6 != 0)) {
                    /* language.dll match for 0x7596: "Select the type of connection to make. For
                       more information, click More Help." */
            TPanel::set_help_info((TPanel *)*ppTVar2,0x7596,0x25f08);
                    /* language.dll match for 0xfa1: "OK" */
            iVar6 = TEasy_Panel::create_button
                              ((TEasy_Panel *)this,(TPanel *)this,&this->okButton,0xfa1,0,0x46,0x1b8
                               ,0xf0,0x1e,0,0,0);
            if (iVar6 != 0) {
              TPanel::set_help_info((TPanel *)this->okButton,0x7531,-1);
                    /* language.dll match for 0xfa2: "Cancel" */
              iVar6 = TEasy_Panel::create_button
                                ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,0xfa2,0,0x14a,0x1b8,0xf0
                                 ,0x1e,0,0,0);
              if (iVar6 != 0) {
                TPanel::set_help_info((TPanel *)*ppTVar1,0x7532,-1);
                pTVar4 = *ppTVar1;
                pTVar4->hotkey = 0x1b;
                pTVar4->hotkey_shift = 0;
                    /* language.dll match for 0xfa9: "?" */
                iVar6 = TEasy_Panel::create_button
                                  ((TEasy_Panel *)this,(TPanel *)this,&this->help_button,0xfa9,0,
                                   0x244,0x1b8,0x1e,0x1e,0,0,0);
                if (iVar6 != 0) {
                  ppTVar1 = &this->close_button;
                    /* language.dll match for 0x3ea: "X" */
                  iVar6 = TEasy_Panel::create_button
                                    ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,0x3ea,0,0,0,0,0,-1,
                                     -1,0);
                  if (iVar6 != 0) {
                    (**(code **)((*ppTVar1)->_padding_ + 0x14))();
                    uStack_378 = 4;
                    uStack_37c = 9;
                    puStack_380 = (undefined1 *)0x49f6b3;
                    (**(code **)((*ppTVar1)->_padding_ + 0x18))();
                    puStack_380 = &stack0xfffffcb4;
                    puStack_384 = &stack0xfffffc94;
                    uStack_388 = 0;
                    uStack_38c = 0xf003f;
                    uVar12 = 0;
                    this->zone_exec[0] = '\0';
                    this->browser_exec[0] = '\0';
                    RegCreateKeyExA(0x80000000,s_http_shell_open_command,0,0,0);
                    uStack_388 = 1;
                    uStack_38c = 0xff;
                    iVar6 = RegQueryValueExA(uVar12,0,0,&uStack_388,&stack0xfffffc98,&uStack_38c);
                    if (dwSize != 0) {
                      RegCloseKey();
                    }
                    if (iVar6 == 0) {
                      iVar6 = -1;
                      pcVar7 = Data + 4;
                      do {
                        if (iVar6 == 0) break;
                        iVar6 = iVar6 + -1;
                        cVar3 = *pcVar7;
                        pcVar7 = pcVar7 + 1;
                      } while (cVar3 != '\0');
                      strncpy();
                      iVar6 = strchr();
                      if (iVar6 != 0) {
                        strncpy();
                        *(undefined1 *)((iVar6 - (int)(temp_str + 4)) + 0x59f + (int)this) = 0;
                      }
                      pcVar7 = TRegistry::RegGetAscii(Regs,0,s_Zone);
                      if (pcVar7 != (char *)0x0) {
                        uVar9 = 0xffffffff;
                        do {
                          pcVar8 = pcVar7;
                          if (uVar9 == 0) break;
                          uVar9 = uVar9 - 1;
                          pcVar8 = pcVar7 + 1;
                          cVar3 = *pcVar7;
                          pcVar7 = pcVar8;
                        } while (cVar3 != '\0');
                        uVar9 = ~uVar9;
                        iVar6 = -1;
                        pcVar7 = Data + 4;
                        do {
                          pcVar11 = pcVar7;
                          if (iVar6 == 0) break;
                          iVar6 = iVar6 + -1;
                          pcVar11 = pcVar7 + 1;
                          cVar3 = *pcVar7;
                          pcVar7 = pcVar11;
                        } while (cVar3 != '\0');
                        pcVar7 = pcVar8 + -uVar9;
                        pcVar8 = pcVar11 + -1;
                        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
                          pcVar7 = pcVar7 + 4;
                          pcVar8 = pcVar8 + 4;
                        }
                        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                          *pcVar8 = *pcVar7;
                          pcVar7 = pcVar7 + 1;
                          pcVar8 = pcVar8 + 1;
                        }
                        uVar9 = 0xffffffff;
                        pcVar7 = Data + 4;
                        do {
                          pcVar8 = pcVar7;
                          if (uVar9 == 0) break;
                          uVar9 = uVar9 - 1;
                          pcVar8 = pcVar7 + 1;
                          cVar3 = *pcVar7;
                          pcVar7 = pcVar8;
                        } while (cVar3 != '\0');
                        uVar9 = ~uVar9;
                        pcVar7 = pcVar8 + -uVar9;
                        pcVar8 = this->zone_exec;
                        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
                          pcVar7 = pcVar7 + 4;
                          pcVar8 = pcVar8 + 4;
                        }
                        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                          *pcVar8 = *pcVar7;
                          pcVar7 = pcVar7 + 1;
                          pcVar8 = pcVar8 + 1;
                        }
                      }
                    }
                    fillList(this);
                    TPanel::set_curr_child((TPanel *)this,(TPanel *)this->input);
                    tabList[3] = (TPanel *)this->okButton;
                    tabList[1] = (TPanel *)this->input;
                    tabList[2] = (TPanel *)this->list;
                    tabList[4] = (TPanel *)this->cancelButton;
                    TPanel::set_tab_order((TPanel *)this,tabList + 1,5);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0049f870
/* public: virtual void * __thiscall TribeMPStartupScreen::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
TribeMPStartupScreen::_vector_deleting_destructor_(TribeMPStartupScreen *this,uint param_1)
{
  ~TribeMPStartupScreen(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeMPStartupScreen
// Address: 0049f890
// [HELPER] s_Create_Dialog: "Create Dialog"
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s_YesNoDialog: "YesNoDialog"
/* public: virtual __thiscall TribeMPStartupScreen::~TribeMPStartupScreen(void) */

void __thiscall TribeMPStartupScreen::~TribeMPStartupScreen(TribeMPStartupScreen *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f118;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->inputTitle);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->input);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->connectionTitle);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->scrollbar);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->okButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->cancelButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->help_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->close_button);
  TPanelSystem::destroyPanel(&panel_system,s_Create_Dialog);
  TPanelSystem::destroyPanel(&panel_system,&s_OKDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 0049f9a0
/* public: virtual long __thiscall TribeMPStartupScreen::handle_idle(void) */

long __thiscall TribeMPStartupScreen::handle_idle(TribeMPStartupScreen *this)
{
  long lVar1;
  
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  lVar1 = TPanel::handle_idle((TPanel *)this);
  return lVar1;
}

// --------------------------------------------------

// Function: action
// Address: 0049f9d0
// [HELPER] s_Default_Age_Of_Empires_Multiplay: "Default Age Of Empires Multiplayer Service"
// [HELPER] s_Default_Age_Of_Empires_Player_Na: "Default Age Of Empires Player Name"
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_List_Error: "List Error"
// [HELPER] s_MP_Startup_Screen: "MP Startup Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Name_Error: "Name Error"
// [HELPER] s_Start_Zone: "Start Zone"
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* public: virtual long __thiscall TribeMPStartupScreen::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TribeMPStartupScreen::action
          (TribeMPStartupScreen *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  uchar *puVar6;
  _GUID *p_Var7;
  TribeJoinScreen *this_00;
  TRIBE_Screen_Main_Menu *this_01;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  undefined4 *unaff_FS_OFFSET;
  bool bVar11;
  undefined1 local_25a0 [12];
  TCommunications_Services Serv;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f157;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 == (TPanel *)0x0) goto LAB_0049fe8e;
  if (((TListPanel *)param_1 == this->list) && (param_2 == 3)) {
    (**(code **)(this->_padding_ + 0xb4))(this->okButton,1,0,0);
    param_2 = 1;
    goto LAB_0049fea7;
  }
  if (((TButtonPanel *)param_1 == this->close_button) && (param_2 == 1)) {
LAB_0049fe75:
    RGE_Base_Game::close(rge_base_game);
LAB_0049fe80:
    param_2 = 1;
  }
  else {
    if (((TButtonPanel *)param_1 == this->okButton) && (param_2 == 1)) {
      RGE_Base_Game::setMultiplayerGame(rge_base_game,1);
      pcVar3 = TEditPanel::get_text(this->input);
      if (*pcVar3 == '\0') {
                    /* language.dll match for 0x258f: "You must enter a valid player name." */
        TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x258f,&s_Name_Error,0x1c2,100);
      }
      else {
        iVar4 = TTextPanel::numberLines((TTextPanel *)this->list);
        if (iVar4 == 0) {
                    /* language.dll match for 0x2592: "No multiplayer connections are available." */
          TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2592,&s_List_Error,0x1c2,100);
          param_2 = 1;
        }
        else if ((this->zone_exec[0] == '\0') ||
                (lVar5 = TTextPanel::get_id((TTextPanel *)this->list), lVar5 != -1)) {
          RGE_Base_Game::disable_input(rge_base_game);
          pcVar3 = TEditPanel::currentLine(this->input);
          uVar9 = 0xffffffff;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          uVar9 = ~uVar9;
          puVar6 = (uchar *)TEditPanel::currentLine(this->input);
          TRegistry::RegSetAscii(Regs,1,s_Default_Age_Of_Empires_Player_Na,puVar6,uVar9);
          pcVar3 = TTextPanel::get_text((TTextPanel *)this->list);
          uVar9 = 0xffffffff;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          uVar9 = ~uVar9;
          puVar6 = (uchar *)TTextPanel::get_text((TTextPanel *)this->list);
          TRegistry::RegSetAscii(Regs,1,s_Default_Age_Of_Empires_Multiplay,puVar6,uVar9);
          pcVar3 = TEditPanel::currentLine(this->input);
          TCommunications_Handler::SetMyPlayerName(comm,pcVar3);
          TCommunications_Services::TCommunications_Services
                    ((TCommunications_Services *)(Serv.Service[0].Name + 4));
          local_4 = 0;
          lVar5 = TTextPanel::get_id((TTextPanel *)this->list);
          p_Var7 = TCommunications_Services::GetServiceGUID
                             ((TCommunications_Services *)(Serv.Service[0].Name + 4),
                              (_GUID *)local_25a0,lVar5);
          TCommunications_Handler::SetServiceGUID(comm,*p_Var7);
          TCommunications_Handler::InitJoinGame(comm);
                    /* language.dll match for 0x4b0: "Ready" */
          this_00 = (TribeJoinScreen *)operator_new(0x4b0);
          local_4._0_1_ = 1;
          if (this_00 != (TribeJoinScreen *)0x0) {
            TribeJoinScreen::TribeJoinScreen(this_00);
          }
          local_4 = (uint)local_4._1_3_ << 8;
          TPanelSystem::setCurrentPanel(&panel_system,s_Join_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,s_MP_Startup_Screen);
          local_4 = 0xffffffff;
          TCommunications_Services::~TCommunications_Services
                    ((TCommunications_Services *)(Serv.Service[0].Name + 4));
          param_2 = 1;
        }
        else {
                    /* language.dll match for 0x2593: "Start your Web browser and go to The Internet
                       Gaming Zone?" */
          TEasy_Panel::popupYesNoDialog((TEasy_Panel *)this,0x2593,&s_Start_Zone,0x1c2,100);
          param_2 = 1;
        }
      }
      goto LAB_0049fea7;
    }
    if ((((TButtonPanel *)param_1 == this->cancelButton) && (param_2 == 1)) ||
       (((TEditPanel *)param_1 == this->input && (param_2 == 1)))) {
      RGE_Base_Game::disable_input(rge_base_game);
      TCommunications_Handler::UnlinkToLevel(comm,SINGLE_PLAYER);
                    /* language.dll match for 0x4b0: "Ready" */
      this_01 = (TRIBE_Screen_Main_Menu *)operator_new(0x4b0);
      local_4 = 2;
      if (this_01 != (TRIBE_Screen_Main_Menu *)0x0) {
        TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(this_01);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
      TPanelSystem::destroyPanel(&panel_system,s_MP_Startup_Screen);
      param_2 = 1;
      goto LAB_0049fea7;
    }
    if (((TButtonPanel *)param_1 == this->help_button) && (param_2 == 1)) {
      TEasy_Panel::setup_popup_help((TEasy_Panel *)this);
      goto LAB_0049fea7;
    }
    pcVar3 = TPanel::panelName(param_1);
    if (pcVar3 != (char *)0x0) {
      pbVar10 = &s_List_Error;
      pbVar8 = (byte *)TPanel::panelName(param_1);
      do {
        bVar2 = *pbVar8;
        bVar11 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0049fd42:
          iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_0049fd47;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar8[1];
        bVar11 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0049fd42;
        pbVar8 = pbVar8 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_0049fd47:
      if (iVar4 == 0) {
        TPanelSystem::destroyPanel(&panel_system,&s_List_Error);
        TPanel::set_curr_child((TPanel *)this,(TPanel *)this->list);
        param_2 = 1;
        goto LAB_0049fea7;
      }
    }
    pcVar3 = TPanel::panelName(param_1);
    if (pcVar3 != (char *)0x0) {
      pbVar10 = &s_Name_Error;
      pbVar8 = (byte *)TPanel::panelName(param_1);
      do {
        bVar2 = *pbVar8;
        bVar11 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0049fdb4:
          iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_0049fdb9;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar8[1];
        bVar11 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0049fdb4;
        pbVar8 = pbVar8 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_0049fdb9:
      if (iVar4 == 0) {
        TPanelSystem::destroyPanel(&panel_system,&s_Name_Error);
        TPanel::set_curr_child((TPanel *)this,(TPanel *)this->input);
        param_2 = 1;
        goto LAB_0049fea7;
      }
    }
    pcVar3 = TPanel::panelName(param_1);
    if (pcVar3 != (char *)0x0) {
      pbVar10 = &s_Start_Zone;
      pbVar8 = (byte *)TPanel::panelName(param_1);
      do {
        bVar2 = *pbVar8;
        bVar11 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0049fe2a:
          iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_0049fe2f;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar8[1];
        bVar11 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0049fe2a;
        pbVar8 = pbVar8 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_0049fe2f:
      if (iVar4 == 0) {
        TPanelSystem::destroyPanel(&panel_system,&s_Start_Zone);
        TPanel::set_curr_child((TPanel *)this,(TPanel *)this->list);
        if (param_2 == 0) {
          RGE_Base_Game::disable_input(rge_base_game);
          WinExec(this->zone_exec,3);
          goto LAB_0049fe75;
        }
        goto LAB_0049fe80;
      }
    }
LAB_0049fe8e:
    param_2 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  }
LAB_0049fea7:
  *unaff_FS_OFFSET = local_c;
  return param_2;
}

// --------------------------------------------------

// Function: fillList
// Address: 0049fed0
// [HELPER] s_: ""
// [HELPER] s_Default_Age_Of_Empires_Multiplay: "Default Age Of Empires Multiplayer Service"
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Variable defined which should be unmapped: lastServiceNumber */
/* protected: void __thiscall TribeMPStartupScreen::fillList(void) */

void __thiscall TribeMPStartupScreen::fillList(TribeMPStartupScreen *this)
{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  byte *pbVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  char *pcVar11;
  char *pcVar12;
  int iVar13;
  undefined4 *unaff_FS_OFFSET;
  bool bVar14;
  int lastServiceNumber;
  char lastServiceName [256];
  _finddata_t file_info;
  TCommunications_Services Serv;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055f17b;
  *unaff_FS_OFFSET = &local_c;
  TTextPanel::empty_list((TTextPanel *)this->list);
  TCommunications_Services::TCommunications_Services
            ((TCommunications_Services *)(Serv.Service[0].Name + 4));
  local_4 = 0;
  iVar3 = TCommunications_Services::GetServiceCount
                    ((TCommunications_Services *)(Serv.Service[0].Name + 4));
  lastServiceName[0] = -1;
  lastServiceName[1] = -1;
  lastServiceName[2] = -1;
  lastServiceName[3] = -1;
  pcVar4 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_Multiplay);
  if (pcVar4 == (char *)0x0) {
    pcVar4 = s_;
  }
  else {
    pcVar4 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_Multiplay);
  }
  pcVar12 = lastServiceName;
  uVar8 = 0xffffffff;
  do {
    pcVar11 = pcVar4;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar11 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar11;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8;
  pcVar4 = pcVar11 + -uVar8;
  for (uVar9 = uVar8 >> 2; pcVar12 = pcVar12 + 4, uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pcVar12 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar12 = pcVar12 + 1;
  }
  iVar13 = 0;
  if (0 < iVar3) {
    do {
      iVar5 = TCommunications_Services::GetServiceActive
                        ((TCommunications_Services *)(Serv.Service[0].Name + 4),iVar13);
      if (iVar5 != 0) {
        pcVar4 = TCommunications_Services::GetServiceName
                           ((TCommunications_Services *)(Serv.Service[0].Name + 4),iVar13);
        if (pcVar4 != (char *)0x0) {
          iVar5 = iVar13;
          pcVar4 = TCommunications_Services::GetServiceName
                             ((TCommunications_Services *)(Serv.Service[0].Name + 4),iVar13);
          TTextPanel::append_line((TTextPanel *)this->list,pcVar4,iVar5);
          pbVar10 = (byte *)(lastServiceName + 4);
          pbVar6 = (byte *)TCommunications_Services::GetServiceName
                                     ((TCommunications_Services *)(Serv.Service[0].Name + 4),iVar13)
          ;
          do {
            bVar2 = *pbVar6;
            bVar14 = bVar2 < *pbVar10;
            if (bVar2 != *pbVar10) {
LAB_0049fffe:
              iVar5 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
              goto LAB_004a0003;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar6[1];
            bVar14 = bVar2 < pbVar10[1];
            if (bVar2 != pbVar10[1]) goto LAB_0049fffe;
            pbVar6 = pbVar6 + 2;
            pbVar10 = pbVar10 + 2;
          } while (bVar2 != 0);
          iVar5 = 0;
LAB_004a0003:
          if (iVar5 == 0) {
            lastServiceName._0_4_ = iVar13;
          }
        }
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < iVar3);
  }
  iVar3 = __findfirst(this->browser_exec,&file_info.time_create);
  if ((iVar3 != -1) && (this->zone_exec[0] != '\0')) {
                    /* language.dll match for 0x258e: "Microsoft Internet Gaming Zone" */
    TTextPanel::append_line((TTextPanel *)this->list,0x258e,-1);
  }
  if (lastServiceName._0_4_ != -1) {
    lVar7 = TTextPanel::get_line((TTextPanel *)this->list,lastServiceName._0_4_);
    TTextPanel::set_line((TTextPanel *)this->list,lVar7);
  }
  local_4 = 0xffffffff;
  TCommunications_Services::~TCommunications_Services
            ((TCommunications_Services *)(Serv.Service[0].Name + 4));
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: handle_user_command
// Address: 004a00a0
/* public: virtual long __thiscall TribeMPStartupScreen::handle_user_command(unsigned int,long) */

long __thiscall
TribeMPStartupScreen::handle_user_command(TribeMPStartupScreen *this,uint param_1,long param_2)
{
  return 1;
}

// --------------------------------------------------

