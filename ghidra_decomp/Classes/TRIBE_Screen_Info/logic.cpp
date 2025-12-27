// Class: TRIBE_Screen_Info
// Function: TRIBE_Screen_Info
// Address: 0049d550
/* public: __thiscall TRIBE_Screen_Info::TRIBE_Screen_Info(char *,char *,long,unsigned long) */

TRIBE_Screen_Info * __thiscall
TRIBE_Screen_Info::TRIBE_Screen_Info
          (TRIBE_Screen_Info *this,char *param_1,char *param_2,long param_3,ulong param_4)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055ef28;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,param_1);
  this->timer = param_4;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->auto_close = (uint)(param_4 != 0);
  this->last_time = 0;
  lVar1 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,param_2,param_3,0);
  if (lVar1 == 0) {
    this->_padding_ = 1;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0049d5e0
/* public: virtual void * __thiscall TRIBE_Screen_Info::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Screen_Info::_scalar_deleting_destructor_(TRIBE_Screen_Info *this,uint param_1)
{
  ~TRIBE_Screen_Info(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Screen_Info
// Address: 0049d600
/* public: virtual __thiscall TRIBE_Screen_Info::~TRIBE_Screen_Info(void) */

void __thiscall TRIBE_Screen_Info::~TRIBE_Screen_Info(TRIBE_Screen_Info *this)
{
  this->_padding_ = (int)&_vftable_;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 0049d610
// [HELPER] s_C__msdev_work_age1_x1_scr_info_c: "C:\msdev\work\age1_x1\scr_info.cpp"
/* public: virtual long __thiscall TRIBE_Screen_Info::handle_idle(void) */

long __thiscall TRIBE_Screen_Info::handle_idle(TRIBE_Screen_Info *this)
{
  ulong uVar1;
  long lVar2;
  
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  if (this->auto_close != 0) {
    if (this->last_time == 0) {
      uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_info_c,0x48);
      this->last_time = uVar1;
      lVar2 = TPanel::handle_idle((TPanel *)this);
      return lVar2;
    }
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_info_c,0x4b);
    if (this->timer < uVar1 - this->last_time) {
      close_screen(this);
      return 0;
    }
  }
  lVar2 = TPanel::handle_idle((TPanel *)this);
  return lVar2;
}

// --------------------------------------------------

// Function: key_down_action
// Address: 0049d690
/* public: virtual long __thiscall TRIBE_Screen_Info::key_down_action(long,short,int,int,int) */

long __thiscall
TRIBE_Screen_Info::key_down_action
          (TRIBE_Screen_Info *this,long param_1,short param_2,int param_3,int param_4,int param_5)
{
  if (((param_1 != 0x12) && (param_1 != 0x11)) && (param_1 != 0x10)) {
    close_screen(this);
  }
  return 0;
}

// --------------------------------------------------

// Function: mouse_left_down_action
// Address: 0049d6b0
/* public: virtual long __thiscall TRIBE_Screen_Info::mouse_left_down_action(long,long,int,int) */

long __thiscall
TRIBE_Screen_Info::mouse_left_down_action
          (TRIBE_Screen_Info *this,long param_1,long param_2,int param_3,int param_4)
{
  close_screen(this);
  return 0;
}

// --------------------------------------------------

// Function: action
// Address: 0049d6c0
/* public: virtual long __thiscall TRIBE_Screen_Info::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TRIBE_Screen_Info::action
          (TRIBE_Screen_Info *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  long lVar1;
  
  lVar1 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

// Function: close_screen
// Address: 0049d6e0
// [HELPER] s_DeathMatch: "DeathMatch"
// [HELPER] s_FeaturesInfo: "FeaturesInfo"
// [HELPER] s_Logo1Screen: "Logo1Screen"
// [HELPER] s_Logo2Screen: "Logo2Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_QuotesInfo: "QuotesInfo"
// [HELPER] s_RandomMap: "RandomMap"
// [HELPER] s_ScenarioEditorInfo: "ScenarioEditorInfo"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
// [HELPER] s_TechInfo: "TechInfo"
// [HELPER] s_UnitInfo1: "UnitInfo1"
// [HELPER] s_UnitInfo2: "UnitInfo2"
// [HELPER] s_UnitInfo3: "UnitInfo3"
// [HELPER] s_scrinfqu: "scrinfqu"
// [HELPER] s_scrlogo2: "scrlogo2"
// [HELPER] s_scrtech: "scrtech"
// [HELPER] s_scrunit1: "scrunit1"
// [HELPER] s_scrunit2: "scrunit2"
// [HELPER] s_scrunit3: "scrunit3"
/* public: void __thiscall TRIBE_Screen_Info::close_screen(void) */

void __thiscall TRIBE_Screen_Info::close_screen(TRIBE_Screen_Info *this)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  TribeSPMenuScreen *pTVar4;
  TRIBE_Screen_Info *pTVar5;
  TRIBE_Screen_Main_Menu *this_00;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 *unaff_FS_OFFSET;
  bool bVar8;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055efa3;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pbVar6 = (byte *)this->_padding_;
  pbVar7 = &s_RandomMap;
  pbVar2 = pbVar6;
  do {
    bVar1 = *pbVar2;
    bVar8 = bVar1 < *pbVar7;
    if (bVar1 != *pbVar7) {
LAB_0049d72f:
      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_0049d733;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar8 = bVar1 < pbVar7[1];
    if (bVar1 != pbVar7[1]) goto LAB_0049d72f;
    pbVar2 = pbVar2 + 2;
    pbVar7 = pbVar7 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0049d733:
  if (iVar3 == 0) {
    RGE_Base_Game::disable_input(rge_base_game);
    pTVar4 = (TribeSPMenuScreen *)operator_new(0x49c);
    local_4 = 0;
    if (pTVar4 != (TribeSPMenuScreen *)0x0) {
      TribeSPMenuScreen::TribeSPMenuScreen(pTVar4);
    }
    local_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Single_Player_Menu,0);
    TPanelSystem::destroyPanel(&panel_system,&s_RandomMap);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  pbVar7 = &s_DeathMatch;
  pbVar2 = pbVar6;
  do {
    bVar1 = *pbVar2;
    bVar8 = bVar1 < *pbVar7;
    if (bVar1 != *pbVar7) {
LAB_0049d7cc:
      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_0049d7d0;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar8 = bVar1 < pbVar7[1];
    if (bVar1 != pbVar7[1]) goto LAB_0049d7cc;
    pbVar2 = pbVar2 + 2;
    pbVar7 = pbVar7 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0049d7d0:
  if (iVar3 == 0) {
    RGE_Base_Game::disable_input(rge_base_game);
    pTVar4 = (TribeSPMenuScreen *)operator_new(0x49c);
    local_4 = 1;
    if (pTVar4 != (TribeSPMenuScreen *)0x0) {
      TribeSPMenuScreen::TribeSPMenuScreen(pTVar4);
    }
    local_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Single_Player_Menu,0);
    TPanelSystem::destroyPanel(&panel_system,&s_DeathMatch);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  pbVar7 = &s_Logo1Screen;
  pbVar2 = pbVar6;
  do {
    bVar1 = *pbVar2;
    bVar8 = bVar1 < *pbVar7;
    if (bVar1 != *pbVar7) {
LAB_0049d869:
      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_0049d86d;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar8 = bVar1 < pbVar7[1];
    if (bVar1 != pbVar7[1]) goto LAB_0049d869;
    pbVar2 = pbVar2 + 2;
    pbVar7 = pbVar7 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0049d86d:
  if (iVar3 == 0) {
    pTVar5 = (TRIBE_Screen_Info *)operator_new(0x484);
    local_4 = 2;
    if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
                    /* language.dll match for 0x7d0: "place holder" */
      TRIBE_Screen_Info(pTVar5,&s_Logo2Screen,s_scrlogo2,0xc392,2000);
    }
    local_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,&s_Logo2Screen,0);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  pbVar7 = &s_Logo2Screen;
  pbVar2 = pbVar6;
  do {
    bVar1 = *pbVar2;
    bVar8 = bVar1 < *pbVar7;
    if (bVar1 != *pbVar7) {
LAB_0049d900:
      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_0049d904;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar8 = bVar1 < pbVar7[1];
    if (bVar1 != pbVar7[1]) goto LAB_0049d900;
    pbVar2 = pbVar2 + 2;
    pbVar7 = pbVar7 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0049d904:
  if (iVar3 == 0) {
    iVar3 = TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
    if (iVar3 != 0) goto LAB_0049d922;
  }
  else {
    pbVar7 = &s_ScenarioEditorInfo;
    pbVar2 = pbVar6;
    do {
      bVar1 = *pbVar2;
      bVar8 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_0049d964:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0049d968;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar8 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_0049d964;
      pbVar2 = pbVar2 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0049d968:
    if (iVar3 == 0) {
      RGE_Base_Game::disable_input(rge_base_game);
      pTVar5 = (TRIBE_Screen_Info *)operator_new(0x484);
      local_4 = 3;
      if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
        TRIBE_Screen_Info(pTVar5,&s_UnitInfo1,s_scrunit1,0xc394,0);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,&s_UnitInfo1,0);
      TPanelSystem::destroyPanel(&panel_system,&s_ScenarioEditorInfo);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    pbVar7 = &s_UnitInfo1;
    pbVar2 = pbVar6;
    do {
      bVar1 = *pbVar2;
      bVar8 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_0049da12:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0049da16;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar8 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_0049da12;
      pbVar2 = pbVar2 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0049da16:
    if (iVar3 == 0) {
      RGE_Base_Game::disable_input(rge_base_game);
      pTVar5 = (TRIBE_Screen_Info *)operator_new(0x484);
      local_4 = 4;
      if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
        TRIBE_Screen_Info(pTVar5,&s_UnitInfo2,s_scrunit2,0xc395,0);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,&s_UnitInfo2,0);
      TPanelSystem::destroyPanel(&panel_system,&s_UnitInfo1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    pbVar7 = &s_UnitInfo2;
    pbVar2 = pbVar6;
    do {
      bVar1 = *pbVar2;
      bVar8 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_0049dac0:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0049dac4;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar8 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_0049dac0;
      pbVar2 = pbVar2 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0049dac4:
    if (iVar3 == 0) {
      RGE_Base_Game::disable_input(rge_base_game);
      pTVar5 = (TRIBE_Screen_Info *)operator_new(0x484);
      local_4 = 5;
      if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
        TRIBE_Screen_Info(pTVar5,&s_UnitInfo3,s_scrunit3,0xc396,0);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,&s_UnitInfo3,0);
      TPanelSystem::destroyPanel(&panel_system,&s_UnitInfo2);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    pbVar7 = &s_UnitInfo3;
    pbVar2 = pbVar6;
    do {
      bVar1 = *pbVar2;
      bVar8 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_0049db6e:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0049db72;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar8 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_0049db6e;
      pbVar2 = pbVar2 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0049db72:
    if (iVar3 == 0) {
      RGE_Base_Game::disable_input(rge_base_game);
                    /* language.dll match for 0x4b0: "Ready" */
      this_00 = (TRIBE_Screen_Main_Menu *)operator_new(0x4b0);
      local_4 = 6;
      if (this_00 != (TRIBE_Screen_Main_Menu *)0x0) {
        TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(this_00);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
      TPanelSystem::destroyPanel(&panel_system,&s_UnitInfo3);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    pbVar7 = &s_FeaturesInfo;
    pbVar2 = pbVar6;
    do {
      bVar1 = *pbVar2;
      bVar8 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_0049dc0b:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0049dc0f;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar8 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_0049dc0b;
      pbVar2 = pbVar2 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0049dc0f:
    if (iVar3 == 0) {
      RGE_Base_Game::disable_input(rge_base_game);
      pTVar5 = (TRIBE_Screen_Info *)operator_new(0x484);
      local_4 = 7;
      if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
        TRIBE_Screen_Info(pTVar5,&s_TechInfo,s_scrtech,0xc393,0);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,&s_TechInfo,0);
      TPanelSystem::destroyPanel(&panel_system,&s_FeaturesInfo);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    pbVar2 = &s_TechInfo;
    do {
      bVar1 = *pbVar6;
      bVar8 = bVar1 < *pbVar2;
      if (bVar1 != *pbVar2) {
LAB_0049dcb9:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0049dcbd;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar6[1];
      bVar8 = bVar1 < pbVar2[1];
      if (bVar1 != pbVar2[1]) goto LAB_0049dcb9;
      pbVar6 = pbVar6 + 2;
      pbVar2 = pbVar2 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0049dcbd:
    if (iVar3 == 0) {
      RGE_Base_Game::disable_input(rge_base_game);
      pTVar5 = (TRIBE_Screen_Info *)operator_new(0x484);
      local_4 = 8;
      if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
        TRIBE_Screen_Info(pTVar5,s_QuotesInfo,s_scrinfqu,0xc38f,0);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_QuotesInfo,0);
      TPanelSystem::destroyPanel(&panel_system,&s_TechInfo);
      *unaff_FS_OFFSET = local_c;
      return;
    }
  }
  RGE_Base_Game::close(rge_base_game);
LAB_0049d922:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

