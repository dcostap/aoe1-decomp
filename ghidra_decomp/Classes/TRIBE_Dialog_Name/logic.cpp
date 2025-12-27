// Class: TRIBE_Dialog_Name
// Function: TRIBE_Dialog_Name
// Address: 004a6d50
// [HELPER] s_: ""
// [HELPER] s_New_Name_Dialog: "New Name Dialog"
/* public: __thiscall TRIBE_Dialog_Name::TRIBE_Dialog_Name(class TScreenPanel *) */

TRIBE_Dialog_Name * __thiscall
TRIBE_Dialog_Name::TRIBE_Dialog_Name(TRIBE_Dialog_Name *this,TScreenPanel *param_1)
{
  TEditPanel **ppTVar1;
  TButtonPanel *pTVar2;
  long lVar3;
  char *pcVar4;
  TDrawArea *pTVar5;
  undefined4 *unaff_FS_OFFSET;
  long lVar6;
  long lVar7;
  int iVar8;
  TPanel *tab_list [3];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f358;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  tab_list[0] = (TPanel *)this;
  TDialogPanel::TDialogPanel((TDialogPanel *)this,&s_New_Name_Dialog);
  ppTVar1 = &this->name_input;
  iVar8 = 1;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->title = (TTextPanel *)0x0;
  this->name_text = (TTextPanel *)0x0;
  *ppTVar1 = (TEditPanel *)0x0;
  this->ok_button = (TButtonPanel *)0x0;
  this->cancel_button = (TButtonPanel *)0x0;
  lVar3 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)param_1);
  pcVar4 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)param_1);
  lVar7 = 0xe6;
  lVar6 = 500;
  pTVar5 = TPanel::renderArea((TPanel *)param_1);
  iVar8 = TDialogPanel::setup((TDialogPanel *)this,pTVar5,(TPanel *)param_1,lVar6,lVar7,pcVar4,lVar3
                              ,iVar8);
  if (iVar8 != 0) {
                    /* language.dll match for 0x2a03: "Name" */
    iVar8 = TEasy_Panel::create_text
                      ((TEasy_Panel *)this,(TPanel *)this,&this->title,0x2a03,0x14,0x14,0x1cc,0x1e,1
                       ,1,1,0);
    if (iVar8 != 0) {
                    /* language.dll match for 0x2a04: "New Player" */
      iVar8 = TEasy_Panel::create_text
                        ((TEasy_Panel *)this,(TPanel *)this,&this->name_text,0x2a04,0x28,0x55,0x1a4,
                         0x14,4,0,1,0);
      if (iVar8 != 0) {
                    /* language.dll match for 0x6e: "Copperplate Gothic Light" */
        iVar8 = TEasy_Panel::create_edit
                          ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,s_,0xf,FormatText,0x28,0x6e,
                           0x1a4,0x17,0xb,1,1);
        if (iVar8 != 0) {
                    /* language.dll match for 0xfa1: "OK" */
          iVar8 = TEasy_Panel::create_button
                            ((TEasy_Panel *)this,(TPanel *)this,&this->ok_button,0xfa1,0,0x3c,0xb4,
                             0xb4,0x1e,0,0,0);
          if (iVar8 != 0) {
                    /* language.dll match for 0xfa2: "Cancel" */
            iVar8 = TEasy_Panel::create_button
                              ((TEasy_Panel *)this,(TPanel *)this,&this->cancel_button,0xfa2,0,0x104
                               ,0xb4,0xb4,0x1e,0,0,0);
            if (iVar8 != 0) {
              pTVar2 = this->cancel_button;
              pTVar2->hotkey = 0x1b;
              pTVar2->hotkey_shift = 0;
              tab_list[1] = (TPanel *)*ppTVar1;
              tab_list[2] = (TPanel *)this->ok_button;
              TPanel::set_tab_order((TPanel *)this,tab_list + 1,3);
              TPanel::set_curr_child((TPanel *)this,(TPanel *)*ppTVar1);
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
// Address: 004a6f40
/* public: virtual void * __thiscall TRIBE_Dialog_Name::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Dialog_Name::_scalar_deleting_destructor_(TRIBE_Dialog_Name *this,uint param_1)
{
  ~TRIBE_Dialog_Name(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Dialog_Name
// Address: 004a6f60
/* public: virtual __thiscall TRIBE_Dialog_Name::~TRIBE_Dialog_Name(void) */

void __thiscall TRIBE_Dialog_Name::~TRIBE_Dialog_Name(TRIBE_Dialog_Name *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f378;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->name_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->name_input);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->ok_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->cancel_button);
  local_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel((TDialogPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 004a6ff0
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_Name_Selection_Screen: "Name Selection Screen"
// [HELPER] s_New_Name_Dialog: "New Name Dialog"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
/* public: virtual long __thiscall TRIBE_Dialog_Name::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TRIBE_Dialog_Name::action
          (TRIBE_Dialog_Name *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  RGE_Game_Info *this_00;
  char *pcVar1;
  TRIBE_Screen_Campaign_Selection *this_01;
  TPanel *pTVar2;
  TribeSPMenuScreen *this_02;
  long lVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f3a6;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 != (TPanel *)0x0) {
    if ((((TButtonPanel *)param_1 == this->ok_button) && (param_2 == 1)) ||
       (((TEditPanel *)param_1 == this->name_input && (param_2 == 0)))) {
      pcVar1 = TEditPanel::get_text(this->name_input);
      if (*pcVar1 == '\0') {
        TPanel::set_curr_child((TPanel *)this,(TPanel *)this->name_input);
        *unaff_FS_OFFSET = local_c;
        return 1;
      }
      this_00 = rge_base_game->player_game_info;
      pcVar1 = TEditPanel::get_text(this->name_input);
      RGE_Game_Info::add_new_person(this_00,pcVar1);
      this_01 = (TRIBE_Screen_Campaign_Selection *)operator_new(0x4cc);
      local_4 = 0;
      if (this_01 != (TRIBE_Screen_Campaign_Selection *)0x0) {
        TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection(this_01);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Campaign_Selection_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,&s_New_Name_Dialog);
      TPanelSystem::destroyPanel(&panel_system,s_Name_Selection_Screen);
      *unaff_FS_OFFSET = local_c;
      return 1;
    }
    if ((((TButtonPanel *)param_1 == this->cancel_button) && (param_2 == 1)) ||
       (((TEditPanel *)param_1 == this->name_input && (param_2 == 1)))) {
      pTVar2 = TPanelSystem::panel(&panel_system,s_Name_Selection_Screen);
      if (pTVar2 == (TPanel *)0x0) {
        this_02 = (TribeSPMenuScreen *)operator_new(0x49c);
        local_4 = 1;
        if (this_02 != (TribeSPMenuScreen *)0x0) {
          TribeSPMenuScreen::TribeSPMenuScreen(this_02);
        }
        local_4 = 0xffffffff;
        pcVar1 = s_Single_Player_Menu;
      }
      else {
        pcVar1 = s_Name_Selection_Screen;
      }
      TPanelSystem::setCurrentPanel(&panel_system,pcVar1,0);
      TPanelSystem::destroyPanel(&panel_system,&s_New_Name_Dialog);
      *unaff_FS_OFFSET = local_c;
      return 1;
    }
  }
  lVar3 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  *unaff_FS_OFFSET = local_c;
  return lVar3;
}

// --------------------------------------------------

// Function: wnd_proc
// Address: 004a71d0
/* public: virtual long __thiscall TRIBE_Dialog_Name::wnd_proc(void *,unsigned int,unsigned
   int,long) */

long __thiscall
TRIBE_Dialog_Name::wnd_proc
          (TRIBE_Dialog_Name *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  long lVar1;
  
  lVar1 = TPanel::wnd_proc((TPanel *)this,param_1,param_2,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

