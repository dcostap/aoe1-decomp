// Class: TribeSelectTribeScreen
// Function: TribeSelectTribeScreen
// Address: 004b75a0
// [HELPER] s_: ""
// [HELPER] s_Cancel: "Cancel"
// [HELPER] s_Civilization_Selection: "Civilization Selection"
// [HELPER] s_Previous_Screen: "Previous Screen"
// [HELPER] s_Select_Tribe_Screen: "Select Tribe Screen"
// [HELPER] s_bgA1024: "bgA1024"
// [HELPER] s_bgA640: "bgA640"
// [HELPER] s_bgA800: "bgA800"
/* public: __thiscall TribeSelectTribeScreen::TribeSelectTribeScreen(void) */

TribeSelectTribeScreen * __thiscall
TribeSelectTribeScreen::TribeSelectTribeScreen(TribeSelectTribeScreen *this)
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
  char *pcVar15;
  undefined4 *puVar16;
  char *unaff_FS_OFFSET;
  void *pvVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int secondHeight;
  int secondWidth;
  TDigital *buttonSound;
  int i;
  RGE_Font *font;
  char backgroundName [10];
  TPanel *tabList [10];
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f81a;
  local_c = *(undefined4 *)unaff_FS_OFFSET;
  *(undefined4 **)unaff_FS_OFFSET = &local_c;
  backgroundName._0_4_ = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Select_Tribe_Screen);
  this->_padding_ = (int)&_vftable_;
  this->screenText = (char **)0x0;
  local_4 = 0;
  lVar4 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,(char *)0x0,0,1);
  if (lVar4 == 0) {
    this->_padding_ = 1;
    *(undefined4 *)unaff_FS_OFFSET = local_c;
    return this;
  }
  iVar22 = *(int *)(this->_padding_ + 0x18);
  if (iVar22 < 800) {
    pcVar13 = &s_bgA640;
  }
  else {
    pcVar13 = s_bgA800;
    if (0x3ff < iVar22) {
      pcVar13 = s_bgA1024;
    }
  }
  pcVar15 = backgroundName;
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
  for (uVar11 = uVar10 >> 2; pcVar15 = pcVar15 + 4, uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar15 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar15 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar15 = pcVar15 + 1;
  }
  pTVar5 = (TPicturePanel *)operator_new(0x11c);
  local_4._0_1_ = 1;
  if (pTVar5 == (TPicturePanel *)0x0) {
    pTVar5 = (TPicturePanel *)0x0;
  }
  else {
    pTVar5 = (TPicturePanel *)TPicturePanel::TPicturePanel(pTVar5);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  this->background = pTVar5;
  if (pTVar5 == (TPicturePanel *)0x0) {
    this->_padding_ = 1;
    *(undefined4 *)unaff_FS_OFFSET = local_c;
    return this;
  }
  lVar4 = TPicturePanel::setup
                    (pTVar5,(TDrawArea *)this->_padding_,(TPanel *)this,0,0,0,0,backgroundName + 4,
                     -1,0,1);
  if (lVar4 == 0) {
    this->_padding_ = 1;
    *(undefined4 *)unaff_FS_OFFSET = local_c;
    return this;
  }
  iVar22 = (this->_padding_ * 0x1e0) / 0x1e0;
  iVar21 = (this->_padding_ * 0x280) / 0x280;
  (**(code **)(this->background->_padding_ + 0x18))(2,0,0,0,0,iVar21,iVar21,iVar22,iVar22,0,0,0,0);
  pRVar6 = RGE_Base_Game::get_font(rge_base_game,1);
  pTVar7 = (TTextPanel *)operator_new(0x188);
  if (pTVar7 == (TTextPanel *)0x0) {
    pTVar7 = (TTextPanel *)0x0;
  }
  else {
    pTVar7 = (TTextPanel *)TTextPanel::TTextPanel(pTVar7);
  }
  this->title = pTVar7;
  if (pTVar7 == (TTextPanel *)0x0) {
    this->_padding_ = 1;
    *(undefined4 *)unaff_FS_OFFSET = backgroundName._4_4_;
    return this;
  }
  TTextPanel::setup(pTVar7,(TDrawArea *)this->_padding_,(TPanel *)this->background,
                    (this->_padding_ * 0x14) / 0x280,(this->_padding_ * 0x14) / 0x1e0,
                    (this->_padding_ * 600) / 0x280,(this->_padding_ * 0x1e) / 0x1e0,pRVar6->font,
                    pRVar6->font_wid,pRVar6->font_hgt,(char *)0x0,0,'\0',0,'\0',0,
                    s_Civilization_Selection);
  pTVar8 = RGE_Base_Game::get_sound(rge_base_game,0);
  pRVar6 = RGE_Base_Game::get_font(rge_base_game,0);
  ppTVar12 = this->tribeButton;
  iVar22 = 0;
  iVar21 = 0;
  iVar23 = 0;
  do {
    pTVar9 = (TButtonPanel *)operator_new(0x2b8);
    if (pTVar9 == (TButtonPanel *)0x0) {
      pTVar9 = (TButtonPanel *)0x0;
    }
    else {
      pTVar9 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar9);
    }
    *ppTVar12 = pTVar9;
    if (pTVar9 == (TButtonPanel *)0x0) goto LAB_004b7c85;
    iVar2 = this->_padding_;
    iVar3 = this->_padding_;
    TButtonPanel::setup(pTVar9,(TDrawArea *)this->_padding_,(TPanel *)this->background,
                        (iVar3 * 0x14) / 0x280 + (iVar22 * iVar3) / 0x280,
                        (iVar2 * 0x32) / 0x1e0 + (iVar21 * iVar2 * 0x73) / 0x1e0,
                        (iVar3 * 200) / 0x280,(iVar2 * 0x6e) / 0x1e0,DrawTextA,pTVar8,NotifyAction,0
                       );
    lVar20 = -1;
    lVar19 = -1;
    lVar4 = pRVar6->font_hgt;
    lVar18 = pRVar6->font_wid;
    pvVar17 = pRVar6->font;
    pcVar13 = tribeName(this,iVar23);
    TButtonPanel::set_text_info(*ppTVar12,pcVar13,pvVar17,lVar18,lVar4,lVar19,lVar20);
    if ((iVar23 == 2) || (iVar23 == 5)) {
      iVar21 = -1;
      iVar22 = iVar22 + 200;
    }
    iVar23 = iVar23 + 1;
    ppTVar12 = ppTVar12 + 1;
    iVar21 = iVar21 + 1;
  } while (iVar23 < 9);
  pRVar6 = RGE_Base_Game::get_font(rge_base_game,0xb);
  pTVar7 = (TTextPanel *)operator_new(0x188);
  if (pTVar7 == (TTextPanel *)0x0) {
    pTVar7 = (TTextPanel *)0x0;
  }
  else {
    pTVar7 = (TTextPanel *)TTextPanel::TTextPanel(pTVar7);
  }
  this->tribeText = pTVar7;
  if (pTVar7 == (TTextPanel *)0x0) {
    this->_padding_ = 1;
    *(undefined4 *)unaff_FS_OFFSET = backgroundName._4_4_;
    return this;
  }
  TTextPanel::setup(pTVar7,(TDrawArea *)this->_padding_,(TPanel *)this->background,
                    (this->_padding_ * 0x14) / 0x280,(this->_padding_ * 400) / 0x1e0,
                    (this->_padding_ * 0x1fe) / 0x280,(this->_padding_ * 0x3c) / 0x1e0,pRVar6->font,
                    pRVar6->font_wid,pRVar6->font_hgt,(char *)0x0,0,'\0',0,'\0',0,s_);
  TTextPanel::set_alignment(this->tribeText,AlignTop,AlignWordwrap);
  pTVar9 = (TButtonPanel *)operator_new(0x2b8);
  if (pTVar9 == (TButtonPanel *)0x0) {
    pTVar9 = (TButtonPanel *)0x0;
  }
  else {
    pTVar9 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar9);
  }
  this->okButton = pTVar9;
  if (pTVar9 == (TButtonPanel *)0x0) {
    this->_padding_ = 1;
    *(undefined4 *)unaff_FS_OFFSET = backgroundName._4_4_;
    return this;
  }
  TButtonPanel::setup(pTVar9,(TDrawArea *)this->_padding_,(TPanel *)this->background,
                      (this->_padding_ * 500) / 0x280,(this->_padding_ * 400) / 0x1e0,
                      (this->_padding_ * 0x78) / 0x280,(this->_padding_ * 0x1e) / 0x1e0,DrawTextA,
                      pTVar8,NotifyAction,0);
  TButtonPanel::set_text_info
            (this->okButton,s_Previous_Screen,pRVar6->font,pRVar6->font_wid,pRVar6->font_hgt,-1,-1);
  pTVar9 = (TButtonPanel *)operator_new(0x2b8);
  if (pTVar9 == (TButtonPanel *)0x0) {
    pTVar9 = (TButtonPanel *)0x0;
  }
  else {
    pTVar9 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar9);
  }
  this->cancelButton = pTVar9;
  if (pTVar9 != (TButtonPanel *)0x0) {
    TButtonPanel::setup(pTVar9,(TDrawArea *)this->_padding_,(TPanel *)this->background,
                        (this->_padding_ * 500) / 0x280,(this->_padding_ * 0x1b8) / 0x1e0,
                        (this->_padding_ * 0x78) / 0x280,(this->_padding_ * 0x1e) / 0x1e0,DrawTextA,
                        pTVar8,NotifyAction,0);
    TButtonPanel::set_text_info
              (this->cancelButton,s_Cancel,pRVar6->font,pRVar6->font_wid,pRVar6->font_hgt,-1,-1);
    TPanel::set_curr_child((TPanel *)this,(TPanel *)this->background);
    TPanel::set_curr_child((TPanel *)this->background,(TPanel *)this->tribeButton[0]);
    fillTribeText(this,0);
    backgroundName._0_4_ = this->okButton;
    ppTVar12 = this->tribeButton;
    puVar16 = (undefined4 *)&stack0xffffff98;
    for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
      *puVar16 = *ppTVar12;
      ppTVar12 = ppTVar12 + 1;
      puVar16 = puVar16 + 1;
    }
    TPanel::set_tab_order((TPanel *)this,(TPanel **)&stack0xffffff98,10);
    *(undefined4 *)unaff_FS_OFFSET = backgroundName._4_4_;
    return this;
  }
LAB_004b7c85:
  this->_padding_ = 1;
  *(undefined4 *)unaff_FS_OFFSET = backgroundName._4_4_;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004b7dd0
/* public: virtual void * __thiscall TribeSelectTribeScreen::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TribeSelectTribeScreen::_scalar_deleting_destructor_(TribeSelectTribeScreen *this,uint param_1)
{
  ~TribeSelectTribeScreen(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeSelectTribeScreen
// Address: 004b7df0
/* public: virtual __thiscall TribeSelectTribeScreen::~TribeSelectTribeScreen(void) */

void __thiscall TribeSelectTribeScreen::~TribeSelectTribeScreen(TribeSelectTribeScreen *this)
{
  int iVar1;
  TButtonPanel **ppTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f838;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->title != (TTextPanel *)0x0) {
    (**(code **)this->title->_padding_)(1);
  }
  if (this->tribeText != (TTextPanel *)0x0) {
    (**(code **)this->tribeText->_padding_)(1);
  }
  ppTVar2 = this->tribeButton;
  iVar1 = 9;
  do {
    if (*ppTVar2 != (TButtonPanel *)0x0) {
      (**(code **)(*ppTVar2)->_padding_)(1);
    }
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (this->okButton != (TButtonPanel *)0x0) {
    (**(code **)this->okButton->_padding_)(1);
  }
  if (this->cancelButton != (TButtonPanel *)0x0) {
    (**(code **)this->cancelButton->_padding_)(1);
  }
  iVar1 = 0;
  if (0 < this->numLines) {
    do {
      free(this->screenText[iVar1]);
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->numLines);
  }
  free(this->screenText);
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 004b7ee0
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_Select_Tribe_Screen: "Select Tribe Screen"
/* protected: virtual long __thiscall TribeSelectTribeScreen::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TribeSelectTribeScreen::action
          (TribeSelectTribeScreen *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  int iVar1;
  long lVar2;
  TButtonPanel **ppTVar3;
  
  if (((TButtonPanel *)param_1 == this->okButton) || ((TButtonPanel *)param_1 == this->cancelButton)
     ) {
    if (param_2 == 1) {
      TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Select_Tribe_Screen);
      return 1;
    }
  }
  else if (param_2 == 1) {
    iVar1 = 0;
    ppTVar3 = this->tribeButton;
    do {
      if ((TButtonPanel *)param_1 == *ppTVar3) {
        fillTribeText(this,iVar1);
        return 1;
      }
      iVar1 = iVar1 + 1;
      ppTVar3 = ppTVar3 + 1;
    } while (iVar1 < 9);
  }
  lVar2 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar2;
}

// --------------------------------------------------

// Function: fillTribeText
// Address: 004b7f70
// [HELPER] s_Assyrian_information_here_: "Assyrian information here."
// [HELPER] s_Babylonian_information_here_: "Babylonian information here."
// [HELPER] s_Egyptian_information_here_: "Egyptian information here."
// [HELPER] s_Greek_information_here_: "Greek information here."
// [HELPER] s_Hittite_information_here_: "Hittite information here."
// [HELPER] s_Isrealite_information_here_: "Isrealite information here."
// [HELPER] s_Minoan_information_here_: "Minoan information here."
// [HELPER] s_Phoenician_information_here_: "Phoenician information here."
// [HELPER] s_Sumerian_information_here_: "Sumerian information here."
/* protected: void __thiscall TribeSelectTribeScreen::fillTribeText(int) */

void __thiscall TribeSelectTribeScreen::fillTribeText(TribeSelectTribeScreen *this,int param_1)
{
  int iVar1;
  char *pcVar2;
  
  switch(param_1) {
  case 0:
    pcVar2 = s_Assyrian_information_here_;
    iVar1 = this->tribeText->_padding_;
    break;
  case 1:
    (**(code **)(this->tribeText->_padding_ + 0xe8))(s_Babylonian_information_here_);
    goto switchD_004b7f80_default;
  case 2:
    pcVar2 = s_Egyptian_information_here_;
    iVar1 = this->tribeText->_padding_;
    break;
  case 3:
    (**(code **)(this->tribeText->_padding_ + 0xe8))(s_Greek_information_here_);
    goto switchD_004b7f80_default;
  case 4:
    pcVar2 = s_Hittite_information_here_;
    iVar1 = this->tribeText->_padding_;
    break;
  case 5:
    (**(code **)(this->tribeText->_padding_ + 0xe8))(s_Isrealite_information_here_);
    goto switchD_004b7f80_default;
  case 6:
    pcVar2 = s_Minoan_information_here_;
    iVar1 = this->tribeText->_padding_;
    break;
  case 7:
    (**(code **)(this->tribeText->_padding_ + 0xe8))(s_Phoenician_information_here_);
    goto switchD_004b7f80_default;
  case 8:
    pcVar2 = s_Sumerian_information_here_;
    iVar1 = this->tribeText->_padding_;
    break;
  default:
    goto switchD_004b7f80_default;
  }
  (**(code **)(iVar1 + 0xe8))(pcVar2);
switchD_004b7f80_default:
  TTextPanel::scroll(this->tribeText,'\x06',0,1);
  return;
}

// --------------------------------------------------

// Function: tribeName
// Address: 004b8070
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
/* protected: char * __thiscall TribeSelectTribeScreen::tribeName(int) */

char * __thiscall TribeSelectTribeScreen::tribeName(TribeSelectTribeScreen *this,int param_1)
{
  switch(param_1) {
  case 0:
    return s_Assyrian;
  case 1:
    return s_Babylonian;
  case 2:
    return s_Egyptian;
  case 3:
    return s_Greek;
  case 4:
    return s_Hittite;
  case 5:
    return s_Isrealite;
  case 6:
    return s_Minoan;
  case 7:
    return s_Phoenician;
  case 8:
    return s_Sumerian;
  default:
    return s_No_Culture;
  }
}

// --------------------------------------------------

