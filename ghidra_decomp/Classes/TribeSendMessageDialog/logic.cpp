// Class: TribeSendMessageDialog
// Function: TribeSendMessageDialog
// Address: 004407a0
// [HELPER] s_: ""
// [HELPER] s_Send_Message_Dialog: "Send Message Dialog"
// [HELPER] s_dlg_plbn_shp: "dlg_plbn.shp"
/* public: __thiscall TribeSendMessageDialog::TribeSendMessageDialog(class TScreenPanel *) */

TribeSendMessageDialog * __thiscall
TribeSendMessageDialog::TribeSendMessageDialog(TribeSendMessageDialog *this,TScreenPanel *param_1)
{
  RGE_Game_World *pRVar1;
  TButtonPanel *pTVar2;
  byte bVar3;
  TTextPanel **ppTVar4;
  TButtonPanel **ppTVar5;
  TShape *pTVar6;
  long lVar7;
  char *pcVar8;
  TDrawArea *pTVar9;
  int iVar10;
  int iVar11;
  RGE_Game_World *pRVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  TButtonPanel **ppTVar16;
  undefined4 *unaff_FS_OFFSET;
  long lVar17;
  long lVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int i;
  int humanity;
  RGE_Game_World *world;
  int id;
  char temp_str [100];
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d223;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  temp_str._0_4_ = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)this,s_Send_Message_Dialog);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->title = (TTextPanel *)0x0;
  ppTVar4 = this->playerCivilization;
  iVar13 = 8;
  do {
    ppTVar4[-8] = (TTextPanel *)0x0;
    *ppTVar4 = (TTextPanel *)0x0;
    ppTVar4[8] = (TTextPanel *)0x0;
    ppTVar4[0x1e] = (TTextPanel *)0x0;
    ppTVar4 = ppTVar4 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  ppTVar5 = this->radioButton;
  iVar13 = 3;
  do {
    ppTVar5[-4] = (TButtonPanel *)0x0;
    *ppTVar5 = (TButtonPanel *)0x0;
    ppTVar5 = ppTVar5 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  this->chatInput = (TEditPanel *)0x0;
  this->chatTitle = (TTextPanel *)0x0;
  this->okButton = (TButtonPanel *)0x0;
  this->help_button = (TButtonPanel *)0x0;
  this->backgroundPics = (TShape *)0x0;
  pTVar6 = (TShape *)operator_new(0x20);
  local_4._0_1_ = 1;
  if (pTVar6 == (TShape *)0x0) {
    pTVar6 = (TShape *)0x0;
  }
  else {
    pTVar6 = (TShape *)TShape::TShape(pTVar6,s_dlg_plbn_shp,0xc63a);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  this->backgroundPics = pTVar6;
  if (pTVar6 != (TShape *)0x0) {
    iVar13 = 1;
    lVar7 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)param_1);
    pcVar8 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)param_1);
    lVar18 = 0x1d1;
    lVar17 = 0x208;
    pTVar9 = TPanel::renderArea((TPanel *)param_1);
    iVar13 = TDialogPanel::setup((TDialogPanel *)this,pTVar9,(TPanel *)param_1,lVar17,lVar18,pcVar8,
                                 lVar7,iVar13);
                    /* language.dll match for 0x2667: "Send Messages to" */
    if ((iVar13 != 0) &&
       (iVar13 = TEasy_Panel::create_text
                           ((TEasy_Panel *)this,(TPanel *)this,&this->title,0x2667,5,10,
                            this->_padding_ + -0x28,0x1e,1,1,1,0), iVar13 != 0)) {
      i = (int)this->checkButton;
      humanity = 1;
      pRVar1 = rge_base_game->world;
      iVar13 = 0x28;
      do {
        iVar10 = RGE_Base_Game::playerID(rge_base_game,humanity);
        if (iVar10 != 0) {
          bVar3 = 0;
          if (pRVar1->players[iVar10]->game_status == '\x02') {
LAB_004409b4:
            bVar3 = 1;
          }
          else {
            iVar11 = RGE_Base_Game::multiplayerGame(rge_base_game);
            if (iVar11 != 0) {
              world = (RGE_Game_World *)0x0;
              uVar14 = 1;
              iVar11 = RGE_Base_Game::numberPlayers(rge_base_game);
              if (0 < iVar11) {
                do {
                  iVar11 = RGE_Base_Game::playerID(rge_base_game,uVar14);
                  if ((iVar11 == iVar10) &&
                     ((pRVar12 = (RGE_Game_World *)
                                 TCommunications_Handler::GetPlayerHumanity(comm,uVar14),
                      pRVar12 == (RGE_Game_World *)0x2 || (pRVar12 == (RGE_Game_World *)0x4)))) {
                    world = pRVar12;
                  }
                  uVar14 = uVar14 + 1;
                  iVar11 = RGE_Base_Game::numberPlayers(rge_base_game);
                } while ((int)uVar14 <= iVar11);
              }
              if ((world != (RGE_Game_World *)0x2) && (world != (RGE_Game_World *)0x4))
              goto LAB_004409b4;
            }
          }
          iVar21 = 0;
          iVar20 = 1;
          iVar15 = (-(uint)bVar3 & 0xfffffffd) + 0xb;
          iVar19 = 0;
          lVar18 = 0x1e;
          lVar17 = 0xbe;
          lVar7 = 0x32;
          iVar11 = iVar13;
          pcVar8 = TCommunications_Handler::GetPlayerName(comm,humanity);
          iVar11 = TEasy_Panel::create_text
                             ((TEasy_Panel *)this,(TPanel *)this,(TTextPanel **)(i + -0x40),pcVar8,
                              lVar7,iVar11,lVar17,lVar18,iVar15,iVar19,iVar20,iVar21);
          if (iVar11 == 0) goto LAB_00440dda;
          (**(code **)(rge_base_game->_padding_ + 0x28))
                    (0x69,pRVar1->players[iVar10]->master_player_id,0,temp_str + 4,100);
                    /* language.dll match for 0x78: "10" */
          iVar10 = TEasy_Panel::create_text
                             ((TEasy_Panel *)this,(TPanel *)this,(TTextPanel **)(i + -0x20),
                              temp_str + 4,0x104,iVar13,0x78,0x1e,0xb,0,1,0);
          if (iVar10 == 0) goto LAB_00440dda;
          iVar10 = TCommunications_Handler::WhoAmI(comm);
          if ((humanity != iVar10) &&
             ((iVar10 = TCommunications_Handler::GetPlayerHumanity(comm,humanity), iVar10 == 2 ||
              (iVar10 = TCommunications_Handler::GetPlayerHumanity(comm,humanity), iVar10 == 4)))) {
            iVar10 = TEasy_Panel::create_check_box
                               ((TEasy_Panel *)this,(TPanel *)this,(TButtonPanel **)i,10,iVar13,0x1e
                                ,0x1e,0,0);
            if (iVar10 == 0) goto LAB_00440dda;
                    /* language.dll match for 0x767f: "Click to send a message to this player." */
            TPanel::set_help_info(*(TPanel **)i,0x767f,-1);
            iVar10 = TChat::inChatGroup(chat,humanity);
            if (iVar10 == 0) {
              (**(code **)(**(int **)i + 0xe0))(0);
            }
            else {
              (**(code **)(**(int **)i + 0xe0))(1);
            }
          }
          *(int *)(i + 0x58) = humanity;
          i = i + 4;
          iVar13 = iVar13 + 0x1e;
        }
        humanity = humanity + 1;
      } while (humanity < 9);
                    /* language.dll match for 0x2668: "Chat" */
      iVar13 = TEasy_Panel::create_text
                         ((TEasy_Panel *)this,(TPanel *)this,&this->chatTitle,0x2668,10,0x13b,0x78,
                          0x1e,4,1,1,0);
      if (iVar13 != 0) {
                    /* language.dll match for 0x82: "B" */
        iVar13 = TEasy_Panel::create_edit
                           ((TEasy_Panel *)this,(TPanel *)this,&this->chatInput,s_,0x41,FormatText,
                            0x82,0x13b,0x17c,0x17,0xb,1,0);
        if (iVar13 != 0) {
                    /* language.dll match for 0x767a: "Type a message. Press ENTER to send." */
          TPanel::set_help_info((TPanel *)this->chatInput,0x767a,-1);
          ppTVar5 = this->radioButton;
          iVar13 = TEasy_Panel::create_radio_button
                             ((TEasy_Panel *)this,(TPanel *)this,ppTVar5,0x2d,0x15e,0x1e,0x1e,0,0);
          if ((((iVar13 != 0) &&
               (iVar13 = TEasy_Panel::create_radio_button
                                   ((TEasy_Panel *)this,(TPanel *)this,this->radioButton + 1,0x113,
                                    0x15e,0x1e,0x1e,0,0), iVar13 != 0)) &&
              (iVar13 = TEasy_Panel::create_radio_button
                                  ((TEasy_Panel *)this,(TPanel *)this,this->radioButton + 2,0x2d,
                                   0x181,0x1e,0x1e,0,0), iVar13 != 0)) &&
             (iVar13 = TEasy_Panel::create_radio_button
                                 ((TEasy_Panel *)this,(TPanel *)this,this->radioButton + 3,0x113,
                                  0x181,0x1e,0x1e,0,0), iVar13 != 0)) {
                    /* language.dll match for 0x2669: "Allies" */
            iVar13 = TEasy_Panel::create_text
                               ((TEasy_Panel *)this,(TPanel *)this,this->radioTitle,0x2669,0x4b,
                                0x15e,200,0x1e,0xb,0,1,0);
            if (iVar13 != 0) {
              TPanel::set_help_info((TPanel *)this->radioTitle[0],-1,-1);
                    /* language.dll match for 0x266a: "Enemies" */
              iVar13 = TEasy_Panel::create_text
                                 ((TEasy_Panel *)this,(TPanel *)this,this->radioTitle + 1,0x266a,
                                  0x131,0x15e,200,0x1e,0xb,0,1,0);
              if (iVar13 != 0) {
                TPanel::set_help_info((TPanel *)this->radioTitle[1],-1,-1);
                    /* language.dll match for 0x266b: "Everyone" */
                iVar13 = TEasy_Panel::create_text
                                   ((TEasy_Panel *)this,(TPanel *)this,this->radioTitle + 2,0x266b,
                                    0x4b,0x181,200,0x1e,0xb,0,1,0);
                if (iVar13 != 0) {
                  TPanel::set_help_info((TPanel *)this->radioTitle[2],-1,-1);
                    /* language.dll match for 0x266e: "Select Player" */
                  iVar13 = TEasy_Panel::create_text
                                     ((TEasy_Panel *)this,(TPanel *)this,this->radioTitle + 3,0x266e
                                      ,0x131,0x181,200,0x1e,0xb,0,1,0);
                  if (iVar13 != 0) {
                    TPanel::set_help_info((TPanel *)this->radioTitle[3],-1,-1);
                    iVar13 = 4;
                    ppTVar16 = ppTVar5;
                    do {
                      TButtonPanel::set_radio_info(*ppTVar16,ppTVar5,4);
                      ppTVar16 = ppTVar16 + 1;
                      iVar13 = iVar13 + -1;
                    } while (iVar13 != 0);
                    (**(code **)(this->radioButton[3]->_padding_ + 0xe0))(1);
                    /* language.dll match for 0x767b: "Click to send a message to all allies." */
                    TPanel::set_help_info((TPanel *)*ppTVar5,0x767b,-1);
                    /* language.dll match for 0x767c: "Click to send a message to all enemies." */
                    TPanel::set_help_info((TPanel *)this->radioButton[1],0x767c,-1);
                    /* language.dll match for 0x767d: "Click to send a message to all players." */
                    TPanel::set_help_info((TPanel *)this->radioButton[2],0x767d,-1);
                    /* language.dll match for 0x767e: "Select which players receive your messages."
                        */
                    TPanel::set_help_info((TPanel *)this->radioButton[3],0x767e,-1);
                    ppTVar5 = &this->okButton;
                    /* language.dll match for 0x266c: "Return to Game" */
                    iVar13 = TEasy_Panel::create_button
                                       ((TEasy_Panel *)this,(TPanel *)this,ppTVar5,0x266c,0,100,
                                        0x1a9,300,0x1e,0,0,0);
                    if (iVar13 != 0) {
                      TPanel::set_help_info((TPanel *)*ppTVar5,0x7531,-1);
                      pTVar2 = *ppTVar5;
                      pTVar2->hotkey = 0x1b;
                      pTVar2->hotkey_shift = 0;
                      TPanel::set_curr_child((TPanel *)this,(TPanel *)this->chatInput);
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
LAB_00440dda:
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00440e00
/* public: virtual void * __thiscall TribeSendMessageDialog::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TribeSendMessageDialog::_scalar_deleting_destructor_(TribeSendMessageDialog *this,uint param_1)
{
  ~TribeSendMessageDialog(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeSendMessageDialog
// Address: 00440e20
/* public: virtual __thiscall TribeSendMessageDialog::~TribeSendMessageDialog(void) */

void __thiscall TribeSendMessageDialog::~TribeSendMessageDialog(TribeSendMessageDialog *this)
{
  TShape *this_00;
  int iVar1;
  TTextPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055d238;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title);
  ppTVar2 = this->playerCivilization;
  iVar1 = 8;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar2 + -8));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar2);
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar2 + 8));
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  ppTVar3 = this->radioButton;
  iVar1 = 4;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)(ppTVar3 + -4));
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar3);
    ppTVar3 = ppTVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->chatInput);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->chatTitle);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->okButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->help_button);
  this_00 = this->backgroundPics;
  if (this_00 != (TShape *)0x0) {
    TShape::~TShape(this_00);
    operator_delete(this_00);
  }
  local_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel((TDialogPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 00440f20
// [HELPER] s_: ""
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Send_Message_Dialog: "Send Message Dialog"
// [HELPER] s_____SEND_CHAT___u___s: "$$$ SEND CHAT @%u: %s"
/* WARNING: Variable defined which should be unmapped: save_msg */
/* protected: virtual long __thiscall TribeSendMessageDialog::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TribeSendMessageDialog::action
          (TribeSendMessageDialog *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  char cVar1;
  TRIBE_Screen_Game *pTVar2;
  RGE_Player *pRVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  TButtonPanel **ppTVar11;
  char *pcVar12;
  char save_msg [66];
  
  if (param_1 == (TPanel *)0x0) {
    lVar8 = TPanel::action((TPanel *)this,(TPanel *)0x0,param_2,param_3,param_4);
    return lVar8;
  }
  if ((TEditPanel *)param_1 == this->chatInput) {
    if (param_2 == 0) {
      pTVar2 = (TRIBE_Screen_Game *)this->_padding_;
      pcVar4 = TEditPanel::currentLine(this->chatInput);
      if ((pcVar4 == (char *)0x0) ||
         (pcVar4 = TEditPanel::currentLine(this->chatInput), *pcVar4 == '\0')) {
        save_msg[4] = '\0';
      }
      else {
        pcVar5 = TEditPanel::currentLine(this->chatInput);
        uVar9 = 0xffffffff;
        pcVar4 = save_msg;
        do {
          pcVar12 = pcVar5;
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          pcVar12 = pcVar5 + 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar12;
        } while (cVar1 != '\0');
        uVar9 = ~uVar9;
        pcVar5 = pcVar12 + -uVar9;
        for (uVar10 = uVar9 >> 2; pcVar4 = pcVar4 + 4, uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar4 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
        }
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar4 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar4 = pcVar4 + 1;
        }
      }
      if (save_msg[4] != '\0') {
        iVar6 = (**(code **)(rge_base_game->_padding_ + 0x54))
                          ((int)rge_base_game->world->curr_player,save_msg + 4);
        if (iVar6 == 0) {
          iVar6 = RGE_Base_Game::multiplayerGame(rge_base_game);
          if (iVar6 == 0) {
            RGE_Base_Game::play_sound(rge_base_game,2);
            TRIBE_Screen_Game::display_system_message(pTVar2,&stack0xffffffb4);
          }
          else if (rge_base_game->prog_mode != 5) {
            TCommunications_Handler::SendGroupChatMsg(comm,&stack0xffffffb4);
            TDebuggingLog::Log(L,(char *)L,s_____SEND_CHAT___u___s,rge_base_game->world->world_time,
                               &stack0xffffffb4);
          }
        }
        TEditPanel::set_text(this->chatInput,s_);
        return 1;
      }
    }
  }
  else {
    if ((TButtonPanel *)param_1 == this->okButton) {
      if (param_2 == 1) {
        checkButtons(this);
        pTVar2 = (TRIBE_Screen_Game *)this->_padding_;
        pcVar4 = TEditPanel::currentLine(this->chatInput);
        if ((pcVar4 == (char *)0x0) ||
           (pcVar4 = TEditPanel::currentLine(this->chatInput), *pcVar4 == '\0')) {
          save_msg[4] = '\0';
        }
        else {
          pcVar5 = TEditPanel::currentLine(this->chatInput);
          uVar9 = 0xffffffff;
          pcVar4 = save_msg;
          do {
            pcVar12 = pcVar5;
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            pcVar12 = pcVar5 + 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar12;
          } while (cVar1 != '\0');
          uVar9 = ~uVar9;
          pcVar5 = pcVar12 + -uVar9;
          for (uVar10 = uVar9 >> 2; pcVar4 = pcVar4 + 4, uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar4 = *(undefined4 *)pcVar5;
            pcVar5 = pcVar5 + 4;
          }
          for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *pcVar4 = *pcVar5;
            pcVar5 = pcVar5 + 1;
            pcVar4 = pcVar4 + 1;
          }
        }
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Send_Message_Dialog);
        if (save_msg[4] == '\0') {
          return 1;
        }
        iVar6 = (**(code **)(rge_base_game->_padding_ + 0x54))
                          ((int)rge_base_game->world->curr_player,save_msg + 4);
        if (iVar6 != 0) {
          return 1;
        }
        iVar6 = RGE_Base_Game::multiplayerGame(rge_base_game);
        if (iVar6 == 0) {
          RGE_Base_Game::play_sound(rge_base_game,2);
          TRIBE_Screen_Game::display_system_message(pTVar2,&stack0xffffffb4);
          return 1;
        }
        if (rge_base_game->prog_mode == 5) {
          return 1;
        }
        TCommunications_Handler::SendGroupChatMsg(comm,&stack0xffffffb4);
        TDebuggingLog::Log(L,(char *)L,s_____SEND_CHAT___u___s,rge_base_game->world->world_time,
                           &stack0xffffffb4);
        return 1;
      }
    }
    else {
      if ((TButtonPanel *)param_1 == this->help_button) {
        TEasy_Panel::setup_popup_help((TEasy_Panel *)this);
        return 1;
      }
      ppTVar11 = this->checkButton;
      if ((((((TButtonPanel *)param_1 == this->checkButton[0]) ||
            ((TButtonPanel *)param_1 == this->checkButton[1])) ||
           ((TButtonPanel *)param_1 == this->checkButton[2])) ||
          (((TButtonPanel *)param_1 == this->checkButton[3] ||
           ((TButtonPanel *)param_1 == this->checkButton[4])))) ||
         (((TButtonPanel *)param_1 == this->checkButton[5] ||
          (((TButtonPanel *)param_1 == this->checkButton[6] ||
           ((TButtonPanel *)param_1 == this->checkButton[7])))))) {
        (**(code **)(this->radioButton[0]->_padding_ + 0xe0))(0);
        (**(code **)(this->radioButton[1]->_padding_ + 0xe0))(0);
        (**(code **)(this->radioButton[2]->_padding_ + 0xe0))(0);
        (**(code **)(this->radioButton[3]->_padding_ + 0xe0))(1);
      }
      else {
        if ((TButtonPanel *)param_1 == this->radioButton[0]) {
          iVar6 = 8;
          pRVar3 = rge_base_game->world->players[rge_base_game->world->curr_player];
          do {
            if (*ppTVar11 != (TButtonPanel *)0x0) {
              iVar7 = RGE_Base_Game::playerID(rge_base_game,(int)ppTVar11[0x16]);
              if ((iVar7 == pRVar3->id) ||
                 (iVar7 = (**(code **)(pRVar3->_padding_ + 0x1c))(iVar7), iVar7 != 0)) {
                (**(code **)((*ppTVar11)->_padding_ + 0xe0))(1);
              }
              else {
                (**(code **)((*ppTVar11)->_padding_ + 0xe0))(0);
              }
            }
            ppTVar11 = ppTVar11 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          checkButtons(this);
          return 1;
        }
        if ((TButtonPanel *)param_1 == this->radioButton[1]) {
          iVar6 = 8;
          pRVar3 = rge_base_game->world->players[rge_base_game->world->curr_player];
          do {
            if (*ppTVar11 != (TButtonPanel *)0x0) {
              iVar7 = RGE_Base_Game::playerID(rge_base_game,(int)ppTVar11[0x16]);
              if ((iVar7 == pRVar3->id) ||
                 (iVar7 = (**(code **)(pRVar3->_padding_ + 0x18))(iVar7), iVar7 == 0)) {
                (**(code **)((*ppTVar11)->_padding_ + 0xe0))(0);
              }
              else {
                (**(code **)((*ppTVar11)->_padding_ + 0xe0))(1);
              }
            }
            ppTVar11 = ppTVar11 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          checkButtons(this);
          return 1;
        }
        if ((TButtonPanel *)param_1 != this->radioButton[2]) {
          checkButtons(this);
          return 1;
        }
        if (param_2 == 1) {
          iVar6 = 8;
          do {
            if (*ppTVar11 != (TButtonPanel *)0x0) {
              (**(code **)((*ppTVar11)->_padding_ + 0xe0))(1);
            }
            ppTVar11 = ppTVar11 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          checkButtons(this);
          return 1;
        }
      }
    }
    checkButtons(this);
  }
  return 1;
}

// --------------------------------------------------

// Function: checkButtons
// Address: 00441410
/* protected: void __thiscall TribeSendMessageDialog::checkButtons(void) */

void __thiscall TribeSendMessageDialog::checkButtons(TribeSendMessageDialog *this)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = this->commPlayers;
  iVar3 = 8;
  do {
    if ((*piVar2 != 0) && ((TButtonPanel *)piVar2[-0x16] != (TButtonPanel *)0x0)) {
      iVar1 = TButtonPanel::get_state((TButtonPanel *)piVar2[-0x16]);
      if (iVar1 != 0) {
        iVar4 = *piVar2;
      }
      else {
        iVar4 = *piVar2;
      }
      TChat::setInChatGroup(chat,iVar4,(uint)(iVar1 != 0));
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 00441460
/* WARNING: Variable defined which should be unmapped: i */
/* protected: virtual void __thiscall TribeSendMessageDialog::draw(void) */

void __thiscall TribeSendMessageDialog::draw(TribeSendMessageDialog *this)
{
  RGE_Game_World *pRVar1;
  RGE_Color_Table *pRVar2;
  int iVar3;
  int iVar4;
  int i;
  int iStack_8;
  
  TEasy_Panel::draw((TEasy_Panel *)this);
  if (this->backgroundPics != (TShape *)0x0) {
    pRVar1 = rge_base_game->world;
    (**(code **)(this->_padding_ + 0x28))(0);
    iVar4 = 0;
    i = 1;
    do {
      iVar3 = RGE_Base_Game::playerID(rge_base_game,i);
      if (iVar3 != 0) {
        pRVar2 = pRVar1->players[iVar3]->color_table;
        if (pRVar2 != (RGE_Color_Table *)0x0) {
          _ASMSet_Color_Xform((pRVar2->id + 1) * 0x10);
          TShape::shape_draw(this->backgroundPics,(TDrawArea *)this->_padding_,
                             this->_padding_ + 0x32,this->_padding_ + 0x28 + iVar4,0,'\x01',
                             pRVar1->players[iVar3]->color_table->table);
        }
        iVar4 = iVar4 + 0x1e;
      }
      i = i + 1;
    } while (i < 9);
    (**(code **)(iStack_8 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

