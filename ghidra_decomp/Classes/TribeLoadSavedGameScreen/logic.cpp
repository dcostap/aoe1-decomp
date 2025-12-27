// Class: TribeLoadSavedGameScreen
// Function: TribeLoadSavedGameScreen
// Address: 0049dd40
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
/* WARNING: Variable defined which should be unmapped: from_panel */
/* public: __thiscall TribeLoadSavedGameScreen::TribeLoadSavedGameScreen(void) */

TribeLoadSavedGameScreen * __thiscall
TribeLoadSavedGameScreen::TribeLoadSavedGameScreen(TribeLoadSavedGameScreen *this)
{
  TListPanel **ppTVar1;
  TButtonPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  char cVar4;
  TDrawArea *pTVar5;
  TButtonPanel *pTVar6;
  char *pcVar7;
  long lVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  undefined4 *unaff_FS_OFFSET;
  int iVar13;
  TEasy_Panel *from_panel;
  TPanel *tabList [4];
  char info_file [260];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055efbb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  info_file._0_4_ = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Load_Saved_Game_Screen);
  ppTVar1 = &this->list;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->screenTitle = (TTextPanel *)0x0;
  this->listTitle = (TTextPanel *)0x0;
  *ppTVar1 = (TListPanel *)0x0;
  this->scrollbar = (TScrollBarPanel *)0x0;
  this->okButton = (TButtonPanel *)0x0;
  this->cancelButton = (TButtonPanel *)0x0;
  this->deleteButton = (TButtonPanel *)0x0;
  tabList[0] = TPanelSystem::currentPanel(&panel_system);
  pcVar7 = TEasy_Panel::get_info_file((TEasy_Panel *)tabList[0]);
  uVar10 = 0xffffffff;
  pcVar9 = info_file;
  do {
    pcVar12 = pcVar7;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar12 = pcVar7 + 1;
    cVar4 = *pcVar7;
    pcVar7 = pcVar12;
  } while (cVar4 != '\0');
  uVar10 = ~uVar10;
  iVar13 = 1;
  pcVar7 = pcVar12 + -uVar10;
  for (uVar11 = uVar10 >> 2; pcVar9 = pcVar9 + 4, uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  pTVar5 = rge_base_game->draw_area;
  lVar8 = TEasy_Panel::get_info_id((TEasy_Panel *)tabList[0]);
  lVar8 = TScreenPanel::setup((TScreenPanel *)this,pTVar5,info_file + 4,lVar8,iVar13);
  if (lVar8 == 0) {
    this->_padding_ = 1;
  }
  else {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)this,0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
                    /* language.dll match for 0x24ff: "Saved Games" */
    iVar13 = TEasy_Panel::create_text
                       ((TEasy_Panel *)this,(TPanel *)this,&this->screenTitle,0x24ff,0x14,10,600,
                        0x1e,1,1,0,0);
    if (iVar13 != 0) {
                    /* language.dll match for 0x2502: "Select Saved Game" */
      iVar13 = TEasy_Panel::create_text
                         ((TEasy_Panel *)this,(TPanel *)this,&this->listTitle,0x2502,0x14,0x2d,600,
                          0x14,4,0,0,0);
      if (iVar13 != 0) {
        iVar13 = TEasy_Panel::create_list
                           ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,0x14,0x41,600,0x160,0xb);
        if (iVar13 != 0) {
          iVar13 = TEasy_Panel::create_auto_scrollbar
                             ((TEasy_Panel *)this,&this->scrollbar,(TTextPanel *)*ppTVar1,0x14);
          if (iVar13 != 0) {
                    /* language.dll match for 0x7670: "Type a name for the game." */
            TPanel::set_help_info((TPanel *)this->scrollbar,0x7670,-1);
            ppTVar2 = &this->okButton;
                    /* language.dll match for 0xfa1: "OK" */
            iVar13 = TEasy_Panel::create_button
                               ((TEasy_Panel *)this,(TPanel *)this,ppTVar2,0xfa1,0,0x1e,0x1b8,0xb4,
                                0x1e,0,0,0);
            if (iVar13 != 0) {
                    /* language.dll match for 0x24c9: "Delete" */
              iVar13 = TEasy_Panel::create_button
                                 ((TEasy_Panel *)this,(TPanel *)this,&this->deleteButton,0x24c9,0,
                                  0xe6,0x1b8,0xb4,0x1e,0,0,0);
              if (iVar13 != 0) {
                ppTVar3 = &this->cancelButton;
                    /* language.dll match for 0xfa2: "Cancel" */
                iVar13 = TEasy_Panel::create_button
                                   ((TEasy_Panel *)this,(TPanel *)this,ppTVar3,0xfa2,0,0x1ae,0x1b8,
                                    0xb4,0x1e,0,0,0);
                if (iVar13 != 0) {
                  TPanel::set_help_info((TPanel *)*ppTVar2,0x7531,-1);
                  TPanel::set_help_info((TPanel *)*ppTVar3,0x7532,-1);
                  pTVar6 = *ppTVar3;
                  pTVar6->hotkey = 0x1b;
                  pTVar6->hotkey_shift = 0;
                  pTVar6 = this->deleteButton;
                  pTVar6->hotkey_shift = 0;
                  pTVar6->hotkey = 0x2e;
                  fillList(this);
                  pcVar9 = TTextPanel::currentLine((TTextPanel *)*ppTVar1);
                  if (*pcVar9 == '\0') {
                    TButtonPanel::set_disabled(*ppTVar2,1);
                    TButtonPanel::set_disabled(this->deleteButton,1);
                  }
                  pcVar9 = TRIBE_Game::get_save_game_name((TRIBE_Game *)rge_base_game);
                  lVar8 = TTextPanel::get_line((TTextPanel *)*ppTVar1,pcVar9);
                  if (lVar8 != -1) {
                    TListPanel::scroll_cur_line(*ppTVar1,'\x01',(short)lVar8,1);
                  }
                  TPanel::set_curr_child((TPanel *)this,(TPanel *)*ppTVar1);
                  tabList[2] = (TPanel *)*ppTVar2;
                  tabList[1] = (TPanel *)*ppTVar1;
                  tabList[3] = (TPanel *)this->deleteButton;
                  TPanel::set_tab_order((TPanel *)this,tabList + 1,4);
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
// Address: 0049e080
/* public: virtual void * __thiscall TribeLoadSavedGameScreen::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
TribeLoadSavedGameScreen::_vector_deleting_destructor_(TribeLoadSavedGameScreen *this,uint param_1)
{
  ~TribeLoadSavedGameScreen(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeLoadSavedGameScreen
// Address: 0049e0a0
/* public: virtual __thiscall TribeLoadSavedGameScreen::~TribeLoadSavedGameScreen(void) */

void __thiscall TribeLoadSavedGameScreen::~TribeLoadSavedGameScreen(TribeLoadSavedGameScreen *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055efd8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->screenTitle);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->listTitle);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->scrollbar);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->okButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->cancelButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->deleteButton);
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: fillList
// Address: 0049e150
// [HELPER] s__s__gam: "%s*.gam"
// [HELPER] s__s__gmx: "%s*.gmx"
/* WARNING: Variable defined which should be unmapped: file_name */
/* protected: void __thiscall TribeLoadSavedGameScreen::fillList(void) */

void __thiscall TribeLoadSavedGameScreen::fillList(TribeLoadSavedGameScreen *this)
{
  char cVar1;
  TListPanel *pTVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char file_name [260];
  _finddata_t fileInfo;
  
  TTextPanel::empty_list((TTextPanel *)this->list);
  this->list->_padding_ = 1;
  sprintf(file_name + 4,s__s__gam,rge_base_game->prog_info->save_dir);
  iVar3 = __findfirst(file_name + 4,&fileInfo.time_create);
  iVar4 = iVar3;
  while (iVar4 != -1) {
    uVar5 = 0xffffffff;
    pcVar6 = fileInfo.name + 4;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    strncpy(file_name + 4,fileInfo.name + 4,~uVar5 - 5);
    pTVar2 = this->list;
    file_name[~uVar5 - 1] = '\0';
    TTextPanel::append_line((TTextPanel *)pTVar2,file_name + 4,0);
    iVar4 = __findnext(iVar3,&fileInfo.time_create);
  }
  sprintf(file_name + 4,s__s__gmx,rge_base_game->prog_info->save_dir);
  iVar3 = __findfirst(file_name + 4,&fileInfo.time_create);
  iVar4 = iVar3;
  do {
    if (iVar4 == -1) {
      return;
    }
    uVar5 = 0xffffffff;
    pcVar6 = fileInfo.name + 4;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    strncpy(file_name + 4,fileInfo.name + 4,~uVar5 - 5);
    pTVar2 = this->list;
    file_name[~uVar5 - 1] = '\0';
    TTextPanel::append_line((TTextPanel *)pTVar2,file_name + 4,0);
    iVar4 = __findnext(iVar3,&fileInfo.time_create);
  } while( true );
}

// --------------------------------------------------

// Function: handle_idle
// Address: 0049e2b0
/* public: virtual long __thiscall TribeLoadSavedGameScreen::handle_idle(void) */

long __thiscall TribeLoadSavedGameScreen::handle_idle(TribeLoadSavedGameScreen *this)
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
// Address: 0049e2e0
// [HELPER] s_Cancel_Dialog: "Cancel Dialog"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
// [HELPER] s__s_gam: "%s.gam"
// [HELPER] s__s_gmx: "%s.gmx"
// [HELPER] s__s_s_gam: "%s%s.gam"
// [HELPER] s__s_s_gmx: "%s%s.gmx"
/* public: virtual long __thiscall TribeLoadSavedGameScreen::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TribeLoadSavedGameScreen::action
          (TribeLoadSavedGameScreen *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  char cVar1;
  byte bVar2;
  RGE_Prog_Info *pRVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  long lVar7;
  char *pcVar8;
  TPanel *pTVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  char *pcVar13;
  undefined4 *unaff_FS_OFFSET;
  bool bVar14;
  char fileName [260];
  char fileNameNoExt [260];
  _finddata_t fileInfo;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055effe;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 != (TPanel *)0x0) {
    pcVar4 = TPanel::panelName(param_1);
    if (pcVar4 != (char *)0x0) {
      pbVar12 = &s_Cancel_Dialog;
      pbVar5 = (byte *)TPanel::panelName(param_1);
      do {
        bVar2 = *pbVar5;
        bVar14 = bVar2 < *pbVar12;
        if (bVar2 != *pbVar12) {
LAB_0049e356:
          iVar6 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
          goto LAB_0049e35b;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar14 = bVar2 < pbVar12[1];
        if (bVar2 != pbVar12[1]) goto LAB_0049e356;
        pbVar5 = pbVar5 + 2;
        pbVar12 = pbVar12 + 2;
      } while (bVar2 != 0);
      iVar6 = 0;
LAB_0049e35b:
      if (iVar6 != 0) goto LAB_0049e444;
      TPanelSystem::destroyPanel(&panel_system,&s_Cancel_Dialog);
      if (param_2 == 0) {
        pRVar3 = rge_base_game->prog_info;
        pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
        sprintf(fileName + 4,s__s_s_gam,pRVar3->save_dir,pcVar4);
        __unlink(fileName + 4);
        pRVar3 = rge_base_game->prog_info;
        pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
        sprintf(fileName + 4,s__s_s_gmx,pRVar3->save_dir,pcVar4);
        __unlink(fileName + 4);
        lVar7 = TTextPanel::get_line((TTextPanel *)this->list);
        TTextPanel::delete_line((TTextPanel *)this->list,lVar7);
        pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
        if (*pcVar4 == '\0') {
          TButtonPanel::set_disabled(this->okButton,1);
          TButtonPanel::set_disabled(this->deleteButton,1);
          lVar7 = 1;
          goto LAB_0049e6b2;
        }
      }
      goto LAB_0049e692;
    }
LAB_0049e444:
    if (((TButtonPanel *)param_1 == this->deleteButton) && (param_2 == 1)) {
      pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
      if (*pcVar4 != '\0') {
                    /* language.dll match for 0x24ca: "Are you sure you want to delete the file
                       \\n'%s'?" */
        TPanel::get_string((TPanel *)this,0x24ca,fileName + 4,0x100);
        pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
        sprintf(&fileInfo.time_create,fileName + 4,pcVar4);
        TEasy_Panel::popupYesNoDialog
                  ((TEasy_Panel *)this,(char *)&fileInfo.time_create,&s_Cancel_Dialog,0x1c2,100);
      }
    }
    if ((TListPanel *)param_1 != this->list) {
      if ((TButtonPanel *)param_1 == this->okButton) {
        if (param_2 != 1) goto LAB_0049e699;
        iVar6 = TTextPanel::numberLines((TTextPanel *)this->list);
        if (0 < iVar6) {
          pcVar8 = TTextPanel::currentLine((TTextPanel *)this->list);
          uVar10 = 0xffffffff;
          pcVar4 = fileNameNoExt;
          do {
            pcVar13 = pcVar8;
            if (uVar10 == 0) break;
            uVar10 = uVar10 - 1;
            pcVar13 = pcVar8 + 1;
            cVar1 = *pcVar8;
            pcVar8 = pcVar13;
          } while (cVar1 != '\0');
          uVar10 = ~uVar10;
          pcVar8 = pcVar13 + -uVar10;
          for (uVar11 = uVar10 >> 2; pcVar4 = pcVar4 + 4, uVar11 != 0; uVar11 = uVar11 - 1) {
            *(undefined4 *)pcVar4 = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
          }
          for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *pcVar4 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            pcVar4 = pcVar4 + 1;
          }
          sprintf(fileName + 4,s__s_s_gmx,rge_base_game->prog_info->save_dir,fileNameNoExt + 4);
          iVar6 = __findfirst(fileName + 4,&fileInfo.time_create);
          if (iVar6 == -1) {
            pcVar4 = s__s_gam;
          }
          else {
            pcVar4 = s__s_gmx;
          }
          sprintf(fileName + 4,pcVar4,fileNameNoExt + 4);
          iVar6 = TRIBE_Game::load_game((TRIBE_Game *)rge_base_game,fileName + 4);
          if (iVar6 == 0) {
                    /* language.dll match for 0x2501: "Cannot load that saved game." */
            TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x2501,(char *)0x0,0x1c2,100);
            lVar7 = 1;
            goto LAB_0049e6b2;
          }
        }
      }
      else {
        if (((TButtonPanel *)param_1 != this->cancelButton) || (param_2 != 1)) goto LAB_0049e699;
        pTVar9 = TPanelSystem::panel(&panel_system,s_Game_Screen);
        if (pTVar9 == (TPanel *)0x0) {
          RGE_Base_Game::disable_input(rge_base_game);
          fileName._0_4_ = operator_new(0x49c);
          local_4 = 0;
          if ((TribeSPMenuScreen *)fileName._0_4_ != (TribeSPMenuScreen *)0x0) {
            TribeSPMenuScreen::TribeSPMenuScreen((TribeSPMenuScreen *)fileName._0_4_);
          }
          local_4 = 0xffffffff;
          pcVar4 = s_Single_Player_Menu;
        }
        else {
          iVar6 = RGE_Base_Game::singlePlayerGame(rge_base_game);
          if ((iVar6 == 1) && (rge_base_game->save_paused == 0)) {
            RGE_Base_Game::set_paused(rge_base_game,0,0);
          }
          pcVar4 = s_Game_Screen;
        }
        TPanelSystem::setCurrentPanel(&panel_system,pcVar4,0);
        TPanelSystem::destroyPanel(&panel_system,s_Load_Saved_Game_Screen);
      }
LAB_0049e692:
      lVar7 = 1;
      goto LAB_0049e6b2;
    }
    if (param_2 == 3) {
      (**(code **)(this->_padding_ + 0xb4))(this->okButton,1,0,0);
      lVar7 = 1;
      goto LAB_0049e6b2;
    }
  }
LAB_0049e699:
  lVar7 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
LAB_0049e6b2:
  *unaff_FS_OFFSET = local_c;
  return lVar7;
}

// --------------------------------------------------

