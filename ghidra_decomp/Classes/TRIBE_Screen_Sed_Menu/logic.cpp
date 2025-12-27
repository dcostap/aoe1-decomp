// Class: TRIBE_Screen_Sed_Menu
// Function: TRIBE_Screen_Sed_Menu
// Address: 004b2ef0
// [HELPER] s_: ""
// [HELPER] s_Scenario_Editor_Menu: "Scenario Editor Menu"
// [HELPER] s_scr4: "scr4"
/* public: __thiscall TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu(void) */

TRIBE_Screen_Sed_Menu * __thiscall
TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu(TRIBE_Screen_Sed_Menu *this)
{
  TButtonPanel **ppTVar1;
  TButtonPanel *pTVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  TButtonPanel **ppTVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f568;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Scenario_Editor_Menu);
  ppTVar1 = this->button;
  this->_padding_ = (int)&_vftable_;
  this->title = (TTextPanel *)0x0;
  *ppTVar1 = (TButtonPanel *)0x0;
  this->button[1] = (TButtonPanel *)0x0;
  local_4 = 0;
  this->button[2] = (TButtonPanel *)0x0;
  this->button[3] = (TButtonPanel *)0x0;
  this->close_button = (TButtonPanel *)0x0;
  lVar3 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,s_scr4,0xc386,1);
  if (lVar3 == 0) {
    this->_padding_ = 1;
    *unaff_FS_OFFSET = local_c;
    return this;
  }
  TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
                    /* language.dll match for 0x242d: "Scenario Builder" */
  iVar4 = TEasy_Panel::create_text
                    ((TEasy_Panel *)this,(TPanel *)this,&this->title,0x242d,0x14,0x14,600,0x1e,1,1,0
                     ,0);
  if (iVar4 != 0) {
    iVar4 = 0xaa;
    ppTVar6 = ppTVar1;
    do {
      iVar5 = TEasy_Panel::create_button
                        ((TEasy_Panel *)this,(TPanel *)this,ppTVar6,s_,(char *)0x0,0xaa,iVar4,300,
                         0x28,0,0,0);
      if (iVar5 == 0) goto LAB_004b30d3;
      iVar4 = iVar4 + 0x32;
      ppTVar6 = ppTVar6 + 1;
    } while (iVar4 < 0x172);
    ppTVar6 = &this->close_button;
                    /* language.dll match for 0x3ea: "X" */
    iVar4 = TEasy_Panel::create_button
                      ((TEasy_Panel *)this,(TPanel *)this,ppTVar6,0x3ea,0,0,0,0,0,-1,-1,0);
    if (iVar4 != 0) {
      (**(code **)((*ppTVar6)->_padding_ + 0x14))(1);
      (**(code **)((*ppTVar6)->_padding_ + 0x18))(9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
                    /* language.dll match for 0x242e: "Create Scenario" */
      TButtonPanel::set_text(*ppTVar1,0,0x242e);
                    /* language.dll match for 0x242f: "Edit Scenario" */
      TButtonPanel::set_text(this->button[1],0,0x242f);
                    /* language.dll match for 0x2431: "Campaign Editor" */
      TButtonPanel::set_text(this->button[2],0,0x2431);
                    /* language.dll match for 0x2430: "Cancel" */
      TButtonPanel::set_text(this->button[3],0,0x2430);
      pTVar2 = this->button[3];
      pTVar2->hotkey = 0x1b;
      pTVar2->hotkey_shift = 0;
      TPanel::set_tab_order((TPanel *)this,(TPanel **)ppTVar1,4);
      TPanel::set_curr_child((TPanel *)this,(TPanel *)*ppTVar1);
    }
  }
LAB_004b30d3:
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004b30f0
/* public: virtual void * __thiscall TRIBE_Screen_Sed_Menu::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TRIBE_Screen_Sed_Menu::_scalar_deleting_destructor_(TRIBE_Screen_Sed_Menu *this,uint param_1)
{
  ~TRIBE_Screen_Sed_Menu(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Screen_Sed_Menu
// Address: 004b3110
/* public: virtual __thiscall TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu(void) */

void __thiscall TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu(TRIBE_Screen_Sed_Menu *this)
{
  int iVar1;
  TButtonPanel **ppTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f588;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title);
  ppTVar2 = this->button;
  iVar1 = 4;
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
// Address: 004b31a0
/* protected: virtual long __thiscall TRIBE_Screen_Sed_Menu::handle_idle(void) */

long __thiscall TRIBE_Screen_Sed_Menu::handle_idle(TRIBE_Screen_Sed_Menu *this)
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
// Address: 004b31d0
// [HELPER] s_Campaign_Editor_Screen: "Campaign Editor Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Scenario_Editor_Menu: "Scenario Editor Menu"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
/* protected: virtual long __thiscall TRIBE_Screen_Sed_Menu::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TRIBE_Screen_Sed_Menu::action
          (TRIBE_Screen_Sed_Menu *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  TRIBE_Screen_Sed_Open *this_00;
  TRIBE_Campaign_Editor_Screen *this_01;
  TRIBE_Screen_Main_Menu *this_02;
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f5c1;
  *unaff_FS_OFFSET = &local_c;
  if ((param_1 != (TPanel *)0x0) && (param_2 == 1)) {
    if ((TButtonPanel *)param_1 == this->button[0]) {
      TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
      *unaff_FS_OFFSET = local_c;
      return 1;
    }
    if ((TButtonPanel *)param_1 == this->button[1]) {
      this_00 = (TRIBE_Screen_Sed_Open *)operator_new(0x490);
      local_4 = 0;
      if (this_00 != (TRIBE_Screen_Sed_Open *)0x0) {
        TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this_00);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Open,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Menu);
      *unaff_FS_OFFSET = local_c;
      return 1;
    }
    if ((TButtonPanel *)param_1 == this->button[2]) {
      this_01 = (TRIBE_Campaign_Editor_Screen *)operator_new(0x4c4);
      local_4 = 1;
      if (this_01 != (TRIBE_Campaign_Editor_Screen *)0x0) {
        TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen(this_01);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Campaign_Editor_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Menu);
      *unaff_FS_OFFSET = local_c;
      return 1;
    }
    if ((TButtonPanel *)param_1 == this->button[3]) {
      RGE_Base_Game::disable_input(rge_base_game);
                    /* language.dll match for 0x4b0: "Ready" */
      this_02 = (TRIBE_Screen_Main_Menu *)operator_new(0x4b0);
      local_4 = 2;
      if (this_02 != (TRIBE_Screen_Main_Menu *)0x0) {
        TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(this_02);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Menu);
      *unaff_FS_OFFSET = local_c;
      return 1;
    }
    if ((TButtonPanel *)param_1 == this->close_button) {
      RGE_Base_Game::close(rge_base_game);
      *unaff_FS_OFFSET = local_c;
      return 1;
    }
  }
  lVar1 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  *unaff_FS_OFFSET = local_c;
  return lVar1;
}

// --------------------------------------------------

