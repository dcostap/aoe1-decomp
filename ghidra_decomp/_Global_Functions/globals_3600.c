// GLOBAL FUNCTIONS PART 3600
// Function: FUN_004b6737
// Address: 004b6737
// XREFS: None
void __fastcall FUN_004b6737(TribeGameSettingsScreen *param_1)
{
  TButtonPanel *pTVar1;
  long lVar2;
  int iVar3;
  TListPanel *pTVar4;
  uint uVar5;
  bool bVar6;
  TListPanel *apTStack_2c [4];
  uint uStack_1c;
  undefined4 uStack_18;
  
  bVar6 = param_1->state != StateScenario;
  iVar3 = param_1->missionTitle->_padding_;
  if (bVar6) {
    uStack_18 = 0;
    uStack_1c = 0x4b6778;
    (**(code **)(iVar3 + 0x14))();
    iVar3 = param_1->missionText->_padding_;
  }
  else {
    uStack_18 = 1;
    uStack_1c = 0x4b6767;
    (**(code **)(iVar3 + 0x14))();
    iVar3 = param_1->missionText->_padding_;
  }
  uStack_1c = (uint)!bVar6;
  apTStack_2c[3] = (TListPanel *)0x4b6785;
  (**(code **)(iVar3 + 0x14))();
  pTVar4 = (TListPanel *)(uint)bVar6;
  apTStack_2c[2] = (TListPanel *)0x4b679a;
  apTStack_2c[3] = pTVar4;
  (**(code **)(param_1->mapSizeDrop->_padding_ + 0x14))();
  apTStack_2c[1] = (TListPanel *)0x4b67a6;
  apTStack_2c[2] = pTVar4;
  (**(code **)(param_1->mapTypeDrop->_padding_ + 0x14))();
  apTStack_2c[0] = (TListPanel *)0x4b67b2;
  apTStack_2c[1] = pTVar4;
  (**(code **)(param_1->mapSizeLabel->_padding_ + 0x14))();
  apTStack_2c[0] = pTVar4;
  (**(code **)(param_1->mapTypeLabel->_padding_ + 0x14))();
  lVar2 = TTextPanel::get_id((TTextPanel *)param_1->scenarioList);
  iVar3 = param_1->resourcesDrop->_padding_;
  if (lVar2 != -1) {
    (**(code **)(iVar3 + 0x14))(1);
    iVar3 = param_1->resourcesLabel->_padding_;
  }
  else {
    (**(code **)(iVar3 + 0x14))(0);
    iVar3 = param_1->resourcesLabel->_padding_;
  }
  (**(code **)(iVar3 + 0x14))(lVar2 != -1);
  TribeGameSettingsScreen::activateVictoryPanels(param_1);
  iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar3 != 0) {
    apTStack_2c[0] = param_1->scenarioList;
  }
  uVar5 = (uint)(iVar3 != 0);
  pTVar1 = param_1->cancelButton;
  apTStack_2c[uVar5] = (TListPanel *)param_1->okButton;
  iVar3 = param_1->_padding_;
  apTStack_2c[uVar5 + 1] = (TListPanel *)pTVar1;
  (**(code **)(iVar3 + 200))(apTStack_2c,uVar5 + 2);
  if ((param_1->_padding_ == 0) || (*(int *)(param_1->_padding_ + 0x6c) == 0)) {
    TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->okButton);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004b6868
// Address: 004b6868
// XREFS: None
void __fastcall FUN_004b6868(int param_1)
{
  long lVar1;
  long lVar2;
  
  (**(code **)(**(int **)(param_1 + 0x4a8) + 0x14))(0);
  (**(code **)(**(int **)(param_1 + 0x4ac) + 0x14))(0);
  (**(code **)(**(int **)(param_1 + 0x4a0) + 0x14))(0);
  (**(code **)(**(int **)(param_1 + 0x4a4) + 0x14))(0);
  if (*(int *)(param_1 + 0x47c) == 0) {
    lVar1 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x4f0));
    lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x4f0));
    if (((*(int *)(param_1 + 0x504) != 0) && (-1 < lVar2)) &&
       (*(int *)(*(int *)(param_1 + 0x500) + (*(int *)(param_1 + 0x558) + lVar1) * 4) != 0)) {
      (**(code **)(**(int **)(param_1 + 0x498) + 0x14))(1);
      (**(code **)(**(int **)(param_1 + 0x490) + 0x14))(0);
      (**(code **)(**(int **)(param_1 + 0x494) + 0x14))(0);
      return;
    }
  }
  (**(code **)(**(int **)(param_1 + 0x498) + 0x14))(0);
  (**(code **)(**(int **)(param_1 + 0x490) + 0x14))(1);
  (**(code **)(**(int **)(param_1 + 0x494) + 0x14))(1);
  lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x494));
  if (lVar1 == 7) {
    (**(code **)(**(int **)(param_1 + 0x4a8) + 0x14))(1);
    (**(code **)(**(int **)(param_1 + 0x4ac) + 0x14))(1);
  }
  lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x494));
  if (lVar1 == 8) {
    (**(code **)(**(int **)(param_1 + 0x4a0) + 0x14))(1);
    (**(code **)(**(int **)(param_1 + 0x4a4) + 0x14))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004b6994
// Address: 004b6994
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
// [HELPER] s_scr2: "scr2"
TEasy_Panel * __fastcall FUN_004b6994(TEasy_Panel *param_1)
{
  long lVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  TPanel **ppTVar6;
  undefined4 *unaff_FS_OFFSET;
  TPanel *apTStack_24 [6];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f6d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Single_Player_Menu);
  param_1->_padding_ = (int)&TribeSPMenuScreen::_vftable_;
  uStack_4 = 0;
  RGE_Base_Game::setSinglePlayerGame(rge_base_game,1);
  RGE_Base_Game::setScenarioName(rge_base_game,s_);
  lVar1 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,&s_scr2,0xc384,1);
  if (lVar1 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  piVar5 = &param_1[1]._padding_;
  piVar4 = piVar5;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  param_1[1]._padding_ = 0;
  TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
  iVar3 = TEasy_Panel::create_text
                    (param_1,(TPanel *)param_1,(TTextPanel **)(param_1 + 1),0x2404,0x14,0x14,600,
                     0x1e,1,1,0,0);
  if (iVar3 != 0) {
    iVar3 = 0x76;
    piVar4 = piVar5;
    do {
      iVar2 = TEasy_Panel::create_button
                        (param_1,(TPanel *)param_1,(TButtonPanel **)piVar4,s_,(char *)0x0,0xaa,iVar3
                         ,300,0x28,0,0,0);
      if (iVar2 == 0) goto LAB_004b6bc8;
      iVar3 = iVar3 + 0x32;
      piVar4 = piVar4 + 1;
    } while (iVar3 < 0x1a2);
    piVar4 = &param_1[1]._padding_;
    iVar3 = TEasy_Panel::create_button
                      (param_1,(TPanel *)param_1,(TButtonPanel **)piVar4,0x3ea,0,0,0,0,0,-1,-1,0);
    if (iVar3 != 0) {
      (**(code **)(*(int *)*piVar4 + 0x14))(1);
      (**(code **)(*(int *)*piVar4 + 0x18))(9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
      TButtonPanel::set_text((TButtonPanel *)*piVar5,0,0x240a);
      TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x2408);
      TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x240b);
      TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x2405);
      TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x2407);
      TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x2409);
      iVar3 = param_1[1]._padding_;
      *(undefined4 *)(iVar3 + 0x298) = 0x1b;
      *(undefined4 *)(iVar3 + 0x29c) = 0;
      TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*piVar5);
      ppTVar6 = apTStack_24;
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppTVar6 = (TPanel *)*piVar5;
        piVar5 = piVar5 + 1;
        ppTVar6 = ppTVar6 + 1;
      }
      TPanel::set_tab_order((TPanel *)param_1,apTStack_24,6);
    }
  }
LAB_004b6bc8:
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b6bdd
// Address: 004b6bdd
// XREFS: None
TribeSPMenuScreen * __thiscall FUN_004b6bdd(TribeSPMenuScreen *param_1,byte param_2)
{
  TribeSPMenuScreen::~TribeSPMenuScreen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b6bfe
// Address: 004b6bfe
// XREFS: None
void __fastcall FUN_004b6bfe(TScreenPanel *param_1)
{
  int iVar1;
  TPanel **ppTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f6f8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeSPMenuScreen::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  ppTVar2 = (TPanel **)&param_1[1].field_0x4;
  iVar1 = 7;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x20);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004b6c81
// Address: 004b6c81
// XREFS: None
void __fastcall FUN_004b6c81(TPanel *param_1)
{
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004b6cb1
// Address: 004b6cb1
// XREFS: None
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Name_Selection_Screen: "Name Selection Screen"
// [HELPER] s_Select_Scenario_Screen: "Select Scenario Screen"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
long __thiscall
FUN_004b6cb1(TEasy_Panel *param_1,TribeMPSetupScreen *param_2,int param_3,ulong param_4,
            TRIBE_Dialog_Name *param_5)
{
  long lVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f75d;
  *unaff_FS_OFFSET = &uStack_c;
  if ((param_2 != (TribeMPSetupScreen *)0x0) && (param_3 == 1)) {
    if (param_2 == (TribeMPSetupScreen *)param_1[1]._padding_) {
      RGE_Base_Game::setCampaignGame(rge_base_game,0);
      RGE_Base_Game::setSavedGame(rge_base_game,0);
      RGE_Base_Game::setScenarioGame(rge_base_game,0);
      TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game,'\0');
      TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game,'\0');
      RGE_Base_Game::disable_input(rge_base_game);
      param_2 = (TribeMPSetupScreen *)operator_new(0x890);
      uStack_4 = 0;
    }
    else {
      if (param_2 != (TribeMPSetupScreen *)param_1[1]._padding_) {
        if (param_2 == (TribeMPSetupScreen *)param_1[1]._padding_) {
          RGE_Base_Game::setCampaignGame(rge_base_game,0);
          RGE_Base_Game::setSavedGame(rge_base_game,0);
          RGE_Base_Game::setScenarioGame(rge_base_game,1);
          TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game,'\0');
          TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game,'\0');
          RGE_Base_Game::disable_input(rge_base_game);
          param_2 = (TribeMPSetupScreen *)operator_new(0x4d8);
          uStack_4 = 2;
          if (param_2 != (TribeMPSetupScreen *)0x0) {
            TribeSelectScenarioScreen::TribeSelectScenarioScreen
                      ((TribeSelectScenarioScreen *)param_2);
          }
          uStack_4 = 0xffffffff;
          TPanelSystem::setCurrentPanel(&panel_system,s_Select_Scenario_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
          *unaff_FS_OFFSET = uStack_c;
          return 1;
        }
        if (param_2 == (TribeMPSetupScreen *)param_1[1]._padding_) {
          RGE_Base_Game::disable_input(rge_base_game);
          param_2 = (TribeMPSetupScreen *)operator_new(0x494);
          uStack_4 = 3;
          if (param_2 != (TribeMPSetupScreen *)0x0) {
            TribeLoadSavedGameScreen::TribeLoadSavedGameScreen((TribeLoadSavedGameScreen *)param_2);
          }
          uStack_4 = 0xffffffff;
          TPanelSystem::setCurrentPanel(&panel_system,s_Load_Saved_Game_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
          *unaff_FS_OFFSET = uStack_c;
          return 1;
        }
        if (param_2 == (TribeMPSetupScreen *)param_1[1]._padding_) {
          RGE_Base_Game::disable_input(rge_base_game);
          param_2 = (TribeMPSetupScreen *)0x0;
          lVar1 = RGE_Game_Info::get_people_list
                            (rge_base_game->player_game_info,(char ***)&param_2,&param_3);
          if (0 < lVar1) {
            iVar2 = 0;
            if (0 < lVar1) {
              do {
                free(*(char **)((int)param_2 + iVar2 * 4));
                iVar2 = iVar2 + 1;
              } while (iVar2 < lVar1);
            }
            free(param_2);
            if (0 < lVar1) {
              param_5 = (TRIBE_Dialog_Name *)operator_new(0x4a0);
              uStack_4 = 4;
              if (param_5 != (TRIBE_Dialog_Name *)0x0) {
                TRIBE_Screen_Name::TRIBE_Screen_Name((TRIBE_Screen_Name *)param_5);
              }
              uStack_4 = 0xffffffff;
              TPanelSystem::setCurrentPanel(&panel_system,s_Name_Selection_Screen,0);
              TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
              *unaff_FS_OFFSET = uStack_c;
              return 1;
            }
          }
          param_5 = (TRIBE_Dialog_Name *)operator_new(0x4a4);
          uStack_4 = 5;
          if (param_5 != (TRIBE_Dialog_Name *)0x0) {
            TRIBE_Dialog_Name::TRIBE_Dialog_Name(param_5,(TScreenPanel *)param_1);
            *unaff_FS_OFFSET = uStack_c;
            return 1;
          }
        }
        else {
          if (param_2 == (TribeMPSetupScreen *)param_1[1]._padding_) {
            RGE_Base_Game::disable_input(rge_base_game);
            param_2 = (TribeMPSetupScreen *)operator_new(0x4b0);
            uStack_4 = 6;
            if (param_2 != (TribeMPSetupScreen *)0x0) {
              TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu((TRIBE_Screen_Main_Menu *)param_2);
            }
            uStack_4 = 0xffffffff;
            TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
            TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
            *unaff_FS_OFFSET = uStack_c;
            return 1;
          }
          if (param_2 != (TribeMPSetupScreen *)param_1[1]._padding_) goto LAB_004b710b;
          RGE_Base_Game::close(rge_base_game);
        }
        *unaff_FS_OFFSET = uStack_c;
        return 1;
      }
      RGE_Base_Game::setCampaignGame(rge_base_game,0);
      RGE_Base_Game::setSavedGame(rge_base_game,0);
      RGE_Base_Game::setScenarioGame(rge_base_game,0);
      TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game,'\x01');
      TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game,'\0');
      RGE_Base_Game::disable_input(rge_base_game);
      param_2 = (TribeMPSetupScreen *)operator_new(0x890);
      uStack_4 = 1;
    }
    if (param_2 != (TribeMPSetupScreen *)0x0) {
      TribeMPSetupScreen::TribeMPSetupScreen(param_2);
    }
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
    TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
LAB_004b710b:
  lVar1 = TEasy_Panel::action(param_1,(TPanel *)param_2,param_3,param_4,(ulong)param_5);
  *unaff_FS_OFFSET = uStack_c;
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_004b7132
// Address: 004b7132
// XREFS: None
// [HELPER] s_Achievements_Screen: "Achievements Screen"
// [HELPER] s_scr2: "scr2"
// [HELPER] s_scr3: "scr3"
TEasy_Panel * __thiscall
FUN_004b7132(TEasy_Panel *param_1,char *param_2,char *param_3,char *param_4,long param_5)
{
  char cVar1;
  TEasy_Panel *this;
  TEasy_Panel *pTVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 *unaff_FS_OFFSET;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f77b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,param_2);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Screen_Status_Message::_vftable_;
  param_1[1]._padding_ = 0;
  this = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
  if ((param_4 == (char *)0x0) && (param_5 == -1)) {
    if ((this == (TEasy_Panel *)0x0) ||
       (pTVar2 = (TEasy_Panel *)TPanelSystem::panel(&panel_system,s_Achievements_Screen),
       this == pTVar2)) {
      acStack_110[0] = '\0';
      param_5 = -1;
    }
    else {
      pcVar3 = TEasy_Panel::get_info_file(this);
      uVar6 = 0xffffffff;
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
      pcVar8 = acStack_110;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar8 = pcVar8 + 1;
      }
      param_5 = TEasy_Panel::get_info_id(this);
    }
  }
  else {
    uVar6 = 0xffffffff;
    do {
      pcVar3 = param_4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar3 = param_4 + 1;
      cVar1 = *param_4;
      param_4 = pcVar3;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar3 = pcVar3 + -uVar6;
    pcVar8 = acStack_110;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar8 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  if (acStack_110[0] == '\0') {
    iVar4 = RGE_Base_Game::multiplayerGame(rge_base_game);
    if (iVar4 == 0) {
      uVar6 = 0xffffffff;
      pcVar3 = &s_scr2;
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
      pcVar8 = acStack_110;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar8 = pcVar8 + 4;
      }
      param_5 = 0xc384;
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar8 = pcVar8 + 1;
      }
    }
    else {
      uVar6 = 0xffffffff;
      pcVar3 = &s_scr3;
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
      pcVar8 = acStack_110;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar8 = pcVar8 + 4;
      }
      param_5 = 0xc385;
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar8 = pcVar8 + 1;
      }
    }
  }
  lVar5 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,acStack_110,param_5,0
                             );
  if (lVar5 == 0) {
    param_1->_padding_ = 1;
  }
  else {
    TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
    TEasy_Panel::create_text
              (param_1,(TPanel *)param_1,(TTextPanel **)(param_1 + 1),param_3,0x28,0x28,0x230,400,4,
               1,1,1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b732e
// Address: 004b732e
// XREFS: None
// [HELPER] s_Achievements_Screen: "Achievements Screen"
// [HELPER] s_scr2: "scr2"
// [HELPER] s_scr3: "scr3"
TEasy_Panel * __thiscall
FUN_004b732e(TEasy_Panel *param_1,char *param_2,int param_3,char *param_4,long param_5)
{
  char cVar1;
  TEasy_Panel *this;
  TEasy_Panel *pTVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 *unaff_FS_OFFSET;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f79b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,param_2);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Screen_Status_Message::_vftable_;
  param_1[1]._padding_ = 0;
  this = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
  if ((param_4 == (char *)0x0) && (param_5 == -1)) {
    if ((this == (TEasy_Panel *)0x0) ||
       (pTVar2 = (TEasy_Panel *)TPanelSystem::panel(&panel_system,s_Achievements_Screen),
       this == pTVar2)) {
      acStack_110[0] = '\0';
      param_5 = -1;
    }
    else {
      pcVar3 = TEasy_Panel::get_info_file(this);
      uVar6 = 0xffffffff;
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
      pcVar8 = acStack_110;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar8 = pcVar8 + 1;
      }
      param_5 = TEasy_Panel::get_info_id(this);
    }
  }
  else {
    uVar6 = 0xffffffff;
    do {
      pcVar3 = param_4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar3 = param_4 + 1;
      cVar1 = *param_4;
      param_4 = pcVar3;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar3 = pcVar3 + -uVar6;
    pcVar8 = acStack_110;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar8 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  if (acStack_110[0] == '\0') {
    iVar4 = RGE_Base_Game::multiplayerGame(rge_base_game);
    if (iVar4 == 0) {
      uVar6 = 0xffffffff;
      pcVar3 = &s_scr2;
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
      pcVar8 = acStack_110;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar8 = pcVar8 + 4;
      }
      param_5 = 0xc384;
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar8 = pcVar8 + 1;
      }
    }
    else {
      uVar6 = 0xffffffff;
      pcVar3 = &s_scr3;
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
      pcVar8 = acStack_110;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar8 = pcVar8 + 4;
      }
      param_5 = 0xc385;
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar8 = pcVar8 + 1;
      }
    }
  }
  lVar5 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,acStack_110,param_5,0
                             );
  if (lVar5 == 0) {
    param_1->_padding_ = 1;
  }
  else {
    TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
    TEasy_Panel::create_text
              (param_1,(TPanel *)param_1,(TTextPanel **)(param_1 + 1),param_3,0x28,0x28,0x230,400,4,
               1,1,1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b7556
// Address: 004b7556
// XREFS: None
void __thiscall FUN_004b7556(int param_1,undefined4 param_2)
{
  (**(code **)(**(int **)(param_1 + 0x478) + 0xe8))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004b7576
// Address: 004b7576
// XREFS: None
void __thiscall FUN_004b7576(int param_1,undefined4 param_2)
{
  (**(code **)(**(int **)(param_1 + 0x478) + 0xe4))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004b7596
// Address: 004b7596
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Cancel: "Cancel"
// [HELPER] s_Civilization_Selection: "Civilization Selection"
// [HELPER] s_Previous_Screen: "Previous Screen"
// [HELPER] s_Select_Tribe_Screen: "Select Tribe Screen"
// [HELPER] s_bgA1024: "bgA1024"
// [HELPER] s_bgA640: "bgA640"
// [HELPER] s_bgA800: "bgA800"
TribeSelectTribeScreen * __fastcall FUN_004b7596(TribeSelectTribeScreen *param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  TPicturePanel *pTVar5;
  RGE_Font *pRVar6;
  TTextPanel *pTVar7;
  TDigital *pTVar8;
  TButtonPanel *pTVar9;
  uint uVar10;
  uint uVar11;
  TButtonPanel **ppTVar12;
  char *pcVar13;
  char *pcVar14;
  undefined4 *puVar15;
  undefined4 *unaff_FS_OFFSET;
  void *pvVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  undefined4 auStack_40 [2];
  undefined1 uStack_38;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f81a;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Select_Tribe_Screen);
  param_1->_padding_ = (int)&TribeSelectTribeScreen::_vftable_;
  param_1->screenText = (char **)0x0;
  iStack_4 = 0;
  lVar4 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,(char *)0x0,0,1);
  if (lVar4 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  iVar21 = *(int *)(param_1->_padding_ + 0x18);
  if (iVar21 < 800) {
    pcVar13 = &s_bgA640;
  }
  else {
    pcVar13 = s_bgA800;
    if (0x3ff < iVar21) {
      pcVar13 = s_bgA1024;
    }
  }
  uVar10 = 0xffffffff;
  do {
    pcVar14 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar14 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar14;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  pcVar13 = pcVar14 + -uVar10;
  pcVar14 = (char *)auStack_40;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar14 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar14 = pcVar14 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar14 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar14 = pcVar14 + 1;
  }
  pTVar5 = (TPicturePanel *)operator_new(0x11c);
  iStack_4._0_1_ = 1;
  if (pTVar5 == (TPicturePanel *)0x0) {
    pTVar5 = (TPicturePanel *)0x0;
  }
  else {
    pTVar5 = (TPicturePanel *)TPicturePanel::TPicturePanel(pTVar5);
  }
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  param_1->background = pTVar5;
  if (pTVar5 == (TPicturePanel *)0x0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  lVar4 = TPicturePanel::setup
                    (pTVar5,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,0,0,0,0,
                     (char *)auStack_40,-1,0,1);
  if (lVar4 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  iVar21 = (param_1->_padding_ * 0x1e0) / 0x1e0;
  iVar20 = (param_1->_padding_ * 0x280) / 0x280;
  (**(code **)(param_1->background->_padding_ + 0x18))
            (2,0,0,0,0,iVar20,iVar20,iVar21,iVar21,0,0,0,0);
  pRVar6 = RGE_Base_Game::get_font(rge_base_game,1);
  pTVar7 = (TTextPanel *)operator_new(0x188);
  uStack_38 = 2;
  if (pTVar7 == (TTextPanel *)0x0) {
    pTVar7 = (TTextPanel *)0x0;
  }
  else {
    pTVar7 = (TTextPanel *)TTextPanel::TTextPanel(pTVar7);
  }
  uStack_38 = 0;
  param_1->title = pTVar7;
  if (pTVar7 == (TTextPanel *)0x0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = auStack_40[0];
    return param_1;
  }
  TTextPanel::setup(pTVar7,(TDrawArea *)param_1->_padding_,(TPanel *)param_1->background,
                    (param_1->_padding_ * 0x14) / 0x280,(param_1->_padding_ * 0x14) / 0x1e0,
                    (param_1->_padding_ * 600) / 0x280,(param_1->_padding_ * 0x1e) / 0x1e0,
                    pRVar6->font,pRVar6->font_wid,pRVar6->font_hgt,(char *)0x0,0,'\0',0,'\0',0,
                    s_Civilization_Selection);
  pTVar8 = RGE_Base_Game::get_sound(rge_base_game,0);
  pRVar6 = RGE_Base_Game::get_font(rge_base_game,0);
  ppTVar12 = param_1->tribeButton;
  iVar21 = 0;
  iVar20 = 0;
  iVar22 = 0;
  do {
    pTVar9 = (TButtonPanel *)operator_new(0x2b8);
    uStack_38 = 3;
    if (pTVar9 == (TButtonPanel *)0x0) {
      pTVar9 = (TButtonPanel *)0x0;
    }
    else {
      pTVar9 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar9);
    }
    uStack_38 = 0;
    *ppTVar12 = pTVar9;
    if (pTVar9 == (TButtonPanel *)0x0) goto LAB_004b7c85;
    iVar2 = param_1->_padding_;
    iVar3 = param_1->_padding_;
    TButtonPanel::setup(pTVar9,(TDrawArea *)param_1->_padding_,(TPanel *)param_1->background,
                        (iVar3 * 0x14) / 0x280 + (iVar21 * iVar3) / 0x280,
                        (iVar2 * 0x32) / 0x1e0 + (iVar20 * iVar2 * 0x73) / 0x1e0,
                        (iVar3 * 200) / 0x280,(iVar2 * 0x6e) / 0x1e0,DrawTextA,pTVar8,NotifyAction,0
                       );
    lVar19 = -1;
    lVar18 = -1;
    lVar4 = pRVar6->font_hgt;
    lVar17 = pRVar6->font_wid;
    pvVar16 = pRVar6->font;
    pcVar13 = TribeSelectTribeScreen::tribeName(param_1,iVar22);
    TButtonPanel::set_text_info(*ppTVar12,pcVar13,pvVar16,lVar17,lVar4,lVar18,lVar19);
    if ((iVar22 == 2) || (iVar22 == 5)) {
      iVar20 = -1;
      iVar21 = iVar21 + 200;
    }
    iVar22 = iVar22 + 1;
    ppTVar12 = ppTVar12 + 1;
    iVar20 = iVar20 + 1;
  } while (iVar22 < 9);
  pRVar6 = RGE_Base_Game::get_font(rge_base_game,0xb);
  pTVar7 = (TTextPanel *)operator_new(0x188);
  uStack_38 = 4;
  if (pTVar7 == (TTextPanel *)0x0) {
    pTVar7 = (TTextPanel *)0x0;
  }
  else {
    pTVar7 = (TTextPanel *)TTextPanel::TTextPanel(pTVar7);
  }
  uStack_38 = 0;
  param_1->tribeText = pTVar7;
  if (pTVar7 == (TTextPanel *)0x0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = auStack_40[0];
    return param_1;
  }
  TTextPanel::setup(pTVar7,(TDrawArea *)param_1->_padding_,(TPanel *)param_1->background,
                    (param_1->_padding_ * 0x14) / 0x280,(param_1->_padding_ * 400) / 0x1e0,
                    (param_1->_padding_ * 0x1fe) / 0x280,(param_1->_padding_ * 0x3c) / 0x1e0,
                    pRVar6->font,pRVar6->font_wid,pRVar6->font_hgt,(char *)0x0,0,'\0',0,'\0',0,s_);
  TTextPanel::set_alignment(param_1->tribeText,AlignTop,AlignWordwrap);
  pTVar9 = (TButtonPanel *)operator_new(0x2b8);
  uStack_38 = 5;
  if (pTVar9 == (TButtonPanel *)0x0) {
    pTVar9 = (TButtonPanel *)0x0;
  }
  else {
    pTVar9 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar9);
  }
  uStack_38 = 0;
  param_1->okButton = pTVar9;
  if (pTVar9 == (TButtonPanel *)0x0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = auStack_40[0];
    return param_1;
  }
  TButtonPanel::setup(pTVar9,(TDrawArea *)param_1->_padding_,(TPanel *)param_1->background,
                      (param_1->_padding_ * 500) / 0x280,(param_1->_padding_ * 400) / 0x1e0,
                      (param_1->_padding_ * 0x78) / 0x280,(param_1->_padding_ * 0x1e) / 0x1e0,
                      DrawTextA,pTVar8,NotifyAction,0);
  TButtonPanel::set_text_info
            (param_1->okButton,s_Previous_Screen,pRVar6->font,pRVar6->font_wid,pRVar6->font_hgt,-1,
             -1);
  pTVar9 = (TButtonPanel *)operator_new(0x2b8);
  uStack_38 = 6;
  if (pTVar9 == (TButtonPanel *)0x0) {
    pTVar9 = (TButtonPanel *)0x0;
  }
  else {
    pTVar9 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar9);
  }
  uStack_38 = 0;
  param_1->cancelButton = pTVar9;
  if (pTVar9 != (TButtonPanel *)0x0) {
    TButtonPanel::setup(pTVar9,(TDrawArea *)param_1->_padding_,(TPanel *)param_1->background,
                        (param_1->_padding_ * 500) / 0x280,(param_1->_padding_ * 0x1b8) / 0x1e0,
                        (param_1->_padding_ * 0x78) / 0x280,(param_1->_padding_ * 0x1e) / 0x1e0,
                        DrawTextA,pTVar8,NotifyAction,0);
    TButtonPanel::set_text_info
              (param_1->cancelButton,s_Cancel,pRVar6->font,pRVar6->font_wid,pRVar6->font_hgt,-1,-1);
    TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->background);
    TPanel::set_curr_child((TPanel *)param_1->background,(TPanel *)param_1->tribeButton[0]);
    TribeSelectTribeScreen::fillTribeText(param_1,0);
    ppTVar12 = param_1->tribeButton;
    puVar15 = (undefined4 *)&stack0xffffff98;
    for (iVar21 = 9; iVar21 != 0; iVar21 = iVar21 + -1) {
      *puVar15 = *ppTVar12;
      ppTVar12 = ppTVar12 + 1;
      puVar15 = puVar15 + 1;
    }
    TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&stack0xffffff98,10);
    *unaff_FS_OFFSET = auStack_40[0];
    return param_1;
  }
LAB_004b7c85:
  param_1->_padding_ = 1;
  *unaff_FS_OFFSET = auStack_40[0];
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b7dc5
// Address: 004b7dc5
// XREFS: None
TribeSelectTribeScreen * __thiscall FUN_004b7dc5(TribeSelectTribeScreen *param_1,byte param_2)
{
  TribeSelectTribeScreen::~TribeSelectTribeScreen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b7dee
// Address: 004b7dee
// XREFS: None
void __fastcall FUN_004b7dee(TScreenPanel *param_1)
{
  int iVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f838;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeSelectTribeScreen::_vftable_;
  uStack_4 = 0;
  if (*(undefined4 **)&param_1[1].field_0x4 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x4)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x8 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x8)(1);
  }
  piVar2 = (int *)&param_1[1].field_0xc;
  iVar1 = 9;
  do {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (*(undefined4 **)&param_1[1].field_0x30 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x30)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x34 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x34)(1);
  }
  iVar1 = 0;
  if (0 < *(int *)&param_1[1].field_0x3c) {
    do {
      free(*(undefined4 *)(*(int *)&param_1[1].field_0x38 + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)&param_1[1].field_0x3c);
  }
  free(*(undefined4 *)&param_1[1].field_0x38);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004b7ed3
// Address: 004b7ed3
// XREFS: None
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_Select_Tribe_Screen: "Select Tribe Screen"
long __thiscall
FUN_004b7ed3(TribeSelectTribeScreen *param_1,TButtonPanel *param_2,int param_3,ulong param_4,
            ulong param_5)
{
  int iVar1;
  long lVar2;
  TButtonPanel **ppTVar3;
  
  if ((param_2 == param_1->okButton) || (param_2 == param_1->cancelButton)) {
    if (param_3 == 1) {
      TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Select_Tribe_Screen);
      return 1;
    }
  }
  else if (param_3 == 1) {
    iVar1 = 0;
    ppTVar3 = param_1->tribeButton;
    do {
      if (param_2 == *ppTVar3) {
        TribeSelectTribeScreen::fillTribeText(param_1,iVar1);
        return 1;
      }
      iVar1 = iVar1 + 1;
      ppTVar3 = ppTVar3 + 1;
    } while (iVar1 < 9);
  }
  lVar2 = TEasy_Panel::action((TEasy_Panel *)param_1,(TPanel *)param_2,param_3,param_4,param_5);
  return lVar2;
}

// --------------------------------------------------

// Function: FUN_004b7f6c
// Address: 004b7f6c
// XREFS: None
// [HELPER] s_Assyrian_information_here_: "Assyrian information here."
// [HELPER] s_Babylonian_information_here_: "Babylonian information here."
// [HELPER] s_Egyptian_information_here_: "Egyptian information here."
// [HELPER] s_Greek_information_here_: "Greek information here."
// [HELPER] s_Hittite_information_here_: "Hittite information here."
// [HELPER] s_Isrealite_information_here_: "Isrealite information here."
// [HELPER] s_Minoan_information_here_: "Minoan information here."
// [HELPER] s_Phoenician_information_here_: "Phoenician information here."
// [HELPER] s_Sumerian_information_here_: "Sumerian information here."
void __thiscall FUN_004b7f6c(int param_1,undefined4 param_2)
{
  int iVar1;
  char *pcVar2;
  
  switch(param_2) {
  case 0:
    pcVar2 = s_Assyrian_information_here_;
    iVar1 = **(int **)(param_1 + 0x480);
    break;
  case 1:
    (**(code **)(**(int **)(param_1 + 0x480) + 0xe8))(s_Babylonian_information_here_);
    goto switchD_004b7f80_default;
  case 2:
    pcVar2 = s_Egyptian_information_here_;
    iVar1 = **(int **)(param_1 + 0x480);
    break;
  case 3:
    (**(code **)(**(int **)(param_1 + 0x480) + 0xe8))(s_Greek_information_here_);
    goto switchD_004b7f80_default;
  case 4:
    pcVar2 = s_Hittite_information_here_;
    iVar1 = **(int **)(param_1 + 0x480);
    break;
  case 5:
    (**(code **)(**(int **)(param_1 + 0x480) + 0xe8))(s_Isrealite_information_here_);
    goto switchD_004b7f80_default;
  case 6:
    pcVar2 = s_Minoan_information_here_;
    iVar1 = **(int **)(param_1 + 0x480);
    break;
  case 7:
    (**(code **)(**(int **)(param_1 + 0x480) + 0xe8))(s_Phoenician_information_here_);
    goto switchD_004b7f80_default;
  case 8:
    pcVar2 = s_Sumerian_information_here_;
    iVar1 = **(int **)(param_1 + 0x480);
    break;
  default:
    goto switchD_004b7f80_default;
  }
  (**(code **)(iVar1 + 0xe8))(pcVar2);
switchD_004b7f80_default:
  TTextPanel::scroll(*(TTextPanel **)(param_1 + 0x480),'\x06',0,1);
  return;
}

// --------------------------------------------------

// Function: FUN_004b8042
// Address: 004b8042
// XREFS: None
// [HELPER] s_Assyrian: "Assyrian"
// [HELPER] s_Babylonian: "Babylonian"
// [HELPER] s_Egyptian: "Egyptian"
// [HELPER] s_Greek: "Greek"
// [HELPER] s_Hittite: "Hittite"
// [HELPER] s_Isrealite: "Isrealite"
// [HELPER] s_Minoan: "Minoan"
// [HELPER] s_No_Culture: "No Culture"
// [HELPER] s_Phoenician: "Phoenician"
// [HELPER] s_Sumerian: "Sumerian"
/* WARNING: Instruction at (ram,0x004b80ad) overlaps instruction at (ram,0x004b80ac)
    */

undefined6 __fastcall FUN_004b8042(int param_1,undefined2 param_2,undefined4 param_3)
{
  char *pcVar1;
  char cVar2;
  undefined4 in_EAX;
  char cVar3;
  char cVar4;
  char cVar5;
  byte *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  char unaff_retaddr;
  
  LOCK();
  *(int *)(unaff_EDI + 0x4b) = unaff_EDI;
  UNLOCK();
  pcVar1 = (char *)(param_1 + -0x51ffb481);
  cVar2 = *pcVar1;
  *pcVar1 = *pcVar1 + (char)unaff_EBX;
  cVar4 = (char)param_2;
  cVar5 = (char)((ushort)param_2 >> 8);
  if (*pcVar1 != '\0' && SCARRY1(cVar2,(char)unaff_EBX) == *pcVar1 < '\0') {
    out(*unaff_ESI,param_2);
    param_2 = CONCAT11(cVar5,cVar4 + unaff_retaddr);
switchD_004b8079_caseD_4:
    return CONCAT24(param_2,s_Hittite);
  }
  pcVar1 = (char *)(unaff_EBP + -0x2dffb481);
  cVar2 = *pcVar1;
  cVar3 = (char)((uint)unaff_EBX >> 8);
  *pcVar1 = *pcVar1 + cVar3;
  if (*pcVar1 == '\0' || SCARRY1(cVar2,cVar3) != *pcVar1 < '\0') {
    cVar2 = (char)((uint)in_EAX >> 8);
    cVar3 = (char)param_1 + cVar2;
    if (cVar3 == '\0' || SCARRY1((char)param_1,cVar2) != cVar3 < '\0') {
      cVar2 = cVar5 * '\x02';
      param_2 = CONCAT11(cVar2,cVar4);
      if (cVar2 == '\0' || SCARRY1(cVar5,cVar5) != cVar2 < '\0') {
        cRam1a004b80 = cRam1a004b80 + (char)in_EAX;
        *unaff_EBX = *unaff_EBX | 0x90;
        switch(param_3) {
        case 0:
          return CONCAT24(param_2,s_Assyrian);
        case 1:
          return CONCAT24(param_2,s_Babylonian);
        case 2:
          return CONCAT24(param_2,s_Egyptian);
        case 3:
          return CONCAT24(param_2,s_Greek);
        case 4:
          goto switchD_004b8079_caseD_4;
        case 5:
          goto switchD_004b8079_caseD_5;
        case 6:
          goto switchD_004b8079_caseD_6;
        case 7:
          return CONCAT24(param_2,s_Phoenician);
        case 8:
          return CONCAT24(param_2,s_Sumerian);
        default:
          return CONCAT24(param_2,s_No_Culture);
        }
      }
      out(*unaff_ESI,param_2);
      param_2 = CONCAT11(cVar2,cVar4 + unaff_retaddr);
switchD_004b8079_caseD_6:
      return CONCAT24(param_2,s_Minoan);
    }
  }
  else {
    out(*unaff_ESI,param_2);
    param_2 = CONCAT11(cVar5,cVar4 + unaff_retaddr);
  }
switchD_004b8079_caseD_5:
  return CONCAT24(param_2,s_Isrealite);
}

// --------------------------------------------------

// Function: FUN_004b87ab
// Address: 004b87ab
// XREFS: None
TRIBE_Mission_Screen * __thiscall FUN_004b87ab(TRIBE_Mission_Screen *param_1,byte param_2)
{
  TRIBE_Mission_Screen::~TRIBE_Mission_Screen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b87ce
// Address: 004b87ce
// XREFS: None
void __fastcall FUN_004b87ce(TScreenPanel *param_1)
{
  int *piVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f878;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Mission_Screen::_vftable_;
  uStack_4 = 0;
  if (((param_1[1].field_0x1c == '\0') && (rge_base_game->prog_info->use_sound != 0)) &&
     (rge_base_game->sound_system != (TSound_Driver *)0x0)) {
    TSound_Driver::stop_stream(rge_base_game->sound_system);
  }
  if (*(undefined4 **)(param_1 + 1) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 1))(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x4 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x4)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x8 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x8)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0xc != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0xc)(1);
  }
  piVar1 = (int *)&param_1[1].field_0x10;
  iVar2 = 3;
  do {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004b88a3
// Address: 004b88a3
// XREFS: None
void __fastcall FUN_004b88a3(TPanel *param_1)
{
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004b88d1
// Address: 004b88d1
// XREFS: None
// [HELPER] s_scr_vc__draw: "scr_vc::draw"
void __fastcall FUN_004b88d1(TScreenPanel *param_1)
{
  int iVar1;
  uchar *puVar2;
  long lVar3;
  int iVar4;
  
  TScreenPanel::draw(param_1);
  if (*(int *)&param_1[1].field_0x20 != 0) {
    iVar1 = *(int *)param_1;
    (**(code **)(iVar1 + 0x28))(0);
    if (*(int *)&param_1->field_0x38 == 2) {
      TDrawArea::Clear(*(TDrawArea **)&param_1->field_0x20,(tagRECT *)&param_1->field_0x24,
                       (uint)(byte)param_1->field_0x454);
    }
    puVar2 = TDrawArea::Lock(*(TDrawArea **)&param_1->field_0x20,s_scr_vc__draw,1);
    if (puVar2 != (uchar *)0x0) {
      if (*(int *)&param_1->field_0x14 < 0x281) {
        iVar4 = *(int *)&param_1->field_0x10 + 0xa6;
        lVar3 = *(int *)&param_1->field_0xc + 7;
      }
      else if (*(int *)&param_1->field_0x14 < 0x321) {
        iVar4 = *(int *)&param_1->field_0x10 + 0x118;
        lVar3 = *(int *)&param_1->field_0xc + 0x53;
      }
      else {
        iVar4 = *(int *)&param_1->field_0x10 + 0x16b;
        lVar3 = *(int *)&param_1->field_0xc + 0xc5;
      }
      TPicture::Draw(*(TPicture **)&param_1[1].field_0x20,*(TDrawArea **)&param_1->field_0x20,lVar3,
                     iVar4,0,0);
      TDrawArea::Unlock(*(TDrawArea **)&param_1->field_0x20,s_scr_vc__draw);
    }
    (**(code **)(iVar1 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004b899f
// Address: 004b899f
// XREFS: None
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Mission_Dialog: "Mission Dialog"
long __thiscall
FUN_004b899f(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  char *pcVar1;
  int iVar2;
  long lVar3;
  
  if (param_3 == 1) {
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      iVar2 = *(int *)param_1[1]._padding_;
      pcVar1 = RGE_Scenario::Get_message(rge_base_game->world->scenario,4);
      (**(code **)(iVar2 + 0xe8))(pcVar1);
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      iVar2 = *(int *)param_1[1]._padding_;
      pcVar1 = RGE_Scenario::Get_message(rge_base_game->world->scenario,0);
      (**(code **)(iVar2 + 0xe8))(pcVar1);
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      iVar2 = *(int *)param_1[1]._padding_;
      pcVar1 = RGE_Scenario::Get_message(rge_base_game->world->scenario,1);
      (**(code **)(iVar2 + 0xe8))(pcVar1);
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      if ((char)param_1[1]._padding_ == '\0') {
        TRIBE_Game::create_game_screen((TRIBE_Game *)rge_base_game);
      }
      else {
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
        if ((iVar2 == 1) && (rge_base_game->save_paused == 0)) {
          RGE_Base_Game::set_paused(rge_base_game,0,0);
        }
      }
      TPanelSystem::destroyPanel(&panel_system,s_Mission_Dialog);
      return 1;
    }
  }
  lVar3 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  return lVar3;
}

// --------------------------------------------------

// Function: FUN_004b8ade
// Address: 004b8ade
// XREFS: None
// [HELPER] s_voice_wav: "voice.wav"
undefined4 __thiscall
FUN_004b8ade(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  if ((param_5 != 0) && (param_2 == 0x56)) {
    if (((*(char *)(param_1 + 0x494) == '\0') && (rge_base_game->prog_info->use_sound != 0)) &&
       (rge_base_game->sound_system != (TSound_Driver *)0x0)) {
      TSound_Driver::stream_file(rge_base_game->sound_system,s_voice_wav,0,0);
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004b8b2d
// Address: 004b8b2d
// XREFS: None
void __fastcall FUN_004b8b2d(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004b8dcb
// Address: 004b8dcb
// XREFS: None
void __fastcall FUN_004b8dcb(int *param_1)
{
  if (param_1[6] != 0) {
    if (param_1[1] == 1) {
      free(param_1[6]);
    }
    if (param_1[1] == 0) {
      RESFILE_Decommit_Mapped_Memory((uchar *)param_1[6],param_1[2]);
    }
  }
  if (*param_1 != 0) {
    if (param_1[1] == 1) {
      free(*param_1);
    }
    if (param_1[1] == 0) {
      RESFILE_Decommit_Mapped_Memory((uchar *)*param_1,param_1[2]);
    }
  }
  *param_1 = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004b8e3b
// Address: 004b8e3b
// XREFS: None
// [HELPER] s_1_10: "1.10"
// [HELPER] s_ERROR___: "ERROR: ("
// [HELPER] s___Bad_shape: ") Bad shape"
// [HELPER] s___Fshape_number_out_of_bounds: ") Fshape number out of bounds"
// [HELPER] s___shape_number_out_of_bounds: ") shape number out of bounds"
// [HELPER] s___shape_version_wrong: ") shape version wrong"
undefined4 __thiscall FUN_004b8e3b(int *param_1,int param_2,char *param_3)
{
  int *piVar1;
  char *pcVar2;
  char *pcStack_4;
  
  pcStack_4 = (char *)0x0;
  if ((*param_1 == 0) && (param_1[6] == 0)) {
    return 1;
  }
  if (*param_1 != 0) {
    piVar1 = (int *)param_1[4];
    if (piVar1 == (int *)0x0) {
      addstring(&pcStack_4,s_ERROR___,param_3);
      pcVar2 = s___Bad_shape;
      goto LAB_004b8f57;
    }
    if ((-1 < param_2) && (piVar1[1] <= param_2)) {
      addstring(&pcStack_4,s_ERROR___,param_3);
      addstring(&pcStack_4,pcStack_4,s___shape_number_out_of_bounds);
      free(pcStack_4);
      return 1;
    }
    if (*piVar1 != s_1_10._0_4_) {
      addstring(&pcStack_4,s_ERROR___,param_3);
      addstring(&pcStack_4,pcStack_4,s___shape_version_wrong);
      free(pcStack_4);
      return 1;
    }
  }
  if (((param_1[6] == 0) || (param_2 < 0)) || (param_2 < *(int *)(param_1[6] + 4))) {
    return 0;
  }
  addstring(&pcStack_4,s_ERROR___,param_3);
  pcVar2 = s___Fshape_number_out_of_bounds;
LAB_004b8f57:
  addstring(&pcStack_4,pcStack_4,pcVar2);
  free(pcStack_4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004b8f84
// Address: 004b8f84
// XREFS: None
undefined4 __fastcall FUN_004b8f84(int *param_1)
{
  if ((*param_1 == 0) && (param_1[6] == 0)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004b8fa5
// Address: 004b8fa5
// XREFS: None
// [HELPER] s_RGL_shape_resolution: "RGL_shape_resolution"
undefined4 __thiscall
FUN_004b8fa5(TShape *param_1,int param_2,undefined2 *param_3,undefined2 *param_4)
{
  int iVar1;
  uchar uVar2;
  
  if (param_1->FShape != (SLhape_File_Header *)0x0) {
    *param_3 = (short)param_1->shape_info[param_2].Width;
    *param_4 = (short)param_1->shape_info[param_2].Height;
    return 1;
  }
  if (-1 < param_2) {
    uVar2 = TShape::Check_shape(param_1,param_2,s_RGL_shape_resolution);
    if (uVar2 == '\0') {
      iVar1 = param_1->offsets[param_2].shape;
      param_1->shape_header = (Shape_Header *)(param_1->shape + iVar1);
      *param_3 = (short)((uint)((Shape_Header *)(param_1->shape + iVar1))->bounds >> 0x10);
      *param_4 = (short)param_1->shape_header->bounds;
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004b9034
// Address: 004b9034
// XREFS: None
// [HELPER] s_RGL_shape_count: "RGL_shape_count"
long __fastcall FUN_004b9034(TShape *param_1)
{
  uchar uVar1;
  SLhape_File_Header *pSVar2;
  
  uVar1 = TShape::Check_shape(param_1,-1,s_RGL_shape_count);
  if (uVar1 != '\0') {
    return 0;
  }
  pSVar2 = param_1->FShape;
  if (pSVar2 == (SLhape_File_Header *)0x0) {
    pSVar2 = (SLhape_File_Header *)param_1->head;
  }
  return pSVar2->Num_Shapes;
}

// --------------------------------------------------

// Function: FUN_004b9066
// Address: 004b9066
// XREFS: None
// [HELPER] s_RGL_shape_minxy: "RGL_shape_minxy"
uint __thiscall
FUN_004b9066(TShape *param_1,long *param_2,long *param_3,long *param_4,long *param_5,int param_6)
{
  int iVar1;
  long lVar2;
  uchar uVar3;
  uint in_EAX;
  undefined3 extraout_var;
  Shape_Info *pSVar4;
  
  if (-1 < param_6) {
    uVar3 = TShape::Check_shape(param_1,param_6,s_RGL_shape_minxy);
    in_EAX = CONCAT31(extraout_var,uVar3);
    if (uVar3 == '\0') {
      if (param_1->FShape != (SLhape_File_Header *)0x0) {
        *param_2 = -param_1->shape_info[param_6].Hotspot_X;
        *param_3 = -param_1->shape_info[param_6].Hotspot_Y;
        *param_4 = (param_1->shape_info[param_6].Width - param_1->shape_info[param_6].Hotspot_X) +
                   -1;
        pSVar4 = param_1->shape_info + param_6;
        *param_5 = (pSVar4->Height - pSVar4->Hotspot_Y) + -1;
        return CONCAT31((int3)((uint)pSVar4 >> 8),1);
      }
      iVar1 = param_1->offsets[param_6].shape;
      param_1->shape_header = (Shape_Header *)(param_1->shape + iVar1);
      *param_2 = ((Shape_Header *)(param_1->shape + iVar1))->xmin;
      *param_3 = param_1->shape_header->ymin;
      *param_4 = param_1->shape_header->xmax;
      lVar2 = param_1->shape_header->ymax;
      *param_5 = lVar2;
      return CONCAT31((int3)((uint)lVar2 >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_004b9135
// Address: 004b9135
// XREFS: None
// [HELPER] s_RGL_shape_draw: "RGL_shape_draw"
uint __thiscall FUN_004b9135(TShape *param_1,uint param_2,int param_3,int param_4)
{
  byte bVar1;
  SLhape_File_Header *pSVar2;
  int iVar3;
  bool bVar4;
  ulong *puVar5;
  uchar uVar6;
  Shape_Info *in_EAX;
  undefined3 extraout_var;
  Shape_Info *pSVar7;
  int iVar8;
  Shape_Header *pSVar9;
  uint uVar10;
  int iVar11;
  
  iVar3 = param_2;
  if (-1 < param_4) {
    uVar6 = TShape::Check_shape(param_1,param_4,s_RGL_shape_draw);
    in_EAX = (Shape_Info *)CONCAT31(extraout_var,uVar6);
    if (uVar6 == '\0') {
      pSVar2 = param_1->FShape;
      if (pSVar2 == (SLhape_File_Header *)0x0) {
        pSVar9 = (Shape_Header *)(param_1->shape + param_1->offsets[param_4].shape);
        param_1->shape_header = pSVar9;
        iVar11 = pSVar9->ymin;
        iVar8 = pSVar9->xmin;
        in_EAX = (Shape_Info *)(pSVar9 + 1);
        if ((((iVar11 <= param_3) && (param_3 <= pSVar9->ymax)) && (iVar8 <= (int)param_2)) &&
           ((int)param_2 <= pSVar9->xmax)) {
          if (iVar11 < param_3) {
            param_3 = param_3 - iVar11;
            do {
              bVar4 = false;
              pSVar7 = in_EAX;
              do {
                bVar1 = (byte)pSVar7->Shape_Data_Offsets;
                in_EAX = (Shape_Info *)((int)&pSVar7->Shape_Data_Offsets + 1);
                if ((bVar1 & 1) == 1) {
                  param_2 = (uint)(bVar1 >> 1);
                  if (bVar1 >> 1 == 0) {
LAB_004b9372:
                    in_EAX = (Shape_Info *)((int)&pSVar7->Shape_Data_Offsets + 2);
                  }
                  else {
                    in_EAX = (Shape_Info *)((int)&in_EAX->Shape_Data_Offsets + param_2);
                  }
                }
                else {
                  if ((bVar1 & 0xfe) != 0) goto LAB_004b9372;
                  bVar4 = true;
                }
                pSVar7 = in_EAX;
              } while (!bVar4);
              param_3 = param_3 + -1;
            } while (param_3 != 0);
          }
          bVar4 = false;
          pSVar7 = in_EAX;
          do {
            bVar1 = (byte)pSVar7->Shape_Data_Offsets;
            in_EAX = (Shape_Info *)((int)&pSVar7->Shape_Data_Offsets + 1);
            if ((bVar1 & 1) == 1) {
              param_2 = (uint)(bVar1 >> 1);
              if (bVar1 >> 1 == 0) {
                iVar8 = iVar8 + (uint)(byte)in_EAX->Shape_Data_Offsets;
                if (iVar3 < iVar8) break;
LAB_004b93d9:
                in_EAX = (Shape_Info *)((int)&pSVar7->Shape_Data_Offsets + 2);
              }
              else {
                iVar8 = iVar8 + param_2;
                if (iVar3 < iVar8) goto LAB_004b93eb;
                in_EAX = (Shape_Info *)((int)&in_EAX->Shape_Data_Offsets + param_2);
              }
            }
            else {
              param_2 = (uint)(bVar1 >> 1);
              if (bVar1 >> 1 != 0) {
                iVar8 = iVar8 + param_2;
                if (iVar8 <= iVar3) goto LAB_004b93d9;
                goto LAB_004b93eb;
              }
              bVar4 = true;
            }
            pSVar7 = in_EAX;
            if (bVar4) {
              return (uint)in_EAX & 0xffffff00;
            }
          } while( true );
        }
      }
      else {
        in_EAX = param_1->shape_info + param_4;
        iVar11 = in_EAX->Hotspot_X + param_2;
        iVar3 = in_EAX->Width;
        param_3 = in_EAX->Hotspot_Y + param_3;
        if (((-1 < iVar11) && (-1 < param_3)) && ((iVar11 < iVar3 && (param_3 < in_EAX->Height)))) {
          param_3 = param_3 * 4;
          iVar8 = (int)*(short *)(pSVar2->Version + param_3 + in_EAX->Shape_Outline_Offset);
          if (((-1 < iVar8) && (iVar8 <= iVar11)) &&
             ((iVar11 <= iVar3 - *(short *)(pSVar2->Version +
                                           param_3 + in_EAX->Shape_Outline_Offset + 2) &&
              (pSVar7 = (Shape_Info *)
                        (pSVar2->Version +
                        *(int *)(pSVar2->Version + param_3 + in_EAX->Shape_Data_Offsets)),
              in_EAX = (Shape_Info *)
                       (pSVar2->Version +
                       *(int *)(pSVar2->Version + param_3 + in_EAX->Shape_Data_Offsets)),
              iVar8 < iVar3)))) {
            while (in_EAX = pSVar7, iVar8 <= iVar11) {
              bVar1 = (byte)pSVar7->Shape_Data_Offsets;
              in_EAX = (Shape_Info *)((int)&pSVar7->Shape_Data_Offsets + 1);
              param_2 = (uint)bVar1;
              switch(bVar1 & 0xf) {
              case 0:
              case 4:
              case 8:
              case 0xc:
                iVar8 = iVar8 + (uint)(bVar1 >> 2);
                if (iVar11 < iVar8) goto LAB_004b93eb;
                in_EAX = (Shape_Info *)((int)&in_EAX->Shape_Data_Offsets + (uint)(bVar1 >> 2));
                break;
              case 1:
              case 5:
              case 9:
              case 0xd:
                iVar8 = iVar8 + (uint)(bVar1 >> 2);
                break;
              case 2:
                uVar10 = param_2 << 4 | (uint)(byte)in_EAX->Shape_Data_Offsets;
                in_EAX = (Shape_Info *)((int)&pSVar7->Shape_Data_Offsets + 2);
                iVar8 = iVar8 + uVar10;
                if (iVar11 < iVar8) {
LAB_004b93eb:
                  return CONCAT31((int3)((uint)in_EAX >> 8),1);
                }
                in_EAX = (Shape_Info *)((int)&in_EAX->Shape_Data_Offsets + uVar10);
                break;
              case 3:
                puVar5 = &in_EAX->Shape_Data_Offsets;
                in_EAX = (Shape_Info *)((int)&pSVar7->Shape_Data_Offsets + 2);
                iVar8 = iVar8 + (param_2 << 4 | (uint)(byte)*puVar5);
                break;
              case 6:
                uVar10 = (uint)(bVar1 >> 4);
                if (uVar10 == 0) {
                  uVar10 = (uint)(byte)in_EAX->Shape_Data_Offsets;
                  in_EAX = (Shape_Info *)((int)&pSVar7->Shape_Data_Offsets + 2);
                }
                iVar8 = iVar8 + uVar10;
                if (iVar11 < iVar8) goto LAB_004b93eb;
                in_EAX = (Shape_Info *)((int)&in_EAX->Shape_Data_Offsets + uVar10);
                break;
              case 7:
              case 10:
                uVar10 = (uint)(bVar1 >> 4);
                if (uVar10 == 0) {
                  uVar10 = (uint)(byte)in_EAX->Shape_Data_Offsets;
                  in_EAX = (Shape_Info *)((int)&pSVar7->Shape_Data_Offsets + 2);
                }
                iVar8 = iVar8 + uVar10;
                if (iVar11 < iVar8) goto LAB_004b93eb;
                in_EAX = (Shape_Info *)((int)&in_EAX->Shape_Data_Offsets + 1);
                break;
              case 0xb:
                uVar10 = (uint)(bVar1 >> 4);
                if (uVar10 == 0) {
                  uVar10 = (uint)(byte)in_EAX->Shape_Data_Offsets;
                  in_EAX = (Shape_Info *)((int)&pSVar7->Shape_Data_Offsets + 2);
                }
                iVar8 = iVar8 + uVar10;
                if (iVar11 < iVar8) goto LAB_004b93eb;
                break;
              default:
                goto switchD_004b9211_caseD_e;
              }
              pSVar7 = in_EAX;
              if (iVar3 <= iVar8) {
                return (uint)in_EAX & 0xffffff00;
              }
            }
          }
        }
      }
    }
  }
switchD_004b9211_caseD_e:
  return (uint)in_EAX & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_004b93fd
// Address: 004b93fd
// XREFS: None
// [HELPER] s_RGL_shape_draw: "RGL_shape_draw"
/* WARNING: Unable to track spacebase fully for stack */

uchar __fastcall FUN_004b93fd(TShape *param_1,char *param_2)
{
  char *pcVar1;
  SLhape_File_Header *pSVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uchar *puVar5;
  char cVar6;
  long lVar7;
  DClipInfo_List *this;
  uchar uVar8;
  char *in_EAX;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  char cVar14;
  Shape_Header *pSVar12;
  uint uVar13;
  int unaff_EBX;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 unaff_EBP;
  char *unaff_ESI;
  undefined4 unaff_EDI;
  SLhape_File_Header *pSVar18;
  char in_CF;
  int unaff_retaddr;
  
  param_2[-0x6da4ffb5] = (param_2[-0x6da4ffb5] - (char)param_2) - in_CF;
  cVar14 = (char)((uint)param_2 >> 8);
  *unaff_ESI = *unaff_ESI + cVar14;
  cVar6 = (char)unaff_EBX;
  pcVar1 = (char *)((int)in_EAX * 5 + 0x4b);
  *pcVar1 = *pcVar1 + (char)((uint)param_1 >> 8);
  *param_2 = *param_2 + cVar6 + -2;
  *(char *)(unaff_EBX + -0x71) = *(char *)(unaff_EBX + -0x71) + cVar6 + -3;
  pcVar1 = (char *)((int)param_2 * 5 + -0x6d59ffb5);
  *pcVar1 = *pcVar1 + (char)in_EAX;
  *in_EAX = *in_EAX + cVar6 + -5;
  *(char *)(unaff_EBX + -0x74) = *(char *)(unaff_EBX + -0x74) + cVar6 + -6;
  unaff_ESI[-0x38ffb46e] = unaff_ESI[-0x38ffb46e] + cVar14;
  *in_EAX = *in_EAX + cVar6 + -8;
  *(char *)(unaff_EBX + -0x77) = *(char *)(unaff_EBX + -0x77) + cVar6 + -9;
  iVar15 = unaff_EBX + -10;
  iVar15 = CONCAT22((short)((uint)iVar15 >> 0x10),
                    CONCAT11((char)((uint)iVar15 >> 8) + (char)((uint)in_EAX >> 8),(char)iVar15));
  iVar16 = iVar15 + -1;
  *(char *)(iVar15 + -0x74ace315) = *(char *)(iVar15 + -0x74ace315) + (char)param_2 + -1;
  *(undefined4 *)(unaff_retaddr + -4) = unaff_EBP;
  *(char **)(unaff_retaddr + -8) = unaff_ESI;
  *(undefined4 *)(unaff_retaddr + -0xc) = unaff_EDI;
  *(undefined1 *)(unaff_retaddr + 7) = 0;
  if (iVar16 < 0) {
    return '\0';
  }
  *(char **)(unaff_retaddr + -0x10) = s_RGL_shape_draw;
  *(int *)(unaff_retaddr + -0x14) = iVar16;
  *(undefined4 *)(unaff_retaddr + -0x18) = 0x4b9465;
  uVar8 = TShape::Check_shape(param_1,*(long *)(unaff_retaddr + -0x14),
                              *(char **)(unaff_retaddr + -0x10));
  iVar10 = SDI_Draw_Level;
  if (uVar8 != '\0') {
    return '\0';
  }
  if (param_1->FShape != (SLhape_File_Header *)0x0) {
    if (SDI_Capture_Info != 0) {
      pSVar18 = param_1->FShape + iVar15;
      *(long *)(unaff_retaddr + -0x10) = SDI_Object_ID;
      *(int *)(unaff_retaddr + -0x14) = iVar10;
      *(undefined4 *)(unaff_retaddr + -0x18) = 0x4b949c;
      uVar9 = _ASMGet_Color_Xform();
      iVar15 = *(int *)(pSVar18->Comment + 0x10);
      *(undefined4 *)(unaff_retaddr + -0x18) = uVar9;
      lVar7 = fog_next_shape;
      *(undefined4 *)(unaff_retaddr + -0x1c) = *(undefined4 *)(unaff_retaddr + 0x38);
      iVar16 = *(int *)(pSVar18->Comment + 0x14);
      *(long *)(unaff_retaddr + -0x20) = lVar7;
      iVar10 = SDI_Draw_Line;
      *(int *)(unaff_retaddr + -0x24) = *(int *)(unaff_retaddr + 0x2c) - iVar16;
      pSVar2 = param_1->FShape;
      *(int *)(unaff_retaddr + -0x28) = *(int *)(unaff_retaddr + 0x28) - iVar15;
      *(int *)(unaff_retaddr + -0x2c) = iVar10;
      *(SLhape_File_Header **)(unaff_retaddr + -0x30) = pSVar18;
      *(SLhape_File_Header **)(unaff_retaddr + -0x34) = pSVar2;
      this = SDI_List;
      *(undefined4 *)(unaff_retaddr + -0x38) = 0x4b94d2;
      DClipInfo_List::AddDrawNode
                (this,*(void **)(unaff_retaddr + -0x34),*(Shape_Info **)(unaff_retaddr + -0x30),
                 *(int *)(unaff_retaddr + -0x2c),*(int *)(unaff_retaddr + -0x28),
                 *(int *)(unaff_retaddr + -0x24),*(int *)(unaff_retaddr + -0x20),
                 *(uchar **)(unaff_retaddr + -0x1c),*(int *)(unaff_retaddr + -0x18),
                 *(int *)(unaff_retaddr + -0x14),*(int *)(unaff_retaddr + -0x10));
      return '\x01';
    }
    iVar16 = *(int *)(unaff_retaddr + 0x24);
    iVar10 = *(int *)(iVar16 + 0xd0);
    iVar11 = *(int *)(*(int *)(iVar16 + 0xcc) + 0x50);
    iVar17 = *(int *)(iVar10 + 0x50);
    if (iVar11 < iVar17) {
      iVar17 = iVar11;
    }
    uVar9 = *(undefined4 *)(iVar16 + 0xc0);
    *(int *)(unaff_retaddr + -0x10) = iVar17 + -1;
    *(undefined4 *)(unaff_retaddr + -0x14) = *(undefined4 *)(iVar10 + 0x5c);
    uVar3 = *(undefined4 *)(iVar10 + 0x40);
    uVar4 = *(undefined4 *)(iVar10 + 0x3c);
    *(undefined4 *)(unaff_retaddr + -0x18) = 0;
    *(undefined4 *)(unaff_retaddr + -0x1c) = 0;
    *(undefined4 *)(unaff_retaddr + -0x20) = uVar3;
    *(undefined4 *)(unaff_retaddr + -0x24) = uVar4;
    *(undefined4 *)(unaff_retaddr + -0x28) = uVar9;
    *(undefined4 *)(unaff_retaddr + -0x2c) = 0x4b951b;
    _ASMSet_Surface_Info();
    if (*(int *)(unaff_retaddr + 0x38) != 0) {
      *(int *)(unaff_retaddr + -0x10) = *(int *)(unaff_retaddr + 0x38);
      *(undefined4 *)(unaff_retaddr + -0x14) = 0x4b952c;
      _ASMSet_Xlate_Table();
    }
    pSVar2 = param_1->FShape;
    *(long *)(unaff_retaddr + -0x10) = fog_next_shape;
    pSVar18 = pSVar2 + iVar15;
    uVar9 = *(undefined4 *)pSVar18->Version;
    *(long *)(unaff_retaddr + -0x14) = pSVar18->Num_Shapes;
    uVar3 = *(undefined4 *)(pSVar18->Comment + 0xc);
    iVar15 = *(int *)(pSVar18->Comment + 0x10);
    *(undefined4 *)(unaff_retaddr + -0x18) = uVar9;
    uVar9 = *(undefined4 *)(pSVar18->Comment + 8);
    *(undefined4 *)(unaff_retaddr + -0x1c) = uVar3;
    *(undefined4 *)(unaff_retaddr + -0x20) = uVar9;
    *(int *)(unaff_retaddr + -0x24) =
         *(int *)(unaff_retaddr + 0x2c) - *(int *)(pSVar18->Comment + 0x14);
    *(int *)(unaff_retaddr + -0x28) = *(int *)(unaff_retaddr + 0x28) - iVar15;
    *(SLhape_File_Header **)(unaff_retaddr + -0x2c) = pSVar2;
    *(undefined4 *)(unaff_retaddr + -0x30) = 0x4b956a;
    _ASMDraw_Sprite();
    ASM_Fast_Count = ASM_Fast_Count + 1;
    return '\x01';
  }
  iVar15 = *(int *)(unaff_retaddr + 0x24);
  *(undefined4 *)(unaff_retaddr + 0x10) = *(undefined4 *)(iVar15 + 0x28);
  *(undefined4 *)(unaff_retaddr + 0x14) = *(undefined4 *)(iVar15 + 0x2c);
  *(undefined4 *)(unaff_retaddr + 0x18) = *(undefined4 *)(iVar15 + 0x30);
  puVar5 = param_1->shape;
  *(undefined4 *)(unaff_retaddr + 0x1c) = *(undefined4 *)(iVar15 + 0x34);
  if (puVar5 == (uchar *)0x0) {
    return '\0';
  }
  iVar10 = *(int *)(unaff_retaddr + 0x28);
  pSVar12 = (Shape_Header *)(puVar5 + param_1->offsets[iVar16].shape);
  param_1->shape_header = pSVar12;
  iVar11 = pSVar12->ymin;
  iVar16 = pSVar12->ymax;
  iVar17 = pSVar12->xmax + *(int *)(unaff_retaddr + 0x28);
  iVar10 = pSVar12->xmin + iVar10;
  *(int *)(unaff_retaddr + 0x24) = iVar10;
  iVar16 = iVar16 + *(int *)(unaff_retaddr + 0x2c);
  iVar11 = iVar11 + *(int *)(unaff_retaddr + 0x2c);
  *(int *)(unaff_retaddr + 8) = iVar16;
  *(int *)(unaff_retaddr + 0x2c) = iVar11;
  *(int *)(unaff_retaddr + 0xc) = iVar17;
  *(int *)(unaff_retaddr + 0x28) = iVar17;
  if (iVar10 < *(int *)(unaff_retaddr + 0x10)) {
    *(int *)(unaff_retaddr + 0x24) = *(int *)(unaff_retaddr + 0x10);
  }
  if (iVar11 < *(int *)(unaff_retaddr + 0x14)) {
    *(int *)(unaff_retaddr + 0x2c) = *(int *)(unaff_retaddr + 0x14);
  }
  if (*(int *)(unaff_retaddr + 0x18) < iVar17) {
    *(int *)(unaff_retaddr + 0x28) = *(int *)(unaff_retaddr + 0x18);
  }
  if (*(int *)(unaff_retaddr + 0x1c) < *(int *)(unaff_retaddr + 8)) {
    iVar16 = *(int *)(unaff_retaddr + 0x1c);
  }
  if (*(int *)(unaff_retaddr + 0x24) < 0) {
    *(undefined4 *)(unaff_retaddr + 0x24) = 0;
  }
  if (*(int *)(unaff_retaddr + 0x2c) < 0) {
    *(undefined4 *)(unaff_retaddr + 0x2c) = 0;
  }
  iVar17 = *(int *)(unaff_retaddr + 0x28);
  if (*(int *)(iVar15 + 0x18) <= iVar17) {
    iVar17 = *(int *)(iVar15 + 0x18) + -1;
    *(int *)(unaff_retaddr + 0x28) = iVar17;
  }
  if (*(int *)(iVar15 + 0x1c) <= iVar16) {
    iVar16 = *(int *)(iVar15 + 0x1c) + -1;
  }
  if (iVar17 < *(int *)(unaff_retaddr + 0x24)) {
    return '\0';
  }
  iVar17 = *(int *)(unaff_retaddr + 0x2c);
  if (iVar16 < iVar17) {
    return '\0';
  }
  if ((*(int *)(unaff_retaddr + 0x24) == iVar10) && (iVar17 == iVar11)) {
    if ((*(int *)(unaff_retaddr + 0x28) == *(int *)(unaff_retaddr + 0xc)) &&
       (iVar16 == *(int *)(unaff_retaddr + 8))) {
      uVar13 = *(uint *)(unaff_retaddr + 0x34) & 0xff;
      if (uVar13 == 0) {
        *(undefined4 *)(unaff_retaddr + -0x10) = *(undefined4 *)(unaff_retaddr + 0x30);
        *(int *)(unaff_retaddr + -0x14) = iVar11;
        *(int *)(unaff_retaddr + -0x18) = iVar10;
        *(int *)(unaff_retaddr + -0x1c) = iVar15;
        *(undefined4 *)(unaff_retaddr + -0x20) = 0x4b9731;
        uVar8 = TShape::shape_draw_unclipped
                          (param_1,*(TDrawArea **)(unaff_retaddr + -0x1c),
                           *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                           *(long *)(unaff_retaddr + -0x10));
        return uVar8;
      }
      if (uVar13 == 1) {
        if (*(int *)(unaff_retaddr + 0x38) == 0) {
          *(undefined4 *)(unaff_retaddr + -0x10) = *(undefined4 *)(unaff_retaddr + 0x30);
          *(int *)(unaff_retaddr + -0x14) = iVar11;
          *(int *)(unaff_retaddr + -0x18) = iVar10;
          *(int *)(unaff_retaddr + -0x1c) = iVar15;
          *(undefined4 *)(unaff_retaddr + -0x20) = 0x4b96fe;
          uVar8 = TShape::shape_draw_unclipped
                            (param_1,*(TDrawArea **)(unaff_retaddr + -0x1c),
                             *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                             *(long *)(unaff_retaddr + -0x10));
          return uVar8;
        }
        *(int *)(unaff_retaddr + -0x10) = *(int *)(unaff_retaddr + 0x38);
        *(undefined4 *)(unaff_retaddr + -0x14) = *(undefined4 *)(unaff_retaddr + 0x30);
        *(int *)(unaff_retaddr + -0x18) = iVar11;
        *(int *)(unaff_retaddr + -0x1c) = iVar10;
        *(int *)(unaff_retaddr + -0x20) = iVar15;
        *(undefined4 *)(unaff_retaddr + -0x24) = 0x4b9718;
        uVar8 = TShape::shape_color_trans_unclipped
                          (param_1,*(TDrawArea **)(unaff_retaddr + -0x20),
                           *(long *)(unaff_retaddr + -0x1c),*(long *)(unaff_retaddr + -0x18),
                           *(long *)(unaff_retaddr + -0x14),*(uchar **)(unaff_retaddr + -0x10));
        return uVar8;
      }
      if (uVar13 == 2) {
        if (*(int *)(unaff_retaddr + 0x38) == 0) {
          *(undefined4 *)(unaff_retaddr + -0x10) = *(undefined4 *)(unaff_retaddr + 0x30);
          *(int *)(unaff_retaddr + -0x14) = iVar11;
          *(int *)(unaff_retaddr + -0x18) = iVar10;
          *(int *)(unaff_retaddr + -0x1c) = iVar15;
          *(undefined4 *)(unaff_retaddr + -0x20) = 0x4b96c8;
          uVar8 = TShape::shape_draw_unclipped
                            (param_1,*(TDrawArea **)(unaff_retaddr + -0x1c),
                             *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                             *(long *)(unaff_retaddr + -0x10));
          return uVar8;
        }
        *(int *)(unaff_retaddr + -0x10) = *(int *)(unaff_retaddr + 0x38);
        *(int *)(unaff_retaddr + -0x14) = iVar11;
        *(int *)(unaff_retaddr + -0x18) = iVar10;
        *(int *)(unaff_retaddr + -0x1c) = iVar15;
        *(undefined4 *)(unaff_retaddr + -0x20) = 0x4b96dd;
        uVar8 = TShape::shape_shadow_unclipped
                          (param_1,*(TDrawArea **)(unaff_retaddr + -0x1c),
                           *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                           *(uchar **)(unaff_retaddr + -0x10));
        return uVar8;
      }
      goto LAB_004b97cb;
    }
    iVar17 = *(int *)(unaff_retaddr + 0x2c);
  }
  uVar13 = *(uint *)(unaff_retaddr + 0x34) & 0xff;
  if (uVar13 != 0) {
    if (uVar13 == 1) {
      if (*(int *)(unaff_retaddr + 0x38) != 0) {
        *(int *)(unaff_retaddr + -0x10) = *(int *)(unaff_retaddr + 0x38);
        *(int *)(unaff_retaddr + -0x14) = iVar16;
        *(undefined4 *)(unaff_retaddr + -0x18) = *(undefined4 *)(unaff_retaddr + 0x28);
        *(int *)(unaff_retaddr + -0x1c) = iVar17;
        *(undefined4 *)(unaff_retaddr + -0x20) = *(undefined4 *)(unaff_retaddr + 0x24);
        *(undefined4 *)(unaff_retaddr + -0x24) = *(undefined4 *)(unaff_retaddr + 0x30);
        *(int *)(unaff_retaddr + -0x28) = iVar11;
        *(int *)(unaff_retaddr + -0x2c) = iVar10;
        *(int *)(unaff_retaddr + -0x30) = iVar15;
        *(undefined4 *)(unaff_retaddr + -0x34) = 0x4b97a1;
        uVar8 = TShape::shape_color_trans_clipped
                          (param_1,*(TDrawArea **)(unaff_retaddr + -0x30),
                           *(long *)(unaff_retaddr + -0x2c),*(long *)(unaff_retaddr + -0x28),
                           *(long *)(unaff_retaddr + -0x24),*(long *)(unaff_retaddr + -0x20),
                           *(long *)(unaff_retaddr + -0x1c),*(long *)(unaff_retaddr + -0x18),
                           *(long *)(unaff_retaddr + -0x14),*(uchar **)(unaff_retaddr + -0x10));
        return uVar8;
      }
    }
    else {
      if (uVar13 != 2) {
LAB_004b97cb:
        return *(uchar *)(unaff_retaddr + 7);
      }
      if (*(int *)(unaff_retaddr + 0x38) != 0) {
        *(int *)(unaff_retaddr + -0x10) = *(int *)(unaff_retaddr + 0x38);
        *(int *)(unaff_retaddr + -0x14) = iVar16;
        *(undefined4 *)(unaff_retaddr + -0x18) = *(undefined4 *)(unaff_retaddr + 0x28);
        *(int *)(unaff_retaddr + -0x1c) = iVar17;
        *(undefined4 *)(unaff_retaddr + -0x20) = *(undefined4 *)(unaff_retaddr + 0x24);
        *(int *)(unaff_retaddr + -0x24) = iVar11;
        *(int *)(unaff_retaddr + -0x28) = iVar10;
        *(int *)(unaff_retaddr + -0x2c) = iVar15;
        *(undefined4 *)(unaff_retaddr + -0x30) = 0x4b9773;
        uVar8 = TShape::shape_shadow_clipped
                          (param_1,*(TDrawArea **)(unaff_retaddr + -0x2c),
                           *(long *)(unaff_retaddr + -0x28),*(long *)(unaff_retaddr + -0x24),
                           *(long *)(unaff_retaddr + -0x20),*(long *)(unaff_retaddr + -0x1c),
                           *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                           *(uchar **)(unaff_retaddr + -0x10));
        return uVar8;
      }
    }
  }
  *(int *)(unaff_retaddr + -0x10) = iVar16;
  *(undefined4 *)(unaff_retaddr + -0x14) = *(undefined4 *)(unaff_retaddr + 0x28);
  *(int *)(unaff_retaddr + -0x18) = iVar17;
  *(undefined4 *)(unaff_retaddr + -0x1c) = *(undefined4 *)(unaff_retaddr + 0x24);
  *(int *)(unaff_retaddr + -0x20) = iVar11;
  *(int *)(unaff_retaddr + -0x24) = iVar10;
  *(int *)(unaff_retaddr + -0x28) = iVar15;
  *(undefined4 *)(unaff_retaddr + -0x2c) = 0x4b97c1;
  uVar8 = TShape::shape_draw_clipped
                    (param_1,*(TDrawArea **)(unaff_retaddr + -0x28),*(long *)(unaff_retaddr + -0x24)
                     ,*(long *)(unaff_retaddr + -0x20),*(long *)(unaff_retaddr + -0x1c),
                     *(long *)(unaff_retaddr + -0x18),*(long *)(unaff_retaddr + -0x14),
                     *(long *)(unaff_retaddr + -0x10));
  return uVar8;
}

// --------------------------------------------------

// Function: FUN_004b97e5
// Address: 004b97e5
// XREFS: None
undefined4 __thiscall FUN_004b97e5(int param_1,TDrawArea *param_2,int param_3,int param_4)
{
  byte bVar1;
  int iVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uchar *puVar8;
  uchar *puVar9;
  byte *pbVar10;
  byte *pbVar11;
  
  iVar5 = *(int *)(param_1 + 0xc);
  iVar2 = param_2->Orien;
  iVar7 = (*(int *)(iVar5 + 0x14) - *(int *)(iVar5 + 0xc)) + 1;
  pbVar11 = (byte *)(iVar5 + 0x18);
  lVar4 = TDrawArea::AlignedWidth(param_2);
  iVar5 = lVar4 * iVar2;
  if (iVar2 < 1) {
    param_4 = (param_4 - param_2->Height) + 1;
  }
  puVar8 = param_2->Bits + param_3 + param_4 * iVar5;
  param_2 = (TDrawArea *)iVar7;
  if (0 < iVar7) {
    do {
      bVar3 = false;
      puVar9 = puVar8;
      pbVar10 = pbVar11;
      do {
        bVar1 = *pbVar10;
        pbVar11 = pbVar10 + 1;
        if ((bVar1 & 1) == 1) {
          if (bVar1 >> 1 == 0) {
            uVar6 = (uint)*pbVar11;
LAB_004b98b0:
            puVar9 = puVar9 + uVar6;
            pbVar11 = pbVar10 + 2;
          }
          else {
            uVar6 = (uint)(bVar1 >> 1);
            memcpy(puVar9,pbVar11,uVar6);
            puVar9 = puVar9 + uVar6;
            pbVar11 = pbVar11 + uVar6;
          }
        }
        else {
          if (bVar1 >> 1 != 0) {
            uVar6 = (uint)(bVar1 >> 1);
            memset(puVar9,*pbVar11,uVar6);
            goto LAB_004b98b0;
          }
          bVar3 = true;
        }
        pbVar10 = pbVar11;
      } while (!bVar3);
      puVar8 = puVar8 + iVar5;
      param_2 = (TDrawArea *)((int)param_2 + -1);
    } while (param_2 != (TDrawArea *)0x0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004b98d8
// Address: 004b98d8
// XREFS: None
undefined4 __thiscall
FUN_004b98d8(int param_1,TDrawArea *param_2,int param_3,int param_4,undefined4 param_5,int param_6)
{
  byte bVar1;
  int iVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  uchar *puVar6;
  uint uVar7;
  uchar *puVar8;
  uchar *puVar9;
  byte *pbVar10;
  byte *pbVar11;
  int iStack_8;
  
  iVar5 = *(int *)(param_1 + 0xc);
  iVar2 = param_2->Orien;
  iStack_8 = (*(int *)(iVar5 + 0x14) - *(int *)(iVar5 + 0xc)) + 1;
  pbVar10 = (byte *)(iVar5 + 0x18);
  lVar4 = TDrawArea::AlignedWidth(param_2);
  iVar5 = lVar4 * iVar2;
  if (iVar2 < 1) {
    param_4 = (param_4 - param_2->Height) + 1;
  }
  puVar8 = param_2->Bits + param_3 + param_4 * iVar5;
  if (0 < iStack_8) {
    do {
      bVar3 = false;
      puVar9 = puVar8;
      pbVar11 = pbVar10;
      do {
        bVar1 = *pbVar11;
        pbVar10 = pbVar11 + 1;
        if ((bVar1 & 1) == 1) {
          if (bVar1 >> 1 == 0) {
            uVar7 = (uint)*pbVar10;
LAB_004b99ba:
            puVar9 = puVar9 + uVar7;
            pbVar10 = pbVar11 + 2;
          }
          else {
            puVar6 = puVar9 + (bVar1 >> 1);
            for (; puVar9 < puVar6; puVar9 = puVar9 + 1) {
              bVar1 = *pbVar10;
              pbVar10 = pbVar10 + 1;
              *puVar9 = *(uchar *)((uint)bVar1 + param_6);
            }
          }
        }
        else {
          if (bVar1 >> 1 != 0) {
            uVar7 = (uint)(bVar1 >> 1);
            memset(puVar9,*(undefined1 *)((uint)*pbVar10 + param_6),uVar7);
            goto LAB_004b99ba;
          }
          bVar3 = true;
        }
        pbVar11 = pbVar10;
      } while (!bVar3);
      puVar8 = puVar8 + iVar5;
      iStack_8 = iStack_8 + -1;
    } while (iStack_8 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004b99ec
// Address: 004b99ec
// XREFS: None
undefined4 __thiscall
FUN_004b99ec(int param_1,TDrawArea *param_2,int param_3,uint param_4,int param_5)
{
  byte bVar1;
  int iVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  
  iVar2 = *(int *)(param_1 + 0xc);
  pbVar9 = (byte *)(iVar2 + 0x18);
  iVar10 = (*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc)) + 1;
  iVar2 = param_2->Orien;
  lVar4 = TDrawArea::AlignedWidth(param_2);
  iVar5 = lVar4 * iVar2;
  if (iVar2 < 1) {
    param_4 = (param_4 - param_2->Height) + 1;
  }
  pbVar6 = param_2->Bits + param_3 + param_4 * iVar5;
  param_2 = (TDrawArea *)iVar10;
  if (0 < iVar10) {
    do {
      bVar3 = false;
      pbVar7 = pbVar6;
      pbVar8 = pbVar9;
      do {
        bVar1 = *pbVar8;
        pbVar9 = pbVar8 + 1;
        if ((bVar1 & 1) == 1) {
          param_4 = (uint)(bVar1 >> 1);
          if (bVar1 >> 1 == 0) {
            pbVar7 = pbVar7 + *pbVar9;
LAB_004b9ac2:
            pbVar9 = pbVar8 + 2;
          }
          else {
            pbVar8 = pbVar7 + param_4;
            for (; pbVar7 < pbVar8; pbVar7 = pbVar7 + 1) {
              *pbVar7 = *(byte *)((uint)*pbVar7 + param_5);
            }
            pbVar9 = pbVar9 + param_4;
          }
        }
        else {
          param_4 = (uint)(bVar1 >> 1);
          if (bVar1 >> 1 != 0) {
            pbVar9 = pbVar7 + param_4;
            for (; pbVar7 < pbVar9; pbVar7 = pbVar7 + 1) {
              *pbVar7 = *(byte *)((uint)*pbVar7 + param_5);
            }
            goto LAB_004b9ac2;
          }
          bVar3 = true;
        }
        pbVar8 = pbVar9;
      } while (!bVar3);
      pbVar6 = pbVar6 + iVar5;
      param_2 = (TDrawArea *)((int)param_2 + -1);
    } while (param_2 != (TDrawArea *)0x0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004b9aee
// Address: 004b9aee
// XREFS: None
undefined4 __thiscall
FUN_004b9aee(int param_1,TDrawArea *param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8)
{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  char cVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uchar *puVar10;
  uchar *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  uint uVar14;
  
  iVar9 = param_2->Orien;
  lVar5 = TDrawArea::AlignedWidth(param_2);
  iVar6 = lVar5 * iVar9;
  pbVar12 = (byte *)(*(int *)(param_1 + 0xc) + 0x18);
  if (iVar9 < 1) {
    puVar10 = param_2->Bits + ((param_6 - param_2->Height) + 1) * iVar6;
  }
  else {
    puVar10 = param_2->Bits + iVar6 * param_6;
  }
  puVar10 = puVar10 + param_5;
  if (param_4 < param_6) {
    param_6 = param_6 - param_4;
    param_4 = param_4 + param_6;
    do {
      bVar2 = false;
      pbVar13 = pbVar12;
      do {
        bVar1 = *pbVar13;
        pbVar12 = pbVar13 + 1;
        if ((bVar1 & 1) == 1) {
          if (bVar1 >> 1 == 0) {
LAB_004b9b90:
            pbVar12 = pbVar13 + 2;
          }
          else {
            pbVar12 = pbVar12 + (bVar1 >> 1);
          }
        }
        else {
          if ((bVar1 & 0xfe) != 0) goto LAB_004b9b90;
          bVar2 = true;
        }
        pbVar13 = pbVar12;
      } while (!bVar2);
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  if (param_4 <= param_8) {
    param_8 = (param_8 - param_4) + 1;
    do {
      iVar9 = param_3;
      puVar11 = puVar10;
      if (param_3 < param_5) {
        param_6._0_1_ = '\0';
        pbVar13 = pbVar12;
        do {
          bVar1 = *pbVar13;
          pbVar12 = pbVar13 + 1;
          if ((bVar1 & 1) == 1) {
            if (bVar1 >> 1 == 0) {
              iVar9 = iVar9 + (uint)*pbVar12;
              pbVar12 = pbVar13 + 2;
              if (param_5 <= iVar9) {
                if (param_7 < iVar9) {
                  param_6._0_1_ = '\x02';
                }
                else {
                  param_6._0_1_ = '\x01';
                  puVar11 = puVar11 + (iVar9 - param_5);
                }
              }
            }
            else {
              uVar3 = (uint)(bVar1 >> 1);
              iVar9 = iVar9 + uVar3;
              if (param_5 <= iVar9) {
                if (param_7 < iVar9) {
                  param_6._0_1_ = '\x02';
                  iVar7 = (param_7 - param_5) + 1;
                  iVar8 = param_5 - iVar9;
                }
                else {
                  param_6._0_1_ = '\x01';
                  iVar7 = iVar9 - param_5;
                  iVar8 = -iVar7;
                }
                memcpy(puVar11,pbVar12 + uVar3 + iVar8,iVar7);
                puVar11 = puVar11 + iVar7;
              }
              pbVar12 = pbVar12 + uVar3;
            }
          }
          else if (bVar1 >> 1 == 0) {
            param_6._0_1_ = '\x03';
          }
          else {
            iVar9 = iVar9 + (uint)(bVar1 >> 1);
            if (param_5 <= iVar9) {
              if (param_7 < iVar9) {
                param_6._0_1_ = '\x02';
                iVar8 = (param_7 - param_5) + 1;
                bVar1 = *pbVar12;
              }
              else {
                param_6._0_1_ = '\x01';
                iVar8 = iVar9 - param_5;
                bVar1 = *pbVar12;
              }
              memset(puVar11,bVar1,iVar8);
              puVar11 = puVar11 + iVar8;
            }
            pbVar12 = pbVar13 + 2;
          }
          pbVar13 = pbVar12;
        } while ((byte)param_6 == '\0');
      }
      else {
        param_6._0_1_ = '\x01';
      }
      param_6._0_1_ = (byte)param_6 - 1;
      while ((byte)param_6 == 0) {
        bVar1 = *pbVar12;
        pbVar13 = pbVar12 + 1;
        if ((bVar1 & 1) == 1) {
          if (bVar1 >> 1 == 0) {
            iVar9 = iVar9 + (uint)*pbVar13;
            puVar11 = puVar11 + *pbVar13;
            pbVar12 = pbVar12 + 2;
            if (param_7 < iVar9) {
              param_6._0_1_ = bVar1 & 1;
            }
          }
          else {
            uVar3 = (uint)(bVar1 >> 1);
            iVar9 = iVar9 + uVar3;
            if (param_7 < iVar9) {
              param_6._0_1_ = 1;
              memcpy(puVar11,pbVar13,(param_7 - iVar9) + 1 + uVar3);
              puVar11 = puVar11 + uVar3;
              pbVar12 = pbVar13 + uVar3;
            }
            else {
              memcpy(puVar11,pbVar13,uVar3);
              puVar11 = puVar11 + uVar3;
              pbVar12 = pbVar13 + uVar3;
            }
          }
        }
        else if (bVar1 >> 1 == 0) {
          param_6._0_1_ = 3;
          pbVar12 = pbVar13;
        }
        else {
          uVar3 = (uint)(bVar1 >> 1);
          iVar9 = iVar9 + uVar3;
          if (param_7 < iVar9) {
            bVar1 = *pbVar13;
            param_6._0_1_ = 1;
            uVar14 = (param_7 - iVar9) + 1 + uVar3;
          }
          else {
            bVar1 = *pbVar13;
            uVar14 = uVar3;
          }
          memset(puVar11,bVar1,uVar14);
          puVar11 = puVar11 + uVar3;
          pbVar12 = pbVar12 + 2;
        }
      }
      cVar4 = (byte)param_6 - 1;
      while (cVar4 == '\0') {
        bVar1 = *pbVar12;
        if ((bVar1 & 1) == 1) {
          if (bVar1 >> 1 == 0) {
LAB_004b9deb:
            pbVar12 = pbVar12 + 2;
          }
          else {
            pbVar12 = pbVar12 + 1 + (bVar1 >> 1);
          }
        }
        else {
          if ((bVar1 & 0xfe) != 0) goto LAB_004b9deb;
          cVar4 = '\x02';
          pbVar12 = pbVar12 + 1;
        }
      }
      puVar10 = puVar10 + iVar6;
      param_8 = param_8 + -1;
    } while (param_8 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004b9e1d
// Address: 004b9e1d
// XREFS: None
undefined4 __thiscall
FUN_004b9e1d(int param_1,TDrawArea *param_2,int param_3,int param_4,undefined4 param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10)
{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  char cVar4;
  long lVar5;
  uchar *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uchar *puVar11;
  uchar *puVar12;
  byte *pbVar13;
  byte *pbVar14;
  uint uVar15;
  
  iVar10 = param_2->Orien;
  lVar5 = TDrawArea::AlignedWidth(param_2);
  iVar7 = lVar5 * iVar10;
  pbVar13 = (byte *)(*(int *)(param_1 + 0xc) + 0x18);
  if (iVar10 < 1) {
    puVar11 = param_2->Bits + ((param_7 - param_2->Height) + 1) * iVar7;
  }
  else {
    puVar11 = param_2->Bits + iVar7 * param_7;
  }
  puVar11 = puVar11 + param_6;
  if (param_4 < param_7) {
    param_7 = param_7 - param_4;
    param_4 = param_4 + param_7;
    do {
      bVar2 = false;
      pbVar14 = pbVar13;
      do {
        bVar1 = *pbVar14;
        pbVar13 = pbVar14 + 1;
        if ((bVar1 & 1) == 1) {
          if (bVar1 >> 1 == 0) {
LAB_004b9ec0:
            pbVar13 = pbVar14 + 2;
          }
          else {
            pbVar13 = pbVar13 + (bVar1 >> 1);
          }
        }
        else {
          if ((bVar1 & 0xfe) != 0) goto LAB_004b9ec0;
          bVar2 = true;
        }
        pbVar14 = pbVar13;
      } while (!bVar2);
      param_7 = param_7 + -1;
    } while (param_7 != 0);
  }
  if (param_4 <= param_9) {
    param_9 = (param_9 - param_4) + 1;
    do {
      iVar10 = param_3;
      puVar12 = puVar11;
      if (param_3 < param_6) {
        param_7._0_1_ = '\0';
        pbVar14 = pbVar13;
        do {
          bVar1 = *pbVar14;
          pbVar13 = pbVar14 + 1;
          if ((bVar1 & 1) == 1) {
            if (bVar1 >> 1 == 0) {
              iVar10 = iVar10 + (uint)*pbVar13;
              pbVar13 = pbVar14 + 2;
              if (param_6 <= iVar10) {
                if (param_8 < iVar10) {
                  param_7._0_1_ = '\x02';
                }
                else {
                  param_7._0_1_ = '\x01';
                  puVar12 = puVar12 + (iVar10 - param_6);
                }
              }
            }
            else {
              uVar3 = (uint)(bVar1 >> 1);
              iVar10 = iVar10 + uVar3;
              if (iVar10 < param_6) {
                pbVar13 = pbVar13 + uVar3;
              }
              else if (param_8 < iVar10) {
                iVar8 = (param_6 - iVar10) + uVar3;
                iVar9 = (param_8 - param_6) + 1;
                pbVar13 = pbVar13 + iVar8;
                param_7._0_1_ = '\x02';
                puVar6 = puVar12 + iVar9;
                for (; puVar12 < puVar6; puVar12 = puVar12 + 1) {
                  bVar1 = *pbVar13;
                  pbVar13 = pbVar13 + 1;
                  *puVar12 = *(uchar *)((uint)bVar1 + param_10);
                }
                pbVar13 = pbVar13 + ((uVar3 - iVar9) - iVar8);
              }
              else {
                param_7._0_1_ = '\x01';
                puVar6 = puVar12 + (iVar10 - param_6);
                pbVar13 = pbVar13 + (uVar3 - (iVar10 - param_6));
                for (; puVar12 < puVar6; puVar12 = puVar12 + 1) {
                  bVar1 = *pbVar13;
                  pbVar13 = pbVar13 + 1;
                  *puVar12 = *(uchar *)((uint)bVar1 + param_10);
                }
              }
            }
          }
          else if (bVar1 >> 1 == 0) {
            param_7._0_1_ = '\x03';
          }
          else {
            iVar10 = iVar10 + (uint)(bVar1 >> 1);
            if (param_6 <= iVar10) {
              if (param_8 < iVar10) {
                param_7._0_1_ = '\x02';
                iVar8 = (param_8 - param_6) + 1;
              }
              else {
                param_7._0_1_ = '\x01';
                iVar8 = iVar10 - param_6;
              }
              memset(puVar12,*(undefined1 *)((uint)*pbVar13 + param_10),iVar8);
              puVar12 = puVar12 + iVar8;
            }
            pbVar13 = pbVar14 + 2;
          }
          pbVar14 = pbVar13;
        } while ((byte)param_7 == '\0');
      }
      else {
        param_7._0_1_ = '\x01';
      }
      param_7._0_1_ = (byte)param_7 - 1;
      while ((byte)param_7 == 0) {
        bVar1 = *pbVar13;
        pbVar14 = pbVar13 + 1;
        if ((bVar1 & 1) == 1) {
          if (bVar1 >> 1 == 0) {
            iVar10 = iVar10 + (uint)*pbVar14;
            puVar12 = puVar12 + *pbVar14;
            pbVar13 = pbVar13 + 2;
            if (param_8 < iVar10) {
              param_7._0_1_ = bVar1 & 1;
            }
          }
          else {
            uVar3 = (uint)(bVar1 >> 1);
            iVar10 = iVar10 + uVar3;
            if (param_8 < iVar10) {
              param_7._0_1_ = 1;
              iVar8 = (param_8 - iVar10) + 1 + uVar3;
              puVar6 = puVar12 + iVar8;
              for (; puVar12 < puVar6; puVar12 = puVar12 + 1) {
                bVar1 = *pbVar14;
                pbVar14 = pbVar14 + 1;
                *puVar12 = *(uchar *)((uint)bVar1 + param_10);
              }
              pbVar13 = pbVar14 + (uVar3 - iVar8);
            }
            else {
              puVar6 = puVar12 + uVar3;
              for (; pbVar13 = pbVar14, puVar12 < puVar6; puVar12 = puVar12 + 1) {
                bVar1 = *pbVar14;
                pbVar14 = pbVar14 + 1;
                *puVar12 = *(uchar *)((uint)bVar1 + param_10);
              }
            }
          }
        }
        else if (bVar1 >> 1 == 0) {
          param_7._0_1_ = 3;
          pbVar13 = pbVar14;
        }
        else {
          uVar3 = (uint)(bVar1 >> 1);
          iVar10 = iVar10 + uVar3;
          uVar15 = uVar3;
          if (param_8 < iVar10) {
            param_7._0_1_ = 1;
            uVar15 = (param_8 - iVar10) + 1 + uVar3;
          }
          memset(puVar12,*(undefined1 *)((uint)*pbVar14 + param_10),uVar15);
          puVar12 = puVar12 + uVar3;
          pbVar13 = pbVar13 + 2;
        }
      }
      cVar4 = (byte)param_7 - 1;
      while (cVar4 == '\0') {
        bVar1 = *pbVar13;
        if ((bVar1 & 1) == 1) {
          if (bVar1 >> 1 == 0) {
LAB_004ba183:
            pbVar13 = pbVar13 + 2;
          }
          else {
            pbVar13 = pbVar13 + 1 + (bVar1 >> 1);
          }
        }
        else {
          if ((bVar1 & 0xfe) != 0) goto LAB_004ba183;
          cVar4 = '\x02';
          pbVar13 = pbVar13 + 1;
        }
      }
      puVar11 = puVar11 + iVar7;
      param_9 = param_9 + -1;
    } while (param_9 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004ba1b5
// Address: 004ba1b5
// XREFS: None
undefined4 __thiscall
FUN_004ba1b5(int param_1,TDrawArea *param_2,int param_3,int param_4,int param_5,uint param_6,
            int param_7,int param_8,int param_9)
{
  byte bVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  long lVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  
  iVar6 = param_2->Orien;
  lVar5 = TDrawArea::AlignedWidth(param_2);
  iVar9 = lVar5 * iVar6;
  pbVar10 = (byte *)(*(int *)(param_1 + 0xc) + 0x18);
  iVar2 = param_6;
  if (iVar6 < 1) {
    iVar2 = (param_6 - param_2->Height) + 1;
  }
  pbVar7 = param_2->Bits + param_5 + iVar2 * iVar9;
  param_2 = (TDrawArea *)pbVar10;
  if (param_4 < (int)param_6) {
    iVar6 = param_6 - param_4;
    param_4 = param_4 + iVar6;
    do {
      bVar3 = false;
      do {
        bVar1 = *(byte *)param_2;
        if ((bVar1 & 1) == 1) {
          param_6 = (uint)(bVar1 >> 1);
          if (bVar1 >> 1 == 0) {
LAB_004ba267:
            param_2 = (TDrawArea *)((int)param_2 + 2);
          }
          else {
            param_2 = (TDrawArea *)((byte *)((int)param_2 + 1) + param_6);
          }
        }
        else {
          if ((bVar1 & 0xfe) != 0) goto LAB_004ba267;
          bVar3 = true;
          param_2 = (TDrawArea *)((int)param_2 + 1);
        }
      } while (!bVar3);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if (param_4 <= param_8) {
    param_4 = (param_8 - param_4) + 1;
    pbVar10 = (byte *)param_2;
    do {
      pbVar8 = pbVar7;
      iVar6 = param_3;
      if (param_3 < param_5) {
        cVar4 = '\0';
        do {
          bVar1 = *pbVar10;
          pbVar10 = (byte *)((int)param_2 + 1);
          if ((bVar1 & 1) == 1) {
            param_6 = (uint)(bVar1 >> 1);
            if (bVar1 >> 1 == 0) {
              iVar6 = iVar6 + (uint)*pbVar10;
              param_2 = (TDrawArea *)((int)param_2 + 2);
              if (param_5 <= iVar6) {
                if (param_7 < iVar6) {
                  cVar4 = '\x02';
                }
                else {
                  cVar4 = '\x01';
                  pbVar8 = pbVar8 + (iVar6 - param_5);
                }
              }
            }
            else {
              iVar6 = iVar6 + param_6;
              if (param_5 <= iVar6) {
                if (param_7 < iVar6) {
                  cVar4 = '\x02';
                  pbVar11 = pbVar8 + (param_7 - param_5) + 1;
                  pbVar12 = pbVar8;
                  if (pbVar8 < pbVar11) {
                    do {
                      pbVar8 = pbVar12 + 1;
                      *pbVar12 = *(byte *)((uint)*pbVar12 + param_9);
                      pbVar12 = pbVar8;
                    } while (pbVar8 < pbVar11);
                    param_2 = (TDrawArea *)(pbVar10 + param_6);
                    goto LAB_004ba3c1;
                  }
                }
                else {
                  cVar4 = '\x01';
                  pbVar12 = pbVar8 + (iVar6 - param_5);
                  for (; pbVar8 < pbVar12; pbVar8 = pbVar8 + 1) {
                    *pbVar8 = *(byte *)((uint)*pbVar8 + param_9);
                  }
                }
              }
              param_2 = (TDrawArea *)(pbVar10 + param_6);
            }
          }
          else {
            param_6 = (uint)(bVar1 >> 1);
            if (bVar1 >> 1 == 0) {
              cVar4 = '\x03';
              param_2 = (TDrawArea *)pbVar10;
            }
            else {
              iVar6 = iVar6 + param_6;
              if (param_5 <= iVar6) {
                if (param_7 < iVar6) {
                  cVar4 = '\x02';
                  pbVar10 = pbVar8 + (param_7 - param_5) + 1;
                  for (; pbVar8 < pbVar10; pbVar8 = pbVar8 + 1) {
                    *pbVar8 = *(byte *)((uint)*pbVar8 + param_9);
                  }
                }
                else {
                  cVar4 = '\x01';
                  pbVar10 = pbVar8 + (iVar6 - param_5);
                  for (; pbVar8 < pbVar10; pbVar8 = pbVar8 + 1) {
                    *pbVar8 = *(byte *)((uint)*pbVar8 + param_9);
                  }
                }
              }
              param_2 = (TDrawArea *)((int)param_2 + 2);
            }
          }
LAB_004ba3c1:
          pbVar10 = (byte *)param_2;
        } while (cVar4 == '\0');
      }
      else {
        cVar4 = '\x01';
      }
      cVar4 = cVar4 + -1;
joined_r0x004ba3d3:
      if (cVar4 == '\0') {
        bVar1 = *pbVar10;
        pbVar10 = (byte *)((int)param_2 + 1);
        if ((bVar1 & 1) == 1) {
          param_6 = (uint)(bVar1 >> 1);
          if (bVar1 >> 1 == 0) {
            iVar6 = iVar6 + (uint)*pbVar10;
            pbVar8 = pbVar8 + *pbVar10;
            pbVar10 = (byte *)((int)param_2 + 2);
            param_2 = (TDrawArea *)pbVar10;
            if (param_7 < iVar6) {
              cVar4 = '\x01';
            }
            goto joined_r0x004ba3d3;
          }
          iVar6 = iVar6 + param_6;
          if (param_7 < iVar6) {
            cVar4 = '\x01';
            pbVar12 = pbVar8 + param_6 + (param_7 - iVar6) + 1;
            pbVar11 = pbVar8;
            if (pbVar8 < pbVar12) {
              do {
                pbVar8 = pbVar11 + 1;
                *pbVar11 = *(byte *)((uint)*pbVar11 + param_9);
                pbVar11 = pbVar8;
              } while (pbVar8 < pbVar12);
              pbVar10 = pbVar10 + param_6;
              param_2 = (TDrawArea *)pbVar10;
              goto joined_r0x004ba3d3;
            }
          }
          else {
            pbVar12 = pbVar8 + param_6;
            for (; pbVar8 < pbVar12; pbVar8 = pbVar8 + 1) {
              *pbVar8 = *(byte *)((uint)*pbVar8 + param_9);
            }
          }
          pbVar10 = pbVar10 + param_6;
          param_2 = (TDrawArea *)pbVar10;
          goto joined_r0x004ba3d3;
        }
        param_6 = (uint)(bVar1 >> 1);
        if (bVar1 >> 1 == 0) {
          cVar4 = '\x03';
          param_2 = (TDrawArea *)pbVar10;
        }
        else {
          iVar6 = iVar6 + param_6;
          if (param_7 < iVar6) {
            cVar4 = '\x01';
            pbVar10 = pbVar8 + param_6 + (param_7 - iVar6) + 1;
            for (; pbVar8 < pbVar10; pbVar8 = pbVar8 + 1) {
              *pbVar8 = *(byte *)((uint)*pbVar8 + param_9);
            }
          }
          else {
            pbVar10 = pbVar8 + param_6;
            for (; pbVar8 < pbVar10; pbVar8 = pbVar8 + 1) {
              *pbVar8 = *(byte *)((uint)*pbVar8 + param_9);
            }
          }
          pbVar10 = (byte *)((int)param_2 + 2);
          param_2 = (TDrawArea *)pbVar10;
        }
        goto joined_r0x004ba3d3;
      }
      cVar4 = cVar4 + -1;
      while (cVar4 == '\0') {
        bVar1 = *pbVar10;
        param_2 = (TDrawArea *)(pbVar10 + 1);
        if ((bVar1 & 1) == 1) {
          param_6 = (uint)(bVar1 >> 1);
          if (bVar1 >> 1 == 0) {
LAB_004ba518:
            param_2 = (TDrawArea *)(pbVar10 + 2);
            pbVar10 = (byte *)param_2;
          }
          else {
            param_2 = (TDrawArea *)((int)param_2 + param_6);
            pbVar10 = (byte *)param_2;
          }
        }
        else {
          if ((bVar1 & 0xfe) != 0) goto LAB_004ba518;
          cVar4 = '\x02';
          pbVar10 = (byte *)param_2;
        }
      }
      pbVar7 = pbVar7 + iVar9;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004ba54a
// Address: 004ba54a
// XREFS: None
// [HELPER] s_RGL_shape_draw: "RGL_shape_draw"
uchar __thiscall
FUN_004ba54a(TShape *param_1,TDrawArea *param_2,int param_3,int param_4,int param_5,char param_6,
            uchar *param_7)
{
  Shape_Header *pSVar1;
  TSpan_List_Manager *pTVar2;
  int iVar3;
  int iVar4;
  TDrawArea *pTVar5;
  uchar uVar6;
  int iVar7;
  SLhape_File_Header *pSVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  Shape_Info *pSVar12;
  int iVar13;
  int iVar14;
  long lVar15;
  int iStack_18;
  
  pTVar5 = param_2;
  if ((-1 < param_5) &&
     (uVar6 = TShape::Check_shape(param_1,param_5,s_RGL_shape_draw), uVar6 == '\0')) {
    if (param_1->FShape != (SLhape_File_Header *)0x0) {
      if (SDI_Capture_Info != 0) {
        pSVar12 = (Shape_Info *)(param_1->FShape + param_5 + 1);
        iVar14 = SDI_Draw_Level;
        lVar15 = SDI_Object_ID;
        iVar7 = _ASMGet_Color_Xform();
        DClipInfo_List::AddDrawNode
                  (SDI_List,param_1->FShape,pSVar12,SDI_Draw_Line,
                   (pSVar12->Hotspot_X - pSVar12->Width) + param_3,param_4 - pSVar12->Hotspot_Y,
                   fog_next_shape + 2,param_7,iVar7,iVar14,lVar15);
        return '\x01';
      }
      pTVar2 = param_2->CurSpanList;
      iVar14 = param_2->SpanList->Num_Lines;
      iVar7 = pTVar2->Num_Lines;
      if (iVar14 < iVar7) {
        iVar7 = iVar14;
      }
      _ASMSet_Surface_Info
                (param_2->CurDisplayOffsets,pTVar2->Line_Head_Ptrs,pTVar2->Line_Tail_Ptrs,0,0,
                 pTVar2->Max_Span_Px,iVar7 + -1);
      if (param_7 != (uchar *)0x0) {
        _ASMSet_Xlate_Table(param_7);
      }
      pSVar8 = param_1->FShape + param_5 + 1;
      _ASMDraw_Sprite(param_1->FShape,
                      (*(int *)(pSVar8->Comment + 0x10) + param_3) - *(int *)(pSVar8->Comment + 8),
                      param_4 - *(int *)(pSVar8->Comment + 0x14),*(int *)(pSVar8->Comment + 8),
                      *(undefined4 *)(pSVar8->Comment + 0xc),*(undefined4 *)pSVar8->Version,
                      pSVar8->Num_Shapes,fog_next_shape + 2);
      ASM_Fast_Count = ASM_Fast_Count + 1;
      return '\x01';
    }
    iVar14 = (param_2->ClipRect).left;
    iVar7 = (param_2->ClipRect).top;
    iVar3 = (param_2->ClipRect).right;
    iVar4 = (param_2->ClipRect).bottom;
    if (param_1->shape != (uchar *)0x0) {
      pSVar1 = (Shape_Header *)(param_1->shape + param_1->offsets[param_5].shape);
      param_1->shape_header = pSVar1;
      iVar13 = param_3 - pSVar1->xmax;
      iVar9 = pSVar1->ymin + param_4;
      iVar11 = param_3 - pSVar1->xmin;
      iVar10 = pSVar1->ymax + param_4;
      param_3 = iVar13;
      if (iVar13 < iVar14) {
        param_3 = iVar14;
      }
      iStack_18 = iVar9;
      if (iVar9 < iVar7) {
        iStack_18 = iVar7;
      }
      param_2 = (TDrawArea *)iVar11;
      if (iVar3 < iVar11) {
        param_2 = (TDrawArea *)iVar3;
      }
      param_4 = iVar10;
      if (iVar4 < iVar10) {
        param_4 = iVar4;
      }
      if (param_3 < 0) {
        param_3 = 0;
      }
      if (iStack_18 < 0) {
        iStack_18 = 0;
      }
      if (pTVar5->Width <= (int)param_2) {
        param_2 = (TDrawArea *)(pTVar5->Width + -1);
      }
      if (pTVar5->Height <= param_4) {
        param_4 = pTVar5->Height + -1;
      }
      if ((param_3 <= (int)param_2) && (iStack_18 <= param_4)) {
        if ((param_3 != iVar13) ||
           (((iStack_18 != iVar9 || (param_2 != (TDrawArea *)iVar11)) || (param_4 != iVar10)))) {
          if (param_6 != '\0') {
            if (param_6 == '\x01') {
              if (param_7 != (uchar *)0x0) {
                uVar6 = TShape::shape_mirror_color_trans_clipped
                                  (param_1,pTVar5,iVar11,iVar9,param_5,param_3,iStack_18,
                                   (long)param_2,param_4,param_7);
                return uVar6;
              }
            }
            else {
              if (param_6 != '\x02') {
                return '\0';
              }
              if (param_7 != (uchar *)0x0) {
                uVar6 = TShape::shape_mirror_shadow_clipped
                                  (param_1,pTVar5,iVar11,iVar9,param_3,iStack_18,(long)param_2,
                                   param_4,param_7);
                return uVar6;
              }
            }
          }
          uVar6 = TShape::shape_mirror_clipped
                            (param_1,pTVar5,iVar11,iVar9,param_3,iStack_18,(long)param_2,param_4);
          return uVar6;
        }
        if (param_6 == '\0') {
          uVar6 = TShape::shape_mirror_unclipped(param_1,pTVar5,iVar11,iVar9);
          return uVar6;
        }
        if (param_6 == '\x01') {
          if (param_7 == (uchar *)0x0) {
            uVar6 = TShape::shape_mirror_unclipped(param_1,pTVar5,iVar11,iVar9);
            return uVar6;
          }
          uVar6 = TShape::shape_mirror_color_trans_unclipped
                            (param_1,pTVar5,iVar11,iVar9,param_5,param_7);
          return uVar6;
        }
        if (param_6 != '\x02') {
          return '\0';
        }
        if (param_7 == (uchar *)0x0) {
          uVar6 = TShape::shape_mirror_unclipped(param_1,pTVar5,iVar11,iVar9);
          return uVar6;
        }
        uVar6 = TShape::shape_mirror_shadow_unclipped(param_1,pTVar5,iVar11,iVar9,param_7);
        return uVar6;
      }
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_004ba9dc
// Address: 004ba9dc
// XREFS: None
undefined4 __thiscall
FUN_004ba9dc(int param_1,TDrawArea *param_2,int param_3,int param_4,undefined4 param_5,int param_6)
{
  int iVar1;
  int iVar2;
  bool bVar3;
  byte bVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  uchar *puVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  uchar *puVar12;
  
  iVar1 = param_2->Orien;
  lVar5 = TDrawArea::AlignedWidth(param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  iVar9 = lVar5 * iVar1;
  iVar6 = (*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc)) + 1;
  pbVar11 = (byte *)(iVar2 + 0x18);
  if (iVar1 < 1) {
    puVar8 = param_2->Bits + ((param_4 - param_2->Height) + 1) * iVar9;
  }
  else {
    puVar8 = param_2->Bits + iVar9 * param_4;
  }
  puVar8 = puVar8 + param_3 + 1;
  param_2 = (TDrawArea *)iVar6;
  if (0 < iVar6) {
    do {
      bVar3 = false;
      pbVar10 = pbVar11;
      puVar12 = puVar8;
      do {
        bVar4 = *pbVar10;
        pbVar11 = pbVar10 + 1;
        if ((bVar4 & 1) == 1) {
          bVar4 = bVar4 >> 1;
          if (bVar4 == 0) {
            puVar12 = puVar12 + -(uint)*pbVar11;
LAB_004baabd:
            pbVar11 = pbVar10 + 2;
          }
          else if (bVar4 != 0) {
            uVar7 = (uint)bVar4;
            do {
              puVar12 = puVar12 + -1;
              bVar4 = *pbVar11;
              pbVar11 = pbVar11 + 1;
              uVar7 = uVar7 - 1;
              *puVar12 = *(uchar *)(param_6 + (uint)bVar4);
            } while (uVar7 != 0);
          }
        }
        else {
          bVar4 = bVar4 >> 1;
          if (bVar4 != 0) {
            puVar12 = puVar12 + -(uint)bVar4;
            memset(puVar12,*(undefined1 *)(param_6 + (uint)*pbVar11),(uint)bVar4);
            goto LAB_004baabd;
          }
          bVar3 = true;
        }
        pbVar10 = pbVar11;
      } while (!bVar3);
      puVar8 = puVar8 + iVar9;
      iVar6 = (int)param_2 + -1;
      param_2 = (TDrawArea *)iVar6;
    } while (iVar6 != 0);
  }
  return CONCAT31((int3)((uint)iVar6 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_004baae9
// Address: 004baae9
// XREFS: None
undefined4 __thiscall
FUN_004baae9(int param_1,TDrawArea *param_2,int param_3,uint param_4,int param_5)
{
  int iVar1;
  bool bVar2;
  long lVar3;
  int iVar4;
  uchar *puVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  
  iVar1 = param_2->Orien;
  lVar3 = TDrawArea::AlignedWidth(param_2);
  iVar4 = lVar3 * iVar1;
  iVar9 = *(int *)(param_1 + 0xc);
  pbVar12 = (byte *)(iVar9 + 0x18);
  iVar9 = (*(int *)(iVar9 + 0x14) - *(int *)(iVar9 + 0xc)) + 1;
  if (iVar1 < 1) {
    puVar5 = param_2->Bits + ((param_4 - param_2->Height) + 1) * iVar4;
  }
  else {
    puVar5 = param_2->Bits + iVar4 * param_4;
  }
  pbVar6 = puVar5 + param_3 + 1;
  param_2 = (TDrawArea *)iVar9;
  if (0 < iVar9) {
    do {
      bVar2 = false;
      pbVar7 = pbVar6;
      pbVar11 = pbVar12;
      do {
        bVar8 = *pbVar11;
        pbVar12 = pbVar11 + 1;
        if ((bVar8 & 1) == 1) {
          bVar8 = bVar8 >> 1;
          param_4 = (uint)bVar8;
          if (bVar8 == 0) {
            pbVar7 = pbVar7 + -(uint)*pbVar12;
LAB_004babcf:
            pbVar12 = pbVar11 + 2;
          }
          else {
            uVar10 = param_4;
            if (bVar8 != 0) {
              do {
                pbVar7 = pbVar7 + -1;
                uVar10 = uVar10 - 1;
                *pbVar7 = *(byte *)(param_5 + (uint)*pbVar7);
              } while (uVar10 != 0);
            }
            pbVar12 = pbVar12 + param_4;
          }
        }
        else {
          bVar8 = bVar8 >> 1;
          param_4 = (uint)bVar8;
          if (bVar8 != 0) {
            if (bVar8 != 0) {
              do {
                pbVar7 = pbVar7 + -1;
                param_4 = param_4 - 1;
                *pbVar7 = *(byte *)(param_5 + (uint)*pbVar7);
              } while (param_4 != 0);
            }
            goto LAB_004babcf;
          }
          bVar2 = true;
        }
        pbVar11 = pbVar12;
      } while (!bVar2);
      pbVar6 = pbVar6 + iVar4;
      param_2 = (TDrawArea *)((int)param_2 + -1);
    } while (param_2 != (TDrawArea *)0x0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004babfb
// Address: 004babfb
// XREFS: None
undefined4 __thiscall
FUN_004babfb(int param_1,TDrawArea *param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8)
{
  bool bVar1;
  byte bVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  uchar *puVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  
  iVar14 = param_2->Orien;
  lVar3 = TDrawArea::AlignedWidth(param_2);
  iVar6 = lVar3 * iVar14;
  pbVar12 = (byte *)(*(int *)(param_1 + 0xc) + 0x18);
  if (iVar14 < 1) {
    puVar9 = param_2->Bits + ((param_6 - param_2->Height) + 1) * iVar6;
  }
  else {
    puVar9 = param_2->Bits + iVar6 * param_6;
  }
  pbVar10 = puVar9 + param_7 + 1;
  if (param_4 < param_6) {
    param_2 = (TDrawArea *)(param_6 - param_4);
    param_4 = param_4 + (int)param_2;
    do {
      bVar1 = false;
      pbVar11 = pbVar12;
      do {
        bVar2 = *pbVar11;
        pbVar12 = pbVar11 + 1;
        if ((bVar2 & 1) == 1) {
          if (bVar2 >> 1 == 0) {
LAB_004bac9a:
            pbVar12 = pbVar11 + 2;
          }
          else {
            pbVar12 = pbVar12 + (bVar2 >> 1);
          }
        }
        else {
          if ((bVar2 & 0xfe) != 0) goto LAB_004bac9a;
          bVar1 = true;
        }
        pbVar11 = pbVar12;
      } while (!bVar1);
      param_2 = (TDrawArea *)((int)param_2 + -1);
    } while (param_2 != (TDrawArea *)0x0);
  }
  if (param_4 <= param_8) {
    param_4 = (param_8 - param_4) + 1;
    do {
      pbVar11 = pbVar10;
      iVar14 = param_3;
      if (param_7 < param_3) {
        cVar8 = '\0';
        pbVar13 = pbVar12;
        do {
          bVar2 = *pbVar13;
          pbVar12 = pbVar13 + 1;
          if ((bVar2 & 1) == 1) {
            if (bVar2 >> 1 == 0) {
              iVar14 = iVar14 - (uint)*pbVar12;
              pbVar12 = pbVar13 + 2;
              if (iVar14 <= param_7) {
                if (iVar14 < param_5) {
                  cVar8 = '\x02';
                }
                else {
                  cVar8 = '\x01';
                  pbVar11 = pbVar11 + (iVar14 - param_7);
                }
              }
            }
            else {
              uVar7 = (uint)(bVar2 >> 1);
              iVar14 = iVar14 - uVar7;
              if (param_7 < iVar14) {
                pbVar12 = pbVar12 + uVar7;
              }
              else if (iVar14 < param_5) {
                uVar5 = (param_7 - param_5) + 1;
                cVar8 = '\x02';
                pbVar13 = pbVar13 + (iVar14 - param_7) + uVar7;
                if ((char)uVar5 != '\0') {
                  uVar5 = uVar5 & 0xff;
                  do {
                    bVar2 = *pbVar13;
                    pbVar11 = pbVar11 + -1;
                    pbVar13 = pbVar13 + 1;
                    uVar5 = uVar5 - 1;
                    *pbVar11 = bVar2;
                  } while (uVar5 != 0);
                }
                pbVar12 = pbVar13 + (param_5 - iVar14);
              }
              else {
                cVar8 = '\x01';
                uVar5 = param_7 - iVar14;
                pbVar12 = pbVar12 + (uVar7 - uVar5);
                if ((char)uVar5 != '\0') {
                  uVar5 = uVar5 & 0xff;
                  do {
                    bVar2 = *pbVar12;
                    pbVar11 = pbVar11 + -1;
                    pbVar12 = pbVar12 + 1;
                    uVar5 = uVar5 - 1;
                    *pbVar11 = bVar2;
                  } while (uVar5 != 0);
                }
              }
            }
          }
          else if (bVar2 >> 1 == 0) {
            cVar8 = '\x03';
          }
          else {
            iVar14 = iVar14 - (uint)(bVar2 >> 1);
            if (iVar14 <= param_7) {
              if (iVar14 < param_5) {
                cVar8 = '\x02';
                iVar4 = (param_7 - param_5) + 1;
                bVar2 = *pbVar12;
              }
              else {
                cVar8 = '\x01';
                iVar4 = param_7 - iVar14;
                bVar2 = *pbVar12;
              }
              pbVar11 = pbVar11 + -iVar4;
              memset(pbVar11,bVar2,iVar4);
            }
            pbVar12 = pbVar13 + 2;
          }
          pbVar13 = pbVar12;
        } while (cVar8 == '\0');
      }
      else {
        cVar8 = '\x01';
      }
      cVar8 = cVar8 + -1;
      while (cVar8 == '\0') {
        bVar2 = *pbVar12;
        pbVar13 = pbVar12 + 1;
        if ((bVar2 & 1) == 1) {
          bVar2 = bVar2 >> 1;
          if (bVar2 == 0) {
            iVar14 = iVar14 - (uint)*pbVar13;
            pbVar11 = pbVar11 + -(uint)*pbVar13;
            pbVar12 = pbVar12 + 2;
            if (iVar14 < param_5) {
              cVar8 = '\x01';
            }
          }
          else {
            uVar7 = (uint)bVar2;
            iVar14 = iVar14 - uVar7;
            if (iVar14 < param_5) {
              cVar8 = '\x01';
              uVar5 = (iVar14 - param_5) + uVar7;
              if ((char)uVar5 != '\0') {
                param_2 = (TDrawArea *)(uVar5 & 0xff);
                do {
                  bVar2 = *pbVar13;
                  pbVar11 = pbVar11 + -1;
                  pbVar13 = pbVar13 + 1;
                  *pbVar11 = bVar2;
                  param_2 = (TDrawArea *)((int)param_2 - 1);
                } while (param_2 != (TDrawArea *)0x0);
              }
              pbVar12 = pbVar13 + (uVar7 - uVar5);
            }
            else {
              pbVar12 = pbVar13;
              if (bVar2 != 0) {
                do {
                  bVar2 = *pbVar13;
                  pbVar11 = pbVar11 + -1;
                  pbVar13 = pbVar13 + 1;
                  uVar7 = uVar7 - 1;
                  *pbVar11 = bVar2;
                  pbVar12 = pbVar13;
                } while (uVar7 != 0);
              }
            }
          }
        }
        else if (bVar2 >> 1 == 0) {
          cVar8 = '\x03';
          pbVar12 = pbVar13;
        }
        else {
          uVar7 = (uint)(bVar2 >> 1);
          iVar14 = iVar14 - uVar7;
          if (iVar14 < param_5) {
            cVar8 = '\x01';
            uVar7 = (iVar14 - param_5) + uVar7;
            bVar2 = *pbVar13;
          }
          else {
            bVar2 = *pbVar13;
          }
          pbVar11 = pbVar11 + -uVar7;
          memset(pbVar11,bVar2,uVar7);
          pbVar12 = pbVar12 + 2;
        }
      }
      cVar8 = cVar8 + -1;
      while (cVar8 == '\0') {
        bVar2 = *pbVar12;
        if ((bVar2 & 1) == 1) {
          if (bVar2 >> 1 == 0) {
LAB_004baef1:
            pbVar12 = pbVar12 + 2;
          }
          else {
            pbVar12 = pbVar12 + 1 + (bVar2 >> 1);
          }
        }
        else {
          if ((bVar2 & 0xfe) != 0) goto LAB_004baef1;
          cVar8 = '\x02';
          pbVar12 = pbVar12 + 1;
        }
      }
      pbVar10 = pbVar10 + iVar6;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004baf1f
// Address: 004baf1f
// XREFS: None
undefined4 __thiscall
FUN_004baf1f(int param_1,TDrawArea *param_2,int param_3,uint param_4,undefined4 param_5,int param_6,
            uint param_7,int param_8,int param_9,int param_10)
{
  bool bVar1;
  byte bVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  uchar *puVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  uchar *puVar13;
  
  iVar10 = param_2->Orien;
  lVar3 = TDrawArea::AlignedWidth(param_2);
  iVar7 = lVar3 * iVar10;
  pbVar11 = (byte *)(*(int *)(param_1 + 0xc) + 0x18);
  if (iVar10 < 1) {
    puVar9 = param_2->Bits + ((param_7 - param_2->Height) + 1) * iVar7;
  }
  else {
    puVar9 = param_2->Bits + iVar7 * param_7;
  }
  puVar9 = puVar9 + param_8 + 1;
  if ((int)param_4 < (int)param_7) {
    param_7 = param_7 - param_4;
    param_4 = param_4 + param_7;
    do {
      bVar1 = false;
      pbVar12 = pbVar11;
      do {
        bVar2 = *pbVar12;
        pbVar11 = pbVar12 + 1;
        if ((bVar2 & 1) == 1) {
          if (bVar2 >> 1 == 0) {
LAB_004bafba:
            pbVar11 = pbVar12 + 2;
          }
          else {
            pbVar11 = pbVar11 + (bVar2 >> 1);
          }
        }
        else {
          if ((bVar2 & 0xfe) != 0) goto LAB_004bafba;
          bVar1 = true;
        }
        pbVar12 = pbVar11;
      } while (!bVar1);
      param_7 = param_7 + -1;
    } while (param_7 != 0);
  }
  if ((int)param_4 <= param_9) {
    param_9 = (param_9 - param_4) + 1;
    do {
      iVar10 = param_3;
      puVar13 = puVar9;
      if (param_8 < param_3) {
        cVar8 = '\0';
        pbVar12 = pbVar11;
        do {
          bVar2 = *pbVar12;
          pbVar11 = pbVar12 + 1;
          if ((bVar2 & 1) == 1) {
            if (bVar2 >> 1 == 0) {
              iVar10 = iVar10 - (uint)*pbVar11;
              pbVar11 = pbVar12 + 2;
              if (iVar10 <= param_8) {
                if (iVar10 < param_6) {
                  cVar8 = '\x02';
                }
                else {
                  cVar8 = '\x01';
                  puVar13 = puVar13 + (iVar10 - param_8);
                }
              }
            }
            else {
              uVar6 = (uint)(bVar2 >> 1);
              iVar10 = iVar10 - uVar6;
              if (param_8 < iVar10) {
                pbVar11 = pbVar11 + uVar6;
              }
              else if (iVar10 < param_6) {
                uVar4 = (param_8 - param_6) + 1;
                cVar8 = '\x02';
                pbVar12 = pbVar12 + (iVar10 - param_8) + uVar6;
                if ((char)uVar4 != '\0') {
                  uVar4 = uVar4 & 0xff;
                  do {
                    bVar2 = *pbVar12;
                    puVar13 = puVar13 + -1;
                    pbVar12 = pbVar12 + 1;
                    uVar4 = uVar4 - 1;
                    *puVar13 = *(uchar *)(param_10 + (uint)bVar2);
                  } while (uVar4 != 0);
                }
                pbVar11 = pbVar12 + (param_6 - iVar10);
              }
              else {
                cVar8 = '\x01';
                uVar4 = param_8 - iVar10;
                pbVar11 = pbVar11 + (uVar6 - uVar4);
                if ((char)uVar4 != '\0') {
                  uVar4 = uVar4 & 0xff;
                  do {
                    bVar2 = *pbVar11;
                    puVar13 = puVar13 + -1;
                    pbVar11 = pbVar11 + 1;
                    uVar4 = uVar4 - 1;
                    *puVar13 = *(uchar *)(param_10 + (uint)bVar2);
                  } while (uVar4 != 0);
                }
              }
            }
          }
          else if (bVar2 >> 1 == 0) {
            cVar8 = '\x03';
          }
          else {
            iVar10 = iVar10 - (uint)(bVar2 >> 1);
            if (iVar10 <= param_8) {
              if (iVar10 < param_6) {
                cVar8 = '\x02';
                iVar5 = (param_8 - param_6) + 1;
              }
              else {
                cVar8 = '\x01';
                iVar5 = param_8 - iVar10;
              }
              puVar13 = puVar13 + -iVar5;
              memset(puVar13,*(undefined1 *)(param_10 + (uint)*pbVar11),iVar5);
            }
            pbVar11 = pbVar12 + 2;
          }
          pbVar12 = pbVar11;
        } while (cVar8 == '\0');
      }
      else {
        cVar8 = '\x01';
      }
      cVar8 = cVar8 + -1;
      while (cVar8 == '\0') {
        bVar2 = *pbVar11;
        pbVar12 = pbVar11 + 1;
        if ((bVar2 & 1) == 1) {
          bVar2 = bVar2 >> 1;
          if (bVar2 == 0) {
            iVar10 = iVar10 - (uint)*pbVar12;
            puVar13 = puVar13 + -(uint)*pbVar12;
            pbVar11 = pbVar11 + 2;
            if (iVar10 < param_6) {
              cVar8 = '\x01';
            }
          }
          else {
            param_7 = (uint)bVar2;
            iVar10 = iVar10 - param_7;
            if (iVar10 < param_6) {
              uVar6 = (iVar10 - param_6) + param_7;
              if ((char)uVar6 != '\0') {
                param_4 = uVar6 & 0xff;
                do {
                  bVar2 = *pbVar12;
                  puVar13 = puVar13 + -1;
                  pbVar12 = pbVar12 + 1;
                  *puVar13 = *(uchar *)(param_10 + (uint)bVar2);
                  param_4 = param_4 - 1;
                } while (param_4 != 0);
              }
              cVar8 = '\x01';
              pbVar11 = pbVar12 + (param_7 - uVar6);
            }
            else {
              pbVar11 = pbVar12;
              if (bVar2 != 0) {
                do {
                  bVar2 = *pbVar12;
                  puVar13 = puVar13 + -1;
                  pbVar12 = pbVar12 + 1;
                  *puVar13 = *(uchar *)(param_10 + (uint)bVar2);
                  param_7 = param_7 - 1;
                  pbVar11 = pbVar12;
                } while (param_7 != 0);
              }
            }
          }
        }
        else if (bVar2 >> 1 == 0) {
          cVar8 = '\x03';
          pbVar11 = pbVar12;
        }
        else {
          uVar6 = (uint)(bVar2 >> 1);
          iVar10 = iVar10 - uVar6;
          if (iVar10 < param_6) {
            cVar8 = '\x01';
            uVar6 = (iVar10 - param_6) + uVar6;
          }
          puVar13 = puVar13 + -uVar6;
          memset(puVar13,*(undefined1 *)(param_10 + (uint)*pbVar12),uVar6);
          pbVar11 = pbVar11 + 2;
        }
      }
      cVar8 = cVar8 + -1;
      while (cVar8 == '\0') {
        bVar2 = *pbVar11;
        if ((bVar2 & 1) == 1) {
          if (bVar2 >> 1 == 0) {
LAB_004bb251:
            pbVar11 = pbVar11 + 2;
          }
          else {
            pbVar11 = pbVar11 + 1 + (bVar2 >> 1);
          }
        }
        else {
          if ((bVar2 & 0xfe) != 0) goto LAB_004bb251;
          cVar8 = '\x02';
          pbVar11 = pbVar11 + 1;
        }
      }
      puVar9 = puVar9 + iVar7;
      param_9 = param_9 + -1;
    } while (param_9 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004bb27f
// Address: 004bb27f
// XREFS: None
undefined4 __thiscall
FUN_004bb27f(int param_1,TDrawArea *param_2,int param_3,int param_4,int param_5,uint param_6,
            int param_7,int param_8,int param_9)
{
  bool bVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  uchar *puVar5;
  byte *pbVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  
  iVar8 = param_2->Orien;
  lVar3 = TDrawArea::AlignedWidth(param_2);
  iVar4 = lVar3 * iVar8;
  pbVar10 = (byte *)(*(int *)(param_1 + 0xc) + 0x18);
  if (iVar8 < 1) {
    puVar5 = param_2->Bits + ((param_6 - param_2->Height) + 1) * iVar4;
  }
  else {
    puVar5 = param_2->Bits + iVar4 * param_6;
  }
  pbVar6 = puVar5 + param_7 + 1;
  param_2 = (TDrawArea *)pbVar10;
  if (param_4 < (int)param_6) {
    iVar8 = param_6 - param_4;
    param_4 = param_4 + iVar8;
    do {
      bVar1 = false;
      pbVar11 = pbVar10;
      do {
        bVar7 = *pbVar11;
        pbVar10 = pbVar11 + 1;
        if ((bVar7 & 1) == 1) {
          param_6 = (uint)(bVar7 >> 1);
          if (bVar7 >> 1 == 0) {
LAB_004bb31c:
            pbVar10 = pbVar11 + 2;
          }
          else {
            pbVar10 = pbVar10 + param_6;
          }
        }
        else {
          if ((bVar7 & 0xfe) != 0) goto LAB_004bb31c;
          bVar1 = true;
        }
        pbVar11 = pbVar10;
      } while (!bVar1);
      iVar8 = iVar8 + -1;
      param_2 = (TDrawArea *)pbVar10;
    } while (iVar8 != 0);
  }
  if (param_4 <= param_8) {
    param_4 = (param_8 - param_4) + 1;
    do {
      pbVar10 = pbVar6;
      iVar8 = param_3;
      if (param_7 < param_3) {
        cVar2 = '\0';
        pbVar11 = (byte *)param_2;
        do {
          bVar7 = *pbVar11;
          param_2 = (TDrawArea *)(pbVar11 + 1);
          if ((bVar7 & 1) == 1) {
            param_6 = (uint)(bVar7 >> 1);
            if (bVar7 >> 1 == 0) {
              iVar8 = iVar8 - (uint)*(byte *)param_2;
              param_2 = (TDrawArea *)(pbVar11 + 2);
              if (iVar8 <= param_7) {
                if (iVar8 < param_5) {
                  cVar2 = '\x02';
                }
                else {
                  cVar2 = '\x01';
                  pbVar10 = pbVar10 + (iVar8 - param_7);
                }
              }
            }
            else {
              iVar8 = iVar8 - param_6;
              if (iVar8 <= param_7) {
                if (iVar8 < param_5) {
                  cVar2 = '\x02';
                  uVar9 = (param_7 - param_5) + 1;
                  if ((char)uVar9 != '\0') {
                    uVar9 = uVar9 & 0xff;
                    do {
                      pbVar10 = pbVar10 + -1;
                      uVar9 = uVar9 - 1;
                      *pbVar10 = *(byte *)((uint)*pbVar10 + param_9);
                    } while (uVar9 != 0);
                    param_2 = (TDrawArea *)((int)param_2 + param_6);
                    goto LAB_004bb477;
                  }
                }
                else {
                  cVar2 = '\x01';
                  if ((char)(param_7 - iVar8) != '\0') {
                    uVar9 = param_7 - iVar8 & 0xff;
                    do {
                      pbVar10 = pbVar10 + -1;
                      uVar9 = uVar9 - 1;
                      *pbVar10 = *(byte *)((uint)*pbVar10 + param_9);
                    } while (uVar9 != 0);
                  }
                }
              }
              param_2 = (TDrawArea *)((int)param_2 + param_6);
            }
          }
          else {
            param_6 = (uint)(bVar7 >> 1);
            if (bVar7 >> 1 == 0) {
              cVar2 = '\x03';
            }
            else {
              iVar8 = iVar8 - param_6;
              if (iVar8 <= param_7) {
                if (iVar8 < param_5) {
                  cVar2 = '\x02';
                  uVar9 = (param_7 - param_5) + 1;
                  if ((char)uVar9 != '\0') {
                    uVar9 = uVar9 & 0xff;
                    do {
                      pbVar10 = pbVar10 + -1;
                      uVar9 = uVar9 - 1;
                      *pbVar10 = *(byte *)((uint)*pbVar10 + param_9);
                    } while (uVar9 != 0);
                  }
                }
                else {
                  cVar2 = '\x01';
                  if ((char)(param_7 - iVar8) != '\0') {
                    uVar9 = param_7 - iVar8 & 0xff;
                    do {
                      pbVar10 = pbVar10 + -1;
                      uVar9 = uVar9 - 1;
                      *pbVar10 = *(byte *)((uint)*pbVar10 + param_9);
                    } while (uVar9 != 0);
                  }
                }
              }
              param_2 = (TDrawArea *)(pbVar11 + 2);
            }
          }
LAB_004bb477:
          pbVar11 = (byte *)param_2;
        } while (cVar2 == '\0');
      }
      else {
        cVar2 = '\x01';
      }
      cVar2 = cVar2 + -1;
joined_r0x004bb485:
      if (cVar2 == '\0') {
        bVar7 = *(byte *)param_2;
        pbVar11 = (byte *)((int)param_2 + 1);
        if ((bVar7 & 1) == 1) {
          bVar7 = bVar7 >> 1;
          param_6 = (uint)bVar7;
          if (bVar7 == 0) {
            iVar8 = iVar8 - (uint)*pbVar11;
            pbVar10 = pbVar10 + -(uint)*pbVar11;
            param_2 = (TDrawArea *)((int)param_2 + 2);
            if (iVar8 < param_5) {
              cVar2 = '\x01';
            }
            goto joined_r0x004bb485;
          }
          iVar8 = iVar8 - param_6;
          if (iVar8 < param_5) {
            cVar2 = '\x01';
            uVar9 = (iVar8 - param_5) + param_6;
            if ((char)uVar9 != '\0') {
              uVar9 = uVar9 & 0xff;
              do {
                pbVar10 = pbVar10 + -1;
                uVar9 = uVar9 - 1;
                *pbVar10 = *(byte *)((uint)*pbVar10 + param_9);
              } while (uVar9 != 0);
              param_2 = (TDrawArea *)(pbVar11 + param_6);
              goto joined_r0x004bb485;
            }
          }
          else {
            uVar9 = param_6;
            if (bVar7 != 0) {
              do {
                pbVar10 = pbVar10 + -1;
                uVar9 = uVar9 - 1;
                *pbVar10 = *(byte *)((uint)*pbVar10 + param_9);
              } while (uVar9 != 0);
            }
          }
          param_2 = (TDrawArea *)(pbVar11 + param_6);
          goto joined_r0x004bb485;
        }
        bVar7 = bVar7 >> 1;
        param_6 = (uint)bVar7;
        if (bVar7 == 0) {
          cVar2 = '\x03';
          param_2 = (TDrawArea *)pbVar11;
        }
        else {
          iVar8 = iVar8 - param_6;
          if (iVar8 < param_5) {
            cVar2 = '\x01';
            param_6 = (iVar8 - param_5) + param_6;
            if ((char)param_6 != '\0') {
              param_6 = param_6 & 0xff;
              do {
                pbVar10 = pbVar10 + -1;
                param_6 = param_6 - 1;
                *pbVar10 = *(byte *)((uint)*pbVar10 + param_9);
              } while (param_6 != 0);
            }
          }
          else if (bVar7 != 0) {
            do {
              pbVar10 = pbVar10 + -1;
              param_6 = param_6 - 1;
              *pbVar10 = *(byte *)((uint)*pbVar10 + param_9);
            } while (param_6 != 0);
          }
          param_2 = (TDrawArea *)((int)param_2 + 2);
        }
        goto joined_r0x004bb485;
      }
      cVar2 = cVar2 + -1;
      while (cVar2 == '\0') {
        bVar7 = *(byte *)param_2;
        if ((bVar7 & 1) == 1) {
          param_6 = (uint)(bVar7 >> 1);
          if (bVar7 >> 1 == 0) {
LAB_004bb5ab:
            param_2 = (TDrawArea *)((int)param_2 + 2);
          }
          else {
            param_2 = (TDrawArea *)((byte *)((int)param_2 + 1) + param_6);
          }
        }
        else {
          if ((bVar7 & 0xfe) != 0) goto LAB_004bb5ab;
          cVar2 = '\x02';
          param_2 = (TDrawArea *)((int)param_2 + 1);
        }
      }
      pbVar6 = pbVar6 + iVar4;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004bb5d9
// Address: 004bb5d9
// XREFS: None
// [HELPER] s_RGL_shape_draw: "RGL_shape_draw"
uchar __thiscall
FUN_004bb5d9(TShape *param_1,TDrawArea *param_2,int param_3,int param_4,int param_5,long param_6,
            long param_7)
{
  Shape_Header *pSVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uchar uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iStack_14;
  
  iVar2 = (param_2->ClipRect).left;
  iVar3 = (param_2->ClipRect).top;
  iVar4 = (param_2->ClipRect).right;
  iVar5 = (param_2->ClipRect).bottom;
  uVar6 = TShape::Check_shape(param_1,param_5,s_RGL_shape_draw);
  if (uVar6 == '\0') {
    pSVar1 = (Shape_Header *)(param_1->shape + param_1->offsets[param_5].shape);
    param_1->shape_header = pSVar1;
    iVar9 = pSVar1->ymin + param_4;
    iVar10 = pSVar1->xmax + param_3;
    iVar7 = pSVar1->ymax + param_4;
    iVar8 = pSVar1->xmin + param_3;
    param_3 = iVar8;
    if (iVar8 < iVar2) {
      param_3 = iVar2;
    }
    param_5 = iVar9;
    if (iVar9 < iVar3) {
      param_5 = iVar3;
    }
    param_4 = iVar10;
    if (iVar4 < iVar10) {
      param_4 = iVar4;
    }
    iStack_14 = iVar7;
    if (iVar5 < iVar7) {
      iStack_14 = iVar5;
    }
    if (param_3 < 0) {
      param_3 = 0;
    }
    if (param_5 < 0) {
      param_5 = 0;
    }
    if (param_2->Width <= param_4) {
      param_4 = param_2->Width + -1;
    }
    if (param_2->Height <= iStack_14) {
      iStack_14 = param_2->Height + -1;
    }
    if ((param_3 <= param_4) && (param_5 <= iStack_14)) {
      if ((((param_3 == iVar8) && (param_5 == iVar9)) && (param_4 == iVar10)) &&
         (iStack_14 == iVar7)) {
        uVar6 = TShape::shape_dithered_unclipped(param_1,param_2,iVar8,iVar9,param_6,param_7);
        return uVar6;
      }
      uVar6 = TShape::shape_dithered_clipped
                        (param_1,param_2,iVar8,iVar9,param_3,param_5,param_4,iStack_14,param_6,
                         param_7);
      return uVar6;
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_004bb764
// Address: 004bb764
// XREFS: None
undefined4 __thiscall
FUN_004bb764(int param_1,TDrawArea *param_2,uint param_3,int param_4,uint param_5,int param_6)
{
  int iVar1;
  bool bVar2;
  byte bVar3;
  long lVar4;
  int iVar5;
  uchar *puVar6;
  uchar *puVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  uchar *puVar11;
  int iVar12;
  bool bVar13;
  
  iVar12 = param_2->Orien;
  lVar4 = TDrawArea::AlignedWidth(param_2);
  iVar1 = *(int *)(param_1 + 0xc);
  iVar8 = lVar4 * iVar12;
  iVar5 = (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + 1;
  pbVar10 = (byte *)(iVar1 + 0x18);
  iVar1 = param_4;
  if (iVar12 < 1) {
    iVar1 = (param_4 - param_2->Height) + 1;
  }
  puVar6 = param_2->Bits + param_3 + iVar1 * iVar8;
  param_3 = param_5 + param_3 & 1;
  if ((param_6 + param_4 & 1U) != 0) {
    param_3 = (uint)(param_3 != 1);
  }
  iVar12 = iVar5;
  if (0 < iVar5) {
    do {
      bVar13 = param_3 != 1;
      bVar2 = false;
      puVar7 = puVar6;
      pbVar9 = pbVar10;
      do {
        bVar3 = *pbVar9;
        pbVar10 = pbVar9 + 1;
        if ((bVar3 & 1) == 1) {
          bVar3 = bVar3 >> 1;
          param_5 = (uint)bVar3;
          if (bVar3 == 0) {
            puVar7 = puVar7 + *pbVar10;
            if ((*pbVar10 & 1) != 0) {
              param_3 = (uint)(param_3 != 1);
            }
LAB_004bb8d6:
            pbVar10 = pbVar9 + 2;
          }
          else {
            if (param_3 != 0) {
              bVar3 = bVar3 - 1;
              puVar7 = puVar7 + 1;
            }
            param_3 = (uint)bVar3;
            puVar11 = puVar7 + param_3;
            param_3 = param_3 & 1;
            for (; puVar7 < puVar11; puVar7 = puVar7 + 2) {
              *puVar7 = '\0';
            }
            if ((bVar3 & 1) != 0) {
              puVar7 = puVar7 + -1;
            }
            pbVar10 = pbVar10 + param_5;
          }
        }
        else {
          bVar3 = bVar3 >> 1;
          if (bVar3 != 0) {
            if (param_3 != 0) {
              bVar3 = bVar3 - 1;
              puVar7 = puVar7 + 1;
            }
            param_3 = (uint)bVar3;
            puVar11 = puVar7 + param_3;
            param_3 = param_3 & 1;
            for (; puVar7 < puVar11; puVar7 = puVar7 + 2) {
              *puVar7 = '\0';
            }
            if ((bVar3 & 1) != 0) {
              puVar7 = puVar7 + -1;
            }
            goto LAB_004bb8d6;
          }
          bVar2 = true;
        }
        iVar5 = 0;
        pbVar9 = pbVar10;
      } while (!bVar2);
      puVar6 = puVar6 + iVar8;
      iVar12 = iVar12 + -1;
      param_3 = (uint)bVar13;
    } while (iVar12 != 0);
  }
  return CONCAT31((int3)((uint)iVar5 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_004bb904
// Address: 004bb904
// XREFS: None
undefined4 __thiscall
FUN_004bb904(int param_1,TDrawArea *param_2,int param_3,uint param_4,int param_5,int param_6,
            int param_7,int param_8,char param_9,int param_10)
{
  int iVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  long lVar5;
  int iVar6;
  uchar *puVar7;
  uchar *puVar8;
  bool bVar9;
  char cVar10;
  byte bVar11;
  uchar *puVar12;
  byte *pbVar13;
  byte *pbVar14;
  bool bVar15;
  
  iVar1 = param_2->Orien;
  lVar5 = TDrawArea::AlignedWidth(param_2);
  iVar6 = lVar5 * iVar1;
  pbVar13 = (byte *)(*(int *)(param_1 + 0xc) + 0x18);
  iVar3 = param_6;
  if (iVar1 < 1) {
    iVar3 = (param_6 - param_2->Height) + 1;
  }
  puVar7 = param_2->Bits + param_5 + iVar3 * iVar6;
  cVar4 = (char)param_5;
  bVar9 = (bool)(param_9 + cVar4 & 1);
  if ((param_10 + param_6 & 1U) != 0) {
    bVar9 = bVar9 != true;
  }
  iVar1 = param_4;
  if ((int)param_4 < param_6) {
    param_6 = param_6 - param_4;
    iVar1 = param_4 + param_6;
    do {
      bVar15 = false;
      pbVar14 = pbVar13;
      do {
        bVar11 = *pbVar14;
        pbVar13 = pbVar14 + 1;
        if ((bVar11 & 1) == 1) {
          param_4 = (uint)(bVar11 >> 1);
          if (bVar11 >> 1 == 0) {
LAB_004bb9c9:
            pbVar13 = pbVar14 + 2;
          }
          else {
            pbVar13 = pbVar13 + param_4;
          }
        }
        else {
          if ((bVar11 & 0xfe) != 0) goto LAB_004bb9c9;
          bVar15 = true;
        }
        pbVar14 = pbVar13;
      } while (!bVar15);
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  do {
    if (param_8 < iVar1) {
      return 1;
    }
    bVar15 = bVar9 != true;
    param_10 = param_3;
    cVar2 = (char)param_7;
    puVar8 = puVar7;
    if (param_3 < param_5) {
      cVar10 = '\0';
      pbVar14 = pbVar13;
      do {
        bVar11 = *pbVar14;
        pbVar13 = pbVar14 + 1;
        if ((bVar11 & 1) == 1) {
          param_4 = (uint)(bVar11 >> 1);
          if (bVar11 >> 1 == 0) {
            param_10 = param_10 + (uint)*pbVar13;
            pbVar13 = pbVar14 + 2;
            if (param_5 <= param_10) {
              if (param_7 < param_10) {
                cVar10 = '\x02';
              }
              else {
                cVar10 = '\x01';
                bVar11 = (char)param_10 - cVar4;
                _param_9 = (uint)bVar11;
                puVar8 = puVar8 + _param_9;
                if ((bVar11 & 1) != 0) {
                  bVar9 = bVar9 != true;
                }
              }
            }
          }
          else {
            param_10 = param_10 + param_4;
            if (param_5 < param_10) {
              if (param_7 < param_10) {
                cVar10 = '\x02';
                bVar11 = (cVar2 - cVar4) + 1;
                if (bVar9 != false) {
                  puVar8 = puVar8 + 1;
                  bVar11 = cVar2 - cVar4;
                }
                _param_9 = (uint)bVar11;
                bVar9 = (bool)(bVar11 & 1);
                puVar12 = puVar8 + _param_9;
                for (; puVar8 < puVar12; puVar8 = puVar8 + 2) {
                  *puVar8 = '\0';
                }
                if (bVar9 != false) {
                  puVar8 = puVar8 + -1;
                  pbVar13 = pbVar13 + param_4;
                  goto LAB_004bbbf1;
                }
              }
              else {
                cVar10 = '\x01';
                bVar11 = (char)param_10 - cVar4;
                if (bVar9 != false) {
                  bVar11 = bVar11 - 1;
                  puVar8 = puVar8 + 1;
                }
                _param_9 = (uint)bVar11;
                bVar9 = (bool)(bVar11 & 1);
                puVar12 = puVar8 + _param_9;
                for (; puVar8 < puVar12; puVar8 = puVar8 + 2) {
                  *puVar8 = '\0';
                }
                if (bVar9 != false) {
                  puVar8 = puVar8 + -1;
                }
              }
            }
            pbVar13 = pbVar13 + param_4;
          }
        }
        else {
          param_4 = (uint)(bVar11 >> 1);
          if (bVar11 >> 1 == 0) {
            cVar10 = '\x03';
          }
          else {
            param_10 = param_10 + param_4;
            if (param_5 < param_10) {
              if (param_7 < param_10) {
                cVar10 = '\x02';
                bVar11 = (cVar2 - cVar4) + 1;
                if (bVar9 != false) {
                  puVar8 = puVar8 + 1;
                  bVar11 = cVar2 - cVar4;
                }
                _param_9 = (uint)bVar11;
                puVar12 = puVar8 + _param_9;
                for (; puVar8 < puVar12; puVar8 = puVar8 + 2) {
                  *puVar8 = '\0';
                }
              }
              else {
                cVar10 = '\x01';
                bVar11 = (char)param_10 - cVar4;
                if (bVar9 != false) {
                  bVar11 = bVar11 - 1;
                  puVar8 = puVar8 + 1;
                }
                _param_9 = (uint)bVar11;
                puVar12 = puVar8 + _param_9;
                for (; puVar8 < puVar12; puVar8 = puVar8 + 2) {
                  *puVar8 = '\0';
                }
              }
              bVar9 = (bool)(bVar11 & 1);
              if (bVar9 != false) {
                puVar8 = puVar8 + -1;
              }
            }
            pbVar13 = pbVar14 + 2;
          }
        }
LAB_004bbbf1:
        pbVar14 = pbVar13;
      } while (cVar10 == '\0');
    }
    else {
      cVar10 = '\x01';
    }
    cVar10 = cVar10 + -1;
joined_r0x004bbc07:
    if (cVar10 == '\0') {
      bVar11 = *pbVar13;
      pbVar14 = pbVar13 + 1;
      if ((bVar11 & 1) == 1) {
        bVar11 = bVar11 >> 1;
        param_4 = (uint)bVar11;
        if (bVar11 == 0) {
          bVar11 = *pbVar14;
          param_10 = param_10 + (uint)bVar11;
          if ((bVar11 & 1) != 0) {
            bVar9 = bVar9 != true;
          }
          puVar8 = puVar8 + bVar11;
          pbVar13 = pbVar13 + 2;
          if (param_7 < param_10) {
            cVar10 = '\x01';
          }
          goto joined_r0x004bbc07;
        }
        param_10 = param_10 + param_4;
        if (param_7 < param_10) {
          cVar10 = '\x01';
          bVar11 = (cVar2 - (char)param_10) + '\x01' + bVar11;
          if (bVar9 != false) {
            bVar11 = bVar11 - 1;
            puVar8 = puVar8 + 1;
          }
          _param_9 = (uint)bVar11;
          bVar9 = (bool)(bVar11 & 1);
          puVar12 = puVar8 + _param_9;
          for (; puVar8 < puVar12; puVar8 = puVar8 + 2) {
            *puVar8 = '\0';
          }
          if (bVar9 != false) {
            puVar8 = puVar8 + -1;
            pbVar13 = pbVar14 + param_4;
            goto joined_r0x004bbc07;
          }
        }
        else {
          if (bVar9 != false) {
            bVar11 = bVar11 - 1;
            puVar8 = puVar8 + 1;
          }
          _param_9 = (uint)bVar11;
          bVar9 = (bool)(bVar11 & 1);
          puVar12 = puVar8 + _param_9;
          for (; puVar8 < puVar12; puVar8 = puVar8 + 2) {
            *puVar8 = '\0';
          }
          if (bVar9 != false) {
            puVar8 = puVar8 + -1;
          }
        }
        pbVar13 = pbVar14 + param_4;
        goto joined_r0x004bbc07;
      }
      bVar11 = bVar11 >> 1;
      param_4 = (uint)bVar11;
      if (bVar11 == 0) {
        cVar10 = '\x03';
        pbVar13 = pbVar14;
      }
      else {
        param_10 = param_10 + param_4;
        if (param_7 < param_10) {
          cVar10 = '\x01';
          bVar11 = (cVar2 - (char)param_10) + '\x01' + bVar11;
          if (bVar9 != false) {
            bVar11 = bVar11 - 1;
            puVar8 = puVar8 + 1;
          }
          _param_9 = (uint)bVar11;
          bVar9 = (bool)(bVar11 & 1);
          puVar12 = puVar8 + _param_9;
          for (; puVar8 < puVar12; puVar8 = puVar8 + 2) {
            *puVar8 = '\0';
          }
          if (bVar9 != false) {
            puVar8 = puVar8 + -1;
          }
        }
        else {
          if (bVar9 != false) {
            bVar11 = bVar11 - 1;
            puVar8 = puVar8 + 1;
          }
          _param_9 = (uint)bVar11;
          bVar9 = (bool)(bVar11 & 1);
          puVar12 = puVar8 + _param_9;
          for (; puVar8 < puVar12; puVar8 = puVar8 + 2) {
            *puVar8 = '\0';
          }
          if (bVar9 != false) {
            puVar8 = puVar8 + -1;
          }
        }
        pbVar13 = pbVar13 + 2;
      }
      goto joined_r0x004bbc07;
    }
    cVar10 = cVar10 + -1;
    while (cVar10 == '\0') {
      bVar11 = *pbVar13;
      if ((bVar11 & 1) == 1) {
        param_4 = (uint)(bVar11 >> 1);
        if (bVar11 >> 1 == 0) {
LAB_004bbe05:
          pbVar13 = pbVar13 + 2;
        }
        else {
          pbVar13 = pbVar13 + 1 + param_4;
        }
      }
      else {
        if ((bVar11 & 0xfe) != 0) goto LAB_004bbe05;
        cVar10 = '\x02';
        pbVar13 = pbVar13 + 1;
      }
    }
    puVar7 = puVar7 + iVar6;
    iVar1 = iVar1 + 1;
    bVar9 = bVar15;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004bbe39
// Address: 004bbe39
// XREFS: None
// [HELPER] s__d__s__hd: "%d %s %hd"
// [HELPER] s__hd: "%hd"
// [HELPER] s__wav: ".wav"
undefined2 * __thiscall FUN_004bbe39(undefined2 *param_1,undefined4 param_2,undefined2 param_3)
{
  short *psVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  
  psVar1 = param_1 + 1;
  iVar8 = 0;
  param_1[6] = param_3;
  *param_1 = 0;
  fscanf(param_2,s__hd,psVar1);
  if (*psVar1 < 1) {
    *(undefined4 *)(param_1 + 2) = 0;
  }
  else {
    uVar3 = calloc((int)*psVar1,0x24);
    *(undefined4 *)(param_1 + 2) = uVar3;
    _param_3 = 0;
    if (0 < *psVar1) {
      do {
        iVar4 = *(int *)(param_1 + 2) + iVar8;
        fscanf(param_2,s__d__s__hd,iVar4 + 0x10,iVar4,iVar4 + 0x14);
        uVar5 = 0xffffffff;
        pcVar7 = (char *)(*(int *)(param_1 + 2) + iVar8);
        pcVar10 = &s__wav;
        do {
          pcVar9 = pcVar10;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar9 = pcVar10 + 1;
          cVar2 = *pcVar10;
          pcVar10 = pcVar9;
        } while (cVar2 != '\0');
        uVar5 = ~uVar5;
        iVar8 = iVar8 + 0x24;
        iVar4 = -1;
        do {
          pcVar10 = pcVar7;
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          pcVar10 = pcVar7 + 1;
          cVar2 = *pcVar7;
          pcVar7 = pcVar10;
        } while (cVar2 != '\0');
        pcVar7 = pcVar9 + -uVar5;
        pcVar10 = pcVar10 + -1;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar10 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar10 = pcVar10 + 1;
        }
        *(undefined4 *)(*(int *)(param_1 + 2) + -0xc + iVar8) = 0;
        _param_3 = _param_3 + 1;
        if ((short)param_1[1] <= _param_3) {
          *(undefined4 *)(param_1 + 4) = 300000;
          return param_1;
        }
      } while( true );
    }
  }
  *(undefined4 *)(param_1 + 4) = 300000;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004bbf26
// Address: 004bbf26
// XREFS: None
void * __thiscall FUN_004bbf26(void *param_1,int param_2,TSound_Driver *param_3)
{
  short *psVar1;
  undefined4 uVar2;
  TDigital *this;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f89b;
  *unaff_FS_OFFSET = &uStack_c;
  rge_read(param_2,(void *)((int)param_1 + 0xc),2);
  rge_read(param_2,param_1,2);
  psVar1 = (short *)((int)param_1 + 2);
  rge_read(param_2,psVar1,2);
  rge_read(param_2,(void *)((int)param_1 + 8),4);
  iVar3 = 0;
  if (*psVar1 < 1) {
    *(undefined4 *)((int)param_1 + 4) = 0;
  }
  else {
    uVar2 = calloc((int)*psVar1,0x24);
    *(undefined4 *)((int)param_1 + 4) = uVar2;
    if (0 < *psVar1) {
      iVar4 = 0;
      do {
        rge_read(param_2,(void *)(*(int *)((int)param_1 + 4) + iVar4),0xd);
        rge_read(param_2,(void *)(*(int *)((int)param_1 + 4) + 0x10 + iVar4),4);
        rge_read(param_2,(void *)(*(int *)((int)param_1 + 4) + 0x14 + iVar4),2);
        this = (TDigital *)operator_new(0x3c);
        uStack_4 = 0;
        if (this == (TDigital *)0x0) {
          uVar2 = 0;
        }
        else {
          uVar2 = TDigital::TDigital(this,param_3,(char *)(*(int *)((int)param_1 + 4) + iVar4),
                                     *(long *)(*(int *)((int)param_1 + 4) + 0x10 + iVar4));
        }
        iVar3 = iVar3 + 1;
        uStack_4 = 0xffffffff;
        *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18 + iVar4) = uVar2;
        *(undefined1 *)(*(int *)((int)param_1 + 4) + 0x1c + iVar4) = 2;
        iVar4 = iVar4 + 0x24;
      } while (iVar3 < *(short *)((int)param_1 + 2));
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004bc062
// Address: 004bc062
// XREFS: None
void __fastcall FUN_004bc062(undefined2 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004bc07f
// Address: 004bc07f
// XREFS: None
void __fastcall FUN_004bc07f(undefined2 *param_1)
{
  TDigital *this;
  int iVar1;
  int iVar2;
  
  *param_1 = 0;
  if (*(int *)(param_1 + 2) != 0) {
    iVar1 = 0;
    if (0 < (short)param_1[1]) {
      iVar2 = 0;
      do {
        *(undefined1 *)(*(int *)(param_1 + 2) + iVar2) = 0;
        this = *(TDigital **)(*(int *)(param_1 + 2) + 0x18 + iVar2);
        if (this != (TDigital *)0x0) {
          TDigital::~TDigital(this);
          operator_delete(this);
          *(undefined4 *)(*(int *)(param_1 + 2) + 0x18 + iVar2) = 0;
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x24;
      } while (iVar1 < (short)param_1[1]);
    }
    free(*(undefined4 *)(param_1 + 2));
    *(undefined4 *)(param_1 + 2) = 0;
    param_1[1] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bc0ef
// Address: 004bc0ef
// XREFS: None
void __thiscall FUN_004bc0ef(void *param_1,int param_2)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  rge_write(param_2,(void *)((int)param_1 + 0xc),2);
  rge_write(param_2,param_1,2);
  rge_write(param_2,(short *)((int)param_1 + 2),2);
  rge_write(param_2,(void *)((int)param_1 + 8),4);
  sVar1 = *(short *)((int)param_1 + 2);
  if ((0 < sVar1) && (iVar2 = 0, 0 < sVar1)) {
    iVar3 = 0;
    do {
      rge_write(param_2,(void *)(*(int *)((int)param_1 + 4) + iVar3),0xd);
      rge_write(param_2,(void *)(*(int *)((int)param_1 + 4) + 0x10 + iVar3),4);
      rge_write(param_2,(void *)(*(int *)((int)param_1 + 4) + 0x14 + iVar3),2);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar2 < *(short *)((int)param_1 + 2));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bc18e
// Address: 004bc18e
// XREFS: None
void __thiscall FUN_004bc18e(int param_1,TSound_Driver *param_2)
{
  TDigital *pTVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f8bb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar3 = 0;
  if (0 < *(short *)(param_1 + 2)) {
    iVar4 = 0;
    do {
      pTVar1 = *(TDigital **)(*(int *)(param_1 + 4) + 0x18 + iVar4);
      if (pTVar1 != (TDigital *)0x0) {
        TDigital::~TDigital(pTVar1);
        operator_delete(pTVar1);
      }
      if (param_2 == (TSound_Driver *)0x0) {
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x18 + iVar4) = 0;
      }
      else {
        pTVar1 = (TDigital *)operator_new(0x3c);
        uStack_4 = 0;
        if (pTVar1 == (TDigital *)0x0) {
          uStack_4 = 0xffffffff;
          *(undefined4 *)(*(int *)(param_1 + 4) + 0x18 + iVar4) = 0;
        }
        else {
          uVar2 = TDigital::TDigital(pTVar1,param_2,(char *)(*(int *)(param_1 + 4) + iVar4),
                                     *(long *)(*(int *)(param_1 + 4) + 0x10 + iVar4));
          uStack_4 = 0xffffffff;
          *(undefined4 *)(*(int *)(param_1 + 4) + 0x18 + iVar4) = uVar2;
        }
      }
      iVar3 = iVar3 + 1;
      *(undefined1 *)(*(int *)(param_1 + 4) + 0x1c + iVar4) = 2;
      iVar4 = iVar4 + 0x24;
    } while (iVar3 < *(short *)(param_1 + 2));
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004bc267
// Address: 004bc267
// XREFS: None
void __thiscall FUN_004bc267(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((0 < *(short *)(param_1 + 2)) && (*(int *)(param_1 + 8) != 0)) &&
     (iVar2 = 0, 0 < *(short *)(param_1 + 2))) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(param_1 + 4) + iVar3;
      if ((*(char *)(iVar1 + 0x1c) == '\x01') &&
         (*(uint *)(param_1 + 8) < (uint)(param_2 - *(int *)(iVar1 + 0x20)))) {
        TDigital::unload(*(TDigital **)(iVar1 + 0x18));
        *(undefined1 *)(*(int *)(param_1 + 4) + 0x1c + iVar3) = 2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar2 < *(short *)(param_1 + 2));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bc2cf
// Address: 004bc2cf
// XREFS: None
void __thiscall FUN_004bc2cf(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004bc2da
// Address: 004bc2da
// XREFS: None
void __fastcall FUN_004bc2da(short *param_1)
{
  *param_1 = *param_1 + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004bc2e4
// Address: 004bc2e4
// XREFS: None
void __fastcall FUN_004bc2e4(RGE_Sound *param_1)
{
  if (0 < param_1->play_at_update_count) {
    RGE_Sound::play(param_1,1);
    param_1->play_at_update_count = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bc307
// Address: 004bc307
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Sound_cpp: "C:\msdev\work\age1_x1\Sound.cpp"
// [HELPER] s__: "}"
// [HELPER] s___s: "{%s"
void __thiscall FUN_004bc307(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  short *psVar5;
  char acStack_100 [256];
  
  if (0 < *(short *)(param_1 + 2)) {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_Sound_cpp,0xdd);
    iVar2 = (iVar2 * 100) / 0x7fff;
    iVar3 = 0;
    if (0 < *(short *)(param_1 + 2)) {
      iVar1 = *(int *)(param_1 + 4);
      psVar5 = (short *)(iVar1 + 0x14);
      while (iVar2 = iVar2 - *psVar5, 0 < iVar2) {
        iVar3 = iVar3 + 1;
        psVar5 = psVar5 + 0x12;
        if (*(short *)(param_1 + 2) <= iVar3) {
          return;
        }
      }
      iVar3 = iVar3 * 0x24;
      if (*(int *)(iVar1 + 0x18 + iVar3) != 0) {
        if (do_draw_log != 0) {
          sprintf(acStack_100,s___s,iVar1 + iVar3);
          if (safe_draw_log == 0) {
            write_draw_log(acStack_100);
          }
          else {
            write_draw_log2(acStack_100);
          }
        }
        if (param_2 == 0) {
          TDigital::play(*(TDigital **)(*(int *)(param_1 + 4) + 0x18 + iVar3));
        }
        else {
          TDigital::add_to_play_list(*(TDigital **)(*(int *)(param_1 + 4) + 0x18 + iVar3));
        }
        if (do_draw_log != 0) {
          if (safe_draw_log == 0) {
            write_draw_log(s__);
          }
          else {
            write_draw_log2(s__);
          }
        }
        *(undefined1 *)(*(int *)(param_1 + 4) + 0x1c + iVar3) = 1;
        iVar2 = debug_timeGetTime_on;
        debug_timeGetTime_on = 0;
        uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Sound_cpp,0x108);
        *(ulong *)(*(int *)(param_1 + 4) + 0x20 + iVar3) = uVar4;
        debug_timeGetTime_on = iVar2;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bc46a
// Address: 004bc46a
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Sound_cpp: "C:\msdev\work\age1_x1\Sound.cpp"
int __fastcall FUN_004bc46a(int param_1)
{
  int iVar1;
  int iVar2;
  short *psVar3;
  
  if (0 < *(short *)(param_1 + 2)) {
    iVar1 = debug_rand(s_C__msdev_work_age1_x1_Sound_cpp,0x11c);
    iVar1 = (iVar1 * 100) / 0x7fff;
    iVar2 = 0;
    if (0 < *(short *)(param_1 + 2)) {
      psVar3 = (short *)(*(int *)(param_1 + 4) + 0x14);
      while (iVar1 = iVar1 - *psVar3, 0 < iVar1) {
        iVar2 = iVar2 + 1;
        psVar3 = psVar3 + 0x12;
        if (*(short *)(param_1 + 2) <= iVar2) {
          return 0;
        }
      }
      iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x18 + iVar2 * 0x24);
      if (iVar1 != 0) {
        return iVar1 + 10;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004bc4e9
// Address: 004bc4e9
// XREFS: None
void __fastcall FUN_004bc4e9(int param_1)
{
  TDigital *this;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((0 < *(short *)(param_1 + 2)) && (iVar2 = 0, 0 < *(short *)(param_1 + 2))) {
    iVar3 = 0;
    do {
      this = *(TDigital **)(*(int *)(param_1 + 4) + 0x18 + iVar3);
      if ((this != (TDigital *)0x0) && (iVar1 = TDigital::is_playing(this), iVar1 != 0)) {
        TDigital::stop(*(TDigital **)(*(int *)(param_1 + 4) + 0x18 + iVar3));
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar2 < *(short *)(param_1 + 2));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bc537
// Address: 004bc537
// XREFS: None
undefined4 __fastcall FUN_004bc537(int param_1)
{
  TDigital *this;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((0 < *(short *)(param_1 + 2)) && (iVar2 = 0, 0 < *(short *)(param_1 + 2))) {
    iVar3 = 0;
    do {
      this = *(TDigital **)(*(int *)(param_1 + 4) + 0x18 + iVar3);
      if (this != (TDigital *)0x0) {
        iVar1 = TDigital::is_playing(this);
        if (iVar1 != 0) {
          return 1;
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar2 < *(short *)(param_1 + 2));
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004bc58c
// Address: 004bc58c
// XREFS: None
TSound_Driver * __fastcall FUN_004bc58c(TSound_Driver *param_1)
{
  TSound_Driver::init_vars(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004bc59c
// Address: 004bc59c
// XREFS: None
TSound_Driver * __thiscall FUN_004bc59c(TSound_Driver *param_1,void *param_2,char *param_3)
{
  TSound_Driver::init_vars(param_1);
  TSound_Driver::init(param_1,param_2,param_3);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004bc5c5
// Address: 004bc5c5
// XREFS: None
void __fastcall FUN_004bc5c5(undefined1 *param_1)
{
  *(undefined4 *)(param_1 + 0x14) = 1;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 0x698) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  param_1[0x1c] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004bc603
// Address: 004bc603
// XREFS: None
uchar __thiscall FUN_004bc603(TSound_Driver *param_1,void *param_2,char *param_3)
{
  IDirectSound **ppIVar1;
  IDirectSoundBuffer **ppIVar2;
  bool bVar3;
  int iVar4;
  IDirectSound *pIVar5;
  long lVar6;
  IDirectSound IVar7;
  IDirectSound *pIStack_a0;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  byte bStack_64;
  undefined4 uStack_60;
  
  pIStack_a0 = (IDirectSound *)0x4bc626;
  TSound_Driver::set_path(param_1,param_3);
  ppIVar1 = &param_1->direct_sound;
  param_1->main_wnd = param_2;
  param_1->ready = '\0';
  pIStack_a0 = (IDirectSound *)ppIVar1;
  iVar4 = _DirectSoundCreate_12(0);
  param_1->dsrval = iVar4;
  if (iVar4 != 0) {
    return '\0';
  }
  pIStack_a0 = *ppIVar1;
  uStack_60 = 0x60;
  (**(code **)((int)*pIStack_a0 + 0x10))();
  bVar3 = false;
  pIVar5 = *ppIVar1;
  IVar7 = *pIVar5;
  if ((bStack_64 & 8) != 0) {
    iVar4 = (**(code **)((int)IVar7 + 0x18))(pIVar5,param_1->main_wnd,2);
    param_1->dsrval = iVar4;
    if (iVar4 == 0) {
      bVar3 = true;
      goto LAB_004bc69f;
    }
    pIVar5 = *ppIVar1;
    IVar7 = *pIVar5;
  }
  lVar6 = (**(code **)((int)IVar7 + 0x18))(pIVar5,param_1->main_wnd,1);
  param_1->dsrval = lVar6;
LAB_004bc69f:
  if (param_1->dsrval != 0) {
    (**(code **)((int)**ppIVar1 + 8))(*ppIVar1);
    *ppIVar1 = (IDirectSound *)0x0;
    return '\0';
  }
  ppIVar2 = &param_1->primary_buffer;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  uStack_7c = 0x14;
  uStack_78 = 1;
  iVar4 = (**(code **)((int)**ppIVar1 + 0xc))(*ppIVar1,&uStack_7c,ppIVar2,0);
  param_1->dsrval = iVar4;
  if (iVar4 == 0) {
    if (bVar3) {
      pIStack_a0 = (IDirectSound *)0x10001;
      lVar6 = (**(code **)((int)**ppIVar2 + 0x38))(*ppIVar2,&pIStack_a0);
      param_1->dsrval = lVar6;
    }
    iVar4 = (**(code **)((int)**ppIVar2 + 0x30))(*ppIVar2,0,0,1);
    param_1->dsrval = iVar4;
    if (iVar4 == 0) {
      param_1->ready = '\x01';
      ds_stream_init(param_1->main_wnd,*ppIVar1,*ppIVar2);
      TSound_Driver::open_mixer(param_1);
      return param_1->ready;
    }
  }
  (**(code **)((int)**ppIVar1 + 8))(*ppIVar1);
  *ppIVar1 = (IDirectSound *)0x0;
  return '\0';
}

// --------------------------------------------------

// Function: FUN_004bc7b4
// Address: 004bc7b4
// XREFS: None
void __fastcall FUN_004bc7b4(TSound_Driver *param_1)
{
  IDirectSoundBuffer *pIVar1;
  IDirectSound *pIVar2;
  
  TSound_Driver::close_mixer(param_1);
  if (param_1->ready != '\0') {
    ds_stream_exit();
    pIVar1 = param_1->primary_buffer;
    if (pIVar1 != (IDirectSoundBuffer *)0x0) {
      (**(code **)((int)*pIVar1 + 0x48))(pIVar1);
      (**(code **)((int)*param_1->primary_buffer + 8))(param_1->primary_buffer);
      param_1->primary_buffer = (IDirectSoundBuffer *)0x0;
    }
    pIVar2 = param_1->direct_sound;
    if (pIVar2 != (IDirectSound *)0x0) {
      (**(code **)((int)*pIVar2 + 8))(pIVar2);
      param_1->direct_sound = (IDirectSound *)0x0;
    }
    param_1->ready = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bc808
// Address: 004bc808
// XREFS: None
void __thiscall FUN_004bc808(int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    *(undefined1 *)(param_1 + 0x1c) = 0;
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = (char *)(param_1 + 0x1c);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bc847
// Address: 004bc847
// XREFS: None
undefined1 __fastcall FUN_004bc847(undefined1 *param_1)
{
  return *param_1;
}

// --------------------------------------------------

// Function: FUN_004bc855
// Address: 004bc855
// XREFS: None
undefined4 __fastcall FUN_004bc855(int param_1)
{
  return *(undefined4 *)(param_1 + 0x18);
}

// --------------------------------------------------

// Function: FUN_004bc864
// Address: 004bc864
// XREFS: None
void __thiscall FUN_004bc864(int param_1,int param_2,int param_3)
{
  undefined4 uVar1;
  
  if (param_3 != 0) {
    *(int *)(param_1 + 0x18) = param_2;
  }
  if (*(int *)(param_1 + 0x120) != 0) {
    *(uint *)(param_1 + 0x294) =
         (uint)((*(int *)(param_1 + 0x250) - *(int *)(param_1 + 0x24c)) * (param_2 + 10000)) / 10000
    ;
    uVar1 = mixerSetControlDetails(*(undefined4 *)(param_1 + 0x124),param_1 + 0x27c,0);
    *(undefined4 *)(param_1 + 0x10) = uVar1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bc8cf
// Address: 004bc8cf
// XREFS: None
// [HELPER] s__s_s: "%s%s"
undefined4 __thiscall
FUN_004bc8cf(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 uVar1;
  undefined1 auStack_104 [260];
  
  if (*param_1 == '\0') {
    return 0;
  }
  sprintf(auStack_104,s__s_s,param_1 + 0x1c,param_2);
  uVar1 = ds_stream_file(auStack_104,param_3,param_4);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_004bc92b
// Address: 004bc92b
// XREFS: None
undefined4 __thiscall FUN_004bc92b(char *param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  if (*param_1 == '\0') {
    return 0;
  }
  uVar1 = ds_stream_volume(param_2);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_004bc94a
// Address: 004bc94a
// XREFS: None
undefined4 __fastcall FUN_004bc94a(char *param_1)
{
  undefined4 uVar1;
  
  if (*param_1 == '\0') {
    return 0;
  }
  uVar1 = ds_stream_pause();
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_004bc95d
// Address: 004bc95d
// XREFS: None
undefined4 __fastcall FUN_004bc95d(char *param_1)
{
  undefined4 uVar1;
  
  if (*param_1 == '\0') {
    return 0;
  }
  uVar1 = ds_stream_resume();
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_004bc96d
// Address: 004bc96d
// XREFS: None
undefined4 __fastcall FUN_004bc96d(char *param_1)
{
  undefined4 uVar1;
  
  if (*param_1 == '\0') {
    return 0;
  }
  uVar1 = ds_stream_stop();
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_004bc97d
// Address: 004bc97d
// XREFS: None
undefined4 __thiscall
FUN_004bc97d(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  undefined4 uVar1;
  
  if (*param_1 == '\0') {
    return 0;
  }
  uVar1 = ds_stream_messages(param_2,param_3,param_4,param_5);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_004bc9a9
// Address: 004bc9a9
// XREFS: None
undefined4 __thiscall FUN_004bc9a9(int param_1,undefined4 param_2)
{
  if ((*(int *)(param_1 + 0x698) != 0xff) && (*(char *)(param_1 + 1) == '\0')) {
    *(undefined4 *)(param_1 + 0x298 + *(int *)(param_1 + 0x698) * 4) = param_2;
    *(int *)(param_1 + 0x698) = *(int *)(param_1 + 0x698) + 1;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004bc9e9
// Address: 004bc9e9
// XREFS: None
void __fastcall FUN_004bc9e9(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x698)) {
    puVar2 = (undefined4 *)(param_1 + 0x298);
    do {
      TDigital::play((TDigital *)*puVar2);
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x698));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bca2b
// Address: 004bca2b
// XREFS: None
undefined4 __fastcall FUN_004bca2b(int param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint unaff_ESI;
  undefined4 *puVar6;
  
  uVar3 = mixerGetNumDevs();
  if ((uVar3 == 0) || (uVar5 = 0, uVar3 == 0)) {
    return 0;
  }
  puVar1 = (undefined4 *)(param_1 + 0x124);
  do {
    iVar4 = mixerOpen(puVar1,uVar5,0,0,0);
    if (iVar4 == 0) {
      puVar2 = (undefined4 *)(param_1 + 0x128);
      puVar6 = puVar2;
      for (iVar4 = 0x2a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *puVar2 = 0xa8;
      *(undefined4 *)(param_1 + 0x140) = 0x1008;
      iVar4 = mixerGetLineInfoA(*puVar1,puVar2,3);
      if (iVar4 == 0) {
        puVar2 = (undefined4 *)(param_1 + 0x1d0);
        puVar6 = puVar2;
        for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        puVar6 = (undefined4 *)(param_1 + 0x1e8);
        for (iVar4 = 0x25; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        *puVar2 = 0x18;
        *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(param_1 + 0x134);
        *(undefined4 *)(param_1 + 0x1d8) = 0x50030001;
        *(undefined4 *)(param_1 + 0x1dc) = 1;
        *(undefined4 *)(param_1 + 0x1e0) = 0x94;
        *(undefined4 **)(param_1 + 0x1e4) = (undefined4 *)(param_1 + 0x1e8);
        iVar4 = mixerGetLineControlsA(*puVar1,puVar2,2);
        uVar5 = unaff_ESI;
        if (iVar4 == 0) {
          puVar2 = (undefined4 *)(param_1 + 0x27c);
          puVar6 = puVar2;
          for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          *(undefined4 *)(param_1 + 0x294) = 0;
          *puVar2 = 0x18;
          *(undefined4 *)(param_1 + 0x280) = *(undefined4 *)(param_1 + 0x1ec);
          *(undefined4 *)(param_1 + 0x284) = 1;
          *(undefined4 *)(param_1 + 0x28c) = 4;
          *(undefined4 **)(param_1 + 0x290) = (undefined4 *)(param_1 + 0x294);
          iVar4 = mixerGetControlDetailsA(*puVar1,puVar2,0);
          if (iVar4 == 0) {
            *(undefined4 *)(param_1 + 0x120) = 1;
            iVar4 = (uint)(*(int *)(param_1 + 0x294) * 10000) /
                    (uint)(*(int *)(param_1 + 0x250) - *(int *)(param_1 + 0x24c)) - 10000;
            *(int *)(param_1 + 0x14) = iVar4;
            *(int *)(param_1 + 0x18) = iVar4;
            return 1;
          }
        }
      }
      mixerClose(*puVar1);
      *puVar1 = 0;
    }
    uVar5 = uVar5 + 1;
    if (uVar3 <= uVar5) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004bcbe6
// Address: 004bcbe6
// XREFS: None
void __fastcall FUN_004bcbe6(TSound_Driver *param_1)
{
  if (param_1->mixer_open != 0) {
    if (param_1->start_volume != 1) {
      TSound_Driver::set_volume(param_1,param_1->start_volume,0);
      param_1->start_volume = 1;
    }
    if (param_1->mixer_handle != (void *)0x0) {
      mixerClose(param_1->mixer_handle);
      param_1->mixer_handle = (void *)0x0;
    }
    param_1->mixer_open = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bcc3b
// Address: 004bcc3b
// XREFS: None
TDigital * __thiscall
FUN_004bcc3b(TDigital *param_1,TSound_Driver *param_2,int param_3,long param_4)
{
  TDigital::init_vars(param_1);
  param_1->sound_system = param_2;
  param_1->resource_id = param_4;
  if (param_3 != 0) {
    strncpy(param_1->sound_file,param_3,0xc);
    param_1->sound_file[0xc] = '\0';
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004bcc76
// Address: 004bcc76
// XREFS: None
TDigital * __thiscall FUN_004bcc76(TDigital *param_1,TDigital *param_2)
{
  TDigital::init_vars(param_1);
  param_1->owner = param_2;
  param_1->volume = param_2->volume;
  param_1->pitch = param_2->pitch;
  param_1->pan = param_2->pan;
  param_1->loop = param_2->loop;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004bccb5
// Address: 004bccb5
// XREFS: None
void __fastcall FUN_004bccb5(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004bcce9
// Address: 004bcce9
// XREFS: None
void __fastcall FUN_004bcce9(TDigital *param_1)
{
  if (param_1->owner != (TDigital *)0x0) {
    TDigital::exit(param_1->owner);
    TDigital::init_vars(param_1);
    return;
  }
  if (param_1->loaded != '\0') {
    TDigital::stop(param_1);
    TDigital::unload(param_1);
    TDigital::init_vars(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bcd26
// Address: 004bcd26
// XREFS: None
// [HELPER] s_RIFF: "RIFF"
// [HELPER] s__s_s: "%s%s"
// [HELPER] sound_file_first: " "
/* WARNING: Type propagation algorithm not settling */

int __thiscall FUN_004bcd26(TDigital *param_1,char *param_2,ulong param_3)
{
  IDirectSoundBuffer **ppIVar1;
  IDirectSound *pIVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  tWAVEFORMATEX *ptVar6;
  uint uVar7;
  uint uVar8;
  uchar *puVar9;
  undefined4 *puVar10;
  uchar *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  uchar *puVar14;
  undefined1 auStack_15c [4];
  uchar auStack_158 [4];
  undefined1 auStack_154 [4];
  undefined1 auStack_150 [4];
  int aiStack_14c [5];
  tWAVEFORMATEX *ptStack_138;
  undefined4 auStack_134 [5];
  ushort uStack_120;
  ushort uStack_11e;
  ulong uStack_11c;
  ulong uStack_118;
  ushort uStack_114;
  ushort uStack_112;
  ulong uStack_10c;
  int iStack_108;
  undefined1 auStack_104 [260];
  
  aiStack_14c[2] = 0;
  aiStack_14c[3] = 0;
  aiStack_14c[4] = 0;
  ptStack_138 = (tWAVEFORMATEX *)0x0;
  aiStack_14c[1] = 0;
  if (param_1->failed != '\0') {
    return 0;
  }
  if (param_1->owner != (TDigital *)0x0) {
    iVar3 = TDigital::load(param_1->owner,param_2,-1);
    return iVar3;
  }
  if (param_1->sound_system == (TSound_Driver *)0x0) {
    return 0;
  }
  color_log(0xba,0xba,1);
  if (param_1->loaded != '\0') {
    TDigital::unload(param_1);
  }
  if (param_2 != (char *)0x0) {
    strncpy(param_1->sound_file,param_2,0xc);
    param_1->sound_file[0xc] = '\0';
  }
  if (param_1->sound_file[0] == '\0') goto LAB_004bd2d5;
  if (0x7fffffff < param_3) {
    param_3 = param_1->resource_id;
  }
  if ((sound_file_first != '\0') || ((int)param_3 < 0)) {
    sprintf(auStack_104,s__s_s,param_1->sound_system->path,param_1->sound_file);
    iVar3 = __open(auStack_104,0,0);
    if (iVar3 != -1) {
      iVar4 = read(iVar3,auStack_134,0x2c);
      if (iVar4 != 0) {
        iVar4 = strncmp(auStack_134,s_RIFF,4);
        if ((iVar4 != 0) || (uStack_120 != 1)) {
          param_1->failed = '\x01';
          close(iVar3);
          goto LAB_004bd2d5;
        }
        param_1->data_size = uStack_10c;
        puVar5 = (uchar *)malloc(uStack_10c);
        param_1->wave_data = puVar5;
        if (puVar5 == (uchar *)0x0) {
          param_1->failed = '\x01';
          close(iVar3);
          goto LAB_004bd2d5;
        }
        iVar4 = read(iVar3,puVar5,param_1->data_size);
        if (iVar4 == 0) {
          param_1->failed = '\x01';
          free(param_1->wave_data);
          param_1->wave_data = (uchar *)0x0;
          close(iVar3);
          goto LAB_004bd2d5;
        }
        close(iVar3);
        ptVar6 = (tWAVEFORMATEX *)malloc(0x12);
        param_1->wave_info = ptVar6;
        if (ptVar6 == (tWAVEFORMATEX *)0x0) {
          param_1->failed = '\x01';
          free(param_1->wave_data);
          param_1->wave_data = (uchar *)0x0;
          goto LAB_004bd2d5;
        }
        ptVar6->wFormatTag = uStack_120;
        ppIVar1 = &param_1->sound_buffer;
        param_1->wave_info->nChannels = uStack_11e;
        param_1->wave_info->nSamplesPerSec = uStack_11c;
        param_1->wave_info->nAvgBytesPerSec = uStack_118;
        param_1->wave_info->nBlockAlign = uStack_114;
        param_1->wave_info->wBitsPerSample = uStack_112;
        param_1->wave_info->cbSize = 0;
        aiStack_14c[3] = param_1->data_size;
        ptStack_138 = param_1->wave_info;
        aiStack_14c[1] = 0x14;
        aiStack_14c[2] = 0xe2;
        aiStack_14c[4] = 0;
        pIVar2 = param_1->sound_system->direct_sound;
        iVar3 = (**(code **)((int)*pIVar2 + 0xc))(pIVar2,aiStack_14c + 1,ppIVar1,0);
        if (iVar3 != 0) {
          param_1->failed = '\x01';
          *ppIVar1 = (IDirectSoundBuffer *)0x0;
          free(param_1->wave_info);
          param_1->wave_info = (tWAVEFORMATEX *)0x0;
          free(param_1->wave_data);
          param_1->wave_data = (uchar *)0x0;
          goto LAB_004bd2d5;
        }
        puVar5 = auStack_158;
        puVar14 = (uchar *)0x0;
        puVar13 = auStack_154;
        puVar12 = auStack_15c;
        iVar3 = (**(code **)((int)**ppIVar1 + 0x2c))(*ppIVar1,0,param_1->data_size,auStack_150);
        if (iVar3 != 0) {
          param_1->failed = '\x01';
          (**(code **)((int)**ppIVar1 + 8))(*ppIVar1);
          *ppIVar1 = (IDirectSoundBuffer *)0x0;
          free(param_1->wave_info);
          param_1->wave_info = (tWAVEFORMATEX *)0x0;
          free(param_1->wave_data);
          param_1->wave_data = (uchar *)0x0;
          goto LAB_004bd2d5;
        }
        puVar9 = param_1->wave_data;
        puVar11 = puVar14;
        for (uVar7 = (uint)puVar12 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)puVar11 = *(undefined4 *)puVar9;
          puVar9 = puVar9 + 4;
          puVar11 = puVar11 + 4;
        }
        for (uVar7 = (uint)puVar12 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        }
        if (puVar13 != (undefined1 *)0x0) {
          puVar9 = puVar12 + (int)param_1->wave_data;
          puVar11 = puVar5;
          for (uVar7 = (uint)puVar13 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined4 *)puVar11 = *(undefined4 *)puVar9;
            puVar9 = puVar9 + 4;
            puVar11 = puVar11 + 4;
          }
          for (uVar7 = (uint)puVar13 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
          }
        }
        (**(code **)((int)**ppIVar1 + 0x4c))(*ppIVar1,puVar14,puVar12,puVar5,puVar13);
        free(param_1->wave_info);
        param_1->wave_info = (tWAVEFORMATEX *)0x0;
        free(param_1->wave_data);
        param_1->wave_data = (uchar *)0x0;
        goto LAB_004bd289;
      }
      param_1->failed = '\x01';
      close(iVar3);
      goto LAB_004bd2d5;
    }
  }
  if (((int)param_3 < 0) ||
     (puVar5 = RESFILE_load(0x77617620,param_3,aiStack_14c,&iStack_108), puVar5 == (uchar *)0x0)) {
    param_1->failed = '\x01';
  }
  else {
    puVar14 = puVar5;
    puVar10 = auStack_134;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar10 = *(undefined4 *)puVar14;
      puVar14 = puVar14 + 4;
      puVar10 = puVar10 + 1;
    }
    param_1->data_size = uStack_10c;
    puVar14 = (uchar *)malloc(uStack_10c);
    param_1->wave_data = puVar14;
    if (puVar14 == (uchar *)0x0) {
      param_1->failed = '\x01';
      if (aiStack_14c[0] == 1) {
        free(puVar5);
      }
    }
    else {
      uVar7 = param_1->data_size;
      puVar9 = puVar5 + 0x2c;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)puVar14 = *(undefined4 *)puVar9;
        puVar9 = puVar9 + 4;
        puVar14 = puVar14 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar14 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar14 = puVar14 + 1;
      }
      if (aiStack_14c[0] == 1) {
        free(puVar5);
      }
      ptVar6 = (tWAVEFORMATEX *)malloc(0x12);
      param_1->wave_info = ptVar6;
      if (ptVar6 == (tWAVEFORMATEX *)0x0) {
        param_1->failed = '\x01';
        if (aiStack_14c[0] == 1) {
          free(puVar5);
        }
      }
      else {
        ptVar6->wFormatTag = uStack_120;
        ppIVar1 = &param_1->sound_buffer;
        param_1->wave_info->nChannels = uStack_11e;
        param_1->wave_info->nSamplesPerSec = uStack_11c;
        param_1->wave_info->nAvgBytesPerSec = uStack_118;
        param_1->wave_info->nBlockAlign = uStack_114;
        param_1->wave_info->wBitsPerSample = uStack_112;
        param_1->wave_info->cbSize = 0;
        aiStack_14c[3] = param_1->data_size;
        ptStack_138 = param_1->wave_info;
        aiStack_14c[4] = 0;
        aiStack_14c[1] = 0x14;
        aiStack_14c[2] = 0xe2;
        pIVar2 = param_1->sound_system->direct_sound;
        iVar3 = (**(code **)((int)*pIVar2 + 0xc))(pIVar2,aiStack_14c + 1,ppIVar1,0);
        if (iVar3 == 0) {
          puVar5 = auStack_158;
          puVar14 = (uchar *)0x0;
          puVar13 = auStack_154;
          puVar12 = auStack_15c;
          iVar3 = (**(code **)((int)**ppIVar1 + 0x2c))(*ppIVar1,0,param_1->data_size,auStack_150);
          if (iVar3 == 0) {
            puVar9 = param_1->wave_data;
            puVar11 = puVar14;
            for (uVar7 = (uint)puVar12 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
              *(undefined4 *)puVar11 = *(undefined4 *)puVar9;
              puVar9 = puVar9 + 4;
              puVar11 = puVar11 + 4;
            }
            for (uVar7 = (uint)puVar12 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
              *puVar11 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar11 = puVar11 + 1;
            }
            if (puVar13 != (undefined1 *)0x0) {
              puVar9 = puVar12 + (int)param_1->wave_data;
              puVar11 = puVar5;
              for (uVar7 = (uint)puVar13 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *(undefined4 *)puVar11 = *(undefined4 *)puVar9;
                puVar9 = puVar9 + 4;
                puVar11 = puVar11 + 4;
              }
              for (uVar7 = (uint)puVar13 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar11 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar11 = puVar11 + 1;
              }
            }
            (**(code **)((int)**ppIVar1 + 0x4c))(*ppIVar1,puVar14,puVar12,puVar5,puVar13);
            free(param_1->wave_info);
            param_1->wave_info = (tWAVEFORMATEX *)0x0;
LAB_004bd289:
            param_1->loaded = '\x01';
            color_log(0xba,'_',1);
            return 1;
          }
          param_1->failed = '\x01';
          (**(code **)((int)**ppIVar1 + 8))(*ppIVar1);
        }
        else {
          param_1->failed = '\x01';
        }
        *ppIVar1 = (IDirectSoundBuffer *)0x0;
        free(param_1->wave_info);
        param_1->wave_info = (tWAVEFORMATEX *)0x0;
      }
    }
  }
LAB_004bd2d5:
  color_log(0xba,'_',1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004bd2f3
// Address: 004bd2f3
// XREFS: None
void __fastcall FUN_004bd2f3(TDigital *param_1)
{
  IDirectSoundBuffer *pIVar1;
  TDigital *pTVar2;
  TDigital *pTVar3;
  
  pTVar3 = param_1->owner;
  while (pTVar2 = pTVar3, pTVar2 != (TDigital *)0x0) {
    param_1 = pTVar2;
    pTVar3 = pTVar2->owner;
  }
  if (param_1->loaded != '\0') {
    TDigital::stop(param_1);
    pIVar1 = param_1->sound_buffer;
    if (pIVar1 != (IDirectSoundBuffer *)0x0) {
      (**(code **)((int)*pIVar1 + 8))(pIVar1);
      param_1->sound_buffer = (IDirectSoundBuffer *)0x0;
    }
    if (param_1->wave_data != (uchar *)0x0) {
      free(param_1->wave_data);
      param_1->wave_data = (uchar *)0x0;
    }
    if (param_1->wave_info != (tWAVEFORMATEX *)0x0) {
      free(param_1->wave_info);
      param_1->wave_info = (tWAVEFORMATEX *)0x0;
    }
    param_1->loaded = '\0';
  }
  param_1->failed = '\0';
  return;
}

// --------------------------------------------------

// Function: FUN_004bd361
// Address: 004bd361
// XREFS: None
IDirectSoundBuffer * __fastcall FUN_004bd361(TDigital *param_1)
{
  TSound_Driver *pTVar1;
  IDirectSoundBuffer *pIVar2;
  int iVar3;
  TDigital *this;
  bool bVar4;
  TDigital *pTStack_4;
  
  this = param_1->owner;
  if (param_1->owner == (TDigital *)0x0) {
    this = param_1;
  }
  pTVar1 = this->sound_system;
  if (((pTVar1 != (TSound_Driver *)0x0) && (pTVar1->ready != '\0')) && (pTVar1->mute == '\0')) {
    pTStack_4 = param_1;
    if (this->loaded == '\0') {
      iVar3 = TDigital::load(this,param_1->sound_file,-1);
      if (iVar3 == 0) {
        return (IDirectSoundBuffer *)0x0;
      }
    }
    pIVar2 = this->sound_buffer;
    if (pIVar2 == (IDirectSoundBuffer *)0x0) {
      this->failed = '\x01';
      return pIVar2;
    }
    (**(code **)((int)*pIVar2 + 0x24))(pIVar2,&pTStack_4);
    bVar4 = this->loop != 0;
    (**(code **)((int)*this->sound_buffer + 0x3c))(this->sound_buffer,param_1->volume);
    (**(code **)((int)*this->sound_buffer + 0x44))(this->sound_buffer,param_1->pitch);
    (**(code **)((int)*this->sound_buffer + 0x40))(this->sound_buffer,param_1->pan);
    (**(code **)((int)*this->sound_buffer + 0x34))(this->sound_buffer,0);
    iVar3 = (**(code **)((int)*this->sound_buffer + 0x30))(this->sound_buffer,0,0,bVar4);
    if (iVar3 == -0x7787ff6a) {
      iVar3 = TDigital::load(this,(char *)0x0,-1);
      if (iVar3 == 0) {
        return (IDirectSoundBuffer *)0x0;
      }
      (**(code **)((int)*this->sound_buffer + 0x3c))(this->sound_buffer,param_1->volume);
      (**(code **)((int)*this->sound_buffer + 0x44))(this->sound_buffer,param_1->pitch);
      (**(code **)((int)*this->sound_buffer + 0x40))(this->sound_buffer,param_1->pan);
      (**(code **)((int)*this->sound_buffer + 0x34))(this->sound_buffer,0);
      (**(code **)((int)*this->sound_buffer + 0x30))(this->sound_buffer,0,0,bVar4);
    }
  }
  return (IDirectSoundBuffer *)0x1;
}

// --------------------------------------------------

// Function: FUN_004bd484
// Address: 004bd484
// XREFS: None
void __fastcall FUN_004bd484(undefined4 *param_1)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1[1];
  while (puVar2 = puVar3, puVar2 != (undefined4 *)0x0) {
    param_1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
  }
  if (((((char *)*param_1 != (char *)0x0) && (*(char *)*param_1 != '\0')) &&
      (*(char *)(param_1 + 2) != '\0')) && (piVar1 = (int *)param_1[0xd], piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x48))(piVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bd4dc
// Address: 004bd4dc
// XREFS: None
void __thiscall FUN_004bd4dc(int param_1,undefined4 param_2)
{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  iVar1 = *(int *)(param_1 + 4);
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = param_1;
  }
  if (*(char *)(iVar1 + 8) != '\0') {
    (**(code **)(**(int **)(iVar1 + 0x34) + 0x3c))(*(int **)(iVar1 + 0x34),param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bd504
// Address: 004bd504
// XREFS: None
void __thiscall FUN_004bd504(int param_1,undefined4 param_2)
{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x20) = param_2;
  iVar1 = *(int *)(param_1 + 4);
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = param_1;
  }
  if (*(char *)(iVar1 + 8) != '\0') {
    (**(code **)(**(int **)(iVar1 + 0x34) + 0x44))(*(int **)(iVar1 + 0x34),param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bd534
// Address: 004bd534
// XREFS: None
void __thiscall FUN_004bd534(int param_1,undefined4 param_2)
{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x24) = param_2;
  iVar1 = *(int *)(param_1 + 4);
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = param_1;
  }
  if (*(char *)(iVar1 + 8) != '\0') {
    (**(code **)(**(int **)(iVar1 + 0x34) + 0x40))(*(int **)(iVar1 + 0x34),param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bd564
// Address: 004bd564
// XREFS: None
undefined4 __fastcall FUN_004bd564(int *param_1)
{
  int *piVar1;
  int iVar2;
  int *piStack_4;
  
  piVar1 = (int *)param_1[1];
  if ((int *)param_1[1] == (int *)0x0) {
    piVar1 = param_1;
  }
  if (((*param_1 != 0) && ((char)piVar1[2] != '\0')) &&
     (piVar1 = (int *)piVar1[0xd], piVar1 != (int *)0x0)) {
    piStack_4 = param_1;
    iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,&piStack_4);
    if ((iVar2 == 0) && ((piVar1 == (int *)0x1 || (piVar1 == (int *)0x4)))) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004bd5b5
// Address: 004bd5b5
// XREFS: None
int __fastcall FUN_004bd5b5(TDigital *param_1)
{
  TSound_Driver *this;
  int iVar1;
  
  this = param_1->sound_system;
  if ((this != (TSound_Driver *)0x0) && (this->mute == '\0')) {
    iVar1 = TSound_Driver::add_to_play_list(this,param_1);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004bd5d9
// Address: 004bd5d9
// XREFS: None
TSpan_Node_List * __thiscall
FUN_004bd5d9(TSpan_Node_List *param_1,int param_2,int param_3,int param_4)
{
  param_1->Free_Pool_Zone = -1;
  param_1->Free_Pool_Index = -1;
  param_1->Zone_Ptrs = (VSpan_Node **)0x0;
  param_1->Zone_Size_Ptrs = (int *)0x0;
  param_1->Used_Zones = 0;
  param_1->Free_Head = (VSpan_Node *)0x0;
  param_1->Total_Blocks = 0;
  param_1->Free_Blocks = 0;
  param_1->Element_Size = param_4;
  param_1->Max_Zones = 8;
  param_1->Default_Grow_Size = param_3;
  TSpan_Node_List::ResetStats(param_1);
  TSpan_Node_List::SetNumZones(param_1,8);
  TSpan_Node_List::InitNewZone(param_1,param_2);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004bd636
// Address: 004bd636
// XREFS: None
void __fastcall FUN_004bd636(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[2]) {
    do {
      iVar1 = *(int *)(*param_1 + iVar2 * 4);
      if (iVar1 != 0) {
        free(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[2]);
  }
  if (*param_1 != 0) {
    free(*param_1);
  }
  if (param_1[1] != 0) {
    free(param_1[1]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bd689
// Address: 004bd689
// XREFS: None
void __thiscall FUN_004bd689(int *param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1[3] <= param_2) {
    iVar3 = calloc(param_2,4);
    iVar4 = calloc(param_2,4);
    if (*param_1 != 0) {
      iVar5 = 0;
      if (0 < param_1[2]) {
        do {
          puVar1 = (undefined4 *)(iVar4 + iVar5 * 4);
          iVar2 = iVar5 * 4;
          iVar5 = iVar5 + 1;
          *(undefined4 *)((iVar3 - iVar4) + (int)puVar1) = *(undefined4 *)(*param_1 + iVar2);
          *puVar1 = *(undefined4 *)(param_1[1] + -4 + iVar5 * 4);
        } while (iVar5 < param_1[2]);
      }
      free(*param_1);
      free(param_1[1]);
    }
    *param_1 = iVar3;
    param_1[1] = iVar4;
    param_1[3] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bd717
// Address: 004bd717
// XREFS: None
void __thiscall FUN_004bd717(TSpan_Node_List *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  VSpan_Node *pVVar3;
  
  if (param_1->Used_Zones == param_1->Max_Zones) {
    TSpan_Node_List::SetNumZones(param_1,param_1->Used_Zones + 4);
  }
  iVar1 = param_1->Used_Zones;
  param_1->Used_Zones = iVar1 + 1;
  iVar2 = param_1->Element_Size;
  param_1->Zone_Size_Ptrs[iVar1] = param_2;
  pVVar3 = (VSpan_Node *)malloc(iVar2 * param_2);
  param_1->Zone_Ptrs[iVar1] = pVVar3;
  param_1->NewZone_Count = param_1->NewZone_Count + 1;
  param_1->Total_Blocks = param_1->Total_Blocks + param_2;
  param_1->Free_Blocks = param_1->Free_Blocks + param_2;
  if (param_1->Free_Pool_Zone == -1) {
    param_1->Free_Pool_Zone = iVar1;
    param_1->Free_Pool_Index = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bd7fd
// Address: 004bd7fd
// XREFS: None
void __thiscall FUN_004bd7fd(int param_1,undefined4 *param_2)
{
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  param_2[1] = 0;
  *(undefined4 **)(param_1 + 0x10) = param_2;
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004bd81d
// Address: 004bd81d
// XREFS: None
int __thiscall FUN_004bd81d(int param_1,int *param_2,int *param_3)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = 0;
  if (param_2 == (int *)0x0) {
    return iVar1;
  }
  piVar3 = param_2;
  if (param_3 == (int *)0x0) {
    do {
      piVar2 = piVar3;
      iVar1 = iVar1 + 1;
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      piVar3 = (int *)*piVar2;
    } while (piVar3 != (int *)0x0);
    *piVar2 = *(int *)(param_1 + 0x10);
    *(int **)(param_1 + 0x10) = param_2;
    return iVar1;
  }
  do {
    iVar1 = iVar1 + 1;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    if (piVar3 == param_3) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)*piVar3;
    }
  } while (piVar3 != (int *)0x0);
  *param_3 = *(int *)(param_1 + 0x10);
  *(int **)(param_1 + 0x10) = param_2;
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_004bd87d
// Address: 004bd87d
// XREFS: None
void __fastcall FUN_004bd87d(int param_1)
{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004bd899
// Address: 004bd899
// XREFS: None
void __fastcall FUN_004bd899(int param_1)
{
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004bd8af
// Address: 004bd8af
// XREFS: None
TSpan_List_Manager * __thiscall FUN_004bd8af(TSpan_List_Manager *param_1,int param_2,int param_3)
{
  VSpan_Node **ppVVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f8d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TSpan_Node_List::TSpan_Node_List
            (&param_1->VSList,
             ((int)(param_2 + 0x1f + (param_2 + 0x1f >> 0x1f & 0x1fU)) >> 5) * param_3,param_3 << 4,
             0x10);
  uStack_4 = 0;
  param_1->Num_Lines = param_3;
  if (param_3 < 0x10) {
    param_1->Num_Lines = 0x10;
  }
  param_1->Num_Pixels = param_2;
  if (param_2 < 0x10) {
    param_1->Num_Pixels = 0x10;
  }
  TSpan_List_Manager::SetSpanRegions(param_1,0,0,param_1->Num_Pixels + -1,param_1->Num_Lines + -1);
  ppVVar1 = (VSpan_Node **)calloc(param_1->Num_Lines,4);
  param_1->Line_Head_Ptrs = ppVVar1;
  ppVVar1 = (VSpan_Node **)calloc(param_1->Num_Lines,4);
  param_1->Line_Tail_Ptrs = ppVVar1;
  piVar2 = (int *)calloc(param_1->Num_Lines,4);
  param_1->LeftMostPx = piVar2;
  piVar2 = (int *)calloc(param_1->Num_Lines,4);
  param_1->RightMostPx = piVar2;
  piVar2 = (int *)calloc(param_1->Num_Lines,4);
  param_1->Span_Count = piVar2;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004bd99a
// Address: 004bd99a
// XREFS: None
void __fastcall FUN_004bd99a(TSpan_Node_List *param_1)
{
  if (param_1[1].Zone_Ptrs != (VSpan_Node **)0x0) {
    free(param_1[1].Zone_Ptrs);
  }
  if (param_1[1].Zone_Size_Ptrs != (int *)0x0) {
    free(param_1[1].Zone_Size_Ptrs);
  }
  if (param_1[1].Used_Zones != 0) {
    free(param_1[1].Used_Zones);
  }
  if (param_1[1].Max_Zones != 0) {
    free(param_1[1].Max_Zones);
  }
  if (param_1[1].Free_Head != (VSpan_Node *)0x0) {
    free(param_1[1].Free_Head);
  }
  TSpan_Node_List::~TSpan_Node_List(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004bd9fc
// Address: 004bd9fc
// XREFS: None
void __thiscall FUN_004bd9fc(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_4;
  if (param_4 < param_2) {
    iVar3 = param_2;
    param_2 = param_4;
  }
  iVar2 = param_3;
  if (param_5 < param_3) {
    iVar2 = param_5;
    param_5 = param_3;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if ((-1 < param_5) && (iVar1 = *(int *)(param_1 + 0x50), iVar2 < iVar1)) {
    if (iVar1 <= param_5) {
      param_5 = iVar1 + -1;
    }
    if (param_2 < 0) {
      param_2 = 0;
    }
    if ((-1 < iVar3) && (iVar1 = *(int *)(param_1 + 0x54), param_2 < iVar1)) {
      if (iVar1 <= iVar3) {
        iVar3 = iVar1 + -1;
      }
      *(int *)(param_1 + 0x60) = iVar2;
      *(int *)(param_1 + 100) = param_5;
      *(int *)(param_1 + 0x58) = param_2;
      *(int *)(param_1 + 0x5c) = iVar3;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bda69
// Address: 004bda69
// XREFS: None
void __fastcall FUN_004bda69(TSpan_Node_List *param_1)
{
  uint uVar1;
  int iVar2;
  VSpan_Node **ppVVar3;
  int *piVar4;
  undefined4 *puVar5;
  VSpan_Node *pVVar6;
  
  TSpan_Node_List::ReclaimAllNodes(param_1);
  ppVVar3 = param_1[1].Zone_Ptrs;
  for (uVar1 = param_1[1].Free_Pool_Zone & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    *ppVVar3 = (VSpan_Node *)0x0;
    ppVVar3 = ppVVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)ppVVar3 = 0;
    ppVVar3 = (VSpan_Node **)((int)ppVVar3 + 1);
  }
  piVar4 = param_1[1].Zone_Size_Ptrs;
  for (uVar1 = param_1[1].Free_Pool_Zone & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)piVar4 = 0;
    piVar4 = (int *)((int)piVar4 + 1);
  }
  puVar5 = (undefined4 *)param_1[1].Used_Zones;
  for (uVar1 = param_1[1].Free_Pool_Zone & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  puVar5 = (undefined4 *)param_1[1].Max_Zones;
  for (uVar1 = param_1[1].Free_Pool_Zone & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  pVVar6 = param_1[1].Free_Head;
  for (uVar1 = param_1[1].Free_Pool_Zone & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    pVVar6->Next = (VSpan_Node *)0x0;
    pVVar6 = (VSpan_Node *)&pVVar6->Prev;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)&pVVar6->Next = 0;
    pVVar6 = (VSpan_Node *)((int)&pVVar6->Next + 1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bdaf9
// Address: 004bdaf9
// XREFS: None
void __thiscall FUN_004bdaf9(TSpan_Node_List *param_1,int param_2,int param_3,int param_4)
{
  VSpan_Node *pVVar1;
  VSpan_Node *pVVar2;
  int iVar3;
  VSpan_Node *pVVar4;
  int *piVar5;
  int iVar6;
  VSpan_Node **ppVVar7;
  
  iVar6 = param_3;
  if ((param_1[1].Default_Grow_Size <= param_4) && (param_4 <= param_1[1].Element_Size)) {
    if (param_3 < param_2) {
      param_3 = param_2;
      param_2 = iVar6;
    }
    iVar6 = param_1[1].Total_Blocks;
    if ((iVar6 <= param_3) && (iVar3 = param_1[1].Free_Blocks, param_2 <= iVar3)) {
      if (param_2 < iVar6) {
        param_2 = iVar6;
      }
      if (iVar3 < param_3) {
        param_3 = iVar3;
      }
      iVar6 = param_4 * 4;
      pVVar1 = param_1[1].Zone_Ptrs[param_4];
      if (pVVar1 == (VSpan_Node *)0x0) {
        pVVar1 = TSpan_Node_List::GetNode(param_1);
        pVVar1->Prev = (VSpan_Node *)0x0;
        pVVar1->Next = (VSpan_Node *)0x0;
        pVVar1->StartPx = param_2;
        pVVar1->EndPx = param_3;
        param_1[1].Zone_Ptrs[param_4] = pVVar1;
        param_1[1].Zone_Size_Ptrs[param_4] = (int)pVVar1;
        *(int *)(param_1[1].Used_Zones + iVar6) = param_2;
        *(int *)(param_1[1].Max_Zones + iVar6) = param_3;
        ppVVar7 = &(param_1[1].Free_Head)->Next + param_4;
        *ppVVar7 = (VSpan_Node *)((int)&(*ppVVar7)->Next + 1);
        return;
      }
      pVVar2 = (VSpan_Node *)param_1[1].Zone_Size_Ptrs[param_4];
      iVar3 = *(int *)(param_1[1].Used_Zones + iVar6);
      if (iVar3 < param_2) {
        piVar5 = (int *)(param_1[1].Max_Zones + iVar6);
        iVar3 = *piVar5;
        if (param_3 < iVar3) {
          iVar6 = pVVar1->EndPx;
          while (iVar6 < param_2 + -1) {
            pVVar1 = pVVar1->Next;
            iVar6 = pVVar1->EndPx;
          }
          if (param_3 + 1 < pVVar1->StartPx) {
            pVVar4 = TSpan_Node_List::GetNode(param_1);
            pVVar2 = pVVar1->Prev;
            pVVar4->Next = pVVar1;
            pVVar4->Prev = pVVar2;
            pVVar1->Prev = pVVar4;
            pVVar4->Prev->Next = pVVar4;
            pVVar4->StartPx = param_2;
            pVVar4->EndPx = param_3;
            ppVVar7 = &(param_1[1].Free_Head)->Next + param_4;
            *ppVVar7 = (VSpan_Node *)((int)&(*ppVVar7)->Next + 1);
            return;
          }
          if (param_2 < pVVar1->StartPx) {
            pVVar1->StartPx = param_2;
          }
          if ((pVVar1->EndPx < param_3) &&
             (pVVar2 = pVVar1->Next, pVVar1->Next != (VSpan_Node *)0x0)) {
            while( true ) {
              if (param_3 + 1 < pVVar2->StartPx) {
                pVVar1->EndPx = param_3;
                return;
              }
              if (param_3 <= pVVar2->EndPx) break;
              if (pVVar2->Prev != (VSpan_Node *)0x0) {
                pVVar2->Prev->Next = pVVar2->Next;
              }
              if (pVVar2->Next != (VSpan_Node *)0x0) {
                pVVar2->Next->Prev = pVVar2->Prev;
              }
              pVVar4 = pVVar2->Next;
              TSpan_Node_List::FreeNode(param_1,pVVar2);
              ppVVar7 = &(param_1[1].Free_Head)->Next + param_4;
              *ppVVar7 = (VSpan_Node *)((int)&(*ppVVar7)[-1].EndPx + 3);
              pVVar2 = pVVar4;
              if (pVVar4 == (VSpan_Node *)0x0) {
                return;
              }
            }
            pVVar1->EndPx = pVVar2->EndPx;
            pVVar1->Next = pVVar2->Next;
            TSpan_Node_List::FreeNode(param_1,pVVar2);
            ppVVar7 = &(param_1[1].Free_Head)->Next + param_4;
            *ppVVar7 = (VSpan_Node *)((int)&(*ppVVar7)[-1].EndPx + 3);
            if (pVVar1->Next != (VSpan_Node *)0x0) {
              pVVar1->Next->Prev = pVVar1;
              return;
            }
            param_1[1].Zone_Size_Ptrs[param_4] = (int)pVVar1;
          }
        }
        else {
          if (iVar3 + 1 < param_2) {
            pVVar1 = TSpan_Node_List::GetNode(param_1);
            pVVar1->Prev = pVVar2;
            pVVar1->Next = (VSpan_Node *)0x0;
            pVVar2->Next = pVVar1;
            pVVar1->StartPx = param_2;
            pVVar1->EndPx = param_3;
            *(int *)(param_1[1].Max_Zones + iVar6) = param_3;
            param_1[1].Zone_Size_Ptrs[param_4] = (int)pVVar1;
            ppVVar7 = &(param_1[1].Free_Head)->Next + param_4;
            *ppVVar7 = (VSpan_Node *)((int)&(*ppVVar7)->Next + 1);
            return;
          }
          *piVar5 = param_3;
          iVar6 = param_2 + -1;
          if (iVar6 <= pVVar2->EndPx) {
            while( true ) {
              if (pVVar2->StartPx <= param_2) {
                pVVar2->EndPx = param_3;
                return;
              }
              pVVar1 = pVVar2->Prev;
              if (pVVar1->EndPx < iVar6) break;
              param_1[1].Zone_Size_Ptrs[param_4] = (int)pVVar1;
              pVVar1->Next = (VSpan_Node *)0x0;
              TSpan_Node_List::FreeNode(param_1,pVVar2);
              (&(param_1[1].Free_Head)->Next)[param_4] =
                   (VSpan_Node *)((int)&(&(param_1[1].Free_Head)->Next)[param_4][-1].EndPx + 3);
              pVVar2 = pVVar1;
              if (pVVar1->EndPx < iVar6) {
                return;
              }
            }
            pVVar2->StartPx = param_2;
            pVVar2->EndPx = param_3;
            return;
          }
        }
      }
      else {
        if (param_3 < iVar3 + -1) {
          pVVar2 = TSpan_Node_List::GetNode(param_1);
          pVVar2->Prev = (VSpan_Node *)0x0;
          pVVar2->Next = pVVar1;
          pVVar1->Prev = pVVar2;
          pVVar2->StartPx = param_2;
          pVVar2->EndPx = param_3;
          *(int *)(param_1[1].Used_Zones + iVar6) = param_2;
          param_1[1].Zone_Ptrs[param_4] = pVVar2;
          ppVVar7 = &(param_1[1].Free_Head)->Next + param_4;
          *ppVVar7 = (VSpan_Node *)((int)&(*ppVVar7)->Next + 1);
          return;
        }
        if (*(int *)(param_1[1].Max_Zones + iVar6) <= param_3) {
          ppVVar7 = &(param_1[1].Free_Head)->Next + param_4;
          iVar3 = TSpan_Node_List::FreeThread(param_1,pVVar1->Next,(VSpan_Node *)0x0);
          *ppVVar7 = (VSpan_Node *)((int)*ppVVar7 - iVar3);
          pVVar1->Prev = (VSpan_Node *)0x0;
          pVVar1->Next = (VSpan_Node *)0x0;
          pVVar1->StartPx = param_2;
          pVVar1->EndPx = param_3;
          param_1[1].Zone_Size_Ptrs[param_4] = (int)pVVar1;
          *(int *)(param_1[1].Max_Zones + iVar6) = param_3;
          *(int *)(param_1[1].Used_Zones + iVar6) = param_2;
          return;
        }
        *(int *)(param_1[1].Used_Zones + iVar6) = param_2;
        iVar6 = param_3 + 1;
        if (pVVar1->StartPx <= iVar6) {
          while( true ) {
            if (param_3 <= pVVar1->EndPx) {
              pVVar1->StartPx = param_2;
              return;
            }
            pVVar2 = pVVar1->Next;
            if (iVar6 < pVVar2->StartPx) break;
            param_1[1].Zone_Ptrs[param_4] = pVVar2;
            pVVar2->Prev = (VSpan_Node *)0x0;
            TSpan_Node_List::FreeNode(param_1,pVVar1);
            ppVVar7 = &(param_1[1].Free_Head)->Next + param_4;
            *ppVVar7 = (VSpan_Node *)((int)&(*ppVVar7)[-1].EndPx + 3);
            pVVar1 = pVVar2;
            if (iVar6 < pVVar2->StartPx) {
              return;
            }
          }
          pVVar1->StartPx = param_2;
          pVVar1->EndPx = param_3;
          return;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bde94
// Address: 004bde94
// XREFS: None
void __thiscall
FUN_004bde94(TSpan_List_Manager *param_1,int param_2,int param_3,int param_4,int param_5,int param_6
            )
{
  ushort *puVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  
  if ((param_2 != 0) && (*(int *)(param_2 + 0x18) != 0)) {
    iVar5 = *(int *)(param_2 + 0x1c) + param_3 * 0x20;
    puVar6 = (ushort *)(*(int *)(iVar5 + 4) + *(int *)(param_2 + 0x18));
    iVar2 = *(int *)(iVar5 + 0x10) + -1 + param_4;
    if (param_6 == 0) {
      iVar4 = param_5;
      if (param_5 < param_5 + *(int *)(iVar5 + 0x14)) {
        do {
          uVar3 = *puVar6;
          puVar1 = puVar6 + 1;
          puVar6 = puVar6 + 2;
          if (((param_1->Min_Line <= iVar4) && (iVar4 <= param_1->Max_Line)) &&
             ((uVar3 & 0x8000) == 0)) {
            TSpan_List_Manager::AddSpan(param_1,(short)uVar3 + param_4,iVar2 - (short)*puVar1,iVar4)
            ;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_5 + *(int *)(iVar5 + 0x14));
        return;
      }
    }
    else {
      iVar4 = param_5;
      if (param_5 < param_5 + *(int *)(iVar5 + 0x14)) {
        do {
          uVar3 = *puVar6;
          puVar1 = puVar6 + 1;
          puVar6 = puVar6 + 2;
          if (((param_1->Min_Line <= iVar4) && (iVar4 <= param_1->Max_Line)) &&
             ((*puVar1 & 0x8000) == 0)) {
            TSpan_List_Manager::AddSpan(param_1,(short)*puVar1 + param_4,iVar2 - (short)uVar3,iVar4)
            ;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_5 + *(int *)(iVar5 + 0x14));
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bdf9e
// Address: 004bdf9e
// XREFS: None
void __thiscall
FUN_004bdf9e(TSpan_List_Manager *param_1,int param_2,int param_3,int param_4,int param_5,int param_6
            )
{
  ushort *puVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  
  if (param_3 != 0) {
    puVar5 = (ushort *)(*(int *)(param_3 + 4) + param_2);
    iVar2 = *(int *)(param_3 + 0x10) + -1 + param_4;
    if (param_6 == 0) {
      iVar4 = param_5;
      if (param_5 < param_5 + *(int *)(param_3 + 0x14)) {
        do {
          uVar3 = *puVar5;
          puVar1 = puVar5 + 1;
          puVar5 = puVar5 + 2;
          if (((param_1->Min_Line <= iVar4) && (iVar4 <= param_1->Max_Line)) &&
             ((uVar3 & 0x8000) == 0)) {
            TSpan_List_Manager::AddSpan
                      (param_1,(short)uVar3 + param_4 & 0xfffffffc,iVar2 - (short)*puVar1 | 3,iVar4)
            ;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_5 + *(int *)(param_3 + 0x14));
        return;
      }
    }
    else {
      iVar4 = param_5;
      if (param_5 < param_5 + *(int *)(param_3 + 0x14)) {
        do {
          uVar3 = *puVar5;
          puVar1 = puVar5 + 1;
          puVar5 = puVar5 + 2;
          if (((param_1->Min_Line <= iVar4) && (iVar4 <= param_1->Max_Line)) &&
             ((*puVar1 & 0x8000) == 0)) {
            TSpan_List_Manager::AddSpan
                      (param_1,(short)*puVar1 + param_4 & 0xfffffffc,iVar2 - (short)uVar3 | 3,iVar4)
            ;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_5 + *(int *)(param_3 + 0x14));
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004be08f
// Address: 004be08f
// XREFS: None
void __thiscall
FUN_004be08f(TSpan_List_Manager *param_1,uint param_2,int param_3,uint param_4,int param_5)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = param_4;
  if (param_2 == param_4) {
    iVar5 = param_5;
    if (param_5 < param_3) {
      iVar5 = param_3;
      param_3 = param_5;
    }
    for (; param_3 <= iVar5; param_3 = param_3 + 1) {
      TSpan_List_Manager::AddSpan(param_1,param_2 & 0xfffffffc,param_2 | 3,param_3);
    }
  }
  else {
    if (param_3 == param_5) {
      TSpan_List_Manager::AddSpan(param_1,param_2 & 0xfffffffc,param_4 | 3,param_3);
      return;
    }
    iVar5 = param_3;
    iVar3 = param_5;
    if ((int)param_4 < (int)param_2) {
      param_4 = param_2;
      param_2 = uVar1;
      iVar5 = param_5;
      iVar3 = param_3;
    }
    iVar4 = (param_4 - param_2) + 1;
    if (iVar5 < iVar3) {
      param_5 = 1;
      iVar2 = iVar3 - iVar5;
    }
    else {
      iVar2 = iVar5 - iVar3;
      param_5 = -1;
    }
    iVar2 = iVar2 + 1;
    if (iVar2 <= iVar4) {
      iVar3 = 0;
      uVar1 = param_2;
      for (; (int)param_2 < (int)param_4; param_2 = param_2 + 1) {
        iVar3 = iVar3 + iVar2;
        if (iVar4 <= iVar3) {
          TSpan_List_Manager::AddSpan(param_1,uVar1 & 0xfffffffc,param_2 | 3,iVar5);
          iVar5 = iVar5 + param_5;
          iVar3 = iVar3 - iVar4;
          uVar1 = param_2 + 1;
        }
      }
      TSpan_List_Manager::AddSpan(param_1,uVar1 & 0xfffffffc,param_2 | 3,iVar5);
      return;
    }
    param_4 = 0;
    for (; TSpan_List_Manager::AddSpan(param_1,param_2 & 0xfffffffc,param_2 | 3,iVar5),
        iVar5 != iVar3; iVar5 = iVar5 + param_5) {
      param_4 = param_4 + iVar4;
      if (iVar2 <= (int)param_4) {
        param_2 = param_2 + 1;
        param_4 = param_4 - iVar2;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004be1e1
// Address: 004be1e1
// XREFS: None
void __thiscall FUN_004be1e1(TSpan_List_Manager *param_1,byte *param_2,int param_3,int param_4)
{
  if (param_2 != (byte *)0x0) {
    do {
      if (*param_2 == 0xff) {
        return;
      }
      TSpan_List_Manager::AddSpan
                (param_1,(uint)param_2[1] + param_3,(uint)param_2[2] + param_3,
                 (uint)*param_2 + param_4);
      param_2 = param_2 + 3;
    } while (param_2 != (byte *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004be237
// Address: 004be237
// XREFS: None
void __thiscall FUN_004be237(TSpan_List_Manager *param_1,byte *param_2,int param_3,int param_4)
{
  if (param_2 != (byte *)0x0) {
    do {
      if (*param_2 == 0xff) {
        return;
      }
      TSpan_List_Manager::DeleteSpan
                (param_1,(uint)param_2[1] + param_3,(uint)param_2[2] + param_3,
                 (uint)*param_2 + param_4);
      param_2 = param_2 + 3;
    } while (param_2 != (byte *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004be287
// Address: 004be287
// XREFS: None
void __thiscall FUN_004be287(TSpan_Node_List *param_1,int param_2,int param_3,VSpan_Node *param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  VSpan_Node *pVVar5;
  VSpan_Node **ppVVar6;
  VSpan_Node *pVVar7;
  VSpan_Node *pVVar8;
  VSpan_Node *pVStack_4;
  
  iVar4 = (int)param_4;
  iVar1 = param_3;
  if ((param_1[1].Default_Grow_Size <= (int)param_4) && ((int)param_4 <= param_1[1].Element_Size)) {
    if (param_3 < param_2) {
      param_3 = param_2;
      param_2 = iVar1;
    }
    iVar1 = param_1[1].Total_Blocks;
    if ((iVar1 <= param_3) && (iVar2 = param_1[1].Free_Blocks, param_2 <= iVar2)) {
      if (param_2 < iVar1) {
        param_2 = iVar1;
      }
      if (iVar2 < param_3) {
        param_3 = iVar2;
      }
      iVar1 = (int)param_4 * 4;
      pVVar5 = param_1[1].Zone_Ptrs[(int)param_4];
      if (((pVVar5 != (VSpan_Node *)0x0) &&
          (iVar2 = *(int *)(iVar1 + param_1[1].Used_Zones), iVar2 <= param_3)) &&
         (iVar3 = *(int *)(iVar1 + param_1[1].Max_Zones), param_2 <= iVar3)) {
        if ((param_2 <= iVar2) && (iVar3 <= param_3)) {
          TSpan_Node_List::FreeThread
                    (param_1,pVVar5,(VSpan_Node *)param_1[1].Zone_Size_Ptrs[(int)param_4]);
          param_1[1].Zone_Ptrs[(int)param_4] = (VSpan_Node *)0x0;
          param_1[1].Zone_Size_Ptrs[(int)param_4] = 0;
          (&(param_1[1].Free_Head)->Next)[(int)param_4] = (VSpan_Node *)0x0;
          *(undefined4 *)(iVar1 + param_1[1].Used_Zones) = 0;
          *(undefined4 *)(iVar1 + param_1[1].Max_Zones) = 0;
          return;
        }
        pVVar8 = (VSpan_Node *)param_1[1].Zone_Size_Ptrs[(int)param_4];
        iVar2 = pVVar5->EndPx;
        pVVar7 = pVVar5;
        while (iVar2 < param_2) {
          pVVar7 = pVVar7->Next;
          iVar2 = pVVar7->EndPx;
        }
        if (pVVar7->StartPx < param_2) {
          if (param_3 < pVVar7->EndPx) {
            pVVar5 = TSpan_Node_List::GetNode(param_1);
            pVVar5->Prev = pVVar7;
            pVVar5->Next = pVVar7->Next;
            pVVar7->Next = pVVar5;
            if (pVVar5->Next != (VSpan_Node *)0x0) {
              pVVar5->Next->Prev = pVVar5;
            }
            if (pVVar7 == pVVar8) {
              param_1[1].Zone_Size_Ptrs[(int)param_4] = (int)pVVar5;
            }
            pVVar5->StartPx = param_3 + 1;
            pVVar5->EndPx = pVVar7->EndPx;
            pVVar7->EndPx = param_2 + -1;
            ppVVar6 = &(param_1[1].Free_Head)->Next + (int)param_4;
            *ppVVar6 = (VSpan_Node *)((int)&(*ppVVar6)->Next + 1);
            return;
          }
          if (pVVar7->StartPx < param_2) {
            pVVar7->EndPx = param_2 + -1;
            pVVar7 = pVVar7->Next;
          }
        }
        param_4 = pVVar8;
        pVStack_4 = pVVar5;
        if (pVVar7 != (VSpan_Node *)0x0) {
          do {
            if ((pVVar7->StartPx < param_2) || (param_3 < pVVar7->EndPx)) {
              pVVar8 = (VSpan_Node *)0x0;
            }
            else {
              if (pVVar7 == pVVar5) {
                pVStack_4 = pVVar7->Next;
              }
              if (pVVar7 == param_4) {
                param_4 = pVVar7->Prev;
              }
              if (pVVar7->Prev != (VSpan_Node *)0x0) {
                pVVar7->Prev->Next = pVVar7->Next;
              }
              if (pVVar7->Next != (VSpan_Node *)0x0) {
                pVVar7->Next->Prev = pVVar7->Prev;
              }
              pVVar8 = pVVar7->Next;
              TSpan_Node_List::FreeNode(param_1,pVVar7);
              ppVVar6 = &(param_1[1].Free_Head)->Next + iVar4;
              *ppVVar6 = (VSpan_Node *)((int)&(*ppVVar6)[-1].EndPx + 3);
              pVVar5 = pVStack_4;
              pVVar7 = pVVar8;
            }
          } while (pVVar8 != (VSpan_Node *)0x0);
          if ((pVVar7 != (VSpan_Node *)0x0) && (pVVar7->StartPx <= param_3)) {
            pVVar7->StartPx = param_3 + 1;
          }
        }
        param_1[1].Zone_Ptrs[iVar4] = pVVar5;
        param_1[1].Zone_Size_Ptrs[iVar4] = (int)param_4;
        *(int *)(iVar1 + param_1[1].Used_Zones) = pVVar5->StartPx;
        *(int *)(iVar1 + param_1[1].Max_Zones) = param_4->EndPx;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004be4a3
// Address: 004be4a3
// XREFS: None
void __thiscall
FUN_004be4a3(TSpan_List_Manager *param_1,int param_2,int param_3,int param_4,int param_5,int param_6
            )
{
  ushort *puVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  
  if ((param_2 != 0) && (*(int *)(param_2 + 0x18) != 0)) {
    iVar4 = param_3 * 0x20 + *(int *)(param_2 + 0x1c);
    puVar5 = (ushort *)(*(int *)(iVar4 + 4) + *(int *)(param_2 + 0x18));
    iVar2 = *(int *)(iVar4 + 0x10) + -1 + param_4;
    if (param_6 == 0) {
      iVar6 = param_5;
      if (param_5 < param_5 + *(int *)(iVar4 + 0x14)) {
        do {
          uVar3 = *puVar5;
          puVar1 = puVar5 + 1;
          puVar5 = puVar5 + 2;
          if ((uVar3 & 0x8000) == 0) {
            TSpan_List_Manager::DeleteSpan
                      (param_1,param_4 + (short)uVar3,iVar2 - (short)*puVar1,iVar6);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_5 + *(int *)(iVar4 + 0x14));
        return;
      }
    }
    else {
      iVar6 = param_5;
      if (param_5 < param_5 + *(int *)(iVar4 + 0x14)) {
        do {
          uVar3 = *puVar5;
          puVar1 = puVar5 + 1;
          puVar5 = puVar5 + 2;
          if ((*puVar1 & 0x8000) == 0) {
            TSpan_List_Manager::DeleteSpan
                      (param_1,param_4 + (short)*puVar1,iVar2 - (short)uVar3,iVar6);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_5 + *(int *)(iVar4 + 0x14));
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004be5a4
// Address: 004be5a4
// XREFS: None
int __thiscall FUN_004be5a4(int param_1,int param_2,int param_3)
{
  int *piVar1;
  
  if (((-1 < param_3) && (param_3 < *(int *)(param_1 + 0x50))) &&
     (piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + param_3 * 4), piVar1 != (int *)0x0)) {
    while ((param_2 < piVar1[2] || (piVar1[3] < param_2))) {
      piVar1 = (int *)*piVar1;
      if (piVar1 == (int *)0x0) {
        return (int)piVar1;
      }
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004be5eb
// Address: 004be5eb
// XREFS: None
void __thiscall FUN_004be5eb(TSpan_List_Manager *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  TSpan_List_Manager::ResetAll(param_1);
  iVar1 = param_1->Num_Lines;
  if ((((iVar1 != *(int *)(param_2 + 0x50)) || (iVar1 != *(int *)(param_3 + 0x50))) ||
      (param_1->Num_Pixels != *(int *)(param_2 + 0x54))) ||
     ((param_1->Num_Pixels != *(int *)(param_3 + 0x54) || (iVar2 = 0, iVar1 < 1)))) {
    return;
  }
LAB_004be62f:
  puVar4 = *(undefined4 **)(*(int *)(param_2 + 0x3c) + iVar2 * 4);
  puVar3 = *(undefined4 **)(*(int *)(param_3 + 0x3c) + iVar2 * 4);
LAB_004be63b:
  if (puVar4 == (undefined4 *)0x0) {
    if (puVar3 == (undefined4 *)0x0) goto LAB_004be67c;
  }
  else {
    TSpan_List_Manager::AddSpan(param_1,puVar4[2] & 0xfffffffc,puVar4[3] | 3,iVar2);
    puVar4 = (undefined4 *)*puVar4;
  }
  if (puVar3 != (undefined4 *)0x0) {
    TSpan_List_Manager::AddSpan(param_1,puVar3[2] & 0xfffffffc,puVar3[3] | 3,iVar2);
    puVar3 = (undefined4 *)*puVar3;
  }
  goto LAB_004be63b;
LAB_004be67c:
  iVar2 = iVar2 + 1;
  if (param_1->Num_Lines <= iVar2) {
    return;
  }
  goto LAB_004be62f;
}

// --------------------------------------------------

// Function: FUN_004be68b
// Address: 004be68b
// XREFS: None
void __fastcall FUN_004be68b(TSpan_Node_List *param_1)
{
  VSpan_Node *pVVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  VSpan_Node *pVVar5;
  
  iVar3 = 0;
  if (0 < param_1[1].Free_Pool_Zone) {
    do {
      pVVar5 = param_1[1].Zone_Ptrs[iVar3];
      while (pVVar5 != (VSpan_Node *)0x0) {
        pVVar1 = pVVar5->Next;
        pVVar5->StartPx = pVVar5->StartPx & 0xfffffffc;
        uVar2 = pVVar5->EndPx | 3;
        pVVar5->EndPx = uVar2;
        if (pVVar1 == (VSpan_Node *)0x0) {
          pVVar5 = (VSpan_Node *)0x0;
        }
        else if ((int)uVar2 < (int)((pVVar1->StartPx & 0x7ffffffcU) - 1)) {
          pVVar5 = pVVar5->Next;
        }
        else {
          pVVar5->EndPx = pVVar1->EndPx | 3;
          pVVar5->Next = pVVar1->Next;
          if (pVVar1 == (VSpan_Node *)param_1[1].Zone_Size_Ptrs[iVar3]) {
            param_1[1].Zone_Size_Ptrs[iVar3] = (int)pVVar5;
          }
          if (pVVar1->Next != (VSpan_Node *)0x0) {
            pVVar1->Next->Prev = pVVar5;
          }
          TSpan_Node_List::FreeNode(param_1,pVVar1);
          (&(param_1[1].Free_Head)->Next)[iVar3] =
               (VSpan_Node *)((int)&(&(param_1[1].Free_Head)->Next)[iVar3][-1].EndPx + 3);
        }
      }
      iVar4 = iVar3 + 1;
      *(int *)(param_1[1].Used_Zones + -4 + iVar4 * 4) = param_1[1].Zone_Ptrs[iVar3]->StartPx;
      *(undefined4 *)(param_1[1].Max_Zones + -4 + iVar4 * 4) =
           *(undefined4 *)(param_1[1].Zone_Size_Ptrs[iVar3] + 0xc);
      iVar3 = iVar4;
    } while (iVar4 < param_1[1].Free_Pool_Zone);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004be74e
// Address: 004be74e
// XREFS: None
void __thiscall FUN_004be74e(TSpan_List_Manager *param_1,uint param_2,int param_3)
{
  VSpan_Node *pVVar1;
  VSpan_Node *pVVar2;
  int iVar3;
  int iVar4;
  VSpan_Node *pVVar5;
  int iVar6;
  int iVar7;
  int iStack_4;
  
  if (param_2 != 0) {
    if ((param_3 != 0) &&
       (param_1->Max_Span_Px - param_1->Min_Span_Px <
        (int)((param_2 ^ (int)param_2 >> 0x1f) - ((int)param_2 >> 0x1f)))) {
      TSpan_List_Manager::ResetAll(param_1);
      return;
    }
    iStack_4 = 0;
    if (0 < param_1->Num_Lines) {
      do {
        pVVar1 = param_1->Line_Head_Ptrs[iStack_4];
        while (pVVar5 = pVVar1, pVVar5 != (VSpan_Node *)0x0) {
          pVVar1 = pVVar5->Next;
          iVar7 = pVVar5->StartPx + param_2;
          iVar6 = pVVar5->EndPx + param_2;
          pVVar2 = pVVar5->Prev;
          if (param_3 != 0) {
            iVar3 = param_1->Min_Span_Px;
            if ((iVar6 < iVar3) || (iVar4 = param_1->Max_Span_Px, iVar4 < iVar7)) {
              if (pVVar2 != (VSpan_Node *)0x0) {
                pVVar2->Next = pVVar1;
              }
              if (pVVar1 != (VSpan_Node *)0x0) {
                pVVar1->Prev = pVVar2;
              }
              TSpan_Node_List::FreeNode(&param_1->VSList,pVVar5);
              param_1->Span_Count[iStack_4] = param_1->Span_Count[iStack_4] + -1;
              pVVar5 = (VSpan_Node *)0x0;
            }
            else {
              if (iVar7 < iVar3) {
                iVar7 = iVar3;
              }
              if (iVar4 < iVar6) {
                iVar6 = iVar4;
              }
            }
          }
          if (pVVar5 != (VSpan_Node *)0x0) {
            pVVar5->StartPx = iVar7;
            pVVar5->EndPx = iVar6;
          }
        }
        iStack_4 = iStack_4 + 1;
      } while (iStack_4 < param_1->Num_Lines);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004be842
// Address: 004be842
// XREFS: None
void __thiscall FUN_004be842(TSpan_List_Manager *param_1,uint param_2,int param_3)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar2 = param_2;
  iVar6 = 0;
  if (param_2 != 0) {
    if (param_3 == 0) {
      param_2 = 0;
      param_3 = param_1->Num_Lines + -1;
    }
    else {
      param_2 = param_1->Min_Line;
      param_3 = param_1->Max_Line;
    }
    if ((int)(param_3 - param_2) < (int)((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f))) {
      TSpan_List_Manager::ResetAll(param_1);
      return;
    }
    uVar4 = uVar2;
    if (0 < param_1->Num_Lines) {
      do {
        if ((param_1->Line_Head_Ptrs[iVar6] != (VSpan_Node *)0x0) &&
           (((int)uVar4 < (int)param_2 || (param_3 < (int)uVar4)))) {
          TSpan_Node_List::FreeThread
                    (&param_1->VSList,param_1->Line_Head_Ptrs[iVar6],param_1->Line_Tail_Ptrs[iVar6])
          ;
          param_1->Line_Head_Ptrs[iVar6] = (VSpan_Node *)0x0;
          param_1->Line_Tail_Ptrs[iVar6] = (VSpan_Node *)0x0;
          param_1->Span_Count[iVar6] = 0;
          param_1->LeftMostPx[iVar6] = 0;
          param_1->RightMostPx[iVar6] = 0;
        }
        iVar6 = iVar6 + 1;
        uVar4 = uVar4 + 1;
      } while (iVar6 < param_1->Num_Lines);
    }
    if ((int)uVar2 < 1) {
      iVar6 = param_1->Num_Lines;
      iVar7 = 1;
      param_2 = iVar6 - uVar2;
      iVar5 = iVar6 + -1;
      uVar4 = uVar2;
    }
    else {
      iVar5 = 0;
      iVar7 = -1;
      param_2 = 0;
      iVar6 = uVar2 - 1;
      uVar4 = (param_1->Num_Lines - uVar2) - 1;
    }
    if (uVar4 != iVar5 + iVar7) {
      iVar3 = (uVar4 + uVar2) * 4;
      do {
        *(VSpan_Node **)(iVar3 + (int)param_1->Line_Head_Ptrs) = param_1->Line_Head_Ptrs[uVar4];
        *(VSpan_Node **)(iVar3 + (int)param_1->Line_Tail_Ptrs) = param_1->Line_Tail_Ptrs[uVar4];
        *(int *)(iVar3 + (int)param_1->Span_Count) = param_1->Span_Count[uVar4];
        *(int *)(iVar3 + (int)param_1->LeftMostPx) = param_1->LeftMostPx[uVar4];
        piVar1 = param_1->RightMostPx + uVar4;
        uVar4 = uVar4 + iVar7;
        *(int *)(iVar3 + (int)param_1->RightMostPx) = *piVar1;
        iVar3 = iVar3 + iVar7 * 4;
      } while (uVar4 != iVar5 + iVar7);
    }
    for (; (int)param_2 <= iVar6; param_2 = param_2 + 1) {
      param_1->Line_Head_Ptrs[param_2] = (VSpan_Node *)0x0;
      param_1->Line_Tail_Ptrs[param_2] = (VSpan_Node *)0x0;
      param_1->Span_Count[param_2] = 0;
      param_1->LeftMostPx[param_2] = 0;
      param_1->RightMostPx[param_2] = 0;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004be9da
// Address: 004be9da
// XREFS: None
bool __thiscall FUN_004be9da(int param_1,int param_2)
{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x50))) {
    param_2 = param_2 * 4;
    piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + param_2);
    if (piVar1 == (int *)0x0) {
      if (((*(int *)(*(int *)(param_1 + 0x40) + param_2) == 0) &&
          (*(int *)(*(int *)(param_1 + 0x4c) + param_2) == 0)) &&
         (*(int *)(*(int *)(param_1 + 0x44) + param_2) == 0)) {
        return *(int *)(*(int *)(param_1 + 0x48) + param_2) == 0;
      }
    }
    else {
      piVar3 = (int *)0x0;
      iVar4 = 0;
      do {
        piVar2 = piVar1;
        iVar5 = iVar5 + 1;
        if ((iVar5 == 1) && (piVar2[2] != *(int *)(*(int *)(param_1 + 0x44) + param_2))) {
          return false;
        }
        if ((int *)piVar2[1] != piVar3) {
          return false;
        }
        if (piVar2[3] < piVar2[2]) {
          return false;
        }
        if ((1 < iVar5) && (piVar2[2] <= iVar4)) {
          return false;
        }
        piVar1 = (int *)*piVar2;
        piVar3 = piVar2;
        iVar4 = piVar2[3];
      } while ((int *)*piVar2 != (int *)0x0);
      if (((*(int *)(*(int *)(param_1 + 0x4c) + param_2) == iVar5) &&
          (*(int **)(*(int *)(param_1 + 0x40) + param_2) == piVar2)) &&
         (iVar5 = *(int *)(*(int *)(param_1 + 0x48) + param_2), piVar2[3] == iVar5)) {
        return *(int *)(*(int *)(param_1 + 0x44) + param_2) <= iVar5;
      }
    }
  }
  return false;
}

// --------------------------------------------------

// Function: FUN_004beac1
// Address: 004beac1
// XREFS: None
int __thiscall FUN_004beac1(int param_1,int param_2,int param_3,char param_4)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  for (puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x3c) + param_3 * 4);
      puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    iVar2 = puVar1[3];
    for (iVar4 = puVar1[2]; iVar4 <= iVar2; iVar4 = iVar4 + 1) {
      *(char *)(iVar4 + param_2) = *(char *)(iVar4 + param_2) + param_4;
    }
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_004beb0a
// Address: 004beb0a
// XREFS: None
// [HELPER] s_C__AOE__03d_BMP: "C:\AOE_%03d.BMP"
void __thiscall
FUN_004beb0a(TSpan_List_Manager *param_1,char *param_2,int *param_3,TDrawArea *param_4,uchar param_5
            ,int *param_6,int param_7,int param_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uchar *puVar9;
  char *pcVar10;
  int iStack_888;
  undefined2 uStack_874;
  int iStack_872;
  undefined2 uStack_86e;
  undefined2 uStack_86c;
  undefined4 uStack_86a;
  undefined4 uStack_864;
  int iStack_860;
  int iStack_85c;
  undefined2 uStack_858;
  undefined2 uStack_856;
  undefined4 uStack_854;
  undefined4 uStack_850;
  undefined4 uStack_84c;
  undefined4 uStack_848;
  undefined4 uStack_844;
  undefined4 uStack_840;
  undefined1 auStack_83c [60];
  undefined1 auStack_800 [1024];
  tagPALETTEENTRY atStack_400 [256];
  
  if ((0 < param_8) && (iVar2 = 0, piVar7 = param_6, 0 < param_8)) {
    do {
      if (*piVar7 == 0) {
        return;
      }
      iVar2 = iVar2 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar2 < param_8);
  }
  iVar2 = param_1->Num_Pixels;
  iVar1 = param_1->Num_Lines;
  uVar8 = iVar2 + 3U & 0xfffc;
  iStack_872 = iVar1 * uVar8 + 0x436;
  uStack_874 = 0x4d42;
  uStack_86e = 0;
  uStack_86c = 0;
  uStack_86a = 0x436;
  uStack_864 = 0x28;
  uStack_858 = 1;
  uStack_856 = 8;
  uStack_854 = 0;
  uStack_850 = 0;
  uStack_84c = 0;
  uStack_848 = 0;
  uStack_844 = 0;
  uStack_840 = 0;
  iStack_860 = iVar2;
  iStack_85c = iVar1;
  TDrawArea::GetPalette(param_4,(tagPALETTEENTRY *)(auStack_800 + 0x400));
  iVar3 = 0;
  do {
    auStack_800[iVar3] = auStack_800[iVar3 + 0x402];
    auStack_800[iVar3 + 1] = auStack_800[iVar3 + 0x401];
    auStack_800[iVar3 + 2] = auStack_800[iVar3 + 0x400];
    auStack_800[iVar3 + 3] = 0;
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x400);
  iVar3 = 0;
  if (*param_3 < 0) {
    *param_3 = 0;
  }
  while( true ) {
    if (param_2 == (char *)0x0) {
      iVar4 = *param_3;
      pcVar10 = s_C__AOE__03d_BMP;
    }
    else {
      iVar4 = *param_3;
      pcVar10 = param_2;
    }
    sprintf(auStack_83c,pcVar10,iVar4);
    iVar3 = iVar3 + 1;
    iVar4 = __open(auStack_83c,0);
    if (iVar4 == -1) break;
    *param_3 = *param_3 + 1;
    close(iVar4);
    if (1000 < iVar3) {
      return;
    }
  }
  puVar5 = (uchar *)malloc(uVar8);
  iVar3 = __open(auStack_83c,0x8301,0x180);
  if (iVar3 != -1) {
    write(iVar3,&uStack_874,0xe);
    write(iVar3,&uStack_864,0x28);
    write(iVar3,auStack_800,0x400);
    while (iVar1 = iVar1 + -1, -1 < iVar1) {
      puVar9 = puVar5;
      for (uVar6 = uVar8 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        puVar9[0] = '\0';
        puVar9[1] = '\0';
        puVar9[2] = '\0';
        puVar9[3] = '\0';
        puVar9 = puVar9 + 4;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar9 = '\0';
        puVar9 = puVar9 + 1;
      }
      TSpan_List_Manager::DecodeLine(param_1,puVar5,iVar1,param_5,iVar2);
      if (0 < param_8) {
        iStack_888 = param_8;
        piVar7 = param_6;
        do {
          TSpan_List_Manager::DecodeLine
                    ((TSpan_List_Manager *)*piVar7,puVar5,iVar1,
                     *(uchar *)((param_7 - (int)param_6) + (int)piVar7),iVar2);
          piVar7 = piVar7 + 1;
          iStack_888 = iStack_888 + -1;
        } while (iStack_888 != 0);
      }
      write(iVar3,puVar5,uVar8);
    }
    close(iVar3);
  }
  free(puVar5);
  return;
}

// --------------------------------------------------

// Function: FUN_004bedb1
// Address: 004bedb1
// XREFS: None
TRIBE_Panel_Object * __thiscall
FUN_004bedb1(TRIBE_Panel_Object *param_1,TDrawArea *param_2,TPanel *param_3,void *param_4,
            long param_5,long param_6,TShape *param_7,TShape **param_8,TRIBE_Player *param_9)
{
  TRIBE_Panel_Object::TRIBE_Panel_Object
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  param_1->_padding_ = (int)&TRIBE_Scenario_Editor_Panel_Object::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004bee0c
// Address: 004bee0c
// XREFS: None
TRIBE_Scenario_Editor_Panel_Object * __thiscall
FUN_004bee0c(TRIBE_Scenario_Editor_Panel_Object *param_1,byte param_2)
{
  TRIBE_Scenario_Editor_Panel_Object::~TRIBE_Scenario_Editor_Panel_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004bee2e
// Address: 004bee2e
// XREFS: None
void __fastcall FUN_004bee2e(TRIBE_Panel_Object *param_1)
{
  param_1->_padding_ = (int)&TRIBE_Scenario_Editor_Panel_Object::_vftable_;
  TRIBE_Panel_Object::~TRIBE_Panel_Object(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004bee3b
// Address: 004bee3b
// XREFS: None
void __thiscall FUN_004bee3b(int param_1,undefined4 param_2,int param_3)
{
  *(undefined4 *)(param_1 + 0x214) = param_2;
  *(int *)(param_1 + 0x110) = param_3;
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x218) = 0;
    return;
  }
  *(uint *)(param_1 + 0x218) = (uint)*(byte *)(param_3 + 0x54);
  return;
}

// --------------------------------------------------

// Function: FUN_004bee6f
// Address: 004bee6f
// XREFS: None
// [HELPER] s_Gaia: "Gaia"
// [HELPER] s_Unknown: "Unknown"
// [HELPER] s__d__d: "%d+%d"
// [HELPER] s__s: "%s"
void __fastcall FUN_004bee6f(TRIBE_Scenario_Editor_Panel_Object *param_1)
{
  char cVar1;
  byte bVar2;
  uchar uVar3;
  RGE_Master_Static_Object *pRVar4;
  code *pcVar5;
  short sVar6;
  uchar *puVar7;
  void *pvVar8;
  undefined4 uVar9;
  byte *pbVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  long lVar14;
  uint uVar15;
  uint uVar16;
  int unaff_EBX;
  byte *pbVar17;
  char *pcVar18;
  int iVar19;
  float *pfVar20;
  short sVar21;
  TShape *this;
  char *pcVar22;
  bool bVar23;
  int iStack_e4;
  int iStack_dc;
  int iStack_d8;
  long lStack_d4;
  long lStack_d0;
  byte abStack_cc [100];
  char acStack_68 [104];
  
  if (((param_1->_padding_ == 0) || (param_1->_padding_ == 0)) || (param_1->_padding_ == 0)) {
LAB_004bf48b:
    param_1->_padding_ = 0;
    return;
  }
  if ((char)param_1->_padding_ == '\x02') {
    TRIBE_Panel_Object::draw_score((TRIBE_Panel_Object *)param_1);
    return;
  }
  if (param_1->master_game_obj == (RGE_Master_Static_Object *)0x0) {
    if ((int *)param_1->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)param_1->_padding_ + 0x34))(&param_1->_padding_);
      param_1->_padding_ = 0;
      return;
    }
    goto LAB_004bf48b;
  }
  iVar11 = param_1->_padding_;
  (**(code **)(iVar11 + 0x28))(0);
  TDrawArea::Clear((TDrawArea *)param_1->_padding_,(tagRECT *)&param_1->_padding_,0);
  puVar7 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,(char *)0x0,1);
  if (puVar7 != (uchar *)0x0) {
    pRVar4 = param_1->master_game_obj;
    unaff_EBX = 1;
    sVar21 = pRVar4->button_pict;
    if (sVar21 == -1) {
      if (pRVar4->sprite != (RGE_Sprite *)0x0) {
        unaff_EBX = 0;
        iVar19 = RGE_Sprite::get_size(pRVar4->sprite,&iStack_dc,&iStack_d8,&lStack_d0,&lStack_d4,0);
        if (iVar19 != 0) {
          RGE_Sprite::do_draw(param_1->master_game_obj->sprite,0,0,
                              (param_1->_padding_ - iStack_dc) + 10,
                              (param_1->_padding_ - iStack_d8) + 0x28,
                              *(RGE_Color_Table **)(param_1->_padding_ + 0x108),
                              (TDrawArea *)param_1->_padding_,'\0');
        }
      }
    }
    else {
      if (pRVar4->unit_level == '\x02') {
        this = *(TShape **)(param_1->_padding_ + param_1->master_culture_id * 4);
        sVar21 = sVar21 + *(short *)((int)&pRVar4[1].outline_radius_z + 2);
      }
      else {
        this = (TShape *)param_1->_padding_;
      }
      if ((param_1->_padding_ == 0) ||
         (iVar19 = *(int *)(param_1->_padding_ + 0x108), iVar19 == -0x28)) {
        TShape::shape_draw(this,(TDrawArea *)param_1->_padding_,param_1->_padding_ + 2,
                           param_1->_padding_ + 0x21,(int)sVar21,'\0',(uchar *)0x0);
      }
      else {
        _ASMSet_Color_Xform((*(short *)(iVar19 + 0x26) + 1) * 0x10);
        TShape::shape_draw(this,(TDrawArea *)param_1->_padding_,param_1->_padding_ + 2,
                           param_1->_padding_ + 0x21,(int)sVar21,'\x01',
                           (uchar *)(*(int *)(param_1->_padding_ + 0x108) + 0x28));
      }
    }
    TDrawArea::Unlock((TDrawArea *)param_1->_padding_,(char *)0x0);
  }
  pvVar8 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,(char *)0x0);
  if (pvVar8 != (void *)0x0) {
    SetBkMode(*(undefined4 *)(param_1->_padding_ + 0x38),1);
    SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),0xffffff);
    SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_);
    uVar9 = SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_);
    if (param_1->_padding_ != 0) {
      (**(code **)(rge_base_game->_padding_ + 0x28))
                (0x69,(int)*(short *)(param_1->_padding_ + 0x4a),0,abStack_cc,100);
      pbVar17 = &s_Unknown;
      pbVar10 = abStack_cc;
      do {
        bVar2 = *pbVar10;
        bVar23 = bVar2 < *pbVar17;
        if (bVar2 != *pbVar17) {
LAB_004bf0f9:
          iVar11 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
          goto LAB_004bf0fe;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar10[1];
        bVar23 = bVar2 < pbVar17[1];
        if (bVar2 != pbVar17[1]) goto LAB_004bf0f9;
        pbVar10 = pbVar10 + 2;
        pbVar17 = pbVar17 + 2;
      } while (bVar2 != 0);
      iVar11 = 0;
LAB_004bf0fe:
      if (iVar11 == 0) {
        uVar15 = 0xffffffff;
        pcVar18 = &s_Gaia;
        do {
          pcVar22 = pcVar18;
          if (uVar15 == 0) break;
          uVar15 = uVar15 - 1;
          pcVar22 = pcVar18 + 1;
          cVar1 = *pcVar18;
          pcVar18 = pcVar22;
        } while (cVar1 != '\0');
        uVar15 = ~uVar15;
        pbVar10 = (byte *)(pcVar22 + -uVar15);
        pbVar17 = abStack_cc;
        for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
          *(undefined4 *)pbVar17 = *(undefined4 *)pbVar10;
          pbVar10 = pbVar10 + 4;
          pbVar17 = pbVar17 + 4;
        }
        for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
          *pbVar17 = *pbVar10;
          pbVar10 = pbVar10 + 1;
          pbVar17 = pbVar17 + 1;
        }
      }
      uVar15 = 0xffffffff;
      pbVar10 = abStack_cc;
      do {
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        bVar2 = *pbVar10;
        pbVar10 = pbVar10 + 1;
      } while (bVar2 != 0);
      TextOutA(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_ + 2,param_1->_padding_,
               abStack_cc,~uVar15 - 1);
    }
    sVar21 = param_1->master_game_obj->string_id;
    if (sVar21 < 1) {
      acStack_68[0] = '\0';
    }
    else {
      (**(code **)(rge_base_game->_padding_ + 0x20))((int)sVar21,acStack_68,100);
    }
    if (acStack_68[0] == '\0') {
      uVar15 = 0xffffffff;
      pcVar18 = param_1->master_game_obj->name;
      do {
        pcVar22 = pcVar18;
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        pcVar22 = pcVar18 + 1;
        cVar1 = *pcVar18;
        pcVar18 = pcVar22;
      } while (cVar1 != '\0');
      uVar15 = ~uVar15;
      pcVar18 = pcVar22 + -uVar15;
      pcVar22 = acStack_68;
      for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
        *(undefined4 *)pcVar22 = *(undefined4 *)pcVar18;
        pcVar18 = pcVar18 + 4;
        pcVar22 = pcVar22 + 4;
      }
      for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
        *pcVar22 = *pcVar18;
        pcVar18 = pcVar18 + 1;
        pcVar22 = pcVar22 + 1;
      }
    }
    sprintf(abStack_cc,s__s,acStack_68);
    uVar15 = 0xffffffff;
    pbVar10 = abStack_cc;
    do {
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      bVar2 = *pbVar10;
      pbVar10 = pbVar10 + 1;
    } while (bVar2 != 0);
    TextOutA(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_ + 2,
             param_1->_padding_ + 0xf,abStack_cc,~uVar15 - 1);
    if (unaff_EBX != 0) {
      iVar11 = (int)param_1->master_game_obj->hp;
      sprintf(acStack_68,s__d__d,iVar11,iVar11);
      uVar15 = 0xffffffff;
      pcVar18 = acStack_68;
      do {
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        cVar1 = *pcVar18;
        pcVar18 = pcVar18 + 1;
      } while (cVar1 != '\0');
      TextOutA(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_ + 5,
               param_1->_padding_ + 0x55,acStack_68,~uVar15 - 1);
      SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),uVar9);
      SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),0);
    }
    TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,(char *)0x0);
    iVar11 = iStack_e4;
  }
  if (unaff_EBX == 0) goto switchD_004bf313_caseD_4;
  pRVar4 = param_1->master_game_obj;
  iVar19 = 0;
  uVar3 = pRVar4->unit_level;
  if (uVar3 == '\x03') {
LAB_004bf3c9:
    iVar19 = (int)*(short *)((int)&pRVar4[1].multiple_attribute_mod + 2);
    (**(code **)(iVar11 + 0xe0))(0,7,1,iVar19,iVar19);
    iVar19 = 1;
  }
  else {
    if (((uVar3 != '\t') && (uVar3 != '\x04')) &&
       ((uVar3 != '\x05' && ((uVar3 != '\x06' && (uVar3 != '\a')))))) {
      if (uVar3 == '\x01') {
        sVar21 = -1;
        iVar19 = 0;
        pfVar20 = pRVar4->attribute_amount_held;
        do {
          if ((float)DAT_00574524 < *pfVar20) {
            sVar21 = pRVar4->attribute_type_held[iVar19];
            break;
          }
          iVar19 = iVar19 + 1;
          pfVar20 = pfVar20 + 1;
        } while (iVar19 < 3);
        switch(sVar21) {
        case 0:
        case 0xf:
        case 0x10:
        case 0x11:
          uVar9 = 2;
          break;
        case 1:
          uVar9 = 0;
          break;
        case 2:
          uVar9 = 1;
          break;
        case 3:
          uVar9 = 3;
          break;
        default:
          goto switchD_004bf313_caseD_4;
        }
        uVar12 = __ftol(0);
        (**(code **)(iVar11 + 0xe0))(0,uVar9,0,uVar12);
        (**(code **)(iVar11 + 0x2c))();
        return;
      }
      if (uVar3 == '\x02') {
        iVar19 = (int)*(short *)((int)&pRVar4[1].multiple_attribute_mod + 2);
        pcVar5 = *(code **)(iVar11 + 0xe0);
        (*pcVar5)(0,7,1,iVar19,iVar19);
        iVar19 = (int)*(short *)&param_1->master_game_obj[1].multiple_attribute_mod;
        (*pcVar5)(1,8,1,iVar19,iVar19);
        uVar9 = __ftol();
        (*pcVar5)(2,6,1,uVar9,uVar9);
        (**(code **)(iVar11 + 0x2c))();
        return;
      }
      goto switchD_004bf313_caseD_4;
    }
    if ((uVar3 == '\x03') || (uVar3 == '\x04')) goto LAB_004bf3c9;
  }
  uVar3 = param_1->master_game_obj->unit_level;
  if ((uVar3 == '\x04') || (uVar3 == '\x06')) {
    iVar13 = (int)*(short *)&param_1->master_game_obj[1].multiple_attribute_mod;
    (**(code **)(iVar11 + 0xe0))(iVar19,8,1,iVar13,iVar13);
    iVar19 = iVar19 + 1;
  }
  lVar14 = TRIBE_Scenario_Editor_Panel_Object::get_pierce_armor(param_1);
  uVar3 = param_1->master_game_obj->unit_level;
  sVar21 = (short)lVar14;
  if ((uVar3 == '\x04') || (uVar3 == '\x06')) {
    (**(code **)(iVar11 + 0xe0))(iVar19,10,1,(int)sVar21,(int)sVar21);
    iVar19 = iVar19 + 1;
  }
  uVar3 = param_1->master_game_obj->unit_level;
  if ((uVar3 == '\x04') || (uVar3 == '\x06')) {
    sVar6 = __ftol();
    (**(code **)(iVar11 + 0xe0))(iVar19,6,1,(int)sVar6,(int)sVar21);
  }
switchD_004bf313_caseD_4:
  (**(code **)(iVar11 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_004bf499
// Address: 004bf499
// XREFS: None
// [HELPER] s__d: "%d"
// [HELPER] s__d__: "%d%%"
// [HELPER] s__d__d: "%d+%d"
void __fastcall FUN_004bf499(char *param_1,undefined4 param_2)
{
  int iVar1;
  char cVar4;
  char *in_EAX;
  uchar *puVar2;
  void *pvVar3;
  uint uVar5;
  int *piVar6;
  char cVar7;
  int unaff_EBX;
  char *pcVar8;
  char in_CF;
  int iStack0000000c;
  char in_stack_00000010;
  undefined2 in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  undefined4 in_stack_00000030;
  int in_stack_00000034;
  int in_stack_00000038;
  
  iVar1 = in_stack_0000002c;
  cVar7 = (char)unaff_EBX;
  piVar6 = (int *)CONCAT22((short)((uint)param_2 >> 0x10),
                           CONCAT11(((char)((uint)param_2 >> 8) - cVar7) - in_CF,(char)param_2));
  cVar4 = (char)((uint)in_EAX >> 8);
  *param_1 = *param_1 + cVar4;
  cRam2c004bf3 = cRam2c004bf3 + cVar4;
  *(char *)piVar6 = (char)*piVar6 + cVar7 + -3;
  *(char *)piVar6 = (char)*piVar6 + cVar7 + -4;
  *(char *)piVar6 = (char)*piVar6 + cVar7 + -5;
  *(char *)(unaff_EBX + -0x12) = *(char *)(unaff_EBX + -0x12) + (char)((uint)(unaff_EBX + -6) >> 8);
  iStack0000000c = unaff_EBX + -7;
  *in_EAX = *in_EAX + (char)in_EAX;
  *piVar6 = (int)(in_EAX + *piVar6);
  if (((*(int *)(param_1 + 0x104) != 0) && (in_stack_0000002c != -1)) &&
     (puVar2 = TDrawArea::Lock(*(TDrawArea **)(param_1 + 0x20),(char *)0x0,1),
     puVar2 != (uchar *)0x0)) {
    TShape::shape_draw(*(TShape **)(param_1 + 0x104),*(TDrawArea **)(param_1 + 0x20),
                       *(int *)(param_1 + 0xc) + 0x3c,
                       *(int *)(param_1 + 0x10) + 0x1e + in_stack_00000028 * 0x12,iVar1,'\0',
                       (uchar *)0x0);
    TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),(char *)0x0);
  }
  switch(in_stack_00000030) {
  case 0:
    sprintf(&stack0x00000010,&s__d,in_stack_00000034);
    break;
  case 1:
    if (in_stack_00000034 < in_stack_00000038) {
      sprintf(&stack0x00000010,s__d__d,in_stack_00000034,in_stack_00000038 - in_stack_00000034);
    }
    else {
      sprintf(&stack0x00000010,&s__d,in_stack_00000034);
    }
    break;
  case 2:
    sprintf(&stack0x00000010,s__d__d,in_stack_00000034,in_stack_00000038);
    break;
  case 3:
    sprintf(&stack0x00000010,s__d__,in_stack_00000034);
    break;
  default:
    in_stack_00000010 = '\0';
  }
  if ((in_stack_00000010 != '\0') &&
     (pvVar3 = TDrawArea::GetDc(*(TDrawArea **)(param_1 + 0x20),(char *)0x0), pvVar3 != (void *)0x0)
     ) {
    SetBkMode(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),1);
    SetTextColor(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),0xffffff);
    SelectClipRgn(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),*(undefined4 *)(param_1 + 0x88));
    in_stack_00000034 =
         SelectObject(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),
                      *(undefined4 *)(param_1 + 0xf4));
    uVar5 = 0xffffffff;
    pcVar8 = &stack0x00000010;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar4 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar4 != '\0');
    TextOutA(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),*(int *)(param_1 + 0xc) + 100,
             *(int *)(param_1 + 0x10) + 0x20 + in_stack_00000028 * 0x12,&stack0x00000010,~uVar5 - 1)
    ;
    SelectObject(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),in_stack_00000034);
    SelectClipRgn(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),0);
    TDrawArea::ReleaseDc(*(TDrawArea **)(param_1 + 0x20),(char *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bf6a5
// Address: 004bf6a5
// XREFS: None
undefined4 __fastcall FUN_004bf6a5(TPanel *param_1,char param_2)
{
  int in_EAX;
  char unaff_BL;
  int unaff_EBP;
  int unaff_ESI;
  
  *(char *)(unaff_EBP + -0xb) = *(char *)(unaff_EBP + -0xb) + unaff_BL + -1;
  *(char *)(unaff_ESI + -0x4bffb40b) = *(char *)(unaff_ESI + -0x4bffb40b) + param_2;
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + param_2;
  TPanel::release_mouse(param_1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004bf6d8
// Address: 004bf6d8
// XREFS: None
int __fastcall FUN_004bf6d8(int param_1)
{
  int iVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x214);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(char *)(iVar1 + 4) != 'F') {
    return 0;
  }
  iVar4 = (int)*(short *)(iVar1 + 0x102);
  iVar2 = 0;
  if (0 < iVar4) {
    psVar3 = *(short **)(iVar1 + 0x104);
    do {
      if (*psVar3 == 3) {
        iVar2 = (int)psVar3[1];
      }
      psVar3 = psVar3 + 2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_004bf71a
// Address: 004bf71a
// XREFS: None
void __thiscall FUN_004bf71a(undefined1 *param_1,undefined2 param_2)
{
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined2 *)(param_1 + 0x72) = param_2;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  param_1[0x48] = 0;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined2 *)(param_1 + 0x5e) = 0;
  *(undefined2 *)(param_1 + 0x60) = 0;
  *(undefined2 *)(param_1 + 0x2a) = 0;
  *(undefined2 *)(param_1 + 0x2e) = 0;
  *(undefined2 *)(param_1 + 0x30) = 0;
  *(undefined2 *)(param_1 + 0x32) = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined2 *)(param_1 + 0x36) = 0;
  param_1[0x14] = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  param_1[0x74] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2c] = 0;
  param_1[0x40] = 0;
  param_1[0x70] = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004bf78b
// Address: 004bf78b
// XREFS: None
void * __thiscall FUN_004bf78b(void *param_1,int param_2,int param_3,undefined4 param_4)
{
  short *psVar1;
  short *psVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar3 = param_2;
  *(undefined4 *)((int)param_1 + 0x18) = param_4;
  *(undefined4 *)((int)param_1 + 0x20) = 0;
  *(undefined4 *)((int)param_1 + 0x24) = 0;
  rge_read(param_2,(void *)((int)param_1 + 0x48),0x15);
  rge_read(iVar3,param_1,0xd);
  rge_read(iVar3,(void *)((int)param_1 + 0x10),4);
  rge_read(iVar3,(void *)((int)param_1 + 0x14),1);
  rge_read(iVar3,(void *)((int)param_1 + 0x28),1);
  rge_read(iVar3,(void *)((int)param_1 + 0x29),1);
  rge_read(iVar3,(void *)((int)param_1 + 0x2a),2);
  rge_read(iVar3,(void *)((int)param_1 + 0x2c),1);
  rge_read(iVar3,(void *)((int)param_1 + 0x2e),2);
  rge_read(iVar3,(void *)((int)param_1 + 0x30),2);
  rge_read(iVar3,(void *)((int)param_1 + 0x32),2);
  rge_read(iVar3,(void *)((int)param_1 + 0x34),2);
  psVar1 = (short *)((int)param_1 + 0x36);
  rge_read(iVar3,psVar1,2);
  rge_read(iVar3,&param_4,2);
  rge_read(iVar3,(void *)((int)param_1 + 0x40),1);
  rge_read(iVar3,(void *)((int)param_1 + 0x5e),2);
  psVar2 = (short *)((int)param_1 + 0x60);
  rge_read(iVar3,psVar2,2);
  rge_read(iVar3,(void *)((int)param_1 + 100),4);
  rge_read(iVar3,(void *)((int)param_1 + 0x68),4);
  rge_read(iVar3,(void *)((int)param_1 + 0x6c),4);
  rge_read(iVar3,(void *)((int)param_1 + 0x70),1);
  rge_read(iVar3,(void *)((int)param_1 + 0x72),2);
  rge_read(iVar3,(void *)((int)param_1 + 0x74),1);
  if ((short)param_4 < 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(param_3 + (short)param_4 * 4);
  }
  *(undefined4 *)((int)param_1 + 0x3c) = uVar5;
  if (*psVar1 < 1) {
    *(undefined4 *)((int)param_1 + 0x38) = 0;
  }
  else {
    pvVar4 = (void *)calloc((int)*psVar1,0x10);
    *(void **)((int)param_1 + 0x38) = pvVar4;
    rge_read(iVar3,pvVar4,(int)*psVar1 << 4);
  }
  if (*(char *)((int)param_1 + 0x40) == '\0') {
    *(undefined4 *)((int)param_1 + 0x44) = 0;
  }
  else {
    uVar5 = calloc((int)*psVar2,0x14);
    *(undefined4 *)((int)param_1 + 0x44) = uVar5;
    iStack_4 = 0;
    if (0 < *psVar2) {
      iStack_c = 0;
      do {
        iVar7 = iStack_c + 0xc;
        iStack_8 = 3;
        iVar6 = iStack_c;
        do {
          rge_read(iVar3,(void *)(iVar7 + *(int *)((int)param_1 + 0x44)),2);
          rge_read(iVar3,&param_2,2);
          if ((short)param_2 < 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = *(undefined4 *)(param_3 + (short)param_2 * 4);
          }
          iVar7 = iVar7 + 2;
          *(undefined4 *)(iVar6 + *(int *)((int)param_1 + 0x44)) = uVar5;
          iVar6 = iVar6 + 4;
          iStack_8 = iStack_8 + -1;
        } while (iStack_8 != 0);
        iStack_4 = iStack_4 + 1;
        iStack_c = iStack_c + 0x14;
      } while (iStack_4 < *(short *)((int)param_1 + 0x60));
      return param_1;
    }
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004bfcdd
// Address: 004bfcdd
// XREFS: None
void __fastcall FUN_004bfcdd(int param_1)
{
  TShape *this;
  
  this = *(TShape **)(param_1 + 0x1c);
  if ((this != (TShape *)0x0) && (*(char *)(param_1 + 0x14) != '\0')) {
    if (this != (TShape *)0x0) {
      TShape::~TShape(this);
      operator_delete(this);
    }
    *(undefined1 *)(param_1 + 0x14) = 0;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (*(int *)(param_1 + 0x44) != 0) {
    free(*(int *)(param_1 + 0x44));
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  if (*(int *)(param_1 + 0x38) != 0) {
    free(*(int *)(param_1 + 0x38));
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004bfd3a
// Address: 004bfd3a
// XREFS: None
void __thiscall FUN_004bfd3a(RGE_Sprite *param_1,RGE_Sprite **param_2)
{
  RGE_Picture_List *pRVar1;
  short sVar2;
  
  if ((0 < param_1->draw_list_num) && (param_1->draw_list != (RGE_Picture_List *)0x0)) {
    sVar2 = 0;
    if (0 < param_1->draw_list_num) {
      do {
        pRVar1 = param_1->draw_list + sVar2;
        if (pRVar1->picture_num == -1) {
          pRVar1->sprite = param_1;
        }
        else {
          pRVar1->sprite = param_2[pRVar1->picture_num];
        }
        sVar2 = sVar2 + 1;
      } while (sVar2 < param_1->draw_list_num);
    }
  }
  RGE_Sprite::load_facets(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004bfd91
// Address: 004bfd91
// XREFS: None
void __thiscall FUN_004bfd91(void *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar2 = param_2;
  iStack_10 = -1;
  if (*(int *)((int)param_1 + 0x3c) != 0) {
    iStack_10 = (int)*(short *)(*(int *)((int)param_1 + 0x3c) + 0xc);
  }
  rge_write(param_2,(void *)((int)param_1 + 0x48),0x15);
  rge_write(param_2,param_1,0xd);
  rge_write(param_2,(void *)((int)param_1 + 0x10),4);
  rge_write(param_2,(void *)((int)param_1 + 0x14),1);
  rge_write(param_2,(void *)((int)param_1 + 0x28),1);
  rge_write(param_2,(void *)((int)param_1 + 0x29),1);
  rge_write(param_2,(void *)((int)param_1 + 0x2a),2);
  rge_write(param_2,(void *)((int)param_1 + 0x2c),1);
  rge_write(param_2,(void *)((int)param_1 + 0x2e),2);
  rge_write(param_2,(void *)((int)param_1 + 0x30),2);
  rge_write(param_2,(void *)((int)param_1 + 0x32),2);
  rge_write(param_2,(void *)((int)param_1 + 0x34),2);
  rge_write(param_2,(short *)((int)param_1 + 0x36),2);
  rge_write(param_2,&iStack_10,2);
  rge_write(param_2,(char *)((int)param_1 + 0x40),1);
  rge_write(param_2,(void *)((int)param_1 + 0x5e),2);
  rge_write(param_2,(void *)((int)param_1 + 0x60),2);
  rge_write(param_2,(void *)((int)param_1 + 100),4);
  rge_write(param_2,(void *)((int)param_1 + 0x68),4);
  rge_write(param_2,(void *)((int)param_1 + 0x6c),4);
  rge_write(param_2,(void *)((int)param_1 + 0x70),1);
  rge_write(param_2,(void *)((int)param_1 + 0x72),2);
  rge_write(param_2,(void *)((int)param_1 + 0x74),1);
  if (*(void **)((int)param_1 + 0x38) != (void *)0x0) {
    rge_write(param_2,*(void **)((int)param_1 + 0x38),(int)*(short *)((int)param_1 + 0x36) << 4);
  }
  if ((*(char *)((int)param_1 + 0x40) != '\0') &&
     (iStack_4 = 0, 0 < *(short *)((int)param_1 + 0x60))) {
    param_2 = 0;
    do {
      iVar4 = param_2 + 0xc;
      iStack_8 = 3;
      iVar3 = param_2;
      do {
        iVar1 = *(int *)(iVar3 + *(int *)((int)param_1 + 0x44));
        if (iVar1 == 0) {
          iStack_c = -1;
        }
        else {
          iStack_c = (int)*(short *)(iVar1 + 0xc);
        }
        rge_write(iVar2,(void *)(iVar4 + *(int *)((int)param_1 + 0x44)),2);
        rge_write(iVar2,&iStack_c,2);
        iVar3 = iVar3 + 4;
        iVar4 = iVar4 + 2;
        iStack_8 = iStack_8 + -1;
      } while (iStack_8 != 0);
      iStack_4 = iStack_4 + 1;
      param_2 = param_2 + 0x14;
    } while (iStack_4 < *(short *)((int)param_1 + 0x60));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004bffd1
// Address: 004bffd1
// XREFS: None
void __fastcall FUN_004bffd1(int param_1)
{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)(param_1 + 0x14) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004bffee
// Address: 004bffee
// XREFS: None
void __thiscall FUN_004bffee(int param_1,short param_2,short param_3,short param_4)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if (*(short *)(param_1 + 0x60) <= param_4) {
    param_4 = 0;
  }
  if (param_2 != param_3) {
    if ((*(RGE_Sound **)(param_1 + 0x3c) != (RGE_Sound *)0x0) &&
       ((param_2 == 0 || ((param_3 < param_2 && (param_3 != 0)))))) {
      RGE_Sound::play(*(RGE_Sound **)(param_1 + 0x3c),1);
    }
    if (*(char *)(param_1 + 0x40) != '\0') {
      if (param_2 < param_3) {
        iVar2 = 0;
        iVar3 = param_4 * 0x14 + 0xc;
        while( true ) {
          sVar1 = *(short *)(iVar3 + *(int *)(param_1 + 0x44));
          if (sVar1 < 0) break;
          if ((param_2 <= sVar1) && (sVar1 < param_3)) {
            RGE_Sound::play(*(RGE_Sound **)(*(int *)(param_1 + 0x44) + (iVar2 + param_4 * 5) * 4),1)
            ;
          }
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 2;
          if (2 < iVar2) {
            return;
          }
        }
      }
      else {
        iVar2 = 0;
        iVar3 = param_4 * 0x14 + 0xc;
        do {
          sVar1 = *(short *)(iVar3 + *(int *)(param_1 + 0x44));
          if (sVar1 < 0) {
            return;
          }
          if ((param_2 <= sVar1) || (sVar1 < param_3)) {
            RGE_Sound::play(*(RGE_Sound **)(*(int *)(param_1 + 0x44) + (iVar2 + param_4 * 5) * 4),1)
            ;
          }
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 2;
        } while (iVar2 < 3);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c00de
// Address: 004c00de
// XREFS: None
uint __thiscall FUN_004c00de(int param_1,uint param_2,int param_3,int *param_4)
{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 0x74);
  if ((bVar1 != 0) && (*(short *)(param_1 + 0x60) == 2)) {
    *param_4 = param_3;
    return param_2 & 0xff;
  }
  if ((bVar1 != 0) &&
     (((int)(uint)bVar1 < (int)param_2 || ((int)param_2 < (int)*(short *)(param_1 + 0x60) >> 2)))) {
    iVar2 = (int)*(short *)(param_1 + 0x60) >> 1;
    if (iVar2 < (int)param_2) {
      iVar2 = (iVar2 - param_2) + (int)*(short *)(param_1 + 0x60);
    }
    else {
      iVar2 = iVar2 - param_2;
    }
    *param_4 = iVar2;
    *param_4 = (*param_4 - ((int)*(short *)(param_1 + 0x60) >> 2)) * (int)*(short *)(param_1 + 0x5e)
               + param_3;
    return 1;
  }
  if (bVar1 == 0) {
    *param_4 = (int)*(short *)(param_1 + 0x5e) * param_2 + param_3;
    return 0;
  }
  *param_4 = (param_2 - ((int)*(short *)(param_1 + 0x60) >> 2)) * (int)*(short *)(param_1 + 0x5e) +
             param_3;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c0199
// Address: 004c0199
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_sprite_cpp: "C:\msdev\work\age1_x1\sprite.cpp"
// [HELPER] s__shp: ".shp"
void __thiscall
FUN_004c0199(RGE_Sprite *param_1,long param_2,long param_3,long param_4,long param_5,int param_6,
            TDrawArea *param_7,uint param_8)
{
  short sVar1;
  uchar uVar2;
  ulong uVar3;
  TShape *pTVar4;
  ulong uVar5;
  uchar *puVar6;
  undefined4 *unaff_FS_OFFSET;
  long lStack_118;
  char *pcStack_114;
  TShape *pTStack_110;
  char acStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f8fe;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pcStack_114 = (char *)0x0;
  if (param_1->frame_num <= param_3) {
    param_3 = 0;
  }
  if (param_1->shape == (TShape *)0x0) {
    if (param_1->loaded == '\0') goto LAB_004c04ca;
    addstring(&pcStack_114,param_1->pict_name,s__shp);
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x1e8);
    pTStack_110 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTStack_110 == (TShape *)0x0) {
      pTVar4 = (TShape *)0x0;
    }
    else {
      pTVar4 = (TShape *)TShape::TShape(pTStack_110,pcStack_114,param_1->resource_id);
    }
    uStack_4 = 0xffffffff;
    param_1->shape = pTVar4;
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x1ea);
    RGE_Base_Game::add_to_timing(rge_base_game,0xb,uVar5 - uVar3);
    free(pcStack_114);
  }
  param_1->delta_time = 0;
  SDI_Draw_Level = (uint)param_1->draw_level;
  if ((uint)param_1->draw_level < (param_8 & 0xff)) {
    SDI_Draw_Level = param_8 & 0xff;
  }
  SDI_List->Select_Box = (short *)0x0;
  if (param_1->box_x1 != 0) {
    SDI_List->Select_Box = &param_1->box_x1;
  }
  uVar2 = RGE_Sprite::get_facetindex(param_1,param_2,param_3,&lStack_118);
  if (uVar2 == '\0') {
    if (do_draw_log != 0) {
      sprintf(acStack_10c,s_<_s,_d,_d,_d,_d,u,param_1,param_4,param_5,lStack_118,param_1->color_flag
             );
      if (safe_draw_log == 0) {
        write_draw_log(acStack_10c);
      }
      else {
        write_draw_log2(acStack_10c);
      }
    }
    sVar1 = param_1->color_table;
    if (sVar1 < 0) {
      if (param_6 == 0) {
        puVar6 = (uchar *)0x0;
      }
      else {
        _ASMSet_Color_Xform((*(short *)(param_6 + 0x26) + 1) * 0x10);
        puVar6 = (uchar *)(param_6 + 0x28);
      }
      uVar2 = param_1->color_flag;
    }
    else {
      if (param_1->color_tables[sVar1] == (RGE_Color_Table *)0x0) {
        puVar6 = (uchar *)0x0;
      }
      else {
        _ASMSet_Color_Xform((sVar1 + 1) * 0x10);
        puVar6 = param_1->color_tables[param_1->color_table]->table;
      }
      uVar2 = param_1->color_flag;
    }
    TShape::shape_draw(param_1->shape,param_7,param_4,param_5,lStack_118,uVar2,puVar6);
  }
  else {
    if (do_draw_log != 0) {
      sprintf(acStack_10c,s_<_s,_d,_d,_d,_d,m,param_1,param_4,param_5,lStack_118,param_1->color_flag
             );
      if (safe_draw_log == 0) {
        write_draw_log(acStack_10c);
      }
      else {
        write_draw_log2(acStack_10c);
      }
    }
    sVar1 = param_1->color_table;
    if (sVar1 < 0) {
      if (param_6 == 0) {
        puVar6 = (uchar *)0x0;
      }
      else {
        _ASMSet_Color_Xform((*(short *)(param_6 + 0x26) + 1) * 0x10);
        puVar6 = (uchar *)(param_6 + 0x28);
      }
      TShape::shape_mirror
                (param_1->shape,param_7,param_4,param_5,lStack_118,param_1->color_flag,puVar6);
    }
    else {
      if (param_1->color_tables[sVar1] == (RGE_Color_Table *)0x0) {
        puVar6 = (uchar *)0x0;
      }
      else {
        _ASMSet_Color_Xform((sVar1 + 1) * 0x10);
        puVar6 = param_1->color_tables[param_1->color_table]->table;
      }
      TShape::shape_mirror
                (param_1->shape,param_7,param_4,param_5,lStack_118,param_1->color_flag,puVar6);
    }
  }
  if (do_draw_log != 0) {
    if (safe_draw_log == 0) {
      write_draw_log(&s_>);
    }
    else {
      write_draw_log2(&s_>);
    }
  }
LAB_004c04ca:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004c04e5
// Address: 004c04e5
// XREFS: None
int __thiscall
FUN_004c04e5(RGE_Sprite *param_1,int param_2,long param_3,long param_4,int param_5,long param_6,
            int param_7,RGE_Color_Table *param_8,TDrawArea *param_9,uchar param_10)
{
  short sVar1;
  RGE_Picture_List *pRVar2;
  RGE_Sprite *this;
  int iVar3;
  long lVar4;
  int iStack_8;
  int iStack_4;
  
  if (param_1->facet_num <= param_2) {
    param_2 = 0;
  }
  if ((param_1->draw_list_num < 1) || (param_1->draw_list == (RGE_Picture_List *)0x0)) {
    if (param_1->draw_level < 0xb) {
      param_4 = param_6;
      param_5 = param_7;
    }
    RGE_Sprite::do_draw(param_1,param_2,param_3,param_4,param_5,param_8,param_9,param_10);
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
    iStack_8 = 0;
    if (0 < param_1->draw_list_num) {
      iStack_4 = 0;
      do {
        pRVar2 = param_1->draw_list;
        sVar1 = *(short *)((int)&pRVar2->facet + iStack_4);
        if ((sVar1 < 0) || (sVar1 == param_2)) {
          this = *(RGE_Sprite **)((int)&pRVar2->sprite + iStack_4);
          iVar3 = (int)*(short *)((int)&pRVar2->offset_y + iStack_4);
          if (this->draw_level < 0xb) {
            iVar3 = iVar3 + param_7;
            sVar1 = *(short *)((int)&pRVar2->offset_x + iStack_4);
            lVar4 = param_6;
          }
          else {
            iVar3 = iVar3 + param_5;
            sVar1 = *(short *)((int)&pRVar2->offset_x + iStack_4);
            lVar4 = param_4;
          }
          RGE_Sprite::do_draw(this,(this->facet_num * param_2) / (int)param_1->facet_num,param_3,
                              sVar1 + lVar4,iVar3,param_8,param_9,param_10);
        }
        iStack_8 = iStack_8 + 1;
        iStack_4 = iStack_4 + 0x10;
      } while (iStack_8 < param_1->draw_list_num);
      return iStack_8;
    }
  }
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_004c071a
// Address: 004c071a
// XREFS: None
uint __thiscall
FUN_004c071a(RGE_Sprite *param_1,uint param_2,long param_3,int param_4,int param_5,
            RGE_Color_Table *param_6,TDrawArea *param_7,byte param_8)
{
  short sVar1;
  RGE_Picture_List *pRVar2;
  RGE_Sprite *this;
  int iVar3;
  int iStack_4;
  
  iVar3 = param_2;
  if ((int)param_1->facet_num <= (int)param_2) {
    iVar3 = 0;
  }
  if ((param_1->draw_list_num < 1) || (param_1->draw_list == (RGE_Picture_List *)0x0)) {
    if ((param_1->draw_level != param_8) && (param_1->draw_level < 0x14)) {
      RGE_Sprite::do_draw(param_1,iVar3,param_3,param_4,param_5,param_6,param_7,'\0');
    }
    param_2 = 1;
  }
  else {
    param_2 = 0;
    if (0 < param_1->draw_list_num) {
      iStack_4 = 0;
      do {
        pRVar2 = param_1->draw_list;
        this = *(RGE_Sprite **)((int)&pRVar2->sprite + iStack_4);
        if (((this->draw_level != param_8) && (this->draw_level < 0x14)) &&
           ((sVar1 = *(short *)((int)&pRVar2->facet + iStack_4), sVar1 < 0 || (sVar1 == iVar3)))) {
          RGE_Sprite::do_draw(this,(this->facet_num * iVar3) / (int)param_1->facet_num,param_3,
                              *(short *)((int)&pRVar2->offset_x + iStack_4) + param_4,
                              *(short *)((int)&pRVar2->offset_y + iStack_4) + param_5,param_6,
                              param_7,'\0');
        }
        iStack_4 = iStack_4 + 0x10;
        param_2 = param_2 + 1;
      } while ((int)param_2 < (int)param_1->draw_list_num);
      return param_2 & 0xff;
    }
  }
  return param_2;
}

// --------------------------------------------------

// Function: FUN_004c0832
// Address: 004c0832
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_sprite_cpp: "C:\msdev\work\age1_x1\sprite.cpp"
// [HELPER] s__shp: ".shp"
uchar __thiscall
FUN_004c0832(char *param_1,long *param_2,long *param_3,long *param_4,long *param_5,long param_6)
{
  uchar uVar1;
  ulong uVar2;
  undefined4 uVar3;
  ulong uVar4;
  undefined4 *unaff_FS_OFFSET;
  char *pcStack_14;
  TShape *pTStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f91b;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 0x1c) == 0) {
    if (param_1[0x14] == '\0') {
      *unaff_FS_OFFSET = uStack_c;
      return '\0';
    }
    pcStack_14 = (char *)0x0;
    addstring(&pcStack_14,param_1,s__shp);
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x2b9);
    pTStack_10 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTStack_10 == (TShape *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = TShape::TShape(pTStack_10,pcStack_14,*(long *)(param_1 + 0x10));
    }
    uStack_4 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c) = uVar3;
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,699);
    RGE_Base_Game::add_to_timing(rge_base_game,0xb,uVar4 - uVar2);
    free(pcStack_14);
  }
  uVar1 = TShape::shape_minmax(*(TShape **)(param_1 + 0x1c),param_2,param_3,param_4,param_5,param_6)
  ;
  *unaff_FS_OFFSET = uStack_c;
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_004c0957
// Address: 004c0957
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_sprite_cpp: "C:\msdev\work\age1_x1\sprite.cpp"
// [HELPER] s__shp: ".shp"
undefined4 __thiscall
FUN_004c0957(RGE_Sprite *param_1,short *param_2,short *param_3,short *param_4,short *param_5,
            int param_6,long param_7)
{
  RGE_Picture_List *pRVar1;
  RGE_Sprite *this;
  short *psVar2;
  ulong uVar3;
  TShape *pTVar4;
  ulong uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  char *pcStack_14;
  TShape *pTStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  psVar2 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f93b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_1->shape == (TShape *)0x0) {
    if (param_1->loaded != '\0') {
      pcStack_14 = (char *)0x0;
      addstring(&pcStack_14,param_1->pict_name,s__shp);
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x2d2);
      pTStack_10 = (TShape *)operator_new(0x20);
      uStack_4 = 0;
      if (pTStack_10 == (TShape *)0x0) {
        pTVar4 = (TShape *)0x0;
      }
      else {
        pTVar4 = (TShape *)TShape::TShape(pTStack_10,pcStack_14,param_1->resource_id);
      }
      uStack_4 = 0xffffffff;
      param_1->shape = pTVar4;
      uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x2d4);
      RGE_Base_Game::add_to_timing(rge_base_game,0xb,uVar5 - uVar3);
      free(pcStack_14);
      goto LAB_004c0a23;
    }
LAB_004c0b1c:
    uVar6 = 0;
  }
  else {
LAB_004c0a23:
    if (((param_1->box_x1 == 0) && (param_1->box_x2 == 0)) ||
       ((param_1->box_y1 == 0 && (param_1->box_y2 == 0)))) {
      *param_2 = 0;
      *param_3 = 0;
      *param_4 = 0;
      *param_5 = 0;
      if ((param_1->draw_list_num < 1) || (param_1->draw_list == (RGE_Picture_List *)0x0)) {
        RGE_Sprite::get_frame_min_max(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0,0);
      }
      else {
        param_2 = (short *)0x0;
        if (0 < param_1->draw_list_num) {
          iVar7 = 0;
          do {
            if (param_1->transparent_picking_flag != '\0') {
              pRVar1 = param_1->draw_list;
              this = *(RGE_Sprite **)((int)&pRVar1->sprite + iVar7);
              RGE_Sprite::get_frame_min_max
                        (this,psVar2,param_3,param_4,param_5,
                         (this->facet_num * param_6) / (int)param_1->facet_num,param_7,
                         *(short *)((int)&pRVar1->offset_x + iVar7),
                         *(short *)((int)&pRVar1->offset_y + iVar7));
            }
            iVar7 = iVar7 + 0x10;
            param_2 = (short *)((int)param_2 + 1);
          } while ((int)param_2 < (int)param_1->draw_list_num);
        }
      }
      if (((*psVar2 == 0) && (*param_4 == 0)) || ((*param_3 == 0 && (*param_5 == 0))))
      goto LAB_004c0b1c;
    }
    else {
      *param_2 = param_1->box_x1;
      *param_3 = param_1->box_y1;
      *param_4 = param_1->box_x2;
      *param_5 = param_1->box_y2;
    }
    uVar6 = 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar6;
}

// --------------------------------------------------

// Function: FUN_004c0b62
// Address: 004c0b62
// XREFS: None
undefined4 __thiscall
FUN_004c0b62(RGE_Sprite *param_1,short *param_2,short *param_3,short *param_4,short *param_5,
            int param_6,int param_7,short param_8,short param_9)
{
  uchar uVar1;
  int iVar2;
  long lStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar2 = param_7;
  if (param_1->frame_num <= param_7) {
    iVar2 = 0;
  }
  uVar1 = RGE_Sprite::get_facetindex(param_1,param_6,iVar2,&lStack_c);
  iVar2 = RGE_Sprite::get_size(param_1,&param_6,&iStack_8,&param_7,&iStack_4,lStack_c);
  if (iVar2 != 0) {
    if (uVar1 != '\0') {
      iVar2 = -param_6;
      param_6 = -param_7;
      param_7 = iVar2;
    }
    param_6 = param_6 + param_8;
    param_7 = param_7 + param_8;
    iStack_8 = iStack_8 + param_9;
    iStack_4 = iStack_4 + param_9;
    if (param_6 < *param_2) {
      *param_2 = (short)param_6;
    }
    if (iStack_8 < *param_3) {
      *param_3 = (short)iStack_8;
    }
    if (*param_4 < param_7) {
      *param_4 = (short)param_7;
    }
    if (*param_5 < iStack_4) {
      *param_5 = (short)iStack_4;
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c0c48
// Address: 004c0c48
// XREFS: None
byte __fastcall FUN_004c0c48(int param_1)
{
  short sVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  
  sVar1 = *(short *)(param_1 + 0x36);
  if (sVar1 == 0) {
    return *(byte *)(param_1 + 0x29);
  }
  bVar2 = 0x14;
  if (0 < sVar1) {
    piVar3 = (int *)(*(int *)(param_1 + 0x38) + 4);
    iVar4 = (int)sVar1;
    do {
      if (*(byte *)(*piVar3 + 0x29) < bVar2) {
        bVar2 = *(byte *)(*piVar3 + 0x29);
      }
      piVar3 = piVar3 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return bVar2;
}

// --------------------------------------------------

// Function: FUN_004c0c82
// Address: 004c0c82
// XREFS: None
uchar __thiscall
FUN_004c0c82(RGE_Sprite *param_1,short param_2,short param_3,int param_4,long param_5)
{
  RGE_Picture_List *pRVar1;
  RGE_Sprite *this;
  uchar uVar2;
  int iVar3;
  int iStack_4;
  
  iVar3 = 0;
  if ((((param_1->box_x1 != 0) || (param_1->box_x2 != 0)) &&
      ((param_1->box_y1 != 0 || (param_1->box_y2 != 0)))) &&
     ((((param_1->box_x1 <= param_2 && (param_2 <= param_1->box_x2)) && (param_1->box_y1 <= param_3)
       ) && (param_3 <= param_1->box_y2)))) {
    return '\x01';
  }
  if ((0 < param_1->draw_list_num) && (param_1->draw_list != (RGE_Picture_List *)0x0)) {
    iStack_4 = 0;
    if (0 < param_1->draw_list_num) {
      do {
        pRVar1 = param_1->draw_list;
        this = *(RGE_Sprite **)((int)&pRVar1->sprite + iVar3);
        uVar2 = RGE_Sprite::shape_hit_test
                          (this,param_2 - *(short *)((int)&pRVar1->offset_x + iVar3),
                           param_3 - *(short *)((int)&pRVar1->offset_y + iVar3),
                           (this->facet_num * param_4) / (int)param_1->facet_num,param_5);
        if (uVar2 != '\0') {
          return '\x01';
        }
        iVar3 = iVar3 + 0x10;
        iStack_4 = iStack_4 + 1;
      } while (iStack_4 < param_1->draw_list_num);
    }
    return '\0';
  }
  uVar2 = RGE_Sprite::shape_hit_test(param_1,param_2,param_3,param_4,param_5);
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_004c0d76
// Address: 004c0d76
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_sprite_cpp: "C:\msdev\work\age1_x1\sprite.cpp"
// [HELPER] s__shp: ".shp"
uchar __thiscall
FUN_004c0d76(RGE_Sprite *param_1,short param_2,short param_3,long param_4,long param_5)
{
  uchar uVar1;
  uchar uVar2;
  ulong uVar3;
  TShape *pTVar4;
  ulong uVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  char *pcStack_28;
  long lStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  TShape *pTStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f95b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_1->shape == (TShape *)0x0) {
    if (param_1->loaded == '\0') goto LAB_004c0f6e;
    pcStack_28 = (char *)0x0;
    addstring(&pcStack_28,param_1->pict_name,s__shp);
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x366);
    pTStack_10 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTStack_10 == (TShape *)0x0) {
      pTVar4 = (TShape *)0x0;
    }
    else {
      pTVar4 = (TShape *)TShape::TShape(pTStack_10,pcStack_28,param_1->resource_id);
    }
    uStack_4 = 0xffffffff;
    param_1->shape = pTVar4;
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x368);
    RGE_Base_Game::add_to_timing(rge_base_game,0xb,uVar5 - uVar3);
    free(pcStack_28);
  }
  if (param_1->frame_num < param_5) {
    param_5 = 0;
  }
  uVar1 = RGE_Sprite::get_facetindex(param_1,param_4,param_5,&lStack_24);
  uVar2 = param_1->transparent_picking_flag;
  if (uVar2 != '\0') {
    if (uVar2 == '\x01') {
      pTVar4 = param_1->shape;
      if (pTVar4 != (TShape *)0x0) {
        if (uVar1 == '\0') {
          uVar2 = TShape::shape_check(pTVar4,(int)param_2,(int)param_3,lStack_24);
          *unaff_FS_OFFSET = uStack_c;
          return uVar2;
        }
        uVar2 = TShape::shape_check(pTVar4,-(int)param_2,(int)param_3,lStack_24);
        *unaff_FS_OFFSET = uStack_c;
        return uVar2;
      }
    }
    else if ((uVar2 == '\x02') && (param_1->shape != (TShape *)0x0)) {
      TShape::shape_minmax(param_1->shape,&iStack_20,&iStack_18,&iStack_1c,&iStack_14,lStack_24);
      iVar6 = (int)param_2;
      if (uVar1 == '\0') {
        if (iVar6 < iStack_20) goto LAB_004c0f6e;
      }
      else {
        if (iVar6 < -iStack_1c) goto LAB_004c0f6e;
        iStack_1c = -iStack_20;
      }
      if (((iVar6 <= iStack_1c) && (iStack_18 <= param_3)) && (param_3 <= iStack_14)) {
        *unaff_FS_OFFSET = uStack_c;
        return '\x01';
      }
    }
  }
LAB_004c0f6e:
  *unaff_FS_OFFSET = uStack_c;
  return '\0';
}

// --------------------------------------------------

// Function: FUN_004c0f84
// Address: 004c0f84
// XREFS: None
undefined4 __fastcall FUN_004c0f84(RGE_Sprite *param_1)
{
  RGE_Active_Animated_Sprite *this;
  undefined4 uVar1;
  RGE_Active_Sprite *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f986;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if ((param_1->flag & 1) == 0) {
    this_00 = (RGE_Active_Sprite *)operator_new(0x14);
    uStack_4 = 1;
    if (this_00 != (RGE_Active_Sprite *)0x0) {
      uVar1 = RGE_Active_Sprite::RGE_Active_Sprite(this_00,param_1);
      *unaff_FS_OFFSET = uStack_c;
      return uVar1;
    }
  }
  else {
    this = (RGE_Active_Animated_Sprite *)operator_new(0x28);
    uStack_4 = 0;
    if (this != (RGE_Active_Animated_Sprite *)0x0) {
      uVar1 = RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(this,param_1);
      *unaff_FS_OFFSET = uStack_c;
      return uVar1;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c1025
// Address: 004c1025
// XREFS: None
undefined4 __fastcall FUN_004c1025(int param_1)
{
  short sVar1;
  int iVar2;
  int *piVar3;
  
  sVar1 = *(short *)(param_1 + 0x36);
  if ((sVar1 < 1) || (*(int *)(param_1 + 0x38) == 0)) {
    if (*(char *)(param_1 + 0x29) != '\0') {
      return 0;
    }
  }
  else {
    iVar2 = 0;
    if (sVar1 < 1) {
      return 0;
    }
    piVar3 = (int *)(*(int *)(param_1 + 0x38) + 4);
    while (*(char *)(*piVar3 + 0x29) != '\0') {
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 4;
      if (sVar1 <= iVar2) {
        return 0;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c1078
// Address: 004c1078
// XREFS: None
void __thiscall FUN_004c1078(int param_1,int param_2)
{
  TShape *this;
  int iVar1;
  
  if ((*(char *)(param_1 + 0x14) != '\0') &&
     (this = *(TShape **)(param_1 + 0x1c), this != (TShape *)0x0)) {
    if ((double)*(int *)(param_1 + 0x24) == DAT_00574524._4_8_) {
      *(int *)(param_1 + 0x20) = param_2;
      *(undefined4 *)(param_1 + 0x24) = 1;
      return;
    }
    iVar1 = *(int *)(param_1 + 0x20);
    *(int *)(param_1 + 0x20) = param_2;
    iVar1 = (param_2 - iVar1) + *(int *)(param_1 + 0x24);
    *(int *)(param_1 + 0x24) = iVar1;
    if (179999 < iVar1) {
      if (this != (TShape *)0x0) {
        TShape::~TShape(this);
        operator_delete(this);
      }
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c10fb
// Address: 004c10fb
// XREFS: None
RGE_Static_Object * __thiscall
FUN_004c10fb(RGE_Static_Object *param_1,RGE_Master_Static_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6,int param_7)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f9a6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->sprite = (RGE_Sprite *)0x0;
  param_1->old_sprite = (RGE_Sprite *)0x0;
  (param_1->pathingGroupMembers).value = (int *)0x0;
  (param_1->pathingGroupMembers).numberValue = 0;
  (param_1->pathingGroupMembers).desiredNumberValue = 0;
  (param_1->pathingGroupMembers).maximumSizeValue = 0;
  (param_1->groupMembers).value = (int *)0x0;
  (param_1->groupMembers).numberValue = 0;
  (param_1->groupMembers).desiredNumberValue = 0;
  (param_1->groupMembers).maximumSizeValue = 0;
  uStack_4 = 1;
  param_1->groupCommanderValue = -1;
  param_1->zoneMapIndex = -1;
  param_1->unitAIValue = (UnitAIModule *)0x0;
  param_1->groupRangeValue = 5.0;
  param_1->inObstructionMapValue = '\0';
  param_1->lastInObstructionMapValue = '\0';
  param_1->underAttackValue = '\0';
  param_1->_padding_ = (int)&RGE_Static_Object::_vftable_;
  param_1->player_object_node = (RGE_Object_Node *)0x0;
  if (param_7 != 0) {
    RGE_Static_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004c11b3
// Address: 004c11b3
// XREFS: None
RGE_Static_Object * __thiscall FUN_004c11b3(RGE_Static_Object *param_1,byte param_2)
{
  RGE_Static_Object::~RGE_Static_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004c11de
// Address: 004c11de
// XREFS: None
RGE_Static_Object * __thiscall
FUN_004c11de(RGE_Static_Object *param_1,int param_2,RGE_Game_World *param_3,int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f9c6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->sprite = (RGE_Sprite *)0x0;
  param_1->old_sprite = (RGE_Sprite *)0x0;
  (param_1->pathingGroupMembers).value = (int *)0x0;
  (param_1->pathingGroupMembers).numberValue = 0;
  (param_1->pathingGroupMembers).desiredNumberValue = 0;
  (param_1->pathingGroupMembers).maximumSizeValue = 0;
  (param_1->groupMembers).value = (int *)0x0;
  (param_1->groupMembers).numberValue = 0;
  (param_1->groupMembers).desiredNumberValue = 0;
  (param_1->groupMembers).maximumSizeValue = 0;
  uStack_4 = 1;
  param_1->groupCommanderValue = -1;
  param_1->zoneMapIndex = -1;
  param_1->unitAIValue = (UnitAIModule *)0x0;
  param_1->groupRangeValue = 5.0;
  param_1->inObstructionMapValue = '\0';
  param_1->lastInObstructionMapValue = '\0';
  param_1->underAttackValue = '\0';
  param_1->_padding_ = (int)&RGE_Static_Object::_vftable_;
  param_1->player_object_node = (RGE_Object_Node *)0x0;
  if (param_4 != 0) {
    RGE_Static_Object::setup(param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004c1284
// Address: 004c1284
// XREFS: None
void __fastcall FUN_004c1284(RGE_Static_Object *param_1)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_List *this;
  int *piVar2;
  RGE_Object_Node *pRVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  pcStack_8 = FUN_0055f9e6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&RGE_Static_Object::_vftable_;
  uStack_4 = 1;
  RGE_Static_Object::remove_visible_resource(param_1);
  if (param_1->owner != (RGE_Player *)0x0) {
    if (param_1->object_state < 3) {
      RGE_Static_Object::take_attribute_from_owner(param_1);
    }
    if (param_1->object_state < 7) {
      RGE_Victory_Conditions::update_for_object(param_1->owner->victory_conditions,param_1);
    }
  }
  if (param_1->sprite_list != (RGE_Active_Sprite_List *)0x0) {
    (**(code **)param_1->sprite_list->_padding_)(1);
    param_1->sprite_list = (RGE_Active_Sprite_List *)0x0;
  }
  if (param_1->owner != (RGE_Player *)0x0) {
    if ((param_1->selected & 1) != 0) {
      RGE_Player::unselect_one_object(param_1->owner,param_1);
    }
    (**(code **)(param_1->owner->_padding_ + 0xe0))
              (param_1,param_1->sleep_flag,param_1->dopple_flag,param_1->player_object_node);
    param_1->owner = (RGE_Player *)0x0;
  }
  if (param_1->tile != (RGE_Tile *)0x0) {
    RGE_Object_List::remove_node(&param_1->tile->objects,param_1,(RGE_Object_Node *)0x0);
    param_1->tile = (RGE_Tile *)0x0;
  }
  if ((param_1->master_obj != (RGE_Master_Static_Object *)0x0) &&
     ((float)(double)DAT_00574718 < param_1->master_obj->radius_z)) {
    RGE_Static_Object::removeFromObstructionMap(param_1,2);
  }
  if (param_1->inside_obj != (RGE_Static_Object *)0x0) {
    RGE_Object_List::remove_node(param_1->inside_obj->objects,param_1,(RGE_Object_Node *)0x0);
    param_1->inside_obj = (RGE_Static_Object *)0x0;
  }
  if (param_1->objects != (RGE_Object_List *)0x0) {
    pRVar3 = param_1->objects->list;
    while (pRVar3 != (RGE_Object_Node *)0x0) {
      pRVar1 = pRVar3->next;
      (**(code **)(pRVar3->node->_padding_ + 0xd4))();
      pRVar3 = pRVar1;
    }
    this = param_1->objects;
    if (this != (RGE_Object_List *)0x0) {
      RGE_Object_List::~RGE_Object_List(this);
      operator_delete(this);
    }
  }
  if (param_1->unitAIValue != (UnitAIModule *)0x0) {
    (**(code **)param_1->unitAIValue->_padding_)(1);
    param_1->unitAIValue = (UnitAIModule *)0x0;
  }
  piVar2 = (param_1->groupMembers).value;
  uStack_4 = uStack_4 & 0xffffff00;
  if (piVar2 != (int *)0x0) {
    operator_delete(piVar2);
    (param_1->groupMembers).value = (int *)0x0;
  }
  (param_1->groupMembers).numberValue = 0;
  (param_1->groupMembers).desiredNumberValue = 0;
  (param_1->groupMembers).maximumSizeValue = 0;
  piVar2 = (param_1->pathingGroupMembers).value;
  uStack_4 = 0xffffffff;
  if (piVar2 != (int *)0x0) {
    operator_delete(piVar2);
    (param_1->pathingGroupMembers).value = (int *)0x0;
  }
  (param_1->pathingGroupMembers).numberValue = 0;
  (param_1->pathingGroupMembers).desiredNumberValue = 0;
  (param_1->pathingGroupMembers).maximumSizeValue = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004c1414
// Address: 004c1414
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_stat_obj_c: "C:\msdev\work\age1_x1\stat_obj.cpp"
void __thiscall
FUN_004c1414(RGE_Static_Object *param_1,RGE_Master_Static_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5)
{
  int iVar1;
  RGE_Sound *this;
  RGE_Object_Node *pRVar2;
  uint uVar3;
  float fVar4;
  
  param_1->old_sprite = (RGE_Sprite *)0x0;
  param_1->unitAIValue = (UnitAIModule *)0x0;
  param_1->underAttackValue = '\0';
  param_1->sprite = (RGE_Sprite *)0x0;
  param_1->groupCommanderValue = -1;
  param_1->groupRangeValue = 5.0;
  param_1->owner = param_3;
  param_1->master_obj = param_2;
  param_1->tile = (RGE_Tile *)0x0;
  param_1->inside_obj = (RGE_Static_Object *)0x0;
  fVar4 = (float)(int)param_2->hp;
  param_1->hp = (float)(int)fVar4;
  param_1->sleep_flag = DAT_00574718._8_4_ < (float)(int)fVar4;
  param_1->dopple_flag = param_2->master_type == '\x19';
  param_1->facet = '\0';
  param_1->world_x = -999.0;
  param_1->world_y = -999.0;
  param_1->world_z = 0.0;
  param_1->screen_x_offset = 0;
  param_1->screen_y_offset = 0;
  param_1->shadow_x_offset = 0;
  param_1->shadow_y_offset = 0;
  param_1->selected = '\0';
  param_1->selected_group = '\0';
  param_1->worker_num = '\0';
  param_1->object_state = '\x02';
  param_1->curr_damage_percent = '\0';
  param_1->goto_sleep_flag = '\0';
  param_1->player_object_node = (RGE_Object_Node *)0x0;
  RGE_Static_Object::get_starting_attribute(param_1);
  RGE_Static_Object::give_attribute_to_owner(param_1);
  iVar1 = param_1->_padding_;
  (**(code **)(iVar1 + 0x38))(param_1->master_obj->sprite);
  param_1->world_x = fVar4;
  param_1->world_z = param_5;
  param_1->world_y = param_4;
  param_1->old_sprite = (RGE_Sprite *)0x0;
  (**(code **)(iVar1 + 0x34))(fVar4,param_4,param_5);
  pRVar2 = (RGE_Object_Node *)
           (**(code **)(param_1->owner->_padding_ + 0xdc))
                     (param_1,param_1->sleep_flag,param_1->dopple_flag);
  param_1->player_object_node = pRVar2;
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x183);
  iVar1 = debug_random_on;
  debug_random_on = 0;
  this = param_1->master_obj->created_sound;
  if ((this != (RGE_Sound *)0x0) && (param_1->owner->id == param_1->owner->world->curr_player)) {
    RGE_Sound::play(this,1);
  }
  debug_random_on = iVar1;
  debug_srand(s_C__msdev_work_age1_x1_stat_obj_c,0x18d,uVar3);
  return;
}

// --------------------------------------------------

// Function: FUN_004c1589
// Address: 004c1589
// XREFS: None
void __fastcall FUN_004c1589(RGE_Static_Object *param_1)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_Node *pRVar2;
  uchar uVar3;
  
  if ((param_1->master_obj->recyclable != '\0') &&
     (uVar3 = RGE_Game_World::recycle_object_out_of_game
                        (param_1->owner->world,param_1->master_obj->master_type,param_1),
     uVar3 != '\0')) {
    if (param_1->object_state < 3) {
      RGE_Static_Object::take_attribute_from_owner(param_1);
    }
    if (param_1->object_state < 7) {
      RGE_Victory_Conditions::update_for_object(param_1->owner->victory_conditions,param_1);
    }
    if (param_1->sprite_list != (RGE_Active_Sprite_List *)0x0) {
      RGE_Active_Sprite_List::delete_list(param_1->sprite_list);
    }
    if (param_1->owner != (RGE_Player *)0x0) {
      if ((param_1->selected & 1) != 0) {
        RGE_Player::unselect_one_object(param_1->owner,param_1);
      }
      (**(code **)(param_1->owner->_padding_ + 0xe0))
                (param_1,param_1->sleep_flag,param_1->dopple_flag,param_1->player_object_node);
      param_1->owner = (RGE_Player *)0x0;
    }
    if (param_1->tile != (RGE_Tile *)0x0) {
      RGE_Object_List::remove_node(&param_1->tile->objects,param_1,(RGE_Object_Node *)0x0);
      param_1->tile = (RGE_Tile *)0x0;
    }
    if (param_1->inside_obj != (RGE_Static_Object *)0x0) {
      RGE_Object_List::remove_node(param_1->inside_obj->objects,param_1,(RGE_Object_Node *)0x0);
      param_1->inside_obj = (RGE_Static_Object *)0x0;
    }
    if (param_1->objects != (RGE_Object_List *)0x0) {
      pRVar2 = param_1->objects->list;
      while (pRVar2 != (RGE_Object_Node *)0x0) {
        pRVar1 = pRVar2->next;
        (**(code **)(pRVar2->node->_padding_ + 0xd4))();
        pRVar2 = pRVar1;
      }
    }
    if (param_1->unitAIValue != (UnitAIModule *)0x0) {
      (**(code **)param_1->unitAIValue->_padding_)(1);
      param_1->unitAIValue = (UnitAIModule *)0x0;
    }
    if ((param_1->master_obj != (RGE_Master_Static_Object *)0x0) &&
       ((float)(double)DAT_00574718 < param_1->master_obj->radius_z)) {
      RGE_Static_Object::removeFromObstructionMap(param_1,2);
    }
    param_1->master_obj = (RGE_Master_Static_Object *)0x0;
    return;
  }
  if (param_1 != (RGE_Static_Object *)0x0) {
    (**(code **)param_1->_padding_)(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c16ad
// Address: 004c16ad
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_stat_obj_c: "C:\msdev\work\age1_x1\stat_obj.cpp"
undefined4 __thiscall
FUN_004c16ad(RGE_Static_Object *param_1,RGE_Master_Static_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5)
{
  int iVar1;
  RGE_Sound *this;
  RGE_Object_List *pRVar2;
  long lVar3;
  RGE_Active_Sprite_List *pRVar4;
  RGE_Object_Node *pRVar5;
  uint uVar6;
  float fVar7;
  
  iVar1 = param_1->_padding_;
  param_1->master_obj = param_2;
  param_1->type = '\n';
  param_1->owner = param_3;
  param_1->tile = (RGE_Tile *)0x0;
  param_1->inside_obj = (RGE_Static_Object *)0x0;
  pRVar2 = (RGE_Object_List *)(**(code **)(iVar1 + 0x1e0))();
  param_1->objects = pRVar2;
  fVar7 = (float)(int)param_1->master_obj->hp;
  param_1->hp = (float)(int)fVar7;
  param_1->sleep_flag = DAT_00574718._8_4_ < (float)(int)fVar7;
  param_1->dopple_flag = param_1->master_obj->master_type == '\x19';
  param_1->facet = '\0';
  param_1->world_x = -999.0;
  param_1->world_y = -999.0;
  param_1->world_z = 0.0;
  param_1->screen_x_offset = 0;
  param_1->screen_y_offset = 0;
  param_1->shadow_x_offset = 0;
  param_1->shadow_y_offset = 0;
  param_1->selected = '\0';
  param_1->selected_group = '\0';
  param_1->worker_num = '\0';
  param_1->object_state = '\x02';
  param_1->curr_damage_percent = '\0';
  param_1->goto_sleep_flag = '\0';
  RGE_Static_Object::get_starting_attribute(param_1);
  RGE_Static_Object::give_attribute_to_owner(param_1);
  if (param_1->master_obj->recyclable == '\0') {
    lVar3 = RGE_Game_World::get_next_object_id(param_1->owner->world);
  }
  else {
    lVar3 = RGE_Game_World::get_next_reusable_object_id(param_1->owner->world);
  }
  param_1->id = lVar3;
  pRVar4 = (RGE_Active_Sprite_List *)(**(code **)(iVar1 + 0x1e4))();
  param_1->sprite_list = pRVar4;
  (**(code **)(iVar1 + 0x38))(param_1->master_obj->sprite);
  param_1->world_x = fVar7;
  param_1->world_z = param_5;
  param_1->world_y = param_4;
  param_1->old_sprite = (RGE_Sprite *)0x0;
  (**(code **)(iVar1 + 0x34))(fVar7,param_4,param_5);
  pRVar5 = (RGE_Object_Node *)
           (**(code **)(param_1->owner->_padding_ + 0xdc))
                     (param_1,param_1->sleep_flag,param_1->dopple_flag);
  param_1->player_object_node = pRVar5;
  uVar6 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x22a);
  iVar1 = debug_random_on;
  debug_random_on = 0;
  this = param_1->master_obj->created_sound;
  if ((this != (RGE_Sound *)0x0) && (param_1->owner->id == param_1->owner->world->curr_player)) {
    RGE_Sound::play(this,1);
  }
  debug_random_on = iVar1;
  debug_srand(s_C__msdev_work_age1_x1_stat_obj_c,0x235,uVar6);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c183e
// Address: 004c183e
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004c183e(RGE_Static_Object *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  RGE_Active_Sprite_List *this;
  RGE_Object_List *pRVar6;
  int iStack_18;
  int iStack_14;
  uint uStack_10;
  RGE_Static_Object *pRStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar2 = param_2;
  param_1->type = '\n';
  rge_read(param_2,&uStack_10,1);
  iVar1 = param_3;
  param_1->owner = *(RGE_Player **)(*(int *)(param_3 + 0x40) + (uStack_10 & 0xff) * 4);
  rge_read(iVar2,&param_2,2);
  param_1->master_obj = param_1->owner->master_objects[(short)param_2];
  rge_read(iVar2,&param_2,2);
  if ((short)param_2 < 0) {
    param_1->sprite = (RGE_Sprite *)0x0;
  }
  else {
    param_1->sprite = *(RGE_Sprite **)(*(int *)(iVar1 + 0x38) + (short)param_2 * 4);
  }
  param_1->old_sprite = (RGE_Sprite *)0x0;
  rge_read(iVar2,&pRStack_c,4);
  if (pRStack_c == (RGE_Static_Object *)0xffffffff) {
    param_1->inside_obj = (RGE_Static_Object *)0x0;
  }
  else {
    param_1->inside_obj = pRStack_c;
  }
  rge_read(iVar2,&param_1->hp,4);
  rge_read(iVar2,&param_1->object_state,1);
  rge_read(iVar2,&param_1->sleep_flag,1);
  if (_DAT_00574724 <= save_game_version) {
    rge_read(iVar2,&param_1->dopple_flag,1);
  }
  rge_read(iVar2,&param_1->goto_sleep_flag,1);
  rge_read(iVar2,&param_1->id,4);
  rge_read(iVar2,&param_1->facet,1);
  rge_read(iVar2,&param_1->world_x,4);
  rge_read(iVar2,&param_1->world_y,4);
  rge_read(iVar2,&param_1->world_z,4);
  rge_read(iVar2,&param_1->screen_x_offset,2);
  rge_read(iVar2,&param_1->screen_y_offset,2);
  rge_read(iVar2,&param_1->shadow_x_offset,2);
  rge_read(iVar2,&param_1->shadow_y_offset,2);
  rge_read(iVar2,&param_1->selected_group,1);
  rge_read(iVar2,&param_1->attribute_type_held,2);
  rge_read(iVar2,&param_1->attribute_amount_held,4);
  rge_read(iVar2,&param_1->worker_num,1);
  rge_read(iVar2,&param_1->curr_damage_percent,1);
  rge_read(iVar2,&param_1->underAttackValue,1);
  param_1->tile = (RGE_Tile *)0x0;
  rge_read(iVar2,&param_1->groupCommanderValue,4);
  rge_read(iVar2,&param_1->groupRangeValue,4);
  if (save_game_version == _DAT_00574728) {
    rge_read(iVar2,&iStack_18,4);
    rge_read(iVar2,&iStack_18,4);
    rge_read(iVar2,&iStack_18,4);
    rge_read(iVar2,&iStack_4,4);
    rge_read(iVar2,&iStack_8,4);
    rge_read(iVar2,&iStack_8,4);
  }
  rge_read(iVar2,&iStack_14,4);
  iStack_18 = 0;
  if (0 < iStack_14) {
    do {
      rge_read(iVar2,&iStack_8,4);
      iVar1 = (param_1->groupMembers).numberValue;
      iVar3 = 0;
      iStack_4 = iStack_8;
      if (0 < iVar1) {
        do {
          if ((param_1->groupMembers).maximumSizeValue <= iVar3) break;
          if ((param_1->groupMembers).value[iVar3] == iStack_8) goto LAB_004c1b80;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar1);
      }
      if ((param_1->groupMembers).maximumSizeValue + -1 < iVar1) {
        iVar1 = iVar1 + 1;
        piVar4 = (int *)operator_new(iVar1 * 4);
        if (piVar4 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (param_1->groupMembers).maximumSizeValue) {
            do {
              if (iVar1 <= iVar3) break;
              iVar5 = iVar3 + 1;
              piVar4[iVar3] = (param_1->groupMembers).value[iVar3];
              iVar3 = iVar5;
            } while (iVar5 < (param_1->groupMembers).maximumSizeValue);
          }
          operator_delete((param_1->groupMembers).value);
          (param_1->groupMembers).value = piVar4;
          (param_1->groupMembers).maximumSizeValue = iVar1;
        }
      }
      (param_1->groupMembers).value[(param_1->groupMembers).numberValue] = iStack_4;
      (param_1->groupMembers).numberValue = (param_1->groupMembers).numberValue + 1;
LAB_004c1b80:
      iStack_18 = iStack_18 + 1;
    } while (iStack_18 < iStack_14);
  }
  rge_read(iVar2,&iStack_14,4);
  iStack_18 = 0;
  if (0 < iStack_14) {
    do {
      rge_read(iVar2,&iStack_4,4);
      iVar1 = (param_1->pathingGroupMembers).numberValue;
      iVar3 = 0;
      iStack_8 = iStack_4;
      if (0 < iVar1) {
        do {
          if ((param_1->pathingGroupMembers).maximumSizeValue <= iVar3) break;
          if ((param_1->pathingGroupMembers).value[iVar3] == iStack_4) goto LAB_004c1c56;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar1);
      }
      if ((param_1->pathingGroupMembers).maximumSizeValue + -1 < iVar1) {
        iVar1 = iVar1 + 1;
        piVar4 = (int *)operator_new(iVar1 * 4);
        if (piVar4 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (param_1->pathingGroupMembers).maximumSizeValue) {
            do {
              if (iVar1 <= iVar3) break;
              iVar5 = iVar3 + 1;
              piVar4[iVar3] = (param_1->pathingGroupMembers).value[iVar3];
              iVar3 = iVar5;
            } while (iVar5 < (param_1->pathingGroupMembers).maximumSizeValue);
          }
          operator_delete((param_1->pathingGroupMembers).value);
          (param_1->pathingGroupMembers).value = piVar4;
          (param_1->pathingGroupMembers).maximumSizeValue = iVar1;
        }
      }
      (param_1->pathingGroupMembers).value[(param_1->pathingGroupMembers).numberValue] = iStack_8;
      (param_1->pathingGroupMembers).numberValue = (param_1->pathingGroupMembers).numberValue + 1;
LAB_004c1c56:
      iStack_18 = iStack_18 + 1;
    } while (iStack_18 < iStack_14);
  }
  iVar1 = param_1->_padding_;
  this = (RGE_Active_Sprite_List *)(**(code **)(iVar1 + 0x1e4))();
  param_1->sprite_list = this;
  RGE_Active_Sprite_List::load(this,iVar2,*(RGE_Sprite ***)(param_3 + 0x38));
  (**(code **)(param_1->owner->world->_padding_ + 0xf8))(param_1);
  if (param_1->sleep_flag == '\0') {
    if (param_1->dopple_flag == '\0') {
      pRVar6 = param_1->owner->objects;
    }
    else {
      pRVar6 = param_1->owner->doppleganger_objects;
    }
  }
  else {
    pRVar6 = param_1->owner->sleeping_objects;
  }
  RGE_Object_List::add_node(pRVar6,param_1);
  pRVar6 = (RGE_Object_List *)(**(code **)(iVar1 + 0x1e0))();
  param_1->objects = pRVar6;
  param_1->selected = '\0';
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c1ce7
// Address: 004c1ce7
// XREFS: None
void __fastcall FUN_004c1ce7(int param_1)
{
  long lVar1;
  undefined4 uVar2;
  
  (**(code **)(**(int **)(param_1 + 0xc) + 0xe0))
            (param_1,*(undefined1 *)(param_1 + 0x49),*(undefined1 *)(param_1 + 0x4a),
             *(undefined4 *)(param_1 + 0x50));
  if (*(char *)(*(int *)(param_1 + 8) + 0xa4) == '\0') {
    lVar1 = RGE_Game_World::get_next_object_id(*(RGE_Game_World **)(*(int *)(param_1 + 0xc) + 0x3c))
    ;
  }
  else {
    lVar1 = RGE_Game_World::get_next_reusable_object_id
                      (*(RGE_Game_World **)(*(int *)(param_1 + 0xc) + 0x3c));
  }
  *(long *)(param_1 + 4) = lVar1;
  uVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0xdc))
                    (param_1,*(undefined1 *)(param_1 + 0x49),*(undefined1 *)(param_1 + 0x4a));
  *(undefined4 *)(param_1 + 0x50) = uVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_004c1d54
// Address: 004c1d54
// XREFS: None
undefined4 FUN_004c1d54(void)
{
  RGE_Object_List *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f9fb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Object_List *)operator_new(0xc);
  uStack_4 = 0;
  if (this != (RGE_Object_List *)0x0) {
    uVar1 = RGE_Object_List::RGE_Object_List(this);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c1db7
// Address: 004c1db7
// XREFS: None
undefined4 __fastcall FUN_004c1db7(RGE_Static_Object *param_1)
{
  RGE_Active_Sprite_List *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fa1b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Active_Sprite_List *)operator_new(0xc);
  uStack_4 = 0;
  if (this != (RGE_Active_Sprite_List *)0x0) {
    uVar1 = RGE_Active_Sprite_List::RGE_Active_Sprite_List(this,param_1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c1e1d
// Address: 004c1e1d
// XREFS: None
void __fastcall FUN_004c1e1d(int param_1)
{
  short *psVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  
  iVar2 = *(int *)(param_1 + 8);
  *(undefined2 *)(param_1 + 0x4c) = 0xffff;
  *(undefined4 *)(param_1 + 0x44) = 0;
  pcVar4 = (char *)(iVar2 + 0x88);
  puVar3 = (undefined4 *)(iVar2 + 0x70);
  psVar1 = (short *)(iVar2 + 0x6a);
  iVar2 = 3;
  do {
    if ((*pcVar4 == '\0') && (*psVar1 != -1)) {
      *(short *)(param_1 + 0x4c) = *psVar1;
      *(undefined4 *)(param_1 + 0x44) = *puVar3;
    }
    psVar1 = psVar1 + 1;
    puVar3 = puVar3 + 1;
    pcVar4 = pcVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_004c1e69
// Address: 004c1e69
// XREFS: None
void __fastcall FUN_004c1e69(int param_1)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_4;
  
  iVar4 = 0;
  uStack_4 = 0x6a;
  iVar3 = 0x70;
  do {
    iVar2 = *(int *)(param_1 + 8);
    bVar1 = *(byte *)(iVar4 + 0x88 + iVar2);
    if (((bVar1 != 0) && (bVar1 < 3)) && (-1 < *(short *)(uStack_4 + iVar2))) {
      (**(code **)(**(int **)(param_1 + 0xc) + 0x78))
                (*(short *)(uStack_4 + iVar2),*(undefined4 *)(iVar3 + iVar2),0);
    }
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
    uStack_4 = uStack_4 + 2;
  } while (iVar3 < 0x7c);
  return;
}

// --------------------------------------------------

// Function: FUN_004c1f26
// Address: 004c1f26
// XREFS: None
void __thiscall
FUN_004c1f26(RGE_Static_Object *param_1,TDrawArea *param_2,short param_3,short param_4,
            undefined4 param_5)
{
  SDI_Object_ID = param_1->id;
  if (param_1->type == '\x19') {
    if (((uint)param_1[1].tile & 1 << ((byte)param_1->owner->world->curr_player & 0x1f)) != 0) {
      SDI_Object_ID = -1;
      return;
    }
    if (param_1[1].id == 0) {
      SDI_Object_ID = -1;
    }
    else {
      SDI_Object_ID = *(long *)(param_1[1].id + 4);
    }
  }
  if ((param_1->tile != (RGE_Tile *)0x0) && (param_1->object_state < 7)) {
    if (((param_1->selected != '\0') || (rge_base_game->outline_type == '\x03')) ||
       (((param_1->master_obj->draw_flag & 1) == 1 && (rge_base_game->prog_mode == 7)))) {
      RGE_Static_Object::capture_frame(param_1,param_2,param_3,param_4);
    }
    SDI_Draw_Line = (int)param_4 + (int)param_1->shadow_y_offset;
    (**(code **)(param_1->sprite_list->_padding_ + 0xc))
              (param_1->facet,param_1->screen_x_offset + param_3,param_1->screen_y_offset + param_4,
               param_1->shadow_x_offset + param_3,param_4 + param_1->shadow_y_offset,param_5,param_2
              );
  }
  SDI_Object_ID = -1;
  return;
}

// --------------------------------------------------

// Function: FUN_004c202f
// Address: 004c202f
// XREFS: None
void __thiscall
FUN_004c202f(int param_1,undefined4 param_2,short param_3,short param_4,undefined4 param_5)
{
  undefined4 uVar1;
  undefined2 uVar2;
  
  if ((*(int *)(param_1 + 0x1c) != 0) && (*(byte *)(param_1 + 0x48) < 7)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x108);
    uVar2 = (undefined2)((uint)uVar1 >> 0x10);
    (**(code **)(**(int **)(param_1 + 0x18) + 0x14))
              (*(undefined1 *)(param_1 + 0x35),CONCAT22(uVar2,*(short *)(param_1 + 0x2c) + param_3),
               CONCAT22(uVar2,*(short *)(param_1 + 0x2e) + param_4),uVar1,param_2,param_5);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c207a
// Address: 004c207a
// XREFS: None
void __thiscall FUN_004c207a(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  bool bVar1;
  undefined2 uVar2;
  undefined4 unaff_EBP;
  
  if ((param_1[7] != 0) && (*(byte *)(param_1 + 0x12) < 7)) {
    if ((*(char *)((int)param_1 + 0x36) == '\0') && (rge_base_game->outline_type != '\x03')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      (**(code **)(*param_1 + 0x1c))(param_2,param_3,param_4);
    }
    uVar2 = (undefined2)((uint)*(undefined4 *)(param_1[3] + 0x108) >> 0x10);
    (**(code **)(*(int *)param_1[6] + 0x10))
              (CONCAT22(uVar2,(ushort)*(byte *)((int)param_1 + 0x35)),
               CONCAT22(uVar2,(short)param_1[10] + (short)param_3),
               CONCAT22(uVar2,*(short *)((int)param_1 + 0x2a) + (short)param_4),
               *(undefined4 *)(param_1[3] + 0x108),param_2);
    if (bVar1) {
      (**(code **)(*param_1 + 0x18))(param_2,param_3,unaff_EBP);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c2109
// Address: 004c2109
// XREFS: None
void __thiscall
FUN_004c2109(RGE_Static_Object *param_1,TDrawArea *param_2,undefined4 param_3,undefined4 param_4)
{
  short sVar1;
  short sVar2;
  
  sVar1 = (short)param_3;
  sVar2 = (short)param_4;
  if (rge_base_game->game_mode != 1) {
    switch(rge_base_game->outline_type) {
    case '\0':
      (**(code **)(param_1->_padding_ + 0x20))(param_2,param_3,param_4);
      return;
    case '\x01':
      RGE_Static_Object::draw_frame_3d_cube_front(param_1,param_2,sVar1,sVar2);
      return;
    case '\x02':
    case '\x03':
      RGE_Static_Object::draw_frame_3d_square_front(param_1,param_2,sVar1,sVar2);
    }
    return;
  }
  RGE_Static_Object::draw_frame_3d_cube_front(param_1,param_2,sVar1,sVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_004c218d
// Address: 004c218d
// XREFS: None
void __fastcall
FUN_004c218d(RGE_Static_Object *param_1,short param_2,TDrawArea *param_3,TDrawArea *param_4,
            short param_5)
{
  uint *puVar1;
  int in_EAX;
  int iVar2;
  short unaff_retaddr;
  short sVar3;
  
  iVar2 = in_EAX + -1;
  puVar1 = (uint *)(in_EAX + 0x5e + iVar2);
  *puVar1 = *puVar1 & (uint)param_1;
  puVar1 = (uint *)(in_EAX + 0x75 + iVar2);
  *puVar1 = *puVar1 & (uint)param_1;
  puVar1 = (uint *)(in_EAX + 0x75 + iVar2);
  *puVar1 = *puVar1 & (uint)param_1;
  puVar1 = (uint *)(in_EAX + -0x60 + iVar2);
  *puVar1 = *puVar1 & (uint)param_1;
  if (*puVar1 == 0) {
    RGE_Static_Object::draw_frame_3d_cube_front(param_1,param_4,param_2,unaff_retaddr);
    return;
  }
  sVar3 = (short)param_4;
  if (*(int *)(in_EAX + 0x1b3) == 1) {
    RGE_Static_Object::draw_frame_3d_cube_back(param_1,param_3,sVar3,param_5);
    return;
  }
  switch(*(undefined1 *)(in_EAX + 0x4f)) {
  case 1:
    RGE_Static_Object::draw_frame_3d_cube_back(param_1,param_3,sVar3,param_5);
    return;
  case 2:
  case 3:
    RGE_Static_Object::draw_frame_3d_square_back(param_1,param_3,sVar3,param_5);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c2206
// Address: 004c2206
// XREFS: None
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */

void __fastcall FUN_004c2206(RGE_Static_Object *param_1,int *param_2)
{
  uint *puVar1;
  int iVar2;
  undefined4 in_EAX;
  int iVar3;
  char unaff_BL;
  undefined4 auStack_11 [2];
  short asStack_9 [2];
  undefined4 uStack_5;
  
  iVar2 = *param_2;
  iVar3 = CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX + unaff_BL);
  puVar1 = (uint *)(iVar3 * 2 + -0x11);
  *puVar1 = *puVar1 & (uint)param_1;
  puVar1 = (uint *)(iVar3 * 2 + -0x11);
  *puVar1 = *puVar1 & (uint)param_1;
  puVar1 = (uint *)(iVar3 * 2 + -0x70);
  *puVar1 = *puVar1 & (uint)param_1;
  if (SDI_Capture_Info != 0) {
    if (rge_base_game->game_mode == 1) {
      *(undefined4 *)((int)&uStack_5 + iVar2) = *(undefined4 *)(&stack0x0000000b + iVar2);
      *(undefined4 *)((int)asStack_9 + iVar2) = *(undefined4 *)(&stack0x00000007 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2 + 4) = *(undefined4 *)(&stack0x00000003 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2) = 0x4c224b;
      RGE_Static_Object::capture_frame_3d_cube
                (param_1,*(TDrawArea **)((int)auStack_11 + iVar2 + 4),
                 *(short *)((int)asStack_9 + iVar2),*(short *)((int)&uStack_5 + iVar2));
      return;
    }
    switch(rge_base_game->outline_type) {
    case '\0':
      *(undefined4 *)((int)&uStack_5 + iVar2) = *(undefined4 *)(&stack0x0000000b + iVar2);
      *(undefined4 *)((int)asStack_9 + iVar2) = *(undefined4 *)(&stack0x00000007 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2 + 4) = *(undefined4 *)(&stack0x00000003 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2) = 0x4c2275;
      RGE_Static_Object::capture_square_frame
                (param_1,*(TDrawArea **)((int)auStack_11 + iVar2 + 4),
                 *(short *)((int)asStack_9 + iVar2),*(short *)((int)&uStack_5 + iVar2));
      return;
    case '\x01':
      *(undefined4 *)((int)&uStack_5 + iVar2) = *(undefined4 *)(&stack0x0000000b + iVar2);
      *(undefined4 *)((int)asStack_9 + iVar2) = *(undefined4 *)(&stack0x00000007 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2 + 4) = *(undefined4 *)(&stack0x00000003 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2) = 0x4c228c;
      RGE_Static_Object::capture_frame_3d_cube
                (param_1,*(TDrawArea **)((int)auStack_11 + iVar2 + 4),
                 *(short *)((int)asStack_9 + iVar2),*(short *)((int)&uStack_5 + iVar2));
      return;
    case '\x02':
    case '\x03':
      *(undefined4 *)((int)&uStack_5 + iVar2) = *(undefined4 *)(&stack0x0000000b + iVar2);
      *(undefined4 *)((int)asStack_9 + iVar2) = *(undefined4 *)(&stack0x00000007 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2 + 4) = *(undefined4 *)(&stack0x00000003 + iVar2);
      *(undefined4 *)((int)auStack_11 + iVar2) = 0x4c22a3;
      RGE_Static_Object::capture_frame_3d_square
                (param_1,*(TDrawArea **)((int)auStack_11 + iVar2 + 4),
                 *(short *)((int)asStack_9 + iVar2),*(short *)((int)&uStack_5 + iVar2));
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c22a6
// Address: 004c22a6
// XREFS: None
void FUN_004c22a6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,int param_8,short param_9)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *this;
  int iVar3;
  int iVar4;
  
  this = (RGE_Static_Object *)
         CONCAT31((int3)((uint)param_6 >> 8),
                  (byte)param_6 & *(byte *)(param_7 * 2 + 0x78) & *(byte *)(param_7 * 2 + -0x71) &
                  *(byte *)(param_7 * 2 + -0x71) & *(byte *)(param_7 * 2 + -0x70));
  param_5 = param_4;
  param_4 = param_2;
  param_3 = param_1;
  if ((this->sprite != (RGE_Sprite *)0x0) && (this->sprite_list != (RGE_Active_Sprite_List *)0x0)) {
    (**(code **)(this->sprite_list->_padding_ + 0x28))();
    iVar2 = RGE_Static_Object::get_frame
                      (this,(short *)&param_4,(short *)((int)&param_4 + 2),
                       (short *)((int)register0x00000010 + 0x16),(short *)&param_5);
    if (iVar2 != 0) {
      iVar3 = (int)(short)param_8;
      iVar2 = (short)param_4 + iVar3 + -1 + (int)this->screen_x_offset;
      iVar1 = (int)param_4._2_2_ + (int)param_9 + -1 + (int)this->screen_y_offset;
      param_8 = (int)(short)param_5 + (int)param_9 + 1 + (int)this->screen_y_offset;
      DClipInfo_List::AddGDINode
                (SDI_List,4,param_8,iVar2,iVar1,
                 param_5._2_2_ + iVar3 + 1 + (int)this->screen_x_offset,param_8,0,0,0,0,10,0xff,
                 SDI_Object_ID);
      if (this->object_state < 3) {
        iVar3 = __ftol();
        if (iVar3 < 1) {
          iVar3 = 0;
        }
        iVar4 = (int)this->master_obj->hp;
        if (0 < iVar4) {
          iVar3 = (iVar3 * 0x19) / iVar4 + iVar2;
          if (iVar2 + 0x1a <= iVar3) {
            iVar3 = iVar2 + 0x19;
          }
          DClipInfo_List::AddGDINode
                    (SDI_List,2,param_8,iVar2,iVar1 + -6,iVar2 + 0x1a,iVar1 + -1,iVar3,0,iVar3 + 1,0
                     ,0x14,0xff,SDI_Object_ID);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c23ee
// Address: 004c23ee
// XREFS: None
void FUN_004c23ee(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004c23f3
// Address: 004c23f3
// XREFS: None
void __thiscall FUN_004c23f3(int param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  RGE_Map *this;
  TShape *pTVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  short sVar7;
  short sVar8;
  uint uStack_54;
  int iStack_50;
  float fStack_4c;
  int iStack_48;
  int iStack_44;
  undefined4 uStack_40;
  float fStack_3c;
  float fStack_38;
  int iStack_34;
  float fStack_30;
  float fStack_2c;
  int iStack_28;
  RGE_Map *pRStack_24;
  int iStack_20;
  int iStack_1c;
  int aiStack_18 [4];
  int iStack_8;
  
  iVar3 = *(int *)(param_1 + 8);
  this = *(RGE_Map **)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28);
  if (rge_base_game->outline_type == '\x03') {
    fStack_4c = *(float *)(iVar3 + 0x30);
    fStack_3c = *(float *)(iVar3 + 0x34);
    fStack_2c = *(float *)(iVar3 + 0x38);
  }
  else {
    fStack_4c = *(float *)(iVar3 + 0xac);
    fStack_3c = *(float *)(iVar3 + 0xb0);
    fStack_2c = *(float *)(iVar3 + 0xb4);
  }
  if (((startLoggingAI == 1) && (*(int *)(param_1 + 0x78) == *(int *)(param_1 + 4))) &&
     (-1 < *(int *)(param_1 + 4))) {
    uStack_54 = 0;
    goto LAB_004c24b2;
  }
  if ((*(byte *)(param_1 + 0x36) & 1) == 0) {
    if (rge_base_game->outline_type == '\x03') {
      uStack_54 = 0x74;
      goto LAB_004c24b2;
    }
    if (((*(byte *)(iVar3 + 0xa8) & 1) == 1) && (rge_base_game->prog_mode == 7)) {
      uStack_54 = (uint)*(byte *)(iVar3 + 0xa9);
      goto LAB_004c24b2;
    }
  }
  uStack_54 = 0xff;
LAB_004c24b2:
  if ((*(byte *)(param_1 + 0x36) & 2) != 0) {
    uStack_54 = 0x4a;
  }
  if ((*(byte *)(param_1 + 0x36) & 4) != 0) {
    uStack_54 = 0x97;
  }
  fStack_38 = -fStack_3c;
  sVar8 = (short)param_4 + *(short *)(param_1 + 0x2a);
  sVar7 = (short)param_3 + *(short *)(param_1 + 0x28);
  pRStack_24 = this;
  RGE_Map::get_point(this,(short *)&iStack_28,(short *)&iStack_34,fStack_4c,fStack_38,0.0,sVar7,
                     sVar8);
  RGE_Map::get_point(this,(short *)&param_4,(short *)&iStack_50,fStack_4c,fStack_3c,0.0,sVar7,sVar8)
  ;
  fStack_30 = -fStack_4c;
  RGE_Map::get_point(this,(short *)&iStack_48,(short *)&uStack_40,fStack_30,fStack_3c,0.0,sVar7,
                     sVar8);
  RGE_Map::get_point(this,(short *)&iStack_44,(short *)&param_3,fStack_30,fStack_38,0.0,sVar7,sVar8)
  ;
  fStack_30 = (float)uStack_54;
  iVar3 = (int)sVar8;
  DClipInfo_List::AddGDINode
            (SDI_List,1,iVar3,(int)(short)iStack_28,(int)(short)iStack_34,(int)(short)param_4,
             (int)(short)iStack_50,(int)(short)iStack_48,(int)(short)uStack_40,(int)(short)iStack_44
             ,(int)(short)param_3,10,uStack_54,SDI_Object_ID);
  if (((*(char *)(param_1 + 0x36) != '\0') && (*(byte *)(param_1 + 0x37) != 0)) &&
     ((*(byte *)(param_1 + 0x37) < 10 &&
      ((*(short *)(*(int *)(param_1 + 0xc) + 0x4a) ==
        *(short *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x7c) &&
       (pTVar1 = RGE_Base_Game::get_shape(rge_base_game,0), pTVar1 != (TShape *)0x0)))))) {
    DClipInfo_List::AddDrawNode
              (SDI_List,pTVar1->FShape,(Shape_Info *)(pTVar1->FShape + *(byte *)(param_1 + 0x37)),
               iVar3,(short)iStack_44 + -6,(short)param_3 + -8,0,(uchar *)0x0,0,0x1e,SDI_Object_ID);
  }
  if ((((*(byte *)(param_1 + 0x36) & 1) == 1) &&
      ((*(byte *)(*(int *)(param_1 + 8) + 0xa8) & 2) == 0)) &&
     (fStack_3c = (float)__ftol(), 0 < (int)fStack_3c)) {
    RGE_Map::get_point(pRStack_24,(short *)&iStack_20,(short *)&iStack_1c,fStack_4c,fStack_38,
                       fStack_2c,sVar7,sVar8);
    if ((int)fStack_3c < 1) {
      fStack_3c = 0.0;
    }
    fStack_2c = (float)(int)*(short *)(*(int *)(param_1 + 8) + 0x26);
    if (0 < (int)fStack_2c) {
      iStack_28 = iStack_20 + -0xc;
      iStack_50 = iStack_1c + -1;
      param_4 = iStack_20 + 0xb;
      iStack_34 = iStack_1c + -2;
      if (fStack_3c == fStack_2c) {
        uStack_40 = 1;
        iStack_44 = -1;
        param_3 = 0;
        iStack_48 = param_4;
      }
      else {
        if (fStack_3c == 0.0) {
          iStack_48 = -1;
          uStack_40 = 0;
          iStack_44 = iStack_28;
        }
        else {
          uStack_40 = 1;
          iStack_48 = ((int)fStack_3c * 0x18) / (int)fStack_2c + iStack_28;
          if ((short)param_4 <= (short)iStack_48) {
            iStack_48 = iStack_20 + 10;
          }
          iStack_44 = iStack_48 + 1;
        }
        param_3 = 1;
      }
      DClipInfo_List::AddGDINode
                (SDI_List,2,iVar3,(int)(short)iStack_28,(int)(short)iStack_34,(int)(short)param_4,
                 (int)(short)iStack_50,(int)(short)iStack_48,(int)(short)uStack_40,
                 (int)(short)iStack_44,(int)(short)param_3,0x1e,(int)fStack_30,SDI_Object_ID);
    }
  }
  if (rge_base_game->display_selected_ids != 0) {
    pRStack_24 = (RGE_Map *)RGE_Base_Game::get_shape(rge_base_game,0);
    iVar6 = *(int *)(param_1 + 4);
    iVar2 = iVar6;
    if (iVar6 < 0) {
      iVar2 = -iVar6;
    }
    aiStack_18[0] = iVar2 / 10000;
    aiStack_18[1] = (iVar2 % 10000) / 1000;
    iVar2 = (iVar2 % 10000) % 1000;
    aiStack_18[2] = iVar2 / 100;
    iVar2 = iVar2 % 100;
    aiStack_18[3] = iVar2 / 10;
    iStack_8 = iVar2 % 10;
    uVar5 = (uint)(iVar6 < 10000);
    if (iVar6 < 1000) {
      uVar5 = 2;
    }
    if (iVar6 < 100) {
      uVar5 = 3;
    }
    if (iVar6 < 10) {
      uVar5 = 4;
    }
    if (iVar6 < 0) {
      param_4 = param_4 + 7;
      DClipInfo_List::AddGDINode
                (SDI_List,4,iVar3,(short)param_4 + 1,(short)iStack_50 + 3,(short)param_4 + 5,
                 (short)iStack_50 + 3,0,0,0,0,0x1e,0x97,SDI_Object_ID);
    }
    if (uVar5 < 5) {
      piVar4 = aiStack_18 + uVar5;
      iVar6 = 5 - uVar5;
      do {
        param_4 = param_4 + 7;
        sVar7 = (short)param_4;
        if (*piVar4 == 0) {
          DClipInfo_List::AddGDINode
                    (SDI_List,4,iVar3,sVar7 + 1,(int)(short)iStack_50,sVar7 + 5,(short)iStack_50 + 5
                     ,0,0,0,0,0x1e,0xff,SDI_Object_ID);
        }
        else {
          DClipInfo_List::AddDrawNode
                    (SDI_List,*(SLhape_File_Header **)pRStack_24->tilesizes,
                     (Shape_Info *)(*(SLhape_File_Header **)pRStack_24->tilesizes + *piVar4),iVar3,
                     (int)sVar7,(int)(short)iStack_50,0,(uchar *)0x0,0,0x1e,SDI_Object_ID);
        }
        piVar4 = piVar4 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c2966
// Address: 004c2966
// XREFS: None
// [HELPER] s_stat_obj__draw_frame_3d_square_b: "stat_obj::draw_frame_3d_square_back"
void __thiscall FUN_004c2966(int param_1,TDrawArea *param_2,short param_3,short param_4)
{
  RGE_Map *this;
  float fVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  short sStack_10;
  short sStack_e;
  short sStack_c;
  short sStack_a;
  float fStack_8;
  float fStack_4;
  
  this = *(RGE_Map **)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28);
  fStack_8 = *(float *)(*(int *)(param_1 + 8) + 0xac);
  fStack_4 = *(float *)(*(int *)(param_1 + 8) + 0xb0);
  iVar2 = (**(code **)(rge_base_game->_padding_ + 0x2c))();
  if (iVar2 != 0) {
    TDrawArea::Unlock(param_2,s_stat_obj__draw_frame_3d_square_b);
    pvVar3 = TDrawArea::GetDc(param_2,s_stat_obj__draw_frame_3d_square_b);
    if (pvVar3 != (void *)0x0) {
      SelectClipRgn(param_2->DrawDc,*(undefined4 *)(iVar2 + 0x88));
      if (((startLoggingAI == 1) && (*(int *)(param_1 + 0x78) == *(int *)(param_1 + 4))) &&
         (-1 < *(int *)(param_1 + 4))) {
        uVar4 = GetStockObject(7);
        pvVar3 = param_2->DrawDc;
      }
      else {
        uVar4 = GetStockObject(6);
        pvVar3 = param_2->DrawDc;
      }
      SelectObject(pvVar3,uVar4);
      fVar1 = -fStack_4;
      param_4 = param_4 + *(short *)(param_1 + 0x2a);
      param_3 = param_3 + *(short *)(param_1 + 0x28);
      RGE_Map::get_point(this,&sStack_e,&sStack_10,fStack_8,fVar1,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_a,&sStack_c,fStack_8,fStack_4,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_e,(int)sStack_10,0);
      LineTo(param_2->DrawDc,(int)sStack_a,(int)sStack_c);
      RGE_Map::get_point(this,&sStack_e,&sStack_10,fStack_8,fVar1,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_a,&sStack_c,-fStack_8,fVar1,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_e,(int)sStack_10,0);
      LineTo(param_2->DrawDc,(int)sStack_a,(int)sStack_c);
      SelectClipRgn(param_2->DrawDc,0);
      TDrawArea::ReleaseDc(param_2,s_stat_obj__draw_frame_3d_square_b);
    }
    TDrawArea::Lock(param_2,s_stat_obj__draw_frame_3d_square_b,1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c2b47
// Address: 004c2b47
// XREFS: None
// [HELPER] s_stat_obj__draw_frame_3d_square_f: "stat_obj::draw_frame_3d_square_front"
void __thiscall FUN_004c2b47(int param_1,TDrawArea *param_2,short param_3,short param_4)
{
  RGE_Map *this;
  float fVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  short sStack_1c;
  short sStack_1a;
  short sStack_18;
  short sStack_16;
  float fStack_14;
  float fStack_10;
  int iStack_c;
  int iStack_8;
  float fStack_4;
  
  iVar4 = *(int *)(param_1 + 8);
  this = *(RGE_Map **)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28);
  fStack_14 = *(float *)(iVar4 + 0xb0);
  fStack_10 = *(float *)(iVar4 + 0xac);
  fStack_4 = *(float *)(iVar4 + 0x38);
  iStack_c = param_1;
  iStack_8 = (**(code **)(rge_base_game->_padding_ + 0x2c))();
  if (iStack_8 != 0) {
    TDrawArea::Unlock(param_2,s_stat_obj__draw_frame_3d_square_f);
    param_3 = param_3 + *(short *)(param_1 + 0x28);
    param_4 = param_4 + *(short *)(param_1 + 0x2a);
    pvVar2 = TDrawArea::GetDc(param_2,s_stat_obj__draw_frame_3d_square_f);
    if (pvVar2 != (void *)0x0) {
      SelectClipRgn(param_2->DrawDc,*(undefined4 *)(iStack_8 + 0x88));
      if (((startLoggingAI == 1) && (*(int *)(iStack_c + 0x78) == *(int *)(iStack_c + 4))) &&
         (-1 < *(int *)(iStack_c + 4))) {
        uVar3 = GetStockObject(7);
        pvVar2 = param_2->DrawDc;
      }
      else {
        uVar3 = GetStockObject(6);
        pvVar2 = param_2->DrawDc;
      }
      SelectObject(pvVar2,uVar3);
      fVar1 = -fStack_10;
      RGE_Map::get_point(this,&sStack_1a,&sStack_1c,fVar1,-fStack_14,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_16,&sStack_18,fVar1,fStack_14,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_1a,(int)sStack_1c,0);
      LineTo(param_2->DrawDc,(int)sStack_16,(int)sStack_18);
      RGE_Map::get_point(this,&sStack_1a,&sStack_1c,fStack_10,fStack_14,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_16,&sStack_18,fVar1,fStack_14,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_1a,(int)sStack_1c,0);
      LineTo(param_2->DrawDc,(int)sStack_16,(int)sStack_18);
      SelectClipRgn(param_2->DrawDc,0);
      TDrawArea::ReleaseDc(param_2,s_stat_obj__draw_frame_3d_square_f);
    }
    TDrawArea::Lock(param_2,s_stat_obj__draw_frame_3d_square_f,1);
    iVar4 = __ftol();
    if (0 < iVar4) {
      RGE_Map::get_point(this,&sStack_1a,&sStack_1c,fStack_10,-fStack_14,fStack_4,param_3,param_4);
      if (iVar4 < 1) {
        iVar4 = 0;
      }
      iVar5 = (int)*(short *)(*(int *)(iStack_c + 8) + 0x26);
      if (0 < iVar5) {
        TDrawArea::FillRect(param_2,sStack_1a + -0xc,sStack_1c + -2,sStack_1a + 0xc,sStack_1c + -1,
                            0x97);
        TDrawArea::FillRect(param_2,sStack_1a + -0xc,sStack_1c + -2,
                            (iVar4 * 0x18) / iVar5 + -0xc + (int)sStack_1a,sStack_1c + -1,'J');
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c2dec
// Address: 004c2dec
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c2dec(int param_1,TDrawArea *param_2,short param_3,short param_4)
{
  RGE_Map *this;
  float fVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  short sStack_24;
  short sStack_22;
  short sStack_20;
  short sStack_1e;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar2 = *(int *)(param_1 + 8);
  fStack_18 = *(float *)(iVar2 + 0xac) * _DAT_00574734;
  fStack_10 = *(float *)(iVar2 + 0xb0) * _DAT_00574734;
  fStack_c = *(float *)(iVar2 + 0xb4) * _DAT_00574734;
  fStack_8 = *(float *)(iVar2 + 0xb4) * _DAT_00574738;
  fStack_1c = *(float *)(iVar2 + 0xac);
  this = *(RGE_Map **)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28);
  fStack_14 = *(float *)(iVar2 + 0xb0);
  fStack_4 = *(float *)(iVar2 + 0xb4);
  iVar2 = (**(code **)(rge_base_game->_padding_ + 0x2c))();
  if (iVar2 != 0) {
    TDrawArea::Unlock(param_2,(char *)0x0);
    pvVar3 = TDrawArea::GetDc(param_2,(char *)0x0);
    if (pvVar3 != (void *)0x0) {
      SelectClipRgn(param_2->DrawDc,*(undefined4 *)(iVar2 + 0x88));
      if (((startLoggingAI == 1) && (*(int *)(param_1 + 0x78) == *(int *)(param_1 + 4))) &&
         (-1 < *(int *)(param_1 + 4))) {
        uVar4 = GetStockObject(7);
        pvVar3 = param_2->DrawDc;
      }
      else {
        uVar4 = GetStockObject(6);
        pvVar3 = param_2->DrawDc;
      }
      SelectObject(pvVar3,uVar4);
      fVar1 = -fStack_14;
      param_4 = param_4 + *(short *)(param_1 + 0x2a);
      param_3 = param_3 + *(short *)(param_1 + 0x28);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_1c,fVar1,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_1e,&sStack_20,fStack_1c,fVar1,fStack_c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_22,(int)sStack_24,0);
      LineTo(param_2->DrawDc,(int)sStack_1e,(int)sStack_20);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_1c,fVar1,fStack_8,param_3,param_4);
      RGE_Map::get_point(this,&sStack_1e,&sStack_20,fStack_1c,fVar1,fStack_4,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_22,(int)sStack_24,0);
      LineTo(param_2->DrawDc,(int)sStack_1e,(int)sStack_20);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_1c,fVar1,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_1e,&sStack_20,fStack_18,fVar1,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_22,(int)sStack_24,0);
      LineTo(param_2->DrawDc,(int)sStack_1e,(int)sStack_20);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,-fStack_1c,fVar1,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_1e,&sStack_20,-fStack_18,fVar1,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_22,(int)sStack_24,0);
      LineTo(param_2->DrawDc,(int)sStack_1e,(int)sStack_20);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_1c,fVar1,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_1e,&sStack_20,fStack_1c,-fStack_10,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_22,(int)sStack_24,0);
      LineTo(param_2->DrawDc,(int)sStack_1e,(int)sStack_20);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_1c,fStack_14,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_1e,&sStack_20,fStack_1c,fStack_10,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_22,(int)sStack_24,0);
      LineTo(param_2->DrawDc,(int)sStack_1e,(int)sStack_20);
      SelectClipRgn(param_2->DrawDc,0);
      TDrawArea::ReleaseDc(param_2,(char *)0x0);
    }
    TDrawArea::Lock(param_2,(char *)0x0,1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c31d2
// Address: 004c31d2
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c31d2(int param_1,TDrawArea *param_2,short param_3,short param_4)
{
  RGE_Map *this;
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  short sStack_28;
  short sStack_26;
  short sStack_24;
  short sStack_22;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar4 = *(int *)(param_1 + 8);
  fStack_10 = *(float *)(iVar4 + 0xac) * _DAT_00574734;
  fStack_14 = *(float *)(iVar4 + 0xb0) * _DAT_00574734;
  fStack_8 = *(float *)(iVar4 + 0xb4) * _DAT_00574734;
  fStack_4 = *(float *)(iVar4 + 0xb4) * _DAT_00574738;
  fStack_18 = *(float *)(iVar4 + 0xac);
  this = *(RGE_Map **)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28);
  fStack_20 = *(float *)(iVar4 + 0xb0);
  fStack_1c = *(float *)(iVar4 + 0xb4);
  iVar4 = (**(code **)(rge_base_game->_padding_ + 0x2c))();
  if (iVar4 != 0) {
    TDrawArea::Unlock(param_2,(char *)0x0);
    pvVar5 = TDrawArea::GetDc(param_2,(char *)0x0);
    if (pvVar5 != (void *)0x0) {
      SelectClipRgn(param_2->DrawDc,*(undefined4 *)(iVar4 + 0x88));
      if (((startLoggingAI == 1) && (*(int *)(param_1 + 0x78) == *(int *)(param_1 + 4))) &&
         (-1 < *(int *)(param_1 + 4))) {
        uVar6 = GetStockObject(7);
        pvVar5 = param_2->DrawDc;
      }
      else {
        uVar6 = GetStockObject(6);
        pvVar5 = param_2->DrawDc;
      }
      SelectObject(pvVar5,uVar6);
      fVar1 = -fStack_20;
      param_4 = param_4 + *(short *)(param_1 + 0x2a) + -0x10;
      param_3 = param_3 + *(short *)(param_1 + 0x28);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fStack_18,fVar1,fStack_1c,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_10,fVar1,fStack_1c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      fVar2 = -fStack_18;
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fVar2,fVar1,fStack_1c,param_3,param_4);
      fStack_c = -fStack_10;
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_c,fVar1,fStack_1c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fStack_18,fStack_20,fStack_1c,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_10,fStack_20,fStack_1c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fVar2,fStack_20,fStack_1c,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_c,fStack_20,fStack_1c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fStack_18,fStack_20,fStack_1c,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_18,fStack_14,fStack_1c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fStack_18,fVar1,fStack_1c,param_3,param_4);
      fVar3 = -fStack_14;
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_18,fVar3,fStack_1c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fVar2,fStack_20,fStack_1c,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fVar2,fStack_14,fStack_1c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fVar2,fVar1,fStack_1c,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fVar2,fVar3,fStack_1c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fVar2,fVar1,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fVar2,fVar3,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fVar2,fStack_20,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fVar2,fStack_14,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fStack_18,fStack_20,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_10,fStack_20,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fVar2,fStack_20,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_c,fStack_20,0.0,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fVar2,fStack_20,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fVar2,fStack_20,fStack_8,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fVar2,fStack_20,fStack_4,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fVar2,fStack_20,fStack_1c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fVar2,fVar1,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fVar2,fVar1,fStack_8,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fVar2,fVar1,fStack_4,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fVar2,fVar1,fStack_1c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fStack_18,fStack_20,0.0,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_18,fStack_20,fStack_8,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      RGE_Map::get_point(this,&sStack_26,&sStack_28,fStack_18,fStack_20,fStack_4,param_3,param_4);
      RGE_Map::get_point(this,&sStack_22,&sStack_24,fStack_18,fStack_20,fStack_1c,param_3,param_4);
      MoveToEx(param_2->DrawDc,(int)sStack_26,(int)sStack_28,0);
      LineTo(param_2->DrawDc,(int)sStack_22,(int)sStack_24);
      SelectClipRgn(param_2->DrawDc,0);
      TDrawArea::ReleaseDc(param_2,(char *)0x0);
    }
    TDrawArea::Lock(param_2,(char *)0x0,1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c3b27
// Address: 004c3b27
// XREFS: None
void __thiscall FUN_004c3b27(RGE_Static_Object *param_1,short param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int iVar5;
  short unaff_retaddr;
  TDrawArea *pTStack_4;
  
  if ((param_1->sprite != (RGE_Sprite *)0x0) &&
     (param_1->sprite_list != (RGE_Active_Sprite_List *)0x0)) {
    (**(code **)(param_1->sprite_list->_padding_ + 0x28))(param_1->sprite,param_1->facet);
    iVar2 = RGE_Static_Object::get_frame
                      (param_1,(short *)&stack0xfffffff0,(short *)&stack0xfffffff2,
                       (short *)&stack0xfffffff6,(short *)&stack0xfffffff4);
    if (iVar2 != 0) {
      iVar2 = (int)(short)unaff_EBP + (int)unaff_retaddr + -1 + (int)param_1->screen_x_offset;
      iVar1 = (int)(short)((uint)unaff_EBP >> 0x10) + (int)param_2 + -1 +
              (int)param_1->screen_y_offset;
      TDrawArea::DrawRect(pTStack_4,iVar2,iVar1,
                          (int)(short)((uint)unaff_EBX >> 0x10) + (int)unaff_retaddr + 1 +
                          (int)param_1->screen_x_offset,
                          (int)(short)unaff_EBX + (int)param_2 + 1 + (int)param_1->screen_y_offset,
                          0xff);
      if (param_1->object_state < 3) {
        iVar3 = __ftol();
        if (iVar3 < 1) {
          iVar3 = 0;
        }
        iVar4 = (int)param_1->master_obj->hp;
        if (0 < iVar4) {
          TDrawArea::DrawRect(pTStack_4,iVar2,iVar1 + -6,iVar2 + 0x1a,iVar1 + -1,0xff);
          iVar5 = iVar2 + 1;
          TDrawArea::FillRect(pTStack_4,iVar5,iVar1 + -5,iVar2 + 0x18,iVar1 + -3,'U');
          TDrawArea::FillRect(pTStack_4,iVar5,iVar1 + -5,(iVar3 * 0x19) / iVar4 + -1 + iVar5,
                              iVar1 + -2,'%');
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c3c69
// Address: 004c3c69
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_stat_obj_c: "C:\msdev\work\age1_x1\stat_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char __fastcall FUN_004c3c69(int *param_1)
{
  int iVar1;
  bool bVar2;
  float fVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  RGE_Static_Object *pRVar7;
  int iVar8;
  undefined3 uVar10;
  uint uVar9;
  int *piVar11;
  undefined4 unaff_ESI;
  char cVar12;
  undefined4 unaff_EDI;
  char cVar13;
  uint uStack_4;
  
  cVar13 = (char)((uint)unaff_EDI >> 0x18);
  cVar12 = (char)((uint)unaff_ESI >> 0x18);
  if (*(char *)((int)param_1 + 0x4b) != '\0') {
    iVar4 = *(int *)param_1[3];
    *(undefined1 *)((int)param_1 + 0x4b) = 0;
    (**(code **)(iVar4 + 0xe0))(param_1,0,*(undefined1 *)((int)param_1 + 0x4a),param_1[0x14]);
    iVar4 = (**(code **)(*(int *)param_1[3] + 0xdc))(param_1,1,*(undefined1 *)((int)param_1 + 0x4a))
    ;
    param_1[0x14] = iVar4;
    return '\0';
  }
  if ((0 < param_1[0x1a]) && (iVar4 = 0, 0 < param_1[0x1a])) {
    uStack_4 = 4;
    do {
      if (param_1[0x1c] + -1 < iVar4) {
        pvVar5 = operator_new(uStack_4);
        if (pvVar5 != (void *)0x0) {
          iVar6 = 0;
          if (0 < param_1[0x1c]) {
            do {
              if (iVar4 + 1 <= iVar6) break;
              iVar6 = iVar6 + 1;
              *(undefined4 *)((int)pvVar5 + iVar6 * 4 + -4) =
                   *(undefined4 *)(param_1[0x19] + -4 + iVar6 * 4);
            } while (iVar6 < param_1[0x1c]);
          }
          operator_delete((void *)param_1[0x19]);
          param_1[0x19] = (int)pvVar5;
          param_1[0x1c] = iVar4 + 1;
        }
      }
      iVar6 = *(int *)(param_1[0x19] + iVar4 * 4);
      pRVar7 = RGE_Game_World::object(*(RGE_Game_World **)(param_1[3] + 0x3c),iVar6);
      cVar13 = (char)((uint)unaff_EDI >> 0x18);
      if ((pRVar7 == (RGE_Static_Object *)0x0) || (2 < pRVar7->object_state)) {
        iVar1 = param_1[0x1c];
        iVar8 = 0;
        if (0 < iVar1) {
          piVar11 = (int *)param_1[0x19];
          do {
            if (*piVar11 == iVar6) break;
            iVar8 = iVar8 + 1;
            piVar11 = piVar11 + 1;
          } while (iVar8 < iVar1);
        }
        if (iVar8 < iVar1) {
          if (iVar8 < iVar1 + -1) {
            do {
              iVar8 = iVar8 + 1;
              *(undefined4 *)(param_1[0x19] + -4 + iVar8 * 4) =
                   *(undefined4 *)(param_1[0x19] + iVar8 * 4);
            } while (iVar8 < param_1[0x1c] + -1);
          }
          iVar6 = param_1[0x1a];
          param_1[0x1a] = iVar6 + -1;
          if (iVar6 + -1 < 0) {
            param_1[0x1a] = 0;
          }
        }
        iVar4 = iVar4 + -1;
        uStack_4 = uStack_4 - 4;
      }
      iVar4 = iVar4 + 1;
      uStack_4 = uStack_4 + 4;
    } while (iVar4 < param_1[0x1a]);
  }
  iVar4 = param_1[8];
  uVar10 = (undefined3)((uint)iVar4 >> 8);
  if (iVar4 == 0) {
    switch(CONCAT31(uVar10,(char)param_1[0x12])) {
    case 2:
      (**(code **)(*param_1 + 0x28))();
    case 0:
      if ((float)param_1[0xc] < _DAT_0057472c) {
        iVar4 = *param_1;
        (**(code **)(iVar4 + 0x5c))(3);
        (**(code **)(iVar4 + 0x38))(*(undefined4 *)(param_1[2] + 0x1c));
        uVar9 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x704);
        iVar4 = debug_random_on;
        debug_random_on = 0;
        if ((*(RGE_Sound **)(param_1[2] + 0x44) != (RGE_Sound *)0x0) &&
           (*(short *)(param_1[3] + 0x4a) == *(short *)(*(int *)(param_1[3] + 0x3c) + 0x7c))) {
          RGE_Sound::play(*(RGE_Sound **)(param_1[2] + 0x44),1);
        }
        debug_random_on = iVar4;
        debug_srand(s_C__msdev_work_age1_x1_stat_obj_c,0x70e,uVar9);
        return cVar13;
      }
      break;
    case 3:
    case 5:
      if (((short)param_1[0x13] == -1) || ((float)param_1[0x11] <= DAT_00574718._8_4_)) {
        iVar4 = *param_1;
        if (*(char *)(param_1[2] + 0x24) != '\0') {
          (**(code **)(iVar4 + 0x5c))(6);
          (**(code **)(iVar4 + 0x38))(*(undefined4 *)(param_1[2] + 0x20));
          return cVar13;
        }
        (**(code **)(iVar4 + 0x5c))(7);
        (**(code **)(iVar4 + 0xb8))();
        return cVar12;
      }
      if ((DAT_00574718._8_4_ < *(float *)(param_1[2] + 0x80)) &&
         (fVar3 = (float)param_1[0x11] -
                  *(float *)(*(int *)(param_1[3] + 0x3c) + 0x84) * *(float *)(param_1[2] + 0x80),
         bVar2 = fVar3 < DAT_00574718._8_4_, param_1[0x11] = (int)fVar3, bVar2)) {
        param_1[0x11] = 0;
        return '\0';
      }
      break;
    case 7:
      (**(code **)(*param_1 + 0x5c))(8);
      return cVar12;
    case 8:
      return (*(char *)(param_1[2] + 0xa4) != '\0') + '\x01';
    }
  }
  else if (2 < *(byte *)(iVar4 + 0x48)) {
    (**(code **)(*param_1 + 0x5c))(CONCAT31(uVar10,*(byte *)(iVar4 + 0x48)));
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_004c3f65
// Address: 004c3f65
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_stat_obj_c: "C:\msdev\work\age1_x1\stat_obj.cpp"
void __fastcall FUN_004c3f65(int param_1,char *param_2)
{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  undefined4 in_EAX;
  byte bVar7;
  byte *pbVar6;
  int *piVar8;
  int iVar9;
  char cVar11;
  int unaff_EBX;
  uint uVar12;
  char *unaff_EDI;
  int iVar13;
  int iVar14;
  byte in_AF;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  short unaff_retaddr;
  short sStack00000004;
  int iStack00000008;
  int iStack0000000c;
  float in_stack_00000010;
  float in_stack_00000014;
  RGE_Sprite *pRVar15;
  undefined1 uStack_3;
  char cVar10;
  
  bVar7 = (byte)in_EAX / 0x3d;
  bVar3 = (byte)in_EAX % 0x3d;
  cVar11 = (char)unaff_EBX;
  *(char *)(param_1 + 0x3f) = *(char *)(param_1 + 0x3f) + cVar11;
  cVar10 = (char)((uint)param_1 >> 8) + (char)param_1;
  piVar8 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar10,(char)param_1));
  *(char *)((int)piVar8 + 0x3f) = *(char *)((int)piVar8 + 0x3f) + cVar11;
  unaff_EDI[0x3e] = unaff_EDI[0x3e] + bVar7;
  *(char *)((int)piVar8 + 0x3f) = *(char *)((int)piVar8 + 0x3f) + cVar11;
  *param_2 = *param_2 + cVar11;
  bVar2 = 9 < (bVar3 & 0xf) | in_AF;
  bVar4 = bVar3 + bVar2 * -6 & 0xf;
  *unaff_EDI = *unaff_EDI + cVar10;
  bVar3 = 9 < bVar4 | bVar2;
  uVar12 = CONCAT31((int3)((uint)in_EAX >> 8),bVar4 + bVar3 * -6) & 0xffff000f;
  pbVar6 = (byte *)(CONCAT22((short)(uVar12 >> 0x10),CONCAT11((bVar7 - bVar2) - bVar3,(char)uVar12))
                   + -0x7c6f6f70);
  bVar2 = *pbVar6;
  bVar3 = (byte)param_2;
  *pbVar6 = *pbVar6 + bVar3;
  in((short)param_2);
  *(char *)(unaff_EBX + 0x55) = (*(char *)(unaff_EBX + 0x55) - bVar3) - CARRY1(bVar2,bVar3);
  iVar9 = piVar8[2];
  iStack0000000c = -1;
  iStack00000008 = -1;
  if (*(short *)(iVar9 + 0x26) < 1) {
    return;
  }
  bVar2 = *(byte *)(iVar9 + 0x93);
  if (bVar2 == 0) {
    return;
  }
  _sStack00000004 = (int)*(short *)(iVar9 + 0x26);
  cVar10 = __ftol();
  bVar3 = 100 - cVar10;
  if (bVar3 == *(byte *)(piVar8 + 0xd)) {
    return;
  }
  iVar14 = -1;
  if ((bVar3 < 100) && (bVar2 != 0)) {
    iVar13 = 0;
    pbVar6 = (byte *)(*(int *)(iVar9 + 0x94) + 4);
    uVar12 = (uint)bVar2;
    do {
      if (*pbVar6 < bVar3) {
        iStack0000000c = iVar13;
      }
      if (*pbVar6 < *(byte *)(piVar8 + 0xd)) {
        iStack00000008 = iVar13;
      }
      iVar13 = iVar13 + 1;
      pbVar6 = pbVar6 + 8;
      uVar12 = uVar12 - 1;
      iVar14 = iStack0000000c;
    } while (uVar12 != 0);
  }
  if (iVar14 == iStack00000008) goto LAB_004c41b6;
  if (-1 < iVar14) {
    puVar1 = (undefined4 *)(*(int *)(piVar8[2] + 0x94) + iVar14 * 8);
    cVar10 = *(char *)((int)puVar1 + 5);
    if (cVar10 == '\0') {
      pRVar15 = (RGE_Sprite *)*puVar1;
      iVar9 = 0;
      iVar13 = 0;
    }
    else {
      if (cVar10 != '\x01') {
        if (cVar10 == '\x02') {
          (**(code **)(*piVar8 + 0x38))(*puVar1);
        }
        goto LAB_004c415b;
      }
      in_stack_00000010 = (float)debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x774);
      sVar5 = __ftol();
      in_stack_00000010 = (float)(int)sVar5;
      in_stack_00000014 =
           (float)(((float10)(float)piVar8[0xe] - (float10)(int)in_stack_00000010) + extraout_ST0);
      in_stack_00000010 = (float)debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x775);
      sVar5 = __ftol();
      in_stack_00000010 =
           (float)(((float10)(float)piVar8[0xf] - (float10)(int)sVar5) + extraout_ST0_00);
      RGE_Map::get_point(*(RGE_Map **)(*(int *)(piVar8[3] + 0x3c) + 0x28),&stack0x00000004,
                         (short *)&stack0x00000002,in_stack_00000014,in_stack_00000010,
                         (float)piVar8[0x10],0,0);
      iVar9 = (int)unaff_retaddr;
      iVar13 = (int)sStack00000004;
      pRVar15 = *(RGE_Sprite **)(*(int *)(piVar8[2] + 0x94) + iVar14 * 8);
    }
    RGE_Active_Sprite_List::add_sprite((RGE_Active_Sprite_List *)piVar8[6],pRVar15,'Z',iVar13,iVar9)
    ;
  }
LAB_004c415b:
  if (-1 < iStack00000008) {
    iVar9 = *(int *)(piVar8[2] + 0x94);
    bVar2 = *(byte *)(iVar9 + 5 + iStack00000008 * 8);
    if (bVar2 < 2) {
      RGE_Active_Sprite_List::remove_sprite
                ((RGE_Active_Sprite_List *)piVar8[6],*(RGE_Sprite **)(iVar9 + iStack00000008 * 8));
    }
    else if ((bVar2 == 2) &&
            ((iStack0000000c < 0 || (*(char *)(iVar9 + 5 + iStack0000000c * 8) != '\x02')))) {
      (**(code **)(*piVar8 + 0x38))(*(undefined4 *)(piVar8[2] + 0x18));
      *(undefined1 *)(piVar8 + 0xd) = uStack_3;
      return;
    }
  }
LAB_004c41b6:
  *(byte *)(piVar8 + 0xd) = bVar3;
  return;
}

// --------------------------------------------------

// Function: FUN_004c41c1
// Address: 004c41c1
// XREFS: None
undefined4 __fastcall FUN_004c41c1(int param_1)
{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  
  sVar1 = *(short *)(*(int *)(param_1 + 8) + 0x48);
  if (-1 < sVar1) {
    piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 0xc) + 0x24) + sVar1 * 4);
    if (piVar2 != (int *)0x0) {
      uVar3 = (**(code **)(*piVar2 + 0x18))
                        (*(int *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x38),
                         *(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x40));
      return uVar3;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c420a
// Address: 004c420a
// XREFS: None
void __fastcall FUN_004c420a(RGE_Static_Object *param_1)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  iVar1 = param_1->_padding_;
  (**(code **)(iVar1 + 0x34))(param_1->world_x,param_1->world_y,param_1->world_z);
  pRVar2 = param_1->inside_obj;
  if (pRVar2 != (RGE_Static_Object *)0x0) {
    param_1->inside_obj = (RGE_Static_Object *)0x0;
    pRVar2 = RGE_Static_Object::get_object_pointer(param_1,(long)pRVar2);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      (**(code **)(iVar1 + 0xd0))(pRVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c424f
// Address: 004c424f
// XREFS: None
RGE_Static_Object * __thiscall FUN_004c424f(int param_1,uint param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  ushort uVar4;
  byte bVar5;
  int iVar6;
  
  iVar1 = param_2;
  pRVar2 = (RGE_Static_Object *)0x0;
  if ((((-1 < (int)param_2) &&
       (pRVar2 = RGE_Object_List::find_by_id
                           (*(RGE_Object_List **)(*(int *)(param_1 + 0xc) + 0x28),param_2),
       pRVar2 == (RGE_Static_Object *)0x0)) &&
      (pRVar2 = RGE_Object_List::find_by_id
                          (*(RGE_Object_List **)(*(int *)(param_1 + 0xc) + 0x2c),param_2),
      pRVar2 == (RGE_Static_Object *)0x0)) &&
     (pRVar2 = RGE_Object_List::find_by_id
                         (*(RGE_Object_List **)(*(int *)(param_1 + 0xc) + 0x30),param_2),
     pRVar2 == (RGE_Static_Object *)0x0)) {
    iVar6 = *(int *)(param_1 + 0xc);
    bVar5 = 0;
    param_2 = 0;
    iVar3 = *(int *)(iVar6 + 0x3c);
    if (0 < *(short *)(iVar3 + 0x3c)) {
      uVar4 = 0;
      do {
        if (uVar4 != *(ushort *)(iVar6 + 0x4a)) {
          iVar6 = param_2 * 4;
          pRVar2 = RGE_Object_List::find_by_id
                             (*(RGE_Object_List **)(*(int *)(*(int *)(iVar3 + 0x40) + iVar6) + 0x28)
                              ,iVar1);
          if (pRVar2 != (RGE_Static_Object *)0x0) {
            return pRVar2;
          }
          pRVar2 = RGE_Object_List::find_by_id
                             (*(RGE_Object_List **)
                               (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x40) +
                                        iVar6) + 0x2c),iVar1);
          if (pRVar2 != (RGE_Static_Object *)0x0) {
            return pRVar2;
          }
          pRVar2 = RGE_Object_List::find_by_id
                             (*(RGE_Object_List **)
                               (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x40) +
                                        iVar6) + 0x30),iVar1);
          if (pRVar2 != (RGE_Static_Object *)0x0) {
            return pRVar2;
          }
        }
        iVar6 = *(int *)(param_1 + 0xc);
        bVar5 = bVar5 + 1;
        param_2 = (uint)bVar5;
        iVar3 = *(int *)(iVar6 + 0x3c);
        uVar4 = (ushort)bVar5;
      } while ((short)(ushort)bVar5 < *(short *)(iVar3 + 0x3c));
    }
  }
  return pRVar2;
}

// --------------------------------------------------

// Function: FUN_004c432b
// Address: 004c432b
// XREFS: None
undefined4 __thiscall FUN_004c432b(int param_1,short param_2)
{
  int iVar1;
  
  if ((-1 < param_2) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c), param_2 < *(short *)(iVar1 + 0x34))) {
    return *(undefined4 *)(*(int *)(iVar1 + 0x38) + param_2 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c4357
// Address: 004c4357
// XREFS: None
void __thiscall FUN_004c4357(int param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_2;
  rge_write(param_2,(void *)(param_1 + 0x4e),1);
  rge_write(iVar1,(void *)(*(int *)(param_1 + 0xc) + 0x4a),1);
  rge_write(iVar1,(void *)(*(int *)(param_1 + 8) + 0x10),2);
  iVar4 = *(int *)(param_1 + 0x10);
  if (iVar4 == 0) {
    uStack_8 = 0xffffffff;
  }
  else {
    uStack_8 = CONCAT22((short)((uint)iVar4 >> 0x10),*(undefined2 *)(iVar4 + 0x72));
  }
  rge_write(iVar1,&uStack_8,2);
  if (*(int *)(param_1 + 0x20) == 0) {
    uStack_4 = 0xffffffff;
  }
  else {
    uStack_4 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
  }
  rge_write(iVar1,&uStack_4,4);
  rge_write(iVar1,(void *)(param_1 + 0x30),4);
  rge_write(iVar1,(void *)(param_1 + 0x48),1);
  rge_write(iVar1,(void *)(param_1 + 0x49),1);
  rge_write(iVar1,(void *)(param_1 + 0x4a),1);
  rge_write(iVar1,(void *)(param_1 + 0x4b),1);
  rge_write(iVar1,(void *)(param_1 + 4),4);
  rge_write(iVar1,(void *)(param_1 + 0x35),1);
  rge_write(iVar1,(void *)(param_1 + 0x38),4);
  rge_write(iVar1,(void *)(param_1 + 0x3c),4);
  rge_write(iVar1,(void *)(param_1 + 0x40),4);
  rge_write(iVar1,(void *)(param_1 + 0x28),2);
  rge_write(iVar1,(void *)(param_1 + 0x2a),2);
  rge_write(iVar1,(void *)(param_1 + 0x2c),2);
  rge_write(iVar1,(void *)(param_1 + 0x2e),2);
  rge_write(iVar1,(void *)(param_1 + 0x37),1);
  rge_write(iVar1,(void *)(param_1 + 0x4c),2);
  rge_write(iVar1,(void *)(param_1 + 0x44),4);
  rge_write(iVar1,(void *)(param_1 + 0x4f),1);
  rge_write(iVar1,(void *)(param_1 + 0x34),1);
  rge_write(iVar1,(void *)(param_1 + 0x86),1);
  rge_write(iVar1,(void *)(param_1 + 0x78),4);
  rge_write(iVar1,(void *)(param_1 + 0x80),4);
  param_2 = *(undefined4 *)(param_1 + 0x68);
  rge_write(iVar1,&param_2,4);
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x68)) {
    do {
      if (*(int *)(param_1 + 0x70) + -1 < iVar4) {
        pvVar2 = operator_new(iVar4 * 4 + 4);
        if (pvVar2 != (void *)0x0) {
          iVar3 = 0;
          if (0 < *(int *)(param_1 + 0x70)) {
            do {
              if (iVar4 + 1 <= iVar3) break;
              iVar3 = iVar3 + 1;
              *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 100) + -4 + iVar3 * 4);
            } while (iVar3 < *(int *)(param_1 + 0x70));
          }
          operator_delete(*(void **)(param_1 + 100));
          *(void **)(param_1 + 100) = pvVar2;
          *(int *)(param_1 + 0x70) = iVar4 + 1;
        }
      }
      param_2 = *(undefined4 *)(*(int *)(param_1 + 100) + iVar4 * 4);
      rge_write(iVar1,&param_2,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x68));
  }
  param_2 = *(undefined4 *)(param_1 + 0x58);
  rge_write(iVar1,&param_2,4);
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x58)) {
    do {
      if (*(int *)(param_1 + 0x60) + -1 < iVar4) {
        pvVar2 = operator_new(iVar4 * 4 + 4);
        if (pvVar2 != (void *)0x0) {
          iVar3 = 0;
          if (0 < *(int *)(param_1 + 0x60)) {
            do {
              if (iVar4 + 1 <= iVar3) break;
              iVar3 = iVar3 + 1;
              *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x54) + -4 + iVar3 * 4);
            } while (iVar3 < *(int *)(param_1 + 0x60));
          }
          operator_delete(*(void **)(param_1 + 0x54));
          *(void **)(param_1 + 0x54) = pvVar2;
          *(int *)(param_1 + 0x60) = iVar4 + 1;
        }
      }
      param_2 = *(undefined4 *)(*(int *)(param_1 + 0x54) + iVar4 * 4);
      rge_write(iVar1,&param_2,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x58));
  }
  RGE_Active_Sprite_List::save(*(RGE_Active_Sprite_List **)(param_1 + 0x18),iVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_004c467f
// Address: 004c467f
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall
FUN_004c467f(RGE_Static_Object *param_1,float param_2,float param_3,float param_4)
{
  RGE_Tile *pRVar1;
  uchar uVar2;
  RGE_Map *pRVar3;
  int iVar4;
  int iVar5;
  RGE_Tile *pRVar6;
  RGE_Master_Static_Object *pRVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  float10 extraout_ST0;
  float10 fVar14;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  
  fVar10 = DAT_00574718._8_4_;
  pRVar3 = param_1->owner->world->map;
  if (param_1->inside_obj != (RGE_Static_Object *)0x0) {
    return (float10)DAT_00574718._8_4_;
  }
  if ((float)(double)DAT_00574718 < param_1->master_obj->radius_z) {
    RGE_Static_Object::removeFromObstructionMap(param_1,2);
  }
  if (param_2 < DAT_00574718._8_4_) {
    param_2 = 0.0;
  }
  iVar4 = pRVar3->map_width;
  if ((float)iVar4 <= param_2) {
    param_2 = (float)iVar4 - _DAT_00574744;
  }
  if (param_3 < DAT_00574718._8_4_) {
    param_3 = 0.0;
  }
  iVar5 = pRVar3->map_height;
  if ((float)iVar5 <= param_3) {
    param_3 = (float)iVar5 - _DAT_00574744;
  }
  iVar12 = __ftol();
  iVar13 = __ftol();
  fVar8 = param_2 - (float)iVar12;
  fVar9 = param_3 - (float)iVar13;
  if (iVar12 < iVar4) {
    if (iVar12 < 0) {
      iVar12 = 0;
    }
  }
  else {
    iVar12 = iVar4 + -1;
  }
  if (iVar13 < iVar5) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
  }
  else {
    iVar13 = iVar5 + -1;
  }
  pRVar1 = pRVar3->map_row_offset[iVar13] + iVar12;
  pRVar6 = param_1->tile;
  if ((pRVar1 == pRVar6) || (param_1->inside_obj != (RGE_Static_Object *)0x0)) {
    param_1->world_x = param_2;
    param_1->world_y = param_3;
    param_1->world_z = param_4;
    fVar14 = extraout_ST0;
  }
  else {
    if (pRVar6 != (RGE_Tile *)0x0) {
      RGE_Object_List::remove_node(&pRVar6->objects,param_1,(RGE_Object_Node *)0x0);
    }
    RGE_Object_List::add_node(&pRVar1->objects,param_1);
    if (param_1->tile != (RGE_Tile *)0x0) {
      (**(code **)(param_1->_padding_ + 0xdc))(param_1->owner,0,0xffffffff);
    }
    param_1->world_z = param_4;
    param_1->world_x = param_2;
    param_1->world_y = param_3;
    param_1->tile = pRVar1;
    if (param_1->object_state == '\x02') {
      (**(code **)(param_1->_padding_ + 0xd8))(param_1->owner,0,0xffffffff);
    }
    fVar14 = (float10)fVar10;
  }
  if ((float)(double)DAT_00574718 < param_1->master_obj->radius_z) {
    RGE_Static_Object::addToObstructionMap(param_1,2);
    fVar14 = (float10)fVar10;
  }
  switch(pRVar1->tile_type) {
  case '\0':
    goto switchD_004c4876_caseD_0;
  case '\x01':
    if (fVar9 + fVar8 < _DAT_0057472c) {
      fVar14 = (float10)fVar9;
      break;
    }
    goto LAB_004c49f3;
  case '\x02':
    if (fVar9 + fVar8 < _DAT_0057472c) {
      fVar14 = (float10)fVar8;
      break;
    }
    goto LAB_004c4920;
  case '\x03':
    if (fVar8 <= fVar9) {
      fVar14 = (float10)_DAT_0057472c - (float10)fVar9;
    }
    else {
      fVar14 = (float10)_DAT_0057472c - (float10)fVar8;
    }
    break;
  case '\x04':
    if (fVar8 <= fVar9) {
      fVar14 = (float10)fVar8;
    }
    else {
      fVar14 = (float10)fVar9;
    }
    break;
  case '\x05':
    fVar14 = (float10)_DAT_0057472c - (float10)fVar8;
    break;
  case '\x06':
LAB_004c4920:
    fVar14 = (float10)_DAT_0057472c - (float10)fVar9;
    break;
  case '\a':
    fVar14 = (float10)fVar9;
    break;
  case '\b':
    fVar14 = (float10)fVar8;
    break;
  case '\t':
    if ((float10)fVar8 - (float10)fVar9 < (float10)DAT_00574718._8_4_) {
      fVar14 = -((float10)fVar8 - (float10)fVar9);
      break;
    }
    goto switchD_004c4876_caseD_0;
  case '\n':
    fVar14 = (float10)fVar8 - (float10)fVar9;
    if (fVar14 <= (float10)DAT_00574718._8_4_) {
      fVar14 = (float10)DAT_00574718._8_4_;
    }
    break;
  case '\v':
    if ((float10)fVar9 + (float10)fVar8 < (float10)_DAT_0057472c) {
      fVar14 = (float10)_DAT_0057472c - ((float10)fVar9 + (float10)fVar8);
      break;
    }
    goto switchD_004c4876_caseD_0;
  case '\f':
    if ((float10)_DAT_0057472c < (float10)fVar9 + (float10)fVar8) {
      fVar14 = ((float10)fVar9 + (float10)fVar8) - (float10)_DAT_0057472c;
      break;
    }
switchD_004c4876_caseD_0:
    fVar14 = (float10)DAT_00574718._8_4_;
    break;
  case '\r':
    if (_DAT_0057472c <= fVar9 + fVar8) {
      fVar14 = (float10)fVar9;
      break;
    }
LAB_004c49f3:
    fVar14 = (float10)_DAT_0057472c - (float10)fVar8;
    break;
  case '\x0e':
    if (_DAT_0057472c <= fVar9 + fVar8) {
      fVar14 = (float10)fVar8;
    }
    else {
      fVar14 = (float10)_DAT_0057472c - (float10)fVar9;
    }
    break;
  case '\x0f':
    if (fVar8 <= fVar9) {
      fVar14 = (float10)fVar9;
    }
    else {
      fVar14 = (float10)fVar8;
    }
    break;
  case '\x10':
    if (fVar8 <= fVar9) {
      fVar14 = (float10)_DAT_0057472c - (float10)fVar8;
    }
    else {
      fVar14 = (float10)_DAT_0057472c - (float10)fVar9;
    }
  }
  pRVar7 = param_1->master_obj;
  uVar2 = pRVar7->movement_type;
  fVar14 = fVar14 + (float10)((byte)param_1->tile->field_0x5 >> 5);
  if ((uVar2 == '\0') || ((uVar2 == '\x01' && ((float10)param_1->world_z < fVar14)))) {
    param_1->world_z = (float)fVar14;
  }
  sVar11 = __ftol();
  param_1->screen_x_offset = sVar11;
  sVar11 = __ftol();
  param_1->screen_y_offset = sVar11;
  uVar2 = pRVar7->movement_type;
  if (uVar2 == '\0') {
    param_1->shadow_x_offset = param_1->screen_x_offset;
    param_1->shadow_y_offset = param_1->screen_y_offset;
  }
  else if (uVar2 == '\x01') {
    sVar11 = __ftol();
    param_1->shadow_x_offset = sVar11;
    sVar11 = __ftol();
    param_1->shadow_y_offset = sVar11;
    return extraout_ST0_01;
  }
  return extraout_ST0_00;
}

// --------------------------------------------------

// Function: FUN_004c4b85
// Address: 004c4b85
// XREFS: None
void FUN_004c4b85(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004c4c1e
// Address: 004c4c1e
// XREFS: None
void __thiscall FUN_004c4c1e(int param_1,RGE_Sprite *param_2,uchar param_3)
{
  RGE_Active_Sprite_List::add_sprite
            (*(RGE_Active_Sprite_List **)(param_1 + 0x18),param_2,param_3,0,0);
  return;
}

// --------------------------------------------------

// Function: FUN_004c4c39
// Address: 004c4c39
// XREFS: None
void __thiscall FUN_004c4c39(int param_1,RGE_Sprite *param_2)
{
  RGE_Active_Sprite_List::remove_sprite(*(RGE_Active_Sprite_List **)(param_1 + 0x18),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004c4d7d
// Address: 004c4d7d
// XREFS: None
void __thiscall FUN_004c4d7d(int *param_1,undefined4 param_2,char param_3)
{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  
  if (param_3 == '\0') {
    sVar2 = __ftol();
    param_1[0xc] = (int)(float)(int)sVar2;
  }
  else if (((param_3 == '\x01') && (param_1[7] != 0)) && ((char)param_1[0x12] == '\x02')) {
    iVar1 = *param_1;
    (**(code **)(iVar1 + 0xdc))(param_1[3],0,0xffffffff);
    uVar3 = __ftol();
    (**(code **)(iVar1 + 0xd8))(param_1[3],0,uVar3);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c4dfd
// Address: 004c4dfd
// XREFS: None
void __thiscall FUN_004c4dfd(int *param_1,undefined4 param_2,char param_3)
{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  
  if (param_3 == '\0') {
    sVar2 = __ftol();
    param_1[0xc] = (int)(float)(int)sVar2;
  }
  else if (((param_3 == '\x01') && (param_1[7] != 0)) && ((char)param_1[0x12] == '\x02')) {
    iVar1 = *param_1;
    (**(code **)(iVar1 + 0xdc))(param_1[3],0,0xffffffff);
    uVar3 = __ftol();
    (**(code **)(iVar1 + 0xd8))(param_1[3],0,uVar3);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c4e8b
// Address: 004c4e8b
// XREFS: None
void __thiscall FUN_004c4e8b(int *param_1,undefined4 param_2,char param_3)
{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  
  if (param_3 == '\0') {
    sVar2 = __ftol();
    param_1[0xc] = (int)(float)(int)sVar2;
  }
  else if (((param_3 == '\x01') && (param_1[7] != 0)) && ((char)param_1[0x12] == '\x02')) {
    iVar1 = *param_1;
    (**(code **)(iVar1 + 0xdc))(param_1[3],0,0xffffffff);
    uVar3 = __ftol();
    (**(code **)(iVar1 + 0xd8))(param_1[3],0,uVar3);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c4f04
// Address: 004c4f04
// XREFS: None
void __thiscall FUN_004c4f04(RGE_Static_Object *param_1,RGE_Master_Static_Object *param_2)
{
  short sVar1;
  int iVar2;
  float unaff_EBX;
  
  if (param_1->tile != (RGE_Tile *)0x0) {
    (**(code **)(param_1->_padding_ + 0xdc))(param_1->owner,0,0xffffffff);
  }
  RGE_Static_Object::removeFromObstructionMap(param_1,2);
  param_1->master_obj = param_2;
  if (param_1->tile != (RGE_Tile *)0x0) {
    (**(code **)(param_1->_padding_ + 0xd8))(param_1->owner,0,0xffffffff);
  }
  RGE_Static_Object::addToObstructionMap(param_1,2);
  iVar2 = param_1->_padding_;
  (**(code **)(iVar2 + 0x38))(param_2->sprite);
  sVar1 = param_2->hp;
  param_1->object_state = '\0';
  param_1->hp = (float)(int)sVar1 * unaff_EBX;
  (**(code **)(iVar2 + 0x5c))(2);
  return;
}

// --------------------------------------------------

// Function: FUN_004c4fa7
// Address: 004c4fa7
// XREFS: None
void __thiscall FUN_004c4fa7(int *param_1,int param_2)
{
  float fVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = 0;
  if ((param_1[7] != 0) && ((char)param_1[0x12] == '\x02')) {
    iVar4 = *param_1;
    (**(code **)(iVar4 + 0xdc))(param_1[3],0,0xffffffff);
    uVar6 = __ftol();
    (**(code **)(iVar4 + 0xd8))(param_1[3],0,uVar6);
  }
  sVar2 = *(short *)(param_1[2] + 0x26);
  fVar1 = (float)param_1[0xc];
  param_1[0xc] = (int)(float)(int)sVar2;
  if ((char)param_1[0x12] == '\x02') {
    (**(code **)(*param_1 + 0x28))();
  }
  iVar4 = param_1[2];
  iVar5 = param_1[4];
  if (iVar5 == *(int *)(iVar4 + 0x18)) {
    iVar7 = *(int *)(param_2 + 0x18);
  }
  else if (iVar5 == *(int *)(iVar4 + 0x1c)) {
    iVar7 = *(int *)(param_2 + 0x1c);
  }
  else if (iVar5 == *(int *)(iVar4 + 0x20)) {
    iVar7 = *(int *)(param_2 + 0x20);
  }
  sVar3 = *(short *)(param_2 + 0x26);
  param_1[2] = param_2;
  param_1[0xc] = (int)((float)(int)sVar3 * (fVar1 / (float)(int)sVar2));
  if ((char)param_1[0x12] == '\x02') {
    (**(code **)(*param_1 + 0x28))();
  }
  param_1[2] = iVar4;
  if (iVar7 != 0) {
    (**(code **)(*param_1 + 0x38))(iVar7);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c5075
// Address: 004c5075
// XREFS: None
void __fastcall FUN_004c5075(RGE_Static_Object *param_1)
{
  if (param_1->object_state < 7) {
    if (param_1->inside_obj != (RGE_Static_Object *)0x0) {
      (**(code **)(param_1->_padding_ + 0xd4))();
    }
    if ((param_1->selected & 1) != 0) {
      RGE_Player::unselect_one_object(param_1->owner,param_1);
    }
    RGE_Static_Object::set_sleep_flag(param_1,'\0');
    (**(code **)(param_1->_padding_ + 0x5c))(7);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c50bb
// Address: 004c50bb
// XREFS: None
void __fastcall FUN_004c50bb(RGE_Static_Object *param_1)
{
  if ((param_1->selected & 1) != 0) {
    RGE_Player::unselect_one_object(param_1->owner,param_1);
  }
  RGE_Static_Object::set_sleep_flag(param_1,'\0');
  param_1->hp = 0.0;
  return;
}

// --------------------------------------------------

// Function: FUN_004c50e4
// Address: 004c50e4
// XREFS: None
void __fastcall FUN_004c50e4(RGE_Static_Object *param_1)
{
  RGE_Master_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if ((((-1 < param_1->id) && (param_1->owner != (RGE_Player *)0x0)) &&
      (pRVar1 = param_1->master_obj, pRVar1 != (RGE_Master_Static_Object *)0x0)) &&
     ((pRVar1->create_doppleganger_on_death != '\0' || (pRVar1->track_as_resource != '\0')))) {
    iVar2 = __ftol();
    iVar3 = __ftol();
    uVar4 = (uint)(&unified_map_offsets)[iVar2][iVar3] & 0xffff;
    uVar5 = (uint)(&unified_map_offsets)[iVar2][iVar3] >> 0x10;
    if (uVar5 != 0) {
      iVar2 = 0;
      do {
        if (((byte)uVar5 & 1) == 1) {
          if (param_1->master_obj->track_as_resource != '\0') {
            Visible_Resource_Manager::Remove_Resource
                      (*(Visible_Resource_Manager **)
                        (*(int *)((int)param_1->owner->world->players + iVar2) + 0x110),param_1->id,
                       (uint)param_1->master_obj->resource_group);
          }
          if (((param_1->master_obj->create_doppleganger_on_death == '\x01') && ((uVar4 & 1) == 0))
             && (0 < iVar2)) {
            iVar3 = *(int *)((int)param_1->owner->world->players + iVar2);
            (**(code **)(**(int **)(*(int *)(iVar3 + 0x24) + 0x3cc) + 0x38))
                      (iVar3,param_1->world_x,param_1->world_y,param_1->world_z,param_1);
          }
        }
        iVar2 = iVar2 + 4;
        uVar4 = uVar4 >> 1;
        uVar5 = uVar5 >> 1;
      } while (uVar5 != 0);
    }
    if (param_1->master_obj->create_doppleganger_on_death == '\x02') {
      RGE_Doppleganger_Creator::remove_doppleganger_check
                (param_1->owner->doppleganger_creator,param_1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c52ef
// Address: 004c52ef
// XREFS: None
void __thiscall FUN_004c52ef(RGE_Static_Object *param_1,byte param_2)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  AIPlayStatus *pAVar6;
  int iStack_4;
  
  if (param_1->object_state != param_2) {
    if (((2 < param_2) && (param_1->object_state < 3)) &&
       (RGE_Static_Object::take_attribute_from_owner(param_1),
       param_1->master_obj->create_doppleganger_on_death == '\x02')) {
      (**(code **)(param_1->_padding_ + 100))();
    }
    if ((param_1->object_state < 4) && (6 < param_2)) {
      (**(code **)(param_1->_padding_ + 0x60))();
    }
    if (((2 < param_2) && (param_1->object_state == '\x02')) && (param_1->tile != (RGE_Tile *)0x0))
{
      iVar4 = param_1->_padding_;
      (**(code **)(iVar4 + 0xdc))(param_1->owner,0,0xffffffff);
      if ((float)(double)DAT_00574718 < param_1->master_obj->los) {
        (**(code **)(iVar4 + 0xd8))(param_1->owner,1,0xffffffff);
      }
    }
    if ((((param_1->object_state < 7) && (param_2 == 7)) && (param_1->tile != (RGE_Tile *)0x0)) &&
       ((float)(double)DAT_00574718 < param_1->master_obj->los)) {
      (**(code **)(param_1->_padding_ + 0xdc))(param_1->owner,1,0xffffffff);
    }
    param_1->object_state = param_2;
    if (((param_2 == 3) && (param_1->groupCommanderValue == param_1->id)) &&
       ((param_1->unitAIValue != (UnitAIModule *)0x0 &&
        (iVar4 = (param_1->groupMembers).numberValue, 1 < iVar4)))) {
      iVar5 = 0;
      iStack_4 = -1;
      if (0 < iVar4) {
        do {
          if ((param_1->groupMembers).maximumSizeValue + -1 < iVar5) {
            piVar1 = (int *)operator_new(iVar5 * 4 + 4);
            if (piVar1 != (int *)0x0) {
              iVar4 = 0;
              if (0 < (param_1->groupMembers).maximumSizeValue) {
                do {
                  if (iVar5 + 1 <= iVar4) break;
                  iVar2 = iVar4 + 1;
                  piVar1[iVar4] = (param_1->groupMembers).value[iVar4];
                  iVar4 = iVar2;
                } while (iVar2 < (param_1->groupMembers).maximumSizeValue);
              }
              operator_delete((param_1->groupMembers).value);
              (param_1->groupMembers).value = piVar1;
              (param_1->groupMembers).maximumSizeValue = iVar5 + 1;
            }
          }
          if ((param_1->groupMembers).value[iVar5] != param_1->id) {
            if ((param_1->groupMembers).maximumSizeValue + -1 < iVar5) {
              piVar1 = (int *)operator_new(iVar5 * 4 + 4);
              if (piVar1 != (int *)0x0) {
                iVar4 = 0;
                if (0 < (param_1->groupMembers).maximumSizeValue) {
                  do {
                    if (iVar5 + 1 <= iVar4) break;
                    iVar2 = iVar4 + 1;
                    piVar1[iVar4] = (param_1->groupMembers).value[iVar4];
                    iVar4 = iVar2;
                  } while (iVar2 < (param_1->groupMembers).maximumSizeValue);
                }
                operator_delete((param_1->groupMembers).value);
                (param_1->groupMembers).value = piVar1;
                (param_1->groupMembers).maximumSizeValue = iVar5 + 1;
              }
            }
            this = RGE_Game_World::object
                             (param_1->owner->world,(param_1->groupMembers).value[iVar5]);
            if (((this != (RGE_Static_Object *)0x0) && (this->object_state < 3)) &&
               (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 != (UnitAIModule *)0x0)) {
              if (iStack_4 == -1) {
                if ((param_1->groupMembers).maximumSizeValue + -1 < iVar5) {
                  piVar1 = (int *)operator_new(iVar5 * 4 + 4);
                  if (piVar1 != (int *)0x0) {
                    iVar4 = 0;
                    if (0 < (param_1->groupMembers).maximumSizeValue) {
                      do {
                        if (iVar5 + 1 <= iVar4) break;
                        iVar2 = iVar4 + 1;
                        piVar1[iVar4] = (param_1->groupMembers).value[iVar4];
                        iVar4 = iVar2;
                      } while (iVar2 < (param_1->groupMembers).maximumSizeValue);
                    }
                    operator_delete((param_1->groupMembers).value);
                    (param_1->groupMembers).value = piVar1;
                    (param_1->groupMembers).maximumSizeValue = iVar5 + 1;
                  }
                }
                iStack_4 = (param_1->groupMembers).value[iVar5];
              }
              this->groupCommanderValue = iStack_4;
              if ((param_1->groupMembers).maximumSizeValue + -1 < iVar5) {
                piVar1 = (int *)operator_new(iVar5 * 4 + 4);
                if (piVar1 != (int *)0x0) {
                  iVar4 = 0;
                  if (0 < (param_1->groupMembers).maximumSizeValue) {
                    do {
                      if (iVar5 + 1 <= iVar4) break;
                      iVar2 = iVar4 + 1;
                      piVar1[iVar4] = (param_1->groupMembers).value[iVar4];
                      iVar4 = iVar2;
                    } while (iVar2 < (param_1->groupMembers).maximumSizeValue);
                  }
                  operator_delete((param_1->groupMembers).value);
                  (param_1->groupMembers).value = piVar1;
                  (param_1->groupMembers).maximumSizeValue = iVar5 + 1;
                }
              }
              if ((param_1->groupMembers).value[iVar5] == iStack_4) {
                pAVar6 = param_1->unitAIValue->playStatus;
                pUVar3 = RGE_Static_Object::unitAI(this);
                UnitAIModule::setPlayStatus(pUVar3,pAVar6);
              }
            }
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < (param_1->groupMembers).numberValue);
      }
    }
    if (((param_1->sleep_flag != '\0') && (param_1->object_state != '\x02')) &&
       (param_1->object_state != '\x06')) {
      RGE_Static_Object::set_sleep_flag(param_1,'\0');
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c5603
// Address: 004c5603
// XREFS: None
int __fastcall FUN_004c5603(int param_1)
{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  undefined4 *puVar14;
  float fStack_2c;
  
  fVar1 = *(float *)(*(int *)(param_1 + 8) + 0x30);
  fVar2 = *(float *)(*(int *)(param_1 + 8) + 0x34);
  if ((DAT_00574718._8_4_ < fVar1) || (DAT_00574718._8_4_ < fVar2)) {
    sVar9 = __ftol();
    sVar10 = __ftol();
    sVar11 = __ftol();
    sVar12 = __ftol();
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28);
    if (sVar9 < 0) {
      sVar9 = 0;
    }
    if (*(int *)(iVar3 + 8) <= (int)sVar11) {
      sVar11 = *(short *)(iVar3 + 8) + -1;
    }
    if (sVar10 < 0) {
      sVar10 = 0;
    }
    if (*(int *)(iVar3 + 0xc) <= (int)sVar12) {
      sVar12 = *(short *)(iVar3 + 0xc) + -1;
    }
    if (sVar10 <= sVar12) {
      do {
        if (sVar9 <= sVar11) {
          puVar14 = (undefined4 *)
                    (*(int *)(*(int *)(iVar3 + 0x8d8c) + sVar10 * 4) + sVar9 * 0x18 + 0x10);
          sVar13 = sVar9;
          do {
            for (piVar4 = (int *)*puVar14; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
              iVar5 = *piVar4;
              fVar6 = *(float *)(*(int *)(iVar5 + 8) + 0x30);
              fVar7 = *(float *)(*(int *)(iVar5 + 8) + 0x34);
              if ((DAT_00574718._8_4_ < fVar6) && (DAT_00574718._8_4_ < fVar7)) {
                fVar8 = *(float *)(iVar5 + 0x3c) - *(float *)(param_1 + 0x3c);
                fStack_2c = *(float *)(iVar5 + 0x38) - *(float *)(param_1 + 0x38);
                if (fVar8 < DAT_00574718._8_4_) {
                  fVar8 = -fVar8;
                }
                if (fStack_2c < DAT_00574718._8_4_) {
                  fStack_2c = -fStack_2c;
                }
                if ((fVar8 <= fVar7 + fVar2) && (fStack_2c <= fVar6 + fVar1)) {
                  return iVar5;
                }
              }
            }
            puVar14 = puVar14 + 6;
            sVar13 = sVar13 + 1;
          } while (sVar13 <= sVar11);
        }
        sVar10 = sVar10 + 1;
        if (sVar12 < sVar10) {
          return 0;
        }
      } while( true );
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c581c
// Address: 004c581c
// XREFS: None
float10 __thiscall FUN_004c581c(int param_1,uint param_2)
{
  return (float10)*(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x54) +
                                     *(short *)(*(int *)(param_1 + 8) + 0x66) * 4) +
                            (param_2 & 0xff) * 4);
}

// --------------------------------------------------

// Function: FUN_004c5842
// Address: 004c5842
// XREFS: None
undefined1 FUN_004c5842(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c5853
// Address: 004c5853
// XREFS: None
undefined1 __fastcall FUN_004c5853(int param_1)
{
  if ((2 < *(byte *)(param_1 + 0x48)) && (*(byte *)(param_1 + 0x48) != 6)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

