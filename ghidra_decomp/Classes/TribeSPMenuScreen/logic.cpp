// Class: TribeSPMenuScreen
// Function: TribeSPMenuScreen
// Address: 004b69a0
// [HELPER] s_: ""
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
// [HELPER] s_scr2: "scr2"
/* public: __thiscall TribeSPMenuScreen::TribeSPMenuScreen(void) */

TribeSPMenuScreen * __thiscall TribeSPMenuScreen::TribeSPMenuScreen(TribeSPMenuScreen *this)
{
  TButtonPanel *pTVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  TButtonPanel **ppTVar5;
  TButtonPanel **ppTVar6;
  TPanel **ppTVar7;
  undefined4 *unaff_FS_OFFSET;
  TPanel *tabList [6];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f6d8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  tabList[0] = (TPanel *)this;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Single_Player_Menu);
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  RGE_Base_Game::setSinglePlayerGame(rge_base_game,1);
  RGE_Base_Game::setScenarioName(rge_base_game,s_);
  lVar2 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,&s_scr2,0xc384,1);
  if (lVar2 == 0) {
    this->_padding_ = 1;
    *unaff_FS_OFFSET = local_c;
    return this;
  }
  ppTVar6 = this->button;
  ppTVar5 = ppTVar6;
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppTVar5 = (TButtonPanel *)0x0;
    ppTVar5 = ppTVar5 + 1;
  }
  this->close_button = (TButtonPanel *)0x0;
  TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
                    /* language.dll match for 0x2404: "Single Player Menu" */
  iVar4 = TEasy_Panel::create_text
                    ((TEasy_Panel *)this,(TPanel *)this,&this->title,0x2404,0x14,0x14,600,0x1e,1,1,0
                     ,0);
  if (iVar4 != 0) {
                    /* language.dll match for 0x76: "B" */
    iVar4 = 0x76;
    ppTVar5 = ppTVar6;
    do {
      iVar3 = TEasy_Panel::create_button
                        ((TEasy_Panel *)this,(TPanel *)this,ppTVar5,s_,(char *)0x0,0xaa,iVar4,300,
                         0x28,0,0,0);
      if (iVar3 == 0) goto LAB_004b6bc8;
      iVar4 = iVar4 + 0x32;
      ppTVar5 = ppTVar5 + 1;
    } while (iVar4 < 0x1a2);
    ppTVar5 = &this->close_button;
                    /* language.dll match for 0x3ea: "X" */
    iVar4 = TEasy_Panel::create_button
                      ((TEasy_Panel *)this,(TPanel *)this,ppTVar5,0x3ea,0,0,0,0,0,-1,-1,0);
    if (iVar4 != 0) {
      (**(code **)((*ppTVar5)->_padding_ + 0x14))(1);
      (**(code **)((*ppTVar5)->_padding_ + 0x18))(9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
                    /* language.dll match for 0x240a: "Random Map" */
      TButtonPanel::set_text(*ppTVar6,0,0x240a);
                    /* language.dll match for 0x2408: "Campaign" */
      TButtonPanel::set_text(this->button[1],0,0x2408);
                    /* language.dll match for 0x240b: "Death Match" */
      TButtonPanel::set_text(this->button[2],0,0x240b);
                    /* language.dll match for 0x2405: "Scenario" */
      TButtonPanel::set_text(this->button[3],0,0x2405);
                    /* language.dll match for 0x2407: "Saved Game" */
      TButtonPanel::set_text(this->button[4],0,0x2407);
                    /* language.dll match for 0x2409: "Cancel" */
      TButtonPanel::set_text(this->button[5],0,0x2409);
      pTVar1 = this->button[5];
      pTVar1->hotkey = 0x1b;
      pTVar1->hotkey_shift = 0;
      TPanel::set_curr_child((TPanel *)this,(TPanel *)*ppTVar6);
      ppTVar7 = tabList;
      for (iVar4 = 6; ppTVar7 = ppTVar7 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
        *ppTVar7 = (TPanel *)*ppTVar6;
        ppTVar6 = ppTVar6 + 1;
      }
      TPanel::set_tab_order((TPanel *)this,tabList + 1,6);
    }
  }
LAB_004b6bc8:
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004b6be0
/* public: virtual void * __thiscall TribeSPMenuScreen::`vector deleting destructor'(unsigned int)
    */

void * __thiscall
TribeSPMenuScreen::_vector_deleting_destructor_(TribeSPMenuScreen *this,uint param_1)
{
  ~TribeSPMenuScreen(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeSPMenuScreen
// Address: 004b6c00
/* public: virtual __thiscall TribeSPMenuScreen::~TribeSPMenuScreen(void) */

void __thiscall TribeSPMenuScreen::~TribeSPMenuScreen(TribeSPMenuScreen *this)
{
  int iVar1;
  TButtonPanel **ppTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f6f8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title);
  ppTVar2 = this->button;
  iVar1 = 7;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->close_button);
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 004b6c90
/* public: virtual long __thiscall TribeSPMenuScreen::handle_idle(void) */

long __thiscall TribeSPMenuScreen::handle_idle(TribeSPMenuScreen *this)
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
// Address: 004b6cc0
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Name_Selection_Screen: "Name Selection Screen"
// [HELPER] s_Select_Scenario_Screen: "Select Scenario Screen"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
/* public: virtual long __thiscall TribeSPMenuScreen::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TribeSPMenuScreen::action
          (TribeSPMenuScreen *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  long lVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f75d;
  *unaff_FS_OFFSET = &local_c;
  if ((param_1 != (TPanel *)0x0) && (param_2 == 1)) {
    if ((TButtonPanel *)param_1 == this->button[0]) {
      RGE_Base_Game::setCampaignGame(rge_base_game,0);
      RGE_Base_Game::setSavedGame(rge_base_game,0);
      RGE_Base_Game::setScenarioGame(rge_base_game,0);
      TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game,'\0');
      TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game,'\0');
      RGE_Base_Game::disable_input(rge_base_game);
      param_1 = (TPanel *)operator_new(0x890);
      local_4 = 0;
    }
    else {
      if ((TButtonPanel *)param_1 != this->button[2]) {
        if ((TButtonPanel *)param_1 == this->button[3]) {
          RGE_Base_Game::setCampaignGame(rge_base_game,0);
          RGE_Base_Game::setSavedGame(rge_base_game,0);
          RGE_Base_Game::setScenarioGame(rge_base_game,1);
          TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game,'\0');
          TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game,'\0');
          RGE_Base_Game::disable_input(rge_base_game);
          param_1 = (TPanel *)operator_new(0x4d8);
          local_4 = 2;
          if ((TribeSelectScenarioScreen *)param_1 != (TribeSelectScenarioScreen *)0x0) {
            TribeSelectScenarioScreen::TribeSelectScenarioScreen
                      ((TribeSelectScenarioScreen *)param_1);
          }
          local_4 = 0xffffffff;
          TPanelSystem::setCurrentPanel(&panel_system,s_Select_Scenario_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
          *unaff_FS_OFFSET = local_c;
          return 1;
        }
        if ((TButtonPanel *)param_1 == this->button[4]) {
          RGE_Base_Game::disable_input(rge_base_game);
          param_1 = (TPanel *)operator_new(0x494);
          local_4 = 3;
          if ((TribeLoadSavedGameScreen *)param_1 != (TribeLoadSavedGameScreen *)0x0) {
            TribeLoadSavedGameScreen::TribeLoadSavedGameScreen((TribeLoadSavedGameScreen *)param_1);
          }
          local_4 = 0xffffffff;
          TPanelSystem::setCurrentPanel(&panel_system,s_Load_Saved_Game_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
          *unaff_FS_OFFSET = local_c;
          return 1;
        }
        if ((TButtonPanel *)param_1 == this->button[1]) {
          RGE_Base_Game::disable_input(rge_base_game);
          param_1 = (TPanel *)0x0;
          lVar1 = RGE_Game_Info::get_people_list
                            (rge_base_game->player_game_info,(char ***)&param_1,&param_2);
          if (0 < lVar1) {
            iVar2 = 0;
            if (0 < lVar1) {
              do {
                free((&param_1->_padding_)[iVar2]);
                iVar2 = iVar2 + 1;
              } while (iVar2 < lVar1);
            }
            free(param_1);
            if (0 < lVar1) {
              param_4 = (ulong)operator_new(0x4a0);
              local_4 = 4;
              if ((TRIBE_Screen_Name *)param_4 != (TRIBE_Screen_Name *)0x0) {
                TRIBE_Screen_Name::TRIBE_Screen_Name((TRIBE_Screen_Name *)param_4);
              }
              local_4 = 0xffffffff;
              TPanelSystem::setCurrentPanel(&panel_system,s_Name_Selection_Screen,0);
              TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
              *unaff_FS_OFFSET = local_c;
              return 1;
            }
          }
          param_4 = (ulong)operator_new(0x4a4);
          local_4 = 5;
          if ((TRIBE_Dialog_Name *)param_4 != (TRIBE_Dialog_Name *)0x0) {
            TRIBE_Dialog_Name::TRIBE_Dialog_Name((TRIBE_Dialog_Name *)param_4,(TScreenPanel *)this);
            *unaff_FS_OFFSET = local_c;
            return 1;
          }
        }
        else {
          if ((TButtonPanel *)param_1 == this->button[5]) {
            RGE_Base_Game::disable_input(rge_base_game);
                    /* language.dll match for 0x4b0: "Ready" */
            param_1 = (TPanel *)operator_new(0x4b0);
            local_4 = 6;
            if ((TRIBE_Screen_Main_Menu *)param_1 != (TRIBE_Screen_Main_Menu *)0x0) {
              TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu((TRIBE_Screen_Main_Menu *)param_1);
            }
            local_4 = 0xffffffff;
            TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
            TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
            *unaff_FS_OFFSET = local_c;
            return 1;
          }
          if ((TButtonPanel *)param_1 != this->close_button) goto LAB_004b710b;
          RGE_Base_Game::close(rge_base_game);
        }
        *unaff_FS_OFFSET = local_c;
        return 1;
      }
      RGE_Base_Game::setCampaignGame(rge_base_game,0);
      RGE_Base_Game::setSavedGame(rge_base_game,0);
      RGE_Base_Game::setScenarioGame(rge_base_game,0);
      TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game,'\x01');
      TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game,'\0');
      RGE_Base_Game::disable_input(rge_base_game);
      param_1 = (TPanel *)operator_new(0x890);
      local_4 = 1;
    }
    if ((TribeMPSetupScreen *)param_1 != (TribeMPSetupScreen *)0x0) {
      TribeMPSetupScreen::TribeMPSetupScreen((TribeMPSetupScreen *)param_1);
    }
    local_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
    TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
    *unaff_FS_OFFSET = local_c;
    return 1;
  }
LAB_004b710b:
  lVar1 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  *unaff_FS_OFFSET = local_c;
  return lVar1;
}

// --------------------------------------------------

