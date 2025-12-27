// Class: TribeJoinScreen
// Function: TribeJoinScreen
// Address: 00491650
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_scr3: "scr3"
/* public: __thiscall TribeJoinScreen::TribeJoinScreen(void) */

TribeJoinScreen * __thiscall TribeJoinScreen::TribeJoinScreen(TribeJoinScreen *this)
{
  TListPanel **ppTVar1;
  TButtonPanel **ppTVar2;
  TButtonPanel *pTVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  undefined4 *unaff_FS_OFFSET;
  TPanel *tabList [5];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e9a8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  tabList[0] = (TPanel *)this;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Join_Screen);
  this->_padding_ = (int)&_vftable_;
  this->startedSession = 0;
  this->listFilled = 0;
  Sess = (TCommunications_Sessions *)0x0;
  this->game_count = 0;
  this->waitingToStart = 0;
  this->joinTime = 0;
  this->close_button = (TButtonPanel *)0x0;
  local_4 = 0;
  TCommunications_Handler::SetPlayerHumanity(comm,1,ME_HUMAN);
  uVar6 = 2;
  do {
    TCommunications_Handler::SetPlayerHumanity(comm,uVar6,ME_ABSENT);
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 10);
  lVar4 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,&s_scr3,0xc385,1);
  if (lVar4 == 0) {
    this->_padding_ = 1;
    *unaff_FS_OFFSET = local_c;
    return this;
  }
  TEasy_Panel::setup_shadow_area((TEasy_Panel *)this,0);
  TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
                    /* language.dll match for 0x259f: "Multiplayer Games" */
  iVar5 = TEasy_Panel::create_text
                    ((TEasy_Panel *)this,(TPanel *)this,&this->title,0x259f,0x14,0x14,600,0x1e,1,1,0
                     ,0);
  if (iVar5 != 0) {
                    /* language.dll match for 0x25a8: "Select Game to Join" */
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->listTitle,0x25a8,0x14,0x41,600,0x14,4,0,0,0
              );
    ppTVar1 = &this->list;
    iVar5 = TEasy_Panel::create_list
                      ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,0x14,0x5a,600,0x10e,0xb);
    if (iVar5 != 0) {
      iVar5 = TEasy_Panel::create_auto_scrollbar
                        ((TEasy_Panel *)this,&this->scrollbar,(TTextPanel *)*ppTVar1,0x14);
      if (iVar5 != 0) {
                    /* language.dll match for 0x25ab: "Click Show Games to see a list of games.
                       Click Create to start a new game." */
        this->listFilled = 1;
        (**(code **)((*ppTVar1)->_padding_ + 0xe4))(0x25ab);
        ppTVar2 = &this->refreshButton;
                    /* language.dll match for 0x25a1: "Show Games" */
        iVar5 = TEasy_Panel::create_button
                          ((TEasy_Panel *)this,(TPanel *)this,ppTVar2,0x25a1,0,0xd2,0x172,0xdc,0x1e,
                           0,0,0);
        if (iVar5 != 0) {
                    /* language.dll match for 0x25a0: "Join" */
          iVar5 = TEasy_Panel::create_button
                            ((TEasy_Panel *)this,(TPanel *)this,&this->joinButton,0x25a0,0,10,0x1b8,
                             200,0x1e,0,0,0);
          if (iVar5 != 0) {
                    /* language.dll match for 0x25a2: "Create" */
            iVar5 = TEasy_Panel::create_button
                              ((TEasy_Panel *)this,(TPanel *)this,&this->createButton,0x25a2,0,0xdc,
                               0x1b8,200,0x1e,0,0,0);
            if (iVar5 != 0) {
                    /* language.dll match for 0xfa2: "Cancel" */
              iVar5 = TEasy_Panel::create_button
                                ((TEasy_Panel *)this,(TPanel *)this,&this->cancelButton,0xfa2,0,
                                 0x1ae,0x1b8,200,0x1e,0,0,0);
              if (iVar5 != 0) {
                pTVar3 = this->cancelButton;
                pTVar3->hotkey = 0x1b;
                pTVar3->hotkey_shift = 0;
                    /* language.dll match for 0x3ea: "X" */
                iVar5 = TEasy_Panel::create_button
                                  ((TEasy_Panel *)this,(TPanel *)this,&this->close_button,0x3ea,0,0,
                                   0,0,0,-1,-1,0);
                if (iVar5 != 0) {
                  (**(code **)(this->close_button->_padding_ + 0x14))(1);
                  (**(code **)(this->close_button->_padding_ + 0x18))
                            (9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
                  TPanel::set_curr_child((TPanel *)this,(TPanel *)*ppTVar2);
                  tabList[3] = (TPanel *)this->joinButton;
                  tabList[1] = (TPanel *)*ppTVar1;
                  tabList[2] = (TPanel *)*ppTVar2;
                  tabList[4] = (TPanel *)this->createButton;
                  TPanel::set_tab_order((TPanel *)this,tabList + 1,5);
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

// Function: `scalar_deleting_destructor'
// Address: 00491970
/* public: virtual void * __thiscall TribeJoinScreen::`scalar deleting destructor'(unsigned int) */

void * __thiscall TribeJoinScreen::_scalar_deleting_destructor_(TribeJoinScreen *this,uint param_1)
{
  ~TribeJoinScreen(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeJoinScreen
// Address: 00491990
/* public: virtual __thiscall TribeJoinScreen::~TribeJoinScreen(void) */

void __thiscall TribeJoinScreen::~TribeJoinScreen(TribeJoinScreen *this)
{
  TCommunications_Sessions *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055e9c8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  pTVar1 = Sess;
  local_4 = 0;
  if (Sess != (TCommunications_Sessions *)0x0) {
    TCommunications_Sessions::~TCommunications_Sessions(Sess);
    operator_delete(pTVar1);
  }
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->listTitle);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->scrollbar);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->refreshButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->joinButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->createButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->cancelButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->close_button);
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 00491a80
// [HELPER] s_C__msdev_work_age1_x1_scr_cj_cpp: "C:\msdev\work\age1_x1\scr_cj.cpp"
/* public: virtual long __thiscall TribeJoinScreen::handle_idle(void) */

long __thiscall TribeJoinScreen::handle_idle(TribeJoinScreen *this)
{
  ulong uVar1;
  long lVar2;
  
  if (this->waitingToStart == 0) {
    if ((this->listFilled != 0) && (rge_base_game->input_enabled == 0)) {
      RGE_Base_Game::enable_input(rge_base_game);
    }
    if (this->waitingToStart == 0) goto LAB_00491b15;
  }
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cj_cpp,0xaa);
  if (10000 < uVar1 - this->joinTime) {
    TCommunications_Handler::UnlinkToLevel(comm,SERVICE_AVAILABLE);
    this->waitingToStart = 0;
    RGE_Base_Game::enable_input(rge_base_game);
                    /* language.dll match for 0x25a3: "Unable to join game." */
    TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x25a3,(char *)0x0,0x1c2,100);
    return 1;
  }
LAB_00491b15:
  lVar2 = TPanel::handle_idle((TPanel *)this);
  return lVar2;
}

// --------------------------------------------------

// Function: handle_user_command
// Address: 00491b20
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
/* public: virtual long __thiscall TribeJoinScreen::handle_user_command(unsigned int,long) */

long __thiscall
TribeJoinScreen::handle_user_command(TribeJoinScreen *this,uint param_1,long param_2)
{
  TribeMPSetupScreen *this_00;
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e9eb;
  *unaff_FS_OFFSET = &local_c;
  switch(param_1) {
  case 0x17a8:
  case 0x17a9:
  case 0x17aa:
  case 0x17b2:
    if (this->waitingToStart != 0) {
      TCommunications_Handler::UnlinkToLevel(comm,SERVICE_AVAILABLE);
      this->waitingToStart = 0;
      RGE_Base_Game::enable_input(rge_base_game);
                    /* language.dll match for 0x25a3: "Unable to join game." */
      TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x25a3,(char *)0x0,0x1c2,100);
      *unaff_FS_OFFSET = local_c;
      return 1;
    }
    break;
  case 0x17b8:
    if (this->waitingToStart != 0) {
      this_00 = (TribeMPSetupScreen *)operator_new(0x890);
      local_4 = 0;
      if (this_00 != (TribeMPSetupScreen *)0x0) {
        TribeMPSetupScreen::TribeMPSetupScreen(this_00);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Join_Screen);
      *unaff_FS_OFFSET = local_c;
      return 1;
    }
  }
  lVar1 = TPanel::handle_user_command((TPanel *)this,param_1,param_2);
  *unaff_FS_OFFSET = local_c;
  return lVar1;
}

// --------------------------------------------------

// Function: fillList
// Address: 00491c70
// [HELPER] s__s_____1d_____1d__: "%s ( %.1d / %.1d )"
/* protected: void __thiscall TribeJoinScreen::fillList(void) */

void __thiscall TribeJoinScreen::fillList(TribeJoinScreen *this)
{
  TCommunications_Sessions *this_00;
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  char *pcVar4;
  undefined4 *unaff_FS_OFFSET;
  char szTemp [126];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ea0e;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Base_Game::disable_input(rge_base_game);
                    /* language.dll match for 0x25a9: "Looking for games..." */
  this->listFilled = 0;
  this->game_count = 0;
  (**(code **)(this->list->_padding_ + 0xe4))(0x25a9);
  RGE_Base_Game::draw_window(rge_base_game);
  if (this->startedSession == 0) {
    this_00 = (TCommunications_Sessions *)operator_new(0x457b0);
    pcStack_8 = (code *)0x0;
    if (this_00 == (TCommunications_Sessions *)0x0) {
      Sess = (TCommunications_Sessions *)0x0;
    }
    else {
      Sess = (TCommunications_Sessions *)
             TCommunications_Sessions::TCommunications_Sessions(this_00,comm);
    }
    pcStack_8 = (code *)0xffffffff;
    if (Sess == (TCommunications_Sessions *)0x0) {
                    /* language.dll match for 0x25ab: "Click Show Games to see a list of games.
                       Click Create to start a new game." */
      (**(code **)(this->list->_padding_ + 0xe4))(0x25ab);
      *unaff_FS_OFFSET = stack0xffffffec;
      return;
    }
    this->startedSession = 1;
  }
  else {
    TCommunications_Sessions::Refresh(Sess);
  }
  iVar1 = TCommunications_Sessions::GetSessionCount(Sess);
  this->game_count = iVar1;
  if (iVar1 < 1) {
                    /* language.dll match for 0x25ab: "Click Show Games to see a list of games.
                       Click Create to start a new game." */
    (**(code **)(this->list->_padding_ + 0xe4))(0x25ab);
  }
  else {
    TTextPanel::empty_list((TTextPanel *)this->list);
    iVar1 = 0;
    if (0 < this->game_count) {
      do {
        uVar2 = TCommunications_Sessions::GetSessionMaxPlayers(Sess,iVar1);
        uVar3 = TCommunications_Sessions::GetSessionCurrentPlayers(Sess,iVar1);
        pcVar4 = TCommunications_Sessions::GetSessionName(Sess,iVar1);
        sprintf(szTemp,s__s_____1d_____1d__,pcVar4,uVar3,uVar2);
        TTextPanel::append_line((TTextPanel *)this->list,szTemp,0);
        iVar1 = iVar1 + 1;
      } while (iVar1 < this->game_count);
    }
    TPanel::set_curr_child((TPanel *)this,(TPanel *)this->list);
  }
  this->listFilled = 1;
  *unaff_FS_OFFSET = uStack_10;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 00491e20
// [HELPER] s_C__msdev_work_age1_x1_scr_cj_cpp: "C:\msdev\work\age1_x1\scr_cj.cpp"
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_MP_Startup_Screen: "MP Startup Screen"
/* public: virtual long __thiscall TribeJoinScreen::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TribeJoinScreen::action
          (TribeJoinScreen *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  long lVar1;
  int iVar2;
  _GUID *p_Var3;
  char *pcVar4;
  ulong uVar5;
  undefined4 *unaff_FS_OFFSET;
  char temp [256];
  char string [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055ea3c;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 == (TPanel *)0x0) {
LAB_0049208e:
    lVar1 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  }
  else {
    if ((TListPanel *)param_1 == this->list) {
      if ((param_2 == 3) && (0 < this->game_count)) {
        (**(code **)(this->_padding_ + 0xb4))(this->joinButton,1,0,0);
        lVar1 = 1;
        goto LAB_004920a7;
      }
    }
    else if ((TButtonPanel *)param_1 == this->joinButton) {
      if (param_2 == 1) {
        if (this->game_count < 1) {
                    /* language.dll match for 0x25a4: "There are no games to join." */
          TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x25a4,(char *)0x0,0x1c2,100);
          lVar1 = 1;
        }
        else {
          iVar2 = TTextPanel::currentLineNumber((TTextPanel *)this->list);
          p_Var3 = TCommunications_Sessions::GetSessionGUID(Sess,iVar2);
          iVar2 = TCommunications_Handler::JoinMultiplayerGame(comm,p_Var3);
          if (iVar2 == 0) {
                    /* language.dll match for 0x25a3: "Unable to join game." */
            TPanel::get_string((TPanel *)this,0x25a3,temp + 4,0x100);
            pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
            sprintf(string + 4,temp + 4,pcVar4);
            TEasy_Panel::popupOKDialog((TEasy_Panel *)this,string + 4,(char *)0x0,0x1c2,100);
            lVar1 = 1;
          }
          else {
            RGE_Base_Game::disable_input(rge_base_game);
            this->waitingToStart = 1;
            uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cj_cpp,0x140);
            this->joinTime = uVar5;
            lVar1 = 1;
          }
        }
        goto LAB_004920a7;
      }
    }
    else if ((TButtonPanel *)param_1 == this->cancelButton) {
      if (param_2 == 1) {
        RGE_Base_Game::disable_input(rge_base_game);
        TCommunications_Handler::UnlinkToLevel(comm,SINGLE_PLAYER);
        temp._0_4_ = operator_new(0x6a0);
        local_4 = 0;
        if ((TribeMPStartupScreen *)temp._0_4_ != (TribeMPStartupScreen *)0x0) {
          TribeMPStartupScreen::TribeMPStartupScreen((TribeMPStartupScreen *)temp._0_4_);
        }
        local_4 = 0xffffffff;
        TPanelSystem::setCurrentPanel(&panel_system,s_MP_Startup_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Join_Screen);
        lVar1 = 1;
        goto LAB_004920a7;
      }
    }
    else if (((TButtonPanel *)param_1 == this->createButton) && (param_2 == 1)) {
      temp._0_4_ = operator_new(0x4a4);
      local_4 = 1;
      if ((TribeMPCreateDialog *)temp._0_4_ != (TribeMPCreateDialog *)0x0) {
        TribeMPCreateDialog::TribeMPCreateDialog((TribeMPCreateDialog *)temp._0_4_,(TPanel *)this);
        lVar1 = 1;
        goto LAB_004920a7;
      }
    }
    else if ((TButtonPanel *)param_1 == this->refreshButton) {
      if (param_2 == 1) {
        fillList(this);
        lVar1 = 1;
        goto LAB_004920a7;
      }
    }
    else {
      if (((TButtonPanel *)param_1 != this->close_button) || (param_2 != 1)) goto LAB_0049208e;
      RGE_Base_Game::close(rge_base_game);
    }
    lVar1 = 1;
  }
LAB_004920a7:
  *unaff_FS_OFFSET = local_c;
  return lVar1;
}

// --------------------------------------------------

