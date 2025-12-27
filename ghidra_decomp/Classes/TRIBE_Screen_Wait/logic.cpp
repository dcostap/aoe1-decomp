// Class: TRIBE_Screen_Wait
// Function: TRIBE_Screen_Wait
// Address: 004a5610
// [HELPER] s_: ""
// [HELPER] s_Multiplayer_Wait_Screen: "Multiplayer Wait Screen"
// [HELPER] s_scr3: "scr3"
/* public: __thiscall TRIBE_Screen_Wait::TRIBE_Screen_Wait(void) */

TRIBE_Screen_Wait * __thiscall TRIBE_Screen_Wait::TRIBE_Screen_Wait(TRIBE_Screen_Wait *this)
{
  TButtonPanel **ppTVar1;
  char cVar2;
  uchar uVar3;
  byte bVar4;
  long lVar5;
  int iVar6;
  MapSize MVar7;
  MapType MVar8;
  VictoryType VVar9;
  char *pcVar10;
  Age AVar11;
  ResourceLevel RVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  TTextPanel **ppTVar16;
  char *pcVar17;
  undefined4 *unaff_FS_OFFSET;
  undefined1 *puVar18;
  int iVar19;
  char str1 [256];
  char str2 [256];
  char str3 [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f25b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  str1._0_4_ = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Multiplayer_Wait_Screen);
  ppTVar1 = &this->close_button;
  this->_padding_ = (int)&_vftable_;
  this->message = (TTextPanel *)0x0;
  this->cancel_button = (TButtonPanel *)0x0;
  *ppTVar1 = (TButtonPanel *)0x0;
  this->scenarioName = (TTextPanel *)0x0;
  ppTVar16 = this->settingText;
  for (iVar13 = 0x14; iVar13 != 0; iVar13 = iVar13 + -1) {
    *ppTVar16 = (TTextPanel *)0x0;
    ppTVar16 = ppTVar16 + 1;
  }
  local_4 = 0;
  lVar5 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,&s_scr3,0xc385,0);
  if (lVar5 == 0) {
    this->_padding_ = 1;
    goto LAB_004a5fb2;
  }
  TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)this,(TPanel *)this,&this->message,s_,0x14,0x28,0x17c,400,4,1,1,1);
                    /* language.dll match for 0x3ea: "X" */
  iVar13 = TEasy_Panel::create_button
                     ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,0x3ea,0,0,0,0,0,-1,-1,0);
  if (iVar13 == 0) goto LAB_004a5fb2;
  (**(code **)((*ppTVar1)->_padding_ + 0x14))();
  (**(code **)((*ppTVar1)->_padding_ + 0x18))(9,4,4,4);
  iVar13 = TEasy_Panel::create_text
                     ((TEasy_Panel *)this,(TPanel *)this,&this->scenarioName,s_,0x1a4,0x54,0xdc,0x44
                      ,0xb,0,0,1);
  if (iVar13 == 0) goto LAB_004a5fb2;
  iVar13 = 0x53;
  ppTVar16 = this->settingText;
  do {
    iVar6 = TEasy_Panel::create_text
                      ((TEasy_Panel *)this,(TPanel *)this,ppTVar16,s_,0x1a4,iVar13,0xdc,0x14,0xb,0,0
                       ,0);
    if (iVar6 == 0) goto LAB_004a5fb2;
    iVar13 = iVar13 + 0x18;
    ppTVar16 = ppTVar16 + 1;
  } while (iVar13 < 0x233);
  ppTVar16 = this->settingText;
  iVar13 = 0x14;
  do {
    (**(code **)((*ppTVar16)->_padding_ + 0x14))();
    ppTVar16 = ppTVar16 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  iVar13 = RGE_Base_Game::scenarioGame(rge_base_game);
  if (iVar13 == 0) {
    uVar3 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
    if (uVar3 == '\0') {
                    /* language.dll match for 0x25b5: "Random Map" */
      iVar13 = 0x25b5;
    }
    else {
      iVar13 = 0x2617;
    }
    TPanel::get_string((TPanel *)this,iVar13,str1 + 4,0x100);
                    /* language.dll match for 0x25ed: "Scenario: %s" */
    TPanel::get_string((TPanel *)this,0x25ed);
    sprintf();
    (**(code **)(this->scenarioName->_padding_ + 0xe8))();
    iVar13 = 1;
  }
  else {
    RGE_Base_Game::scenarioName(rge_base_game);
                    /* language.dll match for 0x25ed: "Scenario: %s" */
    TPanel::get_string((TPanel *)this,0x25ed);
    sprintf();
    (**(code **)(this->scenarioName->_padding_ + 0xe8))();
    iVar13 = 3;
  }
  iVar6 = RGE_Base_Game::randomGame(rge_base_game);
  if (iVar6 != 0) {
    MVar7 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
    switch(MVar7) {
    case Tiny:
      iVar6 = 0x2973;
      break;
    case Small:
      iVar6 = 0x2974;
      break;
    case Medium:
      iVar6 = 0x2975;
      break;
    case Large:
      iVar6 = 0x2976;
      break;
    case Huge:
                    /* language.dll match for 0x2977: "Huge" */
      iVar6 = 0x2977;
      break;
    case Humongous:
                    /* language.dll match for 0x2978: "Gigantic" */
      iVar6 = 0x2978;
      break;
    default:
      goto switchD_004a589d_default;
    }
    pcVar10 = TPanel::get_string((TPanel *)this,iVar6);
    uVar14 = 0xffffffff;
    do {
      pcVar17 = pcVar10;
      if (uVar14 == 0) break;
      uVar14 = uVar14 - 1;
      pcVar17 = pcVar10 + 1;
      cVar2 = *pcVar10;
      pcVar10 = pcVar17;
    } while (cVar2 != '\0');
    uVar14 = ~uVar14;
    pcVar10 = pcVar17 + -uVar14;
    pcVar17 = str1;
    for (uVar15 = uVar14 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
      *pcVar17 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar17 = pcVar17 + 1;
    }
switchD_004a589d_default:
                    /* language.dll match for 0x25da: "Map Size: %s" */
    TPanel::get_string((TPanel *)this,0x25da);
    sprintf();
    (**(code **)(this->settingText[iVar13]->_padding_ + 0xe8))();
    (**(code **)(this->settingText[iVar13]->_padding_ + 0x14))();
    MVar8 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
    switch(MVar8) {
    case AllWater:
      iVar6 = 0x296a;
      break;
    case MostlyWater:
      iVar6 = 0x296b;
      break;
    case WaterAndLand:
      iVar6 = 0x296c;
      break;
    case MostlyLand:
      iVar6 = 0x296d;
      break;
    case AllLand:
      iVar6 = 0x296e;
      break;
    case Continental:
      iVar6 = 0x296f;
      break;
    case Lake:
      iVar6 = 0x2970;
      break;
    case Hilly:
      iVar6 = 0x2971;
      break;
    case Isthmas:
                    /* language.dll match for 0x2972: "Narrows"
                       language.dll match for 0x2972: "******* SIZE *******" */
      iVar6 = 0x2972;
      break;
    default:
      goto switchD_004a594e_default;
    }
    pcVar10 = TPanel::get_string((TPanel *)this,iVar6);
    uVar14 = 0xffffffff;
    do {
      pcVar17 = pcVar10;
      if (uVar14 == 0) break;
      uVar14 = uVar14 - 1;
      pcVar17 = pcVar10 + 1;
      cVar2 = *pcVar10;
      pcVar10 = pcVar17;
    } while (cVar2 != '\0');
    uVar14 = ~uVar14;
    pcVar10 = pcVar17 + -uVar14;
    pcVar17 = &stack0xfffffce8;
    for (uVar15 = uVar14 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
      *pcVar17 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar17 = pcVar17 + 1;
    }
switchD_004a594e_default:
                    /* language.dll match for 0x25b6: "Map Type: %s" */
    TPanel::get_string((TPanel *)this,0x25b6);
    sprintf();
    (**(code **)(this->settingText[iVar13 + 1]->_padding_ + 0xe8))();
    (**(code **)(this->settingText[iVar13 + 1]->_padding_ + 0x14))();
    iVar13 = iVar13 + 2;
  }
  VVar9 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
  switch(VVar9) {
  case VictoryConquest:
    iVar6 = 0x10e1;
    break;
  default:
    iVar6 = RGE_Base_Game::randomGame(rge_base_game);
    if (iVar6 != 0) goto switchD_004a5a16_caseD_9;
                    /* language.dll match for 0x10e7: "Default" */
    iVar6 = 0x10e7;
    break;
  case VictoryTime:
    iVar6 = 0x10e9;
    goto LAB_004a5a33;
  case VictoryScore:
                    /* language.dll match for 0x10ea: "Score" */
    iVar6 = 0x10ea;
LAB_004a5a33:
    pcVar10 = TPanel::get_string((TPanel *)this,iVar6);
    uVar14 = 0xffffffff;
    do {
      pcVar17 = pcVar10;
      if (uVar14 == 0) break;
      uVar14 = uVar14 - 1;
      pcVar17 = pcVar10 + 1;
      cVar2 = *pcVar10;
      pcVar10 = pcVar17;
    } while (cVar2 != '\0');
    uVar14 = ~uVar14;
    pcVar10 = pcVar17 + -uVar14;
    pcVar17 = str1;
    for (uVar15 = uVar14 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
      *pcVar17 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar17 = pcVar17 + 1;
    }
    TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
                    /* language.dll match for 0x25be: "Victory: %s (%d)" */
    TPanel::get_string((TPanel *)this,0x25be);
    sprintf();
    goto LAB_004a5af4;
  case VictoryStandard:
switchD_004a5a16_caseD_9:
    iVar6 = 0x10ec;
  }
  pcVar10 = TPanel::get_string((TPanel *)this,iVar6);
  uVar14 = 0xffffffff;
  do {
    pcVar17 = pcVar10;
    if (uVar14 == 0) break;
    uVar14 = uVar14 - 1;
    pcVar17 = pcVar10 + 1;
    cVar2 = *pcVar10;
    pcVar10 = pcVar17;
  } while (cVar2 != '\0');
  uVar14 = ~uVar14;
  pcVar10 = pcVar17 + -uVar14;
  pcVar17 = str1;
  for (uVar15 = uVar14 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
    *pcVar17 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar17 = pcVar17 + 1;
  }
                    /* language.dll match for 0x25bc: "Victory: %s" */
  TPanel::get_string((TPanel *)this,0x25bc);
  sprintf();
LAB_004a5af4:
  (**(code **)(this->settingText[iVar13 + 1]->_padding_ + 0xe8))();
  (**(code **)(this->settingText[iVar13 + 1]->_padding_ + 0x14))();
  AVar11 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  if (AVar11 == DefaultAge) {
    iVar6 = 0x10e7;
  }
  else if (AVar11 == NomadAge) {
                    /* language.dll match for 0x106e: "Nomad" */
    iVar6 = 0x106e;
  }
  else {
    iVar6 = AVar11 + 0x1067;
  }
  TPanel::get_string((TPanel *)this,iVar6,&stack0xfffffce8,0x100);
                    /* language.dll match for 0x25e4: "Age: %s" */
  TPanel::get_string((TPanel *)this,0x25e4);
  sprintf();
  (**(code **)(this->settingText[iVar13 + 2]->_padding_ + 0xe8))();
  (**(code **)(this->settingText[iVar13 + 2]->_padding_ + 0x14))();
  RVar12 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
  if (RVar12 == DefaultResources) {
                    /* language.dll match for 0x10e7: "Default" */
    iVar6 = 0x10e7;
  }
  else {
    iVar6 = RVar12 + 0x25e5;
  }
  TPanel::get_string((TPanel *)this,iVar6,&stack0xfffffce0,0x100);
                    /* language.dll match for 0x25e5: "Resources: %s" */
  TPanel::get_string((TPanel *)this,0x25e5);
  sprintf();
  (**(code **)(this->settingText[iVar13 + 3]->_padding_ + 0xe8))();
  (**(code **)(this->settingText[iVar13 + 3]->_padding_ + 0x14))();
  RGE_Base_Game::difficulty(rge_base_game);
  pcVar10 = &stack0xfffffcd8;
  iVar19 = 0x100;
  iVar6 = RGE_Base_Game::difficulty(rge_base_game);
  TPanel::get_string((TPanel *)this,iVar6 + 0x2bd0,pcVar10,iVar19);
                    /* language.dll match for 0x25e0: "Difficulty Level: %s" */
  TPanel::get_string((TPanel *)this,0x25e0,str1 + 0xe8,0x100);
  sprintf();
  (**(code **)(this->settingText[iVar13 + 4]->_padding_ + 0xe8))();
  (**(code **)(this->settingText[iVar13 + 4]->_padding_ + 0x14))();
  iVar6 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game);
  if (iVar6 == 0) {
                    /* language.dll match for 0xfa3: "Yes" */
    iVar6 = 0xfa3;
  }
  else {
    iVar6 = 0xfa4;
  }
  TPanel::get_string((TPanel *)this,iVar6,&stack0xfffffcd0,0x100);
                    /* language.dll match for 0x25e9: "Fixed Positions: %s" */
  pcVar10 = TPanel::get_string((TPanel *)this,0x25e9);
  sprintf(str1 + 0xe0,pcVar10);
  (**(code **)(this->settingText[iVar13 + 5]->_padding_ + 0xe8))();
  (**(code **)(this->settingText[iVar13 + 5]->_padding_ + 0x14))(1);
  iVar6 = RGE_Base_Game::fullVisibility(rge_base_game);
  if (iVar6 == 0) {
                    /* language.dll match for 0xfa4: "No" */
    iVar6 = 0xfa4;
  }
  else {
    iVar6 = 0xfa3;
  }
  pcVar10 = TPanel::get_string((TPanel *)this,iVar6);
  uVar14 = 0xffffffff;
  do {
    pcVar17 = pcVar10;
    if (uVar14 == 0) break;
    uVar14 = uVar14 - 1;
    pcVar17 = pcVar10 + 1;
    cVar2 = *pcVar10;
    pcVar10 = pcVar17;
  } while (cVar2 != '\0');
  uVar14 = ~uVar14;
  pcVar10 = pcVar17 + -uVar14;
  pcVar17 = &stack0xfffffcc8;
  for (uVar15 = uVar14 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
    *pcVar17 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar17 = pcVar17 + 1;
  }
  puVar18 = &stack0xfffffcc8;
                    /* language.dll match for 0x25b8: "Reveal Map: %s" */
  pcVar10 = TPanel::get_string((TPanel *)this,0x25b8);
  sprintf(str1 + 0xd8,pcVar10,puVar18);
  (**(code **)(this->settingText[iVar13 + 6]->_padding_ + 0xe8))(str1 + 0xd8);
  (**(code **)(this->settingText[iVar13 + 6]->_padding_ + 0x14))(1);
  iVar6 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
  if (iVar6 == 0) {
                    /* language.dll match for 0xfa4: "No" */
    iVar6 = 0xfa4;
  }
  else {
    iVar6 = 0xfa3;
  }
  TPanel::get_string((TPanel *)this,iVar6,&stack0xfffffcc0,0x100);
  puVar18 = &stack0xfffffcc0;
                    /* language.dll match for 0x25ec: "Full Tech Tree: %s" */
  pcVar10 = TPanel::get_string((TPanel *)this,0x25ec);
  sprintf(str1 + 0xd0,pcVar10,puVar18);
  (**(code **)(this->settingText[iVar13 + 7]->_padding_ + 0xe8))(str1 + 0xd0);
  (**(code **)(this->settingText[iVar13 + 7]->_padding_ + 0x14))(1);
  iVar19 = iVar13 + 8;
  iVar6 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar6 != 0) {
    iVar6 = RGE_Base_Game::allowCheatCodes(rge_base_game);
    if (iVar6 == 0) {
                    /* language.dll match for 0xfa4: "No" */
      iVar6 = 0xfa4;
    }
    else {
      iVar6 = 0xfa3;
    }
    pcVar10 = TPanel::get_string((TPanel *)this,iVar6);
    uVar14 = 0xffffffff;
    do {
      pcVar17 = pcVar10;
      if (uVar14 == 0) break;
      uVar14 = uVar14 - 1;
      pcVar17 = pcVar10 + 1;
      cVar2 = *pcVar10;
      pcVar10 = pcVar17;
    } while (cVar2 != '\0');
    uVar14 = ~uVar14;
    pcVar10 = pcVar17 + -uVar14;
    pcVar17 = &stack0xfffffcb8;
    for (uVar15 = uVar14 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
      *pcVar17 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar17 = pcVar17 + 1;
    }
    puVar18 = &stack0xfffffcb8;
                    /* language.dll match for 0x25bb: "Enable Cheating: %s" */
    pcVar10 = TPanel::get_string((TPanel *)this,0x25bb);
    sprintf(str1 + 200,pcVar10,puVar18);
    (**(code **)(this->settingText[iVar13 + 8]->_padding_ + 0xe8))(str1 + 200);
    (**(code **)(this->settingText[iVar13 + 8]->_padding_ + 0x14))(1);
    iVar19 = iVar13 + 9;
  }
  iVar13 = RGE_Base_Game::multiplayerGame(rge_base_game);
  iVar6 = 0x100;
  if (iVar13 == 0) {
    pcVar10 = &stack0xfffffcb8;
    bVar4 = RGE_Base_Game::pathFinding(rge_base_game);
  }
  else {
    pcVar10 = &stack0xfffffcb8;
    bVar4 = RGE_Base_Game::mpPathFinding(rge_base_game);
  }
  TPanel::get_string((TPanel *)this,bVar4 + 0x260e,pcVar10,iVar6);
  puVar18 = &stack0xfffffcb8;
                    /* language.dll match for 0x25f1: "Path Finding: %s" */
  pcVar10 = TPanel::get_string((TPanel *)this,0x25f1);
  sprintf(str1 + 200,pcVar10,puVar18);
  (**(code **)(this->settingText[iVar19]->_padding_ + 0xe8))(str1 + 200);
  (**(code **)(this->settingText[iVar19]->_padding_ + 0x14))(1);
  bVar4 = TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
  uVar14 = (uint)bVar4;
                    /* language.dll match for 0x25f0: "Population Limit: %d" */
  pcVar10 = TPanel::get_string((TPanel *)this,0x25f0);
  sprintf(str1 + 0xc0,pcVar10,uVar14);
  (**(code **)(this->settingText[iVar19 + 1]->_padding_ + 0xe8))(str1 + 0xc0);
  (**(code **)(this->settingText[iVar19 + 1]->_padding_ + 0x14))(1);
LAB_004a5fb2:
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004a6030
/* public: virtual void * __thiscall TRIBE_Screen_Wait::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Screen_Wait::_scalar_deleting_destructor_(TRIBE_Screen_Wait *this,uint param_1)
{
  ~TRIBE_Screen_Wait(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Screen_Wait
// Address: 004a6050
/* public: virtual __thiscall TRIBE_Screen_Wait::~TRIBE_Screen_Wait(void) */

void __thiscall TRIBE_Screen_Wait::~TRIBE_Screen_Wait(TRIBE_Screen_Wait *this)
{
  int iVar1;
  TTextPanel **ppTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f278;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->message);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->close_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->scenarioName);
  ppTVar2 = this->settingText;
  iVar1 = 0x14;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: set_text
// Address: 004a60e0
/* public: void __thiscall TRIBE_Screen_Wait::set_text(char *) */

void __thiscall TRIBE_Screen_Wait::set_text(TRIBE_Screen_Wait *this,char *param_1)
{
  (**(code **)(this->message->_padding_ + 0xe8))(param_1);
  return;
}

// --------------------------------------------------

// Function: set_text
// Address: 004a6100
/* public: void __thiscall TRIBE_Screen_Wait::set_text(long) */

void __thiscall TRIBE_Screen_Wait::set_text(TRIBE_Screen_Wait *this,long param_1)
{
  (**(code **)(this->message->_padding_ + 0xe4))(param_1);
  return;
}

// --------------------------------------------------

// Function: action
// Address: 004a6120
/* public: virtual long __thiscall TRIBE_Screen_Wait::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TRIBE_Screen_Wait::action
          (TRIBE_Screen_Wait *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  long lVar1;
  
  if (((param_1 != (TPanel *)0x0) && ((TButtonPanel *)param_1 == this->close_button)) &&
     (param_2 == 1)) {
    RGE_Base_Game::close(rge_base_game);
    return 1;
  }
  lVar1 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 004a6170
/* public: virtual long __thiscall TRIBE_Screen_Wait::handle_idle(void) */

long __thiscall TRIBE_Screen_Wait::handle_idle(TRIBE_Screen_Wait *this)
{
  long lVar1;
  
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  lVar1 = TPanel::handle_idle((TPanel *)this);
  return lVar1;
}

// --------------------------------------------------

