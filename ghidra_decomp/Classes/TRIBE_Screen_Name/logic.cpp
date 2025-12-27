// Class: TRIBE_Screen_Name
// Function: TRIBE_Screen_Name
// Address: 004a63d0
// [HELPER] s_Name_Selection_Screen: "Name Selection Screen"
// [HELPER] s_scr2: "scr2"
/* public: __thiscall TRIBE_Screen_Name::TRIBE_Screen_Name(void) */

TRIBE_Screen_Name * __thiscall TRIBE_Screen_Name::TRIBE_Screen_Name(TRIBE_Screen_Name *this)
{
  TButtonPanel **ppTVar1;
  TButtonPanel *pTVar2;
  long lVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f2d8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Name_Selection_Screen);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  init_vars(this);
  lVar3 = TEasy_Panel::setup((TEasy_Panel *)this,rge_base_game->draw_area,(TPanel *)0x0,&s_scr2,
                             0xc384,1,0,0,0,0,1);
  if (lVar3 == 0) {
    this->_padding_ = 1;
    *unaff_FS_OFFSET = local_c;
    return this;
  }
  TEasy_Panel::setup_shadow_area((TEasy_Panel *)this,0);
  TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
                    /* language.dll match for 0x29fe: "Select Player" */
  iVar4 = TEasy_Panel::create_text
                    ((TEasy_Panel *)this,(TPanel *)this,&this->title,0x29fe,0x14,0x14,600,0x1e,1,1,0
                     ,0);
  if (iVar4 != 0) {
                    /* language.dll match for 0x29ff: "Name" */
    iVar4 = TEasy_Panel::create_text
                      ((TEasy_Panel *)this,(TPanel *)this,&this->name_text,0x29ff,0x3c,0x50,0x8c,
                       0x14,4,0,0,0);
    if (iVar4 != 0) {
      iVar4 = TEasy_Panel::create_list
                        ((TEasy_Panel *)this,(TPanel *)this,&this->name_list,0x3c,100,0x14a,300,0xb)
      ;
      if (iVar4 != 0) {
        iVar4 = TEasy_Panel::create_auto_scrollbar
                          ((TEasy_Panel *)this,&this->name_scrollbar,(TTextPanel *)this->name_list,
                           0x14);
        if (iVar4 != 0) {
                    /* language.dll match for 0x765c: "Select a player name." */
          TPanel::set_help_info((TPanel *)this->name_scrollbar,0x765c,-1);
                    /* language.dll match for 0x2a00: "New" */
          iVar4 = TEasy_Panel::create_button
                            ((TEasy_Panel *)this,(TPanel *)this,&this->new_button,0x2a00,0,400,100,
                             0xb4,0x1e,0,0,0);
          if (iVar4 != 0) {
                    /* language.dll match for 0x765d: "Click to add a new player name." */
            TPanel::set_help_info((TPanel *)this->new_button,0x765d,-1);
                    /* language.dll match for 0x2a01: "Remove" */
            iVar4 = TEasy_Panel::create_button
                              ((TEasy_Panel *)this,(TPanel *)this,&this->remove_button,0x2a01,0,400,
                               0x8c,0xb4,0x1e,0,0,0);
            if (iVar4 != 0) {
                    /* language.dll match for 0x765e: "Click to remove a player name." */
              TPanel::set_help_info((TPanel *)this->remove_button,0x765e,-1);
                    /* language.dll match for 0xfa1: "OK" */
              iVar4 = TEasy_Panel::create_button
                                ((TEasy_Panel *)this,(TPanel *)this,&this->ok_button,0xfa1,0,0x46,
                                 0x1b8,0xf0,0x1e,0,0,0);
              if (iVar4 != 0) {
                TPanel::set_help_info((TPanel *)this->ok_button,0x7531,-1);
                ppTVar1 = &this->cancel_button;
                    /* language.dll match for 0xfa2: "Cancel" */
                iVar4 = TEasy_Panel::create_button
                                  ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,0xfa2,0,0x14a,0x1b8,
                                   0xf0,0x1e,0,0,0);
                if (iVar4 != 0) {
                  TPanel::set_help_info((TPanel *)*ppTVar1,0x7532,-1);
                  pTVar2 = *ppTVar1;
                  pTVar2->hotkey = 0x1b;
                  pTVar2->hotkey_shift = 0;
                    /* language.dll match for 0x3ea: "X" */
                  iVar4 = TEasy_Panel::create_button
                                    ((TEasy_Panel *)this,(TPanel *)this,&this->close_button,0x3ea,0,
                                     0,0,0,0,-1,-1,0);
                  if (iVar4 != 0) {
                    (**(code **)(this->close_button->_padding_ + 0x18))
                              (9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
                    setup_tab_order(this);
                    get_player_names(this);
                    this->started_input = 0;
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
// Address: 004a66c0
/* public: virtual void * __thiscall TRIBE_Screen_Name::`vector deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Screen_Name::_vector_deleting_destructor_(TRIBE_Screen_Name *this,uint param_1)
{
  ~TRIBE_Screen_Name(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Screen_Name
// Address: 004a66e0
// [HELPER] s_New_Name_Dialog: "New Name Dialog"
/* public: virtual __thiscall TRIBE_Screen_Name::~TRIBE_Screen_Name(void) */

void __thiscall TRIBE_Screen_Name::~TRIBE_Screen_Name(TRIBE_Screen_Name *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f2f8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanelSystem::setCurrentPanel(&panel_system,&s_New_Name_Dialog,0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->name_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->name_list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->name_scrollbar);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->new_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->remove_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->ok_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->cancel_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->close_button);
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: init_vars
// Address: 004a67c0
/* public: void __thiscall TRIBE_Screen_Name::init_vars(void) */

void __thiscall TRIBE_Screen_Name::init_vars(TRIBE_Screen_Name *this)
{
  this->title = (TTextPanel *)0x0;
  this->name_text = (TTextPanel *)0x0;
  this->name_list = (TListPanel *)0x0;
  this->name_scrollbar = (TScrollBarPanel *)0x0;
  this->new_button = (TButtonPanel *)0x0;
  this->remove_button = (TButtonPanel *)0x0;
  this->ok_button = (TButtonPanel *)0x0;
  this->cancel_button = (TButtonPanel *)0x0;
  this->close_button = (TButtonPanel *)0x0;
  return;
}

// --------------------------------------------------

// Function: get_player_names
// Address: 004a6800
/* WARNING: Variable defined which should be unmapped: players */
/* protected: void __thiscall TRIBE_Screen_Name::get_player_names(void) */

void __thiscall TRIBE_Screen_Name::get_player_names(TRIBE_Screen_Name *this)
{
  long lVar1;
  long lVar2;
  int iVar3;
  char **players;
  long curr_player;
  long local_4;
  
  TTextPanel::empty_list((TTextPanel *)this->name_list);
  curr_player = 0;
  lVar1 = RGE_Game_Info::get_people_list
                    (rge_base_game->player_game_info,(char ***)&curr_player,&local_4);
  if (lVar1 != 0) {
    iVar3 = 0;
    this->name_list->_padding_ = 1;
    if (0 < lVar1) {
      do {
        TTextPanel::append_line
                  ((TTextPanel *)this->name_list,*(char **)(curr_player + iVar3 * 4),iVar3);
        iVar3 = iVar3 + 1;
      } while (iVar3 < lVar1);
    }
    lVar2 = TTextPanel::get_line((TTextPanel *)this->name_list,local_4);
    TTextPanel::set_line((TTextPanel *)this->name_list,lVar2);
    iVar3 = 0;
    if (0 < lVar1) {
      do {
        free(*(undefined4 *)(curr_player + iVar3 * 4));
        iVar3 = iVar3 + 1;
      } while (iVar3 < lVar1);
    }
    free(curr_player);
  }
  return;
}

// --------------------------------------------------

// Function: setup_tab_order
// Address: 004a68c0
/* WARNING: Variable defined which should be unmapped: tab_list */
/* protected: void __thiscall TRIBE_Screen_Name::setup_tab_order(void) */

void __thiscall TRIBE_Screen_Name::setup_tab_order(TRIBE_Screen_Name *this)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  TPanel *tab_list [5];
  
  iVar2 = TTextPanel::numberLines((TTextPanel *)this->name_list);
  uVar3 = (uint)(iVar2 == 0);
  TButtonPanel::set_disabled(this->remove_button,uVar3);
  TButtonPanel::set_disabled(this->ok_button,uVar3);
  tab_list[1] = (TPanel *)this->name_list;
  tab_list[2] = (TPanel *)this->new_button;
  iVar2 = 2;
  if (uVar3 == 0) {
    tab_list[4] = (TPanel *)this->ok_button;
    tab_list[3] = (TPanel *)this->remove_button;
    iVar2 = 4;
  }
  iVar1 = this->_padding_;
  tab_list[iVar2 + 1] = (TPanel *)this->cancel_button;
  (**(code **)(iVar1 + 200))(tab_list + 1,iVar2 + 1);
  iVar2 = TTextPanel::numberLines((TTextPanel *)this->name_list);
  if (iVar2 == 0) {
    TPanel::set_curr_child((TPanel *)this,(TPanel *)this->new_button);
    return;
  }
  TPanel::set_curr_child((TPanel *)this,(TPanel *)this->name_list);
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 004a6980
/* public: virtual long __thiscall TRIBE_Screen_Name::handle_idle(void) */

long __thiscall TRIBE_Screen_Name::handle_idle(TRIBE_Screen_Name *this)
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
// Address: 004a69b0
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_Name_Selection_Screen: "Name Selection Screen"
// [HELPER] s_New_Name_Dialog: "New Name Dialog"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
// [HELPER] s_YesNoDialog: "YesNoDialog"
/* public: virtual long __thiscall TRIBE_Screen_Name::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TRIBE_Screen_Name::action
          (TRIBE_Screen_Name *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  byte bVar1;
  RGE_Game_Info *pRVar2;
  long lVar3;
  char *pcVar4;
  char *pcVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 *unaff_FS_OFFSET;
  bool bVar9;
  char str [256];
  undefined4 local_c;
  code *pcStack_8;
  long local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f33a;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 == (TPanel *)0x0) goto LAB_004a6d0e;
  if (((TButtonPanel *)param_1 == this->ok_button) && (param_2 == 1)) {
    lVar3 = TTextPanel::get_line((TTextPanel *)this->name_list);
    if (lVar3 != -1) {
      RGE_Base_Game::disable_input(rge_base_game);
      pRVar2 = rge_base_game->player_game_info;
      lVar3 = TTextPanel::get_id((TTextPanel *)this->name_list);
      RGE_Game_Info::set_current_person(pRVar2,lVar3);
      str._0_4_ = operator_new(0x4cc);
      local_4 = 0;
      if ((TRIBE_Screen_Campaign_Selection *)str._0_4_ != (TRIBE_Screen_Campaign_Selection *)0x0) {
        TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection
                  ((TRIBE_Screen_Campaign_Selection *)str._0_4_);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Campaign_Selection_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Name_Selection_Screen);
      param_2 = 1;
    }
    goto LAB_004a6d27;
  }
  if (((TButtonPanel *)param_1 == this->cancel_button) && (param_2 == 1)) {
    RGE_Base_Game::disable_input(rge_base_game);
    str._0_4_ = operator_new(0x49c);
    local_4 = param_2;
    if ((TribeSPMenuScreen *)str._0_4_ != (TribeSPMenuScreen *)0x0) {
      TribeSPMenuScreen::TribeSPMenuScreen((TribeSPMenuScreen *)str._0_4_);
    }
    local_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Single_Player_Menu,0);
    TPanelSystem::destroyPanel(&panel_system,s_Name_Selection_Screen);
    param_2 = 1;
    goto LAB_004a6d27;
  }
  if ((TButtonPanel *)param_1 == this->close_button) {
    RGE_Base_Game::close(rge_base_game);
    param_2 = 1;
    goto LAB_004a6d27;
  }
  if (((TListPanel *)param_1 == this->name_list) && (param_2 == 3)) {
    (**(code **)(this->_padding_ + 0xb4))(this->ok_button,1,0,0);
    param_2 = 1;
    goto LAB_004a6d27;
  }
  if (((TButtonPanel *)param_1 == this->new_button) && (param_2 == 1)) {
    str._0_4_ = operator_new(0x4a4);
    local_4 = 2;
    if ((TRIBE_Dialog_Name *)str._0_4_ != (TRIBE_Dialog_Name *)0x0) {
      TRIBE_Dialog_Name::TRIBE_Dialog_Name((TRIBE_Dialog_Name *)str._0_4_,(TScreenPanel *)this);
    }
    local_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,&s_New_Name_Dialog,0);
    param_2 = 1;
    goto LAB_004a6d27;
  }
  if (((TButtonPanel *)param_1 == this->remove_button) && (param_2 == 1)) {
    lVar3 = TTextPanel::get_line((TTextPanel *)this->name_list);
    if (lVar3 != -1) {
      pcVar4 = TTextPanel::get_text((TTextPanel *)this->name_list);
                    /* language.dll match for 0x2a02: "Are you sure you want to remove player %s?"
                        */
      pcVar5 = TPanel::get_string((TPanel *)this,0x2a02);
      sprintf(str + 4,pcVar5,pcVar4);
      TEasy_Panel::popupYesNoDialog((TEasy_Panel *)this,str + 4,(char *)0x0,0x1c2,100);
      goto LAB_004a6d27;
    }
  }
  else {
    pcVar4 = TPanel::panelName(param_1);
    if (pcVar4 == (char *)0x0) {
LAB_004a6c71:
      pcVar4 = TPanel::panelName(param_1);
      if (pcVar4 != (char *)0x0) {
        pbVar8 = &s_YesNoDialog;
        pbVar6 = (byte *)TPanel::panelName(param_1);
        do {
          bVar1 = *pbVar6;
          bVar9 = bVar1 < *pbVar8;
          if (bVar1 != *pbVar8) {
LAB_004a6cb0:
            iVar7 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_004a6cb5;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar6[1];
          bVar9 = bVar1 < pbVar8[1];
          if (bVar1 != pbVar8[1]) goto LAB_004a6cb0;
          pbVar6 = pbVar6 + 2;
          pbVar8 = pbVar8 + 2;
        } while (bVar1 != 0);
        iVar7 = 0;
LAB_004a6cb5:
        if (iVar7 == 0) {
          if ((param_2 == 0) &&
             (lVar3 = TTextPanel::get_line((TTextPanel *)this->name_list), lVar3 != -1)) {
            pRVar2 = rge_base_game->player_game_info;
            lVar3 = TTextPanel::get_id((TTextPanel *)this->name_list,lVar3);
            RGE_Game_Info::remove_player(pRVar2,lVar3);
            get_player_names(this);
          }
          pcVar4 = &s_YesNoDialog;
          goto LAB_004a6cf6;
        }
      }
LAB_004a6d0e:
      param_2 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
      goto LAB_004a6d27;
    }
    pbVar8 = &s_New_Name_Dialog;
    pbVar6 = (byte *)TPanel::panelName(param_1);
    do {
      bVar1 = *pbVar6;
      bVar9 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_004a6c41:
        iVar7 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_004a6c46;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar6[1];
      bVar9 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_004a6c41;
      pbVar6 = pbVar6 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    iVar7 = 0;
LAB_004a6c46:
    if (iVar7 != 0) goto LAB_004a6c71;
    if (param_2 == 1) {
      get_player_names(this);
    }
    TPanelSystem::setCurrentPanel(&panel_system,s_Name_Selection_Screen,0);
    pcVar4 = &s_New_Name_Dialog;
LAB_004a6cf6:
    TPanelSystem::destroyPanel(&panel_system,pcVar4);
    setup_tab_order(this);
  }
  param_2 = 1;
LAB_004a6d27:
  *unaff_FS_OFFSET = local_c;
  return param_2;
}

// --------------------------------------------------

