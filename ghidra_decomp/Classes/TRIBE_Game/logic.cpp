// Class: TRIBE_Game
// Function: TRIBE_Game
// Address: 00521120
/* public: __thiscall TRIBE_Game::TRIBE_Game(struct RGE_Prog_Info *,int) */

TRIBE_Game * __thiscall TRIBE_Game::TRIBE_Game(TRIBE_Game *this,RGE_Prog_Info *param_1,int param_2)
{
  long *plVar1;
  int iVar2;
  int **ppiVar3;
  int *piVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561568;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Base_Game::RGE_Base_Game((RGE_Base_Game *)this,param_1,0);
  this->video_window = (void *)0x0;
  this->cur_video = -1;
  this->old_video_wnd_proc = (void *)0x0;
  this->video_paused = 0;
  this->last_video_time = 0;
  this->video_setup = 0;
  this->video_double_size = 0;
  this->video_changed_res = 0;
  this->video_hi_color = 0;
  this->video_save_res_wid = 0;
  this->video_save_res_hgt = 0;
  this->video_save_palette = (void *)0x0;
  this->started_menu_music = 0;
  this->show_object_id = 0;
  this->game_screen = (TRIBE_Screen_Game *)0x0;
  this->inHandleIdle = 0;
  this->_padding_ = (int)&_vftable_;
  this->_padding_ = 1;
  this->_padding_ = 0;
  this->testing_scenario[0] = '\0';
  StringTableX = (void *)0x0;
  this->startup_scenario[0] = '\0';
  this->startup_game[0] = '\0';
  this->save_game_name[0] = '\0';
  this->load_game_name[0] = '\0';
  this->auto_exit_time = 0;
  this->timing_text2[0] = '\0';
  disable_terrain_sounds = 0;
  out_of_sync = 0;
  out_of_sync2 = 0;
  local_4 = 0;
  this->MouseRightClickTable = (MouseClickInfo *)0x0;
  this->MouseRightClickTableSize = 0;
  this->MouseLeftClickTable = (MouseClickInfo *)0x0;
  this->MouseLeftClickTableSize = 0;
  setMapSize(this,Medium);
  setMapType(this,WaterAndLand);
  setAnimals(this,1);
  setPredators(this,1);
  setVictoryType(this,VictoryConquest,1);
  setAllowTrading(this,1);
  setLongCombat(this,0);
  setRandomizePositions(this,0);
  setFullTechTree(this,0);
  setResourceLevel(this,DefaultResources);
  setStartingAge(this,DefaultAge);
  setStartingUnits(this,0);
  setDeathMatch(this,'\0');
  setPopLimit(this,'2');
  setQuickStartGame(this,'\0');
  setRandomStartValue(this,-1);
  plVar1 = this->notification_loc_y;
  iVar2 = 5;
  do {
    plVar1[-5] = -1;
    *plVar1 = -1;
    plVar1 = plVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->current_notification_loc = -1;
  this->current_notification_recalled = -1;
  param_1 = (RGE_Prog_Info *)0x1;
  iVar2 = 0;
  ppiVar3 = &player_dropped;
  do {
    setCivilization(this,iVar2,(int)param_1);
    param_1 = (RGE_Prog_Info *)(param_1->prog_name + 1);
    if (0x10 < (int)param_1) {
      param_1 = (RGE_Prog_Info *)0x1;
    }
    setScenarioPlayer(this,iVar2,iVar2);
    setPlayerColor(this,iVar2,1);
    setComputerName(this,iVar2,0);
    *ppiVar3 = (int *)0x0;
    ppiVar3 = ppiVar3 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)ppiVar3 < 0x86bccc);
  piVar4 = this->save_humanity;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  RGE_Base_Game::setNumberPlayers((RGE_Base_Game *)this,4);
  resetRandomComputerName(this);
  if (param_2 != 0) {
    iVar2 = setup(this);
    if ((iVar2 == 0) && (this->_padding_ == 0)) {
      this->_padding_ = 1;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00521380
/* public: virtual void * __thiscall TRIBE_Game::`vector deleting destructor'(unsigned int) */

void * __thiscall TRIBE_Game::_vector_deleting_destructor_(TRIBE_Game *this,uint param_1)
{
  ~TRIBE_Game(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Game
// Address: 005213a0
// [HELPER] s_Border_drs: "Border.drs"
// [HELPER] s_Campaign_Editor_Screen: "Campaign Editor Screen"
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_Connecting_Screen: "Connecting Screen"
// [HELPER] s_Create_Dialog: "Create Dialog"
// [HELPER] s_End_Screen: "End Screen"
// [HELPER] s_FeaturesInfo: "FeaturesInfo"
// [HELPER] s_Game_Settings_Screen: "Game Settings Screen"
// [HELPER] s_Game_Setup_Screen: "Game Setup Screen"
// [HELPER] s_Interfac_drs: "Interfac.drs"
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
// [HELPER] s_Logo1Screen: "Logo1Screen"
// [HELPER] s_Logo2Screen: "Logo2Screen"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_MP_Startup_Screen: "MP Startup Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Name_Selection_Screen: "Name Selection Screen"
// [HELPER] s_New_Name_Dialog: "New Name Dialog"
// [HELPER] s_QuotesInfo: "QuotesInfo"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_ScenarioEditorInfo: "ScenarioEditorInfo"
// [HELPER] s_Scenario_Editor_Menu: "Scenario Editor Menu"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_Select_Scenario_Screen: "Select Scenario Screen"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s_Temp_Screen: "Temp Screen"
// [HELPER] s_Terrain_drs: "Terrain.drs"
// [HELPER] s_Video_Screen: "Video Screen"
// [HELPER] s_graphics_drs: "graphics.drs"
// [HELPER] s_sounds_drs: "sounds.drs"
/* public: virtual __thiscall TRIBE_Game::~TRIBE_Game(void) */

void __thiscall TRIBE_Game::~TRIBE_Game(TRIBE_Game *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00561588;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  this->inHandleIdle = 0;
  this->_padding_ = 0;
  if (this->_padding_ != 0) {
    DestroyWindow(this->_padding_);
    this->_padding_ = 0;
  }
  close_game_screens(this,1);
  TPanelSystem::destroyPanel(&panel_system,s_Video_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Create_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Campaign_Editor_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Game_Setup_Screen);
  TPanelSystem::destroyPanel(&panel_system,&s_Game_Settings_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Select_Scenario_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Campaign_Selection_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Load_Saved_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_MP_Startup_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_MP_Setup_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Connecting_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Join_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Main_Menu);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_End_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Menu);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Open);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
  TPanelSystem::destroyPanel(&panel_system,&s_New_Name_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Name_Selection_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Temp_Screen);
  TPanelSystem::destroyPanel(&panel_system,&s_ScenarioEditorInfo);
  TPanelSystem::destroyPanel(&panel_system,&s_FeaturesInfo);
  TPanelSystem::destroyPanel(&panel_system,s_QuotesInfo);
  TPanelSystem::destroyPanel(&panel_system,&s_Logo1Screen);
  TPanelSystem::destroyPanel(&panel_system,&s_Logo2Screen);
  RESFILE_close_new_resource_file(s_sounds_drs);
  RESFILE_close_new_resource_file(s_graphics_drs);
  RESFILE_close_new_resource_file(s_Terrain_drs);
  RESFILE_close_new_resource_file(s_Border_drs);
  RESFILE_close_new_resource_file(s_Interfac_drs);
  if (StringTableX != (void *)0x0) {
    FreeLibrary(StringTableX);
    StringTableX = (void *)0x0;
  }
  local_4 = 0xffffffff;
  RGE_Base_Game::~RGE_Base_Game((RGE_Base_Game *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: close_game_screens
// Address: 00521620
// [HELPER] s_About_Dialog: "About Dialog"
// [HELPER] s_Achievements_Screen: "Achievements Screen"
// [HELPER] s_CloseProgramDialog: "CloseProgramDialog"
// [HELPER] s_Diplomacy_Dialog: "Diplomacy Dialog"
// [HELPER] s_End_Screen: "End Screen"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Help_Dialog: "Help Dialog"
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
// [HELPER] s_Menu_Dialog: "Menu Dialog"
// [HELPER] s_Mission_Dialog: "Mission Dialog"
// [HELPER] s_Multiplayer_Disconnect_Screen: "Multiplayer Disconnect Screen"
// [HELPER] s_Multiplayer_Wait_Screen: "Multiplayer Wait Screen"
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s_Object_List_Dialog: "Object List Dialog"
// [HELPER] s_QuitAndLoadDialog: "QuitAndLoadDialog"
// [HELPER] s_QuitGameDialog: "QuitGameDialog"
// [HELPER] s_ResignDialog: "ResignDialog"
// [HELPER] s_RestartDialog: "RestartDialog"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Send_Message_Dialog: "Send Message Dialog"
// [HELPER] s_Send_Quick_Message_Dialog: "Send Quick Message Dialog"
// [HELPER] s_YesNoDialog: "YesNoDialog"
/* public: void __thiscall TRIBE_Game::close_game_screens(int) */

void __thiscall TRIBE_Game::close_game_screens(TRIBE_Game *this,int param_1)
{
  TPanelSystem::destroyPanel(&panel_system,&s_Object_List_Dialog);
  TPanelSystem::destroyPanel(&panel_system,&s_OKDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_RestartDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_QuitGameDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_CloseProgramDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_QuitAndLoadDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_ResignDialog);
  TPanelSystem::destroyPanel(&panel_system,s_Help_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_About_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Send_Quick_Message_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Mission_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Send_Message_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Diplomacy_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Load_Saved_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_End_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Achievements_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Multiplayer_Wait_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Multiplayer_Disconnect_Screen);
  if (param_1 != 0) {
    this->game_screen = (TRIBE_Screen_Game *)0x0;
    TPanelSystem::destroyPanel(&panel_system,s_Game_Screen);
  }
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 00521790
// [HELPER] s_: ""
// [HELPER] s_Border_drs: "Border.drs"
// [HELPER] s_InputDisabledWindow: "InputDisabledWindow"
// [HELPER] s_Interfac_drs: "Interfac.drs"
// [HELPER] s_LOBBY: "LOBBY"
// [HELPER] s_MAKERES: "MAKERES"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_Main_Error_Screen: "Main Error Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Makeres: "Makeres"
// [HELPER] s_STATIC: "STATIC"
// [HELPER] s_STRING_: "STRING="
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s_Terrain_drs: "Terrain.drs"
// [HELPER] s_______________________________: "------------------------------"
// [HELPER] s_data_: "data\"
// [HELPER] s_data__s__size__d__date__d__d__d_: "data=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d"
// [HELPER] s_graphics_drs: "graphics.drs"
// [HELPER] s_graphics_rm: "graphics.rm"
// [HELPER] s_interfac_rm: "interfac.rm"
// [HELPER] s_languagex_dll: "languagex.dll"
// [HELPER] s_logo1: "logo1"
// [HELPER] s_makeres: "makeres"
// [HELPER] s_options__s: "options=%s"
// [HELPER] s_program__s__size__d__date__d__d_: "program=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d"
// [HELPER] s_resource_: "resource\"
// [HELPER] s_scr1: "scr1"
// [HELPER] s_sounds_drs: "sounds.drs"
// [HELPER] s_sounds_rm: "sounds.rm"
// [HELPER] s_tribe: "tribe"
/* protected: virtual int __thiscall TRIBE_Game::setup(void) */

int __thiscall TRIBE_Game::setup(TRIBE_Game *this)
{
  char cVar1;
  uchar uVar2;
  int iVar3;
  char *pcVar4;
  TRIBE_Screen_Main_Error *this_00;
  TEasy_Panel *this_01;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  uint unaff_EDI;
  char *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined2 uStack_920;
  undefined2 uStack_91e;
  _SYSTEMTIME file_time;
  tagPALETTEENTRY pal_entries [7];
  char new_string_dll_name [100];
  _WIN32_FIND_DATAA file_data;
  char cmd_line [256];
  char str [1024];
  ICINFO ici;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005615d8;
  *unaff_FS_OFFSET = &local_c;
  file_time.wYear = (ushort)unaff_EBX;
  file_time.wMonth = (ushort)((uint)unaff_EBX >> 0x10);
  uStack_920 = (undefined2)unaff_EBP;
  uStack_91e = (undefined2)((uint)unaff_EBP >> 0x10);
  if (this->_padding_ != 0) {
    iVar3 = 0;
    goto LAB_00521e5b;
  }
  iVar3 = strstr(this->_padding_ + 0x518,s_makeres);
  if (((iVar3 != 0) || (iVar3 = strstr(this->_padding_ + 0x518,s_Makeres), iVar3 != 0)) ||
     (iVar3 = strstr(this->_padding_ + 0x518,s_MAKERES), iVar3 != 0)) {
    RESFILE_build_res_file(s_graphics_rm,s_resource_,(char *)(this->_padding_ + 0xf26));
    RESFILE_build_res_file(s_sounds_rm,s_resource_,(char *)(this->_padding_ + 0xf26));
    RESFILE_build_res_file(s_interfac_rm,s_resource_,(char *)(this->_padding_ + 0xf26));
  }
  RESFILE_open_new_resource_file(s_sounds_drs,s_tribe,(char *)(this->_padding_ + 0xf26),1);
  RESFILE_open_new_resource_file(s_graphics_drs,s_tribe,(char *)(this->_padding_ + 0xf26),0);
  RESFILE_open_new_resource_file(s_Interfac_drs,s_tribe,(char *)(this->_padding_ + 0xf26),0);
  RESFILE_open_new_resource_file(s_sounds_drs,s_tribe,s_data_,1);
  RESFILE_open_new_resource_file(s_graphics_drs,s_tribe,s_data_,0);
  RESFILE_open_new_resource_file(s_Terrain_drs,s_tribe,s_data_,0);
  RESFILE_open_new_resource_file(s_Border_drs,s_tribe,s_data_,0);
  RESFILE_open_new_resource_file(s_Interfac_drs,s_tribe,s_data_,0);
  iVar3 = RGE_Base_Game::setup((RGE_Base_Game *)this);
  if (iVar3 == 0) goto LAB_00521e5b;
  strncpy(cmd_line + 4,this->_padding_ + 0x518,0xff);
  str[3] = '\0';
  CharUpperA(cmd_line + 4);
  pcVar4 = (char *)__mbsstr(cmd_line,s_STRING_);
  new_string_dll_name[0] = (char)s_languagex_dll;
  new_string_dll_name[1] = s_languagex_dll._1_1_;
  new_string_dll_name[2] = s_languagex_dll._2_1_;
  new_string_dll_name[3] = s_languagex_dll._3_1_;
  new_string_dll_name[4] = (char)DAT_0058ba38;
  new_string_dll_name[5] = DAT_0058ba38._1_1_;
  new_string_dll_name[6] = DAT_0058ba38._2_1_;
  new_string_dll_name[7] = DAT_0058ba38._3_1_;
  new_string_dll_name[8] = (char)DAT_0058ba3c;
  new_string_dll_name[9] = DAT_0058ba3c._1_1_;
  new_string_dll_name[10] = DAT_0058ba3c._2_1_;
  new_string_dll_name[0xb] = DAT_0058ba3c._3_1_;
  new_string_dll_name[0xc] = (char)DAT_0058ba40;
  new_string_dll_name[0xd] = DAT_0058ba40._1_1_;
  pcVar5 = new_string_dll_name + 0xe;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pcVar5 + 4;
  }
  pcVar5[0] = '\0';
  pcVar5[1] = '\0';
  if (pcVar4 != (char *)0x0) {
    cVar1 = *pcVar4;
    new_string_dll_name._0_4_ = s_languagex_dll;
    new_string_dll_name._4_4_ = DAT_0058ba38;
    new_string_dll_name._8_4_ = DAT_0058ba3c;
    new_string_dll_name._12_2_ = DAT_0058ba40;
    while (cVar1 != '=') {
      pcVar4 = (char *)__mbsninc(pcVar4,1);
      cVar1 = *pcVar4;
    }
    pcVar4 = (char *)__mbsninc(pcVar4,1);
    new_string_dll_name._0_4_ = new_string_dll_name._0_4_ & 0xffffff00;
    iVar3 = __ismbcspace(*pcVar4);
    while ((iVar3 == 0 && (*pcVar4 != '\0'))) {
      __mbsncat(new_string_dll_name,pcVar4,1);
      pcVar4 = (char *)__mbsninc(pcVar4,1);
      iVar3 = __ismbcspace(*pcVar4);
    }
  }
  StringTableX = (void *)LoadLibraryA(new_string_dll_name);
  if (StringTableX == (void *)0x0) {
    this->_padding_ = 1;
    iVar3 = 0;
    goto LAB_00521e5b;
  }
  pal_entries[4].peGreen = '{';
  pal_entries[2].peGreen = '?';
  pal_entries[3].peRed = '?';
  pal_entries[5].peRed = '?';
  pal_entries[6].peGreen = '?';
  pal_entries[1].peRed = '\x17';
  pal_entries[1].peGreen = '\'';
  pal_entries[1].peBlue = '|';
  pal_entries[1].peFlags = '\0';
  pal_entries[2].peRed = '\'';
  pal_entries[2].peBlue = 0x90;
  pal_entries[2].peFlags = '\0';
  pal_entries[3].peGreen = '_';
  pal_entries[3].peBlue = 0x9f;
  pal_entries[3].peFlags = '\0';
  pal_entries[4].peRed = 'W';
  pal_entries[4].peBlue = 0xb4;
  pal_entries[4].peFlags = '\0';
  pal_entries[5].peGreen = '_';
  pal_entries[5].peBlue = 0xa0;
  pal_entries[5].peFlags = '\0';
  pal_entries[6].peRed = '\'';
  pal_entries[6].peBlue = 0x91;
  pal_entries[6].peFlags = '\0';
  SetPaletteEntries(this->_padding_,0xf8,7,pal_entries + 1);
  iVar3 = CreateWindowExA(0,s_STATIC,s_InputDisabledWindow,0x40000000,0,0,1,1,this->_padding_,0,
                          *(undefined4 *)(this->_padding_ + 0x410),0);
  this->_padding_ = iVar3;
  video_codec_available = _ICInfo_12(0x63646976,0x31347669,&ici.fccType);
  uVar2 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)this,s_LOBBY);
  if (uVar2 == '\0') {
    iVar3 = TCommunications_Handler::LaunchLobbyGame((TCommunications_Handler *)this->_padding_);
    if (iVar3 == 1) {
      RGE_Base_Game::setMultiplayerGame((RGE_Base_Game *)this,1);
      new_string_dll_name._0_4_ = operator_new(0x890);
      uStack_4 = 3;
      if ((TribeMPSetupScreen *)new_string_dll_name._0_4_ != (TribeMPSetupScreen *)0x0) {
        TribeMPSetupScreen::TribeMPSetupScreen((TribeMPSetupScreen *)new_string_dll_name._0_4_);
      }
LAB_00521ec8:
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
    }
    else {
      if (this->startup_scenario[0] == '\0') {
        if (this->startup_game[0] == '\0') {
          if (*(int *)(this->_padding_ + 0x890) == 0) {
            start_video(this,0,s_logo1);
          }
          else {
            iVar3 = start_menu(this);
            if (iVar3 == 0) goto LAB_00521f96;
          }
          goto LAB_00521c8a;
        }
        iVar3 = load_game(this,this->startup_game);
      }
      else {
        iVar3 = start_scenario(this,this->startup_scenario);
      }
      if (iVar3 == 0) {
        iVar3 = start_menu(this);
        if (iVar3 == 0) goto LAB_00521e5b;
        this_01 = (TEasy_Panel *)TPanelSystem::panel(&panel_system,s_Main_Menu);
        if (this_01 != (TEasy_Panel *)0x0) {
                    /* language.dll match for 0x961: "An error occurred while trying to start the
                       game." */
          TEasy_Panel::popupOKDialog(this_01,0x961,(char *)0x0,0x1c2,100);
        }
      }
    }
LAB_00521c8a:
    (**(code **)(this->_padding_ + 0x140))();
    run_log(s_______________________________,0);
    run_log(s_,1);
    iVar3 = FindFirstFileA(__pgmptr,&file_data.ftCreationTime);
    if (iVar3 != -1) {
      uStack_920 = 0;
      uStack_91e = 0;
      file_time.wYear = 0;
      file_time.wMonth = 0;
      file_time.wDayOfWeek = 0;
      file_time.wDay = 0;
      file_time.wHour = 0;
      file_time.wMinute = 0;
      FileTimeToSystemTime(&file_data.ftLastAccessTime.dwHighDateTime,&uStack_920);
      sprintf(cmd_line + 0xf4,s_program__s__size__d__date__d__d_,__pgmptr,
              file_data.ftLastWriteTime.dwLowDateTime,unaff_EDI >> 0x10,unaff_EDI >> 0x10,
              unaff_EDI & 0xffff,uStack_920,uStack_91e,file_time.wYear);
      run_log(cmd_line + 0xf4,0);
      FindClose(iVar3);
    }
    iVar3 = FindFirstFileA(this->_padding_ + 0x1f8,new_string_dll_name + 0x60);
    if (iVar3 != -1) {
      file_time.wDayOfWeek = 0;
      file_time.wDay = 0;
      file_time.wHour = 0;
      file_time.wMinute = 0;
      file_time.wSecond = 0;
      file_time.wMilliseconds = 0;
      pal_entries[0].peRed = '\0';
      pal_entries[0].peGreen = '\0';
      pal_entries[0].peBlue = '\0';
      pal_entries[0].peFlags = '\0';
      FileTimeToSystemTime(&file_data.ftLastWriteTime.dwHighDateTime,&file_time.wDayOfWeek);
      sprintf(cmd_line + 0xfc,s_data__s__size__d__date__d__d__d_,this->_padding_ + 0x1f8,
              file_data.nFileSizeHigh,uStack_91e,uStack_91e,uStack_920,file_time.wDayOfWeek,
              file_time.wDay,file_time.wHour);
      run_log(cmd_line + 0xfc,0);
      FindClose(iVar3);
    }
    sprintf(str + 4,s_options__s,this->_padding_ + 0x518);
    run_log(str + 4,0);
    iVar3 = 1;
  }
  else {
    new_string_dll_name._0_4_ = operator_new(0x47c);
    uStack_4 = 0;
    if ((TRIBE_Screen_Status_Message *)new_string_dll_name._0_4_ !=
        (TRIBE_Screen_Status_Message *)0x0) {
                    /* language.dll match for 0x4bf: "Setting up multiplayer game ..." */
      TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message
                ((TRIBE_Screen_Status_Message *)new_string_dll_name._0_4_,s_Status_Screen,0x4bf,
                 s_scr1,0xc383);
    }
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Status_Screen,0);
    iVar3 = TCommunications_Handler::LaunchLobbyGame((TCommunications_Handler *)this->_padding_);
    if (iVar3 == 1) {
      RGE_Base_Game::setMultiplayerGame((RGE_Base_Game *)this,1);
      new_string_dll_name._0_4_ = operator_new(0x890);
      uStack_4 = 1;
      if ((TribeMPSetupScreen *)new_string_dll_name._0_4_ == (TribeMPSetupScreen *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = TribeMPSetupScreen::TribeMPSetupScreen
                          ((TribeMPSetupScreen *)new_string_dll_name._0_4_);
      }
      if ((iVar3 != 0) && (*(int *)(iVar3 + 0xd8) == 0)) goto LAB_00521ec8;
    }
    else {
      if (iVar3 != -1) {
        RGE_Base_Game::close((RGE_Base_Game *)this);
        iVar3 = 1;
        goto LAB_00521e5b;
      }
      new_string_dll_name._0_4_ = operator_new(0x484);
      uStack_4 = 2;
      if ((TRIBE_Screen_Main_Error *)new_string_dll_name._0_4_ == (TRIBE_Screen_Main_Error *)0x0) {
        this_00 = (TRIBE_Screen_Main_Error *)0x0;
      }
      else {
        this_00 = (TRIBE_Screen_Main_Error *)
                  TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error
                            ((TRIBE_Screen_Main_Error *)new_string_dll_name._0_4_);
      }
      uStack_4 = 0xffffffff;
      if ((this_00 != (TRIBE_Screen_Main_Error *)0x0) && (this_00->_padding_ == 0)) {
                    /* language.dll match for 0x96a: "Timed out while trying to connect to the
                       game." */
        TRIBE_Screen_Main_Error::set_text(this_00,0x96a);
        TPanelSystem::setCurrentPanel(&panel_system,s_Main_Error_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
        goto LAB_00521c8a;
      }
    }
LAB_00521f96:
    iVar3 = 0;
  }
LAB_00521e5b:
  *unaff_FS_OFFSET = local_c;
  return iVar3;
}

// --------------------------------------------------

// Function: setup_cmd_options
// Address: 00521fa0
// [HELPER] s_EXIT_: "EXIT="
// [HELPER] s_GAM_: "GAM="
// [HELPER] s_NOTERRAINSOUND: "NOTERRAINSOUND"
// [HELPER] s_QUICK1: "QUICK1"
// [HELPER] s_SCN_: "SCN="
// [HELPER] s____L_c_L___: "+!#L%c#L ^="
// [HELPER] s__gmx: ".gmx"
/* WARNING: Variable defined which should be unmapped: cmd_line */
/* public: virtual int __thiscall TRIBE_Game::setup_cmd_options(void) */

int __thiscall TRIBE_Game::setup_cmd_options(TRIBE_Game *this)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  char cmd_line [256];
  char temp_str [256];
  char encstr [512];
  
  strncpy(cmd_line + 4,this->_padding_ + 0x518,0xff);
  temp_str[3] = '\0';
  CharUpperA(cmd_line + 4);
  encrypt_codes(cmd_line,encstr,0x200);
  iVar2 = strstr(cmd_line,s_NOTERRAINSOUND);
  if (iVar2 != 0) {
    disable_terrain_sounds = 1;
  }
  pcVar3 = (char *)strstr(encstr,s____L_c_L___);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar8 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar8;
    }
    iVar2 = 0;
    cVar1 = pcVar3[1];
    while ((cVar1 != ' ' && (cVar1 != '\0'))) {
      temp_str[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
      cVar1 = pcVar3[2];
      pcVar3 = pcVar3 + 1;
    }
    temp_str[iVar2] = '\0';
    iVar2 = atol(temp_str);
    if (iVar2 < 0x1a) {
      iVar2 = 0x19;
    }
    else if (200 < iVar2) {
      iVar2 = 200;
    }
    setPopLimit(this,(uchar)iVar2);
  }
  iVar2 = strstr(cmd_line,s_QUICK1);
  if (iVar2 != 0) {
    quick_start_game_mode = 1;
  }
  pcVar3 = (char *)strstr(cmd_line,s_SCN_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar8 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar8;
    }
    iVar2 = 0;
    cVar1 = pcVar3[1];
    while ((cVar1 != ' ' && (cVar1 != '\0'))) {
      this->startup_scenario[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
      cVar1 = pcVar3[2];
      pcVar3 = pcVar3 + 1;
    }
    this->startup_scenario[iVar2] = '\0';
  }
  pcVar3 = (char *)strstr(cmd_line,s_EXIT_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar8 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar8;
    }
    iVar2 = 0;
    cVar1 = pcVar3[1];
    while ((cVar1 != ' ' && (cVar1 != '\0'))) {
      temp_str[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
      cVar1 = pcVar3[2];
      pcVar3 = pcVar3 + 1;
    }
    temp_str[iVar2] = '\0';
    uVar4 = atol(temp_str);
    this->auto_exit_time = uVar4;
  }
  pcVar3 = (char *)strstr(cmd_line,s_GAM_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar8 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar8;
    }
    iVar2 = 0;
    cVar1 = pcVar3[1];
    while ((cVar1 != ' ' && (cVar1 != '\0'))) {
      this->startup_game[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
      cVar1 = pcVar3[2];
      pcVar3 = pcVar3 + 1;
    }
    this->startup_game[iVar2] = '\0';
    iVar2 = strchr(this->startup_game,0x2e);
    if (iVar2 == 0) {
      uVar5 = 0xffffffff;
      pcVar3 = &s__gmx;
      do {
        pcVar8 = pcVar3;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar8 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar8;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar2 = -1;
      pcVar3 = this->startup_game;
      do {
        pcVar7 = pcVar3;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar7 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar7;
      } while (cVar1 != '\0');
      pcVar3 = pcVar8 + -uVar5;
      pcVar8 = pcVar7 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar8 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar8 = pcVar8 + 1;
      }
    }
  }
  iVar2 = RGE_Base_Game::setup_cmd_options((RGE_Base_Game *)this);
  return iVar2;
}

// --------------------------------------------------

// Function: setup_palette
// Address: 00522200
/* WARNING: Variable defined which should be unmapped: pal_entries */
/* protected: virtual int __thiscall TRIBE_Game::setup_palette(void) */

int __thiscall TRIBE_Game::setup_palette(TRIBE_Game *this)
{
  int iVar1;
  tagPALETTEENTRY pal_entries [7];
  
  iVar1 = RGE_Base_Game::setup_palette((RGE_Base_Game *)this);
  if (iVar1 == 0) {
    return 0;
  }
  pal_entries[1].peFlags = '\0';
  pal_entries[2].peFlags = '\0';
  pal_entries[3].peFlags = '\0';
  pal_entries[4].peFlags = '\0';
  pal_entries[5].peFlags = '\0';
  pal_entries[6].peFlags = '\0';
  pal_entries[2].peGreen = '?';
  pal_entries[3].peRed = '?';
  pal_entries[5].peRed = '?';
  pal_entries[6].peGreen = '?';
  pal_entries[1].peRed = '\x17';
  pal_entries[1].peGreen = '\'';
  pal_entries[1].peBlue = '|';
  pal_entries[2].peRed = '\'';
  pal_entries[2].peBlue = 0x90;
  pal_entries[3].peGreen = '_';
  pal_entries[3].peBlue = 0x9f;
  pal_entries[4].peRed = 'W';
  pal_entries[4].peGreen = '{';
  pal_entries[4].peBlue = 0xb4;
  pal_entries[5].peGreen = '_';
  pal_entries[5].peBlue = 0xa0;
  pal_entries[6].peRed = '\'';
  pal_entries[6].peBlue = 0x91;
                    /* language.dll match for 0x7b: "9" */
  SetPaletteEntries(this->_padding_,0xf8,7,pal_entries + 1);
  return 1;
}

// --------------------------------------------------

// Function: setup_sounds
// Address: 005222c0
// [HELPER] s_artheld_wav: "artheld.wav"
// [HELPER] s_artlost_wav: "artlost.wav"
// [HELPER] s_button1_wav: "button1.wav"
// [HELPER] s_button2_wav: "button2.wav"
// [HELPER] s_cantdo_wav: "cantdo.wav"
// [HELPER] s_chatrcvd_wav: "chatrcvd.wav"
// [HELPER] s_convdone_wav: "convdone.wav"
// [HELPER] s_convwarn_wav: "convwarn.wav"
// [HELPER] s_farmdie_wav: "farmdie.wav"
// [HELPER] s_mdone_wav: "mdone.wav"
// [HELPER] s_mkilled_wav: "mkilled.wav"
// [HELPER] s_mstart_wav: "mstart.wav"
// [HELPER] s_pdropped_wav: "pdropped.wav"
// [HELPER] s_pkilled_wav: "pkilled.wav"
// [HELPER] s_res_wav: "res.wav"
// [HELPER] s_resdone_wav: "resdone.wav"
// [HELPER] s_tribute_wav: "tribute.wav"
/* protected: virtual int __thiscall TRIBE_Game::setup_sounds(void) */

int __thiscall TRIBE_Game::setup_sounds(TRIBE_Game *this)
{
  int iVar1;
  TDigital *pTVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005616ab;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  *(undefined2 *)&this->_padding_ = 0x11;
  iVar1 = calloc(0x11,4);
  this->_padding_ = iVar1;
  if (iVar1 == 0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  iVar1 = 0;
  if (0 < (short)this->_padding_) {
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(this->_padding_ + -4 + iVar1 * 4) = 0;
    } while (iVar1 < (short)this->_padding_);
  }
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 0;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_button1_wav,0xc47c);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)this->_padding_ = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 1;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_button2_wav,0xc47d);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 4) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 2;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_chatrcvd_wav,0xc47e);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 8) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 3;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_cantdo_wav,0xc47f);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0xc) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 4;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_tribute_wav,0xc480);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x10) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 5;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_resdone_wav,0xc481);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x14) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 6;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_pkilled_wav,0xc482);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x18) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 7;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_pdropped_wav,0xc483);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x1c) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 8;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_mstart_wav,0xc484);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x20) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 9;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_mdone_wav,0xc485);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x24) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 10;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_mkilled_wav,0xc486);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x28) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 0xb;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_artheld_wav,0xc487);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x2c) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 0xc;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_artlost_wav,0xc488);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x30) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 0xd;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_convwarn_wav,0xc489);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x34) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 0xe;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_convdone_wav,0xc48a);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x38) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 0xf;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_res_wav,0xc48b);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + 0x3c) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  local_4 = 0x10;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,(TSound_Driver *)this->_padding_,s_farmdie_wav,0xc48c);
  }
  local_4 = 0xffffffff;
  iVar1 = 0;
  *(undefined4 *)(this->_padding_ + 0x40) = uVar3;
  do {
    pTVar2 = *(TDigital **)(iVar1 + this->_padding_);
    if (pTVar2 != (TDigital *)0x0) {
      TDigital::load(pTVar2,(char *)0x0,-1);
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0xc);
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: create_world
// Address: 00522770
/* protected: virtual class RGE_Game_World * __thiscall TRIBE_Game::create_world(void) */

RGE_Game_World * __thiscall TRIBE_Game::create_world(TRIBE_Game *this)
{
  TRIBE_World *this_00;
  RGE_Game_World *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005616cb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_World *)operator_new(0x124);
  local_4 = 0;
  if (this_00 != (TRIBE_World *)0x0) {
    pRVar1 = (RGE_Game_World *)TRIBE_World::TRIBE_World(this_00);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Game_World *)0x0;
}

// --------------------------------------------------

// Function: set_game_mode
// Address: 005227d0
/* public: virtual void __thiscall TRIBE_Game::set_game_mode(int,int) */

void __thiscall TRIBE_Game::set_game_mode(TRIBE_Game *this,int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = this->_padding_;
  RGE_Base_Game::set_game_mode((RGE_Base_Game *)this,param_1,param_2);
  if (this->game_screen != (TRIBE_Screen_Game *)0x0) {
    TRIBE_Screen_Game::game_mode_changed(this->game_screen,iVar1,this->_padding_);
  }
  return;
}

// --------------------------------------------------

// Function: set_player
// Address: 00522810
/* public: virtual void __thiscall TRIBE_Game::set_player(short) */

void __thiscall TRIBE_Game::set_player(TRIBE_Game *this,short param_1)
{
  short sVar1;
  
  if (this->_padding_ == 0) {
    sVar1 = 0;
  }
  else {
    sVar1 = *(short *)(this->_padding_ + 0x7c);
  }
  RGE_Base_Game::set_player((RGE_Base_Game *)this,param_1);
  if ((this->_padding_ != 0) && (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
    TRIBE_Screen_Game::player_changed
              (this->game_screen,(int)sVar1,(int)*(short *)(this->_padding_ + 0x7c));
  }
  return;
}

// --------------------------------------------------

// Function: set_save_game_name
// Address: 00522860
/* public: void __thiscall TRIBE_Game::set_save_game_name(char *) */

void __thiscall TRIBE_Game::set_save_game_name(TRIBE_Game *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 == (char *)0x0) {
    this->save_game_name[0] = '\0';
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_1;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = this->save_game_name;
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

// Function: set_load_game_name
// Address: 005228a0
/* public: void __thiscall TRIBE_Game::set_load_game_name(char *) */

void __thiscall TRIBE_Game::set_load_game_name(TRIBE_Game *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 == (char *)0x0) {
    this->load_game_name[0] = '\0';
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_1;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = this->load_game_name;
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

// Function: get_string
// Address: 005228e0
/* public: virtual char * __thiscall TRIBE_Game::get_string(long,char *,int) */

char * __thiscall TRIBE_Game::get_string(TRIBE_Game *this,long param_1,char *param_2,int param_3)
{
  int iVar1;
  char *pcVar2;
  
  iVar1 = LoadStringA(StringTableX,param_1,param_2,param_3);
  if (iVar1 == 0) {
    pcVar2 = RGE_Base_Game::get_string((RGE_Base_Game *)this,param_1,param_2,param_3);
    return pcVar2;
  }
  param_2[param_3 + -1] = '\0';
  return param_2;
}

// --------------------------------------------------

// Function: get_string2
// Address: 00522930
/* public: virtual char * __thiscall TRIBE_Game::get_string2(int,long,long,char *,int) */

char * __thiscall
TRIBE_Game::get_string2
          (TRIBE_Game *this,int param_1,long param_2,long param_3,char *param_4,int param_5)
{
  char *pcVar1;
  
  *param_4 = '\0';
  switch(param_1) {
  case 1:
    switch(param_2) {
    case 100:
    case 0x65:
    case 0x66:
                    /* language.dll match for 0x961: "An error occurred while trying to start the
                       game." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x961,param_4,param_5);
      return pcVar1;
    case 0x67:
                    /* language.dll match for 0x962: "The game could not be saved. Free some disk
                       space, and then try again." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x962,param_4,param_5);
      return pcVar1;
    case 0x68:
                    /* language.dll match for 0x963: "The scenario could not be saved. Free some
                       disk space, and then try again." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x963,param_4,param_5);
      return pcVar1;
    case 0x69:
                    /* language.dll match for 0x964: "The game could not be loaded." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x964,param_4,param_5);
      return pcVar1;
    case 0x6a:
                    /* language.dll match for 0x965: "The scenario could not be loaded." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x965,param_4,param_5);
      return pcVar1;
    default:
      pcVar1 = RGE_Base_Game::get_string2
                         ((RGE_Base_Game *)this,param_1,param_2,param_3,param_4,param_5);
      return pcVar1;
    }
  default:
    pcVar1 = RGE_Base_Game::get_string2
                       ((RGE_Base_Game *)this,param_1,param_2,param_3,param_4,param_5);
    return pcVar1;
  case 100:
    switch(param_2) {
    case 0:
    case 0xf:
    case 0x10:
    case 0x11:
                    /* language.dll match for 0x10cd: "Food" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10cd,param_4,param_5);
      return pcVar1;
    case 1:
                    /* language.dll match for 0x10ce: "Wood" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10ce,param_4,param_5);
      return pcVar1;
    case 2:
                    /* language.dll match for 0x10cf: "Stone" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10cf,param_4,param_5);
      return pcVar1;
    case 3:
                    /* language.dll match for 0x10d0: "Gold" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10d0,param_4,param_5);
      return pcVar1;
    case 9:
                    /* language.dll match for 0x10db: "Goods" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10db,param_4,param_5);
      return pcVar1;
    }
    break;
  case 0x65:
    switch(param_2) {
    case 1:
                    /* language.dll match for 0x1069: "Stone Age" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1069,param_4,param_5);
      return pcVar1;
    case 2:
                    /* language.dll match for 0x106a: "Tool Age" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x106a,param_4,param_5);
      return pcVar1;
    case 3:
                    /* language.dll match for 0x106b: "Bronze Age" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x106b,param_4,param_5);
      return pcVar1;
    case 4:
                    /* language.dll match for 0x106c: "Iron Age" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x106c,param_4,param_5);
      return pcVar1;
    }
    break;
  case 0x66:
    switch(param_2) {
    case 1:
                    /* language.dll match for 0x1005: "Work (W)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1005,param_4,param_5);
      return pcVar1;
    case 2:
                    /* language.dll match for 0x1006: "Move (M)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1006,param_4,param_5);
      return pcVar1;
    case 3:
                    /* language.dll match for 0x1007: "Build (B)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1007,param_4,param_5);
      return pcVar1;
    case 4:
                    /* language.dll match for 0x1008: "Trade" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1008,param_4,param_5);
      return pcVar1;
    case 5:
                    /* language.dll match for 0x1009: "Stop (S)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1009,param_4,param_5);
      return pcVar1;
    case 6:
                    /* language.dll match for 0x100a: "Unselect (ESC)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x100a,param_4,param_5);
      return pcVar1;
    case 7:
                    /* language.dll match for 0x100b: "Unload (L)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x100b,param_4,param_5);
      return pcVar1;
    case 8:
                    /* language.dll match for 0x100c: "Group (G)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x100c,param_4,param_5);
      return pcVar1;
    case 9:
                    /* language.dll match for 0x100d: "Ungroup (U)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x100d,param_4,param_5);
      return pcVar1;
    case 10:
                    /* language.dll match for 0x100e: "Formation" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x100e,param_4,param_5);
      return pcVar1;
    case 0xb:
                    /* language.dll match for 0x100f: "Cancel (ESC)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x100f,param_4,param_5);
      return pcVar1;
    case 0xc:
                    /* language.dll match for 0x1010: "Next (X)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1010,param_4,param_5);
      return pcVar1;
    case 0xd:
                    /* language.dll match for 0x1011: "Chat" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1011,param_4,param_5);
      return pcVar1;
    case 0xe:
                    /* language.dll match for 0x1012: "Diplomacy" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1012,param_4,param_5);
      return pcVar1;
    case 0xf:
                    /* language.dll match for 0x1013: "Menu" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1013,param_4,param_5);
      return pcVar1;
    case 0x10:
                    /* language.dll match for 0x1014: "Trade with" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1014,param_4,param_5);
      return pcVar1;
    case 0x11:
                    /* language.dll match for 0x1015: "Research" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1015,param_4,param_5);
      return pcVar1;
    case 0x12:
                    /* language.dll match for 0x1016: "Create" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1016,param_4,param_5);
      return pcVar1;
    case 0x13:
                    /* language.dll match for 0x1017: "Build" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1017,param_4,param_5);
      return pcVar1;
    case 0x14:
                    /* language.dll match for 0x1018: "Cancel construction" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1018,param_4,param_5);
      return pcVar1;
    case 0x15:
                    /* language.dll match for 0x1019: "? Help (SHIFT+F1)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1019,param_4,param_5);
      return pcVar1;
    case 0x16:
                    /* language.dll match for 0x101a: "Stand Ground (D)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x101a,param_4,param_5);
      return pcVar1;
    case 0x17:
                    /* language.dll match for 0x101b: "Attack Ground (T)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x101b,param_4,param_5);
      return pcVar1;
    case 0x19:
                    /* language.dll match for 0x1020: "Trade food for gold." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1020,param_4,param_5);
      return pcVar1;
    case 0x1a:
                    /* language.dll match for 0x1021: "Trade wood for gold." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1021,param_4,param_5);
      return pcVar1;
    case 0x1b:
                    /* language.dll match for 0x1022: "Trade stone for gold." */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1022,param_4,param_5);
      return pcVar1;
    case 0x1c:
                    /* language.dll match for 0x101c: "Heal (E)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x101c,param_4,param_5);
      return pcVar1;
    case 0x1d:
                    /* language.dll match for 0x101d: "Convert (C)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x101d,param_4,param_5);
      return pcVar1;
    case 0x1e:
                    /* language.dll match for 0x101e: "Attack (A)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x101e,param_4,param_5);
      return pcVar1;
    case 0x1f:
                    /* language.dll match for 0x101f: "Repair (R)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x101f,param_4,param_5);
      return pcVar1;
    case 0x20:
                    /* language.dll match for 0x1025: "Increment queue (,)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1025,param_4,param_5);
      return pcVar1;
    case 0x21:
                    /* language.dll match for 0x1026: "Decrement queue (.)" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x1026,param_4,param_5);
      return pcVar1;
    }
    break;
  case 0x67:
    if (param_2 < 0x66) {
      if (param_2 == 0x65) {
                    /* language.dll match for 0xbbe: "No docks to trade with." */
        pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbbe,param_4,param_5);
        return pcVar1;
      }
      if (param_2 == 1) {
        switch(param_3) {
        case 0:
                    /* language.dll match for 0xbb9: "Not enough food." */
          pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbb9,param_4,param_5);
          return pcVar1;
        case 1:
                    /* language.dll match for 0xbba: "Not enough wood." */
          pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbba,param_4,param_5);
          return pcVar1;
        case 2:
                    /* language.dll match for 0xbbb: "Not enough stone." */
          pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbbb,param_4,param_5);
          return pcVar1;
        case 3:
                    /* language.dll match for 0xbbc: "Not enough gold." */
          pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbbc,param_4,param_5);
          return pcVar1;
        case 4:
                    /* language.dll match for 0xbbd: "You need to build more houses." */
          pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbbd,param_4,param_5);
          return pcVar1;
        case 0x20:
                    /* language.dll match for 0xbe6: "You have reached your population limit." */
          pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbe6,param_4,param_5);
          return pcVar1;
        }
      }
    }
    else if (param_2 < 0x3e9) {
      if (param_2 == 1000) {
                    /* language.dll match for 0xbc2: "Not enough room to place unit." */
        pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbc2,param_4,param_5);
        return pcVar1;
      }
      switch(param_2) {
      case 0x66:
                    /* language.dll match for 0xbbf: "Not close enough to land to unload." */
        pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbbf,param_4,param_5);
        return pcVar1;
      case 0x67:
                    /* language.dll match for 0xbc0: "Not enough room to unload all." */
        pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbc0,param_4,param_5);
        return pcVar1;
      case 0x68:
                    /* language.dll match for 0xbc1: "%s paid %d gold in tribute to you." */
        pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbc1,param_4,param_5);
        return pcVar1;
      case 0x69:
                    /* language.dll match for 0xbc3: "You cannot trade with an enemy." */
        pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbc3,param_4,param_5);
        return pcVar1;
      case 0x6a:
                    /* language.dll match for 0xbca: "Can't repair ... out of resources." */
        pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0xbca,param_4,param_5);
        return pcVar1;
      }
    }
    break;
  case 0x68:
    switch(param_2) {
    case 1:
                    /* language.dll match for 0x10d4: "Passengers" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10d4,param_4,param_5);
      return pcVar1;
    case 2:
                    /* language.dll match for 0x10d1: "Health" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10d1,param_4,param_5);
      return pcVar1;
    case 3:
                    /* language.dll match for 0x10d2: "Armor" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10d2,param_4,param_5);
      return pcVar1;
    case 4:
                    /* language.dll match for 0x10d3: "Attack" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10d3,param_4,param_5);
      return pcVar1;
    case 5:
                    /* language.dll match for 0x10d5: "Researching" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10d5,param_4,param_5);
      return pcVar1;
    case 6:
                    /* language.dll match for 0x10d6: "Training" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10d6,param_4,param_5);
      return pcVar1;
    case 7:
                    /* language.dll match for 0x10d7: "Building" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10d7,param_4,param_5);
      return pcVar1;
    case 8:
                    /* language.dll match for 0x10d8: "Sight" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10d8,param_4,param_5);
      return pcVar1;
    case 9:
                    /* language.dll match for 0x10d9: "Population" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10d9,param_4,param_5);
      return pcVar1;
    case 10:
                    /* language.dll match for 0x10da: "Range" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10da,param_4,param_5);
      return pcVar1;
    case 0xb:
                    /* language.dll match for 0x10dc: "Speed" */
      pcVar1 = (char *)(**(code **)(this->_padding_ + 0x20))(0x10dc,param_4,param_5);
      return pcVar1;
    }
    break;
  case 0x69:
    switch(param_2) {
    case 1:
                    /* language.dll match for 0x27f7: "Egyptian" */
      (**(code **)(this->_padding_ + 0x20))(0x27f7,param_4,param_5);
      break;
    case 2:
                    /* language.dll match for 0x27f8: "Greek" */
      (**(code **)(this->_padding_ + 0x20))(0x27f8,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 3:
                    /* language.dll match for 0x27f9: "Babylonian" */
      (**(code **)(this->_padding_ + 0x20))(0x27f9,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 4:
                    /* language.dll match for 0x27fa: "Assyrian" */
      (**(code **)(this->_padding_ + 0x20))(0x27fa,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 5:
                    /* language.dll match for 0x27fb: "Minoan" */
      (**(code **)(this->_padding_ + 0x20))(0x27fb,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 6:
                    /* language.dll match for 0x27fc: "Hittite" */
      (**(code **)(this->_padding_ + 0x20))(0x27fc,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 7:
                    /* language.dll match for 0x27fd: "Phoenician" */
      (**(code **)(this->_padding_ + 0x20))(0x27fd,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 8:
                    /* language.dll match for 0x27fe: "Sumerian" */
      (**(code **)(this->_padding_ + 0x20))(0x27fe,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 9:
                    /* language.dll match for 0x27ff: "Persian" */
      (**(code **)(this->_padding_ + 0x20))(0x27ff,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 10:
                    /* language.dll match for 0x2800: "Shang" */
      (**(code **)(this->_padding_ + 0x20))(0x2800,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 0xb:
                    /* language.dll match for 0x2801: "Yamato" */
      (**(code **)(this->_padding_ + 0x20))(0x2801,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 0xc:
                    /* language.dll match for 0x2802: "Choson" */
      (**(code **)(this->_padding_ + 0x20))(0x2802,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 0xd:
                    /* language.dll match for 0x2806: "Roman" */
      (**(code **)(this->_padding_ + 0x20))(0x2806,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 0xe:
                    /* language.dll match for 0x2807: "Carthaginian" */
      (**(code **)(this->_padding_ + 0x20))(0x2807,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 0xf:
                    /* language.dll match for 0x2809: "Palmyran" */
      (**(code **)(this->_padding_ + 0x20))(0x2809,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    case 0x10:
                    /* language.dll match for 0x2808: "Macedonian" */
      (**(code **)(this->_padding_ + 0x20))(0x2808,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    default:
                    /* language.dll match for 0x2804: "Unknown" */
      (**(code **)(this->_padding_ + 0x20))(0x2804,param_4,param_5);
      param_4[param_5 + -1] = '\0';
      return param_4;
    }
  }
  param_4[param_5 + -1] = '\0';
  return param_4;
}

// --------------------------------------------------

// Function: get_view_panel
// Address: 00523450
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
/* public: virtual class TPanel * __thiscall TRIBE_Game::get_view_panel(void) */

TPanel * __thiscall TRIBE_Game::get_view_panel(TRIBE_Game *this)
{
  int iVar1;
  TPanel *pTVar2;
  
  iVar1 = this->_padding_;
  if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 5)) &&
     (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
    return *(TPanel **)((int)&this->game_screen->main_view + 3);
  }
  if (iVar1 == 7) {
    pTVar2 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Screen);
    if (pTVar2 != (TPanel *)0x0) {
      return pTVar2[5].previousPanelValue;
    }
  }
  return (TPanel *)0x0;
}

// --------------------------------------------------

// Function: get_map_panel
// Address: 005234a0
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
/* public: virtual class TPanel * __thiscall TRIBE_Game::get_map_panel(void) */

TPanel * __thiscall TRIBE_Game::get_map_panel(TRIBE_Game *this)
{
  int iVar1;
  TPanel *pTVar2;
  
  iVar1 = this->_padding_;
  if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 5)) &&
     (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
    return *(TPanel **)((int)&this->game_screen->map_view + 3);
  }
  if (iVar1 == 7) {
    pTVar2 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Screen);
    if (pTVar2 != (TPanel *)0x0) {
      return pTVar2[5].previousModalPanelValue;
    }
  }
  return (TPanel *)0x0;
}

// --------------------------------------------------

// Function: get_save_game_name
// Address: 005234f0
/* public: char * __thiscall TRIBE_Game::get_save_game_name(void) */

char * __thiscall TRIBE_Game::get_save_game_name(TRIBE_Game *this)
{
  return this->save_game_name;
}

// --------------------------------------------------

// Function: get_load_game_name
// Address: 00523500
/* public: char * __thiscall TRIBE_Game::get_load_game_name(void) */

char * __thiscall TRIBE_Game::get_load_game_name(TRIBE_Game *this)
{
  return this->load_game_name;
}

// --------------------------------------------------

// Function: new_scenario_header
// Address: 00523510
/* public: virtual class RGE_Scenario_Header * __thiscall TRIBE_Game::new_scenario_header(int) */

RGE_Scenario_Header * __thiscall TRIBE_Game::new_scenario_header(TRIBE_Game *this,int param_1)
{
  TRIBE_Scenario_Header *this_00;
  RGE_Scenario_Header *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005616eb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Scenario_Header *)operator_new(0x1c);
  local_4 = 0;
  if (this_00 != (TRIBE_Scenario_Header *)0x0) {
    pRVar1 = (RGE_Scenario_Header *)TRIBE_Scenario_Header::TRIBE_Scenario_Header(this_00,param_1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Scenario_Header *)0x0;
}

// --------------------------------------------------

// Function: new_scenario_header
// Address: 00523570
/* public: virtual class RGE_Scenario_Header * __thiscall TRIBE_Game::new_scenario_header(class
   RGE_Scenario *) */

RGE_Scenario_Header * __thiscall
TRIBE_Game::new_scenario_header(TRIBE_Game *this,RGE_Scenario *param_1)
{
  TRIBE_Scenario_Header *this_00;
  RGE_Scenario_Header *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056170b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Scenario_Header *)operator_new(0x1c);
  local_4 = 0;
  if (this_00 != (TRIBE_Scenario_Header *)0x0) {
    pRVar1 = (RGE_Scenario_Header *)
             TRIBE_Scenario_Header::TRIBE_Scenario_Header(this_00,(T_Scenario *)param_1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Scenario_Header *)0x0;
}

// --------------------------------------------------

// Function: new_scenario_info
// Address: 005235d0
/* public: virtual class RGE_Scenario * __thiscall TRIBE_Game::new_scenario_info(int) */

RGE_Scenario * __thiscall TRIBE_Game::new_scenario_info(TRIBE_Game *this,int param_1)
{
  T_Scenario *this_00;
  RGE_Scenario *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056172b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (T_Scenario *)operator_new(0x514c);
  local_4 = 0;
  if (this_00 != (T_Scenario *)0x0) {
    pRVar1 = (RGE_Scenario *)T_Scenario::T_Scenario(this_00,param_1,(RGE_Game_World *)0x0);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Scenario *)0x0;
}

// --------------------------------------------------

// Function: show_error_message
// Address: 00523640
/* WARNING: Variable defined which should be unmapped: title */
/* public: void __thiscall TRIBE_Game::show_error_message(int) */

void __thiscall TRIBE_Game::show_error_message(TRIBE_Game *this,int param_1)
{
  int iVar1;
  undefined4 uStack_220;
  char *pcStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined1 *puStack_210;
  undefined4 uStack_20c;
  char title [256];
  char msg [256];
  
  puStack_210 = title + 4;
  uStack_20c = 0x100;
  iVar1 = this->_padding_;
                    /* language.dll match for 0xfa8: "Error" */
  uStack_214 = 0xfa8;
  uStack_218 = 0x52365e;
  (**(code **)(iVar1 + 0x20))();
  pcStack_21c = title + 0xf8;
  uStack_218 = 0x100;
  uStack_220 = 0;
  (**(code **)(iVar1 + 0x28))(1,msg._252_4_);
  MessageBoxA(this->_padding_,title + 0xe4,&uStack_220,0x10);
  return;
}

// --------------------------------------------------

// Function: show_status_message
// Address: 005236a0
// [HELPER] s_Status_Screen: "Status Screen"
/* public: void __thiscall TRIBE_Game::show_status_message(char *,char *,long) */

void __thiscall
TRIBE_Game::show_status_message(TRIBE_Game *this,char *param_1,char *param_2,long param_3)
{
  TRIBE_Screen_Status_Message *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056174b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = (TRIBE_Screen_Status_Message *)TPanelSystem::panel(&panel_system,s_Status_Screen);
  if (pTVar1 == (TRIBE_Screen_Status_Message *)0x0) {
    pTVar1 = (TRIBE_Screen_Status_Message *)operator_new(0x47c);
    local_4 = 0;
    if (pTVar1 != (TRIBE_Screen_Status_Message *)0x0) {
      TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message
                (pTVar1,s_Status_Screen,param_1,param_2,param_3);
    }
    local_4 = 0xffffffff;
  }
  else {
    TRIBE_Screen_Status_Message::set_text(pTVar1,param_1);
    RGE_Base_Game::draw_window((RGE_Base_Game *)this);
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Status_Screen,0);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: show_status_message
// Address: 00523750
/* WARNING: Variable defined which should be unmapped: str */
/* public: void __thiscall TRIBE_Game::show_status_message(int,char *,long) */

void __thiscall
TRIBE_Game::show_status_message(TRIBE_Game *this,int param_1,char *param_2,long param_3)
{
  long unaff_retaddr;
  undefined1 *puStack_10c;
  undefined4 uStack_108;
  char str [256];
  char *pcStack_4;
  
  puStack_10c = str + 4;
  uStack_108 = 0x100;
  (**(code **)(this->_padding_ + 0x20))(param_1);
  show_status_message(this,(char *)&puStack_10c,pcStack_4,unaff_retaddr);
  return;
}

// --------------------------------------------------

// Function: close_status_message
// Address: 005237a0
/* public: void __thiscall TRIBE_Game::close_status_message(void) */

void __thiscall TRIBE_Game::close_status_message(TRIBE_Game *this)
{
  TPanelSystem::restorePreviousPanel(&panel_system,1);
  return;
}

// --------------------------------------------------

// Function: start_video
// Address: 005237b0
// [HELPER] s_CDPath: "CDPath"
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
// [HELPER] s__s_s_avi: "%s%s.avi"
// [HELPER] s__sgame_avi__s_avi: "%sgame\avi\%s.avi"
// [HELPER] s_stopped: "stopped"
/* WARNING: Variable defined which should be unmapped: video_rect */
/* public: int __thiscall TRIBE_Game::start_video(int,char *) */

int __thiscall TRIBE_Game::start_video(TRIBE_Game *this,int param_1,char *param_2)
{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  void *pvVar6;
  ulong uVar7;
  byte *pbVar8;
  bool bVar9;
  tagRECT video_rect;
  char str [100];
  char temp_name [260];
  
  if (this->video_window != (void *)0x0) {
    SendMessageA(this->video_window,0x46a,100,str + 4);
    if (str[4] != '\0') {
      pbVar8 = &s_stopped;
      pbVar3 = (byte *)(str + 4);
      do {
        bVar1 = *pbVar3;
        bVar9 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_00523811:
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_00523816;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar9 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_00523811;
        pbVar3 = pbVar3 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_00523816:
      if (iVar4 != 0) {
        SendMessageA(this->video_window,0x808,0,0);
      }
    }
    SendMessageA(this->video_window,0x10,0,0);
    this->video_window = (void *)0x0;
  }
  cVar2 = *(char *)((int)&this->_padding_ + 2);
  this->cur_video = param_1;
  if (((cVar2 != '\x01') && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {
    sprintf(temp_name + 4,s__s_s_avi,this->_padding_ + 0x1130,param_2);
    iVar4 = __open(temp_name + 4,0,0x100);
    if (iVar4 == -1) {
      pcVar5 = TRegistry::RegGetAscii((TRegistry *)this->_padding_,0,s_CDPath);
      iVar4 = -1;
      if (pcVar5 != (char *)0x0) {
        sprintf(temp_name + 4,s__sgame_avi__s_avi,pcVar5,param_2);
        iVar4 = __open(temp_name + 4,0,0x100);
      }
      if (iVar4 == -1) goto LAB_00523abd;
    }
    if ((video_codec_available != 0) &&
       ((this->video_setup != 0 || (iVar4 = setup_video_system(this), iVar4 != 0)))) {
      pvVar6 = (void *)_MCIWndCreateA(this->_padding_,*(undefined4 *)(this->_padding_ + 0x410),
                                      0x50001f0a,temp_name + 4);
      this->video_window = pvVar6;
      if (pvVar6 != (void *)0x0) {
        pvVar6 = (void *)GetWindowLongA(pvVar6,0xfffffffc);
        this->old_video_wnd_proc = pvVar6;
        SetWindowLongA(this->video_window,0xfffffffc,video_sub_wnd_proc);
        if (this->video_hi_color == 0) {
                    /* language.dll match for 0x47e: "Victory!" */
          pvVar6 = (void *)SendMessageA(this->video_window,0x47e,0,0);
          TDrawSystem::SetPalette((TDrawSystem *)this->_padding_,pvVar6);
        }
        GetClientRect(this->video_window,&video_rect.top);
        if (this->video_double_size != 0) {
          video_rect.bottom = video_rect.bottom * 2;
          str._0_4_ = str._0_4_ * 2;
        }
        MoveWindow(this->video_window,*(int *)(this->_padding_ + 0x8e0) / 2 - video_rect.bottom / 2,
                   *(int *)(this->_padding_ + 0x8e4) / 2 - (int)str._0_4_ / 2,video_rect.bottom,
                   str._0_4_,0);
        RGE_Base_Game::set_render_all((RGE_Base_Game *)this);
        InvalidateRect(this->_padding_,0,1);
        SendMessageA(this->_padding_,0xf,0,0);
        TDrawSystem::ClearPrimarySurface((TDrawSystem *)this->_padding_);
        this->video_paused = 0;
        uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x598);
        this->last_video_time = uVar7;
        SendMessageA(this->video_window,0x806,0,0);
        RGE_Base_Game::enable_input((RGE_Base_Game *)this);
        SetCursor(0);
        SetClassLongA(this->_padding_,0xfffffff4,0);
        return 1;
      }
    }
  }
LAB_00523abd:
  stop_video(this,'\x01');
  return 0;
}

// --------------------------------------------------

// Function: stop_video
// Address: 00523b10
// [HELPER] s_Achievements_Screen: "Achievements Screen"
// [HELPER] s_Mission_Dialog: "Mission Dialog"
// [HELPER] s_introx: "introx"
// [HELPER] s_logo2: "logo2"
// [HELPER] s_lost_mid: "lost.mid"
// [HELPER] s_stopped: "stopped"
// [HELPER] s_won_mid: "won.mid"
/* WARNING: Variable defined which should be unmapped: save_vid_num */
/* public: void __thiscall TRIBE_Game::stop_video(unsigned char) */

void __thiscall TRIBE_Game::stop_video(TRIBE_Game *this,uchar param_1)
{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  TRIBE_Mission_Screen *this_00;
  TribeAchievementsScreen *this_01;
  char *pcVar5;
  undefined4 *puVar6;
  RGE_Player *pRVar7;
  byte *pbVar8;
  undefined4 *unaff_FS_OFFSET;
  bool bVar9;
  int save_vid_num;
  char str [100];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561776;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  str._0_4_ = this->cur_video;
  this->cur_video = -1;
  if (this->video_window != (void *)0x0) {
    SendMessageA(this->video_window,0x46a,100,str + 4);
    if (str[4] != '\0') {
      pbVar8 = &s_stopped;
      pbVar3 = (byte *)(str + 4);
      do {
        bVar1 = *pbVar3;
        bVar9 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_00523b99:
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_00523b9e;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar9 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_00523b99;
        pbVar3 = pbVar3 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_00523b9e:
      if (iVar4 != 0) {
        SendMessageA(this->video_window,0x808,0,0);
      }
    }
    SendMessageA(this->video_window,0x10,0,0);
    this->video_window = (void *)0x0;
    TDrawSystem::ClearPrimarySurface((TDrawSystem *)this->_padding_);
    TDrawSystem::SetPalette((TDrawSystem *)this->_padding_,(void *)this->_padding_);
    RGE_Base_Game::set_render_all((RGE_Base_Game *)this);
    InvalidateRect(this->_padding_,0,1);
    SendMessageA(this->_padding_,0xf,0,0);
    TDrawSystem::ClearPrimarySurface((TDrawSystem *)this->_padding_);
  }
  switch(str._0_4_) {
  case 0:
    if (param_1 != '\0') {
      start_video(this,1,s_logo2);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 1:
    if (param_1 != '\0') {
      start_video(this,2,s_introx);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 2:
  case 5:
    break;
  case 3:
    if (this->video_setup != 0) {
      shutdown_video_system(this);
    }
    pcVar5 = RGE_Scenario::Get_description(*(RGE_Scenario **)(this->_padding_ + 0x5c));
    if ((((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) &&
        (iVar4 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)this), iVar4 == 0)) &&
       ((iVar4 = RGE_Base_Game::randomGame((RGE_Base_Game *)this), iVar4 == 0 ||
        (iVar4 = RGE_Base_Game::campaignGame((RGE_Base_Game *)this), iVar4 != 0)))) {
      this_00 = (TRIBE_Mission_Screen *)operator_new(0x49c);
      uStack_4 = 0;
      if (this_00 != (TRIBE_Mission_Screen *)0x0) {
        TRIBE_Mission_Screen::TRIBE_Mission_Screen
                  (this_00,pcVar5,'\0',*(TPicture **)(*(int *)(this->_padding_ + 0x5c) + 0x198c));
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Mission_Dialog,0);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    create_game_screen(this);
    *unaff_FS_OFFSET = uStack_c;
    return;
  case 4:
    if (this->video_setup != 0) {
      shutdown_video_system(this);
    }
    if (this->_padding_ != 0) {
      close_game_screens(this,0);
      this_01 = (TribeAchievementsScreen *)operator_new(0x5f8);
      uStack_4 = 1;
      if (this_01 == (TribeAchievementsScreen *)0x0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        iVar4 = 1;
        pcVar5 = game_over_msg(this);
        puVar6 = (undefined4 *)
                 TribeAchievementsScreen::TribeAchievementsScreen(this_01,pcVar5,iVar4);
      }
      uStack_4 = 0xffffffff;
      if (puVar6 != (undefined4 *)0x0) {
        if (puVar6[0x36] == 0) {
          TPanelSystem::setCurrentPanel(&panel_system,s_Achievements_Screen,0);
          if (this->_padding_ != 0) {
            cVar2 = *(char *)(this->_padding_ + 0x104);
            if (cVar2 == '\x01') {
              pRVar7 = RGE_Base_Game::get_player((RGE_Base_Game *)this);
              if (pRVar7->game_status != '\x01') {
                TMusic_System::play_track((TMusic_System *)this->_padding_,4,0,0);
                *unaff_FS_OFFSET = uStack_c;
                return;
              }
              TMusic_System::play_track((TMusic_System *)this->_padding_,3,0,0);
              *unaff_FS_OFFSET = uStack_c;
              return;
            }
            if (cVar2 == '\x02') {
              pRVar7 = RGE_Base_Game::get_player((RGE_Base_Game *)this);
              if (pRVar7->game_status != '\x01') {
                TMusic_System::play_file((TMusic_System *)this->_padding_,s_lost_mid,0,0);
                *unaff_FS_OFFSET = uStack_c;
                return;
              }
              TMusic_System::play_file((TMusic_System *)this->_padding_,s_won_mid,0,0);
              *unaff_FS_OFFSET = uStack_c;
              return;
            }
          }
          goto switchD_00523c17_default;
        }
        if (puVar6 != (undefined4 *)0x0) {
          (**(code **)*puVar6)(1);
        }
      }
      quit_game(this);
    }
  default:
    goto switchD_00523c17_default;
  }
  iVar4 = start_menu(this);
  if (iVar4 == 0) {
    RGE_Base_Game::close((RGE_Base_Game *)this);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
switchD_00523c17_default:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: start_campaign_menu
// Address: 00523f10
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_open_mid: "open.mid"
// [HELPER] s_open_wav: "open.wav"
/* public: int __thiscall TRIBE_Game::start_campaign_menu(void) */

int __thiscall TRIBE_Game::start_campaign_menu(TRIBE_Game *this)
{
  uchar uVar1;
  TMusic_System *this_00;
  TRIBE_Screen_Campaign_Selection *this_01;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056178b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (this->video_setup != 0) {
    shutdown_video_system(this);
  }
  this_01 = (TRIBE_Screen_Campaign_Selection *)operator_new(0x4cc);
  local_4 = 0;
  if (this_01 == (TRIBE_Screen_Campaign_Selection *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection(this_01)
    ;
  }
  local_4 = 0xffffffff;
  if (puVar2 == (undefined4 *)0x0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  if (puVar2[0x36] != 0) {
    (**(code **)*puVar2)(1);
    *unaff_FS_OFFSET = this_01;
    return 0;
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Campaign_Selection_Screen,0);
  (**(code **)(this->_padding_ + 0xc))(2);
  this_00 = (TMusic_System *)this->_padding_;
  if ((this_00 == (TMusic_System *)0x0) || (this->started_menu_music != 0)) goto LAB_0052400d;
  uVar1 = this_00->music_type;
  if (uVar1 == '\x01') {
    TMusic_System::play_track(this_00,2,0,0);
  }
  else {
    if (uVar1 == '\x02') {
      pcVar3 = s_open_mid;
    }
    else {
      if (uVar1 != '\x03') goto LAB_00524003;
      pcVar3 = s_open_wav;
    }
    TMusic_System::play_file(this_00,pcVar3,0,0);
  }
LAB_00524003:
  this->started_menu_music = 1;
LAB_0052400d:
  *unaff_FS_OFFSET = this_01;
  return 1;
}

// --------------------------------------------------

// Function: start_menu
// Address: 00524030
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_open_mid: "open.mid"
// [HELPER] s_open_wav: "open.wav"
/* public: int __thiscall TRIBE_Game::start_menu(void) */

int __thiscall TRIBE_Game::start_menu(TRIBE_Game *this)
{
  uchar uVar1;
  TMusic_System *this_00;
  TRIBE_Screen_Main_Menu *this_01;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005617ab;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (this->video_setup != 0) {
    shutdown_video_system(this);
  }
                    /* language.dll match for 0x4b0: "Ready" */
  this_01 = (TRIBE_Screen_Main_Menu *)operator_new(0x4b0);
  local_4 = 0;
  if (this_01 == (TRIBE_Screen_Main_Menu *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(this_01);
  }
  local_4 = 0xffffffff;
  if (puVar2 == (undefined4 *)0x0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  if (puVar2[0x36] != 0) {
    (**(code **)*puVar2)(1);
    *unaff_FS_OFFSET = this_01;
    return 0;
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
  (**(code **)(this->_padding_ + 0xc))(2);
  this_00 = (TMusic_System *)this->_padding_;
  if ((this_00 == (TMusic_System *)0x0) || (this->started_menu_music != 0)) goto LAB_0052412d;
  uVar1 = this_00->music_type;
  if (uVar1 == '\x01') {
    TMusic_System::play_track(this_00,2,0,0);
  }
  else {
    if (uVar1 == '\x02') {
      pcVar3 = s_open_mid;
    }
    else {
      if (uVar1 != '\x03') goto LAB_00524123;
      pcVar3 = s_open_wav;
    }
    TMusic_System::play_file(this_00,pcVar3,0,0);
  }
LAB_00524123:
  this->started_menu_music = 1;
LAB_0052412d:
  *unaff_FS_OFFSET = this_01;
  return 1;
}

// --------------------------------------------------

// Function: quit_game
// Address: 00524150
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s__s_s_scn: "%s%s.scn"
// [HELPER] s__s_scn: "%s.scn"
// [HELPER] s__s_scx: "%s.scx"
/* WARNING: Variable defined which should be unmapped: campaign */
/* public: void __thiscall TRIBE_Game::quit_game(void) */

void __thiscall TRIBE_Game::quit_game(TRIBE_Game *this)
{
  char *pcVar1;
  bool bVar2;
  uchar uVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar5;
  uchar campaign;
  char temp_test_scenario [260];
  _finddata_t file_info;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005617ce;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  bVar2 = false;
  iVar4 = TCommunications_Handler::IsLobbyLaunched((TCommunications_Handler *)this->_padding_);
  if ((iVar4 != 0) && ((TRIBE_World *)this->_padding_ != (TRIBE_World *)0x0)) {
    TRIBE_World::send_zone_score_info((TRIBE_World *)this->_padding_);
  }
  disconnect_multiplayer_game(this);
  this->_padding_ = 0;
  if (do_debug_random != 0) {
    debug_random_write();
    dump_vismap_log();
  }
  iVar4 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)this);
  if (((iVar4 == 1) && (iVar4 = this->_padding_, iVar4 != 0)) && (-1 < *(int *)(iVar4 + 0xa4))) {
    uVar3 = RGE_Game_Info::set_current_person
                      ((RGE_Game_Info *)this->_padding_,*(long *)(iVar4 + 0xa8));
    if (uVar3 != '\0') {
      uVar3 = RGE_Game_Info::set_current_campaign
                        ((RGE_Game_Info *)this->_padding_,*(long *)(this->_padding_ + 0xa4));
      if (uVar3 != '\0') {
        bVar2 = true;
      }
    }
  }
  if ((int *)this->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)this->_padding_ + 0xb8))();
  }
  iVar4 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)this);
  if (iVar4 == 1) {
    if (bVar2) {
      iVar4 = start_campaign_menu(this);
      if (iVar4 == 0) {
        RGE_Base_Game::close((RGE_Base_Game *)this);
      }
    }
    else {
      pcVar1 = this->testing_scenario;
      if (this->testing_scenario[0] != '\0') {
        close_game_screens(this,0);
        this->game_screen = (TRIBE_Screen_Game *)0x0;
        TPanelSystem::destroyPanel(&panel_system,s_Game_Screen);
        sprintf(temp_test_scenario + 4,s__s_s_scn,this->_padding_ + 0xc17,pcVar1);
        iVar4 = __findfirst(temp_test_scenario + 4,&file_info.time_create);
        if (iVar4 == -1) {
          pcVar5 = s__s_scx;
        }
        else {
          pcVar5 = s__s_scn;
        }
        sprintf(temp_test_scenario + 4,pcVar5,pcVar1);
        *pcVar1 = '\0';
        iVar4 = start_scenario_editor(this,temp_test_scenario + 4,0);
        if (iVar4 != 0) {
          *pcVar1 = '\0';
          goto LAB_0052437e;
        }
      }
      iVar4 = start_menu(this);
      if (iVar4 == 0) {
        RGE_Base_Game::close((RGE_Base_Game *)this);
      }
    }
  }
  else {
    iVar4 = TCommunications_Handler::IsLobbyLaunched((TCommunications_Handler *)this->_padding_);
    if (iVar4 != 0) {
      RGE_Base_Game::close((RGE_Base_Game *)this);
      goto LAB_0052437e;
    }
                    /* language.dll match for 0x4b0: "Ready" */
    temp_test_scenario._0_4_ = operator_new(0x4b0);
    uStack_4 = 0;
    if ((TribeJoinScreen *)temp_test_scenario._0_4_ != (TribeJoinScreen *)0x0) {
      TribeJoinScreen::TribeJoinScreen((TribeJoinScreen *)temp_test_scenario._0_4_);
    }
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Join_Screen,0);
    (**(code **)(this->_padding_ + 0xc))(2);
  }
  close_game_screens(this,0);
  this->game_screen = (TRIBE_Screen_Game *)0x0;
  TPanelSystem::destroyPanel(&panel_system,s_Game_Screen);
  this->testing_scenario[0] = '\0';
LAB_0052437e:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: restart_game
// Address: 005243a0
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s__s_gam: "%s.gam"
// [HELPER] s__s_gmx: "%s.gmx"
// [HELPER] s__s_s_gmx: "%s%s.gmx"
/* WARNING: Variable defined which should be unmapped: temp_name */
/* public: void __thiscall TRIBE_Game::restart_game(void) */

void __thiscall TRIBE_Game::restart_game(TRIBE_Game *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  TEasy_Panel *this_00;
  int *piVar4;
  uint uVar5;
  char *pcVar6;
  char temp_name [260];
  _finddata_t fileInfo;
  
                    /* language.dll match for 0x451: "Starting a new game..." */
  show_status_message(this,0x451,(char *)0x0,-1);
  close_game_screens(this,0);
  this->game_screen = (TRIBE_Screen_Game *)0x0;
  TPanelSystem::destroyPanel(&panel_system,s_Game_Screen);
  this->_padding_ = 0;
  (**(code **)(*(int *)this->_padding_ + 0xb8))();
  uVar5 = 1;
  piVar4 = this->save_humanity;
  do {
    piVar4 = piVar4 + 1;
    TCommunications_Handler::SetPlayerHumanity
              ((TCommunications_Handler *)this->_padding_,uVar5,*piVar4);
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 9);
  iVar1 = RGE_Base_Game::savedGame((RGE_Base_Game *)this);
  if (iVar1 == 0) {
    iVar1 = 0;
    iVar2 = RGE_Base_Game::randomGame((RGE_Base_Game *)this);
    if (iVar2 == 1) {
      iVar2 = RGE_Base_Game::campaignGame((RGE_Base_Game *)this);
      if (iVar2 == 0) {
        iVar1 = this->_padding_;
        this->_padding_ = this->_padding_;
      }
    }
    iVar2 = start_game(this,1);
    iVar3 = RGE_Base_Game::randomGame((RGE_Base_Game *)this);
    if (iVar3 != 0) {
      iVar3 = RGE_Base_Game::campaignGame((RGE_Base_Game *)this);
      if (iVar3 == 0) {
        this->_padding_ = iVar1;
      }
    }
  }
  else {
    sprintf(temp_name + 4,s__s_s_gmx,this->_padding_ + 0xb12,this->load_game_name);
    iVar1 = __findfirst(temp_name + 4,&fileInfo.time_create);
    if (iVar1 == -1) {
      pcVar6 = s__s_gam;
    }
    else {
      pcVar6 = s__s_gmx;
    }
    sprintf(temp_name + 4,pcVar6,this->load_game_name);
    iVar2 = load_game(this,temp_name + 4);
  }
  if (iVar2 == 0) {
    iVar1 = start_menu(this);
    if (iVar1 == 0) {
      RGE_Base_Game::close((RGE_Base_Game *)this);
      return;
    }
    this_00 = (TEasy_Panel *)TPanelSystem::panel(&panel_system,s_Main_Menu);
    if (this_00 != (TEasy_Panel *)0x0) {
                    /* language.dll match for 0x961: "An error occurred while trying to start the
                       game." */
      TEasy_Panel::popupOKDialog(this_00,0x961,(char *)0x0,0x1c2,100);
    }
  }
  return;
}

// --------------------------------------------------

// Function: load_db_files
// Address: 00524530
/* public: int __thiscall TRIBE_Game::load_db_files(void) */

int __thiscall TRIBE_Game::load_db_files(TRIBE_Game *this)
{
  char cVar1;
  int *piVar2;
  uint uVar3;
  
  RGE_Base_Game::disable_input((RGE_Base_Game *)this);
                    /* language.dll match for 0x44d: "Loading game data..." */
  show_status_message(this,0x44d,(char *)0x0,-1);
  uVar3 = 0;
  if ((int *)this->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)this->_padding_ + 0xa0))(1);
    this->_padding_ = 0;
  }
  piVar2 = (int *)(**(code **)(this->_padding_ + 0xb4))();
  this->_padding_ = (int)piVar2;
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0xac))(this->_padding_ + 0x1f8,this->_padding_ + 0xf3);
    uVar3 = (uint)(cVar1 != '\0');
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 0xa0))(1);
    }
    this->_padding_ = 0;
  }
  close_status_message(this);
  RGE_Base_Game::enable_input((RGE_Base_Game *)this);
  return uVar3;
}

// --------------------------------------------------

// Function: load_game_data
// Address: 005245d0
/* public: int __thiscall TRIBE_Game::load_game_data(void) */

int __thiscall TRIBE_Game::load_game_data(TRIBE_Game *this)
{
  char cVar1;
  int *piVar2;
  
  if (this->_padding_ == 0) {
    piVar2 = (int *)(**(code **)(this->_padding_ + 0xb4))();
    this->_padding_ = (int)piVar2;
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    cVar1 = (**(code **)(*piVar2 + 0xb0))(this->_padding_ + 0x1f8,this->_padding_,this->_padding_);
    if (cVar1 == '\0') {
      if ((int *)this->_padding_ != (int *)0x0) {
        (**(code **)(*(int *)this->_padding_ + 0xa0))(1);
      }
      this->_padding_ = 0;
      return 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: save_game
// Address: 00524640
// [HELPER] s_DEBUGSAVEGAME: "DEBUGSAVEGAME"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Status_Screen: "Status Screen"
/* WARNING: Variable defined which should be unmapped: retval */
/* public: int __thiscall TRIBE_Game::save_game(char *) */

int __thiscall TRIBE_Game::save_game(TRIBE_Game *this,char *param_1)
{
  uchar uVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  int retval;
  char fileNameNoExt [260];
  
  iVar4 = this->_padding_;
  if ((((iVar4 != 4) && (iVar4 != 6)) && (iVar4 != 7)) && (iVar4 != 5)) {
    return 0;
  }
  RGE_Base_Game::disable_input((RGE_Base_Game *)this);
                    /* language.dll match for 0x453: "Saving game..." */
  show_status_message(this,0x453,(char *)0x0,-1);
  uVar1 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)this,s_DEBUGSAVEGAME);
  if (uVar1 != '\0') {
    ENABLE_COMPRESSION = 0;
  }
  cVar2 = (**(code **)(*(int *)this->_padding_ + 0xd8))(param_1);
  ENABLE_COMPRESSION = 1;
  if (cVar2 == '\0') {
    close_status_message(this);
    RGE_Base_Game::enable_input((RGE_Base_Game *)this);
    return 0;
  }
  uVar5 = 0xffffffff;
  do {
    pcVar7 = param_1;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = param_1 + 1;
    cVar2 = *param_1;
    param_1 = pcVar7;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar7 + -uVar5;
  pcVar8 = fileNameNoExt;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  puVar3 = (undefined1 *)strchr(fileNameNoExt,0x2e);
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 0;
  }
  set_save_game_name(this,fileNameNoExt);
  iVar4 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)this);
  if (iVar4 == 1) {
    RGE_Base_Game::set_paused((RGE_Base_Game *)this,0,0);
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  RGE_Base_Game::enable_input((RGE_Base_Game *)this);
  return 1;
}

// --------------------------------------------------

// Function: save_scenario
// Address: 00524790
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Status_Screen: "Status Screen"
/* public: int __thiscall TRIBE_Game::save_scenario(char *) */

int __thiscall TRIBE_Game::save_scenario(TRIBE_Game *this,char *param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = this->_padding_;
  if ((((iVar2 != 4) && (iVar2 != 6)) && (iVar2 != 7)) && (iVar2 != 5)) {
    return 0;
  }
  RGE_Base_Game::disable_input((RGE_Base_Game *)this);
                    /* language.dll match for 0x450: "Saving scenario..." */
  show_status_message(this,0x450,(char *)0x0,-1);
  iVar2 = this->_padding_;
  iVar3 = 1;
  if (1 < *(short *)(iVar2 + 0x3c)) {
    do {
      RGE_Scenario::Set_player_Active(*(RGE_Scenario **)(iVar2 + 0x5c),iVar3 + -1,1);
      iVar2 = this->_padding_;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(short *)(iVar2 + 0x3c));
  }
  cVar1 = (**(code **)(*(int *)this->_padding_ + 0xe4))(param_1);
  if (cVar1 == '\0') {
    RGE_Base_Game::enable_input((RGE_Base_Game *)this);
    return 0;
  }
  iVar2 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)this);
  if (iVar2 == 1) {
    RGE_Base_Game::set_paused((RGE_Base_Game *)this,0,0);
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  RGE_Base_Game::enable_input((RGE_Base_Game *)this);
  return 1;
}

// --------------------------------------------------

// Function: calc_timing_text
// Address: 00524880
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
// [HELPER] s_avg_view_time____: "avg view time=???"
// [HELPER] s_avg_view_time__lu__count__lu: "avg view time=%lu, count=%lu"
// [HELPER] s_f_: "f?"
// [HELPER] s_t_lu_f_lu_avg_r_v_lu_m_lu_o_lu__: "t%lu,f%lu,avg(r(v%lu,m%lu,o%lu),s%lu,u%lu,c%lu,l%lu,p%lu,o%lu)"
// [HELPER] s_t_lu_f_lu_max_r_v_lu_m_lu_o_lu__: "t%lu,f%lu,max(r(v%lu,m%lu,o%lu),s%lu,u%lu,c%lu,ls%lu,lg%lu,p%lu,o%lu)"
/* public: virtual void __thiscall TRIBE_Game::calc_timing_text(void) */

void __thiscall TRIBE_Game::calc_timing_text(TRIBE_Game *this)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  char *pcVar6;
  int *piVar7;
  
  if ((DAT_0086bcd0 & 1) == 0) {
    DAT_0086bcd0 = DAT_0086bcd0 | 1;
                    /* language.dll match for 0x7d4: "Could not initialize sound system." */
    DAT_0086bcd8._0_4_ = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x7d4);
  }
                    /* language.dll match for 0x7d6: "Could not create game." */
  DAT_0086bcd8._0_4_ = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x7d6);
  uVar2 = this->_padding_;
  if (uVar2 == 0) {
    uVar2 = 0xffffffff;
    pcVar4 = &s_f_;
    do {
      pcVar6 = pcVar4;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar6 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar6;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar4 = pcVar6 + -uVar2;
    pcVar6 = this->timing_text2;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  else if (show_timing_max == 0) {
    sprintf(this->timing_text2,s_t_lu_f_lu_avg_r_v_lu_m_lu_o_lu__,this->_padding_,this->_padding_,
            (uint)this->_padding_ / uVar2,(uint)this->_padding_ / uVar2,
            (uint)this->_padding_ / uVar2,(uint)this->_padding_ / uVar2,
            (uint)this->_padding_ / uVar2,(uint)this->_padding_ / uVar2,
            (uint)(this->_padding_ + this->_padding_) / uVar2,(uint)this->_padding_ / uVar2,
            (uint)this->_padding_ / uVar2);
  }
  else {
    sprintf(this->timing_text2,s_t_lu_f_lu_max_r_v_lu_m_lu_o_lu__,this->_padding_,this->_padding_,
            this->_padding_,this->_padding_,this->_padding_,this->_padding_,this->_padding_,
            this->_padding_,this->_padding_,this->_padding_,this->_padding_,this->_padding_);
  }
  uVar2 = this->_padding_;
  if (uVar2 != 0) {
    sprintf(&this->_padding_,s_avg_view_time__lu__count__lu,(uint)this->_padding_ / uVar2,uVar2);
    return;
  }
  uVar2 = 0xffffffff;
  pcVar4 = &s_avg_view_time____;
  do {
    pcVar6 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar6 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar6;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  piVar5 = (int *)(pcVar6 + -uVar2);
  piVar7 = &this->_padding_;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *piVar7 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar7 = piVar7 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(char *)piVar7 = (char)*piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
    piVar7 = (int *)((int)piVar7 + 1);
  }
  return;
}

// --------------------------------------------------

// Function: show_timings
// Address: 00524a60
/* public: virtual void __thiscall TRIBE_Game::show_timings(void) */

void __thiscall TRIBE_Game::show_timings(TRIBE_Game *this)
{
  if (this->game_screen != (TRIBE_Screen_Game *)0x0) {
    TRIBE_Screen_Game::show_timings(this->game_screen,(char *)&this->_padding_,this->timing_text2);
  }
  return;
}

// --------------------------------------------------

// Function: show_comm
// Address: 00524a80
/* public: virtual void __thiscall TRIBE_Game::show_comm(void) */

void __thiscall TRIBE_Game::show_comm(TRIBE_Game *this)
{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (this->game_screen != (TRIBE_Screen_Game *)0x0) {
    pcVar1 = TCommunications_Handler::GetCommInfo((TCommunications_Handler *)this->_padding_,'\x06')
    ;
    pcVar2 = TCommunications_Handler::GetCommInfo((TCommunications_Handler *)this->_padding_,'\x05')
    ;
    pcVar3 = TCommunications_Handler::GetCommInfo((TCommunications_Handler *)this->_padding_,'\x04')
    ;
    pcVar4 = TCommunications_Handler::GetCommInfo((TCommunications_Handler *)this->_padding_,'\x03')
    ;
    pcVar5 = TCommunications_Handler::GetCommInfo((TCommunications_Handler *)this->_padding_,'\x02')
    ;
    pcVar6 = TCommunications_Handler::GetCommInfo((TCommunications_Handler *)this->_padding_,'\x01')
    ;
    TRIBE_Screen_Game::show_comm(this->game_screen,pcVar6,pcVar5,pcVar4,pcVar3,pcVar2,pcVar1);
  }
  return;
}

// --------------------------------------------------

// Function: show_ai
// Address: 00524af0
// [HELPER] s_: ""
// [HELPER] s_Player___d__AI_is_not_functional: "Player #%d: AI is not functional."
// [HELPER] s_Player___d___s: "Player #%d: %s"
// [HELPER] s_Player___d_is_not_a_computer_pla: "Player #%d is not a computer player."
/* public: virtual void __thiscall TRIBE_Game::show_ai(void) */

void __thiscall TRIBE_Game::show_ai(TRIBE_Game *this)
{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  char (*pacVar8) [256];
  TRIBE_Game *unaff_EBX;
  char (*pacVar9) [256];
  char *pcVar10;
  char (*pacVar11) [256];
  char (*pacVar12) [256];
  char (*pacVar13) [256];
  char (*pacVar14) [256];
  char str [6] [256];
  
  iVar3 = *(int *)(this->_padding_ + 0x40);
  if (iVar3 != 0) {
    str[0]._0_4_ = this;
    iVar2 = RGE_Player::computerPlayer
                      (*(RGE_Player **)(iVar3 + *(short *)(this->_padding_ + 0x7c) * 4));
    iVar3 = **(int **)(*(int *)(this->_padding_ + 0x40) + *(short *)(this->_padding_ + 0x7c) * 4);
    if (iVar2 == 1) {
      iVar3 = (**(code **)(iVar3 + 0x14))(1);
      if (iVar3 == 0) {
        sprintf(str,s_Player___d__AI_is_not_functional,(int)*(short *)(this->_padding_ + 0x7c));
      }
      else {
        sprintf(str,s_Player___d___s,(int)*(short *)(this->_padding_ + 0x7c),iVar3);
      }
      iVar3 = 2;
      pacVar9 = str + 2;
      do {
        pcVar4 = (char *)(**(code **)(**(int **)(*(int *)(unaff_EBX->_padding_ + 0x40) +
                                                *(short *)(unaff_EBX->_padding_ + 0x7c) * 4) + 0x14)
                         )(iVar3);
        pcVar5 = pacVar9[-1];
        pcVar10 = s_;
        if (pcVar4 != (char *)0x0) {
          pcVar10 = pcVar4;
        }
        uVar6 = 0xffffffff;
        do {
          pcVar4 = pcVar10;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar4 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar4;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        pacVar9 = pacVar9 + 1;
        pcVar10 = pcVar4 + -uVar6;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar5 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar5 = pcVar5 + 4;
        }
        iVar3 = iVar3 + 1;
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar5 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar5 = pcVar5 + 1;
        }
      } while (iVar3 < 7);
    }
    else {
      pcVar5 = (char *)(**(code **)(iVar3 + 0x14))(0);
      uVar6 = 0xffffffff;
      do {
        pcVar10 = pcVar5;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar10 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar10;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      uVar7 = uVar6 >> 2;
      pcVar5 = pcVar10 + -uVar6;
      pcVar10 = str[0];
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar10 = pcVar10 + 1;
      }
      sprintf(str + 1,s_Player___d_is_not_a_computer_pla,(int)*(short *)(this->_padding_ + 0x7c));
      uVar6 = 0xffffffff;
      pcVar5 = s_;
      do {
        pcVar10 = pcVar5;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar10 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar10;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      uVar7 = uVar6 >> 2;
      pcVar5 = pcVar10 + -uVar6;
      pcVar10 = str[2];
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar10 = pcVar10 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar5 = s_;
      do {
        pcVar10 = pcVar5;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar10 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar10;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      uVar7 = uVar6 >> 2;
      pcVar5 = pcVar10 + -uVar6;
      pcVar10 = str[3];
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar10 = pcVar10 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar5 = s_;
      do {
        pcVar10 = pcVar5;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar10 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar10;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      uVar7 = uVar6 >> 2;
      pcVar5 = pcVar10 + -uVar6;
      pcVar10 = str[4];
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar10 = pcVar10 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar5 = s_;
      do {
        pcVar10 = pcVar5;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar10 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar10;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      uVar7 = uVar6 >> 2;
      pcVar5 = pcVar10 + -uVar6;
      pcVar10 = str[5];
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = uVar6 & 3; unaff_EBX = this, uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    if (unaff_EBX->game_screen != (TRIBE_Screen_Game *)0x0) {
      iVar3 = RGE_Player::computerPlayer
                        (*(RGE_Player **)
                          (*(int *)(unaff_EBX->_padding_ + 0x40) +
                          *(short *)(unaff_EBX->_padding_ + 0x7c) * 4));
      if (iVar3 == 1) {
        pacVar9 = str;
        pacVar14 = str + 1;
        pacVar13 = str + 2;
        pacVar12 = str + 3;
        pacVar11 = str + 4;
        pacVar8 = str + 5;
      }
      else {
        pacVar9 = str + 5;
        pacVar14 = str + 4;
        pacVar13 = str + 3;
        pacVar12 = str + 2;
        pacVar11 = str + 1;
        pacVar8 = str;
      }
      TRIBE_Screen_Game::show_ai
                (unaff_EBX->game_screen,*pacVar8,*pacVar11,*pacVar12,*pacVar13,*pacVar14,*pacVar9);
    }
  }
  return;
}

// --------------------------------------------------

// Function: notification
// Address: 00524d70
/* WARNING: Variable defined which should be unmapped: msg */
/* public: virtual void __thiscall TRIBE_Game::notification(int,long,long,long,long) */

void __thiscall
TRIBE_Game::notification
          (TRIBE_Game *this,int param_1,long param_2,long param_3,long param_4,long param_5)
{
  RGE_Player *pRVar1;
  RGE_Player *pRVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  long unaff_retaddr;
  undefined4 uVar6;
  char *pcVar7;
  char msg [256];
  char temp_str [256];
  int iStack_4;
  
  switch(param_1) {
  case 1:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,3);
      iVar4 = this->_padding_;
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
      uVar6 = 0x66;
LAB_005250a4:
                    /* language.dll match for 0x67: "Comic Sans MS" */
      (**(code **)(iVar4 + 0x28))(0x67,uVar6,0);
      TRIBE_Screen_Game::show_message(this->game_screen,BadMessage,&stack0xfffffdec,'U','\0');
      return;
    }
    break;
  case 2:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,3);
      iVar4 = this->_padding_;
      uVar6 = 0x67;
      goto LAB_005250a4;
    }
    break;
  case 3:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,3);
      iVar4 = this->_padding_;
      uVar6 = 0x69;
      goto LAB_005250a4;
    }
    break;
  case 4:
    iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)this,param_2);
    if (((iVar4 != *(short *)(this->_padding_ + 0x7c)) &&
        (this->game_screen != (TRIBE_Screen_Game *)0x0)) &&
       ((&player_dropped)[param_2] == (int *)0x0)) {
      (&player_dropped)[param_2] = (int *)0x1;
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,7);
      iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)this,param_2);
      if (0 < iVar4) {
                    /* language.dll match for 0xbc4: "%s disconnected." */
        (**(code **)(this->_padding_ + 0x20))(0xbc4);
        iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)this,param_2);
        sprintf(&stack0xfffffdf4,msg + 0xf8,
                *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + 0x40) + iVar4 * 4) + 0x44));
        TRIBE_Screen_Game::display_system_message(this->game_screen,&stack0xfffffdf4);
        return;
      }
    }
    break;
  case 5:
    if (((param_2 != *(short *)(this->_padding_ + 0x7c)) &&
        (this->game_screen != (TRIBE_Screen_Game *)0x0)) && (0 < param_2)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,6);
      iVar4 = this->_padding_;
      if (param_3 == 0) {
                    /* language.dll match for 0xbc5: "%s resigned." */
        (**(code **)(iVar4 + 0x20))(0xbc5);
        sprintf(&stack0xfffffdf4,msg + 0xf8,
                *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + 0x40) + param_2 * 4) + 0x44));
        TRIBE_Screen_Game::display_system_message(this->game_screen,&stack0xfffffdf4);
        return;
      }
      uVar6 = 0xbc4;
LAB_00525284:
      (**(code **)(iVar4 + 0x20))(uVar6);
      sprintf(&stack0xfffffdf4,msg + 0xf8,
              *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + 0x40) + param_2 * 4) + 0x44));
      TRIBE_Screen_Game::display_system_message(this->game_screen,&stack0xfffffdf4);
      return;
    }
    break;
  case 6:
    if (((param_2 != *(short *)(this->_padding_ + 0x7c)) &&
        (this->game_screen != (TRIBE_Screen_Game *)0x0)) &&
       (RGE_Base_Game::play_sound((RGE_Base_Game *)this,6), 0 < param_2)) {
      iVar4 = this->_padding_;
                    /* language.dll match for 0xbc6: "%s defeated." */
      uVar6 = 0xbc6;
      goto LAB_00525284;
    }
    break;
  case 7:
    if ((param_3 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,4);
      if (param_4 == 0) {
        iVar4 = this->_padding_;
                    /* language.dll match for 0xbc8: "%s paid %d food in tribute to you." */
        uVar6 = 0xbc8;
      }
      else if (param_4 == 1) {
        iVar4 = this->_padding_;
        uVar6 = 0xbc7;
      }
      else {
        iVar4 = this->_padding_;
        if (param_4 == 3) {
          uVar6 = 0xbc1;
        }
        else {
          uVar6 = 0xbc9;
        }
      }
      (**(code **)(iVar4 + 0x20))(uVar6);
      sprintf(&stack0xfffffdf4,msg + 0xf8,
              *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + 0x40) + iStack_4 * 4) + 0x44),
              param_2);
      TRIBE_Screen_Game::display_system_message(this->game_screen,&stack0xfffffdf4);
      return;
    }
    break;
  case 8:
    if (this->game_screen != (TRIBE_Screen_Game *)0x0) {
      TRIBE_Screen_Game::reset_clocks(this->game_screen);
    }
    if (param_3 != *(short *)(this->_padding_ + 0x7c)) {
      return;
    }
    if (this->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    if (param_4 == 0) {
      iVar4 = this->_padding_;
                    /* language.dll match for 0xbd2: "%s changed diplomatic stance with you to
                       Ally." */
      uVar6 = 0xbd2;
    }
    else {
      if (param_4 != 1) {
        if (param_4 == 3) {
                    /* language.dll match for 0xbd3: "%s changed diplomatic stance with you to
                       Enemy." */
          (**(code **)(this->_padding_ + 0x20))(0xbd3);
        }
        goto LAB_0052543e;
      }
      iVar4 = this->_padding_;
      uVar6 = 0xbd1;
    }
    (**(code **)(iVar4 + 0x20))(uVar6);
LAB_0052543e:
    sprintf(msg + 4);
    TRIBE_Screen_Game::display_system_message(this->game_screen,msg + 4);
    return;
  case 100:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      if ((param_3 == 0x65) || ((param_3 == 0x66 || (param_3 == 0x67)))) {
        iVar4 = 5;
      }
      else {
        iVar4 = 0xf;
      }
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,iVar4);
      TRIBE_Screen_Game::setup_buttons(this->game_screen);
      add_notification_loc(this,param_4,param_5);
      return;
    }
    break;
  case 0x66:
  case 0x69:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      TRIBE_Screen_Game::setup_buttons(this->game_screen);
      add_notification_loc(this,param_4,param_5);
      return;
    }
    break;
  case 0x68:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,3);
      iVar4 = this->_padding_;
      uVar6 = 1000;
LAB_00524f71:
                    /* language.dll match for 0x67: "Comic Sans MS" */
      (**(code **)(iVar4 + 0x28))(0x67,uVar6,param_3);
      TRIBE_Screen_Game::show_message(this->game_screen,BadMessage,&stack0xfffffdec,'U','\0');
      return;
    }
    break;
  case 0x6b:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,3);
      iVar4 = this->_padding_;
      uVar6 = 0x6a;
      goto LAB_005250a4;
    }
    break;
  case 0x6c:
    if (this->game_screen != (TRIBE_Screen_Game *)0x0) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,8);
      if (param_2 == *(short *)(this->_padding_ + 0x7c)) {
                    /* language.dll match for 0xbf2: "You have started building a Wonder!" */
        (**(code **)(this->_padding_ + 0x20))(0xbf2);
      }
      else {
        iVar4 = *(int *)(*(int *)(this->_padding_ + 0x40) + param_2 * 4);
                    /* language.dll match for 0xbcb: "%s started building a Wonder!" */
        (**(code **)(this->_padding_ + 0x20))(0xbcb);
        sprintf(&stack0xfffffdf4,msg + 0xf8,*(undefined4 *)(iVar4 + 0x44));
      }
      TRIBE_Screen_Game::display_system_message(this->game_screen,&stack0xfffffdf4);
      add_notification_loc(this,unaff_retaddr,param_1);
      return;
    }
    break;
  case 0x6d:
    if (this->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)this,9);
    iVar4 = this->_padding_;
    pRVar1 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + param_2 * 4);
    pRVar2 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + *(short *)(iVar4 + 0x7c) * 4);
    if (pRVar1 == pRVar2) {
      if (*(int *)(iVar4 + 0x108) == 0) {
                    /* language.dll match for 0xbcc: "You completed a Wonder. You will win if it
                       stands for 2000 years!" */
        (**(code **)(this->_padding_ + 0x20))(0xbcc);
      }
      else {
                    /* language.dll match for 0xbee: "You completed a Wonder." */
        (**(code **)(this->_padding_ + 0x20))(0xbee);
      }
    }
    else {
      if ((((pRVar1->allied_victory == '\0') ||
           (uVar3 = RGE_Player::relation(pRVar1,(int)pRVar2->id), uVar3 != '\0')) ||
          (pRVar2->allied_victory == '\0')) ||
         (uVar3 = RGE_Player::relation(pRVar2,(int)pRVar1->id), uVar3 != '\0')) {
        iVar4 = this->_padding_;
        if (*(int *)(this->_padding_ + 0x108) != 0) goto LAB_00525645;
                    /* language.dll match for 0xbce: "%s completed a Wonder. You will lose if it
                       stands for 2000 years!" */
        (**(code **)(iVar4 + 0x20))(0xbce);
        pcVar7 = pRVar1->name;
      }
      else {
        iVar4 = this->_padding_;
        if (*(int *)(this->_padding_ + 0x108) == 0) {
                    /* language.dll match for 0xbcd: "%s completed a Wonder. You will win if it
                       stands for 2000 years!" */
          (**(code **)(iVar4 + 0x20))(0xbcd);
          pcVar7 = pRVar1->name;
        }
        else {
LAB_00525645:
                    /* language.dll match for 0xbef: "%s completed a Wonder." */
          (**(code **)(iVar4 + 0x20))(0xbef);
          pcVar7 = pRVar1->name;
        }
      }
LAB_00525745:
      sprintf(&stack0xfffffdf4,msg + 0xf8,pcVar7);
    }
    goto LAB_0052574d;
  case 0x6e:
    if (this->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    if (*(int *)(this->_padding_ + 0x108) != 0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)this,10);
    iVar4 = *(int *)(this->_padding_ + 0x40);
    pRVar1 = *(RGE_Player **)(iVar4 + param_2 * 4);
    pRVar2 = *(RGE_Player **)(iVar4 + *(short *)(this->_padding_ + 0x7c) * 4);
    if (pRVar1 != pRVar2) {
      if (((pRVar1->allied_victory == '\0') ||
          (uVar3 = RGE_Player::relation(pRVar1,(int)pRVar2->id), uVar3 != '\0')) ||
         ((pRVar2->allied_victory == '\0' ||
          (uVar3 = RGE_Player::relation(pRVar2,(int)pRVar1->id), uVar3 != '\0')))) {
                    /* language.dll match for 0xbd0: "%s's Wonder was destroyed!" */
        (**(code **)(this->_padding_ + 0x20))(0xbd0);
        pcVar7 = pRVar1->name;
      }
      else {
                    /* language.dll match for 0xbd0: "%s's Wonder was destroyed!" */
        (**(code **)(this->_padding_ + 0x20))(0xbd0);
        pcVar7 = pRVar1->name;
      }
      goto LAB_00525745;
    }
                    /* language.dll match for 0xbcf: "Your Wonder was destroyed!" */
    (**(code **)(this->_padding_ + 0x20))(0xbcf);
LAB_0052574d:
    add_notification_loc(this,unaff_retaddr,param_1);
LAB_00525a51:
    TRIBE_Screen_Game::display_system_message(this->game_screen,&stack0xfffffdf4);
    TRIBE_Screen_Game::reset_clocks(this->game_screen);
    return;
  case 0x72:
    if (this->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)this,0xb);
    iVar4 = this->_padding_;
    pRVar1 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + param_2 * 4);
    pRVar2 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + *(short *)(iVar4 + 0x7c) * 4);
    if (*(int *)(iVar4 + 0x108) == 0) {
      if (pRVar1 != pRVar2) {
        if (((pRVar1->allied_victory == '\0') ||
            (uVar3 = RGE_Player::relation(pRVar1,(int)pRVar2->id), uVar3 != '\0')) ||
           ((pRVar2->allied_victory == '\0' ||
            (uVar3 = RGE_Player::relation(pRVar2,(int)pRVar1->id), uVar3 != '\0')))) {
          iVar4 = this->_padding_;
          uVar6 = 0xbd5;
        }
        else {
          iVar4 = this->_padding_;
          uVar6 = 0xbd4;
        }
        goto LAB_00525830;
      }
                    /* language.dll match for 0xbd4: "All Artifacts have been captured. Hold them
                       for 2000 years to win!" */
      (**(code **)(this->_padding_ + 0x20))(0xbd4);
    }
    else {
      iVar4 = this->_padding_;
                    /* language.dll match for 0xbf0: "All Artifacts have been captured." */
      uVar6 = 0xbf0;
LAB_00525830:
      (**(code **)(iVar4 + 0x20))(uVar6);
    }
    TRIBE_Screen_Game::display_system_message(this->game_screen,&stack0xfffffdf4);
    TRIBE_Screen_Game::reset_clocks(this->game_screen);
    iVar4 = this->_padding_;
    iVar5 = 1;
    if (1 < *(short *)(iVar4 + 0x3c)) {
      do {
                    /* language.dll match for 0x72: "21" */
        (**(code **)(**(int **)(*(int *)(iVar4 + 0x40) + iVar5 * 4) + 0xe8))
                  ((int)pRVar1->id,iVar5,0x72,0,0,0);
        iVar4 = this->_padding_;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(short *)(iVar4 + 0x3c));
      return;
    }
    break;
  case 0x73:
    if (this->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    if (*(int *)(this->_padding_ + 0x108) != 0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)this,0xc);
    iVar4 = this->_padding_;
                    /* language.dll match for 0xbd6: "Control of the Artifacts was lost!" */
    uVar6 = 0xbd6;
    goto LAB_00525a47;
  case 0x74:
    if (this->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)this,0xb);
    iVar4 = this->_padding_;
    pRVar1 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + param_2 * 4);
    pRVar2 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + *(short *)(iVar4 + 0x7c) * 4);
    if (*(int *)(iVar4 + 0x108) == 0) {
      if (pRVar1 != pRVar2) {
        if ((((pRVar1->allied_victory == '\0') ||
             (uVar3 = RGE_Player::relation(pRVar1,(int)pRVar2->id), uVar3 != '\0')) ||
            (pRVar2->allied_victory == '\0')) ||
           (uVar3 = RGE_Player::relation(pRVar2,(int)pRVar1->id), uVar3 != '\0')) {
          iVar4 = this->_padding_;
          uVar6 = 0xbda;
        }
        else {
          iVar4 = this->_padding_;
          uVar6 = 0xbd9;
        }
        goto LAB_0052599f;
      }
                    /* language.dll match for 0xbd9: "All Ruins have been captured. Hold them for
                       2000 years to win!" */
      (**(code **)(this->_padding_ + 0x20))(0xbd9);
    }
    else {
      iVar4 = this->_padding_;
                    /* language.dll match for 0xbf1: "All Ruins have been captured." */
      uVar6 = 0xbf1;
LAB_0052599f:
      (**(code **)(iVar4 + 0x20))(uVar6);
    }
    TRIBE_Screen_Game::display_system_message(this->game_screen,&stack0xfffffdf4);
    TRIBE_Screen_Game::reset_clocks(this->game_screen);
    iVar4 = this->_padding_;
    iVar5 = 1;
    if (1 < *(short *)(iVar4 + 0x3c)) {
      do {
                    /* language.dll match for 0x74: "Copperplate Gothic Light" */
        (**(code **)(**(int **)(*(int *)(iVar4 + 0x40) + iVar5 * 4) + 0xe8))
                  ((int)pRVar1->id,iVar5,0x74,0,0,0);
        iVar4 = this->_padding_;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(short *)(iVar4 + 0x3c));
      return;
    }
    break;
  case 0x75:
    if (this->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    if (*(int *)(this->_padding_ + 0x108) != 0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)this,0xc);
    iVar4 = this->_padding_;
                    /* language.dll match for 0xbdb: "Control of the Ruins was lost!" */
    uVar6 = 0xbdb;
LAB_00525a47:
    (**(code **)(iVar4 + 0x20))(uVar6);
    goto LAB_00525a51;
  case 0x76:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,3);
      iVar4 = this->_padding_;
                    /* language.dll match for 0xbe7: "Not enough faith to perform a conversion." */
      uVar6 = 0xbe7;
LAB_00525bbc:
      (**(code **)(iVar4 + 0x20))(uVar6);
      TRIBE_Screen_Game::show_message(this->game_screen,BadMessage,&stack0xfffffdf4,'U','\0');
      return;
    }
    break;
  case 0x77:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,3);
      iVar4 = this->_padding_;
                    /* language.dll match for 0xbe8: "You must research Monotheism before you can
                       convert enemy Priests." */
      uVar6 = 0xbe8;
      goto LAB_00525bbc;
    }
    break;
  case 0x78:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,3);
      iVar4 = this->_padding_;
                    /* language.dll match for 0xbe9: "You must research Monotheism before you can
                       convert enemy buildings." */
      uVar6 = 0xbe9;
      goto LAB_00525bbc;
    }
    break;
  case 0x79:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,3);
      iVar4 = this->_padding_;
                    /* language.dll match for 0xbea: "Town Centers cannot be converted." */
      uVar6 = 0xbea;
      goto LAB_00525bbc;
    }
    break;
  case 0x7a:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,3);
      iVar4 = this->_padding_;
                    /* language.dll match for 0xbeb: "Wonders cannot be converted." */
      uVar6 = 0xbeb;
      goto LAB_00525bbc;
    }
    break;
  case 0x7b:
    if (((this->game_screen != (TRIBE_Screen_Game *)0x0) &&
        (iVar4 = (int)*(short *)(this->_padding_ + 0x7c), param_2 != iVar4)) && (param_3 == iVar4))
{
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,0xd);
    }
    break;
  case 0x7c:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      TRIBE_Screen_Game::setup_buttons(this->game_screen);
      return;
    }
    break;
  case 0x7d:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      iVar4 = this->_padding_;
      uVar6 = 1;
      goto LAB_00524f71;
    }
    break;
  case 0x7e:
    if ((param_2 == *(short *)(this->_padding_ + 0x7c)) &&
       (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)this,0x10);
      add_notification_loc(this,param_4,param_5);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: start_game
// Address: 00525d20
// [HELPER] s_scr2: "scr2"
// [HELPER] s_scr3: "scr3"
/* WARNING: Variable defined which should be unmapped: info_file */
/* public: int __thiscall TRIBE_Game::start_game(int) */

int __thiscall TRIBE_Game::start_game(TRIBE_Game *this,int param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  char *pcVar6;
  char *pcVar7;
  char info_file [256];
  
  iVar2 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)this);
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
    pcVar6 = &s_scr3;
    do {
      pcVar7 = pcVar6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar6 = pcVar7 + -uVar3;
    pcVar7 = info_file + 4;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    lVar5 = 0xc385;
  }
  else {
    uVar3 = 0xffffffff;
    pcVar6 = &s_scr2;
    do {
      pcVar7 = pcVar6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar6 = pcVar7 + -uVar3;
    pcVar7 = info_file + 4;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    lVar5 = 0xc384;
  }
  RGE_Base_Game::disable_input((RGE_Base_Game *)this);
  if (this->_padding_ == 0) {
                    /* language.dll match for 0x44d: "Loading game data..." */
    show_status_message(this,0x44d,info_file + 4,lVar5);
    iVar2 = load_game_data(this);
    if (iVar2 == 0) goto LAB_00525dd5;
  }
                    /* language.dll match for 0x451: "Starting a new game..." */
  show_status_message(this,0x451,info_file + 4,lVar5);
  iVar2 = create_game(this,0);
  if (iVar2 != 0) {
    set_save_game_name(this,(char *)0x0);
    set_load_game_name(this,(char *)0x0);
    if (param_1 != 0) {
      iVar2 = create_game_screen(this);
      return iVar2;
    }
    start_video(this,3,(char *)(*(int *)(this->_padding_ + 0x5c) + 0x1508));
    return 1;
  }
LAB_00525dd5:
  close_status_message(this);
  RGE_Base_Game::enable_input((RGE_Base_Game *)this);
  return 0;
}

// --------------------------------------------------

// Function: test_scenario
// Address: 00525e50
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
/* public: int __thiscall TRIBE_Game::test_scenario(char *) */

int __thiscall TRIBE_Game::test_scenario(TRIBE_Game *this,char *param_1)
{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar4 = 0xffffffff;
  do {
    pcVar6 = param_1;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = param_1 + 1;
    cVar2 = *param_1;
    param_1 = pcVar6;
  } while (cVar2 != '\0');
  uVar4 = ~uVar4;
  pcVar1 = this->testing_scenario;
  pcVar6 = pcVar6 + -uVar4;
  pcVar7 = pcVar1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  (**(code **)(this->_padding_ + 0xc))(0);
  iVar3 = start_scenario(this,pcVar1);
  if (iVar3 != 0) {
    return 1;
  }
  iVar3 = start_scenario_editor(this,pcVar1,0);
  if (iVar3 == 0) {
    iVar3 = start_menu(this);
    if (iVar3 == 0) {
      RGE_Base_Game::close((RGE_Base_Game *)this);
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: start_scenario
// Address: 00525ee0
// [HELPER] s__s_s_scn: "%s%s.scn"
// [HELPER] s__s_scn: "%s.scn"
// [HELPER] s__s_scx: "%s.scx"
/* WARNING: Variable defined which should be unmapped: first_any_player */
/* public: int __thiscall TRIBE_Game::start_scenario(char *) */

int __thiscall TRIBE_Game::start_scenario(TRIBE_Game *this,char *param_1)
{
  int iVar1;
  RGE_Scenario *this_00;
  int iVar2;
  int unaff_EBX;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int first_any_player;
  char scenario_file2 [260];
  _finddata_t file_info;
  
  RGE_Base_Game::disable_input((RGE_Base_Game *)this);
  RGE_Base_Game::setSinglePlayerGame((RGE_Base_Game *)this,1);
  RGE_Base_Game::setCampaignGame((RGE_Base_Game *)this,0);
  RGE_Base_Game::setSavedGame((RGE_Base_Game *)this,0);
  RGE_Base_Game::setScenarioGame((RGE_Base_Game *)this,1);
  RGE_Base_Game::setScenarioName((RGE_Base_Game *)this,param_1);
  setVictoryType(this,VictoryDefault,0);
  RGE_Base_Game::setFullVisibility((RGE_Base_Game *)this,0);
  RGE_Base_Game::setFogOfWar((RGE_Base_Game *)this,1);
  RGE_Base_Game::setAllowCheatCodes((RGE_Base_Game *)this,1);
  setRandomizePositions(this,0);
  setLongCombat(this,0);
  setAllowTrading(this,1);
  setFullTechTree(this,0);
  setResourceLevel(this,DefaultResources);
  setStartingAge(this,DefaultAge);
  setStartingUnits(this,0);
  setDeathMatch(this,'\0');
  setPopLimit(this,'2');
  iVar1 = RGE_Base_Game::get_single_player_difficulty((RGE_Base_Game *)this);
  RGE_Base_Game::setDifficulty((RGE_Base_Game *)this,iVar1);
  setQuickStartGame(this,'\0');
  uVar3 = 0;
  scenario_file2[0] = -1;
  scenario_file2[1] = -1;
  scenario_file2[2] = -1;
  scenario_file2[3] = -1;
  sprintf(scenario_file2 + 4,s__s_s_scn,this->_padding_ + 0xc17,param_1);
  iVar1 = __findfirst(scenario_file2 + 4,&file_info.time_create);
  if (iVar1 == -1) {
    pcVar5 = s__s_scx;
  }
  else {
    pcVar5 = s__s_scn;
  }
  sprintf(scenario_file2 + 4,pcVar5,param_1);
  this_00 = RGE_Base_Game::get_scenario_info((RGE_Base_Game *)this,scenario_file2 + 4,0);
  if (this_00 == (RGE_Scenario *)0x0) {
    RGE_Base_Game::enable_input((RGE_Base_Game *)this);
    return 0;
  }
  iVar1 = 0;
  do {
    iVar2 = RGE_Scenario::Get_player_Active(this_00,iVar1);
    if (iVar2 != 0) {
      setScenarioPlayer(this,uVar3,iVar1);
      iVar2 = RGE_Scenario::Get_player_Civ(this_00,iVar1);
      setCivilization(this,iVar1,iVar2);
      setPlayerColor(this,iVar1,iVar1 + 1);
      RGE_Base_Game::setPlayerTeam((RGE_Base_Game *)this,iVar1,1);
      setComputerName(this,iVar1,0);
      uVar3 = uVar3 + 1;
      if ((scenario_file2._0_4_ == -1) &&
         (iVar2 = RGE_Scenario::Get_player_Type(this_00,iVar1), iVar2 == 1)) {
        scenario_file2._0_4_ = iVar1;
      }
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  (**(code **)(this_00->_padding_ + 4))(1);
  if (uVar3 == 0) {
    RGE_Base_Game::enable_input((RGE_Base_Game *)this);
    return 0;
  }
  RGE_Base_Game::setNumberPlayers((RGE_Base_Game *)this,uVar3);
  if (unaff_EBX != -1) {
    iVar1 = 1;
    if (1 < (int)uVar3) {
      do {
        iVar2 = scenarioPlayer(this,iVar1);
        if (iVar2 == unaff_EBX) {
          iVar2 = scenarioPlayer(this,0);
          setScenarioPlayer(this,iVar1,iVar2);
          break;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)uVar3);
    }
    setScenarioPlayer(this,0,unaff_EBX);
  }
  TCommunications_Handler::SetPlayerHumanity((TCommunications_Handler *)this->_padding_,1,ME_HUMAN);
  uVar4 = 2;
  if (1 < (int)uVar3) {
    do {
      TCommunications_Handler::SetPlayerHumanity
                ((TCommunications_Handler *)this->_padding_,uVar4,ME_COMPUTER);
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 <= (int)uVar3);
  }
  while (uVar3 = uVar3 + 1, (int)uVar3 < 10) {
    TCommunications_Handler::SetPlayerHumanity
              ((TCommunications_Handler *)this->_padding_,uVar3,ME_ABSENT);
  }
  iVar1 = start_game(this,1);
  return iVar1;
}

// --------------------------------------------------

// Function: load_game
// Address: 00526170
// [HELPER] s_DEBUGLOAD: "DEBUGLOAD"
// [HELPER] s_DEBUGSAVEGAME: "DEBUGSAVEGAME"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s___Writing__f_: "  Writing=%f\n"
// [HELPER] s_____Doppled_master_obj____s___d_: "    Doppled master obj:  %s, %d.\n"
// [HELPER] s_____NULL_doppled_master_obj__: "    NULL doppled master obj.\n"
// [HELPER] s_________w_i__6_2f__6_2f__d_: "        w%i=%6.2f,%6.2f,%d\n"
// [HELPER] s_____path__s__6_2f__6_2f__6_2f_g_: "    path: s=%6.2f,%6.2f,%6.2f,g=%6.2f,%6.2f,%6.2f,cc=%d,wd=%d\n"
// [HELPER] s___num_dopple_obj__d_: "  num_dopple_obj=%d\n"
// [HELPER] s___num_sleep_obj__d_: "  num_sleep_obj=%d\n"
// [HELPER] s___p__d_attr__d___12_8f_: "  p#%d attr[%d]=%12.8f\n"
// [HELPER] s___p__d_checksum__d__1__d__2__d__: "  p#%d checksum=%d, 1=%d, 2=%d, 3=%d, 4=%d, act=%d\n"
// [HELPER] s___p__d_ob__d___s___st__d__at__8_: "  p#%d ob=%d (%s), st=%d, at=%8.4f, pos=%6.2f,%6.2f,%6.2f, tar=%d (%s)\n"
// [HELPER] s_c___s_txt: "c:\%s.txt"
// [HELPER] s_game_speed__6_2f_: "game_speed=%6.2f\n"
// [HELPER] s_old_world_time__u_: "old_world_time=%u\n"
// [HELPER] s_player__d__civ__d__score__d___s_: "player %d, civ=%d, score=%d, %s\n"
// [HELPER] s_total_checksum__d__act__d_: "total checksum=%d, act=%d\n"
// [HELPER] s_w: "w"
// [HELPER] s_world_time__u_: "world_time=%u\n"
/* public: int __thiscall TRIBE_Game::load_game(char *) */

int __thiscall TRIBE_Game::load_game(TRIBE_Game *this,char *param_1)
{
  Path *pPVar1;
  byte bVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  RGE_Action *pRVar6;
  uchar uVar7;
  char cVar8;
  TPanel *this_00;
  int iVar9;
  char *pcVar10;
  undefined1 *puVar11;
  int iVar12;
  long lVar13;
  int iVar14;
  int iVar15;
  Waypoint *pWVar16;
  uint uVar17;
  int iVar18;
  undefined4 uVar19;
  uint uVar20;
  int iVar21;
  char *pcVar22;
  double dVar23;
  PLAYERHUMANITY PVar24;
  RGE_Object_Node *list;
  RGE_Action_Node *act_node;
  RGE_Player *p;
  long action_checksum;
  long num2;
  long num3;
  float temp_position_checksum;
  int i;
  long total_action_checksum;
  long total_checksum;
  int iStack_2c0;
  long num1;
  long num4;
  char acStack_2ac [4];
  char target_name_fffffd58 [50];
  char target_name_fffffd8c [50];
  char target_name [50];
  char fileNameNoExt [260];
  char fn [260];
  
  this->inHandleIdle = 0;
  this_00 = TPanelSystem::currentPanel(&panel_system);
  RGE_Base_Game::disable_input((RGE_Base_Game *)this);
  iVar9 = this->_padding_;
  if (((iVar9 == 4) || (iVar9 == 6)) || (iVar9 == 5)) {
    this->_padding_ = 0;
    (**(code **)(*(int *)this->_padding_ + 0xb8))();
    this->game_screen = (TRIBE_Screen_Game *)0x0;
    TPanelSystem::destroyPanel(&panel_system,s_Game_Screen);
  }
                    /* language.dll match for 0x44d: "Loading game data..." */
  show_status_message(this,0x44d,(char *)0x0,-1);
  iVar9 = load_game_data(this);
  if (iVar9 == 0) {
    if ((this_00 == (TPanel *)0x0) || (pcVar10 = TPanel::panelName(this_00), pcVar10 == (char *)0x0)
       ) goto LAB_00526303;
    pcVar10 = TPanel::panelName(this_00);
    cVar8 = *pcVar10;
  }
  else {
                    /* language.dll match for 0x452: "Loading saved game..." */
    show_status_message(this,0x452,(char *)0x0,-1);
    if (this->_padding_ != 0) {
      *(undefined1 *)(this->_padding_ + 1) = 1;
    }
    uVar7 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)this,s_DEBUGSAVEGAME);
    if (uVar7 != '\0') {
      ENABLE_COMPRESSION = 0;
    }
    cVar8 = (**(code **)(*(int *)this->_padding_ + 0xcc))(param_1);
    iVar9 = 0;
    if (0 < *(short *)(this->_padding_ + 0x3c)) {
      do {
        RGE_Base_Game::reset_countdown_timer((RGE_Base_Game *)this,iVar9);
        iVar9 = iVar9 + 1;
      } while (iVar9 < *(short *)(this->_padding_ + 0x3c));
    }
    ENABLE_COMPRESSION = 1;
    if (this->_padding_ != 0) {
      *(undefined1 *)(this->_padding_ + 1) = 0;
    }
    if (cVar8 != '\0') {
      RGE_Base_Game::setFullVisibility
                ((RGE_Base_Game *)this,(uint)*(byte *)(*(int *)(this->_padding_ + 0x28) + 0x8db8));
      RGE_Base_Game::setFogOfWar
                ((RGE_Base_Game *)this,(uint)*(byte *)(*(int *)(this->_padding_ + 0x28) + 0x8db9));
      RGE_Base_Game::setAllowCheatCodes((RGE_Base_Game *)this,1);
      RGE_Base_Game::setSavedGame((RGE_Base_Game *)this,1);
      RGE_Base_Game::setNumberPlayers((RGE_Base_Game *)this,*(short *)(this->_padding_ + 0x3c) + -1)
      ;
      uVar7 = RGE_Base_Game::pathFinding((RGE_Base_Game *)this);
      if (uVar7 == '\x01') {
        numberPathingIterations = 5000;
      }
      else if (uVar7 == '\x02') {
        numberPathingIterations = 0x1d4c;
      }
      else {
                    /* language.dll match for 0x9c4: "This is not enabled in the trial version." */
        numberPathingIterations = 0x9c4;
      }
      uVar20 = 0;
      do {
        if ((int)uVar20 < (int)*(short *)(this->_padding_ + 0x3c)) {
          RGE_Base_Game::setPlayerID((RGE_Base_Game *)this,uVar20,uVar20);
          if (0 < (int)uVar20) {
            TCommunications_Handler::SetPlayerName
                      ((TCommunications_Handler *)this->_padding_,uVar20,
                       *(char **)(*(int *)(*(int *)(this->_padding_ + 0x40) + uVar20 * 4) + 0x44));
            if (uVar20 == 1) {
              PVar24 = ME_HUMAN;
            }
            else {
              PVar24 = ME_COMPUTER;
            }
            goto LAB_005263fb;
          }
        }
        else {
          RGE_Base_Game::setPlayerID((RGE_Base_Game *)this,uVar20,0);
          PVar24 = ME_ABSENT;
LAB_005263fb:
          TCommunications_Handler::SetPlayerHumanity
                    ((TCommunications_Handler *)this->_padding_,uVar20,PVar24);
        }
        uVar20 = uVar20 + 1;
      } while ((int)uVar20 < 9);
      uVar20 = 0xffffffff;
      do {
        pcVar10 = param_1;
        if (uVar20 == 0) break;
        uVar20 = uVar20 - 1;
        pcVar10 = param_1 + 1;
        cVar8 = *param_1;
        param_1 = pcVar10;
      } while (cVar8 != '\0');
      uVar20 = ~uVar20;
      pcVar10 = pcVar10 + -uVar20;
      pcVar22 = target_name + 0x30;
      for (uVar17 = uVar20 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
        *(undefined4 *)pcVar22 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar22 = pcVar22 + 4;
      }
      for (uVar20 = uVar20 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
        *pcVar22 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar22 = pcVar22 + 1;
      }
      puVar11 = (undefined1 *)__mbschr(target_name + 0x30,0x2e);
      if (puVar11 != (undefined1 *)0x0) {
        *puVar11 = 0;
      }
      set_save_game_name(this,target_name + 0x30);
      set_load_game_name(this,target_name + 0x30);
      uVar7 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)this,s_DEBUGLOAD);
      if (uVar7 != '\0') {
        sprintf(fileNameNoExt + 0x100,s_c___s_txt,target_name + 0x30);
        iVar9 = fopen(fileNameNoExt + 0x100,s_w);
        if (iVar9 != 0) {
          total_action_checksum = 0;
          i = 0;
          fprintf(iVar9,s_world_time__u_,*(undefined4 *)(this->_padding_ + 4));
          fprintf(iVar9,s_old_world_time__u_,*(undefined4 *)(this->_padding_ + 8));
          fprintf(iVar9,s_game_speed__6_2f_,(double)*(float *)(this->_padding_ + 0x18));
          iVar12 = this->_padding_;
          temp_position_checksum = 0.0;
          if (0 < *(short *)(iVar12 + 0x3c)) {
            do {
              iVar12 = *(int *)(*(int *)(iVar12 + 0x40) + (int)temp_position_checksum * 4);
              uVar19 = *(undefined4 *)(iVar12 + 0x44);
              lVar13 = RGE_Victory_Conditions::get_victory_points
                                 (*(RGE_Victory_Conditions **)(iVar12 + 0x34));
              fprintf(iVar9,s_player__d__civ__d__score__d___s_,temp_position_checksum,
                      *(undefined1 *)(iVar12 + 0x105),lVar13,uVar19);
              fprintf(iVar9,s___Writing__f_,(double)*(float *)(*(int *)(iVar12 + 0x50) + 200));
              iVar21 = 0;
              iVar14 = (int)*(short *)(*(int *)(iVar12 + 0x2c) + 8);
              iVar18 = *(short *)(*(int *)(iVar12 + 0x30) + 8) + iVar14 +
                       (int)*(short *)(iVar12 + 0x4a);
              iStack_2c0 = 0;
              action_checksum = 0;
              num2 = 0;
              p = (RGE_Player *)0x0;
              fprintf(iVar9,s___num_sleep_obj__d_,iVar14);
              fprintf(iVar9,s___num_dopple_obj__d_,(int)*(short *)(*(int *)(iVar12 + 0x30) + 8));
              if (0 < *(short *)(iVar12 + 0x4c)) {
                do {
                  iVar14 = *(int *)(iVar12 + 0x50);
                  iVar15 = __ftol();
                  iStack_2c0 = iStack_2c0 + iVar15;
                  fprintf(iVar9,s___p__d_attr__d___12_8f_,(int)*(short *)(iVar12 + 0x4a),iVar21,
                          (double)*(float *)(iVar14 + iVar21 * 4));
                  iVar21 = iVar21 + 1;
                } while (iVar21 < *(short *)(iVar12 + 0x4c));
              }
              for (piVar3 = *(int **)(*(int *)(iVar12 + 0x28) + 4); piVar3 != (int *)0x0;
                  piVar3 = (int *)piVar3[1]) {
                piVar4 = (int *)*piVar3;
                bVar2 = *(byte *)(piVar4 + 0x12);
                iVar14 = __ftol();
                action_checksum =
                     *(short *)(piVar4[2] + 0x10) + action_checksum + (uint)bVar2 + iVar14;
                num2 = num2 + 1;
                iVar14 = (**(code **)(*piVar4 + 0x1d0))();
                p = (RGE_Player *)((int)&p->_padding_ + iVar14);
                iVar14 = (**(code **)(*(int *)*piVar3 + 0xcc))();
                if (iVar14 == 0) {
                  target_name_fffffd8c[0x30] = '\0';
                  uVar19 = 0xffffffff;
                }
                else {
                  uVar20 = 0xffffffff;
                  pcVar10 = *(char **)(*(int *)(iVar14 + 8) + 8);
                  do {
                    pcVar22 = pcVar10;
                    if (uVar20 == 0) break;
                    uVar20 = uVar20 - 1;
                    pcVar22 = pcVar10 + 1;
                    cVar8 = *pcVar10;
                    pcVar10 = pcVar22;
                  } while (cVar8 != '\0');
                  uVar20 = ~uVar20;
                  pcVar10 = pcVar22 + -uVar20;
                  pcVar22 = target_name_fffffd8c + 0x30;
                  for (uVar17 = uVar20 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
                    *(undefined4 *)pcVar22 = *(undefined4 *)pcVar10;
                    pcVar10 = pcVar10 + 4;
                    pcVar22 = pcVar22 + 4;
                  }
                  for (uVar20 = uVar20 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
                    *pcVar22 = *pcVar10;
                    pcVar10 = pcVar10 + 1;
                    pcVar22 = pcVar22 + 1;
                  }
                  uVar19 = *(undefined4 *)(iVar14 + 4);
                }
                iVar14 = *piVar3;
                fprintf(iVar9,s___p__d_ob__d___s___st__d__at__8_,(int)*(short *)(iVar12 + 0x4a),
                        *(undefined4 *)(iVar14 + 4),*(undefined4 *)(*(int *)(iVar14 + 8) + 8),
                        *(undefined1 *)(iVar14 + 0x48),(double)*(float *)(iVar14 + 0x44),
                        (double)*(float *)(iVar14 + 0x38),(double)*(float *)(iVar14 + 0x3c),
                        (double)*(float *)(iVar14 + 0x40),uVar19,target_name_fffffd8c + 0x30);
                bVar2 = *(byte *)(*(int *)(*piVar3 + 8) + 4);
                if ((0x1d < bVar2) && (bVar2 != 0x5a)) {
                  pPVar1 = (Path *)(*piVar3 + 0xa4);
                  iVar14 = Path::numberOfWaypoints(pPVar1);
                  if (0 < iVar14) {
                    Path::initToStart(pPVar1);
                    fprintf(iVar9,s_____path__s__6_2f__6_2f__6_2f_g_);
                    iVar21 = 0;
                    iVar14 = Path::numberOfWaypoints(pPVar1);
                    if (0 < iVar14) {
                      do {
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        uVar20 = (uint)pWVar16->facetToNextWaypoint;
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        dVar23 = (double)pWVar16->y;
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        fprintf(iVar9,s_________w_i__6_2f__6_2f__d_,iVar21,(double)pWVar16->x,dVar23
                                ,uVar20);
                        iVar21 = iVar21 + 1;
                        Path::moveToNextWaypoint(pPVar1);
                        iVar14 = Path::numberOfWaypoints(pPVar1);
                      } while (iVar21 < iVar14);
                    }
                    Path::initToStart(pPVar1);
                    Path::moveToNextWaypoint(pPVar1);
                  }
                }
                bVar2 = *(byte *)(*(int *)(*piVar3 + 8) + 4);
                if ((0x27 < bVar2) && (bVar2 != 0x5a)) {
                  for (puVar5 = *(undefined4 **)(*(int *)(*piVar3 + 0x184) + 8);
                      puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)puVar5[1]) {
                    pRVar6 = (RGE_Action *)*puVar5;
                    if (pRVar6 != (RGE_Action *)0x0) {
                      RGE_Action::subAction(pRVar6);
                      RGE_Action::targetZ(pRVar6);
                      RGE_Action::targetY(pRVar6);
                      RGE_Action::targetX(pRVar6);
                      fprintf(iVar9);
                    }
                  }
                }
              }
              for (piVar3 = *(int **)(*(int *)(iVar12 + 0x30) + 4); piVar3 != (int *)0x0;
                  piVar3 = (int *)piVar3[1]) {
                piVar4 = (int *)*piVar3;
                bVar2 = *(byte *)(piVar4 + 0x12);
                iVar14 = __ftol();
                action_checksum =
                     *(short *)(piVar4[2] + 0x10) + action_checksum + (uint)bVar2 + iVar14;
                num2 = num2 + 1;
                iVar14 = (**(code **)(*piVar4 + 0x1d0))();
                p = (RGE_Player *)((int)&p->_padding_ + iVar14);
                iVar14 = (**(code **)(*(int *)*piVar3 + 0xcc))();
                if (iVar14 == 0) {
                  acStack_2ac[0] = '\0';
                  uVar19 = 0xffffffff;
                }
                else {
                  uVar20 = 0xffffffff;
                  pcVar10 = *(char **)(*(int *)(iVar14 + 8) + 8);
                  do {
                    pcVar22 = pcVar10;
                    if (uVar20 == 0) break;
                    uVar20 = uVar20 - 1;
                    pcVar22 = pcVar10 + 1;
                    cVar8 = *pcVar10;
                    pcVar10 = pcVar22;
                  } while (cVar8 != '\0');
                  uVar20 = ~uVar20;
                  pcVar10 = pcVar22 + -uVar20;
                  pcVar22 = acStack_2ac;
                  for (uVar17 = uVar20 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
                    *(undefined4 *)pcVar22 = *(undefined4 *)pcVar10;
                    pcVar10 = pcVar10 + 4;
                    pcVar22 = pcVar22 + 4;
                  }
                  for (uVar20 = uVar20 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
                    *pcVar22 = *pcVar10;
                    pcVar10 = pcVar10 + 1;
                    pcVar22 = pcVar22 + 1;
                  }
                  uVar19 = *(undefined4 *)(iVar14 + 4);
                }
                iVar14 = *piVar3;
                fprintf(iVar9,s___p__d_ob__d___s___st__d__at__8_,(int)*(short *)(iVar12 + 0x4a),
                        *(undefined4 *)(iVar14 + 4),*(undefined4 *)(*(int *)(iVar14 + 8) + 8),
                        *(undefined1 *)(iVar14 + 0x48),(double)*(float *)(iVar14 + 0x44),
                        (double)*(float *)(iVar14 + 0x38),(double)*(float *)(iVar14 + 0x3c),
                        (double)*(float *)(iVar14 + 0x40),uVar19,acStack_2ac);
                if (*piVar3 != 0) {
                  iVar14 = *(int *)(*piVar3 + 0x94);
                  if (iVar14 == 0) {
                    fprintf(iVar9,s_____NULL_doppled_master_obj__);
                  }
                  else {
                    fprintf(iVar9,s_____Doppled_master_obj____s___d_,*(undefined4 *)(iVar14 + 8),
                            (int)*(short *)(iVar14 + 0x10));
                  }
                }
                bVar2 = *(byte *)(*(int *)(*piVar3 + 8) + 4);
                if ((0x1d < bVar2) && (bVar2 != 0x5a)) {
                  pPVar1 = (Path *)(*piVar3 + 0xa4);
                  iVar14 = Path::numberOfWaypoints(pPVar1);
                  if (0 < iVar14) {
                    Path::initToStart(pPVar1);
                    fprintf(iVar9,s_____path__s__6_2f__6_2f__6_2f_g_);
                    iVar21 = 0;
                    iVar14 = Path::numberOfWaypoints(pPVar1);
                    if (0 < iVar14) {
                      do {
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        uVar20 = (uint)pWVar16->facetToNextWaypoint;
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        dVar23 = (double)pWVar16->y;
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        fprintf(iVar9,s_________w_i__6_2f__6_2f__d_,iVar21,(double)pWVar16->x,dVar23
                                ,uVar20);
                        iVar21 = iVar21 + 1;
                        Path::moveToNextWaypoint(pPVar1);
                        iVar14 = Path::numberOfWaypoints(pPVar1);
                      } while (iVar21 < iVar14);
                    }
                    Path::initToStart(pPVar1);
                    Path::moveToNextWaypoint(pPVar1);
                  }
                }
                bVar2 = *(byte *)(*(int *)(*piVar3 + 8) + 4);
                if ((0x27 < bVar2) && (bVar2 != 0x5a)) {
                  for (puVar5 = *(undefined4 **)(*(int *)(*piVar3 + 0x184) + 8);
                      puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)puVar5[1]) {
                    pRVar6 = (RGE_Action *)*puVar5;
                    if (pRVar6 != (RGE_Action *)0x0) {
                      RGE_Action::subAction(pRVar6);
                      RGE_Action::targetZ(pRVar6);
                      RGE_Action::targetY(pRVar6);
                      RGE_Action::targetX(pRVar6);
                      fprintf(iVar9);
                    }
                  }
                }
              }
              for (piVar3 = *(int **)(*(int *)(iVar12 + 0x2c) + 4); piVar3 != (int *)0x0;
                  piVar3 = (int *)piVar3[1]) {
                iVar14 = (**(code **)(*(int *)*piVar3 + 0xcc))();
                if (iVar14 == 0) {
                  target_name_fffffd58[0x30] = '\0';
                  uVar19 = 0xffffffff;
                }
                else {
                  uVar20 = 0xffffffff;
                  pcVar10 = *(char **)(*(int *)(iVar14 + 8) + 8);
                  do {
                    pcVar22 = pcVar10;
                    if (uVar20 == 0) break;
                    uVar20 = uVar20 - 1;
                    pcVar22 = pcVar10 + 1;
                    cVar8 = *pcVar10;
                    pcVar10 = pcVar22;
                  } while (cVar8 != '\0');
                  uVar20 = ~uVar20;
                  pcVar10 = pcVar22 + -uVar20;
                  pcVar22 = target_name_fffffd58 + 0x30;
                  for (uVar17 = uVar20 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
                    *(undefined4 *)pcVar22 = *(undefined4 *)pcVar10;
                    pcVar10 = pcVar10 + 4;
                    pcVar22 = pcVar22 + 4;
                  }
                  for (uVar20 = uVar20 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
                    *pcVar22 = *pcVar10;
                    pcVar10 = pcVar10 + 1;
                    pcVar22 = pcVar22 + 1;
                  }
                  uVar19 = *(undefined4 *)(iVar14 + 4);
                }
                iVar14 = *piVar3;
                fprintf(iVar9,s___p__d_ob__d___s___st__d__at__8_,(int)*(short *)(iVar12 + 0x4a),
                        *(undefined4 *)(iVar14 + 4),*(undefined4 *)(*(int *)(iVar14 + 8) + 8),
                        *(undefined1 *)(iVar14 + 0x48),(double)*(float *)(iVar14 + 0x44),
                        (double)*(float *)(iVar14 + 0x38),(double)*(float *)(iVar14 + 0x3c),
                        (double)*(float *)(iVar14 + 0x40),uVar19,target_name_fffffd58 + 0x30);
              }
              iVar14 = ((iVar18 * 0x100 + num2) * 0x100 + action_checksum) * 0x100 + iStack_2c0;
              total_action_checksum = total_action_checksum + iVar14;
              i = (int)&p->_padding_ + i;
              fprintf(iVar9,s___p__d_checksum__d__1__d__2__d__,(int)*(short *)(iVar12 + 0x4a),iVar14
                      ,iStack_2c0,action_checksum,num2,iVar18,p);
              temp_position_checksum = (float)((int)temp_position_checksum + 1);
              iVar12 = this->_padding_;
            } while ((int)temp_position_checksum < (int)*(short *)(iVar12 + 0x3c));
          }
          fprintf(iVar9,s_total_checksum__d__act__d_,total_action_checksum,i);
          fclose(iVar9);
        }
      }
      close_game_screens(this,0);
      iVar9 = create_game_screen(this);
      return iVar9;
    }
    if ((this_00 == (TPanel *)0x0) || (pcVar10 = TPanel::panelName(this_00), pcVar10 == (char *)0x0)
       ) goto LAB_00526303;
    pcVar10 = TPanel::panelName(this_00);
    cVar8 = *pcVar10;
  }
  if (cVar8 != '\0') {
    iVar9 = 0;
    pcVar10 = TPanel::panelName(this_00);
    TPanelSystem::setCurrentPanel(&panel_system,pcVar10,iVar9);
    TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
    RGE_Base_Game::enable_input((RGE_Base_Game *)this);
    return 0;
  }
LAB_00526303:
  close_status_message(this);
  RGE_Base_Game::enable_input((RGE_Base_Game *)this);
  return 0;
}

// --------------------------------------------------

// Function: do_game_over
// Address: 00526dc0
/* public: void __thiscall TRIBE_Game::do_game_over(void) */

void __thiscall TRIBE_Game::do_game_over(TRIBE_Game *this)
{
  int iVar1;
  RGE_Player *pRVar2;
  
  disconnect_multiplayer_game(this);
  if (this->testing_scenario[0] != '\0') {
    quit_game(this);
    return;
  }
  iVar1 = this->_padding_;
  if (((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 5)) || (iVar1 == 3)) &&
     (this->_padding_ = 0, this->_padding_ != 0)) {
    RGE_Base_Game::turn_world_sound_off((RGE_Base_Game *)this);
    pRVar2 = RGE_Base_Game::get_player((RGE_Base_Game *)this);
    if (pRVar2->game_status == '\x01') {
      start_video(this,4,(char *)(*(int *)(this->_padding_ + 0x5c) + 0x15e8));
      return;
    }
    start_video(this,4,(char *)(*(int *)(this->_padding_ + 0x5c) + 0x16c8));
  }
  return;
}

// --------------------------------------------------

// Function: create_game
// Address: 00526e60
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
// [HELPER] s_QUICKBUILD: "QUICKBUILD"
// [HELPER] s__s_s_scn: "%s%s.scn"
// [HELPER] s__s_scn: "%s.scn"
// [HELPER] s__s_scx: "%s.scx"
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Type propagation algorithm not settling */
/* protected: int __thiscall TRIBE_Game::create_game(int) */

int __thiscall TRIBE_Game::create_game(TRIBE_Game *this,int param_1)
{
  bool bVar1;
  uchar uVar2;
  char cVar3;
  long *plVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  undefined1 *puVar12;
  uint uVar13;
  char *pcVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  char *pcVar19;
  RGE_Map_Gen_Info *pRVar20;
  MapType MVar21;
  undefined4 uVar22;
  int i;
  T_Scenario *scenario_info;
  int player_index;
  int scenario_player;
  uchar path_finding_val;
  int humanity;
  int position_used [8];
  RGE_Player_Info player_info;
  char scenario_file [260];
  _finddata_t file_info;
  RGE_Map_Gen_Info map_info;
  
  iVar15 = 0;
  iVar11 = 5;
  this->inHandleIdle = 0;
  plVar4 = this->notification_loc_y;
  do {
    plVar4[-5] = -1;
    *plVar4 = -1;
    plVar4 = plVar4 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  this->current_notification_loc = -1;
  this->current_notification_recalled = -1;
  uVar2 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)this,s_QUICKBUILD);
  if (uVar2 == '\0') {
    this->_padding_ = 0;
  }
  else {
    this->_padding_ = 1;
  }
  this->_padding_ = 0;
  this->_padding_ = 0;
  this->_padding_ = 0;
  RGE_Base_Game::set_map_visible((RGE_Base_Game *)this,'\0');
  RGE_Base_Game::set_map_fog((RGE_Base_Game *)this,'\0');
  puVar12 = (undefined1 *)((int)&this->_padding_ + 2);
  puVar5 = &DAT_0086bcac;
  plVar4 = this->queue_is_waiting_on_pop_counter;
  do {
    plVar4 = plVar4 + 1;
    *puVar12 = 0;
    *puVar5 = 0;
    *plVar4 = 0;
    puVar5 = puVar5 + 1;
    puVar12 = puVar12 + 1;
  } while ((int)puVar5 < 0x86bccc);
  out_of_sync = 0;
  out_of_sync2 = 0;
  no_other_humans_count = 0;
  uVar2 = quickStartGame(this);
  if (uVar2 != '\0') {
    if (quick_start_game_mode == 1) {
      setMapSize(this,Medium);
      MVar21 = AllLand;
    }
    else {
      setMapSize(this,Large);
      iVar11 = debug_rand(s_C__msdev_work_age1_x1_tribegam_c,0xcdd);
      MVar21 = iVar11 % 10;
      if ((int)MVar21 < 2) {
        MVar21 = AllLand;
      }
      else if (MVar21 == WaterAndLand) {
        MVar21 = MostlyLand;
      }
      else if (MVar21 == MostlyLand) {
        MVar21 = WaterAndLand;
      }
      else if (MVar21 == AllLand) {
        MVar21 = MostlyWater;
      }
      else if (((MVar21 != Continental) && (MVar21 != Lake)) && (MVar21 != Hilly)) {
        MVar21 = (MVar21 != Isthmas) - MostlyWater & Isthmas;
      }
    }
    setMapType(this,MVar21);
    resetRandomComputerName(this);
    iVar11 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)this);
    if (0 < iVar11) {
      do {
        uVar6 = debug_rand(s_C__msdev_work_age1_x1_tribegam_c,0xcf8);
        uVar13 = (int)uVar6 >> 0x1f;
        iVar11 = (((uVar6 ^ uVar13) - uVar13 & 0xf ^ uVar13) - uVar13) + 1;
        setCivilization(this,iVar15,iVar11);
        iVar11 = randomComputerName(this,iVar11);
        setComputerName(this,iVar15,iVar11);
        iVar15 = iVar15 + 1;
        iVar11 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)this);
      } while (iVar15 < iVar11);
    }
  }
  pcVar14 = player_info.name[0];
  for (iVar11 = 0xab; pcVar14 = pcVar14 + 4, iVar11 != 0; iVar11 = iVar11 + -1) {
    pcVar14[0] = '\0';
    pcVar14[1] = '\0';
    pcVar14[2] = '\0';
    pcVar14[3] = '\0';
  }
  pRVar20 = &map_info;
  for (iVar11 = 0x148; pRVar20 = (RGE_Map_Gen_Info *)&pRVar20->land, iVar11 != 0;
      iVar11 = iVar11 + -1) {
    ((RGE_Info_Line *)pRVar20)->clump_num = 0.0;
  }
  iVar11 = RGE_Base_Game::campaignGame((RGE_Base_Game *)this);
  if (iVar11 == 0) {
    iVar11 = RGE_Base_Game::scenarioGame((RGE_Base_Game *)this);
    if (iVar11 == 0) {
      player_info._672_4_ = &map_info.land;
      MVar21 = mapType(this);
      player_info.map_height = (short)MVar21;
      iVar11 = RGE_Base_Game::mapXSize((RGE_Base_Game *)this);
      player_info.ai_info = (short)iVar11;
      iVar11 = RGE_Base_Game::mapYSize((RGE_Base_Game *)this);
      player_info._680_2_ = SUB42(iVar11,0);
    }
    else {
      pcVar14 = RGE_Base_Game::scenarioName((RGE_Base_Game *)this);
      if (pcVar14 == (char *)0x0) {
        return 0;
      }
      iVar11 = this->_padding_;
      pcVar14 = RGE_Base_Game::scenarioName((RGE_Base_Game *)this);
      sprintf(scenario_file + 4,s__s_s_scn,iVar11 + 0xc17,pcVar14);
      iVar11 = __findfirst(scenario_file + 4,&file_info.time_create);
      if (iVar11 == -1) {
        pcVar14 = RGE_Base_Game::scenarioName((RGE_Base_Game *)this);
        pcVar9 = s__s_scx;
      }
      else {
        pcVar14 = RGE_Base_Game::scenarioName((RGE_Base_Game *)this);
        pcVar9 = s__s_scn;
      }
      sprintf(scenario_file + 4,pcVar9,pcVar14);
      player_info.map_info = (RGE_Map_Gen_Info *)(scenario_file + 4);
    }
  }
  else {
    scenario_file[0] = '\x01';
  }
  iVar11 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)this);
  if (iVar11 == 0) {
    uVar6 = this->_padding_;
    if (uVar6 == 0xffffffff) {
      uVar6 = debug_rand(s_C__msdev_work_age1_x1_tribegam_c,0xd2a);
      iVar11 = 0xd2a;
    }
    else {
      iVar11 = 0xd28;
    }
  }
  else {
    uVar6 = TCommunications_Handler::GetRandomSeed(comm);
    iVar11 = 0xd24;
  }
  debug_srand(s_C__msdev_work_age1_x1_tribegam_c,iVar11,uVar6);
  iVar11 = 0;
  player_index = (int)(player_info.color + 2);
  scenario_info = (T_Scenario *)(player_info.player_id_hash + 1);
  player_info.scenario._0_2_ = 0;
  pcVar14 = player_info.name[0] + 4;
  piVar16 = this->random_civ;
  do {
    player_info.type[iVar11 + 4] = -1;
    *pcVar14 = '\0';
    scenario_info->_padding_ = iVar11;
    player_info.tribe[iVar11 + 4] = '\x01';
    *(undefined2 *)player_index = 0xffff;
    *piVar16 = 0;
    iVar15 = civilization(this,iVar11);
    if ((0x10 < iVar15) || (iVar15 = civilization(this,iVar11), iVar15 < 0)) {
      iVar15 = debug_rand(s_C__msdev_work_age1_x1_tribegam_c,0xd3b);
      setCivilization(this,iVar11,(iVar15 * 0x10) / 0x7fff + 1);
      *piVar16 = 1;
    }
    iVar11 = iVar11 + 1;
    pcVar14 = pcVar14 + 0x41;
    scenario_info = (T_Scenario *)&scenario_info->_padding_;
    piVar16 = piVar16 + 1;
    player_index = player_index + 2;
  } while (iVar11 < 9);
  resetRandomComputerName(this);
  iVar11 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)this);
  uVar6 = 0;
  if (0 < iVar11) {
    do {
      uVar13 = uVar6 + 1;
      iVar11 = TCommunications_Handler::GetPlayerHumanity(comm,uVar13);
      if (iVar11 == 4) {
        iVar11 = civilization(this,uVar6);
        iVar11 = randomComputerName(this,iVar11);
        setComputerName(this,uVar6,iVar11);
      }
      iVar11 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)this);
      uVar6 = uVar13;
    } while ((int)uVar13 < iVar11);
  }
  iVar11 = RGE_Base_Game::campaignGame((RGE_Base_Game *)this);
  if (iVar11 == 0) {
    iVar11 = RGE_Base_Game::scenarioGame((RGE_Base_Game *)this);
    if (iVar11 == 0) {
      player_index = 0;
      goto LAB_005272dd;
    }
    iVar11 = 0;
    pRVar20 = player_info.map_info;
  }
  else {
    iVar11 = 1;
    pRVar20 = (RGE_Map_Gen_Info *)0x0;
  }
  player_index = (int)RGE_Base_Game::get_scenario_info((RGE_Base_Game *)this,(char *)pRVar20,iVar11)
  ;
  if ((RGE_Scenario *)player_index == (RGE_Scenario *)0x0) {
    return 0;
  }
LAB_005272dd:
  iVar15 = 0;
  piVar16 = position_used;
  for (iVar11 = 9; piVar16 = piVar16 + 1, iVar11 != 0; iVar11 = iVar11 + -1) {
    *piVar16 = -1;
  }
  do {
    RGE_Base_Game::setPlayerID((RGE_Base_Game *)this,iVar15,0);
    iVar15 = iVar15 + 1;
  } while (iVar15 < 9);
  scenario_player = 0;
  scenario_info = (T_Scenario *)0x1;
  iVar11 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)this);
  if (0 < iVar11) {
    do {
      iVar11 = TCommunications_Handler::GetPlayerHumanity
                         ((TCommunications_Handler *)this->_padding_,(uint)scenario_info);
      if (iVar11 == 2) {
        iVar11 = playerColor(this,(int)((int)&scenario_info[-1].victory_time + 3));
        if (position_used[iVar11] == -1) {
          position_used[iVar11] = scenario_player;
          scenario_player = scenario_player + 1;
        }
        RGE_Base_Game::setPlayerID
                  ((RGE_Base_Game *)this,(int)scenario_info,position_used[iVar11] + 1);
      }
      else {
        iVar11 = TCommunications_Handler::GetPlayerHumanity
                           ((TCommunications_Handler *)this->_padding_,(uint)scenario_info);
        if (iVar11 == 4) {
          _path_finding_val = position_used;
          iVar11 = 0;
          do {
            _path_finding_val = _path_finding_val + 1;
            if (*_path_finding_val == -1) {
              bVar1 = false;
              uVar6 = 1;
              do {
                iVar15 = TCommunications_Handler::GetPlayerHumanity
                                   ((TCommunications_Handler *)this->_padding_,uVar6);
                if ((iVar15 == 2) && (iVar15 = playerColor(this,uVar6 - 1), iVar15 + -1 == iVar11))
{
                  bVar1 = true;
                  break;
                }
                uVar6 = uVar6 + 1;
              } while ((int)uVar6 < 9);
              if (!bVar1) {
                setPlayerColor(this,(int)((int)&scenario_info[-1].victory_time + 3),iVar11 + 1);
                position_used[iVar11 + 1] = scenario_player;
                scenario_player = scenario_player + 1;
                RGE_Base_Game::setPlayerID
                          ((RGE_Base_Game *)this,(int)scenario_info,position_used[iVar11 + 1] + 1);
                break;
              }
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 < 8);
        }
      }
      scenario_info = (T_Scenario *)((int)&scenario_info->_padding_ + 1);
      iVar11 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)this);
    } while ((int)scenario_info <= iVar11);
  }
  resetRandomComputerName(this);
  humanity = (int)(player_info.color + 2);
  position_used[0] = (int)(player_info.player_id_hash + 2);
  pcVar14 = player_info.name[0] + 4;
  iVar11 = 0;
  do {
    iVar15 = iVar11 + 1;
    scenario_player = 0;
    iVar17 = 1;
    do {
      iVar7 = RGE_Base_Game::playerID((RGE_Base_Game *)this,iVar17);
      iVar8 = iVar17;
      if (iVar7 == iVar15) break;
      iVar17 = iVar17 + 1;
      iVar8 = scenario_player;
    } while (iVar17 < 9);
    scenario_player = iVar8;
    if (scenario_player == 0) break;
    iVar8 = TCommunications_Handler::GetPlayerHumanity
                      ((TCommunications_Handler *)this->_padding_,scenario_player);
    iVar17 = scenario_player + -1;
    iVar7 = playerColor(this,iVar17);
    iVar18 = iVar7 + -1;
    if (((iVar8 == 4) || (all_cp == 1)) || ((all_cp == 2 && (0 < iVar11)))) {
      pcVar9 = player_info.type + iVar11 + 4;
      *pcVar9 = '\x04';
    }
    else {
      pcVar9 = player_info.type + iVar11 + 4;
      *pcVar9 = '\0';
    }
    iVar11 = RGE_Base_Game::campaignGame((RGE_Base_Game *)this);
    if (iVar11 == 0) {
      iVar11 = civilization(this,iVar17);
      cVar3 = (char)iVar11;
    }
    else {
      iVar11 = RGE_Scenario::Get_player_Civ((RGE_Scenario *)player_index,iVar18);
      cVar3 = (char)iVar11;
    }
    pcVar9[9] = cVar3;
    iVar11 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)this);
    if ((iVar11 == 0) || (iVar8 != 2)) {
      iVar11 = RGE_Base_Game::campaignGame((RGE_Base_Game *)this);
      if ((iVar11 == 0) || (*pcVar9 != '\0')) {
        iVar11 = RGE_Base_Game::campaignGame((RGE_Base_Game *)this);
        if (((iVar11 == 0) &&
            (iVar11 = RGE_Base_Game::randomGame((RGE_Base_Game *)this), iVar11 != 0)) &&
           (*pcVar9 == '\0')) {
                    /* language.dll match for 0x286d: "You" */
          (**(code **)(this->_padding_ + 0x20))(0x286d,pcVar14,0x41);
        }
        else {
          iVar11 = RGE_Base_Game::campaignGame((RGE_Base_Game *)this);
          if ((iVar11 != 0) ||
             (iVar11 = RGE_Base_Game::scenarioGame((RGE_Base_Game *)this), iVar11 != 0)) {
            pcVar10 = RGE_Scenario::GetPlayerName((RGE_Scenario *)player_index,iVar18);
            goto LAB_0052759b;
          }
        }
      }
      else {
        pcVar10 = RGE_Game_Info::get_current_player_name((RGE_Game_Info *)this->_padding_);
LAB_0052759b:
        uVar6 = 0xffffffff;
        do {
          pcVar19 = pcVar10;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar19 = pcVar10 + 1;
          cVar3 = *pcVar10;
          pcVar10 = pcVar19;
        } while (cVar3 != '\0');
        uVar6 = ~uVar6;
        pcVar10 = pcVar19 + -uVar6;
        pcVar19 = pcVar14;
        for (uVar13 = uVar6 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
          *(undefined4 *)pcVar19 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar19 = pcVar19 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar19 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar19 = pcVar19 + 1;
        }
      }
      if (*pcVar14 == '\0') {
        if (*pcVar9 == '\0') {
                    /* language.dll match for 0x286d: "You" */
          (**(code **)(this->_padding_ + 0x20))(0x286d,pcVar14,0x41);
        }
        else {
          iVar11 = RGE_Base_Game::campaignGame((RGE_Base_Game *)this);
          if ((iVar11 == 0) && (iVar11 = computerName(this,iVar17), iVar11 != 0)) {
            iVar11 = this->_padding_;
            uVar22 = 0x41;
            pcVar9 = pcVar14;
            iVar17 = computerName(this,iVar17);
            (**(code **)(iVar11 + 0x20))(iVar17 + 0x1130,pcVar9,uVar22);
          }
          else {
            iVar11 = this->_padding_;
            uVar22 = 0x41;
            pcVar10 = pcVar14;
            iVar17 = randomComputerName(this,(int)pcVar9[9]);
            (**(code **)(iVar11 + 0x20))(iVar17 + 0x1130,pcVar10,uVar22);
          }
        }
      }
      TCommunications_Handler::SetPlayerName
                ((TCommunications_Handler *)this->_padding_,scenario_player,pcVar14);
    }
    else {
      uVar22 = 0x40;
      pcVar9 = TCommunications_Handler::GetPlayerName
                         ((TCommunications_Handler *)this->_padding_,scenario_player);
      strncpy(pcVar14,pcVar9,uVar22);
    }
    pcVar14 = pcVar14 + 0x41;
    *(int *)position_used[0] = iVar7;
    position_used[0] = position_used[0] + 4;
    *(short *)humanity = (short)iVar18;
    player_info.scenario._0_2_ = (short)player_info.scenario + 1;
    humanity = humanity + 2;
    iVar11 = iVar15;
  } while (iVar15 < 8);
  if (player_index != 0) {
    (**(code **)(*(int *)player_index + 4))(1);
  }
  if ((short)player_info.scenario != 0) {
    if (this->_padding_ != 0) {
      *(undefined1 *)(this->_padding_ + 1) = 1;
    }
    iVar11 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)this);
    if (iVar11 == 0) {
      iVar11 = 1;
    }
    else {
      iVar11 = TCommunications_Handler::WhoAmI((TCommunications_Handler *)this->_padding_);
    }
    iVar11 = RGE_Base_Game::playerID((RGE_Base_Game *)this,iVar11);
    uVar6 = (**(code **)(*(int *)this->_padding_ + 0xd0))(player_info.name[0] + 4,iVar11);
    uVar6 = uVar6 & 0xff;
    if ((uVar6 != 0) && ((short)((int *)this->_padding_)[0xf] < 2)) {
      uVar6 = 0;
      (**(code **)(*(int *)this->_padding_ + 0xb8))();
    }
    if (this->_padding_ != 0) {
      *(undefined1 *)(this->_padding_ + 1) = 0;
    }
    iVar11 = 0;
    if (0 < *(short *)(this->_padding_ + 0x3c)) {
      do {
        RGE_Base_Game::reset_countdown_timer((RGE_Base_Game *)this,iVar11);
        iVar11 = iVar11 + 1;
      } while (iVar11 < *(short *)(this->_padding_ + 0x3c));
    }
    RGE_Game_World::update_mutual_allies((RGE_Game_World *)this->_padding_);
    RGE_Base_Game::set_map_visible((RGE_Base_Game *)this,'\0');
    iVar11 = RGE_Base_Game::fullVisibility((RGE_Base_Game *)this);
    if (iVar11 != 0) {
      iVar11 = this->_padding_;
      iVar15 = 1;
      if (1 < *(short *)(iVar11 + 0x3c)) {
        do {
          iVar11 = RGE_Player::computerPlayer
                             (*(RGE_Player **)(*(int *)(iVar11 + 0x40) + iVar15 * 4));
          if (iVar11 == 0) {
            RGE_Visible_Map::explore_all
                      (*(RGE_Visible_Map **)
                        (*(int *)(*(int *)(this->_padding_ + 0x40) + iVar15 * 4) + 0x38));
          }
          iVar11 = this->_padding_;
          iVar15 = iVar15 + 1;
        } while (iVar15 < *(short *)(iVar11 + 0x3c));
      }
    }
    iVar11 = RGE_Base_Game::fogOfWar((RGE_Base_Game *)this);
    RGE_Base_Game::set_map_fog((RGE_Base_Game *)this,(uchar)iVar11);
    iVar11 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)this);
    if (iVar11 == 0) {
      uVar2 = RGE_Base_Game::pathFinding((RGE_Base_Game *)this);
    }
    else {
      uVar2 = RGE_Base_Game::mpPathFinding((RGE_Base_Game *)this);
    }
    if (uVar2 == '\x01') {
      numberPathingIterations = 5000;
    }
    else if (uVar2 == '\x02') {
      numberPathingIterations = 0x1d4c;
    }
    else {
                    /* language.dll match for 0x9c4: "This is not enabled in the trial version." */
      numberPathingIterations = 0x9c4;
    }
    uVar13 = 1;
    piVar16 = this->save_humanity;
    do {
      piVar16 = piVar16 + 1;
      iVar11 = TCommunications_Handler::GetPlayerHumanity
                         ((TCommunications_Handler *)this->_padding_,uVar13);
      *piVar16 = iVar11;
      uVar13 = uVar13 + 1;
    } while ((int)uVar13 < 9);
    return uVar6;
  }
  return 0;
}

// --------------------------------------------------

// Function: create_game_screen
// Address: 00527830
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Game_Settings_Screen: "Game Settings Screen"
// [HELPER] s_Game_Setup_Screen: "Game Setup Screen"
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_MP_Startup_Screen: "MP Startup Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Multiplayer_Wait_Screen: "Multiplayer Wait Screen"
// [HELPER] s_Select_Scenario_Screen: "Select Scenario Screen"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
// [HELPER] s_Status_Screen: "Status Screen"
/* public: int __thiscall TRIBE_Game::create_game_screen(void) */

int __thiscall TRIBE_Game::create_game_screen(TRIBE_Game *this)
{
  int iVar1;
  TRIBE_Screen_Game *this_00;
  TRIBE_Screen_Game *pTVar2;
  int iVar3;
  TRIBE_Screen_Wait *this_01;
  TRIBE_Screen_Wait *this_02;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005617f6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Base_Game::disable_input((RGE_Base_Game *)this);
  iVar1 = this->_padding_;
  uVar5 = 0;
  uVar4 = 0;
  (**(code **)(iVar1 + 0x10))(0,0);
  this_00 = (TRIBE_Screen_Game *)operator_new(0x7c4);
  uStack_c = 0;
  if (this_00 == (TRIBE_Screen_Game *)0x0) {
    pTVar2 = (TRIBE_Screen_Game *)0x0;
  }
  else {
    pTVar2 = (TRIBE_Screen_Game *)TRIBE_Screen_Game::TRIBE_Screen_Game(this_00);
  }
  uStack_c = 0xffffffff;
  this->game_screen = pTVar2;
  if (pTVar2 != (TRIBE_Screen_Game *)0x0) {
    if (*(int *)&pTVar2->field_0xd8 == 0) {
      iVar3 = TCommunications_Handler::MultiplayerGameStart
                        ((TCommunications_Handler *)this->_padding_);
      if (iVar3 != 0) {
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
LAB_0052796f:
        TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
        TPanelSystem::destroyPanel(&panel_system,s_Game_Setup_Screen);
        TPanelSystem::destroyPanel(&panel_system,s_Select_Scenario_Screen);
        TPanelSystem::destroyPanel(&panel_system,&s_Game_Settings_Screen);
        TPanelSystem::destroyPanel(&panel_system,s_Load_Saved_Game_Screen);
        TPanelSystem::destroyPanel(&panel_system,s_MP_Setup_Screen);
        TPanelSystem::destroyPanel(&panel_system,s_Join_Screen);
        TPanelSystem::destroyPanel(&panel_system,s_MP_Startup_Screen);
        TPanelSystem::destroyPanel(&panel_system,s_Main_Menu);
        TPanelSystem::destroyPanel(&panel_system,s_Campaign_Selection_Screen);
        if (this->_padding_ != 3) {
          let_game_begin(this);
        }
        *unaff_FS_OFFSET = unaff_ESI;
        return 1;
      }
      this_01 = (TRIBE_Screen_Wait *)operator_new(0x4d8);
      uStack_c = 1;
      if (this_01 == (TRIBE_Screen_Wait *)0x0) {
        this_02 = (TRIBE_Screen_Wait *)0x0;
      }
      else {
        this_02 = (TRIBE_Screen_Wait *)TRIBE_Screen_Wait::TRIBE_Screen_Wait(this_01);
      }
      uStack_c = 0xffffffff;
      if (this_02 != (TRIBE_Screen_Wait *)0x0) {
                    /* language.dll match for 0x454: "Waiting for other players..." */
        TRIBE_Screen_Wait::set_text(this_02,0x454);
        TPanelSystem::setCurrentPanel(&panel_system,s_Multiplayer_Wait_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
        (**(code **)(iVar1 + 0xc))(3);
        goto LAB_0052796f;
      }
      if (this->game_screen != (TRIBE_Screen_Game *)0x0) {
        (*(code *)**(undefined4 **)this->game_screen)(1,uVar4,uVar5,this_01);
      }
      this->game_screen = (TRIBE_Screen_Game *)0x0;
      (**(code **)(*(int *)this->_padding_ + 0xb8))();
      goto LAB_00527a4f;
    }
    if (pTVar2 != (TRIBE_Screen_Game *)0x0) {
      (*(code *)**(undefined4 **)pTVar2)(1,uVar4,uVar5,this_00);
      this->game_screen = (TRIBE_Screen_Game *)0x0;
    }
  }
  (**(code **)(*(int *)this->_padding_ + 0xb8))();
LAB_00527a4f:
  close_status_message(this);
  RGE_Base_Game::enable_input((RGE_Base_Game *)this);
  *unaff_FS_OFFSET = unaff_ESI;
  return 0;
}

// --------------------------------------------------

// Function: processCheatCode
// Address: 00527a70
// [HELPER] s_BIG_MOMMA: "BIG MOMMA"
// [HELPER] s_CONVERT_THIS_: "CONVERT THIS!"
// [HELPER] s_GRANTLINKSPENCE: "GRANTLINKSPENCE"
// [HELPER] s_KING_ARTHUR: "KING ARTHUR"
// [HELPER] s_MINIWINSETT: "MINIWINSETT"
// [HELPER] s_STORMBILLY: "STORMBILLY"
// [HELPER] s__: "}"
// [HELPER] s___s__d_: "%*s %d "
// [HELPER] s___s__d__s__d_: "%*s %d %s %d "
// [HELPER] s__s_: "%s\n"
// [HELPER] s_w: "w"
/* WARNING: Variable defined which should be unmapped: target */
/* public: virtual int __thiscall TRIBE_Game::processCheatCode(int,char *) */

int __thiscall TRIBE_Game::processCheatCode(TRIBE_Game *this,int param_1,char *param_2)
{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  RGE_Player *pRVar5;
  RGE_Static_Object *pRVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  short sVar14;
  int target;
  int commander;
  char encstr [512];
  char str [256];
  char tempStr1 [256];
  char playName [256];
  
  if (((param_2 == (char *)0x0) || (param_1 < 0)) || (*(short *)(this->_padding_ + 0x3c) <= param_1)
     ) {
    return 0;
  }
  uVar7 = 0xffffffff;
  pcVar12 = str;
  pcVar9 = param_2;
  do {
    pcVar11 = pcVar9;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar11 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar11;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  pcVar9 = pcVar11 + -uVar7;
  for (uVar8 = uVar7 >> 2; pcVar12 = pcVar12 + 4, uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar12 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar12 = pcVar12 + 1;
  }
  __mbsupr(str + 4);
  encrypt_codes(str + 4,encstr + 4,0x200);
  iVar3 = RGE_Base_Game::allowCheatCodes((RGE_Base_Game *)this);
  if (iVar3 == 0) {
    return 0;
  }
  pbVar10 = &s______cAm____jdW;
  pbVar4 = (byte *)(encstr + 4);
  do {
    bVar2 = *pbVar4;
    bVar13 = bVar2 < *pbVar10;
    if (bVar2 != *pbVar10) {
LAB_00527b38:
      iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
      goto LAB_00527b3d;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar4[1];
    bVar13 = bVar2 < pbVar10[1];
    if (bVar2 != pbVar10[1]) goto LAB_00527b38;
    pbVar4 = pbVar4 + 2;
    pbVar10 = pbVar10 + 2;
  } while (bVar2 != 0);
  iVar3 = 0;
LAB_00527b3d:
  if ((iVar3 == 0) && (iVar3 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)this), iVar3 != 0))
{
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
    sVar14 = 0x66;
  }
  else {
    iVar3 = strstr(str + 4,s_STORMBILLY);
    if (iVar3 == 0) {
      iVar3 = strstr(str + 4,s_CONVERT_THIS_);
      if (iVar3 == 0) {
        iVar3 = strstr(str + 4,s_BIG_MOMMA);
        if (iVar3 == 0) {
          iVar3 = strstr(str + 4,s_MINIWINSETT);
          if (iVar3 == 0) {
            iVar3 = strstr(str + 4,s_GRANTLINKSPENCE);
            if (iVar3 == 0) {
              iVar3 = strstr(str + 4,s_KING_ARTHUR);
              if (iVar3 == 0) {
                pbVar10 = &s_w>________dW__chxdW;
                pbVar4 = (byte *)(encstr + 4);
                do {
                  bVar2 = *pbVar4;
                  bVar13 = bVar2 < *pbVar10;
                  if (bVar2 != *pbVar10) {
LAB_00527c40:
                    iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                    goto LAB_00527c45;
                  }
                  if (bVar2 == 0) break;
                  bVar2 = pbVar4[1];
                  bVar13 = bVar2 < pbVar10[1];
                  if (bVar2 != pbVar10[1]) goto LAB_00527c40;
                  pbVar4 = pbVar4 + 2;
                  pbVar10 = pbVar10 + 2;
                } while (bVar2 != 0);
                iVar3 = 0;
LAB_00527c45:
                if (iVar3 == 0) {
                  sVar14 = 0;
                }
                else {
                  pbVar10 = &s_Am__c3C2_________w>Am__;
                  pbVar4 = (byte *)(encstr + 4);
                  do {
                    bVar2 = *pbVar4;
                    bVar13 = bVar2 < *pbVar10;
                    if (bVar2 != *pbVar10) {
LAB_00527c7c:
                      iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                      goto LAB_00527c81;
                    }
                    if (bVar2 == 0) break;
                    bVar2 = pbVar4[1];
                    bVar13 = bVar2 < pbVar10[1];
                    if (bVar2 != pbVar10[1]) goto LAB_00527c7c;
                    pbVar4 = pbVar4 + 2;
                    pbVar10 = pbVar10 + 2;
                  } while (bVar2 != 0);
                  iVar3 = 0;
LAB_00527c81:
                  if (iVar3 == 0) {
                    sVar14 = 1;
                  }
                  else {
                    pbVar10 = &s___hx3CcW___Am_dW_L_c____Am;
                    pbVar4 = (byte *)(encstr + 4);
                    do {
                      bVar2 = *pbVar4;
                      bVar13 = bVar2 < *pbVar10;
                      if (bVar2 != *pbVar10) {
LAB_00527cb9:
                        iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                        goto LAB_00527cbe;
                      }
                      if (bVar2 == 0) break;
                      bVar2 = pbVar4[1];
                      bVar13 = bVar2 < pbVar10[1];
                      if (bVar2 != pbVar10[1]) goto LAB_00527cb9;
                      pbVar4 = pbVar4 + 2;
                      pbVar10 = pbVar10 + 2;
                    } while (bVar2 != 0);
                    iVar3 = 0;
LAB_00527cbe:
                    if (iVar3 == 0) {
                      sVar14 = 2;
                    }
                    else {
                      pbVar10 = &s____L1Z___Am______hx;
                      pbVar4 = (byte *)(encstr + 4);
                      do {
                        bVar2 = *pbVar4;
                        bVar13 = bVar2 < *pbVar10;
                        if (bVar2 != *pbVar10) {
LAB_00527cf6:
                          iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                          goto LAB_00527cfb;
                        }
                        if (bVar2 == 0) break;
                        bVar2 = pbVar4[1];
                        bVar13 = bVar2 < pbVar10[1];
                        if (bVar2 != pbVar10[1]) goto LAB_00527cf6;
                        pbVar4 = pbVar4 + 2;
                        pbVar10 = pbVar10 + 2;
                      } while (bVar2 != 0);
                      iVar3 = 0;
LAB_00527cfb:
                      if (iVar3 == 0) {
                        sVar14 = 3;
                      }
                      else {
                        pbVar10 = &s_Jm_____LdW1Z__>_j__3C___chxdW;
                        pbVar4 = (byte *)(encstr + 4);
                        do {
                          bVar2 = *pbVar4;
                          bVar13 = bVar2 < *pbVar10;
                          if (bVar2 != *pbVar10) {
LAB_00527d33:
                            iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                            goto LAB_00527d38;
                          }
                          if (bVar2 == 0) break;
                          bVar2 = pbVar4[1];
                          bVar13 = bVar2 < pbVar10[1];
                          if (bVar2 != pbVar10[1]) goto LAB_00527d33;
                          pbVar4 = pbVar4 + 2;
                          pbVar10 = pbVar10 + 2;
                        } while (bVar2 != 0);
                        iVar3 = 0;
LAB_00527d38:
                        if (iVar3 == 0) {
                          sVar14 = 4;
                        }
                        else {
                          pbVar10 = &s__jw>1__L_>Jm___LdW___c_____L__Am;
                          pbVar4 = (byte *)(encstr + 4);
                          do {
                            bVar2 = *pbVar4;
                            bVar13 = bVar2 < *pbVar10;
                            if (bVar2 != *pbVar10) {
LAB_00527d70:
                              iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                              goto LAB_00527d75;
                            }
                            if (bVar2 == 0) break;
                            bVar2 = pbVar4[1];
                            bVar13 = bVar2 < pbVar10[1];
                            if (bVar2 != pbVar10[1]) goto LAB_00527d70;
                            pbVar4 = pbVar4 + 2;
                            pbVar10 = pbVar10 + 2;
                          } while (bVar2 != 0);
                          iVar3 = 0;
LAB_00527d75:
                          if (iVar3 == 0) {
                            sVar14 = 7;
                          }
                          else {
                            pbVar10 = &s_________________;
                            pbVar4 = (byte *)(encstr + 4);
                            do {
                              bVar2 = *pbVar4;
                              bVar13 = bVar2 < *pbVar10;
                              if (bVar2 != *pbVar10) {
LAB_00527dad:
                                iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                goto LAB_00527db2;
                              }
                              if (bVar2 == 0) break;
                              bVar2 = pbVar4[1];
                              bVar13 = bVar2 < pbVar10[1];
                              if (bVar2 != pbVar10[1]) goto LAB_00527dad;
                              pbVar4 = pbVar4 + 2;
                              pbVar10 = pbVar10 + 2;
                            } while (bVar2 != 0);
                            iVar3 = 0;
LAB_00527db2:
                            if (iVar3 == 0) {
                              sVar14 = 8;
                            }
                            else {
                              pbVar10 = &s__>hx__cW___hx_LdW;
                              pbVar4 = (byte *)(encstr + 4);
                              do {
                                bVar2 = *pbVar4;
                                bVar13 = bVar2 < *pbVar10;
                                if (bVar2 != *pbVar10) {
LAB_00527dea:
                                  iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                  goto LAB_00527def;
                                }
                                if (bVar2 == 0) break;
                                bVar2 = pbVar4[1];
                                bVar13 = bVar2 < pbVar10[1];
                                if (bVar2 != pbVar10[1]) goto LAB_00527dea;
                                pbVar4 = pbVar4 + 2;
                                pbVar10 = pbVar10 + 2;
                              } while (bVar2 != 0);
                              iVar3 = 0;
LAB_00527def:
                              if (iVar3 == 0) {
                                sVar14 = 10;
                              }
                              else {
                                pbVar10 = &s_____hx3CcW____L_>Am__;
                                pbVar4 = (byte *)(encstr + 4);
                                do {
                                  bVar2 = *pbVar4;
                                  bVar13 = bVar2 < *pbVar10;
                                  if (bVar2 != *pbVar10) {
LAB_00527e27:
                                    iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                    goto LAB_00527e2c;
                                  }
                                  if (bVar2 == 0) break;
                                  bVar2 = pbVar4[1];
                                  bVar13 = bVar2 < pbVar10[1];
                                  if (bVar2 != pbVar10[1]) goto LAB_00527e27;
                                  pbVar4 = pbVar4 + 2;
                                  pbVar10 = pbVar10 + 2;
                                } while (bVar2 != 0);
                                iVar3 = 0;
LAB_00527e2c:
                                if (iVar3 == 0) {
                                  sVar14 = 0xb;
                                }
                                else {
                                  pbVar10 = &s__cAm_>_j1_hx;
                                  pbVar4 = (byte *)(encstr + 4);
                                  do {
                                    bVar2 = *pbVar4;
                                    bVar13 = bVar2 < *pbVar10;
                                    if (bVar2 != *pbVar10) {
LAB_00527e64:
                                      iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                      goto LAB_00527e69;
                                    }
                                    if (bVar2 == 0) break;
                                    bVar2 = pbVar4[1];
                                    bVar13 = bVar2 < pbVar10[1];
                                    if (bVar2 != pbVar10[1]) goto LAB_00527e64;
                                    pbVar4 = pbVar4 + 2;
                                    pbVar10 = pbVar10 + 2;
                                  } while (bVar2 != 0);
                                  iVar3 = 0;
LAB_00527e69:
                                  if (iVar3 == 0) {
                                    sVar14 = 0xc;
                                  }
                                  else {
                                    pbVar10 = &s__L3C___c;
                                    pbVar4 = (byte *)(encstr + 4);
                                    do {
                                      bVar2 = *pbVar4;
                                      bVar13 = bVar2 < *pbVar10;
                                      if (bVar2 != *pbVar10) {
LAB_00527ea1:
                                        iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                        goto LAB_00527ea6;
                                      }
                                      if (bVar2 == 0) break;
                                      bVar2 = pbVar4[1];
                                      bVar13 = bVar2 < pbVar10[1];
                                      if (bVar2 != pbVar10[1]) goto LAB_00527ea1;
                                      pbVar4 = pbVar4 + 2;
                                      pbVar10 = pbVar10 + 2;
                                    } while (bVar2 != 0);
                                    iVar3 = 0;
LAB_00527ea6:
                                    if (iVar3 == 0) {
                                      sVar14 = 0xd;
                                    }
                                    else {
                                      iVar3 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)this)
                                      ;
                                      if (iVar3 != 0) {
                                        pbVar10 = &s__>_LAm_>_LAm_>_LAm;
                                        pbVar4 = (byte *)(encstr + 4);
                                        do {
                                          bVar2 = *pbVar4;
                                          bVar13 = bVar2 < *pbVar10;
                                          if (bVar2 != *pbVar10) {
LAB_00527eed:
                                            iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                            goto LAB_00527ef2;
                                          }
                                          if (bVar2 == 0) break;
                                          bVar2 = pbVar4[1];
                                          bVar13 = bVar2 < pbVar10[1];
                                          if (bVar2 != pbVar10[1]) goto LAB_00527eed;
                                          pbVar4 = pbVar4 + 2;
                                          pbVar10 = pbVar10 + 2;
                                        } while (bVar2 != 0);
                                        iVar3 = 0;
LAB_00527ef2:
                                        if (iVar3 == 0) {
                                          sVar14 = 100;
                                          goto LAB_0052848c;
                                        }
                                        pbVar10 = &s_cW_L____1;
                                        pbVar4 = (byte *)(encstr + 4);
                                        do {
                                          bVar2 = *pbVar4;
                                          bVar13 = bVar2 < *pbVar10;
                                          if (bVar2 != *pbVar10) {
LAB_00527f2a:
                                            iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                            goto LAB_00527f2f;
                                          }
                                          if (bVar2 == 0) break;
                                          bVar2 = pbVar4[1];
                                          bVar13 = bVar2 < pbVar10[1];
                                          if (bVar2 != pbVar10[1]) goto LAB_00527f2a;
                                          pbVar4 = pbVar4 + 2;
                                          pbVar10 = pbVar10 + 2;
                                        } while (bVar2 != 0);
                                        iVar3 = 0;
LAB_00527f2f:
                                        if (iVar3 == 0) {
                                          sVar14 = 0xc9;
                                          goto LAB_0052848c;
                                        }
                                        pbVar10 = &s_cW_L____2;
                                        pbVar4 = (byte *)(encstr + 4);
                                        do {
                                          bVar2 = *pbVar4;
                                          bVar13 = bVar2 < *pbVar10;
                                          if (bVar2 != *pbVar10) {
LAB_00527f6a:
                                            iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                            goto LAB_00527f6f;
                                          }
                                          if (bVar2 == 0) break;
                                          bVar2 = pbVar4[1];
                                          bVar13 = bVar2 < pbVar10[1];
                                          if (bVar2 != pbVar10[1]) goto LAB_00527f6a;
                                          pbVar4 = pbVar4 + 2;
                                          pbVar10 = pbVar10 + 2;
                                        } while (bVar2 != 0);
                                        iVar3 = 0;
LAB_00527f6f:
                                        if (iVar3 == 0) {
                                          sVar14 = 0xca;
                                          goto LAB_0052848c;
                                        }
                                        pbVar10 = &s_cW_L____3;
                                        pbVar4 = (byte *)(encstr + 4);
                                        do {
                                          bVar2 = *pbVar4;
                                          bVar13 = bVar2 < *pbVar10;
                                          if (bVar2 != *pbVar10) {
LAB_00527faa:
                                            iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                            goto LAB_00527faf;
                                          }
                                          if (bVar2 == 0) break;
                                          bVar2 = pbVar4[1];
                                          bVar13 = bVar2 < pbVar10[1];
                                          if (bVar2 != pbVar10[1]) goto LAB_00527faa;
                                          pbVar4 = pbVar4 + 2;
                                          pbVar10 = pbVar10 + 2;
                                        } while (bVar2 != 0);
                                        iVar3 = 0;
LAB_00527faf:
                                        if (iVar3 == 0) {
                                          sVar14 = 0xcb;
                                          goto LAB_0052848c;
                                        }
                                        pbVar10 = &s_cW_L____4;
                                        pbVar4 = (byte *)(encstr + 4);
                                        do {
                                          bVar2 = *pbVar4;
                                          bVar13 = bVar2 < *pbVar10;
                                          if (bVar2 != *pbVar10) {
LAB_00527fea:
                                            iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                            goto LAB_00527fef;
                                          }
                                          if (bVar2 == 0) break;
                                          bVar2 = pbVar4[1];
                                          bVar13 = bVar2 < pbVar10[1];
                                          if (bVar2 != pbVar10[1]) goto LAB_00527fea;
                                          pbVar4 = pbVar4 + 2;
                                          pbVar10 = pbVar10 + 2;
                                        } while (bVar2 != 0);
                                        iVar3 = 0;
LAB_00527fef:
                                        if (iVar3 == 0) {
                                          sVar14 = 0xcc;
                                          goto LAB_0052848c;
                                        }
                                        pbVar10 = &s_cW_L____5;
                                        pbVar4 = (byte *)(encstr + 4);
                                        do {
                                          bVar2 = *pbVar4;
                                          bVar13 = bVar2 < *pbVar10;
                                          if (bVar2 != *pbVar10) {
LAB_0052802a:
                                            iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                            goto LAB_0052802f;
                                          }
                                          if (bVar2 == 0) break;
                                          bVar2 = pbVar4[1];
                                          bVar13 = bVar2 < pbVar10[1];
                                          if (bVar2 != pbVar10[1]) goto LAB_0052802a;
                                          pbVar4 = pbVar4 + 2;
                                          pbVar10 = pbVar10 + 2;
                                        } while (bVar2 != 0);
                                        iVar3 = 0;
LAB_0052802f:
                                        if (iVar3 == 0) {
                                          sVar14 = 0xcd;
                                          goto LAB_0052848c;
                                        }
                                        pbVar10 = &s_cW_L____6;
                                        pbVar4 = (byte *)(encstr + 4);
                                        do {
                                          bVar2 = *pbVar4;
                                          bVar13 = bVar2 < *pbVar10;
                                          if (bVar2 != *pbVar10) {
LAB_0052806a:
                                            iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                            goto LAB_0052806f;
                                          }
                                          if (bVar2 == 0) break;
                                          bVar2 = pbVar4[1];
                                          bVar13 = bVar2 < pbVar10[1];
                                          if (bVar2 != pbVar10[1]) goto LAB_0052806a;
                                          pbVar4 = pbVar4 + 2;
                                          pbVar10 = pbVar10 + 2;
                                        } while (bVar2 != 0);
                                        iVar3 = 0;
LAB_0052806f:
                                        if (iVar3 == 0) {
                                          sVar14 = 0xce;
                                          goto LAB_0052848c;
                                        }
                                        pbVar10 = &s_cW_L____7;
                                        pbVar4 = (byte *)(encstr + 4);
                                        do {
                                          bVar2 = *pbVar4;
                                          bVar13 = bVar2 < *pbVar10;
                                          if (bVar2 != *pbVar10) {
LAB_005280aa:
                                            iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                            goto LAB_005280af;
                                          }
                                          if (bVar2 == 0) break;
                                          bVar2 = pbVar4[1];
                                          bVar13 = bVar2 < pbVar10[1];
                                          if (bVar2 != pbVar10[1]) goto LAB_005280aa;
                                          pbVar4 = pbVar4 + 2;
                                          pbVar10 = pbVar10 + 2;
                                        } while (bVar2 != 0);
                                        iVar3 = 0;
LAB_005280af:
                                        if (iVar3 == 0) {
                                          sVar14 = 0xcf;
                                          goto LAB_0052848c;
                                        }
                                        pbVar10 = &s_cW_L____9;
                                        pbVar4 = (byte *)(encstr + 4);
                                        do {
                                          bVar2 = *pbVar4;
                                          bVar13 = bVar2 < *pbVar10;
                                          if (bVar2 != *pbVar10) {
LAB_005280ea:
                                            iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                            goto LAB_005280ef;
                                          }
                                          if (bVar2 == 0) break;
                                          bVar2 = pbVar4[1];
                                          bVar13 = bVar2 < pbVar10[1];
                                          if (bVar2 != pbVar10[1]) goto LAB_005280ea;
                                          pbVar4 = pbVar4 + 2;
                                          pbVar10 = pbVar10 + 2;
                                        } while (bVar2 != 0);
                                        iVar3 = 0;
LAB_005280ef:
                                        if (iVar3 == 0) {
                                          sVar14 = 0xd0;
                                          goto LAB_0052848c;
                                        }
                                      }
                                      pbVar10 = &s___hx___L_cWhx___L;
                                      pbVar4 = (byte *)(encstr + 4);
                                      do {
                                        bVar2 = *pbVar4;
                                        bVar13 = bVar2 < *pbVar10;
                                        if (bVar2 != *pbVar10) {
LAB_0052812a:
                                          iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                          goto LAB_0052812f;
                                        }
                                        if (bVar2 == 0) break;
                                        bVar2 = pbVar4[1];
                                        bVar13 = bVar2 < pbVar10[1];
                                        if (bVar2 != pbVar10[1]) goto LAB_0052812a;
                                        pbVar4 = pbVar4 + 2;
                                        pbVar10 = pbVar10 + 2;
                                      } while (bVar2 != 0);
                                      iVar3 = 0;
LAB_0052812f:
                                      if (iVar3 == 0) {
                                        sVar14 = 0x65;
                                      }
                                      else {
                                        pbVar10 = &s___Am1__L1ZdW;
                                        pbVar4 = (byte *)(encstr + 4);
                                        do {
                                          bVar2 = *pbVar4;
                                          bVar13 = bVar2 < *pbVar10;
                                          if (bVar2 != *pbVar10) {
LAB_00528167:
                                            iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                            goto LAB_0052816c;
                                          }
                                          if (bVar2 == 0) break;
                                          bVar2 = pbVar4[1];
                                          bVar13 = bVar2 < pbVar10[1];
                                          if (bVar2 != pbVar10[1]) goto LAB_00528167;
                                          pbVar4 = pbVar4 + 2;
                                          pbVar10 = pbVar10 + 2;
                                        } while (bVar2 != 0);
                                        iVar3 = 0;
LAB_0052816c:
                                        if (iVar3 == 0) {
                                          sVar14 = 0x67;
                                        }
                                        else {
                                          pbVar10 = &s_1Zhx_Lhx;
                                          pbVar4 = (byte *)(encstr + 4);
                                          do {
                                            bVar2 = *pbVar4;
                                            bVar13 = bVar2 < *pbVar10;
                                            if (bVar2 != *pbVar10) {
LAB_005281a4:
                                              iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                              goto LAB_005281a9;
                                            }
                                            if (bVar2 == 0) break;
                                            bVar2 = pbVar4[1];
                                            bVar13 = bVar2 < pbVar10[1];
                                            if (bVar2 != pbVar10[1]) goto LAB_005281a4;
                                            pbVar4 = pbVar4 + 2;
                                            pbVar10 = pbVar10 + 2;
                                          } while (bVar2 != 0);
                                          iVar3 = 0;
LAB_005281a9:
                                          if (iVar3 == 0) {
                                            pRVar5 = RGE_Base_Game::get_player
                                                               ((RGE_Base_Game *)this);
                                            RGE_Player::unselect_object(pRVar5);
                                            if ((this->_padding_ == 6) && (this->_padding_ == 1)) {
                                              (**(code **)(this->_padding_ + 0x10))(0,0);
                                            }
                                            (**(code **)(this->_padding_ + 0x14))(0);
                                            return 1;
                                          }
                                          pbVar10 = &s_w>Amw>w>Am____dW_L_w>_LS_S_hx;
                                          pbVar4 = (byte *)(encstr + 4);
                                          do {
                                            bVar2 = *pbVar4;
                                            bVar13 = bVar2 < *pbVar10;
                                            if (bVar2 != *pbVar10) {
LAB_00528222:
                                              iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                              goto LAB_00528227;
                                            }
                                            if (bVar2 == 0) break;
                                            bVar2 = pbVar4[1];
                                            bVar13 = bVar2 < pbVar10[1];
                                            if (bVar2 != pbVar10[1]) goto LAB_00528222;
                                            pbVar4 = pbVar4 + 2;
                                            pbVar10 = pbVar10 + 2;
                                          } while (bVar2 != 0);
                                          iVar3 = 0;
LAB_00528227:
                                          if (iVar3 == 0) {
                                            pRVar5 = RGE_Base_Game::get_player
                                                               ((RGE_Base_Game *)this);
                                            (**(code **)(pRVar5->_padding_ + 0xb4))(0,0x447a0000);
                                            return 1;
                                          }
                                          pbVar10 = &s_3C___LdWhx1ZAm;
                                          pbVar4 = (byte *)(encstr + 4);
                                          do {
                                            bVar2 = *pbVar4;
                                            bVar13 = bVar2 < *pbVar10;
                                            if (bVar2 != *pbVar10) {
LAB_00528282:
                                              iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                              goto LAB_00528287;
                                            }
                                            if (bVar2 == 0) break;
                                            bVar2 = pbVar4[1];
                                            bVar13 = bVar2 < pbVar10[1];
                                            if (bVar2 != pbVar10[1]) goto LAB_00528282;
                                            pbVar4 = pbVar4 + 2;
                                            pbVar10 = pbVar10 + 2;
                                          } while (bVar2 != 0);
                                          iVar3 = 0;
LAB_00528287:
                                          if (iVar3 == 0) {
                                            pRVar5 = RGE_Base_Game::get_player
                                                               ((RGE_Base_Game *)this);
                                            (**(code **)(pRVar5->_padding_ + 0xb4))(3,0x447a0000);
                                            return 1;
                                          }
                                          pbVar10 = &s_43_____>1_____3CcW;
                                          pbVar4 = (byte *)(encstr + 4);
                                          do {
                                            bVar2 = *pbVar4;
                                            bVar13 = bVar2 < *pbVar10;
                                            if (bVar2 != *pbVar10) {
LAB_005282e2:
                                              iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                              goto LAB_005282e7;
                                            }
                                            if (bVar2 == 0) break;
                                            bVar2 = pbVar4[1];
                                            bVar13 = bVar2 < pbVar10[1];
                                            if (bVar2 != pbVar10[1]) goto LAB_005282e2;
                                            pbVar4 = pbVar4 + 2;
                                            pbVar10 = pbVar10 + 2;
                                          } while (bVar2 != 0);
                                          iVar3 = 0;
LAB_005282e7:
                                          if (iVar3 == 0) {
                                            pRVar5 = RGE_Base_Game::get_player
                                                               ((RGE_Base_Game *)this);
                                            (**(code **)(pRVar5->_padding_ + 0xb4))(1,0x447a0000);
                                            return 1;
                                          }
                                          pbVar10 = &s_hx_jhx______;
                                          pbVar4 = (byte *)(encstr + 4);
                                          do {
                                            bVar2 = *pbVar4;
                                            bVar13 = bVar2 < *pbVar10;
                                            if (bVar2 != *pbVar10) {
LAB_00528342:
                                              iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                              goto LAB_00528347;
                                            }
                                            if (bVar2 == 0) break;
                                            bVar2 = pbVar4[1];
                                            bVar13 = bVar2 < pbVar10[1];
                                            if (bVar2 != pbVar10[1]) goto LAB_00528342;
                                            pbVar4 = pbVar4 + 2;
                                            pbVar10 = pbVar10 + 2;
                                          } while (bVar2 != 0);
                                          iVar3 = 0;
LAB_00528347:
                                          if (iVar3 == 0) {
                                            pRVar5 = RGE_Base_Game::get_player
                                                               ((RGE_Base_Game *)this);
                                            (**(code **)(pRVar5->_padding_ + 0xb4))(2,0x447a0000);
                                            return 1;
                                          }
                                          pbVar10 = &s_1___Am_____L_>1_;
                                          pbVar4 = (byte *)(encstr + 4);
                                          do {
                                            bVar2 = *pbVar4;
                                            bVar13 = bVar2 < *pbVar10;
                                            if (bVar2 != *pbVar10) {
LAB_005283a2:
                                              iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                              goto LAB_005283a7;
                                            }
                                            if (bVar2 == 0) break;
                                            bVar2 = pbVar4[1];
                                            bVar13 = bVar2 < pbVar10[1];
                                            if (bVar2 != pbVar10[1]) goto LAB_005283a2;
                                            pbVar4 = pbVar4 + 2;
                                            pbVar10 = pbVar10 + 2;
                                          } while (bVar2 != 0);
                                          iVar3 = 0;
LAB_005283a7:
                                          if (iVar3 == 0) {
                                            TRIBE_Command::command_quick_build
                                                      (*(TRIBE_Command **)(this->_padding_ + 0x58),
                                                       (ushort)(this->_padding_ == 0));
                                            return 1;
                                          }
                                          pbVar10 = &s____L1Z_>hx_>_>__;
                                          pbVar4 = (byte *)(encstr + 4);
                                          do {
                                            bVar2 = *pbVar4;
                                            bVar13 = bVar2 < *pbVar10;
                                            if (bVar2 != *pbVar10) {
LAB_00528404:
                                              iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                              goto LAB_00528409;
                                            }
                                            if (bVar2 == 0) break;
                                            bVar2 = pbVar4[1];
                                            bVar13 = bVar2 < pbVar10[1];
                                            if (bVar2 != pbVar10[1]) goto LAB_00528404;
                                            pbVar4 = pbVar4 + 2;
                                            pbVar10 = pbVar10 + 2;
                                          } while (bVar2 != 0);
                                          iVar3 = 0;
LAB_00528409:
                                          if (iVar3 == 0) {
                                            sVar14 = 0xdc;
                                          }
                                          else {
                                            pbVar10 = &s___Am_TAmhx____chxw>;
                                            pbVar4 = (byte *)(encstr + 4);
                                            do {
                                              bVar2 = *pbVar4;
                                              bVar13 = bVar2 < *pbVar10;
                                              if (bVar2 != *pbVar10) {
LAB_00528441:
                                                iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                                goto LAB_00528446;
                                              }
                                              if (bVar2 == 0) break;
                                              bVar2 = pbVar4[1];
                                              bVar13 = bVar2 < pbVar10[1];
                                              if (bVar2 != pbVar10[1]) goto LAB_00528441;
                                              pbVar4 = pbVar4 + 2;
                                              pbVar10 = pbVar10 + 2;
                                            } while (bVar2 != 0);
                                            iVar3 = 0;
LAB_00528446:
                                            if (iVar3 == 0) {
                                              sVar14 = 0xe6;
                                            }
                                            else {
                                              pbVar10 = &s_dW___Jm__1Z;
                                              pbVar4 = (byte *)(encstr + 4);
                                              do {
                                                bVar2 = *pbVar4;
                                                bVar13 = bVar2 < *pbVar10;
                                                if (bVar2 != *pbVar10) {
LAB_0052847e:
                                                  iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                                                  goto LAB_00528483;
                                                }
                                                if (bVar2 == 0) break;
                                                bVar2 = pbVar4[1];
                                                bVar13 = bVar2 < pbVar10[1];
                                                if (bVar2 != pbVar10[1]) goto LAB_0052847e;
                                                pbVar4 = pbVar4 + 2;
                                                pbVar10 = pbVar10 + 2;
                                              } while (bVar2 != 0);
                                              iVar3 = 0;
LAB_00528483:
                                              if (iVar3 != 0) {
                                                sscanf(str + 4,s__s_,tempStr1 + 4);
                                                pbVar10 = &s_SELECTOBJ;
                                                pbVar4 = (byte *)(tempStr1 + 4);
                                                do {
                                                  bVar2 = *pbVar4;
                                                  bVar13 = bVar2 < *pbVar10;
                                                  if (bVar2 != *pbVar10) {
LAB_005284f6:
                                                    iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0)
                                                    ;
                                                    goto LAB_005284fb;
                                                  }
                                                  if (bVar2 == 0) break;
                                                  bVar2 = pbVar4[1];
                                                  bVar13 = bVar2 < pbVar10[1];
                                                  if (bVar2 != pbVar10[1]) goto LAB_005284f6;
                                                  pbVar4 = pbVar4 + 2;
                                                  pbVar10 = pbVar10 + 2;
                                                } while (bVar2 != 0);
                                                iVar3 = 0;
LAB_005284fb:
                                                if (iVar3 == 0) {
                                                  sscanf(param_2,s___s__d_,&commander);
                                                  pRVar6 = RGE_Game_World::object
                                                                     ((RGE_Game_World *)
                                                                      this->_padding_,commander);
                                                  if (pRVar6 != (RGE_Static_Object *)0x0) {
                                                    pRVar6->selected = '\x01';
                                                    *(RGE_Static_Object **)
                                                     (*(int *)(*(int *)(this->_padding_ + 0x40) +
                                                              param_1 * 4) + 0x130) = pRVar6;
                                                  }
                                                }
                                                pbVar10 = &s_RUNPLAY;
                                                pbVar4 = (byte *)(tempStr1 + 4);
                                                do {
                                                  bVar2 = *pbVar4;
                                                  bVar13 = bVar2 < *pbVar10;
                                                  if (bVar2 != *pbVar10) {
LAB_00528573:
                                                    iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0)
                                                    ;
                                                    goto LAB_00528578;
                                                  }
                                                  if (bVar2 == 0) break;
                                                  bVar2 = pbVar4[1];
                                                  bVar13 = bVar2 < pbVar10[1];
                                                  if (bVar2 != pbVar10[1]) goto LAB_00528573;
                                                  pbVar4 = pbVar4 + 2;
                                                  pbVar10 = pbVar10 + 2;
                                                } while (bVar2 != 0);
                                                iVar3 = 0;
LAB_00528578:
                                                if (iVar3 == 0) {
                                                  sscanf(param_2,s___s__d__s__d_,encstr,playName + 4
                                                         ,&commander);
                                                  iVar3 = AIPlayBook::playNumber
                                                                    (*(AIPlayBook **)
                                                                      (this->_padding_ + 0xa0),
                                                                     playName + 4);
                                                  if (iVar3 != -1) {
                                                    (**(code **)(**(int **)(*(int *)(this->_padding_
                                                                                    + 0x40) +
                                                                           param_1 * 4) + 0x50))
                                                              (encstr._0_4_,commander,iVar3);
                                                    return 1;
                                                  }
                                                }
                                                else {
                                                  pbVar10 = &s_S_Am_j1_;
                                                  pbVar4 = (byte *)(encstr + 4);
                                                  do {
                                                    bVar2 = *pbVar4;
                                                    bVar13 = bVar2 < *pbVar10;
                                                    if (bVar2 != *pbVar10) {
LAB_00528624:
                                                      iVar3 = (1 - (uint)bVar13) -
                                                              (uint)(bVar13 != 0);
                                                      goto LAB_00528629;
                                                    }
                                                    if (bVar2 == 0) break;
                                                    bVar2 = pbVar4[1];
                                                    bVar13 = bVar2 < pbVar10[1];
                                                    if (bVar2 != pbVar10[1]) goto LAB_00528624;
                                                    pbVar4 = pbVar4 + 2;
                                                    pbVar10 = pbVar10 + 2;
                                                  } while (bVar2 != 0);
                                                  iVar3 = 0;
LAB_00528629:
                                                  if (iVar3 != 0) {
                                                    return 0;
                                                  }
                                                  (**(code **)(**(int **)(*(int *)(this->_padding_ +
                                                                                  0x40) +
                                                                         param_1 * 4) + 0x54))
                                                            (param_1,0,0,0,0);
                                                }
                                                return 1;
                                              }
                                              sVar14 = 0xe7;
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else {
                sVar14 = 0x13;
              }
            }
            else {
              sVar14 = 0x12;
            }
          }
          else {
            sVar14 = 0x11;
          }
        }
        else {
          sVar14 = 0x10;
        }
      }
      else {
        sVar14 = 0xf;
      }
    }
    else {
      sVar14 = 0xe;
    }
  }
LAB_0052848c:
  TRIBE_World::send_cheat((TRIBE_World *)this->_padding_,sVar14);
  return 1;
}

// --------------------------------------------------

// Function: let_game_begin
// Address: 00528670
// [HELPER] s_Bronze: "Bronze"
// [HELPER] s_DeathMatch: "DeathMatch"
// [HELPER] s_Default: "Default"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_High: "High"
// [HELPER] s_Iron: "Iron"
// [HELPER] s_Low: "Low"
// [HELPER] s_Medium: "Medium"
// [HELPER] s_Multiplayer: "Multiplayer"
// [HELPER] s_Score__d_: "Score(%d)"
// [HELPER] s_Standard: "Standard"
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s_Stone: "Stone"
// [HELPER] s_Time__d_: "Time(%d)"
// [HELPER] s_Tool: "Tool"
// [HELPER] s_Unknown: "Unknown"
// [HELPER] s_____fulltech__d__revealmap__d: "    fulltech=%d, revealmap=%d"
// [HELPER] s_____numplayers__d: "    numplayers=%d"
// [HELPER] s_____randomgame__d__randommap__d_: "    randomgame=%d, randommap=%d, mapsize=%s, maptype=%s"
// [HELPER] s_____resources__s__age__s__victor: "    resources=%s, age=%s, victory=%s, difficulty=%s"
// [HELPER] s___civs_: ", civs="
// [HELPER] s___players_: ", players="
// [HELPER] s___teams_: ", teams="
// [HELPER] s__d: "%d"
// [HELPER] s__d_: "%d "
// [HELPER] s_game_started: "game started"
/* WARNING: Variable defined which should be unmapped: int_str */
/* protected: void __thiscall TRIBE_Game::let_game_begin(void) */

void __thiscall TRIBE_Game::let_game_begin(TRIBE_Game *this)
{
  char cVar1;
  TMusic_System *this_00;
  uchar uVar2;
  MapType MVar3;
  MapSize MVar4;
  VictoryType VVar5;
  ResourceLevel RVar6;
  Age AVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  code *pcVar12;
  char *pcVar13;
  char *pcVar14;
  char **ppcVar15;
  char **ppcVar16;
  char *pcVar17;
  undefined4 uVar18;
  char *pcStack_858;
  undefined4 uStack_854;
  undefined4 uStack_850;
  char int_str [10];
  char map_type_str [20];
  char map_size_str [20];
  char age_str [256];
  char res_str [256];
  char vic_str [256];
  char str [1024];
  char diff_str [256];
  
  uStack_850 = 0x52868d;
  TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Multiplayer);
  uStack_850 = 0x5286b7;
  run_log(s_game_started,1);
  MVar3 = mapType(this);
  switch(MVar3) {
  case AllWater:
    pcVar12 = *(code **)(this->_padding_ + 0x20);
    uStack_850 = 0x296a;
    break;
  case MostlyWater:
    pcVar12 = *(code **)(this->_padding_ + 0x20);
    uStack_850 = 0x296b;
    break;
  case WaterAndLand:
    pcVar12 = *(code **)(this->_padding_ + 0x20);
    uStack_850 = 0x296c;
    break;
  case MostlyLand:
    pcVar12 = *(code **)(this->_padding_ + 0x20);
    uStack_850 = 0x296d;
    break;
  case AllLand:
    pcVar12 = *(code **)(this->_padding_ + 0x20);
    uStack_850 = 0x296e;
    break;
  case Continental:
    pcVar12 = *(code **)(this->_padding_ + 0x20);
    uStack_850 = 0x296f;
    break;
  case Lake:
    pcVar12 = *(code **)(this->_padding_ + 0x20);
                    /* language.dll match for 0x2970: "Mediterranean" */
    uStack_850 = 0x2970;
    break;
  default:
    pcVar12 = *(code **)(this->_padding_ + 0x20);
                    /* language.dll match for 0x2804: "Unknown" */
    uStack_850 = 0x2804;
  }
  uStack_854 = 0x528776;
  (*pcVar12)();
  uStack_854 = 0x52877d;
  MVar4 = mapSize(this);
  switch(MVar4) {
  case Tiny:
    uVar18 = 0x2973;
    break;
  case Small:
    uVar18 = 0x2974;
    break;
  case Medium:
    uVar18 = 0x2975;
    break;
  case Large:
    uVar18 = 0x2976;
    break;
  case Huge:
    uVar18 = 0x2977;
    break;
  case Humongous:
                    /* language.dll match for 0x2978: "Gigantic" */
    uVar18 = 0x2978;
    break;
  default:
                    /* language.dll match for 0x2804: "Unknown" */
    uVar18 = 0x2804;
  }
  pcStack_858 = map_type_str + 0xc;
  uStack_854 = 0x14;
  (*pcVar12)(uVar18);
  sprintf(vic_str + 0xec,s_____randomgame__d__randommap__d_,this->_padding_,this->_padding_,
          map_type_str,&stack0xfffff7c0);
  run_log(vic_str + 0xec,0);
  VVar5 = victoryType(this);
  switch(VVar5) {
  case VictoryDefault:
    pcVar13 = s_Default;
    break;
  default:
    pcVar13 = &s_Unknown;
    break;
  case VictoryTime:
    iVar8 = victoryAmount(this);
    sprintf(res_str + 0xec,s_Time__d_,iVar8);
    goto LAB_005288c4;
  case VictoryScore:
    iVar8 = victoryAmount(this);
    sprintf(res_str + 0xec,s_Score__d_,iVar8);
    goto LAB_005288c4;
  case VictoryStandard:
    pcVar13 = &s_Standard;
  }
  uVar10 = 0xffffffff;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = res_str + 0xec;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
LAB_005288c4:
  uVar2 = deathMatch(this);
  if (uVar2 == '\0') {
    RVar6 = resourceLevel(this);
    switch(RVar6) {
    case DefaultResources:
      pcVar13 = s_Default;
      break;
    case LowResource:
      pcVar13 = s_Low;
      break;
    case MediumResources:
      pcVar13 = s_Medium;
      break;
    case HighResources:
      pcVar13 = s_High;
      break;
    default:
      pcVar13 = &s_Unknown;
    }
  }
  else {
    pcVar13 = &s_DeathMatch;
  }
  uVar10 = 0xffffffff;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = age_str + 0xec;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  AVar7 = startingAge(this);
  switch(AVar7) {
  case DefaultAge:
    pcVar13 = s_Default;
    break;
  default:
    pcVar13 = &s_Unknown;
    break;
  case StoneAge:
    pcVar13 = s_Stone;
    break;
  case ToolAge:
    pcVar13 = s_Tool;
    break;
  case BronzeAge:
    pcVar13 = s_Bronze;
    break;
  case IronAge:
    pcVar13 = &s_Iron;
  }
  uVar10 = 0xffffffff;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = map_size_str;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar10 = 0xffffffff;
  pcVar13 = &s_Unknown;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = str + 0x3ec;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  pcVar13 = str + 0x3ec;
  iVar8 = RGE_Base_Game::difficulty((RGE_Base_Game *)this);
  (*pcVar12)(iVar8 + 0x2bd0,pcVar13);
  sprintf(vic_str + 0xe0,s_____resources__s__age__s__victor,age_str + 0xe0,map_type_str + 8,
          res_str + 0xe0,str + 0x3e0);
  run_log(vic_str + 0xe0,0);
  iVar8 = RGE_Base_Game::fullVisibility((RGE_Base_Game *)this);
  iVar9 = fullTechTree(this);
  sprintf(vic_str + 0xe0,s_____fulltech__d__revealmap__d,iVar9,iVar8);
  run_log(vic_str + 0xe0,0);
  sprintf(vic_str + 0xe0,s_____numplayers__d,*(short *)(this->_padding_ + 0x3c) + -1);
  uVar10 = 0xffffffff;
  pcVar13 = &s___players_;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  iVar8 = -1;
  pcVar13 = vic_str + 0xe0;
  do {
    pcVar14 = pcVar13;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar14 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar14;
  } while (cVar1 != '\0');
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = pcVar14 + -1;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  iVar8 = this->_padding_;
  iVar9 = 1;
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  if (1 < *(short *)(iVar8 + 0x3c)) {
    do {
      iVar8 = playerColor(this,iVar9 + -1);
      sprintf(&pcStack_858,&s__d,iVar8);
      uVar10 = 0xffffffff;
      ppcVar15 = &pcStack_858;
      do {
        ppcVar16 = ppcVar15;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        ppcVar16 = (char **)((int)ppcVar15 + 1);
        cVar1 = *(char *)ppcVar15;
        ppcVar15 = ppcVar16;
      } while (cVar1 != '\0');
      uVar10 = ~uVar10;
      iVar8 = -1;
      pcVar13 = vic_str + 0xe0;
      do {
        pcVar17 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar17 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar17;
      } while (cVar1 != '\0');
      pcVar13 = (char *)((int)ppcVar16 - uVar10);
      pcVar17 = pcVar17 + -1;
      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar17 = pcVar17 + 4;
      }
      iVar8 = this->_padding_;
      iVar9 = iVar9 + 1;
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar17 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar17 = pcVar17 + 1;
      }
    } while (iVar9 < *(short *)(iVar8 + 0x3c));
  }
  uVar10 = 0xffffffff;
  pcVar13 = &s___teams_;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  iVar8 = -1;
  pcVar13 = vic_str + 0xe0;
  do {
    pcVar14 = pcVar13;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar14 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar14;
  } while (cVar1 != '\0');
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = pcVar14 + -1;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  iVar8 = this->_padding_;
  iVar9 = 1;
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  if (1 < *(short *)(iVar8 + 0x3c)) {
    do {
      iVar8 = RGE_Base_Game::playerTeam((RGE_Base_Game *)this,iVar9 + -1);
      sprintf(&pcStack_858,&s__d,iVar8 + -1);
      uVar10 = 0xffffffff;
      ppcVar15 = &pcStack_858;
      do {
        ppcVar16 = ppcVar15;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        ppcVar16 = (char **)((int)ppcVar15 + 1);
        cVar1 = *(char *)ppcVar15;
        ppcVar15 = ppcVar16;
      } while (cVar1 != '\0');
      uVar10 = ~uVar10;
      iVar8 = -1;
      pcVar13 = vic_str + 0xe0;
      do {
        pcVar17 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar17 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar17;
      } while (cVar1 != '\0');
      pcVar13 = (char *)((int)ppcVar16 - uVar10);
      pcVar17 = pcVar17 + -1;
      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar17 = pcVar17 + 4;
      }
      iVar8 = this->_padding_;
      iVar9 = iVar9 + 1;
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar17 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar17 = pcVar17 + 1;
      }
    } while (iVar9 < *(short *)(iVar8 + 0x3c));
  }
  uVar10 = 0xffffffff;
  pcVar13 = &s___civs_;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  iVar8 = -1;
  pcVar13 = vic_str + 0xe0;
  do {
    pcVar14 = pcVar13;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar14 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar14;
  } while (cVar1 != '\0');
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = pcVar14 + -1;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  iVar8 = this->_padding_;
  iVar9 = 1;
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  if (1 < *(short *)(iVar8 + 0x3c)) {
    do {
      iVar8 = civilization(this,iVar9 + -1);
      sprintf(&pcStack_858,s__d_,iVar8);
      uVar10 = 0xffffffff;
      ppcVar15 = &pcStack_858;
      do {
        ppcVar16 = ppcVar15;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        ppcVar16 = (char **)((int)ppcVar15 + 1);
        cVar1 = *(char *)ppcVar15;
        ppcVar15 = ppcVar16;
      } while (cVar1 != '\0');
      uVar10 = ~uVar10;
      iVar8 = -1;
      pcVar13 = vic_str + 0xe0;
      do {
        pcVar17 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar17 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar17;
      } while (cVar1 != '\0');
      pcVar13 = (char *)((int)ppcVar16 - uVar10);
      pcVar17 = pcVar17 + -1;
      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar17 = pcVar17 + 4;
      }
      iVar8 = this->_padding_;
      iVar9 = iVar9 + 1;
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar17 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar17 = pcVar17 + 1;
      }
    } while (iVar9 < *(short *)(iVar8 + 0x3c));
  }
  run_log(vic_str + 0xe0,0);
  this_00 = (TMusic_System *)this->_padding_;
  if (this_00 != (TMusic_System *)0x0) {
    uVar2 = this_00->music_type;
    if (uVar2 == '\x01') {
      TMusic_System::play_tracks(this_00,5,0xe,1,0,0);
    }
    else if (uVar2 == '\x02') {
      TMusic_System::play_tracks(this_00,1,this_00->track_count,1,0,0);
    }
    else if (uVar2 == '\x03') {
      TMusic_System::stop_track(this_00);
    }
    this->started_menu_music = 0;
  }
  RGE_Base_Game::reset_timings((RGE_Base_Game *)this);
  (**(code **)(this->_padding_ + 0xc))(4);
  iVar8 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)this);
  if (iVar8 == 1) {
    RGE_Base_Game::set_paused((RGE_Base_Game *)this,0,0);
  }
  this->_padding_ = 0;
  TChat::ClearChat(chat);
  TChat::setInChatGroup(chat,(int)*(short *)(this->_padding_ + 0x7c),1);
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) &&
     (iVar8 = IsIconic(this->_padding_), iVar8 == 0)) {
    TMousePointer::center((TMousePointer *)this->_padding_);
  }
  RGE_Base_Game::enable_input((RGE_Base_Game *)this);
  return;
}

// --------------------------------------------------

// Function: start_scenario_editor
// Address: 00528de0
// [HELPER] s_Blank_Screen: "Blank Screen"
// [HELPER] s_Scenario_Editor_Menu: "Scenario Editor Menu"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_Status_Screen: "Status Screen"
/* public: int __thiscall TRIBE_Game::start_scenario_editor(char *,int) */

int __thiscall TRIBE_Game::start_scenario_editor(TRIBE_Game *this,char *param_1,int param_2)
{
  TRIBE_Screen_Sed *this_00;
  int iVar1;
  TPanel *pTVar2;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056180b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Base_Game::disable_input((RGE_Base_Game *)this);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  this_00 = (TRIBE_Screen_Sed *)operator_new(0x948);
  local_4 = 0;
  if (this_00 == (TRIBE_Screen_Sed *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = TRIBE_Screen_Sed::TRIBE_Screen_Sed(this_00,param_1,param_2);
  }
  local_4 = 0xffffffff;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xd8) == 0)) {
    if ((TMusic_System *)this->_padding_ != (TMusic_System *)0x0) {
      TMusic_System::stop_track((TMusic_System *)this->_padding_);
      this->started_menu_music = 0;
    }
    TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Open);
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Menu);
    TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
    TMousePointer::center((TMousePointer *)this->_padding_);
    RGE_Base_Game::enable_input((RGE_Base_Game *)this);
    *unaff_FS_OFFSET = local_c;
    return 1;
  }
  pTVar2 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Open);
  if (pTVar2 == (TPanel *)0x0) {
    pTVar2 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Menu);
    if (pTVar2 == (TPanel *)0x0) {
      pcVar3 = s_Blank_Screen;
    }
    else {
      pcVar3 = s_Scenario_Editor_Menu;
    }
  }
  else {
    pcVar3 = s_Scenario_Editor_Open;
  }
  TPanelSystem::setCurrentPanel(&panel_system,pcVar3,0);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  RGE_Base_Game::enable_input((RGE_Base_Game *)this);
  *unaff_FS_OFFSET = local_c;
  return 0;
}

// --------------------------------------------------

// Function: send_game_options
// Address: 00528f60
/* WARNING: Variable defined which should be unmapped: combined_options */
/* public: virtual void __thiscall TRIBE_Game::send_game_options(void) */

void __thiscall TRIBE_Game::send_game_options(TRIBE_Game *this)
{
  combined_options combined_options;
  
  if (this->_padding_ != 0) {
    RGE_Base_Game::get_game_options
              ((RGE_Base_Game *)this,
               (RGE_Game_Options *)&combined_options.rge_options.scenarioGameValue);
    get_tribe_options(this,(TRIBE_Game_Options *)&combined_options.tribe_options.mapTypeValue);
    TCommunications_Handler::SetMyGameOptions
              ((TCommunications_Handler *)this->_padding_,
               (char *)&combined_options.rge_options.scenarioGameValue,0x114);
  }
  return;
}

// --------------------------------------------------

// Function: receive_game_options
// Address: 00528fb0
/* WARNING: Variable defined which should be unmapped: size */
/* public: virtual void __thiscall TRIBE_Game::receive_game_options(void) */

void __thiscall TRIBE_Game::receive_game_options(TRIBE_Game *this)
{
  RGE_Game_Options *pRVar1;
  ulong size;
  ulong local_4;
  
  if ((TCommunications_Handler *)this->_padding_ != (TCommunications_Handler *)0x0) {
    local_4 = 0;
    pRVar1 = (RGE_Game_Options *)
             TCommunications_Handler::GetMyGameOptions
                       ((TCommunications_Handler *)this->_padding_,&local_4);
    if ((pRVar1 != (RGE_Game_Options *)0x0) && (local_4 == 0x114)) {
      RGE_Base_Game::set_game_options((RGE_Base_Game *)this,pRVar1);
      set_tribe_options(this,(TRIBE_Game_Options *)(pRVar1 + 1));
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_tribe_options
// Address: 00529000
/* public: void __thiscall TRIBE_Game::set_tribe_options(struct TRIBE_Game::TRIBE_Game_Options *) */

void __thiscall TRIBE_Game::set_tribe_options(TRIBE_Game *this,TRIBE_Game_Options *param_1)
{
  int *piVar1;
  int iVar2;
  
  setMapSize(this,param_1->mapSizeValue);
  setMapType(this,param_1->mapTypeValue);
  setAnimals(this,param_1->animalsValue);
  setPredators(this,param_1->predatorsValue);
  setVictoryType(this,param_1->victoryTypeValue,param_1->victoryAmountValue);
  iVar2 = 0;
  piVar1 = param_1->scenarioPlayerValue;
  do {
    setCivilization(this,iVar2,(uint)param_1->civilizationValue[iVar2]);
    setScenarioPlayer(this,iVar2,*piVar1);
    setPlayerColor(this,iVar2,(uint)param_1->playerColorValue[iVar2]);
    setComputerName(this,iVar2,(uint)param_1->computerNameValue[iVar2]);
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 1;
  } while (iVar2 < 9);
  setAllowTrading(this,(uint)param_1->allowTradingValue);
  setLongCombat(this,(uint)param_1->longCombatValue);
  setRandomizePositions(this,(uint)param_1->randomizePositionsValue);
  setFullTechTree(this,(uint)param_1->fullTechTreeValue);
  setResourceLevel(this,param_1->resourceLevelValue);
  setStartingAge(this,param_1->startingAgeValue);
  setStartingUnits(this,(uint)param_1->startingUnitsValue);
  setDeathMatch(this,param_1->deathMatchValue);
  setPopLimit(this,param_1->popLimitValue);
  return;
}

// --------------------------------------------------

// Function: get_tribe_options
// Address: 00529100
/* public: void __thiscall TRIBE_Game::get_tribe_options(struct TRIBE_Game::TRIBE_Game_Options *) */

void __thiscall TRIBE_Game::get_tribe_options(TRIBE_Game *this,TRIBE_Game_Options *param_1)
{
  uchar uVar1;
  MapSize MVar2;
  MapType MVar3;
  int iVar4;
  VictoryType VVar5;
  int iVar6;
  ResourceLevel RVar7;
  Age AVar8;
  int *piVar9;
  
  MVar2 = mapSize(this);
  param_1->mapSizeValue = MVar2;
  MVar3 = mapType(this);
  param_1->mapTypeValue = MVar3;
  iVar4 = animals(this);
  param_1->animalsValue = iVar4;
  iVar4 = predators(this);
  param_1->predatorsValue = iVar4;
  VVar5 = victoryType(this);
  param_1->victoryTypeValue = VVar5;
  iVar4 = victoryAmount(this);
  param_1->victoryAmountValue = iVar4;
  iVar4 = 0;
  piVar9 = param_1->scenarioPlayerValue;
  do {
    iVar6 = civilization(this,iVar4);
    param_1->civilizationValue[iVar4] = (uchar)iVar6;
    iVar6 = scenarioPlayer(this,iVar4);
    *piVar9 = iVar6;
    iVar6 = playerColor(this,iVar4);
    param_1->playerColorValue[iVar4] = (uchar)iVar6;
    iVar6 = computerName(this,iVar4);
    param_1->computerNameValue[iVar4] = (uchar)iVar6;
    iVar4 = iVar4 + 1;
    piVar9 = piVar9 + 1;
  } while (iVar4 < 9);
  iVar4 = allowTrading(this);
  param_1->allowTradingValue = (uchar)iVar4;
  iVar4 = longCombat(this);
  param_1->longCombatValue = (uchar)iVar4;
  iVar4 = randomizePositions(this);
  param_1->randomizePositionsValue = (uchar)iVar4;
  iVar4 = fullTechTree(this);
  param_1->fullTechTreeValue = (uchar)iVar4;
  RVar7 = resourceLevel(this);
  param_1->resourceLevelValue = RVar7;
  AVar8 = startingAge(this);
  param_1->startingAgeValue = AVar8;
  iVar4 = startingUnits(this);
  param_1->startingUnitsValue = (uchar)iVar4;
  uVar1 = deathMatch(this);
  param_1->deathMatchValue = uVar1;
  uVar1 = popLimit(this);
  param_1->popLimitValue = uVar1;
  return;
}

// --------------------------------------------------

// Function: mapSize
// Address: 005291f0
/* public: enum TRIBE_Game::MapSize __thiscall TRIBE_Game::mapSize(void)const  */

MapSize __thiscall TRIBE_Game::mapSize(TRIBE_Game *this)
{
  return (this->tribe_game_options).mapSizeValue;
}

// --------------------------------------------------

// Function: setMapSize
// Address: 00529200
/* public: void __thiscall TRIBE_Game::setMapSize(enum TRIBE_Game::MapSize) */

void __thiscall TRIBE_Game::setMapSize(TRIBE_Game *this,MapSize param_1)
{
  (this->tribe_game_options).mapSizeValue = param_1;
  switch(param_1) {
  case Tiny:
    RGE_Base_Game::setMapSize((RGE_Base_Game *)this,0x48,0x48,8);
    return;
  case Small:
    RGE_Base_Game::setMapSize((RGE_Base_Game *)this,0x60,0x60,8);
    return;
  case Medium:
                    /* language.dll match for 0x78: "10" */
    RGE_Base_Game::setMapSize((RGE_Base_Game *)this,0x78,0x78,8);
    return;
  case Large:
    RGE_Base_Game::setMapSize((RGE_Base_Game *)this,0x90,0x90,8);
    return;
  case Huge:
    RGE_Base_Game::setMapSize((RGE_Base_Game *)this,200,200,8);
    return;
  case Humongous:
    RGE_Base_Game::setMapSize((RGE_Base_Game *)this,0xfa,0xfa,8);
  }
  return;
}

// --------------------------------------------------

// Function: mapType
// Address: 005292a0
/* public: enum TRIBE_Game::MapType __thiscall TRIBE_Game::mapType(void)const  */

MapType __thiscall TRIBE_Game::mapType(TRIBE_Game *this)
{
  return (this->tribe_game_options).mapTypeValue;
}

// --------------------------------------------------

// Function: setMapType
// Address: 005292b0
/* public: void __thiscall TRIBE_Game::setMapType(enum TRIBE_Game::MapType) */

void __thiscall TRIBE_Game::setMapType(TRIBE_Game *this,MapType param_1)
{
  (this->tribe_game_options).mapTypeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: animals
// Address: 005292c0
/* public: int __thiscall TRIBE_Game::animals(void)const  */

int __thiscall TRIBE_Game::animals(TRIBE_Game *this)
{
  return (this->tribe_game_options).animalsValue;
}

// --------------------------------------------------

// Function: setAnimals
// Address: 005292d0
/* public: void __thiscall TRIBE_Game::setAnimals(int) */

void __thiscall TRIBE_Game::setAnimals(TRIBE_Game *this,int param_1)
{
  (this->tribe_game_options).animalsValue = param_1;
  return;
}

// --------------------------------------------------

// Function: predators
// Address: 005292e0
/* public: int __thiscall TRIBE_Game::predators(void)const  */

int __thiscall TRIBE_Game::predators(TRIBE_Game *this)
{
  return (this->tribe_game_options).predatorsValue;
}

// --------------------------------------------------

// Function: setPredators
// Address: 005292f0
/* public: void __thiscall TRIBE_Game::setPredators(int) */

void __thiscall TRIBE_Game::setPredators(TRIBE_Game *this,int param_1)
{
  (this->tribe_game_options).predatorsValue = param_1;
  return;
}

// --------------------------------------------------

// Function: victoryType
// Address: 00529300
/* public: enum TRIBE_Game::VictoryType __thiscall TRIBE_Game::victoryType(void)const  */

VictoryType __thiscall TRIBE_Game::victoryType(TRIBE_Game *this)
{
  return (this->tribe_game_options).victoryTypeValue;
}

// --------------------------------------------------

// Function: victoryAmount
// Address: 00529310
/* public: int __thiscall TRIBE_Game::victoryAmount(void)const  */

int __thiscall TRIBE_Game::victoryAmount(TRIBE_Game *this)
{
  return (this->tribe_game_options).victoryAmountValue;
}

// --------------------------------------------------

// Function: setVictoryType
// Address: 00529320
/* public: void __thiscall TRIBE_Game::setVictoryType(enum TRIBE_Game::VictoryType,int) */

void __thiscall TRIBE_Game::setVictoryType(TRIBE_Game *this,VictoryType param_1,int param_2)
{
  (this->tribe_game_options).victoryTypeValue = param_1;
  (this->tribe_game_options).victoryAmountValue = param_2;
  return;
}

// --------------------------------------------------

// Function: civilization
// Address: 00529340
/* public: int __thiscall TRIBE_Game::civilization(int) */

int __thiscall TRIBE_Game::civilization(TRIBE_Game *this,int param_1)
{
  return (uint)(this->tribe_game_options).civilizationValue[param_1];
}

// --------------------------------------------------

// Function: setCivilization
// Address: 00529350
/* public: void __thiscall TRIBE_Game::setCivilization(int,int) */

void __thiscall TRIBE_Game::setCivilization(TRIBE_Game *this,int param_1,int param_2)
{
  (this->tribe_game_options).civilizationValue[param_1] = (uchar)param_2;
  return;
}

// --------------------------------------------------

// Function: scenarioPlayer
// Address: 00529370
/* public: int __thiscall TRIBE_Game::scenarioPlayer(int) */

int __thiscall TRIBE_Game::scenarioPlayer(TRIBE_Game *this,int param_1)
{
  return (this->tribe_game_options).scenarioPlayerValue[param_1];
}

// --------------------------------------------------

// Function: setScenarioPlayer
// Address: 00529380
/* public: void __thiscall TRIBE_Game::setScenarioPlayer(int,int) */

void __thiscall TRIBE_Game::setScenarioPlayer(TRIBE_Game *this,int param_1,int param_2)
{
  (this->tribe_game_options).scenarioPlayerValue[param_1] = param_2;
  return;
}

// --------------------------------------------------

// Function: playerColor
// Address: 005293a0
/* public: int __thiscall TRIBE_Game::playerColor(int) */

int __thiscall TRIBE_Game::playerColor(TRIBE_Game *this,int param_1)
{
  return (uint)(this->tribe_game_options).playerColorValue[param_1];
}

// --------------------------------------------------

// Function: setPlayerColor
// Address: 005293b0
/* public: void __thiscall TRIBE_Game::setPlayerColor(int,int) */

void __thiscall TRIBE_Game::setPlayerColor(TRIBE_Game *this,int param_1,int param_2)
{
  (this->tribe_game_options).playerColorValue[param_1] = (uchar)param_2;
  return;
}

// --------------------------------------------------

// Function: computerName
// Address: 005293d0
/* public: int __thiscall TRIBE_Game::computerName(int) */

int __thiscall TRIBE_Game::computerName(TRIBE_Game *this,int param_1)
{
  return (uint)(this->tribe_game_options).computerNameValue[param_1];
}

// --------------------------------------------------

// Function: setComputerName
// Address: 005293e0
/* public: void __thiscall TRIBE_Game::setComputerName(int,int) */

void __thiscall TRIBE_Game::setComputerName(TRIBE_Game *this,int param_1,int param_2)
{
  (this->tribe_game_options).computerNameValue[param_1] = (uchar)param_2;
  return;
}

// --------------------------------------------------

// Function: allowTrading
// Address: 00529400
/* public: int __thiscall TRIBE_Game::allowTrading(void) */

int __thiscall TRIBE_Game::allowTrading(TRIBE_Game *this)
{
  return (uint)(this->tribe_game_options).allowTradingValue;
}

// --------------------------------------------------

// Function: longCombat
// Address: 00529410
/* public: int __thiscall TRIBE_Game::longCombat(void) */

int __thiscall TRIBE_Game::longCombat(TRIBE_Game *this)
{
  return (uint)(this->tribe_game_options).longCombatValue;
}

// --------------------------------------------------

// Function: randomizePositions
// Address: 00529420
/* public: int __thiscall TRIBE_Game::randomizePositions(void) */

int __thiscall TRIBE_Game::randomizePositions(TRIBE_Game *this)
{
  return (uint)(this->tribe_game_options).randomizePositionsValue;
}

// --------------------------------------------------

// Function: fullTechTree
// Address: 00529430
/* public: int __thiscall TRIBE_Game::fullTechTree(void) */

int __thiscall TRIBE_Game::fullTechTree(TRIBE_Game *this)
{
  return (uint)(this->tribe_game_options).fullTechTreeValue;
}

// --------------------------------------------------

// Function: resourceLevel
// Address: 00529440
/* public: enum TRIBE_Game::ResourceLevel __thiscall TRIBE_Game::resourceLevel(void) */

ResourceLevel __thiscall TRIBE_Game::resourceLevel(TRIBE_Game *this)
{
  return (this->tribe_game_options).resourceLevelValue;
}

// --------------------------------------------------

// Function: startingAge
// Address: 00529450
/* public: enum TRIBE_Game::Age __thiscall TRIBE_Game::startingAge(void) */

Age __thiscall TRIBE_Game::startingAge(TRIBE_Game *this)
{
  return (this->tribe_game_options).startingAgeValue;
}

// --------------------------------------------------

// Function: startingUnits
// Address: 00529460
/* public: int __thiscall TRIBE_Game::startingUnits(void) */

int __thiscall TRIBE_Game::startingUnits(TRIBE_Game *this)
{
  return (uint)(this->tribe_game_options).startingUnitsValue;
}

// --------------------------------------------------

// Function: deathMatch
// Address: 00529470
/* public: unsigned char __thiscall TRIBE_Game::deathMatch(void) */

uchar __thiscall TRIBE_Game::deathMatch(TRIBE_Game *this)
{
  return (this->tribe_game_options).deathMatchValue;
}

// --------------------------------------------------

// Function: popLimit
// Address: 00529480
/* public: unsigned char __thiscall TRIBE_Game::popLimit(void) */

uchar __thiscall TRIBE_Game::popLimit(TRIBE_Game *this)
{
  int iVar1;
  
  iVar1 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)this);
  if (iVar1 != 0) {
    return (this->tribe_game_options).popLimitValue;
  }
  return '2';
}

// --------------------------------------------------

// Function: quickStartGame
// Address: 005294a0
/* public: unsigned char __thiscall TRIBE_Game::quickStartGame(void) */

uchar __thiscall TRIBE_Game::quickStartGame(TRIBE_Game *this)
{
  return this->quick_start_game;
}

// --------------------------------------------------

// Function: randomStartValue
// Address: 005294b0
/* public: int __thiscall TRIBE_Game::randomStartValue(void) */

int __thiscall TRIBE_Game::randomStartValue(TRIBE_Game *this)
{
  return this->random_start_value;
}

// --------------------------------------------------

// Function: setAllowTrading
// Address: 005294c0
/* public: void __thiscall TRIBE_Game::setAllowTrading(int) */

void __thiscall TRIBE_Game::setAllowTrading(TRIBE_Game *this,int param_1)
{
  (this->tribe_game_options).allowTradingValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setLongCombat
// Address: 005294d0
/* public: void __thiscall TRIBE_Game::setLongCombat(int) */

void __thiscall TRIBE_Game::setLongCombat(TRIBE_Game *this,int param_1)
{
  (this->tribe_game_options).longCombatValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setRandomizePositions
// Address: 005294e0
/* public: void __thiscall TRIBE_Game::setRandomizePositions(int) */

void __thiscall TRIBE_Game::setRandomizePositions(TRIBE_Game *this,int param_1)
{
  (this->tribe_game_options).randomizePositionsValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setFullTechTree
// Address: 005294f0
/* public: void __thiscall TRIBE_Game::setFullTechTree(int) */

void __thiscall TRIBE_Game::setFullTechTree(TRIBE_Game *this,int param_1)
{
  (this->tribe_game_options).fullTechTreeValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setResourceLevel
// Address: 00529500
/* public: void __thiscall TRIBE_Game::setResourceLevel(enum TRIBE_Game::ResourceLevel) */

void __thiscall TRIBE_Game::setResourceLevel(TRIBE_Game *this,ResourceLevel param_1)
{
  (this->tribe_game_options).resourceLevelValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setStartingAge
// Address: 00529510
/* public: void __thiscall TRIBE_Game::setStartingAge(enum TRIBE_Game::Age) */

void __thiscall TRIBE_Game::setStartingAge(TRIBE_Game *this,Age param_1)
{
  (this->tribe_game_options).startingAgeValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setStartingUnits
// Address: 00529520
/* public: void __thiscall TRIBE_Game::setStartingUnits(int) */

void __thiscall TRIBE_Game::setStartingUnits(TRIBE_Game *this,int param_1)
{
  (this->tribe_game_options).startingUnitsValue = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: setDeathMatch
// Address: 00529530
/* public: void __thiscall TRIBE_Game::setDeathMatch(unsigned char) */

void __thiscall TRIBE_Game::setDeathMatch(TRIBE_Game *this,uchar param_1)
{
  (this->tribe_game_options).deathMatchValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setPopLimit
// Address: 00529540
/* public: void __thiscall TRIBE_Game::setPopLimit(unsigned char) */

void __thiscall TRIBE_Game::setPopLimit(TRIBE_Game *this,uchar param_1)
{
  (this->tribe_game_options).popLimitValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setQuickStartGame
// Address: 00529550
/* public: void __thiscall TRIBE_Game::setQuickStartGame(unsigned char) */

void __thiscall TRIBE_Game::setQuickStartGame(TRIBE_Game *this,uchar param_1)
{
  this->quick_start_game = param_1;
  return;
}

// --------------------------------------------------

// Function: setRandomStartValue
// Address: 00529560
/* public: void __thiscall TRIBE_Game::setRandomStartValue(int) */

void __thiscall TRIBE_Game::setRandomStartValue(TRIBE_Game *this,int param_1)
{
  this->random_start_value = param_1;
  return;
}

// --------------------------------------------------

// Function: gameSummary
// Address: 00529570
/* public: virtual char * __thiscall TRIBE_Game::gameSummary(void) */

char * __thiscall TRIBE_Game::gameSummary(TRIBE_Game *this)
{
  DAT_0086bca0._0_1_ = 0;
  return (char *)&DAT_0086bca0;
}

// --------------------------------------------------

// Function: wnd_proc
// Address: 00529580
/* public: virtual long __stdcall TRIBE_Game::wnd_proc(void *,unsigned int,unsigned int,long) */

long TRIBE_Game::wnd_proc(void *param_1,uint param_2,uint param_3,long param_4)
{
  long lVar1;
  
  if (param_3 < 0x201) {
    if (param_3 == 0x200) {
      if (*(int *)((int)param_1 + 0x1b0) == 1) {
        SetCursor(0);
      }
    }
    else if (param_3 == 7) {
      if (*(int *)((int)param_1 + 0x1d8) == 0) {
        RGE_Base_Game::disable_input((RGE_Base_Game *)param_1);
      }
      else {
        RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
      }
    }
  }
  else if (((param_3 == 0x201) || (param_3 == 0x204)) && (*(int *)((int)param_1 + 0x1b0) == 1)) {
    stop_video((TRIBE_Game *)param_1,'\x01');
    return 0;
  }
  lVar1 = RGE_Base_Game::wnd_proc(param_1,param_2,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 00529610
// [HELPER] s_Already_in_handle_idle__wT__ld_: "Already in handle_idle, wT=%ld."
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
// [HELPER] s_Multiplayer_Wait_Screen: "Multiplayer Wait Screen"
// [HELPER] s__: "}"
// [HELPER] s_paused: "paused"
// [HELPER] s_stopped: "stopped"
/* WARNING: Variable defined which should be unmapped: retval */
/* public: virtual int __thiscall TRIBE_Game::handle_idle(void) */

int __thiscall TRIBE_Game::handle_idle(TRIBE_Game *this)
{
  char cVar1;
  byte bVar2;
  TDebuggingLog *this_00;
  ulong uVar3;
  byte *pbVar4;
  int iVar5;
  char *pcVar6;
  TRIBE_Screen_Wait *this_01;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  int retval;
  char str [100];
  char msg [2304];
  
  str._0_4_ = RGE_Base_Game::handle_idle((RGE_Base_Game *)this);
  if (str._0_4_ == 0) {
    return 0;
  }
  if (this->inHandleIdle != 0) {
    this_00 = *(TDebuggingLog **)(this->_padding_ + 4);
    TDebuggingLog::Log(this_00,(char *)L,s_Already_in_handle_idle__wT__ld_,this_00);
    return 0;
  }
  uVar9 = 1;
  this->inHandleIdle = 1;
  color_log('L','L',5);
  color_log('L','\x16',5);
  iVar5 = this->_padding_;
  if ((iVar5 != 1) || (this->video_window == (void *)0x0)) {
    if (iVar5 == 3) {
      iVar5 = TCommunications_Handler::MultiplayerGameStart
                        ((TCommunications_Handler *)this->_padding_);
      if (iVar5 == 0) {
        color_log('L','T',5);
                    /* language.dll match for 0x139c: "Bones 2" */
        uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x139c);
        if (499 < uVar3 - DAT_0086be04) {
                    /* language.dll match for 0x454: "Waiting for other players..." */
          (**(code **)(this->_padding_ + 0x20))(0x454,msg + 4,0x900);
          uVar7 = 0xffffffff;
          pcVar6 = &s__;
          do {
            pcVar12 = pcVar6;
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            pcVar12 = pcVar6 + 1;
            cVar1 = *pcVar6;
            pcVar6 = pcVar12;
          } while (cVar1 != '\0');
          uVar7 = ~uVar7;
          iVar5 = -1;
          pcVar6 = msg + 4;
          do {
            pcVar11 = pcVar6;
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            pcVar11 = pcVar6 + 1;
            cVar1 = *pcVar6;
            pcVar6 = pcVar11;
          } while (cVar1 != '\0');
          pcVar6 = pcVar12 + -uVar7;
          pcVar12 = pcVar11 + -1;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar12 = *(undefined4 *)pcVar6;
            pcVar6 = pcVar6 + 4;
            pcVar12 = pcVar12 + 4;
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *pcVar12 = *pcVar6;
            pcVar6 = pcVar6 + 1;
            pcVar12 = pcVar12 + 1;
          }
          do {
            uVar7 = TCommunications_Handler::WhoAmI((TCommunications_Handler *)this->_padding_);
            if (uVar9 != uVar7) {
              iVar5 = TCommunications_Handler::IsPlayerHuman
                                ((TCommunications_Handler *)this->_padding_,uVar9);
              if (iVar5 != 0) {
                uVar7 = 0xffffffff;
                pcVar6 = &s__;
                do {
                  pcVar12 = pcVar6;
                  if (uVar7 == 0) break;
                  uVar7 = uVar7 - 1;
                  pcVar12 = pcVar6 + 1;
                  cVar1 = *pcVar6;
                  pcVar6 = pcVar12;
                } while (cVar1 != '\0');
                uVar7 = ~uVar7;
                iVar5 = -1;
                pcVar6 = msg + 4;
                do {
                  pcVar11 = pcVar6;
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  pcVar11 = pcVar6 + 1;
                  cVar1 = *pcVar6;
                  pcVar6 = pcVar11;
                } while (cVar1 != '\0');
                pcVar6 = pcVar12 + -uVar7;
                pcVar12 = pcVar11 + -1;
                for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                  *(undefined4 *)pcVar12 = *(undefined4 *)pcVar6;
                  pcVar6 = pcVar6 + 4;
                  pcVar12 = pcVar12 + 4;
                }
                for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                  *pcVar12 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                  pcVar12 = pcVar12 + 1;
                }
                pcVar6 = TCommunications_Handler::WaitingOnNamedInfo
                                   ((TCommunications_Handler *)this->_padding_,uVar9);
                uVar7 = 0xffffffff;
                do {
                  pcVar12 = pcVar6;
                  if (uVar7 == 0) break;
                  uVar7 = uVar7 - 1;
                  pcVar12 = pcVar6 + 1;
                  cVar1 = *pcVar6;
                  pcVar6 = pcVar12;
                } while (cVar1 != '\0');
                uVar7 = ~uVar7;
                iVar5 = -1;
                pcVar6 = msg + 4;
                do {
                  pcVar11 = pcVar6;
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  pcVar11 = pcVar6 + 1;
                  cVar1 = *pcVar6;
                  pcVar6 = pcVar11;
                } while (cVar1 != '\0');
                pcVar6 = pcVar12 + -uVar7;
                pcVar12 = pcVar11 + -1;
                for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                  *(undefined4 *)pcVar12 = *(undefined4 *)pcVar6;
                  pcVar6 = pcVar6 + 4;
                  pcVar12 = pcVar12 + 4;
                }
                for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                  *pcVar12 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                  pcVar12 = pcVar12 + 1;
                }
              }
            }
            uVar9 = uVar9 + 1;
          } while ((int)uVar9 < 9);
          this_01 = (TRIBE_Screen_Wait *)
                    TPanelSystem::panel(&panel_system,s_Multiplayer_Wait_Screen);
          if (this_01 != (TRIBE_Screen_Wait *)0x0) {
            TRIBE_Screen_Wait::set_text(this_01,msg + 4);
          }
          DAT_0086be04 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x13ac);
        }
      }
      else {
        color_log('L','$',5);
        let_game_begin(this);
      }
    }
    else if (((iVar5 == 4) || (iVar5 == 6)) || (iVar5 == 5)) {
      color_log('L','2',5);
      if ((out_of_sync2 == 0) && (this->game_screen != (TRIBE_Screen_Game *)0x0)) {
        TRIBE_Screen_Game::handle_game_update(this->game_screen);
      }
    }
    goto LAB_0052994c;
  }
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x1381);
  if (uVar3 - this->last_video_time < 1000) goto LAB_0052994c;
  SendMessageA(this->video_window,0x46a,100,str + 4);
  if (str[4] == '\0') {
LAB_00529784:
    stop_video(this,'\x01');
  }
  else {
    pbVar10 = &s_stopped;
    pbVar4 = (byte *)(str + 4);
    do {
      bVar2 = *pbVar4;
      bVar13 = bVar2 < *pbVar10;
      if (bVar2 != *pbVar10) {
LAB_00529725:
        iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
        goto LAB_0052972a;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar4[1];
      bVar13 = bVar2 < pbVar10[1];
      if (bVar2 != pbVar10[1]) goto LAB_00529725;
      pbVar4 = pbVar4 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar2 != 0);
    iVar5 = 0;
LAB_0052972a:
    if (iVar5 == 0) goto LAB_00529784;
    if (this->video_paused == 0) {
      pbVar10 = &s_paused;
      pbVar4 = (byte *)(str + 4);
      do {
        bVar2 = *pbVar4;
        bVar13 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_00529769:
          iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          goto LAB_0052976e;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar13 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_00529769;
        pbVar4 = pbVar4 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_0052976e:
      if (iVar5 == 0) {
        SendMessageA(this->video_window,0x855,0,0);
      }
    }
  }
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x138d);
  this->last_video_time = uVar3;
LAB_0052994c:
  color_log('L','_',5);
  iVar5._0_1_ = str[0];
  iVar5._1_1_ = str[1];
  iVar5._2_1_ = str[2];
  iVar5._3_1_ = str[3];
  this->inHandleIdle = 0;
  return iVar5;
}

// --------------------------------------------------

// Function: handle_query_new_palette
// Address: 00529980
/* public: virtual int __thiscall TRIBE_Game::handle_query_new_palette(void *,unsigned int,unsigned
   int,long) */

int __thiscall
TRIBE_Game::handle_query_new_palette
          (TRIBE_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  int iVar1;
  
  iVar1 = 1;
  if (this->_padding_ == 1) {
    if ((this->video_window != (void *)0x0) && (this->video_hi_color == 0)) {
      SendMessageA(this->video_window,0x476,0,0);
      return 1;
    }
  }
  else {
    iVar1 = RGE_Base_Game::handle_query_new_palette
                      ((RGE_Base_Game *)this,param_1,param_2,param_3,param_4);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: handle_activate
// Address: 005299e0
/* public: virtual int __thiscall TRIBE_Game::handle_activate(void *,unsigned int,unsigned int,long)
    */

int __thiscall
TRIBE_Game::handle_activate(TRIBE_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  void *pvVar1;
  
  RGE_Base_Game::handle_activate((RGE_Base_Game *)this,param_1,param_2,param_3,param_4);
  if ((this->_padding_ == 1) && (pvVar1 = this->video_window, pvVar1 != (void *)0x0)) {
    if (param_3 == 1) {
      if (this->video_paused != 0) {
        SendMessageA(pvVar1,0x855,0,0);
        this->video_paused = 0;
        return 1;
      }
    }
    else if (this->video_paused == 0) {
      SendMessageA(pvVar1,0x809,0,0);
      this->video_paused = 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: action_user_command
// Address: 00529a70
// [HELPER] s_: ""
// [HELPER] s_Multiplayer_Wait_Screen: "Multiplayer Wait Screen"
// [HELPER] s_Out_of_sync_detected_by_comm___: "Out of sync detected by comm..."
// [HELPER] s_SKIPSYNCSAVE: "SKIPSYNCSAVE"
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s_Temp_Screen: "Temp Screen"
// [HELPER] s_____PROBLEM_COMMUNICATING_WITH__: "$$$ PROBLEM COMMUNICATING WITH %s"
// [HELPER] s_syncerr_d_gam: "syncerr%d.gam"
/* public: virtual int __thiscall TRIBE_Game::action_user_command(unsigned long,unsigned long) */

int __thiscall TRIBE_Game::action_user_command(TRIBE_Game *this,ulong param_1,ulong param_2)
{
  uchar uVar1;
  TEasy_Panel *pTVar2;
  uint uVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  char msg [256];
  char temp_str [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056182e;
  *unaff_FS_OFFSET = &local_c;
  iVar4 = this->_padding_;
  if (iVar4 == 3) {
    switch(param_1) {
    case 0x17a8:
    case 0x17a9:
    case 0x17aa:
    case 0x17ab:
    case 0x17b2:
    case 0x17b6:
      quit_game(this);
      TPanelSystem::destroyPanel(&panel_system,s_Multiplayer_Wait_Screen);
      TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
      pTVar2 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
joined_r0x00529bcc:
      if (pTVar2 != (TEasy_Panel *)0x0) {
                    /* language.dll match for 0x25c9: "You were dropped from the game." */
        TEasy_Panel::popupOKDialog(pTVar2,0x25c9,(char *)0x0,0x1c2,100);
      }
      break;
    case 0x17ac:
    case 0x17b7:
      (**(code **)(this->_padding_ + 0x44))();
      RGE_Base_Game::setSinglePlayerGame((RGE_Base_Game *)this,1);
      quit_game(this);
      TPanelSystem::destroyPanel(&panel_system,s_Multiplayer_Wait_Screen);
      TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
      pTVar2 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
      if (pTVar2 != (TEasy_Panel *)0x0) {
                    /* language.dll match for 0x25c9: "You were dropped from the game." */
        TEasy_Panel::popupOKDialog(pTVar2,0x25c9,(char *)0x0,0x1c2,100);
      }
    }
  }
  else {
    if (((iVar4 != 4) && (iVar4 != 6)) && (iVar4 != 5)) goto switchD_00529abb_caseD_17ad;
    switch(param_1) {
    case 0x17a2:
      if (this->game_screen != (TRIBE_Screen_Game *)0x0) {
        TRIBE_Screen_Game::handle_pause(this->game_screen);
      }
      break;
    case 0x17a3:
      if (this->game_screen != (TRIBE_Screen_Game *)0x0) {
        TRIBE_Screen_Game::handle_resume(this->game_screen);
      }
      break;
    case 0x17b0:
      if (this->game_screen != (TRIBE_Screen_Game *)0x0) {
        RGE_Base_Game::play_sound((RGE_Base_Game *)this,2);
        TRIBE_Screen_Game::display_system_message
                  (this->game_screen,s_Out_of_sync_detected_by_comm___);
      }
      uVar1 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)this,s_SKIPSYNCSAVE);
      if (uVar1 == '\0') {
        if (out_of_sync == 0) {
          out_of_sync = 1;
          iVar4 = TCommunications_Handler::IsHost((TCommunications_Handler *)this->_padding_);
          if (iVar4 != 0) {
            TRIBE_Command::command_save_game(*(TRIBE_Command **)(this->_padding_ + 0x58));
          }
        }
      }
      else if (out_of_sync == 0) {
        uVar3 = TCommunications_Handler::WhoAmI((TCommunications_Handler *)this->_padding_);
        iVar4 = TCommunications_Handler::IsPlayerOutOfSync
                          ((TCommunications_Handler *)this->_padding_,uVar3,param_2);
        if (iVar4 != 0) {
          out_of_sync = 1;
          out_of_sync2 = 1;
          msg._0_4_ = operator_new(0x47c);
          local_4 = 0;
          if ((TRIBE_Screen_Status_Message *)msg._0_4_ != (TRIBE_Screen_Status_Message *)0x0) {
            TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message
                      ((TRIBE_Screen_Status_Message *)msg._0_4_,s_Temp_Screen,s_,(char *)0x0,-1);
          }
          local_4 = 0xffffffff;
          TPanelSystem::setCurrentPanel(&panel_system,s_Temp_Screen,0);
          close_game_screens(this,1);
          if (do_debug_random != 0) {
            debug_random_write();
            dump_vismap_log();
          }
          iVar4 = TCommunications_Handler::WhoAmI((TCommunications_Handler *)this->_padding_);
          sprintf(msg + 4,s_syncerr_d_gam,iVar4);
          save_game(this,msg + 4);
          RGE_Player::loss_if_game_on
                    (*(RGE_Player **)
                      (*(int *)(this->_padding_ + 0x40) + *(short *)(this->_padding_ + 0x7c) * 4));
          do_game_over(this);
          pTVar2 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
          if (pTVar2 != (TEasy_Panel *)0x0) {
                    /* language.dll match for 0x966: "You were dropped from the game because of a
                       sync error. Your network connection may have been lost." */
            TEasy_Panel::popupOKDialog(pTVar2,0x966,(char *)0x0,0x1c2,100);
          }
          TPanelSystem::destroyPanel(&panel_system,s_Temp_Screen);
        }
      }
      break;
    case 0x17b2:
      if (this->game_screen == (TRIBE_Screen_Game *)0x0) break;
      RGE_Player::loss_if_game_on
                (*(RGE_Player **)
                  (*(int *)(this->_padding_ + 0x40) + *(short *)(this->_padding_ + 0x7c) * 4));
      do_game_over(this);
      pTVar2 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
      goto joined_r0x00529bcc;
    case 0x17bd:
      iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)this,param_2);
      if (((iVar4 != *(short *)(this->_padding_ + 0x7c)) &&
          (this->game_screen != (TRIBE_Screen_Game *)0x0)) &&
         ((iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)this,param_2), 0 < iVar4 &&
          ((&player_dropped)[param_2] == (int *)0x0)))) {
        RGE_Base_Game::play_sound((RGE_Base_Game *)this,2);
                    /* language.dll match for 0x4c1: "Problem communicating with %s..." */
        (**(code **)(this->_padding_ + 0x20))(0x4c1,temp_str + 4,0x100);
        iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)this,param_2);
        sprintf(msg + 4,temp_str + 4,
                *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + 0x40) + iVar4 * 4) + 0x44));
        TRIBE_Screen_Game::display_system_message(this->game_screen,msg + 4);
        iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)this,param_2);
        TDebuggingLog::Log(L,(char *)L,s_____PROBLEM_COMMUNICATING_WITH__,
                           *(undefined4 *)
                            (*(int *)(*(int *)(this->_padding_ + 0x40) + iVar4 * 4) + 0x44));
      }
      break;
    case 0x17d5:
      if (this->game_screen != (TRIBE_Screen_Game *)0x0) {
        RGE_Base_Game::play_sound((RGE_Base_Game *)this,2);
        TRIBE_Screen_Game::handleChatReceived(this->game_screen,param_2);
      }
    }
  }
switchD_00529abb_caseD_17ad:
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: action_key_down
// Address: 00529f60
// [HELPER] s_empires_hlp: "empires.hlp"
/* public: virtual int __thiscall TRIBE_Game::action_key_down(unsigned long,int,int,int,int) */

int __thiscall
TRIBE_Game::action_key_down
          (TRIBE_Game *this,ulong param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  
  if (this->_padding_ != 1) {
    if (param_1 != 0x70) {
      return 1;
    }
    iVar1 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)this);
    if ((iVar1 == 0) ||
       ((((iVar1 = this->_padding_, iVar1 != 4 && (iVar1 != 6)) && (iVar1 != 7)) && (iVar1 != 5))))
{
      WinHelpA(this->_padding_,s_empires_hlp,3,0);
    }
    return 0;
  }
  if (param_1 != 0xd) {
    if (param_1 == 0x1b) {
      stop_video(this,'\0');
      return 0;
    }
    if (param_1 != 0x20) {
      return 1;
    }
  }
  stop_video(this,'\x01');
  return 0;
}

// --------------------------------------------------

// Function: action_close
// Address: 0052a000
/* public: virtual int __thiscall TRIBE_Game::action_close(void) */

int __thiscall TRIBE_Game::action_close(TRIBE_Game *this)
{
  if (this->_padding_ != 0) {
    disconnect_multiplayer_game(this);
    this->_padding_ = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: game_over_msg
// Address: 0052a030
/* public: char * __thiscall TRIBE_Game::game_over_msg(void) */

char * __thiscall TRIBE_Game::game_over_msg(TRIBE_Game *this)
{
  if (*(char *)(*(int *)(*(int *)(this->_padding_ + 0x40) + *(short *)(this->_padding_ + 0x7c) * 4)
               + 0x80) == '\x01') {
                    /* language.dll match for 0x47e: "Victory!" */
    (**(code **)(this->_padding_ + 0x20))(0x47e,0x86bce0,0x100);
    return &DAT_0086bcd8.field_0x8;
  }
                    /* language.dll match for 0x47f: "Defeat!" */
  (**(code **)(this->_padding_ + 0x20))(0x47f,0x86bce0,0x100);
  return &DAT_0086bcd8.field_0x8;
}

// --------------------------------------------------

// Function: get_achievement_info
// Address: 0052a080
/* public: long __thiscall TRIBE_Game::get_achievement_info(unsigned char,char * *) */

long __thiscall TRIBE_Game::get_achievement_info(TRIBE_Game *this,uchar param_1,char **param_2)
{
  long lVar1;
  
  if ((TRIBE_World *)this->_padding_ == (TRIBE_World *)0x0) {
    return 0;
  }
  lVar1 = TRIBE_World::get_achievement((TRIBE_World *)this->_padding_,param_1,param_2);
  return lVar1;
}

// --------------------------------------------------

// Function: randomComputerName
// Address: 0052a0b0
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
/* WARNING: Variable defined which should be unmapped: scount */
/* public: int __thiscall TRIBE_Game::randomComputerName(int) */

int __thiscall TRIBE_Game::randomComputerName(TRIBE_Game *this,int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  char scount [10];
  
  (**(code **)(this->_padding_ + 0x20))((param_1 + 0x1b7) * 10,scount + 4,10);
  iVar1 = atoi(&stack0xffffffe8);
  stack0xfffffff8 = 0;
  do {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_tribegam_c,0x1521);
    iVar3 = iVar2 % iVar1;
    if (iVar1 + -1 < iVar2 % iVar1) {
      iVar3 = iVar1 + -1;
    }
  } while ((this->computerNameUsed[param_1][iVar3] != '\0') &&
          (register0x00000000 = stack0xfffffff8 + 1, register0x00000000 < 0x14));
  iVar1 = iVar3;
  if (this->computerNameUsed[param_1][iVar3] == '\x01') {
    iVar2 = 0;
    do {
      iVar1 = iVar2;
      if (this->computerNameUsed[param_1][iVar2] == '\0') break;
      iVar2 = iVar2 + 1;
      iVar1 = iVar3;
    } while (iVar2 < 10);
  }
  this->computerNameUsed[param_1][iVar1] = '\x01';
  return iVar1 + param_1 * 10 + -9;
}

// --------------------------------------------------

// Function: resetRandomComputerName
// Address: 0052a170
/* public: void __thiscall TRIBE_Game::resetRandomComputerName(void) */

void __thiscall TRIBE_Game::resetRandomComputerName(TRIBE_Game *this)
{
  int iVar1;
  uchar (*pauVar2) [10];
  
  pauVar2 = this->computerNameUsed;
  for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(uchar *)((int)pauVar2 + 0) = '\0';
    *(uchar *)((int)pauVar2 + 1) = '\0';
    *(uchar *)((int)pauVar2 + 2) = '\0';
    *(uchar *)((int)pauVar2 + 3) = '\0';
    pauVar2 = (uchar (*) [10])(*pauVar2 + 4);
  }
  return;
}

// --------------------------------------------------

// Function: video_wnd_proc
// Address: 0052a190
/* public: long __thiscall TRIBE_Game::video_wnd_proc(void *,unsigned int,unsigned int,long) */

long __thiscall
TRIBE_Game::video_wnd_proc(TRIBE_Game *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  long lVar1;
  
  if (param_2 == 0x200) {
    SetCursor(0);
    return 0;
  }
  if ((param_2 != 0x201) && (param_2 != 0x204)) {
    lVar1 = CallWindowProcA(this->old_video_wnd_proc,param_1,param_2,param_3,param_4);
    return lVar1;
  }
  stop_video(this,'\x01');
  return 0;
}

// --------------------------------------------------

// Function: SetClickTables
// Address: 0052a1e0
/* public: void __thiscall TRIBE_Game::SetClickTables(struct MouseClickInfo *,int,struct
   MouseClickInfo *,int) */

void __thiscall
TRIBE_Game::SetClickTables
          (TRIBE_Game *this,MouseClickInfo *param_1,int param_2,MouseClickInfo *param_3,int param_4)
{
  this->MouseRightClickTable = param_1;
  this->MouseRightClickTableSize = param_2;
  this->MouseLeftClickTable = param_3;
  this->MouseLeftClickTableSize = param_4;
  return;
}

// --------------------------------------------------

// Function: set_interface_messages
// Address: 0052a210
/* public: virtual void __thiscall TRIBE_Game::set_interface_messages(void) */

void __thiscall TRIBE_Game::set_interface_messages(TRIBE_Game *this)
{
  if (*(short *)(this->_padding_ + 0x8dc) == 1) {
    SetClickTables(this,(MouseClickInfo *)&Tribe1btnMouseRightClickTable,
                   Tribe1btnMouseRightClickTableSize,(MouseClickInfo *)&Tribe1btnMouseLeftClickTable
                   ,Tribe1btnMouseLeftClickTableSize);
    return;
  }
  SetClickTables(this,(MouseClickInfo *)&Tribe2btnMouseRightClickTable,
                 Tribe2btnMouseRightClickTableSize,(MouseClickInfo *)&Tribe2btnMouseLeftClickTable,
                 Tribe2btnMouseLeftClickTableSize);
  return;
}

// --------------------------------------------------

// Function: setup_video_system
// Address: 0052a260
// [HELPER] s_640x480_16bit: "640x480 16bit"
// [HELPER] s_640x480_16bit_success: "640x480 16bit success"
// [HELPER] s_640x480_8bit: "640x480 8bit"
// [HELPER] s_640x480_8bit_success: "640x480 8bit success"
// [HELPER] s_8BITVIDEO: "8BITVIDEO"
// [HELPER] s_Blank_Screen: "Blank Screen"
// [HELPER] s_video_changed_res__d__double_siz: "video_changed_res=%d, double_size=%d"
/* public: int __thiscall TRIBE_Game::setup_video_system(void) */

int __thiscall TRIBE_Game::setup_video_system(TRIBE_Game *this)
{
  uchar uVar1;
  int iVar2;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  
  if (this->video_setup != 0) {
    return 1;
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Blank_Screen,0);
  RGE_Base_Game::mouse_off((RGE_Base_Game *)this);
  this->video_double_size = 1;
  this->video_changed_res = 0;
  this->video_hi_color = 0;
  this->video_save_palette = *(void **)(this->_padding_ + 8);
  if (*(char *)(this->_padding_ + 0x479) == '\x02') {
    SetCursor(0);
    SetClassLongA(this->_padding_,0xfffffff4,0);
    TMousePointer::Shutdown_Mouse((TMousePointer *)this->_padding_);
    this->video_save_res_wid = *(long *)(this->_padding_ + 0x2c);
    this->video_save_res_hgt = *(long *)(this->_padding_ + 0x30);
    uVar1 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)this,s_8BITVIDEO);
    if (uVar1 == '\0') {
      iVar2 = TDrawSystem::IsModeAvail((TDrawSystem *)this->_padding_,0x280,0x1e0,0x10);
      if (iVar2 != 0) {
        TDebuggingLog::Log(this_00,(char *)L,s_640x480_16bit);
        iVar2 = TDrawSystem::SetDisplaySize((TDrawSystem *)this->_padding_,0x280,0x1e0,0x10);
        this->video_changed_res = iVar2;
        if (iVar2 != 0) {
          this->video_double_size = 1;
          this->video_hi_color = 1;
          TDebuggingLog::Log(L,(char *)L,s_640x480_16bit_success);
        }
      }
      if ((this->video_changed_res == 0) && (((TDrawSystem *)this->_padding_)->ScreenWidth != 0x280)
         ) {
        iVar2 = TDrawSystem::IsModeAvail((TDrawSystem *)this->_padding_,0x280,0x1e0,8);
        if (iVar2 != 0) {
          TDebuggingLog::Log(this_01,(char *)L,s_640x480_8bit);
          iVar2 = TDrawSystem::SetDisplaySize((TDrawSystem *)this->_padding_,0x280,0x1e0,8);
          this->video_changed_res = iVar2;
          if (iVar2 != 0) {
            this->video_double_size = 1;
            TDebuggingLog::Log(this_02,(char *)L,s_640x480_8bit_success);
          }
        }
      }
    }
  }
  TDebuggingLog::Log((TDebuggingLog *)this->video_double_size,(char *)L,
                     s_video_changed_res__d__double_siz,this->video_changed_res,
                     (TDebuggingLog *)this->video_double_size);
  iVar2 = this->_padding_;
  (**(code **)(iVar2 + 0xc))(1);
  (**(code **)(iVar2 + 0xa4))();
  this->video_setup = 1;
  return 1;
}

// --------------------------------------------------

// Function: shutdown_video_system
// Address: 0052a430
/* public: void __thiscall TRIBE_Game::shutdown_video_system(void) */

void __thiscall TRIBE_Game::shutdown_video_system(TRIBE_Game *this)
{
  int iVar1;
  void *pvVar2;
  
  if (this->video_setup != 0) {
    if (this->video_changed_res != 0) {
      TDrawSystem::SetDisplaySize
                ((TDrawSystem *)this->_padding_,this->video_save_res_wid,this->video_save_res_hgt,8)
      ;
      TDrawSystem::ClearPrimarySurface((TDrawSystem *)this->_padding_);
      TDrawSystem::SetPalette((TDrawSystem *)this->_padding_,this->video_save_palette);
      this->video_changed_res = 0;
      TDrawSystem::CheckSurfaces((TDrawSystem *)this->_padding_);
      TDrawSystem::ClearRestored((TDrawSystem *)this->_padding_);
      RGE_Base_Game::check_paint((RGE_Base_Game *)this);
      restore_mouse_after_paint = 1;
    }
    TDrawSystem::ClearPrimarySurface((TDrawSystem *)this->_padding_);
    TDrawSystem::SetPalette((TDrawSystem *)this->_padding_,this->video_save_palette);
    RGE_Base_Game::set_render_all((RGE_Base_Game *)this);
    InvalidateRect(this->_padding_,0,1);
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0xc))(2);
    (**(code **)(iVar1 + 0xa8))();
    pvVar2 = (void *)LoadCursorA(0,0x7f00);
    RGE_Base_Game::set_mouse_cursor((RGE_Base_Game *)this,pvVar2);
    RGE_Base_Game::mouse_on((RGE_Base_Game *)this);
    this->video_setup = 0;
  }
  return;
}

// --------------------------------------------------

// Function: disconnect_multiplayer_game
// Address: 0052a510
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
/* public: void __thiscall TRIBE_Game::disconnect_multiplayer_game(void) */

void __thiscall TRIBE_Game::disconnect_multiplayer_game(TRIBE_Game *this)
{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  iVar1 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)this);
  if (iVar1 == 0) {
    TCommunications_Handler::GameOver((TCommunications_Handler *)this->_padding_);
  }
  else {
    iVar1 = this->_padding_;
    if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
      TCommunications_Handler::SendIResignMsg((TCommunications_Handler *)this->_padding_);
      TCommunications_Handler::ShutdownGameMessages((TCommunications_Handler *)this->_padding_);
      iVar1 = TCommunications_Handler::CountWaitingMessages
                        ((TCommunications_Handler *)this->_padding_);
      if (0 < iVar1) {
        RGE_Base_Game::disable_input((RGE_Base_Game *)this);
                    /* language.dll match for 0x4c0: "Disconnecting from multiplayer
                       game...\\n\\n\\n\\nPlease press ESC if the game does not\\ndisconnect within
                       15 seconds." */
        show_status_message(this,0x4c0,(char *)0x0,-1);
        uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x15f8);
        uVar4 = uVar2;
        do {
          do {
            if ((this->_padding_ == 0) || (*(char *)(this->_padding_ + 0x1d) == '\x01'))
            goto LAB_0052a5fa;
            TCommunications_Handler::ShutdownGameMessages
                      ((TCommunications_Handler *)this->_padding_);
            uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x1601);
          } while (uVar3 - uVar4 < 500);
          iVar1 = TCommunications_Handler::CountWaitingMessages
                            ((TCommunications_Handler *)this->_padding_);
          if (iVar1 == 0) break;
          uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x1605);
        } while (uVar4 - uVar2 < 15000);
      }
LAB_0052a5fa:
      TCommunications_Handler::GameOver((TCommunications_Handler *)this->_padding_);
      TCommunications_Handler::UnlinkToLevel
                ((TCommunications_Handler *)this->_padding_,SERVICE_AVAILABLE);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: add_notification_loc
// Address: 0052a630
/* public: void __thiscall TRIBE_Game::add_notification_loc(long,long) */

void __thiscall TRIBE_Game::add_notification_loc(TRIBE_Game *this,long param_1,long param_2)
{
  int iVar1;
  
  iVar1 = this->current_notification_loc;
  if (((iVar1 < 0) || (this->notification_loc_x[iVar1] != param_1)) ||
     (this->notification_loc_y[iVar1] != param_2)) {
    this->current_notification_loc = iVar1 + 1;
    if (4 < iVar1 + 1) {
      this->current_notification_loc = 0;
    }
    this->notification_loc_x[this->current_notification_loc] = param_1;
    this->notification_loc_y[this->current_notification_loc] = param_2;
  }
  this->current_notification_recalled = this->current_notification_loc;
  return;
}

// --------------------------------------------------

// Function: goto_notification_loc
// Address: 0052a6a0
/* WARNING: Variable defined which should be unmapped: y */
/* public: void __thiscall TRIBE_Game::goto_notification_loc(void) */

void __thiscall TRIBE_Game::goto_notification_loc(TRIBE_Game *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  RGE_Player *this_00;
  float fVar4;
  float fVar5;
  long y;
  long x;
  
  iVar1 = this->current_notification_recalled;
  if (iVar1 != -1) {
    iVar2 = this->notification_loc_x[iVar1];
    iVar3 = this->notification_loc_y[iVar1];
    this->current_notification_recalled = iVar1 + -1;
    if (iVar1 + -1 < 0) {
      this->current_notification_recalled = 4;
    }
    if ((this->notification_loc_x[this->current_notification_recalled] == -1) ||
       (this->notification_loc_y[this->current_notification_recalled] == -1)) {
      this->current_notification_recalled = this->current_notification_loc;
    }
    fVar5 = (float)iVar3;
    fVar4 = (float)iVar2;
    this_00 = RGE_Base_Game::get_player((RGE_Base_Game *)this);
    RGE_Player::set_view_loc(this_00,fVar4,fVar5);
  }
  return;
}

// --------------------------------------------------

