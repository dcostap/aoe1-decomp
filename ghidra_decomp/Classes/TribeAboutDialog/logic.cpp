// Class: TribeAboutDialog
// Function: TribeAboutDialog
// Address: 0043ad70
// [HELPER] s_00000_000_0000000_00000: "00000-000-0000000-00000"
// [HELPER] s_: ""
// [HELPER] s_About_Dialog: "About Dialog"
// [HELPER] s_PID: "PID"
// [HELPER] s__: "}"
// [HELPER] s__s: "%s"
// [HELPER] s_circlep: "circlep"
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Variable defined which should be unmapped: tabList */
/* public: __thiscall TribeAboutDialog::TribeAboutDialog(class TScreenPanel *) */

TribeAboutDialog * __thiscall
TribeAboutDialog::TribeAboutDialog(TribeAboutDialog *this,TScreenPanel *param_1)
{
  TTextPanel **ppTVar1;
  TTextPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  TButtonPanel **ppTVar4;
  char cVar5;
  TTextPanel *this_00;
  TButtonPanel *pTVar6;
  long lVar7;
  char *pcVar8;
  TDrawArea *pTVar9;
  TPicturePanel *pTVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  undefined4 *unaff_FS_OFFSET;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  TPanel *tabList [2];
  tagRECT rect;
  char temp_str [512];
  char str [4096];
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055cf89;
  *unaff_FS_OFFSET = &local_c;
  temp_str._0_4_ = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)this,s_About_Dialog);
  ppTVar1 = &this->ms_copy_text1;
  ppTVar2 = &this->background;
  iVar22 = 1;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->title_text = (TTextPanel *)0x0;
  this->version_text = (TTextPanel *)0x0;
  *ppTVar1 = (TTextPanel *)0x0;
  this->ms_copy_text2 = (TTextPanel *)0x0;
  this->ens_copy_text = (TTextPanel *)0x0;
  this->genie_copy_text = (TTextPanel *)0x0;
  this->pid_label_text = (TTextPanel *)0x0;
  this->pid_text = (TTextPanel *)0x0;
  this->warning_text = (TTextPanel *)0x0;
  this->credits_button = (TButtonPanel *)0x0;
  this->close_button = (TButtonPanel *)0x0;
  this->circle_p_pic = (TPicturePanel *)0x0;
  *ppTVar2 = (TTextPanel *)0x0;
  lVar7 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)param_1);
  pcVar8 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)param_1);
  lVar18 = 0x19c;
  lVar16 = 0x208;
  pTVar9 = TPanel::renderArea((TPanel *)param_1);
  iVar22 = TDialogPanel::setup((TDialogPanel *)this,pTVar9,(TPanel *)param_1,lVar16,lVar18,pcVar8,
                               lVar7,iVar22);
  if (iVar22 != 0) {
    TEasy_Panel::create_text((TEasy_Panel *)this,(TPanel *)this,ppTVar2,s_,10,10,500,0x15e,4,0,0,0);
    (**(code **)((*ppTVar2)->_padding_ + 0xec))
              (3,(char)this->_padding_,*(undefined1 *)((int)&this->_padding_ + 1),
               *(undefined1 *)((int)&this->_padding_ + 2),*(undefined1 *)((int)&this->_padding_ + 3)
               ,(char)this->_padding_,*(undefined1 *)((int)&this->_padding_ + 1));
                    /* language.dll match for 0x2419: "Microsoft\\xAE Age of Empires\\xAE
                       Expansion:"
                       language.dll match for 0x2419: "Microsoft\\xA9 Age of Empires\ufffd" */
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->title_text,0x2419,0x14,0x14,0x1e0,0x14,4,0,
               0,0);
                    /* language.dll match for 0x241a: "Version 1.0"
                       language.dll match for 0x241a: "Version 1.0b" */
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->version_text,0x241a,0x14,0x28,0x1e0,0x14,
               0xb,0,0,0);
    TPanel::get_string((TPanel *)this,0x2424,temp_str + 4,0x200);
    if (temp_str[4] == '\0') {
                    /* language.dll match for 0x241b: "\\xA9 & " */
      TEasy_Panel::create_text
                ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,0x241b,0x14,0x41,0x1e0,0x14,10,0,0,0);
      if (*ppTVar1 != (TTextPanel *)0x0) {
        iVar22 = TTextPanel::get_text_rect(*ppTVar1,(tagRECT *)&rect.top);
        if (iVar22 != 0) {
          pTVar10 = (TPicturePanel *)operator_new(0x11c);
          local_4._0_1_ = 1;
          if (pTVar10 == (TPicturePanel *)0x0) {
            pTVar10 = (TPicturePanel *)0x0;
          }
          else {
            pTVar10 = (TPicturePanel *)TPicturePanel::TPicturePanel(pTVar10);
          }
          local_4 = (uint)local_4._1_3_ << 8;
          this->circle_p_pic = pTVar10;
          if (pTVar10 != (TPicturePanel *)0x0) {
            TPicturePanel::setup
                      (pTVar10,(TDrawArea *)this->_padding_,(TPanel *)this,
                       (rect.bottom - this->_padding_) + 3,0x42,0xf,0xe,s_circlep,0xc4e0,0,1);
            iVar23 = 0;
            iVar21 = 0;
            iVar20 = 0;
            lVar19 = 10;
            lVar17 = 0x14;
            lVar15 = 0x1e0;
            lVar18 = 0x41;
            lVar7 = TPanel::xPosition((TPanel *)this->circle_p_pic);
            iVar22 = this->_padding_;
            lVar16 = TPanel::width((TPanel *)this->circle_p_pic);
                    /* language.dll match for 0x241c: "1997-1998 Microsoft Corporation. All rights
                       reserved."
                       language.dll match for 0x241c: "1997 Microsoft Corporation. All rights
                       reserved." */
            TEasy_Panel::create_text
                      ((TEasy_Panel *)this,(TPanel *)this,&this->ms_copy_text2,0x241c,
                       (lVar7 - iVar22) + lVar16,lVar18,lVar15,lVar17,lVar19,iVar20,iVar21,iVar23);
          }
        }
      }
    }
    else {
                    /* language.dll match for 0x241b: "\\xA9 & " */
      pcVar11 = TPanel::get_string((TPanel *)this,0x241b);
      uVar12 = 0xffffffff;
      pcVar8 = temp_str;
      do {
        pcVar14 = pcVar11;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar14 = pcVar11 + 1;
        cVar5 = *pcVar11;
        pcVar11 = pcVar14;
      } while (cVar5 != '\0');
      uVar12 = ~uVar12;
      pcVar11 = pcVar14 + -uVar12;
      for (uVar13 = uVar12 >> 2; pcVar8 = pcVar8 + 4, uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar8 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar8 = pcVar8 + 1;
      }
      pcVar8 = TPanel::get_string((TPanel *)this,0x2424);
      uVar12 = 0xffffffff;
      do {
        pcVar11 = pcVar8;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar11 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar5 != '\0');
      uVar12 = ~uVar12;
      iVar22 = -1;
      pcVar8 = temp_str + 4;
      do {
        pcVar14 = pcVar8;
        if (iVar22 == 0) break;
        iVar22 = iVar22 + -1;
        pcVar14 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar14;
      } while (cVar5 != '\0');
      pcVar8 = pcVar11 + -uVar12;
      pcVar11 = pcVar14 + -1;
      for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar11 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar12 = 0xffffffff;
      pcVar8 = &s__;
      do {
        pcVar11 = pcVar8;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar11 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar5 != '\0');
      uVar12 = ~uVar12;
      iVar22 = -1;
      pcVar8 = temp_str + 4;
      do {
        pcVar14 = pcVar8;
        if (iVar22 == 0) break;
        iVar22 = iVar22 + -1;
        pcVar14 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar14;
      } while (cVar5 != '\0');
      pcVar8 = pcVar11 + -uVar12;
      pcVar11 = pcVar14 + -1;
      for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar11 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar11 = pcVar11 + 1;
      }
      pcVar8 = TPanel::get_string((TPanel *)this,0x241c);
      uVar12 = 0xffffffff;
      do {
        pcVar11 = pcVar8;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar11 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar5 != '\0');
      uVar12 = ~uVar12;
      iVar22 = -1;
      pcVar8 = temp_str + 4;
      do {
        pcVar14 = pcVar8;
        if (iVar22 == 0) break;
        iVar22 = iVar22 + -1;
        pcVar14 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar14;
      } while (cVar5 != '\0');
      pcVar8 = pcVar11 + -uVar12;
      pcVar11 = pcVar14 + -1;
      for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar11 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar11 = pcVar11 + 1;
      }
      TEasy_Panel::create_text
                ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,temp_str + 4,0x14,0x41,0x1e0,0x14,10,0,0
                 ,0);
    }
                    /* language.dll match for 0x241d: "Developed by Ensemble Studios Corp. for
                       Microsoft Corporation." */
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->ens_copy_text,0x241d,0x14,0x55,0x1e0,0x14,
               10,0,0,0);
                    /* language.dll match for 0x2423: "Genie engine technology \\xA9 Copyright 1995,
                       1996, 1997 by Ensemble Studios Corp. All rights reserved." */
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->genie_copy_text,0x2423,0x14,0x69,0x1e0,0x28
               ,10,0,0,1);
                    /* language.dll match for 0x241e: "Product ID:" */
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->pid_label_text,0x241e,0x14,0x96,0x5f,0x14,
               10,0,0,0);
    this_00 = this->pid_label_text;
    if (this_00 != (TTextPanel *)0x0) {
      iVar22 = TTextPanel::get_text_rect(this_00,(tagRECT *)&rect.top);
      if (iVar22 != 0) {
        pcVar8 = TRegistry::RegGetAscii(Regs,0,s_PID);
        if (pcVar8 == (char *)0x0) {
          pcVar8 = s_00000_000_0000000_00000;
        }
        sprintf(str + 4,s__s,pcVar8);
        TEasy_Panel::create_text
                  ((TEasy_Panel *)this,(TPanel *)this,&this->pid_text,str + 4,
                   (rect.bottom - this->_padding_) + 4,0x96,200,0x14,0xb,0,0,0);
      }
    }
                    /* language.dll match for 0x241f: "WARNING: This computer program is protected
                       by copyright law and international treaties.  Unauthorized reproduction or
                       distribution of this program, or any portion of it, may result in severe
                       civil and criminal penalties, and will be prosecuted to the maximum extent
                       possible under the law.\\n\\nThe names of companies, products, people,
                       characters, events and/or data mentioned in Age of Empires Expansion and its
                       documentation are fictitious unless otherwise noted."
                       language.dll match for 0x241f: "WARNING: This computer program is protected
                       by copyright law and international treaties.  Unauthorized reproduction or
                       distribution of this program, or any portion of it, may result in severe
                       civil and criminal penalties, and will be prosecuted to the maximum extent
                       possible under the law.\\n\\nThe names of companies, products, people,
                       characters, events and/or data mentioned in Age of Empires and its
                       documentation are fictitious unless otherwise noted." */
    TPanel::get_string((TPanel *)this,0x241f,str + 4,0x1000);
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->warning_text,str + 4,0x14,0xaf,0x1e0,0xdc,
               10,0,0,1);
    ppTVar3 = &this->credits_button;
                    /* language.dll match for 0x2420: "Credits" */
    TEasy_Panel::create_button
              ((TEasy_Panel *)this,(TPanel *)this,ppTVar3,0x2420,0,0x46,0x172,0xaa,0x1e,0,0,0);
    ppTVar4 = &this->close_button;
                    /* language.dll match for 0x2421: "Close" */
    TEasy_Panel::create_button
              ((TEasy_Panel *)this,(TPanel *)this,ppTVar4,0x2421,0,0x118,0x172,0xaa,0x1e,0,0,0);
    pTVar6 = *ppTVar4;
    pTVar6->hotkey = 0x1b;
    pTVar6->hotkey_shift = 0;
    tabList[1] = (TPanel *)*ppTVar3;
    rect.left = (long)*ppTVar4;
    TPanel::set_tab_order((TPanel *)this,tabList + 1,2);
    TPanel::set_curr_child((TPanel *)this,(TPanel *)*ppTVar3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0043b2e0
/* public: virtual void * __thiscall TribeAboutDialog::`scalar deleting destructor'(unsigned int) */

void * __thiscall
TribeAboutDialog::_scalar_deleting_destructor_(TribeAboutDialog *this,uint param_1)
{
  ~TribeAboutDialog(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeAboutDialog
// Address: 0043b300
/* public: virtual __thiscall TribeAboutDialog::~TribeAboutDialog(void) */

void __thiscall TribeAboutDialog::~TribeAboutDialog(TribeAboutDialog *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055cfa8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->version_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->ms_copy_text1);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->ms_copy_text2);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->ens_copy_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->genie_copy_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->pid_label_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->pid_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->warning_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->credits_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->close_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->circle_p_pic);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->background);
  local_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel((TDialogPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 0043b400
// [HELPER] s_About_Dialog: "About Dialog"
// [HELPER] s_Credits_Screen: "Credits Screen"
// [HELPER] s_Game_Screen: "Game Screen"
/* protected: virtual long __thiscall TribeAboutDialog::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TribeAboutDialog::action
          (TribeAboutDialog *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  TPanel *pTVar1;
  int iVar2;
  TRIBE_Credits_Screen *this_00;
  long lVar3;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cfcb;
  *unaff_FS_OFFSET = &local_c;
  if (param_2 == 1) {
    if ((TButtonPanel *)param_1 == this->close_button) {
      pTVar1 = TPanelSystem::panel(&panel_system,s_Game_Screen);
      if (pTVar1 != (TPanel *)0x0) {
        iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
        if ((iVar2 == 1) && (rge_base_game->save_paused == 0)) {
          RGE_Base_Game::set_paused(rge_base_game,0,0);
        }
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        (**(code **)(this->_padding_ + 0x14))(0);
        TPanelSystem::destroyPanel(&panel_system,s_About_Dialog);
        *unaff_FS_OFFSET = unaff_ESI;
        return 1;
      }
    }
    else {
      if ((TButtonPanel *)param_1 != this->credits_button) goto LAB_0043b520;
      this_00 = (TRIBE_Credits_Screen *)operator_new(0x8b8);
      local_4 = 0;
      if (this_00 != (TRIBE_Credits_Screen *)0x0) {
        TRIBE_Credits_Screen::TRIBE_Credits_Screen(this_00);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Credits_Screen,0);
    }
    TPanelSystem::destroyPanel(&panel_system,s_About_Dialog);
    *unaff_FS_OFFSET = local_c;
    return 1;
  }
LAB_0043b520:
  lVar3 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  *unaff_FS_OFFSET = local_c;
  return lVar3;
}

// --------------------------------------------------

// Function: draw
// Address: 0043b550
/* public: virtual void __thiscall TribeAboutDialog::draw(void) */

void __thiscall TribeAboutDialog::draw(TribeAboutDialog *this)
{
  if (*(char *)((int)&this->_padding_ + 3) != '\0') {
    if (this->_padding_ != 0) {
      TEasy_Panel::setup_shadow_area((TEasy_Panel *)this,1);
    }
    *(undefined1 *)((int)&this->_padding_ + 3) = 0;
  }
  if (*(char *)((int)&this->_padding_ + 2) != '\0') {
    (**(code **)(this->_padding_ + 0xe0))(1);
    return;
  }
  (**(code **)(this->_padding_ + 0xe0))(0);
  return;
}

// --------------------------------------------------

